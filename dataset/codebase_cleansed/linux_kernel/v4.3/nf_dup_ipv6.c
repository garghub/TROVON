static struct net *pick_net(struct sk_buff *skb)
{
#ifdef CONFIG_NET_NS
const struct dst_entry *dst;
if (skb->dev != NULL)
return dev_net(skb->dev);
dst = skb_dst(skb);
if (dst != NULL && dst->dev != NULL)
return dev_net(dst->dev);
#endif
return &init_net;
}
static bool nf_dup_ipv6_route(struct sk_buff *skb, const struct in6_addr *gw,
int oif)
{
const struct ipv6hdr *iph = ipv6_hdr(skb);
struct net *net = pick_net(skb);
struct dst_entry *dst;
struct flowi6 fl6;
memset(&fl6, 0, sizeof(fl6));
if (oif != -1)
fl6.flowi6_oif = oif;
fl6.daddr = *gw;
fl6.flowlabel = (__force __be32)(((iph->flow_lbl[0] & 0xF) << 16) |
(iph->flow_lbl[1] << 8) | iph->flow_lbl[2]);
dst = ip6_route_output(net, NULL, &fl6);
if (dst->error) {
dst_release(dst);
return false;
}
skb_dst_drop(skb);
skb_dst_set(skb, dst);
skb->dev = dst->dev;
skb->protocol = htons(ETH_P_IPV6);
return true;
}
void nf_dup_ipv6(struct sk_buff *skb, unsigned int hooknum,
const struct in6_addr *gw, int oif)
{
if (this_cpu_read(nf_skb_duplicated))
return;
skb = pskb_copy(skb, GFP_ATOMIC);
if (skb == NULL)
return;
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
nf_conntrack_put(skb->nfct);
skb->nfct = &nf_ct_untracked_get()->ct_general;
skb->nfctinfo = IP_CT_NEW;
nf_conntrack_get(skb->nfct);
#endif
if (hooknum == NF_INET_PRE_ROUTING ||
hooknum == NF_INET_LOCAL_IN) {
struct ipv6hdr *iph = ipv6_hdr(skb);
--iph->hop_limit;
}
if (nf_dup_ipv6_route(skb, gw, oif)) {
__this_cpu_write(nf_skb_duplicated, true);
ip6_local_out(skb);
__this_cpu_write(nf_skb_duplicated, false);
} else {
kfree_skb(skb);
}
}
