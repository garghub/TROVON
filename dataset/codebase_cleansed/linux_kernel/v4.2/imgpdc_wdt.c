static int pdc_wdt_keepalive(struct watchdog_device *wdt_dev)
{
struct pdc_wdt_dev *wdt = watchdog_get_drvdata(wdt_dev);
writel(PDC_WDT_TICKLE1_MAGIC, wdt->base + PDC_WDT_TICKLE1);
writel(PDC_WDT_TICKLE2_MAGIC, wdt->base + PDC_WDT_TICKLE2);
return 0;
}
static int pdc_wdt_stop(struct watchdog_device *wdt_dev)
{
unsigned int val;
struct pdc_wdt_dev *wdt = watchdog_get_drvdata(wdt_dev);
val = readl(wdt->base + PDC_WDT_CONFIG);
val &= ~PDC_WDT_CONFIG_ENABLE;
writel(val, wdt->base + PDC_WDT_CONFIG);
pdc_wdt_keepalive(wdt_dev);
return 0;
}
static void __pdc_wdt_set_timeout(struct pdc_wdt_dev *wdt)
{
unsigned long clk_rate = clk_get_rate(wdt->wdt_clk);
unsigned int val;
val = readl(wdt->base + PDC_WDT_CONFIG) & ~PDC_WDT_CONFIG_DELAY_MASK;
val |= order_base_2(wdt->wdt_dev.timeout * clk_rate) - 1;
writel(val, wdt->base + PDC_WDT_CONFIG);
}
static int pdc_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int new_timeout)
{
struct pdc_wdt_dev *wdt = watchdog_get_drvdata(wdt_dev);
wdt->wdt_dev.timeout = new_timeout;
__pdc_wdt_set_timeout(wdt);
return 0;
}
static int pdc_wdt_start(struct watchdog_device *wdt_dev)
{
unsigned int val;
struct pdc_wdt_dev *wdt = watchdog_get_drvdata(wdt_dev);
__pdc_wdt_set_timeout(wdt);
val = readl(wdt->base + PDC_WDT_CONFIG);
val |= PDC_WDT_CONFIG_ENABLE;
writel(val, wdt->base + PDC_WDT_CONFIG);
return 0;
}
static int pdc_wdt_restart(struct notifier_block *this, unsigned long mode,
void *cmd)
{
struct pdc_wdt_dev *wdt = container_of(this, struct pdc_wdt_dev,
restart_handler);
writel(0x1, wdt->base + PDC_WDT_SOFT_RESET);
return NOTIFY_OK;
}
static int pdc_wdt_probe(struct platform_device *pdev)
{
u64 div;
int ret, val;
unsigned long clk_rate;
struct resource *res;
struct pdc_wdt_dev *pdc_wdt;
pdc_wdt = devm_kzalloc(&pdev->dev, sizeof(*pdc_wdt), GFP_KERNEL);
if (!pdc_wdt)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pdc_wdt->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pdc_wdt->base))
return PTR_ERR(pdc_wdt->base);
pdc_wdt->sys_clk = devm_clk_get(&pdev->dev, "sys");
if (IS_ERR(pdc_wdt->sys_clk)) {
dev_err(&pdev->dev, "failed to get the sys clock\n");
return PTR_ERR(pdc_wdt->sys_clk);
}
pdc_wdt->wdt_clk = devm_clk_get(&pdev->dev, "wdt");
if (IS_ERR(pdc_wdt->wdt_clk)) {
dev_err(&pdev->dev, "failed to get the wdt clock\n");
return PTR_ERR(pdc_wdt->wdt_clk);
}
ret = clk_prepare_enable(pdc_wdt->sys_clk);
if (ret) {
dev_err(&pdev->dev, "could not prepare or enable sys clock\n");
return ret;
}
ret = clk_prepare_enable(pdc_wdt->wdt_clk);
if (ret) {
dev_err(&pdev->dev, "could not prepare or enable wdt clock\n");
goto disable_sys_clk;
}
clk_rate = clk_get_rate(pdc_wdt->wdt_clk);
if (clk_rate == 0) {
dev_err(&pdev->dev, "failed to get clock rate\n");
ret = -EINVAL;
goto disable_wdt_clk;
}
if (order_base_2(clk_rate) > PDC_WDT_CONFIG_DELAY_MASK + 1) {
dev_err(&pdev->dev, "invalid clock rate\n");
ret = -EINVAL;
goto disable_wdt_clk;
}
if (order_base_2(clk_rate) == 0)
pdc_wdt->wdt_dev.min_timeout = PDC_WDT_MIN_TIMEOUT + 1;
else
pdc_wdt->wdt_dev.min_timeout = PDC_WDT_MIN_TIMEOUT;
pdc_wdt->wdt_dev.info = &pdc_wdt_info;
pdc_wdt->wdt_dev.ops = &pdc_wdt_ops;
div = 1ULL << (PDC_WDT_CONFIG_DELAY_MASK + 1);
do_div(div, clk_rate);
pdc_wdt->wdt_dev.max_timeout = div;
pdc_wdt->wdt_dev.timeout = PDC_WDT_DEF_TIMEOUT;
pdc_wdt->wdt_dev.parent = &pdev->dev;
watchdog_set_drvdata(&pdc_wdt->wdt_dev, pdc_wdt);
watchdog_init_timeout(&pdc_wdt->wdt_dev, heartbeat, &pdev->dev);
pdc_wdt_stop(&pdc_wdt->wdt_dev);
val = readl(pdc_wdt->base + PDC_WDT_TICKLE1);
val = (val & PDC_WDT_TICKLE_STATUS_MASK) >> PDC_WDT_TICKLE_STATUS_SHIFT;
switch (val) {
case PDC_WDT_TICKLE_STATUS_TICKLE:
case PDC_WDT_TICKLE_STATUS_TIMEOUT:
pdc_wdt->wdt_dev.bootstatus |= WDIOF_CARDRESET;
dev_info(&pdev->dev,
"watchdog module last reset due to timeout\n");
break;
case PDC_WDT_TICKLE_STATUS_HRESET:
dev_info(&pdev->dev,
"watchdog module last reset due to hard reset\n");
break;
case PDC_WDT_TICKLE_STATUS_SRESET:
dev_info(&pdev->dev,
"watchdog module last reset due to soft reset\n");
break;
case PDC_WDT_TICKLE_STATUS_USER:
dev_info(&pdev->dev,
"watchdog module last reset due to user reset\n");
break;
default:
dev_info(&pdev->dev,
"contains an illegal status code (%08x)\n", val);
break;
}
watchdog_set_nowayout(&pdc_wdt->wdt_dev, nowayout);
platform_set_drvdata(pdev, pdc_wdt);
ret = watchdog_register_device(&pdc_wdt->wdt_dev);
if (ret)
goto disable_wdt_clk;
pdc_wdt->restart_handler.notifier_call = pdc_wdt_restart;
pdc_wdt->restart_handler.priority = 128;
ret = register_restart_handler(&pdc_wdt->restart_handler);
if (ret)
dev_warn(&pdev->dev, "failed to register restart handler: %d\n",
ret);
return 0;
disable_wdt_clk:
clk_disable_unprepare(pdc_wdt->wdt_clk);
disable_sys_clk:
clk_disable_unprepare(pdc_wdt->sys_clk);
return ret;
}
static void pdc_wdt_shutdown(struct platform_device *pdev)
{
struct pdc_wdt_dev *pdc_wdt = platform_get_drvdata(pdev);
pdc_wdt_stop(&pdc_wdt->wdt_dev);
}
static int pdc_wdt_remove(struct platform_device *pdev)
{
struct pdc_wdt_dev *pdc_wdt = platform_get_drvdata(pdev);
pdc_wdt_stop(&pdc_wdt->wdt_dev);
watchdog_unregister_device(&pdc_wdt->wdt_dev);
clk_disable_unprepare(pdc_wdt->wdt_clk);
clk_disable_unprepare(pdc_wdt->sys_clk);
return 0;
}
