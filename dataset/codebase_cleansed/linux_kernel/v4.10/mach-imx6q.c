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
static void ventana_pciesw_early_fixup(struct pci_dev *dev)
{
u32 dw;
if (!of_machine_is_compatible("gw,ventana"))
return;
if (dev->devfn != 0)
return;
pci_read_config_dword(dev, 0x62c, &dw);
dw |= 0xaaa8;
pci_write_config_dword(dev, 0x62c, dw);
pci_read_config_dword(dev, 0x644, &dw);
dw |= 0xfe;
pci_write_config_dword(dev, 0x644, dw);
msleep(100);
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
static int ar8035_phy_fixup(struct phy_device *dev)
{
u16 val;
phy_write(dev, 0xd, 0x3);
phy_write(dev, 0xe, 0x805d);
phy_write(dev, 0xd, 0x4003);
val = phy_read(dev, 0xe);
phy_write(dev, 0xe, val & ~(1 << 8));
ar8031_phy_fixup(dev);
val = phy_read(dev, 0x0);
if (val & BMCR_PDOWN)
phy_write(dev, 0x0, val & ~BMCR_PDOWN);
return 0;
}
static void __init imx6q_enet_phy_init(void)
{
if (IS_BUILTIN(CONFIG_PHYLIB)) {
phy_register_fixup_for_uid(PHY_ID_KSZ9021, MICREL_PHY_ID_MASK,
ksz9021rn_phy_fixup);
phy_register_fixup_for_uid(PHY_ID_KSZ9031, MICREL_PHY_ID_MASK,
ksz9031rn_phy_fixup);
phy_register_fixup_for_uid(PHY_ID_AR8031, 0xffffffef,
ar8031_phy_fixup);
phy_register_fixup_for_uid(PHY_ID_AR8035, 0xffffffef,
ar8035_phy_fixup);
}
}
static void __init imx6q_1588_init(void)
{
struct device_node *np;
struct clk *ptp_clk;
struct clk *enet_ref;
struct regmap *gpr;
u32 clksel;
np = of_find_compatible_node(NULL, NULL, "fsl,imx6q-fec");
if (!np) {
pr_warn("%s: failed to find fec node\n", __func__);
return;
}
ptp_clk = of_clk_get(np, 2);
if (IS_ERR(ptp_clk)) {
pr_warn("%s: failed to get ptp clock\n", __func__);
goto put_node;
}
enet_ref = clk_get_sys(NULL, "enet_ref");
if (IS_ERR(enet_ref)) {
pr_warn("%s: failed to get enet clock\n", __func__);
goto put_ptp_clk;
}
clksel = clk_is_match(ptp_clk, enet_ref) ?
IMX6Q_GPR1_ENET_CLK_SEL_ANATOP :
IMX6Q_GPR1_ENET_CLK_SEL_PAD;
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (!IS_ERR(gpr))
regmap_update_bits(gpr, IOMUXC_GPR1,
IMX6Q_GPR1_ENET_CLK_SEL_MASK,
clksel);
else
pr_err("failed to find fsl,imx6q-iomuxc-gpr regmap\n");
clk_put(enet_ref);
put_ptp_clk:
clk_put(ptp_clk);
put_node:
of_node_put(np);
}
static void __init imx6q_axi_init(void)
{
struct regmap *gpr;
unsigned int mask;
gpr = syscon_regmap_lookup_by_compatible("fsl,imx6q-iomuxc-gpr");
if (!IS_ERR(gpr)) {
mask = IMX6Q_GPR4_VPU_WR_CACHE_SEL |
IMX6Q_GPR4_VPU_RD_CACHE_SEL |
IMX6Q_GPR4_VPU_P_WR_CACHE_VAL |
IMX6Q_GPR4_VPU_P_RD_CACHE_VAL_MASK |
IMX6Q_GPR4_IPU_WR_CACHE_CTL |
IMX6Q_GPR4_IPU_RD_CACHE_CTL;
regmap_update_bits(gpr, IOMUXC_GPR4, mask, mask);
regmap_update_bits(gpr, IOMUXC_GPR6,
IMX6Q_GPR6_IPU1_ID00_RD_QOS_MASK |
IMX6Q_GPR6_IPU1_ID01_RD_QOS_MASK,
(0xf << 16) | (0x7 << 20));
regmap_update_bits(gpr, IOMUXC_GPR7,
IMX6Q_GPR7_IPU2_ID00_RD_QOS_MASK |
IMX6Q_GPR7_IPU2_ID01_RD_QOS_MASK,
(0xf << 16) | (0x7 << 20));
} else {
pr_warn("failed to find fsl,imx6q-iomuxc-gpr regmap\n");
}
}
static void __init imx6q_init_machine(void)
{
struct device *parent;
if (cpu_is_imx6q() && imx_get_soc_revision() == IMX_CHIP_REVISION_2_0)
imx_print_silicon_rev("i.MX6QP", IMX_CHIP_REVISION_1_0);
else
imx_print_silicon_rev(cpu_is_imx6dl() ? "i.MX6DL" : "i.MX6Q",
imx_get_soc_revision());
parent = imx_soc_device_init();
if (parent == NULL)
pr_warn("failed to initialize soc device\n");
imx6q_enet_phy_init();
of_platform_default_populate(NULL, NULL, parent);
imx_anatop_init();
cpu_is_imx6q() ? imx6q_pm_init() : imx6dl_pm_init();
imx6q_1588_init();
imx6q_axi_init();
}
static void __init imx6q_opp_check_speed_grading(struct device *cpu_dev)
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
val &= 0x3;
if ((val != OCOTP_CFG3_SPEED_1P2GHZ) && cpu_is_imx6q())
if (dev_pm_opp_disable(cpu_dev, 1200000000))
pr_warn("failed to disable 1.2 GHz OPP\n");
if (val < OCOTP_CFG3_SPEED_996MHZ)
if (dev_pm_opp_disable(cpu_dev, 996000000))
pr_warn("failed to disable 996 MHz OPP\n");
if (cpu_is_imx6q()) {
if (val != OCOTP_CFG3_SPEED_852MHZ)
if (dev_pm_opp_disable(cpu_dev, 852000000))
pr_warn("failed to disable 852 MHz OPP\n");
}
iounmap(base);
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
if (dev_pm_opp_of_add_table(cpu_dev)) {
pr_warn("failed to init OPP table\n");
goto put_node;
}
imx6q_opp_check_speed_grading(cpu_dev);
put_node:
of_node_put(np);
}
static void __init imx6q_init_late(void)
{
if (imx_get_soc_revision() > IMX_CHIP_REVISION_1_1)
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
imx_gpc_check_dt();
imx_init_revision_from_anatop();
imx_init_l2cache();
imx_src_init();
irqchip_init();
imx6_pm_ccm_init("fsl,imx6q-ccm");
}
