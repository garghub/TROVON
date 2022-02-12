static inline int tmp102_reg_to_mC(s16 val)
{
return ((val & ~0x01) * 1000) / 128;
}
static inline u16 tmp102_mC_to_reg(int val)
{
return (val * 128) / 1000;
}
static struct tmp102 *tmp102_update_device(struct device *dev)
{
struct tmp102 *tmp102 = dev_get_drvdata(dev);
struct i2c_client *client = tmp102->client;
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
tmp102->first_time = false;
}
mutex_unlock(&tmp102->lock);
return tmp102;
}
static int tmp102_read_temp(void *dev, int *temp)
{
struct tmp102 *tmp102 = tmp102_update_device(dev);
if (tmp102->first_time) {
dev_dbg(dev, "%s: Conversion not ready yet..\n", __func__);
return -EAGAIN;
}
*temp = tmp102->temp[0];
return 0;
}
static ssize_t tmp102_show_temp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct tmp102 *tmp102 = tmp102_update_device(dev);
if (tmp102->first_time)
return -EAGAIN;
return sprintf(buf, "%d\n", tmp102->temp[sda->index]);
}
static ssize_t tmp102_set_temp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sda = to_sensor_dev_attr(attr);
struct tmp102 *tmp102 = dev_get_drvdata(dev);
struct i2c_client *client = tmp102->client;
long val;
int status;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
val = clamp_val(val, -256000, 255000);
mutex_lock(&tmp102->lock);
tmp102->temp[sda->index] = val;
status = i2c_smbus_write_word_swapped(client, tmp102_reg[sda->index],
tmp102_mC_to_reg(val));
mutex_unlock(&tmp102->lock);
return status ? : count;
}
static int tmp102_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct tmp102 *tmp102;
int status;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(dev,
"adapter doesn't support SMBus word transactions\n");
return -ENODEV;
}
tmp102 = devm_kzalloc(dev, sizeof(*tmp102), GFP_KERNEL);
if (!tmp102)
return -ENOMEM;
i2c_set_clientdata(client, tmp102);
tmp102->client = client;
status = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (status < 0) {
dev_err(dev, "error reading config register\n");
return status;
}
tmp102->config_orig = status;
status = i2c_smbus_write_word_swapped(client, TMP102_CONF_REG,
TMP102_CONFIG);
if (status < 0) {
dev_err(dev, "error writing config register\n");
goto fail_restore_config;
}
status = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (status < 0) {
dev_err(dev, "error reading config register\n");
goto fail_restore_config;
}
status &= ~TMP102_CONFIG_RD_ONLY;
if (status != TMP102_CONFIG) {
dev_err(dev, "config settings did not stick\n");
status = -ENODEV;
goto fail_restore_config;
}
tmp102->last_update = jiffies;
tmp102->first_time = true;
mutex_init(&tmp102->lock);
hwmon_dev = hwmon_device_register_with_groups(dev, client->name,
tmp102, tmp102_groups);
if (IS_ERR(hwmon_dev)) {
dev_dbg(dev, "unable to register hwmon device\n");
status = PTR_ERR(hwmon_dev);
goto fail_restore_config;
}
tmp102->hwmon_dev = hwmon_dev;
devm_thermal_zone_of_sensor_register(hwmon_dev, 0, hwmon_dev,
&tmp102_of_thermal_ops);
dev_info(dev, "initialized\n");
return 0;
fail_restore_config:
i2c_smbus_write_word_swapped(client, TMP102_CONF_REG,
tmp102->config_orig);
return status;
}
static int tmp102_remove(struct i2c_client *client)
{
struct tmp102 *tmp102 = i2c_get_clientdata(client);
hwmon_device_unregister(tmp102->hwmon_dev);
if (tmp102->config_orig & TMP102_CONF_SD) {
int config;
config = i2c_smbus_read_word_swapped(client, TMP102_CONF_REG);
if (config >= 0)
i2c_smbus_write_word_swapped(client, TMP102_CONF_REG,
config | TMP102_CONF_SD);
}
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
