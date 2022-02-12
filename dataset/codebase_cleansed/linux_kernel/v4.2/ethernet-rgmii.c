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
static void cvm_oct_rgmii_poll(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
unsigned long flags = 0;
cvmx_helper_link_info_t link_info;
int use_global_register_lock = (priv->phydev == NULL);
BUG_ON(in_interrupt());
if (use_global_register_lock) {
spin_lock_irqsave(&global_register_lock, flags);
} else {
mutex_lock(&priv->phydev->bus->mdio_lock);
}
link_info = cvmx_helper_link_get(priv->port);
if (link_info.u64 == priv->link_info) {
if (link_info.s.speed == 10) {
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
union cvmx_gmxx_rxx_int_reg gmxx_rxx_int_reg;
gmxx_rxx_int_reg.u64 =
cvmx_read_csr(CVMX_GMXX_RXX_INT_REG
(index, interface));
if (gmxx_rxx_int_reg.s.pcterr) {
cvm_oct_set_hw_preamble(priv, false);
printk_ratelimited("%s: Using 10Mbps with software preamble removal\n",
dev->name);
}
}
if (use_global_register_lock)
spin_unlock_irqrestore(&global_register_lock, flags);
else
mutex_unlock(&priv->phydev->bus->mdio_lock);
return;
}
cvm_oct_set_hw_preamble(priv, true);
if (priv->phydev == NULL) {
link_info = cvmx_helper_link_autoconf(priv->port);
priv->link_info = link_info.u64;
}
if (use_global_register_lock)
spin_unlock_irqrestore(&global_register_lock, flags);
else
mutex_unlock(&priv->phydev->bus->mdio_lock);
if (priv->phydev == NULL) {
if (link_info.s.link_up) {
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
} else if (netif_carrier_ok(dev)) {
netif_carrier_off(dev);
}
cvm_oct_note_carrier(priv, link_info);
}
}
static int cmv_oct_rgmii_gmx_interrupt(int interface)
{
int index;
int count = 0;
for (index = 0;
index < cvmx_helper_ports_on_interface(interface);
index++) {
union cvmx_gmxx_rxx_int_reg gmx_rx_int_reg;
gmx_rx_int_reg.u64 = cvmx_read_csr(CVMX_GMXX_RXX_INT_REG
(index, interface));
gmx_rx_int_reg.u64 &= cvmx_read_csr(CVMX_GMXX_RXX_INT_EN
(index, interface));
if (gmx_rx_int_reg.s.phy_dupx || gmx_rx_int_reg.s.phy_link ||
gmx_rx_int_reg.s.phy_spd) {
struct net_device *dev =
cvm_oct_device[cvmx_helper_get_ipd_port
(interface, index)];
struct octeon_ethernet *priv = netdev_priv(dev);
if (dev && !atomic_read(&cvm_oct_poll_queue_stopping))
queue_work(cvm_oct_poll_queue,
&priv->port_work);
gmx_rx_int_reg.u64 = 0;
gmx_rx_int_reg.s.phy_dupx = 1;
gmx_rx_int_reg.s.phy_link = 1;
gmx_rx_int_reg.s.phy_spd = 1;
cvmx_write_csr(CVMX_GMXX_RXX_INT_REG(index, interface),
gmx_rx_int_reg.u64);
count++;
}
}
return count;
}
static irqreturn_t cvm_oct_rgmii_rml_interrupt(int cpl, void *dev_id)
{
union cvmx_npi_rsl_int_blocks rsl_int_blocks;
int count = 0;
rsl_int_blocks.u64 = cvmx_read_csr(CVMX_NPI_RSL_INT_BLOCKS);
if (rsl_int_blocks.s.gmx0)
count += cmv_oct_rgmii_gmx_interrupt(0);
if (rsl_int_blocks.s.gmx1)
count += cmv_oct_rgmii_gmx_interrupt(1);
return count ? IRQ_HANDLED : IRQ_NONE;
}
int cvm_oct_rgmii_open(struct net_device *dev)
{
return cvm_oct_common_open(dev, cvm_oct_rgmii_poll, false);
}
static void cvm_oct_rgmii_immediate_poll(struct work_struct *work)
{
struct octeon_ethernet *priv =
container_of(work, struct octeon_ethernet, port_work);
cvm_oct_rgmii_poll(cvm_oct_device[priv->port]);
}
int cvm_oct_rgmii_init(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
int r;
cvm_oct_common_init(dev);
INIT_WORK(&priv->port_work, cvm_oct_rgmii_immediate_poll);
if (number_rgmii_ports == 0) {
r = request_irq(OCTEON_IRQ_RML, cvm_oct_rgmii_rml_interrupt,
IRQF_SHARED, "RGMII", &number_rgmii_ports);
if (r != 0)
return r;
}
number_rgmii_ports++;
if (((priv->imode == CVMX_HELPER_INTERFACE_MODE_GMII)
&& (priv->port == 0))
|| (priv->imode == CVMX_HELPER_INTERFACE_MODE_RGMII)) {
if (!octeon_is_simulation()) {
union cvmx_gmxx_rxx_int_en gmx_rx_int_en;
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
gmx_rx_int_en.u64 = 0;
gmx_rx_int_en.s.phy_dupx = 1;
gmx_rx_int_en.s.phy_link = 1;
gmx_rx_int_en.s.phy_spd = 1;
cvmx_write_csr(CVMX_GMXX_RXX_INT_EN(index, interface),
gmx_rx_int_en.u64);
}
}
return 0;
}
void cvm_oct_rgmii_uninit(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvm_oct_common_uninit(dev);
if (((priv->imode == CVMX_HELPER_INTERFACE_MODE_GMII)
&& (priv->port == 0))
|| (priv->imode == CVMX_HELPER_INTERFACE_MODE_RGMII)) {
if (!octeon_is_simulation()) {
union cvmx_gmxx_rxx_int_en gmx_rx_int_en;
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
gmx_rx_int_en.u64 =
cvmx_read_csr(CVMX_GMXX_RXX_INT_EN
(index, interface));
gmx_rx_int_en.s.phy_dupx = 0;
gmx_rx_int_en.s.phy_link = 0;
gmx_rx_int_en.s.phy_spd = 0;
cvmx_write_csr(CVMX_GMXX_RXX_INT_EN(index, interface),
gmx_rx_int_en.u64);
}
}
number_rgmii_ports--;
if (number_rgmii_ports == 0)
free_irq(OCTEON_IRQ_RML, &number_rgmii_ports);
cancel_work_sync(&priv->port_work);
}
