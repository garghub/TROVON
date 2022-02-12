static int rx51_battery_read_adc(int channel)
{
struct twl4030_madc_request req;
req.channels = 1 << channel;
req.do_avg = 1;
req.method = TWL4030_MADC_SW1;
req.func_cb = NULL;
req.type = TWL4030_MADC_WAIT;
if (twl4030_madc_conversion(&req) <= 0)
return -ENODATA;
return req.rbuf[channel];
}
static int rx51_battery_read_voltage(struct rx51_device_info *di)
{
int voltage = rx51_battery_read_adc(12);
if (voltage < 0)
return voltage;
return 1000 * (10000 * voltage / 1705);
}
static int rx51_battery_read_temperature(struct rx51_device_info *di)
{
int min = 0;
int max = ARRAY_SIZE(rx51_temp_table2) - 1;
int raw = rx51_battery_read_adc(0);
if (raw <= 0)
return INT_MAX;
if (raw >= (1 << 10))
return INT_MIN;
if (raw < ARRAY_SIZE(rx51_temp_table1))
return rx51_temp_table1[raw] * 100;
while (max - min > 1) {
int mid = (max + min) / 2;
if (rx51_temp_table2[mid] <= raw)
min = mid;
else if (rx51_temp_table2[mid] > raw)
max = mid;
if (rx51_temp_table2[mid] == raw)
break;
}
return (rx51_temp_table2_first - min) * 100;
}
static int rx51_battery_read_capacity(struct rx51_device_info *di)
{
int capacity = rx51_battery_read_adc(4);
if (capacity < 0)
return capacity;
return 1280 * (1200 * capacity)/(1024 - capacity);
}
static int rx51_battery_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct rx51_device_info *di = container_of((psy),
struct rx51_device_info, bat);
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
struct rx51_device_info *di;
int ret;
di = kzalloc(sizeof(*di), GFP_KERNEL);
if (!di)
return -ENOMEM;
platform_set_drvdata(pdev, di);
di->bat.name = dev_name(&pdev->dev);
di->bat.type = POWER_SUPPLY_TYPE_BATTERY;
di->bat.properties = rx51_battery_props;
di->bat.num_properties = ARRAY_SIZE(rx51_battery_props);
di->bat.get_property = rx51_battery_get_property;
ret = power_supply_register(di->dev, &di->bat);
if (ret) {
platform_set_drvdata(pdev, NULL);
kfree(di);
return ret;
}
return 0;
}
static int rx51_battery_remove(struct platform_device *pdev)
{
struct rx51_device_info *di = platform_get_drvdata(pdev);
power_supply_unregister(&di->bat);
platform_set_drvdata(pdev, NULL);
kfree(di);
return 0;
}
