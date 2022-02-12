static inline int tmp103_reg_to_mc(s8 val)
{
return val * 1000;
}
static inline u8 tmp103_mc_to_reg(int val)
{
return DIV_ROUND_CLOSEST(val, 1000);
}
static ssize_t tmp103_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int regval;
int ret;
ret = regmap_read(regmap, sda->index, &regval);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", tmp103_reg_to_mc(regval));
}
static ssize_t tmp103_set_temp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct regmap *regmap = dev_get_drvdata(dev);
long val;
int ret;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
val = clamp_val(val, -55000, 127000);
ret = regmap_write(regmap, sda->index, tmp103_mc_to_reg(val));
return ret ? ret : count;
}
static bool tmp103_regmap_is_volatile(struct device *dev, unsigned int reg)
{
return reg == TMP103_TEMP_REG;
}
static int tmp103_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct regmap *regmap;
int ret;
regmap = devm_regmap_init_i2c(client, &tmp103_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to allocate register map\n");
return PTR_ERR(regmap);
}
ret = regmap_update_bits(regmap, TMP103_CONF_REG, TMP103_CONFIG_MASK,
TMP103_CONFIG);
if (ret < 0) {
dev_err(&client->dev, "error writing config register\n");
return ret;
}
i2c_set_clientdata(client, regmap);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
regmap, tmp103_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
static int __maybe_unused tmp103_suspend(struct device *dev)
{
struct regmap *regmap = dev_get_drvdata(dev);
return regmap_update_bits(regmap, TMP103_CONF_REG,
TMP103_CONF_SD_MASK, 0);
}
static int __maybe_unused tmp103_resume(struct device *dev)
{
struct regmap *regmap = dev_get_drvdata(dev);
return regmap_update_bits(regmap, TMP103_CONF_REG,
TMP103_CONF_SD_MASK, TMP103_CONF_SD);
}
