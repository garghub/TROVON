static void nft_redir_ipv6_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_redir *priv = nft_expr_priv(expr);
struct nf_nat_range range;
memset(&range, 0, sizeof(range));
if (priv->sreg_proto_min) {
range.min_proto.all = (__force __be16)nft_reg_load16(
&regs->data[priv->sreg_proto_min]);
range.max_proto.all = (__force __be16)nft_reg_load16(
&regs->data[priv->sreg_proto_max]);
range.flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
range.flags |= priv->flags;
regs->verdict.code =
nf_nat_redirect_ipv6(pkt->skb, &range, nft_hook(pkt));
}
static void
nft_redir_ipv6_destroy(const struct nft_ctx *ctx, const struct nft_expr *expr)
{
nf_ct_netns_put(ctx->net, NFPROTO_IPV6);
}
static int __init nft_redir_ipv6_module_init(void)
{
return nft_register_expr(&nft_redir_ipv6_type);
}
static void __exit nft_redir_ipv6_module_exit(void)
{
nft_unregister_expr(&nft_redir_ipv6_type);
}
