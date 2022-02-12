static irqreturn_t max3355_id_irq(int irq, void *dev_id)
{
struct max3355_data *data = dev_id;
int id = gpiod_get_value_cansleep(data->id_gpiod);
if (id) {
extcon_set_state_sync(data->edev, EXTCON_USB_HOST, false);
extcon_set_state_sync(data->edev, EXTCON_USB, true);
} else {
extcon_set_state_sync(data->edev, EXTCON_USB, false);
extcon_set_state_sync(data->edev, EXTCON_USB_HOST, true);
}
return IRQ_HANDLED;
}
static int max3355_probe(struct platform_device *pdev)
{
struct max3355_data *data;
struct gpio_desc *gpiod;
int irq, err;
data = devm_kzalloc(&pdev->dev, sizeof(struct max3355_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
gpiod = devm_gpiod_get(&pdev->dev, "id", GPIOD_IN);
if (IS_ERR(gpiod)) {
dev_err(&pdev->dev, "failed to get ID_OUT GPIO\n");
return PTR_ERR(gpiod);
}
data->id_gpiod = gpiod;
gpiod = devm_gpiod_get(&pdev->dev, "maxim,shdn", GPIOD_OUT_HIGH);
if (IS_ERR(gpiod)) {
dev_err(&pdev->dev, "failed to get SHDN# GPIO\n");
return PTR_ERR(gpiod);
}
data->shdn_gpiod = gpiod;
data->edev = devm_extcon_dev_allocate(&pdev->dev, max3355_cable);
if (IS_ERR(data->edev)) {
dev_err(&pdev->dev, "failed to allocate extcon device\n");
return PTR_ERR(data->edev);
}
err = devm_extcon_dev_register(&pdev->dev, data->edev);
if (err < 0) {
dev_err(&pdev->dev, "failed to register extcon device\n");
return err;
}
irq = gpiod_to_irq(data->id_gpiod);
if (irq < 0) {
dev_err(&pdev->dev, "failed to translate ID_OUT GPIO to IRQ\n");
return irq;
}
err = devm_request_threaded_irq(&pdev->dev, irq, NULL, max3355_id_irq,
IRQF_ONESHOT | IRQF_NO_SUSPEND |
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING,
pdev->name, data);
if (err < 0) {
dev_err(&pdev->dev, "failed to request ID_OUT IRQ\n");
return err;
}
platform_set_drvdata(pdev, data);
max3355_id_irq(irq, data);
return 0;
}
static int max3355_remove(struct platform_device *pdev)
{
struct max3355_data *data = platform_get_drvdata(pdev);
gpiod_set_value_cansleep(data->shdn_gpiod, 0);
return 0;
}
