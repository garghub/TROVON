static ssize_t vbus_state_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct tahvo_usb *tu = dev_get_drvdata(device);
return sprintf(buf, "%s\n", tu->vbus_state ? "on" : "off");
}
static void check_vbus_state(struct tahvo_usb *tu)
{
struct retu_dev *rdev = dev_get_drvdata(tu->pt_dev->dev.parent);
int reg, prev_state;
reg = retu_read(rdev, TAHVO_REG_IDSR);
if (reg & TAHVO_STAT_VBUS) {
switch (tu->phy.state) {
case OTG_STATE_B_IDLE:
if (tu->phy.otg->gadget)
usb_gadget_vbus_connect(tu->phy.otg->gadget);
tu->phy.state = OTG_STATE_B_PERIPHERAL;
break;
case OTG_STATE_A_IDLE:
tu->phy.state = OTG_STATE_A_HOST;
break;
default:
break;
}
dev_info(&tu->pt_dev->dev, "USB cable connected\n");
} else {
switch (tu->phy.state) {
case OTG_STATE_B_PERIPHERAL:
if (tu->phy.otg->gadget)
usb_gadget_vbus_disconnect(tu->phy.otg->gadget);
tu->phy.state = OTG_STATE_B_IDLE;
break;
case OTG_STATE_A_HOST:
tu->phy.state = OTG_STATE_A_IDLE;
break;
default:
break;
}
dev_info(&tu->pt_dev->dev, "USB cable disconnected\n");
}
prev_state = tu->vbus_state;
tu->vbus_state = reg & TAHVO_STAT_VBUS;
if (prev_state != tu->vbus_state) {
extcon_set_cable_state(&tu->extcon, "USB", tu->vbus_state);
sysfs_notify(&tu->pt_dev->dev.kobj, NULL, "vbus_state");
}
}
static void tahvo_usb_become_host(struct tahvo_usb *tu)
{
struct retu_dev *rdev = dev_get_drvdata(tu->pt_dev->dev.parent);
extcon_set_cable_state(&tu->extcon, "USB-HOST", true);
retu_write(rdev, TAHVO_REG_USBR, USBR_REGOUT | USBR_NSUSPEND |
USBR_MASTER_SW2 | USBR_MASTER_SW1);
tu->phy.state = OTG_STATE_A_IDLE;
check_vbus_state(tu);
}
static void tahvo_usb_stop_host(struct tahvo_usb *tu)
{
tu->phy.state = OTG_STATE_A_IDLE;
}
static void tahvo_usb_become_peripheral(struct tahvo_usb *tu)
{
struct retu_dev *rdev = dev_get_drvdata(tu->pt_dev->dev.parent);
extcon_set_cable_state(&tu->extcon, "USB-HOST", false);
retu_write(rdev, TAHVO_REG_USBR, USBR_SLAVE_CONTROL | USBR_REGOUT |
USBR_NSUSPEND | USBR_SLAVE_SW);
tu->phy.state = OTG_STATE_B_IDLE;
check_vbus_state(tu);
}
static void tahvo_usb_stop_peripheral(struct tahvo_usb *tu)
{
if (tu->phy.otg->gadget)
usb_gadget_vbus_disconnect(tu->phy.otg->gadget);
tu->phy.state = OTG_STATE_B_IDLE;
}
static void tahvo_usb_power_off(struct tahvo_usb *tu)
{
struct retu_dev *rdev = dev_get_drvdata(tu->pt_dev->dev.parent);
if (tu->phy.otg->gadget)
usb_gadget_vbus_disconnect(tu->phy.otg->gadget);
retu_write(rdev, TAHVO_REG_USBR, 0);
tu->phy.state = OTG_STATE_UNDEFINED;
}
static int tahvo_usb_set_suspend(struct usb_phy *dev, int suspend)
{
struct tahvo_usb *tu = container_of(dev, struct tahvo_usb, phy);
struct retu_dev *rdev = dev_get_drvdata(tu->pt_dev->dev.parent);
u16 w;
dev_dbg(&tu->pt_dev->dev, "%s\n", __func__);
w = retu_read(rdev, TAHVO_REG_USBR);
if (suspend)
w &= ~USBR_NSUSPEND;
else
w |= USBR_NSUSPEND;
retu_write(rdev, TAHVO_REG_USBR, w);
return 0;
}
static int tahvo_usb_set_host(struct usb_otg *otg, struct usb_bus *host)
{
struct tahvo_usb *tu = container_of(otg->phy, struct tahvo_usb, phy);
dev_dbg(&tu->pt_dev->dev, "%s %p\n", __func__, host);
mutex_lock(&tu->serialize);
if (host == NULL) {
if (tu->tahvo_mode == TAHVO_MODE_HOST)
tahvo_usb_power_off(tu);
otg->host = NULL;
mutex_unlock(&tu->serialize);
return 0;
}
if (tu->tahvo_mode == TAHVO_MODE_HOST) {
otg->host = NULL;
tahvo_usb_become_host(tu);
}
otg->host = host;
mutex_unlock(&tu->serialize);
return 0;
}
static int tahvo_usb_set_peripheral(struct usb_otg *otg,
struct usb_gadget *gadget)
{
struct tahvo_usb *tu = container_of(otg->phy, struct tahvo_usb, phy);
dev_dbg(&tu->pt_dev->dev, "%s %p\n", __func__, gadget);
mutex_lock(&tu->serialize);
if (!gadget) {
if (tu->tahvo_mode == TAHVO_MODE_PERIPHERAL)
tahvo_usb_power_off(tu);
tu->phy.otg->gadget = NULL;
mutex_unlock(&tu->serialize);
return 0;
}
tu->phy.otg->gadget = gadget;
if (tu->tahvo_mode == TAHVO_MODE_PERIPHERAL)
tahvo_usb_become_peripheral(tu);
mutex_unlock(&tu->serialize);
return 0;
}
static irqreturn_t tahvo_usb_vbus_interrupt(int irq, void *_tu)
{
struct tahvo_usb *tu = _tu;
mutex_lock(&tu->serialize);
check_vbus_state(tu);
mutex_unlock(&tu->serialize);
return IRQ_HANDLED;
}
static ssize_t otg_mode_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct tahvo_usb *tu = dev_get_drvdata(device);
switch (tu->tahvo_mode) {
case TAHVO_MODE_HOST:
return sprintf(buf, "host\n");
case TAHVO_MODE_PERIPHERAL:
return sprintf(buf, "peripheral\n");
}
return -EINVAL;
}
static ssize_t otg_mode_store(struct device *device,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct tahvo_usb *tu = dev_get_drvdata(device);
int r;
mutex_lock(&tu->serialize);
if (count >= 4 && strncmp(buf, "host", 4) == 0) {
if (tu->tahvo_mode == TAHVO_MODE_PERIPHERAL)
tahvo_usb_stop_peripheral(tu);
tu->tahvo_mode = TAHVO_MODE_HOST;
if (tu->phy.otg->host) {
dev_info(device, "HOST mode: host controller present\n");
tahvo_usb_become_host(tu);
} else {
dev_info(device, "HOST mode: no host controller, powering off\n");
tahvo_usb_power_off(tu);
}
r = strlen(buf);
} else if (count >= 10 && strncmp(buf, "peripheral", 10) == 0) {
if (tu->tahvo_mode == TAHVO_MODE_HOST)
tahvo_usb_stop_host(tu);
tu->tahvo_mode = TAHVO_MODE_PERIPHERAL;
if (tu->phy.otg->gadget) {
dev_info(device, "PERIPHERAL mode: gadget driver present\n");
tahvo_usb_become_peripheral(tu);
} else {
dev_info(device, "PERIPHERAL mode: no gadget driver, powering off\n");
tahvo_usb_power_off(tu);
}
r = strlen(buf);
} else {
r = -EINVAL;
}
mutex_unlock(&tu->serialize);
return r;
}
static int tahvo_usb_probe(struct platform_device *pdev)
{
struct retu_dev *rdev = dev_get_drvdata(pdev->dev.parent);
struct tahvo_usb *tu;
int ret;
tu = devm_kzalloc(&pdev->dev, sizeof(*tu), GFP_KERNEL);
if (!tu)
return -ENOMEM;
tu->phy.otg = devm_kzalloc(&pdev->dev, sizeof(*tu->phy.otg),
GFP_KERNEL);
if (!tu->phy.otg)
return -ENOMEM;
tu->pt_dev = pdev;
#ifdef CONFIG_TAHVO_USB_HOST_BY_DEFAULT
tu->tahvo_mode = TAHVO_MODE_HOST;
#else
tu->tahvo_mode = TAHVO_MODE_PERIPHERAL;
#endif
mutex_init(&tu->serialize);
tu->ick = devm_clk_get(&pdev->dev, "usb_l4_ick");
if (!IS_ERR(tu->ick))
clk_enable(tu->ick);
tu->vbus_state = retu_read(rdev, TAHVO_REG_IDSR) & TAHVO_STAT_VBUS;
tu->extcon.name = DRIVER_NAME;
tu->extcon.supported_cable = tahvo_cable;
tu->extcon.dev.parent = &pdev->dev;
ret = extcon_dev_register(&tu->extcon);
if (ret) {
dev_err(&pdev->dev, "could not register extcon device: %d\n",
ret);
goto err_disable_clk;
}
extcon_set_cable_state(&tu->extcon, "USB-HOST",
tu->tahvo_mode == TAHVO_MODE_HOST);
extcon_set_cable_state(&tu->extcon, "USB", tu->vbus_state);
tahvo_usb_power_off(tu);
tu->phy.dev = &pdev->dev;
tu->phy.state = OTG_STATE_UNDEFINED;
tu->phy.label = DRIVER_NAME;
tu->phy.set_suspend = tahvo_usb_set_suspend;
tu->phy.otg->phy = &tu->phy;
tu->phy.otg->set_host = tahvo_usb_set_host;
tu->phy.otg->set_peripheral = tahvo_usb_set_peripheral;
ret = usb_add_phy(&tu->phy, USB_PHY_TYPE_USB2);
if (ret < 0) {
dev_err(&pdev->dev, "cannot register USB transceiver: %d\n",
ret);
goto err_extcon_unreg;
}
dev_set_drvdata(&pdev->dev, tu);
tu->irq = platform_get_irq(pdev, 0);
ret = request_threaded_irq(tu->irq, NULL, tahvo_usb_vbus_interrupt, 0,
"tahvo-vbus", tu);
if (ret) {
dev_err(&pdev->dev, "could not register tahvo-vbus irq: %d\n",
ret);
goto err_remove_phy;
}
ret = sysfs_create_group(&pdev->dev.kobj, &tahvo_attr_group);
if (ret) {
dev_err(&pdev->dev, "cannot create sysfs group: %d\n", ret);
goto err_free_irq;
}
return 0;
err_free_irq:
free_irq(tu->irq, tu);
err_remove_phy:
usb_remove_phy(&tu->phy);
err_extcon_unreg:
extcon_dev_unregister(&tu->extcon);
err_disable_clk:
if (!IS_ERR(tu->ick))
clk_disable(tu->ick);
return ret;
}
static int tahvo_usb_remove(struct platform_device *pdev)
{
struct tahvo_usb *tu = platform_get_drvdata(pdev);
sysfs_remove_group(&pdev->dev.kobj, &tahvo_attr_group);
free_irq(tu->irq, tu);
usb_remove_phy(&tu->phy);
extcon_dev_unregister(&tu->extcon);
if (!IS_ERR(tu->ick))
clk_disable(tu->ick);
return 0;
}
