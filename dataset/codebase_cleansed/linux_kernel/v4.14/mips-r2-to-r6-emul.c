static int __init mipsr2emu_enable(char *s)
{
mipsr2_emulation = 1;
pr_info("MIPS R2-to-R6 Emulator Enabled!");
return 1;
}
static inline int mipsr6_emul(struct pt_regs *regs, u32 ir)
{
switch (MIPSInst_OPCODE(ir)) {
case addiu_op:
if (MIPSInst_RT(ir))
regs->regs[MIPSInst_RT(ir)] =
(s32)regs->regs[MIPSInst_RS(ir)] +
(s32)MIPSInst_SIMM(ir);
return 0;
case daddiu_op:
if (IS_ENABLED(CONFIG_32BIT))
break;
if (MIPSInst_RT(ir))
regs->regs[MIPSInst_RT(ir)] =
(s64)regs->regs[MIPSInst_RS(ir)] +
(s64)MIPSInst_SIMM(ir);
return 0;
case lwc1_op:
case swc1_op:
case cop1_op:
case cop1x_op:
return -SIGFPE;
case spec_op:
switch (MIPSInst_FUNC(ir)) {
case or_op:
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
regs->regs[MIPSInst_RS(ir)] |
regs->regs[MIPSInst_RT(ir)];
return 0;
case sll_op:
if (MIPSInst_RS(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(s32)(((u32)regs->regs[MIPSInst_RT(ir)]) <<
MIPSInst_FD(ir));
return 0;
case srl_op:
if (MIPSInst_RS(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(s32)(((u32)regs->regs[MIPSInst_RT(ir)]) >>
MIPSInst_FD(ir));
return 0;
case addu_op:
if (MIPSInst_FD(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(s32)((u32)regs->regs[MIPSInst_RS(ir)] +
(u32)regs->regs[MIPSInst_RT(ir)]);
return 0;
case subu_op:
if (MIPSInst_FD(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(s32)((u32)regs->regs[MIPSInst_RS(ir)] -
(u32)regs->regs[MIPSInst_RT(ir)]);
return 0;
case dsll_op:
if (IS_ENABLED(CONFIG_32BIT) || MIPSInst_RS(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(s64)(((u64)regs->regs[MIPSInst_RT(ir)]) <<
MIPSInst_FD(ir));
return 0;
case dsrl_op:
if (IS_ENABLED(CONFIG_32BIT) || MIPSInst_RS(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(s64)(((u64)regs->regs[MIPSInst_RT(ir)]) >>
MIPSInst_FD(ir));
return 0;
case daddu_op:
if (IS_ENABLED(CONFIG_32BIT) || MIPSInst_FD(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(u64)regs->regs[MIPSInst_RS(ir)] +
(u64)regs->regs[MIPSInst_RT(ir)];
return 0;
case dsubu_op:
if (IS_ENABLED(CONFIG_32BIT) || MIPSInst_FD(ir))
break;
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] =
(s64)((u64)regs->regs[MIPSInst_RS(ir)] -
(u64)regs->regs[MIPSInst_RT(ir)]);
return 0;
}
break;
default:
pr_debug("No fastpath BD emulation for instruction 0x%08x (op: %02x)\n",
ir, MIPSInst_OPCODE(ir));
}
return SIGILL;
}
static int movf_func(struct pt_regs *regs, u32 ir)
{
u32 csr;
u32 cond;
csr = current->thread.fpu.fcr31;
cond = fpucondbit[MIPSInst_RT(ir) >> 2];
if (((csr & cond) == 0) && MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] = regs->regs[MIPSInst_RS(ir)];
MIPS_R2_STATS(movs);
return 0;
}
static int movt_func(struct pt_regs *regs, u32 ir)
{
u32 csr;
u32 cond;
csr = current->thread.fpu.fcr31;
cond = fpucondbit[MIPSInst_RT(ir) >> 2];
if (((csr & cond) != 0) && MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] = regs->regs[MIPSInst_RS(ir)];
MIPS_R2_STATS(movs);
return 0;
}
static int jr_func(struct pt_regs *regs, u32 ir)
{
int err;
unsigned long cepc, epc, nepc;
u32 nir;
if (delay_slot(regs))
return SIGILL;
nepc = regs->cp0_epc;
regs->cp0_epc -= 4;
epc = regs->cp0_epc;
err = __compute_return_epc(regs);
if (err < 0)
return SIGEMT;
cepc = regs->cp0_epc;
err = __get_user(nir, (u32 __user *)nepc);
if (err)
return SIGSEGV;
MIPS_R2BR_STATS(jrs);
if (nir) {
err = mipsr6_emul(regs, nir);
if (err > 0) {
regs->cp0_epc = nepc;
err = mips_dsemul(regs, nir, epc, cepc);
if (err == SIGILL)
err = SIGEMT;
MIPS_R2_STATS(dsemul);
}
}
return err;
}
static int movz_func(struct pt_regs *regs, u32 ir)
{
if (((regs->regs[MIPSInst_RT(ir)]) == 0) && MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] = regs->regs[MIPSInst_RS(ir)];
MIPS_R2_STATS(movs);
return 0;
}
static int movn_func(struct pt_regs *regs, u32 ir)
{
if (((regs->regs[MIPSInst_RT(ir)]) != 0) && MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] = regs->regs[MIPSInst_RS(ir)];
MIPS_R2_STATS(movs);
return 0;
}
static int mfhi_func(struct pt_regs *regs, u32 ir)
{
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] = regs->hi;
MIPS_R2_STATS(hilo);
return 0;
}
static int mthi_func(struct pt_regs *regs, u32 ir)
{
regs->hi = regs->regs[MIPSInst_RS(ir)];
MIPS_R2_STATS(hilo);
return 0;
}
static int mflo_func(struct pt_regs *regs, u32 ir)
{
if (MIPSInst_RD(ir))
regs->regs[MIPSInst_RD(ir)] = regs->lo;
MIPS_R2_STATS(hilo);
return 0;
}
static int mtlo_func(struct pt_regs *regs, u32 ir)
{
regs->lo = regs->regs[MIPSInst_RS(ir)];
MIPS_R2_STATS(hilo);
return 0;
}
static int mult_func(struct pt_regs *regs, u32 ir)
{
s64 res;
s32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = (s64)rt * (s64)rs;
rs = res;
regs->lo = (s64)rs;
rt = res >> 32;
res = (s64)rt;
regs->hi = res;
MIPS_R2_STATS(muls);
return 0;
}
static int multu_func(struct pt_regs *regs, u32 ir)
{
u64 res;
u32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = (u64)rt * (u64)rs;
rt = res;
regs->lo = (s64)(s32)rt;
regs->hi = (s64)(s32)(res >> 32);
MIPS_R2_STATS(muls);
return 0;
}
static int div_func(struct pt_regs *regs, u32 ir)
{
s32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
regs->lo = (s64)(rs / rt);
regs->hi = (s64)(rs % rt);
MIPS_R2_STATS(divs);
return 0;
}
static int divu_func(struct pt_regs *regs, u32 ir)
{
u32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
regs->lo = (s64)(rs / rt);
regs->hi = (s64)(rs % rt);
MIPS_R2_STATS(divs);
return 0;
}
static int dmult_func(struct pt_regs *regs, u32 ir)
{
s64 res;
s64 rt, rs;
if (IS_ENABLED(CONFIG_32BIT))
return SIGILL;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = rt * rs;
regs->lo = res;
__asm__ __volatile__(
"dmuh %0, %1, %2\t\n"
: "=r"(res)
: "r"(rt), "r"(rs));
regs->hi = res;
MIPS_R2_STATS(muls);
return 0;
}
static int dmultu_func(struct pt_regs *regs, u32 ir)
{
u64 res;
u64 rt, rs;
if (IS_ENABLED(CONFIG_32BIT))
return SIGILL;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = rt * rs;
regs->lo = res;
__asm__ __volatile__(
"dmuhu %0, %1, %2\t\n"
: "=r"(res)
: "r"(rt), "r"(rs));
regs->hi = res;
MIPS_R2_STATS(muls);
return 0;
}
static int ddiv_func(struct pt_regs *regs, u32 ir)
{
s64 rt, rs;
if (IS_ENABLED(CONFIG_32BIT))
return SIGILL;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
regs->lo = rs / rt;
regs->hi = rs % rt;
MIPS_R2_STATS(divs);
return 0;
}
static int ddivu_func(struct pt_regs *regs, u32 ir)
{
u64 rt, rs;
if (IS_ENABLED(CONFIG_32BIT))
return SIGILL;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
regs->lo = rs / rt;
regs->hi = rs % rt;
MIPS_R2_STATS(divs);
return 0;
}
static int madd_func(struct pt_regs *regs, u32 ir)
{
s64 res;
s32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = (s64)rt * (s64)rs;
rt = regs->hi;
rs = regs->lo;
res += ((((s64)rt) << 32) | (u32)rs);
rt = res;
regs->lo = (s64)rt;
rs = res >> 32;
regs->hi = (s64)rs;
MIPS_R2_STATS(dsps);
return 0;
}
static int maddu_func(struct pt_regs *regs, u32 ir)
{
u64 res;
u32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = (u64)rt * (u64)rs;
rt = regs->hi;
rs = regs->lo;
res += ((((s64)rt) << 32) | (u32)rs);
rt = res;
regs->lo = (s64)(s32)rt;
rs = res >> 32;
regs->hi = (s64)(s32)rs;
MIPS_R2_STATS(dsps);
return 0;
}
static int msub_func(struct pt_regs *regs, u32 ir)
{
s64 res;
s32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = (s64)rt * (s64)rs;
rt = regs->hi;
rs = regs->lo;
res = ((((s64)rt) << 32) | (u32)rs) - res;
rt = res;
regs->lo = (s64)rt;
rs = res >> 32;
regs->hi = (s64)rs;
MIPS_R2_STATS(dsps);
return 0;
}
static int msubu_func(struct pt_regs *regs, u32 ir)
{
u64 res;
u32 rt, rs;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = (u64)rt * (u64)rs;
rt = regs->hi;
rs = regs->lo;
res = ((((s64)rt) << 32) | (u32)rs) - res;
rt = res;
regs->lo = (s64)(s32)rt;
rs = res >> 32;
regs->hi = (s64)(s32)rs;
MIPS_R2_STATS(dsps);
return 0;
}
static int mul_func(struct pt_regs *regs, u32 ir)
{
s64 res;
s32 rt, rs;
if (!MIPSInst_RD(ir))
return 0;
rt = regs->regs[MIPSInst_RT(ir)];
rs = regs->regs[MIPSInst_RS(ir)];
res = (s64)rt * (s64)rs;
rs = res;
regs->regs[MIPSInst_RD(ir)] = (s64)rs;
MIPS_R2_STATS(muls);
return 0;
}
static int clz_func(struct pt_regs *regs, u32 ir)
{
u32 res;
u32 rs;
if (!MIPSInst_RD(ir))
return 0;
rs = regs->regs[MIPSInst_RS(ir)];
__asm__ __volatile__("clz %0, %1" : "=r"(res) : "r"(rs));
regs->regs[MIPSInst_RD(ir)] = res;
MIPS_R2_STATS(bops);
return 0;
}
static int clo_func(struct pt_regs *regs, u32 ir)
{
u32 res;
u32 rs;
if (!MIPSInst_RD(ir))
return 0;
rs = regs->regs[MIPSInst_RS(ir)];
__asm__ __volatile__("clo %0, %1" : "=r"(res) : "r"(rs));
regs->regs[MIPSInst_RD(ir)] = res;
MIPS_R2_STATS(bops);
return 0;
}
static int dclz_func(struct pt_regs *regs, u32 ir)
{
u64 res;
u64 rs;
if (IS_ENABLED(CONFIG_32BIT))
return SIGILL;
if (!MIPSInst_RD(ir))
return 0;
rs = regs->regs[MIPSInst_RS(ir)];
__asm__ __volatile__("dclz %0, %1" : "=r"(res) : "r"(rs));
regs->regs[MIPSInst_RD(ir)] = res;
MIPS_R2_STATS(bops);
return 0;
}
static int dclo_func(struct pt_regs *regs, u32 ir)
{
u64 res;
u64 rs;
if (IS_ENABLED(CONFIG_32BIT))
return SIGILL;
if (!MIPSInst_RD(ir))
return 0;
rs = regs->regs[MIPSInst_RS(ir)];
__asm__ __volatile__("dclo %0, %1" : "=r"(res) : "r"(rs));
regs->regs[MIPSInst_RD(ir)] = res;
MIPS_R2_STATS(bops);
return 0;
}
static inline int mipsr2_find_op_func(struct pt_regs *regs, u32 inst,
const struct r2_decoder_table *table)
{
const struct r2_decoder_table *p;
int err;
for (p = table; p->func; p++) {
if ((inst & p->mask) == p->code) {
err = (p->func)(regs, inst);
return err;
}
}
return SIGILL;
}
int mipsr2_decoder(struct pt_regs *regs, u32 inst, unsigned long *fcr31)
{
int err = 0;
unsigned long vaddr;
u32 nir;
unsigned long cpc, epc, nepc, r31, res, rs, rt;
void __user *fault_addr = NULL;
int pass = 0;
repeat:
r31 = regs->regs[31];
epc = regs->cp0_epc;
err = compute_return_epc(regs);
if (err < 0) {
BUG();
return SIGEMT;
}
pr_debug("Emulating the 0x%08x R2 instruction @ 0x%08lx (pass=%d))\n",
inst, epc, pass);
switch (MIPSInst_OPCODE(inst)) {
case spec_op:
err = mipsr2_find_op_func(regs, inst, spec_op_table);
if (err < 0) {
regs->cp0_cause |= CAUSEF_BD;
goto fpu_emul;
}
break;
case spec2_op:
err = mipsr2_find_op_func(regs, inst, spec2_op_table);
break;
case bcond_op:
rt = MIPSInst_RT(inst);
rs = MIPSInst_RS(inst);
switch (rt) {
case tgei_op:
if ((long)regs->regs[rs] >= MIPSInst_SIMM(inst))
do_trap_or_bp(regs, 0, 0, "TGEI");
MIPS_R2_STATS(traps);
break;
case tgeiu_op:
if (regs->regs[rs] >= MIPSInst_UIMM(inst))
do_trap_or_bp(regs, 0, 0, "TGEIU");
MIPS_R2_STATS(traps);
break;
case tlti_op:
if ((long)regs->regs[rs] < MIPSInst_SIMM(inst))
do_trap_or_bp(regs, 0, 0, "TLTI");
MIPS_R2_STATS(traps);
break;
case tltiu_op:
if (regs->regs[rs] < MIPSInst_UIMM(inst))
do_trap_or_bp(regs, 0, 0, "TLTIU");
MIPS_R2_STATS(traps);
break;
case teqi_op:
if (regs->regs[rs] == MIPSInst_SIMM(inst))
do_trap_or_bp(regs, 0, 0, "TEQI");
MIPS_R2_STATS(traps);
break;
case tnei_op:
if (regs->regs[rs] != MIPSInst_SIMM(inst))
do_trap_or_bp(regs, 0, 0, "TNEI");
MIPS_R2_STATS(traps);
break;
case bltzl_op:
case bgezl_op:
case bltzall_op:
case bgezall_op:
if (delay_slot(regs)) {
err = SIGILL;
break;
}
regs->regs[31] = r31;
regs->cp0_epc = epc;
err = __compute_return_epc(regs);
if (err < 0)
return SIGEMT;
if (err != BRANCH_LIKELY_TAKEN)
break;
cpc = regs->cp0_epc;
nepc = epc + 4;
err = __get_user(nir, (u32 __user *)nepc);
if (err) {
err = SIGSEGV;
break;
}
switch (rt) {
case bltzl_op:
MIPS_R2BR_STATS(bltzl);
break;
case bgezl_op:
MIPS_R2BR_STATS(bgezl);
break;
case bltzall_op:
MIPS_R2BR_STATS(bltzall);
break;
case bgezall_op:
MIPS_R2BR_STATS(bgezall);
break;
}
switch (MIPSInst_OPCODE(nir)) {
case cop1_op:
case cop1x_op:
case lwc1_op:
case swc1_op:
regs->cp0_cause |= CAUSEF_BD;
goto fpu_emul;
}
if (nir) {
err = mipsr6_emul(regs, nir);
if (err > 0) {
err = mips_dsemul(regs, nir, epc, cpc);
if (err == SIGILL)
err = SIGEMT;
MIPS_R2_STATS(dsemul);
}
}
break;
case bltzal_op:
case bgezal_op:
if (delay_slot(regs)) {
err = SIGILL;
break;
}
regs->regs[31] = r31;
regs->cp0_epc = epc;
err = __compute_return_epc(regs);
if (err < 0)
return SIGEMT;
cpc = regs->cp0_epc;
nepc = epc + 4;
err = __get_user(nir, (u32 __user *)nepc);
if (err) {
err = SIGSEGV;
break;
}
switch (rt) {
case bltzal_op:
MIPS_R2BR_STATS(bltzal);
break;
case bgezal_op:
MIPS_R2BR_STATS(bgezal);
break;
}
switch (MIPSInst_OPCODE(nir)) {
case cop1_op:
case cop1x_op:
case lwc1_op:
case swc1_op:
regs->cp0_cause |= CAUSEF_BD;
goto fpu_emul;
}
if (nir) {
err = mipsr6_emul(regs, nir);
if (err > 0) {
err = mips_dsemul(regs, nir, epc, cpc);
if (err == SIGILL)
err = SIGEMT;
MIPS_R2_STATS(dsemul);
}
}
break;
default:
regs->regs[31] = r31;
regs->cp0_epc = epc;
err = SIGILL;
break;
}
break;
case blezl_op:
case bgtzl_op:
if (MIPSInst_RT(inst)) {
err = SIGILL;
break;
}
case beql_op:
case bnel_op:
if (delay_slot(regs)) {
err = SIGILL;
break;
}
regs->regs[31] = r31;
regs->cp0_epc = epc;
err = __compute_return_epc(regs);
if (err < 0)
return SIGEMT;
if (err != BRANCH_LIKELY_TAKEN)
break;
cpc = regs->cp0_epc;
nepc = epc + 4;
err = __get_user(nir, (u32 __user *)nepc);
if (err) {
err = SIGSEGV;
break;
}
switch (MIPSInst_OPCODE(inst)) {
case beql_op:
MIPS_R2BR_STATS(beql);
break;
case bnel_op:
MIPS_R2BR_STATS(bnel);
break;
case blezl_op:
MIPS_R2BR_STATS(blezl);
break;
case bgtzl_op:
MIPS_R2BR_STATS(bgtzl);
break;
}
switch (MIPSInst_OPCODE(nir)) {
case cop1_op:
case cop1x_op:
case lwc1_op:
case swc1_op:
regs->cp0_cause |= CAUSEF_BD;
goto fpu_emul;
}
if (nir) {
err = mipsr6_emul(regs, nir);
if (err > 0) {
err = mips_dsemul(regs, nir, epc, cpc);
if (err == SIGILL)
err = SIGEMT;
MIPS_R2_STATS(dsemul);
}
}
break;
case lwc1_op:
case swc1_op:
case cop1_op:
case cop1x_op:
fpu_emul:
regs->regs[31] = r31;
regs->cp0_epc = epc;
if (!used_math()) {
preempt_disable();
err = init_fpu();
preempt_enable();
set_used_math();
}
lose_fpu(1);
err = fpu_emulator_cop1Handler(regs, &current->thread.fpu, 0,
&fault_addr);
*fcr31 = res = mask_fcr31_x(current->thread.fpu.fcr31);
current->thread.fpu.fcr31 &= ~res;
own_fpu(1);
if (err)
current->thread.cp0_baduaddr = (unsigned long)fault_addr;
MIPS_R2_STATS(fpus);
break;
case lwl_op:
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_READ, (void __user *)vaddr, 4)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
#else
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
#endif
"9: sll %0, %0, 0\n"
"10:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 10b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = rt;
MIPS_R2_STATS(loads);
break;
case lwr_op:
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_READ, (void __user *)vaddr, 4)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
" sll %0, %0, 0\n"
#else
"1:" LB "%1, 0(%2)\n"
INS "%0, %1, 0, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"2:" LB "%1, 0(%2)\n"
INS "%0, %1, 8, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"3:" LB "%1, 0(%2)\n"
INS "%0, %1, 16, 8\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
"4:" LB "%1, 0(%2)\n"
INS "%0, %1, 24, 8\n"
" sll %0, %0, 0\n"
#endif
"9:\n"
"10:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 10b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = rt;
MIPS_R2_STATS(loads);
break;
case swl_op:
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr, 4)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
EXT "%1, %0, 24, 8\n"
"1:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 16, 8\n"
"2:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 8, 8\n"
"3:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 0, 8\n"
"4:" SB "%1, 0(%2)\n"
#else
EXT "%1, %0, 24, 8\n"
"1:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 16, 8\n"
"2:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 8, 8\n"
"3:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 0, 8\n"
"4:" SB "%1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
MIPS_R2_STATS(stores);
break;
case swr_op:
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr, 4)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
EXT "%1, %0, 0, 8\n"
"1:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 8, 8\n"
"2:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 16, 8\n"
"3:" SB "%1, 0(%2)\n"
ADDIU "%2, %2, 1\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
EXT "%1, %0, 24, 8\n"
"4:" SB "%1, 0(%2)\n"
#else
EXT "%1, %0, 0, 8\n"
"1:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 8, 8\n"
"2:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 16, 8\n"
"3:" SB "%1, 0(%2)\n"
" andi %1, %2, 0x3\n"
" beq $0, %1, 9f\n"
ADDIU "%2, %2, -1\n"
EXT "%1, %0, 24, 8\n"
"4:" SB "%1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
MIPS_R2_STATS(stores);
break;
case ldl_op:
if (IS_ENABLED(CONFIG_32BIT)) {
err = SIGILL;
break;
}
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_READ, (void __user *)vaddr, 8)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
"1: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"2: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"3: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"4: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"5: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"6: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"7: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"0: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
#else
"1: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"2: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"3: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"4: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"5: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"6: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"7: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"0: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = rt;
MIPS_R2_STATS(loads);
break;
case ldr_op:
if (IS_ENABLED(CONFIG_32BIT)) {
err = SIGILL;
break;
}
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_READ, (void __user *)vaddr, 8)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
"1: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"2: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"3: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"4: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"5: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"6: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"7: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
"0: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
#else
"1: lb %1, 0(%2)\n"
" dins %0, %1, 0, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"2: lb %1, 0(%2)\n"
" dins %0, %1, 8, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"3: lb %1, 0(%2)\n"
" dins %0, %1, 16, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"4: lb %1, 0(%2)\n"
" dins %0, %1, 24, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"5: lb %1, 0(%2)\n"
" dinsu %0, %1, 32, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"6: lb %1, 0(%2)\n"
" dinsu %0, %1, 40, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"7: lb %1, 0(%2)\n"
" dinsu %0, %1, 48, 8\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
"0: lb %1, 0(%2)\n"
" dinsu %0, %1, 56, 8\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV));
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = rt;
MIPS_R2_STATS(loads);
break;
case sdl_op:
if (IS_ENABLED(CONFIG_32BIT)) {
err = SIGILL;
break;
}
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr, 8)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
" dextu %1, %0, 56, 8\n"
"1: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 48, 8\n"
"2: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 40, 8\n"
"3: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 32, 8\n"
"4: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 24, 8\n"
"5: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 16, 8\n"
"6: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 8, 8\n"
"7: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 0, 8\n"
"0: sb %1, 0(%2)\n"
#else
" dextu %1, %0, 56, 8\n"
"1: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 48, 8\n"
"2: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 40, 8\n"
"3: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 32, 8\n"
"4: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 24, 8\n"
"5: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 16, 8\n"
"6: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 8, 8\n"
"7: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 0, 8\n"
"0: sb %1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
MIPS_R2_STATS(stores);
break;
case sdr_op:
if (IS_ENABLED(CONFIG_32BIT)) {
err = SIGILL;
break;
}
rt = regs->regs[MIPSInst_RT(inst)];
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr, 8)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGSEGV;
break;
}
__asm__ __volatile__(
" .set push\n"
" .set reorder\n"
#ifdef CONFIG_CPU_LITTLE_ENDIAN
" dext %1, %0, 0, 8\n"
"1: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 8, 8\n"
"2: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 16, 8\n"
"3: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dext %1, %0, 24, 8\n"
"4: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 32, 8\n"
"5: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 40, 8\n"
"6: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 48, 8\n"
"7: sb %1, 0(%2)\n"
" daddiu %2, %2, 1\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" dextu %1, %0, 56, 8\n"
"0: sb %1, 0(%2)\n"
#else
" dext %1, %0, 0, 8\n"
"1: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 8, 8\n"
"2: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 16, 8\n"
"3: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dext %1, %0, 24, 8\n"
"4: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 32, 8\n"
"5: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 40, 8\n"
"6: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 48, 8\n"
"7: sb %1, 0(%2)\n"
" andi %1, %2, 0x7\n"
" beq $0, %1, 9f\n"
" daddiu %2, %2, -1\n"
" dextu %1, %0, 56, 8\n"
"0: sb %1, 0(%2)\n"
#endif
"9:\n"
" .insn\n"
" .section .fixup,\"ax\"\n"
"8: li %3,%4\n"
" j 9b\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
STR(PTR) " 1b,8b\n"
STR(PTR) " 2b,8b\n"
STR(PTR) " 3b,8b\n"
STR(PTR) " 4b,8b\n"
STR(PTR) " 5b,8b\n"
STR(PTR) " 6b,8b\n"
STR(PTR) " 7b,8b\n"
STR(PTR) " 0b,8b\n"
" .previous\n"
" .set pop\n"
: "+&r"(rt), "=&r"(rs),
"+&r"(vaddr), "+&r"(err)
: "i"(SIGSEGV)
: "memory");
MIPS_R2_STATS(stores);
break;
case ll_op:
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (vaddr & 0x3) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!access_ok(VERIFY_READ, (void __user *)vaddr, 4)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!cpu_has_rw_llb) {
pr_err("Can't emulate MIPSR2 LL/SC without Config5/LLB\n");
err = SIGKILL;
break;
}
__asm__ __volatile__(
"1:\n"
"ll %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "=&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV)
: "memory");
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = res;
MIPS_R2_STATS(llsc);
break;
case sc_op:
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (vaddr & 0x3) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr, 4)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!cpu_has_rw_llb) {
pr_err("Can't emulate MIPSR2 LL/SC without Config5/LLB\n");
err = SIGKILL;
break;
}
res = regs->regs[MIPSInst_RT(inst)];
__asm__ __volatile__(
"1:\n"
"sc %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "+&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV));
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = res;
MIPS_R2_STATS(llsc);
break;
case lld_op:
if (IS_ENABLED(CONFIG_32BIT)) {
err = SIGILL;
break;
}
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (vaddr & 0x7) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!access_ok(VERIFY_READ, (void __user *)vaddr, 8)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!cpu_has_rw_llb) {
pr_err("Can't emulate MIPSR2 LL/SC without Config5/LLB\n");
err = SIGKILL;
break;
}
__asm__ __volatile__(
"1:\n"
"lld %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "=&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV)
: "memory");
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = res;
MIPS_R2_STATS(llsc);
break;
case scd_op:
if (IS_ENABLED(CONFIG_32BIT)) {
err = SIGILL;
break;
}
vaddr = regs->regs[MIPSInst_RS(inst)] + MIPSInst_SIMM(inst);
if (vaddr & 0x7) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!access_ok(VERIFY_WRITE, (void __user *)vaddr, 8)) {
current->thread.cp0_baduaddr = vaddr;
err = SIGBUS;
break;
}
if (!cpu_has_rw_llb) {
pr_err("Can't emulate MIPSR2 LL/SC without Config5/LLB\n");
err = SIGKILL;
break;
}
res = regs->regs[MIPSInst_RT(inst)];
__asm__ __volatile__(
"1:\n"
"scd %0, 0(%2)\n"
"2:\n"
".insn\n"
".section .fixup,\"ax\"\n"
"3:\n"
"li %1, %3\n"
"j 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
STR(PTR) " 1b,3b\n"
".previous\n"
: "+&r"(res), "+&r"(err)
: "r"(vaddr), "i"(SIGSEGV));
if (MIPSInst_RT(inst) && !err)
regs->regs[MIPSInst_RT(inst)] = res;
MIPS_R2_STATS(llsc);
break;
case pref_op:
break;
default:
err = SIGILL;
}
if (!err && (pass++ < MIPS_R2_EMUL_TOTAL_PASS)) {
regs->cp0_cause &= ~CAUSEF_BD;
err = get_user(inst, (u32 __user *)regs->cp0_epc);
if (!err)
goto repeat;
if (err < 0)
err = SIGSEGV;
}
if (err && (err != SIGEMT)) {
regs->regs[31] = r31;
regs->cp0_epc = epc;
}
if (pass && (err == SIGILL))
err = 0;
return err;
}
static int mipsr2_stats_show(struct seq_file *s, void *unused)
{
seq_printf(s, "Instruction\tTotal\tBDslot\n------------------------------\n");
seq_printf(s, "movs\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.movs),
(unsigned long)__this_cpu_read(mipsr2bdemustats.movs));
seq_printf(s, "hilo\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.hilo),
(unsigned long)__this_cpu_read(mipsr2bdemustats.hilo));
seq_printf(s, "muls\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.muls),
(unsigned long)__this_cpu_read(mipsr2bdemustats.muls));
seq_printf(s, "divs\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.divs),
(unsigned long)__this_cpu_read(mipsr2bdemustats.divs));
seq_printf(s, "dsps\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.dsps),
(unsigned long)__this_cpu_read(mipsr2bdemustats.dsps));
seq_printf(s, "bops\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.bops),
(unsigned long)__this_cpu_read(mipsr2bdemustats.bops));
seq_printf(s, "traps\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.traps),
(unsigned long)__this_cpu_read(mipsr2bdemustats.traps));
seq_printf(s, "fpus\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.fpus),
(unsigned long)__this_cpu_read(mipsr2bdemustats.fpus));
seq_printf(s, "loads\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.loads),
(unsigned long)__this_cpu_read(mipsr2bdemustats.loads));
seq_printf(s, "stores\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.stores),
(unsigned long)__this_cpu_read(mipsr2bdemustats.stores));
seq_printf(s, "llsc\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.llsc),
(unsigned long)__this_cpu_read(mipsr2bdemustats.llsc));
seq_printf(s, "dsemul\t\t%ld\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2emustats.dsemul),
(unsigned long)__this_cpu_read(mipsr2bdemustats.dsemul));
seq_printf(s, "jr\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.jrs));
seq_printf(s, "bltzl\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bltzl));
seq_printf(s, "bgezl\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bgezl));
seq_printf(s, "bltzll\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bltzll));
seq_printf(s, "bgezll\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bgezll));
seq_printf(s, "bltzal\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bltzal));
seq_printf(s, "bgezal\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bgezal));
seq_printf(s, "beql\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.beql));
seq_printf(s, "bnel\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bnel));
seq_printf(s, "blezl\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.blezl));
seq_printf(s, "bgtzl\t\t%ld\n",
(unsigned long)__this_cpu_read(mipsr2bremustats.bgtzl));
return 0;
}
static int mipsr2_stats_clear_show(struct seq_file *s, void *unused)
{
mipsr2_stats_show(s, unused);
__this_cpu_write((mipsr2emustats).movs, 0);
__this_cpu_write((mipsr2bdemustats).movs, 0);
__this_cpu_write((mipsr2emustats).hilo, 0);
__this_cpu_write((mipsr2bdemustats).hilo, 0);
__this_cpu_write((mipsr2emustats).muls, 0);
__this_cpu_write((mipsr2bdemustats).muls, 0);
__this_cpu_write((mipsr2emustats).divs, 0);
__this_cpu_write((mipsr2bdemustats).divs, 0);
__this_cpu_write((mipsr2emustats).dsps, 0);
__this_cpu_write((mipsr2bdemustats).dsps, 0);
__this_cpu_write((mipsr2emustats).bops, 0);
__this_cpu_write((mipsr2bdemustats).bops, 0);
__this_cpu_write((mipsr2emustats).traps, 0);
__this_cpu_write((mipsr2bdemustats).traps, 0);
__this_cpu_write((mipsr2emustats).fpus, 0);
__this_cpu_write((mipsr2bdemustats).fpus, 0);
__this_cpu_write((mipsr2emustats).loads, 0);
__this_cpu_write((mipsr2bdemustats).loads, 0);
__this_cpu_write((mipsr2emustats).stores, 0);
__this_cpu_write((mipsr2bdemustats).stores, 0);
__this_cpu_write((mipsr2emustats).llsc, 0);
__this_cpu_write((mipsr2bdemustats).llsc, 0);
__this_cpu_write((mipsr2emustats).dsemul, 0);
__this_cpu_write((mipsr2bdemustats).dsemul, 0);
__this_cpu_write((mipsr2bremustats).jrs, 0);
__this_cpu_write((mipsr2bremustats).bltzl, 0);
__this_cpu_write((mipsr2bremustats).bgezl, 0);
__this_cpu_write((mipsr2bremustats).bltzll, 0);
__this_cpu_write((mipsr2bremustats).bgezll, 0);
__this_cpu_write((mipsr2bremustats).bltzall, 0);
__this_cpu_write((mipsr2bremustats).bgezall, 0);
__this_cpu_write((mipsr2bremustats).bltzal, 0);
__this_cpu_write((mipsr2bremustats).bgezal, 0);
__this_cpu_write((mipsr2bremustats).beql, 0);
__this_cpu_write((mipsr2bremustats).bnel, 0);
__this_cpu_write((mipsr2bremustats).blezl, 0);
__this_cpu_write((mipsr2bremustats).bgtzl, 0);
return 0;
}
static int mipsr2_stats_open(struct inode *inode, struct file *file)
{
return single_open(file, mipsr2_stats_show, inode->i_private);
}
static int mipsr2_stats_clear_open(struct inode *inode, struct file *file)
{
return single_open(file, mipsr2_stats_clear_show, inode->i_private);
}
static int __init mipsr2_init_debugfs(void)
{
struct dentry *mipsr2_emul;
if (!mips_debugfs_dir)
return -ENODEV;
mipsr2_emul = debugfs_create_file("r2_emul_stats", S_IRUGO,
mips_debugfs_dir, NULL,
&mipsr2_emul_fops);
if (!mipsr2_emul)
return -ENOMEM;
mipsr2_emul = debugfs_create_file("r2_emul_stats_clear", S_IRUGO,
mips_debugfs_dir, NULL,
&mipsr2_clear_fops);
if (!mipsr2_emul)
return -ENOMEM;
return 0;
}
