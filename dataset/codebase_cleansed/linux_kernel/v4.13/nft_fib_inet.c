static void nft_fib_inet_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_fib *priv = nft_expr_priv(expr);
switch (nft_pf(pkt)) {
case NFPROTO_IPV4:
switch (priv->result) {
case NFT_FIB_RESULT_OIF:
case NFT_FIB_RESULT_OIFNAME:
return nft_fib4_eval(expr, regs, pkt);
case NFT_FIB_RESULT_ADDRTYPE:
return nft_fib4_eval_type(expr, regs, pkt);
}
break;
case NFPROTO_IPV6:
switch (priv->result) {
case NFT_FIB_RESULT_OIF:
case NFT_FIB_RESULT_OIFNAME:
return nft_fib6_eval(expr, regs, pkt);
case NFT_FIB_RESULT_ADDRTYPE:
return nft_fib6_eval_type(expr, regs, pkt);
}
break;
}
regs->verdict.code = NF_DROP;
}
static int __init nft_fib_inet_module_init(void)
{
return nft_register_expr(&nft_fib_inet_type);
}
static void __exit nft_fib_inet_module_exit(void)
{
nft_unregister_expr(&nft_fib_inet_type);
}
