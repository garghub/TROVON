static void usb_extcon_detect_cable(struct work_struct *work)
{
int id;
struct usb_extcon_info *info = container_of(to_delayed_work(work),
struct usb_extcon_info,
wq_detcable);
id = gpiod_get_value_cansleep(info->id_gpiod);
if (id) {
extcon_set_state_sync(info->edev, EXTCON_USB_HOST, false);
extcon_set_state_sync(info->edev, EXTCON_USB, true);
} else {
extcon_set_state_sync(info->edev, EXTCON_USB, false);
extcon_set_state_sync(info->edev, EXTCON_USB_HOST, true);
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
info->id_gpiod = devm_gpiod_get(&pdev->dev, "id", GPIOD_IN);
if (IS_ERR(info->id_gpiod)) {
dev_err(dev, "failed to get ID GPIO\n");
return PTR_ERR(info->id_gpiod);
}
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
ret = gpiod_set_debounce(info->id_gpiod,
USB_GPIO_DEBOUNCE_MS * 1000);
if (ret < 0)
info->debounce_jiffies = msecs_to_jiffies(USB_GPIO_DEBOUNCE_MS);
INIT_DELAYED_WORK(&info->wq_detcable, usb_extcon_detect_cable);
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
platform_set_drvdata(pdev, info);
device_init_wakeup(dev, true);
dev_pm_set_wake_irq(dev, info->id_irq);
usb_extcon_detect_cable(&info->wq_detcable.work);
return 0;
}
static int usb_extcon_remove(struct platform_device *pdev)
{
struct usb_extcon_info *info = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&info->wq_detcable);
dev_pm_clear_wake_irq(&pdev->dev);
device_init_wakeup(&pdev->dev, false);
return 0;
}
static int usb_extcon_suspend(struct device *dev)
{
struct usb_extcon_info *info = dev_get_drvdata(dev);
int ret = 0;
disable_irq(info->id_irq);
return ret;
}
static int usb_extcon_resume(struct device *dev)
{
struct usb_extcon_info *info = dev_get_drvdata(dev);
int ret = 0;
enable_irq(info->id_irq);
if (!device_may_wakeup(dev))
queue_delayed_work(system_power_efficient_wq,
&info->wq_detcable, 0);
return ret;
}
