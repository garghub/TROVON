static inline int superio_inb(int reg)
{
outb(reg, REG);
return inb(VAL);
}
static inline void superio_outb(int reg, int val)
{
outb(reg, REG);
outb(val, VAL);
}
static int superio_inw(int reg)
{
int val;
outb(reg++, REG);
val = inb(VAL) << 8;
outb(reg, REG);
val |= inb(VAL);
return val;
}
static inline void superio_select(int ldn)
{
outb(DEV, REG);
outb(ldn, VAL);
}
static inline int superio_enter(void)
{
if (!request_muxed_region(REG, 2, DRVNAME))
return -EBUSY;
outb(0x87, REG);
outb(0x01, REG);
outb(0x55, REG);
outb(0x55, REG);
return 0;
}
static inline void superio_exit(void)
{
outb(0x02, REG);
outb(0x02, VAL);
release_region(REG, 2);
}
static inline int has_12mv_adc(const struct it87_data *data)
{
return data->type == it8721
|| data->type == it8728;
}
static inline int has_newer_autopwm(const struct it87_data *data)
{
return data->type == it8721
|| data->type == it8728;
}
static u8 in_to_reg(const struct it87_data *data, int nr, long val)
{
long lsb;
if (has_12mv_adc(data)) {
if (data->in_scaled & (1 << nr))
lsb = 24;
else
lsb = 12;
} else
lsb = 16;
val = DIV_ROUND_CLOSEST(val, lsb);
return SENSORS_LIMIT(val, 0, 255);
}
static int in_from_reg(const struct it87_data *data, int nr, int val)
{
if (has_12mv_adc(data)) {
if (data->in_scaled & (1 << nr))
return val * 24;
else
return val * 12;
} else
return val * 16;
}
static inline u8 FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 255;
rpm = SENSORS_LIMIT(rpm, 1, 1000000);
return SENSORS_LIMIT((1350000 + rpm * div / 2) / (rpm * div), 1,
254);
}
static inline u16 FAN16_TO_REG(long rpm)
{
if (rpm == 0)
return 0xffff;
return SENSORS_LIMIT((1350000 + rpm) / (rpm * 2), 1, 0xfffe);
}
static u8 pwm_to_reg(const struct it87_data *data, long val)
{
if (has_newer_autopwm(data))
return val;
else
return val >> 1;
}
static int pwm_from_reg(const struct it87_data *data, u8 reg)
{
if (has_newer_autopwm(data))
return reg;
else
return (reg & 0x7f) << 1;
}
static int DIV_TO_REG(int val)
{
int answer = 0;
while (answer < 7 && (val >>= 1))
answer++;
return answer;
}
static inline int has_16bit_fans(const struct it87_data *data)
{
return (data->type == it87 && data->revision >= 0x03)
|| (data->type == it8712 && data->revision >= 0x08)
|| data->type == it8716
|| data->type == it8718
|| data->type == it8720
|| data->type == it8721
|| data->type == it8728;
}
static inline int has_old_autopwm(const struct it87_data *data)
{
return (data->type == it87 && data->revision < 0x03)
|| (data->type == it8712 && data->revision < 0x08);
}
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", in_from_reg(data, nr, data->in[nr]));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", in_from_reg(data, nr, data->in_min[nr]));
}
static ssize_t show_in_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", in_from_reg(data, nr, data->in_max[nr]));
}
static ssize_t set_in_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->in_min[nr] = in_to_reg(data, nr, val);
it87_write_value(data, IT87_REG_VIN_MIN(nr),
data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->in_max[nr] = in_to_reg(data, nr, val);
it87_write_value(data, IT87_REG_VIN_MAX(nr),
data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr]));
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_high[nr]));
}
static ssize_t show_temp_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp_low[nr]));
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->temp_high[nr] = TEMP_TO_REG(val);
it87_write_value(data, IT87_REG_TEMP_HIGH(nr), data->temp_high[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->temp_low[nr] = TEMP_TO_REG(val);
it87_write_value(data, IT87_REG_TEMP_LOW(nr), data->temp_low[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_sensor(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
u8 reg = data->sensor;
if (reg & (1 << nr))
return sprintf(buf, "3\n");
if (reg & (8 << nr))
return sprintf(buf, "4\n");
return sprintf(buf, "0\n");
}
static ssize_t set_sensor(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
u8 reg;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
reg = it87_read_value(data, IT87_REG_TEMP_ENABLE);
reg &= ~(1 << nr);
reg &= ~(8 << nr);
if (val == 2) {
dev_warn(dev, "Sensor type 2 is deprecated, please use 4 "
"instead\n");
val = 4;
}
if (val == 3)
reg |= 1 << nr;
else if (val == 4)
reg |= 8 << nr;
else if (val != 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->sensor = reg;
it87_write_value(data, IT87_REG_TEMP_ENABLE, data->sensor);
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static int pwm_mode(const struct it87_data *data, int nr)
{
int ctrl = data->fan_main_ctrl & (1 << nr);
if (ctrl == 0)
return 0;
if (data->pwm_ctrl[nr] & 0x80)
return 2;
else
return 1;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t show_pwm_enable(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", pwm_mode(data, nr));
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n",
pwm_from_reg(data, data->pwm_duty[nr]));
}
static ssize_t show_pwm_freq(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
int index = (data->fan_ctl >> 4) & 0x07;
return sprintf(buf, "%u\n", pwm_freq[index]);
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
u8 reg;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
reg = it87_read_value(data, IT87_REG_FAN_DIV);
switch (nr) {
case 0:
data->fan_div[nr] = reg & 0x07;
break;
case 1:
data->fan_div[nr] = (reg >> 3) & 0x07;
break;
case 2:
data->fan_div[nr] = (reg & 0x40) ? 3 : 1;
break;
}
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
it87_write_value(data, IT87_REG_FAN_MIN[nr], data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
unsigned long val;
int min;
u8 old;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
old = it87_read_value(data, IT87_REG_FAN_DIV);
min = FAN_FROM_REG(data->fan_min[nr], DIV_FROM_REG(data->fan_div[nr]));
switch (nr) {
case 0:
case 1:
data->fan_div[nr] = DIV_TO_REG(val);
break;
case 2:
if (val < 8)
data->fan_div[nr] = 1;
else
data->fan_div[nr] = 3;
}
val = old & 0x80;
val |= (data->fan_div[0] & 0x07);
val |= (data->fan_div[1] & 0x07) << 3;
if (data->fan_div[2] == 3)
val |= 0x1 << 6;
it87_write_value(data, IT87_REG_FAN_DIV, val);
data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
it87_write_value(data, IT87_REG_FAN_MIN[nr], data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static int check_trip_points(struct device *dev, int nr)
{
const struct it87_data *data = dev_get_drvdata(dev);
int i, err = 0;
if (has_old_autopwm(data)) {
for (i = 0; i < 3; i++) {
if (data->auto_temp[nr][i] > data->auto_temp[nr][i + 1])
err = -EINVAL;
}
for (i = 0; i < 2; i++) {
if (data->auto_pwm[nr][i] > data->auto_pwm[nr][i + 1])
err = -EINVAL;
}
}
if (err) {
dev_err(dev, "Inconsistent trip points, not switching to "
"automatic mode\n");
dev_err(dev, "Adjust the trip points and try again\n");
}
return err;
}
static ssize_t set_pwm_enable(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
if (kstrtol(buf, 10, &val) < 0 || val < 0 || val > 2)
return -EINVAL;
if (val == 2) {
if (check_trip_points(dev, nr) < 0)
return -EINVAL;
}
mutex_lock(&data->update_lock);
if (val == 0) {
int tmp;
tmp = it87_read_value(data, IT87_REG_FAN_CTL);
it87_write_value(data, IT87_REG_FAN_CTL, tmp | (1 << nr));
data->fan_main_ctrl &= ~(1 << nr);
it87_write_value(data, IT87_REG_FAN_MAIN_CTRL,
data->fan_main_ctrl);
} else {
if (val == 1)
data->pwm_ctrl[nr] = has_newer_autopwm(data) ?
data->pwm_temp_map[nr] :
data->pwm_duty[nr];
else
data->pwm_ctrl[nr] = 0x80 | data->pwm_temp_map[nr];
it87_write_value(data, IT87_REG_PWM(nr), data->pwm_ctrl[nr]);
data->fan_main_ctrl |= (1 << nr);
it87_write_value(data, IT87_REG_FAN_MAIN_CTRL,
data->fan_main_ctrl);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
if (kstrtol(buf, 10, &val) < 0 || val < 0 || val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
if (has_newer_autopwm(data)) {
if (data->pwm_ctrl[nr] & 0x80) {
mutex_unlock(&data->update_lock);
return -EBUSY;
}
data->pwm_duty[nr] = pwm_to_reg(data, val);
it87_write_value(data, IT87_REG_PWM_DUTY(nr),
data->pwm_duty[nr]);
} else {
data->pwm_duty[nr] = pwm_to_reg(data, val);
if (!(data->pwm_ctrl[nr] & 0x80)) {
data->pwm_ctrl[nr] = data->pwm_duty[nr];
it87_write_value(data, IT87_REG_PWM(nr),
data->pwm_ctrl[nr]);
}
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm_freq(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
unsigned long val;
int i;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
for (i = 0; i < 7; i++) {
if (val > (pwm_freq[i] + pwm_freq[i+1]) / 2)
break;
}
mutex_lock(&data->update_lock);
data->fan_ctl = it87_read_value(data, IT87_REG_FAN_CTL) & 0x8f;
data->fan_ctl |= i << 4;
it87_write_value(data, IT87_REG_FAN_CTL, data->fan_ctl);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_temp_map(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
int map;
if (data->pwm_temp_map[nr] < 3)
map = 1 << data->pwm_temp_map[nr];
else
map = 0;
return sprintf(buf, "%d\n", map);
}
static ssize_t set_pwm_temp_map(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
u8 reg;
if (!has_old_autopwm(data)) {
dev_notice(dev, "Mapping change disabled for safety reasons\n");
return -EINVAL;
}
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
switch (val) {
case (1 << 0):
reg = 0x00;
break;
case (1 << 1):
reg = 0x01;
break;
case (1 << 2):
reg = 0x02;
break;
default:
return -EINVAL;
}
mutex_lock(&data->update_lock);
data->pwm_temp_map[nr] = reg;
if (data->pwm_ctrl[nr] & 0x80) {
data->pwm_ctrl[nr] = 0x80 | data->pwm_temp_map[nr];
it87_write_value(data, IT87_REG_PWM(nr), data->pwm_ctrl[nr]);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_auto_pwm(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct it87_data *data = it87_update_device(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
return sprintf(buf, "%d\n",
pwm_from_reg(data, data->auto_pwm[nr][point]));
}
static ssize_t set_auto_pwm(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
long val;
if (kstrtol(buf, 10, &val) < 0 || val < 0 || val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
data->auto_pwm[nr][point] = pwm_to_reg(data, val);
it87_write_value(data, IT87_REG_AUTO_PWM(nr, point),
data->auto_pwm[nr][point]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_auto_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct it87_data *data = it87_update_device(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->auto_temp[nr][point]));
}
static ssize_t set_auto_temp(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
long val;
if (kstrtol(buf, 10, &val) < 0 || val < -128000 || val > 127000)
return -EINVAL;
mutex_lock(&data->update_lock);
data->auto_temp[nr][point] = TEMP_TO_REG(val);
it87_write_value(data, IT87_REG_AUTO_TEMP(nr, point),
data->auto_temp[nr][point]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan16(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", FAN16_FROM_REG(data->fan[nr]));
}
static ssize_t show_fan16_min(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", FAN16_FROM_REG(data->fan_min[nr]));
}
static ssize_t set_fan16_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN16_TO_REG(val);
it87_write_value(data, IT87_REG_FAN_MIN[nr],
data->fan_min[nr] & 0xff);
it87_write_value(data, IT87_REG_FANX_MIN[nr],
data->fan_min[nr] >> 8);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t clear_intrusion(struct device *dev, struct device_attribute
*attr, const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
long val;
int config;
if (kstrtol(buf, 10, &val) < 0 || val != 0)
return -EINVAL;
mutex_lock(&data->update_lock);
config = it87_read_value(data, IT87_REG_CONFIG);
if (config < 0) {
count = config;
} else {
config |= 1 << 5;
it87_write_value(data, IT87_REG_CONFIG, config);
data->valid = 0;
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
char *buf)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%u\n", (data->beeps >> bitnr) & 1);
}
static ssize_t set_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
if (kstrtol(buf, 10, &val) < 0
|| (val != 0 && val != 1))
return -EINVAL;
mutex_lock(&data->update_lock);
data->beeps = it87_read_value(data, IT87_REG_BEEP_ENABLE);
if (val)
data->beeps |= (1 << bitnr);
else
data->beeps &= ~(1 << bitnr);
it87_write_value(data, IT87_REG_BEEP_ENABLE, data->beeps);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_vrm_reg(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", data->vrm);
}
static ssize_t store_vrm_reg(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
data->vrm = val;
return count;
}
static ssize_t show_vid_reg(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%ld\n", (long) vid_from_reg(data->vid, data->vrm));
}
static ssize_t show_label(struct device *dev, struct device_attribute *attr,
char *buf)
{
static const char * const labels[] = {
"+5V",
"5VSB",
"Vbat",
};
static const char * const labels_it8721[] = {
"+3.3V",
"3VSB",
"Vbat",
};
struct it87_data *data = dev_get_drvdata(dev);
int nr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%s\n", has_12mv_adc(data) ? labels_it8721[nr]
: labels[nr]);
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct it87_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static const struct attribute_group *
it87_get_fan_group(const struct it87_data *data)
{
return has_16bit_fans(data) ? it87_group_fan16 : it87_group_fan;
}
static int __init it87_find(unsigned short *address,
struct it87_sio_data *sio_data)
{
int err;
u16 chip_type;
const char *board_vendor, *board_name;
err = superio_enter();
if (err)
return err;
err = -ENODEV;
chip_type = force_id ? force_id : superio_inw(DEVID);
switch (chip_type) {
case IT8705F_DEVID:
sio_data->type = it87;
break;
case IT8712F_DEVID:
sio_data->type = it8712;
break;
case IT8716F_DEVID:
case IT8726F_DEVID:
sio_data->type = it8716;
break;
case IT8718F_DEVID:
sio_data->type = it8718;
break;
case IT8720F_DEVID:
sio_data->type = it8720;
break;
case IT8721F_DEVID:
sio_data->type = it8721;
break;
case IT8728F_DEVID:
sio_data->type = it8728;
break;
case 0xffff:
goto exit;
default:
pr_debug("Unsupported chip (DEVID=0x%x)\n", chip_type);
goto exit;
}
superio_select(PME);
if (!(superio_inb(IT87_ACT_REG) & 0x01)) {
pr_info("Device not activated, skipping\n");
goto exit;
}
*address = superio_inw(IT87_BASE_REG) & ~(IT87_EXTENT - 1);
if (*address == 0) {
pr_info("Base address not set, skipping\n");
goto exit;
}
err = 0;
sio_data->revision = superio_inb(DEVREV) & 0x0f;
pr_info("Found IT%04xF chip at 0x%x, revision %d\n",
chip_type, *address, sio_data->revision);
sio_data->internal = (1 << 2);
if (sio_data->type == it87) {
sio_data->skip_vid = 1;
superio_select(5);
sio_data->beep_pin = superio_inb(IT87_SIO_BEEP_PIN_REG) & 0x3f;
} else {
int reg;
superio_select(GPIO);
reg = superio_inb(IT87_SIO_GPIO3_REG);
if (sio_data->type == it8721 || sio_data->type == it8728) {
sio_data->skip_vid = 1;
} else {
if (reg & 0x0f) {
pr_info("VID is disabled (pins used for GPIO)\n");
sio_data->skip_vid = 1;
}
}
if (reg & (1 << 6))
sio_data->skip_pwm |= (1 << 2);
if (reg & (1 << 7))
sio_data->skip_fan |= (1 << 2);
reg = superio_inb(IT87_SIO_GPIO5_REG);
if (reg & (1 << 1))
sio_data->skip_pwm |= (1 << 1);
if (reg & (1 << 2))
sio_data->skip_fan |= (1 << 1);
if ((sio_data->type == it8718 || sio_data->type == it8720)
&& !(sio_data->skip_vid))
sio_data->vid_value = superio_inb(IT87_SIO_VID_REG);
reg = superio_inb(IT87_SIO_PINX2_REG);
if (sio_data->type == it8720 && !(reg & (1 << 1))) {
reg |= (1 << 1);
superio_outb(IT87_SIO_PINX2_REG, reg);
pr_notice("Routing internal VCCH to in7\n");
}
if (reg & (1 << 0))
sio_data->internal |= (1 << 0);
if ((reg & (1 << 1)) || sio_data->type == it8721 ||
sio_data->type == it8728)
sio_data->internal |= (1 << 1);
sio_data->beep_pin = superio_inb(IT87_SIO_BEEP_PIN_REG) & 0x3f;
}
if (sio_data->beep_pin)
pr_info("Beeping is supported\n");
board_vendor = dmi_get_system_info(DMI_BOARD_VENDOR);
board_name = dmi_get_system_info(DMI_BOARD_NAME);
if (board_vendor && board_name) {
if (strcmp(board_vendor, "nVIDIA") == 0
&& strcmp(board_name, "FN68PT") == 0) {
pr_info("Disabling pwm2 due to hardware constraints\n");
sio_data->skip_pwm = (1 << 1);
}
}
exit:
superio_exit();
return err;
}
static void it87_remove_files(struct device *dev)
{
struct it87_data *data = platform_get_drvdata(pdev);
struct it87_sio_data *sio_data = dev->platform_data;
const struct attribute_group *fan_group = it87_get_fan_group(data);
int i;
sysfs_remove_group(&dev->kobj, &it87_group);
if (sio_data->beep_pin)
sysfs_remove_group(&dev->kobj, &it87_group_beep);
for (i = 0; i < 5; i++) {
if (!(data->has_fan & (1 << i)))
continue;
sysfs_remove_group(&dev->kobj, &fan_group[i]);
if (sio_data->beep_pin)
sysfs_remove_file(&dev->kobj,
it87_attributes_fan_beep[i]);
}
for (i = 0; i < 3; i++) {
if (sio_data->skip_pwm & (1 << 0))
continue;
sysfs_remove_group(&dev->kobj, &it87_group_pwm[i]);
if (has_old_autopwm(data))
sysfs_remove_group(&dev->kobj,
&it87_group_autopwm[i]);
}
if (!sio_data->skip_vid)
sysfs_remove_group(&dev->kobj, &it87_group_vid);
sysfs_remove_group(&dev->kobj, &it87_group_label);
}
static int __devinit it87_probe(struct platform_device *pdev)
{
struct it87_data *data;
struct resource *res;
struct device *dev = &pdev->dev;
struct it87_sio_data *sio_data = dev->platform_data;
const struct attribute_group *fan_group;
int err = 0, i;
int enable_pwm_interface;
int fan_beep_need_rw;
static const char * const names[] = {
"it87",
"it8712",
"it8716",
"it8718",
"it8720",
"it8721",
"it8728",
};
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!request_region(res->start, IT87_EC_EXTENT, DRVNAME)) {
dev_err(dev, "Failed to request region 0x%lx-0x%lx\n",
(unsigned long)res->start,
(unsigned long)(res->start + IT87_EC_EXTENT - 1));
err = -EBUSY;
goto ERROR0;
}
data = kzalloc(sizeof(struct it87_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto ERROR1;
}
data->addr = res->start;
data->type = sio_data->type;
data->revision = sio_data->revision;
data->name = names[sio_data->type];
if ((it87_read_value(data, IT87_REG_CONFIG) & 0x80)
|| it87_read_value(data, IT87_REG_CHIPID) != 0x90) {
err = -ENODEV;
goto ERROR2;
}
platform_set_drvdata(pdev, data);
mutex_init(&data->update_lock);
enable_pwm_interface = it87_check_pwm(dev);
if (has_12mv_adc(data)) {
if (sio_data->internal & (1 << 0))
data->in_scaled |= (1 << 3);
if (sio_data->internal & (1 << 1))
data->in_scaled |= (1 << 7);
if (sio_data->internal & (1 << 2))
data->in_scaled |= (1 << 8);
}
it87_init_device(pdev);
err = sysfs_create_group(&dev->kobj, &it87_group);
if (err)
goto ERROR2;
if (sio_data->beep_pin) {
err = sysfs_create_group(&dev->kobj, &it87_group_beep);
if (err)
goto ERROR4;
}
fan_group = it87_get_fan_group(data);
fan_beep_need_rw = 1;
for (i = 0; i < 5; i++) {
if (!(data->has_fan & (1 << i)))
continue;
err = sysfs_create_group(&dev->kobj, &fan_group[i]);
if (err)
goto ERROR4;
if (sio_data->beep_pin) {
err = sysfs_create_file(&dev->kobj,
it87_attributes_fan_beep[i]);
if (err)
goto ERROR4;
if (!fan_beep_need_rw)
continue;
if (sysfs_chmod_file(&dev->kobj,
it87_attributes_fan_beep[i],
S_IRUGO | S_IWUSR))
dev_dbg(dev, "chmod +w fan%d_beep failed\n",
i + 1);
fan_beep_need_rw = 0;
}
}
if (enable_pwm_interface) {
for (i = 0; i < 3; i++) {
if (sio_data->skip_pwm & (1 << i))
continue;
err = sysfs_create_group(&dev->kobj,
&it87_group_pwm[i]);
if (err)
goto ERROR4;
if (!has_old_autopwm(data))
continue;
err = sysfs_create_group(&dev->kobj,
&it87_group_autopwm[i]);
if (err)
goto ERROR4;
}
}
if (!sio_data->skip_vid) {
data->vrm = vid_which_vrm();
data->vid = sio_data->vid_value;
err = sysfs_create_group(&dev->kobj, &it87_group_vid);
if (err)
goto ERROR4;
}
for (i = 0; i < 3; i++) {
if (!(sio_data->internal & (1 << i)))
continue;
err = sysfs_create_file(&dev->kobj,
it87_attributes_label[i]);
if (err)
goto ERROR4;
}
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto ERROR4;
}
return 0;
ERROR4:
it87_remove_files(dev);
ERROR2:
platform_set_drvdata(pdev, NULL);
kfree(data);
ERROR1:
release_region(res->start, IT87_EC_EXTENT);
ERROR0:
return err;
}
static int __devexit it87_remove(struct platform_device *pdev)
{
struct it87_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
it87_remove_files(&pdev->dev);
release_region(data->addr, IT87_EC_EXTENT);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static int it87_read_value(struct it87_data *data, u8 reg)
{
outb_p(reg, data->addr + IT87_ADDR_REG_OFFSET);
return inb_p(data->addr + IT87_DATA_REG_OFFSET);
}
static void it87_write_value(struct it87_data *data, u8 reg, u8 value)
{
outb_p(reg, data->addr + IT87_ADDR_REG_OFFSET);
outb_p(value, data->addr + IT87_DATA_REG_OFFSET);
}
static int __devinit it87_check_pwm(struct device *dev)
{
struct it87_data *data = dev_get_drvdata(dev);
int tmp = it87_read_value(data, IT87_REG_FAN_CTL);
if ((tmp & 0x87) == 0) {
if (fix_pwm_polarity) {
int i;
u8 pwm[3];
for (i = 0; i < 3; i++)
pwm[i] = it87_read_value(data,
IT87_REG_PWM(i));
if (!((pwm[0] | pwm[1] | pwm[2]) & 0x80)) {
dev_info(dev, "Reconfiguring PWM to "
"active high polarity\n");
it87_write_value(data, IT87_REG_FAN_CTL,
tmp | 0x87);
for (i = 0; i < 3; i++)
it87_write_value(data,
IT87_REG_PWM(i),
0x7f & ~pwm[i]);
return 1;
}
dev_info(dev, "PWM configuration is "
"too broken to be fixed\n");
}
dev_info(dev, "Detected broken BIOS "
"defaults, disabling PWM interface\n");
return 0;
} else if (fix_pwm_polarity) {
dev_info(dev, "PWM configuration looks "
"sane, won't touch\n");
}
return 1;
}
static void __devinit it87_init_device(struct platform_device *pdev)
{
struct it87_sio_data *sio_data = pdev->dev.platform_data;
struct it87_data *data = platform_get_drvdata(pdev);
int tmp, i;
u8 mask;
for (i = 0; i < 3; i++) {
data->pwm_temp_map[i] = i;
data->pwm_duty[i] = 0x7f;
data->auto_pwm[i][3] = 0x7f;
}
for (i = 0; i < 8; i++) {
tmp = it87_read_value(data, IT87_REG_VIN_MIN(i));
if (tmp == 0xff)
it87_write_value(data, IT87_REG_VIN_MIN(i), 0);
}
for (i = 0; i < 3; i++) {
tmp = it87_read_value(data, IT87_REG_TEMP_HIGH(i));
if (tmp == 0xff)
it87_write_value(data, IT87_REG_TEMP_HIGH(i), 127);
}
tmp = it87_read_value(data, IT87_REG_VIN_ENABLE);
if ((tmp & 0xff) == 0) {
it87_write_value(data, IT87_REG_VIN_ENABLE, 0xff);
}
mask = 0x70 & ~(sio_data->skip_fan << 4);
data->fan_main_ctrl = it87_read_value(data, IT87_REG_FAN_MAIN_CTRL);
if ((data->fan_main_ctrl & mask) == 0) {
data->fan_main_ctrl |= mask;
it87_write_value(data, IT87_REG_FAN_MAIN_CTRL,
data->fan_main_ctrl);
}
data->has_fan = (data->fan_main_ctrl >> 4) & 0x07;
if (has_16bit_fans(data)) {
tmp = it87_read_value(data, IT87_REG_FAN_16BIT);
if (~tmp & 0x07 & data->has_fan) {
dev_dbg(&pdev->dev,
"Setting fan1-3 to 16-bit mode\n");
it87_write_value(data, IT87_REG_FAN_16BIT,
tmp | 0x07);
}
if (data->type != it87) {
if (tmp & (1 << 4))
data->has_fan |= (1 << 3);
if (tmp & (1 << 5))
data->has_fan |= (1 << 4);
}
}
data->has_fan &= ~sio_data->skip_fan;
it87_write_value(data, IT87_REG_CONFIG,
(it87_read_value(data, IT87_REG_CONFIG) & 0x36)
| (update_vbat ? 0x41 : 0x01));
}
static void it87_update_pwm_ctrl(struct it87_data *data, int nr)
{
data->pwm_ctrl[nr] = it87_read_value(data, IT87_REG_PWM(nr));
if (has_newer_autopwm(data)) {
data->pwm_temp_map[nr] = data->pwm_ctrl[nr] & 0x03;
data->pwm_duty[nr] = it87_read_value(data,
IT87_REG_PWM_DUTY(nr));
} else {
if (data->pwm_ctrl[nr] & 0x80)
data->pwm_temp_map[nr] = data->pwm_ctrl[nr] & 0x03;
else
data->pwm_duty[nr] = data->pwm_ctrl[nr] & 0x7f;
}
if (has_old_autopwm(data)) {
int i;
for (i = 0; i < 5 ; i++)
data->auto_temp[nr][i] = it87_read_value(data,
IT87_REG_AUTO_TEMP(nr, i));
for (i = 0; i < 3 ; i++)
data->auto_pwm[nr][i] = it87_read_value(data,
IT87_REG_AUTO_PWM(nr, i));
}
}
static struct it87_data *it87_update_device(struct device *dev)
{
struct it87_data *data = dev_get_drvdata(dev);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
if (update_vbat) {
it87_write_value(data, IT87_REG_CONFIG,
it87_read_value(data, IT87_REG_CONFIG) | 0x40);
}
for (i = 0; i <= 7; i++) {
data->in[i] =
it87_read_value(data, IT87_REG_VIN(i));
data->in_min[i] =
it87_read_value(data, IT87_REG_VIN_MIN(i));
data->in_max[i] =
it87_read_value(data, IT87_REG_VIN_MAX(i));
}
data->in[8] = it87_read_value(data, IT87_REG_VIN(8));
for (i = 0; i < 5; i++) {
if (!(data->has_fan & (1 << i)))
continue;
data->fan_min[i] =
it87_read_value(data, IT87_REG_FAN_MIN[i]);
data->fan[i] = it87_read_value(data,
IT87_REG_FAN[i]);
if (has_16bit_fans(data)) {
data->fan[i] |= it87_read_value(data,
IT87_REG_FANX[i]) << 8;
data->fan_min[i] |= it87_read_value(data,
IT87_REG_FANX_MIN[i]) << 8;
}
}
for (i = 0; i < 3; i++) {
data->temp[i] =
it87_read_value(data, IT87_REG_TEMP(i));
data->temp_high[i] =
it87_read_value(data, IT87_REG_TEMP_HIGH(i));
data->temp_low[i] =
it87_read_value(data, IT87_REG_TEMP_LOW(i));
}
if ((data->has_fan & 0x07) && !has_16bit_fans(data)) {
i = it87_read_value(data, IT87_REG_FAN_DIV);
data->fan_div[0] = i & 0x07;
data->fan_div[1] = (i >> 3) & 0x07;
data->fan_div[2] = (i & 0x40) ? 3 : 1;
}
data->alarms =
it87_read_value(data, IT87_REG_ALARM1) |
(it87_read_value(data, IT87_REG_ALARM2) << 8) |
(it87_read_value(data, IT87_REG_ALARM3) << 16);
data->beeps = it87_read_value(data, IT87_REG_BEEP_ENABLE);
data->fan_main_ctrl = it87_read_value(data,
IT87_REG_FAN_MAIN_CTRL);
data->fan_ctl = it87_read_value(data, IT87_REG_FAN_CTL);
for (i = 0; i < 3; i++)
it87_update_pwm_ctrl(data, i);
data->sensor = it87_read_value(data, IT87_REG_TEMP_ENABLE);
if (data->type == it8712 || data->type == it8716) {
data->vid = it87_read_value(data, IT87_REG_VID);
data->vid &= 0x3f;
}
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init it87_device_add(unsigned short address,
const struct it87_sio_data *sio_data)
{
struct resource res = {
.start = address + IT87_EC_OFFSET,
.end = address + IT87_EC_OFFSET + IT87_EC_EXTENT - 1,
.name = DRVNAME,
.flags = IORESOURCE_IO,
};
int err;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit;
pdev = platform_device_alloc(DRVNAME, address);
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
err = platform_device_add_data(pdev, sio_data,
sizeof(struct it87_sio_data));
if (err) {
pr_err("Platform data allocation failed\n");
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
return err;
}
static int __init sm_it87_init(void)
{
int err;
unsigned short isa_address = 0;
struct it87_sio_data sio_data;
memset(&sio_data, 0, sizeof(struct it87_sio_data));
err = it87_find(&isa_address, &sio_data);
if (err)
return err;
err = platform_driver_register(&it87_driver);
if (err)
return err;
err = it87_device_add(isa_address, &sio_data);
if (err) {
platform_driver_unregister(&it87_driver);
return err;
}
return 0;
}
static void __exit sm_it87_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&it87_driver);
}
