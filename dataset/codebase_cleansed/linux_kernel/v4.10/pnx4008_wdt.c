static int pnx4008_wdt_start(struct watchdog_device *wdd)
{
spin_lock(&io_lock);
writel(RESET_COUNT, WDTIM_CTRL(wdt_base));
while (readl(WDTIM_COUNTER(wdt_base)))
cpu_relax();
writel(M_RES2 | STOP_COUNT0 | RESET_COUNT0, WDTIM_MCTRL(wdt_base));
writel(MATCH_OUTPUT_HIGH, WDTIM_EMR(wdt_base));
writel(MATCH_INT, WDTIM_INT(wdt_base));
writel(0xFFFF, WDTIM_PULSE(wdt_base));
writel(wdd->timeout * WDOG_COUNTER_RATE, WDTIM_MATCH0(wdt_base));
writel(COUNT_ENAB | DEBUG_EN, WDTIM_CTRL(wdt_base));
spin_unlock(&io_lock);
return 0;
}
static int pnx4008_wdt_stop(struct watchdog_device *wdd)
{
spin_lock(&io_lock);
writel(0, WDTIM_CTRL(wdt_base));
spin_unlock(&io_lock);
return 0;
}
static int pnx4008_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int new_timeout)
{
wdd->timeout = new_timeout;
return 0;
}
static int pnx4008_restart_handler(struct watchdog_device *wdd,
unsigned long mode, void *cmd)
{
const char *boot_cmd = cmd;
if (boot_cmd) {
if (boot_cmd[0] == 'h')
mode = REBOOT_HARD;
else if (boot_cmd[0] == 's')
mode = REBOOT_SOFT;
}
if (mode == REBOOT_SOFT) {
writel(EXT_MATCH0, WDTIM_EMR(wdt_base));
writel(M_RES1, WDTIM_MCTRL(wdt_base));
} else {
writel(13000, WDTIM_PULSE(wdt_base));
writel(M_RES2 | RESFRC1 | RESFRC2, WDTIM_MCTRL(wdt_base));
}
mdelay(1000);
return NOTIFY_DONE;
}
static int pnx4008_wdt_probe(struct platform_device *pdev)
{
struct resource *r;
int ret = 0;
watchdog_init_timeout(&pnx4008_wdd, heartbeat, &pdev->dev);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
wdt_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(wdt_base))
return PTR_ERR(wdt_base);
wdt_clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(wdt_clk))
return PTR_ERR(wdt_clk);
ret = clk_prepare_enable(wdt_clk);
if (ret)
return ret;
pnx4008_wdd.bootstatus = (readl(WDTIM_RES(wdt_base)) & WDOG_RESET) ?
WDIOF_CARDRESET : 0;
pnx4008_wdd.parent = &pdev->dev;
watchdog_set_nowayout(&pnx4008_wdd, nowayout);
watchdog_set_restart_priority(&pnx4008_wdd, 128);
pnx4008_wdt_stop(&pnx4008_wdd);
ret = watchdog_register_device(&pnx4008_wdd);
if (ret < 0) {
dev_err(&pdev->dev, "cannot register watchdog device\n");
goto disable_clk;
}
dev_info(&pdev->dev, "heartbeat %d sec\n", pnx4008_wdd.timeout);
return 0;
disable_clk:
clk_disable_unprepare(wdt_clk);
return ret;
}
static int pnx4008_wdt_remove(struct platform_device *pdev)
{
watchdog_unregister_device(&pnx4008_wdd);
clk_disable_unprepare(wdt_clk);
return 0;
}
