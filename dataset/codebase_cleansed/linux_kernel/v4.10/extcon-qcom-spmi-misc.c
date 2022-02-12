static void qcom_usb_extcon_detect_cable(struct work_struct *work)
{
bool id;
int ret;
struct qcom_usb_extcon_info *info = container_of(to_delayed_work(work),
struct qcom_usb_extcon_info,
wq_detcable);
ret = irq_get_irqchip_state(info->irq, IRQCHIP_STATE_LINE_LEVEL, &id);
if (ret)
return;
extcon_set_state_sync(info->edev, EXTCON_USB_HOST, !id);
}
static irqreturn_t qcom_usb_irq_handler(int irq, void *dev_id)
{
struct qcom_usb_extcon_info *info = dev_id;
queue_delayed_work(system_power_efficient_wq, &info->wq_detcable,
info->debounce_jiffies);
return IRQ_HANDLED;
}
static int qcom_usb_extcon_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct qcom_usb_extcon_info *info;
int ret;
info = devm_kzalloc(dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->edev = devm_extcon_dev_allocate(dev, qcom_usb_extcon_cable);
if (IS_ERR(info->edev)) {
dev_err(dev, "failed to allocate extcon device\n");
return -ENOMEM;
}
ret = devm_extcon_dev_register(dev, info->edev);
if (ret < 0) {
dev_err(dev, "failed to register extcon device\n");
return ret;
}
info->debounce_jiffies = msecs_to_jiffies(USB_ID_DEBOUNCE_MS);
INIT_DELAYED_WORK(&info->wq_detcable, qcom_usb_extcon_detect_cable);
info->irq = platform_get_irq_byname(pdev, "usb_id");
if (info->irq < 0)
return info->irq;
ret = devm_request_threaded_irq(dev, info->irq, NULL,
qcom_usb_irq_handler,
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
pdev->name, info);
if (ret < 0) {
dev_err(dev, "failed to request handler for ID IRQ\n");
return ret;
}
platform_set_drvdata(pdev, info);
device_init_wakeup(dev, 1);
qcom_usb_extcon_detect_cable(&info->wq_detcable.work);
return 0;
}
static int qcom_usb_extcon_remove(struct platform_device *pdev)
{
struct qcom_usb_extcon_info *info = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&info->wq_detcable);
return 0;
}
static int qcom_usb_extcon_suspend(struct device *dev)
{
struct qcom_usb_extcon_info *info = dev_get_drvdata(dev);
int ret = 0;
if (device_may_wakeup(dev))
ret = enable_irq_wake(info->irq);
return ret;
}
static int qcom_usb_extcon_resume(struct device *dev)
{
struct qcom_usb_extcon_info *info = dev_get_drvdata(dev);
int ret = 0;
if (device_may_wakeup(dev))
ret = disable_irq_wake(info->irq);
return ret;
}
