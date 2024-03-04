#ifndef __INSTRUCTIONS_H__

    #include "chip8.h"
    #include <stdint.h>

    extern void __00E0(Chip8 *chip8);
    extern void __00EE(Chip8 *chip8);
    extern void __1NNN(Chip8 *chip8, uint8_t nnn);
    extern void __2NNN(Chip8 *chip8, uint8_t nnn);
    extern void __3XNN(Chip8 *chip8, uint8_t x, uint8_t nn);
    extern void __4XNN(Chip8 *chip8, uint8_t x, uint8_t nn);
    extern void __5XY0(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __6XNN(Chip8 *chip8, uint8_t x, uint8_t nn);
    extern void __7XNN(Chip8 *chip8, uint8_t x, uint8_t nn);
    extern void __8XY0(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XY1(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XY2(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XY3(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XY4(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XY5(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XY6(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XY7(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __8XYE(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __9XY0(Chip8 *chip8, uint8_t x, uint8_t y);
    extern void __ANNN(Chip8 *chip8, uint8_t nnn);
    extern void __BNNN(Chip8 *chip8, uint8_t nnn);
    extern void __CXNN(Chip8 *chip8, uint8_t x, uint8_t nn);
    extern void __DXYN(Chip8 *chip8, uint8_t x, uint8_t y, uint8_t n);
    extern void __EX9E(Chip8 *chip8, uint8_t x);
    extern void __EXA1(Chip8 *chip8, uint8_t x);
    extern void __FX07(Chip8 *chip8, uint8_t x);
    extern void __FX0A(Chip8 *chip8, uint8_t x);
    extern void __FX15(Chip8 *chip8, uint8_t x);
    extern void __FX18(Chip8 *chip8, uint8_t x);
    extern void __FX1E(Chip8 *chip8, uint8_t x);
    extern void __FX29(Chip8 *chip8, uint8_t x);
    extern void __FX33(Chip8 *chip8, uint8_t x);
    extern void __FX55(Chip8 *chip8, uint8_t x);
    extern void __FX65(Chip8 *chip8, uint8_t x);

#endif // __INSTRUCTIONS_H__