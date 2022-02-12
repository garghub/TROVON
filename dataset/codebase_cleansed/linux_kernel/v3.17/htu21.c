static inline int htu21_temp_ticks_to_millicelsius(int ticks)
{
ticks &= ~0x0003;
return ((21965 * ticks) >> 13) - 46850;
}
static inline int htu21_rh_ticks_to_per_cent_mille(int ticks)
{
ticks &= ~0x0003;
return ((15625 * ticks) >> 13) - 6000;
}
static int htu21_update_measurements(struct device *dev)
{
struct htu21 *htu21 = dev_get_drvdata(dev);
struct i2c_client *client = htu21->client;
int ret = 0;
mutex_lock(&htu21->lock);
if (time_after(jiffies, htu21->last_update + HZ / 2) ||
!htu21->valid) {
ret = i2c_smbus_read_word_swapped(client,
HTU21_T_MEASUREMENT_HM);
if (ret < 0)
goto out;
htu21->temperature = htu21_temp_ticks_to_millicelsius(ret);
ret = i2c_smbus_read_word_swapped(client,
HTU21_RH_MEASUREMENT_HM);
if (ret < 0)
goto out;
htu21->humidity = htu21_rh_ticks_to_per_cent_mille(ret);
htu21->last_update = jiffies;
htu21->valid = true;
}
out:
mutex_unlock(&htu21->lock);
return ret >= 0 ? 0 : ret;
}
static ssize_t htu21_show_temperature(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct htu21 *htu21 = dev_get_drvdata(dev);
int ret;
ret = htu21_update_measurements(dev);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", htu21->temperature);
}
static ssize_t htu21_show_humidity(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct htu21 *htu21 = dev_get_drvdata(dev);
int ret;
ret = htu21_update_measurements(dev);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", htu21->humidity);
}
static int htu21_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct htu21 *htu21;
struct device *hwmon_dev;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA)) {
dev_err(&client->dev,
"adapter does not support SMBus word transactions\n");
return -ENODEV;
}
htu21 = devm_kzalloc(dev, sizeof(*htu21), GFP_KERNEL);
if (!htu21)
return -ENOMEM;
htu21->client = client;
mutex_init(&htu21->lock);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
htu21,
htu21_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
