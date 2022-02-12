static int pkg_temp_debugfs_init(void)
{
struct dentry *d;
debugfs = debugfs_create_dir("pkg_temp_thermal", NULL);
if (!debugfs)
return -ENOENT;
d = debugfs_create_u32("pkg_thres_interrupt", S_IRUGO, debugfs,
(u32 *)&pkg_interrupt_cnt);
if (!d)
goto err_out;
d = debugfs_create_u32("pkg_thres_work", S_IRUGO, debugfs,
(u32 *)&pkg_work_cnt);
if (!d)
goto err_out;
return 0;
err_out:
debugfs_remove_recursive(debugfs);
return -ENOENT;
}
static struct pkg_device *pkg_temp_thermal_get_dev(unsigned int cpu)
{
int pkgid = topology_logical_package_id(cpu);
if (pkgid >= 0 && pkgid < max_packages)
return packages[pkgid];
return NULL;
}
static int get_tj_max(int cpu, u32 *tj_max)
{
u32 eax, edx, val;
int err;
err = rdmsr_safe_on_cpu(cpu, MSR_IA32_TEMPERATURE_TARGET, &eax, &edx);
if (err)
return err;
val = (eax >> 16) & 0xff;
*tj_max = val * 1000;
return val ? 0 : -EINVAL;
}
static int sys_get_curr_temp(struct thermal_zone_device *tzd, int *temp)
{
struct pkg_device *pkgdev = tzd->devdata;
u32 eax, edx;
rdmsr_on_cpu(pkgdev->cpu, MSR_IA32_PACKAGE_THERM_STATUS, &eax, &edx);
if (eax & 0x80000000) {
*temp = pkgdev->tj_max - ((eax >> 16) & 0x7f) * 1000;
pr_debug("sys_get_curr_temp %d\n", *temp);
return 0;
}
return -EINVAL;
}
static int sys_get_trip_temp(struct thermal_zone_device *tzd,
int trip, int *temp)
{
struct pkg_device *pkgdev = tzd->devdata;
unsigned long thres_reg_value;
u32 mask, shift, eax, edx;
int ret;
if (trip >= MAX_NUMBER_OF_TRIPS)
return -EINVAL;
if (trip) {
mask = THERM_MASK_THRESHOLD1;
shift = THERM_SHIFT_THRESHOLD1;
} else {
mask = THERM_MASK_THRESHOLD0;
shift = THERM_SHIFT_THRESHOLD0;
}
ret = rdmsr_on_cpu(pkgdev->cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT,
&eax, &edx);
if (ret < 0)
return ret;
thres_reg_value = (eax & mask) >> shift;
if (thres_reg_value)
*temp = pkgdev->tj_max - thres_reg_value * 1000;
else
*temp = 0;
pr_debug("sys_get_trip_temp %d\n", *temp);
return 0;
}
static int
sys_set_trip_temp(struct thermal_zone_device *tzd, int trip, int temp)
{
struct pkg_device *pkgdev = tzd->devdata;
u32 l, h, mask, shift, intr;
int ret;
if (trip >= MAX_NUMBER_OF_TRIPS || temp >= pkgdev->tj_max)
return -EINVAL;
ret = rdmsr_on_cpu(pkgdev->cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT,
&l, &h);
if (ret < 0)
return ret;
if (trip) {
mask = THERM_MASK_THRESHOLD1;
shift = THERM_SHIFT_THRESHOLD1;
intr = THERM_INT_THRESHOLD1_ENABLE;
} else {
mask = THERM_MASK_THRESHOLD0;
shift = THERM_SHIFT_THRESHOLD0;
intr = THERM_INT_THRESHOLD0_ENABLE;
}
l &= ~mask;
if (!temp) {
l &= ~intr;
} else {
l |= (pkgdev->tj_max - temp)/1000 << shift;
l |= intr;
}
return wrmsr_on_cpu(pkgdev->cpu, MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
}
static int sys_get_trip_type(struct thermal_zone_device *thermal, int trip,
enum thermal_trip_type *type)
{
*type = THERMAL_TRIP_PASSIVE;
return 0;
}
static bool pkg_thermal_rate_control(void)
{
return true;
}
static inline void enable_pkg_thres_interrupt(void)
{
u8 thres_0, thres_1;
u32 l, h;
rdmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
thres_0 = (l & THERM_MASK_THRESHOLD0) >> THERM_SHIFT_THRESHOLD0;
thres_1 = (l & THERM_MASK_THRESHOLD1) >> THERM_SHIFT_THRESHOLD1;
if (thres_0)
l |= THERM_INT_THRESHOLD0_ENABLE;
if (thres_1)
l |= THERM_INT_THRESHOLD1_ENABLE;
wrmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
}
static inline void disable_pkg_thres_interrupt(void)
{
u32 l, h;
rdmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
l &= ~(THERM_INT_THRESHOLD0_ENABLE | THERM_INT_THRESHOLD1_ENABLE);
wrmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT, l, h);
}
static void pkg_temp_thermal_threshold_work_fn(struct work_struct *work)
{
struct thermal_zone_device *tzone = NULL;
int cpu = smp_processor_id();
struct pkg_device *pkgdev;
u64 msr_val, wr_val;
mutex_lock(&thermal_zone_mutex);
spin_lock_irq(&pkg_temp_lock);
++pkg_work_cnt;
pkgdev = pkg_temp_thermal_get_dev(cpu);
if (!pkgdev) {
spin_unlock_irq(&pkg_temp_lock);
mutex_unlock(&thermal_zone_mutex);
return;
}
pkgdev->work_scheduled = false;
rdmsrl(MSR_IA32_PACKAGE_THERM_STATUS, msr_val);
wr_val = msr_val & ~(THERM_LOG_THRESHOLD0 | THERM_LOG_THRESHOLD1);
if (wr_val != msr_val) {
wrmsrl(MSR_IA32_PACKAGE_THERM_STATUS, wr_val);
tzone = pkgdev->tzone;
}
enable_pkg_thres_interrupt();
spin_unlock_irq(&pkg_temp_lock);
if (tzone)
thermal_zone_device_update(tzone, THERMAL_EVENT_UNSPECIFIED);
mutex_unlock(&thermal_zone_mutex);
}
static void pkg_thermal_schedule_work(int cpu, struct delayed_work *work)
{
unsigned long ms = msecs_to_jiffies(notify_delay_ms);
schedule_delayed_work_on(cpu, work, ms);
}
static int pkg_thermal_notify(u64 msr_val)
{
int cpu = smp_processor_id();
struct pkg_device *pkgdev;
unsigned long flags;
spin_lock_irqsave(&pkg_temp_lock, flags);
++pkg_interrupt_cnt;
disable_pkg_thres_interrupt();
pkgdev = pkg_temp_thermal_get_dev(cpu);
if (pkgdev && !pkgdev->work_scheduled) {
pkgdev->work_scheduled = true;
pkg_thermal_schedule_work(pkgdev->cpu, &pkgdev->work);
}
spin_unlock_irqrestore(&pkg_temp_lock, flags);
return 0;
}
static int pkg_temp_thermal_device_add(unsigned int cpu)
{
int pkgid = topology_logical_package_id(cpu);
u32 tj_max, eax, ebx, ecx, edx;
struct pkg_device *pkgdev;
int thres_count, err;
if (pkgid >= max_packages)
return -ENOMEM;
cpuid(6, &eax, &ebx, &ecx, &edx);
thres_count = ebx & 0x07;
if (!thres_count)
return -ENODEV;
thres_count = clamp_val(thres_count, 0, MAX_NUMBER_OF_TRIPS);
err = get_tj_max(cpu, &tj_max);
if (err)
return err;
pkgdev = kzalloc(sizeof(*pkgdev), GFP_KERNEL);
if (!pkgdev)
return -ENOMEM;
INIT_DELAYED_WORK(&pkgdev->work, pkg_temp_thermal_threshold_work_fn);
pkgdev->cpu = cpu;
pkgdev->tj_max = tj_max;
pkgdev->tzone = thermal_zone_device_register("x86_pkg_temp",
thres_count,
(thres_count == MAX_NUMBER_OF_TRIPS) ? 0x03 : 0x01,
pkgdev, &tzone_ops, &pkg_temp_tz_params, 0, 0);
if (IS_ERR(pkgdev->tzone)) {
err = PTR_ERR(pkgdev->tzone);
kfree(pkgdev);
return err;
}
rdmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT, pkgdev->msr_pkg_therm_low,
pkgdev->msr_pkg_therm_high);
cpumask_set_cpu(cpu, &pkgdev->cpumask);
spin_lock_irq(&pkg_temp_lock);
packages[pkgid] = pkgdev;
spin_unlock_irq(&pkg_temp_lock);
return 0;
}
static int pkg_thermal_cpu_offline(unsigned int cpu)
{
struct pkg_device *pkgdev = pkg_temp_thermal_get_dev(cpu);
bool lastcpu, was_target;
int target;
if (!pkgdev)
return 0;
target = cpumask_any_but(&pkgdev->cpumask, cpu);
cpumask_clear_cpu(cpu, &pkgdev->cpumask);
lastcpu = target >= nr_cpu_ids;
if (lastcpu) {
struct thermal_zone_device *tzone = pkgdev->tzone;
mutex_lock(&thermal_zone_mutex);
pkgdev->tzone = NULL;
mutex_unlock(&thermal_zone_mutex);
thermal_zone_device_unregister(tzone);
}
spin_lock_irq(&pkg_temp_lock);
was_target = pkgdev->cpu == cpu;
pkgdev->cpu = target;
if (lastcpu) {
packages[topology_logical_package_id(cpu)] = NULL;
wrmsr(MSR_IA32_PACKAGE_THERM_INTERRUPT,
pkgdev->msr_pkg_therm_low, pkgdev->msr_pkg_therm_high);
}
if (pkgdev->work_scheduled && was_target) {
spin_unlock_irq(&pkg_temp_lock);
cancel_delayed_work_sync(&pkgdev->work);
spin_lock_irq(&pkg_temp_lock);
if (!lastcpu && pkgdev->work_scheduled)
pkg_thermal_schedule_work(target, &pkgdev->work);
}
spin_unlock_irq(&pkg_temp_lock);
if (lastcpu)
kfree(pkgdev);
return 0;
}
static int pkg_thermal_cpu_online(unsigned int cpu)
{
struct pkg_device *pkgdev = pkg_temp_thermal_get_dev(cpu);
struct cpuinfo_x86 *c = &cpu_data(cpu);
if (!cpu_has(c, X86_FEATURE_DTHERM) || !cpu_has(c, X86_FEATURE_PTS))
return -ENODEV;
if (pkgdev) {
cpumask_set_cpu(cpu, &pkgdev->cpumask);
return 0;
}
return pkg_temp_thermal_device_add(cpu);
}
static int __init pkg_temp_thermal_init(void)
{
int ret;
if (!x86_match_cpu(pkg_temp_thermal_ids))
return -ENODEV;
max_packages = topology_max_packages();
packages = kzalloc(max_packages * sizeof(struct pkg_device *), GFP_KERNEL);
if (!packages)
return -ENOMEM;
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "thermal/x86_pkg:online",
pkg_thermal_cpu_online, pkg_thermal_cpu_offline);
if (ret < 0)
goto err;
pkg_thermal_hp_state = ret;
platform_thermal_package_notify = pkg_thermal_notify;
platform_thermal_package_rate_control = pkg_thermal_rate_control;
pkg_temp_debugfs_init();
return 0;
err:
kfree(packages);
return ret;
}
static void __exit pkg_temp_thermal_exit(void)
{
platform_thermal_package_notify = NULL;
platform_thermal_package_rate_control = NULL;
cpuhp_remove_state(pkg_thermal_hp_state);
debugfs_remove_recursive(debugfs);
kfree(packages);
}
