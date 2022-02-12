static unsigned long truncate_if_32bit(unsigned long msr, unsigned long val)
{
#ifdef __powerpc64__
if ((msr & MSR_64BIT) == 0)
val &= 0xffffffffUL;
#endif
return val;
}
static int __kprobes branch_taken(unsigned int instr, struct pt_regs *regs)
{
unsigned int bo = (instr >> 21) & 0x1f;
unsigned int bi;
if ((bo & 4) == 0) {
--regs->ctr;
if (((bo >> 1) & 1) ^ (regs->ctr == 0))
return 0;
}
if ((bo & 0x10) == 0) {
bi = (instr >> 16) & 0x1f;
if (((regs->ccr >> (31 - bi)) & 1) != ((bo >> 3) & 1))
return 0;
}
return 1;
}
static long __kprobes address_ok(struct pt_regs *regs, unsigned long ea, int nb)
{
if (!user_mode(regs))
return 1;
return __access_ok(ea, nb, USER_DS);
}
static unsigned long __kprobes dform_ea(unsigned int instr, struct pt_regs *regs)
{
int ra;
unsigned long ea;
ra = (instr >> 16) & 0x1f;
ea = (signed short) instr;
if (ra)
ea += regs->gpr[ra];
return truncate_if_32bit(regs->msr, ea);
}
static unsigned long __kprobes dsform_ea(unsigned int instr, struct pt_regs *regs)
{
int ra;
unsigned long ea;
ra = (instr >> 16) & 0x1f;
ea = (signed short) (instr & ~3);
if (ra)
ea += regs->gpr[ra];
return truncate_if_32bit(regs->msr, ea);
}
static unsigned long __kprobes xform_ea(unsigned int instr,
struct pt_regs *regs)
{
int ra, rb;
unsigned long ea;
ra = (instr >> 16) & 0x1f;
rb = (instr >> 11) & 0x1f;
ea = regs->gpr[rb];
if (ra)
ea += regs->gpr[ra];
return truncate_if_32bit(regs->msr, ea);
}
static inline unsigned long max_align(unsigned long x)
{
x |= sizeof(unsigned long);
return x & -x;
}
static inline unsigned long byterev_2(unsigned long x)
{
return ((x >> 8) & 0xff) | ((x & 0xff) << 8);
}
static inline unsigned long byterev_4(unsigned long x)
{
return ((x >> 24) & 0xff) | ((x >> 8) & 0xff00) |
((x & 0xff00) << 8) | ((x & 0xff) << 24);
}
static inline unsigned long byterev_8(unsigned long x)
{
return (byterev_4(x) << 32) | byterev_4(x >> 32);
}
static int __kprobes read_mem_aligned(unsigned long *dest, unsigned long ea,
int nb)
{
int err = 0;
unsigned long x = 0;
switch (nb) {
case 1:
err = __get_user(x, (unsigned char __user *) ea);
break;
case 2:
err = __get_user(x, (unsigned short __user *) ea);
break;
case 4:
err = __get_user(x, (unsigned int __user *) ea);
break;
#ifdef __powerpc64__
case 8:
err = __get_user(x, (unsigned long __user *) ea);
break;
#endif
}
if (!err)
*dest = x;
return err;
}
static int __kprobes read_mem_unaligned(unsigned long *dest, unsigned long ea,
int nb, struct pt_regs *regs)
{
int err;
unsigned long x, b, c;
#ifdef __LITTLE_ENDIAN__
int len = nb;
#endif
x = 0;
for (; nb > 0; nb -= c) {
#ifdef __LITTLE_ENDIAN__
c = 1;
#endif
#ifdef __BIG_ENDIAN__
c = max_align(ea);
#endif
if (c > nb)
c = max_align(nb);
err = read_mem_aligned(&b, ea, c);
if (err)
return err;
x = (x << (8 * c)) + b;
ea += c;
}
#ifdef __LITTLE_ENDIAN__
switch (len) {
case 2:
*dest = byterev_2(x);
break;
case 4:
*dest = byterev_4(x);
break;
#ifdef __powerpc64__
case 8:
*dest = byterev_8(x);
break;
#endif
}
#endif
#ifdef __BIG_ENDIAN__
*dest = x;
#endif
return 0;
}
static int __kprobes read_mem(unsigned long *dest, unsigned long ea, int nb,
struct pt_regs *regs)
{
if (!address_ok(regs, ea, nb))
return -EFAULT;
if ((ea & (nb - 1)) == 0)
return read_mem_aligned(dest, ea, nb);
return read_mem_unaligned(dest, ea, nb, regs);
}
static int __kprobes write_mem_aligned(unsigned long val, unsigned long ea,
int nb)
{
int err = 0;
switch (nb) {
case 1:
err = __put_user(val, (unsigned char __user *) ea);
break;
case 2:
err = __put_user(val, (unsigned short __user *) ea);
break;
case 4:
err = __put_user(val, (unsigned int __user *) ea);
break;
#ifdef __powerpc64__
case 8:
err = __put_user(val, (unsigned long __user *) ea);
break;
#endif
}
return err;
}
static int __kprobes write_mem_unaligned(unsigned long val, unsigned long ea,
int nb, struct pt_regs *regs)
{
int err;
unsigned long c;
#ifdef __LITTLE_ENDIAN__
switch (nb) {
case 2:
val = byterev_2(val);
break;
case 4:
val = byterev_4(val);
break;
#ifdef __powerpc64__
case 8:
val = byterev_8(val);
break;
#endif
}
#endif
for (; nb > 0; nb -= c) {
#ifdef __LITTLE_ENDIAN__
c = 1;
#endif
#ifdef __BIG_ENDIAN__
c = max_align(ea);
#endif
if (c > nb)
c = max_align(nb);
err = write_mem_aligned(val >> (nb - c) * 8, ea, c);
if (err)
return err;
ea += c;
}
return 0;
}
static int __kprobes write_mem(unsigned long val, unsigned long ea, int nb,
struct pt_regs *regs)
{
if (!address_ok(regs, ea, nb))
return -EFAULT;
if ((ea & (nb - 1)) == 0)
return write_mem_aligned(val, ea, nb);
return write_mem_unaligned(val, ea, nb, regs);
}
static int __kprobes do_fp_load(int rn, int (*func)(int, unsigned long),
unsigned long ea, int nb,
struct pt_regs *regs)
{
int err;
union {
double dbl;
unsigned long ul[2];
struct {
#ifdef __BIG_ENDIAN__
unsigned _pad_;
unsigned word;
#endif
#ifdef __LITTLE_ENDIAN__
unsigned word;
unsigned _pad_;
#endif
} single;
} data;
unsigned long ptr;
if (!address_ok(regs, ea, nb))
return -EFAULT;
if ((ea & 3) == 0)
return (*func)(rn, ea);
ptr = (unsigned long) &data.ul;
if (sizeof(unsigned long) == 8 || nb == 4) {
err = read_mem_unaligned(&data.ul[0], ea, nb, regs);
if (nb == 4)
ptr = (unsigned long)&(data.single.word);
} else {
err = read_mem_unaligned(&data.ul[0], ea, 4, regs);
if (!err)
err = read_mem_unaligned(&data.ul[1], ea + 4, 4, regs);
}
if (err)
return err;
return (*func)(rn, ptr);
}
static int __kprobes do_fp_store(int rn, int (*func)(int, unsigned long),
unsigned long ea, int nb,
struct pt_regs *regs)
{
int err;
union {
double dbl;
unsigned long ul[2];
struct {
#ifdef __BIG_ENDIAN__
unsigned _pad_;
unsigned word;
#endif
#ifdef __LITTLE_ENDIAN__
unsigned word;
unsigned _pad_;
#endif
} single;
} data;
unsigned long ptr;
if (!address_ok(regs, ea, nb))
return -EFAULT;
if ((ea & 3) == 0)
return (*func)(rn, ea);
ptr = (unsigned long) &data.ul[0];
if (sizeof(unsigned long) == 8 || nb == 4) {
if (nb == 4)
ptr = (unsigned long)&(data.single.word);
err = (*func)(rn, ptr);
if (err)
return err;
err = write_mem_unaligned(data.ul[0], ea, nb, regs);
} else {
err = (*func)(rn, ptr);
if (err)
return err;
err = write_mem_unaligned(data.ul[0], ea, 4, regs);
if (!err)
err = write_mem_unaligned(data.ul[1], ea + 4, 4, regs);
}
return err;
}
static int __kprobes do_vec_load(int rn, int (*func)(int, unsigned long),
unsigned long ea, struct pt_regs *regs)
{
if (!address_ok(regs, ea & ~0xfUL, 16))
return -EFAULT;
return (*func)(rn, ea);
}
static int __kprobes do_vec_store(int rn, int (*func)(int, unsigned long),
unsigned long ea, struct pt_regs *regs)
{
if (!address_ok(regs, ea & ~0xfUL, 16))
return -EFAULT;
return (*func)(rn, ea);
}
static int __kprobes do_vsx_load(int rn, int (*func)(int, unsigned long),
unsigned long ea, struct pt_regs *regs)
{
int err;
unsigned long val[2];
if (!address_ok(regs, ea, 16))
return -EFAULT;
if ((ea & 3) == 0)
return (*func)(rn, ea);
err = read_mem_unaligned(&val[0], ea, 8, regs);
if (!err)
err = read_mem_unaligned(&val[1], ea + 8, 8, regs);
if (!err)
err = (*func)(rn, (unsigned long) &val[0]);
return err;
}
static int __kprobes do_vsx_store(int rn, int (*func)(int, unsigned long),
unsigned long ea, struct pt_regs *regs)
{
int err;
unsigned long val[2];
if (!address_ok(regs, ea, 16))
return -EFAULT;
if ((ea & 3) == 0)
return (*func)(rn, ea);
err = (*func)(rn, (unsigned long) &val[0]);
if (err)
return err;
err = write_mem_unaligned(val[0], ea, 8, regs);
if (!err)
err = write_mem_unaligned(val[1], ea + 8, 8, regs);
return err;
}
static void __kprobes set_cr0(struct pt_regs *regs, int rd)
{
long val = regs->gpr[rd];
regs->ccr = (regs->ccr & 0x0fffffff) | ((regs->xer >> 3) & 0x10000000);
#ifdef __powerpc64__
if (!(regs->msr & MSR_64BIT))
val = (int) val;
#endif
if (val < 0)
regs->ccr |= 0x80000000;
else if (val > 0)
regs->ccr |= 0x40000000;
else
regs->ccr |= 0x20000000;
}
static void __kprobes add_with_carry(struct pt_regs *regs, int rd,
unsigned long val1, unsigned long val2,
unsigned long carry_in)
{
unsigned long val = val1 + val2;
if (carry_in)
++val;
regs->gpr[rd] = val;
#ifdef __powerpc64__
if (!(regs->msr & MSR_64BIT)) {
val = (unsigned int) val;
val1 = (unsigned int) val1;
}
#endif
if (val < val1 || (carry_in && val == val1))
regs->xer |= XER_CA;
else
regs->xer &= ~XER_CA;
}
static void __kprobes do_cmp_signed(struct pt_regs *regs, long v1, long v2,
int crfld)
{
unsigned int crval, shift;
crval = (regs->xer >> 31) & 1;
if (v1 < v2)
crval |= 8;
else if (v1 > v2)
crval |= 4;
else
crval |= 2;
shift = (7 - crfld) * 4;
regs->ccr = (regs->ccr & ~(0xf << shift)) | (crval << shift);
}
static void __kprobes do_cmp_unsigned(struct pt_regs *regs, unsigned long v1,
unsigned long v2, int crfld)
{
unsigned int crval, shift;
crval = (regs->xer >> 31) & 1;
if (v1 < v2)
crval |= 8;
else if (v1 > v2)
crval |= 4;
else
crval |= 2;
shift = (7 - crfld) * 4;
regs->ccr = (regs->ccr & ~(0xf << shift)) | (crval << shift);
}
static int __kprobes trap_compare(long v1, long v2)
{
int ret = 0;
if (v1 < v2)
ret |= 0x10;
else if (v1 > v2)
ret |= 0x08;
else
ret |= 0x04;
if ((unsigned long)v1 < (unsigned long)v2)
ret |= 0x02;
else if ((unsigned long)v1 > (unsigned long)v2)
ret |= 0x01;
return ret;
}
int __kprobes analyse_instr(struct instruction_op *op, struct pt_regs *regs,
unsigned int instr)
{
unsigned int opcode, ra, rb, rd, spr, u;
unsigned long int imm;
unsigned long int val, val2;
unsigned int mb, me, sh;
long ival;
op->type = COMPUTE;
opcode = instr >> 26;
switch (opcode) {
case 16:
op->type = BRANCH;
imm = (signed short)(instr & 0xfffc);
if ((instr & 2) == 0)
imm += regs->nip;
regs->nip += 4;
regs->nip = truncate_if_32bit(regs->msr, regs->nip);
if (instr & 1)
regs->link = regs->nip;
if (branch_taken(instr, regs))
regs->nip = truncate_if_32bit(regs->msr, imm);
return 1;
#ifdef CONFIG_PPC64
case 17:
if ((instr & 0xfe2) == 2)
op->type = SYSCALL;
else
op->type = UNKNOWN;
return 0;
#endif
case 18:
op->type = BRANCH;
imm = instr & 0x03fffffc;
if (imm & 0x02000000)
imm -= 0x04000000;
if ((instr & 2) == 0)
imm += regs->nip;
if (instr & 1)
regs->link = truncate_if_32bit(regs->msr, regs->nip + 4);
imm = truncate_if_32bit(regs->msr, imm);
regs->nip = imm;
return 1;
case 19:
switch ((instr >> 1) & 0x3ff) {
case 0:
rd = (instr >> 21) & 0x1c;
ra = (instr >> 16) & 0x1c;
val = (regs->ccr >> ra) & 0xf;
regs->ccr = (regs->ccr & ~(0xfUL << rd)) | (val << rd);
goto instr_done;
case 16:
case 528:
op->type = BRANCH;
imm = (instr & 0x400)? regs->ctr: regs->link;
regs->nip = truncate_if_32bit(regs->msr, regs->nip + 4);
imm = truncate_if_32bit(regs->msr, imm);
if (instr & 1)
regs->link = regs->nip;
if (branch_taken(instr, regs))
regs->nip = imm;
return 1;
case 18:
if (regs->msr & MSR_PR)
goto priv;
op->type = RFI;
return 0;
case 150:
op->type = BARRIER;
isync();
goto instr_done;
case 33:
case 129:
case 193:
case 225:
case 257:
case 289:
case 417:
case 449:
ra = (instr >> 16) & 0x1f;
rb = (instr >> 11) & 0x1f;
rd = (instr >> 21) & 0x1f;
ra = (regs->ccr >> (31 - ra)) & 1;
rb = (regs->ccr >> (31 - rb)) & 1;
val = (instr >> (6 + ra * 2 + rb)) & 1;
regs->ccr = (regs->ccr & ~(1UL << (31 - rd))) |
(val << (31 - rd));
goto instr_done;
}
break;
case 31:
switch ((instr >> 1) & 0x3ff) {
case 598:
op->type = BARRIER;
#ifdef __powerpc64__
switch ((instr >> 21) & 3) {
case 1:
asm volatile("lwsync" : : : "memory");
goto instr_done;
case 2:
asm volatile("ptesync" : : : "memory");
goto instr_done;
}
#endif
mb();
goto instr_done;
case 854:
op->type = BARRIER;
eieio();
goto instr_done;
}
break;
}
if (!FULL_REGS(regs))
return 0;
rd = (instr >> 21) & 0x1f;
ra = (instr >> 16) & 0x1f;
rb = (instr >> 11) & 0x1f;
switch (opcode) {
#ifdef __powerpc64__
case 2:
if (rd & trap_compare(regs->gpr[ra], (short) instr))
goto trap;
goto instr_done;
#endif
case 3:
if (rd & trap_compare((int)regs->gpr[ra], (short) instr))
goto trap;
goto instr_done;
case 7:
regs->gpr[rd] = regs->gpr[ra] * (short) instr;
goto instr_done;
case 8:
imm = (short) instr;
add_with_carry(regs, rd, ~regs->gpr[ra], imm, 1);
goto instr_done;
case 10:
imm = (unsigned short) instr;
val = regs->gpr[ra];
#ifdef __powerpc64__
if ((rd & 1) == 0)
val = (unsigned int) val;
#endif
do_cmp_unsigned(regs, val, imm, rd >> 2);
goto instr_done;
case 11:
imm = (short) instr;
val = regs->gpr[ra];
#ifdef __powerpc64__
if ((rd & 1) == 0)
val = (int) val;
#endif
do_cmp_signed(regs, val, imm, rd >> 2);
goto instr_done;
case 12:
imm = (short) instr;
add_with_carry(regs, rd, regs->gpr[ra], imm, 0);
goto instr_done;
case 13:
imm = (short) instr;
add_with_carry(regs, rd, regs->gpr[ra], imm, 0);
set_cr0(regs, rd);
goto instr_done;
case 14:
imm = (short) instr;
if (ra)
imm += regs->gpr[ra];
regs->gpr[rd] = imm;
goto instr_done;
case 15:
imm = ((short) instr) << 16;
if (ra)
imm += regs->gpr[ra];
regs->gpr[rd] = imm;
goto instr_done;
case 20:
mb = (instr >> 6) & 0x1f;
me = (instr >> 1) & 0x1f;
val = DATA32(regs->gpr[rd]);
imm = MASK32(mb, me);
regs->gpr[ra] = (regs->gpr[ra] & ~imm) | (ROTATE(val, rb) & imm);
goto logical_done;
case 21:
mb = (instr >> 6) & 0x1f;
me = (instr >> 1) & 0x1f;
val = DATA32(regs->gpr[rd]);
regs->gpr[ra] = ROTATE(val, rb) & MASK32(mb, me);
goto logical_done;
case 23:
mb = (instr >> 6) & 0x1f;
me = (instr >> 1) & 0x1f;
rb = regs->gpr[rb] & 0x1f;
val = DATA32(regs->gpr[rd]);
regs->gpr[ra] = ROTATE(val, rb) & MASK32(mb, me);
goto logical_done;
case 24:
imm = (unsigned short) instr;
regs->gpr[ra] = regs->gpr[rd] | imm;
goto instr_done;
case 25:
imm = (unsigned short) instr;
regs->gpr[ra] = regs->gpr[rd] | (imm << 16);
goto instr_done;
case 26:
imm = (unsigned short) instr;
regs->gpr[ra] = regs->gpr[rd] ^ imm;
goto instr_done;
case 27:
imm = (unsigned short) instr;
regs->gpr[ra] = regs->gpr[rd] ^ (imm << 16);
goto instr_done;
case 28:
imm = (unsigned short) instr;
regs->gpr[ra] = regs->gpr[rd] & imm;
set_cr0(regs, ra);
goto instr_done;
case 29:
imm = (unsigned short) instr;
regs->gpr[ra] = regs->gpr[rd] & (imm << 16);
set_cr0(regs, ra);
goto instr_done;
#ifdef __powerpc64__
case 30:
mb = ((instr >> 6) & 0x1f) | (instr & 0x20);
val = regs->gpr[rd];
if ((instr & 0x10) == 0) {
sh = rb | ((instr & 2) << 4);
val = ROTATE(val, sh);
switch ((instr >> 2) & 3) {
case 0:
regs->gpr[ra] = val & MASK64_L(mb);
goto logical_done;
case 1:
regs->gpr[ra] = val & MASK64_R(mb);
goto logical_done;
case 2:
regs->gpr[ra] = val & MASK64(mb, 63 - sh);
goto logical_done;
case 3:
imm = MASK64(mb, 63 - sh);
regs->gpr[ra] = (regs->gpr[ra] & ~imm) |
(val & imm);
goto logical_done;
}
} else {
sh = regs->gpr[rb] & 0x3f;
val = ROTATE(val, sh);
switch ((instr >> 1) & 7) {
case 0:
regs->gpr[ra] = val & MASK64_L(mb);
goto logical_done;
case 1:
regs->gpr[ra] = val & MASK64_R(mb);
goto logical_done;
}
}
#endif
break;
case 31:
switch ((instr >> 1) & 0x3ff) {
case 4:
if (rd == 0x1f ||
(rd & trap_compare((int)regs->gpr[ra],
(int)regs->gpr[rb])))
goto trap;
goto instr_done;
#ifdef __powerpc64__
case 68:
if (rd & trap_compare(regs->gpr[ra], regs->gpr[rb]))
goto trap;
goto instr_done;
#endif
case 83:
if (regs->msr & MSR_PR)
goto priv;
op->type = MFMSR;
op->reg = rd;
return 0;
case 146:
if (regs->msr & MSR_PR)
goto priv;
op->type = MTMSR;
op->reg = rd;
op->val = 0xffffffff & ~(MSR_ME | MSR_LE);
return 0;
#ifdef CONFIG_PPC64
case 178:
if (regs->msr & MSR_PR)
goto priv;
op->type = MTMSR;
op->reg = rd;
imm = (instr & 0x10000)? 0x8002: 0xefffffffffffeffeUL;
op->val = imm;
return 0;
#endif
case 19:
regs->gpr[rd] = regs->ccr;
regs->gpr[rd] &= 0xffffffffUL;
goto instr_done;
case 144:
imm = 0xf0000000UL;
val = regs->gpr[rd];
for (sh = 0; sh < 8; ++sh) {
if (instr & (0x80000 >> sh))
regs->ccr = (regs->ccr & ~imm) |
(val & imm);
imm >>= 4;
}
goto instr_done;
case 339:
spr = ((instr >> 16) & 0x1f) | ((instr >> 6) & 0x3e0);
switch (spr) {
case SPRN_XER:
regs->gpr[rd] = regs->xer;
regs->gpr[rd] &= 0xffffffffUL;
goto instr_done;
case SPRN_LR:
regs->gpr[rd] = regs->link;
goto instr_done;
case SPRN_CTR:
regs->gpr[rd] = regs->ctr;
goto instr_done;
default:
op->type = MFSPR;
op->reg = rd;
op->spr = spr;
return 0;
}
break;
case 467:
spr = ((instr >> 16) & 0x1f) | ((instr >> 6) & 0x3e0);
switch (spr) {
case SPRN_XER:
regs->xer = (regs->gpr[rd] & 0xffffffffUL);
goto instr_done;
case SPRN_LR:
regs->link = regs->gpr[rd];
goto instr_done;
case SPRN_CTR:
regs->ctr = regs->gpr[rd];
goto instr_done;
default:
op->type = MTSPR;
op->val = regs->gpr[rd];
op->spr = spr;
return 0;
}
break;
case 0:
val = regs->gpr[ra];
val2 = regs->gpr[rb];
#ifdef __powerpc64__
if ((rd & 1) == 0) {
val = (int) val;
val2 = (int) val2;
}
#endif
do_cmp_signed(regs, val, val2, rd >> 2);
goto instr_done;
case 32:
val = regs->gpr[ra];
val2 = regs->gpr[rb];
#ifdef __powerpc64__
if ((rd & 1) == 0) {
val = (unsigned int) val;
val2 = (unsigned int) val2;
}
#endif
do_cmp_unsigned(regs, val, val2, rd >> 2);
goto instr_done;
case 8:
add_with_carry(regs, rd, ~regs->gpr[ra],
regs->gpr[rb], 1);
goto arith_done;
#ifdef __powerpc64__
case 9:
asm("mulhdu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto arith_done;
#endif
case 10:
add_with_carry(regs, rd, regs->gpr[ra],
regs->gpr[rb], 0);
goto arith_done;
case 11:
asm("mulhwu %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto arith_done;
case 40:
regs->gpr[rd] = regs->gpr[rb] - regs->gpr[ra];
goto arith_done;
#ifdef __powerpc64__
case 73:
asm("mulhd %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto arith_done;
#endif
case 75:
asm("mulhw %0,%1,%2" : "=r" (regs->gpr[rd]) :
"r" (regs->gpr[ra]), "r" (regs->gpr[rb]));
goto arith_done;
case 104:
regs->gpr[rd] = -regs->gpr[ra];
goto arith_done;
case 136:
add_with_carry(regs, rd, ~regs->gpr[ra], regs->gpr[rb],
regs->xer & XER_CA);
goto arith_done;
case 138:
add_with_carry(regs, rd, regs->gpr[ra], regs->gpr[rb],
regs->xer & XER_CA);
goto arith_done;
case 200:
add_with_carry(regs, rd, ~regs->gpr[ra], 0L,
regs->xer & XER_CA);
goto arith_done;
case 202:
add_with_carry(regs, rd, regs->gpr[ra], 0L,
regs->xer & XER_CA);
goto arith_done;
case 232:
add_with_carry(regs, rd, ~regs->gpr[ra], -1L,
regs->xer & XER_CA);
goto arith_done;
#ifdef __powerpc64__
case 233:
regs->gpr[rd] = regs->gpr[ra] * regs->gpr[rb];
goto arith_done;
#endif
case 234:
add_with_carry(regs, rd, regs->gpr[ra], -1L,
regs->xer & XER_CA);
goto arith_done;
case 235:
regs->gpr[rd] = (unsigned int) regs->gpr[ra] *
(unsigned int) regs->gpr[rb];
goto arith_done;
case 266:
regs->gpr[rd] = regs->gpr[ra] + regs->gpr[rb];
goto arith_done;
#ifdef __powerpc64__
case 457:
regs->gpr[rd] = regs->gpr[ra] / regs->gpr[rb];
goto arith_done;
#endif
case 459:
regs->gpr[rd] = (unsigned int) regs->gpr[ra] /
(unsigned int) regs->gpr[rb];
goto arith_done;
#ifdef __powerpc64__
case 489:
regs->gpr[rd] = (long int) regs->gpr[ra] /
(long int) regs->gpr[rb];
goto arith_done;
#endif
case 491:
regs->gpr[rd] = (int) regs->gpr[ra] /
(int) regs->gpr[rb];
goto arith_done;
case 26:
asm("cntlzw %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto logical_done;
#ifdef __powerpc64__
case 58:
asm("cntlzd %0,%1" : "=r" (regs->gpr[ra]) :
"r" (regs->gpr[rd]));
goto logical_done;
#endif
case 28:
regs->gpr[ra] = regs->gpr[rd] & regs->gpr[rb];
goto logical_done;
case 60:
regs->gpr[ra] = regs->gpr[rd] & ~regs->gpr[rb];
goto logical_done;
case 124:
regs->gpr[ra] = ~(regs->gpr[rd] | regs->gpr[rb]);
goto logical_done;
case 284:
regs->gpr[ra] = ~(regs->gpr[rd] ^ regs->gpr[rb]);
goto logical_done;
case 316:
regs->gpr[ra] = regs->gpr[rd] ^ regs->gpr[rb];
goto logical_done;
case 412:
regs->gpr[ra] = regs->gpr[rd] | ~regs->gpr[rb];
goto logical_done;
case 444:
regs->gpr[ra] = regs->gpr[rd] | regs->gpr[rb];
goto logical_done;
case 476:
regs->gpr[ra] = ~(regs->gpr[rd] & regs->gpr[rb]);
goto logical_done;
case 922:
regs->gpr[ra] = (signed short) regs->gpr[rd];
goto logical_done;
case 954:
regs->gpr[ra] = (signed char) regs->gpr[rd];
goto logical_done;
#ifdef __powerpc64__
case 986:
regs->gpr[ra] = (signed int) regs->gpr[rd];
goto logical_done;
#endif
case 24:
sh = regs->gpr[rb] & 0x3f;
if (sh < 32)
regs->gpr[ra] = (regs->gpr[rd] << sh) & 0xffffffffUL;
else
regs->gpr[ra] = 0;
goto logical_done;
case 536:
sh = regs->gpr[rb] & 0x3f;
if (sh < 32)
regs->gpr[ra] = (regs->gpr[rd] & 0xffffffffUL) >> sh;
else
regs->gpr[ra] = 0;
goto logical_done;
case 792:
sh = regs->gpr[rb] & 0x3f;
ival = (signed int) regs->gpr[rd];
regs->gpr[ra] = ival >> (sh < 32 ? sh : 31);
if (ival < 0 && (sh >= 32 || (ival & ((1ul << sh) - 1)) != 0))
regs->xer |= XER_CA;
else
regs->xer &= ~XER_CA;
goto logical_done;
case 824:
sh = rb;
ival = (signed int) regs->gpr[rd];
regs->gpr[ra] = ival >> sh;
if (ival < 0 && (ival & ((1ul << sh) - 1)) != 0)
regs->xer |= XER_CA;
else
regs->xer &= ~XER_CA;
goto logical_done;
#ifdef __powerpc64__
case 27:
sh = regs->gpr[rb] & 0x7f;
if (sh < 64)
regs->gpr[ra] = regs->gpr[rd] << sh;
else
regs->gpr[ra] = 0;
goto logical_done;
case 539:
sh = regs->gpr[rb] & 0x7f;
if (sh < 64)
regs->gpr[ra] = regs->gpr[rd] >> sh;
else
regs->gpr[ra] = 0;
goto logical_done;
case 794:
sh = regs->gpr[rb] & 0x7f;
ival = (signed long int) regs->gpr[rd];
regs->gpr[ra] = ival >> (sh < 64 ? sh : 63);
if (ival < 0 && (sh >= 64 || (ival & ((1ul << sh) - 1)) != 0))
regs->xer |= XER_CA;
else
regs->xer &= ~XER_CA;
goto logical_done;
case 826:
case 827:
sh = rb | ((instr & 2) << 4);
ival = (signed long int) regs->gpr[rd];
regs->gpr[ra] = ival >> sh;
if (ival < 0 && (ival & ((1ul << sh) - 1)) != 0)
regs->xer |= XER_CA;
else
regs->xer &= ~XER_CA;
goto logical_done;
#endif
case 54:
op->type = MKOP(CACHEOP, DCBST, 0);
op->ea = xform_ea(instr, regs);
return 0;
case 86:
op->type = MKOP(CACHEOP, DCBF, 0);
op->ea = xform_ea(instr, regs);
return 0;
case 246:
op->type = MKOP(CACHEOP, DCBTST, 0);
op->ea = xform_ea(instr, regs);
op->reg = rd;
return 0;
case 278:
op->type = MKOP(CACHEOP, DCBTST, 0);
op->ea = xform_ea(instr, regs);
op->reg = rd;
return 0;
case 982:
op->type = MKOP(CACHEOP, ICBI, 0);
op->ea = xform_ea(instr, regs);
return 0;
}
break;
}
op->type = UNKNOWN;
op->update_reg = ra;
op->reg = rd;
op->val = regs->gpr[rd];
u = (instr >> 20) & UPDATE;
switch (opcode) {
case 31:
u = instr & UPDATE;
op->ea = xform_ea(instr, regs);
switch ((instr >> 1) & 0x3ff) {
case 20:
op->type = MKOP(LARX, 0, 4);
break;
case 150:
op->type = MKOP(STCX, 0, 4);
break;
#ifdef __powerpc64__
case 84:
op->type = MKOP(LARX, 0, 8);
break;
case 214:
op->type = MKOP(STCX, 0, 8);
break;
case 21:
case 53:
op->type = MKOP(LOAD, u, 8);
break;
#endif
case 23:
case 55:
op->type = MKOP(LOAD, u, 4);
break;
case 87:
case 119:
op->type = MKOP(LOAD, u, 1);
break;
#ifdef CONFIG_ALTIVEC
case 103:
case 359:
if (!(regs->msr & MSR_VEC))
goto vecunavail;
op->type = MKOP(LOAD_VMX, 0, 16);
break;
case 231:
case 487:
if (!(regs->msr & MSR_VEC))
goto vecunavail;
op->type = MKOP(STORE_VMX, 0, 16);
break;
#endif
#ifdef __powerpc64__
case 149:
case 181:
op->type = MKOP(STORE, u, 8);
break;
#endif
case 151:
case 183:
op->type = MKOP(STORE, u, 4);
break;
case 215:
case 247:
op->type = MKOP(STORE, u, 1);
break;
case 279:
case 311:
op->type = MKOP(LOAD, u, 2);
break;
#ifdef __powerpc64__
case 341:
case 373:
op->type = MKOP(LOAD, SIGNEXT | u, 4);
break;
#endif
case 343:
case 375:
op->type = MKOP(LOAD, SIGNEXT | u, 2);
break;
case 407:
case 439:
op->type = MKOP(STORE, u, 2);
break;
#ifdef __powerpc64__
case 532:
op->type = MKOP(LOAD, BYTEREV, 8);
break;
#endif
case 533:
op->type = MKOP(LOAD_MULTI, 0, regs->xer & 0x7f);
break;
case 534:
op->type = MKOP(LOAD, BYTEREV, 4);
break;
case 597:
if (rb == 0)
rb = 32;
op->type = MKOP(LOAD_MULTI, 0, rb);
op->ea = 0;
if (ra)
op->ea = truncate_if_32bit(regs->msr,
regs->gpr[ra]);
break;
#ifdef CONFIG_PPC_FPU
case 535:
case 567:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(LOAD_FP, u, 4);
break;
case 599:
case 631:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(LOAD_FP, u, 8);
break;
case 663:
case 695:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(STORE_FP, u, 4);
break;
case 727:
case 759:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(STORE_FP, u, 8);
break;
#endif
#ifdef __powerpc64__
case 660:
op->type = MKOP(STORE, BYTEREV, 8);
op->val = byterev_8(regs->gpr[rd]);
break;
#endif
case 661:
op->type = MKOP(STORE_MULTI, 0, regs->xer & 0x7f);
break;
case 662:
op->type = MKOP(STORE, BYTEREV, 4);
op->val = byterev_4(regs->gpr[rd]);
break;
case 725:
if (rb == 0)
rb = 32;
op->type = MKOP(STORE_MULTI, 0, rb);
op->ea = 0;
if (ra)
op->ea = truncate_if_32bit(regs->msr,
regs->gpr[ra]);
break;
case 790:
op->type = MKOP(LOAD, BYTEREV, 2);
break;
case 918:
op->type = MKOP(STORE, BYTEREV, 2);
op->val = byterev_2(regs->gpr[rd]);
break;
#ifdef CONFIG_VSX
case 844:
case 876:
if (!(regs->msr & MSR_VSX))
goto vsxunavail;
op->reg = rd | ((instr & 1) << 5);
op->type = MKOP(LOAD_VSX, u, 16);
break;
case 972:
case 1004:
if (!(regs->msr & MSR_VSX))
goto vsxunavail;
op->reg = rd | ((instr & 1) << 5);
op->type = MKOP(STORE_VSX, u, 16);
break;
#endif
}
break;
case 32:
case 33:
op->type = MKOP(LOAD, u, 4);
op->ea = dform_ea(instr, regs);
break;
case 34:
case 35:
op->type = MKOP(LOAD, u, 1);
op->ea = dform_ea(instr, regs);
break;
case 36:
case 37:
op->type = MKOP(STORE, u, 4);
op->ea = dform_ea(instr, regs);
break;
case 38:
case 39:
op->type = MKOP(STORE, u, 1);
op->ea = dform_ea(instr, regs);
break;
case 40:
case 41:
op->type = MKOP(LOAD, u, 2);
op->ea = dform_ea(instr, regs);
break;
case 42:
case 43:
op->type = MKOP(LOAD, SIGNEXT | u, 2);
op->ea = dform_ea(instr, regs);
break;
case 44:
case 45:
op->type = MKOP(STORE, u, 2);
op->ea = dform_ea(instr, regs);
break;
case 46:
if (ra >= rd)
break;
op->type = MKOP(LOAD_MULTI, 0, 4 * (32 - rd));
op->ea = dform_ea(instr, regs);
break;
case 47:
op->type = MKOP(STORE_MULTI, 0, 4 * (32 - rd));
op->ea = dform_ea(instr, regs);
break;
#ifdef CONFIG_PPC_FPU
case 48:
case 49:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(LOAD_FP, u, 4);
op->ea = dform_ea(instr, regs);
break;
case 50:
case 51:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(LOAD_FP, u, 8);
op->ea = dform_ea(instr, regs);
break;
case 52:
case 53:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(STORE_FP, u, 4);
op->ea = dform_ea(instr, regs);
break;
case 54:
case 55:
if (!(regs->msr & MSR_FP))
goto fpunavail;
op->type = MKOP(STORE_FP, u, 8);
op->ea = dform_ea(instr, regs);
break;
#endif
#ifdef __powerpc64__
case 58:
op->ea = dsform_ea(instr, regs);
switch (instr & 3) {
case 0:
op->type = MKOP(LOAD, 0, 8);
break;
case 1:
op->type = MKOP(LOAD, UPDATE, 8);
break;
case 2:
op->type = MKOP(LOAD, SIGNEXT, 4);
break;
}
break;
case 62:
op->ea = dsform_ea(instr, regs);
switch (instr & 3) {
case 0:
op->type = MKOP(STORE, 0, 8);
break;
case 1:
op->type = MKOP(STORE, UPDATE, 8);
break;
}
break;
#endif
}
return 0;
logical_done:
if (instr & 1)
set_cr0(regs, ra);
goto instr_done;
arith_done:
if (instr & 1)
set_cr0(regs, rd);
instr_done:
regs->nip = truncate_if_32bit(regs->msr, regs->nip + 4);
return 1;
priv:
op->type = INTERRUPT | 0x700;
op->val = SRR1_PROGPRIV;
return 0;
trap:
op->type = INTERRUPT | 0x700;
op->val = SRR1_PROGTRAP;
return 0;
#ifdef CONFIG_PPC_FPU
fpunavail:
op->type = INTERRUPT | 0x800;
return 0;
#endif
#ifdef CONFIG_ALTIVEC
vecunavail:
op->type = INTERRUPT | 0xf20;
return 0;
#endif
#ifdef CONFIG_VSX
vsxunavail:
op->type = INTERRUPT | 0xf40;
return 0;
#endif
}
static __kprobes int handle_stack_update(unsigned long ea, struct pt_regs *regs)
{
#ifdef CONFIG_PPC32
if (ea - STACK_INT_FRAME_SIZE <= current->thread.ksp_limit) {
printk(KERN_CRIT "Can't kprobe this since kernel stack would overflow.\n");
return -EINVAL;
}
#endif
WARN_ON(test_thread_flag(TIF_EMULATE_STACK_STORE));
set_thread_flag(TIF_EMULATE_STACK_STORE);
return 0;
}
static __kprobes void do_signext(unsigned long *valp, int size)
{
switch (size) {
case 2:
*valp = (signed short) *valp;
break;
case 4:
*valp = (signed int) *valp;
break;
}
}
static __kprobes void do_byterev(unsigned long *valp, int size)
{
switch (size) {
case 2:
*valp = byterev_2(*valp);
break;
case 4:
*valp = byterev_4(*valp);
break;
#ifdef __powerpc64__
case 8:
*valp = byterev_8(*valp);
break;
#endif
}
}
int __kprobes emulate_step(struct pt_regs *regs, unsigned int instr)
{
struct instruction_op op;
int r, err, size;
unsigned long val;
unsigned int cr;
int i, rd, nb;
r = analyse_instr(&op, regs, instr);
if (r != 0)
return r;
err = 0;
size = GETSIZE(op.type);
switch (op.type & INSTR_TYPE_MASK) {
case CACHEOP:
if (!address_ok(regs, op.ea, 8))
return 0;
switch (op.type & CACHEOP_MASK) {
case DCBST:
__cacheop_user_asmx(op.ea, err, "dcbst");
break;
case DCBF:
__cacheop_user_asmx(op.ea, err, "dcbf");
break;
case DCBTST:
if (op.reg == 0)
prefetchw((void *) op.ea);
break;
case DCBT:
if (op.reg == 0)
prefetch((void *) op.ea);
break;
case ICBI:
__cacheop_user_asmx(op.ea, err, "icbi");
break;
}
if (err)
return 0;
goto instr_done;
case LARX:
if (op.ea & (size - 1))
break;
if (!address_ok(regs, op.ea, size))
return 0;
err = 0;
switch (size) {
case 4:
__get_user_asmx(val, op.ea, err, "lwarx");
break;
#ifdef __powerpc64__
case 8:
__get_user_asmx(val, op.ea, err, "ldarx");
break;
#endif
default:
return 0;
}
if (!err)
regs->gpr[op.reg] = val;
goto ldst_done;
case STCX:
if (op.ea & (size - 1))
break;
if (!address_ok(regs, op.ea, size))
return 0;
err = 0;
switch (size) {
case 4:
__put_user_asmx(op.val, op.ea, err, "stwcx.", cr);
break;
#ifdef __powerpc64__
case 8:
__put_user_asmx(op.val, op.ea, err, "stdcx.", cr);
break;
#endif
default:
return 0;
}
if (!err)
regs->ccr = (regs->ccr & 0x0fffffff) |
(cr & 0xe0000000) |
((regs->xer >> 3) & 0x10000000);
goto ldst_done;
case LOAD:
err = read_mem(&regs->gpr[op.reg], op.ea, size, regs);
if (!err) {
if (op.type & SIGNEXT)
do_signext(&regs->gpr[op.reg], size);
if (op.type & BYTEREV)
do_byterev(&regs->gpr[op.reg], size);
}
goto ldst_done;
#ifdef CONFIG_PPC_FPU
case LOAD_FP:
if (size == 4)
err = do_fp_load(op.reg, do_lfs, op.ea, size, regs);
else
err = do_fp_load(op.reg, do_lfd, op.ea, size, regs);
goto ldst_done;
#endif
#ifdef CONFIG_ALTIVEC
case LOAD_VMX:
err = do_vec_load(op.reg, do_lvx, op.ea & ~0xfUL, regs);
goto ldst_done;
#endif
#ifdef CONFIG_VSX
case LOAD_VSX:
err = do_vsx_load(op.reg, do_lxvd2x, op.ea, regs);
goto ldst_done;
#endif
case LOAD_MULTI:
if (regs->msr & MSR_LE)
return 0;
rd = op.reg;
for (i = 0; i < size; i += 4) {
nb = size - i;
if (nb > 4)
nb = 4;
err = read_mem(&regs->gpr[rd], op.ea, nb, regs);
if (err)
return 0;
if (nb < 4)
regs->gpr[rd] <<= 32 - 8 * nb;
op.ea += 4;
++rd;
}
goto instr_done;
case STORE:
if ((op.type & UPDATE) && size == sizeof(long) &&
op.reg == 1 && op.update_reg == 1 &&
!(regs->msr & MSR_PR) &&
op.ea >= regs->gpr[1] - STACK_INT_FRAME_SIZE) {
err = handle_stack_update(op.ea, regs);
goto ldst_done;
}
err = write_mem(op.val, op.ea, size, regs);
goto ldst_done;
#ifdef CONFIG_PPC_FPU
case STORE_FP:
if (size == 4)
err = do_fp_store(op.reg, do_stfs, op.ea, size, regs);
else
err = do_fp_store(op.reg, do_stfd, op.ea, size, regs);
goto ldst_done;
#endif
#ifdef CONFIG_ALTIVEC
case STORE_VMX:
err = do_vec_store(op.reg, do_stvx, op.ea & ~0xfUL, regs);
goto ldst_done;
#endif
#ifdef CONFIG_VSX
case STORE_VSX:
err = do_vsx_store(op.reg, do_stxvd2x, op.ea, regs);
goto ldst_done;
#endif
case STORE_MULTI:
if (regs->msr & MSR_LE)
return 0;
rd = op.reg;
for (i = 0; i < size; i += 4) {
val = regs->gpr[rd];
nb = size - i;
if (nb > 4)
nb = 4;
else
val >>= 32 - 8 * nb;
err = write_mem(val, op.ea, nb, regs);
if (err)
return 0;
op.ea += 4;
++rd;
}
goto instr_done;
case MFMSR:
regs->gpr[op.reg] = regs->msr & MSR_MASK;
goto instr_done;
case MTMSR:
val = regs->gpr[op.reg];
if ((val & MSR_RI) == 0)
return -1;
regs->msr = (regs->msr & ~op.val) | (val & op.val);
goto instr_done;
#ifdef CONFIG_PPC64
case SYSCALL:
if (regs->gpr[0] == 0x1ebe &&
cpu_has_feature(CPU_FTR_REAL_LE)) {
regs->msr ^= MSR_LE;
goto instr_done;
}
regs->gpr[9] = regs->gpr[13];
regs->gpr[10] = MSR_KERNEL;
regs->gpr[11] = regs->nip + 4;
regs->gpr[12] = regs->msr & MSR_MASK;
regs->gpr[13] = (unsigned long) get_paca();
regs->nip = (unsigned long) &system_call_common;
regs->msr = MSR_KERNEL;
return 1;
case RFI:
return -1;
#endif
}
return 0;
ldst_done:
if (err)
return 0;
if (op.type & UPDATE)
regs->gpr[op.update_reg] = op.ea;
instr_done:
regs->nip = truncate_if_32bit(regs->msr, regs->nip + 4);
return 1;
}
