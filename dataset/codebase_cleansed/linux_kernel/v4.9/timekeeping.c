static inline void tk_normalize_xtime(struct timekeeper *tk)
{
while (tk->tkr_mono.xtime_nsec >= ((u64)NSEC_PER_SEC << tk->tkr_mono.shift)) {
tk->tkr_mono.xtime_nsec -= (u64)NSEC_PER_SEC << tk->tkr_mono.shift;
tk->xtime_sec++;
}
}
static inline struct timespec64 tk_xtime(struct timekeeper *tk)
{
struct timespec64 ts;
ts.tv_sec = tk->xtime_sec;
ts.tv_nsec = (long)(tk->tkr_mono.xtime_nsec >> tk->tkr_mono.shift);
return ts;
}
static void tk_set_xtime(struct timekeeper *tk, const struct timespec64 *ts)
{
tk->xtime_sec = ts->tv_sec;
tk->tkr_mono.xtime_nsec = (u64)ts->tv_nsec << tk->tkr_mono.shift;
}
static void tk_xtime_add(struct timekeeper *tk, const struct timespec64 *ts)
{
tk->xtime_sec += ts->tv_sec;
tk->tkr_mono.xtime_nsec += (u64)ts->tv_nsec << tk->tkr_mono.shift;
tk_normalize_xtime(tk);
}
static void tk_set_wall_to_mono(struct timekeeper *tk, struct timespec64 wtm)
{
struct timespec64 tmp;
set_normalized_timespec64(&tmp, -tk->wall_to_monotonic.tv_sec,
-tk->wall_to_monotonic.tv_nsec);
WARN_ON_ONCE(tk->offs_real.tv64 != timespec64_to_ktime(tmp).tv64);
tk->wall_to_monotonic = wtm;
set_normalized_timespec64(&tmp, -wtm.tv_sec, -wtm.tv_nsec);
tk->offs_real = timespec64_to_ktime(tmp);
tk->offs_tai = ktime_add(tk->offs_real, ktime_set(tk->tai_offset, 0));
}
static inline void tk_update_sleep_time(struct timekeeper *tk, ktime_t delta)
{
tk->offs_boot = ktime_add(tk->offs_boot, delta);
}
static void timekeeping_check_update(struct timekeeper *tk, cycle_t offset)
{
cycle_t max_cycles = tk->tkr_mono.clock->max_cycles;
const char *name = tk->tkr_mono.clock->name;
if (offset > max_cycles) {
printk_deferred("WARNING: timekeeping: Cycle offset (%lld) is larger than allowed by the '%s' clock's max_cycles value (%lld): time overflow danger\n",
offset, name, max_cycles);
printk_deferred(" timekeeping: Your kernel is sick, but tries to cope by capping time updates\n");
} else {
if (offset > (max_cycles >> 1)) {
printk_deferred("INFO: timekeeping: Cycle offset (%lld) is larger than the '%s' clock's 50%% safety margin (%lld)\n",
offset, name, max_cycles >> 1);
printk_deferred(" timekeeping: Your kernel is still fine, but is feeling a bit nervous\n");
}
}
if (tk->underflow_seen) {
if (jiffies - tk->last_warning > WARNING_FREQ) {
printk_deferred("WARNING: Underflow in clocksource '%s' observed, time update ignored.\n", name);
printk_deferred(" Please report this, consider using a different clocksource, if possible.\n");
printk_deferred(" Your kernel is probably still fine.\n");
tk->last_warning = jiffies;
}
tk->underflow_seen = 0;
}
if (tk->overflow_seen) {
if (jiffies - tk->last_warning > WARNING_FREQ) {
printk_deferred("WARNING: Overflow in clocksource '%s' observed, time update capped.\n", name);
printk_deferred(" Please report this, consider using a different clocksource, if possible.\n");
printk_deferred(" Your kernel is probably still fine.\n");
tk->last_warning = jiffies;
}
tk->overflow_seen = 0;
}
}
static inline cycle_t timekeeping_get_delta(struct tk_read_base *tkr)
{
struct timekeeper *tk = &tk_core.timekeeper;
cycle_t now, last, mask, max, delta;
unsigned int seq;
do {
seq = read_seqcount_begin(&tk_core.seq);
now = tkr->read(tkr->clock);
last = tkr->cycle_last;
mask = tkr->mask;
max = tkr->clock->max_cycles;
} while (read_seqcount_retry(&tk_core.seq, seq));
delta = clocksource_delta(now, last, mask);
if (unlikely((~delta & mask) < (mask >> 3))) {
tk->underflow_seen = 1;
delta = 0;
}
if (unlikely(delta > max)) {
tk->overflow_seen = 1;
delta = tkr->clock->max_cycles;
}
return delta;
}
static inline void timekeeping_check_update(struct timekeeper *tk, cycle_t offset)
{
}
static inline cycle_t timekeeping_get_delta(struct tk_read_base *tkr)
{
cycle_t cycle_now, delta;
cycle_now = tkr->read(tkr->clock);
delta = clocksource_delta(cycle_now, tkr->cycle_last, tkr->mask);
return delta;
}
static void tk_setup_internals(struct timekeeper *tk, struct clocksource *clock)
{
cycle_t interval;
u64 tmp, ntpinterval;
struct clocksource *old_clock;
++tk->cs_was_changed_seq;
old_clock = tk->tkr_mono.clock;
tk->tkr_mono.clock = clock;
tk->tkr_mono.read = clock->read;
tk->tkr_mono.mask = clock->mask;
tk->tkr_mono.cycle_last = tk->tkr_mono.read(clock);
tk->tkr_raw.clock = clock;
tk->tkr_raw.read = clock->read;
tk->tkr_raw.mask = clock->mask;
tk->tkr_raw.cycle_last = tk->tkr_mono.cycle_last;
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
tk->tkr_mono.xtime_nsec >>= -shift_change;
else
tk->tkr_mono.xtime_nsec <<= shift_change;
}
tk->tkr_raw.xtime_nsec = 0;
tk->tkr_mono.shift = clock->shift;
tk->tkr_raw.shift = clock->shift;
tk->ntp_error = 0;
tk->ntp_error_shift = NTP_SCALE_SHIFT - clock->shift;
tk->ntp_tick = ntpinterval << tk->ntp_error_shift;
tk->tkr_mono.mult = clock->mult;
tk->tkr_raw.mult = clock->mult;
tk->ntp_err_mult = 0;
}
static u32 default_arch_gettimeoffset(void) { return 0; }
static inline u32 arch_gettimeoffset(void) { return 0; }
static inline s64 timekeeping_delta_to_ns(struct tk_read_base *tkr,
cycle_t delta)
{
s64 nsec;
nsec = delta * tkr->mult + tkr->xtime_nsec;
nsec >>= tkr->shift;
return nsec + arch_gettimeoffset();
}
static inline s64 timekeeping_get_ns(struct tk_read_base *tkr)
{
cycle_t delta;
delta = timekeeping_get_delta(tkr);
return timekeeping_delta_to_ns(tkr, delta);
}
static inline s64 timekeeping_cycles_to_ns(struct tk_read_base *tkr,
cycle_t cycles)
{
cycle_t delta;
delta = clocksource_delta(cycles, tkr->cycle_last, tkr->mask);
return timekeeping_delta_to_ns(tkr, delta);
}
static void update_fast_timekeeper(struct tk_read_base *tkr, struct tk_fast *tkf)
{
struct tk_read_base *base = tkf->base;
raw_write_seqcount_latch(&tkf->seq);
memcpy(base, tkr, sizeof(*base));
raw_write_seqcount_latch(&tkf->seq);
memcpy(base + 1, base, sizeof(*base));
}
static __always_inline u64 __ktime_get_fast_ns(struct tk_fast *tkf)
{
struct tk_read_base *tkr;
unsigned int seq;
u64 now;
do {
seq = raw_read_seqcount_latch(&tkf->seq);
tkr = tkf->base + (seq & 0x01);
now = ktime_to_ns(tkr->base);
now += timekeeping_delta_to_ns(tkr,
clocksource_delta(
tkr->read(tkr->clock),
tkr->cycle_last,
tkr->mask));
} while (read_seqcount_retry(&tkf->seq, seq));
return now;
}
u64 ktime_get_mono_fast_ns(void)
{
return __ktime_get_fast_ns(&tk_fast_mono);
}
u64 ktime_get_raw_fast_ns(void)
{
return __ktime_get_fast_ns(&tk_fast_raw);
}
static cycle_t dummy_clock_read(struct clocksource *cs)
{
return cycles_at_suspend;
}
static void halt_fast_timekeeper(struct timekeeper *tk)
{
static struct tk_read_base tkr_dummy;
struct tk_read_base *tkr = &tk->tkr_mono;
memcpy(&tkr_dummy, tkr, sizeof(tkr_dummy));
cycles_at_suspend = tkr->read(tkr->clock);
tkr_dummy.read = dummy_clock_read;
update_fast_timekeeper(&tkr_dummy, &tk_fast_mono);
tkr = &tk->tkr_raw;
memcpy(&tkr_dummy, tkr, sizeof(tkr_dummy));
tkr_dummy.read = dummy_clock_read;
update_fast_timekeeper(&tkr_dummy, &tk_fast_raw);
}
static inline void update_vsyscall(struct timekeeper *tk)
{
struct timespec xt, wm;
xt = timespec64_to_timespec(tk_xtime(tk));
wm = timespec64_to_timespec(tk->wall_to_monotonic);
update_vsyscall_old(&xt, &wm, tk->tkr_mono.clock, tk->tkr_mono.mult,
tk->tkr_mono.cycle_last);
}
static inline void old_vsyscall_fixup(struct timekeeper *tk)
{
s64 remainder;
remainder = tk->tkr_mono.xtime_nsec & ((1ULL << tk->tkr_mono.shift) - 1);
if (remainder != 0) {
tk->tkr_mono.xtime_nsec -= remainder;
tk->tkr_mono.xtime_nsec += 1ULL << tk->tkr_mono.shift;
tk->ntp_error += remainder << tk->ntp_error_shift;
tk->ntp_error -= (1ULL << tk->tkr_mono.shift) << tk->ntp_error_shift;
}
}
static void update_pvclock_gtod(struct timekeeper *tk, bool was_set)
{
raw_notifier_call_chain(&pvclock_gtod_chain, was_set, tk);
}
int pvclock_gtod_register_notifier(struct notifier_block *nb)
{
struct timekeeper *tk = &tk_core.timekeeper;
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
static inline void tk_update_leap_state(struct timekeeper *tk)
{
tk->next_leap_ktime = ntp_get_next_leap();
if (tk->next_leap_ktime.tv64 != KTIME_MAX)
tk->next_leap_ktime = ktime_sub(tk->next_leap_ktime, tk->offs_real);
}
static inline void tk_update_ktime_data(struct timekeeper *tk)
{
u64 seconds;
u32 nsec;
seconds = (u64)(tk->xtime_sec + tk->wall_to_monotonic.tv_sec);
nsec = (u32) tk->wall_to_monotonic.tv_nsec;
tk->tkr_mono.base = ns_to_ktime(seconds * NSEC_PER_SEC + nsec);
tk->tkr_raw.base = timespec64_to_ktime(tk->raw_time);
nsec += (u32)(tk->tkr_mono.xtime_nsec >> tk->tkr_mono.shift);
if (nsec >= NSEC_PER_SEC)
seconds++;
tk->ktime_sec = seconds;
}
static void timekeeping_update(struct timekeeper *tk, unsigned int action)
{
if (action & TK_CLEAR_NTP) {
tk->ntp_error = 0;
ntp_clear();
}
tk_update_leap_state(tk);
tk_update_ktime_data(tk);
update_vsyscall(tk);
update_pvclock_gtod(tk, action & TK_CLOCK_WAS_SET);
update_fast_timekeeper(&tk->tkr_mono, &tk_fast_mono);
update_fast_timekeeper(&tk->tkr_raw, &tk_fast_raw);
if (action & TK_CLOCK_WAS_SET)
tk->clock_was_set_seq++;
if (action & TK_MIRROR)
memcpy(&shadow_timekeeper, &tk_core.timekeeper,
sizeof(tk_core.timekeeper));
}
static void timekeeping_forward_now(struct timekeeper *tk)
{
struct clocksource *clock = tk->tkr_mono.clock;
cycle_t cycle_now, delta;
s64 nsec;
cycle_now = tk->tkr_mono.read(clock);
delta = clocksource_delta(cycle_now, tk->tkr_mono.cycle_last, tk->tkr_mono.mask);
tk->tkr_mono.cycle_last = cycle_now;
tk->tkr_raw.cycle_last = cycle_now;
tk->tkr_mono.xtime_nsec += delta * tk->tkr_mono.mult;
tk->tkr_mono.xtime_nsec += (u64)arch_gettimeoffset() << tk->tkr_mono.shift;
tk_normalize_xtime(tk);
nsec = clocksource_cyc2ns(delta, tk->tkr_raw.mult, tk->tkr_raw.shift);
timespec64_add_ns(&tk->raw_time, nsec);
}
int __getnstimeofday64(struct timespec64 *ts)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long seq;
s64 nsecs = 0;
do {
seq = read_seqcount_begin(&tk_core.seq);
ts->tv_sec = tk->xtime_sec;
nsecs = timekeeping_get_ns(&tk->tkr_mono);
} while (read_seqcount_retry(&tk_core.seq, seq));
ts->tv_nsec = 0;
timespec64_add_ns(ts, nsecs);
if (unlikely(timekeeping_suspended))
return -EAGAIN;
return 0;
}
void getnstimeofday64(struct timespec64 *ts)
{
WARN_ON(__getnstimeofday64(ts));
}
ktime_t ktime_get(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned int seq;
ktime_t base;
s64 nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqcount_begin(&tk_core.seq);
base = tk->tkr_mono.base;
nsecs = timekeeping_get_ns(&tk->tkr_mono);
} while (read_seqcount_retry(&tk_core.seq, seq));
return ktime_add_ns(base, nsecs);
}
u32 ktime_get_resolution_ns(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned int seq;
u32 nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqcount_begin(&tk_core.seq);
nsecs = tk->tkr_mono.mult >> tk->tkr_mono.shift;
} while (read_seqcount_retry(&tk_core.seq, seq));
return nsecs;
}
ktime_t ktime_get_with_offset(enum tk_offsets offs)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned int seq;
ktime_t base, *offset = offsets[offs];
s64 nsecs;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqcount_begin(&tk_core.seq);
base = ktime_add(tk->tkr_mono.base, *offset);
nsecs = timekeeping_get_ns(&tk->tkr_mono);
} while (read_seqcount_retry(&tk_core.seq, seq));
return ktime_add_ns(base, nsecs);
}
ktime_t ktime_mono_to_any(ktime_t tmono, enum tk_offsets offs)
{
ktime_t *offset = offsets[offs];
unsigned long seq;
ktime_t tconv;
do {
seq = read_seqcount_begin(&tk_core.seq);
tconv = ktime_add(tmono, *offset);
} while (read_seqcount_retry(&tk_core.seq, seq));
return tconv;
}
ktime_t ktime_get_raw(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned int seq;
ktime_t base;
s64 nsecs;
do {
seq = read_seqcount_begin(&tk_core.seq);
base = tk->tkr_raw.base;
nsecs = timekeeping_get_ns(&tk->tkr_raw);
} while (read_seqcount_retry(&tk_core.seq, seq));
return ktime_add_ns(base, nsecs);
}
void ktime_get_ts64(struct timespec64 *ts)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct timespec64 tomono;
s64 nsec;
unsigned int seq;
WARN_ON(timekeeping_suspended);
do {
seq = read_seqcount_begin(&tk_core.seq);
ts->tv_sec = tk->xtime_sec;
nsec = timekeeping_get_ns(&tk->tkr_mono);
tomono = tk->wall_to_monotonic;
} while (read_seqcount_retry(&tk_core.seq, seq));
ts->tv_sec += tomono.tv_sec;
ts->tv_nsec = 0;
timespec64_add_ns(ts, nsec + tomono.tv_nsec);
}
time64_t ktime_get_seconds(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
WARN_ON(timekeeping_suspended);
return tk->ktime_sec;
}
time64_t ktime_get_real_seconds(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
time64_t seconds;
unsigned int seq;
if (IS_ENABLED(CONFIG_64BIT))
return tk->xtime_sec;
do {
seq = read_seqcount_begin(&tk_core.seq);
seconds = tk->xtime_sec;
} while (read_seqcount_retry(&tk_core.seq, seq));
return seconds;
}
time64_t __ktime_get_real_seconds(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
return tk->xtime_sec;
}
void ktime_get_snapshot(struct system_time_snapshot *systime_snapshot)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long seq;
ktime_t base_raw;
ktime_t base_real;
s64 nsec_raw;
s64 nsec_real;
cycle_t now;
WARN_ON_ONCE(timekeeping_suspended);
do {
seq = read_seqcount_begin(&tk_core.seq);
now = tk->tkr_mono.read(tk->tkr_mono.clock);
systime_snapshot->cs_was_changed_seq = tk->cs_was_changed_seq;
systime_snapshot->clock_was_set_seq = tk->clock_was_set_seq;
base_real = ktime_add(tk->tkr_mono.base,
tk_core.timekeeper.offs_real);
base_raw = tk->tkr_raw.base;
nsec_real = timekeeping_cycles_to_ns(&tk->tkr_mono, now);
nsec_raw = timekeeping_cycles_to_ns(&tk->tkr_raw, now);
} while (read_seqcount_retry(&tk_core.seq, seq));
systime_snapshot->cycles = now;
systime_snapshot->real = ktime_add_ns(base_real, nsec_real);
systime_snapshot->raw = ktime_add_ns(base_raw, nsec_raw);
}
static int scale64_check_overflow(u64 mult, u64 div, u64 *base)
{
u64 tmp, rem;
tmp = div64_u64_rem(*base, div, &rem);
if (((int)sizeof(u64)*8 - fls64(mult) < fls64(tmp)) ||
((int)sizeof(u64)*8 - fls64(mult) < fls64(rem)))
return -EOVERFLOW;
tmp *= mult;
rem *= mult;
do_div(rem, div);
*base = tmp + rem;
return 0;
}
static int adjust_historical_crosststamp(struct system_time_snapshot *history,
cycle_t partial_history_cycles,
cycle_t total_history_cycles,
bool discontinuity,
struct system_device_crosststamp *ts)
{
struct timekeeper *tk = &tk_core.timekeeper;
u64 corr_raw, corr_real;
bool interp_forward;
int ret;
if (total_history_cycles == 0 || partial_history_cycles == 0)
return 0;
interp_forward = partial_history_cycles > total_history_cycles/2 ?
true : false;
partial_history_cycles = interp_forward ?
total_history_cycles - partial_history_cycles :
partial_history_cycles;
corr_raw = (u64)ktime_to_ns(
ktime_sub(ts->sys_monoraw, history->raw));
ret = scale64_check_overflow(partial_history_cycles,
total_history_cycles, &corr_raw);
if (ret)
return ret;
if (discontinuity) {
corr_real = mul_u64_u32_div
(corr_raw, tk->tkr_mono.mult, tk->tkr_raw.mult);
} else {
corr_real = (u64)ktime_to_ns(
ktime_sub(ts->sys_realtime, history->real));
ret = scale64_check_overflow(partial_history_cycles,
total_history_cycles, &corr_real);
if (ret)
return ret;
}
if (interp_forward) {
ts->sys_monoraw = ktime_add_ns(history->raw, corr_raw);
ts->sys_realtime = ktime_add_ns(history->real, corr_real);
} else {
ts->sys_monoraw = ktime_sub_ns(ts->sys_monoraw, corr_raw);
ts->sys_realtime = ktime_sub_ns(ts->sys_realtime, corr_real);
}
return 0;
}
static bool cycle_between(cycle_t before, cycle_t test, cycle_t after)
{
if (test > before && test < after)
return true;
if (test < before && before > after)
return true;
return false;
}
int get_device_system_crosststamp(int (*get_time_fn)
(ktime_t *device_time,
struct system_counterval_t *sys_counterval,
void *ctx),
void *ctx,
struct system_time_snapshot *history_begin,
struct system_device_crosststamp *xtstamp)
{
struct system_counterval_t system_counterval;
struct timekeeper *tk = &tk_core.timekeeper;
cycle_t cycles, now, interval_start;
unsigned int clock_was_set_seq = 0;
ktime_t base_real, base_raw;
s64 nsec_real, nsec_raw;
u8 cs_was_changed_seq;
unsigned long seq;
bool do_interp;
int ret;
do {
seq = read_seqcount_begin(&tk_core.seq);
ret = get_time_fn(&xtstamp->device, &system_counterval, ctx);
if (ret)
return ret;
if (tk->tkr_mono.clock != system_counterval.cs)
return -ENODEV;
cycles = system_counterval.cycles;
now = tk->tkr_mono.read(tk->tkr_mono.clock);
interval_start = tk->tkr_mono.cycle_last;
if (!cycle_between(interval_start, cycles, now)) {
clock_was_set_seq = tk->clock_was_set_seq;
cs_was_changed_seq = tk->cs_was_changed_seq;
cycles = interval_start;
do_interp = true;
} else {
do_interp = false;
}
base_real = ktime_add(tk->tkr_mono.base,
tk_core.timekeeper.offs_real);
base_raw = tk->tkr_raw.base;
nsec_real = timekeeping_cycles_to_ns(&tk->tkr_mono,
system_counterval.cycles);
nsec_raw = timekeeping_cycles_to_ns(&tk->tkr_raw,
system_counterval.cycles);
} while (read_seqcount_retry(&tk_core.seq, seq));
xtstamp->sys_realtime = ktime_add_ns(base_real, nsec_real);
xtstamp->sys_monoraw = ktime_add_ns(base_raw, nsec_raw);
if (do_interp) {
cycle_t partial_history_cycles, total_history_cycles;
bool discontinuity;
if (!history_begin ||
!cycle_between(history_begin->cycles,
system_counterval.cycles, cycles) ||
history_begin->cs_was_changed_seq != cs_was_changed_seq)
return -EINVAL;
partial_history_cycles = cycles - system_counterval.cycles;
total_history_cycles = cycles - history_begin->cycles;
discontinuity =
history_begin->clock_was_set_seq != clock_was_set_seq;
ret = adjust_historical_crosststamp(history_begin,
partial_history_cycles,
total_history_cycles,
discontinuity, xtstamp);
if (ret)
return ret;
}
return 0;
}
void do_gettimeofday(struct timeval *tv)
{
struct timespec64 now;
getnstimeofday64(&now);
tv->tv_sec = now.tv_sec;
tv->tv_usec = now.tv_nsec/1000;
}
int do_settimeofday64(const struct timespec64 *ts)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct timespec64 ts_delta, xt;
unsigned long flags;
int ret = 0;
if (!timespec64_valid_strict(ts))
return -EINVAL;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
timekeeping_forward_now(tk);
xt = tk_xtime(tk);
ts_delta.tv_sec = ts->tv_sec - xt.tv_sec;
ts_delta.tv_nsec = ts->tv_nsec - xt.tv_nsec;
if (timespec64_compare(&tk->wall_to_monotonic, &ts_delta) > 0) {
ret = -EINVAL;
goto out;
}
tk_set_wall_to_mono(tk, timespec64_sub(tk->wall_to_monotonic, ts_delta));
tk_set_xtime(tk, ts);
out:
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
clock_was_set();
return ret;
}
int timekeeping_inject_offset(struct timespec *ts)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long flags;
struct timespec64 ts64, tmp;
int ret = 0;
if (!timespec_inject_offset_valid(ts))
return -EINVAL;
ts64 = timespec_to_timespec64(*ts);
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
timekeeping_forward_now(tk);
tmp = timespec64_add(tk_xtime(tk), ts64);
if (timespec64_compare(&tk->wall_to_monotonic, &ts64) > 0 ||
!timespec64_valid_strict(&tmp)) {
ret = -EINVAL;
goto error;
}
tk_xtime_add(tk, &ts64);
tk_set_wall_to_mono(tk, timespec64_sub(tk->wall_to_monotonic, ts64));
error:
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
clock_was_set();
return ret;
}
s32 timekeeping_get_tai_offset(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned int seq;
s32 ret;
do {
seq = read_seqcount_begin(&tk_core.seq);
ret = tk->tai_offset;
} while (read_seqcount_retry(&tk_core.seq, seq));
return ret;
}
static void __timekeeping_set_tai_offset(struct timekeeper *tk, s32 tai_offset)
{
tk->tai_offset = tai_offset;
tk->offs_tai = ktime_add(tk->offs_real, ktime_set(tai_offset, 0));
}
void timekeeping_set_tai_offset(s32 tai_offset)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long flags;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
__timekeeping_set_tai_offset(tk, tai_offset);
timekeeping_update(tk, TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
clock_was_set();
}
static int change_clocksource(void *data)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct clocksource *new, *old;
unsigned long flags;
new = (struct clocksource *) data;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
timekeeping_forward_now(tk);
if (try_module_get(new->owner)) {
if (!new->enable || new->enable(new) == 0) {
old = tk->tkr_mono.clock;
tk_setup_internals(tk, new);
if (old->disable)
old->disable(old);
module_put(old->owner);
} else {
module_put(new->owner);
}
}
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
return 0;
}
int timekeeping_notify(struct clocksource *clock)
{
struct timekeeper *tk = &tk_core.timekeeper;
if (tk->tkr_mono.clock == clock)
return 0;
stop_machine(change_clocksource, clock, NULL);
tick_clock_notify();
return tk->tkr_mono.clock == clock ? 0 : -1;
}
void getrawmonotonic64(struct timespec64 *ts)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct timespec64 ts64;
unsigned long seq;
s64 nsecs;
do {
seq = read_seqcount_begin(&tk_core.seq);
nsecs = timekeeping_get_ns(&tk->tkr_raw);
ts64 = tk->raw_time;
} while (read_seqcount_retry(&tk_core.seq, seq));
timespec64_add_ns(&ts64, nsecs);
*ts = ts64;
}
int timekeeping_valid_for_hres(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long seq;
int ret;
do {
seq = read_seqcount_begin(&tk_core.seq);
ret = tk->tkr_mono.clock->flags & CLOCK_SOURCE_VALID_FOR_HRES;
} while (read_seqcount_retry(&tk_core.seq, seq));
return ret;
}
u64 timekeeping_max_deferment(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long seq;
u64 ret;
do {
seq = read_seqcount_begin(&tk_core.seq);
ret = tk->tkr_mono.clock->max_idle_ns;
} while (read_seqcount_retry(&tk_core.seq, seq));
return ret;
}
void __weak read_persistent_clock(struct timespec *ts)
{
ts->tv_sec = 0;
ts->tv_nsec = 0;
}
void __weak read_persistent_clock64(struct timespec64 *ts64)
{
struct timespec ts;
read_persistent_clock(&ts);
*ts64 = timespec_to_timespec64(ts);
}
void __weak read_boot_clock64(struct timespec64 *ts)
{
ts->tv_sec = 0;
ts->tv_nsec = 0;
}
void __init timekeeping_init(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct clocksource *clock;
unsigned long flags;
struct timespec64 now, boot, tmp;
read_persistent_clock64(&now);
if (!timespec64_valid_strict(&now)) {
pr_warn("WARNING: Persistent clock returned invalid value!\n"
" Check your CMOS/BIOS settings.\n");
now.tv_sec = 0;
now.tv_nsec = 0;
} else if (now.tv_sec || now.tv_nsec)
persistent_clock_exists = true;
read_boot_clock64(&boot);
if (!timespec64_valid_strict(&boot)) {
pr_warn("WARNING: Boot clock returned invalid value!\n"
" Check your CMOS/BIOS settings.\n");
boot.tv_sec = 0;
boot.tv_nsec = 0;
}
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
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
set_normalized_timespec64(&tmp, -boot.tv_sec, -boot.tv_nsec);
tk_set_wall_to_mono(tk, tmp);
timekeeping_update(tk, TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
}
static void __timekeeping_inject_sleeptime(struct timekeeper *tk,
struct timespec64 *delta)
{
if (!timespec64_valid_strict(delta)) {
printk_deferred(KERN_WARNING
"__timekeeping_inject_sleeptime: Invalid "
"sleep delta value!\n");
return;
}
tk_xtime_add(tk, delta);
tk_set_wall_to_mono(tk, timespec64_sub(tk->wall_to_monotonic, *delta));
tk_update_sleep_time(tk, timespec64_to_ktime(*delta));
tk_debug_account_sleep_time(delta);
}
bool timekeeping_rtc_skipresume(void)
{
return sleeptime_injected;
}
bool timekeeping_rtc_skipsuspend(void)
{
return persistent_clock_exists;
}
void timekeeping_inject_sleeptime64(struct timespec64 *delta)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long flags;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
timekeeping_forward_now(tk);
__timekeeping_inject_sleeptime(tk, delta);
timekeeping_update(tk, TK_CLEAR_NTP | TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
clock_was_set();
}
void timekeeping_resume(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct clocksource *clock = tk->tkr_mono.clock;
unsigned long flags;
struct timespec64 ts_new, ts_delta;
cycle_t cycle_now, cycle_delta;
sleeptime_injected = false;
read_persistent_clock64(&ts_new);
clockevents_resume();
clocksource_resume();
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
cycle_now = tk->tkr_mono.read(clock);
if ((clock->flags & CLOCK_SOURCE_SUSPEND_NONSTOP) &&
cycle_now > tk->tkr_mono.cycle_last) {
u64 num, max = ULLONG_MAX;
u32 mult = clock->mult;
u32 shift = clock->shift;
s64 nsec = 0;
cycle_delta = clocksource_delta(cycle_now, tk->tkr_mono.cycle_last,
tk->tkr_mono.mask);
do_div(max, mult);
if (cycle_delta > max) {
num = div64_u64(cycle_delta, max);
nsec = (((u64) max * mult) >> shift) * num;
cycle_delta -= num * max;
}
nsec += ((u64) cycle_delta * mult) >> shift;
ts_delta = ns_to_timespec64(nsec);
sleeptime_injected = true;
} else if (timespec64_compare(&ts_new, &timekeeping_suspend_time) > 0) {
ts_delta = timespec64_sub(ts_new, timekeeping_suspend_time);
sleeptime_injected = true;
}
if (sleeptime_injected)
__timekeeping_inject_sleeptime(tk, &ts_delta);
tk->tkr_mono.cycle_last = cycle_now;
tk->tkr_raw.cycle_last = cycle_now;
tk->ntp_error = 0;
timekeeping_suspended = 0;
timekeeping_update(tk, TK_MIRROR | TK_CLOCK_WAS_SET);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
touch_softlockup_watchdog();
tick_resume();
hrtimers_resume();
}
int timekeeping_suspend(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long flags;
struct timespec64 delta, delta_delta;
static struct timespec64 old_delta;
read_persistent_clock64(&timekeeping_suspend_time);
if (timekeeping_suspend_time.tv_sec || timekeeping_suspend_time.tv_nsec)
persistent_clock_exists = true;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
timekeeping_forward_now(tk);
timekeeping_suspended = 1;
if (persistent_clock_exists) {
delta = timespec64_sub(tk_xtime(tk), timekeeping_suspend_time);
delta_delta = timespec64_sub(delta, old_delta);
if (abs(delta_delta.tv_sec) >= 2) {
old_delta = delta;
} else {
timekeeping_suspend_time =
timespec64_add(timekeeping_suspend_time, delta_delta);
}
}
timekeeping_update(tk, TK_MIRROR);
halt_fast_timekeeper(tk);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
tick_suspend();
clocksource_suspend();
clockevents_suspend();
return 0;
}
static int __init timekeeping_init_ops(void)
{
register_syscore_ops(&timekeeping_syscore_ops);
return 0;
}
static __always_inline void timekeeping_apply_adjustment(struct timekeeper *tk,
s64 offset,
bool negative,
int adj_scale)
{
s64 interval = tk->cycle_interval;
s32 mult_adj = 1;
if (negative) {
mult_adj = -mult_adj;
interval = -interval;
offset = -offset;
}
mult_adj <<= adj_scale;
interval <<= adj_scale;
offset <<= adj_scale;
if ((mult_adj > 0) && (tk->tkr_mono.mult + mult_adj < mult_adj)) {
WARN_ON_ONCE(1);
return;
}
tk->tkr_mono.mult += mult_adj;
tk->xtime_interval += interval;
tk->tkr_mono.xtime_nsec -= offset;
tk->ntp_error -= (interval - offset) << tk->ntp_error_shift;
}
static __always_inline void timekeeping_freqadjust(struct timekeeper *tk,
s64 offset)
{
s64 interval = tk->cycle_interval;
s64 xinterval = tk->xtime_interval;
u32 base = tk->tkr_mono.clock->mult;
u32 max = tk->tkr_mono.clock->maxadj;
u32 cur_adj = tk->tkr_mono.mult;
s64 tick_error;
bool negative;
u32 adj_scale;
if (tk->ntp_err_mult)
xinterval -= tk->cycle_interval;
tk->ntp_tick = ntp_tick_length();
tick_error = ntp_tick_length() >> tk->ntp_error_shift;
tick_error -= (xinterval + tk->xtime_remainder);
if (likely((tick_error >= 0) && (tick_error <= interval)))
return;
negative = (tick_error < 0);
if (negative && (cur_adj - 1) <= (base - max))
return;
if (!negative && (cur_adj + 1) >= (base + max))
return;
adj_scale = 0;
tick_error = abs(tick_error);
while (tick_error > interval) {
u32 adj = 1 << (adj_scale + 1);
if (negative && (cur_adj - adj) <= (base - max))
break;
if (!negative && (cur_adj + adj) >= (base + max))
break;
adj_scale++;
tick_error >>= 1;
}
timekeeping_apply_adjustment(tk, offset, negative, adj_scale);
}
static void timekeeping_adjust(struct timekeeper *tk, s64 offset)
{
timekeeping_freqadjust(tk, offset);
if (!tk->ntp_err_mult && (tk->ntp_error > 0)) {
tk->ntp_err_mult = 1;
timekeeping_apply_adjustment(tk, offset, 0, 0);
} else if (tk->ntp_err_mult && (tk->ntp_error <= 0)) {
timekeeping_apply_adjustment(tk, offset, 1, 0);
tk->ntp_err_mult = 0;
}
if (unlikely(tk->tkr_mono.clock->maxadj &&
(abs(tk->tkr_mono.mult - tk->tkr_mono.clock->mult)
> tk->tkr_mono.clock->maxadj))) {
printk_once(KERN_WARNING
"Adjusting %s more than 11%% (%ld vs %ld)\n",
tk->tkr_mono.clock->name, (long)tk->tkr_mono.mult,
(long)tk->tkr_mono.clock->mult + tk->tkr_mono.clock->maxadj);
}
if (unlikely((s64)tk->tkr_mono.xtime_nsec < 0)) {
s64 neg = -(s64)tk->tkr_mono.xtime_nsec;
tk->tkr_mono.xtime_nsec = 0;
tk->ntp_error += neg << tk->ntp_error_shift;
}
}
static inline unsigned int accumulate_nsecs_to_secs(struct timekeeper *tk)
{
u64 nsecps = (u64)NSEC_PER_SEC << tk->tkr_mono.shift;
unsigned int clock_set = 0;
while (tk->tkr_mono.xtime_nsec >= nsecps) {
int leap;
tk->tkr_mono.xtime_nsec -= nsecps;
tk->xtime_sec++;
leap = second_overflow(tk->xtime_sec);
if (unlikely(leap)) {
struct timespec64 ts;
tk->xtime_sec += leap;
ts.tv_sec = leap;
ts.tv_nsec = 0;
tk_set_wall_to_mono(tk,
timespec64_sub(tk->wall_to_monotonic, ts));
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
tk->tkr_mono.cycle_last += interval;
tk->tkr_raw.cycle_last += interval;
tk->tkr_mono.xtime_nsec += tk->xtime_interval << shift;
*clock_set |= accumulate_nsecs_to_secs(tk);
raw_nsecs = (u64)tk->raw_interval << shift;
raw_nsecs += tk->raw_time.tv_nsec;
if (raw_nsecs >= NSEC_PER_SEC) {
u64 raw_secs = raw_nsecs;
raw_nsecs = do_div(raw_secs, NSEC_PER_SEC);
tk->raw_time.tv_sec += raw_secs;
}
tk->raw_time.tv_nsec = raw_nsecs;
tk->ntp_error += tk->ntp_tick << shift;
tk->ntp_error -= (tk->xtime_interval + tk->xtime_remainder) <<
(tk->ntp_error_shift + shift);
return offset;
}
void update_wall_time(void)
{
struct timekeeper *real_tk = &tk_core.timekeeper;
struct timekeeper *tk = &shadow_timekeeper;
cycle_t offset;
int shift = 0, maxshift;
unsigned int clock_set = 0;
unsigned long flags;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
if (unlikely(timekeeping_suspended))
goto out;
#ifdef CONFIG_ARCH_USES_GETTIMEOFFSET
offset = real_tk->cycle_interval;
#else
offset = clocksource_delta(tk->tkr_mono.read(tk->tkr_mono.clock),
tk->tkr_mono.cycle_last, tk->tkr_mono.mask);
#endif
if (offset < real_tk->cycle_interval)
goto out;
timekeeping_check_update(real_tk, offset);
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
write_seqcount_begin(&tk_core.seq);
timekeeping_update(tk, clock_set);
memcpy(real_tk, tk, sizeof(*tk));
write_seqcount_end(&tk_core.seq);
out:
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
if (clock_set)
clock_was_set_delayed();
}
void getboottime64(struct timespec64 *ts)
{
struct timekeeper *tk = &tk_core.timekeeper;
ktime_t t = ktime_sub(tk->offs_real, tk->offs_boot);
*ts = ktime_to_timespec64(t);
}
unsigned long get_seconds(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
return tk->xtime_sec;
}
struct timespec __current_kernel_time(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
return timespec64_to_timespec(tk_xtime(tk));
}
struct timespec64 current_kernel_time64(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct timespec64 now;
unsigned long seq;
do {
seq = read_seqcount_begin(&tk_core.seq);
now = tk_xtime(tk);
} while (read_seqcount_retry(&tk_core.seq, seq));
return now;
}
struct timespec64 get_monotonic_coarse64(void)
{
struct timekeeper *tk = &tk_core.timekeeper;
struct timespec64 now, mono;
unsigned long seq;
do {
seq = read_seqcount_begin(&tk_core.seq);
now = tk_xtime(tk);
mono = tk->wall_to_monotonic;
} while (read_seqcount_retry(&tk_core.seq, seq));
set_normalized_timespec64(&now, now.tv_sec + mono.tv_sec,
now.tv_nsec + mono.tv_nsec);
return now;
}
void do_timer(unsigned long ticks)
{
jiffies_64 += ticks;
calc_global_load(ticks);
}
ktime_t ktime_get_update_offsets_now(unsigned int *cwsseq, ktime_t *offs_real,
ktime_t *offs_boot, ktime_t *offs_tai)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned int seq;
ktime_t base;
u64 nsecs;
do {
seq = read_seqcount_begin(&tk_core.seq);
base = tk->tkr_mono.base;
nsecs = timekeeping_get_ns(&tk->tkr_mono);
base = ktime_add_ns(base, nsecs);
if (*cwsseq != tk->clock_was_set_seq) {
*cwsseq = tk->clock_was_set_seq;
*offs_real = tk->offs_real;
*offs_boot = tk->offs_boot;
*offs_tai = tk->offs_tai;
}
if (unlikely(base.tv64 >= tk->next_leap_ktime.tv64))
*offs_real = ktime_sub(tk->offs_real, ktime_set(1, 0));
} while (read_seqcount_retry(&tk_core.seq, seq));
return base;
}
int do_adjtimex(struct timex *txc)
{
struct timekeeper *tk = &tk_core.timekeeper;
unsigned long flags;
struct timespec64 ts;
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
getnstimeofday64(&ts);
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
orig_tai = tai = tk->tai_offset;
ret = __do_adjtimex(txc, &ts, &tai);
if (tai != orig_tai) {
__timekeeping_set_tai_offset(tk, tai);
timekeeping_update(tk, TK_MIRROR | TK_CLOCK_WAS_SET);
}
tk_update_leap_state(tk);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
if (tai != orig_tai)
clock_was_set();
ntp_notify_cmos_timer();
return ret;
}
void hardpps(const struct timespec64 *phase_ts, const struct timespec64 *raw_ts)
{
unsigned long flags;
raw_spin_lock_irqsave(&timekeeper_lock, flags);
write_seqcount_begin(&tk_core.seq);
__hardpps(phase_ts, raw_ts);
write_seqcount_end(&tk_core.seq);
raw_spin_unlock_irqrestore(&timekeeper_lock, flags);
}
void xtime_update(unsigned long ticks)
{
write_seqlock(&jiffies_lock);
do_timer(ticks);
write_sequnlock(&jiffies_lock);
update_wall_time();
}
