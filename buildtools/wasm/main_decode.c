#include <stdio.h>
#include <stdlib.h>

#include "source/armadillo.h"

int main(int argc, char **argv){
    if (argc != 2) {
        printf("Usage: %s <opcode>\n", argv[0]);
        return 1;
    }

    struct ad_insn *insn = NULL;
    unsigned long opcode = strtoul(argv[1], NULL, 0);

    if (ArmadilloDisassemble(opcode, 0, &insn)) {
        printf("Disassembly failed\n");
        ArmadilloDone(&insn);
        return 1;
    }
    printf("%s\n", insn->decoded);
    ArmadilloDone(&insn);
    return 0;
}