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
static void imx6q_restart(enum reboot_mode mode, const char *cmd)
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
phy_write(phydev, MICREL_KSZ9021_EXTREG_CTRL,
0x8000 | MICREL_KSZ9021_RGMII_RX_DATA_PAD_SCEW);
phy_write(phydev, MICREL_KSZ9021_EXTREG_DATA_WRITE, 0x0000);
phy_write(phydev, MICREL_KSZ9021_EXTREG_CTRL,
0x8000 | MICREL_KSZ9021_RGMII_CLK_CTRL_PAD_SCEW);
phy_write(phydev, MICREL_KSZ9021_EXTREG_DATA_WRITE, 0xf0f0);
phy_write(phydev, MICREL_KSZ9021_EXTREG_CTRL,
MICREL_KSZ9021_RGMII_CLK_CTRL_PAD_SCEW);
}
return 0;
}
static void mmd_write_reg(struct phy_device *dev, int device, int reg, int val)
{
phy_write(dev, 0x0d, device);
phy_write(dev, 0x0e, reg);
phy_write(dev, 0x0d, (1 << 14) | device);
phy_write(dev, 0x0e, val);
}
static int ksz9031rn_phy_fixup(struct phy_device *dev)
{
mmd_write_reg(dev, 2, 4, 0);
mmd_write_reg(dev, 2, 5, 0);
mmd_write_reg(dev, 2, 8, 0x003ff);
return 0;
}
static int ar8031_phy_fixup(struct phy_device *dev)
{
u16 val;
phy_write(dev, 0xd, 0x7);
phy_write(dev, 0xe, 0x8016);
phy_write(dev, 0xd, 0x4007);
val = phy_read(dev, 0xe);
val &= 0xffe3;
val |= 0x18;
phy_write(dev, 0xe, val);
phy_write(dev, 0x1d, 0x5);
val = phy_read(dev, 0x1e);
val |= 0x0100;
phy_write(dev, 0x1e, val);
return 0;
}
static void __init imx6q_enet_phy_init(void)
{
if (IS_BUILTIN(CONFIG_PHYLIB)) {
phy_register_fixup_for_uid(PHY_ID_KSZ9021, MICREL_PHY_ID_MASK,
ksz9021rn_phy_fixup);
phy_register_fixup_for_uid(PHY_ID_KSZ9031, MICREL_PHY_ID_MASK,
ksz9031rn_phy_fixup);
phy_register_fixup_for_uid(PHY_ID_AR8031, 0xffffffff,
ar8031_phy_fixup);
}
}
static void __init imx6q_1588_init(void)
{
struct regmap *gpr;
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (!IS_ERR(gpr))
regmap_update_bits(gpr, IOMUXC_GPR1,
IMX6Q_GPR1_ENET_CLK_SEL_MASK,
IMX6Q_GPR1_ENET_CLK_SEL_ANATOP);
else
pr_err("failed to find fsl,imx6q-iomux-gpr regmap\n");
}
static void __init imx6q_init_machine(void)
{
imx6q_enet_phy_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx_anatop_init();
imx6q_pm_init();
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
static void __init imx6q_opp_init(void)
{
struct device_node *np;
struct device *cpu_dev = get_cpu_device(0);
if (!cpu_dev) {
pr_warn("failed to get cpu0 device\n");
return;
}
np = of_node_get(cpu_dev->of_node);
if (!np) {
pr_warn("failed to find cpu0 node\n");
return;
}
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
imx6q_opp_init();
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
imx_init_l2cache();
imx_src_init();
imx_gpc_init();
irqchip_init();
}
static void __init imx6q_timer_init(void)
{
of_clk_init(NULL);
clocksource_of_init();
imx_print_silicon_rev(cpu_is_imx6dl() ? "i.MX6DL" : "i.MX6Q",
imx6q_revision());
}
