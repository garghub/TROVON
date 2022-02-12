static int __init hung_task_panic_setup(char *str)
{
sysctl_hung_task_panic = simple_strtoul(str, NULL, 0);
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
if (!sysctl_hung_task_warnings)
return;
sysctl_hung_task_warnings--;
printk(KERN_ERR "INFO: task %s:%d blocked for more than "
"%ld seconds.\n", t->comm, t->pid, timeout);
printk(KERN_ERR "\"echo 0 > /proc/sys/kernel/hung_task_timeout_secs\""
" disables this message.\n");
sched_show_task(t);
debug_show_held_locks(t);
touch_nmi_watchdog();
if (sysctl_hung_task_panic)
panic("hung_task: blocked tasks");
}
static void rcu_lock_break(struct task_struct *g, struct task_struct *t)
{
get_task_struct(g);
get_task_struct(t);
rcu_read_unlock();
cond_resched();
rcu_read_lock();
put_task_struct(t);
put_task_struct(g);
}
static void check_hung_uninterruptible_tasks(unsigned long timeout)
{
int max_count = sysctl_hung_task_check_count;
int batch_count = HUNG_TASK_BATCHING;
struct task_struct *g, *t;
if (test_taint(TAINT_DIE) || did_panic)
return;
rcu_read_lock();
do_each_thread(g, t) {
if (!max_count--)
goto unlock;
if (!--batch_count) {
batch_count = HUNG_TASK_BATCHING;
rcu_lock_break(g, t);
if (t->state == TASK_DEAD || g->state == TASK_DEAD)
goto unlock;
}
if (t->state == TASK_UNINTERRUPTIBLE)
check_hung_task(t, timeout);
} while_each_thread(g, t);
unlock:
rcu_read_unlock();
}
static unsigned long timeout_jiffies(unsigned long timeout)
{
return timeout ? timeout * HZ : MAX_SCHEDULE_TIMEOUT;
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
static int watchdog(void *dummy)
{
set_user_nice(current, 0);
for ( ; ; ) {
unsigned long timeout = sysctl_hung_task_timeout_secs;
while (schedule_timeout_interruptible(timeout_jiffies(timeout)))
timeout = sysctl_hung_task_timeout_secs;
check_hung_uninterruptible_tasks(timeout);
}
return 0;
}
static int __init hung_task_init(void)
{
atomic_notifier_chain_register(&panic_notifier_list, &panic_block);
watchdog_task = kthread_run(watchdog, NULL, "khungtaskd");
return 0;
}
