static int vsc8211_reset(struct cphy *cphy, int wait)
{
return t3_phy_reset(cphy, MDIO_DEVAD_NONE, 0);
}
static int vsc8211_intr_enable(struct cphy *cphy)
{
return t3_mdio_write(cphy, MDIO_DEVAD_NONE, VSC8211_INTR_ENABLE,
INTR_MASK);
}
static int vsc8211_intr_disable(struct cphy *cphy)
{
return t3_mdio_write(cphy, MDIO_DEVAD_NONE, VSC8211_INTR_ENABLE, 0);
}
static int vsc8211_intr_clear(struct cphy *cphy)
{
u32 val;
return t3_mdio_read(cphy, MDIO_DEVAD_NONE, VSC8211_INTR_STATUS, &val);
}
static int vsc8211_autoneg_enable(struct cphy *cphy)
{
return t3_mdio_change_bits(cphy, MDIO_DEVAD_NONE, MII_BMCR,
BMCR_PDOWN | BMCR_ISOLATE,
BMCR_ANENABLE | BMCR_ANRESTART);
}
static int vsc8211_autoneg_restart(struct cphy *cphy)
{
return t3_mdio_change_bits(cphy, MDIO_DEVAD_NONE, MII_BMCR,
BMCR_PDOWN | BMCR_ISOLATE,
BMCR_ANRESTART);
}
static int vsc8211_get_link_status(struct cphy *cphy, int *link_ok,
int *speed, int *duplex, int *fc)
{
unsigned int bmcr, status, lpa, adv;
int err, sp = -1, dplx = -1, pause = 0;
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_BMCR, &bmcr);
if (!err)
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_BMSR, &status);
if (err)
return err;
if (link_ok) {
if (!(status & BMSR_LSTATUS))
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_BMSR,
&status);
if (err)
return err;
*link_ok = (status & BMSR_LSTATUS) != 0;
}
if (!(bmcr & BMCR_ANENABLE)) {
dplx = (bmcr & BMCR_FULLDPLX) ? DUPLEX_FULL : DUPLEX_HALF;
if (bmcr & BMCR_SPEED1000)
sp = SPEED_1000;
else if (bmcr & BMCR_SPEED100)
sp = SPEED_100;
else
sp = SPEED_10;
} else if (status & BMSR_ANEGCOMPLETE) {
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, VSC8211_AUX_CTRL_STAT,
&status);
if (err)
return err;
dplx = (status & F_ACSR_DUPLEX) ? DUPLEX_FULL : DUPLEX_HALF;
sp = G_ACSR_SPEED(status);
if (sp == 0)
sp = SPEED_10;
else if (sp == 1)
sp = SPEED_100;
else
sp = SPEED_1000;
if (fc && dplx == DUPLEX_FULL) {
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_LPA,
&lpa);
if (!err)
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE,
MII_ADVERTISE, &adv);
if (err)
return err;
if (lpa & adv & ADVERTISE_PAUSE_CAP)
pause = PAUSE_RX | PAUSE_TX;
else if ((lpa & ADVERTISE_PAUSE_CAP) &&
(lpa & ADVERTISE_PAUSE_ASYM) &&
(adv & ADVERTISE_PAUSE_ASYM))
pause = PAUSE_TX;
else if ((lpa & ADVERTISE_PAUSE_ASYM) &&
(adv & ADVERTISE_PAUSE_CAP))
pause = PAUSE_RX;
}
}
if (speed)
*speed = sp;
if (duplex)
*duplex = dplx;
if (fc)
*fc = pause;
return 0;
}
static int vsc8211_get_link_status_fiber(struct cphy *cphy, int *link_ok,
int *speed, int *duplex, int *fc)
{
unsigned int bmcr, status, lpa, adv;
int err, sp = -1, dplx = -1, pause = 0;
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_BMCR, &bmcr);
if (!err)
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_BMSR, &status);
if (err)
return err;
if (link_ok) {
if (!(status & BMSR_LSTATUS))
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_BMSR,
&status);
if (err)
return err;
*link_ok = (status & BMSR_LSTATUS) != 0;
}
if (!(bmcr & BMCR_ANENABLE)) {
dplx = (bmcr & BMCR_FULLDPLX) ? DUPLEX_FULL : DUPLEX_HALF;
if (bmcr & BMCR_SPEED1000)
sp = SPEED_1000;
else if (bmcr & BMCR_SPEED100)
sp = SPEED_100;
else
sp = SPEED_10;
} else if (status & BMSR_ANEGCOMPLETE) {
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_LPA, &lpa);
if (!err)
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, MII_ADVERTISE,
&adv);
if (err)
return err;
if (adv & lpa & ADVERTISE_1000XFULL) {
dplx = DUPLEX_FULL;
sp = SPEED_1000;
} else if (adv & lpa & ADVERTISE_1000XHALF) {
dplx = DUPLEX_HALF;
sp = SPEED_1000;
}
if (fc && dplx == DUPLEX_FULL) {
if (lpa & adv & ADVERTISE_1000XPAUSE)
pause = PAUSE_RX | PAUSE_TX;
else if ((lpa & ADVERTISE_1000XPAUSE) &&
(adv & lpa & ADVERTISE_1000XPSE_ASYM))
pause = PAUSE_TX;
else if ((lpa & ADVERTISE_1000XPSE_ASYM) &&
(adv & ADVERTISE_1000XPAUSE))
pause = PAUSE_RX;
}
}
if (speed)
*speed = sp;
if (duplex)
*duplex = dplx;
if (fc)
*fc = pause;
return 0;
}
static int vsc8211_set_automdi(struct cphy *phy, int enable)
{
int err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, VSC8211_EXT_PAGE_AXS, 0x52b5);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, 18, 0x12);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, 17, enable ? 0x2803 : 0x3003);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, 16, 0x87fa);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, VSC8211_EXT_PAGE_AXS, 0);
if (err)
return err;
return 0;
}
int vsc8211_set_speed_duplex(struct cphy *phy, int speed, int duplex)
{
int err;
err = t3_set_phy_speed_duplex(phy, speed, duplex);
if (!err)
err = vsc8211_set_automdi(phy, 1);
return err;
}
static int vsc8211_power_down(struct cphy *cphy, int enable)
{
return t3_mdio_change_bits(cphy, 0, MII_BMCR, BMCR_PDOWN,
enable ? BMCR_PDOWN : 0);
}
static int vsc8211_intr_handler(struct cphy *cphy)
{
unsigned int cause;
int err, cphy_cause = 0;
err = t3_mdio_read(cphy, MDIO_DEVAD_NONE, VSC8211_INTR_STATUS, &cause);
if (err)
return err;
cause &= INTR_MASK;
if (cause & CFG_CHG_INTR_MASK)
cphy_cause |= cphy_cause_link_change;
if (cause & (VSC_INTR_RX_FIFO | VSC_INTR_TX_FIFO))
cphy_cause |= cphy_cause_fifo_error;
return cphy_cause;
}
int t3_vsc8211_phy_prep(struct cphy *phy, struct adapter *adapter,
int phy_addr, const struct mdio_ops *mdio_ops)
{
int err;
unsigned int val;
cphy_init(phy, adapter, phy_addr, &vsc8211_ops, mdio_ops,
SUPPORTED_10baseT_Full | SUPPORTED_100baseT_Full |
SUPPORTED_1000baseT_Full | SUPPORTED_Autoneg | SUPPORTED_MII |
SUPPORTED_TP | SUPPORTED_IRQ, "10/100/1000BASE-T");
msleep(20);
err = t3_mdio_read(phy, MDIO_DEVAD_NONE, VSC8211_EXT_CTRL, &val);
if (err)
return err;
if (val & VSC_CTRL_MEDIA_MODE_HI) {
return t3_mdio_write(phy, MDIO_DEVAD_NONE, VSC8211_LED_CTRL,
0x100);
}
phy->caps = SUPPORTED_1000baseT_Full | SUPPORTED_Autoneg |
SUPPORTED_MII | SUPPORTED_FIBRE | SUPPORTED_IRQ;
phy->desc = "1000BASE-X";
phy->ops = &vsc8211_fiber_ops;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, VSC8211_EXT_PAGE_AXS, 1);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, VSC8211_SIGDET_CTRL, 1);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, VSC8211_EXT_PAGE_AXS, 0);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_DEVAD_NONE, VSC8211_EXT_CTRL,
val | VSC_CTRL_CLAUSE37_VIEW);
if (err)
return err;
err = vsc8211_reset(phy, 0);
if (err)
return err;
udelay(5);
return 0;
}
