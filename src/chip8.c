#include "../include/instructions.h"
#include <stdint.h>
#include <stdlib.h>

Chip8 *init_cpu()
{
    Chip8 *chip8 = (Chip8*)malloc(sizeof(Chip8));
    
    chip8->I           = 0x00;
    chip8->SP          = 0x00;
    chip8->delay_timer = 0x00;
    chip8->sound_timer = 0x00;
    chip8->PC          = PROGRAM_ADDRESS;
    
    chip8->chip8_stack = (uint16_t*)malloc(STACK_SIZE*sizeof(uint16_t));

    return chip8;
}

void push(Chip8* chip8, uint16_t value)
{
    chip8->chip8_stack[chip8->SP++] = value;
}

uint16_t pop(Chip8* chip8)
{
    if(chip8->PC > 0){
        return chip8->chip8_stack[--chip8->SP];
    }else{
        perror("Stack is empty!");
    }
}

void start_cpu(Chip8 *chip8, uint8_t instructions[], int size)
{
    int ram_index = 0;

    // insert sprites on the memory
    for(int i = 0; i < FONT_SIZE; i++)
    {
        for(int j = 0; j < SPRITE_SIZE; j++)
        {
            chip8->RAM[ram_index++] = font[i][j];
        }
    }

    // insert instructions on the memory
    for(int i = 0; i < size; i++)
    {
        chip8->RAM[PROGRAM_ADDRESS + i] = instructions[i];
    }
}

uint16_t fetch(Chip8 *chip8)
{

    uint16_t instruction;

    uint8_t msb_instruction = chip8->RAM[chip8->PC];
    uint8_t lsb_instruction = chip8->RAM[chip8->PC + 1];

    instruction = ((instruction | msb_instruction) << 8) | lsb_instruction; 
    return instruction;
}


void run(Chip8 *chip8, uint16_t instruction)
{
    uint8_t nn, nnn, n, x, y = 0x00;

    switch (instruction & 0xF000) {
        
        case 0x0000:

            switch (instruction & 0x00FF) {
                
                case 0xE0:
                    __00E0(chip8); // Display clear
                    break;

                case 0xEE:
                    __00EE(chip8); // Returns from a subroutine
                    break;
            
                default:
                    panic("Invalid Instruction!");
            }

            break;
        

        case 0x1000:
            nnn = instruction & 0x0FFF;
            __1NNN(chip8, nnn); 
            break;

        case 0x2000:
            nnn = instruction & 0x0FFF;
            __2NNN(chip8, nnn);
            break;

        case 0x3000:
            x = (instruction & 0x0F00) >> 8;
            nn = instruction & 0x00FF;
            __3XNN(chip8, x, nn);
            break;

        case 0x4000:
            x = (instruction & 0x0F00) >> 8;
            nn = instruction & 0x00FF;
            __4XNN(chip8,x,nn);
            break;

        case 0x5000:
            x = (instruction & 0x0F00) >> 8;
			y = (instruction & 0x00F0) >> 4;
            __5XY0(chip8,x,y);
            break;

        case 0x6000:
            x = (instruction & 0x0F00) >> 8;
			y = (instruction & 0x00F0) >> 4;
            __6XNN(chip8, x, nn);
            break;

        case 0x7000:
            x = (instruction & 0x0F00) >> 8;
            nn = instruction & 0x00FF;
            __7XNN(chip8, x, nn);
            break;

        case 0x8000:
            
            switch (instruction & 0x000F) {
                
                case 0x0:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY0(chip8, x, y);
                    break;

                case 0x1:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY1(chip8, x, y);
                    break;

                case 0x2:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY2(chip8, x, y);
                    break;

                case 0x3:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY3(chip8, x, y);
                    break;

                case 0x4:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY4(chip8, x, y);
                    break;

                case 0x5:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY5(chip8, x, y);
                    break;

                case 0x6:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY6(chip8, x, y);
                    break;

                case 0x7:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XY7(chip8, x, y);
                    break;

                case 0xE:
                    x = (instruction & 0x0F00) >> 8;
			        y = (instruction & 0x00F0) >> 4;
                    __8XYE(chip8, x, y);
                    break;

                default:
                    panic("Invalid Instruction!");
            }

            break;

        case 0x9000:
            x = (instruction & 0x0F00) >> 8;
            y = (instruction & 0x00F0) >> 4;
            __9XY0(chip8, x, y);
            break;

        case 0xA000:
            nnn = instruction & 0x0FFF;
            __ANNN(chip8, nnn);
            break;

        case 0xB000:
            nnn = instruction & 0x0FFF;
            __BNNN(chip8, nnn);
            break;

        case 0xC000:
            x = (instruction & 0x0F00) >> 8;
            nn = instruction & 0x00FF;
            __CXNN(chip8, x, nn);
            break;

        case 0xD000:
            x = (instruction & 0x0F00) >> 8;
            y = (instruction & 0x00F0) >> 4;
            n = (instruction & 0x000F);
            __DXYN(chip8, x, y, n);
            break;

        case 0xE000:

            switch (instruction & 0x00FF) {
                
                case 0x9E:
                    x = (instruction & 0x0F00) >> 8;
                    __EX9E(chip8, x);
                    break;

                case 0xA1:
                    x = (instruction & 0x0F00) >> 8;
                    __EXA1(chip8, x);
                    break;

                default:
                    panic("Invalid Instruction!");
            }

            break;
        
        case 0xF000:

            switch (instruction & 0x00FF) {
                case 0x07:
                    x = (instruction & 0x0F00) >> 8;
                    __FX07(chip8, x);
                    break;

                case 0x0A:
                    x = (instruction & 0x0F00) >> 8;
                    __FX0A(chip8, x);
                    break;

                case 0x15:
                    x = (instruction & 0x0F00) >> 8;
                    __FX15(chip8, x);
                    break;

                case 0x18:
                    x = (instruction & 0x0F00) >> 8;
                    __FX18(chip8, x);
                    break;

                case 0x1E:
                    x = (instruction & 0x0F00) >> 8;
                    __FX15(chip8, x);
                    break;

                case 0x29:
                    x = (instruction & 0x0F00) >> 8;
                    __FX29(chip8, x);
                    break;

                case 0x33:
                    x = (instruction & 0x0F00) >> 8;
                    __FX33(chip8, x);
                    break;

                case 0x55:
                    x = (instruction & 0x0F00) >> 8;
                    __FX55(chip8, x);
                    break;

                case 0x65:
                    x = (instruction & 0x0F00) >> 8;
                    __FX65(chip8, x);
                    break;

                default:
                    panic("Invalid Instruction!");
            }

            break;

        default:
            panic("Invalid Instruction!");
    }

}

