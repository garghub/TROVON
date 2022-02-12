static inline unsigned int rpm_from_cnt(u8 val, u32 clk, u16 div)
{
return ((val == 0x00) ? 0 : ((clk*30)/(val*div)));
}
static int g760a_read_value(struct i2c_client *client, enum g760a_regs reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static int g760a_write_value(struct i2c_client *client, enum g760a_regs reg,
u16 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static struct g760a_data *g760a_update_client(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct g760a_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + G760A_UPDATE_INTERVAL)
|| !data->valid) {
dev_dbg(&client->dev, "Starting g760a update\n");
data->set_cnt = g760a_read_value(client, G760A_REG_SET_CNT);
data->act_cnt = g760a_read_value(client, G760A_REG_ACT_CNT);
data->fan_sta = g760a_read_value(client, G760A_REG_FAN_STA);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g760a_data *data = g760a_update_client(dev);
unsigned int rpm = 0;
mutex_lock(&data->update_lock);
if (!(data->fan_sta & G760A_REG_FAN_STA_RPM_LOW))
rpm = rpm_from_cnt(data->act_cnt, data->clk, data->fan_div);
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", rpm);
}
static ssize_t show_fan_alarm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g760a_data *data = g760a_update_client(dev);
int fan_alarm = (data->fan_sta & G760A_REG_FAN_STA_RPM_OFF) ? 1 : 0;
return sprintf(buf, "%d\n", fan_alarm);
}
static ssize_t get_pwm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct g760a_data *data = g760a_update_client(dev);
return sprintf(buf, "%d\n", PWM_FROM_CNT(data->set_cnt));
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct g760a_data *data = g760a_update_client(dev);
unsigned long val;
if (strict_strtoul(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->update_lock);
data->set_cnt = PWM_TO_CNT(SENSORS_LIMIT(val, 0, 255));
g760a_write_value(client, G760A_REG_SET_CNT, data->set_cnt);
mutex_unlock(&data->update_lock);
return count;
}
static int g760a_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct g760a_data *data;
int err;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
data = kzalloc(sizeof(struct g760a_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->client = client;
mutex_init(&data->update_lock);
data->fan_div = G760A_DEFAULT_FAN_DIV;
data->clk = G760A_DEFAULT_CLK;
err = sysfs_create_group(&client->dev.kobj, &g760a_group);
if (err)
goto error_sysfs_create_group;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error_hwmon_device_register;
}
return 0;
error_hwmon_device_register:
sysfs_remove_group(&client->dev.kobj, &g760a_group);
error_sysfs_create_group:
kfree(data);
return err;
}
static int g760a_remove(struct i2c_client *client)
{
struct g760a_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &g760a_group);
kfree(data);
return 0;
}
static int __init g760a_init(void)
{
return i2c_add_driver(&g760a_driver);
}
static void __exit g760a_exit(void)
{
i2c_del_driver(&g760a_driver);
}
