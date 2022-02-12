struct rtc_device *alarmtimer_get_rtcdev(void)
{
unsigned long flags;
struct rtc_device *ret;
spin_lock_irqsave(&rtcdev_lock, flags);
ret = rtcdev;
spin_unlock_irqrestore(&rtcdev_lock, flags);
return ret;
}
static int alarmtimer_rtc_add_device(struct device *dev,
struct class_interface *class_intf)
{
unsigned long flags;
struct rtc_device *rtc = to_rtc_device(dev);
struct wakeup_source *__ws;
if (rtcdev)
return -EBUSY;
if (!rtc->ops->set_alarm)
return -1;
if (!device_may_wakeup(rtc->dev.parent))
return -1;
__ws = wakeup_source_register("alarmtimer");
spin_lock_irqsave(&rtcdev_lock, flags);
if (!rtcdev) {
if (!try_module_get(rtc->owner)) {
spin_unlock_irqrestore(&rtcdev_lock, flags);
return -1;
}
rtcdev = rtc;
get_device(dev);
ws = __ws;
__ws = NULL;
}
spin_unlock_irqrestore(&rtcdev_lock, flags);
wakeup_source_unregister(__ws);
return 0;
}
static inline void alarmtimer_rtc_timer_init(void)
{
rtc_timer_init(&rtctimer, NULL, NULL);
}
static int alarmtimer_rtc_interface_setup(void)
{
alarmtimer_rtc_interface.class = rtc_class;
return class_interface_register(&alarmtimer_rtc_interface);
}
static void alarmtimer_rtc_interface_remove(void)
{
class_interface_unregister(&alarmtimer_rtc_interface);
}
struct rtc_device *alarmtimer_get_rtcdev(void)
{
return NULL;
}
static inline int alarmtimer_rtc_interface_setup(void) { return 0; }
static inline void alarmtimer_rtc_interface_remove(void) { }
static inline void alarmtimer_rtc_timer_init(void) { }
static void alarmtimer_enqueue(struct alarm_base *base, struct alarm *alarm)
{
if (alarm->state & ALARMTIMER_STATE_ENQUEUED)
timerqueue_del(&base->timerqueue, &alarm->node);
timerqueue_add(&base->timerqueue, &alarm->node);
alarm->state |= ALARMTIMER_STATE_ENQUEUED;
}
static void alarmtimer_dequeue(struct alarm_base *base, struct alarm *alarm)
{
if (!(alarm->state & ALARMTIMER_STATE_ENQUEUED))
return;
timerqueue_del(&base->timerqueue, &alarm->node);
alarm->state &= ~ALARMTIMER_STATE_ENQUEUED;
}
static enum hrtimer_restart alarmtimer_fired(struct hrtimer *timer)
{
struct alarm *alarm = container_of(timer, struct alarm, timer);
struct alarm_base *base = &alarm_bases[alarm->type];
unsigned long flags;
int ret = HRTIMER_NORESTART;
int restart = ALARMTIMER_NORESTART;
spin_lock_irqsave(&base->lock, flags);
alarmtimer_dequeue(base, alarm);
spin_unlock_irqrestore(&base->lock, flags);
if (alarm->function)
restart = alarm->function(alarm, base->gettime());
spin_lock_irqsave(&base->lock, flags);
if (restart != ALARMTIMER_NORESTART) {
hrtimer_set_expires(&alarm->timer, alarm->node.expires);
alarmtimer_enqueue(base, alarm);
ret = HRTIMER_RESTART;
}
spin_unlock_irqrestore(&base->lock, flags);
trace_alarmtimer_fired(alarm, base->gettime());
return ret;
}
ktime_t alarm_expires_remaining(const struct alarm *alarm)
{
struct alarm_base *base = &alarm_bases[alarm->type];
return ktime_sub(alarm->node.expires, base->gettime());
}
static int alarmtimer_suspend(struct device *dev)
{
ktime_t min, now, expires;
int i, ret, type;
struct rtc_device *rtc;
unsigned long flags;
struct rtc_time tm;
spin_lock_irqsave(&freezer_delta_lock, flags);
min = freezer_delta;
expires = freezer_expires;
type = freezer_alarmtype;
freezer_delta = 0;
spin_unlock_irqrestore(&freezer_delta_lock, flags);
rtc = alarmtimer_get_rtcdev();
if (!rtc)
return 0;
for (i = 0; i < ALARM_NUMTYPE; i++) {
struct alarm_base *base = &alarm_bases[i];
struct timerqueue_node *next;
ktime_t delta;
spin_lock_irqsave(&base->lock, flags);
next = timerqueue_getnext(&base->timerqueue);
spin_unlock_irqrestore(&base->lock, flags);
if (!next)
continue;
delta = ktime_sub(next->expires, base->gettime());
if (!min || (delta < min)) {
expires = next->expires;
min = delta;
type = i;
}
}
if (min == 0)
return 0;
if (ktime_to_ns(min) < 2 * NSEC_PER_SEC) {
__pm_wakeup_event(ws, 2 * MSEC_PER_SEC);
return -EBUSY;
}
trace_alarmtimer_suspend(expires, type);
rtc_timer_cancel(rtc, &rtctimer);
rtc_read_time(rtc, &tm);
now = rtc_tm_to_ktime(tm);
now = ktime_add(now, min);
ret = rtc_timer_start(rtc, &rtctimer, now, 0);
if (ret < 0)
__pm_wakeup_event(ws, MSEC_PER_SEC);
return ret;
}
static int alarmtimer_resume(struct device *dev)
{
struct rtc_device *rtc;
rtc = alarmtimer_get_rtcdev();
if (rtc)
rtc_timer_cancel(rtc, &rtctimer);
return 0;
}
static int alarmtimer_suspend(struct device *dev)
{
return 0;
}
static int alarmtimer_resume(struct device *dev)
{
return 0;
}
void alarm_start(struct alarm *alarm, ktime_t start)
{
struct alarm_base *base = &alarm_bases[alarm->type];
unsigned long flags;
spin_lock_irqsave(&base->lock, flags);
alarm->node.expires = start;
alarmtimer_enqueue(base, alarm);
hrtimer_start(&alarm->timer, alarm->node.expires, HRTIMER_MODE_ABS);
spin_unlock_irqrestore(&base->lock, flags);
trace_alarmtimer_start(alarm, base->gettime());
}
void alarm_start_relative(struct alarm *alarm, ktime_t start)
{
struct alarm_base *base = &alarm_bases[alarm->type];
start = ktime_add_safe(start, base->gettime());
alarm_start(alarm, start);
}
void alarm_restart(struct alarm *alarm)
{
struct alarm_base *base = &alarm_bases[alarm->type];
unsigned long flags;
spin_lock_irqsave(&base->lock, flags);
hrtimer_set_expires(&alarm->timer, alarm->node.expires);
hrtimer_restart(&alarm->timer);
alarmtimer_enqueue(base, alarm);
spin_unlock_irqrestore(&base->lock, flags);
}
int alarm_try_to_cancel(struct alarm *alarm)
{
struct alarm_base *base = &alarm_bases[alarm->type];
unsigned long flags;
int ret;
spin_lock_irqsave(&base->lock, flags);
ret = hrtimer_try_to_cancel(&alarm->timer);
if (ret >= 0)
alarmtimer_dequeue(base, alarm);
spin_unlock_irqrestore(&base->lock, flags);
trace_alarmtimer_cancel(alarm, base->gettime());
return ret;
}
int alarm_cancel(struct alarm *alarm)
{
for (;;) {
int ret = alarm_try_to_cancel(alarm);
if (ret >= 0)
return ret;
cpu_relax();
}
}
u64 alarm_forward(struct alarm *alarm, ktime_t now, ktime_t interval)
{
u64 overrun = 1;
ktime_t delta;
delta = ktime_sub(now, alarm->node.expires);
if (delta < 0)
return 0;
if (unlikely(delta >= interval)) {
s64 incr = ktime_to_ns(interval);
overrun = ktime_divns(delta, incr);
alarm->node.expires = ktime_add_ns(alarm->node.expires,
incr*overrun);
if (alarm->node.expires > now)
return overrun;
overrun++;
}
alarm->node.expires = ktime_add_safe(alarm->node.expires, interval);
return overrun;
}
u64 alarm_forward_now(struct alarm *alarm, ktime_t interval)
{
struct alarm_base *base = &alarm_bases[alarm->type];
return alarm_forward(alarm, base->gettime(), interval);
}
static void alarmtimer_freezerset(ktime_t absexp, enum alarmtimer_type type)
{
struct alarm_base *base;
unsigned long flags;
ktime_t delta;
switch(type) {
case ALARM_REALTIME:
base = &alarm_bases[ALARM_REALTIME];
type = ALARM_REALTIME_FREEZER;
break;
case ALARM_BOOTTIME:
base = &alarm_bases[ALARM_BOOTTIME];
type = ALARM_BOOTTIME_FREEZER;
break;
default:
WARN_ONCE(1, "Invalid alarm type: %d\n", type);
return;
}
delta = ktime_sub(absexp, base->gettime());
spin_lock_irqsave(&freezer_delta_lock, flags);
if (!freezer_delta || (delta < freezer_delta)) {
freezer_delta = delta;
freezer_expires = absexp;
freezer_alarmtype = type;
}
spin_unlock_irqrestore(&freezer_delta_lock, flags);
}
static enum alarmtimer_type clock2alarm(clockid_t clockid)
{
if (clockid == CLOCK_REALTIME_ALARM)
return ALARM_REALTIME;
if (clockid == CLOCK_BOOTTIME_ALARM)
return ALARM_BOOTTIME;
return -1;
}
static enum alarmtimer_restart alarm_handle_timer(struct alarm *alarm,
ktime_t now)
{
struct k_itimer *ptr = container_of(alarm, struct k_itimer,
it.alarm.alarmtimer);
enum alarmtimer_restart result = ALARMTIMER_NORESTART;
unsigned long flags;
int si_private = 0;
spin_lock_irqsave(&ptr->it_lock, flags);
ptr->it_active = 0;
if (ptr->it_interval)
si_private = ++ptr->it_requeue_pending;
if (posix_timer_event(ptr, si_private) && ptr->it_interval) {
ptr->it_overrun += alarm_forward_now(alarm, ptr->it_interval);
++ptr->it_requeue_pending;
ptr->it_active = 1;
result = ALARMTIMER_RESTART;
}
spin_unlock_irqrestore(&ptr->it_lock, flags);
return result;
}
static void alarm_timer_rearm(struct k_itimer *timr)
{
struct alarm *alarm = &timr->it.alarm.alarmtimer;
timr->it_overrun += alarm_forward_now(alarm, timr->it_interval);
alarm_start(alarm, alarm->node.expires);
}
static int alarm_timer_forward(struct k_itimer *timr, ktime_t now)
{
struct alarm *alarm = &timr->it.alarm.alarmtimer;
return (int) alarm_forward(alarm, timr->it_interval, now);
}
static ktime_t alarm_timer_remaining(struct k_itimer *timr, ktime_t now)
{
struct alarm *alarm = &timr->it.alarm.alarmtimer;
return ktime_sub(now, alarm->node.expires);
}
static int alarm_timer_try_to_cancel(struct k_itimer *timr)
{
return alarm_try_to_cancel(&timr->it.alarm.alarmtimer);
}
static void alarm_timer_arm(struct k_itimer *timr, ktime_t expires,
bool absolute, bool sigev_none)
{
struct alarm *alarm = &timr->it.alarm.alarmtimer;
struct alarm_base *base = &alarm_bases[alarm->type];
if (!absolute)
expires = ktime_add_safe(expires, base->gettime());
if (sigev_none)
alarm->node.expires = expires;
else
alarm_start(&timr->it.alarm.alarmtimer, expires);
}
static int alarm_clock_getres(const clockid_t which_clock, struct timespec64 *tp)
{
if (!alarmtimer_get_rtcdev())
return -EINVAL;
tp->tv_sec = 0;
tp->tv_nsec = hrtimer_resolution;
return 0;
}
static int alarm_clock_get(clockid_t which_clock, struct timespec64 *tp)
{
struct alarm_base *base = &alarm_bases[clock2alarm(which_clock)];
if (!alarmtimer_get_rtcdev())
return -EINVAL;
*tp = ktime_to_timespec64(base->gettime());
return 0;
}
static int alarm_timer_create(struct k_itimer *new_timer)
{
enum alarmtimer_type type;
if (!alarmtimer_get_rtcdev())
return -ENOTSUPP;
if (!capable(CAP_WAKE_ALARM))
return -EPERM;
type = clock2alarm(new_timer->it_clock);
alarm_init(&new_timer->it.alarm.alarmtimer, type, alarm_handle_timer);
return 0;
}
static enum alarmtimer_restart alarmtimer_nsleep_wakeup(struct alarm *alarm,
ktime_t now)
{
struct task_struct *task = (struct task_struct *)alarm->data;
alarm->data = NULL;
if (task)
wake_up_process(task);
return ALARMTIMER_NORESTART;
}
static int alarmtimer_do_nsleep(struct alarm *alarm, ktime_t absexp,
enum alarmtimer_type type)
{
struct restart_block *restart;
alarm->data = (void *)current;
do {
set_current_state(TASK_INTERRUPTIBLE);
alarm_start(alarm, absexp);
if (likely(alarm->data))
schedule();
alarm_cancel(alarm);
} while (alarm->data && !signal_pending(current));
__set_current_state(TASK_RUNNING);
if (!alarm->data)
return 0;
if (freezing(current))
alarmtimer_freezerset(absexp, type);
restart = &current->restart_block;
if (restart->nanosleep.type != TT_NONE) {
struct timespec64 rmt;
ktime_t rem;
rem = ktime_sub(absexp, alarm_bases[type].gettime());
if (rem <= 0)
return 0;
rmt = ktime_to_timespec64(rem);
return nanosleep_copyout(restart, &rmt);
}
return -ERESTART_RESTARTBLOCK;
}
static long __sched alarm_timer_nsleep_restart(struct restart_block *restart)
{
enum alarmtimer_type type = restart->nanosleep.clockid;
ktime_t exp = restart->nanosleep.expires;
struct alarm alarm;
alarm_init(&alarm, type, alarmtimer_nsleep_wakeup);
return alarmtimer_do_nsleep(&alarm, exp, type);
}
static int alarm_timer_nsleep(const clockid_t which_clock, int flags,
const struct timespec64 *tsreq)
{
enum alarmtimer_type type = clock2alarm(which_clock);
struct restart_block *restart = &current->restart_block;
struct alarm alarm;
ktime_t exp;
int ret = 0;
if (!alarmtimer_get_rtcdev())
return -ENOTSUPP;
if (flags & ~TIMER_ABSTIME)
return -EINVAL;
if (!capable(CAP_WAKE_ALARM))
return -EPERM;
alarm_init(&alarm, type, alarmtimer_nsleep_wakeup);
exp = timespec64_to_ktime(*tsreq);
if (flags != TIMER_ABSTIME) {
ktime_t now = alarm_bases[type].gettime();
exp = ktime_add(now, exp);
}
ret = alarmtimer_do_nsleep(&alarm, exp, type);
if (ret != -ERESTART_RESTARTBLOCK)
return ret;
if (flags == TIMER_ABSTIME)
return -ERESTARTNOHAND;
restart->fn = alarm_timer_nsleep_restart;
restart->nanosleep.clockid = type;
restart->nanosleep.expires = exp;
return ret;
}
static int __init alarmtimer_init(void)
{
struct platform_device *pdev;
int error = 0;
int i;
alarmtimer_rtc_timer_init();
alarm_bases[ALARM_REALTIME].base_clockid = CLOCK_REALTIME;
alarm_bases[ALARM_REALTIME].gettime = &ktime_get_real;
alarm_bases[ALARM_BOOTTIME].base_clockid = CLOCK_BOOTTIME;
alarm_bases[ALARM_BOOTTIME].gettime = &ktime_get_boottime;
for (i = 0; i < ALARM_NUMTYPE; i++) {
timerqueue_init_head(&alarm_bases[i].timerqueue);
spin_lock_init(&alarm_bases[i].lock);
}
error = alarmtimer_rtc_interface_setup();
if (error)
return error;
error = platform_driver_register(&alarmtimer_driver);
if (error)
goto out_if;
pdev = platform_device_register_simple("alarmtimer", -1, NULL, 0);
if (IS_ERR(pdev)) {
error = PTR_ERR(pdev);
goto out_drv;
}
return 0;
out_drv:
platform_driver_unregister(&alarmtimer_driver);
out_if:
alarmtimer_rtc_interface_remove();
return error;
}
