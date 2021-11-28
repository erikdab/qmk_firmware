#include QMK_KEYBOARD_H

enum tapdance_keycodes {
    TD_KEY_2,
};

void dance_key_two (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_BTN2);
        reset_tap_dance (state);
    } else if (state->count == 2) {
        tap_code(KC_CAPS);
        reset_tap_dance (state);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_KEY_2] = ACTION_TAP_DANCE_FN(dance_key_two),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
          KC_BTN1,
          TD(TD_KEY_2)
          )
};
