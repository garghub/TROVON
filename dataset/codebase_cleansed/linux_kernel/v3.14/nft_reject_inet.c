static void nft_reject_inet_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
switch (pkt->ops->pf) {
case NFPROTO_IPV4:
return nft_reject_ipv4_eval(expr, data, pkt);
case NFPROTO_IPV6:
return nft_reject_ipv6_eval(expr, data, pkt);
}
}
static int __init nft_reject_inet_module_init(void)
{
return nft_register_expr(&nft_reject_inet_type);
}
static void __exit nft_reject_inet_module_exit(void)
{
nft_unregister_expr(&nft_reject_inet_type);
}
