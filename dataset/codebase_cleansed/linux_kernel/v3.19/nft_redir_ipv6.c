static void nft_redir_ipv6_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_redir *priv = nft_expr_priv(expr);
struct nf_nat_range range;
unsigned int verdict;
memset(&range, 0, sizeof(range));
if (priv->sreg_proto_min) {
range.min_proto.all =
*(__be16 *)&data[priv->sreg_proto_min].data[0];
range.max_proto.all =
*(__be16 *)&data[priv->sreg_proto_max].data[0];
range.flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
range.flags |= priv->flags;
verdict = nf_nat_redirect_ipv6(pkt->skb, &range, pkt->ops->hooknum);
data[NFT_REG_VERDICT].verdict = verdict;
}
static int __init nft_redir_ipv6_module_init(void)
{
return nft_register_expr(&nft_redir_ipv6_type);
}
static void __exit nft_redir_ipv6_module_exit(void)
{
nft_unregister_expr(&nft_redir_ipv6_type);
}
