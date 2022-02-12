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
if (IS_ENABLED(CONFIG_AXP20X_ADC)) {
ret = iio_read_channel_processed(power->vbus_v,
&val->intval);
if (ret)
return ret;
val->intval *= 1000;
return 0;
}
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
if (power->axp20x_id == AXP221_ID)
val->intval = -1;
else
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
if (IS_ENABLED(CONFIG_AXP20X_ADC)) {
ret = iio_read_channel_processed(power->vbus_i,
&val->intval);
if (ret)
return ret;
val->intval *= 1000;
return 0;
}
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
val->intval = POWER_SUPPLY_HEALTH_GOOD;
if (power->axp20x_id == AXP202_ID) {
ret = regmap_read(power->regmap,
AXP20X_USB_OTG_STATUS, &v);
if (ret)
return ret;
if (!(v & AXP20X_USB_STATUS_VBUS_VALID))
val->intval =
POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
}
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
static int axp20x_usb_power_set_voltage_min(struct axp20x_usb_power *power,
int intval)
{
int val;
switch (intval) {
case 4000000:
case 4100000:
case 4200000:
case 4300000:
case 4400000:
case 4500000:
case 4600000:
case 4700000:
val = (intval - 4000000) / 100000;
return regmap_update_bits(power->regmap,
AXP20X_VBUS_IPSOUT_MGMT,
AXP20X_VBUS_VHOLD_MASK,
val << AXP20X_VBUS_VHOLD_OFFSET);
default:
return -EINVAL;
}
return -EINVAL;
}
static int axp20x_usb_power_set_current_max(struct axp20x_usb_power *power,
int intval)
{
int val;
switch (intval) {
case 100000:
if (power->axp20x_id == AXP221_ID)
return -EINVAL;
case 500000:
case 900000:
val = (900000 - intval) / 400000;
return regmap_update_bits(power->regmap,
AXP20X_VBUS_IPSOUT_MGMT,
AXP20X_VBUS_CLIMIT_MASK, val);
default:
return -EINVAL;
}
return -EINVAL;
}
static int axp20x_usb_power_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct axp20x_usb_power *power = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_VOLTAGE_MIN:
return axp20x_usb_power_set_voltage_min(power, val->intval);
case POWER_SUPPLY_PROP_CURRENT_MAX:
return axp20x_usb_power_set_current_max(power, val->intval);
default:
return -EINVAL;
}
return -EINVAL;
}
static int axp20x_usb_power_prop_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
return psp == POWER_SUPPLY_PROP_VOLTAGE_MIN ||
psp == POWER_SUPPLY_PROP_CURRENT_MAX;
}
static int configure_iio_channels(struct platform_device *pdev,
struct axp20x_usb_power *power)
{
power->vbus_v = devm_iio_channel_get(&pdev->dev, "vbus_v");
if (IS_ERR(power->vbus_v)) {
if (PTR_ERR(power->vbus_v) == -ENODEV)
return -EPROBE_DEFER;
return PTR_ERR(power->vbus_v);
}
power->vbus_i = devm_iio_channel_get(&pdev->dev, "vbus_i");
if (IS_ERR(power->vbus_i)) {
if (PTR_ERR(power->vbus_i) == -ENODEV)
return -EPROBE_DEFER;
return PTR_ERR(power->vbus_i);
}
return 0;
}
static int configure_adc_registers(struct axp20x_usb_power *power)
{
return regmap_update_bits(power->regmap, AXP20X_ADC_EN1,
AXP20X_ADC_EN1_VBUS_CURR |
AXP20X_ADC_EN1_VBUS_VOLT,
AXP20X_ADC_EN1_VBUS_CURR |
AXP20X_ADC_EN1_VBUS_VOLT);
}
static int axp20x_usb_power_probe(struct platform_device *pdev)
{
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
struct power_supply_config psy_cfg = {};
struct axp20x_usb_power *power;
static const char * const axp20x_irq_names[] = { "VBUS_PLUGIN",
"VBUS_REMOVAL", "VBUS_VALID", "VBUS_NOT_VALID", NULL };
static const char * const axp22x_irq_names[] = {
"VBUS_PLUGIN", "VBUS_REMOVAL", NULL };
static const char * const *irq_names;
const struct power_supply_desc *usb_power_desc;
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
power->axp20x_id = (enum axp20x_variants)of_device_get_match_data(
&pdev->dev);
power->np = pdev->dev.of_node;
power->regmap = axp20x->regmap;
if (power->axp20x_id == AXP202_ID) {
ret = regmap_update_bits(power->regmap, AXP20X_VBUS_MON,
AXP20X_VBUS_MON_VBUS_VALID,
AXP20X_VBUS_MON_VBUS_VALID);
if (ret)
return ret;
if (IS_ENABLED(CONFIG_AXP20X_ADC))
ret = configure_iio_channels(pdev, power);
else
ret = configure_adc_registers(power);
if (ret)
return ret;
usb_power_desc = &axp20x_usb_power_desc;
irq_names = axp20x_irq_names;
} else if (power->axp20x_id == AXP221_ID ||
power->axp20x_id == AXP223_ID) {
usb_power_desc = &axp22x_usb_power_desc;
irq_names = axp22x_irq_names;
} else {
dev_err(&pdev->dev, "Unsupported AXP variant: %ld\n",
axp20x->variant);
return -EINVAL;
}
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = power;
power->supply = devm_power_supply_register(&pdev->dev, usb_power_desc,
&psy_cfg);
if (IS_ERR(power->supply))
return PTR_ERR(power->supply);
for (i = 0; irq_names[i]; i++) {
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
