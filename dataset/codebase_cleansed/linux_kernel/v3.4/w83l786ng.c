static inline u8
FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 255;
rpm = SENSORS_LIMIT(rpm, 1, 1000000);
return SENSORS_LIMIT((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static inline u8
DIV_TO_REG(long val)
{
int i;
val = SENSORS_LIMIT(val, 1, 128) >> 1;
for (i = 0; i < 7; i++) {
if (val == 0)
break;
val >>= 1;
}
return (u8)i;
}
static u8
w83l786ng_read_value(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static int
w83l786ng_write_value(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static ssize_t
store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
w83l786ng_write_value(client, W83L786NG_REG_FAN_MIN(nr),
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct w83l786ng_data *data = w83l786ng_update_device(dev);
return sprintf(buf, "%u\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t
store_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
unsigned long min;
u8 tmp_fan_div;
u8 fan_div_reg;
u8 keep_mask = 0;
u8 new_shift = 0;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr], DIV_FROM_REG(data->fan_div[nr]));
data->fan_div[nr] = DIV_TO_REG(val);
switch (nr) {
case 0:
keep_mask = 0xf8;
new_shift = 0;
break;
case 1:
keep_mask = 0x8f;
new_shift = 4;
break;
}
fan_div_reg = w83l786ng_read_value(client, W83L786NG_REG_FAN_DIV)
& keep_mask;
tmp_fan_div = (data->fan_div[nr] << new_shift) & ~keep_mask;
w83l786ng_write_value(client, W83L786NG_REG_FAN_DIV,
fan_div_reg | tmp_fan_div);
data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
w83l786ng_write_value(client, W83L786NG_REG_FAN_MIN(nr),
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83l786ng_data *data = w83l786ng_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr][index]));
}
static ssize_t
store_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp[nr][index] = TEMP_TO_REG(val);
w83l786ng_write_value(client, W83L786NG_REG_TEMP[nr][index],
data->temp[nr][index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_pwm_mode(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
u8 reg;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm_mode[nr] = val;
reg = w83l786ng_read_value(client, W83L786NG_REG_FAN_CFG);
reg &= ~(1 << W83L786NG_PWM_MODE_SHIFT[nr]);
if (!val)
reg |= 1 << W83L786NG_PWM_MODE_SHIFT[nr];
w83l786ng_write_value(client, W83L786NG_REG_FAN_CFG, reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = SENSORS_LIMIT(val, 0, 255);
mutex_lock(&data->update_lock);
data->pwm[nr] = val;
w83l786ng_write_value(client, W83L786NG_REG_PWM[nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_pwm_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
u8 reg;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (!val || val > 2)
return -EINVAL;
mutex_lock(&data->update_lock);
reg = w83l786ng_read_value(client, W83L786NG_REG_FAN_CFG);
data->pwm_enable[nr] = val;
reg &= ~(0x02 << W83L786NG_PWM_ENABLE_SHIFT[nr]);
reg |= (val - 1) << W83L786NG_PWM_ENABLE_SHIFT[nr];
w83l786ng_write_value(client, W83L786NG_REG_FAN_CFG, reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_tolerance(struct device *dev, struct device_attribute *attr, char *buf)
{
int nr = to_sensor_dev_attr(attr)->index;
struct w83l786ng_data *data = w83l786ng_update_device(dev);
return sprintf(buf, "%ld\n", (long)data->tolerance[nr]);
}
static ssize_t
store_tolerance(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(attr)->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
u8 tol_tmp, tol_mask;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
tol_mask = w83l786ng_read_value(client,
W83L786NG_REG_TOLERANCE) & ((nr == 1) ? 0x0f : 0xf0);
tol_tmp = SENSORS_LIMIT(val, 0, 15);
tol_tmp &= 0x0f;
data->tolerance[nr] = tol_tmp;
if (nr == 1)
tol_tmp <<= 4;
w83l786ng_write_value(client, W83L786NG_REG_TOLERANCE,
tol_mask | tol_tmp);
mutex_unlock(&data->update_lock);
return count;
}
static int
w83l786ng_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
u16 man_id;
u8 chip_id;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if ((w83l786ng_read_value(client, W83L786NG_REG_CONFIG) & 0x80)) {
dev_dbg(&adapter->dev, "W83L786NG detection failed at 0x%02x\n",
client->addr);
return -ENODEV;
}
man_id = (w83l786ng_read_value(client, W83L786NG_REG_MAN_ID1) << 8) +
w83l786ng_read_value(client, W83L786NG_REG_MAN_ID2);
chip_id = w83l786ng_read_value(client, W83L786NG_REG_CHIP_ID);
if (man_id != 0x5CA3 ||
chip_id != 0x80) {
dev_dbg(&adapter->dev,
"Unsupported chip (man_id=0x%04X, chip_id=0x%02X)\n",
man_id, chip_id);
return -ENODEV;
}
strlcpy(info->type, "w83l786ng", I2C_NAME_SIZE);
return 0;
}
static int
w83l786ng_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct w83l786ng_data *data;
int i, err = 0;
u8 reg_tmp;
data = kzalloc(sizeof(struct w83l786ng_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit;
}
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
w83l786ng_init_client(client);
for (i = 0; i < 2; i++) {
data->fan_min[i] = w83l786ng_read_value(client,
W83L786NG_REG_FAN_MIN(i));
}
reg_tmp = w83l786ng_read_value(client, W83L786NG_REG_FAN_DIV);
data->fan_div[0] = reg_tmp & 0x07;
data->fan_div[1] = (reg_tmp >> 4) & 0x07;
err = sysfs_create_group(&client->dev.kobj, &w83l786ng_group);
if (err)
goto exit_remove;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
sysfs_remove_group(&client->dev.kobj, &w83l786ng_group);
kfree(data);
exit:
return err;
}
static int
w83l786ng_remove(struct i2c_client *client)
{
struct w83l786ng_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &w83l786ng_group);
kfree(data);
return 0;
}
static void
w83l786ng_init_client(struct i2c_client *client)
{
u8 tmp;
if (reset)
w83l786ng_write_value(client, W83L786NG_REG_CONFIG, 0x80);
tmp = w83l786ng_read_value(client, W83L786NG_REG_CONFIG);
if (!(tmp & 0x01))
w83l786ng_write_value(client, W83L786NG_REG_CONFIG, tmp | 0x01);
}
static struct w83l786ng_data *w83l786ng_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83l786ng_data *data = i2c_get_clientdata(client);
int i, j;
u8 reg_tmp, pwmcfg;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
dev_dbg(&client->dev, "Updating w83l786ng data.\n");
for (i = 0; i < 3; i++) {
data->in[i] = w83l786ng_read_value(client,
W83L786NG_REG_IN(i));
data->in_min[i] = w83l786ng_read_value(client,
W83L786NG_REG_IN_MIN(i));
data->in_max[i] = w83l786ng_read_value(client,
W83L786NG_REG_IN_MAX(i));
}
for (i = 0; i < 2; i++) {
data->fan[i] = w83l786ng_read_value(client,
W83L786NG_REG_FAN(i));
data->fan_min[i] = w83l786ng_read_value(client,
W83L786NG_REG_FAN_MIN(i));
}
reg_tmp = w83l786ng_read_value(client, W83L786NG_REG_FAN_DIV);
data->fan_div[0] = reg_tmp & 0x07;
data->fan_div[1] = (reg_tmp >> 4) & 0x07;
pwmcfg = w83l786ng_read_value(client, W83L786NG_REG_FAN_CFG);
for (i = 0; i < 2; i++) {
data->pwm_mode[i] =
((pwmcfg >> W83L786NG_PWM_MODE_SHIFT[i]) & 1)
? 0 : 1;
data->pwm_enable[i] =
((pwmcfg >> W83L786NG_PWM_ENABLE_SHIFT[i]) & 2) + 1;
data->pwm[i] = w83l786ng_read_value(client,
W83L786NG_REG_PWM[i]);
}
for (i = 0; i < 2; i++) {
for (j = 0; j < 3; j++) {
data->temp[i][j] = w83l786ng_read_value(client,
W83L786NG_REG_TEMP[i][j]);
}
}
reg_tmp = w83l786ng_read_value(client, W83L786NG_REG_TOLERANCE);
data->tolerance[0] = reg_tmp & 0x0f;
data->tolerance[1] = (reg_tmp >> 4) & 0x0f;
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
