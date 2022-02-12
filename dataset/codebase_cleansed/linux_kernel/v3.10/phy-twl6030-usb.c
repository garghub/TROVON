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
static int twl6030_start_srp(struct phy_companion *comparator)
{
struct twl6030_usb *twl = comparator_to_twl(comparator);
twl6030_writeb(twl, TWL_MODULE_USB, 0x24, USB_VBUS_CTRL_SET);
twl6030_writeb(twl, TWL_MODULE_USB, 0x84, USB_VBUS_CTRL_SET);
mdelay(100);
twl6030_writeb(twl, TWL_MODULE_USB, 0xa0, USB_VBUS_CTRL_CLR);
return 0;
}
static int twl6030_usb_ldo_init(struct twl6030_usb *twl)
{
twl6030_writeb(twl, TWL6030_MODULE_ID0 , 0x1, TWL6030_BACKUP_REG);
twl6030_writeb(twl, TWL6030_MODULE_ID0 , 0x1, TWL6030_CFG_LDO_PD2);
twl6030_writeb(twl, TWL6030_MODULE_ID0 , 0x10, TWL6030_MISC2);
twl->usb3v3 = regulator_get(twl->dev, twl->regulator);
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
case OMAP_MUSB_VBUS_VALID:
ret = snprintf(buf, PAGE_SIZE, "vbus\n");
break;
case OMAP_MUSB_ID_GROUND:
ret = snprintf(buf, PAGE_SIZE, "id\n");
break;
case OMAP_MUSB_VBUS_OFF:
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
enum omap_musb_vbus_id_status status = OMAP_MUSB_UNKNOWN;
u8 vbus_state, hw_state;
int ret;
hw_state = twl6030_readb(twl, TWL6030_MODULE_ID0, STS_HW_CONDITIONS);
vbus_state = twl6030_readb(twl, TWL_MODULE_MAIN_CHARGE,
CONTROLLER_STAT1);
if (!(hw_state & STS_USB_ID)) {
if (vbus_state & VBUS_DET) {
ret = regulator_enable(twl->usb3v3);
if (ret)
dev_err(twl->dev, "Failed to enable usb3v3\n");
twl->asleep = 1;
status = OMAP_MUSB_VBUS_VALID;
twl->linkstat = status;
omap_musb_mailbox(status);
} else {
if (twl->linkstat != OMAP_MUSB_UNKNOWN) {
status = OMAP_MUSB_VBUS_OFF;
twl->linkstat = status;
omap_musb_mailbox(status);
if (twl->asleep) {
regulator_disable(twl->usb3v3);
twl->asleep = 0;
}
}
}
}
sysfs_notify(&twl->dev->kobj, NULL, "vbus");
return IRQ_HANDLED;
}
static irqreturn_t twl6030_usbotg_irq(int irq, void *_twl)
{
struct twl6030_usb *twl = _twl;
enum omap_musb_vbus_id_status status = OMAP_MUSB_UNKNOWN;
u8 hw_state;
int ret;
hw_state = twl6030_readb(twl, TWL6030_MODULE_ID0, STS_HW_CONDITIONS);
if (hw_state & STS_USB_ID) {
ret = regulator_enable(twl->usb3v3);
if (ret)
dev_err(twl->dev, "Failed to enable usb3v3\n");
twl->asleep = 1;
twl6030_writeb(twl, TWL_MODULE_USB, 0x1, USB_ID_INT_EN_HI_CLR);
twl6030_writeb(twl, TWL_MODULE_USB, 0x10, USB_ID_INT_EN_HI_SET);
status = OMAP_MUSB_ID_GROUND;
twl->linkstat = status;
omap_musb_mailbox(status);
} else {
twl6030_writeb(twl, TWL_MODULE_USB, 0x10, USB_ID_INT_EN_HI_CLR);
twl6030_writeb(twl, TWL_MODULE_USB, 0x1, USB_ID_INT_EN_HI_SET);
}
twl6030_writeb(twl, TWL_MODULE_USB, status, USB_ID_INT_LATCH_CLR);
return IRQ_HANDLED;
}
static int twl6030_enable_irq(struct twl6030_usb *twl)
{
twl6030_writeb(twl, TWL_MODULE_USB, 0x1, USB_ID_INT_EN_HI_SET);
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
static void otg_set_vbus_work(struct work_struct *data)
{
struct twl6030_usb *twl = container_of(data, struct twl6030_usb,
set_vbus_work);
if (twl->vbus_enable)
twl6030_writeb(twl, TWL_MODULE_MAIN_CHARGE , 0x40,
CHARGERUSB_CTRL1);
else
twl6030_writeb(twl, TWL_MODULE_MAIN_CHARGE , 0x00,
CHARGERUSB_CTRL1);
}
static int twl6030_set_vbus(struct phy_companion *comparator, bool enabled)
{
struct twl6030_usb *twl = comparator_to_twl(comparator);
twl->vbus_enable = enabled;
schedule_work(&twl->set_vbus_work);
return 0;
}
static int twl6030_usb_probe(struct platform_device *pdev)
{
u32 ret;
struct twl6030_usb *twl;
int status, err;
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct twl4030_usb_data *pdata = dev->platform_data;
twl = devm_kzalloc(dev, sizeof *twl, GFP_KERNEL);
if (!twl)
return -ENOMEM;
twl->dev = &pdev->dev;
twl->irq1 = platform_get_irq(pdev, 0);
twl->irq2 = platform_get_irq(pdev, 1);
twl->linkstat = OMAP_MUSB_UNKNOWN;
twl->comparator.set_vbus = twl6030_set_vbus;
twl->comparator.start_srp = twl6030_start_srp;
ret = omap_usb2_set_comparator(&twl->comparator);
if (ret == -ENODEV) {
dev_info(&pdev->dev, "phy not ready, deferring probe");
return -EPROBE_DEFER;
}
if (np) {
twl->regulator = "usb";
} else if (pdata) {
if (pdata->features & TWL6025_SUBCLASS)
twl->regulator = "ldousb";
else
twl->regulator = "vusb";
} else {
dev_err(&pdev->dev, "twl6030 initialized without pdata\n");
return -EINVAL;
}
spin_lock_init(&twl->lock);
err = twl6030_usb_ldo_init(twl);
if (err) {
dev_err(&pdev->dev, "ldo init failed\n");
return err;
}
platform_set_drvdata(pdev, twl);
if (device_create_file(&pdev->dev, &dev_attr_vbus))
dev_warn(&pdev->dev, "could not create sysfs file\n");
INIT_WORK(&twl->set_vbus_work, otg_set_vbus_work);
twl->irq_enabled = true;
status = request_threaded_irq(twl->irq1, NULL, twl6030_usbotg_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"twl6030_usb", twl);
if (status < 0) {
dev_err(&pdev->dev, "can't get IRQ %d, err %d\n",
twl->irq1, status);
device_remove_file(twl->dev, &dev_attr_vbus);
return status;
}
status = request_threaded_irq(twl->irq2, NULL, twl6030_usb_irq,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"twl6030_usb", twl);
if (status < 0) {
dev_err(&pdev->dev, "can't get IRQ %d, err %d\n",
twl->irq2, status);
free_irq(twl->irq1, twl);
device_remove_file(twl->dev, &dev_attr_vbus);
return status;
}
twl->asleep = 0;
twl6030_enable_irq(twl);
dev_info(&pdev->dev, "Initialized TWL6030 USB module\n");
return 0;
}
static int twl6030_usb_remove(struct platform_device *pdev)
{
struct twl6030_usb *twl = platform_get_drvdata(pdev);
twl6030_interrupt_mask(TWL6030_USBOTG_INT_MASK,
REG_INT_MSK_LINE_C);
twl6030_interrupt_mask(TWL6030_USBOTG_INT_MASK,
REG_INT_MSK_STS_C);
free_irq(twl->irq1, twl);
free_irq(twl->irq2, twl);
regulator_put(twl->usb3v3);
device_remove_file(twl->dev, &dev_attr_vbus);
cancel_work_sync(&twl->set_vbus_work);
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
