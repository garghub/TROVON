static void nft_counter_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
struct nft_counter_percpu *this_cpu;
local_bh_disable();
this_cpu = this_cpu_ptr(priv->counter);
u64_stats_update_begin(&this_cpu->syncp);
this_cpu->counter.bytes += pkt->skb->len;
this_cpu->counter.packets++;
u64_stats_update_end(&this_cpu->syncp);
local_bh_enable();
}
static void nft_counter_fetch(const struct nft_counter_percpu __percpu *counter,
struct nft_counter *total)
{
const struct nft_counter_percpu *cpu_stats;
u64 bytes, packets;
unsigned int seq;
int cpu;
memset(total, 0, sizeof(*total));
for_each_possible_cpu(cpu) {
cpu_stats = per_cpu_ptr(counter, cpu);
do {
seq = u64_stats_fetch_begin_irq(&cpu_stats->syncp);
bytes = cpu_stats->counter.bytes;
packets = cpu_stats->counter.packets;
} while (u64_stats_fetch_retry_irq(&cpu_stats->syncp, seq));
total->packets += packets;
total->bytes += bytes;
}
}
static int nft_counter_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
struct nft_counter total;
nft_counter_fetch(priv->counter, &total);
if (nla_put_be64(skb, NFTA_COUNTER_BYTES, cpu_to_be64(total.bytes)) ||
nla_put_be64(skb, NFTA_COUNTER_PACKETS, cpu_to_be64(total.packets)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int nft_counter_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
struct nft_counter_percpu __percpu *cpu_stats;
struct nft_counter_percpu *this_cpu;
cpu_stats = netdev_alloc_pcpu_stats(struct nft_counter_percpu);
if (cpu_stats == NULL)
return ENOMEM;
preempt_disable();
this_cpu = this_cpu_ptr(cpu_stats);
if (tb[NFTA_COUNTER_PACKETS]) {
this_cpu->counter.packets =
be64_to_cpu(nla_get_be64(tb[NFTA_COUNTER_PACKETS]));
}
if (tb[NFTA_COUNTER_BYTES]) {
this_cpu->counter.bytes =
be64_to_cpu(nla_get_be64(tb[NFTA_COUNTER_BYTES]));
}
preempt_enable();
priv->counter = cpu_stats;
return 0;
}
static void nft_counter_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(expr);
free_percpu(priv->counter);
}
static int nft_counter_clone(struct nft_expr *dst, const struct nft_expr *src)
{
struct nft_counter_percpu_priv *priv = nft_expr_priv(src);
struct nft_counter_percpu_priv *priv_clone = nft_expr_priv(dst);
struct nft_counter_percpu __percpu *cpu_stats;
struct nft_counter_percpu *this_cpu;
struct nft_counter total;
nft_counter_fetch(priv->counter, &total);
cpu_stats = __netdev_alloc_pcpu_stats(struct nft_counter_percpu,
GFP_ATOMIC);
if (cpu_stats == NULL)
return ENOMEM;
preempt_disable();
this_cpu = this_cpu_ptr(cpu_stats);
this_cpu->counter.packets = total.packets;
this_cpu->counter.bytes = total.bytes;
preempt_enable();
priv_clone->counter = cpu_stats;
return 0;
}
static int __init nft_counter_module_init(void)
{
return nft_register_expr(&nft_counter_type);
}
static void __exit nft_counter_module_exit(void)
{
nft_unregister_expr(&nft_counter_type);
}
