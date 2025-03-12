/*
Copyright 2022 NapOli1084 (@napoli1084)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

////////////////////////////////////////////////////////////////////////////////
// From splitkb/elora/keymaps/default
////////////////////////////////////////////////////////////////////////////////

// Myriad boilerplate
//#define MYRIAD_ENABLE

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
// 5 is already the default
//#define DEBOUNCE 5

////////////////////////////////////////////////////////////////////////////////

#define ENCODER_RESOLUTION 2
//#define ENCODER_RESOLUTIONS { 2, 2, 2, 4 }
//#define ENCODER_RESOLUTIONS_RIGHT { 2, 2, 2, 4 }

#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE

#define RGBLIGHT_EFFECT_BREATHING // 4 sub-modes (speed), single color (initial red), slowly dim/raise brightness
//#define RGBLIGHT_EFFECT_RAINBOW_MOOD // 3 sub-modes (speed), all leds same color, slowly changes hue
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL // 6 sub-modes (direction/speed), leds different color, hue moves right/left
//#define RGBLIGHT_EFFECT_SNAKE // 6 sub-modes (direction/speed), leds off, then some light up single color move left/right
//#define RGBLIGHT_EFFECT_KNIGHT // 3 sub-modes, similar to snake but both sides
//#define RGBLIGHT_EFFECT_CHRISTMAS // changing red/green
//#define RGBLIGHT_EFFECT_STATIC_GRADIENT // 10 sub-modes, no anim, just different color gradients
//#define RGBLIGHT_EFFECT_RGB_TEST // all leds same color at same time, changing red/green/blue
//#define RGBLIGHT_EFFECT_ALTERNATING // single color flashing on/off
//#define RGBLIGHT_EFFECT_TWINKLE // 6 sub-modes, leds off, then some slowly light on then off single/multi color randomly

// Cyan (slightly more green)
#define NAPOLI1084_HSV_LYR_WORKNAP 120, 255, 255
#define NAPOLI1084_HSV_LYR_NAVNUM HSV_BLUE

