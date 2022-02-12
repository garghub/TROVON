static void nft_masq_ipv6_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_masq *priv = nft_expr_priv(expr);
struct nf_nat_range range;
unsigned int verdict;
memset(&range, 0, sizeof(range));
range.flags = priv->flags;
verdict = nf_nat_masquerade_ipv6(pkt->skb, &range, pkt->out);
data[NFT_REG_VERDICT].verdict = verdict;
}
static int __init nft_masq_ipv6_module_init(void)
{
int ret;
ret = nft_register_expr(&nft_masq_ipv6_type);
if (ret < 0)
return ret;
nf_nat_masquerade_ipv6_register_notifier();
return ret;
}
static void __exit nft_masq_ipv6_module_exit(void)
{
nft_unregister_expr(&nft_masq_ipv6_type);
nf_nat_masquerade_ipv6_unregister_notifier();
}
