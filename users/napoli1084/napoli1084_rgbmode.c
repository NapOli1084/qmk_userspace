// Copyright 2022-2025 NapOli1084 (@napoli1084)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "napoli1084_rgbmode.h"

#include "quantum/bitwise.h"
#include "quantum/action_layer.h"
#include "quantum/logging/debug.h"
#include "quantum/split_common/transactions.h"

#ifndef NAP_RGB_MODE_INITIAL
#define NAP_RGB_MODE_INITIAL 0
#endif

static uint8_t nap_rgb_mode = NAP_RGB_MODE_INITIAL;

uint8_t napoli1084_rgb_mode_get(void) {
    return nap_rgb_mode;
}

__attribute__((weak)) void napoli1084_rgb_mode_on_set(uint8_t rgb_mode) {
}

void napoli1084_rgb_mode_set(uint8_t rgb_mode) {
    napoli1084_rgb_mode_on_set(rgb_mode);
    nap_rgb_mode = rgb_mode;
    dprintf("nap rgb layer mode: %u\n", nap_rgb_mode);
    dprintf("nap rgb layer highest layer: %u\n", get_highest_layer(layer_state));
    dprintf("nap rgb layer default layer: %u\n", get_highest_layer(default_layer_state));
}

void napoli1084_rgb_mode_forward(void) {
    uint8_t rgb_mode = nap_rgb_mode;
    ++rgb_mode;
    rgb_mode %= NAP_RGB_MODE_COUNT;
    napoli1084_rgb_mode_set(rgb_mode);
}

typedef struct _master_to_slave_rgb_mode_t {
    uint8_t rgb_mode;
} master_to_slave_rgb_mode_t;

void napoli1084_sync_rgb_mode_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const master_to_slave_rgb_mode_t* m2s = (const master_to_slave_rgb_mode_t*)in_data;
    nap_rgb_mode = m2s->rgb_mode;
}

bool napoli1084_sync_rgb_mode_master_send(void) {
    master_to_slave_rgb_mode_t m2s = {nap_rgb_mode};
    if (transaction_rpc_send(NAPOLI1084_SYNC_RGB_MODE, sizeof(m2s), &m2s)) {
        //dprintf("napoli1084 slave sync rgb mode sent\n");
        return true;
    }

    dprintf("napoli1084 slave sync rgb mode failed\n");
    return false;
}

void napoli1084_rgb_mode_init(void) {
    transaction_register_rpc(NAPOLI1084_SYNC_RGB_MODE, napoli1084_sync_rgb_mode_slave_handler);
}
