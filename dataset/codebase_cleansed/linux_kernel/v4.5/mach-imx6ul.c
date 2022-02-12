static void __init imx6ul_enet_clk_init(void)
{
struct regmap *gpr;
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6ul-iomuxc-gpr");
if (!IS_ERR(gpr))
regmap_update_bits(gpr, IOMUXC_GPR1, IMX6UL_GPR1_ENET_CLK_DIR,
IMX6UL_GPR1_ENET_CLK_OUTPUT);
else
pr_err("failed to find fsl,imx6ul-iomux-gpr regmap\n");
}
static int ksz8081_phy_fixup(struct phy_device *dev)
{
if (dev && dev->interface == PHY_INTERFACE_MODE_MII) {
phy_write(dev, 0x1f, 0x8110);
phy_write(dev, 0x16, 0x201);
} else if (dev && dev->interface == PHY_INTERFACE_MODE_RMII) {
phy_write(dev, 0x1f, 0x8190);
phy_write(dev, 0x16, 0x202);
}
return 0;
}
static void __init imx6ul_enet_phy_init(void)
{
if (IS_BUILTIN(CONFIG_PHYLIB))
phy_register_fixup_for_uid(PHY_ID_KSZ8081, 0xffffffff,
ksz8081_phy_fixup);
}
static inline void imx6ul_enet_init(void)
{
imx6ul_enet_clk_init();
imx6ul_enet_phy_init();
}
static void __init imx6ul_init_machine(void)
{
struct device *parent;
parent = imx_soc_device_init();
if (parent == NULL)
pr_warn("failed to initialize soc device\n");
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx6ul_enet_init();
imx_anatop_init();
imx6ul_pm_init();
}
static void __init imx6ul_init_irq(void)
{
imx_init_revision_from_anatop();
imx_src_init();
irqchip_init();
imx6_pm_ccm_init("fsl,imx6ul-ccm");
}
static void __init imx6ul_init_late(void)
{
if (IS_ENABLED(CONFIG_ARM_IMX6Q_CPUFREQ))
platform_device_register_simple("imx6q-cpufreq", -1, NULL, 0);
}
