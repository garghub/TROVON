static int kszphy_ack_interrupt(struct phy_device *phydev)
{
int rc;
rc = phy_read(phydev, MII_KSZPHY_INTCS);
return (rc < 0) ? rc : 0;
}
static int kszphy_set_interrupt(struct phy_device *phydev)
{
int temp;
temp = (PHY_INTERRUPT_ENABLED == phydev->interrupts) ?
KSZPHY_INTCS_ALL : 0;
return phy_write(phydev, MII_KSZPHY_INTCS, temp);
}
static int kszphy_config_intr(struct phy_device *phydev)
{
int temp, rc;
temp = phy_read(phydev, MII_KSZPHY_CTRL);
temp &= ~KSZPHY_CTRL_INT_ACTIVE_HIGH;
phy_write(phydev, MII_KSZPHY_CTRL, temp);
rc = kszphy_set_interrupt(phydev);
return rc < 0 ? rc : 0;
}
static int ksz9021_config_intr(struct phy_device *phydev)
{
int temp, rc;
temp = phy_read(phydev, MII_KSZPHY_CTRL);
temp &= ~KSZ9021_CTRL_INT_ACTIVE_HIGH;
phy_write(phydev, MII_KSZPHY_CTRL, temp);
rc = kszphy_set_interrupt(phydev);
return rc < 0 ? rc : 0;
}
static int ks8737_config_intr(struct phy_device *phydev)
{
int temp, rc;
temp = phy_read(phydev, MII_KSZPHY_CTRL);
temp &= ~KS8737_CTRL_INT_ACTIVE_HIGH;
phy_write(phydev, MII_KSZPHY_CTRL, temp);
rc = kszphy_set_interrupt(phydev);
return rc < 0 ? rc : 0;
}
static int kszphy_config_init(struct phy_device *phydev)
{
return 0;
}
static int ks8051_config_init(struct phy_device *phydev)
{
int regval;
if (phydev->dev_flags & MICREL_PHY_50MHZ_CLK) {
regval = phy_read(phydev, MII_KSZPHY_CTRL);
regval |= KSZ8051_RMII_50MHZ_CLK;
phy_write(phydev, MII_KSZPHY_CTRL, regval);
}
return 0;
}
static int __init ksphy_init(void)
{
int ret;
ret = phy_driver_register(&ks8001_driver);
if (ret)
goto err1;
ret = phy_driver_register(&ksz9021_driver);
if (ret)
goto err2;
ret = phy_driver_register(&ks8737_driver);
if (ret)
goto err3;
ret = phy_driver_register(&ks8041_driver);
if (ret)
goto err4;
ret = phy_driver_register(&ks8051_driver);
if (ret)
goto err5;
return 0;
err5:
phy_driver_unregister(&ks8041_driver);
err4:
phy_driver_unregister(&ks8737_driver);
err3:
phy_driver_unregister(&ksz9021_driver);
err2:
phy_driver_unregister(&ks8001_driver);
err1:
return ret;
}
static void __exit ksphy_exit(void)
{
phy_driver_unregister(&ks8001_driver);
phy_driver_unregister(&ks8737_driver);
phy_driver_unregister(&ksz9021_driver);
phy_driver_unregister(&ks8041_driver);
phy_driver_unregister(&ks8051_driver);
}
