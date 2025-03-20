#include QMK_KEYBOARD_H

// Custom keycodes for special functions
enum custom_keycodes {
    KC_CUSTM = SAFE_RANGE,  // Example custom key
    KC_MUS_ON,              // Music mode on
    KC_MUS_OFF              // Music mode off
};

// Audio Feedback Setup
#ifdef AUDIO_ENABLE
float song_startup[][2] = SONG(ODE_TO_JOY);
float song_goodbye[][2] = SONG(GOODBYE_SOUND);
#endif

// Custom macro functionality
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CUSTM:
            if (record->event.pressed) {
                SEND_STRING("Hello from Planck Rev 7!");
            }
            return false; // Skip default processing

        case KC_MUS_ON:
            if (record->event.pressed) {
                PLAY_SONG(song_startup);
            }
            return false;

        case KC_MUS_OFF:
            if (record->event.pressed) {
                stop_all_notes();
            }
            return false;
    }
    return true; // Continue default behavior
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_planck_2x2u(LT(2,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, MO(4), KC_LCTL, KC_LALT, KC_LGUI, MO(3), KC_SPC, KC_ESC, KC_LEFT, KC_RGHT, TG(6)),
    [1] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LCBR, KC_RCBR, KC_PLUS, KC_BSLS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LPRN, KC_RPRN, KC_EQL, KC_COLN, KC_DQUO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_MINS, KC_GRV, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO),
    [2] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_BSPC, KC_BSPC, KC_BSPC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO),
    [3] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, LALT(KC_BSPC), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_ENT, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_0, KC_TRNS, KC_TRNS, KC_NO),
    [4] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO),
    [5] = LAYOUT_planck_2x2u(KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS),
    // Features Layer - Complete with all RGB and audio features - Fixed keycodes
    [6] = LAYOUT_planck_2x2u(
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, KC_NO,   KC_DEL,
        AU_ON,   AU_OFF,  AU_TOGG, CK_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_MUS_ON, KC_MUS_OFF,  CK_UP,   CK_DOWN, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
        TG(6),   KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS)
};


