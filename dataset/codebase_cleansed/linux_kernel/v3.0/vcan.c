static void vcan_rx(struct sk_buff *skb, struct net_device *dev)
{
struct can_frame *cf = (struct can_frame *)skb->data;
struct net_device_stats *stats = &dev->stats;
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
skb->protocol = htons(ETH_P_CAN);
skb->pkt_type = PACKET_BROADCAST;
skb->dev = dev;
skb->ip_summed = CHECKSUM_UNNECESSARY;
netif_rx_ni(skb);
}
static netdev_tx_t vcan_tx(struct sk_buff *skb, struct net_device *dev)
{
struct can_frame *cf = (struct can_frame *)skb->data;
struct net_device_stats *stats = &dev->stats;
int loop;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
stats->tx_packets++;
stats->tx_bytes += cf->can_dlc;
loop = skb->pkt_type == PACKET_LOOPBACK;
if (!echo) {
if (loop) {
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
}
kfree_skb(skb);
return NETDEV_TX_OK;
}
if (loop) {
struct sock *srcsk = skb->sk;
skb = skb_share_check(skb, GFP_ATOMIC);
if (!skb)
return NETDEV_TX_OK;
skb->sk = srcsk;
vcan_rx(skb, dev);
} else {
kfree_skb(skb);
}
return NETDEV_TX_OK;
}
static void vcan_setup(struct net_device *dev)
{
dev->type = ARPHRD_CAN;
dev->mtu = sizeof(struct can_frame);
dev->hard_header_len = 0;
dev->addr_len = 0;
dev->tx_queue_len = 0;
dev->flags = IFF_NOARP;
if (echo)
dev->flags |= IFF_ECHO;
dev->netdev_ops = &vcan_netdev_ops;
dev->destructor = free_netdev;
}
static __init int vcan_init_module(void)
{
printk(banner);
if (echo)
printk(KERN_INFO "vcan: enabled echo on driver level.\n");
return rtnl_link_register(&vcan_link_ops);
}
static __exit void vcan_cleanup_module(void)
{
rtnl_link_unregister(&vcan_link_ops);
}
