static inline void nft_counter_do_eval(struct nft_counter_percpu_priv *priv,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_counter *this_cpu;
seqcount_t *myseq;
local_bh_disable();
this_cpu = this_cpu_ptr(priv->counter);
myseq = this_cpu_ptr(&nft_counter_seq);
write_seqcount_begin(myseq);
this_cpu->bytes += pkt->skb->len;
this_cpu->packets++;
write_seqcount_end(myseq);
local_bh_enable();
}
static inline void nft_counter_obj_eval(struct nft_object *obj,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_counter_percpu_priv *priv = nft_obj_data(obj);
nft_counter_do_eval(priv, regs, pkt);
}
static int nft_counter_do_init(const struct nlattr * const tb[],
struct nft_counter_percpu_priv *priv)
{
struct nft_counter __percpu *cpu_stats;
struct nft_counter *this_cpu;
cpu_stats = alloc_percpu(struct nft_counter);
if (cpu_stats == NULL)
return -ENOMEM;
preempt_disable();
this_cpu = this_cpu_ptr(cpu_stats);
if (tb[NFTA_COUNTER_PACKETS]) {
this_cpu->packets =
be64_to_cpu(nla_get_be64(tb[NFTA_COUNTER_PACKETS]));
}
if (tb[NFTA_COUNTER_BYTES]) {
this_cpu->bytes =
be64_to_cpu(nla_get_be64(tb[NFTA_COUNTER_BYTES]));
}
preempt_enable();
priv->counter = cpu_stats;
return 0;
}
static int nft_counter_obj_init(const struct nft_ctx *ctx,
const struct nlattr * const tb[],
struct nft_object *obj)
{
struct nft_counter_percpu_priv *priv = nft_obj_data(obj);
return nft_counter_do_init(tb, priv);
}
static void nft_counter_do_destroy(struct nft_counter_percpu_priv *priv)
{
free_percpu(priv->counter);
}
static void nft_counter_obj_destroy(struct nft_object *obj)
{
struct nft_counter_percpu_priv *priv = nft_obj_data(obj);
nft_counter_do_destroy(priv);
}
static void nft_counter_reset(struct nft_counter_percpu_priv __percpu *priv,
struct nft_counter *total)
{
struct nft_counter *this_cpu;
local_bh_disable();
this_cpu = this_cpu_ptr(priv->counter);
this_cpu->packets -= total->packets;
this_cpu->bytes -= total->bytes;
local_bh_enable();
}
static void nft_counter_fetch(struct nft_counter_percpu_priv *priv,
struct nft_counter *total)
{
struct nft_counter *this_cpu;
const seqcount_t *myseq;
u64 bytes, packets;
unsigned int seq;
int cpu;
memset(total, 0, sizeof(*total));
for_each_possible_cpu(cpu) {
myseq = per_cpu_ptr(&nft_counter_seq, cpu);
this_cpu = per_cpu_ptr(priv->counter, cpu);
do {
seq = read_seqcount_begin(myseq);
bytes = this_cpu->bytes;
packets = this_cpu->packets;
} while (read_seqcount_retry(myseq, seq));
total->bytes += bytes;
total->packets += packets;
}
}
static int nft_counter_do_dump(struct sk_buff *skb,
struct nft_counter_percpu_priv *priv,
bool reset)
{
struct nft_counter total;
nft_counter_fetch(priv, &total);
if (nla_put_be64(skb, NFTA_COUNTER_BYTES, cpu_to_be64(total.bytes),
NFTA_COUNTER_PAD) ||
nla_put_be64(skb, NFTA_COUNTER_PACKETS, cpu_to_be64(total.packets),
NFTA_COUNTER_PAD))
goto nla_put_failure;
if (reset)
nft_counter_reset(priv, &total);
return 0;
nla_put_failure:
return -1;
}
static int nft_counter_obj_dump(struct sk_buff *skb,
struct nft_object *obj, bool reset)
{
struct nft_counter_percpu_priv *priv = nft_obj_data(obj);
return nft_counter_do_dump(skb, priv, reset);
}
static void nft_counter_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
nft_counter_do_eval(priv, regs, pkt);
}
static int nft_counter_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
return nft_counter_do_dump(skb, priv, false);
}
static int nft_counter_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
return nft_counter_do_init(tb, priv);
}
static void nft_counter_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
nft_counter_do_destroy(priv);
}
static int nft_counter_clone(struct nft_expr *dst, const struct nft_expr *src)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(src);
struct nft_counter_percpu_priv *priv_clone = nft_expr_priv(dst);
struct nft_counter __percpu *cpu_stats;
struct nft_counter *this_cpu;
struct nft_counter total;
nft_counter_fetch(priv, &total);
cpu_stats = alloc_percpu_gfp(struct nft_counter, GFP_ATOMIC);
if (cpu_stats == NULL)
return -ENOMEM;
preempt_disable();
this_cpu = this_cpu_ptr(cpu_stats);
this_cpu->packets = total.packets;
this_cpu->bytes = total.bytes;
preempt_enable();
priv_clone->counter = cpu_stats;
return 0;
}
static int __init nft_counter_module_init(void)
{
int cpu, err;
for_each_possible_cpu(cpu)
seqcount_init(per_cpu_ptr(&nft_counter_seq, cpu));
err = nft_register_obj(&nft_counter_obj);
if (err < 0)
return err;
err = nft_register_expr(&nft_counter_type);
if (err < 0)
goto err1;
return 0;
err1:
nft_unregister_obj(&nft_counter_obj);
return err;
}
static void __exit nft_counter_module_exit(void)
{
nft_unregister_expr(&nft_counter_type);
nft_unregister_obj(&nft_counter_obj);
}
