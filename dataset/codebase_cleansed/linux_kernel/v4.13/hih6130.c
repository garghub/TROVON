static inline int hih6130_temp_ticks_to_millicelsius(int ticks)
{
ticks = ticks >> 2;
return (DIV_ROUND_CLOSEST(ticks * 1650, 16382) - 400) * 100;
}
static inline int hih6130_rh_ticks_to_per_cent_mille(int ticks)
{
ticks &= ~0xC000;
return DIV_ROUND_CLOSEST(ticks * 1000, 16382) * 100;
}
static int hih6130_update_measurements(struct device *dev)
{
struct hih6130 *hih6130 = dev_get_drvdata(dev);
struct i2c_client *client = hih6130->client;
int ret = 0;
int t;
unsigned char tmp[4];
struct i2c_msg msgs[1] = {
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = 4,
.buf = tmp,
}
};
mutex_lock(&hih6130->lock);
if (time_after(jiffies, hih6130->last_update + HZ) || !hih6130->valid) {
tmp[0] = 0;
ret = i2c_master_send(client, tmp, hih6130->write_length);
if (ret < 0)
goto out;
msleep(40);
ret = i2c_transfer(client->adapter, msgs, 1);
if (ret < 0)
goto out;
if ((tmp[0] & 0xC0) != 0) {
dev_err(&client->dev, "Error while reading measurement result\n");
ret = -EIO;
goto out;
}
t = (tmp[0] << 8) + tmp[1];
hih6130->humidity = hih6130_rh_ticks_to_per_cent_mille(t);
t = (tmp[2] << 8) + tmp[3];
hih6130->temperature = hih6130_temp_ticks_to_millicelsius(t);
hih6130->last_update = jiffies;
hih6130->valid = true;
}
out:
mutex_unlock(&hih6130->lock);
return ret >= 0 ? 0 : ret;
}
static ssize_t hih6130_show_temperature(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hih6130 *hih6130 = dev_get_drvdata(dev);
int ret;
ret = hih6130_update_measurements(dev);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", hih6130->temperature);
}
static ssize_t hih6130_show_humidity(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct hih6130 *hih6130 = dev_get_drvdata(dev);
int ret;
ret = hih6130_update_measurements(dev);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n", hih6130->humidity);
}
static int hih6130_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct hih6130 *hih6130;
struct device *hwmon_dev;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "adapter does not support true I2C\n");
return -ENODEV;
}
hih6130 = devm_kzalloc(dev, sizeof(*hih6130), GFP_KERNEL);
if (!hih6130)
return -ENOMEM;
hih6130->client = client;
mutex_init(&hih6130->lock);
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_QUICK))
hih6130->write_length = 1;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
hih6130,
hih6130_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
