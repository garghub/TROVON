static int __init delayacct_setup_disable(char *str)
{
delayacct_on = 0;
return 1;
}
void delayacct_init(void)
{
delayacct_cache = KMEM_CACHE(task_delay_info, SLAB_PANIC);
delayacct_tsk_init(&init_task);
}
void __delayacct_tsk_init(struct task_struct *tsk)
{
tsk->delays = kmem_cache_zalloc(delayacct_cache, GFP_KERNEL);
if (tsk->delays)
spin_lock_init(&tsk->delays->lock);
}
static inline void delayacct_start(struct timespec *start)
{
do_posix_clock_monotonic_gettime(start);
}
static void delayacct_end(struct timespec *start, struct timespec *end,
u64 *total, u32 *count)
{
struct timespec ts;
s64 ns;
unsigned long flags;
do_posix_clock_monotonic_gettime(end);
ts = timespec_sub(*end, *start);
ns = timespec_to_ns(&ts);
if (ns < 0)
return;
spin_lock_irqsave(&current->delays->lock, flags);
*total += ns;
(*count)++;
spin_unlock_irqrestore(&current->delays->lock, flags);
}
void __delayacct_blkio_start(void)
{
delayacct_start(&current->delays->blkio_start);
}
void __delayacct_blkio_end(void)
{
if (current->delays->flags & DELAYACCT_PF_SWAPIN)
delayacct_end(&current->delays->blkio_start,
&current->delays->blkio_end,
&current->delays->swapin_delay,
&current->delays->swapin_count);
else
delayacct_end(&current->delays->blkio_start,
&current->delays->blkio_end,
&current->delays->blkio_delay,
&current->delays->blkio_count);
}
int __delayacct_add_tsk(struct taskstats *d, struct task_struct *tsk)
{
s64 tmp;
unsigned long t1;
unsigned long long t2, t3;
unsigned long flags;
struct timespec ts;
if (!tsk->delays)
goto done;
tmp = (s64)d->cpu_run_real_total;
cputime_to_timespec(tsk->utime + tsk->stime, &ts);
tmp += timespec_to_ns(&ts);
d->cpu_run_real_total = (tmp < (s64)d->cpu_run_real_total) ? 0 : tmp;
tmp = (s64)d->cpu_scaled_run_real_total;
cputime_to_timespec(tsk->utimescaled + tsk->stimescaled, &ts);
tmp += timespec_to_ns(&ts);
d->cpu_scaled_run_real_total =
(tmp < (s64)d->cpu_scaled_run_real_total) ? 0 : tmp;
t1 = tsk->sched_info.pcount;
t2 = tsk->sched_info.run_delay;
t3 = tsk->se.sum_exec_runtime;
d->cpu_count += t1;
tmp = (s64)d->cpu_delay_total + t2;
d->cpu_delay_total = (tmp < (s64)d->cpu_delay_total) ? 0 : tmp;
tmp = (s64)d->cpu_run_virtual_total + t3;
d->cpu_run_virtual_total =
(tmp < (s64)d->cpu_run_virtual_total) ? 0 : tmp;
spin_lock_irqsave(&tsk->delays->lock, flags);
tmp = d->blkio_delay_total + tsk->delays->blkio_delay;
d->blkio_delay_total = (tmp < d->blkio_delay_total) ? 0 : tmp;
tmp = d->swapin_delay_total + tsk->delays->swapin_delay;
d->swapin_delay_total = (tmp < d->swapin_delay_total) ? 0 : tmp;
tmp = d->freepages_delay_total + tsk->delays->freepages_delay;
d->freepages_delay_total = (tmp < d->freepages_delay_total) ? 0 : tmp;
d->blkio_count += tsk->delays->blkio_count;
d->swapin_count += tsk->delays->swapin_count;
d->freepages_count += tsk->delays->freepages_count;
spin_unlock_irqrestore(&tsk->delays->lock, flags);
done:
return 0;
}
__u64 __delayacct_blkio_ticks(struct task_struct *tsk)
{
__u64 ret;
unsigned long flags;
spin_lock_irqsave(&tsk->delays->lock, flags);
ret = nsec_to_clock_t(tsk->delays->blkio_delay +
tsk->delays->swapin_delay);
spin_unlock_irqrestore(&tsk->delays->lock, flags);
return ret;
}
void __delayacct_freepages_start(void)
{
delayacct_start(&current->delays->freepages_start);
}
void __delayacct_freepages_end(void)
{
delayacct_end(&current->delays->freepages_start,
&current->delays->freepages_end,
&current->delays->freepages_delay,
&current->delays->freepages_count);
}
