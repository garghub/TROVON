static void nft_fib_netdev_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_fib *priv = nft_expr_priv(expr);
switch (ntohs(pkt->skb->protocol)) {
case ETH_P_IP:
switch (priv->result) {
case NFT_FIB_RESULT_OIF:
case NFT_FIB_RESULT_OIFNAME:
return nft_fib4_eval(expr, regs, pkt);
case NFT_FIB_RESULT_ADDRTYPE:
return nft_fib4_eval_type(expr, regs, pkt);
}
break;
case ETH_P_IPV6:
switch (priv->result) {
case NFT_FIB_RESULT_OIF:
case NFT_FIB_RESULT_OIFNAME:
return nft_fib6_eval(expr, regs, pkt);
case NFT_FIB_RESULT_ADDRTYPE:
return nft_fib6_eval_type(expr, regs, pkt);
}
break;
}
regs->verdict.code = NFT_BREAK;
}
static int __init nft_fib_netdev_module_init(void)
{
return nft_register_expr(&nft_fib_netdev_type);
}
static void __exit nft_fib_netdev_module_exit(void)
{
nft_unregister_expr(&nft_fib_netdev_type);
}
