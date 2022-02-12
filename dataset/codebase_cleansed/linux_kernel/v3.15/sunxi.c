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
static void sun6i_restart(enum reboot_mode mode, const char *cmd)
{
if (!wdt_base)
return;
writel(0, wdt_base + SUN6I_WATCHDOG1_IRQ_REG);
writel(SUN6I_WATCHDOG1_CONFIG_RESTART,
wdt_base + SUN6I_WATCHDOG1_CONFIG_REG);
writel(SUN6I_WATCHDOG1_MODE_ENABLE,
wdt_base + SUN6I_WATCHDOG1_MODE_REG);
writel(SUN6I_WATCHDOG1_CTRL_RESTART,
wdt_base + SUN6I_WATCHDOG1_CTRL_REG);
while (1) {
mdelay(5);
writel(SUN6I_WATCHDOG1_MODE_ENABLE,
wdt_base + SUN6I_WATCHDOG1_MODE_REG);
}
}
static void sunxi_setup_restart(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, sunxi_restart_ids);
if (WARN(!np, "unable to setup watchdog restart"))
return;
wdt_base = of_iomap(np, 0);
WARN(!wdt_base, "failed to map watchdog base address");
}
static void __init sunxi_dt_init(void)
{
sunxi_setup_restart();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
static void __init sun6i_timer_init(void)
{
of_clk_init(NULL);
sun6i_reset_init();
clocksource_of_init();
}
