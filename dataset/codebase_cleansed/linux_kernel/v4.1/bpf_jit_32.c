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
static u32 jit_udiv(u32 dividend, u32 divisor)
{
return dividend / divisor;
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
static u16 saved_regs(struct jit_ctx *ctx)
{
u16 ret = 0;
if ((ctx->skf->len > 1) ||
(ctx->skf->insns[0].code == (BPF_RET | BPF_A)))
ret |= 1 << r_A;
#ifdef CONFIG_FRAME_POINTER
ret |= (1 << ARM_FP) | (1 << ARM_IP) | (1 << ARM_LR) | (1 << ARM_PC);
#else
if (ctx->seen & SEEN_CALL)
ret |= 1 << ARM_LR;
#endif
if (ctx->seen & (SEEN_DATA | SEEN_SKB))
ret |= 1 << r_skb;
if (ctx->seen & SEEN_DATA)
ret |= (1 << r_skb_data) | (1 << r_skb_hl);
if (ctx->seen & SEEN_X)
ret |= 1 << r_X;
return ret;
}
static inline int mem_words_used(struct jit_ctx *ctx)
{
return fls(ctx->seen & SEEN_MEM);
}
static inline bool is_load_to_a(u16 inst)
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
static void jit_fill_hole(void *area, unsigned int size)
{
u32 *ptr;
for (ptr = area; size >= sizeof(u32); size -= sizeof(u32))
*ptr++ = __opcode_to_mem_arm(ARM_INST_UDF);
}
static void build_prologue(struct jit_ctx *ctx)
{
u16 reg_set = saved_regs(ctx);
u16 first_inst = ctx->skf->insns[0].code;
u16 off;
#ifdef CONFIG_FRAME_POINTER
emit(ARM_MOV_R(ARM_IP, ARM_SP), ctx);
emit(ARM_PUSH(reg_set), ctx);
emit(ARM_SUB_I(ARM_FP, ARM_IP, 4), ctx);
#else
if (reg_set)
emit(ARM_PUSH(reg_set), ctx);
#endif
if (ctx->seen & (SEEN_DATA | SEEN_SKB))
emit(ARM_MOV_R(r_skb, ARM_R0), ctx);
if (ctx->seen & SEEN_DATA) {
off = offsetof(struct sk_buff, data);
emit(ARM_LDR_I(r_skb_data, r_skb, off), ctx);
off = offsetof(struct sk_buff, len);
emit(ARM_LDR_I(r_skb_hl, r_skb, off), ctx);
off = offsetof(struct sk_buff, data_len);
emit(ARM_LDR_I(r_scratch, r_skb, off), ctx);
emit(ARM_SUB_R(r_skb_hl, r_skb_hl, r_scratch), ctx);
}
if (ctx->flags & FLAG_NEED_X_RESET)
emit(ARM_MOV_I(r_X, 0), ctx);
if ((first_inst != (BPF_RET | BPF_K)) && !(is_load_to_a(first_inst)))
emit(ARM_MOV_I(r_A, 0), ctx);
if (ctx->seen & SEEN_MEM)
emit(ARM_SUB_I(ARM_SP, ARM_SP, mem_words_used(ctx) * 4), ctx);
}
static void build_epilogue(struct jit_ctx *ctx)
{
u16 reg_set = saved_regs(ctx);
if (ctx->seen & SEEN_MEM)
emit(ARM_ADD_I(ARM_SP, ARM_SP, mem_words_used(ctx) * 4), ctx);
reg_set &= ~(1 << ARM_LR);
#ifdef CONFIG_FRAME_POINTER
reg_set &= ~(1 << ARM_IP);
reg_set |= (1 << ARM_SP);
emit(ARM_LDM(ARM_SP, reg_set), ctx);
#else
if (reg_set) {
if (ctx->seen & SEEN_CALL)
reg_set |= 1 << ARM_PC;
emit(ARM_POP(reg_set), ctx);
}
if (!(ctx->seen & SEEN_CALL))
emit(ARM_BX(ARM_LR), ctx);
#endif
}
static int16_t imm8m(u32 x)
{
u32 rot;
for (rot = 0; rot < 16; rot++)
if ((x & ~ror32(0xff, 2 * rot)) == 0)
return rol32(x, 2 * rot) | (rot << 8);
return -1;
}
static u16 imm_offset(u32 k, struct jit_ctx *ctx)
{
unsigned i = 0, offset;
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
offset = ctx->offsets[ctx->skf->len];
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
static inline void emit_mov_i_no8m(int rd, u32 val, struct jit_ctx *ctx)
{
#if __LINUX_ARM_ARCH__ < 7
emit(ARM_LDR_I(rd, ARM_PC, imm_offset(val, ctx)), ctx);
#else
emit(ARM_MOVW(rd, val & 0xffff), ctx);
if (val > 0xffff)
emit(ARM_MOVT(rd, val >> 16), ctx);
#endif
}
static inline void emit_mov_i(int rd, u32 val, struct jit_ctx *ctx)
{
int imm12 = imm8m(val);
if (imm12 >= 0)
emit(ARM_MOV_I(rd, imm12), ctx);
else
emit_mov_i_no8m(rd, val, ctx);
}
static void emit_load_be32(u8 cond, u8 r_res, u8 r_addr, struct jit_ctx *ctx)
{
_emit(cond, ARM_LDRB_I(ARM_R3, r_addr, 1), ctx);
_emit(cond, ARM_LDRB_I(ARM_R1, r_addr, 0), ctx);
_emit(cond, ARM_LDRB_I(ARM_R2, r_addr, 3), ctx);
_emit(cond, ARM_LSL_I(ARM_R3, ARM_R3, 16), ctx);
_emit(cond, ARM_LDRB_I(ARM_R0, r_addr, 2), ctx);
_emit(cond, ARM_ORR_S(ARM_R3, ARM_R3, ARM_R1, SRTYPE_LSL, 24), ctx);
_emit(cond, ARM_ORR_R(ARM_R3, ARM_R3, ARM_R2), ctx);
_emit(cond, ARM_ORR_S(r_res, ARM_R3, ARM_R0, SRTYPE_LSL, 8), ctx);
}
static void emit_load_be16(u8 cond, u8 r_res, u8 r_addr, struct jit_ctx *ctx)
{
_emit(cond, ARM_LDRB_I(ARM_R1, r_addr, 0), ctx);
_emit(cond, ARM_LDRB_I(ARM_R2, r_addr, 1), ctx);
_emit(cond, ARM_ORR_S(r_res, ARM_R2, ARM_R1, SRTYPE_LSL, 8), ctx);
}
static inline void emit_swap16(u8 r_dst, u8 r_src, struct jit_ctx *ctx)
{
emit(ARM_LSL_I(ARM_R1, r_src, 8), ctx);
emit(ARM_ORR_S(r_dst, ARM_R1, r_src, SRTYPE_LSR, 8), ctx);
emit(ARM_BIC_I(r_dst, r_dst, 0x8ff), ctx);
}
static void emit_load_be32(u8 cond, u8 r_res, u8 r_addr, struct jit_ctx *ctx)
{
_emit(cond, ARM_LDR_I(r_res, r_addr, 0), ctx);
#ifdef __LITTLE_ENDIAN
_emit(cond, ARM_REV(r_res, r_res), ctx);
#endif
}
static void emit_load_be16(u8 cond, u8 r_res, u8 r_addr, struct jit_ctx *ctx)
{
_emit(cond, ARM_LDRH_I(r_res, r_addr, 0), ctx);
#ifdef __LITTLE_ENDIAN
_emit(cond, ARM_REV16(r_res, r_res), ctx);
#endif
}
static inline void emit_swap16(u8 r_dst __maybe_unused,
u8 r_src __maybe_unused,
struct jit_ctx *ctx __maybe_unused)
{
#ifdef __LITTLE_ENDIAN
emit(ARM_REV16(r_dst, r_src), ctx);
#endif
}
static inline u32 b_imm(unsigned tgt, struct jit_ctx *ctx)
{
u32 imm;
if (ctx->target == NULL)
return 0;
imm = ctx->offsets[tgt] + ctx->prologue_bytes - (ctx->idx * 4 + 8);
return imm >> 2;
}
static inline void emit_err_ret(u8 cond, struct jit_ctx *ctx)
{
if (ctx->ret0_fp_idx >= 0) {
_emit(cond, ARM_B(b_imm(ctx->ret0_fp_idx, ctx)), ctx);
emit(ARM_MOV_R(ARM_R0, ARM_R0), ctx);
} else {
_emit(cond, ARM_MOV_I(ARM_R0, 0), ctx);
_emit(cond, ARM_B(b_imm(ctx->skf->len, ctx)), ctx);
}
}
static inline void emit_blx_r(u8 tgt_reg, struct jit_ctx *ctx)
{
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
static inline void emit_udiv(u8 rd, u8 rm, u8 rn, struct jit_ctx *ctx)
{
#if __LINUX_ARM_ARCH__ == 7
if (elf_hwcap & HWCAP_IDIVA) {
emit(ARM_UDIV(rd, rm, rn), ctx);
return;
}
#endif
if (rn != ARM_R1)
emit(ARM_MOV_R(ARM_R1, rn), ctx);
if (rm != ARM_R0)
emit(ARM_MOV_R(ARM_R0, rm), ctx);
ctx->seen |= SEEN_CALL;
emit_mov_i(ARM_R3, (u32)jit_udiv, ctx);
emit_blx_r(ARM_R3, ctx);
if (rd != ARM_R0)
emit(ARM_MOV_R(rd, ARM_R0), ctx);
}
static inline void update_on_xread(struct jit_ctx *ctx)
{
if (!(ctx->seen & SEEN_X))
ctx->flags |= FLAG_NEED_X_RESET;
ctx->seen |= SEEN_X;
}
static int build_body(struct jit_ctx *ctx)
{
void *load_func[] = {jit_get_skb_b, jit_get_skb_h, jit_get_skb_w};
const struct bpf_prog *prog = ctx->skf;
const struct sock_filter *inst;
unsigned i, load_order, off, condt;
int imm12;
u32 k;
for (i = 0; i < prog->len; i++) {
u16 code;
inst = &(prog->insns[i]);
k = inst->k;
code = bpf_anc_helper(inst);
if (ctx->target == NULL)
ctx->offsets[i] = ctx->idx * 4;
switch (code) {
case BPF_LD | BPF_IMM:
emit_mov_i(r_A, k, ctx);
break;
case BPF_LD | BPF_W | BPF_LEN:
ctx->seen |= SEEN_SKB;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, len) != 4);
emit(ARM_LDR_I(r_A, r_skb,
offsetof(struct sk_buff, len)), ctx);
break;
case BPF_LD | BPF_MEM:
ctx->seen |= SEEN_MEM_WORD(k);
emit(ARM_LDR_I(r_A, ARM_SP, SCRATCH_OFF(k)), ctx);
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
emit_mov_i(r_off, k, ctx);
load_common:
ctx->seen |= SEEN_DATA | SEEN_CALL;
if (load_order > 0) {
emit(ARM_SUB_I(r_scratch, r_skb_hl,
1 << load_order), ctx);
emit(ARM_CMP_R(r_scratch, r_off), ctx);
condt = ARM_COND_HS;
} else {
emit(ARM_CMP_R(r_skb_hl, r_off), ctx);
condt = ARM_COND_HI;
}
_emit(condt, ARM_ADD_R(r_scratch, r_off, r_skb_data),
ctx);
if (load_order == 0)
_emit(condt, ARM_LDRB_I(r_A, r_scratch, 0),
ctx);
else if (load_order == 1)
emit_load_be16(condt, r_A, r_scratch, ctx);
else if (load_order == 2)
emit_load_be32(condt, r_A, r_scratch, ctx);
_emit(condt, ARM_B(b_imm(i + 1, ctx)), ctx);
emit_mov_i(ARM_R3, (u32)load_func[load_order], ctx);
emit(ARM_MOV_R(ARM_R0, r_skb), ctx);
emit_blx_r(ARM_R3, ctx);
emit(ARM_CMP_I(ARM_R1, 0), ctx);
emit_err_ret(ARM_COND_NE, ctx);
emit(ARM_MOV_R(r_A, ARM_R0), ctx);
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
OP_IMM3(ARM_ADD, r_off, r_X, k, ctx);
goto load_common;
case BPF_LDX | BPF_IMM:
ctx->seen |= SEEN_X;
emit_mov_i(r_X, k, ctx);
break;
case BPF_LDX | BPF_W | BPF_LEN:
ctx->seen |= SEEN_X | SEEN_SKB;
emit(ARM_LDR_I(r_X, r_skb,
offsetof(struct sk_buff, len)), ctx);
break;
case BPF_LDX | BPF_MEM:
ctx->seen |= SEEN_X | SEEN_MEM_WORD(k);
emit(ARM_LDR_I(r_X, ARM_SP, SCRATCH_OFF(k)), ctx);
break;
case BPF_LDX | BPF_B | BPF_MSH:
ctx->seen |= SEEN_X | SEEN_DATA | SEEN_CALL;
if ((int)k < 0)
return -1;
emit_mov_i(r_off, k, ctx);
emit(ARM_CMP_R(r_skb_hl, r_off), ctx);
_emit(ARM_COND_HI, ARM_LDRB_R(ARM_R0, r_skb_data,
ARM_R1), ctx);
_emit(ARM_COND_HI, ARM_B(b_imm(i + 1, ctx) - 2), ctx);
emit(ARM_MOV_R(ARM_R0, r_skb), ctx);
emit_mov_i(ARM_R3, (u32)jit_get_skb_b, ctx);
emit_blx_r(ARM_R3, ctx);
emit(ARM_CMP_I(ARM_R1, 0), ctx);
emit_err_ret(ARM_COND_NE, ctx);
emit(ARM_AND_I(r_X, ARM_R0, 0x00f), ctx);
emit(ARM_LSL_I(r_X, r_X, 2), ctx);
break;
case BPF_ST:
ctx->seen |= SEEN_MEM_WORD(k);
emit(ARM_STR_I(r_A, ARM_SP, SCRATCH_OFF(k)), ctx);
break;
case BPF_STX:
update_on_xread(ctx);
ctx->seen |= SEEN_MEM_WORD(k);
emit(ARM_STR_I(r_X, ARM_SP, SCRATCH_OFF(k)), ctx);
break;
case BPF_ALU | BPF_ADD | BPF_K:
OP_IMM3(ARM_ADD, r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_ADD | BPF_X:
update_on_xread(ctx);
emit(ARM_ADD_R(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_SUB | BPF_K:
OP_IMM3(ARM_SUB, r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_SUB | BPF_X:
update_on_xread(ctx);
emit(ARM_SUB_R(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_MUL | BPF_K:
emit_mov_i(r_scratch, k, ctx);
emit(ARM_MUL(r_A, r_A, r_scratch), ctx);
break;
case BPF_ALU | BPF_MUL | BPF_X:
update_on_xread(ctx);
emit(ARM_MUL(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_DIV | BPF_K:
if (k == 1)
break;
emit_mov_i(r_scratch, k, ctx);
emit_udiv(r_A, r_A, r_scratch, ctx);
break;
case BPF_ALU | BPF_DIV | BPF_X:
update_on_xread(ctx);
emit(ARM_CMP_I(r_X, 0), ctx);
emit_err_ret(ARM_COND_EQ, ctx);
emit_udiv(r_A, r_A, r_X, ctx);
break;
case BPF_ALU | BPF_OR | BPF_K:
OP_IMM3(ARM_ORR, r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_OR | BPF_X:
update_on_xread(ctx);
emit(ARM_ORR_R(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_XOR | BPF_K:
OP_IMM3(ARM_EOR, r_A, r_A, k, ctx);
break;
case BPF_ANC | SKF_AD_ALU_XOR_X:
case BPF_ALU | BPF_XOR | BPF_X:
update_on_xread(ctx);
emit(ARM_EOR_R(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_AND | BPF_K:
OP_IMM3(ARM_AND, r_A, r_A, k, ctx);
break;
case BPF_ALU | BPF_AND | BPF_X:
update_on_xread(ctx);
emit(ARM_AND_R(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_LSH | BPF_K:
if (unlikely(k > 31))
return -1;
emit(ARM_LSL_I(r_A, r_A, k), ctx);
break;
case BPF_ALU | BPF_LSH | BPF_X:
update_on_xread(ctx);
emit(ARM_LSL_R(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_RSH | BPF_K:
if (unlikely(k > 31))
return -1;
emit(ARM_LSR_I(r_A, r_A, k), ctx);
break;
case BPF_ALU | BPF_RSH | BPF_X:
update_on_xread(ctx);
emit(ARM_LSR_R(r_A, r_A, r_X), ctx);
break;
case BPF_ALU | BPF_NEG:
emit(ARM_RSB_I(r_A, r_A, 0), ctx);
break;
case BPF_JMP | BPF_JA:
emit(ARM_B(b_imm(i + k + 1, ctx)), ctx);
break;
case BPF_JMP | BPF_JEQ | BPF_K:
condt = ARM_COND_EQ;
goto cmp_imm;
case BPF_JMP | BPF_JGT | BPF_K:
condt = ARM_COND_HI;
goto cmp_imm;
case BPF_JMP | BPF_JGE | BPF_K:
condt = ARM_COND_HS;
cmp_imm:
imm12 = imm8m(k);
if (imm12 < 0) {
emit_mov_i_no8m(r_scratch, k, ctx);
emit(ARM_CMP_R(r_A, r_scratch), ctx);
} else {
emit(ARM_CMP_I(r_A, imm12), ctx);
}
cond_jump:
if (inst->jt)
_emit(condt, ARM_B(b_imm(i + inst->jt + 1,
ctx)), ctx);
if (inst->jf)
_emit(condt ^ 1, ARM_B(b_imm(i + inst->jf + 1,
ctx)), ctx);
break;
case BPF_JMP | BPF_JEQ | BPF_X:
condt = ARM_COND_EQ;
goto cmp_x;
case BPF_JMP | BPF_JGT | BPF_X:
condt = ARM_COND_HI;
goto cmp_x;
case BPF_JMP | BPF_JGE | BPF_X:
condt = ARM_COND_CS;
cmp_x:
update_on_xread(ctx);
emit(ARM_CMP_R(r_A, r_X), ctx);
goto cond_jump;
case BPF_JMP | BPF_JSET | BPF_K:
condt = ARM_COND_NE;
imm12 = imm8m(k);
if (imm12 < 0) {
emit_mov_i_no8m(r_scratch, k, ctx);
emit(ARM_TST_R(r_A, r_scratch), ctx);
} else {
emit(ARM_TST_I(r_A, imm12), ctx);
}
goto cond_jump;
case BPF_JMP | BPF_JSET | BPF_X:
update_on_xread(ctx);
condt = ARM_COND_NE;
emit(ARM_TST_R(r_A, r_X), ctx);
goto cond_jump;
case BPF_RET | BPF_A:
emit(ARM_MOV_R(ARM_R0, r_A), ctx);
goto b_epilogue;
case BPF_RET | BPF_K:
if ((k == 0) && (ctx->ret0_fp_idx < 0))
ctx->ret0_fp_idx = i;
emit_mov_i(ARM_R0, k, ctx);
b_epilogue:
if (i != ctx->skf->len - 1)
emit(ARM_B(b_imm(prog->len, ctx)), ctx);
break;
case BPF_MISC | BPF_TAX:
ctx->seen |= SEEN_X;
emit(ARM_MOV_R(r_X, r_A), ctx);
break;
case BPF_MISC | BPF_TXA:
update_on_xread(ctx);
emit(ARM_MOV_R(r_A, r_X), ctx);
break;
case BPF_ANC | SKF_AD_PROTOCOL:
ctx->seen |= SEEN_SKB;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff,
protocol) != 2);
off = offsetof(struct sk_buff, protocol);
emit(ARM_LDRH_I(r_scratch, r_skb, off), ctx);
emit_swap16(r_A, r_scratch, ctx);
break;
case BPF_ANC | SKF_AD_CPU:
OP_IMM3(ARM_BIC, r_scratch, ARM_SP, THREAD_SIZE - 1, ctx);
BUILD_BUG_ON(FIELD_SIZEOF(struct thread_info, cpu) != 4);
off = offsetof(struct thread_info, cpu);
emit(ARM_LDR_I(r_A, r_scratch, off), ctx);
break;
case BPF_ANC | SKF_AD_IFINDEX:
ctx->seen |= SEEN_SKB;
off = offsetof(struct sk_buff, dev);
emit(ARM_LDR_I(r_scratch, r_skb, off), ctx);
emit(ARM_CMP_I(r_scratch, 0), ctx);
emit_err_ret(ARM_COND_EQ, ctx);
BUILD_BUG_ON(FIELD_SIZEOF(struct net_device,
ifindex) != 4);
off = offsetof(struct net_device, ifindex);
emit(ARM_LDR_I(r_A, r_scratch, off), ctx);
break;
case BPF_ANC | SKF_AD_MARK:
ctx->seen |= SEEN_SKB;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, mark) != 4);
off = offsetof(struct sk_buff, mark);
emit(ARM_LDR_I(r_A, r_skb, off), ctx);
break;
case BPF_ANC | SKF_AD_RXHASH:
ctx->seen |= SEEN_SKB;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, hash) != 4);
off = offsetof(struct sk_buff, hash);
emit(ARM_LDR_I(r_A, r_skb, off), ctx);
break;
case BPF_ANC | SKF_AD_VLAN_TAG:
case BPF_ANC | SKF_AD_VLAN_TAG_PRESENT:
ctx->seen |= SEEN_SKB;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, vlan_tci) != 2);
off = offsetof(struct sk_buff, vlan_tci);
emit(ARM_LDRH_I(r_A, r_skb, off), ctx);
if (code == (BPF_ANC | SKF_AD_VLAN_TAG))
OP_IMM3(ARM_AND, r_A, r_A, VLAN_VID_MASK, ctx);
else
OP_IMM3(ARM_AND, r_A, r_A, VLAN_TAG_PRESENT, ctx);
break;
case BPF_ANC | SKF_AD_QUEUE:
ctx->seen |= SEEN_SKB;
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff,
queue_mapping) != 2);
BUILD_BUG_ON(offsetof(struct sk_buff,
queue_mapping) > 0xff);
off = offsetof(struct sk_buff, queue_mapping);
emit(ARM_LDRH_I(r_A, r_skb, off), ctx);
break;
default:
return -1;
}
if (ctx->flags & FLAG_IMM_OVERFLOW)
return -1;
}
if (ctx->target == NULL)
ctx->offsets[i] = ctx->idx * 4;
return 0;
}
void bpf_jit_compile(struct bpf_prog *fp)
{
struct bpf_binary_header *header;
struct jit_ctx ctx;
unsigned tmp_idx;
unsigned alloc_size;
u8 *target_ptr;
if (!bpf_jit_enable)
return;
memset(&ctx, 0, sizeof(ctx));
ctx.skf = fp;
ctx.ret0_fp_idx = -1;
ctx.offsets = kzalloc(4 * (ctx.skf->len + 1), GFP_KERNEL);
if (ctx.offsets == NULL)
return;
if (unlikely(build_body(&ctx)))
goto out;
tmp_idx = ctx.idx;
build_prologue(&ctx);
ctx.prologue_bytes = (ctx.idx - tmp_idx) * 4;
#if __LINUX_ARM_ARCH__ < 7
tmp_idx = ctx.idx;
build_epilogue(&ctx);
ctx.epilogue_bytes = (ctx.idx - tmp_idx) * 4;
ctx.idx += ctx.imm_count;
if (ctx.imm_count) {
ctx.imms = kzalloc(4 * ctx.imm_count, GFP_KERNEL);
if (ctx.imms == NULL)
goto out;
}
#else
build_epilogue(&ctx);
#endif
alloc_size = 4 * ctx.idx;
header = bpf_jit_binary_alloc(alloc_size, &target_ptr,
4, jit_fill_hole);
if (header == NULL)
goto out;
ctx.target = (u32 *) target_ptr;
ctx.idx = 0;
build_prologue(&ctx);
if (build_body(&ctx) < 0) {
#if __LINUX_ARM_ARCH__ < 7
if (ctx.imm_count)
kfree(ctx.imms);
#endif
bpf_jit_binary_free(header);
goto out;
}
build_epilogue(&ctx);
flush_icache_range((u32)ctx.target, (u32)(ctx.target + ctx.idx));
#if __LINUX_ARM_ARCH__ < 7
if (ctx.imm_count)
kfree(ctx.imms);
#endif
if (bpf_jit_enable > 1)
bpf_jit_dump(fp->len, alloc_size, 2, ctx.target);
set_memory_ro((unsigned long)header, header->pages);
fp->bpf_func = (void *)ctx.target;
fp->jited = true;
out:
kfree(ctx.offsets);
return;
}
void bpf_jit_free(struct bpf_prog *fp)
{
unsigned long addr = (unsigned long)fp->bpf_func & PAGE_MASK;
struct bpf_binary_header *header = (void *)addr;
if (!fp->jited)
goto free_filter;
set_memory_rw(addr, header->pages);
bpf_jit_binary_free(header);
free_filter:
bpf_prog_unlock_free(fp);
}
