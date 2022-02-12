static void hdmi_phy_8960_powerup(struct hdmi_phy *phy,
unsigned long int pixclock)
{
DBG("pixclock: %lu", pixclock);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG2, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG0, 0x1b);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG1, 0xf2);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG4, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG5, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG6, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG7, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG8, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG9, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG10, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG11, 0x00);
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG3, 0x20);
}
static void hdmi_phy_8960_powerdown(struct hdmi_phy *phy)
{
DBG("");
hdmi_phy_write(phy, REG_HDMI_8960_PHY_REG2, 0x7f);
}
