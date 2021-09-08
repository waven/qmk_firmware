#pragma once

#ifdef TAP_DANCE_ENABLE
    #undef TAPPING_TERM
    #define TAPPING_TERM 175
#endif

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_SLEEP
#endif

#define GRAVE_ESC_CTRL_OVERRIDE
