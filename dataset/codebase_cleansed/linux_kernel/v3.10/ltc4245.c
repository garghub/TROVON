static void ltc4245_update_gpios(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ltc4245_data *data = i2c_get_clientdata(client);
u8 gpio_curr, gpio_next, gpio_reg;
int i;
if (!data->use_extra_gpios) {
data->gpios[0] = data->vregs[LTC4245_GPIOADC - 0x10];
return;
}
if (time_after(jiffies, data->last_updated + 5 * HZ)) {
dev_dbg(&client->dev, "Marking GPIOs invalid\n");
for (i = 0; i < ARRAY_SIZE(data->gpios); i++)
data->gpios[i] = -EAGAIN;
}
gpio_curr = (data->cregs[LTC4245_GPIO] & 0xc0) >> 6;
if (gpio_curr > 0)
gpio_curr -= 1;
data->gpios[gpio_curr] = data->vregs[LTC4245_GPIOADC - 0x10];
gpio_next = (gpio_curr + 1) % ARRAY_SIZE(data->gpios);
gpio_reg = (data->cregs[LTC4245_GPIO] & 0x3f) | ((gpio_next + 1) << 6);
i2c_smbus_write_byte_data(client, LTC4245_GPIO, gpio_reg);
data->cregs[LTC4245_GPIO] = gpio_reg;
}
static struct ltc4245_data *ltc4245_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct ltc4245_data *data = i2c_get_clientdata(client);
s32 val;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
dev_dbg(&client->dev, "Starting ltc4245 update\n");
for (i = 0; i < ARRAY_SIZE(data->cregs); i++) {
val = i2c_smbus_read_byte_data(client, i);
if (unlikely(val < 0))
data->cregs[i] = 0;
else
data->cregs[i] = val;
}
for (i = 0; i < ARRAY_SIZE(data->vregs); i++) {
val = i2c_smbus_read_byte_data(client, i+0x10);
if (unlikely(val < 0))
data->vregs[i] = 0;
else
data->vregs[i] = val;
}
ltc4245_update_gpios(dev);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int ltc4245_get_voltage(struct device *dev, u8 reg)
{
struct ltc4245_data *data = ltc4245_update_device(dev);
const u8 regval = data->vregs[reg - 0x10];
u32 voltage = 0;
switch (reg) {
case LTC4245_12VIN:
case LTC4245_12VOUT:
voltage = regval * 55;
break;
case LTC4245_5VIN:
case LTC4245_5VOUT:
voltage = regval * 22;
break;
case LTC4245_3VIN:
case LTC4245_3VOUT:
voltage = regval * 15;
break;
case LTC4245_VEEIN:
case LTC4245_VEEOUT:
voltage = regval * -55;
break;
case LTC4245_GPIOADC:
voltage = regval * 10;
break;
default:
WARN_ON_ONCE(1);
break;
}
return voltage;
}
static unsigned int ltc4245_get_current(struct device *dev, u8 reg)
{
struct ltc4245_data *data = ltc4245_update_device(dev);
const u8 regval = data->vregs[reg - 0x10];
unsigned int voltage;
unsigned int curr;
switch (reg) {
case LTC4245_12VSENSE:
voltage = regval * 250;
curr = voltage / 50;
break;
case LTC4245_5VSENSE:
voltage = regval * 125;
curr = (voltage * 10) / 35;
break;
case LTC4245_3VSENSE:
voltage = regval * 125;
curr = (voltage * 10) / 25;
break;
case LTC4245_VEESENSE:
voltage = regval * 250;
curr = voltage / 100;
break;
default:
WARN_ON_ONCE(1);
curr = 0;
break;
}
return curr;
}
static ssize_t ltc4245_show_voltage(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
const int voltage = ltc4245_get_voltage(dev, attr->index);
return snprintf(buf, PAGE_SIZE, "%d\n", voltage);
}
static ssize_t ltc4245_show_current(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
const unsigned int curr = ltc4245_get_current(dev, attr->index);
return snprintf(buf, PAGE_SIZE, "%u\n", curr);
}
static ssize_t ltc4245_show_power(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
const unsigned int curr = ltc4245_get_current(dev, attr->index);
const int output_voltage = ltc4245_get_voltage(dev, attr->index+1);
const unsigned int power = abs(output_voltage * curr);
return snprintf(buf, PAGE_SIZE, "%u\n", power);
}
static ssize_t ltc4245_show_alarm(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(da);
struct ltc4245_data *data = ltc4245_update_device(dev);
const u8 reg = data->cregs[attr->index];
const u32 mask = attr->nr;
return snprintf(buf, PAGE_SIZE, "%u\n", (reg & mask) ? 1 : 0);
}
static ssize_t ltc4245_show_gpio(struct device *dev,
struct device_attribute *da,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct ltc4245_data *data = ltc4245_update_device(dev);
int val = data->gpios[attr->index];
if (val < 0)
return val;
return snprintf(buf, PAGE_SIZE, "%u\n", val * 10);
}
static int ltc4245_sysfs_create_groups(struct i2c_client *client)
{
struct ltc4245_data *data = i2c_get_clientdata(client);
struct device *dev = &client->dev;
int ret;
ret = sysfs_create_group(&dev->kobj, &ltc4245_std_group);
if (ret) {
dev_err(dev, "unable to register standard attributes\n");
return ret;
}
if (data->use_extra_gpios) {
ret = sysfs_create_group(&dev->kobj, &ltc4245_gpio_group);
if (ret) {
dev_err(dev, "unable to register gpio attributes\n");
sysfs_remove_group(&dev->kobj, &ltc4245_std_group);
return ret;
}
}
return 0;
}
static void ltc4245_sysfs_remove_groups(struct i2c_client *client)
{
struct ltc4245_data *data = i2c_get_clientdata(client);
struct device *dev = &client->dev;
if (data->use_extra_gpios)
sysfs_remove_group(&dev->kobj, &ltc4245_gpio_group);
sysfs_remove_group(&dev->kobj, &ltc4245_std_group);
}
static bool ltc4245_use_extra_gpios(struct i2c_client *client)
{
struct ltc4245_platform_data *pdata = dev_get_platdata(&client->dev);
#ifdef CONFIG_OF
struct device_node *np = client->dev.of_node;
#endif
if (pdata)
return pdata->use_extra_gpios;
#ifdef CONFIG_OF
if (of_find_property(np, "ltc4245,use-extra-gpios", NULL))
return true;
#endif
return false;
}
static int ltc4245_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ltc4245_data *data;
int ret;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->use_extra_gpios = ltc4245_use_extra_gpios(client);
i2c_smbus_write_byte_data(client, LTC4245_FAULT1, 0x00);
i2c_smbus_write_byte_data(client, LTC4245_FAULT2, 0x00);
ret = ltc4245_sysfs_create_groups(client);
if (ret)
return ret;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
ret = PTR_ERR(data->hwmon_dev);
goto out_hwmon_device_register;
}
return 0;
out_hwmon_device_register:
ltc4245_sysfs_remove_groups(client);
return ret;
}
static int ltc4245_remove(struct i2c_client *client)
{
struct ltc4245_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
ltc4245_sysfs_remove_groups(client);
return 0;
}
