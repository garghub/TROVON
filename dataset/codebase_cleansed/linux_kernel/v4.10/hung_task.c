static int __init hung_task_panic_setup(char *str)
{
int rc = kstrtouint(str, 0, &sysctl_hung_task_panic);
if (rc)
return rc;
return 1;
}
static int
hung_task_panic(struct notifier_block *this, unsigned long event, void *ptr)
{
did_panic = 1;
return NOTIFY_DONE;
}
static void check_hung_task(struct task_struct *t, unsigned long timeout)
{
unsigned long switch_count = t->nvcsw + t->nivcsw;
if (unlikely(t->flags & (PF_FROZEN | PF_FREEZER_SKIP)))
return;
if (unlikely(!switch_count))
return;
if (switch_count != t->last_switch_count) {
t->last_switch_count = switch_count;
return;
}
trace_sched_process_hang(t);
if (!sysctl_hung_task_warnings && !sysctl_hung_task_panic)
return;
if (sysctl_hung_task_warnings) {
if (sysctl_hung_task_warnings > 0)
sysctl_hung_task_warnings--;
pr_err("INFO: task %s:%d blocked for more than %ld seconds.\n",
t->comm, t->pid, timeout);
pr_err(" %s %s %.*s\n",
print_tainted(), init_utsname()->release,
(int)strcspn(init_utsname()->version, " "),
init_utsname()->version);
pr_err("\"echo 0 > /proc/sys/kernel/hung_task_timeout_secs\""
" disables this message.\n");
sched_show_task(t);
debug_show_all_locks();
}
touch_nmi_watchdog();
if (sysctl_hung_task_panic) {
trigger_all_cpu_backtrace();
panic("hung_task: blocked tasks");
}
}
static bool rcu_lock_break(struct task_struct *g, struct task_struct *t)
{
bool can_cont;
get_task_struct(g);
get_task_struct(t);
rcu_read_unlock();
cond_resched();
rcu_read_lock();
can_cont = pid_alive(g) && pid_alive(t);
put_task_struct(t);
put_task_struct(g);
return can_cont;
}
static void check_hung_uninterruptible_tasks(unsigned long timeout)
{
int max_count = sysctl_hung_task_check_count;
int batch_count = HUNG_TASK_BATCHING;
struct task_struct *g, *t;
if (test_taint(TAINT_DIE) || did_panic)
return;
rcu_read_lock();
for_each_process_thread(g, t) {
if (!max_count--)
goto unlock;
if (!--batch_count) {
batch_count = HUNG_TASK_BATCHING;
if (!rcu_lock_break(g, t))
goto unlock;
}
if (t->state == TASK_UNINTERRUPTIBLE)
check_hung_task(t, timeout);
}
unlock:
rcu_read_unlock();
}
static long hung_timeout_jiffies(unsigned long last_checked,
unsigned long timeout)
{
return timeout ? last_checked - jiffies + timeout * HZ :
MAX_SCHEDULE_TIMEOUT;
}
int proc_dohung_task_timeout_secs(struct ctl_table *table, int write,
void __user *buffer,
size_t *lenp, loff_t *ppos)
{
int ret;
ret = proc_doulongvec_minmax(table, write, buffer, lenp, ppos);
if (ret || !write)
goto out;
wake_up_process(watchdog_task);
out:
return ret;
}
void reset_hung_task_detector(void)
{
atomic_set(&reset_hung_task, 1);
}
static int watchdog(void *dummy)
{
unsigned long hung_last_checked = jiffies;
set_user_nice(current, 0);
for ( ; ; ) {
unsigned long timeout = sysctl_hung_task_timeout_secs;
long t = hung_timeout_jiffies(hung_last_checked, timeout);
if (t <= 0) {
if (!atomic_xchg(&reset_hung_task, 0))
check_hung_uninterruptible_tasks(timeout);
hung_last_checked = jiffies;
continue;
}
schedule_timeout_interruptible(t);
}
return 0;
}
static int __init hung_task_init(void)
{
atomic_notifier_chain_register(&panic_notifier_list, &panic_block);
watchdog_task = kthread_run(watchdog, NULL, "khungtaskd");
return 0;
}
