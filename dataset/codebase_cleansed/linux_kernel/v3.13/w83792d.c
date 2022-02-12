static inline u8
FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 255;
rpm = clamp_val(rpm, 1, 1000000);
return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static inline u8
DIV_TO_REG(long val)
{
int i;
val = clamp_val(val, 1, 128) >> 1;
for (i = 0; i < 7; i++) {
if (val == 0)
break;
val >>= 1;
}
return (u8)i;
}
static inline long in_count_from_reg(int nr, struct w83792d_data *data)
{
return (data->in[nr] << 2) | ((data->low_bits >> (2 * nr)) & 0x03);
}
static inline int w83792d_read_value(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static inline int
w83792d_write_value(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%ld\n",
IN_FROM_REG(nr, in_count_from_reg(nr, data)));
}
static ssize_t
store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index - 1;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
w83792d_write_value(client, W83792D_REG_FAN_MIN[nr],
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%u\n", DIV_FROM_REG(data->fan_div[nr - 1]));
}
static ssize_t
store_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index - 1;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
unsigned long min;
u8 fan_div_reg = 0;
u8 tmp_fan_div;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr]));
data->fan_div[nr] = DIV_TO_REG(val);
fan_div_reg = w83792d_read_value(client, W83792D_REG_FAN_DIV[nr >> 1]);
fan_div_reg &= (nr & 0x01) ? 0x8f : 0xf8;
tmp_fan_div = (nr & 0x01) ? (((data->fan_div[nr]) << 4) & 0x70)
: ((data->fan_div[nr]) & 0x07);
w83792d_write_value(client, W83792D_REG_FAN_DIV[nr >> 1],
fan_div_reg | tmp_fan_div);
data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
w83792d_write_value(client, W83792D_REG_FAN_MIN[nr], data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp1(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%d\n", TEMP1_FROM_REG(data->temp1[nr]));
}
static ssize_t store_temp1(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp1[nr] = TEMP1_TO_REG(val);
w83792d_write_value(client, W83792D_REG_TEMP1[nr],
data->temp1[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp23(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sensor_attr
= to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%ld\n",
(long)TEMP_ADD_FROM_REG(data->temp_add[nr][index],
data->temp_add[nr][index+1]));
}
static ssize_t store_temp23(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr
= to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_add[nr][index] = TEMP_ADD_TO_REG_HIGH(val);
data->temp_add[nr][index+1] = TEMP_ADD_TO_REG_LOW(val);
w83792d_write_value(client, W83792D_REG_TEMP_ADD[nr][index],
data->temp_add[nr][index]);
w83792d_write_value(client, W83792D_REG_TEMP_ADD[nr][index+1],
data->temp_add[nr][index+1]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_alarms_reg(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%d\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%d\n", (data->alarms >> nr) & 1);
}
static ssize_t
show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%d\n", (data->pwm[nr] & 0x0f) << 4);
}
static ssize_t
show_pwmenable(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index - 1;
struct w83792d_data *data = w83792d_update_device(dev);
long pwm_enable_tmp = 1;
switch (data->pwmenable[nr]) {
case 0:
pwm_enable_tmp = 1;
break;
case 1:
pwm_enable_tmp = 3;
break;
case 2:
pwm_enable_tmp = 2;
break;
}
return sprintf(buf, "%ld\n", pwm_enable_tmp);
}
static ssize_t
store_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, 0, 255) >> 4;
mutex_lock(&data->update_lock);
val |= w83792d_read_value(client, W83792D_REG_PWM[nr]) & 0xf0;
data->pwm[nr] = val;
w83792d_write_value(client, W83792D_REG_PWM[nr], data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_pwmenable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index - 1;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
u8 fan_cfg_tmp, cfg1_tmp, cfg2_tmp, cfg3_tmp, cfg4_tmp;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val < 1 || val > 3)
return -EINVAL;
mutex_lock(&data->update_lock);
switch (val) {
case 1:
data->pwmenable[nr] = 0;
break;
case 2:
data->pwmenable[nr] = 2;
break;
case 3:
data->pwmenable[nr] = 1;
break;
}
cfg1_tmp = data->pwmenable[0];
cfg2_tmp = (data->pwmenable[1]) << 2;
cfg3_tmp = (data->pwmenable[2]) << 4;
cfg4_tmp = w83792d_read_value(client, W83792D_REG_FAN_CFG) & 0xc0;
fan_cfg_tmp = ((cfg4_tmp | cfg3_tmp) | cfg2_tmp) | cfg1_tmp;
w83792d_write_value(client, W83792D_REG_FAN_CFG, fan_cfg_tmp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm_mode(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%d\n", data->pwm[nr] >> 7);
}
static ssize_t
store_pwm_mode(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm[nr] = w83792d_read_value(client, W83792D_REG_PWM[nr]);
if (val) {
data->pwm[nr] |= 0x80;
} else {
data->pwm[nr] &= 0x7f;
}
w83792d_write_value(client, W83792D_REG_PWM[nr], data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_chassis_clear(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%d\n", data->chassis);
}
static ssize_t
store_chassis_clear(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
unsigned long val;
u8 reg;
if (kstrtoul(buf, 10, &val) || val != 0)
return -EINVAL;
mutex_lock(&data->update_lock);
reg = w83792d_read_value(client, W83792D_REG_CHASSIS_CLR);
w83792d_write_value(client, W83792D_REG_CHASSIS_CLR, reg | 0x80);
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_thermal_cruise(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%ld\n", (long)data->thermal_cruise[nr-1]);
}
static ssize_t
store_thermal_cruise(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index - 1;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
u8 target_tmp = 0, target_mask = 0;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
target_tmp = val;
target_tmp = target_tmp & 0x7f;
mutex_lock(&data->update_lock);
target_mask = w83792d_read_value(client,
W83792D_REG_THERMAL[nr]) & 0x80;
data->thermal_cruise[nr] = clamp_val(target_tmp, 0, 255);
w83792d_write_value(client, W83792D_REG_THERMAL[nr],
(data->thermal_cruise[nr]) | target_mask);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_tolerance(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%ld\n", (long)data->tolerance[nr-1]);
}
static ssize_t
store_tolerance(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index - 1;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
u8 tol_tmp, tol_mask;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
tol_mask = w83792d_read_value(client,
W83792D_REG_TOLERANCE[nr]) & ((nr == 1) ? 0x0f : 0xf0);
tol_tmp = clamp_val(val, 0, 15);
tol_tmp &= 0x0f;
data->tolerance[nr] = tol_tmp;
if (nr == 1)
tol_tmp <<= 4;
w83792d_write_value(client, W83792D_REG_TOLERANCE[nr],
tol_mask | tol_tmp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_sf2_point(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sensor_attr
= to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%ld\n", (long)data->sf2_points[index-1][nr-1]);
}
static ssize_t
store_sf2_point(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr
= to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr - 1;
int index = sensor_attr->index - 1;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
u8 mask_tmp = 0;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->sf2_points[index][nr] = clamp_val(val, 0, 127);
mask_tmp = w83792d_read_value(client,
W83792D_REG_POINTS[index][nr]) & 0x80;
w83792d_write_value(client, W83792D_REG_POINTS[index][nr],
mask_tmp|data->sf2_points[index][nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_sf2_level(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sensor_attr
= to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index;
struct w83792d_data *data = w83792d_update_device(dev);
return sprintf(buf, "%d\n",
(((data->sf2_levels[index-1][nr]) * 100) / 15));
}
static ssize_t
store_sf2_level(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sensor_attr
= to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int index = sensor_attr->index - 1;
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
u8 mask_tmp = 0, level_tmp = 0;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->sf2_levels[index][nr] = clamp_val((val * 15) / 100, 0, 15);
mask_tmp = w83792d_read_value(client, W83792D_REG_LEVELS[index][nr])
& ((nr == 3) ? 0xf0 : 0x0f);
if (nr == 3)
level_tmp = data->sf2_levels[index][nr];
else
level_tmp = data->sf2_levels[index][nr] << 4;
w83792d_write_value(client, W83792D_REG_LEVELS[index][nr],
level_tmp | mask_tmp);
mutex_unlock(&data->update_lock);
return count;
}
static int
w83792d_detect_subclients(struct i2c_client *new_client)
{
int i, id, err;
int address = new_client->addr;
u8 val;
struct i2c_adapter *adapter = new_client->adapter;
struct w83792d_data *data = i2c_get_clientdata(new_client);
id = i2c_adapter_id(adapter);
if (force_subclients[0] == id && force_subclients[1] == address) {
for (i = 2; i <= 3; i++) {
if (force_subclients[i] < 0x48 ||
force_subclients[i] > 0x4f) {
dev_err(&new_client->dev,
"invalid subclient address %d; must be 0x48-0x4f\n",
force_subclients[i]);
err = -ENODEV;
goto ERROR_SC_0;
}
}
w83792d_write_value(new_client, W83792D_REG_I2C_SUBADDR,
(force_subclients[2] & 0x07) |
((force_subclients[3] & 0x07) << 4));
}
val = w83792d_read_value(new_client, W83792D_REG_I2C_SUBADDR);
if (!(val & 0x08))
data->lm75[0] = i2c_new_dummy(adapter, 0x48 + (val & 0x7));
if (!(val & 0x80)) {
if ((data->lm75[0] != NULL) &&
((val & 0x7) == ((val >> 4) & 0x7))) {
dev_err(&new_client->dev,
"duplicate addresses 0x%x, use force_subclient\n",
data->lm75[0]->addr);
err = -ENODEV;
goto ERROR_SC_1;
}
data->lm75[1] = i2c_new_dummy(adapter,
0x48 + ((val >> 4) & 0x7));
}
return 0;
ERROR_SC_1:
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
ERROR_SC_0:
return err;
}
static int
w83792d_detect(struct i2c_client *client, struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int val1, val2;
unsigned short address = client->addr;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (w83792d_read_value(client, W83792D_REG_CONFIG) & 0x80)
return -ENODEV;
val1 = w83792d_read_value(client, W83792D_REG_BANK);
val2 = w83792d_read_value(client, W83792D_REG_CHIPMAN);
if (!(val1 & 0x07)) {
if ((!(val1 & 0x80) && val2 != 0xa3) ||
((val1 & 0x80) && val2 != 0x5c))
return -ENODEV;
}
if (w83792d_read_value(client, W83792D_REG_I2C_ADDR) != address)
return -ENODEV;
w83792d_write_value(client,
W83792D_REG_BANK,
(w83792d_read_value(client,
W83792D_REG_BANK) & 0x78) | 0x80);
val1 = w83792d_read_value(client, W83792D_REG_WCHIPID);
val2 = w83792d_read_value(client, W83792D_REG_CHIPMAN);
if (val1 != 0x7a || val2 != 0x5c)
return -ENODEV;
strlcpy(info->type, "w83792d", I2C_NAME_SIZE);
return 0;
}
static int
w83792d_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct w83792d_data *data;
struct device *dev = &client->dev;
int i, val1, err;
data = devm_kzalloc(dev, sizeof(struct w83792d_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
data->valid = 0;
mutex_init(&data->update_lock);
err = w83792d_detect_subclients(client);
if (err)
return err;
w83792d_init_client(client);
for (i = 0; i < 7; i++) {
data->fan_min[i] = w83792d_read_value(client,
W83792D_REG_FAN_MIN[i]);
}
err = sysfs_create_group(&dev->kobj, &w83792d_group);
if (err)
goto exit_i2c_unregister;
val1 = w83792d_read_value(client, W83792D_REG_GPIO_EN);
if (!(val1 & 0x40)) {
err = sysfs_create_group(&dev->kobj, &w83792d_group_fan[0]);
if (err)
goto exit_remove_files;
}
if (!(val1 & 0x20)) {
err = sysfs_create_group(&dev->kobj, &w83792d_group_fan[1]);
if (err)
goto exit_remove_files;
}
val1 = w83792d_read_value(client, W83792D_REG_PIN);
if (val1 & 0x40) {
err = sysfs_create_group(&dev->kobj, &w83792d_group_fan[2]);
if (err)
goto exit_remove_files;
}
if (val1 & 0x04) {
err = sysfs_create_group(&dev->kobj, &w83792d_group_fan[3]);
if (err)
goto exit_remove_files;
}
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&dev->kobj, &w83792d_group);
for (i = 0; i < ARRAY_SIZE(w83792d_group_fan); i++)
sysfs_remove_group(&dev->kobj, &w83792d_group_fan[i]);
exit_i2c_unregister:
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1] != NULL)
i2c_unregister_device(data->lm75[1]);
return err;
}
static int
w83792d_remove(struct i2c_client *client)
{
struct w83792d_data *data = i2c_get_clientdata(client);
int i;
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &w83792d_group);
for (i = 0; i < ARRAY_SIZE(w83792d_group_fan); i++)
sysfs_remove_group(&client->dev.kobj,
&w83792d_group_fan[i]);
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1] != NULL)
i2c_unregister_device(data->lm75[1]);
return 0;
}
static void
w83792d_init_client(struct i2c_client *client)
{
u8 temp2_cfg, temp3_cfg, vid_in_b;
if (init)
w83792d_write_value(client, W83792D_REG_CONFIG, 0x80);
vid_in_b = w83792d_read_value(client, W83792D_REG_VID_IN_B);
w83792d_write_value(client, W83792D_REG_VID_IN_B,
vid_in_b & 0xbf);
temp2_cfg = w83792d_read_value(client, W83792D_REG_TEMP2_CONFIG);
temp3_cfg = w83792d_read_value(client, W83792D_REG_TEMP3_CONFIG);
w83792d_write_value(client, W83792D_REG_TEMP2_CONFIG,
temp2_cfg & 0xe6);
w83792d_write_value(client, W83792D_REG_TEMP3_CONFIG,
temp3_cfg & 0xe6);
w83792d_write_value(client, W83792D_REG_CONFIG,
(w83792d_read_value(client,
W83792D_REG_CONFIG) & 0xf7)
| 0x01);
}
static struct w83792d_data *w83792d_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83792d_data *data = i2c_get_clientdata(client);
int i, j;
u8 reg_array_tmp[4], reg_tmp;
mutex_lock(&data->update_lock);
if (time_after
(jiffies - data->last_updated, (unsigned long) (HZ * 3))
|| time_before(jiffies, data->last_updated) || !data->valid) {
dev_dbg(dev, "Starting device update\n");
for (i = 0; i < 9; i++) {
data->in[i] = w83792d_read_value(client,
W83792D_REG_IN[i]);
data->in_max[i] = w83792d_read_value(client,
W83792D_REG_IN_MAX[i]);
data->in_min[i] = w83792d_read_value(client,
W83792D_REG_IN_MIN[i]);
}
data->low_bits = w83792d_read_value(client,
W83792D_REG_LOW_BITS1) +
(w83792d_read_value(client,
W83792D_REG_LOW_BITS2) << 8);
for (i = 0; i < 7; i++) {
data->fan[i] = w83792d_read_value(client,
W83792D_REG_FAN[i]);
data->fan_min[i] = w83792d_read_value(client,
W83792D_REG_FAN_MIN[i]);
data->pwm[i] = w83792d_read_value(client,
W83792D_REG_PWM[i]);
}
reg_tmp = w83792d_read_value(client, W83792D_REG_FAN_CFG);
data->pwmenable[0] = reg_tmp & 0x03;
data->pwmenable[1] = (reg_tmp>>2) & 0x03;
data->pwmenable[2] = (reg_tmp>>4) & 0x03;
for (i = 0; i < 3; i++) {
data->temp1[i] = w83792d_read_value(client,
W83792D_REG_TEMP1[i]);
}
for (i = 0; i < 2; i++) {
for (j = 0; j < 6; j++) {
data->temp_add[i][j] = w83792d_read_value(
client, W83792D_REG_TEMP_ADD[i][j]);
}
}
for (i = 0; i < 4; i++) {
reg_array_tmp[i] = w83792d_read_value(client,
W83792D_REG_FAN_DIV[i]);
}
data->fan_div[0] = reg_array_tmp[0] & 0x07;
data->fan_div[1] = (reg_array_tmp[0] >> 4) & 0x07;
data->fan_div[2] = reg_array_tmp[1] & 0x07;
data->fan_div[3] = (reg_array_tmp[1] >> 4) & 0x07;
data->fan_div[4] = reg_array_tmp[2] & 0x07;
data->fan_div[5] = (reg_array_tmp[2] >> 4) & 0x07;
data->fan_div[6] = reg_array_tmp[3] & 0x07;
data->alarms = w83792d_read_value(client, W83792D_REG_ALARM1) +
(w83792d_read_value(client, W83792D_REG_ALARM2) << 8) +
(w83792d_read_value(client, W83792D_REG_ALARM3) << 16);
data->chassis = (w83792d_read_value(client,
W83792D_REG_CHASSIS) >> 5) & 0x01;
for (i = 0; i < 3; i++) {
data->thermal_cruise[i] =
w83792d_read_value(client,
W83792D_REG_THERMAL[i]) & 0x7f;
}
reg_tmp = w83792d_read_value(client, W83792D_REG_TOLERANCE[0]);
data->tolerance[0] = reg_tmp & 0x0f;
data->tolerance[1] = (reg_tmp >> 4) & 0x0f;
data->tolerance[2] = w83792d_read_value(client,
W83792D_REG_TOLERANCE[2]) & 0x0f;
for (i = 0; i < 3; i++) {
for (j = 0; j < 4; j++) {
data->sf2_points[i][j]
= w83792d_read_value(client,
W83792D_REG_POINTS[i][j]) & 0x7f;
}
}
for (i = 0; i < 3; i++) {
reg_tmp = w83792d_read_value(client,
W83792D_REG_LEVELS[i][0]);
data->sf2_levels[i][0] = reg_tmp & 0x0f;
data->sf2_levels[i][1] = (reg_tmp >> 4) & 0x0f;
reg_tmp = w83792d_read_value(client,
W83792D_REG_LEVELS[i][2]);
data->sf2_levels[i][2] = (reg_tmp >> 4) & 0x0f;
data->sf2_levels[i][3] = reg_tmp & 0x0f;
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
#ifdef DEBUG
w83792d_print_debug(data, dev);
#endif
return data;
}
static void w83792d_print_debug(struct w83792d_data *data, struct device *dev)
{
int i = 0, j = 0;
dev_dbg(dev, "==========The following is the debug message...========\n");
dev_dbg(dev, "9 set of Voltages: =====>\n");
for (i = 0; i < 9; i++) {
dev_dbg(dev, "vin[%d] is: 0x%x\n", i, data->in[i]);
dev_dbg(dev, "vin[%d] max is: 0x%x\n", i, data->in_max[i]);
dev_dbg(dev, "vin[%d] min is: 0x%x\n", i, data->in_min[i]);
}
dev_dbg(dev, "Low Bit1 is: 0x%x\n", data->low_bits & 0xff);
dev_dbg(dev, "Low Bit2 is: 0x%x\n", data->low_bits >> 8);
dev_dbg(dev, "7 set of Fan Counts and Duty Cycles: =====>\n");
for (i = 0; i < 7; i++) {
dev_dbg(dev, "fan[%d] is: 0x%x\n", i, data->fan[i]);
dev_dbg(dev, "fan[%d] min is: 0x%x\n", i, data->fan_min[i]);
dev_dbg(dev, "pwm[%d] is: 0x%x\n", i, data->pwm[i]);
}
dev_dbg(dev, "3 set of Temperatures: =====>\n");
for (i = 0; i < 3; i++)
dev_dbg(dev, "temp1[%d] is: 0x%x\n", i, data->temp1[i]);
for (i = 0; i < 2; i++) {
for (j = 0; j < 6; j++) {
dev_dbg(dev, "temp_add[%d][%d] is: 0x%x\n", i, j,
data->temp_add[i][j]);
}
}
for (i = 0; i < 7; i++)
dev_dbg(dev, "fan_div[%d] is: 0x%x\n", i, data->fan_div[i]);
dev_dbg(dev, "==========End of the debug message...================\n");
dev_dbg(dev, "\n");
}
