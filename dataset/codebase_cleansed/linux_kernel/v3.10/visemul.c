static inline void maybe_flush_windows(unsigned int rs1, unsigned int rs2,
unsigned int rd, int from_kernel)
{
if (rs2 >= 16 || rs1 >= 16 || rd >= 16) {
if (from_kernel != 0)
__asm__ __volatile__("flushw");
else
flushw_user();
}
}
static unsigned long fetch_reg(unsigned int reg, struct pt_regs *regs)
{
unsigned long value, fp;
if (reg < 16)
return (!reg ? 0 : regs->u_regs[reg]);
fp = regs->u_regs[UREG_FP];
if (regs->tstate & TSTATE_PRIV) {
struct reg_window *win;
win = (struct reg_window *)(fp + STACK_BIAS);
value = win->locals[reg - 16];
} else if (!test_thread_64bit_stack(fp)) {
struct reg_window32 __user *win32;
win32 = (struct reg_window32 __user *)((unsigned long)((u32)fp));
get_user(value, &win32->locals[reg - 16]);
} else {
struct reg_window __user *win;
win = (struct reg_window __user *)(fp + STACK_BIAS);
get_user(value, &win->locals[reg - 16]);
}
return value;
}
static inline unsigned long __user *__fetch_reg_addr_user(unsigned int reg,
struct pt_regs *regs)
{
unsigned long fp = regs->u_regs[UREG_FP];
BUG_ON(reg < 16);
BUG_ON(regs->tstate & TSTATE_PRIV);
if (!test_thread_64bit_stack(fp)) {
struct reg_window32 __user *win32;
win32 = (struct reg_window32 __user *)((unsigned long)((u32)fp));
return (unsigned long __user *)&win32->locals[reg - 16];
} else {
struct reg_window __user *win;
win = (struct reg_window __user *)(fp + STACK_BIAS);
return &win->locals[reg - 16];
}
}
static inline unsigned long *__fetch_reg_addr_kern(unsigned int reg,
struct pt_regs *regs)
{
BUG_ON(reg >= 16);
BUG_ON(regs->tstate & TSTATE_PRIV);
return &regs->u_regs[reg];
}
static void store_reg(struct pt_regs *regs, unsigned long val, unsigned long rd)
{
if (rd < 16) {
unsigned long *rd_kern = __fetch_reg_addr_kern(rd, regs);
*rd_kern = val;
} else {
unsigned long __user *rd_user = __fetch_reg_addr_user(rd, regs);
if (!test_thread_64bit_stack(regs->u_regs[UREG_FP]))
__put_user((u32)val, (u32 __user *)rd_user);
else
__put_user(val, rd_user);
}
}
static inline unsigned long fpd_regval(struct fpustate *f,
unsigned int insn_regnum)
{
insn_regnum = (((insn_regnum & 1) << 5) |
(insn_regnum & 0x1e));
return *(unsigned long *) &f->regs[insn_regnum];
}
static inline unsigned long *fpd_regaddr(struct fpustate *f,
unsigned int insn_regnum)
{
insn_regnum = (((insn_regnum & 1) << 5) |
(insn_regnum & 0x1e));
return (unsigned long *) &f->regs[insn_regnum];
}
static inline unsigned int fps_regval(struct fpustate *f,
unsigned int insn_regnum)
{
return f->regs[insn_regnum];
}
static inline unsigned int *fps_regaddr(struct fpustate *f,
unsigned int insn_regnum)
{
return &f->regs[insn_regnum];
}
static void edge(struct pt_regs *regs, unsigned int insn, unsigned int opf)
{
unsigned long orig_rs1, rs1, orig_rs2, rs2, rd_val;
u16 left, right;
maybe_flush_windows(RS1(insn), RS2(insn), RD(insn), 0);
orig_rs1 = rs1 = fetch_reg(RS1(insn), regs);
orig_rs2 = rs2 = fetch_reg(RS2(insn), regs);
if (test_thread_flag(TIF_32BIT)) {
rs1 = rs1 & 0xffffffff;
rs2 = rs2 & 0xffffffff;
}
switch (opf) {
default:
case EDGE8_OPF:
case EDGE8N_OPF:
left = edge8_tab[rs1 & 0x7].left;
right = edge8_tab[rs2 & 0x7].right;
break;
case EDGE8L_OPF:
case EDGE8LN_OPF:
left = edge8_tab_l[rs1 & 0x7].left;
right = edge8_tab_l[rs2 & 0x7].right;
break;
case EDGE16_OPF:
case EDGE16N_OPF:
left = edge16_tab[(rs1 >> 1) & 0x3].left;
right = edge16_tab[(rs2 >> 1) & 0x3].right;
break;
case EDGE16L_OPF:
case EDGE16LN_OPF:
left = edge16_tab_l[(rs1 >> 1) & 0x3].left;
right = edge16_tab_l[(rs2 >> 1) & 0x3].right;
break;
case EDGE32_OPF:
case EDGE32N_OPF:
left = edge32_tab[(rs1 >> 2) & 0x1].left;
right = edge32_tab[(rs2 >> 2) & 0x1].right;
break;
case EDGE32L_OPF:
case EDGE32LN_OPF:
left = edge32_tab_l[(rs1 >> 2) & 0x1].left;
right = edge32_tab_l[(rs2 >> 2) & 0x1].right;
break;
}
if ((rs1 & ~0x7UL) == (rs2 & ~0x7UL))
rd_val = right & left;
else
rd_val = left;
store_reg(regs, rd_val, RD(insn));
switch (opf) {
case EDGE8_OPF:
case EDGE8L_OPF:
case EDGE16_OPF:
case EDGE16L_OPF:
case EDGE32_OPF:
case EDGE32L_OPF: {
unsigned long ccr, tstate;
__asm__ __volatile__("subcc %1, %2, %%g0\n\t"
"rd %%ccr, %0"
: "=r" (ccr)
: "r" (orig_rs1), "r" (orig_rs2)
: "cc");
tstate = regs->tstate & ~(TSTATE_XCC | TSTATE_ICC);
regs->tstate = tstate | (ccr << 32UL);
}
}
}
static void array(struct pt_regs *regs, unsigned int insn, unsigned int opf)
{
unsigned long rs1, rs2, rd_val;
unsigned int bits, bits_mask;
maybe_flush_windows(RS1(insn), RS2(insn), RD(insn), 0);
rs1 = fetch_reg(RS1(insn), regs);
rs2 = fetch_reg(RS2(insn), regs);
bits = (rs2 > 5 ? 5 : rs2);
bits_mask = (1UL << bits) - 1UL;
rd_val = ((((rs1 >> 11) & 0x3) << 0) |
(((rs1 >> 33) & 0x3) << 2) |
(((rs1 >> 55) & 0x1) << 4) |
(((rs1 >> 13) & 0xf) << 5) |
(((rs1 >> 35) & 0xf) << 9) |
(((rs1 >> 56) & 0xf) << 13) |
(((rs1 >> 17) & bits_mask) << 17) |
(((rs1 >> 39) & bits_mask) << (17 + bits)) |
(((rs1 >> 60) & 0xf) << (17 + (2*bits))));
switch (opf) {
case ARRAY16_OPF:
rd_val <<= 1;
break;
case ARRAY32_OPF:
rd_val <<= 2;
}
store_reg(regs, rd_val, RD(insn));
}
static void bmask(struct pt_regs *regs, unsigned int insn)
{
unsigned long rs1, rs2, rd_val, gsr;
maybe_flush_windows(RS1(insn), RS2(insn), RD(insn), 0);
rs1 = fetch_reg(RS1(insn), regs);
rs2 = fetch_reg(RS2(insn), regs);
rd_val = rs1 + rs2;
store_reg(regs, rd_val, RD(insn));
gsr = current_thread_info()->gsr[0] & 0xffffffff;
gsr |= rd_val << 32UL;
current_thread_info()->gsr[0] = gsr;
}
static void bshuffle(struct pt_regs *regs, unsigned int insn)
{
struct fpustate *f = FPUSTATE;
unsigned long rs1, rs2, rd_val;
unsigned long bmask, i;
bmask = current_thread_info()->gsr[0] >> 32UL;
rs1 = fpd_regval(f, RS1(insn));
rs2 = fpd_regval(f, RS2(insn));
rd_val = 0UL;
for (i = 0; i < 8; i++) {
unsigned long which = (bmask >> (i * 4)) & 0xf;
unsigned long byte;
if (which < 8)
byte = (rs1 >> (which * 8)) & 0xff;
else
byte = (rs2 >> ((which-8)*8)) & 0xff;
rd_val |= (byte << (i * 8));
}
*fpd_regaddr(f, RD(insn)) = rd_val;
}
static void pdist(struct pt_regs *regs, unsigned int insn)
{
struct fpustate *f = FPUSTATE;
unsigned long rs1, rs2, *rd, rd_val;
unsigned long i;
rs1 = fpd_regval(f, RS1(insn));
rs2 = fpd_regval(f, RS2(insn));
rd = fpd_regaddr(f, RD(insn));
rd_val = *rd;
for (i = 0; i < 8; i++) {
s16 s1, s2;
s1 = (rs1 >> (56 - (i * 8))) & 0xff;
s2 = (rs2 >> (56 - (i * 8))) & 0xff;
s1 -= s2;
if (s1 < 0)
s1 = ~s1 + 1;
rd_val += s1;
}
*rd = rd_val;
}
static void pformat(struct pt_regs *regs, unsigned int insn, unsigned int opf)
{
struct fpustate *f = FPUSTATE;
unsigned long rs1, rs2, gsr, scale, rd_val;
gsr = current_thread_info()->gsr[0];
scale = (gsr >> 3) & (opf == FPACK16_OPF ? 0xf : 0x1f);
switch (opf) {
case FPACK16_OPF: {
unsigned long byte;
rs2 = fpd_regval(f, RS2(insn));
rd_val = 0;
for (byte = 0; byte < 4; byte++) {
unsigned int val;
s16 src = (rs2 >> (byte * 16UL)) & 0xffffUL;
int scaled = src << scale;
int from_fixed = scaled >> 7;
val = ((from_fixed < 0) ?
0 :
(from_fixed > 255) ?
255 : from_fixed);
rd_val |= (val << (8 * byte));
}
*fps_regaddr(f, RD(insn)) = rd_val;
break;
}
case FPACK32_OPF: {
unsigned long word;
rs1 = fpd_regval(f, RS1(insn));
rs2 = fpd_regval(f, RS2(insn));
rd_val = (rs1 << 8) & ~(0x000000ff000000ffUL);
for (word = 0; word < 2; word++) {
unsigned long val;
s32 src = (rs2 >> (word * 32UL));
s64 scaled = src << scale;
s64 from_fixed = scaled >> 23;
val = ((from_fixed < 0) ?
0 :
(from_fixed > 255) ?
255 : from_fixed);
rd_val |= (val << (32 * word));
}
*fpd_regaddr(f, RD(insn)) = rd_val;
break;
}
case FPACKFIX_OPF: {
unsigned long word;
rs2 = fpd_regval(f, RS2(insn));
rd_val = 0;
for (word = 0; word < 2; word++) {
long val;
s32 src = (rs2 >> (word * 32UL));
s64 scaled = src << scale;
s64 from_fixed = scaled >> 16;
val = ((from_fixed < -32768) ?
-32768 :
(from_fixed > 32767) ?
32767 : from_fixed);
rd_val |= ((val & 0xffff) << (word * 16));
}
*fps_regaddr(f, RD(insn)) = rd_val;
break;
}
case FEXPAND_OPF: {
unsigned long byte;
rs2 = fps_regval(f, RS2(insn));
rd_val = 0;
for (byte = 0; byte < 4; byte++) {
unsigned long val;
u8 src = (rs2 >> (byte * 8)) & 0xff;
val = src << 4;
rd_val |= (val << (byte * 16));
}
*fpd_regaddr(f, RD(insn)) = rd_val;
break;
}
case FPMERGE_OPF: {
rs1 = fps_regval(f, RS1(insn));
rs2 = fps_regval(f, RS2(insn));
rd_val = (((rs2 & 0x000000ff) << 0) |
((rs1 & 0x000000ff) << 8) |
((rs2 & 0x0000ff00) << 8) |
((rs1 & 0x0000ff00) << 16) |
((rs2 & 0x00ff0000) << 16) |
((rs1 & 0x00ff0000) << 24) |
((rs2 & 0xff000000) << 24) |
((rs1 & 0xff000000) << 32));
*fpd_regaddr(f, RD(insn)) = rd_val;
break;
}
}
}
static void pmul(struct pt_regs *regs, unsigned int insn, unsigned int opf)
{
struct fpustate *f = FPUSTATE;
unsigned long rs1, rs2, rd_val;
switch (opf) {
case FMUL8x16_OPF: {
unsigned long byte;
rs1 = fps_regval(f, RS1(insn));
rs2 = fpd_regval(f, RS2(insn));
rd_val = 0;
for (byte = 0; byte < 4; byte++) {
u16 src1 = (rs1 >> (byte * 8)) & 0x00ff;
s16 src2 = (rs2 >> (byte * 16)) & 0xffff;
u32 prod = src1 * src2;
u16 scaled = ((prod & 0x00ffff00) >> 8);
if (prod & 0x80)
scaled++;
rd_val |= ((scaled & 0xffffUL) << (byte * 16UL));
}
*fpd_regaddr(f, RD(insn)) = rd_val;
break;
}
case FMUL8x16AU_OPF:
case FMUL8x16AL_OPF: {
unsigned long byte;
s16 src2;
rs1 = fps_regval(f, RS1(insn));
rs2 = fps_regval(f, RS2(insn));
rd_val = 0;
src2 = rs2 >> (opf == FMUL8x16AU_OPF ? 16 : 0);
for (byte = 0; byte < 4; byte++) {
u16 src1 = (rs1 >> (byte * 8)) & 0x00ff;
u32 prod = src1 * src2;
u16 scaled = ((prod & 0x00ffff00) >> 8);
if (prod & 0x80)
scaled++;
rd_val |= ((scaled & 0xffffUL) << (byte * 16UL));
}
*fpd_regaddr(f, RD(insn)) = rd_val;
break;
}
case FMUL8SUx16_OPF:
case FMUL8ULx16_OPF: {
unsigned long byte, ushift;
rs1 = fpd_regval(f, RS1(insn));
rs2 = fpd_regval(f, RS2(insn));
rd_val = 0;
ushift = (opf == FMUL8SUx16_OPF) ? 8 : 0;
for (byte = 0; byte < 4; byte++) {
u16 src1;
s16 src2;
u32 prod;
u16 scaled;
src1 = ((rs1 >> ((16 * byte) + ushift)) & 0x00ff);
src2 = ((rs2 >> (16 * byte)) & 0xffff);
prod = src1 * src2;
scaled = ((prod & 0x00ffff00) >> 8);
if (prod & 0x80)
scaled++;
rd_val |= ((scaled & 0xffffUL) << (byte * 16UL));
}
*fpd_regaddr(f, RD(insn)) = rd_val;
break;
}
case FMULD8SUx16_OPF:
case FMULD8ULx16_OPF: {
unsigned long byte, ushift;
rs1 = fps_regval(f, RS1(insn));
rs2 = fps_regval(f, RS2(insn));
rd_val = 0;
ushift = (opf == FMULD8SUx16_OPF) ? 8 : 0;
for (byte = 0; byte < 2; byte++) {
u16 src1;
s16 src2;
u32 prod;
u16 scaled;
src1 = ((rs1 >> ((16 * byte) + ushift)) & 0x00ff);
src2 = ((rs2 >> (16 * byte)) & 0xffff);
prod = src1 * src2;
scaled = ((prod & 0x00ffff00) >> 8);
if (prod & 0x80)
scaled++;
rd_val |= ((scaled & 0xffffUL) <<
((byte * 32UL) + 7UL));
}
*fpd_regaddr(f, RD(insn)) = rd_val;
break;
}
}
}
static void pcmp(struct pt_regs *regs, unsigned int insn, unsigned int opf)
{
struct fpustate *f = FPUSTATE;
unsigned long rs1, rs2, rd_val, i;
rs1 = fpd_regval(f, RS1(insn));
rs2 = fpd_regval(f, RS2(insn));
rd_val = 0;
switch (opf) {
case FCMPGT16_OPF:
for (i = 0; i < 4; i++) {
s16 a = (rs1 >> (i * 16)) & 0xffff;
s16 b = (rs2 >> (i * 16)) & 0xffff;
if (a > b)
rd_val |= 8 >> i;
}
break;
case FCMPGT32_OPF:
for (i = 0; i < 2; i++) {
s32 a = (rs1 >> (i * 32)) & 0xffffffff;
s32 b = (rs2 >> (i * 32)) & 0xffffffff;
if (a > b)
rd_val |= 2 >> i;
}
break;
case FCMPLE16_OPF:
for (i = 0; i < 4; i++) {
s16 a = (rs1 >> (i * 16)) & 0xffff;
s16 b = (rs2 >> (i * 16)) & 0xffff;
if (a <= b)
rd_val |= 8 >> i;
}
break;
case FCMPLE32_OPF:
for (i = 0; i < 2; i++) {
s32 a = (rs1 >> (i * 32)) & 0xffffffff;
s32 b = (rs2 >> (i * 32)) & 0xffffffff;
if (a <= b)
rd_val |= 2 >> i;
}
break;
case FCMPNE16_OPF:
for (i = 0; i < 4; i++) {
s16 a = (rs1 >> (i * 16)) & 0xffff;
s16 b = (rs2 >> (i * 16)) & 0xffff;
if (a != b)
rd_val |= 8 >> i;
}
break;
case FCMPNE32_OPF:
for (i = 0; i < 2; i++) {
s32 a = (rs1 >> (i * 32)) & 0xffffffff;
s32 b = (rs2 >> (i * 32)) & 0xffffffff;
if (a != b)
rd_val |= 2 >> i;
}
break;
case FCMPEQ16_OPF:
for (i = 0; i < 4; i++) {
s16 a = (rs1 >> (i * 16)) & 0xffff;
s16 b = (rs2 >> (i * 16)) & 0xffff;
if (a == b)
rd_val |= 8 >> i;
}
break;
case FCMPEQ32_OPF:
for (i = 0; i < 2; i++) {
s32 a = (rs1 >> (i * 32)) & 0xffffffff;
s32 b = (rs2 >> (i * 32)) & 0xffffffff;
if (a == b)
rd_val |= 2 >> i;
}
break;
}
maybe_flush_windows(0, 0, RD(insn), 0);
store_reg(regs, rd_val, RD(insn));
}
int vis_emul(struct pt_regs *regs, unsigned int insn)
{
unsigned long pc = regs->tpc;
unsigned int opf;
BUG_ON(regs->tstate & TSTATE_PRIV);
perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, regs, 0);
if (test_thread_flag(TIF_32BIT))
pc = (u32)pc;
if (get_user(insn, (u32 __user *) pc))
return -EFAULT;
save_and_clear_fpu();
opf = (insn & VIS_OPF_MASK) >> VIS_OPF_SHIFT;
switch (opf) {
default:
return -EINVAL;
case FPACK16_OPF:
case FPACK32_OPF:
case FPACKFIX_OPF:
case FEXPAND_OPF:
case FPMERGE_OPF:
pformat(regs, insn, opf);
break;
case FMUL8x16_OPF:
case FMUL8x16AU_OPF:
case FMUL8x16AL_OPF:
case FMUL8SUx16_OPF:
case FMUL8ULx16_OPF:
case FMULD8SUx16_OPF:
case FMULD8ULx16_OPF:
pmul(regs, insn, opf);
break;
case FCMPGT16_OPF:
case FCMPGT32_OPF:
case FCMPLE16_OPF:
case FCMPLE32_OPF:
case FCMPNE16_OPF:
case FCMPNE32_OPF:
case FCMPEQ16_OPF:
case FCMPEQ32_OPF:
pcmp(regs, insn, opf);
break;
case EDGE8_OPF:
case EDGE8N_OPF:
case EDGE8L_OPF:
case EDGE8LN_OPF:
case EDGE16_OPF:
case EDGE16N_OPF:
case EDGE16L_OPF:
case EDGE16LN_OPF:
case EDGE32_OPF:
case EDGE32N_OPF:
case EDGE32L_OPF:
case EDGE32LN_OPF:
edge(regs, insn, opf);
break;
case PDIST_OPF:
pdist(regs, insn);
break;
case ARRAY8_OPF:
case ARRAY16_OPF:
case ARRAY32_OPF:
array(regs, insn, opf);
break;
case BMASK_OPF:
bmask(regs, insn);
break;
case BSHUFFLE_OPF:
bshuffle(regs, insn);
break;
}
regs->tpc = regs->tnpc;
regs->tnpc += 4;
return 0;
}
