void update_rlimit_cpu(struct task_struct *task, unsigned long rlim_new)
{
cputime_t cputime = secs_to_cputime(rlim_new);
spin_lock_irq(&task->sighand->siglock);
set_process_cpu_timer(task, CPUCLOCK_PROF, &cputime, NULL);
spin_unlock_irq(&task->sighand->siglock);
}
static int check_clock(const clockid_t which_clock)
{
int error = 0;
struct task_struct *p;
const pid_t pid = CPUCLOCK_PID(which_clock);
if (CPUCLOCK_WHICH(which_clock) >= CPUCLOCK_MAX)
return -EINVAL;
if (pid == 0)
return 0;
rcu_read_lock();
p = find_task_by_vpid(pid);
if (!p || !(CPUCLOCK_PERTHREAD(which_clock) ?
same_thread_group(p, current) : has_group_leader_pid(p))) {
error = -EINVAL;
}
rcu_read_unlock();
return error;
}
static inline unsigned long long
timespec_to_sample(const clockid_t which_clock, const struct timespec *tp)
{
unsigned long long ret;
ret = 0;
if (CPUCLOCK_WHICH(which_clock) == CPUCLOCK_SCHED) {
ret = (unsigned long long)tp->tv_sec * NSEC_PER_SEC + tp->tv_nsec;
} else {
ret = cputime_to_expires(timespec_to_cputime(tp));
}
return ret;
}
static void sample_to_timespec(const clockid_t which_clock,
unsigned long long expires,
struct timespec *tp)
{
if (CPUCLOCK_WHICH(which_clock) == CPUCLOCK_SCHED)
*tp = ns_to_timespec(expires);
else
cputime_to_timespec((__force cputime_t)expires, tp);
}
static void bump_cpu_timer(struct k_itimer *timer,
unsigned long long now)
{
int i;
unsigned long long delta, incr;
if (timer->it.cpu.incr == 0)
return;
if (now < timer->it.cpu.expires)
return;
incr = timer->it.cpu.incr;
delta = now + incr - timer->it.cpu.expires;
for (i = 0; incr < delta - incr; i++)
incr = incr << 1;
for (; i >= 0; incr >>= 1, i--) {
if (delta < incr)
continue;
timer->it.cpu.expires += incr;
timer->it_overrun += 1 << i;
delta -= incr;
}
}
static inline int task_cputime_zero(const struct task_cputime *cputime)
{
if (!cputime->utime && !cputime->stime && !cputime->sum_exec_runtime)
return 1;
return 0;
}
static inline unsigned long long prof_ticks(struct task_struct *p)
{
cputime_t utime, stime;
task_cputime(p, &utime, &stime);
return cputime_to_expires(utime + stime);
}
static inline unsigned long long virt_ticks(struct task_struct *p)
{
cputime_t utime, stime;
task_cputime(p, &utime, &stime);
return cputime_to_expires(utime);
}
static int
posix_cpu_clock_getres(const clockid_t which_clock, struct timespec *tp)
{
int error = check_clock(which_clock);
if (!error) {
tp->tv_sec = 0;
tp->tv_nsec = ((NSEC_PER_SEC + HZ - 1) / HZ);
if (CPUCLOCK_WHICH(which_clock) == CPUCLOCK_SCHED) {
tp->tv_nsec = 1;
}
}
return error;
}
static int
posix_cpu_clock_set(const clockid_t which_clock, const struct timespec *tp)
{
int error = check_clock(which_clock);
if (error == 0) {
error = -EPERM;
}
return error;
}
static int cpu_clock_sample(const clockid_t which_clock, struct task_struct *p,
unsigned long long *sample)
{
switch (CPUCLOCK_WHICH(which_clock)) {
default:
return -EINVAL;
case CPUCLOCK_PROF:
*sample = prof_ticks(p);
break;
case CPUCLOCK_VIRT:
*sample = virt_ticks(p);
break;
case CPUCLOCK_SCHED:
*sample = task_sched_runtime(p);
break;
}
return 0;
}
static inline void __update_gt_cputime(atomic64_t *cputime, u64 sum_cputime)
{
u64 curr_cputime;
retry:
curr_cputime = atomic64_read(cputime);
if (sum_cputime > curr_cputime) {
if (atomic64_cmpxchg(cputime, curr_cputime, sum_cputime) != curr_cputime)
goto retry;
}
}
static void update_gt_cputime(struct task_cputime_atomic *cputime_atomic, struct task_cputime *sum)
{
__update_gt_cputime(&cputime_atomic->utime, sum->utime);
__update_gt_cputime(&cputime_atomic->stime, sum->stime);
__update_gt_cputime(&cputime_atomic->sum_exec_runtime, sum->sum_exec_runtime);
}
static inline void sample_cputime_atomic(struct task_cputime *times,
struct task_cputime_atomic *atomic_times)
{
times->utime = atomic64_read(&atomic_times->utime);
times->stime = atomic64_read(&atomic_times->stime);
times->sum_exec_runtime = atomic64_read(&atomic_times->sum_exec_runtime);
}
void thread_group_cputimer(struct task_struct *tsk, struct task_cputime *times)
{
struct thread_group_cputimer *cputimer = &tsk->signal->cputimer;
struct task_cputime sum;
if (!READ_ONCE(cputimer->running)) {
thread_group_cputime(tsk, &sum);
update_gt_cputime(&cputimer->cputime_atomic, &sum);
WRITE_ONCE(cputimer->running, true);
}
sample_cputime_atomic(times, &cputimer->cputime_atomic);
}
static int cpu_clock_sample_group(const clockid_t which_clock,
struct task_struct *p,
unsigned long long *sample)
{
struct task_cputime cputime;
switch (CPUCLOCK_WHICH(which_clock)) {
default:
return -EINVAL;
case CPUCLOCK_PROF:
thread_group_cputime(p, &cputime);
*sample = cputime_to_expires(cputime.utime + cputime.stime);
break;
case CPUCLOCK_VIRT:
thread_group_cputime(p, &cputime);
*sample = cputime_to_expires(cputime.utime);
break;
case CPUCLOCK_SCHED:
thread_group_cputime(p, &cputime);
*sample = cputime.sum_exec_runtime;
break;
}
return 0;
}
static int posix_cpu_clock_get_task(struct task_struct *tsk,
const clockid_t which_clock,
struct timespec *tp)
{
int err = -EINVAL;
unsigned long long rtn;
if (CPUCLOCK_PERTHREAD(which_clock)) {
if (same_thread_group(tsk, current))
err = cpu_clock_sample(which_clock, tsk, &rtn);
} else {
if (tsk == current || thread_group_leader(tsk))
err = cpu_clock_sample_group(which_clock, tsk, &rtn);
}
if (!err)
sample_to_timespec(which_clock, rtn, tp);
return err;
}
static int posix_cpu_clock_get(const clockid_t which_clock, struct timespec *tp)
{
const pid_t pid = CPUCLOCK_PID(which_clock);
int err = -EINVAL;
if (pid == 0) {
err = posix_cpu_clock_get_task(current, which_clock, tp);
} else {
struct task_struct *p;
rcu_read_lock();
p = find_task_by_vpid(pid);
if (p)
err = posix_cpu_clock_get_task(p, which_clock, tp);
rcu_read_unlock();
}
return err;
}
static int posix_cpu_timer_create(struct k_itimer *new_timer)
{
int ret = 0;
const pid_t pid = CPUCLOCK_PID(new_timer->it_clock);
struct task_struct *p;
if (CPUCLOCK_WHICH(new_timer->it_clock) >= CPUCLOCK_MAX)
return -EINVAL;
INIT_LIST_HEAD(&new_timer->it.cpu.entry);
rcu_read_lock();
if (CPUCLOCK_PERTHREAD(new_timer->it_clock)) {
if (pid == 0) {
p = current;
} else {
p = find_task_by_vpid(pid);
if (p && !same_thread_group(p, current))
p = NULL;
}
} else {
if (pid == 0) {
p = current->group_leader;
} else {
p = find_task_by_vpid(pid);
if (p && !has_group_leader_pid(p))
p = NULL;
}
}
new_timer->it.cpu.task = p;
if (p) {
get_task_struct(p);
} else {
ret = -EINVAL;
}
rcu_read_unlock();
return ret;
}
static int posix_cpu_timer_del(struct k_itimer *timer)
{
int ret = 0;
unsigned long flags;
struct sighand_struct *sighand;
struct task_struct *p = timer->it.cpu.task;
WARN_ON_ONCE(p == NULL);
sighand = lock_task_sighand(p, &flags);
if (unlikely(sighand == NULL)) {
WARN_ON_ONCE(!list_empty(&timer->it.cpu.entry));
} else {
if (timer->it.cpu.firing)
ret = TIMER_RETRY;
else
list_del(&timer->it.cpu.entry);
unlock_task_sighand(p, &flags);
}
if (!ret)
put_task_struct(p);
return ret;
}
static void cleanup_timers_list(struct list_head *head)
{
struct cpu_timer_list *timer, *next;
list_for_each_entry_safe(timer, next, head, entry)
list_del_init(&timer->entry);
}
static void cleanup_timers(struct list_head *head)
{
cleanup_timers_list(head);
cleanup_timers_list(++head);
cleanup_timers_list(++head);
}
void posix_cpu_timers_exit(struct task_struct *tsk)
{
cleanup_timers(tsk->cpu_timers);
}
void posix_cpu_timers_exit_group(struct task_struct *tsk)
{
cleanup_timers(tsk->signal->cpu_timers);
}
static inline int expires_gt(cputime_t expires, cputime_t new_exp)
{
return expires == 0 || expires > new_exp;
}
static void arm_timer(struct k_itimer *timer)
{
struct task_struct *p = timer->it.cpu.task;
struct list_head *head, *listpos;
struct task_cputime *cputime_expires;
struct cpu_timer_list *const nt = &timer->it.cpu;
struct cpu_timer_list *next;
if (CPUCLOCK_PERTHREAD(timer->it_clock)) {
head = p->cpu_timers;
cputime_expires = &p->cputime_expires;
} else {
head = p->signal->cpu_timers;
cputime_expires = &p->signal->cputime_expires;
}
head += CPUCLOCK_WHICH(timer->it_clock);
listpos = head;
list_for_each_entry(next, head, entry) {
if (nt->expires < next->expires)
break;
listpos = &next->entry;
}
list_add(&nt->entry, listpos);
if (listpos == head) {
unsigned long long exp = nt->expires;
switch (CPUCLOCK_WHICH(timer->it_clock)) {
case CPUCLOCK_PROF:
if (expires_gt(cputime_expires->prof_exp, expires_to_cputime(exp)))
cputime_expires->prof_exp = expires_to_cputime(exp);
break;
case CPUCLOCK_VIRT:
if (expires_gt(cputime_expires->virt_exp, expires_to_cputime(exp)))
cputime_expires->virt_exp = expires_to_cputime(exp);
break;
case CPUCLOCK_SCHED:
if (cputime_expires->sched_exp == 0 ||
cputime_expires->sched_exp > exp)
cputime_expires->sched_exp = exp;
break;
}
if (CPUCLOCK_PERTHREAD(timer->it_clock))
tick_dep_set_task(p, TICK_DEP_BIT_POSIX_TIMER);
else
tick_dep_set_signal(p->signal, TICK_DEP_BIT_POSIX_TIMER);
}
}
static void cpu_timer_fire(struct k_itimer *timer)
{
if ((timer->it_sigev_notify & ~SIGEV_THREAD_ID) == SIGEV_NONE) {
timer->it.cpu.expires = 0;
} else if (unlikely(timer->sigq == NULL)) {
wake_up_process(timer->it_process);
timer->it.cpu.expires = 0;
} else if (timer->it.cpu.incr == 0) {
posix_timer_event(timer, 0);
timer->it.cpu.expires = 0;
} else if (posix_timer_event(timer, ++timer->it_requeue_pending)) {
posix_cpu_timer_schedule(timer);
}
}
static int cpu_timer_sample_group(const clockid_t which_clock,
struct task_struct *p,
unsigned long long *sample)
{
struct task_cputime cputime;
thread_group_cputimer(p, &cputime);
switch (CPUCLOCK_WHICH(which_clock)) {
default:
return -EINVAL;
case CPUCLOCK_PROF:
*sample = cputime_to_expires(cputime.utime + cputime.stime);
break;
case CPUCLOCK_VIRT:
*sample = cputime_to_expires(cputime.utime);
break;
case CPUCLOCK_SCHED:
*sample = cputime.sum_exec_runtime;
break;
}
return 0;
}
static int posix_cpu_timer_set(struct k_itimer *timer, int timer_flags,
struct itimerspec *new, struct itimerspec *old)
{
unsigned long flags;
struct sighand_struct *sighand;
struct task_struct *p = timer->it.cpu.task;
unsigned long long old_expires, new_expires, old_incr, val;
int ret;
WARN_ON_ONCE(p == NULL);
new_expires = timespec_to_sample(timer->it_clock, &new->it_value);
sighand = lock_task_sighand(p, &flags);
if (unlikely(sighand == NULL)) {
return -ESRCH;
}
WARN_ON_ONCE(!irqs_disabled());
ret = 0;
old_incr = timer->it.cpu.incr;
old_expires = timer->it.cpu.expires;
if (unlikely(timer->it.cpu.firing)) {
timer->it.cpu.firing = -1;
ret = TIMER_RETRY;
} else
list_del_init(&timer->it.cpu.entry);
if (CPUCLOCK_PERTHREAD(timer->it_clock)) {
cpu_clock_sample(timer->it_clock, p, &val);
} else {
cpu_timer_sample_group(timer->it_clock, p, &val);
}
if (old) {
if (old_expires == 0) {
old->it_value.tv_sec = 0;
old->it_value.tv_nsec = 0;
} else {
bump_cpu_timer(timer, val);
if (val < timer->it.cpu.expires) {
old_expires = timer->it.cpu.expires - val;
sample_to_timespec(timer->it_clock,
old_expires,
&old->it_value);
} else {
old->it_value.tv_nsec = 1;
old->it_value.tv_sec = 0;
}
}
}
if (unlikely(ret)) {
unlock_task_sighand(p, &flags);
goto out;
}
if (new_expires != 0 && !(timer_flags & TIMER_ABSTIME)) {
new_expires += val;
}
timer->it.cpu.expires = new_expires;
if (new_expires != 0 && val < new_expires) {
arm_timer(timer);
}
unlock_task_sighand(p, &flags);
timer->it.cpu.incr = timespec_to_sample(timer->it_clock,
&new->it_interval);
timer->it_requeue_pending = (timer->it_requeue_pending + 2) &
~REQUEUE_PENDING;
timer->it_overrun_last = 0;
timer->it_overrun = -1;
if (new_expires != 0 && !(val < new_expires)) {
cpu_timer_fire(timer);
}
ret = 0;
out:
if (old) {
sample_to_timespec(timer->it_clock,
old_incr, &old->it_interval);
}
return ret;
}
static void posix_cpu_timer_get(struct k_itimer *timer, struct itimerspec *itp)
{
unsigned long long now;
struct task_struct *p = timer->it.cpu.task;
WARN_ON_ONCE(p == NULL);
sample_to_timespec(timer->it_clock,
timer->it.cpu.incr, &itp->it_interval);
if (timer->it.cpu.expires == 0) {
itp->it_value.tv_sec = itp->it_value.tv_nsec = 0;
return;
}
if (CPUCLOCK_PERTHREAD(timer->it_clock)) {
cpu_clock_sample(timer->it_clock, p, &now);
} else {
struct sighand_struct *sighand;
unsigned long flags;
sighand = lock_task_sighand(p, &flags);
if (unlikely(sighand == NULL)) {
timer->it.cpu.expires = 0;
sample_to_timespec(timer->it_clock, timer->it.cpu.expires,
&itp->it_value);
return;
} else {
cpu_timer_sample_group(timer->it_clock, p, &now);
unlock_task_sighand(p, &flags);
}
}
if (now < timer->it.cpu.expires) {
sample_to_timespec(timer->it_clock,
timer->it.cpu.expires - now,
&itp->it_value);
} else {
itp->it_value.tv_nsec = 1;
itp->it_value.tv_sec = 0;
}
}
static unsigned long long
check_timers_list(struct list_head *timers,
struct list_head *firing,
unsigned long long curr)
{
int maxfire = 20;
while (!list_empty(timers)) {
struct cpu_timer_list *t;
t = list_first_entry(timers, struct cpu_timer_list, entry);
if (!--maxfire || curr < t->expires)
return t->expires;
t->firing = 1;
list_move_tail(&t->entry, firing);
}
return 0;
}
static void check_thread_timers(struct task_struct *tsk,
struct list_head *firing)
{
struct list_head *timers = tsk->cpu_timers;
struct signal_struct *const sig = tsk->signal;
struct task_cputime *tsk_expires = &tsk->cputime_expires;
unsigned long long expires;
unsigned long soft;
if (task_cputime_zero(&tsk->cputime_expires))
return;
expires = check_timers_list(timers, firing, prof_ticks(tsk));
tsk_expires->prof_exp = expires_to_cputime(expires);
expires = check_timers_list(++timers, firing, virt_ticks(tsk));
tsk_expires->virt_exp = expires_to_cputime(expires);
tsk_expires->sched_exp = check_timers_list(++timers, firing,
tsk->se.sum_exec_runtime);
soft = READ_ONCE(sig->rlim[RLIMIT_RTTIME].rlim_cur);
if (soft != RLIM_INFINITY) {
unsigned long hard =
READ_ONCE(sig->rlim[RLIMIT_RTTIME].rlim_max);
if (hard != RLIM_INFINITY &&
tsk->rt.timeout > DIV_ROUND_UP(hard, USEC_PER_SEC/HZ)) {
__group_send_sig_info(SIGKILL, SEND_SIG_PRIV, tsk);
return;
}
if (tsk->rt.timeout > DIV_ROUND_UP(soft, USEC_PER_SEC/HZ)) {
if (soft < hard) {
soft += USEC_PER_SEC;
sig->rlim[RLIMIT_RTTIME].rlim_cur = soft;
}
printk(KERN_INFO
"RT Watchdog Timeout: %s[%d]\n",
tsk->comm, task_pid_nr(tsk));
__group_send_sig_info(SIGXCPU, SEND_SIG_PRIV, tsk);
}
}
if (task_cputime_zero(tsk_expires))
tick_dep_clear_task(tsk, TICK_DEP_BIT_POSIX_TIMER);
}
static inline void stop_process_timers(struct signal_struct *sig)
{
struct thread_group_cputimer *cputimer = &sig->cputimer;
WRITE_ONCE(cputimer->running, false);
tick_dep_clear_signal(sig, TICK_DEP_BIT_POSIX_TIMER);
}
static void check_cpu_itimer(struct task_struct *tsk, struct cpu_itimer *it,
unsigned long long *expires,
unsigned long long cur_time, int signo)
{
if (!it->expires)
return;
if (cur_time >= it->expires) {
if (it->incr) {
it->expires += it->incr;
it->error += it->incr_error;
if (it->error >= onecputick) {
it->expires -= cputime_one_jiffy;
it->error -= onecputick;
}
} else {
it->expires = 0;
}
trace_itimer_expire(signo == SIGPROF ?
ITIMER_PROF : ITIMER_VIRTUAL,
tsk->signal->leader_pid, cur_time);
__group_send_sig_info(signo, SEND_SIG_PRIV, tsk);
}
if (it->expires && (!*expires || it->expires < *expires)) {
*expires = it->expires;
}
}
static void check_process_timers(struct task_struct *tsk,
struct list_head *firing)
{
struct signal_struct *const sig = tsk->signal;
unsigned long long utime, ptime, virt_expires, prof_expires;
unsigned long long sum_sched_runtime, sched_expires;
struct list_head *timers = sig->cpu_timers;
struct task_cputime cputime;
unsigned long soft;
if (!READ_ONCE(tsk->signal->cputimer.running))
return;
sig->cputimer.checking_timer = true;
thread_group_cputimer(tsk, &cputime);
utime = cputime_to_expires(cputime.utime);
ptime = utime + cputime_to_expires(cputime.stime);
sum_sched_runtime = cputime.sum_exec_runtime;
prof_expires = check_timers_list(timers, firing, ptime);
virt_expires = check_timers_list(++timers, firing, utime);
sched_expires = check_timers_list(++timers, firing, sum_sched_runtime);
check_cpu_itimer(tsk, &sig->it[CPUCLOCK_PROF], &prof_expires, ptime,
SIGPROF);
check_cpu_itimer(tsk, &sig->it[CPUCLOCK_VIRT], &virt_expires, utime,
SIGVTALRM);
soft = READ_ONCE(sig->rlim[RLIMIT_CPU].rlim_cur);
if (soft != RLIM_INFINITY) {
unsigned long psecs = cputime_to_secs(ptime);
unsigned long hard =
READ_ONCE(sig->rlim[RLIMIT_CPU].rlim_max);
cputime_t x;
if (psecs >= hard) {
__group_send_sig_info(SIGKILL, SEND_SIG_PRIV, tsk);
return;
}
if (psecs >= soft) {
__group_send_sig_info(SIGXCPU, SEND_SIG_PRIV, tsk);
if (soft < hard) {
soft++;
sig->rlim[RLIMIT_CPU].rlim_cur = soft;
}
}
x = secs_to_cputime(soft);
if (!prof_expires || x < prof_expires) {
prof_expires = x;
}
}
sig->cputime_expires.prof_exp = expires_to_cputime(prof_expires);
sig->cputime_expires.virt_exp = expires_to_cputime(virt_expires);
sig->cputime_expires.sched_exp = sched_expires;
if (task_cputime_zero(&sig->cputime_expires))
stop_process_timers(sig);
sig->cputimer.checking_timer = false;
}
void posix_cpu_timer_schedule(struct k_itimer *timer)
{
struct sighand_struct *sighand;
unsigned long flags;
struct task_struct *p = timer->it.cpu.task;
unsigned long long now;
WARN_ON_ONCE(p == NULL);
if (CPUCLOCK_PERTHREAD(timer->it_clock)) {
cpu_clock_sample(timer->it_clock, p, &now);
bump_cpu_timer(timer, now);
if (unlikely(p->exit_state))
goto out;
sighand = lock_task_sighand(p, &flags);
if (!sighand)
goto out;
} else {
sighand = lock_task_sighand(p, &flags);
if (unlikely(sighand == NULL)) {
timer->it.cpu.expires = 0;
goto out;
} else if (unlikely(p->exit_state) && thread_group_empty(p)) {
unlock_task_sighand(p, &flags);
goto out;
}
cpu_timer_sample_group(timer->it_clock, p, &now);
bump_cpu_timer(timer, now);
}
WARN_ON_ONCE(!irqs_disabled());
arm_timer(timer);
unlock_task_sighand(p, &flags);
out:
timer->it_overrun_last = timer->it_overrun;
timer->it_overrun = -1;
++timer->it_requeue_pending;
}
static inline int task_cputime_expired(const struct task_cputime *sample,
const struct task_cputime *expires)
{
if (expires->utime && sample->utime >= expires->utime)
return 1;
if (expires->stime && sample->utime + sample->stime >= expires->stime)
return 1;
if (expires->sum_exec_runtime != 0 &&
sample->sum_exec_runtime >= expires->sum_exec_runtime)
return 1;
return 0;
}
static inline int fastpath_timer_check(struct task_struct *tsk)
{
struct signal_struct *sig;
if (!task_cputime_zero(&tsk->cputime_expires)) {
struct task_cputime task_sample;
task_cputime(tsk, &task_sample.utime, &task_sample.stime);
task_sample.sum_exec_runtime = tsk->se.sum_exec_runtime;
if (task_cputime_expired(&task_sample, &tsk->cputime_expires))
return 1;
}
sig = tsk->signal;
if (READ_ONCE(sig->cputimer.running) &&
!READ_ONCE(sig->cputimer.checking_timer)) {
struct task_cputime group_sample;
sample_cputime_atomic(&group_sample, &sig->cputimer.cputime_atomic);
if (task_cputime_expired(&group_sample, &sig->cputime_expires))
return 1;
}
return 0;
}
void run_posix_cpu_timers(struct task_struct *tsk)
{
LIST_HEAD(firing);
struct k_itimer *timer, *next;
unsigned long flags;
WARN_ON_ONCE(!irqs_disabled());
if (!fastpath_timer_check(tsk))
return;
if (!lock_task_sighand(tsk, &flags))
return;
check_thread_timers(tsk, &firing);
check_process_timers(tsk, &firing);
unlock_task_sighand(tsk, &flags);
list_for_each_entry_safe(timer, next, &firing, it.cpu.entry) {
int cpu_firing;
spin_lock(&timer->it_lock);
list_del_init(&timer->it.cpu.entry);
cpu_firing = timer->it.cpu.firing;
timer->it.cpu.firing = 0;
if (likely(cpu_firing >= 0))
cpu_timer_fire(timer);
spin_unlock(&timer->it_lock);
}
}
void set_process_cpu_timer(struct task_struct *tsk, unsigned int clock_idx,
cputime_t *newval, cputime_t *oldval)
{
unsigned long long now;
WARN_ON_ONCE(clock_idx == CPUCLOCK_SCHED);
cpu_timer_sample_group(clock_idx, tsk, &now);
if (oldval) {
if (*oldval) {
if (*oldval <= now) {
*oldval = cputime_one_jiffy;
} else {
*oldval -= now;
}
}
if (!*newval)
return;
*newval += now;
}
switch (clock_idx) {
case CPUCLOCK_PROF:
if (expires_gt(tsk->signal->cputime_expires.prof_exp, *newval))
tsk->signal->cputime_expires.prof_exp = *newval;
break;
case CPUCLOCK_VIRT:
if (expires_gt(tsk->signal->cputime_expires.virt_exp, *newval))
tsk->signal->cputime_expires.virt_exp = *newval;
break;
}
tick_dep_set_signal(tsk->signal, TICK_DEP_BIT_POSIX_TIMER);
}
static int do_cpu_nanosleep(const clockid_t which_clock, int flags,
struct timespec *rqtp, struct itimerspec *it)
{
struct k_itimer timer;
int error;
memset(&timer, 0, sizeof timer);
spin_lock_init(&timer.it_lock);
timer.it_clock = which_clock;
timer.it_overrun = -1;
error = posix_cpu_timer_create(&timer);
timer.it_process = current;
if (!error) {
static struct itimerspec zero_it;
memset(it, 0, sizeof *it);
it->it_value = *rqtp;
spin_lock_irq(&timer.it_lock);
error = posix_cpu_timer_set(&timer, flags, it, NULL);
if (error) {
spin_unlock_irq(&timer.it_lock);
return error;
}
while (!signal_pending(current)) {
if (timer.it.cpu.expires == 0) {
posix_cpu_timer_del(&timer);
spin_unlock_irq(&timer.it_lock);
return 0;
}
__set_current_state(TASK_INTERRUPTIBLE);
spin_unlock_irq(&timer.it_lock);
schedule();
spin_lock_irq(&timer.it_lock);
}
sample_to_timespec(which_clock, timer.it.cpu.expires, rqtp);
error = posix_cpu_timer_set(&timer, 0, &zero_it, it);
if (!error) {
posix_cpu_timer_del(&timer);
}
spin_unlock_irq(&timer.it_lock);
while (error == TIMER_RETRY) {
spin_lock_irq(&timer.it_lock);
error = posix_cpu_timer_del(&timer);
spin_unlock_irq(&timer.it_lock);
}
if ((it->it_value.tv_sec | it->it_value.tv_nsec) == 0) {
return 0;
}
error = -ERESTART_RESTARTBLOCK;
}
return error;
}
static int posix_cpu_nsleep(const clockid_t which_clock, int flags,
struct timespec *rqtp, struct timespec __user *rmtp)
{
struct restart_block *restart_block = &current->restart_block;
struct itimerspec it;
int error;
if (CPUCLOCK_PERTHREAD(which_clock) &&
(CPUCLOCK_PID(which_clock) == 0 ||
CPUCLOCK_PID(which_clock) == current->pid))
return -EINVAL;
error = do_cpu_nanosleep(which_clock, flags, rqtp, &it);
if (error == -ERESTART_RESTARTBLOCK) {
if (flags & TIMER_ABSTIME)
return -ERESTARTNOHAND;
if (rmtp && copy_to_user(rmtp, &it.it_value, sizeof *rmtp))
return -EFAULT;
restart_block->fn = posix_cpu_nsleep_restart;
restart_block->nanosleep.clockid = which_clock;
restart_block->nanosleep.rmtp = rmtp;
restart_block->nanosleep.expires = timespec_to_ns(rqtp);
}
return error;
}
static long posix_cpu_nsleep_restart(struct restart_block *restart_block)
{
clockid_t which_clock = restart_block->nanosleep.clockid;
struct timespec t;
struct itimerspec it;
int error;
t = ns_to_timespec(restart_block->nanosleep.expires);
error = do_cpu_nanosleep(which_clock, TIMER_ABSTIME, &t, &it);
if (error == -ERESTART_RESTARTBLOCK) {
struct timespec __user *rmtp = restart_block->nanosleep.rmtp;
if (rmtp && copy_to_user(rmtp, &it.it_value, sizeof *rmtp))
return -EFAULT;
restart_block->nanosleep.expires = timespec_to_ns(&t);
}
return error;
}
static int process_cpu_clock_getres(const clockid_t which_clock,
struct timespec *tp)
{
return posix_cpu_clock_getres(PROCESS_CLOCK, tp);
}
static int process_cpu_clock_get(const clockid_t which_clock,
struct timespec *tp)
{
return posix_cpu_clock_get(PROCESS_CLOCK, tp);
}
static int process_cpu_timer_create(struct k_itimer *timer)
{
timer->it_clock = PROCESS_CLOCK;
return posix_cpu_timer_create(timer);
}
static int process_cpu_nsleep(const clockid_t which_clock, int flags,
struct timespec *rqtp,
struct timespec __user *rmtp)
{
return posix_cpu_nsleep(PROCESS_CLOCK, flags, rqtp, rmtp);
}
static long process_cpu_nsleep_restart(struct restart_block *restart_block)
{
return -EINVAL;
}
static int thread_cpu_clock_getres(const clockid_t which_clock,
struct timespec *tp)
{
return posix_cpu_clock_getres(THREAD_CLOCK, tp);
}
static int thread_cpu_clock_get(const clockid_t which_clock,
struct timespec *tp)
{
return posix_cpu_clock_get(THREAD_CLOCK, tp);
}
static int thread_cpu_timer_create(struct k_itimer *timer)
{
timer->it_clock = THREAD_CLOCK;
return posix_cpu_timer_create(timer);
}
static __init int init_posix_cpu_timers(void)
{
struct k_clock process = {
.clock_getres = process_cpu_clock_getres,
.clock_get = process_cpu_clock_get,
.timer_create = process_cpu_timer_create,
.nsleep = process_cpu_nsleep,
.nsleep_restart = process_cpu_nsleep_restart,
};
struct k_clock thread = {
.clock_getres = thread_cpu_clock_getres,
.clock_get = thread_cpu_clock_get,
.timer_create = thread_cpu_timer_create,
};
struct timespec ts;
posix_timers_register_clock(CLOCK_PROCESS_CPUTIME_ID, &process);
posix_timers_register_clock(CLOCK_THREAD_CPUTIME_ID, &thread);
cputime_to_timespec(cputime_one_jiffy, &ts);
onecputick = ts.tv_nsec;
WARN_ON(ts.tv_sec != 0);
return 0;
}
