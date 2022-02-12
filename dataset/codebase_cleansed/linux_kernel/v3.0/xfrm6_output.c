int xfrm6_find_1stfragopt(struct xfrm_state *x, struct sk_buff *skb,
u8 **prevhdr)
{
return ip6_find_1stfragopt(skb, prevhdr);
}
static int xfrm6_tunnel_check_size(struct sk_buff *skb)
{
int mtu, ret = 0;
struct dst_entry *dst = skb_dst(skb);
mtu = dst_mtu(dst);
if (mtu < IPV6_MIN_MTU)
mtu = IPV6_MIN_MTU;
if (!skb->local_df && skb->len > mtu) {
skb->dev = dst->dev;
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
ret = -EMSGSIZE;
}
return ret;
}
int xfrm6_extract_output(struct xfrm_state *x, struct sk_buff *skb)
{
int err;
err = xfrm6_tunnel_check_size(skb);
if (err)
return err;
XFRM_MODE_SKB_CB(skb)->protocol = ipv6_hdr(skb)->nexthdr;
return xfrm6_extract_header(skb);
}
int xfrm6_prepare_output(struct xfrm_state *x, struct sk_buff *skb)
{
int err;
err = xfrm_inner_extract_output(x, skb);
if (err)
return err;
memset(IP6CB(skb), 0, sizeof(*IP6CB(skb)));
#ifdef CONFIG_NETFILTER
IP6CB(skb)->flags |= IP6SKB_XFRM_TRANSFORMED;
#endif
skb->protocol = htons(ETH_P_IPV6);
skb->local_df = 1;
return x->outer_mode->output2(x, skb);
}
int xfrm6_output_finish(struct sk_buff *skb)
{
#ifdef CONFIG_NETFILTER
IP6CB(skb)->flags |= IP6SKB_XFRM_TRANSFORMED;
#endif
skb->protocol = htons(ETH_P_IPV6);
return xfrm_output(skb);
}
static int __xfrm6_output(struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
struct xfrm_state *x = dst->xfrm;
if ((x && x->props.mode == XFRM_MODE_TUNNEL) &&
((skb->len > ip6_skb_dst_mtu(skb) && !skb_is_gso(skb)) ||
dst_allfrag(skb_dst(skb)))) {
return ip6_fragment(skb, x->outer_mode->afinfo->output_finish);
}
return x->outer_mode->afinfo->output_finish(skb);
}
int xfrm6_output(struct sk_buff *skb)
{
return NF_HOOK(NFPROTO_IPV6, NF_INET_POST_ROUTING, skb, NULL,
skb_dst(skb)->dev, __xfrm6_output);
}
