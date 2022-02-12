void rcu_idle_enter(void)
{
}
void rcu_irq_exit(void)
{
}
void rcu_idle_exit(void)
{
}
void rcu_irq_enter(void)
{
}
bool notrace __rcu_is_watching(void)
{
return true;
}
static int rcu_qsctr_help(struct rcu_ctrlblk *rcp)
{
RCU_TRACE(reset_cpu_stall_ticks(rcp));
if (rcp->donetail != rcp->curtail) {
rcp->donetail = rcp->curtail;
return 1;
}
return 0;
}
void rcu_sched_qs(void)
{
unsigned long flags;
local_irq_save(flags);
if (rcu_qsctr_help(&rcu_sched_ctrlblk) +
rcu_qsctr_help(&rcu_bh_ctrlblk))
raise_softirq(RCU_SOFTIRQ);
local_irq_restore(flags);
}
void rcu_bh_qs(void)
{
unsigned long flags;
local_irq_save(flags);
if (rcu_qsctr_help(&rcu_bh_ctrlblk))
raise_softirq(RCU_SOFTIRQ);
local_irq_restore(flags);
}
void rcu_check_callbacks(int user)
{
RCU_TRACE(check_cpu_stalls());
if (user)
rcu_sched_qs();
else if (!in_softirq())
rcu_bh_qs();
if (user)
rcu_note_voluntary_context_switch(current);
}
static void __rcu_process_callbacks(struct rcu_ctrlblk *rcp)
{
const char *rn = NULL;
struct rcu_head *next, *list;
unsigned long flags;
RCU_TRACE(int cb_count = 0);
local_irq_save(flags);
RCU_TRACE(trace_rcu_batch_start(rcp->name, 0, rcp->qlen, -1));
list = rcp->rcucblist;
rcp->rcucblist = *rcp->donetail;
*rcp->donetail = NULL;
if (rcp->curtail == rcp->donetail)
rcp->curtail = &rcp->rcucblist;
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
RCU_TRACE(trace_rcu_batch_end(rcp->name,
cb_count, 0, need_resched(),
is_idle_task(current),
false));
}
static void rcu_process_callbacks(struct softirq_action *unused)
{
__rcu_process_callbacks(&rcu_sched_ctrlblk);
__rcu_process_callbacks(&rcu_bh_ctrlblk);
}
void synchronize_sched(void)
{
rcu_lockdep_assert(!lock_is_held(&rcu_bh_lock_map) &&
!lock_is_held(&rcu_lock_map) &&
!lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_sched() in RCU read-side critical section");
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
if (unlikely(is_idle_task(current))) {
resched_cpu(0);
}
}
void call_rcu_sched(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
__call_rcu(head, func, &rcu_sched_ctrlblk);
}
void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
__call_rcu(head, func, &rcu_bh_ctrlblk);
}
void __init rcu_init(void)
{
open_softirq(RCU_SOFTIRQ, rcu_process_callbacks);
RCU_TRACE(reset_cpu_stall_ticks(&rcu_sched_ctrlblk));
RCU_TRACE(reset_cpu_stall_ticks(&rcu_bh_ctrlblk));
rcu_early_boot_tests();
}
