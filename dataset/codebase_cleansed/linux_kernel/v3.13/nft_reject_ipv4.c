static void nft_reject_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_reject *priv = nft_expr_priv(expr);
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
icmp_send(pkt->skb, ICMP_DEST_UNREACH, priv->icmp_code, 0);
break;
case NFT_REJECT_TCP_RST:
break;
}
data[NFT_REG_VERDICT].verdict = NF_DROP;
}
static int nft_reject_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_reject *priv = nft_expr_priv(expr);
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
static int nft_reject_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_reject *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_REJECT_TYPE, htonl(priv->type)))
goto nla_put_failure;
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
if (nla_put_u8(skb, NFTA_REJECT_ICMP_CODE, priv->icmp_code))
goto nla_put_failure;
break;
}
return 0;
nla_put_failure:
return -1;
}
static int __init nft_reject_module_init(void)
{
return nft_register_expr(&nft_reject_type);
}
static void __exit nft_reject_module_exit(void)
{
nft_unregister_expr(&nft_reject_type);
}
