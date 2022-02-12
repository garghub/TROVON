static inline int wdt_command(int sub, u32 *in, int inlen)
{
return intel_scu_ipc_command(IPC_WATCHDOG, sub, in, inlen, NULL, 0);
}
static int wdt_start(struct watchdog_device *wd)
{
struct device *dev = watchdog_get_drvdata(wd);
int ret, in_size;
int timeout = wd->timeout;
struct ipc_wd_start {
u32 pretimeout;
u32 timeout;
} ipc_wd_start = { timeout - MID_WDT_PRETIMEOUT, timeout };
in_size = DIV_ROUND_UP(sizeof(ipc_wd_start), 4);
ret = wdt_command(SCU_WATCHDOG_START, (u32 *)&ipc_wd_start, in_size);
if (ret)
dev_crit(dev, "error starting watchdog: %d\n", ret);
return ret;
}
static int wdt_ping(struct watchdog_device *wd)
{
struct device *dev = watchdog_get_drvdata(wd);
int ret;
ret = wdt_command(SCU_WATCHDOG_KEEPALIVE, NULL, 0);
if (ret)
dev_crit(dev, "Error executing keepalive: %d\n", ret);
return ret;
}
static int wdt_stop(struct watchdog_device *wd)
{
struct device *dev = watchdog_get_drvdata(wd);
int ret;
ret = wdt_command(SCU_WATCHDOG_STOP, NULL, 0);
if (ret)
dev_crit(dev, "Error stopping watchdog: %d\n", ret);
return ret;
}
static irqreturn_t mid_wdt_irq(int irq, void *dev_id)
{
panic("Kernel Watchdog");
return IRQ_HANDLED;
}
static int mid_wdt_probe(struct platform_device *pdev)
{
struct watchdog_device *wdt_dev;
struct intel_mid_wdt_pdata *pdata = pdev->dev.platform_data;
int ret;
if (!pdata) {
dev_err(&pdev->dev, "missing platform data\n");
return -EINVAL;
}
if (pdata->probe) {
ret = pdata->probe(pdev);
if (ret)
return ret;
}
wdt_dev = devm_kzalloc(&pdev->dev, sizeof(*wdt_dev), GFP_KERNEL);
if (!wdt_dev)
return -ENOMEM;
wdt_dev->info = &mid_wdt_info;
wdt_dev->ops = &mid_wdt_ops;
wdt_dev->min_timeout = MID_WDT_TIMEOUT_MIN;
wdt_dev->max_timeout = MID_WDT_TIMEOUT_MAX;
wdt_dev->timeout = MID_WDT_DEFAULT_TIMEOUT;
wdt_dev->parent = &pdev->dev;
watchdog_set_drvdata(wdt_dev, &pdev->dev);
ret = devm_request_irq(&pdev->dev, pdata->irq, mid_wdt_irq,
IRQF_SHARED | IRQF_NO_SUSPEND, "watchdog",
wdt_dev);
if (ret) {
dev_err(&pdev->dev, "error requesting warning irq %d\n",
pdata->irq);
return ret;
}
wdt_stop(wdt_dev);
ret = devm_watchdog_register_device(&pdev->dev, wdt_dev);
if (ret) {
dev_err(&pdev->dev, "error registering watchdog device\n");
return ret;
}
dev_info(&pdev->dev, "Intel MID watchdog device probed\n");
return 0;
}
