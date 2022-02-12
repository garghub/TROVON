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
if (unlikely(ACCESS_ONCE(t->rcu_read_unlock_special)))
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
void exit_rcu(void)
{
struct task_struct *t = current;
if (likely(list_empty(&current->rcu_node_entry)))
return;
t->rcu_read_lock_nesting = 1;
barrier();
t->rcu_read_unlock_special = RCU_READ_UNLOCK_BLOCKED;
__rcu_read_unlock();
}
void exit_rcu(void)
{
}
int debug_lockdep_rcu_enabled(void)
{
return rcu_scheduler_active && debug_locks &&
current->lockdep_recursion == 0;
}
int rcu_read_lock_bh_held(void)
{
if (!debug_lockdep_rcu_enabled())
return 1;
if (rcu_is_cpu_idle())
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
int rcu_my_thread_group_empty(void)
{
return thread_group_empty(current);
}
static inline void debug_init_rcu_head(struct rcu_head *head)
{
debug_object_init(head, &rcuhead_debug_descr);
}
static inline void debug_rcu_head_free(struct rcu_head *head)
{
debug_object_free(head, &rcuhead_debug_descr);
}
static int rcuhead_fixup_init(void *addr, enum debug_obj_state state)
{
struct rcu_head *head = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
#ifndef CONFIG_PREEMPT
WARN_ON_ONCE(1);
return 0;
#endif
if (rcu_preempt_depth() != 0 || preempt_count() != 0 ||
irqs_disabled()) {
WARN_ON_ONCE(1);
return 0;
}
rcu_barrier();
rcu_barrier_sched();
rcu_barrier_bh();
debug_object_init(head, &rcuhead_debug_descr);
return 1;
default:
return 0;
}
}
static int rcuhead_fixup_activate(void *addr, enum debug_obj_state state)
{
struct rcu_head *head = addr;
switch (state) {
case ODEBUG_STATE_NOTAVAILABLE:
debug_object_init(head, &rcuhead_debug_descr);
debug_object_activate(head, &rcuhead_debug_descr);
return 0;
case ODEBUG_STATE_ACTIVE:
#ifndef CONFIG_PREEMPT
WARN_ON_ONCE(1);
return 0;
#endif
if (rcu_preempt_depth() != 0 || preempt_count() != 0 ||
irqs_disabled()) {
WARN_ON_ONCE(1);
return 0;
}
rcu_barrier();
rcu_barrier_sched();
rcu_barrier_bh();
debug_object_activate(head, &rcuhead_debug_descr);
return 1;
default:
return 0;
}
}
static int rcuhead_fixup_free(void *addr, enum debug_obj_state state)
{
struct rcu_head *head = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
#ifndef CONFIG_PREEMPT
WARN_ON_ONCE(1);
return 0;
#endif
if (rcu_preempt_depth() != 0 || preempt_count() != 0 ||
irqs_disabled()) {
WARN_ON_ONCE(1);
return 0;
}
rcu_barrier();
rcu_barrier_sched();
rcu_barrier_bh();
debug_object_free(head, &rcuhead_debug_descr);
return 1;
default:
return 0;
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
void do_trace_rcu_torture_read(char *rcutorturename, struct rcu_head *rhp)
{
trace_rcu_torture_read(rcutorturename, rhp);
}
