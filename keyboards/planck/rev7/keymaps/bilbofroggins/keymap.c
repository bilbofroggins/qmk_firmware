#include QMK_KEYBOARD_H

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {KC_COLN, KC_SCLN}, // Shift : is ; 
  {KC_UNDS, KC_SPC},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

#define FUNCTION_LAYER 5
enum custom_keycodes {
    MACRO_VIM_SEARCH = SAFE_RANGE,
};

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, FUNCTION_LAYER)) {
        rgblight_sethsv_noeeprom(HSV_GREEN);
    } else {
        rgblight_sethsv_noeeprom(HSV_RED);
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_custom_shift_keys(keycode, record)) { return false; }
  // Your macros ...
  switch (keycode) {
  case MACRO_VIM_SEARCH:
      if (record->event.pressed) {
          // when keycode QMKBEST is pressed
          SEND_STRING(":s/");
      } else {
          // when keycode QMKBEST is released
      }
      break;
  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_planck_2x2u(LT(2,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(4), KC_LCTL, KC_LALT, KC_LGUI, MO(3), KC_SPC, KC_ESC, KC_LEFT, KC_RGHT, TG(5)),
    [1] = LAYOUT_planck_2x2u(KC_NO, KC_TILD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_PLUS, KC_DQUO, KC_PIPE, KC_TRNS, KC_GRV, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_EQL, KC_COLN, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_MINS, KC_BSLS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),
    [2] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_NO, KC_NO, MACRO_VIM_SEARCH, KC_NO, KC_NO, KC_BSPC, KC_BSPC, KC_BSPC, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO),
    [3] = LAYOUT_planck_2x2u(QK_LLCK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, LALT(KC_BSPC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_SLSH, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_0, KC_TRNS, KC_TRNS, QK_BOOT),
    [4] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO),
    [5] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS)
};