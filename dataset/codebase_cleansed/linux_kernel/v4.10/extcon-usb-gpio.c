static void usb_extcon_detect_cable(struct work_struct *work)
{
int id, vbus;
struct usb_extcon_info *info = container_of(to_delayed_work(work),
struct usb_extcon_info,
wq_detcable);
id = info->id_gpiod ?
gpiod_get_value_cansleep(info->id_gpiod) : 1;
vbus = info->vbus_gpiod ?
gpiod_get_value_cansleep(info->vbus_gpiod) : id;
if (id)
extcon_set_state_sync(info->edev, EXTCON_USB_HOST, false);
if (!vbus)
extcon_set_state_sync(info->edev, EXTCON_USB, false);
if (!id) {
extcon_set_state_sync(info->edev, EXTCON_USB_HOST, true);
} else {
if (vbus)
extcon_set_state_sync(info->edev, EXTCON_USB, true);
}
}
static irqreturn_t usb_irq_handler(int irq, void *dev_id)
{
struct usb_extcon_info *info = dev_id;
queue_delayed_work(system_power_efficient_wq, &info->wq_detcable,
info->debounce_jiffies);
return IRQ_HANDLED;
}
static int usb_extcon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct usb_extcon_info *info;
int ret;
if (!np && !ACPI_HANDLE(dev))
return -EINVAL;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = dev;
info->id_gpiod = devm_gpiod_get_optional(&pdev->dev, "id", GPIOD_IN);
info->vbus_gpiod = devm_gpiod_get_optional(&pdev->dev, "vbus",
GPIOD_IN);
if (!info->id_gpiod && !info->vbus_gpiod) {
dev_err(dev, "failed to get gpios\n");
return -ENODEV;
}
if (IS_ERR(info->id_gpiod))
return PTR_ERR(info->id_gpiod);
if (IS_ERR(info->vbus_gpiod))
return PTR_ERR(info->vbus_gpiod);
info->edev = devm_extcon_dev_allocate(dev, usb_extcon_cable);
if (IS_ERR(info->edev)) {
dev_err(dev, "failed to allocate extcon device\n");
return -ENOMEM;
}
ret = devm_extcon_dev_register(dev, info->edev);
if (ret < 0) {
dev_err(dev, "failed to register extcon device\n");
return ret;
}
if (info->id_gpiod)
ret = gpiod_set_debounce(info->id_gpiod,
USB_GPIO_DEBOUNCE_MS * 1000);
if (!ret && info->vbus_gpiod)
ret = gpiod_set_debounce(info->vbus_gpiod,
USB_GPIO_DEBOUNCE_MS * 1000);
if (ret < 0)
info->debounce_jiffies = msecs_to_jiffies(USB_GPIO_DEBOUNCE_MS);
INIT_DELAYED_WORK(&info->wq_detcable, usb_extcon_detect_cable);
if (info->id_gpiod) {
info->id_irq = gpiod_to_irq(info->id_gpiod);
if (info->id_irq < 0) {
dev_err(dev, "failed to get ID IRQ\n");
return info->id_irq;
}
ret = devm_request_threaded_irq(dev, info->id_irq, NULL,
usb_irq_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
pdev->name, info);
if (ret < 0) {
dev_err(dev, "failed to request handler for ID IRQ\n");
return ret;
}
}
if (info->vbus_gpiod) {
info->vbus_irq = gpiod_to_irq(info->vbus_gpiod);
if (info->vbus_irq < 0) {
dev_err(dev, "failed to get VBUS IRQ\n");
return info->vbus_irq;
}
ret = devm_request_threaded_irq(dev, info->vbus_irq, NULL,
usb_irq_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
pdev->name, info);
if (ret < 0) {
dev_err(dev, "failed to request handler for VBUS IRQ\n");
return ret;
}
}
platform_set_drvdata(pdev, info);
device_init_wakeup(dev, true);
usb_extcon_detect_cable(&info->wq_detcable.work);
return 0;
}
static int usb_extcon_remove(struct platform_device *pdev)
{
struct usb_extcon_info *info = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&info->wq_detcable);
device_init_wakeup(&pdev->dev, false);
return 0;
}
static int usb_extcon_suspend(struct device *dev)
{
struct usb_extcon_info *info = dev_get_drvdata(dev);
int ret = 0;
if (device_may_wakeup(dev)) {
if (info->id_gpiod) {
ret = enable_irq_wake(info->id_irq);
if (ret)
return ret;
}
if (info->vbus_gpiod) {
ret = enable_irq_wake(info->vbus_irq);
if (ret) {
if (info->id_gpiod)
disable_irq_wake(info->id_irq);
return ret;
}
}
}
if (info->id_gpiod)
disable_irq(info->id_irq);
if (info->vbus_gpiod)
disable_irq(info->vbus_irq);
return ret;
}
static int usb_extcon_resume(struct device *dev)
{
struct usb_extcon_info *info = dev_get_drvdata(dev);
int ret = 0;
if (device_may_wakeup(dev)) {
if (info->id_gpiod) {
ret = disable_irq_wake(info->id_irq);
if (ret)
return ret;
}
if (info->vbus_gpiod) {
ret = disable_irq_wake(info->vbus_irq);
if (ret) {
if (info->id_gpiod)
enable_irq_wake(info->id_irq);
return ret;
}
}
}
if (info->id_gpiod)
enable_irq(info->id_irq);
if (info->vbus_gpiod)
enable_irq(info->vbus_irq);
if (!device_may_wakeup(dev))
queue_delayed_work(system_power_efficient_wq,
&info->wq_detcable, 0);
return ret;
}
