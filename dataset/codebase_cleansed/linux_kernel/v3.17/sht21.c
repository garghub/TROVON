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
static int sht21_update_measurements(struct device *dev)
{
int ret = 0;
struct sht21 *sht21 = dev_get_drvdata(dev);
struct i2c_client *client = sht21->client;
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
struct sht21 *sht21 = dev_get_drvdata(dev);
int ret;
ret = sht21_update_measurements(dev);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", sht21->temperature);
}
static ssize_t sht21_show_humidity(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct sht21 *sht21 = dev_get_drvdata(dev);
int ret;
ret = sht21_update_measurements(dev);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", sht21->humidity);
}
static int sht21_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device *hwmon_dev;
struct sht21 *sht21;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WORD_DATA)) {
dev_err(&client->dev,
"adapter does not support SMBus word transactions\n");
return -ENODEV;
}
sht21 = devm_kzalloc(dev, sizeof(*sht21), GFP_KERNEL);
if (!sht21)
return -ENOMEM;
sht21->client = client;
mutex_init(&sht21->lock);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
sht21, sht21_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
