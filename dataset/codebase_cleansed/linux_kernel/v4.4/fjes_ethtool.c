static void fjes_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct fjes_adapter *adapter = netdev_priv(netdev);
char *p;
int i;
for (i = 0; i < ARRAY_SIZE(fjes_gstrings_stats); i++) {
p = (char *)adapter + fjes_gstrings_stats[i].stat_offset;
data[i] = (fjes_gstrings_stats[i].sizeof_stat == sizeof(u64))
? *(u64 *)p : *(u32 *)p;
}
}
static void fjes_get_strings(struct net_device *netdev,
u32 stringset, u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < ARRAY_SIZE(fjes_gstrings_stats); i++) {
memcpy(p, fjes_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
}
}
static int fjes_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(fjes_gstrings_stats);
default:
return -EOPNOTSUPP;
}
}
static void fjes_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct fjes_adapter *adapter = netdev_priv(netdev);
struct platform_device *plat_dev;
plat_dev = adapter->plat_dev;
strlcpy(drvinfo->driver, fjes_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, fjes_driver_version,
sizeof(drvinfo->version));
strlcpy(drvinfo->fw_version, "none", sizeof(drvinfo->fw_version));
snprintf(drvinfo->bus_info, sizeof(drvinfo->bus_info),
"platform:%s", plat_dev->name);
}
static int fjes_get_settings(struct net_device *netdev,
struct ethtool_cmd *ecmd)
{
ecmd->supported = 0;
ecmd->advertising = 0;
ecmd->duplex = DUPLEX_FULL;
ecmd->autoneg = AUTONEG_DISABLE;
ecmd->transceiver = XCVR_DUMMY1;
ecmd->port = PORT_NONE;
ethtool_cmd_speed_set(ecmd, 20000);
return 0;
}
void fjes_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &fjes_ethtool_ops;
}
