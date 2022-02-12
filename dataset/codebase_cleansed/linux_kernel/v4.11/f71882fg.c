static inline int superio_inb(int base, int reg)
{
outb(reg, base);
return inb(base + 1);
}
static int superio_inw(int base, int reg)
{
int val;
val = superio_inb(base, reg) << 8;
val |= superio_inb(base, reg + 1);
return val;
}
static inline int superio_enter(int base)
{
if (!request_muxed_region(base, 2, DRVNAME)) {
pr_err("I/O address 0x%04x already in use\n", base);
return -EBUSY;
}
outb(SIO_UNLOCK_KEY, base);
outb(SIO_UNLOCK_KEY, base);
return 0;
}
static inline void superio_select(int base, int ld)
{
outb(SIO_REG_LDSEL, base);
outb(ld, base + 1);
}
static inline void superio_exit(int base)
{
outb(SIO_LOCK_KEY, base);
release_region(base, 2);
}
static inline int fan_from_reg(u16 reg)
{
return reg ? (1500000 / reg) : 0;
}
static inline u16 fan_to_reg(int fan)
{
return fan ? (1500000 / fan) : 0;
}
static u8 f71882fg_read8(struct f71882fg_data *data, u8 reg)
{
u8 val;
outb(reg, data->addr + ADDR_REG_OFFSET);
val = inb(data->addr + DATA_REG_OFFSET);
return val;
}
static u16 f71882fg_read16(struct f71882fg_data *data, u8 reg)
{
u16 val;
val = f71882fg_read8(data, reg) << 8;
val |= f71882fg_read8(data, reg + 1);
return val;
}
static void f71882fg_write8(struct f71882fg_data *data, u8 reg, u8 val)
{
outb(reg, data->addr + ADDR_REG_OFFSET);
outb(val, data->addr + DATA_REG_OFFSET);
}
static void f71882fg_write16(struct f71882fg_data *data, u8 reg, u16 val)
{
f71882fg_write8(data, reg, val >> 8);
f71882fg_write8(data, reg + 1, val & 0xff);
}
static u16 f71882fg_read_temp(struct f71882fg_data *data, int nr)
{
if (data->type == f71858fg)
return f71882fg_read16(data, F71882FG_REG_TEMP(nr));
else
return f71882fg_read8(data, F71882FG_REG_TEMP(nr));
}
static struct f71882fg_data *f71882fg_update_device(struct device *dev)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int nr_fans = f71882fg_nr_fans[data->type];
int nr_temps = f71882fg_nr_temps[data->type];
int nr, reg, point;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_limits + 60 * HZ) ||
!data->valid) {
if (f71882fg_has_in1_alarm[data->type]) {
if (data->type == f81866a) {
data->in1_max =
f71882fg_read8(data,
F81866_REG_IN1_HIGH);
data->in_beep =
f71882fg_read8(data,
F81866_REG_IN_BEEP);
} else {
data->in1_max =
f71882fg_read8(data,
F71882FG_REG_IN1_HIGH);
data->in_beep =
f71882fg_read8(data,
F71882FG_REG_IN_BEEP);
}
}
for (nr = data->temp_start; nr < nr_temps + data->temp_start;
nr++) {
data->temp_ovt[nr] = f71882fg_read8(data,
F71882FG_REG_TEMP_OVT(nr));
data->temp_high[nr] = f71882fg_read8(data,
F71882FG_REG_TEMP_HIGH(nr));
}
if (data->type != f8000) {
data->temp_hyst[0] = f71882fg_read8(data,
F71882FG_REG_TEMP_HYST(0));
data->temp_hyst[1] = f71882fg_read8(data,
F71882FG_REG_TEMP_HYST(1));
}
if ((data->type != f71858fg) && (data->type != f8000)) {
reg = f71882fg_read8(data, F71882FG_REG_TEMP_TYPE);
data->temp_type[1] = (reg & 0x02) ? 2 : 4;
data->temp_type[2] = (reg & 0x04) ? 2 : 4;
data->temp_type[3] = (reg & 0x08) ? 2 : 4;
}
if (f71882fg_fan_has_beep[data->type])
data->fan_beep = f71882fg_read8(data,
F71882FG_REG_FAN_BEEP);
if (f71882fg_temp_has_beep[data->type])
data->temp_beep = f71882fg_read8(data,
F71882FG_REG_TEMP_BEEP);
data->pwm_enable = f71882fg_read8(data,
F71882FG_REG_PWM_ENABLE);
data->pwm_auto_point_hyst[0] =
f71882fg_read8(data, F71882FG_REG_FAN_HYST(0));
data->pwm_auto_point_hyst[1] =
f71882fg_read8(data, F71882FG_REG_FAN_HYST(1));
for (nr = 0; nr < nr_fans; nr++) {
data->pwm_auto_point_mapping[nr] =
f71882fg_read8(data,
F71882FG_REG_POINT_MAPPING(nr));
switch (data->type) {
default:
for (point = 0; point < 5; point++) {
data->pwm_auto_point_pwm[nr][point] =
f71882fg_read8(data,
F71882FG_REG_POINT_PWM
(nr, point));
}
for (point = 0; point < 4; point++) {
data->pwm_auto_point_temp[nr][point] =
f71882fg_read8(data,
F71882FG_REG_POINT_TEMP
(nr, point));
}
break;
case f71808e:
case f71869:
data->pwm_auto_point_pwm[nr][0] =
f71882fg_read8(data,
F71882FG_REG_POINT_PWM(nr, 0));
case f71862fg:
data->pwm_auto_point_pwm[nr][1] =
f71882fg_read8(data,
F71882FG_REG_POINT_PWM
(nr, 1));
data->pwm_auto_point_pwm[nr][4] =
f71882fg_read8(data,
F71882FG_REG_POINT_PWM
(nr, 4));
data->pwm_auto_point_temp[nr][0] =
f71882fg_read8(data,
F71882FG_REG_POINT_TEMP
(nr, 0));
data->pwm_auto_point_temp[nr][3] =
f71882fg_read8(data,
F71882FG_REG_POINT_TEMP
(nr, 3));
break;
}
}
data->last_limits = jiffies;
}
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
data->temp_status = f71882fg_read8(data,
F71882FG_REG_TEMP_STATUS);
data->temp_diode_open = f71882fg_read8(data,
F71882FG_REG_TEMP_DIODE_OPEN);
for (nr = data->temp_start; nr < nr_temps + data->temp_start;
nr++)
data->temp[nr] = f71882fg_read_temp(data, nr);
data->fan_status = f71882fg_read8(data,
F71882FG_REG_FAN_STATUS);
for (nr = 0; nr < nr_fans; nr++) {
data->fan[nr] = f71882fg_read16(data,
F71882FG_REG_FAN(nr));
data->fan_target[nr] =
f71882fg_read16(data, F71882FG_REG_FAN_TARGET(nr));
data->fan_full_speed[nr] =
f71882fg_read16(data,
F71882FG_REG_FAN_FULL_SPEED(nr));
data->pwm[nr] =
f71882fg_read8(data, F71882FG_REG_PWM(nr));
}
if (data->type == f71808a) {
data->fan[2] = f71882fg_read16(data,
F71882FG_REG_FAN(2));
data->pwm[2] = f71882fg_read8(data,
F71882FG_REG_PWM(2));
}
if (data->type == f8000)
data->fan[3] = f71882fg_read16(data,
F71882FG_REG_FAN(3));
if (f71882fg_has_in1_alarm[data->type]) {
if (data->type == f81866a)
data->in_status = f71882fg_read8(data,
F81866_REG_IN_STATUS);
else
data->in_status = f71882fg_read8(data,
F71882FG_REG_IN_STATUS);
}
for (nr = 0; nr < F71882FG_MAX_INS; nr++)
if (f71882fg_has_in[data->type][nr])
data->in[nr] = f71882fg_read8(data,
F71882FG_REG_IN(nr));
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
int speed = fan_from_reg(data->fan[nr]);
if (speed == FAN_MIN_DETECT)
speed = 0;
return sprintf(buf, "%d\n", speed);
}
static ssize_t show_fan_full_speed(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
int speed = fan_from_reg(data->fan_full_speed[nr]);
return sprintf(buf, "%d\n", speed);
}
static ssize_t store_fan_full_speed(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, 23, 1500000);
val = fan_to_reg(val);
mutex_lock(&data->update_lock);
f71882fg_write16(data, F71882FG_REG_FAN_FULL_SPEED(nr), val);
data->fan_full_speed[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_beep(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
if (data->fan_beep & (1 << nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t store_fan_beep(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
unsigned long val;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_beep = f71882fg_read8(data, F71882FG_REG_FAN_BEEP);
if (val)
data->fan_beep |= 1 << nr;
else
data->fan_beep &= ~(1 << nr);
f71882fg_write8(data, F71882FG_REG_FAN_BEEP, data->fan_beep);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
if (data->fan_status & (1 << nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_in(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
return sprintf(buf, "%d\n", data->in[nr] * 8);
}
static ssize_t show_in_max(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
return sprintf(buf, "%d\n", data->in1_max * 8);
}
static ssize_t store_in_max(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val /= 8;
val = clamp_val(val, 0, 255);
mutex_lock(&data->update_lock);
if (data->type == f81866a)
f71882fg_write8(data, F81866_REG_IN1_HIGH, val);
else
f71882fg_write8(data, F71882FG_REG_IN1_HIGH, val);
data->in1_max = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_beep(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
if (data->in_beep & (1 << nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t store_in_beep(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
unsigned long val;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (data->type == f81866a)
data->in_beep = f71882fg_read8(data, F81866_REG_IN_BEEP);
else
data->in_beep = f71882fg_read8(data, F71882FG_REG_IN_BEEP);
if (val)
data->in_beep |= 1 << nr;
else
data->in_beep &= ~(1 << nr);
if (data->type == f81866a)
f71882fg_write8(data, F81866_REG_IN_BEEP, data->in_beep);
else
f71882fg_write8(data, F71882FG_REG_IN_BEEP, data->in_beep);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
if (data->in_status & (1 << nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
int sign, temp;
if (data->type == f71858fg) {
if (data->temp_config & 1) {
sign = data->temp[nr] & 0x0001;
temp = (data->temp[nr] >> 5) & 0x7ff;
} else {
sign = data->temp[nr] & 0x8000;
temp = (data->temp[nr] >> 5) & 0x3ff;
}
temp *= 125;
if (sign)
temp -= 128000;
} else
temp = data->temp[nr] * 1000;
return sprintf(buf, "%d\n", temp);
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
return sprintf(buf, "%d\n", data->temp_high[nr] * 1000);
}
static ssize_t store_temp_max(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val /= 1000;
val = clamp_val(val, 0, 255);
mutex_lock(&data->update_lock);
f71882fg_write8(data, F71882FG_REG_TEMP_HIGH(nr), val);
data->temp_high[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_max_hyst(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
int temp_max_hyst;
mutex_lock(&data->update_lock);
if (nr & 1)
temp_max_hyst = data->temp_hyst[nr / 2] >> 4;
else
temp_max_hyst = data->temp_hyst[nr / 2] & 0x0f;
temp_max_hyst = (data->temp_high[nr] - temp_max_hyst) * 1000;
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", temp_max_hyst);
}
static ssize_t store_temp_max_hyst(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
ssize_t ret = count;
u8 reg;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val /= 1000;
mutex_lock(&data->update_lock);
data->temp_high[nr] = f71882fg_read8(data, F71882FG_REG_TEMP_HIGH(nr));
val = clamp_val(val, data->temp_high[nr] - 15, data->temp_high[nr]);
val = data->temp_high[nr] - val;
reg = f71882fg_read8(data, F71882FG_REG_TEMP_HYST(nr / 2));
if (nr & 1)
reg = (reg & 0x0f) | (val << 4);
else
reg = (reg & 0xf0) | val;
f71882fg_write8(data, F71882FG_REG_TEMP_HYST(nr / 2), reg);
data->temp_hyst[nr / 2] = reg;
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t show_temp_crit(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
return sprintf(buf, "%d\n", data->temp_ovt[nr] * 1000);
}
static ssize_t store_temp_crit(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val /= 1000;
val = clamp_val(val, 0, 255);
mutex_lock(&data->update_lock);
f71882fg_write8(data, F71882FG_REG_TEMP_OVT(nr), val);
data->temp_ovt[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_crit_hyst(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
int temp_crit_hyst;
mutex_lock(&data->update_lock);
if (nr & 1)
temp_crit_hyst = data->temp_hyst[nr / 2] >> 4;
else
temp_crit_hyst = data->temp_hyst[nr / 2] & 0x0f;
temp_crit_hyst = (data->temp_ovt[nr] - temp_crit_hyst) * 1000;
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", temp_crit_hyst);
}
static ssize_t show_temp_type(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
return sprintf(buf, "%d\n", data->temp_type[nr]);
}
static ssize_t show_temp_beep(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
if (data->temp_beep & (1 << nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t store_temp_beep(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
unsigned long val;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_beep = f71882fg_read8(data, F71882FG_REG_TEMP_BEEP);
if (val)
data->temp_beep |= 1 << nr;
else
data->temp_beep &= ~(1 << nr);
f71882fg_write8(data, F71882FG_REG_TEMP_BEEP, data->temp_beep);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
if (data->temp_status & (1 << nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_temp_fault(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
if (data->temp_diode_open & (1 << nr))
return sprintf(buf, "1\n");
else
return sprintf(buf, "0\n");
}
static ssize_t show_pwm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int val, nr = to_sensor_dev_attr_2(devattr)->index;
mutex_lock(&data->update_lock);
if (data->pwm_enable & (1 << (2 * nr)))
val = data->pwm[nr];
else {
val = 255 * fan_from_reg(data->fan_target[nr])
/ fan_from_reg(data->fan_full_speed[nr]);
}
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", val);
}
static ssize_t store_pwm(struct device *dev,
struct device_attribute *devattr, const char *buf,
size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, 0, 255);
mutex_lock(&data->update_lock);
data->pwm_enable = f71882fg_read8(data, F71882FG_REG_PWM_ENABLE);
if ((data->type == f8000 && ((data->pwm_enable >> 2 * nr) & 3) != 2) ||
(data->type != f8000 && !((data->pwm_enable >> 2 * nr) & 2))) {
count = -EROFS;
goto leave;
}
if (data->pwm_enable & (1 << (2 * nr))) {
f71882fg_write8(data, F71882FG_REG_PWM(nr), val);
data->pwm[nr] = val;
} else {
int target, full_speed;
full_speed = f71882fg_read16(data,
F71882FG_REG_FAN_FULL_SPEED(nr));
target = fan_to_reg(val * fan_from_reg(full_speed) / 255);
f71882fg_write16(data, F71882FG_REG_FAN_TARGET(nr), target);
data->fan_target[nr] = target;
data->fan_full_speed[nr] = full_speed;
}
leave:
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_simple_pwm(struct device *dev,
struct device_attribute *devattr, char *buf)
{
struct f71882fg_data *data = f71882fg_update_device(dev);
int val, nr = to_sensor_dev_attr_2(devattr)->index;
val = data->pwm[nr];
return sprintf(buf, "%d\n", val);
}
static ssize_t store_simple_pwm(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, 0, 255);
mutex_lock(&data->update_lock);
f71882fg_write8(data, F71882FG_REG_PWM(nr), val);
data->pwm[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_enable(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int result = 0;
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
switch ((data->pwm_enable >> 2 * nr) & 3) {
case 0:
case 1:
result = 2;
break;
case 2:
result = 1;
break;
case 3:
if (data->type == f8000)
result = 3;
else
result = 1;
break;
}
return sprintf(buf, "%d\n", result);
}
static ssize_t store_pwm_enable(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
if (data->type == f8000 && nr == 2 && val != 2)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm_enable = f71882fg_read8(data, F71882FG_REG_PWM_ENABLE);
if (data->type == f8000 && ((data->pwm_enable >> 2 * nr) & 1)) {
switch (val) {
case 2:
data->pwm_enable &= ~(2 << (2 * nr));
break;
case 3:
data->pwm_enable |= 2 << (2 * nr);
break;
default:
count = -EINVAL;
goto leave;
}
} else {
switch (val) {
case 1:
if (data->type == f71858fg &&
((data->pwm_enable >> (2 * nr)) & 1)) {
count = -EINVAL;
goto leave;
}
data->pwm_enable |= 2 << (2 * nr);
break;
case 2:
data->pwm_enable &= ~(2 << (2 * nr));
break;
default:
count = -EINVAL;
goto leave;
}
}
f71882fg_write8(data, F71882FG_REG_PWM_ENABLE, data->pwm_enable);
leave:
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_point_pwm(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int result;
struct f71882fg_data *data = f71882fg_update_device(dev);
int pwm = to_sensor_dev_attr_2(devattr)->index;
int point = to_sensor_dev_attr_2(devattr)->nr;
mutex_lock(&data->update_lock);
if (data->pwm_enable & (1 << (2 * pwm))) {
result = data->pwm_auto_point_pwm[pwm][point];
} else {
result = 32 * 255 / (32 + data->pwm_auto_point_pwm[pwm][point]);
}
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", result);
}
static ssize_t store_pwm_auto_point_pwm(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, pwm = to_sensor_dev_attr_2(devattr)->index;
int point = to_sensor_dev_attr_2(devattr)->nr;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val = clamp_val(val, 0, 255);
mutex_lock(&data->update_lock);
data->pwm_enable = f71882fg_read8(data, F71882FG_REG_PWM_ENABLE);
if (data->pwm_enable & (1 << (2 * pwm))) {
} else {
if (val < 29)
val = 255;
else
val = (255 - val) * 32 / val;
}
f71882fg_write8(data, F71882FG_REG_POINT_PWM(pwm, point), val);
data->pwm_auto_point_pwm[pwm][point] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_point_temp_hyst(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int result = 0;
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
int point = to_sensor_dev_attr_2(devattr)->nr;
mutex_lock(&data->update_lock);
if (nr & 1)
result = data->pwm_auto_point_hyst[nr / 2] >> 4;
else
result = data->pwm_auto_point_hyst[nr / 2] & 0x0f;
result = 1000 * (data->pwm_auto_point_temp[nr][point] - result);
mutex_unlock(&data->update_lock);
return sprintf(buf, "%d\n", result);
}
static ssize_t store_pwm_auto_point_temp_hyst(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
int point = to_sensor_dev_attr_2(devattr)->nr;
u8 reg;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val /= 1000;
mutex_lock(&data->update_lock);
data->pwm_auto_point_temp[nr][point] =
f71882fg_read8(data, F71882FG_REG_POINT_TEMP(nr, point));
val = clamp_val(val, data->pwm_auto_point_temp[nr][point] - 15,
data->pwm_auto_point_temp[nr][point]);
val = data->pwm_auto_point_temp[nr][point] - val;
reg = f71882fg_read8(data, F71882FG_REG_FAN_HYST(nr / 2));
if (nr & 1)
reg = (reg & 0x0f) | (val << 4);
else
reg = (reg & 0xf0) | val;
f71882fg_write8(data, F71882FG_REG_FAN_HYST(nr / 2), reg);
data->pwm_auto_point_hyst[nr / 2] = reg;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_interpolate(struct device *dev,
struct device_attribute *devattr, char *buf)
{
int result;
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
result = (data->pwm_auto_point_mapping[nr] >> 4) & 1;
return sprintf(buf, "%d\n", result);
}
static ssize_t store_pwm_interpolate(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
unsigned long val;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->pwm_auto_point_mapping[nr] =
f71882fg_read8(data, F71882FG_REG_POINT_MAPPING(nr));
if (val)
val = data->pwm_auto_point_mapping[nr] | (1 << 4);
else
val = data->pwm_auto_point_mapping[nr] & (~(1 << 4));
f71882fg_write8(data, F71882FG_REG_POINT_MAPPING(nr), val);
data->pwm_auto_point_mapping[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_point_channel(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int result;
struct f71882fg_data *data = f71882fg_update_device(dev);
int nr = to_sensor_dev_attr_2(devattr)->index;
result = 1 << ((data->pwm_auto_point_mapping[nr] & 3) -
data->temp_start);
return sprintf(buf, "%d\n", result);
}
static ssize_t store_pwm_auto_point_channel(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, nr = to_sensor_dev_attr_2(devattr)->index;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
switch (val) {
case 1:
val = 0;
break;
case 2:
val = 1;
break;
case 4:
val = 2;
break;
default:
return -EINVAL;
}
val += data->temp_start;
mutex_lock(&data->update_lock);
data->pwm_auto_point_mapping[nr] =
f71882fg_read8(data, F71882FG_REG_POINT_MAPPING(nr));
val = (data->pwm_auto_point_mapping[nr] & 0xfc) | val;
f71882fg_write8(data, F71882FG_REG_POINT_MAPPING(nr), val);
data->pwm_auto_point_mapping[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_point_temp(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int result;
struct f71882fg_data *data = f71882fg_update_device(dev);
int pwm = to_sensor_dev_attr_2(devattr)->index;
int point = to_sensor_dev_attr_2(devattr)->nr;
result = data->pwm_auto_point_temp[pwm][point];
return sprintf(buf, "%d\n", 1000 * result);
}
static ssize_t store_pwm_auto_point_temp(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
int err, pwm = to_sensor_dev_attr_2(devattr)->index;
int point = to_sensor_dev_attr_2(devattr)->nr;
long val;
err = kstrtol(buf, 10, &val);
if (err)
return err;
val /= 1000;
if (data->auto_point_temp_signed)
val = clamp_val(val, -128, 127);
else
val = clamp_val(val, 0, 127);
mutex_lock(&data->update_lock);
f71882fg_write8(data, F71882FG_REG_POINT_TEMP(pwm, point), val);
data->pwm_auto_point_temp[pwm][point] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t name_show(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71882fg_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", f71882fg_names[data->type]);
}
static int f71882fg_create_sysfs_files(struct platform_device *pdev,
struct sensor_device_attribute_2 *attr, int count)
{
int err, i;
for (i = 0; i < count; i++) {
err = device_create_file(&pdev->dev, &attr[i].dev_attr);
if (err)
return err;
}
return 0;
}
static void f71882fg_remove_sysfs_files(struct platform_device *pdev,
struct sensor_device_attribute_2 *attr, int count)
{
int i;
for (i = 0; i < count; i++)
device_remove_file(&pdev->dev, &attr[i].dev_attr);
}
static int f71882fg_create_fan_sysfs_files(
struct platform_device *pdev, int idx)
{
struct f71882fg_data *data = platform_get_drvdata(pdev);
int err;
err = 0;
switch (data->type) {
case f71858fg:
if (((data->pwm_enable >> (idx * 2)) & 3) == 3)
err = 1;
break;
case f71862fg:
if (((data->pwm_enable >> (idx * 2)) & 1) != 1)
err = 1;
break;
case f8000:
if (idx == 2)
err = data->pwm_enable & 0x20;
break;
default:
break;
}
if (err) {
dev_err(&pdev->dev,
"Invalid (reserved) pwm settings: 0x%02x, "
"skipping fan %d\n",
(data->pwm_enable >> (idx * 2)) & 3, idx + 1);
return 0;
}
err = f71882fg_create_sysfs_files(pdev, &fxxxx_fan_attr[idx][0],
ARRAY_SIZE(fxxxx_fan_attr[0]));
if (err)
return err;
if (f71882fg_fan_has_beep[data->type]) {
err = f71882fg_create_sysfs_files(pdev,
&fxxxx_fan_beep_attr[idx],
1);
if (err)
return err;
}
dev_info(&pdev->dev, "Fan: %d is in %s mode\n", idx + 1,
(data->pwm_enable & (1 << (2 * idx))) ? "duty-cycle" : "RPM");
switch (data->type) {
case f71808e:
case f71808a:
case f71869:
case f71869a:
case f71889fg:
case f71889ed:
case f71889a:
data->pwm_auto_point_mapping[idx] =
f71882fg_read8(data, F71882FG_REG_POINT_MAPPING(idx));
if ((data->pwm_auto_point_mapping[idx] & 0x80) ||
(data->pwm_auto_point_mapping[idx] & 3) == 0) {
dev_warn(&pdev->dev,
"Auto pwm controlled by raw digital "
"data, disabling pwm auto_point "
"sysfs attributes for fan %d\n", idx + 1);
return 0;
}
break;
default:
break;
}
switch (data->type) {
case f71862fg:
err = f71882fg_create_sysfs_files(pdev,
&f71862fg_auto_pwm_attr[idx][0],
ARRAY_SIZE(f71862fg_auto_pwm_attr[0]));
break;
case f71808e:
case f71869:
err = f71882fg_create_sysfs_files(pdev,
&f71869_auto_pwm_attr[idx][0],
ARRAY_SIZE(f71869_auto_pwm_attr[0]));
break;
case f8000:
err = f71882fg_create_sysfs_files(pdev,
&f8000_auto_pwm_attr[idx][0],
ARRAY_SIZE(f8000_auto_pwm_attr[0]));
break;
default:
err = f71882fg_create_sysfs_files(pdev,
&fxxxx_auto_pwm_attr[idx][0],
ARRAY_SIZE(fxxxx_auto_pwm_attr[0]));
}
return err;
}
static int f71882fg_probe(struct platform_device *pdev)
{
struct f71882fg_data *data;
struct f71882fg_sio_data *sio_data = dev_get_platdata(&pdev->dev);
int nr_fans = f71882fg_nr_fans[sio_data->type];
int nr_temps = f71882fg_nr_temps[sio_data->type];
int err, i;
int size;
u8 start_reg, reg;
data = devm_kzalloc(&pdev->dev, sizeof(struct f71882fg_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->addr = platform_get_resource(pdev, IORESOURCE_IO, 0)->start;
data->type = sio_data->type;
data->temp_start =
(data->type == f71858fg || data->type == f8000 ||
data->type == f81866a) ? 0 : 1;
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
start_reg = f71882fg_read8(data, F71882FG_REG_START);
if (start_reg & 0x04) {
dev_warn(&pdev->dev, "Hardware monitor is powered down\n");
return -ENODEV;
}
if (!(start_reg & 0x03)) {
dev_warn(&pdev->dev, "Hardware monitoring not activated\n");
return -ENODEV;
}
err = device_create_file(&pdev->dev, &dev_attr_name);
if (err)
goto exit_unregister_sysfs;
if (start_reg & 0x01) {
switch (data->type) {
case f71858fg:
data->temp_config =
f71882fg_read8(data, F71882FG_REG_TEMP_CONFIG);
if (data->temp_config & 0x10)
err = f71882fg_create_sysfs_files(pdev,
f8000_temp_attr,
ARRAY_SIZE(f8000_temp_attr));
else
err = f71882fg_create_sysfs_files(pdev,
f71858fg_temp_attr,
ARRAY_SIZE(f71858fg_temp_attr));
break;
case f8000:
err = f71882fg_create_sysfs_files(pdev,
f8000_temp_attr,
ARRAY_SIZE(f8000_temp_attr));
break;
case f81866a:
err = f71882fg_create_sysfs_files(pdev,
f71858fg_temp_attr,
ARRAY_SIZE(f71858fg_temp_attr));
break;
default:
err = f71882fg_create_sysfs_files(pdev,
&fxxxx_temp_attr[0][0],
ARRAY_SIZE(fxxxx_temp_attr[0]) * nr_temps);
}
if (err)
goto exit_unregister_sysfs;
if (f71882fg_temp_has_beep[data->type]) {
if (data->type == f81866a) {
size = ARRAY_SIZE(f81866_temp_beep_attr[0]);
err = f71882fg_create_sysfs_files(pdev,
&f81866_temp_beep_attr[0][0],
size * nr_temps);
} else {
size = ARRAY_SIZE(fxxxx_temp_beep_attr[0]);
err = f71882fg_create_sysfs_files(pdev,
&fxxxx_temp_beep_attr[0][0],
size * nr_temps);
}
if (err)
goto exit_unregister_sysfs;
}
for (i = 0; i < F71882FG_MAX_INS; i++) {
if (f71882fg_has_in[data->type][i]) {
err = device_create_file(&pdev->dev,
&fxxxx_in_attr[i].dev_attr);
if (err)
goto exit_unregister_sysfs;
}
}
if (f71882fg_has_in1_alarm[data->type]) {
err = f71882fg_create_sysfs_files(pdev,
fxxxx_in1_alarm_attr,
ARRAY_SIZE(fxxxx_in1_alarm_attr));
if (err)
goto exit_unregister_sysfs;
}
}
if (start_reg & 0x02) {
switch (data->type) {
case f71808e:
case f71808a:
case f71869:
case f71869a:
data->auto_point_temp_signed = 1;
case f71889fg:
case f71889ed:
case f71889a:
reg = f71882fg_read8(data, F71882FG_REG_FAN_FAULT_T);
if (reg & F71882FG_FAN_NEG_TEMP_EN)
data->auto_point_temp_signed = 1;
reg &= ~F71882FG_FAN_PROG_SEL;
f71882fg_write8(data, F71882FG_REG_FAN_FAULT_T, reg);
break;
default:
break;
}
data->pwm_enable =
f71882fg_read8(data, F71882FG_REG_PWM_ENABLE);
for (i = 0; i < nr_fans; i++) {
err = f71882fg_create_fan_sysfs_files(pdev, i);
if (err)
goto exit_unregister_sysfs;
}
switch (data->type) {
case f71808a:
err = f71882fg_create_sysfs_files(pdev,
f71808a_fan3_attr,
ARRAY_SIZE(f71808a_fan3_attr));
break;
case f8000:
err = f71882fg_create_sysfs_files(pdev,
f8000_fan_attr,
ARRAY_SIZE(f8000_fan_attr));
break;
default:
break;
}
if (err)
goto exit_unregister_sysfs;
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
data->hwmon_dev = NULL;
goto exit_unregister_sysfs;
}
return 0;
exit_unregister_sysfs:
f71882fg_remove(pdev);
return err;
}
static int f71882fg_remove(struct platform_device *pdev)
{
struct f71882fg_data *data = platform_get_drvdata(pdev);
int nr_fans = f71882fg_nr_fans[data->type];
int nr_temps = f71882fg_nr_temps[data->type];
int i;
u8 start_reg = f71882fg_read8(data, F71882FG_REG_START);
if (data->hwmon_dev)
hwmon_device_unregister(data->hwmon_dev);
device_remove_file(&pdev->dev, &dev_attr_name);
if (start_reg & 0x01) {
switch (data->type) {
case f71858fg:
if (data->temp_config & 0x10)
f71882fg_remove_sysfs_files(pdev,
f8000_temp_attr,
ARRAY_SIZE(f8000_temp_attr));
else
f71882fg_remove_sysfs_files(pdev,
f71858fg_temp_attr,
ARRAY_SIZE(f71858fg_temp_attr));
break;
case f8000:
f71882fg_remove_sysfs_files(pdev,
f8000_temp_attr,
ARRAY_SIZE(f8000_temp_attr));
break;
case f81866a:
f71882fg_remove_sysfs_files(pdev,
f71858fg_temp_attr,
ARRAY_SIZE(f71858fg_temp_attr));
break;
default:
f71882fg_remove_sysfs_files(pdev,
&fxxxx_temp_attr[0][0],
ARRAY_SIZE(fxxxx_temp_attr[0]) * nr_temps);
}
if (f71882fg_temp_has_beep[data->type]) {
if (data->type == f81866a)
f71882fg_remove_sysfs_files(pdev,
&f81866_temp_beep_attr[0][0],
ARRAY_SIZE(f81866_temp_beep_attr[0])
* nr_temps);
else
f71882fg_remove_sysfs_files(pdev,
&fxxxx_temp_beep_attr[0][0],
ARRAY_SIZE(fxxxx_temp_beep_attr[0])
* nr_temps);
}
for (i = 0; i < F71882FG_MAX_INS; i++) {
if (f71882fg_has_in[data->type][i]) {
device_remove_file(&pdev->dev,
&fxxxx_in_attr[i].dev_attr);
}
}
if (f71882fg_has_in1_alarm[data->type]) {
f71882fg_remove_sysfs_files(pdev,
fxxxx_in1_alarm_attr,
ARRAY_SIZE(fxxxx_in1_alarm_attr));
}
}
if (start_reg & 0x02) {
f71882fg_remove_sysfs_files(pdev, &fxxxx_fan_attr[0][0],
ARRAY_SIZE(fxxxx_fan_attr[0]) * nr_fans);
if (f71882fg_fan_has_beep[data->type]) {
f71882fg_remove_sysfs_files(pdev,
fxxxx_fan_beep_attr, nr_fans);
}
switch (data->type) {
case f71808a:
f71882fg_remove_sysfs_files(pdev,
&fxxxx_auto_pwm_attr[0][0],
ARRAY_SIZE(fxxxx_auto_pwm_attr[0]) * nr_fans);
f71882fg_remove_sysfs_files(pdev,
f71808a_fan3_attr,
ARRAY_SIZE(f71808a_fan3_attr));
break;
case f71862fg:
f71882fg_remove_sysfs_files(pdev,
&f71862fg_auto_pwm_attr[0][0],
ARRAY_SIZE(f71862fg_auto_pwm_attr[0]) *
nr_fans);
break;
case f71808e:
case f71869:
f71882fg_remove_sysfs_files(pdev,
&f71869_auto_pwm_attr[0][0],
ARRAY_SIZE(f71869_auto_pwm_attr[0]) * nr_fans);
break;
case f8000:
f71882fg_remove_sysfs_files(pdev,
f8000_fan_attr,
ARRAY_SIZE(f8000_fan_attr));
f71882fg_remove_sysfs_files(pdev,
&f8000_auto_pwm_attr[0][0],
ARRAY_SIZE(f8000_auto_pwm_attr[0]) * nr_fans);
break;
default:
f71882fg_remove_sysfs_files(pdev,
&fxxxx_auto_pwm_attr[0][0],
ARRAY_SIZE(fxxxx_auto_pwm_attr[0]) * nr_fans);
}
}
return 0;
}
static int __init f71882fg_find(int sioaddr, struct f71882fg_sio_data *sio_data)
{
u16 devid;
unsigned short address;
int err = superio_enter(sioaddr);
if (err)
return err;
devid = superio_inw(sioaddr, SIO_REG_MANID);
if (devid != SIO_FINTEK_ID) {
pr_debug("Not a Fintek device\n");
err = -ENODEV;
goto exit;
}
devid = force_id ? force_id : superio_inw(sioaddr, SIO_REG_DEVID);
switch (devid) {
case SIO_F71808E_ID:
sio_data->type = f71808e;
break;
case SIO_F71808A_ID:
sio_data->type = f71808a;
break;
case SIO_F71858_ID:
sio_data->type = f71858fg;
break;
case SIO_F71862_ID:
sio_data->type = f71862fg;
break;
case SIO_F71868_ID:
sio_data->type = f71868a;
break;
case SIO_F71869_ID:
sio_data->type = f71869;
break;
case SIO_F71869A_ID:
sio_data->type = f71869a;
break;
case SIO_F71882_ID:
sio_data->type = f71882fg;
break;
case SIO_F71889_ID:
sio_data->type = f71889fg;
break;
case SIO_F71889E_ID:
sio_data->type = f71889ed;
break;
case SIO_F71889A_ID:
sio_data->type = f71889a;
break;
case SIO_F8000_ID:
sio_data->type = f8000;
break;
case SIO_F81768D_ID:
sio_data->type = f81768d;
break;
case SIO_F81865_ID:
sio_data->type = f81865f;
break;
case SIO_F81866_ID:
sio_data->type = f81866a;
break;
default:
pr_info("Unsupported Fintek device: %04x\n",
(unsigned int)devid);
err = -ENODEV;
goto exit;
}
if (sio_data->type == f71858fg)
superio_select(sioaddr, SIO_F71858FG_LD_HWM);
else
superio_select(sioaddr, SIO_F71882FG_LD_HWM);
if (!(superio_inb(sioaddr, SIO_REG_ENABLE) & 0x01)) {
pr_warn("Device not activated\n");
err = -ENODEV;
goto exit;
}
address = superio_inw(sioaddr, SIO_REG_ADDR);
if (address == 0) {
pr_warn("Base address not set\n");
err = -ENODEV;
goto exit;
}
address &= ~(REGION_LENGTH - 1);
err = address;
pr_info("Found %s chip at %#x, revision %d\n",
f71882fg_names[sio_data->type], (unsigned int)address,
(int)superio_inb(sioaddr, SIO_REG_DEVREV));
exit:
superio_exit(sioaddr);
return err;
}
static int __init f71882fg_device_add(int address,
const struct f71882fg_sio_data *sio_data)
{
struct resource res = {
.start = address,
.end = address + REGION_LENGTH - 1,
.flags = IORESOURCE_IO,
};
int err;
f71882fg_pdev = platform_device_alloc(DRVNAME, address);
if (!f71882fg_pdev)
return -ENOMEM;
res.name = f71882fg_pdev->name;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit_device_put;
err = platform_device_add_resources(f71882fg_pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed\n");
goto exit_device_put;
}
err = platform_device_add_data(f71882fg_pdev, sio_data,
sizeof(struct f71882fg_sio_data));
if (err) {
pr_err("Platform data allocation failed\n");
goto exit_device_put;
}
err = platform_device_add(f71882fg_pdev);
if (err) {
pr_err("Device addition failed\n");
goto exit_device_put;
}
return 0;
exit_device_put:
platform_device_put(f71882fg_pdev);
return err;
}
static int __init f71882fg_init(void)
{
int err;
int address;
struct f71882fg_sio_data sio_data;
memset(&sio_data, 0, sizeof(sio_data));
address = f71882fg_find(0x2e, &sio_data);
if (address < 0)
address = f71882fg_find(0x4e, &sio_data);
if (address < 0)
return address;
err = platform_driver_register(&f71882fg_driver);
if (err)
return err;
err = f71882fg_device_add(address, &sio_data);
if (err)
goto exit_driver;
return 0;
exit_driver:
platform_driver_unregister(&f71882fg_driver);
return err;
}
static void __exit f71882fg_exit(void)
{
platform_device_unregister(f71882fg_pdev);
platform_driver_unregister(&f71882fg_driver);
}
