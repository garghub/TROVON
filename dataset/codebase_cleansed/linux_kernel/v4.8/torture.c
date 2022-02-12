bool torture_offline(int cpu, long *n_offl_attempts, long *n_offl_successes,
unsigned long *sum_offl, int *min_offl, int *max_offl)
{
unsigned long delta;
int ret;
unsigned long starttime;
if (!cpu_online(cpu) || !cpu_is_hotpluggable(cpu))
return false;
if (verbose)
pr_alert("%s" TORTURE_FLAG
"torture_onoff task: offlining %d\n",
torture_type, cpu);
starttime = jiffies;
(*n_offl_attempts)++;
ret = cpu_down(cpu);
if (ret) {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"torture_onoff task: offline %d failed: errno %d\n",
torture_type, cpu, ret);
} else {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"torture_onoff task: offlined %d\n",
torture_type, cpu);
(*n_offl_successes)++;
delta = jiffies - starttime;
sum_offl += delta;
if (*min_offl < 0) {
*min_offl = delta;
*max_offl = delta;
}
if (*min_offl > delta)
*min_offl = delta;
if (*max_offl < delta)
*max_offl = delta;
}
return true;
}
bool torture_online(int cpu, long *n_onl_attempts, long *n_onl_successes,
unsigned long *sum_onl, int *min_onl, int *max_onl)
{
unsigned long delta;
int ret;
unsigned long starttime;
if (cpu_online(cpu) || !cpu_is_hotpluggable(cpu))
return false;
if (verbose)
pr_alert("%s" TORTURE_FLAG
"torture_onoff task: onlining %d\n",
torture_type, cpu);
starttime = jiffies;
(*n_onl_attempts)++;
ret = cpu_up(cpu);
if (ret) {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"torture_onoff task: online %d failed: errno %d\n",
torture_type, cpu, ret);
} else {
if (verbose)
pr_alert("%s" TORTURE_FLAG
"torture_onoff task: onlined %d\n",
torture_type, cpu);
(*n_onl_successes)++;
delta = jiffies - starttime;
*sum_onl += delta;
if (*min_onl < 0) {
*min_onl = delta;
*max_onl = delta;
}
if (*min_onl > delta)
*min_onl = delta;
if (*max_onl < delta)
*max_onl = delta;
}
return true;
}
static int
torture_onoff(void *arg)
{
int cpu;
int maxcpu = -1;
DEFINE_TORTURE_RANDOM(rand);
VERBOSE_TOROUT_STRING("torture_onoff task started");
for_each_online_cpu(cpu)
maxcpu = cpu;
WARN_ON(maxcpu < 0);
if (maxcpu == 0) {
VERBOSE_TOROUT_STRING("Only one CPU, so CPU-hotplug testing is disabled");
goto stop;
}
if (onoff_holdoff > 0) {
VERBOSE_TOROUT_STRING("torture_onoff begin holdoff");
schedule_timeout_interruptible(onoff_holdoff);
VERBOSE_TOROUT_STRING("torture_onoff end holdoff");
}
while (!torture_must_stop()) {
cpu = (torture_random(&rand) >> 4) % (maxcpu + 1);
if (!torture_offline(cpu,
&n_offline_attempts, &n_offline_successes,
&sum_offline, &min_offline, &max_offline))
torture_online(cpu,
&n_online_attempts, &n_online_successes,
&sum_online, &min_online, &max_online);
schedule_timeout_interruptible(onoff_interval);
}
stop:
torture_kthread_stopping("torture_onoff");
return 0;
}
int torture_onoff_init(long ooholdoff, long oointerval)
{
int ret = 0;
#ifdef CONFIG_HOTPLUG_CPU
onoff_holdoff = ooholdoff;
onoff_interval = oointerval;
if (onoff_interval <= 0)
return 0;
ret = torture_create_kthread(torture_onoff, NULL, onoff_task);
#endif
return ret;
}
static void torture_onoff_cleanup(void)
{
#ifdef CONFIG_HOTPLUG_CPU
if (onoff_task == NULL)
return;
VERBOSE_TOROUT_STRING("Stopping torture_onoff task");
kthread_stop(onoff_task);
onoff_task = NULL;
#endif
}
void torture_onoff_stats(void)
{
#ifdef CONFIG_HOTPLUG_CPU
pr_cont("onoff: %ld/%ld:%ld/%ld %d,%d:%d,%d %lu:%lu (HZ=%d) ",
n_online_successes, n_online_attempts,
n_offline_successes, n_offline_attempts,
min_online, max_online,
min_offline, max_offline,
sum_online, sum_offline, HZ);
#endif
}
bool torture_onoff_failures(void)
{
#ifdef CONFIG_HOTPLUG_CPU
return n_online_successes != n_online_attempts ||
n_offline_successes != n_offline_attempts;
#else
return false;
#endif
}
unsigned long
torture_random(struct torture_random_state *trsp)
{
if (--trsp->trs_count < 0) {
trsp->trs_state += (unsigned long)local_clock();
trsp->trs_count = TORTURE_RANDOM_REFRESH;
}
trsp->trs_state = trsp->trs_state * TORTURE_RANDOM_MULT +
TORTURE_RANDOM_ADD;
return swahw32(trsp->trs_state);
}
void torture_shuffle_task_register(struct task_struct *tp)
{
struct shuffle_task *stp;
if (WARN_ON_ONCE(tp == NULL))
return;
stp = kmalloc(sizeof(*stp), GFP_KERNEL);
if (WARN_ON_ONCE(stp == NULL))
return;
stp->st_t = tp;
mutex_lock(&shuffle_task_mutex);
list_add(&stp->st_l, &shuffle_task_list);
mutex_unlock(&shuffle_task_mutex);
}
static void torture_shuffle_task_unregister_all(void)
{
struct shuffle_task *stp;
struct shuffle_task *p;
mutex_lock(&shuffle_task_mutex);
list_for_each_entry_safe(stp, p, &shuffle_task_list, st_l) {
list_del(&stp->st_l);
kfree(stp);
}
mutex_unlock(&shuffle_task_mutex);
}
static void torture_shuffle_tasks(void)
{
struct shuffle_task *stp;
cpumask_setall(shuffle_tmp_mask);
get_online_cpus();
if (num_online_cpus() == 1) {
put_online_cpus();
return;
}
shuffle_idle_cpu = cpumask_next(shuffle_idle_cpu, shuffle_tmp_mask);
if (shuffle_idle_cpu >= nr_cpu_ids)
shuffle_idle_cpu = -1;
else
cpumask_clear_cpu(shuffle_idle_cpu, shuffle_tmp_mask);
mutex_lock(&shuffle_task_mutex);
list_for_each_entry(stp, &shuffle_task_list, st_l)
set_cpus_allowed_ptr(stp->st_t, shuffle_tmp_mask);
mutex_unlock(&shuffle_task_mutex);
put_online_cpus();
}
static int torture_shuffle(void *arg)
{
VERBOSE_TOROUT_STRING("torture_shuffle task started");
do {
schedule_timeout_interruptible(shuffle_interval);
torture_shuffle_tasks();
torture_shutdown_absorb("torture_shuffle");
} while (!torture_must_stop());
torture_kthread_stopping("torture_shuffle");
return 0;
}
int torture_shuffle_init(long shuffint)
{
shuffle_interval = shuffint;
shuffle_idle_cpu = -1;
if (!alloc_cpumask_var(&shuffle_tmp_mask, GFP_KERNEL)) {
VERBOSE_TOROUT_ERRSTRING("Failed to alloc mask");
return -ENOMEM;
}
return torture_create_kthread(torture_shuffle, NULL, shuffler_task);
}
static void torture_shuffle_cleanup(void)
{
torture_shuffle_task_unregister_all();
if (shuffler_task) {
VERBOSE_TOROUT_STRING("Stopping torture_shuffle task");
kthread_stop(shuffler_task);
free_cpumask_var(shuffle_tmp_mask);
}
shuffler_task = NULL;
}
void torture_shutdown_absorb(const char *title)
{
while (READ_ONCE(fullstop) == FULLSTOP_SHUTDOWN) {
pr_notice("torture thread %s parking due to system shutdown\n",
title);
schedule_timeout_uninterruptible(MAX_SCHEDULE_TIMEOUT);
}
}
static int torture_shutdown(void *arg)
{
long delta;
unsigned long jiffies_snap;
VERBOSE_TOROUT_STRING("torture_shutdown task started");
jiffies_snap = jiffies;
while (ULONG_CMP_LT(jiffies_snap, shutdown_time) &&
!torture_must_stop()) {
delta = shutdown_time - jiffies_snap;
if (verbose)
pr_alert("%s" TORTURE_FLAG
"torture_shutdown task: %lu jiffies remaining\n",
torture_type, delta);
schedule_timeout_interruptible(delta);
jiffies_snap = jiffies;
}
if (torture_must_stop()) {
torture_kthread_stopping("torture_shutdown");
return 0;
}
VERBOSE_TOROUT_STRING("torture_shutdown task shutting down system");
shutdown_task = NULL;
if (torture_shutdown_hook)
torture_shutdown_hook();
else
VERBOSE_TOROUT_STRING("No torture_shutdown_hook(), skipping.");
ftrace_dump(DUMP_ALL);
kernel_power_off();
return 0;
}
int torture_shutdown_init(int ssecs, void (*cleanup)(void))
{
int ret = 0;
shutdown_secs = ssecs;
torture_shutdown_hook = cleanup;
if (shutdown_secs > 0) {
shutdown_time = jiffies + shutdown_secs * HZ;
ret = torture_create_kthread(torture_shutdown, NULL,
shutdown_task);
}
return ret;
}
static int torture_shutdown_notify(struct notifier_block *unused1,
unsigned long unused2, void *unused3)
{
mutex_lock(&fullstop_mutex);
if (READ_ONCE(fullstop) == FULLSTOP_DONTSTOP) {
VERBOSE_TOROUT_STRING("Unscheduled system shutdown detected");
WRITE_ONCE(fullstop, FULLSTOP_SHUTDOWN);
} else {
pr_warn("Concurrent rmmod and shutdown illegal!\n");
}
mutex_unlock(&fullstop_mutex);
return NOTIFY_DONE;
}
static void torture_shutdown_cleanup(void)
{
unregister_reboot_notifier(&torture_shutdown_nb);
if (shutdown_task != NULL) {
VERBOSE_TOROUT_STRING("Stopping torture_shutdown task");
kthread_stop(shutdown_task);
}
shutdown_task = NULL;
}
void stutter_wait(const char *title)
{
cond_resched_rcu_qs();
while (READ_ONCE(stutter_pause_test) ||
(torture_runnable && !READ_ONCE(*torture_runnable))) {
if (stutter_pause_test)
if (READ_ONCE(stutter_pause_test) == 1)
schedule_timeout_interruptible(1);
else
while (READ_ONCE(stutter_pause_test))
cond_resched();
else
schedule_timeout_interruptible(round_jiffies_relative(HZ));
torture_shutdown_absorb(title);
}
}
static int torture_stutter(void *arg)
{
VERBOSE_TOROUT_STRING("torture_stutter task started");
do {
if (!torture_must_stop()) {
if (stutter > 1) {
schedule_timeout_interruptible(stutter - 1);
WRITE_ONCE(stutter_pause_test, 2);
}
schedule_timeout_interruptible(1);
WRITE_ONCE(stutter_pause_test, 1);
}
if (!torture_must_stop())
schedule_timeout_interruptible(stutter);
WRITE_ONCE(stutter_pause_test, 0);
torture_shutdown_absorb("torture_stutter");
} while (!torture_must_stop());
torture_kthread_stopping("torture_stutter");
return 0;
}
int torture_stutter_init(int s)
{
int ret;
stutter = s;
ret = torture_create_kthread(torture_stutter, NULL, stutter_task);
return ret;
}
static void torture_stutter_cleanup(void)
{
if (!stutter_task)
return;
VERBOSE_TOROUT_STRING("Stopping torture_stutter task");
kthread_stop(stutter_task);
stutter_task = NULL;
}
bool torture_init_begin(char *ttype, bool v, int *runnable)
{
mutex_lock(&fullstop_mutex);
if (torture_type != NULL) {
pr_alert("torture_init_begin: Refusing %s init: %s running.\n",
ttype, torture_type);
pr_alert("torture_init_begin: One torture test at a time!\n");
mutex_unlock(&fullstop_mutex);
return false;
}
torture_type = ttype;
verbose = v;
torture_runnable = runnable;
fullstop = FULLSTOP_DONTSTOP;
return true;
}
void torture_init_end(void)
{
mutex_unlock(&fullstop_mutex);
register_reboot_notifier(&torture_shutdown_nb);
}
bool torture_cleanup_begin(void)
{
mutex_lock(&fullstop_mutex);
if (READ_ONCE(fullstop) == FULLSTOP_SHUTDOWN) {
pr_warn("Concurrent rmmod and shutdown illegal!\n");
mutex_unlock(&fullstop_mutex);
schedule_timeout_uninterruptible(10);
return true;
}
WRITE_ONCE(fullstop, FULLSTOP_RMMOD);
mutex_unlock(&fullstop_mutex);
torture_shutdown_cleanup();
torture_shuffle_cleanup();
torture_stutter_cleanup();
torture_onoff_cleanup();
return false;
}
void torture_cleanup_end(void)
{
mutex_lock(&fullstop_mutex);
torture_type = NULL;
mutex_unlock(&fullstop_mutex);
}
bool torture_must_stop(void)
{
return torture_must_stop_irq() || kthread_should_stop();
}
bool torture_must_stop_irq(void)
{
return READ_ONCE(fullstop) != FULLSTOP_DONTSTOP;
}
void torture_kthread_stopping(char *title)
{
char buf[128];
snprintf(buf, sizeof(buf), "Stopping %s", title);
VERBOSE_TOROUT_STRING(buf);
while (!kthread_should_stop()) {
torture_shutdown_absorb(title);
schedule_timeout_uninterruptible(1);
}
}
int _torture_create_kthread(int (*fn)(void *arg), void *arg, char *s, char *m,
char *f, struct task_struct **tp)
{
int ret = 0;
VERBOSE_TOROUT_STRING(m);
*tp = kthread_run(fn, arg, "%s", s);
if (IS_ERR(*tp)) {
ret = PTR_ERR(*tp);
VERBOSE_TOROUT_ERRSTRING(f);
*tp = NULL;
}
torture_shuffle_task_register(*tp);
return ret;
}
void _torture_stop_kthread(char *m, struct task_struct **tp)
{
if (*tp == NULL)
return;
VERBOSE_TOROUT_STRING(m);
kthread_stop(*tp);
*tp = NULL;
}
