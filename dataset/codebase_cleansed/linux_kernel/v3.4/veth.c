static int veth_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
cmd->supported = 0;
cmd->advertising = 0;
ethtool_cmd_speed_set(cmd, SPEED_10000);
cmd->duplex = DUPLEX_FULL;
cmd->port = PORT_TP;
cmd->phy_address = 0;
cmd->transceiver = XCVR_INTERNAL;
cmd->autoneg = AUTONEG_DISABLE;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static void veth_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
}
static void veth_get_strings(struct net_device *dev, u32 stringset, u8 *buf)
{
switch(stringset) {
case ETH_SS_STATS:
memcpy(buf, &ethtool_stats_keys, sizeof(ethtool_stats_keys));
break;
}
}
static int veth_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(ethtool_stats_keys);
default:
return -EOPNOTSUPP;
}
}
static void veth_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct veth_priv *priv;
priv = netdev_priv(dev);
data[0] = priv->peer->ifindex;
}
static netdev_tx_t veth_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct net_device *rcv = NULL;
struct veth_priv *priv, *rcv_priv;
struct veth_net_stats *stats, *rcv_stats;
int length;
priv = netdev_priv(dev);
rcv = priv->peer;
rcv_priv = netdev_priv(rcv);
stats = this_cpu_ptr(priv->stats);
rcv_stats = this_cpu_ptr(rcv_priv->stats);
if (skb->ip_summed == CHECKSUM_NONE &&
rcv->features & NETIF_F_RXCSUM)
skb->ip_summed = CHECKSUM_UNNECESSARY;
length = skb->len;
if (dev_forward_skb(rcv, skb) != NET_RX_SUCCESS)
goto rx_drop;
u64_stats_update_begin(&stats->syncp);
stats->tx_bytes += length;
stats->tx_packets++;
u64_stats_update_end(&stats->syncp);
u64_stats_update_begin(&rcv_stats->syncp);
rcv_stats->rx_bytes += length;
rcv_stats->rx_packets++;
u64_stats_update_end(&rcv_stats->syncp);
return NETDEV_TX_OK;
rx_drop:
u64_stats_update_begin(&rcv_stats->syncp);
rcv_stats->rx_dropped++;
u64_stats_update_end(&rcv_stats->syncp);
return NETDEV_TX_OK;
}
static struct rtnl_link_stats64 *veth_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *tot)
{
struct veth_priv *priv = netdev_priv(dev);
int cpu;
for_each_possible_cpu(cpu) {
struct veth_net_stats *stats = per_cpu_ptr(priv->stats, cpu);
u64 rx_packets, rx_bytes, rx_dropped;
u64 tx_packets, tx_bytes;
unsigned int start;
do {
start = u64_stats_fetch_begin_bh(&stats->syncp);
rx_packets = stats->rx_packets;
tx_packets = stats->tx_packets;
rx_bytes = stats->rx_bytes;
tx_bytes = stats->tx_bytes;
rx_dropped = stats->rx_dropped;
} while (u64_stats_fetch_retry_bh(&stats->syncp, start));
tot->rx_packets += rx_packets;
tot->tx_packets += tx_packets;
tot->rx_bytes += rx_bytes;
tot->tx_bytes += tx_bytes;
tot->rx_dropped += rx_dropped;
}
return tot;
}
static int veth_open(struct net_device *dev)
{
struct veth_priv *priv;
priv = netdev_priv(dev);
if (priv->peer == NULL)
return -ENOTCONN;
if (priv->peer->flags & IFF_UP) {
netif_carrier_on(dev);
netif_carrier_on(priv->peer);
}
return 0;
}
static int veth_close(struct net_device *dev)
{
struct veth_priv *priv = netdev_priv(dev);
netif_carrier_off(dev);
netif_carrier_off(priv->peer);
return 0;
}
static int is_valid_veth_mtu(int new_mtu)
{
return new_mtu >= MIN_MTU && new_mtu <= MAX_MTU;
}
static int veth_change_mtu(struct net_device *dev, int new_mtu)
{
if (!is_valid_veth_mtu(new_mtu))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static int veth_dev_init(struct net_device *dev)
{
struct veth_net_stats __percpu *stats;
struct veth_priv *priv;
stats = alloc_percpu(struct veth_net_stats);
if (stats == NULL)
return -ENOMEM;
priv = netdev_priv(dev);
priv->stats = stats;
return 0;
}
static void veth_dev_free(struct net_device *dev)
{
struct veth_priv *priv;
priv = netdev_priv(dev);
free_percpu(priv->stats);
free_netdev(dev);
}
static void veth_setup(struct net_device *dev)
{
ether_setup(dev);
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
dev->netdev_ops = &veth_netdev_ops;
dev->ethtool_ops = &veth_ethtool_ops;
dev->features |= NETIF_F_LLTX;
dev->destructor = veth_dev_free;
dev->hw_features = NETIF_F_HW_CSUM | NETIF_F_SG | NETIF_F_RXCSUM;
}
static int veth_validate(struct nlattr *tb[], struct nlattr *data[])
{
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
if (tb[IFLA_MTU]) {
if (!is_valid_veth_mtu(nla_get_u32(tb[IFLA_MTU])))
return -EINVAL;
}
return 0;
}
static int veth_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
int err;
struct net_device *peer;
struct veth_priv *priv;
char ifname[IFNAMSIZ];
struct nlattr *peer_tb[IFLA_MAX + 1], **tbp;
struct ifinfomsg *ifmp;
struct net *net;
if (data != NULL && data[VETH_INFO_PEER] != NULL) {
struct nlattr *nla_peer;
nla_peer = data[VETH_INFO_PEER];
ifmp = nla_data(nla_peer);
err = nla_parse(peer_tb, IFLA_MAX,
nla_data(nla_peer) + sizeof(struct ifinfomsg),
nla_len(nla_peer) - sizeof(struct ifinfomsg),
ifla_policy);
if (err < 0)
return err;
err = veth_validate(peer_tb, NULL);
if (err < 0)
return err;
tbp = peer_tb;
} else {
ifmp = NULL;
tbp = tb;
}
if (tbp[IFLA_IFNAME])
nla_strlcpy(ifname, tbp[IFLA_IFNAME], IFNAMSIZ);
else
snprintf(ifname, IFNAMSIZ, DRV_NAME "%%d");
net = rtnl_link_get_net(src_net, tbp);
if (IS_ERR(net))
return PTR_ERR(net);
peer = rtnl_create_link(src_net, net, ifname, &veth_link_ops, tbp);
if (IS_ERR(peer)) {
put_net(net);
return PTR_ERR(peer);
}
if (tbp[IFLA_ADDRESS] == NULL)
eth_hw_addr_random(peer);
err = register_netdevice(peer);
put_net(net);
net = NULL;
if (err < 0)
goto err_register_peer;
netif_carrier_off(peer);
err = rtnl_configure_link(peer, ifmp);
if (err < 0)
goto err_configure_peer;
if (tb[IFLA_ADDRESS] == NULL)
eth_hw_addr_random(dev);
if (tb[IFLA_IFNAME])
nla_strlcpy(dev->name, tb[IFLA_IFNAME], IFNAMSIZ);
else
snprintf(dev->name, IFNAMSIZ, DRV_NAME "%%d");
if (strchr(dev->name, '%')) {
err = dev_alloc_name(dev, dev->name);
if (err < 0)
goto err_alloc_name;
}
err = register_netdevice(dev);
if (err < 0)
goto err_register_dev;
netif_carrier_off(dev);
priv = netdev_priv(dev);
priv->peer = peer;
priv = netdev_priv(peer);
priv->peer = dev;
return 0;
err_register_dev:
err_alloc_name:
err_configure_peer:
unregister_netdevice(peer);
return err;
err_register_peer:
free_netdev(peer);
return err;
}
static void veth_dellink(struct net_device *dev, struct list_head *head)
{
struct veth_priv *priv;
struct net_device *peer;
priv = netdev_priv(dev);
peer = priv->peer;
unregister_netdevice_queue(dev, head);
unregister_netdevice_queue(peer, head);
}
static __init int veth_init(void)
{
return rtnl_link_register(&veth_link_ops);
}
static __exit void veth_exit(void)
{
rtnl_link_unregister(&veth_link_ops);
}
