static u64 cev_delta2ns(unsigned long latch, struct clock_event_device *evt,
bool ismax)
{
u64 clc = (u64) latch << evt->shift;
u64 rnd;
if (unlikely(!evt->mult)) {
evt->mult = 1;
WARN_ON(1);
}
rnd = (u64) evt->mult - 1;
if ((clc >> evt->shift) != (u64)latch)
clc = ~0ULL;
if ((~0ULL - clc > rnd) &&
(!ismax || evt->mult <= (1ULL << evt->shift)))
clc += rnd;
do_div(clc, evt->mult);
return clc > 1000 ? clc : 1000;
}
u64 clockevent_delta2ns(unsigned long latch, struct clock_event_device *evt)
{
return cev_delta2ns(latch, evt, false);
}
static int __clockevents_switch_state(struct clock_event_device *dev,
enum clock_event_state state)
{
if (dev->set_mode) {
if (state > CLOCK_EVT_STATE_ONESHOT)
return -ENOSYS;
dev->set_mode((enum clock_event_mode)state, dev);
dev->mode = (enum clock_event_mode)state;
return 0;
}
if (dev->features & CLOCK_EVT_FEAT_DUMMY)
return 0;
switch (state) {
case CLOCK_EVT_STATE_DETACHED:
case CLOCK_EVT_STATE_SHUTDOWN:
if (dev->set_state_shutdown)
return dev->set_state_shutdown(dev);
return 0;
case CLOCK_EVT_STATE_PERIODIC:
if (!(dev->features & CLOCK_EVT_FEAT_PERIODIC))
return -ENOSYS;
if (dev->set_state_periodic)
return dev->set_state_periodic(dev);
return 0;
case CLOCK_EVT_STATE_ONESHOT:
if (!(dev->features & CLOCK_EVT_FEAT_ONESHOT))
return -ENOSYS;
if (dev->set_state_oneshot)
return dev->set_state_oneshot(dev);
return 0;
case CLOCK_EVT_STATE_ONESHOT_STOPPED:
if (WARN_ONCE(!clockevent_state_oneshot(dev),
"Current state: %d\n",
clockevent_get_state(dev)))
return -EINVAL;
if (dev->set_state_oneshot_stopped)
return dev->set_state_oneshot_stopped(dev);
else
return -ENOSYS;
default:
return -ENOSYS;
}
}
void clockevents_switch_state(struct clock_event_device *dev,
enum clock_event_state state)
{
if (clockevent_get_state(dev) != state) {
if (__clockevents_switch_state(dev, state))
return;
clockevent_set_state(dev, state);
if (clockevent_state_oneshot(dev)) {
if (unlikely(!dev->mult)) {
dev->mult = 1;
WARN_ON(1);
}
}
}
}
void clockevents_shutdown(struct clock_event_device *dev)
{
clockevents_switch_state(dev, CLOCK_EVT_STATE_SHUTDOWN);
dev->next_event.tv64 = KTIME_MAX;
}
int clockevents_tick_resume(struct clock_event_device *dev)
{
int ret = 0;
if (dev->set_mode) {
dev->set_mode(CLOCK_EVT_MODE_RESUME, dev);
dev->mode = CLOCK_EVT_MODE_RESUME;
} else if (dev->tick_resume) {
ret = dev->tick_resume(dev);
}
return ret;
}
static int clockevents_increase_min_delta(struct clock_event_device *dev)
{
if (dev->min_delta_ns >= MIN_DELTA_LIMIT) {
printk_deferred(KERN_WARNING
"CE: Reprogramming failure. Giving up\n");
dev->next_event.tv64 = KTIME_MAX;
return -ETIME;
}
if (dev->min_delta_ns < 5000)
dev->min_delta_ns = 5000;
else
dev->min_delta_ns += dev->min_delta_ns >> 1;
if (dev->min_delta_ns > MIN_DELTA_LIMIT)
dev->min_delta_ns = MIN_DELTA_LIMIT;
printk_deferred(KERN_WARNING
"CE: %s increased min_delta_ns to %llu nsec\n",
dev->name ? dev->name : "?",
(unsigned long long) dev->min_delta_ns);
return 0;
}
static int clockevents_program_min_delta(struct clock_event_device *dev)
{
unsigned long long clc;
int64_t delta;
int i;
for (i = 0;;) {
delta = dev->min_delta_ns;
dev->next_event = ktime_add_ns(ktime_get(), delta);
if (clockevent_state_shutdown(dev))
return 0;
dev->retries++;
clc = ((unsigned long long) delta * dev->mult) >> dev->shift;
if (dev->set_next_event((unsigned long) clc, dev) == 0)
return 0;
if (++i > 2) {
if (clockevents_increase_min_delta(dev))
return -ETIME;
i = 0;
}
}
}
static int clockevents_program_min_delta(struct clock_event_device *dev)
{
unsigned long long clc;
int64_t delta;
delta = dev->min_delta_ns;
dev->next_event = ktime_add_ns(ktime_get(), delta);
if (clockevent_state_shutdown(dev))
return 0;
dev->retries++;
clc = ((unsigned long long) delta * dev->mult) >> dev->shift;
return dev->set_next_event((unsigned long) clc, dev);
}
int clockevents_program_event(struct clock_event_device *dev, ktime_t expires,
bool force)
{
unsigned long long clc;
int64_t delta;
int rc;
if (unlikely(expires.tv64 < 0)) {
WARN_ON_ONCE(1);
return -ETIME;
}
dev->next_event = expires;
if (clockevent_state_shutdown(dev))
return 0;
WARN_ONCE(!clockevent_state_oneshot(dev), "Current state: %d\n",
clockevent_get_state(dev));
if (dev->features & CLOCK_EVT_FEAT_KTIME)
return dev->set_next_ktime(expires, dev);
delta = ktime_to_ns(ktime_sub(expires, ktime_get()));
if (delta <= 0)
return force ? clockevents_program_min_delta(dev) : -ETIME;
delta = min(delta, (int64_t) dev->max_delta_ns);
delta = max(delta, (int64_t) dev->min_delta_ns);
clc = ((unsigned long long) delta * dev->mult) >> dev->shift;
rc = dev->set_next_event((unsigned long) clc, dev);
return (rc && force) ? clockevents_program_min_delta(dev) : rc;
}
static void clockevents_notify_released(void)
{
struct clock_event_device *dev;
while (!list_empty(&clockevents_released)) {
dev = list_entry(clockevents_released.next,
struct clock_event_device, list);
list_del(&dev->list);
list_add(&dev->list, &clockevent_devices);
tick_check_new_device(dev);
}
}
static int clockevents_replace(struct clock_event_device *ced)
{
struct clock_event_device *dev, *newdev = NULL;
list_for_each_entry(dev, &clockevent_devices, list) {
if (dev == ced || !clockevent_state_detached(dev))
continue;
if (!tick_check_replacement(newdev, dev))
continue;
if (!try_module_get(dev->owner))
continue;
if (newdev)
module_put(newdev->owner);
newdev = dev;
}
if (newdev) {
tick_install_replacement(newdev);
list_del_init(&ced->list);
}
return newdev ? 0 : -EBUSY;
}
static int __clockevents_try_unbind(struct clock_event_device *ced, int cpu)
{
if (clockevent_state_detached(ced)) {
list_del_init(&ced->list);
return 0;
}
return ced == per_cpu(tick_cpu_device, cpu).evtdev ? -EAGAIN : -EBUSY;
}
static void __clockevents_unbind(void *arg)
{
struct ce_unbind *cu = arg;
int res;
raw_spin_lock(&clockevents_lock);
res = __clockevents_try_unbind(cu->ce, smp_processor_id());
if (res == -EAGAIN)
res = clockevents_replace(cu->ce);
cu->res = res;
raw_spin_unlock(&clockevents_lock);
}
static int clockevents_unbind(struct clock_event_device *ced, int cpu)
{
struct ce_unbind cu = { .ce = ced, .res = -ENODEV };
smp_call_function_single(cpu, __clockevents_unbind, &cu, 1);
return cu.res;
}
int clockevents_unbind_device(struct clock_event_device *ced, int cpu)
{
int ret;
mutex_lock(&clockevents_mutex);
ret = clockevents_unbind(ced, cpu);
mutex_unlock(&clockevents_mutex);
return ret;
}
static int clockevents_sanity_check(struct clock_event_device *dev)
{
if (dev->set_mode) {
WARN_ON(dev->set_state_periodic || dev->set_state_oneshot ||
dev->set_state_shutdown || dev->tick_resume ||
dev->set_state_oneshot_stopped);
BUG_ON(dev->mode != CLOCK_EVT_MODE_UNUSED);
return 0;
}
if (dev->features & CLOCK_EVT_FEAT_DUMMY)
return 0;
return 0;
}
void clockevents_register_device(struct clock_event_device *dev)
{
unsigned long flags;
BUG_ON(clockevents_sanity_check(dev));
clockevent_set_state(dev, CLOCK_EVT_STATE_DETACHED);
if (!dev->cpumask) {
WARN_ON(num_possible_cpus() > 1);
dev->cpumask = cpumask_of(smp_processor_id());
}
raw_spin_lock_irqsave(&clockevents_lock, flags);
list_add(&dev->list, &clockevent_devices);
tick_check_new_device(dev);
clockevents_notify_released();
raw_spin_unlock_irqrestore(&clockevents_lock, flags);
}
void clockevents_config(struct clock_event_device *dev, u32 freq)
{
u64 sec;
if (!(dev->features & CLOCK_EVT_FEAT_ONESHOT))
return;
sec = dev->max_delta_ticks;
do_div(sec, freq);
if (!sec)
sec = 1;
else if (sec > 600 && dev->max_delta_ticks > UINT_MAX)
sec = 600;
clockevents_calc_mult_shift(dev, freq, sec);
dev->min_delta_ns = cev_delta2ns(dev->min_delta_ticks, dev, false);
dev->max_delta_ns = cev_delta2ns(dev->max_delta_ticks, dev, true);
}
void clockevents_config_and_register(struct clock_event_device *dev,
u32 freq, unsigned long min_delta,
unsigned long max_delta)
{
dev->min_delta_ticks = min_delta;
dev->max_delta_ticks = max_delta;
clockevents_config(dev, freq);
clockevents_register_device(dev);
}
int __clockevents_update_freq(struct clock_event_device *dev, u32 freq)
{
clockevents_config(dev, freq);
if (clockevent_state_oneshot(dev))
return clockevents_program_event(dev, dev->next_event, false);
if (clockevent_state_periodic(dev))
return __clockevents_switch_state(dev, CLOCK_EVT_STATE_PERIODIC);
return 0;
}
int clockevents_update_freq(struct clock_event_device *dev, u32 freq)
{
unsigned long flags;
int ret;
local_irq_save(flags);
ret = tick_broadcast_update_freq(dev, freq);
if (ret == -ENODEV)
ret = __clockevents_update_freq(dev, freq);
local_irq_restore(flags);
return ret;
}
void clockevents_handle_noop(struct clock_event_device *dev)
{
}
void clockevents_exchange_device(struct clock_event_device *old,
struct clock_event_device *new)
{
if (old) {
module_put(old->owner);
clockevents_switch_state(old, CLOCK_EVT_STATE_DETACHED);
list_del(&old->list);
list_add(&old->list, &clockevents_released);
}
if (new) {
BUG_ON(!clockevent_state_detached(new));
clockevents_shutdown(new);
}
}
void clockevents_suspend(void)
{
struct clock_event_device *dev;
list_for_each_entry_reverse(dev, &clockevent_devices, list)
if (dev->suspend && !clockevent_state_detached(dev))
dev->suspend(dev);
}
void clockevents_resume(void)
{
struct clock_event_device *dev;
list_for_each_entry(dev, &clockevent_devices, list)
if (dev->resume && !clockevent_state_detached(dev))
dev->resume(dev);
}
void tick_cleanup_dead_cpu(int cpu)
{
struct clock_event_device *dev, *tmp;
unsigned long flags;
raw_spin_lock_irqsave(&clockevents_lock, flags);
tick_shutdown_broadcast_oneshot(cpu);
tick_shutdown_broadcast(cpu);
tick_shutdown(cpu);
list_for_each_entry_safe(dev, tmp, &clockevents_released, list)
list_del(&dev->list);
list_for_each_entry_safe(dev, tmp, &clockevent_devices, list) {
if (cpumask_test_cpu(cpu, dev->cpumask) &&
cpumask_weight(dev->cpumask) == 1 &&
!tick_is_broadcast_device(dev)) {
BUG_ON(!clockevent_state_detached(dev));
list_del(&dev->list);
}
}
raw_spin_unlock_irqrestore(&clockevents_lock, flags);
}
static ssize_t sysfs_show_current_tick_dev(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct tick_device *td;
ssize_t count = 0;
raw_spin_lock_irq(&clockevents_lock);
td = tick_get_tick_dev(dev);
if (td && td->evtdev)
count = snprintf(buf, PAGE_SIZE, "%s\n", td->evtdev->name);
raw_spin_unlock_irq(&clockevents_lock);
return count;
}
static ssize_t sysfs_unbind_tick_dev(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
char name[CS_NAME_LEN];
ssize_t ret = sysfs_get_uname(buf, name, count);
struct clock_event_device *ce;
if (ret < 0)
return ret;
ret = -ENODEV;
mutex_lock(&clockevents_mutex);
raw_spin_lock_irq(&clockevents_lock);
list_for_each_entry(ce, &clockevent_devices, list) {
if (!strcmp(ce->name, name)) {
ret = __clockevents_try_unbind(ce, dev->id);
break;
}
}
raw_spin_unlock_irq(&clockevents_lock);
if (ret == -EAGAIN)
ret = clockevents_unbind(ce, dev->id);
mutex_unlock(&clockevents_mutex);
return ret ? ret : count;
}
static struct tick_device *tick_get_tick_dev(struct device *dev)
{
return dev == &tick_bc_dev ? tick_get_broadcast_device() :
&per_cpu(tick_cpu_device, dev->id);
}
static __init int tick_broadcast_init_sysfs(void)
{
int err = device_register(&tick_bc_dev);
if (!err)
err = device_create_file(&tick_bc_dev, &dev_attr_current_device);
return err;
}
static struct tick_device *tick_get_tick_dev(struct device *dev)
{
return &per_cpu(tick_cpu_device, dev->id);
}
static inline int tick_broadcast_init_sysfs(void) { return 0; }
static int __init tick_init_sysfs(void)
{
int cpu;
for_each_possible_cpu(cpu) {
struct device *dev = &per_cpu(tick_percpu_dev, cpu);
int err;
dev->id = cpu;
dev->bus = &clockevents_subsys;
err = device_register(dev);
if (!err)
err = device_create_file(dev, &dev_attr_current_device);
if (!err)
err = device_create_file(dev, &dev_attr_unbind_device);
if (err)
return err;
}
return tick_broadcast_init_sysfs();
}
static int __init clockevents_init_sysfs(void)
{
int err = subsys_system_register(&clockevents_subsys, NULL);
if (!err)
err = tick_init_sysfs();
return err;
}
