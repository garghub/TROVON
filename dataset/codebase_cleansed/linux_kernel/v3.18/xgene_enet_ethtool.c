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
static int xgene_get_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
struct phy_device *phydev = pdata->phy_dev;
if (pdata->phy_mode == PHY_INTERFACE_MODE_RGMII) {
if (phydev == NULL)
return -ENODEV;
return phy_ethtool_gset(phydev, cmd);
} else if (pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
cmd->supported = SUPPORTED_1000baseT_Full |
SUPPORTED_Autoneg | SUPPORTED_MII;
cmd->advertising = cmd->supported;
ethtool_cmd_speed_set(cmd, SPEED_1000);
cmd->duplex = DUPLEX_FULL;
cmd->port = PORT_MII;
cmd->transceiver = XCVR_INTERNAL;
cmd->autoneg = AUTONEG_ENABLE;
} else {
cmd->supported = SUPPORTED_10000baseT_Full | SUPPORTED_FIBRE;
cmd->advertising = cmd->supported;
ethtool_cmd_speed_set(cmd, SPEED_10000);
cmd->duplex = DUPLEX_FULL;
cmd->port = PORT_FIBRE;
cmd->transceiver = XCVR_INTERNAL;
cmd->autoneg = AUTONEG_DISABLE;
}
return 0;
}
static int xgene_set_settings(struct net_device *ndev, struct ethtool_cmd *cmd)
{
struct xgene_enet_pdata *pdata = netdev_priv(ndev);
struct phy_device *phydev = pdata->phy_dev;
if (pdata->phy_mode == PHY_INTERFACE_MODE_RGMII) {
if (phydev == NULL)
return -ENODEV;
return phy_ethtool_sset(phydev, cmd);
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
