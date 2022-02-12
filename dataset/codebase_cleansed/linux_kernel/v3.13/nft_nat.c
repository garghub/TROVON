static void nft_nat_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
const struct nft_nat *priv = nft_expr_priv(expr);
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(pkt->skb, &ctinfo);
struct nf_nat_range range;
memset(&range, 0, sizeof(range));
if (priv->sreg_addr_min) {
if (priv->family == AF_INET) {
range.min_addr.ip = (__force __be32)
data[priv->sreg_addr_min].data[0];
range.max_addr.ip = (__force __be32)
data[priv->sreg_addr_max].data[0];
} else {
memcpy(range.min_addr.ip6,
data[priv->sreg_addr_min].data,
sizeof(struct nft_data));
memcpy(range.max_addr.ip6,
data[priv->sreg_addr_max].data,
sizeof(struct nft_data));
}
range.flags |= NF_NAT_RANGE_MAP_IPS;
}
if (priv->sreg_proto_min) {
range.min_proto.all = (__force __be16)
data[priv->sreg_proto_min].data[0];
range.max_proto.all = (__force __be16)
data[priv->sreg_proto_max].data[0];
range.flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
data[NFT_REG_VERDICT].verdict =
nf_nat_setup_info(ct, &range, priv->type);
}
static int nft_nat_init(const struct nft_ctx *ctx, const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_nat *priv = nft_expr_priv(expr);
int err;
if (tb[NFTA_NAT_TYPE] == NULL)
return -EINVAL;
switch (ntohl(nla_get_be32(tb[NFTA_NAT_TYPE]))) {
case NFT_NAT_SNAT:
priv->type = NF_NAT_MANIP_SRC;
break;
case NFT_NAT_DNAT:
priv->type = NF_NAT_MANIP_DST;
break;
default:
return -EINVAL;
}
if (tb[NFTA_NAT_FAMILY] == NULL)
return -EINVAL;
priv->family = ntohl(nla_get_be32(tb[NFTA_NAT_FAMILY]));
if (priv->family != AF_INET && priv->family != AF_INET6)
return -EINVAL;
if (tb[NFTA_NAT_REG_ADDR_MIN]) {
priv->sreg_addr_min = ntohl(nla_get_be32(
tb[NFTA_NAT_REG_ADDR_MIN]));
err = nft_validate_input_register(priv->sreg_addr_min);
if (err < 0)
return err;
}
if (tb[NFTA_NAT_REG_ADDR_MAX]) {
priv->sreg_addr_max = ntohl(nla_get_be32(
tb[NFTA_NAT_REG_ADDR_MAX]));
err = nft_validate_input_register(priv->sreg_addr_max);
if (err < 0)
return err;
} else
priv->sreg_addr_max = priv->sreg_addr_min;
if (tb[NFTA_NAT_REG_PROTO_MIN]) {
priv->sreg_proto_min = ntohl(nla_get_be32(
tb[NFTA_NAT_REG_PROTO_MIN]));
err = nft_validate_input_register(priv->sreg_proto_min);
if (err < 0)
return err;
}
if (tb[NFTA_NAT_REG_PROTO_MAX]) {
priv->sreg_proto_max = ntohl(nla_get_be32(
tb[NFTA_NAT_REG_PROTO_MAX]));
err = nft_validate_input_register(priv->sreg_proto_max);
if (err < 0)
return err;
} else
priv->sreg_proto_max = priv->sreg_proto_min;
return 0;
}
static int nft_nat_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_nat *priv = nft_expr_priv(expr);
switch (priv->type) {
case NF_NAT_MANIP_SRC:
if (nla_put_be32(skb, NFTA_NAT_TYPE, htonl(NFT_NAT_SNAT)))
goto nla_put_failure;
break;
case NF_NAT_MANIP_DST:
if (nla_put_be32(skb, NFTA_NAT_TYPE, htonl(NFT_NAT_DNAT)))
goto nla_put_failure;
break;
}
if (nla_put_be32(skb, NFTA_NAT_FAMILY, htonl(priv->family)))
goto nla_put_failure;
if (nla_put_be32(skb,
NFTA_NAT_REG_ADDR_MIN, htonl(priv->sreg_addr_min)))
goto nla_put_failure;
if (nla_put_be32(skb,
NFTA_NAT_REG_ADDR_MAX, htonl(priv->sreg_addr_max)))
goto nla_put_failure;
if (nla_put_be32(skb,
NFTA_NAT_REG_PROTO_MIN, htonl(priv->sreg_proto_min)))
goto nla_put_failure;
if (nla_put_be32(skb,
NFTA_NAT_REG_PROTO_MAX, htonl(priv->sreg_proto_max)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_nat_module_init(void)
{
int err;
err = nft_register_expr(&nft_nat_type);
if (err < 0)
return err;
return 0;
}
static void __exit nft_nat_module_exit(void)
{
nft_unregister_expr(&nft_nat_type);
}
