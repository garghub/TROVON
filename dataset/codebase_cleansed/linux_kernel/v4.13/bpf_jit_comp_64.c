static inline bool is_simm13(unsigned int value)
{
return value + 0x1000 < 0x2000;
}
static inline bool is_simm10(unsigned int value)
{
return value + 0x200 < 0x400;
}
static inline bool is_simm5(unsigned int value)
{
return value + 0x10 < 0x20;
}
static inline bool is_sethi(unsigned int value)
{
return (value & ~0x3fffff) == 0;
}
static void bpf_flush_icache(void *start_, void *end_)
{
if (tlb_type == spitfire) {
unsigned long start = (unsigned long) start_;
unsigned long end = (unsigned long) end_;
start &= ~7UL;
end = (end + 7UL) & ~7UL;
while (start < end) {
flushi(start);
start += 32;
}
}
}
static u32 WDISP10(u32 off)
{
u32 ret = ((off >> 2) & 0xff) << 5;
ret |= ((off >> (2 + 8)) & 0x03) << 19;
return ret;
}
static void emit(const u32 insn, struct jit_ctx *ctx)
{
if (ctx->image != NULL)
ctx->image[ctx->idx] = insn;
ctx->idx++;
}
static void emit_call(u32 *func, struct jit_ctx *ctx)
{
if (ctx->image != NULL) {
void *here = &ctx->image[ctx->idx];
unsigned int off;
off = (void *)func - here;
ctx->image[ctx->idx] = CALL | ((off >> 2) & 0x3fffffff);
}
ctx->idx++;
}
static void emit_nop(struct jit_ctx *ctx)
{
emit(SETHI(0, G0), ctx);
}
static void emit_reg_move(u32 from, u32 to, struct jit_ctx *ctx)
{
emit(OR | RS1(G0) | RS2(from) | RD(to), ctx);
}
static void emit_set_const(s32 K, u32 reg, struct jit_ctx *ctx)
{
emit(SETHI(K, reg), ctx);
emit(OR_LO(K, reg), ctx);
}
static void emit_set_const_sext(s32 K, u32 reg, struct jit_ctx *ctx)
{
if (K >= 0) {
emit(SETHI(K, reg), ctx);
emit(OR_LO(K, reg), ctx);
} else {
u32 hbits = ~(u32) K;
u32 lbits = -0x400 | (u32) K;
emit(SETHI(hbits, reg), ctx);
emit(XOR | IMMED | RS1(reg) | S13(lbits) | RD(reg), ctx);
}
}
static void emit_alu(u32 opcode, u32 src, u32 dst, struct jit_ctx *ctx)
{
emit(opcode | RS1(dst) | RS2(src) | RD(dst), ctx);
}
static void emit_alu3(u32 opcode, u32 a, u32 b, u32 c, struct jit_ctx *ctx)
{
emit(opcode | RS1(a) | RS2(b) | RD(c), ctx);
}
static void emit_alu_K(unsigned int opcode, unsigned int dst, unsigned int imm,
struct jit_ctx *ctx)
{
bool small_immed = is_simm13(imm);
unsigned int insn = opcode;
insn |= RS1(dst) | RD(dst);
if (small_immed) {
emit(insn | IMMED | S13(imm), ctx);
} else {
unsigned int tmp = bpf2sparc[TMP_REG_1];
ctx->tmp_1_used = true;
emit_set_const_sext(imm, tmp, ctx);
emit(insn | RS2(tmp), ctx);
}
}
static void emit_alu3_K(unsigned int opcode, unsigned int src, unsigned int imm,
unsigned int dst, struct jit_ctx *ctx)
{
bool small_immed = is_simm13(imm);
unsigned int insn = opcode;
insn |= RS1(src) | RD(dst);
if (small_immed) {
emit(insn | IMMED | S13(imm), ctx);
} else {
unsigned int tmp = bpf2sparc[TMP_REG_1];
ctx->tmp_1_used = true;
emit_set_const_sext(imm, tmp, ctx);
emit(insn | RS2(tmp), ctx);
}
}
static void emit_loadimm32(s32 K, unsigned int dest, struct jit_ctx *ctx)
{
if (K >= 0 && is_simm13(K)) {
emit(OR | IMMED | RS1(G0) | S13(K) | RD(dest), ctx);
} else {
emit_set_const(K, dest, ctx);
}
}
static void emit_loadimm(s32 K, unsigned int dest, struct jit_ctx *ctx)
{
if (is_simm13(K)) {
emit(OR | IMMED | RS1(G0) | S13(K) | RD(dest), ctx);
} else {
emit_set_const(K, dest, ctx);
}
}
static void emit_loadimm_sext(s32 K, unsigned int dest, struct jit_ctx *ctx)
{
if (is_simm13(K)) {
emit(OR | IMMED | RS1(G0) | S13(K) | RD(dest), ctx);
} else {
emit_set_const_sext(K, dest, ctx);
}
}
static void analyze_64bit_constant(u32 high_bits, u32 low_bits,
int *hbsp, int *lbsp, int *abbasp)
{
int lowest_bit_set, highest_bit_set, all_bits_between_are_set;
int i;
lowest_bit_set = highest_bit_set = -1;
i = 0;
do {
if ((lowest_bit_set == -1) && ((low_bits >> i) & 1))
lowest_bit_set = i;
if ((highest_bit_set == -1) && ((high_bits >> (32 - i - 1)) & 1))
highest_bit_set = (64 - i - 1);
} while (++i < 32 && (highest_bit_set == -1 ||
lowest_bit_set == -1));
if (i == 32) {
i = 0;
do {
if (lowest_bit_set == -1 && ((high_bits >> i) & 1))
lowest_bit_set = i + 32;
if (highest_bit_set == -1 &&
((low_bits >> (32 - i - 1)) & 1))
highest_bit_set = 32 - i - 1;
} while (++i < 32 && (highest_bit_set == -1 ||
lowest_bit_set == -1));
}
all_bits_between_are_set = 1;
for (i = lowest_bit_set; i <= highest_bit_set; i++) {
if (i < 32) {
if ((low_bits & (1 << i)) != 0)
continue;
} else {
if ((high_bits & (1 << (i - 32))) != 0)
continue;
}
all_bits_between_are_set = 0;
break;
}
*hbsp = highest_bit_set;
*lbsp = lowest_bit_set;
*abbasp = all_bits_between_are_set;
}
static unsigned long create_simple_focus_bits(unsigned long high_bits,
unsigned long low_bits,
int lowest_bit_set, int shift)
{
long hi, lo;
if (lowest_bit_set < 32) {
lo = (low_bits >> lowest_bit_set) << shift;
hi = ((high_bits << (32 - lowest_bit_set)) << shift);
} else {
lo = 0;
hi = ((high_bits >> (lowest_bit_set - 32)) << shift);
}
return hi | lo;
}
static bool const64_is_2insns(unsigned long high_bits,
unsigned long low_bits)
{
int highest_bit_set, lowest_bit_set, all_bits_between_are_set;
if (high_bits == 0 || high_bits == 0xffffffff)
return true;
analyze_64bit_constant(high_bits, low_bits,
&highest_bit_set, &lowest_bit_set,
&all_bits_between_are_set);
if ((highest_bit_set == 63 || lowest_bit_set == 0) &&
all_bits_between_are_set != 0)
return true;
if (highest_bit_set - lowest_bit_set < 21)
return true;
return false;
}
static void sparc_emit_set_const64_quick2(unsigned long high_bits,
unsigned long low_imm,
unsigned int dest,
int shift_count, struct jit_ctx *ctx)
{
emit_loadimm32(high_bits, dest, ctx);
emit_alu_K(SLLX, dest, shift_count, ctx);
if (low_imm != 0)
emit(OR | IMMED | RS1(dest) | S13(low_imm) | RD(dest), ctx);
}
static void emit_loadimm64(u64 K, unsigned int dest, struct jit_ctx *ctx)
{
int all_bits_between_are_set, lowest_bit_set, highest_bit_set;
unsigned int tmp = bpf2sparc[TMP_REG_1];
u32 low_bits = (K & 0xffffffff);
u32 high_bits = (K >> 32);
if (high_bits == 0xffffffff && (low_bits & 0x80000000))
return emit_loadimm_sext(K, dest, ctx);
if (high_bits == 0x00000000)
return emit_loadimm32(K, dest, ctx);
analyze_64bit_constant(high_bits, low_bits, &highest_bit_set,
&lowest_bit_set, &all_bits_between_are_set);
if (((highest_bit_set == 63 || lowest_bit_set == 0) &&
all_bits_between_are_set != 0) ||
((highest_bit_set - lowest_bit_set) < 12)) {
int shift = lowest_bit_set;
long the_const = -1;
if ((highest_bit_set != 63 && lowest_bit_set != 0) ||
all_bits_between_are_set == 0) {
the_const =
create_simple_focus_bits(high_bits, low_bits,
lowest_bit_set, 0);
} else if (lowest_bit_set == 0)
shift = -(63 - highest_bit_set);
emit(OR | IMMED | RS1(G0) | S13(the_const) | RD(dest), ctx);
if (shift > 0)
emit_alu_K(SLLX, dest, shift, ctx);
else if (shift < 0)
emit_alu_K(SRLX, dest, -shift, ctx);
return;
}
if ((highest_bit_set - lowest_bit_set) < 21) {
unsigned long focus_bits =
create_simple_focus_bits(high_bits, low_bits,
lowest_bit_set, 10);
emit(SETHI(focus_bits, dest), ctx);
if (lowest_bit_set < 10)
emit_alu_K(SRLX, dest, 10 - lowest_bit_set, ctx);
else if (lowest_bit_set > 10)
emit_alu_K(SLLX, dest, lowest_bit_set - 10, ctx);
return;
}
if (low_bits == 0) {
emit_loadimm32(high_bits, dest, ctx);
emit_alu_K(SLLX, dest, 32, ctx);
return;
}
if (const64_is_2insns((~high_bits) & 0xffffffff,
(~low_bits) & 0xfffffc00)) {
unsigned long trailing_bits = low_bits & 0x3ff;
if ((((~high_bits) & 0xffffffff) == 0 &&
((~low_bits) & 0x80000000) == 0) ||
(((~high_bits) & 0xffffffff) == 0xffffffff &&
((~low_bits) & 0x80000000) != 0)) {
unsigned long fast_int = (~low_bits & 0xffffffff);
if ((is_sethi(fast_int) &&
(~high_bits & 0xffffffff) == 0)) {
emit(SETHI(fast_int, dest), ctx);
} else if (is_simm13(fast_int)) {
emit(OR | IMMED | RS1(G0) | S13(fast_int) | RD(dest), ctx);
} else {
emit_loadimm64(fast_int, dest, ctx);
}
} else {
u64 n = ((~low_bits) & 0xfffffc00) |
(((unsigned long)((~high_bits) & 0xffffffff))<<32);
emit_loadimm64(n, dest, ctx);
}
low_bits = -0x400 | trailing_bits;
emit(XOR | IMMED | RS1(dest) | S13(low_bits) | RD(dest), ctx);
return;
}
if ((highest_bit_set - lowest_bit_set) < 32) {
unsigned long focus_bits =
create_simple_focus_bits(high_bits, low_bits,
lowest_bit_set, 0);
sparc_emit_set_const64_quick2(focus_bits, 0, dest,
lowest_bit_set, ctx);
return;
}
if (is_simm13(low_bits) && ((int)low_bits > 0)) {
sparc_emit_set_const64_quick2(high_bits, low_bits,
dest, 32, ctx);
return;
}
ctx->tmp_1_used = true;
emit_loadimm32(high_bits, tmp, ctx);
emit_loadimm32(low_bits, dest, ctx);
emit_alu_K(SLLX, tmp, 32, ctx);
emit(OR | RS1(dest) | RS2(tmp) | RD(dest), ctx);
}
static void emit_branch(unsigned int br_opc, unsigned int from_idx, unsigned int to_idx,
struct jit_ctx *ctx)
{
unsigned int off = to_idx - from_idx;
if (br_opc & XCC)
emit(br_opc | WDISP19(off << 2), ctx);
else
emit(br_opc | WDISP22(off << 2), ctx);
}
static void emit_cbcond(unsigned int cb_opc, unsigned int from_idx, unsigned int to_idx,
const u8 dst, const u8 src, struct jit_ctx *ctx)
{
unsigned int off = to_idx - from_idx;
emit(cb_opc | WDISP10(off << 2) | RS1(dst) | RS2(src), ctx);
}
static void emit_cbcondi(unsigned int cb_opc, unsigned int from_idx, unsigned int to_idx,
const u8 dst, s32 imm, struct jit_ctx *ctx)
{
unsigned int off = to_idx - from_idx;
emit(cb_opc | IMMED | WDISP10(off << 2) | RS1(dst) | S5(imm), ctx);
}
static int emit_compare_and_branch(const u8 code, const u8 dst, u8 src,
const s32 imm, bool is_imm, int branch_dst,
struct jit_ctx *ctx)
{
bool use_cbcond = (sparc64_elf_hwcap & AV_SPARC_CBCOND) != 0;
const u8 tmp = bpf2sparc[TMP_REG_1];
branch_dst = ctx->offset[branch_dst];
if (!is_simm10(branch_dst - ctx->idx) ||
BPF_OP(code) == BPF_JSET)
use_cbcond = false;
if (is_imm) {
bool fits = true;
if (use_cbcond) {
if (!is_simm5(imm))
fits = false;
} else if (!is_simm13(imm)) {
fits = false;
}
if (!fits) {
ctx->tmp_1_used = true;
emit_loadimm_sext(imm, tmp, ctx);
src = tmp;
is_imm = false;
}
}
if (!use_cbcond) {
u32 br_opcode;
if (BPF_OP(code) == BPF_JSET) {
if (is_imm)
emit_btsti(dst, imm, ctx);
else
emit_btst(dst, src, ctx);
} else {
if (is_imm)
emit_cmpi(dst, imm, ctx);
else
emit_cmp(dst, src, ctx);
}
switch (BPF_OP(code)) {
case BPF_JEQ:
br_opcode = BE;
break;
case BPF_JGT:
br_opcode = BGU;
break;
case BPF_JGE:
br_opcode = BGEU;
break;
case BPF_JSET:
case BPF_JNE:
br_opcode = BNE;
break;
case BPF_JSGT:
br_opcode = BG;
break;
case BPF_JSGE:
br_opcode = BGE;
break;
default:
return -EFAULT;
}
emit_branch(br_opcode, ctx->idx, branch_dst, ctx);
emit_nop(ctx);
} else {
u32 cbcond_opcode;
switch (BPF_OP(code)) {
case BPF_JEQ:
cbcond_opcode = CBCONDE;
break;
case BPF_JGT:
cbcond_opcode = CBCONDGU;
break;
case BPF_JGE:
cbcond_opcode = CBCONDGEU;
break;
case BPF_JNE:
cbcond_opcode = CBCONDNE;
break;
case BPF_JSGT:
cbcond_opcode = CBCONDG;
break;
case BPF_JSGE:
cbcond_opcode = CBCONDGE;
break;
default:
return -EFAULT;
}
cbcond_opcode |= CBCOND_OP;
if (is_imm)
emit_cbcondi(cbcond_opcode, ctx->idx, branch_dst,
dst, imm, ctx);
else
emit_cbcond(cbcond_opcode, ctx->idx, branch_dst,
dst, src, ctx);
}
return 0;
}
static void load_skb_regs(struct jit_ctx *ctx, u8 r_skb)
{
const u8 r_headlen = bpf2sparc[SKB_HLEN_REG];
const u8 r_data = bpf2sparc[SKB_DATA_REG];
const u8 r_tmp = bpf2sparc[TMP_REG_1];
unsigned int off;
off = offsetof(struct sk_buff, len);
emit(LD32I | RS1(r_skb) | S13(off) | RD(r_headlen), ctx);
off = offsetof(struct sk_buff, data_len);
emit(LD32I | RS1(r_skb) | S13(off) | RD(r_tmp), ctx);
emit(SUB | RS1(r_headlen) | RS2(r_tmp) | RD(r_headlen), ctx);
off = offsetof(struct sk_buff, data);
emit(LDPTRI | RS1(r_skb) | S13(off) | RD(r_data), ctx);
}
static void build_prologue(struct jit_ctx *ctx)
{
s32 stack_needed = BASE_STACKFRAME;
if (ctx->saw_frame_pointer || ctx->saw_tail_call) {
struct bpf_prog *prog = ctx->prog;
u32 stack_depth;
stack_depth = prog->aux->stack_depth;
stack_needed += round_up(stack_depth, 16);
}
if (ctx->saw_tail_call)
stack_needed += 8;
emit(SAVE | IMMED | RS1(SP) | S13(-stack_needed) | RD(SP), ctx);
if (ctx->saw_tail_call) {
u32 off = BPF_TAILCALL_CNT_SP_OFF;
emit(ST32 | IMMED | RS1(SP) | S13(off) | RD(G0), ctx);
} else {
emit_nop(ctx);
}
if (ctx->saw_frame_pointer) {
const u8 vfp = bpf2sparc[BPF_REG_FP];
emit(ADD | IMMED | RS1(FP) | S13(STACK_BIAS) | RD(vfp), ctx);
}
emit_reg_move(I0, O0, ctx);
if (ctx->saw_ld_abs_ind)
load_skb_regs(ctx, bpf2sparc[BPF_REG_1]);
}
static void build_epilogue(struct jit_ctx *ctx)
{
ctx->epilogue_offset = ctx->idx;
emit(JMPL | IMMED | RS1(I7) | S13(8) | RD(G0), ctx);
emit(RESTORE | RS1(bpf2sparc[BPF_REG_0]) | RS2(G0) | RD(O0), ctx);
}
static void emit_tail_call(struct jit_ctx *ctx)
{
const u8 bpf_array = bpf2sparc[BPF_REG_2];
const u8 bpf_index = bpf2sparc[BPF_REG_3];
const u8 tmp = bpf2sparc[TMP_REG_1];
u32 off;
ctx->saw_tail_call = true;
off = offsetof(struct bpf_array, map.max_entries);
emit(LD32 | IMMED | RS1(bpf_array) | S13(off) | RD(tmp), ctx);
emit_cmp(bpf_index, tmp, ctx);
#define OFFSET1 17
emit_branch(BGEU, ctx->idx, ctx->idx + OFFSET1, ctx);
emit_nop(ctx);
off = BPF_TAILCALL_CNT_SP_OFF;
emit(LD32 | IMMED | RS1(SP) | S13(off) | RD(tmp), ctx);
emit_cmpi(tmp, MAX_TAIL_CALL_CNT, ctx);
#define OFFSET2 13
emit_branch(BGU, ctx->idx, ctx->idx + OFFSET2, ctx);
emit_nop(ctx);
emit_alu_K(ADD, tmp, 1, ctx);
off = BPF_TAILCALL_CNT_SP_OFF;
emit(ST32 | IMMED | RS1(SP) | S13(off) | RD(tmp), ctx);
emit_alu3_K(SLL, bpf_index, 3, tmp, ctx);
emit_alu(ADD, bpf_array, tmp, ctx);
off = offsetof(struct bpf_array, ptrs);
emit(LD64 | IMMED | RS1(tmp) | S13(off) | RD(tmp), ctx);
emit_cmpi(tmp, 0, ctx);
#define OFFSET3 5
emit_branch(BE, ctx->idx, ctx->idx + OFFSET3, ctx);
emit_nop(ctx);
off = offsetof(struct bpf_prog, bpf_func);
emit(LD64 | IMMED | RS1(tmp) | S13(off) | RD(tmp), ctx);
off = BPF_TAILCALL_PROLOGUE_SKIP;
emit(JMPL | IMMED | RS1(tmp) | S13(off) | RD(G0), ctx);
emit_nop(ctx);
}
static int build_insn(const struct bpf_insn *insn, struct jit_ctx *ctx)
{
const u8 code = insn->code;
const u8 dst = bpf2sparc[insn->dst_reg];
const u8 src = bpf2sparc[insn->src_reg];
const int i = insn - ctx->prog->insnsi;
const s16 off = insn->off;
const s32 imm = insn->imm;
u32 *func;
if (insn->src_reg == BPF_REG_FP)
ctx->saw_frame_pointer = true;
switch (code) {
case BPF_ALU | BPF_MOV | BPF_X:
emit_alu3_K(SRL, src, 0, dst, ctx);
break;
case BPF_ALU64 | BPF_MOV | BPF_X:
emit_reg_move(src, dst, ctx);
break;
case BPF_ALU | BPF_ADD | BPF_X:
case BPF_ALU64 | BPF_ADD | BPF_X:
emit_alu(ADD, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_SUB | BPF_X:
case BPF_ALU64 | BPF_SUB | BPF_X:
emit_alu(SUB, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_AND | BPF_X:
case BPF_ALU64 | BPF_AND | BPF_X:
emit_alu(AND, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_OR | BPF_X:
case BPF_ALU64 | BPF_OR | BPF_X:
emit_alu(OR, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_XOR | BPF_X:
case BPF_ALU64 | BPF_XOR | BPF_X:
emit_alu(XOR, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_MUL | BPF_X:
emit_alu(MUL, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU64 | BPF_MUL | BPF_X:
emit_alu(MULX, src, dst, ctx);
break;
case BPF_ALU | BPF_DIV | BPF_X:
emit_cmp(src, G0, ctx);
emit_branch(BE|ANNUL, ctx->idx, ctx->epilogue_offset, ctx);
emit_loadimm(0, bpf2sparc[BPF_REG_0], ctx);
emit_write_y(G0, ctx);
emit_alu(DIV, src, dst, ctx);
break;
case BPF_ALU64 | BPF_DIV | BPF_X:
emit_cmp(src, G0, ctx);
emit_branch(BE|ANNUL, ctx->idx, ctx->epilogue_offset, ctx);
emit_loadimm(0, bpf2sparc[BPF_REG_0], ctx);
emit_alu(UDIVX, src, dst, ctx);
break;
case BPF_ALU | BPF_MOD | BPF_X: {
const u8 tmp = bpf2sparc[TMP_REG_1];
ctx->tmp_1_used = true;
emit_cmp(src, G0, ctx);
emit_branch(BE|ANNUL, ctx->idx, ctx->epilogue_offset, ctx);
emit_loadimm(0, bpf2sparc[BPF_REG_0], ctx);
emit_write_y(G0, ctx);
emit_alu3(DIV, dst, src, tmp, ctx);
emit_alu3(MULX, tmp, src, tmp, ctx);
emit_alu3(SUB, dst, tmp, dst, ctx);
goto do_alu32_trunc;
}
case BPF_ALU64 | BPF_MOD | BPF_X: {
const u8 tmp = bpf2sparc[TMP_REG_1];
ctx->tmp_1_used = true;
emit_cmp(src, G0, ctx);
emit_branch(BE|ANNUL, ctx->idx, ctx->epilogue_offset, ctx);
emit_loadimm(0, bpf2sparc[BPF_REG_0], ctx);
emit_alu3(UDIVX, dst, src, tmp, ctx);
emit_alu3(MULX, tmp, src, tmp, ctx);
emit_alu3(SUB, dst, tmp, dst, ctx);
break;
}
case BPF_ALU | BPF_LSH | BPF_X:
emit_alu(SLL, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU64 | BPF_LSH | BPF_X:
emit_alu(SLLX, src, dst, ctx);
break;
case BPF_ALU | BPF_RSH | BPF_X:
emit_alu(SRL, src, dst, ctx);
break;
case BPF_ALU64 | BPF_RSH | BPF_X:
emit_alu(SRLX, src, dst, ctx);
break;
case BPF_ALU | BPF_ARSH | BPF_X:
emit_alu(SRA, src, dst, ctx);
goto do_alu32_trunc;
case BPF_ALU64 | BPF_ARSH | BPF_X:
emit_alu(SRAX, src, dst, ctx);
break;
case BPF_ALU | BPF_NEG:
case BPF_ALU64 | BPF_NEG:
emit(SUB | RS1(0) | RS2(dst) | RD(dst), ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_END | BPF_FROM_BE:
switch (imm) {
case 16:
emit_alu_K(SLL, dst, 16, ctx);
emit_alu_K(SRL, dst, 16, ctx);
break;
case 32:
emit_alu_K(SRL, dst, 0, ctx);
break;
case 64:
break;
}
break;
case BPF_ALU | BPF_END | BPF_FROM_LE: {
const u8 tmp = bpf2sparc[TMP_REG_1];
const u8 tmp2 = bpf2sparc[TMP_REG_2];
ctx->tmp_1_used = true;
switch (imm) {
case 16:
emit_alu3_K(AND, dst, 0xff, tmp, ctx);
emit_alu3_K(SRL, dst, 8, dst, ctx);
emit_alu3_K(AND, dst, 0xff, dst, ctx);
emit_alu3_K(SLL, tmp, 8, tmp, ctx);
emit_alu(OR, tmp, dst, ctx);
break;
case 32:
ctx->tmp_2_used = true;
emit_alu3_K(SRL, dst, 24, tmp, ctx);
emit_alu3_K(SRL, dst, 16, tmp2, ctx);
emit_alu3_K(AND, tmp2, 0xff, tmp2, ctx);
emit_alu3_K(SLL, tmp2, 8, tmp2, ctx);
emit_alu(OR, tmp2, tmp, ctx);
emit_alu3_K(SRL, dst, 8, tmp2, ctx);
emit_alu3_K(AND, tmp2, 0xff, tmp2, ctx);
emit_alu3_K(SLL, tmp2, 16, tmp2, ctx);
emit_alu(OR, tmp2, tmp, ctx);
emit_alu3_K(AND, dst, 0xff, dst, ctx);
emit_alu3_K(SLL, dst, 24, dst, ctx);
emit_alu(OR, tmp, dst, ctx);
break;
case 64:
emit_alu3_K(ADD, SP, STACK_BIAS + 128, tmp, ctx);
emit(ST64 | RS1(tmp) | RS2(G0) | RD(dst), ctx);
emit(LD64A | ASI(ASI_PL) | RS1(tmp) | RS2(G0) | RD(dst), ctx);
break;
}
break;
}
case BPF_ALU | BPF_MOV | BPF_K:
emit_loadimm32(imm, dst, ctx);
break;
case BPF_ALU64 | BPF_MOV | BPF_K:
emit_loadimm_sext(imm, dst, ctx);
break;
case BPF_ALU | BPF_ADD | BPF_K:
case BPF_ALU64 | BPF_ADD | BPF_K:
emit_alu_K(ADD, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_SUB | BPF_K:
case BPF_ALU64 | BPF_SUB | BPF_K:
emit_alu_K(SUB, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_AND | BPF_K:
case BPF_ALU64 | BPF_AND | BPF_K:
emit_alu_K(AND, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_OR | BPF_K:
case BPF_ALU64 | BPF_OR | BPF_K:
emit_alu_K(OR, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_XOR | BPF_K:
case BPF_ALU64 | BPF_XOR | BPF_K:
emit_alu_K(XOR, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU | BPF_MUL | BPF_K:
emit_alu_K(MUL, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU64 | BPF_MUL | BPF_K:
emit_alu_K(MULX, dst, imm, ctx);
break;
case BPF_ALU | BPF_DIV | BPF_K:
if (imm == 0)
return -EINVAL;
emit_write_y(G0, ctx);
emit_alu_K(DIV, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU64 | BPF_DIV | BPF_K:
if (imm == 0)
return -EINVAL;
emit_alu_K(UDIVX, dst, imm, ctx);
break;
case BPF_ALU64 | BPF_MOD | BPF_K:
case BPF_ALU | BPF_MOD | BPF_K: {
const u8 tmp = bpf2sparc[TMP_REG_2];
unsigned int div;
if (imm == 0)
return -EINVAL;
div = (BPF_CLASS(code) == BPF_ALU64) ? UDIVX : DIV;
ctx->tmp_2_used = true;
if (BPF_CLASS(code) != BPF_ALU64)
emit_write_y(G0, ctx);
if (is_simm13(imm)) {
emit(div | IMMED | RS1(dst) | S13(imm) | RD(tmp), ctx);
emit(MULX | IMMED | RS1(tmp) | S13(imm) | RD(tmp), ctx);
emit(SUB | RS1(dst) | RS2(tmp) | RD(dst), ctx);
} else {
const u8 tmp1 = bpf2sparc[TMP_REG_1];
ctx->tmp_1_used = true;
emit_set_const_sext(imm, tmp1, ctx);
emit(div | RS1(dst) | RS2(tmp1) | RD(tmp), ctx);
emit(MULX | RS1(tmp) | RS2(tmp1) | RD(tmp), ctx);
emit(SUB | RS1(dst) | RS2(tmp) | RD(dst), ctx);
}
goto do_alu32_trunc;
}
case BPF_ALU | BPF_LSH | BPF_K:
emit_alu_K(SLL, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU64 | BPF_LSH | BPF_K:
emit_alu_K(SLLX, dst, imm, ctx);
break;
case BPF_ALU | BPF_RSH | BPF_K:
emit_alu_K(SRL, dst, imm, ctx);
break;
case BPF_ALU64 | BPF_RSH | BPF_K:
emit_alu_K(SRLX, dst, imm, ctx);
break;
case BPF_ALU | BPF_ARSH | BPF_K:
emit_alu_K(SRA, dst, imm, ctx);
goto do_alu32_trunc;
case BPF_ALU64 | BPF_ARSH | BPF_K:
emit_alu_K(SRAX, dst, imm, ctx);
break;
do_alu32_trunc:
if (BPF_CLASS(code) == BPF_ALU)
emit_alu_K(SRL, dst, 0, ctx);
break;
case BPF_JMP | BPF_JA:
emit_branch(BA, ctx->idx, ctx->offset[i + off], ctx);
emit_nop(ctx);
break;
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JNE | BPF_X:
case BPF_JMP | BPF_JSGT | BPF_X:
case BPF_JMP | BPF_JSGE | BPF_X:
case BPF_JMP | BPF_JSET | BPF_X: {
int err;
err = emit_compare_and_branch(code, dst, src, 0, false, i + off, ctx);
if (err)
return err;
break;
}
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JNE | BPF_K:
case BPF_JMP | BPF_JSGT | BPF_K:
case BPF_JMP | BPF_JSGE | BPF_K:
case BPF_JMP | BPF_JSET | BPF_K: {
int err;
err = emit_compare_and_branch(code, dst, 0, imm, true, i + off, ctx);
if (err)
return err;
break;
}
case BPF_JMP | BPF_CALL:
{
u8 *func = ((u8 *)__bpf_call_base) + imm;
ctx->saw_call = true;
emit_call((u32 *)func, ctx);
emit_nop(ctx);
emit_reg_move(O0, bpf2sparc[BPF_REG_0], ctx);
if (bpf_helper_changes_pkt_data(func) && ctx->saw_ld_abs_ind)
load_skb_regs(ctx, bpf2sparc[BPF_REG_6]);
break;
}
case BPF_JMP | BPF_TAIL_CALL:
emit_tail_call(ctx);
break;
case BPF_JMP | BPF_EXIT:
if (i == ctx->prog->len - 1)
break;
emit_branch(BA, ctx->idx, ctx->epilogue_offset, ctx);
emit_nop(ctx);
break;
case BPF_LD | BPF_IMM | BPF_DW:
{
const struct bpf_insn insn1 = insn[1];
u64 imm64;
imm64 = (u64)insn1.imm << 32 | (u32)imm;
emit_loadimm64(imm64, dst, ctx);
return 1;
}
case BPF_LDX | BPF_MEM | BPF_W:
case BPF_LDX | BPF_MEM | BPF_H:
case BPF_LDX | BPF_MEM | BPF_B:
case BPF_LDX | BPF_MEM | BPF_DW: {
const u8 tmp = bpf2sparc[TMP_REG_1];
u32 opcode = 0, rs2;
ctx->tmp_1_used = true;
switch (BPF_SIZE(code)) {
case BPF_W:
opcode = LD32;
break;
case BPF_H:
opcode = LD16;
break;
case BPF_B:
opcode = LD8;
break;
case BPF_DW:
opcode = LD64;
break;
}
if (is_simm13(off)) {
opcode |= IMMED;
rs2 = S13(off);
} else {
emit_loadimm(off, tmp, ctx);
rs2 = RS2(tmp);
}
emit(opcode | RS1(src) | rs2 | RD(dst), ctx);
break;
}
case BPF_ST | BPF_MEM | BPF_W:
case BPF_ST | BPF_MEM | BPF_H:
case BPF_ST | BPF_MEM | BPF_B:
case BPF_ST | BPF_MEM | BPF_DW: {
const u8 tmp = bpf2sparc[TMP_REG_1];
const u8 tmp2 = bpf2sparc[TMP_REG_2];
u32 opcode = 0, rs2;
ctx->tmp_2_used = true;
emit_loadimm(imm, tmp2, ctx);
switch (BPF_SIZE(code)) {
case BPF_W:
opcode = ST32;
break;
case BPF_H:
opcode = ST16;
break;
case BPF_B:
opcode = ST8;
break;
case BPF_DW:
opcode = ST64;
break;
}
if (is_simm13(off)) {
opcode |= IMMED;
rs2 = S13(off);
} else {
ctx->tmp_1_used = true;
emit_loadimm(off, tmp, ctx);
rs2 = RS2(tmp);
}
emit(opcode | RS1(dst) | rs2 | RD(tmp2), ctx);
break;
}
case BPF_STX | BPF_MEM | BPF_W:
case BPF_STX | BPF_MEM | BPF_H:
case BPF_STX | BPF_MEM | BPF_B:
case BPF_STX | BPF_MEM | BPF_DW: {
const u8 tmp = bpf2sparc[TMP_REG_1];
u32 opcode = 0, rs2;
switch (BPF_SIZE(code)) {
case BPF_W:
opcode = ST32;
break;
case BPF_H:
opcode = ST16;
break;
case BPF_B:
opcode = ST8;
break;
case BPF_DW:
opcode = ST64;
break;
}
if (is_simm13(off)) {
opcode |= IMMED;
rs2 = S13(off);
} else {
ctx->tmp_1_used = true;
emit_loadimm(off, tmp, ctx);
rs2 = RS2(tmp);
}
emit(opcode | RS1(dst) | rs2 | RD(src), ctx);
break;
}
case BPF_STX | BPF_XADD | BPF_W: {
const u8 tmp = bpf2sparc[TMP_REG_1];
const u8 tmp2 = bpf2sparc[TMP_REG_2];
const u8 tmp3 = bpf2sparc[TMP_REG_3];
ctx->tmp_1_used = true;
ctx->tmp_2_used = true;
ctx->tmp_3_used = true;
emit_loadimm(off, tmp, ctx);
emit_alu3(ADD, dst, tmp, tmp, ctx);
emit(LD32 | RS1(tmp) | RS2(G0) | RD(tmp2), ctx);
emit_alu3(ADD, tmp2, src, tmp3, ctx);
emit(CAS | ASI(ASI_P) | RS1(tmp) | RS2(tmp2) | RD(tmp3), ctx);
emit_cmp(tmp2, tmp3, ctx);
emit_branch(BNE, 4, 0, ctx);
emit_nop(ctx);
break;
}
case BPF_STX | BPF_XADD | BPF_DW: {
const u8 tmp = bpf2sparc[TMP_REG_1];
const u8 tmp2 = bpf2sparc[TMP_REG_2];
const u8 tmp3 = bpf2sparc[TMP_REG_3];
ctx->tmp_1_used = true;
ctx->tmp_2_used = true;
ctx->tmp_3_used = true;
emit_loadimm(off, tmp, ctx);
emit_alu3(ADD, dst, tmp, tmp, ctx);
emit(LD64 | RS1(tmp) | RS2(G0) | RD(tmp2), ctx);
emit_alu3(ADD, tmp2, src, tmp3, ctx);
emit(CASX | ASI(ASI_P) | RS1(tmp) | RS2(tmp2) | RD(tmp3), ctx);
emit_cmp(tmp2, tmp3, ctx);
emit_branch(BNE, 4, 0, ctx);
emit_nop(ctx);
break;
}
#define CHOOSE_LOAD_FUNC(K, func) \
((int)K < 0 ? ((int)K >= SKF_LL_OFF ? func##_negative_offset : func) : func##_positive_offset)
case BPF_LD | BPF_ABS | BPF_W:
func = CHOOSE_LOAD_FUNC(imm, bpf_jit_load_word);
goto common_load;
case BPF_LD | BPF_ABS | BPF_H:
func = CHOOSE_LOAD_FUNC(imm, bpf_jit_load_half);
goto common_load;
case BPF_LD | BPF_ABS | BPF_B:
func = CHOOSE_LOAD_FUNC(imm, bpf_jit_load_byte);
goto common_load;
case BPF_LD | BPF_IND | BPF_W:
func = bpf_jit_load_word;
goto common_load;
case BPF_LD | BPF_IND | BPF_H:
func = bpf_jit_load_half;
goto common_load;
case BPF_LD | BPF_IND | BPF_B:
func = bpf_jit_load_byte;
common_load:
ctx->saw_ld_abs_ind = true;
emit_reg_move(bpf2sparc[BPF_REG_6], O0, ctx);
emit_loadimm(imm, O1, ctx);
if (BPF_MODE(code) == BPF_IND)
emit_alu(ADD, src, O1, ctx);
emit_call(func, ctx);
emit_alu_K(SRA, O1, 0, ctx);
emit_reg_move(O0, bpf2sparc[BPF_REG_0], ctx);
break;
default:
pr_err_once("unknown opcode %02x\n", code);
return -EINVAL;
}
return 0;
}
static int build_body(struct jit_ctx *ctx)
{
const struct bpf_prog *prog = ctx->prog;
int i;
for (i = 0; i < prog->len; i++) {
const struct bpf_insn *insn = &prog->insnsi[i];
int ret;
ret = build_insn(insn, ctx);
if (ret > 0) {
i++;
ctx->offset[i] = ctx->idx;
continue;
}
ctx->offset[i] = ctx->idx;
if (ret)
return ret;
}
return 0;
}
static void jit_fill_hole(void *area, unsigned int size)
{
u32 *ptr;
for (ptr = area; size >= sizeof(u32); size -= sizeof(u32))
*ptr++ = 0x91d02005;
}
struct bpf_prog *bpf_int_jit_compile(struct bpf_prog *prog)
{
struct bpf_prog *tmp, *orig_prog = prog;
struct bpf_binary_header *header;
bool tmp_blinded = false;
struct jit_ctx ctx;
u32 image_size;
u8 *image_ptr;
int pass;
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
ctx.offset = kcalloc(prog->len, sizeof(unsigned int), GFP_KERNEL);
if (ctx.offset == NULL) {
prog = orig_prog;
goto out;
}
if (build_body(&ctx)) {
prog = orig_prog;
goto out_off;
}
build_prologue(&ctx);
build_epilogue(&ctx);
image_size = sizeof(u32) * ctx.idx;
header = bpf_jit_binary_alloc(image_size, &image_ptr,
sizeof(u32), jit_fill_hole);
if (header == NULL) {
prog = orig_prog;
goto out_off;
}
ctx.image = (u32 *)image_ptr;
for (pass = 1; pass < 3; pass++) {
ctx.idx = 0;
build_prologue(&ctx);
if (build_body(&ctx)) {
bpf_jit_binary_free(header);
prog = orig_prog;
goto out_off;
}
build_epilogue(&ctx);
if (bpf_jit_enable > 1)
pr_info("Pass %d: shrink = %d, seen = [%c%c%c%c%c%c%c]\n", pass,
image_size - (ctx.idx * 4),
ctx.tmp_1_used ? '1' : ' ',
ctx.tmp_2_used ? '2' : ' ',
ctx.tmp_3_used ? '3' : ' ',
ctx.saw_ld_abs_ind ? 'L' : ' ',
ctx.saw_frame_pointer ? 'F' : ' ',
ctx.saw_call ? 'C' : ' ',
ctx.saw_tail_call ? 'T' : ' ');
}
if (bpf_jit_enable > 1)
bpf_jit_dump(prog->len, image_size, pass, ctx.image);
bpf_flush_icache(header, (u8 *)header + (header->pages * PAGE_SIZE));
bpf_jit_binary_lock_ro(header);
prog->bpf_func = (void *)ctx.image;
prog->jited = 1;
prog->jited_len = image_size;
out_off:
kfree(ctx.offset);
out:
if (tmp_blinded)
bpf_jit_prog_release_other(prog, prog == orig_prog ?
tmp : orig_prog);
return prog;
}
