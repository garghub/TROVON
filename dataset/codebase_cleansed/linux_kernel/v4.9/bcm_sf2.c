static enum dsa_tag_protocol bcm_sf2_sw_get_tag_protocol(struct dsa_switch *ds)
{
return DSA_TAG_PROTO_BRCM;
}
static void bcm_sf2_imp_vlan_setup(struct dsa_switch *ds, int cpu_port)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
unsigned int i;
u32 reg;
for (i = 0; i < priv->hw_params.num_ports; i++) {
if (!((1 << i) & ds->enabled_port_mask))
continue;
reg = core_readl(priv, CORE_PORT_VLAN_CTL_PORT(i));
reg |= (1 << cpu_port);
core_writel(priv, reg, CORE_PORT_VLAN_CTL_PORT(i));
}
}
static void bcm_sf2_imp_setup(struct dsa_switch *ds, int port)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
u32 reg, val;
reg = core_readl(priv, CORE_MEM_PSM_VDD_CTRL);
reg &= ~P_TXQ_PSM_VDD(port);
core_writel(priv, reg, CORE_MEM_PSM_VDD_CTRL);
reg = core_readl(priv, CORE_IMP_CTL);
reg |= (RX_BCST_EN | RX_MCST_EN | RX_UCST_EN);
reg &= ~(RX_DIS | TX_DIS);
core_writel(priv, reg, CORE_IMP_CTL);
core_writel(priv, SW_FWDG_EN, CORE_SWMODE);
reg = core_readl(priv, CORE_SWITCH_CTRL);
reg |= MII_DUMB_FWDG_EN;
core_writel(priv, reg, CORE_SWITCH_CTRL);
switch (port) {
case 8:
val = BRCM_HDR_EN_P8;
break;
case 7:
val = BRCM_HDR_EN_P7;
break;
case 5:
val = BRCM_HDR_EN_P5;
break;
default:
val = 0;
break;
}
reg = core_readl(priv, CORE_BRCM_HDR_CTRL);
reg |= val;
core_writel(priv, reg, CORE_BRCM_HDR_CTRL);
reg = core_readl(priv, CORE_BRCM_HDR_RX_DIS);
reg &= ~(1 << port);
core_writel(priv, reg, CORE_BRCM_HDR_RX_DIS);
reg = core_readl(priv, CORE_BRCM_HDR_TX_DIS);
reg &= ~(1 << port);
core_writel(priv, reg, CORE_BRCM_HDR_TX_DIS);
reg = core_readl(priv, CORE_STS_OVERRIDE_IMP);
reg |= (MII_SW_OR | LINK_STS);
core_writel(priv, reg, CORE_STS_OVERRIDE_IMP);
}
static void bcm_sf2_eee_enable_set(struct dsa_switch *ds, int port, bool enable)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
u32 reg;
reg = core_readl(priv, CORE_EEE_EN_CTRL);
if (enable)
reg |= 1 << port;
else
reg &= ~(1 << port);
core_writel(priv, reg, CORE_EEE_EN_CTRL);
}
static void bcm_sf2_gphy_enable_set(struct dsa_switch *ds, bool enable)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
u32 reg;
reg = reg_readl(priv, REG_SPHY_CNTRL);
if (enable) {
reg |= PHY_RESET;
reg &= ~(EXT_PWR_DOWN | IDDQ_BIAS | CK25_DIS);
reg_writel(priv, reg, REG_SPHY_CNTRL);
udelay(21);
reg = reg_readl(priv, REG_SPHY_CNTRL);
reg &= ~PHY_RESET;
} else {
reg |= EXT_PWR_DOWN | IDDQ_BIAS | PHY_RESET;
reg_writel(priv, reg, REG_SPHY_CNTRL);
mdelay(1);
reg |= CK25_DIS;
}
reg_writel(priv, reg, REG_SPHY_CNTRL);
if (!enable) {
reg = reg_readl(priv, REG_LED_CNTRL(0));
reg |= SPDLNK_SRC_SEL;
reg_writel(priv, reg, REG_LED_CNTRL(0));
}
}
static inline void bcm_sf2_port_intr_enable(struct bcm_sf2_priv *priv,
int port)
{
unsigned int off;
switch (port) {
case 7:
off = P7_IRQ_OFF;
break;
case 0:
intrl2_0_mask_clear(priv, P_IRQ_MASK(P0_IRQ_OFF));
return;
default:
off = P_IRQ_OFF(port);
break;
}
intrl2_1_mask_clear(priv, P_IRQ_MASK(off));
}
static inline void bcm_sf2_port_intr_disable(struct bcm_sf2_priv *priv,
int port)
{
unsigned int off;
switch (port) {
case 7:
off = P7_IRQ_OFF;
break;
case 0:
intrl2_0_mask_set(priv, P_IRQ_MASK(P0_IRQ_OFF));
intrl2_0_writel(priv, P_IRQ_MASK(P0_IRQ_OFF), INTRL2_CPU_CLEAR);
return;
default:
off = P_IRQ_OFF(port);
break;
}
intrl2_1_mask_set(priv, P_IRQ_MASK(off));
intrl2_1_writel(priv, P_IRQ_MASK(off), INTRL2_CPU_CLEAR);
}
static int bcm_sf2_port_setup(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
s8 cpu_port = ds->dst[ds->index].cpu_port;
u32 reg;
reg = core_readl(priv, CORE_MEM_PSM_VDD_CTRL);
reg &= ~P_TXQ_PSM_VDD(port);
core_writel(priv, reg, CORE_MEM_PSM_VDD_CTRL);
core_writel(priv, 0, CORE_G_PCTL_PORT(port));
if (priv->int_phy_mask & 1 << port && priv->hw_params.num_gphy == 1) {
bcm_sf2_gphy_enable_set(ds, true);
if (phy) {
phy->state = PHY_READY;
phy_init_hw(phy);
}
}
if (port == priv->moca_port)
bcm_sf2_port_intr_enable(priv, port);
reg = core_readl(priv, CORE_PORT_VLAN_CTL_PORT(port));
reg &= ~PORT_VLAN_CTRL_MASK;
reg |= (1 << port);
reg |= priv->dev->ports[port].vlan_ctl_mask;
core_writel(priv, reg, CORE_PORT_VLAN_CTL_PORT(port));
bcm_sf2_imp_vlan_setup(ds, cpu_port);
if (priv->port_sts[port].eee.eee_enabled)
bcm_sf2_eee_enable_set(ds, port, true);
return 0;
}
static void bcm_sf2_port_disable(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
u32 off, reg;
if (priv->wol_ports_mask & (1 << port))
return;
if (port == priv->moca_port)
bcm_sf2_port_intr_disable(priv, port);
if (priv->int_phy_mask & 1 << port && priv->hw_params.num_gphy == 1)
bcm_sf2_gphy_enable_set(ds, false);
if (dsa_is_cpu_port(ds, port))
off = CORE_IMP_CTL;
else
off = CORE_G_PCTL_PORT(port);
reg = core_readl(priv, off);
reg |= RX_DIS | TX_DIS;
core_writel(priv, reg, off);
reg = core_readl(priv, CORE_MEM_PSM_VDD_CTRL);
reg |= P_TXQ_PSM_VDD(port);
core_writel(priv, reg, CORE_MEM_PSM_VDD_CTRL);
}
static int bcm_sf2_eee_init(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
struct ethtool_eee *p = &priv->port_sts[port].eee;
int ret;
p->supported = (SUPPORTED_1000baseT_Full | SUPPORTED_100baseT_Full);
ret = phy_init_eee(phy, 0);
if (ret)
return 0;
bcm_sf2_eee_enable_set(ds, port, true);
return 1;
}
static int bcm_sf2_sw_get_eee(struct dsa_switch *ds, int port,
struct ethtool_eee *e)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
struct ethtool_eee *p = &priv->port_sts[port].eee;
u32 reg;
reg = core_readl(priv, CORE_EEE_LPI_INDICATE);
e->eee_enabled = p->eee_enabled;
e->eee_active = !!(reg & (1 << port));
return 0;
}
static int bcm_sf2_sw_set_eee(struct dsa_switch *ds, int port,
struct phy_device *phydev,
struct ethtool_eee *e)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
struct ethtool_eee *p = &priv->port_sts[port].eee;
p->eee_enabled = e->eee_enabled;
if (!p->eee_enabled) {
bcm_sf2_eee_enable_set(ds, port, false);
} else {
p->eee_enabled = bcm_sf2_eee_init(ds, port, phydev);
if (!p->eee_enabled)
return -EOPNOTSUPP;
}
return 0;
}
static int bcm_sf2_sw_indir_rw(struct bcm_sf2_priv *priv, int op, int addr,
int regnum, u16 val)
{
int ret = 0;
u32 reg;
reg = reg_readl(priv, REG_SWITCH_CNTRL);
reg |= MDIO_MASTER_SEL;
reg_writel(priv, reg, REG_SWITCH_CNTRL);
reg = 0x70;
reg <<= 2;
core_writel(priv, addr, reg);
reg = 0x80 << 8 | regnum << 1;
reg <<= 2;
if (op)
ret = core_readl(priv, reg);
else
core_writel(priv, val, reg);
reg = reg_readl(priv, REG_SWITCH_CNTRL);
reg &= ~MDIO_MASTER_SEL;
reg_writel(priv, reg, REG_SWITCH_CNTRL);
return ret & 0xffff;
}
static int bcm_sf2_sw_mdio_read(struct mii_bus *bus, int addr, int regnum)
{
struct bcm_sf2_priv *priv = bus->priv;
if (addr == BRCM_PSEUDO_PHY_ADDR && priv->indir_phy_mask & BIT(addr))
return bcm_sf2_sw_indir_rw(priv, 1, addr, regnum, 0);
else
return mdiobus_read(priv->master_mii_bus, addr, regnum);
}
static int bcm_sf2_sw_mdio_write(struct mii_bus *bus, int addr, int regnum,
u16 val)
{
struct bcm_sf2_priv *priv = bus->priv;
if (addr == BRCM_PSEUDO_PHY_ADDR && priv->indir_phy_mask & BIT(addr))
bcm_sf2_sw_indir_rw(priv, 0, addr, regnum, val);
else
mdiobus_write(priv->master_mii_bus, addr, regnum, val);
return 0;
}
static irqreturn_t bcm_sf2_switch_0_isr(int irq, void *dev_id)
{
struct bcm_sf2_priv *priv = dev_id;
priv->irq0_stat = intrl2_0_readl(priv, INTRL2_CPU_STATUS) &
~priv->irq0_mask;
intrl2_0_writel(priv, priv->irq0_stat, INTRL2_CPU_CLEAR);
return IRQ_HANDLED;
}
static irqreturn_t bcm_sf2_switch_1_isr(int irq, void *dev_id)
{
struct bcm_sf2_priv *priv = dev_id;
priv->irq1_stat = intrl2_1_readl(priv, INTRL2_CPU_STATUS) &
~priv->irq1_mask;
intrl2_1_writel(priv, priv->irq1_stat, INTRL2_CPU_CLEAR);
if (priv->irq1_stat & P_LINK_UP_IRQ(P7_IRQ_OFF))
priv->port_sts[7].link = 1;
if (priv->irq1_stat & P_LINK_DOWN_IRQ(P7_IRQ_OFF))
priv->port_sts[7].link = 0;
return IRQ_HANDLED;
}
static int bcm_sf2_sw_rst(struct bcm_sf2_priv *priv)
{
unsigned int timeout = 1000;
u32 reg;
reg = core_readl(priv, CORE_WATCHDOG_CTRL);
reg |= SOFTWARE_RESET | EN_CHIP_RST | EN_SW_RESET;
core_writel(priv, reg, CORE_WATCHDOG_CTRL);
do {
reg = core_readl(priv, CORE_WATCHDOG_CTRL);
if (!(reg & SOFTWARE_RESET))
break;
usleep_range(1000, 2000);
} while (timeout-- > 0);
if (timeout == 0)
return -ETIMEDOUT;
return 0;
}
static void bcm_sf2_intr_disable(struct bcm_sf2_priv *priv)
{
intrl2_0_mask_set(priv, 0xffffffff);
intrl2_0_writel(priv, 0xffffffff, INTRL2_CPU_CLEAR);
intrl2_1_mask_set(priv, 0xffffffff);
intrl2_1_writel(priv, 0xffffffff, INTRL2_CPU_CLEAR);
}
static void bcm_sf2_identify_ports(struct bcm_sf2_priv *priv,
struct device_node *dn)
{
struct device_node *port;
const char *phy_mode_str;
int mode;
unsigned int port_num;
int ret;
priv->moca_port = -1;
for_each_available_child_of_node(dn, port) {
if (of_property_read_u32(port, "reg", &port_num))
continue;
mode = of_get_phy_mode(port);
if (mode < 0) {
ret = of_property_read_string(port, "phy-mode",
&phy_mode_str);
if (ret < 0)
continue;
if (!strcasecmp(phy_mode_str, "internal"))
priv->int_phy_mask |= 1 << port_num;
}
if (mode == PHY_INTERFACE_MODE_MOCA)
priv->moca_port = port_num;
}
}
static int bcm_sf2_mdio_register(struct dsa_switch *ds)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
struct device_node *dn;
static int index;
int err;
dn = of_find_compatible_node(NULL, NULL, "brcm,unimac-mdio");
priv->master_mii_bus = of_mdio_find_bus(dn);
if (!priv->master_mii_bus)
return -EPROBE_DEFER;
get_device(&priv->master_mii_bus->dev);
priv->master_mii_dn = dn;
priv->slave_mii_bus = devm_mdiobus_alloc(ds->dev);
if (!priv->slave_mii_bus)
return -ENOMEM;
priv->slave_mii_bus->priv = priv;
priv->slave_mii_bus->name = "sf2 slave mii";
priv->slave_mii_bus->read = bcm_sf2_sw_mdio_read;
priv->slave_mii_bus->write = bcm_sf2_sw_mdio_write;
snprintf(priv->slave_mii_bus->id, MII_BUS_ID_SIZE, "sf2-%d",
index++);
priv->slave_mii_bus->dev.of_node = dn;
if (of_machine_is_compatible("brcm,bcm7445d0"))
priv->indir_phy_mask |= (1 << BRCM_PSEUDO_PHY_ADDR);
else
priv->indir_phy_mask = 0;
ds->phys_mii_mask = priv->indir_phy_mask;
ds->slave_mii_bus = priv->slave_mii_bus;
priv->slave_mii_bus->parent = ds->dev->parent;
priv->slave_mii_bus->phy_mask = ~priv->indir_phy_mask;
if (dn)
err = of_mdiobus_register(priv->slave_mii_bus, dn);
else
err = mdiobus_register(priv->slave_mii_bus);
if (err)
of_node_put(dn);
return err;
}
static void bcm_sf2_mdio_unregister(struct bcm_sf2_priv *priv)
{
mdiobus_unregister(priv->slave_mii_bus);
if (priv->master_mii_dn)
of_node_put(priv->master_mii_dn);
}
static u32 bcm_sf2_sw_get_phy_flags(struct dsa_switch *ds, int port)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
return priv->hw_params.gphy_rev;
}
static void bcm_sf2_sw_adjust_link(struct dsa_switch *ds, int port,
struct phy_device *phydev)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
struct ethtool_eee *p = &priv->port_sts[port].eee;
u32 id_mode_dis = 0, port_mode;
const char *str = NULL;
u32 reg;
switch (phydev->interface) {
case PHY_INTERFACE_MODE_RGMII:
str = "RGMII (no delay)";
id_mode_dis = 1;
case PHY_INTERFACE_MODE_RGMII_TXID:
if (!str)
str = "RGMII (TX delay)";
port_mode = EXT_GPHY;
break;
case PHY_INTERFACE_MODE_MII:
str = "MII";
port_mode = EXT_EPHY;
break;
case PHY_INTERFACE_MODE_REVMII:
str = "Reverse MII";
port_mode = EXT_REVMII;
break;
default:
goto force_link;
}
if (!phydev->link) {
reg = reg_readl(priv, REG_RGMII_CNTRL_P(port));
reg &= ~RGMII_MODE_EN;
reg_writel(priv, reg, REG_RGMII_CNTRL_P(port));
goto force_link;
}
reg = reg_readl(priv, REG_RGMII_CNTRL_P(port));
reg &= ~ID_MODE_DIS;
reg &= ~(PORT_MODE_MASK << PORT_MODE_SHIFT);
reg &= ~(RX_PAUSE_EN | TX_PAUSE_EN);
reg |= port_mode | RGMII_MODE_EN;
if (id_mode_dis)
reg |= ID_MODE_DIS;
if (phydev->pause) {
if (phydev->asym_pause)
reg |= TX_PAUSE_EN;
reg |= RX_PAUSE_EN;
}
reg_writel(priv, reg, REG_RGMII_CNTRL_P(port));
pr_info("Port %d configured for %s\n", port, str);
force_link:
reg = SW_OVERRIDE;
switch (phydev->speed) {
case SPEED_1000:
reg |= SPDSTS_1000 << SPEED_SHIFT;
break;
case SPEED_100:
reg |= SPDSTS_100 << SPEED_SHIFT;
break;
}
if (phydev->link)
reg |= LINK_STS;
if (phydev->duplex == DUPLEX_FULL)
reg |= DUPLX_MODE;
core_writel(priv, reg, CORE_STS_OVERRIDE_GMIIP_PORT(port));
if (!phydev->is_pseudo_fixed_link)
p->eee_enabled = bcm_sf2_eee_init(ds, port, phydev);
}
static void bcm_sf2_sw_fixed_link_update(struct dsa_switch *ds, int port,
struct fixed_phy_status *status)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
u32 duplex, pause;
u32 reg;
duplex = core_readl(priv, CORE_DUPSTS);
pause = core_readl(priv, CORE_PAUSESTS);
status->link = 0;
if (port == priv->moca_port) {
status->link = priv->port_sts[port].link;
if (!status->link)
netif_carrier_off(ds->ports[port].netdev);
status->duplex = 1;
} else {
status->link = 1;
status->duplex = !!(duplex & (1 << port));
}
reg = core_readl(priv, CORE_STS_OVERRIDE_GMIIP_PORT(port));
reg |= SW_OVERRIDE;
if (status->link)
reg |= LINK_STS;
else
reg &= ~LINK_STS;
core_writel(priv, reg, CORE_STS_OVERRIDE_GMIIP_PORT(port));
if ((pause & (1 << port)) &&
(pause & (1 << (port + PAUSESTS_TX_PAUSE_SHIFT)))) {
status->asym_pause = 1;
status->pause = 1;
}
if (pause & (1 << port))
status->pause = 1;
}
static int bcm_sf2_sw_suspend(struct dsa_switch *ds)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
unsigned int port;
bcm_sf2_intr_disable(priv);
for (port = 0; port < DSA_MAX_PORTS; port++) {
if ((1 << port) & ds->enabled_port_mask ||
dsa_is_cpu_port(ds, port))
bcm_sf2_port_disable(ds, port, NULL);
}
return 0;
}
static int bcm_sf2_sw_resume(struct dsa_switch *ds)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
unsigned int port;
int ret;
ret = bcm_sf2_sw_rst(priv);
if (ret) {
pr_err("%s: failed to software reset switch\n", __func__);
return ret;
}
if (priv->hw_params.num_gphy == 1)
bcm_sf2_gphy_enable_set(ds, true);
for (port = 0; port < DSA_MAX_PORTS; port++) {
if ((1 << port) & ds->enabled_port_mask)
bcm_sf2_port_setup(ds, port, NULL);
else if (dsa_is_cpu_port(ds, port))
bcm_sf2_imp_setup(ds, port);
}
return 0;
}
static void bcm_sf2_sw_get_wol(struct dsa_switch *ds, int port,
struct ethtool_wolinfo *wol)
{
struct net_device *p = ds->dst[ds->index].master_netdev;
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
struct ethtool_wolinfo pwol;
p->ethtool_ops->get_wol(p, &pwol);
wol->supported = pwol.supported;
memset(&wol->sopass, 0, sizeof(wol->sopass));
if (pwol.wolopts & WAKE_MAGICSECURE)
memcpy(&wol->sopass, pwol.sopass, sizeof(wol->sopass));
if (priv->wol_ports_mask & (1 << port))
wol->wolopts = pwol.wolopts;
else
wol->wolopts = 0;
}
static int bcm_sf2_sw_set_wol(struct dsa_switch *ds, int port,
struct ethtool_wolinfo *wol)
{
struct net_device *p = ds->dst[ds->index].master_netdev;
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
s8 cpu_port = ds->dst[ds->index].cpu_port;
struct ethtool_wolinfo pwol;
p->ethtool_ops->get_wol(p, &pwol);
if (wol->wolopts & ~pwol.supported)
return -EINVAL;
if (wol->wolopts)
priv->wol_ports_mask |= (1 << port);
else
priv->wol_ports_mask &= ~(1 << port);
if (priv->wol_ports_mask && priv->wol_ports_mask != (1 << cpu_port))
priv->wol_ports_mask |= (1 << cpu_port);
else
priv->wol_ports_mask &= ~(1 << cpu_port);
return p->ethtool_ops->set_wol(p, wol);
}
static int bcm_sf2_vlan_op_wait(struct bcm_sf2_priv *priv)
{
unsigned int timeout = 10;
u32 reg;
do {
reg = core_readl(priv, CORE_ARLA_VTBL_RWCTRL);
if (!(reg & ARLA_VTBL_STDN))
return 0;
usleep_range(1000, 2000);
} while (timeout--);
return -ETIMEDOUT;
}
static int bcm_sf2_vlan_op(struct bcm_sf2_priv *priv, u8 op)
{
core_writel(priv, ARLA_VTBL_STDN | op, CORE_ARLA_VTBL_RWCTRL);
return bcm_sf2_vlan_op_wait(priv);
}
static void bcm_sf2_sw_configure_vlan(struct dsa_switch *ds)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
unsigned int port;
bcm_sf2_vlan_op(priv, ARLA_VTBL_CMD_CLEAR);
for (port = 0; port < priv->hw_params.num_ports; port++) {
if (!((1 << port) & ds->enabled_port_mask))
continue;
core_writel(priv, 1, CORE_DEFAULT_1Q_TAG_P(port));
}
}
static int bcm_sf2_sw_setup(struct dsa_switch *ds)
{
struct bcm_sf2_priv *priv = bcm_sf2_to_priv(ds);
unsigned int port;
for (port = 0; port < priv->hw_params.num_ports; port++) {
if ((1 << port) & ds->enabled_port_mask)
bcm_sf2_port_setup(ds, port, NULL);
else if (dsa_is_cpu_port(ds, port))
bcm_sf2_imp_setup(ds, port);
else
bcm_sf2_port_disable(ds, port, NULL);
}
bcm_sf2_sw_configure_vlan(ds);
return 0;
}
static int bcm_sf2_core_read8(struct b53_device *dev, u8 page, u8 reg,
u8 *val)
{
struct bcm_sf2_priv *priv = dev->priv;
*val = core_readl(priv, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_core_read16(struct b53_device *dev, u8 page, u8 reg,
u16 *val)
{
struct bcm_sf2_priv *priv = dev->priv;
*val = core_readl(priv, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_core_read32(struct b53_device *dev, u8 page, u8 reg,
u32 *val)
{
struct bcm_sf2_priv *priv = dev->priv;
*val = core_readl(priv, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_core_read64(struct b53_device *dev, u8 page, u8 reg,
u64 *val)
{
struct bcm_sf2_priv *priv = dev->priv;
*val = core_readq(priv, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_core_write8(struct b53_device *dev, u8 page, u8 reg,
u8 value)
{
struct bcm_sf2_priv *priv = dev->priv;
core_writel(priv, value, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_core_write16(struct b53_device *dev, u8 page, u8 reg,
u16 value)
{
struct bcm_sf2_priv *priv = dev->priv;
core_writel(priv, value, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_core_write32(struct b53_device *dev, u8 page, u8 reg,
u32 value)
{
struct bcm_sf2_priv *priv = dev->priv;
core_writel(priv, value, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_core_write64(struct b53_device *dev, u8 page, u8 reg,
u64 value)
{
struct bcm_sf2_priv *priv = dev->priv;
core_writeq(priv, value, SF2_PAGE_REG_MKADDR(page, reg));
return 0;
}
static int bcm_sf2_sw_probe(struct platform_device *pdev)
{
const char *reg_names[BCM_SF2_REGS_NUM] = BCM_SF2_REGS_NAME;
struct device_node *dn = pdev->dev.of_node;
struct b53_platform_data *pdata;
struct bcm_sf2_priv *priv;
struct b53_device *dev;
struct dsa_switch *ds;
void __iomem **base;
struct resource *r;
unsigned int i;
u32 reg, rev;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
dev = b53_switch_alloc(&pdev->dev, &bcm_sf2_io_ops, priv);
if (!dev)
return -ENOMEM;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->chip_id = BCM7445_DEVICE_ID;
dev->pdata = pdata;
priv->dev = dev;
ds = dev->ds;
ds->ops->get_tag_protocol = bcm_sf2_sw_get_tag_protocol;
ds->ops->setup = bcm_sf2_sw_setup;
ds->ops->get_phy_flags = bcm_sf2_sw_get_phy_flags;
ds->ops->adjust_link = bcm_sf2_sw_adjust_link;
ds->ops->fixed_link_update = bcm_sf2_sw_fixed_link_update;
ds->ops->suspend = bcm_sf2_sw_suspend;
ds->ops->resume = bcm_sf2_sw_resume;
ds->ops->get_wol = bcm_sf2_sw_get_wol;
ds->ops->set_wol = bcm_sf2_sw_set_wol;
ds->ops->port_enable = bcm_sf2_port_setup;
ds->ops->port_disable = bcm_sf2_port_disable;
ds->ops->get_eee = bcm_sf2_sw_get_eee;
ds->ops->set_eee = bcm_sf2_sw_set_eee;
ds->ops->phy_read = NULL;
dev_set_drvdata(&pdev->dev, priv);
spin_lock_init(&priv->indir_lock);
mutex_init(&priv->stats_mutex);
bcm_sf2_identify_ports(priv, dn->child);
priv->irq0 = irq_of_parse_and_map(dn, 0);
priv->irq1 = irq_of_parse_and_map(dn, 1);
base = &priv->core;
for (i = 0; i < BCM_SF2_REGS_NUM; i++) {
r = platform_get_resource(pdev, IORESOURCE_MEM, i);
*base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(*base)) {
pr_err("unable to find register: %s\n", reg_names[i]);
return PTR_ERR(*base);
}
base++;
}
ret = bcm_sf2_sw_rst(priv);
if (ret) {
pr_err("unable to software reset switch: %d\n", ret);
return ret;
}
ret = bcm_sf2_mdio_register(ds);
if (ret) {
pr_err("failed to register MDIO bus\n");
return ret;
}
bcm_sf2_intr_disable(priv);
ret = devm_request_irq(&pdev->dev, priv->irq0, bcm_sf2_switch_0_isr, 0,
"switch_0", priv);
if (ret < 0) {
pr_err("failed to request switch_0 IRQ\n");
goto out_mdio;
}
ret = devm_request_irq(&pdev->dev, priv->irq1, bcm_sf2_switch_1_isr, 0,
"switch_1", priv);
if (ret < 0) {
pr_err("failed to request switch_1 IRQ\n");
goto out_mdio;
}
reg = core_readl(priv, CORE_GMNCFGCFG);
reg |= RST_MIB_CNT;
core_writel(priv, reg, CORE_GMNCFGCFG);
reg &= ~RST_MIB_CNT;
core_writel(priv, reg, CORE_GMNCFGCFG);
priv->hw_params.num_ports = core_readl(priv, CORE_IMP0_PRT_ID) + 1;
if (priv->hw_params.num_ports > DSA_MAX_PORTS)
priv->hw_params.num_ports = DSA_MAX_PORTS;
if (of_property_read_u32(dn, "brcm,num-gphy",
&priv->hw_params.num_gphy))
priv->hw_params.num_gphy = 1;
rev = reg_readl(priv, REG_SWITCH_REVISION);
priv->hw_params.top_rev = (rev >> SWITCH_TOP_REV_SHIFT) &
SWITCH_TOP_REV_MASK;
priv->hw_params.core_rev = (rev & SF2_REV_MASK);
rev = reg_readl(priv, REG_PHY_REVISION);
priv->hw_params.gphy_rev = rev & PHY_REVISION_MASK;
ret = b53_switch_register(dev);
if (ret)
goto out_mdio;
pr_info("Starfighter 2 top: %x.%02x, core: %x.%02x base: 0x%p, IRQs: %d, %d\n",
priv->hw_params.top_rev >> 8, priv->hw_params.top_rev & 0xff,
priv->hw_params.core_rev >> 8, priv->hw_params.core_rev & 0xff,
priv->core, priv->irq0, priv->irq1);
return 0;
out_mdio:
bcm_sf2_mdio_unregister(priv);
return ret;
}
static int bcm_sf2_sw_remove(struct platform_device *pdev)
{
struct bcm_sf2_priv *priv = platform_get_drvdata(pdev);
priv->wol_ports_mask = 0;
bcm_sf2_sw_suspend(priv->dev->ds);
dsa_unregister_switch(priv->dev->ds);
bcm_sf2_mdio_unregister(priv);
return 0;
}
static void bcm_sf2_sw_shutdown(struct platform_device *pdev)
{
struct bcm_sf2_priv *priv = platform_get_drvdata(pdev);
if (priv->hw_params.num_gphy == 1)
bcm_sf2_gphy_enable_set(priv->dev->ds, true);
}
static int bcm_sf2_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct bcm_sf2_priv *priv = platform_get_drvdata(pdev);
return dsa_switch_suspend(priv->dev->ds);
}
static int bcm_sf2_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct bcm_sf2_priv *priv = platform_get_drvdata(pdev);
return dsa_switch_resume(priv->dev->ds);
}
