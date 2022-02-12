static inline void tick_broadcast_clear_oneshot(int cpu) { }
struct tick_device *tick_get_broadcast_device(void)
{
return &tick_broadcast_device;
}
struct cpumask *tick_get_broadcast_mask(void)
{
return tick_broadcast_mask;
}
static void tick_broadcast_start_periodic(struct clock_event_device *bc)
{
if (bc)
tick_setup_periodic(bc, 1);
}
static bool tick_check_broadcast_device(struct clock_event_device *curdev,
struct clock_event_device *newdev)
{
if ((newdev->features & CLOCK_EVT_FEAT_DUMMY) ||
(newdev->features & CLOCK_EVT_FEAT_PERCPU) ||
(newdev->features & CLOCK_EVT_FEAT_C3STOP))
return false;
if (tick_broadcast_device.mode == TICKDEV_MODE_ONESHOT &&
!(newdev->features & CLOCK_EVT_FEAT_ONESHOT))
return false;
return !curdev || newdev->rating > curdev->rating;
}
void tick_install_broadcast_device(struct clock_event_device *dev)
{
struct clock_event_device *cur = tick_broadcast_device.evtdev;
if (!tick_check_broadcast_device(cur, dev))
return;
if (!try_module_get(dev->owner))
return;
clockevents_exchange_device(cur, dev);
if (cur)
cur->event_handler = clockevents_handle_noop;
tick_broadcast_device.evtdev = dev;
if (!cpumask_empty(tick_broadcast_mask))
tick_broadcast_start_periodic(dev);
if (dev->features & CLOCK_EVT_FEAT_ONESHOT)
tick_clock_notify();
}
int tick_is_broadcast_device(struct clock_event_device *dev)
{
return (dev && tick_broadcast_device.evtdev == dev);
}
int tick_broadcast_update_freq(struct clock_event_device *dev, u32 freq)
{
int ret = -ENODEV;
if (tick_is_broadcast_device(dev)) {
raw_spin_lock(&tick_broadcast_lock);
ret = __clockevents_update_freq(dev, freq);
raw_spin_unlock(&tick_broadcast_lock);
}
return ret;
}
static void err_broadcast(const struct cpumask *mask)
{
pr_crit_once("Failed to broadcast timer tick. Some CPUs may be unresponsive.\n");
}
static void tick_device_setup_broadcast_func(struct clock_event_device *dev)
{
if (!dev->broadcast)
dev->broadcast = tick_broadcast;
if (!dev->broadcast) {
pr_warn_once("%s depends on broadcast, but no broadcast function available\n",
dev->name);
dev->broadcast = err_broadcast;
}
}
int tick_device_uses_broadcast(struct clock_event_device *dev, int cpu)
{
struct clock_event_device *bc = tick_broadcast_device.evtdev;
unsigned long flags;
int ret;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
if (!tick_device_is_functional(dev)) {
dev->event_handler = tick_handle_periodic;
tick_device_setup_broadcast_func(dev);
cpumask_set_cpu(cpu, tick_broadcast_mask);
if (tick_broadcast_device.mode == TICKDEV_MODE_PERIODIC)
tick_broadcast_start_periodic(bc);
else
tick_broadcast_setup_oneshot(bc);
ret = 1;
} else {
if (!(dev->features & CLOCK_EVT_FEAT_C3STOP))
cpumask_clear_cpu(cpu, tick_broadcast_mask);
else
tick_device_setup_broadcast_func(dev);
if (!cpumask_test_cpu(cpu, tick_broadcast_on))
cpumask_clear_cpu(cpu, tick_broadcast_mask);
switch (tick_broadcast_device.mode) {
case TICKDEV_MODE_ONESHOT:
tick_broadcast_clear_oneshot(cpu);
ret = 0;
break;
case TICKDEV_MODE_PERIODIC:
if (cpumask_empty(tick_broadcast_mask) && bc)
clockevents_shutdown(bc);
ret = cpumask_test_cpu(cpu, tick_broadcast_mask);
break;
default:
ret = 0;
break;
}
}
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
return ret;
}
int tick_receive_broadcast(void)
{
struct tick_device *td = this_cpu_ptr(&tick_cpu_device);
struct clock_event_device *evt = td->evtdev;
if (!evt)
return -ENODEV;
if (!evt->event_handler)
return -EINVAL;
evt->event_handler(evt);
return 0;
}
static void tick_do_broadcast(struct cpumask *mask)
{
int cpu = smp_processor_id();
struct tick_device *td;
if (cpumask_test_cpu(cpu, mask)) {
cpumask_clear_cpu(cpu, mask);
td = &per_cpu(tick_cpu_device, cpu);
td->evtdev->event_handler(td->evtdev);
}
if (!cpumask_empty(mask)) {
td = &per_cpu(tick_cpu_device, cpumask_first(mask));
td->evtdev->broadcast(mask);
}
}
static void tick_do_periodic_broadcast(void)
{
cpumask_and(tmpmask, cpu_online_mask, tick_broadcast_mask);
tick_do_broadcast(tmpmask);
}
static void tick_handle_periodic_broadcast(struct clock_event_device *dev)
{
ktime_t next;
raw_spin_lock(&tick_broadcast_lock);
tick_do_periodic_broadcast();
if (dev->mode == CLOCK_EVT_MODE_PERIODIC)
goto unlock;
for (next = dev->next_event; ;) {
next = ktime_add(next, tick_period);
if (!clockevents_program_event(dev, next, false))
goto unlock;
tick_do_periodic_broadcast();
}
unlock:
raw_spin_unlock(&tick_broadcast_lock);
}
static void tick_do_broadcast_on_off(unsigned long *reason)
{
struct clock_event_device *bc, *dev;
struct tick_device *td;
unsigned long flags;
int cpu, bc_stopped;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
cpu = smp_processor_id();
td = &per_cpu(tick_cpu_device, cpu);
dev = td->evtdev;
bc = tick_broadcast_device.evtdev;
if (!dev || !(dev->features & CLOCK_EVT_FEAT_C3STOP))
goto out;
if (!tick_device_is_functional(dev))
goto out;
bc_stopped = cpumask_empty(tick_broadcast_mask);
switch (*reason) {
case CLOCK_EVT_NOTIFY_BROADCAST_ON:
case CLOCK_EVT_NOTIFY_BROADCAST_FORCE:
cpumask_set_cpu(cpu, tick_broadcast_on);
if (!cpumask_test_and_set_cpu(cpu, tick_broadcast_mask)) {
if (tick_broadcast_device.mode ==
TICKDEV_MODE_PERIODIC)
clockevents_shutdown(dev);
}
if (*reason == CLOCK_EVT_NOTIFY_BROADCAST_FORCE)
tick_broadcast_force = 1;
break;
case CLOCK_EVT_NOTIFY_BROADCAST_OFF:
if (tick_broadcast_force)
break;
cpumask_clear_cpu(cpu, tick_broadcast_on);
if (!tick_device_is_functional(dev))
break;
if (cpumask_test_and_clear_cpu(cpu, tick_broadcast_mask)) {
if (tick_broadcast_device.mode ==
TICKDEV_MODE_PERIODIC)
tick_setup_periodic(dev, 0);
}
break;
}
if (cpumask_empty(tick_broadcast_mask)) {
if (!bc_stopped)
clockevents_shutdown(bc);
} else if (bc_stopped) {
if (tick_broadcast_device.mode == TICKDEV_MODE_PERIODIC)
tick_broadcast_start_periodic(bc);
else
tick_broadcast_setup_oneshot(bc);
}
out:
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
}
void tick_broadcast_on_off(unsigned long reason, int *oncpu)
{
if (!cpumask_test_cpu(*oncpu, cpu_online_mask))
printk(KERN_ERR "tick-broadcast: ignoring broadcast for "
"offline CPU #%d\n", *oncpu);
else
tick_do_broadcast_on_off(&reason);
}
void tick_set_periodic_handler(struct clock_event_device *dev, int broadcast)
{
if (!broadcast)
dev->event_handler = tick_handle_periodic;
else
dev->event_handler = tick_handle_periodic_broadcast;
}
void tick_shutdown_broadcast(unsigned int *cpup)
{
struct clock_event_device *bc;
unsigned long flags;
unsigned int cpu = *cpup;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
bc = tick_broadcast_device.evtdev;
cpumask_clear_cpu(cpu, tick_broadcast_mask);
cpumask_clear_cpu(cpu, tick_broadcast_on);
if (tick_broadcast_device.mode == TICKDEV_MODE_PERIODIC) {
if (bc && cpumask_empty(tick_broadcast_mask))
clockevents_shutdown(bc);
}
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
}
void tick_suspend_broadcast(void)
{
struct clock_event_device *bc;
unsigned long flags;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
bc = tick_broadcast_device.evtdev;
if (bc)
clockevents_shutdown(bc);
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
}
int tick_resume_broadcast(void)
{
struct clock_event_device *bc;
unsigned long flags;
int broadcast = 0;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
bc = tick_broadcast_device.evtdev;
if (bc) {
clockevents_set_mode(bc, CLOCK_EVT_MODE_RESUME);
switch (tick_broadcast_device.mode) {
case TICKDEV_MODE_PERIODIC:
if (!cpumask_empty(tick_broadcast_mask))
tick_broadcast_start_periodic(bc);
broadcast = cpumask_test_cpu(smp_processor_id(),
tick_broadcast_mask);
break;
case TICKDEV_MODE_ONESHOT:
if (!cpumask_empty(tick_broadcast_mask))
broadcast = tick_resume_broadcast_oneshot(bc);
break;
}
}
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
return broadcast;
}
struct cpumask *tick_get_broadcast_oneshot_mask(void)
{
return tick_broadcast_oneshot_mask;
}
int tick_check_broadcast_expired(void)
{
return cpumask_test_cpu(smp_processor_id(), tick_broadcast_force_mask);
}
static void tick_broadcast_set_affinity(struct clock_event_device *bc,
const struct cpumask *cpumask)
{
if (!(bc->features & CLOCK_EVT_FEAT_DYNIRQ))
return;
if (cpumask_equal(bc->cpumask, cpumask))
return;
bc->cpumask = cpumask;
irq_set_affinity(bc->irq, bc->cpumask);
}
static int tick_broadcast_set_event(struct clock_event_device *bc, int cpu,
ktime_t expires, int force)
{
int ret;
if (bc->mode != CLOCK_EVT_MODE_ONESHOT)
clockevents_set_mode(bc, CLOCK_EVT_MODE_ONESHOT);
ret = clockevents_program_event(bc, expires, force);
if (!ret)
tick_broadcast_set_affinity(bc, cpumask_of(cpu));
return ret;
}
int tick_resume_broadcast_oneshot(struct clock_event_device *bc)
{
clockevents_set_mode(bc, CLOCK_EVT_MODE_ONESHOT);
return 0;
}
void tick_check_oneshot_broadcast_this_cpu(void)
{
if (cpumask_test_cpu(smp_processor_id(), tick_broadcast_oneshot_mask)) {
struct tick_device *td = this_cpu_ptr(&tick_cpu_device);
if (td->mode == TICKDEV_MODE_ONESHOT) {
clockevents_set_mode(td->evtdev,
CLOCK_EVT_MODE_ONESHOT);
}
}
}
static void tick_handle_oneshot_broadcast(struct clock_event_device *dev)
{
struct tick_device *td;
ktime_t now, next_event;
int cpu, next_cpu = 0;
raw_spin_lock(&tick_broadcast_lock);
again:
dev->next_event.tv64 = KTIME_MAX;
next_event.tv64 = KTIME_MAX;
cpumask_clear(tmpmask);
now = ktime_get();
for_each_cpu(cpu, tick_broadcast_oneshot_mask) {
td = &per_cpu(tick_cpu_device, cpu);
if (td->evtdev->next_event.tv64 <= now.tv64) {
cpumask_set_cpu(cpu, tmpmask);
cpumask_set_cpu(cpu, tick_broadcast_pending_mask);
} else if (td->evtdev->next_event.tv64 < next_event.tv64) {
next_event.tv64 = td->evtdev->next_event.tv64;
next_cpu = cpu;
}
}
cpumask_clear_cpu(smp_processor_id(), tick_broadcast_pending_mask);
cpumask_or(tmpmask, tmpmask, tick_broadcast_force_mask);
cpumask_clear(tick_broadcast_force_mask);
if (WARN_ON_ONCE(!cpumask_subset(tmpmask, cpu_online_mask)))
cpumask_and(tmpmask, tmpmask, cpu_online_mask);
tick_do_broadcast(tmpmask);
if (next_event.tv64 != KTIME_MAX) {
if (tick_broadcast_set_event(dev, next_cpu, next_event, 0))
goto again;
}
raw_spin_unlock(&tick_broadcast_lock);
}
static int broadcast_needs_cpu(struct clock_event_device *bc, int cpu)
{
if (!(bc->features & CLOCK_EVT_FEAT_HRTIMER))
return 0;
if (bc->next_event.tv64 == KTIME_MAX)
return 0;
return bc->bound_on == cpu ? -EBUSY : 0;
}
static void broadcast_shutdown_local(struct clock_event_device *bc,
struct clock_event_device *dev)
{
if (bc->features & CLOCK_EVT_FEAT_HRTIMER) {
if (broadcast_needs_cpu(bc, smp_processor_id()))
return;
if (dev->next_event.tv64 < bc->next_event.tv64)
return;
}
clockevents_set_mode(dev, CLOCK_EVT_MODE_SHUTDOWN);
}
static void broadcast_move_bc(int deadcpu)
{
struct clock_event_device *bc = tick_broadcast_device.evtdev;
if (!bc || !broadcast_needs_cpu(bc, deadcpu))
return;
clockevents_program_event(bc, bc->next_event, 1);
}
int tick_broadcast_oneshot_control(unsigned long reason)
{
struct clock_event_device *bc, *dev;
struct tick_device *td;
unsigned long flags;
ktime_t now;
int cpu, ret = 0;
if (tick_broadcast_device.mode == TICKDEV_MODE_PERIODIC)
return 0;
cpu = smp_processor_id();
td = &per_cpu(tick_cpu_device, cpu);
dev = td->evtdev;
if (!(dev->features & CLOCK_EVT_FEAT_C3STOP))
return 0;
bc = tick_broadcast_device.evtdev;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
if (reason == CLOCK_EVT_NOTIFY_BROADCAST_ENTER) {
if (!cpumask_test_and_set_cpu(cpu, tick_broadcast_oneshot_mask)) {
WARN_ON_ONCE(cpumask_test_cpu(cpu, tick_broadcast_pending_mask));
broadcast_shutdown_local(bc, dev);
if (!cpumask_test_cpu(cpu, tick_broadcast_force_mask) &&
dev->next_event.tv64 < bc->next_event.tv64)
tick_broadcast_set_event(bc, cpu, dev->next_event, 1);
}
ret = broadcast_needs_cpu(bc, cpu);
if (ret)
cpumask_clear_cpu(cpu, tick_broadcast_oneshot_mask);
} else {
if (cpumask_test_and_clear_cpu(cpu, tick_broadcast_oneshot_mask)) {
clockevents_set_mode(dev, CLOCK_EVT_MODE_ONESHOT);
if (cpumask_test_and_clear_cpu(cpu,
tick_broadcast_pending_mask))
goto out;
if (dev->next_event.tv64 == KTIME_MAX)
goto out;
now = ktime_get();
if (dev->next_event.tv64 <= now.tv64) {
cpumask_set_cpu(cpu, tick_broadcast_force_mask);
goto out;
}
tick_program_event(dev->next_event, 1);
}
}
out:
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
return ret;
}
static void tick_broadcast_clear_oneshot(int cpu)
{
cpumask_clear_cpu(cpu, tick_broadcast_oneshot_mask);
cpumask_clear_cpu(cpu, tick_broadcast_pending_mask);
}
static void tick_broadcast_init_next_event(struct cpumask *mask,
ktime_t expires)
{
struct tick_device *td;
int cpu;
for_each_cpu(cpu, mask) {
td = &per_cpu(tick_cpu_device, cpu);
if (td->evtdev)
td->evtdev->next_event = expires;
}
}
void tick_broadcast_setup_oneshot(struct clock_event_device *bc)
{
int cpu = smp_processor_id();
if (bc->event_handler != tick_handle_oneshot_broadcast) {
int was_periodic = bc->mode == CLOCK_EVT_MODE_PERIODIC;
bc->event_handler = tick_handle_oneshot_broadcast;
cpumask_copy(tmpmask, tick_broadcast_mask);
cpumask_clear_cpu(cpu, tmpmask);
cpumask_or(tick_broadcast_oneshot_mask,
tick_broadcast_oneshot_mask, tmpmask);
if (was_periodic && !cpumask_empty(tmpmask)) {
clockevents_set_mode(bc, CLOCK_EVT_MODE_ONESHOT);
tick_broadcast_init_next_event(tmpmask,
tick_next_period);
tick_broadcast_set_event(bc, cpu, tick_next_period, 1);
} else
bc->next_event.tv64 = KTIME_MAX;
} else {
tick_broadcast_clear_oneshot(cpu);
}
}
void tick_broadcast_switch_to_oneshot(void)
{
struct clock_event_device *bc;
unsigned long flags;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
tick_broadcast_device.mode = TICKDEV_MODE_ONESHOT;
bc = tick_broadcast_device.evtdev;
if (bc)
tick_broadcast_setup_oneshot(bc);
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
}
void tick_shutdown_broadcast_oneshot(unsigned int *cpup)
{
unsigned long flags;
unsigned int cpu = *cpup;
raw_spin_lock_irqsave(&tick_broadcast_lock, flags);
cpumask_clear_cpu(cpu, tick_broadcast_oneshot_mask);
cpumask_clear_cpu(cpu, tick_broadcast_pending_mask);
cpumask_clear_cpu(cpu, tick_broadcast_force_mask);
broadcast_move_bc(cpu);
raw_spin_unlock_irqrestore(&tick_broadcast_lock, flags);
}
int tick_broadcast_oneshot_active(void)
{
return tick_broadcast_device.mode == TICKDEV_MODE_ONESHOT;
}
bool tick_broadcast_oneshot_available(void)
{
struct clock_event_device *bc = tick_broadcast_device.evtdev;
return bc ? bc->features & CLOCK_EVT_FEAT_ONESHOT : false;
}
void __init tick_broadcast_init(void)
{
zalloc_cpumask_var(&tick_broadcast_mask, GFP_NOWAIT);
zalloc_cpumask_var(&tick_broadcast_on, GFP_NOWAIT);
zalloc_cpumask_var(&tmpmask, GFP_NOWAIT);
#ifdef CONFIG_TICK_ONESHOT
zalloc_cpumask_var(&tick_broadcast_oneshot_mask, GFP_NOWAIT);
zalloc_cpumask_var(&tick_broadcast_pending_mask, GFP_NOWAIT);
zalloc_cpumask_var(&tick_broadcast_force_mask, GFP_NOWAIT);
#endif
}
