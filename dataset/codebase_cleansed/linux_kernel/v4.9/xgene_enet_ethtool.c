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
if (pdata->phy_mode == PHY_INTERFACE_MODE_RGMII) {
if (phydev == NULL)
return -ENODEV;
return phy_ethtool_ksettings_get(phydev, cmd);
} else if (pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
if (pdata->mdio_driver) {
if (!phydev)
return -ENODEV;
return phy_ethtool_ksettings_get(phydev, cmd);
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
if (pdata->phy_mode == PHY_INTERFACE_MODE_RGMII) {
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
}
static int xgene_get_sset_count(struct net_device *ndev, int sset)
{
if (sset != ETH_SS_STATS)
return -EINVAL;
return XGENE_STATS_LEN;
}
static void xgene_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *dummy,
u64 *data)
{
void *pdata = netdev_priv(ndev);
int i;
for (i = 0; i < XGENE_STATS_LEN; i++)
*data++ = *(u64 *)(pdata + gstrings_stats[i].offset);
}
void xgene_enet_set_ethtool_ops(struct net_device *ndev)
{
ndev->ethtool_ops = &xgene_ethtool_ops;
}
