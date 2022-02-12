static irqreturn_t ltc3651_charger_irq(int irq, void *devid)
{
struct power_supply *charger = devid;
power_supply_changed(charger);
return IRQ_HANDLED;
}
static inline struct ltc3651_charger *psy_to_ltc3651_charger(
struct power_supply *psy)
{
return power_supply_get_drvdata(psy);
}
static int ltc3651_charger_get_property(struct power_supply *psy,
enum power_supply_property psp, union power_supply_propval *val)
{
struct ltc3651_charger *ltc3651_charger = psy_to_ltc3651_charger(psy);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (!ltc3651_charger->chrg_gpio) {
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
break;
}
if (gpiod_get_value(ltc3651_charger->chrg_gpio))
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = gpiod_get_value(ltc3651_charger->acpr_gpio);
break;
case POWER_SUPPLY_PROP_HEALTH:
if (!ltc3651_charger->fault_gpio) {
val->intval = POWER_SUPPLY_HEALTH_UNKNOWN;
break;
}
if (!gpiod_get_value(ltc3651_charger->fault_gpio)) {
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
}
if (!ltc3651_charger->chrg_gpio) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
}
val->intval = gpiod_get_value(ltc3651_charger->chrg_gpio) ?
POWER_SUPPLY_HEALTH_OVERHEAT :
POWER_SUPPLY_HEALTH_DEAD;
break;
default:
return -EINVAL;
}
return 0;
}
static int ltc3651_charger_probe(struct platform_device *pdev)
{
struct power_supply_config psy_cfg = {};
struct ltc3651_charger *ltc3651_charger;
struct power_supply_desc *charger_desc;
int ret;
ltc3651_charger = devm_kzalloc(&pdev->dev, sizeof(*ltc3651_charger),
GFP_KERNEL);
if (!ltc3651_charger)
return -ENOMEM;
ltc3651_charger->acpr_gpio = devm_gpiod_get(&pdev->dev,
"lltc,acpr", GPIOD_IN);
if (IS_ERR(ltc3651_charger->acpr_gpio)) {
ret = PTR_ERR(ltc3651_charger->acpr_gpio);
dev_err(&pdev->dev, "Failed to acquire acpr GPIO: %d\n", ret);
return ret;
}
ltc3651_charger->fault_gpio = devm_gpiod_get_optional(&pdev->dev,
"lltc,fault", GPIOD_IN);
if (IS_ERR(ltc3651_charger->fault_gpio)) {
ret = PTR_ERR(ltc3651_charger->fault_gpio);
dev_err(&pdev->dev, "Failed to acquire fault GPIO: %d\n", ret);
return ret;
}
ltc3651_charger->chrg_gpio = devm_gpiod_get_optional(&pdev->dev,
"lltc,chrg", GPIOD_IN);
if (IS_ERR(ltc3651_charger->chrg_gpio)) {
ret = PTR_ERR(ltc3651_charger->chrg_gpio);
dev_err(&pdev->dev, "Failed to acquire chrg GPIO: %d\n", ret);
return ret;
}
charger_desc = &ltc3651_charger->charger_desc;
charger_desc->name = pdev->dev.of_node->name;
charger_desc->type = POWER_SUPPLY_TYPE_MAINS;
charger_desc->properties = ltc3651_charger_properties;
charger_desc->num_properties = ARRAY_SIZE(ltc3651_charger_properties);
charger_desc->get_property = ltc3651_charger_get_property;
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = ltc3651_charger;
ltc3651_charger->charger = devm_power_supply_register(&pdev->dev,
charger_desc, &psy_cfg);
if (IS_ERR(ltc3651_charger->charger)) {
ret = PTR_ERR(ltc3651_charger->charger);
dev_err(&pdev->dev, "Failed to register power supply: %d\n",
ret);
return ret;
}
if (ltc3651_charger->acpr_gpio) {
ret = gpiod_to_irq(ltc3651_charger->acpr_gpio);
if (ret >= 0)
ret = devm_request_any_context_irq(&pdev->dev, ret,
ltc3651_charger_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), ltc3651_charger->charger);
if (ret < 0)
dev_warn(&pdev->dev, "Failed to request acpr irq\n");
}
if (ltc3651_charger->fault_gpio) {
ret = gpiod_to_irq(ltc3651_charger->fault_gpio);
if (ret >= 0)
ret = devm_request_any_context_irq(&pdev->dev, ret,
ltc3651_charger_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), ltc3651_charger->charger);
if (ret < 0)
dev_warn(&pdev->dev, "Failed to request fault irq\n");
}
if (ltc3651_charger->chrg_gpio) {
ret = gpiod_to_irq(ltc3651_charger->chrg_gpio);
if (ret >= 0)
ret = devm_request_any_context_irq(&pdev->dev, ret,
ltc3651_charger_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&pdev->dev), ltc3651_charger->charger);
if (ret < 0)
dev_warn(&pdev->dev, "Failed to request chrg irq\n");
}
platform_set_drvdata(pdev, ltc3651_charger);
return 0;
}
