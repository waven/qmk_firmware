/*
Copyright 2019 @waven

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
#include QMK_KEYBOARD_H
#include "waven.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DL] = LAYOUT_65_ansi_blocker( \
        KC_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS, \
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
        MO(_CL), KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  _______,         \
        KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,   _______,         \
        KC_LCTL, KC_LGUI, KC_LALT,                        KC_SPC,                          KC_RALT, MO(_FL), KC_LEFT, KC_DOWN, KC_RGHT \
    ),
[_FL] = LAYOUT_65_ansi_blocker( \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET,   KC_PSCR, \
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, KC_MPRV, KC_MNXT, KC_MSTP, KC_SLCK, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, _______,          \
        _______, _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, KC_MUTE, _______, _______, _______, _______, KC_VOLU, _______,          \
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_VOLD, _______  \
    ),
[_CL] = LAYOUT_65_ansi_blocker( \
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,      KC_F11,    KC_F12,  _______, TD(TD_PUH),  \
        _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_MINUS, _______,   _______, _______, TD(TD_PDE),  \
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,  _______,   _______, _______,              \
        _______, _______, _______, KC_CAPS, _______, _______, KC_NLCK, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT,   _______,   M_UNCOM, _______,              \
        _______, _______, _______,                            KC_KP_0,                            _______,     KC_RCTRL,  SFT_TAB, M_COM,   KC_TAB       \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_user_waven(keycode, record);
};

// initialize matrix
void matrix_init_user(void) {
    rgblight_set_effect_range(4,4);
}
