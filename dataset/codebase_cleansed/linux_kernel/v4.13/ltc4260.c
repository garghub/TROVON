static int ltc4260_get_value(struct device *dev, u8 reg)
{
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int val;
int ret;
ret = regmap_read(regmap, reg, &val);
if (ret < 0)
return ret;
switch (reg) {
case LTC4260_ADIN:
val = val * 10;
break;
case LTC4260_SOURCE:
val = val * 400;
break;
case LTC4260_SENSE:
val = val * 300;
break;
default:
return -EINVAL;
}
return val;
}
static ssize_t ltc4260_show_value(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int value;
value = ltc4260_get_value(dev, attr->index);
if (value < 0)
return value;
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static ssize_t ltc4260_show_bool(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int fault;
int ret;
ret = regmap_read(regmap, LTC4260_FAULT, &fault);
if (ret < 0)
return ret;
fault &= attr->index;
if (fault)
regmap_update_bits(regmap, LTC4260_FAULT, attr->index, 0);
return snprintf(buf, PAGE_SIZE, "%d\n", !!fault);
}
static int ltc4260_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct regmap *regmap;
regmap = devm_regmap_init_i2c(client, &ltc4260_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to allocate register map\n");
return PTR_ERR(regmap);
}
regmap_write(regmap, LTC4260_FAULT, 0x00);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
regmap,
ltc4260_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
