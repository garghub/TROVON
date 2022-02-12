static int b53_do_vlan_op(struct b53_device *dev, u8 op)
{
unsigned int i;
b53_write8(dev, B53_ARLIO_PAGE, dev->vta_regs[0], VTA_START_CMD | op);
for (i = 0; i < 10; i++) {
u8 vta;
b53_read8(dev, B53_ARLIO_PAGE, dev->vta_regs[0], &vta);
if (!(vta & VTA_START_CMD))
return 0;
usleep_range(100, 200);
}
return -EIO;
}
static void b53_set_vlan_entry(struct b53_device *dev, u16 vid,
struct b53_vlan *vlan)
{
if (is5325(dev)) {
u32 entry = 0;
if (vlan->members) {
entry = ((vlan->untag & VA_UNTAG_MASK_25) <<
VA_UNTAG_S_25) | vlan->members;
if (dev->core_rev >= 3)
entry |= VA_VALID_25_R4 | vid << VA_VID_HIGH_S;
else
entry |= VA_VALID_25;
}
b53_write32(dev, B53_VLAN_PAGE, B53_VLAN_WRITE_25, entry);
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_TABLE_ACCESS_25, vid |
VTA_RW_STATE_WR | VTA_RW_OP_EN);
} else if (is5365(dev)) {
u16 entry = 0;
if (vlan->members)
entry = ((vlan->untag & VA_UNTAG_MASK_65) <<
VA_UNTAG_S_65) | vlan->members | VA_VALID_65;
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_WRITE_65, entry);
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_TABLE_ACCESS_65, vid |
VTA_RW_STATE_WR | VTA_RW_OP_EN);
} else {
b53_write16(dev, B53_ARLIO_PAGE, dev->vta_regs[1], vid);
b53_write32(dev, B53_ARLIO_PAGE, dev->vta_regs[2],
(vlan->untag << VTE_UNTAG_S) | vlan->members);
b53_do_vlan_op(dev, VTA_CMD_WRITE);
}
dev_dbg(dev->ds->dev, "VID: %d, members: 0x%04x, untag: 0x%04x\n",
vid, vlan->members, vlan->untag);
}
static void b53_get_vlan_entry(struct b53_device *dev, u16 vid,
struct b53_vlan *vlan)
{
if (is5325(dev)) {
u32 entry = 0;
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_TABLE_ACCESS_25, vid |
VTA_RW_STATE_RD | VTA_RW_OP_EN);
b53_read32(dev, B53_VLAN_PAGE, B53_VLAN_WRITE_25, &entry);
if (dev->core_rev >= 3)
vlan->valid = !!(entry & VA_VALID_25_R4);
else
vlan->valid = !!(entry & VA_VALID_25);
vlan->members = entry & VA_MEMBER_MASK;
vlan->untag = (entry >> VA_UNTAG_S_25) & VA_UNTAG_MASK_25;
} else if (is5365(dev)) {
u16 entry = 0;
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_TABLE_ACCESS_65, vid |
VTA_RW_STATE_WR | VTA_RW_OP_EN);
b53_read16(dev, B53_VLAN_PAGE, B53_VLAN_WRITE_65, &entry);
vlan->valid = !!(entry & VA_VALID_65);
vlan->members = entry & VA_MEMBER_MASK;
vlan->untag = (entry >> VA_UNTAG_S_65) & VA_UNTAG_MASK_65;
} else {
u32 entry = 0;
b53_write16(dev, B53_ARLIO_PAGE, dev->vta_regs[1], vid);
b53_do_vlan_op(dev, VTA_CMD_READ);
b53_read32(dev, B53_ARLIO_PAGE, dev->vta_regs[2], &entry);
vlan->members = entry & VTE_MEMBERS;
vlan->untag = (entry >> VTE_UNTAG_S) & VTE_MEMBERS;
vlan->valid = true;
}
}
static void b53_set_forwarding(struct b53_device *dev, int enable)
{
struct dsa_switch *ds = dev->ds;
u8 mgmt;
b53_read8(dev, B53_CTRL_PAGE, B53_SWITCH_MODE, &mgmt);
if (enable)
mgmt |= SM_SW_FWD_EN;
else
mgmt &= ~SM_SW_FWD_EN;
b53_write8(dev, B53_CTRL_PAGE, B53_SWITCH_MODE, mgmt);
if (ds->ops->get_tag_protocol(ds) == DSA_TAG_PROTO_NONE) {
b53_read8(dev, B53_CTRL_PAGE, B53_SWITCH_CTRL, &mgmt);
mgmt |= B53_MII_DUMB_FWDG_EN;
b53_write8(dev, B53_CTRL_PAGE, B53_SWITCH_CTRL, mgmt);
}
}
static void b53_enable_vlan(struct b53_device *dev, bool enable)
{
u8 mgmt, vc0, vc1, vc4 = 0, vc5;
b53_read8(dev, B53_CTRL_PAGE, B53_SWITCH_MODE, &mgmt);
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL0, &vc0);
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL1, &vc1);
if (is5325(dev) || is5365(dev)) {
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL4_25, &vc4);
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL5_25, &vc5);
} else if (is63xx(dev)) {
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL4_63XX, &vc4);
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL5_63XX, &vc5);
} else {
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL4, &vc4);
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL5, &vc5);
}
mgmt &= ~SM_SW_FWD_MODE;
if (enable) {
vc0 |= VC0_VLAN_EN | VC0_VID_CHK_EN | VC0_VID_HASH_VID;
vc1 |= VC1_RX_MCST_UNTAG_EN | VC1_RX_MCST_FWD_EN;
vc4 &= ~VC4_ING_VID_CHECK_MASK;
vc4 |= VC4_ING_VID_VIO_DROP << VC4_ING_VID_CHECK_S;
vc5 |= VC5_DROP_VTABLE_MISS;
if (is5325(dev))
vc0 &= ~VC0_RESERVED_1;
if (is5325(dev) || is5365(dev))
vc1 |= VC1_RX_MCST_TAG_EN;
} else {
vc0 &= ~(VC0_VLAN_EN | VC0_VID_CHK_EN | VC0_VID_HASH_VID);
vc1 &= ~(VC1_RX_MCST_UNTAG_EN | VC1_RX_MCST_FWD_EN);
vc4 &= ~VC4_ING_VID_CHECK_MASK;
vc5 &= ~VC5_DROP_VTABLE_MISS;
if (is5325(dev) || is5365(dev))
vc4 |= VC4_ING_VID_VIO_FWD << VC4_ING_VID_CHECK_S;
else
vc4 |= VC4_ING_VID_VIO_TO_IMP << VC4_ING_VID_CHECK_S;
if (is5325(dev) || is5365(dev))
vc1 &= ~VC1_RX_MCST_TAG_EN;
}
if (!is5325(dev) && !is5365(dev))
vc5 &= ~VC5_VID_FFF_EN;
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL0, vc0);
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL1, vc1);
if (is5325(dev) || is5365(dev)) {
if (is5325(dev) && enable)
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL3,
VC3_HIGH_8BIT_EN);
else
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL3, 0);
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL4_25, vc4);
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL5_25, vc5);
} else if (is63xx(dev)) {
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_CTRL3_63XX, 0);
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL4_63XX, vc4);
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL5_63XX, vc5);
} else {
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_CTRL3, 0);
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL4, vc4);
b53_write8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL5, vc5);
}
b53_write8(dev, B53_CTRL_PAGE, B53_SWITCH_MODE, mgmt);
}
static int b53_set_jumbo(struct b53_device *dev, bool enable, bool allow_10_100)
{
u32 port_mask = 0;
u16 max_size = JMS_MIN_SIZE;
if (is5325(dev) || is5365(dev))
return -EINVAL;
if (enable) {
port_mask = dev->enabled_ports;
max_size = JMS_MAX_SIZE;
if (allow_10_100)
port_mask |= JPM_10_100_JUMBO_EN;
}
b53_write32(dev, B53_JUMBO_PAGE, dev->jumbo_pm_reg, port_mask);
return b53_write16(dev, B53_JUMBO_PAGE, dev->jumbo_size_reg, max_size);
}
static int b53_flush_arl(struct b53_device *dev, u8 mask)
{
unsigned int i;
b53_write8(dev, B53_CTRL_PAGE, B53_FAST_AGE_CTRL,
FAST_AGE_DONE | FAST_AGE_DYNAMIC | mask);
for (i = 0; i < 10; i++) {
u8 fast_age_ctrl;
b53_read8(dev, B53_CTRL_PAGE, B53_FAST_AGE_CTRL,
&fast_age_ctrl);
if (!(fast_age_ctrl & FAST_AGE_DONE))
goto out;
msleep(1);
}
return -ETIMEDOUT;
out:
b53_write8(dev, B53_CTRL_PAGE, B53_FAST_AGE_CTRL, FAST_AGE_DYNAMIC);
return 0;
}
static int b53_fast_age_port(struct b53_device *dev, int port)
{
b53_write8(dev, B53_CTRL_PAGE, B53_FAST_AGE_PORT_CTRL, port);
return b53_flush_arl(dev, FAST_AGE_PORT);
}
static int b53_fast_age_vlan(struct b53_device *dev, u16 vid)
{
b53_write16(dev, B53_CTRL_PAGE, B53_FAST_AGE_VID_CTRL, vid);
return b53_flush_arl(dev, FAST_AGE_VLAN);
}
static void b53_imp_vlan_setup(struct dsa_switch *ds, int cpu_port)
{
struct b53_device *dev = ds->priv;
unsigned int i;
u16 pvlan;
b53_for_each_port(dev, i) {
b53_read16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(i), &pvlan);
pvlan |= BIT(cpu_port);
b53_write16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(i), pvlan);
}
}
static int b53_enable_port(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct b53_device *dev = ds->priv;
unsigned int cpu_port = dev->cpu_port;
u16 pvlan;
b53_write8(dev, B53_CTRL_PAGE, B53_PORT_CTRL(port), 0);
b53_read16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(port), &pvlan);
pvlan &= ~0x1ff;
pvlan |= BIT(port);
pvlan |= dev->ports[port].vlan_ctl_mask;
b53_write16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(port), pvlan);
b53_imp_vlan_setup(ds, cpu_port);
return 0;
}
static void b53_disable_port(struct dsa_switch *ds, int port,
struct phy_device *phy)
{
struct b53_device *dev = ds->priv;
u8 reg;
b53_read8(dev, B53_CTRL_PAGE, B53_PORT_CTRL(port), &reg);
reg |= PORT_CTRL_RX_DISABLE | PORT_CTRL_TX_DISABLE;
b53_write8(dev, B53_CTRL_PAGE, B53_PORT_CTRL(port), reg);
}
static void b53_enable_cpu_port(struct b53_device *dev)
{
unsigned int cpu_port = dev->cpu_port;
u8 port_ctrl;
if ((is5325(dev) || is5365(dev)) && cpu_port == B53_CPU_PORT_25)
cpu_port = B53_CPU_PORT;
port_ctrl = PORT_CTRL_RX_BCST_EN |
PORT_CTRL_RX_MCST_EN |
PORT_CTRL_RX_UCST_EN;
b53_write8(dev, B53_CTRL_PAGE, B53_PORT_CTRL(cpu_port), port_ctrl);
}
static void b53_enable_mib(struct b53_device *dev)
{
u8 gc;
b53_read8(dev, B53_MGMT_PAGE, B53_GLOBAL_CONFIG, &gc);
gc &= ~(GC_RESET_MIB | GC_MIB_AC_EN);
b53_write8(dev, B53_MGMT_PAGE, B53_GLOBAL_CONFIG, gc);
}
static int b53_configure_vlan(struct b53_device *dev)
{
struct b53_vlan vl = { 0 };
int i;
if (is5325(dev) || is5365(dev)) {
for (i = 1; i < dev->num_vlans; i++)
b53_set_vlan_entry(dev, i, &vl);
} else {
b53_do_vlan_op(dev, VTA_CMD_CLEAR);
}
b53_enable_vlan(dev, false);
b53_for_each_port(dev, i)
b53_write16(dev, B53_VLAN_PAGE,
B53_VLAN_PORT_DEF_TAG(i), 1);
if (!is5325(dev) && !is5365(dev))
b53_set_jumbo(dev, dev->enable_jumbo, false);
return 0;
}
static void b53_switch_reset_gpio(struct b53_device *dev)
{
int gpio = dev->reset_gpio;
if (gpio < 0)
return;
gpio_set_value(gpio, 0);
mdelay(50);
gpio_set_value(gpio, 1);
mdelay(20);
dev->current_page = 0xff;
}
static int b53_switch_reset(struct b53_device *dev)
{
unsigned int timeout = 1000;
u8 mgmt, reg;
b53_switch_reset_gpio(dev);
if (is539x(dev)) {
b53_write8(dev, B53_CTRL_PAGE, B53_SOFTRESET, 0x83);
b53_write8(dev, B53_CTRL_PAGE, B53_SOFTRESET, 0x00);
}
if (dev->chip_id == BCM58XX_DEVICE_ID) {
b53_read8(dev, B53_CTRL_PAGE, B53_SOFTRESET, &reg);
reg |= SW_RST | EN_SW_RST | EN_CH_RST;
b53_write8(dev, B53_CTRL_PAGE, B53_SOFTRESET, reg);
do {
b53_read8(dev, B53_CTRL_PAGE, B53_SOFTRESET, &reg);
if (!(reg & SW_RST))
break;
usleep_range(1000, 2000);
} while (timeout-- > 0);
if (timeout == 0)
return -ETIMEDOUT;
}
b53_read8(dev, B53_CTRL_PAGE, B53_SWITCH_MODE, &mgmt);
if (!(mgmt & SM_SW_FWD_EN)) {
mgmt &= ~SM_SW_FWD_MODE;
mgmt |= SM_SW_FWD_EN;
b53_write8(dev, B53_CTRL_PAGE, B53_SWITCH_MODE, mgmt);
b53_read8(dev, B53_CTRL_PAGE, B53_SWITCH_MODE, &mgmt);
if (!(mgmt & SM_SW_FWD_EN)) {
dev_err(dev->dev, "Failed to enable switch!\n");
return -EINVAL;
}
}
b53_enable_mib(dev);
return b53_flush_arl(dev, FAST_AGE_STATIC);
}
static int b53_phy_read16(struct dsa_switch *ds, int addr, int reg)
{
struct b53_device *priv = ds->priv;
u16 value = 0;
int ret;
if (priv->ops->phy_read16)
ret = priv->ops->phy_read16(priv, addr, reg, &value);
else
ret = b53_read16(priv, B53_PORT_MII_PAGE(addr),
reg * 2, &value);
return ret ? ret : value;
}
static int b53_phy_write16(struct dsa_switch *ds, int addr, int reg, u16 val)
{
struct b53_device *priv = ds->priv;
if (priv->ops->phy_write16)
return priv->ops->phy_write16(priv, addr, reg, val);
return b53_write16(priv, B53_PORT_MII_PAGE(addr), reg * 2, val);
}
static int b53_reset_switch(struct b53_device *priv)
{
priv->enable_jumbo = false;
memset(priv->vlans, 0, sizeof(*priv->vlans) * priv->num_vlans);
memset(priv->ports, 0, sizeof(*priv->ports) * priv->num_ports);
return b53_switch_reset(priv);
}
static int b53_apply_config(struct b53_device *priv)
{
b53_set_forwarding(priv, 0);
b53_configure_vlan(priv);
b53_set_forwarding(priv, 1);
return 0;
}
static void b53_reset_mib(struct b53_device *priv)
{
u8 gc;
b53_read8(priv, B53_MGMT_PAGE, B53_GLOBAL_CONFIG, &gc);
b53_write8(priv, B53_MGMT_PAGE, B53_GLOBAL_CONFIG, gc | GC_RESET_MIB);
msleep(1);
b53_write8(priv, B53_MGMT_PAGE, B53_GLOBAL_CONFIG, gc & ~GC_RESET_MIB);
msleep(1);
}
static const struct b53_mib_desc *b53_get_mib(struct b53_device *dev)
{
if (is5365(dev))
return b53_mibs_65;
else if (is63xx(dev))
return b53_mibs_63xx;
else if (is58xx(dev))
return b53_mibs_58xx;
else
return b53_mibs;
}
static unsigned int b53_get_mib_size(struct b53_device *dev)
{
if (is5365(dev))
return B53_MIBS_65_SIZE;
else if (is63xx(dev))
return B53_MIBS_63XX_SIZE;
else if (is58xx(dev))
return B53_MIBS_58XX_SIZE;
else
return B53_MIBS_SIZE;
}
void b53_get_strings(struct dsa_switch *ds, int port, uint8_t *data)
{
struct b53_device *dev = ds->priv;
const struct b53_mib_desc *mibs = b53_get_mib(dev);
unsigned int mib_size = b53_get_mib_size(dev);
unsigned int i;
for (i = 0; i < mib_size; i++)
memcpy(data + i * ETH_GSTRING_LEN,
mibs[i].name, ETH_GSTRING_LEN);
}
void b53_get_ethtool_stats(struct dsa_switch *ds, int port, uint64_t *data)
{
struct b53_device *dev = ds->priv;
const struct b53_mib_desc *mibs = b53_get_mib(dev);
unsigned int mib_size = b53_get_mib_size(dev);
const struct b53_mib_desc *s;
unsigned int i;
u64 val = 0;
if (is5365(dev) && port == 5)
port = 8;
mutex_lock(&dev->stats_mutex);
for (i = 0; i < mib_size; i++) {
s = &mibs[i];
if (s->size == 8) {
b53_read64(dev, B53_MIB_PAGE(port), s->offset, &val);
} else {
u32 val32;
b53_read32(dev, B53_MIB_PAGE(port), s->offset,
&val32);
val = val32;
}
data[i] = (u64)val;
}
mutex_unlock(&dev->stats_mutex);
}
int b53_get_sset_count(struct dsa_switch *ds)
{
struct b53_device *dev = ds->priv;
return b53_get_mib_size(dev);
}
static int b53_setup(struct dsa_switch *ds)
{
struct b53_device *dev = ds->priv;
unsigned int port;
int ret;
ret = b53_reset_switch(dev);
if (ret) {
dev_err(ds->dev, "failed to reset switch\n");
return ret;
}
b53_reset_mib(dev);
ret = b53_apply_config(dev);
if (ret)
dev_err(ds->dev, "failed to apply configuration\n");
for (port = 0; port < dev->num_ports; port++) {
if (BIT(port) & ds->enabled_port_mask)
b53_enable_port(ds, port, NULL);
else if (dsa_is_cpu_port(ds, port))
b53_enable_cpu_port(dev);
else
b53_disable_port(ds, port, NULL);
}
return ret;
}
static void b53_adjust_link(struct dsa_switch *ds, int port,
struct phy_device *phydev)
{
struct b53_device *dev = ds->priv;
u8 rgmii_ctrl = 0, reg = 0, off;
if (!phy_is_pseudo_fixed_link(phydev))
return;
if (port == dev->cpu_port) {
off = B53_PORT_OVERRIDE_CTRL;
reg = PORT_OVERRIDE_EN;
} else {
off = B53_GMII_PORT_OVERRIDE_CTRL(port);
reg = GMII_PO_EN;
}
if (phydev->link)
reg |= PORT_OVERRIDE_LINK;
if (phydev->duplex == DUPLEX_FULL)
reg |= PORT_OVERRIDE_FULL_DUPLEX;
switch (phydev->speed) {
case 2000:
reg |= PORT_OVERRIDE_SPEED_2000M;
case SPEED_1000:
reg |= PORT_OVERRIDE_SPEED_1000M;
break;
case SPEED_100:
reg |= PORT_OVERRIDE_SPEED_100M;
break;
case SPEED_10:
reg |= PORT_OVERRIDE_SPEED_10M;
break;
default:
dev_err(ds->dev, "unknown speed: %d\n", phydev->speed);
return;
}
if (is5301x(dev) && port == dev->cpu_port)
reg |= PORT_OVERRIDE_RX_FLOW | PORT_OVERRIDE_TX_FLOW;
if (phydev->pause) {
if (phydev->asym_pause)
reg |= PORT_OVERRIDE_TX_FLOW;
reg |= PORT_OVERRIDE_RX_FLOW;
}
b53_write8(dev, B53_CTRL_PAGE, off, reg);
if (is531x5(dev) && phy_interface_is_rgmii(phydev)) {
if (port == 8)
off = B53_RGMII_CTRL_IMP;
else
off = B53_RGMII_CTRL_P(port);
b53_read8(dev, B53_CTRL_PAGE, off, &rgmii_ctrl);
rgmii_ctrl &= ~(RGMII_CTRL_DLL_RXC | RGMII_CTRL_DLL_TXC |
RGMII_CTRL_TIMING_SEL);
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)
rgmii_ctrl |= RGMII_CTRL_DLL_TXC;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII)
rgmii_ctrl |= RGMII_CTRL_DLL_TXC | RGMII_CTRL_DLL_RXC;
rgmii_ctrl |= RGMII_CTRL_TIMING_SEL;
b53_write8(dev, B53_CTRL_PAGE, off, rgmii_ctrl);
dev_info(ds->dev, "Configured port %d for %s\n", port,
phy_modes(phydev->interface));
}
if (is5325(dev)) {
b53_read8(dev, B53_CTRL_PAGE, B53_PORT_OVERRIDE_CTRL,
&reg);
if (!(reg & PORT_OVERRIDE_RV_MII_25)) {
b53_write8(dev, B53_CTRL_PAGE, B53_PORT_OVERRIDE_CTRL,
reg | PORT_OVERRIDE_RV_MII_25);
b53_read8(dev, B53_CTRL_PAGE, B53_PORT_OVERRIDE_CTRL,
&reg);
if (!(reg & PORT_OVERRIDE_RV_MII_25)) {
dev_err(ds->dev,
"Failed to enable reverse MII mode\n");
return;
}
}
} else if (is5301x(dev)) {
if (port != dev->cpu_port) {
u8 po_reg = B53_GMII_PORT_OVERRIDE_CTRL(dev->cpu_port);
u8 gmii_po;
b53_read8(dev, B53_CTRL_PAGE, po_reg, &gmii_po);
gmii_po |= GMII_PO_LINK |
GMII_PO_RX_FLOW |
GMII_PO_TX_FLOW |
GMII_PO_EN |
GMII_PO_SPEED_2000M;
b53_write8(dev, B53_CTRL_PAGE, po_reg, gmii_po);
}
}
}
int b53_vlan_filtering(struct dsa_switch *ds, int port, bool vlan_filtering)
{
return 0;
}
int b53_vlan_prepare(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan,
struct switchdev_trans *trans)
{
struct b53_device *dev = ds->priv;
if ((is5325(dev) || is5365(dev)) && vlan->vid_begin == 0)
return -EOPNOTSUPP;
if (vlan->vid_end > dev->num_vlans)
return -ERANGE;
b53_enable_vlan(dev, true);
return 0;
}
void b53_vlan_add(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan,
struct switchdev_trans *trans)
{
struct b53_device *dev = ds->priv;
bool untagged = vlan->flags & BRIDGE_VLAN_INFO_UNTAGGED;
bool pvid = vlan->flags & BRIDGE_VLAN_INFO_PVID;
unsigned int cpu_port = dev->cpu_port;
struct b53_vlan *vl;
u16 vid;
for (vid = vlan->vid_begin; vid <= vlan->vid_end; ++vid) {
vl = &dev->vlans[vid];
b53_get_vlan_entry(dev, vid, vl);
vl->members |= BIT(port) | BIT(cpu_port);
if (untagged)
vl->untag |= BIT(port);
else
vl->untag &= ~BIT(port);
vl->untag &= ~BIT(cpu_port);
b53_set_vlan_entry(dev, vid, vl);
b53_fast_age_vlan(dev, vid);
}
if (pvid) {
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_PORT_DEF_TAG(port),
vlan->vid_end);
b53_fast_age_vlan(dev, vid);
}
}
int b53_vlan_del(struct dsa_switch *ds, int port,
const struct switchdev_obj_port_vlan *vlan)
{
struct b53_device *dev = ds->priv;
bool untagged = vlan->flags & BRIDGE_VLAN_INFO_UNTAGGED;
struct b53_vlan *vl;
u16 vid;
u16 pvid;
b53_read16(dev, B53_VLAN_PAGE, B53_VLAN_PORT_DEF_TAG(port), &pvid);
for (vid = vlan->vid_begin; vid <= vlan->vid_end; ++vid) {
vl = &dev->vlans[vid];
b53_get_vlan_entry(dev, vid, vl);
vl->members &= ~BIT(port);
if (pvid == vid) {
if (is5325(dev) || is5365(dev))
pvid = 1;
else
pvid = 0;
}
if (untagged)
vl->untag &= ~(BIT(port));
b53_set_vlan_entry(dev, vid, vl);
b53_fast_age_vlan(dev, vid);
}
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_PORT_DEF_TAG(port), pvid);
b53_fast_age_vlan(dev, pvid);
return 0;
}
static int b53_arl_op_wait(struct b53_device *dev)
{
unsigned int timeout = 10;
u8 reg;
do {
b53_read8(dev, B53_ARLIO_PAGE, B53_ARLTBL_RW_CTRL, &reg);
if (!(reg & ARLTBL_START_DONE))
return 0;
usleep_range(1000, 2000);
} while (timeout--);
dev_warn(dev->dev, "timeout waiting for ARL to finish: 0x%02x\n", reg);
return -ETIMEDOUT;
}
static int b53_arl_rw_op(struct b53_device *dev, unsigned int op)
{
u8 reg;
if (op > ARLTBL_RW)
return -EINVAL;
b53_read8(dev, B53_ARLIO_PAGE, B53_ARLTBL_RW_CTRL, &reg);
reg |= ARLTBL_START_DONE;
if (op)
reg |= ARLTBL_RW;
else
reg &= ~ARLTBL_RW;
b53_write8(dev, B53_ARLIO_PAGE, B53_ARLTBL_RW_CTRL, reg);
return b53_arl_op_wait(dev);
}
static int b53_arl_read(struct b53_device *dev, u64 mac,
u16 vid, struct b53_arl_entry *ent, u8 *idx,
bool is_valid)
{
unsigned int i;
int ret;
ret = b53_arl_op_wait(dev);
if (ret)
return ret;
for (i = 0; i < dev->num_arl_entries; i++) {
u64 mac_vid;
u32 fwd_entry;
b53_read64(dev, B53_ARLIO_PAGE,
B53_ARLTBL_MAC_VID_ENTRY(i), &mac_vid);
b53_read32(dev, B53_ARLIO_PAGE,
B53_ARLTBL_DATA_ENTRY(i), &fwd_entry);
b53_arl_to_entry(ent, mac_vid, fwd_entry);
if (!(fwd_entry & ARLTBL_VALID))
continue;
if ((mac_vid & ARLTBL_MAC_MASK) != mac)
continue;
*idx = i;
}
return -ENOENT;
}
static int b53_arl_op(struct b53_device *dev, int op, int port,
const unsigned char *addr, u16 vid, bool is_valid)
{
struct b53_arl_entry ent;
u32 fwd_entry;
u64 mac, mac_vid = 0;
u8 idx = 0;
int ret;
mac = ether_addr_to_u64(addr);
b53_write48(dev, B53_ARLIO_PAGE, B53_MAC_ADDR_IDX, mac);
b53_write16(dev, B53_ARLIO_PAGE, B53_VLAN_ID_IDX, vid);
ret = b53_arl_rw_op(dev, 1);
if (ret)
return ret;
ret = b53_arl_read(dev, mac, vid, &ent, &idx, is_valid);
if (op)
return ret;
if (ret) {
fwd_entry = 0;
idx = 1;
}
memset(&ent, 0, sizeof(ent));
ent.port = port;
ent.is_valid = is_valid;
ent.vid = vid;
ent.is_static = true;
memcpy(ent.mac, addr, ETH_ALEN);
b53_arl_from_entry(&mac_vid, &fwd_entry, &ent);
b53_write64(dev, B53_ARLIO_PAGE,
B53_ARLTBL_MAC_VID_ENTRY(idx), mac_vid);
b53_write32(dev, B53_ARLIO_PAGE,
B53_ARLTBL_DATA_ENTRY(idx), fwd_entry);
return b53_arl_rw_op(dev, 0);
}
int b53_fdb_add(struct dsa_switch *ds, int port,
const unsigned char *addr, u16 vid)
{
struct b53_device *priv = ds->priv;
if (is5325(priv) || is5365(priv))
return -EOPNOTSUPP;
return b53_arl_op(priv, 0, port, addr, vid, true);
}
int b53_fdb_del(struct dsa_switch *ds, int port,
const unsigned char *addr, u16 vid)
{
struct b53_device *priv = ds->priv;
return b53_arl_op(priv, 0, port, addr, vid, false);
}
static int b53_arl_search_wait(struct b53_device *dev)
{
unsigned int timeout = 1000;
u8 reg;
do {
b53_read8(dev, B53_ARLIO_PAGE, B53_ARL_SRCH_CTL, &reg);
if (!(reg & ARL_SRCH_STDN))
return 0;
if (reg & ARL_SRCH_VLID)
return 0;
usleep_range(1000, 2000);
} while (timeout--);
return -ETIMEDOUT;
}
static void b53_arl_search_rd(struct b53_device *dev, u8 idx,
struct b53_arl_entry *ent)
{
u64 mac_vid;
u32 fwd_entry;
b53_read64(dev, B53_ARLIO_PAGE,
B53_ARL_SRCH_RSTL_MACVID(idx), &mac_vid);
b53_read32(dev, B53_ARLIO_PAGE,
B53_ARL_SRCH_RSTL(idx), &fwd_entry);
b53_arl_to_entry(ent, mac_vid, fwd_entry);
}
static int b53_fdb_copy(int port, const struct b53_arl_entry *ent,
dsa_fdb_dump_cb_t *cb, void *data)
{
if (!ent->is_valid)
return 0;
if (port != ent->port)
return 0;
return cb(ent->mac, ent->vid, ent->is_static, data);
}
int b53_fdb_dump(struct dsa_switch *ds, int port,
dsa_fdb_dump_cb_t *cb, void *data)
{
struct b53_device *priv = ds->priv;
struct b53_arl_entry results[2];
unsigned int count = 0;
int ret;
u8 reg;
reg = ARL_SRCH_STDN;
b53_write8(priv, B53_ARLIO_PAGE, B53_ARL_SRCH_CTL, reg);
do {
ret = b53_arl_search_wait(priv);
if (ret)
return ret;
b53_arl_search_rd(priv, 0, &results[0]);
ret = b53_fdb_copy(port, &results[0], cb, data);
if (ret)
return ret;
if (priv->num_arl_entries > 2) {
b53_arl_search_rd(priv, 1, &results[1]);
ret = b53_fdb_copy(port, &results[1], cb, data);
if (ret)
return ret;
if (!results[0].is_valid && !results[1].is_valid)
break;
}
} while (count++ < 1024);
return 0;
}
int b53_br_join(struct dsa_switch *ds, int port, struct net_device *br)
{
struct b53_device *dev = ds->priv;
s8 cpu_port = ds->dst->cpu_dp->index;
u16 pvlan, reg;
unsigned int i;
if (is58xx(dev)) {
b53_read16(dev, B53_VLAN_PAGE, B53_JOIN_ALL_VLAN_EN, &reg);
reg &= ~BIT(port);
if ((reg & BIT(cpu_port)) == BIT(cpu_port))
reg &= ~BIT(cpu_port);
b53_write16(dev, B53_VLAN_PAGE, B53_JOIN_ALL_VLAN_EN, reg);
}
b53_read16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(port), &pvlan);
b53_for_each_port(dev, i) {
if (ds->ports[i].bridge_dev != br)
continue;
b53_read16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(i), &reg);
reg |= BIT(port);
b53_write16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(i), reg);
dev->ports[i].vlan_ctl_mask = reg;
pvlan |= BIT(i);
}
b53_write16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(port), pvlan);
dev->ports[port].vlan_ctl_mask = pvlan;
return 0;
}
void b53_br_leave(struct dsa_switch *ds, int port, struct net_device *br)
{
struct b53_device *dev = ds->priv;
struct b53_vlan *vl = &dev->vlans[0];
s8 cpu_port = ds->dst->cpu_dp->index;
unsigned int i;
u16 pvlan, reg, pvid;
b53_read16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(port), &pvlan);
b53_for_each_port(dev, i) {
if (ds->ports[i].bridge_dev != br)
continue;
b53_read16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(i), &reg);
reg &= ~BIT(port);
b53_write16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(i), reg);
dev->ports[port].vlan_ctl_mask = reg;
if (port != i)
pvlan &= ~BIT(i);
}
b53_write16(dev, B53_PVLAN_PAGE, B53_PVLAN_PORT_MASK(port), pvlan);
dev->ports[port].vlan_ctl_mask = pvlan;
if (is5325(dev) || is5365(dev))
pvid = 1;
else
pvid = 0;
if (is58xx(dev)) {
b53_read16(dev, B53_VLAN_PAGE, B53_JOIN_ALL_VLAN_EN, &reg);
reg |= BIT(port);
if (!(reg & BIT(cpu_port)))
reg |= BIT(cpu_port);
b53_write16(dev, B53_VLAN_PAGE, B53_JOIN_ALL_VLAN_EN, reg);
} else {
b53_get_vlan_entry(dev, pvid, vl);
vl->members |= BIT(port) | BIT(dev->cpu_port);
vl->untag |= BIT(port) | BIT(dev->cpu_port);
b53_set_vlan_entry(dev, pvid, vl);
}
}
void b53_br_set_stp_state(struct dsa_switch *ds, int port, u8 state)
{
struct b53_device *dev = ds->priv;
u8 hw_state;
u8 reg;
switch (state) {
case BR_STATE_DISABLED:
hw_state = PORT_CTRL_DIS_STATE;
break;
case BR_STATE_LISTENING:
hw_state = PORT_CTRL_LISTEN_STATE;
break;
case BR_STATE_LEARNING:
hw_state = PORT_CTRL_LEARN_STATE;
break;
case BR_STATE_FORWARDING:
hw_state = PORT_CTRL_FWD_STATE;
break;
case BR_STATE_BLOCKING:
hw_state = PORT_CTRL_BLOCK_STATE;
break;
default:
dev_err(ds->dev, "invalid STP state: %d\n", state);
return;
}
b53_read8(dev, B53_CTRL_PAGE, B53_PORT_CTRL(port), &reg);
reg &= ~PORT_CTRL_STP_STATE_MASK;
reg |= hw_state;
b53_write8(dev, B53_CTRL_PAGE, B53_PORT_CTRL(port), reg);
}
void b53_br_fast_age(struct dsa_switch *ds, int port)
{
struct b53_device *dev = ds->priv;
if (b53_fast_age_port(dev, port))
dev_err(ds->dev, "fast ageing failed\n");
}
static enum dsa_tag_protocol b53_get_tag_protocol(struct dsa_switch *ds)
{
return DSA_TAG_PROTO_NONE;
}
int b53_mirror_add(struct dsa_switch *ds, int port,
struct dsa_mall_mirror_tc_entry *mirror, bool ingress)
{
struct b53_device *dev = ds->priv;
u16 reg, loc;
if (ingress)
loc = B53_IG_MIR_CTL;
else
loc = B53_EG_MIR_CTL;
b53_read16(dev, B53_MGMT_PAGE, loc, &reg);
reg &= ~MIRROR_MASK;
reg |= BIT(port);
b53_write16(dev, B53_MGMT_PAGE, loc, reg);
b53_read16(dev, B53_MGMT_PAGE, B53_MIR_CAP_CTL, &reg);
reg &= ~CAP_PORT_MASK;
reg |= mirror->to_local_port;
reg |= MIRROR_EN;
b53_write16(dev, B53_MGMT_PAGE, B53_MIR_CAP_CTL, reg);
return 0;
}
void b53_mirror_del(struct dsa_switch *ds, int port,
struct dsa_mall_mirror_tc_entry *mirror)
{
struct b53_device *dev = ds->priv;
bool loc_disable = false, other_loc_disable = false;
u16 reg, loc;
if (mirror->ingress)
loc = B53_IG_MIR_CTL;
else
loc = B53_EG_MIR_CTL;
b53_read16(dev, B53_MGMT_PAGE, loc, &reg);
reg &= ~BIT(port);
if (!(reg & MIRROR_MASK))
loc_disable = true;
b53_write16(dev, B53_MGMT_PAGE, loc, reg);
if (mirror->ingress)
b53_read16(dev, B53_MGMT_PAGE, B53_EG_MIR_CTL, &reg);
else
b53_read16(dev, B53_MGMT_PAGE, B53_IG_MIR_CTL, &reg);
if (!(reg & MIRROR_MASK))
other_loc_disable = true;
b53_read16(dev, B53_MGMT_PAGE, B53_MIR_CAP_CTL, &reg);
if (loc_disable && other_loc_disable) {
reg &= ~MIRROR_EN;
reg &= ~mirror->to_local_port;
}
b53_write16(dev, B53_MGMT_PAGE, B53_MIR_CAP_CTL, reg);
}
static int b53_switch_init(struct b53_device *dev)
{
unsigned int i;
int ret;
for (i = 0; i < ARRAY_SIZE(b53_switch_chips); i++) {
const struct b53_chip_data *chip = &b53_switch_chips[i];
if (chip->chip_id == dev->chip_id) {
if (!dev->enabled_ports)
dev->enabled_ports = chip->enabled_ports;
dev->name = chip->dev_name;
dev->duplex_reg = chip->duplex_reg;
dev->vta_regs[0] = chip->vta_regs[0];
dev->vta_regs[1] = chip->vta_regs[1];
dev->vta_regs[2] = chip->vta_regs[2];
dev->jumbo_pm_reg = chip->jumbo_pm_reg;
dev->cpu_port = chip->cpu_port;
dev->num_vlans = chip->vlans;
dev->num_arl_entries = chip->arl_entries;
break;
}
}
if (is5325(dev)) {
u8 vc4;
b53_read8(dev, B53_VLAN_PAGE, B53_VLAN_CTRL4_25, &vc4);
switch (vc4 & 3) {
case 1:
break;
case 3:
dev->enabled_ports &= ~BIT(4);
break;
default:
#ifndef CONFIG_BCM47XX
return -EINVAL;
#else
break;
#endif
}
} else if (dev->chip_id == BCM53115_DEVICE_ID) {
u64 strap_value;
b53_read48(dev, B53_STAT_PAGE, B53_STRAP_VALUE, &strap_value);
if (strap_value & SV_GMII_CTRL_115)
dev->cpu_port = 5;
}
dev->num_ports = dev->cpu_port + 1;
dev->enabled_ports |= BIT(dev->cpu_port);
dev->ports = devm_kzalloc(dev->dev,
sizeof(struct b53_port) * dev->num_ports,
GFP_KERNEL);
if (!dev->ports)
return -ENOMEM;
dev->vlans = devm_kzalloc(dev->dev,
sizeof(struct b53_vlan) * dev->num_vlans,
GFP_KERNEL);
if (!dev->vlans)
return -ENOMEM;
dev->reset_gpio = b53_switch_get_reset_gpio(dev);
if (dev->reset_gpio >= 0) {
ret = devm_gpio_request_one(dev->dev, dev->reset_gpio,
GPIOF_OUT_INIT_HIGH, "robo_reset");
if (ret)
return ret;
}
return 0;
}
struct b53_device *b53_switch_alloc(struct device *base,
const struct b53_io_ops *ops,
void *priv)
{
struct dsa_switch *ds;
struct b53_device *dev;
ds = dsa_switch_alloc(base, DSA_MAX_PORTS);
if (!ds)
return NULL;
dev = devm_kzalloc(base, sizeof(*dev), GFP_KERNEL);
if (!dev)
return NULL;
ds->priv = dev;
dev->dev = base;
dev->ds = ds;
dev->priv = priv;
dev->ops = ops;
ds->ops = &b53_switch_ops;
mutex_init(&dev->reg_mutex);
mutex_init(&dev->stats_mutex);
return dev;
}
int b53_switch_detect(struct b53_device *dev)
{
u32 id32;
u16 tmp;
u8 id8;
int ret;
ret = b53_read8(dev, B53_MGMT_PAGE, B53_DEVICE_ID, &id8);
if (ret)
return ret;
switch (id8) {
case 0:
b53_write16(dev, B53_VLAN_PAGE, B53_VLAN_TABLE_ACCESS_25, 0xf);
b53_read16(dev, B53_VLAN_PAGE, B53_VLAN_TABLE_ACCESS_25, &tmp);
if (tmp == 0xf)
dev->chip_id = BCM5325_DEVICE_ID;
else
dev->chip_id = BCM5365_DEVICE_ID;
break;
case BCM5395_DEVICE_ID:
case BCM5397_DEVICE_ID:
case BCM5398_DEVICE_ID:
dev->chip_id = id8;
break;
default:
ret = b53_read32(dev, B53_MGMT_PAGE, B53_DEVICE_ID, &id32);
if (ret)
return ret;
switch (id32) {
case BCM53115_DEVICE_ID:
case BCM53125_DEVICE_ID:
case BCM53128_DEVICE_ID:
case BCM53010_DEVICE_ID:
case BCM53011_DEVICE_ID:
case BCM53012_DEVICE_ID:
case BCM53018_DEVICE_ID:
case BCM53019_DEVICE_ID:
dev->chip_id = id32;
break;
default:
pr_err("unsupported switch detected (BCM53%02x/BCM%x)\n",
id8, id32);
return -ENODEV;
}
}
if (dev->chip_id == BCM5325_DEVICE_ID)
return b53_read8(dev, B53_STAT_PAGE, B53_REV_ID_25,
&dev->core_rev);
else
return b53_read8(dev, B53_MGMT_PAGE, B53_REV_ID,
&dev->core_rev);
}
int b53_switch_register(struct b53_device *dev)
{
int ret;
if (dev->pdata) {
dev->chip_id = dev->pdata->chip_id;
dev->enabled_ports = dev->pdata->enabled_ports;
}
if (!dev->chip_id && b53_switch_detect(dev))
return -EINVAL;
ret = b53_switch_init(dev);
if (ret)
return ret;
pr_info("found switch: %s, rev %i\n", dev->name, dev->core_rev);
return dsa_register_switch(dev->ds);
}
