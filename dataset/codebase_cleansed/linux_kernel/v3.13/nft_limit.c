static void nft_limit_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_limit *priv = nft_expr_priv(expr);
spin_lock_bh(&limit_lock);
if (time_after_eq(jiffies, priv->stamp)) {
priv->tokens = priv->rate;
priv->stamp = jiffies + priv->unit * HZ;
}
if (priv->tokens >= 1) {
priv->tokens--;
spin_unlock_bh(&limit_lock);
return;
}
spin_unlock_bh(&limit_lock);
data[NFT_REG_VERDICT].verdict = NFT_BREAK;
}
static int nft_limit_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_limit *priv = nft_expr_priv(expr);
if (tb[NFTA_LIMIT_RATE] == NULL ||
tb[NFTA_LIMIT_UNIT] == NULL)
return -EINVAL;
priv->rate = be64_to_cpu(nla_get_be64(tb[NFTA_LIMIT_RATE]));
priv->unit = be64_to_cpu(nla_get_be64(tb[NFTA_LIMIT_UNIT]));
priv->stamp = jiffies + priv->unit * HZ;
priv->tokens = priv->rate;
return 0;
}
static int nft_limit_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_limit *priv = nft_expr_priv(expr);
if (nla_put_be64(skb, NFTA_LIMIT_RATE, cpu_to_be64(priv->rate)))
goto nla_put_failure;
if (nla_put_be64(skb, NFTA_LIMIT_UNIT, cpu_to_be64(priv->unit)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_limit_module_init(void)
{
return nft_register_expr(&nft_limit_type);
}
static void __exit nft_limit_module_exit(void)
{
nft_unregister_expr(&nft_limit_type);
}
