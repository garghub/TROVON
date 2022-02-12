static int xway_gphy_config_init(struct phy_device *phydev)
{
int err;
u32 ledxh;
u32 ledxl;
err = phy_write(phydev, XWAY_MDIO_IMASK, 0);
if (err)
return err;
phy_read(phydev, XWAY_MDIO_ISTAT);
phy_write_mmd_indirect(phydev, XWAY_MMD_LEDCH, MDIO_MMD_VEND2,
XWAY_MMD_LEDCH_NACS_NONE |
XWAY_MMD_LEDCH_SBF_F02HZ |
XWAY_MMD_LEDCH_FBF_F16HZ);
phy_write_mmd_indirect(phydev, XWAY_MMD_LEDCL, MDIO_MMD_VEND2,
XWAY_MMD_LEDCH_CBLINK_NONE |
XWAY_MMD_LEDCH_SCAN_NONE);
ledxh = XWAY_MMD_LEDxH_BLINKF_NONE | XWAY_MMD_LEDxH_CON_LINK10XX;
ledxl = XWAY_MMD_LEDxL_PULSE_TXACT | XWAY_MMD_LEDxL_PULSE_RXACT |
XWAY_MMD_LEDxL_BLINKS_NONE;
phy_write_mmd_indirect(phydev, XWAY_MMD_LED0H, MDIO_MMD_VEND2, ledxh);
phy_write_mmd_indirect(phydev, XWAY_MMD_LED0L, MDIO_MMD_VEND2, ledxl);
phy_write_mmd_indirect(phydev, XWAY_MMD_LED1H, MDIO_MMD_VEND2, ledxh);
phy_write_mmd_indirect(phydev, XWAY_MMD_LED1L, MDIO_MMD_VEND2, ledxl);
phy_write_mmd_indirect(phydev, XWAY_MMD_LED2H, MDIO_MMD_VEND2, ledxh);
phy_write_mmd_indirect(phydev, XWAY_MMD_LED2L, MDIO_MMD_VEND2, ledxl);
return 0;
}
static int xway_gphy14_config_aneg(struct phy_device *phydev)
{
int reg, err;
reg = phy_read(phydev, MII_CTRL1000);
reg |= ADVERTISED_MPD;
err = phy_write(phydev, MII_CTRL1000, reg);
if (err)
return err;
return genphy_config_aneg(phydev);
}
static int xway_gphy_ack_interrupt(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, XWAY_MDIO_ISTAT);
return (reg < 0) ? reg : 0;
}
static int xway_gphy_did_interrupt(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, XWAY_MDIO_ISTAT);
return reg & XWAY_MDIO_INIT_MASK;
}
static int xway_gphy_config_intr(struct phy_device *phydev)
{
u16 mask = 0;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
mask = XWAY_MDIO_INIT_MASK;
return phy_write(phydev, XWAY_MDIO_IMASK, mask);
}
