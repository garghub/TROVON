static void at91_start_clock(struct ohci_at91_priv *ohci_at91)
{
if (ohci_at91->clocked)
return;
clk_set_rate(ohci_at91->fclk, 48000000);
clk_prepare_enable(ohci_at91->hclk);
clk_prepare_enable(ohci_at91->iclk);
clk_prepare_enable(ohci_at91->fclk);
ohci_at91->clocked = true;
}
static void at91_stop_clock(struct ohci_at91_priv *ohci_at91)
{
if (!ohci_at91->clocked)
return;
clk_disable_unprepare(ohci_at91->fclk);
clk_disable_unprepare(ohci_at91->iclk);
clk_disable_unprepare(ohci_at91->hclk);
ohci_at91->clocked = false;
}
static void at91_start_hc(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_regs __iomem *regs = hcd->regs;
struct ohci_at91_priv *ohci_at91 = hcd_to_ohci_at91_priv(hcd);
dev_dbg(&pdev->dev, "start\n");
at91_start_clock(ohci_at91);
writel(0, &regs->control);
}
static void at91_stop_hc(struct platform_device *pdev)
{
struct usb_hcd *hcd = platform_get_drvdata(pdev);
struct ohci_regs __iomem *regs = hcd->regs;
struct ohci_at91_priv *ohci_at91 = hcd_to_ohci_at91_priv(hcd);
dev_dbg(&pdev->dev, "stop\n");
writel(0, &regs->control);
at91_stop_clock(ohci_at91);
}
static struct regmap *at91_dt_syscon_sfr(void)
{
struct regmap *regmap;
regmap = syscon_regmap_lookup_by_compatible("atmel,sama5d2-sfr");
if (IS_ERR(regmap))
regmap = NULL;
return regmap;
}
static int usb_hcd_at91_probe(const struct hc_driver *driver,
struct platform_device *pdev)
{
struct at91_usbh_data *board;
struct ohci_hcd *ohci;
int retval;
struct usb_hcd *hcd;
struct ohci_at91_priv *ohci_at91;
struct device *dev = &pdev->dev;
struct resource *res;
int irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_dbg(dev, "hcd probe: missing irq resource\n");
return irq;
}
hcd = usb_create_hcd(driver, dev, "at91");
if (!hcd)
return -ENOMEM;
ohci_at91 = hcd_to_ohci_at91_priv(hcd);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
hcd->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto err;
}
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
ohci_at91->iclk = devm_clk_get(dev, "ohci_clk");
if (IS_ERR(ohci_at91->iclk)) {
dev_err(dev, "failed to get ohci_clk\n");
retval = PTR_ERR(ohci_at91->iclk);
goto err;
}
ohci_at91->fclk = devm_clk_get(dev, "uhpck");
if (IS_ERR(ohci_at91->fclk)) {
dev_err(dev, "failed to get uhpck\n");
retval = PTR_ERR(ohci_at91->fclk);
goto err;
}
ohci_at91->hclk = devm_clk_get(dev, "hclk");
if (IS_ERR(ohci_at91->hclk)) {
dev_err(dev, "failed to get hclk\n");
retval = PTR_ERR(ohci_at91->hclk);
goto err;
}
ohci_at91->sfr_regmap = at91_dt_syscon_sfr();
if (!ohci_at91->sfr_regmap)
dev_warn(dev, "failed to find sfr node\n");
board = hcd->self.controller->platform_data;
ohci = hcd_to_ohci(hcd);
ohci->num_ports = board->ports;
at91_start_hc(pdev);
ohci->hc_control = OHCI_CTRL_RWC;
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval == 0) {
device_wakeup_enable(hcd->self.controller);
return retval;
}
at91_stop_hc(pdev);
err:
usb_put_hcd(hcd);
return retval;
}
static void usb_hcd_at91_remove(struct usb_hcd *hcd,
struct platform_device *pdev)
{
usb_remove_hcd(hcd);
at91_stop_hc(pdev);
usb_put_hcd(hcd);
}
static void ohci_at91_usb_set_power(struct at91_usbh_data *pdata, int port, int enable)
{
if (!valid_port(port))
return;
gpiod_set_value(pdata->vbus_pin[port], enable);
}
static int ohci_at91_usb_get_power(struct at91_usbh_data *pdata, int port)
{
if (!valid_port(port))
return -EINVAL;
return gpiod_get_value(pdata->vbus_pin[port]);
}
static int ohci_at91_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct at91_usbh_data *pdata = hcd->self.controller->platform_data;
int length = ohci_hub_status_data(hcd, buf);
int port;
at91_for_each_port(port) {
if (pdata->overcurrent_changed[port]) {
if (!length)
length = 1;
buf[0] |= 1 << (port + 1);
}
}
return length;
}
static int ohci_at91_port_suspend(struct regmap *regmap, u8 set)
{
u32 regval;
int ret;
if (!regmap)
return 0;
ret = regmap_read(regmap, AT91_SFR_OHCIICR, &regval);
if (ret)
return ret;
if (set)
regval |= AT91_OHCIICR_USB_SUSPEND;
else
regval &= ~AT91_OHCIICR_USB_SUSPEND;
regmap_write(regmap, AT91_SFR_OHCIICR, regval);
return 0;
}
static int ohci_at91_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct at91_usbh_data *pdata = dev_get_platdata(hcd->self.controller);
struct ohci_at91_priv *ohci_at91 = hcd_to_ohci_at91_priv(hcd);
struct usb_hub_descriptor *desc;
int ret = -EINVAL;
u32 *data = (u32 *)buf;
dev_dbg(hcd->self.controller,
"ohci_at91_hub_control(%p,0x%04x,0x%04x,0x%04x,%p,%04x)\n",
hcd, typeReq, wValue, wIndex, buf, wLength);
wIndex--;
switch (typeReq) {
case SetPortFeature:
switch (wValue) {
case USB_PORT_FEAT_POWER:
dev_dbg(hcd->self.controller, "SetPortFeat: POWER\n");
if (valid_port(wIndex)) {
ohci_at91_usb_set_power(pdata, wIndex, 1);
ret = 0;
}
goto out;
case USB_PORT_FEAT_SUSPEND:
dev_dbg(hcd->self.controller, "SetPortFeat: SUSPEND\n");
if (valid_port(wIndex) && ohci_at91->sfr_regmap) {
ohci_at91_port_suspend(ohci_at91->sfr_regmap,
1);
return 0;
}
break;
}
break;
case ClearPortFeature:
switch (wValue) {
case USB_PORT_FEAT_C_OVER_CURRENT:
dev_dbg(hcd->self.controller,
"ClearPortFeature: C_OVER_CURRENT\n");
if (valid_port(wIndex)) {
pdata->overcurrent_changed[wIndex] = 0;
pdata->overcurrent_status[wIndex] = 0;
}
goto out;
case USB_PORT_FEAT_OVER_CURRENT:
dev_dbg(hcd->self.controller,
"ClearPortFeature: OVER_CURRENT\n");
if (valid_port(wIndex))
pdata->overcurrent_status[wIndex] = 0;
goto out;
case USB_PORT_FEAT_POWER:
dev_dbg(hcd->self.controller,
"ClearPortFeature: POWER\n");
if (valid_port(wIndex)) {
ohci_at91_usb_set_power(pdata, wIndex, 0);
return 0;
}
break;
case USB_PORT_FEAT_SUSPEND:
dev_dbg(hcd->self.controller, "ClearPortFeature: SUSPEND\n");
if (valid_port(wIndex) && ohci_at91->sfr_regmap) {
ohci_at91_port_suspend(ohci_at91->sfr_regmap,
0);
return 0;
}
break;
}
break;
}
ret = ohci_hub_control(hcd, typeReq, wValue, wIndex + 1, buf, wLength);
if (ret)
goto out;
switch (typeReq) {
case GetHubDescriptor:
desc = (struct usb_hub_descriptor *)buf;
dev_dbg(hcd->self.controller, "wHubCharacteristics 0x%04x\n",
desc->wHubCharacteristics);
desc->wHubCharacteristics &= ~cpu_to_le16(HUB_CHAR_LPSM);
desc->wHubCharacteristics |=
cpu_to_le16(HUB_CHAR_INDV_PORT_LPSM);
if (pdata->overcurrent_supported) {
desc->wHubCharacteristics &= ~cpu_to_le16(HUB_CHAR_OCPM);
desc->wHubCharacteristics |=
cpu_to_le16(HUB_CHAR_INDV_PORT_OCPM);
}
dev_dbg(hcd->self.controller, "wHubCharacteristics after 0x%04x\n",
desc->wHubCharacteristics);
return ret;
case GetPortStatus:
dev_dbg(hcd->self.controller, "GetPortStatus(%d)\n", wIndex);
if (valid_port(wIndex)) {
if (!ohci_at91_usb_get_power(pdata, wIndex))
*data &= ~cpu_to_le32(RH_PS_PPS);
if (pdata->overcurrent_changed[wIndex])
*data |= cpu_to_le32(RH_PS_OCIC);
if (pdata->overcurrent_status[wIndex])
*data |= cpu_to_le32(RH_PS_POCI);
}
}
out:
return ret;
}
static irqreturn_t ohci_hcd_at91_overcurrent_irq(int irq, void *data)
{
struct platform_device *pdev = data;
struct at91_usbh_data *pdata = dev_get_platdata(&pdev->dev);
int val, port;
at91_for_each_port(port) {
if (gpiod_to_irq(pdata->overcurrent_pin[port]) == irq)
break;
}
if (port == AT91_MAX_USBH_PORTS) {
dev_err(& pdev->dev, "overcurrent interrupt from unknown GPIO\n");
return IRQ_HANDLED;
}
val = gpiod_get_value(pdata->overcurrent_pin[port]);
if (!val) {
ohci_at91_usb_set_power(pdata, port, 0);
pdata->overcurrent_status[port] = 1;
pdata->overcurrent_changed[port] = 1;
}
dev_dbg(& pdev->dev, "overcurrent situation %s\n",
val ? "exited" : "notified");
return IRQ_HANDLED;
}
static int ohci_hcd_at91_drv_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct at91_usbh_data *pdata;
int i;
int ret;
int err;
u32 ports;
ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdev->dev.platform_data = pdata;
if (!of_property_read_u32(np, "num-ports", &ports))
pdata->ports = ports;
at91_for_each_port(i) {
if (i >= pdata->ports)
break;
pdata->vbus_pin[i] =
devm_gpiod_get_index_optional(&pdev->dev, "atmel,vbus",
i, GPIOD_OUT_HIGH);
if (IS_ERR(pdata->vbus_pin[i])) {
err = PTR_ERR(pdata->vbus_pin[i]);
dev_err(&pdev->dev, "unable to claim gpio \"vbus\": %d\n", err);
continue;
}
}
at91_for_each_port(i) {
if (i >= pdata->ports)
break;
pdata->overcurrent_pin[i] =
devm_gpiod_get_index_optional(&pdev->dev, "atmel,oc",
i, GPIOD_IN);
if (IS_ERR(pdata->overcurrent_pin[i])) {
err = PTR_ERR(pdata->overcurrent_pin[i]);
dev_err(&pdev->dev, "unable to claim gpio \"overcurrent\": %d\n", err);
continue;
}
ret = devm_request_irq(&pdev->dev,
gpiod_to_irq(pdata->overcurrent_pin[i]),
ohci_hcd_at91_overcurrent_irq,
IRQF_SHARED,
"ohci_overcurrent", pdev);
if (ret)
dev_info(&pdev->dev, "failed to request gpio \"overcurrent\" IRQ\n");
}
device_init_wakeup(&pdev->dev, 1);
return usb_hcd_at91_probe(&ohci_at91_hc_driver, pdev);
}
static int ohci_hcd_at91_drv_remove(struct platform_device *pdev)
{
struct at91_usbh_data *pdata = dev_get_platdata(&pdev->dev);
int i;
if (pdata) {
at91_for_each_port(i)
ohci_at91_usb_set_power(pdata, i, 0);
}
device_init_wakeup(&pdev->dev, 0);
usb_hcd_at91_remove(platform_get_drvdata(pdev), pdev);
return 0;
}
static int __maybe_unused
ohci_hcd_at91_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
struct ohci_at91_priv *ohci_at91 = hcd_to_ohci_at91_priv(hcd);
int ret;
ohci_at91->wakeup = device_may_wakeup(dev)
&& !at91_suspend_entering_slow_clock();
if (ohci_at91->wakeup)
enable_irq_wake(hcd->irq);
ohci_at91_port_suspend(ohci_at91->sfr_regmap, 1);
ret = ohci_suspend(hcd, ohci_at91->wakeup);
if (ret) {
if (ohci_at91->wakeup)
disable_irq_wake(hcd->irq);
return ret;
}
if (!ohci_at91->wakeup) {
ohci->rh_state = OHCI_RH_HALTED;
(void) ohci_readl (ohci, &ohci->regs->control);
at91_stop_clock(ohci_at91);
}
return ret;
}
static int __maybe_unused
ohci_hcd_at91_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct ohci_at91_priv *ohci_at91 = hcd_to_ohci_at91_priv(hcd);
if (ohci_at91->wakeup)
disable_irq_wake(hcd->irq);
at91_start_clock(ohci_at91);
ohci_resume(hcd, false);
ohci_at91_port_suspend(ohci_at91->sfr_regmap, 0);
return 0;
}
static int __init ohci_at91_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_at91_hc_driver, &ohci_at91_drv_overrides);
ohci_at91_hc_driver.hub_status_data = ohci_at91_hub_status_data;
ohci_at91_hc_driver.hub_control = ohci_at91_hub_control;
return platform_driver_register(&ohci_hcd_at91_driver);
}
static void __exit ohci_at91_cleanup(void)
{
platform_driver_unregister(&ohci_hcd_at91_driver);
}
