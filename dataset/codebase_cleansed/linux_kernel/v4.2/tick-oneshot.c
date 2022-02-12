int tick_program_event(ktime_t expires, int force)
{
struct clock_event_device *dev = __this_cpu_read(tick_cpu_device.evtdev);
if (unlikely(expires.tv64 == KTIME_MAX)) {
clockevents_switch_state(dev, CLOCK_EVT_STATE_ONESHOT_STOPPED);
return 0;
}
if (unlikely(clockevent_state_oneshot_stopped(dev))) {
clockevents_switch_state(dev, CLOCK_EVT_STATE_ONESHOT);
}
return clockevents_program_event(dev, expires, force);
}
void tick_resume_oneshot(void)
{
struct clock_event_device *dev = __this_cpu_read(tick_cpu_device.evtdev);
clockevents_switch_state(dev, CLOCK_EVT_STATE_ONESHOT);
clockevents_program_event(dev, ktime_get(), true);
}
void tick_setup_oneshot(struct clock_event_device *newdev,
void (*handler)(struct clock_event_device *),
ktime_t next_event)
{
newdev->event_handler = handler;
clockevents_switch_state(newdev, CLOCK_EVT_STATE_ONESHOT);
clockevents_program_event(newdev, next_event, true);
}
int tick_switch_to_oneshot(void (*handler)(struct clock_event_device *))
{
struct tick_device *td = this_cpu_ptr(&tick_cpu_device);
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
clockevents_switch_state(dev, CLOCK_EVT_STATE_ONESHOT);
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
