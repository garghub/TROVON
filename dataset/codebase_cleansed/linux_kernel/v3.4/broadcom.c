static int bcm54xx_shadow_read(struct phy_device *phydev, u16 shadow)
{
phy_write(phydev, MII_BCM54XX_SHD, MII_BCM54XX_SHD_VAL(shadow));
return MII_BCM54XX_SHD_DATA(phy_read(phydev, MII_BCM54XX_SHD));
}
static int bcm54xx_shadow_write(struct phy_device *phydev, u16 shadow, u16 val)
{
return phy_write(phydev, MII_BCM54XX_SHD,
MII_BCM54XX_SHD_WRITE |
MII_BCM54XX_SHD_VAL(shadow) |
MII_BCM54XX_SHD_DATA(val));
}
static int bcm54xx_exp_read(struct phy_device *phydev, u16 regnum)
{
int val;
val = phy_write(phydev, MII_BCM54XX_EXP_SEL, regnum);
if (val < 0)
return val;
val = phy_read(phydev, MII_BCM54XX_EXP_DATA);
phy_write(phydev, MII_BCM54XX_EXP_SEL, 0);
return val;
}
static int bcm54xx_exp_write(struct phy_device *phydev, u16 regnum, u16 val)
{
int ret;
ret = phy_write(phydev, MII_BCM54XX_EXP_SEL, regnum);
if (ret < 0)
return ret;
ret = phy_write(phydev, MII_BCM54XX_EXP_DATA, val);
phy_write(phydev, MII_BCM54XX_EXP_SEL, 0);
return ret;
}
static int bcm54xx_auxctl_write(struct phy_device *phydev, u16 regnum, u16 val)
{
return phy_write(phydev, MII_BCM54XX_AUX_CTL, regnum | val);
}
static int bcm50610_a0_workaround(struct phy_device *phydev)
{
int err;
err = bcm54xx_exp_write(phydev, MII_BCM54XX_EXP_AADJ1CH0,
MII_BCM54XX_EXP_AADJ1CH0_SWP_ABCD_OEN |
MII_BCM54XX_EXP_AADJ1CH0_SWSEL_THPF);
if (err < 0)
return err;
err = bcm54xx_exp_write(phydev, MII_BCM54XX_EXP_AADJ1CH3,
MII_BCM54XX_EXP_AADJ1CH3_ADCCKADJ);
if (err < 0)
return err;
err = bcm54xx_exp_write(phydev, MII_BCM54XX_EXP_EXP75,
MII_BCM54XX_EXP_EXP75_VDACCTRL);
if (err < 0)
return err;
err = bcm54xx_exp_write(phydev, MII_BCM54XX_EXP_EXP96,
MII_BCM54XX_EXP_EXP96_MYST);
if (err < 0)
return err;
err = bcm54xx_exp_write(phydev, MII_BCM54XX_EXP_EXP97,
MII_BCM54XX_EXP_EXP97_MYST);
return err;
}
static int bcm54xx_phydsp_config(struct phy_device *phydev)
{
int err, err2;
err = bcm54xx_auxctl_write(phydev,
MII_BCM54XX_AUXCTL_SHDWSEL_AUXCTL,
MII_BCM54XX_AUXCTL_ACTL_SMDSP_ENA |
MII_BCM54XX_AUXCTL_ACTL_TX_6DB);
if (err < 0)
return err;
if (BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610 ||
BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610M) {
err = bcm54xx_exp_write(phydev, MII_BCM54XX_EXP_EXP08,
MII_BCM54XX_EXP_EXP08_RJCT_2MHZ);
if (err < 0)
goto error;
if (phydev->drv->phy_id == PHY_ID_BCM50610) {
err = bcm50610_a0_workaround(phydev);
if (err < 0)
goto error;
}
}
if (BRCM_PHY_MODEL(phydev) == PHY_ID_BCM57780) {
int val;
val = bcm54xx_exp_read(phydev, MII_BCM54XX_EXP_EXP75);
if (val < 0)
goto error;
val |= MII_BCM54XX_EXP_EXP75_CM_OSC;
err = bcm54xx_exp_write(phydev, MII_BCM54XX_EXP_EXP75, val);
}
error:
err2 = bcm54xx_auxctl_write(phydev,
MII_BCM54XX_AUXCTL_SHDWSEL_AUXCTL,
MII_BCM54XX_AUXCTL_ACTL_TX_6DB);
return err ? err : err2;
}
static void bcm54xx_adjust_rxrefclk(struct phy_device *phydev)
{
u32 orig;
int val;
bool clk125en = true;
if (BRCM_PHY_MODEL(phydev) != PHY_ID_BCM57780 &&
BRCM_PHY_MODEL(phydev) != PHY_ID_BCM50610 &&
BRCM_PHY_MODEL(phydev) != PHY_ID_BCM50610M)
return;
val = bcm54xx_shadow_read(phydev, BCM54XX_SHD_SCR3);
if (val < 0)
return;
orig = val;
if ((BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610 ||
BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610M) &&
BRCM_PHY_REV(phydev) >= 0x3) {
clk125en = false;
} else {
if (phydev->dev_flags & PHY_BRCM_RX_REFCLK_UNUSED) {
val &= ~BCM54XX_SHD_SCR3_DEF_CLK125;
clk125en = false;
}
}
if (!clk125en || (phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE))
val &= ~BCM54XX_SHD_SCR3_DLLAPD_DIS;
else
val |= BCM54XX_SHD_SCR3_DLLAPD_DIS;
if (phydev->dev_flags & PHY_BRCM_DIS_TXCRXC_NOENRGY)
val |= BCM54XX_SHD_SCR3_TRDDAPD;
if (orig != val)
bcm54xx_shadow_write(phydev, BCM54XX_SHD_SCR3, val);
val = bcm54xx_shadow_read(phydev, BCM54XX_SHD_APD);
if (val < 0)
return;
orig = val;
if (!clk125en || (phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE))
val |= BCM54XX_SHD_APD_EN;
else
val &= ~BCM54XX_SHD_APD_EN;
if (orig != val)
bcm54xx_shadow_write(phydev, BCM54XX_SHD_APD, val);
}
static int bcm54xx_config_init(struct phy_device *phydev)
{
int reg, err;
reg = phy_read(phydev, MII_BCM54XX_ECR);
if (reg < 0)
return reg;
reg |= MII_BCM54XX_ECR_IM;
err = phy_write(phydev, MII_BCM54XX_ECR, reg);
if (err < 0)
return err;
reg = ~(MII_BCM54XX_INT_DUPLEX |
MII_BCM54XX_INT_SPEED |
MII_BCM54XX_INT_LINK);
err = phy_write(phydev, MII_BCM54XX_IMR, reg);
if (err < 0)
return err;
if ((BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610 ||
BRCM_PHY_MODEL(phydev) == PHY_ID_BCM50610M) &&
(phydev->dev_flags & PHY_BRCM_CLEAR_RGMII_MODE))
bcm54xx_shadow_write(phydev, BCM54XX_SHD_RGMII_MODE, 0);
if ((phydev->dev_flags & PHY_BRCM_RX_REFCLK_UNUSED) ||
(phydev->dev_flags & PHY_BRCM_DIS_TXCRXC_NOENRGY) ||
(phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE))
bcm54xx_adjust_rxrefclk(phydev);
bcm54xx_phydsp_config(phydev);
return 0;
}
static int bcm5482_config_init(struct phy_device *phydev)
{
int err, reg;
err = bcm54xx_config_init(phydev);
if (phydev->dev_flags & PHY_BCM_FLAGS_MODE_1000BX) {
reg = bcm54xx_shadow_read(phydev, BCM5482_SHD_SSD);
bcm54xx_shadow_write(phydev, BCM5482_SHD_SSD,
reg |
BCM5482_SHD_SSD_LEDM |
BCM5482_SHD_SSD_EN);
reg = BCM5482_SSD_SGMII_SLAVE | MII_BCM54XX_EXP_SEL_SSD;
err = bcm54xx_exp_read(phydev, reg);
if (err < 0)
return err;
err = bcm54xx_exp_write(phydev, reg, err |
BCM5482_SSD_SGMII_SLAVE_EN |
BCM5482_SSD_SGMII_SLAVE_AD);
if (err < 0)
return err;
reg = BCM5482_SSD_1000BX_CTL | MII_BCM54XX_EXP_SEL_SSD;
err = bcm54xx_exp_read(phydev, reg);
if (err < 0)
return err;
err = bcm54xx_exp_write(phydev, reg,
err & ~BCM5482_SSD_1000BX_CTL_PWRDOWN);
if (err < 0)
return err;
reg = bcm54xx_shadow_read(phydev, BCM5482_SHD_MODE);
bcm54xx_shadow_write(phydev, BCM5482_SHD_MODE,
reg | BCM5482_SHD_MODE_1000BX);
bcm54xx_shadow_write(phydev, BCM5482_SHD_LEDS1,
BCM5482_SHD_LEDS1_LED1(BCM_LED_SRC_ACTIVITYLED) |
BCM5482_SHD_LEDS1_LED3(BCM_LED_SRC_LINKSPD2));
phydev->autoneg = AUTONEG_DISABLE;
phydev->speed = SPEED_1000;
phydev->duplex = DUPLEX_FULL;
}
return err;
}
static int bcm5482_read_status(struct phy_device *phydev)
{
int err;
err = genphy_read_status(phydev);
if (phydev->dev_flags & PHY_BCM_FLAGS_MODE_1000BX) {
if (phydev->link) {
phydev->speed = SPEED_1000;
phydev->duplex = DUPLEX_FULL;
}
}
return err;
}
static int bcm54xx_ack_interrupt(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_BCM54XX_ISR);
if (reg < 0)
return reg;
return 0;
}
static int bcm54xx_config_intr(struct phy_device *phydev)
{
int reg, err;
reg = phy_read(phydev, MII_BCM54XX_ECR);
if (reg < 0)
return reg;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
reg &= ~MII_BCM54XX_ECR_IM;
else
reg |= MII_BCM54XX_ECR_IM;
err = phy_write(phydev, MII_BCM54XX_ECR, reg);
return err;
}
static int bcm5481_config_aneg(struct phy_device *phydev)
{
int ret;
ret = genphy_config_aneg(phydev);
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID) {
u16 reg;
reg = 0x7 | (0x7 << 12);
phy_write(phydev, 0x18, reg);
reg = phy_read(phydev, 0x18);
reg |= (1 << 8);
reg |= (1 << 15);
phy_write(phydev, 0x18, reg);
}
return ret;
}
static int brcm_phy_setbits(struct phy_device *phydev, int reg, int set)
{
int val;
val = phy_read(phydev, reg);
if (val < 0)
return val;
return phy_write(phydev, reg, val | set);
}
static int brcm_fet_config_init(struct phy_device *phydev)
{
int reg, err, err2, brcmtest;
err = phy_write(phydev, MII_BMCR, BMCR_RESET);
if (err < 0)
return err;
reg = phy_read(phydev, MII_BRCM_FET_INTREG);
if (reg < 0)
return reg;
reg = MII_BRCM_FET_IR_DUPLEX_EN |
MII_BRCM_FET_IR_SPEED_EN |
MII_BRCM_FET_IR_LINK_EN |
MII_BRCM_FET_IR_ENABLE |
MII_BRCM_FET_IR_MASK;
err = phy_write(phydev, MII_BRCM_FET_INTREG, reg);
if (err < 0)
return err;
brcmtest = phy_read(phydev, MII_BRCM_FET_BRCMTEST);
if (brcmtest < 0)
return brcmtest;
reg = brcmtest | MII_BRCM_FET_BT_SRE;
err = phy_write(phydev, MII_BRCM_FET_BRCMTEST, reg);
if (err < 0)
return err;
reg = phy_read(phydev, MII_BRCM_FET_SHDW_AUXMODE4);
if (reg < 0) {
err = reg;
goto done;
}
reg &= ~MII_BRCM_FET_SHDW_AM4_LED_MASK;
reg |= MII_BRCM_FET_SHDW_AM4_LED_MODE1;
err = phy_write(phydev, MII_BRCM_FET_SHDW_AUXMODE4, reg);
if (err < 0)
goto done;
err = brcm_phy_setbits(phydev, MII_BRCM_FET_SHDW_MISCCTRL,
MII_BRCM_FET_SHDW_MC_FAME);
if (err < 0)
goto done;
if (phydev->dev_flags & PHY_BRCM_AUTO_PWRDWN_ENABLE) {
err = brcm_phy_setbits(phydev, MII_BRCM_FET_SHDW_AUXSTAT2,
MII_BRCM_FET_SHDW_AS2_APDE);
}
done:
err2 = phy_write(phydev, MII_BRCM_FET_BRCMTEST, brcmtest);
if (!err)
err = err2;
return err;
}
static int brcm_fet_ack_interrupt(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, MII_BRCM_FET_INTREG);
if (reg < 0)
return reg;
return 0;
}
static int brcm_fet_config_intr(struct phy_device *phydev)
{
int reg, err;
reg = phy_read(phydev, MII_BRCM_FET_INTREG);
if (reg < 0)
return reg;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
reg &= ~MII_BRCM_FET_IR_MASK;
else
reg |= MII_BRCM_FET_IR_MASK;
err = phy_write(phydev, MII_BRCM_FET_INTREG, reg);
return err;
}
static int __init broadcom_init(void)
{
int ret;
ret = phy_driver_register(&bcm5411_driver);
if (ret)
goto out_5411;
ret = phy_driver_register(&bcm5421_driver);
if (ret)
goto out_5421;
ret = phy_driver_register(&bcm5461_driver);
if (ret)
goto out_5461;
ret = phy_driver_register(&bcm5464_driver);
if (ret)
goto out_5464;
ret = phy_driver_register(&bcm5481_driver);
if (ret)
goto out_5481;
ret = phy_driver_register(&bcm5482_driver);
if (ret)
goto out_5482;
ret = phy_driver_register(&bcm50610_driver);
if (ret)
goto out_50610;
ret = phy_driver_register(&bcm50610m_driver);
if (ret)
goto out_50610m;
ret = phy_driver_register(&bcm57780_driver);
if (ret)
goto out_57780;
ret = phy_driver_register(&bcmac131_driver);
if (ret)
goto out_ac131;
ret = phy_driver_register(&bcm5241_driver);
if (ret)
goto out_5241;
return ret;
out_5241:
phy_driver_unregister(&bcmac131_driver);
out_ac131:
phy_driver_unregister(&bcm57780_driver);
out_57780:
phy_driver_unregister(&bcm50610m_driver);
out_50610m:
phy_driver_unregister(&bcm50610_driver);
out_50610:
phy_driver_unregister(&bcm5482_driver);
out_5482:
phy_driver_unregister(&bcm5481_driver);
out_5481:
phy_driver_unregister(&bcm5464_driver);
out_5464:
phy_driver_unregister(&bcm5461_driver);
out_5461:
phy_driver_unregister(&bcm5421_driver);
out_5421:
phy_driver_unregister(&bcm5411_driver);
out_5411:
return ret;
}
static void __exit broadcom_exit(void)
{
phy_driver_unregister(&bcm5241_driver);
phy_driver_unregister(&bcmac131_driver);
phy_driver_unregister(&bcm57780_driver);
phy_driver_unregister(&bcm50610m_driver);
phy_driver_unregister(&bcm50610_driver);
phy_driver_unregister(&bcm5482_driver);
phy_driver_unregister(&bcm5481_driver);
phy_driver_unregister(&bcm5464_driver);
phy_driver_unregister(&bcm5461_driver);
phy_driver_unregister(&bcm5421_driver);
phy_driver_unregister(&bcm5411_driver);
}
