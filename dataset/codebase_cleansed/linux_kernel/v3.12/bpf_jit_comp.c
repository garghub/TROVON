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
static int pkt_type_offset(void)
{
struct sk_buff skb_probe = {
.pkt_type = ~0,
};
char *ct = (char *)&skb_probe;
unsigned int off;
for (off = 0; off < sizeof(struct sk_buff); off++) {
if (ct[off] == PKT_TYPE_MAX)
return off;
}
pr_err_once("Please fix pkt_type_offset(), as pkt_type couldn't be found\n");
return -1;
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
hole = sz - (proglen + sizeof(*header));
*image_ptr = &header->image[prandom_u32() % hole];
return header;
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
struct bpf_binary_header *header = NULL;
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
u8 seen_or_pass0 = (pass == 0) ? (SEEN_XREG | SEEN_DATAREF | SEEN_MEM) : seen;
proglen = 0;
prog = temp;
if (seen_or_pass0) {
EMIT4(0x55, 0x48, 0x89, 0xe5);
EMIT4(0x48, 0x83, 0xec, 96);
if (seen_or_pass0 & (SEEN_XREG | SEEN_DATAREF))
EMIT4(0x48, 0x89, 0x5d, 0xf8);
if (seen_or_pass0 & SEEN_XREG)
CLEAR_X();
if (seen_or_pass0 & SEEN_DATAREF) {
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
case BPF_S_ANC_VLAN_TAG:
case BPF_S_ANC_VLAN_TAG_PRESENT:
case BPF_S_ANC_QUEUE:
case BPF_S_ANC_PKTTYPE:
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
if (pc_ret0 > 0) {
EMIT_COND_JMP(X86_JE, addrs[pc_ret0 - 1] -
(addrs[i] - 4));
} else {
EMIT_COND_JMP(X86_JNE, 2 + 5);
CLEAR_A();
EMIT1_off32(0xe9, cleanup_addr - (addrs[i] - 4));
}
EMIT4(0x31, 0xd2, 0xf7, 0xf3);
break;
case BPF_S_ALU_MOD_X:
seen |= SEEN_XREG;
EMIT2(0x85, 0xdb);
if (pc_ret0 > 0) {
EMIT_COND_JMP(X86_JE, addrs[pc_ret0 - 1] -
(addrs[i] - 6));
} else {
EMIT_COND_JMP(X86_JNE, 2 + 5);
CLEAR_A();
EMIT1_off32(0xe9, cleanup_addr - (addrs[i] - 6));
}
EMIT2(0x31, 0xd2);
EMIT2(0xf7, 0xf3);
EMIT2(0x89, 0xd0);
break;
case BPF_S_ALU_MOD_K:
EMIT2(0x31, 0xd2);
EMIT1(0xb9);EMIT(K, 4);
EMIT2(0xf7, 0xf1);
EMIT2(0x89, 0xd0);
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
EMIT(K, 2);
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
case BPF_S_ANC_ALU_XOR_X:
case BPF_S_ALU_XOR_X:
seen |= SEEN_XREG;
EMIT2(0x31, 0xd8);
break;
case BPF_S_ALU_XOR_K:
if (K == 0)
break;
if (is_imm8(K))
EMIT3(0x83, 0xf0, K);
else
EMIT1_off32(0x35, K);
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
if (seen_or_pass0) {
if (i != flen - 1) {
EMIT_JMP(cleanup_addr - addrs[i]);
break;
}
if (seen_or_pass0 & SEEN_XREG)
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
case BPF_S_ANC_VLAN_TAG:
case BPF_S_ANC_VLAN_TAG_PRESENT:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, vlan_tci) != 2);
if (is_imm8(offsetof(struct sk_buff, vlan_tci))) {
EMIT4(0x0f, 0xb7, 0x47, offsetof(struct sk_buff, vlan_tci));
} else {
EMIT3(0x0f, 0xb7, 0x87);
EMIT(offsetof(struct sk_buff, vlan_tci), 4);
}
BUILD_BUG_ON(VLAN_TAG_PRESENT != 0x1000);
if (filter[i].code == BPF_S_ANC_VLAN_TAG) {
EMIT3(0x80, 0xe4, 0xef);
} else {
EMIT3(0xc1, 0xe8, 0x0c);
EMIT3(0x83, 0xe0, 0x01);
}
break;
case BPF_S_ANC_PKTTYPE:
{
int off = pkt_type_offset();
if (off < 0)
goto out;
if (is_imm8(off)) {
EMIT4(0x0f, 0xb6, 0x47, off);
} else {
EMIT3(0x0f, 0xb6, 0x87);
EMIT(off, 4);
}
EMIT3(0x83, 0xe0, PKT_TYPE_MAX);
break;
}
case BPF_S_LD_W_ABS:
func = CHOOSE_LOAD_FUNC(K, sk_load_word);
common_load: seen |= SEEN_DATAREF;
t_offset = func - (image + addrs[i]);
EMIT1_off32(0xbe, K);
EMIT1_off32(0xe8, t_offset);
break;
case BPF_S_LD_H_ABS:
func = CHOOSE_LOAD_FUNC(K, sk_load_half);
goto common_load;
case BPF_S_LD_B_ABS:
func = CHOOSE_LOAD_FUNC(K, sk_load_byte);
goto common_load;
case BPF_S_LDX_B_MSH:
func = CHOOSE_LOAD_FUNC(K, sk_load_byte_msh);
seen |= SEEN_DATAREF | SEEN_XREG;
t_offset = func - (image + addrs[i]);
EMIT1_off32(0xbe, K);
EMIT1_off32(0xe8, t_offset);
break;
case BPF_S_LD_W_IND:
func = sk_load_word;
common_load_ind: seen |= SEEN_DATAREF | SEEN_XREG;
t_offset = func - (image + addrs[i]);
if (K) {
if (is_imm8(K)) {
EMIT3(0x8d, 0x73, K);
} else {
EMIT2(0x8d, 0xb3);
EMIT(K, 4);
}
} else {
EMIT2(0x89,0xde);
}
EMIT1_off32(0xe8, t_offset);
break;
case BPF_S_LD_H_IND:
func = sk_load_half;
goto common_load_ind;
case BPF_S_LD_B_IND:
func = sk_load_byte;
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
if (filter[i].jf && f_offset)
t_offset += is_near(f_offset) ? 2 : 5;
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
module_free(NULL, header);
return;
}
memcpy(image + proglen, temp, ilen);
}
proglen += ilen;
addrs[i] = proglen;
prog = temp;
}
cleanup_addr = proglen - 1;
if (seen_or_pass0)
cleanup_addr -= 1;
if (seen_or_pass0 & SEEN_XREG)
cleanup_addr -= 4;
if (image) {
if (proglen != oldproglen)
pr_err("bpb_jit_compile proglen=%u != oldproglen=%u\n", proglen, oldproglen);
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
bpf_jit_dump(flen, proglen, pass, image);
if (image) {
bpf_flush_icache(header, image + proglen);
set_memory_ro((unsigned long)header, header->pages);
fp->bpf_func = (void *)image;
}
out:
kfree(addrs);
return;
}
static void bpf_jit_free_deferred(struct work_struct *work)
{
struct sk_filter *fp = container_of(work, struct sk_filter, work);
unsigned long addr = (unsigned long)fp->bpf_func & PAGE_MASK;
struct bpf_binary_header *header = (void *)addr;
set_memory_rw(addr, header->pages);
module_free(NULL, header);
kfree(fp);
}
void bpf_jit_free(struct sk_filter *fp)
{
if (fp->bpf_func != sk_run_filter) {
INIT_WORK(&fp->work, bpf_jit_free_deferred);
schedule_work(&fp->work);
}
}
