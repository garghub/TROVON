static void nft_meta_bridge_get_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
const struct nft_meta *priv = nft_expr_priv(expr);
const struct net_device *in = pkt->in, *out = pkt->out;
struct nft_data *dest = &data[priv->dreg];
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
strncpy((char *)dest->data, p->br->dev->name, sizeof(dest->data));
return;
out:
return nft_meta_get_eval(expr, data, pkt);
err:
data[NFT_REG_VERDICT].verdict = NFT_BREAK;
}
static int nft_meta_bridge_get_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_meta *priv = nft_expr_priv(expr);
int err;
priv->key = ntohl(nla_get_be32(tb[NFTA_META_KEY]));
switch (priv->key) {
case NFT_META_BRI_IIFNAME:
case NFT_META_BRI_OIFNAME:
break;
default:
return nft_meta_get_init(ctx, expr, tb);
}
priv->dreg = ntohl(nla_get_be32(tb[NFTA_META_DREG]));
err = nft_validate_output_register(priv->dreg);
if (err < 0)
return err;
err = nft_validate_data_load(ctx, priv->dreg, NULL, NFT_DATA_VALUE);
if (err < 0)
return err;
return 0;
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
