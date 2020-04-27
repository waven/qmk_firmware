/* Copyright 2020 waven
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
#include "waven.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /* 0: Default layer */
[_DL] = LAYOUT_all(
  KC_GESC, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, KC_NO, 	 	KC_DEL,  KC_PSLS, KC_PAST, KC_PMNS,
  KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,	    KC_BSLS, 	 	KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
  MO(_CL),    KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,	KC_QUOT,KC_NO,       KC_ENT,  	 	KC_P4,   KC_P5,   KC_P6,   KC_NO,
  KC_LSFT,KC_NO,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,  KC_SLSH,        KC_RSFT,        KC_UP,  	KC_P1,   KC_P2,   KC_P3,   KC_PENT,
  KC_LCTL, KC_LGUI,KC_LALT,                    KC_NO,  KC_SPC, KC_NO,          KC_NO,  KC_RALT,MO(_FL),         KC_LEFT,KC_DOWN,KC_RGHT,     KC_P0,   KC_PDOT, KC_NO),

/* 1: Fn layer */
[_FL] = LAYOUT_all(
  KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12, RESET,   _______, 	 	KC_NLCK, _______, _______, _______,
  _______,   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_MPRV, KC_MNXT,	    KC_MSTP,	 	_______, _______, _______, _______,
  _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,     KC_MPLY, 	 	_______, _______, _______, _______,
  _______,_______,_______,_______,_______,_______,_______,_______,KC_MUTE,_______,_______, _______,        _______,       KC_VOLU,	_______, _______, _______, _______,
  _______, _______,_______,                    _______,_______,_______,        _______,_______,_______,         _______,KC_VOLD,_______,     _______, _______, _______),

 /* 2: CapsLock Fn layer */
[_CL] = LAYOUT_all(
  KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11,  KC_F12, _______, _______, 	 	KC_INS,  KC_PSCR, KC_SLCK, KC_PAUS,
  _______,   _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, _______,	    _______,	 	_______, _______, _______, TD(TD_PUH),
  _______,    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,	_______,_______,     _______, 	 	_______, _______, _______, _______,
  _______,_______,_______,_______,BL_DEC, BL_TOGG,BL_INC, BL_STEP,BL_ON,  BL_OFF, BL_BRTG, _______,        _______,       M_UNCOM,	_______, _______, _______, TD(TD_PDE),
  _______, _______,_______,                    _______,_______,_______,        _______,_______,_______,         SFT_TAB,M_COM,  KC_TAB,      _______, _______, _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_user_waven(keycode, record);
};
