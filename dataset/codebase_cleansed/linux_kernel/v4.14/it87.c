static inline int superio_inb(int ioreg, int reg)
{
outb(reg, ioreg);
return inb(ioreg + 1);
}
static inline void superio_outb(int ioreg, int reg, int val)
{
outb(reg, ioreg);
outb(val, ioreg + 1);
}
static int superio_inw(int ioreg, int reg)
{
int val;
outb(reg++, ioreg);
val = inb(ioreg + 1) << 8;
outb(reg, ioreg);
val |= inb(ioreg + 1);
return val;
}
static inline void superio_select(int ioreg, int ldn)
{
outb(DEV, ioreg);
outb(ldn, ioreg + 1);
}
static inline int superio_enter(int ioreg)
{
if (!request_muxed_region(ioreg, 2, DRVNAME))
return -EBUSY;
outb(0x87, ioreg);
outb(0x01, ioreg);
outb(0x55, ioreg);
outb(ioreg == REG_4E ? 0xaa : 0x55, ioreg);
return 0;
}
static inline void superio_exit(int ioreg)
{
outb(0x02, ioreg);
outb(0x02, ioreg + 1);
release_region(ioreg, 2);
}
static int adc_lsb(const struct it87_data *data, int nr)
{
int lsb;
if (has_12mv_adc(data))
lsb = 120;
else if (has_10_9mv_adc(data))
lsb = 109;
else
lsb = 160;
if (data->in_scaled & BIT(nr))
lsb <<= 1;
return lsb;
}
static u8 in_to_reg(const struct it87_data *data, int nr, long val)
{
val = DIV_ROUND_CLOSEST(val * 10, adc_lsb(data, nr));
return clamp_val(val, 0, 255);
}
static int in_from_reg(const struct it87_data *data, int nr, int val)
{
return DIV_ROUND_CLOSEST(val * adc_lsb(data, nr), 10);
}
static inline u8 FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 255;
rpm = clamp_val(rpm, 1, 1000000);
return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static inline u16 FAN16_TO_REG(long rpm)
{
if (rpm == 0)
return 0xffff;
return clamp_val((1350000 + rpm) / (rpm * 2), 1, 0xfffe);
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
static void it87_update_pwm_ctrl(struct it87_data *data, int nr)
{
data->pwm_ctrl[nr] = it87_read_value(data, IT87_REG_PWM[nr]);
if (has_newer_autopwm(data)) {
data->pwm_temp_map[nr] = data->pwm_ctrl[nr] & 0x03;
data->pwm_duty[nr] = it87_read_value(data,
IT87_REG_PWM_DUTY[nr]);
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
} else if (has_newer_autopwm(data)) {
int i;
data->auto_temp[nr][0] =
it87_read_value(data, IT87_REG_AUTO_TEMP(nr, 5));
for (i = 0; i < 3 ; i++)
data->auto_temp[nr][i + 1] =
it87_read_value(data,
IT87_REG_AUTO_TEMP(nr, i));
data->auto_pwm[nr][0] =
it87_read_value(data, IT87_REG_AUTO_TEMP(nr, 3));
data->auto_pwm[nr][1] =
it87_read_value(data, IT87_REG_AUTO_TEMP(nr, 4));
}
}
static struct it87_data *it87_update_device(struct device *dev)
{
struct it87_data *data = dev_get_drvdata(dev);
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2) ||
!data->valid) {
if (update_vbat) {
it87_write_value(data, IT87_REG_CONFIG,
it87_read_value(data, IT87_REG_CONFIG) | 0x40);
}
for (i = 0; i < NUM_VIN; i++) {
if (!(data->has_in & BIT(i)))
continue;
data->in[i][0] =
it87_read_value(data, IT87_REG_VIN[i]);
if (i >= NUM_VIN_LIMIT)
continue;
data->in[i][1] =
it87_read_value(data, IT87_REG_VIN_MIN(i));
data->in[i][2] =
it87_read_value(data, IT87_REG_VIN_MAX(i));
}
for (i = 0; i < NUM_FAN; i++) {
if (!(data->has_fan & BIT(i)))
continue;
data->fan[i][1] =
it87_read_value(data, IT87_REG_FAN_MIN[i]);
data->fan[i][0] = it87_read_value(data,
IT87_REG_FAN[i]);
if (has_16bit_fans(data)) {
data->fan[i][0] |= it87_read_value(data,
IT87_REG_FANX[i]) << 8;
data->fan[i][1] |= it87_read_value(data,
IT87_REG_FANX_MIN[i]) << 8;
}
}
for (i = 0; i < NUM_TEMP; i++) {
if (!(data->has_temp & BIT(i)))
continue;
data->temp[i][0] =
it87_read_value(data, IT87_REG_TEMP(i));
if (has_temp_offset(data) && i < NUM_TEMP_OFFSET)
data->temp[i][3] =
it87_read_value(data,
IT87_REG_TEMP_OFFSET[i]);
if (i >= NUM_TEMP_LIMIT)
continue;
data->temp[i][1] =
it87_read_value(data, IT87_REG_TEMP_LOW(i));
data->temp[i][2] =
it87_read_value(data, IT87_REG_TEMP_HIGH(i));
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
for (i = 0; i < NUM_PWM; i++) {
if (!(data->has_pwm & BIT(i)))
continue;
it87_update_pwm_ctrl(data, i);
}
data->sensor = it87_read_value(data, IT87_REG_TEMP_ENABLE);
data->extra = it87_read_value(data, IT87_REG_TEMP_EXTRA);
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
static ssize_t show_in(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct it87_data *data = it87_update_device(dev);
int index = sattr->index;
int nr = sattr->nr;
return sprintf(buf, "%d\n", in_from_reg(data, nr, data->in[nr][index]));
}
static ssize_t set_in(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct it87_data *data = dev_get_drvdata(dev);
int index = sattr->index;
int nr = sattr->nr;
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->in[nr][index] = in_to_reg(data, nr, val);
it87_write_value(data,
index == 1 ? IT87_REG_VIN_MIN(nr)
: IT87_REG_VIN_MAX(nr),
data->in[nr][index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%d\n", TEMP_FROM_REG(data->temp[nr][index]));
}
static ssize_t set_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
u8 reg, regval;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
switch (index) {
default:
case 1:
reg = IT87_REG_TEMP_LOW(nr);
break;
case 2:
reg = IT87_REG_TEMP_HIGH(nr);
break;
case 3:
regval = it87_read_value(data, IT87_REG_BEEP_ENABLE);
if (!(regval & 0x80)) {
regval |= 0x80;
it87_write_value(data, IT87_REG_BEEP_ENABLE, regval);
}
data->valid = 0;
reg = IT87_REG_TEMP_OFFSET[nr];
break;
}
data->temp[nr][index] = TEMP_TO_REG(val);
it87_write_value(data, reg, data->temp[nr][index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_type(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = it87_update_device(dev);
u8 reg = data->sensor;
u8 extra = data->extra;
if ((has_temp_peci(data, nr) && (reg >> 6 == nr + 1)) ||
(has_temp_old_peci(data, nr) && (extra & 0x80)))
return sprintf(buf, "6\n");
if (reg & (1 << nr))
return sprintf(buf, "3\n");
if (reg & (8 << nr))
return sprintf(buf, "4\n");
return sprintf(buf, "0\n");
}
static ssize_t set_temp_type(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
u8 reg, extra;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
reg = it87_read_value(data, IT87_REG_TEMP_ENABLE);
reg &= ~(1 << nr);
reg &= ~(8 << nr);
if (has_temp_peci(data, nr) && (reg >> 6 == nr + 1 || val == 6))
reg &= 0x3f;
extra = it87_read_value(data, IT87_REG_TEMP_EXTRA);
if (has_temp_old_peci(data, nr) && ((extra & 0x80) || val == 6))
extra &= 0x7f;
if (val == 2) {
dev_warn(dev,
"Sensor type 2 is deprecated, please use 4 instead\n");
val = 4;
}
if (val == 3)
reg |= 1 << nr;
else if (val == 4)
reg |= 8 << nr;
else if (has_temp_peci(data, nr) && val == 6)
reg |= (nr + 1) << 6;
else if (has_temp_old_peci(data, nr) && val == 6)
extra |= 0x80;
else if (val != 0)
return -EINVAL;
mutex_lock(&data->update_lock);
data->sensor = reg;
data->extra = extra;
it87_write_value(data, IT87_REG_TEMP_ENABLE, data->sensor);
if (has_temp_old_peci(data, nr))
it87_write_value(data, IT87_REG_TEMP_EXTRA, data->extra);
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static int pwm_mode(const struct it87_data *data, int nr)
{
if (data->type != it8603 && nr < 3 && !(data->fan_main_ctrl & BIT(nr)))
return 0;
if (data->pwm_ctrl[nr] & 0x80)
return 2;
if ((data->type == it8603 || nr >= 3) &&
data->pwm_duty[nr] == pwm_to_reg(data, 0xff))
return 0;
return 1;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
int speed;
struct it87_data *data = it87_update_device(dev);
speed = has_16bit_fans(data) ?
FAN16_FROM_REG(data->fan[nr][index]) :
FAN_FROM_REG(data->fan[nr][index],
DIV_FROM_REG(data->fan_div[nr]));
return sprintf(buf, "%d\n", speed);
}
static ssize_t show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = it87_update_device(dev);
int nr = sensor_attr->index;
return sprintf(buf, "%lu\n", DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t show_pwm_enable(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = it87_update_device(dev);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n", pwm_mode(data, nr));
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = it87_update_device(dev);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n",
pwm_from_reg(data, data->pwm_duty[nr]));
}
static ssize_t show_pwm_freq(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = it87_update_device(dev);
int nr = sensor_attr->index;
unsigned int freq;
int index;
if (has_pwm_freq2(data) && nr == 1)
index = (data->extra >> 4) & 0x07;
else
index = (data->fan_ctl >> 4) & 0x07;
freq = pwm_freq[index] / (has_newer_autopwm(data) ? 256 : 128);
return sprintf(buf, "%u\n", freq);
}
static ssize_t set_fan(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
u8 reg;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
if (has_16bit_fans(data)) {
data->fan[nr][index] = FAN16_TO_REG(val);
it87_write_value(data, IT87_REG_FAN_MIN[nr],
data->fan[nr][index] & 0xff);
it87_write_value(data, IT87_REG_FANX_MIN[nr],
data->fan[nr][index] >> 8);
} else {
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
data->fan[nr][index] =
FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
it87_write_value(data, IT87_REG_FAN_MIN[nr],
data->fan[nr][index]);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_div(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = dev_get_drvdata(dev);
int nr = sensor_attr->index;
unsigned long val;
int min;
u8 old;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->update_lock);
old = it87_read_value(data, IT87_REG_FAN_DIV);
min = FAN_FROM_REG(data->fan[nr][1], DIV_FROM_REG(data->fan_div[nr]));
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
data->fan[nr][1] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
it87_write_value(data, IT87_REG_FAN_MIN[nr], data->fan[nr][1]);
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
} else if (has_newer_autopwm(data)) {
for (i = 1; i < 3; i++) {
if (data->auto_temp[nr][i] > data->auto_temp[nr][i + 1])
err = -EINVAL;
}
}
if (err) {
dev_err(dev,
"Inconsistent trip points, not switching to automatic mode\n");
dev_err(dev, "Adjust the trip points and try again\n");
}
return err;
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = dev_get_drvdata(dev);
int nr = sensor_attr->index;
long val;
if (kstrtol(buf, 10, &val) < 0 || val < 0 || val > 2)
return -EINVAL;
if (val == 2) {
if (check_trip_points(dev, nr) < 0)
return -EINVAL;
}
mutex_lock(&data->update_lock);
if (val == 0) {
if (nr < 3 && data->type != it8603) {
int tmp;
tmp = it87_read_value(data, IT87_REG_FAN_CTL);
it87_write_value(data, IT87_REG_FAN_CTL, tmp | BIT(nr));
data->fan_main_ctrl &= ~BIT(nr);
it87_write_value(data, IT87_REG_FAN_MAIN_CTRL,
data->fan_main_ctrl);
} else {
u8 ctrl;
data->pwm_duty[nr] = pwm_to_reg(data, 0xff);
it87_write_value(data, IT87_REG_PWM_DUTY[nr],
data->pwm_duty[nr]);
if (has_newer_autopwm(data)) {
ctrl = (data->pwm_ctrl[nr] & 0x7c) |
data->pwm_temp_map[nr];
} else {
ctrl = data->pwm_duty[nr];
}
data->pwm_ctrl[nr] = ctrl;
it87_write_value(data, IT87_REG_PWM[nr], ctrl);
}
} else {
u8 ctrl;
if (has_newer_autopwm(data)) {
ctrl = (data->pwm_ctrl[nr] & 0x7c) |
data->pwm_temp_map[nr];
if (val != 1)
ctrl |= 0x80;
} else {
ctrl = (val == 1 ? data->pwm_duty[nr] : 0x80);
}
data->pwm_ctrl[nr] = ctrl;
it87_write_value(data, IT87_REG_PWM[nr], ctrl);
if (data->type != it8603 && nr < 3) {
data->fan_main_ctrl |= BIT(nr);
it87_write_value(data, IT87_REG_FAN_MAIN_CTRL,
data->fan_main_ctrl);
}
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = dev_get_drvdata(dev);
int nr = sensor_attr->index;
long val;
if (kstrtol(buf, 10, &val) < 0 || val < 0 || val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
it87_update_pwm_ctrl(data, nr);
if (has_newer_autopwm(data)) {
if (data->pwm_ctrl[nr] & 0x80) {
mutex_unlock(&data->update_lock);
return -EBUSY;
}
data->pwm_duty[nr] = pwm_to_reg(data, val);
it87_write_value(data, IT87_REG_PWM_DUTY[nr],
data->pwm_duty[nr]);
} else {
data->pwm_duty[nr] = pwm_to_reg(data, val);
if (!(data->pwm_ctrl[nr] & 0x80)) {
data->pwm_ctrl[nr] = data->pwm_duty[nr];
it87_write_value(data, IT87_REG_PWM[nr],
data->pwm_ctrl[nr]);
}
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm_freq(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = dev_get_drvdata(dev);
int nr = sensor_attr->index;
unsigned long val;
int i;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
val = clamp_val(val, 0, 1000000);
val *= has_newer_autopwm(data) ? 256 : 128;
for (i = 0; i < 7; i++) {
if (val > (pwm_freq[i] + pwm_freq[i + 1]) / 2)
break;
}
mutex_lock(&data->update_lock);
if (nr == 0) {
data->fan_ctl = it87_read_value(data, IT87_REG_FAN_CTL) & 0x8f;
data->fan_ctl |= i << 4;
it87_write_value(data, IT87_REG_FAN_CTL, data->fan_ctl);
} else {
data->extra = it87_read_value(data, IT87_REG_TEMP_EXTRA) & 0x8f;
data->extra |= i << 4;
it87_write_value(data, IT87_REG_TEMP_EXTRA, data->extra);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_temp_map(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = it87_update_device(dev);
int nr = sensor_attr->index;
int map;
map = data->pwm_temp_map[nr];
if (map >= 3)
map = 0;
if (nr >= 3)
map += 3;
return sprintf(buf, "%d\n", (int)BIT(map));
}
static ssize_t set_pwm_temp_map(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
struct it87_data *data = dev_get_drvdata(dev);
int nr = sensor_attr->index;
long val;
u8 reg;
if (kstrtol(buf, 10, &val) < 0)
return -EINVAL;
if (nr >= 3)
val -= 3;
switch (val) {
case BIT(0):
reg = 0x00;
break;
case BIT(1):
reg = 0x01;
break;
case BIT(2):
reg = 0x02;
break;
default:
return -EINVAL;
}
mutex_lock(&data->update_lock);
it87_update_pwm_ctrl(data, nr);
data->pwm_temp_map[nr] = reg;
if (data->pwm_ctrl[nr] & 0x80) {
data->pwm_ctrl[nr] = (data->pwm_ctrl[nr] & 0xfc) |
data->pwm_temp_map[nr];
it87_write_value(data, IT87_REG_PWM[nr], data->pwm_ctrl[nr]);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_auto_pwm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
return sprintf(buf, "%d\n",
pwm_from_reg(data, data->auto_pwm[nr][point]));
}
static ssize_t set_auto_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
int regaddr;
long val;
if (kstrtol(buf, 10, &val) < 0 || val < 0 || val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
data->auto_pwm[nr][point] = pwm_to_reg(data, val);
if (has_newer_autopwm(data))
regaddr = IT87_REG_AUTO_TEMP(nr, 3);
else
regaddr = IT87_REG_AUTO_PWM(nr, point);
it87_write_value(data, regaddr, data->auto_pwm[nr][point]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_auto_pwm_slope(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct it87_data *data = it87_update_device(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n", data->auto_pwm[nr][1] & 0x7f);
}
static ssize_t set_auto_pwm_slope(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0 || val > 127)
return -EINVAL;
mutex_lock(&data->update_lock);
data->auto_pwm[nr][1] = (data->auto_pwm[nr][1] & 0x80) | val;
it87_write_value(data, IT87_REG_AUTO_TEMP(nr, 4),
data->auto_pwm[nr][1]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_auto_temp(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
int reg;
if (has_old_autopwm(data) || point)
reg = data->auto_temp[nr][point];
else
reg = data->auto_temp[nr][1] - (data->auto_temp[nr][0] & 0x1f);
return sprintf(buf, "%d\n", TEMP_FROM_REG(reg));
}
static ssize_t set_auto_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sensor_attr =
to_sensor_dev_attr_2(attr);
int nr = sensor_attr->nr;
int point = sensor_attr->index;
long val;
int reg;
if (kstrtol(buf, 10, &val) < 0 || val < -128000 || val > 127000)
return -EINVAL;
mutex_lock(&data->update_lock);
if (has_newer_autopwm(data) && !point) {
reg = data->auto_temp[nr][1] - TEMP_TO_REG(val);
reg = clamp_val(reg, 0, 0x1f) | (data->auto_temp[nr][0] & 0xe0);
data->auto_temp[nr][0] = reg;
it87_write_value(data, IT87_REG_AUTO_TEMP(nr, 5), reg);
} else {
reg = TEMP_TO_REG(val);
data->auto_temp[nr][point] = reg;
if (has_newer_autopwm(data))
point--;
it87_write_value(data, IT87_REG_AUTO_TEMP(nr, point), reg);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t alarms_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%u\n", data->alarms);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t clear_intrusion(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
int config;
long val;
if (kstrtol(buf, 10, &val) < 0 || val != 0)
return -EINVAL;
mutex_lock(&data->update_lock);
config = it87_read_value(data, IT87_REG_CONFIG);
if (config < 0) {
count = config;
} else {
config |= BIT(5);
it87_write_value(data, IT87_REG_CONFIG, config);
data->valid = 0;
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_beep(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = it87_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u\n", (data->beeps >> bitnr) & 1);
}
static ssize_t set_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int bitnr = to_sensor_dev_attr(attr)->index;
struct it87_data *data = dev_get_drvdata(dev);
long val;
if (kstrtol(buf, 10, &val) < 0 || (val != 0 && val != 1))
return -EINVAL;
mutex_lock(&data->update_lock);
data->beeps = it87_read_value(data, IT87_REG_BEEP_ENABLE);
if (val)
data->beeps |= BIT(bitnr);
else
data->beeps &= ~BIT(bitnr);
it87_write_value(data, IT87_REG_BEEP_ENABLE, data->beeps);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t vrm_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct it87_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", data->vrm);
}
static ssize_t vrm_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct it87_data *data = dev_get_drvdata(dev);
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
data->vrm = val;
return count;
}
static ssize_t cpu0_vid_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct it87_data *data = it87_update_device(dev);
return sprintf(buf, "%ld\n", (long)vid_from_reg(data->vid, data->vrm));
}
static ssize_t show_label(struct device *dev, struct device_attribute *attr,
char *buf)
{
static const char * const labels[] = {
"+5V",
"5VSB",
"Vbat",
"AVCC",
};
static const char * const labels_it8721[] = {
"+3.3V",
"3VSB",
"Vbat",
"+3.3V",
};
struct it87_data *data = dev_get_drvdata(dev);
int nr = to_sensor_dev_attr(attr)->index;
const char *label;
if (has_vin3_5v(data) && nr == 0)
label = labels[0];
else if (has_12mv_adc(data) || has_10_9mv_adc(data))
label = labels_it8721[nr];
else
label = labels[nr];
return sprintf(buf, "%s\n", label);
}
static umode_t it87_in_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct it87_data *data = dev_get_drvdata(dev);
int i = index / 5;
int a = index % 5;
if (index >= 40) {
i = index - 40 + 8;
a = 0;
}
if (!(data->has_in & BIT(i)))
return 0;
if (a == 4 && !data->has_beep)
return 0;
return attr->mode;
}
static umode_t it87_temp_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct it87_data *data = dev_get_drvdata(dev);
int i = index / 7;
int a = index % 7;
if (index >= 21) {
i = index - 21 + 3;
a = 0;
}
if (!(data->has_temp & BIT(i)))
return 0;
if (a == 5 && !has_temp_offset(data))
return 0;
if (a == 6 && !data->has_beep)
return 0;
return attr->mode;
}
static umode_t it87_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct it87_data *data = dev_get_drvdata(dev);
if ((index == 2 || index == 3) && !data->has_vid)
return 0;
if (index > 3 && !(data->in_internal & BIT(index - 4)))
return 0;
return attr->mode;
}
static umode_t it87_fan_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct it87_data *data = dev_get_drvdata(dev);
int i = index / 5;
int a = index % 5;
if (index >= 15) {
i = (index - 15) / 4 + 3;
a = (index - 15) % 4;
}
if (!(data->has_fan & BIT(i)))
return 0;
if (a == 3) {
if (!data->has_beep)
return 0;
if (i == __ffs(data->has_fan))
return attr->mode | S_IWUSR;
}
if (a == 4 && has_16bit_fans(data))
return 0;
return attr->mode;
}
static umode_t it87_pwm_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct it87_data *data = dev_get_drvdata(dev);
int i = index / 4;
int a = index % 4;
if (!(data->has_pwm & BIT(i)))
return 0;
if (a == 3 && (has_old_autopwm(data) || has_newer_autopwm(data)))
return attr->mode | S_IWUSR;
if (has_pwm_freq2(data) && i == 1 && a == 2)
return attr->mode | S_IWUSR;
return attr->mode;
}
static umode_t it87_auto_pwm_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct it87_data *data = dev_get_drvdata(dev);
int i = index / 11;
int a = index % 11;
if (index >= 33) {
i = (index - 33) / 6 + 3;
a = (index - 33) % 6 + 4;
}
if (!(data->has_pwm & BIT(i)))
return 0;
if (has_newer_autopwm(data)) {
if (a < 4)
return 0;
if (a == 8)
return 0;
}
if (has_old_autopwm(data)) {
if (a >= 9)
return 0;
}
return attr->mode;
}
static int __init it87_find(int sioaddr, unsigned short *address,
struct it87_sio_data *sio_data)
{
int err;
u16 chip_type;
const char *board_vendor, *board_name;
const struct it87_devices *config;
err = superio_enter(sioaddr);
if (err)
return err;
err = -ENODEV;
chip_type = force_id ? force_id : superio_inw(sioaddr, DEVID);
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
case IT8732F_DEVID:
sio_data->type = it8732;
break;
case IT8792E_DEVID:
sio_data->type = it8792;
break;
case IT8771E_DEVID:
sio_data->type = it8771;
break;
case IT8772E_DEVID:
sio_data->type = it8772;
break;
case IT8781F_DEVID:
sio_data->type = it8781;
break;
case IT8782F_DEVID:
sio_data->type = it8782;
break;
case IT8783E_DEVID:
sio_data->type = it8783;
break;
case IT8786E_DEVID:
sio_data->type = it8786;
break;
case IT8790E_DEVID:
sio_data->type = it8790;
break;
case IT8603E_DEVID:
case IT8623E_DEVID:
sio_data->type = it8603;
break;
case IT8620E_DEVID:
sio_data->type = it8620;
break;
case IT8622E_DEVID:
sio_data->type = it8622;
break;
case IT8628E_DEVID:
sio_data->type = it8628;
break;
case 0xffff:
goto exit;
default:
pr_debug("Unsupported chip (DEVID=0x%x)\n", chip_type);
goto exit;
}
superio_select(sioaddr, PME);
if (!(superio_inb(sioaddr, IT87_ACT_REG) & 0x01)) {
pr_info("Device not activated, skipping\n");
goto exit;
}
*address = superio_inw(sioaddr, IT87_BASE_REG) & ~(IT87_EXTENT - 1);
if (*address == 0) {
pr_info("Base address not set, skipping\n");
goto exit;
}
err = 0;
sio_data->sioaddr = sioaddr;
sio_data->revision = superio_inb(sioaddr, DEVREV) & 0x0f;
pr_info("Found IT%04x%s chip at 0x%x, revision %d\n", chip_type,
it87_devices[sio_data->type].suffix,
*address, sio_data->revision);
config = &it87_devices[sio_data->type];
if (has_in7_internal(config))
sio_data->internal |= BIT(1);
sio_data->internal |= BIT(2);
if (has_avcc3(config))
sio_data->internal |= BIT(3);
else
sio_data->skip_in |= BIT(9);
if (!has_five_pwm(config))
sio_data->skip_pwm |= BIT(3) | BIT(4) | BIT(5);
else if (!has_six_pwm(config))
sio_data->skip_pwm |= BIT(5);
if (!has_vid(config))
sio_data->skip_vid = 1;
if (sio_data->type == it87) {
superio_select(sioaddr, 5);
sio_data->beep_pin = superio_inb(sioaddr,
IT87_SIO_BEEP_PIN_REG) & 0x3f;
} else if (sio_data->type == it8783) {
int reg25, reg27, reg2a, reg2c, regef;
superio_select(sioaddr, GPIO);
reg25 = superio_inb(sioaddr, IT87_SIO_GPIO1_REG);
reg27 = superio_inb(sioaddr, IT87_SIO_GPIO3_REG);
reg2a = superio_inb(sioaddr, IT87_SIO_PINX1_REG);
reg2c = superio_inb(sioaddr, IT87_SIO_PINX2_REG);
regef = superio_inb(sioaddr, IT87_SIO_SPI_REG);
if ((reg27 & BIT(0)) || !(reg2c & BIT(2)))
sio_data->skip_fan |= BIT(2);
if ((reg25 & BIT(4)) ||
(!(reg2a & BIT(1)) && (regef & BIT(0))))
sio_data->skip_pwm |= BIT(2);
if (reg27 & BIT(7))
sio_data->skip_fan |= BIT(1);
if (reg27 & BIT(3))
sio_data->skip_pwm |= BIT(1);
if ((reg27 & BIT(0)) || (reg2c & BIT(2)))
sio_data->skip_in |= BIT(5);
if (reg27 & BIT(1))
sio_data->skip_in |= BIT(6);
if (reg27 & BIT(2)) {
if (!(reg2c & BIT(1))) {
reg2c |= BIT(1);
superio_outb(sioaddr, IT87_SIO_PINX2_REG,
reg2c);
sio_data->need_in7_reroute = true;
pr_notice("Routing internal VCCH5V to in7.\n");
}
pr_notice("in7 routed to internal voltage divider, with external pin disabled.\n");
pr_notice("Please report if it displays a reasonable voltage.\n");
}
if (reg2c & BIT(0))
sio_data->internal |= BIT(0);
if (reg2c & BIT(1))
sio_data->internal |= BIT(1);
sio_data->beep_pin = superio_inb(sioaddr,
IT87_SIO_BEEP_PIN_REG) & 0x3f;
} else if (sio_data->type == it8603) {
int reg27, reg29;
superio_select(sioaddr, GPIO);
reg27 = superio_inb(sioaddr, IT87_SIO_GPIO3_REG);
if (reg27 & BIT(6))
sio_data->skip_pwm |= BIT(2);
if (reg27 & BIT(7))
sio_data->skip_fan |= BIT(2);
reg29 = superio_inb(sioaddr, IT87_SIO_GPIO5_REG);
if (reg29 & BIT(1))
sio_data->skip_pwm |= BIT(1);
if (reg29 & BIT(2))
sio_data->skip_fan |= BIT(1);
sio_data->skip_in |= BIT(5);
sio_data->skip_in |= BIT(6);
sio_data->beep_pin = superio_inb(sioaddr,
IT87_SIO_BEEP_PIN_REG) & 0x3f;
} else if (sio_data->type == it8620 || sio_data->type == it8628) {
int reg;
superio_select(sioaddr, GPIO);
reg = superio_inb(sioaddr, IT87_SIO_GPIO1_REG);
if (reg & BIT(6))
sio_data->skip_pwm |= BIT(4);
reg = superio_inb(sioaddr, IT87_SIO_GPIO2_REG);
if (!(reg & BIT(5)))
sio_data->skip_fan |= BIT(3);
if (!(reg & BIT(4)))
sio_data->skip_fan |= BIT(4);
reg = superio_inb(sioaddr, IT87_SIO_GPIO3_REG);
if (reg & BIT(6))
sio_data->skip_pwm |= BIT(2);
if (reg & BIT(7))
sio_data->skip_fan |= BIT(2);
reg = superio_inb(sioaddr, IT87_SIO_GPIO4_REG);
if (reg & BIT(2))
sio_data->skip_pwm |= BIT(3);
reg = superio_inb(sioaddr, IT87_SIO_GPIO5_REG);
if (reg & BIT(1))
sio_data->skip_pwm |= BIT(1);
if (reg & BIT(2))
sio_data->skip_fan |= BIT(1);
if (!(reg & BIT(7))) {
sio_data->skip_pwm |= BIT(5);
sio_data->skip_fan |= BIT(5);
}
reg = superio_inb(sioaddr, IT87_SIO_PINX2_REG);
if (reg & BIT(0))
sio_data->internal |= BIT(0);
else
sio_data->skip_in |= BIT(9);
sio_data->beep_pin = superio_inb(sioaddr,
IT87_SIO_BEEP_PIN_REG) & 0x3f;
} else if (sio_data->type == it8622) {
int reg;
superio_select(sioaddr, GPIO);
reg = superio_inb(sioaddr, IT87_SIO_GPIO1_REG);
if (reg & BIT(6))
sio_data->skip_fan |= BIT(3);
if (reg & BIT(5))
sio_data->skip_pwm |= BIT(3);
reg = superio_inb(sioaddr, IT87_SIO_GPIO3_REG);
if (reg & BIT(6))
sio_data->skip_pwm |= BIT(2);
if (reg & BIT(7))
sio_data->skip_fan |= BIT(2);
if (reg & BIT(3))
sio_data->skip_pwm |= BIT(4);
if (reg & BIT(1))
sio_data->skip_fan |= BIT(4);
reg = superio_inb(sioaddr, IT87_SIO_GPIO5_REG);
if (reg & BIT(1))
sio_data->skip_pwm |= BIT(1);
if (reg & BIT(2))
sio_data->skip_fan |= BIT(1);
reg = superio_inb(sioaddr, IT87_SIO_PINX2_REG);
if (!(reg & BIT(0)))
sio_data->skip_in |= BIT(9);
sio_data->beep_pin = superio_inb(sioaddr,
IT87_SIO_BEEP_PIN_REG) & 0x3f;
} else {
int reg;
bool uart6;
superio_select(sioaddr, GPIO);
if (has_five_fans(config)) {
reg = superio_inb(sioaddr, IT87_SIO_GPIO2_REG);
switch (sio_data->type) {
case it8718:
if (reg & BIT(5))
sio_data->skip_fan |= BIT(3);
if (reg & BIT(4))
sio_data->skip_fan |= BIT(4);
break;
case it8720:
case it8721:
case it8728:
if (!(reg & BIT(5)))
sio_data->skip_fan |= BIT(3);
if (!(reg & BIT(4)))
sio_data->skip_fan |= BIT(4);
break;
default:
break;
}
}
reg = superio_inb(sioaddr, IT87_SIO_GPIO3_REG);
if (!sio_data->skip_vid) {
if (reg & 0x0f) {
pr_info("VID is disabled (pins used for GPIO)\n");
sio_data->skip_vid = 1;
}
}
if (reg & BIT(6))
sio_data->skip_pwm |= BIT(2);
if (reg & BIT(7))
sio_data->skip_fan |= BIT(2);
reg = superio_inb(sioaddr, IT87_SIO_GPIO5_REG);
if (reg & BIT(1))
sio_data->skip_pwm |= BIT(1);
if (reg & BIT(2))
sio_data->skip_fan |= BIT(1);
if ((sio_data->type == it8718 || sio_data->type == it8720) &&
!(sio_data->skip_vid))
sio_data->vid_value = superio_inb(sioaddr,
IT87_SIO_VID_REG);
reg = superio_inb(sioaddr, IT87_SIO_PINX2_REG);
uart6 = sio_data->type == it8782 && (reg & BIT(2));
if ((sio_data->type == it8720 || uart6) && !(reg & BIT(1))) {
reg |= BIT(1);
superio_outb(sioaddr, IT87_SIO_PINX2_REG, reg);
sio_data->need_in7_reroute = true;
pr_notice("Routing internal VCCH5V to in7\n");
}
if (reg & BIT(0))
sio_data->internal |= BIT(0);
if (reg & BIT(1))
sio_data->internal |= BIT(1);
if (uart6) {
sio_data->skip_in |= BIT(5) | BIT(6);
sio_data->skip_temp |= BIT(2);
}
sio_data->beep_pin = superio_inb(sioaddr,
IT87_SIO_BEEP_PIN_REG) & 0x3f;
}
if (sio_data->beep_pin)
pr_info("Beeping is supported\n");
board_vendor = dmi_get_system_info(DMI_BOARD_VENDOR);
board_name = dmi_get_system_info(DMI_BOARD_NAME);
if (board_vendor && board_name) {
if (strcmp(board_vendor, "nVIDIA") == 0 &&
strcmp(board_name, "FN68PT") == 0) {
pr_info("Disabling pwm2 due to hardware constraints\n");
sio_data->skip_pwm = BIT(1);
}
}
exit:
superio_exit(sioaddr);
return err;
}
static void it87_check_limit_regs(struct it87_data *data)
{
int i, reg;
for (i = 0; i < NUM_VIN_LIMIT; i++) {
reg = it87_read_value(data, IT87_REG_VIN_MIN(i));
if (reg == 0xff)
it87_write_value(data, IT87_REG_VIN_MIN(i), 0);
}
for (i = 0; i < NUM_TEMP_LIMIT; i++) {
reg = it87_read_value(data, IT87_REG_TEMP_HIGH(i));
if (reg == 0xff)
it87_write_value(data, IT87_REG_TEMP_HIGH(i), 127);
}
}
static void it87_check_voltage_monitors_reset(struct it87_data *data)
{
int reg;
reg = it87_read_value(data, IT87_REG_VIN_ENABLE);
if ((reg & 0xff) == 0) {
it87_write_value(data, IT87_REG_VIN_ENABLE, 0xff);
}
}
static void it87_check_tachometers_reset(struct platform_device *pdev)
{
struct it87_sio_data *sio_data = dev_get_platdata(&pdev->dev);
struct it87_data *data = platform_get_drvdata(pdev);
u8 mask, fan_main_ctrl;
mask = 0x70 & ~(sio_data->skip_fan << 4);
fan_main_ctrl = it87_read_value(data, IT87_REG_FAN_MAIN_CTRL);
if ((fan_main_ctrl & mask) == 0) {
fan_main_ctrl |= mask;
it87_write_value(data, IT87_REG_FAN_MAIN_CTRL,
fan_main_ctrl);
}
}
static void it87_check_tachometers_16bit_mode(struct platform_device *pdev)
{
struct it87_data *data = platform_get_drvdata(pdev);
int reg;
if (!has_fan16_config(data))
return;
reg = it87_read_value(data, IT87_REG_FAN_16BIT);
if (~reg & 0x07 & data->has_fan) {
dev_dbg(&pdev->dev,
"Setting fan1-3 to 16-bit mode\n");
it87_write_value(data, IT87_REG_FAN_16BIT,
reg | 0x07);
}
}
static void it87_start_monitoring(struct it87_data *data)
{
it87_write_value(data, IT87_REG_CONFIG,
(it87_read_value(data, IT87_REG_CONFIG) & 0x3e)
| (update_vbat ? 0x41 : 0x01));
}
static void it87_init_device(struct platform_device *pdev)
{
struct it87_sio_data *sio_data = dev_get_platdata(&pdev->dev);
struct it87_data *data = platform_get_drvdata(pdev);
int tmp, i;
for (i = 0; i < NUM_AUTO_PWM; i++) {
data->pwm_temp_map[i] = i;
data->pwm_duty[i] = 0x7f;
data->auto_pwm[i][3] = 0x7f;
}
it87_check_limit_regs(data);
it87_check_voltage_monitors_reset(data);
it87_check_tachometers_reset(pdev);
data->fan_main_ctrl = it87_read_value(data, IT87_REG_FAN_MAIN_CTRL);
data->has_fan = (data->fan_main_ctrl >> 4) & 0x07;
it87_check_tachometers_16bit_mode(pdev);
if (has_five_fans(data)) {
tmp = it87_read_value(data, IT87_REG_FAN_16BIT);
if (tmp & BIT(4))
data->has_fan |= BIT(3);
if (tmp & BIT(5))
data->has_fan |= BIT(4);
if (has_six_fans(data) && (tmp & BIT(2)))
data->has_fan |= BIT(5);
}
data->has_fan &= ~sio_data->skip_fan;
if (has_six_pwm(data)) {
tmp = it87_read_value(data, IT87_REG_FAN_DIV);
if ((tmp & 0xc0) == 0xc0)
sio_data->skip_pwm |= BIT(4);
if (!(tmp & BIT(3)))
sio_data->skip_pwm |= BIT(5);
}
it87_start_monitoring(data);
}
static int it87_check_pwm(struct device *dev)
{
struct it87_data *data = dev_get_drvdata(dev);
int tmp = it87_read_value(data, IT87_REG_FAN_CTL);
if ((tmp & 0x87) == 0) {
if (fix_pwm_polarity) {
int i;
u8 pwm[3];
for (i = 0; i < ARRAY_SIZE(pwm); i++)
pwm[i] = it87_read_value(data,
IT87_REG_PWM[i]);
if (!((pwm[0] | pwm[1] | pwm[2]) & 0x80)) {
dev_info(dev,
"Reconfiguring PWM to active high polarity\n");
it87_write_value(data, IT87_REG_FAN_CTL,
tmp | 0x87);
for (i = 0; i < 3; i++)
it87_write_value(data,
IT87_REG_PWM[i],
0x7f & ~pwm[i]);
return 1;
}
dev_info(dev,
"PWM configuration is too broken to be fixed\n");
}
return 0;
} else if (fix_pwm_polarity) {
dev_info(dev,
"PWM configuration looks sane, won't touch\n");
}
return 1;
}
static int it87_probe(struct platform_device *pdev)
{
struct it87_data *data;
struct resource *res;
struct device *dev = &pdev->dev;
struct it87_sio_data *sio_data = dev_get_platdata(dev);
int enable_pwm_interface;
struct device *hwmon_dev;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(&pdev->dev, res->start, IT87_EC_EXTENT,
DRVNAME)) {
dev_err(dev, "Failed to request region 0x%lx-0x%lx\n",
(unsigned long)res->start,
(unsigned long)(res->start + IT87_EC_EXTENT - 1));
return -EBUSY;
}
data = devm_kzalloc(&pdev->dev, sizeof(struct it87_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->addr = res->start;
data->sioaddr = sio_data->sioaddr;
data->type = sio_data->type;
data->features = it87_devices[sio_data->type].features;
data->peci_mask = it87_devices[sio_data->type].peci_mask;
data->old_peci_mask = it87_devices[sio_data->type].old_peci_mask;
switch (data->type) {
case it87:
if (sio_data->revision >= 0x03) {
data->features &= ~FEAT_OLD_AUTOPWM;
data->features |= FEAT_FAN16_CONFIG | FEAT_16BIT_FANS;
}
break;
case it8712:
if (sio_data->revision >= 0x08) {
data->features &= ~FEAT_OLD_AUTOPWM;
data->features |= FEAT_FAN16_CONFIG | FEAT_16BIT_FANS |
FEAT_FIVE_FANS;
}
break;
default:
break;
}
if ((it87_read_value(data, IT87_REG_CONFIG) & 0x80) ||
it87_read_value(data, IT87_REG_CHIPID) != 0x90)
return -ENODEV;
platform_set_drvdata(pdev, data);
mutex_init(&data->update_lock);
enable_pwm_interface = it87_check_pwm(dev);
if (!enable_pwm_interface)
dev_info(dev,
"Detected broken BIOS defaults, disabling PWM interface\n");
if (has_12mv_adc(data)) {
if (sio_data->internal & BIT(0))
data->in_scaled |= BIT(3);
if (sio_data->internal & BIT(1))
data->in_scaled |= BIT(7);
if (sio_data->internal & BIT(2))
data->in_scaled |= BIT(8);
if (sio_data->internal & BIT(3))
data->in_scaled |= BIT(9);
} else if (sio_data->type == it8781 || sio_data->type == it8782 ||
sio_data->type == it8783) {
if (sio_data->internal & BIT(0))
data->in_scaled |= BIT(3);
if (sio_data->internal & BIT(1))
data->in_scaled |= BIT(7);
}
data->has_temp = 0x07;
if (sio_data->skip_temp & BIT(2)) {
if (sio_data->type == it8782 &&
!(it87_read_value(data, IT87_REG_TEMP_EXTRA) & 0x80))
data->has_temp &= ~BIT(2);
}
data->in_internal = sio_data->internal;
data->need_in7_reroute = sio_data->need_in7_reroute;
data->has_in = 0x3ff & ~sio_data->skip_in;
if (has_six_temp(data)) {
u8 reg = it87_read_value(data, IT87_REG_TEMP456_ENABLE);
if ((reg & 0x03) >= 0x02)
data->has_temp |= BIT(3);
if (((reg >> 2) & 0x03) >= 0x02)
data->has_temp |= BIT(4);
if (((reg >> 4) & 0x03) >= 0x02)
data->has_temp |= BIT(5);
if ((reg & 0x03) == 0x01)
data->has_in |= BIT(10);
if (((reg >> 2) & 0x03) == 0x01)
data->has_in |= BIT(11);
if (((reg >> 4) & 0x03) == 0x01)
data->has_in |= BIT(12);
}
data->has_beep = !!sio_data->beep_pin;
it87_init_device(pdev);
if (!sio_data->skip_vid) {
data->has_vid = true;
data->vrm = vid_which_vrm();
data->vid = sio_data->vid_value;
}
data->groups[0] = &it87_group;
data->groups[1] = &it87_group_in;
data->groups[2] = &it87_group_temp;
data->groups[3] = &it87_group_fan;
if (enable_pwm_interface) {
data->has_pwm = BIT(ARRAY_SIZE(IT87_REG_PWM)) - 1;
data->has_pwm &= ~sio_data->skip_pwm;
data->groups[4] = &it87_group_pwm;
if (has_old_autopwm(data) || has_newer_autopwm(data))
data->groups[5] = &it87_group_auto_pwm;
}
hwmon_dev = devm_hwmon_device_register_with_groups(dev,
it87_devices[sio_data->type].name,
data, data->groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
static void __maybe_unused it87_resume_sio(struct platform_device *pdev)
{
struct it87_data *data = dev_get_drvdata(&pdev->dev);
int err;
int reg2c;
if (!data->need_in7_reroute)
return;
err = superio_enter(data->sioaddr);
if (err) {
dev_warn(&pdev->dev,
"Unable to enter Super I/O to reroute in7 (%d)",
err);
return;
}
superio_select(data->sioaddr, GPIO);
reg2c = superio_inb(data->sioaddr, IT87_SIO_PINX2_REG);
if (!(reg2c & BIT(1))) {
dev_dbg(&pdev->dev,
"Routing internal VCCH5V to in7 again");
reg2c |= BIT(1);
superio_outb(data->sioaddr, IT87_SIO_PINX2_REG,
reg2c);
}
superio_exit(data->sioaddr);
}
static int __maybe_unused it87_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct it87_data *data = dev_get_drvdata(dev);
it87_resume_sio(pdev);
mutex_lock(&data->update_lock);
it87_check_pwm(dev);
it87_check_limit_regs(data);
it87_check_voltage_monitors_reset(data);
it87_check_tachometers_reset(pdev);
it87_check_tachometers_16bit_mode(pdev);
it87_start_monitoring(data);
data->valid = 0;
mutex_unlock(&data->update_lock);
it87_update_device(dev);
return 0;
}
static int __init it87_device_add(int index, unsigned short address,
const struct it87_sio_data *sio_data)
{
struct platform_device *pdev;
struct resource res = {
.start = address + IT87_EC_OFFSET,
.end = address + IT87_EC_OFFSET + IT87_EC_EXTENT - 1,
.name = DRVNAME,
.flags = IORESOURCE_IO,
};
int err;
err = acpi_check_resource_conflict(&res);
if (err)
return err;
pdev = platform_device_alloc(DRVNAME, address);
if (!pdev)
return -ENOMEM;
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
it87_pdev[index] = pdev;
return 0;
exit_device_put:
platform_device_put(pdev);
return err;
}
static int __init sm_it87_init(void)
{
int sioaddr[2] = { REG_2E, REG_4E };
struct it87_sio_data sio_data;
unsigned short isa_address[2];
bool found = false;
int i, err;
err = platform_driver_register(&it87_driver);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(sioaddr); i++) {
memset(&sio_data, 0, sizeof(struct it87_sio_data));
isa_address[i] = 0;
err = it87_find(sioaddr[i], &isa_address[i], &sio_data);
if (err || isa_address[i] == 0)
continue;
if (i && isa_address[i] == isa_address[0])
break;
err = it87_device_add(i, isa_address[i], &sio_data);
if (err)
goto exit_dev_unregister;
found = true;
if (sio_data.type == it87)
break;
}
if (!found) {
err = -ENODEV;
goto exit_unregister;
}
return 0;
exit_dev_unregister:
platform_device_unregister(it87_pdev[0]);
exit_unregister:
platform_driver_unregister(&it87_driver);
return err;
}
static void __exit sm_it87_exit(void)
{
platform_device_unregister(it87_pdev[1]);
platform_device_unregister(it87_pdev[0]);
platform_driver_unregister(&it87_driver);
}
