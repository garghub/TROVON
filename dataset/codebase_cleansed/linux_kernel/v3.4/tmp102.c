static inline int tmp102_reg_to_mC(s16 val)
{
return ((val & ~0x01) * 1000) / 128;
}
static inline u16 tmp102_mC_to_reg(int val)
{
return (val * 128) / 1000;
}
static struct tmp102 *tmp102_update_device(struct i2c_client *client)
{
struct tmp102 *tmp102 = i2c_get_clientdata(client);
mutex_lock(&tmp102->lock);
if (time_after(jiffies, tmp102->last_update + HZ / 3)) {
int i;
for (i = 0; i < ARRAY_SIZE(tmp102->temp); ++i) {
int status = i2c_smbus_read_word_swapped(client,
tmp102_reg[i]);
if (status > -1)
tmp102->temp[i] = tmp102_reg_to_mC(status);
}
tmp102->last_update = jiffies;
}
mutex_unlock(&tmp102->lock);
return tmp102;
}
static ssize_t tmp102_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct tmp102 *tmp102 = tmp102_update_device(to_i2c_client(dev));
return sprintf(buf, "%d\n", tmp102->temp[sda->index]);
}
static ssize_t tmp102_set_temp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct tmp102 *tmp102 = i2c_get_clientdata(client);
long val;
int status;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
val = SENSORS_LIMIT(val, -256000, 255000);
mutex_lock(&tmp102->lock);
tmp102->temp[sda->index] = val;
status = i2c_smbus_write_word_swapped(client, tmp102_reg[sda->index],
tmp102_mC_to_reg(val));
mutex_unlock(&tmp102->lock);
return status ? : count;
}
static int __devinit tmp102_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tmp102 *tmp102;
int status;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(&client->dev, "adapter doesn't support SMBus word "
"transactions\n");
return -ENODEV;
}
tmp102 = kzalloc(sizeof(*tmp102), GFP_KERNEL);
if (!tmp102) {
dev_dbg(&client->dev, "kzalloc failed\n");
return -ENOMEM;
}
i2c_set_clientdata(client, tmp102);
status = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (status < 0) {
dev_err(&client->dev, "error reading config register\n");
goto fail_free;
}
tmp102->config_orig = status;
status = i2c_smbus_write_word_swapped(client, TMP102_CONF_REG,
TMP102_CONFIG);
if (status < 0) {
dev_err(&client->dev, "error writing config register\n");
goto fail_restore_config;
}
status = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (status < 0) {
dev_err(&client->dev, "error reading config register\n");
goto fail_restore_config;
}
status &= ~TMP102_CONFIG_RD_ONLY;
if (status != TMP102_CONFIG) {
dev_err(&client->dev, "config settings did not stick\n");
status = -ENODEV;
goto fail_restore_config;
}
tmp102->last_update = jiffies - HZ;
mutex_init(&tmp102->lock);
status = sysfs_create_group(&client->dev.kobj, &tmp102_attr_group);
if (status) {
dev_dbg(&client->dev, "could not create sysfs files\n");
goto fail_restore_config;
}
tmp102->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(tmp102->hwmon_dev)) {
dev_dbg(&client->dev, "unable to register hwmon device\n");
status = PTR_ERR(tmp102->hwmon_dev);
goto fail_remove_sysfs;
}
dev_info(&client->dev, "initialized\n");
return 0;
fail_remove_sysfs:
sysfs_remove_group(&client->dev.kobj, &tmp102_attr_group);
fail_restore_config:
i2c_smbus_write_word_swapped(client, TMP102_CONF_REG,
tmp102->config_orig);
fail_free:
kfree(tmp102);
return status;
}
static int __devexit tmp102_remove(struct i2c_client *client)
{
struct tmp102 *tmp102 = i2c_get_clientdata(client);
hwmon_device_unregister(tmp102->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &tmp102_attr_group);
if (tmp102->config_orig & TMP102_CONF_SD) {
int config;
config = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (config >= 0)
i2c_smbus_write_word_swapped(client, TMP102_CONF_REG,
config | TMP102_CONF_SD);
}
kfree(tmp102);
return 0;
}
static int tmp102_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int config;
config = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (config < 0)
return config;
config |= TMP102_CONF_SD;
return i2c_smbus_write_word_swapped(client, TMP102_CONF_REG, config);
}
static int tmp102_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
int config;
config = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (config < 0)
return config;
config &= ~TMP102_CONF_SD;
return i2c_smbus_write_word_swapped(client, TMP102_CONF_REG, config);
}
