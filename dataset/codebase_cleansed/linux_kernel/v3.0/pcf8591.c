static ssize_t show_out0_ouput(struct device *dev, struct device_attribute *attr, char *buf)
{
struct pcf8591_data *data = i2c_get_clientdata(to_i2c_client(dev));
return sprintf(buf, "%d\n", data->aout * 10);
}
static ssize_t set_out0_output(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
unsigned int value;
struct i2c_client *client = to_i2c_client(dev);
struct pcf8591_data *data = i2c_get_clientdata(client);
if ((value = (simple_strtoul(buf, NULL, 10) + 5) / 10) <= 255) {
data->aout = value;
i2c_smbus_write_byte_data(client, data->control, data->aout);
return count;
}
return -EINVAL;
}
static ssize_t show_out0_enable(struct device *dev, struct device_attribute *attr, char *buf)
{
struct pcf8591_data *data = i2c_get_clientdata(to_i2c_client(dev));
return sprintf(buf, "%u\n", !(!(data->control & PCF8591_CONTROL_AOEF)));
}
static ssize_t set_out0_enable(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct pcf8591_data *data = i2c_get_clientdata(client);
unsigned long val = simple_strtoul(buf, NULL, 10);
mutex_lock(&data->update_lock);
if (val)
data->control |= PCF8591_CONTROL_AOEF;
else
data->control &= ~PCF8591_CONTROL_AOEF;
i2c_smbus_write_byte(client, data->control);
mutex_unlock(&data->update_lock);
return count;
}
static int pcf8591_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pcf8591_data *data;
int err;
if (!(data = kzalloc(sizeof(struct pcf8591_data), GFP_KERNEL))) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
pcf8591_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &pcf8591_attr_group);
if (err)
goto exit_kfree;
if (input_mode != 3) {
if ((err = device_create_file(&client->dev,
&dev_attr_in2_input)))
goto exit_sysfs_remove;
}
if (input_mode == 0) {
if ((err = device_create_file(&client->dev,
&dev_attr_in3_input)))
goto exit_sysfs_remove;
}
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_sysfs_remove;
}
return 0;
exit_sysfs_remove:
sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group_opt);
sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group);
exit_kfree:
kfree(data);
exit:
return err;
}
static int pcf8591_remove(struct i2c_client *client)
{
struct pcf8591_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group_opt);
sysfs_remove_group(&client->dev.kobj, &pcf8591_attr_group);
kfree(i2c_get_clientdata(client));
return 0;
}
static void pcf8591_init_client(struct i2c_client *client)
{
struct pcf8591_data *data = i2c_get_clientdata(client);
data->control = PCF8591_INIT_CONTROL;
data->aout = PCF8591_INIT_AOUT;
i2c_smbus_write_byte_data(client, data->control, data->aout);
i2c_smbus_read_byte(client);
}
static int pcf8591_read_channel(struct device *dev, int channel)
{
u8 value;
struct i2c_client *client = to_i2c_client(dev);
struct pcf8591_data *data = i2c_get_clientdata(client);
mutex_lock(&data->update_lock);
if ((data->control & PCF8591_CONTROL_AICH_MASK) != channel) {
data->control = (data->control & ~PCF8591_CONTROL_AICH_MASK)
| channel;
i2c_smbus_write_byte(client, data->control);
i2c_smbus_read_byte(client);
}
value = i2c_smbus_read_byte(client);
mutex_unlock(&data->update_lock);
if ((channel == 2 && input_mode == 2) ||
(channel != 3 && (input_mode == 1 || input_mode == 3)))
return (10 * REG_TO_SIGNED(value));
else
return (10 * value);
}
static int __init pcf8591_init(void)
{
if (input_mode < 0 || input_mode > 3) {
pr_warn("invalid input_mode (%d)\n", input_mode);
input_mode = 0;
}
return i2c_add_driver(&pcf8591_driver);
}
static void __exit pcf8591_exit(void)
{
i2c_del_driver(&pcf8591_driver);
}
