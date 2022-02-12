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
static int bcm7xxx_28nm_config_init(struct phy_device *phydev)
{
int ret;
ret = bcm7445_config_init(phydev);
if (ret)
return ret;
return bcm7xxx_28nm_afe_config_init(phydev);
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
if (!(phydev->dev_flags & PHY_BRCM_100MBPS_WAR))
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
