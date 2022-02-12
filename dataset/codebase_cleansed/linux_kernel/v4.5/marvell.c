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
err = marvell_set_polarity(phydev, phydev->mdix);
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
if (!phydev->mdio.dev.of_node)
return 0;
paddr = of_get_property(phydev->mdio.dev.of_node,
"marvell,reg-init", &len);
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
static int m88e1510_config_aneg(struct phy_device *phydev)
{
int err;
err = m88e1318_config_aneg(phydev);
if (err < 0)
return err;
return 0;
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
static int marvell_read_status(struct phy_device *phydev)
{
int adv;
int err;
int lpa;
int lpagb;
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
lpagb = phy_read(phydev, MII_STAT1000);
if (lpagb < 0)
return lpagb;
adv = phy_read(phydev, MII_ADVERTISE);
if (adv < 0)
return adv;
phydev->lp_advertising = mii_stat1000_to_ethtool_lpa_t(lpagb) |
mii_lpa_to_ethtool_lpa_t(lpa);
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
phydev->lp_advertising = 0;
}
return 0;
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
return ARRAY_SIZE(marvell_hw_stats);
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
int err, oldpage;
u64 val;
oldpage = phy_read(phydev, MII_MARVELL_PHY_PAGE);
err = phy_write(phydev, MII_MARVELL_PHY_PAGE,
stat.page);
if (err < 0)
return UINT64_MAX;
val = phy_read(phydev, stat.reg);
if (val < 0) {
val = UINT64_MAX;
} else {
val = val & ((1 << stat.bits) - 1);
priv->stats[i] += val;
val = priv->stats[i];
}
phy_write(phydev, MII_MARVELL_PHY_PAGE, oldpage);
return val;
}
static void marvell_get_stats(struct phy_device *phydev,
struct ethtool_stats *stats, u64 *data)
{
int i;
for (i = 0; i < ARRAY_SIZE(marvell_hw_stats); i++)
data[i] = marvell_get_stat(phydev, i);
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
