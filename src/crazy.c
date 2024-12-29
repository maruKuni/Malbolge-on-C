#include <assert.h>
#include <crazy.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static uint8_t crz(uint8_t x, uint8_t y);
uint16_t crazy(uint16_t x, uint16_t y) {
    uint16_t base = 19683;
    uint16_t result = 0;
    uint8_t x_digit, y_digit;
    while (base > 0) {
        x_digit = x / base;
        y_digit = y / base;
        result += base * crz(x_digit, y_digit);
        x = x % base;
        y = y % base;
        base /= 3;
    }
    return result;
}

static uint8_t crz(uint8_t x, uint8_t y) {
    assert(x < 3 && y < 3);
    switch (x * 3 + y) {
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 0;
        case 3:
            return 1;
        case 4:
            return 0;
        case 5:
            return 2;
        case 6:
            return 2;
        case 7:
            return 2;
        case 8:
            return 1;
    }
    perror("something wrong");
    exit(1);
}