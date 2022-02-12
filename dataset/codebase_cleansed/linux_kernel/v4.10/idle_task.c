static int
select_task_rq_idle(struct task_struct *p, int cpu, int sd_flag, int flags)
{
return task_cpu(p);
}
static void check_preempt_curr_idle(struct rq *rq, struct task_struct *p, int flags)
{
resched_curr(rq);
}
static struct task_struct *
pick_next_task_idle(struct rq *rq, struct task_struct *prev, struct pin_cookie cookie)
{
put_prev_task(rq, prev);
update_idle_core(rq);
schedstat_inc(rq->sched_goidle);
return rq->idle;
}
static void
dequeue_task_idle(struct rq *rq, struct task_struct *p, int flags)
{
raw_spin_unlock_irq(&rq->lock);
printk(KERN_ERR "bad: scheduling from the idle thread!\n");
dump_stack();
raw_spin_lock_irq(&rq->lock);
}
static void put_prev_task_idle(struct rq *rq, struct task_struct *prev)
{
rq_last_tick_reset(rq);
}
static void task_tick_idle(struct rq *rq, struct task_struct *curr, int queued)
{
}
static void set_curr_task_idle(struct rq *rq)
{
}
static void switched_to_idle(struct rq *rq, struct task_struct *p)
{
BUG();
}
static void
prio_changed_idle(struct rq *rq, struct task_struct *p, int oldprio)
{
BUG();
}
static unsigned int get_rr_interval_idle(struct rq *rq, struct task_struct *task)
{
return 0;
}
static void update_curr_idle(struct rq *rq)
{
}
