static inline void
superio_outb(int ioreg, int reg, int val)
{
outb(reg, ioreg);
outb(val, ioreg + 1);
}
static inline int
superio_inb(int ioreg, int reg)
{
outb(reg, ioreg);
return inb(ioreg + 1);
}
static inline void
superio_select(int ioreg, int ld)
{
outb(SIO_REG_LDSEL, ioreg);
outb(ld, ioreg + 1);
}
static inline void
superio_enter(int ioreg)
{
outb(0x87, ioreg);
outb(0x87, ioreg);
}
static inline void
superio_exit(int ioreg)
{
outb(0xaa, ioreg);
outb(0x02, ioreg);
outb(0x02, ioreg + 1);
}
static int is_word_sized(u16 reg)
{
return ((((reg & 0xff00) == 0x100
|| (reg & 0xff00) == 0x200)
&& ((reg & 0x00ff) == 0x50
|| (reg & 0x00ff) == 0x53
|| (reg & 0x00ff) == 0x55))
|| (reg & 0xfff0) == 0x630
|| reg == 0x640 || reg == 0x642
|| ((reg & 0xfff0) == 0x650
&& (reg & 0x000f) >= 0x06)
|| reg == 0x73 || reg == 0x75 || reg == 0x77
);
}
static inline unsigned int step_time_from_reg(u8 reg, u8 mode)
{
return mode ? 100 * reg : 400 * reg;
}
static inline u8 step_time_to_reg(unsigned int msec, u8 mode)
{
return SENSORS_LIMIT((mode ? (msec + 50) / 100 :
(msec + 200) / 400), 1, 255);
}
static unsigned int fan_from_reg8(u16 reg, unsigned int divreg)
{
if (reg == 0 || reg == 255)
return 0;
return 1350000U / (reg << divreg);
}
static unsigned int fan_from_reg13(u16 reg, unsigned int divreg)
{
if ((reg & 0xff1f) == 0xff1f)
return 0;
reg = (reg & 0x1f) | ((reg & 0xff00) >> 3);
if (reg == 0)
return 0;
return 1350000U / reg;
}
static unsigned int fan_from_reg16(u16 reg, unsigned int divreg)
{
if (reg == 0 || reg == 0xffff)
return 0;
return 1350000U / (reg << divreg);
}
static inline unsigned int
div_from_reg(u8 reg)
{
return 1 << reg;
}
static inline long in_from_reg(u8 reg, u8 nr, const u16 *scale_in)
{
return DIV_ROUND_CLOSEST(reg * scale_in[nr], 100);
}
static inline u8 in_to_reg(u32 val, u8 nr, const u16 *scale_in)
{
return SENSORS_LIMIT(DIV_ROUND_CLOSEST(val * 100, scale_in[nr]), 0,
255);
}
static inline void w83627ehf_set_bank(struct w83627ehf_data *data, u16 reg)
{
u8 bank = reg >> 8;
if (data->bank != bank) {
outb_p(W83627EHF_REG_BANK, data->addr + ADDR_REG_OFFSET);
outb_p(bank, data->addr + DATA_REG_OFFSET);
data->bank = bank;
}
}
static u16 w83627ehf_read_value(struct w83627ehf_data *data, u16 reg)
{
int res, word_sized = is_word_sized(reg);
mutex_lock(&data->lock);
w83627ehf_set_bank(data, reg);
outb_p(reg & 0xff, data->addr + ADDR_REG_OFFSET);
res = inb_p(data->addr + DATA_REG_OFFSET);
if (word_sized) {
outb_p((reg & 0xff) + 1,
data->addr + ADDR_REG_OFFSET);
res = (res << 8) + inb_p(data->addr + DATA_REG_OFFSET);
}
mutex_unlock(&data->lock);
return res;
}
static int w83627ehf_write_value(struct w83627ehf_data *data, u16 reg,
u16 value)
{
int word_sized = is_word_sized(reg);
mutex_lock(&data->lock);
w83627ehf_set_bank(data, reg);
outb_p(reg & 0xff, data->addr + ADDR_REG_OFFSET);
if (word_sized) {
outb_p(value >> 8, data->addr + DATA_REG_OFFSET);
outb_p((reg & 0xff) + 1,
data->addr + ADDR_REG_OFFSET);
}
outb_p(value & 0xff, data->addr + DATA_REG_OFFSET);
mutex_unlock(&data->lock);
return 0;
}
static u16 w83627ehf_read_temp(struct w83627ehf_data *data, u16 reg)
{
u16 res;
res = w83627ehf_read_value(data, reg);
if (!is_word_sized(reg))
res <<= 8;
return res;
}
static int w83627ehf_write_temp(struct w83627ehf_data *data, u16 reg,
u16 value)
{
if (!is_word_sized(reg))
value >>= 8;
return w83627ehf_write_value(data, reg, value);
}
static void nct6775_write_fan_div(struct w83627ehf_data *data, int nr)
{
u8 reg;
switch (nr) {
case 0:
reg = (w83627ehf_read_value(data, NCT6775_REG_FANDIV1) & 0x70)
| (data->fan_div[0] & 0x7);
w83627ehf_write_value(data, NCT6775_REG_FANDIV1, reg);
break;
case 1:
reg = (w83627ehf_read_value(data, NCT6775_REG_FANDIV1) & 0x7)
| ((data->fan_div[1] << 4) & 0x70);
w83627ehf_write_value(data, NCT6775_REG_FANDIV1, reg);
case 2:
reg = (w83627ehf_read_value(data, NCT6775_REG_FANDIV2) & 0x70)
| (data->fan_div[2] & 0x7);
w83627ehf_write_value(data, NCT6775_REG_FANDIV2, reg);
break;
case 3:
reg = (w83627ehf_read_value(data, NCT6775_REG_FANDIV2) & 0x7)
| ((data->fan_div[3] << 4) & 0x70);
w83627ehf_write_value(data, NCT6775_REG_FANDIV2, reg);
break;
}
}
static void w83627ehf_write_fan_div(struct w83627ehf_data *data, int nr)
{
u8 reg;
switch (nr) {
case 0:
reg = (w83627ehf_read_value(data, W83627EHF_REG_FANDIV1) & 0xcf)
| ((data->fan_div[0] & 0x03) << 4);
reg |= (data->has_fan & (1 << 4)) ? 1 : 0;
w83627ehf_write_value(data, W83627EHF_REG_FANDIV1, reg);
reg = (w83627ehf_read_value(data, W83627EHF_REG_VBAT) & 0xdf)
| ((data->fan_div[0] & 0x04) << 3);
w83627ehf_write_value(data, W83627EHF_REG_VBAT, reg);
break;
case 1:
reg = (w83627ehf_read_value(data, W83627EHF_REG_FANDIV1) & 0x3f)
| ((data->fan_div[1] & 0x03) << 6);
reg |= (data->has_fan & (1 << 4)) ? 1 : 0;
w83627ehf_write_value(data, W83627EHF_REG_FANDIV1, reg);
reg = (w83627ehf_read_value(data, W83627EHF_REG_VBAT) & 0xbf)
| ((data->fan_div[1] & 0x04) << 4);
w83627ehf_write_value(data, W83627EHF_REG_VBAT, reg);
break;
case 2:
reg = (w83627ehf_read_value(data, W83627EHF_REG_FANDIV2) & 0x3f)
| ((data->fan_div[2] & 0x03) << 6);
w83627ehf_write_value(data, W83627EHF_REG_FANDIV2, reg);
reg = (w83627ehf_read_value(data, W83627EHF_REG_VBAT) & 0x7f)
| ((data->fan_div[2] & 0x04) << 5);
w83627ehf_write_value(data, W83627EHF_REG_VBAT, reg);
break;
case 3:
reg = (w83627ehf_read_value(data, W83627EHF_REG_DIODE) & 0xfc)
| (data->fan_div[3] & 0x03);
w83627ehf_write_value(data, W83627EHF_REG_DIODE, reg);
reg = (w83627ehf_read_value(data, W83627EHF_REG_SMI_OVT) & 0x7f)
| ((data->fan_div[3] & 0x04) << 5);
w83627ehf_write_value(data, W83627EHF_REG_SMI_OVT, reg);
break;
case 4:
reg = (w83627ehf_read_value(data, W83627EHF_REG_DIODE) & 0x73)
| ((data->fan_div[4] & 0x03) << 2)
| ((data->fan_div[4] & 0x04) << 5);
w83627ehf_write_value(data, W83627EHF_REG_DIODE, reg);
break;
}
}
static void w83627ehf_write_fan_div_common(struct device *dev,
struct w83627ehf_data *data, int nr)
{
struct w83627ehf_sio_data *sio_data = dev->platform_data;
if (sio_data->kind == nct6776)
;
else if (sio_data->kind == nct6775)
nct6775_write_fan_div(data, nr);
else
w83627ehf_write_fan_div(data, nr);
}
static void nct6775_update_fan_div(struct w83627ehf_data *data)
{
u8 i;
i = w83627ehf_read_value(data, NCT6775_REG_FANDIV1);
data->fan_div[0] = i & 0x7;
data->fan_div[1] = (i & 0x70) >> 4;
i = w83627ehf_read_value(data, NCT6775_REG_FANDIV2);
data->fan_div[2] = i & 0x7;
if (data->has_fan & (1<<3))
data->fan_div[3] = (i & 0x70) >> 4;
}
static void w83627ehf_update_fan_div(struct w83627ehf_data *data)
{
int i;
i = w83627ehf_read_value(data, W83627EHF_REG_FANDIV1);
data->fan_div[0] = (i >> 4) & 0x03;
data->fan_div[1] = (i >> 6) & 0x03;
i = w83627ehf_read_value(data, W83627EHF_REG_FANDIV2);
data->fan_div[2] = (i >> 6) & 0x03;
i = w83627ehf_read_value(data, W83627EHF_REG_VBAT);
data->fan_div[0] |= (i >> 3) & 0x04;
data->fan_div[1] |= (i >> 4) & 0x04;
data->fan_div[2] |= (i >> 5) & 0x04;
if (data->has_fan & ((1 << 3) | (1 << 4))) {
i = w83627ehf_read_value(data, W83627EHF_REG_DIODE);
data->fan_div[3] = i & 0x03;
data->fan_div[4] = ((i >> 2) & 0x03)
| ((i >> 5) & 0x04);
}
if (data->has_fan & (1 << 3)) {
i = w83627ehf_read_value(data, W83627EHF_REG_SMI_OVT);
data->fan_div[3] |= (i >> 5) & 0x04;
}
}
static void w83627ehf_update_fan_div_common(struct device *dev,
struct w83627ehf_data *data)
{
struct w83627ehf_sio_data *sio_data = dev->platform_data;
if (sio_data->kind == nct6776)
;
else if (sio_data->kind == nct6775)
nct6775_update_fan_div(data);
else
w83627ehf_update_fan_div(data);
}
static void nct6775_update_pwm(struct w83627ehf_data *data)
{
int i;
int pwmcfg, fanmodecfg;
for (i = 0; i < data->pwm_num; i++) {
pwmcfg = w83627ehf_read_value(data,
W83627EHF_REG_PWM_ENABLE[i]);
fanmodecfg = w83627ehf_read_value(data,
NCT6775_REG_FAN_MODE[i]);
data->pwm_mode[i] =
((pwmcfg >> W83627EHF_PWM_MODE_SHIFT[i]) & 1) ? 0 : 1;
data->pwm_enable[i] = ((fanmodecfg >> 4) & 7) + 1;
data->tolerance[i] = fanmodecfg & 0x0f;
data->pwm[i] = w83627ehf_read_value(data, data->REG_PWM[i]);
}
}
static void w83627ehf_update_pwm(struct w83627ehf_data *data)
{
int i;
int pwmcfg = 0, tolerance = 0;
for (i = 0; i < data->pwm_num; i++) {
if (!(data->has_fan & (1 << i)))
continue;
if (i != 1) {
pwmcfg = w83627ehf_read_value(data,
W83627EHF_REG_PWM_ENABLE[i]);
tolerance = w83627ehf_read_value(data,
W83627EHF_REG_TOLERANCE[i]);
}
data->pwm_mode[i] =
((pwmcfg >> W83627EHF_PWM_MODE_SHIFT[i]) & 1) ? 0 : 1;
data->pwm_enable[i] = ((pwmcfg >> W83627EHF_PWM_ENABLE_SHIFT[i])
& 3) + 1;
data->pwm[i] = w83627ehf_read_value(data, data->REG_PWM[i]);
data->tolerance[i] = (tolerance >> (i == 1 ? 4 : 0)) & 0x0f;
}
}
static void w83627ehf_update_pwm_common(struct device *dev,
struct w83627ehf_data *data)
{
struct w83627ehf_sio_data *sio_data = dev->platform_data;
if (sio_data->kind == nct6775 || sio_data->kind == nct6776)
nct6775_update_pwm(data);
else
w83627ehf_update_pwm(data);
}
static struct w83627ehf_data *w83627ehf_update_device(struct device *dev)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
struct w83627ehf_sio_data *sio_data = dev->platform_data;
int i;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ/2)
|| !data->valid) {
w83627ehf_update_fan_div_common(dev, data);
for (i = 0; i < data->in_num; i++) {
if ((i == 6) && data->in6_skip)
continue;
data->in[i] = w83627ehf_read_value(data,
W83627EHF_REG_IN(i));
data->in_min[i] = w83627ehf_read_value(data,
W83627EHF_REG_IN_MIN(i));
data->in_max[i] = w83627ehf_read_value(data,
W83627EHF_REG_IN_MAX(i));
}
for (i = 0; i < 5; i++) {
u16 reg;
if (!(data->has_fan & (1 << i)))
continue;
reg = w83627ehf_read_value(data, data->REG_FAN[i]);
data->rpm[i] = data->fan_from_reg(reg,
data->fan_div[i]);
if (data->has_fan_min & (1 << i))
data->fan_min[i] = w83627ehf_read_value(data,
data->REG_FAN_MIN[i]);
if (data->has_fan_div
&& (reg >= 0xff || (sio_data->kind == nct6775
&& reg == 0x00))
&& data->fan_div[i] < 0x07) {
dev_dbg(dev, "Increasing fan%d "
"clock divider from %u to %u\n",
i + 1, div_from_reg(data->fan_div[i]),
div_from_reg(data->fan_div[i] + 1));
data->fan_div[i]++;
w83627ehf_write_fan_div_common(dev, data, i);
if ((data->has_fan_min & (1 << i))
&& data->fan_min[i] >= 2
&& data->fan_min[i] != 255)
w83627ehf_write_value(data,
data->REG_FAN_MIN[i],
(data->fan_min[i] /= 2));
}
}
w83627ehf_update_pwm_common(dev, data);
for (i = 0; i < data->pwm_num; i++) {
if (!(data->has_fan & (1 << i)))
continue;
data->fan_start_output[i] =
w83627ehf_read_value(data,
data->REG_FAN_START_OUTPUT[i]);
data->fan_stop_output[i] =
w83627ehf_read_value(data,
data->REG_FAN_STOP_OUTPUT[i]);
data->fan_stop_time[i] =
w83627ehf_read_value(data,
data->REG_FAN_STOP_TIME[i]);
if (data->REG_FAN_MAX_OUTPUT &&
data->REG_FAN_MAX_OUTPUT[i] != 0xff)
data->fan_max_output[i] =
w83627ehf_read_value(data,
data->REG_FAN_MAX_OUTPUT[i]);
if (data->REG_FAN_STEP_OUTPUT &&
data->REG_FAN_STEP_OUTPUT[i] != 0xff)
data->fan_step_output[i] =
w83627ehf_read_value(data,
data->REG_FAN_STEP_OUTPUT[i]);
data->target_temp[i] =
w83627ehf_read_value(data,
data->REG_TARGET[i]) &
(data->pwm_mode[i] == 1 ? 0x7f : 0xff);
}
for (i = 0; i < NUM_REG_TEMP; i++) {
if (!(data->have_temp & (1 << i)))
continue;
data->temp[i] = w83627ehf_read_temp(data,
data->reg_temp[i]);
if (data->reg_temp_over[i])
data->temp_max[i]
= w83627ehf_read_temp(data,
data->reg_temp_over[i]);
if (data->reg_temp_hyst[i])
data->temp_max_hyst[i]
= w83627ehf_read_temp(data,
data->reg_temp_hyst[i]);
}
data->alarms = w83627ehf_read_value(data,
W83627EHF_REG_ALARM1) |
(w83627ehf_read_value(data,
W83627EHF_REG_ALARM2) << 8) |
(w83627ehf_read_value(data,
W83627EHF_REG_ALARM3) << 16);
data->caseopen = w83627ehf_read_value(data,
W83627EHF_REG_CASEOPEN_DET);
data->last_updated = jiffies;
data->valid = 1;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t show_alarm(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83627ehf_data *data = w83627ehf_update_device(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
return sprintf(buf, "%u\n", (data->alarms >> nr) & 0x01);
}
static ssize_t
show_fan(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627ehf_data *data = w83627ehf_update_device(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n", data->rpm[nr]);
}
static ssize_t
show_fan_min(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627ehf_data *data = w83627ehf_update_device(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n",
data->fan_from_reg_min(data->fan_min[nr],
data->fan_div[nr]));
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83627ehf_data *data = w83627ehf_update_device(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
return sprintf(buf, "%u\n", div_from_reg(data->fan_div[nr]));
}
static ssize_t
store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
unsigned long val;
int err;
unsigned int reg;
u8 new_div;
err = strict_strtoul(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
if (!data->has_fan_div) {
if (!val) {
val = 0xff1f;
} else {
if (val > 1350000U)
val = 135000U;
val = 1350000U / val;
val = (val & 0x1f) | ((val << 3) & 0xff00);
}
data->fan_min[nr] = val;
goto done;
}
if (!val) {
data->fan_min[nr] = 255;
new_div = data->fan_div[nr];
dev_info(dev, "fan%u low limit and alarm disabled\n", nr + 1);
} else if ((reg = 1350000U / val) >= 128 * 255) {
data->fan_min[nr] = 254;
new_div = 7;
dev_warn(dev, "fan%u low limit %lu below minimum %u, set to "
"minimum\n", nr + 1, val,
data->fan_from_reg_min(254, 7));
} else if (!reg) {
data->fan_min[nr] = 1;
new_div = 0;
dev_warn(dev, "fan%u low limit %lu above maximum %u, set to "
"maximum\n", nr + 1, val,
data->fan_from_reg_min(1, 0));
} else {
new_div = 0;
while (reg > 192 && new_div < 7) {
reg >>= 1;
new_div++;
}
data->fan_min[nr] = reg;
}
if (new_div != data->fan_div[nr]) {
dev_dbg(dev, "fan%u clock divider changed from %u to %u\n",
nr + 1, div_from_reg(data->fan_div[nr]),
div_from_reg(new_div));
data->fan_div[nr] = new_div;
w83627ehf_write_fan_div_common(dev, data, nr);
data->last_updated = jiffies;
}
done:
w83627ehf_write_value(data, data->REG_FAN_MIN[nr],
data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp_label(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627ehf_data *data = w83627ehf_update_device(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
return sprintf(buf, "%s\n", data->temp_label[data->temp_src[nr]]);
}
static ssize_t
show_temp_type(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627ehf_data *data = w83627ehf_update_device(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
return sprintf(buf, "%d\n", (int)data->temp_type[nr]);
}
static ssize_t
store_pwm_mode(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
unsigned long val;
int err;
u16 reg;
err = strict_strtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
reg = w83627ehf_read_value(data, W83627EHF_REG_PWM_ENABLE[nr]);
data->pwm_mode[nr] = val;
reg &= ~(1 << W83627EHF_PWM_MODE_SHIFT[nr]);
if (!val)
reg |= 1 << W83627EHF_PWM_MODE_SHIFT[nr];
w83627ehf_write_value(data, W83627EHF_REG_PWM_ENABLE[nr], reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
unsigned long val;
int err;
err = strict_strtoul(buf, 10, &val);
if (err < 0)
return err;
val = SENSORS_LIMIT(val, 0, 255);
mutex_lock(&data->update_lock);
data->pwm[nr] = val;
w83627ehf_write_value(data, data->REG_PWM[nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_pwm_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
struct w83627ehf_sio_data *sio_data = dev->platform_data;
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
unsigned long val;
int err;
u16 reg;
err = strict_strtoul(buf, 10, &val);
if (err < 0)
return err;
if (!val || (val > 4 && val != data->pwm_enable_orig[nr]))
return -EINVAL;
if (sio_data->kind == nct6776 && val == 4)
return -EINVAL;
mutex_lock(&data->update_lock);
data->pwm_enable[nr] = val;
if (sio_data->kind == nct6775 || sio_data->kind == nct6776) {
reg = w83627ehf_read_value(data,
NCT6775_REG_FAN_MODE[nr]);
reg &= 0x0f;
reg |= (val - 1) << 4;
w83627ehf_write_value(data,
NCT6775_REG_FAN_MODE[nr], reg);
} else {
reg = w83627ehf_read_value(data, W83627EHF_REG_PWM_ENABLE[nr]);
reg &= ~(0x03 << W83627EHF_PWM_ENABLE_SHIFT[nr]);
reg |= (val - 1) << W83627EHF_PWM_ENABLE_SHIFT[nr];
w83627ehf_write_value(data, W83627EHF_REG_PWM_ENABLE[nr], reg);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_target_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
long val;
int err;
err = strict_strtol(buf, 10, &val);
if (err < 0)
return err;
val = SENSORS_LIMIT(DIV_ROUND_CLOSEST(val, 1000), 0, 127);
mutex_lock(&data->update_lock);
data->target_temp[nr] = val;
w83627ehf_write_value(data, data->REG_TARGET[nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
store_tolerance(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
struct w83627ehf_sio_data *sio_data = dev->platform_data;
struct sensor_device_attribute *sensor_attr = to_sensor_dev_attr(attr);
int nr = sensor_attr->index;
u16 reg;
long val;
int err;
err = strict_strtol(buf, 10, &val);
if (err < 0)
return err;
val = SENSORS_LIMIT(DIV_ROUND_CLOSEST(val, 1000), 0, 15);
mutex_lock(&data->update_lock);
if (sio_data->kind == nct6775 || sio_data->kind == nct6776) {
if (sio_data->kind == nct6776 && val > 7)
val = 7;
reg = w83627ehf_read_value(data, NCT6775_REG_FAN_MODE[nr]);
reg = (reg & 0xf0) | val;
w83627ehf_write_value(data, NCT6775_REG_FAN_MODE[nr], reg);
} else {
reg = w83627ehf_read_value(data, W83627EHF_REG_TOLERANCE[nr]);
if (nr == 1)
reg = (reg & 0x0f) | (val << 4);
else
reg = (reg & 0xf0) | val;
w83627ehf_write_value(data, W83627EHF_REG_TOLERANCE[nr], reg);
}
data->tolerance[nr] = val;
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t show_name(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static ssize_t
show_vid(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t
show_caseopen(struct device *dev, struct device_attribute *attr, char *buf)
{
struct w83627ehf_data *data = w83627ehf_update_device(dev);
return sprintf(buf, "%d\n",
!!(data->caseopen & to_sensor_dev_attr_2(attr)->index));
}
static ssize_t
clear_caseopen(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct w83627ehf_data *data = dev_get_drvdata(dev);
unsigned long val;
u16 reg, mask;
if (strict_strtoul(buf, 10, &val) || val != 0)
return -EINVAL;
mask = to_sensor_dev_attr_2(attr)->nr;
mutex_lock(&data->update_lock);
reg = w83627ehf_read_value(data, W83627EHF_REG_CASEOPEN_CLR);
w83627ehf_write_value(data, W83627EHF_REG_CASEOPEN_CLR, reg | mask);
w83627ehf_write_value(data, W83627EHF_REG_CASEOPEN_CLR, reg & ~mask);
data->valid = 0;
mutex_unlock(&data->update_lock);
return count;
}
static void w83627ehf_device_remove_files(struct device *dev)
{
int i;
struct w83627ehf_data *data = dev_get_drvdata(dev);
for (i = 0; i < ARRAY_SIZE(sda_sf3_arrays); i++)
device_remove_file(dev, &sda_sf3_arrays[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(sda_sf3_max_step_arrays); i++) {
struct sensor_device_attribute *attr =
&sda_sf3_max_step_arrays[i];
if (data->REG_FAN_STEP_OUTPUT &&
data->REG_FAN_STEP_OUTPUT[attr->index] != 0xff)
device_remove_file(dev, &attr->dev_attr);
}
for (i = 0; i < ARRAY_SIZE(sda_sf3_arrays_fan3); i++)
device_remove_file(dev, &sda_sf3_arrays_fan3[i].dev_attr);
for (i = 0; i < ARRAY_SIZE(sda_sf3_arrays_fan4); i++)
device_remove_file(dev, &sda_sf3_arrays_fan4[i].dev_attr);
for (i = 0; i < data->in_num; i++) {
if ((i == 6) && data->in6_skip)
continue;
device_remove_file(dev, &sda_in_input[i].dev_attr);
device_remove_file(dev, &sda_in_alarm[i].dev_attr);
device_remove_file(dev, &sda_in_min[i].dev_attr);
device_remove_file(dev, &sda_in_max[i].dev_attr);
}
for (i = 0; i < 5; i++) {
device_remove_file(dev, &sda_fan_input[i].dev_attr);
device_remove_file(dev, &sda_fan_alarm[i].dev_attr);
device_remove_file(dev, &sda_fan_div[i].dev_attr);
device_remove_file(dev, &sda_fan_min[i].dev_attr);
}
for (i = 0; i < data->pwm_num; i++) {
device_remove_file(dev, &sda_pwm[i].dev_attr);
device_remove_file(dev, &sda_pwm_mode[i].dev_attr);
device_remove_file(dev, &sda_pwm_enable[i].dev_attr);
device_remove_file(dev, &sda_target_temp[i].dev_attr);
device_remove_file(dev, &sda_tolerance[i].dev_attr);
}
for (i = 0; i < NUM_REG_TEMP; i++) {
if (!(data->have_temp & (1 << i)))
continue;
device_remove_file(dev, &sda_temp_input[i].dev_attr);
device_remove_file(dev, &sda_temp_label[i].dev_attr);
if (i == 2 && data->temp3_val_only)
continue;
device_remove_file(dev, &sda_temp_max[i].dev_attr);
device_remove_file(dev, &sda_temp_max_hyst[i].dev_attr);
if (i > 2)
continue;
device_remove_file(dev, &sda_temp_alarm[i].dev_attr);
device_remove_file(dev, &sda_temp_type[i].dev_attr);
}
device_remove_file(dev, &sda_caseopen[0].dev_attr);
device_remove_file(dev, &sda_caseopen[1].dev_attr);
device_remove_file(dev, &dev_attr_name);
device_remove_file(dev, &dev_attr_cpu0_vid);
}
static inline void __devinit w83627ehf_init_device(struct w83627ehf_data *data,
enum kinds kind)
{
int i;
u8 tmp, diode;
tmp = w83627ehf_read_value(data, W83627EHF_REG_CONFIG);
if (!(tmp & 0x01))
w83627ehf_write_value(data, W83627EHF_REG_CONFIG,
tmp | 0x01);
for (i = 0; i < NUM_REG_TEMP; i++) {
if (!(data->have_temp & (1 << i)))
continue;
if (!data->reg_temp_config[i])
continue;
tmp = w83627ehf_read_value(data,
data->reg_temp_config[i]);
if (tmp & 0x01)
w83627ehf_write_value(data,
data->reg_temp_config[i],
tmp & 0xfe);
}
tmp = w83627ehf_read_value(data, W83627EHF_REG_VBAT);
if (!(tmp & 0x01))
w83627ehf_write_value(data, W83627EHF_REG_VBAT, tmp | 0x01);
switch (kind) {
case w83627ehf:
diode = w83627ehf_read_value(data, W83627EHF_REG_DIODE);
break;
case w83627uhg:
diode = 0x00;
break;
default:
diode = 0x70;
}
for (i = 0; i < 3; i++) {
const char *label = NULL;
if (data->temp_label)
label = data->temp_label[data->temp_src[i]];
if (label && strncmp(label, "PECI", 4) == 0)
data->temp_type[i] = 6;
else if (label && strncmp(label, "AMD", 3) == 0)
data->temp_type[i] = 5;
else if ((tmp & (0x02 << i)))
data->temp_type[i] = (diode & (0x10 << i)) ? 1 : 3;
else
data->temp_type[i] = 4;
}
}
static void w82627ehf_swap_tempreg(struct w83627ehf_data *data,
int r1, int r2)
{
u16 tmp;
tmp = data->temp_src[r1];
data->temp_src[r1] = data->temp_src[r2];
data->temp_src[r2] = tmp;
tmp = data->reg_temp[r1];
data->reg_temp[r1] = data->reg_temp[r2];
data->reg_temp[r2] = tmp;
tmp = data->reg_temp_over[r1];
data->reg_temp_over[r1] = data->reg_temp_over[r2];
data->reg_temp_over[r2] = tmp;
tmp = data->reg_temp_hyst[r1];
data->reg_temp_hyst[r1] = data->reg_temp_hyst[r2];
data->reg_temp_hyst[r2] = tmp;
tmp = data->reg_temp_config[r1];
data->reg_temp_config[r1] = data->reg_temp_config[r2];
data->reg_temp_config[r2] = tmp;
}
static void __devinit
w83627ehf_set_temp_reg_ehf(struct w83627ehf_data *data, int n_temp)
{
int i;
for (i = 0; i < n_temp; i++) {
data->reg_temp[i] = W83627EHF_REG_TEMP[i];
data->reg_temp_over[i] = W83627EHF_REG_TEMP_OVER[i];
data->reg_temp_hyst[i] = W83627EHF_REG_TEMP_HYST[i];
data->reg_temp_config[i] = W83627EHF_REG_TEMP_CONFIG[i];
}
}
static void __devinit
w83627ehf_check_fan_inputs(const struct w83627ehf_sio_data *sio_data,
struct w83627ehf_data *data)
{
int fan3pin, fan4pin, fan4min, fan5pin, regval;
if (sio_data->kind == w83627uhg) {
data->has_fan = 0x03;
data->has_fan_min = 0x03;
return;
}
superio_enter(sio_data->sioreg);
if (sio_data->kind == nct6775) {
fan3pin = 1;
fan4pin = !(superio_inb(sio_data->sioreg, 0x2A) & 0x80);
fan4min = 0;
fan5pin = 0;
} else if (sio_data->kind == nct6776) {
fan3pin = !(superio_inb(sio_data->sioreg, 0x24) & 0x40);
fan4pin = !!(superio_inb(sio_data->sioreg, 0x1C) & 0x01);
fan5pin = !!(superio_inb(sio_data->sioreg, 0x1C) & 0x02);
fan4min = fan4pin;
} else if (sio_data->kind == w83667hg || sio_data->kind == w83667hg_b) {
fan3pin = 1;
fan4pin = superio_inb(sio_data->sioreg, 0x27) & 0x40;
fan5pin = superio_inb(sio_data->sioreg, 0x27) & 0x20;
fan4min = fan4pin;
} else {
fan3pin = 1;
fan4pin = !(superio_inb(sio_data->sioreg, 0x29) & 0x06);
fan5pin = !(superio_inb(sio_data->sioreg, 0x24) & 0x02);
fan4min = fan4pin;
}
superio_exit(sio_data->sioreg);
data->has_fan = data->has_fan_min = 0x03;
data->has_fan |= (fan3pin << 2);
data->has_fan_min |= (fan3pin << 2);
if (sio_data->kind == nct6775 || sio_data->kind == nct6776) {
data->has_fan |= (fan4pin << 3) | (fan5pin << 4);
data->has_fan_min |= (fan4min << 3) | (fan5pin << 4);
} else {
regval = w83627ehf_read_value(data, W83627EHF_REG_FANDIV1);
if ((regval & (1 << 2)) && fan4pin) {
data->has_fan |= (1 << 3);
data->has_fan_min |= (1 << 3);
}
if (!(regval & (1 << 1)) && fan5pin) {
data->has_fan |= (1 << 4);
data->has_fan_min |= (1 << 4);
}
}
}
static int __devinit w83627ehf_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct w83627ehf_sio_data *sio_data = dev->platform_data;
struct w83627ehf_data *data;
struct resource *res;
u8 en_vrm10;
int i, err = 0;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!request_region(res->start, IOREGION_LENGTH, DRVNAME)) {
err = -EBUSY;
dev_err(dev, "Failed to request region 0x%lx-0x%lx\n",
(unsigned long)res->start,
(unsigned long)res->start + IOREGION_LENGTH - 1);
goto exit;
}
data = kzalloc(sizeof(struct w83627ehf_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
goto exit_release;
}
data->addr = res->start;
mutex_init(&data->lock);
mutex_init(&data->update_lock);
data->name = w83627ehf_device_names[sio_data->kind];
platform_set_drvdata(pdev, data);
data->in_num = (sio_data->kind == w83627ehf) ? 10 : 9;
switch (sio_data->kind) {
default:
data->pwm_num = 4;
break;
case w83667hg:
case w83667hg_b:
case nct6775:
case nct6776:
data->pwm_num = 3;
break;
case w83627uhg:
data->pwm_num = 2;
break;
}
data->have_temp = 0x07;
if (sio_data->kind == nct6775 || sio_data->kind == nct6776) {
int mask = 0;
for (i = 0; i < NUM_REG_TEMP; i++) {
u8 src;
data->reg_temp[i] = NCT6775_REG_TEMP[i];
data->reg_temp_over[i] = NCT6775_REG_TEMP_OVER[i];
data->reg_temp_hyst[i] = NCT6775_REG_TEMP_HYST[i];
data->reg_temp_config[i] = NCT6775_REG_TEMP_CONFIG[i];
src = w83627ehf_read_value(data,
NCT6775_REG_TEMP_SOURCE[i]);
src &= 0x1f;
if (src && !(mask & (1 << src))) {
data->have_temp |= 1 << i;
mask |= 1 << src;
}
data->temp_src[i] = src;
if (i > 0 && data->temp_src[0] != 1
&& data->temp_src[i] == 1)
w82627ehf_swap_tempreg(data, 0, i);
if (i > 1 && data->temp_src[1] != 2
&& data->temp_src[i] == 2)
w82627ehf_swap_tempreg(data, 1, i);
if (i > 2 && data->temp_src[2] != 3
&& data->temp_src[i] == 3)
w82627ehf_swap_tempreg(data, 2, i);
}
if (sio_data->kind == nct6776) {
if (data->temp_src[2] == 3) {
u8 reg;
if (data->reg_temp_config[2])
reg = w83627ehf_read_value(data,
data->reg_temp_config[2]);
else
reg = 0;
if (reg & 0x01)
data->have_temp &= ~(1 << 2);
else
data->in6_skip = 1;
}
data->temp_label = nct6776_temp_label;
} else {
data->temp_label = nct6775_temp_label;
}
} else if (sio_data->kind == w83667hg_b) {
u8 reg;
w83627ehf_set_temp_reg_ehf(data, 4);
reg = w83627ehf_read_value(data, 0x4a);
data->temp_src[0] = reg >> 5;
reg = w83627ehf_read_value(data, 0x49);
data->temp_src[1] = reg & 0x07;
data->temp_src[2] = (reg >> 4) & 0x07;
reg = w83627ehf_read_value(data, 0x7d);
reg &= 0x07;
if (reg != data->temp_src[0] && reg != data->temp_src[1]
&& reg != data->temp_src[2]) {
data->temp_src[3] = reg;
data->have_temp |= 1 << 3;
}
reg = w83627ehf_read_value(data, W83627EHF_REG_TEMP_CONFIG[2]);
if (data->temp_src[2] == 2 && (reg & 0x01))
data->have_temp &= ~(1 << 2);
if ((data->temp_src[2] == 2 && (data->have_temp & (1 << 2)))
|| (data->temp_src[3] == 2 && (data->have_temp & (1 << 3))))
data->in6_skip = 1;
data->temp_label = w83667hg_b_temp_label;
} else if (sio_data->kind == w83627uhg) {
u8 reg;
w83627ehf_set_temp_reg_ehf(data, 3);
data->temp_src[0] = 0;
reg = w83627ehf_read_value(data, 0x49) & 0x07;
if (reg == 0)
data->temp_src[1]++;
else if (reg >= 2 && reg <= 5)
data->temp_src[1] += 2;
else
data->have_temp &= ~(1 << 1);
reg = w83627ehf_read_value(data, 0x4a);
data->temp_src[2] = reg >> 5;
if (data->temp_src[2] == 2 || data->temp_src[2] == 3 ||
data->temp_src[2] == data->temp_src[0] ||
((data->have_temp & (1 << 1)) &&
data->temp_src[2] == data->temp_src[1]))
data->have_temp &= ~(1 << 2);
else
data->temp3_val_only = 1;
data->in6_skip = 1;
data->temp_label = w83667hg_b_temp_label;
} else {
w83627ehf_set_temp_reg_ehf(data, 3);
if (sio_data->kind == w83667hg) {
u8 reg;
reg = w83627ehf_read_value(data,
W83627EHF_REG_TEMP_CONFIG[2]);
if (reg & 0x01)
data->have_temp &= ~(1 << 2);
else
data->in6_skip = 1;
}
}
if (sio_data->kind == nct6775) {
data->has_fan_div = true;
data->fan_from_reg = fan_from_reg16;
data->fan_from_reg_min = fan_from_reg8;
data->REG_PWM = NCT6775_REG_PWM;
data->REG_TARGET = NCT6775_REG_TARGET;
data->REG_FAN = NCT6775_REG_FAN;
data->REG_FAN_MIN = W83627EHF_REG_FAN_MIN;
data->REG_FAN_START_OUTPUT = NCT6775_REG_FAN_START_OUTPUT;
data->REG_FAN_STOP_OUTPUT = NCT6775_REG_FAN_STOP_OUTPUT;
data->REG_FAN_STOP_TIME = NCT6775_REG_FAN_STOP_TIME;
data->REG_FAN_MAX_OUTPUT = NCT6775_REG_FAN_MAX_OUTPUT;
data->REG_FAN_STEP_OUTPUT = NCT6775_REG_FAN_STEP_OUTPUT;
} else if (sio_data->kind == nct6776) {
data->has_fan_div = false;
data->fan_from_reg = fan_from_reg13;
data->fan_from_reg_min = fan_from_reg13;
data->REG_PWM = NCT6775_REG_PWM;
data->REG_TARGET = NCT6775_REG_TARGET;
data->REG_FAN = NCT6775_REG_FAN;
data->REG_FAN_MIN = NCT6776_REG_FAN_MIN;
data->REG_FAN_START_OUTPUT = NCT6775_REG_FAN_START_OUTPUT;
data->REG_FAN_STOP_OUTPUT = NCT6775_REG_FAN_STOP_OUTPUT;
data->REG_FAN_STOP_TIME = NCT6775_REG_FAN_STOP_TIME;
} else if (sio_data->kind == w83667hg_b) {
data->has_fan_div = true;
data->fan_from_reg = fan_from_reg8;
data->fan_from_reg_min = fan_from_reg8;
data->REG_PWM = W83627EHF_REG_PWM;
data->REG_TARGET = W83627EHF_REG_TARGET;
data->REG_FAN = W83627EHF_REG_FAN;
data->REG_FAN_MIN = W83627EHF_REG_FAN_MIN;
data->REG_FAN_START_OUTPUT = W83627EHF_REG_FAN_START_OUTPUT;
data->REG_FAN_STOP_OUTPUT = W83627EHF_REG_FAN_STOP_OUTPUT;
data->REG_FAN_STOP_TIME = W83627EHF_REG_FAN_STOP_TIME;
data->REG_FAN_MAX_OUTPUT =
W83627EHF_REG_FAN_MAX_OUTPUT_W83667_B;
data->REG_FAN_STEP_OUTPUT =
W83627EHF_REG_FAN_STEP_OUTPUT_W83667_B;
} else {
data->has_fan_div = true;
data->fan_from_reg = fan_from_reg8;
data->fan_from_reg_min = fan_from_reg8;
data->REG_PWM = W83627EHF_REG_PWM;
data->REG_TARGET = W83627EHF_REG_TARGET;
data->REG_FAN = W83627EHF_REG_FAN;
data->REG_FAN_MIN = W83627EHF_REG_FAN_MIN;
data->REG_FAN_START_OUTPUT = W83627EHF_REG_FAN_START_OUTPUT;
data->REG_FAN_STOP_OUTPUT = W83627EHF_REG_FAN_STOP_OUTPUT;
data->REG_FAN_STOP_TIME = W83627EHF_REG_FAN_STOP_TIME;
data->REG_FAN_MAX_OUTPUT =
W83627EHF_REG_FAN_MAX_OUTPUT_COMMON;
data->REG_FAN_STEP_OUTPUT =
W83627EHF_REG_FAN_STEP_OUTPUT_COMMON;
}
if (sio_data->kind == w83627uhg)
data->scale_in = scale_in_w83627uhg;
else
data->scale_in = scale_in_common;
w83627ehf_init_device(data, sio_data->kind);
data->vrm = vid_which_vrm();
superio_enter(sio_data->sioreg);
if (sio_data->kind == w83667hg || sio_data->kind == w83667hg_b ||
sio_data->kind == nct6775 || sio_data->kind == nct6776) {
superio_select(sio_data->sioreg, W83667HG_LD_VID);
data->vid = superio_inb(sio_data->sioreg, 0xe3);
err = device_create_file(dev, &dev_attr_cpu0_vid);
if (err)
goto exit_release;
} else if (sio_data->kind != w83627uhg) {
superio_select(sio_data->sioreg, W83627EHF_LD_HWM);
if (superio_inb(sio_data->sioreg, SIO_REG_VID_CTRL) & 0x80) {
if (sio_data->kind == w83627ehf) {
en_vrm10 = superio_inb(sio_data->sioreg,
SIO_REG_EN_VRM10);
if ((en_vrm10 & 0x08) && data->vrm == 90) {
dev_warn(dev, "Setting VID input "
"voltage to TTL\n");
superio_outb(sio_data->sioreg,
SIO_REG_EN_VRM10,
en_vrm10 & ~0x08);
} else if (!(en_vrm10 & 0x08)
&& data->vrm == 100) {
dev_warn(dev, "Setting VID input "
"voltage to VRM10\n");
superio_outb(sio_data->sioreg,
SIO_REG_EN_VRM10,
en_vrm10 | 0x08);
}
}
data->vid = superio_inb(sio_data->sioreg,
SIO_REG_VID_DATA);
if (sio_data->kind == w83627ehf)
data->vid &= 0x3f;
err = device_create_file(dev, &dev_attr_cpu0_vid);
if (err)
goto exit_release;
} else {
dev_info(dev, "VID pins in output mode, CPU VID not "
"available\n");
}
}
if (fan_debounce &&
(sio_data->kind == nct6775 || sio_data->kind == nct6776)) {
u8 tmp;
superio_select(sio_data->sioreg, W83627EHF_LD_HWM);
tmp = superio_inb(sio_data->sioreg, NCT6775_REG_FAN_DEBOUNCE);
if (sio_data->kind == nct6776)
superio_outb(sio_data->sioreg, NCT6775_REG_FAN_DEBOUNCE,
0x3e | tmp);
else
superio_outb(sio_data->sioreg, NCT6775_REG_FAN_DEBOUNCE,
0x1e | tmp);
pr_info("Enabled fan debounce for chip %s\n", data->name);
}
superio_exit(sio_data->sioreg);
w83627ehf_check_fan_inputs(sio_data, data);
w83627ehf_update_fan_div_common(dev, data);
w83627ehf_update_pwm_common(dev, data);
for (i = 0; i < data->pwm_num; i++)
data->pwm_enable_orig[i] = data->pwm_enable[i];
w83627ehf_update_pwm_common(dev, data);
for (i = 0; i < data->pwm_num; i++)
data->pwm_enable_orig[i] = data->pwm_enable[i];
for (i = 0; i < ARRAY_SIZE(sda_sf3_arrays); i++) {
err = device_create_file(dev, &sda_sf3_arrays[i].dev_attr);
if (err)
goto exit_remove;
}
for (i = 0; i < ARRAY_SIZE(sda_sf3_max_step_arrays); i++) {
struct sensor_device_attribute *attr =
&sda_sf3_max_step_arrays[i];
if (data->REG_FAN_STEP_OUTPUT &&
data->REG_FAN_STEP_OUTPUT[attr->index] != 0xff) {
err = device_create_file(dev, &attr->dev_attr);
if (err)
goto exit_remove;
}
}
if ((data->has_fan & (1 << 2)) && data->pwm_num >= 3)
for (i = 0; i < ARRAY_SIZE(sda_sf3_arrays_fan3); i++) {
err = device_create_file(dev,
&sda_sf3_arrays_fan3[i].dev_attr);
if (err)
goto exit_remove;
}
if ((data->has_fan & (1 << 3)) && data->pwm_num >= 4)
for (i = 0; i < ARRAY_SIZE(sda_sf3_arrays_fan4); i++) {
err = device_create_file(dev,
&sda_sf3_arrays_fan4[i].dev_attr);
if (err)
goto exit_remove;
}
for (i = 0; i < data->in_num; i++) {
if ((i == 6) && data->in6_skip)
continue;
if ((err = device_create_file(dev, &sda_in_input[i].dev_attr))
|| (err = device_create_file(dev,
&sda_in_alarm[i].dev_attr))
|| (err = device_create_file(dev,
&sda_in_min[i].dev_attr))
|| (err = device_create_file(dev,
&sda_in_max[i].dev_attr)))
goto exit_remove;
}
for (i = 0; i < 5; i++) {
if (data->has_fan & (1 << i)) {
if ((err = device_create_file(dev,
&sda_fan_input[i].dev_attr))
|| (err = device_create_file(dev,
&sda_fan_alarm[i].dev_attr)))
goto exit_remove;
if (sio_data->kind != nct6776) {
err = device_create_file(dev,
&sda_fan_div[i].dev_attr);
if (err)
goto exit_remove;
}
if (data->has_fan_min & (1 << i)) {
err = device_create_file(dev,
&sda_fan_min[i].dev_attr);
if (err)
goto exit_remove;
}
if (i < data->pwm_num &&
((err = device_create_file(dev,
&sda_pwm[i].dev_attr))
|| (err = device_create_file(dev,
&sda_pwm_mode[i].dev_attr))
|| (err = device_create_file(dev,
&sda_pwm_enable[i].dev_attr))
|| (err = device_create_file(dev,
&sda_target_temp[i].dev_attr))
|| (err = device_create_file(dev,
&sda_tolerance[i].dev_attr))))
goto exit_remove;
}
}
for (i = 0; i < NUM_REG_TEMP; i++) {
if (!(data->have_temp & (1 << i)))
continue;
err = device_create_file(dev, &sda_temp_input[i].dev_attr);
if (err)
goto exit_remove;
if (data->temp_label) {
err = device_create_file(dev,
&sda_temp_label[i].dev_attr);
if (err)
goto exit_remove;
}
if (i == 2 && data->temp3_val_only)
continue;
if (data->reg_temp_over[i]) {
err = device_create_file(dev,
&sda_temp_max[i].dev_attr);
if (err)
goto exit_remove;
}
if (data->reg_temp_hyst[i]) {
err = device_create_file(dev,
&sda_temp_max_hyst[i].dev_attr);
if (err)
goto exit_remove;
}
if (i > 2)
continue;
if ((err = device_create_file(dev,
&sda_temp_alarm[i].dev_attr))
|| (err = device_create_file(dev,
&sda_temp_type[i].dev_attr)))
goto exit_remove;
}
err = device_create_file(dev, &sda_caseopen[0].dev_attr);
if (err)
goto exit_remove;
if (sio_data->kind == nct6776) {
err = device_create_file(dev, &sda_caseopen[1].dev_attr);
if (err)
goto exit_remove;
}
err = device_create_file(dev, &dev_attr_name);
if (err)
goto exit_remove;
data->hwmon_dev = hwmon_device_register(dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
goto exit_remove;
}
return 0;
exit_remove:
w83627ehf_device_remove_files(dev);
kfree(data);
platform_set_drvdata(pdev, NULL);
exit_release:
release_region(res->start, IOREGION_LENGTH);
exit:
return err;
}
static int __devexit w83627ehf_remove(struct platform_device *pdev)
{
struct w83627ehf_data *data = platform_get_drvdata(pdev);
hwmon_device_unregister(data->hwmon_dev);
w83627ehf_device_remove_files(&pdev->dev);
release_region(data->addr, IOREGION_LENGTH);
platform_set_drvdata(pdev, NULL);
kfree(data);
return 0;
}
static int __init w83627ehf_find(int sioaddr, unsigned short *addr,
struct w83627ehf_sio_data *sio_data)
{
static const char __initdata sio_name_W83627EHF[] = "W83627EHF";
static const char __initdata sio_name_W83627EHG[] = "W83627EHG";
static const char __initdata sio_name_W83627DHG[] = "W83627DHG";
static const char __initdata sio_name_W83627DHG_P[] = "W83627DHG-P";
static const char __initdata sio_name_W83627UHG[] = "W83627UHG";
static const char __initdata sio_name_W83667HG[] = "W83667HG";
static const char __initdata sio_name_W83667HG_B[] = "W83667HG-B";
static const char __initdata sio_name_NCT6775[] = "NCT6775F";
static const char __initdata sio_name_NCT6776[] = "NCT6776F";
u16 val;
const char *sio_name;
superio_enter(sioaddr);
if (force_id)
val = force_id;
else
val = (superio_inb(sioaddr, SIO_REG_DEVID) << 8)
| superio_inb(sioaddr, SIO_REG_DEVID + 1);
switch (val & SIO_ID_MASK) {
case SIO_W83627EHF_ID:
sio_data->kind = w83627ehf;
sio_name = sio_name_W83627EHF;
break;
case SIO_W83627EHG_ID:
sio_data->kind = w83627ehf;
sio_name = sio_name_W83627EHG;
break;
case SIO_W83627DHG_ID:
sio_data->kind = w83627dhg;
sio_name = sio_name_W83627DHG;
break;
case SIO_W83627DHG_P_ID:
sio_data->kind = w83627dhg_p;
sio_name = sio_name_W83627DHG_P;
break;
case SIO_W83627UHG_ID:
sio_data->kind = w83627uhg;
sio_name = sio_name_W83627UHG;
break;
case SIO_W83667HG_ID:
sio_data->kind = w83667hg;
sio_name = sio_name_W83667HG;
break;
case SIO_W83667HG_B_ID:
sio_data->kind = w83667hg_b;
sio_name = sio_name_W83667HG_B;
break;
case SIO_NCT6775_ID:
sio_data->kind = nct6775;
sio_name = sio_name_NCT6775;
break;
case SIO_NCT6776_ID:
sio_data->kind = nct6776;
sio_name = sio_name_NCT6776;
break;
default:
if (val != 0xffff)
pr_debug("unsupported chip ID: 0x%04x\n", val);
superio_exit(sioaddr);
return -ENODEV;
}
superio_select(sioaddr, W83627EHF_LD_HWM);
val = (superio_inb(sioaddr, SIO_REG_ADDR) << 8)
| superio_inb(sioaddr, SIO_REG_ADDR + 1);
*addr = val & IOREGION_ALIGNMENT;
if (*addr == 0) {
pr_err("Refusing to enable a Super-I/O device with a base I/O port 0\n");
superio_exit(sioaddr);
return -ENODEV;
}
val = superio_inb(sioaddr, SIO_REG_ENABLE);
if (!(val & 0x01)) {
pr_warn("Forcibly enabling Super-I/O. "
"Sensor is probably unusable.\n");
superio_outb(sioaddr, SIO_REG_ENABLE, val | 0x01);
}
superio_exit(sioaddr);
pr_info("Found %s chip at %#x\n", sio_name, *addr);
sio_data->sioreg = sioaddr;
return 0;
}
static int __init sensors_w83627ehf_init(void)
{
int err;
unsigned short address;
struct resource res;
struct w83627ehf_sio_data sio_data;
if (w83627ehf_find(0x2e, &address, &sio_data) &&
w83627ehf_find(0x4e, &address, &sio_data))
return -ENODEV;
err = platform_driver_register(&w83627ehf_driver);
if (err)
goto exit;
pdev = platform_device_alloc(DRVNAME, address);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit_unregister;
}
err = platform_device_add_data(pdev, &sio_data,
sizeof(struct w83627ehf_sio_data));
if (err) {
pr_err("Platform data allocation failed\n");
goto exit_device_put;
}
memset(&res, 0, sizeof(res));
res.name = DRVNAME;
res.start = address + IOREGION_OFFSET;
res.end = address + IOREGION_OFFSET + IOREGION_LENGTH - 1;
res.flags = IORESOURCE_IO;
err = acpi_check_resource_conflict(&res);
if (err)
goto exit_device_put;
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
exit_unregister:
platform_driver_unregister(&w83627ehf_driver);
exit:
return err;
}
static void __exit sensors_w83627ehf_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&w83627ehf_driver);
}
