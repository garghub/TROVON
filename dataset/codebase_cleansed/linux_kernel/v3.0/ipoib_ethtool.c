static void ipoib_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *drvinfo)
{
strncpy(drvinfo->driver, "ipoib", sizeof(drvinfo->driver) - 1);
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
SET_ETHTOOL_OPS(dev, &ipoib_ethtool_ops);
}
