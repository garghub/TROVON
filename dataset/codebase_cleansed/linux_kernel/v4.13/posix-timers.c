static int hash(struct signal_struct *sig, unsigned int nr)
{
return hash_32(hash32_ptr(sig) ^ nr, HASH_BITS(posix_timers_hashtable));
}
static struct k_itimer *__posix_timers_find(struct hlist_head *head,
struct signal_struct *sig,
timer_t id)
{
struct k_itimer *timer;
hlist_for_each_entry_rcu(timer, head, t_hash) {
if ((timer->it_signal == sig) && (timer->it_id == id))
return timer;
}
return NULL;
}
static struct k_itimer *posix_timer_by_id(timer_t id)
{
struct signal_struct *sig = current->signal;
struct hlist_head *head = &posix_timers_hashtable[hash(sig, id)];
return __posix_timers_find(head, sig, id);
}
static int posix_timer_add(struct k_itimer *timer)
{
struct signal_struct *sig = current->signal;
int first_free_id = sig->posix_timer_id;
struct hlist_head *head;
int ret = -ENOENT;
do {
spin_lock(&hash_lock);
head = &posix_timers_hashtable[hash(sig, sig->posix_timer_id)];
if (!__posix_timers_find(head, sig, sig->posix_timer_id)) {
hlist_add_head_rcu(&timer->t_hash, head);
ret = sig->posix_timer_id;
}
if (++sig->posix_timer_id < 0)
sig->posix_timer_id = 0;
if ((sig->posix_timer_id == first_free_id) && (ret == -ENOENT))
ret = -EAGAIN;
spin_unlock(&hash_lock);
} while (ret == -ENOENT);
return ret;
}
static inline void unlock_timer(struct k_itimer *timr, unsigned long flags)
{
spin_unlock_irqrestore(&timr->it_lock, flags);
}
static int posix_clock_realtime_get(clockid_t which_clock, struct timespec64 *tp)
{
ktime_get_real_ts64(tp);
return 0;
}
static int posix_clock_realtime_set(const clockid_t which_clock,
const struct timespec64 *tp)
{
return do_sys_settimeofday64(tp, NULL);
}
static int posix_clock_realtime_adj(const clockid_t which_clock,
struct timex *t)
{
return do_adjtimex(t);
}
static int posix_ktime_get_ts(clockid_t which_clock, struct timespec64 *tp)
{
ktime_get_ts64(tp);
return 0;
}
static int posix_get_monotonic_raw(clockid_t which_clock, struct timespec64 *tp)
{
getrawmonotonic64(tp);
return 0;
}
static int posix_get_realtime_coarse(clockid_t which_clock, struct timespec64 *tp)
{
*tp = current_kernel_time64();
return 0;
}
static int posix_get_monotonic_coarse(clockid_t which_clock,
struct timespec64 *tp)
{
*tp = get_monotonic_coarse64();
return 0;
}
static int posix_get_coarse_res(const clockid_t which_clock, struct timespec64 *tp)
{
*tp = ktime_to_timespec64(KTIME_LOW_RES);
return 0;
}
static int posix_get_boottime(const clockid_t which_clock, struct timespec64 *tp)
{
get_monotonic_boottime64(tp);
return 0;
}
static int posix_get_tai(clockid_t which_clock, struct timespec64 *tp)
{
timekeeping_clocktai64(tp);
return 0;
}
static int posix_get_hrtimer_res(clockid_t which_clock, struct timespec64 *tp)
{
tp->tv_sec = 0;
tp->tv_nsec = hrtimer_resolution;
return 0;
}
static __init int init_posix_timers(void)
{
posix_timers_cache = kmem_cache_create("posix_timers_cache",
sizeof (struct k_itimer), 0, SLAB_PANIC,
NULL);
return 0;
}
static void common_hrtimer_rearm(struct k_itimer *timr)
{
struct hrtimer *timer = &timr->it.real.timer;
if (!timr->it_interval)
return;
timr->it_overrun += (unsigned int) hrtimer_forward(timer,
timer->base->get_time(),
timr->it_interval);
hrtimer_restart(timer);
}
void posixtimer_rearm(struct siginfo *info)
{
struct k_itimer *timr;
unsigned long flags;
timr = lock_timer(info->si_tid, &flags);
if (!timr)
return;
if (timr->it_requeue_pending == info->si_sys_private) {
timr->kclock->timer_rearm(timr);
timr->it_active = 1;
timr->it_overrun_last = timr->it_overrun;
timr->it_overrun = -1;
++timr->it_requeue_pending;
info->si_overrun += timr->it_overrun_last;
}
unlock_timer(timr, flags);
}
int posix_timer_event(struct k_itimer *timr, int si_private)
{
struct task_struct *task;
int shared, ret = -1;
timr->sigq->info.si_sys_private = si_private;
rcu_read_lock();
task = pid_task(timr->it_pid, PIDTYPE_PID);
if (task) {
shared = !(timr->it_sigev_notify & SIGEV_THREAD_ID);
ret = send_sigqueue(timr->sigq, task, shared);
}
rcu_read_unlock();
return ret > 0;
}
static enum hrtimer_restart posix_timer_fn(struct hrtimer *timer)
{
struct k_itimer *timr;
unsigned long flags;
int si_private = 0;
enum hrtimer_restart ret = HRTIMER_NORESTART;
timr = container_of(timer, struct k_itimer, it.real.timer);
spin_lock_irqsave(&timr->it_lock, flags);
timr->it_active = 0;
if (timr->it_interval != 0)
si_private = ++timr->it_requeue_pending;
if (posix_timer_event(timr, si_private)) {
if (timr->it_interval != 0) {
ktime_t now = hrtimer_cb_get_time(timer);
#ifdef CONFIG_HIGH_RES_TIMERS
{
ktime_t kj = NSEC_PER_SEC / HZ;
if (timr->it_interval < kj)
now = ktime_add(now, kj);
}
#endif
timr->it_overrun += (unsigned int)
hrtimer_forward(timer, now,
timr->it_interval);
ret = HRTIMER_RESTART;
++timr->it_requeue_pending;
timr->it_active = 1;
}
}
unlock_timer(timr, flags);
return ret;
}
static struct pid *good_sigevent(sigevent_t * event)
{
struct task_struct *rtn = current->group_leader;
if ((event->sigev_notify & SIGEV_THREAD_ID ) &&
(!(rtn = find_task_by_vpid(event->sigev_notify_thread_id)) ||
!same_thread_group(rtn, current) ||
(event->sigev_notify & ~SIGEV_THREAD_ID) != SIGEV_SIGNAL))
return NULL;
if (((event->sigev_notify & ~SIGEV_THREAD_ID) != SIGEV_NONE) &&
((event->sigev_signo <= 0) || (event->sigev_signo > SIGRTMAX)))
return NULL;
return task_pid(rtn);
}
static struct k_itimer * alloc_posix_timer(void)
{
struct k_itimer *tmr;
tmr = kmem_cache_zalloc(posix_timers_cache, GFP_KERNEL);
if (!tmr)
return tmr;
if (unlikely(!(tmr->sigq = sigqueue_alloc()))) {
kmem_cache_free(posix_timers_cache, tmr);
return NULL;
}
memset(&tmr->sigq->info, 0, sizeof(siginfo_t));
return tmr;
}
static void k_itimer_rcu_free(struct rcu_head *head)
{
struct k_itimer *tmr = container_of(head, struct k_itimer, it.rcu);
kmem_cache_free(posix_timers_cache, tmr);
}
static void release_posix_timer(struct k_itimer *tmr, int it_id_set)
{
if (it_id_set) {
unsigned long flags;
spin_lock_irqsave(&hash_lock, flags);
hlist_del_rcu(&tmr->t_hash);
spin_unlock_irqrestore(&hash_lock, flags);
}
put_pid(tmr->it_pid);
sigqueue_free(tmr->sigq);
call_rcu(&tmr->it.rcu, k_itimer_rcu_free);
}
static int common_timer_create(struct k_itimer *new_timer)
{
hrtimer_init(&new_timer->it.real.timer, new_timer->it_clock, 0);
return 0;
}
static int do_timer_create(clockid_t which_clock, struct sigevent *event,
timer_t __user *created_timer_id)
{
const struct k_clock *kc = clockid_to_kclock(which_clock);
struct k_itimer *new_timer;
int error, new_timer_id;
int it_id_set = IT_ID_NOT_SET;
if (!kc)
return -EINVAL;
if (!kc->timer_create)
return -EOPNOTSUPP;
new_timer = alloc_posix_timer();
if (unlikely(!new_timer))
return -EAGAIN;
spin_lock_init(&new_timer->it_lock);
new_timer_id = posix_timer_add(new_timer);
if (new_timer_id < 0) {
error = new_timer_id;
goto out;
}
it_id_set = IT_ID_SET;
new_timer->it_id = (timer_t) new_timer_id;
new_timer->it_clock = which_clock;
new_timer->kclock = kc;
new_timer->it_overrun = -1;
if (event) {
rcu_read_lock();
new_timer->it_pid = get_pid(good_sigevent(event));
rcu_read_unlock();
if (!new_timer->it_pid) {
error = -EINVAL;
goto out;
}
new_timer->it_sigev_notify = event->sigev_notify;
new_timer->sigq->info.si_signo = event->sigev_signo;
new_timer->sigq->info.si_value = event->sigev_value;
} else {
new_timer->it_sigev_notify = SIGEV_SIGNAL;
new_timer->sigq->info.si_signo = SIGALRM;
memset(&new_timer->sigq->info.si_value, 0, sizeof(sigval_t));
new_timer->sigq->info.si_value.sival_int = new_timer->it_id;
new_timer->it_pid = get_pid(task_tgid(current));
}
new_timer->sigq->info.si_tid = new_timer->it_id;
new_timer->sigq->info.si_code = SI_TIMER;
if (copy_to_user(created_timer_id,
&new_timer_id, sizeof (new_timer_id))) {
error = -EFAULT;
goto out;
}
error = kc->timer_create(new_timer);
if (error)
goto out;
spin_lock_irq(&current->sighand->siglock);
new_timer->it_signal = current->signal;
list_add(&new_timer->list, &current->signal->posix_timers);
spin_unlock_irq(&current->sighand->siglock);
return 0;
out:
release_posix_timer(new_timer, it_id_set);
return error;
}
static struct k_itimer *__lock_timer(timer_t timer_id, unsigned long *flags)
{
struct k_itimer *timr;
if ((unsigned long long)timer_id > INT_MAX)
return NULL;
rcu_read_lock();
timr = posix_timer_by_id(timer_id);
if (timr) {
spin_lock_irqsave(&timr->it_lock, *flags);
if (timr->it_signal == current->signal) {
rcu_read_unlock();
return timr;
}
spin_unlock_irqrestore(&timr->it_lock, *flags);
}
rcu_read_unlock();
return NULL;
}
static ktime_t common_hrtimer_remaining(struct k_itimer *timr, ktime_t now)
{
struct hrtimer *timer = &timr->it.real.timer;
return __hrtimer_expires_remaining_adjusted(timer, now);
}
static int common_hrtimer_forward(struct k_itimer *timr, ktime_t now)
{
struct hrtimer *timer = &timr->it.real.timer;
return (int)hrtimer_forward(timer, now, timr->it_interval);
}
void common_timer_get(struct k_itimer *timr, struct itimerspec64 *cur_setting)
{
const struct k_clock *kc = timr->kclock;
ktime_t now, remaining, iv;
struct timespec64 ts64;
bool sig_none;
sig_none = (timr->it_sigev_notify & ~SIGEV_THREAD_ID) == SIGEV_NONE;
iv = timr->it_interval;
if (iv) {
cur_setting->it_interval = ktime_to_timespec64(iv);
} else if (!timr->it_active) {
if (!sig_none)
return;
}
kc->clock_get(timr->it_clock, &ts64);
now = timespec64_to_ktime(ts64);
if (iv && (timr->it_requeue_pending & REQUEUE_PENDING || sig_none))
timr->it_overrun += kc->timer_forward(timr, now);
remaining = kc->timer_remaining(timr, now);
if (remaining <= 0) {
if (!sig_none)
cur_setting->it_value.tv_nsec = 1;
} else {
cur_setting->it_value = ktime_to_timespec64(remaining);
}
}
static int do_timer_gettime(timer_t timer_id, struct itimerspec64 *setting)
{
struct k_itimer *timr;
const struct k_clock *kc;
unsigned long flags;
int ret = 0;
timr = lock_timer(timer_id, &flags);
if (!timr)
return -EINVAL;
memset(setting, 0, sizeof(*setting));
kc = timr->kclock;
if (WARN_ON_ONCE(!kc || !kc->timer_get))
ret = -EINVAL;
else
kc->timer_get(timr, setting);
unlock_timer(timr, flags);
return ret;
}
static void common_hrtimer_arm(struct k_itimer *timr, ktime_t expires,
bool absolute, bool sigev_none)
{
struct hrtimer *timer = &timr->it.real.timer;
enum hrtimer_mode mode;
mode = absolute ? HRTIMER_MODE_ABS : HRTIMER_MODE_REL;
if (timr->it_clock == CLOCK_REALTIME)
timr->kclock = absolute ? &clock_realtime : &clock_monotonic;
hrtimer_init(&timr->it.real.timer, timr->it_clock, mode);
timr->it.real.timer.function = posix_timer_fn;
if (!absolute)
expires = ktime_add_safe(expires, timer->base->get_time());
hrtimer_set_expires(timer, expires);
if (!sigev_none)
hrtimer_start_expires(timer, HRTIMER_MODE_ABS);
}
static int common_hrtimer_try_to_cancel(struct k_itimer *timr)
{
return hrtimer_try_to_cancel(&timr->it.real.timer);
}
int common_timer_set(struct k_itimer *timr, int flags,
struct itimerspec64 *new_setting,
struct itimerspec64 *old_setting)
{
const struct k_clock *kc = timr->kclock;
bool sigev_none;
ktime_t expires;
if (old_setting)
common_timer_get(timr, old_setting);
timr->it_interval = 0;
if (kc->timer_try_to_cancel(timr) < 0)
return TIMER_RETRY;
timr->it_active = 0;
timr->it_requeue_pending = (timr->it_requeue_pending + 2) &
~REQUEUE_PENDING;
timr->it_overrun_last = 0;
if (!new_setting->it_value.tv_sec && !new_setting->it_value.tv_nsec)
return 0;
timr->it_interval = timespec64_to_ktime(new_setting->it_interval);
expires = timespec64_to_ktime(new_setting->it_value);
sigev_none = (timr->it_sigev_notify & ~SIGEV_THREAD_ID) == SIGEV_NONE;
kc->timer_arm(timr, expires, flags & TIMER_ABSTIME, sigev_none);
timr->it_active = !sigev_none;
return 0;
}
static int do_timer_settime(timer_t timer_id, int flags,
struct itimerspec64 *new_spec64,
struct itimerspec64 *old_spec64)
{
const struct k_clock *kc;
struct k_itimer *timr;
unsigned long flag;
int error = 0;
if (!timespec64_valid(&new_spec64->it_interval) ||
!timespec64_valid(&new_spec64->it_value))
return -EINVAL;
if (old_spec64)
memset(old_spec64, 0, sizeof(*old_spec64));
retry:
timr = lock_timer(timer_id, &flag);
if (!timr)
return -EINVAL;
kc = timr->kclock;
if (WARN_ON_ONCE(!kc || !kc->timer_set))
error = -EINVAL;
else
error = kc->timer_set(timr, flags, new_spec64, old_spec64);
unlock_timer(timr, flag);
if (error == TIMER_RETRY) {
old_spec64 = NULL;
goto retry;
}
return error;
}
int common_timer_del(struct k_itimer *timer)
{
const struct k_clock *kc = timer->kclock;
timer->it_interval = 0;
if (kc->timer_try_to_cancel(timer) < 0)
return TIMER_RETRY;
timer->it_active = 0;
return 0;
}
static inline int timer_delete_hook(struct k_itimer *timer)
{
const struct k_clock *kc = timer->kclock;
if (WARN_ON_ONCE(!kc || !kc->timer_del))
return -EINVAL;
return kc->timer_del(timer);
}
static void itimer_delete(struct k_itimer *timer)
{
unsigned long flags;
retry_delete:
spin_lock_irqsave(&timer->it_lock, flags);
if (timer_delete_hook(timer) == TIMER_RETRY) {
unlock_timer(timer, flags);
goto retry_delete;
}
list_del(&timer->list);
timer->it_signal = NULL;
unlock_timer(timer, flags);
release_posix_timer(timer, IT_ID_SET);
}
void exit_itimers(struct signal_struct *sig)
{
struct k_itimer *tmr;
while (!list_empty(&sig->posix_timers)) {
tmr = list_entry(sig->posix_timers.next, struct k_itimer, list);
itimer_delete(tmr);
}
}
static int common_nsleep(const clockid_t which_clock, int flags,
const struct timespec64 *rqtp)
{
return hrtimer_nanosleep(rqtp, flags & TIMER_ABSTIME ?
HRTIMER_MODE_ABS : HRTIMER_MODE_REL,
which_clock);
}
static const struct k_clock *clockid_to_kclock(const clockid_t id)
{
if (id < 0)
return (id & CLOCKFD_MASK) == CLOCKFD ?
&clock_posix_dynamic : &clock_posix_cpu;
if (id >= ARRAY_SIZE(posix_clocks) || !posix_clocks[id])
return NULL;
return posix_clocks[id];
}
