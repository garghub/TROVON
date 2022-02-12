static struct timeval itimer_get_remtime(struct hrtimer *timer)
{
ktime_t rem = __hrtimer_get_remaining(timer, true);
if (hrtimer_active(timer)) {
if (rem <= 0)
rem = NSEC_PER_USEC;
} else
rem = 0;
return ktime_to_timeval(rem);
}
static void get_cpu_itimer(struct task_struct *tsk, unsigned int clock_id,
struct itimerval *const value)
{
u64 val, interval;
struct cpu_itimer *it = &tsk->signal->it[clock_id];
spin_lock_irq(&tsk->sighand->siglock);
val = it->expires;
interval = it->incr;
if (val) {
struct task_cputime cputime;
u64 t;
thread_group_cputimer(tsk, &cputime);
if (clock_id == CPUCLOCK_PROF)
t = cputime.utime + cputime.stime;
else
t = cputime.utime;
if (val < t)
val = TICK_NSEC;
else
val -= t;
}
spin_unlock_irq(&tsk->sighand->siglock);
value->it_value = ns_to_timeval(val);
value->it_interval = ns_to_timeval(interval);
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
static void set_cpu_itimer(struct task_struct *tsk, unsigned int clock_id,
const struct itimerval *const value,
struct itimerval *const ovalue)
{
u64 oval, nval, ointerval, ninterval;
struct cpu_itimer *it = &tsk->signal->it[clock_id];
nval = timeval_to_ns(&value->it_value);
ninterval = timeval_to_ns(&value->it_interval);
spin_lock_irq(&tsk->sighand->siglock);
oval = it->expires;
ointerval = it->incr;
if (oval || nval) {
if (nval > 0)
nval += TICK_NSEC;
set_process_cpu_timer(tsk, clock_id, &nval, &oval);
}
it->expires = nval;
it->incr = ninterval;
trace_itimer_state(clock_id == CPUCLOCK_VIRT ?
ITIMER_VIRTUAL : ITIMER_PROF, value, nval);
spin_unlock_irq(&tsk->sighand->siglock);
if (ovalue) {
ovalue->it_value = ns_to_timeval(oval);
ovalue->it_interval = ns_to_timeval(ointerval);
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
if (expires != 0) {
tsk->signal->it_real_incr =
timeval_to_ktime(value->it_interval);
hrtimer_start(timer, expires, HRTIMER_MODE_REL);
} else
tsk->signal->it_real_incr = 0;
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
static unsigned int alarm_setitimer(unsigned int seconds)
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
