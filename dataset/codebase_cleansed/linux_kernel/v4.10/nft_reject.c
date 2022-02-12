int nft_reject_validate(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nft_data **data)
{
return nft_chain_validate_hooks(ctx->chain,
(1 << NF_INET_LOCAL_IN) |
(1 << NF_INET_FORWARD) |
(1 << NF_INET_LOCAL_OUT));
}
int nft_reject_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_reject *priv = nft_expr_priv(expr);
int err;
err = nft_reject_validate(ctx, expr, NULL);
if (err < 0)
return err;
if (tb[NFTA_REJECT_TYPE] == NULL)
return -EINVAL;
priv->type = ntohl(nla_get_be32(tb[NFTA_REJECT_TYPE]));
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
if (tb[NFTA_REJECT_ICMP_CODE] == NULL)
return -EINVAL;
priv->icmp_code = nla_get_u8(tb[NFTA_REJECT_ICMP_CODE]);
case NFT_REJECT_TCP_RST:
break;
default:
return -EINVAL;
}
return 0;
}
int nft_reject_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_reject *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_REJECT_TYPE, htonl(priv->type)))
goto nla_put_failure;
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
if (nla_put_u8(skb, NFTA_REJECT_ICMP_CODE, priv->icmp_code))
goto nla_put_failure;
break;
default:
break;
}
return 0;
nla_put_failure:
return -1;
}
int nft_reject_icmp_code(u8 code)
{
BUG_ON(code > NFT_REJECT_ICMPX_MAX);
return icmp_code_v4[code];
}
int nft_reject_icmpv6_code(u8 code)
{
BUG_ON(code > NFT_REJECT_ICMPX_MAX);
return icmp_code_v6[code];
}
