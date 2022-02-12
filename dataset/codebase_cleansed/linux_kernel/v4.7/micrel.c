static int kszphy_extended_write(struct phy_device *phydev,
u32 regnum, u16 val)
{
phy_write(phydev, MII_KSZPHY_EXTREG, KSZPHY_EXTREG_WRITE | regnum);
return phy_write(phydev, MII_KSZPHY_EXTREG_WRITE, val);
}
static int kszphy_extended_read(struct phy_device *phydev,
u32 regnum)
{
phy_write(phydev, MII_KSZPHY_EXTREG, regnum);
return phy_read(phydev, MII_KSZPHY_EXTREG_READ);
}
static int kszphy_ack_interrupt(struct phy_device *phydev)
{
int rc;
rc = phy_read(phydev, MII_KSZPHY_INTCS);
return (rc < 0) ? rc : 0;
}
static int kszphy_config_intr(struct phy_device *phydev)
{
const struct kszphy_type *type = phydev->drv->driver_data;
int temp;
u16 mask;
if (type && type->interrupt_level_mask)
mask = type->interrupt_level_mask;
else
mask = KSZPHY_CTRL_INT_ACTIVE_HIGH;
temp = phy_read(phydev, MII_KSZPHY_CTRL);
if (temp < 0)
return temp;
temp &= ~mask;
phy_write(phydev, MII_KSZPHY_CTRL, temp);
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
temp = KSZPHY_INTCS_ALL;
else
temp = 0;
return phy_write(phydev, MII_KSZPHY_INTCS, temp);
}
static int kszphy_rmii_clk_sel(struct phy_device *phydev, bool val)
{
int ctrl;
ctrl = phy_read(phydev, MII_KSZPHY_CTRL);
if (ctrl < 0)
return ctrl;
if (val)
ctrl |= KSZPHY_RMII_REF_CLK_SEL;
else
ctrl &= ~KSZPHY_RMII_REF_CLK_SEL;
return phy_write(phydev, MII_KSZPHY_CTRL, ctrl);
}
static int kszphy_setup_led(struct phy_device *phydev, u32 reg, int val)
{
int rc, temp, shift;
switch (reg) {
case MII_KSZPHY_CTRL_1:
shift = 14;
break;
case MII_KSZPHY_CTRL_2:
shift = 4;
break;
default:
return -EINVAL;
}
temp = phy_read(phydev, reg);
if (temp < 0) {
rc = temp;
goto out;
}
temp &= ~(3 << shift);
temp |= val << shift;
rc = phy_write(phydev, reg, temp);
out:
if (rc < 0)
phydev_err(phydev, "failed to set led mode\n");
return rc;
}
static int kszphy_broadcast_disable(struct phy_device *phydev)
{
int ret;
ret = phy_read(phydev, MII_KSZPHY_OMSO);
if (ret < 0)
goto out;
ret = phy_write(phydev, MII_KSZPHY_OMSO, ret | KSZPHY_OMSO_B_CAST_OFF);
out:
if (ret)
phydev_err(phydev, "failed to disable broadcast address\n");
return ret;
}
static int kszphy_nand_tree_disable(struct phy_device *phydev)
{
int ret;
ret = phy_read(phydev, MII_KSZPHY_OMSO);
if (ret < 0)
goto out;
if (!(ret & KSZPHY_OMSO_NAND_TREE_ON))
return 0;
ret = phy_write(phydev, MII_KSZPHY_OMSO,
ret & ~KSZPHY_OMSO_NAND_TREE_ON);
out:
if (ret)
phydev_err(phydev, "failed to disable NAND tree mode\n");
return ret;
}
static int kszphy_config_init(struct phy_device *phydev)
{
struct kszphy_priv *priv = phydev->priv;
const struct kszphy_type *type;
int ret;
if (!priv)
return 0;
type = priv->type;
if (type->has_broadcast_disable)
kszphy_broadcast_disable(phydev);
if (type->has_nand_tree_disable)
kszphy_nand_tree_disable(phydev);
if (priv->rmii_ref_clk_sel) {
ret = kszphy_rmii_clk_sel(phydev, priv->rmii_ref_clk_sel_val);
if (ret) {
phydev_err(phydev,
"failed to set rmii reference clock\n");
return ret;
}
}
if (priv->led_mode >= 0)
kszphy_setup_led(phydev, type->led_mode_reg, priv->led_mode);
if (phy_interrupt_is_valid(phydev)) {
int ctl = phy_read(phydev, MII_BMCR);
if (ctl < 0)
return ctl;
ret = phy_write(phydev, MII_BMCR, ctl & ~BMCR_ANENABLE);
if (ret < 0)
return ret;
}
return 0;
}
static int ksz9021_load_values_from_of(struct phy_device *phydev,
const struct device_node *of_node,
u16 reg,
const char *field1, const char *field2,
const char *field3, const char *field4)
{
int val1 = -1;
int val2 = -2;
int val3 = -3;
int val4 = -4;
int newval;
int matches = 0;
if (!of_property_read_u32(of_node, field1, &val1))
matches++;
if (!of_property_read_u32(of_node, field2, &val2))
matches++;
if (!of_property_read_u32(of_node, field3, &val3))
matches++;
if (!of_property_read_u32(of_node, field4, &val4))
matches++;
if (!matches)
return 0;
if (matches < 4)
newval = kszphy_extended_read(phydev, reg);
else
newval = 0;
if (val1 != -1)
newval = ((newval & 0xfff0) | ((val1 / PS_TO_REG) & 0xf) << 0);
if (val2 != -2)
newval = ((newval & 0xff0f) | ((val2 / PS_TO_REG) & 0xf) << 4);
if (val3 != -3)
newval = ((newval & 0xf0ff) | ((val3 / PS_TO_REG) & 0xf) << 8);
if (val4 != -4)
newval = ((newval & 0x0fff) | ((val4 / PS_TO_REG) & 0xf) << 12);
return kszphy_extended_write(phydev, reg, newval);
}
static int ksz9021_config_init(struct phy_device *phydev)
{
const struct device *dev = &phydev->mdio.dev;
const struct device_node *of_node = dev->of_node;
const struct device *dev_walker;
dev_walker = &phydev->mdio.dev;
do {
of_node = dev_walker->of_node;
dev_walker = dev_walker->parent;
} while (!of_node && dev_walker);
if (of_node) {
ksz9021_load_values_from_of(phydev, of_node,
MII_KSZPHY_CLK_CONTROL_PAD_SKEW,
"txen-skew-ps", "txc-skew-ps",
"rxdv-skew-ps", "rxc-skew-ps");
ksz9021_load_values_from_of(phydev, of_node,
MII_KSZPHY_RX_DATA_PAD_SKEW,
"rxd0-skew-ps", "rxd1-skew-ps",
"rxd2-skew-ps", "rxd3-skew-ps");
ksz9021_load_values_from_of(phydev, of_node,
MII_KSZPHY_TX_DATA_PAD_SKEW,
"txd0-skew-ps", "txd1-skew-ps",
"txd2-skew-ps", "txd3-skew-ps");
}
return 0;
}
static int ksz9031_extended_write(struct phy_device *phydev,
u8 mode, u32 dev_addr, u32 regnum, u16 val)
{
phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, dev_addr);
phy_write(phydev, MII_KSZ9031RN_MMD_REGDATA_REG, regnum);
phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, (mode << 14) | dev_addr);
return phy_write(phydev, MII_KSZ9031RN_MMD_REGDATA_REG, val);
}
static int ksz9031_extended_read(struct phy_device *phydev,
u8 mode, u32 dev_addr, u32 regnum)
{
phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, dev_addr);
phy_write(phydev, MII_KSZ9031RN_MMD_REGDATA_REG, regnum);
phy_write(phydev, MII_KSZ9031RN_MMD_CTRL_REG, (mode << 14) | dev_addr);
return phy_read(phydev, MII_KSZ9031RN_MMD_REGDATA_REG);
}
static int ksz9031_of_load_skew_values(struct phy_device *phydev,
const struct device_node *of_node,
u16 reg, size_t field_sz,
const char *field[], u8 numfields)
{
int val[4] = {-1, -2, -3, -4};
int matches = 0;
u16 mask;
u16 maxval;
u16 newval;
int i;
for (i = 0; i < numfields; i++)
if (!of_property_read_u32(of_node, field[i], val + i))
matches++;
if (!matches)
return 0;
if (matches < numfields)
newval = ksz9031_extended_read(phydev, OP_DATA, 2, reg);
else
newval = 0;
maxval = (field_sz == 4) ? 0xf : 0x1f;
for (i = 0; i < numfields; i++)
if (val[i] != -(i + 1)) {
mask = 0xffff;
mask ^= maxval << (field_sz * i);
newval = (newval & mask) |
(((val[i] / KSZ9031_PS_TO_REG) & maxval)
<< (field_sz * i));
}
return ksz9031_extended_write(phydev, OP_DATA, 2, reg, newval);
}
static int ksz9031_center_flp_timing(struct phy_device *phydev)
{
int result;
result = ksz9031_extended_write(phydev, OP_DATA, 0,
MII_KSZ9031RN_FLP_BURST_TX_HI, 0x0006);
result = ksz9031_extended_write(phydev, OP_DATA, 0,
MII_KSZ9031RN_FLP_BURST_TX_LO, 0x1A80);
if (result)
return result;
return genphy_restart_aneg(phydev);
}
static int ksz9031_config_init(struct phy_device *phydev)
{
const struct device *dev = &phydev->mdio.dev;
const struct device_node *of_node = dev->of_node;
static const char *clk_skews[2] = {"rxc-skew-ps", "txc-skew-ps"};
static const char *rx_data_skews[4] = {
"rxd0-skew-ps", "rxd1-skew-ps",
"rxd2-skew-ps", "rxd3-skew-ps"
};
static const char *tx_data_skews[4] = {
"txd0-skew-ps", "txd1-skew-ps",
"txd2-skew-ps", "txd3-skew-ps"
};
static const char *control_skews[2] = {"txen-skew-ps", "rxdv-skew-ps"};
const struct device *dev_walker;
dev_walker = &phydev->mdio.dev;
do {
of_node = dev_walker->of_node;
dev_walker = dev_walker->parent;
} while (!of_node && dev_walker);
if (of_node) {
ksz9031_of_load_skew_values(phydev, of_node,
MII_KSZ9031RN_CLK_PAD_SKEW, 5,
clk_skews, 2);
ksz9031_of_load_skew_values(phydev, of_node,
MII_KSZ9031RN_CONTROL_PAD_SKEW, 4,
control_skews, 2);
ksz9031_of_load_skew_values(phydev, of_node,
MII_KSZ9031RN_RX_DATA_PAD_SKEW, 4,
rx_data_skews, 4);
ksz9031_of_load_skew_values(phydev, of_node,
MII_KSZ9031RN_TX_DATA_PAD_SKEW, 4,
tx_data_skews, 4);
}
return ksz9031_center_flp_timing(phydev);
}
static int ksz8873mll_read_status(struct phy_device *phydev)
{
int regval;
regval = phy_read(phydev, KSZ8873MLL_GLOBAL_CONTROL_4);
regval = phy_read(phydev, KSZ8873MLL_GLOBAL_CONTROL_4);
if (regval & KSZ8873MLL_GLOBAL_CONTROL_4_DUPLEX)
phydev->duplex = DUPLEX_HALF;
else
phydev->duplex = DUPLEX_FULL;
if (regval & KSZ8873MLL_GLOBAL_CONTROL_4_SPEED)
phydev->speed = SPEED_10;
else
phydev->speed = SPEED_100;
phydev->link = 1;
phydev->pause = phydev->asym_pause = 0;
return 0;
}
static int ksz9031_read_status(struct phy_device *phydev)
{
int err;
int regval;
err = genphy_read_status(phydev);
if (err)
return err;
regval = phy_read(phydev, MII_STAT1000);
if ((regval & 0xFF) == 0xFF) {
phy_init_hw(phydev);
phydev->link = 0;
}
return 0;
}
static int ksz8873mll_config_aneg(struct phy_device *phydev)
{
return 0;
}
static int
ksz9021_rd_mmd_phyreg(struct phy_device *phydev, int ptrad, int devnum,
int regnum)
{
return -1;
}
static void
ksz9021_wr_mmd_phyreg(struct phy_device *phydev, int ptrad, int devnum,
int regnum, u32 val)
{
}
static int kszphy_get_sset_count(struct phy_device *phydev)
{
return ARRAY_SIZE(kszphy_hw_stats);
}
static void kszphy_get_strings(struct phy_device *phydev, u8 *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(kszphy_hw_stats); i++) {
memcpy(data + i * ETH_GSTRING_LEN,
kszphy_hw_stats[i].string, ETH_GSTRING_LEN);
}
}
static u64 kszphy_get_stat(struct phy_device *phydev, int i)
{
struct kszphy_hw_stat stat = kszphy_hw_stats[i];
struct kszphy_priv *priv = phydev->priv;
int val;
u64 ret;
val = phy_read(phydev, stat.reg);
if (val < 0) {
ret = UINT64_MAX;
} else {
val = val & ((1 << stat.bits) - 1);
priv->stats[i] += val;
ret = priv->stats[i];
}
return ret;
}
static void kszphy_get_stats(struct phy_device *phydev,
struct ethtool_stats *stats, u64 *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(kszphy_hw_stats); i++)
data[i] = kszphy_get_stat(phydev, i);
}
static int kszphy_resume(struct phy_device *phydev)
{
int value;
mutex_lock(&phydev->lock);
value = phy_read(phydev, MII_BMCR);
phy_write(phydev, MII_BMCR, value & ~BMCR_PDOWN);
kszphy_config_intr(phydev);
mutex_unlock(&phydev->lock);
return 0;
}
static int kszphy_probe(struct phy_device *phydev)
{
const struct kszphy_type *type = phydev->drv->driver_data;
const struct device_node *np = phydev->mdio.dev.of_node;
struct kszphy_priv *priv;
struct clk *clk;
int ret;
priv = devm_kzalloc(&phydev->mdio.dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
phydev->priv = priv;
priv->type = type;
if (type->led_mode_reg) {
ret = of_property_read_u32(np, "micrel,led-mode",
&priv->led_mode);
if (ret)
priv->led_mode = -1;
if (priv->led_mode > 3) {
phydev_err(phydev, "invalid led mode: 0x%02x\n",
priv->led_mode);
priv->led_mode = -1;
}
} else {
priv->led_mode = -1;
}
clk = devm_clk_get(&phydev->mdio.dev, "rmii-ref");
if (!IS_ERR_OR_NULL(clk)) {
unsigned long rate = clk_get_rate(clk);
bool rmii_ref_clk_sel_25_mhz;
priv->rmii_ref_clk_sel = type->has_rmii_ref_clk_sel;
rmii_ref_clk_sel_25_mhz = of_property_read_bool(np,
"micrel,rmii-reference-clock-select-25-mhz");
if (rate > 24500000 && rate < 25500000) {
priv->rmii_ref_clk_sel_val = rmii_ref_clk_sel_25_mhz;
} else if (rate > 49500000 && rate < 50500000) {
priv->rmii_ref_clk_sel_val = !rmii_ref_clk_sel_25_mhz;
} else {
phydev_err(phydev, "Clock rate out of range: %ld\n",
rate);
return -EINVAL;
}
}
if (phydev->dev_flags & MICREL_PHY_50MHZ_CLK) {
priv->rmii_ref_clk_sel = true;
priv->rmii_ref_clk_sel_val = true;
}
return 0;
}
