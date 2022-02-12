void rcu_enter_nohz(void)
{
if (--rcu_dynticks_nesting == 0)
rcu_sched_qs(0);
}
void rcu_exit_nohz(void)
{
rcu_dynticks_nesting++;
}
static int rcu_qsctr_help(struct rcu_ctrlblk *rcp)
{
if (rcp->rcucblist != NULL &&
rcp->donetail != rcp->curtail) {
rcp->donetail = rcp->curtail;
return 1;
}
return 0;
}
static void invoke_rcu_kthread(void)
{
have_rcu_kthread_work = 1;
wake_up(&rcu_kthread_wq);
}
void rcu_sched_qs(int cpu)
{
unsigned long flags;
local_irq_save(flags);
if (rcu_qsctr_help(&rcu_sched_ctrlblk) +
rcu_qsctr_help(&rcu_bh_ctrlblk))
invoke_rcu_kthread();
local_irq_restore(flags);
}
void rcu_bh_qs(int cpu)
{
unsigned long flags;
local_irq_save(flags);
if (rcu_qsctr_help(&rcu_bh_ctrlblk))
invoke_rcu_kthread();
local_irq_restore(flags);
}
void rcu_check_callbacks(int cpu, int user)
{
if (user ||
(idle_cpu(cpu) &&
!in_softirq() &&
hardirq_count() <= (1 << HARDIRQ_SHIFT)))
rcu_sched_qs(cpu);
else if (!in_softirq())
rcu_bh_qs(cpu);
rcu_preempt_check_callbacks();
}
static void rcu_process_callbacks(struct rcu_ctrlblk *rcp)
{
struct rcu_head *next, *list;
unsigned long flags;
RCU_TRACE(int cb_count = 0);
if (&rcp->rcucblist == rcp->donetail)
return;
local_irq_save(flags);
list = rcp->rcucblist;
rcp->rcucblist = *rcp->donetail;
*rcp->donetail = NULL;
if (rcp->curtail == rcp->donetail)
rcp->curtail = &rcp->rcucblist;
rcu_preempt_remove_callbacks(rcp);
rcp->donetail = &rcp->rcucblist;
local_irq_restore(flags);
while (list) {
next = list->next;
prefetch(next);
debug_rcu_head_unqueue(list);
local_bh_disable();
__rcu_reclaim(list);
local_bh_enable();
list = next;
RCU_TRACE(cb_count++);
}
RCU_TRACE(rcu_trace_sub_qlen(rcp, cb_count));
}
static int rcu_kthread(void *arg)
{
unsigned long work;
unsigned long morework;
unsigned long flags;
for (;;) {
wait_event_interruptible(rcu_kthread_wq,
have_rcu_kthread_work != 0);
morework = rcu_boost();
local_irq_save(flags);
work = have_rcu_kthread_work;
have_rcu_kthread_work = morework;
local_irq_restore(flags);
if (work) {
rcu_process_callbacks(&rcu_sched_ctrlblk);
rcu_process_callbacks(&rcu_bh_ctrlblk);
rcu_preempt_process_callbacks();
}
schedule_timeout_interruptible(1);
}
return 0;
}
void synchronize_sched(void)
{
cond_resched();
}
static void __call_rcu(struct rcu_head *head,
void (*func)(struct rcu_head *rcu),
struct rcu_ctrlblk *rcp)
{
unsigned long flags;
debug_rcu_head_queue(head);
head->func = func;
head->next = NULL;
local_irq_save(flags);
*rcp->curtail = head;
rcp->curtail = &head->next;
RCU_TRACE(rcp->qlen++);
local_irq_restore(flags);
}
void call_rcu_sched(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
__call_rcu(head, func, &rcu_sched_ctrlblk);
}
void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
__call_rcu(head, func, &rcu_bh_ctrlblk);
}
void rcu_barrier_bh(void)
{
struct rcu_synchronize rcu;
init_rcu_head_on_stack(&rcu.head);
init_completion(&rcu.completion);
call_rcu_bh(&rcu.head, wakeme_after_rcu);
wait_for_completion(&rcu.completion);
destroy_rcu_head_on_stack(&rcu.head);
}
void rcu_barrier_sched(void)
{
struct rcu_synchronize rcu;
init_rcu_head_on_stack(&rcu.head);
init_completion(&rcu.completion);
call_rcu_sched(&rcu.head, wakeme_after_rcu);
wait_for_completion(&rcu.completion);
destroy_rcu_head_on_stack(&rcu.head);
}
static int __init rcu_spawn_kthreads(void)
{
struct sched_param sp;
rcu_kthread_task = kthread_run(rcu_kthread, NULL, "rcu_kthread");
sp.sched_priority = RCU_BOOST_PRIO;
sched_setscheduler_nocheck(rcu_kthread_task, SCHED_FIFO, &sp);
return 0;
}
