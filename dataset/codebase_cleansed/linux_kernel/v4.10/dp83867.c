static int dp83867_ack_interrupt(struct phy_device *phydev)
{
int err = phy_read(phydev, MII_DP83867_ISR);
if (err < 0)
return err;
return 0;
}
static int dp83867_config_intr(struct phy_device *phydev)
{
int micr_status;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
micr_status = phy_read(phydev, MII_DP83867_MICR);
if (micr_status < 0)
return micr_status;
micr_status |=
(MII_DP83867_MICR_AN_ERR_INT_EN |
MII_DP83867_MICR_SPEED_CHNG_INT_EN |
MII_DP83867_MICR_AUTONEG_COMP_INT_EN |
MII_DP83867_MICR_LINK_STS_CHNG_INT_EN |
MII_DP83867_MICR_DUP_MODE_CHNG_INT_EN |
MII_DP83867_MICR_SLEEP_MODE_CHNG_INT_EN);
return phy_write(phydev, MII_DP83867_MICR, micr_status);
}
micr_status = 0x0;
return phy_write(phydev, MII_DP83867_MICR, micr_status);
}
static int dp83867_of_init(struct phy_device *phydev)
{
struct dp83867_private *dp83867 = phydev->priv;
struct device *dev = &phydev->mdio.dev;
struct device_node *of_node = dev->of_node;
int ret;
if (!of_node)
return -ENODEV;
dp83867->io_impedance = -EINVAL;
if (of_property_read_bool(of_node, "ti,max-output-impedance"))
dp83867->io_impedance = DP83867_IO_MUX_CFG_IO_IMPEDANCE_MAX;
else if (of_property_read_bool(of_node, "ti,min-output-impedance"))
dp83867->io_impedance = DP83867_IO_MUX_CFG_IO_IMPEDANCE_MIN;
ret = of_property_read_u32(of_node, "ti,rx-internal-delay",
&dp83867->rx_id_delay);
if (ret &&
(phydev->interface == PHY_INTERFACE_MODE_RGMII_ID ||
phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID))
return ret;
ret = of_property_read_u32(of_node, "ti,tx-internal-delay",
&dp83867->tx_id_delay);
if (ret &&
(phydev->interface == PHY_INTERFACE_MODE_RGMII_ID ||
phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID))
return ret;
return of_property_read_u32(of_node, "ti,fifo-depth",
&dp83867->fifo_depth);
}
static int dp83867_of_init(struct phy_device *phydev)
{
return 0;
}
static int dp83867_config_init(struct phy_device *phydev)
{
struct dp83867_private *dp83867;
int ret, val;
u16 delay;
if (!phydev->priv) {
dp83867 = devm_kzalloc(&phydev->mdio.dev, sizeof(*dp83867),
GFP_KERNEL);
if (!dp83867)
return -ENOMEM;
phydev->priv = dp83867;
ret = dp83867_of_init(phydev);
if (ret)
return ret;
} else {
dp83867 = (struct dp83867_private *)phydev->priv;
}
if (phy_interface_is_rgmii(phydev)) {
val = phy_read(phydev, MII_DP83867_PHYCTRL);
if (val < 0)
return val;
val &= ~DP83867_PHYCR_FIFO_DEPTH_MASK;
val |= (dp83867->fifo_depth << DP83867_PHYCR_FIFO_DEPTH_SHIFT);
ret = phy_write(phydev, MII_DP83867_PHYCTRL, val);
if (ret)
return ret;
}
if ((phydev->interface >= PHY_INTERFACE_MODE_RGMII_ID) &&
(phydev->interface <= PHY_INTERFACE_MODE_RGMII_RXID)) {
val = phy_read_mmd_indirect(phydev, DP83867_RGMIICTL,
DP83867_DEVADDR);
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_ID)
val |= (DP83867_RGMII_TX_CLK_DELAY_EN | DP83867_RGMII_RX_CLK_DELAY_EN);
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID)
val |= DP83867_RGMII_TX_CLK_DELAY_EN;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_RXID)
val |= DP83867_RGMII_RX_CLK_DELAY_EN;
phy_write_mmd_indirect(phydev, DP83867_RGMIICTL,
DP83867_DEVADDR, val);
delay = (dp83867->rx_id_delay |
(dp83867->tx_id_delay << DP83867_RGMII_TX_CLK_DELAY_SHIFT));
phy_write_mmd_indirect(phydev, DP83867_RGMIIDCTL,
DP83867_DEVADDR, delay);
if (dp83867->io_impedance >= 0) {
val = phy_read_mmd_indirect(phydev, DP83867_IO_MUX_CFG,
DP83867_DEVADDR);
val &= ~DP83867_IO_MUX_CFG_IO_IMPEDANCE_CTRL;
val |= dp83867->io_impedance &
DP83867_IO_MUX_CFG_IO_IMPEDANCE_CTRL;
phy_write_mmd_indirect(phydev, DP83867_IO_MUX_CFG,
DP83867_DEVADDR, val);
}
}
if (phy_interrupt_is_valid(phydev)) {
val = phy_read(phydev, DP83867_CFG3);
val |= BIT(7);
phy_write(phydev, DP83867_CFG3, val);
}
return 0;
}
static int dp83867_phy_reset(struct phy_device *phydev)
{
int err;
err = phy_write(phydev, DP83867_CTRL, DP83867_SW_RESET);
if (err < 0)
return err;
return dp83867_config_init(phydev);
}
