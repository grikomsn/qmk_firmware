/* Copyright 2020 sendyyeah
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

#define LAYERNUM 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(TO(0), TO(1), TO(2), TO(3), KC_NO),
    [1] = LAYOUT(TO(0), TO(1), TO(2), TO(3), KC_NO),
    [2] = LAYOUT(TO(0), TO(1), TO(2), TO(3), KC_NO),
    [3] = LAYOUT(TO(0), TO(1), TO(2), TO(3), KC_NO)
    //
};

const uint16_t PROGMEM mash_combo[] = {TO(0), TO(1), TO(2), TO(3), COMBO_END};
combo_t                key_combos[] = {
    COMBO(mash_combo, KC_SYSTEM_POWER),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (layer_state_is(0)) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (layer_state_is(1)) {
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
        } else if (layer_state_is(2)) {
            if (clockwise) {
                tap_code16(RCMD(RSFT(KC_Z)));
            } else {
                tap_code16(RCMD(KC_Z));
            }
        } else if (layer_state_is(3)) {
            if (clockwise) {
                tap_code16(QK_MOUSE_WHEEL_DOWN);
            } else {
                tap_code16(QK_MOUSE_WHEEL_UP);
            }
        }
    }
    return false;
}
