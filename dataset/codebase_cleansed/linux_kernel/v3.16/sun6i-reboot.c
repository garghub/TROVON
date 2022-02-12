static void sun6i_wdt_restart(enum reboot_mode mode, const char *cmd)
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
static int sun6i_reboot_probe(struct platform_device *pdev)
{
wdt_base = of_iomap(pdev->dev.of_node, 0);
if (!wdt_base) {
WARN(1, "failed to map watchdog base address");
return -ENODEV;
}
arm_pm_restart = sun6i_wdt_restart;
return 0;
}
