static inline unsigned make_dsisr(unsigned instr)
{
unsigned dsisr;
dsisr = (instr & 0x03ff0000) >> 16;
if (IS_XFORM(instr)) {
dsisr |= (instr & 0x00000006) << 14;
dsisr |= (instr & 0x00000040) << 8;
dsisr |= (instr & 0x00000780) << 3;
} else {
dsisr |= (instr & 0x04000000) >> 12;
dsisr |= (instr & 0x78000000) >> 17;
if (IS_DSFORM(instr))
dsisr |= (instr & 0x00000003) << 18;
}
return dsisr;
}
static int emulate_dcbz(struct pt_regs *regs, unsigned char __user *addr)
{
long __user *p;
int i, size;
#ifdef __powerpc64__
size = ppc64_caches.dline_size;
#else
size = L1_CACHE_BYTES;
#endif
p = (long __user *) (regs->dar & -size);
if (user_mode(regs) && !access_ok(VERIFY_WRITE, p, size))
return -EFAULT;
for (i = 0; i < size / sizeof(long); ++i)
if (__put_user_inatomic(0, p+i))
return -EFAULT;
return 1;
}
static int emulate_multiple(struct pt_regs *regs, unsigned char __user *addr,
unsigned int reg, unsigned int nb,
unsigned int flags, unsigned int instr,
unsigned long swiz)
{
unsigned long *rptr;
unsigned int nb0, i, bswiz;
unsigned long p;
if (unlikely((nb > 4) || !user_mode(regs)))
return 0;
nb0 = 0;
if (flags & HARD) {
if (flags & SX) {
nb = regs->xer & 127;
if (nb == 0)
return 1;
} else {
unsigned long pc = regs->nip ^ (swiz & 4);
if (__get_user_inatomic(instr,
(unsigned int __user *)pc))
return -EFAULT;
if (swiz == 0 && (flags & SW))
instr = cpu_to_le32(instr);
nb = (instr >> 11) & 0x1f;
if (nb == 0)
nb = 32;
}
if (nb + reg * 4 > 128) {
nb0 = nb + reg * 4 - 128;
nb = 128 - reg * 4;
}
} else {
nb = (32 - reg) * 4;
}
if (!access_ok((flags & ST ? VERIFY_WRITE: VERIFY_READ), addr, nb+nb0))
return -EFAULT;
rptr = &regs->gpr[reg];
p = (unsigned long) addr;
bswiz = (flags & SW)? 3: 0;
if (!(flags & ST)) {
memset(rptr, 0, ((nb + 3) / 4) * sizeof(unsigned long));
if (nb0 > 0)
memset(&regs->gpr[0], 0,
((nb0 + 3) / 4) * sizeof(unsigned long));
for (i = 0; i < nb; ++i, ++p)
if (__get_user_inatomic(REG_BYTE(rptr, i ^ bswiz),
SWIZ_PTR(p)))
return -EFAULT;
if (nb0 > 0) {
rptr = &regs->gpr[0];
addr += nb;
for (i = 0; i < nb0; ++i, ++p)
if (__get_user_inatomic(REG_BYTE(rptr,
i ^ bswiz),
SWIZ_PTR(p)))
return -EFAULT;
}
} else {
for (i = 0; i < nb; ++i, ++p)
if (__put_user_inatomic(REG_BYTE(rptr, i ^ bswiz),
SWIZ_PTR(p)))
return -EFAULT;
if (nb0 > 0) {
rptr = &regs->gpr[0];
addr += nb;
for (i = 0; i < nb0; ++i, ++p)
if (__put_user_inatomic(REG_BYTE(rptr,
i ^ bswiz),
SWIZ_PTR(p)))
return -EFAULT;
}
}
return 1;
}
static int emulate_fp_pair(unsigned char __user *addr, unsigned int reg,
unsigned int flags)
{
char *ptr0 = (char *) &current->thread.TS_FPR(reg);
char *ptr1 = (char *) &current->thread.TS_FPR(reg+1);
int i, ret, sw = 0;
if (!(flags & F))
return 0;
if (reg & 1)
return 0;
if (flags & SW)
sw = 7;
ret = 0;
for (i = 0; i < 8; ++i) {
if (!(flags & ST)) {
ret |= __get_user(ptr0[i^sw], addr + i);
ret |= __get_user(ptr1[i^sw], addr + i + 8);
} else {
ret |= __put_user(ptr0[i^sw], addr + i);
ret |= __put_user(ptr1[i^sw], addr + i + 8);
}
}
if (ret)
return -EFAULT;
return 1;
}
static int emulate_spe(struct pt_regs *regs, unsigned int reg,
unsigned int instr)
{
int t, ret;
union {
u64 ll;
u32 w[2];
u16 h[4];
u8 v[8];
} data, temp;
unsigned char __user *p, *addr;
unsigned long *evr = &current->thread.evr[reg];
unsigned int nb, flags;
instr = (instr >> 1) & 0x1f;
addr = (unsigned char __user *)regs->dar;
nb = spe_aligninfo[instr].len;
flags = spe_aligninfo[instr].flags;
if (unlikely(user_mode(regs) &&
!access_ok((flags & ST ? VERIFY_WRITE : VERIFY_READ),
addr, nb)))
return -EFAULT;
if (unlikely(!user_mode(regs)))
return 0;
flush_spe_to_thread(current);
if (flags & ST) {
data.ll = 0;
switch (instr) {
case EVSTDD:
case EVSTDW:
case EVSTDH:
data.w[0] = *evr;
data.w[1] = regs->gpr[reg];
break;
case EVSTWHE:
data.h[2] = *evr >> 16;
data.h[3] = regs->gpr[reg] >> 16;
break;
case EVSTWHO:
data.h[2] = *evr & 0xffff;
data.h[3] = regs->gpr[reg] & 0xffff;
break;
case EVSTWWE:
data.w[1] = *evr;
break;
case EVSTWWO:
data.w[1] = regs->gpr[reg];
break;
default:
return -EINVAL;
}
} else {
temp.ll = data.ll = 0;
ret = 0;
p = addr;
switch (nb) {
case 8:
ret |= __get_user_inatomic(temp.v[0], p++);
ret |= __get_user_inatomic(temp.v[1], p++);
ret |= __get_user_inatomic(temp.v[2], p++);
ret |= __get_user_inatomic(temp.v[3], p++);
case 4:
ret |= __get_user_inatomic(temp.v[4], p++);
ret |= __get_user_inatomic(temp.v[5], p++);
case 2:
ret |= __get_user_inatomic(temp.v[6], p++);
ret |= __get_user_inatomic(temp.v[7], p++);
if (unlikely(ret))
return -EFAULT;
}
switch (instr) {
case EVLDD:
case EVLDW:
case EVLDH:
data.ll = temp.ll;
break;
case EVLHHESPLAT:
data.h[0] = temp.h[3];
data.h[2] = temp.h[3];
break;
case EVLHHOUSPLAT:
case EVLHHOSSPLAT:
data.h[1] = temp.h[3];
data.h[3] = temp.h[3];
break;
case EVLWHE:
data.h[0] = temp.h[2];
data.h[2] = temp.h[3];
break;
case EVLWHOU:
case EVLWHOS:
data.h[1] = temp.h[2];
data.h[3] = temp.h[3];
break;
case EVLWWSPLAT:
data.w[0] = temp.w[1];
data.w[1] = temp.w[1];
break;
case EVLWHSPLAT:
data.h[0] = temp.h[2];
data.h[1] = temp.h[2];
data.h[2] = temp.h[3];
data.h[3] = temp.h[3];
break;
default:
return -EINVAL;
}
}
if (flags & SW) {
switch (flags & 0xf0) {
case E8:
SWAP(data.v[0], data.v[7]);
SWAP(data.v[1], data.v[6]);
SWAP(data.v[2], data.v[5]);
SWAP(data.v[3], data.v[4]);
break;
case E4:
SWAP(data.v[0], data.v[3]);
SWAP(data.v[1], data.v[2]);
SWAP(data.v[4], data.v[7]);
SWAP(data.v[5], data.v[6]);
break;
default:
SWAP(data.v[0], data.v[1]);
SWAP(data.v[2], data.v[3]);
SWAP(data.v[4], data.v[5]);
SWAP(data.v[6], data.v[7]);
break;
}
}
if (flags & SE) {
data.w[0] = (s16)data.h[1];
data.w[1] = (s16)data.h[3];
}
if (flags & ST) {
ret = 0;
p = addr;
switch (nb) {
case 8:
ret |= __put_user_inatomic(data.v[0], p++);
ret |= __put_user_inatomic(data.v[1], p++);
ret |= __put_user_inatomic(data.v[2], p++);
ret |= __put_user_inatomic(data.v[3], p++);
case 4:
ret |= __put_user_inatomic(data.v[4], p++);
ret |= __put_user_inatomic(data.v[5], p++);
case 2:
ret |= __put_user_inatomic(data.v[6], p++);
ret |= __put_user_inatomic(data.v[7], p++);
}
if (unlikely(ret))
return -EFAULT;
} else {
*evr = data.w[0];
regs->gpr[reg] = data.w[1];
}
return 1;
}
static int emulate_vsx(unsigned char __user *addr, unsigned int reg,
unsigned int areg, struct pt_regs *regs,
unsigned int flags, unsigned int length,
unsigned int elsize)
{
char *ptr;
unsigned long *lptr;
int ret = 0;
int sw = 0;
int i, j;
flush_vsx_to_thread(current);
if (reg < 32)
ptr = (char *) &current->thread.TS_FPR(reg);
else
ptr = (char *) &current->thread.vr[reg - 32];
lptr = (unsigned long *) ptr;
if (flags & SW)
sw = elsize-1;
for (j = 0; j < length; j += elsize) {
for (i = 0; i < elsize; ++i) {
if (flags & ST)
ret |= __put_user(ptr[i^sw], addr + i);
else
ret |= __get_user(ptr[i^sw], addr + i);
}
ptr += elsize;
addr += elsize;
}
if (!ret) {
if (flags & U)
regs->gpr[areg] = regs->dar;
if (flags & SPLT)
lptr[1] = lptr[0];
else if (!(flags & ST) && (8 == length))
lptr[1] = 0;
} else
return -EFAULT;
return 1;
}
int fix_alignment(struct pt_regs *regs)
{
unsigned int instr, nb, flags, instruction = 0;
unsigned int reg, areg;
unsigned int dsisr;
unsigned char __user *addr;
unsigned long p, swiz;
int ret, t;
union {
u64 ll;
double dd;
unsigned char v[8];
struct {
unsigned hi32;
int low32;
} x32;
struct {
unsigned char hi48[6];
short low16;
} x16;
} data;
CHECK_FULL_REGS(regs);
dsisr = regs->dsisr;
if (cpu_has_feature(CPU_FTR_NODSISRALIGN)) {
unsigned long pc = regs->nip;
if (cpu_has_feature(CPU_FTR_PPC_LE) && (regs->msr & MSR_LE))
pc ^= 4;
if (unlikely(__get_user_inatomic(instr,
(unsigned int __user *)pc)))
return -EFAULT;
if (cpu_has_feature(CPU_FTR_REAL_LE) && (regs->msr & MSR_LE))
instr = cpu_to_le32(instr);
dsisr = make_dsisr(instr);
instruction = instr;
}
reg = (dsisr >> 5) & 0x1f;
areg = dsisr & 0x1f;
#ifdef CONFIG_SPE
if ((instr >> 26) == 0x4) {
PPC_WARN_ALIGNMENT(spe, regs);
return emulate_spe(regs, reg, instr);
}
#endif
instr = (dsisr >> 10) & 0x7f;
instr |= (dsisr >> 13) & 0x60;
nb = aligninfo[instr].len;
flags = aligninfo[instr].flags;
swiz = 0;
if (regs->msr & MSR_LE) {
flags ^= SW;
if (cpu_has_feature(CPU_FTR_PPC_LE))
swiz = 7;
}
addr = (unsigned char __user *)regs->dar;
#ifdef CONFIG_VSX
if ((instruction & 0xfc00003e) == 0x7c000018) {
unsigned int elsize;
reg |= (instruction & 0x1) << 5;
nb = 8;
if (instruction & 0x200)
nb = 16;
elsize = 4;
if (instruction & 0x80)
elsize = 8;
flags = 0;
if (regs->msr & MSR_LE)
flags |= SW;
if (instruction & 0x100)
flags |= ST;
if (instruction & 0x040)
flags |= U;
if ((instruction & 0x400) == 0){
flags |= SPLT;
nb = 8;
}
PPC_WARN_ALIGNMENT(vsx, regs);
return emulate_vsx(addr, reg, areg, regs, flags, nb, elsize);
}
#endif
if (instr == DCBZ) {
PPC_WARN_ALIGNMENT(dcbz, regs);
return emulate_dcbz(regs, addr);
}
if (unlikely(nb == 0))
return 0;
if (flags & M) {
PPC_WARN_ALIGNMENT(multiple, regs);
return emulate_multiple(regs, addr, reg, nb,
flags, instr, swiz);
}
if (unlikely(user_mode(regs) &&
!access_ok((flags & ST ? VERIFY_WRITE : VERIFY_READ),
addr, nb)))
return -EFAULT;
if (flags & F) {
if (unlikely(!user_mode(regs)))
return 0;
flush_fp_to_thread(current);
}
if (nb == 16) {
PPC_WARN_ALIGNMENT(fp_pair, regs);
return emulate_fp_pair(addr, reg, flags);
}
PPC_WARN_ALIGNMENT(unaligned, regs);
if (!(flags & ST)) {
data.ll = 0;
ret = 0;
p = (unsigned long) addr;
switch (nb) {
case 8:
ret |= __get_user_inatomic(data.v[0], SWIZ_PTR(p++));
ret |= __get_user_inatomic(data.v[1], SWIZ_PTR(p++));
ret |= __get_user_inatomic(data.v[2], SWIZ_PTR(p++));
ret |= __get_user_inatomic(data.v[3], SWIZ_PTR(p++));
case 4:
ret |= __get_user_inatomic(data.v[4], SWIZ_PTR(p++));
ret |= __get_user_inatomic(data.v[5], SWIZ_PTR(p++));
case 2:
ret |= __get_user_inatomic(data.v[6], SWIZ_PTR(p++));
ret |= __get_user_inatomic(data.v[7], SWIZ_PTR(p++));
if (unlikely(ret))
return -EFAULT;
}
} else if (flags & F) {
data.dd = current->thread.TS_FPR(reg);
if (flags & S) {
#ifdef CONFIG_PPC_FPU
preempt_disable();
enable_kernel_fp();
cvt_df(&data.dd, (float *)&data.v[4]);
preempt_enable();
#else
return 0;
#endif
}
} else
data.ll = regs->gpr[reg];
if (flags & SW) {
switch (nb) {
case 8:
SWAP(data.v[0], data.v[7]);
SWAP(data.v[1], data.v[6]);
SWAP(data.v[2], data.v[5]);
SWAP(data.v[3], data.v[4]);
break;
case 4:
SWAP(data.v[4], data.v[7]);
SWAP(data.v[5], data.v[6]);
break;
case 2:
SWAP(data.v[6], data.v[7]);
break;
}
}
switch (flags & ~(U|SW)) {
case LD+SE:
case LD+F+SE:
if ( nb == 2 )
data.ll = data.x16.low16;
else
data.ll = data.x32.low32;
break;
case LD+F+S:
#ifdef CONFIG_PPC_FPU
preempt_disable();
enable_kernel_fp();
cvt_fd((float *)&data.v[4], &data.dd);
preempt_enable();
#else
return 0;
#endif
break;
}
if (flags & ST) {
ret = 0;
p = (unsigned long) addr;
switch (nb) {
case 8:
ret |= __put_user_inatomic(data.v[0], SWIZ_PTR(p++));
ret |= __put_user_inatomic(data.v[1], SWIZ_PTR(p++));
ret |= __put_user_inatomic(data.v[2], SWIZ_PTR(p++));
ret |= __put_user_inatomic(data.v[3], SWIZ_PTR(p++));
case 4:
ret |= __put_user_inatomic(data.v[4], SWIZ_PTR(p++));
ret |= __put_user_inatomic(data.v[5], SWIZ_PTR(p++));
case 2:
ret |= __put_user_inatomic(data.v[6], SWIZ_PTR(p++));
ret |= __put_user_inatomic(data.v[7], SWIZ_PTR(p++));
}
if (unlikely(ret))
return -EFAULT;
} else if (flags & F)
current->thread.TS_FPR(reg) = data.dd;
else
regs->gpr[reg] = data.ll;
if (flags & U)
regs->gpr[areg] = regs->dar;
return 1;
}
