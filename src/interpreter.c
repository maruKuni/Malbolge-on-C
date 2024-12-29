#include <crazy.h>
#include <interpreter.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MalbolgeInterpreter {
    uint64_t a;
    uint64_t c;
    uint64_t d;
    uint16_t *memory;
} MalbolgeInterpreter;
static uint16_t rot3(uint16_t x);
static uint8_t fetch_ope(MalbolgeInterpreter *interpreter);
static uint16_t read_stdin();
static uint8_t operation(MalbolgeInterpreter *interpreter, uint8_t operation);
static uint8_t encrypt(uint8_t c);

void init_malbolge(MalbolgeInterpreter **interpreter) {
    *interpreter = calloc(1, sizeof(MalbolgeInterpreter));
    (*interpreter)->memory = calloc(59049, sizeof(uint16_t));
}

void set_instruction(MalbolgeInterpreter *interpreter,
                     const char *instruction) {
    uint16_t i, i_instr = 0;
    uint8_t is_whitespace = 0;
    for (i = 0; instruction[i_instr]; i++) {
        while (1) {
            switch (instruction[i_instr]) {
                case ' ':
                case '\n':
                case '\t':
                    is_whitespace = 1;
                    i_instr++;
                    break;
                default:
                    is_whitespace = 0;
            }
            if (!is_whitespace) break;
        }
        interpreter->memory[i] = instruction[i_instr];
        i_instr++;
    }
    for (; i < 59049; i++) {
        interpreter->memory[i] =
            crazy(interpreter->memory[i - 2], interpreter->memory[i - 1]);
    }
}

void run(MalbolgeInterpreter *interpreter) {
    uint8_t ope;
    uint8_t is_alive;
    for (;;) {
        ope = fetch_ope(interpreter);
        is_alive = operation(interpreter, ope);
        if (!is_alive) break;
        interpreter->memory[interpreter->c] %= 94;
        interpreter->memory[interpreter->c] =
            encrypt(interpreter->memory[interpreter->c]);
        interpreter->c = (interpreter->c + 1) % 59049;
        interpreter->d = (interpreter->d + 1) % 59049;
    }
}

static uint16_t rot3(uint16_t x) {
    uint16_t result = x / 3;
    uint16_t base = 19683;
    result += base * (x % 3);
    return result;
}
static uint8_t fetch_ope(MalbolgeInterpreter *interpreter) {
    return (interpreter->c + interpreter->memory[interpreter->c]) % 94;
}
static uint8_t operation(MalbolgeInterpreter *interpreter, uint8_t operation) {
    switch (operation) {
        case 4:
            interpreter->c = interpreter->memory[interpreter->d];
            break;
        case 5:
            putchar(interpreter->a);
            break;
        case 23:
            interpreter->a = read_stdin();
            break;
        case 39:
            interpreter->memory[interpreter->d] =
                rot3(interpreter->memory[interpreter->d]);
            interpreter->a = interpreter->memory[interpreter->d];
            break;
        case 40:
            interpreter->d = interpreter->memory[interpreter->d];
            break;
        case 62:
            interpreter->memory[interpreter->d] =
                crazy(interpreter->memory[interpreter->d], interpreter->a);
            interpreter->a = interpreter->memory[interpreter->d];
            break;
        case 81:
            return 0;
        case 68:
        default:
            break;
    }
    return 1;
}
static uint16_t read_stdin() {
    int8_t in = getchar();
    if (in == '\n') {
        return 10;
    } else if (in == EOF) {
        return 59048;
    }
    return (uint16_t)in;
}
static uint8_t encrypt(uint8_t c) {
    uint8_t result;
    switch (c) {
        case 0:
            result = 57;
            break;
        case 1:
            result = 109;
            break;
        case 2:
            result = 60;
            break;
        case 3:
            result = 46;
            break;
        case 4:
            result = 84;
            break;
        case 5:
            result = 86;
            break;
        case 6:
            result = 97;
            break;
        case 7:
            result = 99;
            break;
        case 8:
            result = 96;
            break;
        case 9:
            result = 117;
            break;
        case 10:
            result = 89;
            break;
        case 11:
            result = 42;
            break;
        case 12:
            result = 77;
            break;
        case 13:
            result = 75;
            break;
        case 14:
            result = 39;
            break;
        case 15:
            result = 88;
            break;
        case 16:
            result = 126;
            break;
        case 17:
            result = 120;
            break;
        case 18:
            result = 68;
            break;
        case 19:
            result = 108;
            break;
        case 20:
            result = 125;
            break;
        case 21:
            result = 82;
            break;
        case 22:
            result = 69;
            break;
        case 23:
            result = 111;
            break;
        case 24:
            result = 107;
            break;
        case 25:
            result = 78;
            break;
        case 26:
            result = 58;
            break;
        case 27:
            result = 35;
            break;
        case 28:
            result = 63;
            break;
        case 29:
            result = 71;
            break;
        case 30:
            result = 34;
            break;
        case 31:
            result = 105;
            break;
        case 32:
            result = 64;
            break;
        case 33:
            result = 53;
            break;
        case 34:
            result = 122;
            break;
        case 35:
            result = 93;
            break;
        case 36:
            result = 38;
            break;
        case 37:
            result = 103;
            break;
        case 38:
            result = 113;
            break;
        case 39:
            result = 116;
            break;
        case 40:
            result = 121;
            break;
        case 41:
            result = 102;
            break;
        case 42:
            result = 114;
            break;
        case 43:
            result = 36;
            break;
        case 44:
            result = 40;
            break;
        case 45:
            result = 119;
            break;
        case 46:
            result = 101;
            break;
        case 47:
            result = 52;
            break;
        case 48:
            result = 123;
            break;
        case 49:
            result = 87;
            break;
        case 50:
            result = 80;
            break;
        case 51:
            result = 41;
            break;
        case 52:
            result = 72;
            break;
        case 53:
            result = 45;
            break;
        case 54:
            result = 90;
            break;
        case 55:
            result = 110;
            break;
        case 56:
            result = 44;
            break;
        case 57:
            result = 91;
            break;
        case 58:
            result = 37;
            break;
        case 59:
            result = 92;
            break;
        case 60:
            result = 51;
            break;
        case 61:
            result = 100;
            break;
        case 62:
            result = 76;
            break;
        case 63:
            result = 43;
            break;
        case 64:
            result = 81;
            break;
        case 65:
            result = 59;
            break;
        case 66:
            result = 62;
            break;
        case 67:
            result = 85;
            break;
        case 69:
            result = 112;
            break;
        case 70:
            result = 74;
            break;
        case 71:
            result = 83;
            break;
        case 72:
            result = 55;
            break;
        case 73:
            result = 50;
            break;
        case 74:
            result = 70;
            break;
        case 75:
            result = 104;
            break;
        case 76:
            result = 79;
            break;
        case 77:
            result = 65;
            break;
        case 78:
            result = 49;
            break;
        case 79:
            result = 67;
            break;
        case 80:
            result = 66;
            break;
        case 81:
            result = 54;
            break;
        case 82:
            result = 118;
            break;
        case 83:
            result = 94;
            break;
        case 84:
            result = 61;
            break;
        case 85:
            result = 73;
            break;
        case 86:
            result = 95;
            break;
        case 87:
            result = 48;
            break;
        case 88:
            result = 47;
            break;
        case 89:
            result = 56;
            break;
        case 90:
            result = 124;
            break;
        case 91:
            result = 106;
            break;
        case 92:
            result = 115;
            break;
        case 93:
            result = 98;
            break;
        default:
            perror("c is over than 94");
            exit(1);
    }
    return result;
}