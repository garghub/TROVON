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
pause->autoneg = pdata->pause_autoneg;
pause->tx_pause = pdata->tx_pause;
pause->rx_pause = pdata->rx_pause;
DBGPR("<--xgbe_get_pauseparam\n");
}
static int xgbe_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct phy_device *phydev = pdata->phydev;
int ret = 0;
DBGPR("-->xgbe_set_pauseparam\n");
DBGPR(" autoneg = %d, tx_pause = %d, rx_pause = %d\n",
pause->autoneg, pause->tx_pause, pause->rx_pause);
pdata->pause_autoneg = pause->autoneg;
if (pause->autoneg) {
phydev->advertising |= ADVERTISED_Pause;
phydev->advertising |= ADVERTISED_Asym_Pause;
} else {
phydev->advertising &= ~ADVERTISED_Pause;
phydev->advertising &= ~ADVERTISED_Asym_Pause;
pdata->tx_pause = pause->tx_pause;
pdata->rx_pause = pause->rx_pause;
}
if (netif_running(netdev))
ret = phy_start_aneg(phydev);
DBGPR("<--xgbe_set_pauseparam\n");
return ret;
}
static int xgbe_get_settings(struct net_device *netdev,
struct ethtool_cmd *cmd)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
int ret;
DBGPR("-->xgbe_get_settings\n");
if (!pdata->phydev)
return -ENODEV;
spin_lock_irq(&pdata->lock);
ret = phy_ethtool_gset(pdata->phydev, cmd);
cmd->transceiver = XCVR_EXTERNAL;
spin_unlock_irq(&pdata->lock);
DBGPR("<--xgbe_get_settings\n");
return ret;
}
static int xgbe_set_settings(struct net_device *netdev,
struct ethtool_cmd *cmd)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct phy_device *phydev = pdata->phydev;
u32 speed;
int ret;
DBGPR("-->xgbe_set_settings\n");
if (!pdata->phydev)
return -ENODEV;
spin_lock_irq(&pdata->lock);
speed = ethtool_cmd_speed(cmd);
ret = -EINVAL;
if (cmd->phy_address != phydev->addr)
goto unlock;
if ((cmd->autoneg != AUTONEG_ENABLE) &&
(cmd->autoneg != AUTONEG_DISABLE))
goto unlock;
if ((cmd->autoneg == AUTONEG_DISABLE) &&
(((speed != SPEED_10000) && (speed != SPEED_1000)) ||
(cmd->duplex != DUPLEX_FULL)))
goto unlock;
if (cmd->autoneg == AUTONEG_ENABLE) {
phydev->supported &= ~SUPPORTED_1000baseT_Full;
phydev->supported &= ~SUPPORTED_10000baseT_Full;
} else {
phydev->supported |= SUPPORTED_1000baseT_Full;
phydev->supported |= SUPPORTED_10000baseT_Full;
}
cmd->advertising &= phydev->supported;
if ((cmd->autoneg == AUTONEG_ENABLE) && !cmd->advertising)
goto unlock;
ret = 0;
phydev->autoneg = cmd->autoneg;
phydev->speed = speed;
phydev->duplex = cmd->duplex;
phydev->advertising = cmd->advertising;
if (cmd->autoneg == AUTONEG_ENABLE)
phydev->advertising |= ADVERTISED_Autoneg;
else
phydev->advertising &= ~ADVERTISED_Autoneg;
if (netif_running(netdev))
ret = phy_start_aneg(phydev);
unlock:
spin_unlock_irq(&pdata->lock);
DBGPR("<--xgbe_set_settings\n");
return ret;
}
static void xgbe_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
strlcpy(drvinfo->driver, XGBE_DRV_NAME, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, XGBE_DRV_VERSION, sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, dev_name(pdata->dev),
sizeof(drvinfo->bus_info));
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version), "%d.%d.%d",
XGMAC_IOREAD_BITS(pdata, MAC_VR, USERVER),
XGMAC_IOREAD_BITS(pdata, MAC_VR, DEVID),
XGMAC_IOREAD_BITS(pdata, MAC_VR, SNPSVER));
drvinfo->n_stats = XGBE_STATS_COUNT;
}
static int xgbe_get_coalesce(struct net_device *netdev,
struct ethtool_coalesce *ec)
{
struct xgbe_prv_data *pdata = netdev_priv(netdev);
struct xgbe_hw_if *hw_if = &pdata->hw_if;
unsigned int riwt;
DBGPR("-->xgbe_get_coalesce\n");
memset(ec, 0, sizeof(struct ethtool_coalesce));
riwt = pdata->rx_riwt;
ec->rx_coalesce_usecs = hw_if->riwt_to_usec(pdata, riwt);
ec->rx_max_coalesced_frames = pdata->rx_frames;
ec->tx_coalesce_usecs = pdata->tx_usecs;
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
unsigned int tx_frames, tx_usecs;
DBGPR("-->xgbe_set_coalesce\n");
if ((ec->rx_coalesce_usecs_irq) ||
(ec->rx_max_coalesced_frames_irq) ||
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
rx_frames = pdata->rx_frames;
if (rx_frames != ec->rx_max_coalesced_frames && netif_running(netdev)) {
netdev_alert(netdev,
"interface must be down to change rx-frames\n");
return -EINVAL;
}
rx_riwt = hw_if->usec_to_riwt(pdata, ec->rx_coalesce_usecs);
rx_frames = ec->rx_max_coalesced_frames;
if (ec->rx_coalesce_usecs && !rx_riwt)
rx_riwt = 1;
if (rx_riwt > XGMAC_MAX_DMA_RIWT) {
rx_usecs = hw_if->riwt_to_usec(pdata, XGMAC_MAX_DMA_RIWT);
netdev_alert(netdev, "rx-usec is limited to %d usecs\n",
rx_usecs);
return -EINVAL;
}
if (rx_frames > pdata->channel->rx_ring->rdesc_count) {
netdev_alert(netdev, "rx-frames is limited to %d frames\n",
pdata->channel->rx_ring->rdesc_count);
return -EINVAL;
}
tx_usecs = ec->tx_coalesce_usecs;
tx_frames = ec->tx_max_coalesced_frames;
if (tx_frames > pdata->channel->tx_ring->rdesc_count) {
netdev_alert(netdev, "tx-frames is limited to %d frames\n",
pdata->channel->tx_ring->rdesc_count);
return -EINVAL;
}
pdata->rx_riwt = rx_riwt;
pdata->rx_frames = rx_frames;
hw_if->config_rx_coalesce(pdata);
pdata->tx_usecs = tx_usecs;
pdata->tx_frames = tx_frames;
hw_if->config_tx_coalesce(pdata);
DBGPR("<--xgbe_set_coalesce\n");
return 0;
}
struct ethtool_ops *xgbe_get_ethtool_ops(void)
{
return (struct ethtool_ops *)&xgbe_ethtool_ops;
}
