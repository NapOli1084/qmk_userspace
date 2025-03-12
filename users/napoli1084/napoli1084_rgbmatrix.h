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

#include "quantum/action.h"

#include <stdint.h>

#ifdef RGB_MATRIX_ENABLE
    bool napoli1084_process_rgb_matrix(uint16_t keycode, keyrecord_t *record);

    #define RGB_MATRIX_ONLY(...) __VA_ARGS__
#else
    #define RGB_MATRIX_ONLY(...)
#endif

