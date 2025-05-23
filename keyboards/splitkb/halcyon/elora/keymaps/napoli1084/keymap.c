// Copyright 2025 NapOli1084 (@napoli1084)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


/*
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | LTB  | LTB  |  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| LTB  | LTB  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 * The additional 5 keys per side are for modules, e.g. encoder button:
 * https://discord.com/channels/574598631399751680/1327075555903930388/1332301708398956636
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */

#define NAPOLI1084_LAYOUT( \
    leftPinky3Row0, leftPinky2Row0, leftPinky1Row0, leftRingRow0, leftMiddleRow0, leftIndex1Row0, leftIndex2Row0, leftIndex3Row0, rightIndex3Row0, rightIndex2Row0, rightIndex1Row0, rightMiddleRow0, rightRingRow0, rightPinky1Row0, rightPinky2Row0, rightPinky3Row0, \
    leftPinky3Row1, leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1, leftIndex3Row1, rightIndex3Row1, rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, rightPinky3Row1, \
    leftPinky3Row2, leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2, leftIndex3Row2, rightIndex3Row2, rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, rightPinky3Row2, \
    leftPinky3Row3, leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3, leftIndex3Row3, rightIndex3Row3, rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, rightPinky3Row3, \
    leftPinky3Row4, leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4, leftIndex3Row4, rightIndex3Row4, rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, rightPinky3Row4, \
    leftPinky3Row5, leftPinky2Row5, leftPinky1Row5, leftRingRow5, leftMiddleRow5, leftIndex1Row5, leftIndex2Row5, leftIndex3Row5, rightIndex3Row5, rightIndex2Row5, rightIndex1Row5, rightMiddleRow5, rightRingRow5, rightPinky1Row5, rightPinky2Row5, rightPinky3Row5, \
    leftThumb0, leftThumb1, leftThumb2, leftThumb3, leftThumb4, leftThumb5, leftThumb6, leftThumb7, rightThumb7, rightThumb6, rightThumb5, rightThumb4, rightThumb3, rightThumb2, rightThumb1, rightThumb0 \
) \
    LAYOUT_elora_hlc( \
      leftPinky2Row1, leftPinky1Row1, leftRingRow1, leftMiddleRow1, leftIndex1Row1, leftIndex2Row1,                                                          rightIndex2Row1, rightIndex1Row1, rightMiddleRow1, rightRingRow1, rightPinky1Row1, rightPinky2Row1, \
      leftPinky2Row2, leftPinky1Row2, leftRingRow2, leftMiddleRow2, leftIndex1Row2, leftIndex2Row2,                                                          rightIndex2Row2, rightIndex1Row2, rightMiddleRow2, rightRingRow2, rightPinky1Row2, rightPinky2Row2, \
      leftPinky2Row3, leftPinky1Row3, leftRingRow3, leftMiddleRow3, leftIndex1Row3, leftIndex2Row3,                                                          rightIndex2Row3, rightIndex1Row3, rightMiddleRow3, rightRingRow3, rightPinky1Row3, rightPinky2Row3, \
      leftPinky2Row4, leftPinky1Row4, leftRingRow4, leftMiddleRow4, leftIndex1Row4, leftIndex2Row4, leftThumb4, leftThumb7,        rightThumb7, rightThumb4, rightIndex2Row4, rightIndex1Row4, rightMiddleRow4, rightRingRow4, rightPinky1Row4, rightPinky2Row4, \
                                            leftRingRow5,   leftMiddleRow5,    leftThumb1,    leftThumb2,   leftThumb3,                rightThumb3,   rightThumb2,    rightThumb1,    rightMiddleRow5,    rightRingRow5, \
      KC_MUTE, leftPinky1Row0, leftRingRow0, leftMiddleRow0, leftIndex1Row0,                                                    rightIndex1Row0, rightMiddleRow0, rightRingRow0, rightPinky1Row0,    KC_MUTE \
    )
// See ../qmk_firmware/.build/obj_splitkb_elora_rev1_napoli1084/src/default_keyboard.h
// for #define LAYOUT_myr

#include "napoli1084_keymap.c"

#ifdef SWAP_HANDS_ENABLE
//12 rows, 8 columns
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    // Left
    {{7, 6}, {6, 6}, {5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{7, 7}, {6, 7}, {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7}, {0, 7}},
    {{7, 8}, {6, 8}, {5, 8}, {4, 8}, {3, 8}, {2, 8}, {1, 8}, {0, 8}},
    {{7, 9}, {6, 9}, {5, 9}, {4, 9}, {3, 9}, {2, 9}, {1, 9}, {0, 9}},
    {{7, 10}, {6, 10}, {5, 10}, {4, 10}, {3, 10}, {2, 10}, {1, 10}, {0, 10}},
    {{7, 11}, {6, 11}, {5, 11}, {4, 11}, {3, 11}, {2, 11}, {1, 11}, {0, 11}},
    // Right
    {{7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{7, 3}, {6, 3}, {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}},
    {{7, 4}, {6, 4}, {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{7, 5}, {6, 5}, {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}}
};

#if defined(ENCODER_MAP_ENABLE)
const uint8_t PROGMEM encoder_hand_swap_config[NUM_ENCODERS] = { 4, 5, 6, 7, 0, 1, 2, 3 };
#endif
#endif

#if defined(ENCODER_MAP_ENABLE)
bool encoder_update_user(uint8_t index, bool clockwise) {
  return false;
}

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LYR_WORKNAP] = {
      // 2 encoders per side supported, 1 soldered, 1 module
      ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT),
      ENCODER_CCW_CW(KC_MS_WH_LEFT, KC_MS_WH_RIGHT),
      ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),
      ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)
    },
    [LYR_GAME] = {
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
      ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
    },
    [LYR_NAVNUM] = {
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)
    },
    [LYR_FRSYMBOL] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN)
    },
    [LYR_FN] = {
      ENCODER_CCW_CW(RGB_HUD, RGB_HUI),
      ENCODER_CCW_CW(RGB_HUD, RGB_HUI),
      ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),
      ENCODER_CCW_CW(RGB_RMOD, RGB_MOD)
    },
    [LYR_F1F12] = {
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
      ENCODER_CCW_CW(KC_PGUP, KC_PGDN)
    }
};
#endif
