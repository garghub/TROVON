static int ohci_ep93xx_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
if ((ret = ohci_init(ohci)) < 0)
return ret;
if ((ret = ohci_run(ohci)) < 0) {
dev_err(hcd->self.controller, "can't start %s\n",
hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_hcd_ep93xx_drv_probe(struct platform_device *pdev)
{
struct usb_hcd *hcd;
struct resource *res;
int irq;
int ret;
if (usb_disabled())
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
hcd = usb_create_hcd(&ohci_ep93xx_hc_driver, &pdev->dev, "ep93xx");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(hcd->regs)) {
ret = PTR_ERR(hcd->regs);
goto err_put_hcd;
}
usb_host_clock = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(usb_host_clock)) {
ret = PTR_ERR(usb_host_clock);
goto err_put_hcd;
}
clk_enable(usb_host_clock);
ohci_hcd_init(hcd_to_ohci(hcd));
ret = usb_add_hcd(hcd, irq, 0);
if (ret)
goto err_clk_disable;
return 0;
err_clk_disable:
clk_disable(usb_host_clock);
err_put_hcd:
usb_put_hcd(hcd);
return ret;
}
static int ohci_hcd_ep93xx_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_remove_hcd(hcd);
clk_disable(usb_host_clock);
usb_put_hcd(hcd);
return 0;
}
static int ohci_hcd_ep93xx_drv_suspend(struct platform_device *pdev, pm_message_t state)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
clk_disable(usb_host_clock);
return 0;
}
static int ohci_hcd_ep93xx_drv_resume(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
clk_enable(usb_host_clock);
ohci_resume(hcd, false);
return 0;
}
