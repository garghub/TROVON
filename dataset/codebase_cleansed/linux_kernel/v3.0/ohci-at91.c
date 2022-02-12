static void at91_start_clock(void)
{
if (cpu_is_at91sam9261() || cpu_is_at91sam9g10())
clk_enable(hclk);
clk_enable(iclk);
clk_enable(fclk);
clocked = 1;
}
static void at91_stop_clock(void)
{
clk_disable(fclk);
clk_disable(iclk);
if (cpu_is_at91sam9261() || cpu_is_at91sam9g10())
clk_disable(hclk);
clocked = 0;
}
static void at91_start_hc(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_regs __iomem *regs = hcd->regs;
dev_dbg(&pdev->dev, "start\n");
at91_start_clock();
writel(0, &regs->control);
}
static void at91_stop_hc(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_regs __iomem *regs = hcd->regs;
dev_dbg(&pdev->dev, "stop\n");
writel(0, &regs->control);
at91_stop_clock();
}
static int usb_hcd_at91_probe(const struct hc_driver *driver,
struct platform_device *pdev)
{
int retval;
struct usb_hcd *hcd = NULL;
if (pdev->num_resources != 2) {
pr_debug("hcd probe: invalid num_resources");
return -ENODEV;
}
if ((pdev->resource[0].flags != IORESOURCE_MEM)
|| (pdev->resource[1].flags != IORESOURCE_IRQ)) {
pr_debug("hcd probe: invalid resource type\n");
return -ENODEV;
}
hcd = usb_create_hcd(driver, &pdev->dev, "at91");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = pdev->resource[0].start;
hcd->rsrc_len = pdev->resource[0].end - pdev->resource[0].start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
pr_debug("request_mem_region failed\n");
retval = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (!hcd->regs) {
pr_debug("ioremap failed\n");
retval = -EIO;
goto err2;
}
iclk = clk_get(&pdev->dev, "ohci_clk");
fclk = clk_get(&pdev->dev, "uhpck");
if (cpu_is_at91sam9261() || cpu_is_at91sam9g10())
hclk = clk_get(&pdev->dev, "hck0");
at91_start_hc(pdev);
ohci_hcd_init(hcd_to_ohci(hcd));
retval = usb_add_hcd(hcd, pdev->resource[1].start, IRQF_SHARED);
if (retval == 0)
return retval;
at91_stop_hc(pdev);
if (cpu_is_at91sam9261() || cpu_is_at91sam9g10())
clk_put(hclk);
clk_put(fclk);
clk_put(iclk);
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return retval;
}
static void usb_hcd_at91_remove(struct usb_hcd *hcd,
struct platform_device *pdev)
{
usb_remove_hcd(hcd);
at91_stop_hc(pdev);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
if (cpu_is_at91sam9261() || cpu_is_at91sam9g10())
clk_put(hclk);
clk_put(fclk);
clk_put(iclk);
fclk = iclk = hclk = NULL;
dev_set_drvdata(&pdev->dev, NULL);
}
static int __devinit
ohci_at91_start (struct usb_hcd *hcd)
{
struct at91_usbh_data *board = hcd->self.controller->platform_data;
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
int ret;
if ((ret = ohci_init(ohci)) < 0)
return ret;
ohci->num_ports = board->ports;
if ((ret = ohci_run(ohci)) < 0) {
err("can't start %s", hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_hcd_at91_drv_probe(struct platform_device *pdev)
{
struct at91_usbh_data *pdata = pdev->dev.platform_data;
int i;
if (pdata) {
for (i = 0; i < ARRAY_SIZE(pdata->vbus_pin); i++) {
if (pdata->vbus_pin[i] <= 0)
continue;
gpio_request(pdata->vbus_pin[i], "ohci_vbus");
gpio_direction_output(pdata->vbus_pin[i], 0);
}
}
device_init_wakeup(&pdev->dev, 1);
return usb_hcd_at91_probe(&ohci_at91_hc_driver, pdev);
}
static int ohci_hcd_at91_drv_remove(struct platform_device *pdev)
{
struct at91_usbh_data *pdata = pdev->dev.platform_data;
int i;
if (pdata) {
for (i = 0; i < ARRAY_SIZE(pdata->vbus_pin); i++) {
if (pdata->vbus_pin[i] <= 0)
continue;
gpio_direction_output(pdata->vbus_pin[i], 1);
gpio_free(pdata->vbus_pin[i]);
}
}
device_init_wakeup(&pdev->dev, 0);
usb_hcd_at91_remove(platform_get_drvdata(pdev), pdev);
return 0;
}
static int
ohci_hcd_at91_drv_suspend(struct platform_device *pdev, pm_message_t mesg)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(hcd->irq);
if (at91_suspend_entering_slow_clock()) {
ohci_usb_reset (ohci);
(void) ohci_readl (ohci, &ohci->regs->control);
at91_stop_clock();
}
return 0;
}
static int ohci_hcd_at91_drv_resume(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
if (device_may_wakeup(&pdev->dev))
disable_irq_wake(hcd->irq);
if (!clocked)
at91_start_clock();
ohci_finish_controller_resume(hcd);
return 0;
}
