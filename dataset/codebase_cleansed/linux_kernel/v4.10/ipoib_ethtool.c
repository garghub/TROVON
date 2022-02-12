static void ipoib_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct ipoib_dev_priv *priv = netdev_priv(netdev);
ib_get_device_fw_str(priv->ca, drvinfo->fw_version,
sizeof(drvinfo->fw_version));
strlcpy(drvinfo->bus_info, dev_name(priv->ca->dma_device),
sizeof(drvinfo->bus_info));
strlcpy(drvinfo->version, ipoib_driver_version,
sizeof(drvinfo->version));
strlcpy(drvinfo->driver, "ib_ipoib", sizeof(drvinfo->driver));
}
static int ipoib_get_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
struct ipoib_dev_priv *priv = netdev_priv(dev);
coal->rx_coalesce_usecs = priv->ethtool.coalesce_usecs;
coal->rx_max_coalesced_frames = priv->ethtool.max_coalesced_frames;
return 0;
}
static int ipoib_set_coalesce(struct net_device *dev,
struct ethtool_coalesce *coal)
{
struct ipoib_dev_priv *priv = netdev_priv(dev);
int ret;
if (coal->rx_coalesce_usecs > 0xffff ||
coal->rx_max_coalesced_frames > 0xffff)
return -EINVAL;
ret = ib_modify_cq(priv->recv_cq, coal->rx_max_coalesced_frames,
coal->rx_coalesce_usecs);
if (ret && ret != -ENOSYS) {
ipoib_warn(priv, "failed modifying CQ (%d)\n", ret);
return ret;
}
priv->ethtool.coalesce_usecs = coal->rx_coalesce_usecs;
priv->ethtool.max_coalesced_frames = coal->rx_max_coalesced_frames;
return 0;
}
static void ipoib_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats __always_unused *stats,
u64 *data)
{
int i;
struct net_device_stats *net_stats = &dev->stats;
u8 *p = (u8 *)net_stats;
for (i = 0; i < IPOIB_GLOBAL_STATS_LEN; i++)
data[i] = *(u64 *)(p + ipoib_gstrings_stats[i].stat_offset);
}
static void ipoib_get_strings(struct net_device __always_unused *dev,
u32 stringset, u8 *data)
{
u8 *p = data;
int i;
switch (stringset) {
case ETH_SS_STATS:
for (i = 0; i < IPOIB_GLOBAL_STATS_LEN; i++) {
memcpy(p, ipoib_gstrings_stats[i].stat_string,
ETH_GSTRING_LEN);
p += ETH_GSTRING_LEN;
}
break;
case ETH_SS_TEST:
default:
break;
}
}
static int ipoib_get_sset_count(struct net_device __always_unused *dev,
int sset)
{
switch (sset) {
case ETH_SS_STATS:
return IPOIB_GLOBAL_STATS_LEN;
case ETH_SS_TEST:
default:
break;
}
return -EOPNOTSUPP;
}
void ipoib_set_ethtool_ops(struct net_device *dev)
{
dev->ethtool_ops = &ipoib_ethtool_ops;
}
