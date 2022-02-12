void __rcu_read_lock(void)
{
current->rcu_read_lock_nesting++;
barrier();
}
void __rcu_read_unlock(void)
{
struct task_struct *t = current;
if (t->rcu_read_lock_nesting != 1) {
--t->rcu_read_lock_nesting;
} else {
barrier();
t->rcu_read_lock_nesting = INT_MIN;
barrier();
if (unlikely(ACCESS_ONCE(t->rcu_read_unlock_special.s)))
rcu_read_unlock_special(t);
barrier();
t->rcu_read_lock_nesting = 0;
}
#ifdef CONFIG_PROVE_LOCKING
{
int rrln = ACCESS_ONCE(t->rcu_read_lock_nesting);
WARN_ON_ONCE(rrln < 0 && rrln > INT_MIN / 2);
}
#endif
}
int notrace debug_lockdep_rcu_enabled(void)
{
return rcu_scheduler_active && debug_locks &&
current->lockdep_recursion == 0;
}
int rcu_read_lock_held(void)
{
if (!debug_lockdep_rcu_enabled())
return 1;
if (!rcu_is_watching())
return 0;
if (!rcu_lockdep_current_cpu_online())
return 0;
return lock_is_held(&rcu_lock_map);
}
int rcu_read_lock_bh_held(void)
{
if (!debug_lockdep_rcu_enabled())
return 1;
if (!rcu_is_watching())
return 0;
if (!rcu_lockdep_current_cpu_online())
return 0;
return in_softirq() || irqs_disabled();
}
static void wakeme_after_rcu(struct rcu_head *head)
{
struct rcu_synchronize *rcu;
rcu = container_of(head, struct rcu_synchronize, head);
complete(&rcu->completion);
}
void wait_rcu_gp(call_rcu_func_t crf)
{
struct rcu_synchronize rcu;
init_rcu_head_on_stack(&rcu.head);
init_completion(&rcu.completion);
crf(&rcu.head, wakeme_after_rcu);
wait_for_completion(&rcu.completion);
destroy_rcu_head_on_stack(&rcu.head);
}
void init_rcu_head(struct rcu_head *head)
{
debug_object_init(head, &rcuhead_debug_descr);
}
void destroy_rcu_head(struct rcu_head *head)
{
debug_object_free(head, &rcuhead_debug_descr);
}
static int rcuhead_fixup_activate(void *addr, enum debug_obj_state state)
{
struct rcu_head *head = addr;
switch (state) {
case ODEBUG_STATE_NOTAVAILABLE:
debug_object_init(head, &rcuhead_debug_descr);
debug_object_activate(head, &rcuhead_debug_descr);
return 0;
default:
return 1;
}
}
void init_rcu_head_on_stack(struct rcu_head *head)
{
debug_object_init_on_stack(head, &rcuhead_debug_descr);
}
void destroy_rcu_head_on_stack(struct rcu_head *head)
{
debug_object_free(head, &rcuhead_debug_descr);
}
void do_trace_rcu_torture_read(const char *rcutorturename, struct rcu_head *rhp,
unsigned long secs,
unsigned long c_old, unsigned long c)
{
trace_rcu_torture_read(rcutorturename, rhp, secs, c_old, c);
}
int rcu_jiffies_till_stall_check(void)
{
int till_stall_check = ACCESS_ONCE(rcu_cpu_stall_timeout);
if (till_stall_check < 3) {
ACCESS_ONCE(rcu_cpu_stall_timeout) = 3;
till_stall_check = 3;
} else if (till_stall_check > 300) {
ACCESS_ONCE(rcu_cpu_stall_timeout) = 300;
till_stall_check = 300;
}
return till_stall_check * HZ + RCU_STALL_DELAY_DELTA;
}
void rcu_sysrq_start(void)
{
if (!rcu_cpu_stall_suppress)
rcu_cpu_stall_suppress = 2;
}
void rcu_sysrq_end(void)
{
if (rcu_cpu_stall_suppress == 2)
rcu_cpu_stall_suppress = 0;
}
static int rcu_panic(struct notifier_block *this, unsigned long ev, void *ptr)
{
rcu_cpu_stall_suppress = 1;
return NOTIFY_DONE;
}
static int __init check_cpu_stall_init(void)
{
atomic_notifier_chain_register(&panic_notifier_list, &rcu_panic_block);
return 0;
}
void call_rcu_tasks(struct rcu_head *rhp, void (*func)(struct rcu_head *rhp))
{
unsigned long flags;
bool needwake;
rhp->next = NULL;
rhp->func = func;
raw_spin_lock_irqsave(&rcu_tasks_cbs_lock, flags);
needwake = !rcu_tasks_cbs_head;
*rcu_tasks_cbs_tail = rhp;
rcu_tasks_cbs_tail = &rhp->next;
raw_spin_unlock_irqrestore(&rcu_tasks_cbs_lock, flags);
if (needwake) {
rcu_spawn_tasks_kthread();
wake_up(&rcu_tasks_cbs_wq);
}
}
void synchronize_rcu_tasks(void)
{
rcu_lockdep_assert(!rcu_scheduler_active,
"synchronize_rcu_tasks called too soon");
wait_rcu_gp(call_rcu_tasks);
}
void rcu_barrier_tasks(void)
{
synchronize_rcu_tasks();
}
static void check_holdout_task(struct task_struct *t,
bool needreport, bool *firstreport)
{
int cpu;
if (!ACCESS_ONCE(t->rcu_tasks_holdout) ||
t->rcu_tasks_nvcsw != ACCESS_ONCE(t->nvcsw) ||
!ACCESS_ONCE(t->on_rq) ||
(IS_ENABLED(CONFIG_NO_HZ_FULL) &&
!is_idle_task(t) && t->rcu_tasks_idle_cpu >= 0)) {
ACCESS_ONCE(t->rcu_tasks_holdout) = false;
list_del_init(&t->rcu_tasks_holdout_list);
put_task_struct(t);
return;
}
if (!needreport)
return;
if (*firstreport) {
pr_err("INFO: rcu_tasks detected stalls on tasks:\n");
*firstreport = false;
}
cpu = task_cpu(t);
pr_alert("%p: %c%c nvcsw: %lu/%lu holdout: %d idle_cpu: %d/%d\n",
t, ".I"[is_idle_task(t)],
"N."[cpu < 0 || !tick_nohz_full_cpu(cpu)],
t->rcu_tasks_nvcsw, t->nvcsw, t->rcu_tasks_holdout,
t->rcu_tasks_idle_cpu, cpu);
sched_show_task(t);
}
static int __noreturn rcu_tasks_kthread(void *arg)
{
unsigned long flags;
struct task_struct *g, *t;
unsigned long lastreport;
struct rcu_head *list;
struct rcu_head *next;
LIST_HEAD(rcu_tasks_holdouts);
for (;;) {
raw_spin_lock_irqsave(&rcu_tasks_cbs_lock, flags);
list = rcu_tasks_cbs_head;
rcu_tasks_cbs_head = NULL;
rcu_tasks_cbs_tail = &rcu_tasks_cbs_head;
raw_spin_unlock_irqrestore(&rcu_tasks_cbs_lock, flags);
if (!list) {
wait_event_interruptible(rcu_tasks_cbs_wq,
rcu_tasks_cbs_head);
if (!rcu_tasks_cbs_head) {
WARN_ON(signal_pending(current));
schedule_timeout_interruptible(HZ/10);
}
continue;
}
synchronize_sched();
rcu_read_lock();
for_each_process_thread(g, t) {
if (t != current && ACCESS_ONCE(t->on_rq) &&
!is_idle_task(t)) {
get_task_struct(t);
t->rcu_tasks_nvcsw = ACCESS_ONCE(t->nvcsw);
ACCESS_ONCE(t->rcu_tasks_holdout) = true;
list_add(&t->rcu_tasks_holdout_list,
&rcu_tasks_holdouts);
}
}
rcu_read_unlock();
synchronize_srcu(&tasks_rcu_exit_srcu);
lastreport = jiffies;
while (!list_empty(&rcu_tasks_holdouts)) {
bool firstreport;
bool needreport;
int rtst;
struct task_struct *t1;
schedule_timeout_interruptible(HZ);
rtst = ACCESS_ONCE(rcu_task_stall_timeout);
needreport = rtst > 0 &&
time_after(jiffies, lastreport + rtst);
if (needreport)
lastreport = jiffies;
firstreport = true;
WARN_ON(signal_pending(current));
list_for_each_entry_safe(t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
check_holdout_task(t, needreport, &firstreport);
cond_resched();
}
}
synchronize_sched();
while (list) {
next = list->next;
local_bh_disable();
list->func(list);
local_bh_enable();
list = next;
cond_resched();
}
schedule_timeout_uninterruptible(HZ/10);
}
}
static void rcu_spawn_tasks_kthread(void)
{
static DEFINE_MUTEX(rcu_tasks_kthread_mutex);
static struct task_struct *rcu_tasks_kthread_ptr;
struct task_struct *t;
if (ACCESS_ONCE(rcu_tasks_kthread_ptr)) {
smp_mb();
return;
}
mutex_lock(&rcu_tasks_kthread_mutex);
if (rcu_tasks_kthread_ptr) {
mutex_unlock(&rcu_tasks_kthread_mutex);
return;
}
t = kthread_run(rcu_tasks_kthread, NULL, "rcu_tasks_kthread");
BUG_ON(IS_ERR(t));
smp_mb();
ACCESS_ONCE(rcu_tasks_kthread_ptr) = t;
mutex_unlock(&rcu_tasks_kthread_mutex);
}
