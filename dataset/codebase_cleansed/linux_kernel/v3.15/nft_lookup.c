static void nft_lookup_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
const struct nft_lookup *priv = nft_expr_priv(expr);
const struct nft_set *set = priv->set;
if (set->ops->lookup(set, &data[priv->sreg], &data[priv->dreg]))
return;
data[NFT_REG_VERDICT].verdict = NFT_BREAK;
}
static int nft_lookup_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_lookup *priv = nft_expr_priv(expr);
struct nft_set *set;
int err;
if (tb[NFTA_LOOKUP_SET] == NULL ||
tb[NFTA_LOOKUP_SREG] == NULL)
return -EINVAL;
set = nf_tables_set_lookup(ctx->table, tb[NFTA_LOOKUP_SET]);
if (IS_ERR(set))
return PTR_ERR(set);
priv->sreg = ntohl(nla_get_be32(tb[NFTA_LOOKUP_SREG]));
err = nft_validate_input_register(priv->sreg);
if (err < 0)
return err;
if (tb[NFTA_LOOKUP_DREG] != NULL) {
if (!(set->flags & NFT_SET_MAP))
return -EINVAL;
priv->dreg = ntohl(nla_get_be32(tb[NFTA_LOOKUP_DREG]));
err = nft_validate_output_register(priv->dreg);
if (err < 0)
return err;
if (priv->dreg == NFT_REG_VERDICT) {
if (set->dtype != NFT_DATA_VERDICT)
return -EINVAL;
} else if (set->dtype == NFT_DATA_VERDICT)
return -EINVAL;
} else if (set->flags & NFT_SET_MAP)
return -EINVAL;
err = nf_tables_bind_set(ctx, set, &priv->binding);
if (err < 0)
return err;
priv->set = set;
return 0;
}
static void nft_lookup_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
struct nft_lookup *priv = nft_expr_priv(expr);
nf_tables_unbind_set(ctx, priv->set, &priv->binding);
}
static int nft_lookup_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_lookup *priv = nft_expr_priv(expr);
if (nla_put_string(skb, NFTA_LOOKUP_SET, priv->set->name))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_LOOKUP_SREG, htonl(priv->sreg)))
goto nla_put_failure;
if (priv->set->flags & NFT_SET_MAP)
if (nla_put_be32(skb, NFTA_LOOKUP_DREG, htonl(priv->dreg)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
int __init nft_lookup_module_init(void)
{
return nft_register_expr(&nft_lookup_type);
}
void nft_lookup_module_exit(void)
{
nft_unregister_expr(&nft_lookup_type);
}
