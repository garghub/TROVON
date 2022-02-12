static void at91_start_clock(void)
{
clk_enable(hclk);
clk_enable(iclk);
clk_enable(fclk);
clocked = 1;
}
static void at91_stop_clock(void)
{
clk_disable(fclk);
clk_disable(iclk);
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
if (IS_ERR(iclk)) {
dev_err(&pdev->dev, "failed to get ohci_clk\n");
retval = PTR_ERR(iclk);
goto err3;
}
fclk = clk_get(&pdev->dev, "uhpck");
if (IS_ERR(fclk)) {
dev_err(&pdev->dev, "failed to get uhpck\n");
retval = PTR_ERR(fclk);
goto err4;
}
hclk = clk_get(&pdev->dev, "hclk");
if (IS_ERR(hclk)) {
dev_err(&pdev->dev, "failed to get hclk\n");
retval = PTR_ERR(hclk);
goto err5;
}
at91_start_hc(pdev);
ohci_hcd_init(hcd_to_ohci(hcd));
retval = usb_add_hcd(hcd, pdev->resource[1].start, IRQF_SHARED);
if (retval == 0)
return retval;
at91_stop_hc(pdev);
clk_put(hclk);
err5:
clk_put(fclk);
err4:
clk_put(iclk);
err3:
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
static void ohci_at91_usb_set_power(struct at91_usbh_data *pdata, int port, int enable)
{
if (port < 0 || port >= 2)
return;
if (!gpio_is_valid(pdata->vbus_pin[port]))
return;
gpio_set_value(pdata->vbus_pin[port],
!pdata->vbus_pin_active_low[port] ^ enable);
}
static int ohci_at91_usb_get_power(struct at91_usbh_data *pdata, int port)
{
if (port < 0 || port >= 2)
return -EINVAL;
if (!gpio_is_valid(pdata->vbus_pin[port]))
return -EINVAL;
return gpio_get_value(pdata->vbus_pin[port]) ^
!pdata->vbus_pin_active_low[port];
}
static int ohci_at91_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct at91_usbh_data *pdata = hcd->self.controller->platform_data;
int length = ohci_hub_status_data(hcd, buf);
int port;
for (port = 0; port < ARRAY_SIZE(pdata->overcurrent_pin); port++) {
if (pdata->overcurrent_changed[port]) {
if (! length)
length = 1;
buf[0] |= 1 << (port + 1);
}
}
return length;
}
static int ohci_at91_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct at91_usbh_data *pdata = hcd->self.controller->platform_data;
struct usb_hub_descriptor *desc;
int ret = -EINVAL;
u32 *data = (u32 *)buf;
dev_dbg(hcd->self.controller,
"ohci_at91_hub_control(%p,0x%04x,0x%04x,0x%04x,%p,%04x)\n",
hcd, typeReq, wValue, wIndex, buf, wLength);
switch (typeReq) {
case SetPortFeature:
if (wValue == USB_PORT_FEAT_POWER) {
dev_dbg(hcd->self.controller, "SetPortFeat: POWER\n");
ohci_at91_usb_set_power(pdata, wIndex - 1, 1);
goto out;
}
break;
case ClearPortFeature:
switch (wValue) {
case USB_PORT_FEAT_C_OVER_CURRENT:
dev_dbg(hcd->self.controller,
"ClearPortFeature: C_OVER_CURRENT\n");
if (wIndex == 1 || wIndex == 2) {
pdata->overcurrent_changed[wIndex-1] = 0;
pdata->overcurrent_status[wIndex-1] = 0;
}
goto out;
case USB_PORT_FEAT_OVER_CURRENT:
dev_dbg(hcd->self.controller,
"ClearPortFeature: OVER_CURRENT\n");
if (wIndex == 1 || wIndex == 2) {
pdata->overcurrent_status[wIndex-1] = 0;
}
goto out;
case USB_PORT_FEAT_POWER:
dev_dbg(hcd->self.controller,
"ClearPortFeature: POWER\n");
if (wIndex == 1 || wIndex == 2) {
ohci_at91_usb_set_power(pdata, wIndex - 1, 0);
return 0;
}
}
break;
}
ret = ohci_hub_control(hcd, typeReq, wValue, wIndex, buf, wLength);
if (ret)
goto out;
switch (typeReq) {
case GetHubDescriptor:
desc = (struct usb_hub_descriptor *)buf;
dev_dbg(hcd->self.controller, "wHubCharacteristics 0x%04x\n",
desc->wHubCharacteristics);
desc->wHubCharacteristics &= ~cpu_to_le16(HUB_CHAR_LPSM);
desc->wHubCharacteristics |= cpu_to_le16(0x0001);
if (pdata->overcurrent_supported) {
desc->wHubCharacteristics &= ~cpu_to_le16(HUB_CHAR_OCPM);
desc->wHubCharacteristics |= cpu_to_le16(0x0008|0x0001);
}
dev_dbg(hcd->self.controller, "wHubCharacteristics after 0x%04x\n",
desc->wHubCharacteristics);
return ret;
case GetPortStatus:
dev_dbg(hcd->self.controller, "GetPortStatus(%d)\n", wIndex);
if (wIndex == 1 || wIndex == 2) {
if (! ohci_at91_usb_get_power(pdata, wIndex-1)) {
*data &= ~cpu_to_le32(RH_PS_PPS);
}
if (pdata->overcurrent_changed[wIndex-1]) {
*data |= cpu_to_le32(RH_PS_OCIC);
}
if (pdata->overcurrent_status[wIndex-1]) {
*data |= cpu_to_le32(RH_PS_POCI);
}
}
}
out:
return ret;
}
static irqreturn_t ohci_hcd_at91_overcurrent_irq(int irq, void *data)
{
struct platform_device *pdev = data;
struct at91_usbh_data *pdata = pdev->dev.platform_data;
int val, gpio, port;
gpio = irq_to_gpio(irq);
for (port = 0; port < ARRAY_SIZE(pdata->overcurrent_pin); port++) {
if (pdata->overcurrent_pin[port] == gpio)
break;
}
if (port == ARRAY_SIZE(pdata->overcurrent_pin)) {
dev_err(& pdev->dev, "overcurrent interrupt from unknown GPIO\n");
return IRQ_HANDLED;
}
val = gpio_get_value(gpio);
if (! val) {
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
struct at91_usbh_data *pdata = pdev->dev.platform_data;
int i;
if (pdata) {
for (i = 0; i < ARRAY_SIZE(pdata->vbus_pin); i++) {
if (!gpio_is_valid(pdata->vbus_pin[i]))
continue;
gpio_request(pdata->vbus_pin[i], "ohci_vbus");
ohci_at91_usb_set_power(pdata, i, 1);
}
for (i = 0; i < ARRAY_SIZE(pdata->overcurrent_pin); i++) {
int ret;
if (!gpio_is_valid(pdata->overcurrent_pin[i]))
continue;
gpio_request(pdata->overcurrent_pin[i], "ohci_overcurrent");
ret = request_irq(gpio_to_irq(pdata->overcurrent_pin[i]),
ohci_hcd_at91_overcurrent_irq,
IRQF_SHARED, "ohci_overcurrent", pdev);
if (ret) {
gpio_free(pdata->overcurrent_pin[i]);
dev_warn(& pdev->dev, "cannot get GPIO IRQ for overcurrent\n");
}
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
if (!gpio_is_valid(pdata->vbus_pin[i]))
continue;
ohci_at91_usb_set_power(pdata, i, 0);
gpio_free(pdata->vbus_pin[i]);
}
for (i = 0; i < ARRAY_SIZE(pdata->overcurrent_pin); i++) {
if (!gpio_is_valid(pdata->overcurrent_pin[i]))
continue;
free_irq(gpio_to_irq(pdata->overcurrent_pin[i]), pdev);
gpio_free(pdata->overcurrent_pin[i]);
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
