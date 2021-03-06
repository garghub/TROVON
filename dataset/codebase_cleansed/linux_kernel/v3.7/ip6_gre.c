static u32 HASH_ADDR(const struct in6_addr *addr)
{
u32 hash = ipv6_addr_hash(addr);
return hash_32(hash, HASH_SIZE_SHIFT);
}
static struct rtnl_link_stats64 *ip6gre_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *tot)
{
int i;
for_each_possible_cpu(i) {
const struct pcpu_tstats *tstats = per_cpu_ptr(dev->tstats, i);
u64 rx_packets, rx_bytes, tx_packets, tx_bytes;
unsigned int start;
do {
start = u64_stats_fetch_begin_bh(&tstats->syncp);
rx_packets = tstats->rx_packets;
tx_packets = tstats->tx_packets;
rx_bytes = tstats->rx_bytes;
tx_bytes = tstats->tx_bytes;
} while (u64_stats_fetch_retry_bh(&tstats->syncp, start));
tot->rx_packets += rx_packets;
tot->tx_packets += tx_packets;
tot->rx_bytes += rx_bytes;
tot->tx_bytes += tx_bytes;
}
tot->multicast = dev->stats.multicast;
tot->rx_crc_errors = dev->stats.rx_crc_errors;
tot->rx_fifo_errors = dev->stats.rx_fifo_errors;
tot->rx_length_errors = dev->stats.rx_length_errors;
tot->rx_frame_errors = dev->stats.rx_frame_errors;
tot->rx_errors = dev->stats.rx_errors;
tot->tx_fifo_errors = dev->stats.tx_fifo_errors;
tot->tx_carrier_errors = dev->stats.tx_carrier_errors;
tot->tx_dropped = dev->stats.tx_dropped;
tot->tx_aborted_errors = dev->stats.tx_aborted_errors;
tot->tx_errors = dev->stats.tx_errors;
return tot;
}
static struct ip6_tnl *ip6gre_tunnel_lookup(struct net_device *dev,
const struct in6_addr *remote, const struct in6_addr *local,
__be32 key, __be16 gre_proto)
{
struct net *net = dev_net(dev);
int link = dev->ifindex;
unsigned int h0 = HASH_ADDR(remote);
unsigned int h1 = HASH_KEY(key);
struct ip6_tnl *t, *cand = NULL;
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
int dev_type = (gre_proto == htons(ETH_P_TEB)) ?
ARPHRD_ETHER : ARPHRD_IP6GRE;
int score, cand_score = 4;
for_each_ip_tunnel_rcu(ign->tunnels_r_l[h0 ^ h1]) {
if (!ipv6_addr_equal(local, &t->parms.laddr) ||
!ipv6_addr_equal(remote, &t->parms.raddr) ||
key != t->parms.i_key ||
!(t->dev->flags & IFF_UP))
continue;
if (t->dev->type != ARPHRD_IP6GRE &&
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
if (!ipv6_addr_equal(remote, &t->parms.raddr) ||
key != t->parms.i_key ||
!(t->dev->flags & IFF_UP))
continue;
if (t->dev->type != ARPHRD_IP6GRE &&
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
if ((!ipv6_addr_equal(local, &t->parms.laddr) &&
(!ipv6_addr_equal(local, &t->parms.raddr) ||
!ipv6_addr_is_multicast(local))) ||
key != t->parms.i_key ||
!(t->dev->flags & IFF_UP))
continue;
if (t->dev->type != ARPHRD_IP6GRE &&
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
if (t->dev->type != ARPHRD_IP6GRE &&
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
static struct ip6_tnl __rcu **__ip6gre_bucket(struct ip6gre_net *ign,
const struct __ip6_tnl_parm *p)
{
const struct in6_addr *remote = &p->raddr;
const struct in6_addr *local = &p->laddr;
unsigned int h = HASH_KEY(p->i_key);
int prio = 0;
if (!ipv6_addr_any(local))
prio |= 1;
if (!ipv6_addr_any(remote) && !ipv6_addr_is_multicast(remote)) {
prio |= 2;
h ^= HASH_ADDR(remote);
}
return &ign->tunnels[prio][h];
}
static inline struct ip6_tnl __rcu **ip6gre_bucket(struct ip6gre_net *ign,
const struct ip6_tnl *t)
{
return __ip6gre_bucket(ign, &t->parms);
}
static void ip6gre_tunnel_link(struct ip6gre_net *ign, struct ip6_tnl *t)
{
struct ip6_tnl __rcu **tp = ip6gre_bucket(ign, t);
rcu_assign_pointer(t->next, rtnl_dereference(*tp));
rcu_assign_pointer(*tp, t);
}
static void ip6gre_tunnel_unlink(struct ip6gre_net *ign, struct ip6_tnl *t)
{
struct ip6_tnl __rcu **tp;
struct ip6_tnl *iter;
for (tp = ip6gre_bucket(ign, t);
(iter = rtnl_dereference(*tp)) != NULL;
tp = &iter->next) {
if (t == iter) {
rcu_assign_pointer(*tp, t->next);
break;
}
}
}
static struct ip6_tnl *ip6gre_tunnel_find(struct net *net,
const struct __ip6_tnl_parm *parms,
int type)
{
const struct in6_addr *remote = &parms->raddr;
const struct in6_addr *local = &parms->laddr;
__be32 key = parms->i_key;
int link = parms->link;
struct ip6_tnl *t;
struct ip6_tnl __rcu **tp;
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
for (tp = __ip6gre_bucket(ign, parms);
(t = rtnl_dereference(*tp)) != NULL;
tp = &t->next)
if (ipv6_addr_equal(local, &t->parms.laddr) &&
ipv6_addr_equal(remote, &t->parms.raddr) &&
key == t->parms.i_key &&
link == t->parms.link &&
type == t->dev->type)
break;
return t;
}
static struct ip6_tnl *ip6gre_tunnel_locate(struct net *net,
const struct __ip6_tnl_parm *parms, int create)
{
struct ip6_tnl *t, *nt;
struct net_device *dev;
char name[IFNAMSIZ];
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
t = ip6gre_tunnel_find(net, parms, ARPHRD_IP6GRE);
if (t || !create)
return t;
if (parms->name[0])
strlcpy(name, parms->name, IFNAMSIZ);
else
strcpy(name, "ip6gre%d");
dev = alloc_netdev(sizeof(*t), name, ip6gre_tunnel_setup);
if (!dev)
return NULL;
dev_net_set(dev, net);
nt = netdev_priv(dev);
nt->parms = *parms;
dev->rtnl_link_ops = &ip6gre_link_ops;
nt->dev = dev;
ip6gre_tnl_link_config(nt, 1);
if (register_netdevice(dev) < 0)
goto failed_free;
if (!(nt->parms.o_flags & GRE_SEQ))
dev->features |= NETIF_F_LLTX;
dev_hold(dev);
ip6gre_tunnel_link(ign, nt);
return nt;
failed_free:
free_netdev(dev);
return NULL;
}
static void ip6gre_tunnel_uninit(struct net_device *dev)
{
struct net *net = dev_net(dev);
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
ip6gre_tunnel_unlink(ign, netdev_priv(dev));
dev_put(dev);
}
static void ip6gre_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
const struct ipv6hdr *ipv6h = (const struct ipv6hdr *)skb->data;
__be16 *p = (__be16 *)(skb->data + offset);
int grehlen = offset + 4;
struct ip6_tnl *t;
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
if (!pskb_may_pull(skb, grehlen))
return;
ipv6h = (const struct ipv6hdr *)skb->data;
p = (__be16 *)(skb->data + offset);
t = ip6gre_tunnel_lookup(skb->dev, &ipv6h->daddr, &ipv6h->saddr,
flags & GRE_KEY ?
*(((__be32 *)p) + (grehlen / 4) - 1) : 0,
p[1]);
if (t == NULL)
return;
switch (type) {
__u32 teli;
struct ipv6_tlv_tnl_enc_lim *tel;
__u32 mtu;
case ICMPV6_DEST_UNREACH:
net_warn_ratelimited("%s: Path to destination invalid or inactive!\n",
t->parms.name);
break;
case ICMPV6_TIME_EXCEED:
if (code == ICMPV6_EXC_HOPLIMIT) {
net_warn_ratelimited("%s: Too small hop limit or routing loop in tunnel!\n",
t->parms.name);
}
break;
case ICMPV6_PARAMPROB:
teli = 0;
if (code == ICMPV6_HDR_FIELD)
teli = ip6_tnl_parse_tlv_enc_lim(skb, skb->data);
if (teli && teli == info - 2) {
tel = (struct ipv6_tlv_tnl_enc_lim *) &skb->data[teli];
if (tel->encap_limit == 0) {
net_warn_ratelimited("%s: Too small encapsulation limit or routing loop in tunnel!\n",
t->parms.name);
}
} else {
net_warn_ratelimited("%s: Recipient unable to parse tunneled packet!\n",
t->parms.name);
}
break;
case ICMPV6_PKT_TOOBIG:
mtu = info - offset;
if (mtu < IPV6_MIN_MTU)
mtu = IPV6_MIN_MTU;
t->dev->mtu = mtu;
break;
}
if (time_before(jiffies, t->err_time + IP6TUNNEL_ERR_TIMEO))
t->err_count++;
else
t->err_count = 1;
t->err_time = jiffies;
}
static int ip6gre_rcv(struct sk_buff *skb)
{
const struct ipv6hdr *ipv6h;
u8 *h;
__be16 flags;
__sum16 csum = 0;
__be32 key = 0;
u32 seqno = 0;
struct ip6_tnl *tunnel;
int offset = 4;
__be16 gre_proto;
int err;
if (!pskb_may_pull(skb, sizeof(struct in6_addr)))
goto drop;
ipv6h = ipv6_hdr(skb);
h = skb->data;
flags = *(__be16 *)h;
if (flags&(GRE_CSUM|GRE_KEY|GRE_ROUTING|GRE_SEQ|GRE_VERSION)) {
if (flags&(GRE_VERSION|GRE_ROUTING))
goto drop;
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
key = *(__be32 *)(h + offset);
offset += 4;
}
if (flags&GRE_SEQ) {
seqno = ntohl(*(__be32 *)(h + offset));
offset += 4;
}
}
gre_proto = *(__be16 *)(h + 2);
tunnel = ip6gre_tunnel_lookup(skb->dev,
&ipv6h->saddr, &ipv6h->daddr, key,
gre_proto);
if (tunnel) {
struct pcpu_tstats *tstats;
if (!xfrm6_policy_check(NULL, XFRM_POLICY_IN, skb))
goto drop;
if (!ip6_tnl_rcv_ctl(tunnel, &ipv6h->daddr, &ipv6h->saddr)) {
tunnel->dev->stats.rx_dropped++;
goto drop;
}
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
if (((flags&GRE_CSUM) && csum) ||
(!(flags&GRE_CSUM) && tunnel->parms.i_flags&GRE_CSUM)) {
tunnel->dev->stats.rx_crc_errors++;
tunnel->dev->stats.rx_errors++;
goto drop;
}
if (tunnel->parms.i_flags&GRE_SEQ) {
if (!(flags&GRE_SEQ) ||
(tunnel->i_seqno &&
(s32)(seqno - tunnel->i_seqno) < 0)) {
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
ipv6h = ipv6_hdr(skb);
skb->protocol = eth_type_trans(skb, tunnel->dev);
skb_postpull_rcsum(skb, eth_hdr(skb), ETH_HLEN);
}
__skb_tunnel_rx(skb, tunnel->dev);
skb_reset_network_header(skb);
err = IP6_ECN_decapsulate(ipv6h, skb);
if (unlikely(err)) {
if (log_ecn_error)
net_info_ratelimited("non-ECT from %pI6 with dsfield=%#x\n",
&ipv6h->saddr,
ipv6_get_dsfield(ipv6h));
if (err > 1) {
++tunnel->dev->stats.rx_frame_errors;
++tunnel->dev->stats.rx_errors;
goto drop;
}
}
tstats = this_cpu_ptr(tunnel->dev->tstats);
u64_stats_update_begin(&tstats->syncp);
tstats->rx_packets++;
tstats->rx_bytes += skb->len;
u64_stats_update_end(&tstats->syncp);
netif_rx(skb);
return 0;
}
icmpv6_send(skb, ICMPV6_DEST_UNREACH, ICMPV6_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
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
static netdev_tx_t ip6gre_xmit2(struct sk_buff *skb,
struct net_device *dev,
__u8 dsfield,
struct flowi6 *fl6,
int encap_limit,
__u32 *pmtu)
{
struct net *net = dev_net(dev);
struct ip6_tnl *tunnel = netdev_priv(dev);
struct net_device *tdev;
struct ipv6hdr *ipv6h;
unsigned int max_headroom;
int gre_hlen;
struct ipv6_tel_txoption opt;
int mtu;
struct dst_entry *dst = NULL, *ndst = NULL;
struct net_device_stats *stats = &tunnel->dev->stats;
int err = -1;
u8 proto;
int pkt_len;
struct sk_buff *new_skb;
if (dev->type == ARPHRD_ETHER)
IPCB(skb)->flags = 0;
if (dev->header_ops && dev->type == ARPHRD_IP6GRE) {
gre_hlen = 0;
ipv6h = (struct ipv6hdr *)skb->data;
fl6->daddr = ipv6h->daddr;
} else {
gre_hlen = tunnel->hlen;
fl6->daddr = tunnel->parms.raddr;
}
if (!fl6->flowi6_mark)
dst = ip6_tnl_dst_check(tunnel);
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
tunnel->parms.name);
goto tx_err_dst_release;
}
mtu = dst_mtu(dst) - sizeof(*ipv6h);
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
if (tunnel->err_count > 0) {
if (time_before(jiffies,
tunnel->err_time + IP6TUNNEL_ERR_TIMEO)) {
tunnel->err_count--;
dst_link_failure(skb);
} else
tunnel->err_count = 0;
}
max_headroom = LL_RESERVED_SPACE(tdev) + gre_hlen + dst->header_len;
if (skb_headroom(skb) < max_headroom || skb_shared(skb) ||
(skb_cloned(skb) && !skb_clone_writable(skb, 0))) {
new_skb = skb_realloc_headroom(skb, max_headroom);
if (max_headroom > dev->needed_headroom)
dev->needed_headroom = max_headroom;
if (!new_skb)
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
proto = NEXTHDR_GRE;
if (encap_limit >= 0) {
init_tel_txopt(&opt, encap_limit);
ipv6_push_nfrag_opts(skb, &opt.ops, &proto, NULL);
}
skb_push(skb, gre_hlen);
skb_reset_network_header(skb);
ipv6h = ipv6_hdr(skb);
*(__be32 *)ipv6h = fl6->flowlabel | htonl(0x60000000);
dsfield = INET_ECN_encapsulate(0, dsfield);
ipv6_change_dsfield(ipv6h, ~INET_ECN_MASK, dsfield);
ipv6h->hop_limit = tunnel->parms.hop_limit;
ipv6h->nexthdr = proto;
ipv6h->saddr = fl6->saddr;
ipv6h->daddr = fl6->daddr;
((__be16 *)(ipv6h + 1))[0] = tunnel->parms.o_flags;
((__be16 *)(ipv6h + 1))[1] = (dev->type == ARPHRD_ETHER) ?
htons(ETH_P_TEB) : skb->protocol;
if (tunnel->parms.o_flags&(GRE_KEY|GRE_CSUM|GRE_SEQ)) {
__be32 *ptr = (__be32 *)(((u8 *)ipv6h) + tunnel->hlen - 4);
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
*(__sum16 *)ptr = ip_compute_csum((void *)(ipv6h+1),
skb->len - sizeof(struct ipv6hdr));
}
}
nf_reset(skb);
pkt_len = skb->len;
err = ip6_local_out(skb);
if (net_xmit_eval(err) == 0) {
struct pcpu_tstats *tstats = this_cpu_ptr(tunnel->dev->tstats);
tstats->tx_bytes += pkt_len;
tstats->tx_packets++;
} else {
stats->tx_errors++;
stats->tx_aborted_errors++;
}
if (ndst)
ip6_tnl_dst_store(tunnel, ndst);
return 0;
tx_err_link_failure:
stats->tx_carrier_errors++;
dst_link_failure(skb);
tx_err_dst_release:
dst_release(ndst);
return err;
}
static inline int ip6gre_xmit_ipv4(struct sk_buff *skb, struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
const struct iphdr *iph = ip_hdr(skb);
int encap_limit = -1;
struct flowi6 fl6;
__u8 dsfield;
__u32 mtu;
int err;
if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
encap_limit = t->parms.encap_limit;
memcpy(&fl6, &t->fl.u.ip6, sizeof(fl6));
fl6.flowi6_proto = IPPROTO_IPIP;
dsfield = ipv4_get_dsfield(iph);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_TCLASS)
fl6.flowlabel |= htonl((__u32)iph->tos << IPV6_TCLASS_SHIFT)
& IPV6_TCLASS_MASK;
if (t->parms.flags & IP6_TNL_F_USE_ORIG_FWMARK)
fl6.flowi6_mark = skb->mark;
err = ip6gre_xmit2(skb, dev, dsfield, &fl6, encap_limit, &mtu);
if (err != 0) {
if (err == -EMSGSIZE)
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED,
htonl(mtu));
return -1;
}
return 0;
}
static inline int ip6gre_xmit_ipv6(struct sk_buff *skb, struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct ipv6hdr *ipv6h = ipv6_hdr(skb);
int encap_limit = -1;
__u16 offset;
struct flowi6 fl6;
__u8 dsfield;
__u32 mtu;
int err;
if (ipv6_addr_equal(&t->parms.raddr, &ipv6h->saddr))
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
memcpy(&fl6, &t->fl.u.ip6, sizeof(fl6));
fl6.flowi6_proto = IPPROTO_IPV6;
dsfield = ipv6_get_dsfield(ipv6h);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_TCLASS)
fl6.flowlabel |= (*(__be32 *) ipv6h & IPV6_TCLASS_MASK);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_FLOWLABEL)
fl6.flowlabel |= (*(__be32 *) ipv6h & IPV6_FLOWLABEL_MASK);
if (t->parms.flags & IP6_TNL_F_USE_ORIG_FWMARK)
fl6.flowi6_mark = skb->mark;
err = ip6gre_xmit2(skb, dev, dsfield, &fl6, encap_limit, &mtu);
if (err != 0) {
if (err == -EMSGSIZE)
icmpv6_send(skb, ICMPV6_PKT_TOOBIG, 0, mtu);
return -1;
}
return 0;
}
static inline bool ip6gre_tnl_addr_conflict(const struct ip6_tnl *t,
const struct ipv6hdr *hdr)
{
return ipv6_addr_equal(&t->parms.raddr, &hdr->saddr);
}
static int ip6gre_xmit_other(struct sk_buff *skb, struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
int encap_limit = -1;
struct flowi6 fl6;
__u32 mtu;
int err;
if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
encap_limit = t->parms.encap_limit;
memcpy(&fl6, &t->fl.u.ip6, sizeof(fl6));
fl6.flowi6_proto = skb->protocol;
err = ip6gre_xmit2(skb, dev, 0, &fl6, encap_limit, &mtu);
return err;
}
static netdev_tx_t ip6gre_tunnel_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct net_device_stats *stats = &t->dev->stats;
int ret;
if (!ip6_tnl_xmit_ctl(t))
return -1;
switch (skb->protocol) {
case htons(ETH_P_IP):
ret = ip6gre_xmit_ipv4(skb, dev);
break;
case htons(ETH_P_IPV6):
ret = ip6gre_xmit_ipv6(skb, dev);
break;
default:
ret = ip6gre_xmit_other(skb, dev);
break;
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
static void ip6gre_tnl_link_config(struct ip6_tnl *t, int set_mtu)
{
struct net_device *dev = t->dev;
struct __ip6_tnl_parm *p = &t->parms;
struct flowi6 *fl6 = &t->fl.u.ip6;
int addend = sizeof(struct ipv6hdr) + 4;
if (dev->type != ARPHRD_ETHER) {
memcpy(dev->dev_addr, &p->laddr, sizeof(struct in6_addr));
memcpy(dev->broadcast, &p->raddr, sizeof(struct in6_addr));
}
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
if (p->flags&IP6_TNL_F_CAP_XMIT &&
p->flags&IP6_TNL_F_CAP_RCV && dev->type != ARPHRD_ETHER)
dev->flags |= IFF_POINTOPOINT;
else
dev->flags &= ~IFF_POINTOPOINT;
dev->iflink = p->link;
if (t->parms.o_flags&(GRE_CSUM|GRE_KEY|GRE_SEQ)) {
if (t->parms.o_flags&GRE_CSUM)
addend += 4;
if (t->parms.o_flags&GRE_KEY)
addend += 4;
if (t->parms.o_flags&GRE_SEQ)
addend += 4;
}
if (p->flags & IP6_TNL_F_CAP_XMIT) {
int strict = (ipv6_addr_type(&p->raddr) &
(IPV6_ADDR_MULTICAST|IPV6_ADDR_LINKLOCAL));
struct rt6_info *rt = rt6_lookup(dev_net(dev),
&p->raddr, &p->laddr,
p->link, strict);
if (rt == NULL)
return;
if (rt->dst.dev) {
dev->hard_header_len = rt->dst.dev->hard_header_len + addend;
if (set_mtu) {
dev->mtu = rt->dst.dev->mtu - addend;
if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
dev->mtu -= 8;
if (dev->mtu < IPV6_MIN_MTU)
dev->mtu = IPV6_MIN_MTU;
}
}
dst_release(&rt->dst);
}
t->hlen = addend;
}
static int ip6gre_tnl_change(struct ip6_tnl *t,
const struct __ip6_tnl_parm *p, int set_mtu)
{
t->parms.laddr = p->laddr;
t->parms.raddr = p->raddr;
t->parms.flags = p->flags;
t->parms.hop_limit = p->hop_limit;
t->parms.encap_limit = p->encap_limit;
t->parms.flowinfo = p->flowinfo;
t->parms.link = p->link;
t->parms.proto = p->proto;
t->parms.i_key = p->i_key;
t->parms.o_key = p->o_key;
t->parms.i_flags = p->i_flags;
t->parms.o_flags = p->o_flags;
ip6_tnl_dst_reset(t);
ip6gre_tnl_link_config(t, set_mtu);
return 0;
}
static void ip6gre_tnl_parm_from_user(struct __ip6_tnl_parm *p,
const struct ip6_tnl_parm2 *u)
{
p->laddr = u->laddr;
p->raddr = u->raddr;
p->flags = u->flags;
p->hop_limit = u->hop_limit;
p->encap_limit = u->encap_limit;
p->flowinfo = u->flowinfo;
p->link = u->link;
p->i_key = u->i_key;
p->o_key = u->o_key;
p->i_flags = u->i_flags;
p->o_flags = u->o_flags;
memcpy(p->name, u->name, sizeof(u->name));
}
static void ip6gre_tnl_parm_to_user(struct ip6_tnl_parm2 *u,
const struct __ip6_tnl_parm *p)
{
u->proto = IPPROTO_GRE;
u->laddr = p->laddr;
u->raddr = p->raddr;
u->flags = p->flags;
u->hop_limit = p->hop_limit;
u->encap_limit = p->encap_limit;
u->flowinfo = p->flowinfo;
u->link = p->link;
u->i_key = p->i_key;
u->o_key = p->o_key;
u->i_flags = p->i_flags;
u->o_flags = p->o_flags;
memcpy(u->name, p->name, sizeof(u->name));
}
static int ip6gre_tunnel_ioctl(struct net_device *dev,
struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip6_tnl_parm2 p;
struct __ip6_tnl_parm p1;
struct ip6_tnl *t;
struct net *net = dev_net(dev);
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
switch (cmd) {
case SIOCGETTUNNEL:
t = NULL;
if (dev == ign->fb_tunnel_dev) {
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p))) {
err = -EFAULT;
break;
}
ip6gre_tnl_parm_from_user(&p1, &p);
t = ip6gre_tunnel_locate(net, &p1, 0);
}
if (t == NULL)
t = netdev_priv(dev);
ip6gre_tnl_parm_to_user(&p, &t->parms);
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
if ((p.i_flags|p.o_flags)&(GRE_VERSION|GRE_ROUTING))
goto done;
if (!(p.i_flags&GRE_KEY))
p.i_key = 0;
if (!(p.o_flags&GRE_KEY))
p.o_key = 0;
ip6gre_tnl_parm_from_user(&p1, &p);
t = ip6gre_tunnel_locate(net, &p1, cmd == SIOCADDTUNNEL);
if (dev != ign->fb_tunnel_dev && cmd == SIOCCHGTUNNEL) {
if (t != NULL) {
if (t->dev != dev) {
err = -EEXIST;
break;
}
} else {
t = netdev_priv(dev);
ip6gre_tunnel_unlink(ign, t);
synchronize_net();
ip6gre_tnl_change(t, &p1, 1);
ip6gre_tunnel_link(ign, t);
netdev_state_change(dev);
}
}
if (t) {
err = 0;
ip6gre_tnl_parm_to_user(&p, &t->parms);
if (copy_to_user(ifr->ifr_ifru.ifru_data, &p, sizeof(p)))
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
ip6gre_tnl_parm_from_user(&p1, &p);
t = ip6gre_tunnel_locate(net, &p1, 0);
if (t == NULL)
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
static int ip6gre_tunnel_change_mtu(struct net_device *dev, int new_mtu)
{
struct ip6_tnl *tunnel = netdev_priv(dev);
if (new_mtu < 68 ||
new_mtu > 0xFFF8 - dev->hard_header_len - tunnel->hlen)
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static int ip6gre_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr, unsigned int len)
{
struct ip6_tnl *t = netdev_priv(dev);
struct ipv6hdr *ipv6h = (struct ipv6hdr *)skb_push(skb, t->hlen);
__be16 *p = (__be16 *)(ipv6h+1);
*(__be32 *)ipv6h = t->fl.u.ip6.flowlabel | htonl(0x60000000);
ipv6h->hop_limit = t->parms.hop_limit;
ipv6h->nexthdr = NEXTHDR_GRE;
ipv6h->saddr = t->parms.laddr;
ipv6h->daddr = t->parms.raddr;
p[0] = t->parms.o_flags;
p[1] = htons(type);
if (saddr)
memcpy(&ipv6h->saddr, saddr, sizeof(struct in6_addr));
if (daddr)
memcpy(&ipv6h->daddr, daddr, sizeof(struct in6_addr));
if (!ipv6_addr_any(&ipv6h->daddr))
return t->hlen;
return -t->hlen;
}
static void ip6gre_dev_free(struct net_device *dev)
{
free_percpu(dev->tstats);
free_netdev(dev);
}
static void ip6gre_tunnel_setup(struct net_device *dev)
{
struct ip6_tnl *t;
dev->netdev_ops = &ip6gre_netdev_ops;
dev->destructor = ip6gre_dev_free;
dev->type = ARPHRD_IP6GRE;
dev->hard_header_len = LL_MAX_HEADER + sizeof(struct ipv6hdr) + 4;
dev->mtu = ETH_DATA_LEN - sizeof(struct ipv6hdr) - 4;
t = netdev_priv(dev);
if (!(t->parms.flags & IP6_TNL_F_IGN_ENCAP_LIMIT))
dev->mtu -= 8;
dev->flags |= IFF_NOARP;
dev->iflink = 0;
dev->addr_len = sizeof(struct in6_addr);
dev->features |= NETIF_F_NETNS_LOCAL;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
}
static int ip6gre_tunnel_init(struct net_device *dev)
{
struct ip6_tnl *tunnel;
tunnel = netdev_priv(dev);
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
memcpy(dev->dev_addr, &tunnel->parms.laddr, sizeof(struct in6_addr));
memcpy(dev->broadcast, &tunnel->parms.raddr, sizeof(struct in6_addr));
if (ipv6_addr_any(&tunnel->parms.raddr))
dev->header_ops = &ip6gre_header_ops;
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static void ip6gre_fb_tunnel_init(struct net_device *dev)
{
struct ip6_tnl *tunnel = netdev_priv(dev);
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
tunnel->hlen = sizeof(struct ipv6hdr) + 4;
dev_hold(dev);
}
static void ip6gre_destroy_tunnels(struct ip6gre_net *ign,
struct list_head *head)
{
int prio;
for (prio = 0; prio < 4; prio++) {
int h;
for (h = 0; h < HASH_SIZE; h++) {
struct ip6_tnl *t;
t = rtnl_dereference(ign->tunnels[prio][h]);
while (t != NULL) {
unregister_netdevice_queue(t->dev, head);
t = rtnl_dereference(t->next);
}
}
}
}
static int __net_init ip6gre_init_net(struct net *net)
{
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
int err;
ign->fb_tunnel_dev = alloc_netdev(sizeof(struct ip6_tnl), "ip6gre0",
ip6gre_tunnel_setup);
if (!ign->fb_tunnel_dev) {
err = -ENOMEM;
goto err_alloc_dev;
}
dev_net_set(ign->fb_tunnel_dev, net);
ip6gre_fb_tunnel_init(ign->fb_tunnel_dev);
ign->fb_tunnel_dev->rtnl_link_ops = &ip6gre_link_ops;
err = register_netdev(ign->fb_tunnel_dev);
if (err)
goto err_reg_dev;
rcu_assign_pointer(ign->tunnels_wc[0],
netdev_priv(ign->fb_tunnel_dev));
return 0;
err_reg_dev:
ip6gre_dev_free(ign->fb_tunnel_dev);
err_alloc_dev:
return err;
}
static void __net_exit ip6gre_exit_net(struct net *net)
{
struct ip6gre_net *ign;
LIST_HEAD(list);
ign = net_generic(net, ip6gre_net_id);
rtnl_lock();
ip6gre_destroy_tunnels(ign, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
}
static int ip6gre_tunnel_validate(struct nlattr *tb[], struct nlattr *data[])
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
static int ip6gre_tap_validate(struct nlattr *tb[], struct nlattr *data[])
{
struct in6_addr daddr;
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
if (!data)
goto out;
if (data[IFLA_GRE_REMOTE]) {
nla_memcpy(&daddr, data[IFLA_GRE_REMOTE], sizeof(struct in6_addr));
if (ipv6_addr_any(&daddr))
return -EINVAL;
}
out:
return ip6gre_tunnel_validate(tb, data);
}
static void ip6gre_netlink_parms(struct nlattr *data[],
struct __ip6_tnl_parm *parms)
{
memset(parms, 0, sizeof(*parms));
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
nla_memcpy(&parms->laddr, data[IFLA_GRE_LOCAL], sizeof(struct in6_addr));
if (data[IFLA_GRE_REMOTE])
nla_memcpy(&parms->raddr, data[IFLA_GRE_REMOTE], sizeof(struct in6_addr));
if (data[IFLA_GRE_TTL])
parms->hop_limit = nla_get_u8(data[IFLA_GRE_TTL]);
if (data[IFLA_GRE_ENCAP_LIMIT])
parms->encap_limit = nla_get_u8(data[IFLA_GRE_ENCAP_LIMIT]);
if (data[IFLA_GRE_FLOWINFO])
parms->flowinfo = nla_get_u32(data[IFLA_GRE_FLOWINFO]);
if (data[IFLA_GRE_FLAGS])
parms->flags = nla_get_u32(data[IFLA_GRE_FLAGS]);
}
static int ip6gre_tap_init(struct net_device *dev)
{
struct ip6_tnl *tunnel;
tunnel = netdev_priv(dev);
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
ip6gre_tnl_link_config(tunnel, 1);
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static void ip6gre_tap_setup(struct net_device *dev)
{
ether_setup(dev);
dev->netdev_ops = &ip6gre_tap_netdev_ops;
dev->destructor = ip6gre_dev_free;
dev->iflink = 0;
dev->features |= NETIF_F_NETNS_LOCAL;
}
static int ip6gre_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct ip6_tnl *nt;
struct net *net = dev_net(dev);
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
int err;
nt = netdev_priv(dev);
ip6gre_netlink_parms(data, &nt->parms);
if (ip6gre_tunnel_find(net, &nt->parms, dev->type))
return -EEXIST;
if (dev->type == ARPHRD_ETHER && !tb[IFLA_ADDRESS])
eth_hw_addr_random(dev);
nt->dev = dev;
ip6gre_tnl_link_config(nt, !tb[IFLA_MTU]);
if (!(nt->parms.o_flags & GRE_SEQ))
dev->features |= NETIF_F_LLTX;
err = register_netdevice(dev);
if (err)
goto out;
dev_hold(dev);
ip6gre_tunnel_link(ign, nt);
out:
return err;
}
static int ip6gre_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip6_tnl *t, *nt;
struct net *net = dev_net(dev);
struct ip6gre_net *ign = net_generic(net, ip6gre_net_id);
struct __ip6_tnl_parm p;
if (dev == ign->fb_tunnel_dev)
return -EINVAL;
nt = netdev_priv(dev);
ip6gre_netlink_parms(data, &p);
t = ip6gre_tunnel_locate(net, &p, 0);
if (t) {
if (t->dev != dev)
return -EEXIST;
} else {
t = nt;
ip6gre_tunnel_unlink(ign, t);
ip6gre_tnl_change(t, &p, !tb[IFLA_MTU]);
ip6gre_tunnel_link(ign, t);
netdev_state_change(dev);
}
return 0;
}
static size_t ip6gre_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(sizeof(struct in6_addr)) +
nla_total_size(sizeof(struct in6_addr)) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(4) +
nla_total_size(4) +
0;
}
static int ip6gre_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip6_tnl *t = netdev_priv(dev);
struct __ip6_tnl_parm *p = &t->parms;
if (nla_put_u32(skb, IFLA_GRE_LINK, p->link) ||
nla_put_be16(skb, IFLA_GRE_IFLAGS, p->i_flags) ||
nla_put_be16(skb, IFLA_GRE_OFLAGS, p->o_flags) ||
nla_put_be32(skb, IFLA_GRE_IKEY, p->i_key) ||
nla_put_be32(skb, IFLA_GRE_OKEY, p->o_key) ||
nla_put(skb, IFLA_GRE_LOCAL, sizeof(struct in6_addr), &p->laddr) ||
nla_put(skb, IFLA_GRE_REMOTE, sizeof(struct in6_addr), &p->raddr) ||
nla_put_u8(skb, IFLA_GRE_TTL, p->hop_limit) ||
nla_put_u8(skb, IFLA_GRE_ENCAP_LIMIT, p->encap_limit) ||
nla_put_be32(skb, IFLA_GRE_FLOWINFO, p->flowinfo) ||
nla_put_u32(skb, IFLA_GRE_FLAGS, p->flags))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int __init ip6gre_init(void)
{
int err;
pr_info("GRE over IPv6 tunneling driver\n");
err = register_pernet_device(&ip6gre_net_ops);
if (err < 0)
return err;
err = inet6_add_protocol(&ip6gre_protocol, IPPROTO_GRE);
if (err < 0) {
pr_info("%s: can't add protocol\n", __func__);
goto add_proto_failed;
}
err = rtnl_link_register(&ip6gre_link_ops);
if (err < 0)
goto rtnl_link_failed;
err = rtnl_link_register(&ip6gre_tap_ops);
if (err < 0)
goto tap_ops_failed;
out:
return err;
tap_ops_failed:
rtnl_link_unregister(&ip6gre_link_ops);
rtnl_link_failed:
inet6_del_protocol(&ip6gre_protocol, IPPROTO_GRE);
add_proto_failed:
unregister_pernet_device(&ip6gre_net_ops);
goto out;
}
static void __exit ip6gre_fini(void)
{
rtnl_link_unregister(&ip6gre_tap_ops);
rtnl_link_unregister(&ip6gre_link_ops);
inet6_del_protocol(&ip6gre_protocol, IPPROTO_GRE);
unregister_pernet_device(&ip6gre_net_ops);
}
