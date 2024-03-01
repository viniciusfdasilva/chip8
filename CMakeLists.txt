cmake_minimum_required(VERSION 3.10)
project(MeuProjetoC C)

# Definir versão C padrão (opcional)
set(CMAKE_C_STANDARD 11)

# Configuração do projeto
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})

# Adicionar diretório de includes
include_directories(${INCLUDE_DIR})

# Obter todos os arquivos fonte do diretório src
file(GLOB SOURCES ${SOURCE_DIR}/*.c)

# Executável de saída
add_executable(MeuPrograma ${SOURCES})

# Configurações de otimização e outras opções de compilação
if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -O3")
endif()
