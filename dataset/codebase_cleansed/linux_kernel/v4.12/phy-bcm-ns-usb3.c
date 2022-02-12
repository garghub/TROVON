static int bcm_ns_usb3_wait_reg(struct bcm_ns_usb3 *usb3, void __iomem *addr,
u32 mask, u32 value, unsigned long timeout)
{
unsigned long deadline = jiffies + timeout;
u32 val;
do {
val = readl(addr);
if ((val & mask) == value)
return 0;
cpu_relax();
udelay(10);
} while (!time_after_eq(jiffies, deadline));
dev_err(usb3->dev, "Timeout waiting for register %p\n", addr);
return -EBUSY;
}
static inline int bcm_ns_usb3_mii_mng_wait_idle(struct bcm_ns_usb3 *usb3)
{
return bcm_ns_usb3_wait_reg(usb3, usb3->ccb_mii + BCMA_CCB_MII_MNG_CTL,
0x0100, 0x0000,
usecs_to_jiffies(BCM_NS_USB3_MII_MNG_TIMEOUT_US));
}
static int bcm_ns_usb3_mdio_phy_write(struct bcm_ns_usb3 *usb3, u16 reg,
u16 value)
{
u32 tmp = 0;
int err;
err = bcm_ns_usb3_mii_mng_wait_idle(usb3);
if (err < 0) {
dev_err(usb3->dev, "Couldn't write 0x%08x value\n", value);
return err;
}
tmp |= 0x58020000;
tmp |= reg << 18;
tmp |= value;
writel(tmp, usb3->ccb_mii + BCMA_CCB_MII_MNG_CMD_DATA);
return 0;
}
static int bcm_ns_usb3_phy_init_ns_bx(struct bcm_ns_usb3 *usb3)
{
int err;
writel(0x0000009a, usb3->ccb_mii + BCMA_CCB_MII_MNG_CTL);
udelay(2);
err = bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PHY_BASE_ADDR_REG,
BCM_NS_USB3_PHY_PLL30_BLOCK);
if (err < 0)
return err;
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PLL_CONTROL, 0x1000);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PLLA_CONTROL0, 0x6400);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PLLA_CONTROL1, 0xc000);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PLLA_CONTROL1, 0x8000);
bcm_ns_usb3_mii_mng_wait_idle(usb3);
writel(0, usb3->dmp + BCMA_RESET_CTL);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PLL_CONTROL, 0x9000);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PHY_BASE_ADDR_REG,
BCM_NS_USB3_PHY_PIPE_BLOCK);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_LFPS_CMP, 0xf30d);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_LFPS_DEGLITCH, 0x6302);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PHY_BASE_ADDR_REG,
BCM_NS_USB3_PHY_TX_PMD_BLOCK);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_TX_PMD_CONTROL1, 0x1003);
bcm_ns_usb3_mii_mng_wait_idle(usb3);
return 0;
}
static int bcm_ns_usb3_phy_init_ns_ax(struct bcm_ns_usb3 *usb3)
{
int err;
writel(0x0000009a, usb3->ccb_mii + BCMA_CCB_MII_MNG_CTL);
udelay(2);
err = bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PHY_BASE_ADDR_REG,
BCM_NS_USB3_PHY_PLL30_BLOCK);
if (err < 0)
return err;
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PLLA_CONTROL0, 0x6400);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PHY_BASE_ADDR_REG, 0x80e0);
bcm_ns_usb3_mdio_phy_write(usb3, 0x02, 0x009c);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_PHY_BASE_ADDR_REG,
BCM_NS_USB3_PHY_TX_PMD_BLOCK);
bcm_ns_usb3_mdio_phy_write(usb3, 0x02, 0x21d3);
bcm_ns_usb3_mdio_phy_write(usb3, BCM_NS_USB3_TX_PMD_CONTROL1, 0x1003);
bcm_ns_usb3_mii_mng_wait_idle(usb3);
writel(0, usb3->dmp + BCMA_RESET_CTL);
return 0;
}
static int bcm_ns_usb3_phy_init(struct phy *phy)
{
struct bcm_ns_usb3 *usb3 = phy_get_drvdata(phy);
int err;
writel(BCMA_RESET_CTL_RESET, usb3->dmp + BCMA_RESET_CTL);
switch (usb3->family) {
case BCM_NS_AX:
err = bcm_ns_usb3_phy_init_ns_ax(usb3);
break;
case BCM_NS_BX:
err = bcm_ns_usb3_phy_init_ns_bx(usb3);
break;
default:
WARN_ON(1);
err = -ENOTSUPP;
}
return err;
}
static int bcm_ns_usb3_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
struct bcm_ns_usb3 *usb3;
struct resource *res;
struct phy_provider *phy_provider;
usb3 = devm_kzalloc(dev, sizeof(*usb3), GFP_KERNEL);
if (!usb3)
return -ENOMEM;
usb3->dev = dev;
of_id = of_match_device(bcm_ns_usb3_id_table, dev);
if (!of_id)
return -EINVAL;
usb3->family = (enum bcm_ns_family)of_id->data;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dmp");
usb3->dmp = devm_ioremap_resource(dev, res);
if (IS_ERR(usb3->dmp)) {
dev_err(dev, "Failed to map DMP regs\n");
return PTR_ERR(usb3->dmp);
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "ccb-mii");
usb3->ccb_mii = devm_ioremap_resource(dev, res);
if (IS_ERR(usb3->ccb_mii)) {
dev_err(dev, "Failed to map ChipCommon B MII regs\n");
return PTR_ERR(usb3->ccb_mii);
}
usb3->phy = devm_phy_create(dev, NULL, &ops);
if (IS_ERR(usb3->phy)) {
dev_err(dev, "Failed to create PHY\n");
return PTR_ERR(usb3->phy);
}
phy_set_drvdata(usb3->phy, usb3);
platform_set_drvdata(pdev, usb3);
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (!IS_ERR(phy_provider))
dev_info(dev, "Registered Broadcom Northstar USB 3.0 PHY driver\n");
return PTR_ERR_OR_ZERO(phy_provider);
}
