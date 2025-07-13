/* Copyright 2022 Yiancar
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
#include "process_combo.h"
#include "process_key_override.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_65_ansi(/* default mac */
    QK_GESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_HOME,
    KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_PGUP,
    KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,     KC_PGDN,
    KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,                KC_UP,      KC_END,
    KC_LCTL,    KC_LALT,    KC_LGUI,                            KC_SPC,                                         KC_RGUI,    KC_RALT,    MO(1),      KC_LEFT,    KC_DOWN,    KC_RGHT),

[1] = LAYOUT_65_ansi(/* alternate mac */
    KC_GRV,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_DEL,     KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
    KC_TRNS,    RGB_TOG,    RGB_MOD,    RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,    RGB_VAD,    RGB_VAI,    RGB_SPD,    RGB_SPI,    KC_TRNS,                KC_VOLU,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,                                        KC_TRNS,    MO(2),      KC_TRNS,    KC_BRID,    KC_VOLD,    KC_BRIU),

[2] = LAYOUT_65_ansi(
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,                                        MO(3),      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),

[3] = LAYOUT_65_ansi(
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    QK_BOOT,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,                            KC_TRNS,                                        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS),
};

const uint16_t PROGMEM grave_combo[]        = {QK_GESC, KC_1,       COMBO_END};
// const uint16_t PROGMEM bright_down_combo[]  = {KC_1,    KC_2,       COMBO_END};
// const uint16_t PROGMEM bright_up_combo[]    = {KC_2,    KC_3,       COMBO_END};
// const uint16_t PROGMEM vol_down_combo[]     = {KC_0,    KC_MINS,    COMBO_END};
// const uint16_t PROGMEM vol_up_combo[]       = {KC_MINS, KC_EQL,     COMBO_END};
// const uint16_t PROGMEM vol_mute_combo[]     = {KC_0,    KC_MINS,    KC_EQL,     COMBO_END};

combo_t key_combos[] = {
    COMBO(grave_combo,          KC_GRV),
//     COMBO(bright_down_combo,    KC_BRID),
//     COMBO(bright_up_combo,      KC_BRIU),
//     COMBO(vol_down_combo,       KC_VOLD),
//     COMBO(vol_up_combo,         KC_VOLU),
//     COMBO(vol_mute_combo,       KC_MUTE),
};

const key_override_t lctl_bspc_as_del_override  = ko_make_basic(MOD_BIT_LCTRL, KC_BSPC, KC_DEL);
const key_override_t rgui_gesc_as_is_override   = ko_make_basic(MOD_BIT_RGUI, QK_GESC, LGUI(KC_GRV));
const key_override_t rshift_gesc_as_is_override = ko_make_basic(MOD_BIT_RSHIFT, QK_GESC, LSFT(KC_ESC));

const key_override_t *key_overrides[] = {
    &lctl_bspc_as_del_override,
    &rgui_gesc_as_is_override,
    &rshift_gesc_as_is_override,
};
