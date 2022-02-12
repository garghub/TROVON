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
static bool nf_dup_ipv4_route(struct sk_buff *skb, const struct in_addr *gw,
int oif)
{
const struct iphdr *iph = ip_hdr(skb);
struct net *net = pick_net(skb);
struct rtable *rt;
struct flowi4 fl4;
memset(&fl4, 0, sizeof(fl4));
if (oif != -1)
fl4.flowi4_oif = oif;
fl4.daddr = gw->s_addr;
fl4.flowi4_tos = RT_TOS(iph->tos);
fl4.flowi4_scope = RT_SCOPE_UNIVERSE;
fl4.flowi4_flags = FLOWI_FLAG_KNOWN_NH;
rt = ip_route_output_key(net, &fl4);
if (IS_ERR(rt))
return false;
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
skb->dev = rt->dst.dev;
skb->protocol = htons(ETH_P_IP);
return true;
}
void nf_dup_ipv4(struct sk_buff *skb, unsigned int hooknum,
const struct in_addr *gw, int oif)
{
struct iphdr *iph;
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
iph = ip_hdr(skb);
iph->frag_off |= htons(IP_DF);
if (hooknum == NF_INET_PRE_ROUTING ||
hooknum == NF_INET_LOCAL_IN)
--iph->ttl;
ip_send_check(iph);
if (nf_dup_ipv4_route(skb, gw, oif)) {
__this_cpu_write(nf_skb_duplicated, true);
ip_local_out(skb);
__this_cpu_write(nf_skb_duplicated, false);
} else {
kfree_skb(skb);
}
}
