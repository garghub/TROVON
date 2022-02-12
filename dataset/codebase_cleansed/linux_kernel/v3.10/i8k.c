static inline const char *i8k_get_dmi_data(int field)
{
const char *dmi_data = dmi_get_system_info(field);
return dmi_data && *dmi_data ? dmi_data : "?";
}
static int i8k_smm(struct smm_regs *regs)
{
int rc;
int eax = regs->eax;
#if defined(CONFIG_X86_64)
asm volatile("pushq %%rax\n\t"
"movl 0(%%rax),%%edx\n\t"
"pushq %%rdx\n\t"
"movl 4(%%rax),%%ebx\n\t"
"movl 8(%%rax),%%ecx\n\t"
"movl 12(%%rax),%%edx\n\t"
"movl 16(%%rax),%%esi\n\t"
"movl 20(%%rax),%%edi\n\t"
"popq %%rax\n\t"
"out %%al,$0xb2\n\t"
"out %%al,$0x84\n\t"
"xchgq %%rax,(%%rsp)\n\t"
"movl %%ebx,4(%%rax)\n\t"
"movl %%ecx,8(%%rax)\n\t"
"movl %%edx,12(%%rax)\n\t"
"movl %%esi,16(%%rax)\n\t"
"movl %%edi,20(%%rax)\n\t"
"popq %%rdx\n\t"
"movl %%edx,0(%%rax)\n\t"
"pushfq\n\t"
"popq %%rax\n\t"
"andl $1,%%eax\n"
:"=a"(rc)
: "a"(regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
#else
asm volatile("pushl %%eax\n\t"
"movl 0(%%eax),%%edx\n\t"
"push %%edx\n\t"
"movl 4(%%eax),%%ebx\n\t"
"movl 8(%%eax),%%ecx\n\t"
"movl 12(%%eax),%%edx\n\t"
"movl 16(%%eax),%%esi\n\t"
"movl 20(%%eax),%%edi\n\t"
"popl %%eax\n\t"
"out %%al,$0xb2\n\t"
"out %%al,$0x84\n\t"
"xchgl %%eax,(%%esp)\n\t"
"movl %%ebx,4(%%eax)\n\t"
"movl %%ecx,8(%%eax)\n\t"
"movl %%edx,12(%%eax)\n\t"
"movl %%esi,16(%%eax)\n\t"
"movl %%edi,20(%%eax)\n\t"
"popl %%edx\n\t"
"movl %%edx,0(%%eax)\n\t"
"lahf\n\t"
"shrl $8,%%eax\n\t"
"andl $1,%%eax\n"
:"=a"(rc)
: "a"(regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
#endif
if (rc != 0 || (regs->eax & 0xffff) == 0xffff || regs->eax == eax)
return -EINVAL;
return 0;
}
static int i8k_get_bios_version(void)
{
struct smm_regs regs = { .eax = I8K_SMM_BIOS_VERSION, };
return i8k_smm(&regs) ? : regs.eax;
}
static int i8k_get_fn_status(void)
{
struct smm_regs regs = { .eax = I8K_SMM_FN_STATUS, };
int rc;
if ((rc = i8k_smm(&regs)) < 0)
return rc;
switch ((regs.eax >> I8K_FN_SHIFT) & I8K_FN_MASK) {
case I8K_FN_UP:
return I8K_VOL_UP;
case I8K_FN_DOWN:
return I8K_VOL_DOWN;
case I8K_FN_MUTE:
return I8K_VOL_MUTE;
default:
return 0;
}
}
static int i8k_get_power_status(void)
{
struct smm_regs regs = { .eax = I8K_SMM_POWER_STATUS, };
int rc;
if ((rc = i8k_smm(&regs)) < 0)
return rc;
return (regs.eax & 0xff) == I8K_POWER_AC ? I8K_AC : I8K_BATTERY;
}
static int i8k_get_fan_status(int fan)
{
struct smm_regs regs = { .eax = I8K_SMM_GET_FAN, };
regs.ebx = fan & 0xff;
return i8k_smm(&regs) ? : regs.eax & 0xff;
}
static int i8k_get_fan_speed(int fan)
{
struct smm_regs regs = { .eax = I8K_SMM_GET_SPEED, };
regs.ebx = fan & 0xff;
return i8k_smm(&regs) ? : (regs.eax & 0xffff) * fan_mult;
}
static int i8k_set_fan(int fan, int speed)
{
struct smm_regs regs = { .eax = I8K_SMM_SET_FAN, };
speed = (speed < 0) ? 0 : ((speed > I8K_FAN_MAX) ? I8K_FAN_MAX : speed);
regs.ebx = (fan & 0xff) | (speed << 8);
return i8k_smm(&regs) ? : i8k_get_fan_status(fan);
}
static int i8k_get_temp(int sensor)
{
struct smm_regs regs = { .eax = I8K_SMM_GET_TEMP, };
int rc;
int temp;
#ifdef I8K_TEMPERATURE_BUG
static int prev;
#endif
regs.ebx = sensor & 0xff;
if ((rc = i8k_smm(&regs)) < 0)
return rc;
temp = regs.eax & 0xff;
#ifdef I8K_TEMPERATURE_BUG
if (temp > I8K_MAX_TEMP) {
temp = prev;
prev = I8K_MAX_TEMP;
} else {
prev = temp;
}
#endif
return temp;
}
static int i8k_get_dell_signature(int req_fn)
{
struct smm_regs regs = { .eax = req_fn, };
int rc;
if ((rc = i8k_smm(&regs)) < 0)
return rc;
return regs.eax == 1145651527 && regs.edx == 1145392204 ? 0 : -1;
}
static int
i8k_ioctl_unlocked(struct file *fp, unsigned int cmd, unsigned long arg)
{
int val = 0;
int speed;
unsigned char buff[16];
int __user *argp = (int __user *)arg;
if (!argp)
return -EINVAL;
switch (cmd) {
case I8K_BIOS_VERSION:
val = i8k_get_bios_version();
break;
case I8K_MACHINE_ID:
memset(buff, 0, 16);
strlcpy(buff, i8k_get_dmi_data(DMI_PRODUCT_SERIAL), sizeof(buff));
break;
case I8K_FN_STATUS:
val = i8k_get_fn_status();
break;
case I8K_POWER_STATUS:
val = i8k_get_power_status();
break;
case I8K_GET_TEMP:
val = i8k_get_temp(0);
break;
case I8K_GET_SPEED:
if (copy_from_user(&val, argp, sizeof(int)))
return -EFAULT;
val = i8k_get_fan_speed(val);
break;
case I8K_GET_FAN:
if (copy_from_user(&val, argp, sizeof(int)))
return -EFAULT;
val = i8k_get_fan_status(val);
break;
case I8K_SET_FAN:
if (restricted && !capable(CAP_SYS_ADMIN))
return -EPERM;
if (copy_from_user(&val, argp, sizeof(int)))
return -EFAULT;
if (copy_from_user(&speed, argp + 1, sizeof(int)))
return -EFAULT;
val = i8k_set_fan(val, speed);
break;
default:
return -EINVAL;
}
if (val < 0)
return val;
switch (cmd) {
case I8K_BIOS_VERSION:
if (copy_to_user(argp, &val, 4))
return -EFAULT;
break;
case I8K_MACHINE_ID:
if (copy_to_user(argp, buff, 16))
return -EFAULT;
break;
default:
if (copy_to_user(argp, &val, sizeof(int)))
return -EFAULT;
break;
}
return 0;
}
static long i8k_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
long ret;
mutex_lock(&i8k_mutex);
ret = i8k_ioctl_unlocked(fp, cmd, arg);
mutex_unlock(&i8k_mutex);
return ret;
}
static int i8k_proc_show(struct seq_file *seq, void *offset)
{
int fn_key, cpu_temp, ac_power;
int left_fan, right_fan, left_speed, right_speed;
cpu_temp = i8k_get_temp(0);
left_fan = i8k_get_fan_status(I8K_FAN_LEFT);
right_fan = i8k_get_fan_status(I8K_FAN_RIGHT);
left_speed = i8k_get_fan_speed(I8K_FAN_LEFT);
right_speed = i8k_get_fan_speed(I8K_FAN_RIGHT);
fn_key = i8k_get_fn_status();
if (power_status)
ac_power = i8k_get_power_status();
else
ac_power = -1;
return seq_printf(seq, "%s %s %s %d %d %d %d %d %d %d\n",
I8K_PROC_FMT,
bios_version,
i8k_get_dmi_data(DMI_PRODUCT_SERIAL),
cpu_temp,
left_fan, right_fan, left_speed, right_speed,
ac_power, fn_key);
}
static int i8k_open_fs(struct inode *inode, struct file *file)
{
return single_open(file, i8k_proc_show, NULL);
}
static ssize_t i8k_hwmon_show_temp(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int cpu_temp;
cpu_temp = i8k_get_temp(0);
if (cpu_temp < 0)
return cpu_temp;
return sprintf(buf, "%d\n", cpu_temp * 1000);
}
static ssize_t i8k_hwmon_show_fan(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
int fan_speed;
fan_speed = i8k_get_fan_speed(index);
if (fan_speed < 0)
return fan_speed;
return sprintf(buf, "%d\n", fan_speed);
}
static ssize_t i8k_hwmon_show_label(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
static const char *labels[4] = {
"i8k",
"CPU",
"Left Fan",
"Right Fan",
};
int index = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%s\n", labels[index]);
}
static void i8k_hwmon_remove_files(struct device *dev)
{
device_remove_file(dev, &dev_attr_temp1_input);
device_remove_file(dev, &sensor_dev_attr_fan1_input.dev_attr);
device_remove_file(dev, &sensor_dev_attr_fan2_input.dev_attr);
device_remove_file(dev, &sensor_dev_attr_temp1_label.dev_attr);
device_remove_file(dev, &sensor_dev_attr_fan1_label.dev_attr);
device_remove_file(dev, &sensor_dev_attr_fan2_label.dev_attr);
device_remove_file(dev, &sensor_dev_attr_name.dev_attr);
}
static int __init i8k_init_hwmon(void)
{
int err;
i8k_hwmon_dev = hwmon_device_register(NULL);
if (IS_ERR(i8k_hwmon_dev)) {
err = PTR_ERR(i8k_hwmon_dev);
i8k_hwmon_dev = NULL;
printk(KERN_ERR "i8k: hwmon registration failed (%d)\n", err);
return err;
}
err = device_create_file(i8k_hwmon_dev,
&sensor_dev_attr_name.dev_attr);
if (err)
goto exit_unregister;
err = i8k_get_temp(0);
if (err < 0) {
dev_dbg(i8k_hwmon_dev,
"Not creating temperature attributes (%d)\n", err);
} else {
err = device_create_file(i8k_hwmon_dev, &dev_attr_temp1_input);
if (err)
goto exit_remove_files;
err = device_create_file(i8k_hwmon_dev,
&sensor_dev_attr_temp1_label.dev_attr);
if (err)
goto exit_remove_files;
}
err = i8k_get_fan_status(I8K_FAN_LEFT);
if (err < 0) {
dev_dbg(i8k_hwmon_dev,
"Not creating %s fan attributes (%d)\n", "left", err);
} else {
err = device_create_file(i8k_hwmon_dev,
&sensor_dev_attr_fan1_input.dev_attr);
if (err)
goto exit_remove_files;
err = device_create_file(i8k_hwmon_dev,
&sensor_dev_attr_fan1_label.dev_attr);
if (err)
goto exit_remove_files;
}
err = i8k_get_fan_status(I8K_FAN_RIGHT);
if (err < 0) {
dev_dbg(i8k_hwmon_dev,
"Not creating %s fan attributes (%d)\n", "right", err);
} else {
err = device_create_file(i8k_hwmon_dev,
&sensor_dev_attr_fan2_input.dev_attr);
if (err)
goto exit_remove_files;
err = device_create_file(i8k_hwmon_dev,
&sensor_dev_attr_fan2_label.dev_attr);
if (err)
goto exit_remove_files;
}
return 0;
exit_remove_files:
i8k_hwmon_remove_files(i8k_hwmon_dev);
exit_unregister:
hwmon_device_unregister(i8k_hwmon_dev);
return err;
}
static void __exit i8k_exit_hwmon(void)
{
i8k_hwmon_remove_files(i8k_hwmon_dev);
hwmon_device_unregister(i8k_hwmon_dev);
}
static int __init i8k_probe(void)
{
char buff[4];
int version;
if (!dmi_check_system(i8k_dmi_table)) {
if (!ignore_dmi && !force)
return -ENODEV;
printk(KERN_INFO "i8k: not running on a supported Dell system.\n");
printk(KERN_INFO "i8k: vendor=%s, model=%s, version=%s\n",
i8k_get_dmi_data(DMI_SYS_VENDOR),
i8k_get_dmi_data(DMI_PRODUCT_NAME),
i8k_get_dmi_data(DMI_BIOS_VERSION));
}
strlcpy(bios_version, i8k_get_dmi_data(DMI_BIOS_VERSION), sizeof(bios_version));
if (i8k_get_dell_signature(I8K_SMM_GET_DELL_SIG1) &&
i8k_get_dell_signature(I8K_SMM_GET_DELL_SIG2)) {
printk(KERN_ERR "i8k: unable to get SMM Dell signature\n");
if (!force)
return -ENODEV;
}
version = i8k_get_bios_version();
if (version <= 0) {
printk(KERN_WARNING "i8k: unable to get SMM BIOS version\n");
} else {
buff[0] = (version >> 16) & 0xff;
buff[1] = (version >> 8) & 0xff;
buff[2] = (version) & 0xff;
buff[3] = '\0';
if (!dmi_get_system_info(DMI_BIOS_VERSION))
strlcpy(bios_version, buff, sizeof(bios_version));
if (strncmp(buff, bios_version, sizeof(bios_version)) != 0)
printk(KERN_WARNING "i8k: BIOS version mismatch: %s != %s\n",
buff, bios_version);
}
return 0;
}
static int __init i8k_init(void)
{
struct proc_dir_entry *proc_i8k;
int err;
if (i8k_probe())
return -ENODEV;
proc_i8k = proc_create("i8k", 0, NULL, &i8k_fops);
if (!proc_i8k)
return -ENOENT;
err = i8k_init_hwmon();
if (err)
goto exit_remove_proc;
printk(KERN_INFO
"Dell laptop SMM driver v%s Massimo Dal Zotto (dz@debian.org)\n",
I8K_VERSION);
return 0;
exit_remove_proc:
remove_proc_entry("i8k", NULL);
return err;
}
static void __exit i8k_exit(void)
{
i8k_exit_hwmon();
remove_proc_entry("i8k", NULL);
}
