void bcm_kona_setup_restart(void)
{
struct device_node *np_wdog;
np_wdog = of_find_compatible_node(NULL, NULL, "brcm,kona-wdt");
if (!np_wdog) {
pr_err("brcm,kona-wdt not found in DT, reboot disabled\n");
return;
}
watchdog_base = of_iomap(np_wdog, 0);
WARN(!watchdog_base, "failed to map watchdog base");
of_node_put(np_wdog);
}
void bcm_kona_restart(enum reboot_mode mode, const char *cmd)
{
uint32_t val;
if (!watchdog_base)
panic("Watchdog not mapped. Reboot failed.\n");
val = readl(watchdog_base + SECWDOG_OFFSET);
val &= SECWDOG_RESERVED_MASK | SECWDOG_WD_LOAD_FLAG_MASK;
val |= SECWDOG_EN_MASK | SECWDOG_SRSTEN_MASK |
(0x8 << SECWDOG_CLKS_SHIFT) |
(0x8 << SECWDOG_LOCK_SHIFT);
writel(val, watchdog_base + SECWDOG_OFFSET);
while (1)
;
}
