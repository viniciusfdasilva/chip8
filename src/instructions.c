#include "../include/instructions.h"

#include <stdint.h>
#include <stdlib.h>

void __00E0(Chip8 *chip8)
{
    for(int y = 0; y < DISPLAY_HEIGHT; y++)
    {
        for(int x = 0; x < DISPLAY_WIDTH; x++)
        {
            chip8->display[y][x] = 0x00;
        }
    }
}

void __00EE(Chip8 *chip8)
{
    chip8->PC = pop(chip8);
}

void __1NNN(Chip8 *chip8, uint8_t nnn)
{
    chip8->PC = nnn;
}

void __2NNN(Chip8 *chip8, uint8_t nnn)
{
    push(chip8, chip8->PC);
    chip8->PC = nnn;
}

void __3XNN(Chip8 *chip8, uint8_t x, uint8_t nn)
{
    if(chip8->V[x] == nn){ chip8->PC += 2; }
}

void __4XNN(Chip8 *chip8, uint8_t x, uint8_t nn)
{
    if(chip8->V[x] != nn){ chip8->PC += 2; }
}

void __5XY0(Chip8 *chip8, uint8_t x, uint8_t y)
{
    if(chip8->V[x] == chip8->V[y]){ chip8->PC += 2; }
}

void __6XNN(Chip8 *chip8, uint8_t x, uint8_t nn)
{
    chip8->V[x] = nn;
}

void __7XNN(Chip8 *chip8, uint8_t x, uint8_t nn)
{
    chip8->V[x] += nn;
}

void __8XY0(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] = chip8->V[y];
}

void __8XY1(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] |= chip8->V[y];
}

void __8XY2(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] &= chip8->V[y];
}

void __8XY3(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] ^= chip8->V[y];
}

void __8XY4(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] += chip8->V[y];
}

void __8XY5(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] -= chip8->V[y];
}

void __8XY6(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] = chip8->V[x] >> 1;
}

void __8XY7(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] = chip8->V[y] - chip8->V[x];

    if(chip8->V[y] >= chip8->V[x])
    {
        chip8->V[F] = 1;
    }else{
        chip8->V[F] = 0;
    }
}

void __8XYE(Chip8 *chip8, uint8_t x, uint8_t y)
{
    chip8->V[x] = chip8->V[x] >> 1;
}

void __9XY0(Chip8 *chip8, uint8_t x, uint8_t y)
{
    if(chip8->V[x] != chip8->V[y]){ chip8->PC += 2; }
}

void __ANNN(Chip8 *chip8, uint8_t nnn)
{
    chip8->I = nnn;
}

void __BNNN(Chip8 *chip8, uint8_t nnn)
{
    chip8->PC = chip8->V[0] + nnn;
}

void __CXNN(Chip8 *chip8, uint8_t x, uint8_t nn)
{
    chip8->V[x] = (rand() % 255) & nn;
}

void __DXYN(Chip8 *chip8, uint8_t x, uint8_t y, uint8_t n)
{
    uint8_t x_coord = (chip8->V[x] % DISPLAY_WIDTH);
    uint8_t y_coord = (chip8->V[y] % DISPLAY_HEIGHT);
    chip8->V[F] = 0;

    for(int i = 0; i < n; i++)
    {
        uint8_t pixel = chip8->RAM[chip8->I + n];

        for(int j = 0; j < 8; j++)
        {
            if(pixel == 1 && chip8->display[y_coord + i][x_coord + j] == 1)
            {
                chip8->display[y_coord + i][x_coord + j] == 0;
                chip8->V[F] = 1;
            }
        }
    }


}

void __EX9E(Chip8 *chip8, uint8_t x)
{
    if(chip8->key == chip8->V[x]){ chip8->PC += 2; }
}

void __EXA1(Chip8 *chip8, uint8_t x)
{
    if(chip8->key != chip8->V[x]){ chip8->PC += 2; }
}

void __FX07(Chip8 *chip8, uint8_t x)
{
    chip8->V[x] = chip8->delay_timer;
}

void __FX0A(Chip8 *chip8, uint8_t x)
{
    chip8->V[x] = chip8->key;
}

void __FX15(Chip8 *chip8, uint8_t x)
{
    chip8->delay_timer = chip8->V[x];
}

void __FX18(Chip8 *chip8, uint8_t x)
{
    chip8->sound_timer = chip8->V[x];
}

void __FX1E(Chip8 *chip8, uint8_t x)
{
    chip8->I = chip8->V[x];
}

void __FX29(Chip8 *chip8, uint8_t x)
{

}

void __FX33(Chip8 *chip8, uint8_t x)
{

}

void __FX55(Chip8 *chip8, uint8_t x)
{
    for(int i = 0; i <= x; i++)
    {
        chip8->RAM[chip8->I + i] = chip8->V[i];
    }
}

void __FX65(Chip8 *chip8, uint8_t x)
{
    for(int i = 0; i <= x; i++)
    {
        chip8->V[i] = chip8->RAM[chip8->I + i];
    }
}


