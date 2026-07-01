// Copyright 2026 NapOli1084 (@napoli1084)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum/quantum.h"
#include "napoli1084_utils.h"

// Waiting https://github.com/qmk/qmk_firmware/issues/26304 to decide if I remove this.
#if 0
// This is the reason for re-implementing unicode functions here;
// it allows knowing if we're registering unicode keys to use a different delay in tap_code.
// Other than that the functions in this file are the same as in `quantum/unicode/unicode.c`.
bool is_registering_unicode = false;

#ifndef UNICODE_KEY_MAC
#    define UNICODE_KEY_MAC KC_LEFT_ALT
#endif
#ifndef UNICODE_KEY_LNX
#    define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#endif
#ifndef UNICODE_KEY_WINC
#    define UNICODE_KEY_WINC KC_RIGHT_ALT
#endif
#ifndef UNICODE_TYPE_DELAY
#    define UNICODE_TYPE_DELAY 10
#endif

uint8_t unicode_saved_mods;
led_t unicode_saved_led_state;

void unicode_input_start(void) {

    is_registering_unicode = true; // napoli1084
    nap_dprintf("unicode_input_start: is_registering_unicode=%u\n", is_registering_unicode);

    unicode_saved_led_state = host_keyboard_led_state();

    // Note the order matters here!
    // Need to do this before we mess around with the mods, or else
    // UNICODE_KEY_LNX (which is usually Ctrl-Shift-U) might not work
    // correctly in the shifted case.
    if (unicode_config.input_mode == UNICODE_MODE_LINUX && unicode_saved_led_state.caps_lock) {
        tap_code(KC_CAPS_LOCK);
    }

    unicode_saved_mods = get_mods(); // Save current mods
    clear_mods();                    // Unregister mods to start from a clean state
    clear_weak_mods();

    switch (get_unicode_input_mode()) {
        case UNICODE_MODE_MACOS:
            register_code(UNICODE_KEY_MAC);
            break;
        case UNICODE_MODE_LINUX:
            tap_code16(UNICODE_KEY_LNX);
            break;
        case UNICODE_MODE_WINDOWS:
            // For increased reliability, use numpad keys for inputting digits
            if (!unicode_saved_led_state.num_lock) {
                tap_code(KC_NUM_LOCK);
            }
            register_code(KC_LEFT_ALT);
            wait_ms(UNICODE_TYPE_DELAY);
            tap_code(KC_KP_PLUS);
            break;
        case UNICODE_MODE_WINCOMPOSE:
            tap_code(UNICODE_KEY_WINC);
            tap_code(KC_U);
            break;
        case UNICODE_MODE_EMACS:
            // The usual way to type unicode in emacs is C-x-8 <RET> then the unicode number in hex
            tap_code16(LCTL(KC_X));
            tap_code16(KC_8);
            tap_code16(KC_ENTER);
            break;
    }

    wait_ms(UNICODE_TYPE_DELAY);
}

void unicode_input_finish(void) {
    switch (get_unicode_input_mode()) {
        case UNICODE_MODE_MACOS:
            unregister_code(UNICODE_KEY_MAC);
            break;
        case UNICODE_MODE_LINUX:
            tap_code(KC_SPACE);
            if (unicode_saved_led_state.caps_lock) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
        case UNICODE_MODE_WINDOWS:
            unregister_code(KC_LEFT_ALT);
            if (!unicode_saved_led_state.num_lock) {
                tap_code(KC_NUM_LOCK);
            }
            break;
        case UNICODE_MODE_WINCOMPOSE:
            tap_code(KC_ENTER);
            break;
        case UNICODE_MODE_EMACS:
            tap_code16(KC_ENTER);
            break;
    }

    set_mods(unicode_saved_mods); // Reregister previously set mods

    is_registering_unicode = false; // napoli1084
    nap_dprintf("unicode_input_finish: is_registering_unicode=%u\n", is_registering_unicode);
}

void unicode_input_cancel(void) {
    switch (unicode_config.input_mode) {
        case UNICODE_MODE_MACOS:
            unregister_code(UNICODE_KEY_MAC);
            break;
        case UNICODE_MODE_LINUX:
            tap_code(KC_ESCAPE);
            if (unicode_saved_led_state.caps_lock) {
                tap_code(KC_CAPS_LOCK);
            }
            break;
        case UNICODE_MODE_WINCOMPOSE:
            tap_code(KC_ESCAPE);
            break;
        case UNICODE_MODE_WINDOWS:
            unregister_code(KC_LEFT_ALT);
            if (!unicode_saved_led_state.num_lock) {
                tap_code(KC_NUM_LOCK);
            }
            break;
        case UNICODE_MODE_EMACS:
            tap_code16(LCTL(KC_G)); // C-g cancels
            break;
    }

    set_mods(unicode_saved_mods); // Reregister previously set mods
}


void tap_code(uint8_t code) {
    uint16_t delay_ms;
    if (is_registering_unicode) {
        delay_ms = 4;
    } else if (code == KC_CAPS_LOCK) {
        delay_ms = TAP_HOLD_CAPS_DELAY;
    } else {
        delay_ms = TAP_CODE_DELAY;
    }
    nap_dprintf("tap_code: 0x%x delay_ms=%u\n", code, delay_ms);
    tap_code_delay(code, delay_ms);
}
#endif
