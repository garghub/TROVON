asmlinkage void misalignment(struct pt_regs *regs, enum exception_code code)
{
const struct exception_table_entry *fixup;
const struct mn10300_opcode *pop;
unsigned long *registers = (unsigned long *) regs;
unsigned long data, *store, *postinc, disp, inc, sp;
mm_segment_t seg;
siginfo_t info;
uint32_t opcode, noc, xo, xm;
uint8_t *pc, byte, datasz;
void *address;
unsigned tmp, npop, dispsz, loop;
if (user_mode(regs))
goto bus_error;
sp = (unsigned long) regs + sizeof(*regs);
kdebug("==>misalignment({pc=%lx,sp=%lx})", regs->pc, sp);
if (regs->epsw & EPSW_IE)
asm volatile("or %0,epsw" : : "i"(EPSW_IE));
seg = get_fs();
set_fs(KERNEL_DS);
fixup = search_exception_tables(regs->pc);
pc = (u_int8_t *) regs->pc;
if (__get_user(byte, pc) != 0)
goto fetch_error;
opcode = byte;
noc = 8;
for (pop = mn10300_opcodes; pop->name[0]; pop++) {
npop = ilog2(pop->opcode | pop->opmask);
if (npop <= 0 || npop > 31)
continue;
npop = (npop + 8) & ~7;
got_more_bits:
if (npop == noc) {
if ((opcode & pop->opmask) == pop->opcode)
goto found_opcode;
} else if (npop > noc) {
xo = pop->opcode >> (npop - noc);
xm = pop->opmask >> (npop - noc);
if ((opcode & xm) != xo)
continue;
pc++;
if (__get_user(byte, pc) != 0)
goto fetch_error;
opcode = opcode << 8 | byte;
noc += 8;
goto got_more_bits;
} else {
continue;
}
}
printk(KERN_CRIT "MISALIGN: %lx: unsupported instruction %x\n",
regs->pc, opcode);
failed:
set_fs(seg);
if (die_if_no_fixup("misalignment error", regs, code))
return;
bus_error:
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = BUS_ADRALN;
info.si_addr = (void *) regs->pc;
force_sig_info(SIGBUS, &info, current);
return;
fetch_error:
printk(KERN_CRIT
"MISALIGN: %p: fault whilst reading instruction data\n",
pc);
goto failed;
bad_addr_mode:
printk(KERN_CRIT
"MISALIGN: %lx: unsupported addressing mode %x\n",
regs->pc, opcode);
goto failed;
bad_reg_mode:
printk(KERN_CRIT
"MISALIGN: %lx: unsupported register mode %x\n",
regs->pc, opcode);
goto failed;
unsupported_instruction:
printk(KERN_CRIT
"MISALIGN: %lx: unsupported instruction %x (%s)\n",
regs->pc, opcode, pop->name);
goto failed;
transfer_failed:
set_fs(seg);
if (fixup) {
regs->pc = fixup->fixup;
return;
}
if (die_if_no_fixup("misalignment fixup", regs, code))
return;
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_code = 0;
info.si_addr = (void *) regs->pc;
force_sig_info(SIGSEGV, &info, current);
return;
found_opcode:
kdebug("%lx: %x==%x { %x, %x }",
regs->pc, opcode, pop->opcode, pop->params[0], pop->params[1]);
tmp = format_tbl[pop->format].opsz;
BUG_ON(tmp > noc);
if (tmp < noc) {
tmp = noc - tmp;
opcode >>= tmp;
pc -= tmp >> 3;
}
disp = 0;
dispsz = format_tbl[pop->format].dispsz;
for (loop = 0; loop < dispsz; loop += 8) {
pc++;
if (__get_user(byte, pc) != 0)
goto fetch_error;
disp |= byte << loop;
kdebug("{%p} disp[%02x]=%02x", pc, loop, byte);
}
kdebug("disp=%lx", disp);
set_fs(KERNEL_XDS);
if (fixup)
set_fs(seg);
tmp = (pop->params[0] ^ pop->params[1]) & 0x80000000;
if (!tmp) {
printk(KERN_CRIT
"MISALIGN: %lx: insn not move to/from memory %x\n",
regs->pc, opcode);
goto failed;
}
if (pop->name[3] == 0 ||
pop->name[4] == 'l')
inc = datasz = 4;
else if (pop->name[3] == 'h')
inc = datasz = 2;
else
goto unsupported_instruction;
if (pop->params[0] & 0x80000000) {
if (!misalignment_addr(registers, sp,
pop->params[0], opcode, disp,
&address, &postinc, &inc))
goto bad_addr_mode;
if (!misalignment_reg(registers, pop->params[1], opcode, disp,
&store))
goto bad_reg_mode;
kdebug("mov%u (%p),DARn", datasz, address);
if (copy_from_user(&data, (void *) address, datasz) != 0)
goto transfer_failed;
if (pop->params[0] & 0x1000000) {
kdebug("inc=%lx", inc);
*postinc += inc;
}
*store = data;
kdebug("loaded %lx", data);
} else {
if (!misalignment_reg(registers, pop->params[0], opcode, disp,
&store))
goto bad_reg_mode;
if (!misalignment_addr(registers, sp,
pop->params[1], opcode, disp,
&address, &postinc, &inc))
goto bad_addr_mode;
data = *store;
kdebug("mov%u %lx,(%p)", datasz, data, address);
if (copy_to_user((void *) address, &data, datasz) != 0)
goto transfer_failed;
if (pop->params[1] & 0x1000000)
*postinc += inc;
}
tmp = format_tbl[pop->format].opsz + format_tbl[pop->format].dispsz;
regs->pc += tmp >> 3;
if (pop->format == FMT_D10)
misalignment_MOV_Lcc(regs, opcode);
set_fs(seg);
}
static int misalignment_addr(unsigned long *registers, unsigned long sp,
unsigned params, unsigned opcode,
unsigned long disp,
void **_address, unsigned long **_postinc,
unsigned long *_inc)
{
unsigned long *postinc = NULL, address = 0, tmp;
if (!(params & 0x1000000)) {
kdebug("noinc");
*_inc = 0;
_inc = NULL;
}
params &= 0x00ffffff;
do {
switch (params & 0xff) {
case DM0:
postinc = &registers[Dreg_index[opcode & 0x03]];
address += *postinc;
break;
case DM1:
postinc = &registers[Dreg_index[opcode >> 2 & 0x03]];
address += *postinc;
break;
case DM2:
postinc = &registers[Dreg_index[opcode >> 4 & 0x03]];
address += *postinc;
break;
case AM0:
postinc = &registers[Areg_index[opcode & 0x03]];
address += *postinc;
break;
case AM1:
postinc = &registers[Areg_index[opcode >> 2 & 0x03]];
address += *postinc;
break;
case AM2:
postinc = &registers[Areg_index[opcode >> 4 & 0x03]];
address += *postinc;
break;
case RM0:
postinc = &registers[Rreg_index[opcode & 0x0f]];
address += *postinc;
break;
case RM1:
postinc = &registers[Rreg_index[opcode >> 2 & 0x0f]];
address += *postinc;
break;
case RM2:
postinc = &registers[Rreg_index[opcode >> 4 & 0x0f]];
address += *postinc;
break;
case RM4:
postinc = &registers[Rreg_index[opcode >> 8 & 0x0f]];
address += *postinc;
break;
case RM6:
postinc = &registers[Rreg_index[opcode >> 12 & 0x0f]];
address += *postinc;
break;
case RD0:
postinc = &registers[Rreg_index[disp & 0x0f]];
address += *postinc;
break;
case RD2:
postinc = &registers[Rreg_index[disp >> 4 & 0x0f]];
address += *postinc;
break;
case SP:
address += sp;
break;
case SD8:
case SIMM8:
disp = (long) (int8_t) (disp & 0xff);
goto displace_or_inc;
case SD16:
disp = (long) (int16_t) (disp & 0xffff);
goto displace_or_inc;
case SD24:
tmp = disp << 8;
asm("asr 8,%0" : "=r"(tmp) : "0"(tmp) : "cc");
disp = (long) tmp;
goto displace_or_inc;
case SIMM4_2:
tmp = opcode >> 4 & 0x0f;
tmp <<= 28;
asm("asr 28,%0" : "=r"(tmp) : "0"(tmp) : "cc");
disp = (long) tmp;
goto displace_or_inc;
case IMM8:
disp &= 0x000000ff;
goto displace_or_inc;
case IMM16:
disp &= 0x0000ffff;
goto displace_or_inc;
case IMM24:
disp &= 0x00ffffff;
goto displace_or_inc;
case IMM32:
case IMM32_MEM:
case IMM32_HIGH8:
case IMM32_HIGH8_MEM:
displace_or_inc:
kdebug("%s %lx", _inc ? "incr" : "disp", disp);
if (!_inc)
address += disp;
else
*_inc = disp;
break;
default:
BUG();
return 0;
}
} while ((params >>= 8));
*_address = (void *) address;
*_postinc = postinc;
return 1;
}
static int misalignment_reg(unsigned long *registers, unsigned params,
unsigned opcode, unsigned long disp,
unsigned long **_register)
{
params &= 0x7fffffff;
if (params & 0xffffff00)
return 0;
switch (params & 0xff) {
case DM0:
*_register = &registers[Dreg_index[opcode & 0x03]];
break;
case DM1:
*_register = &registers[Dreg_index[opcode >> 2 & 0x03]];
break;
case DM2:
*_register = &registers[Dreg_index[opcode >> 4 & 0x03]];
break;
case AM0:
*_register = &registers[Areg_index[opcode & 0x03]];
break;
case AM1:
*_register = &registers[Areg_index[opcode >> 2 & 0x03]];
break;
case AM2:
*_register = &registers[Areg_index[opcode >> 4 & 0x03]];
break;
case RM0:
*_register = &registers[Rreg_index[opcode & 0x0f]];
break;
case RM1:
*_register = &registers[Rreg_index[opcode >> 2 & 0x0f]];
break;
case RM2:
*_register = &registers[Rreg_index[opcode >> 4 & 0x0f]];
break;
case RM4:
*_register = &registers[Rreg_index[opcode >> 8 & 0x0f]];
break;
case RM6:
*_register = &registers[Rreg_index[opcode >> 12 & 0x0f]];
break;
case RD0:
*_register = &registers[Rreg_index[disp & 0x0f]];
break;
case RD2:
*_register = &registers[Rreg_index[disp >> 4 & 0x0f]];
break;
case SP:
*_register = &registers[REG_SP >> 2];
break;
default:
BUG();
return 0;
}
return 1;
}
static void misalignment_MOV_Lcc(struct pt_regs *regs, uint32_t opcode)
{
unsigned long epsw = regs->epsw;
unsigned long NxorV;
kdebug("MOV_Lcc %x [flags=%lx]", opcode, epsw & 0xf);
NxorV = ((epsw >> 3) ^ epsw >> 1) & 1;
switch (opcode & 0xf) {
case 0x0:
if (NxorV)
goto take_the_loop;
return;
case 0x1:
if (!((epsw & EPSW_FLAG_Z) | NxorV))
goto take_the_loop;
return;
case 0x2:
if (!NxorV)
goto take_the_loop;
return;
case 0x3:
if ((epsw & EPSW_FLAG_Z) | NxorV)
goto take_the_loop;
return;
case 0x4:
if (epsw & EPSW_FLAG_C)
goto take_the_loop;
return;
case 0x5:
if (!(epsw & (EPSW_FLAG_C | EPSW_FLAG_Z)))
goto take_the_loop;
return;
case 0x6:
if (!(epsw & EPSW_FLAG_C))
goto take_the_loop;
return;
case 0x7:
if (epsw & (EPSW_FLAG_C | EPSW_FLAG_Z))
goto take_the_loop;
return;
case 0x8:
if (epsw & EPSW_FLAG_Z)
goto take_the_loop;
return;
case 0x9:
if (!(epsw & EPSW_FLAG_Z))
goto take_the_loop;
return;
case 0xa:
goto take_the_loop;
default:
BUG();
}
take_the_loop:
kdebug("loop LAR=%lx", regs->lar);
regs->pc = regs->lar - 4;
}
static int __init test_misalignment(void)
{
register void *r asm("e0");
register u32 y asm("e1");
void *p = testbuf, *q;
u32 tmp, tmp2, x;
printk(KERN_NOTICE "==>test_misalignment() [testbuf=%p]\n", p);
p++;
printk(KERN_NOTICE "___ MOV (Am),Dn ___\n");
q = p + 256;
asm volatile("mov (%0),%1" : "+a"(q), "=d"(x));
ASSERTCMP(q, ==, p + 256);
ASSERTCMP(x, ==, 0x44332211);
printk(KERN_NOTICE "___ MOV (256,Am),Dn ___\n");
q = p;
asm volatile("mov (256,%0),%1" : "+a"(q), "=d"(x));
ASSERTCMP(q, ==, p);
ASSERTCMP(x, ==, 0x44332211);
printk(KERN_NOTICE "___ MOV (Di,Am),Dn ___\n");
tmp = 256;
q = p;
asm volatile("mov (%2,%0),%1" : "+a"(q), "=d"(x), "+d"(tmp));
ASSERTCMP(q, ==, p);
ASSERTCMP(x, ==, 0x44332211);
ASSERTCMP(tmp, ==, 256);
printk(KERN_NOTICE "___ MOV (256,Rm),Rn ___\n");
r = p;
asm volatile("mov (256,%0),%1" : "+r"(r), "=r"(y));
ASSERTCMP(r, ==, p);
ASSERTCMP(y, ==, 0x44332211);
printk(KERN_NOTICE "___ MOV (Rm+),Rn ___\n");
r = p + 256;
asm volatile("mov (%0+),%1" : "+r"(r), "=r"(y));
ASSERTCMP(r, ==, p + 256 + 4);
ASSERTCMP(y, ==, 0x44332211);
printk(KERN_NOTICE "___ MOV (Rm+,8),Rn ___\n");
r = p + 256;
asm volatile("mov (%0+,8),%1" : "+r"(r), "=r"(y));
ASSERTCMP(r, ==, p + 256 + 8);
ASSERTCMP(y, ==, 0x44332211);
printk(KERN_NOTICE "___ MOV (7,SP),Rn ___\n");
asm volatile(
"add -16,sp \n"
"mov +0x11,%0 \n"
"movbu %0,(7,sp) \n"
"mov +0x22,%0 \n"
"movbu %0,(8,sp) \n"
"mov +0x33,%0 \n"
"movbu %0,(9,sp) \n"
"mov +0x44,%0 \n"
"movbu %0,(10,sp) \n"
"mov (7,sp),%1 \n"
"add +16,sp \n"
: "+a"(q), "=d"(x));
ASSERTCMP(x, ==, 0x44332211);
printk(KERN_NOTICE "___ MOV (259,SP),Rn ___\n");
asm volatile(
"add -264,sp \n"
"mov +0x11,%0 \n"
"movbu %0,(259,sp) \n"
"mov +0x22,%0 \n"
"movbu %0,(260,sp) \n"
"mov +0x33,%0 \n"
"movbu %0,(261,sp) \n"
"mov +0x55,%0 \n"
"movbu %0,(262,sp) \n"
"mov (259,sp),%1 \n"
"add +264,sp \n"
: "+d"(tmp), "=d"(x));
ASSERTCMP(x, ==, 0x55332211);
printk(KERN_NOTICE "___ MOV (260,SP),Rn ___\n");
asm volatile(
"add -264,sp \n"
"mov +0x11,%0 \n"
"movbu %0,(260,sp) \n"
"mov +0x22,%0 \n"
"movbu %0,(261,sp) \n"
"mov +0x33,%0 \n"
"movbu %0,(262,sp) \n"
"mov +0x55,%0 \n"
"movbu %0,(263,sp) \n"
"mov (260,sp),%1 \n"
"add +264,sp \n"
: "+d"(tmp), "=d"(x));
ASSERTCMP(x, ==, 0x55332211);
printk(KERN_NOTICE "___ MOV_LNE ___\n");
tmp = 1;
tmp2 = 2;
q = p + 256;
asm volatile(
"setlb \n"
"mov %2,%3 \n"
"mov %1,%2 \n"
"cmp +0,%1 \n"
"mov_lne (%0+,4),%1"
: "+r"(q), "+d"(tmp), "+d"(tmp2), "=d"(x)
:
: "cc");
ASSERTCMP(q, ==, p + 256 + 12);
ASSERTCMP(x, ==, 0x44332211);
printk(KERN_NOTICE "___ MOV in SETLB ___\n");
tmp = 1;
tmp2 = 2;
q = p + 256;
asm volatile(
"setlb \n"
"mov %1,%3 \n"
"mov (%0+),%1 \n"
"cmp +0,%1 \n"
"lne "
: "+a"(q), "+d"(tmp), "+d"(tmp2), "=d"(x)
:
: "cc");
ASSERTCMP(q, ==, p + 256 + 8);
ASSERTCMP(x, ==, 0x44332211);
printk(KERN_NOTICE "<==test_misalignment()\n");
return 0;
}
