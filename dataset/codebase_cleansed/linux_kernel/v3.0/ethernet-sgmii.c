int cvm_oct_sgmii_open(struct net_device *dev)
{
union cvmx_gmxx_prtx_cfg gmx_cfg;
struct octeon_ethernet *priv = netdev_priv(dev);
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
cvmx_helper_link_info_t link_info;
gmx_cfg.u64 = cvmx_read_csr(CVMX_GMXX_PRTX_CFG(index, interface));
gmx_cfg.s.en = 1;
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface), gmx_cfg.u64);
if (!octeon_is_simulation()) {
link_info = cvmx_helper_link_get(priv->port);
if (!link_info.s.link_up)
netif_carrier_off(dev);
}
return 0;
}
int cvm_oct_sgmii_stop(struct net_device *dev)
{
union cvmx_gmxx_prtx_cfg gmx_cfg;
struct octeon_ethernet *priv = netdev_priv(dev);
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
gmx_cfg.u64 = cvmx_read_csr(CVMX_GMXX_PRTX_CFG(index, interface));
gmx_cfg.s.en = 0;
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface), gmx_cfg.u64);
return 0;
}
static void cvm_oct_sgmii_poll(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvmx_helper_link_info_t link_info;
link_info = cvmx_helper_link_get(priv->port);
if (link_info.u64 == priv->link_info)
return;
link_info = cvmx_helper_link_autoconf(priv->port);
priv->link_info = link_info.u64;
if (link_info.s.link_up) {
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
if (priv->queue != -1)
DEBUGPRINT
("%s: %u Mbps %s duplex, port %2d, queue %2d\n",
dev->name, link_info.s.speed,
(link_info.s.full_duplex) ? "Full" : "Half",
priv->port, priv->queue);
else
DEBUGPRINT("%s: %u Mbps %s duplex, port %2d, POW\n",
dev->name, link_info.s.speed,
(link_info.s.full_duplex) ? "Full" : "Half",
priv->port);
} else {
if (netif_carrier_ok(dev))
netif_carrier_off(dev);
DEBUGPRINT("%s: Link down\n", dev->name);
}
}
int cvm_oct_sgmii_init(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvm_oct_common_init(dev);
dev->netdev_ops->ndo_stop(dev);
if (!octeon_is_simulation() && priv->phydev == NULL)
priv->poll = cvm_oct_sgmii_poll;
return 0;
}
void cvm_oct_sgmii_uninit(struct net_device *dev)
{
cvm_oct_common_uninit(dev);
}
