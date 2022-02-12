static int xilinx_wdt_start(struct watchdog_device *wdd)
{
u32 control_status_reg;
struct xwdt_device *xdev = watchdog_get_drvdata(wdd);
spin_lock(&xdev->spinlock);
control_status_reg = ioread32(xdev->base + XWT_TWCSR0_OFFSET);
control_status_reg |= (XWT_CSR0_WRS_MASK | XWT_CSR0_WDS_MASK);
iowrite32((control_status_reg | XWT_CSR0_EWDT1_MASK),
xdev->base + XWT_TWCSR0_OFFSET);
iowrite32(XWT_CSRX_EWDT2_MASK, xdev->base + XWT_TWCSR1_OFFSET);
spin_unlock(&xdev->spinlock);
return 0;
}
static int xilinx_wdt_stop(struct watchdog_device *wdd)
{
u32 control_status_reg;
struct xwdt_device *xdev = watchdog_get_drvdata(wdd);
spin_lock(&xdev->spinlock);
control_status_reg = ioread32(xdev->base + XWT_TWCSR0_OFFSET);
iowrite32((control_status_reg & ~XWT_CSR0_EWDT1_MASK),
xdev->base + XWT_TWCSR0_OFFSET);
iowrite32(0, xdev->base + XWT_TWCSR1_OFFSET);
spin_unlock(&xdev->spinlock);
pr_info("Stopped!\n");
return 0;
}
static int xilinx_wdt_keepalive(struct watchdog_device *wdd)
{
u32 control_status_reg;
struct xwdt_device *xdev = watchdog_get_drvdata(wdd);
spin_lock(&xdev->spinlock);
control_status_reg = ioread32(xdev->base + XWT_TWCSR0_OFFSET);
control_status_reg |= (XWT_CSR0_WRS_MASK | XWT_CSR0_WDS_MASK);
iowrite32(control_status_reg, xdev->base + XWT_TWCSR0_OFFSET);
spin_unlock(&xdev->spinlock);
return 0;
}
static u32 xwdt_selftest(struct xwdt_device *xdev)
{
int i;
u32 timer_value1;
u32 timer_value2;
spin_lock(&xdev->spinlock);
timer_value1 = ioread32(xdev->base + XWT_TBR_OFFSET);
timer_value2 = ioread32(xdev->base + XWT_TBR_OFFSET);
for (i = 0;
((i <= XWT_MAX_SELFTEST_LOOP_COUNT) &&
(timer_value2 == timer_value1)); i++) {
timer_value2 = ioread32(xdev->base + XWT_TBR_OFFSET);
}
spin_unlock(&xdev->spinlock);
if (timer_value2 != timer_value1)
return ~XWT_TIMER_FAILED;
else
return XWT_TIMER_FAILED;
}
static int xwdt_probe(struct platform_device *pdev)
{
int rc;
u32 pfreq = 0, enable_once = 0;
struct resource *res;
struct xwdt_device *xdev;
struct watchdog_device *xilinx_wdt_wdd;
xdev = devm_kzalloc(&pdev->dev, sizeof(*xdev), GFP_KERNEL);
if (!xdev)
return -ENOMEM;
xilinx_wdt_wdd = &xdev->xilinx_wdt_wdd;
xilinx_wdt_wdd->info = &xilinx_wdt_ident;
xilinx_wdt_wdd->ops = &xilinx_wdt_ops;
xilinx_wdt_wdd->parent = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xdev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xdev->base))
return PTR_ERR(xdev->base);
rc = of_property_read_u32(pdev->dev.of_node, "clock-frequency", &pfreq);
if (rc)
dev_warn(&pdev->dev,
"The watchdog clock frequency cannot be obtained\n");
rc = of_property_read_u32(pdev->dev.of_node, "xlnx,wdt-interval",
&xdev->wdt_interval);
if (rc)
dev_warn(&pdev->dev,
"Parameter \"xlnx,wdt-interval\" not found\n");
rc = of_property_read_u32(pdev->dev.of_node, "xlnx,wdt-enable-once",
&enable_once);
if (rc)
dev_warn(&pdev->dev,
"Parameter \"xlnx,wdt-enable-once\" not found\n");
watchdog_set_nowayout(xilinx_wdt_wdd, enable_once);
if (pfreq && xdev->wdt_interval)
xilinx_wdt_wdd->timeout = 2 * ((1 << xdev->wdt_interval) /
pfreq);
spin_lock_init(&xdev->spinlock);
watchdog_set_drvdata(xilinx_wdt_wdd, xdev);
rc = xwdt_selftest(xdev);
if (rc == XWT_TIMER_FAILED) {
dev_err(&pdev->dev, "SelfTest routine error\n");
return rc;
}
rc = watchdog_register_device(xilinx_wdt_wdd);
if (rc) {
dev_err(&pdev->dev, "Cannot register watchdog (err=%d)\n", rc);
return rc;
}
dev_info(&pdev->dev, "Xilinx Watchdog Timer at %p with timeout %ds\n",
xdev->base, xilinx_wdt_wdd->timeout);
platform_set_drvdata(pdev, xdev);
return 0;
}
static int xwdt_remove(struct platform_device *pdev)
{
struct xwdt_device *xdev = platform_get_drvdata(pdev);
watchdog_unregister_device(&xdev->xilinx_wdt_wdd);
return 0;
}
