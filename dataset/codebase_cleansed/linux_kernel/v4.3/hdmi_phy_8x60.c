static void hdmi_phy_8x60_destroy(struct hdmi_phy *phy)
{
struct hdmi_phy_8x60 *phy_8x60 = to_hdmi_phy_8x60(phy);
kfree(phy_8x60);
}
static void hdmi_phy_8x60_powerup(struct hdmi_phy *phy,
unsigned long int pixclock)
{
struct hdmi_phy_8x60 *phy_8x60 = to_hdmi_phy_8x60(phy);
struct hdmi *hdmi = phy_8x60->hdmi;
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG0,
HDMI_8x60_PHY_REG0_DESER_DEL_CTRL(3));
if (pixclock == 27000000) {
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG1,
HDMI_8x60_PHY_REG1_DTEST_MUX_SEL(5) |
HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL(3));
} else {
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG1,
HDMI_8x60_PHY_REG1_DTEST_MUX_SEL(5) |
HDMI_8x60_PHY_REG1_OUTVOL_SWING_CTRL(4));
}
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG2,
HDMI_8x60_PHY_REG2_PD_PWRGEN |
HDMI_8x60_PHY_REG2_PD_PLL |
HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
HDMI_8x60_PHY_REG2_PD_DESER);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG2,
HDMI_8x60_PHY_REG2_PD_PLL |
HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
HDMI_8x60_PHY_REG2_PD_DESER);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG2,
HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
HDMI_8x60_PHY_REG2_PD_DESER);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG3,
HDMI_8x60_PHY_REG3_PLL_ENABLE);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG9, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG12,
HDMI_8x60_PHY_REG12_RETIMING_EN |
HDMI_8x60_PHY_REG12_PLL_LOCK_DETECT_EN);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG2,
HDMI_8x60_PHY_REG2_PD_DESER);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG2,
HDMI_8x60_PHY_REG2_RCV_SENSE_EN |
HDMI_8x60_PHY_REG2_PD_DESER);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG4, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG5, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG6, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG7, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG8, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG9, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG10, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG11, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG12,
HDMI_8x60_PHY_REG12_RETIMING_EN |
HDMI_8x60_PHY_REG12_PLL_LOCK_DETECT_EN |
HDMI_8x60_PHY_REG12_FORCE_LOCK);
}
static void hdmi_phy_8x60_powerdown(struct hdmi_phy *phy)
{
struct hdmi_phy_8x60 *phy_8x60 = to_hdmi_phy_8x60(phy);
struct hdmi *hdmi = phy_8x60->hdmi;
hdmi_write(hdmi, REG_HDMI_PHY_CTRL,
HDMI_PHY_CTRL_SW_RESET);
udelay(10);
hdmi_write(hdmi, REG_HDMI_PHY_CTRL, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG2,
HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
HDMI_8x60_PHY_REG2_PD_DESER);
udelay(10);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG3, 0);
hdmi_write(hdmi, REG_HDMI_8x60_PHY_REG2,
HDMI_8x60_PHY_REG2_RCV_SENSE_EN |
HDMI_8x60_PHY_REG2_PD_PWRGEN |
HDMI_8x60_PHY_REG2_PD_PLL |
HDMI_8x60_PHY_REG2_PD_DRIVE_4 |
HDMI_8x60_PHY_REG2_PD_DRIVE_3 |
HDMI_8x60_PHY_REG2_PD_DRIVE_2 |
HDMI_8x60_PHY_REG2_PD_DRIVE_1 |
HDMI_8x60_PHY_REG2_PD_DESER);
}
struct hdmi_phy *hdmi_phy_8x60_init(struct hdmi *hdmi)
{
struct hdmi_phy_8x60 *phy_8x60;
struct hdmi_phy *phy = NULL;
int ret;
phy_8x60 = kzalloc(sizeof(*phy_8x60), GFP_KERNEL);
if (!phy_8x60) {
ret = -ENOMEM;
goto fail;
}
phy = &phy_8x60->base;
phy->funcs = &hdmi_phy_8x60_funcs;
phy_8x60->hdmi = hdmi;
return phy;
fail:
if (phy)
hdmi_phy_8x60_destroy(phy);
return ERR_PTR(ret);
}
