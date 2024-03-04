#include "../include/chip8.h"
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
                    
                    break;

                case 0xEE:
                    break;
            
                default:
                    panic("Invalid Instruction!");
            }

            break;
        

        case 0x1000:

            break;

        case 0x2000:

            break;

        case 0x3000:

            break;

        case 0x4000:

            break;

        case 0x5000:

            break;

        case 0x6000:

            break;

        case 0x7000:

            break;

        case 0x8000:
            
            switch (instruction & 0x000F) {
                
                case 0x0:
                    break;

                case 0x1:
                    break;

                case 0x2:
                    break;

                case 0x3:
                    break;

                case 0x4:
                    break;

                case 0x5:
                    break;

                case 0x6:
                    break;

                case 0x7:
                    break;

                case 0xE:
                    break;

                default:
                    panic("Invalid Instruction!");
            }

            break;

        case 0x9000:
            break;

        case 0xA000:
            break;

        case 0xB000:
            break;

        case 0xC000:
            break;

        case 0xD000:
            break;

        case 0xE000:

            switch (instruction & 0x00FF) {
                
                case 0x9E:
                    break;

                case 0xA1:
                    break;

                default:
                    panic("Invalid Instruction!");
            }

            break;
        
        case 0xF000:

            switch (instruction & 0x00FF) {
                case 0x07:
                    break;

                case 0x0A:
                    break;

                case 0x15:
                    break;

                case 0x18:
                    break;

                case 0x1E:
                    break;

                case 0x29:
                    break;

                case 0x33:
                    break;

                case 0x55:
                    break;

                case 0x65:
                    break;

                default:
                    panic("Invalid Instruction!");
            }

            break;

        default:
            panic("Invalid Instruction!");
    }

}