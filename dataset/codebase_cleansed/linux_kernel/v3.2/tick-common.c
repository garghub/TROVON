struct tick_device *tick_get_device(int cpu)
{
return &per_cpu(tick_cpu_device, cpu);
}
int tick_is_oneshot_available(void)
{
struct clock_event_device *dev = __this_cpu_read(tick_cpu_device.evtdev);
if (!dev || !(dev->features & CLOCK_EVT_FEAT_ONESHOT))
return 0;
if (!(dev->features & CLOCK_EVT_FEAT_C3STOP))
return 1;
return tick_broadcast_oneshot_available();
}
static void tick_periodic(int cpu)
{
if (tick_do_timer_cpu == cpu) {
write_seqlock(&xtime_lock);
tick_next_period = ktime_add(tick_next_period, tick_period);
do_timer(1);
write_sequnlock(&xtime_lock);
}
update_process_times(user_mode(get_irq_regs()));
profile_tick(CPU_PROFILING);
}
void tick_handle_periodic(struct clock_event_device *dev)
{
int cpu = smp_processor_id();
ktime_t next;
tick_periodic(cpu);
if (dev->mode != CLOCK_EVT_MODE_ONESHOT)
return;
next = ktime_add(dev->next_event, tick_period);
for (;;) {
if (!clockevents_program_event(dev, next, false))
return;
if (timekeeping_valid_for_hres())
tick_periodic(cpu);
next = ktime_add(next, tick_period);
}
}
void tick_setup_periodic(struct clock_event_device *dev, int broadcast)
{
tick_set_periodic_handler(dev, broadcast);
if (!tick_device_is_functional(dev))
return;
if ((dev->features & CLOCK_EVT_FEAT_PERIODIC) &&
!tick_broadcast_oneshot_active()) {
clockevents_set_mode(dev, CLOCK_EVT_MODE_PERIODIC);
} else {
unsigned long seq;
ktime_t next;
do {
seq = read_seqbegin(&xtime_lock);
next = tick_next_period;
} while (read_seqretry(&xtime_lock, seq));
clockevents_set_mode(dev, CLOCK_EVT_MODE_ONESHOT);
for (;;) {
if (!clockevents_program_event(dev, next, false))
return;
next = ktime_add(next, tick_period);
}
}
}
static void tick_setup_device(struct tick_device *td,
struct clock_event_device *newdev, int cpu,
const struct cpumask *cpumask)
{
ktime_t next_event;
void (*handler)(struct clock_event_device *) = NULL;
if (!td->evtdev) {
if (tick_do_timer_cpu == TICK_DO_TIMER_BOOT) {
tick_do_timer_cpu = cpu;
tick_next_period = ktime_get();
tick_period = ktime_set(0, NSEC_PER_SEC / HZ);
}
td->mode = TICKDEV_MODE_PERIODIC;
} else {
handler = td->evtdev->event_handler;
next_event = td->evtdev->next_event;
td->evtdev->event_handler = clockevents_handle_noop;
}
td->evtdev = newdev;
if (!cpumask_equal(newdev->cpumask, cpumask))
irq_set_affinity(newdev->irq, cpumask);
if (tick_device_uses_broadcast(newdev, cpu))
return;
if (td->mode == TICKDEV_MODE_PERIODIC)
tick_setup_periodic(newdev, 0);
else
tick_setup_oneshot(newdev, handler, next_event);
}
static int tick_check_new_device(struct clock_event_device *newdev)
{
struct clock_event_device *curdev;
struct tick_device *td;
int cpu, ret = NOTIFY_OK;
unsigned long flags;
raw_spin_lock_irqsave(&tick_device_lock, flags);
cpu = smp_processor_id();
if (!cpumask_test_cpu(cpu, newdev->cpumask))
goto out_bc;
td = &per_cpu(tick_cpu_device, cpu);
curdev = td->evtdev;
if (!cpumask_equal(newdev->cpumask, cpumask_of(cpu))) {
if (!irq_can_set_affinity(newdev->irq))
goto out_bc;
if (curdev && cpumask_equal(curdev->cpumask, cpumask_of(cpu)))
goto out_bc;
}
if (curdev) {
if ((curdev->features & CLOCK_EVT_FEAT_ONESHOT) &&
!(newdev->features & CLOCK_EVT_FEAT_ONESHOT))
goto out_bc;
if (curdev->rating >= newdev->rating)
goto out_bc;
}
if (tick_is_broadcast_device(curdev)) {
clockevents_shutdown(curdev);
curdev = NULL;
}
clockevents_exchange_device(curdev, newdev);
tick_setup_device(td, newdev, cpu, cpumask_of(cpu));
if (newdev->features & CLOCK_EVT_FEAT_ONESHOT)
tick_oneshot_notify();
raw_spin_unlock_irqrestore(&tick_device_lock, flags);
return NOTIFY_STOP;
out_bc:
if (tick_check_broadcast_device(newdev))
ret = NOTIFY_STOP;
raw_spin_unlock_irqrestore(&tick_device_lock, flags);
return ret;
}
static void tick_handover_do_timer(int *cpup)
{
if (*cpup == tick_do_timer_cpu) {
int cpu = cpumask_first(cpu_online_mask);
tick_do_timer_cpu = (cpu < nr_cpu_ids) ? cpu :
TICK_DO_TIMER_NONE;
}
}
static void tick_shutdown(unsigned int *cpup)
{
struct tick_device *td = &per_cpu(tick_cpu_device, *cpup);
struct clock_event_device *dev = td->evtdev;
unsigned long flags;
raw_spin_lock_irqsave(&tick_device_lock, flags);
td->mode = TICKDEV_MODE_PERIODIC;
if (dev) {
dev->mode = CLOCK_EVT_MODE_UNUSED;
clockevents_exchange_device(dev, NULL);
td->evtdev = NULL;
}
raw_spin_unlock_irqrestore(&tick_device_lock, flags);
}
static void tick_suspend(void)
{
struct tick_device *td = &__get_cpu_var(tick_cpu_device);
unsigned long flags;
raw_spin_lock_irqsave(&tick_device_lock, flags);
clockevents_shutdown(td->evtdev);
raw_spin_unlock_irqrestore(&tick_device_lock, flags);
}
static void tick_resume(void)
{
struct tick_device *td = &__get_cpu_var(tick_cpu_device);
unsigned long flags;
int broadcast = tick_resume_broadcast();
raw_spin_lock_irqsave(&tick_device_lock, flags);
clockevents_set_mode(td->evtdev, CLOCK_EVT_MODE_RESUME);
if (!broadcast) {
if (td->mode == TICKDEV_MODE_PERIODIC)
tick_setup_periodic(td->evtdev, 0);
else
tick_resume_oneshot();
}
raw_spin_unlock_irqrestore(&tick_device_lock, flags);
}
static int tick_notify(struct notifier_block *nb, unsigned long reason,
void *dev)
{
switch (reason) {
case CLOCK_EVT_NOTIFY_ADD:
return tick_check_new_device(dev);
case CLOCK_EVT_NOTIFY_BROADCAST_ON:
case CLOCK_EVT_NOTIFY_BROADCAST_OFF:
case CLOCK_EVT_NOTIFY_BROADCAST_FORCE:
tick_broadcast_on_off(reason, dev);
break;
case CLOCK_EVT_NOTIFY_BROADCAST_ENTER:
case CLOCK_EVT_NOTIFY_BROADCAST_EXIT:
tick_broadcast_oneshot_control(reason);
break;
case CLOCK_EVT_NOTIFY_CPU_DYING:
tick_handover_do_timer(dev);
break;
case CLOCK_EVT_NOTIFY_CPU_DEAD:
tick_shutdown_broadcast_oneshot(dev);
tick_shutdown_broadcast(dev);
tick_shutdown(dev);
break;
case CLOCK_EVT_NOTIFY_SUSPEND:
tick_suspend();
tick_suspend_broadcast();
break;
case CLOCK_EVT_NOTIFY_RESUME:
tick_resume();
break;
default:
break;
}
return NOTIFY_OK;
}
void __init tick_init(void)
{
clockevents_register_notifier(&tick_notifier);
}
