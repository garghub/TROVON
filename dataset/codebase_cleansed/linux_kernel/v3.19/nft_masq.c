int nft_masq_validate(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nft_data **data)
{
int err;
err = nft_chain_validate_dependency(ctx->chain, NFT_CHAIN_T_NAT);
if (err < 0)
return err;
return nft_chain_validate_hooks(ctx->chain,
(1 << NF_INET_POST_ROUTING));
}
int nft_masq_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_masq *priv = nft_expr_priv(expr);
int err;
err = nft_masq_validate(ctx, expr, NULL);
if (err)
return err;
if (tb[NFTA_MASQ_FLAGS] == NULL)
return 0;
priv->flags = ntohl(nla_get_be32(tb[NFTA_MASQ_FLAGS]));
if (priv->flags & ~NF_NAT_RANGE_MASK)
return -EINVAL;
return 0;
}
int nft_masq_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_masq *priv = nft_expr_priv(expr);
if (priv->flags == 0)
return 0;
if (nla_put_be32(skb, NFTA_MASQ_FLAGS, htonl(priv->flags)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
