# Vision

## Project Goal
Create a context-aware, physical control console for Linux that accelerates workflow, reduces cognitive load, and enables instant system-level actions. The device will serve as an external command interface, allowing the user to manage applications, system modes, and hardware controls without relying on slow graphical menus or repetitive keyboard shortcuts.

## Problem Statement
Current workflows in Linux environments are slowed by:
- Opening and closing applications manually
- Navigating nested menus and settings
- Adjusting system parameters (brightness, audio, Bluetooth, WiFi)
- Switching between workspaces or tasks
- Recovering from frozen interfaces

These repetitive actions reduce productivity and interrupt focus.

## Solution
The solution is a compact hardware deck with:
- 16 MX-style switches in a 4x4 matrix
- 2 rotary encoders for continuous control
- 1 small OLED display for showing current mode and button mappings
- 16 addressable RGB LEDs for feedback and status indication
- Three distinct operating modes to group functions by workflow context

The system combines custom firmware on the XIAO RP2040 with a lightweight Linux daemon. The firmware handles button scanning, encoder input, mode management, LED control, and HID communication. The daemon maps deck input to system commands, monitors active applications, and synchronizes contextual behavior with the deck display.

## Design Principles
- **Physical first:** all actions are accessible without looking at the PC or mouse.
- **Context aware:** functions of buttons adapt to the active mode.
- **Minimal cognitive load:** the user immediately knows the function of each control via display and LEDs.
- **Reliable execution:** critical system actions work even if UI freezes or applications hang.
- **Modular:** hardware and software components can be modified, upgraded, or expanded independently.
