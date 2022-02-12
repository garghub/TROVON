static inline u8
FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 255;
rpm = clamp_val(rpm, 1, 1000000);
return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static inline long
FAN_FROM_REG(u8 val, int div)
{
if (val == 0)
return -1;
if (val == 255)
return 0;
return 1350000 / (val * div);
}
static inline u8
DIV_TO_REG(long val, enum chips type)
{
int i;
val = clamp_val(val, 1,
((type == w83781d || type == as99127f) ? 8 : 128)) >> 1;
for (i = 0; i < 7; i++) {
if (val == 0)
break;
val >>= 1;
}
return i;
}
static ssize_t
store_fan_min(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct w83781d_data *data = dev_get_drvdata(dev);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] =
FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
w83781d_write_value(data, W83781D_REG_FAN_MIN(nr),
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
cpu0_vid_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
return sprintf(buf, "%ld\n", (long) vid_from_reg(data->vid, data->vrm));
}
static ssize_t
vrm_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83781d_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%ld\n", (long) data->vrm);
}
static ssize_t
vrm_store(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct w83781d_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
data->vrm = clamp_val(val, 0, 255);
return count;
}
static ssize_t
alarms_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_temp3_alarm(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
int bitnr = (data->type == w83781d) ? 5 : 13;
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t beep_mask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
return sprintf(buf, "%ld\n",
(long)BEEP_MASK_FROM_REG(data->beep_mask, data->type));
}
static ssize_t
beep_mask_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83781d_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->beep_mask &= 0x8000;
data->beep_mask |= BEEP_MASK_TO_REG(val, data->type);
w83781d_write_value(data, W83781D_REG_BEEP_INTS1,
data->beep_mask & 0xff);
w83781d_write_value(data, W83781D_REG_BEEP_INTS2,
(data->beep_mask >> 8) & 0xff);
if (data->type != w83781d && data->type != as99127f) {
w83781d_write_value(data, W83781D_REG_BEEP_INTS3,
((data->beep_mask) >> 16) & 0xff);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u\n", (data->beep_mask >> bitnr) & 1);
}
static ssize_t
store_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83781d_data *data = dev_get_drvdata(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
u8 reg;
unsigned long bit;
int err;
err = kstrtoul(buf, 10, &bit);
if (err)
return err;
if (bit & ~1)
return -EINVAL;
mutex_lock(&data->update_lock);
if (bit)
data->beep_mask |= (1 << bitnr);
else
data->beep_mask &= ~(1 << bitnr);
if (bitnr < 8) {
reg = w83781d_read_value(data, W83781D_REG_BEEP_INTS1);
if (bit)
reg |= (1 << bitnr);
else
reg &= ~(1 << bitnr);
w83781d_write_value(data, W83781D_REG_BEEP_INTS1, reg);
} else if (bitnr < 16) {
reg = w83781d_read_value(data, W83781D_REG_BEEP_INTS2);
if (bit)
reg |= (1 << (bitnr - 8));
else
reg &= ~(1 << (bitnr - 8));
w83781d_write_value(data, W83781D_REG_BEEP_INTS2, reg);
} else {
reg = w83781d_read_value(data, W83781D_REG_BEEP_INTS3);
if (bit)
reg |= (1 << (bitnr - 16));
else
reg &= ~(1 << (bitnr - 16));
w83781d_write_value(data, W83781D_REG_BEEP_INTS3, reg);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp3_beep(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
int bitnr = (data->type == w83781d) ? 5 : 13;
return sprintf(buf, "%u\n", (data->beep_mask >> bitnr) & 1);
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct w83781d_data *data = w83781d_update_device(dev);
return sprintf(buf, "%ld\n",
(long) DIV_FROM_REG(data->fan_div[attr->index]));
}
static ssize_t
store_fan_div(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct w83781d_data *data = dev_get_drvdata(dev);
unsigned long min;
int nr = attr->index;
u8 reg;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr]));
data->fan_div[nr] = DIV_TO_REG(val, data->type);
reg = (w83781d_read_value(data, nr == 2 ?
W83781D_REG_PIN : W83781D_REG_VID_FANDIV)
& (nr == 0 ? 0xcf : 0x3f))
| ((data->fan_div[nr] & 0x03) << (nr == 0 ? 4 : 6));
w83781d_write_value(data, nr == 2 ?
W83781D_REG_PIN : W83781D_REG_VID_FANDIV, reg);
if (data->type != w83781d && data->type != as99127f) {
reg = (w83781d_read_value(data, W83781D_REG_VBAT)
& ~(1 << (5 + nr)))
| ((data->fan_div[nr] & 0x04) << (3 + nr));
w83781d_write_value(data, W83781D_REG_VBAT, reg);
}
data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
w83781d_write_value(data, W83781D_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm(struct device *dev, struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct w83781d_data *data = w83781d_update_device(dev);
return sprintf(buf, "%d\n", (int)data->pwm[attr->index]);
}
static ssize_t
pwm2_enable_show(struct device *dev, struct device_attribute *da, char *buf)
{
struct w83781d_data *data = w83781d_update_device(dev);
return sprintf(buf, "%d\n", (int)data->pwm2_enable);
}
static ssize_t
store_pwm(struct device *dev, struct device_attribute *da, const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct w83781d_data *data = dev_get_drvdata(dev);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->pwm[nr] = clamp_val(val, 0, 255);
w83781d_write_value(data, W83781D_REG_PWM[nr], data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
pwm2_enable_store(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct w83781d_data *data = dev_get_drvdata(dev);
unsigned long val;
u32 reg;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
switch (val) {
case 0:
case 1:
reg = w83781d_read_value(data, W83781D_REG_PWMCLK12);
w83781d_write_value(data, W83781D_REG_PWMCLK12,
(reg & 0xf7) | (val << 3));
reg = w83781d_read_value(data, W83781D_REG_BEEP_CONFIG);
w83781d_write_value(data, W83781D_REG_BEEP_CONFIG,
(reg & 0xef) | (!val << 4));
data->pwm2_enable = val;
break;
default:
mutex_unlock(&data->update_lock);
return -EINVAL;
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_sensor(struct device *dev, struct device_attribute *da, char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct w83781d_data *data = w83781d_update_device(dev);
return sprintf(buf, "%d\n", (int)data->sens[attr->index]);
}
static ssize_t
store_sensor(struct device *dev, struct device_attribute *da,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
struct w83781d_data *data = dev_get_drvdata(dev);
int nr = attr->index;
unsigned long val;
u32 tmp;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
switch (val) {
case 1:
tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
w83781d_write_value(data, W83781D_REG_SCFG1,
tmp | BIT_SCFG1[nr]);
tmp = w83781d_read_value(data, W83781D_REG_SCFG2);
w83781d_write_value(data, W83781D_REG_SCFG2,
tmp | BIT_SCFG2[nr]);
data->sens[nr] = val;
break;
case 2:
tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
w83781d_write_value(data, W83781D_REG_SCFG1,
tmp | BIT_SCFG1[nr]);
tmp = w83781d_read_value(data, W83781D_REG_SCFG2);
w83781d_write_value(data, W83781D_REG_SCFG2,
tmp & ~BIT_SCFG2[nr]);
data->sens[nr] = val;
break;
case W83781D_DEFAULT_BETA:
dev_warn(dev,
"Sensor type %d is deprecated, please use 4 instead\n",
W83781D_DEFAULT_BETA);
case 4:
tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
w83781d_write_value(data, W83781D_REG_SCFG1,
tmp & ~BIT_SCFG1[nr]);
data->sens[nr] = val;
break;
default:
dev_err(dev, "Invalid sensor type %ld; must be 1, 2, or 4\n",
(long) val);
break;
}
mutex_unlock(&data->update_lock);
return count;
}
static int
w83781d_detect_subclients(struct i2c_client *new_client)
{
int i, val1 = 0, id;
int err;
int address = new_client->addr;
unsigned short sc_addr[2];
struct i2c_adapter *adapter = new_client->adapter;
struct w83781d_data *data = i2c_get_clientdata(new_client);
enum chips kind = data->type;
int num_sc = 1;
id = i2c_adapter_id(adapter);
if (force_subclients[0] == id && force_subclients[1] == address) {
for (i = 2; i <= 3; i++) {
if (force_subclients[i] < 0x48 ||
force_subclients[i] > 0x4f) {
dev_err(&new_client->dev,
"Invalid subclient address %d; must be 0x48-0x4f\n",
force_subclients[i]);
err = -EINVAL;
goto ERROR_SC_1;
}
}
w83781d_write_value(data, W83781D_REG_I2C_SUBADDR,
(force_subclients[2] & 0x07) |
((force_subclients[3] & 0x07) << 4));
sc_addr[0] = force_subclients[2];
} else {
val1 = w83781d_read_value(data, W83781D_REG_I2C_SUBADDR);
sc_addr[0] = 0x48 + (val1 & 0x07);
}
if (kind != w83783s) {
num_sc = 2;
if (force_subclients[0] == id &&
force_subclients[1] == address) {
sc_addr[1] = force_subclients[3];
} else {
sc_addr[1] = 0x48 + ((val1 >> 4) & 0x07);
}
if (sc_addr[0] == sc_addr[1]) {
dev_err(&new_client->dev,
"Duplicate addresses 0x%x for subclients.\n",
sc_addr[0]);
err = -EBUSY;
goto ERROR_SC_2;
}
}
for (i = 0; i < num_sc; i++) {
data->lm75[i] = i2c_new_dummy(adapter, sc_addr[i]);
if (!data->lm75[i]) {
dev_err(&new_client->dev,
"Subclient %d registration at address 0x%x failed.\n",
i, sc_addr[i]);
err = -ENOMEM;
if (i == 1)
goto ERROR_SC_3;
goto ERROR_SC_2;
}
}
return 0;
ERROR_SC_3:
i2c_unregister_device(data->lm75[0]);
ERROR_SC_2:
ERROR_SC_1:
return err;
}
static int
w83781d_create_files(struct device *dev, int kind, int is_isa)
{
int err;
err = sysfs_create_group(&dev->kobj, &w83781d_group);
if (err)
return err;
if (kind != w83783s) {
err = sysfs_create_group(&dev->kobj, &w83781d_group_in1);
if (err)
return err;
}
if (kind != as99127f && kind != w83781d && kind != w83783s) {
err = sysfs_create_group(&dev->kobj, &w83781d_group_in78);
if (err)
return err;
}
if (kind != w83783s) {
err = sysfs_create_group(&dev->kobj, &w83781d_group_temp3);
if (err)
return err;
if (kind != w83781d) {
err = sysfs_chmod_file(&dev->kobj,
&sensor_dev_attr_temp3_alarm.dev_attr.attr,
S_IRUGO | S_IWUSR);
if (err)
return err;
}
}
if (kind != w83781d && kind != as99127f) {
err = sysfs_create_group(&dev->kobj, &w83781d_group_pwm12);
if (err)
return err;
}
if (kind == w83782d && !is_isa) {
err = sysfs_create_group(&dev->kobj, &w83781d_group_pwm34);
if (err)
return err;
}
if (kind != as99127f && kind != w83781d) {
err = device_create_file(dev,
&sensor_dev_attr_temp1_type.dev_attr);
if (err)
return err;
err = device_create_file(dev,
&sensor_dev_attr_temp2_type.dev_attr);
if (err)
return err;
if (kind != w83783s) {
err = device_create_file(dev,
&sensor_dev_attr_temp3_type.dev_attr);
if (err)
return err;
}
}
return 0;
}
static int
w83781d_detect(struct i2c_client *client, struct i2c_board_info *info)
{
int val1, val2;
struct w83781d_data *isa = w83781d_data_if_isa();
struct i2c_adapter *adapter = client->adapter;
int address = client->addr;
const char *client_name;
enum vendor { winbond, asus } vendid;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
if (isa)
mutex_lock(&isa->update_lock);
if (i2c_smbus_read_byte_data(client, W83781D_REG_CONFIG) & 0x80) {
dev_dbg(&adapter->dev,
"Detection of w83781d chip failed at step 3\n");
goto err_nodev;
}
val1 = i2c_smbus_read_byte_data(client, W83781D_REG_BANK);
val2 = i2c_smbus_read_byte_data(client, W83781D_REG_CHIPMAN);
if (!(val1 & 0x07) &&
((!(val1 & 0x80) && val2 != 0xa3 && val2 != 0xc3) ||
((val1 & 0x80) && val2 != 0x5c && val2 != 0x12))) {
dev_dbg(&adapter->dev,
"Detection of w83781d chip failed at step 4\n");
goto err_nodev;
}
if ((!(val1 & 0x80) && val2 == 0xa3) ||
((val1 & 0x80) && val2 == 0x5c)) {
if (i2c_smbus_read_byte_data(client, W83781D_REG_I2C_ADDR)
!= address) {
dev_dbg(&adapter->dev,
"Detection of w83781d chip failed at step 5\n");
goto err_nodev;
}
}
i2c_smbus_write_byte_data(client, W83781D_REG_BANK,
(i2c_smbus_read_byte_data(client, W83781D_REG_BANK)
& 0x78) | 0x80);
val2 = i2c_smbus_read_byte_data(client, W83781D_REG_CHIPMAN);
if (val2 == 0x5c)
vendid = winbond;
else if (val2 == 0x12)
vendid = asus;
else {
dev_dbg(&adapter->dev,
"w83781d chip vendor is neither Winbond nor Asus\n");
goto err_nodev;
}
val1 = i2c_smbus_read_byte_data(client, W83781D_REG_WCHIPID);
if ((val1 == 0x10 || val1 == 0x11) && vendid == winbond)
client_name = "w83781d";
else if (val1 == 0x30 && vendid == winbond)
client_name = "w83782d";
else if (val1 == 0x40 && vendid == winbond && address == 0x2d)
client_name = "w83783s";
else if (val1 == 0x31)
client_name = "as99127f";
else
goto err_nodev;
if (val1 <= 0x30 && w83781d_alias_detect(client, val1)) {
dev_dbg(&adapter->dev,
"Device at 0x%02x appears to be the same as ISA device\n",
address);
goto err_nodev;
}
if (isa)
mutex_unlock(&isa->update_lock);
strlcpy(info->type, client_name, I2C_NAME_SIZE);
return 0;
err_nodev:
if (isa)
mutex_unlock(&isa->update_lock);
return -ENODEV;
}
static void w83781d_remove_files(struct device *dev)
{
sysfs_remove_group(&dev->kobj, &w83781d_group);
sysfs_remove_group(&dev->kobj, &w83781d_group_in1);
sysfs_remove_group(&dev->kobj, &w83781d_group_in78);
sysfs_remove_group(&dev->kobj, &w83781d_group_temp3);
sysfs_remove_group(&dev->kobj, &w83781d_group_pwm12);
sysfs_remove_group(&dev->kobj, &w83781d_group_pwm34);
sysfs_remove_group(&dev->kobj, &w83781d_group_other);
}
static int
w83781d_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct w83781d_data *data;
int err;
data = devm_kzalloc(dev, sizeof(struct w83781d_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->lock);
mutex_init(&data->update_lock);
data->type = id->driver_data;
data->client = client;
err = w83781d_detect_subclients(client);
if (err)
return err;
w83781d_init_device(dev);
err = w83781d_create_files(dev, data->type, 0);
if (err)
goto exit_remove_files;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
w83781d_remove_files(dev);
if (data->lm75[0])
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1])
i2c_unregister_device(data->lm75[1]);
return err;
}
static int
w83781d_remove(struct i2c_client *client)
{
struct w83781d_data *data = i2c_get_clientdata(client);
struct device *dev = &client->dev;
hwmon_device_unregister(data->hwmon_dev);
w83781d_remove_files(dev);
if (data->lm75[0])
i2c_unregister_device(data->lm75[0]);
if (data->lm75[1])
i2c_unregister_device(data->lm75[1]);
return 0;
}
static int
w83781d_read_value_i2c(struct w83781d_data *data, u16 reg)
{
struct i2c_client *client = data->client;
int res, bank;
struct i2c_client *cl;
bank = (reg >> 8) & 0x0f;
if (bank > 2)
i2c_smbus_write_byte_data(client, W83781D_REG_BANK,
bank);
if (bank == 0 || bank > 2) {
res = i2c_smbus_read_byte_data(client, reg & 0xff);
} else {
cl = data->lm75[bank - 1];
switch (reg & 0xff) {
case 0x50:
res = i2c_smbus_read_word_swapped(cl, 0);
break;
case 0x52:
res = i2c_smbus_read_byte_data(cl, 1);
break;
case 0x53:
res = i2c_smbus_read_word_swapped(cl, 2);
break;
case 0x55:
default:
res = i2c_smbus_read_word_swapped(cl, 3);
break;
}
}
if (bank > 2)
i2c_smbus_write_byte_data(client, W83781D_REG_BANK, 0);
return res;
}
static int
w83781d_write_value_i2c(struct w83781d_data *data, u16 reg, u16 value)
{
struct i2c_client *client = data->client;
int bank;
struct i2c_client *cl;
bank = (reg >> 8) & 0x0f;
if (bank > 2)
i2c_smbus_write_byte_data(client, W83781D_REG_BANK,
bank);
if (bank == 0 || bank > 2) {
i2c_smbus_write_byte_data(client, reg & 0xff,
value & 0xff);
} else {
cl = data->lm75[bank - 1];
switch (reg & 0xff) {
case 0x52:
i2c_smbus_write_byte_data(cl, 1, value & 0xff);
break;
case 0x53:
i2c_smbus_write_word_swapped(cl, 2, value);
break;
case 0x55:
i2c_smbus_write_word_swapped(cl, 3, value);
break;
}
}
if (bank > 2)
i2c_smbus_write_byte_data(client, W83781D_REG_BANK, 0);
return 0;
}
static void
w83781d_init_device(struct device *dev)
{
struct w83781d_data *data = dev_get_drvdata(dev);
int i, p;
int type = data->type;
u8 tmp;
if (reset && type != as99127f) {
dev_info(dev,
"If reset=1 solved a problem you were having, please report!\n");
i = w83781d_read_value(data, W83781D_REG_BEEP_CONFIG);
p = w83781d_read_value(data, W83781D_REG_PWMCLK12);
w83781d_write_value(data, W83781D_REG_CONFIG, 0x80);
w83781d_write_value(data, W83781D_REG_BEEP_CONFIG, i | 0x80);
w83781d_write_value(data, W83781D_REG_PWMCLK12, p);
w83781d_write_value(data, W83781D_REG_BEEP_INTS2, 0);
}
if (init && !reset && type != as99127f) {
i = w83781d_read_value(data, W83781D_REG_BEEP_CONFIG);
w83781d_write_value(data, W83781D_REG_BEEP_CONFIG, i | 0x80);
}
data->vrm = vid_which_vrm();
if ((type != w83781d) && (type != as99127f)) {
tmp = w83781d_read_value(data, W83781D_REG_SCFG1);
for (i = 1; i <= 3; i++) {
if (!(tmp & BIT_SCFG1[i - 1])) {
data->sens[i - 1] = 4;
} else {
if (w83781d_read_value
(data,
W83781D_REG_SCFG2) & BIT_SCFG2[i - 1])
data->sens[i - 1] = 1;
else
data->sens[i - 1] = 2;
}
if (type == w83783s && i == 2)
break;
}
}
if (init && type != as99127f) {
tmp = w83781d_read_value(data, W83781D_REG_TEMP2_CONFIG);
if (tmp & 0x01) {
dev_warn(dev,
"Enabling temp2, readings might not make sense\n");
w83781d_write_value(data, W83781D_REG_TEMP2_CONFIG,
tmp & 0xfe);
}
if (type != w83783s) {
tmp = w83781d_read_value(data,
W83781D_REG_TEMP3_CONFIG);
if (tmp & 0x01) {
dev_warn(dev,
"Enabling temp3, readings might not make sense\n");
w83781d_write_value(data,
W83781D_REG_TEMP3_CONFIG, tmp & 0xfe);
}
}
}
w83781d_write_value(data, W83781D_REG_CONFIG,
(w83781d_read_value(data,
W83781D_REG_CONFIG) & 0xf7)
| 0x01);
for (i = 0; i < 3; i++) {
data->fan_min[i] = w83781d_read_value(data,
W83781D_REG_FAN_MIN(i));
}
mutex_init(&data->update_lock);
}
static struct w83781d_data *w83781d_update_device(struct device *dev)
{
struct w83781d_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
dev_dbg(dev, "Starting device update\n");
for (i = 0; i <= 8; i++) {
if (data->type == w83783s && i == 1)
continue;
data->in[i] =
w83781d_read_value(data, W83781D_REG_IN(i));
data->in_min[i] =
w83781d_read_value(data, W83781D_REG_IN_MIN(i));
data->in_max[i] =
w83781d_read_value(data, W83781D_REG_IN_MAX(i));
if ((data->type != w83782d) && (i == 6))
break;
}
for (i = 0; i < 3; i++) {
data->fan[i] =
w83781d_read_value(data, W83781D_REG_FAN(i));
data->fan_min[i] =
w83781d_read_value(data, W83781D_REG_FAN_MIN(i));
}
if (data->type != w83781d && data->type != as99127f) {
for (i = 0; i < 4; i++) {
data->pwm[i] =
w83781d_read_value(data,
W83781D_REG_PWM[i]);
if ((data->type != w83782d || !client)
&& i == 1)
break;
}
data->pwm2_enable = (w83781d_read_value(data,
W83781D_REG_PWMCLK12) & 0x08) >> 3;
}
data->temp = w83781d_read_value(data, W83781D_REG_TEMP(1));
data->temp_max =
w83781d_read_value(data, W83781D_REG_TEMP_OVER(1));
data->temp_max_hyst =
w83781d_read_value(data, W83781D_REG_TEMP_HYST(1));
data->temp_add[0] =
w83781d_read_value(data, W83781D_REG_TEMP(2));
data->temp_max_add[0] =
w83781d_read_value(data, W83781D_REG_TEMP_OVER(2));
data->temp_max_hyst_add[0] =
w83781d_read_value(data, W83781D_REG_TEMP_HYST(2));
if (data->type != w83783s) {
data->temp_add[1] =
w83781d_read_value(data, W83781D_REG_TEMP(3));
data->temp_max_add[1] =
w83781d_read_value(data,
W83781D_REG_TEMP_OVER(3));
data->temp_max_hyst_add[1] =
w83781d_read_value(data,
W83781D_REG_TEMP_HYST(3));
}
i = w83781d_read_value(data, W83781D_REG_VID_FANDIV);
data->vid = i & 0x0f;
data->vid |= (w83781d_read_value(data,
W83781D_REG_CHIPID) & 0x01) << 4;
data->fan_div[0] = (i >> 4) & 0x03;
data->fan_div[1] = (i >> 6) & 0x03;
data->fan_div[2] = (w83781d_read_value(data,
W83781D_REG_PIN) >> 6) & 0x03;
if ((data->type != w83781d) && (data->type != as99127f)) {
i = w83781d_read_value(data, W83781D_REG_VBAT);
data->fan_div[0] |= (i >> 3) & 0x04;
data->fan_div[1] |= (i >> 4) & 0x04;
data->fan_div[2] |= (i >> 5) & 0x04;
}
if (data->type == w83782d) {
data->alarms = w83781d_read_value(data,
W83782D_REG_ALARM1)
| (w83781d_read_value(data,
W83782D_REG_ALARM2) << 8)
| (w83781d_read_value(data,
W83782D_REG_ALARM3) << 16);
} else if (data->type == w83783s) {
data->alarms = w83781d_read_value(data,
W83782D_REG_ALARM1)
| (w83781d_read_value(data,
W83782D_REG_ALARM2) << 8);
} else {
data->alarms = w83781d_read_value(data,
W83781D_REG_ALARM1)
| (w83781d_read_value(data,
W83781D_REG_ALARM2) << 8);
}
i = w83781d_read_value(data, W83781D_REG_BEEP_INTS2);
data->beep_mask = (i << 8) +
w83781d_read_value(data, W83781D_REG_BEEP_INTS1);
if ((data->type != w83781d) && (data->type != as99127f)) {
data->beep_mask |=
w83781d_read_value(data,
W83781D_REG_BEEP_INTS3) << 16;
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t
name_show(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct w83781d_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static struct w83781d_data *w83781d_data_if_isa(void)
{
return pdev ? platform_get_drvdata(pdev) : NULL;
}
static int w83781d_alias_detect(struct i2c_client *client, u8 chipid)
{
struct w83781d_data *isa;
int i;
if (!pdev)
return 0;
isa = platform_get_drvdata(pdev);
if (w83781d_read_value(isa, W83781D_REG_I2C_ADDR) != client->addr)
return 0;
if (w83781d_read_value(isa, W83781D_REG_WCHIPID) != chipid)
return 0;
for (i = 0x2b; i <= 0x3d; i++) {
if (w83781d_read_value(isa, i) !=
i2c_smbus_read_byte_data(client, i))
return 0;
}
if (w83781d_read_value(isa, W83781D_REG_CONFIG) !=
i2c_smbus_read_byte_data(client, W83781D_REG_CONFIG))
return 0;
for (i = 0x43; i <= 0x46; i++) {
if (w83781d_read_value(isa, i) !=
i2c_smbus_read_byte_data(client, i))
return 0;
}
return 1;
}
static int
w83781d_read_value_isa(struct w83781d_data *data, u16 reg)
{
int word_sized, res;
word_sized = (((reg & 0xff00) == 0x100)
|| ((reg & 0xff00) == 0x200))
&& (((reg & 0x00ff) == 0x50)
|| ((reg & 0x00ff) == 0x53)
|| ((reg & 0x00ff) == 0x55));
if (reg & 0xff00) {
outb_p(W83781D_REG_BANK,
data->isa_addr + W83781D_ADDR_REG_OFFSET);
outb_p(reg >> 8,
data->isa_addr + W83781D_DATA_REG_OFFSET);
}
outb_p(reg & 0xff, data->isa_addr + W83781D_ADDR_REG_OFFSET);
res = inb_p(data->isa_addr + W83781D_DATA_REG_OFFSET);
if (word_sized) {
outb_p((reg & 0xff) + 1,
data->isa_addr + W83781D_ADDR_REG_OFFSET);
res =
(res << 8) + inb_p(data->isa_addr +
W83781D_DATA_REG_OFFSET);
}
if (reg & 0xff00) {
outb_p(W83781D_REG_BANK,
data->isa_addr + W83781D_ADDR_REG_OFFSET);
outb_p(0, data->isa_addr + W83781D_DATA_REG_OFFSET);
}
return res;
}
static void
w83781d_write_value_isa(struct w83781d_data *data, u16 reg, u16 value)
{
int word_sized;
word_sized = (((reg & 0xff00) == 0x100)
|| ((reg & 0xff00) == 0x200))
&& (((reg & 0x00ff) == 0x53)
|| ((reg & 0x00ff) == 0x55));
if (reg & 0xff00) {
outb_p(W83781D_REG_BANK,
data->isa_addr + W83781D_ADDR_REG_OFFSET);
outb_p(reg >> 8,
data->isa_addr + W83781D_DATA_REG_OFFSET);
}
outb_p(reg & 0xff, data->isa_addr + W83781D_ADDR_REG_OFFSET);
if (word_sized) {
outb_p(value >> 8,
data->isa_addr + W83781D_DATA_REG_OFFSET);
outb_p((reg & 0xff) + 1,
data->isa_addr + W83781D_ADDR_REG_OFFSET);
}
outb_p(value & 0xff, data->isa_addr + W83781D_DATA_REG_OFFSET);
if (reg & 0xff00) {
outb_p(W83781D_REG_BANK,
data->isa_addr + W83781D_ADDR_REG_OFFSET);
outb_p(0, data->isa_addr + W83781D_DATA_REG_OFFSET);
}
}
static int
w83781d_read_value(struct w83781d_data *data, u16 reg)
{
struct i2c_client *client = data->client;
int res;
mutex_lock(&data->lock);
if (client)
res = w83781d_read_value_i2c(data, reg);
else
res = w83781d_read_value_isa(data, reg);
mutex_unlock(&data->lock);
return res;
}
static int
w83781d_write_value(struct w83781d_data *data, u16 reg, u16 value)
{
struct i2c_client *client = data->client;
mutex_lock(&data->lock);
if (client)
w83781d_write_value_i2c(data, reg, value);
else
w83781d_write_value_isa(data, reg, value);
mutex_unlock(&data->lock);
return 0;
}
static int
w83781d_isa_probe(struct platform_device *pdev)
{
int err, reg;
struct w83781d_data *data;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(&pdev->dev,
res->start + W83781D_ADDR_REG_OFFSET, 2,
"w83781d"))
return -EBUSY;
data = devm_kzalloc(&pdev->dev, sizeof(struct w83781d_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
mutex_init(&data->lock);
data->isa_addr = res->start;
platform_set_drvdata(pdev, data);
reg = w83781d_read_value(data, W83781D_REG_WCHIPID);
switch (reg) {
case 0x30:
data->type = w83782d;
data->name = "w83782d";
break;
default:
data->type = w83781d;
data->name = "w83781d";
}
w83781d_init_device(&pdev->dev);
err = w83781d_create_files(&pdev->dev, data->type, 1);
if (err)
goto exit_remove_files;
err = device_create_file(&pdev->dev, &dev_attr_name);
if (err)
goto exit_remove_files;
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove_files;
}
return 0;
exit_remove_files:
w83781d_remove_files(&pdev->dev);
device_remove_file(&pdev->dev, &dev_attr_name);
return err;
}
static int
w83781d_isa_remove(struct platform_device *pdev)
{
struct w83781d_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
w83781d_remove_files(&pdev->dev);
device_remove_file(&pdev->dev, &dev_attr_name);
return 0;
}
static int __init
w83781d_isa_found(unsigned short address)
{
int val, save, found = 0;
int port;
for (port = address; port < address + W83781D_EXTENT; port++) {
if (!request_region(port, 1, "w83781d")) {
pr_debug("Failed to request port 0x%x\n", port);
goto release;
}
}
#define REALLY_SLOW_IO
val = inb_p(address + 1);
if (inb_p(address + 2) != val
|| inb_p(address + 3) != val
|| inb_p(address + 7) != val) {
pr_debug("Detection failed at step %d\n", 1);
goto release;
}
#undef REALLY_SLOW_IO
save = inb_p(address + W83781D_ADDR_REG_OFFSET);
if (save & 0x80) {
pr_debug("Detection failed at step %d\n", 2);
goto release;
}
val = ~save & 0x7f;
outb_p(val, address + W83781D_ADDR_REG_OFFSET);
if (inb_p(address + W83781D_ADDR_REG_OFFSET) != (val | 0x80)) {
outb_p(save, address + W83781D_ADDR_REG_OFFSET);
pr_debug("Detection failed at step %d\n", 3);
goto release;
}
outb_p(W83781D_REG_CONFIG, address + W83781D_ADDR_REG_OFFSET);
val = inb_p(address + W83781D_DATA_REG_OFFSET);
if (val & 0x80) {
pr_debug("Detection failed at step %d\n", 4);
goto release;
}
outb_p(W83781D_REG_BANK, address + W83781D_ADDR_REG_OFFSET);
save = inb_p(address + W83781D_DATA_REG_OFFSET);
outb_p(W83781D_REG_CHIPMAN, address + W83781D_ADDR_REG_OFFSET);
val = inb_p(address + W83781D_DATA_REG_OFFSET);
if ((!(save & 0x80) && (val != 0xa3))
|| ((save & 0x80) && (val != 0x5c))) {
pr_debug("Detection failed at step %d\n", 5);
goto release;
}
outb_p(W83781D_REG_I2C_ADDR, address + W83781D_ADDR_REG_OFFSET);
val = inb_p(address + W83781D_DATA_REG_OFFSET);
if (val < 0x03 || val > 0x77) {
pr_debug("Detection failed at step %d\n", 6);
goto release;
}
if (inb_p(address + W83781D_ADDR_REG_OFFSET) & 0x80) {
pr_debug("Detection failed at step %d\n", 7);
goto release;
}
outb_p(W83781D_REG_BANK, address + W83781D_ADDR_REG_OFFSET);
save = inb_p(address + W83781D_DATA_REG_OFFSET);
outb_p(save & 0xf8, address + W83781D_DATA_REG_OFFSET);
outb_p(W83781D_REG_WCHIPID, address + W83781D_ADDR_REG_OFFSET);
val = inb_p(address + W83781D_DATA_REG_OFFSET);
if ((val & 0xfe) == 0x10
|| val == 0x30)
found = 1;
if (found)
pr_info("Found a %s chip at %#x\n",
val == 0x30 ? "W83782D" : "W83781D", (int)address);
release:
for (port--; port >= address; port--)
release_region(port, 1);
return found;
}
static int __init
w83781d_isa_device_add(unsigned short address)
{
struct resource res = {
.start = address,
.end = address + W83781D_EXTENT - 1,
.name = "w83781d",
.flags = IORESOURCE_IO,
};
int err;
pdev = platform_device_alloc("w83781d", address);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
err = platform_device_add_resources(pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_device_add(pdev);
if (err) {
pr_err("Device addition failed (%d)\n", err);
goto exit_device_put;
}
return 0;
exit_device_put:
platform_device_put(pdev);
exit:
pdev = NULL;
return err;
}
static int __init
w83781d_isa_register(void)
{
int res;
if (w83781d_isa_found(isa_address)) {
res = platform_driver_register(&w83781d_isa_driver);
if (res)
goto exit;
res = w83781d_isa_device_add(isa_address);
if (res)
goto exit_unreg_isa_driver;
}
return 0;
exit_unreg_isa_driver:
platform_driver_unregister(&w83781d_isa_driver);
exit:
return res;
}
static void
w83781d_isa_unregister(void)
{
if (pdev) {
platform_device_unregister(pdev);
platform_driver_unregister(&w83781d_isa_driver);
}
}
static struct w83781d_data *w83781d_data_if_isa(void)
{
return NULL;
}
static int
w83781d_alias_detect(struct i2c_client *client, u8 chipid)
{
return 0;
}
static int
w83781d_read_value(struct w83781d_data *data, u16 reg)
{
int res;
mutex_lock(&data->lock);
res = w83781d_read_value_i2c(data, reg);
mutex_unlock(&data->lock);
return res;
}
static int
w83781d_write_value(struct w83781d_data *data, u16 reg, u16 value)
{
mutex_lock(&data->lock);
w83781d_write_value_i2c(data, reg, value);
mutex_unlock(&data->lock);
return 0;
}
static int __init
w83781d_isa_register(void)
{
return 0;
}
static void
w83781d_isa_unregister(void)
{
}
static int __init
sensors_w83781d_init(void)
{
int res;
res = w83781d_isa_register();
if (res)
goto exit;
res = i2c_add_driver(&w83781d_driver);
if (res)
goto exit_unreg_isa;
return 0;
exit_unreg_isa:
w83781d_isa_unregister();
exit:
return res;
}
static void __exit
sensors_w83781d_exit(void)
{
w83781d_isa_unregister();
i2c_del_driver(&w83781d_driver);
}
