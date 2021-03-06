static int
bnad_get_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
cmd->supported = SUPPORTED_10000baseT_Full;
cmd->advertising = ADVERTISED_10000baseT_Full;
cmd->autoneg = AUTONEG_DISABLE;
cmd->supported |= SUPPORTED_FIBRE;
cmd->advertising |= ADVERTISED_FIBRE;
cmd->port = PORT_FIBRE;
cmd->phy_address = 0;
if (netif_carrier_ok(netdev)) {
ethtool_cmd_speed_set(cmd, SPEED_10000);
cmd->duplex = DUPLEX_FULL;
} else {
ethtool_cmd_speed_set(cmd, SPEED_UNKNOWN);
cmd->duplex = DUPLEX_UNKNOWN;
}
cmd->transceiver = XCVR_EXTERNAL;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static int
bnad_set_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
if (cmd->autoneg == AUTONEG_ENABLE)
return -EOPNOTSUPP; else {
if ((ethtool_cmd_speed(cmd) == SPEED_10000)
&& (cmd->duplex == DUPLEX_FULL))
return 0;
}
return -EOPNOTSUPP;
}
static void
bnad_get_drvinfo(struct net_device *netdev, struct ethtool_drvinfo *drvinfo)
{
struct bnad *bnad = netdev_priv(netdev);
struct bfa_ioc_attr *ioc_attr;
unsigned long flags;
strlcpy(drvinfo->driver, BNAD_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, BNAD_VERSION, sizeof(drvinfo->version));
ioc_attr = kzalloc(sizeof(*ioc_attr), GFP_KERNEL);
if (ioc_attr) {
spin_lock_irqsave(&bnad->bna_lock, flags);
bfa_nw_ioc_get_attr(&bnad->bna.ioceth.ioc, ioc_attr);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
strlcpy(drvinfo->fw_version, ioc_attr->adapter_attr.fw_ver,
sizeof(drvinfo->fw_version));
kfree(ioc_attr);
}
strlcpy(drvinfo->bus_info, pci_name(bnad->pcidev),
sizeof(drvinfo->bus_info));
}
static void
bnad_get_wol(struct net_device *netdev, struct ethtool_wolinfo *wolinfo)
{
wolinfo->supported = 0;
wolinfo->wolopts = 0;
}
static int
bnad_get_coalesce(struct net_device *netdev, struct ethtool_coalesce *coalesce)
{
struct bnad *bnad = netdev_priv(netdev);
unsigned long flags;
spin_lock_irqsave(&bnad->bna_lock, flags);
coalesce->use_adaptive_rx_coalesce =
(bnad->cfg_flags & BNAD_CF_DIM_ENABLED) ? true : false;
spin_unlock_irqrestore(&bnad->bna_lock, flags);
coalesce->rx_coalesce_usecs = bnad->rx_coalescing_timeo *
BFI_COALESCING_TIMER_UNIT;
coalesce->tx_coalesce_usecs = bnad->tx_coalescing_timeo *
BFI_COALESCING_TIMER_UNIT;
coalesce->tx_max_coalesced_frames = BFI_TX_INTERPKT_COUNT;
return 0;
}
static int
bnad_set_coalesce(struct net_device *netdev, struct ethtool_coalesce *coalesce)
{
struct bnad *bnad = netdev_priv(netdev);
unsigned long flags;
int to_del = 0;
if (coalesce->rx_coalesce_usecs == 0 ||
coalesce->rx_coalesce_usecs >
BFI_MAX_COALESCING_TIMEO * BFI_COALESCING_TIMER_UNIT)
return -EINVAL;
if (coalesce->tx_coalesce_usecs == 0 ||
coalesce->tx_coalesce_usecs >
BFI_MAX_COALESCING_TIMEO * BFI_COALESCING_TIMER_UNIT)
return -EINVAL;
mutex_lock(&bnad->conf_mutex);
spin_lock_irqsave(&bnad->bna_lock, flags);
if (coalesce->use_adaptive_rx_coalesce) {
if (!(bnad->cfg_flags & BNAD_CF_DIM_ENABLED)) {
bnad->cfg_flags |= BNAD_CF_DIM_ENABLED;
bnad_dim_timer_start(bnad);
}
} else {
if (bnad->cfg_flags & BNAD_CF_DIM_ENABLED) {
bnad->cfg_flags &= ~BNAD_CF_DIM_ENABLED;
if (bnad->cfg_flags & BNAD_CF_DIM_ENABLED &&
test_bit(BNAD_RF_DIM_TIMER_RUNNING,
&bnad->run_flags)) {
clear_bit(BNAD_RF_DIM_TIMER_RUNNING,
&bnad->run_flags);
to_del = 1;
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
if (to_del)
del_timer_sync(&bnad->dim_timer);
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad_rx_coalescing_timeo_set(bnad);
}
}
if (bnad->tx_coalescing_timeo != coalesce->tx_coalesce_usecs /
BFI_COALESCING_TIMER_UNIT) {
bnad->tx_coalescing_timeo = coalesce->tx_coalesce_usecs /
BFI_COALESCING_TIMER_UNIT;
bnad_tx_coalescing_timeo_set(bnad);
}
if (bnad->rx_coalescing_timeo != coalesce->rx_coalesce_usecs /
BFI_COALESCING_TIMER_UNIT) {
bnad->rx_coalescing_timeo = coalesce->rx_coalesce_usecs /
BFI_COALESCING_TIMER_UNIT;
if (!(bnad->cfg_flags & BNAD_CF_DIM_ENABLED))
bnad_rx_coalescing_timeo_set(bnad);
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
return 0;
}
static void
bnad_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ringparam)
{
struct bnad *bnad = netdev_priv(netdev);
ringparam->rx_max_pending = BNAD_MAX_RXQ_DEPTH;
ringparam->tx_max_pending = BNAD_MAX_TXQ_DEPTH;
ringparam->rx_pending = bnad->rxq_depth;
ringparam->tx_pending = bnad->txq_depth;
}
static int
bnad_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ringparam)
{
int i, current_err, err = 0;
struct bnad *bnad = netdev_priv(netdev);
unsigned long flags;
mutex_lock(&bnad->conf_mutex);
if (ringparam->rx_pending == bnad->rxq_depth &&
ringparam->tx_pending == bnad->txq_depth) {
mutex_unlock(&bnad->conf_mutex);
return 0;
}
if (ringparam->rx_pending < BNAD_MIN_Q_DEPTH ||
ringparam->rx_pending > BNAD_MAX_RXQ_DEPTH ||
!BNA_POWER_OF_2(ringparam->rx_pending)) {
mutex_unlock(&bnad->conf_mutex);
return -EINVAL;
}
if (ringparam->tx_pending < BNAD_MIN_Q_DEPTH ||
ringparam->tx_pending > BNAD_MAX_TXQ_DEPTH ||
!BNA_POWER_OF_2(ringparam->tx_pending)) {
mutex_unlock(&bnad->conf_mutex);
return -EINVAL;
}
if (ringparam->rx_pending != bnad->rxq_depth) {
bnad->rxq_depth = ringparam->rx_pending;
if (!netif_running(netdev)) {
mutex_unlock(&bnad->conf_mutex);
return 0;
}
for (i = 0; i < bnad->num_rx; i++) {
if (!bnad->rx_info[i].rx)
continue;
bnad_destroy_rx(bnad, i);
current_err = bnad_setup_rx(bnad, i);
if (current_err && !err)
err = current_err;
}
if (!err && bnad->rx_info[0].rx) {
bnad_restore_vlans(bnad, 0);
bnad_enable_default_bcast(bnad);
spin_lock_irqsave(&bnad->bna_lock, flags);
bnad_mac_addr_set_locked(bnad, netdev->dev_addr);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
bnad->cfg_flags &= ~(BNAD_CF_ALLMULTI |
BNAD_CF_PROMISC);
bnad_set_rx_mode(netdev);
}
}
if (ringparam->tx_pending != bnad->txq_depth) {
bnad->txq_depth = ringparam->tx_pending;
if (!netif_running(netdev)) {
mutex_unlock(&bnad->conf_mutex);
return 0;
}
for (i = 0; i < bnad->num_tx; i++) {
if (!bnad->tx_info[i].tx)
continue;
bnad_destroy_tx(bnad, i);
current_err = bnad_setup_tx(bnad, i);
if (current_err && !err)
err = current_err;
}
}
mutex_unlock(&bnad->conf_mutex);
return err;
}
static void
bnad_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pauseparam)
{
struct bnad *bnad = netdev_priv(netdev);
pauseparam->autoneg = 0;
pauseparam->rx_pause = bnad->bna.enet.pause_config.rx_pause;
pauseparam->tx_pause = bnad->bna.enet.pause_config.tx_pause;
}
static int
bnad_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pauseparam)
{
struct bnad *bnad = netdev_priv(netdev);
struct bna_pause_config pause_config;
unsigned long flags;
if (pauseparam->autoneg == AUTONEG_ENABLE)
return -EINVAL;
mutex_lock(&bnad->conf_mutex);
if (pauseparam->rx_pause != bnad->bna.enet.pause_config.rx_pause ||
pauseparam->tx_pause != bnad->bna.enet.pause_config.tx_pause) {
pause_config.rx_pause = pauseparam->rx_pause;
pause_config.tx_pause = pauseparam->tx_pause;
spin_lock_irqsave(&bnad->bna_lock, flags);
bna_enet_pause_config(&bnad->bna.enet, &pause_config, NULL);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
}
mutex_unlock(&bnad->conf_mutex);
return 0;
}
static void
bnad_get_strings(struct net_device *netdev, u32 stringset, u8 *string)
{
struct bnad *bnad = netdev_priv(netdev);
int i, j, q_num;
u32 bmap;
mutex_lock(&bnad->conf_mutex);
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < BNAD_ETHTOOL_STATS_NUM; i++) {
BUG_ON(!(strlen(bnad_net_stats_strings[i]) <
ETH_GSTRING_LEN));
memcpy(string, bnad_net_stats_strings[i],
ETH_GSTRING_LEN);
string += ETH_GSTRING_LEN;
}
bmap = bna_tx_rid_mask(&bnad->bna);
for (i = 0; bmap; i++) {
if (bmap & 1) {
sprintf(string, "txf%d_ucast_octets", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_ucast", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_ucast_vlan", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_mcast_octets", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_mcast", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_mcast_vlan", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_bcast_octets", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_bcast", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_bcast_vlan", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_errors", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_filter_vlan", i);
string += ETH_GSTRING_LEN;
sprintf(string, "txf%d_filter_mac_sa", i);
string += ETH_GSTRING_LEN;
}
bmap >>= 1;
}
bmap = bna_rx_rid_mask(&bnad->bna);
for (i = 0; bmap; i++) {
if (bmap & 1) {
sprintf(string, "rxf%d_ucast_octets", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_ucast", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_ucast_vlan", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_mcast_octets", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_mcast", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_mcast_vlan", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_bcast_octets", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_bcast", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_bcast_vlan", i);
string += ETH_GSTRING_LEN;
sprintf(string, "rxf%d_frame_drops", i);
string += ETH_GSTRING_LEN;
}
bmap >>= 1;
}
q_num = 0;
for (i = 0; i < bnad->num_rx; i++) {
if (!bnad->rx_info[i].rx)
continue;
for (j = 0; j < bnad->num_rxp_per_rx; j++) {
sprintf(string, "cq%d_producer_index", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "cq%d_consumer_index", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "cq%d_hw_producer_index",
q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "cq%d_intr", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "cq%d_poll", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "cq%d_schedule", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "cq%d_keep_poll", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "cq%d_complete", q_num);
string += ETH_GSTRING_LEN;
q_num++;
}
}
q_num = 0;
for (i = 0; i < bnad->num_rx; i++) {
if (!bnad->rx_info[i].rx)
continue;
for (j = 0; j < bnad->num_rxp_per_rx; j++) {
sprintf(string, "rxq%d_packets", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_bytes", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_packets_with_error",
q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_allocbuf_failed", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_producer_index", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_consumer_index", q_num);
string += ETH_GSTRING_LEN;
q_num++;
if (bnad->rx_info[i].rx_ctrl[j].ccb &&
bnad->rx_info[i].rx_ctrl[j].ccb->
rcb[1] &&
bnad->rx_info[i].rx_ctrl[j].ccb->
rcb[1]->rxq) {
sprintf(string, "rxq%d_packets", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_bytes", q_num);
string += ETH_GSTRING_LEN;
sprintf(string,
"rxq%d_packets_with_error", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_allocbuf_failed",
q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_producer_index",
q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "rxq%d_consumer_index",
q_num);
string += ETH_GSTRING_LEN;
q_num++;
}
}
}
q_num = 0;
for (i = 0; i < bnad->num_tx; i++) {
if (!bnad->tx_info[i].tx)
continue;
for (j = 0; j < bnad->num_txq_per_tx; j++) {
sprintf(string, "txq%d_packets", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "txq%d_bytes", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "txq%d_producer_index", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "txq%d_consumer_index", q_num);
string += ETH_GSTRING_LEN;
sprintf(string, "txq%d_hw_consumer_index",
q_num);
string += ETH_GSTRING_LEN;
q_num++;
}
}
break;
default:
break;
}
mutex_unlock(&bnad->conf_mutex);
}
static int
bnad_get_stats_count_locked(struct net_device *netdev)
{
struct bnad *bnad = netdev_priv(netdev);
int i, j, count = 0, rxf_active_num = 0, txf_active_num = 0;
u32 bmap;
bmap = bna_tx_rid_mask(&bnad->bna);
for (i = 0; bmap; i++) {
if (bmap & 1)
txf_active_num++;
bmap >>= 1;
}
bmap = bna_rx_rid_mask(&bnad->bna);
for (i = 0; bmap; i++) {
if (bmap & 1)
rxf_active_num++;
bmap >>= 1;
}
count = BNAD_ETHTOOL_STATS_NUM +
txf_active_num * BNAD_NUM_TXF_COUNTERS +
rxf_active_num * BNAD_NUM_RXF_COUNTERS;
for (i = 0; i < bnad->num_rx; i++) {
if (!bnad->rx_info[i].rx)
continue;
count += bnad->num_rxp_per_rx * BNAD_NUM_CQ_COUNTERS;
count += bnad->num_rxp_per_rx * BNAD_NUM_RXQ_COUNTERS;
for (j = 0; j < bnad->num_rxp_per_rx; j++)
if (bnad->rx_info[i].rx_ctrl[j].ccb &&
bnad->rx_info[i].rx_ctrl[j].ccb->rcb[1] &&
bnad->rx_info[i].rx_ctrl[j].ccb->rcb[1]->rxq)
count += BNAD_NUM_RXQ_COUNTERS;
}
for (i = 0; i < bnad->num_tx; i++) {
if (!bnad->tx_info[i].tx)
continue;
count += bnad->num_txq_per_tx * BNAD_NUM_TXQ_COUNTERS;
}
return count;
}
static int
bnad_per_q_stats_fill(struct bnad *bnad, u64 *buf, int bi)
{
int i, j;
struct bna_rcb *rcb = NULL;
struct bna_tcb *tcb = NULL;
for (i = 0; i < bnad->num_rx; i++) {
if (!bnad->rx_info[i].rx)
continue;
for (j = 0; j < bnad->num_rxp_per_rx; j++)
if (bnad->rx_info[i].rx_ctrl[j].ccb &&
bnad->rx_info[i].rx_ctrl[j].ccb->rcb[0] &&
bnad->rx_info[i].rx_ctrl[j].ccb->rcb[0]->rxq) {
buf[bi++] = bnad->rx_info[i].rx_ctrl[j].
ccb->producer_index;
buf[bi++] = 0;
buf[bi++] = *(bnad->rx_info[i].rx_ctrl[j].
ccb->hw_producer_index);
buf[bi++] = bnad->rx_info[i].
rx_ctrl[j].rx_intr_ctr;
buf[bi++] = bnad->rx_info[i].
rx_ctrl[j].rx_poll_ctr;
buf[bi++] = bnad->rx_info[i].
rx_ctrl[j].rx_schedule;
buf[bi++] = bnad->rx_info[i].
rx_ctrl[j].rx_keep_poll;
buf[bi++] = bnad->rx_info[i].
rx_ctrl[j].rx_complete;
}
}
for (i = 0; i < bnad->num_rx; i++) {
if (!bnad->rx_info[i].rx)
continue;
for (j = 0; j < bnad->num_rxp_per_rx; j++)
if (bnad->rx_info[i].rx_ctrl[j].ccb) {
if (bnad->rx_info[i].rx_ctrl[j].ccb->rcb[0] &&
bnad->rx_info[i].rx_ctrl[j].ccb->
rcb[0]->rxq) {
rcb = bnad->rx_info[i].rx_ctrl[j].
ccb->rcb[0];
buf[bi++] = rcb->rxq->rx_packets;
buf[bi++] = rcb->rxq->rx_bytes;
buf[bi++] = rcb->rxq->
rx_packets_with_error;
buf[bi++] = rcb->rxq->
rxbuf_alloc_failed;
buf[bi++] = rcb->producer_index;
buf[bi++] = rcb->consumer_index;
}
if (bnad->rx_info[i].rx_ctrl[j].ccb->rcb[1] &&
bnad->rx_info[i].rx_ctrl[j].ccb->
rcb[1]->rxq) {
rcb = bnad->rx_info[i].rx_ctrl[j].
ccb->rcb[1];
buf[bi++] = rcb->rxq->rx_packets;
buf[bi++] = rcb->rxq->rx_bytes;
buf[bi++] = rcb->rxq->
rx_packets_with_error;
buf[bi++] = rcb->rxq->
rxbuf_alloc_failed;
buf[bi++] = rcb->producer_index;
buf[bi++] = rcb->consumer_index;
}
}
}
for (i = 0; i < bnad->num_tx; i++) {
if (!bnad->tx_info[i].tx)
continue;
for (j = 0; j < bnad->num_txq_per_tx; j++)
if (bnad->tx_info[i].tcb[j] &&
bnad->tx_info[i].tcb[j]->txq) {
tcb = bnad->tx_info[i].tcb[j];
buf[bi++] = tcb->txq->tx_packets;
buf[bi++] = tcb->txq->tx_bytes;
buf[bi++] = tcb->producer_index;
buf[bi++] = tcb->consumer_index;
buf[bi++] = *(tcb->hw_consumer_index);
}
}
return bi;
}
static void
bnad_get_ethtool_stats(struct net_device *netdev, struct ethtool_stats *stats,
u64 *buf)
{
struct bnad *bnad = netdev_priv(netdev);
int i, j, bi;
unsigned long flags;
struct rtnl_link_stats64 *net_stats64;
u64 *stats64;
u32 bmap;
mutex_lock(&bnad->conf_mutex);
if (bnad_get_stats_count_locked(netdev) != stats->n_stats) {
mutex_unlock(&bnad->conf_mutex);
return;
}
spin_lock_irqsave(&bnad->bna_lock, flags);
bi = 0;
memset(buf, 0, stats->n_stats * sizeof(u64));
net_stats64 = (struct rtnl_link_stats64 *)buf;
bnad_netdev_qstats_fill(bnad, net_stats64);
bnad_netdev_hwstats_fill(bnad, net_stats64);
bi = sizeof(*net_stats64) / sizeof(u64);
bnad->stats.drv_stats.netif_queue_stopped = netif_queue_stopped(netdev);
stats64 = (u64 *)&bnad->stats.drv_stats;
for (i = 0; i < sizeof(struct bnad_drv_stats) / sizeof(u64); i++)
buf[bi++] = stats64[i];
stats64 = (u64 *) &bnad->stats.bna_stats->hw_stats;
for (i = 0;
i < offsetof(struct bfi_enet_stats, rxf_stats[0]) /
sizeof(u64);
i++)
buf[bi++] = stats64[i];
bmap = bna_tx_rid_mask(&bnad->bna);
for (i = 0; bmap; i++) {
if (bmap & 1) {
stats64 = (u64 *)&bnad->stats.bna_stats->
hw_stats.txf_stats[i];
for (j = 0; j < sizeof(struct bfi_enet_stats_txf) /
sizeof(u64); j++)
buf[bi++] = stats64[j];
}
bmap >>= 1;
}
bmap = bna_rx_rid_mask(&bnad->bna);
for (i = 0; bmap; i++) {
if (bmap & 1) {
stats64 = (u64 *)&bnad->stats.bna_stats->
hw_stats.rxf_stats[i];
for (j = 0; j < sizeof(struct bfi_enet_stats_rxf) /
sizeof(u64); j++)
buf[bi++] = stats64[j];
}
bmap >>= 1;
}
bi = bnad_per_q_stats_fill(bnad, buf, bi);
spin_unlock_irqrestore(&bnad->bna_lock, flags);
mutex_unlock(&bnad->conf_mutex);
}
static int
bnad_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return bnad_get_stats_count_locked(netdev);
default:
return -EOPNOTSUPP;
}
}
static u32
bnad_get_flash_partition_by_offset(struct bnad *bnad, u32 offset,
u32 *base_offset)
{
struct bfa_flash_attr *flash_attr;
struct bnad_iocmd_comp fcomp;
u32 i, flash_part = 0, ret;
unsigned long flags = 0;
flash_attr = kzalloc(sizeof(struct bfa_flash_attr), GFP_KERNEL);
if (!flash_attr)
return 0;
fcomp.bnad = bnad;
fcomp.comp_status = 0;
init_completion(&fcomp.comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
ret = bfa_nw_flash_get_attr(&bnad->bna.flash, flash_attr,
bnad_cb_completion, &fcomp);
if (ret != BFA_STATUS_OK) {
spin_unlock_irqrestore(&bnad->bna_lock, flags);
kfree(flash_attr);
return 0;
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&fcomp.comp);
ret = fcomp.comp_status;
if (ret == BFA_STATUS_OK) {
for (i = 0; i < flash_attr->npart; i++) {
if (offset >= flash_attr->part[i].part_off &&
offset < (flash_attr->part[i].part_off +
flash_attr->part[i].part_size)) {
flash_part = flash_attr->part[i].part_type;
*base_offset = flash_attr->part[i].part_off;
break;
}
}
}
kfree(flash_attr);
return flash_part;
}
static int
bnad_get_eeprom_len(struct net_device *netdev)
{
return BFA_TOTAL_FLASH_SIZE;
}
static int
bnad_get_eeprom(struct net_device *netdev, struct ethtool_eeprom *eeprom,
u8 *bytes)
{
struct bnad *bnad = netdev_priv(netdev);
struct bnad_iocmd_comp fcomp;
u32 flash_part = 0, base_offset = 0;
unsigned long flags = 0;
int ret = 0;
eeprom->magic = bnad->pcidev->vendor | (bnad->pcidev->device << 16);
flash_part = bnad_get_flash_partition_by_offset(bnad,
eeprom->offset, &base_offset);
if (flash_part == 0)
return -EFAULT;
fcomp.bnad = bnad;
fcomp.comp_status = 0;
init_completion(&fcomp.comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
ret = bfa_nw_flash_read_part(&bnad->bna.flash, flash_part,
bnad->id, bytes, eeprom->len,
eeprom->offset - base_offset,
bnad_cb_completion, &fcomp);
if (ret != BFA_STATUS_OK) {
spin_unlock_irqrestore(&bnad->bna_lock, flags);
goto done;
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&fcomp.comp);
ret = fcomp.comp_status;
done:
return ret;
}
static int
bnad_set_eeprom(struct net_device *netdev, struct ethtool_eeprom *eeprom,
u8 *bytes)
{
struct bnad *bnad = netdev_priv(netdev);
struct bnad_iocmd_comp fcomp;
u32 flash_part = 0, base_offset = 0;
unsigned long flags = 0;
int ret = 0;
if (eeprom->magic != (bnad->pcidev->vendor |
(bnad->pcidev->device << 16)))
return -EINVAL;
flash_part = bnad_get_flash_partition_by_offset(bnad,
eeprom->offset, &base_offset);
if (flash_part == 0)
return -EFAULT;
fcomp.bnad = bnad;
fcomp.comp_status = 0;
init_completion(&fcomp.comp);
spin_lock_irqsave(&bnad->bna_lock, flags);
ret = bfa_nw_flash_update_part(&bnad->bna.flash, flash_part,
bnad->id, bytes, eeprom->len,
eeprom->offset - base_offset,
bnad_cb_completion, &fcomp);
if (ret != BFA_STATUS_OK) {
spin_unlock_irqrestore(&bnad->bna_lock, flags);
goto done;
}
spin_unlock_irqrestore(&bnad->bna_lock, flags);
wait_for_completion(&fcomp.comp);
ret = fcomp.comp_status;
done:
return ret;
}
static int
bnad_flash_device(struct net_device *netdev, struct ethtool_flash *eflash)
{
struct bnad *bnad = netdev_priv(netdev);
struct bnad_iocmd_comp fcomp;
const struct firmware *fw;
int ret = 0;
ret = request_firmware(&fw, eflash->data, &bnad->pcidev->dev);
if (ret) {
pr_err("BNA: Can't locate firmware %s\n", eflash->data);
goto out;
}
fcomp.bnad = bnad;
fcomp.comp_status = 0;
init_completion(&fcomp.comp);
spin_lock_irq(&bnad->bna_lock);
ret = bfa_nw_flash_update_part(&bnad->bna.flash, BFA_FLASH_PART_FWIMG,
bnad->id, (u8 *)fw->data, fw->size, 0,
bnad_cb_completion, &fcomp);
if (ret != BFA_STATUS_OK) {
pr_warn("BNA: Flash update failed with err: %d\n", ret);
ret = -EIO;
spin_unlock_irq(&bnad->bna_lock);
goto out;
}
spin_unlock_irq(&bnad->bna_lock);
wait_for_completion(&fcomp.comp);
if (fcomp.comp_status != BFA_STATUS_OK) {
ret = -EIO;
pr_warn("BNA: Firmware image update to flash failed with: %d\n",
fcomp.comp_status);
}
out:
release_firmware(fw);
return ret;
}
void
bnad_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &bnad_ethtool_ops;
}
