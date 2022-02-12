static inline int twl6030_writeb(struct twl6030_usb *twl, u8 module,
u8 data, u8 address)
{
int ret = 0;
ret = twl_i2c_write_u8(module, data, address);
if (ret < 0)
dev_err(twl->dev,
"Write[0x%x] Error %d\n", address, ret);
return ret;
}
static inline u8 twl6030_readb(struct twl6030_usb *twl, u8 module, u8 address)
{
u8 data, ret = 0;
ret = twl_i2c_read_u8(module, &data, address);
if (ret >= 0)
ret = data;
else
dev_err(twl->dev,
"readb[0x%x,0x%x] Error %d\n",
module, address, ret);
return ret;
}
static int twl6030_set_phy_clk(struct otg_transceiver *x, int on)
{
struct twl6030_usb *twl;
struct device *dev;
struct twl4030_usb_data *pdata;
twl = xceiv_to_twl(x);
dev = twl->dev;
pdata = dev->platform_data;
pdata->phy_set_clock(twl->dev, on);
return 0;
}
static int twl6030_phy_init(struct otg_transceiver *x)
{
struct twl6030_usb *twl;
struct device *dev;
struct twl4030_usb_data *pdata;
twl = xceiv_to_twl(x);
dev = twl->dev;
pdata = dev->platform_data;
if (twl->linkstat == USB_EVENT_ID)
pdata->phy_power(twl->dev, 1, 1);
else
pdata->phy_power(twl->dev, 0, 1);
return 0;
}
static void twl6030_phy_shutdown(struct otg_transceiver *x)
{
struct twl6030_usb *twl;
struct device *dev;
struct twl4030_usb_data *pdata;
twl = xceiv_to_twl(x);
dev = twl->dev;
pdata = dev->platform_data;
pdata->phy_power(twl->dev, 0, 0);
}
static int twl6030_phy_suspend(struct otg_transceiver *x, int suspend)
{
struct twl6030_usb *twl = xceiv_to_twl(x);
struct device *dev = twl->dev;
struct twl4030_usb_data *pdata = dev->platform_data;
pdata->phy_suspend(dev, suspend);
return 0;
}
static int twl6030_start_srp(struct otg_transceiver *x)
{
struct twl6030_usb *twl = xceiv_to_twl(x);
twl6030_writeb(twl, TWL_MODULE_USB, 0x24, USB_VBUS_CTRL_SET);
twl6030_writeb(twl, TWL_MODULE_USB, 0x84, USB_VBUS_CTRL_SET);
mdelay(100);
twl6030_writeb(twl, TWL_MODULE_USB, 0xa0, USB_VBUS_CTRL_CLR);
return 0;
}
static int twl6030_usb_ldo_init(struct twl6030_usb *twl)
{
char *regulator_name;
if (twl->features & TWL6025_SUBCLASS)
regulator_name = "ldousb";
else
regulator_name = "vusb";
twl6030_writeb(twl, TWL6030_MODULE_ID0 , 0x1, TWL6030_BACKUP_REG);
twl6030_writeb(twl, TWL6030_MODULE_ID0 , 0x1, TWL6030_CFG_LDO_PD2);
twl6030_writeb(twl, TWL6030_MODULE_ID0 , 0x10, TWL6030_MISC2);
twl->usb3v3 = regulator_get(twl->dev, regulator_name);
if (IS_ERR(twl->usb3v3))
return -ENODEV;
twl6030_writeb(twl, TWL_MODULE_USB, 0x4, USB_VBUS_CTRL_SET);
twl6030_writeb(twl, TWL_MODULE_USB, 0x14, USB_ID_CTRL_SET);
return 0;
}
static ssize_t twl6030_usb_vbus_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct twl6030_usb *twl = dev_get_drvdata(dev);
unsigned long flags;
int ret = -EINVAL;
spin_lock_irqsave(&twl->lock, flags);
switch (twl->linkstat) {
case USB_EVENT_VBUS:
ret = snprintf(buf, PAGE_SIZE, "vbus\n");
break;
case USB_EVENT_ID:
ret = snprintf(buf, PAGE_SIZE, "id\n");
break;
case USB_EVENT_NONE:
ret = snprintf(buf, PAGE_SIZE, "none\n");
break;
default:
ret = snprintf(buf, PAGE_SIZE, "UNKNOWN\n");
}
spin_unlock_irqrestore(&twl->lock, flags);
return ret;
}
static irqreturn_t twl6030_usb_irq(int irq, void *_twl)
{
struct twl6030_usb *twl = _twl;
int status;
u8 vbus_state, hw_state;
hw_state = twl6030_readb(twl, TWL6030_MODULE_ID0, STS_HW_CONDITIONS);
vbus_state = twl6030_readb(twl, TWL_MODULE_MAIN_CHARGE,
CONTROLLER_STAT1);
if (!(hw_state & STS_USB_ID)) {
if (vbus_state & VBUS_DET) {
regulator_enable(twl->usb3v3);
twl->asleep = 1;
status = USB_EVENT_VBUS;
twl->otg.default_a = false;
twl->otg.state = OTG_STATE_B_IDLE;
twl->linkstat = status;
twl->otg.last_event = status;
atomic_notifier_call_chain(&twl->otg.notifier,
status, twl->otg.gadget);
} else {
status = USB_EVENT_NONE;
twl->linkstat = status;
twl->otg.last_event = status;
atomic_notifier_call_chain(&twl->otg.notifier,
status, twl->otg.gadget);
if (twl->asleep) {
regulator_disable(twl->usb3v3);
twl->asleep = 0;
}
}
}
sysfs_notify(&twl->dev->kobj, NULL, "vbus");
return IRQ_HANDLED;
}
static irqreturn_t twl6030_usbotg_irq(int irq, void *_twl)
{
struct twl6030_usb *twl = _twl;
int status = USB_EVENT_NONE;
u8 hw_state;
hw_state = twl6030_readb(twl, TWL6030_MODULE_ID0, STS_HW_CONDITIONS);
if (hw_state & STS_USB_ID) {
regulator_enable(twl->usb3v3);
twl->asleep = 1;
twl6030_writeb(twl, TWL_MODULE_USB, USB_ID_INT_EN_HI_CLR, 0x1);
twl6030_writeb(twl, TWL_MODULE_USB, USB_ID_INT_EN_HI_SET,
0x10);
status = USB_EVENT_ID;
twl->otg.default_a = true;
twl->otg.state = OTG_STATE_A_IDLE;
twl->linkstat = status;
twl->otg.last_event = status;
atomic_notifier_call_chain(&twl->otg.notifier, status,
twl->otg.gadget);
} else {
twl6030_writeb(twl, TWL_MODULE_USB, USB_ID_INT_EN_HI_CLR,
0x10);
twl6030_writeb(twl, TWL_MODULE_USB, USB_ID_INT_EN_HI_SET,
0x1);
}
twl6030_writeb(twl, TWL_MODULE_USB, USB_ID_INT_LATCH_CLR, status);
return IRQ_HANDLED;
}
static int twl6030_set_peripheral(struct otg_transceiver *x,
struct usb_gadget *gadget)
{
struct twl6030_usb *twl;
if (!x)
return -ENODEV;
twl = xceiv_to_twl(x);
twl->otg.gadget = gadget;
if (!gadget)
twl->otg.state = OTG_STATE_UNDEFINED;
return 0;
}
static int twl6030_enable_irq(struct otg_transceiver *x)
{
struct twl6030_usb *twl = xceiv_to_twl(x);
twl6030_writeb(twl, TWL_MODULE_USB, USB_ID_INT_EN_HI_SET, 0x1);
twl6030_interrupt_unmask(0x05, REG_INT_MSK_LINE_C);
twl6030_interrupt_unmask(0x05, REG_INT_MSK_STS_C);
twl6030_interrupt_unmask(TWL6030_CHARGER_CTRL_INT_MASK,
REG_INT_MSK_LINE_C);
twl6030_interrupt_unmask(TWL6030_CHARGER_CTRL_INT_MASK,
REG_INT_MSK_STS_C);
twl6030_usb_irq(twl->irq2, twl);
twl6030_usbotg_irq(twl->irq1, twl);
return 0;
}
static int twl6030_set_vbus(struct otg_transceiver *x, bool enabled)
{
struct twl6030_usb *twl = xceiv_to_twl(x);
if (enabled)
twl6030_writeb(twl, TWL_MODULE_MAIN_CHARGE , 0x40,
CHARGERUSB_CTRL1);
else
twl6030_writeb(twl, TWL_MODULE_MAIN_CHARGE , 0x00,
CHARGERUSB_CTRL1);
return 0;
}
static int twl6030_set_host(struct otg_transceiver *x, struct usb_bus *host)
{
struct twl6030_usb *twl;
if (!x)
return -ENODEV;
twl = xceiv_to_twl(x);
twl->otg.host = host;
if (!host)
twl->otg.state = OTG_STATE_UNDEFINED;
return 0;
}
static int __devinit twl6030_usb_probe(struct platform_device *pdev)
{
struct twl6030_usb *twl;
int status, err;
struct twl4030_usb_data *pdata;
struct device *dev = &pdev->dev;
pdata = dev->platform_data;
twl = kzalloc(sizeof *twl, GFP_KERNEL);
if (!twl)
return -ENOMEM;
twl->dev = &pdev->dev;
twl->irq1 = platform_get_irq(pdev, 0);
twl->irq2 = platform_get_irq(pdev, 1);
twl->features = pdata->features;
twl->otg.dev = twl->dev;
twl->otg.label = "twl6030";
twl->otg.set_host = twl6030_set_host;
twl->otg.set_peripheral = twl6030_set_peripheral;
twl->otg.set_vbus = twl6030_set_vbus;
twl->otg.init = twl6030_phy_init;
twl->otg.shutdown = twl6030_phy_shutdown;
twl->otg.set_suspend = twl6030_phy_suspend;
twl->otg.start_srp = twl6030_start_srp;
spin_lock_init(&twl->lock);
err = twl6030_usb_ldo_init(twl);
if (err) {
dev_err(&pdev->dev, "ldo init failed\n");
kfree(twl);
return err;
}
otg_set_transceiver(&twl->otg);
platform_set_drvdata(pdev, twl);
if (device_create_file(&pdev->dev, &dev_attr_vbus))
dev_warn(&pdev->dev, "could not create sysfs file\n");
ATOMIC_INIT_NOTIFIER_HEAD(&twl->otg.notifier);
twl->irq_enabled = true;
status = request_threaded_irq(twl->irq1, NULL, twl6030_usbotg_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"twl6030_usb", twl);
if (status < 0) {
dev_err(&pdev->dev, "can't get IRQ %d, err %d\n",
twl->irq1, status);
device_remove_file(twl->dev, &dev_attr_vbus);
kfree(twl);
return status;
}
status = request_threaded_irq(twl->irq2, NULL, twl6030_usb_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING,
"twl6030_usb", twl);
if (status < 0) {
dev_err(&pdev->dev, "can't get IRQ %d, err %d\n",
twl->irq2, status);
free_irq(twl->irq1, twl);
device_remove_file(twl->dev, &dev_attr_vbus);
kfree(twl);
return status;
}
twl->asleep = 0;
pdata->phy_init(dev);
twl6030_phy_suspend(&twl->otg, 0);
twl6030_enable_irq(&twl->otg);
dev_info(&pdev->dev, "Initialized TWL6030 USB module\n");
return 0;
}
static int __exit twl6030_usb_remove(struct platform_device *pdev)
{
struct twl6030_usb *twl = platform_get_drvdata(pdev);
struct twl4030_usb_data *pdata;
struct device *dev = &pdev->dev;
pdata = dev->platform_data;
twl6030_interrupt_mask(TWL6030_USBOTG_INT_MASK,
REG_INT_MSK_LINE_C);
twl6030_interrupt_mask(TWL6030_USBOTG_INT_MASK,
REG_INT_MSK_STS_C);
free_irq(twl->irq1, twl);
free_irq(twl->irq2, twl);
regulator_put(twl->usb3v3);
pdata->phy_exit(twl->dev);
device_remove_file(twl->dev, &dev_attr_vbus);
kfree(twl);
return 0;
}
static int __init twl6030_usb_init(void)
{
return platform_driver_register(&twl6030_usb_driver);
}
static void __exit twl6030_usb_exit(void)
{
platform_driver_unregister(&twl6030_usb_driver);
}
