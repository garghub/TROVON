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
err = phy_write(phydev, MII_M1011_PHY_SCR,
MII_M1011_PHY_SCR_AUTO_CROSS);
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
int len, i, saved_page, current_page, page_changed, ret;
if (!phydev->dev.of_node)
return 0;
paddr = of_get_property(phydev->dev.of_node, "marvell,reg-init", &len);
if (!paddr || len < (4 * sizeof(*paddr)))
return 0;
saved_page = phy_read(phydev, MII_MARVELL_PHY_PAGE);
if (saved_page < 0)
return saved_page;
page_changed = 0;
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
page_changed = 1;
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
if (page_changed) {
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
if ((phydev->interface == PHY_INTERFACE_MODE_RGMII) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_ID) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)) {
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
oldpage = phy_read(phydev, MII_MARVELL_PHY_PAGE);
phy_write(phydev, MII_MARVELL_PHY_PAGE, MII_88E1121_PHY_LED_PAGE);
phy_write(phydev, MII_88E1121_PHY_LED_CTRL, MII_88E1121_PHY_LED_DEF);
phy_write(phydev, MII_MARVELL_PHY_PAGE, oldpage);
err = genphy_config_aneg(phydev);
return err;
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
static int m88e1111_config_init(struct phy_device *phydev)
{
int err;
int temp;
temp = phy_read(phydev, MII_M1111_PHY_EXT_SR);
temp &= ~MII_M1111_HWCFG_FIBER_COPPER_AUTO;
phy_write(phydev, MII_M1111_PHY_EXT_SR, temp);
temp = phy_read(phydev, MII_BMCR);
temp |= BMCR_RESET;
phy_write(phydev, MII_BMCR, temp);
if ((phydev->interface == PHY_INTERFACE_MODE_RGMII) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_ID) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)) {
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
err = marvell_of_reg_init(phydev);
if (err < 0)
return err;
return 0;
}
static int marvell_read_status(struct phy_device *phydev)
{
int adv;
int err;
int lpa;
int status = 0;
err = genphy_update_link(phydev);
if (err)
return err;
if (AUTONEG_ENABLE == phydev->autoneg) {
status = phy_read(phydev, MII_M1011_PHY_STATUS);
if (status < 0)
return status;
lpa = phy_read(phydev, MII_LPA);
if (lpa < 0)
return lpa;
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
if (phydev->duplex == DUPLEX_FULL) {
phydev->pause = lpa & LPA_PAUSE_CAP ? 1 : 0;
phydev->asym_pause = lpa & LPA_PAUSE_ASYM ? 1 : 0;
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
}
return 0;
}
static int m88e1121_did_interrupt(struct phy_device *phydev)
{
int imask;
imask = phy_read(phydev, MII_M1011_IEVENT);
if (imask & MII_M1011_IMASK_INIT)
return 1;
return 0;
}
static int __init marvell_init(void)
{
return phy_drivers_register(marvell_drivers,
ARRAY_SIZE(marvell_drivers));
}
static void __exit marvell_exit(void)
{
phy_drivers_unregister(marvell_drivers,
ARRAY_SIZE(marvell_drivers));
}
