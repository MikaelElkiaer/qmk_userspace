// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#define TOP 0
#define NAV 1
#define SYM 2
#define FUN 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌────┬───────────┬───────────┬───────────┬──────────────┬──────────────┐               ┌───────────────┬───────────┬───────────┬───────────┬───────────┬────┐
//    │ no │     q     │     w     │     e     │      r       │      t       │               │       p       │     y     │     u     │     i     │     o     │ no │
//    ├────┼───────────┼───────────┼───────────┼──────────────┼──────────────┤               ├───────────────┼───────────┼───────────┼───────────┼───────────┼────┤
//    │ no │ LCTL_T(a) │ LSFT_T(s) │ LGUI_T(d) │  LALT_T(f)   │  RALT_T(g)   │               │   RALT_T(;)   │ LALT_T(h) │ RGUI_T(j) │ RSFT_T(k) │ RCTL_T(l) │ no │
//    ├────┼───────────┼───────────┼───────────┼──────────────┼──────────────┤               ├───────────────┼───────────┼───────────┼───────────┼───────────┼────┤
//    │ no │     z     │     x     │     c     │      v       │      b       │               │       /       │     n     │     m     │     ,     │     .     │ no │
//    └────┴───────────┴───────────┴───────────┼──────────────┼──────────────┼─────┐   ┌─────┼───────────────┼───────────┼───────────┴───────────┴───────────┴────┘
//                                             │ LT(FUN, esc) │ LT(SYM, spc) │ tab │   │ ent │ LT(NAV, bspc) │    no     │
//                                             └──────────────┴──────────────┴─────┘   └─────┴───────────────┴───────────┘
[TOP] = LAYOUT_split_3x6_3(
  KC_NO , KC_Q         , KC_W         , KC_E         , KC_R            , KC_T            ,                       KC_P             , KC_Y         , KC_U         , KC_I         , KC_O         , KC_NO,
  KC_NO , LCTL_T(KC_A) , LSFT_T(KC_S) , LGUI_T(KC_D) , LALT_T(KC_F)    , RALT_T(KC_G)    ,                       RALT_T(KC_SCLN)  , LALT_T(KC_H) , RGUI_T(KC_J) , RSFT_T(KC_K) , RCTL_T(KC_L) , KC_NO,
  KC_NO , KC_Z         , KC_X         , KC_C         , KC_V            , KC_B            ,                       KC_SLSH          , KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_NO,
                                                       LT(FUN, KC_ESC) , LT(SYM, KC_SPC) , KC_TAB ,     KC_ENT , LT(NAV, KC_BSPC) , KC_NO
),

//    ┌────┬──────┬─────────────────────────────┬───────────────────┬──────┬─────────────┐             ┌──────────────┬──────────────────┬──────────────┬────────────┬──────────────┬────┐
//    │ no │  no  │             no              │        no         │  no  │     no      │             │     pscr     │        no        │     pgup     │     no     │      no      │ no │
//    ├────┼──────┼─────────────────────────────┼───────────────────┼──────┼─────────────┤             ├──────────────┼──────────────────┼──────────────┼────────────┼──────────────┼────┤
//    │ no │ lctl │ LSFT_T(locking_scroll_lock) │   LGUI_T(pgdn)    │ lalt │ RALT_T(end) │             │ RALT_T(home) │   LALT_T(left)   │ RGUI_T(down) │ RSFT_T(up) │ RCTL_T(rght) │ no │
//    ├────┼──────┼─────────────────────────────┼───────────────────┼──────┼─────────────┤             ├──────────────┼──────────────────┼──────────────┼────────────┼──────────────┼────┤
//    │ no │  no  │             del             │ locking_caps_lock │  no  │    paus     │             │      no      │ locking_num_lock │     app      │     no     │      no      │ no │
//    └────┴──────┴─────────────────────────────┴───────────────────┼──────┼─────────────┼────┐   ┌────┼──────────────┼──────────────────┼──────────────┴────────────┴──────────────┴────┘
//                                                                  │  no  │     no      │ no │   │ no │      no      │        no        │
//                                                                  └──────┴─────────────┴────┘   └────┴──────────────┴──────────────────┘
[NAV] = LAYOUT_split_3x6_3(
  KC_NO , KC_NO   , KC_NO           , KC_NO           , KC_NO   , KC_NO          ,                     KC_PSCR         , KC_NO           , KC_PGUP         , KC_NO         , KC_NO           , KC_NO,
  KC_NO , KC_LCTL , LSFT_T(KC_LSCR) , LGUI_T(KC_PGDN) , KC_LALT , RALT_T(KC_END) ,                     RALT_T(KC_HOME) , LALT_T(KC_LEFT) , RGUI_T(KC_DOWN) , RSFT_T(KC_UP) , RCTL_T(KC_RGHT) , KC_NO,
  KC_NO , KC_NO   , KC_DEL          , KC_LCAP         , KC_NO   , KC_PAUS        ,                     KC_NO           , KC_LNUM         , KC_APP          , KC_NO         , KC_NO           , KC_NO,
                                                        KC_NO   , KC_NO          , KC_NO ,     KC_NO , KC_NO           , KC_NO
),

