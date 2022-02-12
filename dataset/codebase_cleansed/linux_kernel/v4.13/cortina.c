static int cortina_read_reg(struct phy_device *phydev, u16 regnum)
{
return mdiobus_read(phydev->mdio.bus, phydev->mdio.addr,
MII_ADDR_C45 | regnum);
}
static int cortina_config_aneg(struct phy_device *phydev)
{
phydev->supported = SUPPORTED_10000baseT_Full;
phydev->advertising = SUPPORTED_10000baseT_Full;
return 0;
}
static int cortina_read_status(struct phy_device *phydev)
{
int gpio_int_status, ret = 0;
gpio_int_status = cortina_read_reg(phydev, VILLA_GLOBAL_GPIO_1_INTS);
if (gpio_int_status < 0) {
ret = gpio_int_status;
goto err;
}
if (gpio_int_status & 0x8) {
phydev->speed = SPEED_10000;
phydev->duplex = DUPLEX_FULL;
phydev->link = 1;
} else {
phydev->link = 0;
}
err:
return ret;
}
static int cortina_soft_reset(struct phy_device *phydev)
{
return 0;
}
static int cortina_probe(struct phy_device *phydev)
{
u32 phy_id = 0;
int id_lsb = 0, id_msb = 0;
id_lsb = cortina_read_reg(phydev, VILLA_GLOBAL_CHIP_ID_LSB);
if (id_lsb < 0)
return -ENXIO;
phy_id = id_lsb << 16;
id_msb = cortina_read_reg(phydev, VILLA_GLOBAL_CHIP_ID_MSB);
if (id_msb < 0)
return -ENXIO;
phy_id |= id_msb;
if (phy_id != phydev->drv->phy_id) {
phydev_err(phydev, "Error matching phy with %s driver\n",
phydev->drv->name);
return -ENODEV;
}
return 0;
}
