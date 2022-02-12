static inline int DS1621_TEMP_FROM_REG(u16 reg)
{
return DIV_ROUND_CLOSEST(((s16)reg / 16) * 625, 10);
}
static inline u16 DS1621_TEMP_TO_REG(long temp, u8 zbits)
{
temp = clamp_val(temp, DS1621_TEMP_MIN, DS1621_TEMP_MAX);
temp = DIV_ROUND_CLOSEST(temp * (1 << (8 - zbits)), 1000) << zbits;
return temp;
}
static void ds1621_init_client(struct i2c_client *client)
{
u8 conf, new_conf, sreg, resol;
struct ds1621_data *data = i2c_get_clientdata(client);
new_conf = conf = i2c_smbus_read_byte_data(client, DS1621_REG_CONF);
new_conf &= ~DS1621_REG_CONFIG_1SHOT;
if (polarity == 0)
new_conf &= ~DS1621_REG_CONFIG_POLARITY;
else if (polarity == 1)
new_conf |= DS1621_REG_CONFIG_POLARITY;
if (conf != new_conf)
i2c_smbus_write_byte_data(client, DS1621_REG_CONF, new_conf);
switch (data->kind) {
case ds1625:
data->update_interval = DS1625_CONVERSION_MAX;
data->zbits = 7;
sreg = DS1621_COM_START;
break;
case ds1631:
case ds1721:
case ds1731:
resol = (new_conf & DS1621_REG_CONFIG_RESOL) >>
DS1621_REG_CONFIG_RESOL_SHIFT;
data->update_interval = ds1721_convrates[resol];
data->zbits = 7 - resol;
sreg = DS1721_COM_START;
break;
default:
data->update_interval = DS1621_CONVERSION_MAX;
data->zbits = 7;
sreg = DS1621_COM_START;
break;
}
i2c_smbus_write_byte(client, sreg);
}
static struct ds1621_data *ds1621_update_client(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds1621_data *data = i2c_get_clientdata(client);
u8 new_conf;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + data->update_interval) ||
!data->valid) {
int i;
dev_dbg(&client->dev, "Starting ds1621 update\n");
data->conf = i2c_smbus_read_byte_data(client, DS1621_REG_CONF);
for (i = 0; i < ARRAY_SIZE(data->temp); i++)
data->temp[i] = i2c_smbus_read_word_swapped(client,
DS1621_REG_TEMP[i]);
new_conf = data->conf;
if (data->temp[0] > data->temp[1])
new_conf &= ~DS1621_ALARM_TEMP_LOW;
if (data->temp[0] < data->temp[2])
new_conf &= ~DS1621_ALARM_TEMP_HIGH;
if (data->conf != new_conf)
i2c_smbus_write_byte_data(client, DS1621_REG_CONF,
new_conf);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ds1621_data *data = ds1621_update_client(dev);
return sprintf(buf, "%d\n",
DS1621_TEMP_FROM_REG(data->temp[attr->index]));
}
static ssize_t set_temp(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct i2c_client *client = to_i2c_client(dev);
struct ds1621_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp[attr->index] = DS1621_TEMP_TO_REG(val, data->zbits);
i2c_smbus_write_word_swapped(client, DS1621_REG_TEMP[attr->index],
data->temp[attr->index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *da,
char *buf)
{
struct ds1621_data *data = ds1621_update_client(dev);
return sprintf(buf, "%d\n", ALARMS_FROM_REG(data->conf));
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ds1621_data *data = ds1621_update_client(dev);
return sprintf(buf, "%d\n", !!(data->conf & attr->index));
}
static ssize_t show_convrate(struct device *dev, struct device_attribute *da,
char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds1621_data *data = i2c_get_clientdata(client);
return scnprintf(buf, PAGE_SIZE, "%hu\n", data->update_interval);
}
static ssize_t set_convrate(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct ds1621_data *data = i2c_get_clientdata(client);
unsigned long convrate;
s32 err;
int resol = 0;
err = kstrtoul(buf, 10, &convrate);
if (err)
return err;
while (resol < (ARRAY_SIZE(ds1721_convrates) - 1) &&
convrate > ds1721_convrates[resol])
resol++;
mutex_lock(&data->update_lock);
data->conf = i2c_smbus_read_byte_data(client, DS1621_REG_CONF);
data->conf &= ~DS1621_REG_CONFIG_RESOL;
data->conf |= (resol << DS1621_REG_CONFIG_RESOL_SHIFT);
i2c_smbus_write_byte_data(client, DS1621_REG_CONF, data->conf);
data->update_interval = ds1721_convrates[resol];
mutex_unlock(&data->update_lock);
return count;
}
static umode_t ds1621_attribute_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct i2c_client *client = to_i2c_client(dev);
struct ds1621_data *data = i2c_get_clientdata(client);
if (attr == &dev_attr_update_interval.attr)
if (data->kind == ds1621 || data->kind == ds1625)
return 0;
return attr->mode;
}
static int ds1621_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds1621_data *data;
int err;
data = devm_kzalloc(&client->dev, sizeof(struct ds1621_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->kind = id->driver_data;
ds1621_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &ds1621_group);
if (err)
return err;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&client->dev.kobj, &ds1621_group);
return err;
}
static int ds1621_remove(struct i2c_client *client)
{
struct ds1621_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &ds1621_group);
return 0;
}
