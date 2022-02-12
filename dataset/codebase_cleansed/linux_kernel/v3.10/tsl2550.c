static int tsl2550_set_operating_mode(struct i2c_client *client, int mode)
{
struct tsl2550_data *data = i2c_get_clientdata(client);
int ret = i2c_smbus_write_byte(client, TSL2550_MODE_RANGE[mode]);
data->operating_mode = mode;
return ret;
}
static int tsl2550_set_power_state(struct i2c_client *client, int state)
{
struct tsl2550_data *data = i2c_get_clientdata(client);
int ret;
if (state == 0)
ret = i2c_smbus_write_byte(client, TSL2550_POWER_DOWN);
else {
ret = i2c_smbus_write_byte(client, TSL2550_POWER_UP);
tsl2550_set_operating_mode(client, data->operating_mode);
}
data->power_state = state;
return ret;
}
static int tsl2550_get_adc_value(struct i2c_client *client, u8 cmd)
{
int ret;
ret = i2c_smbus_read_byte_data(client, cmd);
if (ret < 0)
return ret;
if (!(ret & 0x80))
return -EAGAIN;
return ret & 0x7f;
}
static int tsl2550_calculate_lux(u8 ch0, u8 ch1)
{
unsigned int lux;
u16 c0 = count_lut[ch0];
u16 c1 = count_lut[ch1];
u8 r = 128;
if (c1 <= c0)
if (c0) {
r = c1 * 128 / c0;
lux = ((c0 - c1) * ratio_lut[r]) / 256;
} else
lux = 0;
else
return -EAGAIN;
return lux > TSL2550_MAX_LUX ? TSL2550_MAX_LUX : lux;
}
static ssize_t tsl2550_show_power_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2550_data *data = i2c_get_clientdata(to_i2c_client(dev));
return sprintf(buf, "%u\n", data->power_state);
}
static ssize_t tsl2550_store_power_state(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct tsl2550_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtoul(buf, NULL, 10);
int ret;
if (val < 0 || val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
ret = tsl2550_set_power_state(client, val);
mutex_unlock(&data->update_lock);
if (ret < 0)
return ret;
return count;
}
static ssize_t tsl2550_show_operating_mode(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct tsl2550_data *data = i2c_get_clientdata(to_i2c_client(dev));
return sprintf(buf, "%u\n", data->operating_mode);
}
static ssize_t tsl2550_store_operating_mode(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct tsl2550_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtoul(buf, NULL, 10);
int ret;
if (val < 0 || val > 1)
return -EINVAL;
if (data->power_state == 0)
return -EBUSY;
mutex_lock(&data->update_lock);
ret = tsl2550_set_operating_mode(client, val);
mutex_unlock(&data->update_lock);
if (ret < 0)
return ret;
return count;
}
static ssize_t __tsl2550_show_lux(struct i2c_client *client, char *buf)
{
struct tsl2550_data *data = i2c_get_clientdata(client);
u8 ch0, ch1;
int ret;
ret = tsl2550_get_adc_value(client, TSL2550_READ_ADC0);
if (ret < 0)
return ret;
ch0 = ret;
ret = tsl2550_get_adc_value(client, TSL2550_READ_ADC1);
if (ret < 0)
return ret;
ch1 = ret;
ret = tsl2550_calculate_lux(ch0, ch1);
if (ret < 0)
return ret;
if (data->operating_mode == 1)
ret *= 5;
return sprintf(buf, "%d\n", ret);
}
static ssize_t tsl2550_show_lux1_input(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct tsl2550_data *data = i2c_get_clientdata(client);
int ret;
if (!data->power_state)
return -EBUSY;
mutex_lock(&data->update_lock);
ret = __tsl2550_show_lux(client, buf);
mutex_unlock(&data->update_lock);
return ret;
}
static int tsl2550_init_client(struct i2c_client *client)
{
struct tsl2550_data *data = i2c_get_clientdata(client);
int err;
err = i2c_smbus_read_byte_data(client, TSL2550_POWER_UP);
if (err < 0)
return err;
if (err != TSL2550_POWER_UP)
return -ENODEV;
data->power_state = 1;
err = i2c_smbus_write_byte(client,
TSL2550_MODE_RANGE[data->operating_mode]);
if (err < 0)
return err;
return 0;
}
static int tsl2550_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct tsl2550_data *data;
int *opmode, err = 0;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_WRITE_BYTE
| I2C_FUNC_SMBUS_READ_BYTE_DATA)) {
err = -EIO;
goto exit;
}
data = kzalloc(sizeof(struct tsl2550_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
data->client = client;
i2c_set_clientdata(client, data);
opmode = client->dev.platform_data;
if (opmode) {
if (*opmode < 0 || *opmode > 1) {
dev_err(&client->dev, "invalid operating_mode (%d)\n",
*opmode);
err = -EINVAL;
goto exit_kfree;
}
data->operating_mode = *opmode;
} else
data->operating_mode = 0;
dev_info(&client->dev, "%s operating mode\n",
data->operating_mode ? "extended" : "standard");
mutex_init(&data->update_lock);
err = tsl2550_init_client(client);
if (err)
goto exit_kfree;
err = sysfs_create_group(&client->dev.kobj, &tsl2550_attr_group);
if (err)
goto exit_kfree;
dev_info(&client->dev, "support ver. %s enabled\n", DRIVER_VERSION);
return 0;
exit_kfree:
kfree(data);
exit:
return err;
}
static int tsl2550_remove(struct i2c_client *client)
{
sysfs_remove_group(&client->dev.kobj, &tsl2550_attr_group);
tsl2550_set_power_state(client, 0);
kfree(i2c_get_clientdata(client));
return 0;
}
static int tsl2550_suspend(struct device *dev)
{
return tsl2550_set_power_state(to_i2c_client(dev), 0);
}
static int tsl2550_resume(struct device *dev)
{
return tsl2550_set_power_state(to_i2c_client(dev), 1);
}
