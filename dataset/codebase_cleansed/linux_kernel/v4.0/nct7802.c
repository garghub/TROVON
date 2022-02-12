static int nct7802_read_temp(struct nct7802_data *data,
u8 reg_temp, u8 reg_temp_low, int *temp)
{
unsigned int t1, t2 = 0;
int err;
*temp = 0;
mutex_lock(&data->access_lock);
err = regmap_read(data->regmap, reg_temp, &t1);
if (err < 0)
goto abort;
t1 <<= 8;
if (reg_temp_low) {
err = regmap_read(data->regmap, reg_temp_low, &t2);
if (err < 0)
goto abort;
}
t1 |= t2 & 0xe0;
*temp = (s16)t1 / 32 * 125;
abort:
mutex_unlock(&data->access_lock);
return err;
}
static int nct7802_read_fan(struct nct7802_data *data, u8 reg_fan)
{
unsigned int f1, f2;
int ret;
mutex_lock(&data->access_lock);
ret = regmap_read(data->regmap, reg_fan, &f1);
if (ret < 0)
goto abort;
ret = regmap_read(data->regmap, REG_FANCOUNT_LOW, &f2);
if (ret < 0)
goto abort;
ret = (f1 << 5) | (f2 >> 3);
if (ret == 0x1fff)
ret = 0;
else if (ret)
ret = DIV_ROUND_CLOSEST(1350000U, ret);
abort:
mutex_unlock(&data->access_lock);
return ret;
}
static int nct7802_read_fan_min(struct nct7802_data *data, u8 reg_fan_low,
u8 reg_fan_high)
{
unsigned int f1, f2;
int ret;
mutex_lock(&data->access_lock);
ret = regmap_read(data->regmap, reg_fan_low, &f1);
if (ret < 0)
goto abort;
ret = regmap_read(data->regmap, reg_fan_high, &f2);
if (ret < 0)
goto abort;
ret = f1 | ((f2 & 0xf8) << 5);
if (ret == 0x1fff)
ret = 0;
else if (ret)
ret = DIV_ROUND_CLOSEST(1350000U, ret);
abort:
mutex_unlock(&data->access_lock);
return ret;
}
static int nct7802_write_fan_min(struct nct7802_data *data, u8 reg_fan_low,
u8 reg_fan_high, unsigned int limit)
{
int err;
if (limit)
limit = DIV_ROUND_CLOSEST(1350000U, limit);
else
limit = 0x1fff;
limit = clamp_val(limit, 0, 0x1fff);
mutex_lock(&data->access_lock);
err = regmap_write(data->regmap, reg_fan_low, limit & 0xff);
if (err < 0)
goto abort;
err = regmap_write(data->regmap, reg_fan_high, (limit & 0x1f00) >> 5);
abort:
mutex_unlock(&data->access_lock);
return err;
}
static int nct7802_read_voltage(struct nct7802_data *data, int nr, int index)
{
unsigned int v1, v2;
int ret;
mutex_lock(&data->access_lock);
if (index == 0) {
ret = regmap_read(data->regmap, REG_VOLTAGE[nr], &v1);
if (ret < 0)
goto abort;
ret = regmap_read(data->regmap, REG_VOLTAGE_LOW, &v2);
if (ret < 0)
goto abort;
ret = ((v1 << 2) | (v2 >> 6)) * nct7802_vmul[nr];
} else {
int shift = 8 - REG_VOLTAGE_LIMIT_MSB_SHIFT[index - 1][nr];
ret = regmap_read(data->regmap,
REG_VOLTAGE_LIMIT_LSB[index - 1][nr], &v1);
if (ret < 0)
goto abort;
ret = regmap_read(data->regmap, REG_VOLTAGE_LIMIT_MSB[nr],
&v2);
if (ret < 0)
goto abort;
ret = (v1 | ((v2 << shift) & 0x300)) * nct7802_vmul[nr];
}
abort:
mutex_unlock(&data->access_lock);
return ret;
}
static int nct7802_write_voltage(struct nct7802_data *data, int nr, int index,
unsigned int voltage)
{
int shift = 8 - REG_VOLTAGE_LIMIT_MSB_SHIFT[index - 1][nr];
int err;
voltage = DIV_ROUND_CLOSEST(voltage, nct7802_vmul[nr]);
voltage = clamp_val(voltage, 0, 0x3ff);
mutex_lock(&data->access_lock);
err = regmap_write(data->regmap,
REG_VOLTAGE_LIMIT_LSB[index - 1][nr],
voltage & 0xff);
if (err < 0)
goto abort;
err = regmap_update_bits(data->regmap, REG_VOLTAGE_LIMIT_MSB[nr],
0x0300 >> shift, (voltage & 0x0300) >> shift);
abort:
mutex_unlock(&data->access_lock);
return err;
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
int voltage;
voltage = nct7802_read_voltage(data, sattr->nr, sattr->index);
if (voltage < 0)
return voltage;
return sprintf(buf, "%d\n", voltage);
}
static ssize_t store_in(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
int index = sattr->index;
int nr = sattr->nr;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
err = nct7802_write_voltage(data, nr, index, val);
return err ? : count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct nct7802_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int err, temp;
err = nct7802_read_temp(data, sattr->nr, sattr->index, &temp);
if (err < 0)
return err;
return sprintf(buf, "%d\n", temp);
}
static ssize_t store_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
int nr = sattr->nr;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), -128, 127);
err = regmap_write(data->regmap, nr, val & 0xff);
return err ? : count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
int speed;
speed = nct7802_read_fan(data, sattr->index);
if (speed < 0)
return speed;
return sprintf(buf, "%d\n", speed);
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
int speed;
speed = nct7802_read_fan_min(data, sattr->nr, sattr->index);
if (speed < 0)
return speed;
return sprintf(buf, "%d\n", speed);
}
static ssize_t store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
err = nct7802_write_fan_min(data, sattr->nr, sattr->index, val);
return err ? : count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct nct7802_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int bit = sattr->index;
unsigned int val;
int ret;
ret = regmap_read(data->regmap, sattr->nr, &val);
if (ret < 0)
return ret;
return sprintf(buf, "%u\n", !!(val & (1 << bit)));
}
static ssize_t
show_beep(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
unsigned int regval;
int err;
err = regmap_read(data->regmap, sattr->nr, &regval);
if (err)
return err;
return sprintf(buf, "%u\n", !!(regval & (1 << sattr->index)));
}
static ssize_t
store_beep(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct7802_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > 1)
return -EINVAL;
err = regmap_update_bits(data->regmap, sattr->nr, 1 << sattr->index,
val ? 1 << sattr->index : 0);
return err ? : count;
}
static umode_t nct7802_temp_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct7802_data *data = dev_get_drvdata(dev);
unsigned int reg;
int err;
err = regmap_read(data->regmap, REG_MODE, &reg);
if (err < 0)
return 0;
if (index < 9 &&
(reg & 03) != 0x01 && (reg & 0x03) != 0x02)
return 0;
if (index >= 9 && index < 18 &&
(reg & 0x0c) != 0x04 && (reg & 0x0c) != 0x08)
return 0;
if (index >= 18 && index < 27 && (reg & 0x30) != 0x10)
return 0;
if (index >= 27 && index < 35)
return attr->mode;
err = regmap_read(data->regmap, REG_PECI_ENABLE, &reg);
if (err < 0)
return 0;
if (index >= 35 && index < 43 && !(reg & 0x01))
return 0;
if (index >= 0x43 && (!(reg & 0x02)))
return 0;
return attr->mode;
}
static umode_t nct7802_in_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct7802_data *data = dev_get_drvdata(dev);
unsigned int reg;
int err;
if (index < 6)
return attr->mode;
err = regmap_read(data->regmap, REG_MODE, &reg);
if (err < 0)
return 0;
if (index >= 6 && index < 11 && (reg & 0x03) != 0x03)
return 0;
if (index >= 11 && index < 17 && (reg & 0x0c) != 0x0c)
return 0;
if (index >= 17 && (reg & 0x30) != 0x30)
return 0;
return attr->mode;
}
static umode_t nct7802_fan_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct7802_data *data = dev_get_drvdata(dev);
int fan = index / 4;
unsigned int reg;
int err;
err = regmap_read(data->regmap, REG_FAN_ENABLE, &reg);
if (err < 0 || !(reg & (1 << fan)))
return 0;
return attr->mode;
}
static int nct7802_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
int reg;
reg = i2c_smbus_read_byte_data(client, REG_BANK);
if (reg != 0x00)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, REG_VENDOR_ID);
if (reg != 0x50)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, REG_CHIP_ID);
if (reg != 0xc3)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, REG_VERSION_ID);
if (reg < 0 || (reg & 0xf0) != 0x20)
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, REG_TEMP_LSB);
if (reg < 0 || (reg & 0x1f))
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, REG_TEMP_PECI_LSB);
if (reg < 0 || (reg & 0x3f))
return -ENODEV;
reg = i2c_smbus_read_byte_data(client, REG_VOLTAGE_LOW);
if (reg < 0 || (reg & 0x3f))
return -ENODEV;
strlcpy(info->type, "nct7802", I2C_NAME_SIZE);
return 0;
}
static bool nct7802_regmap_is_volatile(struct device *dev, unsigned int reg)
{
return reg != REG_BANK && reg <= 0x20;
}
static int nct7802_init_chip(struct nct7802_data *data)
{
int err;
err = regmap_update_bits(data->regmap, REG_START, 0x01, 0x01);
if (err)
return err;
err = regmap_update_bits(data->regmap, REG_MODE, 0x40, 0x40);
if (err)
return err;
return regmap_update_bits(data->regmap, REG_VMON_ENABLE, 0x03, 0x03);
}
static int nct7802_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct nct7802_data *data;
struct device *hwmon_dev;
int ret;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
data->regmap = devm_regmap_init_i2c(client, &nct7802_regmap_config);
if (IS_ERR(data->regmap))
return PTR_ERR(data->regmap);
mutex_init(&data->access_lock);
ret = nct7802_init_chip(data);
if (ret < 0)
return ret;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
nct7802_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
