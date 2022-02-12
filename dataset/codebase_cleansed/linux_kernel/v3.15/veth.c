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
struct veth_priv *priv = netdev_priv(dev);
struct net_device *peer = rtnl_dereference(priv->peer);
data[0] = peer ? peer->ifindex : 0;
}
static netdev_tx_t veth_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct veth_priv *priv = netdev_priv(dev);
struct net_device *rcv;
int length = skb->len;
rcu_read_lock();
rcv = rcu_dereference(priv->peer);
if (unlikely(!rcv)) {
kfree_skb(skb);
goto drop;
}
if (skb->ip_summed == CHECKSUM_NONE &&
rcv->features & NETIF_F_RXCSUM)
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (likely(dev_forward_skb(rcv, skb) == NET_RX_SUCCESS)) {
struct pcpu_vstats *stats = this_cpu_ptr(dev->vstats);
u64_stats_update_begin(&stats->syncp);
stats->bytes += length;
stats->packets++;
u64_stats_update_end(&stats->syncp);
} else {
drop:
atomic64_inc(&priv->dropped);
}
rcu_read_unlock();
return NETDEV_TX_OK;
}
static u64 veth_stats_one(struct pcpu_vstats *result, struct net_device *dev)
{
struct veth_priv *priv = netdev_priv(dev);
int cpu;
result->packets = 0;
result->bytes = 0;
for_each_possible_cpu(cpu) {
struct pcpu_vstats *stats = per_cpu_ptr(dev->vstats, cpu);
u64 packets, bytes;
unsigned int start;
do {
start = u64_stats_fetch_begin_irq(&stats->syncp);
packets = stats->packets;
bytes = stats->bytes;
} while (u64_stats_fetch_retry_irq(&stats->syncp, start));
result->packets += packets;
result->bytes += bytes;
}
return atomic64_read(&priv->dropped);
}
static struct rtnl_link_stats64 *veth_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *tot)
{
struct veth_priv *priv = netdev_priv(dev);
struct net_device *peer;
struct pcpu_vstats one;
tot->tx_dropped = veth_stats_one(&one, dev);
tot->tx_bytes = one.bytes;
tot->tx_packets = one.packets;
rcu_read_lock();
peer = rcu_dereference(priv->peer);
if (peer) {
tot->rx_dropped = veth_stats_one(&one, peer);
tot->rx_bytes = one.bytes;
tot->rx_packets = one.packets;
}
rcu_read_unlock();
return tot;
}
static void veth_set_multicast_list(struct net_device *dev)
{
}
static int veth_open(struct net_device *dev)
{
struct veth_priv *priv = netdev_priv(dev);
struct net_device *peer = rtnl_dereference(priv->peer);
if (!peer)
return -ENOTCONN;
if (peer->flags & IFF_UP) {
netif_carrier_on(dev);
netif_carrier_on(peer);
}
return 0;
}
static int veth_close(struct net_device *dev)
{
struct veth_priv *priv = netdev_priv(dev);
struct net_device *peer = rtnl_dereference(priv->peer);
netif_carrier_off(dev);
if (peer)
netif_carrier_off(peer);
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
dev->vstats = netdev_alloc_pcpu_stats(struct pcpu_vstats);
if (!dev->vstats)
return -ENOMEM;
return 0;
}
static void veth_dev_free(struct net_device *dev)
{
free_percpu(dev->vstats);
free_netdev(dev);
}
static void veth_setup(struct net_device *dev)
{
ether_setup(dev);
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
dev->priv_flags |= IFF_LIVE_ADDR_CHANGE;
dev->netdev_ops = &veth_netdev_ops;
dev->ethtool_ops = &veth_ethtool_ops;
dev->features |= NETIF_F_LLTX;
dev->features |= VETH_FEATURES;
dev->vlan_features = dev->features &
~(NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_STAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_STAG_RX);
dev->destructor = veth_dev_free;
dev->hw_features = VETH_FEATURES;
dev->hw_enc_features = VETH_FEATURES;
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
err = rtnl_nla_parse_ifla(peer_tb,
nla_data(nla_peer) + sizeof(struct ifinfomsg),
nla_len(nla_peer) - sizeof(struct ifinfomsg));
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
peer = rtnl_create_link(net, ifname, &veth_link_ops, tbp);
if (IS_ERR(peer)) {
put_net(net);
return PTR_ERR(peer);
}
if (tbp[IFLA_ADDRESS] == NULL)
eth_hw_addr_random(peer);
if (ifmp && (dev->ifindex != 0))
peer->ifindex = ifmp->ifi_index;
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
err = register_netdevice(dev);
if (err < 0)
goto err_register_dev;
netif_carrier_off(dev);
priv = netdev_priv(dev);
rcu_assign_pointer(priv->peer, peer);
priv = netdev_priv(peer);
rcu_assign_pointer(priv->peer, dev);
return 0;
err_register_dev:
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
peer = rtnl_dereference(priv->peer);
RCU_INIT_POINTER(priv->peer, NULL);
unregister_netdevice_queue(dev, head);
if (peer) {
priv = netdev_priv(peer);
RCU_INIT_POINTER(priv->peer, NULL);
unregister_netdevice_queue(peer, head);
}
}
static __init int veth_init(void)
{
return rtnl_link_register(&veth_link_ops);
}
static __exit void veth_exit(void)
{
rtnl_link_unregister(&veth_link_ops);
}
