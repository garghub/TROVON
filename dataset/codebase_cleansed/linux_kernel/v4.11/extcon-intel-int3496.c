static void int3496_do_usb_id(struct work_struct *work)
{
struct int3496_data *data =
container_of(work, struct int3496_data, work.work);
int id = gpiod_get_value_cansleep(data->gpio_usb_id);
dev_dbg(data->dev, "Connected %s cable\n", id ? "PERIPHERAL" : "HOST");
if (!IS_ERR(data->gpio_usb_mux))
gpiod_direction_output(data->gpio_usb_mux, id);
if (!IS_ERR(data->gpio_vbus_en))
gpiod_direction_output(data->gpio_vbus_en, !id);
extcon_set_state_sync(data->edev, EXTCON_USB_HOST, !id);
}
static irqreturn_t int3496_thread_isr(int irq, void *priv)
{
struct int3496_data *data = priv;
mod_delayed_work(system_wq, &data->work, DEBOUNCE_TIME);
return IRQ_HANDLED;
}
static int int3496_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct int3496_data *data;
int ret;
ret = acpi_dev_add_driver_gpios(ACPI_COMPANION(dev),
acpi_int3496_default_gpios);
if (ret) {
dev_err(dev, "can't add GPIO ACPI mapping\n");
return ret;
}
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->dev = dev;
INIT_DELAYED_WORK(&data->work, int3496_do_usb_id);
data->gpio_usb_id = devm_gpiod_get(dev, "id", GPIOD_IN);
if (IS_ERR(data->gpio_usb_id)) {
ret = PTR_ERR(data->gpio_usb_id);
dev_err(dev, "can't request USB ID GPIO: %d\n", ret);
return ret;
} else if (gpiod_get_direction(data->gpio_usb_id) != GPIOF_DIR_IN) {
dev_warn(dev, FW_BUG "USB ID GPIO not in input mode, fixing\n");
gpiod_direction_input(data->gpio_usb_id);
}
data->usb_id_irq = gpiod_to_irq(data->gpio_usb_id);
if (data->usb_id_irq < 0) {
dev_err(dev, "can't get USB ID IRQ: %d\n", data->usb_id_irq);
return data->usb_id_irq;
}
data->gpio_vbus_en = devm_gpiod_get(dev, "vbus", GPIOD_ASIS);
if (IS_ERR(data->gpio_vbus_en))
dev_info(dev, "can't request VBUS EN GPIO\n");
data->gpio_usb_mux = devm_gpiod_get(dev, "mux", GPIOD_ASIS);
if (IS_ERR(data->gpio_usb_mux))
dev_info(dev, "can't request USB MUX GPIO\n");
data->edev = devm_extcon_dev_allocate(dev, int3496_cable);
if (IS_ERR(data->edev))
return -ENOMEM;
ret = devm_extcon_dev_register(dev, data->edev);
if (ret < 0) {
dev_err(dev, "can't register extcon device: %d\n", ret);
return ret;
}
ret = devm_request_threaded_irq(dev, data->usb_id_irq,
NULL, int3496_thread_isr,
IRQF_SHARED | IRQF_ONESHOT |
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING,
dev_name(dev), data);
if (ret < 0) {
dev_err(dev, "can't request IRQ for USB ID GPIO: %d\n", ret);
return ret;
}
queue_delayed_work(system_wq, &data->work, 0);
platform_set_drvdata(pdev, data);
return 0;
}
static int int3496_remove(struct platform_device *pdev)
{
struct int3496_data *data = platform_get_drvdata(pdev);
devm_free_irq(&pdev->dev, data->usb_id_irq, data);
cancel_delayed_work_sync(&data->work);
acpi_dev_remove_driver_gpios(ACPI_COMPANION(&pdev->dev));
return 0;
}
