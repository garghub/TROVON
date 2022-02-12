static void sun4i_restart(enum reboot_mode mode, const char *cmd)
{
if (!wdt_base)
return;
writel(SUN4I_WATCHDOG_MODE_ENABLE | SUN4I_WATCHDOG_MODE_RESET_ENABLE,
wdt_base + SUN4I_WATCHDOG_MODE_REG);
writel(SUN4I_WATCHDOG_CTRL_RESTART, wdt_base + SUN4I_WATCHDOG_CTRL_REG);
while (1) {
mdelay(5);
writel(SUN4I_WATCHDOG_MODE_ENABLE | SUN4I_WATCHDOG_MODE_RESET_ENABLE,
wdt_base + SUN4I_WATCHDOG_MODE_REG);
}
}
static void sunxi_setup_restart(void)
{
const struct of_device_id *of_id;
struct device_node *np;
np = of_find_matching_node(NULL, sunxi_restart_ids);
if (WARN(!np, "unable to setup watchdog restart"))
return;
wdt_base = of_iomap(np, 0);
WARN(!wdt_base, "failed to map watchdog base address");
of_id = of_match_node(sunxi_restart_ids, np);
WARN(!of_id, "restart function not available");
arm_pm_restart = of_id->data;
}
static void __init sunxi_timer_init(void)
{
sunxi_init_clocks();
clocksource_of_init();
}
static void __init sunxi_dt_init(void)
{
sunxi_setup_restart();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