void set_key(Chip8 *chip8,uint8_t key_pressed)
{
    switch (key_pressed) {

        case 0x31:
            chip8->key = keymap[0];
            break;
        case 0x32:
            chip8->key = keymap[1];
            break;
        case 0x33:
            chip8->key = keymap[2];
            break;
        case 0x34:
            chip8->key = keymap[3];
            break;
        case 0x51:
            chip8->key = keymap[4];
            break;
        case 0x71:
            chip8->key = keymap[4];
            break;
        case 0x57:
            chip8->key = keymap[5];
            break;
        case 0x77:
            chip8->key = keymap[5];
            break;
        case 0x45:
            chip8->key = keymap[6];
            break;
        case 0x65:
            chip8->key = keymap[6];
            break;
        case 0x52:
            chip8->key = keymap[7];
            break;
        case 0x72:
            chip8->key = keymap[7];
            break;
        case 0x41:
            chip8->key = keymap[8];
            break;
        case 0x61:
            chip8->key = keymap[8];
            break;
        case 0x53:
            chip8->key = keymap[9];
            break;
        case 0x73:
            chip8->key = keymap[9];
            break;
        case 0x44:
            chip8->key = keymap[10];
            break;
        case 0x64:
            chip8->key = keymap[10];
            break;
        case 0x46:
            chip8->key = keymap[11];
            break;
        case 0x66:
            chip8->key = keymap[11];
            break;
        case 0x5A:
            chip8->key = keymap[12];
            break;
        case 0x7A:
            chip8->key = keymap[12];
            break;
        case 0x58:
            chip8->key = keymap[13];
            break;
        case 0x78:
            chip8->key = keymap[13];
            break;
        case 0x43:
            chip8->key = keymap[14];
            break;
        case 0X63:
            chip8->key = keymap[14];
            break;
        case 0x56:
            chip8->key = keymap[15];
            break;
        case 0X76:
            chip8->key = keymap[15];
            break;
        default:
            panic("Key pressed is invalid!");
    }
}

void reset_key(Chip8 *chip8)
{
    chip8->key = 0;
}