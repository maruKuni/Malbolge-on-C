#ifndef INTERPRETER_H_
#define INTERPRETER_H_
typedef struct MalbolgeInterpreter MalbolgeInterpreter;
void init_malbolge(MalbolgeInterpreter **interpreter);
void set_instruction(MalbolgeInterpreter *interpreter, const char *instruction);
void run(MalbolgeInterpreter *interpreter);
#endif