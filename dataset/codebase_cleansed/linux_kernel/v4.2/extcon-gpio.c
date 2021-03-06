static void gpio_extcon_work(struct work_struct *work)
{
int state;
struct gpio_extcon_data *data =
container_of(to_delayed_work(work), struct gpio_extcon_data,
work);
state = gpio_get_value(data->gpio);
if (data->gpio_active_low)
state = !state;
extcon_set_state(data->edev, state);
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
struct device *dev = edev->dev.parent;
struct gpio_extcon_data *extcon_data = dev_get_drvdata(dev);
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
extcon_data->edev = devm_extcon_dev_allocate(&pdev->dev, NULL);
if (IS_ERR(extcon_data->edev)) {
dev_err(&pdev->dev, "failed to allocate extcon device\n");
return -ENOMEM;
}
extcon_data->gpio = pdata->gpio;
extcon_data->gpio_active_low = pdata->gpio_active_low;
extcon_data->state_on = pdata->state_on;
extcon_data->state_off = pdata->state_off;
extcon_data->check_on_resume = pdata->check_on_resume;
if (pdata->state_on && pdata->state_off)
extcon_data->edev->print_state = extcon_gpio_print_state;
ret = devm_gpio_request_one(&pdev->dev, extcon_data->gpio, GPIOF_DIR_IN,
pdev->name);
if (ret < 0)
return ret;
if (pdata->debounce) {
ret = gpio_set_debounce(extcon_data->gpio,
pdata->debounce * 1000);
if (ret < 0)
extcon_data->debounce_jiffies =
msecs_to_jiffies(pdata->debounce);
}
ret = devm_extcon_dev_register(&pdev->dev, extcon_data->edev);
if (ret < 0)
return ret;
INIT_DELAYED_WORK(&extcon_data->work, gpio_extcon_work);
extcon_data->irq = gpio_to_irq(extcon_data->gpio);
if (extcon_data->irq < 0)
return extcon_data->irq;
ret = request_any_context_irq(extcon_data->irq, gpio_irq_handler,
pdata->irq_flags, pdev->name,
extcon_data);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, extcon_data);
gpio_extcon_work(&extcon_data->work.work);
return 0;
}
static int gpio_extcon_remove(struct platform_device *pdev)
{
struct gpio_extcon_data *extcon_data = platform_get_drvdata(pdev);
cancel_delayed_work_sync(&extcon_data->work);
free_irq(extcon_data->irq, extcon_data);
return 0;
}
static int gpio_extcon_resume(struct device *dev)
{
struct gpio_extcon_data *extcon_data;
extcon_data = dev_get_drvdata(dev);
if (extcon_data->check_on_resume)
queue_delayed_work(system_power_efficient_wq,
&extcon_data->work, extcon_data->debounce_jiffies);
return 0;
}
