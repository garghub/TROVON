static inline void
superio_outb(struct w83627hf_sio_data *sio, int reg, int val)
{
outb(reg, sio->sioaddr);
outb(val, sio->sioaddr + 1);
}
static inline int
superio_inb(struct w83627hf_sio_data *sio, int reg)
{
outb(reg, sio->sioaddr);
return inb(sio->sioaddr + 1);
}
static inline void
superio_select(struct w83627hf_sio_data *sio, int ld)
{
outb(DEV, sio->sioaddr);
outb(ld, sio->sioaddr + 1);
}
static inline void
superio_enter(struct w83627hf_sio_data *sio)
{
outb(0x87, sio->sioaddr);
outb(0x87, sio->sioaddr);
}
static inline void
superio_exit(struct w83627hf_sio_data *sio)
{
outb(0xAA, sio->sioaddr);
}
static inline u8 FAN_TO_REG(long rpm, int div)
{
if (rpm == 0)
return 255;
rpm = clamp_val(rpm, 1, 1000000);
return clamp_val((1350000 + rpm * div / 2) / (rpm * div), 1, 254);
}
static u8 TEMP_TO_REG(long temp)
{
int ntemp = clamp_val(temp, TEMP_MIN, TEMP_MAX);
ntemp += (ntemp < 0 ? -500 : 500);
return (u8)(ntemp / 1000);
}
static int TEMP_FROM_REG(u8 reg)
{
return (s8)reg * 1000;
}
static inline unsigned long pwm_freq_from_reg_627hf(u8 reg)
{
unsigned long freq;
freq = W83627HF_BASE_PWM_FREQ >> reg;
return freq;
}
static inline u8 pwm_freq_to_reg_627hf(unsigned long val)
{
u8 i;
for (i = 0; i < 4; i++) {
if (val > (((W83627HF_BASE_PWM_FREQ >> i) +
(W83627HF_BASE_PWM_FREQ >> (i+1))) / 2))
break;
}
return i;
}
static inline unsigned long pwm_freq_from_reg(u8 reg)
{
unsigned long clock = (reg & 0x80) ? 180000UL : 24000000UL;
reg &= 0x7f;
if (reg == 0)
reg++;
return clock / (reg << 8);
}
static inline u8 pwm_freq_to_reg(unsigned long val)
{
if (val >= 93750)
return 0x01;
if (val >= 720)
return 24000000UL / (val << 8);
if (val < 6)
return 0xFF;
else
return 0x80 | (180000UL / (val << 8));
}
static inline u8 DIV_TO_REG(long val)
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
static int w83627hf_suspend(struct device *dev)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
mutex_lock(&data->update_lock);
data->scfg1 = w83627hf_read_value(data, W83781D_REG_SCFG1);
data->scfg2 = w83627hf_read_value(data, W83781D_REG_SCFG2);
mutex_unlock(&data->update_lock);
return 0;
}
static int w83627hf_resume(struct device *dev)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
int i, num_temps = (data->type == w83697hf) ? 2 : 3;
mutex_lock(&data->update_lock);
for (i = 0; i <= 8; i++) {
if (((data->type == w83697hf) && (i == 1)) ||
((data->type != w83627hf && data->type != w83697hf)
&& (i == 5 || i == 6)))
continue;
w83627hf_write_value(data, W83781D_REG_IN_MAX(i),
data->in_max[i]);
w83627hf_write_value(data, W83781D_REG_IN_MIN(i),
data->in_min[i]);
}
for (i = 0; i <= 2; i++)
w83627hf_write_value(data, W83627HF_REG_FAN_MIN(i),
data->fan_min[i]);
for (i = 0; i < num_temps; i++) {
w83627hf_write_value(data, w83627hf_reg_temp_over[i],
data->temp_max[i]);
w83627hf_write_value(data, w83627hf_reg_temp_hyst[i],
data->temp_max_hyst[i]);
}
if (data->type == w83627thf || data->type == w83637hf ||
data->type == w83687thf)
w83627hf_write_value(data, W83627THF_REG_VRM_OVT_CFG,
data->vrm_ovt);
w83627hf_write_value(data, W83781D_REG_SCFG1, data->scfg1);
w83627hf_write_value(data, W83781D_REG_SCFG2, data->scfg2);
data->valid = 0;
mutex_unlock(&data->update_lock);
return 0;
}
static ssize_t
show_in_input(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", (long)IN_FROM_REG(data->in[nr]));
}
static ssize_t
show_in_min(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", (long)IN_FROM_REG(data->in_min[nr]));
}
static ssize_t
show_in_max(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", (long)IN_FROM_REG(data->in_max[nr]));
}
static ssize_t
store_in_min(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_min[nr] = IN_TO_REG(val);
w83627hf_write_value(data, W83781D_REG_IN_MIN(nr), data->in_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_in_max(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->in_max[nr] = IN_TO_REG(val);
w83627hf_write_value(data, W83781D_REG_IN_MAX(nr), data->in_max[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_in_0(struct w83627hf_data *data, char *buf, u8 reg)
{
long in0;
if ((data->vrm_ovt & 0x01) &&
(w83627thf == data->type || w83637hf == data->type
|| w83687thf == data->type))
in0 = (long)((reg * 488 + 70000 + 50) / 100);
else
in0 = (long)IN_FROM_REG(reg);
return sprintf(buf,"%ld\n", in0);
}
static ssize_t show_regs_in_0(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
return show_in_0(data, buf, data->in[0]);
}
static ssize_t show_regs_in_min0(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
return show_in_0(data, buf, data->in_min[0]);
}
static ssize_t show_regs_in_max0(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
return show_in_0(data, buf, data->in_max[0]);
}
static ssize_t store_regs_in_min0(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if ((data->vrm_ovt & 0x01) &&
(w83627thf == data->type || w83637hf == data->type
|| w83687thf == data->type))
data->in_min[0] =
clamp_val(((val * 100) - 70000 + 244) / 488, 0, 255);
else
data->in_min[0] = IN_TO_REG(val);
w83627hf_write_value(data, W83781D_REG_IN_MIN(0), data->in_min[0]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t store_regs_in_max0(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if ((data->vrm_ovt & 0x01) &&
(w83627thf == data->type || w83637hf == data->type
|| w83687thf == data->type))
data->in_max[0] =
clamp_val(((val * 100) - 70000 + 244) / 488, 0, 255);
else
data->in_max[0] = IN_TO_REG(val);
w83627hf_write_value(data, W83781D_REG_IN_MAX(0), data->in_max[0]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_input(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", FAN_FROM_REG(data->fan[nr],
(long)DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t
show_fan_min(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", FAN_FROM_REG(data->fan_min[nr],
(long)DIV_FROM_REG(data->fan_div[nr])));
}
static ssize_t
store_fan_min(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->fan_min[nr] = FAN_TO_REG(val, DIV_FROM_REG(data->fan_div[nr]));
w83627hf_write_value(data, W83627HF_REG_FAN_MIN(nr),
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
u16 tmp = data->temp[nr];
return sprintf(buf, "%ld\n", (nr) ? (long) LM75_TEMP_FROM_REG(tmp)
: (long) TEMP_FROM_REG(tmp));
}
static ssize_t
show_temp_max(struct device *dev, struct device_attribute *devattr,
char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
u16 tmp = data->temp_max[nr];
return sprintf(buf, "%ld\n", (nr) ? (long) LM75_TEMP_FROM_REG(tmp)
: (long) TEMP_FROM_REG(tmp));
}
static ssize_t
show_temp_max_hyst(struct device *dev, struct device_attribute *devattr,
char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
u16 tmp = data->temp_max_hyst[nr];
return sprintf(buf, "%ld\n", (nr) ? (long) LM75_TEMP_FROM_REG(tmp)
: (long) TEMP_FROM_REG(tmp));
}
static ssize_t
store_temp_max(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
u16 tmp;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
tmp = (nr) ? LM75_TEMP_TO_REG(val) : TEMP_TO_REG(val);
mutex_lock(&data->update_lock);
data->temp_max[nr] = tmp;
w83627hf_write_value(data, w83627hf_reg_temp_over[nr], tmp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_temp_max_hyst(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
u16 tmp;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err)
return err;
tmp = (nr) ? LM75_TEMP_TO_REG(val) : TEMP_TO_REG(val);
mutex_lock(&data->update_lock);
data->temp_max_hyst[nr] = tmp;
w83627hf_write_value(data, w83627hf_reg_temp_hyst[nr], tmp);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_vid_reg(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", (long) vid_from_reg(data->vid, data->vrm));
}
static ssize_t
show_vrm_reg(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%ld\n", (long) data->vrm);
}
static ssize_t
store_vrm_reg(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
data->vrm = val;
return count;
}
static ssize_t
show_alarms_reg(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", (long) data->alarms);
}
static ssize_t
show_alarm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u\n", (data->alarms >> bitnr) & 1);
}
static ssize_t
show_beep_mask(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n",
(long)BEEP_MASK_FROM_REG(data->beep_mask));
}
static ssize_t
store_beep_mask(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
data->beep_mask = (data->beep_mask & 0x8000)
| BEEP_MASK_TO_REG(val);
w83627hf_write_value(data, W83781D_REG_BEEP_INTS1,
data->beep_mask & 0xff);
w83627hf_write_value(data, W83781D_REG_BEEP_INTS3,
((data->beep_mask) >> 16) & 0xff);
w83627hf_write_value(data, W83781D_REG_BEEP_INTS2,
(data->beep_mask >> 8) & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_beep(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627hf_data *data = w83627hf_update_device(dev);
int bitnr = to_sensor_dev_attr(attr)->index;
return sprintf(buf, "%u\n", (data->beep_mask >> bitnr) & 1);
}
static ssize_t
store_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
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
reg = w83627hf_read_value(data, W83781D_REG_BEEP_INTS1);
if (bit)
reg |= (1 << bitnr);
else
reg &= ~(1 << bitnr);
w83627hf_write_value(data, W83781D_REG_BEEP_INTS1, reg);
} else if (bitnr < 16) {
reg = w83627hf_read_value(data, W83781D_REG_BEEP_INTS2);
if (bit)
reg |= (1 << (bitnr - 8));
else
reg &= ~(1 << (bitnr - 8));
w83627hf_write_value(data, W83781D_REG_BEEP_INTS2, reg);
} else {
reg = w83627hf_read_value(data, W83781D_REG_BEEP_INTS3);
if (bit)
reg |= (1 << (bitnr - 16));
else
reg &= ~(1 << (bitnr - 16));
w83627hf_write_value(data, W83781D_REG_BEEP_INTS3, reg);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n",
(long) DIV_FROM_REG(data->fan_div[nr]));
}
static ssize_t
store_fan_div(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long min;
u8 reg;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
min = FAN_FROM_REG(data->fan_min[nr],
DIV_FROM_REG(data->fan_div[nr]));
data->fan_div[nr] = DIV_TO_REG(val);
reg = (w83627hf_read_value(data, nr==2 ? W83781D_REG_PIN : W83781D_REG_VID_FANDIV)
& (nr==0 ? 0xcf : 0x3f))
| ((data->fan_div[nr] & 0x03) << (nr==0 ? 4 : 6));
w83627hf_write_value(data, nr==2 ? W83781D_REG_PIN : W83781D_REG_VID_FANDIV, reg);
reg = (w83627hf_read_value(data, W83781D_REG_VBAT)
& ~(1 << (5 + nr)))
| ((data->fan_div[nr] & 0x04) << (3 + nr));
w83627hf_write_value(data, W83781D_REG_VBAT, reg);
data->fan_min[nr] = FAN_TO_REG(min, DIV_FROM_REG(data->fan_div[nr]));
w83627hf_write_value(data, W83627HF_REG_FAN_MIN(nr), data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", (long) data->pwm[nr]);
}
static ssize_t
store_pwm(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (data->type == w83627thf) {
data->pwm[nr] = PWM_TO_REG(val) & 0xf0;
w83627hf_write_value(data,
W836X7HF_REG_PWM(data->type, nr),
data->pwm[nr] |
(w83627hf_read_value(data,
W836X7HF_REG_PWM(data->type, nr)) & 0x0f));
} else {
data->pwm[nr] = PWM_TO_REG(val);
w83627hf_write_value(data,
W836X7HF_REG_PWM(data->type, nr),
data->pwm[nr]);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm_enable(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%d\n", data->pwm_enable[nr]);
}
static ssize_t
store_pwm_enable(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
u8 reg;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (!val || val > 3)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm_enable[nr] = val;
reg = w83627hf_read_value(data, W83627THF_REG_PWM_ENABLE[nr]);
reg &= ~(0x03 << W83627THF_PWM_ENABLE_SHIFT[nr]);
reg |= (val - 1) << W83627THF_PWM_ENABLE_SHIFT[nr];
w83627hf_write_value(data, W83627THF_REG_PWM_ENABLE[nr], reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm_freq(struct device *dev, struct device_attribute *devattr, char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
if (data->type == w83627hf)
return sprintf(buf, "%ld\n",
pwm_freq_from_reg_627hf(data->pwm_freq[nr]));
else
return sprintf(buf, "%ld\n",
pwm_freq_from_reg(data->pwm_freq[nr]));
}
static ssize_t
store_pwm_freq(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
static const u8 mask[]={0xF8, 0x8F};
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
if (data->type == w83627hf) {
data->pwm_freq[nr] = pwm_freq_to_reg_627hf(val);
w83627hf_write_value(data, W83627HF_REG_PWM_FREQ,
(data->pwm_freq[nr] << (nr*4)) |
(w83627hf_read_value(data,
W83627HF_REG_PWM_FREQ) & mask[nr]));
} else {
data->pwm_freq[nr] = pwm_freq_to_reg(val);
w83627hf_write_value(data, W83637HF_REG_PWM_FREQ[nr],
data->pwm_freq[nr]);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp_type(struct device *dev, struct device_attribute *devattr,
char *buf)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = w83627hf_update_device(dev);
return sprintf(buf, "%ld\n", (long) data->sens[nr]);
}
static ssize_t
store_temp_type(struct device *dev, struct device_attribute *devattr,
const char *buf, size_t count)
{
int nr = to_sensor_dev_attr(devattr)->index;
struct w83627hf_data *data = dev_get_drvdata(dev);
unsigned long val;
u32 tmp;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
mutex_lock(&data->update_lock);
switch (val) {
case 1:
tmp = w83627hf_read_value(data, W83781D_REG_SCFG1);
w83627hf_write_value(data, W83781D_REG_SCFG1,
tmp | BIT_SCFG1[nr]);
tmp = w83627hf_read_value(data, W83781D_REG_SCFG2);
w83627hf_write_value(data, W83781D_REG_SCFG2,
tmp | BIT_SCFG2[nr]);
data->sens[nr] = val;
break;
case 2:
tmp = w83627hf_read_value(data, W83781D_REG_SCFG1);
w83627hf_write_value(data, W83781D_REG_SCFG1,
tmp | BIT_SCFG1[nr]);
tmp = w83627hf_read_value(data, W83781D_REG_SCFG2);
w83627hf_write_value(data, W83781D_REG_SCFG2,
tmp & ~BIT_SCFG2[nr]);
data->sens[nr] = val;
break;
case W83781D_DEFAULT_BETA:
dev_warn(dev, "Sensor type %d is deprecated, please use 4 "
"instead\n", W83781D_DEFAULT_BETA);
case 4:
tmp = w83627hf_read_value(data, W83781D_REG_SCFG1);
w83627hf_write_value(data, W83781D_REG_SCFG1,
tmp & ~BIT_SCFG1[nr]);
data->sens[nr] = val;
break;
default:
dev_err(dev,
"Invalid sensor type %ld; must be 1, 2, or 4\n",
(long) val);
break;
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_name(struct device *dev, struct device_attribute *devattr, char *buf)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static int __init w83627hf_find(int sioaddr, unsigned short *addr,
struct w83627hf_sio_data *sio_data)
{
int err = -ENODEV;
u16 val;
static __initconst char *const names[] = {
"W83627HF",
"W83627THF",
"W83697HF",
"W83637HF",
"W83687THF",
};
sio_data->sioaddr = sioaddr;
superio_enter(sio_data);
val = force_id ? force_id : superio_inb(sio_data, DEVID);
switch (val) {
case W627_DEVID:
sio_data->type = w83627hf;
break;
case W627THF_DEVID:
sio_data->type = w83627thf;
break;
case W697_DEVID:
sio_data->type = w83697hf;
break;
case W637_DEVID:
sio_data->type = w83637hf;
break;
case W687THF_DEVID:
sio_data->type = w83687thf;
break;
case 0xff:
goto exit;
default:
pr_debug(DRVNAME ": Unsupported chip (DEVID=0x%02x)\n", val);
goto exit;
}
superio_select(sio_data, W83627HF_LD_HWM);
val = (superio_inb(sio_data, WINB_BASE_REG) << 8) |
superio_inb(sio_data, WINB_BASE_REG + 1);
*addr = val & WINB_ALIGNMENT;
if (*addr == 0) {
pr_warn("Base address not set, skipping\n");
goto exit;
}
val = superio_inb(sio_data, WINB_ACT_REG);
if (!(val & 0x01)) {
pr_warn("Enabling HWM logical device\n");
superio_outb(sio_data, WINB_ACT_REG, val | 0x01);
}
err = 0;
pr_info(DRVNAME ": Found %s chip at %#x\n",
names[sio_data->type], *addr);
exit:
superio_exit(sio_data);
return err;
}
static int w83627hf_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct w83627hf_sio_data *sio_data = dev_get_platdata(dev);
struct w83627hf_data *data;
struct resource *res;
int err, i;
static const char *names[] = {
"w83627hf",
"w83627thf",
"w83697hf",
"w83637hf",
"w83687thf",
};
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(dev, res->start, WINB_REGION_SIZE, DRVNAME)) {
dev_err(dev, "Failed to request region 0x%lx-0x%lx\n",
(unsigned long)res->start,
(unsigned long)(res->start + WINB_REGION_SIZE - 1));
return -EBUSY;
}
data = devm_kzalloc(dev, sizeof(struct w83627hf_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->addr = res->start;
data->type = sio_data->type;
data->name = names[sio_data->type];
mutex_init(&data->lock);
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
w83627hf_init_device(pdev);
for (i = 0; i <= 2; i++)
data->fan_min[i] = w83627hf_read_value(
data, W83627HF_REG_FAN_MIN(i));
w83627hf_update_fan_div(data);
err = sysfs_create_group(&dev->kobj, &w83627hf_group);
if (err)
return err;
if (data->type == w83627hf || data->type == w83697hf)
if ((err = device_create_file(dev,
&sensor_dev_attr_in5_input.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in5_min.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in5_max.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in5_alarm.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in5_beep.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in6_input.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in6_min.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in6_max.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in6_alarm.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in6_beep.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_pwm1_freq.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_pwm2_freq.dev_attr)))
goto error;
if (data->type != w83697hf)
if ((err = device_create_file(dev,
&sensor_dev_attr_in1_input.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in1_min.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in1_max.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in1_alarm.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_in1_beep.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_fan3_input.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_fan3_min.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_fan3_div.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_fan3_alarm.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_fan3_beep.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_temp3_input.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_temp3_max.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_temp3_max_hyst.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_temp3_alarm.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_temp3_beep.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_temp3_type.dev_attr)))
goto error;
if (data->type != w83697hf && data->vid != 0xff) {
data->vrm = vid_which_vrm();
if ((err = device_create_file(dev, &dev_attr_cpu0_vid))
|| (err = device_create_file(dev, &dev_attr_vrm)))
goto error;
}
if (data->type == w83627thf || data->type == w83637hf
|| data->type == w83687thf) {
err = device_create_file(dev, &sensor_dev_attr_pwm3.dev_attr);
if (err)
goto error;
}
if (data->type == w83637hf || data->type == w83687thf)
if ((err = device_create_file(dev,
&sensor_dev_attr_pwm1_freq.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_pwm2_freq.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_pwm3_freq.dev_attr)))
goto error;
if (data->type != w83627hf)
if ((err = device_create_file(dev,
&sensor_dev_attr_pwm1_enable.dev_attr))
|| (err = device_create_file(dev,
&sensor_dev_attr_pwm2_enable.dev_attr)))
goto error;
if (data->type == w83627thf || data->type == w83637hf
|| data->type == w83687thf) {
err = device_create_file(dev,
&sensor_dev_attr_pwm3_enable.dev_attr);
if (err)
goto error;
}
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto error;
}
return 0;
error:
sysfs_remove_group(&dev->kobj, &w83627hf_group);
sysfs_remove_group(&dev->kobj, &w83627hf_group_opt);
return err;
}
static int w83627hf_remove(struct platform_device *pdev)
{
struct w83627hf_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
sysfs_remove_group(&pdev->dev.kobj, &w83627hf_group);
sysfs_remove_group(&pdev->dev.kobj, &w83627hf_group_opt);
return 0;
}
static inline void w83627hf_set_bank(struct w83627hf_data *data, u16 reg)
{
if ((reg & 0x00f0) == 0x50) {
outb_p(W83781D_REG_BANK, data->addr + W83781D_ADDR_REG_OFFSET);
outb_p(reg >> 8, data->addr + W83781D_DATA_REG_OFFSET);
}
}
static inline void w83627hf_reset_bank(struct w83627hf_data *data, u16 reg)
{
if (reg & 0xff00) {
outb_p(W83781D_REG_BANK, data->addr + W83781D_ADDR_REG_OFFSET);
outb_p(0, data->addr + W83781D_DATA_REG_OFFSET);
}
}
static int w83627hf_read_value(struct w83627hf_data *data, u16 reg)
{
int res, word_sized;
mutex_lock(&data->lock);
word_sized = (((reg & 0xff00) == 0x100)
|| ((reg & 0xff00) == 0x200))
&& (((reg & 0x00ff) == 0x50)
|| ((reg & 0x00ff) == 0x53)
|| ((reg & 0x00ff) == 0x55));
w83627hf_set_bank(data, reg);
outb_p(reg & 0xff, data->addr + W83781D_ADDR_REG_OFFSET);
res = inb_p(data->addr + W83781D_DATA_REG_OFFSET);
if (word_sized) {
outb_p((reg & 0xff) + 1,
data->addr + W83781D_ADDR_REG_OFFSET);
res =
(res << 8) + inb_p(data->addr +
W83781D_DATA_REG_OFFSET);
}
w83627hf_reset_bank(data, reg);
mutex_unlock(&data->lock);
return res;
}
static int w83627thf_read_gpio5(struct platform_device *pdev)
{
struct w83627hf_sio_data *sio_data = dev_get_platdata(&pdev->dev);
int res = 0xff, sel;
superio_enter(sio_data);
superio_select(sio_data, W83627HF_LD_GPIO5);
if (!(superio_inb(sio_data, W83627THF_GPIO5_EN) & (1<<3))) {
dev_dbg(&pdev->dev, "GPIO5 disabled, no VID function\n");
goto exit;
}
sel = superio_inb(sio_data, W83627THF_GPIO5_IOSR) & 0x3f;
if ((sel & 0x1f) != 0x1f) {
dev_dbg(&pdev->dev, "GPIO5 not configured for VID "
"function\n");
goto exit;
}
dev_info(&pdev->dev, "Reading VID from GPIO5\n");
res = superio_inb(sio_data, W83627THF_GPIO5_DR) & sel;
exit:
superio_exit(sio_data);
return res;
}
static int w83687thf_read_vid(struct platform_device *pdev)
{
struct w83627hf_sio_data *sio_data = dev_get_platdata(&pdev->dev);
int res = 0xff;
superio_enter(sio_data);
superio_select(sio_data, W83627HF_LD_HWM);
if (!(superio_inb(sio_data, W83687THF_VID_EN) & (1 << 2))) {
dev_dbg(&pdev->dev, "VID disabled, no VID function\n");
goto exit;
}
if (!(superio_inb(sio_data, W83687THF_VID_CFG) & (1 << 4))) {
dev_dbg(&pdev->dev, "VID configured as output, "
"no VID function\n");
goto exit;
}
res = superio_inb(sio_data, W83687THF_VID_DATA) & 0x3f;
exit:
superio_exit(sio_data);
return res;
}
static int w83627hf_write_value(struct w83627hf_data *data, u16 reg, u16 value)
{
int word_sized;
mutex_lock(&data->lock);
word_sized = (((reg & 0xff00) == 0x100)
|| ((reg & 0xff00) == 0x200))
&& (((reg & 0x00ff) == 0x53)
|| ((reg & 0x00ff) == 0x55));
w83627hf_set_bank(data, reg);
outb_p(reg & 0xff, data->addr + W83781D_ADDR_REG_OFFSET);
if (word_sized) {
outb_p(value >> 8,
data->addr + W83781D_DATA_REG_OFFSET);
outb_p((reg & 0xff) + 1,
data->addr + W83781D_ADDR_REG_OFFSET);
}
outb_p(value & 0xff,
data->addr + W83781D_DATA_REG_OFFSET);
w83627hf_reset_bank(data, reg);
mutex_unlock(&data->lock);
return 0;
}
static void w83627hf_init_device(struct platform_device *pdev)
{
struct w83627hf_data *data = platform_get_drvdata(pdev);
int i;
enum chips type = data->type;
u8 tmp;
if (type == w83627hf) {
w83627hf_write_value(data, W83781D_REG_I2C_SUBADDR, 0x89);
w83627hf_write_value(data, W83781D_REG_I2C_ADDR, force_i2c);
}
if (type == w83627hf || type == w83637hf) {
int lo = w83627hf_read_value(data, W83781D_REG_VID_FANDIV);
int hi = w83627hf_read_value(data, W83781D_REG_CHIPID);
data->vid = (lo & 0x0f) | ((hi & 0x01) << 4);
} else if (type == w83627thf) {
data->vid = w83627thf_read_gpio5(pdev);
} else if (type == w83687thf) {
data->vid = w83687thf_read_vid(pdev);
}
if (type == w83627thf || type == w83637hf || type == w83687thf) {
data->vrm_ovt =
w83627hf_read_value(data, W83627THF_REG_VRM_OVT_CFG);
}
tmp = w83627hf_read_value(data, W83781D_REG_SCFG1);
for (i = 1; i <= 3; i++) {
if (!(tmp & BIT_SCFG1[i - 1])) {
data->sens[i - 1] = 4;
} else {
if (w83627hf_read_value
(data,
W83781D_REG_SCFG2) & BIT_SCFG2[i - 1])
data->sens[i - 1] = 1;
else
data->sens[i - 1] = 2;
}
if ((type == w83697hf) && (i == 2))
break;
}
if(init) {
tmp = w83627hf_read_value(data, W83627HF_REG_TEMP2_CONFIG);
if (tmp & 0x01) {
dev_warn(&pdev->dev, "Enabling temp2, readings "
"might not make sense\n");
w83627hf_write_value(data, W83627HF_REG_TEMP2_CONFIG,
tmp & 0xfe);
}
if (type != w83697hf) {
tmp = w83627hf_read_value(data,
W83627HF_REG_TEMP3_CONFIG);
if (tmp & 0x01) {
dev_warn(&pdev->dev, "Enabling temp3, "
"readings might not make sense\n");
w83627hf_write_value(data,
W83627HF_REG_TEMP3_CONFIG, tmp & 0xfe);
}
}
}
w83627hf_write_value(data, W83781D_REG_CONFIG,
(w83627hf_read_value(data,
W83781D_REG_CONFIG) & 0xf7)
| 0x01);
tmp = w83627hf_read_value(data, W83781D_REG_VBAT);
if (!(tmp & 0x01))
w83627hf_write_value(data, W83781D_REG_VBAT, tmp | 0x01);
}
static void w83627hf_update_fan_div(struct w83627hf_data *data)
{
int reg;
reg = w83627hf_read_value(data, W83781D_REG_VID_FANDIV);
data->fan_div[0] = (reg >> 4) & 0x03;
data->fan_div[1] = (reg >> 6) & 0x03;
if (data->type != w83697hf) {
data->fan_div[2] = (w83627hf_read_value(data,
W83781D_REG_PIN) >> 6) & 0x03;
}
reg = w83627hf_read_value(data, W83781D_REG_VBAT);
data->fan_div[0] |= (reg >> 3) & 0x04;
data->fan_div[1] |= (reg >> 4) & 0x04;
if (data->type != w83697hf)
data->fan_div[2] |= (reg >> 5) & 0x04;
}
static struct w83627hf_data *w83627hf_update_device(struct device *dev)
{
struct w83627hf_data *data = dev_get_drvdata(dev);
int i, num_temps = (data->type == w83697hf) ? 2 : 3;
int num_pwms = (data->type == w83697hf) ? 2 : 3;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
for (i = 0; i <= 8; i++) {
if (((data->type == w83697hf) && (i == 1)) ||
((data->type != w83627hf && data->type != w83697hf)
&& (i == 5 || i == 6)))
continue;
data->in[i] =
w83627hf_read_value(data, W83781D_REG_IN(i));
data->in_min[i] =
w83627hf_read_value(data,
W83781D_REG_IN_MIN(i));
data->in_max[i] =
w83627hf_read_value(data,
W83781D_REG_IN_MAX(i));
}
for (i = 0; i <= 2; i++) {
data->fan[i] =
w83627hf_read_value(data, W83627HF_REG_FAN(i));
data->fan_min[i] =
w83627hf_read_value(data,
W83627HF_REG_FAN_MIN(i));
}
for (i = 0; i <= 2; i++) {
u8 tmp = w83627hf_read_value(data,
W836X7HF_REG_PWM(data->type, i));
if (data->type == w83627thf)
tmp &= 0xf0;
data->pwm[i] = tmp;
if (i == 1 &&
(data->type == w83627hf || data->type == w83697hf))
break;
}
if (data->type == w83627hf) {
u8 tmp = w83627hf_read_value(data,
W83627HF_REG_PWM_FREQ);
data->pwm_freq[0] = tmp & 0x07;
data->pwm_freq[1] = (tmp >> 4) & 0x07;
} else if (data->type != w83627thf) {
for (i = 1; i <= 3; i++) {
data->pwm_freq[i - 1] =
w83627hf_read_value(data,
W83637HF_REG_PWM_FREQ[i - 1]);
if (i == 2 && (data->type == w83697hf))
break;
}
}
if (data->type != w83627hf) {
for (i = 0; i < num_pwms; i++) {
u8 tmp = w83627hf_read_value(data,
W83627THF_REG_PWM_ENABLE[i]);
data->pwm_enable[i] =
((tmp >> W83627THF_PWM_ENABLE_SHIFT[i])
& 0x03) + 1;
}
}
for (i = 0; i < num_temps; i++) {
data->temp[i] = w83627hf_read_value(
data, w83627hf_reg_temp[i]);
data->temp_max[i] = w83627hf_read_value(
data, w83627hf_reg_temp_over[i]);
data->temp_max_hyst[i] = w83627hf_read_value(
data, w83627hf_reg_temp_hyst[i]);
}
w83627hf_update_fan_div(data);
data->alarms =
w83627hf_read_value(data, W83781D_REG_ALARM1) |
(w83627hf_read_value(data, W83781D_REG_ALARM2) << 8) |
(w83627hf_read_value(data, W83781D_REG_ALARM3) << 16);
i = w83627hf_read_value(data, W83781D_REG_BEEP_INTS2);
data->beep_mask = (i << 8) |
w83627hf_read_value(data, W83781D_REG_BEEP_INTS1) |
w83627hf_read_value(data, W83781D_REG_BEEP_INTS3) << 16;
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static int __init w83627hf_device_add(unsigned short address,
const struct w83627hf_sio_data *sio_data)
{
struct resource res = {
.start = address + WINB_REGION_OFFSET,
.end = address + WINB_REGION_OFFSET + WINB_REGION_SIZE - 1,
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
sizeof(struct w83627hf_sio_data));
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
static int __init sensors_w83627hf_init(void)
{
int err;
unsigned short address;
struct w83627hf_sio_data sio_data;
if (w83627hf_find(0x2e, &address, &sio_data)
&& w83627hf_find(0x4e, &address, &sio_data))
return -ENODEV;
err = platform_driver_register(&w83627hf_driver);
if (err)
goto exit;
err = w83627hf_device_add(address, &sio_data);
if (err)
goto exit_driver;
return 0;
exit_driver:
platform_driver_unregister(&w83627hf_driver);
exit:
return err;
}
static void __exit sensors_w83627hf_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&w83627hf_driver);
}
