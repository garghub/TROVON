void initregs(struct biosregs *reg)\r\n{\r\nmemset(reg, 0, sizeof *reg);\r\nreg->eflags |= X86_EFLAGS_CF;\r\nreg->ds = ds();\r\nreg->es = ds();\r\nreg->fs = fs();\r\nreg->gs = gs();\r\n}
