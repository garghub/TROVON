static int ltc4222_get_value(struct device *dev, u8 reg)
{
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int val;
u8 buf[2];
int ret;
ret = regmap_bulk_read(regmap, reg, buf, 2);
if (ret < 0)
return ret;
val = ((buf[0] << 8) + buf[1]) >> 6;
switch (reg) {
case LTC4222_ADIN1:
case LTC4222_ADIN2:
val = DIV_ROUND_CLOSEST(val * 5, 4);
break;
case LTC4222_SOURCE1:
case LTC4222_SOURCE2:
val = DIV_ROUND_CLOSEST(val * 125, 4);
break;
case LTC4222_SENSE1:
case LTC4222_SENSE2:
val = DIV_ROUND_CLOSEST(val * 125, 2);
break;
default:
return -EINVAL;
}
return val;
}
static ssize_t ltc4222_show_value(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int value;
value = ltc4222_get_value(dev, attr->index);
if (value < 0)
return value;
return snprintf(buf, PAGE_SIZE, "%d\n", value);
}
static ssize_t ltc4222_show_bool(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int fault;
int ret;
ret = regmap_read(regmap, attr->nr, &fault);
if (ret < 0)
return ret;
fault &= attr->index;
if (fault)
regmap_update_bits(regmap, attr->nr, attr->index, 0);
return snprintf(buf, PAGE_SIZE, "%d\n", !!fault);
}
static int ltc4222_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct regmap *regmap;
regmap = devm_regmap_init_i2c(client, &ltc4222_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to allocate register map\n");
return PTR_ERR(regmap);
}
regmap_write(regmap, LTC4222_FAULT1, 0x00);
regmap_write(regmap, LTC4222_FAULT2, 0x00);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
regmap,
ltc4222_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
