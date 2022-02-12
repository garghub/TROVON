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
write_seqlock(&jiffies_lock);
tick_next_period = ktime_add(tick_next_period, tick_period);
do_timer(1);
write_sequnlock(&jiffies_lock);
update_wall_time();
}
update_process_times(user_mode(get_irq_regs()));
profile_tick(CPU_PROFILING);
}
void tick_handle_periodic(struct clock_event_device *dev)
{
int cpu = smp_processor_id();
ktime_t next = dev->next_event;
tick_periodic(cpu);
#if defined(CONFIG_HIGH_RES_TIMERS) || defined(CONFIG_NO_HZ_COMMON)
if (dev->event_handler != tick_handle_periodic)
return;
#endif
if (!clockevent_state_oneshot(dev))
return;
for (;;) {
next = ktime_add(next, tick_period);
if (!clockevents_program_event(dev, next, false))
return;
if (timekeeping_valid_for_hres())
tick_periodic(cpu);
}
}
void tick_setup_periodic(struct clock_event_device *dev, int broadcast)
{
tick_set_periodic_handler(dev, broadcast);
if (!tick_device_is_functional(dev))
return;
if ((dev->features & CLOCK_EVT_FEAT_PERIODIC) &&
!tick_broadcast_oneshot_active()) {
clockevents_switch_state(dev, CLOCK_EVT_STATE_PERIODIC);
} else {
unsigned long seq;
ktime_t next;
do {
seq = read_seqbegin(&jiffies_lock);
next = tick_next_period;
} while (read_seqretry(&jiffies_lock, seq));
clockevents_switch_state(dev, CLOCK_EVT_STATE_ONESHOT);
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
if (!tick_nohz_full_cpu(cpu))
tick_do_timer_cpu = cpu;
else
tick_do_timer_cpu = TICK_DO_TIMER_NONE;
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
void tick_install_replacement(struct clock_event_device *newdev)
{
struct tick_device *td = this_cpu_ptr(&tick_cpu_device);
int cpu = smp_processor_id();
clockevents_exchange_device(td->evtdev, newdev);
tick_setup_device(td, newdev, cpu, cpumask_of(cpu));
if (newdev->features & CLOCK_EVT_FEAT_ONESHOT)
tick_oneshot_notify();
}
static bool tick_check_percpu(struct clock_event_device *curdev,
struct clock_event_device *newdev, int cpu)
{
if (!cpumask_test_cpu(cpu, newdev->cpumask))
return false;
if (cpumask_equal(newdev->cpumask, cpumask_of(cpu)))
return true;
if (newdev->irq >= 0 && !irq_can_set_affinity(newdev->irq))
return false;
if (curdev && cpumask_equal(curdev->cpumask, cpumask_of(cpu)))
return false;
return true;
}
static bool tick_check_preferred(struct clock_event_device *curdev,
struct clock_event_device *newdev)
{
if (!(newdev->features & CLOCK_EVT_FEAT_ONESHOT)) {
if (curdev && (curdev->features & CLOCK_EVT_FEAT_ONESHOT))
return false;
if (tick_oneshot_mode_active())
return false;
}
return !curdev ||
newdev->rating > curdev->rating ||
!cpumask_equal(curdev->cpumask, newdev->cpumask);
}
bool tick_check_replacement(struct clock_event_device *curdev,
struct clock_event_device *newdev)
{
if (!tick_check_percpu(curdev, newdev, smp_processor_id()))
return false;
return tick_check_preferred(curdev, newdev);
}
void tick_check_new_device(struct clock_event_device *newdev)
{
struct clock_event_device *curdev;
struct tick_device *td;
int cpu;
cpu = smp_processor_id();
td = &per_cpu(tick_cpu_device, cpu);
curdev = td->evtdev;
if (!tick_check_percpu(curdev, newdev, cpu))
goto out_bc;
if (!tick_check_preferred(curdev, newdev))
goto out_bc;
if (!try_module_get(newdev->owner))
return;
if (tick_is_broadcast_device(curdev)) {
clockevents_shutdown(curdev);
curdev = NULL;
}
clockevents_exchange_device(curdev, newdev);
tick_setup_device(td, newdev, cpu, cpumask_of(cpu));
if (newdev->features & CLOCK_EVT_FEAT_ONESHOT)
tick_oneshot_notify();
return;
out_bc:
tick_install_broadcast_device(newdev);
}
int tick_broadcast_oneshot_control(enum tick_broadcast_state state)
{
struct tick_device *td = this_cpu_ptr(&tick_cpu_device);
if (!(td->evtdev->features & CLOCK_EVT_FEAT_C3STOP))
return 0;
return __tick_broadcast_oneshot_control(state);
}
void tick_handover_do_timer(void)
{
if (tick_do_timer_cpu == smp_processor_id()) {
int cpu = cpumask_first(cpu_online_mask);
tick_do_timer_cpu = (cpu < nr_cpu_ids) ? cpu :
TICK_DO_TIMER_NONE;
}
}
void tick_shutdown(unsigned int cpu)
{
struct tick_device *td = &per_cpu(tick_cpu_device, cpu);
struct clock_event_device *dev = td->evtdev;
td->mode = TICKDEV_MODE_PERIODIC;
if (dev) {
clockevent_set_state(dev, CLOCK_EVT_STATE_DETACHED);
clockevents_exchange_device(dev, NULL);
dev->event_handler = clockevents_handle_noop;
td->evtdev = NULL;
}
}
void tick_suspend_local(void)
{
struct tick_device *td = this_cpu_ptr(&tick_cpu_device);
clockevents_shutdown(td->evtdev);
}
void tick_resume_local(void)
{
struct tick_device *td = this_cpu_ptr(&tick_cpu_device);
bool broadcast = tick_resume_check_broadcast();
clockevents_tick_resume(td->evtdev);
if (!broadcast) {
if (td->mode == TICKDEV_MODE_PERIODIC)
tick_setup_periodic(td->evtdev, 0);
else
tick_resume_oneshot();
}
}
void tick_suspend(void)
{
tick_suspend_local();
tick_suspend_broadcast();
}
void tick_resume(void)
{
tick_resume_broadcast();
tick_resume_local();
}
void tick_freeze(void)
{
raw_spin_lock(&tick_freeze_lock);
tick_freeze_depth++;
if (tick_freeze_depth == num_online_cpus()) {
trace_suspend_resume(TPS("timekeeping_freeze"),
smp_processor_id(), true);
timekeeping_suspend();
} else {
tick_suspend_local();
}
raw_spin_unlock(&tick_freeze_lock);
}
void tick_unfreeze(void)
{
raw_spin_lock(&tick_freeze_lock);
if (tick_freeze_depth == num_online_cpus()) {
timekeeping_resume();
trace_suspend_resume(TPS("timekeeping_freeze"),
smp_processor_id(), false);
} else {
tick_resume_local();
}
tick_freeze_depth--;
raw_spin_unlock(&tick_freeze_lock);
}
void __init tick_init(void)
{
tick_broadcast_init();
tick_nohz_init();
}
