static void stmmac_ethtool_getdrvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (priv->plat->has_gmac)
strlcpy(info->driver, GMAC_ETHTOOL_NAME, sizeof(info->driver));
else
strlcpy(info->driver, MAC100_ETHTOOL_NAME,
sizeof(info->driver));
strlcpy(info->version, DRV_MODULE_VERSION, sizeof(info->version));
}
static int stmmac_ethtool_getsettings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phy = priv->phydev;
int rc;
if (priv->hw->pcs & STMMAC_PCS_RGMII ||
priv->hw->pcs & STMMAC_PCS_SGMII) {
struct rgmii_adv adv;
if (!priv->xstats.pcs_link) {
ethtool_cmd_speed_set(cmd, SPEED_UNKNOWN);
cmd->duplex = DUPLEX_UNKNOWN;
return 0;
}
cmd->duplex = priv->xstats.pcs_duplex;
ethtool_cmd_speed_set(cmd, priv->xstats.pcs_speed);
if (!priv->hw->mac->pcs_get_adv_lp)
return -EOPNOTSUPP;
priv->hw->mac->pcs_get_adv_lp(priv->ioaddr, &adv);
if (adv.pause & STMMAC_PCS_PAUSE)
cmd->advertising |= ADVERTISED_Pause;
if (adv.pause & STMMAC_PCS_ASYM_PAUSE)
cmd->advertising |= ADVERTISED_Asym_Pause;
if (adv.lp_pause & STMMAC_PCS_PAUSE)
cmd->lp_advertising |= ADVERTISED_Pause;
if (adv.lp_pause & STMMAC_PCS_ASYM_PAUSE)
cmd->lp_advertising |= ADVERTISED_Asym_Pause;
cmd->autoneg = ADVERTISED_Autoneg;
cmd->supported |= SUPPORTED_Autoneg;
cmd->advertising |= ADVERTISED_Autoneg;
cmd->lp_advertising |= ADVERTISED_Autoneg;
if (adv.duplex) {
cmd->supported |= (SUPPORTED_1000baseT_Full |
SUPPORTED_100baseT_Full |
SUPPORTED_10baseT_Full);
cmd->advertising |= (ADVERTISED_1000baseT_Full |
ADVERTISED_100baseT_Full |
ADVERTISED_10baseT_Full);
} else {
cmd->supported |= (SUPPORTED_1000baseT_Half |
SUPPORTED_100baseT_Half |
SUPPORTED_10baseT_Half);
cmd->advertising |= (ADVERTISED_1000baseT_Half |
ADVERTISED_100baseT_Half |
ADVERTISED_10baseT_Half);
}
if (adv.lp_duplex)
cmd->lp_advertising |= (ADVERTISED_1000baseT_Full |
ADVERTISED_100baseT_Full |
ADVERTISED_10baseT_Full);
else
cmd->lp_advertising |= (ADVERTISED_1000baseT_Half |
ADVERTISED_100baseT_Half |
ADVERTISED_10baseT_Half);
cmd->port = PORT_OTHER;
return 0;
}
if (phy == NULL) {
pr_err("%s: %s: PHY is not registered\n",
__func__, dev->name);
return -ENODEV;
}
if (!netif_running(dev)) {
pr_err("%s: interface is disabled: we cannot track "
"link speed / duplex setting\n", dev->name);
return -EBUSY;
}
cmd->transceiver = XCVR_INTERNAL;
rc = phy_ethtool_gset(phy, cmd);
return rc;
}
static int stmmac_ethtool_setsettings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phy = priv->phydev;
int rc;
if (priv->hw->pcs & STMMAC_PCS_RGMII ||
priv->hw->pcs & STMMAC_PCS_SGMII) {
u32 mask = ADVERTISED_Autoneg | ADVERTISED_Pause;
if (cmd->autoneg != AUTONEG_ENABLE)
return -EINVAL;
mask &= (ADVERTISED_1000baseT_Half |
ADVERTISED_1000baseT_Full |
ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full |
ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full);
spin_lock(&priv->lock);
if (priv->hw->mac->pcs_ctrl_ane)
priv->hw->mac->pcs_ctrl_ane(priv->ioaddr, 1,
priv->hw->ps, 0);
spin_unlock(&priv->lock);
return 0;
}
spin_lock(&priv->lock);
rc = phy_ethtool_sset(phy, cmd);
spin_unlock(&priv->lock);
return rc;
}
static u32 stmmac_ethtool_getmsglevel(struct net_device *dev)
{
struct stmmac_priv *priv = netdev_priv(dev);
return priv->msg_enable;
}
static void stmmac_ethtool_setmsglevel(struct net_device *dev, u32 level)
{
struct stmmac_priv *priv = netdev_priv(dev);
priv->msg_enable = level;
}
static int stmmac_check_if_running(struct net_device *dev)
{
if (!netif_running(dev))
return -EBUSY;
return 0;
}
static int stmmac_ethtool_get_regs_len(struct net_device *dev)
{
return REG_SPACE_SIZE;
}
static void stmmac_ethtool_gregs(struct net_device *dev,
struct ethtool_regs *regs, void *space)
{
int i;
u32 *reg_space = (u32 *) space;
struct stmmac_priv *priv = netdev_priv(dev);
memset(reg_space, 0x0, REG_SPACE_SIZE);
if (!priv->plat->has_gmac) {
for (i = 0; i < 12; i++)
reg_space[i] = readl(priv->ioaddr + (i * 4));
for (i = 0; i < 9; i++)
reg_space[i + 12] =
readl(priv->ioaddr + (DMA_BUS_MODE + (i * 4)));
reg_space[22] = readl(priv->ioaddr + DMA_CUR_TX_BUF_ADDR);
reg_space[23] = readl(priv->ioaddr + DMA_CUR_RX_BUF_ADDR);
} else {
for (i = 0; i < 55; i++)
reg_space[i] = readl(priv->ioaddr + (i * 4));
for (i = 0; i < 22; i++)
reg_space[i + 55] =
readl(priv->ioaddr + (DMA_BUS_MODE + (i * 4)));
}
}
static void
stmmac_get_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct stmmac_priv *priv = netdev_priv(netdev);
pause->rx_pause = 0;
pause->tx_pause = 0;
if (priv->hw->pcs && priv->hw->mac->pcs_get_adv_lp) {
struct rgmii_adv adv_lp;
pause->autoneg = 1;
priv->hw->mac->pcs_get_adv_lp(priv->ioaddr, &adv_lp);
if (!adv_lp.pause)
return;
} else {
if (!(priv->phydev->supported & SUPPORTED_Pause) ||
!(priv->phydev->supported & SUPPORTED_Asym_Pause))
return;
}
pause->autoneg = priv->phydev->autoneg;
if (priv->flow_ctrl & FLOW_RX)
pause->rx_pause = 1;
if (priv->flow_ctrl & FLOW_TX)
pause->tx_pause = 1;
}
static int
stmmac_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct stmmac_priv *priv = netdev_priv(netdev);
struct phy_device *phy = priv->phydev;
int new_pause = FLOW_OFF;
if (priv->hw->pcs && priv->hw->mac->pcs_get_adv_lp) {
struct rgmii_adv adv_lp;
pause->autoneg = 1;
priv->hw->mac->pcs_get_adv_lp(priv->ioaddr, &adv_lp);
if (!adv_lp.pause)
return -EOPNOTSUPP;
} else {
if (!(phy->supported & SUPPORTED_Pause) ||
!(phy->supported & SUPPORTED_Asym_Pause))
return -EOPNOTSUPP;
}
if (pause->rx_pause)
new_pause |= FLOW_RX;
if (pause->tx_pause)
new_pause |= FLOW_TX;
priv->flow_ctrl = new_pause;
phy->autoneg = pause->autoneg;
if (phy->autoneg) {
if (netif_running(netdev))
return phy_start_aneg(phy);
}
priv->hw->mac->flow_ctrl(priv->hw, phy->duplex, priv->flow_ctrl,
priv->pause);
return 0;
}
static void stmmac_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *dummy, u64 *data)
{
struct stmmac_priv *priv = netdev_priv(dev);
int i, j = 0;
if (priv->hw->dma->dma_diagnostic_fr)
priv->hw->dma->dma_diagnostic_fr(&dev->stats,
(void *) &priv->xstats,
priv->ioaddr);
else {
if (priv->dma_cap.rmon) {
dwmac_mmc_read(priv->mmcaddr, &priv->mmc);
for (i = 0; i < STMMAC_MMC_STATS_LEN; i++) {
char *p;
p = (char *)priv + stmmac_mmc[i].stat_offset;
data[j++] = (stmmac_mmc[i].sizeof_stat ==
sizeof(u64)) ? (*(u64 *)p) :
(*(u32 *)p);
}
}
if (priv->eee_enabled) {
int val = phy_get_eee_err(priv->phydev);
if (val)
priv->xstats.phy_eee_wakeup_error_n = val;
}
if ((priv->hw->mac->debug) &&
(priv->synopsys_id >= DWMAC_CORE_3_50))
priv->hw->mac->debug(priv->ioaddr,
(void *)&priv->xstats);
}
for (i = 0; i < STMMAC_STATS_LEN; i++) {
char *p = (char *)priv + stmmac_gstrings_stats[i].stat_offset;
data[j++] = (stmmac_gstrings_stats[i].sizeof_stat ==
sizeof(u64)) ? (*(u64 *)p) : (*(u32 *)p);
}
}
static int stmmac_get_sset_count(struct net_device *netdev, int sset)
{
struct stmmac_priv *priv = netdev_priv(netdev);
int len;
switch (sset) {
case ETH_SS_STATS:
len = STMMAC_STATS_LEN;
if (priv->dma_cap.rmon)
len += STMMAC_MMC_STATS_LEN;
return len;
default:
return -EOPNOTSUPP;
}
}
static void stmmac_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
int i;
u8 *p = data;
struct stmmac_priv *priv = netdev_priv(dev);
switch (stringset) {
case ETH_SS_STATS:
if (priv->dma_cap.rmon)
for (i = 0; i < STMMAC_MMC_STATS_LEN; i++) {
memcpy(p, stmmac_mmc[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < STMMAC_STATS_LEN; i++) {
memcpy(p, stmmac_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
default:
WARN_ON(1);
break;
}
}
static void stmmac_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct stmmac_priv *priv = netdev_priv(dev);
spin_lock_irq(&priv->lock);
if (device_can_wakeup(priv->device)) {
wol->supported = WAKE_MAGIC | WAKE_UCAST;
wol->wolopts = priv->wolopts;
}
spin_unlock_irq(&priv->lock);
}
static int stmmac_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct stmmac_priv *priv = netdev_priv(dev);
u32 support = WAKE_MAGIC | WAKE_UCAST;
if ((priv->hw_cap_support) && (!priv->dma_cap.pmt_magic_frame))
wol->wolopts &= ~WAKE_MAGIC;
if (!device_can_wakeup(priv->device))
return -EINVAL;
if (wol->wolopts & ~support)
return -EINVAL;
if (wol->wolopts) {
pr_info("stmmac: wakeup enable\n");
device_set_wakeup_enable(priv->device, 1);
enable_irq_wake(priv->wol_irq);
} else {
device_set_wakeup_enable(priv->device, 0);
disable_irq_wake(priv->wol_irq);
}
spin_lock_irq(&priv->lock);
priv->wolopts = wol->wolopts;
spin_unlock_irq(&priv->lock);
return 0;
}
static int stmmac_ethtool_op_get_eee(struct net_device *dev,
struct ethtool_eee *edata)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (!priv->dma_cap.eee)
return -EOPNOTSUPP;
edata->eee_enabled = priv->eee_enabled;
edata->eee_active = priv->eee_active;
edata->tx_lpi_timer = priv->tx_lpi_timer;
return phy_ethtool_get_eee(priv->phydev, edata);
}
static int stmmac_ethtool_op_set_eee(struct net_device *dev,
struct ethtool_eee *edata)
{
struct stmmac_priv *priv = netdev_priv(dev);
priv->eee_enabled = edata->eee_enabled;
if (!priv->eee_enabled)
stmmac_disable_eee_mode(priv);
else {
priv->eee_enabled = stmmac_eee_init(priv);
if (!priv->eee_enabled)
return -EOPNOTSUPP;
priv->tx_lpi_timer = edata->tx_lpi_timer;
}
return phy_ethtool_set_eee(priv->phydev, edata);
}
static u32 stmmac_usec2riwt(u32 usec, struct stmmac_priv *priv)
{
unsigned long clk = clk_get_rate(priv->stmmac_clk);
if (!clk)
return 0;
return (usec * (clk / 1000000)) / 256;
}
static u32 stmmac_riwt2usec(u32 riwt, struct stmmac_priv *priv)
{
unsigned long clk = clk_get_rate(priv->stmmac_clk);
if (!clk)
return 0;
return (riwt * 256) / (clk / 1000000);
}
static int stmmac_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct stmmac_priv *priv = netdev_priv(dev);
ec->tx_coalesce_usecs = priv->tx_coal_timer;
ec->tx_max_coalesced_frames = priv->tx_coal_frames;
if (priv->use_riwt)
ec->rx_coalesce_usecs = stmmac_riwt2usec(priv->rx_riwt, priv);
return 0;
}
static int stmmac_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *ec)
{
struct stmmac_priv *priv = netdev_priv(dev);
unsigned int rx_riwt;
if ((ec->rx_max_coalesced_frames) || (ec->rx_coalesce_usecs_irq) ||
(ec->rx_max_coalesced_frames_irq) || (ec->tx_coalesce_usecs_irq) ||
(ec->use_adaptive_rx_coalesce) || (ec->use_adaptive_tx_coalesce) ||
(ec->pkt_rate_low) || (ec->rx_coalesce_usecs_low) ||
(ec->rx_max_coalesced_frames_low) || (ec->tx_coalesce_usecs_high) ||
(ec->tx_max_coalesced_frames_low) || (ec->pkt_rate_high) ||
(ec->tx_coalesce_usecs_low) || (ec->rx_coalesce_usecs_high) ||
(ec->rx_max_coalesced_frames_high) ||
(ec->tx_max_coalesced_frames_irq) ||
(ec->stats_block_coalesce_usecs) ||
(ec->tx_max_coalesced_frames_high) || (ec->rate_sample_interval))
return -EOPNOTSUPP;
if (ec->rx_coalesce_usecs == 0)
return -EINVAL;
if ((ec->tx_coalesce_usecs == 0) &&
(ec->tx_max_coalesced_frames == 0))
return -EINVAL;
if ((ec->tx_coalesce_usecs > STMMAC_MAX_COAL_TX_TICK) ||
(ec->tx_max_coalesced_frames > STMMAC_TX_MAX_FRAMES))
return -EINVAL;
rx_riwt = stmmac_usec2riwt(ec->rx_coalesce_usecs, priv);
if ((rx_riwt > MAX_DMA_RIWT) || (rx_riwt < MIN_DMA_RIWT))
return -EINVAL;
else if (!priv->use_riwt)
return -EOPNOTSUPP;
priv->tx_coal_frames = ec->tx_max_coalesced_frames;
priv->tx_coal_timer = ec->tx_coalesce_usecs;
priv->rx_riwt = rx_riwt;
priv->hw->dma->rx_watchdog(priv->ioaddr, priv->rx_riwt);
return 0;
}
static int stmmac_get_ts_info(struct net_device *dev,
struct ethtool_ts_info *info)
{
struct stmmac_priv *priv = netdev_priv(dev);
if ((priv->dma_cap.time_stamp || priv->dma_cap.atime_stamp)) {
info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
SOF_TIMESTAMPING_TX_HARDWARE |
SOF_TIMESTAMPING_RX_SOFTWARE |
SOF_TIMESTAMPING_RX_HARDWARE |
SOF_TIMESTAMPING_SOFTWARE |
SOF_TIMESTAMPING_RAW_HARDWARE;
if (priv->ptp_clock)
info->phc_index = ptp_clock_index(priv->ptp_clock);
info->tx_types = (1 << HWTSTAMP_TX_OFF) | (1 << HWTSTAMP_TX_ON);
info->rx_filters = ((1 << HWTSTAMP_FILTER_NONE) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_PTP_V2_EVENT) |
(1 << HWTSTAMP_FILTER_PTP_V2_SYNC) |
(1 << HWTSTAMP_FILTER_PTP_V2_DELAY_REQ) |
(1 << HWTSTAMP_FILTER_ALL));
return 0;
} else
return ethtool_op_get_ts_info(dev, info);
}
static int stmmac_get_tunable(struct net_device *dev,
const struct ethtool_tunable *tuna, void *data)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret = 0;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
*(u32 *)data = priv->rx_copybreak;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int stmmac_set_tunable(struct net_device *dev,
const struct ethtool_tunable *tuna,
const void *data)
{
struct stmmac_priv *priv = netdev_priv(dev);
int ret = 0;
switch (tuna->id) {
case ETHTOOL_RX_COPYBREAK:
priv->rx_copybreak = *(u32 *)data;
break;
default:
ret = -EINVAL;
break;
}
return ret;
}
void stmmac_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &stmmac_ethtool_ops;
}
