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
static inline int
superio_enter(int ioreg)
{
if (!request_muxed_region(ioreg, 2, DRVNAME))
return -EBUSY;
outb(0x87, ioreg);
outb(0x87, ioreg);
return 0;
}
static inline void
superio_exit(int ioreg)
{
outb(0xaa, ioreg);
outb(0x02, ioreg);
outb(0x02, ioreg + 1);
release_region(ioreg, 2);
}
static enum pwm_enable reg_to_pwm_enable(int pwm, int mode)
{
if (mode == 0 && pwm == 255)
return off;
return mode + 1;
}
static int pwm_enable_to_reg(enum pwm_enable mode)
{
if (mode == off)
return 0;
return mode - 1;
}
static unsigned int step_time_from_reg(u8 reg, u8 mode)
{
return mode ? 400 * reg : 100 * reg;
}
static u8 step_time_to_reg(unsigned int msec, u8 mode)
{
return clamp_val((mode ? (msec + 200) / 400 :
(msec + 50) / 100), 1, 255);
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
static u16 fan_to_reg(u32 fan, unsigned int divreg)
{
if (!fan)
return 0;
return (1350000U / fan) >> divreg;
}
static inline unsigned int
div_from_reg(u8 reg)
{
return BIT(reg);
}
static inline long in_from_reg(u8 reg, u8 nr)
{
return DIV_ROUND_CLOSEST(reg * scale_in[nr], 100);
}
static inline u8 in_to_reg(u32 val, u8 nr)
{
return clamp_val(DIV_ROUND_CLOSEST(val * 100, scale_in[nr]), 0, 255);
}
static struct attribute_group *
nct6775_create_attr_group(struct device *dev,
const struct sensor_template_group *tg,
int repeat)
{
struct attribute_group *group;
struct sensor_device_attr_u *su;
struct sensor_device_attribute *a;
struct sensor_device_attribute_2 *a2;
struct attribute **attrs;
struct sensor_device_template **t;
int i, count;
if (repeat <= 0)
return ERR_PTR(-EINVAL);
t = tg->templates;
for (count = 0; *t; t++, count++)
;
if (count == 0)
return ERR_PTR(-EINVAL);
group = devm_kzalloc(dev, sizeof(*group), GFP_KERNEL);
if (group == NULL)
return ERR_PTR(-ENOMEM);
attrs = devm_kzalloc(dev, sizeof(*attrs) * (repeat * count + 1),
GFP_KERNEL);
if (attrs == NULL)
return ERR_PTR(-ENOMEM);
su = devm_kzalloc(dev, sizeof(*su) * repeat * count,
GFP_KERNEL);
if (su == NULL)
return ERR_PTR(-ENOMEM);
group->attrs = attrs;
group->is_visible = tg->is_visible;
for (i = 0; i < repeat; i++) {
t = tg->templates;
while (*t != NULL) {
snprintf(su->name, sizeof(su->name),
(*t)->dev_attr.attr.name, tg->base + i);
if ((*t)->s2) {
a2 = &su->u.a2;
sysfs_attr_init(&a2->dev_attr.attr);
a2->dev_attr.attr.name = su->name;
a2->nr = (*t)->u.s.nr + i;
a2->index = (*t)->u.s.index;
a2->dev_attr.attr.mode =
(*t)->dev_attr.attr.mode;
a2->dev_attr.show = (*t)->dev_attr.show;
a2->dev_attr.store = (*t)->dev_attr.store;
*attrs = &a2->dev_attr.attr;
} else {
a = &su->u.a1;
sysfs_attr_init(&a->dev_attr.attr);
a->dev_attr.attr.name = su->name;
a->index = (*t)->u.index + i;
a->dev_attr.attr.mode =
(*t)->dev_attr.attr.mode;
a->dev_attr.show = (*t)->dev_attr.show;
a->dev_attr.store = (*t)->dev_attr.store;
*attrs = &a->dev_attr.attr;
}
attrs++;
su++;
t++;
}
}
return group;
}
static bool is_word_sized(struct nct6775_data *data, u16 reg)
{
switch (data->kind) {
case nct6106:
return reg == 0x20 || reg == 0x22 || reg == 0x24 ||
reg == 0xe0 || reg == 0xe2 || reg == 0xe4 ||
reg == 0x111 || reg == 0x121 || reg == 0x131;
case nct6775:
return (((reg & 0xff00) == 0x100 ||
(reg & 0xff00) == 0x200) &&
((reg & 0x00ff) == 0x50 ||
(reg & 0x00ff) == 0x53 ||
(reg & 0x00ff) == 0x55)) ||
(reg & 0xfff0) == 0x630 ||
reg == 0x640 || reg == 0x642 ||
reg == 0x662 ||
((reg & 0xfff0) == 0x650 && (reg & 0x000f) >= 0x06) ||
reg == 0x73 || reg == 0x75 || reg == 0x77;
case nct6776:
return (((reg & 0xff00) == 0x100 ||
(reg & 0xff00) == 0x200) &&
((reg & 0x00ff) == 0x50 ||
(reg & 0x00ff) == 0x53 ||
(reg & 0x00ff) == 0x55)) ||
(reg & 0xfff0) == 0x630 ||
reg == 0x402 ||
reg == 0x640 || reg == 0x642 ||
((reg & 0xfff0) == 0x650 && (reg & 0x000f) >= 0x06) ||
reg == 0x73 || reg == 0x75 || reg == 0x77;
case nct6779:
case nct6791:
case nct6792:
case nct6793:
case nct6795:
return reg == 0x150 || reg == 0x153 || reg == 0x155 ||
((reg & 0xfff0) == 0x4b0 && (reg & 0x000f) < 0x0b) ||
reg == 0x402 ||
reg == 0x63a || reg == 0x63c || reg == 0x63e ||
reg == 0x640 || reg == 0x642 ||
reg == 0x73 || reg == 0x75 || reg == 0x77 || reg == 0x79 ||
reg == 0x7b || reg == 0x7d;
}
return false;
}
static inline void nct6775_set_bank(struct nct6775_data *data, u16 reg)
{
u8 bank = reg >> 8;
if (data->bank != bank) {
outb_p(NCT6775_REG_BANK, data->addr + ADDR_REG_OFFSET);
outb_p(bank, data->addr + DATA_REG_OFFSET);
data->bank = bank;
}
}
static u16 nct6775_read_value(struct nct6775_data *data, u16 reg)
{
int res, word_sized = is_word_sized(data, reg);
nct6775_set_bank(data, reg);
outb_p(reg & 0xff, data->addr + ADDR_REG_OFFSET);
res = inb_p(data->addr + DATA_REG_OFFSET);
if (word_sized) {
outb_p((reg & 0xff) + 1,
data->addr + ADDR_REG_OFFSET);
res = (res << 8) + inb_p(data->addr + DATA_REG_OFFSET);
}
return res;
}
static int nct6775_write_value(struct nct6775_data *data, u16 reg, u16 value)
{
int word_sized = is_word_sized(data, reg);
nct6775_set_bank(data, reg);
outb_p(reg & 0xff, data->addr + ADDR_REG_OFFSET);
if (word_sized) {
outb_p(value >> 8, data->addr + DATA_REG_OFFSET);
outb_p((reg & 0xff) + 1,
data->addr + ADDR_REG_OFFSET);
}
outb_p(value & 0xff, data->addr + DATA_REG_OFFSET);
return 0;
}
static u16 nct6775_read_temp(struct nct6775_data *data, u16 reg)
{
u16 res;
res = nct6775_read_value(data, reg);
if (!is_word_sized(data, reg))
res <<= 8;
return res;
}
static int nct6775_write_temp(struct nct6775_data *data, u16 reg, u16 value)
{
if (!is_word_sized(data, reg))
value >>= 8;
return nct6775_write_value(data, reg, value);
}
static void nct6775_write_fan_div(struct nct6775_data *data, int nr)
{
u8 reg;
switch (nr) {
case 0:
reg = (nct6775_read_value(data, NCT6775_REG_FANDIV1) & 0x70)
| (data->fan_div[0] & 0x7);
nct6775_write_value(data, NCT6775_REG_FANDIV1, reg);
break;
case 1:
reg = (nct6775_read_value(data, NCT6775_REG_FANDIV1) & 0x7)
| ((data->fan_div[1] << 4) & 0x70);
nct6775_write_value(data, NCT6775_REG_FANDIV1, reg);
break;
case 2:
reg = (nct6775_read_value(data, NCT6775_REG_FANDIV2) & 0x70)
| (data->fan_div[2] & 0x7);
nct6775_write_value(data, NCT6775_REG_FANDIV2, reg);
break;
case 3:
reg = (nct6775_read_value(data, NCT6775_REG_FANDIV2) & 0x7)
| ((data->fan_div[3] << 4) & 0x70);
nct6775_write_value(data, NCT6775_REG_FANDIV2, reg);
break;
}
}
static void nct6775_write_fan_div_common(struct nct6775_data *data, int nr)
{
if (data->kind == nct6775)
nct6775_write_fan_div(data, nr);
}
static void nct6775_update_fan_div(struct nct6775_data *data)
{
u8 i;
i = nct6775_read_value(data, NCT6775_REG_FANDIV1);
data->fan_div[0] = i & 0x7;
data->fan_div[1] = (i & 0x70) >> 4;
i = nct6775_read_value(data, NCT6775_REG_FANDIV2);
data->fan_div[2] = i & 0x7;
if (data->has_fan & BIT(3))
data->fan_div[3] = (i & 0x70) >> 4;
}
static void nct6775_update_fan_div_common(struct nct6775_data *data)
{
if (data->kind == nct6775)
nct6775_update_fan_div(data);
}
static void nct6775_init_fan_div(struct nct6775_data *data)
{
int i;
nct6775_update_fan_div_common(data);
for (i = 0; i < ARRAY_SIZE(data->fan_div); i++) {
if (!(data->has_fan & BIT(i)))
continue;
if (data->fan_div[i] == 0) {
data->fan_div[i] = 7;
nct6775_write_fan_div_common(data, i);
}
}
}
static void nct6775_init_fan_common(struct device *dev,
struct nct6775_data *data)
{
int i;
u8 reg;
if (data->has_fan_div)
nct6775_init_fan_div(data);
for (i = 0; i < ARRAY_SIZE(data->fan_min); i++) {
if (data->has_fan_min & BIT(i)) {
reg = nct6775_read_value(data, data->REG_FAN_MIN[i]);
if (!reg)
nct6775_write_value(data, data->REG_FAN_MIN[i],
data->has_fan_div ? 0xff
: 0xff1f);
}
}
}
static void nct6775_select_fan_div(struct device *dev,
struct nct6775_data *data, int nr, u16 reg)
{
u8 fan_div = data->fan_div[nr];
u16 fan_min;
if (!data->has_fan_div)
return;
if (reg == 0x00 && fan_div < 0x07)
fan_div++;
else if (reg != 0x00 && reg < 0x30 && fan_div > 0)
fan_div--;
if (fan_div != data->fan_div[nr]) {
dev_dbg(dev, "Modifying fan%d clock divider from %u to %u\n",
nr + 1, div_from_reg(data->fan_div[nr]),
div_from_reg(fan_div));
if (data->has_fan_min & BIT(nr)) {
fan_min = data->fan_min[nr];
if (fan_div > data->fan_div[nr]) {
if (fan_min != 255 && fan_min > 1)
fan_min >>= 1;
} else {
if (fan_min != 255) {
fan_min <<= 1;
if (fan_min > 254)
fan_min = 254;
}
}
if (fan_min != data->fan_min[nr]) {
data->fan_min[nr] = fan_min;
nct6775_write_value(data, data->REG_FAN_MIN[nr],
fan_min);
}
}
data->fan_div[nr] = fan_div;
nct6775_write_fan_div_common(data, nr);
}
}
static void nct6775_update_pwm(struct device *dev)
{
struct nct6775_data *data = dev_get_drvdata(dev);
int i, j;
int fanmodecfg, reg;
bool duty_is_dc;
for (i = 0; i < data->pwm_num; i++) {
if (!(data->has_pwm & BIT(i)))
continue;
duty_is_dc = data->REG_PWM_MODE[i] &&
(nct6775_read_value(data, data->REG_PWM_MODE[i])
& data->PWM_MODE_MASK[i]);
data->pwm_mode[i] = duty_is_dc;
fanmodecfg = nct6775_read_value(data, data->REG_FAN_MODE[i]);
for (j = 0; j < ARRAY_SIZE(data->REG_PWM); j++) {
if (data->REG_PWM[j] && data->REG_PWM[j][i]) {
data->pwm[j][i]
= nct6775_read_value(data,
data->REG_PWM[j][i]);
}
}
data->pwm_enable[i] = reg_to_pwm_enable(data->pwm[0][i],
(fanmodecfg >> 4) & 7);
if (!data->temp_tolerance[0][i] ||
data->pwm_enable[i] != speed_cruise)
data->temp_tolerance[0][i] = fanmodecfg & 0x0f;
if (!data->target_speed_tolerance[i] ||
data->pwm_enable[i] == speed_cruise) {
u8 t = fanmodecfg & 0x0f;
if (data->REG_TOLERANCE_H) {
t |= (nct6775_read_value(data,
data->REG_TOLERANCE_H[i]) & 0x70) >> 1;
}
data->target_speed_tolerance[i] = t;
}
data->temp_tolerance[1][i] =
nct6775_read_value(data,
data->REG_CRITICAL_TEMP_TOLERANCE[i]);
reg = nct6775_read_value(data, data->REG_TEMP_SEL[i]);
data->pwm_temp_sel[i] = reg & 0x1f;
if (reg & 0x80)
data->pwm[2][i] = 0;
if (!data->REG_WEIGHT_TEMP_SEL[i])
continue;
reg = nct6775_read_value(data, data->REG_WEIGHT_TEMP_SEL[i]);
data->pwm_weight_temp_sel[i] = reg & 0x1f;
if (j == 1 && !(reg & 0x80))
data->pwm_weight_temp_sel[i] = 0;
for (j = 0; j < ARRAY_SIZE(data->weight_temp); j++) {
data->weight_temp[j][i]
= nct6775_read_value(data,
data->REG_WEIGHT_TEMP[j][i]);
}
}
}
static void nct6775_update_pwm_limits(struct device *dev)
{
struct nct6775_data *data = dev_get_drvdata(dev);
int i, j;
u8 reg;
u16 reg_t;
for (i = 0; i < data->pwm_num; i++) {
if (!(data->has_pwm & BIT(i)))
continue;
for (j = 0; j < ARRAY_SIZE(data->fan_time); j++) {
data->fan_time[j][i] =
nct6775_read_value(data, data->REG_FAN_TIME[j][i]);
}
reg_t = nct6775_read_value(data, data->REG_TARGET[i]);
if (!data->target_temp[i] ||
data->pwm_enable[i] == thermal_cruise)
data->target_temp[i] = reg_t & data->target_temp_mask;
if (!data->target_speed[i] ||
data->pwm_enable[i] == speed_cruise) {
if (data->REG_TOLERANCE_H) {
reg_t |= (nct6775_read_value(data,
data->REG_TOLERANCE_H[i]) & 0x0f) << 8;
}
data->target_speed[i] = reg_t;
}
for (j = 0; j < data->auto_pwm_num; j++) {
data->auto_pwm[i][j] =
nct6775_read_value(data,
NCT6775_AUTO_PWM(data, i, j));
data->auto_temp[i][j] =
nct6775_read_value(data,
NCT6775_AUTO_TEMP(data, i, j));
}
data->auto_temp[i][data->auto_pwm_num] =
nct6775_read_value(data, data->REG_CRITICAL_TEMP[i]);
switch (data->kind) {
case nct6775:
reg = nct6775_read_value(data,
NCT6775_REG_CRITICAL_ENAB[i]);
data->auto_pwm[i][data->auto_pwm_num] =
(reg & 0x02) ? 0xff : 0x00;
break;
case nct6776:
data->auto_pwm[i][data->auto_pwm_num] = 0xff;
break;
case nct6106:
case nct6779:
case nct6791:
case nct6792:
case nct6793:
case nct6795:
reg = nct6775_read_value(data,
data->REG_CRITICAL_PWM_ENABLE[i]);
if (reg & data->CRITICAL_PWM_ENABLE_MASK)
reg = nct6775_read_value(data,
data->REG_CRITICAL_PWM[i]);
else
reg = 0xff;
data->auto_pwm[i][data->auto_pwm_num] = reg;
break;
}
}
}
static struct nct6775_data *nct6775_update_device(struct device *dev)
{
struct nct6775_data *data = dev_get_drvdata(dev);
int i, j;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ + HZ / 2)
|| !data->valid) {
nct6775_update_fan_div_common(data);
for (i = 0; i < data->in_num; i++) {
if (!(data->have_in & BIT(i)))
continue;
data->in[i][0] = nct6775_read_value(data,
data->REG_VIN[i]);
data->in[i][1] = nct6775_read_value(data,
data->REG_IN_MINMAX[0][i]);
data->in[i][2] = nct6775_read_value(data,
data->REG_IN_MINMAX[1][i]);
}
for (i = 0; i < ARRAY_SIZE(data->rpm); i++) {
u16 reg;
if (!(data->has_fan & BIT(i)))
continue;
reg = nct6775_read_value(data, data->REG_FAN[i]);
data->rpm[i] = data->fan_from_reg(reg,
data->fan_div[i]);
if (data->has_fan_min & BIT(i))
data->fan_min[i] = nct6775_read_value(data,
data->REG_FAN_MIN[i]);
data->fan_pulses[i] =
(nct6775_read_value(data, data->REG_FAN_PULSES[i])
>> data->FAN_PULSE_SHIFT[i]) & 0x03;
nct6775_select_fan_div(dev, data, i, reg);
}
nct6775_update_pwm(dev);
nct6775_update_pwm_limits(dev);
for (i = 0; i < NUM_TEMP; i++) {
if (!(data->have_temp & BIT(i)))
continue;
for (j = 0; j < ARRAY_SIZE(data->reg_temp); j++) {
if (data->reg_temp[j][i])
data->temp[j][i]
= nct6775_read_temp(data,
data->reg_temp[j][i]);
}
if (i >= NUM_TEMP_FIXED ||
!(data->have_temp_fixed & BIT(i)))
continue;
data->temp_offset[i]
= nct6775_read_value(data, data->REG_TEMP_OFFSET[i]);
}
data->alarms = 0;
for (i = 0; i < NUM_REG_ALARM; i++) {
u8 alarm;
if (!data->REG_ALARM[i])
continue;
alarm = nct6775_read_value(data, data->REG_ALARM[i]);
data->alarms |= ((u64)alarm) << (i << 3);
}
data->beeps = 0;
for (i = 0; i < NUM_REG_BEEP; i++) {
u8 beep;
if (!data->REG_BEEP[i])
continue;
beep = nct6775_read_value(data, data->REG_BEEP[i]);
data->beeps |= ((u64)beep) << (i << 3);
}
data->last_updated = jiffies;
data->valid = true;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t
show_in_reg(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int index = sattr->index;
int nr = sattr->nr;
return sprintf(buf, "%ld\n", in_from_reg(data->in[nr][index], nr));
}
static ssize_t
store_in_reg(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int index = sattr->index;
int nr = sattr->nr;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
data->in[nr][index] = in_to_reg(val, nr);
nct6775_write_value(data, data->REG_IN_MINMAX[index - 1][nr],
data->in[nr][index]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_alarm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = data->ALARM_BITS[sattr->index];
return sprintf(buf, "%u\n",
(unsigned int)((data->alarms >> nr) & 0x01));
}
static int find_temp_source(struct nct6775_data *data, int index, int count)
{
int source = data->temp_src[index];
int nr;
for (nr = 0; nr < count; nr++) {
int src;
src = nct6775_read_value(data,
data->REG_TEMP_SOURCE[nr]) & 0x1f;
if (src == source)
return nr;
}
return -ENODEV;
}
static ssize_t
show_temp_alarm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6775_data *data = nct6775_update_device(dev);
unsigned int alarm = 0;
int nr;
nr = find_temp_source(data, sattr->index, data->num_temp_alarms);
if (nr >= 0) {
int bit = data->ALARM_BITS[nr + TEMP_ALARM_BASE];
alarm = (data->alarms >> bit) & 0x01;
}
return sprintf(buf, "%u\n", alarm);
}
static ssize_t
show_beep(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6775_data *data = nct6775_update_device(dev);
int nr = data->BEEP_BITS[sattr->index];
return sprintf(buf, "%u\n",
(unsigned int)((data->beeps >> nr) & 0x01));
}
static ssize_t
store_beep(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct6775_data *data = dev_get_drvdata(dev);
int nr = data->BEEP_BITS[sattr->index];
int regindex = nr >> 3;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > 1)
return -EINVAL;
mutex_lock(&data->update_lock);
if (val)
data->beeps |= (1ULL << nr);
else
data->beeps &= ~(1ULL << nr);
nct6775_write_value(data, data->REG_BEEP[regindex],
(data->beeps >> (regindex << 3)) & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp_beep(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6775_data *data = nct6775_update_device(dev);
unsigned int beep = 0;
int nr;
nr = find_temp_source(data, sattr->index, data->num_temp_beeps);
if (nr >= 0) {
int bit = data->BEEP_BITS[nr + TEMP_ALARM_BASE];
beep = (data->beeps >> bit) & 0x01;
}
return sprintf(buf, "%u\n", beep);
}
static ssize_t
store_temp_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct6775_data *data = dev_get_drvdata(dev);
int nr, bit, regindex;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > 1)
return -EINVAL;
nr = find_temp_source(data, sattr->index, data->num_temp_beeps);
if (nr < 0)
return nr;
bit = data->BEEP_BITS[nr + TEMP_ALARM_BASE];
regindex = bit >> 3;
mutex_lock(&data->update_lock);
if (val)
data->beeps |= (1ULL << bit);
else
data->beeps &= ~(1ULL << bit);
nct6775_write_value(data, data->REG_BEEP[regindex],
(data->beeps >> (regindex << 3)) & 0xff);
mutex_unlock(&data->update_lock);
return count;
}
static umode_t nct6775_in_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6775_data *data = dev_get_drvdata(dev);
int in = index / 5;
if (!(data->have_in & BIT(in)))
return 0;
return attr->mode;
}
static ssize_t
show_fan(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%d\n", data->rpm[nr]);
}
static ssize_t
show_fan_min(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%d\n",
data->fan_from_reg_min(data->fan_min[nr],
data->fan_div[nr]));
}
static ssize_t
show_fan_div(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%u\n", div_from_reg(data->fan_div[nr]));
}
static ssize_t
store_fan_min(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
unsigned int reg;
u8 new_div;
int err;
err = kstrtoul(buf, 10, &val);
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
goto write_min;
}
if (!val) {
data->fan_min[nr] = 255;
new_div = data->fan_div[nr];
dev_info(dev, "fan%u low limit and alarm disabled\n", nr + 1);
goto write_div;
}
reg = 1350000U / val;
if (reg >= 128 * 255) {
data->fan_min[nr] = 254;
new_div = 7;
dev_warn(dev,
"fan%u low limit %lu below minimum %u, set to minimum\n",
nr + 1, val, data->fan_from_reg_min(254, 7));
} else if (!reg) {
data->fan_min[nr] = 1;
new_div = 0;
dev_warn(dev,
"fan%u low limit %lu above maximum %u, set to maximum\n",
nr + 1, val, data->fan_from_reg_min(1, 0));
} else {
new_div = 0;
while (reg > 192 && new_div < 7) {
reg >>= 1;
new_div++;
}
data->fan_min[nr] = reg;
}
write_div:
if (new_div != data->fan_div[nr]) {
dev_dbg(dev, "fan%u clock divider changed from %u to %u\n",
nr + 1, div_from_reg(data->fan_div[nr]),
div_from_reg(new_div));
data->fan_div[nr] = new_div;
nct6775_write_fan_div_common(data, nr);
data->last_updated = jiffies;
}
write_min:
nct6775_write_value(data, data->REG_FAN_MIN[nr], data->fan_min[nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_pulses(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int p = data->fan_pulses[sattr->index];
return sprintf(buf, "%d\n", p ? : 4);
}
static ssize_t
store_fan_pulses(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err;
u8 reg;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > 4)
return -EINVAL;
mutex_lock(&data->update_lock);
data->fan_pulses[nr] = val & 3;
reg = nct6775_read_value(data, data->REG_FAN_PULSES[nr]);
reg &= ~(0x03 << data->FAN_PULSE_SHIFT[nr]);
reg |= (val & 3) << data->FAN_PULSE_SHIFT[nr];
nct6775_write_value(data, data->REG_FAN_PULSES[nr], reg);
mutex_unlock(&data->update_lock);
return count;
}
static umode_t nct6775_fan_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6775_data *data = dev_get_drvdata(dev);
int fan = index / 6;
int nr = index % 6;
if (!(data->has_fan & BIT(fan)))
return 0;
if (nr == 1 && data->ALARM_BITS[FAN_ALARM_BASE + fan] == -1)
return 0;
if (nr == 2 && data->BEEP_BITS[FAN_ALARM_BASE + fan] == -1)
return 0;
if (nr == 4 && !(data->has_fan_min & BIT(fan)))
return 0;
if (nr == 5 && data->kind != nct6775)
return 0;
return attr->mode;
}
static ssize_t
show_temp_label(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%s\n", data->temp_label[data->temp_src[nr]]);
}
static ssize_t
show_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
return sprintf(buf, "%d\n", LM75_TEMP_FROM_REG(data->temp[index][nr]));
}
static ssize_t
store_temp(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
int err;
long val;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
mutex_lock(&data->update_lock);
data->temp[index][nr] = LM75_TEMP_TO_REG(val);
nct6775_write_temp(data, data->reg_temp[index][nr],
data->temp[index][nr]);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp_offset(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
return sprintf(buf, "%d\n", data->temp_offset[sattr->index] * 1000);
}
static ssize_t
store_temp_offset(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
long val;
int err;
err = kstrtol(buf, 10, &val);
if (err < 0)
return err;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), -128, 127);
mutex_lock(&data->update_lock);
data->temp_offset[nr] = val;
nct6775_write_value(data, data->REG_TEMP_OFFSET[nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp_type(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%d\n", (int)data->temp_type[nr]);
}
static ssize_t
store_temp_type(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err;
u8 vbat, diode, vbit, dbit;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val != 1 && val != 3 && val != 4)
return -EINVAL;
mutex_lock(&data->update_lock);
data->temp_type[nr] = val;
vbit = 0x02 << nr;
dbit = data->DIODE_MASK << nr;
vbat = nct6775_read_value(data, data->REG_VBAT) & ~vbit;
diode = nct6775_read_value(data, data->REG_DIODE) & ~dbit;
switch (val) {
case 1:
vbat |= vbit;
diode |= dbit;
break;
case 3:
vbat |= dbit;
break;
case 4:
break;
}
nct6775_write_value(data, data->REG_VBAT, vbat);
nct6775_write_value(data, data->REG_DIODE, diode);
mutex_unlock(&data->update_lock);
return count;
}
static umode_t nct6775_temp_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6775_data *data = dev_get_drvdata(dev);
int temp = index / 10;
int nr = index % 10;
if (!(data->have_temp & BIT(temp)))
return 0;
if (nr == 1 && !data->temp_label)
return 0;
if (nr == 2 && find_temp_source(data, temp, data->num_temp_alarms) < 0)
return 0;
if (nr == 3 && find_temp_source(data, temp, data->num_temp_beeps) < 0)
return 0;
if (nr == 4 && !data->reg_temp[1][temp])
return 0;
if (nr == 5 && !data->reg_temp[2][temp])
return 0;
if (nr == 6 && !data->reg_temp[3][temp])
return 0;
if (nr == 7 && !data->reg_temp[4][temp])
return 0;
if (nr > 7 && !(data->have_temp_fixed & BIT(temp)))
return 0;
return attr->mode;
}
static ssize_t
show_pwm_mode(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
return sprintf(buf, "%d\n", !data->pwm_mode[sattr->index]);
}
static ssize_t
store_pwm_mode(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err;
u8 reg;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > 1)
return -EINVAL;
if (data->REG_PWM_MODE[nr] == 0) {
if (val)
return -EINVAL;
return count;
}
mutex_lock(&data->update_lock);
data->pwm_mode[nr] = val;
reg = nct6775_read_value(data, data->REG_PWM_MODE[nr]);
reg &= ~data->PWM_MODE_MASK[nr];
if (val)
reg |= data->PWM_MODE_MASK[nr];
nct6775_write_value(data, data->REG_PWM_MODE[nr], reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
int pwm;
if (index == 0 && data->pwm_enable[nr] > manual)
pwm = nct6775_read_value(data, data->REG_PWM_READ[nr]);
else
pwm = data->pwm[index][nr];
return sprintf(buf, "%d\n", pwm);
}
static ssize_t
store_pwm(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
unsigned long val;
int minval[7] = { 0, 1, 1, data->pwm[2][nr], 0, 0, 0 };
int maxval[7]
= { 255, 255, data->pwm[3][nr] ? : 255, 255, 255, 255, 255 };
int err;
u8 reg;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = clamp_val(val, minval[index], maxval[index]);
mutex_lock(&data->update_lock);
data->pwm[index][nr] = val;
nct6775_write_value(data, data->REG_PWM[index][nr], val);
if (index == 2) {
reg = nct6775_read_value(data, data->REG_TEMP_SEL[nr]);
reg &= 0x7f;
if (val)
reg |= 0x80;
nct6775_write_value(data, data->REG_TEMP_SEL[nr], reg);
}
mutex_unlock(&data->update_lock);
return count;
}
static int check_trip_points(struct nct6775_data *data, int nr)
{
int i;
for (i = 0; i < data->auto_pwm_num - 1; i++) {
if (data->auto_temp[nr][i] > data->auto_temp[nr][i + 1])
return -EINVAL;
}
for (i = 0; i < data->auto_pwm_num - 1; i++) {
if (data->auto_pwm[nr][i] > data->auto_pwm[nr][i + 1])
return -EINVAL;
}
if (data->auto_pwm[nr][data->auto_pwm_num]) {
if (data->auto_temp[nr][data->auto_pwm_num - 1] >
data->auto_temp[nr][data->auto_pwm_num] ||
data->auto_pwm[nr][data->auto_pwm_num - 1] >
data->auto_pwm[nr][data->auto_pwm_num])
return -EINVAL;
}
return 0;
}
static void pwm_update_registers(struct nct6775_data *data, int nr)
{
u8 reg;
switch (data->pwm_enable[nr]) {
case off:
case manual:
break;
case speed_cruise:
reg = nct6775_read_value(data, data->REG_FAN_MODE[nr]);
reg = (reg & ~data->tolerance_mask) |
(data->target_speed_tolerance[nr] & data->tolerance_mask);
nct6775_write_value(data, data->REG_FAN_MODE[nr], reg);
nct6775_write_value(data, data->REG_TARGET[nr],
data->target_speed[nr] & 0xff);
if (data->REG_TOLERANCE_H) {
reg = (data->target_speed[nr] >> 8) & 0x0f;
reg |= (data->target_speed_tolerance[nr] & 0x38) << 1;
nct6775_write_value(data,
data->REG_TOLERANCE_H[nr],
reg);
}
break;
case thermal_cruise:
nct6775_write_value(data, data->REG_TARGET[nr],
data->target_temp[nr]);
default:
reg = nct6775_read_value(data, data->REG_FAN_MODE[nr]);
reg = (reg & ~data->tolerance_mask) |
data->temp_tolerance[0][nr];
nct6775_write_value(data, data->REG_FAN_MODE[nr], reg);
break;
}
}
static ssize_t
show_pwm_enable(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
return sprintf(buf, "%d\n", data->pwm_enable[sattr->index]);
}
static ssize_t
store_pwm_enable(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err;
u16 reg;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > sf4)
return -EINVAL;
if (val == sf3 && data->kind != nct6775)
return -EINVAL;
if (val == sf4 && check_trip_points(data, nr)) {
dev_err(dev, "Inconsistent trip points, not switching to SmartFan IV mode\n");
dev_err(dev, "Adjust trip points and try again\n");
return -EINVAL;
}
mutex_lock(&data->update_lock);
data->pwm_enable[nr] = val;
if (val == off) {
data->pwm[0][nr] = 255;
nct6775_write_value(data, data->REG_PWM[0][nr], 255);
}
pwm_update_registers(data, nr);
reg = nct6775_read_value(data, data->REG_FAN_MODE[nr]);
reg &= 0x0f;
reg |= pwm_enable_to_reg(val) << 4;
nct6775_write_value(data, data->REG_FAN_MODE[nr], reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm_temp_sel_common(struct nct6775_data *data, char *buf, int src)
{
int i, sel = 0;
for (i = 0; i < NUM_TEMP; i++) {
if (!(data->have_temp & BIT(i)))
continue;
if (src == data->temp_src[i]) {
sel = i + 1;
break;
}
}
return sprintf(buf, "%d\n", sel);
}
static ssize_t
show_pwm_temp_sel(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int index = sattr->index;
return show_pwm_temp_sel_common(data, buf, data->pwm_temp_sel[index]);
}
static ssize_t
store_pwm_temp_sel(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err, reg, src;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val == 0 || val > NUM_TEMP)
return -EINVAL;
if (!(data->have_temp & BIT(val - 1)) || !data->temp_src[val - 1])
return -EINVAL;
mutex_lock(&data->update_lock);
src = data->temp_src[val - 1];
data->pwm_temp_sel[nr] = src;
reg = nct6775_read_value(data, data->REG_TEMP_SEL[nr]);
reg &= 0xe0;
reg |= src;
nct6775_write_value(data, data->REG_TEMP_SEL[nr], reg);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_pwm_weight_temp_sel(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int index = sattr->index;
return show_pwm_temp_sel_common(data, buf,
data->pwm_weight_temp_sel[index]);
}
static ssize_t
store_pwm_weight_temp_sel(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err, reg, src;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > NUM_TEMP)
return -EINVAL;
if (val && (!(data->have_temp & BIT(val - 1)) ||
!data->temp_src[val - 1]))
return -EINVAL;
mutex_lock(&data->update_lock);
if (val) {
src = data->temp_src[val - 1];
data->pwm_weight_temp_sel[nr] = src;
reg = nct6775_read_value(data, data->REG_WEIGHT_TEMP_SEL[nr]);
reg &= 0xe0;
reg |= (src | 0x80);
nct6775_write_value(data, data->REG_WEIGHT_TEMP_SEL[nr], reg);
} else {
data->pwm_weight_temp_sel[nr] = 0;
reg = nct6775_read_value(data, data->REG_WEIGHT_TEMP_SEL[nr]);
reg &= 0x7f;
nct6775_write_value(data, data->REG_WEIGHT_TEMP_SEL[nr], reg);
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_target_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
return sprintf(buf, "%d\n", data->target_temp[sattr->index] * 1000);
}
static ssize_t
store_target_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), 0,
data->target_temp_mask);
mutex_lock(&data->update_lock);
data->target_temp[nr] = val;
pwm_update_registers(data, nr);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_target_speed(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%d\n",
fan_from_reg16(data->target_speed[nr],
data->fan_div[nr]));
}
static ssize_t
store_target_speed(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err;
u16 speed;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = clamp_val(val, 0, 1350000U);
speed = fan_to_reg(val, data->fan_div[nr]);
mutex_lock(&data->update_lock);
data->target_speed[nr] = speed;
pwm_update_registers(data, nr);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_temp_tolerance(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
return sprintf(buf, "%d\n", data->temp_tolerance[index][nr] * 1000);
}
static ssize_t
store_temp_tolerance(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), 0, data->tolerance_mask);
mutex_lock(&data->update_lock);
data->temp_tolerance[index][nr] = val;
if (index)
pwm_update_registers(data, nr);
else
nct6775_write_value(data,
data->REG_CRITICAL_TEMP_TOLERANCE[nr],
val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_speed_tolerance(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
int low = data->target_speed[nr] - data->target_speed_tolerance[nr];
int high = data->target_speed[nr] + data->target_speed_tolerance[nr];
int tolerance;
if (low <= 0)
low = 1;
if (high > 0xffff)
high = 0xffff;
if (high < low)
high = low;
tolerance = (fan_from_reg16(low, data->fan_div[nr])
- fan_from_reg16(high, data->fan_div[nr])) / 2;
return sprintf(buf, "%d\n", tolerance);
}
static ssize_t
store_speed_tolerance(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
unsigned long val;
int err;
int low, high;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
high = fan_from_reg16(data->target_speed[nr],
data->fan_div[nr]) + val;
low = fan_from_reg16(data->target_speed[nr],
data->fan_div[nr]) - val;
if (low <= 0)
low = 1;
if (high < low)
high = low;
val = (fan_to_reg(low, data->fan_div[nr]) -
fan_to_reg(high, data->fan_div[nr])) / 2;
val = clamp_val(val, 0, data->speed_tolerance_limit);
mutex_lock(&data->update_lock);
data->target_speed_tolerance[nr] = val;
pwm_update_registers(data, nr);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_weight_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
return sprintf(buf, "%d\n", data->weight_temp[index][nr] * 1000);
}
static ssize_t
store_weight_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = clamp_val(DIV_ROUND_CLOSEST(val, 1000), 0, 255);
mutex_lock(&data->update_lock);
data->weight_temp[index][nr] = val;
nct6775_write_value(data, data->REG_WEIGHT_TEMP[index][nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_fan_time(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
return sprintf(buf, "%d\n",
step_time_from_reg(data->fan_time[index][nr],
data->pwm_mode[nr]));
}
static ssize_t
store_fan_time(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int index = sattr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
val = step_time_to_reg(val, data->pwm_mode[nr]);
mutex_lock(&data->update_lock);
data->fan_time[index][nr] = val;
nct6775_write_value(data, data->REG_FAN_TIME[index][nr], val);
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_auto_pwm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
return sprintf(buf, "%d\n", data->auto_pwm[sattr->nr][sattr->index]);
}
static ssize_t
store_auto_pwm(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int point = sattr->index;
unsigned long val;
int err;
u8 reg;
err = kstrtoul(buf, 10, &val);
if (err < 0)
return err;
if (val > 255)
return -EINVAL;
if (point == data->auto_pwm_num) {
if (data->kind != nct6775 && !val)
return -EINVAL;
if (data->kind != nct6779 && val)
val = 0xff;
}
mutex_lock(&data->update_lock);
data->auto_pwm[nr][point] = val;
if (point < data->auto_pwm_num) {
nct6775_write_value(data,
NCT6775_AUTO_PWM(data, nr, point),
data->auto_pwm[nr][point]);
} else {
switch (data->kind) {
case nct6775:
reg = nct6775_read_value(data,
NCT6775_REG_CRITICAL_ENAB[nr]);
if (val)
reg |= 0x02;
else
reg &= ~0x02;
nct6775_write_value(data, NCT6775_REG_CRITICAL_ENAB[nr],
reg);
break;
case nct6776:
break;
case nct6106:
case nct6779:
case nct6791:
case nct6792:
case nct6793:
case nct6795:
nct6775_write_value(data, data->REG_CRITICAL_PWM[nr],
val);
reg = nct6775_read_value(data,
data->REG_CRITICAL_PWM_ENABLE[nr]);
if (val == 255)
reg &= ~data->CRITICAL_PWM_ENABLE_MASK;
else
reg |= data->CRITICAL_PWM_ENABLE_MASK;
nct6775_write_value(data,
data->REG_CRITICAL_PWM_ENABLE[nr],
reg);
break;
}
}
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_auto_temp(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = nct6775_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int point = sattr->index;
return sprintf(buf, "%d\n", data->auto_temp[nr][point] * 1000);
}
static ssize_t
store_auto_temp(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int nr = sattr->nr;
int point = sattr->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
if (val > 255000)
return -EINVAL;
mutex_lock(&data->update_lock);
data->auto_temp[nr][point] = DIV_ROUND_CLOSEST(val, 1000);
if (point < data->auto_pwm_num) {
nct6775_write_value(data,
NCT6775_AUTO_TEMP(data, nr, point),
data->auto_temp[nr][point]);
} else {
nct6775_write_value(data, data->REG_CRITICAL_TEMP[nr],
data->auto_temp[nr][point]);
}
mutex_unlock(&data->update_lock);
return count;
}
static umode_t nct6775_pwm_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6775_data *data = dev_get_drvdata(dev);
int pwm = index / 36;
int nr = index % 36;
if (!(data->has_pwm & BIT(pwm)))
return 0;
if ((nr >= 14 && nr <= 18) || nr == 21)
if (!data->REG_WEIGHT_TEMP_SEL[pwm])
return 0;
if (nr == 19 && data->REG_PWM[3] == NULL)
return 0;
if (nr == 20 && data->REG_PWM[4] == NULL)
return 0;
if (nr == 21 && data->REG_PWM[6] == NULL)
return 0;
if (nr >= 22 && nr <= 35) {
int api = (nr - 22) / 2;
if (api > data->auto_pwm_num)
return 0;
}
return attr->mode;
}
static ssize_t
cpu0_vid_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6775_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", vid_from_reg(data->vid, data->vrm));
}
static ssize_t
clear_caseopen(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6775_data *data = dev_get_drvdata(dev);
int nr = to_sensor_dev_attr(attr)->index - INTRUSION_ALARM_BASE;
unsigned long val;
u8 reg;
int ret;
if (kstrtoul(buf, 10, &val) || val != 0)
return -EINVAL;
mutex_lock(&data->update_lock);
ret = superio_enter(data->sioreg);
if (ret) {
count = ret;
goto error;
}
superio_select(data->sioreg, NCT6775_LD_ACPI);
reg = superio_inb(data->sioreg, NCT6775_REG_CR_CASEOPEN_CLR[nr]);
reg |= NCT6775_CR_CASEOPEN_CLR_MASK[nr];
superio_outb(data->sioreg, NCT6775_REG_CR_CASEOPEN_CLR[nr], reg);
reg &= ~NCT6775_CR_CASEOPEN_CLR_MASK[nr];
superio_outb(data->sioreg, NCT6775_REG_CR_CASEOPEN_CLR[nr], reg);
superio_exit(data->sioreg);
data->valid = false;
error:
mutex_unlock(&data->update_lock);
return count;
}
static umode_t nct6775_other_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6775_data *data = dev_get_drvdata(dev);
if (index == 0 && !data->have_vid)
return 0;
if (index == 1 || index == 2) {
if (data->ALARM_BITS[INTRUSION_ALARM_BASE + index - 1] < 0)
return 0;
}
if (index == 3 || index == 4) {
if (data->BEEP_BITS[INTRUSION_ALARM_BASE + index - 3] < 0)
return 0;
}
return attr->mode;
}
static inline void nct6775_init_device(struct nct6775_data *data)
{
int i;
u8 tmp, diode;
if (data->REG_CONFIG) {
tmp = nct6775_read_value(data, data->REG_CONFIG);
if (!(tmp & 0x01))
nct6775_write_value(data, data->REG_CONFIG, tmp | 0x01);
}
for (i = 0; i < NUM_TEMP; i++) {
if (!(data->have_temp & BIT(i)))
continue;
if (!data->reg_temp_config[i])
continue;
tmp = nct6775_read_value(data, data->reg_temp_config[i]);
if (tmp & 0x01)
nct6775_write_value(data, data->reg_temp_config[i],
tmp & 0xfe);
}
tmp = nct6775_read_value(data, data->REG_VBAT);
if (!(tmp & 0x01))
nct6775_write_value(data, data->REG_VBAT, tmp | 0x01);
diode = nct6775_read_value(data, data->REG_DIODE);
for (i = 0; i < data->temp_fixed_num; i++) {
if (!(data->have_temp_fixed & BIT(i)))
continue;
if ((tmp & (data->DIODE_MASK << i)))
data->temp_type[i]
= 3 - ((diode >> i) & data->DIODE_MASK);
else
data->temp_type[i] = 4;
}
}
static void
nct6775_check_fan_inputs(struct nct6775_data *data)
{
bool fan3pin, fan4pin, fan4min, fan5pin, fan6pin;
bool pwm3pin, pwm4pin, pwm5pin, pwm6pin;
int sioreg = data->sioreg;
int regval;
superio_select(sioreg, NCT6775_LD_HWM);
data->sio_reg_enable = superio_inb(sioreg, SIO_REG_ENABLE);
if (data->kind == nct6775) {
regval = superio_inb(sioreg, 0x2c);
fan3pin = regval & BIT(6);
pwm3pin = regval & BIT(7);
fan4pin = !(superio_inb(sioreg, 0x2A) & 0x80);
fan4min = false;
fan5pin = false;
fan6pin = false;
pwm4pin = false;
pwm5pin = false;
pwm6pin = false;
} else if (data->kind == nct6776) {
bool gpok = superio_inb(sioreg, 0x27) & 0x80;
const char *board_vendor, *board_name;
board_vendor = dmi_get_system_info(DMI_BOARD_VENDOR);
board_name = dmi_get_system_info(DMI_BOARD_NAME);
if (board_name && board_vendor &&
!strcmp(board_vendor, "ASRock")) {
if (!strcmp(board_name, "Z77 Pro4-M")) {
if ((data->sio_reg_enable & 0xe0) != 0xe0) {
data->sio_reg_enable |= 0xe0;
superio_outb(sioreg, SIO_REG_ENABLE,
data->sio_reg_enable);
}
}
}
if (data->sio_reg_enable & 0x80)
fan3pin = gpok;
else
fan3pin = !(superio_inb(sioreg, 0x24) & 0x40);
if (data->sio_reg_enable & 0x40)
fan4pin = gpok;
else
fan4pin = superio_inb(sioreg, 0x1C) & 0x01;
if (data->sio_reg_enable & 0x20)
fan5pin = gpok;
else
fan5pin = superio_inb(sioreg, 0x1C) & 0x02;
fan4min = fan4pin;
fan6pin = false;
pwm3pin = fan3pin;
pwm4pin = false;
pwm5pin = false;
pwm6pin = false;
} else if (data->kind == nct6106) {
regval = superio_inb(sioreg, 0x24);
fan3pin = !(regval & 0x80);
pwm3pin = regval & 0x08;
fan4pin = false;
fan4min = false;
fan5pin = false;
fan6pin = false;
pwm4pin = false;
pwm5pin = false;
pwm6pin = false;
} else {
int regval_1b, regval_2a, regval_eb;
regval = superio_inb(sioreg, 0x1c);
fan3pin = !(regval & BIT(5));
fan4pin = !(regval & BIT(6));
fan5pin = !(regval & BIT(7));
pwm3pin = !(regval & BIT(0));
pwm4pin = !(regval & BIT(1));
pwm5pin = !(regval & BIT(2));
regval = superio_inb(sioreg, 0x2d);
switch (data->kind) {
case nct6791:
case nct6792:
fan6pin = regval & BIT(1);
pwm6pin = regval & BIT(0);
break;
case nct6793:
case nct6795:
regval_1b = superio_inb(sioreg, 0x1b);
regval_2a = superio_inb(sioreg, 0x2a);
if (!pwm5pin)
pwm5pin = regval & BIT(7);
fan6pin = regval & BIT(1);
pwm6pin = regval & BIT(0);
if (!fan5pin)
fan5pin = regval_1b & BIT(5);
superio_select(sioreg, NCT6775_LD_12);
regval_eb = superio_inb(sioreg, 0xeb);
if (!fan5pin)
fan5pin = regval_eb & BIT(5);
if (!pwm5pin)
pwm5pin = (regval_eb & BIT(4)) &&
!(regval_2a & BIT(0));
if (!fan6pin)
fan6pin = regval_eb & BIT(3);
if (!pwm6pin)
pwm6pin = regval_eb & BIT(2);
break;
default:
fan6pin = false;
pwm6pin = false;
break;
}
fan4min = fan4pin;
}
data->has_fan = 0x03 | (fan3pin << 2) | (fan4pin << 3) |
(fan5pin << 4) | (fan6pin << 5);
data->has_fan_min = 0x03 | (fan3pin << 2) | (fan4min << 3) |
(fan5pin << 4);
data->has_pwm = 0x03 | (pwm3pin << 2) | (pwm4pin << 3) |
(pwm5pin << 4) | (pwm6pin << 5);
}
static void add_temp_sensors(struct nct6775_data *data, const u16 *regp,
int *available, int *mask)
{
int i;
u8 src;
for (i = 0; i < data->pwm_num && *available; i++) {
int index;
if (!regp[i])
continue;
src = nct6775_read_value(data, regp[i]);
src &= 0x1f;
if (!src || (*mask & BIT(src)))
continue;
if (!(data->temp_mask & BIT(src)))
continue;
index = __ffs(*available);
nct6775_write_value(data, data->REG_TEMP_SOURCE[index], src);
*available &= ~BIT(index);
*mask |= BIT(src);
}
}
static int nct6775_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct nct6775_sio_data *sio_data = dev_get_platdata(dev);
struct nct6775_data *data;
struct resource *res;
int i, s, err = 0;
int src, mask, available;
const u16 *reg_temp, *reg_temp_over, *reg_temp_hyst, *reg_temp_config;
const u16 *reg_temp_mon, *reg_temp_alternate, *reg_temp_crit;
const u16 *reg_temp_crit_l = NULL, *reg_temp_crit_h = NULL;
int num_reg_temp, num_reg_temp_mon;
u8 cr2a;
struct attribute_group *group;
struct device *hwmon_dev;
int num_attr_groups = 0;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(&pdev->dev, res->start, IOREGION_LENGTH,
DRVNAME))
return -EBUSY;
data = devm_kzalloc(&pdev->dev, sizeof(struct nct6775_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->kind = sio_data->kind;
data->sioreg = sio_data->sioreg;
data->addr = res->start;
mutex_init(&data->update_lock);
data->name = nct6775_device_names[data->kind];
data->bank = 0xff;
platform_set_drvdata(pdev, data);
switch (data->kind) {
case nct6106:
data->in_num = 9;
data->pwm_num = 3;
data->auto_pwm_num = 4;
data->temp_fixed_num = 3;
data->num_temp_alarms = 6;
data->num_temp_beeps = 6;
data->fan_from_reg = fan_from_reg13;
data->fan_from_reg_min = fan_from_reg13;
data->temp_label = nct6776_temp_label;
data->temp_mask = NCT6776_TEMP_MASK;
data->REG_VBAT = NCT6106_REG_VBAT;
data->REG_DIODE = NCT6106_REG_DIODE;
data->DIODE_MASK = NCT6106_DIODE_MASK;
data->REG_VIN = NCT6106_REG_IN;
data->REG_IN_MINMAX[0] = NCT6106_REG_IN_MIN;
data->REG_IN_MINMAX[1] = NCT6106_REG_IN_MAX;
data->REG_TARGET = NCT6106_REG_TARGET;
data->REG_FAN = NCT6106_REG_FAN;
data->REG_FAN_MODE = NCT6106_REG_FAN_MODE;
data->REG_FAN_MIN = NCT6106_REG_FAN_MIN;
data->REG_FAN_PULSES = NCT6106_REG_FAN_PULSES;
data->FAN_PULSE_SHIFT = NCT6106_FAN_PULSE_SHIFT;
data->REG_FAN_TIME[0] = NCT6106_REG_FAN_STOP_TIME;
data->REG_FAN_TIME[1] = NCT6106_REG_FAN_STEP_UP_TIME;
data->REG_FAN_TIME[2] = NCT6106_REG_FAN_STEP_DOWN_TIME;
data->REG_PWM[0] = NCT6106_REG_PWM;
data->REG_PWM[1] = NCT6106_REG_FAN_START_OUTPUT;
data->REG_PWM[2] = NCT6106_REG_FAN_STOP_OUTPUT;
data->REG_PWM[5] = NCT6106_REG_WEIGHT_DUTY_STEP;
data->REG_PWM[6] = NCT6106_REG_WEIGHT_DUTY_BASE;
data->REG_PWM_READ = NCT6106_REG_PWM_READ;
data->REG_PWM_MODE = NCT6106_REG_PWM_MODE;
data->PWM_MODE_MASK = NCT6106_PWM_MODE_MASK;
data->REG_AUTO_TEMP = NCT6106_REG_AUTO_TEMP;
data->REG_AUTO_PWM = NCT6106_REG_AUTO_PWM;
data->REG_CRITICAL_TEMP = NCT6106_REG_CRITICAL_TEMP;
data->REG_CRITICAL_TEMP_TOLERANCE
= NCT6106_REG_CRITICAL_TEMP_TOLERANCE;
data->REG_CRITICAL_PWM_ENABLE = NCT6106_REG_CRITICAL_PWM_ENABLE;
data->CRITICAL_PWM_ENABLE_MASK
= NCT6106_CRITICAL_PWM_ENABLE_MASK;
data->REG_CRITICAL_PWM = NCT6106_REG_CRITICAL_PWM;
data->REG_TEMP_OFFSET = NCT6106_REG_TEMP_OFFSET;
data->REG_TEMP_SOURCE = NCT6106_REG_TEMP_SOURCE;
data->REG_TEMP_SEL = NCT6106_REG_TEMP_SEL;
data->REG_WEIGHT_TEMP_SEL = NCT6106_REG_WEIGHT_TEMP_SEL;
data->REG_WEIGHT_TEMP[0] = NCT6106_REG_WEIGHT_TEMP_STEP;
data->REG_WEIGHT_TEMP[1] = NCT6106_REG_WEIGHT_TEMP_STEP_TOL;
data->REG_WEIGHT_TEMP[2] = NCT6106_REG_WEIGHT_TEMP_BASE;
data->REG_ALARM = NCT6106_REG_ALARM;
data->ALARM_BITS = NCT6106_ALARM_BITS;
data->REG_BEEP = NCT6106_REG_BEEP;
data->BEEP_BITS = NCT6106_BEEP_BITS;
reg_temp = NCT6106_REG_TEMP;
reg_temp_mon = NCT6106_REG_TEMP_MON;
num_reg_temp = ARRAY_SIZE(NCT6106_REG_TEMP);
num_reg_temp_mon = ARRAY_SIZE(NCT6106_REG_TEMP_MON);
reg_temp_over = NCT6106_REG_TEMP_OVER;
reg_temp_hyst = NCT6106_REG_TEMP_HYST;
reg_temp_config = NCT6106_REG_TEMP_CONFIG;
reg_temp_alternate = NCT6106_REG_TEMP_ALTERNATE;
reg_temp_crit = NCT6106_REG_TEMP_CRIT;
reg_temp_crit_l = NCT6106_REG_TEMP_CRIT_L;
reg_temp_crit_h = NCT6106_REG_TEMP_CRIT_H;
break;
case nct6775:
data->in_num = 9;
data->pwm_num = 3;
data->auto_pwm_num = 6;
data->has_fan_div = true;
data->temp_fixed_num = 3;
data->num_temp_alarms = 3;
data->num_temp_beeps = 3;
data->ALARM_BITS = NCT6775_ALARM_BITS;
data->BEEP_BITS = NCT6775_BEEP_BITS;
data->fan_from_reg = fan_from_reg16;
data->fan_from_reg_min = fan_from_reg8;
data->target_temp_mask = 0x7f;
data->tolerance_mask = 0x0f;
data->speed_tolerance_limit = 15;
data->temp_label = nct6775_temp_label;
data->temp_mask = NCT6775_TEMP_MASK;
data->REG_CONFIG = NCT6775_REG_CONFIG;
data->REG_VBAT = NCT6775_REG_VBAT;
data->REG_DIODE = NCT6775_REG_DIODE;
data->DIODE_MASK = NCT6775_DIODE_MASK;
data->REG_VIN = NCT6775_REG_IN;
data->REG_IN_MINMAX[0] = NCT6775_REG_IN_MIN;
data->REG_IN_MINMAX[1] = NCT6775_REG_IN_MAX;
data->REG_TARGET = NCT6775_REG_TARGET;
data->REG_FAN = NCT6775_REG_FAN;
data->REG_FAN_MODE = NCT6775_REG_FAN_MODE;
data->REG_FAN_MIN = NCT6775_REG_FAN_MIN;
data->REG_FAN_PULSES = NCT6775_REG_FAN_PULSES;
data->FAN_PULSE_SHIFT = NCT6775_FAN_PULSE_SHIFT;
data->REG_FAN_TIME[0] = NCT6775_REG_FAN_STOP_TIME;
data->REG_FAN_TIME[1] = NCT6775_REG_FAN_STEP_UP_TIME;
data->REG_FAN_TIME[2] = NCT6775_REG_FAN_STEP_DOWN_TIME;
data->REG_PWM[0] = NCT6775_REG_PWM;
data->REG_PWM[1] = NCT6775_REG_FAN_START_OUTPUT;
data->REG_PWM[2] = NCT6775_REG_FAN_STOP_OUTPUT;
data->REG_PWM[3] = NCT6775_REG_FAN_MAX_OUTPUT;
data->REG_PWM[4] = NCT6775_REG_FAN_STEP_OUTPUT;
data->REG_PWM[5] = NCT6775_REG_WEIGHT_DUTY_STEP;
data->REG_PWM_READ = NCT6775_REG_PWM_READ;
data->REG_PWM_MODE = NCT6775_REG_PWM_MODE;
data->PWM_MODE_MASK = NCT6775_PWM_MODE_MASK;
data->REG_AUTO_TEMP = NCT6775_REG_AUTO_TEMP;
data->REG_AUTO_PWM = NCT6775_REG_AUTO_PWM;
data->REG_CRITICAL_TEMP = NCT6775_REG_CRITICAL_TEMP;
data->REG_CRITICAL_TEMP_TOLERANCE
= NCT6775_REG_CRITICAL_TEMP_TOLERANCE;
data->REG_TEMP_OFFSET = NCT6775_REG_TEMP_OFFSET;
data->REG_TEMP_SOURCE = NCT6775_REG_TEMP_SOURCE;
data->REG_TEMP_SEL = NCT6775_REG_TEMP_SEL;
data->REG_WEIGHT_TEMP_SEL = NCT6775_REG_WEIGHT_TEMP_SEL;
data->REG_WEIGHT_TEMP[0] = NCT6775_REG_WEIGHT_TEMP_STEP;
data->REG_WEIGHT_TEMP[1] = NCT6775_REG_WEIGHT_TEMP_STEP_TOL;
data->REG_WEIGHT_TEMP[2] = NCT6775_REG_WEIGHT_TEMP_BASE;
data->REG_ALARM = NCT6775_REG_ALARM;
data->REG_BEEP = NCT6775_REG_BEEP;
reg_temp = NCT6775_REG_TEMP;
reg_temp_mon = NCT6775_REG_TEMP_MON;
num_reg_temp = ARRAY_SIZE(NCT6775_REG_TEMP);
num_reg_temp_mon = ARRAY_SIZE(NCT6775_REG_TEMP_MON);
reg_temp_over = NCT6775_REG_TEMP_OVER;
reg_temp_hyst = NCT6775_REG_TEMP_HYST;
reg_temp_config = NCT6775_REG_TEMP_CONFIG;
reg_temp_alternate = NCT6775_REG_TEMP_ALTERNATE;
reg_temp_crit = NCT6775_REG_TEMP_CRIT;
break;
case nct6776:
data->in_num = 9;
data->pwm_num = 3;
data->auto_pwm_num = 4;
data->has_fan_div = false;
data->temp_fixed_num = 3;
data->num_temp_alarms = 3;
data->num_temp_beeps = 6;
data->ALARM_BITS = NCT6776_ALARM_BITS;
data->BEEP_BITS = NCT6776_BEEP_BITS;
data->fan_from_reg = fan_from_reg13;
data->fan_from_reg_min = fan_from_reg13;
data->target_temp_mask = 0xff;
data->tolerance_mask = 0x07;
data->speed_tolerance_limit = 63;
data->temp_label = nct6776_temp_label;
data->temp_mask = NCT6776_TEMP_MASK;
data->REG_CONFIG = NCT6775_REG_CONFIG;
data->REG_VBAT = NCT6775_REG_VBAT;
data->REG_DIODE = NCT6775_REG_DIODE;
data->DIODE_MASK = NCT6775_DIODE_MASK;
data->REG_VIN = NCT6775_REG_IN;
data->REG_IN_MINMAX[0] = NCT6775_REG_IN_MIN;
data->REG_IN_MINMAX[1] = NCT6775_REG_IN_MAX;
data->REG_TARGET = NCT6775_REG_TARGET;
data->REG_FAN = NCT6775_REG_FAN;
data->REG_FAN_MODE = NCT6775_REG_FAN_MODE;
data->REG_FAN_MIN = NCT6776_REG_FAN_MIN;
data->REG_FAN_PULSES = NCT6776_REG_FAN_PULSES;
data->FAN_PULSE_SHIFT = NCT6775_FAN_PULSE_SHIFT;
data->REG_FAN_TIME[0] = NCT6775_REG_FAN_STOP_TIME;
data->REG_FAN_TIME[1] = NCT6776_REG_FAN_STEP_UP_TIME;
data->REG_FAN_TIME[2] = NCT6776_REG_FAN_STEP_DOWN_TIME;
data->REG_TOLERANCE_H = NCT6776_REG_TOLERANCE_H;
data->REG_PWM[0] = NCT6775_REG_PWM;
data->REG_PWM[1] = NCT6775_REG_FAN_START_OUTPUT;
data->REG_PWM[2] = NCT6775_REG_FAN_STOP_OUTPUT;
data->REG_PWM[5] = NCT6775_REG_WEIGHT_DUTY_STEP;
data->REG_PWM[6] = NCT6776_REG_WEIGHT_DUTY_BASE;
data->REG_PWM_READ = NCT6775_REG_PWM_READ;
data->REG_PWM_MODE = NCT6776_REG_PWM_MODE;
data->PWM_MODE_MASK = NCT6776_PWM_MODE_MASK;
data->REG_AUTO_TEMP = NCT6775_REG_AUTO_TEMP;
data->REG_AUTO_PWM = NCT6775_REG_AUTO_PWM;
data->REG_CRITICAL_TEMP = NCT6775_REG_CRITICAL_TEMP;
data->REG_CRITICAL_TEMP_TOLERANCE
= NCT6775_REG_CRITICAL_TEMP_TOLERANCE;
data->REG_TEMP_OFFSET = NCT6775_REG_TEMP_OFFSET;
data->REG_TEMP_SOURCE = NCT6775_REG_TEMP_SOURCE;
data->REG_TEMP_SEL = NCT6775_REG_TEMP_SEL;
data->REG_WEIGHT_TEMP_SEL = NCT6775_REG_WEIGHT_TEMP_SEL;
data->REG_WEIGHT_TEMP[0] = NCT6775_REG_WEIGHT_TEMP_STEP;
data->REG_WEIGHT_TEMP[1] = NCT6775_REG_WEIGHT_TEMP_STEP_TOL;
data->REG_WEIGHT_TEMP[2] = NCT6775_REG_WEIGHT_TEMP_BASE;
data->REG_ALARM = NCT6775_REG_ALARM;
data->REG_BEEP = NCT6776_REG_BEEP;
reg_temp = NCT6775_REG_TEMP;
reg_temp_mon = NCT6775_REG_TEMP_MON;
num_reg_temp = ARRAY_SIZE(NCT6775_REG_TEMP);
num_reg_temp_mon = ARRAY_SIZE(NCT6775_REG_TEMP_MON);
reg_temp_over = NCT6775_REG_TEMP_OVER;
reg_temp_hyst = NCT6775_REG_TEMP_HYST;
reg_temp_config = NCT6776_REG_TEMP_CONFIG;
reg_temp_alternate = NCT6776_REG_TEMP_ALTERNATE;
reg_temp_crit = NCT6776_REG_TEMP_CRIT;
break;
case nct6779:
data->in_num = 15;
data->pwm_num = 5;
data->auto_pwm_num = 4;
data->has_fan_div = false;
data->temp_fixed_num = 6;
data->num_temp_alarms = 2;
data->num_temp_beeps = 2;
data->ALARM_BITS = NCT6779_ALARM_BITS;
data->BEEP_BITS = NCT6779_BEEP_BITS;
data->fan_from_reg = fan_from_reg13;
data->fan_from_reg_min = fan_from_reg13;
data->target_temp_mask = 0xff;
data->tolerance_mask = 0x07;
data->speed_tolerance_limit = 63;
data->temp_label = nct6779_temp_label;
data->temp_mask = NCT6779_TEMP_MASK;
data->REG_CONFIG = NCT6775_REG_CONFIG;
data->REG_VBAT = NCT6775_REG_VBAT;
data->REG_DIODE = NCT6775_REG_DIODE;
data->DIODE_MASK = NCT6775_DIODE_MASK;
data->REG_VIN = NCT6779_REG_IN;
data->REG_IN_MINMAX[0] = NCT6775_REG_IN_MIN;
data->REG_IN_MINMAX[1] = NCT6775_REG_IN_MAX;
data->REG_TARGET = NCT6775_REG_TARGET;
data->REG_FAN = NCT6779_REG_FAN;
data->REG_FAN_MODE = NCT6775_REG_FAN_MODE;
data->REG_FAN_MIN = NCT6776_REG_FAN_MIN;
data->REG_FAN_PULSES = NCT6779_REG_FAN_PULSES;
data->FAN_PULSE_SHIFT = NCT6775_FAN_PULSE_SHIFT;
data->REG_FAN_TIME[0] = NCT6775_REG_FAN_STOP_TIME;
data->REG_FAN_TIME[1] = NCT6776_REG_FAN_STEP_UP_TIME;
data->REG_FAN_TIME[2] = NCT6776_REG_FAN_STEP_DOWN_TIME;
data->REG_TOLERANCE_H = NCT6776_REG_TOLERANCE_H;
data->REG_PWM[0] = NCT6775_REG_PWM;
data->REG_PWM[1] = NCT6775_REG_FAN_START_OUTPUT;
data->REG_PWM[2] = NCT6775_REG_FAN_STOP_OUTPUT;
data->REG_PWM[5] = NCT6775_REG_WEIGHT_DUTY_STEP;
data->REG_PWM[6] = NCT6776_REG_WEIGHT_DUTY_BASE;
data->REG_PWM_READ = NCT6775_REG_PWM_READ;
data->REG_PWM_MODE = NCT6776_REG_PWM_MODE;
data->PWM_MODE_MASK = NCT6776_PWM_MODE_MASK;
data->REG_AUTO_TEMP = NCT6775_REG_AUTO_TEMP;
data->REG_AUTO_PWM = NCT6775_REG_AUTO_PWM;
data->REG_CRITICAL_TEMP = NCT6775_REG_CRITICAL_TEMP;
data->REG_CRITICAL_TEMP_TOLERANCE
= NCT6775_REG_CRITICAL_TEMP_TOLERANCE;
data->REG_CRITICAL_PWM_ENABLE = NCT6779_REG_CRITICAL_PWM_ENABLE;
data->CRITICAL_PWM_ENABLE_MASK
= NCT6779_CRITICAL_PWM_ENABLE_MASK;
data->REG_CRITICAL_PWM = NCT6779_REG_CRITICAL_PWM;
data->REG_TEMP_OFFSET = NCT6779_REG_TEMP_OFFSET;
data->REG_TEMP_SOURCE = NCT6775_REG_TEMP_SOURCE;
data->REG_TEMP_SEL = NCT6775_REG_TEMP_SEL;
data->REG_WEIGHT_TEMP_SEL = NCT6775_REG_WEIGHT_TEMP_SEL;
data->REG_WEIGHT_TEMP[0] = NCT6775_REG_WEIGHT_TEMP_STEP;
data->REG_WEIGHT_TEMP[1] = NCT6775_REG_WEIGHT_TEMP_STEP_TOL;
data->REG_WEIGHT_TEMP[2] = NCT6775_REG_WEIGHT_TEMP_BASE;
data->REG_ALARM = NCT6779_REG_ALARM;
data->REG_BEEP = NCT6776_REG_BEEP;
reg_temp = NCT6779_REG_TEMP;
reg_temp_mon = NCT6779_REG_TEMP_MON;
num_reg_temp = ARRAY_SIZE(NCT6779_REG_TEMP);
num_reg_temp_mon = ARRAY_SIZE(NCT6779_REG_TEMP_MON);
reg_temp_over = NCT6779_REG_TEMP_OVER;
reg_temp_hyst = NCT6779_REG_TEMP_HYST;
reg_temp_config = NCT6779_REG_TEMP_CONFIG;
reg_temp_alternate = NCT6779_REG_TEMP_ALTERNATE;
reg_temp_crit = NCT6779_REG_TEMP_CRIT;
break;
case nct6791:
case nct6792:
case nct6793:
case nct6795:
data->in_num = 15;
data->pwm_num = 6;
data->auto_pwm_num = 4;
data->has_fan_div = false;
data->temp_fixed_num = 6;
data->num_temp_alarms = 2;
data->num_temp_beeps = 2;
data->ALARM_BITS = NCT6791_ALARM_BITS;
data->BEEP_BITS = NCT6779_BEEP_BITS;
data->fan_from_reg = fan_from_reg13;
data->fan_from_reg_min = fan_from_reg13;
data->target_temp_mask = 0xff;
data->tolerance_mask = 0x07;
data->speed_tolerance_limit = 63;
switch (data->kind) {
default:
case nct6791:
data->temp_label = nct6779_temp_label;
data->temp_mask = NCT6791_TEMP_MASK;
break;
case nct6792:
data->temp_label = nct6792_temp_label;
data->temp_mask = NCT6792_TEMP_MASK;
break;
case nct6793:
data->temp_label = nct6793_temp_label;
data->temp_mask = NCT6793_TEMP_MASK;
break;
case nct6795:
data->temp_label = nct6795_temp_label;
data->temp_mask = NCT6795_TEMP_MASK;
break;
}
data->REG_CONFIG = NCT6775_REG_CONFIG;
data->REG_VBAT = NCT6775_REG_VBAT;
data->REG_DIODE = NCT6775_REG_DIODE;
data->DIODE_MASK = NCT6775_DIODE_MASK;
data->REG_VIN = NCT6779_REG_IN;
data->REG_IN_MINMAX[0] = NCT6775_REG_IN_MIN;
data->REG_IN_MINMAX[1] = NCT6775_REG_IN_MAX;
data->REG_TARGET = NCT6775_REG_TARGET;
data->REG_FAN = NCT6779_REG_FAN;
data->REG_FAN_MODE = NCT6775_REG_FAN_MODE;
data->REG_FAN_MIN = NCT6776_REG_FAN_MIN;
data->REG_FAN_PULSES = NCT6779_REG_FAN_PULSES;
data->FAN_PULSE_SHIFT = NCT6775_FAN_PULSE_SHIFT;
data->REG_FAN_TIME[0] = NCT6775_REG_FAN_STOP_TIME;
data->REG_FAN_TIME[1] = NCT6776_REG_FAN_STEP_UP_TIME;
data->REG_FAN_TIME[2] = NCT6776_REG_FAN_STEP_DOWN_TIME;
data->REG_TOLERANCE_H = NCT6776_REG_TOLERANCE_H;
data->REG_PWM[0] = NCT6775_REG_PWM;
data->REG_PWM[1] = NCT6775_REG_FAN_START_OUTPUT;
data->REG_PWM[2] = NCT6775_REG_FAN_STOP_OUTPUT;
data->REG_PWM[5] = NCT6791_REG_WEIGHT_DUTY_STEP;
data->REG_PWM[6] = NCT6791_REG_WEIGHT_DUTY_BASE;
data->REG_PWM_READ = NCT6775_REG_PWM_READ;
data->REG_PWM_MODE = NCT6776_REG_PWM_MODE;
data->PWM_MODE_MASK = NCT6776_PWM_MODE_MASK;
data->REG_AUTO_TEMP = NCT6775_REG_AUTO_TEMP;
data->REG_AUTO_PWM = NCT6775_REG_AUTO_PWM;
data->REG_CRITICAL_TEMP = NCT6775_REG_CRITICAL_TEMP;
data->REG_CRITICAL_TEMP_TOLERANCE
= NCT6775_REG_CRITICAL_TEMP_TOLERANCE;
data->REG_CRITICAL_PWM_ENABLE = NCT6779_REG_CRITICAL_PWM_ENABLE;
data->CRITICAL_PWM_ENABLE_MASK
= NCT6779_CRITICAL_PWM_ENABLE_MASK;
data->REG_CRITICAL_PWM = NCT6779_REG_CRITICAL_PWM;
data->REG_TEMP_OFFSET = NCT6779_REG_TEMP_OFFSET;
data->REG_TEMP_SOURCE = NCT6775_REG_TEMP_SOURCE;
data->REG_TEMP_SEL = NCT6775_REG_TEMP_SEL;
data->REG_WEIGHT_TEMP_SEL = NCT6791_REG_WEIGHT_TEMP_SEL;
data->REG_WEIGHT_TEMP[0] = NCT6791_REG_WEIGHT_TEMP_STEP;
data->REG_WEIGHT_TEMP[1] = NCT6791_REG_WEIGHT_TEMP_STEP_TOL;
data->REG_WEIGHT_TEMP[2] = NCT6791_REG_WEIGHT_TEMP_BASE;
data->REG_ALARM = NCT6791_REG_ALARM;
if (data->kind == nct6791)
data->REG_BEEP = NCT6776_REG_BEEP;
else
data->REG_BEEP = NCT6792_REG_BEEP;
reg_temp = NCT6779_REG_TEMP;
num_reg_temp = ARRAY_SIZE(NCT6779_REG_TEMP);
if (data->kind == nct6791) {
reg_temp_mon = NCT6779_REG_TEMP_MON;
num_reg_temp_mon = ARRAY_SIZE(NCT6779_REG_TEMP_MON);
} else {
reg_temp_mon = NCT6792_REG_TEMP_MON;
num_reg_temp_mon = ARRAY_SIZE(NCT6792_REG_TEMP_MON);
}
reg_temp_over = NCT6779_REG_TEMP_OVER;
reg_temp_hyst = NCT6779_REG_TEMP_HYST;
reg_temp_config = NCT6779_REG_TEMP_CONFIG;
reg_temp_alternate = NCT6779_REG_TEMP_ALTERNATE;
reg_temp_crit = NCT6779_REG_TEMP_CRIT;
break;
default:
return -ENODEV;
}
data->have_in = BIT(data->in_num) - 1;
data->have_temp = 0;
mask = 0;
available = 0;
for (i = 0; i < num_reg_temp; i++) {
if (reg_temp[i] == 0)
continue;
src = nct6775_read_value(data, data->REG_TEMP_SOURCE[i]) & 0x1f;
if (!src || (mask & BIT(src)))
available |= BIT(i);
mask |= BIT(src);
}
add_temp_sensors(data, data->REG_TEMP_SEL, &available, &mask);
add_temp_sensors(data, data->REG_WEIGHT_TEMP_SEL, &available, &mask);
mask = 0;
s = NUM_TEMP_FIXED;
for (i = 0; i < num_reg_temp; i++) {
if (reg_temp[i] == 0)
continue;
src = nct6775_read_value(data, data->REG_TEMP_SOURCE[i]) & 0x1f;
if (!src || (mask & BIT(src)))
continue;
if (!(data->temp_mask & BIT(src))) {
dev_info(dev,
"Invalid temperature source %d at index %d, source register 0x%x, temp register 0x%x\n",
src, i, data->REG_TEMP_SOURCE[i], reg_temp[i]);
continue;
}
mask |= BIT(src);
if (src <= data->temp_fixed_num) {
data->have_temp |= BIT(src - 1);
data->have_temp_fixed |= BIT(src - 1);
data->reg_temp[0][src - 1] = reg_temp[i];
data->reg_temp[1][src - 1] = reg_temp_over[i];
data->reg_temp[2][src - 1] = reg_temp_hyst[i];
if (reg_temp_crit_h && reg_temp_crit_h[i])
data->reg_temp[3][src - 1] = reg_temp_crit_h[i];
else if (reg_temp_crit[src - 1])
data->reg_temp[3][src - 1]
= reg_temp_crit[src - 1];
if (reg_temp_crit_l && reg_temp_crit_l[i])
data->reg_temp[4][src - 1] = reg_temp_crit_l[i];
data->reg_temp_config[src - 1] = reg_temp_config[i];
data->temp_src[src - 1] = src;
continue;
}
if (s >= NUM_TEMP)
continue;
data->have_temp |= BIT(s);
data->reg_temp[0][s] = reg_temp[i];
data->reg_temp[1][s] = reg_temp_over[i];
data->reg_temp[2][s] = reg_temp_hyst[i];
data->reg_temp_config[s] = reg_temp_config[i];
if (reg_temp_crit_h && reg_temp_crit_h[i])
data->reg_temp[3][s] = reg_temp_crit_h[i];
else if (reg_temp_crit[src - 1])
data->reg_temp[3][s] = reg_temp_crit[src - 1];
if (reg_temp_crit_l && reg_temp_crit_l[i])
data->reg_temp[4][s] = reg_temp_crit_l[i];
data->temp_src[s] = src;
s++;
}
for (i = 0; i < num_reg_temp_mon; i++) {
if (reg_temp_mon[i] == 0)
continue;
src = nct6775_read_value(data, data->REG_TEMP_SEL[i]) & 0x1f;
if (!src)
continue;
if (!(data->temp_mask & BIT(src))) {
dev_info(dev,
"Invalid temperature source %d at index %d, source register 0x%x, temp register 0x%x\n",
src, i, data->REG_TEMP_SEL[i],
reg_temp_mon[i]);
continue;
}
if (src != TEMP_SOURCE_VIRTUAL) {
if (mask & BIT(src))
continue;
mask |= BIT(src);
}
if (src <= data->temp_fixed_num) {
if (data->have_temp & BIT(src - 1))
continue;
data->have_temp |= BIT(src - 1);
data->have_temp_fixed |= BIT(src - 1);
data->reg_temp[0][src - 1] = reg_temp_mon[i];
data->temp_src[src - 1] = src;
continue;
}
if (s >= NUM_TEMP)
continue;
data->have_temp |= BIT(s);
data->reg_temp[0][s] = reg_temp_mon[i];
data->temp_src[s] = src;
s++;
}
#ifdef USE_ALTERNATE
for (i = 0; i < 32; i++) {
if (!(data->temp_mask & BIT(i + 1)))
continue;
if (!reg_temp_alternate[i])
continue;
if (mask & BIT(i + 1))
continue;
if (i < data->temp_fixed_num) {
if (data->have_temp & BIT(i))
continue;
data->have_temp |= BIT(i);
data->have_temp_fixed |= BIT(i);
data->reg_temp[0][i] = reg_temp_alternate[i];
if (i < num_reg_temp) {
data->reg_temp[1][i] = reg_temp_over[i];
data->reg_temp[2][i] = reg_temp_hyst[i];
}
data->temp_src[i] = i + 1;
continue;
}
if (s >= NUM_TEMP)
break;
data->have_temp |= BIT(s);
data->reg_temp[0][s] = reg_temp_alternate[i];
data->temp_src[s] = i + 1;
s++;
}
#endif
nct6775_init_device(data);
err = superio_enter(sio_data->sioreg);
if (err)
return err;
cr2a = superio_inb(sio_data->sioreg, 0x2a);
switch (data->kind) {
case nct6775:
data->have_vid = (cr2a & 0x40);
break;
case nct6776:
data->have_vid = (cr2a & 0x60) == 0x40;
break;
case nct6106:
case nct6779:
case nct6791:
case nct6792:
case nct6793:
case nct6795:
break;
}
if (data->have_vid) {
superio_select(sio_data->sioreg, NCT6775_LD_VID);
data->vid = superio_inb(sio_data->sioreg, 0xe3);
data->vrm = vid_which_vrm();
}
if (fan_debounce) {
u8 tmp;
superio_select(sio_data->sioreg, NCT6775_LD_HWM);
tmp = superio_inb(sio_data->sioreg,
NCT6775_REG_CR_FAN_DEBOUNCE);
switch (data->kind) {
case nct6106:
tmp |= 0xe0;
break;
case nct6775:
tmp |= 0x1e;
break;
case nct6776:
case nct6779:
tmp |= 0x3e;
break;
case nct6791:
case nct6792:
case nct6793:
case nct6795:
tmp |= 0x7e;
break;
}
superio_outb(sio_data->sioreg, NCT6775_REG_CR_FAN_DEBOUNCE,
tmp);
dev_info(&pdev->dev, "Enabled fan debounce for chip %s\n",
data->name);
}
nct6775_check_fan_inputs(data);
superio_exit(sio_data->sioreg);
nct6775_init_fan_common(dev, data);
group = nct6775_create_attr_group(dev, &nct6775_pwm_template_group,
data->pwm_num);
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[num_attr_groups++] = group;
group = nct6775_create_attr_group(dev, &nct6775_in_template_group,
fls(data->have_in));
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[num_attr_groups++] = group;
group = nct6775_create_attr_group(dev, &nct6775_fan_template_group,
fls(data->has_fan));
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[num_attr_groups++] = group;
group = nct6775_create_attr_group(dev, &nct6775_temp_template_group,
fls(data->have_temp));
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[num_attr_groups++] = group;
data->groups[num_attr_groups++] = &nct6775_group_other;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, data->name,
data, data->groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
static void nct6791_enable_io_mapping(int sioaddr)
{
int val;
val = superio_inb(sioaddr, NCT6791_REG_HM_IO_SPACE_LOCK_ENABLE);
if (val & 0x10) {
pr_info("Enabling hardware monitor logical device mappings.\n");
superio_outb(sioaddr, NCT6791_REG_HM_IO_SPACE_LOCK_ENABLE,
val & ~0x10);
}
}
static int __maybe_unused nct6775_suspend(struct device *dev)
{
struct nct6775_data *data = nct6775_update_device(dev);
mutex_lock(&data->update_lock);
data->vbat = nct6775_read_value(data, data->REG_VBAT);
if (data->kind == nct6775) {
data->fandiv1 = nct6775_read_value(data, NCT6775_REG_FANDIV1);
data->fandiv2 = nct6775_read_value(data, NCT6775_REG_FANDIV2);
}
mutex_unlock(&data->update_lock);
return 0;
}
static int __maybe_unused nct6775_resume(struct device *dev)
{
struct nct6775_data *data = dev_get_drvdata(dev);
int sioreg = data->sioreg;
int i, j, err = 0;
u8 reg;
mutex_lock(&data->update_lock);
data->bank = 0xff;
err = superio_enter(sioreg);
if (err)
goto abort;
superio_select(sioreg, NCT6775_LD_HWM);
reg = superio_inb(sioreg, SIO_REG_ENABLE);
if (reg != data->sio_reg_enable)
superio_outb(sioreg, SIO_REG_ENABLE, data->sio_reg_enable);
if (data->kind == nct6791 || data->kind == nct6792 ||
data->kind == nct6793 || data->kind == nct6795)
nct6791_enable_io_mapping(sioreg);
superio_exit(sioreg);
for (i = 0; i < data->in_num; i++) {
if (!(data->have_in & BIT(i)))
continue;
nct6775_write_value(data, data->REG_IN_MINMAX[0][i],
data->in[i][1]);
nct6775_write_value(data, data->REG_IN_MINMAX[1][i],
data->in[i][2]);
}
for (i = 0; i < ARRAY_SIZE(data->fan_min); i++) {
if (!(data->has_fan_min & BIT(i)))
continue;
nct6775_write_value(data, data->REG_FAN_MIN[i],
data->fan_min[i]);
}
for (i = 0; i < NUM_TEMP; i++) {
if (!(data->have_temp & BIT(i)))
continue;
for (j = 1; j < ARRAY_SIZE(data->reg_temp); j++)
if (data->reg_temp[j][i])
nct6775_write_temp(data, data->reg_temp[j][i],
data->temp[j][i]);
}
nct6775_write_value(data, data->REG_VBAT, data->vbat);
if (data->kind == nct6775) {
nct6775_write_value(data, NCT6775_REG_FANDIV1, data->fandiv1);
nct6775_write_value(data, NCT6775_REG_FANDIV2, data->fandiv2);
}
abort:
data->valid = false;
mutex_unlock(&data->update_lock);
return err;
}
static int __init nct6775_find(int sioaddr, struct nct6775_sio_data *sio_data)
{
u16 val;
int err;
int addr;
err = superio_enter(sioaddr);
if (err)
return err;
val = (superio_inb(sioaddr, SIO_REG_DEVID) << 8) |
superio_inb(sioaddr, SIO_REG_DEVID + 1);
if (force_id && val != 0xffff)
val = force_id;
switch (val & SIO_ID_MASK) {
case SIO_NCT6106_ID:
sio_data->kind = nct6106;
break;
case SIO_NCT6775_ID:
sio_data->kind = nct6775;
break;
case SIO_NCT6776_ID:
sio_data->kind = nct6776;
break;
case SIO_NCT6779_ID:
sio_data->kind = nct6779;
break;
case SIO_NCT6791_ID:
sio_data->kind = nct6791;
break;
case SIO_NCT6792_ID:
sio_data->kind = nct6792;
break;
case SIO_NCT6793_ID:
sio_data->kind = nct6793;
break;
case SIO_NCT6795_ID:
sio_data->kind = nct6795;
break;
default:
if (val != 0xffff)
pr_debug("unsupported chip ID: 0x%04x\n", val);
superio_exit(sioaddr);
return -ENODEV;
}
superio_select(sioaddr, NCT6775_LD_HWM);
val = (superio_inb(sioaddr, SIO_REG_ADDR) << 8)
| superio_inb(sioaddr, SIO_REG_ADDR + 1);
addr = val & IOREGION_ALIGNMENT;
if (addr == 0) {
pr_err("Refusing to enable a Super-I/O device with a base I/O port 0\n");
superio_exit(sioaddr);
return -ENODEV;
}
val = superio_inb(sioaddr, SIO_REG_ENABLE);
if (!(val & 0x01)) {
pr_warn("Forcibly enabling Super-I/O. Sensor is probably unusable.\n");
superio_outb(sioaddr, SIO_REG_ENABLE, val | 0x01);
}
if (sio_data->kind == nct6791 || sio_data->kind == nct6792 ||
sio_data->kind == nct6793 || sio_data->kind == nct6795)
nct6791_enable_io_mapping(sioaddr);
superio_exit(sioaddr);
pr_info("Found %s or compatible chip at %#x:%#x\n",
nct6775_sio_names[sio_data->kind], sioaddr, addr);
sio_data->sioreg = sioaddr;
return addr;
}
static int __init sensors_nct6775_init(void)
{
int i, err;
bool found = false;
int address;
struct resource res;
struct nct6775_sio_data sio_data;
int sioaddr[2] = { 0x2e, 0x4e };
err = platform_driver_register(&nct6775_driver);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(pdev); i++) {
address = nct6775_find(sioaddr[i], &sio_data);
if (address <= 0)
continue;
found = true;
pdev[i] = platform_device_alloc(DRVNAME, address);
if (!pdev[i]) {
err = -ENOMEM;
goto exit_device_unregister;
}
err = platform_device_add_data(pdev[i], &sio_data,
sizeof(struct nct6775_sio_data));
if (err)
goto exit_device_put;
memset(&res, 0, sizeof(res));
res.name = DRVNAME;
res.start = address + IOREGION_OFFSET;
res.end = address + IOREGION_OFFSET + IOREGION_LENGTH - 1;
res.flags = IORESOURCE_IO;
err = acpi_check_resource_conflict(&res);
if (err) {
platform_device_put(pdev[i]);
pdev[i] = NULL;
continue;
}
err = platform_device_add_resources(pdev[i], &res, 1);
if (err)
goto exit_device_put;
err = platform_device_add(pdev[i]);
if (err)
goto exit_device_put;
}
if (!found) {
err = -ENODEV;
goto exit_unregister;
}
return 0;
exit_device_put:
platform_device_put(pdev[i]);
exit_device_unregister:
while (--i >= 0) {
if (pdev[i])
platform_device_unregister(pdev[i]);
}
exit_unregister:
platform_driver_unregister(&nct6775_driver);
return err;
}
static void __exit sensors_nct6775_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(pdev); i++) {
if (pdev[i])
platform_device_unregister(pdev[i]);
}
platform_driver_unregister(&nct6775_driver);
}
