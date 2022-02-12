static irqreturn_t pps_gpio_irq_handler(int irq, void *data)
{
const struct pps_gpio_device_data *info;
struct pps_event_time ts;
int rising_edge;
pps_get_ts(&ts);
info = data;
rising_edge = gpio_get_value(info->gpio_pin);
if ((rising_edge && !info->assert_falling_edge) ||
(!rising_edge && info->assert_falling_edge))
pps_event(info->pps, &ts, PPS_CAPTUREASSERT, NULL);
else if (info->capture_clear &&
((rising_edge && info->assert_falling_edge) ||
(!rising_edge && !info->assert_falling_edge)))
pps_event(info->pps, &ts, PPS_CAPTURECLEAR, NULL);
return IRQ_HANDLED;
}
static unsigned long
get_irqf_trigger_flags(const struct pps_gpio_device_data *data)
{
unsigned long flags = data->assert_falling_edge ?
IRQF_TRIGGER_FALLING : IRQF_TRIGGER_RISING;
if (data->capture_clear) {
flags |= ((flags & IRQF_TRIGGER_RISING) ?
IRQF_TRIGGER_FALLING : IRQF_TRIGGER_RISING);
}
return flags;
}
static int pps_gpio_probe(struct platform_device *pdev)
{
struct pps_gpio_device_data *data;
const char *gpio_label;
int ret;
int pps_default_params;
const struct pps_gpio_platform_data *pdata = pdev->dev.platform_data;
struct device_node *np = pdev->dev.of_node;
data = devm_kzalloc(&pdev->dev, sizeof(struct pps_gpio_device_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
if (pdata) {
data->gpio_pin = pdata->gpio_pin;
gpio_label = pdata->gpio_label;
data->assert_falling_edge = pdata->assert_falling_edge;
data->capture_clear = pdata->capture_clear;
} else {
ret = of_get_gpio(np, 0);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get GPIO from device tree\n");
return ret;
}
data->gpio_pin = ret;
gpio_label = PPS_GPIO_NAME;
if (of_get_property(np, "assert-falling-edge", NULL))
data->assert_falling_edge = true;
}
ret = devm_gpio_request(&pdev->dev, data->gpio_pin, gpio_label);
if (ret) {
dev_err(&pdev->dev, "failed to request GPIO %u\n",
data->gpio_pin);
return ret;
}
ret = gpio_direction_input(data->gpio_pin);
if (ret) {
dev_err(&pdev->dev, "failed to set pin direction\n");
return -EINVAL;
}
ret = gpio_to_irq(data->gpio_pin);
if (ret < 0) {
dev_err(&pdev->dev, "failed to map GPIO to IRQ: %d\n", ret);
return -EINVAL;
}
data->irq = ret;
data->info.mode = PPS_CAPTUREASSERT | PPS_OFFSETASSERT |
PPS_ECHOASSERT | PPS_CANWAIT | PPS_TSFMT_TSPEC;
if (data->capture_clear)
data->info.mode |= PPS_CAPTURECLEAR | PPS_OFFSETCLEAR |
PPS_ECHOCLEAR;
data->info.owner = THIS_MODULE;
snprintf(data->info.name, PPS_MAX_NAME_LEN - 1, "%s.%d",
pdev->name, pdev->id);
pps_default_params = PPS_CAPTUREASSERT | PPS_OFFSETASSERT;
if (data->capture_clear)
pps_default_params |= PPS_CAPTURECLEAR | PPS_OFFSETCLEAR;
data->pps = pps_register_source(&data->info, pps_default_params);
if (data->pps == NULL) {
dev_err(&pdev->dev, "failed to register IRQ %d as PPS source\n",
data->irq);
return -EINVAL;
}
ret = devm_request_irq(&pdev->dev, data->irq, pps_gpio_irq_handler,
get_irqf_trigger_flags(data), data->info.name, data);
if (ret) {
pps_unregister_source(data->pps);
dev_err(&pdev->dev, "failed to acquire IRQ %d\n", data->irq);
return -EINVAL;
}
platform_set_drvdata(pdev, data);
dev_info(data->pps->dev, "Registered IRQ %d as PPS source\n",
data->irq);
return 0;
}
static int pps_gpio_remove(struct platform_device *pdev)
{
struct pps_gpio_device_data *data = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
pps_unregister_source(data->pps);
dev_info(&pdev->dev, "removed IRQ %d as PPS source\n", data->irq);
return 0;
}
