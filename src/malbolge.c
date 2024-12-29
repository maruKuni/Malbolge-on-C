#include <crazy.h>
#include <interpreter.h>
#include <stdio.h>
int main() {
    MalbolgeInterpreter *interpreter;
    init_malbolge(&interpreter);
    set_instruction(
        interpreter,
        "(=<`:9876Z4321UT.-Q+*)M\'&%$H\"!~}|Bzy?=|{z]KwZY44Eq0/"
        "{mlk**hKs_dG5[m_BA{?-Y;;Vb\'rR5431M}/.zHGwEDCBA@98\\6543W10/.R,+O<");
    run(interpreter);
}