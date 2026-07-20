// Copyright 2021-2025 NapOli1084 (@napoli1084)
// SPDX-License-Identifier: GPL-2.0-or-later

///////////////////////////////////////////////////////////////////////////
// Caps Word
///////////////////////////////////////////////////////////////////////////
//#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

///////////////////////////////////////////////////////////////////////////
// Layers
///////////////////////////////////////////////////////////////////////////
// I don't expect using more than 16 layers, so using 16 bits saves some space.
// Moved to keyboard
//#define LAYER_STATE_16BIT

///////////////////////////////////////////////////////////////////////////
// Locking
///////////////////////////////////////////////////////////////////////////
// This is for mechanically locking keys.
// https://docs.qmk.fm/#/squeezing_avr?id=configh-settings
// https://docs.qmk.fm/#/faq_keymap?id=mechanical-lock-switch-support
//
// Supports KC_LOCKING_CAPS_LOCK, KC_LOCKING_NUM_LOCK, KC_LOCKING_SCROLL_LOCK.
// ergodox_ez enables it (?!), keebio/viterbi and dactyl_manuform also,
// let's disable it.
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

///////////////////////////////////////////////////////////////////////////
// RGB backlight/underglow
///////////////////////////////////////////////////////////////////////////
#ifdef RGBLIGHT_ENABLE
#define RGBLIGHT_LAYERS
#endif
#define RGBLIGHT_MAX_LAYERS 12
#undef RGBLIGHT_SLEEP
#define RGBLIGHT_SLEEP

// Using my own processing for rgb keycodes
#define RGBLIGHT_DISABLE_KEYCODES

#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 8
#undef RGBLIGHT_SAT_STEP
#define RGBLIGHT_SAT_STEP 8
#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 8

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#define NAPOLI1084_RGB_MODE_ENABLE
#endif

///////////////////////////////////////////////////////////////////////////
// RGB Matrix
///////////////////////////////////////////////////////////////////////////
#undef RGB_MATRIX_SLEEP
#define RGB_MATRIX_SLEEP

#undef RGB_MATRIX_TIMEOUT
// Turn off after 10 minutes (10*60sec*1000ms)
#define RGB_MATRIX_TIMEOUT 600000

// Startup animation speed
//#define RGB_MATRIX_STARTUP_SPD 60

// Using my own processing for rgb keycodes
#define RGB_MATRIX_DISABLE_KEYCODES
#define RGB_TRIGGER_ON_KEYDOWN

#undef RGB_MATRIX_HUE_STEP
#define RGB_MATRIX_HUE_STEP 4


// https://www.youtube.com/watch?v=7f3usatOIKM&t=7s
// SOLID_COLOR=1 always enabled
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS // alpha keys one color, mod keys another color
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN // static rainbow up-down
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT // static rainbow left-right
#undef ENABLE_RGB_MATRIX_BREATHING // breathing one color
#undef ENABLE_RGB_MATRIX_BAND_SAT // all white, one color vertical band moving left-right
#undef ENABLE_RGB_MATRIX_BAND_VAL // all off, one color vertical band moving left-right
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT // all white, one color pinwheel
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL // one color pinwheel
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT // all white, one color spiral
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL // one color spiral
#undef ENABLE_RGB_MATRIX_CYCLE_ALL // all same color changing rainbow
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT //===> left-right moving rainbow, default initial value if enabled <===
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN // up-down moving rainbow
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // left-right moving rainbow chevron '>'
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN // circular rainbow towards center
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL // 2 circular rainbow towards each half's center
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL // rainbow pinwheel around center
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL // rainbow spiral arount center
#undef ENABLE_RGB_MATRIX_DUAL_BEACON // rainbow beacon spinning both ways from center
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON // rainbow beacon spinning from center
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS // 2 rainbow pinwheels centered on each half
#undef ENABLE_RGB_MATRIX_RAINDROPS // few bright red/blue/green/yellow colors
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS // many pastel colors, pink/purple/turquoise/etc.
#undef ENABLE_RGB_MATRIX_HUE_BREATHING // more like heartbeat
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM // left-right, right-left single color
#undef ENABLE_RGB_MATRIX_HUE_WAVE // left-right single color
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN // most off, pixel rain multicolor
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL // all off, pixels moving from center towards each side

#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT // default initial value if enabled
//#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON

#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN // The Matrix-like white-green drops top to bottom

