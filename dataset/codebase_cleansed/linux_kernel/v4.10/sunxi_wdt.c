static int sunxi_wdt_restart(struct watchdog_device *wdt_dev,
unsigned long action, void *data)
{
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
const struct sunxi_wdt_reg *regs = sunxi_wdt->wdt_regs;
u32 val;
val = readl(wdt_base + regs->wdt_cfg);
val &= ~(regs->wdt_reset_mask);
val |= regs->wdt_reset_val;
writel(val, wdt_base + regs->wdt_cfg);
val = readl(wdt_base + regs->wdt_mode);
val &= ~(WDT_TIMEOUT_MASK << regs->wdt_timeout_shift);
val |= WDT_MODE_EN;
writel(val, wdt_base + regs->wdt_mode);
writel(WDT_CTRL_RELOAD, wdt_base + regs->wdt_ctrl);
while (1) {
mdelay(5);
val = readl(wdt_base + regs->wdt_mode);
val |= WDT_MODE_EN;
writel(val, wdt_base + regs->wdt_mode);
}
return 0;
}
static int sunxi_wdt_ping(struct watchdog_device *wdt_dev)
{
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
const struct sunxi_wdt_reg *regs = sunxi_wdt->wdt_regs;
writel(WDT_CTRL_RELOAD, wdt_base + regs->wdt_ctrl);
return 0;
}
static int sunxi_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
const struct sunxi_wdt_reg *regs = sunxi_wdt->wdt_regs;
u32 reg;
if (wdt_timeout_map[timeout] == 0)
timeout++;
sunxi_wdt->wdt_dev.timeout = timeout;
reg = readl(wdt_base + regs->wdt_mode);
reg &= ~(WDT_TIMEOUT_MASK << regs->wdt_timeout_shift);
reg |= wdt_timeout_map[timeout] << regs->wdt_timeout_shift;
writel(reg, wdt_base + regs->wdt_mode);
sunxi_wdt_ping(wdt_dev);
return 0;
}
static int sunxi_wdt_stop(struct watchdog_device *wdt_dev)
{
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
const struct sunxi_wdt_reg *regs = sunxi_wdt->wdt_regs;
writel(0, wdt_base + regs->wdt_mode);
return 0;
}
static int sunxi_wdt_start(struct watchdog_device *wdt_dev)
{
u32 reg;
struct sunxi_wdt_dev *sunxi_wdt = watchdog_get_drvdata(wdt_dev);
void __iomem *wdt_base = sunxi_wdt->wdt_base;
const struct sunxi_wdt_reg *regs = sunxi_wdt->wdt_regs;
int ret;
ret = sunxi_wdt_set_timeout(&sunxi_wdt->wdt_dev,
sunxi_wdt->wdt_dev.timeout);
if (ret < 0)
return ret;
reg = readl(wdt_base + regs->wdt_cfg);
reg &= ~(regs->wdt_reset_mask);
reg |= regs->wdt_reset_val;
writel(reg, wdt_base + regs->wdt_cfg);
reg = readl(wdt_base + regs->wdt_mode);
reg |= WDT_MODE_EN;
writel(reg, wdt_base + regs->wdt_mode);
return 0;
}
static int sunxi_wdt_probe(struct platform_device *pdev)
{
struct sunxi_wdt_dev *sunxi_wdt;
const struct of_device_id *device;
struct resource *res;
int err;
sunxi_wdt = devm_kzalloc(&pdev->dev, sizeof(*sunxi_wdt), GFP_KERNEL);
if (!sunxi_wdt)
return -EINVAL;
platform_set_drvdata(pdev, sunxi_wdt);
device = of_match_device(sunxi_wdt_dt_ids, &pdev->dev);
if (!device)
return -ENODEV;
sunxi_wdt->wdt_regs = device->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
sunxi_wdt->wdt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(sunxi_wdt->wdt_base))
return PTR_ERR(sunxi_wdt->wdt_base);
sunxi_wdt->wdt_dev.info = &sunxi_wdt_info;
sunxi_wdt->wdt_dev.ops = &sunxi_wdt_ops;
sunxi_wdt->wdt_dev.timeout = WDT_MAX_TIMEOUT;
sunxi_wdt->wdt_dev.max_timeout = WDT_MAX_TIMEOUT;
sunxi_wdt->wdt_dev.min_timeout = WDT_MIN_TIMEOUT;
sunxi_wdt->wdt_dev.parent = &pdev->dev;
watchdog_init_timeout(&sunxi_wdt->wdt_dev, timeout, &pdev->dev);
watchdog_set_nowayout(&sunxi_wdt->wdt_dev, nowayout);
watchdog_set_restart_priority(&sunxi_wdt->wdt_dev, 128);
watchdog_set_drvdata(&sunxi_wdt->wdt_dev, sunxi_wdt);
sunxi_wdt_stop(&sunxi_wdt->wdt_dev);
err = watchdog_register_device(&sunxi_wdt->wdt_dev);
if (unlikely(err))
return err;
dev_info(&pdev->dev, "Watchdog enabled (timeout=%d sec, nowayout=%d)",
sunxi_wdt->wdt_dev.timeout, nowayout);
return 0;
}
static int sunxi_wdt_remove(struct platform_device *pdev)
{
struct sunxi_wdt_dev *sunxi_wdt = platform_get_drvdata(pdev);
watchdog_unregister_device(&sunxi_wdt->wdt_dev);
watchdog_set_drvdata(&sunxi_wdt->wdt_dev, NULL);
return 0;
}
static void sunxi_wdt_shutdown(struct platform_device *pdev)
{
struct sunxi_wdt_dev *sunxi_wdt = platform_get_drvdata(pdev);
sunxi_wdt_stop(&sunxi_wdt->wdt_dev);
}
