void *bpf_internal_load_pointer_neg_helper(const struct sk_buff *skb, int k, unsigned int size)
{
u8 *ptr = NULL;
if (k >= SKF_NET_OFF)
ptr = skb_network_header(skb) + k - SKF_NET_OFF;
else if (k >= SKF_LL_OFF)
ptr = skb_mac_header(skb) + k - SKF_LL_OFF;
if (ptr >= skb->head && ptr + size <= skb_tail_pointer(skb))
return ptr;
return NULL;
}
static inline void *load_pointer(const struct sk_buff *skb, int k,
unsigned int size, void *buffer)
{
if (k >= 0)
return skb_header_pointer(skb, k, size, buffer);
return bpf_internal_load_pointer_neg_helper(skb, k, size);
}
int sk_filter(struct sock *sk, struct sk_buff *skb)
{
int err;
struct sk_filter *filter;
if (skb_pfmemalloc(skb) && !sock_flag(sk, SOCK_MEMALLOC))
return -ENOMEM;
err = security_sock_rcv_skb(sk, skb);
if (err)
return err;
rcu_read_lock();
filter = rcu_dereference(sk->sk_filter);
if (filter) {
unsigned int pkt_len = SK_RUN_FILTER(filter, skb);
err = pkt_len ? pskb_trim(skb, pkt_len) : -EPERM;
}
rcu_read_unlock();
return err;
}
noinline u64 __bpf_call_base(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
return 0;
}
static unsigned int __sk_run_filter(void *ctx, const struct sock_filter_int *insn)
{
u64 stack[MAX_BPF_STACK / sizeof(u64)];
u64 regs[MAX_BPF_REG], tmp;
static const void *jumptable[256] = {
[0 ... 255] = &&default_label,
[BPF_ALU | BPF_ADD | BPF_X] = &&ALU_ADD_X,
[BPF_ALU | BPF_ADD | BPF_K] = &&ALU_ADD_K,
[BPF_ALU | BPF_SUB | BPF_X] = &&ALU_SUB_X,
[BPF_ALU | BPF_SUB | BPF_K] = &&ALU_SUB_K,
[BPF_ALU | BPF_AND | BPF_X] = &&ALU_AND_X,
[BPF_ALU | BPF_AND | BPF_K] = &&ALU_AND_K,
[BPF_ALU | BPF_OR | BPF_X] = &&ALU_OR_X,
[BPF_ALU | BPF_OR | BPF_K] = &&ALU_OR_K,
[BPF_ALU | BPF_LSH | BPF_X] = &&ALU_LSH_X,
[BPF_ALU | BPF_LSH | BPF_K] = &&ALU_LSH_K,
[BPF_ALU | BPF_RSH | BPF_X] = &&ALU_RSH_X,
[BPF_ALU | BPF_RSH | BPF_K] = &&ALU_RSH_K,
[BPF_ALU | BPF_XOR | BPF_X] = &&ALU_XOR_X,
[BPF_ALU | BPF_XOR | BPF_K] = &&ALU_XOR_K,
[BPF_ALU | BPF_MUL | BPF_X] = &&ALU_MUL_X,
[BPF_ALU | BPF_MUL | BPF_K] = &&ALU_MUL_K,
[BPF_ALU | BPF_MOV | BPF_X] = &&ALU_MOV_X,
[BPF_ALU | BPF_MOV | BPF_K] = &&ALU_MOV_K,
[BPF_ALU | BPF_DIV | BPF_X] = &&ALU_DIV_X,
[BPF_ALU | BPF_DIV | BPF_K] = &&ALU_DIV_K,
[BPF_ALU | BPF_MOD | BPF_X] = &&ALU_MOD_X,
[BPF_ALU | BPF_MOD | BPF_K] = &&ALU_MOD_K,
[BPF_ALU | BPF_NEG] = &&ALU_NEG,
[BPF_ALU | BPF_END | BPF_TO_BE] = &&ALU_END_TO_BE,
[BPF_ALU | BPF_END | BPF_TO_LE] = &&ALU_END_TO_LE,
[BPF_ALU64 | BPF_ADD | BPF_X] = &&ALU64_ADD_X,
[BPF_ALU64 | BPF_ADD | BPF_K] = &&ALU64_ADD_K,
[BPF_ALU64 | BPF_SUB | BPF_X] = &&ALU64_SUB_X,
[BPF_ALU64 | BPF_SUB | BPF_K] = &&ALU64_SUB_K,
[BPF_ALU64 | BPF_AND | BPF_X] = &&ALU64_AND_X,
[BPF_ALU64 | BPF_AND | BPF_K] = &&ALU64_AND_K,
[BPF_ALU64 | BPF_OR | BPF_X] = &&ALU64_OR_X,
[BPF_ALU64 | BPF_OR | BPF_K] = &&ALU64_OR_K,
[BPF_ALU64 | BPF_LSH | BPF_X] = &&ALU64_LSH_X,
[BPF_ALU64 | BPF_LSH | BPF_K] = &&ALU64_LSH_K,
[BPF_ALU64 | BPF_RSH | BPF_X] = &&ALU64_RSH_X,
[BPF_ALU64 | BPF_RSH | BPF_K] = &&ALU64_RSH_K,
[BPF_ALU64 | BPF_XOR | BPF_X] = &&ALU64_XOR_X,
[BPF_ALU64 | BPF_XOR | BPF_K] = &&ALU64_XOR_K,
[BPF_ALU64 | BPF_MUL | BPF_X] = &&ALU64_MUL_X,
[BPF_ALU64 | BPF_MUL | BPF_K] = &&ALU64_MUL_K,
[BPF_ALU64 | BPF_MOV | BPF_X] = &&ALU64_MOV_X,
[BPF_ALU64 | BPF_MOV | BPF_K] = &&ALU64_MOV_K,
[BPF_ALU64 | BPF_ARSH | BPF_X] = &&ALU64_ARSH_X,
[BPF_ALU64 | BPF_ARSH | BPF_K] = &&ALU64_ARSH_K,
[BPF_ALU64 | BPF_DIV | BPF_X] = &&ALU64_DIV_X,
[BPF_ALU64 | BPF_DIV | BPF_K] = &&ALU64_DIV_K,
[BPF_ALU64 | BPF_MOD | BPF_X] = &&ALU64_MOD_X,
[BPF_ALU64 | BPF_MOD | BPF_K] = &&ALU64_MOD_K,
[BPF_ALU64 | BPF_NEG] = &&ALU64_NEG,
[BPF_JMP | BPF_CALL] = &&JMP_CALL,
[BPF_JMP | BPF_JA] = &&JMP_JA,
[BPF_JMP | BPF_JEQ | BPF_X] = &&JMP_JEQ_X,
[BPF_JMP | BPF_JEQ | BPF_K] = &&JMP_JEQ_K,
[BPF_JMP | BPF_JNE | BPF_X] = &&JMP_JNE_X,
[BPF_JMP | BPF_JNE | BPF_K] = &&JMP_JNE_K,
[BPF_JMP | BPF_JGT | BPF_X] = &&JMP_JGT_X,
[BPF_JMP | BPF_JGT | BPF_K] = &&JMP_JGT_K,
[BPF_JMP | BPF_JGE | BPF_X] = &&JMP_JGE_X,
[BPF_JMP | BPF_JGE | BPF_K] = &&JMP_JGE_K,
[BPF_JMP | BPF_JSGT | BPF_X] = &&JMP_JSGT_X,
[BPF_JMP | BPF_JSGT | BPF_K] = &&JMP_JSGT_K,
[BPF_JMP | BPF_JSGE | BPF_X] = &&JMP_JSGE_X,
[BPF_JMP | BPF_JSGE | BPF_K] = &&JMP_JSGE_K,
[BPF_JMP | BPF_JSET | BPF_X] = &&JMP_JSET_X,
[BPF_JMP | BPF_JSET | BPF_K] = &&JMP_JSET_K,
[BPF_JMP | BPF_EXIT] = &&JMP_EXIT,
[BPF_STX | BPF_MEM | BPF_B] = &&STX_MEM_B,
[BPF_STX | BPF_MEM | BPF_H] = &&STX_MEM_H,
[BPF_STX | BPF_MEM | BPF_W] = &&STX_MEM_W,
[BPF_STX | BPF_MEM | BPF_DW] = &&STX_MEM_DW,
[BPF_STX | BPF_XADD | BPF_W] = &&STX_XADD_W,
[BPF_STX | BPF_XADD | BPF_DW] = &&STX_XADD_DW,
[BPF_ST | BPF_MEM | BPF_B] = &&ST_MEM_B,
[BPF_ST | BPF_MEM | BPF_H] = &&ST_MEM_H,
[BPF_ST | BPF_MEM | BPF_W] = &&ST_MEM_W,
[BPF_ST | BPF_MEM | BPF_DW] = &&ST_MEM_DW,
[BPF_LDX | BPF_MEM | BPF_B] = &&LDX_MEM_B,
[BPF_LDX | BPF_MEM | BPF_H] = &&LDX_MEM_H,
[BPF_LDX | BPF_MEM | BPF_W] = &&LDX_MEM_W,
[BPF_LDX | BPF_MEM | BPF_DW] = &&LDX_MEM_DW,
[BPF_LD | BPF_ABS | BPF_W] = &&LD_ABS_W,
[BPF_LD | BPF_ABS | BPF_H] = &&LD_ABS_H,
[BPF_LD | BPF_ABS | BPF_B] = &&LD_ABS_B,
[BPF_LD | BPF_IND | BPF_W] = &&LD_IND_W,
[BPF_LD | BPF_IND | BPF_H] = &&LD_IND_H,
[BPF_LD | BPF_IND | BPF_B] = &&LD_IND_B,
};
void *ptr;
int off;
#define CONT ({ insn++; goto select_insn; })
#define CONT_JMP ({ insn++; goto select_insn; })
FP = (u64) (unsigned long) &stack[ARRAY_SIZE(stack)];
ARG1 = (u64) (unsigned long) ctx;
regs[BPF_REG_A] = 0;
regs[BPF_REG_X] = 0;
select_insn:
goto *jumptable[insn->code];
#define ALU(OPCODE, OP) \
ALU64_##OPCODE##_X: \
DST = DST OP SRC; \
CONT; \
ALU_##OPCODE##_X: \
DST = (u32) DST OP (u32) SRC; \
CONT; \
ALU64_##OPCODE##_K: \
DST = DST OP IMM; \
CONT; \
ALU_##OPCODE##_K: \
DST = (u32) DST OP (u32) IMM; \
CONT;
ALU(ADD, +)
ALU(SUB, -)
ALU(AND, &)
ALU(OR, |)
ALU(LSH, <<)
ALU(RSH, >>)
ALU(XOR, ^)
ALU(MUL, *)
#undef ALU
ALU_NEG:
DST = (u32) -DST;
CONT;
ALU64_NEG:
DST = -DST;
CONT;
ALU_MOV_X:
DST = (u32) SRC;
CONT;
ALU_MOV_K:
DST = (u32) IMM;
CONT;
ALU64_MOV_X:
DST = SRC;
CONT;
ALU64_MOV_K:
DST = IMM;
CONT;
ALU64_ARSH_X:
(*(s64 *) &DST) >>= SRC;
CONT;
ALU64_ARSH_K:
(*(s64 *) &DST) >>= IMM;
CONT;
ALU64_MOD_X:
if (unlikely(SRC == 0))
return 0;
tmp = DST;
DST = do_div(tmp, SRC);
CONT;
ALU_MOD_X:
if (unlikely(SRC == 0))
return 0;
tmp = (u32) DST;
DST = do_div(tmp, (u32) SRC);
CONT;
ALU64_MOD_K:
tmp = DST;
DST = do_div(tmp, IMM);
CONT;
ALU_MOD_K:
tmp = (u32) DST;
DST = do_div(tmp, (u32) IMM);
CONT;
ALU64_DIV_X:
if (unlikely(SRC == 0))
return 0;
do_div(DST, SRC);
CONT;
ALU_DIV_X:
if (unlikely(SRC == 0))
return 0;
tmp = (u32) DST;
do_div(tmp, (u32) SRC);
DST = (u32) tmp;
CONT;
ALU64_DIV_K:
do_div(DST, IMM);
CONT;
ALU_DIV_K:
tmp = (u32) DST;
do_div(tmp, (u32) IMM);
DST = (u32) tmp;
CONT;
ALU_END_TO_BE:
switch (IMM) {
case 16:
DST = (__force u16) cpu_to_be16(DST);
break;
case 32:
DST = (__force u32) cpu_to_be32(DST);
break;
case 64:
DST = (__force u64) cpu_to_be64(DST);
break;
}
CONT;
ALU_END_TO_LE:
switch (IMM) {
case 16:
DST = (__force u16) cpu_to_le16(DST);
break;
case 32:
DST = (__force u32) cpu_to_le32(DST);
break;
case 64:
DST = (__force u64) cpu_to_le64(DST);
break;
}
CONT;
JMP_CALL:
BPF_R0 = (__bpf_call_base + insn->imm)(BPF_R1, BPF_R2, BPF_R3,
BPF_R4, BPF_R5);
CONT;
JMP_JA:
insn += insn->off;
CONT;
JMP_JEQ_X:
if (DST == SRC) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JEQ_K:
if (DST == IMM) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JNE_X:
if (DST != SRC) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JNE_K:
if (DST != IMM) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JGT_X:
if (DST > SRC) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JGT_K:
if (DST > IMM) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JGE_X:
if (DST >= SRC) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JGE_K:
if (DST >= IMM) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JSGT_X:
if (((s64) DST) > ((s64) SRC)) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JSGT_K:
if (((s64) DST) > ((s64) IMM)) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JSGE_X:
if (((s64) DST) >= ((s64) SRC)) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JSGE_K:
if (((s64) DST) >= ((s64) IMM)) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JSET_X:
if (DST & SRC) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_JSET_K:
if (DST & IMM) {
insn += insn->off;
CONT_JMP;
}
CONT;
JMP_EXIT:
return BPF_R0;
#define LDST(SIZEOP, SIZE) \
STX_MEM_##SIZEOP: \
*(SIZE *)(unsigned long) (DST + insn->off) = SRC; \
CONT; \
ST_MEM_##SIZEOP: \
*(SIZE *)(unsigned long) (DST + insn->off) = IMM; \
CONT; \
LDX_MEM_##SIZEOP: \
DST = *(SIZE *)(unsigned long) (SRC + insn->off); \
CONT;
LDST(B, u8)
LDST(H, u16)
LDST(W, u32)
LDST(DW, u64)
#undef LDST
STX_XADD_W:
atomic_add((u32) SRC, (atomic_t *)(unsigned long)
(DST + insn->off));
CONT;
STX_XADD_DW:
atomic64_add((u64) SRC, (atomic64_t *)(unsigned long)
(DST + insn->off));
CONT;
LD_ABS_W:
off = IMM;
load_word:
ptr = load_pointer((struct sk_buff *) (unsigned long) CTX, off, 4, &tmp);
if (likely(ptr != NULL)) {
BPF_R0 = get_unaligned_be32(ptr);
CONT;
}
return 0;
LD_ABS_H:
off = IMM;
load_half:
ptr = load_pointer((struct sk_buff *) (unsigned long) CTX, off, 2, &tmp);
if (likely(ptr != NULL)) {
BPF_R0 = get_unaligned_be16(ptr);
CONT;
}
return 0;
LD_ABS_B:
off = IMM;
load_byte:
ptr = load_pointer((struct sk_buff *) (unsigned long) CTX, off, 1, &tmp);
if (likely(ptr != NULL)) {
BPF_R0 = *(u8 *)ptr;
CONT;
}
return 0;
LD_IND_W:
off = IMM + SRC;
goto load_word;
LD_IND_H:
off = IMM + SRC;
goto load_half;
LD_IND_B:
off = IMM + SRC;
goto load_byte;
default_label:
WARN_RATELIMIT(1, "unknown opcode %02x\n", insn->code);
return 0;
}
static unsigned int pkt_type_offset(void)
{
struct sk_buff skb_probe = { .pkt_type = ~0, };
u8 *ct = (u8 *) &skb_probe;
unsigned int off;
for (off = 0; off < sizeof(struct sk_buff); off++) {
if (ct[off] == PKT_TYPE_MAX)
return off;
}
pr_err_once("Please fix %s, as pkt_type couldn't be found!\n", __func__);
return -1;
}
static u64 __skb_get_pay_offset(u64 ctx, u64 a, u64 x, u64 r4, u64 r5)
{
return __skb_get_poff((struct sk_buff *)(unsigned long) ctx);
}
static u64 __skb_get_nlattr(u64 ctx, u64 a, u64 x, u64 r4, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *)(unsigned long) ctx;
struct nlattr *nla;
if (skb_is_nonlinear(skb))
return 0;
if (skb->len < sizeof(struct nlattr))
return 0;
if (a > skb->len - sizeof(struct nlattr))
return 0;
nla = nla_find((struct nlattr *) &skb->data[a], skb->len - a, x);
if (nla)
return (void *) nla - (void *) skb->data;
return 0;
}
static u64 __skb_get_nlattr_nest(u64 ctx, u64 a, u64 x, u64 r4, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *)(unsigned long) ctx;
struct nlattr *nla;
if (skb_is_nonlinear(skb))
return 0;
if (skb->len < sizeof(struct nlattr))
return 0;
if (a > skb->len - sizeof(struct nlattr))
return 0;
nla = (struct nlattr *) &skb->data[a];
if (nla->nla_len > skb->len - a)
return 0;
nla = nla_find_nested(nla, x);
if (nla)
return (void *) nla - (void *) skb->data;
return 0;
}
static u64 __get_raw_cpu_id(u64 ctx, u64 a, u64 x, u64 r4, u64 r5)
{
return raw_smp_processor_id();
}
static u64 __get_random_u32(u64 ctx, u64 a, u64 x, u64 r4, u64 r5)
{
return prandom_u32();
}
static bool convert_bpf_extensions(struct sock_filter *fp,
struct sock_filter_int **insnp)
{
struct sock_filter_int *insn = *insnp;
switch (fp->k) {
case SKF_AD_OFF + SKF_AD_PROTOCOL:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, protocol) != 2);
*insn++ = BPF_LDX_MEM(BPF_H, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, protocol));
*insn = BPF_ENDIAN(BPF_FROM_BE, BPF_REG_A, 16);
break;
case SKF_AD_OFF + SKF_AD_PKTTYPE:
*insn = BPF_LDX_MEM(BPF_B, BPF_REG_A, BPF_REG_CTX,
pkt_type_offset());
if (insn->off < 0)
return false;
insn++;
*insn = BPF_ALU32_IMM(BPF_AND, BPF_REG_A, PKT_TYPE_MAX);
#ifdef __BIG_ENDIAN_BITFIELD
insn++;
*insn = BPF_ALU32_IMM(BPF_RSH, BPF_REG_A, 5);
#endif
break;
case SKF_AD_OFF + SKF_AD_IFINDEX:
case SKF_AD_OFF + SKF_AD_HATYPE:
BUILD_BUG_ON(FIELD_SIZEOF(struct net_device, ifindex) != 4);
BUILD_BUG_ON(FIELD_SIZEOF(struct net_device, type) != 2);
BUILD_BUG_ON(bytes_to_bpf_size(FIELD_SIZEOF(struct sk_buff, dev)) < 0);
*insn++ = BPF_LDX_MEM(bytes_to_bpf_size(FIELD_SIZEOF(struct sk_buff, dev)),
BPF_REG_TMP, BPF_REG_CTX,
offsetof(struct sk_buff, dev));
*insn++ = BPF_JMP_IMM(BPF_JNE, BPF_REG_TMP, 0, 1);
*insn++ = BPF_EXIT_INSN();
if (fp->k == SKF_AD_OFF + SKF_AD_IFINDEX)
*insn = BPF_LDX_MEM(BPF_W, BPF_REG_A, BPF_REG_TMP,
offsetof(struct net_device, ifindex));
else
*insn = BPF_LDX_MEM(BPF_H, BPF_REG_A, BPF_REG_TMP,
offsetof(struct net_device, type));
break;
case SKF_AD_OFF + SKF_AD_MARK:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, mark) != 4);
*insn = BPF_LDX_MEM(BPF_W, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, mark));
break;
case SKF_AD_OFF + SKF_AD_RXHASH:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, hash) != 4);
*insn = BPF_LDX_MEM(BPF_W, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, hash));
break;
case SKF_AD_OFF + SKF_AD_QUEUE:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, queue_mapping) != 2);
*insn = BPF_LDX_MEM(BPF_H, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, queue_mapping));
break;
case SKF_AD_OFF + SKF_AD_VLAN_TAG:
case SKF_AD_OFF + SKF_AD_VLAN_TAG_PRESENT:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, vlan_tci) != 2);
BUILD_BUG_ON(VLAN_TAG_PRESENT != 0x1000);
*insn++ = BPF_LDX_MEM(BPF_H, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, vlan_tci));
if (fp->k == SKF_AD_OFF + SKF_AD_VLAN_TAG) {
*insn = BPF_ALU32_IMM(BPF_AND, BPF_REG_A,
~VLAN_TAG_PRESENT);
} else {
*insn++ = BPF_ALU32_IMM(BPF_RSH, BPF_REG_A, 12);
*insn = BPF_ALU32_IMM(BPF_AND, BPF_REG_A, 1);
}
break;
case SKF_AD_OFF + SKF_AD_PAY_OFFSET:
case SKF_AD_OFF + SKF_AD_NLATTR:
case SKF_AD_OFF + SKF_AD_NLATTR_NEST:
case SKF_AD_OFF + SKF_AD_CPU:
case SKF_AD_OFF + SKF_AD_RANDOM:
*insn++ = BPF_MOV64_REG(BPF_REG_ARG1, BPF_REG_CTX);
*insn++ = BPF_MOV64_REG(BPF_REG_ARG2, BPF_REG_A);
*insn++ = BPF_MOV64_REG(BPF_REG_ARG3, BPF_REG_X);
switch (fp->k) {
case SKF_AD_OFF + SKF_AD_PAY_OFFSET:
*insn = BPF_EMIT_CALL(__skb_get_pay_offset);
break;
case SKF_AD_OFF + SKF_AD_NLATTR:
*insn = BPF_EMIT_CALL(__skb_get_nlattr);
break;
case SKF_AD_OFF + SKF_AD_NLATTR_NEST:
*insn = BPF_EMIT_CALL(__skb_get_nlattr_nest);
break;
case SKF_AD_OFF + SKF_AD_CPU:
*insn = BPF_EMIT_CALL(__get_raw_cpu_id);
break;
case SKF_AD_OFF + SKF_AD_RANDOM:
*insn = BPF_EMIT_CALL(__get_random_u32);
break;
}
break;
case SKF_AD_OFF + SKF_AD_ALU_XOR_X:
*insn = BPF_ALU32_REG(BPF_XOR, BPF_REG_A, BPF_REG_X);
break;
default:
BUG_ON(__bpf_call_base(0, 0, 0, 0, 0) != 0);
return false;
}
*insnp = insn;
return true;
}
int sk_convert_filter(struct sock_filter *prog, int len,
struct sock_filter_int *new_prog, int *new_len)
{
int new_flen = 0, pass = 0, target, i;
struct sock_filter_int *new_insn;
struct sock_filter *fp;
int *addrs = NULL;
u8 bpf_src;
BUILD_BUG_ON(BPF_MEMWORDS * sizeof(u32) > MAX_BPF_STACK);
BUILD_BUG_ON(BPF_REG_FP + 1 != MAX_BPF_REG);
if (len <= 0 || len > BPF_MAXINSNS)
return -EINVAL;
if (new_prog) {
addrs = kcalloc(len, sizeof(*addrs), GFP_KERNEL);
if (!addrs)
return -ENOMEM;
}
do_pass:
new_insn = new_prog;
fp = prog;
if (new_insn)
*new_insn = BPF_MOV64_REG(BPF_REG_CTX, BPF_REG_ARG1);
new_insn++;
for (i = 0; i < len; fp++, i++) {
struct sock_filter_int tmp_insns[6] = { };
struct sock_filter_int *insn = tmp_insns;
if (addrs)
addrs[i] = new_insn - new_prog;
switch (fp->code) {
case BPF_ALU | BPF_ADD | BPF_X:
case BPF_ALU | BPF_ADD | BPF_K:
case BPF_ALU | BPF_SUB | BPF_X:
case BPF_ALU | BPF_SUB | BPF_K:
case BPF_ALU | BPF_AND | BPF_X:
case BPF_ALU | BPF_AND | BPF_K:
case BPF_ALU | BPF_OR | BPF_X:
case BPF_ALU | BPF_OR | BPF_K:
case BPF_ALU | BPF_LSH | BPF_X:
case BPF_ALU | BPF_LSH | BPF_K:
case BPF_ALU | BPF_RSH | BPF_X:
case BPF_ALU | BPF_RSH | BPF_K:
case BPF_ALU | BPF_XOR | BPF_X:
case BPF_ALU | BPF_XOR | BPF_K:
case BPF_ALU | BPF_MUL | BPF_X:
case BPF_ALU | BPF_MUL | BPF_K:
case BPF_ALU | BPF_DIV | BPF_X:
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU | BPF_MOD | BPF_X:
case BPF_ALU | BPF_MOD | BPF_K:
case BPF_ALU | BPF_NEG:
case BPF_LD | BPF_ABS | BPF_W:
case BPF_LD | BPF_ABS | BPF_H:
case BPF_LD | BPF_ABS | BPF_B:
case BPF_LD | BPF_IND | BPF_W:
case BPF_LD | BPF_IND | BPF_H:
case BPF_LD | BPF_IND | BPF_B:
if (BPF_CLASS(fp->code) == BPF_LD &&
BPF_MODE(fp->code) == BPF_ABS &&
convert_bpf_extensions(fp, &insn))
break;
*insn = BPF_RAW_INSN(fp->code, BPF_REG_A, BPF_REG_X, 0, fp->k);
break;
#define BPF_EMIT_JMP \
do { \
if (target >= len || target < 0) \
goto err; \
insn->off = addrs ? addrs[target] - addrs[i] - 1 : 0; \
\
insn->off -= insn - tmp_insns; \
} while (0)
case BPF_JMP | BPF_JA:
target = i + fp->k + 1;
insn->code = fp->code;
BPF_EMIT_JMP;
break;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JSET | BPF_K:
case BPF_JMP | BPF_JSET | BPF_X:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JGE | BPF_X:
if (BPF_SRC(fp->code) == BPF_K && (int) fp->k < 0) {
*insn++ = BPF_MOV32_IMM(BPF_REG_TMP, fp->k);
insn->dst_reg = BPF_REG_A;
insn->src_reg = BPF_REG_TMP;
bpf_src = BPF_X;
} else {
insn->dst_reg = BPF_REG_A;
insn->src_reg = BPF_REG_X;
insn->imm = fp->k;
bpf_src = BPF_SRC(fp->code);
}
if (fp->jf == 0) {
insn->code = BPF_JMP | BPF_OP(fp->code) | bpf_src;
target = i + fp->jt + 1;
BPF_EMIT_JMP;
break;
}
if (fp->jt == 0 && BPF_OP(fp->code) == BPF_JEQ) {
insn->code = BPF_JMP | BPF_JNE | bpf_src;
target = i + fp->jf + 1;
BPF_EMIT_JMP;
break;
}
target = i + fp->jt + 1;
insn->code = BPF_JMP | BPF_OP(fp->code) | bpf_src;
BPF_EMIT_JMP;
insn++;
insn->code = BPF_JMP | BPF_JA;
target = i + fp->jf + 1;
BPF_EMIT_JMP;
break;
case BPF_LDX | BPF_MSH | BPF_B:
*insn++ = BPF_MOV64_REG(BPF_REG_TMP, BPF_REG_A);
*insn++ = BPF_LD_ABS(BPF_B, fp->k);
*insn++ = BPF_ALU32_IMM(BPF_AND, BPF_REG_A, 0xf);
*insn++ = BPF_ALU32_IMM(BPF_LSH, BPF_REG_A, 2);
*insn++ = BPF_MOV64_REG(BPF_REG_X, BPF_REG_A);
*insn = BPF_MOV64_REG(BPF_REG_A, BPF_REG_TMP);
break;
case BPF_RET | BPF_A:
case BPF_RET | BPF_K:
*insn++ = BPF_MOV32_RAW(BPF_RVAL(fp->code) == BPF_K ?
BPF_K : BPF_X, BPF_REG_0,
BPF_REG_A, fp->k);
*insn = BPF_EXIT_INSN();
break;
case BPF_ST:
case BPF_STX:
*insn = BPF_STX_MEM(BPF_W, BPF_REG_FP, BPF_CLASS(fp->code) ==
BPF_ST ? BPF_REG_A : BPF_REG_X,
-(BPF_MEMWORDS - fp->k) * 4);
break;
case BPF_LD | BPF_MEM:
case BPF_LDX | BPF_MEM:
*insn = BPF_LDX_MEM(BPF_W, BPF_CLASS(fp->code) == BPF_LD ?
BPF_REG_A : BPF_REG_X, BPF_REG_FP,
-(BPF_MEMWORDS - fp->k) * 4);
break;
case BPF_LD | BPF_IMM:
case BPF_LDX | BPF_IMM:
*insn = BPF_MOV32_IMM(BPF_CLASS(fp->code) == BPF_LD ?
BPF_REG_A : BPF_REG_X, fp->k);
break;
case BPF_MISC | BPF_TAX:
*insn = BPF_MOV64_REG(BPF_REG_X, BPF_REG_A);
break;
case BPF_MISC | BPF_TXA:
*insn = BPF_MOV64_REG(BPF_REG_A, BPF_REG_X);
break;
case BPF_LD | BPF_W | BPF_LEN:
case BPF_LDX | BPF_W | BPF_LEN:
*insn = BPF_LDX_MEM(BPF_W, BPF_CLASS(fp->code) == BPF_LD ?
BPF_REG_A : BPF_REG_X, BPF_REG_CTX,
offsetof(struct sk_buff, len));
break;
case BPF_LDX | BPF_ABS | BPF_W:
*insn = BPF_LDX_MEM(BPF_W, BPF_REG_A, BPF_REG_CTX, fp->k);
break;
default:
goto err;
}
insn++;
if (new_prog)
memcpy(new_insn, tmp_insns,
sizeof(*insn) * (insn - tmp_insns));
new_insn += insn - tmp_insns;
}
if (!new_prog) {
*new_len = new_insn - new_prog;
return 0;
}
pass++;
if (new_flen != new_insn - new_prog) {
new_flen = new_insn - new_prog;
if (pass > 2)
goto err;
goto do_pass;
}
kfree(addrs);
BUG_ON(*new_len != new_flen);
return 0;
err:
kfree(addrs);
return -EINVAL;
}
static int check_load_and_stores(struct sock_filter *filter, int flen)
{
u16 *masks, memvalid = 0;
int pc, ret = 0;
BUILD_BUG_ON(BPF_MEMWORDS > 16);
masks = kmalloc_array(flen, sizeof(*masks), GFP_KERNEL);
if (!masks)
return -ENOMEM;
memset(masks, 0xff, flen * sizeof(*masks));
for (pc = 0; pc < flen; pc++) {
memvalid &= masks[pc];
switch (filter[pc].code) {
case BPF_ST:
case BPF_STX:
memvalid |= (1 << filter[pc].k);
break;
case BPF_LD | BPF_MEM:
case BPF_LDX | BPF_MEM:
if (!(memvalid & (1 << filter[pc].k))) {
ret = -EINVAL;
goto error;
}
break;
case BPF_JMP | BPF_JA:
masks[pc + 1 + filter[pc].k] &= memvalid;
memvalid = ~0;
break;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JSET | BPF_K:
case BPF_JMP | BPF_JSET | BPF_X:
masks[pc + 1 + filter[pc].jt] &= memvalid;
masks[pc + 1 + filter[pc].jf] &= memvalid;
memvalid = ~0;
break;
}
}
error:
kfree(masks);
return ret;
}
static bool chk_code_allowed(u16 code_to_probe)
{
static const bool codes[] = {
[BPF_ALU | BPF_ADD | BPF_K] = true,
[BPF_ALU | BPF_ADD | BPF_X] = true,
[BPF_ALU | BPF_SUB | BPF_K] = true,
[BPF_ALU | BPF_SUB | BPF_X] = true,
[BPF_ALU | BPF_MUL | BPF_K] = true,
[BPF_ALU | BPF_MUL | BPF_X] = true,
[BPF_ALU | BPF_DIV | BPF_K] = true,
[BPF_ALU | BPF_DIV | BPF_X] = true,
[BPF_ALU | BPF_MOD | BPF_K] = true,
[BPF_ALU | BPF_MOD | BPF_X] = true,
[BPF_ALU | BPF_AND | BPF_K] = true,
[BPF_ALU | BPF_AND | BPF_X] = true,
[BPF_ALU | BPF_OR | BPF_K] = true,
[BPF_ALU | BPF_OR | BPF_X] = true,
[BPF_ALU | BPF_XOR | BPF_K] = true,
[BPF_ALU | BPF_XOR | BPF_X] = true,
[BPF_ALU | BPF_LSH | BPF_K] = true,
[BPF_ALU | BPF_LSH | BPF_X] = true,
[BPF_ALU | BPF_RSH | BPF_K] = true,
[BPF_ALU | BPF_RSH | BPF_X] = true,
[BPF_ALU | BPF_NEG] = true,
[BPF_LD | BPF_W | BPF_ABS] = true,
[BPF_LD | BPF_H | BPF_ABS] = true,
[BPF_LD | BPF_B | BPF_ABS] = true,
[BPF_LD | BPF_W | BPF_LEN] = true,
[BPF_LD | BPF_W | BPF_IND] = true,
[BPF_LD | BPF_H | BPF_IND] = true,
[BPF_LD | BPF_B | BPF_IND] = true,
[BPF_LD | BPF_IMM] = true,
[BPF_LD | BPF_MEM] = true,
[BPF_LDX | BPF_W | BPF_LEN] = true,
[BPF_LDX | BPF_B | BPF_MSH] = true,
[BPF_LDX | BPF_IMM] = true,
[BPF_LDX | BPF_MEM] = true,
[BPF_ST] = true,
[BPF_STX] = true,
[BPF_MISC | BPF_TAX] = true,
[BPF_MISC | BPF_TXA] = true,
[BPF_RET | BPF_K] = true,
[BPF_RET | BPF_A] = true,
[BPF_JMP | BPF_JA] = true,
[BPF_JMP | BPF_JEQ | BPF_K] = true,
[BPF_JMP | BPF_JEQ | BPF_X] = true,
[BPF_JMP | BPF_JGE | BPF_K] = true,
[BPF_JMP | BPF_JGE | BPF_X] = true,
[BPF_JMP | BPF_JGT | BPF_K] = true,
[BPF_JMP | BPF_JGT | BPF_X] = true,
[BPF_JMP | BPF_JSET | BPF_K] = true,
[BPF_JMP | BPF_JSET | BPF_X] = true,
};
if (code_to_probe >= ARRAY_SIZE(codes))
return false;
return codes[code_to_probe];
}
int sk_chk_filter(struct sock_filter *filter, unsigned int flen)
{
bool anc_found;
int pc;
if (flen == 0 || flen > BPF_MAXINSNS)
return -EINVAL;
for (pc = 0; pc < flen; pc++) {
struct sock_filter *ftest = &filter[pc];
if (!chk_code_allowed(ftest->code))
return -EINVAL;
switch (ftest->code) {
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU | BPF_MOD | BPF_K:
if (ftest->k == 0)
return -EINVAL;
break;
case BPF_LD | BPF_MEM:
case BPF_LDX | BPF_MEM:
case BPF_ST:
case BPF_STX:
if (ftest->k >= BPF_MEMWORDS)
return -EINVAL;
break;
case BPF_JMP | BPF_JA:
if (ftest->k >= (unsigned int)(flen - pc - 1))
return -EINVAL;
break;
case BPF_JMP | BPF_JEQ | BPF_K:
case BPF_JMP | BPF_JEQ | BPF_X:
case BPF_JMP | BPF_JGE | BPF_K:
case BPF_JMP | BPF_JGE | BPF_X:
case BPF_JMP | BPF_JGT | BPF_K:
case BPF_JMP | BPF_JGT | BPF_X:
case BPF_JMP | BPF_JSET | BPF_K:
case BPF_JMP | BPF_JSET | BPF_X:
if (pc + ftest->jt + 1 >= flen ||
pc + ftest->jf + 1 >= flen)
return -EINVAL;
break;
case BPF_LD | BPF_W | BPF_ABS:
case BPF_LD | BPF_H | BPF_ABS:
case BPF_LD | BPF_B | BPF_ABS:
anc_found = false;
if (bpf_anc_helper(ftest) & BPF_ANC)
anc_found = true;
if (anc_found == false && ftest->k >= SKF_AD_OFF)
return -EINVAL;
}
}
switch (filter[flen - 1].code) {
case BPF_RET | BPF_K:
case BPF_RET | BPF_A:
return check_load_and_stores(filter, flen);
}
return -EINVAL;
}
static int sk_store_orig_filter(struct sk_filter *fp,
const struct sock_fprog *fprog)
{
unsigned int fsize = sk_filter_proglen(fprog);
struct sock_fprog_kern *fkprog;
fp->orig_prog = kmalloc(sizeof(*fkprog), GFP_KERNEL);
if (!fp->orig_prog)
return -ENOMEM;
fkprog = fp->orig_prog;
fkprog->len = fprog->len;
fkprog->filter = kmemdup(fp->insns, fsize, GFP_KERNEL);
if (!fkprog->filter) {
kfree(fp->orig_prog);
return -ENOMEM;
}
return 0;
}
static void sk_release_orig_filter(struct sk_filter *fp)
{
struct sock_fprog_kern *fprog = fp->orig_prog;
if (fprog) {
kfree(fprog->filter);
kfree(fprog);
}
}
static void sk_filter_release_rcu(struct rcu_head *rcu)
{
struct sk_filter *fp = container_of(rcu, struct sk_filter, rcu);
sk_release_orig_filter(fp);
sk_filter_free(fp);
}
static void sk_filter_release(struct sk_filter *fp)
{
if (atomic_dec_and_test(&fp->refcnt))
call_rcu(&fp->rcu, sk_filter_release_rcu);
}
void sk_filter_uncharge(struct sock *sk, struct sk_filter *fp)
{
atomic_sub(sk_filter_size(fp->len), &sk->sk_omem_alloc);
sk_filter_release(fp);
}
void sk_filter_charge(struct sock *sk, struct sk_filter *fp)
{
atomic_inc(&fp->refcnt);
atomic_add(sk_filter_size(fp->len), &sk->sk_omem_alloc);
}
static struct sk_filter *__sk_migrate_realloc(struct sk_filter *fp,
struct sock *sk,
unsigned int len)
{
struct sk_filter *fp_new;
if (sk == NULL)
return krealloc(fp, len, GFP_KERNEL);
fp_new = sock_kmalloc(sk, len, GFP_KERNEL);
if (fp_new) {
*fp_new = *fp;
fp->orig_prog = NULL;
sk_filter_uncharge(sk, fp);
}
return fp_new;
}
static struct sk_filter *__sk_migrate_filter(struct sk_filter *fp,
struct sock *sk)
{
struct sock_filter *old_prog;
struct sk_filter *old_fp;
int err, new_len, old_len = fp->len;
BUILD_BUG_ON(sizeof(struct sock_filter) !=
sizeof(struct sock_filter_int));
old_prog = kmemdup(fp->insns, old_len * sizeof(struct sock_filter),
GFP_KERNEL);
if (!old_prog) {
err = -ENOMEM;
goto out_err;
}
err = sk_convert_filter(old_prog, old_len, NULL, &new_len);
if (err)
goto out_err_free;
old_fp = fp;
fp = __sk_migrate_realloc(old_fp, sk, sk_filter_size(new_len));
if (!fp) {
fp = old_fp;
err = -ENOMEM;
goto out_err_free;
}
fp->len = new_len;
err = sk_convert_filter(old_prog, old_len, fp->insnsi, &new_len);
if (err)
goto out_err_free;
sk_filter_select_runtime(fp);
kfree(old_prog);
return fp;
out_err_free:
kfree(old_prog);
out_err:
if (sk != NULL)
sk_filter_uncharge(sk, fp);
else
kfree(fp);
return ERR_PTR(err);
}
void __weak bpf_int_jit_compile(struct sk_filter *prog)
{
}
void sk_filter_select_runtime(struct sk_filter *fp)
{
fp->bpf_func = (void *) __sk_run_filter;
bpf_int_jit_compile(fp);
}
void sk_filter_free(struct sk_filter *fp)
{
bpf_jit_free(fp);
}
static struct sk_filter *__sk_prepare_filter(struct sk_filter *fp,
struct sock *sk)
{
int err;
fp->bpf_func = NULL;
fp->jited = 0;
err = sk_chk_filter(fp->insns, fp->len);
if (err) {
if (sk != NULL)
sk_filter_uncharge(sk, fp);
else
kfree(fp);
return ERR_PTR(err);
}
bpf_jit_compile(fp);
if (!fp->jited)
fp = __sk_migrate_filter(fp, sk);
return fp;
}
int sk_unattached_filter_create(struct sk_filter **pfp,
struct sock_fprog_kern *fprog)
{
unsigned int fsize = sk_filter_proglen(fprog);
struct sk_filter *fp;
if (fprog->filter == NULL)
return -EINVAL;
fp = kmalloc(sk_filter_size(fprog->len), GFP_KERNEL);
if (!fp)
return -ENOMEM;
memcpy(fp->insns, fprog->filter, fsize);
atomic_set(&fp->refcnt, 1);
fp->len = fprog->len;
fp->orig_prog = NULL;
fp = __sk_prepare_filter(fp, NULL);
if (IS_ERR(fp))
return PTR_ERR(fp);
*pfp = fp;
return 0;
}
void sk_unattached_filter_destroy(struct sk_filter *fp)
{
sk_filter_release(fp);
}
int sk_attach_filter(struct sock_fprog *fprog, struct sock *sk)
{
struct sk_filter *fp, *old_fp;
unsigned int fsize = sk_filter_proglen(fprog);
unsigned int sk_fsize = sk_filter_size(fprog->len);
int err;
if (sock_flag(sk, SOCK_FILTER_LOCKED))
return -EPERM;
if (fprog->filter == NULL)
return -EINVAL;
fp = sock_kmalloc(sk, sk_fsize, GFP_KERNEL);
if (!fp)
return -ENOMEM;
if (copy_from_user(fp->insns, fprog->filter, fsize)) {
sock_kfree_s(sk, fp, sk_fsize);
return -EFAULT;
}
atomic_set(&fp->refcnt, 1);
fp->len = fprog->len;
err = sk_store_orig_filter(fp, fprog);
if (err) {
sk_filter_uncharge(sk, fp);
return -ENOMEM;
}
fp = __sk_prepare_filter(fp, sk);
if (IS_ERR(fp))
return PTR_ERR(fp);
old_fp = rcu_dereference_protected(sk->sk_filter,
sock_owned_by_user(sk));
rcu_assign_pointer(sk->sk_filter, fp);
if (old_fp)
sk_filter_uncharge(sk, old_fp);
return 0;
}
int sk_detach_filter(struct sock *sk)
{
int ret = -ENOENT;
struct sk_filter *filter;
if (sock_flag(sk, SOCK_FILTER_LOCKED))
return -EPERM;
filter = rcu_dereference_protected(sk->sk_filter,
sock_owned_by_user(sk));
if (filter) {
RCU_INIT_POINTER(sk->sk_filter, NULL);
sk_filter_uncharge(sk, filter);
ret = 0;
}
return ret;
}
int sk_get_filter(struct sock *sk, struct sock_filter __user *ubuf,
unsigned int len)
{
struct sock_fprog_kern *fprog;
struct sk_filter *filter;
int ret = 0;
lock_sock(sk);
filter = rcu_dereference_protected(sk->sk_filter,
sock_owned_by_user(sk));
if (!filter)
goto out;
fprog = filter->orig_prog;
ret = fprog->len;
if (!len)
goto out;
ret = -EINVAL;
if (len < fprog->len)
goto out;
ret = -EFAULT;
if (copy_to_user(ubuf, fprog->filter, sk_filter_proglen(fprog)))
goto out;
ret = fprog->len;
out:
release_sock(sk);
return ret;
}
