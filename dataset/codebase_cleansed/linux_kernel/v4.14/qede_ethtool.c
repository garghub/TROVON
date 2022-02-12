static void qede_get_strings_stats_txq(struct qede_dev *edev,
struct qede_tx_queue *txq, u8 **buf)
{
int i;
for (i = 0; i < QEDE_NUM_TQSTATS; i++) {
if (txq->is_xdp)
sprintf(*buf, "%d [XDP]: %s",
QEDE_TXQ_XDP_TO_IDX(edev, txq),
qede_tqstats_arr[i].string);
else
sprintf(*buf, "%d: %s", txq->index,
qede_tqstats_arr[i].string);
*buf += ETH_GSTRING_LEN;
}
}
static void qede_get_strings_stats_rxq(struct qede_dev *edev,
struct qede_rx_queue *rxq, u8 **buf)
{
int i;
for (i = 0; i < QEDE_NUM_RQSTATS; i++) {
sprintf(*buf, "%d: %s", rxq->rxq_id,
qede_rqstats_arr[i].string);
*buf += ETH_GSTRING_LEN;
}
}
static bool qede_is_irrelevant_stat(struct qede_dev *edev, int stat_index)
{
return (IS_VF(edev) && QEDE_STAT_IS_PF_ONLY(stat_index)) ||
(QEDE_IS_BB(edev) && QEDE_STAT_IS_AH_ONLY(stat_index)) ||
(QEDE_IS_AH(edev) && QEDE_STAT_IS_BB_ONLY(stat_index));
}
static void qede_get_strings_stats(struct qede_dev *edev, u8 *buf)
{
struct qede_fastpath *fp;
int i;
for (i = 0; i < QEDE_QUEUE_CNT(edev); i++) {
fp = &edev->fp_array[i];
if (fp->type & QEDE_FASTPATH_RX)
qede_get_strings_stats_rxq(edev, fp->rxq, &buf);
if (fp->type & QEDE_FASTPATH_XDP)
qede_get_strings_stats_txq(edev, fp->xdp_tx, &buf);
if (fp->type & QEDE_FASTPATH_TX)
qede_get_strings_stats_txq(edev, fp->txq, &buf);
}
for (i = 0; i < QEDE_NUM_STATS; i++) {
if (qede_is_irrelevant_stat(edev, i))
continue;
strcpy(buf, qede_stats_arr[i].string);
buf += ETH_GSTRING_LEN;
}
}
static void qede_get_strings(struct net_device *dev, u32 stringset, u8 *buf)
{
struct qede_dev *edev = netdev_priv(dev);
switch (stringset) {
case ETH_SS_STATS:
qede_get_strings_stats(edev, buf);
break;
case ETH_SS_PRIV_FLAGS:
memcpy(buf, qede_private_arr,
ETH_GSTRING_LEN * QEDE_PRI_FLAG_LEN);
break;
case ETH_SS_TEST:
memcpy(buf, qede_tests_str_arr,
ETH_GSTRING_LEN * QEDE_ETHTOOL_TEST_MAX);
break;
default:
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Unsupported stringset 0x%08x\n", stringset);
}
}
static void qede_get_ethtool_stats_txq(struct qede_tx_queue *txq, u64 **buf)
{
int i;
for (i = 0; i < QEDE_NUM_TQSTATS; i++) {
**buf = *((u64 *)(((void *)txq) + qede_tqstats_arr[i].offset));
(*buf)++;
}
}
static void qede_get_ethtool_stats_rxq(struct qede_rx_queue *rxq, u64 **buf)
{
int i;
for (i = 0; i < QEDE_NUM_RQSTATS; i++) {
**buf = *((u64 *)(((void *)rxq) + qede_rqstats_arr[i].offset));
(*buf)++;
}
}
static void qede_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *buf)
{
struct qede_dev *edev = netdev_priv(dev);
struct qede_fastpath *fp;
int i;
qede_fill_by_demand_stats(edev);
__qede_lock(edev);
for (i = 0; i < QEDE_QUEUE_CNT(edev); i++) {
fp = &edev->fp_array[i];
if (fp->type & QEDE_FASTPATH_RX)
qede_get_ethtool_stats_rxq(fp->rxq, &buf);
if (fp->type & QEDE_FASTPATH_XDP)
qede_get_ethtool_stats_txq(fp->xdp_tx, &buf);
if (fp->type & QEDE_FASTPATH_TX)
qede_get_ethtool_stats_txq(fp->txq, &buf);
}
for (i = 0; i < QEDE_NUM_STATS; i++) {
if (qede_is_irrelevant_stat(edev, i))
continue;
*buf = *((u64 *)(((void *)&edev->stats) +
qede_stats_arr[i].offset));
buf++;
}
__qede_unlock(edev);
}
static int qede_get_sset_count(struct net_device *dev, int stringset)
{
struct qede_dev *edev = netdev_priv(dev);
int num_stats = QEDE_NUM_STATS, i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < QEDE_NUM_STATS; i++)
if (qede_is_irrelevant_stat(edev, i))
num_stats--;
num_stats += QEDE_TSS_COUNT(edev) * QEDE_NUM_TQSTATS;
num_stats += QEDE_RSS_COUNT(edev) * QEDE_NUM_RQSTATS;
if (edev->xdp_prog)
num_stats += QEDE_RSS_COUNT(edev) * QEDE_NUM_TQSTATS;
return num_stats;
case ETH_SS_PRIV_FLAGS:
return QEDE_PRI_FLAG_LEN;
case ETH_SS_TEST:
if (!IS_VF(edev))
return QEDE_ETHTOOL_TEST_MAX;
else
return 0;
default:
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Unsupported stringset 0x%08x\n", stringset);
return -EINVAL;
}
}
static u32 qede_get_priv_flags(struct net_device *dev)
{
struct qede_dev *edev = netdev_priv(dev);
return (!!(edev->dev_info.common.num_hwfns > 1)) << QEDE_PRI_FLAG_CMT;
}
static int qede_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *cmd)
{
struct ethtool_link_settings *base = &cmd->base;
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
__qede_lock(edev);
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
ethtool_link_ksettings_zero_link_mode(cmd, supported);
QEDE_DRV_TO_ETHTOOL_CAPS(current_link.supported_caps, cmd, supported)
ethtool_link_ksettings_zero_link_mode(cmd, advertising);
QEDE_DRV_TO_ETHTOOL_CAPS(current_link.advertised_caps, cmd, advertising)
ethtool_link_ksettings_zero_link_mode(cmd, lp_advertising);
QEDE_DRV_TO_ETHTOOL_CAPS(current_link.lp_caps, cmd, lp_advertising)
if ((edev->state == QEDE_STATE_OPEN) && (current_link.link_up)) {
base->speed = current_link.speed;
base->duplex = current_link.duplex;
} else {
base->speed = SPEED_UNKNOWN;
base->duplex = DUPLEX_UNKNOWN;
}
__qede_unlock(edev);
base->port = current_link.port;
base->autoneg = (current_link.autoneg) ? AUTONEG_ENABLE :
AUTONEG_DISABLE;
return 0;
}
static int qede_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *cmd)
{
const struct ethtool_link_settings *base = &cmd->base;
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
struct qed_link_params params;
if (!edev->ops || !edev->ops->common->can_link_change(edev->cdev)) {
DP_INFO(edev, "Link settings are not allowed to be changed\n");
return -EOPNOTSUPP;
}
memset(&current_link, 0, sizeof(current_link));
memset(&params, 0, sizeof(params));
edev->ops->common->get_link(edev->cdev, &current_link);
params.override_flags |= QED_LINK_OVERRIDE_SPEED_ADV_SPEEDS;
params.override_flags |= QED_LINK_OVERRIDE_SPEED_AUTONEG;
if (base->autoneg == AUTONEG_ENABLE) {
if (!(current_link.supported_caps & QED_LM_Autoneg_BIT)) {
DP_INFO(edev, "Auto negotiation is not supported\n");
return -EOPNOTSUPP;
}
params.autoneg = true;
params.forced_speed = 0;
QEDE_ETHTOOL_TO_DRV_CAPS(params.adv_speeds, cmd, advertising)
} else {
params.override_flags |= QED_LINK_OVERRIDE_SPEED_FORCED_SPEED;
params.autoneg = false;
params.forced_speed = base->speed;
switch (base->speed) {
case SPEED_1000:
if (!(current_link.supported_caps &
QED_LM_1000baseT_Full_BIT)) {
DP_INFO(edev, "1G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = QED_LM_1000baseT_Full_BIT;
break;
case SPEED_10000:
if (!(current_link.supported_caps &
QED_LM_10000baseKR_Full_BIT)) {
DP_INFO(edev, "10G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = QED_LM_10000baseKR_Full_BIT;
break;
case SPEED_25000:
if (!(current_link.supported_caps &
QED_LM_25000baseKR_Full_BIT)) {
DP_INFO(edev, "25G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = QED_LM_25000baseKR_Full_BIT;
break;
case SPEED_40000:
if (!(current_link.supported_caps &
QED_LM_40000baseLR4_Full_BIT)) {
DP_INFO(edev, "40G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = QED_LM_40000baseLR4_Full_BIT;
break;
case SPEED_50000:
if (!(current_link.supported_caps &
QED_LM_50000baseKR2_Full_BIT)) {
DP_INFO(edev, "50G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = QED_LM_50000baseKR2_Full_BIT;
break;
case SPEED_100000:
if (!(current_link.supported_caps &
QED_LM_100000baseKR4_Full_BIT)) {
DP_INFO(edev, "100G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = QED_LM_100000baseKR4_Full_BIT;
break;
default:
DP_INFO(edev, "Unsupported speed %u\n", base->speed);
return -EINVAL;
}
}
params.link_up = true;
edev->ops->common->set_link(edev->cdev, &params);
return 0;
}
static void qede_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
char mfw[ETHTOOL_FWVERS_LEN], storm[ETHTOOL_FWVERS_LEN];
struct qede_dev *edev = netdev_priv(ndev);
strlcpy(info->driver, "qede", sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
snprintf(storm, ETHTOOL_FWVERS_LEN, "%d.%d.%d.%d",
edev->dev_info.common.fw_major,
edev->dev_info.common.fw_minor,
edev->dev_info.common.fw_rev,
edev->dev_info.common.fw_eng);
snprintf(mfw, ETHTOOL_FWVERS_LEN, "%d.%d.%d.%d",
(edev->dev_info.common.mfw_rev >> 24) & 0xFF,
(edev->dev_info.common.mfw_rev >> 16) & 0xFF,
(edev->dev_info.common.mfw_rev >> 8) & 0xFF,
edev->dev_info.common.mfw_rev & 0xFF);
if ((strlen(storm) + strlen(mfw) + strlen("mfw storm ")) <
sizeof(info->fw_version)) {
snprintf(info->fw_version, sizeof(info->fw_version),
"mfw %s storm %s", mfw, storm);
} else {
snprintf(info->fw_version, sizeof(info->fw_version),
"%s %s", mfw, storm);
}
strlcpy(info->bus_info, pci_name(edev->pdev), sizeof(info->bus_info));
}
static void qede_get_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct qede_dev *edev = netdev_priv(ndev);
if (edev->dev_info.common.wol_support) {
wol->supported = WAKE_MAGIC;
wol->wolopts = edev->wol_enabled ? WAKE_MAGIC : 0;
}
}
static int qede_set_wol(struct net_device *ndev, struct ethtool_wolinfo *wol)
{
struct qede_dev *edev = netdev_priv(ndev);
bool wol_requested;
int rc;
if (wol->wolopts & ~WAKE_MAGIC) {
DP_INFO(edev,
"Can't support WoL options other than magic-packet\n");
return -EINVAL;
}
wol_requested = !!(wol->wolopts & WAKE_MAGIC);
if (wol_requested == edev->wol_enabled)
return 0;
if (!edev->dev_info.common.wol_support) {
DP_INFO(edev, "Device doesn't support WoL\n");
return -EINVAL;
}
rc = edev->ops->common->update_wol(edev->cdev, wol_requested);
if (!rc)
edev->wol_enabled = wol_requested;
return rc;
}
static u32 qede_get_msglevel(struct net_device *ndev)
{
struct qede_dev *edev = netdev_priv(ndev);
return ((u32)edev->dp_level << QED_LOG_LEVEL_SHIFT) | edev->dp_module;
}
static void qede_set_msglevel(struct net_device *ndev, u32 level)
{
struct qede_dev *edev = netdev_priv(ndev);
u32 dp_module = 0;
u8 dp_level = 0;
qede_config_debug(level, &dp_module, &dp_level);
edev->dp_level = dp_level;
edev->dp_module = dp_module;
edev->ops->common->update_msglvl(edev->cdev,
dp_module, dp_level);
}
static int qede_nway_reset(struct net_device *dev)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
struct qed_link_params link_params;
if (!edev->ops || !edev->ops->common->can_link_change(edev->cdev)) {
DP_INFO(edev, "Link settings are not allowed to be changed\n");
return -EOPNOTSUPP;
}
if (!netif_running(dev))
return 0;
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
if (!current_link.link_up)
return 0;
memset(&link_params, 0, sizeof(link_params));
link_params.link_up = false;
edev->ops->common->set_link(edev->cdev, &link_params);
link_params.link_up = true;
edev->ops->common->set_link(edev->cdev, &link_params);
return 0;
}
static u32 qede_get_link(struct net_device *dev)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
return current_link.link_up;
}
static int qede_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
void *rx_handle = NULL, *tx_handle = NULL;
struct qede_dev *edev = netdev_priv(dev);
u16 rx_coal, tx_coal, i, rc = 0;
struct qede_fastpath *fp;
rx_coal = QED_DEFAULT_RX_USECS;
tx_coal = QED_DEFAULT_TX_USECS;
memset(coal, 0, sizeof(struct ethtool_coalesce));
__qede_lock(edev);
if (edev->state == QEDE_STATE_OPEN) {
for_each_queue(i) {
fp = &edev->fp_array[i];
if (fp->type & QEDE_FASTPATH_RX) {
rx_handle = fp->rxq->handle;
break;
}
}
rc = edev->ops->get_coalesce(edev->cdev, &rx_coal, rx_handle);
if (rc) {
DP_INFO(edev, "Read Rx coalesce error\n");
goto out;
}
for_each_queue(i) {
fp = &edev->fp_array[i];
if (fp->type & QEDE_FASTPATH_TX) {
tx_handle = fp->txq->handle;
break;
}
}
rc = edev->ops->get_coalesce(edev->cdev, &tx_coal, tx_handle);
if (rc)
DP_INFO(edev, "Read Tx coalesce error\n");
}
out:
__qede_unlock(edev);
coal->rx_coalesce_usecs = rx_coal;
coal->tx_coalesce_usecs = tx_coal;
return rc;
}
static int qede_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
struct qede_dev *edev = netdev_priv(dev);
struct qede_fastpath *fp;
int i, rc = 0;
u16 rxc, txc;
if (!netif_running(dev)) {
DP_INFO(edev, "Interface is down\n");
return -EINVAL;
}
if (coal->rx_coalesce_usecs > QED_COALESCE_MAX ||
coal->tx_coalesce_usecs > QED_COALESCE_MAX) {
DP_INFO(edev,
"Can't support requested %s coalesce value [max supported value %d]\n",
coal->rx_coalesce_usecs > QED_COALESCE_MAX ? "rx" :
"tx", QED_COALESCE_MAX);
return -EINVAL;
}
rxc = (u16)coal->rx_coalesce_usecs;
txc = (u16)coal->tx_coalesce_usecs;
for_each_queue(i) {
fp = &edev->fp_array[i];
if (edev->fp_array[i].type & QEDE_FASTPATH_RX) {
rc = edev->ops->common->set_coalesce(edev->cdev,
rxc, 0,
fp->rxq->handle);
if (rc) {
DP_INFO(edev,
"Set RX coalesce error, rc = %d\n", rc);
return rc;
}
}
if (edev->fp_array[i].type & QEDE_FASTPATH_TX) {
rc = edev->ops->common->set_coalesce(edev->cdev,
0, txc,
fp->txq->handle);
if (rc) {
DP_INFO(edev,
"Set TX coalesce error, rc = %d\n", rc);
return rc;
}
}
}
return rc;
}
static void qede_get_ringparam(struct net_device *dev,
struct ethtool_ringparam *ering)
{
struct qede_dev *edev = netdev_priv(dev);
ering->rx_max_pending = NUM_RX_BDS_MAX;
ering->rx_pending = edev->q_num_rx_buffers;
ering->tx_max_pending = NUM_TX_BDS_MAX;
ering->tx_pending = edev->q_num_tx_buffers;
}
static int qede_set_ringparam(struct net_device *dev,
struct ethtool_ringparam *ering)
{
struct qede_dev *edev = netdev_priv(dev);
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"Set ring params command parameters: rx_pending = %d, tx_pending = %d\n",
ering->rx_pending, ering->tx_pending);
if (ering->rx_pending > NUM_RX_BDS_MAX ||
ering->rx_pending < NUM_RX_BDS_MIN ||
ering->tx_pending > NUM_TX_BDS_MAX ||
ering->tx_pending < NUM_TX_BDS_MIN) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"Can only support Rx Buffer size [0%08x,...,0x%08x] and Tx Buffer size [0x%08x,...,0x%08x]\n",
NUM_RX_BDS_MIN, NUM_RX_BDS_MAX,
NUM_TX_BDS_MIN, NUM_TX_BDS_MAX);
return -EINVAL;
}
edev->q_num_rx_buffers = ering->rx_pending;
edev->q_num_tx_buffers = ering->tx_pending;
qede_reload(edev, NULL, false);
return 0;
}
static void qede_get_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
if (current_link.pause_config & QED_LINK_PAUSE_AUTONEG_ENABLE)
epause->autoneg = true;
if (current_link.pause_config & QED_LINK_PAUSE_RX_ENABLE)
epause->rx_pause = true;
if (current_link.pause_config & QED_LINK_PAUSE_TX_ENABLE)
epause->tx_pause = true;
DP_VERBOSE(edev, QED_MSG_DEBUG,
"ethtool_pauseparam: cmd %d autoneg %d rx_pause %d tx_pause %d\n",
epause->cmd, epause->autoneg, epause->rx_pause,
epause->tx_pause);
}
static int qede_set_pauseparam(struct net_device *dev,
struct ethtool_pauseparam *epause)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_params params;
struct qed_link_output current_link;
if (!edev->ops || !edev->ops->common->can_link_change(edev->cdev)) {
DP_INFO(edev,
"Pause settings are not allowed to be changed\n");
return -EOPNOTSUPP;
}
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
memset(&params, 0, sizeof(params));
params.override_flags |= QED_LINK_OVERRIDE_PAUSE_CONFIG;
if (epause->autoneg) {
if (!(current_link.supported_caps & QED_LM_Autoneg_BIT)) {
DP_INFO(edev, "autoneg not supported\n");
return -EINVAL;
}
params.pause_config |= QED_LINK_PAUSE_AUTONEG_ENABLE;
}
if (epause->rx_pause)
params.pause_config |= QED_LINK_PAUSE_RX_ENABLE;
if (epause->tx_pause)
params.pause_config |= QED_LINK_PAUSE_TX_ENABLE;
params.link_up = true;
edev->ops->common->set_link(edev->cdev, &params);
return 0;
}
static void qede_get_regs(struct net_device *ndev,
struct ethtool_regs *regs, void *buffer)
{
struct qede_dev *edev = netdev_priv(ndev);
regs->version = 0;
memset(buffer, 0, regs->len);
if (edev->ops && edev->ops->common)
edev->ops->common->dbg_all_data(edev->cdev, buffer);
}
static int qede_get_regs_len(struct net_device *ndev)
{
struct qede_dev *edev = netdev_priv(ndev);
if (edev->ops && edev->ops->common)
return edev->ops->common->dbg_all_data_size(edev->cdev);
else
return -EINVAL;
}
static void qede_update_mtu(struct qede_dev *edev,
struct qede_reload_args *args)
{
edev->ndev->mtu = args->u.mtu;
}
int qede_change_mtu(struct net_device *ndev, int new_mtu)
{
struct qede_dev *edev = netdev_priv(ndev);
struct qede_reload_args args;
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"Configuring MTU size of %d\n", new_mtu);
args.u.mtu = new_mtu;
args.func = &qede_update_mtu;
qede_reload(edev, &args, false);
edev->ops->common->update_mtu(edev->cdev, new_mtu);
return 0;
}
static void qede_get_channels(struct net_device *dev,
struct ethtool_channels *channels)
{
struct qede_dev *edev = netdev_priv(dev);
channels->max_combined = QEDE_MAX_RSS_CNT(edev);
channels->max_rx = QEDE_MAX_RSS_CNT(edev);
channels->max_tx = QEDE_MAX_RSS_CNT(edev);
channels->combined_count = QEDE_QUEUE_CNT(edev) - edev->fp_num_tx -
edev->fp_num_rx;
channels->tx_count = edev->fp_num_tx;
channels->rx_count = edev->fp_num_rx;
}
static int qede_set_channels(struct net_device *dev,
struct ethtool_channels *channels)
{
struct qede_dev *edev = netdev_priv(dev);
u32 count;
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"set-channels command parameters: rx = %d, tx = %d, other = %d, combined = %d\n",
channels->rx_count, channels->tx_count,
channels->other_count, channels->combined_count);
count = channels->rx_count + channels->tx_count +
channels->combined_count;
if (channels->other_count) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"command parameters not supported\n");
return -EINVAL;
}
if (!(channels->combined_count || (channels->rx_count &&
channels->tx_count))) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"need to request at least one transmit and one receive channel\n");
return -EINVAL;
}
if (count > QEDE_MAX_RSS_CNT(edev)) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"requested channels = %d max supported channels = %d\n",
count, QEDE_MAX_RSS_CNT(edev));
return -EINVAL;
}
if ((count == QEDE_QUEUE_CNT(edev)) &&
(channels->tx_count == edev->fp_num_tx) &&
(channels->rx_count == edev->fp_num_rx)) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"No change in active parameters\n");
return 0;
}
if ((count % edev->dev_info.common.num_hwfns) ||
(channels->tx_count % edev->dev_info.common.num_hwfns) ||
(channels->rx_count % edev->dev_info.common.num_hwfns)) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"Number of channels must be divisible by %04x\n",
edev->dev_info.common.num_hwfns);
return -EINVAL;
}
edev->req_queues = count;
edev->req_num_tx = channels->tx_count;
edev->req_num_rx = channels->rx_count;
if ((edev->req_queues - edev->req_num_tx) != QEDE_RSS_COUNT(edev)) {
edev->rss_params_inited &= ~QEDE_RSS_INDIR_INITED;
memset(edev->rss_ind_table, 0, sizeof(edev->rss_ind_table));
}
qede_reload(edev, NULL, false);
return 0;
}
static int qede_get_ts_info(struct net_device *dev,
struct ethtool_ts_info *info)
{
struct qede_dev *edev = netdev_priv(dev);
return qede_ptp_get_ts_info(edev, info);
}
static int qede_set_phys_id(struct net_device *dev,
enum ethtool_phys_id_state state)
{
struct qede_dev *edev = netdev_priv(dev);
u8 led_state = 0;
switch (state) {
case ETHTOOL_ID_ACTIVE:
return 1;
case ETHTOOL_ID_ON:
led_state = QED_LED_MODE_ON;
break;
case ETHTOOL_ID_OFF:
led_state = QED_LED_MODE_OFF;
break;
case ETHTOOL_ID_INACTIVE:
led_state = QED_LED_MODE_RESTORE;
break;
}
edev->ops->common->set_led(edev->cdev, led_state);
return 0;
}
static int qede_get_rss_flags(struct qede_dev *edev, struct ethtool_rxnfc *info)
{
info->data = RXH_IP_SRC | RXH_IP_DST;
switch (info->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
info->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
break;
case UDP_V4_FLOW:
if (edev->rss_caps & QED_RSS_IPV4_UDP)
info->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
break;
case UDP_V6_FLOW:
if (edev->rss_caps & QED_RSS_IPV6_UDP)
info->data |= RXH_L4_B_0_1 | RXH_L4_B_2_3;
break;
case IPV4_FLOW:
case IPV6_FLOW:
break;
default:
info->data = 0;
break;
}
return 0;
}
static int qede_get_rxnfc(struct net_device *dev, struct ethtool_rxnfc *info,
u32 *rule_locs)
{
struct qede_dev *edev = netdev_priv(dev);
int rc = 0;
switch (info->cmd) {
case ETHTOOL_GRXRINGS:
info->data = QEDE_RSS_COUNT(edev);
break;
case ETHTOOL_GRXFH:
rc = qede_get_rss_flags(edev, info);
break;
case ETHTOOL_GRXCLSRLCNT:
info->rule_cnt = qede_get_arfs_filter_count(edev);
info->data = QEDE_RFS_MAX_FLTR;
break;
case ETHTOOL_GRXCLSRULE:
rc = qede_get_cls_rule_entry(edev, info);
break;
case ETHTOOL_GRXCLSRLALL:
rc = qede_get_cls_rule_all(edev, info, rule_locs);
break;
default:
DP_ERR(edev, "Command parameters not supported\n");
rc = -EOPNOTSUPP;
}
return rc;
}
static int qede_set_rss_flags(struct qede_dev *edev, struct ethtool_rxnfc *info)
{
struct qed_update_vport_params *vport_update_params;
u8 set_caps = 0, clr_caps = 0;
int rc = 0;
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Set rss flags command parameters: flow type = %d, data = %llu\n",
info->flow_type, info->data);
switch (info->flow_type) {
case TCP_V4_FLOW:
case TCP_V6_FLOW:
if (info->data ^ (RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
DP_INFO(edev, "Command parameters not supported\n");
return -EINVAL;
}
return 0;
case UDP_V4_FLOW:
if (info->data == (RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
set_caps = QED_RSS_IPV4_UDP;
DP_VERBOSE(edev, QED_MSG_DEBUG,
"UDP 4-tuple enabled\n");
} else if (info->data == (RXH_IP_SRC | RXH_IP_DST)) {
clr_caps = QED_RSS_IPV4_UDP;
DP_VERBOSE(edev, QED_MSG_DEBUG,
"UDP 4-tuple disabled\n");
} else {
return -EINVAL;
}
break;
case UDP_V6_FLOW:
if (info->data == (RXH_IP_SRC | RXH_IP_DST |
RXH_L4_B_0_1 | RXH_L4_B_2_3)) {
set_caps = QED_RSS_IPV6_UDP;
DP_VERBOSE(edev, QED_MSG_DEBUG,
"UDP 4-tuple enabled\n");
} else if (info->data == (RXH_IP_SRC | RXH_IP_DST)) {
clr_caps = QED_RSS_IPV6_UDP;
DP_VERBOSE(edev, QED_MSG_DEBUG,
"UDP 4-tuple disabled\n");
} else {
return -EINVAL;
}
break;
case IPV4_FLOW:
case IPV6_FLOW:
if (info->data ^ (RXH_IP_SRC | RXH_IP_DST)) {
DP_INFO(edev, "Command parameters not supported\n");
return -EINVAL;
}
return 0;
case SCTP_V4_FLOW:
case AH_ESP_V4_FLOW:
case AH_V4_FLOW:
case ESP_V4_FLOW:
case SCTP_V6_FLOW:
case AH_ESP_V6_FLOW:
case AH_V6_FLOW:
case ESP_V6_FLOW:
case IP_USER_FLOW:
case ETHER_FLOW:
if (info->data) {
DP_INFO(edev, "Command parameters not supported\n");
return -EINVAL;
}
return 0;
default:
return -EINVAL;
}
if (edev->rss_caps == ((edev->rss_caps & ~clr_caps) | set_caps))
return 0;
edev->rss_caps = ((edev->rss_caps & ~clr_caps) | set_caps);
edev->rss_params_inited |= QEDE_RSS_CAPS_INITED;
__qede_lock(edev);
if (edev->state == QEDE_STATE_OPEN) {
vport_update_params = vzalloc(sizeof(*vport_update_params));
if (!vport_update_params) {
__qede_unlock(edev);
return -ENOMEM;
}
qede_fill_rss_params(edev, &vport_update_params->rss_params,
&vport_update_params->update_rss_flg);
rc = edev->ops->vport_update(edev->cdev, vport_update_params);
vfree(vport_update_params);
}
__qede_unlock(edev);
return rc;
}
static int qede_set_rxnfc(struct net_device *dev, struct ethtool_rxnfc *info)
{
struct qede_dev *edev = netdev_priv(dev);
int rc;
switch (info->cmd) {
case ETHTOOL_SRXFH:
rc = qede_set_rss_flags(edev, info);
break;
case ETHTOOL_SRXCLSRLINS:
rc = qede_add_cls_rule(edev, info);
break;
case ETHTOOL_SRXCLSRLDEL:
rc = qede_del_cls_rule(edev, info);
break;
default:
DP_INFO(edev, "Command parameters not supported\n");
rc = -EOPNOTSUPP;
}
return rc;
}
static u32 qede_get_rxfh_indir_size(struct net_device *dev)
{
return QED_RSS_IND_TABLE_SIZE;
}
static u32 qede_get_rxfh_key_size(struct net_device *dev)
{
struct qede_dev *edev = netdev_priv(dev);
return sizeof(edev->rss_key);
}
static int qede_get_rxfh(struct net_device *dev, u32 *indir, u8 *key, u8 *hfunc)
{
struct qede_dev *edev = netdev_priv(dev);
int i;
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
if (!indir)
return 0;
for (i = 0; i < QED_RSS_IND_TABLE_SIZE; i++)
indir[i] = edev->rss_ind_table[i];
if (key)
memcpy(key, edev->rss_key, qede_get_rxfh_key_size(dev));
return 0;
}
static int qede_set_rxfh(struct net_device *dev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct qed_update_vport_params *vport_update_params;
struct qede_dev *edev = netdev_priv(dev);
int i, rc = 0;
if (edev->dev_info.common.num_hwfns > 1) {
DP_INFO(edev,
"RSS configuration is not supported for 100G devices\n");
return -EOPNOTSUPP;
}
if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP)
return -EOPNOTSUPP;
if (!indir && !key)
return 0;
if (indir) {
for (i = 0; i < QED_RSS_IND_TABLE_SIZE; i++)
edev->rss_ind_table[i] = indir[i];
edev->rss_params_inited |= QEDE_RSS_INDIR_INITED;
}
if (key) {
memcpy(&edev->rss_key, key, qede_get_rxfh_key_size(dev));
edev->rss_params_inited |= QEDE_RSS_KEY_INITED;
}
__qede_lock(edev);
if (edev->state == QEDE_STATE_OPEN) {
vport_update_params = vzalloc(sizeof(*vport_update_params));
if (!vport_update_params) {
__qede_unlock(edev);
return -ENOMEM;
}
qede_fill_rss_params(edev, &vport_update_params->rss_params,
&vport_update_params->update_rss_flg);
rc = edev->ops->vport_update(edev->cdev, vport_update_params);
vfree(vport_update_params);
}
__qede_unlock(edev);
return rc;
}
static void qede_netif_start(struct qede_dev *edev)
{
int i;
if (!netif_running(edev->ndev))
return;
for_each_queue(i) {
qed_sb_ack(edev->fp_array[i].sb_info, IGU_INT_ENABLE, 1);
napi_enable(&edev->fp_array[i].napi);
}
}
static void qede_netif_stop(struct qede_dev *edev)
{
int i;
for_each_queue(i) {
napi_disable(&edev->fp_array[i].napi);
qed_sb_ack(edev->fp_array[i].sb_info, IGU_INT_DISABLE, 0);
}
}
static int qede_selftest_transmit_traffic(struct qede_dev *edev,
struct sk_buff *skb)
{
struct qede_tx_queue *txq = NULL;
struct eth_tx_1st_bd *first_bd;
dma_addr_t mapping;
int i, idx;
u16 val;
for_each_queue(i) {
if (edev->fp_array[i].type & QEDE_FASTPATH_TX) {
txq = edev->fp_array[i].txq;
break;
}
}
if (!txq) {
DP_NOTICE(edev, "Tx path is not available\n");
return -1;
}
idx = txq->sw_tx_prod;
txq->sw_tx_ring.skbs[idx].skb = skb;
first_bd = qed_chain_produce(&txq->tx_pbl);
memset(first_bd, 0, sizeof(*first_bd));
val = 1 << ETH_TX_1ST_BD_FLAGS_START_BD_SHIFT;
first_bd->data.bd_flags.bitfields = val;
val = skb->len & ETH_TX_DATA_1ST_BD_PKT_LEN_MASK;
val = val << ETH_TX_DATA_1ST_BD_PKT_LEN_SHIFT;
first_bd->data.bitfields |= cpu_to_le16(val);
mapping = dma_map_single(&edev->pdev->dev, skb->data,
skb_headlen(skb), DMA_TO_DEVICE);
if (unlikely(dma_mapping_error(&edev->pdev->dev, mapping))) {
DP_NOTICE(edev, "SKB mapping failed\n");
return -ENOMEM;
}
BD_SET_UNMAP_ADDR_LEN(first_bd, mapping, skb_headlen(skb));
first_bd->data.nbds = 1;
txq->sw_tx_prod = (txq->sw_tx_prod + 1) % txq->num_tx_buffers;
val = qed_chain_get_prod_idx(&txq->tx_pbl);
txq->tx_db.data.bd_prod = cpu_to_le16(val);
wmb();
barrier();
writel(txq->tx_db.raw, txq->doorbell_addr);
mmiowb();
for (i = 0; i < QEDE_SELFTEST_POLL_COUNT; i++) {
if (qede_txq_has_work(txq))
break;
usleep_range(100, 200);
}
if (!qede_txq_has_work(txq)) {
DP_NOTICE(edev, "Tx completion didn't happen\n");
return -1;
}
first_bd = (struct eth_tx_1st_bd *)qed_chain_consume(&txq->tx_pbl);
dma_unmap_single(&edev->pdev->dev, BD_UNMAP_ADDR(first_bd),
BD_UNMAP_LEN(first_bd), DMA_TO_DEVICE);
txq->sw_tx_cons = (txq->sw_tx_cons + 1) % txq->num_tx_buffers;
txq->sw_tx_ring.skbs[idx].skb = NULL;
return 0;
}
static int qede_selftest_receive_traffic(struct qede_dev *edev)
{
u16 hw_comp_cons, sw_comp_cons, sw_rx_index, len;
struct eth_fast_path_rx_reg_cqe *fp_cqe;
struct qede_rx_queue *rxq = NULL;
struct sw_rx_data *sw_rx_data;
union eth_rx_cqe *cqe;
int i, iter, rc = 0;
u8 *data_ptr;
for_each_queue(i) {
if (edev->fp_array[i].type & QEDE_FASTPATH_RX) {
rxq = edev->fp_array[i].rxq;
break;
}
}
if (!rxq) {
DP_NOTICE(edev, "Rx path is not available\n");
return -1;
}
for (iter = 0; iter < QEDE_SELFTEST_POLL_COUNT; iter++) {
if (!qede_has_rx_work(rxq)) {
usleep_range(100, 200);
continue;
}
hw_comp_cons = le16_to_cpu(*rxq->hw_cons_ptr);
sw_comp_cons = qed_chain_get_cons_idx(&rxq->rx_comp_ring);
rmb();
cqe = (union eth_rx_cqe *)qed_chain_consume(&rxq->rx_comp_ring);
sw_rx_index = rxq->sw_rx_cons & NUM_RX_BDS_MAX;
sw_rx_data = &rxq->sw_rx_ring[sw_rx_index];
fp_cqe = &cqe->fast_path_regular;
len = le16_to_cpu(fp_cqe->len_on_first_bd);
data_ptr = (u8 *)(page_address(sw_rx_data->data) +
fp_cqe->placement_offset +
sw_rx_data->page_offset);
if (ether_addr_equal(data_ptr, edev->ndev->dev_addr) &&
ether_addr_equal(data_ptr + ETH_ALEN,
edev->ndev->dev_addr)) {
for (i = ETH_HLEN; i < len; i++)
if (data_ptr[i] != (unsigned char)(i & 0xff)) {
rc = -1;
break;
}
qede_recycle_rx_bd_ring(rxq, 1);
qed_chain_recycle_consumed(&rxq->rx_comp_ring);
break;
}
DP_INFO(edev, "Not the transmitted packet\n");
qede_recycle_rx_bd_ring(rxq, 1);
qed_chain_recycle_consumed(&rxq->rx_comp_ring);
}
if (iter == QEDE_SELFTEST_POLL_COUNT) {
DP_NOTICE(edev, "Failed to receive the traffic\n");
return -1;
}
qede_update_rx_prod(edev, rxq);
return rc;
}
static int qede_selftest_run_loopback(struct qede_dev *edev, u32 loopback_mode)
{
struct qed_link_params link_params;
struct sk_buff *skb = NULL;
int rc = 0, i;
u32 pkt_size;
u8 *packet;
if (!netif_running(edev->ndev)) {
DP_NOTICE(edev, "Interface is down\n");
return -EINVAL;
}
qede_netif_stop(edev);
memset(&link_params, 0, sizeof(link_params));
link_params.link_up = true;
link_params.override_flags = QED_LINK_OVERRIDE_LOOPBACK_MODE;
link_params.loopback_mode = loopback_mode;
edev->ops->common->set_link(edev->cdev, &link_params);
msleep_interruptible(500);
pkt_size = edev->ndev->mtu + ETH_HLEN;
skb = netdev_alloc_skb(edev->ndev, pkt_size);
if (!skb) {
DP_INFO(edev, "Can't allocate skb\n");
rc = -ENOMEM;
goto test_loopback_exit;
}
packet = skb_put(skb, pkt_size);
ether_addr_copy(packet, edev->ndev->dev_addr);
ether_addr_copy(packet + ETH_ALEN, edev->ndev->dev_addr);
memset(packet + (2 * ETH_ALEN), 0x77, (ETH_HLEN - (2 * ETH_ALEN)));
for (i = ETH_HLEN; i < pkt_size; i++)
packet[i] = (unsigned char)(i & 0xff);
rc = qede_selftest_transmit_traffic(edev, skb);
if (rc)
goto test_loopback_exit;
rc = qede_selftest_receive_traffic(edev);
if (rc)
goto test_loopback_exit;
DP_VERBOSE(edev, NETIF_MSG_RX_STATUS, "Loopback test successful\n");
test_loopback_exit:
dev_kfree_skb(skb);
memset(&link_params, 0, sizeof(link_params));
link_params.link_up = true;
link_params.override_flags = QED_LINK_OVERRIDE_LOOPBACK_MODE;
link_params.loopback_mode = QED_LINK_LOOPBACK_NONE;
edev->ops->common->set_link(edev->cdev, &link_params);
msleep_interruptible(500);
qede_netif_start(edev);
return rc;
}
static void qede_self_test(struct net_device *dev,
struct ethtool_test *etest, u64 *buf)
{
struct qede_dev *edev = netdev_priv(dev);
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Self-test command parameters: offline = %d, external_lb = %d\n",
(etest->flags & ETH_TEST_FL_OFFLINE),
(etest->flags & ETH_TEST_FL_EXTERNAL_LB) >> 2);
memset(buf, 0, sizeof(u64) * QEDE_ETHTOOL_TEST_MAX);
if (etest->flags & ETH_TEST_FL_OFFLINE) {
if (qede_selftest_run_loopback(edev,
QED_LINK_LOOPBACK_INT_PHY)) {
buf[QEDE_ETHTOOL_INT_LOOPBACK] = 1;
etest->flags |= ETH_TEST_FL_FAILED;
}
}
if (edev->ops->common->selftest->selftest_interrupt(edev->cdev)) {
buf[QEDE_ETHTOOL_INTERRUPT_TEST] = 1;
etest->flags |= ETH_TEST_FL_FAILED;
}
if (edev->ops->common->selftest->selftest_memory(edev->cdev)) {
buf[QEDE_ETHTOOL_MEMORY_TEST] = 1;
etest->flags |= ETH_TEST_FL_FAILED;
}
if (edev->ops->common->selftest->selftest_register(edev->cdev)) {
buf[QEDE_ETHTOOL_REGISTER_TEST] = 1;
etest->flags |= ETH_TEST_FL_FAILED;
}
if (edev->ops->common->selftest->selftest_clock(edev->cdev)) {
buf[QEDE_ETHTOOL_CLOCK_TEST] = 1;
etest->flags |= ETH_TEST_FL_FAILED;
}
if (edev->ops->common->selftest->selftest_nvram(edev->cdev)) {
buf[QEDE_ETHTOOL_NVRAM_TEST] = 1;
etest->flags |= ETH_TEST_FL_FAILED;
}
}
static int qede_set_tunable(struct net_device *dev,
const struct ethtool_tunable *tuna,
const void *data)
{
struct qede_dev *edev = netdev_priv(dev);
u32 val;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
val = *(u32 *)data;
if (val < QEDE_MIN_PKT_LEN || val > QEDE_RX_HDR_SIZE) {
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Invalid rx copy break value, range is [%u, %u]",
QEDE_MIN_PKT_LEN, QEDE_RX_HDR_SIZE);
return -EINVAL;
}
edev->rx_copybreak = *(u32 *)data;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int qede_get_tunable(struct net_device *dev,
const struct ethtool_tunable *tuna, void *data)
{
struct qede_dev *edev = netdev_priv(dev);
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
*(u32 *)data = edev->rx_copybreak;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int qede_get_eee(struct net_device *dev, struct ethtool_eee *edata)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
if (!current_link.eee_supported) {
DP_INFO(edev, "EEE is not supported\n");
return -EOPNOTSUPP;
}
if (current_link.eee.adv_caps & QED_EEE_1G_ADV)
edata->advertised = ADVERTISED_1000baseT_Full;
if (current_link.eee.adv_caps & QED_EEE_10G_ADV)
edata->advertised |= ADVERTISED_10000baseT_Full;
if (current_link.sup_caps & QED_EEE_1G_ADV)
edata->supported = ADVERTISED_1000baseT_Full;
if (current_link.sup_caps & QED_EEE_10G_ADV)
edata->supported |= ADVERTISED_10000baseT_Full;
if (current_link.eee.lp_adv_caps & QED_EEE_1G_ADV)
edata->lp_advertised = ADVERTISED_1000baseT_Full;
if (current_link.eee.lp_adv_caps & QED_EEE_10G_ADV)
edata->lp_advertised |= ADVERTISED_10000baseT_Full;
edata->tx_lpi_timer = current_link.eee.tx_lpi_timer;
edata->eee_enabled = current_link.eee.enable;
edata->tx_lpi_enabled = current_link.eee.tx_lpi_enable;
edata->eee_active = current_link.eee_active;
return 0;
}
static int qede_set_eee(struct net_device *dev, struct ethtool_eee *edata)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
struct qed_link_params params;
if (!edev->ops->common->can_link_change(edev->cdev)) {
DP_INFO(edev, "Link settings are not allowed to be changed\n");
return -EOPNOTSUPP;
}
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
if (!current_link.eee_supported) {
DP_INFO(edev, "EEE is not supported\n");
return -EOPNOTSUPP;
}
memset(&params, 0, sizeof(params));
params.override_flags |= QED_LINK_OVERRIDE_EEE_CONFIG;
if (!(edata->advertised & (ADVERTISED_1000baseT_Full |
ADVERTISED_10000baseT_Full)) ||
((edata->advertised & (ADVERTISED_1000baseT_Full |
ADVERTISED_10000baseT_Full)) !=
edata->advertised)) {
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Invalid advertised capabilities %d\n",
edata->advertised);
return -EINVAL;
}
if (edata->advertised & ADVERTISED_1000baseT_Full)
params.eee.adv_caps = QED_EEE_1G_ADV;
if (edata->advertised & ADVERTISED_10000baseT_Full)
params.eee.adv_caps |= QED_EEE_10G_ADV;
params.eee.enable = edata->eee_enabled;
params.eee.tx_lpi_enable = edata->tx_lpi_enabled;
params.eee.tx_lpi_timer = edata->tx_lpi_timer;
params.link_up = true;
edev->ops->common->set_link(edev->cdev, &params);
return 0;
}
void qede_set_ethtool_ops(struct net_device *dev)
{
struct qede_dev *edev = netdev_priv(dev);
if (IS_VF(edev))
dev->ethtool_ops = &qede_vf_ethtool_ops;
else
dev->ethtool_ops = &qede_ethtool_ops;
}
