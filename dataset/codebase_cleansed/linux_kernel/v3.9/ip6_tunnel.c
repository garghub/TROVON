static u32 HASH(const struct in6_addr *addr1, const struct in6_addr *addr2)
{
u32 hash = ipv6_addr_hash(addr1) ^ ipv6_addr_hash(addr2);
return hash_32(hash, HASH_SIZE_SHIFT);
}
static struct net_device_stats *ip6_get_stats(struct net_device *dev)
{
struct pcpu_tstats sum = { 0 };
int i;
for_each_possible_cpu(i) {
const struct pcpu_tstats *tstats = per_cpu_ptr(dev->tstats, i);
sum.rx_packets += tstats->rx_packets;
sum.rx_bytes += tstats->rx_bytes;
sum.tx_packets += tstats->tx_packets;
sum.tx_bytes += tstats->tx_bytes;
}
dev->stats.rx_packets = sum.rx_packets;
dev->stats.rx_bytes = sum.rx_bytes;
dev->stats.tx_packets = sum.tx_packets;
dev->stats.tx_bytes = sum.tx_bytes;
return &dev->stats;
}
struct dst_entry *ip6_tnl_dst_check(struct ip6_tnl *t)
{
struct dst_entry *dst = t->dst_cache;
if (dst && dst->obsolete &&
dst->ops->check(dst, t->dst_cookie) == NULL) {
t->dst_cache = NULL;
dst_release(dst);
return NULL;
}
return dst;
}
void ip6_tnl_dst_reset(struct ip6_tnl *t)
{
dst_release(t->dst_cache);
t->dst_cache = NULL;
}
void ip6_tnl_dst_store(struct ip6_tnl *t, struct dst_entry *dst)
{
struct rt6_info *rt = (struct rt6_info *) dst;
t->dst_cookie = rt->rt6i_node ? rt->rt6i_node->fn_sernum : 0;
dst_release(t->dst_cache);
t->dst_cache = dst;
}
static struct ip6_tnl *
ip6_tnl_lookup(struct net *net, const struct in6_addr *remote, const struct in6_addr *local)
{
unsigned int hash = HASH(remote, local);
struct ip6_tnl *t;
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
for_each_ip6_tunnel_rcu(ip6n->tnls_r_l[hash]) {
if (ipv6_addr_equal(local, &t->parms.laddr) &&
ipv6_addr_equal(remote, &t->parms.raddr) &&
(t->dev->flags & IFF_UP))
return t;
}
t = rcu_dereference(ip6n->tnls_wc[0]);
if (t && (t->dev->flags & IFF_UP))
return t;
return NULL;
}
static struct ip6_tnl __rcu **
ip6_tnl_bucket(struct ip6_tnl_net *ip6n, const struct __ip6_tnl_parm *p)
{
const struct in6_addr *remote = &p->raddr;
const struct in6_addr *local = &p->laddr;
unsigned int h = 0;
int prio = 0;
if (!ipv6_addr_any(remote) || !ipv6_addr_any(local)) {
prio = 1;
h = HASH(remote, local);
}
return &ip6n->tnls[prio][h];
}
static void
ip6_tnl_link(struct ip6_tnl_net *ip6n, struct ip6_tnl *t)
{
struct ip6_tnl __rcu **tp = ip6_tnl_bucket(ip6n, &t->parms);
rcu_assign_pointer(t->next , rtnl_dereference(*tp));
rcu_assign_pointer(*tp, t);
}
static void
ip6_tnl_unlink(struct ip6_tnl_net *ip6n, struct ip6_tnl *t)
{
struct ip6_tnl __rcu **tp;
struct ip6_tnl *iter;
for (tp = ip6_tnl_bucket(ip6n, &t->parms);
(iter = rtnl_dereference(*tp)) != NULL;
tp = &iter->next) {
if (t == iter) {
rcu_assign_pointer(*tp, t->next);
break;
}
}
}
static void ip6_dev_free(struct net_device *dev)
{
free_percpu(dev->tstats);
free_netdev(dev);
}
static int ip6_tnl_create2(struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct net *net = dev_net(dev);
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
int err;
t = netdev_priv(dev);
err = ip6_tnl_dev_init(dev);
if (err < 0)
goto out;
err = register_netdevice(dev);
if (err < 0)
goto out;
strcpy(t->parms.name, dev->name);
dev->rtnl_link_ops = &ip6_link_ops;
dev_hold(dev);
ip6_tnl_link(ip6n, t);
return 0;
out:
return err;
}
static struct ip6_tnl *ip6_tnl_create(struct net *net, struct __ip6_tnl_parm *p)
{
struct net_device *dev;
struct ip6_tnl *t;
char name[IFNAMSIZ];
int err;
if (p->name[0])
strlcpy(name, p->name, IFNAMSIZ);
else
sprintf(name, "ip6tnl%%d");
dev = alloc_netdev(sizeof (*t), name, ip6_tnl_dev_setup);
if (dev == NULL)
goto failed;
dev_net_set(dev, net);
t = netdev_priv(dev);
t->parms = *p;
err = ip6_tnl_create2(dev);
if (err < 0)
goto failed_free;
return t;
failed_free:
ip6_dev_free(dev);
failed:
return NULL;
}
static struct ip6_tnl *ip6_tnl_locate(struct net *net,
struct __ip6_tnl_parm *p, int create)
{
const struct in6_addr *remote = &p->raddr;
const struct in6_addr *local = &p->laddr;
struct ip6_tnl __rcu **tp;
struct ip6_tnl *t;
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
for (tp = ip6_tnl_bucket(ip6n, p);
(t = rtnl_dereference(*tp)) != NULL;
tp = &t->next) {
if (ipv6_addr_equal(local, &t->parms.laddr) &&
ipv6_addr_equal(remote, &t->parms.raddr))
return t;
}
if (!create)
return NULL;
return ip6_tnl_create(net, p);
}
static void
ip6_tnl_dev_uninit(struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct net *net = dev_net(dev);
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
if (dev == ip6n->fb_tnl_dev)
RCU_INIT_POINTER(ip6n->tnls_wc[0], NULL);
else
ip6_tnl_unlink(ip6n, t);
ip6_tnl_dst_reset(t);
dev_put(dev);
}
__u16 ip6_tnl_parse_tlv_enc_lim(struct sk_buff *skb, __u8 *raw)
{
const struct ipv6hdr *ipv6h = (const struct ipv6hdr *) raw;
__u8 nexthdr = ipv6h->nexthdr;
__u16 off = sizeof (*ipv6h);
while (ipv6_ext_hdr(nexthdr) && nexthdr != NEXTHDR_NONE) {
__u16 optlen = 0;
struct ipv6_opt_hdr *hdr;
if (raw + off + sizeof (*hdr) > skb->data &&
!pskb_may_pull(skb, raw - skb->data + off + sizeof (*hdr)))
break;
hdr = (struct ipv6_opt_hdr *) (raw + off);
if (nexthdr == NEXTHDR_FRAGMENT) {
struct frag_hdr *frag_hdr = (struct frag_hdr *) hdr;
if (frag_hdr->frag_off)
break;
optlen = 8;
} else if (nexthdr == NEXTHDR_AUTH) {
optlen = (hdr->hdrlen + 2) << 2;
} else {
optlen = ipv6_optlen(hdr);
}
if (nexthdr == NEXTHDR_DEST) {
__u16 i = off + 2;
while (1) {
struct ipv6_tlv_tnl_enc_lim *tel;
if (i + sizeof (*tel) > off + optlen)
break;
tel = (struct ipv6_tlv_tnl_enc_lim *) &raw[i];
if (tel->type == IPV6_TLV_TNL_ENCAP_LIMIT &&
tel->length == 1)
return i;
if (tel->type)
i += tel->length + 2;
else
i++;
}
}
nexthdr = hdr->nexthdr;
off += optlen;
}
return 0;
}
static int
ip6_tnl_err(struct sk_buff *skb, __u8 ipproto, struct inet6_skb_parm *opt,
u8 *type, u8 *code, int *msg, __u32 *info, int offset)
{
const struct ipv6hdr *ipv6h = (const struct ipv6hdr *) skb->data;
struct ip6_tnl *t;
int rel_msg = 0;
u8 rel_type = ICMPV6_DEST_UNREACH;
u8 rel_code = ICMPV6_ADDR_UNREACH;
__u32 rel_info = 0;
__u16 len;
int err = -ENOENT;
rcu_read_lock();
if ((t = ip6_tnl_lookup(dev_net(skb->dev), &ipv6h->daddr,
&ipv6h->saddr)) == NULL)
goto out;
if (t->parms.proto != ipproto && t->parms.proto != 0)
goto out;
err = 0;
switch (*type) {
__u32 teli;
struct ipv6_tlv_tnl_enc_lim *tel;
__u32 mtu;
case ICMPV6_DEST_UNREACH:
net_warn_ratelimited("%s: Path to destination invalid or inactive!\n",
t->parms.name);
rel_msg = 1;
break;
case ICMPV6_TIME_EXCEED:
if ((*code) == ICMPV6_EXC_HOPLIMIT) {
net_warn_ratelimited("%s: Too small hop limit or routing loop in tunnel!\n",
t->parms.name);
rel_msg = 1;
}
break;
case ICMPV6_PARAMPROB:
teli = 0;
if ((*code) == ICMPV6_HDR_FIELD)
teli = ip6_tnl_parse_tlv_enc_lim(skb, skb->data);
if (teli && teli == *info - 2) {
tel = (struct ipv6_tlv_tnl_enc_lim *) &skb->data[teli];
if (tel->encap_limit == 0) {
net_warn_ratelimited("%s: Too small encapsulation limit or routing loop in tunnel!\n",
t->parms.name);
rel_msg = 1;
}
} else {
net_warn_ratelimited("%s: Recipient unable to parse tunneled packet!\n",
t->parms.name);
}
break;
case ICMPV6_PKT_TOOBIG:
mtu = *info - offset;
if (mtu < IPV6_MIN_MTU)
mtu = IPV6_MIN_MTU;
t->dev->mtu = mtu;
if ((len = sizeof (*ipv6h) + ntohs(ipv6h->payload_len)) > mtu) {
rel_type = ICMPV6_PKT_TOOBIG;
rel_code = 0;
rel_info = mtu;
rel_msg = 1;
}
break;
}
*type = rel_type;
*code = rel_code;
*info = rel_info;
*msg = rel_msg;
out:
rcu_read_unlock();
return err;
}
static int
ip4ip6_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
int rel_msg = 0;
u8 rel_type = type;
u8 rel_code = code;
__u32 rel_info = ntohl(info);
int err;
struct sk_buff *skb2;
const struct iphdr *eiph;
struct rtable *rt;
struct flowi4 fl4;
err = ip6_tnl_err(skb, IPPROTO_IPIP, opt, &rel_type, &rel_code,
&rel_msg, &rel_info, offset);
if (err < 0)
return err;
if (rel_msg == 0)
return 0;
switch (rel_type) {
case ICMPV6_DEST_UNREACH:
if (rel_code != ICMPV6_ADDR_UNREACH)
return 0;
rel_type = ICMP_DEST_UNREACH;
rel_code = ICMP_HOST_UNREACH;
break;
case ICMPV6_PKT_TOOBIG:
if (rel_code != 0)
return 0;
rel_type = ICMP_DEST_UNREACH;
rel_code = ICMP_FRAG_NEEDED;
break;
case NDISC_REDIRECT:
rel_type = ICMP_REDIRECT;
rel_code = ICMP_REDIR_HOST;
default:
return 0;
}
if (!pskb_may_pull(skb, offset + sizeof(struct iphdr)))
return 0;
skb2 = skb_clone(skb, GFP_ATOMIC);
if (!skb2)
return 0;
skb_dst_drop(skb2);
skb_pull(skb2, offset);
skb_reset_network_header(skb2);
eiph = ip_hdr(skb2);
rt = ip_route_output_ports(dev_net(skb->dev), &fl4, NULL,
eiph->saddr, 0,
0, 0,
IPPROTO_IPIP, RT_TOS(eiph->tos), 0);
if (IS_ERR(rt))
goto out;
skb2->dev = rt->dst.dev;
if (rt->rt_flags & RTCF_LOCAL) {
ip_rt_put(rt);
rt = NULL;
rt = ip_route_output_ports(dev_net(skb->dev), &fl4, NULL,
eiph->daddr, eiph->saddr,
0, 0,
IPPROTO_IPIP,
RT_TOS(eiph->tos), 0);
if (IS_ERR(rt) ||
rt->dst.dev->type != ARPHRD_TUNNEL) {
if (!IS_ERR(rt))
ip_rt_put(rt);
goto out;
}
skb_dst_set(skb2, &rt->dst);
} else {
ip_rt_put(rt);
if (ip_route_input(skb2, eiph->daddr, eiph->saddr, eiph->tos,
skb2->dev) ||
skb_dst(skb2)->dev->type != ARPHRD_TUNNEL)
goto out;
}
if (rel_type == ICMP_DEST_UNREACH && rel_code == ICMP_FRAG_NEEDED) {
if (rel_info > dst_mtu(skb_dst(skb2)))
goto out;
skb_dst(skb2)->ops->update_pmtu(skb_dst(skb2), NULL, skb2, rel_info);
}
if (rel_type == ICMP_REDIRECT)
skb_dst(skb2)->ops->redirect(skb_dst(skb2), NULL, skb2);
icmp_send(skb2, rel_type, rel_code, htonl(rel_info));
out:
kfree_skb(skb2);
return 0;
}
static int
ip6ip6_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
int rel_msg = 0;
u8 rel_type = type;
u8 rel_code = code;
__u32 rel_info = ntohl(info);
int err;
err = ip6_tnl_err(skb, IPPROTO_IPV6, opt, &rel_type, &rel_code,
&rel_msg, &rel_info, offset);
if (err < 0)
return err;
if (rel_msg && pskb_may_pull(skb, offset + sizeof(struct ipv6hdr))) {
struct rt6_info *rt;
struct sk_buff *skb2 = skb_clone(skb, GFP_ATOMIC);
if (!skb2)
return 0;
skb_dst_drop(skb2);
skb_pull(skb2, offset);
skb_reset_network_header(skb2);
rt = rt6_lookup(dev_net(skb->dev), &ipv6_hdr(skb2)->saddr,
NULL, 0, 0);
if (rt && rt->dst.dev)
skb2->dev = rt->dst.dev;
icmpv6_send(skb2, rel_type, rel_code, rel_info);
ip6_rt_put(rt);
kfree_skb(skb2);
}
return 0;
}
static int ip4ip6_dscp_ecn_decapsulate(const struct ip6_tnl *t,
const struct ipv6hdr *ipv6h,
struct sk_buff *skb)
{
__u8 dsfield = ipv6_get_dsfield(ipv6h) & ~INET_ECN_MASK;
if (t->parms.flags & IP6_TNL_F_RCV_DSCP_COPY)
ipv4_change_dsfield(ip_hdr(skb), INET_ECN_MASK, dsfield);
return IP6_ECN_decapsulate(ipv6h, skb);
}
static int ip6ip6_dscp_ecn_decapsulate(const struct ip6_tnl *t,
const struct ipv6hdr *ipv6h,
struct sk_buff *skb)
{
if (t->parms.flags & IP6_TNL_F_RCV_DSCP_COPY)
ipv6_copy_dscp(ipv6_get_dsfield(ipv6h), ipv6_hdr(skb));
return IP6_ECN_decapsulate(ipv6h, skb);
}
__u32 ip6_tnl_get_cap(struct ip6_tnl *t,
const struct in6_addr *laddr,
const struct in6_addr *raddr)
{
struct __ip6_tnl_parm *p = &t->parms;
int ltype = ipv6_addr_type(laddr);
int rtype = ipv6_addr_type(raddr);
__u32 flags = 0;
if (ltype == IPV6_ADDR_ANY || rtype == IPV6_ADDR_ANY) {
flags = IP6_TNL_F_CAP_PER_PACKET;
} else if (ltype & (IPV6_ADDR_UNICAST|IPV6_ADDR_MULTICAST) &&
rtype & (IPV6_ADDR_UNICAST|IPV6_ADDR_MULTICAST) &&
!((ltype|rtype) & IPV6_ADDR_LOOPBACK) &&
(!((ltype|rtype) & IPV6_ADDR_LINKLOCAL) || p->link)) {
if (ltype&IPV6_ADDR_UNICAST)
flags |= IP6_TNL_F_CAP_XMIT;
if (rtype&IPV6_ADDR_UNICAST)
flags |= IP6_TNL_F_CAP_RCV;
}
return flags;
}
int ip6_tnl_rcv_ctl(struct ip6_tnl *t,
const struct in6_addr *laddr,
const struct in6_addr *raddr)
{
struct __ip6_tnl_parm *p = &t->parms;
int ret = 0;
struct net *net = dev_net(t->dev);
if ((p->flags & IP6_TNL_F_CAP_RCV) ||
((p->flags & IP6_TNL_F_CAP_PER_PACKET) &&
(ip6_tnl_get_cap(t, laddr, raddr) & IP6_TNL_F_CAP_RCV))) {
struct net_device *ldev = NULL;
if (p->link)
ldev = dev_get_by_index_rcu(net, p->link);
if ((ipv6_addr_is_multicast(laddr) ||
likely(ipv6_chk_addr(net, laddr, ldev, 0))) &&
likely(!ipv6_chk_addr(net, raddr, NULL, 0)))
ret = 1;
}
return ret;
}
static int ip6_tnl_rcv(struct sk_buff *skb, __u16 protocol,
__u8 ipproto,
int (*dscp_ecn_decapsulate)(const struct ip6_tnl *t,
const struct ipv6hdr *ipv6h,
struct sk_buff *skb))
{
struct ip6_tnl *t;
const struct ipv6hdr *ipv6h = ipv6_hdr(skb);
int err;
rcu_read_lock();
if ((t = ip6_tnl_lookup(dev_net(skb->dev), &ipv6h->saddr,
&ipv6h->daddr)) != NULL) {
struct pcpu_tstats *tstats;
if (t->parms.proto != ipproto && t->parms.proto != 0) {
rcu_read_unlock();
goto discard;
}
if (!xfrm6_policy_check(NULL, XFRM_POLICY_IN, skb)) {
rcu_read_unlock();
goto discard;
}
if (!ip6_tnl_rcv_ctl(t, &ipv6h->daddr, &ipv6h->saddr)) {
t->dev->stats.rx_dropped++;
rcu_read_unlock();
goto discard;
}
secpath_reset(skb);
skb->mac_header = skb->network_header;
skb_reset_network_header(skb);
skb->protocol = htons(protocol);
skb->pkt_type = PACKET_HOST;
memset(skb->cb, 0, sizeof(struct inet6_skb_parm));
__skb_tunnel_rx(skb, t->dev);
err = dscp_ecn_decapsulate(t, ipv6h, skb);
if (unlikely(err)) {
if (log_ecn_error)
net_info_ratelimited("non-ECT from %pI6 with dsfield=%#x\n",
&ipv6h->saddr,
ipv6_get_dsfield(ipv6h));
if (err > 1) {
++t->dev->stats.rx_frame_errors;
++t->dev->stats.rx_errors;
rcu_read_unlock();
goto discard;
}
}
tstats = this_cpu_ptr(t->dev->tstats);
tstats->rx_packets++;
tstats->rx_bytes += skb->len;
netif_rx(skb);
rcu_read_unlock();
return 0;
}
rcu_read_unlock();
return 1;
discard:
kfree_skb(skb);
return 0;
}
static int ip4ip6_rcv(struct sk_buff *skb)
{
return ip6_tnl_rcv(skb, ETH_P_IP, IPPROTO_IPIP,
ip4ip6_dscp_ecn_decapsulate);
}
static int ip6ip6_rcv(struct sk_buff *skb)
{
return ip6_tnl_rcv(skb, ETH_P_IPV6, IPPROTO_IPV6,
ip6ip6_dscp_ecn_decapsulate);
}
static void init_tel_txopt(struct ipv6_tel_txoption *opt, __u8 encap_limit)
{
memset(opt, 0, sizeof(struct ipv6_tel_txoption));
opt->dst_opt[2] = IPV6_TLV_TNL_ENCAP_LIMIT;
opt->dst_opt[3] = 1;
opt->dst_opt[4] = encap_limit;
opt->dst_opt[5] = IPV6_TLV_PADN;
opt->dst_opt[6] = 1;
opt->ops.dst0opt = (struct ipv6_opt_hdr *) opt->dst_opt;
opt->ops.opt_nflen = 8;
}
static inline bool
ip6_tnl_addr_conflict(const struct ip6_tnl *t, const struct ipv6hdr *hdr)
{
return ipv6_addr_equal(&t->parms.raddr, &hdr->saddr);
}
int ip6_tnl_xmit_ctl(struct ip6_tnl *t)
{
struct __ip6_tnl_parm *p = &t->parms;
int ret = 0;
struct net *net = dev_net(t->dev);
if (p->flags & IP6_TNL_F_CAP_XMIT) {
struct net_device *ldev = NULL;
rcu_read_lock();
if (p->link)
ldev = dev_get_by_index_rcu(net, p->link);
if (unlikely(!ipv6_chk_addr(net, &p->laddr, ldev, 0)))
pr_warn("%s xmit: Local address not yet configured!\n",
p->name);
else if (!ipv6_addr_is_multicast(&p->raddr) &&
unlikely(ipv6_chk_addr(net, &p->raddr, NULL, 0)))
pr_warn("%s xmit: Routing loop! Remote address found on this node!\n",
p->name);
else
ret = 1;
rcu_read_unlock();
}
return ret;
}
static int ip6_tnl_xmit2(struct sk_buff *skb,
struct net_device *dev,
__u8 dsfield,
struct flowi6 *fl6,
int encap_limit,
__u32 *pmtu)
{
struct net *net = dev_net(dev);
struct ip6_tnl *t = netdev_priv(dev);
struct net_device_stats *stats = &t->dev->stats;
struct ipv6hdr *ipv6h = ipv6_hdr(skb);
struct ipv6_tel_txoption opt;
struct dst_entry *dst = NULL, *ndst = NULL;
struct net_device *tdev;
int mtu;
unsigned int max_headroom = sizeof(struct ipv6hdr);
u8 proto;
int err = -1;
int pkt_len;
if (!fl6->flowi6_mark)
dst = ip6_tnl_dst_check(t);
if (!dst) {
ndst = ip6_route_output(net, NULL, fl6);
if (ndst->error)
goto tx_err_link_failure;
ndst = xfrm_lookup(net, ndst, flowi6_to_flowi(fl6), NULL, 0);
if (IS_ERR(ndst)) {
err = PTR_ERR(ndst);
ndst = NULL;
goto tx_err_link_failure;
}
dst = ndst;
}
tdev = dst->dev;
if (tdev == dev) {
stats->collisions++;
net_warn_ratelimited("%s: Local routing loop detected!\n",
t->parms.name);
goto tx_err_dst_release;
}
mtu = dst_mtu(dst) - sizeof (*ipv6h);
if (encap_limit >= 0) {
max_headroom += 8;
mtu -= 8;
}
if (mtu < IPV6_MIN_MTU)
mtu = IPV6_MIN_MTU;
if (skb_dst(skb))
skb_dst(skb)->ops->update_pmtu(skb_dst(skb), NULL, skb, mtu);
if (skb->len > mtu) {
*pmtu = mtu;
err = -EMSGSIZE;
goto tx_err_dst_release;
}
max_headroom += LL_RESERVED_SPACE(tdev);
if (skb_headroom(skb) < max_headroom || skb_shared(skb) ||
(skb_cloned(skb) && !skb_clone_writable(skb, 0))) {
struct sk_buff *new_skb;
if (!(new_skb = skb_realloc_headroom(skb, max_headroom)))
goto tx_err_dst_release;
if (skb->sk)
skb_set_owner_w(new_skb, skb->sk);
consume_skb(skb);
skb = new_skb;
}
skb_dst_drop(skb);
if (fl6->flowi6_mark) {
skb_dst_set(skb, dst);
ndst = NULL;
} else {
skb_dst_set_noref(skb, dst);
}
skb->transport_header = skb->network_header;
proto = fl6->flowi6_proto;
if (encap_limit >= 0) {
init_tel_txopt(&opt, encap_limit);
ipv6_push_nfrag_opts(skb, &opt.ops, &proto, NULL);
}
skb_push(skb, sizeof(struct ipv6hdr));
skb_reset_network_header(skb);
ipv6h = ipv6_hdr(skb);
ip6_flow_hdr(ipv6h, INET_ECN_encapsulate(0, dsfield), fl6->flowlabel);
ipv6h->hop_limit = t->parms.hop_limit;
ipv6h->nexthdr = proto;
ipv6h->saddr = fl6->saddr;
ipv6h->daddr = fl6->daddr;
nf_reset(skb);
pkt_len = skb->len;
err = ip6_local_out(skb);
if (net_xmit_eval(err) == 0) {
struct pcpu_tstats *tstats = this_cpu_ptr(t->dev->tstats);
tstats->tx_bytes += pkt_len;
tstats->tx_packets++;
} else {
stats->tx_errors++;
stats->tx_aborted_errors++;
}
if (ndst)
ip6_tnl_dst_store(t, ndst);
return 0;
tx_err_link_failure:
stats->tx_carrier_errors++;
dst_link_failure(skb);
tx_err_dst_release:
dst_release(ndst);
return err;
}
static inline int
ip4ip6_tnl_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
const struct iphdr *iph = ip_hdr(skb);
int encap_limit = -1;
struct flowi6 fl6;
__u8 dsfield;
__u32 mtu;
int err;
if ((t->parms.proto != IPPROTO_IPIP && t->parms.proto != 0) ||
!ip6_tnl_xmit_ctl(t))
return -1;
if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
encap_limit = t->parms.encap_limit;
memcpy(&fl6, &t->fl.u.ip6, sizeof (fl6));
fl6.flowi6_proto = IPPROTO_IPIP;
dsfield = ipv4_get_dsfield(iph);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_TCLASS)
fl6.flowlabel |= htonl((__u32)iph->tos << IPV6_TCLASS_SHIFT)
& IPV6_TCLASS_MASK;
if (t->parms.flags & IP6_TNL_F_USE_ORIG_FWMARK)
fl6.flowi6_mark = skb->mark;
err = ip6_tnl_xmit2(skb, dev, dsfield, &fl6, encap_limit, &mtu);
if (err != 0) {
if (err == -EMSGSIZE)
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED,
htonl(mtu));
return -1;
}
return 0;
}
static inline int
ip6ip6_tnl_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct ipv6hdr *ipv6h = ipv6_hdr(skb);
int encap_limit = -1;
__u16 offset;
struct flowi6 fl6;
__u8 dsfield;
__u32 mtu;
int err;
if ((t->parms.proto != IPPROTO_IPV6 && t->parms.proto != 0) ||
!ip6_tnl_xmit_ctl(t) || ip6_tnl_addr_conflict(t, ipv6h))
return -1;
offset = ip6_tnl_parse_tlv_enc_lim(skb, skb_network_header(skb));
if (offset > 0) {
struct ipv6_tlv_tnl_enc_lim *tel;
tel = (struct ipv6_tlv_tnl_enc_lim *)&skb_network_header(skb)[offset];
if (tel->encap_limit == 0) {
icmpv6_send(skb, ICMPV6_PARAMPROB,
ICMPV6_HDR_FIELD, offset + 2);
return -1;
}
encap_limit = tel->encap_limit - 1;
} else if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
encap_limit = t->parms.encap_limit;
memcpy(&fl6, &t->fl.u.ip6, sizeof (fl6));
fl6.flowi6_proto = IPPROTO_IPV6;
dsfield = ipv6_get_dsfield(ipv6h);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_TCLASS)
fl6.flowlabel |= (*(__be32 *) ipv6h & IPV6_TCLASS_MASK);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_FLOWLABEL)
fl6.flowlabel |= (*(__be32 *) ipv6h & IPV6_FLOWLABEL_MASK);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_FWMARK)
fl6.flowi6_mark = skb->mark;
err = ip6_tnl_xmit2(skb, dev, dsfield, &fl6, encap_limit, &mtu);
if (err != 0) {
if (err == -EMSGSIZE)
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
return -1;
}
return 0;
}
static netdev_tx_t
ip6_tnl_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct net_device_stats *stats = &t->dev->stats;
int ret;
switch (skb->protocol) {
case htons(ETH_P_IP):
ret = ip4ip6_tnl_xmit(skb, dev);
break;
case htons(ETH_P_IPV6):
ret = ip6ip6_tnl_xmit(skb, dev);
break;
default:
goto tx_err;
}
if (ret < 0)
goto tx_err;
return NETDEV_TX_OK;
tx_err:
stats->tx_errors++;
stats->tx_dropped++;
kfree_skb(skb);
return NETDEV_TX_OK;
}
static void ip6_tnl_link_config(struct ip6_tnl *t)
{
struct net_device *dev = t->dev;
struct __ip6_tnl_parm *p = &t->parms;
struct flowi6 *fl6 = &t->fl.u.ip6;
memcpy(dev->dev_addr, &p->laddr, sizeof(struct in6_addr));
memcpy(dev->broadcast, &p->raddr, sizeof(struct in6_addr));
fl6->saddr = p->laddr;
fl6->daddr = p->raddr;
fl6->flowi6_oif = p->link;
fl6->flowlabel = 0;
if (!(p->flags&IP6_TNL_F_USE_ORIG_TCLASS))
fl6->flowlabel |= IPV6_TCLASS_MASK & p->flowinfo;
if (!(p->flags&IP6_TNL_F_USE_ORIG_FLOWLABEL))
fl6->flowlabel |= IPV6_FLOWLABEL_MASK & p->flowinfo;
p->flags &= ~(IP6_TNL_F_CAP_XMIT|IP6_TNL_F_CAP_RCV|IP6_TNL_F_CAP_PER_PACKET);
p->flags |= ip6_tnl_get_cap(t, &p->laddr, &p->raddr);
if (p->flags&IP6_TNL_F_CAP_XMIT && p->flags&IP6_TNL_F_CAP_RCV)
dev->flags |= IFF_POINTOPOINT;
else
dev->flags &= ~IFF_POINTOPOINT;
dev->iflink = p->link;
if (p->flags & IP6_TNL_F_CAP_XMIT) {
int strict = (ipv6_addr_type(&p->raddr) &
(IPV6_ADDR_MULTICAST|IPV6_ADDR_LINKLOCAL));
struct rt6_info *rt = rt6_lookup(dev_net(dev),
&p->raddr, &p->laddr,
p->link, strict);
if (rt == NULL)
return;
if (rt->dst.dev) {
dev->hard_header_len = rt->dst.dev->hard_header_len +
sizeof (struct ipv6hdr);
dev->mtu = rt->dst.dev->mtu - sizeof (struct ipv6hdr);
if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
dev->mtu-=8;
if (dev->mtu < IPV6_MIN_MTU)
dev->mtu = IPV6_MIN_MTU;
}
ip6_rt_put(rt);
}
}
static int
ip6_tnl_change(struct ip6_tnl *t, const struct __ip6_tnl_parm *p)
{
t->parms.laddr = p->laddr;
t->parms.raddr = p->raddr;
t->parms.flags = p->flags;
t->parms.hop_limit = p->hop_limit;
t->parms.encap_limit = p->encap_limit;
t->parms.flowinfo = p->flowinfo;
t->parms.link = p->link;
t->parms.proto = p->proto;
ip6_tnl_dst_reset(t);
ip6_tnl_link_config(t);
return 0;
}
static int ip6_tnl_update(struct ip6_tnl *t, struct __ip6_tnl_parm *p)
{
struct net *net = dev_net(t->dev);
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
int err;
ip6_tnl_unlink(ip6n, t);
synchronize_net();
err = ip6_tnl_change(t, p);
ip6_tnl_link(ip6n, t);
netdev_state_change(t->dev);
return err;
}
static void
ip6_tnl_parm_from_user(struct __ip6_tnl_parm *p, const struct ip6_tnl_parm *u)
{
p->laddr = u->laddr;
p->raddr = u->raddr;
p->flags = u->flags;
p->hop_limit = u->hop_limit;
p->encap_limit = u->encap_limit;
p->flowinfo = u->flowinfo;
p->link = u->link;
p->proto = u->proto;
memcpy(p->name, u->name, sizeof(u->name));
}
static void
ip6_tnl_parm_to_user(struct ip6_tnl_parm *u, const struct __ip6_tnl_parm *p)
{
u->laddr = p->laddr;
u->raddr = p->raddr;
u->flags = p->flags;
u->hop_limit = p->hop_limit;
u->encap_limit = p->encap_limit;
u->flowinfo = p->flowinfo;
u->link = p->link;
u->proto = p->proto;
memcpy(u->name, p->name, sizeof(u->name));
}
static int
ip6_tnl_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip6_tnl_parm p;
struct __ip6_tnl_parm p1;
struct ip6_tnl *t = NULL;
struct net *net = dev_net(dev);
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
switch (cmd) {
case SIOCGETTUNNEL:
if (dev == ip6n->fb_tnl_dev) {
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof (p))) {
err = -EFAULT;
break;
}
ip6_tnl_parm_from_user(&p1, &p);
t = ip6_tnl_locate(net, &p1, 0);
} else {
memset(&p, 0, sizeof(p));
}
if (t == NULL)
t = netdev_priv(dev);
ip6_tnl_parm_to_user(&p, &t->parms);
if (copy_to_user(ifr->ifr_ifru.ifru_data, &p, sizeof (p))) {
err = -EFAULT;
}
break;
case SIOCADDTUNNEL:
case SIOCCHGTUNNEL:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
err = -EFAULT;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof (p)))
break;
err = -EINVAL;
if (p.proto != IPPROTO_IPV6 && p.proto != IPPROTO_IPIP &&
p.proto != 0)
break;
ip6_tnl_parm_from_user(&p1, &p);
t = ip6_tnl_locate(net, &p1, cmd == SIOCADDTUNNEL);
if (dev != ip6n->fb_tnl_dev && cmd == SIOCCHGTUNNEL) {
if (t != NULL) {
if (t->dev != dev) {
err = -EEXIST;
break;
}
} else
t = netdev_priv(dev);
err = ip6_tnl_update(t, &p1);
}
if (t) {
err = 0;
ip6_tnl_parm_to_user(&p, &t->parms);
if (copy_to_user(ifr->ifr_ifru.ifru_data, &p, sizeof(p)))
err = -EFAULT;
} else
err = (cmd == SIOCADDTUNNEL ? -ENOBUFS : -ENOENT);
break;
case SIOCDELTUNNEL:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
break;
if (dev == ip6n->fb_tnl_dev) {
err = -EFAULT;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof (p)))
break;
err = -ENOENT;
ip6_tnl_parm_from_user(&p1, &p);
t = ip6_tnl_locate(net, &p1, 0);
if (t == NULL)
break;
err = -EPERM;
if (t->dev == ip6n->fb_tnl_dev)
break;
dev = t->dev;
}
err = 0;
unregister_netdevice(dev);
break;
default:
err = -EINVAL;
}
return err;
}
static int
ip6_tnl_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < IPV6_MIN_MTU) {
return -EINVAL;
}
dev->mtu = new_mtu;
return 0;
}
static void ip6_tnl_dev_setup(struct net_device *dev)
{
struct ip6_tnl *t;
dev->netdev_ops = &ip6_tnl_netdev_ops;
dev->destructor = ip6_dev_free;
dev->type = ARPHRD_TUNNEL6;
dev->hard_header_len = LL_MAX_HEADER + sizeof (struct ipv6hdr);
dev->mtu = ETH_DATA_LEN - sizeof (struct ipv6hdr);
t = netdev_priv(dev);
if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
dev->mtu-=8;
dev->flags |= IFF_NOARP;
dev->addr_len = sizeof(struct in6_addr);
dev->features |= NETIF_F_NETNS_LOCAL;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
}
static inline int
ip6_tnl_dev_init_gen(struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
t->dev = dev;
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static int ip6_tnl_dev_init(struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
int err = ip6_tnl_dev_init_gen(dev);
if (err)
return err;
ip6_tnl_link_config(t);
return 0;
}
static int __net_init ip6_fb_tnl_dev_init(struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct net *net = dev_net(dev);
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
int err = ip6_tnl_dev_init_gen(dev);
if (err)
return err;
t->parms.proto = IPPROTO_IPV6;
dev_hold(dev);
ip6_tnl_link_config(t);
rcu_assign_pointer(ip6n->tnls_wc[0], t);
return 0;
}
static int ip6_tnl_validate(struct nlattr *tb[], struct nlattr *data[])
{
u8 proto;
if (!data)
return 0;
proto = nla_get_u8(data[IFLA_IPTUN_PROTO]);
if (proto != IPPROTO_IPV6 &&
proto != IPPROTO_IPIP &&
proto != 0)
return -EINVAL;
return 0;
}
static void ip6_tnl_netlink_parms(struct nlattr *data[],
struct __ip6_tnl_parm *parms)
{
memset(parms, 0, sizeof(*parms));
if (!data)
return;
if (data[IFLA_IPTUN_LINK])
parms->link = nla_get_u32(data[IFLA_IPTUN_LINK]);
if (data[IFLA_IPTUN_LOCAL])
nla_memcpy(&parms->laddr, data[IFLA_IPTUN_LOCAL],
sizeof(struct in6_addr));
if (data[IFLA_IPTUN_REMOTE])
nla_memcpy(&parms->raddr, data[IFLA_IPTUN_REMOTE],
sizeof(struct in6_addr));
if (data[IFLA_IPTUN_TTL])
parms->hop_limit = nla_get_u8(data[IFLA_IPTUN_TTL]);
if (data[IFLA_IPTUN_ENCAP_LIMIT])
parms->encap_limit = nla_get_u8(data[IFLA_IPTUN_ENCAP_LIMIT]);
if (data[IFLA_IPTUN_FLOWINFO])
parms->flowinfo = nla_get_be32(data[IFLA_IPTUN_FLOWINFO]);
if (data[IFLA_IPTUN_FLAGS])
parms->flags = nla_get_u32(data[IFLA_IPTUN_FLAGS]);
if (data[IFLA_IPTUN_PROTO])
parms->proto = nla_get_u8(data[IFLA_IPTUN_PROTO]);
}
static int ip6_tnl_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct net *net = dev_net(dev);
struct ip6_tnl *nt;
nt = netdev_priv(dev);
ip6_tnl_netlink_parms(data, &nt->parms);
if (ip6_tnl_locate(net, &nt->parms, 0))
return -EEXIST;
return ip6_tnl_create2(dev);
}
static int ip6_tnl_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip6_tnl *t;
struct __ip6_tnl_parm p;
struct net *net = dev_net(dev);
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
if (dev == ip6n->fb_tnl_dev)
return -EINVAL;
ip6_tnl_netlink_parms(data, &p);
t = ip6_tnl_locate(net, &p, 0);
if (t) {
if (t->dev != dev)
return -EEXIST;
} else
t = netdev_priv(dev);
return ip6_tnl_update(t, &p);
}
static size_t ip6_tnl_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(sizeof(struct in6_addr)) +
nla_total_size(sizeof(struct in6_addr)) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(1) +
0;
}
static int ip6_tnl_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip6_tnl *tunnel = netdev_priv(dev);
struct __ip6_tnl_parm *parm = &tunnel->parms;
if (nla_put_u32(skb, IFLA_IPTUN_LINK, parm->link) ||
nla_put(skb, IFLA_IPTUN_LOCAL, sizeof(struct in6_addr),
&parm->raddr) ||
nla_put(skb, IFLA_IPTUN_REMOTE, sizeof(struct in6_addr),
&parm->laddr) ||
nla_put_u8(skb, IFLA_IPTUN_TTL, parm->hop_limit) ||
nla_put_u8(skb, IFLA_IPTUN_ENCAP_LIMIT, parm->encap_limit) ||
nla_put_be32(skb, IFLA_IPTUN_FLOWINFO, parm->flowinfo) ||
nla_put_u32(skb, IFLA_IPTUN_FLAGS, parm->flags) ||
nla_put_u8(skb, IFLA_IPTUN_PROTO, parm->proto))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static void __net_exit ip6_tnl_destroy_tunnels(struct ip6_tnl_net *ip6n)
{
int h;
struct ip6_tnl *t;
LIST_HEAD(list);
for (h = 0; h < HASH_SIZE; h++) {
t = rtnl_dereference(ip6n->tnls_r_l[h]);
while (t != NULL) {
unregister_netdevice_queue(t->dev, &list);
t = rtnl_dereference(t->next);
}
}
t = rtnl_dereference(ip6n->tnls_wc[0]);
unregister_netdevice_queue(t->dev, &list);
unregister_netdevice_many(&list);
}
static int __net_init ip6_tnl_init_net(struct net *net)
{
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
struct ip6_tnl *t = NULL;
int err;
ip6n->tnls[0] = ip6n->tnls_wc;
ip6n->tnls[1] = ip6n->tnls_r_l;
err = -ENOMEM;
ip6n->fb_tnl_dev = alloc_netdev(sizeof(struct ip6_tnl), "ip6tnl0",
ip6_tnl_dev_setup);
if (!ip6n->fb_tnl_dev)
goto err_alloc_dev;
dev_net_set(ip6n->fb_tnl_dev, net);
err = ip6_fb_tnl_dev_init(ip6n->fb_tnl_dev);
if (err < 0)
goto err_register;
err = register_netdev(ip6n->fb_tnl_dev);
if (err < 0)
goto err_register;
t = netdev_priv(ip6n->fb_tnl_dev);
strcpy(t->parms.name, ip6n->fb_tnl_dev->name);
return 0;
err_register:
ip6_dev_free(ip6n->fb_tnl_dev);
err_alloc_dev:
return err;
}
static void __net_exit ip6_tnl_exit_net(struct net *net)
{
struct ip6_tnl_net *ip6n = net_generic(net, ip6_tnl_net_id);
rtnl_lock();
ip6_tnl_destroy_tunnels(ip6n);
rtnl_unlock();
}
static int __init ip6_tunnel_init(void)
{
int err;
err = register_pernet_device(&ip6_tnl_net_ops);
if (err < 0)
goto out_pernet;
err = xfrm6_tunnel_register(&ip4ip6_handler, AF_INET);
if (err < 0) {
pr_err("%s: can't register ip4ip6\n", __func__);
goto out_ip4ip6;
}
err = xfrm6_tunnel_register(&ip6ip6_handler, AF_INET6);
if (err < 0) {
pr_err("%s: can't register ip6ip6\n", __func__);
goto out_ip6ip6;
}
err = rtnl_link_register(&ip6_link_ops);
if (err < 0)
goto rtnl_link_failed;
return 0;
rtnl_link_failed:
xfrm6_tunnel_deregister(&ip6ip6_handler, AF_INET6);
out_ip6ip6:
xfrm6_tunnel_deregister(&ip4ip6_handler, AF_INET);
out_ip4ip6:
unregister_pernet_device(&ip6_tnl_net_ops);
out_pernet:
return err;
}
static void __exit ip6_tunnel_cleanup(void)
{
rtnl_link_unregister(&ip6_link_ops);
if (xfrm6_tunnel_deregister(&ip4ip6_handler, AF_INET))
pr_info("%s: can't deregister ip4ip6\n", __func__);
if (xfrm6_tunnel_deregister(&ip6ip6_handler, AF_INET6))
pr_info("%s: can't deregister ip6ip6\n", __func__);
unregister_pernet_device(&ip6_tnl_net_ops);
}
