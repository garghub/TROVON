static void at803x_set_wol_mac_addr(struct phy_device *phydev)
{
struct net_device *ndev = phydev->attached_dev;
const u8 *mac;
unsigned int i, offsets[] = {
AT803X_LOC_MAC_ADDR_32_47_OFFSET,
AT803X_LOC_MAC_ADDR_16_31_OFFSET,
AT803X_LOC_MAC_ADDR_0_15_OFFSET,
};
if (!ndev)
return;
mac = (const u8 *) ndev->dev_addr;
if (!is_valid_ether_addr(mac))
return;
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
}
static int at803x_config_init(struct phy_device *phydev)
{
int val;
u32 features;
int status;
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
at803x_set_wol_mac_addr(phydev);
status = phy_write(phydev, AT803X_INTR_ENABLE, AT803X_WOL_ENABLE);
status = phy_read(phydev, AT803X_INTR_STATUS);
return 0;
}
static int __init atheros_init(void)
{
int ret;
ret = phy_driver_register(&at8035_driver);
if (ret)
goto err1;
ret = phy_driver_register(&at8030_driver);
if (ret)
goto err2;
return 0;
err2:
phy_driver_unregister(&at8035_driver);
err1:
return ret;
}
static void __exit atheros_exit(void)
{
phy_driver_unregister(&at8035_driver);
phy_driver_unregister(&at8030_driver);
}
