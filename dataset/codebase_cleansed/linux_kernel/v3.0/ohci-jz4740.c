static inline struct jz4740_ohci_hcd *hcd_to_jz4740_hcd(struct usb_hcd *hcd)
{
return (struct jz4740_ohci_hcd *)(hcd->hcd_priv);
}
static inline struct usb_hcd *jz4740_hcd_to_hcd(struct jz4740_ohci_hcd *jz4740_ohci)
{
return container_of((void *)jz4740_ohci, struct usb_hcd, hcd_priv);
}
static int ohci_jz4740_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ret = ohci_init(ohci);
if (ret < 0)
return ret;
ohci->num_ports = 1;
ret = ohci_run(ohci);
if (ret < 0) {
dev_err(hcd->self.controller, "Can not start %s",
hcd->self.bus_name);
ohci_stop(hcd);
return ret;
}
return 0;
}
static int ohci_jz4740_set_vbus_power(struct jz4740_ohci_hcd *jz4740_ohci,
bool enabled)
{
int ret = 0;
if (!jz4740_ohci->vbus)
return 0;
if (enabled && !jz4740_ohci->vbus_enabled) {
ret = regulator_enable(jz4740_ohci->vbus);
if (ret)
dev_err(jz4740_hcd_to_hcd(jz4740_ohci)->self.controller,
"Could not power vbus\n");
} else if (!enabled && jz4740_ohci->vbus_enabled) {
ret = regulator_disable(jz4740_ohci->vbus);
}
if (ret == 0)
jz4740_ohci->vbus_enabled = enabled;
return ret;
}
static int ohci_jz4740_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct jz4740_ohci_hcd *jz4740_ohci = hcd_to_jz4740_hcd(hcd);
int ret;
switch (typeReq) {
case SetHubFeature:
if (wValue == USB_PORT_FEAT_POWER)
ret = ohci_jz4740_set_vbus_power(jz4740_ohci, true);
break;
case ClearHubFeature:
if (wValue == USB_PORT_FEAT_POWER)
ret = ohci_jz4740_set_vbus_power(jz4740_ohci, false);
break;
}
if (ret)
return ret;
return ohci_hub_control(hcd, typeReq, wValue, wIndex, buf, wLength);
}
static __devinit int jz4740_ohci_probe(struct platform_device *pdev)
{
int ret;
struct usb_hcd *hcd;
struct jz4740_ohci_hcd *jz4740_ohci;
struct resource *res;
int irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Failed to get platform resource\n");
return -ENOENT;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "Failed to get platform irq\n");
return irq;
}
hcd = usb_create_hcd(&ohci_jz4740_hc_driver, &pdev->dev, "jz4740");
if (!hcd) {
dev_err(&pdev->dev, "Failed to create hcd.\n");
return -ENOMEM;
}
jz4740_ohci = hcd_to_jz4740_hcd(hcd);
res = request_mem_region(res->start, resource_size(res), hcd_name);
if (!res) {
dev_err(&pdev->dev, "Failed to request mem region.\n");
ret = -EBUSY;
goto err_free;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
hcd->regs = ioremap(res->start, resource_size(res));
if (!hcd->regs) {
dev_err(&pdev->dev, "Failed to ioremap registers.\n");
ret = -EBUSY;
goto err_release_mem;
}
jz4740_ohci->clk = clk_get(&pdev->dev, "uhc");
if (IS_ERR(jz4740_ohci->clk)) {
ret = PTR_ERR(jz4740_ohci->clk);
dev_err(&pdev->dev, "Failed to get clock: %d\n", ret);
goto err_iounmap;
}
jz4740_ohci->vbus = regulator_get(&pdev->dev, "vbus");
if (IS_ERR(jz4740_ohci->vbus))
jz4740_ohci->vbus = NULL;
clk_set_rate(jz4740_ohci->clk, 48000000);
clk_enable(jz4740_ohci->clk);
if (jz4740_ohci->vbus)
ohci_jz4740_set_vbus_power(jz4740_ohci, true);
platform_set_drvdata(pdev, hcd);
ohci_hcd_init(hcd_to_ohci(hcd));
ret = usb_add_hcd(hcd, irq, 0);
if (ret) {
dev_err(&pdev->dev, "Failed to add hcd: %d\n", ret);
goto err_disable;
}
return 0;
err_disable:
platform_set_drvdata(pdev, NULL);
if (jz4740_ohci->vbus) {
regulator_disable(jz4740_ohci->vbus);
regulator_put(jz4740_ohci->vbus);
}
clk_disable(jz4740_ohci->clk);
clk_put(jz4740_ohci->clk);
err_iounmap:
iounmap(hcd->regs);
err_release_mem:
release_mem_region(res->start, resource_size(res));
err_free:
usb_put_hcd(hcd);
return ret;
}
static __devexit int jz4740_ohci_remove(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct jz4740_ohci_hcd *jz4740_ohci = hcd_to_jz4740_hcd(hcd);
usb_remove_hcd(hcd);
platform_set_drvdata(pdev, NULL);
if (jz4740_ohci->vbus) {
regulator_disable(jz4740_ohci->vbus);
regulator_put(jz4740_ohci->vbus);
}
clk_disable(jz4740_ohci->clk);
clk_put(jz4740_ohci->clk);
iounmap(hcd->regs);
release_mem_region(hcd->rsrc_start, hcd->rsrc_len);
usb_put_hcd(hcd);
return 0;
}
