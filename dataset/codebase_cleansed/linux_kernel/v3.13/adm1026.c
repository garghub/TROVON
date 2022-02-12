static int adm1026_read_value(struct i2c_client *client, u8 reg)
{
int res;
if (reg < 0x80) {
res = i2c_smbus_read_byte_data(client, reg) & 0xff;
} else {
res = 0;
}
return res;
}
static int adm1026_write_value(struct i2c_client *client, u8 reg, int value)
{
int res;
if (reg < 0x80) {
res = i2c_smbus_write_byte_data(client, reg, value);
} else {
res = 0;
}
return res;
}
static void adm1026_init_client(struct i2c_client *client)
{
int value, i;
struct adm1026_data *data = i2c_get_clientdata(client);
dev_dbg(&client->dev, "Initializing device\n");
data->config1 = adm1026_read_value(client, ADM1026_REG_CONFIG1);
data->config2 = adm1026_read_value(client, ADM1026_REG_CONFIG2);
data->config3 = adm1026_read_value(client, ADM1026_REG_CONFIG3);
dev_dbg(&client->dev, "ADM1026_REG_CONFIG1 is: 0x%02x\n",
data->config1);
if ((data->config1 & CFG1_MONITOR) == 0) {
dev_dbg(&client->dev,
"Monitoring not currently enabled.\n");
}
if (data->config1 & CFG1_INT_ENABLE) {
dev_dbg(&client->dev,
"SMBALERT interrupts are enabled.\n");
}
if (data->config1 & CFG1_AIN8_9) {
dev_dbg(&client->dev,
"in8 and in9 enabled. temp3 disabled.\n");
} else {
dev_dbg(&client->dev,
"temp3 enabled. in8 and in9 disabled.\n");
}
if (data->config1 & CFG1_THERM_HOT) {
dev_dbg(&client->dev,
"Automatic THERM, PWM, and temp limits enabled.\n");
}
if (data->config3 & CFG3_GPIO16_ENABLE) {
dev_dbg(&client->dev,
"GPIO16 enabled. THERM pin disabled.\n");
} else {
dev_dbg(&client->dev,
"THERM pin enabled. GPIO16 disabled.\n");
}
if (data->config3 & CFG3_VREF_250)
dev_dbg(&client->dev, "Vref is 2.50 Volts.\n");
else
dev_dbg(&client->dev, "Vref is 1.82 Volts.\n");
value = 0;
for (i = 0; i <= 15; ++i) {
if ((i & 0x03) == 0) {
value = adm1026_read_value(client,
ADM1026_REG_GPIO_CFG_0_3 + i / 4);
}
data->gpio_config[i] = value & 0x03;
value >>= 2;
}
data->gpio_config[16] = (data->config3 >> 6) & 0x03;
adm1026_print_gpio(client);
if (gpio_input[0] != -1 || gpio_output[0] != -1
|| gpio_inverted[0] != -1 || gpio_normal[0] != -1
|| gpio_fan[0] != -1) {
adm1026_fixup_gpio(client);
}
data->pwm1.auto_pwm_min = 255;
value = adm1026_read_value(client, ADM1026_REG_CONFIG1);
value = (value | CFG1_MONITOR) & (~CFG1_INT_CLEAR & ~CFG1_RESET);
dev_dbg(&client->dev, "Setting CONFIG to: 0x%02x\n", value);
data->config1 = value;
adm1026_write_value(client, ADM1026_REG_CONFIG1, value);
value = adm1026_read_value(client, ADM1026_REG_FAN_DIV_0_3) |
(adm1026_read_value(client, ADM1026_REG_FAN_DIV_4_7) << 8);
for (i = 0; i <= 7; ++i) {
data->fan_div[i] = DIV_FROM_REG(value & 0x03);
value >>= 2;
}
}
static void adm1026_print_gpio(struct i2c_client *client)
{
struct adm1026_data *data = i2c_get_clientdata(client);
int i;
dev_dbg(&client->dev, "GPIO config is:\n");
for (i = 0; i <= 7; ++i) {
if (data->config2 & (1 << i)) {
dev_dbg(&client->dev, "\t%sGP%s%d\n",
data->gpio_config[i] & 0x02 ? "" : "!",
data->gpio_config[i] & 0x01 ? "OUT" : "IN",
i);
} else {
dev_dbg(&client->dev, "\tFAN%d\n", i);
}
}
for (i = 8; i <= 15; ++i) {
dev_dbg(&client->dev, "\t%sGP%s%d\n",
data->gpio_config[i] & 0x02 ? "" : "!",
data->gpio_config[i] & 0x01 ? "OUT" : "IN",
i);
}
if (data->config3 & CFG3_GPIO16_ENABLE) {
dev_dbg(&client->dev, "\t%sGP%s16\n",
data->gpio_config[16] & 0x02 ? "" : "!",
data->gpio_config[16] & 0x01 ? "OUT" : "IN");
} else {
dev_dbg(&client->dev, "\tTHERM\n");
}
}
static void adm1026_fixup_gpio(struct i2c_client *client)
{
struct adm1026_data *data = i2c_get_clientdata(client);
int i;
int value;
for (i = 0; i <= 16; ++i) {
if (gpio_output[i] >= 0 && gpio_output[i] <= 16)
data->gpio_config[gpio_output[i]] |= 0x01;
if (gpio_output[i] >= 0 && gpio_output[i] <= 7)
data->config2 |= 1 << gpio_output[i];
}
for (i = 0; i <= 16; ++i) {
if (gpio_input[i] >= 0 && gpio_input[i] <= 16)
data->gpio_config[gpio_input[i]] &= ~0x01;
if (gpio_input[i] >= 0 && gpio_input[i] <= 7)
data->config2 |= 1 << gpio_input[i];
}
for (i = 0; i <= 16; ++i) {
if (gpio_inverted[i] >= 0 && gpio_inverted[i] <= 16)
data->gpio_config[gpio_inverted[i]] &= ~0x02;
}
for (i = 0; i <= 16; ++i) {
if (gpio_normal[i] >= 0 && gpio_normal[i] <= 16)
data->gpio_config[gpio_normal[i]] |= 0x02;
}
for (i = 0; i <= 7; ++i) {
if (gpio_fan[i] >= 0 && gpio_fan[i] <= 7)
data->config2 &= ~(1 << gpio_fan[i]);
}
adm1026_write_value(client, ADM1026_REG_CONFIG2, data->config2);
data->config3 = (data->config3 & 0x3f)
| ((data->gpio_config[16] & 0x03) << 6);
adm1026_write_value(client, ADM1026_REG_CONFIG3, data->config3);
for (i = 15, value = 0; i >= 0; --i) {
value <<= 2;
value |= data->gpio_config[i] & 0x03;
if ((i & 0x03) == 0) {
adm1026_write_value(client,
ADM1026_REG_GPIO_CFG_0_3 + i/4,
value);
value = 0;
}
}
adm1026_print_gpio(client);
}
static struct adm1026_data *adm1026_update_device(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
int i;
long value, alarms, gpio;
mutex_lock(&data->update_lock);
if (!data->valid
|| time_after(jiffies,
data->last_reading + ADM1026_DATA_INTERVAL)) {
dev_dbg(&client->dev, "Reading sensor values\n");
for (i = 0; i <= 16; ++i) {
data->in[i] =
adm1026_read_value(client, ADM1026_REG_IN[i]);
}
for (i = 0; i <= 7; ++i) {
data->fan[i] =
adm1026_read_value(client, ADM1026_REG_FAN(i));
}
for (i = 0; i <= 2; ++i) {
data->temp[i] =
adm1026_read_value(client, ADM1026_REG_TEMP[i]);
}
data->pwm1.pwm = adm1026_read_value(client,
ADM1026_REG_PWM);
data->analog_out = adm1026_read_value(client,
ADM1026_REG_DAC);
alarms = adm1026_read_value(client, ADM1026_REG_STATUS4);
gpio = alarms & 0x80 ? 0x0100 : 0;
alarms &= 0x7f;
alarms <<= 8;
alarms |= adm1026_read_value(client, ADM1026_REG_STATUS3);
alarms <<= 8;
alarms |= adm1026_read_value(client, ADM1026_REG_STATUS2);
alarms <<= 8;
alarms |= adm1026_read_value(client, ADM1026_REG_STATUS1);
data->alarms = alarms;
gpio |= adm1026_read_value(client,
ADM1026_REG_GPIO_STATUS_8_15);
gpio <<= 8;
gpio |= adm1026_read_value(client,
ADM1026_REG_GPIO_STATUS_0_7);
data->gpio = gpio;
data->last_reading = jiffies;
}
if (!data->valid ||
time_after(jiffies, data->last_config + ADM1026_CONFIG_INTERVAL)) {
dev_dbg(&client->dev, "Reading config values\n");
for (i = 0; i <= 16; ++i) {
data->in_min[i] = adm1026_read_value(client,
ADM1026_REG_IN_MIN[i]);
data->in_max[i] = adm1026_read_value(client,
ADM1026_REG_IN_MAX[i]);
}
value = adm1026_read_value(client, ADM1026_REG_FAN_DIV_0_3)
| (adm1026_read_value(client, ADM1026_REG_FAN_DIV_4_7)
<< 8);
for (i = 0; i <= 7; ++i) {
data->fan_min[i] = adm1026_read_value(client,
ADM1026_REG_FAN_MIN(i));
data->fan_div[i] = DIV_FROM_REG(value & 0x03);
value >>= 2;
}
for (i = 0; i <= 2; ++i) {
data->temp_min[i] = adm1026_read_value(client,
ADM1026_REG_TEMP_MIN[i]);
data->temp_max[i] = adm1026_read_value(client,
ADM1026_REG_TEMP_MAX[i]);
data->temp_tmin[i] = adm1026_read_value(client,
ADM1026_REG_TEMP_TMIN[i]);
data->temp_crit[i] = adm1026_read_value(client,
ADM1026_REG_TEMP_THERM[i]);
data->temp_offset[i] = adm1026_read_value(client,
ADM1026_REG_TEMP_OFFSET[i]);
}
alarms = adm1026_read_value(client, ADM1026_REG_MASK4);
gpio = alarms & 0x80 ? 0x0100 : 0;
alarms = (alarms & 0x7f) << 8;
alarms |= adm1026_read_value(client, ADM1026_REG_MASK3);
alarms <<= 8;
alarms |= adm1026_read_value(client, ADM1026_REG_MASK2);
alarms <<= 8;
alarms |= adm1026_read_value(client, ADM1026_REG_MASK1);
data->alarm_mask = alarms;
gpio |= adm1026_read_value(client,
ADM1026_REG_GPIO_MASK_8_15);
gpio <<= 8;
gpio |= adm1026_read_value(client, ADM1026_REG_GPIO_MASK_0_7);
data->gpio_mask = gpio;
data->config1 = adm1026_read_value(client,
ADM1026_REG_CONFIG1);
if (data->config1 & CFG1_PWM_AFC) {
data->pwm1.enable = 2;
data->pwm1.auto_pwm_min =
PWM_MIN_FROM_REG(data->pwm1.pwm);
}
data->config2 = adm1026_read_value(client,
ADM1026_REG_CONFIG2);
data->config3 = adm1026_read_value(client,
ADM1026_REG_CONFIG3);
data->gpio_config[16] = (data->config3 >> 6) & 0x03;
value = 0;
for (i = 0; i <= 15; ++i) {
if ((i & 0x03) == 0) {
value = adm1026_read_value(client,
ADM1026_REG_GPIO_CFG_0_3 + i/4);
}
data->gpio_config[i] = value & 0x03;
value >>= 2;
}
data->last_config = jiffies;
}
data->valid = 1;
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(nr, data->in[nr]));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(nr, data->in_min[nr]));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[nr] = INS_TO_REG(nr, val);
adm1026_write_value(client, ADM1026_REG_IN_MIN[nr], data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(nr, data->in_max[nr]));
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[nr] = INS_TO_REG(nr, val);
adm1026_write_value(client, ADM1026_REG_IN_MAX[nr], data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in16(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(16, data->in[16]) -
NEG12_OFFSET);
}
static ssize_t show_in16_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(16, data->in_min[16])
- NEG12_OFFSET);
}
static ssize_t set_in16_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[16] = INS_TO_REG(16, val + NEG12_OFFSET);
adm1026_write_value(client, ADM1026_REG_IN_MIN[16], data->in_min[16]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in16_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", INS_FROM_REG(16, data->in_max[16])
- NEG12_OFFSET);
}
static ssize_t set_in16_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[16] = INS_TO_REG(16, val+NEG12_OFFSET);
adm1026_write_value(client, ADM1026_REG_IN_MAX[16], data->in_max[16]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
data->fan_div[nr]));
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
data->fan_div[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, data->fan_div[nr]);
adm1026_write_value(client, ADM1026_REG_FAN_MIN(nr),
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static void fixup_fan_min(struct device *dev, int fan, int old_div)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
int new_min;
int new_div = data->fan_div[fan];
if (data->fan_min[fan] == 0 || data->fan_min[fan] == 0xff)
return;
new_min = data->fan_min[fan] * old_div / new_div;
new_min = clamp_val(new_min, 1, 254);
data->fan_min[fan] = new_min;
adm1026_write_value(client, ADM1026_REG_FAN_MIN(fan), new_min);
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", data->fan_div[nr]);
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int orig_div, new_div;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
new_div = DIV_TO_REG(val);
mutex_lock(&data->update_lock);
orig_div = data->fan_div[nr];
data->fan_div[nr] = DIV_FROM_REG(new_div);
if (nr < 4) {
adm1026_write_value(client, ADM1026_REG_FAN_DIV_0_3,
(DIV_TO_REG(data->fan_div[0]) << 0) |
(DIV_TO_REG(data->fan_div[1]) << 2) |
(DIV_TO_REG(data->fan_div[2]) << 4) |
(DIV_TO_REG(data->fan_div[3]) << 6));
} else {
adm1026_write_value(client, ADM1026_REG_FAN_DIV_4_7,
(DIV_TO_REG(data->fan_div[4]) << 0) |
(DIV_TO_REG(data->fan_div[5]) << 2) |
(DIV_TO_REG(data->fan_div[6]) << 4) |
(DIV_TO_REG(data->fan_div[7]) << 6));
}
if (data->fan_div[nr] != orig_div)
fixup_fan_min(dev, nr, orig_div);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr]));
}
static ssize_t show_temp_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_min[nr]));
}
static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_min[nr] = TEMP_TO_REG(val);
adm1026_write_value(client, ADM1026_REG_TEMP_MIN[nr],
data->temp_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_max[nr]));
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_max[nr] = TEMP_TO_REG(val);
adm1026_write_value(client, ADM1026_REG_TEMP_MAX[nr],
data->temp_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_offset(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_offset[nr]));
}
static ssize_t set_temp_offset(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_offset[nr] = TEMP_TO_REG(val);
adm1026_write_value(client, ADM1026_REG_TEMP_OFFSET[nr],
data->temp_offset[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_auto_point1_temp_hyst(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(
ADM1026_FAN_ACTIVATION_TEMP_HYST + data->temp_tmin[nr]));
}
static ssize_t show_temp_auto_point2_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_tmin[nr] +
ADM1026_FAN_CONTROL_TEMP_RANGE));
}
static ssize_t show_temp_auto_point1_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_tmin[nr]));
}
static ssize_t set_temp_auto_point1_temp(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_tmin[nr] = TEMP_TO_REG(val);
adm1026_write_value(client, ADM1026_REG_TEMP_TMIN[nr],
data->temp_tmin[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_crit_enable(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", (data->config1 & CFG1_THERM_HOT) >> 4);
}
static ssize_t set_temp_crit_enable(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
data->config1 = (data->config1 & ~CFG1_THERM_HOT) | (val << 4);
adm1026_write_value(client, ADM1026_REG_CONFIG1, data->config1);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_crit(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_crit[nr]));
}
static ssize_t set_temp_crit(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_crit[nr] = TEMP_TO_REG(val);
adm1026_write_value(client, ADM1026_REG_TEMP_THERM[nr],
data->temp_crit[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_analog_out_reg(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", DAC_FROM_REG(data->analog_out));
}
static ssize_t set_analog_out_reg(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->analog_out = DAC_TO_REG(val);
adm1026_write_value(client, ADM1026_REG_DAC, data->analog_out);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_vid_reg(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
int vid = (data->gpio >> 11) & 0x1f;
dev_dbg(dev, "Setting VID from GPIO11-15.\n");
return sprintf(buf, "%d\n", vid_from_reg(vid, data->vrm));
}
static ssize_t show_vrm_reg(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", data->vrm);
}
static ssize_t store_vrm_reg(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct adm1026_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
data->vrm = val;
return count;
}
static ssize_t show_alarms_reg(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%ld\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%ld\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_alarm_mask(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%ld\n", data->alarm_mask);
}
static ssize_t set_alarm_mask(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
unsigned long mask;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->alarm_mask = val & 0x7fffffff;
mask = data->alarm_mask
| (data->gpio_mask & 0x10000 ? 0x80000000 : 0);
adm1026_write_value(client, ADM1026_REG_MASK1,
mask & 0xff);
mask >>= 8;
adm1026_write_value(client, ADM1026_REG_MASK2,
mask & 0xff);
mask >>= 8;
adm1026_write_value(client, ADM1026_REG_MASK3,
mask & 0xff);
mask >>= 8;
adm1026_write_value(client, ADM1026_REG_MASK4,
mask & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_gpio(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%ld\n", data->gpio);
}
static ssize_t set_gpio(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long gpio;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->gpio = val & 0x1ffff;
gpio = data->gpio;
adm1026_write_value(client, ADM1026_REG_GPIO_STATUS_0_7, gpio & 0xff);
gpio >>= 8;
adm1026_write_value(client, ADM1026_REG_GPIO_STATUS_8_15, gpio & 0xff);
gpio = ((gpio >> 1) & 0x80) | (data->alarms >> 24 & 0x7f);
adm1026_write_value(client, ADM1026_REG_STATUS4, gpio & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_gpio_mask(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%ld\n", data->gpio_mask);
}
static ssize_t set_gpio_mask(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
long mask;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->gpio_mask = val & 0x1ffff;
mask = data->gpio_mask;
adm1026_write_value(client, ADM1026_REG_GPIO_MASK_0_7, mask & 0xff);
mask >>= 8;
adm1026_write_value(client, ADM1026_REG_GPIO_MASK_8_15, mask & 0xff);
mask = ((mask >> 1) & 0x80) | (data->alarm_mask >> 24 & 0x7f);
adm1026_write_value(client, ADM1026_REG_MASK1, mask & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_reg(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", PWM_FROM_REG(data->pwm1.pwm));
}
static ssize_t set_pwm_reg(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
if (data->pwm1.enable == 1) {
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->pwm1.pwm = PWM_TO_REG(val);
adm1026_write_value(client, ADM1026_REG_PWM, data->pwm1.pwm);
mutex_unlock(&data->update_lock);
}
return count;
}
static ssize_t show_auto_pwm_min(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", data->pwm1.auto_pwm_min);
}
static ssize_t set_auto_pwm_min(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->pwm1.auto_pwm_min = clamp_val(val, 0, 255);
if (data->pwm1.enable == 2) {
data->pwm1.pwm = PWM_TO_REG((data->pwm1.pwm & 0x0f) |
PWM_MIN_TO_REG(data->pwm1.auto_pwm_min));
adm1026_write_value(client, ADM1026_REG_PWM, data->pwm1.pwm);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_auto_pwm_max(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%d\n", ADM1026_PWM_MAX);
}
static ssize_t show_pwm_enable(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct adm1026_data *data = adm1026_update_device(dev);
return sprintf(buf, "%d\n", data->pwm1.enable);
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct adm1026_data *data = i2c_get_clientdata(client);
int old_enable;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val >= 3)
return -EINVAL;
mutex_lock(&data->update_lock);
old_enable = data->pwm1.enable;
data->pwm1.enable = val;
data->config1 = (data->config1 & ~CFG1_PWM_AFC)
| ((val == 2) ? CFG1_PWM_AFC : 0);
adm1026_write_value(client, ADM1026_REG_CONFIG1, data->config1);
if (val == 2) {
data->pwm1.pwm = PWM_TO_REG((data->pwm1.pwm & 0x0f) |
PWM_MIN_TO_REG(data->pwm1.auto_pwm_min));
adm1026_write_value(client, ADM1026_REG_PWM, data->pwm1.pwm);
} else if (!((old_enable == 1) && (val == 1))) {
data->pwm1.pwm = 255;
adm1026_write_value(client, ADM1026_REG_PWM, data->pwm1.pwm);
}
mutex_unlock(&data->update_lock);
return count;
}
static int adm1026_detect(struct i2c_client *client,
struct i2c_board_info *info)
{
struct i2c_adapter *adapter = client->adapter;
int address = client->addr;
int company, verstep;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA)) {
return -ENODEV;
}
company = adm1026_read_value(client, ADM1026_REG_COMPANY);
verstep = adm1026_read_value(client, ADM1026_REG_VERSTEP);
dev_dbg(&adapter->dev,
"Detecting device at %d,0x%02x with COMPANY: 0x%02x and VERSTEP: 0x%02x\n",
i2c_adapter_id(client->adapter), client->addr,
company, verstep);
dev_dbg(&adapter->dev, "Autodetecting device at %d,0x%02x...\n",
i2c_adapter_id(adapter), address);
if (company == ADM1026_COMPANY_ANALOG_DEV
&& verstep == ADM1026_VERSTEP_ADM1026) {
} else if (company == ADM1026_COMPANY_ANALOG_DEV
&& (verstep & 0xf0) == ADM1026_VERSTEP_GENERIC) {
dev_err(&adapter->dev,
"Unrecognized stepping 0x%02x. Defaulting to ADM1026.\n",
verstep);
} else if ((verstep & 0xf0) == ADM1026_VERSTEP_GENERIC) {
dev_err(&adapter->dev,
"Found version/stepping 0x%02x. Assuming generic ADM1026.\n",
verstep);
} else {
dev_dbg(&adapter->dev, "Autodetection failed\n");
return -ENODEV;
}
strlcpy(info->type, "adm1026", I2C_NAME_SIZE);
return 0;
}
static int adm1026_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adm1026_data *data;
int err;
data = devm_kzalloc(&client->dev, sizeof(struct adm1026_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
i2c_set_clientdata(client, data);
mutex_init(&data->update_lock);
data->vrm = vid_which_vrm();
adm1026_init_client(client);
err = sysfs_create_group(&client->dev.kobj, &adm1026_group);
if (err)
return err;
if (data->config1 & CFG1_AIN8_9)
err = sysfs_create_group(&client->dev.kobj,
&adm1026_group_in8_9);
else
err = sysfs_create_group(&client->dev.kobj,
&adm1026_group_temp3);
if (err)
goto exitremove;
data->hwmon_dev = hwmon_device_register(&client->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exitremove;
}
return 0;
exitremove:
sysfs_remove_group(&client->dev.kobj, &adm1026_group);
if (data->config1 & CFG1_AIN8_9)
sysfs_remove_group(&client->dev.kobj, &adm1026_group_in8_9);
else
sysfs_remove_group(&client->dev.kobj, &adm1026_group_temp3);
return err;
}
static int adm1026_remove(struct i2c_client *client)
{
struct adm1026_data *data = i2c_get_clientdata(client);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&client->dev.kobj, &adm1026_group);
if (data->config1 & CFG1_AIN8_9)
sysfs_remove_group(&client->dev.kobj, &adm1026_group_in8_9);
else
sysfs_remove_group(&client->dev.kobj, &adm1026_group_temp3);
return 0;
}
