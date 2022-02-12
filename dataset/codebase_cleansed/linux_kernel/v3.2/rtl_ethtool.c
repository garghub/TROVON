static void rtl819x_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct r8192_priv *priv = rtllib_priv(dev);
strcpy(info->driver, DRV_NAME);
strcpy(info->version, DRV_VERSION);
strcpy(info->bus_info, pci_name(priv->pdev));
}
static u32 rtl819x_ethtool_get_link(struct net_device *dev)
{
struct r8192_priv *priv = rtllib_priv(dev);
return ((priv->rtllib->state == RTLLIB_LINKED) ||
(priv->rtllib->state == RTLLIB_LINKED_SCANNING));
}
