static int __isl29003_read_reg(struct i2c_client *client,
u32 reg, u8 mask, u8 shift)
{
struct isl29003_data *data = i2c_get_clientdata(client);
return (data->reg_cache[reg] & mask) >> shift;
}
static int __isl29003_write_reg(struct i2c_client *client,
u32 reg, u8 mask, u8 shift, u8 val)
{
struct isl29003_data *data = i2c_get_clientdata(client);
int ret = 0;
u8 tmp;
if (reg >= ISL29003_NUM_CACHABLE_REGS)
return -EINVAL;
mutex_lock(&data->lock);
tmp = data->reg_cache[reg];
tmp &= ~mask;
tmp |= val << shift;
ret = i2c_smbus_write_byte_data(client, reg, tmp);
if (!ret)
data->reg_cache[reg] = tmp;
mutex_unlock(&data->lock);
return ret;
}
static int isl29003_get_range(struct i2c_client *client)
{
return __isl29003_read_reg(client, ISL29003_REG_CONTROL,
ISL29003_RANGE_MASK, ISL29003_RANGE_SHIFT);
}
static int isl29003_set_range(struct i2c_client *client, int range)
{
return __isl29003_write_reg(client, ISL29003_REG_CONTROL,
ISL29003_RANGE_MASK, ISL29003_RANGE_SHIFT, range);
}
static int isl29003_get_resolution(struct i2c_client *client)
{
return __isl29003_read_reg(client, ISL29003_REG_COMMAND,
ISL29003_RES_MASK, ISL29003_RES_SHIFT);
}
static int isl29003_set_resolution(struct i2c_client *client, int res)
{
return __isl29003_write_reg(client, ISL29003_REG_COMMAND,
ISL29003_RES_MASK, ISL29003_RES_SHIFT, res);
}
static int isl29003_get_mode(struct i2c_client *client)
{
return __isl29003_read_reg(client, ISL29003_REG_COMMAND,
ISL29003_RES_MASK, ISL29003_RES_SHIFT);
}
static int isl29003_set_mode(struct i2c_client *client, int mode)
{
return __isl29003_write_reg(client, ISL29003_REG_COMMAND,
ISL29003_RES_MASK, ISL29003_RES_SHIFT, mode);
}
static int isl29003_set_power_state(struct i2c_client *client, int state)
{
return __isl29003_write_reg(client, ISL29003_REG_COMMAND,
ISL29003_ADC_ENABLED | ISL29003_ADC_PD, 0,
state ? ISL29003_ADC_ENABLED : ISL29003_ADC_PD);
}
static int isl29003_get_power_state(struct i2c_client *client)
{
struct isl29003_data *data = i2c_get_clientdata(client);
u8 cmdreg = data->reg_cache[ISL29003_REG_COMMAND];
return ~cmdreg & ISL29003_ADC_PD;
}
static int isl29003_get_adc_value(struct i2c_client *client)
{
struct isl29003_data *data = i2c_get_clientdata(client);
int lsb, msb, range, bitdepth;
mutex_lock(&data->lock);
lsb = i2c_smbus_read_byte_data(client, ISL29003_REG_LSB_SENSOR);
if (lsb < 0) {
mutex_unlock(&data->lock);
return lsb;
}
msb = i2c_smbus_read_byte_data(client, ISL29003_REG_MSB_SENSOR);
mutex_unlock(&data->lock);
if (msb < 0)
return msb;
range = isl29003_get_range(client);
bitdepth = (4 - isl29003_get_resolution(client)) * 4;
return (((msb << 8) | lsb) * gain_range[range]) >> bitdepth;
}
static ssize_t isl29003_show_range(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
return sprintf(buf, "%i\n", isl29003_get_range(client));
}
static ssize_t isl29003_store_range(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val > 3)
return -EINVAL;
ret = isl29003_set_range(client, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t isl29003_show_resolution(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
return sprintf(buf, "%d\n", isl29003_get_resolution(client));
}
static ssize_t isl29003_store_resolution(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val > 3)
return -EINVAL;
ret = isl29003_set_resolution(client, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t isl29003_show_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
return sprintf(buf, "%d\n", isl29003_get_mode(client));
}
static ssize_t isl29003_store_mode(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val > 2)
return -EINVAL;
ret = isl29003_set_mode(client, val);
if (ret < 0)
return ret;
return count;
}
static ssize_t isl29003_show_power_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
return sprintf(buf, "%d\n", isl29003_get_power_state(client));
}
static ssize_t isl29003_store_power_state(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
if (val > 1)
return -EINVAL;
ret = isl29003_set_power_state(client, val);
return ret ? ret : count;
}
static ssize_t isl29003_show_lux(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
if (!isl29003_get_power_state(client))
return -EBUSY;
return sprintf(buf, "%d\n", isl29003_get_adc_value(client));
}
static int isl29003_init_client(struct i2c_client *client)
{
struct isl29003_data *data = i2c_get_clientdata(client);
int i;
for (i = 0; i < ARRAY_SIZE(data->reg_cache); i++) {
int v = i2c_smbus_read_byte_data(client, i);
if (v < 0)
return -ENODEV;
data->reg_cache[i] = v;
}
isl29003_set_range(client, 0);
isl29003_set_resolution(client, 0);
isl29003_set_mode(client, 0);
isl29003_set_power_state(client, 0);
return 0;
}
static int isl29003_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct isl29003_data *data;
int err = 0;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE))
return -EIO;
data = kzalloc(sizeof(struct isl29003_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
err = isl29003_init_client(client);
if (err)
goto exit_kfree;
err = sysfs_create_group(&client->dev.kobj, &isl29003_attr_group);
if (err)
goto exit_kfree;
dev_info(&client->dev, "driver version %s enabled\n", DRIVER_VERSION);
return 0;
exit_kfree:
kfree(data);
return err;
}
static int isl29003_remove(struct i2c_client *client)
{
sysfs_remove_group(&client->dev.kobj, &isl29003_attr_group);
isl29003_set_power_state(client, 0);
kfree(i2c_get_clientdata(client));
return 0;
}
static int isl29003_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct isl29003_data *data = i2c_get_clientdata(client);
data->power_state_before_suspend = isl29003_get_power_state(client);
return isl29003_set_power_state(client, 0);
}
static int isl29003_resume(struct device *dev)
{
int i;
struct i2c_client *client = to_i2c_client(dev);
struct isl29003_data *data = i2c_get_clientdata(client);
for (i = 0; i < ARRAY_SIZE(data->reg_cache); i++)
if (i2c_smbus_write_byte_data(client, i, data->reg_cache[i]))
return -EIO;
return isl29003_set_power_state(client,
data->power_state_before_suspend);
}
