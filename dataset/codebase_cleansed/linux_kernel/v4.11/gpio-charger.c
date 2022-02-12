static irqreturn_t gpio_charger_irq(int irq, void *devid)
{
struct power_supply *charger = devid;
power_supply_changed(charger);
return IRQ_HANDLED;
}
static inline struct gpio_charger *psy_to_gpio_charger(struct power_supply *psy)
{
return power_supply_get_drvdata(psy);
}
static int gpio_charger_get_property(struct power_supply *psy,
enum power_supply_property psp, union power_supply_propval *val)
{
struct gpio_charger *gpio_charger = psy_to_gpio_charger(psy);
const struct gpio_charger_platform_data *pdata = gpio_charger->pdata;
switch (psp) {
case POWER_SUPPLY_PROP_ONLINE:
val->intval = gpiod_get_value_cansleep(gpio_charger->gpiod);
val->intval ^= pdata->gpio_active_low;
break;
default:
return -EINVAL;
}
return 0;
}
static
struct gpio_charger_platform_data *gpio_charger_parse_dt(struct device *dev)
{
struct device_node *np = dev->of_node;
struct gpio_charger_platform_data *pdata;
const char *chargetype;
int ret;
if (!np)
return ERR_PTR(-ENOENT);
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
pdata->name = np->name;
pdata->type = POWER_SUPPLY_TYPE_UNKNOWN;
ret = of_property_read_string(np, "charger-type", &chargetype);
if (ret >= 0) {
if (!strncmp("unknown", chargetype, 7))
pdata->type = POWER_SUPPLY_TYPE_UNKNOWN;
else if (!strncmp("battery", chargetype, 7))
pdata->type = POWER_SUPPLY_TYPE_BATTERY;
else if (!strncmp("ups", chargetype, 3))
pdata->type = POWER_SUPPLY_TYPE_UPS;
else if (!strncmp("mains", chargetype, 5))
pdata->type = POWER_SUPPLY_TYPE_MAINS;
else if (!strncmp("usb-sdp", chargetype, 7))
pdata->type = POWER_SUPPLY_TYPE_USB;
else if (!strncmp("usb-dcp", chargetype, 7))
pdata->type = POWER_SUPPLY_TYPE_USB_DCP;
else if (!strncmp("usb-cdp", chargetype, 7))
pdata->type = POWER_SUPPLY_TYPE_USB_CDP;
else if (!strncmp("usb-aca", chargetype, 7))
pdata->type = POWER_SUPPLY_TYPE_USB_ACA;
else
dev_warn(dev, "unknown charger type %s\n", chargetype);
}
return pdata;
}
static int gpio_charger_probe(struct platform_device *pdev)
{
const struct gpio_charger_platform_data *pdata = pdev->dev.platform_data;
struct power_supply_config psy_cfg = {};
struct gpio_charger *gpio_charger;
struct power_supply_desc *charger_desc;
int ret;
int irq;
if (!pdata) {
pdata = gpio_charger_parse_dt(&pdev->dev);
if (IS_ERR(pdata)) {
ret = PTR_ERR(pdata);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "No platform data\n");
return ret;
}
}
gpio_charger = devm_kzalloc(&pdev->dev, sizeof(*gpio_charger),
GFP_KERNEL);
if (!gpio_charger) {
dev_err(&pdev->dev, "Failed to alloc driver structure\n");
return -ENOMEM;
}
gpio_charger->gpiod = devm_gpiod_get(&pdev->dev, NULL, GPIOD_IN);
if (IS_ERR(gpio_charger->gpiod) && !pdev->dev.of_node) {
if (!gpio_is_valid(pdata->gpio)) {
dev_err(&pdev->dev, "Invalid gpio pin in pdata\n");
return -EINVAL;
}
ret = gpio_request(pdata->gpio, dev_name(&pdev->dev));
if (ret) {
dev_err(&pdev->dev, "Failed to request gpio pin: %d\n",
ret);
return ret;
}
gpio_charger->legacy_gpio_requested = true;
ret = gpio_direction_input(pdata->gpio);
if (ret) {
dev_err(&pdev->dev, "Failed to set gpio to input: %d\n",
ret);
goto err_gpio_free;
}
gpio_charger->gpiod = gpio_to_desc(pdata->gpio);
} else if (IS_ERR(gpio_charger->gpiod)) {
if (PTR_ERR(gpio_charger->gpiod) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_err(&pdev->dev, "error getting GPIO descriptor\n");
return PTR_ERR(gpio_charger->gpiod);
}
charger_desc = &gpio_charger->charger_desc;
charger_desc->name = pdata->name ? pdata->name : "gpio-charger";
charger_desc->type = pdata->type;
charger_desc->properties = gpio_charger_properties;
charger_desc->num_properties = ARRAY_SIZE(gpio_charger_properties);
charger_desc->get_property = gpio_charger_get_property;
psy_cfg.supplied_to = pdata->supplied_to;
psy_cfg.num_supplicants = pdata->num_supplicants;
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = gpio_charger;
gpio_charger->pdata = pdata;
gpio_charger->charger = power_supply_register(&pdev->dev,
charger_desc, &psy_cfg);
if (IS_ERR(gpio_charger->charger)) {
ret = PTR_ERR(gpio_charger->charger);
dev_err(&pdev->dev, "Failed to register power supply: %d\n",
ret);
goto err_gpio_free;
}
irq = gpiod_to_irq(gpio_charger->gpiod);
if (irq > 0) {
ret = request_any_context_irq(irq, gpio_charger_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), gpio_charger->charger);
if (ret < 0)
dev_warn(&pdev->dev, "Failed to request irq: %d\n", ret);
else
gpio_charger->irq = irq;
}
platform_set_drvdata(pdev, gpio_charger);
device_init_wakeup(&pdev->dev, 1);
return 0;
err_gpio_free:
if (gpio_charger->legacy_gpio_requested)
gpio_free(pdata->gpio);
return ret;
}
static int gpio_charger_remove(struct platform_device *pdev)
{
struct gpio_charger *gpio_charger = platform_get_drvdata(pdev);
if (gpio_charger->irq)
free_irq(gpio_charger->irq, gpio_charger->charger);
power_supply_unregister(gpio_charger->charger);
if (gpio_charger->legacy_gpio_requested)
gpio_free(gpio_charger->pdata->gpio);
return 0;
}
static int gpio_charger_suspend(struct device *dev)
{
struct gpio_charger *gpio_charger = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
gpio_charger->wakeup_enabled =
!enable_irq_wake(gpio_charger->irq);
return 0;
}
static int gpio_charger_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct gpio_charger *gpio_charger = platform_get_drvdata(pdev);
if (device_may_wakeup(dev) && gpio_charger->wakeup_enabled)
disable_irq_wake(gpio_charger->irq);
power_supply_changed(gpio_charger->charger);
return 0;
}
