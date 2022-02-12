int nft_redir_validate(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nft_data **data)
{
int err;
err = nft_chain_validate_dependency(ctx->chain, NFT_CHAIN_T_NAT);
if (err < 0)
return err;
return nft_chain_validate_hooks(ctx->chain,
(1 << NF_INET_PRE_ROUTING) |
(1 << NF_INET_LOCAL_OUT));
}
int nft_redir_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_redir *priv = nft_expr_priv(expr);
int err;
err = nft_redir_validate(ctx, expr, NULL);
if (err < 0)
return err;
if (tb[NFTA_REDIR_REG_PROTO_MIN]) {
priv->sreg_proto_min =
ntohl(nla_get_be32(tb[NFTA_REDIR_REG_PROTO_MIN]));
err = nft_validate_input_register(priv->sreg_proto_min);
if (err < 0)
return err;
if (tb[NFTA_REDIR_REG_PROTO_MAX]) {
priv->sreg_proto_max =
ntohl(nla_get_be32(tb[NFTA_REDIR_REG_PROTO_MAX]));
err = nft_validate_input_register(priv->sreg_proto_max);
if (err < 0)
return err;
} else {
priv->sreg_proto_max = priv->sreg_proto_min;
}
}
if (tb[NFTA_REDIR_FLAGS]) {
priv->flags = ntohl(nla_get_be32(tb[NFTA_REDIR_FLAGS]));
if (priv->flags & ~NF_NAT_RANGE_MASK)
return -EINVAL;
}
return 0;
}
int nft_redir_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_redir *priv = nft_expr_priv(expr);
if (priv->sreg_proto_min) {
if (nla_put_be32(skb, NFTA_REDIR_REG_PROTO_MIN,
htonl(priv->sreg_proto_min)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_REDIR_REG_PROTO_MAX,
htonl(priv->sreg_proto_max)))
goto nla_put_failure;
}
if (priv->flags != 0 &&
nla_put_be32(skb, NFTA_REDIR_FLAGS, htonl(priv->flags)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
