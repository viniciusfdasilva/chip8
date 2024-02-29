#ifndef __CHIP8_H__

#include <stdint.h>
#include <stdio.h>

#define panic(x) printf("%d",x); exit(1);
#define MEM_SIZE        4096
#define DISPLAY_WIDTH   64
#define DISPLAY_HEIGHT  32
#define F               0xF
#define PROGRAM_ADDRESS 0x200
#define SPRITE_SIZE     8
#define FONT_SIZE       16
#define REG_SIZE        16
#define STACK_SIZE      16

int font[FONT_SIZE][SPRITE_SIZE] = {
    {0xF0, 0x90, 0x90, 0x90, 0xF0}, // 0
    {0x20, 0x60, 0x20, 0x20, 0x70}, // 1
    {0xF0, 0x10, 0xF0, 0x80, 0xF0}, // 2
    {0xF0, 0x10, 0xF0, 0x10, 0xF0}, // 3
    {0x90, 0x90, 0xF0, 0x10, 0x10}, // 4
    {0xF0, 0x80, 0xF0, 0x10, 0xF0}, // 5
    {0xF0, 0x80, 0xF0, 0x90, 0xF0}, // 6
    {0xF0, 0x10, 0x20, 0x40, 0x40}, // 7
    {0xF0, 0x90, 0xF0, 0x90, 0xF0}, // 8
    {0xF0, 0x90, 0xF0, 0x10, 0xF0}, // 9
    {0xF0, 0x90, 0xF0, 0x90, 0x90}, // A
    {0xE0, 0x90, 0xE0, 0x90, 0xE0}, // B
    {0xF0, 0x80, 0x80, 0x80, 0xF0}, // C
    {0xE0, 0x90, 0x90, 0x90, 0xE0}, // D
    {0xF0, 0x80, 0xF0, 0x80, 0xF0}, // E
    {0xF0, 0x80, 0xF0, 0x80, 0x80}, // F
};

typedef uint16_t* stack;

typedef struct Chip8{
    uint8_t RAM[MEM_SIZE];
    uint8_t V[REG_SIZE];
    uint8_t display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint16_t I;
    uint16_t PC;
    uint16_t SP;
    stack chip8_stack;
}Chip8;

#endif // __CHIP8_H__