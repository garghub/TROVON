static void cvm_oct_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, KBUILD_MODNAME, sizeof(info->driver));
strlcpy(info->version, UTS_RELEASE, sizeof(info->version));
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
void cvm_oct_note_carrier(struct octeon_ethernet *priv,
cvmx_helper_link_info_t li)
{
if (li.s.link_up) {
pr_notice_ratelimited("%s: %u Mbps %s duplex, port %d, queue %d\n",
netdev_name(priv->netdev), li.s.speed,
(li.s.full_duplex) ? "Full" : "Half",
priv->port, priv->queue);
} else {
pr_notice_ratelimited("%s: Link down\n",
netdev_name(priv->netdev));
}
}
void cvm_oct_adjust_link(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvmx_helper_link_info_t link_info;
link_info.u64 = 0;
link_info.s.link_up = priv->phydev->link ? 1 : 0;
link_info.s.full_duplex = priv->phydev->duplex ? 1 : 0;
link_info.s.speed = priv->phydev->speed;
priv->link_info = link_info.u64;
if (priv->poll)
priv->poll(dev);
if (priv->last_link != priv->phydev->link) {
priv->last_link = priv->phydev->link;
cvmx_helper_link_set(priv->port, link_info);
cvm_oct_note_carrier(priv, link_info);
}
}
int cvm_oct_common_stop(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
int interface = INTERFACE(priv->port);
cvmx_helper_link_info_t link_info;
union cvmx_gmxx_prtx_cfg gmx_cfg;
int index = INDEX(priv->port);
gmx_cfg.u64 = cvmx_read_csr(CVMX_GMXX_PRTX_CFG(index, interface));
gmx_cfg.s.en = 0;
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface), gmx_cfg.u64);
priv->poll = NULL;
if (priv->phydev)
phy_disconnect(priv->phydev);
priv->phydev = NULL;
if (priv->last_link) {
link_info.u64 = 0;
priv->last_link = 0;
cvmx_helper_link_set(priv->port, link_info);
cvm_oct_note_carrier(priv, link_info);
}
return 0;
}
int cvm_oct_phy_setup_device(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
struct device_node *phy_node;
if (!priv->of_node)
goto no_phy;
phy_node = of_parse_phandle(priv->of_node, "phy-handle", 0);
if (!phy_node && of_phy_is_fixed_link(priv->of_node)) {
int rc;
rc = of_phy_register_fixed_link(priv->of_node);
if (rc)
return rc;
phy_node = of_node_get(priv->of_node);
}
if (!phy_node)
goto no_phy;
priv->phydev = of_phy_connect(dev, phy_node, cvm_oct_adjust_link, 0,
PHY_INTERFACE_MODE_GMII);
if (!priv->phydev)
return -ENODEV;
priv->last_link = 0;
phy_start_aneg(priv->phydev);
return 0;
no_phy:
netif_carrier_on(dev);
return 0;
}
