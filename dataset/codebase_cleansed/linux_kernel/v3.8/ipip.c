static struct rtnl_link_stats64 *ipip_get_stats64(struct net_device *dev,
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
tot->tx_fifo_errors = dev->stats.tx_fifo_errors;
tot->tx_carrier_errors = dev->stats.tx_carrier_errors;
tot->tx_dropped = dev->stats.tx_dropped;
tot->tx_aborted_errors = dev->stats.tx_aborted_errors;
tot->tx_errors = dev->stats.tx_errors;
tot->collisions = dev->stats.collisions;
return tot;
}
static struct ip_tunnel *ipip_tunnel_lookup(struct net *net,
__be32 remote, __be32 local)
{
unsigned int h0 = HASH(remote);
unsigned int h1 = HASH(local);
struct ip_tunnel *t;
struct ipip_net *ipn = net_generic(net, ipip_net_id);
for_each_ip_tunnel_rcu(t, ipn->tunnels_r_l[h0 ^ h1])
if (local == t->parms.iph.saddr &&
remote == t->parms.iph.daddr && (t->dev->flags&IFF_UP))
return t;
for_each_ip_tunnel_rcu(t, ipn->tunnels_r[h0])
if (remote == t->parms.iph.daddr && (t->dev->flags&IFF_UP))
return t;
for_each_ip_tunnel_rcu(t, ipn->tunnels_l[h1])
if (local == t->parms.iph.saddr && (t->dev->flags&IFF_UP))
return t;
t = rcu_dereference(ipn->tunnels_wc[0]);
if (t && (t->dev->flags&IFF_UP))
return t;
return NULL;
}
static struct ip_tunnel __rcu **__ipip_bucket(struct ipip_net *ipn,
struct ip_tunnel_parm *parms)
{
__be32 remote = parms->iph.daddr;
__be32 local = parms->iph.saddr;
unsigned int h = 0;
int prio = 0;
if (remote) {
prio |= 2;
h ^= HASH(remote);
}
if (local) {
prio |= 1;
h ^= HASH(local);
}
return &ipn->tunnels[prio][h];
}
static inline struct ip_tunnel __rcu **ipip_bucket(struct ipip_net *ipn,
struct ip_tunnel *t)
{
return __ipip_bucket(ipn, &t->parms);
}
static void ipip_tunnel_unlink(struct ipip_net *ipn, struct ip_tunnel *t)
{
struct ip_tunnel __rcu **tp;
struct ip_tunnel *iter;
for (tp = ipip_bucket(ipn, t);
(iter = rtnl_dereference(*tp)) != NULL;
tp = &iter->next) {
if (t == iter) {
rcu_assign_pointer(*tp, t->next);
break;
}
}
}
static void ipip_tunnel_link(struct ipip_net *ipn, struct ip_tunnel *t)
{
struct ip_tunnel __rcu **tp = ipip_bucket(ipn, t);
rcu_assign_pointer(t->next, rtnl_dereference(*tp));
rcu_assign_pointer(*tp, t);
}
static int ipip_tunnel_create(struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
struct net *net = dev_net(dev);
struct ipip_net *ipn = net_generic(net, ipip_net_id);
int err;
err = ipip_tunnel_init(dev);
if (err < 0)
goto out;
err = register_netdevice(dev);
if (err < 0)
goto out;
strcpy(t->parms.name, dev->name);
dev->rtnl_link_ops = &ipip_link_ops;
dev_hold(dev);
ipip_tunnel_link(ipn, t);
return 0;
out:
return err;
}
static struct ip_tunnel *ipip_tunnel_locate(struct net *net,
struct ip_tunnel_parm *parms, int create)
{
__be32 remote = parms->iph.daddr;
__be32 local = parms->iph.saddr;
struct ip_tunnel *t, *nt;
struct ip_tunnel __rcu **tp;
struct net_device *dev;
char name[IFNAMSIZ];
struct ipip_net *ipn = net_generic(net, ipip_net_id);
for (tp = __ipip_bucket(ipn, parms);
(t = rtnl_dereference(*tp)) != NULL;
tp = &t->next) {
if (local == t->parms.iph.saddr && remote == t->parms.iph.daddr)
return t;
}
if (!create)
return NULL;
if (parms->name[0])
strlcpy(name, parms->name, IFNAMSIZ);
else
strcpy(name, "tunl%d");
dev = alloc_netdev(sizeof(*t), name, ipip_tunnel_setup);
if (dev == NULL)
return NULL;
dev_net_set(dev, net);
nt = netdev_priv(dev);
nt->parms = *parms;
if (ipip_tunnel_create(dev) < 0)
goto failed_free;
return nt;
failed_free:
ipip_dev_free(dev);
return NULL;
}
static void ipip_tunnel_uninit(struct net_device *dev)
{
struct net *net = dev_net(dev);
struct ipip_net *ipn = net_generic(net, ipip_net_id);
if (dev == ipn->fb_tunnel_dev)
RCU_INIT_POINTER(ipn->tunnels_wc[0], NULL);
else
ipip_tunnel_unlink(ipn, netdev_priv(dev));
dev_put(dev);
}
static int ipip_err(struct sk_buff *skb, u32 info)
{
const struct iphdr *iph = (const struct iphdr *)skb->data;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct ip_tunnel *t;
int err;
switch (type) {
default:
case ICMP_PARAMETERPROB:
return 0;
case ICMP_DEST_UNREACH:
switch (code) {
case ICMP_SR_FAILED:
case ICMP_PORT_UNREACH:
return 0;
default:
break;
}
break;
case ICMP_TIME_EXCEEDED:
if (code != ICMP_EXC_TTL)
return 0;
break;
case ICMP_REDIRECT:
break;
}
err = -ENOENT;
t = ipip_tunnel_lookup(dev_net(skb->dev), iph->daddr, iph->saddr);
if (t == NULL)
goto out;
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED) {
ipv4_update_pmtu(skb, dev_net(skb->dev), info,
t->dev->ifindex, 0, IPPROTO_IPIP, 0);
err = 0;
goto out;
}
if (type == ICMP_REDIRECT) {
ipv4_redirect(skb, dev_net(skb->dev), t->dev->ifindex, 0,
IPPROTO_IPIP, 0);
err = 0;
goto out;
}
if (t->parms.iph.daddr == 0)
goto out;
err = 0;
if (t->parms.iph.ttl == 0 && type == ICMP_TIME_EXCEEDED)
goto out;
if (time_before(jiffies, t->err_time + IPTUNNEL_ERR_TIMEO))
t->err_count++;
else
t->err_count = 1;
t->err_time = jiffies;
out:
return err;
}
static int ipip_rcv(struct sk_buff *skb)
{
struct ip_tunnel *tunnel;
const struct iphdr *iph = ip_hdr(skb);
int err;
tunnel = ipip_tunnel_lookup(dev_net(skb->dev), iph->saddr, iph->daddr);
if (tunnel != NULL) {
struct pcpu_tstats *tstats;
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
goto drop;
secpath_reset(skb);
skb->mac_header = skb->network_header;
skb_reset_network_header(skb);
skb->protocol = htons(ETH_P_IP);
skb->pkt_type = PACKET_HOST;
__skb_tunnel_rx(skb, tunnel->dev);
err = IP_ECN_decapsulate(iph, skb);
if (unlikely(err)) {
if (log_ecn_error)
net_info_ratelimited("non-ECT from %pI4 with TOS=%#x\n",
&iph->saddr, iph->tos);
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
return -1;
drop:
kfree_skb(skb);
return 0;
}
static netdev_tx_t ipip_tunnel_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
const struct iphdr *tiph = &tunnel->parms.iph;
u8 tos = tunnel->parms.iph.tos;
__be16 df = tiph->frag_off;
struct rtable *rt;
struct net_device *tdev;
const struct iphdr *old_iph = ip_hdr(skb);
struct iphdr *iph;
unsigned int max_headroom;
__be32 dst = tiph->daddr;
struct flowi4 fl4;
int mtu;
if (skb->protocol != htons(ETH_P_IP))
goto tx_error;
if (skb->ip_summed == CHECKSUM_PARTIAL &&
skb_checksum_help(skb))
goto tx_error;
if (tos & 1)
tos = old_iph->tos;
if (!dst) {
if ((rt = skb_rtable(skb)) == NULL) {
dev->stats.tx_fifo_errors++;
goto tx_error;
}
dst = rt_nexthop(rt, old_iph->daddr);
}
rt = ip_route_output_ports(dev_net(dev), &fl4, NULL,
dst, tiph->saddr,
0, 0,
IPPROTO_IPIP, RT_TOS(tos),
tunnel->parms.link);
if (IS_ERR(rt)) {
dev->stats.tx_carrier_errors++;
goto tx_error_icmp;
}
tdev = rt->dst.dev;
if (tdev == dev) {
ip_rt_put(rt);
dev->stats.collisions++;
goto tx_error;
}
df |= old_iph->frag_off & htons(IP_DF);
if (df) {
mtu = dst_mtu(&rt->dst) - sizeof(struct iphdr);
if (mtu < 68) {
dev->stats.collisions++;
ip_rt_put(rt);
goto tx_error;
}
if (skb_dst(skb))
skb_dst(skb)->ops->update_pmtu(skb_dst(skb), NULL, skb, mtu);
if ((old_iph->frag_off & htons(IP_DF)) &&
mtu < ntohs(old_iph->tot_len)) {
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_FRAG_NEEDED,
htonl(mtu));
ip_rt_put(rt);
goto tx_error;
}
}
if (tunnel->err_count > 0) {
if (time_before(jiffies,
tunnel->err_time + IPTUNNEL_ERR_TIMEO)) {
tunnel->err_count--;
dst_link_failure(skb);
} else
tunnel->err_count = 0;
}
max_headroom = (LL_RESERVED_SPACE(tdev)+sizeof(struct iphdr));
if (skb_headroom(skb) < max_headroom || skb_shared(skb) ||
(skb_cloned(skb) && !skb_clone_writable(skb, 0))) {
struct sk_buff *new_skb = skb_realloc_headroom(skb, max_headroom);
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
skb->transport_header = skb->network_header;
skb_push(skb, sizeof(struct iphdr));
skb_reset_network_header(skb);
memset(&(IPCB(skb)->opt), 0, sizeof(IPCB(skb)->opt));
IPCB(skb)->flags &= ~(IPSKB_XFRM_TUNNEL_SIZE | IPSKB_XFRM_TRANSFORMED |
IPSKB_REROUTED);
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
iph = ip_hdr(skb);
iph->version = 4;
iph->ihl = sizeof(struct iphdr)>>2;
iph->frag_off = df;
iph->protocol = IPPROTO_IPIP;
iph->tos = INET_ECN_encapsulate(tos, old_iph->tos);
iph->daddr = fl4.daddr;
iph->saddr = fl4.saddr;
if ((iph->ttl = tiph->ttl) == 0)
iph->ttl = old_iph->ttl;
iptunnel_xmit(skb, dev);
return NETDEV_TX_OK;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
dev->stats.tx_errors++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void ipip_tunnel_bind_dev(struct net_device *dev)
{
struct net_device *tdev = NULL;
struct ip_tunnel *tunnel;
const struct iphdr *iph;
tunnel = netdev_priv(dev);
iph = &tunnel->parms.iph;
if (iph->daddr) {
struct rtable *rt;
struct flowi4 fl4;
rt = ip_route_output_ports(dev_net(dev), &fl4, NULL,
iph->daddr, iph->saddr,
0, 0,
IPPROTO_IPIP,
RT_TOS(iph->tos),
tunnel->parms.link);
if (!IS_ERR(rt)) {
tdev = rt->dst.dev;
ip_rt_put(rt);
}
dev->flags |= IFF_POINTOPOINT;
}
if (!tdev && tunnel->parms.link)
tdev = __dev_get_by_index(dev_net(dev), tunnel->parms.link);
if (tdev) {
dev->hard_header_len = tdev->hard_header_len + sizeof(struct iphdr);
dev->mtu = tdev->mtu - sizeof(struct iphdr);
}
dev->iflink = tunnel->parms.link;
}
static void ipip_tunnel_update(struct ip_tunnel *t, struct ip_tunnel_parm *p)
{
struct net *net = dev_net(t->dev);
struct ipip_net *ipn = net_generic(net, ipip_net_id);
ipip_tunnel_unlink(ipn, t);
synchronize_net();
t->parms.iph.saddr = p->iph.saddr;
t->parms.iph.daddr = p->iph.daddr;
memcpy(t->dev->dev_addr, &p->iph.saddr, 4);
memcpy(t->dev->broadcast, &p->iph.daddr, 4);
ipip_tunnel_link(ipn, t);
t->parms.iph.ttl = p->iph.ttl;
t->parms.iph.tos = p->iph.tos;
t->parms.iph.frag_off = p->iph.frag_off;
if (t->parms.link != p->link) {
t->parms.link = p->link;
ipip_tunnel_bind_dev(t->dev);
}
netdev_state_change(t->dev);
}
static int
ipip_tunnel_ioctl (struct net_device *dev, struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip_tunnel_parm p;
struct ip_tunnel *t;
struct net *net = dev_net(dev);
struct ipip_net *ipn = net_generic(net, ipip_net_id);
switch (cmd) {
case SIOCGETTUNNEL:
t = NULL;
if (dev == ipn->fb_tunnel_dev) {
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p))) {
err = -EFAULT;
break;
}
t = ipip_tunnel_locate(net, &p, 0);
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
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
goto done;
err = -EFAULT;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
goto done;
err = -EINVAL;
if (p.iph.version != 4 || p.iph.protocol != IPPROTO_IPIP ||
p.iph.ihl != 5 || (p.iph.frag_off&htons(~IP_DF)))
goto done;
if (p.iph.ttl)
p.iph.frag_off |= htons(IP_DF);
t = ipip_tunnel_locate(net, &p, cmd == SIOCADDTUNNEL);
if (dev != ipn->fb_tunnel_dev && cmd == SIOCCHGTUNNEL) {
if (t != NULL) {
if (t->dev != dev) {
err = -EEXIST;
break;
}
} else {
if (((dev->flags&IFF_POINTOPOINT) && !p.iph.daddr) ||
(!(dev->flags&IFF_POINTOPOINT) && p.iph.daddr)) {
err = -EINVAL;
break;
}
t = netdev_priv(dev);
}
ipip_tunnel_update(t, &p);
}
if (t) {
err = 0;
if (copy_to_user(ifr->ifr_ifru.ifru_data, &t->parms, sizeof(p)))
err = -EFAULT;
} else
err = (cmd == SIOCADDTUNNEL ? -ENOBUFS : -ENOENT);
break;
case SIOCDELTUNNEL:
err = -EPERM;
if (!ns_capable(net->user_ns, CAP_NET_ADMIN))
goto done;
if (dev == ipn->fb_tunnel_dev) {
err = -EFAULT;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
goto done;
err = -ENOENT;
if ((t = ipip_tunnel_locate(net, &p, 0)) == NULL)
goto done;
err = -EPERM;
if (t->dev == ipn->fb_tunnel_dev)
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
static int ipip_tunnel_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < 68 || new_mtu > 0xFFF8 - sizeof(struct iphdr))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static void ipip_dev_free(struct net_device *dev)
{
free_percpu(dev->tstats);
free_netdev(dev);
}
static void ipip_tunnel_setup(struct net_device *dev)
{
dev->netdev_ops = &ipip_netdev_ops;
dev->destructor = ipip_dev_free;
dev->type = ARPHRD_TUNNEL;
dev->hard_header_len = LL_MAX_HEADER + sizeof(struct iphdr);
dev->mtu = ETH_DATA_LEN - sizeof(struct iphdr);
dev->flags = IFF_NOARP;
dev->iflink = 0;
dev->addr_len = 4;
dev->features |= NETIF_F_NETNS_LOCAL;
dev->features |= NETIF_F_LLTX;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
dev->features |= IPIP_FEATURES;
dev->hw_features |= IPIP_FEATURES;
}
static int ipip_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
tunnel->dev = dev;
memcpy(dev->dev_addr, &tunnel->parms.iph.saddr, 4);
memcpy(dev->broadcast, &tunnel->parms.iph.daddr, 4);
ipip_tunnel_bind_dev(dev);
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static int __net_init ipip_fb_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct iphdr *iph = &tunnel->parms.iph;
struct ipip_net *ipn = net_generic(dev_net(dev), ipip_net_id);
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
iph->version = 4;
iph->protocol = IPPROTO_IPIP;
iph->ihl = 5;
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
dev_hold(dev);
rcu_assign_pointer(ipn->tunnels_wc[0], tunnel);
return 0;
}
static void ipip_netlink_parms(struct nlattr *data[],
struct ip_tunnel_parm *parms)
{
memset(parms, 0, sizeof(*parms));
parms->iph.version = 4;
parms->iph.protocol = IPPROTO_IPIP;
parms->iph.ihl = 5;
if (!data)
return;
if (data[IFLA_IPTUN_LINK])
parms->link = nla_get_u32(data[IFLA_IPTUN_LINK]);
if (data[IFLA_IPTUN_LOCAL])
parms->iph.saddr = nla_get_be32(data[IFLA_IPTUN_LOCAL]);
if (data[IFLA_IPTUN_REMOTE])
parms->iph.daddr = nla_get_be32(data[IFLA_IPTUN_REMOTE]);
if (data[IFLA_IPTUN_TTL]) {
parms->iph.ttl = nla_get_u8(data[IFLA_IPTUN_TTL]);
if (parms->iph.ttl)
parms->iph.frag_off = htons(IP_DF);
}
if (data[IFLA_IPTUN_TOS])
parms->iph.tos = nla_get_u8(data[IFLA_IPTUN_TOS]);
if (!data[IFLA_IPTUN_PMTUDISC] || nla_get_u8(data[IFLA_IPTUN_PMTUDISC]))
parms->iph.frag_off = htons(IP_DF);
}
static int ipip_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct net *net = dev_net(dev);
struct ip_tunnel *nt;
nt = netdev_priv(dev);
ipip_netlink_parms(data, &nt->parms);
if (ipip_tunnel_locate(net, &nt->parms, 0))
return -EEXIST;
return ipip_tunnel_create(dev);
}
static int ipip_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel *t;
struct ip_tunnel_parm p;
struct net *net = dev_net(dev);
struct ipip_net *ipn = net_generic(net, ipip_net_id);
if (dev == ipn->fb_tunnel_dev)
return -EINVAL;
ipip_netlink_parms(data, &p);
if (((dev->flags & IFF_POINTOPOINT) && !p.iph.daddr) ||
(!(dev->flags & IFF_POINTOPOINT) && p.iph.daddr))
return -EINVAL;
t = ipip_tunnel_locate(net, &p, 0);
if (t) {
if (t->dev != dev)
return -EEXIST;
} else
t = netdev_priv(dev);
ipip_tunnel_update(t, &p);
return 0;
}
static size_t ipip_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(1) +
0;
}
static int ipip_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct ip_tunnel_parm *parm = &tunnel->parms;
if (nla_put_u32(skb, IFLA_IPTUN_LINK, parm->link) ||
nla_put_be32(skb, IFLA_IPTUN_LOCAL, parm->iph.saddr) ||
nla_put_be32(skb, IFLA_IPTUN_REMOTE, parm->iph.daddr) ||
nla_put_u8(skb, IFLA_IPTUN_TTL, parm->iph.ttl) ||
nla_put_u8(skb, IFLA_IPTUN_TOS, parm->iph.tos) ||
nla_put_u8(skb, IFLA_IPTUN_PMTUDISC,
!!(parm->iph.frag_off & htons(IP_DF))))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static void ipip_destroy_tunnels(struct ipip_net *ipn, struct list_head *head)
{
int prio;
for (prio = 1; prio < 4; prio++) {
int h;
for (h = 0; h < HASH_SIZE; h++) {
struct ip_tunnel *t;
t = rtnl_dereference(ipn->tunnels[prio][h]);
while (t != NULL) {
unregister_netdevice_queue(t->dev, head);
t = rtnl_dereference(t->next);
}
}
}
}
static int __net_init ipip_init_net(struct net *net)
{
struct ipip_net *ipn = net_generic(net, ipip_net_id);
struct ip_tunnel *t;
int err;
ipn->tunnels[0] = ipn->tunnels_wc;
ipn->tunnels[1] = ipn->tunnels_l;
ipn->tunnels[2] = ipn->tunnels_r;
ipn->tunnels[3] = ipn->tunnels_r_l;
ipn->fb_tunnel_dev = alloc_netdev(sizeof(struct ip_tunnel),
"tunl0",
ipip_tunnel_setup);
if (!ipn->fb_tunnel_dev) {
err = -ENOMEM;
goto err_alloc_dev;
}
dev_net_set(ipn->fb_tunnel_dev, net);
err = ipip_fb_tunnel_init(ipn->fb_tunnel_dev);
if (err)
goto err_reg_dev;
if ((err = register_netdev(ipn->fb_tunnel_dev)))
goto err_reg_dev;
t = netdev_priv(ipn->fb_tunnel_dev);
strcpy(t->parms.name, ipn->fb_tunnel_dev->name);
return 0;
err_reg_dev:
ipip_dev_free(ipn->fb_tunnel_dev);
err_alloc_dev:
return err;
}
static void __net_exit ipip_exit_net(struct net *net)
{
struct ipip_net *ipn = net_generic(net, ipip_net_id);
LIST_HEAD(list);
rtnl_lock();
ipip_destroy_tunnels(ipn, &list);
unregister_netdevice_queue(ipn->fb_tunnel_dev, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
}
static int __init ipip_init(void)
{
int err;
printk(banner);
err = register_pernet_device(&ipip_net_ops);
if (err < 0)
return err;
err = xfrm4_tunnel_register(&ipip_handler, AF_INET);
if (err < 0) {
pr_info("%s: can't register tunnel\n", __func__);
goto xfrm_tunnel_failed;
}
err = rtnl_link_register(&ipip_link_ops);
if (err < 0)
goto rtnl_link_failed;
out:
return err;
rtnl_link_failed:
xfrm4_tunnel_deregister(&ipip_handler, AF_INET);
xfrm_tunnel_failed:
unregister_pernet_device(&ipip_net_ops);
goto out;
}
static void __exit ipip_fini(void)
{
rtnl_link_unregister(&ipip_link_ops);
if (xfrm4_tunnel_deregister(&ipip_handler, AF_INET))
pr_info("%s: can't deregister tunnel\n", __func__);
unregister_pernet_device(&ipip_net_ops);
}
