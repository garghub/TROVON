static void bcm281xx_restart(enum reboot_mode mode, const char *cmd)
{
uint32_t val;
void __iomem *base;
struct device_node *np_wdog;
np_wdog = of_find_compatible_node(NULL, NULL, "brcm,kona-wdt");
if (!np_wdog) {
pr_emerg("Couldn't find brcm,kona-wdt\n");
return;
}
base = of_iomap(np_wdog, 0);
if (!base) {
pr_emerg("Couldn't map brcm,kona-wdt\n");
return;
}
val = readl(base + SECWDOG_OFFSET);
val &= SECWDOG_RESERVED_MASK | SECWDOG_WD_LOAD_FLAG_MASK;
val |= SECWDOG_EN_MASK | SECWDOG_SRSTEN_MASK |
(0x15 << SECWDOG_CLKS_SHIFT) |
(0x8 << SECWDOG_COUNT_SHIFT);
writel(val, base + SECWDOG_OFFSET);
while (1);
}
static void __init bcm281xx_init(void)
{
kona_l2_cache_init();
}
