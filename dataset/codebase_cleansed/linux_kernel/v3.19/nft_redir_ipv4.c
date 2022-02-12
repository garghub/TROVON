static void nft_redir_ipv4_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_redir *priv = nft_expr_priv(expr);
struct nf_nat_ipv4_multi_range_compat mr;
unsigned int verdict;
memset(&mr, 0, sizeof(mr));
if (priv->sreg_proto_min) {
mr.range[0].min.all =
*(__be16 *)&data[priv->sreg_proto_min].data[0];
mr.range[0].max.all =
*(__be16 *)&data[priv->sreg_proto_max].data[0];
mr.range[0].flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
mr.range[0].flags |= priv->flags;
verdict = nf_nat_redirect_ipv4(pkt->skb, &mr, pkt->ops->hooknum);
data[NFT_REG_VERDICT].verdict = verdict;
}
static int __init nft_redir_ipv4_module_init(void)
{
return nft_register_expr(&nft_redir_ipv4_type);
}
static void __exit nft_redir_ipv4_module_exit(void)
{
nft_unregister_expr(&nft_redir_ipv4_type);
}
