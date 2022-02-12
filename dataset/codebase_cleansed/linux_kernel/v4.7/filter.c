int sk_filter_trim_cap(struct sock *sk, struct sk_buff *skb, unsigned int cap)
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
unsigned int pkt_len = bpf_prog_run_save_cb(filter->prog, skb);
err = pkt_len ? pskb_trim(skb, max(cap, pkt_len)) : -EPERM;
}
rcu_read_unlock();
return err;
}
static u64 __skb_get_pay_offset(u64 ctx, u64 a, u64 x, u64 r4, u64 r5)
{
return skb_get_poff((struct sk_buff *)(unsigned long) ctx);
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
static u32 convert_skb_access(int skb_field, int dst_reg, int src_reg,
struct bpf_insn *insn_buf)
{
struct bpf_insn *insn = insn_buf;
switch (skb_field) {
case SKF_AD_MARK:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, mark) != 4);
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, mark));
break;
case SKF_AD_PKTTYPE:
*insn++ = BPF_LDX_MEM(BPF_B, dst_reg, src_reg, PKT_TYPE_OFFSET());
*insn++ = BPF_ALU32_IMM(BPF_AND, dst_reg, PKT_TYPE_MAX);
#ifdef __BIG_ENDIAN_BITFIELD
*insn++ = BPF_ALU32_IMM(BPF_RSH, dst_reg, 5);
#endif
break;
case SKF_AD_QUEUE:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, queue_mapping) != 2);
*insn++ = BPF_LDX_MEM(BPF_H, dst_reg, src_reg,
offsetof(struct sk_buff, queue_mapping));
break;
case SKF_AD_VLAN_TAG:
case SKF_AD_VLAN_TAG_PRESENT:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, vlan_tci) != 2);
BUILD_BUG_ON(VLAN_TAG_PRESENT != 0x1000);
*insn++ = BPF_LDX_MEM(BPF_H, dst_reg, src_reg,
offsetof(struct sk_buff, vlan_tci));
if (skb_field == SKF_AD_VLAN_TAG) {
*insn++ = BPF_ALU32_IMM(BPF_AND, dst_reg,
~VLAN_TAG_PRESENT);
} else {
*insn++ = BPF_ALU32_IMM(BPF_RSH, dst_reg, 12);
*insn++ = BPF_ALU32_IMM(BPF_AND, dst_reg, 1);
}
break;
}
return insn - insn_buf;
}
static bool convert_bpf_extensions(struct sock_filter *fp,
struct bpf_insn **insnp)
{
struct bpf_insn *insn = *insnp;
u32 cnt;
switch (fp->k) {
case SKF_AD_OFF + SKF_AD_PROTOCOL:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, protocol) != 2);
*insn++ = BPF_LDX_MEM(BPF_H, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, protocol));
*insn = BPF_ENDIAN(BPF_FROM_BE, BPF_REG_A, 16);
break;
case SKF_AD_OFF + SKF_AD_PKTTYPE:
cnt = convert_skb_access(SKF_AD_PKTTYPE, BPF_REG_A, BPF_REG_CTX, insn);
insn += cnt - 1;
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
cnt = convert_skb_access(SKF_AD_MARK, BPF_REG_A, BPF_REG_CTX, insn);
insn += cnt - 1;
break;
case SKF_AD_OFF + SKF_AD_RXHASH:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, hash) != 4);
*insn = BPF_LDX_MEM(BPF_W, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, hash));
break;
case SKF_AD_OFF + SKF_AD_QUEUE:
cnt = convert_skb_access(SKF_AD_QUEUE, BPF_REG_A, BPF_REG_CTX, insn);
insn += cnt - 1;
break;
case SKF_AD_OFF + SKF_AD_VLAN_TAG:
cnt = convert_skb_access(SKF_AD_VLAN_TAG,
BPF_REG_A, BPF_REG_CTX, insn);
insn += cnt - 1;
break;
case SKF_AD_OFF + SKF_AD_VLAN_TAG_PRESENT:
cnt = convert_skb_access(SKF_AD_VLAN_TAG_PRESENT,
BPF_REG_A, BPF_REG_CTX, insn);
insn += cnt - 1;
break;
case SKF_AD_OFF + SKF_AD_VLAN_TPID:
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, vlan_proto) != 2);
*insn++ = BPF_LDX_MEM(BPF_H, BPF_REG_A, BPF_REG_CTX,
offsetof(struct sk_buff, vlan_proto));
*insn = BPF_ENDIAN(BPF_FROM_BE, BPF_REG_A, 16);
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
*insn = BPF_EMIT_CALL(bpf_user_rnd_u32);
bpf_user_rnd_init_once();
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
static int bpf_convert_filter(struct sock_filter *prog, int len,
struct bpf_insn *new_prog, int *new_len)
{
int new_flen = 0, pass = 0, target, i;
struct bpf_insn *new_insn;
struct sock_filter *fp;
int *addrs = NULL;
u8 bpf_src;
BUILD_BUG_ON(BPF_MEMWORDS * sizeof(u32) > MAX_BPF_STACK);
BUILD_BUG_ON(BPF_REG_FP + 1 != MAX_BPF_REG);
if (len <= 0 || len > BPF_MAXINSNS)
return -EINVAL;
if (new_prog) {
addrs = kcalloc(len, sizeof(*addrs),
GFP_KERNEL | __GFP_NOWARN);
if (!addrs)
return -ENOMEM;
}
do_pass:
new_insn = new_prog;
fp = prog;
if (new_insn) {
*new_insn++ = BPF_ALU64_REG(BPF_XOR, BPF_REG_A, BPF_REG_A);
*new_insn++ = BPF_ALU64_REG(BPF_XOR, BPF_REG_X, BPF_REG_X);
*new_insn++ = BPF_MOV64_REG(BPF_REG_CTX, BPF_REG_ARG1);
} else {
new_insn += 3;
}
for (i = 0; i < len; fp++, i++) {
struct bpf_insn tmp_insns[6] = { };
struct bpf_insn *insn = tmp_insns;
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
insn->imm = fp->k;
bpf_src = BPF_SRC(fp->code);
insn->src_reg = bpf_src == BPF_X ? BPF_REG_X : 0;
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
if (BPF_RVAL(fp->code) == BPF_K)
*insn++ = BPF_MOV32_RAW(BPF_K, BPF_REG_0,
0, fp->k);
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
static int check_load_and_stores(const struct sock_filter *filter, int flen)
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
static int bpf_check_classic(const struct sock_filter *filter,
unsigned int flen)
{
bool anc_found;
int pc;
if (flen == 0 || flen > BPF_MAXINSNS)
return -EINVAL;
for (pc = 0; pc < flen; pc++) {
const struct sock_filter *ftest = &filter[pc];
if (!chk_code_allowed(ftest->code))
return -EINVAL;
switch (ftest->code) {
case BPF_ALU | BPF_DIV | BPF_K:
case BPF_ALU | BPF_MOD | BPF_K:
if (ftest->k == 0)
return -EINVAL;
break;
case BPF_ALU | BPF_LSH | BPF_K:
case BPF_ALU | BPF_RSH | BPF_K:
if (ftest->k >= 32)
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
static int bpf_prog_store_orig_filter(struct bpf_prog *fp,
const struct sock_fprog *fprog)
{
unsigned int fsize = bpf_classic_proglen(fprog);
struct sock_fprog_kern *fkprog;
fp->orig_prog = kmalloc(sizeof(*fkprog), GFP_KERNEL);
if (!fp->orig_prog)
return -ENOMEM;
fkprog = fp->orig_prog;
fkprog->len = fprog->len;
fkprog->filter = kmemdup(fp->insns, fsize,
GFP_KERNEL | __GFP_NOWARN);
if (!fkprog->filter) {
kfree(fp->orig_prog);
return -ENOMEM;
}
return 0;
}
static void bpf_release_orig_filter(struct bpf_prog *fp)
{
struct sock_fprog_kern *fprog = fp->orig_prog;
if (fprog) {
kfree(fprog->filter);
kfree(fprog);
}
}
static void __bpf_prog_release(struct bpf_prog *prog)
{
if (prog->type == BPF_PROG_TYPE_SOCKET_FILTER) {
bpf_prog_put(prog);
} else {
bpf_release_orig_filter(prog);
bpf_prog_free(prog);
}
}
static void __sk_filter_release(struct sk_filter *fp)
{
__bpf_prog_release(fp->prog);
kfree(fp);
}
static void sk_filter_release_rcu(struct rcu_head *rcu)
{
struct sk_filter *fp = container_of(rcu, struct sk_filter, rcu);
__sk_filter_release(fp);
}
static void sk_filter_release(struct sk_filter *fp)
{
if (atomic_dec_and_test(&fp->refcnt))
call_rcu(&fp->rcu, sk_filter_release_rcu);
}
void sk_filter_uncharge(struct sock *sk, struct sk_filter *fp)
{
u32 filter_size = bpf_prog_size(fp->prog->len);
atomic_sub(filter_size, &sk->sk_omem_alloc);
sk_filter_release(fp);
}
bool sk_filter_charge(struct sock *sk, struct sk_filter *fp)
{
u32 filter_size = bpf_prog_size(fp->prog->len);
if (filter_size <= sysctl_optmem_max &&
atomic_read(&sk->sk_omem_alloc) + filter_size < sysctl_optmem_max) {
atomic_inc(&fp->refcnt);
atomic_add(filter_size, &sk->sk_omem_alloc);
return true;
}
return false;
}
static struct bpf_prog *bpf_migrate_filter(struct bpf_prog *fp)
{
struct sock_filter *old_prog;
struct bpf_prog *old_fp;
int err, new_len, old_len = fp->len;
BUILD_BUG_ON(sizeof(struct sock_filter) !=
sizeof(struct bpf_insn));
old_prog = kmemdup(fp->insns, old_len * sizeof(struct sock_filter),
GFP_KERNEL | __GFP_NOWARN);
if (!old_prog) {
err = -ENOMEM;
goto out_err;
}
err = bpf_convert_filter(old_prog, old_len, NULL, &new_len);
if (err)
goto out_err_free;
old_fp = fp;
fp = bpf_prog_realloc(old_fp, bpf_prog_size(new_len), 0);
if (!fp) {
fp = old_fp;
err = -ENOMEM;
goto out_err_free;
}
fp->len = new_len;
err = bpf_convert_filter(old_prog, old_len, fp->insnsi, &new_len);
if (err)
goto out_err_free;
fp = bpf_prog_select_runtime(fp, &err);
kfree(old_prog);
return fp;
out_err_free:
kfree(old_prog);
out_err:
__bpf_prog_release(fp);
return ERR_PTR(err);
}
static struct bpf_prog *bpf_prepare_filter(struct bpf_prog *fp,
bpf_aux_classic_check_t trans)
{
int err;
fp->bpf_func = NULL;
fp->jited = 0;
err = bpf_check_classic(fp->insns, fp->len);
if (err) {
__bpf_prog_release(fp);
return ERR_PTR(err);
}
if (trans) {
err = trans(fp->insns, fp->len);
if (err) {
__bpf_prog_release(fp);
return ERR_PTR(err);
}
}
bpf_jit_compile(fp);
if (!fp->jited)
fp = bpf_migrate_filter(fp);
return fp;
}
int bpf_prog_create(struct bpf_prog **pfp, struct sock_fprog_kern *fprog)
{
unsigned int fsize = bpf_classic_proglen(fprog);
struct bpf_prog *fp;
if (fprog->filter == NULL)
return -EINVAL;
fp = bpf_prog_alloc(bpf_prog_size(fprog->len), 0);
if (!fp)
return -ENOMEM;
memcpy(fp->insns, fprog->filter, fsize);
fp->len = fprog->len;
fp->orig_prog = NULL;
fp = bpf_prepare_filter(fp, NULL);
if (IS_ERR(fp))
return PTR_ERR(fp);
*pfp = fp;
return 0;
}
int bpf_prog_create_from_user(struct bpf_prog **pfp, struct sock_fprog *fprog,
bpf_aux_classic_check_t trans, bool save_orig)
{
unsigned int fsize = bpf_classic_proglen(fprog);
struct bpf_prog *fp;
int err;
if (fprog->filter == NULL)
return -EINVAL;
fp = bpf_prog_alloc(bpf_prog_size(fprog->len), 0);
if (!fp)
return -ENOMEM;
if (copy_from_user(fp->insns, fprog->filter, fsize)) {
__bpf_prog_free(fp);
return -EFAULT;
}
fp->len = fprog->len;
fp->orig_prog = NULL;
if (save_orig) {
err = bpf_prog_store_orig_filter(fp, fprog);
if (err) {
__bpf_prog_free(fp);
return -ENOMEM;
}
}
fp = bpf_prepare_filter(fp, trans);
if (IS_ERR(fp))
return PTR_ERR(fp);
*pfp = fp;
return 0;
}
void bpf_prog_destroy(struct bpf_prog *fp)
{
__bpf_prog_release(fp);
}
static int __sk_attach_prog(struct bpf_prog *prog, struct sock *sk)
{
struct sk_filter *fp, *old_fp;
fp = kmalloc(sizeof(*fp), GFP_KERNEL);
if (!fp)
return -ENOMEM;
fp->prog = prog;
atomic_set(&fp->refcnt, 0);
if (!sk_filter_charge(sk, fp)) {
kfree(fp);
return -ENOMEM;
}
old_fp = rcu_dereference_protected(sk->sk_filter,
lockdep_sock_is_held(sk));
rcu_assign_pointer(sk->sk_filter, fp);
if (old_fp)
sk_filter_uncharge(sk, old_fp);
return 0;
}
static int __reuseport_attach_prog(struct bpf_prog *prog, struct sock *sk)
{
struct bpf_prog *old_prog;
int err;
if (bpf_prog_size(prog->len) > sysctl_optmem_max)
return -ENOMEM;
if (sk_unhashed(sk) && sk->sk_reuseport) {
err = reuseport_alloc(sk);
if (err)
return err;
} else if (!rcu_access_pointer(sk->sk_reuseport_cb)) {
return -EINVAL;
}
old_prog = reuseport_attach_prog(sk, prog);
if (old_prog)
bpf_prog_destroy(old_prog);
return 0;
}
static
struct bpf_prog *__get_filter(struct sock_fprog *fprog, struct sock *sk)
{
unsigned int fsize = bpf_classic_proglen(fprog);
unsigned int bpf_fsize = bpf_prog_size(fprog->len);
struct bpf_prog *prog;
int err;
if (sock_flag(sk, SOCK_FILTER_LOCKED))
return ERR_PTR(-EPERM);
if (fprog->filter == NULL)
return ERR_PTR(-EINVAL);
prog = bpf_prog_alloc(bpf_fsize, 0);
if (!prog)
return ERR_PTR(-ENOMEM);
if (copy_from_user(prog->insns, fprog->filter, fsize)) {
__bpf_prog_free(prog);
return ERR_PTR(-EFAULT);
}
prog->len = fprog->len;
err = bpf_prog_store_orig_filter(prog, fprog);
if (err) {
__bpf_prog_free(prog);
return ERR_PTR(-ENOMEM);
}
return bpf_prepare_filter(prog, NULL);
}
int sk_attach_filter(struct sock_fprog *fprog, struct sock *sk)
{
struct bpf_prog *prog = __get_filter(fprog, sk);
int err;
if (IS_ERR(prog))
return PTR_ERR(prog);
err = __sk_attach_prog(prog, sk);
if (err < 0) {
__bpf_prog_release(prog);
return err;
}
return 0;
}
int sk_reuseport_attach_filter(struct sock_fprog *fprog, struct sock *sk)
{
struct bpf_prog *prog = __get_filter(fprog, sk);
int err;
if (IS_ERR(prog))
return PTR_ERR(prog);
err = __reuseport_attach_prog(prog, sk);
if (err < 0) {
__bpf_prog_release(prog);
return err;
}
return 0;
}
static struct bpf_prog *__get_bpf(u32 ufd, struct sock *sk)
{
struct bpf_prog *prog;
if (sock_flag(sk, SOCK_FILTER_LOCKED))
return ERR_PTR(-EPERM);
prog = bpf_prog_get(ufd);
if (IS_ERR(prog))
return prog;
if (prog->type != BPF_PROG_TYPE_SOCKET_FILTER) {
bpf_prog_put(prog);
return ERR_PTR(-EINVAL);
}
return prog;
}
int sk_attach_bpf(u32 ufd, struct sock *sk)
{
struct bpf_prog *prog = __get_bpf(ufd, sk);
int err;
if (IS_ERR(prog))
return PTR_ERR(prog);
err = __sk_attach_prog(prog, sk);
if (err < 0) {
bpf_prog_put(prog);
return err;
}
return 0;
}
int sk_reuseport_attach_bpf(u32 ufd, struct sock *sk)
{
struct bpf_prog *prog = __get_bpf(ufd, sk);
int err;
if (IS_ERR(prog))
return PTR_ERR(prog);
err = __reuseport_attach_prog(prog, sk);
if (err < 0) {
bpf_prog_put(prog);
return err;
}
return 0;
}
static inline int bpf_try_make_writable(struct sk_buff *skb,
unsigned int write_len)
{
int err;
if (!skb_cloned(skb))
return 0;
if (skb_clone_writable(skb, write_len))
return 0;
err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
if (!err)
bpf_compute_data_end(skb);
return err;
}
static u64 bpf_skb_store_bytes(u64 r1, u64 r2, u64 r3, u64 r4, u64 flags)
{
struct bpf_scratchpad *sp = this_cpu_ptr(&bpf_sp);
struct sk_buff *skb = (struct sk_buff *) (long) r1;
int offset = (int) r2;
void *from = (void *) (long) r3;
unsigned int len = (unsigned int) r4;
void *ptr;
if (unlikely(flags & ~(BPF_F_RECOMPUTE_CSUM | BPF_F_INVALIDATE_HASH)))
return -EINVAL;
if (unlikely((u32) offset > 0xffff || len > sizeof(sp->buff)))
return -EFAULT;
if (unlikely(bpf_try_make_writable(skb, offset + len)))
return -EFAULT;
ptr = skb_header_pointer(skb, offset, len, sp->buff);
if (unlikely(!ptr))
return -EFAULT;
if (flags & BPF_F_RECOMPUTE_CSUM)
skb_postpull_rcsum(skb, ptr, len);
memcpy(ptr, from, len);
if (ptr == sp->buff)
skb_store_bits(skb, offset, ptr, len);
if (flags & BPF_F_RECOMPUTE_CSUM)
skb_postpush_rcsum(skb, ptr, len);
if (flags & BPF_F_INVALIDATE_HASH)
skb_clear_hash(skb);
return 0;
}
static u64 bpf_skb_load_bytes(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
const struct sk_buff *skb = (const struct sk_buff *)(unsigned long) r1;
int offset = (int) r2;
void *to = (void *)(unsigned long) r3;
unsigned int len = (unsigned int) r4;
void *ptr;
if (unlikely((u32) offset > 0xffff))
goto err_clear;
ptr = skb_header_pointer(skb, offset, len, to);
if (unlikely(!ptr))
goto err_clear;
if (ptr != to)
memcpy(to, ptr, len);
return 0;
err_clear:
memset(to, 0, len);
return -EFAULT;
}
static u64 bpf_l3_csum_replace(u64 r1, u64 r2, u64 from, u64 to, u64 flags)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
int offset = (int) r2;
__sum16 sum, *ptr;
if (unlikely(flags & ~(BPF_F_HDR_FIELD_MASK)))
return -EINVAL;
if (unlikely((u32) offset > 0xffff))
return -EFAULT;
if (unlikely(bpf_try_make_writable(skb, offset + sizeof(sum))))
return -EFAULT;
ptr = skb_header_pointer(skb, offset, sizeof(sum), &sum);
if (unlikely(!ptr))
return -EFAULT;
switch (flags & BPF_F_HDR_FIELD_MASK) {
case 0:
if (unlikely(from != 0))
return -EINVAL;
csum_replace_by_diff(ptr, to);
break;
case 2:
csum_replace2(ptr, from, to);
break;
case 4:
csum_replace4(ptr, from, to);
break;
default:
return -EINVAL;
}
if (ptr == &sum)
skb_store_bits(skb, offset, ptr, sizeof(sum));
return 0;
}
static u64 bpf_l4_csum_replace(u64 r1, u64 r2, u64 from, u64 to, u64 flags)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
bool is_pseudo = flags & BPF_F_PSEUDO_HDR;
bool is_mmzero = flags & BPF_F_MARK_MANGLED_0;
int offset = (int) r2;
__sum16 sum, *ptr;
if (unlikely(flags & ~(BPF_F_MARK_MANGLED_0 | BPF_F_PSEUDO_HDR |
BPF_F_HDR_FIELD_MASK)))
return -EINVAL;
if (unlikely((u32) offset > 0xffff))
return -EFAULT;
if (unlikely(bpf_try_make_writable(skb, offset + sizeof(sum))))
return -EFAULT;
ptr = skb_header_pointer(skb, offset, sizeof(sum), &sum);
if (unlikely(!ptr))
return -EFAULT;
if (is_mmzero && !*ptr)
return 0;
switch (flags & BPF_F_HDR_FIELD_MASK) {
case 0:
if (unlikely(from != 0))
return -EINVAL;
inet_proto_csum_replace_by_diff(ptr, skb, to, is_pseudo);
break;
case 2:
inet_proto_csum_replace2(ptr, skb, from, to, is_pseudo);
break;
case 4:
inet_proto_csum_replace4(ptr, skb, from, to, is_pseudo);
break;
default:
return -EINVAL;
}
if (is_mmzero && !*ptr)
*ptr = CSUM_MANGLED_0;
if (ptr == &sum)
skb_store_bits(skb, offset, ptr, sizeof(sum));
return 0;
}
static u64 bpf_csum_diff(u64 r1, u64 from_size, u64 r3, u64 to_size, u64 seed)
{
struct bpf_scratchpad *sp = this_cpu_ptr(&bpf_sp);
u64 diff_size = from_size + to_size;
__be32 *from = (__be32 *) (long) r1;
__be32 *to = (__be32 *) (long) r3;
int i, j = 0;
if (unlikely(((from_size | to_size) & (sizeof(__be32) - 1)) ||
diff_size > sizeof(sp->diff)))
return -EINVAL;
for (i = 0; i < from_size / sizeof(__be32); i++, j++)
sp->diff[j] = ~from[i];
for (i = 0; i < to_size / sizeof(__be32); i++, j++)
sp->diff[j] = to[i];
return csum_partial(sp->diff, diff_size, seed);
}
static u64 bpf_clone_redirect(u64 r1, u64 ifindex, u64 flags, u64 r4, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1, *skb2;
struct net_device *dev;
if (unlikely(flags & ~(BPF_F_INGRESS)))
return -EINVAL;
dev = dev_get_by_index_rcu(dev_net(skb->dev), ifindex);
if (unlikely(!dev))
return -EINVAL;
skb2 = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!skb2))
return -ENOMEM;
if (flags & BPF_F_INGRESS) {
if (skb_at_tc_ingress(skb2))
skb_postpush_rcsum(skb2, skb_mac_header(skb2),
skb2->mac_len);
return dev_forward_skb(dev, skb2);
}
skb2->dev = dev;
return dev_queue_xmit(skb2);
}
static u64 bpf_redirect(u64 ifindex, u64 flags, u64 r3, u64 r4, u64 r5)
{
struct redirect_info *ri = this_cpu_ptr(&redirect_info);
if (unlikely(flags & ~(BPF_F_INGRESS)))
return TC_ACT_SHOT;
ri->ifindex = ifindex;
ri->flags = flags;
return TC_ACT_REDIRECT;
}
int skb_do_redirect(struct sk_buff *skb)
{
struct redirect_info *ri = this_cpu_ptr(&redirect_info);
struct net_device *dev;
dev = dev_get_by_index_rcu(dev_net(skb->dev), ri->ifindex);
ri->ifindex = 0;
if (unlikely(!dev)) {
kfree_skb(skb);
return -EINVAL;
}
if (ri->flags & BPF_F_INGRESS) {
if (skb_at_tc_ingress(skb))
skb_postpush_rcsum(skb, skb_mac_header(skb),
skb->mac_len);
return dev_forward_skb(dev, skb);
}
skb->dev = dev;
return dev_queue_xmit(skb);
}
static u64 bpf_get_cgroup_classid(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
return task_get_classid((struct sk_buff *) (unsigned long) r1);
}
static u64 bpf_get_route_realm(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
return dst_tclassid((struct sk_buff *) (unsigned long) r1);
}
static u64 bpf_skb_vlan_push(u64 r1, u64 r2, u64 vlan_tci, u64 r4, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
__be16 vlan_proto = (__force __be16) r2;
int ret;
if (unlikely(vlan_proto != htons(ETH_P_8021Q) &&
vlan_proto != htons(ETH_P_8021AD)))
vlan_proto = htons(ETH_P_8021Q);
ret = skb_vlan_push(skb, vlan_proto, vlan_tci);
bpf_compute_data_end(skb);
return ret;
}
static u64 bpf_skb_vlan_pop(u64 r1, u64 r2, u64 r3, u64 r4, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
int ret;
ret = skb_vlan_pop(skb);
bpf_compute_data_end(skb);
return ret;
}
bool bpf_helper_changes_skb_data(void *func)
{
if (func == bpf_skb_vlan_push)
return true;
if (func == bpf_skb_vlan_pop)
return true;
if (func == bpf_skb_store_bytes)
return true;
if (func == bpf_l3_csum_replace)
return true;
if (func == bpf_l4_csum_replace)
return true;
return false;
}
static unsigned short bpf_tunnel_key_af(u64 flags)
{
return flags & BPF_F_TUNINFO_IPV6 ? AF_INET6 : AF_INET;
}
static u64 bpf_skb_get_tunnel_key(u64 r1, u64 r2, u64 size, u64 flags, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
struct bpf_tunnel_key *to = (struct bpf_tunnel_key *) (long) r2;
const struct ip_tunnel_info *info = skb_tunnel_info(skb);
u8 compat[sizeof(struct bpf_tunnel_key)];
void *to_orig = to;
int err;
if (unlikely(!info || (flags & ~(BPF_F_TUNINFO_IPV6)))) {
err = -EINVAL;
goto err_clear;
}
if (ip_tunnel_info_af(info) != bpf_tunnel_key_af(flags)) {
err = -EPROTO;
goto err_clear;
}
if (unlikely(size != sizeof(struct bpf_tunnel_key))) {
err = -EINVAL;
switch (size) {
case offsetof(struct bpf_tunnel_key, tunnel_label):
case offsetof(struct bpf_tunnel_key, tunnel_ext):
goto set_compat;
case offsetof(struct bpf_tunnel_key, remote_ipv6[1]):
if (ip_tunnel_info_af(info) != AF_INET)
goto err_clear;
set_compat:
to = (struct bpf_tunnel_key *)compat;
break;
default:
goto err_clear;
}
}
to->tunnel_id = be64_to_cpu(info->key.tun_id);
to->tunnel_tos = info->key.tos;
to->tunnel_ttl = info->key.ttl;
if (flags & BPF_F_TUNINFO_IPV6) {
memcpy(to->remote_ipv6, &info->key.u.ipv6.src,
sizeof(to->remote_ipv6));
to->tunnel_label = be32_to_cpu(info->key.label);
} else {
to->remote_ipv4 = be32_to_cpu(info->key.u.ipv4.src);
}
if (unlikely(size != sizeof(struct bpf_tunnel_key)))
memcpy(to_orig, to, size);
return 0;
err_clear:
memset(to_orig, 0, size);
return err;
}
static u64 bpf_skb_get_tunnel_opt(u64 r1, u64 r2, u64 size, u64 r4, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
u8 *to = (u8 *) (long) r2;
const struct ip_tunnel_info *info = skb_tunnel_info(skb);
int err;
if (unlikely(!info ||
!(info->key.tun_flags & TUNNEL_OPTIONS_PRESENT))) {
err = -ENOENT;
goto err_clear;
}
if (unlikely(size < info->options_len)) {
err = -ENOMEM;
goto err_clear;
}
ip_tunnel_info_opts_get(to, info);
if (size > info->options_len)
memset(to + info->options_len, 0, size - info->options_len);
return info->options_len;
err_clear:
memset(to, 0, size);
return err;
}
static u64 bpf_skb_set_tunnel_key(u64 r1, u64 r2, u64 size, u64 flags, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
struct bpf_tunnel_key *from = (struct bpf_tunnel_key *) (long) r2;
struct metadata_dst *md = this_cpu_ptr(md_dst);
u8 compat[sizeof(struct bpf_tunnel_key)];
struct ip_tunnel_info *info;
if (unlikely(flags & ~(BPF_F_TUNINFO_IPV6 | BPF_F_ZERO_CSUM_TX |
BPF_F_DONT_FRAGMENT)))
return -EINVAL;
if (unlikely(size != sizeof(struct bpf_tunnel_key))) {
switch (size) {
case offsetof(struct bpf_tunnel_key, tunnel_label):
case offsetof(struct bpf_tunnel_key, tunnel_ext):
case offsetof(struct bpf_tunnel_key, remote_ipv6[1]):
memcpy(compat, from, size);
memset(compat + size, 0, sizeof(compat) - size);
from = (struct bpf_tunnel_key *)compat;
break;
default:
return -EINVAL;
}
}
if (unlikely((!(flags & BPF_F_TUNINFO_IPV6) && from->tunnel_label) ||
from->tunnel_ext))
return -EINVAL;
skb_dst_drop(skb);
dst_hold((struct dst_entry *) md);
skb_dst_set(skb, (struct dst_entry *) md);
info = &md->u.tun_info;
info->mode = IP_TUNNEL_INFO_TX;
info->key.tun_flags = TUNNEL_KEY | TUNNEL_CSUM | TUNNEL_NOCACHE;
if (flags & BPF_F_DONT_FRAGMENT)
info->key.tun_flags |= TUNNEL_DONT_FRAGMENT;
info->key.tun_id = cpu_to_be64(from->tunnel_id);
info->key.tos = from->tunnel_tos;
info->key.ttl = from->tunnel_ttl;
if (flags & BPF_F_TUNINFO_IPV6) {
info->mode |= IP_TUNNEL_INFO_IPV6;
memcpy(&info->key.u.ipv6.dst, from->remote_ipv6,
sizeof(from->remote_ipv6));
info->key.label = cpu_to_be32(from->tunnel_label) &
IPV6_FLOWLABEL_MASK;
} else {
info->key.u.ipv4.dst = cpu_to_be32(from->remote_ipv4);
if (flags & BPF_F_ZERO_CSUM_TX)
info->key.tun_flags &= ~TUNNEL_CSUM;
}
return 0;
}
static u64 bpf_skb_set_tunnel_opt(u64 r1, u64 r2, u64 size, u64 r4, u64 r5)
{
struct sk_buff *skb = (struct sk_buff *) (long) r1;
u8 *from = (u8 *) (long) r2;
struct ip_tunnel_info *info = skb_tunnel_info(skb);
const struct metadata_dst *md = this_cpu_ptr(md_dst);
if (unlikely(info != &md->u.tun_info || (size & (sizeof(u32) - 1))))
return -EINVAL;
if (unlikely(size > IP_TUNNEL_OPTS_MAX))
return -ENOMEM;
ip_tunnel_info_opts_set(info, from, size);
return 0;
}
static const struct bpf_func_proto *
bpf_get_skb_set_tunnel_proto(enum bpf_func_id which)
{
if (!md_dst) {
md_dst = metadata_dst_alloc_percpu(IP_TUNNEL_OPTS_MAX,
GFP_KERNEL);
if (!md_dst)
return NULL;
}
switch (which) {
case BPF_FUNC_skb_set_tunnel_key:
return &bpf_skb_set_tunnel_key_proto;
case BPF_FUNC_skb_set_tunnel_opt:
return &bpf_skb_set_tunnel_opt_proto;
default:
return NULL;
}
}
static const struct bpf_func_proto *
sk_filter_func_proto(enum bpf_func_id func_id)
{
switch (func_id) {
case BPF_FUNC_map_lookup_elem:
return &bpf_map_lookup_elem_proto;
case BPF_FUNC_map_update_elem:
return &bpf_map_update_elem_proto;
case BPF_FUNC_map_delete_elem:
return &bpf_map_delete_elem_proto;
case BPF_FUNC_get_prandom_u32:
return &bpf_get_prandom_u32_proto;
case BPF_FUNC_get_smp_processor_id:
return &bpf_get_smp_processor_id_proto;
case BPF_FUNC_tail_call:
return &bpf_tail_call_proto;
case BPF_FUNC_ktime_get_ns:
return &bpf_ktime_get_ns_proto;
case BPF_FUNC_trace_printk:
if (capable(CAP_SYS_ADMIN))
return bpf_get_trace_printk_proto();
default:
return NULL;
}
}
static const struct bpf_func_proto *
tc_cls_act_func_proto(enum bpf_func_id func_id)
{
switch (func_id) {
case BPF_FUNC_skb_store_bytes:
return &bpf_skb_store_bytes_proto;
case BPF_FUNC_skb_load_bytes:
return &bpf_skb_load_bytes_proto;
case BPF_FUNC_csum_diff:
return &bpf_csum_diff_proto;
case BPF_FUNC_l3_csum_replace:
return &bpf_l3_csum_replace_proto;
case BPF_FUNC_l4_csum_replace:
return &bpf_l4_csum_replace_proto;
case BPF_FUNC_clone_redirect:
return &bpf_clone_redirect_proto;
case BPF_FUNC_get_cgroup_classid:
return &bpf_get_cgroup_classid_proto;
case BPF_FUNC_skb_vlan_push:
return &bpf_skb_vlan_push_proto;
case BPF_FUNC_skb_vlan_pop:
return &bpf_skb_vlan_pop_proto;
case BPF_FUNC_skb_get_tunnel_key:
return &bpf_skb_get_tunnel_key_proto;
case BPF_FUNC_skb_set_tunnel_key:
return bpf_get_skb_set_tunnel_proto(func_id);
case BPF_FUNC_skb_get_tunnel_opt:
return &bpf_skb_get_tunnel_opt_proto;
case BPF_FUNC_skb_set_tunnel_opt:
return bpf_get_skb_set_tunnel_proto(func_id);
case BPF_FUNC_redirect:
return &bpf_redirect_proto;
case BPF_FUNC_get_route_realm:
return &bpf_get_route_realm_proto;
case BPF_FUNC_perf_event_output:
return bpf_get_event_output_proto();
default:
return sk_filter_func_proto(func_id);
}
}
static bool __is_valid_access(int off, int size, enum bpf_access_type type)
{
if (off < 0 || off >= sizeof(struct __sk_buff))
return false;
if (off % size != 0)
return false;
if (size != sizeof(__u32))
return false;
return true;
}
static bool sk_filter_is_valid_access(int off, int size,
enum bpf_access_type type,
enum bpf_reg_type *reg_type)
{
switch (off) {
case offsetof(struct __sk_buff, tc_classid):
case offsetof(struct __sk_buff, data):
case offsetof(struct __sk_buff, data_end):
return false;
}
if (type == BPF_WRITE) {
switch (off) {
case offsetof(struct __sk_buff, cb[0]) ...
offsetof(struct __sk_buff, cb[4]):
break;
default:
return false;
}
}
return __is_valid_access(off, size, type);
}
static bool tc_cls_act_is_valid_access(int off, int size,
enum bpf_access_type type,
enum bpf_reg_type *reg_type)
{
if (type == BPF_WRITE) {
switch (off) {
case offsetof(struct __sk_buff, mark):
case offsetof(struct __sk_buff, tc_index):
case offsetof(struct __sk_buff, priority):
case offsetof(struct __sk_buff, cb[0]) ...
offsetof(struct __sk_buff, cb[4]):
case offsetof(struct __sk_buff, tc_classid):
break;
default:
return false;
}
}
switch (off) {
case offsetof(struct __sk_buff, data):
*reg_type = PTR_TO_PACKET;
break;
case offsetof(struct __sk_buff, data_end):
*reg_type = PTR_TO_PACKET_END;
break;
}
return __is_valid_access(off, size, type);
}
static u32 bpf_net_convert_ctx_access(enum bpf_access_type type, int dst_reg,
int src_reg, int ctx_off,
struct bpf_insn *insn_buf,
struct bpf_prog *prog)
{
struct bpf_insn *insn = insn_buf;
switch (ctx_off) {
case offsetof(struct __sk_buff, len):
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, len) != 4);
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, len));
break;
case offsetof(struct __sk_buff, protocol):
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, protocol) != 2);
*insn++ = BPF_LDX_MEM(BPF_H, dst_reg, src_reg,
offsetof(struct sk_buff, protocol));
break;
case offsetof(struct __sk_buff, vlan_proto):
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, vlan_proto) != 2);
*insn++ = BPF_LDX_MEM(BPF_H, dst_reg, src_reg,
offsetof(struct sk_buff, vlan_proto));
break;
case offsetof(struct __sk_buff, priority):
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, priority) != 4);
if (type == BPF_WRITE)
*insn++ = BPF_STX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, priority));
else
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, priority));
break;
case offsetof(struct __sk_buff, ingress_ifindex):
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, skb_iif) != 4);
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, skb_iif));
break;
case offsetof(struct __sk_buff, ifindex):
BUILD_BUG_ON(FIELD_SIZEOF(struct net_device, ifindex) != 4);
*insn++ = BPF_LDX_MEM(bytes_to_bpf_size(FIELD_SIZEOF(struct sk_buff, dev)),
dst_reg, src_reg,
offsetof(struct sk_buff, dev));
*insn++ = BPF_JMP_IMM(BPF_JEQ, dst_reg, 0, 1);
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, dst_reg,
offsetof(struct net_device, ifindex));
break;
case offsetof(struct __sk_buff, hash):
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, hash) != 4);
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, hash));
break;
case offsetof(struct __sk_buff, mark):
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, mark) != 4);
if (type == BPF_WRITE)
*insn++ = BPF_STX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, mark));
else
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, src_reg,
offsetof(struct sk_buff, mark));
break;
case offsetof(struct __sk_buff, pkt_type):
return convert_skb_access(SKF_AD_PKTTYPE, dst_reg, src_reg, insn);
case offsetof(struct __sk_buff, queue_mapping):
return convert_skb_access(SKF_AD_QUEUE, dst_reg, src_reg, insn);
case offsetof(struct __sk_buff, vlan_present):
return convert_skb_access(SKF_AD_VLAN_TAG_PRESENT,
dst_reg, src_reg, insn);
case offsetof(struct __sk_buff, vlan_tci):
return convert_skb_access(SKF_AD_VLAN_TAG,
dst_reg, src_reg, insn);
case offsetof(struct __sk_buff, cb[0]) ...
offsetof(struct __sk_buff, cb[4]):
BUILD_BUG_ON(FIELD_SIZEOF(struct qdisc_skb_cb, data) < 20);
prog->cb_access = 1;
ctx_off -= offsetof(struct __sk_buff, cb[0]);
ctx_off += offsetof(struct sk_buff, cb);
ctx_off += offsetof(struct qdisc_skb_cb, data);
if (type == BPF_WRITE)
*insn++ = BPF_STX_MEM(BPF_W, dst_reg, src_reg, ctx_off);
else
*insn++ = BPF_LDX_MEM(BPF_W, dst_reg, src_reg, ctx_off);
break;
case offsetof(struct __sk_buff, tc_classid):
ctx_off -= offsetof(struct __sk_buff, tc_classid);
ctx_off += offsetof(struct sk_buff, cb);
ctx_off += offsetof(struct qdisc_skb_cb, tc_classid);
if (type == BPF_WRITE)
*insn++ = BPF_STX_MEM(BPF_H, dst_reg, src_reg, ctx_off);
else
*insn++ = BPF_LDX_MEM(BPF_H, dst_reg, src_reg, ctx_off);
break;
case offsetof(struct __sk_buff, data):
*insn++ = BPF_LDX_MEM(bytes_to_bpf_size(FIELD_SIZEOF(struct sk_buff, data)),
dst_reg, src_reg,
offsetof(struct sk_buff, data));
break;
case offsetof(struct __sk_buff, data_end):
ctx_off -= offsetof(struct __sk_buff, data_end);
ctx_off += offsetof(struct sk_buff, cb);
ctx_off += offsetof(struct bpf_skb_data_end, data_end);
*insn++ = BPF_LDX_MEM(bytes_to_bpf_size(sizeof(void *)),
dst_reg, src_reg, ctx_off);
break;
case offsetof(struct __sk_buff, tc_index):
#ifdef CONFIG_NET_SCHED
BUILD_BUG_ON(FIELD_SIZEOF(struct sk_buff, tc_index) != 2);
if (type == BPF_WRITE)
*insn++ = BPF_STX_MEM(BPF_H, dst_reg, src_reg,
offsetof(struct sk_buff, tc_index));
else
*insn++ = BPF_LDX_MEM(BPF_H, dst_reg, src_reg,
offsetof(struct sk_buff, tc_index));
break;
#else
if (type == BPF_WRITE)
*insn++ = BPF_MOV64_REG(dst_reg, dst_reg);
else
*insn++ = BPF_MOV64_IMM(dst_reg, 0);
break;
#endif
}
return insn - insn_buf;
}
static int __init register_sk_filter_ops(void)
{
bpf_register_prog_type(&sk_filter_type);
bpf_register_prog_type(&sched_cls_type);
bpf_register_prog_type(&sched_act_type);
return 0;
}
int sk_detach_filter(struct sock *sk)
{
int ret = -ENOENT;
struct sk_filter *filter;
if (sock_flag(sk, SOCK_FILTER_LOCKED))
return -EPERM;
filter = rcu_dereference_protected(sk->sk_filter,
lockdep_sock_is_held(sk));
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
lockdep_sock_is_held(sk));
if (!filter)
goto out;
ret = -EACCES;
fprog = filter->prog->orig_prog;
if (!fprog)
goto out;
ret = fprog->len;
if (!len)
goto out;
ret = -EINVAL;
if (len < fprog->len)
goto out;
ret = -EFAULT;
if (copy_to_user(ubuf, fprog->filter, bpf_classic_proglen(fprog)))
goto out;
ret = fprog->len;
out:
release_sock(sk);
return ret;
}
