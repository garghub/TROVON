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
static inline bool is_near(int offset)
{
return offset <= 127 && offset >= -128;
}
static inline void bpf_flush_icache(void *start, void *end)
{
mm_segment_t old_fs = get_fs();
set_fs(KERNEL_DS);
smp_wmb();
flush_icache_range((unsigned long)start, (unsigned long)end);
set_fs(old_fs);
}
void bpf_jit_compile(struct sk_filter *fp)
{
u8 temp[64];
u8 *prog;
unsigned int proglen, oldproglen = 0;
int ilen, i;
int t_offset, f_offset;
u8 t_op, f_op, seen = 0, pass;
u8 *image = NULL;
u8 *func;
int pc_ret0 = -1;
unsigned int cleanup_addr;
unsigned int *addrs;
const struct sock_filter *filter = fp->insns;
int flen = fp->len;
if (!bpf_jit_enable)
return;
addrs = kmalloc(flen * sizeof(*addrs), GFP_KERNEL);
if (addrs == NULL)
return;
for (proglen = 0, i = 0; i < flen; i++) {
proglen += 64;
addrs[i] = proglen;
}
cleanup_addr = proglen;
for (pass = 0; pass < 10; pass++) {
proglen = 0;
prog = temp;
if (seen) {
EMIT4(0x55, 0x48, 0x89, 0xe5);
EMIT4(0x48, 0x83, 0xec, 96);
if (seen & (SEEN_XREG | SEEN_DATAREF))
EMIT4(0x48, 0x89, 0x5d, 0xf8);
if (seen & SEEN_XREG)
CLEAR_X();
if (seen & SEEN_DATAREF) {
if (offsetof(struct sk_buff, len) <= 127)
EMIT4(0x44, 0x8b, 0x4f, offsetof(struct sk_buff, len));
else {
EMIT3(0x44, 0x8b, 0x8f);
EMIT(offsetof(struct sk_buff, len), 4);
}
if (is_imm8(offsetof(struct sk_buff, data_len)))
EMIT4(0x44, 0x2b, 0x4f, offsetof(struct sk_buff, data_len));
else {
EMIT3(0x44, 0x2b, 0x8f);
EMIT(offsetof(struct sk_buff, data_len), 4);
}
if (is_imm8(offsetof(struct sk_buff, data)))
EMIT4(0x4c, 0x8b, 0x47, offsetof(struct sk_buff, data));
else {
EMIT3(0x4c, 0x8b, 0x87);
EMIT(offsetof(struct sk_buff, data), 4);
}
}
}
switch (filter[0].code) {
case BPF_S_RET_K:
case BPF_S_LD_W_LEN:
case BPF_S_ANC_PROTOCOL:
case BPF_S_ANC_IFINDEX:
case BPF_S_ANC_MARK:
case BPF_S_ANC_RXHASH:
case BPF_S_ANC_CPU:
case BPF_S_ANC_QUEUE:
case BPF_S_LD_W_ABS:
case BPF_S_LD_H_ABS:
case BPF_S_LD_B_ABS:
break;
default:
CLEAR_A();
}
for (i = 0; i < flen; i++) {
unsigned int K = filter[i].k;
switch (filter[i].code) {
case BPF_S_ALU_ADD_X:
seen |= SEEN_XREG;
EMIT2(0x01, 0xd8);
break;
case BPF_S_ALU_ADD_K:
if (!K)
break;
if (is_imm8(K))
EMIT3(0x83, 0xc0, K);
else
EMIT1_off32(0x05, K);
break;
case BPF_S_ALU_SUB_X:
seen |= SEEN_XREG;
EMIT2(0x29, 0xd8);
break;
case BPF_S_ALU_SUB_K:
if (!K)
break;
if (is_imm8(K))
EMIT3(0x83, 0xe8, K);
else
EMIT1_off32(0x2d, K);
break;
case BPF_S_ALU_MUL_X:
seen |= SEEN_XREG;
EMIT3(0x0f, 0xaf, 0xc3);
break;
case BPF_S_ALU_MUL_K:
if (is_imm8(K))
EMIT3(0x6b, 0xc0, K);
else {
EMIT2(0x69, 0xc0);
EMIT(K, 4);
}
break;
case BPF_S_ALU_DIV_X:
seen |= SEEN_XREG;
EMIT2(0x85, 0xdb);
if (pc_ret0 != -1)
EMIT_COND_JMP(X86_JE, addrs[pc_ret0] - (addrs[i] - 4));
else {
EMIT_COND_JMP(X86_JNE, 2 + 5);
CLEAR_A();
EMIT1_off32(0xe9, cleanup_addr - (addrs[i] - 4));
}
EMIT4(0x31, 0xd2, 0xf7, 0xf3);
break;
case BPF_S_ALU_DIV_K:
EMIT3(0x48, 0x69, 0xc0);
EMIT(K, 4);
EMIT4(0x48, 0xc1, 0xe8, 0x20);
break;
case BPF_S_ALU_AND_X:
seen |= SEEN_XREG;
EMIT2(0x21, 0xd8);
break;
case BPF_S_ALU_AND_K:
if (K >= 0xFFFFFF00) {
EMIT2(0x24, K & 0xFF);
} else if (K >= 0xFFFF0000) {
EMIT2(0x66, 0x25);
EMIT2(K, 2);
} else {
EMIT1_off32(0x25, K);
}
break;
case BPF_S_ALU_OR_X:
seen |= SEEN_XREG;
EMIT2(0x09, 0xd8);
break;
case BPF_S_ALU_OR_K:
if (is_imm8(K))
EMIT3(0x83, 0xc8, K);
else
EMIT1_off32(0x0d, K);
break;
case BPF_S_ALU_LSH_X:
seen |= SEEN_XREG;
EMIT4(0x89, 0xd9, 0xd3, 0xe0);
break;
case BPF_S_ALU_LSH_K:
if (K == 0)
break;
else if (K == 1)
EMIT2(0xd1, 0xe0);
else
EMIT3(0xc1, 0xe0, K);
break;
case BPF_S_ALU_RSH_X:
seen |= SEEN_XREG;
EMIT4(0x89, 0xd9, 0xd3, 0xe8);
break;
case BPF_S_ALU_RSH_K:
if (K == 0)
break;
else if (K == 1)
EMIT2(0xd1, 0xe8);
else
EMIT3(0xc1, 0xe8, K);
break;
case BPF_S_ALU_NEG:
EMIT2(0xf7, 0xd8);
break;
case BPF_S_RET_K:
if (!K) {
if (pc_ret0 == -1)
pc_ret0 = i;
CLEAR_A();
} else {
EMIT1_off32(0xb8, K);
}
case BPF_S_RET_A:
if (seen) {
if (i != flen - 1) {
EMIT_JMP(cleanup_addr - addrs[i]);
break;
}
if (seen & SEEN_XREG)
EMIT4(0x48, 0x8b, 0x5d, 0xf8);
EMIT1(0xc9);
}
EMIT1(0xc3);
break;
case BPF_S_MISC_TAX:
seen |= SEEN_XREG;
EMIT2(0x89, 0xc3);
break;
case BPF_S_MISC_TXA:
seen |= SEEN_XREG;
EMIT2(0x89, 0xd8);
break;
case BPF_S_LD_IMM:
if (!K)
CLEAR_A();
else
EMIT1_off32(0xb8, K);
break;
case BPF_S_LDX_IMM:
seen |= SEEN_XREG;
if (!K)
CLEAR_X();
else
EMIT1_off32(0xbb, K);
break;
case BPF_S_LD_MEM:
seen |= SEEN_MEM;
EMIT3(0x8b, 0x45, 0xf0 - K*4);
break;
case BPF_S_LDX_MEM:
seen |= SEEN_XREG | SEEN_MEM;
EMIT3(0x8b, 0x5d, 0xf0 - K*4);
break;
case BPF_S_ST:
seen |= SEEN_MEM;
EMIT3(0x89, 0x45, 0xf0 - K*4);
break;
case BPF_S_STX:
seen |= SEEN_XREG | SEEN_MEM;
EMIT3(0x89, 0x5d, 0xf0 - K*4);
break;
case BPF_S_LD_W_LEN:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, len) != 4);
if (is_imm8(offsetof(struct sk_buff, len)))
EMIT3(0x8b, 0x47, offsetof(struct sk_buff, len));
else {
EMIT2(0x8b, 0x87);
EMIT(offsetof(struct sk_buff, len), 4);
}
break;
case BPF_S_LDX_W_LEN:
seen |= SEEN_XREG;
if (is_imm8(offsetof(struct sk_buff, len)))
EMIT3(0x8b, 0x5f, offsetof(struct sk_buff, len));
else {
EMIT2(0x8b, 0x9f);
EMIT(offsetof(struct sk_buff, len), 4);
}
break;
case BPF_S_ANC_PROTOCOL:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, protocol) != 2);
if (is_imm8(offsetof(struct sk_buff, protocol))) {
EMIT4(0x0f, 0xb7, 0x47, offsetof(struct sk_buff, protocol));
} else {
EMIT3(0x0f, 0xb7, 0x87);
EMIT(offsetof(struct sk_buff, protocol), 4);
}
EMIT2(0x86, 0xc4);
break;
case BPF_S_ANC_IFINDEX:
if (is_imm8(offsetof(struct sk_buff, dev))) {
EMIT4(0x48, 0x8b, 0x47, offsetof(struct sk_buff, dev));
} else {
EMIT3(0x48, 0x8b, 0x87);
EMIT(offsetof(struct sk_buff, dev), 4);
}
EMIT3(0x48, 0x85, 0xc0);
EMIT_COND_JMP(X86_JE, cleanup_addr - (addrs[i] - 6));
BUILD_BUG_ON(FIELD_SIZEOF(struct net_device, ifindex) != 4);
EMIT2(0x8b, 0x80);
EMIT(offsetof(struct net_device, ifindex), 4);
break;
case BPF_S_ANC_MARK:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, mark) != 4);
if (is_imm8(offsetof(struct sk_buff, mark))) {
EMIT3(0x8b, 0x47, offsetof(struct sk_buff, mark));
} else {
EMIT2(0x8b, 0x87);
EMIT(offsetof(struct sk_buff, mark), 4);
}
break;
case BPF_S_ANC_RXHASH:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, rxhash) != 4);
if (is_imm8(offsetof(struct sk_buff, rxhash))) {
EMIT3(0x8b, 0x47, offsetof(struct sk_buff, rxhash));
} else {
EMIT2(0x8b, 0x87);
EMIT(offsetof(struct sk_buff, rxhash), 4);
}
break;
case BPF_S_ANC_QUEUE:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, queue_mapping) != 2);
if (is_imm8(offsetof(struct sk_buff, queue_mapping))) {
EMIT4(0x0f, 0xb7, 0x47, offsetof(struct sk_buff, queue_mapping));
} else {
EMIT3(0x0f, 0xb7, 0x87);
EMIT(offsetof(struct sk_buff, queue_mapping), 4);
}
break;
case BPF_S_ANC_CPU:
#ifdef CONFIG_SMP
EMIT4(0x65, 0x8b, 0x04, 0x25);
EMIT((u32)(unsigned long)&cpu_number, 4);
#else
CLEAR_A();
#endif
break;
case BPF_S_LD_W_ABS:
func = sk_load_word;
common_load: seen |= SEEN_DATAREF;
if ((int)K < 0)
goto out;
t_offset = func - (image + addrs[i]);
EMIT1_off32(0xbe, K);
EMIT1_off32(0xe8, t_offset);
break;
case BPF_S_LD_H_ABS:
func = sk_load_half;
goto common_load;
case BPF_S_LD_B_ABS:
func = sk_load_byte;
goto common_load;
case BPF_S_LDX_B_MSH:
if ((int)K < 0) {
if (pc_ret0 != -1) {
EMIT_JMP(addrs[pc_ret0] - addrs[i]);
break;
}
CLEAR_A();
EMIT_JMP(cleanup_addr - addrs[i]);
break;
}
seen |= SEEN_DATAREF | SEEN_XREG;
t_offset = sk_load_byte_msh - (image + addrs[i]);
EMIT1_off32(0xbe, K);
EMIT1_off32(0xe8, t_offset);
break;
case BPF_S_LD_W_IND:
func = sk_load_word_ind;
common_load_ind: seen |= SEEN_DATAREF | SEEN_XREG;
t_offset = func - (image + addrs[i]);
EMIT1_off32(0xbe, K);
EMIT1_off32(0xe8, t_offset);
break;
case BPF_S_LD_H_IND:
func = sk_load_half_ind;
goto common_load_ind;
case BPF_S_LD_B_IND:
func = sk_load_byte_ind;
goto common_load_ind;
case BPF_S_JMP_JA:
t_offset = addrs[i + K] - addrs[i];
EMIT_JMP(t_offset);
break;
COND_SEL(BPF_S_JMP_JGT_K, X86_JA, X86_JBE);
COND_SEL(BPF_S_JMP_JGE_K, X86_JAE, X86_JB);
COND_SEL(BPF_S_JMP_JEQ_K, X86_JE, X86_JNE);
COND_SEL(BPF_S_JMP_JSET_K,X86_JNE, X86_JE);
COND_SEL(BPF_S_JMP_JGT_X, X86_JA, X86_JBE);
COND_SEL(BPF_S_JMP_JGE_X, X86_JAE, X86_JB);
COND_SEL(BPF_S_JMP_JEQ_X, X86_JE, X86_JNE);
COND_SEL(BPF_S_JMP_JSET_X,X86_JNE, X86_JE);
cond_branch: f_offset = addrs[i + filter[i].jf] - addrs[i];
t_offset = addrs[i + filter[i].jt] - addrs[i];
if (filter[i].jt == filter[i].jf) {
EMIT_JMP(t_offset);
break;
}
switch (filter[i].code) {
case BPF_S_JMP_JGT_X:
case BPF_S_JMP_JGE_X:
case BPF_S_JMP_JEQ_X:
seen |= SEEN_XREG;
EMIT2(0x39, 0xd8);
break;
case BPF_S_JMP_JSET_X:
seen |= SEEN_XREG;
EMIT2(0x85, 0xd8);
break;
case BPF_S_JMP_JEQ_K:
if (K == 0) {
EMIT2(0x85, 0xc0);
break;
}
case BPF_S_JMP_JGT_K:
case BPF_S_JMP_JGE_K:
if (K <= 127)
EMIT3(0x83, 0xf8, K);
else
EMIT1_off32(0x3d, K);
break;
case BPF_S_JMP_JSET_K:
if (K <= 0xFF)
EMIT2(0xa8, K);
else if (!(K & 0xFFFF00FF))
EMIT3(0xf6, 0xc4, K >> 8);
else if (K <= 0xFFFF) {
EMIT2(0x66, 0xa9);
EMIT(K, 2);
} else {
EMIT1_off32(0xa9, K);
}
break;
}
if (filter[i].jt != 0) {
if (filter[i].jf)
t_offset += is_near(f_offset) ? 2 : 6;
EMIT_COND_JMP(t_op, t_offset);
if (filter[i].jf)
EMIT_JMP(f_offset);
break;
}
EMIT_COND_JMP(f_op, f_offset);
break;
default:
goto out;
}
ilen = prog - temp;
if (image) {
if (unlikely(proglen + ilen > oldproglen)) {
pr_err("bpb_jit_compile fatal error\n");
kfree(addrs);
module_free(NULL, image);
return;
}
memcpy(image + proglen, temp, ilen);
}
proglen += ilen;
addrs[i] = proglen;
prog = temp;
}
cleanup_addr = proglen - 1;
if (seen)
cleanup_addr -= 1;
if (seen & SEEN_XREG)
cleanup_addr -= 4;
if (image) {
WARN_ON(proglen != oldproglen);
break;
}
if (proglen == oldproglen) {
image = module_alloc(max_t(unsigned int,
proglen,
sizeof(struct work_struct)));
if (!image)
goto out;
}
oldproglen = proglen;
}
if (bpf_jit_enable > 1)
pr_err("flen=%d proglen=%u pass=%d image=%p\n",
flen, proglen, pass, image);
if (image) {
if (bpf_jit_enable > 1)
print_hex_dump(KERN_ERR, "JIT code: ", DUMP_PREFIX_ADDRESS,
16, 1, image, proglen, false);
bpf_flush_icache(image, image + proglen);
fp->bpf_func = (void *)image;
}
out:
kfree(addrs);
return;
}
static void jit_free_defer(struct work_struct *arg)
{
module_free(NULL, arg);
}
void bpf_jit_free(struct sk_filter *fp)
{
if (fp->bpf_func != sk_run_filter) {
struct work_struct *work = (struct work_struct *)fp->bpf_func;
INIT_WORK(work, jit_free_defer);
schedule_work(work);
}
}
