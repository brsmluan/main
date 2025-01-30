# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)
# Defina o tipo do projeto (C e CXX)
project(matriz_interrupicao_bounce C CXX)

# Defina o caminho do SDK do Pico
set(PICO_SDK_PATH "C:/caminho/para/o/pico-sdk")

# Inclua o SDK
include(${PICO_SDK_PATH}/cmake/pico_sdk_init.cmake)

# Inicialize o SDK do Pico
pico_sdk_init()

# Adicione o arquivo-fonte principal
add_executable(matriz_interrupicao_bounce matriz_interrupicao_bounce.c)

# Inclua as bibliotecas padrão
target_link_libraries(matriz_interrupicao_bounce pico_stdlib)

# Adicionar saídas extras
pico_add_extra_outputs(matriz_interrupicao_bounce)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(mratrix_interrupicao_bounce C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(mratrix_interrupicao_bounce mratrix_interrupicao_bounce.cpp )

pico_set_program_name(mratrix_interrupicao_bounce "mratrix_interrupicao_bounce")
pico_set_program_version(mratrix_interrupicao_bounce "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(mratrix_interrupicao_bounce 1)
pico_enable_stdio_usb(mratrix_interrupicao_bounce 1)

# Add the standard library to the build
target_link_libraries(mratrix_interrupicao_bounce
        pico_stdlib)

# Add the standard include files to the build
target_include_directories(mratrix_interrupicao_bounce PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(mratrix_interrupicao_bounce 
        
        )

pico_add_extra_outputs(mratrix_interrupicao_bounce)

