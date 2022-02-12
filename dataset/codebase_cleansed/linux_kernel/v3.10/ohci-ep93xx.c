static void ep93xx_start_hc(struct device *dev)
{
clk_enable(usb_host_clock);
}
static void ep93xx_stop_hc(struct device *dev)
{
clk_disable(usb_host_clock);
}
static int usb_hcd_ep93xx_probe(const struct hc_driver *driver,
struct platform_device *pdev)
{
int retval;
struct usb_hcd *hcd;
if (pdev->resource[1].flags != IORESOURCE_IRQ) {
dev_dbg(&pdev->dev, "resource[1] is not IORESOURCE_IRQ\n");
return -ENOMEM;
}
hcd = usb_create_hcd(driver, &pdev->dev, "ep93xx");
if (hcd == NULL)
return -ENOMEM;
hcd->rsrc_start = pdev->resource[0].start;
hcd->rsrc_len = pdev->resource[0].end - pdev->resource[0].start + 1;
if (!request_mem_region(hcd->rsrc_start, hcd->rsrc_len, hcd_name)) {
usb_put_hcd(hcd);
retval = -EBUSY;
goto err1;
}
hcd->regs = ioremap(hcd->rsrc_start, hcd->rsrc_len);
if (hcd->regs == NULL) {
dev_dbg(&pdev->dev, "ioremap failed\n");
retval = -ENOMEM;
goto err2;
}
usb_host_clock = clk_get(&pdev->dev, NULL);
if (IS_ERR(usb_host_clock)) {
dev_dbg(&pdev->dev, "clk_get failed\n");
retval = PTR_ERR(usb_host_clock);
goto err3;
}
ep93xx_start_hc(&pdev->dev);
ohci_hcd_init(hcd_to_ohci(hcd));
retval = usb_add_hcd(hcd, pdev->resource[1].start, 0);
if (retval == 0)
return retval;
ep93xx_stop_hc(&pdev->dev);
err3:
iounmap(hcd->regs);
err2:
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
err1:
usb_put_hcd(hcd);
return retval;
}
static void usb_hcd_ep93xx_remove(struct usb_hcd *hcd,
struct platform_device *pdev)
{
usb_remove_hcd(hcd);
ep93xx_stop_hc(&pdev->dev);
clk_put(usb_host_clock);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
}
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
int ret;
ret = -ENODEV;
if (!usb_disabled())
ret = usb_hcd_ep93xx_probe(&ohci_ep93xx_hc_driver, pdev);
return ret;
}
static int ohci_hcd_ep93xx_drv_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
usb_hcd_ep93xx_remove(hcd, pdev);
return 0;
}
static int ohci_hcd_ep93xx_drv_suspend(struct platform_device *pdev, pm_message_t state)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
ep93xx_stop_hc(&pdev->dev);
return 0;
}
static int ohci_hcd_ep93xx_drv_resume(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
if (time_before(jiffies, ohci->next_statechange))
msleep(5);
ohci->next_statechange = jiffies;
ep93xx_start_hc(&pdev->dev);
ohci_resume(hcd, false);
return 0;
}
