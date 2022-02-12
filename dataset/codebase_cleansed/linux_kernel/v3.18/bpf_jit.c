static inline int optimize_div(u32 *k)
{
if (!(*k & (*k-1))) {
*k = ilog2(*k);
return 1;
}
return 0;
}
static inline bool is_range16(s32 imm)
{
return !(imm >= SBIT(15) || imm < -SBIT(15));
}
static inline void emit_addu(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, addu, dst, src1, src2);
}
static inline void emit_nop(struct jit_ctx *ctx)
{
emit_instr(ctx, nop);
}
static inline void emit_load_imm(unsigned int dst, u32 imm, struct jit_ctx *ctx)
{
if (ctx->target != NULL) {
if (!is_range16(imm)) {
u32 *p = &ctx->target[ctx->idx];
uasm_i_lui(&p, r_tmp_imm, (s32)imm >> 16);
p = &ctx->target[ctx->idx + 1];
uasm_i_ori(&p, dst, r_tmp_imm, imm & 0xffff);
} else {
u32 *p = &ctx->target[ctx->idx];
uasm_i_addiu(&p, dst, r_zero, imm);
}
}
ctx->idx++;
if (!is_range16(imm))
ctx->idx++;
}
static inline void emit_or(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, or, dst, src1, src2);
}
static inline void emit_ori(unsigned int dst, unsigned src, u32 imm,
struct jit_ctx *ctx)
{
if (imm >= BIT(16)) {
emit_load_imm(r_tmp, imm, ctx);
emit_or(dst, src, r_tmp, ctx);
} else {
emit_instr(ctx, ori, dst, src, imm);
}
}
static inline void emit_daddiu(unsigned int dst, unsigned int src,
int imm, struct jit_ctx *ctx)
{
emit_instr(ctx, daddiu, dst, src, imm);
}
static inline void emit_addiu(unsigned int dst, unsigned int src,
u32 imm, struct jit_ctx *ctx)
{
if (!is_range16(imm)) {
emit_load_imm(r_tmp, imm, ctx);
emit_addu(dst, r_tmp, src, ctx);
} else {
emit_instr(ctx, addiu, dst, src, imm);
}
}
static inline void emit_and(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, and, dst, src1, src2);
}
static inline void emit_andi(unsigned int dst, unsigned int src,
u32 imm, struct jit_ctx *ctx)
{
if (imm >= BIT(16)) {
emit_load_imm(r_tmp, imm, ctx);
emit_and(dst, src, r_tmp, ctx);
} else {
emit_instr(ctx, andi, dst, src, imm);
}
}
static inline void emit_xor(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, xor, dst, src1, src2);
}
static inline void emit_xori(ptr dst, ptr src, u32 imm, struct jit_ctx *ctx)
{
if (imm >= BIT(16)) {
emit_load_imm(r_tmp, imm, ctx);
emit_xor(dst, src, r_tmp, ctx);
} else {
emit_instr(ctx, xori, dst, src, imm);
}
}
static inline void emit_stack_offset(int offset, struct jit_ctx *ctx)
{
emit_long_instr(ctx, ADDIU, r_sp, r_sp, offset);
}
static inline void emit_subu(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, subu, dst, src1, src2);
}
static inline void emit_neg(unsigned int reg, struct jit_ctx *ctx)
{
emit_subu(reg, r_zero, reg, ctx);
}
static inline void emit_sllv(unsigned int dst, unsigned int src,
unsigned int sa, struct jit_ctx *ctx)
{
emit_instr(ctx, sllv, dst, src, sa);
}
static inline void emit_sll(unsigned int dst, unsigned int src,
unsigned int sa, struct jit_ctx *ctx)
{
if (sa >= BIT(5))
emit_jit_reg_move(dst, r_zero, ctx);
else
emit_instr(ctx, sll, dst, src, sa);
}
static inline void emit_srlv(unsigned int dst, unsigned int src,
unsigned int sa, struct jit_ctx *ctx)
{
emit_instr(ctx, srlv, dst, src, sa);
}
static inline void emit_srl(unsigned int dst, unsigned int src,
unsigned int sa, struct jit_ctx *ctx)
{
if (sa >= BIT(5))
emit_jit_reg_move(dst, r_zero, ctx);
else
emit_instr(ctx, srl, dst, src, sa);
}
static inline void emit_slt(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, slt, dst, src1, src2);
}
static inline void emit_sltu(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, sltu, dst, src1, src2);
}
static inline void emit_sltiu(unsigned dst, unsigned int src,
unsigned int imm, struct jit_ctx *ctx)
{
if (!is_range16((s32)imm)) {
emit_load_imm(r_tmp, imm, ctx);
emit_sltu(dst, src, r_tmp, ctx);
} else {
emit_instr(ctx, sltiu, dst, src, imm);
}
}
static inline void emit_store_stack_reg(ptr reg, ptr base,
unsigned int offset,
struct jit_ctx *ctx)
{
emit_long_instr(ctx, SW, reg, offset, base);
}
static inline void emit_store(ptr reg, ptr base, unsigned int offset,
struct jit_ctx *ctx)
{
emit_instr(ctx, sw, reg, offset, base);
}
static inline void emit_load_stack_reg(ptr reg, ptr base,
unsigned int offset,
struct jit_ctx *ctx)
{
emit_long_instr(ctx, LW, reg, offset, base);
}
static inline void emit_load(unsigned int reg, unsigned int base,
unsigned int offset, struct jit_ctx *ctx)
{
emit_instr(ctx, lw, reg, offset, base);
}
static inline void emit_load_byte(unsigned int reg, unsigned int base,
unsigned int offset, struct jit_ctx *ctx)
{
emit_instr(ctx, lb, reg, offset, base);
}
static inline void emit_half_load(unsigned int reg, unsigned int base,
unsigned int offset, struct jit_ctx *ctx)
{
emit_instr(ctx, lh, reg, offset, base);
}
static inline void emit_mul(unsigned int dst, unsigned int src1,
unsigned int src2, struct jit_ctx *ctx)
{
emit_instr(ctx, mul, dst, src1, src2);
}
static inline void emit_div(unsigned int dst, unsigned int src,
struct jit_ctx *ctx)
{
if (ctx->target != NULL) {
u32 *p = &ctx->target[ctx->idx];
uasm_i_divu(&p, dst, src);
p = &ctx->target[ctx->idx + 1];
uasm_i_mflo(&p, dst);
}
ctx->idx += 2;
}
static inline void emit_mod(unsigned int dst, unsigned int src,
struct jit_ctx *ctx)
{
if (ctx->target != NULL) {
u32 *p = &ctx->target[ctx->idx];
uasm_i_divu(&p, dst, src);
p = &ctx->target[ctx->idx + 1];
uasm_i_mflo(&p, dst);
}
ctx->idx += 2;
}
static inline void emit_dsll(unsigned int dst, unsigned int src,
unsigned int sa, struct jit_ctx *ctx)
{
emit_instr(ctx, dsll, dst, src, sa);
}
static inline void emit_dsrl32(unsigned int dst, unsigned int src,
unsigned int sa, struct jit_ctx *ctx)
{
emit_instr(ctx, dsrl32, dst, src, sa);
}
static inline void emit_wsbh(unsigned int dst, unsigned int src,
struct jit_ctx *ctx)
{
emit_instr(ctx, wsbh, dst, src);
}
static inline void emit_load_ptr(unsigned int dst, unsigned int src,
int imm, struct jit_ctx *ctx)
{
emit_long_instr(ctx, LW, dst, imm, src);
}
static inline void emit_load_func(unsigned int reg, ptr imm,
struct jit_ctx *ctx)
{
if (config_enabled(CONFIG_64BIT)) {
emit_load_imm(r_tmp, (u64)imm >> 32, ctx);
emit_dsll(r_tmp_imm, r_tmp, 16, ctx);
emit_ori(r_tmp, r_tmp_imm, (imm >> 16) & 0xffff, ctx);
emit_dsll(r_tmp_imm, r_tmp, 16, ctx);
emit_ori(reg, r_tmp_imm, imm & 0xffff, ctx);
} else {
emit_load_imm(reg, imm, ctx);
}
}
static inline void emit_reg_move(ptr dst, ptr src, struct jit_ctx *ctx)
{
emit_long_instr(ctx, ADDU, dst, src, r_zero);
}
static inline void emit_jit_reg_move(ptr dst, ptr src, struct jit_ctx *ctx)
{
emit_addu(dst, src, r_zero, ctx);
}
static inline u32 b_imm(unsigned int tgt, struct jit_ctx *ctx)
{
if (ctx->target == NULL)
return 0;
return ctx->offsets[tgt] -
(ctx->idx * 4 - ctx->prologue_bytes) - 4;
}
static inline void emit_bcond(int cond, unsigned int reg1, unsigned int reg2,
unsigned int imm, struct jit_ctx *ctx)
{
if (ctx->target != NULL) {
u32 *p = &ctx->target[ctx->idx];
switch (cond) {
case MIPS_COND_EQ:
uasm_i_beq(&p, reg1, reg2, imm);
break;
case MIPS_COND_NE:
uasm_i_bne(&p, reg1, reg2, imm);
break;
case MIPS_COND_ALL:
uasm_i_b(&p, imm);
break;
default:
pr_warn("%s: Unhandled branch conditional: %d\n",
__func__, cond);
}
}
ctx->idx++;
}
static inline void emit_b(unsigned int imm, struct jit_ctx *ctx)
{
emit_bcond(MIPS_COND_ALL, r_zero, r_zero, imm, ctx);
}
static inline void emit_jalr(unsigned int link, unsigned int reg,
struct jit_ctx *ctx)
{
emit_instr(ctx, jalr, link, reg);
}
static inline void emit_jr(unsigned int reg, struct jit_ctx *ctx)
{
emit_instr(ctx, jr, reg);
}
static inline u16 align_sp(unsigned int num)
{
unsigned int align = config_enabled(CONFIG_64BIT) ? 16 : 8;
num = (num + (align - 1)) & -align;
return num;
}
static bool is_load_to_a(u16 inst)
{
switch (inst) {
case BPF_LD | BPF_W | BPF_LEN:
case BPF_LD | BPF_W | BPF_ABS:
case BPF_LD | BPF_H | BPF_ABS:
case BPF_LD | BPF_B | BPF_ABS:
return true;
default:
return false;
}
}
static void save_bpf_jit_regs(struct jit_ctx *ctx, unsigned offset)
{
int i = 0, real_off = 0;
u32 sflags, tmp_flags;
emit_stack_offset(-align_sp(offset), ctx);
if (ctx->flags & SEEN_CALL) {
if (config_enabled(CONFIG_64BIT))
real_off = align_sp(offset) - RSIZE;
else
real_off = align_sp(offset) + RSIZE;
emit_store_stack_reg(MIPS_R_A0, r_sp, real_off, ctx);
emit_store_stack_reg(MIPS_R_A1, r_sp, real_off + RSIZE, ctx);
real_off = 0;
}
tmp_flags = sflags = ctx->flags >> SEEN_SREG_SFT;
while (tmp_flags) {
if ((sflags >> i) & 0x1) {
emit_store_stack_reg(MIPS_R_S0 + i, r_sp, real_off,
ctx);
real_off += RSIZE;
}
i++;
tmp_flags >>= 1;
}
if (ctx->flags & SEEN_CALL) {
emit_store_stack_reg(r_ra, r_sp, real_off, ctx);
real_off += RSIZE;
}
if (ctx->flags & SEEN_MEM) {
if (real_off % (RSIZE * 2))
real_off += RSIZE;
emit_long_instr(ctx, ADDIU, r_M, r_sp, real_off);
}
}
static void restore_bpf_jit_regs(struct jit_ctx *ctx,
unsigned int offset)
{
int i, real_off = 0;
u32 sflags, tmp_flags;
if (ctx->flags & SEEN_CALL) {
if (config_enabled(CONFIG_64BIT))
real_off = align_sp(offset) - RSIZE;
else
real_off = align_sp(offset) + RSIZE;
emit_load_stack_reg(MIPS_R_A0, r_sp, real_off, ctx);
emit_load_stack_reg(MIPS_R_A1, r_sp, real_off + RSIZE, ctx);
real_off = 0;
}
tmp_flags = sflags = ctx->flags >> SEEN_SREG_SFT;
i = 0;
while (tmp_flags) {
if ((sflags >> i) & 0x1) {
emit_load_stack_reg(MIPS_R_S0 + i, r_sp, real_off,
ctx);
real_off += RSIZE;
}
i++;
tmp_flags >>= 1;
}
if (ctx->flags & SEEN_CALL)
emit_load_stack_reg(r_ra, r_sp, real_off, ctx);
emit_stack_offset(align_sp(offset), ctx);
}
static unsigned int get_stack_depth(struct jit_ctx *ctx)
{
int sp_off = 0;
sp_off += hweight32(ctx->flags >> SEEN_SREG_SFT) * RSIZE;
if (ctx->flags & SEEN_MEM)
sp_off += 4 * BPF_MEMWORDS;
if (ctx->flags & SEEN_CALL)
sp_off += config_enabled(CONFIG_64BIT) ?
(ARGS_USED_BY_JIT + 1) * RSIZE : RSIZE;
return sp_off - RSIZE;
}
static void build_prologue(struct jit_ctx *ctx)
{
u16 first_inst = ctx->skf->insns[0].code;
int sp_off;
sp_off = get_stack_depth(ctx);
save_bpf_jit_regs(ctx, sp_off);
if (ctx->flags & SEEN_SKB)
emit_reg_move(r_skb, MIPS_R_A0, ctx);
if (ctx->flags & SEEN_X)
emit_jit_reg_move(r_X, r_zero, ctx);
if ((first_inst != (BPF_RET | BPF_K)) && !(is_load_to_a(first_inst)))
emit_jit_reg_move(r_A, r_zero, ctx);
}
static void build_epilogue(struct jit_ctx *ctx)
{
unsigned int sp_off;
sp_off = get_stack_depth(ctx);
restore_bpf_jit_regs(ctx, sp_off);
emit_jr(r_ra, ctx);
emit_nop(ctx);
}
static u64 jit_get_skb_b(struct sk_buff *skb, unsigned offset)
{
u8 ret;
int err;
err = skb_copy_bits(skb, offset, &ret, 1);
return (u64)err << 32 | ret;
}
static u64 jit_get_skb_h(struct sk_buff *skb, unsigned offset)
{
u16 ret;
int err;
err = skb_copy_bits(skb, offset, &ret, 2);
return (u64)err << 32 | ntohs(ret);
}
static u64 jit_get_skb_w(struct sk_buff *skb, unsigned offset)
{
u32 ret;
int err;
err = skb_copy_bits(skb, offset, &ret, 4);
return (u64)err << 32 | ntohl(ret);
}
static int build_body(struct jit_ctx *ctx)
{
void *load_func[] = {jit_get_skb_b, jit_get_skb_h, jit_get_skb_w};
const struct bpf_prog *prog = ctx->skf;
const struct sock_filter *inst;
unsigned int i, off, load_order, condt;
u32 k, b_off __maybe_unused;
for (i = 0; i < prog->len; i++) {
u16 code;
inst = &(prog->insns[i]);
pr_debug("%s: code->0x%02x, jt->0x%x, jf->0x%x, k->0x%x\n",
__func__, inst->code, inst->jt, inst->jf, inst->k);
k = inst->k;
code = bpf_anc_helper(inst);
if (ctx->target == NULL)
ctx->offsets[i] = ctx->idx * 4;
switch (code) {
case BPF_LD | BPF_IMM:
ctx->flags |= SEEN_A;
emit_load_imm(r_A, k, ctx);
break;
case BPF_LD | BPF_W | BPF_LEN:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, len) != 4);
ctx->flags |= SEEN_SKB | SEEN_A;
off = offsetof(struct sk_buff, len);
emit_load(r_A, r_skb, off, ctx);
break;
case BPF_LD | BPF_MEM:
ctx->flags |= SEEN_MEM | SEEN_A;
emit_load(r_A, r_M, SCRATCH_OFF(k), ctx);
break;
case BPF_LD | BPF_W | BPF_ABS:
load_order = 2;
goto load;
case BPF_LD | BPF_H | BPF_ABS:
load_order = 1;
goto load;
case BPF_LD | BPF_B | BPF_ABS:
load_order = 0;
load:
if ((int)k < 0)
return -ENOTSUPP;
emit_load_imm(r_off, k, ctx);
load_common:
emit_slt(r_s0, r_off, r_zero, ctx);
emit_bcond(MIPS_COND_NE, r_s0, r_zero,
b_imm(prog->len, ctx), ctx);
emit_reg_move(r_ret, r_zero, ctx);
ctx->flags |= SEEN_CALL | SEEN_OFF | SEEN_S0 |
SEEN_SKB | SEEN_A;
emit_load_func(r_s0, (ptr)load_func[load_order],
ctx);
emit_reg_move(MIPS_R_A0, r_skb, ctx);
emit_jalr(MIPS_R_RA, r_s0, ctx);
emit_reg_move(MIPS_R_A1, r_off, ctx);
if (config_enabled(CONFIG_64BIT)) {
emit_dsrl32(r_s0, r_val, 0, ctx);
emit_bcond(MIPS_COND_NE, r_s0, r_zero, 3 << 2,
ctx);
} else {
emit_bcond(MIPS_COND_NE, r_err, r_zero, 3 << 2,
ctx);
}
emit_nop(ctx);
emit_b(b_imm(i + 1, ctx), ctx);
emit_jit_reg_move(r_A, r_val, ctx);
emit_b(b_imm(prog->len, ctx), ctx);
emit_reg_move(r_ret, r_zero, ctx);
break;
case BPF_LD | BPF_W | BPF_IND:
load_order = 2;
goto load_ind;
case BPF_LD | BPF_H | BPF_IND:
load_order = 1;
goto load_ind;
case BPF_LD | BPF_B | BPF_IND:
load_order = 0;
load_ind:
ctx->flags |= SEEN_OFF | SEEN_X;
emit_addiu(r_off, r_X, k, ctx);
goto load_common;
case BPF_LDX | BPF_IMM:
ctx->flags |= SEEN_X;
emit_load_imm(r_X, k, ctx);
break;
case BPF_LDX | BPF_MEM:
ctx->flags |= SEEN_X | SEEN_MEM;
emit_load(r_X, r_M, SCRATCH_OFF(k), ctx);
break;
case BPF_LDX | BPF_W | BPF_LEN:
ctx->flags |= SEEN_X | SEEN_SKB;
off = offsetof(struct sk_buff, len);
emit_load(r_X, r_skb, off, ctx);
break;
case BPF_LDX | BPF_B | BPF_MSH:
if ((int)k < 0)
return -ENOTSUPP;
ctx->flags |= SEEN_X | SEEN_CALL | SEEN_S0 | SEEN_SKB;
emit_load_func(r_s0, (ptr)jit_get_skb_b, ctx);
emit_load_imm(MIPS_R_A1, k, ctx);
emit_jalr(MIPS_R_RA, r_s0, ctx);
emit_reg_move(MIPS_R_A0, r_skb, ctx);
if (config_enabled(CONFIG_64BIT)) {
emit_dsrl32(r_s0, r_val, 0, ctx);
emit_bcond(MIPS_COND_NE, r_s0, r_zero,
3 << 2, ctx);
} else {
emit_bcond(MIPS_COND_NE, r_err, r_zero,
3 << 2, ctx);
}
emit_andi(r_X, r_val, 0xf, ctx);
emit_b(b_imm(i + 1, ctx), ctx);
emit_sll(r_X, r_X, 2, ctx);
emit_b(b_imm(prog->len, ctx), ctx);
emit_load_imm(r_ret, 0, ctx);
break;
case BPF_ST:
ctx->flags |= SEEN_MEM | SEEN_A;
emit_store(r_A, r_M, SCRATCH_OFF(k), ctx);
break;
case BPF_STX:
ctx->flags |= SEEN_MEM | SEEN_X;
emit_store(r_X, r_M, SCRATCH_OFF(k), ctx);
break;
case BPF_ALU | BPF_ADD | BPF_K:
ctx->flags |= SEEN_A;
emit_addiu(r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_ADD | BPF_X:
ctx->flags |= SEEN_A | SEEN_X;
emit_addu(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_SUB | BPF_K:
ctx->flags |= SEEN_A;
emit_addiu(r_A, r_A, -k, ctx);
break;
case BPF_ALU | BPF_SUB | BPF_X:
ctx->flags |= SEEN_A | SEEN_X;
emit_subu(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_MUL | BPF_K:
ctx->flags |= SEEN_A | SEEN_S0;
emit_load_imm(r_s0, k, ctx);
emit_mul(r_A, r_A, r_s0, ctx);
break;
case BPF_ALU | BPF_MUL | BPF_X:
ctx->flags |= SEEN_A | SEEN_X;
emit_mul(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_DIV | BPF_K:
if (k == 1)
break;
if (optimize_div(&k)) {
ctx->flags |= SEEN_A;
emit_srl(r_A, r_A, k, ctx);
break;
}
ctx->flags |= SEEN_A | SEEN_S0;
emit_load_imm(r_s0, k, ctx);
emit_div(r_A, r_s0, ctx);
break;
case BPF_ALU | BPF_MOD | BPF_K:
if (k == 1 || optimize_div(&k)) {
ctx->flags |= SEEN_A;
emit_jit_reg_move(r_A, r_zero, ctx);
} else {
ctx->flags |= SEEN_A | SEEN_S0;
emit_load_imm(r_s0, k, ctx);
emit_mod(r_A, r_s0, ctx);
}
break;
case BPF_ALU | BPF_DIV | BPF_X:
ctx->flags |= SEEN_X | SEEN_A;
emit_bcond(MIPS_COND_EQ, r_X, r_zero,
b_imm(prog->len, ctx), ctx);
emit_load_imm(r_val, 0, ctx);
emit_div(r_A, r_X, ctx);
break;
case BPF_ALU | BPF_MOD | BPF_X:
ctx->flags |= SEEN_X | SEEN_A;
emit_bcond(MIPS_COND_EQ, r_X, r_zero,
b_imm(prog->len, ctx), ctx);
emit_load_imm(r_val, 0, ctx);
emit_mod(r_A, r_X, ctx);
break;
case BPF_ALU | BPF_OR | BPF_K:
ctx->flags |= SEEN_A;
emit_ori(r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_OR | BPF_X:
ctx->flags |= SEEN_A;
emit_ori(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_XOR | BPF_K:
ctx->flags |= SEEN_A;
emit_xori(r_A, r_A, k, ctx);
break;
case BPF_ANC | SKF_AD_ALU_XOR_X:
case BPF_ALU | BPF_XOR | BPF_X:
ctx->flags |= SEEN_A;
emit_xor(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_AND | BPF_K:
ctx->flags |= SEEN_A;
emit_andi(r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_AND | BPF_X:
ctx->flags |= SEEN_A | SEEN_X;
emit_and(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_LSH | BPF_K:
ctx->flags |= SEEN_A;
emit_sll(r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_LSH | BPF_X:
ctx->flags |= SEEN_A | SEEN_X;
emit_sllv(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_RSH | BPF_K:
ctx->flags |= SEEN_A;
emit_srl(r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_RSH | BPF_X:
ctx->flags |= SEEN_A | SEEN_X;
emit_srlv(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_NEG:
ctx->flags |= SEEN_A;
emit_neg(r_A, ctx);
break;
case BPF_JMP | BPF_JA:
emit_b(b_imm(i + k + 1, ctx), ctx);
emit_nop(ctx);
break;
case BPF_JMP | BPF_JEQ | BPF_K:
condt = MIPS_COND_EQ | MIPS_COND_K;
goto jmp_cmp;
case BPF_JMP | BPF_JEQ | BPF_X:
ctx->flags |= SEEN_X;
condt = MIPS_COND_EQ | MIPS_COND_X;
goto jmp_cmp;
case BPF_JMP | BPF_JGE | BPF_K:
condt = MIPS_COND_GE | MIPS_COND_K;
goto jmp_cmp;
case BPF_JMP | BPF_JGE | BPF_X:
ctx->flags |= SEEN_X;
condt = MIPS_COND_GE | MIPS_COND_X;
goto jmp_cmp;
case BPF_JMP | BPF_JGT | BPF_K:
condt = MIPS_COND_GT | MIPS_COND_K;
goto jmp_cmp;
case BPF_JMP | BPF_JGT | BPF_X:
ctx->flags |= SEEN_X;
condt = MIPS_COND_GT | MIPS_COND_X;
jmp_cmp:
if ((condt & MIPS_COND_GE) ||
(condt & MIPS_COND_GT)) {
if (condt & MIPS_COND_K) {
ctx->flags |= SEEN_S0 | SEEN_A;
emit_sltiu(r_s0, r_A, k, ctx);
} else {
ctx->flags |= SEEN_S0 | SEEN_A |
SEEN_X;
emit_sltu(r_s0, r_A, r_X, ctx);
}
b_off = b_imm(i + inst->jf + 1, ctx);
emit_bcond(MIPS_COND_NE, r_s0, r_zero, b_off,
ctx);
emit_nop(ctx);
if (condt & MIPS_COND_GT) {
ctx->flags |= SEEN_S0 | SEEN_A | SEEN_X;
if (condt & MIPS_COND_K)
emit_load_imm(r_s0, k, ctx);
else
emit_jit_reg_move(r_s0, r_X,
ctx);
b_off = b_imm(i + inst->jf + 1, ctx);
emit_bcond(MIPS_COND_EQ, r_A, r_s0,
b_off, ctx);
emit_nop(ctx);
b_off = b_imm(i + inst->jt + 1, ctx);
emit_b(b_off, ctx);
emit_nop(ctx);
} else {
b_off = b_imm(i + inst->jt + 1, ctx);
emit_b(b_off, ctx);
emit_nop(ctx);
}
} else {
if (condt & MIPS_COND_K) {
ctx->flags |= SEEN_S0 | SEEN_A;
emit_load_imm(r_s0, k, ctx);
b_off = b_imm(i + inst->jt + 1, ctx);
emit_bcond(MIPS_COND_EQ, r_A, r_s0,
b_off, ctx);
emit_nop(ctx);
b_off = b_imm(i + inst->jf + 1,
ctx);
emit_bcond(MIPS_COND_NE, r_A, r_s0,
b_off, ctx);
emit_nop(ctx);
} else {
ctx->flags |= SEEN_A | SEEN_X;
b_off = b_imm(i + inst->jt + 1,
ctx);
emit_bcond(MIPS_COND_EQ, r_A, r_X,
b_off, ctx);
emit_nop(ctx);
b_off = b_imm(i + inst->jf + 1, ctx);
emit_bcond(MIPS_COND_NE, r_A, r_X,
b_off, ctx);
emit_nop(ctx);
}
}
break;
case BPF_JMP | BPF_JSET | BPF_K:
ctx->flags |= SEEN_S0 | SEEN_S1 | SEEN_A;
emit_load_imm(r_s1, k, ctx);
emit_and(r_s0, r_A, r_s1, ctx);
b_off = b_imm(i + inst->jt + 1, ctx);
emit_bcond(MIPS_COND_NE, r_s0, r_zero, b_off, ctx);
emit_nop(ctx);
b_off = b_imm(i + inst->jf + 1, ctx);
emit_b(b_off, ctx);
emit_nop(ctx);
break;
case BPF_JMP | BPF_JSET | BPF_X:
ctx->flags |= SEEN_S0 | SEEN_X | SEEN_A;
emit_and(r_s0, r_A, r_X, ctx);
b_off = b_imm(i + inst->jt + 1, ctx);
emit_bcond(MIPS_COND_NE, r_s0, r_zero, b_off, ctx);
emit_nop(ctx);
b_off = b_imm(i + inst->jf + 1, ctx);
emit_b(b_off, ctx);
emit_nop(ctx);
break;
case BPF_RET | BPF_A:
ctx->flags |= SEEN_A;
if (i != prog->len - 1)
emit_b(b_imm(prog->len, ctx), ctx);
emit_reg_move(r_ret, r_A, ctx);
break;
case BPF_RET | BPF_K:
emit_load_imm(r_ret, k, ctx);
if (i != prog->len - 1) {
emit_b(b_imm(prog->len, ctx), ctx);
emit_nop(ctx);
}
break;
case BPF_MISC | BPF_TAX:
ctx->flags |= SEEN_X | SEEN_A;
emit_jit_reg_move(r_X, r_A, ctx);
break;
case BPF_MISC | BPF_TXA:
ctx->flags |= SEEN_A | SEEN_X;
emit_jit_reg_move(r_A, r_X, ctx);
break;
case BPF_ANC | SKF_AD_PROTOCOL:
ctx->flags |= SEEN_SKB | SEEN_OFF | SEEN_A;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff,
protocol) != 2);
off = offsetof(struct sk_buff, protocol);
emit_half_load(r_A, r_skb, off, ctx);
#ifdef CONFIG_CPU_LITTLE_ENDIAN
if (cpu_has_wsbh) {
emit_wsbh(r_A, r_A, ctx);
} else {
emit_andi(r_tmp_imm, r_A, 0xff, ctx);
emit_sll(r_tmp, r_tmp_imm, 8, ctx);
emit_srl(r_tmp_imm, r_A, 8, ctx);
emit_andi(r_tmp_imm, r_tmp_imm, 0xff, ctx);
emit_or(r_A, r_tmp, r_tmp_imm, ctx);
}
#endif
break;
case BPF_ANC | SKF_AD_CPU:
ctx->flags |= SEEN_A | SEEN_OFF;
BUILD_BUG_ON(FIELD_SIZEOF(struct thread_info,
cpu) != 4);
off = offsetof(struct thread_info, cpu);
emit_load(r_A, 28, off, ctx);
break;
case BPF_ANC | SKF_AD_IFINDEX:
ctx->flags |= SEEN_SKB | SEEN_A | SEEN_S0;
off = offsetof(struct sk_buff, dev);
emit_load_ptr(r_s0, r_skb, off, ctx);
emit_bcond(MIPS_COND_EQ, r_s0, r_zero,
b_imm(prog->len, ctx), ctx);
emit_reg_move(r_ret, r_zero, ctx);
BUILD_BUG_ON(FIELD_SIZEOF(struct net_device,
ifindex) != 4);
off = offsetof(struct net_device, ifindex);
emit_load(r_A, r_s0, off, ctx);
break;
case BPF_ANC | SKF_AD_MARK:
ctx->flags |= SEEN_SKB | SEEN_A;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, mark) != 4);
off = offsetof(struct sk_buff, mark);
emit_load(r_A, r_skb, off, ctx);
break;
case BPF_ANC | SKF_AD_RXHASH:
ctx->flags |= SEEN_SKB | SEEN_A;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, hash) != 4);
off = offsetof(struct sk_buff, hash);
emit_load(r_A, r_skb, off, ctx);
break;
case BPF_ANC | SKF_AD_VLAN_TAG:
case BPF_ANC | SKF_AD_VLAN_TAG_PRESENT:
ctx->flags |= SEEN_SKB | SEEN_S0 | SEEN_A;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff,
vlan_tci) != 2);
off = offsetof(struct sk_buff, vlan_tci);
emit_half_load(r_s0, r_skb, off, ctx);
if (code == (BPF_ANC | SKF_AD_VLAN_TAG)) {
emit_andi(r_A, r_s0, (u16)~VLAN_TAG_PRESENT, ctx);
} else {
emit_andi(r_A, r_s0, VLAN_TAG_PRESENT, ctx);
emit_sltu(r_A, r_zero, r_A, ctx);
}
break;
case BPF_ANC | SKF_AD_PKTTYPE:
ctx->flags |= SEEN_SKB;
emit_load_byte(r_tmp, r_skb, PKT_TYPE_OFFSET(), ctx);
emit_andi(r_A, r_tmp, PKT_TYPE_MAX, ctx);
#ifdef __BIG_ENDIAN_BITFIELD
emit_srl(r_A, r_A, 5, ctx);
#endif
break;
case BPF_ANC | SKF_AD_QUEUE:
ctx->flags |= SEEN_SKB | SEEN_A;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff,
queue_mapping) != 2);
BUILD_BUG_ON(offsetof(struct sk_buff,
queue_mapping) > 0xff);
off = offsetof(struct sk_buff, queue_mapping);
emit_half_load(r_A, r_skb, off, ctx);
break;
default:
pr_debug("%s: Unhandled opcode: 0x%02x\n", __FILE__,
inst->code);
return -1;
}
}
if (ctx->target == NULL)
ctx->offsets[i] = ctx->idx * 4;
return 0;
}
void bpf_jit_compile(struct bpf_prog *fp)
{
struct jit_ctx ctx;
unsigned int alloc_size, tmp_idx;
if (!bpf_jit_enable)
return;
memset(&ctx, 0, sizeof(ctx));
ctx.offsets = kcalloc(fp->len, sizeof(*ctx.offsets), GFP_KERNEL);
if (ctx.offsets == NULL)
return;
ctx.skf = fp;
if (build_body(&ctx))
goto out;
tmp_idx = ctx.idx;
build_prologue(&ctx);
ctx.prologue_bytes = (ctx.idx - tmp_idx) * 4;
build_epilogue(&ctx);
alloc_size = 4 * ctx.idx;
ctx.target = module_alloc(alloc_size);
if (ctx.target == NULL)
goto out;
memset(ctx.target, 0, alloc_size);
ctx.idx = 0;
build_prologue(&ctx);
build_body(&ctx);
build_epilogue(&ctx);
flush_icache_range((ptr)ctx.target, (ptr)(ctx.target + ctx.idx));
if (bpf_jit_enable > 1)
bpf_jit_dump(fp->len, alloc_size, 2, ctx.target);
fp->bpf_func = (void *)ctx.target;
fp->jited = true;
out:
kfree(ctx.offsets);
}
void bpf_jit_free(struct bpf_prog *fp)
{
if (fp->jited)
module_free(NULL, fp->bpf_func);
bpf_prog_unlock_free(fp);
}
