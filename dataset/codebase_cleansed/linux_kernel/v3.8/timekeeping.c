static inline void tk_normalize_xtime(struct timekeeper *tk)
{
while (tk->xtime_nsec >= ((u64)NSEC_PER_SEC << tk->shift)) {
tk->xtime_nsec -= (u64)NSEC_PER_SEC << tk->shift;
tk->xtime_sec++;
}
}
static void tk_set_xtime(struct timekeeper *tk, const struct timespec *ts)
{
tk->xtime_sec = ts->tv_sec;
tk->xtime_nsec = (u64)ts->tv_nsec << tk->shift;
}
static void tk_xtime_add(struct timekeeper *tk, const struct timespec *ts)
{
tk->xtime_sec += ts->tv_sec;
tk->xtime_nsec += (u64)ts->tv_nsec << tk->shift;
tk_normalize_xtime(tk);
}
static void tk_set_wall_to_mono(struct timekeeper *tk, struct timespec wtm)
{
struct timespec tmp;
set_normalized_timespec(&tmp, -tk->wall_to_monotonic.tv_sec,
-tk->wall_to_monotonic.tv_nsec);
WARN_ON_ONCE(tk->offs_real.tv64 != timespec_to_ktime(tmp).tv64);
tk->wall_to_monotonic = wtm;
set_normalized_timespec(&tmp, -wtm.tv_sec, -wtm.tv_nsec);
tk->offs_real = timespec_to_ktime(tmp);
}
static void tk_set_sleep_time(struct timekeeper *tk, struct timespec t)
{
WARN_ON_ONCE(tk->offs_boot.tv64 != timespec_to_ktime(tk->total_sleep_time).tv64);
tk->total_sleep_time = t;
tk->offs_boot = timespec_to_ktime(t);
}
static void tk_setup_internals(struct timekeeper *tk, struct clocksource *clock)
{
cycle_t interval;
u64 tmp, ntpinterval;
struct clocksource *old_clock;
old_clock = tk->clock;
tk->clock = clock;
clock->cycle_last = clock->read(clock);
tmp = NTP_INTERVAL_LENGTH;
tmp <<= clock->shift;
ntpinterval = tmp;
tmp += clock->mult/2;
do_div(tmp, clock->mult);
if (tmp == 0)
tmp = 1;
interval = (cycle_t) tmp;
tk->cycle_interval = interval;
tk->xtime_interval = (u64) interval * clock->mult;
tk->xtime_remainder = ntpinterval - tk->xtime_interval;
tk->raw_interval =
((u64) interval * clock->mult) >> clock->shift;
if (old_clock) {
int shift_change = clock->shift - old_clock->shift;
if (shift_change < 0)
tk->xtime_nsec >>= -shift_change;
else
tk->xtime_nsec <<= shift_change;
}
tk->shift = clock->shift;
tk->ntp_error = 0;
tk->ntp_error_shift = NTP_SCALE_SHIFT - clock->shift;
tk->mult = clock->mult;
}
static inline s64 timekeeping_get_ns(struct timekeeper *tk)
{
cycle_t cycle_now, cycle_delta;
struct clocksource *clock;
s64 nsec;
clock = tk->clock;
cycle_now = clock->read(clock);
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
nsec = cycle_delta * tk->mult + tk->xtime_nsec;
nsec >>= tk->shift;
return nsec + arch_gettimeoffset();
}
static inline s64 timekeeping_get_ns_raw(struct timekeeper *tk)
{
cycle_t cycle_now, cycle_delta;
struct clocksource *clock;
s64 nsec;
clock = tk->clock;
cycle_now = clock->read(clock);
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
nsec = clocksource_cyc2ns(cycle_delta, clock->mult, clock->shift);
return nsec + arch_gettimeoffset();
}
static void update_pvclock_gtod(struct timekeeper *tk)
{
raw_notifier_call_chain(&pvclock_gtod_chain, 0, tk);
}
int pvclock_gtod_register_notifier(struct notifier_block *nb)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
int ret;
write_seqlock_irqsave(&tk->lock, flags);
ret = raw_notifier_chain_register(&pvclock_gtod_chain, nb);
update_pvclock_gtod(tk);
write_sequnlock_irqrestore(&tk->lock, flags);
return ret;
}
int pvclock_gtod_unregister_notifier(struct notifier_block *nb)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
int ret;
write_seqlock_irqsave(&tk->lock, flags);
ret = raw_notifier_chain_unregister(&pvclock_gtod_chain, nb);
write_sequnlock_irqrestore(&tk->lock, flags);
return ret;
}
static void timekeeping_update(struct timekeeper *tk, bool clearntp)
{
if (clearntp) {
tk->ntp_error = 0;
ntp_clear();
}
update_vsyscall(tk);
update_pvclock_gtod(tk);
}
static void timekeeping_forward_now(struct timekeeper *tk)
{
cycle_t cycle_now, cycle_delta;
struct clocksource *clock;
s64 nsec;
clock = tk->clock;
cycle_now = clock->read(clock);
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
clock->cycle_last = cycle_now;
tk->xtime_nsec += cycle_delta * tk->mult;
tk->xtime_nsec += (u64)arch_gettimeoffset() << tk->shift;
tk_normalize_xtime(tk);
nsec = clocksource_cyc2ns(cycle_delta, clock->mult, clock->shift);
timespec_add_ns(&tk->raw_time, nsec);
}
void getnstimeofday(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
s64 nsecs = 0;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&tk->lock);
ts->tv_sec = tk->xtime_sec;
nsecs = timekeeping_get_ns(tk);
} while (read_seqretry(&tk->lock, seq));
ts->tv_nsec = 0;
timespec_add_ns(ts, nsecs);
}
ktime_t ktime_get(void)
{
struct timekeeper *tk = &timekeeper;
unsigned int seq;
s64 secs, nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&tk->lock);
secs = tk->xtime_sec + tk->wall_to_monotonic.tv_sec;
nsecs = timekeeping_get_ns(tk) + tk->wall_to_monotonic.tv_nsec;
} while (read_seqretry(&tk->lock, seq));
return ktime_add_ns(ktime_set(secs, 0), nsecs);
}
void ktime_get_ts(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
struct timespec tomono;
s64 nsec;
unsigned int seq;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&tk->lock);
ts->tv_sec = tk->xtime_sec;
nsec = timekeeping_get_ns(tk);
tomono = tk->wall_to_monotonic;
} while (read_seqretry(&tk->lock, seq));
ts->tv_sec += tomono.tv_sec;
ts->tv_nsec = 0;
timespec_add_ns(ts, nsec + tomono.tv_nsec);
}
void getnstime_raw_and_real(struct timespec *ts_raw, struct timespec *ts_real)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
s64 nsecs_raw, nsecs_real;
WARN_ON_ONCE(timekeeping_suspended);
do {
seq = read_seqbegin(&tk->lock);
*ts_raw = tk->raw_time;
ts_real->tv_sec = tk->xtime_sec;
ts_real->tv_nsec = 0;
nsecs_raw = timekeeping_get_ns_raw(tk);
nsecs_real = timekeeping_get_ns(tk);
} while (read_seqretry(&tk->lock, seq));
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
struct timekeeper *tk = &timekeeper;
struct timespec ts_delta, xt;
unsigned long flags;
if (!timespec_valid_strict(tv))
return -EINVAL;
write_seqlock_irqsave(&tk->lock, flags);
timekeeping_forward_now(tk);
xt = tk_xtime(tk);
ts_delta.tv_sec = tv->tv_sec - xt.tv_sec;
ts_delta.tv_nsec = tv->tv_nsec - xt.tv_nsec;
tk_set_wall_to_mono(tk, timespec_sub(tk->wall_to_monotonic, ts_delta));
tk_set_xtime(tk, tv);
timekeeping_update(tk, true);
write_sequnlock_irqrestore(&tk->lock, flags);
clock_was_set();
return 0;
}
int timekeeping_inject_offset(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
struct timespec tmp;
int ret = 0;
if ((unsigned long)ts->tv_nsec >= NSEC_PER_SEC)
return -EINVAL;
write_seqlock_irqsave(&tk->lock, flags);
timekeeping_forward_now(tk);
tmp = timespec_add(tk_xtime(tk), *ts);
if (!timespec_valid_strict(&tmp)) {
ret = -EINVAL;
goto error;
}
tk_xtime_add(tk, ts);
tk_set_wall_to_mono(tk, timespec_sub(tk->wall_to_monotonic, *ts));
error:
timekeeping_update(tk, true);
write_sequnlock_irqrestore(&tk->lock, flags);
clock_was_set();
return ret;
}
static int change_clocksource(void *data)
{
struct timekeeper *tk = &timekeeper;
struct clocksource *new, *old;
unsigned long flags;
new = (struct clocksource *) data;
write_seqlock_irqsave(&tk->lock, flags);
timekeeping_forward_now(tk);
if (!new->enable || new->enable(new) == 0) {
old = tk->clock;
tk_setup_internals(tk, new);
if (old->disable)
old->disable(old);
}
timekeeping_update(tk, true);
write_sequnlock_irqrestore(&tk->lock, flags);
return 0;
}
void timekeeping_notify(struct clocksource *clock)
{
struct timekeeper *tk = &timekeeper;
if (tk->clock == clock)
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
struct timekeeper *tk = &timekeeper;
unsigned long seq;
s64 nsecs;
do {
seq = read_seqbegin(&tk->lock);
nsecs = timekeeping_get_ns_raw(tk);
*ts = tk->raw_time;
} while (read_seqretry(&tk->lock, seq));
timespec_add_ns(ts, nsecs);
}
int timekeeping_valid_for_hres(void)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
int ret;
do {
seq = read_seqbegin(&tk->lock);
ret = tk->clock->flags & CLOCK_SOURCE_VALID_FOR_HRES;
} while (read_seqretry(&tk->lock, seq));
return ret;
}
u64 timekeeping_max_deferment(void)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
u64 ret;
do {
seq = read_seqbegin(&tk->lock);
ret = tk->clock->max_idle_ns;
} while (read_seqretry(&tk->lock, seq));
return ret;
}
void __init timekeeping_init(void)
{
struct timekeeper *tk = &timekeeper;
struct clocksource *clock;
unsigned long flags;
struct timespec now, boot, tmp;
read_persistent_clock(&now);
if (!timespec_valid_strict(&now)) {
pr_warn("WARNING: Persistent clock returned invalid value!\n"
" Check your CMOS/BIOS settings.\n");
now.tv_sec = 0;
now.tv_nsec = 0;
}
read_boot_clock(&boot);
if (!timespec_valid_strict(&boot)) {
pr_warn("WARNING: Boot clock returned invalid value!\n"
" Check your CMOS/BIOS settings.\n");
boot.tv_sec = 0;
boot.tv_nsec = 0;
}
seqlock_init(&tk->lock);
ntp_init();
write_seqlock_irqsave(&tk->lock, flags);
clock = clocksource_default_clock();
if (clock->enable)
clock->enable(clock);
tk_setup_internals(tk, clock);
tk_set_xtime(tk, &now);
tk->raw_time.tv_sec = 0;
tk->raw_time.tv_nsec = 0;
if (boot.tv_sec == 0 && boot.tv_nsec == 0)
boot = tk_xtime(tk);
set_normalized_timespec(&tmp, -boot.tv_sec, -boot.tv_nsec);
tk_set_wall_to_mono(tk, tmp);
tmp.tv_sec = 0;
tmp.tv_nsec = 0;
tk_set_sleep_time(tk, tmp);
write_sequnlock_irqrestore(&tk->lock, flags);
}
static void __timekeeping_inject_sleeptime(struct timekeeper *tk,
struct timespec *delta)
{
if (!timespec_valid_strict(delta)) {
printk(KERN_WARNING "__timekeeping_inject_sleeptime: Invalid "
"sleep delta value!\n");
return;
}
tk_xtime_add(tk, delta);
tk_set_wall_to_mono(tk, timespec_sub(tk->wall_to_monotonic, *delta));
tk_set_sleep_time(tk, timespec_add(tk->total_sleep_time, *delta));
}
void timekeeping_inject_sleeptime(struct timespec *delta)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
struct timespec ts;
read_persistent_clock(&ts);
if (!(ts.tv_sec == 0 && ts.tv_nsec == 0))
return;
write_seqlock_irqsave(&tk->lock, flags);
timekeeping_forward_now(tk);
__timekeeping_inject_sleeptime(tk, delta);
timekeeping_update(tk, true);
write_sequnlock_irqrestore(&tk->lock, flags);
clock_was_set();
}
static void timekeeping_resume(void)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
struct timespec ts;
read_persistent_clock(&ts);
clockevents_resume();
clocksource_resume();
write_seqlock_irqsave(&tk->lock, flags);
if (timespec_compare(&ts, &timekeeping_suspend_time) > 0) {
ts = timespec_sub(ts, timekeeping_suspend_time);
__timekeeping_inject_sleeptime(tk, &ts);
}
tk->clock->cycle_last = tk->clock->read(tk->clock);
tk->ntp_error = 0;
timekeeping_suspended = 0;
timekeeping_update(tk, false);
write_sequnlock_irqrestore(&tk->lock, flags);
touch_softlockup_watchdog();
clockevents_notify(CLOCK_EVT_NOTIFY_RESUME, NULL);
hrtimers_resume();
}
static int timekeeping_suspend(void)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
struct timespec delta, delta_delta;
static struct timespec old_delta;
read_persistent_clock(&timekeeping_suspend_time);
write_seqlock_irqsave(&tk->lock, flags);
timekeeping_forward_now(tk);
timekeeping_suspended = 1;
delta = timespec_sub(tk_xtime(tk), timekeeping_suspend_time);
delta_delta = timespec_sub(delta, old_delta);
if (abs(delta_delta.tv_sec) >= 2) {
old_delta = delta;
} else {
timekeeping_suspend_time =
timespec_add(timekeeping_suspend_time, delta_delta);
}
write_sequnlock_irqrestore(&tk->lock, flags);
clockevents_notify(CLOCK_EVT_NOTIFY_SUSPEND, NULL);
clocksource_suspend();
clockevents_suspend();
return 0;
}
static int __init timekeeping_init_ops(void)
{
register_syscore_ops(&timekeeping_syscore_ops);
return 0;
}
static __always_inline int timekeeping_bigadjust(struct timekeeper *tk,
s64 error, s64 *interval,
s64 *offset)
{
s64 tick_error, i;
u32 look_ahead, adj;
s32 error2, mult;
error2 = tk->ntp_error >> (NTP_SCALE_SHIFT + 22 - 2 * SHIFT_HZ);
error2 = abs(error2);
for (look_ahead = 0; error2 > 0; look_ahead++)
error2 >>= 2;
tick_error = ntp_tick_length() >> (tk->ntp_error_shift + 1);
tick_error -= tk->xtime_interval >> 1;
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
static void timekeeping_adjust(struct timekeeper *tk, s64 offset)
{
s64 error, interval = tk->cycle_interval;
int adj;
error = tk->ntp_error >> (tk->ntp_error_shift - 1);
if (error > interval) {
error >>= 2;
if (likely(error <= interval))
adj = 1;
else
adj = timekeeping_bigadjust(tk, error, &interval, &offset);
} else {
if (error < -interval) {
error >>= 2;
if (likely(error >= -interval)) {
adj = -1;
interval = -interval;
offset = -offset;
} else {
adj = timekeeping_bigadjust(tk, error, &interval, &offset);
}
} else {
goto out_adjust;
}
}
if (unlikely(tk->clock->maxadj &&
(tk->mult + adj > tk->clock->mult + tk->clock->maxadj))) {
printk_once(KERN_WARNING
"Adjusting %s more than 11%% (%ld vs %ld)\n",
tk->clock->name, (long)tk->mult + adj,
(long)tk->clock->mult + tk->clock->maxadj);
}
tk->mult += adj;
tk->xtime_interval += interval;
tk->xtime_nsec -= offset;
tk->ntp_error -= (interval - offset) << tk->ntp_error_shift;
out_adjust:
if (unlikely((s64)tk->xtime_nsec < 0)) {
s64 neg = -(s64)tk->xtime_nsec;
tk->xtime_nsec = 0;
tk->ntp_error += neg << tk->ntp_error_shift;
}
}
static inline void accumulate_nsecs_to_secs(struct timekeeper *tk)
{
u64 nsecps = (u64)NSEC_PER_SEC << tk->shift;
while (tk->xtime_nsec >= nsecps) {
int leap;
tk->xtime_nsec -= nsecps;
tk->xtime_sec++;
leap = second_overflow(tk->xtime_sec);
if (unlikely(leap)) {
struct timespec ts;
tk->xtime_sec += leap;
ts.tv_sec = leap;
ts.tv_nsec = 0;
tk_set_wall_to_mono(tk,
timespec_sub(tk->wall_to_monotonic, ts));
clock_was_set_delayed();
}
}
}
static cycle_t logarithmic_accumulation(struct timekeeper *tk, cycle_t offset,
u32 shift)
{
u64 raw_nsecs;
if (offset < tk->cycle_interval<<shift)
return offset;
offset -= tk->cycle_interval << shift;
tk->clock->cycle_last += tk->cycle_interval << shift;
tk->xtime_nsec += tk->xtime_interval << shift;
accumulate_nsecs_to_secs(tk);
raw_nsecs = (u64)tk->raw_interval << shift;
raw_nsecs += tk->raw_time.tv_nsec;
if (raw_nsecs >= NSEC_PER_SEC) {
u64 raw_secs = raw_nsecs;
raw_nsecs = do_div(raw_secs, NSEC_PER_SEC);
tk->raw_time.tv_sec += raw_secs;
}
tk->raw_time.tv_nsec = raw_nsecs;
tk->ntp_error += ntp_tick_length() << shift;
tk->ntp_error -= (tk->xtime_interval + tk->xtime_remainder) <<
(tk->ntp_error_shift + shift);
return offset;
}
static inline void old_vsyscall_fixup(struct timekeeper *tk)
{
s64 remainder;
remainder = tk->xtime_nsec & ((1ULL << tk->shift) - 1);
tk->xtime_nsec -= remainder;
tk->xtime_nsec += 1ULL << tk->shift;
tk->ntp_error += remainder << tk->ntp_error_shift;
}
static void update_wall_time(void)
{
struct clocksource *clock;
struct timekeeper *tk = &timekeeper;
cycle_t offset;
int shift = 0, maxshift;
unsigned long flags;
write_seqlock_irqsave(&tk->lock, flags);
if (unlikely(timekeeping_suspended))
goto out;
clock = tk->clock;
#ifdef CONFIG_ARCH_USES_GETTIMEOFFSET
offset = tk->cycle_interval;
#else
offset = (clock->read(clock) - clock->cycle_last) & clock->mask;
#endif
if (offset < tk->cycle_interval)
goto out;
shift = ilog2(offset) - ilog2(tk->cycle_interval);
shift = max(0, shift);
maxshift = (64 - (ilog2(ntp_tick_length())+1)) - 1;
shift = min(shift, maxshift);
while (offset >= tk->cycle_interval) {
offset = logarithmic_accumulation(tk, offset, shift);
if (offset < tk->cycle_interval<<shift)
shift--;
}
timekeeping_adjust(tk, offset);
old_vsyscall_fixup(tk);
accumulate_nsecs_to_secs(tk);
timekeeping_update(tk, false);
out:
write_sequnlock_irqrestore(&tk->lock, flags);
}
void getboottime(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
struct timespec boottime = {
.tv_sec = tk->wall_to_monotonic.tv_sec +
tk->total_sleep_time.tv_sec,
.tv_nsec = tk->wall_to_monotonic.tv_nsec +
tk->total_sleep_time.tv_nsec
};
set_normalized_timespec(ts, -boottime.tv_sec, -boottime.tv_nsec);
}
void get_monotonic_boottime(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
struct timespec tomono, sleep;
s64 nsec;
unsigned int seq;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqbegin(&tk->lock);
ts->tv_sec = tk->xtime_sec;
nsec = timekeeping_get_ns(tk);
tomono = tk->wall_to_monotonic;
sleep = tk->total_sleep_time;
} while (read_seqretry(&tk->lock, seq));
ts->tv_sec += tomono.tv_sec + sleep.tv_sec;
ts->tv_nsec = 0;
timespec_add_ns(ts, nsec + tomono.tv_nsec + sleep.tv_nsec);
}
ktime_t ktime_get_boottime(void)
{
struct timespec ts;
get_monotonic_boottime(&ts);
return timespec_to_ktime(ts);
}
void monotonic_to_bootbased(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
*ts = timespec_add(*ts, tk->total_sleep_time);
}
unsigned long get_seconds(void)
{
struct timekeeper *tk = &timekeeper;
return tk->xtime_sec;
}
struct timespec __current_kernel_time(void)
{
struct timekeeper *tk = &timekeeper;
return tk_xtime(tk);
}
struct timespec current_kernel_time(void)
{
struct timekeeper *tk = &timekeeper;
struct timespec now;
unsigned long seq;
do {
seq = read_seqbegin(&tk->lock);
now = tk_xtime(tk);
} while (read_seqretry(&tk->lock, seq));
return now;
}
struct timespec get_monotonic_coarse(void)
{
struct timekeeper *tk = &timekeeper;
struct timespec now, mono;
unsigned long seq;
do {
seq = read_seqbegin(&tk->lock);
now = tk_xtime(tk);
mono = tk->wall_to_monotonic;
} while (read_seqretry(&tk->lock, seq));
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
struct timekeeper *tk = &timekeeper;
unsigned long seq;
do {
seq = read_seqbegin(&tk->lock);
*xtim = tk_xtime(tk);
*wtom = tk->wall_to_monotonic;
*sleep = tk->total_sleep_time;
} while (read_seqretry(&tk->lock, seq));
}
ktime_t ktime_get_update_offsets(ktime_t *offs_real, ktime_t *offs_boot)
{
struct timekeeper *tk = &timekeeper;
ktime_t now;
unsigned int seq;
u64 secs, nsecs;
do {
seq = read_seqbegin(&tk->lock);
secs = tk->xtime_sec;
nsecs = timekeeping_get_ns(tk);
*offs_real = tk->offs_real;
*offs_boot = tk->offs_boot;
} while (read_seqretry(&tk->lock, seq));
now = ktime_add_ns(ktime_set(secs, 0), nsecs);
now = ktime_sub(now, *offs_real);
return now;
}
ktime_t ktime_get_monotonic_offset(void)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
struct timespec wtom;
do {
seq = read_seqbegin(&tk->lock);
wtom = tk->wall_to_monotonic;
} while (read_seqretry(&tk->lock, seq));
return timespec_to_ktime(wtom);
}
void xtime_update(unsigned long ticks)
{
write_seqlock(&jiffies_lock);
do_timer(ticks);
write_sequnlock(&jiffies_lock);
}
