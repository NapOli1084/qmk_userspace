// Copyright 2022-2025 NapOli1084 (@napoli1084)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum/led.h"
#include "quantum/action_layer.h"

enum napoli1084_rgb_layer_modes {
#if defined(RGBLIGHT_LAYERS) || defined(RGB_MATRIX_ENABLE)
    NAP_RGB_MODE_LAYER, // Use layer colors
    NAP_RGB_MODE_LAYER_EFFECT_DEFAULT, // Use layer colors except on default layer, play effect
    NAP_RGB_MODE_LAYER_TEST, // Test layer
#endif
    NAP_RGB_MODE_EFFECT, // Use QMK's RGB effects
    NAP_RGB_MODE_COUNT
};

uint8_t napoli1084_rgb_mode_get(void);
void napoli1084_rgb_mode_forward(void);
bool napoli1084_sync_rgb_mode_master_send(void);
void napoli1084_rgb_mode_init(void);
