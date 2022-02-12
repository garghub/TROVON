static int init_srcu_struct_fields(struct srcu_struct *sp)
{
sp->srcu_lock_nesting[0] = 0;
sp->srcu_lock_nesting[1] = 0;
init_swait_queue_head(&sp->srcu_wq);
sp->srcu_gp_seq = 0;
rcu_segcblist_init(&sp->srcu_cblist);
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
WARN_ON(rcu_seq_state(sp->srcu_gp_seq));
WARN_ON(sp->srcu_gp_running);
WARN_ON(sp->srcu_gp_waiting);
WARN_ON(!rcu_segcblist_empty(&sp->srcu_cblist));
}
int __srcu_read_lock(struct srcu_struct *sp)
{
int idx;
idx = READ_ONCE(sp->srcu_idx);
WRITE_ONCE(sp->srcu_lock_nesting[idx], sp->srcu_lock_nesting[idx] + 1);
return idx;
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
struct rcu_cblist ready_cbs;
struct srcu_struct *sp;
struct rcu_head *rhp;
sp = container_of(wp, struct srcu_struct, srcu_work);
if (sp->srcu_gp_running || rcu_segcblist_empty(&sp->srcu_cblist))
return;
WRITE_ONCE(sp->srcu_gp_running, true);
rcu_segcblist_accelerate(&sp->srcu_cblist,
rcu_seq_snap(&sp->srcu_gp_seq));
rcu_seq_start(&sp->srcu_gp_seq);
idx = sp->srcu_idx;
WRITE_ONCE(sp->srcu_idx, !sp->srcu_idx);
WRITE_ONCE(sp->srcu_gp_waiting, true);
swait_event(sp->srcu_wq, !READ_ONCE(sp->srcu_lock_nesting[idx]));
WRITE_ONCE(sp->srcu_gp_waiting, false);
rcu_seq_end(&sp->srcu_gp_seq);
rcu_segcblist_advance(&sp->srcu_cblist,
rcu_seq_current(&sp->srcu_gp_seq));
if (rcu_segcblist_ready_cbs(&sp->srcu_cblist)) {
rcu_cblist_init(&ready_cbs);
local_irq_disable();
rcu_segcblist_extract_done_cbs(&sp->srcu_cblist, &ready_cbs);
local_irq_enable();
rhp = rcu_cblist_dequeue(&ready_cbs);
for (; rhp != NULL; rhp = rcu_cblist_dequeue(&ready_cbs)) {
local_bh_disable();
rhp->func(rhp);
local_bh_enable();
}
local_irq_disable();
rcu_segcblist_insert_count(&sp->srcu_cblist, &ready_cbs);
local_irq_enable();
}
WRITE_ONCE(sp->srcu_gp_running, false);
if (!rcu_segcblist_empty(&sp->srcu_cblist))
schedule_work(&sp->srcu_work);
}
void call_srcu(struct srcu_struct *sp, struct rcu_head *head,
rcu_callback_t func)
{
unsigned long flags;
head->func = func;
local_irq_save(flags);
rcu_segcblist_enqueue(&sp->srcu_cblist, head, false);
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
