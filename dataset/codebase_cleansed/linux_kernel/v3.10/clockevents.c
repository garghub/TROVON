u64 clockevent_delta2ns(unsigned long latch, struct clock_event_device *evt)
{
u64 clc = (u64) latch << evt->shift;
if (unlikely(!evt->mult)) {
evt->mult = 1;
WARN_ON(1);
}
do_div(clc, evt->mult);
if (clc < 1000)
clc = 1000;
if (clc > KTIME_MAX)
clc = KTIME_MAX;
return clc;
}
void clockevents_set_mode(struct clock_event_device *dev,
enum clock_event_mode mode)
{
if (dev->mode != mode) {
dev->set_mode(mode, dev);
dev->mode = mode;
if (mode == CLOCK_EVT_MODE_ONESHOT) {
if (unlikely(!dev->mult)) {
dev->mult = 1;
WARN_ON(1);
}
}
}
}
void clockevents_shutdown(struct clock_event_device *dev)
{
clockevents_set_mode(dev, CLOCK_EVT_MODE_SHUTDOWN);
dev->next_event.tv64 = KTIME_MAX;
}
static int clockevents_increase_min_delta(struct clock_event_device *dev)
{
if (dev->min_delta_ns >= MIN_DELTA_LIMIT) {
printk(KERN_WARNING "CE: Reprogramming failure. Giving up\n");
dev->next_event.tv64 = KTIME_MAX;
return -ETIME;
}
if (dev->min_delta_ns < 5000)
dev->min_delta_ns = 5000;
else
dev->min_delta_ns += dev->min_delta_ns >> 1;
if (dev->min_delta_ns > MIN_DELTA_LIMIT)
dev->min_delta_ns = MIN_DELTA_LIMIT;
printk(KERN_WARNING "CE: %s increased min_delta_ns to %llu nsec\n",
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
if (dev->mode == CLOCK_EVT_MODE_SHUTDOWN)
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
if (dev->mode == CLOCK_EVT_MODE_SHUTDOWN)
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
if (dev->mode == CLOCK_EVT_MODE_SHUTDOWN)
return 0;
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
int clockevents_register_notifier(struct notifier_block *nb)
{
unsigned long flags;
int ret;
raw_spin_lock_irqsave(&clockevents_lock, flags);
ret = raw_notifier_chain_register(&clockevents_chain, nb);
raw_spin_unlock_irqrestore(&clockevents_lock, flags);
return ret;
}
static void clockevents_do_notify(unsigned long reason, void *dev)
{
raw_notifier_call_chain(&clockevents_chain, reason, dev);
}
static void clockevents_notify_released(void)
{
struct clock_event_device *dev;
while (!list_empty(&clockevents_released)) {
dev = list_entry(clockevents_released.next,
struct clock_event_device, list);
list_del(&dev->list);
list_add(&dev->list, &clockevent_devices);
clockevents_do_notify(CLOCK_EVT_NOTIFY_ADD, dev);
}
}
void clockevents_register_device(struct clock_event_device *dev)
{
unsigned long flags;
BUG_ON(dev->mode != CLOCK_EVT_MODE_UNUSED);
if (!dev->cpumask) {
WARN_ON(num_possible_cpus() > 1);
dev->cpumask = cpumask_of(smp_processor_id());
}
raw_spin_lock_irqsave(&clockevents_lock, flags);
list_add(&dev->list, &clockevent_devices);
clockevents_do_notify(CLOCK_EVT_NOTIFY_ADD, dev);
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
dev->min_delta_ns = clockevent_delta2ns(dev->min_delta_ticks, dev);
dev->max_delta_ns = clockevent_delta2ns(dev->max_delta_ticks, dev);
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
int clockevents_update_freq(struct clock_event_device *dev, u32 freq)
{
clockevents_config(dev, freq);
if (dev->mode != CLOCK_EVT_MODE_ONESHOT)
return 0;
return clockevents_program_event(dev, dev->next_event, false);
}
void clockevents_handle_noop(struct clock_event_device *dev)
{
}
void clockevents_exchange_device(struct clock_event_device *old,
struct clock_event_device *new)
{
unsigned long flags;
local_irq_save(flags);
if (old) {
clockevents_set_mode(old, CLOCK_EVT_MODE_UNUSED);
list_del(&old->list);
list_add(&old->list, &clockevents_released);
}
if (new) {
BUG_ON(new->mode != CLOCK_EVT_MODE_UNUSED);
clockevents_shutdown(new);
}
local_irq_restore(flags);
}
void clockevents_suspend(void)
{
struct clock_event_device *dev;
list_for_each_entry_reverse(dev, &clockevent_devices, list)
if (dev->suspend)
dev->suspend(dev);
}
void clockevents_resume(void)
{
struct clock_event_device *dev;
list_for_each_entry(dev, &clockevent_devices, list)
if (dev->resume)
dev->resume(dev);
}
void clockevents_notify(unsigned long reason, void *arg)
{
struct clock_event_device *dev, *tmp;
unsigned long flags;
int cpu;
raw_spin_lock_irqsave(&clockevents_lock, flags);
clockevents_do_notify(reason, arg);
switch (reason) {
case CLOCK_EVT_NOTIFY_CPU_DEAD:
list_for_each_entry_safe(dev, tmp, &clockevents_released, list)
list_del(&dev->list);
cpu = *((int *)arg);
list_for_each_entry_safe(dev, tmp, &clockevent_devices, list) {
if (cpumask_test_cpu(cpu, dev->cpumask) &&
cpumask_weight(dev->cpumask) == 1 &&
!tick_is_broadcast_device(dev)) {
BUG_ON(dev->mode != CLOCK_EVT_MODE_UNUSED);
list_del(&dev->list);
}
}
break;
default:
break;
}
raw_spin_unlock_irqrestore(&clockevents_lock, flags);
}
