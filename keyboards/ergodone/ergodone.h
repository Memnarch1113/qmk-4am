#ifndef ERGODOX_ERGODONE_H
#define ERGODOX_ERGODONE_H

#include "quantum.h"
#include <stdint.h>
#include <stdbool.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

void init_ergodox(void);

inline void ergodox_right_led_1_off(void) { DDRB &= ~(1<<PB5); PORTB &= ~(1<<PB5); }
inline void ergodox_right_led_1_on(void) { DDRB |= (1<<PB5); PORTB |= (1<<PB5); }
inline void ergodox_right_led_2_off(void) { DDRB &= ~(1<<PB6); PORTB &= ~(1<<PB6); }
inline void ergodox_right_led_2_on(void) { DDRB |= (1<<PB6); PORTB |= (1<<PB6); }
inline void ergodox_right_led_3_off(void) { DDRB &= ~(1<<PB3); PORTB &= ~(1<<PB3); }
inline void ergodox_right_led_3_on(void) { DDRB |= (1<<PB3); PORTB |= (1<<PB3); }
inline void ergodox_right_led_on(uint8_t l) {
    switch (l) {
         case 1:
             ergodox_right_led_1_on();
             break;
         case 2:
             ergodox_right_led_2_on();
             break;
         case 3:
             ergodox_right_led_3_on();
             break;
         default:
             break;
        }
}

inline void ergodox_right_led_off(uint8_t l) {
    switch (l) {
         case 1:
             ergodox_right_led_1_off();
             break;
         case 2:
             ergodox_right_led_2_off();
             break;
         case 3:
             ergodox_right_led_3_off();
             break;
         default:
             break;
        }
}
inline void ergodox_board_led_off(void) { DDRB &= ~(1<<PB0); PORTB |= (1<<PB0); }
inline void ergodox_board_led_on(void) { DDRB |= (1<<PB0); PORTB &= ~(1<<PB0); }
inline void ergodox_led_all_on(void) {
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
    ergodox_board_led_on();
}
inline void ergodox_led_all_off(void) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_board_led_off();
}
inline void ergodox_right_led_1_set(uint8_t n)          {}
inline void ergodox_right_led_2_set(uint8_t n)          {}
inline void ergodox_right_led_3_set(uint8_t n)          {}
inline void ergodox_right_led_set(uint8_t l, uint8_t n) {}
inline void ergodox_led_all_set(uint8_t n)              {}

#define KEYMAP( \
	    L00, L01, L02, L03, L04, L05, L06, L07, L08,     \
		  L10, L11, L12, L13, L14, L15, L16, L17, L18,     \
		  L20, L21, L22, L23, L24, L25, L26, L27, L28,     \
		  L30, L31, L32, L33, L34, L35, L36, L37, L38,     \
		  L40, L41, L42, L43, L44, L45, L46, L47, L48,     \
                                                       \
      R00, R01, R02, R03, R04, R05, R06, R07, R08,     \
      R10, R11, R12, R13, R14, R15, R16, R17, R18,     \
      R20, R21, R22, R23, R24, R25, R26, R27, R28,     \
      R30, R31, R32, R33, R34, R35, R36, R37, R38,     \
      R40, R41, R42, R43, R44, R45, R46, R47, R48      \
	) \
	{ \
		{ L00, L01, L02, L03, L04, L05, L06, L07, L08,    R00, R01, R02, R03, R04, R05, R06, R07, R08}, \
		{ L10, L11, L12, L13, L14, L15, L16, L17, L18,    R10, R11, R12, R13, R14, R15, R16, R17, R18}, \
		{ L20, L21, L22, L23, L24, L25, L26, L27, L28,    R20, R21, R22, R23, R24, R25, R26, R27, R28}, \
		{ L30, L31, L32, L33, L34, L35, L36, L37, L38,    R30, R31, R32, R33, R34, R35, R36, R37, R38}, \
		{ L40, L41, L42, L43, L44, L45, L46, L47, L48,    R40, R41, R42, R43, R44, R45, R46, R47, R48}  \
  }

#define LAYOUT_ergodox KEYMAP
// #define LAYOUT_ergodox_pretty KEYMAP_PRETTY

#endif
