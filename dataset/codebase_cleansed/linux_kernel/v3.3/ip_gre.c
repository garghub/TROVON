static struct net_device_stats *ipgre_get_stats(struct net_device *dev)
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
static struct ip_tunnel * ipgre_tunnel_lookup(struct net_device *dev,
__be32 remote, __be32 local,
__be32 key, __be16 gre_proto)
{
struct net *net = dev_net(dev);
int link = dev->ifindex;
unsigned int h0 = HASH(remote);
unsigned int h1 = HASH(key);
struct ip_tunnel *t, *cand = NULL;
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
int dev_type = (gre_proto == htons(ETH_P_TEB)) ?
ARPHRD_ETHER : ARPHRD_IPGRE;
int score, cand_score = 4;
for_each_ip_tunnel_rcu(ign->tunnels_r_l[h0 ^ h1]) {
if (local != t->parms.iph.saddr ||
remote != t->parms.iph.daddr ||
key != t->parms.i_key ||
!(t->dev->flags & IFF_UP))
continue;
if (t->dev->type != ARPHRD_IPGRE &&
t->dev->type != dev_type)
continue;
score = 0;
if (t->parms.link != link)
score |= 1;
if (t->dev->type != dev_type)
score |= 2;
if (score == 0)
return t;
if (score < cand_score) {
cand = t;
cand_score = score;
}
}
for_each_ip_tunnel_rcu(ign->tunnels_r[h0 ^ h1]) {
if (remote != t->parms.iph.daddr ||
key != t->parms.i_key ||
!(t->dev->flags & IFF_UP))
continue;
if (t->dev->type != ARPHRD_IPGRE &&
t->dev->type != dev_type)
continue;
score = 0;
if (t->parms.link != link)
score |= 1;
if (t->dev->type != dev_type)
score |= 2;
if (score == 0)
return t;
if (score < cand_score) {
cand = t;
cand_score = score;
}
}
for_each_ip_tunnel_rcu(ign->tunnels_l[h1]) {
if ((local != t->parms.iph.saddr &&
(local != t->parms.iph.daddr ||
!ipv4_is_multicast(local))) ||
key != t->parms.i_key ||
!(t->dev->flags & IFF_UP))
continue;
if (t->dev->type != ARPHRD_IPGRE &&
t->dev->type != dev_type)
continue;
score = 0;
if (t->parms.link != link)
score |= 1;
if (t->dev->type != dev_type)
score |= 2;
if (score == 0)
return t;
if (score < cand_score) {
cand = t;
cand_score = score;
}
}
for_each_ip_tunnel_rcu(ign->tunnels_wc[h1]) {
if (t->parms.i_key != key ||
!(t->dev->flags & IFF_UP))
continue;
if (t->dev->type != ARPHRD_IPGRE &&
t->dev->type != dev_type)
continue;
score = 0;
if (t->parms.link != link)
score |= 1;
if (t->dev->type != dev_type)
score |= 2;
if (score == 0)
return t;
if (score < cand_score) {
cand = t;
cand_score = score;
}
}
if (cand != NULL)
return cand;
dev = ign->fb_tunnel_dev;
if (dev->flags & IFF_UP)
return netdev_priv(dev);
return NULL;
}
static struct ip_tunnel __rcu **__ipgre_bucket(struct ipgre_net *ign,
struct ip_tunnel_parm *parms)
{
__be32 remote = parms->iph.daddr;
__be32 local = parms->iph.saddr;
__be32 key = parms->i_key;
unsigned int h = HASH(key);
int prio = 0;
if (local)
prio |= 1;
if (remote && !ipv4_is_multicast(remote)) {
prio |= 2;
h ^= HASH(remote);
}
return &ign->tunnels[prio][h];
}
static inline struct ip_tunnel __rcu **ipgre_bucket(struct ipgre_net *ign,
struct ip_tunnel *t)
{
return __ipgre_bucket(ign, &t->parms);
}
static void ipgre_tunnel_link(struct ipgre_net *ign, struct ip_tunnel *t)
{
struct ip_tunnel __rcu **tp = ipgre_bucket(ign, t);
rcu_assign_pointer(t->next, rtnl_dereference(*tp));
rcu_assign_pointer(*tp, t);
}
static void ipgre_tunnel_unlink(struct ipgre_net *ign, struct ip_tunnel *t)
{
struct ip_tunnel __rcu **tp;
struct ip_tunnel *iter;
for (tp = ipgre_bucket(ign, t);
(iter = rtnl_dereference(*tp)) != NULL;
tp = &iter->next) {
if (t == iter) {
rcu_assign_pointer(*tp, t->next);
break;
}
}
}
static struct ip_tunnel *ipgre_tunnel_find(struct net *net,
struct ip_tunnel_parm *parms,
int type)
{
__be32 remote = parms->iph.daddr;
__be32 local = parms->iph.saddr;
__be32 key = parms->i_key;
int link = parms->link;
struct ip_tunnel *t;
struct ip_tunnel __rcu **tp;
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
for (tp = __ipgre_bucket(ign, parms);
(t = rtnl_dereference(*tp)) != NULL;
tp = &t->next)
if (local == t->parms.iph.saddr &&
remote == t->parms.iph.daddr &&
key == t->parms.i_key &&
link == t->parms.link &&
type == t->dev->type)
break;
return t;
}
static struct ip_tunnel *ipgre_tunnel_locate(struct net *net,
struct ip_tunnel_parm *parms, int create)
{
struct ip_tunnel *t, *nt;
struct net_device *dev;
char name[IFNAMSIZ];
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
t = ipgre_tunnel_find(net, parms, ARPHRD_IPGRE);
if (t || !create)
return t;
if (parms->name[0])
strlcpy(name, parms->name, IFNAMSIZ);
else
strcpy(name, "gre%d");
dev = alloc_netdev(sizeof(*t), name, ipgre_tunnel_setup);
if (!dev)
return NULL;
dev_net_set(dev, net);
nt = netdev_priv(dev);
nt->parms = *parms;
dev->rtnl_link_ops = &ipgre_link_ops;
dev->mtu = ipgre_tunnel_bind_dev(dev);
if (register_netdevice(dev) < 0)
goto failed_free;
if (!(nt->parms.o_flags & GRE_SEQ))
dev->features |= NETIF_F_LLTX;
dev_hold(dev);
ipgre_tunnel_link(ign, nt);
return nt;
failed_free:
free_netdev(dev);
return NULL;
}
static void ipgre_tunnel_uninit(struct net_device *dev)
{
struct net *net = dev_net(dev);
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
ipgre_tunnel_unlink(ign, netdev_priv(dev));
dev_put(dev);
}
static void ipgre_err(struct sk_buff *skb, u32 info)
{
const struct iphdr *iph = (const struct iphdr *)skb->data;
__be16 *p = (__be16*)(skb->data+(iph->ihl<<2));
int grehlen = (iph->ihl<<2) + 4;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct ip_tunnel *t;
__be16 flags;
flags = p[0];
if (flags&(GRE_CSUM|GRE_KEY|GRE_SEQ|GRE_ROUTING|GRE_VERSION)) {
if (flags&(GRE_VERSION|GRE_ROUTING))
return;
if (flags&GRE_KEY) {
grehlen += 4;
if (flags&GRE_CSUM)
grehlen += 4;
}
}
if (skb_headlen(skb) < grehlen)
return;
switch (type) {
default:
case ICMP_PARAMETERPROB:
return;
case ICMP_DEST_UNREACH:
switch (code) {
case ICMP_SR_FAILED:
case ICMP_PORT_UNREACH:
return;
case ICMP_FRAG_NEEDED:
return;
default:
break;
}
break;
case ICMP_TIME_EXCEEDED:
if (code != ICMP_EXC_TTL)
return;
break;
}
rcu_read_lock();
t = ipgre_tunnel_lookup(skb->dev, iph->daddr, iph->saddr,
flags & GRE_KEY ?
*(((__be32 *)p) + (grehlen / 4) - 1) : 0,
p[1]);
if (t == NULL || t->parms.iph.daddr == 0 ||
ipv4_is_multicast(t->parms.iph.daddr))
goto out;
if (t->parms.iph.ttl == 0 && type == ICMP_TIME_EXCEEDED)
goto out;
if (time_before(jiffies, t->err_time + IPTUNNEL_ERR_TIMEO))
t->err_count++;
else
t->err_count = 1;
t->err_time = jiffies;
out:
rcu_read_unlock();
}
static inline void ipgre_ecn_decapsulate(const struct iphdr *iph, struct sk_buff *skb)
{
if (INET_ECN_is_ce(iph->tos)) {
if (skb->protocol == htons(ETH_P_IP)) {
IP_ECN_set_ce(ip_hdr(skb));
} else if (skb->protocol == htons(ETH_P_IPV6)) {
IP6_ECN_set_ce(ipv6_hdr(skb));
}
}
}
static inline u8
ipgre_ecn_encapsulate(u8 tos, const struct iphdr *old_iph, struct sk_buff *skb)
{
u8 inner = 0;
if (skb->protocol == htons(ETH_P_IP))
inner = old_iph->tos;
else if (skb->protocol == htons(ETH_P_IPV6))
inner = ipv6_get_dsfield((const struct ipv6hdr *)old_iph);
return INET_ECN_encapsulate(tos, inner);
}
static int ipgre_rcv(struct sk_buff *skb)
{
const struct iphdr *iph;
u8 *h;
__be16 flags;
__sum16 csum = 0;
__be32 key = 0;
u32 seqno = 0;
struct ip_tunnel *tunnel;
int offset = 4;
__be16 gre_proto;
if (!pskb_may_pull(skb, 16))
goto drop_nolock;
iph = ip_hdr(skb);
h = skb->data;
flags = *(__be16*)h;
if (flags&(GRE_CSUM|GRE_KEY|GRE_ROUTING|GRE_SEQ|GRE_VERSION)) {
if (flags&(GRE_VERSION|GRE_ROUTING))
goto drop_nolock;
if (flags&GRE_CSUM) {
switch (skb->ip_summed) {
case CHECKSUM_COMPLETE:
csum = csum_fold(skb->csum);
if (!csum)
break;
case CHECKSUM_NONE:
skb->csum = 0;
csum = __skb_checksum_complete(skb);
skb->ip_summed = CHECKSUM_COMPLETE;
}
offset += 4;
}
if (flags&GRE_KEY) {
key = *(__be32*)(h + offset);
offset += 4;
}
if (flags&GRE_SEQ) {
seqno = ntohl(*(__be32*)(h + offset));
offset += 4;
}
}
gre_proto = *(__be16 *)(h + 2);
rcu_read_lock();
if ((tunnel = ipgre_tunnel_lookup(skb->dev,
iph->saddr, iph->daddr, key,
gre_proto))) {
struct pcpu_tstats *tstats;
secpath_reset(skb);
skb->protocol = gre_proto;
if (flags == 0 && gre_proto == htons(ETH_P_WCCP)) {
skb->protocol = htons(ETH_P_IP);
if ((*(h + offset) & 0xF0) != 0x40)
offset += 4;
}
skb->mac_header = skb->network_header;
__pskb_pull(skb, offset);
skb_postpull_rcsum(skb, skb_transport_header(skb), offset);
skb->pkt_type = PACKET_HOST;
#ifdef CONFIG_NET_IPGRE_BROADCAST
if (ipv4_is_multicast(iph->daddr)) {
if (rt_is_output_route(skb_rtable(skb)))
goto drop;
tunnel->dev->stats.multicast++;
skb->pkt_type = PACKET_BROADCAST;
}
#endif
if (((flags&GRE_CSUM) && csum) ||
(!(flags&GRE_CSUM) && tunnel->parms.i_flags&GRE_CSUM)) {
tunnel->dev->stats.rx_crc_errors++;
tunnel->dev->stats.rx_errors++;
goto drop;
}
if (tunnel->parms.i_flags&GRE_SEQ) {
if (!(flags&GRE_SEQ) ||
(tunnel->i_seqno && (s32)(seqno - tunnel->i_seqno) < 0)) {
tunnel->dev->stats.rx_fifo_errors++;
tunnel->dev->stats.rx_errors++;
goto drop;
}
tunnel->i_seqno = seqno + 1;
}
if (tunnel->dev->type == ARPHRD_ETHER) {
if (!pskb_may_pull(skb, ETH_HLEN)) {
tunnel->dev->stats.rx_length_errors++;
tunnel->dev->stats.rx_errors++;
goto drop;
}
iph = ip_hdr(skb);
skb->protocol = eth_type_trans(skb, tunnel->dev);
skb_postpull_rcsum(skb, eth_hdr(skb), ETH_HLEN);
}
tstats = this_cpu_ptr(tunnel->dev->tstats);
tstats->rx_packets++;
tstats->rx_bytes += skb->len;
__skb_tunnel_rx(skb, tunnel->dev);
skb_reset_network_header(skb);
ipgre_ecn_decapsulate(iph, skb);
netif_rx(skb);
rcu_read_unlock();
return 0;
}
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
drop:
rcu_read_unlock();
drop_nolock:
kfree_skb(skb);
return 0;
}
static netdev_tx_t ipgre_tunnel_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct pcpu_tstats *tstats;
const struct iphdr *old_iph = ip_hdr(skb);
const struct iphdr *tiph;
struct flowi4 fl4;
u8 tos;
__be16 df;
struct rtable *rt;
struct net_device *tdev;
struct iphdr *iph;
unsigned int max_headroom;
int gre_hlen;
__be32 dst;
int mtu;
if (dev->type == ARPHRD_ETHER)
IPCB(skb)->flags = 0;
if (dev->header_ops && dev->type == ARPHRD_IPGRE) {
gre_hlen = 0;
tiph = (const struct iphdr *)skb->data;
} else {
gre_hlen = tunnel->hlen;
tiph = &tunnel->parms.iph;
}
if ((dst = tiph->daddr) == 0) {
if (skb_dst(skb) == NULL) {
dev->stats.tx_fifo_errors++;
goto tx_error;
}
if (skb->protocol == htons(ETH_P_IP)) {
rt = skb_rtable(skb);
if ((dst = rt->rt_gateway) == 0)
goto tx_error_icmp;
}
#if IS_ENABLED(CONFIG_IPV6)
else if (skb->protocol == htons(ETH_P_IPV6)) {
struct neighbour *neigh = dst_get_neighbour_noref(skb_dst(skb));
const struct in6_addr *addr6;
int addr_type;
if (neigh == NULL)
goto tx_error;
addr6 = (const struct in6_addr *)&neigh->primary_key;
addr_type = ipv6_addr_type(addr6);
if (addr_type == IPV6_ADDR_ANY) {
addr6 = &ipv6_hdr(skb)->daddr;
addr_type = ipv6_addr_type(addr6);
}
if ((addr_type & IPV6_ADDR_COMPATv4) == 0)
goto tx_error_icmp;
dst = addr6->s6_addr32[3];
}
#endif
else
goto tx_error;
}
tos = tiph->tos;
if (tos == 1) {
tos = 0;
if (skb->protocol == htons(ETH_P_IP))
tos = old_iph->tos;
else if (skb->protocol == htons(ETH_P_IPV6))
tos = ipv6_get_dsfield((const struct ipv6hdr *)old_iph);
}
rt = ip_route_output_gre(dev_net(dev), &fl4, dst, tiph->saddr,
tunnel->parms.o_key, RT_TOS(tos),
tunnel->parms.link);
if (IS_ERR(rt)) {
dev->stats.tx_carrier_errors++;
goto tx_error;
}
tdev = rt->dst.dev;
if (tdev == dev) {
ip_rt_put(rt);
dev->stats.collisions++;
goto tx_error;
}
df = tiph->frag_off;
if (df)
mtu = dst_mtu(&rt->dst) - dev->hard_header_len - tunnel->hlen;
else
mtu = skb_dst(skb) ? dst_mtu(skb_dst(skb)) : dev->mtu;
if (skb_dst(skb))
skb_dst(skb)->ops->update_pmtu(skb_dst(skb), mtu);
if (skb->protocol == htons(ETH_P_IP)) {
df |= (old_iph->frag_off&htons(IP_DF));
if ((old_iph->frag_off&htons(IP_DF)) &&
mtu < ntohs(old_iph->tot_len)) {
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED, htonl(mtu));
ip_rt_put(rt);
goto tx_error;
}
}
#if IS_ENABLED(CONFIG_IPV6)
else if (skb->protocol == htons(ETH_P_IPV6)) {
struct rt6_info *rt6 = (struct rt6_info *)skb_dst(skb);
if (rt6 && mtu < dst_mtu(skb_dst(skb)) && mtu >= IPV6_MIN_MTU) {
if ((tunnel->parms.iph.daddr &&
!ipv4_is_multicast(tunnel->parms.iph.daddr)) ||
rt6->rt6i_dst.plen == 128) {
rt6->rt6i_flags |= RTF_MODIFIED;
dst_metric_set(skb_dst(skb), RTAX_MTU, mtu);
}
}
if (mtu >= IPV6_MIN_MTU && mtu < skb->len - tunnel->hlen + gre_hlen) {
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
ip_rt_put(rt);
goto tx_error;
}
}
#endif
if (tunnel->err_count > 0) {
if (time_before(jiffies,
tunnel->err_time + IPTUNNEL_ERR_TIMEO)) {
tunnel->err_count--;
dst_link_failure(skb);
} else
tunnel->err_count = 0;
}
max_headroom = LL_RESERVED_SPACE(tdev) + gre_hlen + rt->dst.header_len;
if (skb_headroom(skb) < max_headroom || skb_shared(skb)||
(skb_cloned(skb) && !skb_clone_writable(skb, 0))) {
struct sk_buff *new_skb = skb_realloc_headroom(skb, max_headroom);
if (max_headroom > dev->needed_headroom)
dev->needed_headroom = max_headroom;
if (!new_skb) {
ip_rt_put(rt);
dev->stats.tx_dropped++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
if (skb->sk)
skb_set_owner_w(new_skb, skb->sk);
dev_kfree_skb(skb);
skb = new_skb;
old_iph = ip_hdr(skb);
}
skb_reset_transport_header(skb);
skb_push(skb, gre_hlen);
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
IPCB(skb)->flags &= ~(IPSKB_XFRM_TUNNEL_SIZE | IPSKB_XFRM_TRANSFORMED |
IPSKB_REROUTED);
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
iph = ip_hdr(skb);
iph->version = 4;
iph->ihl = sizeof(struct iphdr) >> 2;
iph->frag_off = df;
iph->protocol = IPPROTO_GRE;
iph->tos = ipgre_ecn_encapsulate(tos, old_iph, skb);
iph->daddr = fl4.daddr;
iph->saddr = fl4.saddr;
if ((iph->ttl = tiph->ttl) == 0) {
if (skb->protocol == htons(ETH_P_IP))
iph->ttl = old_iph->ttl;
#if IS_ENABLED(CONFIG_IPV6)
else if (skb->protocol == htons(ETH_P_IPV6))
iph->ttl = ((const struct ipv6hdr *)old_iph)->hop_limit;
#endif
else
iph->ttl = ip4_dst_hoplimit(&rt->dst);
}
((__be16 *)(iph + 1))[0] = tunnel->parms.o_flags;
((__be16 *)(iph + 1))[1] = (dev->type == ARPHRD_ETHER) ?
htons(ETH_P_TEB) : skb->protocol;
if (tunnel->parms.o_flags&(GRE_KEY|GRE_CSUM|GRE_SEQ)) {
__be32 *ptr = (__be32*)(((u8*)iph) + tunnel->hlen - 4);
if (tunnel->parms.o_flags&GRE_SEQ) {
++tunnel->o_seqno;
*ptr = htonl(tunnel->o_seqno);
ptr--;
}
if (tunnel->parms.o_flags&GRE_KEY) {
*ptr = tunnel->parms.o_key;
ptr--;
}
if (tunnel->parms.o_flags&GRE_CSUM) {
*ptr = 0;
*(__sum16*)ptr = ip_compute_csum((void*)(iph+1), skb->len - sizeof(struct iphdr));
}
}
nf_reset(skb);
tstats = this_cpu_ptr(dev->tstats);
__IPTUNNEL_XMIT(tstats, &dev->stats);
return NETDEV_TX_OK;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
dev->stats.tx_errors++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int ipgre_tunnel_bind_dev(struct net_device *dev)
{
struct net_device *tdev = NULL;
struct ip_tunnel *tunnel;
const struct iphdr *iph;
int hlen = LL_MAX_HEADER;
int mtu = ETH_DATA_LEN;
int addend = sizeof(struct iphdr) + 4;
tunnel = netdev_priv(dev);
iph = &tunnel->parms.iph;
if (iph->daddr) {
struct flowi4 fl4;
struct rtable *rt;
rt = ip_route_output_gre(dev_net(dev), &fl4,
iph->daddr, iph->saddr,
tunnel->parms.o_key,
RT_TOS(iph->tos),
tunnel->parms.link);
if (!IS_ERR(rt)) {
tdev = rt->dst.dev;
ip_rt_put(rt);
}
if (dev->type != ARPHRD_ETHER)
dev->flags |= IFF_POINTOPOINT;
}
if (!tdev && tunnel->parms.link)
tdev = __dev_get_by_index(dev_net(dev), tunnel->parms.link);
if (tdev) {
hlen = tdev->hard_header_len + tdev->needed_headroom;
mtu = tdev->mtu;
}
dev->iflink = tunnel->parms.link;
if (tunnel->parms.o_flags&(GRE_CSUM|GRE_KEY|GRE_SEQ)) {
if (tunnel->parms.o_flags&GRE_CSUM)
addend += 4;
if (tunnel->parms.o_flags&GRE_KEY)
addend += 4;
if (tunnel->parms.o_flags&GRE_SEQ)
addend += 4;
}
dev->needed_headroom = addend + hlen;
mtu -= dev->hard_header_len + addend;
if (mtu < 68)
mtu = 68;
tunnel->hlen = addend;
return mtu;
}
static int
ipgre_tunnel_ioctl (struct net_device *dev, struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip_tunnel_parm p;
struct ip_tunnel *t;
struct net *net = dev_net(dev);
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
switch (cmd) {
case SIOCGETTUNNEL:
t = NULL;
if (dev == ign->fb_tunnel_dev) {
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p))) {
err = -EFAULT;
break;
}
t = ipgre_tunnel_locate(net, &p, 0);
}
if (t == NULL)
t = netdev_priv(dev);
memcpy(&p, &t->parms, sizeof(p));
if (copy_to_user(ifr->ifr_ifru.ifru_data, &p, sizeof(p)))
err = -EFAULT;
break;
case SIOCADDTUNNEL:
case SIOCCHGTUNNEL:
err = -EPERM;
if (!capable(CAP_NET_ADMIN))
goto done;
err = -EFAULT;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
goto done;
err = -EINVAL;
if (p.iph.version != 4 || p.iph.protocol != IPPROTO_GRE ||
p.iph.ihl != 5 || (p.iph.frag_off&htons(~IP_DF)) ||
((p.i_flags|p.o_flags)&(GRE_VERSION|GRE_ROUTING)))
goto done;
if (p.iph.ttl)
p.iph.frag_off |= htons(IP_DF);
if (!(p.i_flags&GRE_KEY))
p.i_key = 0;
if (!(p.o_flags&GRE_KEY))
p.o_key = 0;
t = ipgre_tunnel_locate(net, &p, cmd == SIOCADDTUNNEL);
if (dev != ign->fb_tunnel_dev && cmd == SIOCCHGTUNNEL) {
if (t != NULL) {
if (t->dev != dev) {
err = -EEXIST;
break;
}
} else {
unsigned int nflags = 0;
t = netdev_priv(dev);
if (ipv4_is_multicast(p.iph.daddr))
nflags = IFF_BROADCAST;
else if (p.iph.daddr)
nflags = IFF_POINTOPOINT;
if ((dev->flags^nflags)&(IFF_POINTOPOINT|IFF_BROADCAST)) {
err = -EINVAL;
break;
}
ipgre_tunnel_unlink(ign, t);
synchronize_net();
t->parms.iph.saddr = p.iph.saddr;
t->parms.iph.daddr = p.iph.daddr;
t->parms.i_key = p.i_key;
t->parms.o_key = p.o_key;
memcpy(dev->dev_addr, &p.iph.saddr, 4);
memcpy(dev->broadcast, &p.iph.daddr, 4);
ipgre_tunnel_link(ign, t);
netdev_state_change(dev);
}
}
if (t) {
err = 0;
if (cmd == SIOCCHGTUNNEL) {
t->parms.iph.ttl = p.iph.ttl;
t->parms.iph.tos = p.iph.tos;
t->parms.iph.frag_off = p.iph.frag_off;
if (t->parms.link != p.link) {
t->parms.link = p.link;
dev->mtu = ipgre_tunnel_bind_dev(dev);
netdev_state_change(dev);
}
}
if (copy_to_user(ifr->ifr_ifru.ifru_data, &t->parms, sizeof(p)))
err = -EFAULT;
} else
err = (cmd == SIOCADDTUNNEL ? -ENOBUFS : -ENOENT);
break;
case SIOCDELTUNNEL:
err = -EPERM;
if (!capable(CAP_NET_ADMIN))
goto done;
if (dev == ign->fb_tunnel_dev) {
err = -EFAULT;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
goto done;
err = -ENOENT;
if ((t = ipgre_tunnel_locate(net, &p, 0)) == NULL)
goto done;
err = -EPERM;
if (t == netdev_priv(ign->fb_tunnel_dev))
goto done;
dev = t->dev;
}
unregister_netdevice(dev);
err = 0;
break;
default:
err = -EINVAL;
}
done:
return err;
}
static int ipgre_tunnel_change_mtu(struct net_device *dev, int new_mtu)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
if (new_mtu < 68 ||
new_mtu > 0xFFF8 - dev->hard_header_len - tunnel->hlen)
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static int ipgre_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr, unsigned int len)
{
struct ip_tunnel *t = netdev_priv(dev);
struct iphdr *iph = (struct iphdr *)skb_push(skb, t->hlen);
__be16 *p = (__be16*)(iph+1);
memcpy(iph, &t->parms.iph, sizeof(struct iphdr));
p[0] = t->parms.o_flags;
p[1] = htons(type);
if (saddr)
memcpy(&iph->saddr, saddr, 4);
if (daddr)
memcpy(&iph->daddr, daddr, 4);
if (iph->daddr)
return t->hlen;
return -t->hlen;
}
static int ipgre_header_parse(const struct sk_buff *skb, unsigned char *haddr)
{
const struct iphdr *iph = (const struct iphdr *) skb_mac_header(skb);
memcpy(haddr, &iph->saddr, 4);
return 4;
}
static int ipgre_open(struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
if (ipv4_is_multicast(t->parms.iph.daddr)) {
struct flowi4 fl4;
struct rtable *rt;
rt = ip_route_output_gre(dev_net(dev), &fl4,
t->parms.iph.daddr,
t->parms.iph.saddr,
t->parms.o_key,
RT_TOS(t->parms.iph.tos),
t->parms.link);
if (IS_ERR(rt))
return -EADDRNOTAVAIL;
dev = rt->dst.dev;
ip_rt_put(rt);
if (__in_dev_get_rtnl(dev) == NULL)
return -EADDRNOTAVAIL;
t->mlink = dev->ifindex;
ip_mc_inc_group(__in_dev_get_rtnl(dev), t->parms.iph.daddr);
}
return 0;
}
static int ipgre_close(struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
if (ipv4_is_multicast(t->parms.iph.daddr) && t->mlink) {
struct in_device *in_dev;
in_dev = inetdev_by_index(dev_net(dev), t->mlink);
if (in_dev)
ip_mc_dec_group(in_dev, t->parms.iph.daddr);
}
return 0;
}
static void ipgre_dev_free(struct net_device *dev)
{
free_percpu(dev->tstats);
free_netdev(dev);
}
static void ipgre_tunnel_setup(struct net_device *dev)
{
dev->netdev_ops = &ipgre_netdev_ops;
dev->destructor = ipgre_dev_free;
dev->type = ARPHRD_IPGRE;
dev->needed_headroom = LL_MAX_HEADER + sizeof(struct iphdr) + 4;
dev->mtu = ETH_DATA_LEN - sizeof(struct iphdr) - 4;
dev->flags = IFF_NOARP;
dev->iflink = 0;
dev->addr_len = 4;
dev->features |= NETIF_F_NETNS_LOCAL;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
}
static int ipgre_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel;
struct iphdr *iph;
tunnel = netdev_priv(dev);
iph = &tunnel->parms.iph;
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
memcpy(dev->dev_addr, &tunnel->parms.iph.saddr, 4);
memcpy(dev->broadcast, &tunnel->parms.iph.daddr, 4);
if (iph->daddr) {
#ifdef CONFIG_NET_IPGRE_BROADCAST
if (ipv4_is_multicast(iph->daddr)) {
if (!iph->saddr)
return -EINVAL;
dev->flags = IFF_BROADCAST;
dev->header_ops = &ipgre_header_ops;
}
#endif
} else
dev->header_ops = &ipgre_header_ops;
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static void ipgre_fb_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct iphdr *iph = &tunnel->parms.iph;
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
iph->version = 4;
iph->protocol = IPPROTO_GRE;
iph->ihl = 5;
tunnel->hlen = sizeof(struct iphdr) + 4;
dev_hold(dev);
}
static void ipgre_destroy_tunnels(struct ipgre_net *ign, struct list_head *head)
{
int prio;
for (prio = 0; prio < 4; prio++) {
int h;
for (h = 0; h < HASH_SIZE; h++) {
struct ip_tunnel *t;
t = rtnl_dereference(ign->tunnels[prio][h]);
while (t != NULL) {
unregister_netdevice_queue(t->dev, head);
t = rtnl_dereference(t->next);
}
}
}
}
static int __net_init ipgre_init_net(struct net *net)
{
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
int err;
ign->fb_tunnel_dev = alloc_netdev(sizeof(struct ip_tunnel), "gre0",
ipgre_tunnel_setup);
if (!ign->fb_tunnel_dev) {
err = -ENOMEM;
goto err_alloc_dev;
}
dev_net_set(ign->fb_tunnel_dev, net);
ipgre_fb_tunnel_init(ign->fb_tunnel_dev);
ign->fb_tunnel_dev->rtnl_link_ops = &ipgre_link_ops;
if ((err = register_netdev(ign->fb_tunnel_dev)))
goto err_reg_dev;
rcu_assign_pointer(ign->tunnels_wc[0],
netdev_priv(ign->fb_tunnel_dev));
return 0;
err_reg_dev:
ipgre_dev_free(ign->fb_tunnel_dev);
err_alloc_dev:
return err;
}
static void __net_exit ipgre_exit_net(struct net *net)
{
struct ipgre_net *ign;
LIST_HEAD(list);
ign = net_generic(net, ipgre_net_id);
rtnl_lock();
ipgre_destroy_tunnels(ign, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
}
static int ipgre_tunnel_validate(struct nlattr *tb[], struct nlattr *data[])
{
__be16 flags;
if (!data)
return 0;
flags = 0;
if (data[IFLA_GRE_IFLAGS])
flags |= nla_get_be16(data[IFLA_GRE_IFLAGS]);
if (data[IFLA_GRE_OFLAGS])
flags |= nla_get_be16(data[IFLA_GRE_OFLAGS]);
if (flags & (GRE_VERSION|GRE_ROUTING))
return -EINVAL;
return 0;
}
static int ipgre_tap_validate(struct nlattr *tb[], struct nlattr *data[])
{
__be32 daddr;
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
if (!data)
goto out;
if (data[IFLA_GRE_REMOTE]) {
memcpy(&daddr, nla_data(data[IFLA_GRE_REMOTE]), 4);
if (!daddr)
return -EINVAL;
}
out:
return ipgre_tunnel_validate(tb, data);
}
static void ipgre_netlink_parms(struct nlattr *data[],
struct ip_tunnel_parm *parms)
{
memset(parms, 0, sizeof(*parms));
parms->iph.protocol = IPPROTO_GRE;
if (!data)
return;
if (data[IFLA_GRE_LINK])
parms->link = nla_get_u32(data[IFLA_GRE_LINK]);
if (data[IFLA_GRE_IFLAGS])
parms->i_flags = nla_get_be16(data[IFLA_GRE_IFLAGS]);
if (data[IFLA_GRE_OFLAGS])
parms->o_flags = nla_get_be16(data[IFLA_GRE_OFLAGS]);
if (data[IFLA_GRE_IKEY])
parms->i_key = nla_get_be32(data[IFLA_GRE_IKEY]);
if (data[IFLA_GRE_OKEY])
parms->o_key = nla_get_be32(data[IFLA_GRE_OKEY]);
if (data[IFLA_GRE_LOCAL])
parms->iph.saddr = nla_get_be32(data[IFLA_GRE_LOCAL]);
if (data[IFLA_GRE_REMOTE])
parms->iph.daddr = nla_get_be32(data[IFLA_GRE_REMOTE]);
if (data[IFLA_GRE_TTL])
parms->iph.ttl = nla_get_u8(data[IFLA_GRE_TTL]);
if (data[IFLA_GRE_TOS])
parms->iph.tos = nla_get_u8(data[IFLA_GRE_TOS]);
if (!data[IFLA_GRE_PMTUDISC] || nla_get_u8(data[IFLA_GRE_PMTUDISC]))
parms->iph.frag_off = htons(IP_DF);
}
static int ipgre_tap_init(struct net_device *dev)
{
struct ip_tunnel *tunnel;
tunnel = netdev_priv(dev);
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
ipgre_tunnel_bind_dev(dev);
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static void ipgre_tap_setup(struct net_device *dev)
{
ether_setup(dev);
dev->netdev_ops = &ipgre_tap_netdev_ops;
dev->destructor = ipgre_dev_free;
dev->iflink = 0;
dev->features |= NETIF_F_NETNS_LOCAL;
}
static int ipgre_newlink(struct net *src_net, struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel *nt;
struct net *net = dev_net(dev);
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
int mtu;
int err;
nt = netdev_priv(dev);
ipgre_netlink_parms(data, &nt->parms);
if (ipgre_tunnel_find(net, &nt->parms, dev->type))
return -EEXIST;
if (dev->type == ARPHRD_ETHER && !tb[IFLA_ADDRESS])
random_ether_addr(dev->dev_addr);
mtu = ipgre_tunnel_bind_dev(dev);
if (!tb[IFLA_MTU])
dev->mtu = mtu;
if (!(nt->parms.o_flags & GRE_SEQ))
dev->features |= NETIF_F_LLTX;
err = register_netdevice(dev);
if (err)
goto out;
dev_hold(dev);
ipgre_tunnel_link(ign, nt);
out:
return err;
}
static int ipgre_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel *t, *nt;
struct net *net = dev_net(dev);
struct ipgre_net *ign = net_generic(net, ipgre_net_id);
struct ip_tunnel_parm p;
int mtu;
if (dev == ign->fb_tunnel_dev)
return -EINVAL;
nt = netdev_priv(dev);
ipgre_netlink_parms(data, &p);
t = ipgre_tunnel_locate(net, &p, 0);
if (t) {
if (t->dev != dev)
return -EEXIST;
} else {
t = nt;
if (dev->type != ARPHRD_ETHER) {
unsigned int nflags = 0;
if (ipv4_is_multicast(p.iph.daddr))
nflags = IFF_BROADCAST;
else if (p.iph.daddr)
nflags = IFF_POINTOPOINT;
if ((dev->flags ^ nflags) &
(IFF_POINTOPOINT | IFF_BROADCAST))
return -EINVAL;
}
ipgre_tunnel_unlink(ign, t);
t->parms.iph.saddr = p.iph.saddr;
t->parms.iph.daddr = p.iph.daddr;
t->parms.i_key = p.i_key;
if (dev->type != ARPHRD_ETHER) {
memcpy(dev->dev_addr, &p.iph.saddr, 4);
memcpy(dev->broadcast, &p.iph.daddr, 4);
}
ipgre_tunnel_link(ign, t);
netdev_state_change(dev);
}
t->parms.o_key = p.o_key;
t->parms.iph.ttl = p.iph.ttl;
t->parms.iph.tos = p.iph.tos;
t->parms.iph.frag_off = p.iph.frag_off;
if (t->parms.link != p.link) {
t->parms.link = p.link;
mtu = ipgre_tunnel_bind_dev(dev);
if (!tb[IFLA_MTU])
dev->mtu = mtu;
netdev_state_change(dev);
}
return 0;
}
static size_t ipgre_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(1) +
0;
}
static int ipgre_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
struct ip_tunnel_parm *p = &t->parms;
NLA_PUT_U32(skb, IFLA_GRE_LINK, p->link);
NLA_PUT_BE16(skb, IFLA_GRE_IFLAGS, p->i_flags);
NLA_PUT_BE16(skb, IFLA_GRE_OFLAGS, p->o_flags);
NLA_PUT_BE32(skb, IFLA_GRE_IKEY, p->i_key);
NLA_PUT_BE32(skb, IFLA_GRE_OKEY, p->o_key);
NLA_PUT_BE32(skb, IFLA_GRE_LOCAL, p->iph.saddr);
NLA_PUT_BE32(skb, IFLA_GRE_REMOTE, p->iph.daddr);
NLA_PUT_U8(skb, IFLA_GRE_TTL, p->iph.ttl);
NLA_PUT_U8(skb, IFLA_GRE_TOS, p->iph.tos);
NLA_PUT_U8(skb, IFLA_GRE_PMTUDISC, !!(p->iph.frag_off & htons(IP_DF)));
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int __init ipgre_init(void)
{
int err;
printk(KERN_INFO "GRE over IPv4 tunneling driver\n");
err = register_pernet_device(&ipgre_net_ops);
if (err < 0)
return err;
err = gre_add_protocol(&ipgre_protocol, GREPROTO_CISCO);
if (err < 0) {
printk(KERN_INFO "ipgre init: can't add protocol\n");
goto add_proto_failed;
}
err = rtnl_link_register(&ipgre_link_ops);
if (err < 0)
goto rtnl_link_failed;
err = rtnl_link_register(&ipgre_tap_ops);
if (err < 0)
goto tap_ops_failed;
out:
return err;
tap_ops_failed:
rtnl_link_unregister(&ipgre_link_ops);
rtnl_link_failed:
gre_del_protocol(&ipgre_protocol, GREPROTO_CISCO);
add_proto_failed:
unregister_pernet_device(&ipgre_net_ops);
goto out;
}
static void __exit ipgre_fini(void)
{
rtnl_link_unregister(&ipgre_tap_ops);
rtnl_link_unregister(&ipgre_link_ops);
if (gre_del_protocol(&ipgre_protocol, GREPROTO_CISCO) < 0)
printk(KERN_INFO "ipgre close: can't remove protocol\n");
unregister_pernet_device(&ipgre_net_ops);
}
