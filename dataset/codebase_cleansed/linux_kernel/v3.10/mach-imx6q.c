int imx6q_revision(void)
{
return chip_revision;
}
static void __init imx6q_init_revision(void)
{
u32 rev = imx_anatop_get_digprog();
switch (rev & 0xff) {
case 0:
chip_revision = IMX_CHIP_REVISION_1_0;
break;
case 1:
chip_revision = IMX_CHIP_REVISION_1_1;
break;
case 2:
chip_revision = IMX_CHIP_REVISION_1_2;
break;
default:
chip_revision = IMX_CHIP_REVISION_UNKNOWN;
}
mxc_set_cpu_type(rev >> 16 & 0xff);
}
static void imx6q_restart(char mode, const char *cmd)
{
struct device_node *np;
void __iomem *wdog_base;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-wdt");
wdog_base = of_iomap(np, 0);
if (!wdog_base)
goto soft;
imx_src_prepare_restart();
writew_relaxed(1 << 2, wdog_base);
writew_relaxed(1 << 2, wdog_base);
mdelay(500);
pr_err("Watchdog reset failed to assert reset\n");
mdelay(50);
soft:
soft_restart(0);
}
static int ksz9021rn_phy_fixup(struct phy_device *phydev)
{
if (IS_BUILTIN(CONFIG_PHYLIB)) {
phy_write(phydev, 0x0b, 0x8105);
phy_write(phydev, 0x0c, 0x0000);
phy_write(phydev, 0x0b, 0x8104);
phy_write(phydev, 0x0c, 0xf0f0);
phy_write(phydev, 0x0b, 0x104);
}
return 0;
}
static void __init imx6q_sabrelite_cko1_setup(void)
{
struct clk *cko1_sel, *ahb, *cko1;
unsigned long rate;
cko1_sel = clk_get_sys(NULL, "cko1_sel");
ahb = clk_get_sys(NULL, "ahb");
cko1 = clk_get_sys(NULL, "cko1");
if (IS_ERR(cko1_sel) || IS_ERR(ahb) || IS_ERR(cko1)) {
pr_err("cko1 setup failed!\n");
goto put_clk;
}
clk_set_parent(cko1_sel, ahb);
rate = clk_round_rate(cko1, 16000000);
clk_set_rate(cko1, rate);
put_clk:
if (!IS_ERR(cko1_sel))
clk_put(cko1_sel);
if (!IS_ERR(ahb))
clk_put(ahb);
if (!IS_ERR(cko1))
clk_put(cko1);
}
static void __init imx6q_sabrelite_init(void)
{
if (IS_BUILTIN(CONFIG_PHYLIB))
phy_register_fixup_for_uid(PHY_ID_KSZ9021, MICREL_PHY_ID_MASK,
ksz9021rn_phy_fixup);
imx6q_sabrelite_cko1_setup();
}
static void __init imx6q_1588_init(void)
{
struct regmap *gpr;
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (!IS_ERR(gpr))
regmap_update_bits(gpr, 0x4, 1 << 21, 1 << 21);
else
pr_err("failed to find fsl,imx6q-iomux-gpr regmap\n");
}
static void __init imx6q_usb_init(void)
{
imx_anatop_usb_chrg_detect_disable();
}
static void __init imx6q_init_machine(void)
{
if (of_machine_is_compatible("fsl,imx6q-sabrelite"))
imx6q_sabrelite_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx_anatop_init();
imx6q_pm_init();
imx6q_usb_init();
imx6q_1588_init();
}
static void __init imx6q_opp_check_1p2ghz(struct device *cpu_dev)
{
struct device_node *np;
void __iomem *base;
u32 val;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-ocotp");
if (!np) {
pr_warn("failed to find ocotp node\n");
return;
}
base = of_iomap(np, 0);
if (!base) {
pr_warn("failed to map ocotp\n");
goto put_node;
}
val = readl_relaxed(base + OCOTP_CFG3);
val >>= OCOTP_CFG3_SPEED_SHIFT;
if ((val & 0x3) != OCOTP_CFG3_SPEED_1P2GHZ)
if (opp_disable(cpu_dev, 1200000000))
pr_warn("failed to disable 1.2 GHz OPP\n");
put_node:
of_node_put(np);
}
static void __init imx6q_opp_init(struct device *cpu_dev)
{
struct device_node *np;
np = of_find_node_by_path("/cpus/cpu@0");
if (!np) {
pr_warn("failed to find cpu0 node\n");
return;
}
cpu_dev->of_node = np;
if (of_init_opp_table(cpu_dev)) {
pr_warn("failed to init OPP table\n");
goto put_node;
}
imx6q_opp_check_1p2ghz(cpu_dev);
put_node:
of_node_put(np);
}
static void __init imx6q_init_late(void)
{
if (imx6q_revision() > IMX_CHIP_REVISION_1_1)
imx6q_cpuidle_init();
if (IS_ENABLED(CONFIG_ARM_IMX6Q_CPUFREQ)) {
imx6q_opp_init(&imx6q_cpufreq_pdev.dev);
platform_device_register(&imx6q_cpufreq_pdev);
}
}
static void __init imx6q_map_io(void)
{
debug_ll_io_init();
imx_scu_map_io();
}
static void __init imx6q_init_irq(void)
{
imx6q_init_revision();
l2x0_of_init(0, ~0UL);
imx_src_init();
imx_gpc_init();
irqchip_init();
}
static void __init imx6q_timer_init(void)
{
mx6q_clocks_init();
clocksource_of_init();
imx_print_silicon_rev(cpu_is_imx6dl() ? "i.MX6DL" : "i.MX6Q",
imx6q_revision());
}
