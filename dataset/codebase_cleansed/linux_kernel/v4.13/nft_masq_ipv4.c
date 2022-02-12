static void nft_masq_ipv4_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_masq *priv = nft_expr_priv(expr);
struct nf_nat_range range;
memset(&range, 0, sizeof(range));
range.flags = priv->flags;
if (priv->sreg_proto_min) {
range.min_proto.all = (__force __be16)nft_reg_load16(
&regs->data[priv->sreg_proto_min]);
range.max_proto.all = (__force __be16)nft_reg_load16(
&regs->data[priv->sreg_proto_max]);
}
regs->verdict.code = nf_nat_masquerade_ipv4(pkt->skb, nft_hook(pkt),
&range, nft_out(pkt));
}
static void
nft_masq_ipv4_destroy(const struct nft_ctx *ctx, const struct nft_expr *expr)
{
nf_ct_netns_put(ctx->net, NFPROTO_IPV4);
}
static int __init nft_masq_ipv4_module_init(void)
{
int ret;
ret = nft_register_expr(&nft_masq_ipv4_type);
if (ret < 0)
return ret;
nf_nat_masquerade_ipv4_register_notifier();
return ret;
}
static void __exit nft_masq_ipv4_module_exit(void)
{
nft_unregister_expr(&nft_masq_ipv4_type);
nf_nat_masquerade_ipv4_unregister_notifier();
}
