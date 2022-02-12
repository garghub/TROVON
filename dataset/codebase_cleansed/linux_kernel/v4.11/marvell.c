static int marvell_ack_interrupt(struct phy_device *phydev)
{
int err;
err = phy_read(phydev, MII_M1011_IEVENT);
if (err < 0)
return err;
return 0;
}
static int marvell_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, MII_M1011_IMASK, MII_M1011_IMASK_INIT);
else
err = phy_write(phydev, MII_M1011_IMASK, MII_M1011_IMASK_CLEAR);
return err;
}
static int marvell_set_polarity(struct phy_device *phydev, int polarity)
{
int reg;
int err;
int val;
reg = phy_read(phydev, MII_M1011_PHY_SCR);
if (reg < 0)
return reg;
val = reg;
val &= ~MII_M1011_PHY_SCR_AUTO_CROSS;
switch (polarity) {
case ETH_TP_MDI:
val |= MII_M1011_PHY_SCR_MDI;
break;
case ETH_TP_MDI_X:
val |= MII_M1011_PHY_SCR_MDI_X;
break;
case ETH_TP_MDI_AUTO:
case ETH_TP_MDI_INVALID:
default:
val |= MII_M1011_PHY_SCR_AUTO_CROSS;
break;
}
if (val != reg) {
err = phy_write(phydev, MII_M1011_PHY_SCR, val);
if (err)
return err;
}
return 0;
}
static int marvell_config_aneg(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_BMCR, BMCR_RESET);
if (err < 0)
return err;
err = phy_write(phydev, 0x1d, 0x1f);
if (err < 0)
return err;
err = phy_write(phydev, 0x1e, 0x200c);
if (err < 0)
return err;
err = phy_write(phydev, 0x1d, 0x5);
if (err < 0)
return err;
err = phy_write(phydev, 0x1e, 0);
if (err < 0)
return err;
err = phy_write(phydev, 0x1e, 0x100);
if (err < 0)
return err;
err = marvell_set_polarity(phydev, phydev->mdix_ctrl);
if (err < 0)
return err;
err = phy_write(phydev, MII_M1111_PHY_LED_CONTROL,
MII_M1111_PHY_LED_DIRECT);
if (err < 0)
return err;
err = genphy_config_aneg(phydev);
if (err < 0)
return err;
if (phydev->autoneg != AUTONEG_ENABLE) {
int bmcr;
bmcr = phy_read(phydev, MII_BMCR);
if (bmcr < 0)
return bmcr;
err = phy_write(phydev, MII_BMCR, bmcr | BMCR_RESET);
if (err < 0)
return err;
}
return 0;
}
static int m88e1111_config_aneg(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_BMCR, BMCR_RESET);
err = marvell_set_polarity(phydev, phydev->mdix_ctrl);
if (err < 0)
return err;
err = phy_write(phydev, MII_M1111_PHY_LED_CONTROL,
MII_M1111_PHY_LED_DIRECT);
if (err < 0)
return err;
err = genphy_config_aneg(phydev);
if (err < 0)
return err;
if (phydev->autoneg != AUTONEG_ENABLE) {
int bmcr;
bmcr = phy_read(phydev, MII_BMCR);
if (bmcr < 0)
return bmcr;
err = phy_write(phydev, MII_BMCR, bmcr | BMCR_RESET);
if (err < 0)
return err;
}
return 0;
}
static int marvell_of_reg_init(struct phy_device *phydev)
{
const __be32 *paddr;
int len, i, saved_page, current_page, ret;
if (!phydev->mdio.dev.of_node)
return 0;
paddr = of_get_property(phydev->mdio.dev.of_node,
"marvell,reg-init", &len);
if (!paddr || len < (4 * sizeof(*paddr)))
return 0;
saved_page = phy_read(phydev, MII_MARVELL_PHY_PAGE);
if (saved_page < 0)
return saved_page;
current_page = saved_page;
ret = 0;
len /= sizeof(*paddr);
for (i = 0; i < len - 3; i += 4) {
u16 reg_page = be32_to_cpup(paddr + i);
u16 reg = be32_to_cpup(paddr + i + 1);
u16 mask = be32_to_cpup(paddr + i + 2);
u16 val_bits = be32_to_cpup(paddr + i + 3);
int val;
if (reg_page != current_page) {
current_page = reg_page;
ret = phy_write(phydev, MII_MARVELL_PHY_PAGE, reg_page);
if (ret < 0)
goto err;
}
val = 0;
if (mask) {
val = phy_read(phydev, reg);
if (val < 0) {
ret = val;
goto err;
}
val &= mask;
}
val |= val_bits;
ret = phy_write(phydev, reg, val);
if (ret < 0)
goto err;
}
err:
if (current_page != saved_page) {
i = phy_write(phydev, MII_MARVELL_PHY_PAGE, saved_page);
if (ret == 0)
ret = i;
}
return ret;
}
static int marvell_of_reg_init(struct phy_device *phydev)
{
return 0;
}
static int m88e1121_config_aneg(struct phy_device *phydev)
{
int err, oldpage, mscr;
oldpage = phy_read(phydev, MII_MARVELL_PHY_PAGE);
err = phy_write(phydev, MII_MARVELL_PHY_PAGE,
MII_88E1121_PHY_MSCR_PAGE);
if (err < 0)
return err;
if (phy_interface_is_rgmii(phydev)) {
mscr = phy_read(phydev, MII_88E1121_PHY_MSCR_REG) &
MII_88E1121_PHY_MSCR_DELAY_MASK;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
mscr |= (MII_88E1121_PHY_MSCR_RX_DELAY |
MII_88E1121_PHY_MSCR_TX_DELAY);
else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID)
mscr |= MII_88E1121_PHY_MSCR_RX_DELAY;
else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)
mscr |= MII_88E1121_PHY_MSCR_TX_DELAY;
err = phy_write(phydev, MII_88E1121_PHY_MSCR_REG, mscr);
if (err < 0)
return err;
}
phy_write(phydev, MII_MARVELL_PHY_PAGE, oldpage);
err = phy_write(phydev, MII_BMCR, BMCR_RESET);
if (err < 0)
return err;
err = phy_write(phydev, MII_M1011_PHY_SCR,
MII_M1011_PHY_SCR_AUTO_CROSS);
if (err < 0)
return err;
return genphy_config_aneg(phydev);
}
static int m88e1318_config_aneg(struct phy_device *phydev)
{
int err, oldpage, mscr;
oldpage = phy_read(phydev, MII_MARVELL_PHY_PAGE);
err = phy_write(phydev, MII_MARVELL_PHY_PAGE,
MII_88E1121_PHY_MSCR_PAGE);
if (err < 0)
return err;
mscr = phy_read(phydev, MII_88E1318S_PHY_MSCR1_REG);
mscr |= MII_88E1318S_PHY_MSCR1_PAD_ODD;
err = phy_write(phydev, MII_88E1318S_PHY_MSCR1_REG, mscr);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, oldpage);
if (err < 0)
return err;
return m88e1121_config_aneg(phydev);
}
static inline u32 ethtool_adv_to_fiber_adv_t(u32 ethadv)
{
u32 result = 0;
if (ethadv & ADVERTISED_1000baseT_Half)
result |= ADVERTISE_FIBER_1000HALF;
if (ethadv & ADVERTISED_1000baseT_Full)
result |= ADVERTISE_FIBER_1000FULL;
if ((ethadv & ADVERTISE_PAUSE_ASYM) && (ethadv & ADVERTISE_PAUSE_CAP))
result |= LPA_PAUSE_ASYM_FIBER;
else if (ethadv & ADVERTISE_PAUSE_CAP)
result |= (ADVERTISE_PAUSE_FIBER
& (~ADVERTISE_PAUSE_ASYM_FIBER));
return result;
}
static int marvell_config_aneg_fiber(struct phy_device *phydev)
{
int changed = 0;
int err;
int adv, oldadv;
u32 advertise;
if (phydev->autoneg != AUTONEG_ENABLE)
return genphy_setup_forced(phydev);
phydev->advertising &= phydev->supported;
advertise = phydev->advertising;
adv = phy_read(phydev, MII_ADVERTISE);
if (adv < 0)
return adv;
oldadv = adv;
adv &= ~(ADVERTISE_FIBER_1000HALF | ADVERTISE_FIBER_1000FULL
| LPA_PAUSE_FIBER);
adv |= ethtool_adv_to_fiber_adv_t(advertise);
if (adv != oldadv) {
err = phy_write(phydev, MII_ADVERTISE, adv);
if (err < 0)
return err;
changed = 1;
}
if (changed == 0) {
int ctl = phy_read(phydev, MII_BMCR);
if (ctl < 0)
return ctl;
if (!(ctl & BMCR_ANENABLE) || (ctl & BMCR_ISOLATE))
changed = 1;
}
if (changed > 0)
changed = genphy_restart_aneg(phydev);
return changed;
}
static int m88e1510_config_aneg(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
if (err < 0)
goto error;
err = m88e1318_config_aneg(phydev);
if (err < 0)
goto error;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_FIBER);
if (err < 0)
goto error;
err = marvell_config_aneg_fiber(phydev);
if (err < 0)
goto error;
return phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
error:
phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
return err;
}
static int marvell_config_init(struct phy_device *phydev)
{
return marvell_of_reg_init(phydev);
}
static int m88e1116r_config_init(struct phy_device *phydev)
{
int temp;
int err;
temp = phy_read(phydev, MII_BMCR);
temp |= BMCR_RESET;
err = phy_write(phydev, MII_BMCR, temp);
if (err < 0)
return err;
mdelay(500);
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0);
if (err < 0)
return err;
temp = phy_read(phydev, MII_M1011_PHY_SCR);
temp |= (7 << 12);
temp |= (1 << 11);
temp |= MII_M1011_PHY_SCR_AUTO_CROSS;
err = phy_write(phydev, MII_M1011_PHY_SCR, temp);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 2);
if (err < 0)
return err;
temp = phy_read(phydev, MII_M1116R_CONTROL_REG_MAC);
temp |= (1 << 5);
temp |= (1 << 4);
err = phy_write(phydev, MII_M1116R_CONTROL_REG_MAC, temp);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0);
if (err < 0)
return err;
temp = phy_read(phydev, MII_BMCR);
temp |= BMCR_RESET;
err = phy_write(phydev, MII_BMCR, temp);
if (err < 0)
return err;
mdelay(500);
return marvell_config_init(phydev);
}
static int m88e3016_config_init(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_88E3016_PHY_SPEC_CTRL);
if (reg < 0)
return reg;
reg &= ~MII_88E3016_DISABLE_SCRAMBLER;
reg |= MII_88E3016_AUTO_MDIX_CROSSOVER;
reg = phy_write(phydev, MII_88E3016_PHY_SPEC_CTRL, reg);
if (reg < 0)
return reg;
return marvell_config_init(phydev);
}
static int m88e1111_config_init(struct phy_device *phydev)
{
int err;
int temp;
if (phy_interface_is_rgmii(phydev)) {
temp = phy_read(phydev, MII_M1111_PHY_EXT_CR);
if (temp < 0)
return temp;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID) {
temp |= (MII_M1111_RX_DELAY | MII_M1111_TX_DELAY);
} else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID) {
temp &= ~MII_M1111_TX_DELAY;
temp |= MII_M1111_RX_DELAY;
} else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID) {
temp &= ~MII_M1111_RX_DELAY;
temp |= MII_M1111_TX_DELAY;
}
err = phy_write(phydev, MII_M1111_PHY_EXT_CR, temp);
if (err < 0)
return err;
temp = phy_read(phydev, MII_M1111_PHY_EXT_SR);
if (temp < 0)
return temp;
temp &= ~(MII_M1111_HWCFG_MODE_MASK);
if (temp & MII_M1111_HWCFG_FIBER_COPPER_RES)
temp |= MII_M1111_HWCFG_MODE_FIBER_RGMII;
else
temp |= MII_M1111_HWCFG_MODE_COPPER_RGMII;
err = phy_write(phydev, MII_M1111_PHY_EXT_SR, temp);
if (err < 0)
return err;
}
if (phydev->interface == PHY_INTERFACE_MODE_SGMII) {
temp = phy_read(phydev, MII_M1111_PHY_EXT_SR);
if (temp < 0)
return temp;
temp &= ~(MII_M1111_HWCFG_MODE_MASK);
temp |= MII_M1111_HWCFG_MODE_SGMII_NO_CLK;
temp |= MII_M1111_HWCFG_FIBER_COPPER_AUTO;
err = phy_write(phydev, MII_M1111_PHY_EXT_SR, temp);
if (err < 0)
return err;
err = phy_read(phydev, MII_M1145_PHY_EXT_ADDR_PAGE);
if (err < 0)
return err;
err = phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE,
err & (~0xff));
if (err < 0)
return err;
}
if (phydev->interface == PHY_INTERFACE_MODE_RTBI) {
temp = phy_read(phydev, MII_M1111_PHY_EXT_CR);
if (temp < 0)
return temp;
temp |= (MII_M1111_RX_DELAY | MII_M1111_TX_DELAY);
err = phy_write(phydev, MII_M1111_PHY_EXT_CR, temp);
if (err < 0)
return err;
temp = phy_read(phydev, MII_M1111_PHY_EXT_SR);
if (temp < 0)
return temp;
temp &= ~(MII_M1111_HWCFG_MODE_MASK | MII_M1111_HWCFG_FIBER_COPPER_RES);
temp |= 0x7 | MII_M1111_HWCFG_FIBER_COPPER_AUTO;
err = phy_write(phydev, MII_M1111_PHY_EXT_SR, temp);
if (err < 0)
return err;
err = phy_write(phydev, MII_BMCR, BMCR_RESET);
if (err < 0)
return err;
do
temp = phy_read(phydev, MII_BMCR);
while (temp & BMCR_RESET);
temp = phy_read(phydev, MII_M1111_PHY_EXT_SR);
if (temp < 0)
return temp;
temp &= ~(MII_M1111_HWCFG_MODE_MASK | MII_M1111_HWCFG_FIBER_COPPER_RES);
temp |= MII_M1111_HWCFG_MODE_COPPER_RTBI | MII_M1111_HWCFG_FIBER_COPPER_AUTO;
err = phy_write(phydev, MII_M1111_PHY_EXT_SR, temp);
if (err < 0)
return err;
}
err = marvell_of_reg_init(phydev);
if (err < 0)
return err;
return phy_write(phydev, MII_BMCR, BMCR_RESET);
}
static int m88e1121_config_init(struct phy_device *phydev)
{
int err, oldpage;
oldpage = phy_read(phydev, MII_MARVELL_PHY_PAGE);
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_88E1121_PHY_LED_PAGE);
if (err < 0)
return err;
err = phy_write(phydev, MII_88E1121_PHY_LED_CTRL,
MII_88E1121_PHY_LED_DEF);
if (err < 0)
return err;
phy_write(phydev, MII_MARVELL_PHY_PAGE, oldpage);
return marvell_config_init(phydev);
}
static int m88e1510_config_init(struct phy_device *phydev)
{
int err;
int temp;
if (phydev->interface == PHY_INTERFACE_MODE_SGMII) {
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 18);
if (err < 0)
return err;
temp = phy_read(phydev, MII_88E1510_GEN_CTRL_REG_1);
temp &= ~MII_88E1510_GEN_CTRL_REG_1_MODE_MASK;
temp |= MII_88E1510_GEN_CTRL_REG_1_MODE_SGMII;
err = phy_write(phydev, MII_88E1510_GEN_CTRL_REG_1, temp);
if (err < 0)
return err;
temp |= MII_88E1510_GEN_CTRL_REG_1_RESET;
err = phy_write(phydev, MII_88E1510_GEN_CTRL_REG_1, temp);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0);
if (err < 0)
return err;
}
return m88e1121_config_init(phydev);
}
static int m88e1118_config_aneg(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_BMCR, BMCR_RESET);
if (err < 0)
return err;
err = phy_write(phydev, MII_M1011_PHY_SCR,
MII_M1011_PHY_SCR_AUTO_CROSS);
if (err < 0)
return err;
err = genphy_config_aneg(phydev);
return 0;
}
static int m88e1118_config_init(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0x0002);
if (err < 0)
return err;
err = phy_write(phydev, 0x15, 0x1070);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0x0003);
if (err < 0)
return err;
if (phydev->dev_flags & MARVELL_PHY_M1118_DNS323_LEDS)
err = phy_write(phydev, 0x10, 0x1100);
else
err = phy_write(phydev, 0x10, 0x021e);
if (err < 0)
return err;
err = marvell_of_reg_init(phydev);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0x0);
if (err < 0)
return err;
return phy_write(phydev, MII_BMCR, BMCR_RESET);
}
static int m88e1149_config_init(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0x0002);
if (err < 0)
return err;
err = phy_write(phydev, 0x15, 0x1048);
if (err < 0)
return err;
err = marvell_of_reg_init(phydev);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0x0);
if (err < 0)
return err;
return phy_write(phydev, MII_BMCR, BMCR_RESET);
}
static int m88e1145_config_init(struct phy_device *phydev)
{
int err;
int temp;
err = phy_write(phydev, 0x1d, 0x001b);
if (err < 0)
return err;
err = phy_write(phydev, 0x1e, 0x418f);
if (err < 0)
return err;
err = phy_write(phydev, 0x1d, 0x0016);
if (err < 0)
return err;
err = phy_write(phydev, 0x1e, 0xa2da);
if (err < 0)
return err;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID) {
int temp = phy_read(phydev, MII_M1145_PHY_EXT_CR);
if (temp < 0)
return temp;
temp |= (MII_M1145_RGMII_RX_DELAY | MII_M1145_RGMII_TX_DELAY);
err = phy_write(phydev, MII_M1145_PHY_EXT_CR, temp);
if (err < 0)
return err;
if (phydev->dev_flags & MARVELL_PHY_M1145_FLAGS_RESISTANCE) {
err = phy_write(phydev, 0x1d, 0x0012);
if (err < 0)
return err;
temp = phy_read(phydev, 0x1e);
if (temp < 0)
return temp;
temp &= 0xf03f;
temp |= 2 << 9;
temp |= 2 << 6;
err = phy_write(phydev, 0x1e, temp);
if (err < 0)
return err;
err = phy_write(phydev, 0x1d, 0x3);
if (err < 0)
return err;
err = phy_write(phydev, 0x1e, 0x8000);
if (err < 0)
return err;
}
}
if (phydev->interface == PHY_INTERFACE_MODE_SGMII) {
temp = phy_read(phydev, MII_M1145_PHY_EXT_SR);
if (temp < 0)
return temp;
temp &= ~MII_M1145_HWCFG_MODE_MASK;
temp |= MII_M1145_HWCFG_MODE_SGMII_NO_CLK;
temp |= MII_M1145_HWCFG_FIBER_COPPER_AUTO;
err = phy_write(phydev, MII_M1145_PHY_EXT_SR, temp);
if (err < 0)
return err;
}
err = marvell_of_reg_init(phydev);
if (err < 0)
return err;
return 0;
}
static u32 fiber_lpa_to_ethtool_lpa_t(u32 lpa)
{
u32 result = 0;
if (lpa & LPA_FIBER_1000HALF)
result |= ADVERTISED_1000baseT_Half;
if (lpa & LPA_FIBER_1000FULL)
result |= ADVERTISED_1000baseT_Full;
return result;
}
static int marvell_update_link(struct phy_device *phydev, int fiber)
{
int status;
if (fiber) {
status = phy_read(phydev, MII_M1011_PHY_STATUS);
if (status < 0)
return status;
if ((status & REGISTER_LINK_STATUS) == 0)
phydev->link = 0;
else
phydev->link = 1;
} else {
return genphy_update_link(phydev);
}
return 0;
}
static int marvell_read_status_page(struct phy_device *phydev, int page)
{
int adv;
int err;
int lpa;
int lpagb;
int status = 0;
int fiber;
if (page == MII_M1111_FIBER)
fiber = 1;
else
fiber = 0;
err = marvell_update_link(phydev, fiber);
if (err)
return err;
if (AUTONEG_ENABLE == phydev->autoneg) {
status = phy_read(phydev, MII_M1011_PHY_STATUS);
if (status < 0)
return status;
lpa = phy_read(phydev, MII_LPA);
if (lpa < 0)
return lpa;
lpagb = phy_read(phydev, MII_STAT1000);
if (lpagb < 0)
return lpagb;
adv = phy_read(phydev, MII_ADVERTISE);
if (adv < 0)
return adv;
lpa &= adv;
if (status & MII_M1011_PHY_STATUS_FULLDUPLEX)
phydev->duplex = DUPLEX_FULL;
else
phydev->duplex = DUPLEX_HALF;
status = status & MII_M1011_PHY_STATUS_SPD_MASK;
phydev->pause = phydev->asym_pause = 0;
switch (status) {
case MII_M1011_PHY_STATUS_1000:
phydev->speed = SPEED_1000;
break;
case MII_M1011_PHY_STATUS_100:
phydev->speed = SPEED_100;
break;
default:
phydev->speed = SPEED_10;
break;
}
if (!fiber) {
phydev->lp_advertising = mii_stat1000_to_ethtool_lpa_t(lpagb) |
mii_lpa_to_ethtool_lpa_t(lpa);
if (phydev->duplex == DUPLEX_FULL) {
phydev->pause = lpa & LPA_PAUSE_CAP ? 1 : 0;
phydev->asym_pause = lpa & LPA_PAUSE_ASYM ? 1 : 0;
}
} else {
phydev->lp_advertising = fiber_lpa_to_ethtool_lpa_t(lpa);
if (phydev->duplex == DUPLEX_FULL) {
if (!(lpa & LPA_PAUSE_FIBER)) {
phydev->pause = 0;
phydev->asym_pause = 0;
} else if ((lpa & LPA_PAUSE_ASYM_FIBER)) {
phydev->pause = 1;
phydev->asym_pause = 1;
} else {
phydev->pause = 1;
phydev->asym_pause = 0;
}
}
}
} else {
int bmcr = phy_read(phydev, MII_BMCR);
if (bmcr < 0)
return bmcr;
if (bmcr & BMCR_FULLDPLX)
phydev->duplex = DUPLEX_FULL;
else
phydev->duplex = DUPLEX_HALF;
if (bmcr & BMCR_SPEED1000)
phydev->speed = SPEED_1000;
else if (bmcr & BMCR_SPEED100)
phydev->speed = SPEED_100;
else
phydev->speed = SPEED_10;
phydev->pause = phydev->asym_pause = 0;
phydev->lp_advertising = 0;
}
return 0;
}
static int marvell_read_status(struct phy_device *phydev)
{
int err;
if (phydev->supported & SUPPORTED_FIBRE &&
phydev->interface != PHY_INTERFACE_MODE_SGMII) {
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_FIBER);
if (err < 0)
goto error;
err = marvell_read_status_page(phydev, MII_M1111_FIBER);
if (err < 0)
goto error;
if (phydev->link)
return 0;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
if (err < 0)
goto error;
}
return marvell_read_status_page(phydev, MII_M1111_COPPER);
error:
phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
return err;
}
static int marvell_suspend(struct phy_device *phydev)
{
int err;
if (!(phydev->supported & SUPPORTED_FIBRE)) {
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_FIBER);
if (err < 0)
goto error;
err = genphy_suspend(phydev);
if (err < 0)
goto error;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
if (err < 0)
goto error;
}
return genphy_suspend(phydev);
error:
phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
return err;
}
static int marvell_resume(struct phy_device *phydev)
{
int err;
if (!(phydev->supported & SUPPORTED_FIBRE)) {
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_FIBER);
if (err < 0)
goto error;
err = genphy_resume(phydev);
if (err < 0)
goto error;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
if (err < 0)
goto error;
}
return genphy_resume(phydev);
error:
phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_M1111_COPPER);
return err;
}
static int marvell_aneg_done(struct phy_device *phydev)
{
int retval = phy_read(phydev, MII_M1011_PHY_STATUS);
return (retval < 0) ? retval : (retval & MII_M1011_PHY_STATUS_RESOLVED);
}
static int m88e1121_did_interrupt(struct phy_device *phydev)
{
int imask;
imask = phy_read(phydev, MII_M1011_IEVENT);
if (imask & MII_M1011_IMASK_INIT)
return 1;
return 0;
}
static void m88e1318_get_wol(struct phy_device *phydev, struct ethtool_wolinfo *wol)
{
wol->supported = WAKE_MAGIC;
wol->wolopts = 0;
if (phy_write(phydev, MII_MARVELL_PHY_PAGE,
MII_88E1318S_PHY_WOL_PAGE) < 0)
return;
if (phy_read(phydev, MII_88E1318S_PHY_WOL_CTRL) &
MII_88E1318S_PHY_WOL_CTRL_MAGIC_PACKET_MATCH_ENABLE)
wol->wolopts |= WAKE_MAGIC;
if (phy_write(phydev, MII_MARVELL_PHY_PAGE, 0x00) < 0)
return;
}
static int m88e1318_set_wol(struct phy_device *phydev, struct ethtool_wolinfo *wol)
{
int err, oldpage, temp;
oldpage = phy_read(phydev, MII_MARVELL_PHY_PAGE);
if (wol->wolopts & WAKE_MAGIC) {
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, 0x00);
if (err < 0)
return err;
temp = phy_read(phydev, MII_88E1318S_PHY_CSIER);
temp |= MII_88E1318S_PHY_CSIER_WOL_EIE;
err = phy_write(phydev, MII_88E1318S_PHY_CSIER, temp);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE,
MII_88E1318S_PHY_LED_PAGE);
if (err < 0)
return err;
temp = phy_read(phydev, MII_88E1318S_PHY_LED_TCR);
temp &= ~MII_88E1318S_PHY_LED_TCR_FORCE_INT;
temp |= MII_88E1318S_PHY_LED_TCR_INTn_ENABLE;
temp |= MII_88E1318S_PHY_LED_TCR_INT_ACTIVE_LOW;
err = phy_write(phydev, MII_88E1318S_PHY_LED_TCR, temp);
if (err < 0)
return err;
err = phy_write(phydev, MII_MARVELL_PHY_PAGE,
MII_88E1318S_PHY_WOL_PAGE);
if (err < 0)
return err;
err = phy_write(phydev, MII_88E1318S_PHY_MAGIC_PACKET_WORD2,
((phydev->attached_dev->dev_addr[5] << 8) |
phydev->attached_dev->dev_addr[4]));
if (err < 0)
return err;
err = phy_write(phydev, MII_88E1318S_PHY_MAGIC_PACKET_WORD1,
((phydev->attached_dev->dev_addr[3] << 8) |
phydev->attached_dev->dev_addr[2]));
if (err < 0)
return err;
err = phy_write(phydev, MII_88E1318S_PHY_MAGIC_PACKET_WORD0,
((phydev->attached_dev->dev_addr[1] << 8) |
phydev->attached_dev->dev_addr[0]));
if (err < 0)
return err;
temp = phy_read(phydev, MII_88E1318S_PHY_WOL_CTRL);
temp |= MII_88E1318S_PHY_WOL_CTRL_CLEAR_WOL_STATUS;
temp |= MII_88E1318S_PHY_WOL_CTRL_MAGIC_PACKET_MATCH_ENABLE;
err = phy_write(phydev, MII_88E1318S_PHY_WOL_CTRL, temp);
if (err < 0)
return err;
} else {
err = phy_write(phydev, MII_MARVELL_PHY_PAGE,
MII_88E1318S_PHY_WOL_PAGE);
if (err < 0)
return err;
temp = phy_read(phydev, MII_88E1318S_PHY_WOL_CTRL);
temp |= MII_88E1318S_PHY_WOL_CTRL_CLEAR_WOL_STATUS;
temp &= ~MII_88E1318S_PHY_WOL_CTRL_MAGIC_PACKET_MATCH_ENABLE;
err = phy_write(phydev, MII_88E1318S_PHY_WOL_CTRL, temp);
if (err < 0)
return err;
}
err = phy_write(phydev, MII_MARVELL_PHY_PAGE, oldpage);
if (err < 0)
return err;
return 0;
}
static int marvell_get_sset_count(struct phy_device *phydev)
{
if (phydev->supported & SUPPORTED_FIBRE)
return ARRAY_SIZE(marvell_hw_stats);
else
return ARRAY_SIZE(marvell_hw_stats) - NB_FIBER_STATS;
}
static void marvell_get_strings(struct phy_device *phydev, u8 *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(marvell_hw_stats); i++) {
memcpy(data + i * ETH_GSTRING_LEN,
marvell_hw_stats[i].string, ETH_GSTRING_LEN);
}
}
static u64 marvell_get_stat(struct phy_device *phydev, int i)
{
struct marvell_hw_stat stat = marvell_hw_stats[i];
struct marvell_priv *priv = phydev->priv;
int err, oldpage, val;
u64 ret;
oldpage = phy_read(phydev, MII_MARVELL_PHY_PAGE);
err = phy_write(phydev, MII_MARVELL_PHY_PAGE,
stat.page);
if (err < 0)
return UINT64_MAX;
val = phy_read(phydev, stat.reg);
if (val < 0) {
ret = UINT64_MAX;
} else {
val = val & ((1 << stat.bits) - 1);
priv->stats[i] += val;
ret = priv->stats[i];
}
phy_write(phydev, MII_MARVELL_PHY_PAGE, oldpage);
return ret;
}
static void marvell_get_stats(struct phy_device *phydev,
struct ethtool_stats *stats, u64 *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(marvell_hw_stats); i++)
data[i] = marvell_get_stat(phydev, i);
}
static int m88e1121_get_temp(struct phy_device *phydev, long *temp)
{
int ret;
int val;
*temp = 0;
mutex_lock(&phydev->lock);
ret = phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x6);
if (ret < 0)
goto error;
ret = phy_read(phydev, MII_88E1121_MISC_TEST);
if (ret < 0)
goto error;
ret = phy_write(phydev, MII_88E1121_MISC_TEST,
ret | MII_88E1121_MISC_TEST_TEMP_SENSOR_EN);
if (ret < 0)
goto error;
usleep_range(10000, 12000);
val = phy_read(phydev, MII_88E1121_MISC_TEST);
if (val < 0) {
ret = val;
goto error;
}
ret = phy_write(phydev, MII_88E1121_MISC_TEST,
ret & ~MII_88E1121_MISC_TEST_TEMP_SENSOR_EN);
if (ret < 0)
goto error;
*temp = ((val & MII_88E1121_MISC_TEST_TEMP_MASK) - 5) * 5000;
error:
phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x0);
mutex_unlock(&phydev->lock);
return ret;
}
static int m88e1121_hwmon_read(struct device *dev,
enum hwmon_sensor_types type,
u32 attr, int channel, long *temp)
{
struct phy_device *phydev = dev_get_drvdata(dev);
int err;
switch (attr) {
case hwmon_temp_input:
err = m88e1121_get_temp(phydev, temp);
break;
default:
return -EOPNOTSUPP;
}
return err;
}
static umode_t m88e1121_hwmon_is_visible(const void *data,
enum hwmon_sensor_types type,
u32 attr, int channel)
{
if (type != hwmon_temp)
return 0;
switch (attr) {
case hwmon_temp_input:
return 0444;
default:
return 0;
}
}
static int m88e1510_get_temp(struct phy_device *phydev, long *temp)
{
int ret;
*temp = 0;
mutex_lock(&phydev->lock);
ret = phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x6);
if (ret < 0)
goto error;
ret = phy_read(phydev, MII_88E1510_TEMP_SENSOR);
if (ret < 0)
goto error;
*temp = ((ret & MII_88E1510_TEMP_SENSOR_MASK) - 25) * 1000;
error:
phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x0);
mutex_unlock(&phydev->lock);
return ret;
}
int m88e1510_get_temp_critical(struct phy_device *phydev, long *temp)
{
int ret;
*temp = 0;
mutex_lock(&phydev->lock);
ret = phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x6);
if (ret < 0)
goto error;
ret = phy_read(phydev, MII_88E1121_MISC_TEST);
if (ret < 0)
goto error;
*temp = (((ret & MII_88E1510_MISC_TEST_TEMP_THRESHOLD_MASK) >>
MII_88E1510_MISC_TEST_TEMP_THRESHOLD_SHIFT) * 5) - 25;
*temp *= 1000;
error:
phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x0);
mutex_unlock(&phydev->lock);
return ret;
}
int m88e1510_set_temp_critical(struct phy_device *phydev, long temp)
{
int ret;
mutex_lock(&phydev->lock);
ret = phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x6);
if (ret < 0)
goto error;
ret = phy_read(phydev, MII_88E1121_MISC_TEST);
if (ret < 0)
goto error;
temp = temp / 1000;
temp = clamp_val(DIV_ROUND_CLOSEST(temp, 5) + 5, 0, 0x1f);
ret = phy_write(phydev, MII_88E1121_MISC_TEST,
(ret & ~MII_88E1510_MISC_TEST_TEMP_THRESHOLD_MASK) |
(temp << MII_88E1510_MISC_TEST_TEMP_THRESHOLD_SHIFT));
error:
phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x0);
mutex_unlock(&phydev->lock);
return ret;
}
int m88e1510_get_temp_alarm(struct phy_device *phydev, long *alarm)
{
int ret;
*alarm = false;
mutex_lock(&phydev->lock);
ret = phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x6);
if (ret < 0)
goto error;
ret = phy_read(phydev, MII_88E1121_MISC_TEST);
if (ret < 0)
goto error;
*alarm = !!(ret & MII_88E1510_MISC_TEST_TEMP_IRQ);
error:
phy_write(phydev, MII_M1145_PHY_EXT_ADDR_PAGE, 0x0);
mutex_unlock(&phydev->lock);
return ret;
}
static int m88e1510_hwmon_read(struct device *dev,
enum hwmon_sensor_types type,
u32 attr, int channel, long *temp)
{
struct phy_device *phydev = dev_get_drvdata(dev);
int err;
switch (attr) {
case hwmon_temp_input:
err = m88e1510_get_temp(phydev, temp);
break;
case hwmon_temp_crit:
err = m88e1510_get_temp_critical(phydev, temp);
break;
case hwmon_temp_max_alarm:
err = m88e1510_get_temp_alarm(phydev, temp);
break;
default:
return -EOPNOTSUPP;
}
return err;
}
static int m88e1510_hwmon_write(struct device *dev,
enum hwmon_sensor_types type,
u32 attr, int channel, long temp)
{
struct phy_device *phydev = dev_get_drvdata(dev);
int err;
switch (attr) {
case hwmon_temp_crit:
err = m88e1510_set_temp_critical(phydev, temp);
break;
default:
return -EOPNOTSUPP;
}
return err;
}
static umode_t m88e1510_hwmon_is_visible(const void *data,
enum hwmon_sensor_types type,
u32 attr, int channel)
{
if (type != hwmon_temp)
return 0;
switch (attr) {
case hwmon_temp_input:
case hwmon_temp_max_alarm:
return 0444;
case hwmon_temp_crit:
return 0644;
default:
return 0;
}
}
static int marvell_hwmon_name(struct phy_device *phydev)
{
struct marvell_priv *priv = phydev->priv;
struct device *dev = &phydev->mdio.dev;
const char *devname = dev_name(dev);
size_t len = strlen(devname);
int i, j;
priv->hwmon_name = devm_kzalloc(dev, len, GFP_KERNEL);
if (!priv->hwmon_name)
return -ENOMEM;
for (i = j = 0; i < len && devname[i]; i++) {
if (isalnum(devname[i]))
priv->hwmon_name[j++] = devname[i];
}
return 0;
}
static int marvell_hwmon_probe(struct phy_device *phydev,
const struct hwmon_chip_info *chip)
{
struct marvell_priv *priv = phydev->priv;
struct device *dev = &phydev->mdio.dev;
int err;
err = marvell_hwmon_name(phydev);
if (err)
return err;
priv->hwmon_dev = devm_hwmon_device_register_with_info(
dev, priv->hwmon_name, phydev, chip, NULL);
return PTR_ERR_OR_ZERO(priv->hwmon_dev);
}
static int m88e1121_hwmon_probe(struct phy_device *phydev)
{
return marvell_hwmon_probe(phydev, &m88e1121_hwmon_chip_info);
}
static int m88e1510_hwmon_probe(struct phy_device *phydev)
{
return marvell_hwmon_probe(phydev, &m88e1510_hwmon_chip_info);
}
static int m88e1121_hwmon_probe(struct phy_device *phydev)
{
return 0;
}
static int m88e1510_hwmon_probe(struct phy_device *phydev)
{
return 0;
}
static int marvell_probe(struct phy_device *phydev)
{
struct marvell_priv *priv;
priv = devm_kzalloc(&phydev->mdio.dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
phydev->priv = priv;
return 0;
}
static int m88e1121_probe(struct phy_device *phydev)
{
int err;
err = marvell_probe(phydev);
if (err)
return err;
return m88e1121_hwmon_probe(phydev);
}
static int m88e1510_probe(struct phy_device *phydev)
{
int err;
err = marvell_probe(phydev);
if (err)
return err;
return m88e1510_hwmon_probe(phydev);
}
