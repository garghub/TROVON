static int lego_ev3_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct lego_ev3_battery *batt = power_supply_get_drvdata(psy);
int val2;
switch (psp) {
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = batt->technology;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
iio_read_channel_processed(batt->iio_v, &val->intval);
val->intval *= 2000;
val->intval += 200000;
iio_read_channel_processed(batt->iio_i, &val2);
val2 *= 1000;
val2 /= 15;
val->intval += val2;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
val->intval = batt->v_max;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
val->intval = batt->v_min;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
iio_read_channel_processed(batt->iio_i, &val->intval);
val->intval *= 20000;
val->intval /= 15;
break;
case POWER_SUPPLY_PROP_SCOPE:
val->intval = POWER_SUPPLY_SCOPE_SYSTEM;
break;
default:
return -EINVAL;
}
return 0;
}
static int lego_ev3_battery_set_property(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct lego_ev3_battery *batt = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_TECHNOLOGY:
if (batt->technology != POWER_SUPPLY_TECHNOLOGY_UNKNOWN)
return -EINVAL;
switch (val->intval) {
case POWER_SUPPLY_TECHNOLOGY_NiMH:
batt->technology = POWER_SUPPLY_TECHNOLOGY_NiMH;
batt->v_max = 7800000;
batt->v_min = 5400000;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return 0;
}
static int lego_ev3_battery_property_is_writeable(struct power_supply *psy,
enum power_supply_property psp)
{
struct lego_ev3_battery *batt = power_supply_get_drvdata(psy);
return psp == POWER_SUPPLY_PROP_TECHNOLOGY &&
batt->technology == POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
}
static int lego_ev3_battery_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct lego_ev3_battery *batt;
struct power_supply_config psy_cfg = {};
int err;
batt = devm_kzalloc(dev, sizeof(*batt), GFP_KERNEL);
if (!batt)
return -ENOMEM;
platform_set_drvdata(pdev, batt);
batt->iio_v = devm_iio_channel_get(dev, "voltage");
err = PTR_ERR_OR_ZERO(batt->iio_v);
if (err) {
if (err != -EPROBE_DEFER)
dev_err(dev, "Failed to get voltage iio channel\n");
return err;
}
batt->iio_i = devm_iio_channel_get(dev, "current");
err = PTR_ERR_OR_ZERO(batt->iio_i);
if (err) {
if (err != -EPROBE_DEFER)
dev_err(dev, "Failed to get current iio channel\n");
return err;
}
batt->rechargeable_gpio = devm_gpiod_get(dev, "rechargeable", GPIOD_IN);
err = PTR_ERR_OR_ZERO(batt->rechargeable_gpio);
if (err) {
if (err != -EPROBE_DEFER)
dev_err(dev, "Failed to get rechargeable gpio\n");
return err;
}
if (gpiod_get_value(batt->rechargeable_gpio)) {
batt->technology = POWER_SUPPLY_TECHNOLOGY_LION;
batt->v_max = 84000000;
batt->v_min = 60000000;
} else {
batt->technology = POWER_SUPPLY_TECHNOLOGY_UNKNOWN;
batt->v_max = 90000000;
batt->v_min = 48000000;
}
psy_cfg.of_node = pdev->dev.of_node;
psy_cfg.drv_data = batt;
batt->psy = devm_power_supply_register(dev, &lego_ev3_battery_desc,
&psy_cfg);
err = PTR_ERR_OR_ZERO(batt->psy);
if (err) {
dev_err(dev, "failed to register power supply\n");
return err;
}
return 0;
}
