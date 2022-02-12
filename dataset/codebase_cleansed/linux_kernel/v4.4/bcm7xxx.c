static void r_rc_cal_reset(struct phy_device *phydev)
{
bcm_phy_write_exp(phydev, 0x00b0, 0x0010);
bcm_phy_write_exp(phydev, 0x00b0, 0x0000);
}
static int bcm7xxx_28nm_b0_afe_config_init(struct phy_device *phydev)
{
bcm_phy_write_misc(phydev, PLL_PLLCTRL_1, 0x0048);
bcm_phy_write_misc(phydev, PLL_PLLCTRL_2, 0x021b);
bcm_phy_write_misc(phydev, PLL_PLLCTRL_4, 0x0e20);
bcm_phy_write_misc(phydev, DSP_TAP10, 0x690b);
phy_write(phydev, MII_BRCM_CORE_BASE1E, 0xd);
r_rc_cal_reset(phydev);
bcm_phy_write_misc(phydev, AFE_RXCONFIG_0, 0xeb19);
bcm_phy_write_misc(phydev, AFE_RXCONFIG_1, 0x9a3f);
bcm_phy_write_misc(phydev, AFE_RX_LP_COUNTER, 0x7fc0);
bcm_phy_write_misc(phydev, AFE_HPF_TRIM_OTHERS, 0x000b);
bcm_phy_write_misc(phydev, AFE_TX_CONFIG, 0x0800);
return 0;
}
static int bcm7xxx_28nm_d0_afe_config_init(struct phy_device *phydev)
{
bcm_phy_write_misc(phydev, AFE_RXCONFIG_0, 0xeb15);
bcm_phy_write_misc(phydev, AFE_RXCONFIG_1, 0x9b2f);
bcm_phy_write_misc(phydev, AFE_RXCONFIG_2, 0x2003);
bcm_phy_write_misc(phydev, AFE_RX_LP_COUNTER, 0x7fc0);
bcm_phy_write_misc(phydev, AFE_TX_CONFIG, 0x431);
bcm_phy_write_misc(phydev, AFE_VDCA_ICTRL_0, 0xa7da);
bcm_phy_write_misc(phydev, AFE_VDAC_OTHERS_0, 0xa020);
bcm_phy_write_misc(phydev, AFE_HPF_TRIM_OTHERS, 0x00e3);
phy_write(phydev, MII_BRCM_CORE_BASE1E, 0x0010);
bcm_phy_write_misc(phydev, DSP_TAP10, 0x011b);
r_rc_cal_reset(phydev);
return 0;
}
static int bcm7xxx_28nm_e0_plus_afe_config_init(struct phy_device *phydev)
{
bcm_phy_write_misc(phydev, AFE_RXCONFIG_1, 0x9b2f);
bcm_phy_write_misc(phydev, AFE_TX_CONFIG, 0x431);
bcm_phy_write_misc(phydev, AFE_VDCA_ICTRL_0, 0xa7da);
bcm_phy_write_misc(phydev, AFE_HPF_TRIM_OTHERS, 0x00e3);
phy_write(phydev, MII_BRCM_CORE_BASE1E, 0x0010);
bcm_phy_write_misc(phydev, DSP_TAP10, 0x011b);
r_rc_cal_reset(phydev);
return 0;
}
static int bcm7xxx_28nm_config_init(struct phy_device *phydev)
{
u8 rev = PHY_BRCM_7XXX_REV(phydev->dev_flags);
u8 patch = PHY_BRCM_7XXX_PATCH(phydev->dev_flags);
int ret = 0;
pr_info_once("%s: %s PHY revision: 0x%02x, patch: %d\n",
dev_name(&phydev->dev), phydev->drv->name, rev, patch);
phy_read(phydev, MII_BMSR);
switch (rev) {
case 0xb0:
ret = bcm7xxx_28nm_b0_afe_config_init(phydev);
break;
case 0xd0:
ret = bcm7xxx_28nm_d0_afe_config_init(phydev);
break;
case 0xe0:
case 0xf0:
case 0x10:
ret = bcm7xxx_28nm_e0_plus_afe_config_init(phydev);
break;
default:
break;
}
if (ret)
return ret;
ret = bcm_phy_enable_eee(phydev);
if (ret)
return ret;
return bcm_phy_enable_apd(phydev, true);
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
