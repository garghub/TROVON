static bool ip_may_fragment(const struct sk_buff *skb)
{
return unlikely((ip_hdr(skb)->frag_off & htons(IP_DF)) == 0) ||
!skb->local_df;
}
static bool ip_exceeds_mtu(const struct sk_buff *skb, unsigned int mtu)
{
if (skb->len <= mtu || skb->local_df)
return false;
if (skb_is_gso(skb) && skb_gso_network_seglen(skb) <= mtu)
return false;
return true;
}
static bool ip_gso_exceeds_dst_mtu(const struct sk_buff *skb)
{
unsigned int mtu;
if (skb->local_df || !skb_is_gso(skb))
return false;
mtu = ip_dst_mtu_maybe_forward(skb_dst(skb), true);
return skb_gso_network_seglen(skb) > mtu;
}
static int ip_forward_finish_gso(struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
netdev_features_t features;
struct sk_buff *segs;
int ret = 0;
features = netif_skb_dev_features(skb, dst->dev);
segs = skb_gso_segment(skb, features & ~NETIF_F_GSO_MASK);
if (IS_ERR(segs)) {
kfree_skb(skb);
return -ENOMEM;
}
consume_skb(skb);
do {
struct sk_buff *nskb = segs->next;
int err;
segs->next = NULL;
err = dst_output(segs);
if (err && ret == 0)
ret = err;
segs = nskb;
} while (segs);
return ret;
}
static int ip_forward_finish(struct sk_buff *skb)
{
struct ip_options *opt = &(IPCB(skb)->opt);
IP_INC_STATS_BH(dev_net(skb_dst(skb)->dev), IPSTATS_MIB_OUTFORWDATAGRAMS);
IP_ADD_STATS_BH(dev_net(skb_dst(skb)->dev), IPSTATS_MIB_OUTOCTETS, skb->len);
if (unlikely(opt->optlen))
ip_forward_options(skb);
if (ip_gso_exceeds_dst_mtu(skb))
return ip_forward_finish_gso(skb);
return dst_output(skb);
}
int ip_forward(struct sk_buff *skb)
{
u32 mtu;
struct iphdr *iph;
struct rtable *rt;
struct ip_options *opt = &(IPCB(skb)->opt);
if (skb_warn_if_lro(skb))
goto drop;
if (!xfrm4_policy_check(NULL, XFRM_POLICY_FWD, skb))
goto drop;
if (IPCB(skb)->opt.router_alert && ip_call_ra_chain(skb))
return NET_RX_SUCCESS;
if (skb->pkt_type != PACKET_HOST)
goto drop;
skb_forward_csum(skb);
if (ip_hdr(skb)->ttl <= 1)
goto too_many_hops;
if (!xfrm4_route_forward(skb))
goto drop;
rt = skb_rtable(skb);
if (opt->is_strictroute && rt->rt_uses_gateway)
goto sr_failed;
IPCB(skb)->flags |= IPSKB_FORWARDED;
mtu = ip_dst_mtu_maybe_forward(&rt->dst, true);
if (!ip_may_fragment(skb) && ip_exceeds_mtu(skb, mtu)) {
IP_INC_STATS(dev_net(rt->dst.dev), IPSTATS_MIB_FRAGFAILS);
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED,
htonl(mtu));
goto drop;
}
if (skb_cow(skb, LL_RESERVED_SPACE(rt->dst.dev)+rt->dst.header_len))
goto drop;
iph = ip_hdr(skb);
ip_decrease_ttl(iph);
if (rt->rt_flags&RTCF_DOREDIRECT && !opt->srr && !skb_sec_path(skb))
ip_rt_send_redirect(skb);
skb->priority = rt_tos2priority(iph->tos);
return NF_HOOK(NFPROTO_IPV4, NF_INET_FORWARD, skb, skb->dev,
rt->dst.dev, ip_forward_finish);
sr_failed:
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_SR_FAILED, 0);
goto drop;
too_many_hops:
IP_INC_STATS_BH(dev_net(skb_dst(skb)->dev), IPSTATS_MIB_INHDRERRORS);
icmp_send(skb, ICMP_TIME_EXCEEDED, ICMP_EXC_TTL, 0);
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
