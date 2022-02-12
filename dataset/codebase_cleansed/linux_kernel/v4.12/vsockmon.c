static int vsockmon_dev_init(struct net_device *dev)
{
dev->lstats = netdev_alloc_pcpu_stats(struct pcpu_lstats);
if (!dev->lstats)
return -ENOMEM;
return 0;
}
static void vsockmon_dev_uninit(struct net_device *dev)
{
free_percpu(dev->lstats);
}
static int vsockmon_open(struct net_device *dev)
{
struct vsockmon *vsockmon = netdev_priv(dev);
vsockmon->vt.dev = dev;
vsockmon->vt.module = THIS_MODULE;
return vsock_add_tap(&vsockmon->vt);
}
static int vsockmon_close(struct net_device *dev)
{
struct vsockmon *vsockmon = netdev_priv(dev);
return vsock_remove_tap(&vsockmon->vt);
}
static netdev_tx_t vsockmon_xmit(struct sk_buff *skb, struct net_device *dev)
{
int len = skb->len;
struct pcpu_lstats *stats = this_cpu_ptr(dev->lstats);
u64_stats_update_begin(&stats->syncp);
stats->rx_bytes += len;
stats->rx_packets++;
u64_stats_update_end(&stats->syncp);
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void
vsockmon_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
int i;
u64 bytes = 0, packets = 0;
for_each_possible_cpu(i) {
const struct pcpu_lstats *vstats;
u64 tbytes, tpackets;
unsigned int start;
vstats = per_cpu_ptr(dev->lstats, i);
do {
start = u64_stats_fetch_begin_irq(&vstats->syncp);
tbytes = vstats->rx_bytes;
tpackets = vstats->rx_packets;
} while (u64_stats_fetch_retry_irq(&vstats->syncp, start));
packets += tpackets;
bytes += tbytes;
}
stats->rx_packets = packets;
stats->tx_packets = 0;
stats->rx_bytes = bytes;
stats->tx_bytes = 0;
}
static int vsockmon_is_valid_mtu(int new_mtu)
{
return new_mtu >= (int)sizeof(struct af_vsockmon_hdr);
}
static int vsockmon_change_mtu(struct net_device *dev, int new_mtu)
{
if (!vsockmon_is_valid_mtu(new_mtu))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static u32 always_on(struct net_device *dev)
{
return 1;
}
static void vsockmon_setup(struct net_device *dev)
{
dev->type = ARPHRD_VSOCKMON;
dev->priv_flags |= IFF_NO_QUEUE;
dev->netdev_ops = &vsockmon_ops;
dev->ethtool_ops = &vsockmon_ethtool_ops;
dev->needs_free_netdev = true;
dev->features = NETIF_F_SG | NETIF_F_FRAGLIST |
NETIF_F_HIGHDMA | NETIF_F_LLTX;
dev->flags = IFF_NOARP;
dev->mtu = DEFAULT_MTU;
}
static __init int vsockmon_register(void)
{
return rtnl_link_register(&vsockmon_link_ops);
}
static __exit void vsockmon_unregister(void)
{
rtnl_link_unregister(&vsockmon_link_ops);
}
