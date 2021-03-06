static void at91_start_clock(void)
{
if (IS_ENABLED(CONFIG_COMMON_CLK)) {
clk_set_rate(uclk, 48000000);
clk_prepare_enable(uclk);
}
clk_prepare_enable(hclk);
clk_prepare_enable(iclk);
clk_prepare_enable(fclk);
clocked = 1;
}
static void at91_stop_clock(void)
{
clk_disable_unprepare(fclk);
clk_disable_unprepare(iclk);
clk_disable_unprepare(hclk);
if (IS_ENABLED(CONFIG_COMMON_CLK))
clk_disable_unprepare(uclk);
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
struct at91_usbh_data *board;
struct ohci_hcd *ohci;
int retval;
struct usb_hcd *hcd = NULL;
struct device *dev = &pdev->dev;
struct resource *res;
int irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_dbg(dev, "hcd probe: missing memory resource\n");
return -ENXIO;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_dbg(dev, "hcd probe: missing irq resource\n");
return irq;
}
hcd = usb_create_hcd(driver, &pdev->dev, "at91");
if (!hcd)
return -ENOMEM;
hcd->rsrc_start = res->start;
hcd->rsrc_len = resource_size(res);
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
if (IS_ENABLED(CONFIG_COMMON_CLK)) {
uclk = clk_get(&pdev->dev, "usb_clk");
if (IS_ERR(uclk)) {
dev_err(&pdev->dev, "failed to get uclk\n");
retval = PTR_ERR(uclk);
goto err6;
}
}
board = hcd->self.controller->platform_data;
ohci = hcd_to_ohci(hcd);
ohci->num_ports = board->ports;
at91_start_hc(pdev);
retval = usb_add_hcd(hcd, irq, IRQF_SHARED);
if (retval == 0)
return retval;
at91_stop_hc(pdev);
if (IS_ENABLED(CONFIG_COMMON_CLK))
clk_put(uclk);
err6:
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
if (IS_ENABLED(CONFIG_COMMON_CLK))
clk_put(uclk);
clk_put(hclk);
clk_put(fclk);
clk_put(iclk);
fclk = iclk = hclk = NULL;
}
static void ohci_at91_usb_set_power(struct at91_usbh_data *pdata, int port, int enable)
{
if (!valid_port(port))
return;
if (!gpio_is_valid(pdata->vbus_pin[port]))
return;
gpio_set_value(pdata->vbus_pin[port],
pdata->vbus_pin_active_low[port] ^ enable);
}
static int ohci_at91_usb_get_power(struct at91_usbh_data *pdata, int port)
{
if (!valid_port(port))
return -EINVAL;
if (!gpio_is_valid(pdata->vbus_pin[port]))
return -EINVAL;
return gpio_get_value(pdata->vbus_pin[port]) ^
pdata->vbus_pin_active_low[port];
}
static int ohci_at91_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct at91_usbh_data *pdata = hcd->self.controller->platform_data;
int length = orig_ohci_hub_status_data(hcd, buf);
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
static int ohci_at91_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct at91_usbh_data *pdata = dev_get_platdata(hcd->self.controller);
struct usb_hub_descriptor *desc;
int ret = -EINVAL;
u32 *data = (u32 *)buf;
dev_dbg(hcd->self.controller,
"ohci_at91_hub_control(%p,0x%04x,0x%04x,0x%04x,%p,%04x)\n",
hcd, typeReq, wValue, wIndex, buf, wLength);
wIndex--;
switch (typeReq) {
case SetPortFeature:
if (wValue == USB_PORT_FEAT_POWER) {
dev_dbg(hcd->self.controller, "SetPortFeat: POWER\n");
if (valid_port(wIndex)) {
ohci_at91_usb_set_power(pdata, wIndex, 1);
ret = 0;
}
goto out;
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
}
break;
}
ret = orig_ohci_hub_control(hcd, typeReq, wValue, wIndex + 1,
buf, wLength);
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
int val, gpio, port;
at91_for_each_port(port) {
if (gpio_is_valid(pdata->overcurrent_pin[port]) &&
gpio_to_irq(pdata->overcurrent_pin[port]) == irq) {
gpio = pdata->overcurrent_pin[port];
break;
}
}
if (port == AT91_MAX_USBH_PORTS) {
dev_err(& pdev->dev, "overcurrent interrupt from unknown GPIO\n");
return IRQ_HANDLED;
}
val = gpio_get_value(gpio);
if (!val) {
ohci_at91_usb_set_power(pdata, port, 0);
pdata->overcurrent_status[port] = 1;
pdata->overcurrent_changed[port] = 1;
}
dev_dbg(& pdev->dev, "overcurrent situation %s\n",
val ? "exited" : "notified");
return IRQ_HANDLED;
}
static int ohci_at91_of_init(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
int i, gpio, ret;
enum of_gpio_flags flags;
struct at91_usbh_data *pdata;
u32 ports;
if (!np)
return 0;
ret = dma_coerce_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (!of_property_read_u32(np, "num-ports", &ports))
pdata->ports = ports;
at91_for_each_port(i) {
gpio = of_get_named_gpio_flags(np, "atmel,vbus-gpio", i, &flags);
pdata->vbus_pin[i] = gpio;
if (!gpio_is_valid(gpio))
continue;
pdata->vbus_pin_active_low[i] = flags & OF_GPIO_ACTIVE_LOW;
}
at91_for_each_port(i)
pdata->overcurrent_pin[i] =
of_get_named_gpio_flags(np, "atmel,oc-gpio", i, &flags);
pdev->dev.platform_data = pdata;
return 0;
}
static int ohci_at91_of_init(struct platform_device *pdev)
{
return 0;
}
static int ohci_hcd_at91_drv_probe(struct platform_device *pdev)
{
struct at91_usbh_data *pdata;
int i;
int gpio;
int ret;
ret = ohci_at91_of_init(pdev);
if (ret)
return ret;
pdata = dev_get_platdata(&pdev->dev);
if (pdata) {
at91_for_each_port(i) {
if (i >= pdata->ports) {
pdata->vbus_pin[i] = -EINVAL;
pdata->overcurrent_pin[i] = -EINVAL;
break;
}
if (!gpio_is_valid(pdata->vbus_pin[i]))
continue;
gpio = pdata->vbus_pin[i];
ret = gpio_request(gpio, "ohci_vbus");
if (ret) {
dev_err(&pdev->dev,
"can't request vbus gpio %d\n", gpio);
continue;
}
ret = gpio_direction_output(gpio,
!pdata->vbus_pin_active_low[i]);
if (ret) {
dev_err(&pdev->dev,
"can't put vbus gpio %d as output %d\n",
gpio, !pdata->vbus_pin_active_low[i]);
gpio_free(gpio);
continue;
}
ohci_at91_usb_set_power(pdata, i, 1);
}
at91_for_each_port(i) {
if (!gpio_is_valid(pdata->overcurrent_pin[i]))
continue;
gpio = pdata->overcurrent_pin[i];
ret = gpio_request(gpio, "ohci_overcurrent");
if (ret) {
dev_err(&pdev->dev,
"can't request overcurrent gpio %d\n",
gpio);
continue;
}
ret = gpio_direction_input(gpio);
if (ret) {
dev_err(&pdev->dev,
"can't configure overcurrent gpio %d as input\n",
gpio);
gpio_free(gpio);
continue;
}
ret = request_irq(gpio_to_irq(gpio),
ohci_hcd_at91_overcurrent_irq,
IRQF_SHARED, "ohci_overcurrent", pdev);
if (ret) {
gpio_free(gpio);
dev_err(&pdev->dev,
"can't get gpio IRQ for overcurrent\n");
}
}
}
device_init_wakeup(&pdev->dev, 1);
return usb_hcd_at91_probe(&ohci_at91_hc_driver, pdev);
}
static int ohci_hcd_at91_drv_remove(struct platform_device *pdev)
{
struct at91_usbh_data *pdata = dev_get_platdata(&pdev->dev);
int i;
if (pdata) {
at91_for_each_port(i) {
if (!gpio_is_valid(pdata->vbus_pin[i]))
continue;
ohci_at91_usb_set_power(pdata, i, 0);
gpio_free(pdata->vbus_pin[i]);
}
at91_for_each_port(i) {
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
ohci->hc_control = ohci_readl(ohci, &ohci->regs->control);
ohci->hc_control &= OHCI_CTRL_RWC;
ohci_writel(ohci, ohci->hc_control, &ohci->regs->control);
ohci->rh_state = OHCI_RH_HALTED;
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
ohci_resume(hcd, false);
return 0;
}
static int __init ohci_at91_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_at91_hc_driver, NULL);
orig_ohci_hub_control = ohci_at91_hc_driver.hub_control;
orig_ohci_hub_status_data = ohci_at91_hc_driver.hub_status_data;
ohci_at91_hc_driver.hub_status_data = ohci_at91_hub_status_data;
ohci_at91_hc_driver.hub_control = ohci_at91_hub_control;
return platform_driver_register(&ohci_hcd_at91_driver);
}
static void __exit ohci_at91_cleanup(void)
{
platform_driver_unregister(&ohci_hcd_at91_driver);
}
