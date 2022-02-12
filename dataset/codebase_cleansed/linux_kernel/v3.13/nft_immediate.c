static void nft_immediate_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
const struct nft_immediate_expr *priv = nft_expr_priv(expr);
nft_data_copy(&data[priv->dreg], &priv->data);
}
static int nft_immediate_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_immediate_expr *priv = nft_expr_priv(expr);
struct nft_data_desc desc;
int err;
if (tb[NFTA_IMMEDIATE_DREG] == NULL ||
tb[NFTA_IMMEDIATE_DATA] == NULL)
return -EINVAL;
priv->dreg = ntohl(nla_get_be32(tb[NFTA_IMMEDIATE_DREG]));
err = nft_validate_output_register(priv->dreg);
if (err < 0)
return err;
err = nft_data_init(ctx, &priv->data, &desc, tb[NFTA_IMMEDIATE_DATA]);
if (err < 0)
return err;
priv->dlen = desc.len;
err = nft_validate_data_load(ctx, priv->dreg, &priv->data, desc.type);
if (err < 0)
goto err1;
return 0;
err1:
nft_data_uninit(&priv->data, desc.type);
return err;
}
static void nft_immediate_destroy(const struct nft_expr *expr)
{
const struct nft_immediate_expr *priv = nft_expr_priv(expr);
return nft_data_uninit(&priv->data, nft_dreg_to_type(priv->dreg));
}
static int nft_immediate_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_immediate_expr *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_IMMEDIATE_DREG, htonl(priv->dreg)))
goto nla_put_failure;
return nft_data_dump(skb, NFTA_IMMEDIATE_DATA, &priv->data,
nft_dreg_to_type(priv->dreg), priv->dlen);
nla_put_failure:
return -1;
}
static int nft_immediate_validate(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nft_data **data)
{
const struct nft_immediate_expr *priv = nft_expr_priv(expr);
if (priv->dreg == NFT_REG_VERDICT)
*data = &priv->data;
return 0;
}
int __init nft_immediate_module_init(void)
{
return nft_register_expr(&nft_imm_type);
}
void nft_immediate_module_exit(void)
{
nft_unregister_expr(&nft_imm_type);
}
