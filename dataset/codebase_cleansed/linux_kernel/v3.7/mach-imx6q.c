void imx6q_restart(char mode, const char *cmd)
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
static void __init imx6q_usb_init(void)
{
struct regmap *anatop;
#define HW_ANADIG_USB1_CHRG_DETECT 0x000001b0
#define HW_ANADIG_USB2_CHRG_DETECT 0x00000210
#define BM_ANADIG_USB_CHRG_DETECT_EN_B 0x00100000
#define BM_ANADIG_USB_CHRG_DETECT_CHK_CHRG_B 0x00080000
anatop = syscon_regmap_lookup_by_compatible("fsl,imx6q-anatop");
if (!IS_ERR(anatop)) {
regmap_write(anatop, HW_ANADIG_USB1_CHRG_DETECT,
BM_ANADIG_USB_CHRG_DETECT_EN_B
| BM_ANADIG_USB_CHRG_DETECT_CHK_CHRG_B);
regmap_write(anatop, HW_ANADIG_USB2_CHRG_DETECT,
BM_ANADIG_USB_CHRG_DETECT_EN_B |
BM_ANADIG_USB_CHRG_DETECT_CHK_CHRG_B);
} else {
pr_warn("failed to find fsl,imx6q-anatop regmap\n");
}
}
static void __init imx6q_init_machine(void)
{
if (of_machine_is_compatible("fsl,imx6q-sabrelite"))
imx6q_sabrelite_init();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx6q_pm_init();
imx6q_usb_init();
}
static void __init imx6q_init_late(void)
{
imx_cpuidle_init(&imx6q_cpuidle_driver);
}
static void __init imx6q_map_io(void)
{
imx_lluart_map_io();
imx_scu_map_io();
imx6q_clock_map_io();
}
static void __init imx6q_init_irq(void)
{
l2x0_of_init(0, ~0UL);
imx_src_init();
imx_gpc_init();
of_irq_init(imx6q_irq_match);
}
static void __init imx6q_timer_init(void)
{
mx6q_clocks_init();
twd_local_timer_of_register();
}
