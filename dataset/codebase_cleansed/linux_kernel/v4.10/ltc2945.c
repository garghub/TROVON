static inline bool is_power_reg(u8 reg)
{
return reg < LTC2945_SENSE_H;
}
static long long ltc2945_reg_to_val(struct device *dev, u8 reg)
{
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int control;
u8 buf[3];
long long val;
int ret;
ret = regmap_bulk_read(regmap, reg, buf,
is_power_reg(reg) ? 3 : 2);
if (ret < 0)
return ret;
if (is_power_reg(reg)) {
val = (buf[0] << 16) + (buf[1] << 8) + buf[2];
} else {
val = (buf[0] << 4) + (buf[1] >> 4);
}
switch (reg) {
case LTC2945_POWER_H:
case LTC2945_MAX_POWER_H:
case LTC2945_MIN_POWER_H:
case LTC2945_MAX_POWER_THRES_H:
case LTC2945_MIN_POWER_THRES_H:
ret = regmap_read(regmap, LTC2945_CONTROL, &control);
if (ret < 0)
return ret;
if (control & CONTROL_MULT_SELECT) {
val *= 625LL;
} else {
val = (val * 25LL) >> 1;
}
break;
case LTC2945_VIN_H:
case LTC2945_MAX_VIN_H:
case LTC2945_MIN_VIN_H:
case LTC2945_MAX_VIN_THRES_H:
case LTC2945_MIN_VIN_THRES_H:
val *= 25;
break;
case LTC2945_ADIN_H:
case LTC2945_MAX_ADIN_H:
case LTC2945_MIN_ADIN_THRES_H:
case LTC2945_MAX_ADIN_THRES_H:
case LTC2945_MIN_ADIN_H:
val = val >> 1;
break;
case LTC2945_SENSE_H:
case LTC2945_MAX_SENSE_H:
case LTC2945_MIN_SENSE_H:
case LTC2945_MAX_SENSE_THRES_H:
case LTC2945_MIN_SENSE_THRES_H:
val *= 25;
break;
default:
return -EINVAL;
}
return val;
}
static int ltc2945_val_to_reg(struct device *dev, u8 reg,
unsigned long val)
{
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int control;
int ret;
switch (reg) {
case LTC2945_POWER_H:
case LTC2945_MAX_POWER_H:
case LTC2945_MIN_POWER_H:
case LTC2945_MAX_POWER_THRES_H:
case LTC2945_MIN_POWER_THRES_H:
ret = regmap_read(regmap, LTC2945_CONTROL, &control);
if (ret < 0)
return ret;
if (control & CONTROL_MULT_SELECT) {
val = DIV_ROUND_CLOSEST(val, 625);
} else {
val = DIV_ROUND_CLOSEST(val, 25) * 2;
}
break;
case LTC2945_VIN_H:
case LTC2945_MAX_VIN_H:
case LTC2945_MIN_VIN_H:
case LTC2945_MAX_VIN_THRES_H:
case LTC2945_MIN_VIN_THRES_H:
val /= 25;
break;
case LTC2945_ADIN_H:
case LTC2945_MAX_ADIN_H:
case LTC2945_MIN_ADIN_THRES_H:
case LTC2945_MAX_ADIN_THRES_H:
case LTC2945_MIN_ADIN_H:
val *= 2;
break;
case LTC2945_SENSE_H:
case LTC2945_MAX_SENSE_H:
case LTC2945_MIN_SENSE_H:
case LTC2945_MAX_SENSE_THRES_H:
case LTC2945_MIN_SENSE_THRES_H:
val = DIV_ROUND_CLOSEST(val, 25);
break;
default:
return -EINVAL;
}
return val;
}
static ssize_t ltc2945_show_value(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
long long value;
value = ltc2945_reg_to_val(dev, attr->index);
if (value < 0)
return value;
return snprintf(buf, PAGE_SIZE, "%lld\n", value);
}
static ssize_t ltc2945_set_value(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct regmap *regmap = dev_get_drvdata(dev);
u8 reg = attr->index;
unsigned long val;
u8 regbuf[3];
int num_regs;
int regval;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
regval = ltc2945_val_to_reg(dev, reg, val);
if (is_power_reg(reg)) {
regval = clamp_val(regval, 0, 0xffffff);
regbuf[0] = regval >> 16;
regbuf[1] = (regval >> 8) & 0xff;
regbuf[2] = regval;
num_regs = 3;
} else {
regval = clamp_val(regval, 0, 0xfff) << 4;
regbuf[0] = regval >> 8;
regbuf[1] = regval & 0xff;
num_regs = 2;
}
ret = regmap_bulk_write(regmap, reg, regbuf, num_regs);
return ret < 0 ? ret : count;
}
static ssize_t ltc2945_reset_history(struct device *dev,
struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct regmap *regmap = dev_get_drvdata(dev);
u8 reg = attr->index;
int num_regs = is_power_reg(reg) ? 3 : 2;
u8 buf_min[3] = { 0xff, 0xff, 0xff };
u8 buf_max[3] = { 0, 0, 0 };
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val != 1)
return -EINVAL;
ret = regmap_update_bits(regmap, LTC2945_CONTROL, CONTROL_TEST_MODE,
CONTROL_TEST_MODE);
ret = regmap_bulk_write(regmap, reg, buf_min, num_regs);
if (ret)
return ret;
switch (reg) {
case LTC2945_MIN_POWER_H:
reg = LTC2945_MAX_POWER_H;
break;
case LTC2945_MIN_SENSE_H:
reg = LTC2945_MAX_SENSE_H;
break;
case LTC2945_MIN_VIN_H:
reg = LTC2945_MAX_VIN_H;
break;
case LTC2945_MIN_ADIN_H:
reg = LTC2945_MAX_ADIN_H;
break;
default:
WARN_ONCE(1, "Bad register: 0x%x\n", reg);
return -EINVAL;
}
ret = regmap_bulk_write(regmap, reg, buf_max, num_regs);
regmap_update_bits(regmap, LTC2945_CONTROL, CONTROL_TEST_MODE, 0);
return ret ? : count;
}
static ssize_t ltc2945_show_bool(struct device *dev,
struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct regmap *regmap = dev_get_drvdata(dev);
unsigned int fault;
int ret;
ret = regmap_read(regmap, LTC2945_FAULT, &fault);
if (ret < 0)
return ret;
fault &= attr->index;
if (fault)
regmap_update_bits(regmap, LTC2945_FAULT, attr->index, 0);
return snprintf(buf, PAGE_SIZE, "%d\n", !!fault);
}
static int ltc2945_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct regmap *regmap;
regmap = devm_regmap_init_i2c(client, &ltc2945_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "failed to allocate register map\n");
return PTR_ERR(regmap);
}
regmap_write(regmap, LTC2945_FAULT, 0x00);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
regmap,
ltc2945_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
