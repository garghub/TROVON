static void qede_get_strings_stats(struct qede_dev *edev, u8 *buf)
{
int i, j, k;
for (i = 0, j = 0; i < QEDE_NUM_STATS; i++) {
strcpy(buf + j * ETH_GSTRING_LEN,
qede_stats_arr[i].string);
j++;
}
for (k = 0; k < QEDE_NUM_RQSTATS; k++, j++)
strcpy(buf + j * ETH_GSTRING_LEN,
qede_rqstats_arr[k].string);
}
static void qede_get_strings(struct net_device *dev, u32 stringset, u8 *buf)
{
struct qede_dev *edev = netdev_priv(dev);
switch (stringset) {
case ETH_SS_STATS:
qede_get_strings_stats(edev, buf);
break;
default:
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Unsupported stringset 0x%08x\n", stringset);
}
}
static void qede_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *buf)
{
struct qede_dev *edev = netdev_priv(dev);
int sidx, cnt = 0;
int qid;
qede_fill_by_demand_stats(edev);
mutex_lock(&edev->qede_lock);
for (sidx = 0; sidx < QEDE_NUM_STATS; sidx++)
buf[cnt++] = QEDE_STATS_DATA(edev, sidx);
for (sidx = 0; sidx < QEDE_NUM_RQSTATS; sidx++) {
buf[cnt] = 0;
for (qid = 0; qid < edev->num_rss; qid++)
buf[cnt] += QEDE_RQSTATS_DATA(edev, sidx, qid);
cnt++;
}
mutex_unlock(&edev->qede_lock);
}
static int qede_get_sset_count(struct net_device *dev, int stringset)
{
struct qede_dev *edev = netdev_priv(dev);
int num_stats = QEDE_NUM_STATS;
switch (stringset) {
case ETH_SS_STATS:
return num_stats + QEDE_NUM_RQSTATS;
default:
DP_VERBOSE(edev, QED_MSG_DEBUG,
"Unsupported stringset 0x%08x\n", stringset);
return -EINVAL;
}
}
static int qede_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
cmd->supported = current_link.supported_caps;
cmd->advertising = current_link.advertised_caps;
if ((edev->state == QEDE_STATE_OPEN) && (current_link.link_up)) {
ethtool_cmd_speed_set(cmd, current_link.speed);
cmd->duplex = current_link.duplex;
} else {
cmd->duplex = DUPLEX_UNKNOWN;
ethtool_cmd_speed_set(cmd, SPEED_UNKNOWN);
}
cmd->port = current_link.port;
cmd->autoneg = (current_link.autoneg) ? AUTONEG_ENABLE :
AUTONEG_DISABLE;
cmd->lp_advertising = current_link.lp_caps;
return 0;
}
static int qede_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct qede_dev *edev = netdev_priv(dev);
struct qed_link_output current_link;
struct qed_link_params params;
u32 speed;
if (edev->dev_info.common.is_mf) {
DP_INFO(edev,
"Link parameters can not be changed in MF mode\n");
return -EOPNOTSUPP;
}
memset(&current_link, 0, sizeof(current_link));
memset(&params, 0, sizeof(params));
edev->ops->common->get_link(edev->cdev, &current_link);
speed = ethtool_cmd_speed(cmd);
params.override_flags |= QED_LINK_OVERRIDE_SPEED_ADV_SPEEDS;
params.override_flags |= QED_LINK_OVERRIDE_SPEED_AUTONEG;
if (cmd->autoneg == AUTONEG_ENABLE) {
params.autoneg = true;
params.forced_speed = 0;
params.adv_speeds = cmd->advertising;
} else {
params.override_flags |= QED_LINK_OVERRIDE_SPEED_FORCED_SPEED;
params.autoneg = false;
params.forced_speed = speed;
switch (speed) {
case SPEED_10000:
if (!(current_link.supported_caps &
SUPPORTED_10000baseKR_Full)) {
DP_INFO(edev, "10G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = SUPPORTED_10000baseKR_Full;
break;
case SPEED_40000:
if (!(current_link.supported_caps &
SUPPORTED_40000baseLR4_Full)) {
DP_INFO(edev, "40G speed not supported\n");
return -EINVAL;
}
params.adv_speeds = SUPPORTED_40000baseLR4_Full;
break;
default:
DP_INFO(edev, "Unsupported speed %u\n", speed);
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
static u32 qede_get_msglevel(struct net_device *ndev)
{
struct qede_dev *edev = netdev_priv(ndev);
return ((u32)edev->dp_level << QED_LOG_LEVEL_SHIFT) |
edev->dp_module;
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
if (netif_running(edev->ndev))
qede_reload(edev, NULL, NULL);
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
if (!edev->dev_info.common.is_mf) {
DP_INFO(edev,
"Pause parameters can not be updated in non-default mode\n");
return -EOPNOTSUPP;
}
memset(&current_link, 0, sizeof(current_link));
edev->ops->common->get_link(edev->cdev, &current_link);
memset(&params, 0, sizeof(params));
params.override_flags |= QED_LINK_OVERRIDE_PAUSE_CONFIG;
if (epause->autoneg) {
if (!(current_link.supported_caps & SUPPORTED_Autoneg)) {
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
static void qede_update_mtu(struct qede_dev *edev, union qede_reload_args *args)
{
edev->ndev->mtu = args->mtu;
}
int qede_change_mtu(struct net_device *ndev, int new_mtu)
{
struct qede_dev *edev = netdev_priv(ndev);
union qede_reload_args args;
if ((new_mtu > ETH_MAX_JUMBO_PACKET_SIZE) ||
((new_mtu + ETH_HLEN) < ETH_MIN_PACKET_SIZE)) {
DP_ERR(edev, "Can't support requested MTU size\n");
return -EINVAL;
}
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"Configuring MTU size of %d\n", new_mtu);
args.mtu = new_mtu;
if (netif_running(edev->ndev))
qede_reload(edev, &qede_update_mtu, &args);
qede_update_mtu(edev, &args);
return 0;
}
static void qede_get_channels(struct net_device *dev,
struct ethtool_channels *channels)
{
struct qede_dev *edev = netdev_priv(dev);
channels->max_combined = QEDE_MAX_RSS_CNT(edev);
channels->combined_count = QEDE_RSS_CNT(edev);
}
static int qede_set_channels(struct net_device *dev,
struct ethtool_channels *channels)
{
struct qede_dev *edev = netdev_priv(dev);
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"set-channels command parameters: rx = %d, tx = %d, other = %d, combined = %d\n",
channels->rx_count, channels->tx_count,
channels->other_count, channels->combined_count);
if (channels->rx_count || channels->tx_count ||
channels->other_count || (channels->combined_count == 0) ||
(channels->combined_count > QEDE_MAX_RSS_CNT(edev))) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"command parameters not supported\n");
return -EINVAL;
}
if (channels->combined_count == QEDE_RSS_CNT(edev)) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"No change in active parameters\n");
return 0;
}
if (channels->combined_count % edev->dev_info.common.num_hwfns) {
DP_VERBOSE(edev, (NETIF_MSG_IFUP | NETIF_MSG_IFDOWN),
"Number of channels must be divisable by %04x\n",
edev->dev_info.common.num_hwfns);
return -EINVAL;
}
edev->req_rss = channels->combined_count;
if (netif_running(dev))
qede_reload(edev, NULL, NULL);
return 0;
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
void qede_set_ethtool_ops(struct net_device *dev)
{
dev->ethtool_ops = &qede_ethtool_ops;
}
