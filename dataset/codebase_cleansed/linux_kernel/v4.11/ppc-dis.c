static long
operand_value_powerpc (const struct powerpc_operand *operand,
unsigned long insn, ppc_cpu_t dialect)
{
long value;
int invalid;
if (operand->extract)
value = (*operand->extract) (insn, dialect, &invalid);
else
{
if (operand->shift >= 0)
value = (insn >> operand->shift) & operand->bitm;
else
value = (insn << -operand->shift) & operand->bitm;
if ((operand->flags & PPC_OPERAND_SIGNED) != 0)
{
unsigned long top = operand->bitm;
top |= (top & -top) - 1;
top &= ~(top >> 1);
value = (value ^ top) - top;
}
}
return value;
}
static int
skip_optional_operands (const unsigned char *opindex,
unsigned long insn, ppc_cpu_t dialect)
{
const struct powerpc_operand *operand;
for (; *opindex != 0; opindex++)
{
operand = &powerpc_operands[*opindex];
if ((operand->flags & PPC_OPERAND_NEXT) != 0
|| ((operand->flags & PPC_OPERAND_OPTIONAL) != 0
&& operand_value_powerpc (operand, insn, dialect) !=
ppc_optional_operand_value (operand)))
return 0;
}
return 1;
}
static const struct powerpc_opcode *
lookup_powerpc (unsigned long insn, ppc_cpu_t dialect)
{
const struct powerpc_opcode *opcode;
const struct powerpc_opcode *opcode_end;
unsigned long op;
op = PPC_OP (insn);
opcode_end = powerpc_opcodes + powerpc_num_opcodes;
for (opcode = powerpc_opcodes; opcode < opcode_end; ++opcode)
{
const unsigned char *opindex;
const struct powerpc_operand *operand;
int invalid;
if ((insn & opcode->mask) != opcode->opcode
|| (dialect != (ppc_cpu_t) -1
&& ((opcode->flags & dialect) == 0
|| (opcode->deprecated & dialect) != 0)))
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
return opcode;
}
return NULL;
}
int print_insn_powerpc (unsigned long insn, unsigned long memaddr)
{
const struct powerpc_opcode *opcode;
bool insn_is_short;
ppc_cpu_t dialect;
dialect = PPC_OPCODE_PPC | PPC_OPCODE_COMMON
| PPC_OPCODE_64 | PPC_OPCODE_POWER4 | PPC_OPCODE_ALTIVEC;
if (cpu_has_feature(CPU_FTRS_POWER5))
dialect |= PPC_OPCODE_POWER5;
if (cpu_has_feature(CPU_FTRS_CELL))
dialect |= (PPC_OPCODE_CELL | PPC_OPCODE_ALTIVEC);
if (cpu_has_feature(CPU_FTRS_POWER6))
dialect |= (PPC_OPCODE_POWER5 | PPC_OPCODE_POWER6 | PPC_OPCODE_ALTIVEC);
if (cpu_has_feature(CPU_FTRS_POWER7))
dialect |= (PPC_OPCODE_POWER5 | PPC_OPCODE_POWER6 | PPC_OPCODE_POWER7
| PPC_OPCODE_ALTIVEC | PPC_OPCODE_VSX);
if (cpu_has_feature(CPU_FTRS_POWER8))
dialect |= (PPC_OPCODE_POWER5 | PPC_OPCODE_POWER6 | PPC_OPCODE_POWER7
| PPC_OPCODE_POWER8 | PPC_OPCODE_HTM
| PPC_OPCODE_ALTIVEC | PPC_OPCODE_ALTIVEC2 | PPC_OPCODE_VSX);
if (cpu_has_feature(CPU_FTRS_POWER9))
dialect |= (PPC_OPCODE_POWER5 | PPC_OPCODE_POWER6 | PPC_OPCODE_POWER7
| PPC_OPCODE_POWER8 | PPC_OPCODE_POWER9 | PPC_OPCODE_HTM
| PPC_OPCODE_ALTIVEC | PPC_OPCODE_ALTIVEC2
| PPC_OPCODE_VSX | PPC_OPCODE_VSX3),
opcode = NULL;
insn_is_short = false;
if (opcode == NULL)
opcode = lookup_powerpc (insn, dialect);
if (opcode == NULL && (dialect & PPC_OPCODE_ANY) != 0)
opcode = lookup_powerpc (insn, (ppc_cpu_t) -1);
if (opcode != NULL)
{
const unsigned char *opindex;
const struct powerpc_operand *operand;
int need_comma;
int need_paren;
int skip_optional;
if (opcode->operands[0] != 0)
printf("%-7s ", opcode->name);
else
printf("%s", opcode->name);
if (insn_is_short)
insn >>= 16;
need_comma = 0;
need_paren = 0;
skip_optional = -1;
for (opindex = opcode->operands; *opindex != 0; opindex++)
{
long value;
operand = powerpc_operands + *opindex;
if ((operand->flags & PPC_OPERAND_FAKE) != 0)
continue;
if ((operand->flags & PPC_OPERAND_OPTIONAL) != 0)
{
if (skip_optional < 0)
skip_optional = skip_optional_operands (opindex, insn,
dialect);
if (skip_optional)
continue;
}
value = operand_value_powerpc (operand, insn, dialect);
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
else if ((operand->flags & PPC_OPERAND_VSR) != 0)
printf("vs%ld", value);
else if ((operand->flags & PPC_OPERAND_RELATIVE) != 0)
print_address(memaddr + value);
else if ((operand->flags & PPC_OPERAND_ABSOLUTE) != 0)
print_address(value & 0xffffffff);
else if ((operand->flags & PPC_OPERAND_FSL) != 0)
printf("fsl%ld", value);
else if ((operand->flags & PPC_OPERAND_FCR) != 0)
printf("fcr%ld", value);
else if ((operand->flags & PPC_OPERAND_UDI) != 0)
printf("%ld", value);
else if ((operand->flags & PPC_OPERAND_CR_REG) != 0
&& (((dialect & PPC_OPCODE_PPC) != 0)
|| ((dialect & PPC_OPCODE_VLE) != 0)))
printf("cr%ld", value);
else if (((operand->flags & PPC_OPERAND_CR_BIT) != 0)
&& (((dialect & PPC_OPCODE_PPC) != 0)
|| ((dialect & PPC_OPCODE_VLE) != 0)))
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
else
printf("%d", (int) value);
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
if (insn_is_short)
{
memaddr += 2;
return 2;
}
else
return 4;
}
printf(".long 0x%lx", insn);
return 4;
}
