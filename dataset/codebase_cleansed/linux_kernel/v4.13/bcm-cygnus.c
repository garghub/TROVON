static int bcm_cygnus_afe_config(struct phy_device *phydev)
{
int rc;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, 0x0c30);
if (rc < 0)
return rc;
rc = bcm_phy_write_misc(phydev, 0x39, 0x01, 0xA7C8);
if (rc < 0)
return rc;
rc = bcm_phy_write_misc(phydev, 0x3A, 0x00, 0x0803);
if (rc < 0)
return rc;
rc = bcm_phy_write_misc(phydev, 0x3A, 0x01, 0xA740);
if (rc < 0)
return rc;
rc = bcm_phy_write_misc(phydev, 0x3A, 0x03, 0x8400);
if (rc < 0)
return rc;
rc = bcm_phy_write_misc(phydev, 0x3B, 0x00, 0x0004);
if (rc < 0)
return rc;
rc = phy_write(phydev, MII_BRCM_CORE_BASE1E, 0x02);
if (rc < 0)
return rc;
rc = bcm_phy_write_exp(phydev, MII_BRCM_CORE_EXPB1, 0x10);
if (rc < 0)
return rc;
rc = bcm_phy_write_exp(phydev, MII_BRCM_CORE_EXPB0, 0x10);
if (rc < 0)
return rc;
rc = bcm_phy_write_exp(phydev, MII_BRCM_CORE_EXPB0, 0x00);
return 0;
}
static int bcm_cygnus_config_init(struct phy_device *phydev)
{
int reg, rc;
reg = phy_read(phydev, MII_BCM54XX_ECR);
if (reg < 0)
return reg;
reg |= MII_BCM54XX_ECR_IM;
rc = phy_write(phydev, MII_BCM54XX_ECR, reg);
if (rc)
return rc;
reg = ~(MII_BCM54XX_INT_DUPLEX |
MII_BCM54XX_INT_SPEED |
MII_BCM54XX_INT_LINK);
rc = phy_write(phydev, MII_BCM54XX_IMR, reg);
if (rc)
return rc;
rc = bcm_cygnus_afe_config(phydev);
if (rc)
return rc;
rc = bcm_phy_set_eee(phydev, true);
if (rc)
return rc;
return bcm_phy_enable_apd(phydev, false);
}
static int bcm_cygnus_resume(struct phy_device *phydev)
{
int rc;
genphy_resume(phydev);
rc = bcm_cygnus_config_init(phydev);
if (rc)
return rc;
return genphy_config_aneg(phydev);
}
