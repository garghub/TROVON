static netdev_tx_t loopback_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct pcpu_lstats *lb_stats;
int len;
skb_orphan(skb);
skb_dst_force(skb);
skb->protocol = eth_type_trans(skb, dev);
lb_stats = this_cpu_ptr(dev->lstats);
len = skb->len;
if (likely(netif_rx(skb) == NET_RX_SUCCESS)) {
u64_stats_update_begin(&lb_stats->syncp);
lb_stats->bytes += len;
lb_stats->packets++;
u64_stats_update_end(&lb_stats->syncp);
}
return NETDEV_TX_OK;
}
static struct rtnl_link_stats64 *loopback_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
u64 bytes = 0;
u64 packets = 0;
int i;
for_each_possible_cpu(i) {
const struct pcpu_lstats *lb_stats;
u64 tbytes, tpackets;
unsigned int start;
lb_stats = per_cpu_ptr(dev->lstats, i);
do {
start = u64_stats_fetch_begin_bh(&lb_stats->syncp);
tbytes = lb_stats->bytes;
tpackets = lb_stats->packets;
} while (u64_stats_fetch_retry_bh(&lb_stats->syncp, start));
bytes += tbytes;
packets += tpackets;
}
stats->rx_packets = packets;
stats->tx_packets = packets;
stats->rx_bytes = bytes;
stats->tx_bytes = bytes;
return stats;
}
static u32 always_on(struct net_device *dev)
{
return 1;
}
static int loopback_dev_init(struct net_device *dev)
{
dev->lstats = alloc_percpu(struct pcpu_lstats);
if (!dev->lstats)
return -ENOMEM;
return 0;
}
static void loopback_dev_free(struct net_device *dev)
{
dev_net(dev)->loopback_dev = NULL;
free_percpu(dev->lstats);
free_netdev(dev);
}
static void loopback_setup(struct net_device *dev)
{
dev->mtu = 64 * 1024;
dev->hard_header_len = ETH_HLEN;
dev->addr_len = ETH_ALEN;
dev->tx_queue_len = 0;
dev->type = ARPHRD_LOOPBACK;
dev->flags = IFF_LOOPBACK;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
dev->hw_features = NETIF_F_ALL_TSO | NETIF_F_UFO;
dev->features = NETIF_F_SG | NETIF_F_FRAGLIST
| NETIF_F_ALL_TSO
| NETIF_F_UFO
| NETIF_F_HW_CSUM
| NETIF_F_RXCSUM
| NETIF_F_HIGHDMA
| NETIF_F_LLTX
| NETIF_F_NETNS_LOCAL
| NETIF_F_VLAN_CHALLENGED
| NETIF_F_LOOPBACK;
dev->ethtool_ops = &loopback_ethtool_ops;
dev->header_ops = &eth_header_ops;
dev->netdev_ops = &loopback_ops;
dev->destructor = loopback_dev_free;
}
static __net_init int loopback_net_init(struct net *net)
{
struct net_device *dev;
int err;
err = -ENOMEM;
dev = alloc_netdev(0, "lo", loopback_setup);
if (!dev)
goto out;
dev_net_set(dev, net);
err = register_netdev(dev);
if (err)
goto out_free_netdev;
BUG_ON(dev->ifindex != LOOPBACK_IFINDEX);
net->loopback_dev = dev;
return 0;
out_free_netdev:
free_netdev(dev);
out:
if (net_eq(net, &init_net))
panic("loopback: Failed to register netdevice: %d\n", err);
return err;
}
