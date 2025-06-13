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

#define LAYERNUM 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, TO(1)),
    [1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, TO(2)),
    [2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, TO(0))
    //
};

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
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
        }
    }
    return true;
}
