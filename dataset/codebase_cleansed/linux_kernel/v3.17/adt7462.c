static inline int adt7462_read_word_data(struct i2c_client *client, u8 reg)
{
u16 foo;
foo = i2c_smbus_read_byte_data(client, reg);
foo |= ((u16)i2c_smbus_read_byte_data(client, reg + 1) << 8);
return foo;
}
static int ADT7462_REG_FAN(int fan)
{
if (fan < 4)
return ADT7462_REG_FAN_BASE_ADDR + (2 * fan);
return ADT7462_REG_FAN2_BASE_ADDR + (2 * (fan - 4));
}
static int ADT7462_REG_VOLT_MAX(struct adt7462_data *data, int which)
{
switch (which) {
case 0:
if (!(data->pin_cfg[0] & ADT7462_PIN7_INPUT))
return 0x7C;
break;
case 1:
return 0x69;
case 2:
if (!(data->pin_cfg[1] & ADT7462_PIN22_INPUT))
return 0x7F;
break;
case 3:
if (!(data->pin_cfg[1] & ADT7462_PIN21_INPUT))
return 0x7E;
break;
case 4:
if (!(data->pin_cfg[0] & ADT7462_DIODE3_INPUT))
return 0x4B;
break;
case 5:
if (!(data->pin_cfg[0] & ADT7462_DIODE1_INPUT))
return 0x49;
break;
case 6:
if (!(data->pin_cfg[1] & ADT7462_PIN13_INPUT))
return 0x68;
break;
case 7:
if (!(data->pin_cfg[1] & ADT7462_PIN8_INPUT))
return 0x7D;
break;
case 8:
if (!(data->pin_cfg[2] & ADT7462_PIN26_VOLT_INPUT))
return 0x6C;
break;
case 9:
if (!(data->pin_cfg[2] & ADT7462_PIN25_VOLT_INPUT))
return 0x6B;
break;
case 10:
return 0x6A;
case 11:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return 0x50;
break;
case 12:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return 0x4C;
break;
}
return 0;
}
static int ADT7462_REG_VOLT_MIN(struct adt7462_data *data, int which)
{
switch (which) {
case 0:
if (!(data->pin_cfg[0] & ADT7462_PIN7_INPUT))
return 0x6D;
break;
case 1:
return 0x72;
case 2:
if (!(data->pin_cfg[1] & ADT7462_PIN22_INPUT))
return 0x6F;
break;
case 3:
if (!(data->pin_cfg[1] & ADT7462_PIN21_INPUT))
return 0x71;
break;
case 4:
if (!(data->pin_cfg[0] & ADT7462_DIODE3_INPUT))
return 0x47;
break;
case 5:
if (!(data->pin_cfg[0] & ADT7462_DIODE1_INPUT))
return 0x45;
break;
case 6:
if (!(data->pin_cfg[1] & ADT7462_PIN13_INPUT))
return 0x70;
break;
case 7:
if (!(data->pin_cfg[1] & ADT7462_PIN8_INPUT))
return 0x6E;
break;
case 8:
if (!(data->pin_cfg[2] & ADT7462_PIN26_VOLT_INPUT))
return 0x75;
break;
case 9:
if (!(data->pin_cfg[2] & ADT7462_PIN25_VOLT_INPUT))
return 0x74;
break;
case 10:
return 0x73;
case 11:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return 0x76;
break;
case 12:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return 0x77;
break;
}
return 0;
}
static int ADT7462_REG_VOLT(struct adt7462_data *data, int which)
{
switch (which) {
case 0:
if (!(data->pin_cfg[0] & ADT7462_PIN7_INPUT))
return 0xA3;
break;
case 1:
return 0x90;
case 2:
if (!(data->pin_cfg[1] & ADT7462_PIN22_INPUT))
return 0xA9;
break;
case 3:
if (!(data->pin_cfg[1] & ADT7462_PIN21_INPUT))
return 0xA7;
break;
case 4:
if (!(data->pin_cfg[0] & ADT7462_DIODE3_INPUT))
return 0x8F;
break;
case 5:
if (!(data->pin_cfg[0] & ADT7462_DIODE1_INPUT))
return 0x8B;
break;
case 6:
if (!(data->pin_cfg[1] & ADT7462_PIN13_INPUT))
return 0x96;
break;
case 7:
if (!(data->pin_cfg[1] & ADT7462_PIN8_INPUT))
return 0xA5;
break;
case 8:
if (!(data->pin_cfg[2] & ADT7462_PIN26_VOLT_INPUT))
return 0x93;
break;
case 9:
if (!(data->pin_cfg[2] & ADT7462_PIN25_VOLT_INPUT))
return 0x92;
break;
case 10:
return 0x91;
case 11:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return 0x94;
break;
case 12:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return 0x95;
break;
}
return -ENODEV;
}
static const char *voltage_label(struct adt7462_data *data, int which)
{
switch (which) {
case 0:
if (!(data->pin_cfg[0] & ADT7462_PIN7_INPUT))
return "+12V1";
break;
case 1:
switch (MASK_AND_SHIFT(data->pin_cfg[1], ADT7462_PIN23)) {
case 0:
return "Vccp1";
case 1:
return "+2.5V";
case 2:
return "+1.8V";
case 3:
return "+1.5V";
}
case 2:
if (!(data->pin_cfg[1] & ADT7462_PIN22_INPUT))
return "+12V3";
break;
case 3:
if (!(data->pin_cfg[1] & ADT7462_PIN21_INPUT))
return "+5V";
break;
case 4:
if (!(data->pin_cfg[0] & ADT7462_DIODE3_INPUT)) {
if (data->pin_cfg[1] & ADT7462_PIN19_INPUT)
return "+0.9V";
return "+1.25V";
}
break;
case 5:
if (!(data->pin_cfg[0] & ADT7462_DIODE1_INPUT)) {
if (data->pin_cfg[1] & ADT7462_PIN19_INPUT)
return "+1.8V";
return "+2.5V";
}
break;
case 6:
if (!(data->pin_cfg[1] & ADT7462_PIN13_INPUT))
return "+3.3V";
break;
case 7:
if (!(data->pin_cfg[1] & ADT7462_PIN8_INPUT))
return "+12V2";
break;
case 8:
switch (MASK_AND_SHIFT(data->pin_cfg[2], ADT7462_PIN26)) {
case 0:
return "Vbatt";
case 1:
return "FSB_Vtt";
}
break;
case 9:
switch (MASK_AND_SHIFT(data->pin_cfg[2], ADT7462_PIN25)) {
case 0:
return "+3.3V";
case 1:
return "+1.2V1";
}
break;
case 10:
switch (MASK_AND_SHIFT(data->pin_cfg[2], ADT7462_PIN24)) {
case 0:
return "Vccp2";
case 1:
return "+2.5V";
case 2:
return "+1.8V";
case 3:
return "+1.5";
}
case 11:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return "+1.5V ICH";
break;
case 12:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return "+1.5V 3GPIO";
break;
}
return "N/A";
}
static int voltage_multiplier(struct adt7462_data *data, int which)
{
switch (which) {
case 0:
if (!(data->pin_cfg[0] & ADT7462_PIN7_INPUT))
return 62500;
break;
case 1:
switch (MASK_AND_SHIFT(data->pin_cfg[1], ADT7462_PIN23)) {
case 0:
if (data->pin_cfg[0] & ADT7462_VID_INPUT)
return 12500;
return 6250;
case 1:
return 13000;
case 2:
return 9400;
case 3:
return 7800;
}
case 2:
if (!(data->pin_cfg[1] & ADT7462_PIN22_INPUT))
return 62500;
break;
case 3:
if (!(data->pin_cfg[1] & ADT7462_PIN21_INPUT))
return 26000;
break;
case 4:
if (!(data->pin_cfg[0] & ADT7462_DIODE3_INPUT)) {
if (data->pin_cfg[1] & ADT7462_PIN19_INPUT)
return 4690;
return 6500;
}
break;
case 5:
if (!(data->pin_cfg[0] & ADT7462_DIODE1_INPUT)) {
if (data->pin_cfg[1] & ADT7462_PIN15_INPUT)
return 9400;
return 13000;
}
break;
case 6:
if (!(data->pin_cfg[1] & ADT7462_PIN13_INPUT))
return 17200;
break;
case 7:
if (!(data->pin_cfg[1] & ADT7462_PIN8_INPUT))
return 62500;
break;
case 8:
switch (MASK_AND_SHIFT(data->pin_cfg[2], ADT7462_PIN26)) {
case 0:
return 15600;
case 1:
return 6250;
}
break;
case 9:
switch (MASK_AND_SHIFT(data->pin_cfg[2], ADT7462_PIN25)) {
case 0:
return 17200;
case 1:
return 6250;
}
break;
case 10:
switch (MASK_AND_SHIFT(data->pin_cfg[2], ADT7462_PIN24)) {
case 0:
return 6250;
case 1:
return 13000;
case 2:
return 9400;
case 3:
return 7800;
}
case 11:
case 12:
if (data->pin_cfg[3] >> ADT7462_PIN28_SHIFT ==
ADT7462_PIN28_VOLT &&
!(data->pin_cfg[0] & ADT7462_VID_INPUT))
return 7800;
}
return 0;
}
static int temp_enabled(struct adt7462_data *data, int which)
{
switch (which) {
case 0:
case 2:
return 1;
case 1:
if (data->pin_cfg[0] & ADT7462_DIODE1_INPUT)
return 1;
break;
case 3:
if (data->pin_cfg[0] & ADT7462_DIODE3_INPUT)
return 1;
break;
}
return 0;
}
static const char *temp_label(struct adt7462_data *data, int which)
{
switch (which) {
case 0:
return "local";
case 1:
if (data->pin_cfg[0] & ADT7462_DIODE1_INPUT)
return "remote1";
break;
case 2:
return "remote2";
case 3:
if (data->pin_cfg[0] & ADT7462_DIODE3_INPUT)
return "remote3";
break;
}
return "N/A";
}
static int find_trange_value(int trange)
{
int i;
for (i = 0; i < NUM_TRANGE_VALUES; i++)
if (trange_values[i] == trange)
return i;
return -EINVAL;
}
static struct adt7462_data *adt7462_update_device(struct device *dev)
{
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
unsigned long local_jiffies = jiffies;
int i;
mutex_lock(&data->lock);
if (time_before(local_jiffies, data->sensors_last_updated +
SENSOR_REFRESH_INTERVAL)
&& data->sensors_valid)
goto no_sensor_update;
for (i = 0; i < ADT7462_TEMP_COUNT; i++) {
data->temp_frac[i] = i2c_smbus_read_byte_data(client,
ADT7462_TEMP_REG(i));
data->temp[i] = i2c_smbus_read_byte_data(client,
ADT7462_TEMP_REG(i) + 1);
}
for (i = 0; i < ADT7462_FAN_COUNT; i++)
data->fan[i] = adt7462_read_word_data(client,
ADT7462_REG_FAN(i));
data->fan_enabled = i2c_smbus_read_byte_data(client,
ADT7462_REG_FAN_ENABLE);
for (i = 0; i < ADT7462_PWM_COUNT; i++)
data->pwm[i] = i2c_smbus_read_byte_data(client,
ADT7462_REG_PWM(i));
for (i = 0; i < ADT7462_PIN_CFG_REG_COUNT; i++)
data->pin_cfg[i] = i2c_smbus_read_byte_data(client,
ADT7462_REG_PIN_CFG(i));
for (i = 0; i < ADT7462_VOLT_COUNT; i++) {
int reg = ADT7462_REG_VOLT(data, i);
if (!reg)
data->voltages[i] = 0;
else
data->voltages[i] = i2c_smbus_read_byte_data(client,
reg);
}
data->alarms[0] = i2c_smbus_read_byte_data(client, ADT7462_REG_ALARM1);
data->alarms[1] = i2c_smbus_read_byte_data(client, ADT7462_REG_ALARM2);
data->alarms[2] = i2c_smbus_read_byte_data(client, ADT7462_REG_ALARM3);
data->alarms[3] = i2c_smbus_read_byte_data(client, ADT7462_REG_ALARM4);
data->sensors_last_updated = local_jiffies;
data->sensors_valid = 1;
no_sensor_update:
if (time_before(local_jiffies, data->limits_last_updated +
LIMIT_REFRESH_INTERVAL)
&& data->limits_valid)
goto out;
for (i = 0; i < ADT7462_TEMP_COUNT; i++) {
data->temp_min[i] = i2c_smbus_read_byte_data(client,
ADT7462_TEMP_MIN_REG(i));
data->temp_max[i] = i2c_smbus_read_byte_data(client,
ADT7462_TEMP_MAX_REG(i));
}
for (i = 0; i < ADT7462_FAN_COUNT; i++)
data->fan_min[i] = i2c_smbus_read_byte_data(client,
ADT7462_REG_FAN_MIN(i));
for (i = 0; i < ADT7462_VOLT_COUNT; i++) {
int reg = ADT7462_REG_VOLT_MAX(data, i);
data->volt_max[i] =
(reg ? i2c_smbus_read_byte_data(client, reg) : 0);
reg = ADT7462_REG_VOLT_MIN(data, i);
data->volt_min[i] =
(reg ? i2c_smbus_read_byte_data(client, reg) : 0);
}
for (i = 0; i < ADT7462_PWM_COUNT; i++) {
data->pwm_min[i] = i2c_smbus_read_byte_data(client,
ADT7462_REG_PWM_MIN(i));
data->pwm_tmin[i] = i2c_smbus_read_byte_data(client,
ADT7462_REG_PWM_TMIN(i));
data->pwm_trange[i] = i2c_smbus_read_byte_data(client,
ADT7462_REG_PWM_TRANGE(i));
data->pwm_cfg[i] = i2c_smbus_read_byte_data(client,
ADT7462_REG_PWM_CFG(i));
}
data->pwm_max = i2c_smbus_read_byte_data(client, ADT7462_REG_PWM_MAX);
data->cfg2 = i2c_smbus_read_byte_data(client, ADT7462_REG_CFG2);
data->limits_last_updated = local_jiffies;
data->limits_valid = 1;
out:
mutex_unlock(&data->lock);
return data;
}
static ssize_t show_temp_min(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
if (!temp_enabled(data, attr->index))
return sprintf(buf, "0\n");
return sprintf(buf, "%d\n", 1000 * (data->temp_min[attr->index] - 64));
}
static ssize_t set_temp_min(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp) || !temp_enabled(data, attr->index))
return -EINVAL;
temp = DIV_ROUND_CLOSEST(temp, 1000) + 64;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->temp_min[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_TEMP_MIN_REG(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_temp_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
if (!temp_enabled(data, attr->index))
return sprintf(buf, "0\n");
return sprintf(buf, "%d\n", 1000 * (data->temp_max[attr->index] - 64));
}
static ssize_t set_temp_max(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp) || !temp_enabled(data, attr->index))
return -EINVAL;
temp = DIV_ROUND_CLOSEST(temp, 1000) + 64;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->temp_max[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_TEMP_MAX_REG(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
u8 frac = data->temp_frac[attr->index] >> TEMP_FRAC_OFFSET;
if (!temp_enabled(data, attr->index))
return sprintf(buf, "0\n");
return sprintf(buf, "%d\n", 1000 * (data->temp[attr->index] - 64) +
250 * frac);
}
static ssize_t show_temp_label(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%s\n", temp_label(data, attr->index));
}
static ssize_t show_volt_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
int x = voltage_multiplier(data, attr->index);
x *= data->volt_max[attr->index];
x /= 1000;
return sprintf(buf, "%d\n", x);
}
static ssize_t set_volt_max(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int x = voltage_multiplier(data, attr->index);
long temp;
if (kstrtol(buf, 10, &temp) || !x)
return -EINVAL;
temp *= 1000;
temp = DIV_ROUND_CLOSEST(temp, x);
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->volt_max[attr->index] = temp;
i2c_smbus_write_byte_data(client,
ADT7462_REG_VOLT_MAX(data, attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_volt_min(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
int x = voltage_multiplier(data, attr->index);
x *= data->volt_min[attr->index];
x /= 1000;
return sprintf(buf, "%d\n", x);
}
static ssize_t set_volt_min(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int x = voltage_multiplier(data, attr->index);
long temp;
if (kstrtol(buf, 10, &temp) || !x)
return -EINVAL;
temp *= 1000;
temp = DIV_ROUND_CLOSEST(temp, x);
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->volt_min[attr->index] = temp;
i2c_smbus_write_byte_data(client,
ADT7462_REG_VOLT_MIN(data, attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_voltage(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
int x = voltage_multiplier(data, attr->index);
x *= data->voltages[attr->index];
x /= 1000;
return sprintf(buf, "%d\n", x);
}
static ssize_t show_voltage_label(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%s\n", voltage_label(data, attr->index));
}
static ssize_t show_alarm(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
int reg = attr->index >> ADT7462_ALARM_REG_SHIFT;
int mask = attr->index & ADT7462_ALARM_FLAG_MASK;
if (data->alarms[reg] & mask)
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static int fan_enabled(struct adt7462_data *data, int fan)
{
return data->fan_enabled & (1 << fan);
}
static ssize_t show_fan_min(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
u16 temp;
temp = data->fan_min[attr->index];
temp <<= 8;
if (!fan_enabled(data, attr->index) ||
!FAN_DATA_VALID(temp))
return sprintf(buf, "0\n");
return sprintf(buf, "%d\n", FAN_PERIOD_TO_RPM(temp));
}
static ssize_t set_fan_min(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp) || !temp ||
!fan_enabled(data, attr->index))
return -EINVAL;
temp = FAN_RPM_TO_PERIOD(temp);
temp >>= 8;
temp = clamp_val(temp, 1, 255);
mutex_lock(&data->lock);
data->fan_min[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_FAN_MIN(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
if (!fan_enabled(data, attr->index) ||
!FAN_DATA_VALID(data->fan[attr->index]))
return sprintf(buf, "0\n");
return sprintf(buf, "%d\n",
FAN_PERIOD_TO_RPM(data->fan[attr->index]));
}
static ssize_t show_force_pwm_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%d\n", (data->cfg2 & ADT7462_FSPD_MASK ? 1 : 0));
}
static ssize_t set_force_pwm_max(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
u8 reg;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
mutex_lock(&data->lock);
reg = i2c_smbus_read_byte_data(client, ADT7462_REG_CFG2);
if (temp)
reg |= ADT7462_FSPD_MASK;
else
reg &= ~ADT7462_FSPD_MASK;
data->cfg2 = reg;
i2c_smbus_write_byte_data(client, ADT7462_REG_CFG2, reg);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%d\n", data->pwm[attr->index]);
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->pwm[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_PWM(attr->index), temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_max(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%d\n", data->pwm_max);
}
static ssize_t set_pwm_max(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->pwm_max = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_PWM_MAX, temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_min(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%d\n", data->pwm_min[attr->index]);
}
static ssize_t set_pwm_min(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->pwm_min[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_PWM_MIN(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_hyst(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%d\n", 1000 *
(data->pwm_trange[attr->index] & ADT7462_PWM_HYST_MASK));
}
static ssize_t set_pwm_hyst(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = DIV_ROUND_CLOSEST(temp, 1000);
temp = clamp_val(temp, 0, 15);
temp &= ADT7462_PWM_HYST_MASK;
temp |= data->pwm_trange[attr->index] & ADT7462_PWM_RANGE_MASK;
mutex_lock(&data->lock);
data->pwm_trange[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_PWM_TRANGE(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_tmax(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
int trange = trange_values[data->pwm_trange[attr->index] >>
ADT7462_PWM_RANGE_SHIFT];
int tmin = (data->pwm_tmin[attr->index] - 64) * 1000;
return sprintf(buf, "%d\n", tmin + trange);
}
static ssize_t set_pwm_tmax(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
int temp;
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
int tmin, trange_value;
long trange;
if (kstrtol(buf, 10, &trange))
return -EINVAL;
tmin = (data->pwm_tmin[attr->index] - 64) * 1000;
trange_value = find_trange_value(trange - tmin);
if (trange_value < 0)
return trange_value;
temp = trange_value << ADT7462_PWM_RANGE_SHIFT;
temp |= data->pwm_trange[attr->index] & ADT7462_PWM_HYST_MASK;
mutex_lock(&data->lock);
data->pwm_trange[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_PWM_TRANGE(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_tmin(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
return sprintf(buf, "%d\n", 1000 * (data->pwm_tmin[attr->index] - 64));
}
static ssize_t set_pwm_tmin(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = DIV_ROUND_CLOSEST(temp, 1000) + 64;
temp = clamp_val(temp, 0, 255);
mutex_lock(&data->lock);
data->pwm_tmin[attr->index] = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_PWM_TMIN(attr->index),
temp);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm_auto(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
int cfg = data->pwm_cfg[attr->index] >> ADT7462_PWM_CHANNEL_SHIFT;
switch (cfg) {
case 4:
return sprintf(buf, "0\n");
case 7:
return sprintf(buf, "1\n");
default:
return sprintf(buf, "2\n");
}
}
static void set_pwm_channel(struct i2c_client *client,
struct adt7462_data *data,
int which,
int value)
{
int temp = data->pwm_cfg[which] & ~ADT7462_PWM_CHANNEL_MASK;
temp |= value << ADT7462_PWM_CHANNEL_SHIFT;
mutex_lock(&data->lock);
data->pwm_cfg[which] = temp;
i2c_smbus_write_byte_data(client, ADT7462_REG_PWM_CFG(which), temp);
mutex_unlock(&data->lock);
}
static ssize_t set_pwm_auto(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
switch (temp) {
case 0:
set_pwm_channel(client, data, attr->index, 4);
return count;
case 1:
set_pwm_channel(client, data, attr->index, 7);
return count;
default:
return -EINVAL;
}
}
static ssize_t show_pwm_auto_temp(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = adt7462_update_device(dev);
int channel = data->pwm_cfg[attr->index] >> ADT7462_PWM_CHANNEL_SHIFT;
switch (channel) {
case 0:
case 1:
case 2:
case 3:
return sprintf(buf, "%d\n", (1 << channel));
case 5:
return sprintf(buf, "9\n");
case 6:
return sprintf(buf, "15\n");
default:
return sprintf(buf, "0\n");
}
}
static int cvt_auto_temp(int input)
{
if (input == 0xF)
return 6;
if (input == 0x9)
return 5;
if (input < 1 || !is_power_of_2(input))
return -EINVAL;
return ilog2(input);
}
static ssize_t set_pwm_auto_temp(struct device *dev,
struct device_attribute *devattr,
const char *buf,
size_t count)
{
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
struct adt7462_data *data = dev_get_drvdata(dev);
struct i2c_client *client = data->client;
long temp;
if (kstrtol(buf, 10, &temp))
return -EINVAL;
temp = cvt_auto_temp(temp);
if (temp < 0)
return temp;
set_pwm_channel(client, data, attr->index, temp);
return count;
}
static int adt7462_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int vendor, device, revision;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -ENODEV;
vendor = i2c_smbus_read_byte_data(client, ADT7462_REG_VENDOR);
if (vendor != ADT7462_VENDOR)
return -ENODEV;
device = i2c_smbus_read_byte_data(client, ADT7462_REG_DEVICE);
if (device != ADT7462_DEVICE)
return -ENODEV;
revision = i2c_smbus_read_byte_data(client, ADT7462_REG_REVISION);
if (revision != ADT7462_REVISION)
return -ENODEV;
strlcpy(info->type, "adt7462", I2C_NAME_SIZE);
return 0;
}
static int adt7462_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct adt7462_data *data;
struct device *hwmon_dev;
data = devm_kzalloc(dev, sizeof(struct adt7462_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->client = client;
mutex_init(&data->lock);
dev_info(&client->dev, "%s chip found\n", client->name);
hwmon_dev = devm_hwmon_device_register_with_groups(dev, client->name,
data,
adt7462_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
