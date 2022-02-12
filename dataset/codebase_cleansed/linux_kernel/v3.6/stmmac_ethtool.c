static void stmmac_ethtool_getdrvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct stmmac_priv *priv = netdev_priv(dev);
if (priv->plat->has_gmac)
strlcpy(info->driver, GMAC_ETHTOOL_NAME, sizeof(info->driver));
else
strlcpy(info->driver, MAC100_ETHTOOL_NAME,
sizeof(info->driver));
strcpy(info->version, DRV_MODULE_VERSION);
info->fw_version[0] = '\0';
}
static int stmmac_ethtool_getsettings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phy = priv->phydev;
int rc;
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
spin_lock_irq(&priv->lock);
rc = phy_ethtool_gset(phy, cmd);
spin_unlock_irq(&priv->lock);
return rc;
}
static int stmmac_ethtool_setsettings(struct net_device *dev,
struct ethtool_cmd *cmd)
{
struct stmmac_priv *priv = netdev_priv(dev);
struct phy_device *phy = priv->phydev;
int rc;
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
spin_lock(&priv->lock);
pause->rx_pause = 0;
pause->tx_pause = 0;
pause->autoneg = priv->phydev->autoneg;
if (priv->flow_ctrl & FLOW_RX)
pause->rx_pause = 1;
if (priv->flow_ctrl & FLOW_TX)
pause->tx_pause = 1;
spin_unlock(&priv->lock);
}
static int
stmmac_set_pauseparam(struct net_device *netdev,
struct ethtool_pauseparam *pause)
{
struct stmmac_priv *priv = netdev_priv(netdev);
struct phy_device *phy = priv->phydev;
int new_pause = FLOW_OFF;
int ret = 0;
spin_lock(&priv->lock);
if (pause->rx_pause)
new_pause |= FLOW_RX;
if (pause->tx_pause)
new_pause |= FLOW_TX;
priv->flow_ctrl = new_pause;
phy->autoneg = pause->autoneg;
if (phy->autoneg) {
if (netif_running(netdev))
ret = phy_start_aneg(phy);
} else
priv->hw->mac->flow_ctrl(priv->ioaddr, phy->duplex,
priv->flow_ctrl, priv->pause);
spin_unlock(&priv->lock);
return ret;
}
static void stmmac_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *dummy, u64 *data)
{
struct stmmac_priv *priv = netdev_priv(dev);
int i, j = 0;
if (!priv->plat->has_gmac)
priv->hw->dma->dma_diagnostic_fr(&dev->stats,
(void *) &priv->xstats,
priv->ioaddr);
else {
if (priv->dma_cap.rmon) {
dwmac_mmc_read(priv->ioaddr, &priv->mmc);
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
void stmmac_set_ethtool_ops(struct net_device *netdev)
{
SET_ETHTOOL_OPS(netdev, &stmmac_ethtool_ops);
}
