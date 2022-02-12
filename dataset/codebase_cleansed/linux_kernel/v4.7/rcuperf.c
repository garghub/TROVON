static int rcu_perf_read_lock(void) __acquires(RCU)
{
rcu_read_lock();
return 0;
}
static void rcu_perf_read_unlock(int idx) __releases(RCU)
{
rcu_read_unlock();
}
static unsigned long __maybe_unused rcu_no_completed(void)
{
return 0;
}
static void rcu_sync_perf_init(void)
{
}
static int rcu_bh_perf_read_lock(void) __acquires(RCU_BH)
{
rcu_read_lock_bh();
return 0;
}
static void rcu_bh_perf_read_unlock(int idx) __releases(RCU_BH)
{
rcu_read_unlock_bh();
}
static int srcu_perf_read_lock(void) __acquires(srcu_ctlp)
{
return srcu_read_lock(srcu_ctlp);
}
static void srcu_perf_read_unlock(int idx) __releases(srcu_ctlp)
{
srcu_read_unlock(srcu_ctlp, idx);
}
static unsigned long srcu_perf_completed(void)
{
return srcu_batches_completed(srcu_ctlp);
}
static void srcu_perf_synchronize(void)
{
synchronize_srcu(srcu_ctlp);
}
static void srcu_perf_synchronize_expedited(void)
{
synchronize_srcu_expedited(srcu_ctlp);
}
static int sched_perf_read_lock(void)
{
preempt_disable();
return 0;
}
static void sched_perf_read_unlock(int idx)
{
preempt_enable();
}
static int tasks_perf_read_lock(void)
{
return 0;
}
static void tasks_perf_read_unlock(int idx)
{
}
static bool __maybe_unused torturing_tasks(void)
{
return cur_ops == &tasks_ops;
}
static bool __maybe_unused torturing_tasks(void)
{
return false;
}
static void rcu_perf_wait_shutdown(void)
{
cond_resched_rcu_qs();
if (atomic_read(&n_rcu_perf_writer_finished) < nrealwriters)
return;
while (!torture_must_stop())
schedule_timeout_uninterruptible(1);
}
static int
rcu_perf_reader(void *arg)
{
unsigned long flags;
int idx;
long me = (long)arg;
VERBOSE_PERFOUT_STRING("rcu_perf_reader task started");
set_cpus_allowed_ptr(current, cpumask_of(me % nr_cpu_ids));
set_user_nice(current, MAX_NICE);
atomic_inc(&n_rcu_perf_reader_started);
do {
local_irq_save(flags);
idx = cur_ops->readlock();
cur_ops->readunlock(idx);
local_irq_restore(flags);
rcu_perf_wait_shutdown();
} while (!torture_must_stop());
torture_kthread_stopping("rcu_perf_reader");
return 0;
}
static int
rcu_perf_writer(void *arg)
{
int i = 0;
int i_max;
long me = (long)arg;
struct sched_param sp;
bool started = false, done = false, alldone = false;
u64 t;
u64 *wdp;
u64 *wdpp = writer_durations[me];
VERBOSE_PERFOUT_STRING("rcu_perf_writer task started");
WARN_ON(rcu_gp_is_expedited() && !rcu_gp_is_normal() && !gp_exp);
WARN_ON(rcu_gp_is_normal() && gp_exp);
WARN_ON(!wdpp);
set_cpus_allowed_ptr(current, cpumask_of(me % nr_cpu_ids));
sp.sched_priority = 1;
sched_setscheduler_nocheck(current, SCHED_FIFO, &sp);
if (holdoff)
schedule_timeout_uninterruptible(holdoff * HZ);
t = ktime_get_mono_fast_ns();
if (atomic_inc_return(&n_rcu_perf_writer_started) >= nrealwriters) {
t_rcu_perf_writer_started = t;
if (gp_exp) {
b_rcu_perf_writer_started =
cur_ops->exp_completed() / 2;
} else {
b_rcu_perf_writer_started =
cur_ops->completed();
}
}
do {
wdp = &wdpp[i];
*wdp = ktime_get_mono_fast_ns();
if (gp_exp) {
rcu_perf_writer_state = RTWS_EXP_SYNC;
cur_ops->exp_sync();
} else {
rcu_perf_writer_state = RTWS_SYNC;
cur_ops->sync();
}
rcu_perf_writer_state = RTWS_IDLE;
t = ktime_get_mono_fast_ns();
*wdp = t - *wdp;
i_max = i;
if (!started &&
atomic_read(&n_rcu_perf_writer_started) >= nrealwriters)
started = true;
if (!done && i >= MIN_MEAS) {
done = true;
sp.sched_priority = 0;
sched_setscheduler_nocheck(current,
SCHED_NORMAL, &sp);
pr_alert("%s" PERF_FLAG
"rcu_perf_writer %ld has %d measurements\n",
perf_type, me, MIN_MEAS);
if (atomic_inc_return(&n_rcu_perf_writer_finished) >=
nrealwriters) {
schedule_timeout_interruptible(10);
rcu_ftrace_dump(DUMP_ALL);
PERFOUT_STRING("Test complete");
t_rcu_perf_writer_finished = t;
if (gp_exp) {
b_rcu_perf_writer_finished =
cur_ops->exp_completed() / 2;
} else {
b_rcu_perf_writer_finished =
cur_ops->completed();
}
if (shutdown) {
smp_mb();
wake_up(&shutdown_wq);
}
}
}
if (done && !alldone &&
atomic_read(&n_rcu_perf_writer_finished) >= nrealwriters)
alldone = true;
if (started && !alldone && i < MAX_MEAS - 1)
i++;
rcu_perf_wait_shutdown();
} while (!torture_must_stop());
rcu_perf_writer_state = RTWS_STOPPING;
writer_n_durations[me] = i_max;
torture_kthread_stopping("rcu_perf_writer");
return 0;
}
static inline void
rcu_perf_print_module_parms(struct rcu_perf_ops *cur_ops, const char *tag)
{
pr_alert("%s" PERF_FLAG
"--- %s: nreaders=%d nwriters=%d verbose=%d shutdown=%d\n",
perf_type, tag, nrealreaders, nrealwriters, verbose, shutdown);
}
static void
rcu_perf_cleanup(void)
{
int i;
int j;
int ngps = 0;
u64 *wdp;
u64 *wdpp;
if (torture_cleanup_begin())
return;
if (reader_tasks) {
for (i = 0; i < nrealreaders; i++)
torture_stop_kthread(rcu_perf_reader,
reader_tasks[i]);
kfree(reader_tasks);
}
if (writer_tasks) {
for (i = 0; i < nrealwriters; i++) {
torture_stop_kthread(rcu_perf_writer,
writer_tasks[i]);
if (!writer_n_durations)
continue;
j = writer_n_durations[i];
pr_alert("%s%s writer %d gps: %d\n",
perf_type, PERF_FLAG, i, j);
ngps += j;
}
pr_alert("%s%s start: %llu end: %llu duration: %llu gps: %d batches: %ld\n",
perf_type, PERF_FLAG,
t_rcu_perf_writer_started, t_rcu_perf_writer_finished,
t_rcu_perf_writer_finished -
t_rcu_perf_writer_started,
ngps,
b_rcu_perf_writer_finished -
b_rcu_perf_writer_started);
for (i = 0; i < nrealwriters; i++) {
if (!writer_durations)
break;
if (!writer_n_durations)
continue;
wdpp = writer_durations[i];
if (!wdpp)
continue;
for (j = 0; j <= writer_n_durations[i]; j++) {
wdp = &wdpp[j];
pr_alert("%s%s %4d writer-duration: %5d %llu\n",
perf_type, PERF_FLAG,
i, j, *wdp);
if (j % 100 == 0)
schedule_timeout_uninterruptible(1);
}
kfree(writer_durations[i]);
}
kfree(writer_tasks);
kfree(writer_durations);
kfree(writer_n_durations);
}
if (cur_ops->cleanup != NULL)
cur_ops->cleanup();
torture_cleanup_end();
}
static int compute_real(int n)
{
int nr;
if (n >= 0) {
nr = n;
} else {
nr = num_online_cpus() + 1 + n;
if (nr <= 0)
nr = 1;
}
return nr;
}
static int
rcu_perf_shutdown(void *arg)
{
do {
wait_event(shutdown_wq,
atomic_read(&n_rcu_perf_writer_finished) >=
nrealwriters);
} while (atomic_read(&n_rcu_perf_writer_finished) < nrealwriters);
smp_mb();
rcu_perf_cleanup();
kernel_power_off();
return -EINVAL;
}
static int __init
rcu_perf_init(void)
{
long i;
int firsterr = 0;
static struct rcu_perf_ops *perf_ops[] = {
&rcu_ops, &rcu_bh_ops, &srcu_ops, &sched_ops,
RCUPERF_TASKS_OPS
};
if (!torture_init_begin(perf_type, verbose, &perf_runnable))
return -EBUSY;
for (i = 0; i < ARRAY_SIZE(perf_ops); i++) {
cur_ops = perf_ops[i];
if (strcmp(perf_type, cur_ops->name) == 0)
break;
}
if (i == ARRAY_SIZE(perf_ops)) {
pr_alert("rcu-perf: invalid perf type: \"%s\"\n",
perf_type);
pr_alert("rcu-perf types:");
for (i = 0; i < ARRAY_SIZE(perf_ops); i++)
pr_alert(" %s", perf_ops[i]->name);
pr_alert("\n");
firsterr = -EINVAL;
goto unwind;
}
if (cur_ops->init)
cur_ops->init();
nrealwriters = compute_real(nwriters);
nrealreaders = compute_real(nreaders);
atomic_set(&n_rcu_perf_reader_started, 0);
atomic_set(&n_rcu_perf_writer_started, 0);
atomic_set(&n_rcu_perf_writer_finished, 0);
rcu_perf_print_module_parms(cur_ops, "Start of test");
if (shutdown) {
init_waitqueue_head(&shutdown_wq);
firsterr = torture_create_kthread(rcu_perf_shutdown, NULL,
shutdown_task);
if (firsterr)
goto unwind;
schedule_timeout_uninterruptible(1);
}
reader_tasks = kcalloc(nrealreaders, sizeof(reader_tasks[0]),
GFP_KERNEL);
if (reader_tasks == NULL) {
VERBOSE_PERFOUT_ERRSTRING("out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < nrealreaders; i++) {
firsterr = torture_create_kthread(rcu_perf_reader, (void *)i,
reader_tasks[i]);
if (firsterr)
goto unwind;
}
while (atomic_read(&n_rcu_perf_reader_started) < nrealreaders)
schedule_timeout_uninterruptible(1);
writer_tasks = kcalloc(nrealwriters, sizeof(reader_tasks[0]),
GFP_KERNEL);
writer_durations = kcalloc(nrealwriters, sizeof(*writer_durations),
GFP_KERNEL);
writer_n_durations =
kcalloc(nrealwriters, sizeof(*writer_n_durations),
GFP_KERNEL);
if (!writer_tasks || !writer_durations || !writer_n_durations) {
VERBOSE_PERFOUT_ERRSTRING("out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < nrealwriters; i++) {
writer_durations[i] =
kcalloc(MAX_MEAS, sizeof(*writer_durations[i]),
GFP_KERNEL);
if (!writer_durations[i])
goto unwind;
firsterr = torture_create_kthread(rcu_perf_writer, (void *)i,
writer_tasks[i]);
if (firsterr)
goto unwind;
}
torture_init_end();
return 0;
unwind:
torture_init_end();
rcu_perf_cleanup();
return firsterr;
}
