static void vnet_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_MODULE_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
}
static u32 vnet_get_msglevel(struct net_device *dev)
{
struct vnet *vp = netdev_priv(dev);
return vp->msg_enable;
}
static void vnet_set_msglevel(struct net_device *dev, u32 value)
{
struct vnet *vp = netdev_priv(dev);
vp->msg_enable = value;
}
static int vnet_get_sset_count(struct net_device *dev, int sset)
{
struct vnet *vp = (struct vnet *)netdev_priv(dev);
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(ethtool_stats_keys)
+ (NUM_VNET_PORT_STATS * vp->nports);
default:
return -EOPNOTSUPP;
}
}
static void vnet_get_strings(struct net_device *dev, u32 stringset, u8 *buf)
{
struct vnet *vp = (struct vnet *)netdev_priv(dev);
struct vnet_port *port;
char *p = (char *)buf;
switch (stringset) {
case ETH_SS_STATS:
memcpy(buf, &ethtool_stats_keys, sizeof(ethtool_stats_keys));
p += sizeof(ethtool_stats_keys);
rcu_read_lock();
list_for_each_entry_rcu(port, &vp->port_list, list) {
snprintf(p, ETH_GSTRING_LEN, "p%u.%s-%pM",
port->q_index, port->switch_port ? "s" : "q",
port->raddr);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "p%u.rx_packets",
port->q_index);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "p%u.tx_packets",
port->q_index);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "p%u.rx_bytes",
port->q_index);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "p%u.tx_bytes",
port->q_index);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "p%u.event_up",
port->q_index);
p += ETH_GSTRING_LEN;
snprintf(p, ETH_GSTRING_LEN, "p%u.event_reset",
port->q_index);
p += ETH_GSTRING_LEN;
}
rcu_read_unlock();
break;
default:
WARN_ON(1);
break;
}
}
static void vnet_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *estats, u64 *data)
{
struct vnet *vp = (struct vnet *)netdev_priv(dev);
struct vnet_port *port;
int i = 0;
data[i++] = dev->stats.rx_packets;
data[i++] = dev->stats.tx_packets;
data[i++] = dev->stats.rx_bytes;
data[i++] = dev->stats.tx_bytes;
data[i++] = dev->stats.rx_errors;
data[i++] = dev->stats.tx_errors;
data[i++] = dev->stats.rx_dropped;
data[i++] = dev->stats.tx_dropped;
data[i++] = dev->stats.multicast;
data[i++] = dev->stats.rx_length_errors;
data[i++] = dev->stats.rx_frame_errors;
data[i++] = dev->stats.rx_missed_errors;
data[i++] = dev->stats.tx_carrier_errors;
data[i++] = vp->nports;
rcu_read_lock();
list_for_each_entry_rcu(port, &vp->port_list, list) {
data[i++] = port->q_index;
data[i++] = port->stats.rx_packets;
data[i++] = port->stats.tx_packets;
data[i++] = port->stats.rx_bytes;
data[i++] = port->stats.tx_bytes;
data[i++] = port->stats.event_up;
data[i++] = port->stats.event_reset;
}
rcu_read_unlock();
}
static struct vnet_port *__tx_port_find(struct vnet *vp, struct sk_buff *skb)
{
unsigned int hash = vnet_hashfn(skb->data);
struct hlist_head *hp = &vp->port_hash[hash];
struct vnet_port *port;
hlist_for_each_entry_rcu(port, hp, hash) {
if (!sunvnet_port_is_up_common(port))
continue;
if (ether_addr_equal(port->raddr, skb->data))
return port;
}
list_for_each_entry_rcu(port, &vp->port_list, list) {
if (!port->switch_port)
continue;
if (!sunvnet_port_is_up_common(port))
continue;
return port;
}
return NULL;
}
static struct vnet_port *vnet_tx_port_find(struct sk_buff *skb,
struct net_device *dev)
{
struct vnet *vp = netdev_priv(dev);
return __tx_port_find(vp, skb);
}
static u16 vnet_select_queue(struct net_device *dev, struct sk_buff *skb,
void *accel_priv, select_queue_fallback_t fallback)
{
struct vnet *vp = netdev_priv(dev);
struct vnet_port *port = __tx_port_find(vp, skb);
if (!port)
return 0;
return port->q_index;
}
static int vnet_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
return sunvnet_start_xmit_common(skb, dev, vnet_tx_port_find);
}
static void vnet_set_rx_mode(struct net_device *dev)
{
struct vnet *vp = netdev_priv(dev);
return sunvnet_set_rx_mode_common(dev, vp);
}
static void vnet_poll_controller(struct net_device *dev)
{
struct vnet *vp = netdev_priv(dev);
return sunvnet_poll_controller_common(dev, vp);
}
static struct vnet *vnet_new(const u64 *local_mac,
struct vio_dev *vdev)
{
struct net_device *dev;
struct vnet *vp;
int err, i;
dev = alloc_etherdev_mqs(sizeof(*vp), VNET_MAX_TXQS, 1);
if (!dev)
return ERR_PTR(-ENOMEM);
dev->needed_headroom = VNET_PACKET_SKIP + 8;
dev->needed_tailroom = 8;
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = (*local_mac >> (5 - i) * 8) & 0xff;
vp = netdev_priv(dev);
spin_lock_init(&vp->lock);
vp->dev = dev;
INIT_LIST_HEAD(&vp->port_list);
for (i = 0; i < VNET_PORT_HASH_SIZE; i++)
INIT_HLIST_HEAD(&vp->port_hash[i]);
INIT_LIST_HEAD(&vp->list);
vp->local_mac = *local_mac;
dev->netdev_ops = &vnet_ops;
dev->ethtool_ops = &vnet_ethtool_ops;
dev->watchdog_timeo = VNET_TX_TIMEOUT;
dev->hw_features = NETIF_F_TSO | NETIF_F_GSO | NETIF_F_GSO_SOFTWARE |
NETIF_F_HW_CSUM | NETIF_F_SG;
dev->features = dev->hw_features;
dev->min_mtu = ETH_MIN_MTU;
dev->max_mtu = VNET_MAX_MTU;
SET_NETDEV_DEV(dev, &vdev->dev);
err = register_netdev(dev);
if (err) {
pr_err("Cannot register net device, aborting\n");
goto err_out_free_dev;
}
netdev_info(dev, "Sun LDOM vnet %pM\n", dev->dev_addr);
list_add(&vp->list, &vnet_list);
return vp;
err_out_free_dev:
free_netdev(dev);
return ERR_PTR(err);
}
static struct vnet *vnet_find_or_create(const u64 *local_mac,
struct vio_dev *vdev)
{
struct vnet *iter, *vp;
mutex_lock(&vnet_list_mutex);
vp = NULL;
list_for_each_entry(iter, &vnet_list, list) {
if (iter->local_mac == *local_mac) {
vp = iter;
break;
}
}
if (!vp)
vp = vnet_new(local_mac, vdev);
mutex_unlock(&vnet_list_mutex);
return vp;
}
static void vnet_cleanup(void)
{
struct vnet *vp;
struct net_device *dev;
mutex_lock(&vnet_list_mutex);
while (!list_empty(&vnet_list)) {
vp = list_first_entry(&vnet_list, struct vnet, list);
list_del(&vp->list);
dev = vp->dev;
BUG_ON(!list_empty(&vp->port_list));
unregister_netdev(dev);
free_netdev(dev);
}
mutex_unlock(&vnet_list_mutex);
}
static struct vnet *vnet_find_parent(struct mdesc_handle *hp,
u64 port_node,
struct vio_dev *vdev)
{
const u64 *local_mac = NULL;
u64 a;
mdesc_for_each_arc(a, hp, port_node, MDESC_ARC_TYPE_BACK) {
u64 target = mdesc_arc_target(hp, a);
const char *name;
name = mdesc_get_property(hp, target, "name", NULL);
if (!name || strcmp(name, "network"))
continue;
local_mac = mdesc_get_property(hp, target,
local_mac_prop, NULL);
if (local_mac)
break;
}
if (!local_mac)
return ERR_PTR(-ENODEV);
return vnet_find_or_create(local_mac, vdev);
}
static int vnet_port_probe(struct vio_dev *vdev, const struct vio_device_id *id)
{
struct mdesc_handle *hp;
struct vnet_port *port;
unsigned long flags;
struct vnet *vp;
const u64 *rmac;
int len, i, err, switch_port;
hp = mdesc_grab();
vp = vnet_find_parent(hp, vdev->mp, vdev);
if (IS_ERR(vp)) {
pr_err("Cannot find port parent vnet\n");
err = PTR_ERR(vp);
goto err_out_put_mdesc;
}
rmac = mdesc_get_property(hp, vdev->mp, remote_macaddr_prop, &len);
err = -ENODEV;
if (!rmac) {
pr_err("Port lacks %s property\n", remote_macaddr_prop);
goto err_out_put_mdesc;
}
port = kzalloc(sizeof(*port), GFP_KERNEL);
err = -ENOMEM;
if (!port)
goto err_out_put_mdesc;
for (i = 0; i < ETH_ALEN; i++)
port->raddr[i] = (*rmac >> (5 - i) * 8) & 0xff;
port->vp = vp;
err = vio_driver_init(&port->vio, vdev, VDEV_NETWORK,
vnet_versions, ARRAY_SIZE(vnet_versions),
&vnet_vio_ops, vp->dev->name);
if (err)
goto err_out_free_port;
err = vio_ldc_alloc(&port->vio, &vnet_ldc_cfg, port);
if (err)
goto err_out_free_port;
netif_napi_add(port->vp->dev, &port->napi, sunvnet_poll_common,
NAPI_POLL_WEIGHT);
INIT_HLIST_NODE(&port->hash);
INIT_LIST_HEAD(&port->list);
switch_port = 0;
if (mdesc_get_property(hp, vdev->mp, "switch-port", NULL))
switch_port = 1;
port->switch_port = switch_port;
port->tso = true;
port->tsolen = 0;
spin_lock_irqsave(&vp->lock, flags);
if (switch_port)
list_add_rcu(&port->list, &vp->port_list);
else
list_add_tail_rcu(&port->list, &vp->port_list);
hlist_add_head_rcu(&port->hash,
&vp->port_hash[vnet_hashfn(port->raddr)]);
sunvnet_port_add_txq_common(port);
spin_unlock_irqrestore(&vp->lock, flags);
dev_set_drvdata(&vdev->dev, port);
pr_info("%s: PORT ( remote-mac %pM%s )\n",
vp->dev->name, port->raddr, switch_port ? " switch-port" : "");
setup_timer(&port->clean_timer, sunvnet_clean_timer_expire_common,
(unsigned long)port);
napi_enable(&port->napi);
vio_port_up(&port->vio);
mdesc_release(hp);
return 0;
err_out_free_port:
kfree(port);
err_out_put_mdesc:
mdesc_release(hp);
return err;
}
static int vnet_port_remove(struct vio_dev *vdev)
{
struct vnet_port *port = dev_get_drvdata(&vdev->dev);
if (port) {
del_timer_sync(&port->vio.timer);
napi_disable(&port->napi);
list_del_rcu(&port->list);
hlist_del_rcu(&port->hash);
synchronize_rcu();
del_timer_sync(&port->clean_timer);
sunvnet_port_rm_txq_common(port);
netif_napi_del(&port->napi);
sunvnet_port_free_tx_bufs_common(port);
vio_ldc_free(&port->vio);
dev_set_drvdata(&vdev->dev, NULL);
kfree(port);
}
return 0;
}
static int __init vnet_init(void)
{
pr_info("%s\n", version);
return vio_register_driver(&vnet_port_driver);
}
static void __exit vnet_exit(void)
{
vio_unregister_driver(&vnet_port_driver);
vnet_cleanup();
}
