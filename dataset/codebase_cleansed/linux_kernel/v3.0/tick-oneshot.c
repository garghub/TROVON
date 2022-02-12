static int tick_increase_min_delta(struct clock_event_device *dev)
{
if (dev->min_delta_ns >= MIN_DELTA_LIMIT)
return -ETIME;
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
int tick_dev_program_event(struct clock_event_device *dev, ktime_t expires,
int force)
{
ktime_t now = ktime_get();
int i;
for (i = 0;;) {
int ret = clockevents_program_event(dev, expires, now);
if (!ret || !force)
return ret;
dev->retries++;
if (++i > 2) {
if (tick_increase_min_delta(dev)) {
printk(KERN_WARNING
"CE: Reprogramming failure. Giving up\n");
dev->next_event.tv64 = KTIME_MAX;
return -ETIME;
}
i = 0;
}
now = ktime_get();
expires = ktime_add_ns(now, dev->min_delta_ns);
}
}
int tick_program_event(ktime_t expires, int force)
{
struct clock_event_device *dev = __this_cpu_read(tick_cpu_device.evtdev);
return tick_dev_program_event(dev, expires, force);
}
void tick_resume_oneshot(void)
{
struct tick_device *td = &__get_cpu_var(tick_cpu_device);
struct clock_event_device *dev = td->evtdev;
clockevents_set_mode(dev, CLOCK_EVT_MODE_ONESHOT);
tick_program_event(ktime_get(), 1);
}
void tick_setup_oneshot(struct clock_event_device *newdev,
void (*handler)(struct clock_event_device *),
ktime_t next_event)
{
newdev->event_handler = handler;
clockevents_set_mode(newdev, CLOCK_EVT_MODE_ONESHOT);
tick_dev_program_event(newdev, next_event, 1);
}
int tick_switch_to_oneshot(void (*handler)(struct clock_event_device *))
{
struct tick_device *td = &__get_cpu_var(tick_cpu_device);
struct clock_event_device *dev = td->evtdev;
if (!dev || !(dev->features & CLOCK_EVT_FEAT_ONESHOT) ||
!tick_device_is_functional(dev)) {
printk(KERN_INFO "Clockevents: "
"could not switch to one-shot mode:");
if (!dev) {
printk(" no tick device\n");
} else {
if (!tick_device_is_functional(dev))
printk(" %s is not functional.\n", dev->name);
else
printk(" %s does not support one-shot mode.\n",
dev->name);
}
return -EINVAL;
}
td->mode = TICKDEV_MODE_ONESHOT;
dev->event_handler = handler;
clockevents_set_mode(dev, CLOCK_EVT_MODE_ONESHOT);
tick_broadcast_switch_to_oneshot();
return 0;
}
int tick_oneshot_mode_active(void)
{
unsigned long flags;
int ret;
local_irq_save(flags);
ret = __this_cpu_read(tick_cpu_device.mode) == TICKDEV_MODE_ONESHOT;
local_irq_restore(flags);
return ret;
}
int tick_init_highres(void)
{
return tick_switch_to_oneshot(hrtimer_interrupt);
}
