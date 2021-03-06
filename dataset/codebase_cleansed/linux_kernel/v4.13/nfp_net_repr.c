static void
nfp_repr_inc_tx_stats(struct net_device *netdev, unsigned int len,
int tx_status)
{
struct nfp_repr *repr = netdev_priv(netdev);
struct nfp_repr_pcpu_stats *stats;
if (unlikely(tx_status != NET_XMIT_SUCCESS &&
tx_status != NET_XMIT_CN)) {
this_cpu_inc(repr->stats->tx_drops);
return;
}
stats = this_cpu_ptr(repr->stats);
u64_stats_update_begin(&stats->syncp);
stats->tx_packets++;
stats->tx_bytes += len;
u64_stats_update_end(&stats->syncp);
}
void nfp_repr_inc_rx_stats(struct net_device *netdev, unsigned int len)
{
struct nfp_repr *repr = netdev_priv(netdev);
struct nfp_repr_pcpu_stats *stats;
stats = this_cpu_ptr(repr->stats);
u64_stats_update_begin(&stats->syncp);
stats->rx_packets++;
stats->rx_bytes += len;
u64_stats_update_end(&stats->syncp);
}
static void
nfp_repr_phy_port_get_stats64(const struct nfp_app *app, u8 phy_port,
struct rtnl_link_stats64 *stats)
{
u8 __iomem *mem;
mem = app->pf->mac_stats_mem + phy_port * NFP_MAC_STATS_SIZE;
stats->tx_packets = readq(mem + NFP_MAC_STATS_RX_FRAMES_RECEIVED_OK);
stats->tx_bytes = readq(mem + NFP_MAC_STATS_RX_IN_OCTETS);
stats->tx_dropped = readq(mem + NFP_MAC_STATS_RX_IN_ERRORS);
stats->rx_packets = readq(mem + NFP_MAC_STATS_TX_FRAMES_TRANSMITTED_OK);
stats->rx_bytes = readq(mem + NFP_MAC_STATS_TX_OUT_OCTETS);
stats->rx_dropped = readq(mem + NFP_MAC_STATS_TX_OUT_ERRORS);
}
static void
nfp_repr_vf_get_stats64(const struct nfp_app *app, u8 vf,
struct rtnl_link_stats64 *stats)
{
u8 __iomem *mem;
mem = app->pf->vf_cfg_mem + vf * NFP_NET_CFG_BAR_SZ;
stats->tx_packets = readq(mem + NFP_NET_CFG_STATS_RX_FRAMES);
stats->tx_bytes = readq(mem + NFP_NET_CFG_STATS_RX_OCTETS);
stats->tx_dropped = readq(mem + NFP_NET_CFG_STATS_RX_DISCARDS);
stats->rx_packets = readq(mem + NFP_NET_CFG_STATS_TX_FRAMES);
stats->rx_bytes = readq(mem + NFP_NET_CFG_STATS_TX_OCTETS);
stats->rx_dropped = readq(mem + NFP_NET_CFG_STATS_TX_DISCARDS);
}
static void
nfp_repr_pf_get_stats64(const struct nfp_app *app, u8 pf,
struct rtnl_link_stats64 *stats)
{
u8 __iomem *mem;
if (pf)
return;
mem = nfp_cpp_area_iomem(app->pf->data_vnic_bar);
stats->tx_packets = readq(mem + NFP_NET_CFG_STATS_RX_FRAMES);
stats->tx_bytes = readq(mem + NFP_NET_CFG_STATS_RX_OCTETS);
stats->tx_dropped = readq(mem + NFP_NET_CFG_STATS_RX_DISCARDS);
stats->rx_packets = readq(mem + NFP_NET_CFG_STATS_TX_FRAMES);
stats->rx_bytes = readq(mem + NFP_NET_CFG_STATS_TX_OCTETS);
stats->rx_dropped = readq(mem + NFP_NET_CFG_STATS_TX_DISCARDS);
}
static void
nfp_repr_get_stats64(struct net_device *netdev, struct rtnl_link_stats64 *stats)
{
struct nfp_repr *repr = netdev_priv(netdev);
struct nfp_eth_table_port *eth_port;
struct nfp_app *app = repr->app;
if (WARN_ON(!repr->port))
return;
switch (repr->port->type) {
case NFP_PORT_PHYS_PORT:
eth_port = __nfp_port_get_eth_port(repr->port);
if (!eth_port)
break;
nfp_repr_phy_port_get_stats64(app, eth_port->index, stats);
break;
case NFP_PORT_PF_PORT:
nfp_repr_pf_get_stats64(app, repr->port->pf_id, stats);
break;
case NFP_PORT_VF_PORT:
nfp_repr_vf_get_stats64(app, repr->port->vf_id, stats);
default:
break;
}
}
static bool
nfp_repr_has_offload_stats(const struct net_device *dev, int attr_id)
{
switch (attr_id) {
case IFLA_OFFLOAD_XSTATS_CPU_HIT:
return true;
}
return false;
}
static int
nfp_repr_get_host_stats64(const struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct nfp_repr *repr = netdev_priv(netdev);
int i;
for_each_possible_cpu(i) {
u64 tbytes, tpkts, tdrops, rbytes, rpkts;
struct nfp_repr_pcpu_stats *repr_stats;
unsigned int start;
repr_stats = per_cpu_ptr(repr->stats, i);
do {
start = u64_stats_fetch_begin_irq(&repr_stats->syncp);
tbytes = repr_stats->tx_bytes;
tpkts = repr_stats->tx_packets;
tdrops = repr_stats->tx_drops;
rbytes = repr_stats->rx_bytes;
rpkts = repr_stats->rx_packets;
} while (u64_stats_fetch_retry_irq(&repr_stats->syncp, start));
stats->tx_bytes += tbytes;
stats->tx_packets += tpkts;
stats->tx_dropped += tdrops;
stats->rx_bytes += rbytes;
stats->rx_packets += rpkts;
}
return 0;
}
static int
nfp_repr_get_offload_stats(int attr_id, const struct net_device *dev,
void *stats)
{
switch (attr_id) {
case IFLA_OFFLOAD_XSTATS_CPU_HIT:
return nfp_repr_get_host_stats64(dev, stats);
}
return -EINVAL;
}
static netdev_tx_t nfp_repr_xmit(struct sk_buff *skb, struct net_device *netdev)
{
struct nfp_repr *repr = netdev_priv(netdev);
unsigned int len = skb->len;
int ret;
skb_dst_drop(skb);
dst_hold((struct dst_entry *)repr->dst);
skb_dst_set(skb, (struct dst_entry *)repr->dst);
skb->dev = repr->dst->u.port_info.lower_dev;
ret = dev_queue_xmit(skb);
nfp_repr_inc_tx_stats(netdev, len, ret);
return ret;
}
static int nfp_repr_stop(struct net_device *netdev)
{
struct nfp_repr *repr = netdev_priv(netdev);
return nfp_app_repr_stop(repr->app, repr);
}
static int nfp_repr_open(struct net_device *netdev)
{
struct nfp_repr *repr = netdev_priv(netdev);
return nfp_app_repr_open(repr->app, repr);
}
static void nfp_repr_clean(struct nfp_repr *repr)
{
unregister_netdev(repr->netdev);
dst_release((struct dst_entry *)repr->dst);
nfp_port_free(repr->port);
}
static void nfp_repr_set_lockdep_class_one(struct net_device *dev,
struct netdev_queue *txq,
void *_unused)
{
lockdep_set_class(&txq->_xmit_lock, &nfp_repr_netdev_xmit_lock_key);
}
static void nfp_repr_set_lockdep_class(struct net_device *dev)
{
lockdep_set_class(&dev->addr_list_lock, &nfp_repr_netdev_addr_lock_key);
netdev_for_each_tx_queue(dev, nfp_repr_set_lockdep_class_one, NULL);
}
int nfp_repr_init(struct nfp_app *app, struct net_device *netdev,
u32 cmsg_port_id, struct nfp_port *port,
struct net_device *pf_netdev)
{
struct nfp_repr *repr = netdev_priv(netdev);
int err;
nfp_repr_set_lockdep_class(netdev);
repr->port = port;
repr->dst = metadata_dst_alloc(0, METADATA_HW_PORT_MUX, GFP_KERNEL);
if (!repr->dst)
return -ENOMEM;
repr->dst->u.port_info.port_id = cmsg_port_id;
repr->dst->u.port_info.lower_dev = pf_netdev;
netdev->netdev_ops = &nfp_repr_netdev_ops;
SWITCHDEV_SET_OPS(netdev, &nfp_port_switchdev_ops);
if (nfp_app_has_tc(app)) {
netdev->features |= NETIF_F_HW_TC;
netdev->hw_features |= NETIF_F_HW_TC;
}
err = register_netdev(netdev);
if (err)
goto err_clean;
return 0;
err_clean:
dst_release((struct dst_entry *)repr->dst);
return err;
}
static void nfp_repr_free(struct nfp_repr *repr)
{
free_percpu(repr->stats);
free_netdev(repr->netdev);
}
struct net_device *nfp_repr_alloc(struct nfp_app *app)
{
struct net_device *netdev;
struct nfp_repr *repr;
netdev = alloc_etherdev(sizeof(*repr));
if (!netdev)
return NULL;
repr = netdev_priv(netdev);
repr->netdev = netdev;
repr->app = app;
repr->stats = netdev_alloc_pcpu_stats(struct nfp_repr_pcpu_stats);
if (!repr->stats)
goto err_free_netdev;
return netdev;
err_free_netdev:
free_netdev(netdev);
return NULL;
}
static void nfp_repr_clean_and_free(struct nfp_repr *repr)
{
nfp_info(repr->app->cpp, "Destroying Representor(%s)\n",
repr->netdev->name);
nfp_repr_clean(repr);
nfp_repr_free(repr);
}
void nfp_reprs_clean_and_free(struct nfp_reprs *reprs)
{
unsigned int i;
for (i = 0; i < reprs->num_reprs; i++)
if (reprs->reprs[i])
nfp_repr_clean_and_free(netdev_priv(reprs->reprs[i]));
kfree(reprs);
}
void
nfp_reprs_clean_and_free_by_type(struct nfp_app *app,
enum nfp_repr_type type)
{
struct nfp_reprs *reprs;
reprs = nfp_app_reprs_set(app, type, NULL);
if (!reprs)
return;
synchronize_rcu();
nfp_reprs_clean_and_free(reprs);
}
struct nfp_reprs *nfp_reprs_alloc(unsigned int num_reprs)
{
struct nfp_reprs *reprs;
reprs = kzalloc(sizeof(*reprs) +
num_reprs * sizeof(struct net_device *), GFP_KERNEL);
if (!reprs)
return NULL;
reprs->num_reprs = num_reprs;
return reprs;
}
