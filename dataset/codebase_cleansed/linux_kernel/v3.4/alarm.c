static void update_timer_locked(struct alarm_queue *base, bool head_removed)
{
struct android_alarm *alarm;
bool is_wakeup = base == &alarms[ANDROID_ALARM_RTC_WAKEUP] ||
base == &alarms[ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP];
if (base->stopped) {
pr_alarm(FLOW, "changed alarm while setting the wall time\n");
return;
}
if (is_wakeup && !suspended && head_removed)
wake_unlock(&alarm_rtc_wake_lock);
if (!base->first)
return;
alarm = container_of(base->first, struct android_alarm, node);
pr_alarm(FLOW, "selected alarm, type %d, func %pF at %lld\n",
alarm->type, alarm->function, ktime_to_ns(alarm->expires));
if (is_wakeup && suspended) {
pr_alarm(FLOW, "changed alarm while suspened\n");
wake_lock_timeout(&alarm_rtc_wake_lock, 1 * HZ);
return;
}
hrtimer_try_to_cancel(&base->timer);
base->timer.node.expires = ktime_add(base->delta, alarm->expires);
base->timer._softexpires = ktime_add(base->delta, alarm->softexpires);
hrtimer_start_expires(&base->timer, HRTIMER_MODE_ABS);
}
static void alarm_enqueue_locked(struct android_alarm *alarm)
{
struct alarm_queue *base = &alarms[alarm->type];
struct rb_node **link = &base->alarms.rb_node;
struct rb_node *parent = NULL;
struct android_alarm *entry;
int leftmost = 1;
bool was_first = false;
pr_alarm(FLOW, "added alarm, type %d, func %pF at %lld\n",
alarm->type, alarm->function, ktime_to_ns(alarm->expires));
if (base->first == &alarm->node) {
base->first = rb_next(&alarm->node);
was_first = true;
}
if (!RB_EMPTY_NODE(&alarm->node)) {
rb_erase(&alarm->node, &base->alarms);
RB_CLEAR_NODE(&alarm->node);
}
while (*link) {
parent = *link;
entry = rb_entry(parent, struct android_alarm, node);
if (alarm->expires.tv64 < entry->expires.tv64) {
link = &(*link)->rb_left;
} else {
link = &(*link)->rb_right;
leftmost = 0;
}
}
if (leftmost)
base->first = &alarm->node;
if (leftmost || was_first)
update_timer_locked(base, was_first);
rb_link_node(&alarm->node, parent, link);
rb_insert_color(&alarm->node, &base->alarms);
}
void android_alarm_init(struct android_alarm *alarm,
enum android_alarm_type type, void (*function)(struct android_alarm *))
{
RB_CLEAR_NODE(&alarm->node);
alarm->type = type;
alarm->function = function;
pr_alarm(FLOW, "created alarm, type %d, func %pF\n", type, function);
}
void android_alarm_start_range(struct android_alarm *alarm, ktime_t start,
ktime_t end)
{
unsigned long flags;
spin_lock_irqsave(&alarm_slock, flags);
alarm->softexpires = start;
alarm->expires = end;
alarm_enqueue_locked(alarm);
spin_unlock_irqrestore(&alarm_slock, flags);
}
int android_alarm_try_to_cancel(struct android_alarm *alarm)
{
struct alarm_queue *base = &alarms[alarm->type];
unsigned long flags;
bool first = false;
int ret = 0;
spin_lock_irqsave(&alarm_slock, flags);
if (!RB_EMPTY_NODE(&alarm->node)) {
pr_alarm(FLOW, "canceled alarm, type %d, func %pF at %lld\n",
alarm->type, alarm->function,
ktime_to_ns(alarm->expires));
ret = 1;
if (base->first == &alarm->node) {
base->first = rb_next(&alarm->node);
first = true;
}
rb_erase(&alarm->node, &base->alarms);
RB_CLEAR_NODE(&alarm->node);
if (first)
update_timer_locked(base, true);
} else
pr_alarm(FLOW, "tried to cancel alarm, type %d, func %pF\n",
alarm->type, alarm->function);
spin_unlock_irqrestore(&alarm_slock, flags);
if (!ret && hrtimer_callback_running(&base->timer))
ret = -1;
return ret;
}
int android_alarm_cancel(struct android_alarm *alarm)
{
for (;;) {
int ret = android_alarm_try_to_cancel(alarm);
if (ret >= 0)
return ret;
cpu_relax();
}
}
int android_alarm_set_rtc(struct timespec new_time)
{
int i;
int ret;
unsigned long flags;
struct rtc_time rtc_new_rtc_time;
struct timespec tmp_time;
rtc_time_to_tm(new_time.tv_sec, &rtc_new_rtc_time);
pr_alarm(TSET, "set rtc %ld %ld - rtc %02d:%02d:%02d %02d/%02d/%04d\n",
new_time.tv_sec, new_time.tv_nsec,
rtc_new_rtc_time.tm_hour, rtc_new_rtc_time.tm_min,
rtc_new_rtc_time.tm_sec, rtc_new_rtc_time.tm_mon + 1,
rtc_new_rtc_time.tm_mday,
rtc_new_rtc_time.tm_year + 1900);
mutex_lock(&alarm_setrtc_mutex);
spin_lock_irqsave(&alarm_slock, flags);
wake_lock(&alarm_rtc_wake_lock);
getnstimeofday(&tmp_time);
for (i = 0; i < ANDROID_ALARM_SYSTEMTIME; i++) {
hrtimer_try_to_cancel(&alarms[i].timer);
alarms[i].stopped = true;
alarms[i].stopped_time = timespec_to_ktime(tmp_time);
}
alarms[ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP].delta =
alarms[ANDROID_ALARM_ELAPSED_REALTIME].delta =
ktime_sub(alarms[ANDROID_ALARM_ELAPSED_REALTIME].delta,
timespec_to_ktime(timespec_sub(tmp_time, new_time)));
spin_unlock_irqrestore(&alarm_slock, flags);
ret = do_settimeofday(&new_time);
spin_lock_irqsave(&alarm_slock, flags);
for (i = 0; i < ANDROID_ALARM_SYSTEMTIME; i++) {
alarms[i].stopped = false;
update_timer_locked(&alarms[i], false);
}
spin_unlock_irqrestore(&alarm_slock, flags);
if (ret < 0) {
pr_alarm(ERROR, "alarm_set_rtc: Failed to set time\n");
goto err;
}
if (!alarm_rtc_dev) {
pr_alarm(ERROR,
"alarm_set_rtc: no RTC, time will be lost on reboot\n");
goto err;
}
ret = rtc_set_time(alarm_rtc_dev, &rtc_new_rtc_time);
if (ret < 0)
pr_alarm(ERROR, "alarm_set_rtc: "
"Failed to set RTC, time will be lost on reboot\n");
err:
wake_unlock(&alarm_rtc_wake_lock);
mutex_unlock(&alarm_setrtc_mutex);
return ret;
}
ktime_t alarm_get_elapsed_realtime(void)
{
ktime_t now;
unsigned long flags;
struct alarm_queue *base = &alarms[ANDROID_ALARM_ELAPSED_REALTIME];
spin_lock_irqsave(&alarm_slock, flags);
now = base->stopped ? base->stopped_time : ktime_get_real();
now = ktime_sub(now, base->delta);
spin_unlock_irqrestore(&alarm_slock, flags);
return now;
}
static enum hrtimer_restart alarm_timer_triggered(struct hrtimer *timer)
{
struct alarm_queue *base;
struct android_alarm *alarm;
unsigned long flags;
ktime_t now;
spin_lock_irqsave(&alarm_slock, flags);
base = container_of(timer, struct alarm_queue, timer);
now = base->stopped ? base->stopped_time : hrtimer_cb_get_time(timer);
now = ktime_sub(now, base->delta);
pr_alarm(INT, "alarm_timer_triggered type %ld at %lld\n",
base - alarms, ktime_to_ns(now));
while (base->first) {
alarm = container_of(base->first, struct android_alarm, node);
if (alarm->softexpires.tv64 > now.tv64) {
pr_alarm(FLOW, "don't call alarm, %pF, %lld (s %lld)\n",
alarm->function, ktime_to_ns(alarm->expires),
ktime_to_ns(alarm->softexpires));
break;
}
base->first = rb_next(&alarm->node);
rb_erase(&alarm->node, &base->alarms);
RB_CLEAR_NODE(&alarm->node);
pr_alarm(CALL, "call alarm, type %d, func %pF, %lld (s %lld)\n",
alarm->type, alarm->function,
ktime_to_ns(alarm->expires),
ktime_to_ns(alarm->softexpires));
spin_unlock_irqrestore(&alarm_slock, flags);
alarm->function(alarm);
spin_lock_irqsave(&alarm_slock, flags);
}
if (!base->first)
pr_alarm(FLOW, "no more alarms of type %ld\n", base - alarms);
update_timer_locked(base, true);
spin_unlock_irqrestore(&alarm_slock, flags);
return HRTIMER_NORESTART;
}
static void alarm_triggered_func(void *p)
{
struct rtc_device *rtc = alarm_rtc_dev;
if (!(rtc->irq_data & RTC_AF))
return;
pr_alarm(INT, "rtc alarm triggered\n");
wake_lock_timeout(&alarm_rtc_wake_lock, 1 * HZ);
}
static int alarm_suspend(struct platform_device *pdev, pm_message_t state)
{
int err = 0;
unsigned long flags;
struct rtc_wkalrm rtc_alarm;
struct rtc_time rtc_current_rtc_time;
unsigned long rtc_current_time;
unsigned long rtc_alarm_time;
struct timespec rtc_delta;
struct timespec wall_time;
struct alarm_queue *wakeup_queue = NULL;
struct alarm_queue *tmp_queue = NULL;
pr_alarm(SUSPEND, "alarm_suspend(%p, %d)\n", pdev, state.event);
spin_lock_irqsave(&alarm_slock, flags);
suspended = true;
spin_unlock_irqrestore(&alarm_slock, flags);
hrtimer_cancel(&alarms[ANDROID_ALARM_RTC_WAKEUP].timer);
hrtimer_cancel(&alarms[
ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP].timer);
tmp_queue = &alarms[ANDROID_ALARM_RTC_WAKEUP];
if (tmp_queue->first)
wakeup_queue = tmp_queue;
tmp_queue = &alarms[ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP];
if (tmp_queue->first && (!wakeup_queue ||
hrtimer_get_expires(&tmp_queue->timer).tv64 <
hrtimer_get_expires(&wakeup_queue->timer).tv64))
wakeup_queue = tmp_queue;
if (wakeup_queue) {
rtc_read_time(alarm_rtc_dev, &rtc_current_rtc_time);
getnstimeofday(&wall_time);
rtc_tm_to_time(&rtc_current_rtc_time, &rtc_current_time);
set_normalized_timespec(&rtc_delta,
wall_time.tv_sec - rtc_current_time,
wall_time.tv_nsec);
rtc_alarm_time = timespec_sub(ktime_to_timespec(
hrtimer_get_expires(&wakeup_queue->timer)),
rtc_delta).tv_sec;
rtc_time_to_tm(rtc_alarm_time, &rtc_alarm.time);
rtc_alarm.enabled = 1;
rtc_set_alarm(alarm_rtc_dev, &rtc_alarm);
rtc_read_time(alarm_rtc_dev, &rtc_current_rtc_time);
rtc_tm_to_time(&rtc_current_rtc_time, &rtc_current_time);
pr_alarm(SUSPEND,
"rtc alarm set at %ld, now %ld, rtc delta %ld.%09ld\n",
rtc_alarm_time, rtc_current_time,
rtc_delta.tv_sec, rtc_delta.tv_nsec);
if (rtc_current_time + 1 >= rtc_alarm_time) {
pr_alarm(SUSPEND, "alarm about to go off\n");
memset(&rtc_alarm, 0, sizeof(rtc_alarm));
rtc_alarm.enabled = 0;
rtc_set_alarm(alarm_rtc_dev, &rtc_alarm);
spin_lock_irqsave(&alarm_slock, flags);
suspended = false;
wake_lock_timeout(&alarm_rtc_wake_lock, 2 * HZ);
update_timer_locked(&alarms[ANDROID_ALARM_RTC_WAKEUP],
false);
update_timer_locked(&alarms[
ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP], false);
err = -EBUSY;
spin_unlock_irqrestore(&alarm_slock, flags);
}
}
return err;
}
static int alarm_resume(struct platform_device *pdev)
{
struct rtc_wkalrm alarm;
unsigned long flags;
pr_alarm(SUSPEND, "alarm_resume(%p)\n", pdev);
memset(&alarm, 0, sizeof(alarm));
alarm.enabled = 0;
rtc_set_alarm(alarm_rtc_dev, &alarm);
spin_lock_irqsave(&alarm_slock, flags);
suspended = false;
update_timer_locked(&alarms[ANDROID_ALARM_RTC_WAKEUP], false);
update_timer_locked(&alarms[ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP],
false);
spin_unlock_irqrestore(&alarm_slock, flags);
return 0;
}
static int rtc_alarm_add_device(struct device *dev,
struct class_interface *class_intf)
{
int err;
struct rtc_device *rtc = to_rtc_device(dev);
mutex_lock(&alarm_setrtc_mutex);
if (alarm_rtc_dev) {
err = -EBUSY;
goto err1;
}
alarm_platform_dev =
platform_device_register_simple("alarm", -1, NULL, 0);
if (IS_ERR(alarm_platform_dev)) {
err = PTR_ERR(alarm_platform_dev);
goto err2;
}
err = rtc_irq_register(rtc, &alarm_rtc_task);
if (err)
goto err3;
alarm_rtc_dev = rtc;
pr_alarm(INIT_STATUS, "using rtc device, %s, for alarms", rtc->name);
mutex_unlock(&alarm_setrtc_mutex);
return 0;
err3:
platform_device_unregister(alarm_platform_dev);
err2:
err1:
mutex_unlock(&alarm_setrtc_mutex);
return err;
}
static void rtc_alarm_remove_device(struct device *dev,
struct class_interface *class_intf)
{
if (dev == &alarm_rtc_dev->dev) {
pr_alarm(INIT_STATUS, "lost rtc device for alarms");
rtc_irq_unregister(alarm_rtc_dev, &alarm_rtc_task);
platform_device_unregister(alarm_platform_dev);
alarm_rtc_dev = NULL;
}
}
static int __init alarm_late_init(void)
{
unsigned long flags;
struct timespec tmp_time, system_time;
spin_lock_irqsave(&alarm_slock, flags);
getnstimeofday(&tmp_time);
ktime_get_ts(&system_time);
alarms[ANDROID_ALARM_ELAPSED_REALTIME_WAKEUP].delta =
alarms[ANDROID_ALARM_ELAPSED_REALTIME].delta =
timespec_to_ktime(timespec_sub(tmp_time, system_time));
spin_unlock_irqrestore(&alarm_slock, flags);
return 0;
}
static int __init alarm_driver_init(void)
{
int err;
int i;
for (i = 0; i < ANDROID_ALARM_SYSTEMTIME; i++) {
hrtimer_init(&alarms[i].timer,
CLOCK_REALTIME, HRTIMER_MODE_ABS);
alarms[i].timer.function = alarm_timer_triggered;
}
hrtimer_init(&alarms[ANDROID_ALARM_SYSTEMTIME].timer,
CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
alarms[ANDROID_ALARM_SYSTEMTIME].timer.function = alarm_timer_triggered;
err = platform_driver_register(&alarm_driver);
if (err < 0)
goto err1;
wake_lock_init(&alarm_rtc_wake_lock, WAKE_LOCK_SUSPEND, "alarm_rtc");
rtc_alarm_interface.class = rtc_class;
err = class_interface_register(&rtc_alarm_interface);
if (err < 0)
goto err2;
return 0;
err2:
wake_lock_destroy(&alarm_rtc_wake_lock);
platform_driver_unregister(&alarm_driver);
err1:
return err;
}
static void __exit alarm_exit(void)
{
class_interface_unregister(&rtc_alarm_interface);
wake_lock_destroy(&alarm_rtc_wake_lock);
platform_driver_unregister(&alarm_driver);
}
