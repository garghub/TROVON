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
static struct attribute_group *
nct6683_create_attr_group(struct device *dev, struct sensor_template_group *tg,
int repeat)
{
struct sensor_device_attribute_2 *a2;
struct sensor_device_attribute *a;
struct sensor_device_template **t;
struct sensor_device_attr_u *su;
struct attribute_group *group;
struct attribute **attrs;
int i, j, count;
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
for (j = 0; *t != NULL; j++) {
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
static inline long in_from_reg(u16 reg, u8 src)
{
int scale = 16;
if (src == MON_SRC_VCC || src == MON_SRC_VSB || src == MON_SRC_AVSB ||
src == MON_SRC_VBAT)
scale <<= 1;
return reg * scale;
}
static inline u16 in_to_reg(u32 val, u8 src)
{
int scale = 16;
if (src == MON_SRC_VCC || src == MON_SRC_VSB || src == MON_SRC_AVSB ||
src == MON_SRC_VBAT)
scale <<= 1;
return clamp_val(DIV_ROUND_CLOSEST(val, scale), 0, 127);
}
static u16 nct6683_read(struct nct6683_data *data, u16 reg)
{
int res;
outb_p(0xff, data->addr + EC_PAGE_REG);
outb_p(reg >> 8, data->addr + EC_PAGE_REG);
outb_p(reg & 0xff, data->addr + EC_INDEX_REG);
res = inb_p(data->addr + EC_DATA_REG);
return res;
}
static u16 nct6683_read16(struct nct6683_data *data, u16 reg)
{
return (nct6683_read(data, reg) << 8) | nct6683_read(data, reg + 1);
}
static void nct6683_write(struct nct6683_data *data, u16 reg, u16 value)
{
outb_p(0xff, data->addr + EC_PAGE_REG);
outb_p(reg >> 8, data->addr + EC_PAGE_REG);
outb_p(reg & 0xff, data->addr + EC_INDEX_REG);
outb_p(value & 0xff, data->addr + EC_DATA_REG);
}
static int get_in_reg(struct nct6683_data *data, int nr, int index)
{
int ch = data->in_index[index];
int reg = -EINVAL;
switch (nr) {
case 0:
reg = NCT6683_REG_MON(ch);
break;
case 1:
if (data->customer_id != NCT6683_CUSTOMER_ID_INTEL)
reg = NCT6683_REG_MON_LOW(ch);
break;
case 2:
if (data->customer_id != NCT6683_CUSTOMER_ID_INTEL)
reg = NCT6683_REG_MON_HIGH(ch);
break;
default:
break;
}
return reg;
}
static int get_temp_reg(struct nct6683_data *data, int nr, int index)
{
int ch = data->temp_index[index];
int reg = -EINVAL;
switch (data->customer_id) {
case NCT6683_CUSTOMER_ID_INTEL:
switch (nr) {
default:
case 1:
reg = NCT6683_REG_INTEL_TEMP_MAX(ch);
break;
case 3:
reg = NCT6683_REG_INTEL_TEMP_CRIT(ch);
break;
}
break;
default:
switch (nr) {
default:
case 0:
reg = NCT6683_REG_MON_LOW(ch);
break;
case 1:
reg = NCT6683_REG_TEMP_MAX(ch);
break;
case 2:
reg = NCT6683_REG_TEMP_HYST(ch);
break;
case 3:
reg = NCT6683_REG_MON_HIGH(ch);
break;
}
break;
}
return reg;
}
static void nct6683_update_pwm(struct device *dev)
{
struct nct6683_data *data = dev_get_drvdata(dev);
int i;
for (i = 0; i < NCT6683_NUM_REG_PWM; i++) {
if (!(data->have_pwm & (1 << i)))
continue;
data->pwm[i] = nct6683_read(data, NCT6683_REG_PWM(i));
}
}
static struct nct6683_data *nct6683_update_device(struct device *dev)
{
struct nct6683_data *data = dev_get_drvdata(dev);
int i, j;
mutex_lock(&data->update_lock);
if (time_after(jiffies, data->last_updated + HZ) || !data->valid) {
for (i = 0; i < data->in_num; i++) {
for (j = 0; j < 3; j++) {
int reg = get_in_reg(data, j, i);
if (reg >= 0)
data->in[j][i] =
nct6683_read(data, reg);
}
}
for (i = 0; i < data->temp_num; i++) {
u8 ch = data->temp_index[i];
data->temp_in[i] = nct6683_read16(data,
NCT6683_REG_MON(ch));
for (j = 0; j < 4; j++) {
int reg = get_temp_reg(data, j, i);
if (reg >= 0)
data->temp[j][i] =
nct6683_read(data, reg);
}
}
for (i = 0; i < ARRAY_SIZE(data->rpm); i++) {
if (!(data->have_fan & (1 << i)))
continue;
data->rpm[i] = nct6683_read16(data,
NCT6683_REG_FAN_RPM(i));
data->fan_min[i] = nct6683_read16(data,
NCT6683_REG_FAN_MIN(i));
}
nct6683_update_pwm(dev);
data->last_updated = jiffies;
data->valid = true;
}
mutex_unlock(&data->update_lock);
return data;
}
static ssize_t
show_in_label(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6683_data *data = nct6683_update_device(dev);
int nr = sattr->index;
return sprintf(buf, "%s\n", nct6683_mon_label[data->in_src[nr]]);
}
static ssize_t
show_in_reg(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct6683_data *data = nct6683_update_device(dev);
int index = sattr->index;
int nr = sattr->nr;
return sprintf(buf, "%ld\n",
in_from_reg(data->in[index][nr], data->in_index[index]));
}
static umode_t nct6683_in_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6683_data *data = dev_get_drvdata(dev);
int nr = index % 4;
if ((nr == 2 || nr == 3) &&
data->customer_id == NCT6683_CUSTOMER_ID_INTEL)
return 0;
return attr->mode;
}
static ssize_t
show_fan(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6683_data *data = nct6683_update_device(dev);
return sprintf(buf, "%d\n", data->rpm[sattr->index]);
}
static ssize_t
show_fan_min(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6683_data *data = nct6683_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%d\n", data->fan_min[nr]);
}
static ssize_t
show_fan_pulses(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6683_data *data = nct6683_update_device(dev);
return sprintf(buf, "%d\n",
((data->fanin_cfg[sattr->index] >> 5) & 0x03) + 1);
}
static umode_t nct6683_fan_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6683_data *data = dev_get_drvdata(dev);
int fan = index / 3;
int nr = index % 3;
if (!(data->have_fan & (1 << fan)))
return 0;
if (nr == 2 && data->customer_id == NCT6683_CUSTOMER_ID_INTEL)
return 0;
return attr->mode;
}
static ssize_t
show_temp_label(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6683_data *data = nct6683_update_device(dev);
int nr = sattr->index;
return sprintf(buf, "%s\n", nct6683_mon_label[data->temp_src[nr]]);
}
static ssize_t
show_temp8(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
struct nct6683_data *data = nct6683_update_device(dev);
int index = sattr->index;
int nr = sattr->nr;
return sprintf(buf, "%d\n", data->temp[index][nr] * 1000);
}
static ssize_t
show_temp_hyst(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6683_data *data = nct6683_update_device(dev);
int nr = sattr->index;
int temp = data->temp[1][nr] - data->temp[2][nr];
return sprintf(buf, "%d\n", temp * 1000);
}
static ssize_t
show_temp16(struct device *dev, struct device_attribute *attr, char *buf)
{
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
struct nct6683_data *data = nct6683_update_device(dev);
int index = sattr->index;
return sprintf(buf, "%d\n", (data->temp_in[index] / 128) * 500);
}
static int get_temp_type(u8 src)
{
if (src >= 0x02 && src <= 0x07)
return 3;
else if (src >= 0x08 && src <= 0x18)
return 4;
else if (src >= 0x20 && src <= 0x2b)
return 6;
else if (src >= 0x42 && src <= 0x49)
return 5;
return 0;
}
static ssize_t
show_temp_type(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6683_data *data = nct6683_update_device(dev);
struct sensor_device_attribute *sattr = to_sensor_dev_attr(attr);
int nr = sattr->index;
return sprintf(buf, "%d\n", get_temp_type(data->temp_src[nr]));
}
static umode_t nct6683_temp_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6683_data *data = dev_get_drvdata(dev);
int temp = index / 7;
int nr = index % 7;
if ((nr == 2 || nr == 4) &&
data->customer_id == NCT6683_CUSTOMER_ID_INTEL)
return 0;
if (nr == 6 && get_temp_type(data->temp_src[temp]) == 0)
return 0;
return attr->mode;
}
static ssize_t
show_pwm(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6683_data *data = nct6683_update_device(dev);
struct sensor_device_attribute_2 *sattr = to_sensor_dev_attr_2(attr);
int index = sattr->index;
return sprintf(buf, "%d\n", data->pwm[index]);
}
static umode_t nct6683_pwm_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = container_of(kobj, struct device, kobj);
struct nct6683_data *data = dev_get_drvdata(dev);
int pwm = index;
if (!(data->have_pwm & (1 << pwm)))
return 0;
return attr->mode;
}
static ssize_t
show_global_beep(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6683_data *data = dev_get_drvdata(dev);
int ret;
u8 reg;
mutex_lock(&data->update_lock);
ret = superio_enter(data->sioreg);
if (ret)
goto error;
superio_select(data->sioreg, NCT6683_LD_HWM);
reg = superio_inb(data->sioreg, NCT6683_REG_CR_BEEP);
superio_exit(data->sioreg);
mutex_unlock(&data->update_lock);
return sprintf(buf, "%u\n", !!(reg & NCT6683_CR_BEEP_MASK));
error:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t
store_global_beep(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6683_data *data = dev_get_drvdata(dev);
unsigned long val;
u8 reg;
int ret;
if (kstrtoul(buf, 10, &val) || (val != 0 && val != 1))
return -EINVAL;
mutex_lock(&data->update_lock);
ret = superio_enter(data->sioreg);
if (ret) {
count = ret;
goto error;
}
superio_select(data->sioreg, NCT6683_LD_HWM);
reg = superio_inb(data->sioreg, NCT6683_REG_CR_BEEP);
if (val)
reg |= NCT6683_CR_BEEP_MASK;
else
reg &= ~NCT6683_CR_BEEP_MASK;
superio_outb(data->sioreg, NCT6683_REG_CR_BEEP, reg);
superio_exit(data->sioreg);
error:
mutex_unlock(&data->update_lock);
return count;
}
static ssize_t
show_caseopen(struct device *dev, struct device_attribute *attr, char *buf)
{
struct nct6683_data *data = dev_get_drvdata(dev);
int ret;
u8 reg;
mutex_lock(&data->update_lock);
ret = superio_enter(data->sioreg);
if (ret)
goto error;
superio_select(data->sioreg, NCT6683_LD_ACPI);
reg = superio_inb(data->sioreg, NCT6683_REG_CR_CASEOPEN);
superio_exit(data->sioreg);
mutex_unlock(&data->update_lock);
return sprintf(buf, "%u\n", !(reg & NCT6683_CR_CASEOPEN_MASK));
error:
mutex_unlock(&data->update_lock);
return ret;
}
static ssize_t
clear_caseopen(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct nct6683_data *data = dev_get_drvdata(dev);
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
superio_select(data->sioreg, NCT6683_LD_ACPI);
reg = superio_inb(data->sioreg, NCT6683_REG_CR_CASEOPEN);
reg |= NCT6683_CR_CASEOPEN_MASK;
superio_outb(data->sioreg, NCT6683_REG_CR_CASEOPEN, reg);
reg &= ~NCT6683_CR_CASEOPEN_MASK;
superio_outb(data->sioreg, NCT6683_REG_CR_CASEOPEN, reg);
superio_exit(data->sioreg);
data->valid = false;
error:
mutex_unlock(&data->update_lock);
return count;
}
static inline void nct6683_init_device(struct nct6683_data *data)
{
u8 tmp;
tmp = nct6683_read(data, NCT6683_HWM_CFG);
if (!(tmp & 0x80))
nct6683_write(data, NCT6683_HWM_CFG, tmp | 0x80);
}
static void
nct6683_setup_fans(struct nct6683_data *data)
{
int i;
u8 reg;
for (i = 0; i < NCT6683_NUM_REG_FAN; i++) {
reg = nct6683_read(data, NCT6683_REG_FANIN_CFG(i));
if (reg & 0x80)
data->have_fan |= 1 << i;
data->fanin_cfg[i] = reg;
}
for (i = 0; i < NCT6683_NUM_REG_PWM; i++) {
reg = nct6683_read(data, NCT6683_REG_FANOUT_CFG(i));
if (reg & 0x80)
data->have_pwm |= 1 << i;
data->fanout_cfg[i] = reg;
}
}
static void nct6683_setup_sensors(struct nct6683_data *data)
{
u8 reg;
int i;
data->temp_num = 0;
data->in_num = 0;
for (i = 0; i < NCT6683_NUM_REG_MON; i++) {
reg = nct6683_read(data, NCT6683_REG_MON_CFG(i)) & 0x7f;
if (reg >= NUM_MON_LABELS)
continue;
if (nct6683_mon_label[reg] == NULL)
continue;
if (reg < MON_VOLTAGE_START) {
data->temp_index[data->temp_num] = i;
data->temp_src[data->temp_num] = reg;
data->temp_num++;
} else {
data->in_index[data->in_num] = i;
data->in_src[data->in_num] = reg;
data->in_num++;
}
}
}
static int nct6683_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct nct6683_sio_data *sio_data = dev->platform_data;
struct attribute_group *group;
struct nct6683_data *data;
struct device *hwmon_dev;
struct resource *res;
int groups = 0;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!devm_request_region(dev, res->start, IOREGION_LENGTH, DRVNAME))
return -EBUSY;
data = devm_kzalloc(dev, sizeof(struct nct6683_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->kind = sio_data->kind;
data->sioreg = sio_data->sioreg;
data->addr = res->start;
mutex_init(&data->update_lock);
platform_set_drvdata(pdev, data);
data->customer_id = nct6683_read16(data, NCT6683_REG_CUSTOMER_ID);
nct6683_init_device(data);
nct6683_setup_fans(data);
nct6683_setup_sensors(data);
if (data->have_pwm) {
group = nct6683_create_attr_group(dev,
&nct6683_pwm_template_group,
fls(data->have_pwm));
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[groups++] = group;
}
if (data->in_num) {
group = nct6683_create_attr_group(dev,
&nct6683_in_template_group,
data->in_num);
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[groups++] = group;
}
if (data->have_fan) {
group = nct6683_create_attr_group(dev,
&nct6683_fan_template_group,
fls(data->have_fan));
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[groups++] = group;
}
if (data->temp_num) {
group = nct6683_create_attr_group(dev,
&nct6683_temp_template_group,
data->temp_num);
if (IS_ERR(group))
return PTR_ERR(group);
data->groups[groups++] = group;
}
data->groups[groups++] = &nct6683_group_other;
dev_info(dev, "%s EC firmware version %d.%d build %02x/%02x/%02x\n",
nct6683_chip_names[data->kind],
nct6683_read(data, NCT6683_REG_VERSION_HI),
nct6683_read(data, NCT6683_REG_VERSION_LO),
nct6683_read(data, NCT6683_REG_BUILD_MONTH),
nct6683_read(data, NCT6683_REG_BUILD_DAY),
nct6683_read(data, NCT6683_REG_BUILD_YEAR));
hwmon_dev = devm_hwmon_device_register_with_groups(dev,
nct6683_device_names[data->kind], data, data->groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
static int nct6683_suspend(struct device *dev)
{
struct nct6683_data *data = nct6683_update_device(dev);
mutex_lock(&data->update_lock);
data->hwm_cfg = nct6683_read(data, NCT6683_HWM_CFG);
mutex_unlock(&data->update_lock);
return 0;
}
static int nct6683_resume(struct device *dev)
{
struct nct6683_data *data = dev_get_drvdata(dev);
mutex_lock(&data->update_lock);
nct6683_write(data, NCT6683_HWM_CFG, data->hwm_cfg);
data->valid = false;
mutex_unlock(&data->update_lock);
return 0;
}
static int __init nct6683_find(int sioaddr, struct nct6683_sio_data *sio_data)
{
const char *board_vendor;
int addr;
u16 val;
int err;
if (!force) {
board_vendor = dmi_get_system_info(DMI_BOARD_VENDOR);
if (!board_vendor || strcmp(board_vendor, "Intel Corporation"))
return -ENODEV;
}
err = superio_enter(sioaddr);
if (err)
return err;
val = (superio_inb(sioaddr, SIO_REG_DEVID) << 8)
| superio_inb(sioaddr, SIO_REG_DEVID + 1);
switch (val & SIO_ID_MASK) {
case SIO_NCT6683_ID:
sio_data->kind = nct6683;
break;
default:
if (val != 0xffff)
pr_debug("unsupported chip ID: 0x%04x\n", val);
goto fail;
}
superio_select(sioaddr, NCT6683_LD_HWM);
val = (superio_inb(sioaddr, SIO_REG_ADDR) << 8)
| superio_inb(sioaddr, SIO_REG_ADDR + 1);
addr = val & IOREGION_ALIGNMENT;
if (addr == 0) {
pr_err("EC base I/O port unconfigured\n");
goto fail;
}
val = superio_inb(sioaddr, SIO_REG_ENABLE);
if (!(val & 0x01)) {
pr_err("EC is disabled\n");
goto fail;
}
superio_exit(sioaddr);
pr_info("Found %s or compatible chip at %#x:%#x\n",
nct6683_chip_names[sio_data->kind], sioaddr, addr);
sio_data->sioreg = sioaddr;
return addr;
fail:
superio_exit(sioaddr);
return -ENODEV;
}
static int __init sensors_nct6683_init(void)
{
struct nct6683_sio_data sio_data;
int sioaddr[2] = { 0x2e, 0x4e };
struct resource res;
bool found = false;
int address;
int i, err;
err = platform_driver_register(&nct6683_driver);
if (err)
return err;
for (i = 0; i < ARRAY_SIZE(pdev); i++) {
address = nct6683_find(sioaddr[i], &sio_data);
if (address <= 0)
continue;
found = true;
pdev[i] = platform_device_alloc(DRVNAME, address);
if (!pdev[i]) {
err = -ENOMEM;
goto exit_device_unregister;
}
err = platform_device_add_data(pdev[i], &sio_data,
sizeof(struct nct6683_sio_data));
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
platform_driver_unregister(&nct6683_driver);
return err;
}
static void __exit sensors_nct6683_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(pdev); i++) {
if (pdev[i])
platform_device_unregister(pdev[i]);
}
platform_driver_unregister(&nct6683_driver);
}
