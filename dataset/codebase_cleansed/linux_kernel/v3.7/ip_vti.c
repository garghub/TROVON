static struct rtnl_link_stats64 *vti_get_stats64(struct net_device *dev,
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
tot->rx_errors = dev->stats.rx_errors;
tot->tx_fifo_errors = dev->stats.tx_fifo_errors;
tot->tx_carrier_errors = dev->stats.tx_carrier_errors;
tot->tx_dropped = dev->stats.tx_dropped;
tot->tx_aborted_errors = dev->stats.tx_aborted_errors;
tot->tx_errors = dev->stats.tx_errors;
return tot;
}
static struct ip_tunnel *vti_tunnel_lookup(struct net *net,
__be32 remote, __be32 local)
{
unsigned h0 = HASH(remote);
unsigned h1 = HASH(local);
struct ip_tunnel *t;
struct vti_net *ipn = net_generic(net, vti_net_id);
for_each_ip_tunnel_rcu(ipn->tunnels_r_l[h0 ^ h1])
if (local == t->parms.iph.saddr &&
remote == t->parms.iph.daddr && (t->dev->flags&IFF_UP))
return t;
for_each_ip_tunnel_rcu(ipn->tunnels_r[h0])
if (remote == t->parms.iph.daddr && (t->dev->flags&IFF_UP))
return t;
for_each_ip_tunnel_rcu(ipn->tunnels_l[h1])
if (local == t->parms.iph.saddr && (t->dev->flags&IFF_UP))
return t;
for_each_ip_tunnel_rcu(ipn->tunnels_wc[0])
if (t && (t->dev->flags&IFF_UP))
return t;
return NULL;
}
static struct ip_tunnel __rcu **__vti_bucket(struct vti_net *ipn,
struct ip_tunnel_parm *parms)
{
__be32 remote = parms->iph.daddr;
__be32 local = parms->iph.saddr;
unsigned h = 0;
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
static inline struct ip_tunnel __rcu **vti_bucket(struct vti_net *ipn,
struct ip_tunnel *t)
{
return __vti_bucket(ipn, &t->parms);
}
static void vti_tunnel_unlink(struct vti_net *ipn, struct ip_tunnel *t)
{
struct ip_tunnel __rcu **tp;
struct ip_tunnel *iter;
for (tp = vti_bucket(ipn, t);
(iter = rtnl_dereference(*tp)) != NULL;
tp = &iter->next) {
if (t == iter) {
rcu_assign_pointer(*tp, t->next);
break;
}
}
}
static void vti_tunnel_link(struct vti_net *ipn, struct ip_tunnel *t)
{
struct ip_tunnel __rcu **tp = vti_bucket(ipn, t);
rcu_assign_pointer(t->next, rtnl_dereference(*tp));
rcu_assign_pointer(*tp, t);
}
static struct ip_tunnel *vti_tunnel_locate(struct net *net,
struct ip_tunnel_parm *parms,
int create)
{
__be32 remote = parms->iph.daddr;
__be32 local = parms->iph.saddr;
struct ip_tunnel *t, *nt;
struct ip_tunnel __rcu **tp;
struct net_device *dev;
char name[IFNAMSIZ];
struct vti_net *ipn = net_generic(net, vti_net_id);
for (tp = __vti_bucket(ipn, parms);
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
strcpy(name, "vti%d");
dev = alloc_netdev(sizeof(*t), name, vti_tunnel_setup);
if (dev == NULL)
return NULL;
dev_net_set(dev, net);
nt = netdev_priv(dev);
nt->parms = *parms;
dev->rtnl_link_ops = &vti_link_ops;
vti_tunnel_bind_dev(dev);
if (register_netdevice(dev) < 0)
goto failed_free;
dev_hold(dev);
vti_tunnel_link(ipn, nt);
return nt;
failed_free:
free_netdev(dev);
return NULL;
}
static void vti_tunnel_uninit(struct net_device *dev)
{
struct net *net = dev_net(dev);
struct vti_net *ipn = net_generic(net, vti_net_id);
vti_tunnel_unlink(ipn, netdev_priv(dev));
dev_put(dev);
}
static int vti_err(struct sk_buff *skb, u32 info)
{
struct iphdr *iph = (struct iphdr *)skb->data;
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
}
err = -ENOENT;
t = vti_tunnel_lookup(dev_net(skb->dev), iph->daddr, iph->saddr);
if (t == NULL)
goto out;
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED) {
ipv4_update_pmtu(skb, dev_net(skb->dev), info,
t->parms.link, 0, IPPROTO_IPIP, 0);
err = 0;
goto out;
}
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
static int vti_rcv(struct sk_buff *skb)
{
struct ip_tunnel *tunnel;
const struct iphdr *iph = ip_hdr(skb);
tunnel = vti_tunnel_lookup(dev_net(skb->dev), iph->saddr, iph->daddr);
if (tunnel != NULL) {
struct pcpu_tstats *tstats;
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
return -1;
tstats = this_cpu_ptr(tunnel->dev->tstats);
u64_stats_update_begin(&tstats->syncp);
tstats->rx_packets++;
tstats->rx_bytes += skb->len;
u64_stats_update_end(&tstats->syncp);
skb->mark = 0;
secpath_reset(skb);
skb->dev = tunnel->dev;
return 1;
}
return -1;
}
static netdev_tx_t vti_tunnel_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct pcpu_tstats *tstats;
struct iphdr *tiph = &tunnel->parms.iph;
u8 tos;
struct rtable *rt;
struct net_device *tdev;
struct iphdr *old_iph = ip_hdr(skb);
__be32 dst = tiph->daddr;
struct flowi4 fl4;
if (skb->protocol != htons(ETH_P_IP))
goto tx_error;
tos = old_iph->tos;
memset(&fl4, 0, sizeof(fl4));
flowi4_init_output(&fl4, tunnel->parms.link,
be32_to_cpu(tunnel->parms.i_key), RT_TOS(tos),
RT_SCOPE_UNIVERSE,
IPPROTO_IPIP, 0,
dst, tiph->saddr, 0, 0);
rt = ip_route_output_key(dev_net(dev), &fl4);
if (IS_ERR(rt)) {
dev->stats.tx_carrier_errors++;
goto tx_error_icmp;
}
if (!rt->dst.xfrm ||
rt->dst.xfrm->props.mode != XFRM_MODE_TUNNEL) {
dev->stats.tx_carrier_errors++;
goto tx_error_icmp;
}
tdev = rt->dst.dev;
if (tdev == dev) {
ip_rt_put(rt);
dev->stats.collisions++;
goto tx_error;
}
if (tunnel->err_count > 0) {
if (time_before(jiffies,
tunnel->err_time + IPTUNNEL_ERR_TIMEO)) {
tunnel->err_count--;
dst_link_failure(skb);
} else
tunnel->err_count = 0;
}
IPCB(skb)->flags &= ~(IPSKB_XFRM_TUNNEL_SIZE | IPSKB_XFRM_TRANSFORMED |
IPSKB_REROUTED);
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
nf_reset(skb);
skb->dev = skb_dst(skb)->dev;
tstats = this_cpu_ptr(dev->tstats);
VTI_XMIT(tstats, &dev->stats);
return NETDEV_TX_OK;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
dev->stats.tx_errors++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int vti_tunnel_bind_dev(struct net_device *dev)
{
struct net_device *tdev = NULL;
struct ip_tunnel *tunnel;
struct iphdr *iph;
tunnel = netdev_priv(dev);
iph = &tunnel->parms.iph;
if (iph->daddr) {
struct rtable *rt;
struct flowi4 fl4;
memset(&fl4, 0, sizeof(fl4));
flowi4_init_output(&fl4, tunnel->parms.link,
be32_to_cpu(tunnel->parms.i_key),
RT_TOS(iph->tos), RT_SCOPE_UNIVERSE,
IPPROTO_IPIP, 0,
iph->daddr, iph->saddr, 0, 0);
rt = ip_route_output_key(dev_net(dev), &fl4);
if (!IS_ERR(rt)) {
tdev = rt->dst.dev;
ip_rt_put(rt);
}
dev->flags |= IFF_POINTOPOINT;
}
if (!tdev && tunnel->parms.link)
tdev = __dev_get_by_index(dev_net(dev), tunnel->parms.link);
if (tdev) {
dev->hard_header_len = tdev->hard_header_len +
sizeof(struct iphdr);
dev->mtu = tdev->mtu;
}
dev->iflink = tunnel->parms.link;
return dev->mtu;
}
static int
vti_tunnel_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip_tunnel_parm p;
struct ip_tunnel *t;
struct net *net = dev_net(dev);
struct vti_net *ipn = net_generic(net, vti_net_id);
switch (cmd) {
case SIOCGETTUNNEL:
t = NULL;
if (dev == ipn->fb_tunnel_dev) {
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data,
sizeof(p))) {
err = -EFAULT;
break;
}
t = vti_tunnel_locate(net, &p, 0);
}
if (t == NULL)
t = netdev_priv(dev);
memcpy(&p, &t->parms, sizeof(p));
p.i_flags |= GRE_KEY | VTI_ISVTI;
p.o_flags |= GRE_KEY;
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
if (p.iph.version != 4 || p.iph.protocol != IPPROTO_IPIP ||
p.iph.ihl != 5)
goto done;
t = vti_tunnel_locate(net, &p, cmd == SIOCADDTUNNEL);
if (dev != ipn->fb_tunnel_dev && cmd == SIOCCHGTUNNEL) {
if (t != NULL) {
if (t->dev != dev) {
err = -EEXIST;
break;
}
} else {
if (((dev->flags&IFF_POINTOPOINT) &&
!p.iph.daddr) ||
(!(dev->flags&IFF_POINTOPOINT) &&
p.iph.daddr)) {
err = -EINVAL;
break;
}
t = netdev_priv(dev);
vti_tunnel_unlink(ipn, t);
synchronize_net();
t->parms.iph.saddr = p.iph.saddr;
t->parms.iph.daddr = p.iph.daddr;
t->parms.i_key = p.i_key;
t->parms.o_key = p.o_key;
t->parms.iph.protocol = IPPROTO_IPIP;
memcpy(dev->dev_addr, &p.iph.saddr, 4);
memcpy(dev->broadcast, &p.iph.daddr, 4);
vti_tunnel_link(ipn, t);
netdev_state_change(dev);
}
}
if (t) {
err = 0;
if (cmd == SIOCCHGTUNNEL) {
t->parms.i_key = p.i_key;
t->parms.o_key = p.o_key;
if (t->parms.link != p.link) {
t->parms.link = p.link;
vti_tunnel_bind_dev(dev);
netdev_state_change(dev);
}
}
p.i_flags |= GRE_KEY | VTI_ISVTI;
p.o_flags |= GRE_KEY;
if (copy_to_user(ifr->ifr_ifru.ifru_data, &t->parms,
sizeof(p)))
err = -EFAULT;
} else
err = (cmd == SIOCADDTUNNEL ? -ENOBUFS : -ENOENT);
break;
case SIOCDELTUNNEL:
err = -EPERM;
if (!capable(CAP_NET_ADMIN))
goto done;
if (dev == ipn->fb_tunnel_dev) {
err = -EFAULT;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data,
sizeof(p)))
goto done;
err = -ENOENT;
t = vti_tunnel_locate(net, &p, 0);
if (t == NULL)
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
static int vti_tunnel_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < 68 || new_mtu > 0xFFF8)
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static void vti_dev_free(struct net_device *dev)
{
free_percpu(dev->tstats);
free_netdev(dev);
}
static void vti_tunnel_setup(struct net_device *dev)
{
dev->netdev_ops = &vti_netdev_ops;
dev->destructor = vti_dev_free;
dev->type = ARPHRD_TUNNEL;
dev->hard_header_len = LL_MAX_HEADER + sizeof(struct iphdr);
dev->mtu = ETH_DATA_LEN;
dev->flags = IFF_NOARP;
dev->iflink = 0;
dev->addr_len = 4;
dev->features |= NETIF_F_NETNS_LOCAL;
dev->features |= NETIF_F_LLTX;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
}
static int vti_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
tunnel->dev = dev;
strcpy(tunnel->parms.name, dev->name);
memcpy(dev->dev_addr, &tunnel->parms.iph.saddr, 4);
memcpy(dev->broadcast, &tunnel->parms.iph.daddr, 4);
dev->tstats = alloc_percpu(struct pcpu_tstats);
if (!dev->tstats)
return -ENOMEM;
return 0;
}
static int __net_init vti_fb_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct iphdr *iph = &tunnel->parms.iph;
struct vti_net *ipn = net_generic(dev_net(dev), vti_net_id);
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
static void vti_destroy_tunnels(struct vti_net *ipn, struct list_head *head)
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
static int __net_init vti_init_net(struct net *net)
{
int err;
struct vti_net *ipn = net_generic(net, vti_net_id);
ipn->tunnels[0] = ipn->tunnels_wc;
ipn->tunnels[1] = ipn->tunnels_l;
ipn->tunnels[2] = ipn->tunnels_r;
ipn->tunnels[3] = ipn->tunnels_r_l;
ipn->fb_tunnel_dev = alloc_netdev(sizeof(struct ip_tunnel),
"ip_vti0",
vti_tunnel_setup);
if (!ipn->fb_tunnel_dev) {
err = -ENOMEM;
goto err_alloc_dev;
}
dev_net_set(ipn->fb_tunnel_dev, net);
err = vti_fb_tunnel_init(ipn->fb_tunnel_dev);
if (err)
goto err_reg_dev;
ipn->fb_tunnel_dev->rtnl_link_ops = &vti_link_ops;
err = register_netdev(ipn->fb_tunnel_dev);
if (err)
goto err_reg_dev;
return 0;
err_reg_dev:
vti_dev_free(ipn->fb_tunnel_dev);
err_alloc_dev:
return err;
}
static void __net_exit vti_exit_net(struct net *net)
{
struct vti_net *ipn = net_generic(net, vti_net_id);
LIST_HEAD(list);
rtnl_lock();
vti_destroy_tunnels(ipn, &list);
unregister_netdevice_many(&list);
rtnl_unlock();
}
static int vti_tunnel_validate(struct nlattr *tb[], struct nlattr *data[])
{
return 0;
}
static void vti_netlink_parms(struct nlattr *data[],
struct ip_tunnel_parm *parms)
{
memset(parms, 0, sizeof(*parms));
parms->iph.protocol = IPPROTO_IPIP;
if (!data)
return;
if (data[IFLA_VTI_LINK])
parms->link = nla_get_u32(data[IFLA_VTI_LINK]);
if (data[IFLA_VTI_IKEY])
parms->i_key = nla_get_be32(data[IFLA_VTI_IKEY]);
if (data[IFLA_VTI_OKEY])
parms->o_key = nla_get_be32(data[IFLA_VTI_OKEY]);
if (data[IFLA_VTI_LOCAL])
parms->iph.saddr = nla_get_be32(data[IFLA_VTI_LOCAL]);
if (data[IFLA_VTI_REMOTE])
parms->iph.daddr = nla_get_be32(data[IFLA_VTI_REMOTE]);
}
static int vti_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct ip_tunnel *nt;
struct net *net = dev_net(dev);
struct vti_net *ipn = net_generic(net, vti_net_id);
int mtu;
int err;
nt = netdev_priv(dev);
vti_netlink_parms(data, &nt->parms);
if (vti_tunnel_locate(net, &nt->parms, 0))
return -EEXIST;
mtu = vti_tunnel_bind_dev(dev);
if (!tb[IFLA_MTU])
dev->mtu = mtu;
err = register_netdevice(dev);
if (err)
goto out;
dev_hold(dev);
vti_tunnel_link(ipn, nt);
out:
return err;
}
static int vti_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel *t, *nt;
struct net *net = dev_net(dev);
struct vti_net *ipn = net_generic(net, vti_net_id);
struct ip_tunnel_parm p;
int mtu;
if (dev == ipn->fb_tunnel_dev)
return -EINVAL;
nt = netdev_priv(dev);
vti_netlink_parms(data, &p);
t = vti_tunnel_locate(net, &p, 0);
if (t) {
if (t->dev != dev)
return -EEXIST;
} else {
t = nt;
vti_tunnel_unlink(ipn, t);
t->parms.iph.saddr = p.iph.saddr;
t->parms.iph.daddr = p.iph.daddr;
t->parms.i_key = p.i_key;
t->parms.o_key = p.o_key;
if (dev->type != ARPHRD_ETHER) {
memcpy(dev->dev_addr, &p.iph.saddr, 4);
memcpy(dev->broadcast, &p.iph.daddr, 4);
}
vti_tunnel_link(ipn, t);
netdev_state_change(dev);
}
if (t->parms.link != p.link) {
t->parms.link = p.link;
mtu = vti_tunnel_bind_dev(dev);
if (!tb[IFLA_MTU])
dev->mtu = mtu;
netdev_state_change(dev);
}
return 0;
}
static size_t vti_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
0;
}
static int vti_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
struct ip_tunnel_parm *p = &t->parms;
nla_put_u32(skb, IFLA_VTI_LINK, p->link);
nla_put_be32(skb, IFLA_VTI_IKEY, p->i_key);
nla_put_be32(skb, IFLA_VTI_OKEY, p->o_key);
nla_put_be32(skb, IFLA_VTI_LOCAL, p->iph.saddr);
nla_put_be32(skb, IFLA_VTI_REMOTE, p->iph.daddr);
return 0;
}
static int __init vti_init(void)
{
int err;
pr_info("IPv4 over IPSec tunneling driver\n");
err = register_pernet_device(&vti_net_ops);
if (err < 0)
return err;
err = xfrm4_mode_tunnel_input_register(&vti_handler);
if (err < 0) {
unregister_pernet_device(&vti_net_ops);
pr_info(KERN_INFO "vti init: can't register tunnel\n");
}
err = rtnl_link_register(&vti_link_ops);
if (err < 0)
goto rtnl_link_failed;
return err;
rtnl_link_failed:
xfrm4_mode_tunnel_input_deregister(&vti_handler);
unregister_pernet_device(&vti_net_ops);
return err;
}
static void __exit vti_fini(void)
{
rtnl_link_unregister(&vti_link_ops);
if (xfrm4_mode_tunnel_input_deregister(&vti_handler))
pr_info("vti close: can't deregister tunnel\n");
unregister_pernet_device(&vti_net_ops);
}
