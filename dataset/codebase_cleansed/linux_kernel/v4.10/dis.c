static unsigned int extract_operand(unsigned char *code,
const struct s390_operand *operand)
{
unsigned char *cp;
unsigned int val;
int bits;
cp = code + operand->shift / 8;
bits = (operand->shift & 7) + operand->bits;
val = 0;
do {
val <<= 8;
val |= (unsigned int) *cp++;
bits -= 8;
} while (bits > 0);
val >>= -bits;
val &= ((1U << (operand->bits - 1)) << 1) - 1;
if (operand->bits == 20 && operand->shift == 20)
val = (val & 0xff) << 12 | (val & 0xfff00) >> 8;
if (operand->flags & OPERAND_VR) {
if (operand->shift == 8)
val |= (code[4] & 8) << 1;
else if (operand->shift == 12)
val |= (code[4] & 4) << 2;
else if (operand->shift == 16)
val |= (code[4] & 2) << 3;
else if (operand->shift == 32)
val |= (code[4] & 1) << 4;
}
if ((operand->flags & (OPERAND_SIGNED | OPERAND_PCREL)) &&
(val & (1U << (operand->bits - 1))))
val |= (-1U << (operand->bits - 1)) << 1;
if (operand->flags & OPERAND_PCREL)
val <<= 1;
if (operand->flags & OPERAND_LENGTH)
val++;
return val;
}
struct s390_insn *find_insn(unsigned char *code)
{
unsigned char opfrag = code[1];
unsigned char opmask;
struct s390_insn *table;
switch (code[0]) {
case 0x01:
table = opcode_01;
break;
case 0xa5:
table = opcode_a5;
break;
case 0xa7:
table = opcode_a7;
break;
case 0xaa:
table = opcode_aa;
break;
case 0xb2:
table = opcode_b2;
break;
case 0xb3:
table = opcode_b3;
break;
case 0xb9:
table = opcode_b9;
break;
case 0xc0:
table = opcode_c0;
break;
case 0xc2:
table = opcode_c2;
break;
case 0xc4:
table = opcode_c4;
break;
case 0xc6:
table = opcode_c6;
break;
case 0xc8:
table = opcode_c8;
break;
case 0xcc:
table = opcode_cc;
break;
case 0xe3:
table = opcode_e3;
opfrag = code[5];
break;
case 0xe5:
table = opcode_e5;
break;
case 0xe7:
table = opcode_e7;
opfrag = code[5];
break;
case 0xeb:
table = opcode_eb;
opfrag = code[5];
break;
case 0xec:
table = opcode_ec;
opfrag = code[5];
break;
case 0xed:
table = opcode_ed;
opfrag = code[5];
break;
default:
table = opcode;
opfrag = code[0];
break;
}
while (table->format != INSTR_INVALID) {
opmask = formats[table->format][0];
if (table->opfrag == (opfrag & opmask))
return table;
table++;
}
return NULL;
}
int insn_to_mnemonic(unsigned char *instruction, char *buf, unsigned int len)
{
struct s390_insn *insn;
insn = find_insn(instruction);
if (!insn)
return -ENOENT;
if (insn->name[0] == '\0')
snprintf(buf, len, "%s",
long_insn_name[(int) insn->name[1]]);
else
snprintf(buf, len, "%.5s", insn->name);
return 0;
}
static int print_insn(char *buffer, unsigned char *code, unsigned long addr)
{
struct s390_insn *insn;
const unsigned char *ops;
const struct s390_operand *operand;
unsigned int value;
char separator;
char *ptr;
int i;
ptr = buffer;
insn = find_insn(code);
if (insn) {
if (insn->name[0] == '\0')
ptr += sprintf(ptr, "%s\t",
long_insn_name[(int) insn->name[1]]);
else
ptr += sprintf(ptr, "%.5s\t", insn->name);
separator = 0;
for (ops = formats[insn->format] + 1, i = 0;
*ops != 0 && i < 6; ops++, i++) {
operand = operands + *ops;
value = extract_operand(code, operand);
if ((operand->flags & OPERAND_INDEX) && value == 0)
continue;
if ((operand->flags & OPERAND_BASE) &&
value == 0 && separator == '(') {
separator = ',';
continue;
}
if (separator)
ptr += sprintf(ptr, "%c", separator);
if (operand->flags & OPERAND_GPR)
ptr += sprintf(ptr, "%%r%i", value);
else if (operand->flags & OPERAND_FPR)
ptr += sprintf(ptr, "%%f%i", value);
else if (operand->flags & OPERAND_AR)
ptr += sprintf(ptr, "%%a%i", value);
else if (operand->flags & OPERAND_CR)
ptr += sprintf(ptr, "%%c%i", value);
else if (operand->flags & OPERAND_VR)
ptr += sprintf(ptr, "%%v%i", value);
else if (operand->flags & OPERAND_PCREL)
ptr += sprintf(ptr, "%lx", (signed int) value
+ addr);
else if (operand->flags & OPERAND_SIGNED)
ptr += sprintf(ptr, "%i", value);
else
ptr += sprintf(ptr, "%u", value);
if (operand->flags & OPERAND_DISP)
separator = '(';
else if (operand->flags & OPERAND_BASE) {
ptr += sprintf(ptr, ")");
separator = ',';
} else
separator = ',';
}
} else
ptr += sprintf(ptr, "unknown");
return (int) (ptr - buffer);
}
void show_code(struct pt_regs *regs)
{
char *mode = user_mode(regs) ? "User" : "Krnl";
unsigned char code[64];
char buffer[64], *ptr;
mm_segment_t old_fs;
unsigned long addr;
int start, end, opsize, hops, i;
old_fs = get_fs();
set_fs(user_mode(regs) ? USER_DS : KERNEL_DS);
for (start = 32; start && regs->psw.addr >= 34 - start; start -= 2) {
addr = regs->psw.addr - 34 + start;
if (__copy_from_user(code + start - 2,
(char __user *) addr, 2))
break;
}
for (end = 32; end < 64; end += 2) {
addr = regs->psw.addr + end - 32;
if (__copy_from_user(code + end,
(char __user *) addr, 2))
break;
}
set_fs(old_fs);
if ((regs->psw.addr & 1) || start >= end) {
printk("%s Code: Bad PSW.\n", mode);
return;
}
while (start < 32) {
for (i = 0, hops = 0; start + i < 32 && hops < 3; hops++) {
if (!find_insn(code + start + i))
break;
i += insn_length(code[start + i]);
}
if (start + i == 32)
break;
start += 2;
}
ptr = buffer;
ptr += sprintf(ptr, "%s Code:", mode);
hops = 0;
while (start < end && hops < 8) {
opsize = insn_length(code[start]);
if (start + opsize == 32)
*ptr++ = '#';
else if (start == 32)
*ptr++ = '>';
else
*ptr++ = ' ';
addr = regs->psw.addr + start - 32;
ptr += sprintf(ptr, "%016lx: ", addr);
if (start + opsize >= end)
break;
for (i = 0; i < opsize; i++)
ptr += sprintf(ptr, "%02x", code[start + i]);
*ptr++ = '\t';
if (i < 6)
*ptr++ = '\t';
ptr += print_insn(ptr, code + start, addr);
start += opsize;
pr_cont("%s", buffer);
ptr = buffer;
ptr += sprintf(ptr, "\n ");
hops++;
}
pr_cont("\n");
}
void print_fn_code(unsigned char *code, unsigned long len)
{
char buffer[64], *ptr;
int opsize, i;
while (len) {
ptr = buffer;
opsize = insn_length(*code);
if (opsize > len)
break;
ptr += sprintf(ptr, "%p: ", code);
for (i = 0; i < opsize; i++)
ptr += sprintf(ptr, "%02x", code[i]);
*ptr++ = '\t';
if (i < 4)
*ptr++ = '\t';
ptr += print_insn(ptr, code, (unsigned long) code);
*ptr++ = '\n';
*ptr++ = 0;
printk("%s", buffer);
code += opsize;
len -= opsize;
}
}
