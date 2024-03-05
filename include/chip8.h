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
#define KEYMAP_SIZE     16

int keymap[KEYMAP_SIZE] = {
    49, 50, 51,67,    // 1 2 3 C
    52, 68, 55, 56,   // 4 5 6 D
    57, 58, 59, 69, // 7 8 9 E
    65,79, 66, 70,// A O B F
};


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


typedef struct Chip8{
    uint8_t RAM[MEM_SIZE];
    uint8_t V[REG_SIZE];
    uint8_t display[DISPLAY_HEIGHT][DISPLAY_WIDTH];
    uint8_t delay_timer;
    uint8_t sound_timer;
    uint16_t I;
    uint16_t PC;
    int SP;
    uint16_t* chip8_stack;
    uint8_t key;
}Chip8;

void push(Chip8* chip8, uint16_t value);
uint16_t pop(Chip8* chip8);
void set_key(Chip8 *chip8, uint8_t key_pressed);
void reset_key(Chip8 *chip8);

#endif // __CHIP8_H__