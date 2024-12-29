#include <crazy.h>
#include <interpreter.h>
#include <stdio.h>
#include <string.h>
int main() {
    MalbolgeInterpreter *interpreter;
    char buf[512] = {'\0'};

    init_malbolge(&interpreter);
    printf("> ");
    while (scanf("%s", buf) > 0) {
        set_instruction(interpreter, buf);
        run(interpreter);
        memset(buf, 0, sizeof(char) * 512);
        printf("\n> ");
    }
}