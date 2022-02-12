static int rx51_battery_read_adc(struct iio_channel *channel)
{
int val, err;
err = iio_read_channel_average_raw(channel, &val);
if (err < 0)
return err;
return val;
}
static int rx51_battery_read_voltage(struct rx51_device_info *di)
{
int voltage = rx51_battery_read_adc(di->channel_vbat);
if (voltage < 0) {
dev_err(di->dev, "Could not read ADC: %d\n", voltage);
return voltage;
}
return 1000 * (10000 * voltage / 1705);
}
static int rx51_battery_read_temperature(struct rx51_device_info *di)
{
int min = 0;
int max = ARRAY_SIZE(rx51_temp_table2) - 1;
int raw = rx51_battery_read_adc(di->channel_temp);
if (raw < 0)
dev_err(di->dev, "Could not read ADC: %d\n", raw);
if (raw <= 0)
return INT_MAX;
if (raw >= (1 << 10))
return INT_MIN;
if (raw < ARRAY_SIZE(rx51_temp_table1))
return rx51_temp_table1[raw] * 10;
while (max - min > 1) {
int mid = (max + min) / 2;
if (rx51_temp_table2[mid] <= raw)
min = mid;
else if (rx51_temp_table2[mid] > raw)
max = mid;
if (rx51_temp_table2[mid] == raw)
break;
}
return (rx51_temp_table2_first - min) * 10;
}
static int rx51_battery_read_capacity(struct rx51_device_info *di)
{
int capacity = rx51_battery_read_adc(di->channel_bsi);
if (capacity < 0) {
dev_err(di->dev, "Could not read ADC: %d\n", capacity);
return capacity;
}
return 1280 * (1200 * capacity)/(1024 - capacity);
}
static int rx51_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct rx51_device_info *di = power_supply_get_drvdata(psy);
switch (psp) {
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
val->intval = 4200000;
break;
case POWER_SUPPLY_PROP_PRESENT:
val->intval = rx51_battery_read_voltage(di) ? 1 : 0;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
val->intval = rx51_battery_read_voltage(di);
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval = rx51_battery_read_temperature(di);
break;
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
val->intval = rx51_battery_read_capacity(di);
break;
default:
return -EINVAL;
}
if (val->intval == INT_MAX || val->intval == INT_MIN)
return -EINVAL;
return 0;
}
static int rx51_battery_probe(struct platform_device *pdev)
{
struct power_supply_config psy_cfg = {};
struct rx51_device_info *di;
int ret;
di = devm_kzalloc(&pdev->dev, sizeof(*di), GFP_KERNEL);
if (!di)
return -ENOMEM;
platform_set_drvdata(pdev, di);
di->dev = &pdev->dev;
di->bat_desc.name = "rx51-battery";
di->bat_desc.type = POWER_SUPPLY_TYPE_BATTERY;
di->bat_desc.properties = rx51_battery_props;
di->bat_desc.num_properties = ARRAY_SIZE(rx51_battery_props);
di->bat_desc.get_property = rx51_battery_get_property;
psy_cfg.drv_data = di;
di->channel_temp = iio_channel_get(di->dev, "temp");
if (IS_ERR(di->channel_temp)) {
ret = PTR_ERR(di->channel_temp);
goto error;
}
di->channel_bsi = iio_channel_get(di->dev, "bsi");
if (IS_ERR(di->channel_bsi)) {
ret = PTR_ERR(di->channel_bsi);
goto error_channel_temp;
}
di->channel_vbat = iio_channel_get(di->dev, "vbat");
if (IS_ERR(di->channel_vbat)) {
ret = PTR_ERR(di->channel_vbat);
goto error_channel_bsi;
}
di->bat = power_supply_register(di->dev, &di->bat_desc, &psy_cfg);
if (IS_ERR(di->bat)) {
ret = PTR_ERR(di->bat);
goto error_channel_vbat;
}
return 0;
error_channel_vbat:
iio_channel_release(di->channel_vbat);
error_channel_bsi:
iio_channel_release(di->channel_bsi);
error_channel_temp:
iio_channel_release(di->channel_temp);
error:
return ret;
}
static int rx51_battery_remove(struct platform_device *pdev)
{
struct rx51_device_info *di = platform_get_drvdata(pdev);
power_supply_unregister(di->bat);
iio_channel_release(di->channel_vbat);
iio_channel_release(di->channel_bsi);
iio_channel_release(di->channel_temp);
return 0;
}
