static void nft_rt_get_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_rt *priv = nft_expr_priv(expr);
const struct sk_buff *skb = pkt->skb;
u32 *dest = &regs->data[priv->dreg];
const struct dst_entry *dst;
dst = skb_dst(skb);
if (!dst)
goto err;
switch (priv->key) {
#ifdef CONFIG_IP_ROUTE_CLASSID
case NFT_RT_CLASSID:
*dest = dst->tclassid;
break;
#endif
case NFT_RT_NEXTHOP4:
if (nft_pf(pkt) != NFPROTO_IPV4)
goto err;
*dest = rt_nexthop((const struct rtable *)dst,
ip_hdr(skb)->daddr);
break;
case NFT_RT_NEXTHOP6:
if (nft_pf(pkt) != NFPROTO_IPV6)
goto err;
memcpy(dest, rt6_nexthop((struct rt6_info *)dst,
&ipv6_hdr(skb)->daddr),
sizeof(struct in6_addr));
break;
default:
WARN_ON(1);
goto err;
}
return;
err:
regs->verdict.code = NFT_BREAK;
}
static int nft_rt_get_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_rt *priv = nft_expr_priv(expr);
unsigned int len;
if (tb[NFTA_RT_KEY] == NULL ||
tb[NFTA_RT_DREG] == NULL)
return -EINVAL;
priv->key = ntohl(nla_get_be32(tb[NFTA_RT_KEY]));
switch (priv->key) {
#ifdef CONFIG_IP_ROUTE_CLASSID
case NFT_RT_CLASSID:
#endif
case NFT_RT_NEXTHOP4:
len = sizeof(u32);
break;
case NFT_RT_NEXTHOP6:
len = sizeof(struct in6_addr);
break;
default:
return -EOPNOTSUPP;
}
priv->dreg = nft_parse_register(tb[NFTA_RT_DREG]);
return nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, len);
}
static int nft_rt_get_dump(struct sk_buff *skb,
const struct nft_expr *expr)
{
const struct nft_rt *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_RT_KEY, htonl(priv->key)))
goto nla_put_failure;
if (nft_dump_register(skb, NFTA_RT_DREG, priv->dreg))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_rt_module_init(void)
{
return nft_register_expr(&nft_rt_type);
}
static void __exit nft_rt_module_exit(void)
{
nft_unregister_expr(&nft_rt_type);
}
