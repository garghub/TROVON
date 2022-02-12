static struct amc6821_data *amc6821_update_device(struct device *dev)
{
struct amc6821_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int timeout = HZ;
u8 reg;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + timeout) ||
!data->valid) {
for (i = 0; i < TEMP_IDX_LEN; i++)
data->temp[i] = (int8_t)i2c_smbus_read_byte_data(
client, temp_reg[i]);
data->stat1 = i2c_smbus_read_byte_data(client,
AMC6821_REG_STAT1);
data->stat2 = i2c_smbus_read_byte_data(client,
AMC6821_REG_STAT2);
data->pwm1 = i2c_smbus_read_byte_data(client,
AMC6821_REG_DCY);
for (i = 0; i < FAN1_IDX_LEN; i++) {
data->fan[i] = i2c_smbus_read_byte_data(
client,
fan_reg_low[i]);
data->fan[i] += i2c_smbus_read_byte_data(
client,
fan_reg_hi[i]) << 8;
}
data->fan1_div = i2c_smbus_read_byte_data(client,
AMC6821_REG_CONF4);
data->fan1_div = data->fan1_div & AMC6821_CONF4_PSPR ? 4 : 2;
data->pwm1_auto_point_pwm[0] = 0;
data->pwm1_auto_point_pwm[2] = 255;
data->pwm1_auto_point_pwm[1] = i2c_smbus_read_byte_data(client,
AMC6821_REG_DCY_LOW_TEMP);
data->temp1_auto_point_temp[0] =
i2c_smbus_read_byte_data(client,
AMC6821_REG_PSV_TEMP);
data->temp2_auto_point_temp[0] =
data->temp1_auto_point_temp[0];
reg = i2c_smbus_read_byte_data(client,
AMC6821_REG_LTEMP_FAN_CTRL);
data->temp1_auto_point_temp[1] = (reg & 0xF8) >> 1;
reg &= 0x07;
reg = 0x20 >> reg;
if (reg > 0)
data->temp1_auto_point_temp[2] =
data->temp1_auto_point_temp[1] +
(data->pwm1_auto_point_pwm[2] -
data->pwm1_auto_point_pwm[1]) / reg;
else
data->temp1_auto_point_temp[2] = 255;
reg = i2c_smbus_read_byte_data(client,
AMC6821_REG_RTEMP_FAN_CTRL);
data->temp2_auto_point_temp[1] = (reg & 0xF8) >> 1;
reg &= 0x07;
reg = 0x20 >> reg;
if (reg > 0)
data->temp2_auto_point_temp[2] =
data->temp2_auto_point_temp[1] +
(data->pwm1_auto_point_pwm[2] -
data->pwm1_auto_point_pwm[1]) / reg;
else
data->temp2_auto_point_temp[2] = 255;
reg = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF1);
reg = (reg >> 5) & 0x3;
switch (reg) {
case 0:
data->pwm1_auto_channels_temp = 0;
data->pwm1_enable = 1;
break;
case 2:
data->pwm1_auto_channels_temp = 2;
data->pwm1_enable = 2;
break;
case 3:
data->pwm1_auto_channels_temp = 3;
data->pwm1_enable = 3;
break;
case 1:
data->pwm1_auto_channels_temp = 0;
data->pwm1_enable = 0;
break;
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t get_temp(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
int ix = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", data->temp[ix] * 1000);
}
static ssize_t set_temp(
struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct amc6821_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int ix = to_sensor_dev_attr(attr)->index;
long val;
int ret = kstrtol(buf, 10, &val);
if (ret)
return ret;
val = clamp_val(val / 1000, -128, 127);
mutex_lock(&data->update_lock);
data->temp[ix] = val;
if (i2c_smbus_write_byte_data(client, temp_reg[ix], data->temp[ix])) {
dev_err(&client->dev, "Register write error, aborting.\n");
count = -EIO;
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_temp_alarm(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
int ix = to_sensor_dev_attr(devattr)->index;
u8 flag;
switch (ix) {
case IDX_TEMP1_MIN:
flag = data->stat1 & AMC6821_STAT1_LTL;
break;
case IDX_TEMP1_MAX:
flag = data->stat1 & AMC6821_STAT1_LTH;
break;
case IDX_TEMP1_CRIT:
flag = data->stat2 & AMC6821_STAT2_LTC;
break;
case IDX_TEMP2_MIN:
flag = data->stat1 & AMC6821_STAT1_RTL;
break;
case IDX_TEMP2_MAX:
flag = data->stat1 & AMC6821_STAT1_RTH;
break;
case IDX_TEMP2_CRIT:
flag = data->stat2 & AMC6821_STAT2_RTC;
break;
default:
dev_dbg(dev, "Unknown attr->index (%d).\n", ix);
return -EINVAL;
}
if (flag)
return sprintf(buf, "1");
else
return sprintf(buf, "0");
}
static ssize_t get_temp2_fault(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
if (data->stat1 & AMC6821_STAT1_RTF)
return sprintf(buf, "1");
else
return sprintf(buf, "0");
}
static ssize_t get_pwm1(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
return sprintf(buf, "%d\n", data->pwm1);
}
static ssize_t set_pwm1(
struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct amc6821_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int ret = kstrtol(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&data->update_lock);
data->pwm1 = clamp_val(val , 0, 255);
i2c_smbus_write_byte_data(client, AMC6821_REG_DCY, data->pwm1);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_pwm1_enable(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
return sprintf(buf, "%d\n", data->pwm1_enable);
}
static ssize_t set_pwm1_enable(
struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct amc6821_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int config = kstrtol(buf, 10, &val);
if (config)
return config;
mutex_lock(&data->update_lock);
config = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF1);
if (config < 0) {
dev_err(&client->dev,
"Error reading configuration register, aborting.\n");
count = config;
goto unlock;
}
switch (val) {
case 1:
config &= ~AMC6821_CONF1_FDRC0;
config &= ~AMC6821_CONF1_FDRC1;
break;
case 2:
config &= ~AMC6821_CONF1_FDRC0;
config |= AMC6821_CONF1_FDRC1;
break;
case 3:
config |= AMC6821_CONF1_FDRC0;
config |= AMC6821_CONF1_FDRC1;
break;
default:
count = -EINVAL;
goto unlock;
}
if (i2c_smbus_write_byte_data(client, AMC6821_REG_CONF1, config)) {
dev_err(&client->dev,
"Configuration register write error, aborting.\n");
count = -EIO;
}
unlock:
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_pwm1_auto_channels_temp(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
return sprintf(buf, "%d\n", data->pwm1_auto_channels_temp);
}
static ssize_t get_temp_auto_point_temp(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int ix = to_sensor_dev_attr_2(devattr)->index;
int nr = to_sensor_dev_attr_2(devattr)->nr;
struct amc6821_data *data = amc6821_update_device(dev);
switch (nr) {
case 1:
return sprintf(buf, "%d\n",
data->temp1_auto_point_temp[ix] * 1000);
case 2:
return sprintf(buf, "%d\n",
data->temp2_auto_point_temp[ix] * 1000);
default:
dev_dbg(dev, "Unknown attr->nr (%d).\n", nr);
return -EINVAL;
}
}
static ssize_t get_pwm1_auto_point_pwm(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int ix = to_sensor_dev_attr(devattr)->index;
struct amc6821_data *data = amc6821_update_device(dev);
return sprintf(buf, "%d\n", data->pwm1_auto_point_pwm[ix]);
}
static inline ssize_t set_slope_register(struct i2c_client *client,
u8 reg,
u8 dpwm,
u8 *ptemp)
{
int dt;
u8 tmp;
dt = ptemp[2]-ptemp[1];
for (tmp = 4; tmp > 0; tmp--) {
if (dt * (0x20 >> tmp) >= dpwm)
break;
}
tmp |= (ptemp[1] & 0x7C) << 1;
if (i2c_smbus_write_byte_data(client,
reg, tmp)) {
dev_err(&client->dev, "Register write error, aborting.\n");
return -EIO;
}
return 0;
}
static ssize_t set_temp_auto_point_temp(
struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct amc6821_data *data = amc6821_update_device(dev);
struct i2c_client *client = data->client;
int ix = to_sensor_dev_attr_2(attr)->index;
int nr = to_sensor_dev_attr_2(attr)->nr;
u8 *ptemp;
u8 reg;
int dpwm;
long val;
int ret = kstrtol(buf, 10, &val);
if (ret)
return ret;
switch (nr) {
case 1:
ptemp = data->temp1_auto_point_temp;
reg = AMC6821_REG_LTEMP_FAN_CTRL;
break;
case 2:
ptemp = data->temp2_auto_point_temp;
reg = AMC6821_REG_RTEMP_FAN_CTRL;
break;
default:
dev_dbg(dev, "Unknown attr->nr (%d).\n", nr);
return -EINVAL;
}
mutex_lock(&data->update_lock);
data->valid = 0;
switch (ix) {
case 0:
ptemp[0] = clamp_val(val / 1000, 0,
data->temp1_auto_point_temp[1]);
ptemp[0] = clamp_val(ptemp[0], 0,
data->temp2_auto_point_temp[1]);
ptemp[0] = clamp_val(ptemp[0], 0, 63);
if (i2c_smbus_write_byte_data(
client,
AMC6821_REG_PSV_TEMP,
ptemp[0])) {
dev_err(&client->dev,
"Register write error, aborting.\n");
count = -EIO;
}
goto EXIT;
case 1:
ptemp[1] = clamp_val(val / 1000, (ptemp[0] & 0x7C) + 4, 124);
ptemp[1] &= 0x7C;
ptemp[2] = clamp_val(ptemp[2], ptemp[1] + 1, 255);
break;
case 2:
ptemp[2] = clamp_val(val / 1000, ptemp[1]+1, 255);
break;
default:
dev_dbg(dev, "Unknown attr->index (%d).\n", ix);
count = -EINVAL;
goto EXIT;
}
dpwm = data->pwm1_auto_point_pwm[2] - data->pwm1_auto_point_pwm[1];
if (set_slope_register(client, reg, dpwm, ptemp))
count = -EIO;
EXIT:
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm1_auto_point_pwm(
struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct amc6821_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int dpwm;
long val;
int ret = kstrtol(buf, 10, &val);
if (ret)
return ret;
mutex_lock(&data->update_lock);
data->pwm1_auto_point_pwm[1] = clamp_val(val, 0, 254);
if (i2c_smbus_write_byte_data(client, AMC6821_REG_DCY_LOW_TEMP,
data->pwm1_auto_point_pwm[1])) {
dev_err(&client->dev, "Register write error, aborting.\n");
count = -EIO;
goto EXIT;
}
dpwm = data->pwm1_auto_point_pwm[2] - data->pwm1_auto_point_pwm[1];
if (set_slope_register(client, AMC6821_REG_LTEMP_FAN_CTRL, dpwm,
data->temp1_auto_point_temp)) {
count = -EIO;
goto EXIT;
}
if (set_slope_register(client, AMC6821_REG_RTEMP_FAN_CTRL, dpwm,
data->temp2_auto_point_temp)) {
count = -EIO;
goto EXIT;
}
EXIT:
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_fan(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
int ix = to_sensor_dev_attr(devattr)->index;
if (0 == data->fan[ix])
return sprintf(buf, "0");
return sprintf(buf, "%d\n", (int)(6000000 / data->fan[ix]));
}
static ssize_t get_fan1_fault(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
if (data->stat1 & AMC6821_STAT1_FANS)
return sprintf(buf, "1");
else
return sprintf(buf, "0");
}
static ssize_t set_fan(
struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct amc6821_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int ix = to_sensor_dev_attr(attr)->index;
int ret = kstrtol(buf, 10, &val);
if (ret)
return ret;
val = 1 > val ? 0xFFFF : 6000000/val;
mutex_lock(&data->update_lock);
data->fan[ix] = (u16) clamp_val(val, 1, 0xFFFF);
if (i2c_smbus_write_byte_data(client, fan_reg_low[ix],
data->fan[ix] & 0xFF)) {
dev_err(&client->dev, "Register write error, aborting.\n");
count = -EIO;
goto EXIT;
}
if (i2c_smbus_write_byte_data(client,
fan_reg_hi[ix], data->fan[ix] >> 8)) {
dev_err(&client->dev, "Register write error, aborting.\n");
count = -EIO;
}
EXIT:
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t get_fan1_div(
struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct amc6821_data *data = amc6821_update_device(dev);
return sprintf(buf, "%d\n", data->fan1_div);
}
static ssize_t set_fan1_div(
struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct amc6821_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long val;
int config = kstrtol(buf, 10, &val);
if (config)
return config;
mutex_lock(&data->update_lock);
config = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF4);
if (config < 0) {
dev_err(&client->dev,
"Error reading configuration register, aborting.\n");
count = config;
goto EXIT;
}
switch (val) {
case 2:
config &= ~AMC6821_CONF4_PSPR;
data->fan1_div = 2;
break;
case 4:
config |= AMC6821_CONF4_PSPR;
data->fan1_div = 4;
break;
default:
count = -EINVAL;
goto EXIT;
}
if (i2c_smbus_write_byte_data(client, AMC6821_REG_CONF4, config)) {
dev_err(&client->dev,
"Configuration register write error, aborting.\n");
count = -EIO;
}
EXIT:
mutex_unlock(&data->update_lock);
return count;
}
static int amc6821_detect(
struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int address = client->addr;
int dev_id, comp_id;
dev_dbg(&adapter->dev, "amc6821_detect called.\n");
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_dbg(&adapter->dev,
"amc6821: I2C bus doesn't support byte mode, "
"skipping.\n");
return -ENODEV;
}
dev_id = i2c_smbus_read_byte_data(client, AMC6821_REG_DEV_ID);
comp_id = i2c_smbus_read_byte_data(client, AMC6821_REG_COMP_ID);
if (dev_id != 0x21 || comp_id != 0x49) {
dev_dbg(&adapter->dev,
"amc6821: detection failed at 0x%02x.\n",
address);
return -ENODEV;
}
dev_id = i2c_smbus_read_byte_data(client, 0x80 | AMC6821_REG_DEV_ID);
comp_id = i2c_smbus_read_byte_data(client, 0x80 | AMC6821_REG_COMP_ID);
if (dev_id != 0x21 || comp_id != 0x49) {
dev_dbg(&adapter->dev,
"amc6821: detection failed at 0x%02x.\n",
address);
return -ENODEV;
}
dev_info(&adapter->dev, "amc6821: chip found at 0x%02x.\n", address);
strlcpy(info->type, "amc6821", I2C_NAME_SIZE);
return 0;
}
static int amc6821_init_client(struct i2c_client *client)
{
int config;
int err = -EIO;
if (init) {
config = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF4);
if (config < 0) {
dev_err(&client->dev,
"Error reading configuration register, aborting.\n");
return err;
}
config |= AMC6821_CONF4_MODE;
if (i2c_smbus_write_byte_data(client, AMC6821_REG_CONF4,
config)) {
dev_err(&client->dev,
"Configuration register write error, aborting.\n");
return err;
}
config = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF3);
if (config < 0) {
dev_err(&client->dev,
"Error reading configuration register, aborting.\n");
return err;
}
dev_info(&client->dev, "Revision %d\n", config & 0x0f);
config &= ~AMC6821_CONF3_THERM_FAN_EN;
if (i2c_smbus_write_byte_data(client, AMC6821_REG_CONF3,
config)) {
dev_err(&client->dev,
"Configuration register write error, aborting.\n");
return err;
}
config = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF2);
if (config < 0) {
dev_err(&client->dev,
"Error reading configuration register, aborting.\n");
return err;
}
config &= ~AMC6821_CONF2_RTFIE;
config &= ~AMC6821_CONF2_LTOIE;
config &= ~AMC6821_CONF2_RTOIE;
if (i2c_smbus_write_byte_data(client,
AMC6821_REG_CONF2, config)) {
dev_err(&client->dev,
"Configuration register write error, aborting.\n");
return err;
}
config = i2c_smbus_read_byte_data(client, AMC6821_REG_CONF1);
if (config < 0) {
dev_err(&client->dev,
"Error reading configuration register, aborting.\n");
return err;
}
config &= ~AMC6821_CONF1_THERMOVIE;
config &= ~AMC6821_CONF1_FANIE;
config |= AMC6821_CONF1_START;
if (pwminv)
config |= AMC6821_CONF1_PWMINV;
else
config &= ~AMC6821_CONF1_PWMINV;
if (i2c_smbus_write_byte_data(
client, AMC6821_REG_CONF1, config)) {
dev_err(&client->dev,
"Configuration register write error, aborting.\n");
return err;
}
}
return 0;
}
static int amc6821_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct amc6821_data *data;
struct device *hwmon_dev;
int err;
data = devm_kzalloc(dev, sizeof(struct amc6821_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->update_lock);
err = amc6821_init_client(client);
if (err)
return err;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
amc6821_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
