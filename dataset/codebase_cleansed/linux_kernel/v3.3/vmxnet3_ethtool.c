struct rtnl_link_stats64 *
vmxnet3_get_stats64(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct vmxnet3_adapter *adapter;
struct vmxnet3_tq_driver_stats *drvTxStats;
struct vmxnet3_rq_driver_stats *drvRxStats;
struct UPT1_TxStats *devTxStats;
struct UPT1_RxStats *devRxStats;
unsigned long flags;
int i;
adapter = netdev_priv(netdev);
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD, VMXNET3_CMD_GET_STATS);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
for (i = 0; i < adapter->num_tx_queues; i++) {
devTxStats = &adapter->tqd_start[i].stats;
drvTxStats = &adapter->tx_queue[i].stats;
stats->tx_packets += devTxStats->ucastPktsTxOK +
devTxStats->mcastPktsTxOK +
devTxStats->bcastPktsTxOK;
stats->tx_bytes += devTxStats->ucastBytesTxOK +
devTxStats->mcastBytesTxOK +
devTxStats->bcastBytesTxOK;
stats->tx_errors += devTxStats->pktsTxError;
stats->tx_dropped += drvTxStats->drop_total;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
devRxStats = &adapter->rqd_start[i].stats;
drvRxStats = &adapter->rx_queue[i].stats;
stats->rx_packets += devRxStats->ucastPktsRxOK +
devRxStats->mcastPktsRxOK +
devRxStats->bcastPktsRxOK;
stats->rx_bytes += devRxStats->ucastBytesRxOK +
devRxStats->mcastBytesRxOK +
devRxStats->bcastBytesRxOK;
stats->rx_errors += devRxStats->pktsRxError;
stats->rx_dropped += drvRxStats->drop_total;
stats->multicast += devRxStats->mcastPktsRxOK;
}
return stats;
}
static int
vmxnet3_get_sset_count(struct net_device *netdev, int sset)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
switch (sset) {
case ETH_SS_STATS:
return (ARRAY_SIZE(vmxnet3_tq_dev_stats) +
ARRAY_SIZE(vmxnet3_tq_driver_stats)) *
adapter->num_tx_queues +
(ARRAY_SIZE(vmxnet3_rq_dev_stats) +
ARRAY_SIZE(vmxnet3_rq_driver_stats)) *
adapter->num_rx_queues +
ARRAY_SIZE(vmxnet3_global_stats);
default:
return -EOPNOTSUPP;
}
}
static int
vmxnet3_get_regs_len(struct net_device *netdev)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
return (adapter->num_tx_queues * NUM_TX_REGS * sizeof(u32) +
adapter->num_rx_queues * NUM_RX_REGS * sizeof(u32));
}
static void
vmxnet3_get_drvinfo(struct net_device *netdev, struct ethtool_drvinfo *drvinfo)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
strlcpy(drvinfo->driver, vmxnet3_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, VMXNET3_DRIVER_VERSION_REPORT,
sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev),
ETHTOOL_BUSINFO_LEN);
drvinfo->n_stats = vmxnet3_get_sset_count(netdev, ETH_SS_STATS);
drvinfo->testinfo_len = 0;
drvinfo->eedump_len = 0;
drvinfo->regdump_len = vmxnet3_get_regs_len(netdev);
}
static void
vmxnet3_get_strings(struct net_device *netdev, u32 stringset, u8 *buf)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
if (stringset == ETH_SS_STATS) {
int i, j;
for (j = 0; j < adapter->num_tx_queues; j++) {
for (i = 0; i < ARRAY_SIZE(vmxnet3_tq_dev_stats); i++) {
memcpy(buf, vmxnet3_tq_dev_stats[i].desc,
ETH_GSTRING_LEN);
buf += ETH_GSTRING_LEN;
}
for (i = 0; i < ARRAY_SIZE(vmxnet3_tq_driver_stats);
i++) {
memcpy(buf, vmxnet3_tq_driver_stats[i].desc,
ETH_GSTRING_LEN);
buf += ETH_GSTRING_LEN;
}
}
for (j = 0; j < adapter->num_rx_queues; j++) {
for (i = 0; i < ARRAY_SIZE(vmxnet3_rq_dev_stats); i++) {
memcpy(buf, vmxnet3_rq_dev_stats[i].desc,
ETH_GSTRING_LEN);
buf += ETH_GSTRING_LEN;
}
for (i = 0; i < ARRAY_SIZE(vmxnet3_rq_driver_stats);
i++) {
memcpy(buf, vmxnet3_rq_driver_stats[i].desc,
ETH_GSTRING_LEN);
buf += ETH_GSTRING_LEN;
}
}
for (i = 0; i < ARRAY_SIZE(vmxnet3_global_stats); i++) {
memcpy(buf, vmxnet3_global_stats[i].desc,
ETH_GSTRING_LEN);
buf += ETH_GSTRING_LEN;
}
}
}
int vmxnet3_set_features(struct net_device *netdev, netdev_features_t features)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
unsigned long flags;
netdev_features_t changed = features ^ netdev->features;
if (changed & (NETIF_F_RXCSUM | NETIF_F_LRO | NETIF_F_HW_VLAN_RX)) {
if (features & NETIF_F_RXCSUM)
adapter->shared->devRead.misc.uptFeatures |=
UPT1_F_RXCSUM;
else
adapter->shared->devRead.misc.uptFeatures &=
~UPT1_F_RXCSUM;
if (features & NETIF_F_LRO)
adapter->shared->devRead.misc.uptFeatures |=
UPT1_F_LRO;
else
adapter->shared->devRead.misc.uptFeatures &=
~UPT1_F_LRO;
if (features & NETIF_F_HW_VLAN_RX)
adapter->shared->devRead.misc.uptFeatures |=
UPT1_F_RXVLAN;
else
adapter->shared->devRead.misc.uptFeatures &=
~UPT1_F_RXVLAN;
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_FEATURE);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
}
return 0;
}
static void
vmxnet3_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *buf)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
unsigned long flags;
u8 *base;
int i;
int j = 0;
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD, VMXNET3_CMD_GET_STATS);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
for (j = 0; j < adapter->num_tx_queues; j++) {
base = (u8 *)&adapter->tqd_start[j].stats;
*buf++ = (u64)j;
for (i = 1; i < ARRAY_SIZE(vmxnet3_tq_dev_stats); i++)
*buf++ = *(u64 *)(base +
vmxnet3_tq_dev_stats[i].offset);
base = (u8 *)&adapter->tx_queue[j].stats;
for (i = 0; i < ARRAY_SIZE(vmxnet3_tq_driver_stats); i++)
*buf++ = *(u64 *)(base +
vmxnet3_tq_driver_stats[i].offset);
}
for (j = 0; j < adapter->num_tx_queues; j++) {
base = (u8 *)&adapter->rqd_start[j].stats;
*buf++ = (u64) j;
for (i = 1; i < ARRAY_SIZE(vmxnet3_rq_dev_stats); i++)
*buf++ = *(u64 *)(base +
vmxnet3_rq_dev_stats[i].offset);
base = (u8 *)&adapter->rx_queue[j].stats;
for (i = 0; i < ARRAY_SIZE(vmxnet3_rq_driver_stats); i++)
*buf++ = *(u64 *)(base +
vmxnet3_rq_driver_stats[i].offset);
}
base = (u8 *)adapter;
for (i = 0; i < ARRAY_SIZE(vmxnet3_global_stats); i++)
*buf++ = *(u64 *)(base + vmxnet3_global_stats[i].offset);
}
static void
vmxnet3_get_regs(struct net_device *netdev, struct ethtool_regs *regs, void *p)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
u32 *buf = p;
int i = 0, j = 0;
memset(p, 0, vmxnet3_get_regs_len(netdev));
regs->version = 1;
for (i = 0; i < adapter->num_tx_queues; i++) {
buf[j++] = adapter->tx_queue[i].tx_ring.next2fill;
buf[j++] = adapter->tx_queue[i].tx_ring.next2comp;
buf[j++] = adapter->tx_queue[i].tx_ring.gen;
buf[j++] = 0;
buf[j++] = adapter->tx_queue[i].comp_ring.next2proc;
buf[j++] = adapter->tx_queue[i].comp_ring.gen;
buf[j++] = adapter->tx_queue[i].stopped;
buf[j++] = 0;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
buf[j++] = adapter->rx_queue[i].rx_ring[0].next2fill;
buf[j++] = adapter->rx_queue[i].rx_ring[0].next2comp;
buf[j++] = adapter->rx_queue[i].rx_ring[0].gen;
buf[j++] = 0;
buf[j++] = adapter->rx_queue[i].rx_ring[1].next2fill;
buf[j++] = adapter->rx_queue[i].rx_ring[1].next2comp;
buf[j++] = adapter->rx_queue[i].rx_ring[1].gen;
buf[j++] = 0;
buf[j++] = adapter->rx_queue[i].comp_ring.next2proc;
buf[j++] = adapter->rx_queue[i].comp_ring.gen;
buf[j++] = 0;
buf[j++] = 0;
}
}
static void
vmxnet3_get_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
wol->supported = WAKE_UCAST | WAKE_ARP | WAKE_MAGIC;
wol->wolopts = adapter->wol;
}
static int
vmxnet3_set_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
if (wol->wolopts & (WAKE_PHY | WAKE_MCAST | WAKE_BCAST |
WAKE_MAGICSECURE)) {
return -EOPNOTSUPP;
}
adapter->wol = wol->wolopts;
device_set_wakeup_enable(&adapter->pdev->dev, adapter->wol);
return 0;
}
static int
vmxnet3_get_settings(struct net_device *netdev, struct ethtool_cmd *ecmd)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
ecmd->supported = SUPPORTED_10000baseT_Full | SUPPORTED_1000baseT_Full |
SUPPORTED_TP;
ecmd->advertising = ADVERTISED_TP;
ecmd->port = PORT_TP;
ecmd->transceiver = XCVR_INTERNAL;
if (adapter->link_speed) {
ethtool_cmd_speed_set(ecmd, adapter->link_speed);
ecmd->duplex = DUPLEX_FULL;
} else {
ethtool_cmd_speed_set(ecmd, -1);
ecmd->duplex = -1;
}
return 0;
}
static void
vmxnet3_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *param)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
param->rx_max_pending = VMXNET3_RX_RING_MAX_SIZE;
param->tx_max_pending = VMXNET3_TX_RING_MAX_SIZE;
param->rx_mini_max_pending = 0;
param->rx_jumbo_max_pending = 0;
param->rx_pending = adapter->rx_queue[0].rx_ring[0].size *
adapter->num_rx_queues;
param->tx_pending = adapter->tx_queue[0].tx_ring.size *
adapter->num_tx_queues;
param->rx_mini_pending = 0;
param->rx_jumbo_pending = 0;
}
static int
vmxnet3_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *param)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
u32 new_tx_ring_size, new_rx_ring_size;
u32 sz;
int err = 0;
if (param->tx_pending == 0 || param->tx_pending >
VMXNET3_TX_RING_MAX_SIZE)
return -EINVAL;
if (param->rx_pending == 0 || param->rx_pending >
VMXNET3_RX_RING_MAX_SIZE)
return -EINVAL;
new_tx_ring_size = (param->tx_pending + VMXNET3_RING_SIZE_MASK) &
~VMXNET3_RING_SIZE_MASK;
new_tx_ring_size = min_t(u32, new_tx_ring_size,
VMXNET3_TX_RING_MAX_SIZE);
if (new_tx_ring_size > VMXNET3_TX_RING_MAX_SIZE || (new_tx_ring_size %
VMXNET3_RING_SIZE_ALIGN) != 0)
return -EINVAL;
sz = adapter->rx_buf_per_pkt * VMXNET3_RING_SIZE_ALIGN;
new_rx_ring_size = (param->rx_pending + sz - 1) / sz * sz;
new_rx_ring_size = min_t(u32, new_rx_ring_size,
VMXNET3_RX_RING_MAX_SIZE / sz * sz);
if (new_rx_ring_size > VMXNET3_RX_RING_MAX_SIZE || (new_rx_ring_size %
sz) != 0)
return -EINVAL;
if (new_tx_ring_size == adapter->tx_queue[0].tx_ring.size &&
new_rx_ring_size == adapter->rx_queue[0].rx_ring[0].size) {
return 0;
}
while (test_and_set_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state))
msleep(1);
if (netif_running(netdev)) {
vmxnet3_quiesce_dev(adapter);
vmxnet3_reset_dev(adapter);
vmxnet3_tq_destroy_all(adapter);
vmxnet3_rq_destroy_all(adapter);
err = vmxnet3_create_queues(adapter, new_tx_ring_size,
new_rx_ring_size, VMXNET3_DEF_RX_RING_SIZE);
if (err) {
printk(KERN_ERR "%s: failed to apply new sizes, try the"
" default ones\n", netdev->name);
err = vmxnet3_create_queues(adapter,
VMXNET3_DEF_TX_RING_SIZE,
VMXNET3_DEF_RX_RING_SIZE,
VMXNET3_DEF_RX_RING_SIZE);
if (err) {
printk(KERN_ERR "%s: failed to create queues "
"with default sizes. Closing it\n",
netdev->name);
goto out;
}
}
err = vmxnet3_activate_dev(adapter);
if (err)
printk(KERN_ERR "%s: failed to re-activate, error %d."
" Closing it\n", netdev->name, err);
}
out:
clear_bit(VMXNET3_STATE_BIT_RESETTING, &adapter->state);
if (err)
vmxnet3_force_close(adapter);
return err;
}
static int
vmxnet3_get_rxnfc(struct net_device *netdev, struct ethtool_rxnfc *info,
u32 *rules)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
switch (info->cmd) {
case ETHTOOL_GRXRINGS:
info->data = adapter->num_rx_queues;
return 0;
}
return -EOPNOTSUPP;
}
static u32
vmxnet3_get_rss_indir_size(struct net_device *netdev)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct UPT1_RSSConf *rssConf = adapter->rss_conf;
return rssConf->indTableSize;
}
static int
vmxnet3_get_rss_indir(struct net_device *netdev, u32 *p)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct UPT1_RSSConf *rssConf = adapter->rss_conf;
unsigned int n = rssConf->indTableSize;
while (n--)
p[n] = rssConf->indTable[n];
return 0;
}
static int
vmxnet3_set_rss_indir(struct net_device *netdev, const u32 *p)
{
unsigned int i;
unsigned long flags;
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct UPT1_RSSConf *rssConf = adapter->rss_conf;
for (i = 0; i < rssConf->indTableSize; i++)
rssConf->indTable[i] = p[i];
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_RSSIDT);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
return 0;
}
void vmxnet3_set_ethtool_ops(struct net_device *netdev)
{
SET_ETHTOOL_OPS(netdev, &vmxnet3_ethtool_ops);
}
