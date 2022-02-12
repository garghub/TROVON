static void frontswap_selfshrink(void)
{
static unsigned long cur_frontswap_pages;
static unsigned long last_frontswap_pages;
static unsigned long tgt_frontswap_pages;
last_frontswap_pages = cur_frontswap_pages;
cur_frontswap_pages = frontswap_curr_pages();
if (!cur_frontswap_pages ||
(cur_frontswap_pages > last_frontswap_pages)) {
frontswap_inertia_counter = frontswap_inertia;
return;
}
if (frontswap_inertia_counter && --frontswap_inertia_counter)
return;
if (cur_frontswap_pages <= frontswap_hysteresis)
tgt_frontswap_pages = 0;
else
tgt_frontswap_pages = cur_frontswap_pages -
(cur_frontswap_pages / frontswap_hysteresis);
frontswap_shrink(tgt_frontswap_pages);
}
static int __init xen_nofrontswap_selfshrink_setup(char *s)
{
use_frontswap_selfshrink = false;
return 1;
}
static int __init xen_noselfballooning_setup(char *s)
{
use_selfballooning = false;
return 1;
}
static int __init xen_selfballooning_setup(char *s)
{
use_selfballooning = true;
return 1;
}
static void selfballoon_process(struct work_struct *work)
{
unsigned long cur_pages, goal_pages, tgt_pages;
bool reset_timer = false;
if (xen_selfballooning_enabled) {
cur_pages = balloon_stats.current_pages;
tgt_pages = cur_pages;
goal_pages = percpu_counter_read_positive(&vm_committed_as) +
balloon_stats.current_pages - totalram_pages;
#ifdef CONFIG_FRONTSWAP
if (frontswap_selfshrinking && frontswap_enabled)
goal_pages += frontswap_curr_pages();
#endif
if (cur_pages > goal_pages)
tgt_pages = cur_pages -
((cur_pages - goal_pages) /
selfballoon_downhysteresis);
else if (cur_pages < goal_pages)
tgt_pages = cur_pages +
((goal_pages - cur_pages) /
selfballoon_uphysteresis);
balloon_set_new_target(tgt_pages);
reset_timer = true;
}
#ifdef CONFIG_FRONTSWAP
if (frontswap_selfshrinking && frontswap_enabled) {
frontswap_selfshrink();
reset_timer = true;
}
#endif
if (reset_timer)
schedule_delayed_work(&selfballoon_worker,
selfballoon_interval * HZ);
}
static ssize_t store_selfballooning(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf,
size_t count)
{
bool was_enabled = xen_selfballooning_enabled;
unsigned long tmp;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
err = strict_strtoul(buf, 10, &tmp);
if (err || ((tmp != 0) && (tmp != 1)))
return -EINVAL;
xen_selfballooning_enabled = !!tmp;
if (!was_enabled && xen_selfballooning_enabled)
schedule_delayed_work(&selfballoon_worker,
selfballoon_interval * HZ);
return count;
}
static ssize_t store_selfballoon_interval(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf,
size_t count)
{
unsigned long val;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
err = strict_strtoul(buf, 10, &val);
if (err || val == 0)
return -EINVAL;
selfballoon_interval = val;
return count;
}
static ssize_t store_selfballoon_downhys(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf,
size_t count)
{
unsigned long val;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
err = strict_strtoul(buf, 10, &val);
if (err || val == 0)
return -EINVAL;
selfballoon_downhysteresis = val;
return count;
}
static ssize_t store_selfballoon_uphys(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf,
size_t count)
{
unsigned long val;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
err = strict_strtoul(buf, 10, &val);
if (err || val == 0)
return -EINVAL;
selfballoon_uphysteresis = val;
return count;
}
static ssize_t store_frontswap_selfshrinking(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf,
size_t count)
{
bool was_enabled = frontswap_selfshrinking;
unsigned long tmp;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
err = strict_strtoul(buf, 10, &tmp);
if (err || ((tmp != 0) && (tmp != 1)))
return -EINVAL;
frontswap_selfshrinking = !!tmp;
if (!was_enabled && !xen_selfballooning_enabled &&
frontswap_selfshrinking)
schedule_delayed_work(&selfballoon_worker,
selfballoon_interval * HZ);
return count;
}
static ssize_t store_frontswap_inertia(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf,
size_t count)
{
unsigned long val;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
err = strict_strtoul(buf, 10, &val);
if (err || val == 0)
return -EINVAL;
frontswap_inertia = val;
frontswap_inertia_counter = val;
return count;
}
static ssize_t store_frontswap_hysteresis(struct sys_device *dev,
struct sysdev_attribute *attr,
const char *buf,
size_t count)
{
unsigned long val;
int err;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
err = strict_strtoul(buf, 10, &val);
if (err || val == 0)
return -EINVAL;
frontswap_hysteresis = val;
return count;
}
int register_xen_selfballooning(struct sys_device *sysdev)
{
int error = -1;
#ifdef CONFIG_SYSFS
error = sysfs_create_group(&sysdev->kobj, &selfballoon_group);
#endif
return error;
}
static int __init xen_selfballoon_init(void)
{
bool enable = false;
if (!xen_domain())
return -ENODEV;
if (xen_initial_domain()) {
pr_info("xen/balloon: Xen selfballooning driver "
"disabled for domain0.\n");
return -ENODEV;
}
xen_selfballooning_enabled = tmem_enabled && use_selfballooning;
if (xen_selfballooning_enabled) {
pr_info("xen/balloon: Initializing Xen "
"selfballooning driver.\n");
enable = true;
}
#ifdef CONFIG_FRONTSWAP
frontswap_selfshrinking = tmem_enabled && use_frontswap_selfshrink;
if (frontswap_selfshrinking) {
pr_info("xen/balloon: Initializing frontswap "
"selfshrinking driver.\n");
enable = true;
}
#endif
if (!enable)
return -ENODEV;
schedule_delayed_work(&selfballoon_worker, selfballoon_interval * HZ);
return 0;
}
