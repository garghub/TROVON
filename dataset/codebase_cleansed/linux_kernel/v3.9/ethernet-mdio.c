static void cvm_oct_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "cavium-ethernet", sizeof(info->driver));
strlcpy(info->version, OCTEON_ETHERNET_VERSION, sizeof(info->version));
strlcpy(info->bus_info, "Builtin", sizeof(info->bus_info));
}
static int cvm_oct_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct octeon_ethernet *priv = netdev_priv(dev);
if (priv->phydev)
return phy_ethtool_gset(priv->phydev, cmd);
return -EINVAL;
}
static int cvm_oct_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct octeon_ethernet *priv = netdev_priv(dev);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (priv->phydev)
return phy_ethtool_sset(priv->phydev, cmd);
return -EINVAL;
}
static int cvm_oct_nway_reset(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (priv->phydev)
return phy_start_aneg(priv->phydev);
return -EINVAL;
}
int cvm_oct_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct octeon_ethernet *priv = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (!priv->phydev)
return -EINVAL;
return phy_mii_ioctl(priv->phydev, rq, cmd);
}
static void cvm_oct_adjust_link(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvmx_helper_link_info_t link_info;
if (priv->last_link != priv->phydev->link) {
priv->last_link = priv->phydev->link;
link_info.u64 = 0;
link_info.s.link_up = priv->last_link ? 1 : 0;
link_info.s.full_duplex = priv->phydev->duplex ? 1 : 0;
link_info.s.speed = priv->phydev->speed;
cvmx_helper_link_set( priv->port, link_info);
if (priv->last_link) {
netif_carrier_on(dev);
if (priv->queue != -1)
printk_ratelimited("%s: %u Mbps %s duplex, "
"port %2d, queue %2d\n",
dev->name, priv->phydev->speed,
priv->phydev->duplex ?
"Full" : "Half",
priv->port, priv->queue);
else
printk_ratelimited("%s: %u Mbps %s duplex, "
"port %2d, POW\n",
dev->name, priv->phydev->speed,
priv->phydev->duplex ?
"Full" : "Half",
priv->port);
} else {
netif_carrier_off(dev);
printk_ratelimited("%s: Link down\n", dev->name);
}
}
}
int cvm_oct_phy_setup_device(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
struct device_node *phy_node;
if (!priv->of_node)
return 0;
phy_node = of_parse_phandle(priv->of_node, "phy-handle", 0);
if (!phy_node)
return 0;
priv->phydev = of_phy_connect(dev, phy_node, cvm_oct_adjust_link, 0,
PHY_INTERFACE_MODE_GMII);
if (priv->phydev == NULL)
return -ENODEV;
priv->last_link = 0;
phy_start_aneg(priv->phydev);
return 0;
}
