static bool check_ipv6_frame(const struct sk_buff *skb)
{
const struct ipv6hdr *ipv6h;
struct ipv6hdr _ipv6h;
bool rc = true;
ipv6h = skb_header_pointer(skb, 0, sizeof(_ipv6h), &_ipv6h);
if (!ipv6h)
goto out;
if (ipv6h->nexthdr == NEXTHDR_ICMP) {
const struct icmp6hdr *icmph;
struct icmp6hdr _icmph;
icmph = skb_header_pointer(skb, sizeof(_ipv6h),
sizeof(_icmph), &_icmph);
if (!icmph)
goto out;
switch (icmph->icmp6_type) {
case NDISC_ROUTER_SOLICITATION:
case NDISC_ROUTER_ADVERTISEMENT:
case NDISC_NEIGHBOUR_SOLICITATION:
case NDISC_NEIGHBOUR_ADVERTISEMENT:
case NDISC_REDIRECT:
rc = false;
break;
}
}
out:
return rc;
}
static bool check_ipv6_frame(const struct sk_buff *skb)
{
return false;
}
static bool is_ip_rx_frame(struct sk_buff *skb)
{
switch (skb->protocol) {
case htons(ETH_P_IP):
return true;
case htons(ETH_P_IPV6):
return check_ipv6_frame(skb);
}
return false;
}
static void vrf_tx_error(struct net_device *vrf_dev, struct sk_buff *skb)
{
vrf_dev->stats.tx_errors++;
kfree_skb(skb);
}
static rx_handler_result_t vrf_handle_frame(struct sk_buff **pskb)
{
struct sk_buff *skb = *pskb;
if (is_ip_rx_frame(skb)) {
struct net_device *dev = vrf_master_get_rcu(skb->dev);
struct pcpu_dstats *dstats = this_cpu_ptr(dev->dstats);
u64_stats_update_begin(&dstats->syncp);
dstats->rx_pkts++;
dstats->rx_bytes += skb->len;
u64_stats_update_end(&dstats->syncp);
skb->dev = dev;
return RX_HANDLER_ANOTHER;
}
return RX_HANDLER_PASS;
}
static struct rtnl_link_stats64 *vrf_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
int i;
for_each_possible_cpu(i) {
const struct pcpu_dstats *dstats;
u64 tbytes, tpkts, tdrops, rbytes, rpkts;
unsigned int start;
dstats = per_cpu_ptr(dev->dstats, i);
do {
start = u64_stats_fetch_begin_irq(&dstats->syncp);
tbytes = dstats->tx_bytes;
tpkts = dstats->tx_pkts;
tdrops = dstats->tx_drps;
rbytes = dstats->rx_bytes;
rpkts = dstats->rx_pkts;
} while (u64_stats_fetch_retry_irq(&dstats->syncp, start));
stats->tx_bytes += tbytes;
stats->tx_packets += tpkts;
stats->tx_dropped += tdrops;
stats->rx_bytes += rbytes;
stats->rx_packets += rpkts;
}
return stats;
}
static netdev_tx_t vrf_process_v6_outbound(struct sk_buff *skb,
struct net_device *dev)
{
const struct ipv6hdr *iph = ipv6_hdr(skb);
struct net *net = dev_net(skb->dev);
struct flowi6 fl6 = {
.flowi6_oif = dev->ifindex,
.flowi6_iif = LOOPBACK_IFINDEX,
.daddr = iph->daddr,
.saddr = iph->saddr,
.flowlabel = ip6_flowinfo(iph),
.flowi6_mark = skb->mark,
.flowi6_proto = iph->nexthdr,
.flowi6_flags = FLOWI_FLAG_L3MDEV_SRC | FLOWI_FLAG_SKIP_NH_OIF,
};
int ret = NET_XMIT_DROP;
struct dst_entry *dst;
struct dst_entry *dst_null = &net->ipv6.ip6_null_entry->dst;
dst = ip6_route_output(net, NULL, &fl6);
if (dst == dst_null)
goto err;
skb_dst_drop(skb);
skb_dst_set(skb, dst);
ret = ip6_local_out(net, skb->sk, skb);
if (unlikely(net_xmit_eval(ret)))
dev->stats.tx_errors++;
else
ret = NET_XMIT_SUCCESS;
return ret;
err:
vrf_tx_error(dev, skb);
return NET_XMIT_DROP;
}
static netdev_tx_t vrf_process_v6_outbound(struct sk_buff *skb,
struct net_device *dev)
{
vrf_tx_error(dev, skb);
return NET_XMIT_DROP;
}
static int vrf_send_v4_prep(struct sk_buff *skb, struct flowi4 *fl4,
struct net_device *vrf_dev)
{
struct rtable *rt;
int err = 1;
rt = ip_route_output_flow(dev_net(vrf_dev), fl4, NULL);
if (IS_ERR(rt))
goto out;
if (rt->rt_type != RTN_UNICAST && rt->rt_type != RTN_LOCAL) {
ip_rt_put(rt);
goto out;
}
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
err = 0;
out:
return err;
}
static netdev_tx_t vrf_process_v4_outbound(struct sk_buff *skb,
struct net_device *vrf_dev)
{
struct iphdr *ip4h = ip_hdr(skb);
int ret = NET_XMIT_DROP;
struct flowi4 fl4 = {
.flowi4_oif = vrf_dev->ifindex,
.flowi4_iif = LOOPBACK_IFINDEX,
.flowi4_tos = RT_TOS(ip4h->tos),
.flowi4_flags = FLOWI_FLAG_ANYSRC | FLOWI_FLAG_L3MDEV_SRC |
FLOWI_FLAG_SKIP_NH_OIF,
.daddr = ip4h->daddr,
};
if (vrf_send_v4_prep(skb, &fl4, vrf_dev))
goto err;
if (!ip4h->saddr) {
ip4h->saddr = inet_select_addr(skb_dst(skb)->dev, 0,
RT_SCOPE_LINK);
}
ret = ip_local_out(dev_net(skb_dst(skb)->dev), skb->sk, skb);
if (unlikely(net_xmit_eval(ret)))
vrf_dev->stats.tx_errors++;
else
ret = NET_XMIT_SUCCESS;
out:
return ret;
err:
vrf_tx_error(vrf_dev, skb);
goto out;
}
static netdev_tx_t is_ip_tx_frame(struct sk_buff *skb, struct net_device *dev)
{
__skb_pull(skb, skb_network_offset(skb));
switch (skb->protocol) {
case htons(ETH_P_IP):
return vrf_process_v4_outbound(skb, dev);
case htons(ETH_P_IPV6):
return vrf_process_v6_outbound(skb, dev);
default:
vrf_tx_error(dev, skb);
return NET_XMIT_DROP;
}
}
static netdev_tx_t vrf_xmit(struct sk_buff *skb, struct net_device *dev)
{
netdev_tx_t ret = is_ip_tx_frame(skb, dev);
if (likely(ret == NET_XMIT_SUCCESS || ret == NET_XMIT_CN)) {
struct pcpu_dstats *dstats = this_cpu_ptr(dev->dstats);
u64_stats_update_begin(&dstats->syncp);
dstats->tx_pkts++;
dstats->tx_bytes += skb->len;
u64_stats_update_end(&dstats->syncp);
} else {
this_cpu_inc(dev->dstats->tx_drps);
}
return ret;
}
static int vrf_finish_output6(struct net *net, struct sock *sk,
struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
struct net_device *dev = dst->dev;
struct neighbour *neigh;
struct in6_addr *nexthop;
int ret;
skb->protocol = htons(ETH_P_IPV6);
skb->dev = dev;
rcu_read_lock_bh();
nexthop = rt6_nexthop((struct rt6_info *)dst, &ipv6_hdr(skb)->daddr);
neigh = __ipv6_neigh_lookup_noref(dst->dev, nexthop);
if (unlikely(!neigh))
neigh = __neigh_create(&nd_tbl, nexthop, dst->dev, false);
if (!IS_ERR(neigh)) {
ret = dst_neigh_output(dst, neigh, skb);
rcu_read_unlock_bh();
return ret;
}
rcu_read_unlock_bh();
IP6_INC_STATS(dev_net(dst->dev),
ip6_dst_idev(dst), IPSTATS_MIB_OUTNOROUTES);
kfree_skb(skb);
return -EINVAL;
}
static int vrf_output6(struct net *net, struct sock *sk, struct sk_buff *skb)
{
return NF_HOOK_COND(NFPROTO_IPV6, NF_INET_POST_ROUTING,
net, sk, skb, NULL, skb_dst(skb)->dev,
vrf_finish_output6,
!(IP6CB(skb)->flags & IP6SKB_REROUTED));
}
static void vrf_rt6_release(struct net_vrf *vrf)
{
dst_release(&vrf->rt6->dst);
vrf->rt6 = NULL;
}
static int vrf_rt6_create(struct net_device *dev)
{
struct net_vrf *vrf = netdev_priv(dev);
struct net *net = dev_net(dev);
struct rt6_info *rt6;
int rc = -ENOMEM;
rt6 = ip6_dst_alloc(net, dev,
DST_HOST | DST_NOPOLICY | DST_NOXFRM | DST_NOCACHE);
if (!rt6)
goto out;
rt6->dst.output = vrf_output6;
rt6->rt6i_table = fib6_get_table(net, vrf->tb_id);
dst_hold(&rt6->dst);
vrf->rt6 = rt6;
rc = 0;
out:
return rc;
}
static void vrf_rt6_release(struct net_vrf *vrf)
{
}
static int vrf_rt6_create(struct net_device *dev)
{
return 0;
}
static int vrf_finish_output(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
struct rtable *rt = (struct rtable *)dst;
struct net_device *dev = dst->dev;
unsigned int hh_len = LL_RESERVED_SPACE(dev);
struct neighbour *neigh;
u32 nexthop;
int ret = -EINVAL;
if (unlikely(skb_headroom(skb) < hh_len && dev->header_ops)) {
struct sk_buff *skb2;
skb2 = skb_realloc_headroom(skb, LL_RESERVED_SPACE(dev));
if (!skb2) {
ret = -ENOMEM;
goto err;
}
if (skb->sk)
skb_set_owner_w(skb2, skb->sk);
consume_skb(skb);
skb = skb2;
}
rcu_read_lock_bh();
nexthop = (__force u32)rt_nexthop(rt, ip_hdr(skb)->daddr);
neigh = __ipv4_neigh_lookup_noref(dev, nexthop);
if (unlikely(!neigh))
neigh = __neigh_create(&arp_tbl, &nexthop, dev, false);
if (!IS_ERR(neigh))
ret = dst_neigh_output(dst, neigh, skb);
rcu_read_unlock_bh();
err:
if (unlikely(ret < 0))
vrf_tx_error(skb->dev, skb);
return ret;
}
static int vrf_output(struct net *net, struct sock *sk, struct sk_buff *skb)
{
struct net_device *dev = skb_dst(skb)->dev;
IP_UPD_PO_STATS(net, IPSTATS_MIB_OUT, skb->len);
skb->dev = dev;
skb->protocol = htons(ETH_P_IP);
return NF_HOOK_COND(NFPROTO_IPV4, NF_INET_POST_ROUTING,
net, sk, skb, NULL, dev,
vrf_finish_output,
!(IPCB(skb)->flags & IPSKB_REROUTED));
}
static void vrf_rtable_release(struct net_vrf *vrf)
{
struct dst_entry *dst = (struct dst_entry *)vrf->rth;
dst_release(dst);
vrf->rth = NULL;
}
static struct rtable *vrf_rtable_create(struct net_device *dev)
{
struct net_vrf *vrf = netdev_priv(dev);
struct rtable *rth;
rth = rt_dst_alloc(dev, 0, RTN_UNICAST, 1, 1, 0);
if (rth) {
rth->dst.output = vrf_output;
rth->rt_table_id = vrf->tb_id;
}
return rth;
}
static void cycle_netdev(struct net_device *dev)
{
unsigned int flags = dev->flags;
int ret;
if (!netif_running(dev))
return;
ret = dev_change_flags(dev, flags & ~IFF_UP);
if (ret >= 0)
ret = dev_change_flags(dev, flags);
if (ret < 0) {
netdev_err(dev,
"Failed to cycle device %s; route tables might be wrong!\n",
dev->name);
}
}
static int do_vrf_add_slave(struct net_device *dev, struct net_device *port_dev)
{
int ret;
ret = netdev_rx_handler_register(port_dev, vrf_handle_frame, dev);
if (ret) {
netdev_err(port_dev,
"Device %s failed to register rx_handler\n",
port_dev->name);
goto out_fail;
}
ret = netdev_master_upper_dev_link(port_dev, dev, NULL, NULL);
if (ret < 0)
goto out_unregister;
port_dev->priv_flags |= IFF_L3MDEV_SLAVE;
cycle_netdev(port_dev);
return 0;
out_unregister:
netdev_rx_handler_unregister(port_dev);
out_fail:
return ret;
}
static int vrf_add_slave(struct net_device *dev, struct net_device *port_dev)
{
if (netif_is_l3_master(port_dev) || netif_is_l3_slave(port_dev))
return -EINVAL;
return do_vrf_add_slave(dev, port_dev);
}
static int do_vrf_del_slave(struct net_device *dev, struct net_device *port_dev)
{
netdev_upper_dev_unlink(port_dev, dev);
port_dev->priv_flags &= ~IFF_L3MDEV_SLAVE;
netdev_rx_handler_unregister(port_dev);
cycle_netdev(port_dev);
return 0;
}
static int vrf_del_slave(struct net_device *dev, struct net_device *port_dev)
{
return do_vrf_del_slave(dev, port_dev);
}
static void vrf_dev_uninit(struct net_device *dev)
{
struct net_vrf *vrf = netdev_priv(dev);
struct net_device *port_dev;
struct list_head *iter;
vrf_rtable_release(vrf);
vrf_rt6_release(vrf);
netdev_for_each_lower_dev(dev, port_dev, iter)
vrf_del_slave(dev, port_dev);
free_percpu(dev->dstats);
dev->dstats = NULL;
}
static int vrf_dev_init(struct net_device *dev)
{
struct net_vrf *vrf = netdev_priv(dev);
dev->dstats = netdev_alloc_pcpu_stats(struct pcpu_dstats);
if (!dev->dstats)
goto out_nomem;
vrf->rth = vrf_rtable_create(dev);
if (!vrf->rth)
goto out_stats;
if (vrf_rt6_create(dev) != 0)
goto out_rth;
dev->flags = IFF_MASTER | IFF_NOARP;
return 0;
out_rth:
vrf_rtable_release(vrf);
out_stats:
free_percpu(dev->dstats);
dev->dstats = NULL;
out_nomem:
return -ENOMEM;
}
static u32 vrf_fib_table(const struct net_device *dev)
{
struct net_vrf *vrf = netdev_priv(dev);
return vrf->tb_id;
}
static struct rtable *vrf_get_rtable(const struct net_device *dev,
const struct flowi4 *fl4)
{
struct rtable *rth = NULL;
if (!(fl4->flowi4_flags & FLOWI_FLAG_L3MDEV_SRC)) {
struct net_vrf *vrf = netdev_priv(dev);
rth = vrf->rth;
dst_hold(&rth->dst);
}
return rth;
}
static int vrf_get_saddr(struct net_device *dev, struct flowi4 *fl4)
{
struct fib_result res = { .tclassid = 0 };
struct net *net = dev_net(dev);
u32 orig_tos = fl4->flowi4_tos;
u8 flags = fl4->flowi4_flags;
u8 scope = fl4->flowi4_scope;
u8 tos = RT_FL_TOS(fl4);
int rc;
if (unlikely(!fl4->daddr))
return 0;
fl4->flowi4_flags |= FLOWI_FLAG_SKIP_NH_OIF;
fl4->flowi4_iif = LOOPBACK_IFINDEX;
fl4->flowi4_tos = tos & IPTOS_RT_MASK;
fl4->flowi4_scope = ((tos & RTO_ONLINK) ?
RT_SCOPE_LINK : RT_SCOPE_UNIVERSE);
rc = fib_lookup(net, fl4, &res, 0);
if (!rc) {
if (res.type == RTN_LOCAL)
fl4->saddr = res.fi->fib_prefsrc ? : fl4->daddr;
else
fib_select_path(net, &res, fl4, -1);
}
fl4->flowi4_flags = flags;
fl4->flowi4_tos = orig_tos;
fl4->flowi4_scope = scope;
return rc;
}
static struct dst_entry *vrf_get_rt6_dst(const struct net_device *dev,
const struct flowi6 *fl6)
{
struct rt6_info *rt = NULL;
if (!(fl6->flowi6_flags & FLOWI_FLAG_L3MDEV_SRC)) {
struct net_vrf *vrf = netdev_priv(dev);
rt = vrf->rt6;
dst_hold(&rt->dst);
}
return (struct dst_entry *)rt;
}
static void vrf_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
}
static void vrf_setup(struct net_device *dev)
{
ether_setup(dev);
dev->netdev_ops = &vrf_netdev_ops;
dev->l3mdev_ops = &vrf_l3mdev_ops;
dev->ethtool_ops = &vrf_ethtool_ops;
dev->destructor = free_netdev;
eth_hw_addr_random(dev);
dev->features |= NETIF_F_LLTX;
dev->features |= NETIF_F_NETNS_LOCAL;
}
static int vrf_validate(struct nlattr *tb[], struct nlattr *data[])
{
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
return 0;
}
static void vrf_dellink(struct net_device *dev, struct list_head *head)
{
unregister_netdevice_queue(dev, head);
}
static int vrf_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct net_vrf *vrf = netdev_priv(dev);
if (!data || !data[IFLA_VRF_TABLE])
return -EINVAL;
vrf->tb_id = nla_get_u32(data[IFLA_VRF_TABLE]);
dev->priv_flags |= IFF_L3MDEV_MASTER;
return register_netdevice(dev);
}
static size_t vrf_nl_getsize(const struct net_device *dev)
{
return nla_total_size(sizeof(u32));
}
static int vrf_fillinfo(struct sk_buff *skb,
const struct net_device *dev)
{
struct net_vrf *vrf = netdev_priv(dev);
return nla_put_u32(skb, IFLA_VRF_TABLE, vrf->tb_id);
}
static size_t vrf_get_slave_size(const struct net_device *bond_dev,
const struct net_device *slave_dev)
{
return nla_total_size(sizeof(u32));
}
static int vrf_fill_slave_info(struct sk_buff *skb,
const struct net_device *vrf_dev,
const struct net_device *slave_dev)
{
struct net_vrf *vrf = netdev_priv(vrf_dev);
if (nla_put_u32(skb, IFLA_VRF_PORT_TABLE, vrf->tb_id))
return -EMSGSIZE;
return 0;
}
static int vrf_device_event(struct notifier_block *unused,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
if (event == NETDEV_UNREGISTER) {
struct net_device *vrf_dev;
if (!netif_is_l3_slave(dev))
goto out;
vrf_dev = netdev_master_upper_dev_get(dev);
vrf_del_slave(vrf_dev, dev);
}
out:
return NOTIFY_DONE;
}
static int __init vrf_init_module(void)
{
int rc;
register_netdevice_notifier(&vrf_notifier_block);
rc = rtnl_link_register(&vrf_link_ops);
if (rc < 0)
goto error;
return 0;
error:
unregister_netdevice_notifier(&vrf_notifier_block);
return rc;
}
