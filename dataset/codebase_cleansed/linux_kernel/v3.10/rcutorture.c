static u64 notrace rcu_trace_clock_local(void)
{
u64 ts = trace_clock_local();
unsigned long __maybe_unused ts_rem = do_div(ts, NSEC_PER_USEC);
return ts;
}
static u64 notrace rcu_trace_clock_local(void)
{
return 0ULL;
}
static int
rcutorture_shutdown_notify(struct notifier_block *unused1,
unsigned long unused2, void *unused3)
{
mutex_lock(&fullstop_mutex);
if (fullstop == FULLSTOP_DONTSTOP)
fullstop = FULLSTOP_SHUTDOWN;
else
pr_warn(
"Concurrent 'rmmod rcutorture' and shutdown illegal!\n");
mutex_unlock(&fullstop_mutex);
return NOTIFY_DONE;
}
static void rcutorture_shutdown_absorb(char *title)
{
if (ACCESS_ONCE(fullstop) == FULLSTOP_SHUTDOWN) {
pr_notice(
"rcutorture thread %s parking due to system shutdown\n",
title);
schedule_timeout_uninterruptible(MAX_SCHEDULE_TIMEOUT);
}
}
static struct rcu_torture *
rcu_torture_alloc(void)
{
struct list_head *p;
spin_lock_bh(&rcu_torture_lock);
if (list_empty(&rcu_torture_freelist)) {
atomic_inc(&n_rcu_torture_alloc_fail);
spin_unlock_bh(&rcu_torture_lock);
return NULL;
}
atomic_inc(&n_rcu_torture_alloc);
p = rcu_torture_freelist.next;
list_del_init(p);
spin_unlock_bh(&rcu_torture_lock);
return container_of(p, struct rcu_torture, rtort_free);
}
static void
rcu_torture_free(struct rcu_torture *p)
{
atomic_inc(&n_rcu_torture_free);
spin_lock_bh(&rcu_torture_lock);
list_add_tail(&p->rtort_free, &rcu_torture_freelist);
spin_unlock_bh(&rcu_torture_lock);
}
static unsigned long
rcu_random(struct rcu_random_state *rrsp)
{
if (--rrsp->rrs_count < 0) {
rrsp->rrs_state += (unsigned long)local_clock();
rrsp->rrs_count = RCU_RANDOM_REFRESH;
}
rrsp->rrs_state = rrsp->rrs_state * RCU_RANDOM_MULT + RCU_RANDOM_ADD;
return swahw32(rrsp->rrs_state);
}
static void
rcu_stutter_wait(char *title)
{
while (stutter_pause_test || !rcutorture_runnable) {
if (rcutorture_runnable)
schedule_timeout_interruptible(1);
else
schedule_timeout_interruptible(round_jiffies_relative(HZ));
rcutorture_shutdown_absorb(title);
}
}
static int rcu_torture_read_lock(void) __acquires(RCU)
{
rcu_read_lock();
return 0;
}
static void rcu_read_delay(struct rcu_random_state *rrsp)
{
const unsigned long shortdelay_us = 200;
const unsigned long longdelay_ms = 50;
if (!(rcu_random(rrsp) % (nrealreaders * 2000 * longdelay_ms)))
mdelay(longdelay_ms);
if (!(rcu_random(rrsp) % (nrealreaders * 2 * shortdelay_us)))
udelay(shortdelay_us);
#ifdef CONFIG_PREEMPT
if (!preempt_count() && !(rcu_random(rrsp) % (nrealreaders * 20000)))
preempt_schedule();
#endif
}
static void rcu_torture_read_unlock(int idx) __releases(RCU)
{
rcu_read_unlock();
}
static int rcu_torture_completed(void)
{
return rcu_batches_completed();
}
static void
rcu_torture_cb(struct rcu_head *p)
{
int i;
struct rcu_torture *rp = container_of(p, struct rcu_torture, rtort_rcu);
if (fullstop != FULLSTOP_DONTSTOP) {
return;
}
i = rp->rtort_pipe_count;
if (i > RCU_TORTURE_PIPE_LEN)
i = RCU_TORTURE_PIPE_LEN;
atomic_inc(&rcu_torture_wcount[i]);
if (++rp->rtort_pipe_count >= RCU_TORTURE_PIPE_LEN) {
rp->rtort_mbtest = 0;
rcu_torture_free(rp);
} else {
cur_ops->deferred_free(rp);
}
}
static int rcu_no_completed(void)
{
return 0;
}
static void rcu_torture_deferred_free(struct rcu_torture *p)
{
call_rcu(&p->rtort_rcu, rcu_torture_cb);
}
static void rcu_sync_torture_deferred_free(struct rcu_torture *p)
{
int i;
struct rcu_torture *rp;
struct rcu_torture *rp1;
cur_ops->sync();
list_add(&p->rtort_free, &rcu_torture_removed);
list_for_each_entry_safe(rp, rp1, &rcu_torture_removed, rtort_free) {
i = rp->rtort_pipe_count;
if (i > RCU_TORTURE_PIPE_LEN)
i = RCU_TORTURE_PIPE_LEN;
atomic_inc(&rcu_torture_wcount[i]);
if (++rp->rtort_pipe_count >= RCU_TORTURE_PIPE_LEN) {
rp->rtort_mbtest = 0;
list_del(&rp->rtort_free);
rcu_torture_free(rp);
}
}
}
static void rcu_sync_torture_init(void)
{
INIT_LIST_HEAD(&rcu_torture_removed);
}
static int rcu_bh_torture_read_lock(void) __acquires(RCU_BH)
{
rcu_read_lock_bh();
return 0;
}
static void rcu_bh_torture_read_unlock(int idx) __releases(RCU_BH)
{
rcu_read_unlock_bh();
}
static int rcu_bh_torture_completed(void)
{
return rcu_batches_completed_bh();
}
static void rcu_bh_torture_deferred_free(struct rcu_torture *p)
{
call_rcu_bh(&p->rtort_rcu, rcu_torture_cb);
}
static int srcu_torture_read_lock(void) __acquires(&srcu_ctl
static void srcu_read_delay(struct rcu_random_state *rrsp)
{
long delay;
const long uspertick = 1000000 / HZ;
const long longdelay = 10;
delay = rcu_random(rrsp) % (nrealreaders * 2 * longdelay * uspertick);
if (!delay)
schedule_timeout_interruptible(longdelay);
else
rcu_read_delay(rrsp);
}
static void srcu_torture_read_unlock(int idx) __releases(&srcu_ctl
static int srcu_torture_completed(void)
{
return srcu_batches_completed(&srcu_ctl);
}
static void srcu_torture_deferred_free(struct rcu_torture *rp)
{
call_srcu(&srcu_ctl, &rp->rtort_rcu, rcu_torture_cb);
}
static void srcu_torture_synchronize(void)
{
synchronize_srcu(&srcu_ctl);
}
static void srcu_torture_call(struct rcu_head *head,
void (*func)(struct rcu_head *head))
{
call_srcu(&srcu_ctl, head, func);
}
static void srcu_torture_barrier(void)
{
srcu_barrier(&srcu_ctl);
}
static int srcu_torture_stats(char *page)
{
int cnt = 0;
int cpu;
int idx = srcu_ctl.completed & 0x1;
cnt += sprintf(&page[cnt], "%s%s per-CPU(idx=%d):",
torture_type, TORTURE_FLAG, idx);
for_each_possible_cpu(cpu) {
cnt += sprintf(&page[cnt], " %d(%lu,%lu)", cpu,
per_cpu_ptr(srcu_ctl.per_cpu_ref, cpu)->c[!idx],
per_cpu_ptr(srcu_ctl.per_cpu_ref, cpu)->c[idx]);
}
cnt += sprintf(&page[cnt], "\n");
return cnt;
}
static int srcu_torture_read_lock_raw(void) __acquires(&srcu_ctl
static void srcu_torture_read_unlock_raw(int idx) __releases(&srcu_ctl
static void srcu_torture_synchronize_expedited(void)
{
synchronize_srcu_expedited(&srcu_ctl);
}
static int sched_torture_read_lock(void)
{
preempt_disable();
return 0;
}
static void sched_torture_read_unlock(int idx)
{
preempt_enable();
}
static void rcu_sched_torture_deferred_free(struct rcu_torture *p)
{
call_rcu_sched(&p->rtort_rcu, rcu_torture_cb);
}
static void rcu_torture_boost_cb(struct rcu_head *head)
{
struct rcu_boost_inflight *rbip =
container_of(head, struct rcu_boost_inflight, rcu);
smp_mb();
rbip->inflight = 0;
}
static int rcu_torture_boost(void *arg)
{
unsigned long call_rcu_time;
unsigned long endtime;
unsigned long oldstarttime;
struct rcu_boost_inflight rbi = { .inflight = 0 };
struct sched_param sp;
VERBOSE_PRINTK_STRING("rcu_torture_boost started");
sp.sched_priority = 1;
if (sched_setscheduler(current, SCHED_FIFO, &sp) < 0) {
VERBOSE_PRINTK_STRING("rcu_torture_boost RT prio failed!");
n_rcu_torture_boost_rterror++;
}
init_rcu_head_on_stack(&rbi.rcu);
do {
oldstarttime = boost_starttime;
while (ULONG_CMP_LT(jiffies, oldstarttime)) {
schedule_timeout_interruptible(oldstarttime - jiffies);
rcu_stutter_wait("rcu_torture_boost");
if (kthread_should_stop() ||
fullstop != FULLSTOP_DONTSTOP)
goto checkwait;
}
endtime = oldstarttime + test_boost_duration * HZ;
call_rcu_time = jiffies;
while (ULONG_CMP_LT(jiffies, endtime)) {
if (!rbi.inflight) {
smp_mb();
rbi.inflight = 1;
call_rcu(&rbi.rcu, rcu_torture_boost_cb);
if (jiffies - call_rcu_time >
test_boost_duration * HZ - HZ / 2) {
VERBOSE_PRINTK_STRING("rcu_torture_boost boosting failed");
n_rcu_torture_boost_failure++;
}
call_rcu_time = jiffies;
}
cond_resched();
rcu_stutter_wait("rcu_torture_boost");
if (kthread_should_stop() ||
fullstop != FULLSTOP_DONTSTOP)
goto checkwait;
}
while (oldstarttime == boost_starttime &&
!kthread_should_stop()) {
if (mutex_trylock(&boost_mutex)) {
boost_starttime = jiffies +
test_boost_interval * HZ;
n_rcu_torture_boosts++;
mutex_unlock(&boost_mutex);
break;
}
schedule_timeout_uninterruptible(1);
}
checkwait: rcu_stutter_wait("rcu_torture_boost");
} while (!kthread_should_stop() && fullstop == FULLSTOP_DONTSTOP);
VERBOSE_PRINTK_STRING("rcu_torture_boost task stopping");
rcutorture_shutdown_absorb("rcu_torture_boost");
while (!kthread_should_stop() || rbi.inflight)
schedule_timeout_uninterruptible(1);
smp_mb();
destroy_rcu_head_on_stack(&rbi.rcu);
return 0;
}
static int
rcu_torture_fqs(void *arg)
{
unsigned long fqs_resume_time;
int fqs_burst_remaining;
VERBOSE_PRINTK_STRING("rcu_torture_fqs task started");
do {
fqs_resume_time = jiffies + fqs_stutter * HZ;
while (ULONG_CMP_LT(jiffies, fqs_resume_time) &&
!kthread_should_stop()) {
schedule_timeout_interruptible(1);
}
fqs_burst_remaining = fqs_duration;
while (fqs_burst_remaining > 0 &&
!kthread_should_stop()) {
cur_ops->fqs();
udelay(fqs_holdoff);
fqs_burst_remaining -= fqs_holdoff;
}
rcu_stutter_wait("rcu_torture_fqs");
} while (!kthread_should_stop() && fullstop == FULLSTOP_DONTSTOP);
VERBOSE_PRINTK_STRING("rcu_torture_fqs task stopping");
rcutorture_shutdown_absorb("rcu_torture_fqs");
while (!kthread_should_stop())
schedule_timeout_uninterruptible(1);
return 0;
}
static int
rcu_torture_writer(void *arg)
{
int i;
long oldbatch = rcu_batches_completed();
struct rcu_torture *rp;
struct rcu_torture *old_rp;
static DEFINE_RCU_RANDOM(rand);
VERBOSE_PRINTK_STRING("rcu_torture_writer task started");
set_user_nice(current, 19);
do {
schedule_timeout_uninterruptible(1);
rp = rcu_torture_alloc();
if (rp == NULL)
continue;
rp->rtort_pipe_count = 0;
udelay(rcu_random(&rand) & 0x3ff);
old_rp = rcu_dereference_check(rcu_torture_current,
current == writer_task);
rp->rtort_mbtest = 1;
rcu_assign_pointer(rcu_torture_current, rp);
smp_wmb();
if (old_rp) {
i = old_rp->rtort_pipe_count;
if (i > RCU_TORTURE_PIPE_LEN)
i = RCU_TORTURE_PIPE_LEN;
atomic_inc(&rcu_torture_wcount[i]);
old_rp->rtort_pipe_count++;
cur_ops->deferred_free(old_rp);
}
rcutorture_record_progress(++rcu_torture_current_version);
oldbatch = cur_ops->completed();
rcu_stutter_wait("rcu_torture_writer");
} while (!kthread_should_stop() && fullstop == FULLSTOP_DONTSTOP);
VERBOSE_PRINTK_STRING("rcu_torture_writer task stopping");
rcutorture_shutdown_absorb("rcu_torture_writer");
while (!kthread_should_stop())
schedule_timeout_uninterruptible(1);
return 0;
}
static int
rcu_torture_fakewriter(void *arg)
{
DEFINE_RCU_RANDOM(rand);
VERBOSE_PRINTK_STRING("rcu_torture_fakewriter task started");
set_user_nice(current, 19);
do {
schedule_timeout_uninterruptible(1 + rcu_random(&rand)%10);
udelay(rcu_random(&rand) & 0x3ff);
if (cur_ops->cb_barrier != NULL &&
rcu_random(&rand) % (nfakewriters * 8) == 0)
cur_ops->cb_barrier();
else
cur_ops->sync();
rcu_stutter_wait("rcu_torture_fakewriter");
} while (!kthread_should_stop() && fullstop == FULLSTOP_DONTSTOP);
VERBOSE_PRINTK_STRING("rcu_torture_fakewriter task stopping");
rcutorture_shutdown_absorb("rcu_torture_fakewriter");
while (!kthread_should_stop())
schedule_timeout_uninterruptible(1);
return 0;
}
void rcutorture_trace_dump(void)
{
static atomic_t beenhere = ATOMIC_INIT(0);
if (atomic_read(&beenhere))
return;
if (atomic_xchg(&beenhere, 1) != 0)
return;
ftrace_dump(DUMP_ALL);
}
static void rcu_torture_timer(unsigned long unused)
{
int idx;
int completed;
int completed_end;
static DEFINE_RCU_RANDOM(rand);
static DEFINE_SPINLOCK(rand_lock);
struct rcu_torture *p;
int pipe_count;
unsigned long long ts;
idx = cur_ops->readlock();
completed = cur_ops->completed();
ts = rcu_trace_clock_local();
p = rcu_dereference_check(rcu_torture_current,
rcu_read_lock_bh_held() ||
rcu_read_lock_sched_held() ||
srcu_read_lock_held(&srcu_ctl));
if (p == NULL) {
cur_ops->readunlock(idx);
return;
}
if (p->rtort_mbtest == 0)
atomic_inc(&n_rcu_torture_mberror);
spin_lock(&rand_lock);
cur_ops->read_delay(&rand);
n_rcu_torture_timers++;
spin_unlock(&rand_lock);
preempt_disable();
pipe_count = p->rtort_pipe_count;
if (pipe_count > RCU_TORTURE_PIPE_LEN) {
pipe_count = RCU_TORTURE_PIPE_LEN;
}
completed_end = cur_ops->completed();
if (pipe_count > 1) {
do_trace_rcu_torture_read(cur_ops->name, &p->rtort_rcu, ts,
completed, completed_end);
rcutorture_trace_dump();
}
__this_cpu_inc(rcu_torture_count[pipe_count]);
completed = completed_end - completed;
if (completed > RCU_TORTURE_PIPE_LEN) {
completed = RCU_TORTURE_PIPE_LEN;
}
__this_cpu_inc(rcu_torture_batch[completed]);
preempt_enable();
cur_ops->readunlock(idx);
}
static int
rcu_torture_reader(void *arg)
{
int completed;
int completed_end;
int idx;
DEFINE_RCU_RANDOM(rand);
struct rcu_torture *p;
int pipe_count;
struct timer_list t;
unsigned long long ts;
VERBOSE_PRINTK_STRING("rcu_torture_reader task started");
set_user_nice(current, 19);
if (irqreader && cur_ops->irq_capable)
setup_timer_on_stack(&t, rcu_torture_timer, 0);
do {
if (irqreader && cur_ops->irq_capable) {
if (!timer_pending(&t))
mod_timer(&t, jiffies + 1);
}
idx = cur_ops->readlock();
completed = cur_ops->completed();
ts = rcu_trace_clock_local();
p = rcu_dereference_check(rcu_torture_current,
rcu_read_lock_bh_held() ||
rcu_read_lock_sched_held() ||
srcu_read_lock_held(&srcu_ctl));
if (p == NULL) {
cur_ops->readunlock(idx);
schedule_timeout_interruptible(HZ);
continue;
}
if (p->rtort_mbtest == 0)
atomic_inc(&n_rcu_torture_mberror);
cur_ops->read_delay(&rand);
preempt_disable();
pipe_count = p->rtort_pipe_count;
if (pipe_count > RCU_TORTURE_PIPE_LEN) {
pipe_count = RCU_TORTURE_PIPE_LEN;
}
completed_end = cur_ops->completed();
if (pipe_count > 1) {
do_trace_rcu_torture_read(cur_ops->name, &p->rtort_rcu,
ts, completed, completed_end);
rcutorture_trace_dump();
}
__this_cpu_inc(rcu_torture_count[pipe_count]);
completed = completed_end - completed;
if (completed > RCU_TORTURE_PIPE_LEN) {
completed = RCU_TORTURE_PIPE_LEN;
}
__this_cpu_inc(rcu_torture_batch[completed]);
preempt_enable();
cur_ops->readunlock(idx);
schedule();
rcu_stutter_wait("rcu_torture_reader");
} while (!kthread_should_stop() && fullstop == FULLSTOP_DONTSTOP);
VERBOSE_PRINTK_STRING("rcu_torture_reader task stopping");
rcutorture_shutdown_absorb("rcu_torture_reader");
if (irqreader && cur_ops->irq_capable)
del_timer_sync(&t);
while (!kthread_should_stop())
schedule_timeout_uninterruptible(1);
return 0;
}
static int
rcu_torture_printk(char *page)
{
int cnt = 0;
int cpu;
int i;
long pipesummary[RCU_TORTURE_PIPE_LEN + 1] = { 0 };
long batchsummary[RCU_TORTURE_PIPE_LEN + 1] = { 0 };
for_each_possible_cpu(cpu) {
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++) {
pipesummary[i] += per_cpu(rcu_torture_count, cpu)[i];
batchsummary[i] += per_cpu(rcu_torture_batch, cpu)[i];
}
}
for (i = RCU_TORTURE_PIPE_LEN - 1; i >= 0; i--) {
if (pipesummary[i] != 0)
break;
}
cnt += sprintf(&page[cnt], "%s%s ", torture_type, TORTURE_FLAG);
cnt += sprintf(&page[cnt],
"rtc: %p ver: %lu tfle: %d rta: %d rtaf: %d rtf: %d ",
rcu_torture_current,
rcu_torture_current_version,
list_empty(&rcu_torture_freelist),
atomic_read(&n_rcu_torture_alloc),
atomic_read(&n_rcu_torture_alloc_fail),
atomic_read(&n_rcu_torture_free));
cnt += sprintf(&page[cnt], "rtmbe: %d rtbke: %ld rtbre: %ld ",
atomic_read(&n_rcu_torture_mberror),
n_rcu_torture_boost_ktrerror,
n_rcu_torture_boost_rterror);
cnt += sprintf(&page[cnt], "rtbf: %ld rtb: %ld nt: %ld ",
n_rcu_torture_boost_failure,
n_rcu_torture_boosts,
n_rcu_torture_timers);
cnt += sprintf(&page[cnt],
"onoff: %ld/%ld:%ld/%ld %d,%d:%d,%d %lu:%lu (HZ=%d) ",
n_online_successes, n_online_attempts,
n_offline_successes, n_offline_attempts,
min_online, max_online,
min_offline, max_offline,
sum_online, sum_offline, HZ);
cnt += sprintf(&page[cnt], "barrier: %ld/%ld:%ld",
n_barrier_successes,
n_barrier_attempts,
n_rcu_torture_barrier_error);
cnt += sprintf(&page[cnt], "\n%s%s ", torture_type, TORTURE_FLAG);
if (atomic_read(&n_rcu_torture_mberror) != 0 ||
n_rcu_torture_barrier_error != 0 ||
n_rcu_torture_boost_ktrerror != 0 ||
n_rcu_torture_boost_rterror != 0 ||
n_rcu_torture_boost_failure != 0 ||
i > 1) {
cnt += sprintf(&page[cnt], "!!! ");
atomic_inc(&n_rcu_torture_error);
WARN_ON_ONCE(1);
}
cnt += sprintf(&page[cnt], "Reader Pipe: ");
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++)
cnt += sprintf(&page[cnt], " %ld", pipesummary[i]);
cnt += sprintf(&page[cnt], "\n%s%s ", torture_type, TORTURE_FLAG);
cnt += sprintf(&page[cnt], "Reader Batch: ");
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++)
cnt += sprintf(&page[cnt], " %ld", batchsummary[i]);
cnt += sprintf(&page[cnt], "\n%s%s ", torture_type, TORTURE_FLAG);
cnt += sprintf(&page[cnt], "Free-Block Circulation: ");
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++) {
cnt += sprintf(&page[cnt], " %d",
atomic_read(&rcu_torture_wcount[i]));
}
cnt += sprintf(&page[cnt], "\n");
if (cur_ops->stats)
cnt += cur_ops->stats(&page[cnt]);
return cnt;
}
static void
rcu_torture_stats_print(void)
{
int cnt;
cnt = rcu_torture_printk(printk_buf);
pr_alert("%s", printk_buf);
}
static int
rcu_torture_stats(void *arg)
{
VERBOSE_PRINTK_STRING("rcu_torture_stats task started");
do {
schedule_timeout_interruptible(stat_interval * HZ);
rcu_torture_stats_print();
rcutorture_shutdown_absorb("rcu_torture_stats");
} while (!kthread_should_stop());
VERBOSE_PRINTK_STRING("rcu_torture_stats task stopping");
return 0;
}
static void rcu_torture_shuffle_tasks(void)
{
int i;
cpumask_setall(shuffle_tmp_mask);
get_online_cpus();
if (num_online_cpus() == 1) {
put_online_cpus();
return;
}
if (rcu_idle_cpu != -1)
cpumask_clear_cpu(rcu_idle_cpu, shuffle_tmp_mask);
set_cpus_allowed_ptr(current, shuffle_tmp_mask);
if (reader_tasks) {
for (i = 0; i < nrealreaders; i++)
if (reader_tasks[i])
set_cpus_allowed_ptr(reader_tasks[i],
shuffle_tmp_mask);
}
if (fakewriter_tasks) {
for (i = 0; i < nfakewriters; i++)
if (fakewriter_tasks[i])
set_cpus_allowed_ptr(fakewriter_tasks[i],
shuffle_tmp_mask);
}
if (writer_task)
set_cpus_allowed_ptr(writer_task, shuffle_tmp_mask);
if (stats_task)
set_cpus_allowed_ptr(stats_task, shuffle_tmp_mask);
if (stutter_task)
set_cpus_allowed_ptr(stutter_task, shuffle_tmp_mask);
if (fqs_task)
set_cpus_allowed_ptr(fqs_task, shuffle_tmp_mask);
if (shutdown_task)
set_cpus_allowed_ptr(shutdown_task, shuffle_tmp_mask);
#ifdef CONFIG_HOTPLUG_CPU
if (onoff_task)
set_cpus_allowed_ptr(onoff_task, shuffle_tmp_mask);
#endif
if (stall_task)
set_cpus_allowed_ptr(stall_task, shuffle_tmp_mask);
if (barrier_cbs_tasks)
for (i = 0; i < n_barrier_cbs; i++)
if (barrier_cbs_tasks[i])
set_cpus_allowed_ptr(barrier_cbs_tasks[i],
shuffle_tmp_mask);
if (barrier_task)
set_cpus_allowed_ptr(barrier_task, shuffle_tmp_mask);
if (rcu_idle_cpu == -1)
rcu_idle_cpu = num_online_cpus() - 1;
else
rcu_idle_cpu--;
put_online_cpus();
}
static int
rcu_torture_shuffle(void *arg)
{
VERBOSE_PRINTK_STRING("rcu_torture_shuffle task started");
do {
schedule_timeout_interruptible(shuffle_interval * HZ);
rcu_torture_shuffle_tasks();
rcutorture_shutdown_absorb("rcu_torture_shuffle");
} while (!kthread_should_stop());
VERBOSE_PRINTK_STRING("rcu_torture_shuffle task stopping");
return 0;
}
static int
rcu_torture_stutter(void *arg)
{
VERBOSE_PRINTK_STRING("rcu_torture_stutter task started");
do {
schedule_timeout_interruptible(stutter * HZ);
stutter_pause_test = 1;
if (!kthread_should_stop())
schedule_timeout_interruptible(stutter * HZ);
stutter_pause_test = 0;
rcutorture_shutdown_absorb("rcu_torture_stutter");
} while (!kthread_should_stop());
VERBOSE_PRINTK_STRING("rcu_torture_stutter task stopping");
return 0;
}
static inline void
rcu_torture_print_module_parms(struct rcu_torture_ops *cur_ops, char *tag)
{
pr_alert("%s" TORTURE_FLAG
"--- %s: nreaders=%d nfakewriters=%d "
"stat_interval=%d verbose=%d test_no_idle_hz=%d "
"shuffle_interval=%d stutter=%d irqreader=%d "
"fqs_duration=%d fqs_holdoff=%d fqs_stutter=%d "
"test_boost=%d/%d test_boost_interval=%d "
"test_boost_duration=%d shutdown_secs=%d "
"stall_cpu=%d stall_cpu_holdoff=%d "
"n_barrier_cbs=%d "
"onoff_interval=%d onoff_holdoff=%d\n",
torture_type, tag, nrealreaders, nfakewriters,
stat_interval, verbose, test_no_idle_hz, shuffle_interval,
stutter, irqreader, fqs_duration, fqs_holdoff, fqs_stutter,
test_boost, cur_ops->can_boost,
test_boost_interval, test_boost_duration, shutdown_secs,
stall_cpu, stall_cpu_holdoff,
n_barrier_cbs,
onoff_interval, onoff_holdoff);
}
static void rcutorture_booster_cleanup(int cpu)
{
struct task_struct *t;
if (boost_tasks[cpu] == NULL)
return;
mutex_lock(&boost_mutex);
VERBOSE_PRINTK_STRING("Stopping rcu_torture_boost task");
t = boost_tasks[cpu];
boost_tasks[cpu] = NULL;
mutex_unlock(&boost_mutex);
kthread_stop(t);
boost_tasks[cpu] = NULL;
}
static int rcutorture_booster_init(int cpu)
{
int retval;
if (boost_tasks[cpu] != NULL)
return 0;
mutex_lock(&boost_mutex);
VERBOSE_PRINTK_STRING("Creating rcu_torture_boost task");
boost_tasks[cpu] = kthread_create_on_node(rcu_torture_boost, NULL,
cpu_to_node(cpu),
"rcu_torture_boost");
if (IS_ERR(boost_tasks[cpu])) {
retval = PTR_ERR(boost_tasks[cpu]);
VERBOSE_PRINTK_STRING("rcu_torture_boost task create failed");
n_rcu_torture_boost_ktrerror++;
boost_tasks[cpu] = NULL;
mutex_unlock(&boost_mutex);
return retval;
}
kthread_bind(boost_tasks[cpu], cpu);
wake_up_process(boost_tasks[cpu]);
mutex_unlock(&boost_mutex);
return 0;
}
static int
rcu_torture_shutdown(void *arg)
{
long delta;
unsigned long jiffies_snap;
VERBOSE_PRINTK_STRING("rcu_torture_shutdown task started");
jiffies_snap = ACCESS_ONCE(jiffies);
while (ULONG_CMP_LT(jiffies_snap, shutdown_time) &&
!kthread_should_stop()) {
delta = shutdown_time - jiffies_snap;
if (verbose)
pr_alert("%s" TORTURE_FLAG
"rcu_torture_shutdown task: %lu jiffies remaining\n",
torture_type, delta);
schedule_timeout_interruptible(delta);
jiffies_snap = ACCESS_ONCE(jiffies);
}
if (kthread_should_stop()) {
VERBOSE_PRINTK_STRING("rcu_torture_shutdown task stopping");
return 0;
}
VERBOSE_PRINTK_STRING("rcu_torture_shutdown task shutting down system");
shutdown_task = NULL;
rcu_torture_cleanup();
kernel_power_off();
return 0;
}
static int __cpuinit
rcu_torture_onoff(void *arg)
{
int cpu;
unsigned long delta;
int maxcpu = -1;
DEFINE_RCU_RANDOM(rand);
int ret;
unsigned long starttime;
VERBOSE_PRINTK_STRING("rcu_torture_onoff task started");
for_each_online_cpu(cpu)
maxcpu = cpu;
WARN_ON(maxcpu < 0);
if (onoff_holdoff > 0) {
VERBOSE_PRINTK_STRING("rcu_torture_onoff begin holdoff");
schedule_timeout_interruptible(onoff_holdoff * HZ);
VERBOSE_PRINTK_STRING("rcu_torture_onoff end holdoff");
}
while (!kthread_should_stop()) {
cpu = (rcu_random(&rand) >> 4) % (maxcpu + 1);
if (cpu_online(cpu) && cpu_is_hotpluggable(cpu)) {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"rcu_torture_onoff task: offlining %d\n",
torture_type, cpu);
starttime = jiffies;
n_offline_attempts++;
ret = cpu_down(cpu);
if (ret) {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"rcu_torture_onoff task: offline %d failed: errno %d\n",
torture_type, cpu, ret);
} else {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"rcu_torture_onoff task: offlined %d\n",
torture_type, cpu);
n_offline_successes++;
delta = jiffies - starttime;
sum_offline += delta;
if (min_offline < 0) {
min_offline = delta;
max_offline = delta;
}
if (min_offline > delta)
min_offline = delta;
if (max_offline < delta)
max_offline = delta;
}
} else if (cpu_is_hotpluggable(cpu)) {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"rcu_torture_onoff task: onlining %d\n",
torture_type, cpu);
starttime = jiffies;
n_online_attempts++;
if (cpu_up(cpu) == 0) {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"rcu_torture_onoff task: onlined %d\n",
torture_type, cpu);
n_online_successes++;
delta = jiffies - starttime;
sum_online += delta;
if (min_online < 0) {
min_online = delta;
max_online = delta;
}
if (min_online > delta)
min_online = delta;
if (max_online < delta)
max_online = delta;
}
}
schedule_timeout_interruptible(onoff_interval * HZ);
}
VERBOSE_PRINTK_STRING("rcu_torture_onoff task stopping");
return 0;
}
static int __cpuinit
rcu_torture_onoff_init(void)
{
int ret;
if (onoff_interval <= 0)
return 0;
onoff_task = kthread_run(rcu_torture_onoff, NULL, "rcu_torture_onoff");
if (IS_ERR(onoff_task)) {
ret = PTR_ERR(onoff_task);
onoff_task = NULL;
return ret;
}
return 0;
}
static void rcu_torture_onoff_cleanup(void)
{
if (onoff_task == NULL)
return;
VERBOSE_PRINTK_STRING("Stopping rcu_torture_onoff task");
kthread_stop(onoff_task);
onoff_task = NULL;
}
static int
rcu_torture_onoff_init(void)
{
return 0;
}
static void rcu_torture_onoff_cleanup(void)
{
}
static int __cpuinit rcu_torture_stall(void *args)
{
unsigned long stop_at;
VERBOSE_PRINTK_STRING("rcu_torture_stall task started");
if (stall_cpu_holdoff > 0) {
VERBOSE_PRINTK_STRING("rcu_torture_stall begin holdoff");
schedule_timeout_interruptible(stall_cpu_holdoff * HZ);
VERBOSE_PRINTK_STRING("rcu_torture_stall end holdoff");
}
if (!kthread_should_stop()) {
stop_at = get_seconds() + stall_cpu;
pr_alert("rcu_torture_stall start.\n");
rcu_read_lock();
preempt_disable();
while (ULONG_CMP_LT(get_seconds(), stop_at))
continue;
preempt_enable();
rcu_read_unlock();
pr_alert("rcu_torture_stall end.\n");
}
rcutorture_shutdown_absorb("rcu_torture_stall");
while (!kthread_should_stop())
schedule_timeout_interruptible(10 * HZ);
return 0;
}
static int __init rcu_torture_stall_init(void)
{
int ret;
if (stall_cpu <= 0)
return 0;
stall_task = kthread_run(rcu_torture_stall, NULL, "rcu_torture_stall");
if (IS_ERR(stall_task)) {
ret = PTR_ERR(stall_task);
stall_task = NULL;
return ret;
}
return 0;
}
static void rcu_torture_stall_cleanup(void)
{
if (stall_task == NULL)
return;
VERBOSE_PRINTK_STRING("Stopping rcu_torture_stall_task.");
kthread_stop(stall_task);
stall_task = NULL;
}
void rcu_torture_barrier_cbf(struct rcu_head *rcu)
{
atomic_inc(&barrier_cbs_invoked);
}
static int rcu_torture_barrier_cbs(void *arg)
{
long myid = (long)arg;
bool lastphase = 0;
struct rcu_head rcu;
init_rcu_head_on_stack(&rcu);
VERBOSE_PRINTK_STRING("rcu_torture_barrier_cbs task started");
set_user_nice(current, 19);
do {
wait_event(barrier_cbs_wq[myid],
barrier_phase != lastphase ||
kthread_should_stop() ||
fullstop != FULLSTOP_DONTSTOP);
lastphase = barrier_phase;
smp_mb();
if (kthread_should_stop() || fullstop != FULLSTOP_DONTSTOP)
break;
cur_ops->call(&rcu, rcu_torture_barrier_cbf);
if (atomic_dec_and_test(&barrier_cbs_count))
wake_up(&barrier_wq);
} while (!kthread_should_stop() && fullstop == FULLSTOP_DONTSTOP);
VERBOSE_PRINTK_STRING("rcu_torture_barrier_cbs task stopping");
rcutorture_shutdown_absorb("rcu_torture_barrier_cbs");
while (!kthread_should_stop())
schedule_timeout_interruptible(1);
cur_ops->cb_barrier();
destroy_rcu_head_on_stack(&rcu);
return 0;
}
static int rcu_torture_barrier(void *arg)
{
int i;
VERBOSE_PRINTK_STRING("rcu_torture_barrier task starting");
do {
atomic_set(&barrier_cbs_invoked, 0);
atomic_set(&barrier_cbs_count, n_barrier_cbs);
smp_mb();
barrier_phase = !barrier_phase;
for (i = 0; i < n_barrier_cbs; i++)
wake_up(&barrier_cbs_wq[i]);
wait_event(barrier_wq,
atomic_read(&barrier_cbs_count) == 0 ||
kthread_should_stop() ||
fullstop != FULLSTOP_DONTSTOP);
if (kthread_should_stop() || fullstop != FULLSTOP_DONTSTOP)
break;
n_barrier_attempts++;
cur_ops->cb_barrier();
if (atomic_read(&barrier_cbs_invoked) != n_barrier_cbs) {
n_rcu_torture_barrier_error++;
WARN_ON_ONCE(1);
}
n_barrier_successes++;
schedule_timeout_interruptible(HZ / 10);
} while (!kthread_should_stop() && fullstop == FULLSTOP_DONTSTOP);
VERBOSE_PRINTK_STRING("rcu_torture_barrier task stopping");
rcutorture_shutdown_absorb("rcu_torture_barrier");
while (!kthread_should_stop())
schedule_timeout_interruptible(1);
return 0;
}
static int rcu_torture_barrier_init(void)
{
int i;
int ret;
if (n_barrier_cbs == 0)
return 0;
if (cur_ops->call == NULL || cur_ops->cb_barrier == NULL) {
pr_alert("%s" TORTURE_FLAG
" Call or barrier ops missing for %s,\n",
torture_type, cur_ops->name);
pr_alert("%s" TORTURE_FLAG
" RCU barrier testing omitted from run.\n",
torture_type);
return 0;
}
atomic_set(&barrier_cbs_count, 0);
atomic_set(&barrier_cbs_invoked, 0);
barrier_cbs_tasks =
kzalloc(n_barrier_cbs * sizeof(barrier_cbs_tasks[0]),
GFP_KERNEL);
barrier_cbs_wq =
kzalloc(n_barrier_cbs * sizeof(barrier_cbs_wq[0]),
GFP_KERNEL);
if (barrier_cbs_tasks == NULL || !barrier_cbs_wq)
return -ENOMEM;
for (i = 0; i < n_barrier_cbs; i++) {
init_waitqueue_head(&barrier_cbs_wq[i]);
barrier_cbs_tasks[i] = kthread_run(rcu_torture_barrier_cbs,
(void *)(long)i,
"rcu_torture_barrier_cbs");
if (IS_ERR(barrier_cbs_tasks[i])) {
ret = PTR_ERR(barrier_cbs_tasks[i]);
VERBOSE_PRINTK_ERRSTRING("Failed to create rcu_torture_barrier_cbs");
barrier_cbs_tasks[i] = NULL;
return ret;
}
}
barrier_task = kthread_run(rcu_torture_barrier, NULL,
"rcu_torture_barrier");
if (IS_ERR(barrier_task)) {
ret = PTR_ERR(barrier_task);
VERBOSE_PRINTK_ERRSTRING("Failed to create rcu_torture_barrier");
barrier_task = NULL;
}
return 0;
}
static void rcu_torture_barrier_cleanup(void)
{
int i;
if (barrier_task != NULL) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_barrier task");
kthread_stop(barrier_task);
barrier_task = NULL;
}
if (barrier_cbs_tasks != NULL) {
for (i = 0; i < n_barrier_cbs; i++) {
if (barrier_cbs_tasks[i] != NULL) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_barrier_cbs task");
kthread_stop(barrier_cbs_tasks[i]);
barrier_cbs_tasks[i] = NULL;
}
}
kfree(barrier_cbs_tasks);
barrier_cbs_tasks = NULL;
}
if (barrier_cbs_wq != NULL) {
kfree(barrier_cbs_wq);
barrier_cbs_wq = NULL;
}
}
static int rcutorture_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
long cpu = (long)hcpu;
switch (action) {
case CPU_ONLINE:
case CPU_DOWN_FAILED:
(void)rcutorture_booster_init(cpu);
break;
case CPU_DOWN_PREPARE:
rcutorture_booster_cleanup(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static void
rcu_torture_cleanup(void)
{
int i;
mutex_lock(&fullstop_mutex);
rcutorture_record_test_transition();
if (fullstop == FULLSTOP_SHUTDOWN) {
pr_warn(
"Concurrent 'rmmod rcutorture' and shutdown illegal!\n");
mutex_unlock(&fullstop_mutex);
schedule_timeout_uninterruptible(10);
if (cur_ops->cb_barrier != NULL)
cur_ops->cb_barrier();
return;
}
fullstop = FULLSTOP_RMMOD;
mutex_unlock(&fullstop_mutex);
unregister_reboot_notifier(&rcutorture_shutdown_nb);
rcu_torture_barrier_cleanup();
rcu_torture_stall_cleanup();
if (stutter_task) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_stutter task");
kthread_stop(stutter_task);
}
stutter_task = NULL;
if (shuffler_task) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_shuffle task");
kthread_stop(shuffler_task);
free_cpumask_var(shuffle_tmp_mask);
}
shuffler_task = NULL;
if (writer_task) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_writer task");
kthread_stop(writer_task);
}
writer_task = NULL;
if (reader_tasks) {
for (i = 0; i < nrealreaders; i++) {
if (reader_tasks[i]) {
VERBOSE_PRINTK_STRING(
"Stopping rcu_torture_reader task");
kthread_stop(reader_tasks[i]);
}
reader_tasks[i] = NULL;
}
kfree(reader_tasks);
reader_tasks = NULL;
}
rcu_torture_current = NULL;
if (fakewriter_tasks) {
for (i = 0; i < nfakewriters; i++) {
if (fakewriter_tasks[i]) {
VERBOSE_PRINTK_STRING(
"Stopping rcu_torture_fakewriter task");
kthread_stop(fakewriter_tasks[i]);
}
fakewriter_tasks[i] = NULL;
}
kfree(fakewriter_tasks);
fakewriter_tasks = NULL;
}
if (stats_task) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_stats task");
kthread_stop(stats_task);
}
stats_task = NULL;
if (fqs_task) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_fqs task");
kthread_stop(fqs_task);
}
fqs_task = NULL;
if ((test_boost == 1 && cur_ops->can_boost) ||
test_boost == 2) {
unregister_cpu_notifier(&rcutorture_cpu_nb);
for_each_possible_cpu(i)
rcutorture_booster_cleanup(i);
}
if (shutdown_task != NULL) {
VERBOSE_PRINTK_STRING("Stopping rcu_torture_shutdown task");
kthread_stop(shutdown_task);
}
shutdown_task = NULL;
rcu_torture_onoff_cleanup();
if (cur_ops->cb_barrier != NULL)
cur_ops->cb_barrier();
rcu_torture_stats_print();
if (atomic_read(&n_rcu_torture_error) || n_rcu_torture_barrier_error)
rcu_torture_print_module_parms(cur_ops, "End of test: FAILURE");
else if (n_online_successes != n_online_attempts ||
n_offline_successes != n_offline_attempts)
rcu_torture_print_module_parms(cur_ops,
"End of test: RCU_HOTPLUG");
else
rcu_torture_print_module_parms(cur_ops, "End of test: SUCCESS");
}
static int __init
rcu_torture_init(void)
{
int i;
int cpu;
int firsterr = 0;
int retval;
static struct rcu_torture_ops *torture_ops[] =
{ &rcu_ops, &rcu_sync_ops, &rcu_expedited_ops,
&rcu_bh_ops, &rcu_bh_sync_ops, &rcu_bh_expedited_ops,
&srcu_ops, &srcu_sync_ops, &srcu_expedited_ops,
&srcu_raw_ops, &srcu_raw_sync_ops,
&sched_ops, &sched_sync_ops, &sched_expedited_ops, };
mutex_lock(&fullstop_mutex);
for (i = 0; i < ARRAY_SIZE(torture_ops); i++) {
cur_ops = torture_ops[i];
if (strcmp(torture_type, cur_ops->name) == 0)
break;
}
if (i == ARRAY_SIZE(torture_ops)) {
pr_alert("rcu-torture: invalid torture type: \"%s\"\n",
torture_type);
pr_alert("rcu-torture types:");
for (i = 0; i < ARRAY_SIZE(torture_ops); i++)
pr_alert(" %s", torture_ops[i]->name);
pr_alert("\n");
mutex_unlock(&fullstop_mutex);
return -EINVAL;
}
if (cur_ops->fqs == NULL && fqs_duration != 0) {
pr_alert("rcu-torture: ->fqs NULL and non-zero fqs_duration, fqs disabled.\n");
fqs_duration = 0;
}
if (cur_ops->init)
cur_ops->init();
if (nreaders >= 0)
nrealreaders = nreaders;
else
nrealreaders = 2 * num_online_cpus();
rcu_torture_print_module_parms(cur_ops, "Start of test");
fullstop = FULLSTOP_DONTSTOP;
INIT_LIST_HEAD(&rcu_torture_freelist);
for (i = 0; i < ARRAY_SIZE(rcu_tortures); i++) {
rcu_tortures[i].rtort_mbtest = 0;
list_add_tail(&rcu_tortures[i].rtort_free,
&rcu_torture_freelist);
}
rcu_torture_current = NULL;
rcu_torture_current_version = 0;
atomic_set(&n_rcu_torture_alloc, 0);
atomic_set(&n_rcu_torture_alloc_fail, 0);
atomic_set(&n_rcu_torture_free, 0);
atomic_set(&n_rcu_torture_mberror, 0);
atomic_set(&n_rcu_torture_error, 0);
n_rcu_torture_barrier_error = 0;
n_rcu_torture_boost_ktrerror = 0;
n_rcu_torture_boost_rterror = 0;
n_rcu_torture_boost_failure = 0;
n_rcu_torture_boosts = 0;
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++)
atomic_set(&rcu_torture_wcount[i], 0);
for_each_possible_cpu(cpu) {
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++) {
per_cpu(rcu_torture_count, cpu)[i] = 0;
per_cpu(rcu_torture_batch, cpu)[i] = 0;
}
}
VERBOSE_PRINTK_STRING("Creating rcu_torture_writer task");
writer_task = kthread_create(rcu_torture_writer, NULL,
"rcu_torture_writer");
if (IS_ERR(writer_task)) {
firsterr = PTR_ERR(writer_task);
VERBOSE_PRINTK_ERRSTRING("Failed to create writer");
writer_task = NULL;
goto unwind;
}
wake_up_process(writer_task);
fakewriter_tasks = kzalloc(nfakewriters * sizeof(fakewriter_tasks[0]),
GFP_KERNEL);
if (fakewriter_tasks == NULL) {
VERBOSE_PRINTK_ERRSTRING("out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < nfakewriters; i++) {
VERBOSE_PRINTK_STRING("Creating rcu_torture_fakewriter task");
fakewriter_tasks[i] = kthread_run(rcu_torture_fakewriter, NULL,
"rcu_torture_fakewriter");
if (IS_ERR(fakewriter_tasks[i])) {
firsterr = PTR_ERR(fakewriter_tasks[i]);
VERBOSE_PRINTK_ERRSTRING("Failed to create fakewriter");
fakewriter_tasks[i] = NULL;
goto unwind;
}
}
reader_tasks = kzalloc(nrealreaders * sizeof(reader_tasks[0]),
GFP_KERNEL);
if (reader_tasks == NULL) {
VERBOSE_PRINTK_ERRSTRING("out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < nrealreaders; i++) {
VERBOSE_PRINTK_STRING("Creating rcu_torture_reader task");
reader_tasks[i] = kthread_run(rcu_torture_reader, NULL,
"rcu_torture_reader");
if (IS_ERR(reader_tasks[i])) {
firsterr = PTR_ERR(reader_tasks[i]);
VERBOSE_PRINTK_ERRSTRING("Failed to create reader");
reader_tasks[i] = NULL;
goto unwind;
}
}
if (stat_interval > 0) {
VERBOSE_PRINTK_STRING("Creating rcu_torture_stats task");
stats_task = kthread_run(rcu_torture_stats, NULL,
"rcu_torture_stats");
if (IS_ERR(stats_task)) {
firsterr = PTR_ERR(stats_task);
VERBOSE_PRINTK_ERRSTRING("Failed to create stats");
stats_task = NULL;
goto unwind;
}
}
if (test_no_idle_hz) {
rcu_idle_cpu = num_online_cpus() - 1;
if (!alloc_cpumask_var(&shuffle_tmp_mask, GFP_KERNEL)) {
firsterr = -ENOMEM;
VERBOSE_PRINTK_ERRSTRING("Failed to alloc mask");
goto unwind;
}
shuffler_task = kthread_run(rcu_torture_shuffle, NULL,
"rcu_torture_shuffle");
if (IS_ERR(shuffler_task)) {
free_cpumask_var(shuffle_tmp_mask);
firsterr = PTR_ERR(shuffler_task);
VERBOSE_PRINTK_ERRSTRING("Failed to create shuffler");
shuffler_task = NULL;
goto unwind;
}
}
if (stutter < 0)
stutter = 0;
if (stutter) {
stutter_task = kthread_run(rcu_torture_stutter, NULL,
"rcu_torture_stutter");
if (IS_ERR(stutter_task)) {
firsterr = PTR_ERR(stutter_task);
VERBOSE_PRINTK_ERRSTRING("Failed to create stutter");
stutter_task = NULL;
goto unwind;
}
}
if (fqs_duration < 0)
fqs_duration = 0;
if (fqs_duration) {
fqs_task = kthread_run(rcu_torture_fqs, NULL,
"rcu_torture_fqs");
if (IS_ERR(fqs_task)) {
firsterr = PTR_ERR(fqs_task);
VERBOSE_PRINTK_ERRSTRING("Failed to create fqs");
fqs_task = NULL;
goto unwind;
}
}
if (test_boost_interval < 1)
test_boost_interval = 1;
if (test_boost_duration < 2)
test_boost_duration = 2;
if ((test_boost == 1 && cur_ops->can_boost) ||
test_boost == 2) {
boost_starttime = jiffies + test_boost_interval * HZ;
register_cpu_notifier(&rcutorture_cpu_nb);
for_each_possible_cpu(i) {
if (cpu_is_offline(i))
continue;
retval = rcutorture_booster_init(i);
if (retval < 0) {
firsterr = retval;
goto unwind;
}
}
}
if (shutdown_secs > 0) {
shutdown_time = jiffies + shutdown_secs * HZ;
shutdown_task = kthread_create(rcu_torture_shutdown, NULL,
"rcu_torture_shutdown");
if (IS_ERR(shutdown_task)) {
firsterr = PTR_ERR(shutdown_task);
VERBOSE_PRINTK_ERRSTRING("Failed to create shutdown");
shutdown_task = NULL;
goto unwind;
}
wake_up_process(shutdown_task);
}
i = rcu_torture_onoff_init();
if (i != 0) {
firsterr = i;
goto unwind;
}
register_reboot_notifier(&rcutorture_shutdown_nb);
i = rcu_torture_stall_init();
if (i != 0) {
firsterr = i;
goto unwind;
}
retval = rcu_torture_barrier_init();
if (retval != 0) {
firsterr = retval;
goto unwind;
}
rcutorture_record_test_transition();
mutex_unlock(&fullstop_mutex);
return 0;
unwind:
mutex_unlock(&fullstop_mutex);
rcu_torture_cleanup();
return firsterr;
}
