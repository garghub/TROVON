static void bpf_jit_fill_ill_insns(void *area, unsigned int size)
{
int *p = area;
while (p < (int *)((char *)area + size))
*p++ = BREAKPOINT_INSTRUCTION;
}
static inline void bpf_flush_icache(void *start, void *end)
{
smp_wmb();
flush_icache_range((unsigned long)start, (unsigned long)end);
}
static inline bool bpf_is_seen_register(struct codegen_context *ctx, int i)
{
return (ctx->seen & (1 << (31 - b2p[i])));
}
static inline void bpf_set_seen_register(struct codegen_context *ctx, int i)
{
ctx->seen |= (1 << (31 - b2p[i]));
}
static inline bool bpf_has_stack_frame(struct codegen_context *ctx)
{
return ctx->seen & SEEN_FUNC || bpf_is_seen_register(ctx, BPF_REG_FP);
}
static void bpf_jit_emit_skb_loads(u32 *image, struct codegen_context *ctx)
{
PPC_LWZ(b2p[SKB_HLEN_REG], 3, offsetof(struct sk_buff, len));
PPC_LWZ(b2p[TMP_REG_1], 3, offsetof(struct sk_buff, data_len));
PPC_SUB(b2p[SKB_HLEN_REG], b2p[SKB_HLEN_REG], b2p[TMP_REG_1]);
PPC_BPF_LL(b2p[SKB_DATA_REG], 3, offsetof(struct sk_buff, data));
}
static void bpf_jit_emit_func_call(u32 *image, struct codegen_context *ctx, u64 func)
{
#ifdef PPC64_ELF_ABI_v1
PPC_LI64(b2p[TMP_REG_2], func);
PPC_BPF_LL(b2p[TMP_REG_1], b2p[TMP_REG_2], 0);
PPC_MTLR(b2p[TMP_REG_1]);
PPC_BPF_LL(2, b2p[TMP_REG_2], 8);
#else
PPC_FUNC_ADDR(12, func);
PPC_MTLR(12);
#endif
PPC_BLRL();
}
static void bpf_jit_build_prologue(u32 *image, struct codegen_context *ctx)
{
int i;
bool new_stack_frame = bpf_has_stack_frame(ctx);
if (new_stack_frame) {
if (ctx->seen & SEEN_FUNC) {
EMIT(PPC_INST_MFLR | __PPC_RT(R0));
PPC_BPF_STL(0, 1, PPC_LR_STKOFF);
}
PPC_BPF_STLU(1, 1, -BPF_PPC_STACKFRAME);
}
for (i = BPF_REG_6; i <= BPF_REG_10; i++)
if (bpf_is_seen_register(ctx, i))
PPC_BPF_STL(b2p[i], 1,
(new_stack_frame ? BPF_PPC_STACKFRAME : 0) -
(8 * (32 - b2p[i])));
if (ctx->seen & SEEN_SKB) {
PPC_BPF_STL(b2p[SKB_HLEN_REG], 1,
BPF_PPC_STACKFRAME - (8 * (32 - b2p[SKB_HLEN_REG])));
PPC_BPF_STL(b2p[SKB_DATA_REG], 1,
BPF_PPC_STACKFRAME - (8 * (32 - b2p[SKB_DATA_REG])));
bpf_jit_emit_skb_loads(image, ctx);
}
if (bpf_is_seen_register(ctx, BPF_REG_FP))
PPC_ADDI(b2p[BPF_REG_FP], 1,
BPF_PPC_STACKFRAME - BPF_PPC_STACK_SAVE);
}
static void bpf_jit_build_epilogue(u32 *image, struct codegen_context *ctx)
{
int i;
bool new_stack_frame = bpf_has_stack_frame(ctx);
PPC_MR(3, b2p[BPF_REG_0]);
for (i = BPF_REG_6; i <= BPF_REG_10; i++)
if (bpf_is_seen_register(ctx, i))
PPC_BPF_LL(b2p[i], 1,
(new_stack_frame ? BPF_PPC_STACKFRAME : 0) -
(8 * (32 - b2p[i])));
if (ctx->seen & SEEN_SKB) {
PPC_BPF_LL(b2p[SKB_HLEN_REG], 1,
BPF_PPC_STACKFRAME - (8 * (32 - b2p[SKB_HLEN_REG])));
PPC_BPF_LL(b2p[SKB_DATA_REG], 1,
BPF_PPC_STACKFRAME - (8 * (32 - b2p[SKB_DATA_REG])));
}
if (new_stack_frame) {
PPC_ADDI(1, 1, BPF_PPC_STACKFRAME);
if (ctx->seen & SEEN_FUNC) {
PPC_BPF_LL(0, 1, PPC_LR_STKOFF);
PPC_MTLR(0);
}
}
PPC_BLR();
}
static int bpf_jit_build_body(struct bpf_prog *fp, u32 *image,
struct codegen_context *ctx,
u32 *addrs)
{
const struct bpf_insn *insn = fp->insnsi;
int flen = fp->len;
int i;
u32 exit_addr = addrs[flen];
for (i = 0; i < flen; i++) {
u32 code = insn[i].code;
u32 dst_reg = b2p[insn[i].dst_reg];
u32 src_reg = b2p[insn[i].src_reg];
s16 off = insn[i].off;
s32 imm = insn[i].imm;
u64 imm64;
u8 *func;
u32 true_cond;
int stack_local_off;
addrs[i] = ctx->idx * 4;
if (dst_reg >= 24 && dst_reg <= 31)
bpf_set_seen_register(ctx, insn[i].dst_reg);
if (src_reg >= 24 && src_reg <= 31)
bpf_set_seen_register(ctx, insn[i].src_reg);
switch (code) {
case BPF_ALU | BPF_ADD | BPF_X:
case BPF_ALU64 | BPF_ADD | BPF_X:
PPC_ADD(dst_reg, dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_SUB | BPF_X:
case BPF_ALU64 | BPF_SUB | BPF_X:
PPC_SUB(dst_reg, dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_ADD | BPF_K:
case BPF_ALU | BPF_SUB | BPF_K:
case BPF_ALU64 | BPF_ADD | BPF_K:
case BPF_ALU64 | BPF_SUB | BPF_K:
if (BPF_OP(code) == BPF_SUB)
imm = -imm;
if (imm) {
if (imm >= -32768 && imm < 32768)
PPC_ADDI(dst_reg, dst_reg, IMM_L(imm));
else {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_ADD(dst_reg, dst_reg, b2p[TMP_REG_1]);
}
}
goto bpf_alu32_trunc;
case BPF_ALU | BPF_MUL | BPF_X:
case BPF_ALU64 | BPF_MUL | BPF_X:
if (BPF_CLASS(code) == BPF_ALU)
PPC_MULW(dst_reg, dst_reg, src_reg);
else
PPC_MULD(dst_reg, dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_MUL | BPF_K:
case BPF_ALU64 | BPF_MUL | BPF_K:
if (imm >= -32768 && imm < 32768)
PPC_MULI(dst_reg, dst_reg, IMM_L(imm));
else {
PPC_LI32(b2p[TMP_REG_1], imm);
if (BPF_CLASS(code) == BPF_ALU)
PPC_MULW(dst_reg, dst_reg,
b2p[TMP_REG_1]);
else
PPC_MULD(dst_reg, dst_reg,
b2p[TMP_REG_1]);
}
goto bpf_alu32_trunc;
case BPF_ALU | BPF_DIV | BPF_X:
case BPF_ALU | BPF_MOD | BPF_X:
PPC_CMPWI(src_reg, 0);
PPC_BCC_SHORT(COND_NE, (ctx->idx * 4) + 12);
PPC_LI(b2p[BPF_REG_0], 0);
PPC_JMP(exit_addr);
if (BPF_OP(code) == BPF_MOD) {
PPC_DIVWU(b2p[TMP_REG_1], dst_reg, src_reg);
PPC_MULW(b2p[TMP_REG_1], src_reg,
b2p[TMP_REG_1]);
PPC_SUB(dst_reg, dst_reg, b2p[TMP_REG_1]);
} else
PPC_DIVWU(dst_reg, dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU64 | BPF_DIV | BPF_X:
case BPF_ALU64 | BPF_MOD | BPF_X:
PPC_CMPDI(src_reg, 0);
PPC_BCC_SHORT(COND_NE, (ctx->idx * 4) + 12);
PPC_LI(b2p[BPF_REG_0], 0);
PPC_JMP(exit_addr);
if (BPF_OP(code) == BPF_MOD) {
PPC_DIVD(b2p[TMP_REG_1], dst_reg, src_reg);
PPC_MULD(b2p[TMP_REG_1], src_reg,
b2p[TMP_REG_1]);
PPC_SUB(dst_reg, dst_reg, b2p[TMP_REG_1]);
} else
PPC_DIVD(dst_reg, dst_reg, src_reg);
break;
case BPF_ALU | BPF_MOD | BPF_K:
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU64 | BPF_MOD | BPF_K:
case BPF_ALU64 | BPF_DIV | BPF_K:
if (imm == 0)
return -EINVAL;
else if (imm == 1)
goto bpf_alu32_trunc;
PPC_LI32(b2p[TMP_REG_1], imm);
switch (BPF_CLASS(code)) {
case BPF_ALU:
if (BPF_OP(code) == BPF_MOD) {
PPC_DIVWU(b2p[TMP_REG_2], dst_reg,
b2p[TMP_REG_1]);
PPC_MULW(b2p[TMP_REG_1],
b2p[TMP_REG_1],
b2p[TMP_REG_2]);
PPC_SUB(dst_reg, dst_reg,
b2p[TMP_REG_1]);
} else
PPC_DIVWU(dst_reg, dst_reg,
b2p[TMP_REG_1]);
break;
case BPF_ALU64:
if (BPF_OP(code) == BPF_MOD) {
PPC_DIVD(b2p[TMP_REG_2], dst_reg,
b2p[TMP_REG_1]);
PPC_MULD(b2p[TMP_REG_1],
b2p[TMP_REG_1],
b2p[TMP_REG_2]);
PPC_SUB(dst_reg, dst_reg,
b2p[TMP_REG_1]);
} else
PPC_DIVD(dst_reg, dst_reg,
b2p[TMP_REG_1]);
break;
}
goto bpf_alu32_trunc;
case BPF_ALU | BPF_NEG:
case BPF_ALU64 | BPF_NEG:
PPC_NEG(dst_reg, dst_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_AND | BPF_X:
case BPF_ALU64 | BPF_AND | BPF_X:
PPC_AND(dst_reg, dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_AND | BPF_K:
case BPF_ALU64 | BPF_AND | BPF_K:
if (!IMM_H(imm))
PPC_ANDI(dst_reg, dst_reg, IMM_L(imm));
else {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_AND(dst_reg, dst_reg, b2p[TMP_REG_1]);
}
goto bpf_alu32_trunc;
case BPF_ALU | BPF_OR | BPF_X:
case BPF_ALU64 | BPF_OR | BPF_X:
PPC_OR(dst_reg, dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_OR | BPF_K:
case BPF_ALU64 | BPF_OR | BPF_K:
if (imm < 0 && BPF_CLASS(code) == BPF_ALU64) {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_OR(dst_reg, dst_reg, b2p[TMP_REG_1]);
} else {
if (IMM_L(imm))
PPC_ORI(dst_reg, dst_reg, IMM_L(imm));
if (IMM_H(imm))
PPC_ORIS(dst_reg, dst_reg, IMM_H(imm));
}
goto bpf_alu32_trunc;
case BPF_ALU | BPF_XOR | BPF_X:
case BPF_ALU64 | BPF_XOR | BPF_X:
PPC_XOR(dst_reg, dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_XOR | BPF_K:
case BPF_ALU64 | BPF_XOR | BPF_K:
if (imm < 0 && BPF_CLASS(code) == BPF_ALU64) {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_XOR(dst_reg, dst_reg, b2p[TMP_REG_1]);
} else {
if (IMM_L(imm))
PPC_XORI(dst_reg, dst_reg, IMM_L(imm));
if (IMM_H(imm))
PPC_XORIS(dst_reg, dst_reg, IMM_H(imm));
}
goto bpf_alu32_trunc;
case BPF_ALU | BPF_LSH | BPF_X:
PPC_SLW(dst_reg, dst_reg, src_reg);
break;
case BPF_ALU64 | BPF_LSH | BPF_X:
PPC_SLD(dst_reg, dst_reg, src_reg);
break;
case BPF_ALU | BPF_LSH | BPF_K:
PPC_SLWI(dst_reg, dst_reg, imm);
break;
case BPF_ALU64 | BPF_LSH | BPF_K:
if (imm != 0)
PPC_SLDI(dst_reg, dst_reg, imm);
break;
case BPF_ALU | BPF_RSH | BPF_X:
PPC_SRW(dst_reg, dst_reg, src_reg);
break;
case BPF_ALU64 | BPF_RSH | BPF_X:
PPC_SRD(dst_reg, dst_reg, src_reg);
break;
case BPF_ALU | BPF_RSH | BPF_K:
PPC_SRWI(dst_reg, dst_reg, imm);
break;
case BPF_ALU64 | BPF_RSH | BPF_K:
if (imm != 0)
PPC_SRDI(dst_reg, dst_reg, imm);
break;
case BPF_ALU64 | BPF_ARSH | BPF_X:
PPC_SRAD(dst_reg, dst_reg, src_reg);
break;
case BPF_ALU64 | BPF_ARSH | BPF_K:
if (imm != 0)
PPC_SRADI(dst_reg, dst_reg, imm);
break;
case BPF_ALU | BPF_MOV | BPF_X:
case BPF_ALU64 | BPF_MOV | BPF_X:
PPC_MR(dst_reg, src_reg);
goto bpf_alu32_trunc;
case BPF_ALU | BPF_MOV | BPF_K:
case BPF_ALU64 | BPF_MOV | BPF_K:
PPC_LI32(dst_reg, imm);
if (imm < 0)
goto bpf_alu32_trunc;
break;
bpf_alu32_trunc:
if (BPF_CLASS(code) == BPF_ALU)
PPC_RLWINM(dst_reg, dst_reg, 0, 0, 31);
break;
case BPF_ALU | BPF_END | BPF_FROM_LE:
case BPF_ALU | BPF_END | BPF_FROM_BE:
#ifdef __BIG_ENDIAN__
if (BPF_SRC(code) == BPF_FROM_BE)
goto emit_clear;
#else
if (BPF_SRC(code) == BPF_FROM_LE)
goto emit_clear;
#endif
switch (imm) {
case 16:
PPC_RLWINM(b2p[TMP_REG_1], dst_reg, 8, 16, 23);
PPC_RLWIMI(b2p[TMP_REG_1], dst_reg, 24, 24, 31);
PPC_MR(dst_reg, b2p[TMP_REG_1]);
break;
case 32:
PPC_RLWINM(b2p[TMP_REG_1], dst_reg, 8, 0, 31);
PPC_RLWIMI(b2p[TMP_REG_1], dst_reg, 24, 0, 7);
PPC_RLWIMI(b2p[TMP_REG_1], dst_reg, 24, 16, 23);
PPC_MR(dst_reg, b2p[TMP_REG_1]);
break;
case 64:
if (bpf_has_stack_frame(ctx))
stack_local_off = STACK_FRAME_MIN_SIZE;
else
stack_local_off = -(BPF_PPC_STACK_SAVE + 8);
PPC_STD(dst_reg, 1, stack_local_off);
PPC_ADDI(b2p[TMP_REG_1], 1, stack_local_off);
PPC_LDBRX(dst_reg, 0, b2p[TMP_REG_1]);
break;
}
break;
emit_clear:
switch (imm) {
case 16:
PPC_RLDICL(dst_reg, dst_reg, 0, 48);
break;
case 32:
PPC_RLDICL(dst_reg, dst_reg, 0, 32);
break;
case 64:
break;
}
break;
case BPF_STX | BPF_MEM | BPF_B:
case BPF_ST | BPF_MEM | BPF_B:
if (BPF_CLASS(code) == BPF_ST) {
PPC_LI(b2p[TMP_REG_1], imm);
src_reg = b2p[TMP_REG_1];
}
PPC_STB(src_reg, dst_reg, off);
break;
case BPF_STX | BPF_MEM | BPF_H:
case BPF_ST | BPF_MEM | BPF_H:
if (BPF_CLASS(code) == BPF_ST) {
PPC_LI(b2p[TMP_REG_1], imm);
src_reg = b2p[TMP_REG_1];
}
PPC_STH(src_reg, dst_reg, off);
break;
case BPF_STX | BPF_MEM | BPF_W:
case BPF_ST | BPF_MEM | BPF_W:
if (BPF_CLASS(code) == BPF_ST) {
PPC_LI32(b2p[TMP_REG_1], imm);
src_reg = b2p[TMP_REG_1];
}
PPC_STW(src_reg, dst_reg, off);
break;
case BPF_STX | BPF_MEM | BPF_DW:
case BPF_ST | BPF_MEM | BPF_DW:
if (BPF_CLASS(code) == BPF_ST) {
PPC_LI32(b2p[TMP_REG_1], imm);
src_reg = b2p[TMP_REG_1];
}
PPC_STD(src_reg, dst_reg, off);
break;
case BPF_STX | BPF_XADD | BPF_W:
PPC_ADDI(b2p[TMP_REG_1], dst_reg, off);
PPC_ANDI(b2p[TMP_REG_2], b2p[TMP_REG_1], 0x03);
PPC_BCC_SHORT(COND_EQ, (ctx->idx * 4) + 12);
PPC_LI(b2p[BPF_REG_0], 0);
PPC_JMP(exit_addr);
PPC_BPF_LWARX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1], 0);
PPC_ADD(b2p[TMP_REG_2], b2p[TMP_REG_2], src_reg);
PPC_BPF_STWCX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1]);
PPC_BCC_SHORT(COND_EQ, (ctx->idx * 4) + (7*4));
PPC_BPF_LWARX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1], 0);
PPC_ADD(b2p[TMP_REG_2], b2p[TMP_REG_2], src_reg);
PPC_BPF_STWCX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1]);
PPC_LI(b2p[BPF_REG_0], 0);
PPC_BCC(COND_NE, exit_addr);
break;
case BPF_STX | BPF_XADD | BPF_DW:
PPC_ADDI(b2p[TMP_REG_1], dst_reg, off);
PPC_ANDI(b2p[TMP_REG_2], b2p[TMP_REG_1], 0x07);
PPC_BCC_SHORT(COND_EQ, (ctx->idx * 4) + (3*4));
PPC_LI(b2p[BPF_REG_0], 0);
PPC_JMP(exit_addr);
PPC_BPF_LDARX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1], 0);
PPC_ADD(b2p[TMP_REG_2], b2p[TMP_REG_2], src_reg);
PPC_BPF_STDCX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1]);
PPC_BCC_SHORT(COND_EQ, (ctx->idx * 4) + (7*4));
PPC_BPF_LDARX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1], 0);
PPC_ADD(b2p[TMP_REG_2], b2p[TMP_REG_2], src_reg);
PPC_BPF_STDCX(b2p[TMP_REG_2], 0, b2p[TMP_REG_1]);
PPC_LI(b2p[BPF_REG_0], 0);
PPC_BCC(COND_NE, exit_addr);
break;
case BPF_LDX | BPF_MEM | BPF_B:
PPC_LBZ(dst_reg, src_reg, off);
break;
case BPF_LDX | BPF_MEM | BPF_H:
PPC_LHZ(dst_reg, src_reg, off);
break;
case BPF_LDX | BPF_MEM | BPF_W:
PPC_LWZ(dst_reg, src_reg, off);
break;
case BPF_LDX | BPF_MEM | BPF_DW:
PPC_LD(dst_reg, src_reg, off);
break;
case BPF_LD | BPF_IMM | BPF_DW:
imm64 = ((u64)(u32) insn[i].imm) |
(((u64)(u32) insn[i+1].imm) << 32);
addrs[++i] = ctx->idx * 4;
PPC_LI64(dst_reg, imm64);
break;
case BPF_JMP | BPF_EXIT:
if (i != flen - 1)
PPC_JMP(exit_addr);
break;
case BPF_JMP | BPF_CALL:
ctx->seen |= SEEN_FUNC;
func = (u8 *) __bpf_call_base + imm;
if (bpf_helper_changes_skb_data(func))
PPC_BPF_STL(3, 1, STACK_FRAME_MIN_SIZE);
bpf_jit_emit_func_call(image, ctx, (u64)func);
PPC_MR(b2p[BPF_REG_0], 3);
if (bpf_helper_changes_skb_data(func)) {
PPC_BPF_LL(3, 1, STACK_FRAME_MIN_SIZE);
bpf_jit_emit_skb_loads(image, ctx);
}
break;
case BPF_JMP | BPF_JA:
PPC_JMP(addrs[i + 1 + off]);
break;
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JSGT | BPF_K:
case BPF_JMP | BPF_JSGT | BPF_X:
true_cond = COND_GT;
goto cond_branch;
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JSGE | BPF_K:
case BPF_JMP | BPF_JSGE | BPF_X:
true_cond = COND_GE;
goto cond_branch;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JEQ | BPF_X:
true_cond = COND_EQ;
goto cond_branch;
case BPF_JMP | BPF_JNE | BPF_K:
case BPF_JMP | BPF_JNE | BPF_X:
true_cond = COND_NE;
goto cond_branch;
case BPF_JMP | BPF_JSET | BPF_K:
case BPF_JMP | BPF_JSET | BPF_X:
true_cond = COND_NE;
cond_branch:
switch (code) {
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JNE | BPF_X:
PPC_CMPLD(dst_reg, src_reg);
break;
case BPF_JMP | BPF_JSGT | BPF_X:
case BPF_JMP | BPF_JSGE | BPF_X:
PPC_CMPD(dst_reg, src_reg);
break;
case BPF_JMP | BPF_JSET | BPF_X:
PPC_AND_DOT(b2p[TMP_REG_1], dst_reg, src_reg);
break;
case BPF_JMP | BPF_JNE | BPF_K:
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGE | BPF_K:
if (imm >= 0 && imm < 32768)
PPC_CMPLDI(dst_reg, imm);
else {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_CMPLD(dst_reg, b2p[TMP_REG_1]);
}
break;
case BPF_JMP | BPF_JSGT | BPF_K:
case BPF_JMP | BPF_JSGE | BPF_K:
if (imm >= -32768 && imm < 32768)
PPC_CMPDI(dst_reg, imm);
else {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_CMPD(dst_reg, b2p[TMP_REG_1]);
}
break;
case BPF_JMP | BPF_JSET | BPF_K:
if (imm >= 0 && imm < 32768)
PPC_ANDI(b2p[TMP_REG_1], dst_reg, imm);
else {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_AND_DOT(b2p[TMP_REG_1], dst_reg,
b2p[TMP_REG_1]);
}
break;
}
PPC_BCC(true_cond, addrs[i + 1 + off]);
break;
case BPF_LD | BPF_W | BPF_ABS:
func = (u8 *)CHOOSE_LOAD_FUNC(imm, sk_load_word);
goto common_load_abs;
case BPF_LD | BPF_H | BPF_ABS:
func = (u8 *)CHOOSE_LOAD_FUNC(imm, sk_load_half);
goto common_load_abs;
case BPF_LD | BPF_B | BPF_ABS:
func = (u8 *)CHOOSE_LOAD_FUNC(imm, sk_load_byte);
common_load_abs:
PPC_LI32(4, imm);
goto common_load;
case BPF_LD | BPF_W | BPF_IND:
func = (u8 *)sk_load_word;
goto common_load_ind;
case BPF_LD | BPF_H | BPF_IND:
func = (u8 *)sk_load_half;
goto common_load_ind;
case BPF_LD | BPF_B | BPF_IND:
func = (u8 *)sk_load_byte;
common_load_ind:
PPC_EXTSW(4, src_reg);
if (imm) {
if (imm >= -32768 && imm < 32768)
PPC_ADDI(4, 4, IMM_L(imm));
else {
PPC_LI32(b2p[TMP_REG_1], imm);
PPC_ADD(4, 4, b2p[TMP_REG_1]);
}
}
common_load:
ctx->seen |= SEEN_SKB;
ctx->seen |= SEEN_FUNC;
bpf_jit_emit_func_call(image, ctx, (u64)func);
PPC_BCC(COND_LT, exit_addr);
break;
case BPF_JMP | BPF_CALL | BPF_X:
default:
pr_err_ratelimited("eBPF filter opcode %04x (@%d) unsupported\n",
code, i);
return -ENOTSUPP;
}
}
addrs[i] = ctx->idx * 4;
return 0;
}
void bpf_jit_compile(struct bpf_prog *fp) { }
struct bpf_prog *bpf_int_jit_compile(struct bpf_prog *fp)
{
u32 proglen;
u32 alloclen;
u8 *image = NULL;
u32 *code_base;
u32 *addrs;
struct codegen_context cgctx;
int pass;
int flen;
struct bpf_binary_header *bpf_hdr;
if (!bpf_jit_enable)
return fp;
flen = fp->len;
addrs = kzalloc((flen+1) * sizeof(*addrs), GFP_KERNEL);
if (addrs == NULL)
return fp;
cgctx.idx = 0;
cgctx.seen = 0;
if (bpf_jit_build_body(fp, 0, &cgctx, addrs))
goto out;
bpf_jit_build_prologue(0, &cgctx);
bpf_jit_build_epilogue(0, &cgctx);
proglen = cgctx.idx * 4;
alloclen = proglen + FUNCTION_DESCR_SIZE;
bpf_hdr = bpf_jit_binary_alloc(alloclen, &image, 4,
bpf_jit_fill_ill_insns);
if (!bpf_hdr)
goto out;
code_base = (u32 *)(image + FUNCTION_DESCR_SIZE);
for (pass = 1; pass < 3; pass++) {
cgctx.idx = 0;
bpf_jit_build_prologue(code_base, &cgctx);
bpf_jit_build_body(fp, code_base, &cgctx, addrs);
bpf_jit_build_epilogue(code_base, &cgctx);
if (bpf_jit_enable > 1)
pr_info("Pass %d: shrink = %d, seen = 0x%x\n", pass,
proglen - (cgctx.idx * 4), cgctx.seen);
}
if (bpf_jit_enable > 1)
bpf_jit_dump(flen, proglen, pass, code_base);
if (image) {
bpf_flush_icache(bpf_hdr, image + alloclen);
#ifdef PPC64_ELF_ABI_v1
((u64 *)image)[0] = (u64)code_base;
((u64 *)image)[1] = local_paca->kernel_toc;
#endif
fp->bpf_func = (void *)image;
fp->jited = 1;
}
out:
kfree(addrs);
return fp;
}
void bpf_jit_free(struct bpf_prog *fp)
{
unsigned long addr = (unsigned long)fp->bpf_func & PAGE_MASK;
struct bpf_binary_header *bpf_hdr = (void *)addr;
if (fp->jited)
bpf_jit_binary_free(bpf_hdr);
bpf_prog_unlock_free(fp);
}
