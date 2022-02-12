static int lxt970_ack_interrupt(struct phy_device *phydev)
{
int err;
err = phy_read(phydev, MII_BMSR);
if (err < 0)
return err;
err = phy_read(phydev, MII_LXT970_ISR);
if (err < 0)
return err;
return 0;
}
static int lxt970_config_intr(struct phy_device *phydev)
{
int err;
if(phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, MII_LXT970_IER, MII_LXT970_IER_IEN);
else
err = phy_write(phydev, MII_LXT970_IER, 0);
return err;
}
static int lxt970_config_init(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, MII_LXT970_CONFIG, 0);
return err;
}
static int lxt971_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, MII_LXT971_ISR);
if (err < 0)
return err;
return 0;
}
static int lxt971_config_intr(struct phy_device *phydev)
{
int err;
if(phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, MII_LXT971_IER, MII_LXT971_IER_IEN);
else
err = phy_write(phydev, MII_LXT971_IER, 0);
return err;
}
static int lxt973_probe(struct phy_device *phydev)
{
int val = phy_read(phydev, MII_LXT973_PCR);
if (val & PCR_FIBER_SELECT) {
val = phy_read(phydev, MII_BMCR);
val |= (BMCR_SPEED100 | BMCR_FULLDPLX);
val &= ~BMCR_ANENABLE;
phy_write(phydev, MII_BMCR, val);
phydev->priv = lxt973_probe;
} else {
phydev->priv = NULL;
}
return 0;
}
static int lxt973_config_aneg(struct phy_device *phydev)
{
return phydev->priv ? 0 : genphy_config_aneg(phydev);
}
static int __init lxt_init(void)
{
int ret;
ret = phy_driver_register(&lxt970_driver);
if (ret)
goto err1;
ret = phy_driver_register(&lxt971_driver);
if (ret)
goto err2;
ret = phy_driver_register(&lxt973_driver);
if (ret)
goto err3;
return 0;
err3:
phy_driver_unregister(&lxt971_driver);
err2:
phy_driver_unregister(&lxt970_driver);
err1:
return ret;
}
static void __exit lxt_exit(void)
{
phy_driver_unregister(&lxt970_driver);
phy_driver_unregister(&lxt971_driver);
phy_driver_unregister(&lxt973_driver);
}
