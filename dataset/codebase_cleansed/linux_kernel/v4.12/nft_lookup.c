static void nft_lookup_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_lookup *priv = nft_expr_priv(expr);
const struct nft_set *set = priv->set;
const struct nft_set_ext *ext;
bool found;
found = set->ops->lookup(nft_net(pkt), set, &regs->data[priv->sreg],
&ext) ^ priv->invert;
if (!found) {
regs->verdict.code = NFT_BREAK;
return;
}
if (set->flags & NFT_SET_MAP)
nft_data_copy(&regs->data[priv->dreg],
nft_set_ext_data(ext), set->dlen);
}
static int nft_lookup_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_lookup *priv = nft_expr_priv(expr);
u8 genmask = nft_genmask_next(ctx->net);
struct nft_set *set;
u32 flags;
int err;
if (tb[NFTA_LOOKUP_SET] == NULL ||
tb[NFTA_LOOKUP_SREG] == NULL)
return -EINVAL;
set = nft_set_lookup(ctx->net, ctx->table, tb[NFTA_LOOKUP_SET],
tb[NFTA_LOOKUP_SET_ID], genmask);
if (IS_ERR(set))
return PTR_ERR(set);
if (set->flags & NFT_SET_EVAL)
return -EOPNOTSUPP;
priv->sreg = nft_parse_register(tb[NFTA_LOOKUP_SREG]);
err = nft_validate_register_load(priv->sreg, set->klen);
if (err < 0)
return err;
if (tb[NFTA_LOOKUP_FLAGS]) {
flags = ntohl(nla_get_be32(tb[NFTA_LOOKUP_FLAGS]));
if (flags & ~NFT_LOOKUP_F_INV)
return -EINVAL;
if (flags & NFT_LOOKUP_F_INV) {
if (set->flags & NFT_SET_MAP)
return -EINVAL;
priv->invert = true;
}
}
if (tb[NFTA_LOOKUP_DREG] != NULL) {
if (priv->invert)
return -EINVAL;
if (!(set->flags & NFT_SET_MAP))
return -EINVAL;
priv->dreg = nft_parse_register(tb[NFTA_LOOKUP_DREG]);
err = nft_validate_register_store(ctx, priv->dreg, NULL,
set->dtype, set->dlen);
if (err < 0)
return err;
} else if (set->flags & NFT_SET_MAP)
return -EINVAL;
priv->binding.flags = set->flags & NFT_SET_MAP;
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
u32 flags = priv->invert ? NFT_LOOKUP_F_INV : 0;
if (nla_put_string(skb, NFTA_LOOKUP_SET, priv->set->name))
goto nla_put_failure;
if (nft_dump_register(skb, NFTA_LOOKUP_SREG, priv->sreg))
goto nla_put_failure;
if (priv->set->flags & NFT_SET_MAP)
if (nft_dump_register(skb, NFTA_LOOKUP_DREG, priv->dreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_LOOKUP_FLAGS, htonl(flags)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
