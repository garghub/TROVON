static void sunxi_setup_restart(void)
{
struct device_node *np = of_find_compatible_node(NULL, NULL,
"allwinner,sunxi-wdt");
if (WARN(!np, "unable to setup watchdog restart"))
return;
wdt_base = of_iomap(np, 0);
WARN(!wdt_base, "failed to map watchdog base address");
}
static void sunxi_restart(char mode, const char *cmd)
{
if (!wdt_base)
return;
writel(3, wdt_base + WATCHDOG_MODE_REG);
writel(0xa57 << 1 | 1, wdt_base + WATCHDOG_CTRL_REG);
while(1) {
mdelay(5);
writel(3, wdt_base + WATCHDOG_MODE_REG);
}
}
void __init sunxi_map_io(void)
{
iotable_init(sunxi_io_desc, ARRAY_SIZE(sunxi_io_desc));
}
static void __init sunxi_dt_init(void)
{
sunxi_setup_restart();
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
