static inline void schedule_mac_stats_update(struct adapter *ap, int secs)
{
schedule_delayed_work(&ap->stats_update_task, secs * HZ);
}
static inline void cancel_mac_stats_update(struct adapter *ap)
{
cancel_delayed_work(&ap->stats_update_task);
}
static void t1_set_rxmode(struct net_device *dev)
{
struct adapter *adapter = dev->ml_priv;
struct cmac *mac = adapter->port[dev->if_port].mac;
struct t1_rx_mode rm;
rm.dev = dev;
mac->ops->set_rx_mode(mac, &rm);
}
static void link_report(struct port_info *p)
{
if (!netif_carrier_ok(p->dev))
netdev_info(p->dev, "link down\n");
else {
const char *s = "10Mbps";
switch (p->link_config.speed) {
case SPEED_10000: s = "10Gbps"; break;
case SPEED_1000: s = "1000Mbps"; break;
case SPEED_100: s = "100Mbps"; break;
}
netdev_info(p->dev, "link up, %s, %s-duplex\n",
s, p->link_config.duplex == DUPLEX_FULL
? "full" : "half");
}
}
void t1_link_negotiated(struct adapter *adapter, int port_id, int link_stat,
int speed, int duplex, int pause)
{
struct port_info *p = &adapter->port[port_id];
if (link_stat != netif_carrier_ok(p->dev)) {
if (link_stat)
netif_carrier_on(p->dev);
else
netif_carrier_off(p->dev);
link_report(p);
if ((speed > 0) && (adapter->params.nports > 1)) {
unsigned int sched_speed = 10;
switch (speed) {
case SPEED_1000:
sched_speed = 1000;
break;
case SPEED_100:
sched_speed = 100;
break;
case SPEED_10:
sched_speed = 10;
break;
}
t1_sched_update_parms(adapter->sge, port_id, 0, sched_speed);
}
}
}
static void link_start(struct port_info *p)
{
struct cmac *mac = p->mac;
mac->ops->reset(mac);
if (mac->ops->macaddress_set)
mac->ops->macaddress_set(mac, p->dev->dev_addr);
t1_set_rxmode(p->dev);
t1_link_start(p->phy, mac, &p->link_config);
mac->ops->enable(mac, MAC_DIRECTION_RX | MAC_DIRECTION_TX);
}
static void enable_hw_csum(struct adapter *adapter)
{
if (adapter->port[0].dev->hw_features & NETIF_F_TSO)
t1_tp_set_ip_checksum_offload(adapter->tp, 1);
t1_tp_set_tcp_checksum_offload(adapter->tp, 1);
}
static int cxgb_up(struct adapter *adapter)
{
int err = 0;
if (!(adapter->flags & FULL_INIT_DONE)) {
err = t1_init_hw_modules(adapter);
if (err)
goto out_err;
enable_hw_csum(adapter);
adapter->flags |= FULL_INIT_DONE;
}
t1_interrupts_clear(adapter);
adapter->params.has_msi = !disable_msi && !pci_enable_msi(adapter->pdev);
err = request_irq(adapter->pdev->irq, t1_interrupt,
adapter->params.has_msi ? 0 : IRQF_SHARED,
adapter->name, adapter);
if (err) {
if (adapter->params.has_msi)
pci_disable_msi(adapter->pdev);
goto out_err;
}
t1_sge_start(adapter->sge);
t1_interrupts_enable(adapter);
out_err:
return err;
}
static void cxgb_down(struct adapter *adapter)
{
t1_sge_stop(adapter->sge);
t1_interrupts_disable(adapter);
free_irq(adapter->pdev->irq, adapter);
if (adapter->params.has_msi)
pci_disable_msi(adapter->pdev);
}
static int cxgb_open(struct net_device *dev)
{
int err;
struct adapter *adapter = dev->ml_priv;
int other_ports = adapter->open_device_map & PORT_MASK;
napi_enable(&adapter->napi);
if (!adapter->open_device_map && (err = cxgb_up(adapter)) < 0) {
napi_disable(&adapter->napi);
return err;
}
__set_bit(dev->if_port, &adapter->open_device_map);
link_start(&adapter->port[dev->if_port]);
netif_start_queue(dev);
if (!other_ports && adapter->params.stats_update_period)
schedule_mac_stats_update(adapter,
adapter->params.stats_update_period);
t1_vlan_mode(adapter, dev->features);
return 0;
}
static int cxgb_close(struct net_device *dev)
{
struct adapter *adapter = dev->ml_priv;
struct port_info *p = &adapter->port[dev->if_port];
struct cmac *mac = p->mac;
netif_stop_queue(dev);
napi_disable(&adapter->napi);
mac->ops->disable(mac, MAC_DIRECTION_TX | MAC_DIRECTION_RX);
netif_carrier_off(dev);
clear_bit(dev->if_port, &adapter->open_device_map);
if (adapter->params.stats_update_period &&
!(adapter->open_device_map & PORT_MASK)) {
smp_mb__after_clear_bit();
spin_lock(&adapter->work_lock);
spin_unlock(&adapter->work_lock);
cancel_mac_stats_update(adapter);
}
if (!adapter->open_device_map)
cxgb_down(adapter);
return 0;
}
static struct net_device_stats *t1_get_stats(struct net_device *dev)
{
struct adapter *adapter = dev->ml_priv;
struct port_info *p = &adapter->port[dev->if_port];
struct net_device_stats *ns = &p->netstats;
const struct cmac_statistics *pstats;
pstats = p->mac->ops->statistics_update(p->mac,
MAC_STATS_UPDATE_FULL);
ns->tx_packets = pstats->TxUnicastFramesOK +
pstats->TxMulticastFramesOK + pstats->TxBroadcastFramesOK;
ns->rx_packets = pstats->RxUnicastFramesOK +
pstats->RxMulticastFramesOK + pstats->RxBroadcastFramesOK;
ns->tx_bytes = pstats->TxOctetsOK;
ns->rx_bytes = pstats->RxOctetsOK;
ns->tx_errors = pstats->TxLateCollisions + pstats->TxLengthErrors +
pstats->TxUnderrun + pstats->TxFramesAbortedDueToXSCollisions;
ns->rx_errors = pstats->RxDataErrors + pstats->RxJabberErrors +
pstats->RxFCSErrors + pstats->RxAlignErrors +
pstats->RxSequenceErrors + pstats->RxFrameTooLongErrors +
pstats->RxSymbolErrors + pstats->RxRuntErrors;
ns->multicast = pstats->RxMulticastFramesOK;
ns->collisions = pstats->TxTotalCollisions;
ns->rx_length_errors = pstats->RxFrameTooLongErrors +
pstats->RxJabberErrors;
ns->rx_over_errors = 0;
ns->rx_crc_errors = pstats->RxFCSErrors;
ns->rx_frame_errors = pstats->RxAlignErrors;
ns->rx_fifo_errors = 0;
ns->rx_missed_errors = 0;
ns->tx_aborted_errors = pstats->TxFramesAbortedDueToXSCollisions;
ns->tx_carrier_errors = 0;
ns->tx_fifo_errors = pstats->TxUnderrun;
ns->tx_heartbeat_errors = 0;
ns->tx_window_errors = pstats->TxLateCollisions;
return ns;
}
static u32 get_msglevel(struct net_device *dev)
{
struct adapter *adapter = dev->ml_priv;
return adapter->msg_enable;
}
static void set_msglevel(struct net_device *dev, u32 val)
{
struct adapter *adapter = dev->ml_priv;
adapter->msg_enable = val;
}
static int get_regs_len(struct net_device *dev)
{
return T2_REGMAP_SIZE;
}
static void get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct adapter *adapter = dev->ml_priv;
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(adapter->pdev),
sizeof(info->bus_info));
}
static int get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(stats_strings);
default:
return -EOPNOTSUPP;
}
}
static void get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
if (stringset == ETH_SS_STATS)
memcpy(data, stats_strings, sizeof(stats_strings));
}
static void get_stats(struct net_device *dev, struct ethtool_stats *stats,
u64 *data)
{
struct adapter *adapter = dev->ml_priv;
struct cmac *mac = adapter->port[dev->if_port].mac;
const struct cmac_statistics *s;
const struct sge_intr_counts *t;
struct sge_port_stats ss;
s = mac->ops->statistics_update(mac, MAC_STATS_UPDATE_FULL);
t = t1_sge_get_intr_counts(adapter->sge);
t1_sge_get_port_stats(adapter->sge, dev->if_port, &ss);
*data++ = s->TxOctetsOK;
*data++ = s->TxOctetsBad;
*data++ = s->TxUnicastFramesOK;
*data++ = s->TxMulticastFramesOK;
*data++ = s->TxBroadcastFramesOK;
*data++ = s->TxPauseFrames;
*data++ = s->TxFramesWithDeferredXmissions;
*data++ = s->TxLateCollisions;
*data++ = s->TxTotalCollisions;
*data++ = s->TxFramesAbortedDueToXSCollisions;
*data++ = s->TxUnderrun;
*data++ = s->TxLengthErrors;
*data++ = s->TxInternalMACXmitError;
*data++ = s->TxFramesWithExcessiveDeferral;
*data++ = s->TxFCSErrors;
*data++ = s->TxJumboFramesOK;
*data++ = s->TxJumboOctetsOK;
*data++ = s->RxOctetsOK;
*data++ = s->RxOctetsBad;
*data++ = s->RxUnicastFramesOK;
*data++ = s->RxMulticastFramesOK;
*data++ = s->RxBroadcastFramesOK;
*data++ = s->RxPauseFrames;
*data++ = s->RxFCSErrors;
*data++ = s->RxAlignErrors;
*data++ = s->RxSymbolErrors;
*data++ = s->RxDataErrors;
*data++ = s->RxSequenceErrors;
*data++ = s->RxRuntErrors;
*data++ = s->RxJabberErrors;
*data++ = s->RxInternalMACRcvError;
*data++ = s->RxInRangeLengthErrors;
*data++ = s->RxOutOfRangeLengthField;
*data++ = s->RxFrameTooLongErrors;
*data++ = s->RxJumboFramesOK;
*data++ = s->RxJumboOctetsOK;
*data++ = ss.rx_cso_good;
*data++ = ss.tx_cso;
*data++ = ss.tx_tso;
*data++ = ss.vlan_xtract;
*data++ = ss.vlan_insert;
*data++ = ss.tx_need_hdrroom;
*data++ = t->rx_drops;
*data++ = t->pure_rsps;
*data++ = t->unhandled_irqs;
*data++ = t->respQ_empty;
*data++ = t->respQ_overflow;
*data++ = t->freelistQ_empty;
*data++ = t->pkt_too_big;
*data++ = t->pkt_mismatch;
*data++ = t->cmdQ_full[0];
*data++ = t->cmdQ_full[1];
if (adapter->espi) {
const struct espi_intr_counts *e;
e = t1_espi_get_intr_counts(adapter->espi);
*data++ = e->DIP2_parity_err;
*data++ = e->DIP4_err;
*data++ = e->rx_drops;
*data++ = e->tx_drops;
*data++ = e->rx_ovflw;
*data++ = e->parity_err;
}
}
static inline void reg_block_dump(struct adapter *ap, void *buf,
unsigned int start, unsigned int end)
{
u32 *p = buf + start;
for ( ; start <= end; start += sizeof(u32))
*p++ = readl(ap->regs + start);
}
static void get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *buf)
{
struct adapter *ap = dev->ml_priv;
regs->version = 2;
memset(buf, 0, T2_REGMAP_SIZE);
reg_block_dump(ap, buf, 0, A_SG_RESPACCUTIMER);
reg_block_dump(ap, buf, A_MC3_CFG, A_MC4_INT_CAUSE);
reg_block_dump(ap, buf, A_TPI_ADDR, A_TPI_PAR);
reg_block_dump(ap, buf, A_TP_IN_CONFIG, A_TP_TX_DROP_COUNT);
reg_block_dump(ap, buf, A_RAT_ROUTE_CONTROL, A_RAT_INTR_CAUSE);
reg_block_dump(ap, buf, A_CSPI_RX_AE_WM, A_CSPI_INTR_ENABLE);
reg_block_dump(ap, buf, A_ESPI_SCH_TOKEN0, A_ESPI_GOSTAT);
reg_block_dump(ap, buf, A_ULP_ULIMIT, A_ULP_PIO_CTRL);
reg_block_dump(ap, buf, A_PL_ENABLE, A_PL_CAUSE);
reg_block_dump(ap, buf, A_MC5_CONFIG, A_MC5_MASK_WRITE_CMD);
}
static int get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct adapter *adapter = dev->ml_priv;
struct port_info *p = &adapter->port[dev->if_port];
cmd->supported = p->link_config.supported;
cmd->advertising = p->link_config.advertising;
if (netif_carrier_ok(dev)) {
ethtool_cmd_speed_set(cmd, p->link_config.speed);
cmd->duplex = p->link_config.duplex;
} else {
ethtool_cmd_speed_set(cmd, -1);
cmd->duplex = -1;
}
cmd->port = (cmd->supported & SUPPORTED_TP) ? PORT_TP : PORT_FIBRE;
cmd->phy_address = p->phy->mdio.prtad;
cmd->transceiver = XCVR_EXTERNAL;
cmd->autoneg = p->link_config.autoneg;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static int speed_duplex_to_caps(int speed, int duplex)
{
int cap = 0;
switch (speed) {
case SPEED_10:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_10baseT_Full;
else
cap = SUPPORTED_10baseT_Half;
break;
case SPEED_100:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_100baseT_Full;
else
cap = SUPPORTED_100baseT_Half;
break;
case SPEED_1000:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_1000baseT_Full;
else
cap = SUPPORTED_1000baseT_Half;
break;
case SPEED_10000:
if (duplex == DUPLEX_FULL)
cap = SUPPORTED_10000baseT_Full;
}
return cap;
}
static int set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct adapter *adapter = dev->ml_priv;
struct port_info *p = &adapter->port[dev->if_port];
struct link_config *lc = &p->link_config;
if (!(lc->supported & SUPPORTED_Autoneg))
return -EOPNOTSUPP;
if (cmd->autoneg == AUTONEG_DISABLE) {
u32 speed = ethtool_cmd_speed(cmd);
int cap = speed_duplex_to_caps(speed, cmd->duplex);
if (!(lc->supported & cap) || (speed == SPEED_1000))
return -EINVAL;
lc->requested_speed = speed;
lc->requested_duplex = cmd->duplex;
lc->advertising = 0;
} else {
cmd->advertising &= ADVERTISED_MASK;
if (cmd->advertising & (cmd->advertising - 1))
cmd->advertising = lc->supported;
cmd->advertising &= lc->supported;
if (!cmd->advertising)
return -EINVAL;
lc->requested_speed = SPEED_INVALID;
lc->requested_duplex = DUPLEX_INVALID;
lc->advertising = cmd->advertising | ADVERTISED_Autoneg;
}
lc->autoneg = cmd->autoneg;
if (netif_running(dev))
t1_link_start(p->phy, p->mac, lc);
return 0;
}
static void get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct adapter *adapter = dev->ml_priv;
struct port_info *p = &adapter->port[dev->if_port];
epause->autoneg = (p->link_config.requested_fc & PAUSE_AUTONEG) != 0;
epause->rx_pause = (p->link_config.fc & PAUSE_RX) != 0;
epause->tx_pause = (p->link_config.fc & PAUSE_TX) != 0;
}
static int set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct adapter *adapter = dev->ml_priv;
struct port_info *p = &adapter->port[dev->if_port];
struct link_config *lc = &p->link_config;
if (epause->autoneg == AUTONEG_DISABLE)
lc->requested_fc = 0;
else if (lc->supported & SUPPORTED_Autoneg)
lc->requested_fc = PAUSE_AUTONEG;
else
return -EINVAL;
if (epause->rx_pause)
lc->requested_fc |= PAUSE_RX;
if (epause->tx_pause)
lc->requested_fc |= PAUSE_TX;
if (lc->autoneg == AUTONEG_ENABLE) {
if (netif_running(dev))
t1_link_start(p->phy, p->mac, lc);
} else {
lc->fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
if (netif_running(dev))
p->mac->ops->set_speed_duplex_fc(p->mac, -1, -1,
lc->fc);
}
return 0;
}
static void get_sge_param(struct net_device *dev, struct ethtool_ringparam *e)
{
struct adapter *adapter = dev->ml_priv;
int jumbo_fl = t1_is_T1B(adapter) ? 1 : 0;
e->rx_max_pending = MAX_RX_BUFFERS;
e->rx_jumbo_max_pending = MAX_RX_JUMBO_BUFFERS;
e->tx_max_pending = MAX_CMDQ_ENTRIES;
e->rx_pending = adapter->params.sge.freelQ_size[!jumbo_fl];
e->rx_jumbo_pending = adapter->params.sge.freelQ_size[jumbo_fl];
e->tx_pending = adapter->params.sge.cmdQ_size[0];
}
static int set_sge_param(struct net_device *dev, struct ethtool_ringparam *e)
{
struct adapter *adapter = dev->ml_priv;
int jumbo_fl = t1_is_T1B(adapter) ? 1 : 0;
if (e->rx_pending > MAX_RX_BUFFERS || e->rx_mini_pending ||
e->rx_jumbo_pending > MAX_RX_JUMBO_BUFFERS ||
e->tx_pending > MAX_CMDQ_ENTRIES ||
e->rx_pending < MIN_FL_ENTRIES ||
e->rx_jumbo_pending < MIN_FL_ENTRIES ||
e->tx_pending < (adapter->params.nports + 1) * (MAX_SKB_FRAGS + 1))
return -EINVAL;
if (adapter->flags & FULL_INIT_DONE)
return -EBUSY;
adapter->params.sge.freelQ_size[!jumbo_fl] = e->rx_pending;
adapter->params.sge.freelQ_size[jumbo_fl] = e->rx_jumbo_pending;
adapter->params.sge.cmdQ_size[0] = e->tx_pending;
adapter->params.sge.cmdQ_size[1] = e->tx_pending > MAX_CMDQ1_ENTRIES ?
MAX_CMDQ1_ENTRIES : e->tx_pending;
return 0;
}
static int set_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
struct adapter *adapter = dev->ml_priv;
adapter->params.sge.rx_coalesce_usecs = c->rx_coalesce_usecs;
adapter->params.sge.coalesce_enable = c->use_adaptive_rx_coalesce;
adapter->params.sge.sample_interval_usecs = c->rate_sample_interval;
t1_sge_set_coalesce_params(adapter->sge, &adapter->params.sge);
return 0;
}
static int get_coalesce(struct net_device *dev, struct ethtool_coalesce *c)
{
struct adapter *adapter = dev->ml_priv;
c->rx_coalesce_usecs = adapter->params.sge.rx_coalesce_usecs;
c->rate_sample_interval = adapter->params.sge.sample_interval_usecs;
c->use_adaptive_rx_coalesce = adapter->params.sge.coalesce_enable;
return 0;
}
static int get_eeprom_len(struct net_device *dev)
{
struct adapter *adapter = dev->ml_priv;
return t1_is_asic(adapter) ? EEPROM_SIZE : 0;
}
static int get_eeprom(struct net_device *dev, struct ethtool_eeprom *e,
u8 *data)
{
int i;
u8 buf[EEPROM_SIZE] __attribute__((aligned(4)));
struct adapter *adapter = dev->ml_priv;
e->magic = EEPROM_MAGIC(adapter);
for (i = e->offset & ~3; i < e->offset + e->len; i += sizeof(u32))
t1_seeprom_read(adapter, i, (__le32 *)&buf[i]);
memcpy(data, buf + e->offset, e->len);
return 0;
}
static int t1_ioctl(struct net_device *dev, struct ifreq *req, int cmd)
{
struct adapter *adapter = dev->ml_priv;
struct mdio_if_info *mdio = &adapter->port[dev->if_port].phy->mdio;
return mdio_mii_ioctl(mdio, if_mii(req), cmd);
}
static int t1_change_mtu(struct net_device *dev, int new_mtu)
{
int ret;
struct adapter *adapter = dev->ml_priv;
struct cmac *mac = adapter->port[dev->if_port].mac;
if (!mac->ops->set_mtu)
return -EOPNOTSUPP;
if (new_mtu < 68)
return -EINVAL;
if ((ret = mac->ops->set_mtu(mac, new_mtu)))
return ret;
dev->mtu = new_mtu;
return 0;
}
static int t1_set_mac_addr(struct net_device *dev, void *p)
{
struct adapter *adapter = dev->ml_priv;
struct cmac *mac = adapter->port[dev->if_port].mac;
struct sockaddr *addr = p;
if (!mac->ops->macaddress_set)
return -EOPNOTSUPP;
memcpy(dev->dev_addr, addr->sa_data, dev->addr_len);
mac->ops->macaddress_set(mac, dev->dev_addr);
return 0;
}
static netdev_features_t t1_fix_features(struct net_device *dev,
netdev_features_t features)
{
if (features & NETIF_F_HW_VLAN_CTAG_RX)
features |= NETIF_F_HW_VLAN_CTAG_TX;
else
features &= ~NETIF_F_HW_VLAN_CTAG_TX;
return features;
}
static int t1_set_features(struct net_device *dev, netdev_features_t features)
{
netdev_features_t changed = dev->features ^ features;
struct adapter *adapter = dev->ml_priv;
if (changed & NETIF_F_HW_VLAN_CTAG_RX)
t1_vlan_mode(adapter, features);
return 0;
}
static void t1_netpoll(struct net_device *dev)
{
unsigned long flags;
struct adapter *adapter = dev->ml_priv;
local_irq_save(flags);
t1_interrupt(adapter->pdev->irq, adapter);
local_irq_restore(flags);
}
static void mac_stats_task(struct work_struct *work)
{
int i;
struct adapter *adapter =
container_of(work, struct adapter, stats_update_task.work);
for_each_port(adapter, i) {
struct port_info *p = &adapter->port[i];
if (netif_running(p->dev))
p->mac->ops->statistics_update(p->mac,
MAC_STATS_UPDATE_FAST);
}
spin_lock(&adapter->work_lock);
if (adapter->open_device_map & PORT_MASK)
schedule_mac_stats_update(adapter,
adapter->params.stats_update_period);
spin_unlock(&adapter->work_lock);
}
static void ext_intr_task(struct work_struct *work)
{
struct adapter *adapter =
container_of(work, struct adapter, ext_intr_handler_task);
t1_elmer0_ext_intr_handler(adapter);
spin_lock_irq(&adapter->async_lock);
adapter->slow_intr_mask |= F_PL_INTR_EXT;
writel(F_PL_INTR_EXT, adapter->regs + A_PL_CAUSE);
writel(adapter->slow_intr_mask | F_PL_INTR_SGE_DATA,
adapter->regs + A_PL_ENABLE);
spin_unlock_irq(&adapter->async_lock);
}
void t1_elmer0_ext_intr(struct adapter *adapter)
{
adapter->slow_intr_mask &= ~F_PL_INTR_EXT;
writel(adapter->slow_intr_mask | F_PL_INTR_SGE_DATA,
adapter->regs + A_PL_ENABLE);
schedule_work(&adapter->ext_intr_handler_task);
}
void t1_fatal_err(struct adapter *adapter)
{
if (adapter->flags & FULL_INIT_DONE) {
t1_sge_stop(adapter->sge);
t1_interrupts_disable(adapter);
}
pr_alert("%s: encountered fatal error, operation suspended\n",
adapter->name);
}
static int init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int i, err, pci_using_dac = 0;
unsigned long mmio_start, mmio_len;
const struct board_info *bi;
struct adapter *adapter = NULL;
struct port_info *pi;
pr_info_once("%s - version %s\n", DRV_DESCRIPTION, DRV_VERSION);
err = pci_enable_device(pdev);
if (err)
return err;
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
pr_err("%s: cannot find PCI device memory base address\n",
pci_name(pdev));
err = -ENODEV;
goto out_disable_pdev;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
pci_using_dac = 1;
if (pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64))) {
pr_err("%s: unable to obtain 64-bit DMA for "
"consistent allocations\n", pci_name(pdev));
err = -ENODEV;
goto out_disable_pdev;
}
} else if ((err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) != 0) {
pr_err("%s: no usable DMA configuration\n", pci_name(pdev));
goto out_disable_pdev;
}
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
pr_err("%s: cannot obtain PCI resources\n", pci_name(pdev));
goto out_disable_pdev;
}
pci_set_master(pdev);
mmio_start = pci_resource_start(pdev, 0);
mmio_len = pci_resource_len(pdev, 0);
bi = t1_get_board_info(ent->driver_data);
for (i = 0; i < bi->port_number; ++i) {
struct net_device *netdev;
netdev = alloc_etherdev(adapter ? 0 : sizeof(*adapter));
if (!netdev) {
err = -ENOMEM;
goto out_free_dev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
if (!adapter) {
adapter = netdev_priv(netdev);
adapter->pdev = pdev;
adapter->port[0].dev = netdev;
adapter->regs = ioremap(mmio_start, mmio_len);
if (!adapter->regs) {
pr_err("%s: cannot map device registers\n",
pci_name(pdev));
err = -ENOMEM;
goto out_free_dev;
}
if (t1_get_board_rev(adapter, bi, &adapter->params)) {
err = -ENODEV;
goto out_free_dev;
}
adapter->name = pci_name(pdev);
adapter->msg_enable = dflt_msg_enable;
adapter->mmio_len = mmio_len;
spin_lock_init(&adapter->tpi_lock);
spin_lock_init(&adapter->work_lock);
spin_lock_init(&adapter->async_lock);
spin_lock_init(&adapter->mac_lock);
INIT_WORK(&adapter->ext_intr_handler_task,
ext_intr_task);
INIT_DELAYED_WORK(&adapter->stats_update_task,
mac_stats_task);
pci_set_drvdata(pdev, netdev);
}
pi = &adapter->port[i];
pi->dev = netdev;
netif_carrier_off(netdev);
netdev->irq = pdev->irq;
netdev->if_port = i;
netdev->mem_start = mmio_start;
netdev->mem_end = mmio_start + mmio_len - 1;
netdev->ml_priv = adapter;
netdev->hw_features |= NETIF_F_SG | NETIF_F_IP_CSUM |
NETIF_F_RXCSUM;
netdev->features |= NETIF_F_SG | NETIF_F_IP_CSUM |
NETIF_F_RXCSUM | NETIF_F_LLTX;
if (pci_using_dac)
netdev->features |= NETIF_F_HIGHDMA;
if (vlan_tso_capable(adapter)) {
netdev->features |=
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX;
netdev->hw_features |= NETIF_F_HW_VLAN_CTAG_RX;
if (!(is_T2(adapter)) || bi->port_number != 4) {
netdev->hw_features |= NETIF_F_TSO;
netdev->features |= NETIF_F_TSO;
}
}
netdev->netdev_ops = &cxgb_netdev_ops;
netdev->hard_header_len += (netdev->hw_features & NETIF_F_TSO) ?
sizeof(struct cpl_tx_pkt_lso) : sizeof(struct cpl_tx_pkt);
netif_napi_add(netdev, &adapter->napi, t1_poll, 64);
SET_ETHTOOL_OPS(netdev, &t1_ethtool_ops);
}
if (t1_init_sw_modules(adapter, bi) < 0) {
err = -ENODEV;
goto out_free_dev;
}
for (i = 0; i < bi->port_number; ++i) {
err = register_netdev(adapter->port[i].dev);
if (err)
pr_warn("%s: cannot register net device %s, skipping\n",
pci_name(pdev), adapter->port[i].dev->name);
else {
if (!adapter->registered_device_map)
adapter->name = adapter->port[i].dev->name;
__set_bit(i, &adapter->registered_device_map);
}
}
if (!adapter->registered_device_map) {
pr_err("%s: could not register any net devices\n",
pci_name(pdev));
goto out_release_adapter_res;
}
pr_info("%s: %s (rev %d), %s %dMHz/%d-bit\n",
adapter->name, bi->desc, adapter->params.chip_revision,
adapter->params.pci.is_pcix ? "PCIX" : "PCI",
adapter->params.pci.speed, adapter->params.pci.width);
if (t1powersave)
adapter->t1powersave = LCLOCK;
else
adapter->t1powersave = HCLOCK;
if (t1_is_T1B(adapter))
t1_clock(adapter, t1powersave);
return 0;
out_release_adapter_res:
t1_free_sw_modules(adapter);
out_free_dev:
if (adapter) {
if (adapter->regs)
iounmap(adapter->regs);
for (i = bi->port_number - 1; i >= 0; --i)
if (adapter->port[i].dev)
free_netdev(adapter->port[i].dev);
}
pci_release_regions(pdev);
out_disable_pdev:
pci_disable_device(pdev);
return err;
}
static void bit_bang(struct adapter *adapter, int bitdata, int nbits)
{
int data;
int i;
u32 val;
enum {
S_CLOCK = 1 << 3,
S_DATA = 1 << 4
};
for (i = (nbits - 1); i > -1; i--) {
udelay(50);
data = ((bitdata >> i) & 0x1);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
if (data)
val |= S_DATA;
else
val &= ~S_DATA;
udelay(50);
val &= ~S_CLOCK;
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
val |= S_CLOCK;
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
}
}
static int t1_clock(struct adapter *adapter, int mode)
{
u32 val;
int M_CORE_VAL;
int M_MEM_VAL;
enum {
M_CORE_BITS = 9,
T_CORE_VAL = 0,
T_CORE_BITS = 2,
N_CORE_VAL = 0,
N_CORE_BITS = 2,
M_MEM_BITS = 9,
T_MEM_VAL = 0,
T_MEM_BITS = 2,
N_MEM_VAL = 0,
N_MEM_BITS = 2,
NP_LOAD = 1 << 17,
S_LOAD_MEM = 1 << 5,
S_LOAD_CORE = 1 << 6,
S_CLOCK = 1 << 3
};
if (!t1_is_T1B(adapter))
return -ENODEV;
if (mode & 2)
return 0;
if ((adapter->t1powersave & 1) == (mode & 1))
return -EALREADY;
if ((mode & 1) == HCLOCK) {
M_CORE_VAL = 0x14;
M_MEM_VAL = 0x18;
adapter->t1powersave = HCLOCK;
} else {
M_CORE_VAL = 0xe;
M_MEM_VAL = 0x10;
adapter->t1powersave = LCLOCK;
}
spin_lock(&adapter->tpi_lock);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val |= NP_LOAD;
udelay(50);
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val &= ~S_LOAD_CORE;
val &= ~S_CLOCK;
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
bit_bang(adapter, T_CORE_VAL, T_CORE_BITS);
bit_bang(adapter, N_CORE_VAL, N_CORE_BITS);
bit_bang(adapter, M_CORE_VAL, M_CORE_BITS);
udelay(50);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val |= S_LOAD_CORE;
udelay(50);
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val &= ~S_LOAD_CORE;
udelay(50);
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val |= NP_LOAD;
udelay(50);
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val &= ~S_LOAD_MEM;
val &= ~S_CLOCK;
udelay(50);
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
bit_bang(adapter, T_MEM_VAL, T_MEM_BITS);
bit_bang(adapter, N_MEM_VAL, N_MEM_BITS);
bit_bang(adapter, M_MEM_VAL, M_MEM_BITS);
udelay(50);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val |= S_LOAD_MEM;
udelay(50);
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(50);
__t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val &= ~S_LOAD_MEM;
udelay(50);
__t1_tpi_write(adapter, A_ELMER0_GPO, val);
spin_unlock(&adapter->tpi_lock);
return 0;
}
static inline void t1_sw_reset(struct pci_dev *pdev)
{
pci_write_config_dword(pdev, A_PCICFG_PM_CSR, 3);
pci_write_config_dword(pdev, A_PCICFG_PM_CSR, 0);
}
static void remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct adapter *adapter = dev->ml_priv;
int i;
for_each_port(adapter, i) {
if (test_bit(i, &adapter->registered_device_map))
unregister_netdev(adapter->port[i].dev);
}
t1_free_sw_modules(adapter);
iounmap(adapter->regs);
while (--i >= 0) {
if (adapter->port[i].dev)
free_netdev(adapter->port[i].dev);
}
pci_release_regions(pdev);
pci_disable_device(pdev);
t1_sw_reset(pdev);
}
