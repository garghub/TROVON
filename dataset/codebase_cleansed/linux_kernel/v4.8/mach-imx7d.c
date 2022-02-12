static int ar8031_phy_fixup(struct phy_device *dev)
{
u16 val;
phy_write(dev, 0x1d, 0x1f);
phy_write(dev, 0x1e, 0x8);
phy_write(dev, 0xd, 0x3);
phy_write(dev, 0xe, 0x805d);
phy_write(dev, 0xd, 0x4003);
val = phy_read(dev, 0xe);
val &= ~(0x1 << 8);
phy_write(dev, 0xe, val);
phy_write(dev, 0x1d, 0x5);
val = phy_read(dev, 0x1e);
val |= 0x0100;
phy_write(dev, 0x1e, val);
return 0;
}
static int bcm54220_phy_fixup(struct phy_device *dev)
{
phy_write(dev, 0x1e, 0x21);
phy_write(dev, 0x1f, 0x7ea8);
phy_write(dev, 0x1e, 0x2f);
phy_write(dev, 0x1f, 0x71b7);
return 0;
}
static void __init imx7d_enet_phy_init(void)
{
if (IS_BUILTIN(CONFIG_PHYLIB)) {
phy_register_fixup_for_uid(PHY_ID_AR8031, 0xffffffff,
ar8031_phy_fixup);
phy_register_fixup_for_uid(PHY_ID_BCM54220, 0xffffffff,
bcm54220_phy_fixup);
}
}
static void __init imx7d_enet_clk_sel(void)
{
struct regmap *gpr;
gpr = syscon_regmap_lookup_by_compatible("fsl,imx7d-iomuxc-gpr");
if (!IS_ERR(gpr)) {
regmap_update_bits(gpr, IOMUXC_GPR1, IMX7D_GPR1_ENET_TX_CLK_SEL_MASK, 0);
regmap_update_bits(gpr, IOMUXC_GPR1, IMX7D_GPR1_ENET_CLK_DIR_MASK, 0);
} else {
pr_err("failed to find fsl,imx7d-iomux-gpr regmap\n");
}
}
static inline void imx7d_enet_init(void)
{
imx7d_enet_phy_init();
imx7d_enet_clk_sel();
}
static void __init imx7d_init_machine(void)
{
struct device *parent;
parent = imx_soc_device_init();
if (parent == NULL)
pr_warn("failed to initialize soc device\n");
imx_anatop_init();
imx7d_enet_init();
}
static void __init imx7d_init_irq(void)
{
imx_init_revision_from_anatop();
imx_src_init();
irqchip_init();
}
