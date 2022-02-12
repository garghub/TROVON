static void xlgmac_ethtool_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct xlgmac_pdata *pdata = netdev_priv(netdev);
u32 ver = pdata->hw_feat.version;
u32 snpsver, devid, userver;
strlcpy(drvinfo->driver, pdata->drv_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, pdata->drv_ver, sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, dev_name(pdata->dev),
sizeof(drvinfo->bus_info));
snpsver = XLGMAC_GET_REG_BITS(ver, MAC_VR_SNPSVER_POS,
MAC_VR_SNPSVER_LEN);
devid = XLGMAC_GET_REG_BITS(ver, MAC_VR_DEVID_POS,
MAC_VR_DEVID_LEN);
userver = XLGMAC_GET_REG_BITS(ver, MAC_VR_USERVER_POS,
MAC_VR_USERVER_LEN);
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"S.D.U: %x.%x.%x", snpsver, devid, userver);
}
static u32 xlgmac_ethtool_get_msglevel(struct net_device *netdev)
{
struct xlgmac_pdata *pdata = netdev_priv(netdev);
return pdata->msg_enable;
}
static void xlgmac_ethtool_set_msglevel(struct net_device *netdev,
u32 msglevel)
{
struct xlgmac_pdata *pdata = netdev_priv(netdev);
pdata->msg_enable = msglevel;
}
static void xlgmac_ethtool_get_channels(struct net_device *netdev,
struct ethtool_channels *channel)
{
struct xlgmac_pdata *pdata = netdev_priv(netdev);
channel->max_rx = XLGMAC_MAX_DMA_CHANNELS;
channel->max_tx = XLGMAC_MAX_DMA_CHANNELS;
channel->rx_count = pdata->rx_q_count;
channel->tx_count = pdata->tx_q_count;
}
static int xlgmac_ethtool_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct xlgmac_pdata *pdata = netdev_priv(netdev);
memset(ec, 0, sizeof(struct ethtool_coalesce));
ec->rx_coalesce_usecs = pdata->rx_usecs;
ec->rx_max_coalesced_frames = pdata->rx_frames;
ec->tx_max_coalesced_frames = pdata->tx_frames;
return 0;
}
static int xlgmac_ethtool_set_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct xlgmac_pdata *pdata = netdev_priv(netdev);
struct xlgmac_hw_ops *hw_ops = &pdata->hw_ops;
unsigned int rx_frames, rx_riwt, rx_usecs;
unsigned int tx_frames;
if ((ec->rx_coalesce_usecs_irq) || (ec->rx_max_coalesced_frames_irq) ||
(ec->tx_coalesce_usecs) || (ec->tx_coalesce_usecs_high) ||
(ec->tx_max_coalesced_frames_irq) || (ec->tx_coalesce_usecs_irq) ||
(ec->stats_block_coalesce_usecs) || (ec->pkt_rate_low) ||
(ec->use_adaptive_rx_coalesce) || (ec->use_adaptive_tx_coalesce) ||
(ec->rx_max_coalesced_frames_low) || (ec->rx_coalesce_usecs_low) ||
(ec->tx_coalesce_usecs_low) || (ec->tx_max_coalesced_frames_low) ||
(ec->pkt_rate_high) || (ec->rx_coalesce_usecs_high) ||
(ec->rx_max_coalesced_frames_high) ||
(ec->tx_max_coalesced_frames_high) ||
(ec->rate_sample_interval))
return -EOPNOTSUPP;
rx_usecs = ec->rx_coalesce_usecs;
rx_riwt = hw_ops->usec_to_riwt(pdata, rx_usecs);
rx_frames = ec->rx_max_coalesced_frames;
tx_frames = ec->tx_max_coalesced_frames;
if ((rx_riwt > XLGMAC_MAX_DMA_RIWT) ||
(rx_riwt < XLGMAC_MIN_DMA_RIWT) ||
(rx_frames > pdata->rx_desc_count))
return -EINVAL;
if (tx_frames > pdata->tx_desc_count)
return -EINVAL;
pdata->rx_riwt = rx_riwt;
pdata->rx_usecs = rx_usecs;
pdata->rx_frames = rx_frames;
hw_ops->config_rx_coalesce(pdata);
pdata->tx_frames = tx_frames;
hw_ops->config_tx_coalesce(pdata);
return 0;
}
static void xlgmac_ethtool_get_strings(struct net_device *netdev,
u32 stringset, u8 *data)
{
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < XLGMAC_STATS_COUNT; i++) {
memcpy(data, xlgmac_gstring_stats[i].stat_string,
ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
break;
default:
WARN_ON(1);
break;
}
}
static int xlgmac_ethtool_get_sset_count(struct net_device *netdev,
int stringset)
{
int ret;
switch (stringset) {
case ETH_SS_STATS:
ret = XLGMAC_STATS_COUNT;
break;
default:
ret = -EOPNOTSUPP;
}
return ret;
}
static void xlgmac_ethtool_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats,
u64 *data)
{
struct xlgmac_pdata *pdata = netdev_priv(netdev);
u8 *stat;
int i;
pdata->hw_ops.read_mmc_stats(pdata);
for (i = 0; i < XLGMAC_STATS_COUNT; i++) {
stat = (u8 *)pdata + xlgmac_gstring_stats[i].stat_offset;
*data++ = *(u64 *)stat;
}
}
const struct ethtool_ops *xlgmac_get_ethtool_ops(void)
{
return &xlgmac_ethtool_ops;
}
