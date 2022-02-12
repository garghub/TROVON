void rmnet_vnd_rx_fixup(struct sk_buff *skb, struct net_device *dev)
{
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
}
void rmnet_vnd_tx_fixup(struct sk_buff *skb, struct net_device *dev)
{
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
}
static netdev_tx_t rmnet_vnd_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct rmnet_priv *priv;
priv = netdev_priv(dev);
if (priv->local_ep.egress_dev) {
rmnet_egress_handler(skb, &priv->local_ep);
} else {
dev->stats.tx_dropped++;
kfree_skb(skb);
}
return NETDEV_TX_OK;
}
static int rmnet_vnd_change_mtu(struct net_device *rmnet_dev, int new_mtu)
{
if (new_mtu < 0 || new_mtu > RMNET_MAX_PACKET_SIZE)
return -EINVAL;
rmnet_dev->mtu = new_mtu;
return 0;
}
static int rmnet_vnd_get_iflink(const struct net_device *dev)
{
struct rmnet_priv *priv = netdev_priv(dev);
return priv->real_dev->ifindex;
}
void rmnet_vnd_setup(struct net_device *rmnet_dev)
{
rmnet_dev->netdev_ops = &rmnet_vnd_ops;
rmnet_dev->mtu = RMNET_DFLT_PACKET_SIZE;
rmnet_dev->needed_headroom = RMNET_NEEDED_HEADROOM;
random_ether_addr(rmnet_dev->dev_addr);
rmnet_dev->tx_queue_len = RMNET_TX_QUEUE_LEN;
rmnet_dev->header_ops = NULL;
rmnet_dev->type = ARPHRD_RAWIP;
rmnet_dev->hard_header_len = 0;
rmnet_dev->flags &= ~(IFF_BROADCAST | IFF_MULTICAST);
rmnet_dev->needs_free_netdev = true;
}
int rmnet_vnd_newlink(u8 id, struct net_device *rmnet_dev,
struct rmnet_port *port,
struct net_device *real_dev)
{
struct rmnet_priv *priv;
int rc;
if (port->rmnet_devices[id])
return -EINVAL;
rc = register_netdevice(rmnet_dev);
if (!rc) {
port->rmnet_devices[id] = rmnet_dev;
port->nr_rmnet_devs++;
rmnet_dev->rtnl_link_ops = &rmnet_link_ops;
priv = netdev_priv(rmnet_dev);
priv->mux_id = id;
priv->real_dev = real_dev;
netdev_dbg(rmnet_dev, "rmnet dev created\n");
}
return rc;
}
int rmnet_vnd_dellink(u8 id, struct rmnet_port *port)
{
if (id >= RMNET_MAX_LOGICAL_EP || !port->rmnet_devices[id])
return -EINVAL;
port->rmnet_devices[id] = NULL;
port->nr_rmnet_devs--;
return 0;
}
u8 rmnet_vnd_get_mux(struct net_device *rmnet_dev)
{
struct rmnet_priv *priv;
priv = netdev_priv(rmnet_dev);
return priv->mux_id;
}
struct rmnet_endpoint *rmnet_vnd_get_endpoint(struct net_device *rmnet_dev)
{
struct rmnet_priv *priv;
if (!rmnet_dev)
return NULL;
priv = netdev_priv(rmnet_dev);
return &priv->local_ep;
}
int rmnet_vnd_do_flow_control(struct net_device *rmnet_dev, int enable)
{
netdev_dbg(rmnet_dev, "Setting VND TX queue state to %d\n", enable);
if (unlikely(enable))
netif_wake_queue(rmnet_dev);
else
netif_stop_queue(rmnet_dev);
return 0;
}
