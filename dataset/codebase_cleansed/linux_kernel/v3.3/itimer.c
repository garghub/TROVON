static struct timeval itimer_get_remtime(struct hrtimer *timer)
{
ktime_t rem = hrtimer_get_remaining(timer);
if (hrtimer_active(timer)) {
if (rem.tv64 <= 0)
rem.tv64 = NSEC_PER_USEC;
} else
rem.tv64 = 0;
return ktime_to_timeval(rem);
}
static void get_cpu_itimer(struct task_struct *tsk, unsigned int clock_id,
struct itimerval *const value)
{
cputime_t cval, cinterval;
struct cpu_itimer *it = &tsk->signal->it[clock_id];
spin_lock_irq(&tsk->sighand->siglock);
cval = it->expires;
cinterval = it->incr;
if (cval) {
struct task_cputime cputime;
cputime_t t;
thread_group_cputimer(tsk, &cputime);
if (clock_id == CPUCLOCK_PROF)
t = cputime.utime + cputime.stime;
else
t = cputime.utime;
if (cval < t)
cval = cputime_one_jiffy;
else
cval = cval - t;
}
spin_unlock_irq(&tsk->sighand->siglock);
cputime_to_timeval(cval, &value->it_value);
cputime_to_timeval(cinterval, &value->it_interval);
}
int do_getitimer(int which, struct itimerval *value)
{
struct task_struct *tsk = current;
switch (which) {
case ITIMER_REAL:
spin_lock_irq(&tsk->sighand->siglock);
value->it_value = itimer_get_remtime(&tsk->signal->real_timer);
value->it_interval =
ktime_to_timeval(tsk->signal->it_real_incr);
spin_unlock_irq(&tsk->sighand->siglock);
break;
case ITIMER_VIRTUAL:
get_cpu_itimer(tsk, CPUCLOCK_VIRT, value);
break;
case ITIMER_PROF:
get_cpu_itimer(tsk, CPUCLOCK_PROF, value);
break;
default:
return(-EINVAL);
}
return 0;
}
enum hrtimer_restart it_real_fn(struct hrtimer *timer)
{
struct signal_struct *sig =
container_of(timer, struct signal_struct, real_timer);
trace_itimer_expire(ITIMER_REAL, sig->leader_pid, 0);
kill_pid_info(SIGALRM, SEND_SIG_PRIV, sig->leader_pid);
return HRTIMER_NORESTART;
}
static inline u32 cputime_sub_ns(cputime_t ct, s64 real_ns)
{
struct timespec ts;
s64 cpu_ns;
cputime_to_timespec(ct, &ts);
cpu_ns = timespec_to_ns(&ts);
return (cpu_ns <= real_ns) ? 0 : cpu_ns - real_ns;
}
static void set_cpu_itimer(struct task_struct *tsk, unsigned int clock_id,
const struct itimerval *const value,
struct itimerval *const ovalue)
{
cputime_t cval, nval, cinterval, ninterval;
s64 ns_ninterval, ns_nval;
u32 error, incr_error;
struct cpu_itimer *it = &tsk->signal->it[clock_id];
nval = timeval_to_cputime(&value->it_value);
ns_nval = timeval_to_ns(&value->it_value);
ninterval = timeval_to_cputime(&value->it_interval);
ns_ninterval = timeval_to_ns(&value->it_interval);
error = cputime_sub_ns(nval, ns_nval);
incr_error = cputime_sub_ns(ninterval, ns_ninterval);
spin_lock_irq(&tsk->sighand->siglock);
cval = it->expires;
cinterval = it->incr;
if (cval || nval) {
if (nval > 0)
nval += cputime_one_jiffy;
set_process_cpu_timer(tsk, clock_id, &nval, &cval);
}
it->expires = nval;
it->incr = ninterval;
it->error = error;
it->incr_error = incr_error;
trace_itimer_state(clock_id == CPUCLOCK_VIRT ?
ITIMER_VIRTUAL : ITIMER_PROF, value, nval);
spin_unlock_irq(&tsk->sighand->siglock);
if (ovalue) {
cputime_to_timeval(cval, &ovalue->it_value);
cputime_to_timeval(cinterval, &ovalue->it_interval);
}
}
int do_setitimer(int which, struct itimerval *value, struct itimerval *ovalue)
{
struct task_struct *tsk = current;
struct hrtimer *timer;
ktime_t expires;
if (!timeval_valid(&value->it_value) ||
!timeval_valid(&value->it_interval))
return -EINVAL;
switch (which) {
case ITIMER_REAL:
again:
spin_lock_irq(&tsk->sighand->siglock);
timer = &tsk->signal->real_timer;
if (ovalue) {
ovalue->it_value = itimer_get_remtime(timer);
ovalue->it_interval
= ktime_to_timeval(tsk->signal->it_real_incr);
}
if (hrtimer_try_to_cancel(timer) < 0) {
spin_unlock_irq(&tsk->sighand->siglock);
goto again;
}
expires = timeval_to_ktime(value->it_value);
if (expires.tv64 != 0) {
tsk->signal->it_real_incr =
timeval_to_ktime(value->it_interval);
hrtimer_start(timer, expires, HRTIMER_MODE_REL);
} else
tsk->signal->it_real_incr.tv64 = 0;
trace_itimer_state(ITIMER_REAL, value, 0);
spin_unlock_irq(&tsk->sighand->siglock);
break;
case ITIMER_VIRTUAL:
set_cpu_itimer(tsk, CPUCLOCK_VIRT, value, ovalue);
break;
case ITIMER_PROF:
set_cpu_itimer(tsk, CPUCLOCK_PROF, value, ovalue);
break;
default:
return -EINVAL;
}
return 0;
}
unsigned int alarm_setitimer(unsigned int seconds)
{
struct itimerval it_new, it_old;
#if BITS_PER_LONG < 64
if (seconds > INT_MAX)
seconds = INT_MAX;
#endif
it_new.it_value.tv_sec = seconds;
it_new.it_value.tv_usec = 0;
it_new.it_interval.tv_sec = it_new.it_interval.tv_usec = 0;
do_setitimer(ITIMER_REAL, &it_new, &it_old);
if ((!it_old.it_value.tv_sec && it_old.it_value.tv_usec) ||
it_old.it_value.tv_usec >= 500000)
it_old.it_value.tv_sec++;
return it_old.it_value.tv_sec;
}
