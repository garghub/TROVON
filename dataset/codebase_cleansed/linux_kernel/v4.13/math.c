static int
fcmp_gt(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
if (CMP(CMP) > 0)
regs->sr |= 1;
else
regs->sr &= ~1;
return 0;
}
static int
fcmp_eq(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
if (CMP(CMP ) == 0)
regs->sr |= 1;
else
regs->sr &= ~1;
return 0;
}
static int
fadd(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
BOTH_PRmn(ARITH_X, ADD);
return 0;
}
static int
fsub(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
BOTH_PRmn(ARITH_X, SUB);
return 0;
}
static int
fmul(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
BOTH_PRmn(ARITH_X, MUL);
return 0;
}
static int
fdiv(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
BOTH_PRmn(ARITH_X, DIV);
return 0;
}
static int
fmac(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
FP_DECL_EX;
FP_DECL_S(Fr);
FP_DECL_S(Ft);
FP_DECL_S(F0);
FP_DECL_S(Fm);
FP_DECL_S(Fn);
UNPACK_S(F0, FR0);
UNPACK_S(Fm, FRm);
UNPACK_S(Fn, FRn);
FP_MUL_S(Ft, Fm, F0);
FP_ADD_S(Fr, Fn, Ft);
PACK_S(FRn, Fr);
return 0;
}
static int
fmov_idx_reg(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m,
int n)
{
if (FPSCR_SZ) {
FMOV_EXT(n);
READ(FRn, Rm + R0 + 4);
n++;
READ(FRn, Rm + R0);
} else {
READ(FRn, Rm + R0);
}
return 0;
}
static int
fmov_mem_reg(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m,
int n)
{
if (FPSCR_SZ) {
FMOV_EXT(n);
READ(FRn, Rm + 4);
n++;
READ(FRn, Rm);
} else {
READ(FRn, Rm);
}
return 0;
}
static int
fmov_inc_reg(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m,
int n)
{
if (FPSCR_SZ) {
FMOV_EXT(n);
READ(FRn, Rm + 4);
n++;
READ(FRn, Rm);
Rm += 8;
} else {
READ(FRn, Rm);
Rm += 4;
}
return 0;
}
static int
fmov_reg_idx(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m,
int n)
{
if (FPSCR_SZ) {
FMOV_EXT(m);
WRITE(FRm, Rn + R0 + 4);
m++;
WRITE(FRm, Rn + R0);
} else {
WRITE(FRm, Rn + R0);
}
return 0;
}
static int
fmov_reg_mem(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m,
int n)
{
if (FPSCR_SZ) {
FMOV_EXT(m);
WRITE(FRm, Rn + 4);
m++;
WRITE(FRm, Rn);
} else {
WRITE(FRm, Rn);
}
return 0;
}
static int
fmov_reg_dec(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m,
int n)
{
if (FPSCR_SZ) {
FMOV_EXT(m);
Rn -= 8;
WRITE(FRm, Rn + 4);
m++;
WRITE(FRm, Rn);
} else {
Rn -= 4;
WRITE(FRm, Rn);
}
return 0;
}
static int
fmov_reg_reg(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m,
int n)
{
if (FPSCR_SZ) {
FMOV_EXT(m);
FMOV_EXT(n);
DRn = DRm;
} else {
FRn = FRm;
}
return 0;
}
static int
fnop_mn(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int m, int n)
{
return -EINVAL;
}
static int ffloat(struct sh_fpu_soft_struct *fregs, int n)
{
FP_DECL_EX;
if (FPSCR_PR)
EMU_FLOAT_X(D, DRn);
else
EMU_FLOAT_X(S, FRn);
return 0;
}
static int ftrc(struct sh_fpu_soft_struct *fregs, int n)
{
FP_DECL_EX;
if (FPSCR_PR)
EMU_FTRC_X(D, DRn);
else
EMU_FTRC_X(S, FRn);
return 0;
}
static int fcnvsd(struct sh_fpu_soft_struct *fregs, int n)
{
FP_DECL_EX;
FP_DECL_S(Fn);
FP_DECL_D(Fr);
UNPACK_S(Fn, FPUL);
FP_CONV(D, S, 2, 1, Fr, Fn);
PACK_D(DRn, Fr);
return 0;
}
static int fcnvds(struct sh_fpu_soft_struct *fregs, int n)
{
FP_DECL_EX;
FP_DECL_D(Fn);
FP_DECL_S(Fr);
UNPACK_D(Fn, DRn);
FP_CONV(S, D, 1, 2, Fr, Fn);
PACK_S(FPUL, Fr);
return 0;
}
static int fxchg(struct sh_fpu_soft_struct *fregs, int flag)
{
FPSCR ^= flag;
return 0;
}
static int fsts(struct sh_fpu_soft_struct *fregs, int n)
{
FRn = FPUL;
return 0;
}
static int flds(struct sh_fpu_soft_struct *fregs, int n)
{
FPUL = FRn;
return 0;
}
static int fneg(struct sh_fpu_soft_struct *fregs, int n)
{
FRn ^= (1 << (_FP_W_TYPE_SIZE - 1));
return 0;
}
static int fabs(struct sh_fpu_soft_struct *fregs, int n)
{
FRn &= ~(1 << (_FP_W_TYPE_SIZE - 1));
return 0;
}
static int fld0(struct sh_fpu_soft_struct *fregs, int n)
{
FRn = 0;
return 0;
}
static int fld1(struct sh_fpu_soft_struct *fregs, int n)
{
FRn = (_FP_EXPBIAS_S << (_FP_FRACBITS_S - 1));
return 0;
}
static int fnop_n(struct sh_fpu_soft_struct *fregs, int n)
{
return -EINVAL;
}
static int id_fxfd(struct sh_fpu_soft_struct *fregs, int x)
{
const int flag[] = { FPSCR_SZ, FPSCR_PR, FPSCR_FR, 0 };
switch (x & 3) {
case 3:
fxchg(fregs, flag[x >> 2]);
break;
case 1:
ftrv(fregs, x - 1);
break;
default:
fsca(fregs, x);
}
return 0;
}
static int
id_fnxd(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, int x, int n)
{
return (fnxd[x])(fregs, n);
}
static int
id_fnmx(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, u16 code)
{
int n = (code >> 8) & 0xf, m = (code >> 4) & 0xf, x = code & 0xf;
return (fnmx[x])(fregs, regs, m, n);
}
static int
id_sys(struct sh_fpu_soft_struct *fregs, struct pt_regs *regs, u16 code)
{
int n = ((code >> 8) & 0xf);
unsigned long *reg = (code & 0x0010) ? &FPUL : &FPSCR;
switch (code & 0xf0ff) {
case 0x005a:
case 0x006a:
Rn = *reg;
break;
case 0x405a:
case 0x406a:
*reg = Rn;
break;
case 0x4052:
case 0x4062:
Rn -= 4;
WRITE(*reg, Rn);
break;
case 0x4056:
case 0x4066:
READ(*reg, Rn);
Rn += 4;
break;
default:
return -EINVAL;
}
return 0;
}
static int fpu_emulate(u16 code, struct sh_fpu_soft_struct *fregs, struct pt_regs *regs)
{
if ((code & 0xf000) == 0xf000)
return id_fnmx(fregs, regs, code);
else
return id_sys(fregs, regs, code);
}
static void denormal_to_double(struct sh_fpu_soft_struct *fpu, int n)
{
unsigned long du, dl;
unsigned long x = fpu->fpul;
int exp = 1023 - 126;
if (x != 0 && (x & 0x7f800000) == 0) {
du = (x & 0x80000000);
while ((x & 0x00800000) == 0) {
x <<= 1;
exp--;
}
x &= 0x007fffff;
du |= (exp << 20) | (x >> 3);
dl = x << 29;
fpu->fp_regs[n] = du;
fpu->fp_regs[n+1] = dl;
}
}
static int ieee_fpe_handler(struct pt_regs *regs)
{
unsigned short insn = *(unsigned short *)regs->pc;
unsigned short finsn;
unsigned long nextpc;
siginfo_t info;
int nib[4] = {
(insn >> 12) & 0xf,
(insn >> 8) & 0xf,
(insn >> 4) & 0xf,
insn & 0xf};
if (nib[0] == 0xb ||
(nib[0] == 0x4 && nib[2] == 0x0 && nib[3] == 0xb))
regs->pr = regs->pc + 4;
if (nib[0] == 0xa || nib[0] == 0xb) {
nextpc = regs->pc + 4 + ((short) ((insn & 0xfff) << 4) >> 3);
finsn = *(unsigned short *) (regs->pc + 2);
} else if (nib[0] == 0x8 && nib[1] == 0xd) {
if (regs->sr & 1)
nextpc = regs->pc + 4 + ((char) (insn & 0xff) << 1);
else
nextpc = regs->pc + 4;
finsn = *(unsigned short *) (regs->pc + 2);
} else if (nib[0] == 0x8 && nib[1] == 0xf) {
if (regs->sr & 1)
nextpc = regs->pc + 4;
else
nextpc = regs->pc + 4 + ((char) (insn & 0xff) << 1);
finsn = *(unsigned short *) (regs->pc + 2);
} else if (nib[0] == 0x4 && nib[3] == 0xb &&
(nib[2] == 0x0 || nib[2] == 0x2)) {
nextpc = regs->regs[nib[1]];
finsn = *(unsigned short *) (regs->pc + 2);
} else if (nib[0] == 0x0 && nib[3] == 0x3 &&
(nib[2] == 0x0 || nib[2] == 0x2)) {
nextpc = regs->pc + 4 + regs->regs[nib[1]];
finsn = *(unsigned short *) (regs->pc + 2);
} else if (insn == 0x000b) {
nextpc = regs->pr;
finsn = *(unsigned short *) (regs->pc + 2);
} else {
nextpc = regs->pc + 2;
finsn = insn;
}
if ((finsn & 0xf1ff) == 0xf0ad) {
struct task_struct *tsk = current;
if ((tsk->thread.xstate->softfpu.fpscr & (1 << 17))) {
denormal_to_double (&tsk->thread.xstate->softfpu,
(finsn >> 8) & 0xf);
tsk->thread.xstate->softfpu.fpscr &=
~(FPSCR_CAUSE_MASK | FPSCR_FLAG_MASK);
task_thread_info(tsk)->status |= TS_USEDFPU;
} else {
info.si_signo = SIGFPE;
info.si_errno = 0;
info.si_code = FPE_FLTINV;
info.si_addr = (void __user *)regs->pc;
force_sig_info(SIGFPE, &info, tsk);
}
regs->pc = nextpc;
return 1;
}
return 0;
}
static void fpu_init(struct sh_fpu_soft_struct *fpu)
{
int i;
fpu->fpscr = FPSCR_INIT;
fpu->fpul = 0;
for (i = 0; i < 16; i++) {
fpu->fp_regs[i] = 0;
fpu->xfp_regs[i]= 0;
}
}
int do_fpu_inst(unsigned short inst, struct pt_regs *regs)
{
struct task_struct *tsk = current;
struct sh_fpu_soft_struct *fpu = &(tsk->thread.xstate->softfpu);
perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, regs, 0);
if (!(task_thread_info(tsk)->status & TS_USEDFPU)) {
fpu_init(fpu);
task_thread_info(tsk)->status |= TS_USEDFPU;
}
return fpu_emulate(inst, fpu, regs);
}
