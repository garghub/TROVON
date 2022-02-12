static void cvm_oct_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strcpy(info->driver, "cavium-ethernet");
strcpy(info->version, OCTEON_ETHERNET_VERSION);
strcpy(info->bus_info, "Builtin");
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
int phy_addr = cvmx_helper_board_get_mii_address(priv->port);
if (phy_addr != -1) {
char phy_id[MII_BUS_ID_SIZE + 3];
snprintf(phy_id, sizeof(phy_id), PHY_ID_FMT, "mdio-octeon-0", phy_addr);
priv->phydev = phy_connect(dev, phy_id, cvm_oct_adjust_link, 0,
PHY_INTERFACE_MODE_GMII);
if (IS_ERR(priv->phydev)) {
priv->phydev = NULL;
return -1;
}
priv->last_link = 0;
phy_start_aneg(priv->phydev);
}
return 0;
}
