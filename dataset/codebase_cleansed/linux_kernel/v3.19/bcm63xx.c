static int bcm63xx_config_init(struct phy_device *phydev)
{
int reg, err;
reg = phy_read(phydev, MII_BCM63XX_IR);
if (reg < 0)
return reg;
reg |= MII_BCM63XX_IR_GMASK;
err = phy_write(phydev, MII_BCM63XX_IR, reg);
if (err < 0)
return err;
reg = ~(MII_BCM63XX_IR_DUPLEX |
MII_BCM63XX_IR_SPEED |
MII_BCM63XX_IR_LINK) |
MII_BCM63XX_IR_EN;
return phy_write(phydev, MII_BCM63XX_IR, reg);
}
static int bcm63xx_ack_interrupt(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_BCM63XX_IR);
if (reg < 0)
return reg;
return 0;
}
static int bcm63xx_config_intr(struct phy_device *phydev)
{
int reg, err;
reg = phy_read(phydev, MII_BCM63XX_IR);
if (reg < 0)
return reg;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
reg &= ~MII_BCM63XX_IR_GMASK;
else
reg |= MII_BCM63XX_IR_GMASK;
err = phy_write(phydev, MII_BCM63XX_IR, reg);
return err;
}
