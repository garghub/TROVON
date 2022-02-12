static struct s3c2410_hcd_info *to_s3c2410_info(struct usb_hcd *hcd)
{
return dev_get_platdata(hcd->self.controller);
}
static void s3c2410_start_hc(struct platform_device *dev, struct usb_hcd *hcd)
{
struct s3c2410_hcd_info *info = dev_get_platdata(&dev->dev);
dev_dbg(&dev->dev, "s3c2410_start_hc:\n");
clk_prepare_enable(usb_clk);
mdelay(2);
clk_prepare_enable(clk);
if (info != NULL) {
info->hcd = hcd;
info->report_oc = s3c2410_hcd_oc;
if (info->enable_oc != NULL)
(info->enable_oc)(info, 1);
}
}
static void s3c2410_stop_hc(struct platform_device *dev)
{
struct s3c2410_hcd_info *info = dev_get_platdata(&dev->dev);
dev_dbg(&dev->dev, "s3c2410_stop_hc:\n");
if (info != NULL) {
info->report_oc = NULL;
info->hcd = NULL;
if (info->enable_oc != NULL)
(info->enable_oc)(info, 0);
}
clk_disable_unprepare(clk);
clk_disable_unprepare(usb_clk);
}
static int
ohci_s3c2410_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct s3c2410_hcd_info *info = to_s3c2410_info(hcd);
struct s3c2410_hcd_port *port;
int orig;
int portno;
orig = ohci_hub_status_data(hcd, buf);
if (info == NULL)
return orig;
port = &info->port[0];
for (portno = 0; portno < 2; port++, portno++) {
if (port->oc_changed == 1 &&
port->flags & S3C_HCDFLG_USED) {
dev_dbg(hcd->self.controller,
"oc change on port %d\n", portno);
if (orig < 1)
orig = 1;
buf[0] |= 1<<(portno+1);
}
}
return orig;
}
static void s3c2410_usb_set_power(struct s3c2410_hcd_info *info,
int port, int to)
{
if (info == NULL)
return;
if (info->power_control != NULL) {
info->port[port-1].power = to;
(info->power_control)(port-1, to);
}
}
static int ohci_s3c2410_hub_control(
struct usb_hcd *hcd,
u16 typeReq,
u16 wValue,
u16 wIndex,
char *buf,
u16 wLength)
{
struct s3c2410_hcd_info *info = to_s3c2410_info(hcd);
struct usb_hub_descriptor *desc;
int ret = -EINVAL;
u32 *data = (u32 *)buf;
dev_dbg(hcd->self.controller,
"s3c2410_hub_control(%p,0x%04x,0x%04x,0x%04x,%p,%04x)\n",
hcd, typeReq, wValue, wIndex, buf, wLength);
if (info == NULL) {
ret = ohci_hub_control(hcd, typeReq, wValue,
wIndex, buf, wLength);
goto out;
}
switch (typeReq) {
case SetPortFeature:
if (wValue == USB_PORT_FEAT_POWER) {
dev_dbg(hcd->self.controller, "SetPortFeat: POWER\n");
s3c2410_usb_set_power(info, wIndex, 1);
goto out;
}
break;
case ClearPortFeature:
switch (wValue) {
case USB_PORT_FEAT_C_OVER_CURRENT:
dev_dbg(hcd->self.controller,
"ClearPortFeature: C_OVER_CURRENT\n");
if (valid_port(wIndex)) {
info->port[wIndex-1].oc_changed = 0;
info->port[wIndex-1].oc_status = 0;
}
goto out;
case USB_PORT_FEAT_OVER_CURRENT:
dev_dbg(hcd->self.controller,
"ClearPortFeature: OVER_CURRENT\n");
if (valid_port(wIndex))
info->port[wIndex-1].oc_status = 0;
goto out;
case USB_PORT_FEAT_POWER:
dev_dbg(hcd->self.controller,
"ClearPortFeature: POWER\n");
if (valid_port(wIndex)) {
s3c2410_usb_set_power(info, wIndex, 0);
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
if (info->power_control == NULL)
return ret;
dev_dbg(hcd->self.controller, "wHubCharacteristics 0x%04x\n",
desc->wHubCharacteristics);
desc->wHubCharacteristics &= ~cpu_to_le16(HUB_CHAR_LPSM);
desc->wHubCharacteristics |= cpu_to_le16(
HUB_CHAR_INDV_PORT_LPSM);
if (info->enable_oc) {
desc->wHubCharacteristics &= ~cpu_to_le16(
HUB_CHAR_OCPM);
desc->wHubCharacteristics |= cpu_to_le16(
HUB_CHAR_INDV_PORT_OCPM);
}
dev_dbg(hcd->self.controller, "wHubCharacteristics after 0x%04x\n",
desc->wHubCharacteristics);
return ret;
case GetPortStatus:
dev_dbg(hcd->self.controller, "GetPortStatus(%d)\n", wIndex);
if (valid_port(wIndex)) {
if (info->port[wIndex-1].oc_changed)
*data |= cpu_to_le32(RH_PS_OCIC);
if (info->port[wIndex-1].oc_status)
*data |= cpu_to_le32(RH_PS_POCI);
}
}
out:
return ret;
}
static void s3c2410_hcd_oc(struct s3c2410_hcd_info *info, int port_oc)
{
struct s3c2410_hcd_port *port;
struct usb_hcd *hcd;
unsigned long flags;
int portno;
if (info == NULL)
return;
port = &info->port[0];
hcd = info->hcd;
local_irq_save(flags);
for (portno = 0; portno < 2; port++, portno++) {
if (port_oc & (1<<portno) &&
port->flags & S3C_HCDFLG_USED) {
port->oc_status = 1;
port->oc_changed = 1;
s3c2410_usb_set_power(info, portno+1, 0);
}
}
local_irq_restore(flags);
}
static int
ohci_hcd_s3c2410_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
usb_remove_hcd(hcd);
s3c2410_stop_hc(dev);
usb_put_hcd(hcd);
return 0;
}
static int ohci_hcd_s3c2410_probe(struct platform_device *dev)
{
struct usb_hcd *hcd = NULL;
struct s3c2410_hcd_info *info = dev_get_platdata(&dev->dev);
int retval;
s3c2410_usb_set_power(info, 1, 1);
s3c2410_usb_set_power(info, 2, 1);
hcd = usb_create_hcd(&ohci_s3c2410_hc_driver, &dev->dev, "s3c24xx");
if (hcd == NULL)
return -ENOMEM;
hcd->rsrc_start = dev->resource[0].start;
hcd->rsrc_len = resource_size(&dev->resource[0]);
hcd->regs = devm_ioremap_resource(&dev->dev, &dev->resource[0]);
if (IS_ERR(hcd->regs)) {
retval = PTR_ERR(hcd->regs);
goto err_put;
}
clk = devm_clk_get(&dev->dev, "usb-host");
if (IS_ERR(clk)) {
dev_err(&dev->dev, "cannot get usb-host clock\n");
retval = PTR_ERR(clk);
goto err_put;
}
usb_clk = devm_clk_get(&dev->dev, "usb-bus-host");
if (IS_ERR(usb_clk)) {
dev_err(&dev->dev, "cannot get usb-bus-host clock\n");
retval = PTR_ERR(usb_clk);
goto err_put;
}
s3c2410_start_hc(dev, hcd);
retval = usb_add_hcd(hcd, dev->resource[1].start, 0);
if (retval != 0)
goto err_ioremap;
device_wakeup_enable(hcd->self.controller);
return 0;
err_ioremap:
s3c2410_stop_hc(dev);
err_put:
usb_put_hcd(hcd);
return retval;
}
static int ohci_hcd_s3c2410_drv_suspend(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct platform_device *pdev = to_platform_device(dev);
bool do_wakeup = device_may_wakeup(dev);
int rc = 0;
rc = ohci_suspend(hcd, do_wakeup);
if (rc)
return rc;
s3c2410_stop_hc(pdev);
return rc;
}
static int ohci_hcd_s3c2410_drv_resume(struct device *dev)
{
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct platform_device *pdev = to_platform_device(dev);
s3c2410_start_hc(pdev, hcd);
ohci_resume(hcd, false);
return 0;
}
static int __init ohci_s3c2410_init(void)
{
if (usb_disabled())
return -ENODEV;
pr_info("%s: " DRIVER_DESC "\n", hcd_name);
ohci_init_driver(&ohci_s3c2410_hc_driver, NULL);
ohci_s3c2410_hc_driver.hub_status_data = ohci_s3c2410_hub_status_data;
ohci_s3c2410_hc_driver.hub_control = ohci_s3c2410_hub_control;
return platform_driver_register(&ohci_hcd_s3c2410_driver);
}
static void __exit ohci_s3c2410_cleanup(void)
{
platform_driver_unregister(&ohci_hcd_s3c2410_driver);
}
