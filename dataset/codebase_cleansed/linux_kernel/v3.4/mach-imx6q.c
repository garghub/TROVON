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
phy_write(phydev, 0x0b, 0x8105);
phy_write(phydev, 0x0c, 0x0000);
phy_write(phydev, 0x0b, 0x8104);
phy_write(phydev, 0x0c, 0xf0f0);
phy_write(phydev, 0x0b, 0x104);
return 0;
}
static void __init imx6q_init_machine(void)
{
if (of_machine_is_compatible("fsl,imx6q-sabrelite"))
phy_register_fixup_for_uid(PHY_ID_KSZ9021, MICREL_PHY_ID_MASK,
ksz9021rn_phy_fixup);
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
imx6q_pm_init();
}
static void __init imx6q_map_io(void)
{
imx_lluart_map_io();
imx_scu_map_io();
imx6q_clock_map_io();
}
static int __init imx6q_gpio_add_irq_domain(struct device_node *np,
struct device_node *interrupt_parent)
{
static int gpio_irq_base = MXC_GPIO_IRQ_START + ARCH_NR_GPIOS;
gpio_irq_base -= 32;
irq_domain_add_legacy(np, 32, gpio_irq_base, 0, &irq_domain_simple_ops,
NULL);
return 0;
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
