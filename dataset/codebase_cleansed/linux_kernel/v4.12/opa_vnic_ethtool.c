static void vnic_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
strlcpy(drvinfo->driver, opa_vnic_driver_name, sizeof(drvinfo->driver));
strlcpy(drvinfo->version, opa_vnic_driver_version,
sizeof(drvinfo->version));
strlcpy(drvinfo->bus_info, dev_name(netdev->dev.parent),
sizeof(drvinfo->bus_info));
}
static int vnic_get_sset_count(struct net_device *netdev, int sset)
{
return (sset == ETH_SS_STATS) ? VNIC_STATS_LEN : -EOPNOTSUPP;
}
static void vnic_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct opa_vnic_adapter *adapter = opa_vnic_priv(netdev);
struct opa_vnic_stats vstats;
int i;
memset(&vstats, 0, sizeof(vstats));
mutex_lock(&adapter->stats_lock);
adapter->rn_ops->ndo_get_stats64(netdev, &vstats.netstats);
for (i = 0; i < VNIC_STATS_LEN; i++) {
char *p = (char *)&vstats + vnic_gstrings_stats[i].stat_offset;
data[i] = (vnic_gstrings_stats[i].sizeof_stat ==
sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
}
mutex_unlock(&adapter->stats_lock);
}
static void vnic_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
int i;
if (stringset != ETH_SS_STATS)
return;
for (i = 0; i < VNIC_STATS_LEN; i++)
memcpy(data + i * ETH_GSTRING_LEN,
vnic_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
}
void opa_vnic_set_ethtool_ops(struct net_device *netdev)
{
netdev->ethtool_ops = &opa_vnic_ethtool_ops;
}
