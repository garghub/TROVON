static struct internal_dev *internal_dev_priv(struct net_device *netdev)
{
return netdev_priv(netdev);
}
static struct rtnl_link_stats64 *internal_dev_get_stats(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct vport *vport = ovs_internal_dev_get_vport(netdev);
struct ovs_vport_stats vport_stats;
ovs_vport_get_stats(vport, &vport_stats);
stats->rx_packets = vport_stats.tx_packets;
stats->tx_packets = vport_stats.rx_packets;
stats->rx_bytes = vport_stats.tx_bytes;
stats->tx_bytes = vport_stats.rx_bytes;
stats->rx_errors = vport_stats.tx_errors;
stats->tx_errors = vport_stats.rx_errors;
stats->rx_dropped = vport_stats.tx_dropped;
stats->tx_dropped = vport_stats.rx_dropped;
return stats;
}
static int internal_dev_xmit(struct sk_buff *skb, struct net_device *netdev)
{
rcu_read_lock();
ovs_vport_receive(internal_dev_priv(netdev)->vport, skb, NULL);
rcu_read_unlock();
return 0;
}
static int internal_dev_open(struct net_device *netdev)
{
netif_start_queue(netdev);
return 0;
}
static int internal_dev_stop(struct net_device *netdev)
{
netif_stop_queue(netdev);
return 0;
}
static void internal_dev_getinfo(struct net_device *netdev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "openvswitch", sizeof(info->driver));
}
static int internal_dev_change_mtu(struct net_device *netdev, int new_mtu)
{
if (new_mtu < 68)
return -EINVAL;
netdev->mtu = new_mtu;
return 0;
}
static void internal_dev_destructor(struct net_device *dev)
{
struct vport *vport = ovs_internal_dev_get_vport(dev);
ovs_vport_free(vport);
free_netdev(dev);
}
static void do_setup(struct net_device *netdev)
{
ether_setup(netdev);
netdev->netdev_ops = &internal_dev_netdev_ops;
netdev->priv_flags &= ~IFF_TX_SKB_SHARING;
netdev->priv_flags |= IFF_LIVE_ADDR_CHANGE;
netdev->destructor = internal_dev_destructor;
SET_ETHTOOL_OPS(netdev, &internal_dev_ethtool_ops);
netdev->tx_queue_len = 0;
netdev->features = NETIF_F_LLTX | NETIF_F_SG | NETIF_F_FRAGLIST |
NETIF_F_HIGHDMA | NETIF_F_HW_CSUM | NETIF_F_TSO;
netdev->vlan_features = netdev->features;
netdev->features |= NETIF_F_HW_VLAN_CTAG_TX;
netdev->hw_features = netdev->features & ~NETIF_F_LLTX;
eth_hw_addr_random(netdev);
}
static struct vport *internal_dev_create(const struct vport_parms *parms)
{
struct vport *vport;
struct netdev_vport *netdev_vport;
struct internal_dev *internal_dev;
int err;
vport = ovs_vport_alloc(sizeof(struct netdev_vport),
&ovs_internal_vport_ops, parms);
if (IS_ERR(vport)) {
err = PTR_ERR(vport);
goto error;
}
netdev_vport = netdev_vport_priv(vport);
netdev_vport->dev = alloc_netdev(sizeof(struct internal_dev),
parms->name, do_setup);
if (!netdev_vport->dev) {
err = -ENOMEM;
goto error_free_vport;
}
dev_net_set(netdev_vport->dev, ovs_dp_get_net(vport->dp));
internal_dev = internal_dev_priv(netdev_vport->dev);
internal_dev->vport = vport;
if (vport->port_no == OVSP_LOCAL)
netdev_vport->dev->features |= NETIF_F_NETNS_LOCAL;
rtnl_lock();
err = register_netdevice(netdev_vport->dev);
if (err)
goto error_free_netdev;
dev_set_promiscuity(netdev_vport->dev, 1);
rtnl_unlock();
netif_start_queue(netdev_vport->dev);
return vport;
error_free_netdev:
rtnl_unlock();
free_netdev(netdev_vport->dev);
error_free_vport:
ovs_vport_free(vport);
error:
return ERR_PTR(err);
}
static void internal_dev_destroy(struct vport *vport)
{
struct netdev_vport *netdev_vport = netdev_vport_priv(vport);
netif_stop_queue(netdev_vport->dev);
rtnl_lock();
dev_set_promiscuity(netdev_vport->dev, -1);
unregister_netdevice(netdev_vport->dev);
rtnl_unlock();
}
static int internal_dev_recv(struct vport *vport, struct sk_buff *skb)
{
struct net_device *netdev = netdev_vport_priv(vport)->dev;
int len;
len = skb->len;
skb_dst_drop(skb);
nf_reset(skb);
secpath_reset(skb);
skb->dev = netdev;
skb->pkt_type = PACKET_HOST;
skb->protocol = eth_type_trans(skb, netdev);
skb_postpull_rcsum(skb, eth_hdr(skb), ETH_HLEN);
netif_rx(skb);
return len;
}
int ovs_is_internal_dev(const struct net_device *netdev)
{
return netdev->netdev_ops == &internal_dev_netdev_ops;
}
struct vport *ovs_internal_dev_get_vport(struct net_device *netdev)
{
if (!ovs_is_internal_dev(netdev))
return NULL;
return internal_dev_priv(netdev)->vport;
}
