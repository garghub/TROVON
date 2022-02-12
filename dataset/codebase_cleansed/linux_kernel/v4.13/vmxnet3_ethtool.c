void
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
return ((9 +
(1 + adapter->intr.num_intrs) +
(1 + adapter->num_tx_queues * 17 ) +
(1 + adapter->num_rx_queues * 23 )) *
sizeof(u32));
}
static void
vmxnet3_get_drvinfo(struct net_device *netdev, struct ethtool_drvinfo *drvinfo)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
strlcpy(drvinfo->driver, vmxnet3_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, VMXNET3_DRIVER_VERSION_REPORT,
sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, pci_name(adapter->pdev),
sizeof(drvinfo->bus_info));
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
if (changed & (NETIF_F_RXCSUM | NETIF_F_LRO |
NETIF_F_HW_VLAN_CTAG_RX)) {
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
if (features & NETIF_F_HW_VLAN_CTAG_RX)
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
for (j = 0; j < adapter->num_rx_queues; j++) {
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
regs->version = 2;
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_VRRS);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_UVRS);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_DSAL);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_DSAH);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_CMD);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_MACL);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_MACH);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_ICR);
buf[j++] = VMXNET3_READ_BAR1_REG(adapter, VMXNET3_REG_ECR);
buf[j++] = adapter->intr.num_intrs;
for (i = 0; i < adapter->intr.num_intrs; i++) {
buf[j++] = VMXNET3_READ_BAR0_REG(adapter, VMXNET3_REG_IMR
+ i * VMXNET3_REG_ALIGN);
}
buf[j++] = adapter->num_tx_queues;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct vmxnet3_tx_queue *tq = &adapter->tx_queue[i];
buf[j++] = VMXNET3_READ_BAR0_REG(adapter, VMXNET3_REG_TXPROD +
i * VMXNET3_REG_ALIGN);
buf[j++] = VMXNET3_GET_ADDR_LO(tq->tx_ring.basePA);
buf[j++] = VMXNET3_GET_ADDR_HI(tq->tx_ring.basePA);
buf[j++] = tq->tx_ring.size;
buf[j++] = tq->tx_ring.next2fill;
buf[j++] = tq->tx_ring.next2comp;
buf[j++] = tq->tx_ring.gen;
buf[j++] = VMXNET3_GET_ADDR_LO(tq->data_ring.basePA);
buf[j++] = VMXNET3_GET_ADDR_HI(tq->data_ring.basePA);
buf[j++] = tq->data_ring.size;
buf[j++] = tq->txdata_desc_size;
buf[j++] = VMXNET3_GET_ADDR_LO(tq->comp_ring.basePA);
buf[j++] = VMXNET3_GET_ADDR_HI(tq->comp_ring.basePA);
buf[j++] = tq->comp_ring.size;
buf[j++] = tq->comp_ring.next2proc;
buf[j++] = tq->comp_ring.gen;
buf[j++] = tq->stopped;
}
buf[j++] = adapter->num_rx_queues;
for (i = 0; i < adapter->num_rx_queues; i++) {
struct vmxnet3_rx_queue *rq = &adapter->rx_queue[i];
buf[j++] = VMXNET3_READ_BAR0_REG(adapter, VMXNET3_REG_RXPROD +
i * VMXNET3_REG_ALIGN);
buf[j++] = VMXNET3_READ_BAR0_REG(adapter, VMXNET3_REG_RXPROD2 +
i * VMXNET3_REG_ALIGN);
buf[j++] = VMXNET3_GET_ADDR_LO(rq->rx_ring[0].basePA);
buf[j++] = VMXNET3_GET_ADDR_HI(rq->rx_ring[0].basePA);
buf[j++] = rq->rx_ring[0].size;
buf[j++] = rq->rx_ring[0].next2fill;
buf[j++] = rq->rx_ring[0].next2comp;
buf[j++] = rq->rx_ring[0].gen;
buf[j++] = VMXNET3_GET_ADDR_LO(rq->rx_ring[1].basePA);
buf[j++] = VMXNET3_GET_ADDR_HI(rq->rx_ring[1].basePA);
buf[j++] = rq->rx_ring[1].size;
buf[j++] = rq->rx_ring[1].next2fill;
buf[j++] = rq->rx_ring[1].next2comp;
buf[j++] = rq->rx_ring[1].gen;
buf[j++] = VMXNET3_GET_ADDR_LO(rq->data_ring.basePA);
buf[j++] = VMXNET3_GET_ADDR_HI(rq->data_ring.basePA);
buf[j++] = rq->rx_ring[0].size;
buf[j++] = rq->data_ring.desc_size;
buf[j++] = VMXNET3_GET_ADDR_LO(rq->comp_ring.basePA);
buf[j++] = VMXNET3_GET_ADDR_HI(rq->comp_ring.basePA);
buf[j++] = rq->comp_ring.size;
buf[j++] = rq->comp_ring.next2proc;
buf[j++] = rq->comp_ring.gen;
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
vmxnet3_get_link_ksettings(struct net_device *netdev,
struct ethtool_link_ksettings *ecmd)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
ethtool_link_ksettings_zero_link_mode(ecmd, supported);
ethtool_link_ksettings_add_link_mode(ecmd, supported, 10000baseT_Full);
ethtool_link_ksettings_add_link_mode(ecmd, supported, 1000baseT_Full);
ethtool_link_ksettings_add_link_mode(ecmd, supported, TP);
ethtool_link_ksettings_zero_link_mode(ecmd, advertising);
ethtool_link_ksettings_add_link_mode(ecmd, advertising, TP);
ecmd->base.port = PORT_TP;
if (adapter->link_speed) {
ecmd->base.speed = adapter->link_speed;
ecmd->base.duplex = DUPLEX_FULL;
} else {
ecmd->base.speed = SPEED_UNKNOWN;
ecmd->base.duplex = DUPLEX_UNKNOWN;
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
param->rx_mini_max_pending = VMXNET3_VERSION_GE_3(adapter) ?
VMXNET3_RXDATA_DESC_MAX_SIZE : 0;
param->rx_jumbo_max_pending = VMXNET3_RX_RING2_MAX_SIZE;
param->rx_pending = adapter->rx_ring_size;
param->tx_pending = adapter->tx_ring_size;
param->rx_mini_pending = VMXNET3_VERSION_GE_3(adapter) ?
adapter->rxdata_desc_size : 0;
param->rx_jumbo_pending = adapter->rx_ring2_size;
}
static int
vmxnet3_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *param)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
u32 new_tx_ring_size, new_rx_ring_size, new_rx_ring2_size;
u16 new_rxdata_desc_size;
u32 sz;
int err = 0;
if (param->tx_pending == 0 || param->tx_pending >
VMXNET3_TX_RING_MAX_SIZE)
return -EINVAL;
if (param->rx_pending == 0 || param->rx_pending >
VMXNET3_RX_RING_MAX_SIZE)
return -EINVAL;
if (param->rx_jumbo_pending == 0 ||
param->rx_jumbo_pending > VMXNET3_RX_RING2_MAX_SIZE)
return -EINVAL;
if (adapter->rx_buf_per_pkt == 0) {
netdev_err(netdev, "adapter not completely initialized, "
"ring size cannot be changed yet\n");
return -EOPNOTSUPP;
}
if (VMXNET3_VERSION_GE_3(adapter)) {
if (param->rx_mini_pending < 0 ||
param->rx_mini_pending > VMXNET3_RXDATA_DESC_MAX_SIZE) {
return -EINVAL;
}
} else if (param->rx_mini_pending != 0) {
return -EINVAL;
}
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
new_rx_ring2_size = (param->rx_jumbo_pending + VMXNET3_RING_SIZE_MASK) &
~VMXNET3_RING_SIZE_MASK;
new_rx_ring2_size = min_t(u32, new_rx_ring2_size,
VMXNET3_RX_RING2_MAX_SIZE);
new_rxdata_desc_size =
(param->rx_mini_pending + VMXNET3_RXDATA_DESC_SIZE_MASK) &
~VMXNET3_RXDATA_DESC_SIZE_MASK;
new_rxdata_desc_size = min_t(u16, new_rxdata_desc_size,
VMXNET3_RXDATA_DESC_MAX_SIZE);
if (new_tx_ring_size == adapter->tx_ring_size &&
new_rx_ring_size == adapter->rx_ring_size &&
new_rx_ring2_size == adapter->rx_ring2_size &&
new_rxdata_desc_size == adapter->rxdata_desc_size) {
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
new_rx_ring_size, new_rx_ring2_size,
adapter->txdata_desc_size,
new_rxdata_desc_size);
if (err) {
netdev_err(netdev, "failed to apply new sizes, "
"try the default ones\n");
new_rx_ring_size = VMXNET3_DEF_RX_RING_SIZE;
new_rx_ring2_size = VMXNET3_DEF_RX_RING2_SIZE;
new_tx_ring_size = VMXNET3_DEF_TX_RING_SIZE;
new_rxdata_desc_size = VMXNET3_VERSION_GE_3(adapter) ?
VMXNET3_DEF_RXDATA_DESC_SIZE : 0;
err = vmxnet3_create_queues(adapter,
new_tx_ring_size,
new_rx_ring_size,
new_rx_ring2_size,
adapter->txdata_desc_size,
new_rxdata_desc_size);
if (err) {
netdev_err(netdev, "failed to create queues "
"with default sizes. Closing it\n");
goto out;
}
}
err = vmxnet3_activate_dev(adapter);
if (err)
netdev_err(netdev, "failed to re-activate, error %d."
" Closing it\n", err);
}
adapter->tx_ring_size = new_tx_ring_size;
adapter->rx_ring_size = new_rx_ring_size;
adapter->rx_ring2_size = new_rx_ring2_size;
adapter->rxdata_desc_size = new_rxdata_desc_size;
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
vmxnet3_get_rss(struct net_device *netdev, u32 *p, u8 *key, u8 *hfunc)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct UPT1_RSSConf *rssConf = adapter->rss_conf;
unsigned int n = rssConf->indTableSize;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (!p)
return 0;
while (n--)
p[n] = rssConf->indTable[n];
return 0;
}
static int
vmxnet3_set_rss(struct net_device *netdev, const u32 *p, const u8 *key,
const u8 hfunc)
{
unsigned int i;
unsigned long flags;
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct UPT1_RSSConf *rssConf = adapter->rss_conf;
if (key ||
(hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP))
return -EOPNOTSUPP;
if (!p)
return 0;
for (i = 0; i < rssConf->indTableSize; i++)
rssConf->indTable[i] = p[i];
spin_lock_irqsave(&adapter->cmd_lock, flags);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_UPDATE_RSSIDT);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
return 0;
}
static int
vmxnet3_get_coalesce(struct net_device *netdev, struct ethtool_coalesce *ec)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
if (!VMXNET3_VERSION_GE_3(adapter))
return -EOPNOTSUPP;
switch (adapter->coal_conf->coalMode) {
case VMXNET3_COALESCE_DISABLED:
break;
case VMXNET3_COALESCE_ADAPT:
ec->use_adaptive_rx_coalesce = true;
break;
case VMXNET3_COALESCE_STATIC:
ec->tx_max_coalesced_frames =
adapter->coal_conf->coalPara.coalStatic.tx_comp_depth;
ec->rx_max_coalesced_frames =
adapter->coal_conf->coalPara.coalStatic.rx_depth;
break;
case VMXNET3_COALESCE_RBC: {
u32 rbc_rate;
rbc_rate = adapter->coal_conf->coalPara.coalRbc.rbc_rate;
ec->rx_coalesce_usecs = VMXNET3_COAL_RBC_USECS(rbc_rate);
}
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int
vmxnet3_set_coalesce(struct net_device *netdev, struct ethtool_coalesce *ec)
{
struct vmxnet3_adapter *adapter = netdev_priv(netdev);
struct Vmxnet3_DriverShared *shared = adapter->shared;
union Vmxnet3_CmdInfo *cmdInfo = &shared->cu.cmdInfo;
unsigned long flags;
if (!VMXNET3_VERSION_GE_3(adapter))
return -EOPNOTSUPP;
if (ec->rx_coalesce_usecs_irq ||
ec->rx_max_coalesced_frames_irq ||
ec->tx_coalesce_usecs ||
ec->tx_coalesce_usecs_irq ||
ec->tx_max_coalesced_frames_irq ||
ec->stats_block_coalesce_usecs ||
ec->use_adaptive_tx_coalesce ||
ec->pkt_rate_low ||
ec->rx_coalesce_usecs_low ||
ec->rx_max_coalesced_frames_low ||
ec->tx_coalesce_usecs_low ||
ec->tx_max_coalesced_frames_low ||
ec->pkt_rate_high ||
ec->rx_coalesce_usecs_high ||
ec->rx_max_coalesced_frames_high ||
ec->tx_coalesce_usecs_high ||
ec->tx_max_coalesced_frames_high ||
ec->rate_sample_interval) {
return -EINVAL;
}
if ((ec->rx_coalesce_usecs == 0) &&
(ec->use_adaptive_rx_coalesce == 0) &&
(ec->tx_max_coalesced_frames == 0) &&
(ec->rx_max_coalesced_frames == 0)) {
memset(adapter->coal_conf, 0, sizeof(*adapter->coal_conf));
adapter->coal_conf->coalMode = VMXNET3_COALESCE_DISABLED;
goto done;
}
if (ec->rx_coalesce_usecs != 0) {
u32 rbc_rate;
if ((ec->use_adaptive_rx_coalesce != 0) ||
(ec->tx_max_coalesced_frames != 0) ||
(ec->rx_max_coalesced_frames != 0)) {
return -EINVAL;
}
rbc_rate = VMXNET3_COAL_RBC_RATE(ec->rx_coalesce_usecs);
if (rbc_rate < VMXNET3_COAL_RBC_MIN_RATE ||
rbc_rate > VMXNET3_COAL_RBC_MAX_RATE) {
return -EINVAL;
}
memset(adapter->coal_conf, 0, sizeof(*adapter->coal_conf));
adapter->coal_conf->coalMode = VMXNET3_COALESCE_RBC;
adapter->coal_conf->coalPara.coalRbc.rbc_rate = rbc_rate;
goto done;
}
if (ec->use_adaptive_rx_coalesce != 0) {
if ((ec->rx_coalesce_usecs != 0) ||
(ec->tx_max_coalesced_frames != 0) ||
(ec->rx_max_coalesced_frames != 0)) {
return -EINVAL;
}
memset(adapter->coal_conf, 0, sizeof(*adapter->coal_conf));
adapter->coal_conf->coalMode = VMXNET3_COALESCE_ADAPT;
goto done;
}
if ((ec->tx_max_coalesced_frames != 0) ||
(ec->rx_max_coalesced_frames != 0)) {
if ((ec->rx_coalesce_usecs != 0) ||
(ec->use_adaptive_rx_coalesce != 0)) {
return -EINVAL;
}
if ((ec->tx_max_coalesced_frames >
VMXNET3_COAL_STATIC_MAX_DEPTH) ||
(ec->rx_max_coalesced_frames >
VMXNET3_COAL_STATIC_MAX_DEPTH)) {
return -EINVAL;
}
memset(adapter->coal_conf, 0, sizeof(*adapter->coal_conf));
adapter->coal_conf->coalMode = VMXNET3_COALESCE_STATIC;
adapter->coal_conf->coalPara.coalStatic.tx_comp_depth =
(ec->tx_max_coalesced_frames ?
ec->tx_max_coalesced_frames :
VMXNET3_COAL_STATIC_DEFAULT_DEPTH);
adapter->coal_conf->coalPara.coalStatic.rx_depth =
(ec->rx_max_coalesced_frames ?
ec->rx_max_coalesced_frames :
VMXNET3_COAL_STATIC_DEFAULT_DEPTH);
adapter->coal_conf->coalPara.coalStatic.tx_depth =
VMXNET3_COAL_STATIC_DEFAULT_DEPTH;
goto done;
}
done:
adapter->default_coal_mode = false;
if (netif_running(netdev)) {
spin_lock_irqsave(&adapter->cmd_lock, flags);
cmdInfo->varConf.confVer = 1;
cmdInfo->varConf.confLen =
cpu_to_le32(sizeof(*adapter->coal_conf));
cmdInfo->varConf.confPA = cpu_to_le64(adapter->coal_conf_pa);
VMXNET3_WRITE_BAR1_REG(adapter, VMXNET3_REG_CMD,
VMXNET3_CMD_SET_COALESCE);
spin_unlock_irqrestore(&adapter->cmd_lock, flags);
}
return 0;
}
void vmxnet3_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &vmxnet3_ethtool_ops;
}
