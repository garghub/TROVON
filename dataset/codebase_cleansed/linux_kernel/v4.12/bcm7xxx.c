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
static int bcm7xxx_28nm_a0_patch_afe_config_init(struct phy_device *phydev)
{
bcm_phy_write_misc(phydev, AFE_RXCONFIG_2, 0xd003);
bcm_phy_write_misc(phydev, DSP_TAP10, 0x791b);
bcm_phy_write_misc(phydev, AFE_HPF_TRIM_OTHERS, 0x10e3);
bcm_phy_write_misc(phydev, 0x21, 0x2, 0x87f6);
bcm_phy_write_misc(phydev, 0x22, 0x2, 0x017d);
bcm_phy_write_misc(phydev, 0x26, 0x2, 0x0015);
r_rc_cal_reset(phydev);
return 0;
}
static int bcm7xxx_28nm_config_init(struct phy_device *phydev)
{
u8 rev = PHY_BRCM_7XXX_REV(phydev->dev_flags);
u8 patch = PHY_BRCM_7XXX_PATCH(phydev->dev_flags);
u8 count;
int ret = 0;
if (rev == 0)
rev = phydev->phy_id & ~phydev->drv->phy_id_mask;
pr_info_once("%s: %s PHY revision: 0x%02x, patch: %d\n",
phydev_name(phydev), phydev->drv->name, rev, patch);
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
case 0x01:
ret = bcm7xxx_28nm_a0_patch_afe_config_init(phydev);
break;
default:
break;
}
if (ret)
return ret;
ret = bcm_phy_downshift_get(phydev, &count);
if (ret)
return ret;
ret = bcm_phy_set_eee(phydev, count == DOWNSHIFT_DEV_DISABLE);
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
static int bcm7xxx_28nm_ephy_01_afe_config_init(struct phy_device *phydev)
{
int ret;
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST,
MII_BCM7XXX_SHD_MODE_2, 0);
if (ret < 0)
return ret;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_BIAS_TRIM, 0x3BE0);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_ADDR_CTRL,
MII_BCM7XXX_SHD_3_TL4);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_SHD_2_CTRL_STAT,
MII_BCM7XXX_TL4_RST_MSK, 0);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_ADDR_CTRL,
MII_BCM7XXX_SHD_3_TL4);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_SHD_2_CTRL_STAT,
0, MII_BCM7XXX_TL4_RST_MSK);
if (ret < 0)
goto reset_shadow_mode;
reset_shadow_mode:
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST, 0,
MII_BCM7XXX_SHD_MODE_2);
if (ret < 0)
return ret;
return 0;
}
static int bcm7xxx_28nm_ephy_apd_enable(struct phy_device *phydev)
{
int ret;
ret = phy_set_clr_bits(phydev, MII_BRCM_FET_BRCMTEST,
MII_BRCM_FET_BT_SRE, 0);
if (ret < 0)
return ret;
ret = phy_set_clr_bits(phydev, MII_BRCM_FET_SHDW_AUXSTAT2,
MII_BRCM_FET_SHDW_AS2_APDE, 0);
if (ret < 0)
return ret;
ret = phy_set_clr_bits(phydev, MII_BRCM_FET_BRCMTEST, 0,
MII_BRCM_FET_BT_SRE);
if (ret < 0)
return ret;
return 0;
}
static int bcm7xxx_28nm_ephy_eee_enable(struct phy_device *phydev)
{
int ret;
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST,
MII_BCM7XXX_SHD_MODE_2, 0);
if (ret < 0)
return ret;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_ADDR_CTRL,
MII_BCM7XXX_SHD_3_AN_EEE_ADV);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_CTRL_STAT,
MDIO_EEE_100TX);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_ADDR_CTRL,
MII_BCM7XXX_SHD_3_PCS_CTRL_2);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_CTRL_STAT,
MII_BCM7XXX_PCS_CTRL_2_DEF);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_ADDR_CTRL,
MII_BCM7XXX_SHD_3_EEE_THRESH);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_CTRL_STAT,
MII_BCM7XXX_EEE_THRESH_DEF);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_ADDR_CTRL,
MII_BCM7XXX_SHD_3_AN_STAT);
if (ret < 0)
goto reset_shadow_mode;
ret = phy_write(phydev, MII_BCM7XXX_SHD_2_CTRL_STAT,
(MII_BCM7XXX_AN_NULL_MSG_EN | MII_BCM7XXX_AN_EEE_EN));
if (ret < 0)
goto reset_shadow_mode;
reset_shadow_mode:
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST, 0,
MII_BCM7XXX_SHD_MODE_2);
if (ret < 0)
return ret;
phy_write(phydev, MII_BMCR,
(BMCR_SPEED100 | BMCR_ANENABLE | BMCR_ANRESTART));
return 0;
}
static int bcm7xxx_28nm_ephy_config_init(struct phy_device *phydev)
{
u8 rev = phydev->phy_id & ~phydev->drv->phy_id_mask;
int ret = 0;
pr_info_once("%s: %s PHY revision: 0x%02x\n",
phydev_name(phydev), phydev->drv->name, rev);
phy_read(phydev, MII_BMSR);
if (rev == 0x01) {
ret = bcm7xxx_28nm_ephy_01_afe_config_init(phydev);
if (ret)
return ret;
}
ret = bcm7xxx_28nm_ephy_eee_enable(phydev);
if (ret)
return ret;
return bcm7xxx_28nm_ephy_apd_enable(phydev);
}
static int bcm7xxx_28nm_ephy_resume(struct phy_device *phydev)
{
int ret;
ret = bcm7xxx_28nm_ephy_config_init(phydev);
if (ret)
return ret;
return genphy_config_aneg(phydev);
}
static int bcm7xxx_config_init(struct phy_device *phydev)
{
int ret;
phy_write(phydev, MII_BCM7XXX_AUX_MODE, MII_BCM7XXX_64CLK_MDIO);
phy_read(phydev, MII_BCM7XXX_AUX_MODE);
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST,
MII_BCM7XXX_SHD_MODE_2, MII_BCM7XXX_SHD_MODE_2);
if (ret < 0)
return ret;
phy_write(phydev, MII_BCM7XXX_100TX_DISC, 0x0F00);
udelay(10);
phy_write(phydev, MII_BCM7XXX_100TX_DISC, 0x0C00);
phy_write(phydev, MII_BCM7XXX_100TX_FALSE_CAR, 0x7555);
ret = phy_set_clr_bits(phydev, MII_BCM7XXX_TEST, 0, MII_BCM7XXX_SHD_MODE_2);
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
static int bcm7xxx_28nm_get_tunable(struct phy_device *phydev,
struct ethtool_tunable *tuna,
void *data)
{
switch (tuna->id) {
case ETHTOOL_PHY_DOWNSHIFT:
return bcm_phy_downshift_get(phydev, (u8 *)data);
default:
return -EOPNOTSUPP;
}
}
static int bcm7xxx_28nm_set_tunable(struct phy_device *phydev,
struct ethtool_tunable *tuna,
const void *data)
{
u8 count = *(u8 *)data;
int ret;
switch (tuna->id) {
case ETHTOOL_PHY_DOWNSHIFT:
ret = bcm_phy_downshift_set(phydev, count);
break;
default:
return -EOPNOTSUPP;
}
if (ret)
return ret;
ret = bcm_phy_set_eee(phydev, count == DOWNSHIFT_DEV_DISABLE);
if (ret)
return ret;
return genphy_restart_aneg(phydev);
}
static void bcm7xxx_28nm_get_phy_stats(struct phy_device *phydev,
struct ethtool_stats *stats, u64 *data)
{
struct bcm7xxx_phy_priv *priv = phydev->priv;
bcm_phy_get_stats(phydev, priv->stats, stats, data);
}
static int bcm7xxx_28nm_probe(struct phy_device *phydev)
{
struct bcm7xxx_phy_priv *priv;
priv = devm_kzalloc(&phydev->mdio.dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
phydev->priv = priv;
priv->stats = devm_kcalloc(&phydev->mdio.dev,
bcm_phy_get_sset_count(phydev), sizeof(u64),
GFP_KERNEL);
if (!priv->stats)
return -ENOMEM;
return 0;
}
