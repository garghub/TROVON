int
print_insn_powerpc (unsigned long insn, unsigned long memaddr)
{
const struct powerpc_opcode *opcode;
const struct powerpc_opcode *opcode_end;
unsigned long op;
int dialect;
dialect = PPC_OPCODE_PPC | PPC_OPCODE_CLASSIC | PPC_OPCODE_COMMON
| PPC_OPCODE_64 | PPC_OPCODE_POWER4 | PPC_OPCODE_ALTIVEC;
if (cpu_has_feature(CPU_FTRS_POWER5))
dialect |= PPC_OPCODE_POWER5;
if (cpu_has_feature(CPU_FTRS_CELL))
dialect |= PPC_OPCODE_CELL | PPC_OPCODE_ALTIVEC;
if (cpu_has_feature(CPU_FTRS_POWER6))
dialect |= PPC_OPCODE_POWER5 | PPC_OPCODE_POWER6 | PPC_OPCODE_ALTIVEC;
op = PPC_OP (insn);
opcode_end = powerpc_opcodes + powerpc_num_opcodes;
again:
for (opcode = powerpc_opcodes; opcode < opcode_end; opcode++)
{
unsigned long table_op;
const unsigned char *opindex;
const struct powerpc_operand *operand;
int invalid;
int need_comma;
int need_paren;
table_op = PPC_OP (opcode->opcode);
if (op < table_op)
break;
if (op > table_op)
continue;
if ((insn & opcode->mask) != opcode->opcode
|| (opcode->flags & dialect) == 0)
continue;
invalid = 0;
for (opindex = opcode->operands; *opindex != 0; opindex++)
{
operand = powerpc_operands + *opindex;
if (operand->extract)
(*operand->extract) (insn, dialect, &invalid);
}
if (invalid)
continue;
printf("%s", opcode->name);
if (opcode->operands[0] != 0)
printf("\t");
need_comma = 0;
need_paren = 0;
for (opindex = opcode->operands; *opindex != 0; opindex++)
{
long value;
operand = powerpc_operands + *opindex;
if ((operand->flags & PPC_OPERAND_FAKE) != 0)
continue;
if (operand->extract)
value = (*operand->extract) (insn, dialect, &invalid);
else
{
value = (insn >> operand->shift) & ((1 << operand->bits) - 1);
if ((operand->flags & PPC_OPERAND_SIGNED) != 0
&& (value & (1 << (operand->bits - 1))) != 0)
value -= 1 << operand->bits;
}
if ((operand->flags & PPC_OPERAND_OPTIONAL) != 0
&& (operand->flags & PPC_OPERAND_NEXT) == 0
&& value == 0)
continue;
if (need_comma)
{
printf(",");
need_comma = 0;
}
if ((operand->flags & PPC_OPERAND_GPR) != 0
|| ((operand->flags & PPC_OPERAND_GPR_0) != 0 && value != 0))
printf("r%ld", value);
else if ((operand->flags & PPC_OPERAND_FPR) != 0)
printf("f%ld", value);
else if ((operand->flags & PPC_OPERAND_VR) != 0)
printf("v%ld", value);
else if ((operand->flags & PPC_OPERAND_RELATIVE) != 0)
print_address (memaddr + value);
else if ((operand->flags & PPC_OPERAND_ABSOLUTE) != 0)
print_address (value & 0xffffffff);
else if ((operand->flags & PPC_OPERAND_CR) == 0
|| (dialect & PPC_OPCODE_PPC) == 0)
printf("%ld", value);
else
{
if (operand->bits == 3)
printf("cr%ld", value);
else
{
static const char *cbnames[4] = { "lt", "gt", "eq", "so" };
int cr;
int cc;
cr = value >> 2;
if (cr != 0)
printf("4*cr%d+", cr);
cc = value & 3;
printf("%s", cbnames[cc]);
}
}
if (need_paren)
{
printf(")");
need_paren = 0;
}
if ((operand->flags & PPC_OPERAND_PARENS) == 0)
need_comma = 1;
else
{
printf("(");
need_paren = 1;
}
}
return 4;
}
if ((dialect & PPC_OPCODE_ANY) != 0)
{
dialect = ~PPC_OPCODE_ANY;
goto again;
}
printf(".long 0x%lx", insn);
return 4;
}
