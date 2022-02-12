static void __init imx6sl_fec_init(void)
{
struct regmap *gpr;
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6sl-iomuxc-gpr");
if (!IS_ERR(gpr)) {
regmap_update_bits(gpr, IOMUXC_GPR1,
IMX6SL_GPR1_FEC_CLOCK_MUX2_SEL_MASK, 0);
regmap_update_bits(gpr, IOMUXC_GPR1,
IMX6SL_GPR1_FEC_CLOCK_MUX1_SEL_MASK, 0);
} else {
pr_err("failed to find fsl,imx6sl-iomux-gpr regmap\n");
}
}
static void __init imx6sl_init_late(void)
{
if (IS_ENABLED(CONFIG_ARM_IMX6Q_CPUFREQ))
platform_device_register_simple("imx6q-cpufreq", -1, NULL, 0);
}
static void __init imx6sl_init_machine(void)
{
struct device *parent;
mxc_arch_reset_init_dt();
parent = imx_soc_device_init();
if (parent == NULL)
pr_warn("failed to initialize soc device\n");
of_platform_populate(NULL, of_default_bus_match_table, NULL, parent);
imx6sl_fec_init();
imx_anatop_init();
imx6q_pm_init();
}
static void __init imx6sl_init_irq(void)
{
imx_init_revision_from_anatop();
imx_init_l2cache();
imx_src_init();
imx_gpc_init();
irqchip_init();
}
