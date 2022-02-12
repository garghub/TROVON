static void xgbe_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
int i;
DBGPR("-->%s\n", __func__);
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < XGBE_STATS_COUNT; i++) {
memcpy(data, xgbe_gstring_stats[i].stat_string,
ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
break;
}
DBGPR("<--%s\n", __func__);
}
static void xgbe_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
u8 *stat;
int i;
DBGPR("-->%s\n", __func__);
pdata->hw_if.read_mmc_stats(pdata);
for (i = 0; i < XGBE_STATS_COUNT; i++) {
stat = (u8 *)pdata + xgbe_gstring_stats[i].stat_offset;
*data++ = *(u64 *)stat;
}
DBGPR("<--%s\n", __func__);
}
static int xgbe_get_sset_count(struct net_device *netdev, int stringset)
{
int ret;
DBGPR("-->%s\n", __func__);
switch (stringset) {
case ETH_SS_STATS:
ret = XGBE_STATS_COUNT;
break;
default:
ret = -EOPNOTSUPP;
}
DBGPR("<--%s\n", __func__);
return ret;
}
static void xgbe_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
DBGPR("-->xgbe_get_pauseparam\n");
pause->autoneg = pdata->phy.pause_autoneg;
pause->tx_pause = pdata->phy.tx_pause;
pause->rx_pause = pdata->phy.rx_pause;
DBGPR("<--xgbe_get_pauseparam\n");
}
static int xgbe_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
int ret = 0;
DBGPR("-->xgbe_set_pauseparam\n");
DBGPR(" autoneg = %d, tx_pause = %d, rx_pause = %d\n",
pause->autoneg, pause->tx_pause, pause->rx_pause);
if (pause->autoneg && (pdata->phy.autoneg != AUTONEG_ENABLE))
return -EINVAL;
pdata->phy.pause_autoneg = pause->autoneg;
pdata->phy.tx_pause = pause->tx_pause;
pdata->phy.rx_pause = pause->rx_pause;
pdata->phy.advertising &= ~ADVERTISED_Pause;
pdata->phy.advertising &= ~ADVERTISED_Asym_Pause;
if (pause->rx_pause) {
pdata->phy.advertising |= ADVERTISED_Pause;
pdata->phy.advertising |= ADVERTISED_Asym_Pause;
}
if (pause->tx_pause)
pdata->phy.advertising ^= ADVERTISED_Asym_Pause;
if (netif_running(netdev))
ret = pdata->phy_if.phy_config_aneg(pdata);
DBGPR("<--xgbe_set_pauseparam\n");
return ret;
}
static int xgbe_get_settings(struct net_device *netdev,
struct ethtool_cmd *cmd)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
DBGPR("-->xgbe_get_settings\n");
cmd->phy_address = pdata->phy.address;
cmd->supported = pdata->phy.supported;
cmd->advertising = pdata->phy.advertising;
cmd->lp_advertising = pdata->phy.lp_advertising;
cmd->autoneg = pdata->phy.autoneg;
ethtool_cmd_speed_set(cmd, pdata->phy.speed);
cmd->duplex = pdata->phy.duplex;
cmd->port = PORT_NONE;
cmd->transceiver = XCVR_INTERNAL;
DBGPR("<--xgbe_get_settings\n");
return 0;
}
static int xgbe_set_settings(struct net_device *netdev,
struct ethtool_cmd *cmd)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
u32 speed;
int ret;
DBGPR("-->xgbe_set_settings\n");
speed = ethtool_cmd_speed(cmd);
if (cmd->phy_address != pdata->phy.address)
return -EINVAL;
if ((cmd->autoneg != AUTONEG_ENABLE) &&
(cmd->autoneg != AUTONEG_DISABLE))
return -EINVAL;
if (cmd->autoneg == AUTONEG_DISABLE) {
switch (speed) {
case SPEED_10000:
case SPEED_2500:
case SPEED_1000:
break;
default:
return -EINVAL;
}
if (cmd->duplex != DUPLEX_FULL)
return -EINVAL;
}
cmd->advertising &= pdata->phy.supported;
if ((cmd->autoneg == AUTONEG_ENABLE) && !cmd->advertising)
return -EINVAL;
ret = 0;
pdata->phy.autoneg = cmd->autoneg;
pdata->phy.speed = speed;
pdata->phy.duplex = cmd->duplex;
pdata->phy.advertising = cmd->advertising;
if (cmd->autoneg == AUTONEG_ENABLE)
pdata->phy.advertising |= ADVERTISED_Autoneg;
else
pdata->phy.advertising &= ~ADVERTISED_Autoneg;
if (netif_running(netdev))
ret = pdata->phy_if.phy_config_aneg(pdata);
DBGPR("<--xgbe_set_settings\n");
return ret;
}
static void xgbe_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_features *hw_feat = &pdata->hw_feat;
strlcpy(drvinfo->driver, XGBE_DRV_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, XGBE_DRV_VERSION, sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, dev_name(pdata->dev),
sizeof(drvinfo->bus_info));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version), "%d.%d.%d",
XGMAC_GET_BITS(hw_feat->version, MAC_VR, USERVER),
XGMAC_GET_BITS(hw_feat->version, MAC_VR, DEVID),
XGMAC_GET_BITS(hw_feat->version, MAC_VR, SNPSVER));
drvinfo->n_stats = XGBE_STATS_COUNT;
}
static int xgbe_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
DBGPR("-->xgbe_get_coalesce\n");
memset(ec, 0, sizeof(struct ethtool_coalesce));
ec->rx_coalesce_usecs = pdata->rx_usecs;
ec->rx_max_coalesced_frames = pdata->rx_frames;
ec->tx_max_coalesced_frames = pdata->tx_frames;
DBGPR("<--xgbe_get_coalesce\n");
return 0;
}
static int xgbe_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned int rx_frames, rx_riwt, rx_usecs;
unsigned int tx_frames;
DBGPR("-->xgbe_set_coalesce\n");
if ((ec->rx_coalesce_usecs_irq) ||
(ec->rx_max_coalesced_frames_irq) ||
(ec->tx_coalesce_usecs) ||
(ec->tx_coalesce_usecs_irq) ||
(ec->tx_max_coalesced_frames_irq) ||
(ec->stats_block_coalesce_usecs) ||
(ec->use_adaptive_rx_coalesce) ||
(ec->use_adaptive_tx_coalesce) ||
(ec->pkt_rate_low) ||
(ec->rx_coalesce_usecs_low) ||
(ec->rx_max_coalesced_frames_low) ||
(ec->tx_coalesce_usecs_low) ||
(ec->tx_max_coalesced_frames_low) ||
(ec->pkt_rate_high) ||
(ec->rx_coalesce_usecs_high) ||
(ec->rx_max_coalesced_frames_high) ||
(ec->tx_coalesce_usecs_high) ||
(ec->tx_max_coalesced_frames_high) ||
(ec->rate_sample_interval))
return -EOPNOTSUPP;
rx_riwt = hw_if->usec_to_riwt(pdata, ec->rx_coalesce_usecs);
rx_usecs = ec->rx_coalesce_usecs;
rx_frames = ec->rx_max_coalesced_frames;
if (rx_usecs && !rx_riwt)
rx_riwt = 1;
if (rx_riwt > XGMAC_MAX_DMA_RIWT) {
netdev_alert(netdev, "rx-usec is limited to %d usecs\n",
hw_if->riwt_to_usec(pdata, XGMAC_MAX_DMA_RIWT));
return -EINVAL;
}
if (rx_frames > pdata->rx_desc_count) {
netdev_alert(netdev, "rx-frames is limited to %d frames\n",
pdata->rx_desc_count);
return -EINVAL;
}
tx_frames = ec->tx_max_coalesced_frames;
if (tx_frames > pdata->tx_desc_count) {
netdev_alert(netdev, "tx-frames is limited to %d frames\n",
pdata->tx_desc_count);
return -EINVAL;
}
pdata->rx_riwt = rx_riwt;
pdata->rx_usecs = rx_usecs;
pdata->rx_frames = rx_frames;
hw_if->config_rx_coalesce(pdata);
pdata->tx_frames = tx_frames;
hw_if->config_tx_coalesce(pdata);
DBGPR("<--xgbe_set_coalesce\n");
return 0;
}
static int xgbe_get_rxnfc(struct net_device *netdev,
struct ethtool_rxnfc *rxnfc, u32 *rule_locs)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
switch (rxnfc->cmd) {
case ETHTOOL_GRXRINGS:
rxnfc->data = pdata->rx_ring_count;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static u32 xgbe_get_rxfh_key_size(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
return sizeof(pdata->rss_key);
}
static u32 xgbe_get_rxfh_indir_size(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
return ARRAY_SIZE(pdata->rss_table);
}
static int xgbe_get_rxfh(struct net_device *netdev, u32 *indir, u8 *key,
u8 *hfunc)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
unsigned int i;
if (indir) {
for (i = 0; i < ARRAY_SIZE(pdata->rss_table); i++)
indir[i] = XGMAC_GET_BITS(pdata->rss_table[i],
MAC_RSSDR, DMCH);
}
if (key)
memcpy(key, pdata->rss_key, sizeof(pdata->rss_key));
if (hfunc)
*hfunc = ETH_RSS_HASH_TOP;
return 0;
}
static int xgbe_set_rxfh(struct net_device *netdev, const u32 *indir,
const u8 *key, const u8 hfunc)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned int ret;
if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP)
return -EOPNOTSUPP;
if (indir) {
ret = hw_if->set_rss_lookup_table(pdata, indir);
if (ret)
return ret;
}
if (key) {
ret = hw_if->set_rss_hash_key(pdata, key);
if (ret)
return ret;
}
return 0;
}
static int xgbe_get_ts_info(struct net_device *netdev,
struct ethtool_ts_info *ts_info)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
ts_info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
if (pdata->ptp_clock)
ts_info->phc_index = ptp_clock_index(pdata->ptp_clock);
else
ts_info->phc_index = -1;
ts_info->tx_types = (1 << HWTSTAMP_TX_OFF) | (1 << HWTSTAMP_TX_ON);
ts_info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_PTP_V2_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V2_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_ALL);
return 0;
}
struct ethtool_ops *xgbe_get_ethtool_ops(void)
{
return (struct ethtool_ops *)&xgbe_ethtool_ops;
}
