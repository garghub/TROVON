static void hdmi_phy_8x74_powerup(struct hdmi_phy *phy,
unsigned long int pixclock)
{
hdmi_phy_write(phy, REG_HDMI_8x74_ANA_CFG0, 0x1b);
hdmi_phy_write(phy, REG_HDMI_8x74_ANA_CFG1, 0xf2);
hdmi_phy_write(phy, REG_HDMI_8x74_BIST_CFG0, 0x0);
hdmi_phy_write(phy, REG_HDMI_8x74_BIST_PATN0, 0x0);
hdmi_phy_write(phy, REG_HDMI_8x74_BIST_PATN1, 0x0);
hdmi_phy_write(phy, REG_HDMI_8x74_BIST_PATN2, 0x0);
hdmi_phy_write(phy, REG_HDMI_8x74_BIST_PATN3, 0x0);
hdmi_phy_write(phy, REG_HDMI_8x74_PD_CTRL1, 0x20);
}
static void hdmi_phy_8x74_powerdown(struct hdmi_phy *phy)
{
hdmi_phy_write(phy, REG_HDMI_8x74_PD_CTRL0, 0x7f);
}
