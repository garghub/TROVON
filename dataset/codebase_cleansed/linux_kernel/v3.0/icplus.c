static int ip175c_config_init(struct phy_device *phydev)
{
int err, i;
static int full_reset_performed = 0;
if (full_reset_performed == 0) {
err = phydev->bus->write(phydev->bus, 30, 0, 0x175c);
if (err < 0)
return err;
err = phydev->bus->read(phydev->bus, 30, 0);
mdelay(2);
err = phydev->bus->write(phydev->bus, 29, 31, 0x175c);
if (err < 0)
return err;
err = phydev->bus->write(phydev->bus, 29, 22, 0x420);
if (err < 0)
return err;
for (i = 0; i < 5; i++) {
err = phydev->bus->write(phydev->bus, i,
MII_BMCR, BMCR_RESET);
if (err < 0)
return err;
}
for (i = 0; i < 5; i++)
err = phydev->bus->read(phydev->bus, i, MII_BMCR);
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
static int ip1001_config_init(struct phy_device *phydev)
{
int err, value;
value = phy_read(phydev, MII_BMCR);
value |= BMCR_RESET;
err = phy_write(phydev, MII_BMCR, value);
if (err < 0)
return err;
do {
value = phy_read(phydev, MII_BMCR);
} while (value & BMCR_RESET);
value = phy_read(phydev, 16);
value |= 0x3;
err = phy_write(phydev, 16, value);
if (err < 0)
return err;
return err;
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
static int __init icplus_init(void)
{
int ret = 0;
ret = phy_driver_register(&ip1001_driver);
if (ret < 0)
return -ENODEV;
return phy_driver_register(&ip175c_driver);
}
static void __exit icplus_exit(void)
{
phy_driver_unregister(&ip1001_driver);
phy_driver_unregister(&ip175c_driver);
}
