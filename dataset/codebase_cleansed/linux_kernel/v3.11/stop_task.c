static int
select_task_rq_stop(struct task_struct *p, int sd_flag, int flags)
{
return task_cpu(p);
}
static void
check_preempt_curr_stop(struct rq *rq, struct task_struct *p, int flags)
{
}
static struct task_struct *pick_next_task_stop(struct rq *rq)
{
struct task_struct *stop = rq->stop;
if (stop && stop->on_rq) {
stop->se.exec_start = rq_clock_task(rq);
return stop;
}
return NULL;
}
static void
enqueue_task_stop(struct rq *rq, struct task_struct *p, int flags)
{
inc_nr_running(rq);
}
static void
dequeue_task_stop(struct rq *rq, struct task_struct *p, int flags)
{
dec_nr_running(rq);
}
static void yield_task_stop(struct rq *rq)
{
BUG();
}
static void put_prev_task_stop(struct rq *rq, struct task_struct *prev)
{
struct task_struct *curr = rq->curr;
u64 delta_exec;
delta_exec = rq_clock_task(rq) - curr->se.exec_start;
if (unlikely((s64)delta_exec < 0))
delta_exec = 0;
schedstat_set(curr->se.statistics.exec_max,
max(curr->se.statistics.exec_max, delta_exec));
curr->se.sum_exec_runtime += delta_exec;
account_group_exec_runtime(curr, delta_exec);
curr->se.exec_start = rq_clock_task(rq);
cpuacct_charge(curr, delta_exec);
}
static void task_tick_stop(struct rq *rq, struct task_struct *curr, int queued)
{
}
static void set_curr_task_stop(struct rq *rq)
{
struct task_struct *stop = rq->stop;
stop->se.exec_start = rq_clock_task(rq);
}
static void switched_to_stop(struct rq *rq, struct task_struct *p)
{
BUG();
}
static void
prio_changed_stop(struct rq *rq, struct task_struct *p, int oldprio)
{
BUG();
}
static unsigned int
get_rr_interval_stop(struct rq *rq, struct task_struct *task)
{
return 0;
}
