static void nft_counter_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_counter *priv = nft_expr_priv(expr);
write_seqlock_bh(&priv->lock);
priv->bytes += pkt->skb->len;
priv->packets++;
write_sequnlock_bh(&priv->lock);
}
static int nft_counter_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
struct nft_counter *priv = nft_expr_priv(expr);
unsigned int seq;
u64 bytes;
u64 packets;
do {
seq = read_seqbegin(&priv->lock);
bytes = priv->bytes;
packets = priv->packets;
} while (read_seqretry(&priv->lock, seq));
if (nla_put_be64(skb, NFTA_COUNTER_BYTES, cpu_to_be64(bytes)))
goto nla_put_failure;
if (nla_put_be64(skb, NFTA_COUNTER_PACKETS, cpu_to_be64(packets)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int nft_counter_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_counter *priv = nft_expr_priv(expr);
if (tb[NFTA_COUNTER_PACKETS])
priv->packets = be64_to_cpu(nla_get_be64(tb[NFTA_COUNTER_PACKETS]));
if (tb[NFTA_COUNTER_BYTES])
priv->bytes = be64_to_cpu(nla_get_be64(tb[NFTA_COUNTER_BYTES]));
seqlock_init(&priv->lock);
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
