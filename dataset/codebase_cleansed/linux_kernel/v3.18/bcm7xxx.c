static int bcm7445_config_init(struct phy_device *phydev)
{
int ret;
const struct bcm7445_regs {
int reg;
u16 value;
} bcm7445_regs_cfg[] = {
{ MII_BCM54XX_EXP_SEL, 0x0038 },
{ MII_BCM54XX_EXP_DATA, 0xAB95 },
{ MII_BCM54XX_EXP_SEL, 0x2038 },
{ MII_BCM54XX_EXP_DATA, 0xBB22 },
{ MII_BCM54XX_EXP_SEL, 0x6038 },
{ MII_BCM54XX_EXP_DATA, 0xFFC5 },
{ MII_BCM54XX_EXP_SEL, 0x003a },
{ MII_BCM54XX_EXP_DATA, 0x2002 },
};
unsigned int i;
for (i = 0; i < ARRAY_SIZE(bcm7445_regs_cfg); i++) {
ret = phy_write(phydev,
bcm7445_regs_cfg[i].reg,
bcm7445_regs_cfg[i].value);
if (ret)
return ret;
}
return 0;
}
static void phy_write_exp(struct phy_device *phydev,
u16 reg, u16 value)
{
phy_write(phydev, MII_BCM54XX_EXP_SEL, MII_BCM54XX_EXP_SEL_ER | reg);
phy_write(phydev, MII_BCM54XX_EXP_DATA, value);
}
static void phy_write_misc(struct phy_device *phydev,
u16 reg, u16 chl, u16 value)
{
int tmp;
phy_write(phydev, MII_BCM54XX_AUX_CTL, MII_BCM54XX_AUXCTL_SHDWSEL_MISC);
tmp = phy_read(phydev, MII_BCM54XX_AUX_CTL);
tmp |= MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA;
phy_write(phydev, MII_BCM54XX_AUX_CTL, tmp);
tmp = (chl * MII_BCM7XXX_CHANNEL_WIDTH) | reg;
phy_write(phydev, MII_BCM54XX_EXP_SEL, tmp);
phy_write(phydev, MII_BCM54XX_EXP_DATA, value);
}
static int bcm7xxx_28nm_afe_config_init(struct phy_device *phydev)
{
phy_write_misc(phydev, PLL_PLLCTRL_1, 0x0048);
phy_write_misc(phydev, PLL_PLLCTRL_2, 0x021b);
phy_write_misc(phydev, PLL_PLLCTRL_4, 0x0e20);
phy_write_misc(phydev, DSP_TAP10, 0x690b);
phy_write(phydev, MII_BCM7XXX_CORE_BASE1E, 0xd);
phy_write_exp(phydev, CORE_EXPB0, 0x0010);
phy_write_exp(phydev, CORE_EXPB0, 0x0000);
phy_write_misc(phydev, AFE_RXCONFIG_0, 0xeb19);
phy_write_misc(phydev, AFE_RXCONFIG_1, 0x9a3f);
phy_write_misc(phydev, AFE_RX_LP_COUNTER, 0x7fc0);
phy_write_misc(phydev, AFE_HPF_TRIM_OTHERS, 0x000b);
phy_write_misc(phydev, AFE_TX_CONFIG, 0x0800);
return 0;
}
static int bcm7xxx_apd_enable(struct phy_device *phydev)
{
int val;
val = bcm54xx_shadow_read(phydev, BCM54XX_SHD_SCR3);
if (val < 0)
return val;
val |= BCM54XX_SHD_SCR3_DLLAPD_DIS;
bcm54xx_shadow_write(phydev, BCM54XX_SHD_SCR3, val);
val = bcm54xx_shadow_read(phydev, BCM54XX_SHD_APD);
if (val < 0)
return val;
val |= BCM54XX_SHD_APD_EN;
return bcm54xx_shadow_write(phydev, BCM54XX_SHD_APD, val);
}
static int bcm7xxx_eee_enable(struct phy_device *phydev)
{
int val;
val = phy_read_mmd_indirect(phydev, BRCM_CL45VEN_EEE_CONTROL,
MDIO_MMD_AN, phydev->addr);
if (val < 0)
return val;
val |= LPI_FEATURE_EN | LPI_FEATURE_EN_DIG1000X;
phy_write_mmd_indirect(phydev, BRCM_CL45VEN_EEE_CONTROL,
MDIO_MMD_AN, phydev->addr, val);
val = phy_read_mmd_indirect(phydev, MDIO_AN_EEE_ADV,
MDIO_MMD_AN, phydev->addr);
val |= (MDIO_AN_EEE_ADV_100TX | MDIO_AN_EEE_ADV_1000T);
phy_write_mmd_indirect(phydev, MDIO_AN_EEE_ADV,
MDIO_MMD_AN, phydev->addr, val);
return 0;
}
static int bcm7xxx_28nm_config_init(struct phy_device *phydev)
{
u8 rev = PHY_BRCM_7XXX_REV(phydev->dev_flags);
u8 patch = PHY_BRCM_7XXX_PATCH(phydev->dev_flags);
int ret = 0;
dev_info(&phydev->dev, "PHY revision: 0x%02x, patch: %d\n", rev, patch);
switch (rev) {
case 0xa0:
case 0xb0:
ret = bcm7445_config_init(phydev);
break;
default:
ret = bcm7xxx_28nm_afe_config_init(phydev);
break;
}
if (ret)
return ret;
ret = bcm7xxx_eee_enable(phydev);
if (ret)
return ret;
return bcm7xxx_apd_enable(phydev);
}
static int bcm7xxx_28nm_resume(struct phy_device *phydev)
{
int ret;
ret = bcm7xxx_28nm_config_init(phydev);
if (ret)
return ret;
return genphy_config_aneg(phydev);
}
static int phy_set_clr_bits(struct phy_device *dev, int location,
int set_mask, int clr_mask)
{
int v, ret;
v = phy_read(dev, location);
if (v < 0)
return v;
v &= ~clr_mask;
v |= set_mask;
ret = phy_write(dev, location, v);
if (ret < 0)
return ret;
return v;
}
static int bcm7xxx_config_init(struct phy_device *phydev)
{
int ret;
phy_write(phydev, MII_BCM7XXX_AUX_MODE, MII_BCM7XX_64CLK_MDIO);
phy_read(phydev, MII_BCM7XXX_AUX_MODE);
if (phydev->supported & PHY_GBIT_FEATURES)
return 0;
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST,
MII_BCM7XXX_SHD_MODE_2, MII_BCM7XXX_SHD_MODE_2);
if (ret < 0)
return ret;
phy_write(phydev, MII_BCM7XXX_100TX_DISC, 0x0F00);
udelay(10);
phy_write(phydev, MII_BCM7XXX_100TX_DISC, 0x0C00);
phy_write(phydev, MII_BCM7XXX_100TX_FALSE_CAR, 0x7555);
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST, MII_BCM7XXX_SHD_MODE_2, 0);
if (ret < 0)
return ret;
return 0;
}
static int bcm7xxx_suspend(struct phy_device *phydev)
{
int ret;
const struct bcm7xxx_regs {
int reg;
u16 value;
} bcm7xxx_suspend_cfg[] = {
{ MII_BCM7XXX_TEST, 0x008b },
{ MII_BCM7XXX_100TX_AUX_CTL, 0x01c0 },
{ MII_BCM7XXX_100TX_DISC, 0x7000 },
{ MII_BCM7XXX_TEST, 0x000f },
{ MII_BCM7XXX_100TX_AUX_CTL, 0x20d0 },
{ MII_BCM7XXX_TEST, 0x000b },
};
unsigned int i;
for (i = 0; i < ARRAY_SIZE(bcm7xxx_suspend_cfg); i++) {
ret = phy_write(phydev,
bcm7xxx_suspend_cfg[i].reg,
bcm7xxx_suspend_cfg[i].value);
if (ret)
return ret;
}
return 0;
}
static int bcm7xxx_dummy_config_init(struct phy_device *phydev)
{
return 0;
}
static int __init bcm7xxx_phy_init(void)
{
return phy_drivers_register(bcm7xxx_driver,
ARRAY_SIZE(bcm7xxx_driver));
}
static void __exit bcm7xxx_phy_exit(void)
{
phy_drivers_unregister(bcm7xxx_driver,
ARRAY_SIZE(bcm7xxx_driver));
}
