static struct dst_entry *__xfrm4_dst_lookup(struct net *net, struct flowi4 *fl4,
int tos,
const xfrm_address_t *saddr,
const xfrm_address_t *daddr)
{
struct rtable *rt;
memset(fl4, 0, sizeof(*fl4));
fl4->daddr = daddr->a4;
fl4->flowi4_tos = tos;
if (saddr)
fl4->saddr = saddr->a4;
rt = __ip_route_output_key(net, fl4);
if (!IS_ERR(rt))
return &rt->dst;
return ERR_CAST(rt);
}
static struct dst_entry *xfrm4_dst_lookup(struct net *net, int tos,
const xfrm_address_t *saddr,
const xfrm_address_t *daddr)
{
struct flowi4 fl4;
return __xfrm4_dst_lookup(net, &fl4, tos, saddr, daddr);
}
static int xfrm4_get_saddr(struct net *net,
xfrm_address_t *saddr, xfrm_address_t *daddr)
{
struct dst_entry *dst;
struct flowi4 fl4;
dst = __xfrm4_dst_lookup(net, &fl4, 0, NULL, daddr);
if (IS_ERR(dst))
return -EHOSTUNREACH;
saddr->a4 = fl4.saddr;
dst_release(dst);
return 0;
}
static int xfrm4_get_tos(const struct flowi *fl)
{
return IPTOS_RT_MASK & fl->u.ip4.flowi4_tos;
}
static int xfrm4_init_path(struct xfrm_dst *path, struct dst_entry *dst,
int nfheader_len)
{
return 0;
}
static int xfrm4_fill_dst(struct xfrm_dst *xdst, struct net_device *dev,
const struct flowi *fl)
{
struct rtable *rt = (struct rtable *)xdst->route;
const struct flowi4 *fl4 = &fl->u.ip4;
rt->rt_key_dst = fl4->daddr;
rt->rt_key_src = fl4->saddr;
rt->rt_key_tos = fl4->flowi4_tos;
rt->rt_route_iif = fl4->flowi4_iif;
rt->rt_iif = fl4->flowi4_iif;
rt->rt_oif = fl4->flowi4_oif;
rt->rt_mark = fl4->flowi4_mark;
xdst->u.dst.dev = dev;
dev_hold(dev);
xdst->u.rt.peer = rt->peer;
if (rt->peer)
atomic_inc(&rt->peer->refcnt);
xdst->u.rt.rt_flags = rt->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST |
RTCF_LOCAL);
xdst->u.rt.rt_type = rt->rt_type;
xdst->u.rt.rt_src = rt->rt_src;
xdst->u.rt.rt_dst = rt->rt_dst;
xdst->u.rt.rt_gateway = rt->rt_gateway;
xdst->u.rt.rt_spec_dst = rt->rt_spec_dst;
return 0;
}
static void
_decode_session4(struct sk_buff *skb, struct flowi *fl, int reverse)
{
const struct iphdr *iph = ip_hdr(skb);
u8 *xprth = skb_network_header(skb) + iph->ihl * 4;
struct flowi4 *fl4 = &fl->u.ip4;
memset(fl4, 0, sizeof(struct flowi4));
fl4->flowi4_mark = skb->mark;
if (!ip_is_fragment(iph)) {
switch (iph->protocol) {
case IPPROTO_UDP:
case IPPROTO_UDPLITE:
case IPPROTO_TCP:
case IPPROTO_SCTP:
case IPPROTO_DCCP:
if (xprth + 4 < skb->data ||
pskb_may_pull(skb, xprth + 4 - skb->data)) {
__be16 *ports = (__be16 *)xprth;
fl4->fl4_sport = ports[!!reverse];
fl4->fl4_dport = ports[!reverse];
}
break;
case IPPROTO_ICMP:
if (pskb_may_pull(skb, xprth + 2 - skb->data)) {
u8 *icmp = xprth;
fl4->fl4_icmp_type = icmp[0];
fl4->fl4_icmp_code = icmp[1];
}
break;
case IPPROTO_ESP:
if (pskb_may_pull(skb, xprth + 4 - skb->data)) {
__be32 *ehdr = (__be32 *)xprth;
fl4->fl4_ipsec_spi = ehdr[0];
}
break;
case IPPROTO_AH:
if (pskb_may_pull(skb, xprth + 8 - skb->data)) {
__be32 *ah_hdr = (__be32*)xprth;
fl4->fl4_ipsec_spi = ah_hdr[1];
}
break;
case IPPROTO_COMP:
if (pskb_may_pull(skb, xprth + 4 - skb->data)) {
__be16 *ipcomp_hdr = (__be16 *)xprth;
fl4->fl4_ipsec_spi = htonl(ntohs(ipcomp_hdr[1]));
}
break;
case IPPROTO_GRE:
if (pskb_may_pull(skb, xprth + 12 - skb->data)) {
__be16 *greflags = (__be16 *)xprth;
__be32 *gre_hdr = (__be32 *)xprth;
if (greflags[0] & GRE_KEY) {
if (greflags[0] & GRE_CSUM)
gre_hdr++;
fl4->fl4_gre_key = gre_hdr[1];
}
}
break;
default:
fl4->fl4_ipsec_spi = 0;
break;
}
}
fl4->flowi4_proto = iph->protocol;
fl4->daddr = reverse ? iph->saddr : iph->daddr;
fl4->saddr = reverse ? iph->daddr : iph->saddr;
fl4->flowi4_tos = iph->tos;
}
static inline int xfrm4_garbage_collect(struct dst_ops *ops)
{
struct net *net = container_of(ops, struct net, xfrm.xfrm4_dst_ops);
xfrm4_policy_afinfo.garbage_collect(net);
return (dst_entries_get_slow(ops) > ops->gc_thresh * 2);
}
static void xfrm4_update_pmtu(struct dst_entry *dst, u32 mtu)
{
struct xfrm_dst *xdst = (struct xfrm_dst *)dst;
struct dst_entry *path = xdst->route;
path->ops->update_pmtu(path, mtu);
}
static void xfrm4_dst_destroy(struct dst_entry *dst)
{
struct xfrm_dst *xdst = (struct xfrm_dst *)dst;
dst_destroy_metrics_generic(dst);
if (likely(xdst->u.rt.peer))
inet_putpeer(xdst->u.rt.peer);
xfrm_dst_destroy(xdst);
}
static void xfrm4_dst_ifdown(struct dst_entry *dst, struct net_device *dev,
int unregister)
{
if (!unregister)
return;
xfrm_dst_ifdown(dst, dev);
}
static void __init xfrm4_policy_init(void)
{
xfrm_policy_register_afinfo(&xfrm4_policy_afinfo);
}
static void __exit xfrm4_policy_fini(void)
{
#ifdef CONFIG_SYSCTL
if (sysctl_hdr)
unregister_net_sysctl_table(sysctl_hdr);
#endif
xfrm_policy_unregister_afinfo(&xfrm4_policy_afinfo);
}
void __init xfrm4_init(int rt_max_size)
{
xfrm4_dst_ops.gc_thresh = rt_max_size/2;
dst_entries_init(&xfrm4_dst_ops);
xfrm4_state_init();
xfrm4_policy_init();
#ifdef CONFIG_SYSCTL
sysctl_hdr = register_net_sysctl_table(&init_net, net_ipv4_ctl_path,
xfrm4_policy_table);
#endif
}
