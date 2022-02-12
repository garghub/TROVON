static int ip175c_config_init(struct phy_device *phydev)
{
int err, i;
static int full_reset_performed = 0;
if (full_reset_performed == 0) {
err = mdiobus_write(phydev->bus, 30, 0, 0x175c);
if (err < 0)
return err;
err = mdiobus_read(phydev->bus, 30, 0);
mdelay(2);
err = mdiobus_write(phydev->bus, 29, 31, 0x175c);
if (err < 0)
return err;
err = mdiobus_write(phydev->bus, 29, 22, 0x420);
if (err < 0)
return err;
for (i = 0; i < 5; i++) {
err = mdiobus_write(phydev->bus, i,
MII_BMCR, BMCR_RESET);
if (err < 0)
return err;
}
for (i = 0; i < 5; i++)
err = mdiobus_read(phydev->bus, i, MII_BMCR);
mdelay(2);
full_reset_performed = 1;
}
if (phydev->addr != 4) {
phydev->state = PHY_RUNNING;
phydev->speed = SPEED_100;
phydev->duplex = DUPLEX_FULL;
phydev->link = 1;
netif_carrier_on(phydev->attached_dev);
}
return 0;
}
static int ip1xx_reset(struct phy_device *phydev)
{
int bmcr;
bmcr = phy_read(phydev, MII_BMCR);
if (bmcr < 0)
return bmcr;
bmcr |= BMCR_RESET;
bmcr = phy_write(phydev, MII_BMCR, bmcr);
if (bmcr < 0)
return bmcr;
do {
bmcr = phy_read(phydev, MII_BMCR);
if (bmcr < 0)
return bmcr;
} while (bmcr & BMCR_RESET);
return 0;
}
static int ip1001_config_init(struct phy_device *phydev)
{
int c;
c = ip1xx_reset(phydev);
if (c < 0)
return c;
c = phy_read(phydev, IP1001_SPEC_CTRL_STATUS_2);
if (c < 0)
return c;
c |= IP1001_APS_ON;
c = phy_write(phydev, IP1001_SPEC_CTRL_STATUS_2, c);
if (c < 0)
return c;
if ((phydev->interface == PHY_INTERFACE_MODE_RGMII) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_ID) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID) ||
(phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)) {
c = phy_read(phydev, IP10XX_SPEC_CTRL_STATUS);
if (c < 0)
return c;
c &= ~(IP1001_RXPHASE_SEL | IP1001_TXPHASE_SEL);
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
c |= (IP1001_RXPHASE_SEL | IP1001_TXPHASE_SEL);
else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID)
c |= IP1001_RXPHASE_SEL;
else if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)
c |= IP1001_TXPHASE_SEL;
c = phy_write(phydev, IP10XX_SPEC_CTRL_STATUS, c);
if (c < 0)
return c;
}
return 0;
}
static int ip101a_g_config_init(struct phy_device *phydev)
{
int c;
c = ip1xx_reset(phydev);
if (c < 0)
return c;
c = phy_write(phydev, IP101A_G_IRQ_CONF_STATUS, IP101A_G_IRQ_DEFAULT);
if (c < 0)
return c;
c = phy_read(phydev, IP10XX_SPEC_CTRL_STATUS);
c |= IP101A_G_APS_ON;
return phy_write(phydev, IP10XX_SPEC_CTRL_STATUS, c);
}
static int ip175c_read_status(struct phy_device *phydev)
{
if (phydev->addr == 4)
genphy_read_status(phydev);
else
phydev->irq = PHY_IGNORE_INTERRUPT;
return 0;
}
static int ip175c_config_aneg(struct phy_device *phydev)
{
if (phydev->addr == 4)
genphy_config_aneg(phydev);
return 0;
}
static int ip101a_g_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, IP101A_G_IRQ_CONF_STATUS);
if (err < 0)
return err;
return 0;
}
static int __init icplus_init(void)
{
return phy_drivers_register(icplus_driver,
ARRAY_SIZE(icplus_driver));
}
static void __exit icplus_exit(void)
{
phy_drivers_unregister(icplus_driver,
ARRAY_SIZE(icplus_driver));
}
