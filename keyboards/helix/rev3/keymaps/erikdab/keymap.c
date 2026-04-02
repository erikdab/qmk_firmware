/* Copyright 2020 yushakobo
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
#include QMK_KEYBOARD_H

// Layer names
// _GAME  : primary left-hand-only gaming layer
// _SWAP   : extra numbers and punctuation used in some games
// _FUNC   : arrows, F1-F12, media, and navigation shortcuts
// _UTIL  : GUI, delete/backspace, boot/reset, and admin keys
enum layer_names {
    _GAME = 0,
    _UTIL,
    _FUNC,
    _SWAP,
};

// Custom keycodes
// ADJUST toggles the admin/media layer on and off.
enum custom_keycodes {
    ADJUST = SAFE_RANGE,
};

// Thumb and layer helpers
#define UTIL     MO(_UTIL)
#define FUNC      MO(_FUNC)
#define SWAP     MO(_SWAP)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* GAME
     * Left-hand-only gaming layer for a single Helix half.
     *
     * Design goals:
     * - direct access to ` and 1-6
     * - strong WASD/QERFG/ZXCVB coverage
     * - no GUI on the base layer
     * - no Delete or Backspace on the base layer
     * - thumb cluster dedicated to layer access and core actions
     * - entire physical right half left empty because it is not present
     */
    [_GAME] = LAYOUT_5row(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_6,    _______, _______, _______, _______, _______, _______, _______,
        UTIL,     KC_ESC,    SWAP,     FUNC,    KC_LALT, KC_SPC, KC_ENT,  _______, _______, _______, _______, _______, _______, _______
    ),
     
    /* UTIL
     * 6-0, arrow keys and print screen
     * Plus WASD to keep moving around in games without switching layers
     * Plus Modifiers to use with any of the above keys
     */
    [_UTIL] = LAYOUT_5row(
        KC_TILD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                       _______, _______, _______, _______, _______, _______,
        KC_TAB,  KC_Q,     KC_W,   KC_E, KC_R, KC_PGUP,                           _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D, KC_UP,  KC_PGDN,                             _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_Z,    KC_X,    KC_LEFT, KC_DOWN,    KC_RGHT, KC_PSCR, _______, _______, _______, _______, _______, _______, _______,
        _______,     KC_ESC, SWAP,     FUNC,   KC_LALT, KC_SPC, KC_ENT,  _______, _______, _______, _______, _______, _______, _______
    ),

    /* FUNC/
     * Function keys and home/end/pgup/pgdn for navigation
     * Plus WASD to keep moving around in games without switching layers
     * Plus Modifiers to use with any of the above keys
     */
    [_FUNC] = LAYOUT_5row(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       _______, _______, _______, _______, _______, _______,
        KC_TAB, KC_Q,     KC_W,   KC_E, KC_F9, KC_F10,                      _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_UP,  KC_F11,                     _______, _______, _______, _______, _______, _______,
        KC_LSFT,   KC_F7,   KC_F8,   KC_LEFT, KC_DOWN,    KC_RGHT,   KC_F12,  _______,  _______, _______, _______, _______, _______, _______,
        UTIL,     KC_ESC,    SWAP,     _______,  KC_LALT, KC_SPC, KC_ENT,  _______,  _______, _______, _______, _______, _______, _______
    ),

    /* SWAP
     * Right half of keyboard with numbers and punctuation, for games that use those keys more than the left half
     * Plus arrow keys
     * Plus Modifiers to use with any of the above keys
     */
    [_SWAP] = LAYOUT_5row(
        KC_TILD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                     _______, _______, _______, _______, _______, _______,
        KC_TAB, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                      _______, _______, _______, _______, _______, _______,
        KC_LCTL, KC_H,    KC_J,    KC_K,    KC_UP,    KC_L,                   _______, _______, _______, _______, _______, _______,
        KC_LSFT, KC_N,    KC_M,    KC_LEFT, KC_DOWN,    KC_RGHT,    KC_COMM, _______, _______, _______, _______, _______, _______, _______,
        UTIL,     KC_ESC,    _______,     FUNC,  KC_LALT, KC_SPC, KC_ENT,  _______, _______, _______, _______, _______, _______, _______
    ),
};
