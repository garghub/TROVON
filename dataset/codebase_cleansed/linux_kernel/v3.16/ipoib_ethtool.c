static void ipoib_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
struct ipoib_dev_priv *priv = netdev_priv(netdev);
struct ib_device_attr *attr;
attr = kmalloc(sizeof(*attr), GFP_KERNEL);
if (attr && !ib_query_device(priv->ca, attr))
snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
"%d.%d.%d", (int)(attr->fw_ver >> 32),
(int)(attr->fw_ver >> 16) & 0xffff,
(int)attr->fw_ver & 0xffff);
kfree(attr);
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
void ipoib_set_ethtool_ops(struct net_device *dev)
{
dev->ethtool_ops = &ipoib_ethtool_ops;
}
