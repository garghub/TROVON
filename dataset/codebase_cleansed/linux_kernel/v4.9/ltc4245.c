static void ltc4245_update_gpios(struct device *dev)
{
struct ltc4245_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
u8 gpio_curr, gpio_next, gpio_reg;
int i;
if (!data->use_extra_gpios) {
data->gpios[0] = data->vregs[LTC4245_GPIOADC - 0x10];
return;
}
if (time_after(jiffies, data->last_updated + 5 * HZ)) {
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
struct ltc4245_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
s32 val;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
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
data->valid = true;
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
static int ltc4245_read_curr(struct device *dev, u32 attr, int channel,
long *val)
{
struct ltc4245_data *data = ltc4245_update_device(dev);
switch (attr) {
case hwmon_curr_input:
*val = ltc4245_get_current(dev, ltc4245_curr_regs[channel]);
return 0;
case hwmon_curr_max_alarm:
*val = !!(data->cregs[LTC4245_FAULT1] & BIT(channel + 4));
return 0;
default:
return -EOPNOTSUPP;
}
}
static int ltc4245_read_in(struct device *dev, u32 attr, int channel, long *val)
{
struct ltc4245_data *data = ltc4245_update_device(dev);
switch (attr) {
case hwmon_in_input:
if (channel < 8) {
*val = ltc4245_get_voltage(dev,
ltc4245_in_regs[channel]);
} else {
int regval = data->gpios[channel - 8];
if (regval < 0)
return regval;
*val = regval * 10;
}
return 0;
case hwmon_in_min_alarm:
if (channel < 4)
*val = !!(data->cregs[LTC4245_FAULT1] & BIT(channel));
else
*val = !!(data->cregs[LTC4245_FAULT2] &
BIT(channel - 4));
return 0;
default:
return -EOPNOTSUPP;
}
}
static int ltc4245_read_power(struct device *dev, u32 attr, int channel,
long *val)
{
unsigned long curr;
long voltage;
switch (attr) {
case hwmon_power_input:
(void)ltc4245_update_device(dev);
curr = ltc4245_get_current(dev, ltc4245_curr_regs[channel]);
voltage = ltc4245_get_voltage(dev, ltc4245_in_regs[channel]);
*val = abs(curr * voltage);
return 0;
default:
return -EOPNOTSUPP;
}
}
static int ltc4245_read(struct device *dev, enum hwmon_sensor_types type,
u32 attr, int channel, long *val)
{
switch (type) {
case hwmon_curr:
return ltc4245_read_curr(dev, attr, channel, val);
case hwmon_power:
return ltc4245_read_power(dev, attr, channel, val);
case hwmon_in:
return ltc4245_read_in(dev, attr, channel - 1, val);
default:
return -EOPNOTSUPP;
}
}
static umode_t ltc4245_is_visible(const void *_data,
enum hwmon_sensor_types type,
u32 attr, int channel)
{
const struct ltc4245_data *data = _data;
switch (type) {
case hwmon_in:
if (channel == 0)
return 0;
switch (attr) {
case hwmon_in_input:
if (channel > 9 && !data->use_extra_gpios)
return 0;
return S_IRUGO;
case hwmon_in_min_alarm:
if (channel > 8)
return 0;
return S_IRUGO;
default:
return 0;
}
case hwmon_curr:
switch (attr) {
case hwmon_curr_input:
case hwmon_curr_max_alarm:
return S_IRUGO;
default:
return 0;
}
case hwmon_power:
switch (attr) {
case hwmon_power_input:
return S_IRUGO;
default:
return 0;
}
default:
return 0;
}
}
static bool ltc4245_use_extra_gpios(struct i2c_client *client)
{
struct ltc4245_platform_data *pdata = dev_get_platdata(&client->dev);
struct device_node *np = client->dev.of_node;
if (pdata)
return pdata->use_extra_gpios;
if (of_find_property(np, "ltc4245,use-extra-gpios", NULL))
return true;
return false;
}
static int ltc4245_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = client->adapter;
struct ltc4245_data *data;
struct device *hwmon_dev;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
data->use_extra_gpios = ltc4245_use_extra_gpios(client);
i2c_smbus_write_byte_data(client, LTC4245_FAULT1, 0x00);
i2c_smbus_write_byte_data(client, LTC4245_FAULT2, 0x00);
hwmon_dev = devm_hwmon_device_register_with_info(&client->dev,
client->name, data,
&ltc4245_chip_info,
NULL);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
