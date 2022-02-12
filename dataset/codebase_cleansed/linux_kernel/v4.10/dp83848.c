static int dp83848_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, DP83848_MISR);
return err < 0 ? err : 0;
}
static int dp83848_config_intr(struct phy_device *phydev)
{
int control, ret;
control = phy_read(phydev, DP83848_MICR);
if (control < 0)
return control;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
control |= DP83848_MICR_INT_OE;
control |= DP83848_MICR_INTEN;
ret = phy_write(phydev, DP83848_MISR, DP83848_INT_EN_MASK);
if (ret < 0)
return ret;
} else {
control &= ~DP83848_MICR_INTEN;
}
return phy_write(phydev, DP83848_MICR, control);
}
