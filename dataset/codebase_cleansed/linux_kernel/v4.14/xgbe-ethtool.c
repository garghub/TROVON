static void xgbe_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < XGBE_STATS_COUNT; i++) {
memcpy(data, xgbe_gstring_stats[i].stat_string,
ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
for (i = 0; i < pdata->tx_ring_count; i++) {
sprintf(data, "txq_%u_packets", i);
data += ETH_GSTRING_LEN;
sprintf(data, "txq_%u_bytes", i);
data += ETH_GSTRING_LEN;
}
for (i = 0; i < pdata->rx_ring_count; i++) {
sprintf(data, "rxq_%u_packets", i);
data += ETH_GSTRING_LEN;
sprintf(data, "rxq_%u_bytes", i);
data += ETH_GSTRING_LEN;
}
break;
}
}
static void xgbe_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
u8 *stat;
int i;
pdata->hw_if.read_mmc_stats(pdata);
for (i = 0; i < XGBE_STATS_COUNT; i++) {
stat = (u8 *)pdata + xgbe_gstring_stats[i].stat_offset;
*data++ = *(u64 *)stat;
}
for (i = 0; i < pdata->tx_ring_count; i++) {
*data++ = pdata->ext_stats.txq_packets[i];
*data++ = pdata->ext_stats.txq_bytes[i];
}
for (i = 0; i < pdata->rx_ring_count; i++) {
*data++ = pdata->ext_stats.rxq_packets[i];
*data++ = pdata->ext_stats.rxq_bytes[i];
}
}
static int xgbe_get_sset_count(struct net_device *netdev, int stringset)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
int ret;
switch (stringset) {
case ETH_SS_STATS:
ret = XGBE_STATS_COUNT +
(pdata->tx_ring_count * 2) +
(pdata->rx_ring_count * 2);
break;
default:
ret = -EOPNOTSUPP;
}
return ret;
}
static void xgbe_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
pause->autoneg = pdata->phy.pause_autoneg;
pause->tx_pause = pdata->phy.tx_pause;
pause->rx_pause = pdata->phy.rx_pause;
}
static int xgbe_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct ethtool_link_ksettings *lks = &pdata->phy.lks;
int ret = 0;
if (pause->autoneg && (pdata->phy.autoneg != AUTONEG_ENABLE)) {
netdev_err(netdev,
"autoneg disabled, pause autoneg not available\n");
return -EINVAL;
}
pdata->phy.pause_autoneg = pause->autoneg;
pdata->phy.tx_pause = pause->tx_pause;
pdata->phy.rx_pause = pause->rx_pause;
XGBE_CLR_ADV(lks, Pause);
XGBE_CLR_ADV(lks, Asym_Pause);
if (pause->rx_pause) {
XGBE_SET_ADV(lks, Pause);
XGBE_SET_ADV(lks, Asym_Pause);
}
if (pause->tx_pause) {
if (XGBE_ADV(lks, Asym_Pause))
XGBE_CLR_ADV(lks, Asym_Pause);
else
XGBE_SET_ADV(lks, Asym_Pause);
}
if (netif_running(netdev))
ret = pdata->phy_if.phy_config_aneg(pdata);
return ret;
}
static int xgbe_get_link_ksettings(struct net_device *netdev,
struct ethtool_link_ksettings *cmd)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct ethtool_link_ksettings *lks = &pdata->phy.lks;
cmd->base.phy_address = pdata->phy.address;
cmd->base.autoneg = pdata->phy.autoneg;
cmd->base.speed = pdata->phy.speed;
cmd->base.duplex = pdata->phy.duplex;
cmd->base.port = PORT_NONE;
XGBE_LM_COPY(cmd, supported, lks, supported);
XGBE_LM_COPY(cmd, advertising, lks, advertising);
XGBE_LM_COPY(cmd, lp_advertising, lks, lp_advertising);
return 0;
}
static int xgbe_set_link_ksettings(struct net_device *netdev,
const struct ethtool_link_ksettings *cmd)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct ethtool_link_ksettings *lks = &pdata->phy.lks;
__ETHTOOL_DECLARE_LINK_MODE_MASK(advertising);
u32 speed;
int ret;
speed = cmd->base.speed;
if (cmd->base.phy_address != pdata->phy.address) {
netdev_err(netdev, "invalid phy address %hhu\n",
cmd->base.phy_address);
return -EINVAL;
}
if ((cmd->base.autoneg != AUTONEG_ENABLE) &&
(cmd->base.autoneg != AUTONEG_DISABLE)) {
netdev_err(netdev, "unsupported autoneg %hhu\n",
cmd->base.autoneg);
return -EINVAL;
}
if (cmd->base.autoneg == AUTONEG_DISABLE) {
if (!pdata->phy_if.phy_valid_speed(pdata, speed)) {
netdev_err(netdev, "unsupported speed %u\n", speed);
return -EINVAL;
}
if (cmd->base.duplex != DUPLEX_FULL) {
netdev_err(netdev, "unsupported duplex %hhu\n",
cmd->base.duplex);
return -EINVAL;
}
}
netif_dbg(pdata, link, netdev,
"requested advertisement 0x%*pb, phy supported 0x%*pb\n",
__ETHTOOL_LINK_MODE_MASK_NBITS, cmd->link_modes.advertising,
__ETHTOOL_LINK_MODE_MASK_NBITS, lks->link_modes.supported);
bitmap_and(advertising,
cmd->link_modes.advertising, lks->link_modes.supported,
__ETHTOOL_LINK_MODE_MASK_NBITS);
if ((cmd->base.autoneg == AUTONEG_ENABLE) &&
bitmap_empty(advertising, __ETHTOOL_LINK_MODE_MASK_NBITS)) {
netdev_err(netdev,
"unsupported requested advertisement\n");
return -EINVAL;
}
ret = 0;
pdata->phy.autoneg = cmd->base.autoneg;
pdata->phy.speed = speed;
pdata->phy.duplex = cmd->base.duplex;
bitmap_copy(lks->link_modes.advertising, advertising,
__ETHTOOL_LINK_MODE_MASK_NBITS);
if (cmd->base.autoneg == AUTONEG_ENABLE)
XGBE_SET_ADV(lks, Autoneg);
else
XGBE_CLR_ADV(lks, Autoneg);
if (netif_running(netdev))
ret = pdata->phy_if.phy_config_aneg(pdata);
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
}
static u32 xgbe_get_msglevel(struct net_device *netdev)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
return pdata->msg_enable;
}
static void xgbe_set_msglevel(struct net_device *netdev, u32 msglevel)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
pdata->msg_enable = msglevel;
}
static int xgbe_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
memset(ec, 0, sizeof(struct ethtool_coalesce));
ec->rx_coalesce_usecs = pdata->rx_usecs;
ec->rx_max_coalesced_frames = pdata->rx_frames;
ec->tx_max_coalesced_frames = pdata->tx_frames;
return 0;
}
static int xgbe_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned int rx_frames, rx_riwt, rx_usecs;
unsigned int tx_frames;
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
(ec->rate_sample_interval)) {
netdev_err(netdev, "unsupported coalescing parameter\n");
return -EOPNOTSUPP;
}
rx_riwt = hw_if->usec_to_riwt(pdata, ec->rx_coalesce_usecs);
rx_usecs = ec->rx_coalesce_usecs;
rx_frames = ec->rx_max_coalesced_frames;
if (rx_usecs && !rx_riwt)
rx_riwt = 1;
if (rx_riwt > XGMAC_MAX_DMA_RIWT) {
netdev_err(netdev, "rx-usec is limited to %d usecs\n",
hw_if->riwt_to_usec(pdata, XGMAC_MAX_DMA_RIWT));
return -EINVAL;
}
if (rx_frames > pdata->rx_desc_count) {
netdev_err(netdev, "rx-frames is limited to %d frames\n",
pdata->rx_desc_count);
return -EINVAL;
}
tx_frames = ec->tx_max_coalesced_frames;
if (tx_frames > pdata->tx_desc_count) {
netdev_err(netdev, "tx-frames is limited to %d frames\n",
pdata->tx_desc_count);
return -EINVAL;
}
pdata->rx_riwt = rx_riwt;
pdata->rx_usecs = rx_usecs;
pdata->rx_frames = rx_frames;
hw_if->config_rx_coalesce(pdata);
pdata->tx_frames = tx_frames;
hw_if->config_tx_coalesce(pdata);
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
if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP) {
netdev_err(netdev, "unsupported hash function\n");
return -EOPNOTSUPP;
}
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
const struct ethtool_ops *xgbe_get_ethtool_ops(void)
{
return &xgbe_ethtool_ops;
}
