static void ri_tasklet(unsigned long dev)
{
struct net_device *_dev = (struct net_device *)dev;
struct ifb_private *dp = netdev_priv(_dev);
struct netdev_queue *txq;
struct sk_buff *skb;
txq = netdev_get_tx_queue(_dev, 0);
if ((skb = skb_peek(&dp->tq)) == NULL) {
if (__netif_tx_trylock(txq)) {
skb_queue_splice_tail_init(&dp->rq, &dp->tq);
__netif_tx_unlock(txq);
} else {
goto resched;
}
}
while ((skb = __skb_dequeue(&dp->tq)) != NULL) {
u32 from = G_TC_FROM(skb->tc_verd);
skb->tc_verd = 0;
skb->tc_verd = SET_TC_NCLS(skb->tc_verd);
u64_stats_update_begin(&dp->tsync);
dp->tx_packets++;
dp->tx_bytes += skb->len;
u64_stats_update_end(&dp->tsync);
rcu_read_lock();
skb->dev = dev_get_by_index_rcu(dev_net(_dev), skb->skb_iif);
if (!skb->dev) {
rcu_read_unlock();
dev_kfree_skb(skb);
_dev->stats.tx_dropped++;
if (skb_queue_len(&dp->tq) != 0)
goto resched;
break;
}
rcu_read_unlock();
skb->skb_iif = _dev->ifindex;
if (from & AT_EGRESS) {
dev_queue_xmit(skb);
} else if (from & AT_INGRESS) {
skb_pull(skb, skb->dev->hard_header_len);
netif_receive_skb(skb);
} else
BUG();
}
if (__netif_tx_trylock(txq)) {
if ((skb = skb_peek(&dp->rq)) == NULL) {
dp->tasklet_pending = 0;
if (netif_queue_stopped(_dev))
netif_wake_queue(_dev);
} else {
__netif_tx_unlock(txq);
goto resched;
}
__netif_tx_unlock(txq);
} else {
resched:
dp->tasklet_pending = 1;
tasklet_schedule(&dp->ifb_tasklet);
}
}
static struct rtnl_link_stats64 *ifb_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct ifb_private *dp = netdev_priv(dev);
unsigned int start;
do {
start = u64_stats_fetch_begin_bh(&dp->rsync);
stats->rx_packets = dp->rx_packets;
stats->rx_bytes = dp->rx_bytes;
} while (u64_stats_fetch_retry_bh(&dp->rsync, start));
do {
start = u64_stats_fetch_begin_bh(&dp->tsync);
stats->tx_packets = dp->tx_packets;
stats->tx_bytes = dp->tx_bytes;
} while (u64_stats_fetch_retry_bh(&dp->tsync, start));
stats->rx_dropped = dev->stats.rx_dropped;
stats->tx_dropped = dev->stats.tx_dropped;
return stats;
}
static void ifb_setup(struct net_device *dev)
{
dev->destructor = free_netdev;
dev->netdev_ops = &ifb_netdev_ops;
ether_setup(dev);
dev->tx_queue_len = TX_Q_LIMIT;
dev->features |= IFB_FEATURES;
dev->vlan_features |= IFB_FEATURES;
dev->flags |= IFF_NOARP;
dev->flags &= ~IFF_MULTICAST;
dev->priv_flags &= ~(IFF_XMIT_DST_RELEASE | IFF_TX_SKB_SHARING);
eth_hw_addr_random(dev);
}
static netdev_tx_t ifb_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ifb_private *dp = netdev_priv(dev);
u32 from = G_TC_FROM(skb->tc_verd);
u64_stats_update_begin(&dp->rsync);
dp->rx_packets++;
dp->rx_bytes += skb->len;
u64_stats_update_end(&dp->rsync);
if (!(from & (AT_INGRESS|AT_EGRESS)) || !skb->skb_iif) {
dev_kfree_skb(skb);
dev->stats.rx_dropped++;
return NETDEV_TX_OK;
}
if (skb_queue_len(&dp->rq) >= dev->tx_queue_len) {
netif_stop_queue(dev);
}
__skb_queue_tail(&dp->rq, skb);
if (!dp->tasklet_pending) {
dp->tasklet_pending = 1;
tasklet_schedule(&dp->ifb_tasklet);
}
return NETDEV_TX_OK;
}
static int ifb_close(struct net_device *dev)
{
struct ifb_private *dp = netdev_priv(dev);
tasklet_kill(&dp->ifb_tasklet);
netif_stop_queue(dev);
__skb_queue_purge(&dp->rq);
__skb_queue_purge(&dp->tq);
return 0;
}
static int ifb_open(struct net_device *dev)
{
struct ifb_private *dp = netdev_priv(dev);
tasklet_init(&dp->ifb_tasklet, ri_tasklet, (unsigned long)dev);
__skb_queue_head_init(&dp->rq);
__skb_queue_head_init(&dp->tq);
netif_start_queue(dev);
return 0;
}
static int ifb_validate(struct nlattr *tb[], struct nlattr *data[])
{
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
return 0;
}
static int __init ifb_init_one(int index)
{
struct net_device *dev_ifb;
int err;
dev_ifb = alloc_netdev(sizeof(struct ifb_private),
"ifb%d", ifb_setup);
if (!dev_ifb)
return -ENOMEM;
dev_ifb->rtnl_link_ops = &ifb_link_ops;
err = register_netdevice(dev_ifb);
if (err < 0)
goto err;
return 0;
err:
free_netdev(dev_ifb);
return err;
}
static int __init ifb_init_module(void)
{
int i, err;
rtnl_lock();
err = __rtnl_link_register(&ifb_link_ops);
for (i = 0; i < numifbs && !err; i++)
err = ifb_init_one(i);
if (err)
__rtnl_link_unregister(&ifb_link_ops);
rtnl_unlock();
return err;
}
static void __exit ifb_cleanup_module(void)
{
rtnl_link_unregister(&ifb_link_ops);
}
