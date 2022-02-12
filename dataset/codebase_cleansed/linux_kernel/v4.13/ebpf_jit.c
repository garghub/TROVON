static void set_reg_val_type(u64 *rvt, int reg, enum reg_val_type type)
{
*rvt &= ~(7ull << (reg * 3));
*rvt |= ((u64)type << (reg * 3));
}
static enum reg_val_type get_reg_val_type(const struct jit_ctx *ctx,
int index, int reg)
{
return (ctx->reg_val_types[index] >> (reg * 3)) & 7;
}
static unsigned int j_target(struct jit_ctx *ctx, int target_idx)
{
unsigned long target_va, base_va;
unsigned int r;
if (!ctx->target)
return 0;
base_va = (unsigned long)ctx->target;
target_va = base_va + (ctx->offsets[target_idx] & ~OFFSETS_B_CONV);
if ((base_va & ~0x0ffffffful) != (target_va & ~0x0ffffffful))
return (unsigned int)-1;
r = target_va & 0x0ffffffful;
return r;
}
static u32 b_imm(unsigned int tgt, struct jit_ctx *ctx)
{
if (!ctx->gen_b_offsets)
return 0;
return (ctx->offsets[tgt] & ~OFFSETS_B_CONV) -
(ctx->idx * 4) - 4;
}
int ebpf_to_mips_reg(struct jit_ctx *ctx, const struct bpf_insn *insn,
enum which_ebpf_reg w)
{
int ebpf_reg = (w == src_reg || w == src_reg_no_fp) ?
insn->src_reg : insn->dst_reg;
switch (ebpf_reg) {
case BPF_REG_0:
return MIPS_R_V0;
case BPF_REG_1:
return MIPS_R_A0;
case BPF_REG_2:
return MIPS_R_A1;
case BPF_REG_3:
return MIPS_R_A2;
case BPF_REG_4:
return MIPS_R_A3;
case BPF_REG_5:
return MIPS_R_A4;
case BPF_REG_6:
ctx->flags |= EBPF_SAVE_S0;
return MIPS_R_S0;
case BPF_REG_7:
ctx->flags |= EBPF_SAVE_S1;
return MIPS_R_S1;
case BPF_REG_8:
ctx->flags |= EBPF_SAVE_S2;
return MIPS_R_S2;
case BPF_REG_9:
ctx->flags |= EBPF_SAVE_S3;
return MIPS_R_S3;
case BPF_REG_10:
if (w == dst_reg || w == src_reg_no_fp)
goto bad_reg;
ctx->flags |= EBPF_SEEN_FP;
return MIPS_R_ZERO;
case BPF_REG_AX:
return MIPS_R_T4;
default:
bad_reg:
WARN(1, "Illegal bpf reg: %d\n", ebpf_reg);
return -EINVAL;
}
}
static int gen_int_prologue(struct jit_ctx *ctx)
{
int stack_adjust = 0;
int store_offset;
int locals_size;
if (ctx->flags & EBPF_SAVE_RA)
stack_adjust += 16;
if (ctx->flags & EBPF_SAVE_S0)
stack_adjust += 8;
if (ctx->flags & EBPF_SAVE_S1)
stack_adjust += 8;
if (ctx->flags & EBPF_SAVE_S2)
stack_adjust += 8;
if (ctx->flags & EBPF_SAVE_S3)
stack_adjust += 8;
if (ctx->flags & EBPF_SAVE_S4)
stack_adjust += 8;
BUILD_BUG_ON(MAX_BPF_STACK & 7);
locals_size = (ctx->flags & EBPF_SEEN_FP) ? MAX_BPF_STACK : 0;
stack_adjust += locals_size;
ctx->tmp_offset = locals_size;
ctx->stack_size = stack_adjust;
emit_instr(ctx, daddiu, MIPS_R_V1, MIPS_R_ZERO, MAX_TAIL_CALL_CNT);
if (stack_adjust)
emit_instr(ctx, daddiu, MIPS_R_SP, MIPS_R_SP, -stack_adjust);
else
return 0;
store_offset = stack_adjust - 8;
if (ctx->flags & EBPF_SAVE_RA) {
emit_instr(ctx, sd, MIPS_R_RA, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S0) {
emit_instr(ctx, sd, MIPS_R_S0, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S1) {
emit_instr(ctx, sd, MIPS_R_S1, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S2) {
emit_instr(ctx, sd, MIPS_R_S2, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S3) {
emit_instr(ctx, sd, MIPS_R_S3, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S4) {
emit_instr(ctx, sd, MIPS_R_S4, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if ((ctx->flags & EBPF_SEEN_TC) && !(ctx->flags & EBPF_TCC_IN_V1))
emit_instr(ctx, daddu, MIPS_R_S4, MIPS_R_V1, MIPS_R_ZERO);
return 0;
}
static int build_int_epilogue(struct jit_ctx *ctx, int dest_reg)
{
const struct bpf_prog *prog = ctx->skf;
int stack_adjust = ctx->stack_size;
int store_offset = stack_adjust - 8;
int r0 = MIPS_R_V0;
if (dest_reg == MIPS_R_RA &&
get_reg_val_type(ctx, prog->len, BPF_REG_0) == REG_32BIT_ZERO_EX)
emit_instr(ctx, sll, r0, r0, 0);
if (ctx->flags & EBPF_SAVE_RA) {
emit_instr(ctx, ld, MIPS_R_RA, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S0) {
emit_instr(ctx, ld, MIPS_R_S0, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S1) {
emit_instr(ctx, ld, MIPS_R_S1, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S2) {
emit_instr(ctx, ld, MIPS_R_S2, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S3) {
emit_instr(ctx, ld, MIPS_R_S3, store_offset, MIPS_R_SP);
store_offset -= 8;
}
if (ctx->flags & EBPF_SAVE_S4) {
emit_instr(ctx, ld, MIPS_R_S4, store_offset, MIPS_R_SP);
store_offset -= 8;
}
emit_instr(ctx, jr, dest_reg);
if (stack_adjust)
emit_instr(ctx, daddiu, MIPS_R_SP, MIPS_R_SP, stack_adjust);
else
emit_instr(ctx, nop);
return 0;
}
static void gen_imm_to_reg(const struct bpf_insn *insn, int reg,
struct jit_ctx *ctx)
{
if (insn->imm >= S16_MIN && insn->imm <= S16_MAX) {
emit_instr(ctx, addiu, reg, MIPS_R_ZERO, insn->imm);
} else {
int lower = (s16)(insn->imm & 0xffff);
int upper = insn->imm - lower;
emit_instr(ctx, lui, reg, upper >> 16);
emit_instr(ctx, addiu, reg, reg, lower);
}
}
static int gen_imm_insn(const struct bpf_insn *insn, struct jit_ctx *ctx,
int idx)
{
int upper_bound, lower_bound;
int dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
switch (BPF_OP(insn->code)) {
case BPF_MOV:
case BPF_ADD:
upper_bound = S16_MAX;
lower_bound = S16_MIN;
break;
case BPF_SUB:
upper_bound = -(int)S16_MIN;
lower_bound = -(int)S16_MAX;
break;
case BPF_AND:
case BPF_OR:
case BPF_XOR:
upper_bound = 0xffff;
lower_bound = 0;
break;
case BPF_RSH:
case BPF_LSH:
case BPF_ARSH:
upper_bound = S32_MAX;
lower_bound = S32_MIN;
break;
default:
return -EINVAL;
}
if (BPF_CLASS(insn->code) == BPF_ALU64 &&
BPF_OP(insn->code) != BPF_MOV &&
get_reg_val_type(ctx, idx, insn->dst_reg) == REG_32BIT)
emit_instr(ctx, dinsu, dst, MIPS_R_ZERO, 32, 32);
if (BPF_CLASS(insn->code) == BPF_ALU &&
BPF_OP(insn->code) != BPF_LSH &&
BPF_OP(insn->code) != BPF_MOV &&
get_reg_val_type(ctx, idx, insn->dst_reg) != REG_32BIT)
emit_instr(ctx, sll, dst, dst, 0);
if (insn->imm >= lower_bound && insn->imm <= upper_bound) {
switch (BPF_OP(insn->code) | BPF_CLASS(insn->code)) {
case BPF_ALU64 | BPF_MOV:
emit_instr(ctx, daddiu, dst, MIPS_R_ZERO, insn->imm);
break;
case BPF_ALU64 | BPF_AND:
case BPF_ALU | BPF_AND:
emit_instr(ctx, andi, dst, dst, insn->imm);
break;
case BPF_ALU64 | BPF_OR:
case BPF_ALU | BPF_OR:
emit_instr(ctx, ori, dst, dst, insn->imm);
break;
case BPF_ALU64 | BPF_XOR:
case BPF_ALU | BPF_XOR:
emit_instr(ctx, xori, dst, dst, insn->imm);
break;
case BPF_ALU64 | BPF_ADD:
emit_instr(ctx, daddiu, dst, dst, insn->imm);
break;
case BPF_ALU64 | BPF_SUB:
emit_instr(ctx, daddiu, dst, dst, -insn->imm);
break;
case BPF_ALU64 | BPF_RSH:
emit_instr(ctx, dsrl_safe, dst, dst, insn->imm & 0x3f);
break;
case BPF_ALU | BPF_RSH:
emit_instr(ctx, srl, dst, dst, insn->imm & 0x1f);
break;
case BPF_ALU64 | BPF_LSH:
emit_instr(ctx, dsll_safe, dst, dst, insn->imm & 0x3f);
break;
case BPF_ALU | BPF_LSH:
emit_instr(ctx, sll, dst, dst, insn->imm & 0x1f);
break;
case BPF_ALU64 | BPF_ARSH:
emit_instr(ctx, dsra_safe, dst, dst, insn->imm & 0x3f);
break;
case BPF_ALU | BPF_ARSH:
emit_instr(ctx, sra, dst, dst, insn->imm & 0x1f);
break;
case BPF_ALU | BPF_MOV:
emit_instr(ctx, addiu, dst, MIPS_R_ZERO, insn->imm);
break;
case BPF_ALU | BPF_ADD:
emit_instr(ctx, addiu, dst, dst, insn->imm);
break;
case BPF_ALU | BPF_SUB:
emit_instr(ctx, addiu, dst, dst, -insn->imm);
break;
default:
return -EINVAL;
}
} else {
if (BPF_OP(insn->code) == BPF_MOV) {
gen_imm_to_reg(insn, dst, ctx);
} else {
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
switch (BPF_OP(insn->code) | BPF_CLASS(insn->code)) {
case BPF_ALU64 | BPF_AND:
case BPF_ALU | BPF_AND:
emit_instr(ctx, and, dst, dst, MIPS_R_AT);
break;
case BPF_ALU64 | BPF_OR:
case BPF_ALU | BPF_OR:
emit_instr(ctx, or, dst, dst, MIPS_R_AT);
break;
case BPF_ALU64 | BPF_XOR:
case BPF_ALU | BPF_XOR:
emit_instr(ctx, xor, dst, dst, MIPS_R_AT);
break;
case BPF_ALU64 | BPF_ADD:
emit_instr(ctx, daddu, dst, dst, MIPS_R_AT);
break;
case BPF_ALU64 | BPF_SUB:
emit_instr(ctx, dsubu, dst, dst, MIPS_R_AT);
break;
case BPF_ALU | BPF_ADD:
emit_instr(ctx, addu, dst, dst, MIPS_R_AT);
break;
case BPF_ALU | BPF_SUB:
emit_instr(ctx, subu, dst, dst, MIPS_R_AT);
break;
default:
return -EINVAL;
}
}
}
return 0;
}
static void * __must_check
ool_skb_header_pointer(const struct sk_buff *skb, int offset,
int len, void *buffer)
{
return skb_header_pointer(skb, offset, len, buffer);
}
static int size_to_len(const struct bpf_insn *insn)
{
switch (BPF_SIZE(insn->code)) {
case BPF_B:
return 1;
case BPF_H:
return 2;
case BPF_W:
return 4;
case BPF_DW:
return 8;
}
return 0;
}
static void emit_const_to_reg(struct jit_ctx *ctx, int dst, u64 value)
{
if (value >= 0xffffffffffff8000ull || value < 0x8000ull) {
emit_instr(ctx, daddiu, dst, MIPS_R_ZERO, (int)value);
} else if (value >= 0xffffffff80000000ull ||
(value < 0x80000000 && value > 0xffff)) {
emit_instr(ctx, lui, dst, (s32)(s16)(value >> 16));
emit_instr(ctx, ori, dst, dst, (unsigned int)(value & 0xffff));
} else {
int i;
bool seen_part = false;
int needed_shift = 0;
for (i = 0; i < 4; i++) {
u64 part = (value >> (16 * (3 - i))) & 0xffff;
if (seen_part && needed_shift > 0 && (part || i == 3)) {
emit_instr(ctx, dsll_safe, dst, dst, needed_shift);
needed_shift = 0;
}
if (part) {
if (i == 0 || (!seen_part && i < 3 && part < 0x8000)) {
emit_instr(ctx, lui, dst, (s32)(s16)part);
needed_shift = -16;
} else {
emit_instr(ctx, ori, dst,
seen_part ? dst : MIPS_R_ZERO,
(unsigned int)part);
}
seen_part = true;
}
if (seen_part)
needed_shift += 16;
}
}
}
static int emit_bpf_tail_call(struct jit_ctx *ctx, int this_idx)
{
int off, b_off;
ctx->flags |= EBPF_SEEN_TC;
off = offsetof(struct bpf_array, map.max_entries);
emit_instr(ctx, lwu, MIPS_R_T5, off, MIPS_R_A1);
emit_instr(ctx, sltu, MIPS_R_AT, MIPS_R_T5, MIPS_R_A2);
b_off = b_imm(this_idx + 1, ctx);
emit_instr(ctx, bne, MIPS_R_AT, MIPS_R_ZERO, b_off);
emit_instr(ctx, daddiu, MIPS_R_T5,
(ctx->flags & EBPF_TCC_IN_V1) ? MIPS_R_V1 : MIPS_R_S4, -1);
b_off = b_imm(this_idx + 1, ctx);
emit_instr(ctx, bltz, MIPS_R_T5, b_off);
emit_instr(ctx, dsll, MIPS_R_T8, MIPS_R_A2, 3);
emit_instr(ctx, daddu, MIPS_R_T8, MIPS_R_T8, MIPS_R_A1);
off = offsetof(struct bpf_array, ptrs);
emit_instr(ctx, ld, MIPS_R_AT, off, MIPS_R_T8);
b_off = b_imm(this_idx + 1, ctx);
emit_instr(ctx, beq, MIPS_R_AT, MIPS_R_ZERO, b_off);
emit_instr(ctx, nop);
off = offsetof(struct bpf_prog, bpf_func);
emit_instr(ctx, ld, MIPS_R_T9, off, MIPS_R_AT);
emit_instr(ctx, daddu, MIPS_R_V1, MIPS_R_T5, MIPS_R_ZERO);
emit_instr(ctx, daddiu, MIPS_R_T9, MIPS_R_T9, 4);
return build_int_epilogue(ctx, MIPS_R_T9);
}
static bool use_bbit_insns(void)
{
switch (current_cpu_type()) {
case CPU_CAVIUM_OCTEON:
case CPU_CAVIUM_OCTEON_PLUS:
case CPU_CAVIUM_OCTEON2:
case CPU_CAVIUM_OCTEON3:
return true;
default:
return false;
}
}
static bool is_bad_offset(int b_off)
{
return b_off > 0x1ffff || b_off < -0x20000;
}
static int build_one_insn(const struct bpf_insn *insn, struct jit_ctx *ctx,
int this_idx, int exit_idx)
{
int src, dst, r, td, ts, mem_off, b_off;
bool need_swap, did_move, cmp_eq;
unsigned int target;
u64 t64;
s64 t64s;
switch (insn->code) {
case BPF_ALU64 | BPF_ADD | BPF_K:
case BPF_ALU64 | BPF_SUB | BPF_K:
case BPF_ALU64 | BPF_OR | BPF_K:
case BPF_ALU64 | BPF_AND | BPF_K:
case BPF_ALU64 | BPF_LSH | BPF_K:
case BPF_ALU64 | BPF_RSH | BPF_K:
case BPF_ALU64 | BPF_XOR | BPF_K:
case BPF_ALU64 | BPF_ARSH | BPF_K:
case BPF_ALU64 | BPF_MOV | BPF_K:
case BPF_ALU | BPF_MOV | BPF_K:
case BPF_ALU | BPF_ADD | BPF_K:
case BPF_ALU | BPF_SUB | BPF_K:
case BPF_ALU | BPF_OR | BPF_K:
case BPF_ALU | BPF_AND | BPF_K:
case BPF_ALU | BPF_LSH | BPF_K:
case BPF_ALU | BPF_RSH | BPF_K:
case BPF_ALU | BPF_XOR | BPF_K:
case BPF_ALU | BPF_ARSH | BPF_K:
r = gen_imm_insn(insn, ctx, this_idx);
if (r < 0)
return r;
break;
case BPF_ALU64 | BPF_MUL | BPF_K:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
if (get_reg_val_type(ctx, this_idx, insn->dst_reg) == REG_32BIT)
emit_instr(ctx, dinsu, dst, MIPS_R_ZERO, 32, 32);
if (insn->imm == 1)
break;
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
emit_instr(ctx, dmultu, MIPS_R_AT, dst);
emit_instr(ctx, mflo, dst);
break;
case BPF_ALU64 | BPF_NEG | BPF_K:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
if (get_reg_val_type(ctx, this_idx, insn->dst_reg) == REG_32BIT)
emit_instr(ctx, dinsu, dst, MIPS_R_ZERO, 32, 32);
emit_instr(ctx, dsubu, dst, MIPS_R_ZERO, dst);
break;
case BPF_ALU | BPF_MUL | BPF_K:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
td = get_reg_val_type(ctx, this_idx, insn->dst_reg);
if (td == REG_64BIT || td == REG_32BIT_ZERO_EX) {
emit_instr(ctx, sll, dst, dst, 0);
}
if (insn->imm == 1)
break;
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
emit_instr(ctx, multu, dst, MIPS_R_AT);
emit_instr(ctx, mflo, dst);
break;
case BPF_ALU | BPF_NEG | BPF_K:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
td = get_reg_val_type(ctx, this_idx, insn->dst_reg);
if (td == REG_64BIT || td == REG_32BIT_ZERO_EX) {
emit_instr(ctx, sll, dst, dst, 0);
}
emit_instr(ctx, subu, dst, MIPS_R_ZERO, dst);
break;
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU | BPF_MOD | BPF_K:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
if (insn->imm == 0) {
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, beq, MIPS_R_ZERO, MIPS_R_ZERO, b_off);
emit_instr(ctx, addu, MIPS_R_V0, MIPS_R_ZERO, MIPS_R_ZERO);
}
td = get_reg_val_type(ctx, this_idx, insn->dst_reg);
if (td == REG_64BIT || td == REG_32BIT_ZERO_EX)
emit_instr(ctx, sll, dst, dst, 0);
if (insn->imm == 1) {
if (BPF_OP(insn->code) == BPF_MOD)
emit_instr(ctx, addu, dst, MIPS_R_ZERO, MIPS_R_ZERO);
break;
}
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
emit_instr(ctx, divu, dst, MIPS_R_AT);
if (BPF_OP(insn->code) == BPF_DIV)
emit_instr(ctx, mflo, dst);
else
emit_instr(ctx, mfhi, dst);
break;
case BPF_ALU64 | BPF_DIV | BPF_K:
case BPF_ALU64 | BPF_MOD | BPF_K:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
if (insn->imm == 0) {
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, beq, MIPS_R_ZERO, MIPS_R_ZERO, b_off);
emit_instr(ctx, addu, MIPS_R_V0, MIPS_R_ZERO, MIPS_R_ZERO);
}
if (get_reg_val_type(ctx, this_idx, insn->dst_reg) == REG_32BIT)
emit_instr(ctx, dinsu, dst, MIPS_R_ZERO, 32, 32);
if (insn->imm == 1) {
if (BPF_OP(insn->code) == BPF_MOD)
emit_instr(ctx, addu, dst, MIPS_R_ZERO, MIPS_R_ZERO);
break;
}
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
emit_instr(ctx, ddivu, dst, MIPS_R_AT);
if (BPF_OP(insn->code) == BPF_DIV)
emit_instr(ctx, mflo, dst);
else
emit_instr(ctx, mfhi, dst);
break;
case BPF_ALU64 | BPF_MOV | BPF_X:
case BPF_ALU64 | BPF_ADD | BPF_X:
case BPF_ALU64 | BPF_SUB | BPF_X:
case BPF_ALU64 | BPF_XOR | BPF_X:
case BPF_ALU64 | BPF_OR | BPF_X:
case BPF_ALU64 | BPF_AND | BPF_X:
case BPF_ALU64 | BPF_MUL | BPF_X:
case BPF_ALU64 | BPF_DIV | BPF_X:
case BPF_ALU64 | BPF_MOD | BPF_X:
case BPF_ALU64 | BPF_LSH | BPF_X:
case BPF_ALU64 | BPF_RSH | BPF_X:
case BPF_ALU64 | BPF_ARSH | BPF_X:
src = ebpf_to_mips_reg(ctx, insn, src_reg);
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (src < 0 || dst < 0)
return -EINVAL;
if (get_reg_val_type(ctx, this_idx, insn->dst_reg) == REG_32BIT)
emit_instr(ctx, dinsu, dst, MIPS_R_ZERO, 32, 32);
did_move = false;
if (insn->src_reg == BPF_REG_10) {
if (BPF_OP(insn->code) == BPF_MOV) {
emit_instr(ctx, daddiu, dst, MIPS_R_SP, MAX_BPF_STACK);
did_move = true;
} else {
emit_instr(ctx, daddiu, MIPS_R_AT, MIPS_R_SP, MAX_BPF_STACK);
src = MIPS_R_AT;
}
} else if (get_reg_val_type(ctx, this_idx, insn->src_reg) == REG_32BIT) {
int tmp_reg = MIPS_R_AT;
if (BPF_OP(insn->code) == BPF_MOV) {
tmp_reg = dst;
did_move = true;
}
emit_instr(ctx, daddu, tmp_reg, src, MIPS_R_ZERO);
emit_instr(ctx, dinsu, tmp_reg, MIPS_R_ZERO, 32, 32);
src = MIPS_R_AT;
}
switch (BPF_OP(insn->code)) {
case BPF_MOV:
if (!did_move)
emit_instr(ctx, daddu, dst, src, MIPS_R_ZERO);
break;
case BPF_ADD:
emit_instr(ctx, daddu, dst, dst, src);
break;
case BPF_SUB:
emit_instr(ctx, dsubu, dst, dst, src);
break;
case BPF_XOR:
emit_instr(ctx, xor, dst, dst, src);
break;
case BPF_OR:
emit_instr(ctx, or, dst, dst, src);
break;
case BPF_AND:
emit_instr(ctx, and, dst, dst, src);
break;
case BPF_MUL:
emit_instr(ctx, dmultu, dst, src);
emit_instr(ctx, mflo, dst);
break;
case BPF_DIV:
case BPF_MOD:
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, beq, src, MIPS_R_ZERO, b_off);
emit_instr(ctx, movz, MIPS_R_V0, MIPS_R_ZERO, src);
emit_instr(ctx, ddivu, dst, src);
if (BPF_OP(insn->code) == BPF_DIV)
emit_instr(ctx, mflo, dst);
else
emit_instr(ctx, mfhi, dst);
break;
case BPF_LSH:
emit_instr(ctx, dsllv, dst, dst, src);
break;
case BPF_RSH:
emit_instr(ctx, dsrlv, dst, dst, src);
break;
case BPF_ARSH:
emit_instr(ctx, dsrav, dst, dst, src);
break;
default:
pr_err("ALU64_REG NOT HANDLED\n");
return -EINVAL;
}
break;
case BPF_ALU | BPF_MOV | BPF_X:
case BPF_ALU | BPF_ADD | BPF_X:
case BPF_ALU | BPF_SUB | BPF_X:
case BPF_ALU | BPF_XOR | BPF_X:
case BPF_ALU | BPF_OR | BPF_X:
case BPF_ALU | BPF_AND | BPF_X:
case BPF_ALU | BPF_MUL | BPF_X:
case BPF_ALU | BPF_DIV | BPF_X:
case BPF_ALU | BPF_MOD | BPF_X:
case BPF_ALU | BPF_LSH | BPF_X:
case BPF_ALU | BPF_RSH | BPF_X:
src = ebpf_to_mips_reg(ctx, insn, src_reg_no_fp);
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (src < 0 || dst < 0)
return -EINVAL;
td = get_reg_val_type(ctx, this_idx, insn->dst_reg);
if (td == REG_64BIT || td == REG_32BIT_ZERO_EX) {
emit_instr(ctx, sll, dst, dst, 0);
}
did_move = false;
ts = get_reg_val_type(ctx, this_idx, insn->src_reg);
if (ts == REG_64BIT || ts == REG_32BIT_ZERO_EX) {
int tmp_reg = MIPS_R_AT;
if (BPF_OP(insn->code) == BPF_MOV) {
tmp_reg = dst;
did_move = true;
}
emit_instr(ctx, sll, tmp_reg, src, 0);
src = MIPS_R_AT;
}
switch (BPF_OP(insn->code)) {
case BPF_MOV:
if (!did_move)
emit_instr(ctx, addu, dst, src, MIPS_R_ZERO);
break;
case BPF_ADD:
emit_instr(ctx, addu, dst, dst, src);
break;
case BPF_SUB:
emit_instr(ctx, subu, dst, dst, src);
break;
case BPF_XOR:
emit_instr(ctx, xor, dst, dst, src);
break;
case BPF_OR:
emit_instr(ctx, or, dst, dst, src);
break;
case BPF_AND:
emit_instr(ctx, and, dst, dst, src);
break;
case BPF_MUL:
emit_instr(ctx, mul, dst, dst, src);
break;
case BPF_DIV:
case BPF_MOD:
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, beq, src, MIPS_R_ZERO, b_off);
emit_instr(ctx, movz, MIPS_R_V0, MIPS_R_ZERO, src);
emit_instr(ctx, divu, dst, src);
if (BPF_OP(insn->code) == BPF_DIV)
emit_instr(ctx, mflo, dst);
else
emit_instr(ctx, mfhi, dst);
break;
case BPF_LSH:
emit_instr(ctx, sllv, dst, dst, src);
break;
case BPF_RSH:
emit_instr(ctx, srlv, dst, dst, src);
break;
default:
pr_err("ALU_REG NOT HANDLED\n");
return -EINVAL;
}
break;
case BPF_JMP | BPF_EXIT:
if (this_idx + 1 < exit_idx) {
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, beq, MIPS_R_ZERO, MIPS_R_ZERO, b_off);
emit_instr(ctx, nop);
}
break;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JNE | BPF_K:
cmp_eq = (BPF_OP(insn->code) == BPF_JEQ);
dst = ebpf_to_mips_reg(ctx, insn, dst_reg_fp_ok);
if (dst < 0)
return dst;
if (insn->imm == 0) {
src = MIPS_R_ZERO;
} else {
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
src = MIPS_R_AT;
}
goto jeq_common;
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JNE | BPF_X:
case BPF_JMP | BPF_JSGT | BPF_X:
case BPF_JMP | BPF_JSGE | BPF_X:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JSET | BPF_X:
src = ebpf_to_mips_reg(ctx, insn, src_reg_no_fp);
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (src < 0 || dst < 0)
return -EINVAL;
td = get_reg_val_type(ctx, this_idx, insn->dst_reg);
ts = get_reg_val_type(ctx, this_idx, insn->src_reg);
if (td == REG_32BIT && ts != REG_32BIT) {
emit_instr(ctx, sll, MIPS_R_AT, src, 0);
src = MIPS_R_AT;
} else if (ts == REG_32BIT && td != REG_32BIT) {
emit_instr(ctx, sll, MIPS_R_AT, dst, 0);
dst = MIPS_R_AT;
}
if (BPF_OP(insn->code) == BPF_JSET) {
emit_instr(ctx, and, MIPS_R_AT, dst, src);
cmp_eq = false;
dst = MIPS_R_AT;
src = MIPS_R_ZERO;
} else if (BPF_OP(insn->code) == BPF_JSGT) {
emit_instr(ctx, dsubu, MIPS_R_AT, dst, src);
if ((insn + 1)->code == (BPF_JMP | BPF_EXIT) && insn->off == 1) {
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, blez, MIPS_R_AT, b_off);
emit_instr(ctx, nop);
return 2;
}
b_off = b_imm(this_idx + insn->off + 1, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, bgtz, MIPS_R_AT, b_off);
emit_instr(ctx, nop);
break;
} else if (BPF_OP(insn->code) == BPF_JSGE) {
emit_instr(ctx, slt, MIPS_R_AT, dst, src);
cmp_eq = true;
dst = MIPS_R_AT;
src = MIPS_R_ZERO;
} else if (BPF_OP(insn->code) == BPF_JGT) {
emit_instr(ctx, dsubu, MIPS_R_T8, dst, src);
emit_instr(ctx, sltu, MIPS_R_AT, dst, src);
emit_instr(ctx, movz, MIPS_R_T9, MIPS_R_SP, MIPS_R_T8);
emit_instr(ctx, movn, MIPS_R_T9, MIPS_R_ZERO, MIPS_R_T8);
emit_instr(ctx, or, MIPS_R_AT, MIPS_R_T9, MIPS_R_AT);
cmp_eq = true;
dst = MIPS_R_AT;
src = MIPS_R_ZERO;
} else if (BPF_OP(insn->code) == BPF_JGE) {
emit_instr(ctx, sltu, MIPS_R_AT, dst, src);
cmp_eq = true;
dst = MIPS_R_AT;
src = MIPS_R_ZERO;
} else {
cmp_eq = (BPF_OP(insn->code) == BPF_JEQ);
}
jeq_common:
if ((insn + 1)->code == (BPF_JMP | BPF_EXIT) && insn->off == 1) {
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off)) {
target = j_target(ctx, exit_idx);
if (target == (unsigned int)-1)
return -E2BIG;
cmp_eq = !cmp_eq;
b_off = 4 * 3;
if (!(ctx->offsets[this_idx] & OFFSETS_B_CONV)) {
ctx->offsets[this_idx] |= OFFSETS_B_CONV;
ctx->long_b_conversion = 1;
}
}
if (cmp_eq)
emit_instr(ctx, bne, dst, src, b_off);
else
emit_instr(ctx, beq, dst, src, b_off);
emit_instr(ctx, nop);
if (ctx->offsets[this_idx] & OFFSETS_B_CONV) {
emit_instr(ctx, j, target);
emit_instr(ctx, nop);
}
return 2;
}
b_off = b_imm(this_idx + insn->off + 1, ctx);
if (is_bad_offset(b_off)) {
target = j_target(ctx, this_idx + insn->off + 1);
if (target == (unsigned int)-1)
return -E2BIG;
cmp_eq = !cmp_eq;
b_off = 4 * 3;
if (!(ctx->offsets[this_idx] & OFFSETS_B_CONV)) {
ctx->offsets[this_idx] |= OFFSETS_B_CONV;
ctx->long_b_conversion = 1;
}
}
if (cmp_eq)
emit_instr(ctx, beq, dst, src, b_off);
else
emit_instr(ctx, bne, dst, src, b_off);
emit_instr(ctx, nop);
if (ctx->offsets[this_idx] & OFFSETS_B_CONV) {
emit_instr(ctx, j, target);
emit_instr(ctx, nop);
}
break;
case BPF_JMP | BPF_JSGT | BPF_K:
case BPF_JMP | BPF_JSGE | BPF_K:
cmp_eq = (BPF_OP(insn->code) == BPF_JSGE);
dst = ebpf_to_mips_reg(ctx, insn, dst_reg_fp_ok);
if (dst < 0)
return dst;
if (insn->imm == 0) {
if ((insn + 1)->code == (BPF_JMP | BPF_EXIT) && insn->off == 1) {
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
if (cmp_eq)
emit_instr(ctx, bltz, dst, b_off);
else
emit_instr(ctx, blez, dst, b_off);
emit_instr(ctx, nop);
return 2;
}
b_off = b_imm(this_idx + insn->off + 1, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
if (cmp_eq)
emit_instr(ctx, bgez, dst, b_off);
else
emit_instr(ctx, bgtz, dst, b_off);
emit_instr(ctx, nop);
break;
}
t64s = insn->imm + (cmp_eq ? 0 : 1);
if (t64s >= S16_MIN && t64s <= S16_MAX) {
emit_instr(ctx, slti, MIPS_R_AT, dst, (int)t64s);
src = MIPS_R_AT;
dst = MIPS_R_ZERO;
cmp_eq = true;
goto jeq_common;
}
emit_const_to_reg(ctx, MIPS_R_AT, (u64)t64s);
emit_instr(ctx, slt, MIPS_R_AT, dst, MIPS_R_AT);
src = MIPS_R_AT;
dst = MIPS_R_ZERO;
cmp_eq = true;
goto jeq_common;
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGE | BPF_K:
cmp_eq = (BPF_OP(insn->code) == BPF_JGE);
dst = ebpf_to_mips_reg(ctx, insn, dst_reg_fp_ok);
if (dst < 0)
return dst;
t64s = (u64)(u32)(insn->imm) + (cmp_eq ? 0 : 1);
if (t64s >= 0 && t64s <= S16_MAX) {
emit_instr(ctx, sltiu, MIPS_R_AT, dst, (int)t64s);
src = MIPS_R_AT;
dst = MIPS_R_ZERO;
cmp_eq = true;
goto jeq_common;
}
emit_const_to_reg(ctx, MIPS_R_AT, (u64)t64s);
emit_instr(ctx, sltu, MIPS_R_AT, dst, MIPS_R_AT);
src = MIPS_R_AT;
dst = MIPS_R_ZERO;
cmp_eq = true;
goto jeq_common;
case BPF_JMP | BPF_JSET | BPF_K:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg_fp_ok);
if (dst < 0)
return dst;
if (use_bbit_insns() && hweight32((u32)insn->imm) == 1) {
if ((insn + 1)->code == (BPF_JMP | BPF_EXIT) && insn->off == 1) {
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, bbit0, dst, ffs((u32)insn->imm) - 1, b_off);
emit_instr(ctx, nop);
return 2;
}
b_off = b_imm(this_idx + insn->off + 1, ctx);
if (is_bad_offset(b_off))
return -E2BIG;
emit_instr(ctx, bbit1, dst, ffs((u32)insn->imm) - 1, b_off);
emit_instr(ctx, nop);
break;
}
t64 = (u32)insn->imm;
emit_const_to_reg(ctx, MIPS_R_AT, t64);
emit_instr(ctx, and, MIPS_R_AT, dst, MIPS_R_AT);
src = MIPS_R_AT;
dst = MIPS_R_ZERO;
cmp_eq = false;
goto jeq_common;
case BPF_JMP | BPF_JA:
b_off = b_imm(this_idx + insn->off + 1, ctx);
if (is_bad_offset(b_off)) {
target = j_target(ctx, this_idx + insn->off + 1);
if (target == (unsigned int)-1)
return -E2BIG;
emit_instr(ctx, j, target);
} else {
emit_instr(ctx, b, b_off);
}
emit_instr(ctx, nop);
break;
case BPF_LD | BPF_DW | BPF_IMM:
if (insn->src_reg != 0)
return -EINVAL;
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
t64 = ((u64)(u32)insn->imm) | ((u64)(insn + 1)->imm << 32);
emit_const_to_reg(ctx, dst, t64);
return 2;
case BPF_JMP | BPF_CALL:
ctx->flags |= EBPF_SAVE_RA;
t64s = (s64)insn->imm + (s64)__bpf_call_base;
emit_const_to_reg(ctx, MIPS_R_T9, (u64)t64s);
emit_instr(ctx, jalr, MIPS_R_RA, MIPS_R_T9);
emit_instr(ctx, nop);
break;
case BPF_JMP | BPF_TAIL_CALL:
if (emit_bpf_tail_call(ctx, this_idx))
return -EINVAL;
break;
case BPF_LD | BPF_B | BPF_ABS:
case BPF_LD | BPF_H | BPF_ABS:
case BPF_LD | BPF_W | BPF_ABS:
case BPF_LD | BPF_DW | BPF_ABS:
ctx->flags |= EBPF_SAVE_RA;
gen_imm_to_reg(insn, MIPS_R_A1, ctx);
emit_instr(ctx, addiu, MIPS_R_A2, MIPS_R_ZERO, size_to_len(insn));
if (insn->imm < 0) {
emit_const_to_reg(ctx, MIPS_R_T9, (u64)bpf_internal_load_pointer_neg_helper);
} else {
emit_const_to_reg(ctx, MIPS_R_T9, (u64)ool_skb_header_pointer);
emit_instr(ctx, daddiu, MIPS_R_A3, MIPS_R_SP, ctx->tmp_offset);
}
goto ld_skb_common;
case BPF_LD | BPF_B | BPF_IND:
case BPF_LD | BPF_H | BPF_IND:
case BPF_LD | BPF_W | BPF_IND:
case BPF_LD | BPF_DW | BPF_IND:
ctx->flags |= EBPF_SAVE_RA;
src = ebpf_to_mips_reg(ctx, insn, src_reg_no_fp);
if (src < 0)
return src;
ts = get_reg_val_type(ctx, this_idx, insn->src_reg);
if (ts == REG_32BIT_ZERO_EX) {
emit_instr(ctx, sll, MIPS_R_A1, src, 0);
src = MIPS_R_A1;
}
if (insn->imm >= S16_MIN && insn->imm <= S16_MAX) {
emit_instr(ctx, daddiu, MIPS_R_A1, src, insn->imm);
} else {
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
emit_instr(ctx, daddu, MIPS_R_A1, MIPS_R_AT, src);
}
emit_instr(ctx, sll, MIPS_R_A1, MIPS_R_A1, 0);
emit_instr(ctx, daddiu, MIPS_R_A3, MIPS_R_SP, ctx->tmp_offset);
emit_instr(ctx, slt, MIPS_R_AT, MIPS_R_A1, MIPS_R_ZERO);
emit_const_to_reg(ctx, MIPS_R_T8, (u64)bpf_internal_load_pointer_neg_helper);
emit_const_to_reg(ctx, MIPS_R_T9, (u64)ool_skb_header_pointer);
emit_instr(ctx, addiu, MIPS_R_A2, MIPS_R_ZERO, size_to_len(insn));
emit_instr(ctx, movn, MIPS_R_T9, MIPS_R_T8, MIPS_R_AT);
ld_skb_common:
emit_instr(ctx, jalr, MIPS_R_RA, MIPS_R_T9);
emit_instr(ctx, daddu, MIPS_R_A0, MIPS_R_S0, MIPS_R_ZERO);
b_off = b_imm(exit_idx, ctx);
if (is_bad_offset(b_off)) {
target = j_target(ctx, exit_idx);
if (target == (unsigned int)-1)
return -E2BIG;
if (!(ctx->offsets[this_idx] & OFFSETS_B_CONV)) {
ctx->offsets[this_idx] |= OFFSETS_B_CONV;
ctx->long_b_conversion = 1;
}
emit_instr(ctx, bne, MIPS_R_V0, MIPS_R_ZERO, 4 * 3);
emit_instr(ctx, nop);
emit_instr(ctx, j, target);
emit_instr(ctx, nop);
} else {
emit_instr(ctx, beq, MIPS_R_V0, MIPS_R_ZERO, b_off);
emit_instr(ctx, nop);
}
#ifdef __BIG_ENDIAN
need_swap = false;
#else
need_swap = true;
#endif
dst = MIPS_R_V0;
switch (BPF_SIZE(insn->code)) {
case BPF_B:
emit_instr(ctx, lbu, dst, 0, MIPS_R_V0);
break;
case BPF_H:
emit_instr(ctx, lhu, dst, 0, MIPS_R_V0);
if (need_swap)
emit_instr(ctx, wsbh, dst, dst);
break;
case BPF_W:
emit_instr(ctx, lw, dst, 0, MIPS_R_V0);
if (need_swap) {
emit_instr(ctx, wsbh, dst, dst);
emit_instr(ctx, rotr, dst, dst, 16);
}
break;
case BPF_DW:
emit_instr(ctx, ld, dst, 0, MIPS_R_V0);
if (need_swap) {
emit_instr(ctx, dsbh, dst, dst);
emit_instr(ctx, dshd, dst, dst);
}
break;
}
break;
case BPF_ALU | BPF_END | BPF_FROM_BE:
case BPF_ALU | BPF_END | BPF_FROM_LE:
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
td = get_reg_val_type(ctx, this_idx, insn->dst_reg);
if (insn->imm == 64 && td == REG_32BIT)
emit_instr(ctx, dinsu, dst, MIPS_R_ZERO, 32, 32);
if (insn->imm != 64 &&
(td == REG_64BIT || td == REG_32BIT_ZERO_EX)) {
emit_instr(ctx, sll, dst, dst, 0);
}
#ifdef __BIG_ENDIAN
need_swap = (BPF_SRC(insn->code) == BPF_FROM_LE);
#else
need_swap = (BPF_SRC(insn->code) == BPF_FROM_BE);
#endif
if (insn->imm == 16) {
if (need_swap)
emit_instr(ctx, wsbh, dst, dst);
emit_instr(ctx, andi, dst, dst, 0xffff);
} else if (insn->imm == 32) {
if (need_swap) {
emit_instr(ctx, wsbh, dst, dst);
emit_instr(ctx, rotr, dst, dst, 16);
}
} else {
if (need_swap) {
emit_instr(ctx, dsbh, dst, dst);
emit_instr(ctx, dshd, dst, dst);
}
}
break;
case BPF_ST | BPF_B | BPF_MEM:
case BPF_ST | BPF_H | BPF_MEM:
case BPF_ST | BPF_W | BPF_MEM:
case BPF_ST | BPF_DW | BPF_MEM:
if (insn->dst_reg == BPF_REG_10) {
ctx->flags |= EBPF_SEEN_FP;
dst = MIPS_R_SP;
mem_off = insn->off + MAX_BPF_STACK;
} else {
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
mem_off = insn->off;
}
gen_imm_to_reg(insn, MIPS_R_AT, ctx);
switch (BPF_SIZE(insn->code)) {
case BPF_B:
emit_instr(ctx, sb, MIPS_R_AT, mem_off, dst);
break;
case BPF_H:
emit_instr(ctx, sh, MIPS_R_AT, mem_off, dst);
break;
case BPF_W:
emit_instr(ctx, sw, MIPS_R_AT, mem_off, dst);
break;
case BPF_DW:
emit_instr(ctx, sd, MIPS_R_AT, mem_off, dst);
break;
}
break;
case BPF_LDX | BPF_B | BPF_MEM:
case BPF_LDX | BPF_H | BPF_MEM:
case BPF_LDX | BPF_W | BPF_MEM:
case BPF_LDX | BPF_DW | BPF_MEM:
if (insn->src_reg == BPF_REG_10) {
ctx->flags |= EBPF_SEEN_FP;
src = MIPS_R_SP;
mem_off = insn->off + MAX_BPF_STACK;
} else {
src = ebpf_to_mips_reg(ctx, insn, src_reg_no_fp);
if (src < 0)
return src;
mem_off = insn->off;
}
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
switch (BPF_SIZE(insn->code)) {
case BPF_B:
emit_instr(ctx, lbu, dst, mem_off, src);
break;
case BPF_H:
emit_instr(ctx, lhu, dst, mem_off, src);
break;
case BPF_W:
emit_instr(ctx, lw, dst, mem_off, src);
break;
case BPF_DW:
emit_instr(ctx, ld, dst, mem_off, src);
break;
}
break;
case BPF_STX | BPF_B | BPF_MEM:
case BPF_STX | BPF_H | BPF_MEM:
case BPF_STX | BPF_W | BPF_MEM:
case BPF_STX | BPF_DW | BPF_MEM:
case BPF_STX | BPF_W | BPF_XADD:
case BPF_STX | BPF_DW | BPF_XADD:
if (insn->dst_reg == BPF_REG_10) {
ctx->flags |= EBPF_SEEN_FP;
dst = MIPS_R_SP;
mem_off = insn->off + MAX_BPF_STACK;
} else {
dst = ebpf_to_mips_reg(ctx, insn, dst_reg);
if (dst < 0)
return dst;
mem_off = insn->off;
}
src = ebpf_to_mips_reg(ctx, insn, src_reg_no_fp);
if (src < 0)
return dst;
if (BPF_MODE(insn->code) == BPF_XADD) {
switch (BPF_SIZE(insn->code)) {
case BPF_W:
if (get_reg_val_type(ctx, this_idx, insn->src_reg) == REG_32BIT) {
emit_instr(ctx, sll, MIPS_R_AT, src, 0);
src = MIPS_R_AT;
}
emit_instr(ctx, ll, MIPS_R_T8, mem_off, dst);
emit_instr(ctx, addu, MIPS_R_T8, MIPS_R_T8, src);
emit_instr(ctx, sc, MIPS_R_T8, mem_off, dst);
emit_instr(ctx, beq, MIPS_R_T8, MIPS_R_ZERO, -4 * 4);
emit_instr(ctx, nop);
break;
case BPF_DW:
if (get_reg_val_type(ctx, this_idx, insn->src_reg) == REG_32BIT) {
emit_instr(ctx, daddu, MIPS_R_AT, src, MIPS_R_ZERO);
emit_instr(ctx, dinsu, MIPS_R_AT, MIPS_R_ZERO, 32, 32);
src = MIPS_R_AT;
}
emit_instr(ctx, lld, MIPS_R_T8, mem_off, dst);
emit_instr(ctx, daddu, MIPS_R_T8, MIPS_R_T8, src);
emit_instr(ctx, scd, MIPS_R_T8, mem_off, dst);
emit_instr(ctx, beq, MIPS_R_T8, MIPS_R_ZERO, -4 * 4);
emit_instr(ctx, nop);
break;
}
} else {
switch (BPF_SIZE(insn->code)) {
case BPF_B:
emit_instr(ctx, sb, src, mem_off, dst);
break;
case BPF_H:
emit_instr(ctx, sh, src, mem_off, dst);
break;
case BPF_W:
emit_instr(ctx, sw, src, mem_off, dst);
break;
case BPF_DW:
if (get_reg_val_type(ctx, this_idx, insn->src_reg) == REG_32BIT) {
emit_instr(ctx, daddu, MIPS_R_AT, src, MIPS_R_ZERO);
emit_instr(ctx, dinsu, MIPS_R_AT, MIPS_R_ZERO, 32, 32);
src = MIPS_R_AT;
}
emit_instr(ctx, sd, src, mem_off, dst);
break;
}
}
break;
default:
pr_err("NOT HANDLED %d - (%02x)\n",
this_idx, (unsigned int)insn->code);
return -EINVAL;
}
return 1;
}
static int build_int_body(struct jit_ctx *ctx)
{
const struct bpf_prog *prog = ctx->skf;
const struct bpf_insn *insn;
int i, r;
for (i = 0; i < prog->len; ) {
insn = prog->insnsi + i;
if ((ctx->reg_val_types[i] & RVT_VISITED_MASK) == 0) {
i++;
continue;
}
if (ctx->target == NULL)
ctx->offsets[i] = (ctx->offsets[i] & OFFSETS_B_CONV) | (ctx->idx * 4);
r = build_one_insn(insn, ctx, i, prog->len);
if (r < 0)
return r;
i += r;
}
if (ctx->target == NULL)
ctx->offsets[i] = ctx->idx * 4;
if (ctx->target == NULL)
for (i = 0; i < prog->len; i++) {
insn = prog->insnsi + i;
if (insn->code == (BPF_JMP | BPF_EXIT))
ctx->offsets[i] = ctx->idx * 4;
}
return 0;
}
static int reg_val_propagate_range(struct jit_ctx *ctx, u64 initial_rvt,
int start_idx, bool follow_taken)
{
const struct bpf_prog *prog = ctx->skf;
const struct bpf_insn *insn;
u64 exit_rvt = initial_rvt;
u64 *rvt = ctx->reg_val_types;
int idx;
int reg;
for (idx = start_idx; idx < prog->len; idx++) {
rvt[idx] = (rvt[idx] & RVT_VISITED_MASK) | exit_rvt;
insn = prog->insnsi + idx;
switch (BPF_CLASS(insn->code)) {
case BPF_ALU:
switch (BPF_OP(insn->code)) {
case BPF_ADD:
case BPF_SUB:
case BPF_MUL:
case BPF_DIV:
case BPF_OR:
case BPF_AND:
case BPF_LSH:
case BPF_RSH:
case BPF_NEG:
case BPF_MOD:
case BPF_XOR:
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT);
break;
case BPF_MOV:
if (BPF_SRC(insn->code)) {
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT);
} else {
if (insn->imm >= 0)
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT_POS);
else
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT);
}
break;
case BPF_END:
if (insn->imm == 64)
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT);
else if (insn->imm == 32)
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT);
else
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT_POS);
break;
}
rvt[idx] |= RVT_DONE;
break;
case BPF_ALU64:
switch (BPF_OP(insn->code)) {
case BPF_MOV:
if (BPF_SRC(insn->code)) {
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT);
} else {
if (insn->imm >= 0)
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT_POS);
else
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT_32BIT);
}
break;
default:
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT);
}
rvt[idx] |= RVT_DONE;
break;
case BPF_LD:
switch (BPF_SIZE(insn->code)) {
case BPF_DW:
if (BPF_MODE(insn->code) == BPF_IMM) {
s64 val;
val = (s64)((u32)insn->imm | ((u64)(insn + 1)->imm << 32));
if (val > 0 && val <= S32_MAX)
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT_POS);
else if (val >= S32_MIN && val <= S32_MAX)
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT_32BIT);
else
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT);
rvt[idx] |= RVT_DONE;
idx++;
} else {
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT);
}
break;
case BPF_B:
case BPF_H:
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT_POS);
break;
case BPF_W:
if (BPF_MODE(insn->code) == BPF_IMM)
set_reg_val_type(&exit_rvt, insn->dst_reg,
insn->imm >= 0 ? REG_32BIT_POS : REG_32BIT);
else
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT);
break;
}
rvt[idx] |= RVT_DONE;
break;
case BPF_LDX:
switch (BPF_SIZE(insn->code)) {
case BPF_DW:
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_64BIT);
break;
case BPF_B:
case BPF_H:
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT_POS);
break;
case BPF_W:
set_reg_val_type(&exit_rvt, insn->dst_reg, REG_32BIT);
break;
}
rvt[idx] |= RVT_DONE;
break;
case BPF_JMP:
switch (BPF_OP(insn->code)) {
case BPF_EXIT:
rvt[idx] = RVT_DONE | exit_rvt;
rvt[prog->len] = exit_rvt;
return idx;
case BPF_JA:
rvt[idx] |= RVT_DONE;
idx += insn->off;
break;
case BPF_JEQ:
case BPF_JGT:
case BPF_JGE:
case BPF_JSET:
case BPF_JNE:
case BPF_JSGT:
case BPF_JSGE:
if (follow_taken) {
rvt[idx] |= RVT_BRANCH_TAKEN;
idx += insn->off;
follow_taken = false;
} else {
rvt[idx] |= RVT_FALL_THROUGH;
}
break;
case BPF_CALL:
set_reg_val_type(&exit_rvt, BPF_REG_0, REG_64BIT);
for (reg = BPF_REG_0; reg <= BPF_REG_5; reg++)
set_reg_val_type(&exit_rvt, reg, REG_64BIT);
rvt[idx] |= RVT_DONE;
break;
default:
WARN(1, "Unhandled BPF_JMP case.\n");
rvt[idx] |= RVT_DONE;
break;
}
break;
default:
rvt[idx] |= RVT_DONE;
break;
}
}
return idx;
}
static int reg_val_propagate(struct jit_ctx *ctx)
{
const struct bpf_prog *prog = ctx->skf;
u64 exit_rvt;
int reg;
int i;
exit_rvt = 0;
for (reg = BPF_REG_1; reg <= BPF_REG_5; reg++)
set_reg_val_type(&exit_rvt, reg, REG_64BIT);
reg_val_propagate_range(ctx, exit_rvt, 0, false);
restart_search:
for (i = 0; i < prog->len; i++) {
u64 rvt = ctx->reg_val_types[i];
if ((rvt & RVT_VISITED_MASK) == RVT_DONE ||
(rvt & RVT_VISITED_MASK) == 0)
continue;
if ((rvt & RVT_VISITED_MASK) == RVT_FALL_THROUGH) {
reg_val_propagate_range(ctx, rvt & ~RVT_VISITED_MASK, i, true);
} else {
WARN(1, "Unexpected RVT_BRANCH_TAKEN case.\n");
reg_val_propagate_range(ctx, rvt & ~RVT_VISITED_MASK, i, false);
}
goto restart_search;
}
return 0;
}
static void jit_fill_hole(void *area, unsigned int size)
{
u32 *p;
for (p = area; size >= sizeof(u32); size -= sizeof(u32))
uasm_i_break(&p, BRK_BUG);
}
struct bpf_prog *bpf_int_jit_compile(struct bpf_prog *prog)
{
struct bpf_prog *orig_prog = prog;
bool tmp_blinded = false;
struct bpf_prog *tmp;
struct bpf_binary_header *header = NULL;
struct jit_ctx ctx;
unsigned int image_size;
u8 *image_ptr;
if (!bpf_jit_enable || !cpu_has_mips64r2)
return prog;
tmp = bpf_jit_blind_constants(prog);
if (IS_ERR(tmp))
return orig_prog;
if (tmp != prog) {
tmp_blinded = true;
prog = tmp;
}
memset(&ctx, 0, sizeof(ctx));
ctx.offsets = kcalloc(prog->len + 1, sizeof(*ctx.offsets), GFP_KERNEL);
if (ctx.offsets == NULL)
goto out_err;
ctx.reg_val_types = kcalloc(prog->len + 1, sizeof(*ctx.reg_val_types), GFP_KERNEL);
if (ctx.reg_val_types == NULL)
goto out_err;
ctx.skf = prog;
if (reg_val_propagate(&ctx))
goto out_err;
if (build_int_body(&ctx))
goto out_err;
if (ctx.flags & EBPF_SEEN_TC) {
if (ctx.flags & EBPF_SAVE_RA)
ctx.flags |= EBPF_SAVE_S4;
else
ctx.flags |= EBPF_TCC_IN_V1;
}
do {
ctx.idx = 0;
ctx.gen_b_offsets = 1;
ctx.long_b_conversion = 0;
if (gen_int_prologue(&ctx))
goto out_err;
if (build_int_body(&ctx))
goto out_err;
if (build_int_epilogue(&ctx, MIPS_R_RA))
goto out_err;
} while (ctx.long_b_conversion);
image_size = 4 * ctx.idx;
header = bpf_jit_binary_alloc(image_size, &image_ptr,
sizeof(u32), jit_fill_hole);
if (header == NULL)
goto out_err;
ctx.target = (u32 *)image_ptr;
ctx.idx = 0;
if (gen_int_prologue(&ctx))
goto out_err;
if (build_int_body(&ctx))
goto out_err;
if (build_int_epilogue(&ctx, MIPS_R_RA))
goto out_err;
flush_icache_range((unsigned long)ctx.target,
(unsigned long)(ctx.target + ctx.idx * sizeof(u32)));
if (bpf_jit_enable > 1)
bpf_jit_dump(prog->len, image_size, 2, ctx.target);
bpf_jit_binary_lock_ro(header);
prog->bpf_func = (void *)ctx.target;
prog->jited = 1;
prog->jited_len = image_size;
out_normal:
if (tmp_blinded)
bpf_jit_prog_release_other(prog, prog == orig_prog ?
tmp : orig_prog);
kfree(ctx.offsets);
kfree(ctx.reg_val_types);
return prog;
out_err:
prog = orig_prog;
if (header)
bpf_jit_binary_free(header);
goto out_normal;
}
