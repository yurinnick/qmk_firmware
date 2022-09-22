/*
 * Copyright 2020 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2020 Anthony MARIN <anthony@hidtech.ca>
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

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE TT(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQUAL,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,     KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLASH,
                             KC_LBRC, KC_SPC,   KC_ENT,      KC_DEL,  KC_BSPC, KC_RBRC,
                                       KC_LGUI, LOWER,       RAISE,   KC_LCTRL
),
[_LOWER] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
                             KC_LCBR, _______, _______,     _______, _______, KC_RBRC,
                                      _______, _______,     _______, _______
),
[_RAISE] = LAYOUT(
  _______, _______, _______,     _______,       _______, _______,           _______, _______, _______,   _______, _______,   _______,
  _______, _______, C(KC_RIGHT), _______,       _______, _______,           _______, _______, KC_PGDOWN, KC_PGUP, RCS(KC_P), _______,
  _______, _______, C(KC_S),     KC_DEL,        C(KC_F), C(KC_G),           KC_HOME, KC_LEFT, KC_DOWN,   KC_UP,   KC_RGHT,   KC_END,
  _______, C(KC_Z), C(KC_X),     C(KC_C),       C(KC_V), C(KC_LEFT),        _______, _______, _______,   _______, _______,   _______,
                                 LSA(KC_LEFT),  _______, _______,           _______, _______, LSA(KC_RIGHT),
                                                _______, _______,           _______, _______

),
[_ADJUST] = LAYOUT(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______,         _______, _______, _______,
                                      _______, _______,         _______, _______
)
};

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_mode_noeeprom(RGB_MODE_RAINBOW);
}
#endif
