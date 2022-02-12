static void nft_dup_ipv6_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_dup_ipv6 *priv = nft_expr_priv(expr);
struct in6_addr *gw = (struct in6_addr *)&regs->data[priv->sreg_addr];
int oif = priv->sreg_dev ? regs->data[priv->sreg_dev] : -1;
nf_dup_ipv6(pkt->net, pkt->skb, pkt->hook, gw, oif);
}
static int nft_dup_ipv6_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_dup_ipv6 *priv = nft_expr_priv(expr);
int err;
if (tb[NFTA_DUP_SREG_ADDR] == NULL)
return -EINVAL;
priv->sreg_addr = nft_parse_register(tb[NFTA_DUP_SREG_ADDR]);
err = nft_validate_register_load(priv->sreg_addr, sizeof(struct in6_addr));
if (err < 0)
return err;
if (tb[NFTA_DUP_SREG_DEV] != NULL) {
priv->sreg_dev = nft_parse_register(tb[NFTA_DUP_SREG_DEV]);
return nft_validate_register_load(priv->sreg_dev, sizeof(int));
}
return 0;
}
static int nft_dup_ipv6_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
struct nft_dup_ipv6 *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_DUP_SREG_ADDR, priv->sreg_addr))
goto nla_put_failure;
if (priv->sreg_dev &&
nft_dump_register(skb, NFTA_DUP_SREG_DEV, priv->sreg_dev))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_dup_ipv6_module_init(void)
{
return nft_register_expr(&nft_dup_ipv6_type);
}
static void __exit nft_dup_ipv6_module_exit(void)
{
nft_unregister_expr(&nft_dup_ipv6_type);
}
