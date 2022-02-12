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
tk->offs_tai = ktime_add(tk->offs_real, ktime_set(tk->tai_offset, 0));
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
tk->cycle_last = clock->cycle_last = clock->read(clock);
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
u32 get_arch_timeoffset(void)
{
if (likely(arch_gettimeoffset))
return arch_gettimeoffset();
return 0;
}
static inline u32 get_arch_timeoffset(void) { return 0; }
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
return nsec + get_arch_timeoffset();
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
return nsec + get_arch_timeoffset();
}
static void update_pvclock_gtod(struct timekeeper *tk, bool was_set)
{
raw_notifier_call_chain(&pvclock_gtod_chain, was_set, tk);
}
int pvclock_gtod_register_notifier(struct notifier_block *nb)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
int ret;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
ret = raw_notifier_chain_register(&pvclock_gtod_chain, nb);
update_pvclock_gtod(tk, true);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
return ret;
}
int pvclock_gtod_unregister_notifier(struct notifier_block *nb)
{
unsigned long flags;
int ret;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
ret = raw_notifier_chain_unregister(&pvclock_gtod_chain, nb);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
return ret;
}
static void timekeeping_update(struct timekeeper *tk, unsigned int action)
{
if (action & TK_CLEAR_NTP) {
tk->ntp_error = 0;
ntp_clear();
}
update_vsyscall(tk);
update_pvclock_gtod(tk, action & TK_CLOCK_WAS_SET);
if (action & TK_MIRROR)
memcpy(&shadow_timekeeper, &timekeeper, sizeof(timekeeper));
}
static void timekeeping_forward_now(struct timekeeper *tk)
{
cycle_t cycle_now, cycle_delta;
struct clocksource *clock;
s64 nsec;
clock = tk->clock;
cycle_now = clock->read(clock);
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
tk->cycle_last = clock->cycle_last = cycle_now;
tk->xtime_nsec += cycle_delta * tk->mult;
tk->xtime_nsec += (u64)get_arch_timeoffset() << tk->shift;
tk_normalize_xtime(tk);
nsec = clocksource_cyc2ns(cycle_delta, clock->mult, clock->shift);
timespec_add_ns(&tk->raw_time, nsec);
}
int __getnstimeofday(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
s64 nsecs = 0;
do {
seq = read_seqcount_begin(&timekeeper_seq);
ts->tv_sec = tk->xtime_sec;
nsecs = timekeeping_get_ns(tk);
} while (read_seqcount_retry(&timekeeper_seq, seq));
ts->tv_nsec = 0;
timespec_add_ns(ts, nsecs);
if (unlikely(timekeeping_suspended))
return -EAGAIN;
return 0;
}
void getnstimeofday(struct timespec *ts)
{
WARN_ON(__getnstimeofday(ts));
}
ktime_t ktime_get(void)
{
struct timekeeper *tk = &timekeeper;
unsigned int seq;
s64 secs, nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqcount_begin(&timekeeper_seq);
secs = tk->xtime_sec + tk->wall_to_monotonic.tv_sec;
nsecs = timekeeping_get_ns(tk) + tk->wall_to_monotonic.tv_nsec;
} while (read_seqcount_retry(&timekeeper_seq, seq));
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
seq = read_seqcount_begin(&timekeeper_seq);
ts->tv_sec = tk->xtime_sec;
nsec = timekeeping_get_ns(tk);
tomono = tk->wall_to_monotonic;
} while (read_seqcount_retry(&timekeeper_seq, seq));
ts->tv_sec += tomono.tv_sec;
ts->tv_nsec = 0;
timespec_add_ns(ts, nsec + tomono.tv_nsec);
}
void timekeeping_clocktai(struct timespec *ts)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
u64 nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqcount_begin(&timekeeper_seq);
ts->tv_sec = tk->xtime_sec + tk->tai_offset;
nsecs = timekeeping_get_ns(tk);
} while (read_seqcount_retry(&timekeeper_seq, seq));
ts->tv_nsec = 0;
timespec_add_ns(ts, nsecs);
}
ktime_t ktime_get_clocktai(void)
{
struct timespec ts;
timekeeping_clocktai(&ts);
return timespec_to_ktime(ts);
}
void getnstime_raw_and_real(struct timespec *ts_raw, struct timespec *ts_real)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
s64 nsecs_raw, nsecs_real;
WARN_ON_ONCE(timekeeping_suspended);
do {
seq = read_seqcount_begin(&timekeeper_seq);
*ts_raw = tk->raw_time;
ts_real->tv_sec = tk->xtime_sec;
ts_real->tv_nsec = 0;
nsecs_raw = timekeeping_get_ns_raw(tk);
nsecs_real = timekeeping_get_ns(tk);
} while (read_seqcount_retry(&timekeeper_seq, seq));
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
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
timekeeping_forward_now(tk);
xt = tk_xtime(tk);
ts_delta.tv_sec = tv->tv_sec - xt.tv_sec;
ts_delta.tv_nsec = tv->tv_nsec - xt.tv_nsec;
tk_set_wall_to_mono(tk, timespec_sub(tk->wall_to_monotonic, ts_delta));
tk_set_xtime(tk, tv);
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
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
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
timekeeping_forward_now(tk);
tmp = timespec_add(tk_xtime(tk), *ts);
if (!timespec_valid_strict(&tmp)) {
ret = -EINVAL;
goto error;
}
tk_xtime_add(tk, ts);
tk_set_wall_to_mono(tk, timespec_sub(tk->wall_to_monotonic, *ts));
error:
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
clock_was_set();
return ret;
}
s32 timekeeping_get_tai_offset(void)
{
struct timekeeper *tk = &timekeeper;
unsigned int seq;
s32 ret;
do {
seq = read_seqcount_begin(&timekeeper_seq);
ret = tk->tai_offset;
} while (read_seqcount_retry(&timekeeper_seq, seq));
return ret;
}
static void __timekeeping_set_tai_offset(struct timekeeper *tk, s32 tai_offset)
{
tk->tai_offset = tai_offset;
tk->offs_tai = ktime_add(tk->offs_real, ktime_set(tai_offset, 0));
}
void timekeeping_set_tai_offset(s32 tai_offset)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
__timekeeping_set_tai_offset(tk, tai_offset);
timekeeping_update(tk, TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
clock_was_set();
}
static int change_clocksource(void *data)
{
struct timekeeper *tk = &timekeeper;
struct clocksource *new, *old;
unsigned long flags;
new = (struct clocksource *) data;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
timekeeping_forward_now(tk);
if (try_module_get(new->owner)) {
if (!new->enable || new->enable(new) == 0) {
old = tk->clock;
tk_setup_internals(tk, new);
if (old->disable)
old->disable(old);
module_put(old->owner);
} else {
module_put(new->owner);
}
}
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
return 0;
}
int timekeeping_notify(struct clocksource *clock)
{
struct timekeeper *tk = &timekeeper;
if (tk->clock == clock)
return 0;
stop_machine(change_clocksource, clock, NULL);
tick_clock_notify();
return tk->clock == clock ? 0 : -1;
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
seq = read_seqcount_begin(&timekeeper_seq);
nsecs = timekeeping_get_ns_raw(tk);
*ts = tk->raw_time;
} while (read_seqcount_retry(&timekeeper_seq, seq));
timespec_add_ns(ts, nsecs);
}
int timekeeping_valid_for_hres(void)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
int ret;
do {
seq = read_seqcount_begin(&timekeeper_seq);
ret = tk->clock->flags & CLOCK_SOURCE_VALID_FOR_HRES;
} while (read_seqcount_retry(&timekeeper_seq, seq));
return ret;
}
u64 timekeeping_max_deferment(void)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
u64 ret;
do {
seq = read_seqcount_begin(&timekeeper_seq);
ret = tk->clock->max_idle_ns;
} while (read_seqcount_retry(&timekeeper_seq, seq));
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
} else if (now.tv_sec || now.tv_nsec)
persistent_clock_exist = true;
read_boot_clock(&boot);
if (!timespec_valid_strict(&boot)) {
pr_warn("WARNING: Boot clock returned invalid value!\n"
" Check your CMOS/BIOS settings.\n");
boot.tv_sec = 0;
boot.tv_nsec = 0;
}
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
ntp_init();
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
memcpy(&shadow_timekeeper, &timekeeper, sizeof(timekeeper));
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
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
tk_debug_account_sleep_time(delta);
}
void timekeeping_inject_sleeptime(struct timespec *delta)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
if (has_persistent_clock())
return;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
timekeeping_forward_now(tk);
__timekeeping_inject_sleeptime(tk, delta);
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
clock_was_set();
}
static void timekeeping_resume(void)
{
struct timekeeper *tk = &timekeeper;
struct clocksource *clock = tk->clock;
unsigned long flags;
struct timespec ts_new, ts_delta;
cycle_t cycle_now, cycle_delta;
bool suspendtime_found = false;
read_persistent_clock(&ts_new);
clockevents_resume();
clocksource_resume();
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
cycle_now = clock->read(clock);
if ((clock->flags & CLOCK_SOURCE_SUSPEND_NONSTOP) &&
cycle_now > clock->cycle_last) {
u64 num, max = ULLONG_MAX;
u32 mult = clock->mult;
u32 shift = clock->shift;
s64 nsec = 0;
cycle_delta = (cycle_now - clock->cycle_last) & clock->mask;
do_div(max, mult);
if (cycle_delta > max) {
num = div64_u64(cycle_delta, max);
nsec = (((u64) max * mult) >> shift) * num;
cycle_delta -= num * max;
}
nsec += ((u64) cycle_delta * mult) >> shift;
ts_delta = ns_to_timespec(nsec);
suspendtime_found = true;
} else if (timespec_compare(&ts_new, &timekeeping_suspend_time) > 0) {
ts_delta = timespec_sub(ts_new, timekeeping_suspend_time);
suspendtime_found = true;
}
if (suspendtime_found)
__timekeeping_inject_sleeptime(tk, &ts_delta);
tk->cycle_last = clock->cycle_last = cycle_now;
tk->ntp_error = 0;
timekeeping_suspended = 0;
timekeeping_update(tk, TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
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
if (timekeeping_suspend_time.tv_sec || timekeeping_suspend_time.tv_nsec)
persistent_clock_exist = true;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
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
timekeeping_update(tk, TK_MIRROR);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
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
static inline unsigned int accumulate_nsecs_to_secs(struct timekeeper *tk)
{
u64 nsecps = (u64)NSEC_PER_SEC << tk->shift;
unsigned int clock_set = 0;
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
__timekeeping_set_tai_offset(tk, tk->tai_offset - leap);
clock_set = TK_CLOCK_WAS_SET;
}
}
return clock_set;
}
static cycle_t logarithmic_accumulation(struct timekeeper *tk, cycle_t offset,
u32 shift,
unsigned int *clock_set)
{
cycle_t interval = tk->cycle_interval << shift;
u64 raw_nsecs;
if (offset < interval)
return offset;
offset -= interval;
tk->cycle_last += interval;
tk->xtime_nsec += tk->xtime_interval << shift;
*clock_set |= accumulate_nsecs_to_secs(tk);
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
tk->ntp_error -= (1ULL << tk->shift) << tk->ntp_error_shift;
}
void update_wall_time(void)
{
struct clocksource *clock;
struct timekeeper *real_tk = &timekeeper;
struct timekeeper *tk = &shadow_timekeeper;
cycle_t offset;
int shift = 0, maxshift;
unsigned int clock_set = 0;
unsigned long flags;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
if (unlikely(timekeeping_suspended))
goto out;
clock = real_tk->clock;
#ifdef CONFIG_ARCH_USES_GETTIMEOFFSET
offset = real_tk->cycle_interval;
#else
offset = (clock->read(clock) - clock->cycle_last) & clock->mask;
#endif
if (offset < real_tk->cycle_interval)
goto out;
shift = ilog2(offset) - ilog2(tk->cycle_interval);
shift = max(0, shift);
maxshift = (64 - (ilog2(ntp_tick_length())+1)) - 1;
shift = min(shift, maxshift);
while (offset >= tk->cycle_interval) {
offset = logarithmic_accumulation(tk, offset, shift,
&clock_set);
if (offset < tk->cycle_interval<<shift)
shift--;
}
timekeeping_adjust(tk, offset);
old_vsyscall_fixup(tk);
clock_set |= accumulate_nsecs_to_secs(tk);
write_seqcount_begin(&timekeeper_seq);
clock->cycle_last = tk->cycle_last;
memcpy(real_tk, tk, sizeof(*tk));
timekeeping_update(real_tk, clock_set);
write_seqcount_end(&timekeeper_seq);
out:
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
if (clock_set)
clock_was_set_delayed();
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
seq = read_seqcount_begin(&timekeeper_seq);
ts->tv_sec = tk->xtime_sec;
nsec = timekeeping_get_ns(tk);
tomono = tk->wall_to_monotonic;
sleep = tk->total_sleep_time;
} while (read_seqcount_retry(&timekeeper_seq, seq));
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
seq = read_seqcount_begin(&timekeeper_seq);
now = tk_xtime(tk);
} while (read_seqcount_retry(&timekeeper_seq, seq));
return now;
}
struct timespec get_monotonic_coarse(void)
{
struct timekeeper *tk = &timekeeper;
struct timespec now, mono;
unsigned long seq;
do {
seq = read_seqcount_begin(&timekeeper_seq);
now = tk_xtime(tk);
mono = tk->wall_to_monotonic;
} while (read_seqcount_retry(&timekeeper_seq, seq));
set_normalized_timespec(&now, now.tv_sec + mono.tv_sec,
now.tv_nsec + mono.tv_nsec);
return now;
}
void do_timer(unsigned long ticks)
{
jiffies_64 += ticks;
calc_global_load(ticks);
}
void get_xtime_and_monotonic_and_sleep_offset(struct timespec *xtim,
struct timespec *wtom, struct timespec *sleep)
{
struct timekeeper *tk = &timekeeper;
unsigned long seq;
do {
seq = read_seqcount_begin(&timekeeper_seq);
*xtim = tk_xtime(tk);
*wtom = tk->wall_to_monotonic;
*sleep = tk->total_sleep_time;
} while (read_seqcount_retry(&timekeeper_seq, seq));
}
ktime_t ktime_get_update_offsets(ktime_t *offs_real, ktime_t *offs_boot,
ktime_t *offs_tai)
{
struct timekeeper *tk = &timekeeper;
ktime_t now;
unsigned int seq;
u64 secs, nsecs;
do {
seq = read_seqcount_begin(&timekeeper_seq);
secs = tk->xtime_sec;
nsecs = timekeeping_get_ns(tk);
*offs_real = tk->offs_real;
*offs_boot = tk->offs_boot;
*offs_tai = tk->offs_tai;
} while (read_seqcount_retry(&timekeeper_seq, seq));
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
seq = read_seqcount_begin(&timekeeper_seq);
wtom = tk->wall_to_monotonic;
} while (read_seqcount_retry(&timekeeper_seq, seq));
return timespec_to_ktime(wtom);
}
int do_adjtimex(struct timex *txc)
{
struct timekeeper *tk = &timekeeper;
unsigned long flags;
struct timespec ts;
s32 orig_tai, tai;
int ret;
ret = ntp_validate_timex(txc);
if (ret)
return ret;
if (txc->modes & ADJ_SETOFFSET) {
struct timespec delta;
delta.tv_sec = txc->time.tv_sec;
delta.tv_nsec = txc->time.tv_usec;
if (!(txc->modes & ADJ_NANO))
delta.tv_nsec *= 1000;
ret = timekeeping_inject_offset(&delta);
if (ret)
return ret;
}
getnstimeofday(&ts);
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
orig_tai = tai = tk->tai_offset;
ret = __do_adjtimex(txc, &ts, &tai);
if (tai != orig_tai) {
__timekeeping_set_tai_offset(tk, tai);
timekeeping_update(tk, TK_MIRROR | TK_CLOCK_WAS_SET);
}
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
if (tai != orig_tai)
clock_was_set();
ntp_notify_cmos_timer();
return ret;
}
void hardpps(const struct timespec *phase_ts, const struct timespec *raw_ts)
{
unsigned long flags;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&timekeeper_seq);
__hardpps(phase_ts, raw_ts);
write_seqcount_end(&timekeeper_seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
}
void xtime_update(unsigned long ticks)
{
write_seqlock(&jiffies_lock);
do_timer(ticks);
write_sequnlock(&jiffies_lock);
update_wall_time();
}
