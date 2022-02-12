static void nft_fwd_netdev_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_fwd_netdev *priv = nft_expr_priv(expr);
int oif = regs->data[priv->sreg_dev];
nf_fwd_netdev_egress(pkt, oif);
regs->verdict.code = NF_STOLEN;
}
static int nft_fwd_netdev_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_fwd_netdev *priv = nft_expr_priv(expr);
if (tb[NFTA_FWD_SREG_DEV] == NULL)
return -EINVAL;
priv->sreg_dev = nft_parse_register(tb[NFTA_FWD_SREG_DEV]);
return nft_validate_register_load(priv->sreg_dev, sizeof(int));
}
static int nft_fwd_netdev_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
struct nft_fwd_netdev *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_FWD_SREG_DEV, priv->sreg_dev))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_fwd_netdev_module_init(void)
{
return nft_register_expr(&nft_fwd_netdev_type);
}
static void __exit nft_fwd_netdev_module_exit(void)
{
nft_unregister_expr(&nft_fwd_netdev_type);
}
