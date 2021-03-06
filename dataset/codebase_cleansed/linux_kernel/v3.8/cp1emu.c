static int isBranchInstr(mips_instruction * i)
{
switch (MIPSInst_OPCODE(*i)) {
case spec_op:
switch (MIPSInst_FUNC(*i)) {
case jalr_op:
case jr_op:
return 1;
}
break;
case bcond_op:
switch (MIPSInst_RT(*i)) {
case bltz_op:
case bgez_op:
case bltzl_op:
case bgezl_op:
case bltzal_op:
case bgezal_op:
case bltzall_op:
case bgezall_op:
return 1;
}
break;
case j_op:
case jal_op:
case jalx_op:
case beq_op:
case bne_op:
case blez_op:
case bgtz_op:
case beql_op:
case bnel_op:
case blezl_op:
case bgtzl_op:
return 1;
case cop0_op:
case cop1_op:
case cop2_op:
case cop1x_op:
if (MIPSInst_RS(*i) == bc_op)
return 1;
break;
}
return 0;
}
static inline int cop1_64bit(struct pt_regs *xcp)
{
#if defined(CONFIG_64BIT) && !defined(CONFIG_MIPS32_O32)
return 1;
#elif defined(CONFIG_64BIT) && defined(CONFIG_MIPS32_O32)
return !test_thread_flag(TIF_32BIT_REGS);
#else
return 0;
#endif
}
static int cop1Emulate(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
void *__user *fault_addr)
{
mips_instruction ir;
unsigned long emulpc, contpc;
unsigned int cond;
if (!access_ok(VERIFY_READ, xcp->cp0_epc, sizeof(mips_instruction))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)xcp->cp0_epc;
return SIGBUS;
}
if (__get_user(ir, (mips_instruction __user *) xcp->cp0_epc)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)xcp->cp0_epc;
return SIGSEGV;
}
if ((xcp->cp0_cause & CAUSEF_BD) && !isBranchInstr(&ir))
xcp->cp0_cause &= ~CAUSEF_BD;
if (xcp->cp0_cause & CAUSEF_BD) {
emulpc = xcp->cp0_epc + 4;
if (__compute_return_epc(xcp) < 0) {
#ifdef CP1DBG
printk("failed to emulate branch at %p\n",
(void *) (xcp->cp0_epc));
#endif
return SIGILL;
}
if (!access_ok(VERIFY_READ, emulpc, sizeof(mips_instruction))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)emulpc;
return SIGBUS;
}
if (__get_user(ir, (mips_instruction __user *) emulpc)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)emulpc;
return SIGSEGV;
}
contpc = xcp->cp0_epc;
xcp->cp0_epc = emulpc - 4;
} else {
emulpc = xcp->cp0_epc;
contpc = xcp->cp0_epc + 4;
}
emul:
perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, xcp, 0);
MIPS_FPU_EMU_INC_STATS(emulated);
switch (MIPSInst_OPCODE(ir)) {
case ldc1_op:{
u64 __user *va = (u64 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u64 val;
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
DITOREG(val, MIPSInst_RT(ir));
break;
}
case sdc1_op:{
u64 __user *va = (u64 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u64 val;
MIPS_FPU_EMU_INC_STATS(stores);
DIFROMREG(val, MIPSInst_RT(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
}
case lwc1_op:{
u32 __user *va = (u32 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u32 val;
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
SITOREG(val, MIPSInst_RT(ir));
break;
}
case swc1_op:{
u32 __user *va = (u32 __user *) (xcp->regs[MIPSInst_RS(ir)] +
MIPSInst_SIMM(ir));
u32 val;
MIPS_FPU_EMU_INC_STATS(stores);
SIFROMREG(val, MIPSInst_RT(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
}
case cop1_op:
switch (MIPSInst_RS(ir)) {
#if defined(__mips64)
case dmfc_op:
if (MIPSInst_RT(ir) != 0) {
DIFROMREG(xcp->regs[MIPSInst_RT(ir)],
MIPSInst_RD(ir));
}
break;
case dmtc_op:
DITOREG(xcp->regs[MIPSInst_RT(ir)], MIPSInst_RD(ir));
break;
#endif
case mfc_op:
if (MIPSInst_RT(ir) != 0) {
SIFROMREG(xcp->regs[MIPSInst_RT(ir)],
MIPSInst_RD(ir));
}
break;
case mtc_op:
SITOREG(xcp->regs[MIPSInst_RT(ir)], MIPSInst_RD(ir));
break;
case cfc_op:{
u32 value;
if (MIPSInst_RD(ir) == FPCREG_CSR) {
value = ctx->fcr31;
value = (value & ~FPU_CSR_RM) |
mips_rm[modeindex(value)];
#ifdef CSRTRACE
printk("%p gpr[%d]<-csr=%08x\n",
(void *) (xcp->cp0_epc),
MIPSInst_RT(ir), value);
#endif
}
else if (MIPSInst_RD(ir) == FPCREG_RID)
value = 0;
else
value = 0;
if (MIPSInst_RT(ir))
xcp->regs[MIPSInst_RT(ir)] = value;
break;
}
case ctc_op:{
u32 value;
if (MIPSInst_RT(ir) == 0)
value = 0;
else
value = xcp->regs[MIPSInst_RT(ir)];
if (MIPSInst_RD(ir) == FPCREG_CSR) {
#ifdef CSRTRACE
printk("%p gpr[%d]->csr=%08x\n",
(void *) (xcp->cp0_epc),
MIPSInst_RT(ir), value);
#endif
ctx->fcr31 = (value &
~(FPU_CSR_RSVD | FPU_CSR_RM)) |
ieee_rm[modeindex(value)];
}
if ((ctx->fcr31 >> 5) & ctx->fcr31 & FPU_CSR_ALL_E) {
return SIGFPE;
}
break;
}
case bc_op:{
int likely = 0;
if (xcp->cp0_cause & CAUSEF_BD)
return SIGILL;
#if __mips >= 4
cond = ctx->fcr31 & fpucondbit[MIPSInst_RT(ir) >> 2];
#else
cond = ctx->fcr31 & FPU_CSR_COND;
#endif
switch (MIPSInst_RT(ir) & 3) {
case bcfl_op:
likely = 1;
case bcf_op:
cond = !cond;
break;
case bctl_op:
likely = 1;
case bct_op:
break;
default:
return SIGILL;
}
xcp->cp0_cause |= CAUSEF_BD;
if (cond) {
xcp->cp0_epc += 4;
contpc = (xcp->cp0_epc +
(MIPSInst_SIMM(ir) << 2));
if (!access_ok(VERIFY_READ, xcp->cp0_epc,
sizeof(mips_instruction))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)xcp->cp0_epc;
return SIGBUS;
}
if (__get_user(ir,
(mips_instruction __user *) xcp->cp0_epc)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)xcp->cp0_epc;
return SIGSEGV;
}
switch (MIPSInst_OPCODE(ir)) {
case lwc1_op:
case swc1_op:
#if (__mips >= 2 || defined(__mips64))
case ldc1_op:
case sdc1_op:
#endif
case cop1_op:
#if __mips >= 4 && __mips != 32
case cop1x_op:
#endif
goto emul;
#if __mips >= 4
case spec_op:
if (MIPSInst_FUNC(ir) == movc_op)
goto emul;
break;
#endif
}
return mips_dsemul(xcp, ir, contpc);
}
else {
if (likely) {
xcp->cp0_epc += 4;
contpc += 4;
}
}
break;
}
default:
if (!(MIPSInst_RS(ir) & 0x10))
return SIGILL;
{
int sig;
if ((sig = fpu_emu(xcp, ctx, ir)))
return sig;
}
}
break;
#if __mips >= 4 && __mips != 32
case cop1x_op:{
int sig = fpux_emu(xcp, ctx, ir, fault_addr);
if (sig)
return sig;
break;
}
#endif
#if __mips >= 4
case spec_op:
if (MIPSInst_FUNC(ir) != movc_op)
return SIGILL;
cond = fpucondbit[MIPSInst_RT(ir) >> 2];
if (((ctx->fcr31 & cond) != 0) == ((MIPSInst_RT(ir) & 1) != 0))
xcp->regs[MIPSInst_RD(ir)] =
xcp->regs[MIPSInst_RS(ir)];
break;
#endif
default:
return SIGILL;
}
xcp->cp0_epc = contpc;
xcp->cp0_cause &= ~CAUSEF_BD;
return 0;
}
static ieee754dp fpemu_dp_recip(ieee754dp d)
{
return ieee754dp_div(ieee754dp_one(0), d);
}
static ieee754dp fpemu_dp_rsqrt(ieee754dp d)
{
return ieee754dp_div(ieee754dp_one(0), ieee754dp_sqrt(d));
}
static ieee754sp fpemu_sp_recip(ieee754sp s)
{
return ieee754sp_div(ieee754sp_one(0), s);
}
static ieee754sp fpemu_sp_rsqrt(ieee754sp s)
{
return ieee754sp_div(ieee754sp_one(0), ieee754sp_sqrt(s));
}
static int fpux_emu(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
mips_instruction ir, void *__user *fault_addr)
{
unsigned rcsr = 0;
MIPS_FPU_EMU_INC_STATS(cp1xops);
switch (MIPSInst_FMA_FFMT(ir)) {
case s_fmt:{
ieee754sp(*handler) (ieee754sp, ieee754sp, ieee754sp);
ieee754sp fd, fr, fs, ft;
u32 __user *va;
u32 val;
switch (MIPSInst_FUNC(ir)) {
case lwxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
SITOREG(val, MIPSInst_FD(ir));
break;
case swxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(stores);
SIFROMREG(val, MIPSInst_FS(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u32))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
case madd_s_op:
handler = fpemu_sp_madd;
goto scoptop;
case msub_s_op:
handler = fpemu_sp_msub;
goto scoptop;
case nmadd_s_op:
handler = fpemu_sp_nmadd;
goto scoptop;
case nmsub_s_op:
handler = fpemu_sp_nmsub;
goto scoptop;
scoptop:
SPFROMREG(fr, MIPSInst_FR(ir));
SPFROMREG(fs, MIPSInst_FS(ir));
SPFROMREG(ft, MIPSInst_FT(ir));
fd = (*handler) (fr, fs, ft);
SPTOREG(fd, MIPSInst_FD(ir));
copcsr:
if (ieee754_cxtest(IEEE754_INEXACT))
rcsr |= FPU_CSR_INE_X | FPU_CSR_INE_S;
if (ieee754_cxtest(IEEE754_UNDERFLOW))
rcsr |= FPU_CSR_UDF_X | FPU_CSR_UDF_S;
if (ieee754_cxtest(IEEE754_OVERFLOW))
rcsr |= FPU_CSR_OVF_X | FPU_CSR_OVF_S;
if (ieee754_cxtest(IEEE754_INVALID_OPERATION))
rcsr |= FPU_CSR_INV_X | FPU_CSR_INV_S;
ctx->fcr31 = (ctx->fcr31 & ~FPU_CSR_ALL_X) | rcsr;
if ((ctx->fcr31 >> 5) & ctx->fcr31 & FPU_CSR_ALL_E) {
return SIGFPE;
}
break;
default:
return SIGILL;
}
break;
}
case d_fmt:{
ieee754dp(*handler) (ieee754dp, ieee754dp, ieee754dp);
ieee754dp fd, fr, fs, ft;
u64 __user *va;
u64 val;
switch (MIPSInst_FUNC(ir)) {
case ldxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(loads);
if (!access_ok(VERIFY_READ, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__get_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
DITOREG(val, MIPSInst_FD(ir));
break;
case sdxc1_op:
va = (void __user *) (xcp->regs[MIPSInst_FR(ir)] +
xcp->regs[MIPSInst_FT(ir)]);
MIPS_FPU_EMU_INC_STATS(stores);
DIFROMREG(val, MIPSInst_FS(ir));
if (!access_ok(VERIFY_WRITE, va, sizeof(u64))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGBUS;
}
if (__put_user(val, va)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = va;
return SIGSEGV;
}
break;
case madd_d_op:
handler = fpemu_dp_madd;
goto dcoptop;
case msub_d_op:
handler = fpemu_dp_msub;
goto dcoptop;
case nmadd_d_op:
handler = fpemu_dp_nmadd;
goto dcoptop;
case nmsub_d_op:
handler = fpemu_dp_nmsub;
goto dcoptop;
dcoptop:
DPFROMREG(fr, MIPSInst_FR(ir));
DPFROMREG(fs, MIPSInst_FS(ir));
DPFROMREG(ft, MIPSInst_FT(ir));
fd = (*handler) (fr, fs, ft);
DPTOREG(fd, MIPSInst_FD(ir));
goto copcsr;
default:
return SIGILL;
}
break;
}
case 0x7:
if (MIPSInst_FUNC(ir) != pfetch_op) {
return SIGILL;
}
break;
default:
return SIGILL;
}
return 0;
}
static int fpu_emu(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
mips_instruction ir)
{
int rfmt;
unsigned rcsr = 0;
unsigned cond;
union {
ieee754dp d;
ieee754sp s;
int w;
#ifdef __mips64
s64 l;
#endif
} rv;
MIPS_FPU_EMU_INC_STATS(cp1ops);
switch (rfmt = (MIPSInst_FFMT(ir) & 0xf)) {
case s_fmt:{
union {
ieee754sp(*b) (ieee754sp, ieee754sp);
ieee754sp(*u) (ieee754sp);
} handler;
switch (MIPSInst_FUNC(ir)) {
case fadd_op:
handler.b = ieee754sp_add;
goto scopbop;
case fsub_op:
handler.b = ieee754sp_sub;
goto scopbop;
case fmul_op:
handler.b = ieee754sp_mul;
goto scopbop;
case fdiv_op:
handler.b = ieee754sp_div;
goto scopbop;
#if __mips >= 2 || defined(__mips64)
case fsqrt_op:
handler.u = ieee754sp_sqrt;
goto scopuop;
#endif
#if __mips >= 4 && __mips != 32
case frsqrt_op:
handler.u = fpemu_sp_rsqrt;
goto scopuop;
case frecip_op:
handler.u = fpemu_sp_recip;
goto scopuop;
#endif
#if __mips >= 4
case fmovc_op:
cond = fpucondbit[MIPSInst_FT(ir) >> 2];
if (((ctx->fcr31 & cond) != 0) !=
((MIPSInst_FT(ir) & 1) != 0))
return 0;
SPFROMREG(rv.s, MIPSInst_FS(ir));
break;
case fmovz_op:
if (xcp->regs[MIPSInst_FT(ir)] != 0)
return 0;
SPFROMREG(rv.s, MIPSInst_FS(ir));
break;
case fmovn_op:
if (xcp->regs[MIPSInst_FT(ir)] == 0)
return 0;
SPFROMREG(rv.s, MIPSInst_FS(ir));
break;
#endif
case fabs_op:
handler.u = ieee754sp_abs;
goto scopuop;
case fneg_op:
handler.u = ieee754sp_neg;
goto scopuop;
case fmov_op:
SPFROMREG(rv.s, MIPSInst_FS(ir));
goto copcsr;
scopbop:
{
ieee754sp fs, ft;
SPFROMREG(fs, MIPSInst_FS(ir));
SPFROMREG(ft, MIPSInst_FT(ir));
rv.s = (*handler.b) (fs, ft);
goto copcsr;
}
scopuop:
{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.s = (*handler.u) (fs);
goto copcsr;
}
copcsr:
if (ieee754_cxtest(IEEE754_INEXACT))
rcsr |= FPU_CSR_INE_X | FPU_CSR_INE_S;
if (ieee754_cxtest(IEEE754_UNDERFLOW))
rcsr |= FPU_CSR_UDF_X | FPU_CSR_UDF_S;
if (ieee754_cxtest(IEEE754_OVERFLOW))
rcsr |= FPU_CSR_OVF_X | FPU_CSR_OVF_S;
if (ieee754_cxtest(IEEE754_ZERO_DIVIDE))
rcsr |= FPU_CSR_DIV_X | FPU_CSR_DIV_S;
if (ieee754_cxtest(IEEE754_INVALID_OPERATION))
rcsr |= FPU_CSR_INV_X | FPU_CSR_INV_S;
break;
case fcvts_op:
return SIGILL;
case fcvtd_op:{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.d = ieee754dp_fsp(fs);
rfmt = d_fmt;
goto copcsr;
}
case fcvtw_op:{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.w = ieee754sp_tint(fs);
rfmt = w_fmt;
goto copcsr;
}
#if __mips >= 2 || defined(__mips64)
case fround_op:
case ftrunc_op:
case fceil_op:
case ffloor_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.w = ieee754sp_tint(fs);
ieee754_csr.rm = oldrm;
rfmt = w_fmt;
goto copcsr;
}
#endif
#if defined(__mips64)
case fcvtl_op:{
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
rv.l = ieee754sp_tlong(fs);
rfmt = l_fmt;
goto copcsr;
}
case froundl_op:
case ftruncl_op:
case fceill_op:
case ffloorl_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754sp fs;
SPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.l = ieee754sp_tlong(fs);
ieee754_csr.rm = oldrm;
rfmt = l_fmt;
goto copcsr;
}
#endif
default:
if (MIPSInst_FUNC(ir) >= fcmp_op) {
unsigned cmpop = MIPSInst_FUNC(ir) - fcmp_op;
ieee754sp fs, ft;
SPFROMREG(fs, MIPSInst_FS(ir));
SPFROMREG(ft, MIPSInst_FT(ir));
rv.w = ieee754sp_cmp(fs, ft,
cmptab[cmpop & 0x7], cmpop & 0x8);
rfmt = -1;
if ((cmpop & 0x8) && ieee754_cxtest
(IEEE754_INVALID_OPERATION))
rcsr = FPU_CSR_INV_X | FPU_CSR_INV_S;
else
goto copcsr;
}
else {
return SIGILL;
}
break;
}
break;
}
case d_fmt:{
union {
ieee754dp(*b) (ieee754dp, ieee754dp);
ieee754dp(*u) (ieee754dp);
} handler;
switch (MIPSInst_FUNC(ir)) {
case fadd_op:
handler.b = ieee754dp_add;
goto dcopbop;
case fsub_op:
handler.b = ieee754dp_sub;
goto dcopbop;
case fmul_op:
handler.b = ieee754dp_mul;
goto dcopbop;
case fdiv_op:
handler.b = ieee754dp_div;
goto dcopbop;
#if __mips >= 2 || defined(__mips64)
case fsqrt_op:
handler.u = ieee754dp_sqrt;
goto dcopuop;
#endif
#if __mips >= 4 && __mips != 32
case frsqrt_op:
handler.u = fpemu_dp_rsqrt;
goto dcopuop;
case frecip_op:
handler.u = fpemu_dp_recip;
goto dcopuop;
#endif
#if __mips >= 4
case fmovc_op:
cond = fpucondbit[MIPSInst_FT(ir) >> 2];
if (((ctx->fcr31 & cond) != 0) !=
((MIPSInst_FT(ir) & 1) != 0))
return 0;
DPFROMREG(rv.d, MIPSInst_FS(ir));
break;
case fmovz_op:
if (xcp->regs[MIPSInst_FT(ir)] != 0)
return 0;
DPFROMREG(rv.d, MIPSInst_FS(ir));
break;
case fmovn_op:
if (xcp->regs[MIPSInst_FT(ir)] == 0)
return 0;
DPFROMREG(rv.d, MIPSInst_FS(ir));
break;
#endif
case fabs_op:
handler.u = ieee754dp_abs;
goto dcopuop;
case fneg_op:
handler.u = ieee754dp_neg;
goto dcopuop;
case fmov_op:
DPFROMREG(rv.d, MIPSInst_FS(ir));
goto copcsr;
dcopbop:{
ieee754dp fs, ft;
DPFROMREG(fs, MIPSInst_FS(ir));
DPFROMREG(ft, MIPSInst_FT(ir));
rv.d = (*handler.b) (fs, ft);
goto copcsr;
}
dcopuop:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.d = (*handler.u) (fs);
goto copcsr;
}
case fcvts_op:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.s = ieee754sp_fdp(fs);
rfmt = s_fmt;
goto copcsr;
}
case fcvtd_op:
return SIGILL;
case fcvtw_op:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.w = ieee754dp_tint(fs);
rfmt = w_fmt;
goto copcsr;
}
#if __mips >= 2 || defined(__mips64)
case fround_op:
case ftrunc_op:
case fceil_op:
case ffloor_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.w = ieee754dp_tint(fs);
ieee754_csr.rm = oldrm;
rfmt = w_fmt;
goto copcsr;
}
#endif
#if defined(__mips64)
case fcvtl_op:{
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
rv.l = ieee754dp_tlong(fs);
rfmt = l_fmt;
goto copcsr;
}
case froundl_op:
case ftruncl_op:
case fceill_op:
case ffloorl_op:{
unsigned int oldrm = ieee754_csr.rm;
ieee754dp fs;
DPFROMREG(fs, MIPSInst_FS(ir));
ieee754_csr.rm = ieee_rm[modeindex(MIPSInst_FUNC(ir))];
rv.l = ieee754dp_tlong(fs);
ieee754_csr.rm = oldrm;
rfmt = l_fmt;
goto copcsr;
}
#endif
default:
if (MIPSInst_FUNC(ir) >= fcmp_op) {
unsigned cmpop = MIPSInst_FUNC(ir) - fcmp_op;
ieee754dp fs, ft;
DPFROMREG(fs, MIPSInst_FS(ir));
DPFROMREG(ft, MIPSInst_FT(ir));
rv.w = ieee754dp_cmp(fs, ft,
cmptab[cmpop & 0x7], cmpop & 0x8);
rfmt = -1;
if ((cmpop & 0x8)
&&
ieee754_cxtest
(IEEE754_INVALID_OPERATION))
rcsr = FPU_CSR_INV_X | FPU_CSR_INV_S;
else
goto copcsr;
}
else {
return SIGILL;
}
break;
}
break;
}
case w_fmt:{
ieee754sp fs;
switch (MIPSInst_FUNC(ir)) {
case fcvts_op:
SPFROMREG(fs, MIPSInst_FS(ir));
rv.s = ieee754sp_fint(fs.bits);
rfmt = s_fmt;
goto copcsr;
case fcvtd_op:
SPFROMREG(fs, MIPSInst_FS(ir));
rv.d = ieee754dp_fint(fs.bits);
rfmt = d_fmt;
goto copcsr;
default:
return SIGILL;
}
break;
}
#if defined(__mips64)
case l_fmt:{
switch (MIPSInst_FUNC(ir)) {
case fcvts_op:
rv.s = ieee754sp_flong(ctx->fpr[MIPSInst_FS(ir)]);
rfmt = s_fmt;
goto copcsr;
case fcvtd_op:
rv.d = ieee754dp_flong(ctx->fpr[MIPSInst_FS(ir)]);
rfmt = d_fmt;
goto copcsr;
default:
return SIGILL;
}
break;
}
#endif
default:
return SIGILL;
}
ctx->fcr31 = (ctx->fcr31 & ~FPU_CSR_ALL_X) | rcsr;
if ((ctx->fcr31 >> 5) & ctx->fcr31 & FPU_CSR_ALL_E) {
return SIGFPE;
}
switch (rfmt) {
case -1:{
#if __mips >= 4
cond = fpucondbit[MIPSInst_FD(ir) >> 2];
#else
cond = FPU_CSR_COND;
#endif
if (rv.w)
ctx->fcr31 |= cond;
else
ctx->fcr31 &= ~cond;
break;
}
case d_fmt:
DPTOREG(rv.d, MIPSInst_FD(ir));
break;
case s_fmt:
SPTOREG(rv.s, MIPSInst_FD(ir));
break;
case w_fmt:
SITOREG(rv.w, MIPSInst_FD(ir));
break;
#if defined(__mips64)
case l_fmt:
DITOREG(rv.l, MIPSInst_FD(ir));
break;
#endif
default:
return SIGILL;
}
return 0;
}
int fpu_emulator_cop1Handler(struct pt_regs *xcp, struct mips_fpu_struct *ctx,
int has_fpu, void *__user *fault_addr)
{
unsigned long oldepc, prevepc;
mips_instruction insn;
int sig = 0;
oldepc = xcp->cp0_epc;
do {
prevepc = xcp->cp0_epc;
if (!access_ok(VERIFY_READ, xcp->cp0_epc, sizeof(mips_instruction))) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)xcp->cp0_epc;
return SIGBUS;
}
if (__get_user(insn, (mips_instruction __user *) xcp->cp0_epc)) {
MIPS_FPU_EMU_INC_STATS(errors);
*fault_addr = (mips_instruction __user *)xcp->cp0_epc;
return SIGSEGV;
}
if (insn == 0)
xcp->cp0_epc += 4;
else {
ieee754_csr.rm = ieee_rm[ieee754_csr.rm];
sig = cop1Emulate(xcp, ctx, fault_addr);
ieee754_csr.rm = mips_rm[ieee754_csr.rm];
}
if (has_fpu)
break;
if (sig)
break;
cond_resched();
} while (xcp->cp0_epc > prevepc);
if (sig == SIGILL && xcp->cp0_epc != oldepc)
sig = 0;
return sig;
}
static int fpuemu_stat_get(void *data, u64 *val)
{
int cpu;
unsigned long sum = 0;
for_each_online_cpu(cpu) {
struct mips_fpu_emulator_stats *ps;
local_t *pv;
ps = &per_cpu(fpuemustats, cpu);
pv = (void *)ps + (unsigned long)data;
sum += local_read(pv);
}
*val = sum;
return 0;
}
static int __init debugfs_fpuemu(void)
{
struct dentry *d, *dir;
if (!mips_debugfs_dir)
return -ENODEV;
dir = debugfs_create_dir("fpuemustats", mips_debugfs_dir);
if (!dir)
return -ENOMEM;
#define FPU_STAT_CREATE(M) \
do { \
d = debugfs_create_file(#M , S_IRUGO, dir, \
(void *)offsetof(struct mips_fpu_emulator_stats, M), \
&fops_fpuemu_stat); \
if (!d) \
return -ENOMEM; \
} while (0)
FPU_STAT_CREATE(emulated);
FPU_STAT_CREATE(loads);
FPU_STAT_CREATE(stores);
FPU_STAT_CREATE(cp1ops);
FPU_STAT_CREATE(cp1xops);
FPU_STAT_CREATE(errors);
return 0;
}
