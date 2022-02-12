static inline int
superio_inb(int base, int reg)
{
outb(reg, base);
return inb(base + 1);
}
static int
superio_inw(int base, int reg)
{
int val;
outb(reg++, base);
val = inb(base + 1) << 8;
outb(reg, base);
val |= inb(base + 1);
return val;
}
static inline void
superio_select(int base, int ld)
{
outb(SIO_REG_LDSEL, base);
outb(ld, base + 1);
}
static inline void
superio_enter(int base)
{
outb(0x87, base);
outb(0x87, base);
}
static inline void
superio_exit(int base)
{
outb(0xaa, base);
}
static inline long in_from_reg(u8 reg)
{
return reg * 8;
}
static inline u8 in_to_reg(long val)
{
if (val <= 0)
return 0;
if (val >= 2016)
return 0xfc;
return ((val + 16) / 32) << 2;
}
static inline long in0_from_reg(u8 reg)
{
return reg * 16;
}
static inline u8 in0_to_reg(long val)
{
if (val <= 0)
return 0;
if (val >= 4032)
return 0xfc;
return ((val + 32) / 64) << 2;
}
static inline long fan_from_reg(u16 reg)
{
reg &= 0xfff;
if (!reg || reg == 0xfff)
return 0;
return 1500000 / reg;
}
static inline u16 fan_to_reg(long rpm)
{
if (rpm < 367)
return 0xfff;
return 1500000 / rpm;
}
static inline unsigned long pwm_freq_from_reg(u8 reg)
{
unsigned long clock = (reg & 0x80) ? 48000000UL : 1000000UL;
reg &= 0x7f;
if (reg == 0)
reg++;
return clock / (reg << 8);
}
static inline u8 pwm_freq_to_reg(unsigned long val)
{
if (val >= 187500)
return 0x80;
if (val >= 1475)
return 0x80 | (48000000UL / (val << 8));
if (val < 31)
return 0x7f;
else
return 1000000UL / (val << 8);
}
static inline int pwm_mode_from_reg(u8 reg)
{
return !(reg & FAN_CTRL_DC_MODE);
}
static inline long temp_from_reg(u8 reg)
{
return reg * 1000;
}
static inline u8 temp_to_reg(long val)
{
if (val <= 0)
return 0;
if (val >= 1000 * 0xff)
return 0xff;
return (val + 500) / 1000;
}
static u8 f71805f_read8(struct f71805f_data *data, u8 reg)
{
outb(reg, data->addr + ADDR_REG_OFFSET);
return inb(data->addr + DATA_REG_OFFSET);
}
static void f71805f_write8(struct f71805f_data *data, u8 reg, u8 val)
{
outb(reg, data->addr + ADDR_REG_OFFSET);
outb(val, data->addr + DATA_REG_OFFSET);
}
static u16 f71805f_read16(struct f71805f_data *data, u8 reg)
{
u16 val;
outb(reg, data->addr + ADDR_REG_OFFSET);
val = inb(data->addr + DATA_REG_OFFSET) << 8;
outb(++reg, data->addr + ADDR_REG_OFFSET);
val |= inb(data->addr + DATA_REG_OFFSET);
return val;
}
static void f71805f_write16(struct f71805f_data *data, u8 reg, u16 val)
{
outb(reg, data->addr + ADDR_REG_OFFSET);
outb(val >> 8, data->addr + DATA_REG_OFFSET);
outb(++reg, data->addr + ADDR_REG_OFFSET);
outb(val & 0xff, data->addr + DATA_REG_OFFSET);
}
static struct f71805f_data *f71805f_update_device(struct device *dev)
{
struct f71805f_data *data = dev_get_drvdata(dev);
int nr, apnr;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + 60 * HZ)
|| !data->valid) {
for (nr = 0; nr < 11; nr++) {
if (!(data->has_in & (1 << nr)))
continue;
data->in_high[nr] = f71805f_read8(data,
F71805F_REG_IN_HIGH(nr));
data->in_low[nr] = f71805f_read8(data,
F71805F_REG_IN_LOW(nr));
}
for (nr = 0; nr < 3; nr++) {
data->fan_low[nr] = f71805f_read16(data,
F71805F_REG_FAN_LOW(nr));
data->fan_target[nr] = f71805f_read16(data,
F71805F_REG_FAN_TARGET(nr));
data->pwm_freq[nr] = f71805f_read8(data,
F71805F_REG_PWM_FREQ(nr));
}
for (nr = 0; nr < 3; nr++) {
data->temp_high[nr] = f71805f_read8(data,
F71805F_REG_TEMP_HIGH(nr));
data->temp_hyst[nr] = f71805f_read8(data,
F71805F_REG_TEMP_HYST(nr));
}
data->temp_mode = f71805f_read8(data, F71805F_REG_TEMP_MODE);
for (nr = 0; nr < 3; nr++) {
for (apnr = 0; apnr < 3; apnr++) {
data->auto_points[nr].temp[apnr] =
f71805f_read8(data,
F71805F_REG_PWM_AUTO_POINT_TEMP(nr,
apnr));
data->auto_points[nr].fan[apnr] =
f71805f_read16(data,
F71805F_REG_PWM_AUTO_POINT_FAN(nr,
apnr));
}
}
data->last_limits = jiffies;
}
if (time_after(jiffies, data->last_updated + HZ)
|| !data->valid) {
for (nr = 0; nr < 11; nr++) {
if (!(data->has_in & (1 << nr)))
continue;
data->in[nr] = f71805f_read8(data,
F71805F_REG_IN(nr));
}
for (nr = 0; nr < 3; nr++) {
data->fan[nr] = f71805f_read16(data,
F71805F_REG_FAN(nr));
data->fan_ctrl[nr] = f71805f_read8(data,
F71805F_REG_FAN_CTRL(nr));
data->pwm[nr] = f71805f_read8(data,
F71805F_REG_PWM_DUTY(nr));
}
for (nr = 0; nr < 3; nr++) {
data->temp[nr] = f71805f_read8(data,
F71805F_REG_TEMP(nr));
}
data->alarms = f71805f_read8(data, F71805F_REG_STATUS(0))
+ (f71805f_read8(data, F71805F_REG_STATUS(1)) << 8)
+ (f71805f_read8(data, F71805F_REG_STATUS(2)) << 16);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_in0(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", in0_from_reg(data->in[nr]));
}
static ssize_t show_in0_max(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", in0_from_reg(data->in_high[nr]));
}
static ssize_t show_in0_min(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", in0_from_reg(data->in_low[nr]));
}
static ssize_t set_in0_max(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_high[nr] = in0_to_reg(val);
f71805f_write8(data, F71805F_REG_IN_HIGH(nr), data->in_high[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in0_min(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_low[nr] = in0_to_reg(val);
f71805f_write8(data, F71805F_REG_IN_LOW(nr), data->in_low[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", in_from_reg(data->in[nr]));
}
static ssize_t show_in_max(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", in_from_reg(data->in_high[nr]));
}
static ssize_t show_in_min(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", in_from_reg(data->in_low[nr]));
}
static ssize_t set_in_max(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_high[nr] = in_to_reg(val);
f71805f_write8(data, F71805F_REG_IN_HIGH(nr), data->in_high[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_in_min(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_low[nr] = in_to_reg(val);
f71805f_write8(data, F71805F_REG_IN_LOW(nr), data->in_low[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_fan(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", fan_from_reg(data->fan[nr]));
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", fan_from_reg(data->fan_low[nr]));
}
static ssize_t show_fan_target(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", fan_from_reg(data->fan_target[nr]));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_low[nr] = fan_to_reg(val);
f71805f_write16(data, F71805F_REG_FAN_LOW(nr), data->fan_low[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_fan_target(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_target[nr] = fan_to_reg(val);
f71805f_write16(data, F71805F_REG_FAN_TARGET(nr),
data->fan_target[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%d\n", (int)data->pwm[nr]);
}
static ssize_t show_pwm_enable(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
int mode;
switch (data->fan_ctrl[nr] & FAN_CTRL_MODE_MASK) {
case FAN_CTRL_MODE_SPEED:
mode = 3;
break;
case FAN_CTRL_MODE_TEMPERATURE:
mode = 2;
break;
default:
mode = 1;
}
return sprintf(buf, "%d\n", mode);
}
static ssize_t show_pwm_freq(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%lu\n", pwm_freq_from_reg(data->pwm_freq[nr]));
}
static ssize_t show_pwm_mode(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%d\n", pwm_mode_from_reg(data->fan_ctrl[nr]));
}
static ssize_t set_pwm(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 255)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm[nr] = val;
f71805f_write8(data, F71805F_REG_PWM_DUTY(nr), data->pwm[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
u8 reg;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val < 1 || val > 3)
return -EINVAL;
if (val > 1) {
if (sysfs_chmod_file(&dev->kobj, f71805f_attr_pwm[nr],
S_IRUGO))
dev_dbg(dev, "chmod -w pwm%d failed\n", nr + 1);
}
mutex_lock(&data->update_lock);
reg = f71805f_read8(data, F71805F_REG_FAN_CTRL(nr))
& ~FAN_CTRL_MODE_MASK;
switch (val) {
case 1:
reg |= FAN_CTRL_MODE_MANUAL;
break;
case 2:
reg |= FAN_CTRL_MODE_TEMPERATURE;
break;
case 3:
reg |= FAN_CTRL_MODE_SPEED;
break;
}
data->fan_ctrl[nr] = reg;
f71805f_write8(data, F71805F_REG_FAN_CTRL(nr), reg);
mutex_unlock(&data->update_lock);
if (val == 1) {
if (sysfs_chmod_file(&dev->kobj, f71805f_attr_pwm[nr],
S_IRUGO | S_IWUSR))
dev_dbg(dev, "chmod +w pwm%d failed\n", nr + 1);
}
return count;
}
static ssize_t set_pwm_freq(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->pwm_freq[nr] = pwm_freq_to_reg(val);
f71805f_write8(data, F71805F_REG_PWM_FREQ(nr), data->pwm_freq[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_point_temp(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
int pwmnr = attr->nr;
int apnr = attr->index;
return sprintf(buf, "%ld\n",
temp_from_reg(data->auto_points[pwmnr].temp[apnr]));
}
static ssize_t set_pwm_auto_point_temp(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
int pwmnr = attr->nr;
int apnr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->auto_points[pwmnr].temp[apnr] = temp_to_reg(val);
f71805f_write8(data, F71805F_REG_PWM_AUTO_POINT_TEMP(pwmnr, apnr),
data->auto_points[pwmnr].temp[apnr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_pwm_auto_point_fan(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
int pwmnr = attr->nr;
int apnr = attr->index;
return sprintf(buf, "%ld\n",
fan_from_reg(data->auto_points[pwmnr].fan[apnr]));
}
static ssize_t set_pwm_auto_point_fan(struct device *dev,
struct device_attribute *devattr,
const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *attr = to_sensor_dev_attr_2(devattr);
int pwmnr = attr->nr;
int apnr = attr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->auto_points[pwmnr].fan[apnr] = fan_to_reg(val);
f71805f_write16(data, F71805F_REG_PWM_AUTO_POINT_FAN(pwmnr, apnr),
data->auto_points[pwmnr].fan[apnr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_temp(struct device *dev, struct device_attribute *devattr,
char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", temp_from_reg(data->temp[nr]));
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", temp_from_reg(data->temp_high[nr]));
}
static ssize_t show_temp_hyst(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%ld\n", temp_from_reg(data->temp_hyst[nr]));
}
static ssize_t show_temp_type(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
return sprintf(buf, "%u\n", (data->temp_mode & (1 << nr)) ? 3 : 4);
}
static ssize_t set_temp_max(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_high[nr] = temp_to_reg(val);
f71805f_write8(data, F71805F_REG_TEMP_HIGH(nr), data->temp_high[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t set_temp_hyst(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct f71805f_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int nr = attr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->temp_hyst[nr] = temp_to_reg(val);
f71805f_write8(data, F71805F_REG_TEMP_HYST(nr), data->temp_hyst[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_alarms_in(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
return sprintf(buf, "%lu\n", data->alarms & 0x7ff);
}
static ssize_t show_alarms_fan(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
return sprintf(buf, "%lu\n", (data->alarms >> 16) & 0x07);
}
static ssize_t show_alarms_temp(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
return sprintf(buf, "%lu\n", (data->alarms >> 11) & 0x07);
}
static ssize_t show_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = f71805f_update_device(dev);
struct sensor_device_attribute *attr = to_sensor_dev_attr(devattr);
int bitnr = attr->index;
return sprintf(buf, "%lu\n", (data->alarms >> bitnr) & 1);
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct f71805f_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static void __devinit f71805f_init_device(struct f71805f_data *data)
{
u8 reg;
int i;
reg = f71805f_read8(data, F71805F_REG_START);
if ((reg & 0x41) != 0x01) {
printk(KERN_DEBUG DRVNAME ": Starting monitoring "
"operations\n");
f71805f_write8(data, F71805F_REG_START, (reg | 0x01) & ~0x40);
}
for (i = 0; i < 3; i++) {
data->fan_ctrl[i] = f71805f_read8(data,
F71805F_REG_FAN_CTRL(i));
if (data->fan_ctrl[i] & FAN_CTRL_LATCH_FULL) {
data->fan_ctrl[i] &= ~FAN_CTRL_LATCH_FULL;
f71805f_write8(data, F71805F_REG_FAN_CTRL(i),
data->fan_ctrl[i]);
}
}
}
static int __devinit f71805f_probe(struct platform_device *pdev)
{
struct f71805f_sio_data *sio_data = pdev->dev.platform_data;
struct f71805f_data *data;
struct resource *res;
int i, err;
static const char * const names[] = {
"f71805f",
"f71872f",
};
data = devm_kzalloc(&pdev->dev, sizeof(struct f71805f_data),
GFP_KERNEL);
if (!data) {
pr_err("Out of memory\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(&pdev->dev, res->start + ADDR_REG_OFFSET, 2,
DRVNAME)) {
dev_err(&pdev->dev, "Failed to request region 0x%lx-0x%lx\n",
(unsigned long)(res->start + ADDR_REG_OFFSET),
(unsigned long)(res->start + ADDR_REG_OFFSET + 1));
return -EBUSY;
}
data->addr = res->start;
data->name = names[sio_data->kind];
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
switch (sio_data->kind) {
case f71805f:
data->has_in = 0x1ff;
break;
case f71872f:
data->has_in = 0x6ef;
if (sio_data->fnsel1 & 0x01)
data->has_in |= (1 << 4);
if (sio_data->fnsel1 & 0x02)
data->has_in |= (1 << 8);
break;
}
f71805f_init_device(data);
err = sysfs_create_group(&pdev->dev.kobj, &f71805f_group);
if (err)
return err;
if (data->has_in & (1 << 4)) {
err = sysfs_create_group(&pdev->dev.kobj,
&f71805f_group_optin[0]);
if (err)
goto exit_remove_files;
}
if (data->has_in & (1 << 8)) {
err = sysfs_create_group(&pdev->dev.kobj,
&f71805f_group_optin[1]);
if (err)
goto exit_remove_files;
}
if (data->has_in & (1 << 9)) {
err = sysfs_create_group(&pdev->dev.kobj,
&f71805f_group_optin[2]);
if (err)
goto exit_remove_files;
}
if (data->has_in & (1 << 10)) {
err = sysfs_create_group(&pdev->dev.kobj,
&f71805f_group_optin[3]);
if (err)
goto exit_remove_files;
}
for (i = 0; i < 3; i++) {
if (!(data->fan_ctrl[i] & FAN_CTRL_DC_MODE)) {
err = sysfs_create_file(&pdev->dev.kobj,
f71805f_attributes_pwm_freq[i]);
if (err)
goto exit_remove_files;
}
if (data->fan_ctrl[i] & FAN_CTRL_MODE_MANUAL) {
err = sysfs_chmod_file(&pdev->dev.kobj,
f71805f_attr_pwm[i],
S_IRUGO | S_IWUSR);
if (err) {
dev_err(&pdev->dev, "chmod +w pwm%d failed\n",
i + 1);
goto exit_remove_files;
}
}
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
dev_err(&pdev->dev, "Class registration failed (%d)\n", err);
goto exit_remove_files;
}
return 0;
exit_remove_files:
sysfs_remove_group(&pdev->dev.kobj, &f71805f_group);
for (i = 0; i < 4; i++)
sysfs_remove_group(&pdev->dev.kobj, &f71805f_group_optin[i]);
sysfs_remove_group(&pdev->dev.kobj, &f71805f_group_pwm_freq);
return err;
}
static int __devexit f71805f_remove(struct platform_device *pdev)
{
struct f71805f_data *data = platform_get_drvdata(pdev);
int i;
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &f71805f_group);
for (i = 0; i < 4; i++)
sysfs_remove_group(&pdev->dev.kobj, &f71805f_group_optin[i]);
sysfs_remove_group(&pdev->dev.kobj, &f71805f_group_pwm_freq);
return 0;
}
static int __init f71805f_device_add(unsigned short address,
const struct f71805f_sio_data *sio_data)
{
struct resource res = {
.start = address,
.end = address + REGION_LENGTH - 1,
.flags = IORESOURCE_IO,
};
int err;
pdev = platform_device_alloc(DRVNAME, address);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
res.name = pdev->name;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit_device_put;
err = platform_device_add_resources(pdev, &res, 1);
if (err) {
pr_err("Device resource addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_device_add_data(pdev, sio_data,
sizeof(struct f71805f_sio_data));
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
static int __init f71805f_find(int sioaddr, unsigned short *address,
struct f71805f_sio_data *sio_data)
{
int err = -ENODEV;
u16 devid;
static const char * const names[] = {
"F71805F/FG",
"F71872F/FG or F71806F/FG",
};
superio_enter(sioaddr);
devid = superio_inw(sioaddr, SIO_REG_MANID);
if (devid != SIO_FINTEK_ID)
goto exit;
devid = force_id ? force_id : superio_inw(sioaddr, SIO_REG_DEVID);
switch (devid) {
case SIO_F71805F_ID:
sio_data->kind = f71805f;
break;
case SIO_F71872F_ID:
sio_data->kind = f71872f;
sio_data->fnsel1 = superio_inb(sioaddr, SIO_REG_FNSEL1);
break;
default:
pr_info("Unsupported Fintek device, skipping\n");
goto exit;
}
superio_select(sioaddr, F71805F_LD_HWM);
if (!(superio_inb(sioaddr, SIO_REG_ENABLE) & 0x01)) {
pr_warn("Device not activated, skipping\n");
goto exit;
}
*address = superio_inw(sioaddr, SIO_REG_ADDR);
if (*address == 0) {
pr_warn("Base address not set, skipping\n");
goto exit;
}
*address &= ~(REGION_LENGTH - 1);
err = 0;
pr_info("Found %s chip at %#x, revision %u\n",
names[sio_data->kind], *address,
superio_inb(sioaddr, SIO_REG_DEVREV));
exit:
superio_exit(sioaddr);
return err;
}
static int __init f71805f_init(void)
{
int err;
unsigned short address;
struct f71805f_sio_data sio_data;
if (f71805f_find(0x2e, &address, &sio_data)
&& f71805f_find(0x4e, &address, &sio_data))
return -ENODEV;
err = platform_driver_register(&f71805f_driver);
if (err)
goto exit;
err = f71805f_device_add(address, &sio_data);
if (err)
goto exit_driver;
return 0;
exit_driver:
platform_driver_unregister(&f71805f_driver);
exit:
return err;
}
static void __exit f71805f_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&f71805f_driver);
}
