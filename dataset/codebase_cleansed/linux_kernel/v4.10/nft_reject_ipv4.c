static void nft_reject_ipv4_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_reject *priv = nft_expr_priv(expr);
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
nf_send_unreach(pkt->skb, priv->icmp_code, nft_hook(pkt));
break;
case NFT_REJECT_TCP_RST:
nf_send_reset(nft_net(pkt), pkt->skb, nft_hook(pkt));
break;
default:
break;
}
regs->verdict.code = NF_DROP;
}
static int __init nft_reject_ipv4_module_init(void)
{
return nft_register_expr(&nft_reject_ipv4_type);
}
static void __exit nft_reject_ipv4_module_exit(void)
{
nft_unregister_expr(&nft_reject_ipv4_type);
}
