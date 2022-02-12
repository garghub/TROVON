static inline const char *i8k_get_dmi_data(int field)
{
const char *dmi_data = dmi_get_system_info(field);
return dmi_data && *dmi_data ? dmi_data : "?";
}
static int i8k_smm(struct smm_regs *regs)
{
int rc;
int eax = regs->eax;
cpumask_var_t old_mask;
if (!alloc_cpumask_var(&old_mask, GFP_KERNEL))
return -ENOMEM;
cpumask_copy(old_mask, &current->cpus_allowed);
set_cpus_allowed_ptr(current, cpumask_of(0));
if (smp_processor_id() != 0) {
rc = -EBUSY;
goto out;
}
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
: "=a"(rc)
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
: "=a"(rc)
: "a"(regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
#endif
if (rc != 0 || (regs->eax & 0xffff) == 0xffff || regs->eax == eax)
rc = -EINVAL;
out:
set_cpus_allowed_ptr(current, old_mask);
free_cpumask_var(old_mask);
return rc;
}
static int i8k_get_fn_status(void)
{
struct smm_regs regs = { .eax = I8K_SMM_FN_STATUS, };
int rc;
rc = i8k_smm(&regs);
if (rc < 0)
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
rc = i8k_smm(&regs);
if (rc < 0)
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
return i8k_smm(&regs) ? : (regs.eax & 0xffff) * i8k_fan_mult;
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
static int prev[4];
#endif
regs.ebx = sensor & 0xff;
rc = i8k_smm(&regs);
if (rc < 0)
return rc;
temp = regs.eax & 0xff;
#ifdef I8K_TEMPERATURE_BUG
if (temp > I8K_MAX_TEMP) {
temp = prev[sensor];
prev[sensor] = I8K_MAX_TEMP;
} else {
prev[sensor] = temp;
}
#endif
return temp;
}
static int i8k_get_dell_signature(int req_fn)
{
struct smm_regs regs = { .eax = req_fn, };
int rc;
rc = i8k_smm(&regs);
if (rc < 0)
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
val = (bios_version[0] << 16) |
(bios_version[1] << 8) | bios_version[2];
break;
case I8K_MACHINE_ID:
memset(buff, 0, 16);
strlcpy(buff, i8k_get_dmi_data(DMI_PRODUCT_SERIAL),
sizeof(buff));
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
int index = to_sensor_dev_attr(devattr)->index;
int temp;
temp = i8k_get_temp(index);
if (temp < 0)
return temp;
return sprintf(buf, "%d\n", temp * 1000);
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
static ssize_t i8k_hwmon_show_pwm(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
int index = to_sensor_dev_attr(devattr)->index;
int status;
status = i8k_get_fan_status(index);
if (status < 0)
return -EIO;
return sprintf(buf, "%d\n", clamp_val(status * 128, 0, 255));
}
static ssize_t i8k_hwmon_set_pwm(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int index = to_sensor_dev_attr(attr)->index;
unsigned long val;
int err;
err = kstrtoul(buf, 10, &val);
if (err)
return err;
val = clamp_val(DIV_ROUND_CLOSEST(val, 128), 0, 2);
mutex_lock(&i8k_mutex);
err = i8k_set_fan(index, val);
mutex_unlock(&i8k_mutex);
return err < 0 ? -EIO : count;
}
static ssize_t i8k_hwmon_show_label(struct device *dev,
struct device_attribute *devattr,
char *buf)
{
static const char *labels[3] = {
"CPU",
"Left Fan",
"Right Fan",
};
int index = to_sensor_dev_attr(devattr)->index;
return sprintf(buf, "%s\n", labels[index]);
}
static umode_t i8k_is_visible(struct kobject *kobj, struct attribute *attr,
int index)
{
if ((index == 0 || index == 1) &&
!(i8k_hwmon_flags & I8K_HWMON_HAVE_TEMP1))
return 0;
if (index == 2 && !(i8k_hwmon_flags & I8K_HWMON_HAVE_TEMP2))
return 0;
if (index == 3 && !(i8k_hwmon_flags & I8K_HWMON_HAVE_TEMP3))
return 0;
if (index == 4 && !(i8k_hwmon_flags & I8K_HWMON_HAVE_TEMP4))
return 0;
if (index >= 5 && index <= 7 &&
!(i8k_hwmon_flags & I8K_HWMON_HAVE_FAN1))
return 0;
if (index >= 8 && index <= 10 &&
!(i8k_hwmon_flags & I8K_HWMON_HAVE_FAN2))
return 0;
return attr->mode;
}
static int __init i8k_init_hwmon(void)
{
int err;
i8k_hwmon_flags = 0;
err = i8k_get_temp(0);
if (err >= 0)
i8k_hwmon_flags |= I8K_HWMON_HAVE_TEMP1;
err = i8k_get_temp(1);
if (err >= 0)
i8k_hwmon_flags |= I8K_HWMON_HAVE_TEMP2;
err = i8k_get_temp(2);
if (err >= 0)
i8k_hwmon_flags |= I8K_HWMON_HAVE_TEMP3;
err = i8k_get_temp(3);
if (err >= 0)
i8k_hwmon_flags |= I8K_HWMON_HAVE_TEMP4;
err = i8k_get_fan_status(I8K_FAN_LEFT);
if (err >= 0)
i8k_hwmon_flags |= I8K_HWMON_HAVE_FAN1;
err = i8k_get_fan_status(I8K_FAN_RIGHT);
if (err >= 0)
i8k_hwmon_flags |= I8K_HWMON_HAVE_FAN2;
i8k_hwmon_dev = hwmon_device_register_with_groups(NULL, "i8k", NULL,
i8k_groups);
if (IS_ERR(i8k_hwmon_dev)) {
err = PTR_ERR(i8k_hwmon_dev);
i8k_hwmon_dev = NULL;
pr_err("hwmon registration failed (%d)\n", err);
return err;
}
return 0;
}
static int __init i8k_probe(void)
{
const struct dmi_system_id *id;
if (!dmi_check_system(i8k_dmi_table)) {
if (!ignore_dmi && !force)
return -ENODEV;
pr_info("not running on a supported Dell system.\n");
pr_info("vendor=%s, model=%s, version=%s\n",
i8k_get_dmi_data(DMI_SYS_VENDOR),
i8k_get_dmi_data(DMI_PRODUCT_NAME),
i8k_get_dmi_data(DMI_BIOS_VERSION));
}
strlcpy(bios_version, i8k_get_dmi_data(DMI_BIOS_VERSION),
sizeof(bios_version));
if (i8k_get_dell_signature(I8K_SMM_GET_DELL_SIG1) &&
i8k_get_dell_signature(I8K_SMM_GET_DELL_SIG2)) {
pr_err("unable to get SMM Dell signature\n");
if (!force)
return -ENODEV;
}
i8k_fan_mult = fan_mult;
id = dmi_first_match(i8k_dmi_table);
if (id && fan_mult == I8K_FAN_MULT && id->driver_data)
i8k_fan_mult = (unsigned long)id->driver_data;
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
return 0;
exit_remove_proc:
remove_proc_entry("i8k", NULL);
return err;
}
static void __exit i8k_exit(void)
{
hwmon_device_unregister(i8k_hwmon_dev);
remove_proc_entry("i8k", NULL);
}
