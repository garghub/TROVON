static void bcm2835_setup_restart(void)
{
struct device_node *np = of_find_compatible_node(NULL, NULL,
"brcm,bcm2835-pm-wdt");
if (WARN(!np, "unable to setup watchdog restart"))
return;
wdt_regs = of_iomap(np, 0);
WARN(!wdt_regs, "failed to remap watchdog regs");
}
static void bcm2835_restart(enum reboot_mode mode, const char *cmd)
{
u32 val;
if (!wdt_regs)
return;
writel_relaxed(10 | PM_PASSWORD, wdt_regs + PM_WDOG);
val = readl_relaxed(wdt_regs + PM_RSTC);
val &= ~PM_RSTC_WRCFG_MASK;
val |= PM_PASSWORD | PM_RSTC_WRCFG_FULL_RESET;
writel_relaxed(val, wdt_regs + PM_RSTC);
mdelay(1);
}
static void bcm2835_power_off(void)
{
u32 val;
val = readl_relaxed(wdt_regs + PM_RSTS);
val &= ~PM_RSTC_WRCFG_MASK;
val |= PM_PASSWORD | PM_RSTS_HADWRH_SET;
writel_relaxed(val, wdt_regs + PM_RSTS);
bcm2835_restart(REBOOT_HARD, "");
}
static void __init bcm2835_map_io(void)
{
iotable_init(&io_map, 1);
}
static void __init bcm2835_init(void)
{
int ret;
bcm2835_setup_restart();
if (wdt_regs)
pm_power_off = bcm2835_power_off;
bcm2835_init_clocks();
ret = of_platform_populate(NULL, of_default_bus_match_table, NULL,
NULL);
if (ret) {
pr_err("of_platform_populate failed: %d\n", ret);
BUG();
}
}