//    ┌────┬───────────┬───────────┬───────────┬───────────┬────┐             ┌────┬───────────┬───────────┬───────────┬─────────┬────┐
//    │ no │     {     │     }     │     (     │     )     │ no │             │ no │     7     │     8     │     9     │ RALT(w) │ no │
//    ├────┼───────────┼───────────┼───────────┼───────────┼────┤             ├────┼───────────┼───────────┼───────────┼─────────┼────┤
//    │ no │ LCTL_T(`) │ LSFT_T(-) │ LGUI_T(=) │ LALT_T(') │ \  │             │ no │ LALT_T(4) │ RGUI_T(5) │ RSFT_T(6) │ RALT(l) │ no │
//    ├────┼───────────┼───────────┼───────────┼───────────┼────┤             ├────┼───────────┼───────────┼───────────┼─────────┼────┤
//    │ no │     <     │     >     │     [     │     ]     │ no │             │ no │     1     │     2     │     3     │ RALT(z) │ no │
//    └────┴───────────┴───────────┴───────────┼───────────┼────┼────┐   ┌────┼────┼───────────┼───────────┴───────────┴─────────┴────┘
//                                             │    no     │ no │ no │   │ no │ 0  │    no     │
//                                             └───────────┴────┴────┘   └────┴────┴───────────┘
[SYM] = LAYOUT_split_3x6_3(
  KC_NO , KC_LCBR        , KC_RCBR         , KC_LPRN        , KC_RPRN         , KC_NO   ,                     KC_NO , KC_7         , KC_8         , KC_9         , RALT(KC_W) , KC_NO,
  KC_NO , LCTL_T(KC_GRV) , LSFT_T(KC_MINS) , LGUI_T(KC_EQL) , LALT_T(KC_QUOT) , KC_BSLS ,                     KC_NO , LALT_T(KC_4) , RGUI_T(KC_5) , RSFT_T(KC_6) , RALT(KC_L) , KC_NO,
  KC_NO , KC_LT          , KC_GT           , KC_LBRC        , KC_RBRC         , KC_NO   ,                     KC_NO , KC_1         , KC_2         , KC_3         , RALT(KC_Z) , KC_NO,
                                                              KC_NO           , KC_NO   , KC_NO ,     KC_NO , KC_0  , KC_NO
),

//    ┌────┬──────────────┬──────────────┬──────────────┬──────────────┬─────────┐             ┌────┬────┬────┬────┬─────┬────┐
//    │ no │     mply     │     mute     │      no      │    QK_RBT    │  bRIU   │             │ no │ f7 │ f8 │ f9 │ f12 │ no │
//    ├────┼──────────────┼──────────────┼──────────────┼──────────────┼─────────┤             ├────┼────┼────┼────┼─────┼────┤
//    │ no │ LCTL_T(mprv) │ LSFT_T(vold) │ LGUI_T(volu) │ LALT_T(mnxt) │  bRID   │             │ no │ f4 │ f5 │ f6 │ f11 │ no │
//    ├────┼──────────────┼──────────────┼──────────────┼──────────────┼─────────┤             ├────┼────┼────┼────┼─────┼────┤
//    │ no │      no      │      no      │      no      │      no      │ QK_BOOT │             │ no │ f1 │ f2 │ f3 │ f10 │ no │
//    └────┴──────────────┴──────────────┴──────────────┼──────────────┼─────────┼────┐   ┌────┼────┼────┼────┴────┴─────┴────┘
//                                                      │      no      │   no    │ no │   │ no │ no │ no │
//                                                      └──────────────┴─────────┴────┘   └────┴────┴────┘
[FUN] = LAYOUT_split_3x6_3(
  KC_NO , KC_MPLY         , KC_MUTE         , KC_NO           , QK_RBT          , KC_BRIU ,                     KC_NO , KC_F7 , KC_F8 , KC_F9 , KC_F12 , KC_NO,
  KC_NO , LCTL_T(KC_MPRV) , LSFT_T(KC_VOLD) , LGUI_T(KC_VOLU) , LALT_T(KC_MNXT) , KC_BRID ,                     KC_NO , KC_F4 , KC_F5 , KC_F6 , KC_F11 , KC_NO,
  KC_NO , KC_NO           , KC_NO           , KC_NO           , KC_NO           , QK_BOOT ,                     KC_NO , KC_F1 , KC_F2 , KC_F3 , KC_F10 , KC_NO,
                                                                KC_NO           , KC_NO   , KC_NO ,     KC_NO , KC_NO , KC_NO
)
};
