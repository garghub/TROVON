static u32 jit_udiv32(u32 dividend, u32 divisor)
{
return dividend / divisor;
}
static u32 jit_mod32(u32 dividend, u32 divisor)
{
return dividend % divisor;
}
static inline void _emit(int cond, u32 inst, struct jit_ctx *ctx)
{
inst |= (cond << 28);
inst = __opcode_to_mem_arm(inst);
if (ctx->target != NULL)
ctx->target[ctx->idx] = inst;
ctx->idx++;
}
static inline void emit(u32 inst, struct jit_ctx *ctx)
{
_emit(ARM_COND_AL, inst, ctx);
}
static int16_t imm8m(u32 x)
{
u32 rot;
for (rot = 0; rot < 16; rot++)
if ((x & ~ror32(0xff, 2 * rot)) == 0)
return rol32(x, 2 * rot) | (rot << 8);
return -1;
}
static void jit_fill_hole(void *area, unsigned int size)
{
u32 *ptr;
for (ptr = area; size >= sizeof(u32); size -= sizeof(u32))
*ptr++ = __opcode_to_mem_arm(ARM_INST_UDF);
}
static u16 imm_offset(u32 k, struct jit_ctx *ctx)
{
unsigned int i = 0, offset;
u16 imm;
if (ctx->target == NULL) {
ctx->imm_count++;
return 0;
}
while ((i < ctx->imm_count) && ctx->imms[i]) {
if (ctx->imms[i] == k)
break;
i++;
}
if (ctx->imms[i] == 0)
ctx->imms[i] = k;
offset = ctx->offsets[ctx->prog->len - 1] * 4;
offset += ctx->prologue_bytes;
offset += ctx->epilogue_bytes;
offset += i * 4;
ctx->target[offset / 4] = k;
imm = offset - (8 + ctx->idx * 4);
if (imm & ~0xfff) {
ctx->flags |= FLAG_IMM_OVERFLOW;
return 0;
}
return imm;
}
static inline int bpf2a32_offset(int bpf_to, int bpf_from,
const struct jit_ctx *ctx) {
int to, from;
if (ctx->target == NULL)
return 0;
to = ctx->offsets[bpf_to];
from = ctx->offsets[bpf_from];
return to - from - 1;
}
static inline void emit_mov_i_no8m(const u8 rd, u32 val, struct jit_ctx *ctx)
{
#if __LINUX_ARM_ARCH__ < 7
emit(ARM_LDR_I(rd, ARM_PC, imm_offset(val, ctx)), ctx);
#else
emit(ARM_MOVW(rd, val & 0xffff), ctx);
if (val > 0xffff)
emit(ARM_MOVT(rd, val >> 16), ctx);
#endif
}
static inline void emit_mov_i(const u8 rd, u32 val, struct jit_ctx *ctx)
{
int imm12 = imm8m(val);
if (imm12 >= 0)
emit(ARM_MOV_I(rd, imm12), ctx);
else
emit_mov_i_no8m(rd, val, ctx);
}
static inline void emit_blx_r(u8 tgt_reg, struct jit_ctx *ctx)
{
ctx->seen |= SEEN_CALL;
#if __LINUX_ARM_ARCH__ < 5
emit(ARM_MOV_R(ARM_LR, ARM_PC), ctx);
if (elf_hwcap & HWCAP_THUMB)
emit(ARM_BX(tgt_reg), ctx);
else
emit(ARM_MOV_R(ARM_PC, tgt_reg), ctx);
#else
emit(ARM_BLX_R(tgt_reg), ctx);
#endif
}
static inline int epilogue_offset(const struct jit_ctx *ctx)
{
int to, from;
if (ctx->target == NULL)
return 0;
to = ctx->epilogue_offset;
from = ctx->idx;
return to - from - 2;
}
static inline void emit_udivmod(u8 rd, u8 rm, u8 rn, struct jit_ctx *ctx, u8 op)
{
const u8 *tmp = bpf2a32[TMP_REG_1];
s32 jmp_offset;
emit(ARM_CMP_I(rn, 0), ctx);
_emit(ARM_COND_EQ, ARM_MOV_I(ARM_R0, 0), ctx);
jmp_offset = epilogue_offset(ctx);
_emit(ARM_COND_EQ, ARM_B(jmp_offset), ctx);
#if __LINUX_ARM_ARCH__ == 7
if (elf_hwcap & HWCAP_IDIVA) {
if (op == BPF_DIV)
emit(ARM_UDIV(rd, rm, rn), ctx);
else {
emit(ARM_UDIV(ARM_IP, rm, rn), ctx);
emit(ARM_MLS(rd, rn, ARM_IP, rm), ctx);
}
return;
}
#endif
if (rn != ARM_R1) {
emit(ARM_MOV_R(tmp[0], ARM_R1), ctx);
emit(ARM_MOV_R(ARM_R1, rn), ctx);
}
if (rm != ARM_R0) {
emit(ARM_MOV_R(tmp[1], ARM_R0), ctx);
emit(ARM_MOV_R(ARM_R0, rm), ctx);
}
ctx->seen |= SEEN_CALL;
emit_mov_i(ARM_IP, op == BPF_DIV ?
(u32)jit_udiv32 : (u32)jit_mod32, ctx);
emit_blx_r(ARM_IP, ctx);
if (rd != ARM_R0)
emit(ARM_MOV_R(rd, ARM_R0), ctx);
if (rn != ARM_R1)
emit(ARM_MOV_R(ARM_R1, tmp[0]), ctx);
if (rm != ARM_R0)
emit(ARM_MOV_R(ARM_R0, tmp[1]), ctx);
}
static inline bool is_on_stack(u8 bpf_reg)
{
static u8 stack_regs[] = {BPF_REG_AX, BPF_REG_3, BPF_REG_4, BPF_REG_5,
BPF_REG_7, BPF_REG_8, BPF_REG_9, TCALL_CNT,
BPF_REG_2, BPF_REG_FP};
int i, reg_len = sizeof(stack_regs);
for (i = 0 ; i < reg_len ; i++) {
if (bpf_reg == stack_regs[i])
return true;
}
return false;
}
static inline void emit_a32_mov_i(const u8 dst, const u32 val,
bool dstk, struct jit_ctx *ctx)
{
const u8 *tmp = bpf2a32[TMP_REG_1];
if (dstk) {
emit_mov_i(tmp[1], val, ctx);
emit(ARM_STR_I(tmp[1], ARM_SP, STACK_VAR(dst)), ctx);
} else {
emit_mov_i(dst, val, ctx);
}
}
static inline void emit_a32_mov_i64(const bool is64, const u8 dst[],
const u32 val, bool dstk,
struct jit_ctx *ctx) {
u32 hi = 0;
if (is64 && (val & (1<<31)))
hi = (u32)~0;
emit_a32_mov_i(dst_lo, val, dstk, ctx);
emit_a32_mov_i(dst_hi, hi, dstk, ctx);
}
static inline void emit_a32_add_r(const u8 dst, const u8 src,
const bool is64, const bool hi,
struct jit_ctx *ctx) {
if (!hi && is64)
emit(ARM_ADDS_R(dst, dst, src), ctx);
else if (hi && is64)
emit(ARM_ADC_R(dst, dst, src), ctx);
else
emit(ARM_ADD_R(dst, dst, src), ctx);
}
static inline void emit_a32_sub_r(const u8 dst, const u8 src,
const bool is64, const bool hi,
struct jit_ctx *ctx) {
if (!hi && is64)
emit(ARM_SUBS_R(dst, dst, src), ctx);
else if (hi && is64)
emit(ARM_SBC_R(dst, dst, src), ctx);
else
emit(ARM_SUB_R(dst, dst, src), ctx);
}
static inline void emit_alu_r(const u8 dst, const u8 src, const bool is64,
const bool hi, const u8 op, struct jit_ctx *ctx){
switch (BPF_OP(op)) {
case BPF_ADD:
emit_a32_add_r(dst, src, is64, hi, ctx);
break;
case BPF_SUB:
emit_a32_sub_r(dst, src, is64, hi, ctx);
break;
case BPF_OR:
emit(ARM_ORR_R(dst, dst, src), ctx);
break;
case BPF_AND:
emit(ARM_AND_R(dst, dst, src), ctx);
break;
case BPF_XOR:
emit(ARM_EOR_R(dst, dst, src), ctx);
break;
case BPF_MUL:
emit(ARM_MUL(dst, dst, src), ctx);
break;
case BPF_LSH:
emit(ARM_LSL_R(dst, dst, src), ctx);
break;
case BPF_RSH:
emit(ARM_LSR_R(dst, dst, src), ctx);
break;
case BPF_ARSH:
emit(ARM_MOV_SR(dst, dst, SRTYPE_ASR, src), ctx);
break;
}
}
static inline void emit_a32_alu_r(const u8 dst, const u8 src,
bool dstk, bool sstk,
struct jit_ctx *ctx, const bool is64,
const bool hi, const u8 op) {
const u8 *tmp = bpf2a32[TMP_REG_1];
u8 rn = sstk ? tmp[1] : src;
if (sstk)
emit(ARM_LDR_I(rn, ARM_SP, STACK_VAR(src)), ctx);
if (dstk) {
emit(ARM_LDR_I(tmp[0], ARM_SP, STACK_VAR(dst)), ctx);
emit_alu_r(tmp[0], rn, is64, hi, op, ctx);
emit(ARM_STR_I(tmp[0], ARM_SP, STACK_VAR(dst)), ctx);
} else {
emit_alu_r(dst, rn, is64, hi, op, ctx);
}
}
static inline void emit_a32_alu_r64(const bool is64, const u8 dst[],
const u8 src[], bool dstk,
bool sstk, struct jit_ctx *ctx,
const u8 op) {
emit_a32_alu_r(dst_lo, src_lo, dstk, sstk, ctx, is64, false, op);
if (is64)
emit_a32_alu_r(dst_hi, src_hi, dstk, sstk, ctx, is64, true, op);
else
emit_a32_mov_i(dst_hi, 0, dstk, ctx);
}
static inline void emit_a32_mov_r(const u8 dst, const u8 src,
bool dstk, bool sstk,
struct jit_ctx *ctx) {
const u8 *tmp = bpf2a32[TMP_REG_1];
u8 rt = sstk ? tmp[0] : src;
if (sstk)
emit(ARM_LDR_I(tmp[0], ARM_SP, STACK_VAR(src)), ctx);
if (dstk)
emit(ARM_STR_I(rt, ARM_SP, STACK_VAR(dst)), ctx);
else
emit(ARM_MOV_R(dst, rt), ctx);
}
static inline void emit_a32_mov_r64(const bool is64, const u8 dst[],
const u8 src[], bool dstk,
bool sstk, struct jit_ctx *ctx) {
emit_a32_mov_r(dst_lo, src_lo, dstk, sstk, ctx);
if (is64) {
emit_a32_mov_r(dst_hi, src_hi, dstk, sstk, ctx);
} else {
emit_a32_mov_i(dst_hi, 0, dstk, ctx);
}
}
static inline void emit_a32_alu_i(const u8 dst, const u32 val, bool dstk,
struct jit_ctx *ctx, const u8 op) {
const u8 *tmp = bpf2a32[TMP_REG_1];
u8 rd = dstk ? tmp[0] : dst;
if (dstk)
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst)), ctx);
switch (op) {
case BPF_LSH:
emit(ARM_LSL_I(rd, rd, val), ctx);
break;
case BPF_RSH:
emit(ARM_LSR_I(rd, rd, val), ctx);
break;
case BPF_NEG:
emit(ARM_RSB_I(rd, rd, val), ctx);
break;
}
if (dstk)
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst)), ctx);
}
static inline void emit_a32_neg64(const u8 dst[], bool dstk,
struct jit_ctx *ctx){
const u8 *tmp = bpf2a32[TMP_REG_1];
u8 rd = dstk ? tmp[1] : dst[1];
u8 rm = dstk ? tmp[0] : dst[0];
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
emit(ARM_RSBS_I(rd, rd, 0), ctx);
emit(ARM_RSC_I(rm, rm, 0), ctx);
if (dstk) {
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
}
static inline void emit_a32_lsh_r64(const u8 dst[], const u8 src[], bool dstk,
bool sstk, struct jit_ctx *ctx) {
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u8 rt = sstk ? tmp2[1] : src_lo;
u8 rd = dstk ? tmp[1] : dst_lo;
u8 rm = dstk ? tmp[0] : dst_hi;
if (sstk)
emit(ARM_LDR_I(rt, ARM_SP, STACK_VAR(src_lo)), ctx);
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
emit(ARM_SUB_I(ARM_IP, rt, 32), ctx);
emit(ARM_RSB_I(tmp2[0], rt, 32), ctx);
ctx->seen |= SEEN_CALL;
emit(ARM_MOV_SR(ARM_LR, rm, SRTYPE_ASL, rt), ctx);
emit(ARM_ORR_SR(ARM_LR, ARM_LR, rd, SRTYPE_ASL, ARM_IP), ctx);
emit(ARM_ORR_SR(ARM_IP, ARM_LR, rd, SRTYPE_LSR, tmp2[0]), ctx);
emit(ARM_MOV_SR(ARM_LR, rd, SRTYPE_ASL, rt), ctx);
if (dstk) {
emit(ARM_STR_I(ARM_LR, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(ARM_IP, ARM_SP, STACK_VAR(dst_hi)), ctx);
} else {
emit(ARM_MOV_R(rd, ARM_LR), ctx);
emit(ARM_MOV_R(rm, ARM_IP), ctx);
}
}
static inline void emit_a32_arsh_r64(const u8 dst[], const u8 src[], bool dstk,
bool sstk, struct jit_ctx *ctx) {
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u8 rt = sstk ? tmp2[1] : src_lo;
u8 rd = dstk ? tmp[1] : dst_lo;
u8 rm = dstk ? tmp[0] : dst_hi;
if (sstk)
emit(ARM_LDR_I(rt, ARM_SP, STACK_VAR(src_lo)), ctx);
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
emit(ARM_RSB_I(ARM_IP, rt, 32), ctx);
emit(ARM_SUBS_I(tmp2[0], rt, 32), ctx);
ctx->seen |= SEEN_CALL;
emit(ARM_MOV_SR(ARM_LR, rd, SRTYPE_LSR, rt), ctx);
emit(ARM_ORR_SR(ARM_LR, ARM_LR, rm, SRTYPE_ASL, ARM_IP), ctx);
_emit(ARM_COND_MI, ARM_B(0), ctx);
emit(ARM_ORR_SR(ARM_LR, ARM_LR, rm, SRTYPE_ASR, tmp2[0]), ctx);
emit(ARM_MOV_SR(ARM_IP, rm, SRTYPE_ASR, rt), ctx);
if (dstk) {
emit(ARM_STR_I(ARM_LR, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(ARM_IP, ARM_SP, STACK_VAR(dst_hi)), ctx);
} else {
emit(ARM_MOV_R(rd, ARM_LR), ctx);
emit(ARM_MOV_R(rm, ARM_IP), ctx);
}
}
static inline void emit_a32_lsr_r64(const u8 dst[], const u8 src[], bool dstk,
bool sstk, struct jit_ctx *ctx) {
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u8 rt = sstk ? tmp2[1] : src_lo;
u8 rd = dstk ? tmp[1] : dst_lo;
u8 rm = dstk ? tmp[0] : dst_hi;
if (sstk)
emit(ARM_LDR_I(rt, ARM_SP, STACK_VAR(src_lo)), ctx);
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
emit(ARM_RSB_I(ARM_IP, rt, 32), ctx);
emit(ARM_SUBS_I(tmp2[0], rt, 32), ctx);
ctx->seen |= SEEN_CALL;
emit(ARM_MOV_SR(ARM_LR, rd, SRTYPE_LSR, rt), ctx);
emit(ARM_ORR_SR(ARM_LR, ARM_LR, rm, SRTYPE_ASL, ARM_IP), ctx);
emit(ARM_ORR_SR(ARM_LR, ARM_LR, rm, SRTYPE_LSR, tmp2[0]), ctx);
emit(ARM_MOV_SR(ARM_IP, rm, SRTYPE_LSR, rt), ctx);
if (dstk) {
emit(ARM_STR_I(ARM_LR, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(ARM_IP, ARM_SP, STACK_VAR(dst_hi)), ctx);
} else {
emit(ARM_MOV_R(rd, ARM_LR), ctx);
emit(ARM_MOV_R(rm, ARM_IP), ctx);
}
}
static inline void emit_a32_lsh_i64(const u8 dst[], bool dstk,
const u32 val, struct jit_ctx *ctx){
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u8 rd = dstk ? tmp[1] : dst_lo;
u8 rm = dstk ? tmp[0] : dst_hi;
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
if (val < 32) {
emit(ARM_MOV_SI(tmp2[0], rm, SRTYPE_ASL, val), ctx);
emit(ARM_ORR_SI(rm, tmp2[0], rd, SRTYPE_LSR, 32 - val), ctx);
emit(ARM_MOV_SI(rd, rd, SRTYPE_ASL, val), ctx);
} else {
if (val == 32)
emit(ARM_MOV_R(rm, rd), ctx);
else
emit(ARM_MOV_SI(rm, rd, SRTYPE_ASL, val - 32), ctx);
emit(ARM_EOR_R(rd, rd, rd), ctx);
}
if (dstk) {
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
}
static inline void emit_a32_lsr_i64(const u8 dst[], bool dstk,
const u32 val, struct jit_ctx *ctx) {
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u8 rd = dstk ? tmp[1] : dst_lo;
u8 rm = dstk ? tmp[0] : dst_hi;
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
if (val < 32) {
emit(ARM_MOV_SI(tmp2[1], rd, SRTYPE_LSR, val), ctx);
emit(ARM_ORR_SI(rd, tmp2[1], rm, SRTYPE_ASL, 32 - val), ctx);
emit(ARM_MOV_SI(rm, rm, SRTYPE_LSR, val), ctx);
} else if (val == 32) {
emit(ARM_MOV_R(rd, rm), ctx);
emit(ARM_MOV_I(rm, 0), ctx);
} else {
emit(ARM_MOV_SI(rd, rm, SRTYPE_LSR, val - 32), ctx);
emit(ARM_MOV_I(rm, 0), ctx);
}
if (dstk) {
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
}
static inline void emit_a32_arsh_i64(const u8 dst[], bool dstk,
const u32 val, struct jit_ctx *ctx){
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u8 rd = dstk ? tmp[1] : dst_lo;
u8 rm = dstk ? tmp[0] : dst_hi;
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
if (val < 32) {
emit(ARM_MOV_SI(tmp2[1], rd, SRTYPE_LSR, val), ctx);
emit(ARM_ORR_SI(rd, tmp2[1], rm, SRTYPE_ASL, 32 - val), ctx);
emit(ARM_MOV_SI(rm, rm, SRTYPE_ASR, val), ctx);
} else if (val == 32) {
emit(ARM_MOV_R(rd, rm), ctx);
emit(ARM_MOV_SI(rm, rm, SRTYPE_ASR, 31), ctx);
} else {
emit(ARM_MOV_SI(rd, rm, SRTYPE_ASR, val - 32), ctx);
emit(ARM_MOV_SI(rm, rm, SRTYPE_ASR, 31), ctx);
}
if (dstk) {
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
}
static inline void emit_a32_mul_r64(const u8 dst[], const u8 src[], bool dstk,
bool sstk, struct jit_ctx *ctx) {
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u8 rd = dstk ? tmp[1] : dst_lo;
u8 rm = dstk ? tmp[0] : dst_hi;
u8 rt = sstk ? tmp2[1] : src_lo;
u8 rn = sstk ? tmp2[0] : src_hi;
if (dstk) {
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
if (sstk) {
emit(ARM_LDR_I(rt, ARM_SP, STACK_VAR(src_lo)), ctx);
emit(ARM_LDR_I(rn, ARM_SP, STACK_VAR(src_hi)), ctx);
}
emit(ARM_MUL(ARM_IP, rd, rn), ctx);
emit(ARM_MUL(ARM_LR, rm, rt), ctx);
ctx->seen |= SEEN_CALL;
emit(ARM_ADD_R(ARM_LR, ARM_IP, ARM_LR), ctx);
emit(ARM_UMULL(ARM_IP, rm, rd, rt), ctx);
emit(ARM_ADD_R(rm, ARM_LR, rm), ctx);
if (dstk) {
emit(ARM_STR_I(ARM_IP, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(rm, ARM_SP, STACK_VAR(dst_hi)), ctx);
} else {
emit(ARM_MOV_R(rd, ARM_IP), ctx);
}
}
static inline void emit_str_r(const u8 dst, const u8 src, bool dstk,
const s32 off, struct jit_ctx *ctx, const u8 sz){
const u8 *tmp = bpf2a32[TMP_REG_1];
u8 rd = dstk ? tmp[1] : dst;
if (dstk)
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst)), ctx);
if (off) {
emit_a32_mov_i(tmp[0], off, false, ctx);
emit(ARM_ADD_R(tmp[0], rd, tmp[0]), ctx);
rd = tmp[0];
}
switch (sz) {
case BPF_W:
emit(ARM_STR_I(src, rd, 0), ctx);
break;
case BPF_H:
emit(ARM_STRH_I(src, rd, 0), ctx);
break;
case BPF_B:
emit(ARM_STRB_I(src, rd, 0), ctx);
break;
}
}
static inline void emit_ldx_r(const u8 dst, const u8 src, bool dstk,
const s32 off, struct jit_ctx *ctx, const u8 sz){
const u8 *tmp = bpf2a32[TMP_REG_1];
u8 rd = dstk ? tmp[1] : dst;
u8 rm = src;
if (off) {
emit_a32_mov_i(tmp[0], off, false, ctx);
emit(ARM_ADD_R(tmp[0], tmp[0], src), ctx);
rm = tmp[0];
}
switch (sz) {
case BPF_W:
emit(ARM_LDR_I(rd, rm, 0), ctx);
break;
case BPF_H:
emit(ARM_LDRH_I(rd, rm, 0), ctx);
break;
case BPF_B:
emit(ARM_LDRB_I(rd, rm, 0), ctx);
break;
}
if (dstk)
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst)), ctx);
}
static inline void emit_ar_r(const u8 rd, const u8 rt, const u8 rm,
const u8 rn, struct jit_ctx *ctx, u8 op) {
switch (op) {
case BPF_JSET:
ctx->seen |= SEEN_CALL;
emit(ARM_AND_R(ARM_IP, rt, rn), ctx);
emit(ARM_AND_R(ARM_LR, rd, rm), ctx);
emit(ARM_ORRS_R(ARM_IP, ARM_LR, ARM_IP), ctx);
break;
case BPF_JEQ:
case BPF_JNE:
case BPF_JGT:
case BPF_JGE:
case BPF_JLE:
case BPF_JLT:
emit(ARM_CMP_R(rd, rm), ctx);
_emit(ARM_COND_EQ, ARM_CMP_R(rt, rn), ctx);
break;
case BPF_JSLE:
case BPF_JSGT:
emit(ARM_CMP_R(rn, rt), ctx);
emit(ARM_SBCS_R(ARM_IP, rm, rd), ctx);
break;
case BPF_JSLT:
case BPF_JSGE:
emit(ARM_CMP_R(rt, rn), ctx);
emit(ARM_SBCS_R(ARM_IP, rd, rm), ctx);
break;
}
}
static int emit_bpf_tail_call(struct jit_ctx *ctx)
{
const u8 *r2 = bpf2a32[BPF_REG_2];
const u8 *r3 = bpf2a32[BPF_REG_3];
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
const u8 *tcc = bpf2a32[TCALL_CNT];
const int idx0 = ctx->idx;
#define cur_offset (ctx->idx - idx0)
#define jmp_offset (out_offset - (cur_offset))
u32 off, lo, hi;
off = offsetof(struct bpf_array, map.max_entries);
emit_a32_mov_i(tmp[1], off, false, ctx);
emit(ARM_LDR_I(tmp2[1], ARM_SP, STACK_VAR(r2[1])), ctx);
emit(ARM_LDR_R(tmp[1], tmp2[1], tmp[1]), ctx);
emit(ARM_LDR_I(tmp2[1], ARM_SP, STACK_VAR(r3[1])), ctx);
emit(ARM_CMP_R(tmp2[1], tmp[1]), ctx);
_emit(ARM_COND_CS, ARM_B(jmp_offset), ctx);
lo = (u32)MAX_TAIL_CALL_CNT;
hi = (u32)((u64)MAX_TAIL_CALL_CNT >> 32);
emit(ARM_LDR_I(tmp[1], ARM_SP, STACK_VAR(tcc[1])), ctx);
emit(ARM_LDR_I(tmp[0], ARM_SP, STACK_VAR(tcc[0])), ctx);
emit(ARM_CMP_I(tmp[0], hi), ctx);
_emit(ARM_COND_EQ, ARM_CMP_I(tmp[1], lo), ctx);
_emit(ARM_COND_HI, ARM_B(jmp_offset), ctx);
emit(ARM_ADDS_I(tmp[1], tmp[1], 1), ctx);
emit(ARM_ADC_I(tmp[0], tmp[0], 0), ctx);
emit(ARM_STR_I(tmp[1], ARM_SP, STACK_VAR(tcc[1])), ctx);
emit(ARM_STR_I(tmp[0], ARM_SP, STACK_VAR(tcc[0])), ctx);
off = offsetof(struct bpf_array, ptrs);
emit_a32_mov_i(tmp[1], off, false, ctx);
emit(ARM_LDR_I(tmp2[1], ARM_SP, STACK_VAR(r2[1])), ctx);
emit(ARM_ADD_R(tmp[1], tmp2[1], tmp[1]), ctx);
emit(ARM_LDR_I(tmp2[1], ARM_SP, STACK_VAR(r3[1])), ctx);
emit(ARM_MOV_SI(tmp[0], tmp2[1], SRTYPE_ASL, 2), ctx);
emit(ARM_LDR_R(tmp[1], tmp[1], tmp[0]), ctx);
emit(ARM_CMP_I(tmp[1], 0), ctx);
_emit(ARM_COND_EQ, ARM_B(jmp_offset), ctx);
off = offsetof(struct bpf_prog, bpf_func);
emit_a32_mov_i(tmp2[1], off, false, ctx);
emit(ARM_LDR_R(tmp[1], tmp[1], tmp2[1]), ctx);
emit(ARM_ADD_I(tmp[1], tmp[1], ctx->prologue_bytes), ctx);
emit(ARM_BX(tmp[1]), ctx);
if (out_offset == -1)
out_offset = cur_offset;
if (cur_offset != out_offset) {
pr_err_once("tail_call out_offset = %d, expected %d!\n",
cur_offset, out_offset);
return -1;
}
return 0;
#undef cur_offset
#undef jmp_offset
}
static inline void emit_rev16(const u8 rd, const u8 rn, struct jit_ctx *ctx)
{
#if __LINUX_ARM_ARCH__ < 6
const u8 *tmp2 = bpf2a32[TMP_REG_2];
emit(ARM_AND_I(tmp2[1], rn, 0xff), ctx);
emit(ARM_MOV_SI(tmp2[0], rn, SRTYPE_LSR, 8), ctx);
emit(ARM_AND_I(tmp2[0], tmp2[0], 0xff), ctx);
emit(ARM_ORR_SI(rd, tmp2[0], tmp2[1], SRTYPE_LSL, 8), ctx);
#else
emit(ARM_REV16(rd, rn), ctx);
#endif
}
static inline void emit_rev32(const u8 rd, const u8 rn, struct jit_ctx *ctx)
{
#if __LINUX_ARM_ARCH__ < 6
const u8 *tmp2 = bpf2a32[TMP_REG_2];
emit(ARM_AND_I(tmp2[1], rn, 0xff), ctx);
emit(ARM_MOV_SI(tmp2[0], rn, SRTYPE_LSR, 24), ctx);
emit(ARM_ORR_SI(ARM_IP, tmp2[0], tmp2[1], SRTYPE_LSL, 24), ctx);
emit(ARM_MOV_SI(tmp2[1], rn, SRTYPE_LSR, 8), ctx);
emit(ARM_AND_I(tmp2[1], tmp2[1], 0xff), ctx);
emit(ARM_MOV_SI(tmp2[0], rn, SRTYPE_LSR, 16), ctx);
emit(ARM_AND_I(tmp2[0], tmp2[0], 0xff), ctx);
emit(ARM_MOV_SI(tmp2[0], tmp2[0], SRTYPE_LSL, 8), ctx);
emit(ARM_ORR_SI(tmp2[0], tmp2[0], tmp2[1], SRTYPE_LSL, 16), ctx);
emit(ARM_ORR_R(rd, ARM_IP, tmp2[0]), ctx);
#else
emit(ARM_REV(rd, rn), ctx);
#endif
}
static inline void emit_push_r64(const u8 src[], const u8 shift,
struct jit_ctx *ctx)
{
const u8 *tmp2 = bpf2a32[TMP_REG_2];
u16 reg_set = 0;
emit(ARM_LDR_I(tmp2[1], ARM_SP, STACK_VAR(src[1]+shift)), ctx);
emit(ARM_LDR_I(tmp2[0], ARM_SP, STACK_VAR(src[0]+shift)), ctx);
reg_set = (1 << tmp2[1]) | (1 << tmp2[0]);
emit(ARM_PUSH(reg_set), ctx);
}
static void build_prologue(struct jit_ctx *ctx)
{
const u8 r0 = bpf2a32[BPF_REG_0][1];
const u8 r2 = bpf2a32[BPF_REG_1][1];
const u8 r3 = bpf2a32[BPF_REG_1][0];
const u8 r4 = bpf2a32[BPF_REG_6][1];
const u8 r5 = bpf2a32[BPF_REG_6][0];
const u8 r6 = bpf2a32[TMP_REG_1][1];
const u8 r7 = bpf2a32[TMP_REG_1][0];
const u8 r8 = bpf2a32[TMP_REG_2][1];
const u8 r10 = bpf2a32[TMP_REG_2][0];
const u8 fplo = bpf2a32[BPF_REG_FP][1];
const u8 fphi = bpf2a32[BPF_REG_FP][0];
const u8 sp = ARM_SP;
const u8 *tcc = bpf2a32[TCALL_CNT];
u16 reg_set = 0;
reg_set |= (1<<r4) | (1<<r5) | (1<<r6) | (1<<r7) | (1<<r8) | (1<<r10);
#ifdef CONFIG_FRAME_POINTER
reg_set |= (1<<ARM_FP) | (1<<ARM_IP) | (1<<ARM_LR) | (1<<ARM_PC);
emit(ARM_MOV_R(ARM_IP, sp), ctx);
emit(ARM_PUSH(reg_set), ctx);
emit(ARM_SUB_I(ARM_FP, ARM_IP, 4), ctx);
#else
if (ctx->seen & SEEN_CALL)
reg_set |= (1<<ARM_LR);
emit(ARM_PUSH(reg_set), ctx);
#endif
emit(ARM_SUB_I(ARM_IP, sp, SCRATCH_SIZE), ctx);
ctx->stack_size = imm8m(STACK_SIZE);
emit(ARM_SUB_I(ARM_SP, ARM_SP, ctx->stack_size), ctx);
emit_a32_mov_r(fplo, ARM_IP, true, false, ctx);
emit_a32_mov_i(fphi, 0, true, ctx);
emit(ARM_MOV_I(r4, 0), ctx);
emit(ARM_MOV_R(r3, r4), ctx);
emit(ARM_MOV_R(r2, r0), ctx);
emit(ARM_STR_I(r4, ARM_SP, STACK_VAR(tcc[0])), ctx);
emit(ARM_STR_I(r4, ARM_SP, STACK_VAR(tcc[1])), ctx);
}
static void build_epilogue(struct jit_ctx *ctx)
{
const u8 r4 = bpf2a32[BPF_REG_6][1];
const u8 r5 = bpf2a32[BPF_REG_6][0];
const u8 r6 = bpf2a32[TMP_REG_1][1];
const u8 r7 = bpf2a32[TMP_REG_1][0];
const u8 r8 = bpf2a32[TMP_REG_2][1];
const u8 r10 = bpf2a32[TMP_REG_2][0];
u16 reg_set = 0;
emit(ARM_ADD_I(ARM_SP, ARM_SP, ctx->stack_size), ctx);
reg_set |= (1<<r4) | (1<<r5) | (1<<r6) | (1<<r7) | (1<<r8) | (1<<r10);
#ifdef CONFIG_FRAME_POINTER
reg_set |= (1<<ARM_FP) | (1<<ARM_SP) | (1<<ARM_PC);
emit(ARM_LDM(ARM_SP, reg_set), ctx);
#else
if (ctx->seen & SEEN_CALL)
reg_set |= (1<<ARM_PC);
emit(ARM_POP(reg_set), ctx);
if (!(ctx->seen & SEEN_CALL))
emit(ARM_BX(ARM_LR), ctx);
#endif
}
static int build_insn(const struct bpf_insn *insn, struct jit_ctx *ctx)
{
const u8 code = insn->code;
const u8 *dst = bpf2a32[insn->dst_reg];
const u8 *src = bpf2a32[insn->src_reg];
const u8 *tmp = bpf2a32[TMP_REG_1];
const u8 *tmp2 = bpf2a32[TMP_REG_2];
const s16 off = insn->off;
const s32 imm = insn->imm;
const int i = insn - ctx->prog->insnsi;
const bool is64 = BPF_CLASS(code) == BPF_ALU64;
const bool dstk = is_on_stack(insn->dst_reg);
const bool sstk = is_on_stack(insn->src_reg);
u8 rd, rt, rm, rn;
s32 jmp_offset;
#define check_imm(bits, imm) do { \
if ((((imm) > 0) && ((imm) >> (bits))) || \
(((imm) < 0) && (~(imm) >> (bits)))) { \
pr_info("[%2d] imm=%d(0x%x) out of range\n", \
i, imm, imm); \
return -EINVAL; \
} \
} while (0)
#define check_imm24(imm) check_imm(24, imm)
switch (code) {
case BPF_ALU | BPF_MOV | BPF_K:
case BPF_ALU | BPF_MOV | BPF_X:
case BPF_ALU64 | BPF_MOV | BPF_K:
case BPF_ALU64 | BPF_MOV | BPF_X:
switch (BPF_SRC(code)) {
case BPF_X:
emit_a32_mov_r64(is64, dst, src, dstk, sstk, ctx);
break;
case BPF_K:
emit_a32_mov_i64(is64, dst, imm, dstk, ctx);
break;
}
break;
case BPF_ALU | BPF_ADD | BPF_K:
case BPF_ALU | BPF_ADD | BPF_X:
case BPF_ALU | BPF_SUB | BPF_K:
case BPF_ALU | BPF_SUB | BPF_X:
case BPF_ALU | BPF_OR | BPF_K:
case BPF_ALU | BPF_OR | BPF_X:
case BPF_ALU | BPF_AND | BPF_K:
case BPF_ALU | BPF_AND | BPF_X:
case BPF_ALU | BPF_XOR | BPF_K:
case BPF_ALU | BPF_XOR | BPF_X:
case BPF_ALU | BPF_MUL | BPF_K:
case BPF_ALU | BPF_MUL | BPF_X:
case BPF_ALU | BPF_LSH | BPF_X:
case BPF_ALU | BPF_RSH | BPF_X:
case BPF_ALU | BPF_ARSH | BPF_K:
case BPF_ALU | BPF_ARSH | BPF_X:
case BPF_ALU64 | BPF_ADD | BPF_K:
case BPF_ALU64 | BPF_ADD | BPF_X:
case BPF_ALU64 | BPF_SUB | BPF_K:
case BPF_ALU64 | BPF_SUB | BPF_X:
case BPF_ALU64 | BPF_OR | BPF_K:
case BPF_ALU64 | BPF_OR | BPF_X:
case BPF_ALU64 | BPF_AND | BPF_K:
case BPF_ALU64 | BPF_AND | BPF_X:
case BPF_ALU64 | BPF_XOR | BPF_K:
case BPF_ALU64 | BPF_XOR | BPF_X:
switch (BPF_SRC(code)) {
case BPF_X:
emit_a32_alu_r64(is64, dst, src, dstk, sstk,
ctx, BPF_OP(code));
break;
case BPF_K:
emit_a32_mov_i64(is64, tmp2, imm, false, ctx);
emit_a32_alu_r64(is64, dst, tmp2, dstk, false,
ctx, BPF_OP(code));
break;
}
break;
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU | BPF_DIV | BPF_X:
case BPF_ALU | BPF_MOD | BPF_K:
case BPF_ALU | BPF_MOD | BPF_X:
rt = src_lo;
rd = dstk ? tmp2[1] : dst_lo;
if (dstk)
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
switch (BPF_SRC(code)) {
case BPF_X:
rt = sstk ? tmp2[0] : rt;
if (sstk)
emit(ARM_LDR_I(rt, ARM_SP, STACK_VAR(src_lo)),
ctx);
break;
case BPF_K:
rt = tmp2[0];
emit_a32_mov_i(rt, imm, false, ctx);
break;
}
emit_udivmod(rd, rd, rt, ctx, BPF_OP(code));
if (dstk)
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit_a32_mov_i(dst_hi, 0, dstk, ctx);
break;
case BPF_ALU64 | BPF_DIV | BPF_K:
case BPF_ALU64 | BPF_DIV | BPF_X:
case BPF_ALU64 | BPF_MOD | BPF_K:
case BPF_ALU64 | BPF_MOD | BPF_X:
goto notyet;
case BPF_ALU | BPF_RSH | BPF_K:
case BPF_ALU | BPF_LSH | BPF_K:
if (unlikely(imm > 31))
return -EINVAL;
if (imm)
emit_a32_alu_i(dst_lo, imm, dstk, ctx, BPF_OP(code));
emit_a32_mov_i(dst_hi, 0, dstk, ctx);
break;
case BPF_ALU64 | BPF_LSH | BPF_K:
if (unlikely(imm > 63))
return -EINVAL;
emit_a32_lsh_i64(dst, dstk, imm, ctx);
break;
case BPF_ALU64 | BPF_RSH | BPF_K:
if (unlikely(imm > 63))
return -EINVAL;
emit_a32_lsr_i64(dst, dstk, imm, ctx);
break;
case BPF_ALU64 | BPF_LSH | BPF_X:
emit_a32_lsh_r64(dst, src, dstk, sstk, ctx);
break;
case BPF_ALU64 | BPF_RSH | BPF_X:
emit_a32_lsr_r64(dst, src, dstk, sstk, ctx);
break;
case BPF_ALU64 | BPF_ARSH | BPF_X:
emit_a32_arsh_r64(dst, src, dstk, sstk, ctx);
break;
case BPF_ALU64 | BPF_ARSH | BPF_K:
if (unlikely(imm > 63))
return -EINVAL;
emit_a32_arsh_i64(dst, dstk, imm, ctx);
break;
case BPF_ALU | BPF_NEG:
emit_a32_alu_i(dst_lo, 0, dstk, ctx, BPF_OP(code));
emit_a32_mov_i(dst_hi, 0, dstk, ctx);
break;
case BPF_ALU64 | BPF_NEG:
emit_a32_neg64(dst, dstk, ctx);
break;
case BPF_ALU64 | BPF_MUL | BPF_X:
case BPF_ALU64 | BPF_MUL | BPF_K:
switch (BPF_SRC(code)) {
case BPF_X:
emit_a32_mul_r64(dst, src, dstk, sstk, ctx);
break;
case BPF_K:
emit_a32_mov_i64(is64, tmp2, imm, false, ctx);
emit_a32_mul_r64(dst, tmp2, dstk, false, ctx);
break;
}
break;
case BPF_ALU | BPF_END | BPF_FROM_LE:
case BPF_ALU | BPF_END | BPF_FROM_BE:
rd = dstk ? tmp[0] : dst_hi;
rt = dstk ? tmp[1] : dst_lo;
if (dstk) {
emit(ARM_LDR_I(rt, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
if (BPF_SRC(code) == BPF_FROM_LE)
goto emit_bswap_uxt;
switch (imm) {
case 16:
emit_rev16(rt, rt, ctx);
goto emit_bswap_uxt;
case 32:
emit_rev32(rt, rt, ctx);
goto emit_bswap_uxt;
case 64:
ctx->seen |= SEEN_CALL;
emit_rev32(ARM_LR, rt, ctx);
emit_rev32(rt, rd, ctx);
emit(ARM_MOV_R(rd, ARM_LR), ctx);
break;
}
goto exit;
emit_bswap_uxt:
switch (imm) {
case 16:
#if __LINUX_ARM_ARCH__ < 6
emit_a32_mov_i(tmp2[1], 0xffff, false, ctx);
emit(ARM_AND_R(rt, rt, tmp2[1]), ctx);
#else
emit(ARM_UXTH(rt, rt), ctx);
#endif
emit(ARM_EOR_R(rd, rd, rd), ctx);
break;
case 32:
emit(ARM_EOR_R(rd, rd, rd), ctx);
break;
case 64:
break;
}
exit:
if (dstk) {
emit(ARM_STR_I(rt, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_STR_I(rd, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
break;
case BPF_LD | BPF_IMM | BPF_DW:
{
const struct bpf_insn insn1 = insn[1];
u32 hi, lo = imm;
hi = insn1.imm;
emit_a32_mov_i(dst_lo, lo, dstk, ctx);
emit_a32_mov_i(dst_hi, hi, dstk, ctx);
return 1;
}
case BPF_LDX | BPF_MEM | BPF_W:
case BPF_LDX | BPF_MEM | BPF_H:
case BPF_LDX | BPF_MEM | BPF_B:
case BPF_LDX | BPF_MEM | BPF_DW:
rn = sstk ? tmp2[1] : src_lo;
if (sstk)
emit(ARM_LDR_I(rn, ARM_SP, STACK_VAR(src_lo)), ctx);
switch (BPF_SIZE(code)) {
case BPF_W:
case BPF_H:
case BPF_B:
emit_ldx_r(dst_lo, rn, dstk, off, ctx, BPF_SIZE(code));
emit_a32_mov_i(dst_hi, 0, dstk, ctx);
break;
case BPF_DW:
emit_ldx_r(dst_lo, rn, dstk, off, ctx, BPF_W);
emit_ldx_r(dst_hi, rn, dstk, off+4, ctx, BPF_W);
break;
}
break;
case BPF_LD | BPF_ABS | BPF_W:
case BPF_LD | BPF_ABS | BPF_H:
case BPF_LD | BPF_ABS | BPF_B:
case BPF_LD | BPF_IND | BPF_W:
case BPF_LD | BPF_IND | BPF_H:
case BPF_LD | BPF_IND | BPF_B:
{
const u8 r4 = bpf2a32[BPF_REG_6][1];
const u8 r0 = bpf2a32[BPF_REG_0][1];
const u8 r1 = bpf2a32[BPF_REG_0][0];
const u8 r2 = bpf2a32[BPF_REG_1][1];
const u8 r3 = bpf2a32[BPF_REG_1][0];
const u8 r6 = bpf2a32[TMP_REG_1][1];
int size;
emit(ARM_MOV_R(r0, r4), ctx);
emit_a32_mov_i(r1, imm, false, ctx);
if (BPF_MODE(code) == BPF_IND)
emit_a32_alu_r(r1, src_lo, false, sstk, ctx,
false, false, BPF_ADD);
switch (BPF_SIZE(code)) {
case BPF_W:
size = 4;
break;
case BPF_H:
size = 2;
break;
case BPF_B:
size = 1;
break;
default:
return -EINVAL;
}
emit_a32_mov_i(r2, size, false, ctx);
emit(ARM_ADD_I(r3, ARM_SP, imm8m(SKB_BUFFER)), ctx);
emit_a32_mov_i(r6, (unsigned int)bpf_load_pointer, false, ctx);
emit_blx_r(r6, ctx);
emit(ARM_EOR_R(r1, r1, r1), ctx);
emit(ARM_CMP_I(r0, 0), ctx);
jmp_offset = epilogue_offset(ctx);
check_imm24(jmp_offset);
_emit(ARM_COND_EQ, ARM_B(jmp_offset), ctx);
switch (BPF_SIZE(code)) {
case BPF_W:
emit(ARM_LDR_I(r0, r0, 0), ctx);
emit_rev32(r0, r0, ctx);
break;
case BPF_H:
emit(ARM_LDRH_I(r0, r0, 0), ctx);
emit_rev16(r0, r0, ctx);
break;
case BPF_B:
emit(ARM_LDRB_I(r0, r0, 0), ctx);
break;
}
break;
}
case BPF_ST | BPF_MEM | BPF_W:
case BPF_ST | BPF_MEM | BPF_H:
case BPF_ST | BPF_MEM | BPF_B:
case BPF_ST | BPF_MEM | BPF_DW:
switch (BPF_SIZE(code)) {
case BPF_DW:
emit_a32_mov_i64(true, tmp2, imm, false, ctx);
emit_str_r(dst_lo, tmp2[1], dstk, off, ctx, BPF_W);
emit_str_r(dst_lo, tmp2[0], dstk, off+4, ctx, BPF_W);
break;
case BPF_W:
case BPF_H:
case BPF_B:
emit_a32_mov_i(tmp2[1], imm, false, ctx);
emit_str_r(dst_lo, tmp2[1], dstk, off, ctx,
BPF_SIZE(code));
break;
}
break;
case BPF_STX | BPF_XADD | BPF_W:
case BPF_STX | BPF_XADD | BPF_DW:
goto notyet;
case BPF_STX | BPF_MEM | BPF_W:
case BPF_STX | BPF_MEM | BPF_H:
case BPF_STX | BPF_MEM | BPF_B:
case BPF_STX | BPF_MEM | BPF_DW:
{
u8 sz = BPF_SIZE(code);
rn = sstk ? tmp2[1] : src_lo;
rm = sstk ? tmp2[0] : src_hi;
if (sstk) {
emit(ARM_LDR_I(rn, ARM_SP, STACK_VAR(src_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(src_hi)), ctx);
}
if (BPF_SIZE(code) == BPF_DW) {
emit_str_r(dst_lo, rn, dstk, off, ctx, BPF_W);
emit_str_r(dst_lo, rm, dstk, off+4, ctx, BPF_W);
} else {
emit_str_r(dst_lo, rn, dstk, off, ctx, sz);
}
break;
}
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JNE | BPF_X:
case BPF_JMP | BPF_JSGT | BPF_X:
case BPF_JMP | BPF_JSGE | BPF_X:
case BPF_JMP | BPF_JSET | BPF_X:
case BPF_JMP | BPF_JLE | BPF_X:
case BPF_JMP | BPF_JLT | BPF_X:
case BPF_JMP | BPF_JSLT | BPF_X:
case BPF_JMP | BPF_JSLE | BPF_X:
rm = sstk ? tmp2[0] : src_hi;
rn = sstk ? tmp2[1] : src_lo;
if (sstk) {
emit(ARM_LDR_I(rn, ARM_SP, STACK_VAR(src_lo)), ctx);
emit(ARM_LDR_I(rm, ARM_SP, STACK_VAR(src_hi)), ctx);
}
goto go_jmp;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JNE | BPF_K:
case BPF_JMP | BPF_JSGT | BPF_K:
case BPF_JMP | BPF_JSGE | BPF_K:
case BPF_JMP | BPF_JSET | BPF_K:
case BPF_JMP | BPF_JLT | BPF_K:
case BPF_JMP | BPF_JLE | BPF_K:
case BPF_JMP | BPF_JSLT | BPF_K:
case BPF_JMP | BPF_JSLE | BPF_K:
if (off == 0)
break;
rm = tmp2[0];
rn = tmp2[1];
emit_a32_mov_i64(true, tmp2, imm, false, ctx);
go_jmp:
rd = dstk ? tmp[0] : dst_hi;
rt = dstk ? tmp[1] : dst_lo;
if (dstk) {
emit(ARM_LDR_I(rt, ARM_SP, STACK_VAR(dst_lo)), ctx);
emit(ARM_LDR_I(rd, ARM_SP, STACK_VAR(dst_hi)), ctx);
}
emit_ar_r(rd, rt, rm, rn, ctx, BPF_OP(code));
jmp_offset = bpf2a32_offset(i+off, i, ctx);
switch (BPF_OP(code)) {
case BPF_JNE:
case BPF_JSET:
_emit(ARM_COND_NE, ARM_B(jmp_offset), ctx);
break;
case BPF_JEQ:
_emit(ARM_COND_EQ, ARM_B(jmp_offset), ctx);
break;
case BPF_JGT:
_emit(ARM_COND_HI, ARM_B(jmp_offset), ctx);
break;
case BPF_JGE:
_emit(ARM_COND_CS, ARM_B(jmp_offset), ctx);
break;
case BPF_JSGT:
_emit(ARM_COND_LT, ARM_B(jmp_offset), ctx);
break;
case BPF_JSGE:
_emit(ARM_COND_GE, ARM_B(jmp_offset), ctx);
break;
case BPF_JLE:
_emit(ARM_COND_LS, ARM_B(jmp_offset), ctx);
break;
case BPF_JLT:
_emit(ARM_COND_CC, ARM_B(jmp_offset), ctx);
break;
case BPF_JSLT:
_emit(ARM_COND_LT, ARM_B(jmp_offset), ctx);
break;
case BPF_JSLE:
_emit(ARM_COND_GE, ARM_B(jmp_offset), ctx);
break;
}
break;
case BPF_JMP | BPF_JA:
{
if (off == 0)
break;
jmp_offset = bpf2a32_offset(i+off, i, ctx);
check_imm24(jmp_offset);
emit(ARM_B(jmp_offset), ctx);
break;
}
case BPF_JMP | BPF_TAIL_CALL:
if (emit_bpf_tail_call(ctx))
return -EFAULT;
break;
case BPF_JMP | BPF_CALL:
{
const u8 *r0 = bpf2a32[BPF_REG_0];
const u8 *r1 = bpf2a32[BPF_REG_1];
const u8 *r2 = bpf2a32[BPF_REG_2];
const u8 *r3 = bpf2a32[BPF_REG_3];
const u8 *r4 = bpf2a32[BPF_REG_4];
const u8 *r5 = bpf2a32[BPF_REG_5];
const u32 func = (u32)__bpf_call_base + (u32)imm;
emit_a32_mov_r64(true, r0, r1, false, false, ctx);
emit_a32_mov_r64(true, r1, r2, false, true, ctx);
emit_push_r64(r5, 0, ctx);
emit_push_r64(r4, 8, ctx);
emit_push_r64(r3, 16, ctx);
emit_a32_mov_i(tmp[1], func, false, ctx);
emit_blx_r(tmp[1], ctx);
emit(ARM_ADD_I(ARM_SP, ARM_SP, imm8m(24)), ctx);
break;
}
case BPF_JMP | BPF_EXIT:
if (i == ctx->prog->len - 1)
break;
jmp_offset = epilogue_offset(ctx);
check_imm24(jmp_offset);
emit(ARM_B(jmp_offset), ctx);
break;
notyet:
pr_info_once("*** NOT YET: opcode %02x ***\n", code);
return -EFAULT;
default:
pr_err_once("unknown opcode %02x\n", code);
return -EINVAL;
}
if (ctx->flags & FLAG_IMM_OVERFLOW)
return -1;
return 0;
}
static int build_body(struct jit_ctx *ctx)
{
const struct bpf_prog *prog = ctx->prog;
unsigned int i;
for (i = 0; i < prog->len; i++) {
const struct bpf_insn *insn = &(prog->insnsi[i]);
int ret;
ret = build_insn(insn, ctx);
if (ret > 0) {
i++;
if (ctx->target == NULL)
ctx->offsets[i] = ctx->idx;
continue;
}
if (ctx->target == NULL)
ctx->offsets[i] = ctx->idx;
if (ret)
return ret;
}
return 0;
}
static int validate_code(struct jit_ctx *ctx)
{
int i;
for (i = 0; i < ctx->idx; i++) {
if (ctx->target[i] == __opcode_to_mem_arm(ARM_INST_UDF))
return -1;
}
return 0;
}
void bpf_jit_compile(struct bpf_prog *prog)
{
}
struct bpf_prog *bpf_int_jit_compile(struct bpf_prog *prog)
{
struct bpf_prog *tmp, *orig_prog = prog;
struct bpf_binary_header *header;
bool tmp_blinded = false;
struct jit_ctx ctx;
unsigned int tmp_idx;
unsigned int image_size;
u8 *image_ptr;
if (!bpf_jit_enable)
return orig_prog;
tmp = bpf_jit_blind_constants(prog);
if (IS_ERR(tmp))
return orig_prog;
if (tmp != prog) {
tmp_blinded = true;
prog = tmp;
}
memset(&ctx, 0, sizeof(ctx));
ctx.prog = prog;
ctx.offsets = kcalloc(prog->len, sizeof(int), GFP_KERNEL);
if (ctx.offsets == NULL) {
prog = orig_prog;
goto out;
}
if (build_body(&ctx)) {
prog = orig_prog;
goto out_off;
}
tmp_idx = ctx.idx;
build_prologue(&ctx);
ctx.prologue_bytes = (ctx.idx - tmp_idx) * 4;
ctx.epilogue_offset = ctx.idx;
#if __LINUX_ARM_ARCH__ < 7
tmp_idx = ctx.idx;
build_epilogue(&ctx);
ctx.epilogue_bytes = (ctx.idx - tmp_idx) * 4;
ctx.idx += ctx.imm_count;
if (ctx.imm_count) {
ctx.imms = kcalloc(ctx.imm_count, sizeof(u32), GFP_KERNEL);
if (ctx.imms == NULL) {
prog = orig_prog;
goto out_off;
}
}
#else
build_epilogue(&ctx);
#endif
image_size = sizeof(u32) * ctx.idx;
header = bpf_jit_binary_alloc(image_size, &image_ptr,
sizeof(u32), jit_fill_hole);
if (header == NULL) {
prog = orig_prog;
goto out_imms;
}
ctx.target = (u32 *) image_ptr;
ctx.idx = 0;
build_prologue(&ctx);
if (build_body(&ctx) < 0) {
image_ptr = NULL;
bpf_jit_binary_free(header);
prog = orig_prog;
goto out_imms;
}
build_epilogue(&ctx);
if (validate_code(&ctx)) {
image_ptr = NULL;
bpf_jit_binary_free(header);
prog = orig_prog;
goto out_imms;
}
flush_icache_range((u32)header, (u32)(ctx.target + ctx.idx));
if (bpf_jit_enable > 1)
bpf_jit_dump(prog->len, image_size, 2, ctx.target);
set_memory_ro((unsigned long)header, header->pages);
prog->bpf_func = (void *)ctx.target;
prog->jited = 1;
prog->jited_len = image_size;
out_imms:
#if __LINUX_ARM_ARCH__ < 7
if (ctx.imm_count)
kfree(ctx.imms);
#endif
out_off:
kfree(ctx.offsets);
out:
if (tmp_blinded)
bpf_jit_prog_release_other(prog, prog == orig_prog ?
tmp : orig_prog);
return prog;
}
