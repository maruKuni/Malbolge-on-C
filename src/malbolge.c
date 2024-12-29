#include <crazy.h>
#include <interpreter.h>
#include <stdio.h>
int main() {
    MalbolgeInterpreter *interpreter;
    char buf[512] = {'\0'};

    init_malbolge(&interpreter);
    printf("> ");
    while (scanf("%s", buf) > 0) {
        set_instruction(interpreter, buf);
        run(interpreter);
        printf("\n> ");
    }
}