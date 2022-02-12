static int bcm87xx_of_reg_init(struct phy_device *phydev)
{
const __be32 *paddr;
const __be32 *paddr_end;
int len, ret;
if (!phydev->dev.of_node)
return 0;
paddr = of_get_property(phydev->dev.of_node,
"broadcom,c45-reg-init", &len);
if (!paddr)
return 0;
paddr_end = paddr + (len /= sizeof(*paddr));
ret = 0;
while (paddr + 3 < paddr_end) {
u16 devid = be32_to_cpup(paddr++);
u16 reg = be32_to_cpup(paddr++);
u16 mask = be32_to_cpup(paddr++);
u16 val_bits = be32_to_cpup(paddr++);
int val;
u32 regnum = MII_ADDR_C45 | (devid << 16) | reg;
val = 0;
if (mask) {
val = phy_read(phydev, regnum);
if (val < 0) {
ret = val;
goto err;
}
val &= mask;
}
val |= val_bits;
ret = phy_write(phydev, regnum, val);
if (ret < 0)
goto err;
}
err:
return ret;
}
static int bcm87xx_of_reg_init(struct phy_device *phydev)
{
return 0;
}
static int bcm87xx_config_init(struct phy_device *phydev)
{
phydev->supported = SUPPORTED_10000baseR_FEC;
phydev->advertising = ADVERTISED_10000baseR_FEC;
phydev->state = PHY_NOLINK;
phydev->autoneg = AUTONEG_DISABLE;
bcm87xx_of_reg_init(phydev);
return 0;
}
static int bcm87xx_config_aneg(struct phy_device *phydev)
{
return -EINVAL;
}
static int bcm87xx_read_status(struct phy_device *phydev)
{
int rx_signal_detect;
int pcs_status;
int xgxs_lane_status;
rx_signal_detect = phy_read(phydev, BCM87XX_PMD_RX_SIGNAL_DETECT);
if (rx_signal_detect < 0)
return rx_signal_detect;
if ((rx_signal_detect & 1) == 0)
goto no_link;
pcs_status = phy_read(phydev, BCM87XX_10GBASER_PCS_STATUS);
if (pcs_status < 0)
return pcs_status;
if ((pcs_status & 1) == 0)
goto no_link;
xgxs_lane_status = phy_read(phydev, BCM87XX_XGXS_LANE_STATUS);
if (xgxs_lane_status < 0)
return xgxs_lane_status;
if ((xgxs_lane_status & 0x1000) == 0)
goto no_link;
phydev->speed = 10000;
phydev->link = 1;
phydev->duplex = 1;
return 0;
no_link:
phydev->link = 0;
return 0;
}
static int bcm87xx_config_intr(struct phy_device *phydev)
{
int reg, err;
reg = phy_read(phydev, BCM87XX_LASI_CONTROL);
if (reg < 0)
return reg;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
reg |= 1;
else
reg &= ~1;
err = phy_write(phydev, BCM87XX_LASI_CONTROL, reg);
return err;
}
static int bcm87xx_did_interrupt(struct phy_device *phydev)
{
int reg;
reg = phy_read(phydev, BCM87XX_LASI_STATUS);
if (reg < 0) {
dev_err(&phydev->dev,
"Error: Read of BCM87XX_LASI_STATUS failed: %d\n", reg);
return 0;
}
return (reg & 1) != 0;
}
static int bcm87xx_ack_interrupt(struct phy_device *phydev)
{
bcm87xx_did_interrupt(phydev);
return 0;
}
static int bcm8706_match_phy_device(struct phy_device *phydev)
{
return phydev->c45_ids.device_ids[4] == PHY_ID_BCM8706;
}
static int bcm8727_match_phy_device(struct phy_device *phydev)
{
return phydev->c45_ids.device_ids[4] == PHY_ID_BCM8727;
}
static int __init bcm87xx_init(void)
{
return phy_drivers_register(bcm87xx_driver,
ARRAY_SIZE(bcm87xx_driver));
}
static void __exit bcm87xx_exit(void)
{
phy_drivers_unregister(bcm87xx_driver,
ARRAY_SIZE(bcm87xx_driver));
}
