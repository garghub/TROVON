static inline int sht21_temp_ticks_to_millicelsius(int ticks)
{
ticks &= ~0x0003;
return ((21965 * ticks) >> 13) - 46850;
}
static inline int sht21_rh_ticks_to_per_cent_mille(int ticks)
{
ticks &= ~0x0003;
return ((15625 * ticks) >> 13) - 6000;
}
static int sht21_update_measurements(struct i2c_client *client)
{
int ret = 0;
struct sht21 *sht21 = i2c_get_clientdata(client);
mutex_lock(&sht21->lock);
if (time_after(jiffies, sht21->last_update + HZ / 2) || !sht21->valid) {
ret = i2c_smbus_read_word_swapped(client,
SHT21_TRIG_T_MEASUREMENT_HM);
if (ret < 0)
goto out;
sht21->temperature = sht21_temp_ticks_to_millicelsius(ret);
ret = i2c_smbus_read_word_swapped(client,
SHT21_TRIG_RH_MEASUREMENT_HM);
if (ret < 0)
goto out;
sht21->humidity = sht21_rh_ticks_to_per_cent_mille(ret);
sht21->last_update = jiffies;
sht21->valid = 1;
}
out:
mutex_unlock(&sht21->lock);
return ret >= 0 ? 0 : ret;
}
static ssize_t sht21_show_temperature(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct sht21 *sht21 = i2c_get_clientdata(client);
int ret = sht21_update_measurements(client);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", sht21->temperature);
}
static ssize_t sht21_show_humidity(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct sht21 *sht21 = i2c_get_clientdata(client);
int ret = sht21_update_measurements(client);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", sht21->humidity);
}
static int __devinit sht21_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sht21 *sht21;
int err;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(&client->dev,
"adapter does not support SMBus word transactions\n");
return -ENODEV;
}
sht21 = devm_kzalloc(&client->dev, sizeof(*sht21), GFP_KERNEL);
if (!sht21)
return -ENOMEM;
i2c_set_clientdata(client, sht21);
mutex_init(&sht21->lock);
err = sysfs_create_group(&client->dev.kobj, &sht21_attr_group);
if (err) {
dev_dbg(&client->dev, "could not create sysfs files\n");
return err;
}
sht21->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(sht21->hwmon_dev)) {
dev_dbg(&client->dev, "unable to register hwmon device\n");
err = PTR_ERR(sht21->hwmon_dev);
goto fail_remove_sysfs;
}
dev_info(&client->dev, "initialized\n");
return 0;
fail_remove_sysfs:
sysfs_remove_group(&client->dev.kobj, &sht21_attr_group);
return err;
}
static int __devexit sht21_remove(struct i2c_client *client)
{
struct sht21 *sht21 = i2c_get_clientdata(client);
hwmon_device_unregister(sht21->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &sht21_attr_group);
return 0;
}
