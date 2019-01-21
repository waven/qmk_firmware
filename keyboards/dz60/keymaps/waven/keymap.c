/*
Copyright 2018 David Vonau <dvonau@waven.ch> @waven

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

	[_DL] = LAYOUT_60_ansi(
		KC_ESC,  KC_1,    KC_2,    KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,            KC_BSPC,
		KC_TAB,           KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC, KC_BSLS,
		MO(_CL),          KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,  KC_ENT,
		KC_LSFT,          KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT,
		KC_LCTL, KC_LGUI,          KC_LALT,                    KC_SPC,                             KC_RALT, MO(_FL),           KC_RGUI,     KC_RCTL
  ),

	[_FL] = LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
		_______,          _______, KC_UP,   _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
		_______,          KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______,          _______, _______, _______,  BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, _______, _______,          _______,
		_______, _______,          _______,                    _______,                            _______, _______,          _______, _______
  ),

	[_CL] = LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,      KC_F12,           _______,
    _______,          _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,  _______, _______, _______,
    _______,          _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_MINUS, _______, _______,
    _______,          _______, _______, KC_CAPS, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT,            _______,
    _______, _______,          _______,                   KC_KP_0,                            KC_NLCK, _______,              _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_user_waven(keycode, record);
};
