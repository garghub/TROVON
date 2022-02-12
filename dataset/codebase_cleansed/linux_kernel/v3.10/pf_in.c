static int skip_prefix(unsigned char *addr, struct prefix_bits *prf)
{
int i;
unsigned char *p = addr;
prf->shorted = 0;
prf->enlarged = 0;
prf->rexr = 0;
prf->rex = 0;
restart:
for (i = 0; i < ARRAY_SIZE(prefix_codes); i++) {
if (*p == prefix_codes[i]) {
if (*p == 0x66)
prf->shorted = 1;
#ifdef __amd64__
if ((*p & 0xf8) == 0x48)
prf->enlarged = 1;
if ((*p & 0xf4) == 0x44)
prf->rexr = 1;
if ((*p & 0xf0) == 0x40)
prf->rex = 1;
#endif
p++;
goto restart;
}
}
return (p - addr);
}
static int get_opcode(unsigned char *addr, unsigned int *opcode)
{
int len;
if (*addr == 0x0F) {
*opcode = *(unsigned short *)addr;
len = 2;
} else {
*opcode = *addr;
len = 1;
}
return len;
}
enum reason_type get_ins_type(unsigned long ins_addr)
{
unsigned int opcode;
unsigned char *p;
struct prefix_bits prf;
int i;
enum reason_type rv = OTHERS;
p = (unsigned char *)ins_addr;
p += skip_prefix(p, &prf);
p += get_opcode(p, &opcode);
CHECK_OP_TYPE(opcode, reg_rop, REG_READ);
CHECK_OP_TYPE(opcode, reg_wop, REG_WRITE);
CHECK_OP_TYPE(opcode, imm_wop, IMM_WRITE);
exit:
return rv;
}
static unsigned int get_ins_reg_width(unsigned long ins_addr)
{
unsigned int opcode;
unsigned char *p;
struct prefix_bits prf;
int i;
p = (unsigned char *)ins_addr;
p += skip_prefix(p, &prf);
p += get_opcode(p, &opcode);
for (i = 0; i < ARRAY_SIZE(rw8); i++)
if (rw8[i] == opcode)
return 1;
for (i = 0; i < ARRAY_SIZE(rw32); i++)
if (rw32[i] == opcode)
return prf.shorted ? 2 : (prf.enlarged ? 8 : 4);
printk(KERN_ERR "mmiotrace: Unknown opcode 0x%02x\n", opcode);
return 0;
}
unsigned int get_ins_mem_width(unsigned long ins_addr)
{
unsigned int opcode;
unsigned char *p;
struct prefix_bits prf;
int i;
p = (unsigned char *)ins_addr;
p += skip_prefix(p, &prf);
p += get_opcode(p, &opcode);
for (i = 0; i < ARRAY_SIZE(mw8); i++)
if (mw8[i] == opcode)
return 1;
for (i = 0; i < ARRAY_SIZE(mw16); i++)
if (mw16[i] == opcode)
return 2;
for (i = 0; i < ARRAY_SIZE(mw32); i++)
if (mw32[i] == opcode)
return prf.shorted ? 2 : 4;
for (i = 0; i < ARRAY_SIZE(mw64); i++)
if (mw64[i] == opcode)
return prf.shorted ? 2 : (prf.enlarged ? 8 : 4);
printk(KERN_ERR "mmiotrace: Unknown opcode 0x%02x\n", opcode);
return 0;
}
static unsigned char *get_reg_w8(int no, int rex, struct pt_regs *regs)
{
unsigned char *rv = NULL;
switch (no) {
case arg_AL:
rv = (unsigned char *)&regs->ax;
break;
case arg_BL:
rv = (unsigned char *)&regs->bx;
break;
case arg_CL:
rv = (unsigned char *)&regs->cx;
break;
case arg_DL:
rv = (unsigned char *)&regs->dx;
break;
#ifdef __amd64__
case arg_R8:
rv = (unsigned char *)&regs->r8;
break;
case arg_R9:
rv = (unsigned char *)&regs->r9;
break;
case arg_R10:
rv = (unsigned char *)&regs->r10;
break;
case arg_R11:
rv = (unsigned char *)&regs->r11;
break;
case arg_R12:
rv = (unsigned char *)&regs->r12;
break;
case arg_R13:
rv = (unsigned char *)&regs->r13;
break;
case arg_R14:
rv = (unsigned char *)&regs->r14;
break;
case arg_R15:
rv = (unsigned char *)&regs->r15;
break;
#endif
default:
break;
}
if (rv)
return rv;
if (rex) {
switch (no) {
case arg_SI:
rv = (unsigned char *)&regs->si;
break;
case arg_DI:
rv = (unsigned char *)&regs->di;
break;
case arg_BP:
rv = (unsigned char *)&regs->bp;
break;
case arg_SP:
rv = (unsigned char *)&regs->sp;
break;
default:
break;
}
} else {
switch (no) {
case arg_AH:
rv = 1 + (unsigned char *)&regs->ax;
break;
case arg_BH:
rv = 1 + (unsigned char *)&regs->bx;
break;
case arg_CH:
rv = 1 + (unsigned char *)&regs->cx;
break;
case arg_DH:
rv = 1 + (unsigned char *)&regs->dx;
break;
default:
break;
}
}
if (!rv)
printk(KERN_ERR "mmiotrace: Error reg no# %d\n", no);
return rv;
}
static unsigned long *get_reg_w32(int no, struct pt_regs *regs)
{
unsigned long *rv = NULL;
switch (no) {
case arg_AX:
rv = &regs->ax;
break;
case arg_BX:
rv = &regs->bx;
break;
case arg_CX:
rv = &regs->cx;
break;
case arg_DX:
rv = &regs->dx;
break;
case arg_SP:
rv = &regs->sp;
break;
case arg_BP:
rv = &regs->bp;
break;
case arg_SI:
rv = &regs->si;
break;
case arg_DI:
rv = &regs->di;
break;
#ifdef __amd64__
case arg_R8:
rv = &regs->r8;
break;
case arg_R9:
rv = &regs->r9;
break;
case arg_R10:
rv = &regs->r10;
break;
case arg_R11:
rv = &regs->r11;
break;
case arg_R12:
rv = &regs->r12;
break;
case arg_R13:
rv = &regs->r13;
break;
case arg_R14:
rv = &regs->r14;
break;
case arg_R15:
rv = &regs->r15;
break;
#endif
default:
printk(KERN_ERR "mmiotrace: Error reg no# %d\n", no);
}
return rv;
}
unsigned long get_ins_reg_val(unsigned long ins_addr, struct pt_regs *regs)
{
unsigned int opcode;
int reg;
unsigned char *p;
struct prefix_bits prf;
int i;
p = (unsigned char *)ins_addr;
p += skip_prefix(p, &prf);
p += get_opcode(p, &opcode);
for (i = 0; i < ARRAY_SIZE(reg_rop); i++)
if (reg_rop[i] == opcode)
goto do_work;
for (i = 0; i < ARRAY_SIZE(reg_wop); i++)
if (reg_wop[i] == opcode)
goto do_work;
printk(KERN_ERR "mmiotrace: Not a register instruction, opcode "
"0x%02x\n", opcode);
goto err;
do_work:
if (opcode == 0xAA || opcode == 0xAB) {
reg = arg_AX;
} else {
unsigned char mod_rm = *p;
reg = ((mod_rm >> 3) & 0x7) | (prf.rexr << 3);
}
switch (get_ins_reg_width(ins_addr)) {
case 1:
return *get_reg_w8(reg, prf.rex, regs);
case 2:
return *(unsigned short *)get_reg_w32(reg, regs);
case 4:
return *(unsigned int *)get_reg_w32(reg, regs);
#ifdef __amd64__
case 8:
return *(unsigned long *)get_reg_w32(reg, regs);
#endif
default:
printk(KERN_ERR "mmiotrace: Error width# %d\n", reg);
}
err:
return 0;
}
unsigned long get_ins_imm_val(unsigned long ins_addr)
{
unsigned int opcode;
unsigned char mod_rm;
unsigned char mod;
unsigned char *p;
struct prefix_bits prf;
int i;
p = (unsigned char *)ins_addr;
p += skip_prefix(p, &prf);
p += get_opcode(p, &opcode);
for (i = 0; i < ARRAY_SIZE(imm_wop); i++)
if (imm_wop[i] == opcode)
goto do_work;
printk(KERN_ERR "mmiotrace: Not an immediate instruction, opcode "
"0x%02x\n", opcode);
goto err;
do_work:
mod_rm = *p;
mod = mod_rm >> 6;
p++;
switch (mod) {
case 0:
if ((mod_rm & 0x7) == 0x5)
p += 4;
break;
case 1:
p += 1;
break;
case 2:
p += 4;
break;
case 3:
default:
printk(KERN_ERR "mmiotrace: not a memory access instruction "
"at 0x%lx, rm_mod=0x%02x\n",
ins_addr, mod_rm);
}
switch (get_ins_reg_width(ins_addr)) {
case 1:
return *(unsigned char *)p;
case 2:
return *(unsigned short *)p;
case 4:
return *(unsigned int *)p;
#ifdef __amd64__
case 8:
return *(unsigned long *)p;
#endif
default:
printk(KERN_ERR "mmiotrace: Error: width.\n");
}
err:
return 0;
}
