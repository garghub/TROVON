static void palmas_usb_wakeup(struct palmas *palmas, int enable)
{
if (enable)
palmas_write(palmas, PALMAS_USB_OTG_BASE, PALMAS_USB_WAKEUP,
PALMAS_USB_WAKEUP_ID_WK_UP_COMP);
else
palmas_write(palmas, PALMAS_USB_OTG_BASE, PALMAS_USB_WAKEUP, 0);
}
static irqreturn_t palmas_vbus_irq_handler(int irq, void *_palmas_usb)
{
struct palmas_usb *palmas_usb = _palmas_usb;
unsigned int vbus_line_state;
palmas_read(palmas_usb->palmas, PALMAS_INTERRUPT_BASE,
PALMAS_INT3_LINE_STATE, &vbus_line_state);
if (vbus_line_state & PALMAS_INT3_LINE_STATE_VBUS) {
if (palmas_usb->linkstat != PALMAS_USB_STATE_VBUS) {
palmas_usb->linkstat = PALMAS_USB_STATE_VBUS;
extcon_set_cable_state(palmas_usb->edev, "USB", true);
dev_info(palmas_usb->dev, "USB cable is attached\n");
} else {
dev_dbg(palmas_usb->dev,
"Spurious connect event detected\n");
}
} else if (!(vbus_line_state & PALMAS_INT3_LINE_STATE_VBUS)) {
if (palmas_usb->linkstat == PALMAS_USB_STATE_VBUS) {
palmas_usb->linkstat = PALMAS_USB_STATE_DISCONNECT;
extcon_set_cable_state(palmas_usb->edev, "USB", false);
dev_info(palmas_usb->dev, "USB cable is detached\n");
} else {
dev_dbg(palmas_usb->dev,
"Spurious disconnect event detected\n");
}
}
return IRQ_HANDLED;
}
static irqreturn_t palmas_id_irq_handler(int irq, void *_palmas_usb)
{
unsigned int set, id_src;
struct palmas_usb *palmas_usb = _palmas_usb;
palmas_read(palmas_usb->palmas, PALMAS_USB_OTG_BASE,
PALMAS_USB_ID_INT_LATCH_SET, &set);
palmas_read(palmas_usb->palmas, PALMAS_USB_OTG_BASE,
PALMAS_USB_ID_INT_SRC, &id_src);
if ((set & PALMAS_USB_ID_INT_SRC_ID_GND) &&
(id_src & PALMAS_USB_ID_INT_SRC_ID_GND)) {
palmas_write(palmas_usb->palmas, PALMAS_USB_OTG_BASE,
PALMAS_USB_ID_INT_LATCH_CLR,
PALMAS_USB_ID_INT_EN_HI_CLR_ID_GND);
palmas_usb->linkstat = PALMAS_USB_STATE_ID;
extcon_set_cable_state(palmas_usb->edev, "USB-HOST", true);
dev_info(palmas_usb->dev, "USB-HOST cable is attached\n");
} else if ((set & PALMAS_USB_ID_INT_SRC_ID_FLOAT) &&
(id_src & PALMAS_USB_ID_INT_SRC_ID_FLOAT)) {
palmas_write(palmas_usb->palmas, PALMAS_USB_OTG_BASE,
PALMAS_USB_ID_INT_LATCH_CLR,
PALMAS_USB_ID_INT_EN_HI_CLR_ID_FLOAT);
palmas_usb->linkstat = PALMAS_USB_STATE_DISCONNECT;
extcon_set_cable_state(palmas_usb->edev, "USB-HOST", false);
dev_info(palmas_usb->dev, "USB-HOST cable is detached\n");
} else if ((palmas_usb->linkstat == PALMAS_USB_STATE_ID) &&
(!(set & PALMAS_USB_ID_INT_SRC_ID_GND))) {
palmas_usb->linkstat = PALMAS_USB_STATE_DISCONNECT;
extcon_set_cable_state(palmas_usb->edev, "USB-HOST", false);
dev_info(palmas_usb->dev, "USB-HOST cable is detached\n");
} else if ((palmas_usb->linkstat == PALMAS_USB_STATE_DISCONNECT) &&
(id_src & PALMAS_USB_ID_INT_SRC_ID_GND)) {
palmas_usb->linkstat = PALMAS_USB_STATE_ID;
extcon_set_cable_state(palmas_usb->edev, "USB-HOST", true);
dev_info(palmas_usb->dev, " USB-HOST cable is attached\n");
}
return IRQ_HANDLED;
}
static void palmas_enable_irq(struct palmas_usb *palmas_usb)
{
palmas_write(palmas_usb->palmas, PALMAS_USB_OTG_BASE,
PALMAS_USB_VBUS_CTRL_SET,
PALMAS_USB_VBUS_CTRL_SET_VBUS_ACT_COMP);
palmas_write(palmas_usb->palmas, PALMAS_USB_OTG_BASE,
PALMAS_USB_ID_CTRL_SET, PALMAS_USB_ID_CTRL_SET_ID_ACT_COMP);
palmas_write(palmas_usb->palmas, PALMAS_USB_OTG_BASE,
PALMAS_USB_ID_INT_EN_HI_SET,
PALMAS_USB_ID_INT_EN_HI_SET_ID_GND |
PALMAS_USB_ID_INT_EN_HI_SET_ID_FLOAT);
if (palmas_usb->enable_vbus_detection)
palmas_vbus_irq_handler(palmas_usb->vbus_irq, palmas_usb);
if (palmas_usb->enable_id_detection) {
msleep(30);
palmas_id_irq_handler(palmas_usb->id_irq, palmas_usb);
}
}
static int palmas_usb_probe(struct platform_device *pdev)
{
struct palmas *palmas = dev_get_drvdata(pdev->dev.parent);
struct palmas_usb_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct device_node *node = pdev->dev.of_node;
struct palmas_usb *palmas_usb;
int status;
palmas_usb = devm_kzalloc(&pdev->dev, sizeof(*palmas_usb), GFP_KERNEL);
if (!palmas_usb)
return -ENOMEM;
if (node && !pdata) {
palmas_usb->wakeup = of_property_read_bool(node, "ti,wakeup");
palmas_usb->enable_id_detection = of_property_read_bool(node,
"ti,enable-id-detection");
palmas_usb->enable_vbus_detection = of_property_read_bool(node,
"ti,enable-vbus-detection");
} else {
palmas_usb->wakeup = true;
palmas_usb->enable_id_detection = true;
palmas_usb->enable_vbus_detection = true;
if (pdata)
palmas_usb->wakeup = pdata->wakeup;
}
palmas->usb = palmas_usb;
palmas_usb->palmas = palmas;
palmas_usb->dev = &pdev->dev;
palmas_usb->id_otg_irq = regmap_irq_get_virq(palmas->irq_data,
PALMAS_ID_OTG_IRQ);
palmas_usb->id_irq = regmap_irq_get_virq(palmas->irq_data,
PALMAS_ID_IRQ);
palmas_usb->vbus_otg_irq = regmap_irq_get_virq(palmas->irq_data,
PALMAS_VBUS_OTG_IRQ);
palmas_usb->vbus_irq = regmap_irq_get_virq(palmas->irq_data,
PALMAS_VBUS_IRQ);
palmas_usb_wakeup(palmas, palmas_usb->wakeup);
platform_set_drvdata(pdev, palmas_usb);
palmas_usb->edev = devm_extcon_dev_allocate(&pdev->dev,
palmas_extcon_cable);
if (IS_ERR(palmas_usb->edev)) {
dev_err(&pdev->dev, "failed to allocate extcon device\n");
return -ENOMEM;
}
palmas_usb->edev->name = kstrdup(node->name, GFP_KERNEL);
palmas_usb->edev->dev.parent = palmas_usb->dev;
palmas_usb->edev->mutually_exclusive = mutually_exclusive;
status = devm_extcon_dev_register(&pdev->dev, palmas_usb->edev);
if (status) {
dev_err(&pdev->dev, "failed to register extcon device\n");
kfree(palmas_usb->edev->name);
return status;
}
if (palmas_usb->enable_id_detection) {
status = devm_request_threaded_irq(palmas_usb->dev,
palmas_usb->id_irq,
NULL, palmas_id_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING |
IRQF_ONESHOT | IRQF_EARLY_RESUME,
"palmas_usb_id", palmas_usb);
if (status < 0) {
dev_err(&pdev->dev, "can't get IRQ %d, err %d\n",
palmas_usb->id_irq, status);
kfree(palmas_usb->edev->name);
return status;
}
}
if (palmas_usb->enable_vbus_detection) {
status = devm_request_threaded_irq(palmas_usb->dev,
palmas_usb->vbus_irq, NULL,
palmas_vbus_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_TRIGGER_RISING |
IRQF_ONESHOT | IRQF_EARLY_RESUME,
"palmas_usb_vbus", palmas_usb);
if (status < 0) {
dev_err(&pdev->dev, "can't get IRQ %d, err %d\n",
palmas_usb->vbus_irq, status);
kfree(palmas_usb->edev->name);
return status;
}
}
palmas_enable_irq(palmas_usb);
device_set_wakeup_capable(&pdev->dev, true);
return 0;
}
static int palmas_usb_remove(struct platform_device *pdev)
{
struct palmas_usb *palmas_usb = platform_get_drvdata(pdev);
kfree(palmas_usb->edev->name);
return 0;
}
static int palmas_usb_suspend(struct device *dev)
{
struct palmas_usb *palmas_usb = dev_get_drvdata(dev);
if (device_may_wakeup(dev)) {
if (palmas_usb->enable_vbus_detection)
enable_irq_wake(palmas_usb->vbus_irq);
if (palmas_usb->enable_id_detection)
enable_irq_wake(palmas_usb->id_irq);
}
return 0;
}
static int palmas_usb_resume(struct device *dev)
{
struct palmas_usb *palmas_usb = dev_get_drvdata(dev);
if (device_may_wakeup(dev)) {
if (palmas_usb->enable_vbus_detection)
disable_irq_wake(palmas_usb->vbus_irq);
if (palmas_usb->enable_id_detection)
disable_irq_wake(palmas_usb->id_irq);
}
return 0;
}
