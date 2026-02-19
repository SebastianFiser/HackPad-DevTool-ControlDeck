# Architecture

## Overview
The system consists of two main components:

1. **Firmware on XIAO RP2040** – handles physical inputs, mode management, LED control, and USB HID communication.
2. **Linux Daemon** – maps deck input to system commands, monitors context, and updates the display and LED feedback.

The architecture is designed for modularity, reliability, and low latency.

---

## 1. Firmware

**Responsibilities:**
- Scan 4x4 button matrix with diodes to prevent ghosting
- Read rotary encoder inputs
- Manage 3 operating modes and context-specific mapping of buttons and encoders
- Drive the OLED display over I2C
- Control 16 SK6812 MINI-E RGB LEDs for feedback
- Communicate with Linux daemon via USB HID or serial interface
- Ensure deterministic execution of critical system commands (panic button, macro sequences)

**Mode Management:**
- Firmware keeps track of active mode
- Button presses are interpreted relative to the current mode
- Encoder inputs are mapped to context-specific continuous control (volume, brightness, scroll, etc.)

**LED / Display Integration:**
- LEDs indicate mode and key states
- OLED displays current mode, button labels, and system feedback

---

## 2. Linux Daemon

**Responsibilities:**
- Receive input events from the deck
- Map physical buttons and encoders to system actions, hotkeys, or macros
- Monitor active applications and system context to provide dynamic mapping
- Send status updates back to firmware for display and LED feedback
- Handle OS-level tasks: application launching, workspace switching, system toggles, smart save, recovery sequences

**Design Principles:**
- Lightweight and low-latency
- Configurable user profiles
- Extensible for future modes and macros
- Fault-tolerant: ensures critical commands execute even if UI is frozen

---

## 3. Communication Protocol

- **Bidirectional** between firmware and daemon
- Encodes:
  - Button press / release events
  - Encoder delta values
  - Mode changes
  - System feedback (LED, display)
- Can use either:
  - USB HID reports
  - Serial-over-USB messages
- Structured for simplicity and low-latency response

---

## 4. Modularity

- Firmware and daemon are decoupled; either component can be upgraded independently
- Adding new modes or remapping functions requires minimal firmware changes
- Hardware abstraction allows easy migration to future boards or additional peripherals

---

## 5. Summary

The architecture ensures:

- Fast, reliable input handling
- Mode-based context-aware behavior
- Real-time visual feedback
- Flexible integration with Linux workflows
- Maintainability and extensibility for future enhancements
