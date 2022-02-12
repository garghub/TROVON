static int ltc2990_voltage_to_int(int raw)
{
if (raw & BIT(14))
return -(0x4000 - (raw & 0x3FFF)) << 2;
else
return (raw & 0x3FFF) << 2;
}
static int ltc2990_get_value(struct i2c_client *i2c, u8 reg, int *result)
{
int val;
val = i2c_smbus_read_word_swapped(i2c, reg);
if (unlikely(val < 0))
return val;
switch (reg) {
case LTC2990_TINT_MSB:
val = (val & 0x1FFF) << 3;
*result = (val * 1000) >> 7;
break;
case LTC2990_V1_MSB:
case LTC2990_V3_MSB:
*result = ltc2990_voltage_to_int(val) * 1942 / (4 * 100);
break;
case LTC2990_VCC_MSB:
*result = (ltc2990_voltage_to_int(val) * 30518 /
(4 * 100 * 1000)) + 2500;
break;
default:
return -EINVAL;
}
return 0;
}
static ssize_t ltc2990_show_value(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int value;
int ret;
ret = ltc2990_get_value(dev_get_drvdata(dev), attr->index, &value);
if (unlikely(ret < 0))
return ret;
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static int ltc2990_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
int ret;
struct device *hwmon_dev;
if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA))
return -ENODEV;
ret = i2c_smbus_write_byte_data(i2c, LTC2990_CONTROL,
LTC2990_CONTROL_MEASURE_ALL |
LTC2990_CONTROL_MODE_CURRENT);
if (ret < 0) {
dev_err(&i2c->dev, "Error: Failed to set control mode.\n");
return ret;
}
ret = i2c_smbus_write_byte_data(i2c, LTC2990_TRIGGER, 1);
if (ret < 0) {
dev_err(&i2c->dev, "Error: Failed to start acquisition.\n");
return ret;
}
hwmon_dev = devm_hwmon_device_register_with_groups(&i2c->dev,
i2c->name,
i2c,
ltc2990_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
