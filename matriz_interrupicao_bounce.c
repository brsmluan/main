#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/gpio.h"
#include "hardware/irq.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"  // Incluindo o arquivo de controle WS2812

// Definições dos pinos
#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6
#define MATRIX_PIN 7   // Pino de dados para a matriz WS2812

// Variáveis globais
volatile int current_number = 0;  // Número exibido
int debounce_time = 0;  // Variável para controle de debounce

// Função para exibir número na matriz (exemplo simples de como você pode exibir um número)
void display_number(int num) {
    // Exemplo de controle de LEDs: você pode personalizar isso para exibir números
    uint32_t color = (num == 0) ? 0xFF0000 : 0x00FF00;  // Cor vermelha para o número 0, verde para outros
    for (int i = 0; i < 25; i++) {
        matrix.setPixelColor(i, color);  // Defina a cor para todos os LEDs
    }
    matrix.show();  // Atualiza os LEDs
}

// Função principal
int main() {
    stdio_init_all();

    // Configuração do pino de dados do WS2812
    PIO pio = pio0;  // Usando PIO 0
    uint sm = 0;      // Usando a máquina de estado 0
    uint offset = pio_add_program(pio, &ws2812_program);  // Adicionando o programa PIO
    ws2812_program_init(pio, sm, offset, MATRIX_PIN, 800000, false); // Inicializa o WS2812

    // Configuração dos botões A e B com interrupções (para incrementar e decrementar)
    gpio_init(BUTTON_A_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);  
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, button_A_isr);

    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_B_PIN);  
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, button_B_isr);

    // Loop principal
    while (true) {
        // Exibe o número no WS2812
        display_number(current_number);
    }

    return 0;
}
