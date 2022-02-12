static int aq100x_reset(struct cphy *phy, int wait)
{
int err = t3_phy_reset(phy, MDIO_MMD_VEND1, 3000);
if (err)
CH_WARN(phy->adapter, "PHY%d: reset failed (0x%x).\n",
phy->mdio.prtad, err);
return err;
}
static int aq100x_intr_enable(struct cphy *phy)
{
int err = t3_mdio_write(phy, MDIO_MMD_PMAPMD, AQ_IMASK_PMA, IMASK_PMA);
if (err)
return err;
err = t3_mdio_write(phy, MDIO_MMD_VEND1, AQ_IMASK_GLOBAL, IMASK_GLOBAL);
return err;
}
static int aq100x_intr_disable(struct cphy *phy)
{
return t3_mdio_write(phy, MDIO_MMD_VEND1, AQ_IMASK_GLOBAL, 0);
}
static int aq100x_intr_clear(struct cphy *phy)
{
unsigned int v;
t3_mdio_read(phy, MDIO_MMD_VEND1, AQ_IFLAG_GLOBAL, &v);
t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_STAT1, &v);
return 0;
}
static int aq100x_intr_handler(struct cphy *phy)
{
int err;
unsigned int cause, v;
err = t3_mdio_read(phy, MDIO_MMD_VEND1, AQ_IFLAG_GLOBAL, &cause);
if (err)
return err;
t3_mdio_read(phy, MDIO_MMD_PMAPMD, MDIO_STAT1, &v);
return cphy_cause_link_change;
}
static int aq100x_power_down(struct cphy *phy, int off)
{
return mdio_set_flag(&phy->mdio, phy->mdio.prtad,
MDIO_MMD_PMAPMD, MDIO_CTRL1,
MDIO_CTRL1_LPOWER, off);
}
static int aq100x_autoneg_enable(struct cphy *phy)
{
int err;
err = aq100x_power_down(phy, 0);
if (!err)
err = mdio_set_flag(&phy->mdio, phy->mdio.prtad,
MDIO_MMD_AN, MDIO_CTRL1,
BMCR_ANENABLE | BMCR_ANRESTART, 1);
return err;
}
static int aq100x_autoneg_restart(struct cphy *phy)
{
int err;
err = aq100x_power_down(phy, 0);
if (!err)
err = mdio_set_flag(&phy->mdio, phy->mdio.prtad,
MDIO_MMD_AN, MDIO_CTRL1,
BMCR_ANENABLE | BMCR_ANRESTART, 1);
return err;
}
static int aq100x_advertise(struct cphy *phy, unsigned int advertise_map)
{
unsigned int adv;
int err;
adv = 0;
if (advertise_map & ADVERTISED_10000baseT_Full)
adv |= ADV_10G_FULL;
err = t3_mdio_change_bits(phy, MDIO_MMD_AN, MDIO_AN_10GBT_CTRL,
ADV_10G_FULL, adv);
if (err)
return err;
adv = 0;
if (advertise_map & ADVERTISED_1000baseT_Full)
adv |= ADV_1G_FULL;
if (advertise_map & ADVERTISED_1000baseT_Half)
adv |= ADV_1G_HALF;
err = t3_mdio_change_bits(phy, MDIO_MMD_AN, AQ_1G_CTRL,
ADV_1G_FULL | ADV_1G_HALF, adv);
if (err)
return err;
adv = 0;
if (advertise_map & ADVERTISED_100baseT_Half)
adv |= ADVERTISE_100HALF;
if (advertise_map & ADVERTISED_100baseT_Full)
adv |= ADVERTISE_100FULL;
if (advertise_map & ADVERTISED_Pause)
adv |= ADVERTISE_PAUSE_CAP;
if (advertise_map & ADVERTISED_Asym_Pause)
adv |= ADVERTISE_PAUSE_ASYM;
err = t3_mdio_change_bits(phy, MDIO_MMD_AN, MDIO_AN_ADVERTISE,
0xfe0, adv);
return err;
}
static int aq100x_set_loopback(struct cphy *phy, int mmd, int dir, int enable)
{
return mdio_set_flag(&phy->mdio, phy->mdio.prtad,
MDIO_MMD_PMAPMD, MDIO_CTRL1,
BMCR_LOOPBACK, enable);
}
static int aq100x_set_speed_duplex(struct cphy *phy, int speed, int duplex)
{
return -1;
}
static int aq100x_get_link_status(struct cphy *phy, int *link_ok,
int *speed, int *duplex, int *fc)
{
int err;
unsigned int v;
if (link_ok) {
err = t3_mdio_read(phy, MDIO_MMD_PMAPMD, AQ_LINK_STAT, &v);
if (err)
return err;
*link_ok = v & 1;
if (!*link_ok)
return 0;
}
err = t3_mdio_read(phy, MDIO_MMD_AN, AQ_ANEG_STAT, &v);
if (err)
return err;
if (speed) {
switch (v & 0x6) {
case 0x6:
*speed = SPEED_10000;
break;
case 0x4:
*speed = SPEED_1000;
break;
case 0x2:
*speed = SPEED_100;
break;
case 0x0:
*speed = SPEED_10;
break;
}
}
if (duplex)
*duplex = v & 1 ? DUPLEX_FULL : DUPLEX_HALF;
return 0;
}
int t3_aq100x_phy_prep(struct cphy *phy, struct adapter *adapter, int phy_addr,
const struct mdio_ops *mdio_ops)
{
unsigned int v, v2, gpio, wait;
int err;
cphy_init(phy, adapter, phy_addr, &aq100x_ops, mdio_ops,
SUPPORTED_1000baseT_Full | SUPPORTED_10000baseT_Full |
SUPPORTED_TP | SUPPORTED_Autoneg | SUPPORTED_AUI,
"1000/10GBASE-T");
gpio = phy_addr ? F_GPIO10_OUT_VAL : F_GPIO6_OUT_VAL;
t3_set_reg_field(adapter, A_T3DBG_GPIO_EN, gpio, 0);
msleep(1);
t3_set_reg_field(adapter, A_T3DBG_GPIO_EN, gpio, gpio);
msleep(1000);
wait = 500;
do {
err = t3_mdio_read(phy, MDIO_MMD_VEND1, MDIO_CTRL1, &v);
if (err || v == 0xffff) {
CH_WARN(adapter, "PHY%d: reset failed (0x%x, 0x%x).\n",
phy_addr, err, v);
goto done;
}
v &= AQ_RESET;
if (v)
msleep(10);
} while (v && --wait);
if (v) {
CH_WARN(adapter, "PHY%d: reset timed out (0x%x).\n",
phy_addr, v);
goto done;
}
wait = (500 - wait) * 10 + 1000;
if (wait > 3000)
CH_WARN(adapter, "PHY%d: reset took %ums\n", phy_addr, wait);
t3_mdio_read(phy, MDIO_MMD_VEND1, AQ_FW_VERSION, &v);
if (v != 101)
CH_WARN(adapter, "PHY%d: unsupported firmware %d\n",
phy_addr, v);
err = t3_mdio_read(phy, MDIO_MMD_VEND1, MDIO_CTRL1, &v);
if (err)
return err;
if (v & AQ_LOWPOWER) {
err = t3_mdio_change_bits(phy, MDIO_MMD_VEND1, MDIO_CTRL1,
AQ_LOWPOWER, 0);
if (err)
return err;
msleep(10);
} else
CH_WARN(adapter, "PHY%d does not start in low power mode.\n",
phy_addr);
v = v2 = 0;
t3_mdio_read(phy, MDIO_MMD_PHYXS, AQ_XAUI_RX_CFG, &v);
t3_mdio_read(phy, MDIO_MMD_PHYXS, AQ_XAUI_TX_CFG, &v2);
if (v != 0x1b || v2 != 0x1b)
CH_WARN(adapter,
"PHY%d: incorrect XAUI settings (0x%x, 0x%x).\n",
phy_addr, v, v2);
done:
return err;
}
