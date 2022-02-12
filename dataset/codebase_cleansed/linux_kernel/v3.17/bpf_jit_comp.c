static inline u8 *emit_code(u8 *ptr, u32 bytes, unsigned int len)
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
static inline bool is_imm8(int value)
{
return value <= 127 && value >= -128;
}
static inline bool is_simm32(s64 value)
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
static inline void bpf_flush_icache(void *start, void *end)
{
mm_segment_t old_fs = get_fs();
set_fs(KERNEL_DS);
smp_wmb();
flush_icache_range((unsigned long)start, (unsigned long)end);
set_fs(old_fs);
}
static struct bpf_binary_header *bpf_alloc_binary(unsigned int proglen,
u8 **image_ptr)
{
unsigned int sz, hole;
struct bpf_binary_header *header;
sz = round_up(proglen + sizeof(*header) + 128, PAGE_SIZE);
header = module_alloc(sz);
if (!header)
return NULL;
memset(header, 0xcc, sz);
header->pages = sz / PAGE_SIZE;
hole = min(sz - (proglen + sizeof(*header)), PAGE_SIZE - sizeof(*header));
*image_ptr = &header->image[prandom_u32() % hole];
return header;
}
static inline bool is_ereg(u32 reg)
{
if (reg == BPF_REG_5 || reg == AUX_REG ||
(reg >= BPF_REG_7 && reg <= BPF_REG_9))
return true;
else
return false;
}
static inline u8 add_1mod(u8 byte, u32 reg)
{
if (is_ereg(reg))
byte |= 1;
return byte;
}
static inline u8 add_2mod(u8 byte, u32 r1, u32 r2)
{
if (is_ereg(r1))
byte |= 1;
if (is_ereg(r2))
byte |= 4;
return byte;
}
static inline u8 add_1reg(u8 byte, u32 dst_reg)
{
return byte + reg2hex[dst_reg];
}
static inline u8 add_2reg(u8 byte, u32 dst_reg, u32 src_reg)
{
return byte + reg2hex[dst_reg] + (reg2hex[src_reg] << 3);
}
static int do_jit(struct bpf_prog *bpf_prog, int *addrs, u8 *image,
int oldproglen, struct jit_context *ctx)
{
struct bpf_insn *insn = bpf_prog->insnsi;
int insn_cnt = bpf_prog->len;
u8 temp[64];
int i;
int proglen = 0;
u8 *prog = temp;
int stacksize = MAX_BPF_STACK +
32 +
8 ;
EMIT1(0x55);
EMIT3(0x48, 0x89, 0xE5);
EMIT3_off32(0x48, 0x81, 0xEC, stacksize);
EMIT3_off32(0x48, 0x89, 0x9D, -stacksize);
EMIT3_off32(0x4C, 0x89, 0xAD, -stacksize + 8);
EMIT3_off32(0x4C, 0x89, 0xB5, -stacksize + 16);
EMIT3_off32(0x4C, 0x89, 0xBD, -stacksize + 24);
EMIT2(0x31, 0xc0);
EMIT3(0x4D, 0x31, 0xED);
if (ctx->seen_ld_abs) {
if (is_imm8(offsetof(struct sk_buff, len)))
EMIT4(0x44, 0x8b, 0x4f,
offsetof(struct sk_buff, len));
else
EMIT3_off32(0x44, 0x8b, 0x8f,
offsetof(struct sk_buff, len));
if (is_imm8(offsetof(struct sk_buff, data_len)))
EMIT4(0x44, 0x2b, 0x4f,
offsetof(struct sk_buff, data_len));
else
EMIT3_off32(0x44, 0x2b, 0x8f,
offsetof(struct sk_buff, data_len));
if (is_imm8(offsetof(struct sk_buff, data)))
EMIT4(0x4c, 0x8b, 0x57,
offsetof(struct sk_buff, data));
else
EMIT3_off32(0x4c, 0x8b, 0x97,
offsetof(struct sk_buff, data));
}
for (i = 0; i < insn_cnt; i++, insn++) {
const s32 imm32 = insn->imm;
u32 dst_reg = insn->dst_reg;
u32 src_reg = insn->src_reg;
u8 b1 = 0, b2 = 0, b3 = 0;
s64 jmp_offset;
u8 jmp_cond;
int ilen;
u8 *func;
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
if (is_ereg(dst_reg))
EMIT1(add_1mod(0x40, dst_reg));
EMIT1_off32(add_1reg(0xB8, dst_reg), imm32);
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
case BPF_ALU | BPF_END | BPF_FROM_BE:
switch (imm32) {
case 16:
EMIT1(0x66);
if (is_ereg(dst_reg))
EMIT1(0x41);
EMIT3(0xC1, add_1reg(0xC8, dst_reg), 8);
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
if (ctx->seen_ld_abs) {
EMIT2(0x41, 0x52);
EMIT2(0x41, 0x51);
jmp_offset += 4;
}
if (!imm32 || !is_simm32(jmp_offset)) {
pr_err("unsupported bpf func %d addr %p image %p\n",
imm32, func, image);
return -EINVAL;
}
EMIT1_off32(0xE8, jmp_offset);
if (ctx->seen_ld_abs) {
EMIT2(0x41, 0x59);
EMIT2(0x41, 0x5A);
}
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
common_load: ctx->seen_ld_abs = true;
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
if (i != insn_cnt - 1) {
jmp_offset = ctx->cleanup_addr - addrs[i];
goto emit_jmp;
}
ctx->cleanup_addr = proglen;
EMIT3_off32(0x48, 0x8B, 0x9D, -stacksize);
EMIT3_off32(0x4C, 0x8B, 0xAD, -stacksize + 8);
EMIT3_off32(0x4C, 0x8B, 0xB5, -stacksize + 16);
EMIT3_off32(0x4C, 0x8B, 0xBD, -stacksize + 24);
EMIT1(0xC9);
EMIT1(0xC3);
break;
default:
pr_err("bpf_jit: unknown opcode %02x\n", insn->code);
return -EINVAL;
}
ilen = prog - temp;
if (image) {
if (unlikely(proglen + ilen > oldproglen)) {
pr_err("bpf_jit_compile fatal error\n");
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
void bpf_jit_compile(struct bpf_prog *prog)
{
}
void bpf_int_jit_compile(struct bpf_prog *prog)
{
struct bpf_binary_header *header = NULL;
int proglen, oldproglen = 0;
struct jit_context ctx = {};
u8 *image = NULL;
int *addrs;
int pass;
int i;
if (!bpf_jit_enable)
return;
if (!prog || !prog->len)
return;
addrs = kmalloc(prog->len * sizeof(*addrs), GFP_KERNEL);
if (!addrs)
return;
for (proglen = 0, i = 0; i < prog->len; i++) {
proglen += 64;
addrs[i] = proglen;
}
ctx.cleanup_addr = proglen;
for (pass = 0; pass < 10; pass++) {
proglen = do_jit(prog, addrs, image, oldproglen, &ctx);
if (proglen <= 0) {
image = NULL;
if (header)
module_free(NULL, header);
goto out;
}
if (image) {
if (proglen != oldproglen)
pr_err("bpf_jit: proglen=%d != oldproglen=%d\n",
proglen, oldproglen);
break;
}
if (proglen == oldproglen) {
header = bpf_alloc_binary(proglen, &image);
if (!header)
goto out;
}
oldproglen = proglen;
}
if (bpf_jit_enable > 1)
bpf_jit_dump(prog->len, proglen, 0, image);
if (image) {
bpf_flush_icache(header, image + proglen);
set_memory_ro((unsigned long)header, header->pages);
prog->bpf_func = (void *)image;
prog->jited = 1;
}
out:
kfree(addrs);
}
static void bpf_jit_free_deferred(struct work_struct *work)
{
struct bpf_prog *fp = container_of(work, struct bpf_prog, work);
unsigned long addr = (unsigned long)fp->bpf_func & PAGE_MASK;
struct bpf_binary_header *header = (void *)addr;
set_memory_rw(addr, header->pages);
module_free(NULL, header);
kfree(fp);
}
void bpf_jit_free(struct bpf_prog *fp)
{
if (fp->jited) {
INIT_WORK(&fp->work, bpf_jit_free_deferred);
schedule_work(&fp->work);
} else {
kfree(fp);
}
}
