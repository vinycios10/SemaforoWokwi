# Semáforo com Raspberry Pi Pico

Este projeto implementa um semáforo simples utilizando um Raspberry Pi Pico. Os LEDs vermelho, amarelo e verde acendem em sequência a cada 3 segundos.

## Componentes Utilizados

- Raspberry Pi Pico
- 3 LEDs (vermelho, amarelo e verde)
- Resistores adequados para os LEDs
- Fios de conexão

## Funcionamento

O código utiliza um timer repetitivo para alternar entre os estados do semáforo:

1. LED vermelho aceso → 3 segundos
2. LED amarelo aceso → 3 segundos
3. LED verde aceso → 3 segundos

Este ciclo se repete indefinidamente.

## Como Usar

1. Monte o circuito conectando os LEDs nas portas GPIO:
   - **LED vermelho:** GPIO 13
   - **LED amarelo:** GPIO 12
   - **LED verde:** GPIO 11
2. Compile e carregue o código no Raspberry Pi Pico.
3. O semáforo iniciará automaticamente.

## Bibliotecas Utilizadas

- `pico/stdlib.h` - Funções básicas do Pico.
- `hardware/timer.h` - Controle do temporizador.

## Código

Veja o código-fonte no arquivo `Semaforo.c`.
