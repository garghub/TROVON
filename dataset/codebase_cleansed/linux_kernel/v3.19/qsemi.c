static int qs6612_config_init(struct phy_device *phydev)
{
return phy_write(phydev, MII_QS6612_PCR, 0x0dc0);
}
static int qs6612_ack_interrupt(struct phy_device *phydev)
{
int err;
err = phy_read(phydev, MII_QS6612_ISR);
if (err < 0)
return err;
err = phy_read(phydev, MII_BMSR);
if (err < 0)
return err;
err = phy_read(phydev, MII_EXPANSION);
if (err < 0)
return err;
return 0;
}
static int qs6612_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, MII_QS6612_IMR,
MII_QS6612_IMR_INIT);
else
err = phy_write(phydev, MII_QS6612_IMR, 0);
return err;
}
