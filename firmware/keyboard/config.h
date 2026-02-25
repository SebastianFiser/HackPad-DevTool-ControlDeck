#pragma once

// Matice a diody (užitečné mít i zde pro jistotu)
#define DIODE_DIRECTION COL2ROW

// Encoder - pins 8 a 7
#define ENCODERS_PAD_A { GP8 }
#define ENCODERS_PAD_B { GP7 }
#define ENCODER_RESOLUTION 4

// RGB LED on pin 10, 2 pieces
#define RGB_DI_PIN GP10
#define RGBLED_NUM 2

// Debouncing for stability
#define DEBOUNCE 5