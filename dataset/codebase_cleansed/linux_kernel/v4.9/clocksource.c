void
clocks_calc_mult_shift(u32 *mult, u32 *shift, u32 from, u32 to, u32 maxsec)
{
u64 tmp;
u32 sft, sftacc= 32;
tmp = ((u64)maxsec * from) >> 32;
while (tmp) {
tmp >>=1;
sftacc--;
}
for (sft = 32; sft > 0; sft--) {
tmp = (u64) to << sft;
tmp += from / 2;
do_div(tmp, from);
if ((tmp >> sftacc) == 0)
break;
}
*mult = tmp;
*shift = sft;
}
static void clocksource_watchdog_work(struct work_struct *work)
{
kthread_run(clocksource_watchdog_kthread, NULL, "kwatchdog");
}
static void __clocksource_unstable(struct clocksource *cs)
{
cs->flags &= ~(CLOCK_SOURCE_VALID_FOR_HRES | CLOCK_SOURCE_WATCHDOG);
cs->flags |= CLOCK_SOURCE_UNSTABLE;
if (finished_booting)
schedule_work(&watchdog_work);
}
void clocksource_mark_unstable(struct clocksource *cs)
{
unsigned long flags;
spin_lock_irqsave(&watchdog_lock, flags);
if (!(cs->flags & CLOCK_SOURCE_UNSTABLE)) {
if (list_empty(&cs->wd_list))
list_add(&cs->wd_list, &watchdog_list);
__clocksource_unstable(cs);
}
spin_unlock_irqrestore(&watchdog_lock, flags);
}
static void clocksource_watchdog(unsigned long data)
{
struct clocksource *cs;
cycle_t csnow, wdnow, cslast, wdlast, delta;
int64_t wd_nsec, cs_nsec;
int next_cpu, reset_pending;
spin_lock(&watchdog_lock);
if (!watchdog_running)
goto out;
reset_pending = atomic_read(&watchdog_reset_pending);
list_for_each_entry(cs, &watchdog_list, wd_list) {
if (cs->flags & CLOCK_SOURCE_UNSTABLE) {
if (finished_booting)
schedule_work(&watchdog_work);
continue;
}
local_irq_disable();
csnow = cs->read(cs);
wdnow = watchdog->read(watchdog);
local_irq_enable();
if (!(cs->flags & CLOCK_SOURCE_WATCHDOG) ||
atomic_read(&watchdog_reset_pending)) {
cs->flags |= CLOCK_SOURCE_WATCHDOG;
cs->wd_last = wdnow;
cs->cs_last = csnow;
continue;
}
delta = clocksource_delta(wdnow, cs->wd_last, watchdog->mask);
wd_nsec = clocksource_cyc2ns(delta, watchdog->mult,
watchdog->shift);
delta = clocksource_delta(csnow, cs->cs_last, cs->mask);
cs_nsec = clocksource_cyc2ns(delta, cs->mult, cs->shift);
wdlast = cs->wd_last;
cslast = cs->cs_last;
cs->cs_last = csnow;
cs->wd_last = wdnow;
if (atomic_read(&watchdog_reset_pending))
continue;
if (abs(cs_nsec - wd_nsec) > WATCHDOG_THRESHOLD) {
pr_warn("timekeeping watchdog on CPU%d: Marking clocksource '%s' as unstable because the skew is too large:\n",
smp_processor_id(), cs->name);
pr_warn(" '%s' wd_now: %llx wd_last: %llx mask: %llx\n",
watchdog->name, wdnow, wdlast, watchdog->mask);
pr_warn(" '%s' cs_now: %llx cs_last: %llx mask: %llx\n",
cs->name, csnow, cslast, cs->mask);
__clocksource_unstable(cs);
continue;
}
if (!(cs->flags & CLOCK_SOURCE_VALID_FOR_HRES) &&
(cs->flags & CLOCK_SOURCE_IS_CONTINUOUS) &&
(watchdog->flags & CLOCK_SOURCE_IS_CONTINUOUS)) {
cs->flags |= CLOCK_SOURCE_VALID_FOR_HRES;
if (!finished_booting)
continue;
if (cs != curr_clocksource) {
cs->flags |= CLOCK_SOURCE_RESELECT;
schedule_work(&watchdog_work);
} else {
tick_clock_notify();
}
}
}
if (reset_pending)
atomic_dec(&watchdog_reset_pending);
next_cpu = cpumask_next(raw_smp_processor_id(), cpu_online_mask);
if (next_cpu >= nr_cpu_ids)
next_cpu = cpumask_first(cpu_online_mask);
watchdog_timer.expires += WATCHDOG_INTERVAL;
add_timer_on(&watchdog_timer, next_cpu);
out:
spin_unlock(&watchdog_lock);
}
static inline void clocksource_start_watchdog(void)
{
if (watchdog_running || !watchdog || list_empty(&watchdog_list))
return;
init_timer(&watchdog_timer);
watchdog_timer.function = clocksource_watchdog;
watchdog_timer.expires = jiffies + WATCHDOG_INTERVAL;
add_timer_on(&watchdog_timer, cpumask_first(cpu_online_mask));
watchdog_running = 1;
}
static inline void clocksource_stop_watchdog(void)
{
if (!watchdog_running || (watchdog && !list_empty(&watchdog_list)))
return;
del_timer(&watchdog_timer);
watchdog_running = 0;
}
static inline void clocksource_reset_watchdog(void)
{
struct clocksource *cs;
list_for_each_entry(cs, &watchdog_list, wd_list)
cs->flags &= ~CLOCK_SOURCE_WATCHDOG;
}
static void clocksource_resume_watchdog(void)
{
atomic_inc(&watchdog_reset_pending);
}
static void clocksource_enqueue_watchdog(struct clocksource *cs)
{
unsigned long flags;
spin_lock_irqsave(&watchdog_lock, flags);
if (cs->flags & CLOCK_SOURCE_MUST_VERIFY) {
list_add(&cs->wd_list, &watchdog_list);
cs->flags &= ~CLOCK_SOURCE_WATCHDOG;
} else {
if (cs->flags & CLOCK_SOURCE_IS_CONTINUOUS)
cs->flags |= CLOCK_SOURCE_VALID_FOR_HRES;
}
spin_unlock_irqrestore(&watchdog_lock, flags);
}
static void clocksource_select_watchdog(bool fallback)
{
struct clocksource *cs, *old_wd;
unsigned long flags;
spin_lock_irqsave(&watchdog_lock, flags);
old_wd = watchdog;
if (fallback)
watchdog = NULL;
list_for_each_entry(cs, &clocksource_list, list) {
if (cs->flags & CLOCK_SOURCE_MUST_VERIFY)
continue;
if (fallback && cs == old_wd)
continue;
if (!watchdog || cs->rating > watchdog->rating)
watchdog = cs;
}
if (!watchdog)
watchdog = old_wd;
if (watchdog != old_wd)
clocksource_reset_watchdog();
clocksource_start_watchdog();
spin_unlock_irqrestore(&watchdog_lock, flags);
}
static void clocksource_dequeue_watchdog(struct clocksource *cs)
{
unsigned long flags;
spin_lock_irqsave(&watchdog_lock, flags);
if (cs != watchdog) {
if (cs->flags & CLOCK_SOURCE_MUST_VERIFY) {
list_del_init(&cs->wd_list);
clocksource_stop_watchdog();
}
}
spin_unlock_irqrestore(&watchdog_lock, flags);
}
static int __clocksource_watchdog_kthread(void)
{
struct clocksource *cs, *tmp;
unsigned long flags;
LIST_HEAD(unstable);
int select = 0;
spin_lock_irqsave(&watchdog_lock, flags);
list_for_each_entry_safe(cs, tmp, &watchdog_list, wd_list) {
if (cs->flags & CLOCK_SOURCE_UNSTABLE) {
list_del_init(&cs->wd_list);
list_add(&cs->wd_list, &unstable);
select = 1;
}
if (cs->flags & CLOCK_SOURCE_RESELECT) {
cs->flags &= ~CLOCK_SOURCE_RESELECT;
select = 1;
}
}
clocksource_stop_watchdog();
spin_unlock_irqrestore(&watchdog_lock, flags);
list_for_each_entry_safe(cs, tmp, &unstable, wd_list) {
list_del_init(&cs->wd_list);
__clocksource_change_rating(cs, 0);
}
return select;
}
static int clocksource_watchdog_kthread(void *data)
{
mutex_lock(&clocksource_mutex);
if (__clocksource_watchdog_kthread())
clocksource_select();
mutex_unlock(&clocksource_mutex);
return 0;
}
static bool clocksource_is_watchdog(struct clocksource *cs)
{
return cs == watchdog;
}
static void clocksource_enqueue_watchdog(struct clocksource *cs)
{
if (cs->flags & CLOCK_SOURCE_IS_CONTINUOUS)
cs->flags |= CLOCK_SOURCE_VALID_FOR_HRES;
}
static void clocksource_select_watchdog(bool fallback) { }
static inline void clocksource_dequeue_watchdog(struct clocksource *cs) { }
static inline void clocksource_resume_watchdog(void) { }
static inline int __clocksource_watchdog_kthread(void) { return 0; }
static bool clocksource_is_watchdog(struct clocksource *cs) { return false; }
void clocksource_mark_unstable(struct clocksource *cs) { }
void clocksource_suspend(void)
{
struct clocksource *cs;
list_for_each_entry_reverse(cs, &clocksource_list, list)
if (cs->suspend)
cs->suspend(cs);
}
void clocksource_resume(void)
{
struct clocksource *cs;
list_for_each_entry(cs, &clocksource_list, list)
if (cs->resume)
cs->resume(cs);
clocksource_resume_watchdog();
}
void clocksource_touch_watchdog(void)
{
clocksource_resume_watchdog();
}
static u32 clocksource_max_adjustment(struct clocksource *cs)
{
u64 ret;
ret = (u64)cs->mult * 11;
do_div(ret,100);
return (u32)ret;
}
u64 clocks_calc_max_nsecs(u32 mult, u32 shift, u32 maxadj, u64 mask, u64 *max_cyc)
{
u64 max_nsecs, max_cycles;
max_cycles = ULLONG_MAX;
do_div(max_cycles, mult+maxadj);
max_cycles = min(max_cycles, mask);
max_nsecs = clocksource_cyc2ns(max_cycles, mult - maxadj, shift);
if (max_cyc)
*max_cyc = max_cycles;
max_nsecs >>= 1;
return max_nsecs;
}
static inline void clocksource_update_max_deferment(struct clocksource *cs)
{
cs->max_idle_ns = clocks_calc_max_nsecs(cs->mult, cs->shift,
cs->maxadj, cs->mask,
&cs->max_cycles);
}
static struct clocksource *clocksource_find_best(bool oneshot, bool skipcur)
{
struct clocksource *cs;
if (!finished_booting || list_empty(&clocksource_list))
return NULL;
list_for_each_entry(cs, &clocksource_list, list) {
if (skipcur && cs == curr_clocksource)
continue;
if (oneshot && !(cs->flags & CLOCK_SOURCE_VALID_FOR_HRES))
continue;
return cs;
}
return NULL;
}
static void __clocksource_select(bool skipcur)
{
bool oneshot = tick_oneshot_mode_active();
struct clocksource *best, *cs;
best = clocksource_find_best(oneshot, skipcur);
if (!best)
return;
list_for_each_entry(cs, &clocksource_list, list) {
if (skipcur && cs == curr_clocksource)
continue;
if (strcmp(cs->name, override_name) != 0)
continue;
if (!(cs->flags & CLOCK_SOURCE_VALID_FOR_HRES) && oneshot) {
if (cs->flags & CLOCK_SOURCE_UNSTABLE) {
pr_warn("Override clocksource %s is unstable and not HRT compatible - cannot switch while in HRT/NOHZ mode\n",
cs->name);
override_name[0] = 0;
} else {
pr_info("Override clocksource %s is not currently HRT compatible - deferring\n",
cs->name);
}
} else
best = cs;
break;
}
if (curr_clocksource != best && !timekeeping_notify(best)) {
pr_info("Switched to clocksource %s\n", best->name);
curr_clocksource = best;
}
}
static void clocksource_select(void)
{
__clocksource_select(false);
}
static void clocksource_select_fallback(void)
{
__clocksource_select(true);
}
static inline void clocksource_select(void) { }
static inline void clocksource_select_fallback(void) { }
static int __init clocksource_done_booting(void)
{
mutex_lock(&clocksource_mutex);
curr_clocksource = clocksource_default_clock();
finished_booting = 1;
__clocksource_watchdog_kthread();
clocksource_select();
mutex_unlock(&clocksource_mutex);
return 0;
}
static void clocksource_enqueue(struct clocksource *cs)
{
struct list_head *entry = &clocksource_list;
struct clocksource *tmp;
list_for_each_entry(tmp, &clocksource_list, list) {
if (tmp->rating < cs->rating)
break;
entry = &tmp->list;
}
list_add(&cs->list, entry);
}
void __clocksource_update_freq_scale(struct clocksource *cs, u32 scale, u32 freq)
{
u64 sec;
if (freq) {
sec = cs->mask;
do_div(sec, freq);
do_div(sec, scale);
if (!sec)
sec = 1;
else if (sec > 600 && cs->mask > UINT_MAX)
sec = 600;
clocks_calc_mult_shift(&cs->mult, &cs->shift, freq,
NSEC_PER_SEC / scale, sec * scale);
}
cs->maxadj = clocksource_max_adjustment(cs);
while (freq && ((cs->mult + cs->maxadj < cs->mult)
|| (cs->mult - cs->maxadj > cs->mult))) {
cs->mult >>= 1;
cs->shift--;
cs->maxadj = clocksource_max_adjustment(cs);
}
WARN_ONCE(cs->mult + cs->maxadj < cs->mult,
"timekeeping: Clocksource %s might overflow on 11%% adjustment\n",
cs->name);
clocksource_update_max_deferment(cs);
pr_info("%s: mask: 0x%llx max_cycles: 0x%llx, max_idle_ns: %lld ns\n",
cs->name, cs->mask, cs->max_cycles, cs->max_idle_ns);
}
int __clocksource_register_scale(struct clocksource *cs, u32 scale, u32 freq)
{
__clocksource_update_freq_scale(cs, scale, freq);
mutex_lock(&clocksource_mutex);
clocksource_enqueue(cs);
clocksource_enqueue_watchdog(cs);
clocksource_select();
clocksource_select_watchdog(false);
mutex_unlock(&clocksource_mutex);
return 0;
}
static void __clocksource_change_rating(struct clocksource *cs, int rating)
{
list_del(&cs->list);
cs->rating = rating;
clocksource_enqueue(cs);
}
void clocksource_change_rating(struct clocksource *cs, int rating)
{
mutex_lock(&clocksource_mutex);
__clocksource_change_rating(cs, rating);
clocksource_select();
clocksource_select_watchdog(false);
mutex_unlock(&clocksource_mutex);
}
static int clocksource_unbind(struct clocksource *cs)
{
if (clocksource_is_watchdog(cs)) {
clocksource_select_watchdog(true);
if (clocksource_is_watchdog(cs))
return -EBUSY;
}
if (cs == curr_clocksource) {
clocksource_select_fallback();
if (curr_clocksource == cs)
return -EBUSY;
}
clocksource_dequeue_watchdog(cs);
list_del_init(&cs->list);
return 0;
}
int clocksource_unregister(struct clocksource *cs)
{
int ret = 0;
mutex_lock(&clocksource_mutex);
if (!list_empty(&cs->list))
ret = clocksource_unbind(cs);
mutex_unlock(&clocksource_mutex);
return ret;
}
static ssize_t
sysfs_show_current_clocksources(struct device *dev,
struct device_attribute *attr, char *buf)
{
ssize_t count = 0;
mutex_lock(&clocksource_mutex);
count = snprintf(buf, PAGE_SIZE, "%s\n", curr_clocksource->name);
mutex_unlock(&clocksource_mutex);
return count;
}
ssize_t sysfs_get_uname(const char *buf, char *dst, size_t cnt)
{
size_t ret = cnt;
if (!cnt || cnt >= CS_NAME_LEN)
return -EINVAL;
if (buf[cnt-1] == '\n')
cnt--;
if (cnt > 0)
memcpy(dst, buf, cnt);
dst[cnt] = 0;
return ret;
}
static ssize_t sysfs_override_clocksource(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
ssize_t ret;
mutex_lock(&clocksource_mutex);
ret = sysfs_get_uname(buf, override_name, count);
if (ret >= 0)
clocksource_select();
mutex_unlock(&clocksource_mutex);
return ret;
}
static ssize_t sysfs_unbind_clocksource(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct clocksource *cs;
char name[CS_NAME_LEN];
ssize_t ret;
ret = sysfs_get_uname(buf, name, count);
if (ret < 0)
return ret;
ret = -ENODEV;
mutex_lock(&clocksource_mutex);
list_for_each_entry(cs, &clocksource_list, list) {
if (strcmp(cs->name, name))
continue;
ret = clocksource_unbind(cs);
break;
}
mutex_unlock(&clocksource_mutex);
return ret ? ret : count;
}
static ssize_t
sysfs_show_available_clocksources(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct clocksource *src;
ssize_t count = 0;
mutex_lock(&clocksource_mutex);
list_for_each_entry(src, &clocksource_list, list) {
if (!tick_oneshot_mode_active() ||
(src->flags & CLOCK_SOURCE_VALID_FOR_HRES))
count += snprintf(buf + count,
max((ssize_t)PAGE_SIZE - count, (ssize_t)0),
"%s ", src->name);
}
mutex_unlock(&clocksource_mutex);
count += snprintf(buf + count,
max((ssize_t)PAGE_SIZE - count, (ssize_t)0), "\n");
return count;
}
static int __init init_clocksource_sysfs(void)
{
int error = subsys_system_register(&clocksource_subsys, NULL);
if (!error)
error = device_register(&device_clocksource);
if (!error)
error = device_create_file(
&device_clocksource,
&dev_attr_current_clocksource);
if (!error)
error = device_create_file(&device_clocksource,
&dev_attr_unbind_clocksource);
if (!error)
error = device_create_file(
&device_clocksource,
&dev_attr_available_clocksource);
return error;
}
static int __init boot_override_clocksource(char* str)
{
mutex_lock(&clocksource_mutex);
if (str)
strlcpy(override_name, str, sizeof(override_name));
mutex_unlock(&clocksource_mutex);
return 1;
}
static int __init boot_override_clock(char* str)
{
if (!strcmp(str, "pmtmr")) {
pr_warn("clock=pmtmr is deprecated - use clocksource=acpi_pm\n");
return boot_override_clocksource("acpi_pm");
}
pr_warn("clock= boot option is deprecated - use clocksource=xyz\n");
return boot_override_clocksource(str);
}
