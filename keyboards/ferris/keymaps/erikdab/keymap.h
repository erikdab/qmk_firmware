/* Copyright 2020 Dustin Bosveld <steamyleafjuice@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _GAME,
    _MEDR,
    _NAVR,
    _MOUR,
    _NSL,
    _FUNL,
    _NSSL,
};

/* Add definitions for MT and LT */
#define SHFT_F MT(MOD_LSFT, KC_F)
#define SHFT_J MT(MOD_RSFT, KC_J)
#define CTRL_D MT(MOD_LCTL, KC_D)
#define CTRL_K MT(MOD_LCTL, KC_K)
#define ALT_S MT(MOD_LALT, KC_S)
#define ALT_L MT(MOD_LALT, KC_L)
#define AGR_X MT(MOD_RALT, KC_X)
#define AGR_DOT MT(MOD_RALT, KC_DOT)
#define GUI_A MT(MOD_LGUI, KC_A)
#define GUI_QUOT MT(MOD_LGUI, KC_QUOT)
#define MED_ESC LT(_MEDR, KC_ESC)
#define NAV_SPC LT(_NAVR, KC_SPC)
#define MOS_TAB LT(_MOUR, KC_TAB)
#define SYM_ENT LT(_NSSL, KC_ENT)
#define NUM_BSC LT(_NSL, KC_BSPC)
#define FN_DEL LT(_FUNL, KC_DEL)
#define BASE DF(_BASE)
#define GAME DF(_GAME)
#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO
