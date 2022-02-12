static void xgene_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
struct platform_device *pdev = pdata->pdev;
strcpy(info->driver, "xgene_enet");
strcpy(info->version, XGENE_DRV_VERSION);
snprintf(info->fw_version, ETHTOOL_FWVERS_LEN, "N/A");
sprintf(info->bus_info, "%s", pdev->name);
}
static int xgene_get_link_ksettings(struct net_device *ndev,
struct ethtool_link_ksettings *cmd)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
struct phy_device *phydev = ndev->phydev;
u32 supported;
if (phy_interface_mode_is_rgmii(pdata->phy_mode)) {
if (phydev == NULL)
return -ENODEV;
phy_ethtool_ksettings_get(phydev, cmd);
return 0;
} else if (pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
if (pdata->mdio_driver) {
if (!phydev)
return -ENODEV;
phy_ethtool_ksettings_get(phydev, cmd);
return 0;
}
supported = SUPPORTED_1000baseT_Full | SUPPORTED_Autoneg |
SUPPORTED_MII;
ethtool_convert_legacy_u32_to_link_mode(
cmd->link_modes.supported,
supported);
ethtool_convert_legacy_u32_to_link_mode(
cmd->link_modes.advertising,
supported);
cmd->base.speed = SPEED_1000;
cmd->base.duplex = DUPLEX_FULL;
cmd->base.port = PORT_MII;
cmd->base.autoneg = AUTONEG_ENABLE;
} else {
supported = SUPPORTED_10000baseT_Full | SUPPORTED_FIBRE;
ethtool_convert_legacy_u32_to_link_mode(
cmd->link_modes.supported,
supported);
ethtool_convert_legacy_u32_to_link_mode(
cmd->link_modes.advertising,
supported);
cmd->base.speed = SPEED_10000;
cmd->base.duplex = DUPLEX_FULL;
cmd->base.port = PORT_FIBRE;
cmd->base.autoneg = AUTONEG_DISABLE;
}
return 0;
}
static int xgene_set_link_ksettings(struct net_device *ndev,
const struct ethtool_link_ksettings *cmd)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
struct phy_device *phydev = ndev->phydev;
if (phy_interface_mode_is_rgmii(pdata->phy_mode)) {
if (!phydev)
return -ENODEV;
return phy_ethtool_ksettings_set(phydev, cmd);
}
if (pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
if (pdata->mdio_driver) {
if (!phydev)
return -ENODEV;
return phy_ethtool_ksettings_set(phydev, cmd);
}
}
return -EINVAL;
}
static void xgene_get_strings(struct net_device *ndev, u32 stringset, u8 *data)
{
int i;
u8 *p = data;
if (stringset != ETH_SS_STATS)
return;
for (i = 0; i < XGENE_STATS_LEN; i++) {
memcpy(p, gstrings_stats[i].name, ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < XGENE_EXTD_STATS_LEN; i++) {
memcpy(p, gstrings_extd_stats[i].name, ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
}
static int xgene_get_sset_count(struct net_device *ndev, int sset)
{
if (sset != ETH_SS_STATS)
return -EINVAL;
return XGENE_STATS_LEN + XGENE_EXTD_STATS_LEN;
}
static void xgene_get_extd_stats(struct xgene_enet_pdata *pdata)
{
u32 rx_drop, tx_drop;
u32 mask, tmp;
int i;
for (i = 0; i < XGENE_EXTD_STATS_LEN; i++) {
tmp = xgene_enet_rd_stat(pdata, gstrings_extd_stats[i].addr);
if (gstrings_extd_stats[i].mask) {
mask = GENMASK(gstrings_extd_stats[i].mask - 1, 0);
pdata->extd_stats[i] += (tmp & mask);
}
}
if (pdata->phy_mode == PHY_INTERFACE_MODE_XGMII) {
pdata->extd_stats[RALN_IDX] = 0;
} else {
pdata->extd_stats[RFCS_IDX] -= pdata->extd_stats[RALN_IDX];
pdata->extd_stats[RFLR_IDX] -= pdata->extd_stats[RUND_IDX];
pdata->extd_stats[TFCS_IDX] -= pdata->extd_stats[TFRG_IDX];
}
pdata->mac_ops->get_drop_cnt(pdata, &rx_drop, &tx_drop);
pdata->extd_stats[RX_OVERRUN_IDX] += rx_drop;
pdata->extd_stats[TX_UNDERRUN_IDX] += tx_drop;
pdata->extd_stats[FALSE_RFLR_IDX] = pdata->false_rflr;
pdata->extd_stats[FALSE_RJBR_IDX] = pdata->vlan_rjbr;
}
int xgene_extd_stats_init(struct xgene_enet_pdata *pdata)
{
pdata->extd_stats = devm_kmalloc_array(&pdata->pdev->dev,
XGENE_EXTD_STATS_LEN, sizeof(u64), GFP_KERNEL);
if (!pdata->extd_stats)
return -ENOMEM;
xgene_get_extd_stats(pdata);
memset(pdata->extd_stats, 0, XGENE_EXTD_STATS_LEN * sizeof(u64));
return 0;
}
static void xgene_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *dummy,
u64 *data)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
struct rtnl_link_stats64 stats;
int i;
dev_get_stats(ndev, &stats);
for (i = 0; i < XGENE_STATS_LEN; i++)
data[i] = *(u64 *)((char *)&stats + gstrings_stats[i].offset);
xgene_get_extd_stats(pdata);
for (i = 0; i < XGENE_EXTD_STATS_LEN; i++)
data[i + XGENE_STATS_LEN] = pdata->extd_stats[i];
}
static void xgene_get_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pp)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
pp->autoneg = pdata->pause_autoneg;
pp->tx_pause = pdata->tx_pause;
pp->rx_pause = pdata->rx_pause;
}
static int xgene_set_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pp)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
struct phy_device *phydev = ndev->phydev;
u32 oldadv, newadv;
if (phy_interface_mode_is_rgmii(pdata->phy_mode) ||
pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
if (!phydev)
return -EINVAL;
if (!(phydev->supported & SUPPORTED_Pause) ||
(!(phydev->supported & SUPPORTED_Asym_Pause) &&
pp->rx_pause != pp->tx_pause))
return -EINVAL;
pdata->pause_autoneg = pp->autoneg;
pdata->tx_pause = pp->tx_pause;
pdata->rx_pause = pp->rx_pause;
oldadv = phydev->advertising;
newadv = oldadv & ~(ADVERTISED_Pause | ADVERTISED_Asym_Pause);
if (pp->rx_pause)
newadv |= ADVERTISED_Pause | ADVERTISED_Asym_Pause;
if (pp->tx_pause)
newadv ^= ADVERTISED_Asym_Pause;
if (oldadv ^ newadv) {
phydev->advertising = newadv;
if (phydev->autoneg)
return phy_start_aneg(phydev);
if (!pp->autoneg) {
pdata->mac_ops->flowctl_tx(pdata,
pdata->tx_pause);
pdata->mac_ops->flowctl_rx(pdata,
pdata->rx_pause);
}
}
} else {
if (pp->autoneg)
return -EINVAL;
pdata->tx_pause = pp->tx_pause;
pdata->rx_pause = pp->rx_pause;
pdata->mac_ops->flowctl_tx(pdata, pdata->tx_pause);
pdata->mac_ops->flowctl_rx(pdata, pdata->rx_pause);
}
return 0;
}
void xgene_enet_set_ethtool_ops(struct net_device *ndev)
{
ndev->ethtool_ops = &xgene_ethtool_ops;
}
