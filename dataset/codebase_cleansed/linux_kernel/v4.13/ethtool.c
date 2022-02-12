static void xge_mac_get_extd_stats(struct xge_pdata *pdata)
{
u32 data;
int i;
for (i = 0; i < XGE_EXTD_STATS_LEN; i++) {
data = xge_rd_csr(pdata, gstrings_extd_stats[i].addr);
gstrings_extd_stats[i].value += data;
}
}
static void xge_get_drvinfo(struct net_device *ndev,
struct ethtool_drvinfo *info)
{
struct xge_pdata *pdata = netdev_priv(ndev);
struct platform_device *pdev = pdata->pdev;
strcpy(info->driver, "xgene-enet-v2");
strcpy(info->version, XGENE_ENET_V2_VERSION);
snprintf(info->fw_version, ETHTOOL_FWVERS_LEN, "N/A");
sprintf(info->bus_info, "%s", pdev->name);
}
static void xge_get_strings(struct net_device *ndev, u32 stringset, u8 *data)
{
u8 *p = data;
int i;
if (stringset != ETH_SS_STATS)
return;
for (i = 0; i < XGE_STATS_LEN; i++) {
memcpy(p, gstrings_stats[i].name, ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
for (i = 0; i < XGE_EXTD_STATS_LEN; i++) {
memcpy(p, gstrings_extd_stats[i].name, ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
}
static int xge_get_sset_count(struct net_device *ndev, int sset)
{
if (sset != ETH_SS_STATS)
return -EINVAL;
return XGE_STATS_LEN + XGE_EXTD_STATS_LEN;
}
static void xge_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *dummy,
u64 *data)
{
void *pdata = netdev_priv(ndev);
int i;
for (i = 0; i < XGE_STATS_LEN; i++)
*data++ = *(u64 *)(pdata + gstrings_stats[i].offset);
xge_mac_get_extd_stats(pdata);
for (i = 0; i < XGE_EXTD_STATS_LEN; i++)
*data++ = gstrings_extd_stats[i].value;
}
static int xge_get_link_ksettings(struct net_device *ndev,
struct ethtool_link_ksettings *cmd)
{
struct phy_device *phydev = ndev->phydev;
if (!phydev)
return -ENODEV;
phy_ethtool_ksettings_get(phydev, cmd);
return 0;
}
static int xge_set_link_ksettings(struct net_device *ndev,
const struct ethtool_link_ksettings *cmd)
{
struct phy_device *phydev = ndev->phydev;
if (!phydev)
return -ENODEV;
return phy_ethtool_ksettings_set(phydev, cmd);
}
void xge_set_ethtool_ops(struct net_device *ndev)
{
ndev->ethtool_ops = &xge_ethtool_ops;
}