#undef RGB_MATRIX_KEYRELEASES
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE // all off, single color on press
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE // all single color, opposite color on press
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE // all off, single color on surrounding keys on press
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE // as above on multiple simultaneous key press
// Cross/nexus are weird on columnar staggered keyboards, best on ortholinear
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS // all off, single color on colum+line on press
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS // as above on multiple simultaneous key press
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS // smaller cross
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS // as above on multiple simultaneous key press
#undef ENABLE_RGB_MATRIX_SPLASH // all off, moving rainbow on all from pressed key. Pretty intense when typing.
#undef ENABLE_RGB_MATRIX_MULTISPLASH // as above on multiple simultaneous key press
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH // all off, single color splash from pressed key
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH


///////////////////////////////////////////////////////////////////////////
// Split
///////////////////////////////////////////////////////////////////////////

// Needed for my RGB layers.
#undef SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE

#define SPLIT_TRANSACTION_IDS_USER NAPOLI1084_SYNC_RGB_MODE

///////////////////////////////////////////////////////////////////////////
// Tap-Hold
///////////////////////////////////////////////////////////////////////////

//#define PERMISSIVE_HOLD

// Use with PERMISSIVE_HOLD or HOLD_ON_OTHER_KEY_PRESS.
// Opposite hands rule: triggers tap for tap-hold keys if other key pressed on same hand within tapping term.
// Prevents quick layer+key tap with layer-tap (LT) keys.
//#define CHORDAL_HOLD

// Taps tap-hold key if held and no other key pressed.
//#define RETRO_TAPPING

// Triggers mod when pressing mod-tap (MT), releases it before sending tap code if tap selected.
// May be useful for Shift+Click. Would probably trigger OS sticky keys.
//#define SPECULATIVE_HOLD

// Disables hold for MT and LT keys during fast typing (tapped within timeout of preceding key).
// https://docs.qmk.fm/tap_hold#flow-tap
#define FLOW_TAP_TERM 150

// how many taps before oneshot toggle is triggered
// https://docs.qmk.fm/#/one_shot_keys?id=one-shot-keys
#define ONESHOT_TAP_TOGGLE 2

// If timeout doesn't work, make sure one shot keys are enabled by pressing OS_TOGG.
// See also `oneshot_enable(void)`, that I added to my keyboard_post_init_user.
#define ONESHOT_TIMEOUT 5000

// how many taps before triggering the toggle with layer Tap-Toggle function TT(layer)
// https://docs.qmk.fm/#/feature_layers?id=switching-and-toggling-layers
#define TAPPING_TOGGLE 1

// How long before a tap becomes a hold in milliseconds. Default is 200.
#undef TAPPING_TERM
#define TAPPING_TERM 225

// Waits milliseconds before calling unregister_code() when tap_code() is called.
// Needed for my symbol keys with LSFT and 2 keys sequence, e.g. 'ë' on CAFR keyboard.
// Otherwise shift isn't applied to the right keystroke and doesn't give the desired result.
// 3 milliseconds seems enough (it worked well with 5 and 10 also).
// More than 4 milliseconds slows down repetition with WinCompose unicode keys
// since they end up tapping 7-8 keys (ComposeKey, u, 4-5 hex digits, enter) and repetition is every 33ms.
//
// Changed to 6 while trying to fix combos in:
// https://github.com/NapOli1084/qmk_firmware/commit/067937cd330233c5b92160a027ff1b41c95bb873
// See also register_code16 in napoli1084.c.
//
// Longer delay fixes mod-tap, layer-tap (LT) and tap-dance keys
// that don't always register in ubi games (in-game console, menu shortcut).
// 100 worked well, while with 6 it missed one keypress on ~3-5.
// However with 100 it slows down unicode keys a lot, and causes them to repeat (e.g. ~ repeats 3 times)
// 16-30 worked well, but also slows down unicode, can't type // twice rapidly.
// 10 seems the best tradeoff for now, both MT/LT/TD and unicode drop some key presses, but only ~1/10.
// It's not enough for menu shortcuts in Shadows, still miss ~1/2.
#define TAP_CODE_DELAY 10

///////////////////////////////////////////////////////////////////////////
// Unicode
///////////////////////////////////////////////////////////////////////////

// Unicode mode WinCompose with KC_APP as trigger key
// https://docs.qmk.fm/#/feature_unicode?id=setting-the-input-mode
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE
// https://docs.qmk.fm/#/feature_unicode?id=input-key-configuration
#define UNICODE_KEY_WINC KC_APPLICATION

// Don't save Unicode mode to EEPROM
#define UNICODE_CYCLE_PERSIST 0

//#define UNICODE_TYPE_DELAY 0


