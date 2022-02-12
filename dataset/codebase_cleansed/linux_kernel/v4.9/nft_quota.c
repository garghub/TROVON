static inline bool nft_overquota(struct nft_quota *priv,
const struct nft_pktinfo *pkt)
{
return atomic64_sub_return(pkt->skb->len, &priv->remain) < 0;
}
static void nft_quota_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_quota *priv = nft_expr_priv(expr);
if (nft_overquota(priv, pkt) ^ priv->invert)
regs->verdict.code = NFT_BREAK;
}
static int nft_quota_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_quota *priv = nft_expr_priv(expr);
u32 flags = 0;
u64 quota;
if (!tb[NFTA_QUOTA_BYTES])
return -EINVAL;
quota = be64_to_cpu(nla_get_be64(tb[NFTA_QUOTA_BYTES]));
if (quota > S64_MAX)
return -EOVERFLOW;
if (tb[NFTA_QUOTA_FLAGS]) {
flags = ntohl(nla_get_be32(tb[NFTA_QUOTA_FLAGS]));
if (flags & ~NFT_QUOTA_F_INV)
return -EINVAL;
}
priv->quota = quota;
priv->invert = (flags & NFT_QUOTA_F_INV) ? true : false;
atomic64_set(&priv->remain, quota);
return 0;
}
static int nft_quota_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_quota *priv = nft_expr_priv(expr);
u32 flags = priv->invert ? NFT_QUOTA_F_INV : 0;
if (nla_put_be64(skb, NFTA_QUOTA_BYTES, cpu_to_be64(priv->quota),
NFTA_QUOTA_PAD) ||
nla_put_be32(skb, NFTA_QUOTA_FLAGS, htonl(flags)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_quota_module_init(void)
{
return nft_register_expr(&nft_quota_type);
}
static void __exit nft_quota_module_exit(void)
{
nft_unregister_expr(&nft_quota_type);
}
