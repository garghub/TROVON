int bcm_phy_write_exp(struct phy_device *phydev, u16 reg, u16 val)
{
int rc;
rc = phy_write(phydev, MII_BCM54XX_EXP_SEL, reg);
if (rc < 0)
return rc;
return phy_write(phydev, MII_BCM54XX_EXP_DATA, val);
}
int bcm_phy_read_exp(struct phy_device *phydev, u16 reg)
{
int val;
val = phy_write(phydev, MII_BCM54XX_EXP_SEL, reg);
if (val < 0)
return val;
val = phy_read(phydev, MII_BCM54XX_EXP_DATA);
phy_write(phydev, MII_BCM54XX_EXP_SEL, 0);
return val;
}
int bcm_phy_write_misc(struct phy_device *phydev,
u16 reg, u16 chl, u16 val)
{
int rc;
int tmp;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL,
MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
if (rc < 0)
return rc;
tmp = phy_read(phydev, MII_BCM54XX_AUX_CTL);
tmp |= MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, tmp);
if (rc < 0)
return rc;
tmp = (chl * MII_BCM_CHANNEL_WIDTH) | reg;
rc = bcm_phy_write_exp(phydev, tmp, val);
return rc;
}
int bcm_phy_read_misc(struct phy_device *phydev,
u16 reg, u16 chl)
{
int rc;
int tmp;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL,
MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
if (rc < 0)
return rc;
tmp = phy_read(phydev, MII_BCM54XX_AUX_CTL);
tmp |= MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA;
rc = phy_write(phydev, MII_BCM54XX_AUX_CTL, tmp);
if (rc < 0)
return rc;
tmp = (chl * MII_BCM_CHANNEL_WIDTH) | reg;
rc = bcm_phy_read_exp(phydev, tmp);
return rc;
}
int bcm_phy_ack_intr(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_BCM54XX_ISR);
if (reg < 0)
return reg;
return 0;
}
int bcm_phy_config_intr(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_BCM54XX_ECR);
if (reg < 0)
return reg;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
reg &= ~MII_BCM54XX_ECR_IM;
else
reg |= MII_BCM54XX_ECR_IM;
return phy_write(phydev, MII_BCM54XX_ECR, reg);
}
int bcm_phy_read_shadow(struct phy_device *phydev, u16 shadow)
{
phy_write(phydev, MII_BCM54XX_SHD, MII_BCM54XX_SHD_VAL(shadow));
return MII_BCM54XX_SHD_DATA(phy_read(phydev, MII_BCM54XX_SHD));
}
int bcm_phy_write_shadow(struct phy_device *phydev, u16 shadow,
u16 val)
{
return phy_write(phydev, MII_BCM54XX_SHD,
MII_BCM54XX_SHD_WRITE |
MII_BCM54XX_SHD_VAL(shadow) |
MII_BCM54XX_SHD_DATA(val));
}
int bcm_phy_enable_apd(struct phy_device *phydev, bool dll_pwr_down)
{
int val;
if (dll_pwr_down) {
val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_SCR3);
if (val < 0)
return val;
val |= BCM54XX_SHD_SCR3_DLLAPD_DIS;
bcm_phy_write_shadow(phydev, BCM54XX_SHD_SCR3, val);
}
val = bcm_phy_read_shadow(phydev, BCM54XX_SHD_APD);
if (val < 0)
return val;
val &= BCM_APD_CLR_MASK;
if (phydev->autoneg == AUTONEG_ENABLE)
val |= BCM54XX_SHD_APD_EN;
else
val |= BCM_NO_ANEG_APD_EN;
val |= BCM_APD_SINGLELP_EN;
return bcm_phy_write_shadow(phydev, BCM54XX_SHD_APD, val);
}
int bcm_phy_enable_eee(struct phy_device *phydev)
{
int val;
val = phy_read_mmd_indirect(phydev, BRCM_CL45VEN_EEE_CONTROL,
MDIO_MMD_AN, phydev->addr);
if (val < 0)
return val;
val |= LPI_FEATURE_EN | LPI_FEATURE_EN_DIG1000X;
phy_write_mmd_indirect(phydev, BRCM_CL45VEN_EEE_CONTROL,
MDIO_MMD_AN, phydev->addr, (u32)val);
val = phy_read_mmd_indirect(phydev, BCM_CL45VEN_EEE_ADV,
MDIO_MMD_AN, phydev->addr);
if (val < 0)
return val;
val |= (MDIO_AN_EEE_ADV_100TX | MDIO_AN_EEE_ADV_1000T);
phy_write_mmd_indirect(phydev, BCM_CL45VEN_EEE_ADV,
MDIO_MMD_AN, phydev->addr, (u32)val);
return 0;
}
