static void timekeeper_setup_internals(struct clocksource *clock)
{
cycle_t interval;
u64 tmp, ntpinterval;
timekeeper.clock = clock;
clock->cycle_last = clock->read(clock);
tmp = NTP_INTERVAL_LENGTH;
tmp <<= clock->shift;
ntpinterval = tmp;
tmp += clock->mult/2;
do_div(tmp, clock->mult);
if (tmp == 0)
tmp = 1;
interval = (cycle_t) tmp;
timekeeper.cycle_interval = interval;
timekeeper.xtime_interval = (u64) interval * clock->mult;
timekeeper.xtime_remainder = ntpinterval - timekeeper.xtime_interval;
timekeeper.raw_interval =
((u64) interval * clock->mult) >> clock->shift;
timekeeper.xtime_nsec = 0;
timekeeper.shift = clock->shift;
timekeeper.ntp_error = 0;
timekeeper.ntp_error_shift = NTP_SCALE_SHIFT - clock->shift;
timekeeper.mult = clock->mult;
}
static inline s64 timekeeping_get_ns(void)
{
cycle_t cycle_now, cycle_delta;
struct clocksource *clock;
clock = timekeeper.clock;
cycle_now = clock->read(clock);
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
return clocksource_cyc2ns(cycle_delta, timekeeper.mult,
timekeeper.shift);
}
static inline s64 timekeeping_get_ns_raw(void)
{
cycle_t cycle_now, cycle_delta;
struct clocksource *clock;
clock = timekeeper.clock;
cycle_now = clock->read(clock);
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
return clocksource_cyc2ns(cycle_delta, clock->mult, clock->shift);
}
void timekeeping_leap_insert(int leapsecond)
{
xtime.tv_sec += leapsecond;
wall_to_monotonic.tv_sec -= leapsecond;
update_vsyscall(&xtime, &wall_to_monotonic, timekeeper.clock,
timekeeper.mult);
}
static void timekeeping_forward_now(void)
{
cycle_t cycle_now, cycle_delta;
struct clocksource *clock;
s64 nsec;
clock = timekeeper.clock;
cycle_now = clock->read(clock);
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
clock->cycle_last = cycle_now;
nsec = clocksource_cyc2ns(cycle_delta, timekeeper.mult,
timekeeper.shift);
nsec += arch_gettimeoffset();
timespec_add_ns(&xtime, nsec);
nsec = clocksource_cyc2ns(cycle_delta, clock->mult, clock->shift);
timespec_add_ns(&raw_time, nsec);
}
void getnstimeofday(struct timespec *ts)
{
unsigned long seq;
s64 nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&xtime_lock);
*ts = xtime;
nsecs = timekeeping_get_ns();
nsecs += arch_gettimeoffset();
} while (read_seqretry(&xtime_lock, seq));
timespec_add_ns(ts, nsecs);
}
ktime_t ktime_get(void)
{
unsigned int seq;
s64 secs, nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&xtime_lock);
secs = xtime.tv_sec + wall_to_monotonic.tv_sec;
nsecs = xtime.tv_nsec + wall_to_monotonic.tv_nsec;
nsecs += timekeeping_get_ns();
nsecs += arch_gettimeoffset();
} while (read_seqretry(&xtime_lock, seq));
return ktime_add_ns(ktime_set(secs, 0), nsecs);
}
void ktime_get_ts(struct timespec *ts)
{
struct timespec tomono;
unsigned int seq;
s64 nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&xtime_lock);
*ts = xtime;
tomono = wall_to_monotonic;
nsecs = timekeeping_get_ns();
nsecs += arch_gettimeoffset();
} while (read_seqretry(&xtime_lock, seq));
set_normalized_timespec(ts, ts->tv_sec + tomono.tv_sec,
ts->tv_nsec + tomono.tv_nsec + nsecs);
}
void getnstime_raw_and_real(struct timespec *ts_raw, struct timespec *ts_real)
{
unsigned long seq;
s64 nsecs_raw, nsecs_real;
WARN_ON_ONCE(timekeeping_suspended);
do {
u32 arch_offset;
seq = read_seqbegin(&xtime_lock);
*ts_raw = raw_time;
*ts_real = xtime;
nsecs_raw = timekeeping_get_ns_raw();
nsecs_real = timekeeping_get_ns();
arch_offset = arch_gettimeoffset();
nsecs_raw += arch_offset;
nsecs_real += arch_offset;
} while (read_seqretry(&xtime_lock, seq));
timespec_add_ns(ts_raw, nsecs_raw);
timespec_add_ns(ts_real, nsecs_real);
}
void do_gettimeofday(struct timeval *tv)
{
struct timespec now;
getnstimeofday(&now);
tv->tv_sec = now.tv_sec;
tv->tv_usec = now.tv_nsec/1000;
}
int do_settimeofday(const struct timespec *tv)
{
struct timespec ts_delta;
unsigned long flags;
if ((unsigned long)tv->tv_nsec >= NSEC_PER_SEC)
return -EINVAL;
write_seqlock_irqsave(&xtime_lock, flags);
timekeeping_forward_now();
ts_delta.tv_sec = tv->tv_sec - xtime.tv_sec;
ts_delta.tv_nsec = tv->tv_nsec - xtime.tv_nsec;
wall_to_monotonic = timespec_sub(wall_to_monotonic, ts_delta);
xtime = *tv;
timekeeper.ntp_error = 0;
ntp_clear();
update_vsyscall(&xtime, &wall_to_monotonic, timekeeper.clock,
timekeeper.mult);
write_sequnlock_irqrestore(&xtime_lock, flags);
clock_was_set();
return 0;
}
int timekeeping_inject_offset(struct timespec *ts)
{
unsigned long flags;
if ((unsigned long)ts->tv_nsec >= NSEC_PER_SEC)
return -EINVAL;
write_seqlock_irqsave(&xtime_lock, flags);
timekeeping_forward_now();
xtime = timespec_add(xtime, *ts);
wall_to_monotonic = timespec_sub(wall_to_monotonic, *ts);
timekeeper.ntp_error = 0;
ntp_clear();
update_vsyscall(&xtime, &wall_to_monotonic, timekeeper.clock,
timekeeper.mult);
write_sequnlock_irqrestore(&xtime_lock, flags);
clock_was_set();
return 0;
}
static int change_clocksource(void *data)
{
struct clocksource *new, *old;
new = (struct clocksource *) data;
timekeeping_forward_now();
if (!new->enable || new->enable(new) == 0) {
old = timekeeper.clock;
timekeeper_setup_internals(new);
if (old->disable)
old->disable(old);
}
return 0;
}
void timekeeping_notify(struct clocksource *clock)
{
if (timekeeper.clock == clock)
return;
stop_machine(change_clocksource, clock, NULL);
tick_clock_notify();
}
ktime_t ktime_get_real(void)
{
struct timespec now;
getnstimeofday(&now);
return timespec_to_ktime(now);
}
void getrawmonotonic(struct timespec *ts)
{
unsigned long seq;
s64 nsecs;
do {
seq = read_seqbegin(&xtime_lock);
nsecs = timekeeping_get_ns_raw();
*ts = raw_time;
} while (read_seqretry(&xtime_lock, seq));
timespec_add_ns(ts, nsecs);
}
int timekeeping_valid_for_hres(void)
{
unsigned long seq;
int ret;
do {
seq = read_seqbegin(&xtime_lock);
ret = timekeeper.clock->flags & CLOCK_SOURCE_VALID_FOR_HRES;
} while (read_seqretry(&xtime_lock, seq));
return ret;
}
u64 timekeeping_max_deferment(void)
{
return timekeeper.clock->max_idle_ns;
}
void __init timekeeping_init(void)
{
struct clocksource *clock;
unsigned long flags;
struct timespec now, boot;
read_persistent_clock(&now);
read_boot_clock(&boot);
write_seqlock_irqsave(&xtime_lock, flags);
ntp_init();
clock = clocksource_default_clock();
if (clock->enable)
clock->enable(clock);
timekeeper_setup_internals(clock);
xtime.tv_sec = now.tv_sec;
xtime.tv_nsec = now.tv_nsec;
raw_time.tv_sec = 0;
raw_time.tv_nsec = 0;
if (boot.tv_sec == 0 && boot.tv_nsec == 0) {
boot.tv_sec = xtime.tv_sec;
boot.tv_nsec = xtime.tv_nsec;
}
set_normalized_timespec(&wall_to_monotonic,
-boot.tv_sec, -boot.tv_nsec);
total_sleep_time.tv_sec = 0;
total_sleep_time.tv_nsec = 0;
write_sequnlock_irqrestore(&xtime_lock, flags);
}
static void __timekeeping_inject_sleeptime(struct timespec *delta)
{
if (!timespec_valid(delta)) {
printk(KERN_WARNING "__timekeeping_inject_sleeptime: Invalid "
"sleep delta value!\n");
return;
}
xtime = timespec_add(xtime, *delta);
wall_to_monotonic = timespec_sub(wall_to_monotonic, *delta);
total_sleep_time = timespec_add(total_sleep_time, *delta);
}
void timekeeping_inject_sleeptime(struct timespec *delta)
{
unsigned long flags;
struct timespec ts;
read_persistent_clock(&ts);
if (!(ts.tv_sec == 0 && ts.tv_nsec == 0))
return;
write_seqlock_irqsave(&xtime_lock, flags);
timekeeping_forward_now();
__timekeeping_inject_sleeptime(delta);
timekeeper.ntp_error = 0;
ntp_clear();
update_vsyscall(&xtime, &wall_to_monotonic, timekeeper.clock,
timekeeper.mult);
write_sequnlock_irqrestore(&xtime_lock, flags);
clock_was_set();
}
static void timekeeping_resume(void)
{
unsigned long flags;
struct timespec ts;
read_persistent_clock(&ts);
clocksource_resume();
write_seqlock_irqsave(&xtime_lock, flags);
if (timespec_compare(&ts, &timekeeping_suspend_time) > 0) {
ts = timespec_sub(ts, timekeeping_suspend_time);
__timekeeping_inject_sleeptime(&ts);
}
timekeeper.clock->cycle_last = timekeeper.clock->read(timekeeper.clock);
timekeeper.ntp_error = 0;
timekeeping_suspended = 0;
write_sequnlock_irqrestore(&xtime_lock, flags);
touch_softlockup_watchdog();
clockevents_notify(CLOCK_EVT_NOTIFY_RESUME, NULL);
hrtimers_resume();
}
static int timekeeping_suspend(void)
{
unsigned long flags;
struct timespec delta, delta_delta;
static struct timespec old_delta;
read_persistent_clock(&timekeeping_suspend_time);
write_seqlock_irqsave(&xtime_lock, flags);
timekeeping_forward_now();
timekeeping_suspended = 1;
delta = timespec_sub(xtime, timekeeping_suspend_time);
delta_delta = timespec_sub(delta, old_delta);
if (abs(delta_delta.tv_sec) >= 2) {
old_delta = delta;
} else {
timekeeping_suspend_time =
timespec_add(timekeeping_suspend_time, delta_delta);
}
write_sequnlock_irqrestore(&xtime_lock, flags);
clockevents_notify(CLOCK_EVT_NOTIFY_SUSPEND, NULL);
clocksource_suspend();
return 0;
}
static int __init timekeeping_init_ops(void)
{
register_syscore_ops(&timekeeping_syscore_ops);
return 0;
}
static __always_inline int timekeeping_bigadjust(s64 error, s64 *interval,
s64 *offset)
{
s64 tick_error, i;
u32 look_ahead, adj;
s32 error2, mult;
error2 = timekeeper.ntp_error >> (NTP_SCALE_SHIFT + 22 - 2 * SHIFT_HZ);
error2 = abs(error2);
for (look_ahead = 0; error2 > 0; look_ahead++)
error2 >>= 2;
tick_error = tick_length >> (timekeeper.ntp_error_shift + 1);
tick_error -= timekeeper.xtime_interval >> 1;
error = ((error - tick_error) >> look_ahead) + tick_error;
i = *interval;
mult = 1;
if (error < 0) {
error = -error;
*interval = -*interval;
*offset = -*offset;
mult = -1;
}
for (adj = 0; error > i; adj++)
error >>= 1;
*interval <<= adj;
*offset <<= adj;
return mult << adj;
}
static void timekeeping_adjust(s64 offset)
{
s64 error, interval = timekeeper.cycle_interval;
int adj;
error = timekeeper.ntp_error >> (timekeeper.ntp_error_shift - 1);
if (error > interval) {
error >>= 2;
if (likely(error <= interval))
adj = 1;
else
adj = timekeeping_bigadjust(error, &interval, &offset);
} else if (error < -interval) {
error >>= 2;
if (likely(error >= -interval)) {
adj = -1;
interval = -interval;
offset = -offset;
} else
adj = timekeeping_bigadjust(error, &interval, &offset);
} else
return;
WARN_ONCE(timekeeper.clock->maxadj &&
(timekeeper.mult + adj > timekeeper.clock->mult +
timekeeper.clock->maxadj),
"Adjusting %s more then 11%% (%ld vs %ld)\n",
timekeeper.clock->name, (long)timekeeper.mult + adj,
(long)timekeeper.clock->mult +
timekeeper.clock->maxadj);
timekeeper.mult += adj;
timekeeper.xtime_interval += interval;
timekeeper.xtime_nsec -= offset;
timekeeper.ntp_error -= (interval - offset) <<
timekeeper.ntp_error_shift;
}
static cycle_t logarithmic_accumulation(cycle_t offset, int shift)
{
u64 nsecps = (u64)NSEC_PER_SEC << timekeeper.shift;
u64 raw_nsecs;
if (offset < timekeeper.cycle_interval<<shift)
return offset;
offset -= timekeeper.cycle_interval << shift;
timekeeper.clock->cycle_last += timekeeper.cycle_interval << shift;
timekeeper.xtime_nsec += timekeeper.xtime_interval << shift;
while (timekeeper.xtime_nsec >= nsecps) {
timekeeper.xtime_nsec -= nsecps;
xtime.tv_sec++;
second_overflow();
}
raw_nsecs = timekeeper.raw_interval << shift;
raw_nsecs += raw_time.tv_nsec;
if (raw_nsecs >= NSEC_PER_SEC) {
u64 raw_secs = raw_nsecs;
raw_nsecs = do_div(raw_secs, NSEC_PER_SEC);
raw_time.tv_sec += raw_secs;
}
raw_time.tv_nsec = raw_nsecs;
timekeeper.ntp_error += tick_length << shift;
timekeeper.ntp_error -=
(timekeeper.xtime_interval + timekeeper.xtime_remainder) <<
(timekeeper.ntp_error_shift + shift);
return offset;
}
static void update_wall_time(void)
{
struct clocksource *clock;
cycle_t offset;
int shift = 0, maxshift;
if (unlikely(timekeeping_suspended))
return;
clock = timekeeper.clock;
#ifdef CONFIG_ARCH_USES_GETTIMEOFFSET
offset = timekeeper.cycle_interval;
#else
offset = (clock->read(clock) - clock->cycle_last) & clock->mask;
#endif
timekeeper.xtime_nsec = (s64)xtime.tv_nsec << timekeeper.shift;
shift = ilog2(offset) - ilog2(timekeeper.cycle_interval);
shift = max(0, shift);
maxshift = (8*sizeof(tick_length) - (ilog2(tick_length)+1)) - 1;
shift = min(shift, maxshift);
while (offset >= timekeeper.cycle_interval) {
offset = logarithmic_accumulation(offset, shift);
if(offset < timekeeper.cycle_interval<<shift)
shift--;
}
timekeeping_adjust(offset);
if (unlikely((s64)timekeeper.xtime_nsec < 0)) {
s64 neg = -(s64)timekeeper.xtime_nsec;
timekeeper.xtime_nsec = 0;
timekeeper.ntp_error += neg << timekeeper.ntp_error_shift;
}
xtime.tv_nsec = ((s64) timekeeper.xtime_nsec >> timekeeper.shift) + 1;
timekeeper.xtime_nsec -= (s64) xtime.tv_nsec << timekeeper.shift;
timekeeper.ntp_error += timekeeper.xtime_nsec <<
timekeeper.ntp_error_shift;
if (unlikely(xtime.tv_nsec >= NSEC_PER_SEC)) {
xtime.tv_nsec -= NSEC_PER_SEC;
xtime.tv_sec++;
second_overflow();
}
update_vsyscall(&xtime, &wall_to_monotonic, timekeeper.clock,
timekeeper.mult);
}
void getboottime(struct timespec *ts)
{
struct timespec boottime = {
.tv_sec = wall_to_monotonic.tv_sec + total_sleep_time.tv_sec,
.tv_nsec = wall_to_monotonic.tv_nsec + total_sleep_time.tv_nsec
};
set_normalized_timespec(ts, -boottime.tv_sec, -boottime.tv_nsec);
}
void get_monotonic_boottime(struct timespec *ts)
{
struct timespec tomono, sleep;
unsigned int seq;
s64 nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&xtime_lock);
*ts = xtime;
tomono = wall_to_monotonic;
sleep = total_sleep_time;
nsecs = timekeeping_get_ns();
} while (read_seqretry(&xtime_lock, seq));
set_normalized_timespec(ts, ts->tv_sec + tomono.tv_sec + sleep.tv_sec,
ts->tv_nsec + tomono.tv_nsec + sleep.tv_nsec + nsecs);
}
ktime_t ktime_get_boottime(void)
{
struct timespec ts;
get_monotonic_boottime(&ts);
return timespec_to_ktime(ts);
}
void monotonic_to_bootbased(struct timespec *ts)
{
*ts = timespec_add(*ts, total_sleep_time);
}
unsigned long get_seconds(void)
{
return xtime.tv_sec;
}
struct timespec __current_kernel_time(void)
{
return xtime;
}
struct timespec current_kernel_time(void)
{
struct timespec now;
unsigned long seq;
do {
seq = read_seqbegin(&xtime_lock);
now = xtime;
} while (read_seqretry(&xtime_lock, seq));
return now;
}
struct timespec get_monotonic_coarse(void)
{
struct timespec now, mono;
unsigned long seq;
do {
seq = read_seqbegin(&xtime_lock);
now = xtime;
mono = wall_to_monotonic;
} while (read_seqretry(&xtime_lock, seq));
set_normalized_timespec(&now, now.tv_sec + mono.tv_sec,
now.tv_nsec + mono.tv_nsec);
return now;
}
void do_timer(unsigned long ticks)
{
jiffies_64 += ticks;
update_wall_time();
calc_global_load(ticks);
}
void get_xtime_and_monotonic_and_sleep_offset(struct timespec *xtim,
struct timespec *wtom, struct timespec *sleep)
{
unsigned long seq;
do {
seq = read_seqbegin(&xtime_lock);
*xtim = xtime;
*wtom = wall_to_monotonic;
*sleep = total_sleep_time;
} while (read_seqretry(&xtime_lock, seq));
}
ktime_t ktime_get_monotonic_offset(void)
{
unsigned long seq;
struct timespec wtom;
do {
seq = read_seqbegin(&xtime_lock);
wtom = wall_to_monotonic;
} while (read_seqretry(&xtime_lock, seq));
return timespec_to_ktime(wtom);
}
void xtime_update(unsigned long ticks)
{
write_seqlock(&xtime_lock);
do_timer(ticks);
write_sequnlock(&xtime_lock);
}
