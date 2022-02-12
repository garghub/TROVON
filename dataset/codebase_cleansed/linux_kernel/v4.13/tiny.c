void rcu_barrier_bh(void)
{
wait_rcu_gp(call_rcu_bh);
}
void rcu_barrier_sched(void)
{
wait_rcu_gp(call_rcu_sched);
}
static int rcu_qsctr_help(struct rcu_ctrlblk *rcp)
{
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
if (user)
rcu_sched_qs();
else if (!in_softirq())
rcu_bh_qs();
if (user)
rcu_note_voluntary_context_switch(current);
}
static void __rcu_process_callbacks(struct rcu_ctrlblk *rcp)
{
struct rcu_head *next, *list;
unsigned long flags;
local_irq_save(flags);
if (rcp->donetail == &rcp->rcucblist) {
local_irq_restore(flags);
return;
}
list = rcp->rcucblist;
rcp->rcucblist = *rcp->donetail;
*rcp->donetail = NULL;
if (rcp->curtail == rcp->donetail)
rcp->curtail = &rcp->rcucblist;
rcp->donetail = &rcp->rcucblist;
local_irq_restore(flags);
while (list) {
next = list->next;
prefetch(next);
debug_rcu_head_unqueue(list);
local_bh_disable();
__rcu_reclaim("", list);
local_bh_enable();
list = next;
}
}
static __latent_entropy void rcu_process_callbacks(struct softirq_action *unused)
{
__rcu_process_callbacks(&rcu_sched_ctrlblk);
__rcu_process_callbacks(&rcu_bh_ctrlblk);
}
void synchronize_sched(void)
{
RCU_LOCKDEP_WARN(lock_is_held(&rcu_bh_lock_map) ||
lock_is_held(&rcu_lock_map) ||
lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_sched() in RCU read-side critical section");
}
static void __call_rcu(struct rcu_head *head,
rcu_callback_t func,
struct rcu_ctrlblk *rcp)
{
unsigned long flags;
debug_rcu_head_queue(head);
head->func = func;
head->next = NULL;
local_irq_save(flags);
*rcp->curtail = head;
rcp->curtail = &head->next;
local_irq_restore(flags);
if (unlikely(is_idle_task(current))) {
resched_cpu(0);
}
}
void call_rcu_sched(struct rcu_head *head, rcu_callback_t func)
{
__call_rcu(head, func, &rcu_sched_ctrlblk);
}
void call_rcu_bh(struct rcu_head *head, rcu_callback_t func)
{
__call_rcu(head, func, &rcu_bh_ctrlblk);
}
void __init rcu_init(void)
{
open_softirq(RCU_SOFTIRQ, rcu_process_callbacks);
rcu_early_boot_tests();
}
