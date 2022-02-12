static irqreturn_t axp20x_usb_power_irq(int irq, void *devid)
{
struct axp20x_usb_power *power = devid;
power_supply_changed(power->supply);
return IRQ_HANDLED;
}
static int axp20x_usb_power_get_property(struct power_supply *psy,
enum power_supply_property psp, union power_supply_propval *val)
{
struct axp20x_usb_power *power = power_supply_get_drvdata(psy);
unsigned int input, v;
int ret;
switch (psp) {
case POWER_SUPPLY_PROP_VOLTAGE_MIN:
ret = regmap_read(power->regmap, AXP20X_VBUS_IPSOUT_MGMT, &v);
if (ret)
return ret;
val->intval = AXP20X_VBUS_VHOLD_uV(v);
return 0;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = axp20x_read_variable_width(power->regmap,
AXP20X_VBUS_V_ADC_H, 12);
if (ret < 0)
return ret;
val->intval = ret * 1700;
return 0;
case POWER_SUPPLY_PROP_CURRENT_MAX:
ret = regmap_read(power->regmap, AXP20X_VBUS_IPSOUT_MGMT, &v);
if (ret)
return ret;
switch (v & AXP20X_VBUS_CLIMIT_MASK) {
case AXP20X_VBUC_CLIMIT_100mA:
val->intval = 100000;
break;
case AXP20X_VBUC_CLIMIT_500mA:
val->intval = 500000;
break;
case AXP20X_VBUC_CLIMIT_900mA:
val->intval = 900000;
break;
case AXP20X_VBUC_CLIMIT_NONE:
val->intval = -1;
break;
}
return 0;
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = axp20x_read_variable_width(power->regmap,
AXP20X_VBUS_I_ADC_H, 12);
if (ret < 0)
return ret;
val->intval = ret * 375;
return 0;
default:
break;
}
ret = regmap_read(power->regmap, AXP20X_PWR_INPUT_STATUS, &input);
if (ret)
return ret;
switch (psp) {
case POWER_SUPPLY_PROP_HEALTH:
if (!(input & AXP20X_PWR_STATUS_VBUS_PRESENT)) {
val->intval = POWER_SUPPLY_HEALTH_UNKNOWN;
break;
}
ret = regmap_read(power->regmap, AXP20X_USB_OTG_STATUS, &v);
if (ret)
return ret;
if (!(v & AXP20X_USB_STATUS_VBUS_VALID)) {
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
break;
}
val->intval = POWER_SUPPLY_HEALTH_GOOD;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = !!(input & AXP20X_PWR_STATUS_VBUS_PRESENT);
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = !!(input & AXP20X_PWR_STATUS_VBUS_USED);
break;
default:
return -EINVAL;
}
return 0;
}
static int axp20x_usb_power_probe(struct platform_device *pdev)
{
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
struct power_supply_config psy_cfg = {};
struct axp20x_usb_power *power;
static const char * const irq_names[] = { "VBUS_PLUGIN",
"VBUS_REMOVAL", "VBUS_VALID", "VBUS_NOT_VALID" };
int i, irq, ret;
if (!of_device_is_available(pdev->dev.of_node))
return -ENODEV;
if (!axp20x) {
dev_err(&pdev->dev, "Parent drvdata not set\n");
return -EINVAL;
}
power = devm_kzalloc(&pdev->dev, sizeof(*power), GFP_KERNEL);
if (!power)
return -ENOMEM;
power->regmap = axp20x->regmap;
ret = regmap_update_bits(power->regmap, AXP20X_VBUS_MON,
AXP20X_VBUS_MON_VBUS_VALID, AXP20X_VBUS_MON_VBUS_VALID);
if (ret)
return ret;
ret = regmap_update_bits(power->regmap, AXP20X_ADC_EN1,
AXP20X_ADC_EN1_VBUS_CURR | AXP20X_ADC_EN1_VBUS_VOLT,
AXP20X_ADC_EN1_VBUS_CURR | AXP20X_ADC_EN1_VBUS_VOLT);
if (ret)
return ret;
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = power;
power->supply = devm_power_supply_register(&pdev->dev,
&axp20x_usb_power_desc, &psy_cfg);
if (IS_ERR(power->supply))
return PTR_ERR(power->supply);
for (i = 0; i < ARRAY_SIZE(irq_names); i++) {
irq = platform_get_irq_byname(pdev, irq_names[i]);
if (irq < 0) {
dev_warn(&pdev->dev, "No IRQ for %s: %d\n",
irq_names[i], irq);
continue;
}
irq = regmap_irq_get_virq(axp20x->regmap_irqc, irq);
ret = devm_request_any_context_irq(&pdev->dev, irq,
axp20x_usb_power_irq, 0, DRVNAME, power);
if (ret < 0)
dev_warn(&pdev->dev, "Error requesting %s IRQ: %d\n",
irq_names[i], ret);
}
return 0;
}
