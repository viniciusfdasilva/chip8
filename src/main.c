#include "../include/chip8.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <stdbool.h>

noreturn void get_graphics()
{
    while(true)
    {
        
    }
}

uint8_t load_rom(char* rom_path)
{
    FILE *file;
    char* buffer;
    long file_size;

    file = fopen(rom_path,"rb");

    if(file == NULL)
    {
        perror("File can not be opened!");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    buffer = (char*)malloc(file_size*sizeof(char*));

    size_t bytes_read = fread(buffer, 1, file_size, file);
}

int main(int argc, char** argv)
{

    if(argc > 1)
    {
        load_rom(argv[1]);
    }else
    {
        perror("ROM not specified!");
    }

    return 0;
}