static int init_srcu_struct_fields(struct srcu_struct *sp)
{
sp->srcu_lock_nesting[0] = 0;
sp->srcu_lock_nesting[1] = 0;
init_swait_queue_head(&sp->srcu_wq);
sp->srcu_cb_head = NULL;
sp->srcu_cb_tail = &sp->srcu_cb_head;
sp->srcu_gp_running = false;
sp->srcu_gp_waiting = false;
sp->srcu_idx = 0;
INIT_WORK(&sp->srcu_work, srcu_drive_gp);
return 0;
}
int __init_srcu_struct(struct srcu_struct *sp, const char *name,
struct lock_class_key *key)
{
debug_check_no_locks_freed((void *)sp, sizeof(*sp));
lockdep_init_map(&sp->dep_map, name, key, 0);
return init_srcu_struct_fields(sp);
}
int init_srcu_struct(struct srcu_struct *sp)
{
return init_srcu_struct_fields(sp);
}
void cleanup_srcu_struct(struct srcu_struct *sp)
{
WARN_ON(sp->srcu_lock_nesting[0] || sp->srcu_lock_nesting[1]);
flush_work(&sp->srcu_work);
WARN_ON(sp->srcu_gp_running);
WARN_ON(sp->srcu_gp_waiting);
WARN_ON(sp->srcu_cb_head);
WARN_ON(&sp->srcu_cb_head != sp->srcu_cb_tail);
}
void __srcu_read_unlock(struct srcu_struct *sp, int idx)
{
int newval = sp->srcu_lock_nesting[idx] - 1;
WRITE_ONCE(sp->srcu_lock_nesting[idx], newval);
if (!newval && READ_ONCE(sp->srcu_gp_waiting))
swake_up(&sp->srcu_wq);
}
void srcu_drive_gp(struct work_struct *wp)
{
int idx;
struct rcu_head *lh;
struct rcu_head *rhp;
struct srcu_struct *sp;
sp = container_of(wp, struct srcu_struct, srcu_work);
if (sp->srcu_gp_running || !READ_ONCE(sp->srcu_cb_head))
return;
WRITE_ONCE(sp->srcu_gp_running, true);
local_irq_disable();
lh = sp->srcu_cb_head;
sp->srcu_cb_head = NULL;
sp->srcu_cb_tail = &sp->srcu_cb_head;
local_irq_enable();
idx = sp->srcu_idx;
WRITE_ONCE(sp->srcu_idx, !sp->srcu_idx);
WRITE_ONCE(sp->srcu_gp_waiting, true);
swait_event(sp->srcu_wq, !READ_ONCE(sp->srcu_lock_nesting[idx]));
WRITE_ONCE(sp->srcu_gp_waiting, false);
while (lh) {
rhp = lh;
lh = lh->next;
local_bh_disable();
rhp->func(rhp);
local_bh_enable();
}
WRITE_ONCE(sp->srcu_gp_running, false);
if (READ_ONCE(sp->srcu_cb_head))
schedule_work(&sp->srcu_work);
}
void call_srcu(struct srcu_struct *sp, struct rcu_head *rhp,
rcu_callback_t func)
{
unsigned long flags;
rhp->func = func;
rhp->next = NULL;
local_irq_save(flags);
*sp->srcu_cb_tail = rhp;
sp->srcu_cb_tail = &rhp->next;
local_irq_restore(flags);
if (!READ_ONCE(sp->srcu_gp_running))
schedule_work(&sp->srcu_work);
}
void synchronize_srcu(struct srcu_struct *sp)
{
struct rcu_synchronize rs;
init_rcu_head_on_stack(&rs.head);
init_completion(&rs.completion);
call_srcu(sp, &rs.head, wakeme_after_rcu);
wait_for_completion(&rs.completion);
destroy_rcu_head_on_stack(&rs.head);
}
void __init rcu_scheduler_starting(void)
{
rcu_scheduler_active = RCU_SCHEDULER_RUNNING;
}
