static int
select_task_rq_idle(struct task_struct *p, int sd_flag, int flags)
{
return task_cpu(p);
}
static void pre_schedule_idle(struct rq *rq, struct task_struct *prev)
{
idle_exit_fair(rq);
rq_last_tick_reset(rq);
}
static void post_schedule_idle(struct rq *rq)
{
idle_enter_fair(rq);
}
static void check_preempt_curr_idle(struct rq *rq, struct task_struct *p, int flags)
{
resched_task(rq->idle);
}
static struct task_struct *pick_next_task_idle(struct rq *rq)
{
schedstat_inc(rq, sched_goidle);
#ifdef CONFIG_SMP
rq->post_schedule = 1;
#endif
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
