static inline int w83791d_read(struct i2c_client *client, u8 reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static inline int w83791d_write(struct i2c_client *client, u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(client, reg, value);
}
static u8 fan_to_reg(long rpm, int div)
{
if (rpm == 0)
return 255;
rpm = clamp_val(rpm, 1, 1000000);
return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static u8 div_to_reg(int nr, long val)
{
int i;
val = clamp_val(val, 1, 128) >> 1;
for (i = 0; i < 7; i++) {
if (val == 0)
break;
val >>= 1;
}
return (u8) i;
}
static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr =
to_sensor_dev_attr(attr);
struct w83791d_data *data = w83791d_update_device(dev);
int bitnr = sensor_attr->index;
return sprintf(buf, "%d\n", (data->beep_mask >> bitnr) & 1);
}
static ssize_t store_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr =
to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int bitnr = sensor_attr->index;
int bytenr = bitnr / 8;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = val ? 1 : 0;
mutex_lock(&data->update_lock);
data->beep_mask &= ~(0xff << (bytenr * 8));
data->beep_mask |= w83791d_read(client, W83791D_REG_BEEP_CTRL[bytenr])
<< (bytenr * 8);
data->beep_mask &= ~(1 << bitnr);
data->beep_mask |= val << bitnr;
w83791d_write(client, W83791D_REG_BEEP_CTRL[bytenr],
(data->beep_mask >> (bytenr * 8)) & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr =
to_sensor_dev_attr(attr);
struct w83791d_data *data = w83791d_update_device(dev);
int bitnr = sensor_attr->index;
return sprintf(buf, "%d\n", (data->alarms >> bitnr) & 1);
}
static ssize_t store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int nr = sensor_attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = fan_to_reg(val, DIV_FROM_REG(data->fan_div[nr]));
w83791d_write(client, W83791D_REG_FAN_MIN[nr], data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%u\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t store_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int nr = sensor_attr->index;
unsigned long min;
u8 tmp_fan_div;
u8 fan_div_reg;
u8 vbat_reg;
int indx = 0;
u8 keep_mask = 0;
u8 new_shift = 0;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
min = FAN_FROM_REG(data->fan_min[nr], DIV_FROM_REG(data->fan_div[nr]));
mutex_lock(&data->update_lock);
data->fan_div[nr] = div_to_reg(nr, val);
switch (nr) {
case 0:
indx = 0;
keep_mask = 0xcf;
new_shift = 4;
break;
case 1:
indx = 0;
keep_mask = 0x3f;
new_shift = 6;
break;
case 2:
indx = 1;
keep_mask = 0x3f;
new_shift = 6;
break;
case 3:
indx = 2;
keep_mask = 0xf8;
new_shift = 0;
break;
case 4:
indx = 2;
keep_mask = 0x8f;
new_shift = 4;
break;
#ifdef DEBUG
default:
dev_warn(dev, "store_fan_div: Unexpected nr seen: %d\n", nr);
count = -EINVAL;
goto err_exit;
#endif
}
fan_div_reg = w83791d_read(client, W83791D_REG_FAN_DIV[indx])
& keep_mask;
tmp_fan_div = (data->fan_div[nr] << new_shift) & ~keep_mask;
w83791d_write(client, W83791D_REG_FAN_DIV[indx],
fan_div_reg | tmp_fan_div);
if (nr < 3) {
keep_mask = ~(1 << (nr + 5));
vbat_reg = w83791d_read(client, W83791D_REG_VBAT)
& keep_mask;
tmp_fan_div = (data->fan_div[nr] << (3 + nr)) & ~keep_mask;
w83791d_write(client, W83791D_REG_VBAT,
vbat_reg | tmp_fan_div);
}
data->fan_min[nr] = fan_to_reg(min, DIV_FROM_REG(data->fan_div[nr]));
w83791d_write(client, W83791D_REG_FAN_MIN[nr], data->fan_min[nr]);
#ifdef DEBUG
err_exit:
#endif
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%u\n", data->pwm[nr]);
}
static ssize_t store_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int nr = sensor_attr->index;
unsigned long val;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm[nr] = clamp_val(val, 0, 255);
w83791d_write(client, W83791D_REG_PWM[nr], data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwmenable(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%u\n", data->pwm_enable[nr] + 1);
}
static ssize_t store_pwmenable(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int nr = sensor_attr->index;
unsigned long val;
u8 reg_cfg_tmp;
u8 reg_idx = 0;
u8 val_shift = 0;
u8 keep_mask = 0;
int ret = kstrtoul(buf, 10, &val);
if (ret || val < 1 || val > 3)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm_enable[nr] = val - 1;
switch (nr) {
case 0:
reg_idx = 0;
val_shift = 2;
keep_mask = 0xf3;
break;
case 1:
reg_idx = 0;
val_shift = 4;
keep_mask = 0xcf;
break;
case 2:
reg_idx = 1;
val_shift = 2;
keep_mask = 0xf3;
break;
}
reg_cfg_tmp = w83791d_read(client, W83791D_REG_FAN_CFG[reg_idx]);
reg_cfg_tmp = (reg_cfg_tmp & keep_mask) |
data->pwm_enable[nr] << val_shift;
w83791d_write(client, W83791D_REG_FAN_CFG[reg_idx], reg_cfg_tmp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_target(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct w83791d_data *data = w83791d_update_device(dev);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n", TEMP1_FROM_REG(data->temp_target[nr]));
}
static ssize_t store_temp_target(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int nr = sensor_attr->index;
long val;
u8 target_mask;
if (kstrtol(buf, 10, &val))
return -EINVAL;
mutex_lock(&data->update_lock);
data->temp_target[nr] = TARGET_TEMP_TO_REG(val);
target_mask = w83791d_read(client,
W83791D_REG_TEMP_TARGET[nr]) & 0x80;
w83791d_write(client, W83791D_REG_TEMP_TARGET[nr],
data->temp_target[nr] | target_mask);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_tolerance(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct w83791d_data *data = w83791d_update_device(dev);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n", TEMP1_FROM_REG(data->temp_tolerance[nr]));
}
static ssize_t store_temp_tolerance(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int nr = sensor_attr->index;
unsigned long val;
u8 target_mask;
u8 reg_idx = 0;
u8 val_shift = 0;
u8 keep_mask = 0;
if (kstrtoul(buf, 10, &val))
return -EINVAL;
switch (nr) {
case 0:
reg_idx = 0;
val_shift = 0;
keep_mask = 0xf0;
break;
case 1:
reg_idx = 0;
val_shift = 4;
keep_mask = 0x0f;
break;
case 2:
reg_idx = 1;
val_shift = 0;
keep_mask = 0xf0;
break;
}
mutex_lock(&data->update_lock);
data->temp_tolerance[nr] = TOL_TEMP_TO_REG(val);
target_mask = w83791d_read(client,
W83791D_REG_TEMP_TOL[reg_idx]) & keep_mask;
w83791d_write(client, W83791D_REG_TEMP_TOL[reg_idx],
(data->temp_tolerance[nr] << val_shift) | target_mask);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp1(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%d\n", TEMP1_FROM_REG(data->temp1[attr->index]));
}
static ssize_t store_temp1(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp1[nr] = TEMP1_TO_REG(val);
w83791d_write(client, W83791D_REG_TEMP1[nr], data->temp1[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp23(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct w83791d_data *data = w83791d_update_device(dev);
int nr = attr->nr;
int index = attr->index;
return sprintf(buf, "%d\n", TEMP23_FROM_REG(data->temp_add[nr][index]));
}
static ssize_t store_temp23(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
long val;
int err;
int nr = attr->nr;
int index = attr->index;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_add[nr][index] = TEMP23_TO_REG(val);
w83791d_write(client, W83791D_REG_TEMP_ADD[nr][index * 2],
data->temp_add[nr][index] >> 8);
w83791d_write(client, W83791D_REG_TEMP_ADD[nr][index * 2 + 1],
data->temp_add[nr][index] & 0x80);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_beep_enable(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%d\n", data->beep_enable);
}
static ssize_t show_beep_mask(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%d\n", BEEP_MASK_FROM_REG(data->beep_mask));
}
static ssize_t store_beep_mask(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int i;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->beep_mask = BEEP_MASK_TO_REG(val) & ~GLOBAL_BEEP_ENABLE_MASK;
data->beep_mask |= (data->beep_enable << GLOBAL_BEEP_ENABLE_SHIFT);
val = data->beep_mask;
for (i = 0; i < 3; i++) {
w83791d_write(client, W83791D_REG_BEEP_CTRL[i], (val & 0xff));
val >>= 8;
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t store_beep_enable(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->beep_enable = val ? 1 : 0;
data->beep_mask &= ~GLOBAL_BEEP_ENABLE_MASK;
data->beep_mask |= (data->beep_enable << GLOBAL_BEEP_ENABLE_SHIFT);
val = (data->beep_mask >> 8) & 0xff;
w83791d_write(client, W83791D_REG_BEEP_CTRL[1], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t cpu0_vid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w83791d_data *data = w83791d_update_device(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t vrm_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83791d_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->vrm);
}
static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83791d_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 255)
return -EINVAL;
data->vrm = val;
return count;
}
static int w83791d_detect_subclients(struct i2c_client *client)
{
struct i2c_adapter *adapter = client->adapter;
struct w83791d_data *data = i2c_get_clientdata(client);
int address = client->addr;
int i, id, err;
u8 val;
id = i2c_adapter_id(adapter);
if (force_subclients[0] == id && force_subclients[1] == address) {
for (i = 2; i <= 3; i++) {
if (force_subclients[i] < 0x48 ||
force_subclients[i] > 0x4f) {
dev_err(&client->dev,
"invalid subclient "
"address %d; must be 0x48-0x4f\n",
force_subclients[i]);
err = -ENODEV;
goto error_sc_0;
}
}
w83791d_write(client, W83791D_REG_I2C_SUBADDR,
(force_subclients[2] & 0x07) |
((force_subclients[3] & 0x07) << 4));
}
val = w83791d_read(client, W83791D_REG_I2C_SUBADDR);
if (!(val & 0x08))
data->lm75[0] = i2c_new_dummy(adapter, 0x48 + (val & 0x7));
if (!(val & 0x80)) {
if ((data->lm75[0] != NULL) &&
((val & 0x7) == ((val >> 4) & 0x7))) {
dev_err(&client->dev,
"duplicate addresses 0x%x, "
"use force_subclient\n",
data->lm75[0]->addr);
err = -ENODEV;
goto error_sc_1;
}
data->lm75[1] = i2c_new_dummy(adapter,
0x48 + ((val >> 4) & 0x7));
}
return 0;
error_sc_1:
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
error_sc_0:
return err;
}
static int w83791d_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int val1, val2;
unsigned short address = client->addr;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (w83791d_read(client, W83791D_REG_CONFIG) & 0x80)
return -ENODEV;
val1 = w83791d_read(client, W83791D_REG_BANK);
val2 = w83791d_read(client, W83791D_REG_CHIPMAN);
if (!(val1 & 0x07)) {
if ((!(val1 & 0x80) && val2 != 0xa3) ||
((val1 & 0x80) && val2 != 0x5c)) {
return -ENODEV;
}
}
if (w83791d_read(client, W83791D_REG_I2C_ADDR) != address)
return -ENODEV;
val1 = w83791d_read(client, W83791D_REG_BANK) & 0x78;
w83791d_write(client, W83791D_REG_BANK, val1 | 0x80);
val1 = w83791d_read(client, W83791D_REG_WCHIPID);
val2 = w83791d_read(client, W83791D_REG_CHIPMAN);
if (val1 != 0x71 || val2 != 0x5c)
return -ENODEV;
strlcpy(info->type, "w83791d", I2C_NAME_SIZE);
return 0;
}
static int w83791d_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct w83791d_data *data;
struct device *dev = &client->dev;
int i, err;
u8 has_fanpwm45;
#ifdef DEBUG
int val1;
val1 = w83791d_read(client, W83791D_REG_DID_VID4);
dev_dbg(dev, "Device ID version: %d.%d (0x%02x)\n",
(val1 >> 5) & 0x07, (val1 >> 1) & 0x0f, val1);
#endif
data = devm_kzalloc(&client->dev, sizeof(struct w83791d_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
err = w83791d_detect_subclients(client);
if (err)
return err;
w83791d_init_client(client);
for (i = 0; i < NUMBER_OF_FANIN; i++)
data->fan_min[i] = w83791d_read(client, W83791D_REG_FAN_MIN[i]);
err = sysfs_create_group(&client->dev.kobj, &w83791d_group);
if (err)
goto error3;
has_fanpwm45 = w83791d_read(client, W83791D_REG_GPIO) & 0x10;
if (has_fanpwm45) {
err = sysfs_create_group(&client->dev.kobj,
&w83791d_group_fanpwm45);
if (err)
goto error4;
}
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error5;
}
return 0;
error5:
if (has_fanpwm45)
sysfs_remove_group(&client->dev.kobj, &w83791d_group_fanpwm45);
error4:
sysfs_remove_group(&client->dev.kobj, &w83791d_group);
error3:
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1] != NULL)
i2c_unregister_device(data->lm75[1]);
return err;
}
static int w83791d_remove(struct i2c_client *client)
{
struct w83791d_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &w83791d_group);
if (data->lm75[0] != NULL)
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1] != NULL)
i2c_unregister_device(data->lm75[1]);
return 0;
}
static void w83791d_init_client(struct i2c_client *client)
{
struct w83791d_data *data = i2c_get_clientdata(client);
u8 tmp;
u8 old_beep;
if (reset || init) {
old_beep = w83791d_read(client, W83791D_REG_BEEP_CONFIG);
if (reset) {
w83791d_write(client, W83791D_REG_CONFIG, 0x80);
}
w83791d_write(client, W83791D_REG_BEEP_CONFIG, old_beep | 0x80);
tmp = w83791d_read(client, W83791D_REG_BEEP_CTRL[1]);
w83791d_write(client, W83791D_REG_BEEP_CTRL[1], tmp & 0xef);
if (init) {
tmp = w83791d_read(client, W83791D_REG_TEMP2_CONFIG);
if (tmp & 1) {
w83791d_write(client, W83791D_REG_TEMP2_CONFIG,
tmp & 0xfe);
}
tmp = w83791d_read(client, W83791D_REG_TEMP3_CONFIG);
if (tmp & 1) {
w83791d_write(client, W83791D_REG_TEMP3_CONFIG,
tmp & 0xfe);
}
tmp = w83791d_read(client, W83791D_REG_CONFIG) & 0xf7;
w83791d_write(client, W83791D_REG_CONFIG, tmp | 0x01);
}
}
data->vrm = vid_which_vrm();
}
static struct w83791d_data *w83791d_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct w83791d_data *data = i2c_get_clientdata(client);
int i, j;
u8 reg_array_tmp[3];
u8 vbat_reg;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + (HZ * 3))
|| !data->valid) {
dev_dbg(dev, "Starting w83791d device update\n");
for (i = 0; i < NUMBER_OF_VIN; i++) {
data->in[i] = w83791d_read(client,
W83791D_REG_IN[i]);
data->in_max[i] = w83791d_read(client,
W83791D_REG_IN_MAX[i]);
data->in_min[i] = w83791d_read(client,
W83791D_REG_IN_MIN[i]);
}
for (i = 0; i < NUMBER_OF_FANIN; i++) {
data->fan[i] = w83791d_read(client,
W83791D_REG_FAN[i]);
data->fan_min[i] = w83791d_read(client,
W83791D_REG_FAN_MIN[i]);
}
for (i = 0; i < 3; i++) {
reg_array_tmp[i] = w83791d_read(client,
W83791D_REG_FAN_DIV[i]);
}
data->fan_div[0] = (reg_array_tmp[0] >> 4) & 0x03;
data->fan_div[1] = (reg_array_tmp[0] >> 6) & 0x03;
data->fan_div[2] = (reg_array_tmp[1] >> 6) & 0x03;
data->fan_div[3] = reg_array_tmp[2] & 0x07;
data->fan_div[4] = (reg_array_tmp[2] >> 4) & 0x07;
vbat_reg = w83791d_read(client, W83791D_REG_VBAT);
for (i = 0; i < 3; i++)
data->fan_div[i] |= (vbat_reg >> (3 + i)) & 0x04;
for (i = 0; i < NUMBER_OF_PWM; i++) {
data->pwm[i] = w83791d_read(client,
W83791D_REG_PWM[i]);
}
for (i = 0; i < 2; i++) {
reg_array_tmp[i] = w83791d_read(client,
W83791D_REG_FAN_CFG[i]);
}
data->pwm_enable[0] = (reg_array_tmp[0] >> 2) & 0x03;
data->pwm_enable[1] = (reg_array_tmp[0] >> 4) & 0x03;
data->pwm_enable[2] = (reg_array_tmp[1] >> 2) & 0x03;
for (i = 0; i < 3; i++) {
data->temp_target[i] = w83791d_read(client,
W83791D_REG_TEMP_TARGET[i]) & 0x7f;
}
for (i = 0; i < 2; i++) {
reg_array_tmp[i] = w83791d_read(client,
W83791D_REG_TEMP_TOL[i]);
}
data->temp_tolerance[0] = reg_array_tmp[0] & 0x0f;
data->temp_tolerance[1] = (reg_array_tmp[0] >> 4) & 0x0f;
data->temp_tolerance[2] = reg_array_tmp[1] & 0x0f;
for (i = 0; i < 3; i++) {
data->temp1[i] = w83791d_read(client,
W83791D_REG_TEMP1[i]);
}
for (i = 0; i < 2; i++) {
for (j = 0; j < 3; j++) {
data->temp_add[i][j] =
(w83791d_read(client,
W83791D_REG_TEMP_ADD[i][j * 2]) << 8) |
w83791d_read(client,
W83791D_REG_TEMP_ADD[i][j * 2 + 1]);
}
}
data->alarms =
w83791d_read(client, W83791D_REG_ALARM1) +
(w83791d_read(client, W83791D_REG_ALARM2) << 8) +
(w83791d_read(client, W83791D_REG_ALARM3) << 16);
data->beep_mask =
w83791d_read(client, W83791D_REG_BEEP_CTRL[0]) +
(w83791d_read(client, W83791D_REG_BEEP_CTRL[1]) << 8) +
(w83791d_read(client, W83791D_REG_BEEP_CTRL[2]) << 16);
data->beep_enable =
(data->beep_mask >> GLOBAL_BEEP_ENABLE_SHIFT) & 0x01;
i = w83791d_read(client, W83791D_REG_VID_FANDIV);
data->vid = i & 0x0f;
data->vid |= (w83791d_read(client, W83791D_REG_DID_VID4) & 0x01)
<< 4;
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
#ifdef DEBUG
w83791d_print_debug(data, dev);
#endif
return data;
}
static void w83791d_print_debug(struct w83791d_data *data, struct device *dev)
{
int i = 0, j = 0;
dev_dbg(dev, "======Start of w83791d debug values======\n");
dev_dbg(dev, "%d set of Voltages: ===>\n", NUMBER_OF_VIN);
for (i = 0; i < NUMBER_OF_VIN; i++) {
dev_dbg(dev, "vin[%d] is: 0x%02x\n", i, data->in[i]);
dev_dbg(dev, "vin[%d] min is: 0x%02x\n", i, data->in_min[i]);
dev_dbg(dev, "vin[%d] max is: 0x%02x\n", i, data->in_max[i]);
}
dev_dbg(dev, "%d set of Fan Counts/Divisors: ===>\n", NUMBER_OF_FANIN);
for (i = 0; i < NUMBER_OF_FANIN; i++) {
dev_dbg(dev, "fan[%d] is: 0x%02x\n", i, data->fan[i]);
dev_dbg(dev, "fan[%d] min is: 0x%02x\n", i, data->fan_min[i]);
dev_dbg(dev, "fan_div[%d] is: 0x%02x\n", i, data->fan_div[i]);
}
dev_dbg(dev, "%d set of Temperatures: ===>\n", NUMBER_OF_TEMPIN);
for (i = 0; i < 3; i++)
dev_dbg(dev, "temp1[%d] is: 0x%02x\n", i, (u8) data->temp1[i]);
for (i = 0; i < 2; i++) {
for (j = 0; j < 3; j++) {
dev_dbg(dev, "temp_add[%d][%d] is: 0x%04x\n", i, j,
(u16) data->temp_add[i][j]);
}
}
dev_dbg(dev, "Misc Information: ===>\n");
dev_dbg(dev, "alarm is: 0x%08x\n", data->alarms);
dev_dbg(dev, "beep_mask is: 0x%08x\n", data->beep_mask);
dev_dbg(dev, "beep_enable is: %d\n", data->beep_enable);
dev_dbg(dev, "vid is: 0x%02x\n", data->vid);
dev_dbg(dev, "vrm is: 0x%02x\n", data->vrm);
dev_dbg(dev, "=======End of w83791d debug values========\n");
dev_dbg(dev, "\n");
}
