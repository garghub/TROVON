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
static inline int __ip_vs_is_local_route6(struct rt6_info *rt)
{
return rt->dst.dev && rt->dst.dev->flags & IFF_LOOPBACK;
}
static inline bool crosses_local_route_boundary(int skb_af, struct sk_buff *skb,
int rt_mode,
bool new_rt_is_local)
{
bool rt_mode_allow_local = !!(rt_mode & IP_VS_RT_MODE_LOCAL);
bool rt_mode_allow_non_local = !!(rt_mode & IP_VS_RT_MODE_LOCAL);
bool rt_mode_allow_redirect = !!(rt_mode & IP_VS_RT_MODE_RDR);
bool source_is_loopback;
bool old_rt_is_local;
#ifdef CONFIG_IP_VS_IPV6
if (skb_af == AF_INET6) {
int addr_type = ipv6_addr_type(&ipv6_hdr(skb)->saddr);
source_is_loopback =
(!skb->dev || skb->dev->flags & IFF_LOOPBACK) &&
(addr_type & IPV6_ADDR_LOOPBACK);
old_rt_is_local = __ip_vs_is_local_route6(
(struct rt6_info *)skb_dst(skb));
} else
#endif
{
source_is_loopback = ipv4_is_loopback(ip_hdr(skb)->saddr);
old_rt_is_local = skb_rtable(skb)->rt_flags & RTCF_LOCAL;
}
if (unlikely(new_rt_is_local)) {
if (!rt_mode_allow_local)
return true;
if (!rt_mode_allow_redirect && !old_rt_is_local)
return true;
} else {
if (!rt_mode_allow_non_local)
return true;
if (source_is_loopback)
return true;
}
return false;
}
static inline void maybe_update_pmtu(int skb_af, struct sk_buff *skb, int mtu)
{
struct sock *sk = skb->sk;
struct rtable *ort = skb_rtable(skb);
if (!skb->dev && sk && sk_fullsock(sk))
ort->dst.ops->update_pmtu(&ort->dst, sk, NULL, mtu);
}
static inline bool ensure_mtu_is_adequate(struct netns_ipvs *ipvs, int skb_af,
int rt_mode,
struct ip_vs_iphdr *ipvsh,
struct sk_buff *skb, int mtu)
{
#ifdef CONFIG_IP_VS_IPV6
if (skb_af == AF_INET6) {
struct net *net = ipvs->net;
if (unlikely(__mtu_check_toobig_v6(skb, mtu))) {
if (!skb->dev)
skb->dev = net->loopback_dev;
if (!ipvsh->fragoffs && !ip_vs_iph_icmp(ipvsh))
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
IP_VS_DBG(1, "frag needed for %pI6c\n",
&ipv6_hdr(skb)->saddr);
return false;
}
} else
#endif
{
if ((rt_mode & IP_VS_RT_MODE_TUNNEL) && !sysctl_pmtu_disc(ipvs))
return true;
if (unlikely(ip_hdr(skb)->frag_off & htons(IP_DF) &&
skb->len > mtu && !skb_is_gso(skb) &&
!ip_vs_iph_icmp(ipvsh))) {
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED,
htonl(mtu));
IP_VS_DBG(1, "frag needed for %pI4\n",
&ip_hdr(skb)->saddr);
return false;
}
}
return true;
}
static int
__ip_vs_get_out_rt(struct netns_ipvs *ipvs, int skb_af, struct sk_buff *skb,
struct ip_vs_dest *dest,
__be32 daddr, int rt_mode, __be32 *ret_saddr,
struct ip_vs_iphdr *ipvsh)
{
struct net *net = ipvs->net;
struct ip_vs_dest_dst *dest_dst;
struct rtable *rt;
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
if (unlikely(crosses_local_route_boundary(skb_af, skb, rt_mode,
local))) {
IP_VS_DBG_RL("We are crossing local and non-local addresses"
" daddr=%pI4\n", &daddr);
goto err_put;
}
if (unlikely(local)) {
if (!noref)
ip_rt_put(rt);
return local;
}
if (likely(!(rt_mode & IP_VS_RT_MODE_TUNNEL))) {
mtu = dst_mtu(&rt->dst);
} else {
mtu = dst_mtu(&rt->dst) - sizeof(struct iphdr);
if (mtu < 68) {
IP_VS_DBG_RL("%s(): mtu less than 68\n", __func__);
goto err_put;
}
maybe_update_pmtu(skb_af, skb, mtu);
}
if (!ensure_mtu_is_adequate(ipvs, skb_af, rt_mode, ipvsh, skb, mtu))
goto err_put;
skb_dst_drop(skb);
if (noref) {
if (!local)
skb_dst_set_noref(skb, &rt->dst);
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
static struct dst_entry *
__ip_vs_route_output_v6(struct net *net, struct in6_addr *daddr,
struct in6_addr *ret_saddr, int do_xfrm, int rt_mode)
{
struct dst_entry *dst;
struct flowi6 fl6 = {
.daddr = *daddr,
};
if (rt_mode & IP_VS_RT_MODE_KNOWN_NH)
fl6.flowi6_flags = FLOWI_FLAG_KNOWN_NH;
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
__ip_vs_get_out_rt_v6(struct netns_ipvs *ipvs, int skb_af, struct sk_buff *skb,
struct ip_vs_dest *dest,
struct in6_addr *daddr, struct in6_addr *ret_saddr,
struct ip_vs_iphdr *ipvsh, int do_xfrm, int rt_mode)
{
struct net *net = ipvs->net;
struct ip_vs_dest_dst *dest_dst;
struct rt6_info *rt;
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
do_xfrm, rt_mode);
if (!dst) {
__ip_vs_dst_set(dest, NULL, NULL, 0);
spin_unlock_bh(&dest->dst_lock);
ip_vs_dest_dst_free(dest_dst);
goto err_unreach;
}
rt = (struct rt6_info *) dst;
cookie = rt6_get_cookie(rt);
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
dst = __ip_vs_route_output_v6(net, daddr, ret_saddr, do_xfrm,
rt_mode);
if (!dst)
goto err_unreach;
rt = (struct rt6_info *) dst;
}
local = __ip_vs_is_local_route6(rt);
if (unlikely(crosses_local_route_boundary(skb_af, skb, rt_mode,
local))) {
IP_VS_DBG_RL("We are crossing local and non-local addresses"
" daddr=%pI6\n", daddr);
goto err_put;
}
if (unlikely(local)) {
if (!noref)
dst_release(&rt->dst);
return local;
}
if (likely(!(rt_mode & IP_VS_RT_MODE_TUNNEL)))
mtu = dst_mtu(&rt->dst);
else {
mtu = dst_mtu(&rt->dst) - sizeof(struct ipv6hdr);
if (mtu < IPV6_MIN_MTU) {
IP_VS_DBG_RL("%s(): mtu less than %d\n", __func__,
IPV6_MIN_MTU);
goto err_put;
}
maybe_update_pmtu(skb_af, skb, mtu);
}
if (!ensure_mtu_is_adequate(ipvs, skb_af, rt_mode, ipvsh, skb, mtu))
goto err_put;
skb_dst_drop(skb);
if (noref) {
if (!local)
skb_dst_set_noref(skb, &rt->dst);
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
if (!skb->dev)
skb->dev = skb_dst(skb)->dev;
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
static inline void ip_vs_drop_early_demux_sk(struct sk_buff *skb)
{
if (skb->dev)
skb_orphan(skb);
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
if (!local || cp->vport != cp->dport ||
!ip_vs_addr_equal(cp->af, &cp->vaddr, &cp->daddr))
ip_vs_drop_early_demux_sk(skb);
if (!local) {
skb_forward_csum(skb);
NF_HOOK(pf, NF_INET_LOCAL_OUT, cp->ipvs->net, NULL, skb,
NULL, skb_dst(skb)->dev, dst_output);
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
ip_vs_drop_early_demux_sk(skb);
skb_forward_csum(skb);
NF_HOOK(pf, NF_INET_LOCAL_OUT, cp->ipvs->net, NULL, skb,
NULL, skb_dst(skb)->dev, dst_output);
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
if (__ip_vs_get_out_rt(cp->ipvs, cp->af, skb, NULL, iph->daddr,
IP_VS_RT_MODE_NON_LOCAL, NULL, ipvsh) < 0)
goto tx_error;
ip_send_check(iph);
skb->ignore_df = 1;
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
struct ipv6hdr *iph = ipv6_hdr(skb);
EnterFunction(10);
rcu_read_lock();
if (__ip_vs_get_out_rt_v6(cp->ipvs, cp->af, skb, NULL,
&iph->daddr, NULL,
ipvsh, 0, IP_VS_RT_MODE_NON_LOCAL) < 0)
goto tx_error;
skb->ignore_df = 1;
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
local = __ip_vs_get_out_rt(cp->ipvs, cp->af, skb, cp->dest, cp->daddr.ip,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_RDR, NULL, ipvsh);
if (local < 0)
goto tx_error;
rt = skb_rtable(skb);
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (cp->flags & IP_VS_CONN_F_SYNC && local) {
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
if (ct && !nf_ct_is_untracked(ct)) {
IP_VS_DBG_RL_PKT(10, AF_INET, pp, skb, ipvsh->off,
"ip_vs_nat_xmit(): "
"stopping DNAT to local address");
goto tx_error;
}
}
#endif
if (local && ipv4_is_loopback(cp->daddr.ip) && was_input) {
IP_VS_DBG_RL_PKT(1, AF_INET, pp, skb, ipvsh->off,
"ip_vs_nat_xmit(): stopping DNAT to loopback "
"address");
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
IP_VS_DBG_PKT(10, AF_INET, pp, skb, ipvsh->off, "After DNAT");
skb->ignore_df = 1;
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
local = __ip_vs_get_out_rt_v6(cp->ipvs, cp->af, skb, cp->dest,
&cp->daddr.in6,
NULL, ipvsh, 0,
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
IP_VS_DBG_RL_PKT(10, AF_INET6, pp, skb, ipvsh->off,
"ip_vs_nat_xmit_v6(): "
"stopping DNAT to local address");
goto tx_error;
}
}
#endif
if (local && skb->dev && !(skb->dev->flags & IFF_LOOPBACK) &&
ipv6_addr_type(&cp->daddr.in6) & IPV6_ADDR_LOOPBACK) {
IP_VS_DBG_RL_PKT(1, AF_INET6, pp, skb, ipvsh->off,
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
IP_VS_DBG_PKT(10, AF_INET6, pp, skb, ipvsh->off, "After DNAT");
skb->ignore_df = 1;
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
static struct sk_buff *
ip_vs_prepare_tunneled_skb(struct sk_buff *skb, int skb_af,
unsigned int max_headroom, __u8 *next_protocol,
__u32 *payload_len, __u8 *dsfield, __u8 *ttl,
__be16 *df)
{
struct sk_buff *new_skb = NULL;
struct iphdr *old_iph = NULL;
#ifdef CONFIG_IP_VS_IPV6
struct ipv6hdr *old_ipv6h = NULL;
#endif
ip_vs_drop_early_demux_sk(skb);
if (skb_headroom(skb) < max_headroom || skb_cloned(skb)) {
new_skb = skb_realloc_headroom(skb, max_headroom);
if (!new_skb)
goto error;
if (skb->sk)
skb_set_owner_w(new_skb, skb->sk);
consume_skb(skb);
skb = new_skb;
}
#ifdef CONFIG_IP_VS_IPV6
if (skb_af == AF_INET6) {
old_ipv6h = ipv6_hdr(skb);
*next_protocol = IPPROTO_IPV6;
if (payload_len)
*payload_len =
ntohs(old_ipv6h->payload_len) +
sizeof(*old_ipv6h);
*dsfield = ipv6_get_dsfield(old_ipv6h);
*ttl = old_ipv6h->hop_limit;
if (df)
*df = 0;
} else
#endif
{
old_iph = ip_hdr(skb);
if (df)
*df = (old_iph->frag_off & htons(IP_DF));
*next_protocol = IPPROTO_IPIP;
ip_send_check(old_iph);
*dsfield = ipv4_get_dsfield(old_iph);
*ttl = old_iph->ttl;
if (payload_len)
*payload_len = ntohs(old_iph->tot_len);
}
return skb;
error:
kfree_skb(skb);
return ERR_PTR(-ENOMEM);
}
static inline int __tun_gso_type_mask(int encaps_af, int orig_af)
{
if (encaps_af == AF_INET) {
if (orig_af == AF_INET)
return SKB_GSO_IPIP;
return SKB_GSO_SIT;
}
return 0;
}
int
ip_vs_tunnel_xmit(struct sk_buff *skb, struct ip_vs_conn *cp,
struct ip_vs_protocol *pp, struct ip_vs_iphdr *ipvsh)
{
struct netns_ipvs *ipvs = cp->ipvs;
struct net *net = ipvs->net;
struct rtable *rt;
__be32 saddr;
struct net_device *tdev;
__u8 next_protocol = 0;
__u8 dsfield = 0;
__u8 ttl = 0;
__be16 df = 0;
__be16 *dfp = NULL;
struct iphdr *iph;
unsigned int max_headroom;
int ret, local;
EnterFunction(10);
rcu_read_lock();
local = __ip_vs_get_out_rt(ipvs, cp->af, skb, cp->dest, cp->daddr.ip,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_CONNECT |
IP_VS_RT_MODE_TUNNEL, &saddr, ipvsh);
if (local < 0)
goto tx_error;
if (local) {
rcu_read_unlock();
return ip_vs_send_or_cont(NFPROTO_IPV4, skb, cp, 1);
}
rt = skb_rtable(skb);
tdev = rt->dst.dev;
max_headroom = LL_RESERVED_SPACE(tdev) + sizeof(struct iphdr);
dfp = sysctl_pmtu_disc(ipvs) ? &df : NULL;
skb = ip_vs_prepare_tunneled_skb(skb, cp->af, max_headroom,
&next_protocol, NULL, &dsfield,
&ttl, dfp);
if (IS_ERR(skb))
goto tx_error;
skb = iptunnel_handle_offloads(skb, __tun_gso_type_mask(AF_INET, cp->af));
if (IS_ERR(skb))
goto tx_error;
skb->transport_header = skb->network_header;
skb_push(skb, sizeof(struct iphdr));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
iph = ip_hdr(skb);
iph->version = 4;
iph->ihl = sizeof(struct iphdr)>>2;
iph->frag_off = df;
iph->protocol = next_protocol;
iph->tos = dsfield;
iph->daddr = cp->daddr.ip;
iph->saddr = saddr;
iph->ttl = ttl;
ip_select_ident(net, skb, NULL);
skb->ignore_df = 1;
ret = ip_vs_tunnel_xmit_prepare(skb, cp);
if (ret == NF_ACCEPT)
ip_local_out(net, skb->sk, skb);
else if (ret == NF_DROP)
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
if (!IS_ERR(skb))
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
__u8 next_protocol = 0;
__u32 payload_len = 0;
__u8 dsfield = 0;
__u8 ttl = 0;
struct ipv6hdr *iph;
unsigned int max_headroom;
int ret, local;
EnterFunction(10);
rcu_read_lock();
local = __ip_vs_get_out_rt_v6(cp->ipvs, cp->af, skb, cp->dest,
&cp->daddr.in6,
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
skb = ip_vs_prepare_tunneled_skb(skb, cp->af, max_headroom,
&next_protocol, &payload_len,
&dsfield, &ttl, NULL);
if (IS_ERR(skb))
goto tx_error;
skb = iptunnel_handle_offloads(skb, __tun_gso_type_mask(AF_INET6, cp->af));
if (IS_ERR(skb))
goto tx_error;
skb->transport_header = skb->network_header;
skb_push(skb, sizeof(struct ipv6hdr));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
iph = ipv6_hdr(skb);
iph->version = 6;
iph->nexthdr = next_protocol;
iph->payload_len = htons(payload_len);
memset(&iph->flow_lbl, 0, sizeof(iph->flow_lbl));
ipv6_change_dsfield(iph, 0, dsfield);
iph->daddr = cp->daddr.in6;
iph->saddr = saddr;
iph->hop_limit = ttl;
skb->ignore_df = 1;
ret = ip_vs_tunnel_xmit_prepare(skb, cp);
if (ret == NF_ACCEPT)
ip6_local_out(cp->ipvs->net, skb->sk, skb);
else if (ret == NF_DROP)
kfree_skb(skb);
rcu_read_unlock();
LeaveFunction(10);
return NF_STOLEN;
tx_error:
if (!IS_ERR(skb))
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
local = __ip_vs_get_out_rt(cp->ipvs, cp->af, skb, cp->dest, cp->daddr.ip,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_KNOWN_NH, NULL, ipvsh);
if (local < 0)
goto tx_error;
if (local) {
rcu_read_unlock();
return ip_vs_send_or_cont(NFPROTO_IPV4, skb, cp, 1);
}
ip_send_check(ip_hdr(skb));
skb->ignore_df = 1;
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
local = __ip_vs_get_out_rt_v6(cp->ipvs, cp->af, skb, cp->dest,
&cp->daddr.in6,
NULL, ipvsh, 0,
IP_VS_RT_MODE_LOCAL |
IP_VS_RT_MODE_NON_LOCAL |
IP_VS_RT_MODE_KNOWN_NH);
if (local < 0)
goto tx_error;
if (local) {
rcu_read_unlock();
return ip_vs_send_or_cont(NFPROTO_IPV6, skb, cp, 1);
}
skb->ignore_df = 1;
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
local = __ip_vs_get_out_rt(cp->ipvs, cp->af, skb, cp->dest, cp->daddr.ip, rt_mode,
NULL, iph);
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
skb->ignore_df = 1;
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
local = __ip_vs_get_out_rt_v6(cp->ipvs, cp->af, skb, cp->dest,
&cp->daddr.in6, NULL, ipvsh, 0, rt_mode);
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
ipv6_addr_type(&cp->daddr.in6) & IPV6_ADDR_LOOPBACK) {
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
skb->ignore_df = 1;
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
