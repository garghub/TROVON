static void gpio_extcon_work(struct work_struct *work)
{
int state;
struct gpio_extcon_data *data =
container_of(to_delayed_work(work), struct gpio_extcon_data,
work);
state = gpio_get_value(data->gpio);
if (data->gpio_active_low)
state = !state;
extcon_set_state(&data->edev, state);
}
static irqreturn_t gpio_irq_handler(int irq, void *dev_id)
{
struct gpio_extcon_data *extcon_data = dev_id;
queue_delayed_work(system_power_efficient_wq, &extcon_data->work,
extcon_data->debounce_jiffies);
return IRQ_HANDLED;
}
static ssize_t extcon_gpio_print_state(struct extcon_dev *edev, char *buf)
{
struct gpio_extcon_data *extcon_data =
container_of(edev, struct gpio_extcon_data, edev);
const char *state;
if (extcon_get_state(edev))
state = extcon_data->state_on;
else
state = extcon_data->state_off;
if (state)
return sprintf(buf, "%s\n", state);
return -EINVAL;
}
static int gpio_extcon_probe(struct platform_device *pdev)
{
struct gpio_extcon_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct gpio_extcon_data *extcon_data;
int ret;
if (!pdata)
return -EBUSY;
if (!pdata->irq_flags) {
dev_err(&pdev->dev, "IRQ flag is not specified.\n");
return -EINVAL;
}
extcon_data = devm_kzalloc(&pdev->dev, sizeof(struct gpio_extcon_data),
GFP_KERNEL);
if (!extcon_data)
return -ENOMEM;
extcon_data->edev.name = pdata->name;
extcon_data->edev.dev.parent = &pdev->dev;
extcon_data->gpio = pdata->gpio;
extcon_data->gpio_active_low = pdata->gpio_active_low;
extcon_data->state_on = pdata->state_on;
extcon_data->state_off = pdata->state_off;
if (pdata->state_on && pdata->state_off)
extcon_data->edev.print_state = extcon_gpio_print_state;
if (pdata->debounce) {
ret = gpio_set_debounce(extcon_data->gpio,
pdata->debounce * 1000);
if (ret < 0)
extcon_data->debounce_jiffies =
msecs_to_jiffies(pdata->debounce);
}
ret = extcon_dev_register(&extcon_data->edev);
if (ret < 0)
return ret;
ret = devm_gpio_request_one(&pdev->dev, extcon_data->gpio, GPIOF_DIR_IN,
pdev->name);
if (ret < 0)
goto err;
INIT_DELAYED_WORK(&extcon_data->work, gpio_extcon_work);
extcon_data->irq = gpio_to_irq(extcon_data->gpio);
if (extcon_data->irq < 0) {
ret = extcon_data->irq;
goto err;
}
ret = request_any_context_irq(extcon_data->irq, gpio_irq_handler,
pdata->irq_flags, pdev->name,
extcon_data);
if (ret < 0)
goto err;
platform_set_drvdata(pdev, extcon_data);
gpio_extcon_work(&extcon_data->work.work);
return 0;
err:
extcon_dev_unregister(&extcon_data->edev);
return ret;
}
static int gpio_extcon_remove(struct platform_device *pdev)
{
struct gpio_extcon_data *extcon_data = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&extcon_data->work);
free_irq(extcon_data->irq, extcon_data);
extcon_dev_unregister(&extcon_data->edev);
return 0;
}
