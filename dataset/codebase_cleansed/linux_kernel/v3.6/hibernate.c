void hibernation_set_ops(const struct platform_hibernation_ops *ops)
{
if (ops && !(ops->begin && ops->end && ops->pre_snapshot
&& ops->prepare && ops->finish && ops->enter && ops->pre_restore
&& ops->restore_cleanup && ops->leave)) {
WARN_ON(1);
return;
}
lock_system_sleep();
hibernation_ops = ops;
if (ops)
hibernation_mode = HIBERNATION_PLATFORM;
else if (hibernation_mode == HIBERNATION_PLATFORM)
hibernation_mode = HIBERNATION_SHUTDOWN;
unlock_system_sleep();
}
bool system_entering_hibernation(void)
{
return entering_platform_hibernation;
}
static void hibernation_debug_sleep(void)
{
printk(KERN_INFO "hibernation debug: Waiting for 5 seconds.\n");
mdelay(5000);
}
static int hibernation_test(int level)
{
if (pm_test_level == level) {
hibernation_debug_sleep();
return 1;
}
return 0;
}
static int hibernation_test(int level) { return 0; }
static int platform_begin(int platform_mode)
{
return (platform_mode && hibernation_ops) ?
hibernation_ops->begin() : 0;
}
static void platform_end(int platform_mode)
{
if (platform_mode && hibernation_ops)
hibernation_ops->end();
}
static int platform_pre_snapshot(int platform_mode)
{
return (platform_mode && hibernation_ops) ?
hibernation_ops->pre_snapshot() : 0;
}
static void platform_leave(int platform_mode)
{
if (platform_mode && hibernation_ops)
hibernation_ops->leave();
}
static void platform_finish(int platform_mode)
{
if (platform_mode && hibernation_ops)
hibernation_ops->finish();
}
static int platform_pre_restore(int platform_mode)
{
return (platform_mode && hibernation_ops) ?
hibernation_ops->pre_restore() : 0;
}
static void platform_restore_cleanup(int platform_mode)
{
if (platform_mode && hibernation_ops)
hibernation_ops->restore_cleanup();
}
static void platform_recover(int platform_mode)
{
if (platform_mode && hibernation_ops && hibernation_ops->recover)
hibernation_ops->recover();
}
void swsusp_show_speed(struct timeval *start, struct timeval *stop,
unsigned nr_pages, char *msg)
{
s64 elapsed_centisecs64;
int centisecs;
int k;
int kps;
elapsed_centisecs64 = timeval_to_ns(stop) - timeval_to_ns(start);
do_div(elapsed_centisecs64, NSEC_PER_SEC / 100);
centisecs = elapsed_centisecs64;
if (centisecs == 0)
centisecs = 1;
k = nr_pages * (PAGE_SIZE / 1024);
kps = (k * 100) / centisecs;
printk(KERN_INFO "PM: %s %d kbytes in %d.%02d seconds (%d.%02d MB/s)\n",
msg, k,
centisecs / 100, centisecs % 100,
kps / 1000, (kps % 1000) / 10);
}
static int create_image(int platform_mode)
{
int error;
error = dpm_suspend_end(PMSG_FREEZE);
if (error) {
printk(KERN_ERR "PM: Some devices failed to power down, "
"aborting hibernation\n");
return error;
}
error = platform_pre_snapshot(platform_mode);
if (error || hibernation_test(TEST_PLATFORM))
goto Platform_finish;
error = disable_nonboot_cpus();
if (error || hibernation_test(TEST_CPUS))
goto Enable_cpus;
local_irq_disable();
error = syscore_suspend();
if (error) {
printk(KERN_ERR "PM: Some system devices failed to power down, "
"aborting hibernation\n");
goto Enable_irqs;
}
if (hibernation_test(TEST_CORE) || pm_wakeup_pending())
goto Power_up;
in_suspend = 1;
save_processor_state();
error = swsusp_arch_suspend();
if (error)
printk(KERN_ERR "PM: Error %d creating hibernation image\n",
error);
restore_processor_state();
if (!in_suspend) {
events_check_enabled = false;
platform_leave(platform_mode);
}
Power_up:
syscore_resume();
Enable_irqs:
local_irq_enable();
Enable_cpus:
enable_nonboot_cpus();
Platform_finish:
platform_finish(platform_mode);
dpm_resume_start(in_suspend ?
(error ? PMSG_RECOVER : PMSG_THAW) : PMSG_RESTORE);
return error;
}
int hibernation_snapshot(int platform_mode)
{
pm_message_t msg;
int error;
error = platform_begin(platform_mode);
if (error)
goto Close;
error = hibernate_preallocate_memory();
if (error)
goto Close;
error = freeze_kernel_threads();
if (error)
goto Cleanup;
if (hibernation_test(TEST_FREEZER)) {
freezer_test_done = true;
goto Thaw;
}
error = dpm_prepare(PMSG_FREEZE);
if (error) {
dpm_complete(PMSG_RECOVER);
goto Thaw;
}
suspend_console();
ftrace_stop();
pm_restrict_gfp_mask();
error = dpm_suspend(PMSG_FREEZE);
if (error || hibernation_test(TEST_DEVICES))
platform_recover(platform_mode);
else
error = create_image(platform_mode);
if (error || !in_suspend)
swsusp_free();
msg = in_suspend ? (error ? PMSG_RECOVER : PMSG_THAW) : PMSG_RESTORE;
dpm_resume(msg);
if (error || !in_suspend)
pm_restore_gfp_mask();
ftrace_start();
resume_console();
dpm_complete(msg);
Close:
platform_end(platform_mode);
return error;
Thaw:
thaw_kernel_threads();
Cleanup:
swsusp_free();
goto Close;
}
static int resume_target_kernel(bool platform_mode)
{
int error;
error = dpm_suspend_end(PMSG_QUIESCE);
if (error) {
printk(KERN_ERR "PM: Some devices failed to power down, "
"aborting resume\n");
return error;
}
error = platform_pre_restore(platform_mode);
if (error)
goto Cleanup;
error = disable_nonboot_cpus();
if (error)
goto Enable_cpus;
local_irq_disable();
error = syscore_suspend();
if (error)
goto Enable_irqs;
save_processor_state();
error = restore_highmem();
if (!error) {
error = swsusp_arch_resume();
BUG_ON(!error);
restore_highmem();
}
swsusp_free();
restore_processor_state();
touch_softlockup_watchdog();
syscore_resume();
Enable_irqs:
local_irq_enable();
Enable_cpus:
enable_nonboot_cpus();
Cleanup:
platform_restore_cleanup(platform_mode);
dpm_resume_start(PMSG_RECOVER);
return error;
}
int hibernation_restore(int platform_mode)
{
int error;
pm_prepare_console();
suspend_console();
ftrace_stop();
pm_restrict_gfp_mask();
error = dpm_suspend_start(PMSG_QUIESCE);
if (!error) {
error = resume_target_kernel(platform_mode);
dpm_resume_end(PMSG_RECOVER);
}
pm_restore_gfp_mask();
ftrace_start();
resume_console();
pm_restore_console();
return error;
}
int hibernation_platform_enter(void)
{
int error;
if (!hibernation_ops)
return -ENOSYS;
error = hibernation_ops->begin();
if (error)
goto Close;
entering_platform_hibernation = true;
suspend_console();
ftrace_stop();
error = dpm_suspend_start(PMSG_HIBERNATE);
if (error) {
if (hibernation_ops->recover)
hibernation_ops->recover();
goto Resume_devices;
}
error = dpm_suspend_end(PMSG_HIBERNATE);
if (error)
goto Resume_devices;
error = hibernation_ops->prepare();
if (error)
goto Platform_finish;
error = disable_nonboot_cpus();
if (error)
goto Platform_finish;
local_irq_disable();
syscore_suspend();
if (pm_wakeup_pending()) {
error = -EAGAIN;
goto Power_up;
}
hibernation_ops->enter();
while (1);
Power_up:
syscore_resume();
local_irq_enable();
enable_nonboot_cpus();
Platform_finish:
hibernation_ops->finish();
dpm_resume_start(PMSG_RESTORE);
Resume_devices:
entering_platform_hibernation = false;
dpm_resume_end(PMSG_RESTORE);
ftrace_start();
resume_console();
Close:
hibernation_ops->end();
return error;
}
static void power_down(void)
{
#ifdef CONFIG_SUSPEND
int error;
#endif
switch (hibernation_mode) {
case HIBERNATION_REBOOT:
kernel_restart(NULL);
break;
case HIBERNATION_PLATFORM:
hibernation_platform_enter();
case HIBERNATION_SHUTDOWN:
kernel_power_off();
break;
#ifdef CONFIG_SUSPEND
case HIBERNATION_SUSPEND:
error = suspend_devices_and_enter(PM_SUSPEND_MEM);
if (error) {
if (hibernation_ops)
hibernation_mode = HIBERNATION_PLATFORM;
else
hibernation_mode = HIBERNATION_SHUTDOWN;
power_down();
}
error = swsusp_unmark();
if (error)
printk(KERN_ERR "PM: Swap will be unusable! "
"Try swapon -a.\n");
return;
#endif
}
kernel_halt();
printk(KERN_CRIT "PM: Please power down manually\n");
while(1);
}
int hibernate(void)
{
int error;
lock_system_sleep();
if (!atomic_add_unless(&snapshot_device_available, -1, 0)) {
error = -EBUSY;
goto Unlock;
}
pm_prepare_console();
error = pm_notifier_call_chain(PM_HIBERNATION_PREPARE);
if (error)
goto Exit;
error = create_basic_memory_bitmaps();
if (error)
goto Exit;
printk(KERN_INFO "PM: Syncing filesystems ... ");
sys_sync();
printk("done.\n");
error = freeze_processes();
if (error)
goto Free_bitmaps;
error = hibernation_snapshot(hibernation_mode == HIBERNATION_PLATFORM);
if (error || freezer_test_done)
goto Thaw;
if (in_suspend) {
unsigned int flags = 0;
if (hibernation_mode == HIBERNATION_PLATFORM)
flags |= SF_PLATFORM_MODE;
if (nocompress)
flags |= SF_NOCOMPRESS_MODE;
else
flags |= SF_CRC32_MODE;
pr_debug("PM: writing image.\n");
error = swsusp_write(flags);
swsusp_free();
if (!error)
power_down();
in_suspend = 0;
pm_restore_gfp_mask();
} else {
pr_debug("PM: Image restored successfully.\n");
}
Thaw:
thaw_processes();
freezer_test_done = false;
Free_bitmaps:
free_basic_memory_bitmaps();
Exit:
pm_notifier_call_chain(PM_POST_HIBERNATION);
pm_restore_console();
atomic_inc(&snapshot_device_available);
Unlock:
unlock_system_sleep();
return error;
}
static int software_resume(void)
{
int error;
unsigned int flags;
if (noresume)
return 0;
mutex_lock_nested(&pm_mutex, SINGLE_DEPTH_NESTING);
if (swsusp_resume_device)
goto Check_image;
if (!strlen(resume_file)) {
error = -ENOENT;
goto Unlock;
}
pr_debug("PM: Checking hibernation image partition %s\n", resume_file);
if (resume_delay) {
printk(KERN_INFO "Waiting %dsec before reading resume device...\n",
resume_delay);
ssleep(resume_delay);
}
swsusp_resume_device = name_to_dev_t(resume_file);
if (isdigit(resume_file[0]) && resume_wait) {
int partno;
while (!get_gendisk(swsusp_resume_device, &partno))
msleep(10);
}
if (!swsusp_resume_device) {
wait_for_device_probe();
if (resume_wait) {
while ((swsusp_resume_device = name_to_dev_t(resume_file)) == 0)
msleep(10);
async_synchronize_full();
}
swsusp_resume_device = name_to_dev_t(resume_file);
if (!swsusp_resume_device) {
error = -ENODEV;
goto Unlock;
}
}
Check_image:
pr_debug("PM: Hibernation image partition %d:%d present\n",
MAJOR(swsusp_resume_device), MINOR(swsusp_resume_device));
pr_debug("PM: Looking for hibernation image.\n");
error = swsusp_check();
if (error)
goto Unlock;
if (!atomic_add_unless(&snapshot_device_available, -1, 0)) {
error = -EBUSY;
swsusp_close(FMODE_READ);
goto Unlock;
}
pm_prepare_console();
error = pm_notifier_call_chain(PM_RESTORE_PREPARE);
if (error)
goto close_finish;
error = create_basic_memory_bitmaps();
if (error)
goto close_finish;
pr_debug("PM: Preparing processes for restore.\n");
error = freeze_processes();
if (error) {
swsusp_close(FMODE_READ);
goto Done;
}
pr_debug("PM: Loading hibernation image.\n");
error = swsusp_read(&flags);
swsusp_close(FMODE_READ);
if (!error)
hibernation_restore(flags & SF_PLATFORM_MODE);
printk(KERN_ERR "PM: Failed to load hibernation image, recovering.\n");
swsusp_free();
thaw_processes();
Done:
free_basic_memory_bitmaps();
Finish:
pm_notifier_call_chain(PM_POST_RESTORE);
pm_restore_console();
atomic_inc(&snapshot_device_available);
Unlock:
mutex_unlock(&pm_mutex);
pr_debug("PM: Hibernation image not present or could not be loaded.\n");
return error;
close_finish:
swsusp_close(FMODE_READ);
goto Finish;
}
static ssize_t disk_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
int i;
char *start = buf;
for (i = HIBERNATION_FIRST; i <= HIBERNATION_MAX; i++) {
if (!hibernation_modes[i])
continue;
switch (i) {
case HIBERNATION_SHUTDOWN:
case HIBERNATION_REBOOT:
#ifdef CONFIG_SUSPEND
case HIBERNATION_SUSPEND:
#endif
break;
case HIBERNATION_PLATFORM:
if (hibernation_ops)
break;
continue;
}
if (i == hibernation_mode)
buf += sprintf(buf, "[%s] ", hibernation_modes[i]);
else
buf += sprintf(buf, "%s ", hibernation_modes[i]);
}
buf += sprintf(buf, "\n");
return buf-start;
}
static ssize_t disk_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t n)
{
int error = 0;
int i;
int len;
char *p;
int mode = HIBERNATION_INVALID;
p = memchr(buf, '\n', n);
len = p ? p - buf : n;
lock_system_sleep();
for (i = HIBERNATION_FIRST; i <= HIBERNATION_MAX; i++) {
if (len == strlen(hibernation_modes[i])
&& !strncmp(buf, hibernation_modes[i], len)) {
mode = i;
break;
}
}
if (mode != HIBERNATION_INVALID) {
switch (mode) {
case HIBERNATION_SHUTDOWN:
case HIBERNATION_REBOOT:
#ifdef CONFIG_SUSPEND
case HIBERNATION_SUSPEND:
#endif
hibernation_mode = mode;
break;
case HIBERNATION_PLATFORM:
if (hibernation_ops)
hibernation_mode = mode;
else
error = -EINVAL;
}
} else
error = -EINVAL;
if (!error)
pr_debug("PM: Hibernation mode set to '%s'\n",
hibernation_modes[mode]);
unlock_system_sleep();
return error ? error : n;
}
static ssize_t resume_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf,"%d:%d\n", MAJOR(swsusp_resume_device),
MINOR(swsusp_resume_device));
}
static ssize_t resume_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t n)
{
unsigned int maj, min;
dev_t res;
int ret = -EINVAL;
if (sscanf(buf, "%u:%u", &maj, &min) != 2)
goto out;
res = MKDEV(maj,min);
if (maj != MAJOR(res) || min != MINOR(res))
goto out;
lock_system_sleep();
swsusp_resume_device = res;
unlock_system_sleep();
printk(KERN_INFO "PM: Starting manual resume from disk\n");
noresume = 0;
software_resume();
ret = n;
out:
return ret;
}
static ssize_t image_size_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%lu\n", image_size);
}
static ssize_t image_size_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t n)
{
unsigned long size;
if (sscanf(buf, "%lu", &size) == 1) {
image_size = size;
return n;
}
return -EINVAL;
}
static ssize_t reserved_size_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%lu\n", reserved_size);
}
static ssize_t reserved_size_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t n)
{
unsigned long size;
if (sscanf(buf, "%lu", &size) == 1) {
reserved_size = size;
return n;
}
return -EINVAL;
}
static int __init pm_disk_init(void)
{
return sysfs_create_group(power_kobj, &attr_group);
}
static int __init resume_setup(char *str)
{
if (noresume)
return 1;
strncpy( resume_file, str, 255 );
return 1;
}
static int __init resume_offset_setup(char *str)
{
unsigned long long offset;
if (noresume)
return 1;
if (sscanf(str, "%llu", &offset) == 1)
swsusp_resume_block = offset;
return 1;
}
static int __init hibernate_setup(char *str)
{
if (!strncmp(str, "noresume", 8))
noresume = 1;
else if (!strncmp(str, "nocompress", 10))
nocompress = 1;
return 1;
}
static int __init noresume_setup(char *str)
{
noresume = 1;
return 1;
}
static int __init resumewait_setup(char *str)
{
resume_wait = 1;
return 1;
}
static int __init resumedelay_setup(char *str)
{
resume_delay = simple_strtoul(str, NULL, 0);
return 1;
}
