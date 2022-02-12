static irqreturn_t gpio_charger_irq(int irq, void *devid)
{
struct power_supply *charger = devid;
power_supply_changed(charger);
return IRQ_HANDLED;
}
static inline struct gpio_charger *psy_to_gpio_charger(struct power_supply *psy)
{
return container_of(psy, struct gpio_charger, charger);
}
static int gpio_charger_get_property(struct power_supply *psy,
enum power_supply_property psp, union power_supply_propval *val)
{
struct gpio_charger *gpio_charger = psy_to_gpio_charger(psy);
const struct gpio_charger_platform_data *pdata = gpio_charger->pdata;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = gpio_get_value_cansleep(pdata->gpio);
val->intval ^= pdata->gpio_active_low;
break;
default:
return -EINVAL;
}
return 0;
}
static int gpio_charger_probe(struct platform_device *pdev)
{
const struct gpio_charger_platform_data *pdata = pdev->dev.platform_data;
struct gpio_charger *gpio_charger;
struct power_supply *charger;
int ret;
int irq;
if (!pdata) {
dev_err(&pdev->dev, "No platform data\n");
return -EINVAL;
}
if (!gpio_is_valid(pdata->gpio)) {
dev_err(&pdev->dev, "Invalid gpio pin\n");
return -EINVAL;
}
gpio_charger = kzalloc(sizeof(*gpio_charger), GFP_KERNEL);
if (!gpio_charger) {
dev_err(&pdev->dev, "Failed to alloc driver structure\n");
return -ENOMEM;
}
charger = &gpio_charger->charger;
charger->name = pdata->name ? pdata->name : "gpio-charger";
charger->type = pdata->type;
charger->properties = gpio_charger_properties;
charger->num_properties = ARRAY_SIZE(gpio_charger_properties);
charger->get_property = gpio_charger_get_property;
charger->supplied_to = pdata->supplied_to;
charger->num_supplicants = pdata->num_supplicants;
ret = gpio_request(pdata->gpio, dev_name(&pdev->dev));
if (ret) {
dev_err(&pdev->dev, "Failed to request gpio pin: %d\n", ret);
goto err_free;
}
ret = gpio_direction_input(pdata->gpio);
if (ret) {
dev_err(&pdev->dev, "Failed to set gpio to input: %d\n", ret);
goto err_gpio_free;
}
gpio_charger->pdata = pdata;
ret = power_supply_register(&pdev->dev, charger);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register power supply: %d\n",
ret);
goto err_gpio_free;
}
irq = gpio_to_irq(pdata->gpio);
if (irq > 0) {
ret = request_any_context_irq(irq, gpio_charger_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), charger);
if (ret < 0)
dev_warn(&pdev->dev, "Failed to request irq: %d\n", ret);
else
gpio_charger->irq = irq;
}
platform_set_drvdata(pdev, gpio_charger);
return 0;
err_gpio_free:
gpio_free(pdata->gpio);
err_free:
kfree(gpio_charger);
return ret;
}
static int gpio_charger_remove(struct platform_device *pdev)
{
struct gpio_charger *gpio_charger = platform_get_drvdata(pdev);
if (gpio_charger->irq)
free_irq(gpio_charger->irq, &gpio_charger->charger);
power_supply_unregister(&gpio_charger->charger);
gpio_free(gpio_charger->pdata->gpio);
platform_set_drvdata(pdev, NULL);
kfree(gpio_charger);
return 0;
}
static int gpio_charger_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct gpio_charger *gpio_charger = platform_get_drvdata(pdev);
power_supply_changed(&gpio_charger->charger);
return 0;
}
