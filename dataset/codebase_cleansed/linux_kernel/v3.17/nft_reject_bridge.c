static void nft_reject_bridge_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
switch (eth_hdr(pkt->skb)->h_proto) {
case htons(ETH_P_IP):
return nft_reject_ipv4_eval(expr, data, pkt);
case htons(ETH_P_IPV6):
return nft_reject_ipv6_eval(expr, data, pkt);
default:
data[NFT_REG_VERDICT].verdict = NF_DROP;
break;
}
}
static int __init nft_reject_bridge_module_init(void)
{
return nft_register_expr(&nft_reject_bridge_type);
}
static void __exit nft_reject_bridge_module_exit(void)
{
nft_unregister_expr(&nft_reject_bridge_type);
}
