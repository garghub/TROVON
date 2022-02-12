static void nft_reject_inet_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_reject *priv = nft_expr_priv(expr);
switch (nft_pf(pkt)) {
case NFPROTO_IPV4:
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
nf_send_unreach(pkt->skb, priv->icmp_code,
nft_hook(pkt));
break;
case NFT_REJECT_TCP_RST:
nf_send_reset(nft_net(pkt), pkt->skb, nft_hook(pkt));
break;
case NFT_REJECT_ICMPX_UNREACH:
nf_send_unreach(pkt->skb,
nft_reject_icmp_code(priv->icmp_code),
nft_hook(pkt));
break;
}
break;
case NFPROTO_IPV6:
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
nf_send_unreach6(nft_net(pkt), pkt->skb,
priv->icmp_code, nft_hook(pkt));
break;
case NFT_REJECT_TCP_RST:
nf_send_reset6(nft_net(pkt), pkt->skb, nft_hook(pkt));
break;
case NFT_REJECT_ICMPX_UNREACH:
nf_send_unreach6(nft_net(pkt), pkt->skb,
nft_reject_icmpv6_code(priv->icmp_code),
nft_hook(pkt));
break;
}
break;
}
regs->verdict.code = NF_DROP;
}
static int nft_reject_inet_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_reject *priv = nft_expr_priv(expr);
int icmp_code;
if (tb[NFTA_REJECT_TYPE] == NULL)
return -EINVAL;
priv->type = ntohl(nla_get_be32(tb[NFTA_REJECT_TYPE]));
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
case NFT_REJECT_ICMPX_UNREACH:
if (tb[NFTA_REJECT_ICMP_CODE] == NULL)
return -EINVAL;
icmp_code = nla_get_u8(tb[NFTA_REJECT_ICMP_CODE]);
if (priv->type == NFT_REJECT_ICMPX_UNREACH &&
icmp_code > NFT_REJECT_ICMPX_MAX)
return -EINVAL;
priv->icmp_code = icmp_code;
break;
case NFT_REJECT_TCP_RST:
break;
default:
return -EINVAL;
}
return 0;
}
static int nft_reject_inet_dump(struct sk_buff *skb,
const struct nft_expr *expr)
{
const struct nft_reject *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_REJECT_TYPE, htonl(priv->type)))
goto nla_put_failure;
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
case NFT_REJECT_ICMPX_UNREACH:
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
static int __init nft_reject_inet_module_init(void)
{
return nft_register_expr(&nft_reject_inet_type);
}
static void __exit nft_reject_inet_module_exit(void)
{
nft_unregister_expr(&nft_reject_inet_type);
}
