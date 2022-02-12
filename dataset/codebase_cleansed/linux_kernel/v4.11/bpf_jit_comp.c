static u8 *emit_code(u8 *ptr, u32 bytes, unsigned int len)
{
if (len == 1)
*ptr = bytes;
else if (len == 2)
*(u16 *)ptr = bytes;
else {
*(u32 *)ptr = bytes;
barrier();
}
return ptr + len;
}
static bool is_imm8(int value)
{
return value <= 127 && value >= -128;
}
static bool is_simm32(s64 value)
{
return value == (s64) (s32) value;
}
static int bpf_size_to_x86_bytes(int bpf_size)
{
if (bpf_size == BPF_W)
return 4;
else if (bpf_size == BPF_H)
return 2;
else if (bpf_size == BPF_B)
return 1;
else if (bpf_size == BPF_DW)
return 4;
else
return 0;
}
static void bpf_flush_icache(void *start, void *end)
{
mm_segment_t old_fs = get_fs();
set_fs(KERNEL_DS);
smp_wmb();
flush_icache_range((unsigned long)start, (unsigned long)end);
set_fs(old_fs);
}
static bool is_ereg(u32 reg)
{
return (1 << reg) & (BIT(BPF_REG_5) |
BIT(AUX_REG) |
BIT(BPF_REG_7) |
BIT(BPF_REG_8) |
BIT(BPF_REG_9) |
BIT(BPF_REG_AX));
}
static u8 add_1mod(u8 byte, u32 reg)
{
if (is_ereg(reg))
byte |= 1;
return byte;
}
static u8 add_2mod(u8 byte, u32 r1, u32 r2)
{
if (is_ereg(r1))
byte |= 1;
if (is_ereg(r2))
byte |= 4;
return byte;
}
static u8 add_1reg(u8 byte, u32 dst_reg)
{
return byte + reg2hex[dst_reg];
}
static u8 add_2reg(u8 byte, u32 dst_reg, u32 src_reg)
{
return byte + reg2hex[dst_reg] + (reg2hex[src_reg] << 3);
}
static void jit_fill_hole(void *area, unsigned int size)
{
memset(area, 0xcc, size);
}
static void emit_prologue(u8 **pprog)
{
u8 *prog = *pprog;
int cnt = 0;
EMIT1(0x55);
EMIT3(0x48, 0x89, 0xE5);
EMIT3_off32(0x48, 0x81, 0xEC, STACKSIZE);
EMIT3_off32(0x48, 0x89, 0x9D, -STACKSIZE);
EMIT3_off32(0x4C, 0x89, 0xAD, -STACKSIZE + 8);
EMIT3_off32(0x4C, 0x89, 0xB5, -STACKSIZE + 16);
EMIT3_off32(0x4C, 0x89, 0xBD, -STACKSIZE + 24);
EMIT2(0x31, 0xc0);
EMIT3_off32(0x48, 0x89, 0x85, -STACKSIZE + 32);
BUILD_BUG_ON(cnt != PROLOGUE_SIZE);
*pprog = prog;
}
static void emit_bpf_tail_call(u8 **pprog)
{
u8 *prog = *pprog;
int label1, label2, label3;
int cnt = 0;
EMIT4(0x48, 0x8B, 0x46,
offsetof(struct bpf_array, map.max_entries));
EMIT3(0x48, 0x39, 0xD0);
#define OFFSET1 47
EMIT2(X86_JBE, OFFSET1);
label1 = cnt;
EMIT2_off32(0x8B, 0x85, -STACKSIZE + 36);
EMIT3(0x83, 0xF8, MAX_TAIL_CALL_CNT);
#define OFFSET2 36
EMIT2(X86_JA, OFFSET2);
label2 = cnt;
EMIT3(0x83, 0xC0, 0x01);
EMIT2_off32(0x89, 0x85, -STACKSIZE + 36);
EMIT4_off32(0x48, 0x8D, 0x84, 0xD6,
offsetof(struct bpf_array, ptrs));
EMIT3(0x48, 0x8B, 0x00);
EMIT4(0x48, 0x83, 0xF8, 0x00);
#define OFFSET3 10
EMIT2(X86_JE, OFFSET3);
label3 = cnt;
EMIT4(0x48, 0x8B, 0x40,
offsetof(struct bpf_prog, bpf_func));
EMIT4(0x48, 0x83, 0xC0, PROLOGUE_SIZE);
EMIT2(0xFF, 0xE0);
BUILD_BUG_ON(cnt - label1 != OFFSET1);
BUILD_BUG_ON(cnt - label2 != OFFSET2);
BUILD_BUG_ON(cnt - label3 != OFFSET3);
*pprog = prog;
}
static void emit_load_skb_data_hlen(u8 **pprog)
{
u8 *prog = *pprog;
int cnt = 0;
EMIT3_off32(0x44, 0x8b, 0x8f, offsetof(struct sk_buff, len));
EMIT3_off32(0x44, 0x2b, 0x8f, offsetof(struct sk_buff, data_len));
EMIT3_off32(0x4c, 0x8b, 0x97, offsetof(struct sk_buff, data));
*pprog = prog;
}
static int do_jit(struct bpf_prog *bpf_prog, int *addrs, u8 *image,
int oldproglen, struct jit_context *ctx)
{
struct bpf_insn *insn = bpf_prog->insnsi;
int insn_cnt = bpf_prog->len;
bool seen_ld_abs = ctx->seen_ld_abs | (oldproglen == 0);
bool seen_ax_reg = ctx->seen_ax_reg | (oldproglen == 0);
bool seen_exit = false;
u8 temp[BPF_MAX_INSN_SIZE + BPF_INSN_SAFETY];
int i, cnt = 0;
int proglen = 0;
u8 *prog = temp;
emit_prologue(&prog);
if (seen_ld_abs)
emit_load_skb_data_hlen(&prog);
for (i = 0; i < insn_cnt; i++, insn++) {
const s32 imm32 = insn->imm;
u32 dst_reg = insn->dst_reg;
u32 src_reg = insn->src_reg;
u8 b1 = 0, b2 = 0, b3 = 0;
s64 jmp_offset;
u8 jmp_cond;
bool reload_skb_data;
int ilen;
u8 *func;
if (dst_reg == BPF_REG_AX || src_reg == BPF_REG_AX)
ctx->seen_ax_reg = seen_ax_reg = true;
switch (insn->code) {
case BPF_ALU | BPF_ADD | BPF_X:
case BPF_ALU | BPF_SUB | BPF_X:
case BPF_ALU | BPF_AND | BPF_X:
case BPF_ALU | BPF_OR | BPF_X:
case BPF_ALU | BPF_XOR | BPF_X:
case BPF_ALU64 | BPF_ADD | BPF_X:
case BPF_ALU64 | BPF_SUB | BPF_X:
case BPF_ALU64 | BPF_AND | BPF_X:
case BPF_ALU64 | BPF_OR | BPF_X:
case BPF_ALU64 | BPF_XOR | BPF_X:
switch (BPF_OP(insn->code)) {
case BPF_ADD: b2 = 0x01; break;
case BPF_SUB: b2 = 0x29; break;
case BPF_AND: b2 = 0x21; break;
case BPF_OR: b2 = 0x09; break;
case BPF_XOR: b2 = 0x31; break;
}
if (BPF_CLASS(insn->code) == BPF_ALU64)
EMIT1(add_2mod(0x48, dst_reg, src_reg));
else if (is_ereg(dst_reg) || is_ereg(src_reg))
EMIT1(add_2mod(0x40, dst_reg, src_reg));
EMIT2(b2, add_2reg(0xC0, dst_reg, src_reg));
break;
case BPF_ALU64 | BPF_MOV | BPF_X:
EMIT_mov(dst_reg, src_reg);
break;
case BPF_ALU | BPF_MOV | BPF_X:
if (is_ereg(dst_reg) || is_ereg(src_reg))
EMIT1(add_2mod(0x40, dst_reg, src_reg));
EMIT2(0x89, add_2reg(0xC0, dst_reg, src_reg));
break;
case BPF_ALU | BPF_NEG:
case BPF_ALU64 | BPF_NEG:
if (BPF_CLASS(insn->code) == BPF_ALU64)
EMIT1(add_1mod(0x48, dst_reg));
else if (is_ereg(dst_reg))
EMIT1(add_1mod(0x40, dst_reg));
EMIT2(0xF7, add_1reg(0xD8, dst_reg));
break;
case BPF_ALU | BPF_ADD | BPF_K:
case BPF_ALU | BPF_SUB | BPF_K:
case BPF_ALU | BPF_AND | BPF_K:
case BPF_ALU | BPF_OR | BPF_K:
case BPF_ALU | BPF_XOR | BPF_K:
case BPF_ALU64 | BPF_ADD | BPF_K:
case BPF_ALU64 | BPF_SUB | BPF_K:
case BPF_ALU64 | BPF_AND | BPF_K:
case BPF_ALU64 | BPF_OR | BPF_K:
case BPF_ALU64 | BPF_XOR | BPF_K:
if (BPF_CLASS(insn->code) == BPF_ALU64)
EMIT1(add_1mod(0x48, dst_reg));
else if (is_ereg(dst_reg))
EMIT1(add_1mod(0x40, dst_reg));
switch (BPF_OP(insn->code)) {
case BPF_ADD: b3 = 0xC0; break;
case BPF_SUB: b3 = 0xE8; break;
case BPF_AND: b3 = 0xE0; break;
case BPF_OR: b3 = 0xC8; break;
case BPF_XOR: b3 = 0xF0; break;
}
if (is_imm8(imm32))
EMIT3(0x83, add_1reg(b3, dst_reg), imm32);
else
EMIT2_off32(0x81, add_1reg(b3, dst_reg), imm32);
break;
case BPF_ALU64 | BPF_MOV | BPF_K:
if (imm32 < 0) {
b1 = add_1mod(0x48, dst_reg);
b2 = 0xC7;
b3 = 0xC0;
EMIT3_off32(b1, b2, add_1reg(b3, dst_reg), imm32);
break;
}
case BPF_ALU | BPF_MOV | BPF_K:
if (imm32 == 0) {
if (is_ereg(dst_reg))
EMIT1(add_2mod(0x40, dst_reg, dst_reg));
b2 = 0x31;
b3 = 0xC0;
EMIT2(b2, add_2reg(b3, dst_reg, dst_reg));
break;
}
if (is_ereg(dst_reg))
EMIT1(add_1mod(0x40, dst_reg));
EMIT1_off32(add_1reg(0xB8, dst_reg), imm32);
break;
case BPF_LD | BPF_IMM | BPF_DW:
if (insn[1].code != 0 || insn[1].src_reg != 0 ||
insn[1].dst_reg != 0 || insn[1].off != 0) {
pr_err("invalid BPF_LD_IMM64 insn\n");
return -EINVAL;
}
if (insn[0].imm == 0 && insn[1].imm == 0) {
b1 = add_2mod(0x48, dst_reg, dst_reg);
b2 = 0x31;
b3 = 0xC0;
EMIT3(b1, b2, add_2reg(b3, dst_reg, dst_reg));
insn++;
i++;
break;
}
EMIT2(add_1mod(0x48, dst_reg), add_1reg(0xB8, dst_reg));
EMIT(insn[0].imm, 4);
EMIT(insn[1].imm, 4);
insn++;
i++;
break;
case BPF_ALU | BPF_MOD | BPF_X:
case BPF_ALU | BPF_DIV | BPF_X:
case BPF_ALU | BPF_MOD | BPF_K:
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU64 | BPF_MOD | BPF_X:
case BPF_ALU64 | BPF_DIV | BPF_X:
case BPF_ALU64 | BPF_MOD | BPF_K:
case BPF_ALU64 | BPF_DIV | BPF_K:
EMIT1(0x50);
EMIT1(0x52);
if (BPF_SRC(insn->code) == BPF_X)
EMIT_mov(AUX_REG, src_reg);
else
EMIT3_off32(0x49, 0xC7, 0xC3, imm32);
EMIT_mov(BPF_REG_0, dst_reg);
EMIT2(0x31, 0xd2);
if (BPF_SRC(insn->code) == BPF_X) {
EMIT4(0x49, 0x83, 0xFB, 0x00);
EMIT2(X86_JNE, 1 + 1 + 2 + 5);
EMIT1(0x5A);
EMIT1(0x58);
EMIT2(0x31, 0xc0);
jmp_offset = ctx->cleanup_addr - (addrs[i] - 11);
EMIT1_off32(0xE9, jmp_offset);
}
if (BPF_CLASS(insn->code) == BPF_ALU64)
EMIT3(0x49, 0xF7, 0xF3);
else
EMIT3(0x41, 0xF7, 0xF3);
if (BPF_OP(insn->code) == BPF_MOD)
EMIT3(0x49, 0x89, 0xD3);
else
EMIT3(0x49, 0x89, 0xC3);
EMIT1(0x5A);
EMIT1(0x58);
EMIT_mov(dst_reg, AUX_REG);
break;
case BPF_ALU | BPF_MUL | BPF_K:
case BPF_ALU | BPF_MUL | BPF_X:
case BPF_ALU64 | BPF_MUL | BPF_K:
case BPF_ALU64 | BPF_MUL | BPF_X:
EMIT1(0x50);
EMIT1(0x52);
EMIT_mov(AUX_REG, dst_reg);
if (BPF_SRC(insn->code) == BPF_X)
EMIT_mov(BPF_REG_0, src_reg);
else
EMIT3_off32(0x48, 0xC7, 0xC0, imm32);
if (BPF_CLASS(insn->code) == BPF_ALU64)
EMIT1(add_1mod(0x48, AUX_REG));
else if (is_ereg(AUX_REG))
EMIT1(add_1mod(0x40, AUX_REG));
EMIT2(0xF7, add_1reg(0xE0, AUX_REG));
EMIT_mov(AUX_REG, BPF_REG_0);
EMIT1(0x5A);
EMIT1(0x58);
EMIT_mov(dst_reg, AUX_REG);
break;
case BPF_ALU | BPF_LSH | BPF_K:
case BPF_ALU | BPF_RSH | BPF_K:
case BPF_ALU | BPF_ARSH | BPF_K:
case BPF_ALU64 | BPF_LSH | BPF_K:
case BPF_ALU64 | BPF_RSH | BPF_K:
case BPF_ALU64 | BPF_ARSH | BPF_K:
if (BPF_CLASS(insn->code) == BPF_ALU64)
EMIT1(add_1mod(0x48, dst_reg));
else if (is_ereg(dst_reg))
EMIT1(add_1mod(0x40, dst_reg));
switch (BPF_OP(insn->code)) {
case BPF_LSH: b3 = 0xE0; break;
case BPF_RSH: b3 = 0xE8; break;
case BPF_ARSH: b3 = 0xF8; break;
}
EMIT3(0xC1, add_1reg(b3, dst_reg), imm32);
break;
case BPF_ALU | BPF_LSH | BPF_X:
case BPF_ALU | BPF_RSH | BPF_X:
case BPF_ALU | BPF_ARSH | BPF_X:
case BPF_ALU64 | BPF_LSH | BPF_X:
case BPF_ALU64 | BPF_RSH | BPF_X:
case BPF_ALU64 | BPF_ARSH | BPF_X:
if (dst_reg == BPF_REG_4) {
EMIT_mov(AUX_REG, dst_reg);
dst_reg = AUX_REG;
}
if (src_reg != BPF_REG_4) {
EMIT1(0x51);
EMIT_mov(BPF_REG_4, src_reg);
}
if (BPF_CLASS(insn->code) == BPF_ALU64)
EMIT1(add_1mod(0x48, dst_reg));
else if (is_ereg(dst_reg))
EMIT1(add_1mod(0x40, dst_reg));
switch (BPF_OP(insn->code)) {
case BPF_LSH: b3 = 0xE0; break;
case BPF_RSH: b3 = 0xE8; break;
case BPF_ARSH: b3 = 0xF8; break;
}
EMIT2(0xD3, add_1reg(b3, dst_reg));
if (src_reg != BPF_REG_4)
EMIT1(0x59);
if (insn->dst_reg == BPF_REG_4)
EMIT_mov(insn->dst_reg, AUX_REG);
break;
case BPF_ALU | BPF_END | BPF_FROM_BE:
switch (imm32) {
case 16:
EMIT1(0x66);
if (is_ereg(dst_reg))
EMIT1(0x41);
EMIT3(0xC1, add_1reg(0xC8, dst_reg), 8);
if (is_ereg(dst_reg))
EMIT3(0x45, 0x0F, 0xB7);
else
EMIT2(0x0F, 0xB7);
EMIT1(add_2reg(0xC0, dst_reg, dst_reg));
break;
case 32:
if (is_ereg(dst_reg))
EMIT2(0x41, 0x0F);
else
EMIT1(0x0F);
EMIT1(add_1reg(0xC8, dst_reg));
break;
case 64:
EMIT3(add_1mod(0x48, dst_reg), 0x0F,
add_1reg(0xC8, dst_reg));
break;
}
break;
case BPF_ALU | BPF_END | BPF_FROM_LE:
switch (imm32) {
case 16:
if (is_ereg(dst_reg))
EMIT3(0x45, 0x0F, 0xB7);
else
EMIT2(0x0F, 0xB7);
EMIT1(add_2reg(0xC0, dst_reg, dst_reg));
break;
case 32:
if (is_ereg(dst_reg))
EMIT1(0x45);
EMIT2(0x89, add_2reg(0xC0, dst_reg, dst_reg));
break;
case 64:
break;
}
break;
case BPF_ST | BPF_MEM | BPF_B:
if (is_ereg(dst_reg))
EMIT2(0x41, 0xC6);
else
EMIT1(0xC6);
goto st;
case BPF_ST | BPF_MEM | BPF_H:
if (is_ereg(dst_reg))
EMIT3(0x66, 0x41, 0xC7);
else
EMIT2(0x66, 0xC7);
goto st;
case BPF_ST | BPF_MEM | BPF_W:
if (is_ereg(dst_reg))
EMIT2(0x41, 0xC7);
else
EMIT1(0xC7);
goto st;
case BPF_ST | BPF_MEM | BPF_DW:
EMIT2(add_1mod(0x48, dst_reg), 0xC7);
st: if (is_imm8(insn->off))
EMIT2(add_1reg(0x40, dst_reg), insn->off);
else
EMIT1_off32(add_1reg(0x80, dst_reg), insn->off);
EMIT(imm32, bpf_size_to_x86_bytes(BPF_SIZE(insn->code)));
break;
case BPF_STX | BPF_MEM | BPF_B:
if (is_ereg(dst_reg) || is_ereg(src_reg) ||
src_reg == BPF_REG_1 || src_reg == BPF_REG_2)
EMIT2(add_2mod(0x40, dst_reg, src_reg), 0x88);
else
EMIT1(0x88);
goto stx;
case BPF_STX | BPF_MEM | BPF_H:
if (is_ereg(dst_reg) || is_ereg(src_reg))
EMIT3(0x66, add_2mod(0x40, dst_reg, src_reg), 0x89);
else
EMIT2(0x66, 0x89);
goto stx;
case BPF_STX | BPF_MEM | BPF_W:
if (is_ereg(dst_reg) || is_ereg(src_reg))
EMIT2(add_2mod(0x40, dst_reg, src_reg), 0x89);
else
EMIT1(0x89);
goto stx;
case BPF_STX | BPF_MEM | BPF_DW:
EMIT2(add_2mod(0x48, dst_reg, src_reg), 0x89);
stx: if (is_imm8(insn->off))
EMIT2(add_2reg(0x40, dst_reg, src_reg), insn->off);
else
EMIT1_off32(add_2reg(0x80, dst_reg, src_reg),
insn->off);
break;
case BPF_LDX | BPF_MEM | BPF_B:
EMIT3(add_2mod(0x48, src_reg, dst_reg), 0x0F, 0xB6);
goto ldx;
case BPF_LDX | BPF_MEM | BPF_H:
EMIT3(add_2mod(0x48, src_reg, dst_reg), 0x0F, 0xB7);
goto ldx;
case BPF_LDX | BPF_MEM | BPF_W:
if (is_ereg(dst_reg) || is_ereg(src_reg))
EMIT2(add_2mod(0x40, src_reg, dst_reg), 0x8B);
else
EMIT1(0x8B);
goto ldx;
case BPF_LDX | BPF_MEM | BPF_DW:
EMIT2(add_2mod(0x48, src_reg, dst_reg), 0x8B);
ldx:
if (is_imm8(insn->off))
EMIT2(add_2reg(0x40, src_reg, dst_reg), insn->off);
else
EMIT1_off32(add_2reg(0x80, src_reg, dst_reg),
insn->off);
break;
case BPF_STX | BPF_XADD | BPF_W:
if (is_ereg(dst_reg) || is_ereg(src_reg))
EMIT3(0xF0, add_2mod(0x40, dst_reg, src_reg), 0x01);
else
EMIT2(0xF0, 0x01);
goto xadd;
case BPF_STX | BPF_XADD | BPF_DW:
EMIT3(0xF0, add_2mod(0x48, dst_reg, src_reg), 0x01);
xadd: if (is_imm8(insn->off))
EMIT2(add_2reg(0x40, dst_reg, src_reg), insn->off);
else
EMIT1_off32(add_2reg(0x80, dst_reg, src_reg),
insn->off);
break;
case BPF_JMP | BPF_CALL:
func = (u8 *) __bpf_call_base + imm32;
jmp_offset = func - (image + addrs[i]);
if (seen_ld_abs) {
reload_skb_data = bpf_helper_changes_pkt_data(func);
if (reload_skb_data) {
EMIT1(0x57);
jmp_offset += 22;
} else {
EMIT2(0x41, 0x52);
EMIT2(0x41, 0x51);
jmp_offset += 4;
}
}
if (!imm32 || !is_simm32(jmp_offset)) {
pr_err("unsupported bpf func %d addr %p image %p\n",
imm32, func, image);
return -EINVAL;
}
EMIT1_off32(0xE8, jmp_offset);
if (seen_ld_abs) {
if (reload_skb_data) {
EMIT1(0x5F);
emit_load_skb_data_hlen(&prog);
} else {
EMIT2(0x41, 0x59);
EMIT2(0x41, 0x5A);
}
}
break;
case BPF_JMP | BPF_CALL | BPF_X:
emit_bpf_tail_call(&prog);
break;
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JNE | BPF_X:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JSGT | BPF_X:
case BPF_JMP | BPF_JSGE | BPF_X:
EMIT3(add_2mod(0x48, dst_reg, src_reg), 0x39,
add_2reg(0xC0, dst_reg, src_reg));
goto emit_cond_jmp;
case BPF_JMP | BPF_JSET | BPF_X:
EMIT3(add_2mod(0x48, dst_reg, src_reg), 0x85,
add_2reg(0xC0, dst_reg, src_reg));
goto emit_cond_jmp;
case BPF_JMP | BPF_JSET | BPF_K:
EMIT1(add_1mod(0x48, dst_reg));
EMIT2_off32(0xF7, add_1reg(0xC0, dst_reg), imm32);
goto emit_cond_jmp;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JNE | BPF_K:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JSGT | BPF_K:
case BPF_JMP | BPF_JSGE | BPF_K:
EMIT1(add_1mod(0x48, dst_reg));
if (is_imm8(imm32))
EMIT3(0x83, add_1reg(0xF8, dst_reg), imm32);
else
EMIT2_off32(0x81, add_1reg(0xF8, dst_reg), imm32);
emit_cond_jmp:
switch (BPF_OP(insn->code)) {
case BPF_JEQ:
jmp_cond = X86_JE;
break;
case BPF_JSET:
case BPF_JNE:
jmp_cond = X86_JNE;
break;
case BPF_JGT:
jmp_cond = X86_JA;
break;
case BPF_JGE:
jmp_cond = X86_JAE;
break;
case BPF_JSGT:
jmp_cond = X86_JG;
break;
case BPF_JSGE:
jmp_cond = X86_JGE;
break;
default:
return -EFAULT;
}
jmp_offset = addrs[i + insn->off] - addrs[i];
if (is_imm8(jmp_offset)) {
EMIT2(jmp_cond, jmp_offset);
} else if (is_simm32(jmp_offset)) {
EMIT2_off32(0x0F, jmp_cond + 0x10, jmp_offset);
} else {
pr_err("cond_jmp gen bug %llx\n", jmp_offset);
return -EFAULT;
}
break;
case BPF_JMP | BPF_JA:
jmp_offset = addrs[i + insn->off] - addrs[i];
if (!jmp_offset)
break;
emit_jmp:
if (is_imm8(jmp_offset)) {
EMIT2(0xEB, jmp_offset);
} else if (is_simm32(jmp_offset)) {
EMIT1_off32(0xE9, jmp_offset);
} else {
pr_err("jmp gen bug %llx\n", jmp_offset);
return -EFAULT;
}
break;
case BPF_LD | BPF_IND | BPF_W:
func = sk_load_word;
goto common_load;
case BPF_LD | BPF_ABS | BPF_W:
func = CHOOSE_LOAD_FUNC(imm32, sk_load_word);
common_load:
ctx->seen_ld_abs = seen_ld_abs = true;
jmp_offset = func - (image + addrs[i]);
if (!func || !is_simm32(jmp_offset)) {
pr_err("unsupported bpf func %d addr %p image %p\n",
imm32, func, image);
return -EINVAL;
}
if (BPF_MODE(insn->code) == BPF_ABS) {
EMIT1_off32(0xBE, imm32);
} else {
EMIT_mov(BPF_REG_2, src_reg);
if (imm32) {
if (is_imm8(imm32))
EMIT3(0x83, 0xC6, imm32);
else
EMIT2_off32(0x81, 0xC6, imm32);
}
}
if (seen_ax_reg)
EMIT3_off32(0x4c, 0x8b, 0x93,
offsetof(struct sk_buff, data));
EMIT1_off32(0xE8, jmp_offset);
break;
case BPF_LD | BPF_IND | BPF_H:
func = sk_load_half;
goto common_load;
case BPF_LD | BPF_ABS | BPF_H:
func = CHOOSE_LOAD_FUNC(imm32, sk_load_half);
goto common_load;
case BPF_LD | BPF_IND | BPF_B:
func = sk_load_byte;
goto common_load;
case BPF_LD | BPF_ABS | BPF_B:
func = CHOOSE_LOAD_FUNC(imm32, sk_load_byte);
goto common_load;
case BPF_JMP | BPF_EXIT:
if (seen_exit) {
jmp_offset = ctx->cleanup_addr - addrs[i];
goto emit_jmp;
}
seen_exit = true;
ctx->cleanup_addr = proglen;
EMIT3_off32(0x48, 0x8B, 0x9D, -STACKSIZE);
EMIT3_off32(0x4C, 0x8B, 0xAD, -STACKSIZE + 8);
EMIT3_off32(0x4C, 0x8B, 0xB5, -STACKSIZE + 16);
EMIT3_off32(0x4C, 0x8B, 0xBD, -STACKSIZE + 24);
EMIT1(0xC9);
EMIT1(0xC3);
break;
default:
pr_err("bpf_jit: unknown opcode %02x\n", insn->code);
return -EINVAL;
}
ilen = prog - temp;
if (ilen > BPF_MAX_INSN_SIZE) {
pr_err("bpf_jit: fatal insn size error\n");
return -EFAULT;
}
if (image) {
if (unlikely(proglen + ilen > oldproglen)) {
pr_err("bpf_jit: fatal error\n");
return -EFAULT;
}
memcpy(image + proglen, temp, ilen);
}
proglen += ilen;
addrs[i] = proglen;
prog = temp;
}
return proglen;
}
struct bpf_prog *bpf_int_jit_compile(struct bpf_prog *prog)
{
struct bpf_binary_header *header = NULL;
struct bpf_prog *tmp, *orig_prog = prog;
int proglen, oldproglen = 0;
struct jit_context ctx = {};
bool tmp_blinded = false;
u8 *image = NULL;
int *addrs;
int pass;
int i;
if (!bpf_jit_enable)
return orig_prog;
tmp = bpf_jit_blind_constants(prog);
if (IS_ERR(tmp))
return orig_prog;
if (tmp != prog) {
tmp_blinded = true;
prog = tmp;
}
addrs = kmalloc(prog->len * sizeof(*addrs), GFP_KERNEL);
if (!addrs) {
prog = orig_prog;
goto out;
}
for (proglen = 0, i = 0; i < prog->len; i++) {
proglen += 64;
addrs[i] = proglen;
}
ctx.cleanup_addr = proglen;
for (pass = 0; pass < 10 || image; pass++) {
proglen = do_jit(prog, addrs, image, oldproglen, &ctx);
if (proglen <= 0) {
image = NULL;
if (header)
bpf_jit_binary_free(header);
prog = orig_prog;
goto out_addrs;
}
if (image) {
if (proglen != oldproglen) {
pr_err("bpf_jit: proglen=%d != oldproglen=%d\n",
proglen, oldproglen);
prog = orig_prog;
goto out_addrs;
}
break;
}
if (proglen == oldproglen) {
header = bpf_jit_binary_alloc(proglen, &image,
1, jit_fill_hole);
if (!header) {
prog = orig_prog;
goto out_addrs;
}
}
oldproglen = proglen;
}
if (bpf_jit_enable > 1)
bpf_jit_dump(prog->len, proglen, pass + 1, image);
if (image) {
bpf_flush_icache(header, image + proglen);
bpf_jit_binary_lock_ro(header);
prog->bpf_func = (void *)image;
prog->jited = 1;
} else {
prog = orig_prog;
}
out_addrs:
kfree(addrs);
out:
if (tmp_blinded)
bpf_jit_prog_release_other(prog, prog == orig_prog ?
tmp : orig_prog);
return prog;
}
