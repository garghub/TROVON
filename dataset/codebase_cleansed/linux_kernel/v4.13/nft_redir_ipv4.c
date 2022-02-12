static void nft_redir_ipv4_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_redir *priv = nft_expr_priv(expr);
struct nf_nat_ipv4_multi_range_compat mr;
memset(&mr, 0, sizeof(mr));
if (priv->sreg_proto_min) {
mr.range[0].min.all = (__force __be16)nft_reg_load16(
&regs->data[priv->sreg_proto_min]);
mr.range[0].max.all = (__force __be16)nft_reg_load16(
&regs->data[priv->sreg_proto_max]);
mr.range[0].flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
mr.range[0].flags |= priv->flags;
regs->verdict.code = nf_nat_redirect_ipv4(pkt->skb, &mr, nft_hook(pkt));
}
static void
nft_redir_ipv4_destroy(const struct nft_ctx *ctx, const struct nft_expr *expr)
{
nf_ct_netns_put(ctx->net, NFPROTO_IPV4);
}
static int __init nft_redir_ipv4_module_init(void)
{
return nft_register_expr(&nft_redir_ipv4_type);
}
static void __exit nft_redir_ipv4_module_exit(void)
{
nft_unregister_expr(&nft_redir_ipv4_type);
}
