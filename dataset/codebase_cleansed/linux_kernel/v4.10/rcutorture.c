static const char *rcu_torture_writer_state_getname(void)
{
unsigned int i = READ_ONCE(rcu_torture_writer_state);
if (i >= ARRAY_SIZE(rcu_torture_writer_state_names))
return "???";
return rcu_torture_writer_state_names[i];
}
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
static int rcu_torture_read_lock(void) __acquires(RCU)
{
rcu_read_lock();
return 0;
}
static void rcu_read_delay(struct torture_random_state *rrsp)
{
unsigned long started;
unsigned long completed;
const unsigned long shortdelay_us = 200;
const unsigned long longdelay_ms = 50;
unsigned long long ts;
if (!(torture_random(rrsp) % (nrealreaders * 2000 * longdelay_ms))) {
started = cur_ops->completed();
ts = rcu_trace_clock_local();
mdelay(longdelay_ms);
completed = cur_ops->completed();
do_trace_rcu_torture_read(cur_ops->name, NULL, ts,
started, completed);
}
if (!(torture_random(rrsp) % (nrealreaders * 2 * shortdelay_us)))
udelay(shortdelay_us);
#ifdef CONFIG_PREEMPT
if (!preempt_count() &&
!(torture_random(rrsp) % (nrealreaders * 20000)))
preempt_schedule();
#endif
}
static void rcu_torture_read_unlock(int idx) __releases(RCU)
{
rcu_read_unlock();
}
static bool
rcu_torture_pipe_update_one(struct rcu_torture *rp)
{
int i;
i = rp->rtort_pipe_count;
if (i > RCU_TORTURE_PIPE_LEN)
i = RCU_TORTURE_PIPE_LEN;
atomic_inc(&rcu_torture_wcount[i]);
if (++rp->rtort_pipe_count >= RCU_TORTURE_PIPE_LEN) {
rp->rtort_mbtest = 0;
return true;
}
return false;
}
static void
rcu_torture_pipe_update(struct rcu_torture *old_rp)
{
struct rcu_torture *rp;
struct rcu_torture *rp1;
if (old_rp)
list_add(&old_rp->rtort_free, &rcu_torture_removed);
list_for_each_entry_safe(rp, rp1, &rcu_torture_removed, rtort_free) {
if (rcu_torture_pipe_update_one(rp)) {
list_del(&rp->rtort_free);
rcu_torture_free(rp);
}
}
}
static void
rcu_torture_cb(struct rcu_head *p)
{
struct rcu_torture *rp = container_of(p, struct rcu_torture, rtort_rcu);
if (torture_must_stop_irq()) {
return;
}
if (rcu_torture_pipe_update_one(rp))
rcu_torture_free(rp);
else
cur_ops->deferred_free(rp);
}
static unsigned long rcu_no_completed(void)
{
return 0;
}
static void rcu_torture_deferred_free(struct rcu_torture *p)
{
call_rcu(&p->rtort_rcu, rcu_torture_cb);
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
static void rcu_bh_torture_deferred_free(struct rcu_torture *p)
{
call_rcu_bh(&p->rtort_rcu, rcu_torture_cb);
}
static void rcu_busted_torture_deferred_free(struct rcu_torture *p)
{
rcu_torture_cb(&p->rtort_rcu);
}
static void synchronize_rcu_busted(void)
{
}
static void
call_rcu_busted(struct rcu_head *head, rcu_callback_t func)
{
func(head);
}
static int srcu_torture_read_lock(void) __acquires(srcu_ctlp)
{
return srcu_read_lock(srcu_ctlp);
}
static void srcu_read_delay(struct torture_random_state *rrsp)
{
long delay;
const long uspertick = 1000000 / HZ;
const long longdelay = 10;
delay = torture_random(rrsp) %
(nrealreaders * 2 * longdelay * uspertick);
if (!delay)
schedule_timeout_interruptible(longdelay);
else
rcu_read_delay(rrsp);
}
static void srcu_torture_read_unlock(int idx) __releases(srcu_ctlp)
{
srcu_read_unlock(srcu_ctlp, idx);
}
static unsigned long srcu_torture_completed(void)
{
return srcu_batches_completed(srcu_ctlp);
}
static void srcu_torture_deferred_free(struct rcu_torture *rp)
{
call_srcu(srcu_ctlp, &rp->rtort_rcu, rcu_torture_cb);
}
static void srcu_torture_synchronize(void)
{
synchronize_srcu(srcu_ctlp);
}
static void srcu_torture_call(struct rcu_head *head,
rcu_callback_t func)
{
call_srcu(srcu_ctlp, head, func);
}
static void srcu_torture_barrier(void)
{
srcu_barrier(srcu_ctlp);
}
static void srcu_torture_stats(void)
{
int cpu;
int idx = srcu_ctlp->completed & 0x1;
pr_alert("%s%s per-CPU(idx=%d):",
torture_type, TORTURE_FLAG, idx);
for_each_possible_cpu(cpu) {
long c0, c1;
c0 = (long)per_cpu_ptr(srcu_ctlp->per_cpu_ref, cpu)->c[!idx];
c1 = (long)per_cpu_ptr(srcu_ctlp->per_cpu_ref, cpu)->c[idx];
pr_cont(" %d(%ld,%ld)", cpu, c0, c1);
}
pr_cont("\n");
}
static void srcu_torture_synchronize_expedited(void)
{
synchronize_srcu_expedited(srcu_ctlp);
}
static void srcu_torture_init(void)
{
rcu_sync_torture_init();
WARN_ON(init_srcu_struct(&srcu_ctld));
srcu_ctlp = &srcu_ctld;
}
static void srcu_torture_cleanup(void)
{
cleanup_srcu_struct(&srcu_ctld);
srcu_ctlp = &srcu_ctl;
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
static int tasks_torture_read_lock(void)
{
return 0;
}
static void tasks_torture_read_unlock(int idx)
{
}
static void rcu_tasks_torture_deferred_free(struct rcu_torture *p)
{
call_rcu_tasks(&p->rtort_rcu, rcu_torture_cb);
}
static bool __maybe_unused torturing_tasks(void)
{
return cur_ops == &tasks_ops;
}
static bool __maybe_unused torturing_tasks(void)
{
return false;
}
static void rcu_torture_boost_cb(struct rcu_head *head)
{
struct rcu_boost_inflight *rbip =
container_of(head, struct rcu_boost_inflight, rcu);
smp_store_release(&rbip->inflight, 0);
}
static int rcu_torture_boost(void *arg)
{
unsigned long call_rcu_time;
unsigned long endtime;
unsigned long oldstarttime;
struct rcu_boost_inflight rbi = { .inflight = 0 };
struct sched_param sp;
VERBOSE_TOROUT_STRING("rcu_torture_boost started");
sp.sched_priority = 1;
if (sched_setscheduler(current, SCHED_FIFO, &sp) < 0) {
VERBOSE_TOROUT_STRING("rcu_torture_boost RT prio failed!");
n_rcu_torture_boost_rterror++;
}
init_rcu_head_on_stack(&rbi.rcu);
do {
oldstarttime = boost_starttime;
while (ULONG_CMP_LT(jiffies, oldstarttime)) {
schedule_timeout_interruptible(oldstarttime - jiffies);
stutter_wait("rcu_torture_boost");
if (torture_must_stop())
goto checkwait;
}
endtime = oldstarttime + test_boost_duration * HZ;
call_rcu_time = jiffies;
while (ULONG_CMP_LT(jiffies, endtime)) {
if (!smp_load_acquire(&rbi.inflight)) {
smp_store_release(&rbi.inflight, 1);
call_rcu(&rbi.rcu, rcu_torture_boost_cb);
if (jiffies - call_rcu_time >
test_boost_duration * HZ - HZ / 2) {
VERBOSE_TOROUT_STRING("rcu_torture_boost boosting failed");
n_rcu_torture_boost_failure++;
}
call_rcu_time = jiffies;
}
stutter_wait("rcu_torture_boost");
if (torture_must_stop())
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
checkwait: stutter_wait("rcu_torture_boost");
} while (!torture_must_stop());
while (!kthread_should_stop() || smp_load_acquire(&rbi.inflight)) {
torture_shutdown_absorb("rcu_torture_boost");
schedule_timeout_uninterruptible(1);
}
destroy_rcu_head_on_stack(&rbi.rcu);
torture_kthread_stopping("rcu_torture_boost");
return 0;
}
static void rcu_torture_cbflood_cb(struct rcu_head *rhp)
{
}
static int
rcu_torture_cbflood(void *arg)
{
int err = 1;
int i;
int j;
struct rcu_head *rhp;
if (cbflood_n_per_burst > 0 &&
cbflood_inter_holdoff > 0 &&
cbflood_intra_holdoff > 0 &&
cur_ops->call &&
cur_ops->cb_barrier) {
rhp = vmalloc(sizeof(*rhp) *
cbflood_n_burst * cbflood_n_per_burst);
err = !rhp;
}
if (err) {
VERBOSE_TOROUT_STRING("rcu_torture_cbflood disabled: Bad args or OOM");
goto wait_for_stop;
}
VERBOSE_TOROUT_STRING("rcu_torture_cbflood task started");
do {
schedule_timeout_interruptible(cbflood_inter_holdoff);
atomic_long_inc(&n_cbfloods);
WARN_ON(signal_pending(current));
for (i = 0; i < cbflood_n_burst; i++) {
for (j = 0; j < cbflood_n_per_burst; j++) {
cur_ops->call(&rhp[i * cbflood_n_per_burst + j],
rcu_torture_cbflood_cb);
}
schedule_timeout_interruptible(cbflood_intra_holdoff);
WARN_ON(signal_pending(current));
}
cur_ops->cb_barrier();
stutter_wait("rcu_torture_cbflood");
} while (!torture_must_stop());
vfree(rhp);
wait_for_stop:
torture_kthread_stopping("rcu_torture_cbflood");
return 0;
}
static int
rcu_torture_fqs(void *arg)
{
unsigned long fqs_resume_time;
int fqs_burst_remaining;
VERBOSE_TOROUT_STRING("rcu_torture_fqs task started");
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
stutter_wait("rcu_torture_fqs");
} while (!torture_must_stop());
torture_kthread_stopping("rcu_torture_fqs");
return 0;
}
static int
rcu_torture_writer(void *arg)
{
bool can_expedite = !rcu_gp_is_expedited() && !rcu_gp_is_normal();
int expediting = 0;
unsigned long gp_snap;
bool gp_cond1 = gp_cond, gp_exp1 = gp_exp, gp_normal1 = gp_normal;
bool gp_sync1 = gp_sync;
int i;
struct rcu_torture *rp;
struct rcu_torture *old_rp;
static DEFINE_TORTURE_RANDOM(rand);
int synctype[] = { RTWS_DEF_FREE, RTWS_EXP_SYNC,
RTWS_COND_GET, RTWS_SYNC };
int nsynctypes = 0;
VERBOSE_TOROUT_STRING("rcu_torture_writer task started");
if (!can_expedite) {
pr_alert("%s" TORTURE_FLAG
" GP expediting controlled from boot/sysfs for %s,\n",
torture_type, cur_ops->name);
pr_alert("%s" TORTURE_FLAG
" Disabled dynamic grace-period expediting.\n",
torture_type);
}
if (!gp_cond1 && !gp_exp1 && !gp_normal1 && !gp_sync1)
gp_cond1 = gp_exp1 = gp_normal1 = gp_sync1 = true;
if (gp_cond1 && cur_ops->get_state && cur_ops->cond_sync)
synctype[nsynctypes++] = RTWS_COND_GET;
else if (gp_cond && (!cur_ops->get_state || !cur_ops->cond_sync))
pr_alert("rcu_torture_writer: gp_cond without primitives.\n");
if (gp_exp1 && cur_ops->exp_sync)
synctype[nsynctypes++] = RTWS_EXP_SYNC;
else if (gp_exp && !cur_ops->exp_sync)
pr_alert("rcu_torture_writer: gp_exp without primitives.\n");
if (gp_normal1 && cur_ops->deferred_free)
synctype[nsynctypes++] = RTWS_DEF_FREE;
else if (gp_normal && !cur_ops->deferred_free)
pr_alert("rcu_torture_writer: gp_normal without primitives.\n");
if (gp_sync1 && cur_ops->sync)
synctype[nsynctypes++] = RTWS_SYNC;
else if (gp_sync && !cur_ops->sync)
pr_alert("rcu_torture_writer: gp_sync without primitives.\n");
if (WARN_ONCE(nsynctypes == 0,
"rcu_torture_writer: No update-side primitives.\n")) {
rcu_torture_writer_state = RTWS_STOPPING;
torture_kthread_stopping("rcu_torture_writer");
}
do {
rcu_torture_writer_state = RTWS_FIXED_DELAY;
schedule_timeout_uninterruptible(1);
rp = rcu_torture_alloc();
if (rp == NULL)
continue;
rp->rtort_pipe_count = 0;
rcu_torture_writer_state = RTWS_DELAY;
udelay(torture_random(&rand) & 0x3ff);
rcu_torture_writer_state = RTWS_REPLACE;
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
switch (synctype[torture_random(&rand) % nsynctypes]) {
case RTWS_DEF_FREE:
rcu_torture_writer_state = RTWS_DEF_FREE;
cur_ops->deferred_free(old_rp);
break;
case RTWS_EXP_SYNC:
rcu_torture_writer_state = RTWS_EXP_SYNC;
cur_ops->exp_sync();
rcu_torture_pipe_update(old_rp);
break;
case RTWS_COND_GET:
rcu_torture_writer_state = RTWS_COND_GET;
gp_snap = cur_ops->get_state();
i = torture_random(&rand) % 16;
if (i != 0)
schedule_timeout_interruptible(i);
udelay(torture_random(&rand) % 1000);
rcu_torture_writer_state = RTWS_COND_SYNC;
cur_ops->cond_sync(gp_snap);
rcu_torture_pipe_update(old_rp);
break;
case RTWS_SYNC:
rcu_torture_writer_state = RTWS_SYNC;
cur_ops->sync();
rcu_torture_pipe_update(old_rp);
break;
default:
WARN_ON_ONCE(1);
break;
}
}
rcutorture_record_progress(++rcu_torture_current_version);
if (can_expedite &&
!(torture_random(&rand) & 0xff & (!!expediting - 1))) {
WARN_ON_ONCE(expediting == 0 && rcu_gp_is_expedited());
if (expediting >= 0)
rcu_expedite_gp();
else
rcu_unexpedite_gp();
if (++expediting > 3)
expediting = -expediting;
}
rcu_torture_writer_state = RTWS_STUTTER;
stutter_wait("rcu_torture_writer");
} while (!torture_must_stop());
if (expediting > 0)
expediting = -expediting;
while (can_expedite && expediting++ < 0)
rcu_unexpedite_gp();
WARN_ON_ONCE(can_expedite && rcu_gp_is_expedited());
rcu_torture_writer_state = RTWS_STOPPING;
torture_kthread_stopping("rcu_torture_writer");
return 0;
}
static int
rcu_torture_fakewriter(void *arg)
{
DEFINE_TORTURE_RANDOM(rand);
VERBOSE_TOROUT_STRING("rcu_torture_fakewriter task started");
set_user_nice(current, MAX_NICE);
do {
schedule_timeout_uninterruptible(1 + torture_random(&rand)%10);
udelay(torture_random(&rand) & 0x3ff);
if (cur_ops->cb_barrier != NULL &&
torture_random(&rand) % (nfakewriters * 8) == 0) {
cur_ops->cb_barrier();
} else if (gp_normal == gp_exp) {
if (torture_random(&rand) & 0x80)
cur_ops->sync();
else
cur_ops->exp_sync();
} else if (gp_normal) {
cur_ops->sync();
} else {
cur_ops->exp_sync();
}
stutter_wait("rcu_torture_fakewriter");
} while (!torture_must_stop());
torture_kthread_stopping("rcu_torture_fakewriter");
return 0;
}
static void rcu_torture_timer(unsigned long unused)
{
int idx;
unsigned long started;
unsigned long completed;
static DEFINE_TORTURE_RANDOM(rand);
static DEFINE_SPINLOCK(rand_lock);
struct rcu_torture *p;
int pipe_count;
unsigned long long ts;
idx = cur_ops->readlock();
if (cur_ops->started)
started = cur_ops->started();
else
started = cur_ops->completed();
ts = rcu_trace_clock_local();
p = rcu_dereference_check(rcu_torture_current,
rcu_read_lock_bh_held() ||
rcu_read_lock_sched_held() ||
srcu_read_lock_held(srcu_ctlp) ||
torturing_tasks());
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
completed = cur_ops->completed();
if (pipe_count > 1) {
do_trace_rcu_torture_read(cur_ops->name, &p->rtort_rcu, ts,
started, completed);
rcu_ftrace_dump(DUMP_ALL);
}
__this_cpu_inc(rcu_torture_count[pipe_count]);
completed = completed - started;
if (cur_ops->started)
completed++;
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
unsigned long started;
unsigned long completed;
int idx;
DEFINE_TORTURE_RANDOM(rand);
struct rcu_torture *p;
int pipe_count;
struct timer_list t;
unsigned long long ts;
VERBOSE_TOROUT_STRING("rcu_torture_reader task started");
set_user_nice(current, MAX_NICE);
if (irqreader && cur_ops->irq_capable)
setup_timer_on_stack(&t, rcu_torture_timer, 0);
do {
if (irqreader && cur_ops->irq_capable) {
if (!timer_pending(&t))
mod_timer(&t, jiffies + 1);
}
idx = cur_ops->readlock();
if (cur_ops->started)
started = cur_ops->started();
else
started = cur_ops->completed();
ts = rcu_trace_clock_local();
p = rcu_dereference_check(rcu_torture_current,
rcu_read_lock_bh_held() ||
rcu_read_lock_sched_held() ||
srcu_read_lock_held(srcu_ctlp) ||
torturing_tasks());
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
completed = cur_ops->completed();
if (pipe_count > 1) {
do_trace_rcu_torture_read(cur_ops->name, &p->rtort_rcu,
ts, started, completed);
rcu_ftrace_dump(DUMP_ALL);
}
__this_cpu_inc(rcu_torture_count[pipe_count]);
completed = completed - started;
if (cur_ops->started)
completed++;
if (completed > RCU_TORTURE_PIPE_LEN) {
completed = RCU_TORTURE_PIPE_LEN;
}
__this_cpu_inc(rcu_torture_batch[completed]);
preempt_enable();
cur_ops->readunlock(idx);
stutter_wait("rcu_torture_reader");
} while (!torture_must_stop());
if (irqreader && cur_ops->irq_capable) {
del_timer_sync(&t);
destroy_timer_on_stack(&t);
}
torture_kthread_stopping("rcu_torture_reader");
return 0;
}
static void
rcu_torture_stats_print(void)
{
int cpu;
int i;
long pipesummary[RCU_TORTURE_PIPE_LEN + 1] = { 0 };
long batchsummary[RCU_TORTURE_PIPE_LEN + 1] = { 0 };
static unsigned long rtcv_snap = ULONG_MAX;
struct task_struct *wtp;
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
pr_alert("%s%s ", torture_type, TORTURE_FLAG);
pr_cont("rtc: %p ver: %lu tfle: %d rta: %d rtaf: %d rtf: %d ",
rcu_torture_current,
rcu_torture_current_version,
list_empty(&rcu_torture_freelist),
atomic_read(&n_rcu_torture_alloc),
atomic_read(&n_rcu_torture_alloc_fail),
atomic_read(&n_rcu_torture_free));
pr_cont("rtmbe: %d rtbe: %ld rtbke: %ld rtbre: %ld ",
atomic_read(&n_rcu_torture_mberror),
n_rcu_torture_barrier_error,
n_rcu_torture_boost_ktrerror,
n_rcu_torture_boost_rterror);
pr_cont("rtbf: %ld rtb: %ld nt: %ld ",
n_rcu_torture_boost_failure,
n_rcu_torture_boosts,
n_rcu_torture_timers);
torture_onoff_stats();
pr_cont("barrier: %ld/%ld:%ld ",
n_barrier_successes,
n_barrier_attempts,
n_rcu_torture_barrier_error);
pr_cont("cbflood: %ld\n", atomic_long_read(&n_cbfloods));
pr_alert("%s%s ", torture_type, TORTURE_FLAG);
if (atomic_read(&n_rcu_torture_mberror) != 0 ||
n_rcu_torture_barrier_error != 0 ||
n_rcu_torture_boost_ktrerror != 0 ||
n_rcu_torture_boost_rterror != 0 ||
n_rcu_torture_boost_failure != 0 ||
i > 1) {
pr_cont("%s", "!!! ");
atomic_inc(&n_rcu_torture_error);
WARN_ON_ONCE(1);
}
pr_cont("Reader Pipe: ");
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++)
pr_cont(" %ld", pipesummary[i]);
pr_cont("\n");
pr_alert("%s%s ", torture_type, TORTURE_FLAG);
pr_cont("Reader Batch: ");
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++)
pr_cont(" %ld", batchsummary[i]);
pr_cont("\n");
pr_alert("%s%s ", torture_type, TORTURE_FLAG);
pr_cont("Free-Block Circulation: ");
for (i = 0; i < RCU_TORTURE_PIPE_LEN + 1; i++) {
pr_cont(" %d", atomic_read(&rcu_torture_wcount[i]));
}
pr_cont("\n");
if (cur_ops->stats)
cur_ops->stats();
if (rtcv_snap == rcu_torture_current_version &&
rcu_torture_current != NULL) {
int __maybe_unused flags;
unsigned long __maybe_unused gpnum;
unsigned long __maybe_unused completed;
rcutorture_get_gp_data(cur_ops->ttype,
&flags, &gpnum, &completed);
wtp = READ_ONCE(writer_task);
pr_alert("??? Writer stall state %s(%d) g%lu c%lu f%#x ->state %#lx\n",
rcu_torture_writer_state_getname(),
rcu_torture_writer_state,
gpnum, completed, flags,
wtp == NULL ? ~0UL : wtp->state);
show_rcu_gp_kthreads();
rcu_ftrace_dump(DUMP_ALL);
}
rtcv_snap = rcu_torture_current_version;
}
static int
rcu_torture_stats(void *arg)
{
VERBOSE_TOROUT_STRING("rcu_torture_stats task started");
do {
schedule_timeout_interruptible(stat_interval * HZ);
rcu_torture_stats_print();
torture_shutdown_absorb("rcu_torture_stats");
} while (!torture_must_stop());
torture_kthread_stopping("rcu_torture_stats");
return 0;
}
static inline void
rcu_torture_print_module_parms(struct rcu_torture_ops *cur_ops, const char *tag)
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
static int rcutorture_booster_cleanup(unsigned int cpu)
{
struct task_struct *t;
if (boost_tasks[cpu] == NULL)
return 0;
mutex_lock(&boost_mutex);
t = boost_tasks[cpu];
boost_tasks[cpu] = NULL;
mutex_unlock(&boost_mutex);
torture_stop_kthread(rcu_torture_boost, t);
return 0;
}
static int rcutorture_booster_init(unsigned int cpu)
{
int retval;
if (boost_tasks[cpu] != NULL)
return 0;
mutex_lock(&boost_mutex);
VERBOSE_TOROUT_STRING("Creating rcu_torture_boost task");
boost_tasks[cpu] = kthread_create_on_node(rcu_torture_boost, NULL,
cpu_to_node(cpu),
"rcu_torture_boost");
if (IS_ERR(boost_tasks[cpu])) {
retval = PTR_ERR(boost_tasks[cpu]);
VERBOSE_TOROUT_STRING("rcu_torture_boost task create failed");
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
static int rcu_torture_stall(void *args)
{
unsigned long stop_at;
VERBOSE_TOROUT_STRING("rcu_torture_stall task started");
if (stall_cpu_holdoff > 0) {
VERBOSE_TOROUT_STRING("rcu_torture_stall begin holdoff");
schedule_timeout_interruptible(stall_cpu_holdoff * HZ);
VERBOSE_TOROUT_STRING("rcu_torture_stall end holdoff");
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
torture_shutdown_absorb("rcu_torture_stall");
while (!kthread_should_stop())
schedule_timeout_interruptible(10 * HZ);
return 0;
}
static int __init rcu_torture_stall_init(void)
{
if (stall_cpu <= 0)
return 0;
return torture_create_kthread(rcu_torture_stall, NULL, stall_task);
}
static void rcu_torture_barrier_cbf(struct rcu_head *rcu)
{
atomic_inc(&barrier_cbs_invoked);
}
static int rcu_torture_barrier_cbs(void *arg)
{
long myid = (long)arg;
bool lastphase = 0;
bool newphase;
struct rcu_head rcu;
init_rcu_head_on_stack(&rcu);
VERBOSE_TOROUT_STRING("rcu_torture_barrier_cbs task started");
set_user_nice(current, MAX_NICE);
do {
wait_event(barrier_cbs_wq[myid],
(newphase =
smp_load_acquire(&barrier_phase)) != lastphase ||
torture_must_stop());
lastphase = newphase;
if (torture_must_stop())
break;
local_irq_disable();
cur_ops->call(&rcu, rcu_torture_barrier_cbf);
local_irq_enable();
if (atomic_dec_and_test(&barrier_cbs_count))
wake_up(&barrier_wq);
} while (!torture_must_stop());
if (cur_ops->cb_barrier != NULL)
cur_ops->cb_barrier();
destroy_rcu_head_on_stack(&rcu);
torture_kthread_stopping("rcu_torture_barrier_cbs");
return 0;
}
static int rcu_torture_barrier(void *arg)
{
int i;
VERBOSE_TOROUT_STRING("rcu_torture_barrier task starting");
do {
atomic_set(&barrier_cbs_invoked, 0);
atomic_set(&barrier_cbs_count, n_barrier_cbs);
smp_store_release(&barrier_phase, !barrier_phase);
for (i = 0; i < n_barrier_cbs; i++)
wake_up(&barrier_cbs_wq[i]);
wait_event(barrier_wq,
atomic_read(&barrier_cbs_count) == 0 ||
torture_must_stop());
if (torture_must_stop())
break;
n_barrier_attempts++;
cur_ops->cb_barrier();
if (atomic_read(&barrier_cbs_invoked) != n_barrier_cbs) {
n_rcu_torture_barrier_error++;
pr_err("barrier_cbs_invoked = %d, n_barrier_cbs = %d\n",
atomic_read(&barrier_cbs_invoked),
n_barrier_cbs);
WARN_ON_ONCE(1);
}
n_barrier_successes++;
schedule_timeout_interruptible(HZ / 10);
} while (!torture_must_stop());
torture_kthread_stopping("rcu_torture_barrier");
return 0;
}
static int rcu_torture_barrier_init(void)
{
int i;
int ret;
if (n_barrier_cbs <= 0)
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
ret = torture_create_kthread(rcu_torture_barrier_cbs,
(void *)(long)i,
barrier_cbs_tasks[i]);
if (ret)
return ret;
}
return torture_create_kthread(rcu_torture_barrier, NULL, barrier_task);
}
static void rcu_torture_barrier_cleanup(void)
{
int i;
torture_stop_kthread(rcu_torture_barrier, barrier_task);
if (barrier_cbs_tasks != NULL) {
for (i = 0; i < n_barrier_cbs; i++)
torture_stop_kthread(rcu_torture_barrier_cbs,
barrier_cbs_tasks[i]);
kfree(barrier_cbs_tasks);
barrier_cbs_tasks = NULL;
}
if (barrier_cbs_wq != NULL) {
kfree(barrier_cbs_wq);
barrier_cbs_wq = NULL;
}
}
static void
rcu_torture_cleanup(void)
{
int i;
rcutorture_record_test_transition();
if (torture_cleanup_begin()) {
if (cur_ops->cb_barrier != NULL)
cur_ops->cb_barrier();
return;
}
rcu_torture_barrier_cleanup();
torture_stop_kthread(rcu_torture_stall, stall_task);
torture_stop_kthread(rcu_torture_writer, writer_task);
if (reader_tasks) {
for (i = 0; i < nrealreaders; i++)
torture_stop_kthread(rcu_torture_reader,
reader_tasks[i]);
kfree(reader_tasks);
}
rcu_torture_current = NULL;
if (fakewriter_tasks) {
for (i = 0; i < nfakewriters; i++) {
torture_stop_kthread(rcu_torture_fakewriter,
fakewriter_tasks[i]);
}
kfree(fakewriter_tasks);
fakewriter_tasks = NULL;
}
torture_stop_kthread(rcu_torture_stats, stats_task);
torture_stop_kthread(rcu_torture_fqs, fqs_task);
for (i = 0; i < ncbflooders; i++)
torture_stop_kthread(rcu_torture_cbflood, cbflood_task[i]);
if ((test_boost == 1 && cur_ops->can_boost) ||
test_boost == 2)
cpuhp_remove_state(rcutor_hp);
if (cur_ops->cb_barrier != NULL)
cur_ops->cb_barrier();
if (cur_ops->cleanup != NULL)
cur_ops->cleanup();
rcu_torture_stats_print();
if (atomic_read(&n_rcu_torture_error) || n_rcu_torture_barrier_error)
rcu_torture_print_module_parms(cur_ops, "End of test: FAILURE");
else if (torture_onoff_failures())
rcu_torture_print_module_parms(cur_ops,
"End of test: RCU_HOTPLUG");
else
rcu_torture_print_module_parms(cur_ops, "End of test: SUCCESS");
torture_cleanup_end();
}
static void rcu_torture_leak_cb(struct rcu_head *rhp)
{
}
static void rcu_torture_err_cb(struct rcu_head *rhp)
{
pr_alert("rcutorture: duplicated callback was invoked.\n");
}
static void rcu_test_debug_objects(void)
{
#ifdef CONFIG_DEBUG_OBJECTS_RCU_HEAD
struct rcu_head rh1;
struct rcu_head rh2;
init_rcu_head_on_stack(&rh1);
init_rcu_head_on_stack(&rh2);
pr_alert("rcutorture: WARN: Duplicate call_rcu() test starting.\n");
preempt_disable();
rcu_read_lock();
call_rcu(&rh1, rcu_torture_leak_cb);
local_irq_disable();
call_rcu(&rh2, rcu_torture_leak_cb);
call_rcu(&rh2, rcu_torture_err_cb);
local_irq_enable();
rcu_read_unlock();
preempt_enable();
rcu_barrier();
pr_alert("rcutorture: WARN: Duplicate call_rcu() test complete.\n");
destroy_rcu_head_on_stack(&rh1);
destroy_rcu_head_on_stack(&rh2);
#else
pr_alert("rcutorture: !CONFIG_DEBUG_OBJECTS_RCU_HEAD, not testing duplicate call_rcu()\n");
#endif
}
static int __init
rcu_torture_init(void)
{
int i;
int cpu;
int firsterr = 0;
static struct rcu_torture_ops *torture_ops[] = {
&rcu_ops, &rcu_bh_ops, &rcu_busted_ops, &srcu_ops, &srcud_ops,
&sched_ops, RCUTORTURE_TASKS_OPS
};
if (!torture_init_begin(torture_type, verbose, &torture_runnable))
return -EBUSY;
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
firsterr = -EINVAL;
goto unwind;
}
if (cur_ops->fqs == NULL && fqs_duration != 0) {
pr_alert("rcu-torture: ->fqs NULL and non-zero fqs_duration, fqs disabled.\n");
fqs_duration = 0;
}
if (cur_ops->init)
cur_ops->init();
if (nreaders >= 0) {
nrealreaders = nreaders;
} else {
nrealreaders = num_online_cpus() - 2 - nreaders;
if (nrealreaders <= 0)
nrealreaders = 1;
}
rcu_torture_print_module_parms(cur_ops, "Start of test");
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
firsterr = torture_create_kthread(rcu_torture_writer, NULL,
writer_task);
if (firsterr)
goto unwind;
if (nfakewriters > 0) {
fakewriter_tasks = kzalloc(nfakewriters *
sizeof(fakewriter_tasks[0]),
GFP_KERNEL);
if (fakewriter_tasks == NULL) {
VERBOSE_TOROUT_ERRSTRING("out of memory");
firsterr = -ENOMEM;
goto unwind;
}
}
for (i = 0; i < nfakewriters; i++) {
firsterr = torture_create_kthread(rcu_torture_fakewriter,
NULL, fakewriter_tasks[i]);
if (firsterr)
goto unwind;
}
reader_tasks = kzalloc(nrealreaders * sizeof(reader_tasks[0]),
GFP_KERNEL);
if (reader_tasks == NULL) {
VERBOSE_TOROUT_ERRSTRING("out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < nrealreaders; i++) {
firsterr = torture_create_kthread(rcu_torture_reader, NULL,
reader_tasks[i]);
if (firsterr)
goto unwind;
}
if (stat_interval > 0) {
firsterr = torture_create_kthread(rcu_torture_stats, NULL,
stats_task);
if (firsterr)
goto unwind;
}
if (test_no_idle_hz && shuffle_interval > 0) {
firsterr = torture_shuffle_init(shuffle_interval * HZ);
if (firsterr)
goto unwind;
}
if (stutter < 0)
stutter = 0;
if (stutter) {
firsterr = torture_stutter_init(stutter * HZ);
if (firsterr)
goto unwind;
}
if (fqs_duration < 0)
fqs_duration = 0;
if (fqs_duration) {
firsterr = torture_create_kthread(rcu_torture_fqs, NULL,
fqs_task);
if (firsterr)
goto unwind;
}
if (test_boost_interval < 1)
test_boost_interval = 1;
if (test_boost_duration < 2)
test_boost_duration = 2;
if ((test_boost == 1 && cur_ops->can_boost) ||
test_boost == 2) {
boost_starttime = jiffies + test_boost_interval * HZ;
firsterr = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "RCU_TORTURE",
rcutorture_booster_init,
rcutorture_booster_cleanup);
if (firsterr < 0)
goto unwind;
rcutor_hp = firsterr;
}
firsterr = torture_shutdown_init(shutdown_secs, rcu_torture_cleanup);
if (firsterr)
goto unwind;
firsterr = torture_onoff_init(onoff_holdoff * HZ, onoff_interval * HZ);
if (firsterr)
goto unwind;
firsterr = rcu_torture_stall_init();
if (firsterr)
goto unwind;
firsterr = rcu_torture_barrier_init();
if (firsterr)
goto unwind;
if (object_debug)
rcu_test_debug_objects();
if (cbflood_n_burst > 0) {
ncbflooders = (num_online_cpus() + 3) / 4;
cbflood_task = kcalloc(ncbflooders, sizeof(*cbflood_task),
GFP_KERNEL);
if (!cbflood_task) {
VERBOSE_TOROUT_ERRSTRING("out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < ncbflooders; i++) {
firsterr = torture_create_kthread(rcu_torture_cbflood,
NULL,
cbflood_task[i]);
if (firsterr)
goto unwind;
}
}
rcutorture_record_test_transition();
torture_init_end();
return 0;
unwind:
torture_init_end();
rcu_torture_cleanup();
return firsterr;
}
