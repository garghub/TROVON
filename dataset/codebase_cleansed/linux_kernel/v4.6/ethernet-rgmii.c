static void cvm_oct_set_hw_preamble(struct octeon_ethernet *priv, bool enable)
{
union cvmx_gmxx_rxx_frm_ctl gmxx_rxx_frm_ctl;
union cvmx_ipd_sub_port_fcs ipd_sub_port_fcs;
union cvmx_gmxx_rxx_int_reg gmxx_rxx_int_reg;
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
gmxx_rxx_frm_ctl.u64 = cvmx_read_csr(CVMX_GMXX_RXX_FRM_CTL(index,
interface));
gmxx_rxx_frm_ctl.s.pre_chk = enable;
cvmx_write_csr(CVMX_GMXX_RXX_FRM_CTL(index, interface),
gmxx_rxx_frm_ctl.u64);
ipd_sub_port_fcs.u64 = cvmx_read_csr(CVMX_IPD_SUB_PORT_FCS);
if (enable)
ipd_sub_port_fcs.s.port_bit |= 1ull << priv->port;
else
ipd_sub_port_fcs.s.port_bit &=
0xffffffffull ^ (1ull << priv->port);
cvmx_write_csr(CVMX_IPD_SUB_PORT_FCS, ipd_sub_port_fcs.u64);
gmxx_rxx_int_reg.u64 = cvmx_read_csr(CVMX_GMXX_RXX_INT_REG(index,
interface));
cvmx_write_csr(CVMX_GMXX_RXX_INT_REG(index, interface),
gmxx_rxx_int_reg.u64);
}
static void cvm_oct_check_preamble_errors(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvmx_helper_link_info_t link_info;
unsigned long flags;
link_info.u64 = priv->link_info;
spin_lock_irqsave(&global_register_lock, flags);
if (link_info.s.speed == 10 && priv->last_speed == 10) {
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
union cvmx_gmxx_rxx_int_reg gmxx_rxx_int_reg;
gmxx_rxx_int_reg.u64 = cvmx_read_csr(CVMX_GMXX_RXX_INT_REG
(index, interface));
if (gmxx_rxx_int_reg.s.pcterr) {
cvm_oct_set_hw_preamble(priv, false);
printk_ratelimited("%s: Using 10Mbps with software preamble removal\n",
dev->name);
}
} else {
if (priv->last_speed != link_info.s.speed)
cvm_oct_set_hw_preamble(priv, true);
priv->last_speed = link_info.s.speed;
}
spin_unlock_irqrestore(&global_register_lock, flags);
}
static void cvm_oct_rgmii_poll(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvmx_helper_link_info_t link_info;
bool status_change;
link_info = cvmx_helper_link_autoconf(priv->port);
status_change = priv->link_info != link_info.u64;
priv->link_info = link_info.u64;
cvm_oct_check_preamble_errors(dev);
if (likely(!status_change))
return;
if (link_info.s.link_up) {
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
} else if (netif_carrier_ok(dev)) {
netif_carrier_off(dev);
}
cvm_oct_note_carrier(priv, link_info);
}
int cvm_oct_rgmii_open(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
int ret;
ret = cvm_oct_common_open(dev, cvm_oct_rgmii_poll);
if (ret)
return ret;
if (priv->phydev) {
if ((priv->imode == CVMX_HELPER_INTERFACE_MODE_GMII &&
priv->port == 0) ||
(priv->imode == CVMX_HELPER_INTERFACE_MODE_RGMII)) {
priv->poll = cvm_oct_check_preamble_errors;
cvm_oct_check_preamble_errors(dev);
}
}
return 0;
}
