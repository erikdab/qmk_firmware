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


// Defines names for use in layer keycodes and the keymap
enum layer_names {
  _QWERTY = 0,
  _SWAP,
  _FUNCTION,
  _SWAPFX
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  SWAPFX = SAFE_RANGE
};

#define SWAP MO(_SWAP)
#define FUNCTION MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |
   * |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |
   * |------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |
   * |------+------+------+------+------+------+------.
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Enter|
   * |------+------+------+------+------+------+------|
   * |SwapFX| Esc  | Alt  | GUI  | Func | SWAP | Space|
   * `------------------------------------------------'
   */
  [_QWERTY] = LAYOUT( \
      KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,       KC_5,                      _______, _______, _______, _______, _______, _______, \
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,       KC_T,                      _______, _______, _______, _______, _______, _______, \
      KC_LCTL,   KC_A,    KC_S,    KC_D,    KC_F,       KC_G,                      _______, _______, _______, _______, _______, _______, \
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,       KC_B,    KC_DEL, _______,  _______, _______, _______, _______, _______, _______, \
      SWAPFX,    KC_ESC,  KC_LALT, KC_SPC , FUNCTION,   SWAP,    KC_ENT, _______,  _______, _______, _______, _______, _______, _______ \
    ),
  /* SWAP
   * ,-----------------------------------------.
   * | Del  |   6  |   7  |   8  |   9  |   0  |
   * |------+------+------+------+------+------|
   * | Bksp |   Y  |   U  |   I  |   O  |   P  |
   * |------+------+------+------+------+------|
   * | Ctrl |   H  |   J  |   K  |   L  |   ;  |
   * |------+------+------+------+------+------+------.
   * | Shift|   N  |   M  |   ,  |   .  |   /  |  '   |
   * |------+------+------+------+------+------+------|
   * |      |      | Alt  | GUI  |      |      |  |   |
   * `------------------------------------------------'
   */
  [_SWAP] = LAYOUT( \
      KC_GRV,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      _______, _______, _______, _______, _______, _______, \
      KC_TAB,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,                      _______, _______, _______, _______, _______, _______, \
      KC_LCTL, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,                   _______, _______, _______, _______, _______, _______, \
      KC_LSFT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSPC, _______, _______, _______, _______, _______, _______, _______, \
      _______, KC_ESC, KC_LALT, KC_SPC, _______, _______, KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
      ),

  /* FUNCTION
   * ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |
   * |------+------+------+------+------+------|
   * |      |   Q  |  Up  |   E  | Home | PGUP |
   * |------+------+------+------+------+------|
   * | Ctrl | Left | Down | Right|  End | PGDN |
   * |------+------+------+------+------+------+------.
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |
   * |------+------+------+------+------+------+------|
   * |      |      | Alt  | GUI  |      |      |      |
   * `------------------------------------------------'
   */
  [_FUNCTION] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     _______, _______, _______, _______, _______, _______, \
      KC_TAB, KC_Q,    KC_UP,   KC_E,    KC_HOME, KC_PGUP,                   _______, _______, _______, _______, _______, _______, \
      KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN,                   _______, _______, _______, _______, _______, _______, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    _______, KC_DEL, _______, _______, _______, _______, _______, _______, _______, \
      _______, KC_ESC, KC_LALT, KC_SPC, _______, _______, KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
      ),

  /* SWAPFX (SWAP + FUNCTION)
   * ,-----------------------------------------.
   * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|
   * |      |   Q  |  Up  |   E  | Home | PGUP |
   * |------+------+------+------+------+------|
   * | Ctrl | Left | Down | Right|  End | PGDN |
   * |------+------+------+------+------+------+------.
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |
   * |------+------+------+------+------+------+------|
   * |      |      | Alt  | GUI  |      |      |      |
   * `------------------------------------------------'
   */
  [_SWAPFX] =  LAYOUT( \
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    _______, _______, _______, _______, _______, _______, \
      KC_TAB, KC_Q,    KC_UP,   KC_E,    KC_HOME, KC_PGUP,                   _______, _______, _______, _______, _______, _______, \
      KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_PGDN,                   _______, _______, _______, _______, _______, _______, \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    _______, KC_DEL, _______, _______, _______, _______, _______, _______, _______, \
      _______, KC_ESC, KC_LALT, KC_SPC, _______, KC_LGUI, KC_ENT, _______, _______, _______, _______, _______, _______, _______ \
      )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SWAP, _FUNCTION, _SWAPFX);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SWAPFX:
      if (record->event.pressed) {
        layer_on(_SWAP);
        layer_on(_FUNCTION);
      } else {
        layer_off(_SWAP);
        layer_off(_FUNCTION);
      }
      break;
  }
  return true;
}
