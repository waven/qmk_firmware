/*
Copyright 2019 David Vonau <dvonau@waven.ch> @waven

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
  /* 0: Default layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │ ESC │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │█████│BKSPC| DEL │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ TAB │█████│  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │     │PG_UP│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │ _CL │█████│  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │ENTER│█████│PG_DN│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LSHFT│█████│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │RSHFT│█████│ UP  │ _FL │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │LCTRL│L_GUI│█████│L_GUI│█████│█████│ SPC │█████│█████│█████│R_ALT│R_CTL│     │LEFT │DOWN │RIGHT│
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 0: Default layer */
  [_DL] = LAYOUT_65_ansi(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
    MO(_CL),          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGDN,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   MO(_FL),
    KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             KC_RALT, KC_RCTL, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT
  ),

    /* 1: Function layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │  `  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │█████│RESET│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │█████│     │     │     │     │     │     │     │     │MPRV │MPLY │MNXT │     │     │     |
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │█████│     │     │     │     │     │     │     │     │     │     │     │     │█████│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │█████│     │     │ BL- │BLTOG| BL+ │     │     │MUTE │     │     │     │█████│VOLUP│     │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │█████│     │█████│█████│     │█████│█████│█████│     │     │     │     │VOLDN│     │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 1: Fn layer */
  [_FL] = LAYOUT_65_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           RESET,   _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,   _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, BL_DEC,  BL_TOGG, BL_INC,  _______, KC_MUTE, _______, _______, _______, _______,          KC_VOLU, _______,
    _______, _______,                   _______,                            _______,          _______, _______, _______, _______, KC_VOLD, _______
  ),

  /* 2: CapsLock function layer
   * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
   * │  `  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │█████│     │PAUSE│
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │█████│     │     │     │     │     │     │KP_7 │KP_8 │KP_9 │KP_- │     │     │     │ INS |
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │█████│     │     │     │     │     │     │KP_4 │KP_5 │KP_6 │KP_+ │     │     │█████│HOME │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │█████│     │     │CAPS │     │     │     │KP_1 │KP_2 │KP_3 │KPDOT│     │█████│M_UNC│ END │
   * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
   * │     │     │█████│     │█████│█████│KP_0 │█████│█████|█████│     │NLCK │     │S_TAB│M_COM│ TAB │
   * └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
   */

  /* 2: CapsLock Fn layer */
  [_CL] = LAYOUT_65_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,      KC_F12,           _______, KC_PAUS,
    _______,          _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS,  _______, _______, _______, KC_INS,
    _______,          _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_MINUS, _______, _______,          KC_HOME,
    _______,          _______, _______, KC_CAPS, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_DOT,   _______,          M_UNCOM, KC_END,
    _______, _______,                   _______,          KC_KP_0,                            _______,  KC_NLCK,    _______, SFT_TAB, M_COM,   KC_TAB
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return process_record_user_waven(keycode, record);
};
