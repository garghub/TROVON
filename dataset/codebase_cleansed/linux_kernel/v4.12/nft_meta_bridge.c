static void nft_meta_bridge_get_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_meta *priv = nft_expr_priv(expr);
const struct net_device *in = nft_in(pkt), *out = nft_out(pkt);
u32 *dest = &regs->data[priv->dreg];
const struct net_bridge_port *p;
switch (priv->key) {
case NFT_META_BRI_IIFNAME:
if (in == NULL || (p = br_port_get_rcu(in)) == NULL)
goto err;
break;
case NFT_META_BRI_OIFNAME:
if (out == NULL || (p = br_port_get_rcu(out)) == NULL)
goto err;
break;
default:
goto out;
}
strncpy((char *)dest, p->br->dev->name, IFNAMSIZ);
return;
out:
return nft_meta_get_eval(expr, regs, pkt);
err:
regs->verdict.code = NFT_BREAK;
}
static int nft_meta_bridge_get_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_meta *priv = nft_expr_priv(expr);
unsigned int len;
priv->key = ntohl(nla_get_be32(tb[NFTA_META_KEY]));
switch (priv->key) {
case NFT_META_BRI_IIFNAME:
case NFT_META_BRI_OIFNAME:
len = IFNAMSIZ;
break;
default:
return nft_meta_get_init(ctx, expr, tb);
}
priv->dreg = nft_parse_register(tb[NFTA_META_DREG]);
return nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, len);
}
static const struct nft_expr_ops *
nft_meta_bridge_select_ops(const struct nft_ctx *ctx,
const struct nlattr * const tb[])
{
if (tb[NFTA_META_KEY] == NULL)
return ERR_PTR(-EINVAL);
if (tb[NFTA_META_DREG] && tb[NFTA_META_SREG])
return ERR_PTR(-EINVAL);
if (tb[NFTA_META_DREG])
return &nft_meta_bridge_get_ops;
if (tb[NFTA_META_SREG])
return &nft_meta_bridge_set_ops;
return ERR_PTR(-EINVAL);
}
static int __init nft_meta_bridge_module_init(void)
{
return nft_register_expr(&nft_meta_bridge_type);
}
static void __exit nft_meta_bridge_module_exit(void)
{
nft_unregister_expr(&nft_meta_bridge_type);
}
