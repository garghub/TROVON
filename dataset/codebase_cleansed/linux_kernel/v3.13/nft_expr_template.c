static void nft_template_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_template *priv = nft_expr_priv(expr);
}
static int nft_template_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_template *priv = nft_expr_priv(expr);
return 0;
}
static void nft_template_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
struct nft_template *priv = nft_expr_priv(expr);
}
static int nft_template_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_template *priv = nft_expr_priv(expr);
NLA_PUT_BE32(skb, NFTA_TEMPLATE_ATTR, priv->field);
return 0;
nla_put_failure:
return -1;
}
static int __init nft_template_module_init(void)
{
return nft_register_expr(&nft_template_type);
}
static void __exit nft_template_module_exit(void)
{
nft_unregister_expr(&nft_template_type);
}
