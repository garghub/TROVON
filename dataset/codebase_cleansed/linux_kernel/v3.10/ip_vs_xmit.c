static inline struct ip_vs_dest_dst *ip_vs_dest_dst_alloc(void)
{
return kmalloc(sizeof(struct ip_vs_dest_dst), GFP_ATOMIC);
}
static inline void ip_vs_dest_dst_free(struct ip_vs_dest_dst *dest_dst)
{
kfree(dest_dst);
}
static inline void
__ip_vs_dst_set(struct ip_vs_dest *dest, struct ip_vs_dest_dst *dest_dst,
struct dst_entry *dst, u32 dst_cookie)
{
struct ip_vs_dest_dst *old;
old = rcu_dereference_protected(dest->dest_dst,
lockdep_is_held(&dest->dst_lock));
if (dest_dst) {
dest_dst->dst_cache = dst;
dest_dst->dst_cookie = dst_cookie;
}
rcu_assign_pointer(dest->dest_dst, dest_dst);
if (old)
call_rcu(&old->rcu_head, ip_vs_dest_dst_rcu_free);
}
static inline struct ip_vs_dest_dst *
__ip_vs_dst_check(struct ip_vs_dest *dest)
{
struct ip_vs_dest_dst *dest_dst = rcu_dereference(dest->dest_dst);
struct dst_entry *dst;
if (!dest_dst)
return NULL;
dst = dest_dst->dst_cache;
if (dst->obsolete &&
dst->ops->check(dst, dest_dst->dst_cookie) == NULL)
return NULL;
return dest_dst;
}
static inline bool
__mtu_check_toobig_v6(const struct sk_buff *skb, u32 mtu)
{
if (IP6CB(skb)->frag_max_size) {
if (IP6CB(skb)->frag_max_size > mtu)
return true;
}
else if (skb->len > mtu && !skb_is_gso(skb)) {
return true;
}
return false;
}
static struct rtable *do_output_route4(struct net *net, __be32 daddr,
int rt_mode, __be32 *saddr)
{
struct flowi4 fl4;
struct rtable *rt;
int loop = 0;
memset(&fl4, 0, sizeof(fl4));
fl4.daddr = daddr;
fl4.saddr = (rt_mode & IP_VS_RT_MODE_CONNECT) ? *saddr : 0;
fl4.flowi4_flags = (rt_mode & IP_VS_RT_MODE_KNOWN_NH) ?
FLOWI_FLAG_KNOWN_NH : 0;
retry:
rt = ip_route_output_key(net, &fl4);
if (IS_ERR(rt)) {
if (PTR_ERR(rt) == -EINVAL && *saddr &&
rt_mode & IP_VS_RT_MODE_CONNECT && !loop) {
*saddr = 0;
flowi4_update_output(&fl4, 0, 0, daddr, 0);
goto retry;
}
IP_VS_DBG_RL("ip_route_output error, dest: %pI4\n", &daddr);
return NULL;
} else if (!*saddr && rt_mode & IP_VS_RT_MODE_CONNECT && fl4.saddr) {
ip_rt_put(rt);
*saddr = fl4.saddr;
flowi4_update_output(&fl4, 0, 0, daddr, fl4.saddr);
loop++;
goto retry;
}
*saddr = fl4.saddr;
return rt;
}
static int
__ip_vs_get_out_rt(struct sk_buff *skb, struct ip_vs_dest *dest,
__be32 daddr, int rt_mode, __be32 *ret_saddr)
{
struct net *net = dev_net(skb_dst(skb)->dev);
struct netns_ipvs *ipvs = net_ipvs(net);
struct ip_vs_dest_dst *dest_dst;
struct rtable *rt;
struct rtable *ort;
struct iphdr *iph;
__be16 df;
int mtu;
int local, noref = 1;
if (dest) {
dest_dst = __ip_vs_dst_check(dest);
if (likely(dest_dst))
rt = (struct rtable *) dest_dst->dst_cache;
else {
dest_dst = ip_vs_dest_dst_alloc();
spin_lock_bh(&dest->dst_lock);
if (!dest_dst) {
__ip_vs_dst_set(dest, NULL, NULL, 0);
spin_unlock_bh(&dest->dst_lock);
goto err_unreach;
}
rt = do_output_route4(net, dest->addr.ip, rt_mode,
&dest_dst->dst_saddr.ip);
if (!rt) {
__ip_vs_dst_set(dest, NULL, NULL, 0);
spin_unlock_bh(&dest->dst_lock);
ip_vs_dest_dst_free(dest_dst);
goto err_unreach;
}
__ip_vs_dst_set(dest, dest_dst, &rt->dst, 0);
spin_unlock_bh(&dest->dst_lock);
IP_VS_DBG(10, "new dst %pI4, src %pI4, refcnt=%d\n",
&dest->addr.ip, &dest_dst->dst_saddr.ip,
atomic_read(&rt->dst.__refcnt));
}
daddr = dest->addr.ip;
if (ret_saddr)
*ret_saddr = dest_dst->dst_saddr.ip;
} else {
__be32 saddr = htonl(INADDR_ANY);
noref = 0;
rt_mode &= ~IP_VS_RT_MODE_CONNECT;
rt = do_output_route4(net, daddr, rt_mode, &saddr);
if (!rt)
goto err_unreach;
if (ret_saddr)
*ret_saddr = saddr;
}
local = (rt->rt_flags & RTCF_LOCAL) ? 1 : 0;
if (!((local ? IP_VS_RT_MODE_LOCAL : IP_VS_RT_MODE_NON_LOCAL) &
rt_mode)) {
IP_VS_DBG_RL("Stopping traffic to %s address, dest: %pI4\n",
(rt->rt_flags & RTCF_LOCAL) ?
"local":"non-local", &daddr);
goto err_put;
}
iph = ip_hdr(skb);
if (likely(!local)) {
if (unlikely(ipv4_is_loopback(iph->saddr))) {
IP_VS_DBG_RL("Stopping traffic from loopback address "
"%pI4 to non-local address, dest: %pI4\n",
&iph->saddr, &daddr);
goto err_put;
}
} else {
ort = skb_rtable(skb);
if (!(rt_mode & IP_VS_RT_MODE_RDR) &&
!(ort->rt_flags & RTCF_LOCAL)) {
IP_VS_DBG_RL("Redirect from non-local address %pI4 to "
"local requires NAT method, dest: %pI4\n",
&iph->daddr, &daddr);
goto err_put;
}
if (!noref)
ip_rt_put(rt);
return local;
}
if (likely(!(rt_mode & IP_VS_RT_MODE_TUNNEL))) {
mtu = dst_mtu(&rt->dst);
df = iph->frag_off & htons(IP_DF);
} else {
struct sock *sk = skb->sk;
mtu = dst_mtu(&rt->dst) - sizeof(struct iphdr);
if (mtu < 68) {
IP_VS_DBG_RL("%s(): mtu less than 68\n", __func__);
goto err_put;
}
ort = skb_rtable(skb);
if (!skb->dev && sk && sk->sk_state != TCP_TIME_WAIT)
ort->dst.ops->update_pmtu(&ort->dst, sk, NULL, mtu);
df = sysctl_pmtu_disc(ipvs) ? iph->frag_off & htons(IP_DF) : 0;
}
if (unlikely(df && skb->len > mtu && !skb_is_gso(skb))) {
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED, htonl(mtu));
IP_VS_DBG(1, "frag needed for %pI4\n", &iph->saddr);
goto err_put;
}
skb_dst_drop(skb);
if (noref) {
if (!local)
skb_dst_set_noref_force(skb, &rt->dst);
else
skb_dst_set(skb, dst_clone(&rt->dst));
} else
skb_dst_set(skb, &rt->dst);
return local;
err_put:
if (!noref)
ip_rt_put(rt);
return -1;
err_unreach:
dst_link_failure(skb);
return -1;
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
static int
__ip_vs_get_out_rt_v6(struct sk_buff *skb, struct ip_vs_dest *dest,
struct in6_addr *daddr, struct in6_addr *ret_saddr,
struct ip_vs_iphdr *ipvsh, int do_xfrm, int rt_mode)
{
struct net *net = dev_net(skb_dst(skb)->dev);
struct ip_vs_dest_dst *dest_dst;
struct rt6_info *rt;
struct rt6_info *ort;
struct dst_entry *dst;
int mtu;
int local, noref = 1;
if (dest) {
dest_dst = __ip_vs_dst_check(dest);
if (likely(dest_dst))
rt = (struct rt6_info *) dest_dst->dst_cache;
else {
u32 cookie;
dest_dst = ip_vs_dest_dst_alloc();
spin_lock_bh(&dest->dst_lock);
if (!dest_dst) {
__ip_vs_dst_set(dest, NULL, NULL, 0);
spin_unlock_bh(&dest->dst_lock);
goto err_unreach;
}
dst = __ip_vs_route_output_v6(net, &dest->addr.in6,
&dest_dst->dst_saddr.in6,
do_xfrm);
if (!dst) {
__ip_vs_dst_set(dest, NULL, NULL, 0);
spin_unlock_bh(&dest->dst_lock);
ip_vs_dest_dst_free(dest_dst);
goto err_unreach;
}
rt = (struct rt6_info *) dst;
cookie = rt->rt6i_node ? rt->rt6i_node->fn_sernum : 0;
__ip_vs_dst_set(dest, dest_dst, &rt->dst, cookie);
spin_unlock_bh(&dest->dst_lock);
IP_VS_DBG(10, "new dst %pI6, src %pI6, refcnt=%d\n",
&dest->addr.in6, &dest_dst->dst_saddr.in6,
atomic_read(&rt->dst.__refcnt));
}
if (ret_saddr)
*ret_saddr = dest_dst->dst_saddr.in6;
} else {
noref = 0;
dst = __ip_vs_route_output_v6(net, daddr, ret_saddr, do_xfrm);
if (!dst)
goto err_unreach;
rt = (struct rt6_info *) dst;
}
local = __ip_vs_is_local_route6(rt);
if (!((local ? IP_VS_RT_MODE_LOCAL : IP_VS_RT_MODE_NON_LOCAL) &
rt_mode)) {
IP_VS_DBG_RL("Stopping traffic to %s address, dest: %pI6c\n",
local ? "local":"non-local", daddr);
goto err_put;
}
if (likely(!local)) {
if (unlikely((!skb->dev || skb->dev->flags & IFF_LOOPBACK) &&
ipv6_addr_type(&ipv6_hdr(skb)->saddr) &
IPV6_ADDR_LOOPBACK)) {
IP_VS_DBG_RL("Stopping traffic from loopback address "
"%pI6c to non-local address, "
"dest: %pI6c\n",
&ipv6_hdr(skb)->saddr, daddr);
goto err_put;
}
} else {
ort = (struct rt6_info *) skb_dst(skb);
if (!(rt_mode & IP_VS_RT_MODE_RDR) &&
!__ip_vs_is_local_route6(ort)) {
IP_VS_DBG_RL("Redirect from non-local address %pI6c "
"to local requires NAT method, "
"dest: %pI6c\n",
&ipv6_hdr(skb)->daddr, daddr);
goto err_put;
}
if (!noref)
dst_release(&rt->dst);
return local;
}
if (likely(!(rt_mode & IP_VS_RT_MODE_TUNNEL)))
mtu = dst_mtu(&rt->dst);
else {
struct sock *sk = skb->sk;
mtu = dst_mtu(&rt->dst) - sizeof(struct ipv6hdr);
if (mtu < IPV6_MIN_MTU) {
IP_VS_DBG_RL("%s(): mtu less than %d\n", __func__,
IPV6_MIN_MTU);
goto err_put;
}
ort = (struct rt6_info *) skb_dst(skb);
if (!skb->dev && sk && sk->sk_state != TCP_TIME_WAIT)
ort->dst.ops->update_pmtu(&ort->dst, sk, NULL, mtu);
}
if (unlikely(__mtu_check_toobig_v6(skb, mtu))) {
if (!skb->dev)
skb->dev = net->loopback_dev;
if (!ipvsh->fragoffs)
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
IP_VS_DBG(1, "frag needed for %pI6c\n", &ipv6_hdr(skb)->saddr);
goto err_put;
}
skb_dst_drop(skb);
if (noref) {
if (!local)
skb_dst_set_noref_force(skb, &rt->dst);
else
skb_dst_set(skb, dst_clone(&rt->dst));
} else
skb_dst_set(skb, &rt->dst);
return local;
err_put:
if (!noref)
dst_release(&rt->dst);
return -1;
err_unreach:
dst_link_failure(skb);
return -1;
}
static inline int ip_vs_tunnel_xmit_prepare(struct sk_buff *skb,
struct ip_vs_conn *cp)
{
int ret = NF_ACCEPT;
skb->ipvs_property = 1;
if (unlikely(cp->flags & IP_VS_CONN_F_NFCT))
ret = ip_vs_confirm_conntrack(skb);
if (ret == NF_ACCEPT) {
nf_reset(skb);
skb_forward_csum(skb);
}
return ret;
}
static inline int ip_vs_nat_send_or_cont(int pf, struct sk_buff *skb,
struct ip_vs_conn *cp, int local)
{
int ret = NF_STOLEN;
skb->ipvs_property = 1;
if (likely(!(cp->flags & IP_VS_CONN_F_NFCT)))
ip_vs_notrack(skb);
else
ip_vs_update_conntrack(skb, cp, 1);
if (!local) {
skb_forward_csum(skb);
NF_HOOK(pf, NF_INET_LOCAL_OUT, skb, NULL, skb_dst(skb)->dev,
dst_output);
} else
ret = NF_ACCEPT;
return ret;
}
static inline int ip_vs_send_or_cont(int pf, struct sk_buff *skb,
struct ip_vs_conn *cp, int local)
{
int ret = NF_STOLEN;
skb->ipvs_property = 1;
if (likely(!(cp->flags & IP_VS_CONN_F_NFCT)))
ip_vs_notrack(skb);
if (!local) {
skb_forward_csum(skb);
NF_HOOK(pf, NF_INET_LOCAL_OUT, skb, NULL, skb_dst(skb)->dev,
dst_output);
} else
ret = NF_ACCEPT;
return ret;
}
int
ip_vs_null_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
return ip_vs_send_or_cont(NFPROTO_IPV4, skb, cp, 1);
}
int
ip_vs_bypass_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
struct iphdr *iph = ip_hdr(skb);
EnterFunction(10);
rcu_read_lock();
if (__ip_vs_get_out_rt(skb, NULL, iph->daddr, IP_VS_RT_MODE_NON_LOCAL,
NULL) < 0)
goto tx_error;
ip_send_check(iph);
skb->local_df = 1;
ip_vs_send_or_cont(NFPROTO_IPV4, skb, cp, 0);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_bypass_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
EnterFunction(10);
rcu_read_lock();
if (__ip_vs_get_out_rt_v6(skb, NULL, &ipvsh->daddr.in6, NULL,
ipvsh, 0, IP_VS_RT_MODE_NON_LOCAL) < 0)
goto tx_error;
skb->local_df = 1;
ip_vs_send_or_cont(NFPROTO_IPV6, skb, cp, 0);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_nat_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
struct rtable *rt;
int local, rc, was_input;
EnterFunction(10);
rcu_read_lock();
if (unlikely(cp->flags & IP_VS_CONN_F_NO_CPORT)) {
__be16 _pt, *p;
p = skb_header_pointer(skb, ipvsh->len, sizeof(_pt), &_pt);
if (p == NULL)
goto tx_error;
ip_vs_conn_fill_cport(cp, *p);
IP_VS_DBG(10, "filled cport=%d\n", ntohs(*p));
}
was_input = rt_is_input_route(skb_rtable(skb));
local = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR, NULL);
if (local < 0)
goto tx_error;
rt = skb_rtable(skb);
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG_RL_PKT(10, AF_INET, pp, skb, 0,
"ip_vs_nat_xmit(): "
"stopping DNAT to local address");
goto tx_error;
}
}
#endif
if (local && ipv4_is_loopback(cp->daddr.ip) && was_input) {
IP_VS_DBG_RL_PKT(1, AF_INET, pp, skb, 0, "ip_vs_nat_xmit(): "
"stopping DNAT to loopback address");
goto tx_error;
}
if (!skb_make_writable(skb, sizeof(struct iphdr)))
goto tx_error;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error;
if (pp->dnat_handler && !pp->dnat_handler(skb, pp, cp, ipvsh))
goto tx_error;
ip_hdr(skb)->daddr = cp->daddr.ip;
ip_send_check(ip_hdr(skb));
IP_VS_DBG_PKT(10, AF_INET, pp, skb, 0, "After DNAT");
skb->local_df = 1;
rc = ip_vs_nat_send_or_cont(NFPROTO_IPV4, skb, cp, local);
rcu_read_unlock();
LeaveFunction(10);
return rc;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_nat_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
struct rt6_info *rt;
int local, rc;
EnterFunction(10);
rcu_read_lock();
if (unlikely(cp->flags & IP_VS_CONN_F_NO_CPORT && !ipvsh->fragoffs)) {
__be16 _pt, *p;
p = skb_header_pointer(skb, ipvsh->len, sizeof(_pt), &_pt);
if (p == NULL)
goto tx_error;
ip_vs_conn_fill_cport(cp, *p);
IP_VS_DBG(10, "filled cport=%d\n", ntohs(*p));
}
local = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6, NULL,
ipvsh, 0,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR);
if (local < 0)
goto tx_error;
rt = (struct rt6_info *) skb_dst(skb);
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG_RL_PKT(10, AF_INET6, pp, skb, 0,
"ip_vs_nat_xmit_v6(): "
"stopping DNAT to local address");
goto tx_error;
}
}
#endif
if (local && skb->dev && !(skb->dev->flags & IFF_LOOPBACK) &&
ipv6_addr_type(&rt->rt6i_dst.addr) & IPV6_ADDR_LOOPBACK) {
IP_VS_DBG_RL_PKT(1, AF_INET6, pp, skb, 0,
"ip_vs_nat_xmit_v6(): "
"stopping DNAT to loopback address");
goto tx_error;
}
if (!skb_make_writable(skb, sizeof(struct ipv6hdr)))
goto tx_error;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error;
if (pp->dnat_handler && !pp->dnat_handler(skb, pp, cp, ipvsh))
goto tx_error;
ipv6_hdr(skb)->daddr = cp->daddr.in6;
IP_VS_DBG_PKT(10, AF_INET6, pp, skb, 0, "After DNAT");
skb->local_df = 1;
rc = ip_vs_nat_send_or_cont(NFPROTO_IPV6, skb, cp, local);
rcu_read_unlock();
LeaveFunction(10);
return rc;
tx_error:
LeaveFunction(10);
kfree_skb(skb);
rcu_read_unlock();
return NF_STOLEN;
}
int
ip_vs_tunnel_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
struct netns_ipvs *ipvs = net_ipvs(skb_net(skb));
struct rtable *rt;
__be32 saddr;
struct net_device *tdev;
struct iphdr *old_iph = ip_hdr(skb);
u8 tos = old_iph->tos;
__be16 df;
struct iphdr *iph;
unsigned int max_headroom;
int ret, local;
EnterFunction(10);
rcu_read_lock();
local = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_CONNECT |
IP_VS_RT_MODE_TUNNEL, &saddr);
if (local < 0)
goto tx_error;
if (local) {
rcu_read_unlock();
return ip_vs_send_or_cont(NFPROTO_IPV4, skb, cp, 1);
}
rt = skb_rtable(skb);
tdev = rt->dst.dev;
df = sysctl_pmtu_disc(ipvs) ? old_iph->frag_off & htons(IP_DF) : 0;
max_headroom = LL_RESERVED_SPACE(tdev) + sizeof(struct iphdr);
if (skb_headroom(skb) < max_headroom || skb_cloned(skb)) {
struct sk_buff *new_skb =
skb_realloc_headroom(skb, max_headroom);
if (!new_skb)
goto tx_error;
consume_skb(skb);
skb = new_skb;
old_iph = ip_hdr(skb);
}
skb->transport_header = skb->network_header;
ip_send_check(old_iph);
skb_push(skb, sizeof(struct iphdr));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
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
ret = ip_vs_tunnel_xmit_prepare(skb, cp);
if (ret == NF_ACCEPT)
ip_local_out(skb);
else if (ret == NF_DROP)
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_tunnel_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
struct rt6_info *rt;
struct in6_addr saddr;
struct net_device *tdev;
struct ipv6hdr *old_iph = ipv6_hdr(skb);
struct ipv6hdr *iph;
unsigned int max_headroom;
int ret, local;
EnterFunction(10);
rcu_read_lock();
local = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6,
&saddr, ipvsh, 1,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_TUNNEL);
if (local < 0)
goto tx_error;
if (local) {
rcu_read_unlock();
return ip_vs_send_or_cont(NFPROTO_IPV6, skb, cp, 1);
}
rt = (struct rt6_info *) skb_dst(skb);
tdev = rt->dst.dev;
max_headroom = LL_RESERVED_SPACE(tdev) + sizeof(struct ipv6hdr);
if (skb_headroom(skb) < max_headroom || skb_cloned(skb)) {
struct sk_buff *new_skb =
skb_realloc_headroom(skb, max_headroom);
if (!new_skb)
goto tx_error;
consume_skb(skb);
skb = new_skb;
old_iph = ipv6_hdr(skb);
}
skb->transport_header = skb->network_header;
skb_push(skb, sizeof(struct ipv6hdr));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
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
ret = ip_vs_tunnel_xmit_prepare(skb, cp);
if (ret == NF_ACCEPT)
ip6_local_out(skb);
else if (ret == NF_DROP)
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_dr_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
int local;
EnterFunction(10);
rcu_read_lock();
local = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_KNOWN_NH, NULL);
if (local < 0)
goto tx_error;
if (local) {
rcu_read_unlock();
return ip_vs_send_or_cont(NFPROTO_IPV4, skb, cp, 1);
}
ip_send_check(ip_hdr(skb));
skb->local_df = 1;
ip_vs_send_or_cont(NFPROTO_IPV4, skb, cp, 0);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_dr_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
int local;
EnterFunction(10);
rcu_read_lock();
local = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6, NULL,
ipvsh, 0,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL);
if (local < 0)
goto tx_error;
if (local) {
rcu_read_unlock();
return ip_vs_send_or_cont(NFPROTO_IPV6, skb, cp, 1);
}
skb->local_df = 1;
ip_vs_send_or_cont(NFPROTO_IPV6, skb, cp, 0);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
}
int
ip_vs_icmp_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, int offset, unsigned int hooknum,
struct ip_vs_iphdr *iph)
{
struct rtable *rt;
int rc;
int local;
int rt_mode, was_input;
EnterFunction(10);
if (IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ) {
if (cp->packet_xmit)
rc = cp->packet_xmit(skb, cp, pp, iph);
else
rc = NF_ACCEPT;
atomic_inc(&cp->in_pkts);
goto out;
}
was_input = rt_is_input_route(skb_rtable(skb));
rt_mode = (hooknum != NF_INET_FORWARD) ?
IP_VS_RT_MODE_LOCAL | IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR : IP_VS_RT_MODE_NON_LOCAL;
rcu_read_lock();
local = __ip_vs_get_out_rt(skb, cp->dest, cp->daddr.ip, rt_mode, NULL);
if (local < 0)
goto tx_error;
rt = skb_rtable(skb);
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG(10, "%s(): "
"stopping DNAT to local address %pI4\n",
__func__, &cp->daddr.ip);
goto tx_error;
}
}
#endif
if (local && ipv4_is_loopback(cp->daddr.ip) && was_input) {
IP_VS_DBG(1, "%s(): "
"stopping DNAT to loopback %pI4\n",
__func__, &cp->daddr.ip);
goto tx_error;
}
if (!skb_make_writable(skb, offset))
goto tx_error;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error;
ip_vs_nat_icmp(skb, pp, cp, 0);
skb->local_df = 1;
rc = ip_vs_nat_send_or_cont(NFPROTO_IPV4, skb, cp, local);
rcu_read_unlock();
goto out;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
rc = NF_STOLEN;
out:
LeaveFunction(10);
return rc;
}
int
ip_vs_icmp_xmit_v6(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, int offset, unsigned int hooknum,
struct ip_vs_iphdr *ipvsh)
{
struct rt6_info *rt;
int rc;
int local;
int rt_mode;
EnterFunction(10);
if (IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ) {
if (cp->packet_xmit)
rc = cp->packet_xmit(skb, cp, pp, ipvsh);
else
rc = NF_ACCEPT;
atomic_inc(&cp->in_pkts);
goto out;
}
rt_mode = (hooknum != NF_INET_FORWARD) ?
IP_VS_RT_MODE_LOCAL | IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR : IP_VS_RT_MODE_NON_LOCAL;
rcu_read_lock();
local = __ip_vs_get_out_rt_v6(skb, cp->dest, &cp->daddr.in6, NULL,
ipvsh, 0, rt_mode);
if (local < 0)
goto tx_error;
rt = (struct rt6_info *) skb_dst(skb);
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG(10, "%s(): "
"stopping DNAT to local address %pI6\n",
__func__, &cp->daddr.in6);
goto tx_error;
}
}
#endif
if (local && skb->dev && !(skb->dev->flags & IFF_LOOPBACK) &&
ipv6_addr_type(&rt->rt6i_dst.addr) & IPV6_ADDR_LOOPBACK) {
IP_VS_DBG(1, "%s(): "
"stopping DNAT to loopback %pI6\n",
__func__, &cp->daddr.in6);
goto tx_error;
}
if (!skb_make_writable(skb, offset))
goto tx_error;
if (skb_cow(skb, rt->dst.dev->hard_header_len))
goto tx_error;
ip_vs_nat_icmp_v6(skb, pp, cp, 0);
skb->local_df = 1;
rc = ip_vs_nat_send_or_cont(NFPROTO_IPV6, skb, cp, local);
rcu_read_unlock();
goto out;
tx_error:
kfree_skb(skb);
rcu_read_unlock();
rc = NF_STOLEN;
out:
LeaveFunction(10);
return rc;
}
