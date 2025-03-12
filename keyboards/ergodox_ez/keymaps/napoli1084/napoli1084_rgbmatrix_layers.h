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

#include "napoli1084_colors.h"
#include "ergodox_ez.h"

#define NAPOLI1084_RGBMATRIX_LYR_WINDOWS LED_LAYOUT_ergodox_pretty( \
    {HSV_RED}    ,{HSV_RED}    ,{HSV_WHITE}  ,{HSV_GREEN}  ,{HSV_GREEN}  ,    {HSV_RED}    ,{HSV_RED}    ,{HSV_WHITE}  ,{HSV_GREEN}  ,{HSV_GREEN}  ,  \
    {HSV_RED}    ,{HSV_RED}    ,{HSV_WHITE}  ,{HSV_GREEN}  ,{HSV_GREEN}  ,    {HSV_RED}    ,{HSV_RED}    ,{HSV_WHITE}  ,{HSV_GREEN}  ,{HSV_GREEN}  ,  \
    {HSV_WHITE}  ,{HSV_WHITE}  ,{HSV_WHITE}  ,{HSV_WHITE}  ,{HSV_WHITE}  ,    {HSV_WHITE}  ,{HSV_WHITE}  ,{HSV_WHITE}  ,{HSV_WHITE}  ,{HSV_WHITE}  ,  \
    {HSV_BLUE}   ,{HSV_BLUE}   ,{HSV_WHITE}  ,{HSV_YELLOW} ,{HSV_YELLOW} ,    {HSV_BLUE}   ,{HSV_BLUE}   ,{HSV_WHITE}  ,{HSV_YELLOW} ,{HSV_YELLOW} ,  \
    {HSV_BLUE}   ,{HSV_BLUE}   ,{HSV_WHITE}  ,{HSV_YELLOW} ,                                {HSV_BLUE}   ,{HSV_WHITE}  ,{HSV_YELLOW} ,{HSV_YELLOW} )
