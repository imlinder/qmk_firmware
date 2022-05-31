/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _SWE,
  _GAME,
  _LOWER,
  _RAISE,
  _NAV,
  _NUM,
  _ADJUST,
  _FN,
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  SWE,
  GAME,
  LOWER,
  RAISE,
};

#define CTL_DOWN MT(MOD_RCTL, KC_DOWN)
#define ALT_LEFT MT(MOD_RALT, KC_LEFT)
#define CTL_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,  KC_8,     KC_9,     KC_0,    _______,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,  KC_I,     KC_O,     KC_P,    KC_BSLS,
  CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,  KC_K,     KC_L,     KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH, RSFT_T(KC_ENT),
  MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   LT(_NUM, KC_SPC), KC_BSPC, RAISE, ALT_LEFT, CTL_DOWN, KC_UP,   KC_RIGHT
),

// å, ä and ö
[_SWE] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    RALT(KC_W),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RALT(KC_O), RALT(KC_A),
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______
),

// Gaming overrides + revert back swedish layer
[_GAME] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC,
  KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_QUOT,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT
),

[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_UP,   _______,
  _______, KC_LPRN, KC_LCBR, _______, KC_RIGHT, _______, _______, KC_UNDS, KC_PLUS, KC_RCBR, KC_RPRN, KC_PIPE,
  _______, _______, _______, _______, _______,  KC_LEFT, KC_DOWN, _______, _______, _______, _______,  _______,
  _______, _______, _______, _______, _______,  _______,  KC_DEL,  _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_RAISE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_LPRN, KC_LBRC, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_RBRC, KC_RPRN, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, KC_ENT,  _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

[_NUM] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______,    _______,
  _______, _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______, _______
),

[_NAV] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,      KC_F7,      KC_F8,      KC_F9,       KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______, _______,    LAG_NRM,    LAG_SWP,    _______,     _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    QWERTY,     SWE,        GAME,        _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______,     _______, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______,     _______, _______
),

/* [_ADJUST] = LAYOUT_preonic_grid( */
/*   KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,      KC_F7,      KC_F8,      KC_F9,       KC_F10,  KC_F11, */
/*   _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______,     _______, KC_DEL, */
/*   _______, _______, _______, _______, _______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP,   KC_MS_RIGHT, _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______,    KC_MS_BTN1, KC_MS_BTN2, _______,     _______, _______, */
/*   _______, _______, _______, _______, _______, _______, _______,    _______,    _______,    _______,     _______, _______ */
/* ), */

#define SWP_LFT MAGIC_SWAP_LALT_LGUI
#define USWP_LFT MAGIC_UNSWAP_LALT_LGUI
#define SWP_RGT MAGIC_SWAP_RALT_RGUI
#define USWP_RGT MAGIC_UNSWAP_RALT_RGUI

[_FN] = LAYOUT_preonic_grid(
  KC_F12,  KC_F1,          KC_F2,            KC_F3,   KC_F4,            KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, RGB_HUI,        RGB_SAI,          RGB_VAI, RGB_MODE_FORWARD, AU_ON,   MU_ON,   SWP_LFT, SWP_RGT, _______, _______, _______,
  RGB_TOG, RGB_HUD,        RGB_SAD,          RGB_VAD, RGB_MODE_REVERSE, AU_OFF,  MU_OFF,  USWP_LFT, USWP_RGT, _______, DEBUG,   RESET,
  _______, RGB_MODE_PLAIN, RGB_MODE_BREATHE, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  _______, _______,        _______,          _______, _______,          _______, _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case SWE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_SWE);
          }
          return false;
          break;
        case GAME:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAME);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
      }
    return true;
};

