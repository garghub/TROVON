static int at803x_set_wol(struct phy_device *phydev,
struct ethtool_wolinfo *wol)
{
struct net_device *ndev = phydev->attached_dev;
const u8 *mac;
int ret;
u32 value;
unsigned int i, offsets[] = {
AT803X_LOC_MAC_ADDR_32_47_OFFSET,
AT803X_LOC_MAC_ADDR_16_31_OFFSET,
AT803X_LOC_MAC_ADDR_0_15_OFFSET,
};
if (!ndev)
return -ENODEV;
if (wol->wolopts & WAKE_MAGIC) {
mac = (const u8 *) ndev->dev_addr;
if (!is_valid_ether_addr(mac))
return -EFAULT;
for (i = 0; i < 3; i++) {
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL,
AT803X_DEVICE_ADDR);
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL_DATA,
offsets[i]);
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL,
AT803X_FUNC_DATA);
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL_DATA,
mac[(i * 2) + 1] | (mac[(i * 2)] << 8));
}
value = phy_read(phydev, AT803X_INTR_ENABLE);
value |= AT803X_WOL_ENABLE;
ret = phy_write(phydev, AT803X_INTR_ENABLE, value);
if (ret)
return ret;
value = phy_read(phydev, AT803X_INTR_STATUS);
} else {
value = phy_read(phydev, AT803X_INTR_ENABLE);
value &= (~AT803X_WOL_ENABLE);
ret = phy_write(phydev, AT803X_INTR_ENABLE, value);
if (ret)
return ret;
value = phy_read(phydev, AT803X_INTR_STATUS);
}
return ret;
}
static void at803x_get_wol(struct phy_device *phydev,
struct ethtool_wolinfo *wol)
{
u32 value;
wol->supported = WAKE_MAGIC;
wol->wolopts = 0;
value = phy_read(phydev, AT803X_INTR_ENABLE);
if (value & AT803X_WOL_ENABLE)
wol->wolopts |= WAKE_MAGIC;
}
static int at803x_config_init(struct phy_device *phydev)
{
int val;
int ret;
u32 features;
features = SUPPORTED_TP | SUPPORTED_MII | SUPPORTED_AUI |
SUPPORTED_FIBRE | SUPPORTED_BNC;
val = phy_read(phydev, MII_BMSR);
if (val < 0)
return val;
if (val & BMSR_ANEGCAPABLE)
features |= SUPPORTED_Autoneg;
if (val & BMSR_100FULL)
features |= SUPPORTED_100baseT_Full;
if (val & BMSR_100HALF)
features |= SUPPORTED_100baseT_Half;
if (val & BMSR_10FULL)
features |= SUPPORTED_10baseT_Full;
if (val & BMSR_10HALF)
features |= SUPPORTED_10baseT_Half;
if (val & BMSR_ESTATEN) {
val = phy_read(phydev, MII_ESTATUS);
if (val < 0)
return val;
if (val & ESTATUS_1000_TFULL)
features |= SUPPORTED_1000baseT_Full;
if (val & ESTATUS_1000_THALF)
features |= SUPPORTED_1000baseT_Half;
}
phydev->supported = features;
phydev->advertising = features;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID) {
ret = phy_write(phydev, AT803X_DEBUG_ADDR,
AT803X_DEBUG_SYSTEM_MODE_CTRL);
if (ret)
return ret;
ret = phy_write(phydev, AT803X_DEBUG_DATA,
AT803X_DEBUG_RGMII_TX_CLK_DLY);
if (ret)
return ret;
}
return 0;
}
static int __init atheros_init(void)
{
return phy_drivers_register(at803x_driver,
ARRAY_SIZE(at803x_driver));
}
static void __exit atheros_exit(void)
{
return phy_drivers_unregister(at803x_driver,
ARRAY_SIZE(at803x_driver));
}
