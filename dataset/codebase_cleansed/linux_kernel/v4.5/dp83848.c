static int dp83848_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, DP83848_MISR);
return err < 0 ? err : 0;
}
static int dp83848_config_intr(struct phy_device *phydev)
{
int err;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
err = phy_write(phydev, DP83848_MICR,
DP83848_MICR_INT_OE |
DP83848_MICR_INTEN);
if (err < 0)
return err;
return phy_write(phydev, DP83848_MISR,
DP83848_MISR_ANC_INT_EN |
DP83848_MISR_DUP_INT_EN |
DP83848_MISR_SPD_INT_EN |
DP83848_MISR_LINK_INT_EN);
}
return phy_write(phydev, DP83848_MICR, 0x0);
}
