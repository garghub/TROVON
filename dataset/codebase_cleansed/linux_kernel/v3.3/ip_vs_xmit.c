static inline void
__ip_vs_dst_set(struct ip_vs_dest *dest, u32 rtos, struct dst_entry *dst,
u32 dst_cookie)
{
struct dst_entry *old_dst;
old_dst = dest->dst_cache;
dest->dst_cache = dst;
dest->dst_rtos = rtos;
dest->dst_cookie = dst_cookie;
dst_release(old_dst);
}
static inline struct dst_entry *
__ip_vs_dst_check(struct ip_vs_dest *dest, u32 rtos)
{
struct dst_entry *dst = dest->dst_cache;
if (!dst)
return NULL;
if ((dst->obsolete || rtos != dest->dst_rtos) &&
dst->ops->check(dst, dest->dst_cookie) == NULL) {
dest->dst_cache = NULL;
dst_release(dst);
return NULL;
}
dst_hold(dst);
return dst;
}
static struct rtable *
__ip_vs_get_out_rt(struct sk_buff *skb, struct ip_vs_dest *dest,
__be32 daddr, u32 rtos, int rt_mode, __be32 *ret_saddr)
{
struct net *net = dev_net(skb_dst(skb)->dev);
struct rtable *rt;
struct rtable *ort;
int local;
if (dest) {
spin_lock(&dest->dst_lock);
if (!(rt = (struct rtable *)
__ip_vs_dst_check(dest, rtos))) {
struct flowi4 fl4;
memset(&fl4, 0, sizeof(fl4));
fl4.daddr = dest->addr.ip;
fl4.flowi4_tos = rtos;
rt = ip_route_output_key(net, &fl4);
if (IS_ERR(rt)) {
spin_unlock(&dest->dst_lock);
IP_VS_DBG_RL("ip_route_output error, dest: %pI4\n",
&dest->addr.ip);
return NULL;
}
__ip_vs_dst_set(dest, rtos, dst_clone(&rt->dst), 0);
dest->dst_saddr.ip = fl4.saddr;
IP_VS_DBG(10, "new dst %pI4, src %pI4, refcnt=%d, "
"rtos=%X\n",
&dest->addr.ip, &dest->dst_saddr.ip,
atomic_read(&rt->dst.__refcnt), rtos);
}
daddr = dest->addr.ip;
if (ret_saddr)
*ret_saddr = dest->dst_saddr.ip;
spin_unlock(&dest->dst_lock);
} else {
struct flowi4 fl4;
memset(&fl4, 0, sizeof(fl4));
fl4.daddr = daddr;
fl4.flowi4_tos = rtos;
rt = ip_route_output_key(net, &fl4);
if (IS_ERR(rt)) {
IP_VS_DBG_RL("ip_route_output error, dest: %pI4\n",
&daddr);
return NULL;
}
if (ret_saddr)
*ret_saddr = fl4.saddr;
}
local = rt->rt_flags & RTCF_LOCAL;
if (!((local ? IP_VS_RT_MODE_LOCAL : IP_VS_RT_MODE_NON_LOCAL) &
rt_mode)) {
IP_VS_DBG_RL("Stopping traffic to %s address, dest: %pI4\n",
(rt->rt_flags & RTCF_LOCAL) ?
"local":"non-local", &daddr);
ip_rt_put(rt);
return NULL;
}
if (local && !(rt_mode & IP_VS_RT_MODE_RDR) &&
!((ort = skb_rtable(skb)) && ort->rt_flags & RTCF_LOCAL)) {
IP_VS_DBG_RL("Redirect from non-local address %pI4 to local "
"requires NAT method, dest: %pI4\n",
&ip_hdr(skb)->daddr, &daddr);
ip_rt_put(rt);
return NULL;
}
if (unlikely(!local && ipv4_is_loopback(ip_hdr(skb)->saddr))) {
IP_VS_DBG_RL("Stopping traffic from loopback address %pI4 "
"to non-local address, dest: %pI4\n",
&ip_hdr(skb)->saddr, &daddr);
ip_rt_put(rt);
return NULL;
}
return rt;
}
static int
__ip_vs_reroute_locally(struct sk_buff *skb)
{
struct rtable *rt = skb_rtable(skb);
struct net_device *dev = rt->dst.dev;
struct net *net = dev_net(dev);
struct iphdr *iph = ip_hdr(skb);
if (rt_is_input_route(rt)) {
unsigned long orefdst = skb->_skb_refdst;
if (ip_route_input(skb, iph->daddr, iph->saddr,
iph->tos, skb->dev))
return 0;
refdst_drop(orefdst);
} else {
struct flowi4 fl4 = {
.daddr = iph->daddr,
.saddr = iph->saddr,
.flowi4_tos = RT_TOS(iph->tos),
.flowi4_mark = skb->mark,
};
rt = ip_route_output_key(net, &fl4);
if (IS_ERR(rt))
return 0;
if (!(rt->rt_flags & RTCF_LOCAL)) {
ip_rt_put(rt);
return 0;
}
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
}
return 1;
}
static inline int __ip_vs_is_local_route6(struct rt6_info *rt)
{
return rt->dst.dev && rt->dst.dev->flags & IFF_LOOPBACK;
}
static struct dst_entry *
__ip_vs_route_output_v6(struct net *net, struct in6_addr *daddr,
struct in6_addr *ret_saddr, int do_xfrm)
{
struct dst_entry *dst;
struct flowi6 fl6 = {
.daddr = *daddr,
};
dst = ip6_route_output(net, NULL, &fl6);
if (dst->error)
goto out_err;
if (!ret_saddr)
return dst;
if (ipv6_addr_any(&fl6.saddr) &&
ipv6_dev_get_saddr(net, ip6_dst_idev(dst)->dev,
&fl6.daddr, 0, &fl6.saddr) < 0)
goto out_err;
if (do_xfrm) {
dst = xfrm_lookup(net, dst, flowi6_to_flowi(&fl6), NULL, 0);
if (IS_ERR(dst)) {
dst = NULL;
goto out_err;
}
}
*ret_saddr = fl6.saddr;
return dst;
out_err:
dst_release(dst);
IP_VS_DBG_RL("ip6_route_output error, dest: %pI6\n", daddr);
return NULL;
}
static struct rt6_info *
__ip_vs_get_out_rt_v6(struct sk_buff *skb, struct ip_vs_dest *dest,
struct in6_addr *daddr, struct in6_addr *ret_saddr,
int do_xfrm, int rt_mode)
{
struct net *net = dev_net(skb_dst(skb)->dev);
struct rt6_info *rt;
struct rt6_info *ort;
struct dst_entry *dst;
int local;
if (dest) {
spin_lock(&dest->dst_lock);
rt = (struct rt6_info *)__ip_vs_dst_check(dest, 0);
if (!rt) {
u32 cookie;
dst = __ip_vs_route_output_v6(net, &dest->addr.in6,
&dest->dst_saddr.in6,
do_xfrm);
if (!dst) {
spin_unlock(&dest->dst_lock);
return NULL;
}
rt = (struct rt6_info *) dst;
cookie = rt->rt6i_node ? rt->rt6i_node->fn_sernum : 0;
__ip_vs_dst_set(dest, 0, dst_clone(&rt->dst), cookie);
IP_VS_DBG(10, "new dst %pI6, src %pI6, refcnt=%d\n",
&dest->addr.in6, &dest->dst_saddr.in6,
atomic_read(&rt->dst.__refcnt));
}
if (ret_saddr)
*ret_saddr = dest->dst_saddr.in6;
spin_unlock(&dest->dst_lock);
} else {
dst = __ip_vs_route_output_v6(net, daddr, ret_saddr, do_xfrm);
if (!dst)
return NULL;
rt = (struct rt6_info *) dst;
}
local = __ip_vs_is_local_route6(rt);
if (!((local ? IP_VS_RT_MODE_LOCAL : IP_VS_RT_MODE_NON_LOCAL) &
rt_mode)) {
IP_VS_DBG_RL("Stopping traffic to %s address, dest: %pI6\n",
local ? "local":"non-local", daddr);
dst_release(&rt->dst);
return NULL;
}
if (local && !(rt_mode & IP_VS_RT_MODE_RDR) &&
!((ort = (struct rt6_info *) skb_dst(skb)) &&
__ip_vs_is_local_route6(ort))) {
IP_VS_DBG_RL("Redirect from non-local address %pI6 to local "
"requires NAT method, dest: %pI6\n",
&ipv6_hdr(skb)->daddr, daddr);
dst_release(&rt->dst);
return NULL;
}
if (unlikely(!local && (!skb->dev || skb->dev->flags & IFF_LOOPBACK) &&
ipv6_addr_type(&ipv6_hdr(skb)->saddr) &
IPV6_ADDR_LOOPBACK)) {
IP_VS_DBG_RL("Stopping traffic from loopback address %pI6 "
"to non-local address, dest: %pI6\n",
&ipv6_hdr(skb)->saddr, daddr);
dst_release(&rt->dst);
return NULL;
}
return rt;
}
void
ip_vs_dst_reset(struct ip_vs_dest *dest)
{
struct dst_entry *old_dst;
old_dst = dest->dst_cache;
dest->dst_cache = NULL;
dst_release(old_dst);
}
int
ip_vs_null_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
IP_VS_XMIT(NFPROTO_IPV4, skb, cp, 1);
}
int
ip_vs_bypass_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rtable *rt;
struct iphdr *iph = ip_hdr(skb);
int mtu;
EnterFunction(10);
if (!(rt = __ip_vs_get_out_rt(skb, NULL, iph->daddr, RT_TOS(iph->tos),
IP_VS_RT_MODE_NON_LOCAL, NULL)))
goto tx_error_icmp;
mtu = dst_mtu(&rt->dst);
if ((skb->len > mtu) && (iph->frag_off & htons(IP_DF)) &&
!skb_is_gso(skb)) {
ip_rt_put(rt);
icmp_send(skb, ICMP_DEST_UNREACH,ICMP_FRAG_NEEDED, htonl(mtu));
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error;
}
if (unlikely((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL)) {
ip_rt_put(rt);
return NF_STOLEN;
}
ip_send_check(ip_hdr(skb));
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
skb->local_df = 1;
IP_VS_XMIT(NFPROTO_IPV4, skb, cp, 0);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_bypass_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rt6_info *rt;
struct ipv6hdr *iph = ipv6_hdr(skb);
int mtu;
EnterFunction(10);
if (!(rt = __ip_vs_get_out_rt_v6(skb, NULL, &iph->daddr, NULL, 0,
IP_VS_RT_MODE_NON_LOCAL)))
goto tx_error_icmp;
mtu = dst_mtu(&rt->dst);
if (skb->len > mtu && !skb_is_gso(skb)) {
if (!skb->dev) {
struct net *net = dev_net(skb_dst(skb)->dev);
skb->dev = net->loopback_dev;
}
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
dst_release(&rt->dst);
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error;
}
skb = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(skb == NULL)) {
dst_release(&rt->dst);
return NF_STOLEN;
}
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
skb->local_df = 1;
IP_VS_XMIT(NFPROTO_IPV6, skb, cp, 0);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_nat_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rtable *rt;
int mtu;
struct iphdr *iph = ip_hdr(skb);
int local;
EnterFunction(10);
if (unlikely(cp->flags & IP_VS_CONN_F_NO_CPORT)) {
__be16 _pt, *p;
p = skb_header_pointer(skb, iph->ihl*4, sizeof(_pt), &_pt);
if (p == NULL)
goto tx_error;
ip_vs_conn_fill_cport(cp, *p);
IP_VS_DBG(10, "filled cport=%d\n", ntohs(*p));
}
if (!(rt = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip,
RT_TOS(iph->tos),
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR, NULL)))
goto tx_error_icmp;
local = rt->rt_flags & RTCF_LOCAL;
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG_RL_PKT(10, AF_INET, pp, skb, 0,
"ip_vs_nat_xmit(): "
"stopping DNAT to local address");
goto tx_error_put;
}
}
#endif
if (local && ipv4_is_loopback(cp->daddr.ip) &&
rt_is_input_route(skb_rtable(skb))) {
IP_VS_DBG_RL_PKT(1, AF_INET, pp, skb, 0, "ip_vs_nat_xmit(): "
"stopping DNAT to loopback address");
goto tx_error_put;
}
mtu = dst_mtu(&rt->dst);
if ((skb->len > mtu) && (iph->frag_off & htons(IP_DF)) &&
!skb_is_gso(skb)) {
icmp_send(skb, ICMP_DEST_UNREACH,ICMP_FRAG_NEEDED, htonl(mtu));
IP_VS_DBG_RL_PKT(0, AF_INET, pp, skb, 0,
"ip_vs_nat_xmit(): frag needed for");
goto tx_error_put;
}
if (!skb_make_writable(skb, sizeof(struct iphdr)))
goto tx_error_put;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error_put;
if (pp->dnat_handler && !pp->dnat_handler(skb, pp, cp))
goto tx_error_put;
ip_hdr(skb)->daddr = cp->daddr.ip;
ip_send_check(ip_hdr(skb));
if (!local) {
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
} else {
ip_rt_put(rt);
if (!__ip_vs_reroute_locally(skb))
goto tx_error;
}
IP_VS_DBG_PKT(10, AF_INET, pp, skb, 0, "After DNAT");
skb->local_df = 1;
IP_VS_XMIT_NAT(NFPROTO_IPV4, skb, cp, local);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
tx_error_put:
ip_rt_put(rt);
goto tx_error;
}
int
ip_vs_nat_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rt6_info *rt;
int mtu;
int local;
EnterFunction(10);
if (unlikely(cp->flags & IP_VS_CONN_F_NO_CPORT)) {
__be16 _pt, *p;
p = skb_header_pointer(skb, sizeof(struct ipv6hdr),
sizeof(_pt), &_pt);
if (p == NULL)
goto tx_error;
ip_vs_conn_fill_cport(cp, *p);
IP_VS_DBG(10, "filled cport=%d\n", ntohs(*p));
}
if (!(rt = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6, NULL,
0, (IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR))))
goto tx_error_icmp;
local = __ip_vs_is_local_route6(rt);
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG_RL_PKT(10, AF_INET6, pp, skb, 0,
"ip_vs_nat_xmit_v6(): "
"stopping DNAT to local address");
goto tx_error_put;
}
}
#endif
if (local && skb->dev && !(skb->dev->flags & IFF_LOOPBACK) &&
ipv6_addr_type(&rt->rt6i_dst.addr) & IPV6_ADDR_LOOPBACK) {
IP_VS_DBG_RL_PKT(1, AF_INET6, pp, skb, 0,
"ip_vs_nat_xmit_v6(): "
"stopping DNAT to loopback address");
goto tx_error_put;
}
mtu = dst_mtu(&rt->dst);
if (skb->len > mtu && !skb_is_gso(skb)) {
if (!skb->dev) {
struct net *net = dev_net(skb_dst(skb)->dev);
skb->dev = net->loopback_dev;
}
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
IP_VS_DBG_RL_PKT(0, AF_INET6, pp, skb, 0,
"ip_vs_nat_xmit_v6(): frag needed for");
goto tx_error_put;
}
if (!skb_make_writable(skb, sizeof(struct ipv6hdr)))
goto tx_error_put;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error_put;
if (pp->dnat_handler && !pp->dnat_handler(skb, pp, cp))
goto tx_error;
ipv6_hdr(skb)->daddr = cp->daddr.in6;
if (!local || !skb->dev) {
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
} else {
dst_release(&rt->dst);
}
IP_VS_DBG_PKT(10, AF_INET6, pp, skb, 0, "After DNAT");
skb->local_df = 1;
IP_VS_XMIT_NAT(NFPROTO_IPV6, skb, cp, local);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
LeaveFunction(10);
kfree_skb(skb);
return NF_STOLEN;
tx_error_put:
dst_release(&rt->dst);
goto tx_error;
}
int
ip_vs_tunnel_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rtable *rt;
__be32 saddr;
struct net_device *tdev;
struct iphdr *old_iph = ip_hdr(skb);
u8 tos = old_iph->tos;
__be16 df = old_iph->frag_off;
struct iphdr *iph;
unsigned int max_headroom;
int mtu;
int ret;
EnterFunction(10);
if (!(rt = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip,
RT_TOS(tos), IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL,
&saddr)))
goto tx_error_icmp;
if (rt->rt_flags & RTCF_LOCAL) {
ip_rt_put(rt);
IP_VS_XMIT(NFPROTO_IPV4, skb, cp, 1);
}
tdev = rt->dst.dev;
mtu = dst_mtu(&rt->dst) - sizeof(struct iphdr);
if (mtu < 68) {
IP_VS_DBG_RL("%s(): mtu less than 68\n", __func__);
goto tx_error_put;
}
if (skb_dst(skb))
skb_dst(skb)->ops->update_pmtu(skb_dst(skb), mtu);
df |= (old_iph->frag_off & htons(IP_DF));
if ((old_iph->frag_off & htons(IP_DF) &&
mtu < ntohs(old_iph->tot_len) && !skb_is_gso(skb))) {
icmp_send(skb, ICMP_DEST_UNREACH,ICMP_FRAG_NEEDED, htonl(mtu));
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error_put;
}
max_headroom = LL_RESERVED_SPACE(tdev) + sizeof(struct iphdr);
if (skb_headroom(skb) < max_headroom
|| skb_cloned(skb) || skb_shared(skb)) {
struct sk_buff *new_skb =
skb_realloc_headroom(skb, max_headroom);
if (!new_skb) {
ip_rt_put(rt);
kfree_skb(skb);
IP_VS_ERR_RL("%s(): no memory\n", __func__);
return NF_STOLEN;
}
kfree_skb(skb);
skb = new_skb;
old_iph = ip_hdr(skb);
}
skb->transport_header = skb->network_header;
ip_send_check(old_iph);
skb_push(skb, sizeof(struct iphdr));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
iph = ip_hdr(skb);
iph->version = 4;
iph->ihl = sizeof(struct iphdr)>>2;
iph->frag_off = df;
iph->protocol = IPPROTO_IPIP;
iph->tos = tos;
iph->daddr = cp->daddr.ip;
iph->saddr = saddr;
iph->ttl = old_iph->ttl;
ip_select_ident(iph, &rt->dst, NULL);
skb->local_df = 1;
ret = IP_VS_XMIT_TUNNEL(skb, cp);
if (ret == NF_ACCEPT)
ip_local_out(skb);
else if (ret == NF_DROP)
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
tx_error_put:
ip_rt_put(rt);
goto tx_error;
}
int
ip_vs_tunnel_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rt6_info *rt;
struct in6_addr saddr;
struct net_device *tdev;
struct ipv6hdr *old_iph = ipv6_hdr(skb);
struct ipv6hdr *iph;
unsigned int max_headroom;
int mtu;
int ret;
EnterFunction(10);
if (!(rt = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6,
&saddr, 1, (IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL))))
goto tx_error_icmp;
if (__ip_vs_is_local_route6(rt)) {
dst_release(&rt->dst);
IP_VS_XMIT(NFPROTO_IPV6, skb, cp, 1);
}
tdev = rt->dst.dev;
mtu = dst_mtu(&rt->dst) - sizeof(struct ipv6hdr);
if (mtu < IPV6_MIN_MTU) {
IP_VS_DBG_RL("%s(): mtu less than %d\n", __func__,
IPV6_MIN_MTU);
goto tx_error_put;
}
if (skb_dst(skb))
skb_dst(skb)->ops->update_pmtu(skb_dst(skb), mtu);
if (mtu < ntohs(old_iph->payload_len) + sizeof(struct ipv6hdr) &&
!skb_is_gso(skb)) {
if (!skb->dev) {
struct net *net = dev_net(skb_dst(skb)->dev);
skb->dev = net->loopback_dev;
}
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error_put;
}
max_headroom = LL_RESERVED_SPACE(tdev) + sizeof(struct ipv6hdr);
if (skb_headroom(skb) < max_headroom
|| skb_cloned(skb) || skb_shared(skb)) {
struct sk_buff *new_skb =
skb_realloc_headroom(skb, max_headroom);
if (!new_skb) {
dst_release(&rt->dst);
kfree_skb(skb);
IP_VS_ERR_RL("%s(): no memory\n", __func__);
return NF_STOLEN;
}
kfree_skb(skb);
skb = new_skb;
old_iph = ipv6_hdr(skb);
}
skb->transport_header = skb->network_header;
skb_push(skb, sizeof(struct ipv6hdr));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
iph = ipv6_hdr(skb);
iph->version = 6;
iph->nexthdr = IPPROTO_IPV6;
iph->payload_len = old_iph->payload_len;
be16_add_cpu(&iph->payload_len, sizeof(*old_iph));
iph->priority = old_iph->priority;
memset(&iph->flow_lbl, 0, sizeof(iph->flow_lbl));
iph->daddr = cp->daddr.in6;
iph->saddr = saddr;
iph->hop_limit = old_iph->hop_limit;
skb->local_df = 1;
ret = IP_VS_XMIT_TUNNEL(skb, cp);
if (ret == NF_ACCEPT)
ip6_local_out(skb);
else if (ret == NF_DROP)
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
tx_error_put:
dst_release(&rt->dst);
goto tx_error;
}
int
ip_vs_dr_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rtable *rt;
struct iphdr *iph = ip_hdr(skb);
int mtu;
EnterFunction(10);
if (!(rt = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip,
RT_TOS(iph->tos),
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL, NULL)))
goto tx_error_icmp;
if (rt->rt_flags & RTCF_LOCAL) {
ip_rt_put(rt);
IP_VS_XMIT(NFPROTO_IPV4, skb, cp, 1);
}
mtu = dst_mtu(&rt->dst);
if ((iph->frag_off & htons(IP_DF)) && skb->len > mtu &&
!skb_is_gso(skb)) {
icmp_send(skb, ICMP_DEST_UNREACH,ICMP_FRAG_NEEDED, htonl(mtu));
ip_rt_put(rt);
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error;
}
if (unlikely((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL)) {
ip_rt_put(rt);
return NF_STOLEN;
}
ip_send_check(ip_hdr(skb));
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
skb->local_df = 1;
IP_VS_XMIT(NFPROTO_IPV4, skb, cp, 0);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_dr_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp)
{
struct rt6_info *rt;
int mtu;
EnterFunction(10);
if (!(rt = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6, NULL,
0, (IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL))))
goto tx_error_icmp;
if (__ip_vs_is_local_route6(rt)) {
dst_release(&rt->dst);
IP_VS_XMIT(NFPROTO_IPV6, skb, cp, 1);
}
mtu = dst_mtu(&rt->dst);
if (skb->len > mtu) {
if (!skb->dev) {
struct net *net = dev_net(skb_dst(skb)->dev);
skb->dev = net->loopback_dev;
}
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
dst_release(&rt->dst);
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error;
}
skb = skb_share_check(skb, GFP_ATOMIC);
if (unlikely(skb == NULL)) {
dst_release(&rt->dst);
return NF_STOLEN;
}
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
skb->local_df = 1;
IP_VS_XMIT(NFPROTO_IPV6, skb, cp, 0);
LeaveFunction(10);
return NF_STOLEN;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
kfree_skb(skb);
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_icmp_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, int offset, unsigned int hooknum)
{
struct rtable *rt;
int mtu;
int rc;
int local;
int rt_mode;
EnterFunction(10);
if (IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ) {
if (cp->packet_xmit)
rc = cp->packet_xmit(skb, cp, pp);
else
rc = NF_ACCEPT;
atomic_inc(&cp->in_pkts);
goto out;
}
rt_mode = (hooknum != NF_INET_FORWARD) ?
IP_VS_RT_MODE_LOCAL | IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR : IP_VS_RT_MODE_NON_LOCAL;
if (!(rt = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip,
RT_TOS(ip_hdr(skb)->tos),
rt_mode, NULL)))
goto tx_error_icmp;
local = rt->rt_flags & RTCF_LOCAL;
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG(10, "%s(): "
"stopping DNAT to local address %pI4\n",
__func__, &cp->daddr.ip);
goto tx_error_put;
}
}
#endif
if (local && ipv4_is_loopback(cp->daddr.ip) &&
rt_is_input_route(skb_rtable(skb))) {
IP_VS_DBG(1, "%s(): "
"stopping DNAT to loopback %pI4\n",
__func__, &cp->daddr.ip);
goto tx_error_put;
}
mtu = dst_mtu(&rt->dst);
if ((skb->len > mtu) && (ip_hdr(skb)->frag_off & htons(IP_DF)) &&
!skb_is_gso(skb)) {
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED, htonl(mtu));
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error_put;
}
if (!skb_make_writable(skb, offset))
goto tx_error_put;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error_put;
ip_vs_nat_icmp(skb, pp, cp, 0);
if (!local) {
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
} else {
ip_rt_put(rt);
if (!__ip_vs_reroute_locally(skb))
goto tx_error;
}
skb->local_df = 1;
IP_VS_XMIT_NAT(NFPROTO_IPV4, skb, cp, local);
rc = NF_STOLEN;
goto out;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
dev_kfree_skb(skb);
rc = NF_STOLEN;
out:
LeaveFunction(10);
return rc;
tx_error_put:
ip_rt_put(rt);
goto tx_error;
}
int
ip_vs_icmp_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, int offset, unsigned int hooknum)
{
struct rt6_info *rt;
int mtu;
int rc;
int local;
int rt_mode;
EnterFunction(10);
if (IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ) {
if (cp->packet_xmit)
rc = cp->packet_xmit(skb, cp, pp);
else
rc = NF_ACCEPT;
atomic_inc(&cp->in_pkts);
goto out;
}
rt_mode = (hooknum != NF_INET_FORWARD) ?
IP_VS_RT_MODE_LOCAL | IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR : IP_VS_RT_MODE_NON_LOCAL;
if (!(rt = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6, NULL,
0, rt_mode)))
goto tx_error_icmp;
local = __ip_vs_is_local_route6(rt);
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG(10, "%s(): "
"stopping DNAT to local address %pI6\n",
__func__, &cp->daddr.in6);
goto tx_error_put;
}
}
#endif
if (local && skb->dev && !(skb->dev->flags & IFF_LOOPBACK) &&
ipv6_addr_type(&rt->rt6i_dst.addr) & IPV6_ADDR_LOOPBACK) {
IP_VS_DBG(1, "%s(): "
"stopping DNAT to loopback %pI6\n",
__func__, &cp->daddr.in6);
goto tx_error_put;
}
mtu = dst_mtu(&rt->dst);
if (skb->len > mtu && !skb_is_gso(skb)) {
if (!skb->dev) {
struct net *net = dev_net(skb_dst(skb)->dev);
skb->dev = net->loopback_dev;
}
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
IP_VS_DBG_RL("%s(): frag needed\n", __func__);
goto tx_error_put;
}
if (!skb_make_writable(skb, offset))
goto tx_error_put;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error_put;
ip_vs_nat_icmp_v6(skb, pp, cp, 0);
if (!local || !skb->dev) {
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
} else {
dst_release(&rt->dst);
}
skb->local_df = 1;
IP_VS_XMIT_NAT(NFPROTO_IPV6, skb, cp, local);
rc = NF_STOLEN;
goto out;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
dev_kfree_skb(skb);
rc = NF_STOLEN;
out:
LeaveFunction(10);
return rc;
tx_error_put:
dst_release(&rt->dst);
goto tx_error;
}
