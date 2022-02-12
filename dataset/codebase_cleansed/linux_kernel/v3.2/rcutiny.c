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
void rcu_sched_qs(int cpu)
{
unsigned long flags;
local_irq_save(flags);
if (rcu_qsctr_help(&rcu_sched_ctrlblk) +
rcu_qsctr_help(&rcu_bh_ctrlblk))
invoke_rcu_callbacks();
local_irq_restore(flags);
}
void rcu_bh_qs(int cpu)
{
unsigned long flags;
local_irq_save(flags);
if (rcu_qsctr_help(&rcu_bh_ctrlblk))
invoke_rcu_callbacks();
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
static void __rcu_process_callbacks(struct rcu_ctrlblk *rcp)
{
char *rn = NULL;
struct rcu_head *next, *list;
unsigned long flags;
RCU_TRACE(int cb_count = 0);
if (&rcp->rcucblist == rcp->donetail) {
RCU_TRACE(trace_rcu_batch_start(rcp->name, 0, -1));
RCU_TRACE(trace_rcu_batch_end(rcp->name, 0));
return;
}
local_irq_save(flags);
RCU_TRACE(trace_rcu_batch_start(rcp->name, 0, -1));
list = rcp->rcucblist;
rcp->rcucblist = *rcp->donetail;
*rcp->donetail = NULL;
if (rcp->curtail == rcp->donetail)
rcp->curtail = &rcp->rcucblist;
rcu_preempt_remove_callbacks(rcp);
rcp->donetail = &rcp->rcucblist;
local_irq_restore(flags);
RCU_TRACE(rn = rcp->name);
while (list) {
next = list->next;
prefetch(next);
debug_rcu_head_unqueue(list);
local_bh_disable();
__rcu_reclaim(rn, list);
local_bh_enable();
list = next;
RCU_TRACE(cb_count++);
}
RCU_TRACE(rcu_trace_sub_qlen(rcp, cb_count));
RCU_TRACE(trace_rcu_batch_end(rcp->name, cb_count));
}
static void rcu_process_callbacks(struct softirq_action *unused)
{
__rcu_process_callbacks(&rcu_sched_ctrlblk);
__rcu_process_callbacks(&rcu_bh_ctrlblk);
rcu_preempt_process_callbacks();
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
