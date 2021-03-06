static inline s64 ntp_offset_chunk(s64 offset)
{
if (time_status & STA_PPSTIME && time_status & STA_PPSSIGNAL)
return offset;
else
return shift_right(offset, SHIFT_PLL + time_constant);
}
static inline void pps_reset_freq_interval(void)
{
pps_shift = PPS_INTMIN;
pps_intcnt = 0;
}
static inline void pps_clear(void)
{
pps_reset_freq_interval();
pps_tf[0] = 0;
pps_tf[1] = 0;
pps_tf[2] = 0;
pps_fbase.tv_sec = pps_fbase.tv_nsec = 0;
pps_freq = 0;
}
static inline void pps_dec_valid(void)
{
if (pps_valid > 0)
pps_valid--;
else {
time_status &= ~(STA_PPSSIGNAL | STA_PPSJITTER |
STA_PPSWANDER | STA_PPSERROR);
pps_clear();
}
}
static inline void pps_set_freq(s64 freq)
{
pps_freq = freq;
}
static inline int is_error_status(int status)
{
return (status & (STA_UNSYNC|STA_CLOCKERR))
|| ((status & (STA_PPSFREQ|STA_PPSTIME))
&& !(status & STA_PPSSIGNAL))
|| ((status & (STA_PPSTIME|STA_PPSJITTER))
== (STA_PPSTIME|STA_PPSJITTER))
|| ((status & STA_PPSFREQ)
&& (status & (STA_PPSWANDER|STA_PPSERROR)));
}
static inline void pps_fill_timex(struct timex *txc)
{
txc->ppsfreq = shift_right((pps_freq >> PPM_SCALE_INV_SHIFT) *
PPM_SCALE_INV, NTP_SCALE_SHIFT);
txc->jitter = pps_jitter;
if (!(time_status & STA_NANO))
txc->jitter /= NSEC_PER_USEC;
txc->shift = pps_shift;
txc->stabil = pps_stabil;
txc->jitcnt = pps_jitcnt;
txc->calcnt = pps_calcnt;
txc->errcnt = pps_errcnt;
txc->stbcnt = pps_stbcnt;
}
static inline s64 ntp_offset_chunk(s64 offset)
{
return shift_right(offset, SHIFT_PLL + time_constant);
}
static inline void pps_reset_freq_interval(void) {}
static inline void pps_clear(void) {}
static inline void pps_dec_valid(void) {}
static inline void pps_set_freq(s64 freq) {}
static inline int is_error_status(int status)
{
return status & (STA_UNSYNC|STA_CLOCKERR);
}
static inline void pps_fill_timex(struct timex *txc)
{
txc->ppsfreq = 0;
txc->jitter = 0;
txc->shift = 0;
txc->stabil = 0;
txc->jitcnt = 0;
txc->calcnt = 0;
txc->errcnt = 0;
txc->stbcnt = 0;
}
static inline int ntp_synced(void)
{
return !(time_status & STA_UNSYNC);
}
static void ntp_update_frequency(void)
{
u64 second_length;
u64 new_base;
second_length = (u64)(tick_usec * NSEC_PER_USEC * USER_HZ)
<< NTP_SCALE_SHIFT;
second_length += ntp_tick_adj;
second_length += time_freq;
tick_nsec = div_u64(second_length, HZ) >> NTP_SCALE_SHIFT;
new_base = div_u64(second_length, NTP_INTERVAL_FREQ);
tick_length += new_base - tick_length_base;
tick_length_base = new_base;
}
static inline s64 ntp_update_offset_fll(s64 offset64, long secs)
{
time_status &= ~STA_MODE;
if (secs < MINSEC)
return 0;
if (!(time_status & STA_FLL) && (secs <= MAXSEC))
return 0;
time_status |= STA_MODE;
return div64_long(offset64 << (NTP_SCALE_SHIFT - SHIFT_FLL), secs);
}
static void ntp_update_offset(long offset)
{
s64 freq_adj;
s64 offset64;
long secs;
if (!(time_status & STA_PLL))
return;
if (!(time_status & STA_NANO)) {
offset = clamp(offset, -USEC_PER_SEC, USEC_PER_SEC);
offset *= NSEC_PER_USEC;
}
offset = clamp(offset, -MAXPHASE, MAXPHASE);
secs = (long)(__ktime_get_real_seconds() - time_reftime);
if (unlikely(time_status & STA_FREQHOLD))
secs = 0;
time_reftime = __ktime_get_real_seconds();
offset64 = offset;
freq_adj = ntp_update_offset_fll(offset64, secs);
if (unlikely(secs > 1 << (SHIFT_PLL + 1 + time_constant)))
secs = 1 << (SHIFT_PLL + 1 + time_constant);
freq_adj += (offset64 * secs) <<
(NTP_SCALE_SHIFT - 2 * (SHIFT_PLL + 2 + time_constant));
freq_adj = min(freq_adj + time_freq, MAXFREQ_SCALED);
time_freq = max(freq_adj, -MAXFREQ_SCALED);
time_offset = div_s64(offset64 << NTP_SCALE_SHIFT, NTP_INTERVAL_FREQ);
}
void ntp_clear(void)
{
time_adjust = 0;
time_status |= STA_UNSYNC;
time_maxerror = NTP_PHASE_LIMIT;
time_esterror = NTP_PHASE_LIMIT;
ntp_update_frequency();
tick_length = tick_length_base;
time_offset = 0;
ntp_next_leap_sec = TIME64_MAX;
pps_clear();
}
u64 ntp_tick_length(void)
{
return tick_length;
}
ktime_t ntp_get_next_leap(void)
{
ktime_t ret;
if ((time_state == TIME_INS) && (time_status & STA_INS))
return ktime_set(ntp_next_leap_sec, 0);
ret = KTIME_MAX;
return ret;
}
int second_overflow(time64_t secs)
{
s64 delta;
int leap = 0;
s32 rem;
switch (time_state) {
case TIME_OK:
if (time_status & STA_INS) {
time_state = TIME_INS;
div_s64_rem(secs, SECS_PER_DAY, &rem);
ntp_next_leap_sec = secs + SECS_PER_DAY - rem;
} else if (time_status & STA_DEL) {
time_state = TIME_DEL;
div_s64_rem(secs + 1, SECS_PER_DAY, &rem);
ntp_next_leap_sec = secs + SECS_PER_DAY - rem;
}
break;
case TIME_INS:
if (!(time_status & STA_INS)) {
ntp_next_leap_sec = TIME64_MAX;
time_state = TIME_OK;
} else if (secs == ntp_next_leap_sec) {
leap = -1;
time_state = TIME_OOP;
printk(KERN_NOTICE
"Clock: inserting leap second 23:59:60 UTC\n");
}
break;
case TIME_DEL:
if (!(time_status & STA_DEL)) {
ntp_next_leap_sec = TIME64_MAX;
time_state = TIME_OK;
} else if (secs == ntp_next_leap_sec) {
leap = 1;
ntp_next_leap_sec = TIME64_MAX;
time_state = TIME_WAIT;
printk(KERN_NOTICE
"Clock: deleting leap second 23:59:59 UTC\n");
}
break;
case TIME_OOP:
ntp_next_leap_sec = TIME64_MAX;
time_state = TIME_WAIT;
break;
case TIME_WAIT:
if (!(time_status & (STA_INS | STA_DEL)))
time_state = TIME_OK;
break;
}
time_maxerror += MAXFREQ / NSEC_PER_USEC;
if (time_maxerror > NTP_PHASE_LIMIT) {
time_maxerror = NTP_PHASE_LIMIT;
time_status |= STA_UNSYNC;
}
tick_length = tick_length_base;
delta = ntp_offset_chunk(time_offset);
time_offset -= delta;
tick_length += delta;
pps_dec_valid();
if (!time_adjust)
goto out;
if (time_adjust > MAX_TICKADJ) {
time_adjust -= MAX_TICKADJ;
tick_length += MAX_TICKADJ_SCALED;
goto out;
}
if (time_adjust < -MAX_TICKADJ) {
time_adjust += MAX_TICKADJ;
tick_length -= MAX_TICKADJ_SCALED;
goto out;
}
tick_length += (s64)(time_adjust * NSEC_PER_USEC / NTP_INTERVAL_FREQ)
<< NTP_SCALE_SHIFT;
time_adjust = 0;
out:
return leap;
}
int __weak update_persistent_clock(struct timespec now)
{
return -ENODEV;
}
int __weak update_persistent_clock64(struct timespec64 now64)
{
struct timespec now;
now = timespec64_to_timespec(now64);
return update_persistent_clock(now);
}
static void sync_cmos_clock(struct work_struct *work)
{
struct timespec64 now;
struct timespec64 next;
int fail = 1;
if (!ntp_synced()) {
return;
}
getnstimeofday64(&now);
if (abs(now.tv_nsec - (NSEC_PER_SEC / 2)) <= tick_nsec * 5) {
struct timespec64 adjust = now;
fail = -ENODEV;
if (persistent_clock_is_local)
adjust.tv_sec -= (sys_tz.tz_minuteswest * 60);
#ifdef CONFIG_GENERIC_CMOS_UPDATE
fail = update_persistent_clock64(adjust);
#endif
#ifdef CONFIG_RTC_SYSTOHC
if (fail == -ENODEV)
fail = rtc_set_ntp_time(adjust);
#endif
}
next.tv_nsec = (NSEC_PER_SEC / 2) - now.tv_nsec - (TICK_NSEC / 2);
if (next.tv_nsec <= 0)
next.tv_nsec += NSEC_PER_SEC;
if (!fail || fail == -ENODEV)
next.tv_sec = 659;
else
next.tv_sec = 0;
if (next.tv_nsec >= NSEC_PER_SEC) {
next.tv_sec++;
next.tv_nsec -= NSEC_PER_SEC;
}
queue_delayed_work(system_power_efficient_wq,
&sync_cmos_work, timespec64_to_jiffies(&next));
}
void ntp_notify_cmos_timer(void)
{
queue_delayed_work(system_power_efficient_wq, &sync_cmos_work, 0);
}
void ntp_notify_cmos_timer(void) { }
static inline void process_adj_status(struct timex *txc, struct timespec64 *ts)
{
if ((time_status & STA_PLL) && !(txc->status & STA_PLL)) {
time_state = TIME_OK;
time_status = STA_UNSYNC;
ntp_next_leap_sec = TIME64_MAX;
pps_reset_freq_interval();
}
if (!(time_status & STA_PLL) && (txc->status & STA_PLL))
time_reftime = __ktime_get_real_seconds();
time_status &= STA_RONLY;
time_status |= txc->status & ~STA_RONLY;
}
static inline void process_adjtimex_modes(struct timex *txc,
struct timespec64 *ts,
s32 *time_tai)
{
if (txc->modes & ADJ_STATUS)
process_adj_status(txc, ts);
if (txc->modes & ADJ_NANO)
time_status |= STA_NANO;
if (txc->modes & ADJ_MICRO)
time_status &= ~STA_NANO;
if (txc->modes & ADJ_FREQUENCY) {
time_freq = txc->freq * PPM_SCALE;
time_freq = min(time_freq, MAXFREQ_SCALED);
time_freq = max(time_freq, -MAXFREQ_SCALED);
pps_set_freq(time_freq);
}
if (txc->modes & ADJ_MAXERROR)
time_maxerror = txc->maxerror;
if (txc->modes & ADJ_ESTERROR)
time_esterror = txc->esterror;
if (txc->modes & ADJ_TIMECONST) {
time_constant = txc->constant;
if (!(time_status & STA_NANO))
time_constant += 4;
time_constant = min(time_constant, (long)MAXTC);
time_constant = max(time_constant, 0l);
}
if (txc->modes & ADJ_TAI && txc->constant > 0)
*time_tai = txc->constant;
if (txc->modes & ADJ_OFFSET)
ntp_update_offset(txc->offset);
if (txc->modes & ADJ_TICK)
tick_usec = txc->tick;
if (txc->modes & (ADJ_TICK|ADJ_FREQUENCY|ADJ_OFFSET))
ntp_update_frequency();
}
int ntp_validate_timex(struct timex *txc)
{
if (txc->modes & ADJ_ADJTIME) {
if (!(txc->modes & ADJ_OFFSET_SINGLESHOT))
return -EINVAL;
if (!(txc->modes & ADJ_OFFSET_READONLY) &&
!capable(CAP_SYS_TIME))
return -EPERM;
} else {
if (txc->modes && !capable(CAP_SYS_TIME))
return -EPERM;
if (txc->modes & ADJ_TICK &&
(txc->tick < 900000/USER_HZ ||
txc->tick > 1100000/USER_HZ))
return -EINVAL;
}
if (txc->modes & ADJ_SETOFFSET) {
if (!capable(CAP_SYS_TIME))
return -EPERM;
if (txc->modes & ADJ_NANO) {
struct timespec ts;
ts.tv_sec = txc->time.tv_sec;
ts.tv_nsec = txc->time.tv_usec;
if (!timespec_inject_offset_valid(&ts))
return -EINVAL;
} else {
if (!timeval_inject_offset_valid(&txc->time))
return -EINVAL;
}
}
if ((txc->modes & ADJ_FREQUENCY) && (BITS_PER_LONG == 64)) {
if (LLONG_MIN / PPM_SCALE > txc->freq)
return -EINVAL;
if (LLONG_MAX / PPM_SCALE < txc->freq)
return -EINVAL;
}
return 0;
}
int __do_adjtimex(struct timex *txc, struct timespec64 *ts, s32 *time_tai)
{
int result;
if (txc->modes & ADJ_ADJTIME) {
long save_adjust = time_adjust;
if (!(txc->modes & ADJ_OFFSET_READONLY)) {
time_adjust = txc->offset;
ntp_update_frequency();
}
txc->offset = save_adjust;
} else {
if (txc->modes)
process_adjtimex_modes(txc, ts, time_tai);
txc->offset = shift_right(time_offset * NTP_INTERVAL_FREQ,
NTP_SCALE_SHIFT);
if (!(time_status & STA_NANO))
txc->offset /= NSEC_PER_USEC;
}
result = time_state;
if (is_error_status(time_status))
result = TIME_ERROR;
txc->freq = shift_right((time_freq >> PPM_SCALE_INV_SHIFT) *
PPM_SCALE_INV, NTP_SCALE_SHIFT);
txc->maxerror = time_maxerror;
txc->esterror = time_esterror;
txc->status = time_status;
txc->constant = time_constant;
txc->precision = 1;
txc->tolerance = MAXFREQ_SCALED / PPM_SCALE;
txc->tick = tick_usec;
txc->tai = *time_tai;
pps_fill_timex(txc);
txc->time.tv_sec = (time_t)ts->tv_sec;
txc->time.tv_usec = ts->tv_nsec;
if (!(time_status & STA_NANO))
txc->time.tv_usec /= NSEC_PER_USEC;
if (unlikely(ts->tv_sec >= ntp_next_leap_sec)) {
if ((time_state == TIME_INS) && (time_status & STA_INS)) {
result = TIME_OOP;
txc->tai++;
txc->time.tv_sec--;
}
if ((time_state == TIME_DEL) && (time_status & STA_DEL)) {
result = TIME_WAIT;
txc->tai--;
txc->time.tv_sec++;
}
if ((time_state == TIME_OOP) &&
(ts->tv_sec == ntp_next_leap_sec)) {
result = TIME_WAIT;
}
}
return result;
}
static inline struct pps_normtime pps_normalize_ts(struct timespec64 ts)
{
struct pps_normtime norm = {
.sec = ts.tv_sec,
.nsec = ts.tv_nsec
};
if (norm.nsec > (NSEC_PER_SEC >> 1)) {
norm.nsec -= NSEC_PER_SEC;
norm.sec++;
}
return norm;
}
static inline long pps_phase_filter_get(long *jitter)
{
*jitter = pps_tf[0] - pps_tf[1];
if (*jitter < 0)
*jitter = -*jitter;
return pps_tf[0];
}
static inline void pps_phase_filter_add(long err)
{
pps_tf[2] = pps_tf[1];
pps_tf[1] = pps_tf[0];
pps_tf[0] = err;
}
static inline void pps_dec_freq_interval(void)
{
if (--pps_intcnt <= -PPS_INTCOUNT) {
pps_intcnt = -PPS_INTCOUNT;
if (pps_shift > PPS_INTMIN) {
pps_shift--;
pps_intcnt = 0;
}
}
}
static inline void pps_inc_freq_interval(void)
{
if (++pps_intcnt >= PPS_INTCOUNT) {
pps_intcnt = PPS_INTCOUNT;
if (pps_shift < PPS_INTMAX) {
pps_shift++;
pps_intcnt = 0;
}
}
}
static long hardpps_update_freq(struct pps_normtime freq_norm)
{
long delta, delta_mod;
s64 ftemp;
if (freq_norm.sec > (2 << pps_shift)) {
time_status |= STA_PPSERROR;
pps_errcnt++;
pps_dec_freq_interval();
printk_deferred(KERN_ERR
"hardpps: PPSERROR: interval too long - %lld s\n",
freq_norm.sec);
return 0;
}
ftemp = div_s64(((s64)(-freq_norm.nsec)) << NTP_SCALE_SHIFT,
freq_norm.sec);
delta = shift_right(ftemp - pps_freq, NTP_SCALE_SHIFT);
pps_freq = ftemp;
if (delta > PPS_MAXWANDER || delta < -PPS_MAXWANDER) {
printk_deferred(KERN_WARNING
"hardpps: PPSWANDER: change=%ld\n", delta);
time_status |= STA_PPSWANDER;
pps_stbcnt++;
pps_dec_freq_interval();
} else {
pps_inc_freq_interval();
}
delta_mod = delta;
if (delta_mod < 0)
delta_mod = -delta_mod;
pps_stabil += (div_s64(((s64)delta_mod) <<
(NTP_SCALE_SHIFT - SHIFT_USEC),
NSEC_PER_USEC) - pps_stabil) >> PPS_INTMIN;
if ((time_status & STA_PPSFREQ) != 0 &&
(time_status & STA_FREQHOLD) == 0) {
time_freq = pps_freq;
ntp_update_frequency();
}
return delta;
}
static void hardpps_update_phase(long error)
{
long correction = -error;
long jitter;
pps_phase_filter_add(correction);
correction = pps_phase_filter_get(&jitter);
if (jitter > (pps_jitter << PPS_POPCORN)) {
printk_deferred(KERN_WARNING
"hardpps: PPSJITTER: jitter=%ld, limit=%ld\n",
jitter, (pps_jitter << PPS_POPCORN));
time_status |= STA_PPSJITTER;
pps_jitcnt++;
} else if (time_status & STA_PPSTIME) {
time_offset = div_s64(((s64)correction) << NTP_SCALE_SHIFT,
NTP_INTERVAL_FREQ);
time_adjust = 0;
}
pps_jitter += (jitter - pps_jitter) >> PPS_INTMIN;
}
void __hardpps(const struct timespec64 *phase_ts, const struct timespec64 *raw_ts)
{
struct pps_normtime pts_norm, freq_norm;
pts_norm = pps_normalize_ts(*phase_ts);
time_status &= ~(STA_PPSJITTER | STA_PPSWANDER | STA_PPSERROR);
time_status |= STA_PPSSIGNAL;
pps_valid = PPS_VALID;
if (unlikely(pps_fbase.tv_sec == 0)) {
pps_fbase = *raw_ts;
return;
}
freq_norm = pps_normalize_ts(timespec64_sub(*raw_ts, pps_fbase));
if ((freq_norm.sec == 0) ||
(freq_norm.nsec > MAXFREQ * freq_norm.sec) ||
(freq_norm.nsec < -MAXFREQ * freq_norm.sec)) {
time_status |= STA_PPSJITTER;
pps_fbase = *raw_ts;
printk_deferred(KERN_ERR "hardpps: PPSJITTER: bad pulse\n");
return;
}
if (freq_norm.sec >= (1 << pps_shift)) {
pps_calcnt++;
pps_fbase = *raw_ts;
hardpps_update_freq(freq_norm);
}
hardpps_update_phase(pts_norm.nsec);
}
static int __init ntp_tick_adj_setup(char *str)
{
int rc = kstrtol(str, 0, (long *)&ntp_tick_adj);
if (rc)
return rc;
ntp_tick_adj <<= NTP_SCALE_SHIFT;
return 1;
}
void __init ntp_init(void)
{
ntp_clear();
}
