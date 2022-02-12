static inline void superio_outb(int sioaddr, int reg, int val)
{
outb(reg, sioaddr);
outb(val, sioaddr + 1);
}
static inline int superio_inb(int sioaddr, int reg)
{
outb(reg, sioaddr);
return inb(sioaddr + 1);
}
static inline void superio_exit(int sioaddr)
{
outb(0x02, sioaddr);
outb(0x02, sioaddr + 1);
}
static inline int pc87427_read8(struct pc87427_data *data, u8 ldi, u8 reg)
{
return inb(data->address[ldi] + reg);
}
static inline int pc87427_read8_bank(struct pc87427_data *data, u8 ldi,
u8 bank, u8 reg)
{
outb(bank, data->address[ldi] + PC87427_REG_BANK);
return inb(data->address[ldi] + reg);
}
static inline void pc87427_write8_bank(struct pc87427_data *data, u8 ldi,
u8 bank, u8 reg, u8 value)
{
outb(bank, data->address[ldi] + PC87427_REG_BANK);
outb(value, data->address[ldi] + reg);
}
static void pc87427_readall_fan(struct pc87427_data *data, u8 nr)
{
int iobase = data->address[LD_FAN];
outb(BANK_FM(nr), iobase + PC87427_REG_BANK);
data->fan[nr] = inw(iobase + PC87427_REG_FAN);
data->fan_min[nr] = inw(iobase + PC87427_REG_FAN_MIN);
data->fan_status[nr] = inb(iobase + PC87427_REG_FAN_STATUS);
outb(data->fan_status[nr], iobase + PC87427_REG_FAN_STATUS);
}
static inline unsigned long fan_from_reg(u16 reg)
{
reg &= 0xfffc;
if (reg == 0x0000 || reg == 0xfffc)
return 0;
return 5400000UL / reg;
}
static inline u16 fan_to_reg(unsigned long val)
{
if (val < 83UL)
return 0xffff;
if (val >= 1350000UL)
return 0x0004;
return ((1350000UL + val / 2) / val) << 2;
}
static void pc87427_readall_pwm(struct pc87427_data *data, u8 nr)
{
int iobase = data->address[LD_FAN];
outb(BANK_FC(nr), iobase + PC87427_REG_BANK);
data->pwm_enable[nr] = inb(iobase + PC87427_REG_PWM_ENABLE);
data->pwm[nr] = inb(iobase + PC87427_REG_PWM_DUTY);
}
static inline int pwm_enable_from_reg(u8 reg)
{
switch (reg & PWM_ENABLE_MODE_MASK) {
case PWM_MODE_ON:
return 0;
case PWM_MODE_MANUAL:
case PWM_MODE_OFF:
return 1;
case PWM_MODE_AUTO:
return 2;
default:
return -EPROTO;
}
}
static inline u8 pwm_enable_to_reg(unsigned long val, u8 pwmval)
{
switch (val) {
default:
return PWM_MODE_ON;
case 1:
return pwmval ? PWM_MODE_MANUAL : PWM_MODE_OFF;
case 2:
return PWM_MODE_AUTO;
}
}
static void pc87427_readall_temp(struct pc87427_data *data, u8 nr)
{
int iobase = data->address[LD_TEMP];
outb(BANK_TM(nr), iobase + PC87427_REG_BANK);
data->temp[nr] = le16_to_cpu(inw(iobase + PC87427_REG_TEMP));
data->temp_max[nr] = inb(iobase + PC87427_REG_TEMP_MAX);
data->temp_min[nr] = inb(iobase + PC87427_REG_TEMP_MIN);
data->temp_crit[nr] = inb(iobase + PC87427_REG_TEMP_CRIT);
data->temp_type[nr] = inb(iobase + PC87427_REG_TEMP_TYPE);
data->temp_status[nr] = inb(iobase + PC87427_REG_TEMP_STATUS);
outb(data->temp_status[nr], iobase + PC87427_REG_TEMP_STATUS);
}
static inline unsigned int temp_type_from_reg(u8 reg)
{
switch (reg & TEMP_TYPE_MASK) {
case TEMP_TYPE_THERMISTOR:
return 4;
case TEMP_TYPE_REMOTE_DIODE:
case TEMP_TYPE_LOCAL_DIODE:
return 3;
default:
return 0;
}
}
static inline long temp_from_reg(s16 reg)
{
return reg * 1000 / 256;
}
static inline long temp_from_reg8(s8 reg)
{
return reg * 1000;
}
static struct pc87427_data *pc87427_update_device(struct device *dev)
{
struct pc87427_data *data = dev_get_drvdata(dev);
int i;
mutex_lock(&data->lock);
if (!time_after(jiffies, data->last_updated + HZ)
&& data->last_updated)
goto done;
for (i = 0; i < 8; i++) {
if (!(data->fan_enabled & (1 << i)))
continue;
pc87427_readall_fan(data, i);
}
for (i = 0; i < 4; i++) {
if (!(data->pwm_enabled & (1 << i)))
continue;
pc87427_readall_pwm(data, i);
}
for (i = 0; i < 6; i++) {
if (!(data->temp_enabled & (1 << i)))
continue;
pc87427_readall_temp(data, i);
}
data->last_updated = jiffies;
done:
mutex_unlock(&data->lock);
return data;
}
static ssize_t show_fan_input(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%lu\n", fan_from_reg(data->fan[nr]));
}
static ssize_t show_fan_min(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%lu\n", fan_from_reg(data->fan_min[nr]));
}
static ssize_t show_fan_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", !!(data->fan_status[nr]
& FAN_STATUS_LOSPD));
}
static ssize_t show_fan_fault(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", !!(data->fan_status[nr]
& FAN_STATUS_STALL));
}
static ssize_t set_fan_min(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct pc87427_data *data = dev_get_drvdata(dev);
int nr = to_sensor_dev_attr(devattr)->index;
unsigned long val;
int iobase = data->address[LD_FAN];
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
mutex_lock(&data->lock);
outb(BANK_FM(nr), iobase + PC87427_REG_BANK);
outb(0, iobase + PC87427_REG_FAN_STATUS);
data->fan_min[nr] = fan_to_reg(val);
outw(data->fan_min[nr], iobase + PC87427_REG_FAN_MIN);
outb(FAN_STATUS_MONEN, iobase + PC87427_REG_FAN_STATUS);
mutex_unlock(&data->lock);
return count;
}
static void update_pwm_enable(struct pc87427_data *data, int nr, u8 mode)
{
int iobase = data->address[LD_FAN];
data->pwm_enable[nr] &= ~PWM_ENABLE_MODE_MASK;
data->pwm_enable[nr] |= mode;
outb(data->pwm_enable[nr], iobase + PC87427_REG_PWM_ENABLE);
}
static ssize_t show_pwm_enable(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
int pwm_enable;
pwm_enable = pwm_enable_from_reg(data->pwm_enable[nr]);
if (pwm_enable < 0)
return pwm_enable;
return sprintf(buf, "%d\n", pwm_enable);
}
static ssize_t set_pwm_enable(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct pc87427_data *data = dev_get_drvdata(dev);
int nr = to_sensor_dev_attr(devattr)->index;
unsigned long val;
if (kstrtoul(buf, 10, &val) < 0 || val > 2)
return -EINVAL;
if (val == 2 && !(data->pwm_auto_ok & (1 << nr)))
return -EINVAL;
mutex_lock(&data->lock);
pc87427_readall_pwm(data, nr);
update_pwm_enable(data, nr, pwm_enable_to_reg(val, data->pwm[nr]));
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_pwm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", (int)data->pwm[nr]);
}
static ssize_t set_pwm(struct device *dev, struct device_attribute
*devattr, const char *buf, size_t count)
{
struct pc87427_data *data = dev_get_drvdata(dev);
int nr = to_sensor_dev_attr(devattr)->index;
unsigned long val;
int iobase = data->address[LD_FAN];
u8 mode;
if (kstrtoul(buf, 10, &val) < 0 || val > 0xff)
return -EINVAL;
mutex_lock(&data->lock);
pc87427_readall_pwm(data, nr);
mode = data->pwm_enable[nr] & PWM_ENABLE_MODE_MASK;
if (mode != PWM_MODE_MANUAL && mode != PWM_MODE_OFF) {
dev_notice(dev, "Can't set PWM%d duty cycle while not in "
"manual mode\n", nr + 1);
mutex_unlock(&data->lock);
return -EPERM;
}
if (mode == PWM_MODE_MANUAL && val == 0) {
update_pwm_enable(data, nr, PWM_MODE_OFF);
mode = PWM_MODE_OFF;
dev_dbg(dev, "Switching PWM%d from %s to %s\n", nr + 1,
"manual", "off");
} else if (mode == PWM_MODE_OFF && val != 0) {
update_pwm_enable(data, nr, PWM_MODE_MANUAL);
mode = PWM_MODE_MANUAL;
dev_dbg(dev, "Switching PWM%d from %s to %s\n", nr + 1,
"off", "manual");
}
data->pwm[nr] = val;
if (mode == PWM_MODE_MANUAL)
outb(val, iobase + PC87427_REG_PWM_DUTY);
mutex_unlock(&data->lock);
return count;
}
static ssize_t show_temp_input(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%ld\n", temp_from_reg(data->temp[nr]));
}
static ssize_t show_temp_min(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%ld\n", temp_from_reg8(data->temp_min[nr]));
}
static ssize_t show_temp_max(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%ld\n", temp_from_reg8(data->temp_max[nr]));
}
static ssize_t show_temp_crit(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%ld\n", temp_from_reg8(data->temp_crit[nr]));
}
static ssize_t show_temp_type(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%u\n", temp_type_from_reg(data->temp_type[nr]));
}
static ssize_t show_temp_min_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", !!(data->temp_status[nr]
& TEMP_STATUS_LOWFLG));
}
static ssize_t show_temp_max_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", !!(data->temp_status[nr]
& TEMP_STATUS_HIGHFLG));
}
static ssize_t show_temp_crit_alarm(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", !!(data->temp_status[nr]
& TEMP_STATUS_CRITFLG));
}
static ssize_t show_temp_fault(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = pc87427_update_device(dev);
int nr = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%d\n", !!(data->temp_status[nr]
& TEMP_STATUS_SENSERR));
}
static ssize_t show_name(struct device *dev, struct device_attribute
*devattr, char *buf)
{
struct pc87427_data *data = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", data->name);
}
static void pc87427_release_regions(struct platform_device *pdev, int count)
{
struct resource *res;
int i;
for (i = 0; i < count; i++) {
res = platform_get_resource(pdev, IORESOURCE_IO, i);
release_region(res->start, resource_size(res));
}
}
static int __devinit pc87427_request_regions(struct platform_device *pdev,
int count)
{
struct resource *res;
int i, err = 0;
for (i = 0; i < count; i++) {
res = platform_get_resource(pdev, IORESOURCE_IO, i);
if (!res) {
err = -ENOENT;
dev_err(&pdev->dev, "Missing resource #%d\n", i);
break;
}
if (!request_region(res->start, resource_size(res), DRVNAME)) {
err = -EBUSY;
dev_err(&pdev->dev,
"Failed to request region 0x%lx-0x%lx\n",
(unsigned long)res->start,
(unsigned long)res->end);
break;
}
}
if (err && i)
pc87427_release_regions(pdev, i);
return err;
}
static void __devinit pc87427_init_device(struct device *dev)
{
struct pc87427_sio_data *sio_data = dev->platform_data;
struct pc87427_data *data = dev_get_drvdata(dev);
int i;
u8 reg;
reg = pc87427_read8(data, LD_FAN, PC87427_REG_BANK);
if (!(reg & 0x80))
dev_warn(dev, "%s module not ready!\n", "FMC");
for (i = 0; i < 8; i++) {
if (!(sio_data->has_fanin & (1 << i)))
continue;
reg = pc87427_read8_bank(data, LD_FAN, BANK_FM(i),
PC87427_REG_FAN_STATUS);
if (reg & FAN_STATUS_MONEN)
data->fan_enabled |= (1 << i);
}
if (!data->fan_enabled) {
dev_dbg(dev, "Enabling monitoring of all fans\n");
for (i = 0; i < 8; i++) {
if (!(sio_data->has_fanin & (1 << i)))
continue;
pc87427_write8_bank(data, LD_FAN, BANK_FM(i),
PC87427_REG_FAN_STATUS,
FAN_STATUS_MONEN);
}
data->fan_enabled = sio_data->has_fanin;
}
for (i = 0; i < 4; i++) {
if (!(sio_data->has_fanout & (1 << i)))
continue;
reg = pc87427_read8_bank(data, LD_FAN, BANK_FC(i),
PC87427_REG_PWM_ENABLE);
if (reg & PWM_ENABLE_CTLEN)
data->pwm_enabled |= (1 << i);
if ((reg & PWM_ENABLE_MODE_MASK) == PWM_MODE_AUTO) {
dev_dbg(dev, "PWM%d is in automatic control mode\n",
i + 1);
data->pwm_auto_ok |= (1 << i);
}
}
reg = pc87427_read8(data, LD_TEMP, PC87427_REG_BANK);
if (!(reg & 0x80))
dev_warn(dev, "%s module not ready!\n", "HMC");
for (i = 0; i < 6; i++) {
reg = pc87427_read8_bank(data, LD_TEMP, BANK_TM(i),
PC87427_REG_TEMP_STATUS);
if (reg & TEMP_STATUS_CHANEN)
data->temp_enabled |= (1 << i);
}
}
static void pc87427_remove_files(struct device *dev)
{
struct pc87427_data *data = dev_get_drvdata(dev);
int i;
device_remove_file(dev, &dev_attr_name);
for (i = 0; i < 8; i++) {
if (!(data->fan_enabled & (1 << i)))
continue;
sysfs_remove_group(&dev->kobj, &pc87427_group_fan[i]);
}
for (i = 0; i < 4; i++) {
if (!(data->pwm_enabled & (1 << i)))
continue;
sysfs_remove_group(&dev->kobj, &pc87427_group_pwm[i]);
}
for (i = 0; i < 6; i++) {
if (!(data->temp_enabled & (1 << i)))
continue;
sysfs_remove_group(&dev->kobj, &pc87427_group_temp[i]);
}
}
static int __devinit pc87427_probe(struct platform_device *pdev)
{
struct pc87427_sio_data *sio_data = pdev->dev.platform_data;
struct pc87427_data *data;
int i, err, res_count;
data = kzalloc(sizeof(struct pc87427_data), GFP_KERNEL);
if (!data) {
err = -ENOMEM;
pr_err("Out of memory\n");
goto exit;
}
data->address[0] = sio_data->address[0];
data->address[1] = sio_data->address[1];
res_count = (data->address[0] != 0) + (data->address[1] != 0);
err = pc87427_request_regions(pdev, res_count);
if (err)
goto exit_kfree;
mutex_init(&data->lock);
data->name = "pc87427";
platform_set_drvdata(pdev, data);
pc87427_init_device(&pdev->dev);
err = device_create_file(&pdev->dev, &dev_attr_name);
if (err)
goto exit_release_region;
for (i = 0; i < 8; i++) {
if (!(data->fan_enabled & (1 << i)))
continue;
err = sysfs_create_group(&pdev->dev.kobj,
&pc87427_group_fan[i]);
if (err)
goto exit_remove_files;
}
for (i = 0; i < 4; i++) {
if (!(data->pwm_enabled & (1 << i)))
continue;
err = sysfs_create_group(&pdev->dev.kobj,
&pc87427_group_pwm[i]);
if (err)
goto exit_remove_files;
}
for (i = 0; i < 6; i++) {
if (!(data->temp_enabled & (1 << i)))
continue;
err = sysfs_create_group(&pdev->dev.kobj,
&pc87427_group_temp[i]);
if (err)
goto exit_remove_files;
}
data->hwmon_dev = hwmon_device_register(&pdev->dev);
if (IS_ERR(data->hwmon_dev)) {
err = PTR_ERR(data->hwmon_dev);
dev_err(&pdev->dev, "Class registration failed (%d)\n", err);
goto exit_remove_files;
}
return 0;
exit_remove_files:
pc87427_remove_files(&pdev->dev);
exit_release_region:
pc87427_release_regions(pdev, res_count);
exit_kfree:
platform_set_drvdata(pdev, NULL);
kfree(data);
exit:
return err;
}
static int __devexit pc87427_remove(struct platform_device *pdev)
{
struct pc87427_data *data = platform_get_drvdata(pdev);
int res_count;
res_count = (data->address[0] != 0) + (data->address[1] != 0);
hwmon_device_unregister(data->hwmon_dev);
pc87427_remove_files(&pdev->dev);
platform_set_drvdata(pdev, NULL);
kfree(data);
pc87427_release_regions(pdev, res_count);
return 0;
}
static int __init pc87427_device_add(const struct pc87427_sio_data *sio_data)
{
struct resource res[2] = {
{ .flags = IORESOURCE_IO },
{ .flags = IORESOURCE_IO },
};
int err, i, res_count;
res_count = 0;
for (i = 0; i < 2; i++) {
if (!sio_data->address[i])
continue;
res[res_count].start = sio_data->address[i];
res[res_count].end = sio_data->address[i] + REGION_LENGTH - 1;
res[res_count].name = logdev_str[i];
err = acpi_check_resource_conflict(&res[res_count]);
if (err)
goto exit;
res_count++;
}
pdev = platform_device_alloc(DRVNAME, res[0].start);
if (!pdev) {
err = -ENOMEM;
pr_err("Device allocation failed\n");
goto exit;
}
err = platform_device_add_resources(pdev, res, res_count);
if (err) {
pr_err("Device resource addition failed (%d)\n", err);
goto exit_device_put;
}
err = platform_device_add_data(pdev, sio_data,
sizeof(struct pc87427_sio_data));
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
static int __init pc87427_find(int sioaddr, struct pc87427_sio_data *sio_data)
{
u16 val;
u8 cfg, cfg_b;
int i, err = 0;
val = force_id ? force_id : superio_inb(sioaddr, SIOREG_DEVID);
if (val != 0xf2) {
err = -ENODEV;
goto exit;
}
for (i = 0; i < 2; i++) {
sio_data->address[i] = 0;
superio_outb(sioaddr, SIOREG_LDSEL, logdev[i]);
val = superio_inb(sioaddr, SIOREG_ACT);
if (!(val & 0x01)) {
pr_info("Logical device 0x%02x not activated\n",
logdev[i]);
continue;
}
val = superio_inb(sioaddr, SIOREG_MAP);
if (val & 0x01) {
pr_warn("Logical device 0x%02x is memory-mapped, "
"can't use\n", logdev[i]);
continue;
}
val = (superio_inb(sioaddr, SIOREG_IOBASE) << 8)
| superio_inb(sioaddr, SIOREG_IOBASE + 1);
if (!val) {
pr_info("I/O base address not set for logical device "
"0x%02x\n", logdev[i]);
continue;
}
sio_data->address[i] = val;
}
if (!sio_data->address[0] && !sio_data->address[1]) {
err = -ENODEV;
goto exit;
}
sio_data->has_fanin = (1 << 2) | (1 << 3);
cfg = superio_inb(sioaddr, SIOREG_CF2);
if (!(cfg & (1 << 3)))
sio_data->has_fanin |= (1 << 0);
if (!(cfg & (1 << 2)))
sio_data->has_fanin |= (1 << 4);
cfg = superio_inb(sioaddr, SIOREG_CFD);
if (!(cfg & (1 << 0)))
sio_data->has_fanin |= (1 << 1);
cfg = superio_inb(sioaddr, SIOREG_CF4);
if (!(cfg & (1 << 0)))
sio_data->has_fanin |= (1 << 7);
cfg_b = superio_inb(sioaddr, SIOREG_CFB);
if (!(cfg & (1 << 1)) && (cfg_b & (1 << 3)))
sio_data->has_fanin |= (1 << 5);
cfg = superio_inb(sioaddr, SIOREG_CF3);
if ((cfg & (1 << 3)) && !(cfg_b & (1 << 5)))
sio_data->has_fanin |= (1 << 6);
sio_data->has_fanout = (1 << 0);
if (cfg_b & (1 << 0))
sio_data->has_fanout |= (1 << 3);
cfg = superio_inb(sioaddr, SIOREG_CFC);
if (!(cfg & (1 << 4))) {
if (cfg_b & (1 << 1))
sio_data->has_fanout |= (1 << 1);
if (cfg_b & (1 << 2))
sio_data->has_fanout |= (1 << 2);
}
cfg = superio_inb(sioaddr, SIOREG_CF5);
if (cfg & (1 << 6))
sio_data->has_fanout |= (1 << 1);
if (cfg & (1 << 5))
sio_data->has_fanout |= (1 << 2);
exit:
superio_exit(sioaddr);
return err;
}
static int __init pc87427_init(void)
{
int err;
struct pc87427_sio_data sio_data;
if (pc87427_find(0x2e, &sio_data)
&& pc87427_find(0x4e, &sio_data))
return -ENODEV;
err = platform_driver_register(&pc87427_driver);
if (err)
goto exit;
err = pc87427_device_add(&sio_data);
if (err)
goto exit_driver;
return 0;
exit_driver:
platform_driver_unregister(&pc87427_driver);
exit:
return err;
}
static void __exit pc87427_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&pc87427_driver);
}
