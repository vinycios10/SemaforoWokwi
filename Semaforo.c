#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"


const uint led_pin_red  = 11;
const uint led_pin_yellow = 12;
const uint led_pin_green  = 13;

uint8_t led_atual;

bool semaforo_timer_callback(struct repeating_timer *t) {
    
    switch (led_atual)
    {
    case 1:
        gpio_put(led_pin_red, true);
        gpio_put(led_pin_yellow, false);
        gpio_put(led_pin_green, false);
        led_atual++;
        break;
    case 2:
        gpio_put(led_pin_red, false);
        gpio_put(led_pin_yellow, true);
        gpio_put(led_pin_green, false);
        led_atual++;
        break;
    case 3:
        gpio_put(led_pin_red, false);
        gpio_put(led_pin_yellow, false);
        gpio_put(led_pin_green, true);
        led_atual = 1;
        break;
    
    default:
        break;
    }
    return true;        //true mantem o temporizador repetindo. se for false ele para
}

int main()
{
    stdio_init_all();

    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);
    gpio_init(led_pin_yellow);
    gpio_set_dir(led_pin_yellow, GPIO_OUT);
    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);

    gpio_put(led_pin_red, true);
    gpio_put(led_pin_yellow, false);
    gpio_put(led_pin_green, false);
    led_atual = 2;

    struct repeating_timer timer;

    // chama a funcao a cada 3 segundos
    add_repeating_timer_ms(3000, semaforo_timer_callback, NULL, &timer);

    while (true) {
        printf("\nPreste atencao no sinal!");
        sleep_ms(1000);
    }
}
