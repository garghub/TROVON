static inline int rt_policy(int policy)
{
if (policy == SCHED_FIFO || policy == SCHED_RR)
return 1;
return 0;
}
static inline int task_has_rt_policy(struct task_struct *p)
{
return rt_policy(p->policy);
}
static enum hrtimer_restart sched_rt_period_timer(struct hrtimer *timer)
{
struct rt_bandwidth *rt_b =
container_of(timer, struct rt_bandwidth, rt_period_timer);
ktime_t now;
int overrun;
int idle = 0;
for (;;) {
now = hrtimer_cb_get_time(timer);
overrun = hrtimer_forward(timer, now, rt_b->rt_period);
if (!overrun)
break;
idle = do_sched_rt_period_timer(rt_b, overrun);
}
return idle ? HRTIMER_NORESTART : HRTIMER_RESTART;
}
static
void init_rt_bandwidth(struct rt_bandwidth *rt_b, u64 period, u64 runtime)
{
rt_b->rt_period = ns_to_ktime(period);
rt_b->rt_runtime = runtime;
raw_spin_lock_init(&rt_b->rt_runtime_lock);
hrtimer_init(&rt_b->rt_period_timer,
CLOCK_MONOTONIC, HRTIMER_MODE_REL);
rt_b->rt_period_timer.function = sched_rt_period_timer;
}
static inline int rt_bandwidth_enabled(void)
{
return sysctl_sched_rt_runtime >= 0;
}
static void start_rt_bandwidth(struct rt_bandwidth *rt_b)
{
ktime_t now;
if (!rt_bandwidth_enabled() || rt_b->rt_runtime == RUNTIME_INF)
return;
if (hrtimer_active(&rt_b->rt_period_timer))
return;
raw_spin_lock(&rt_b->rt_runtime_lock);
for (;;) {
unsigned long delta;
ktime_t soft, hard;
if (hrtimer_active(&rt_b->rt_period_timer))
break;
now = hrtimer_cb_get_time(&rt_b->rt_period_timer);
hrtimer_forward(&rt_b->rt_period_timer, now, rt_b->rt_period);
soft = hrtimer_get_softexpires(&rt_b->rt_period_timer);
hard = hrtimer_get_expires(&rt_b->rt_period_timer);
delta = ktime_to_ns(ktime_sub(hard, soft));
__hrtimer_start_range_ns(&rt_b->rt_period_timer, soft, delta,
HRTIMER_MODE_ABS_PINNED, 0);
}
raw_spin_unlock(&rt_b->rt_runtime_lock);
}
static void destroy_rt_bandwidth(struct rt_bandwidth *rt_b)
{
hrtimer_cancel(&rt_b->rt_period_timer);
}
static inline int cpu_of(struct rq *rq)
{
#ifdef CONFIG_SMP
return rq->cpu;
#else
return 0;
#endif
}
static inline struct task_group *task_group(struct task_struct *p)
{
struct task_group *tg;
struct cgroup_subsys_state *css;
css = task_subsys_state_check(p, cpu_cgroup_subsys_id,
lockdep_is_held(&p->pi_lock) ||
lockdep_is_held(&task_rq(p)->lock));
tg = container_of(css, struct task_group, css);
return autogroup_task_group(p, tg);
}
static inline void set_task_rq(struct task_struct *p, unsigned int cpu)
{
#ifdef CONFIG_FAIR_GROUP_SCHED
p->se.cfs_rq = task_group(p)->cfs_rq[cpu];
p->se.parent = task_group(p)->se[cpu];
#endif
#ifdef CONFIG_RT_GROUP_SCHED
p->rt.rt_rq = task_group(p)->rt_rq[cpu];
p->rt.parent = task_group(p)->rt_se[cpu];
#endif
}
static inline void set_task_rq(struct task_struct *p, unsigned int cpu) { }
static inline struct task_group *task_group(struct task_struct *p)
{
return NULL;
}
static void update_rq_clock(struct rq *rq)
{
s64 delta;
if (rq->skip_clock_update > 0)
return;
delta = sched_clock_cpu(cpu_of(rq)) - rq->clock;
rq->clock += delta;
update_rq_clock_task(rq, delta);
}
int runqueue_is_locked(int cpu)
{
return raw_spin_is_locked(&cpu_rq(cpu)->lock);
}
static int sched_feat_show(struct seq_file *m, void *v)
{
int i;
for (i = 0; sched_feat_names[i]; i++) {
if (!(sysctl_sched_features & (1UL << i)))
seq_puts(m, "NO_");
seq_printf(m, "%s ", sched_feat_names[i]);
}
seq_puts(m, "\n");
return 0;
}
static ssize_t
sched_feat_write(struct file *filp, const char __user *ubuf,
size_t cnt, loff_t *ppos)
{
char buf[64];
char *cmp;
int neg = 0;
int i;
if (cnt > 63)
cnt = 63;
if (copy_from_user(&buf, ubuf, cnt))
return -EFAULT;
buf[cnt] = 0;
cmp = strstrip(buf);
if (strncmp(cmp, "NO_", 3) == 0) {
neg = 1;
cmp += 3;
}
for (i = 0; sched_feat_names[i]; i++) {
if (strcmp(cmp, sched_feat_names[i]) == 0) {
if (neg)
sysctl_sched_features &= ~(1UL << i);
else
sysctl_sched_features |= (1UL << i);
break;
}
}
if (!sched_feat_names[i])
return -EINVAL;
*ppos += cnt;
return cnt;
}
static int sched_feat_open(struct inode *inode, struct file *filp)
{
return single_open(filp, sched_feat_show, NULL);
}
static __init int sched_init_debug(void)
{
debugfs_create_file("sched_features", 0644, NULL, NULL,
&sched_feat_fops);
return 0;
}
static inline u64 global_rt_period(void)
{
return (u64)sysctl_sched_rt_period * NSEC_PER_USEC;
}
static inline u64 global_rt_runtime(void)
{
if (sysctl_sched_rt_runtime < 0)
return RUNTIME_INF;
return (u64)sysctl_sched_rt_runtime * NSEC_PER_USEC;
}
static inline int task_current(struct rq *rq, struct task_struct *p)
{
return rq->curr == p;
}
static inline int task_running(struct rq *rq, struct task_struct *p)
{
#ifdef CONFIG_SMP
return p->on_cpu;
#else
return task_current(rq, p);
#endif
}
static inline void prepare_lock_switch(struct rq *rq, struct task_struct *next)
{
#ifdef CONFIG_SMP
next->on_cpu = 1;
#endif
}
static inline void finish_lock_switch(struct rq *rq, struct task_struct *prev)
{
#ifdef CONFIG_SMP
smp_wmb();
prev->on_cpu = 0;
#endif
#ifdef CONFIG_DEBUG_SPINLOCK
rq->lock.owner = current;
#endif
spin_acquire(&rq->lock.dep_map, 0, 0, _THIS_IP_);
raw_spin_unlock_irq(&rq->lock);
}
static inline void prepare_lock_switch(struct rq *rq, struct task_struct *next)
{
#ifdef CONFIG_SMP
next->on_cpu = 1;
#endif
#ifdef __ARCH_WANT_INTERRUPTS_ON_CTXSW
raw_spin_unlock_irq(&rq->lock);
#else
raw_spin_unlock(&rq->lock);
#endif
}
static inline void finish_lock_switch(struct rq *rq, struct task_struct *prev)
{
#ifdef CONFIG_SMP
smp_wmb();
prev->on_cpu = 0;
#endif
#ifndef __ARCH_WANT_INTERRUPTS_ON_CTXSW
local_irq_enable();
#endif
}
static inline struct rq *__task_rq_lock(struct task_struct *p)
__acquires(rq->lock)
{
struct rq *rq;
lockdep_assert_held(&p->pi_lock);
for (;;) {
rq = task_rq(p);
raw_spin_lock(&rq->lock);
if (likely(rq == task_rq(p)))
return rq;
raw_spin_unlock(&rq->lock);
}
}
static struct rq *task_rq_lock(struct task_struct *p, unsigned long *flags)
__acquires(p->pi_lock)
__acquires(rq->lock)
{
struct rq *rq;
for (;;) {
raw_spin_lock_irqsave(&p->pi_lock, *flags);
rq = task_rq(p);
raw_spin_lock(&rq->lock);
if (likely(rq == task_rq(p)))
return rq;
raw_spin_unlock(&rq->lock);
raw_spin_unlock_irqrestore(&p->pi_lock, *flags);
}
}
static void __task_rq_unlock(struct rq *rq)
__releases(rq->lock)
{
raw_spin_unlock(&rq->lock);
}
static inline void
task_rq_unlock(struct rq *rq, struct task_struct *p, unsigned long *flags)
__releases(rq->lock)
__releases(p->pi_lock)
{
raw_spin_unlock(&rq->lock);
raw_spin_unlock_irqrestore(&p->pi_lock, *flags);
}
static struct rq *this_rq_lock(void)
__acquires(rq->lock)
{
struct rq *rq;
local_irq_disable();
rq = this_rq();
raw_spin_lock(&rq->lock);
return rq;
}
static inline int hrtick_enabled(struct rq *rq)
{
if (!sched_feat(HRTICK))
return 0;
if (!cpu_active(cpu_of(rq)))
return 0;
return hrtimer_is_hres_active(&rq->hrtick_timer);
}
static void hrtick_clear(struct rq *rq)
{
if (hrtimer_active(&rq->hrtick_timer))
hrtimer_cancel(&rq->hrtick_timer);
}
static enum hrtimer_restart hrtick(struct hrtimer *timer)
{
struct rq *rq = container_of(timer, struct rq, hrtick_timer);
WARN_ON_ONCE(cpu_of(rq) != smp_processor_id());
raw_spin_lock(&rq->lock);
update_rq_clock(rq);
rq->curr->sched_class->task_tick(rq, rq->curr, 1);
raw_spin_unlock(&rq->lock);
return HRTIMER_NORESTART;
}
static void __hrtick_start(void *arg)
{
struct rq *rq = arg;
raw_spin_lock(&rq->lock);
hrtimer_restart(&rq->hrtick_timer);
rq->hrtick_csd_pending = 0;
raw_spin_unlock(&rq->lock);
}
static void hrtick_start(struct rq *rq, u64 delay)
{
struct hrtimer *timer = &rq->hrtick_timer;
ktime_t time = ktime_add_ns(timer->base->get_time(), delay);
hrtimer_set_expires(timer, time);
if (rq == this_rq()) {
hrtimer_restart(timer);
} else if (!rq->hrtick_csd_pending) {
__smp_call_function_single(cpu_of(rq), &rq->hrtick_csd, 0);
rq->hrtick_csd_pending = 1;
}
}
static int
hotplug_hrtick(struct notifier_block *nfb, unsigned long action, void *hcpu)
{
int cpu = (int)(long)hcpu;
switch (action) {
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
case CPU_DEAD:
case CPU_DEAD_FROZEN:
hrtick_clear(cpu_rq(cpu));
return NOTIFY_OK;
}
return NOTIFY_DONE;
}
static __init void init_hrtick(void)
{
hotcpu_notifier(hotplug_hrtick, 0);
}
static void hrtick_start(struct rq *rq, u64 delay)
{
__hrtimer_start_range_ns(&rq->hrtick_timer, ns_to_ktime(delay), 0,
HRTIMER_MODE_REL_PINNED, 0);
}
static inline void init_hrtick(void)
{
}
static void init_rq_hrtick(struct rq *rq)
{
#ifdef CONFIG_SMP
rq->hrtick_csd_pending = 0;
rq->hrtick_csd.flags = 0;
rq->hrtick_csd.func = __hrtick_start;
rq->hrtick_csd.info = rq;
#endif
hrtimer_init(&rq->hrtick_timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
rq->hrtick_timer.function = hrtick;
}
static inline void hrtick_clear(struct rq *rq)
{
}
static inline void init_rq_hrtick(struct rq *rq)
{
}
static inline void init_hrtick(void)
{
}
static void resched_task(struct task_struct *p)
{
int cpu;
assert_raw_spin_locked(&task_rq(p)->lock);
if (test_tsk_need_resched(p))
return;
set_tsk_need_resched(p);
cpu = task_cpu(p);
if (cpu == smp_processor_id())
return;
smp_mb();
if (!tsk_is_polling(p))
smp_send_reschedule(cpu);
}
static void resched_cpu(int cpu)
{
struct rq *rq = cpu_rq(cpu);
unsigned long flags;
if (!raw_spin_trylock_irqsave(&rq->lock, flags))
return;
resched_task(cpu_curr(cpu));
raw_spin_unlock_irqrestore(&rq->lock, flags);
}
int get_nohz_timer_target(void)
{
int cpu = smp_processor_id();
int i;
struct sched_domain *sd;
rcu_read_lock();
for_each_domain(cpu, sd) {
for_each_cpu(i, sched_domain_span(sd)) {
if (!idle_cpu(i)) {
cpu = i;
goto unlock;
}
}
}
unlock:
rcu_read_unlock();
return cpu;
}
void wake_up_idle_cpu(int cpu)
{
struct rq *rq = cpu_rq(cpu);
if (cpu == smp_processor_id())
return;
if (rq->curr != rq->idle)
return;
set_tsk_need_resched(rq->idle);
smp_mb();
if (!tsk_is_polling(rq->idle))
smp_send_reschedule(cpu);
}
static u64 sched_avg_period(void)
{
return (u64)sysctl_sched_time_avg * NSEC_PER_MSEC / 2;
}
static void sched_avg_update(struct rq *rq)
{
s64 period = sched_avg_period();
while ((s64)(rq->clock - rq->age_stamp) > period) {
asm("" : "+rm" (rq->age_stamp));
rq->age_stamp += period;
rq->rt_avg /= 2;
}
}
static void sched_rt_avg_update(struct rq *rq, u64 rt_delta)
{
rq->rt_avg += rt_delta;
sched_avg_update(rq);
}
static void resched_task(struct task_struct *p)
{
assert_raw_spin_locked(&task_rq(p)->lock);
set_tsk_need_resched(p);
}
static void sched_rt_avg_update(struct rq *rq, u64 rt_delta)
{
}
static void sched_avg_update(struct rq *rq)
{
}
static unsigned long
calc_delta_mine(unsigned long delta_exec, unsigned long weight,
struct load_weight *lw)
{
u64 tmp;
if (likely(weight > (1UL << SCHED_LOAD_RESOLUTION)))
tmp = (u64)delta_exec * scale_load_down(weight);
else
tmp = (u64)delta_exec;
if (!lw->inv_weight) {
unsigned long w = scale_load_down(lw->weight);
if (BITS_PER_LONG > 32 && unlikely(w >= WMULT_CONST))
lw->inv_weight = 1;
else if (unlikely(!w))
lw->inv_weight = WMULT_CONST;
else
lw->inv_weight = WMULT_CONST / w;
}
if (unlikely(tmp > WMULT_CONST))
tmp = SRR(SRR(tmp, WMULT_SHIFT/2) * lw->inv_weight,
WMULT_SHIFT/2);
else
tmp = SRR(tmp * lw->inv_weight, WMULT_SHIFT);
return (unsigned long)min(tmp, (u64)(unsigned long)LONG_MAX);
}
static inline void update_load_add(struct load_weight *lw, unsigned long inc)
{
lw->weight += inc;
lw->inv_weight = 0;
}
static inline void update_load_sub(struct load_weight *lw, unsigned long dec)
{
lw->weight -= dec;
lw->inv_weight = 0;
}
static inline void update_load_set(struct load_weight *lw, unsigned long w)
{
lw->weight = w;
lw->inv_weight = 0;
}
static inline void cpuacct_charge(struct task_struct *tsk, u64 cputime) {}
static inline void cpuacct_update_stats(struct task_struct *tsk,
enum cpuacct_stat_index idx, cputime_t val) {}
static inline void inc_cpu_load(struct rq *rq, unsigned long load)
{
update_load_add(&rq->load, load);
}
static inline void dec_cpu_load(struct rq *rq, unsigned long load)
{
update_load_sub(&rq->load, load);
}
static int walk_tg_tree(tg_visitor down, tg_visitor up, void *data)
{
struct task_group *parent, *child;
int ret;
rcu_read_lock();
parent = &root_task_group;
down:
ret = (*down)(parent, data);
if (ret)
goto out_unlock;
list_for_each_entry_rcu(child, &parent->children, siblings) {
parent = child;
goto down;
up:
continue;
}
ret = (*up)(parent, data);
if (ret)
goto out_unlock;
child = parent;
parent = parent->parent;
if (parent)
goto up;
out_unlock:
rcu_read_unlock();
return ret;
}
static int tg_nop(struct task_group *tg, void *data)
{
return 0;
}
static unsigned long weighted_cpuload(const int cpu)
{
return cpu_rq(cpu)->load.weight;
}
static unsigned long source_load(int cpu, int type)
{
struct rq *rq = cpu_rq(cpu);
unsigned long total = weighted_cpuload(cpu);
if (type == 0 || !sched_feat(LB_BIAS))
return total;
return min(rq->cpu_load[type-1], total);
}
static unsigned long target_load(int cpu, int type)
{
struct rq *rq = cpu_rq(cpu);
unsigned long total = weighted_cpuload(cpu);
if (type == 0 || !sched_feat(LB_BIAS))
return total;
return max(rq->cpu_load[type-1], total);
}
static unsigned long power_of(int cpu)
{
return cpu_rq(cpu)->cpu_power;
}
static unsigned long cpu_avg_load_per_task(int cpu)
{
struct rq *rq = cpu_rq(cpu);
unsigned long nr_running = ACCESS_ONCE(rq->nr_running);
if (nr_running)
rq->avg_load_per_task = rq->load.weight / nr_running;
else
rq->avg_load_per_task = 0;
return rq->avg_load_per_task;
}
static inline int _double_lock_balance(struct rq *this_rq, struct rq *busiest)
__releases(this_rq->lock)
__acquires(busiest->lock)
__acquires(this_rq->lock)
{
raw_spin_unlock(&this_rq->lock);
double_rq_lock(this_rq, busiest);
return 1;
}
static int _double_lock_balance(struct rq *this_rq, struct rq *busiest)
__releases(this_rq->lock)
__acquires(busiest->lock)
__acquires(this_rq->lock)
{
int ret = 0;
if (unlikely(!raw_spin_trylock(&busiest->lock))) {
if (busiest < this_rq) {
raw_spin_unlock(&this_rq->lock);
raw_spin_lock(&busiest->lock);
raw_spin_lock_nested(&this_rq->lock,
SINGLE_DEPTH_NESTING);
ret = 1;
} else
raw_spin_lock_nested(&busiest->lock,
SINGLE_DEPTH_NESTING);
}
return ret;
}
static int double_lock_balance(struct rq *this_rq, struct rq *busiest)
{
if (unlikely(!irqs_disabled())) {
raw_spin_unlock(&this_rq->lock);
BUG_ON(1);
}
return _double_lock_balance(this_rq, busiest);
}
static inline void double_unlock_balance(struct rq *this_rq, struct rq *busiest)
__releases(busiest->lock)
{
raw_spin_unlock(&busiest->lock);
lock_set_subclass(&this_rq->lock.dep_map, 0, _RET_IP_);
}
static void double_rq_lock(struct rq *rq1, struct rq *rq2)
__acquires(rq1->lock)
__acquires(rq2->lock)
{
BUG_ON(!irqs_disabled());
if (rq1 == rq2) {
raw_spin_lock(&rq1->lock);
__acquire(rq2->lock);
} else {
if (rq1 < rq2) {
raw_spin_lock(&rq1->lock);
raw_spin_lock_nested(&rq2->lock, SINGLE_DEPTH_NESTING);
} else {
raw_spin_lock(&rq2->lock);
raw_spin_lock_nested(&rq1->lock, SINGLE_DEPTH_NESTING);
}
}
}
static void double_rq_unlock(struct rq *rq1, struct rq *rq2)
__releases(rq1->lock)
__releases(rq2->lock)
{
raw_spin_unlock(&rq1->lock);
if (rq1 != rq2)
raw_spin_unlock(&rq2->lock);
else
__release(rq2->lock);
}
static void double_rq_lock(struct rq *rq1, struct rq *rq2)
__acquires(rq1->lock)
__acquires(rq2->lock)
{
BUG_ON(!irqs_disabled());
BUG_ON(rq1 != rq2);
raw_spin_lock(&rq1->lock);
__acquire(rq2->lock);
}
static void double_rq_unlock(struct rq *rq1, struct rq *rq2)
__releases(rq1->lock)
__releases(rq2->lock)
{
BUG_ON(rq1 != rq2);
raw_spin_unlock(&rq1->lock);
__release(rq2->lock);
}
static inline void __set_task_cpu(struct task_struct *p, unsigned int cpu)
{
set_task_rq(p, cpu);
#ifdef CONFIG_SMP
smp_wmb();
task_thread_info(p)->cpu = cpu;
#endif
}
static void inc_nr_running(struct rq *rq)
{
rq->nr_running++;
}
static void dec_nr_running(struct rq *rq)
{
rq->nr_running--;
}
static void set_load_weight(struct task_struct *p)
{
int prio = p->static_prio - MAX_RT_PRIO;
struct load_weight *load = &p->se.load;
if (p->policy == SCHED_IDLE) {
load->weight = scale_load(WEIGHT_IDLEPRIO);
load->inv_weight = WMULT_IDLEPRIO;
return;
}
load->weight = scale_load(prio_to_weight[prio]);
load->inv_weight = prio_to_wmult[prio];
}
static void enqueue_task(struct rq *rq, struct task_struct *p, int flags)
{
update_rq_clock(rq);
sched_info_queued(p);
p->sched_class->enqueue_task(rq, p, flags);
}
static void dequeue_task(struct rq *rq, struct task_struct *p, int flags)
{
update_rq_clock(rq);
sched_info_dequeued(p);
p->sched_class->dequeue_task(rq, p, flags);
}
static void activate_task(struct rq *rq, struct task_struct *p, int flags)
{
if (task_contributes_to_load(p))
rq->nr_uninterruptible--;
enqueue_task(rq, p, flags);
inc_nr_running(rq);
}
static void deactivate_task(struct rq *rq, struct task_struct *p, int flags)
{
if (task_contributes_to_load(p))
rq->nr_uninterruptible++;
dequeue_task(rq, p, flags);
dec_nr_running(rq);
}
void enable_sched_clock_irqtime(void)
{
sched_clock_irqtime = 1;
}
void disable_sched_clock_irqtime(void)
{
sched_clock_irqtime = 0;
}
static inline void irq_time_write_begin(void)
{
__this_cpu_inc(irq_time_seq.sequence);
smp_wmb();
}
static inline void irq_time_write_end(void)
{
smp_wmb();
__this_cpu_inc(irq_time_seq.sequence);
}
static inline u64 irq_time_read(int cpu)
{
u64 irq_time;
unsigned seq;
do {
seq = read_seqcount_begin(&per_cpu(irq_time_seq, cpu));
irq_time = per_cpu(cpu_softirq_time, cpu) +
per_cpu(cpu_hardirq_time, cpu);
} while (read_seqcount_retry(&per_cpu(irq_time_seq, cpu), seq));
return irq_time;
}
static inline void irq_time_write_begin(void)
{
}
static inline void irq_time_write_end(void)
{
}
static inline u64 irq_time_read(int cpu)
{
return per_cpu(cpu_softirq_time, cpu) + per_cpu(cpu_hardirq_time, cpu);
}
void account_system_vtime(struct task_struct *curr)
{
unsigned long flags;
s64 delta;
int cpu;
if (!sched_clock_irqtime)
return;
local_irq_save(flags);
cpu = smp_processor_id();
delta = sched_clock_cpu(cpu) - __this_cpu_read(irq_start_time);
__this_cpu_add(irq_start_time, delta);
irq_time_write_begin();
if (hardirq_count())
__this_cpu_add(cpu_hardirq_time, delta);
else if (in_serving_softirq() && curr != this_cpu_ksoftirqd())
__this_cpu_add(cpu_softirq_time, delta);
irq_time_write_end();
local_irq_restore(flags);
}
static inline u64 steal_ticks(u64 steal)
{
if (unlikely(steal > NSEC_PER_SEC))
return div_u64(steal, TICK_NSEC);
return __iter_div_u64_rem(steal, TICK_NSEC, &steal);
}
static void update_rq_clock_task(struct rq *rq, s64 delta)
{
#if defined(CONFIG_IRQ_TIME_ACCOUNTING) || defined(CONFIG_PARAVIRT_TIME_ACCOUNTING)
s64 steal = 0, irq_delta = 0;
#endif
#ifdef CONFIG_IRQ_TIME_ACCOUNTING
irq_delta = irq_time_read(cpu_of(rq)) - rq->prev_irq_time;
if (irq_delta > delta)
irq_delta = delta;
rq->prev_irq_time += irq_delta;
delta -= irq_delta;
#endif
#ifdef CONFIG_PARAVIRT_TIME_ACCOUNTING
if (static_branch((&paravirt_steal_rq_enabled))) {
u64 st;
steal = paravirt_steal_clock(cpu_of(rq));
steal -= rq->prev_steal_time_rq;
if (unlikely(steal > delta))
steal = delta;
st = steal_ticks(steal);
steal = st * TICK_NSEC;
rq->prev_steal_time_rq += steal;
delta -= steal;
}
#endif
rq->clock_task += delta;
#if defined(CONFIG_IRQ_TIME_ACCOUNTING) || defined(CONFIG_PARAVIRT_TIME_ACCOUNTING)
if ((irq_delta + steal) && sched_feat(NONTASK_POWER))
sched_rt_avg_update(rq, irq_delta + steal);
#endif
}
static int irqtime_account_hi_update(void)
{
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
unsigned long flags;
u64 latest_ns;
int ret = 0;
local_irq_save(flags);
latest_ns = this_cpu_read(cpu_hardirq_time);
if (cputime64_gt(nsecs_to_cputime64(latest_ns), cpustat->irq))
ret = 1;
local_irq_restore(flags);
return ret;
}
static int irqtime_account_si_update(void)
{
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
unsigned long flags;
u64 latest_ns;
int ret = 0;
local_irq_save(flags);
latest_ns = this_cpu_read(cpu_softirq_time);
if (cputime64_gt(nsecs_to_cputime64(latest_ns), cpustat->softirq))
ret = 1;
local_irq_restore(flags);
return ret;
}
void sched_set_stop_task(int cpu, struct task_struct *stop)
{
struct sched_param param = { .sched_priority = MAX_RT_PRIO - 1 };
struct task_struct *old_stop = cpu_rq(cpu)->stop;
if (stop) {
sched_setscheduler_nocheck(stop, SCHED_FIFO, &param);
stop->sched_class = &stop_sched_class;
}
cpu_rq(cpu)->stop = stop;
if (old_stop) {
old_stop->sched_class = &rt_sched_class;
}
}
static inline int __normal_prio(struct task_struct *p)
{
return p->static_prio;
}
static inline int normal_prio(struct task_struct *p)
{
int prio;
if (task_has_rt_policy(p))
prio = MAX_RT_PRIO-1 - p->rt_priority;
else
prio = __normal_prio(p);
return prio;
}
static int effective_prio(struct task_struct *p)
{
p->normal_prio = normal_prio(p);
if (!rt_prio(p->prio))
return p->normal_prio;
return p->prio;
}
inline int task_curr(const struct task_struct *p)
{
return cpu_curr(task_cpu(p)) == p;
}
static inline void check_class_changed(struct rq *rq, struct task_struct *p,
const struct sched_class *prev_class,
int oldprio)
{
if (prev_class != p->sched_class) {
if (prev_class->switched_from)
prev_class->switched_from(rq, p);
p->sched_class->switched_to(rq, p);
} else if (oldprio != p->prio)
p->sched_class->prio_changed(rq, p, oldprio);
}
static void check_preempt_curr(struct rq *rq, struct task_struct *p, int flags)
{
const struct sched_class *class;
if (p->sched_class == rq->curr->sched_class) {
rq->curr->sched_class->check_preempt_curr(rq, p, flags);
} else {
for_each_class(class) {
if (class == rq->curr->sched_class)
break;
if (class == p->sched_class) {
resched_task(rq->curr);
break;
}
}
}
if (rq->curr->on_rq && test_tsk_need_resched(rq->curr))
rq->skip_clock_update = 1;
}
static int
task_hot(struct task_struct *p, u64 now, struct sched_domain *sd)
{
s64 delta;
if (p->sched_class != &fair_sched_class)
return 0;
if (unlikely(p->policy == SCHED_IDLE))
return 0;
if (sched_feat(CACHE_HOT_BUDDY) && this_rq()->nr_running &&
(&p->se == cfs_rq_of(&p->se)->next ||
&p->se == cfs_rq_of(&p->se)->last))
return 1;
if (sysctl_sched_migration_cost == -1)
return 1;
if (sysctl_sched_migration_cost == 0)
return 0;
delta = now - p->se.exec_start;
return delta < (s64)sysctl_sched_migration_cost;
}
void set_task_cpu(struct task_struct *p, unsigned int new_cpu)
{
#ifdef CONFIG_SCHED_DEBUG
WARN_ON_ONCE(p->state != TASK_RUNNING && p->state != TASK_WAKING &&
!(task_thread_info(p)->preempt_count & PREEMPT_ACTIVE));
#ifdef CONFIG_LOCKDEP
WARN_ON_ONCE(debug_locks && !(lockdep_is_held(&p->pi_lock) ||
lockdep_is_held(&task_rq(p)->lock)));
#endif
#endif
trace_sched_migrate_task(p, new_cpu);
if (task_cpu(p) != new_cpu) {
p->se.nr_migrations++;
perf_sw_event(PERF_COUNT_SW_CPU_MIGRATIONS, 1, NULL, 0);
}
__set_task_cpu(p, new_cpu);
}
unsigned long wait_task_inactive(struct task_struct *p, long match_state)
{
unsigned long flags;
int running, on_rq;
unsigned long ncsw;
struct rq *rq;
for (;;) {
rq = task_rq(p);
while (task_running(rq, p)) {
if (match_state && unlikely(p->state != match_state))
return 0;
cpu_relax();
}
rq = task_rq_lock(p, &flags);
trace_sched_wait_task(p);
running = task_running(rq, p);
on_rq = p->on_rq;
ncsw = 0;
if (!match_state || p->state == match_state)
ncsw = p->nvcsw | LONG_MIN;
task_rq_unlock(rq, p, &flags);
if (unlikely(!ncsw))
break;
if (unlikely(running)) {
cpu_relax();
continue;
}
if (unlikely(on_rq)) {
ktime_t to = ktime_set(0, NSEC_PER_SEC/HZ);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_hrtimeout(&to, HRTIMER_MODE_REL);
continue;
}
break;
}
return ncsw;
}
void kick_process(struct task_struct *p)
{
int cpu;
preempt_disable();
cpu = task_cpu(p);
if ((cpu != smp_processor_id()) && task_curr(p))
smp_send_reschedule(cpu);
preempt_enable();
}
static int select_fallback_rq(int cpu, struct task_struct *p)
{
int dest_cpu;
const struct cpumask *nodemask = cpumask_of_node(cpu_to_node(cpu));
for_each_cpu_and(dest_cpu, nodemask, cpu_active_mask)
if (cpumask_test_cpu(dest_cpu, &p->cpus_allowed))
return dest_cpu;
dest_cpu = cpumask_any_and(&p->cpus_allowed, cpu_active_mask);
if (dest_cpu < nr_cpu_ids)
return dest_cpu;
dest_cpu = cpuset_cpus_allowed_fallback(p);
if (p->mm && printk_ratelimit()) {
printk(KERN_INFO "process %d (%s) no longer affine to cpu%d\n",
task_pid_nr(p), p->comm, cpu);
}
return dest_cpu;
}
static inline
int select_task_rq(struct task_struct *p, int sd_flags, int wake_flags)
{
int cpu = p->sched_class->select_task_rq(p, sd_flags, wake_flags);
if (unlikely(!cpumask_test_cpu(cpu, &p->cpus_allowed) ||
!cpu_online(cpu)))
cpu = select_fallback_rq(task_cpu(p), p);
return cpu;
}
static void update_avg(u64 *avg, u64 sample)
{
s64 diff = sample - *avg;
*avg += diff >> 3;
}
static void
ttwu_stat(struct task_struct *p, int cpu, int wake_flags)
{
#ifdef CONFIG_SCHEDSTATS
struct rq *rq = this_rq();
#ifdef CONFIG_SMP
int this_cpu = smp_processor_id();
if (cpu == this_cpu) {
schedstat_inc(rq, ttwu_local);
schedstat_inc(p, se.statistics.nr_wakeups_local);
} else {
struct sched_domain *sd;
schedstat_inc(p, se.statistics.nr_wakeups_remote);
rcu_read_lock();
for_each_domain(this_cpu, sd) {
if (cpumask_test_cpu(cpu, sched_domain_span(sd))) {
schedstat_inc(sd, ttwu_wake_remote);
break;
}
}
rcu_read_unlock();
}
if (wake_flags & WF_MIGRATED)
schedstat_inc(p, se.statistics.nr_wakeups_migrate);
#endif
schedstat_inc(rq, ttwu_count);
schedstat_inc(p, se.statistics.nr_wakeups);
if (wake_flags & WF_SYNC)
schedstat_inc(p, se.statistics.nr_wakeups_sync);
#endif
}
static void ttwu_activate(struct rq *rq, struct task_struct *p, int en_flags)
{
activate_task(rq, p, en_flags);
p->on_rq = 1;
if (p->flags & PF_WQ_WORKER)
wq_worker_waking_up(p, cpu_of(rq));
}
static void
ttwu_do_wakeup(struct rq *rq, struct task_struct *p, int wake_flags)
{
trace_sched_wakeup(p, true);
check_preempt_curr(rq, p, wake_flags);
p->state = TASK_RUNNING;
#ifdef CONFIG_SMP
if (p->sched_class->task_woken)
p->sched_class->task_woken(rq, p);
if (rq->idle_stamp) {
u64 delta = rq->clock - rq->idle_stamp;
u64 max = 2*sysctl_sched_migration_cost;
if (delta > max)
rq->avg_idle = max;
else
update_avg(&rq->avg_idle, delta);
rq->idle_stamp = 0;
}
#endif
}
static void
ttwu_do_activate(struct rq *rq, struct task_struct *p, int wake_flags)
{
#ifdef CONFIG_SMP
if (p->sched_contributes_to_load)
rq->nr_uninterruptible--;
#endif
ttwu_activate(rq, p, ENQUEUE_WAKEUP | ENQUEUE_WAKING);
ttwu_do_wakeup(rq, p, wake_flags);
}
static int ttwu_remote(struct task_struct *p, int wake_flags)
{
struct rq *rq;
int ret = 0;
rq = __task_rq_lock(p);
if (p->on_rq) {
ttwu_do_wakeup(rq, p, wake_flags);
ret = 1;
}
__task_rq_unlock(rq);
return ret;
}
static void sched_ttwu_do_pending(struct task_struct *list)
{
struct rq *rq = this_rq();
raw_spin_lock(&rq->lock);
while (list) {
struct task_struct *p = list;
list = list->wake_entry;
ttwu_do_activate(rq, p, 0);
}
raw_spin_unlock(&rq->lock);
}
static void sched_ttwu_pending(void)
{
struct rq *rq = this_rq();
struct task_struct *list = xchg(&rq->wake_list, NULL);
if (!list)
return;
sched_ttwu_do_pending(list);
}
void scheduler_ipi(void)
{
struct rq *rq = this_rq();
struct task_struct *list = xchg(&rq->wake_list, NULL);
if (!list)
return;
irq_enter();
sched_ttwu_do_pending(list);
irq_exit();
}
static void ttwu_queue_remote(struct task_struct *p, int cpu)
{
struct rq *rq = cpu_rq(cpu);
struct task_struct *next = rq->wake_list;
for (;;) {
struct task_struct *old = next;
p->wake_entry = next;
next = cmpxchg(&rq->wake_list, old, p);
if (next == old)
break;
}
if (!next)
smp_send_reschedule(cpu);
}
static int ttwu_activate_remote(struct task_struct *p, int wake_flags)
{
struct rq *rq;
int ret = 0;
rq = __task_rq_lock(p);
if (p->on_cpu) {
ttwu_activate(rq, p, ENQUEUE_WAKEUP);
ttwu_do_wakeup(rq, p, wake_flags);
ret = 1;
}
__task_rq_unlock(rq);
return ret;
}
static void ttwu_queue(struct task_struct *p, int cpu)
{
struct rq *rq = cpu_rq(cpu);
#if defined(CONFIG_SMP)
if (sched_feat(TTWU_QUEUE) && cpu != smp_processor_id()) {
sched_clock_cpu(cpu);
ttwu_queue_remote(p, cpu);
return;
}
#endif
raw_spin_lock(&rq->lock);
ttwu_do_activate(rq, p, 0);
raw_spin_unlock(&rq->lock);
}
static int
try_to_wake_up(struct task_struct *p, unsigned int state, int wake_flags)
{
unsigned long flags;
int cpu, success = 0;
smp_wmb();
raw_spin_lock_irqsave(&p->pi_lock, flags);
if (!(p->state & state))
goto out;
success = 1;
cpu = task_cpu(p);
if (p->on_rq && ttwu_remote(p, wake_flags))
goto stat;
#ifdef CONFIG_SMP
while (p->on_cpu) {
#ifdef __ARCH_WANT_INTERRUPTS_ON_CTXSW
if (ttwu_activate_remote(p, wake_flags))
goto stat;
#else
cpu_relax();
#endif
}
smp_rmb();
p->sched_contributes_to_load = !!task_contributes_to_load(p);
p->state = TASK_WAKING;
if (p->sched_class->task_waking)
p->sched_class->task_waking(p);
cpu = select_task_rq(p, SD_BALANCE_WAKE, wake_flags);
if (task_cpu(p) != cpu) {
wake_flags |= WF_MIGRATED;
set_task_cpu(p, cpu);
}
#endif
ttwu_queue(p, cpu);
stat:
ttwu_stat(p, cpu, wake_flags);
out:
raw_spin_unlock_irqrestore(&p->pi_lock, flags);
return success;
}
static void try_to_wake_up_local(struct task_struct *p)
{
struct rq *rq = task_rq(p);
BUG_ON(rq != this_rq());
BUG_ON(p == current);
lockdep_assert_held(&rq->lock);
if (!raw_spin_trylock(&p->pi_lock)) {
raw_spin_unlock(&rq->lock);
raw_spin_lock(&p->pi_lock);
raw_spin_lock(&rq->lock);
}
if (!(p->state & TASK_NORMAL))
goto out;
if (!p->on_rq)
ttwu_activate(rq, p, ENQUEUE_WAKEUP);
ttwu_do_wakeup(rq, p, 0);
ttwu_stat(p, smp_processor_id(), 0);
out:
raw_spin_unlock(&p->pi_lock);
}
int wake_up_process(struct task_struct *p)
{
return try_to_wake_up(p, TASK_ALL, 0);
}
int wake_up_state(struct task_struct *p, unsigned int state)
{
return try_to_wake_up(p, state, 0);
}
static void __sched_fork(struct task_struct *p)
{
p->on_rq = 0;
p->se.on_rq = 0;
p->se.exec_start = 0;
p->se.sum_exec_runtime = 0;
p->se.prev_sum_exec_runtime = 0;
p->se.nr_migrations = 0;
p->se.vruntime = 0;
INIT_LIST_HEAD(&p->se.group_node);
#ifdef CONFIG_SCHEDSTATS
memset(&p->se.statistics, 0, sizeof(p->se.statistics));
#endif
INIT_LIST_HEAD(&p->rt.run_list);
#ifdef CONFIG_PREEMPT_NOTIFIERS
INIT_HLIST_HEAD(&p->preempt_notifiers);
#endif
}
void sched_fork(struct task_struct *p)
{
unsigned long flags;
int cpu = get_cpu();
__sched_fork(p);
p->state = TASK_RUNNING;
if (unlikely(p->sched_reset_on_fork)) {
if (p->policy == SCHED_FIFO || p->policy == SCHED_RR) {
p->policy = SCHED_NORMAL;
p->normal_prio = p->static_prio;
}
if (PRIO_TO_NICE(p->static_prio) < 0) {
p->static_prio = NICE_TO_PRIO(0);
p->normal_prio = p->static_prio;
set_load_weight(p);
}
p->sched_reset_on_fork = 0;
}
p->prio = current->normal_prio;
if (!rt_prio(p->prio))
p->sched_class = &fair_sched_class;
if (p->sched_class->task_fork)
p->sched_class->task_fork(p);
raw_spin_lock_irqsave(&p->pi_lock, flags);
set_task_cpu(p, cpu);
raw_spin_unlock_irqrestore(&p->pi_lock, flags);
#if defined(CONFIG_SCHEDSTATS) || defined(CONFIG_TASK_DELAY_ACCT)
if (likely(sched_info_on()))
memset(&p->sched_info, 0, sizeof(p->sched_info));
#endif
#if defined(CONFIG_SMP)
p->on_cpu = 0;
#endif
#ifdef CONFIG_PREEMPT_COUNT
task_thread_info(p)->preempt_count = 1;
#endif
#ifdef CONFIG_SMP
plist_node_init(&p->pushable_tasks, MAX_PRIO);
#endif
put_cpu();
}
void wake_up_new_task(struct task_struct *p)
{
unsigned long flags;
struct rq *rq;
raw_spin_lock_irqsave(&p->pi_lock, flags);
#ifdef CONFIG_SMP
set_task_cpu(p, select_task_rq(p, SD_BALANCE_FORK, 0));
#endif
rq = __task_rq_lock(p);
activate_task(rq, p, 0);
p->on_rq = 1;
trace_sched_wakeup_new(p, true);
check_preempt_curr(rq, p, WF_FORK);
#ifdef CONFIG_SMP
if (p->sched_class->task_woken)
p->sched_class->task_woken(rq, p);
#endif
task_rq_unlock(rq, p, &flags);
}
void preempt_notifier_register(struct preempt_notifier *notifier)
{
hlist_add_head(&notifier->link, &current->preempt_notifiers);
}
void preempt_notifier_unregister(struct preempt_notifier *notifier)
{
hlist_del(&notifier->link);
}
static void fire_sched_in_preempt_notifiers(struct task_struct *curr)
{
struct preempt_notifier *notifier;
struct hlist_node *node;
hlist_for_each_entry(notifier, node, &curr->preempt_notifiers, link)
notifier->ops->sched_in(notifier, raw_smp_processor_id());
}
static void
fire_sched_out_preempt_notifiers(struct task_struct *curr,
struct task_struct *next)
{
struct preempt_notifier *notifier;
struct hlist_node *node;
hlist_for_each_entry(notifier, node, &curr->preempt_notifiers, link)
notifier->ops->sched_out(notifier, next);
}
static void fire_sched_in_preempt_notifiers(struct task_struct *curr)
{
}
static void
fire_sched_out_preempt_notifiers(struct task_struct *curr,
struct task_struct *next)
{
}
static inline void
prepare_task_switch(struct rq *rq, struct task_struct *prev,
struct task_struct *next)
{
sched_info_switch(prev, next);
perf_event_task_sched_out(prev, next);
fire_sched_out_preempt_notifiers(prev, next);
prepare_lock_switch(rq, next);
prepare_arch_switch(next);
trace_sched_switch(prev, next);
}
static void finish_task_switch(struct rq *rq, struct task_struct *prev)
__releases(rq->lock)
{
struct mm_struct *mm = rq->prev_mm;
long prev_state;
rq->prev_mm = NULL;
prev_state = prev->state;
finish_arch_switch(prev);
#ifdef __ARCH_WANT_INTERRUPTS_ON_CTXSW
local_irq_disable();
#endif
perf_event_task_sched_in(prev, current);
#ifdef __ARCH_WANT_INTERRUPTS_ON_CTXSW
local_irq_enable();
#endif
finish_lock_switch(rq, prev);
fire_sched_in_preempt_notifiers(current);
if (mm)
mmdrop(mm);
if (unlikely(prev_state == TASK_DEAD)) {
kprobe_flush_task(prev);
put_task_struct(prev);
}
}
static inline void pre_schedule(struct rq *rq, struct task_struct *prev)
{
if (prev->sched_class->pre_schedule)
prev->sched_class->pre_schedule(rq, prev);
}
static inline void post_schedule(struct rq *rq)
{
if (rq->post_schedule) {
unsigned long flags;
raw_spin_lock_irqsave(&rq->lock, flags);
if (rq->curr->sched_class->post_schedule)
rq->curr->sched_class->post_schedule(rq);
raw_spin_unlock_irqrestore(&rq->lock, flags);
rq->post_schedule = 0;
}
}
static inline void pre_schedule(struct rq *rq, struct task_struct *p)
{
}
static inline void post_schedule(struct rq *rq)
{
}
asmlinkage void schedule_tail(struct task_struct *prev)
__releases(rq->lock)
{
struct rq *rq = this_rq();
finish_task_switch(rq, prev);
post_schedule(rq);
#ifdef __ARCH_WANT_UNLOCKED_CTXSW
preempt_enable();
#endif
if (current->set_child_tid)
put_user(task_pid_vnr(current), current->set_child_tid);
}
static inline void
context_switch(struct rq *rq, struct task_struct *prev,
struct task_struct *next)
{
struct mm_struct *mm, *oldmm;
prepare_task_switch(rq, prev, next);
mm = next->mm;
oldmm = prev->active_mm;
arch_start_context_switch(prev);
if (!mm) {
next->active_mm = oldmm;
atomic_inc(&oldmm->mm_count);
enter_lazy_tlb(oldmm, next);
} else
switch_mm(oldmm, mm, next);
if (!prev->mm) {
prev->active_mm = NULL;
rq->prev_mm = oldmm;
}
#ifndef __ARCH_WANT_UNLOCKED_CTXSW
spin_release(&rq->lock.dep_map, 1, _THIS_IP_);
#endif
switch_to(prev, next, prev);
barrier();
finish_task_switch(this_rq(), prev);
}
unsigned long nr_running(void)
{
unsigned long i, sum = 0;
for_each_online_cpu(i)
sum += cpu_rq(i)->nr_running;
return sum;
}
unsigned long nr_uninterruptible(void)
{
unsigned long i, sum = 0;
for_each_possible_cpu(i)
sum += cpu_rq(i)->nr_uninterruptible;
if (unlikely((long)sum < 0))
sum = 0;
return sum;
}
unsigned long long nr_context_switches(void)
{
int i;
unsigned long long sum = 0;
for_each_possible_cpu(i)
sum += cpu_rq(i)->nr_switches;
return sum;
}
unsigned long nr_iowait(void)
{
unsigned long i, sum = 0;
for_each_possible_cpu(i)
sum += atomic_read(&cpu_rq(i)->nr_iowait);
return sum;
}
unsigned long nr_iowait_cpu(int cpu)
{
struct rq *this = cpu_rq(cpu);
return atomic_read(&this->nr_iowait);
}
unsigned long this_cpu_load(void)
{
struct rq *this = this_rq();
return this->cpu_load[0];
}
static long calc_load_fold_active(struct rq *this_rq)
{
long nr_active, delta = 0;
nr_active = this_rq->nr_running;
nr_active += (long) this_rq->nr_uninterruptible;
if (nr_active != this_rq->calc_load_active) {
delta = nr_active - this_rq->calc_load_active;
this_rq->calc_load_active = nr_active;
}
return delta;
}
static unsigned long
calc_load(unsigned long load, unsigned long exp, unsigned long active)
{
load *= exp;
load += active * (FIXED_1 - exp);
load += 1UL << (FSHIFT - 1);
return load >> FSHIFT;
}
static void calc_load_account_idle(struct rq *this_rq)
{
long delta;
delta = calc_load_fold_active(this_rq);
if (delta)
atomic_long_add(delta, &calc_load_tasks_idle);
}
static long calc_load_fold_idle(void)
{
long delta = 0;
if (atomic_long_read(&calc_load_tasks_idle))
delta = atomic_long_xchg(&calc_load_tasks_idle, 0);
return delta;
}
static unsigned long
fixed_power_int(unsigned long x, unsigned int frac_bits, unsigned int n)
{
unsigned long result = 1UL << frac_bits;
if (n) for (;;) {
if (n & 1) {
result *= x;
result += 1UL << (frac_bits - 1);
result >>= frac_bits;
}
n >>= 1;
if (!n)
break;
x *= x;
x += 1UL << (frac_bits - 1);
x >>= frac_bits;
}
return result;
}
static unsigned long
calc_load_n(unsigned long load, unsigned long exp,
unsigned long active, unsigned int n)
{
return calc_load(load, fixed_power_int(exp, FSHIFT, n), active);
}
static void calc_global_nohz(unsigned long ticks)
{
long delta, active, n;
if (time_before(jiffies, calc_load_update))
return;
delta = calc_load_fold_idle();
if (delta)
atomic_long_add(delta, &calc_load_tasks);
if (ticks >= LOAD_FREQ) {
n = ticks / LOAD_FREQ;
active = atomic_long_read(&calc_load_tasks);
active = active > 0 ? active * FIXED_1 : 0;
avenrun[0] = calc_load_n(avenrun[0], EXP_1, active, n);
avenrun[1] = calc_load_n(avenrun[1], EXP_5, active, n);
avenrun[2] = calc_load_n(avenrun[2], EXP_15, active, n);
calc_load_update += n * LOAD_FREQ;
}
}
static void calc_load_account_idle(struct rq *this_rq)
{
}
static inline long calc_load_fold_idle(void)
{
return 0;
}
static void calc_global_nohz(unsigned long ticks)
{
}
void get_avenrun(unsigned long *loads, unsigned long offset, int shift)
{
loads[0] = (avenrun[0] + offset) << shift;
loads[1] = (avenrun[1] + offset) << shift;
loads[2] = (avenrun[2] + offset) << shift;
}
void calc_global_load(unsigned long ticks)
{
long active;
calc_global_nohz(ticks);
if (time_before(jiffies, calc_load_update + 10))
return;
active = atomic_long_read(&calc_load_tasks);
active = active > 0 ? active * FIXED_1 : 0;
avenrun[0] = calc_load(avenrun[0], EXP_1, active);
avenrun[1] = calc_load(avenrun[1], EXP_5, active);
avenrun[2] = calc_load(avenrun[2], EXP_15, active);
calc_load_update += LOAD_FREQ;
}
static void calc_load_account_active(struct rq *this_rq)
{
long delta;
if (time_before(jiffies, this_rq->calc_load_update))
return;
delta = calc_load_fold_active(this_rq);
delta += calc_load_fold_idle();
if (delta)
atomic_long_add(delta, &calc_load_tasks);
this_rq->calc_load_update += LOAD_FREQ;
}
static unsigned long
decay_load_missed(unsigned long load, unsigned long missed_updates, int idx)
{
int j = 0;
if (!missed_updates)
return load;
if (missed_updates >= degrade_zero_ticks[idx])
return 0;
if (idx == 1)
return load >> missed_updates;
while (missed_updates) {
if (missed_updates % 2)
load = (load * degrade_factor[idx][j]) >> DEGRADE_SHIFT;
missed_updates >>= 1;
j++;
}
return load;
}
static void update_cpu_load(struct rq *this_rq)
{
unsigned long this_load = this_rq->load.weight;
unsigned long curr_jiffies = jiffies;
unsigned long pending_updates;
int i, scale;
this_rq->nr_load_updates++;
if (curr_jiffies == this_rq->last_load_update_tick)
return;
pending_updates = curr_jiffies - this_rq->last_load_update_tick;
this_rq->last_load_update_tick = curr_jiffies;
this_rq->cpu_load[0] = this_load;
for (i = 1, scale = 2; i < CPU_LOAD_IDX_MAX; i++, scale += scale) {
unsigned long old_load, new_load;
old_load = this_rq->cpu_load[i];
old_load = decay_load_missed(old_load, pending_updates - 1, i);
new_load = this_load;
if (new_load > old_load)
new_load += scale - 1;
this_rq->cpu_load[i] = (old_load * (scale - 1) + new_load) >> i;
}
sched_avg_update(this_rq);
}
static void update_cpu_load_active(struct rq *this_rq)
{
update_cpu_load(this_rq);
calc_load_account_active(this_rq);
}
void sched_exec(void)
{
struct task_struct *p = current;
unsigned long flags;
int dest_cpu;
raw_spin_lock_irqsave(&p->pi_lock, flags);
dest_cpu = p->sched_class->select_task_rq(p, SD_BALANCE_EXEC, 0);
if (dest_cpu == smp_processor_id())
goto unlock;
if (likely(cpu_active(dest_cpu))) {
struct migration_arg arg = { p, dest_cpu };
raw_spin_unlock_irqrestore(&p->pi_lock, flags);
stop_one_cpu(task_cpu(p), migration_cpu_stop, &arg);
return;
}
unlock:
raw_spin_unlock_irqrestore(&p->pi_lock, flags);
}
static u64 do_task_delta_exec(struct task_struct *p, struct rq *rq)
{
u64 ns = 0;
if (task_current(rq, p)) {
update_rq_clock(rq);
ns = rq->clock_task - p->se.exec_start;
if ((s64)ns < 0)
ns = 0;
}
return ns;
}
unsigned long long task_delta_exec(struct task_struct *p)
{
unsigned long flags;
struct rq *rq;
u64 ns = 0;
rq = task_rq_lock(p, &flags);
ns = do_task_delta_exec(p, rq);
task_rq_unlock(rq, p, &flags);
return ns;
}
unsigned long long task_sched_runtime(struct task_struct *p)
{
unsigned long flags;
struct rq *rq;
u64 ns = 0;
rq = task_rq_lock(p, &flags);
ns = p->se.sum_exec_runtime + do_task_delta_exec(p, rq);
task_rq_unlock(rq, p, &flags);
return ns;
}
void account_user_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled)
{
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
cputime64_t tmp;
p->utime = cputime_add(p->utime, cputime);
p->utimescaled = cputime_add(p->utimescaled, cputime_scaled);
account_group_user_time(p, cputime);
tmp = cputime_to_cputime64(cputime);
if (TASK_NICE(p) > 0)
cpustat->nice = cputime64_add(cpustat->nice, tmp);
else
cpustat->user = cputime64_add(cpustat->user, tmp);
cpuacct_update_stats(p, CPUACCT_STAT_USER, cputime);
acct_update_integrals(p);
}
static void account_guest_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled)
{
cputime64_t tmp;
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
tmp = cputime_to_cputime64(cputime);
p->utime = cputime_add(p->utime, cputime);
p->utimescaled = cputime_add(p->utimescaled, cputime_scaled);
account_group_user_time(p, cputime);
p->gtime = cputime_add(p->gtime, cputime);
if (TASK_NICE(p) > 0) {
cpustat->nice = cputime64_add(cpustat->nice, tmp);
cpustat->guest_nice = cputime64_add(cpustat->guest_nice, tmp);
} else {
cpustat->user = cputime64_add(cpustat->user, tmp);
cpustat->guest = cputime64_add(cpustat->guest, tmp);
}
}
static inline
void __account_system_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled, cputime64_t *target_cputime64)
{
cputime64_t tmp = cputime_to_cputime64(cputime);
p->stime = cputime_add(p->stime, cputime);
p->stimescaled = cputime_add(p->stimescaled, cputime_scaled);
account_group_system_time(p, cputime);
*target_cputime64 = cputime64_add(*target_cputime64, tmp);
cpuacct_update_stats(p, CPUACCT_STAT_SYSTEM, cputime);
acct_update_integrals(p);
}
void account_system_time(struct task_struct *p, int hardirq_offset,
cputime_t cputime, cputime_t cputime_scaled)
{
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
cputime64_t *target_cputime64;
if ((p->flags & PF_VCPU) && (irq_count() - hardirq_offset == 0)) {
account_guest_time(p, cputime, cputime_scaled);
return;
}
if (hardirq_count() - hardirq_offset)
target_cputime64 = &cpustat->irq;
else if (in_serving_softirq())
target_cputime64 = &cpustat->softirq;
else
target_cputime64 = &cpustat->system;
__account_system_time(p, cputime, cputime_scaled, target_cputime64);
}
void account_steal_time(cputime_t cputime)
{
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
cputime64_t cputime64 = cputime_to_cputime64(cputime);
cpustat->steal = cputime64_add(cpustat->steal, cputime64);
}
void account_idle_time(cputime_t cputime)
{
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
cputime64_t cputime64 = cputime_to_cputime64(cputime);
struct rq *rq = this_rq();
if (atomic_read(&rq->nr_iowait) > 0)
cpustat->iowait = cputime64_add(cpustat->iowait, cputime64);
else
cpustat->idle = cputime64_add(cpustat->idle, cputime64);
}
static __always_inline bool steal_account_process_tick(void)
{
#ifdef CONFIG_PARAVIRT
if (static_branch(&paravirt_steal_enabled)) {
u64 steal, st = 0;
steal = paravirt_steal_clock(smp_processor_id());
steal -= this_rq()->prev_steal_time;
st = steal_ticks(steal);
this_rq()->prev_steal_time += st * TICK_NSEC;
account_steal_time(st);
return st;
}
#endif
return false;
}
static void irqtime_account_process_tick(struct task_struct *p, int user_tick,
struct rq *rq)
{
cputime_t one_jiffy_scaled = cputime_to_scaled(cputime_one_jiffy);
cputime64_t tmp = cputime_to_cputime64(cputime_one_jiffy);
struct cpu_usage_stat *cpustat = &kstat_this_cpu.cpustat;
if (steal_account_process_tick())
return;
if (irqtime_account_hi_update()) {
cpustat->irq = cputime64_add(cpustat->irq, tmp);
} else if (irqtime_account_si_update()) {
cpustat->softirq = cputime64_add(cpustat->softirq, tmp);
} else if (this_cpu_ksoftirqd() == p) {
__account_system_time(p, cputime_one_jiffy, one_jiffy_scaled,
&cpustat->softirq);
} else if (user_tick) {
account_user_time(p, cputime_one_jiffy, one_jiffy_scaled);
} else if (p == rq->idle) {
account_idle_time(cputime_one_jiffy);
} else if (p->flags & PF_VCPU) {
account_guest_time(p, cputime_one_jiffy, one_jiffy_scaled);
} else {
__account_system_time(p, cputime_one_jiffy, one_jiffy_scaled,
&cpustat->system);
}
}
static void irqtime_account_idle_ticks(int ticks)
{
int i;
struct rq *rq = this_rq();
for (i = 0; i < ticks; i++)
irqtime_account_process_tick(current, 0, rq);
}
static void irqtime_account_idle_ticks(int ticks) {}
static void irqtime_account_process_tick(struct task_struct *p, int user_tick,
struct rq *rq) {}
void account_process_tick(struct task_struct *p, int user_tick)
{
cputime_t one_jiffy_scaled = cputime_to_scaled(cputime_one_jiffy);
struct rq *rq = this_rq();
if (sched_clock_irqtime) {
irqtime_account_process_tick(p, user_tick, rq);
return;
}
if (steal_account_process_tick())
return;
if (user_tick)
account_user_time(p, cputime_one_jiffy, one_jiffy_scaled);
else if ((p != rq->idle) || (irq_count() != HARDIRQ_OFFSET))
account_system_time(p, HARDIRQ_OFFSET, cputime_one_jiffy,
one_jiffy_scaled);
else
account_idle_time(cputime_one_jiffy);
}
void account_steal_ticks(unsigned long ticks)
{
account_steal_time(jiffies_to_cputime(ticks));
}
void account_idle_ticks(unsigned long ticks)
{
if (sched_clock_irqtime) {
irqtime_account_idle_ticks(ticks);
return;
}
account_idle_time(jiffies_to_cputime(ticks));
}
void task_times(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
*ut = p->utime;
*st = p->stime;
}
void thread_group_times(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
struct task_cputime cputime;
thread_group_cputime(p, &cputime);
*ut = cputime.utime;
*st = cputime.stime;
}
void task_times(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
cputime_t rtime, utime = p->utime, total = cputime_add(utime, p->stime);
rtime = nsecs_to_cputime(p->se.sum_exec_runtime);
if (total) {
u64 temp = rtime;
temp *= utime;
do_div(temp, total);
utime = (cputime_t)temp;
} else
utime = rtime;
p->prev_utime = max(p->prev_utime, utime);
p->prev_stime = max(p->prev_stime, cputime_sub(rtime, p->prev_utime));
*ut = p->prev_utime;
*st = p->prev_stime;
}
void thread_group_times(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
struct signal_struct *sig = p->signal;
struct task_cputime cputime;
cputime_t rtime, utime, total;
thread_group_cputime(p, &cputime);
total = cputime_add(cputime.utime, cputime.stime);
rtime = nsecs_to_cputime(cputime.sum_exec_runtime);
if (total) {
u64 temp = rtime;
temp *= cputime.utime;
do_div(temp, total);
utime = (cputime_t)temp;
} else
utime = rtime;
sig->prev_utime = max(sig->prev_utime, utime);
sig->prev_stime = max(sig->prev_stime,
cputime_sub(rtime, sig->prev_utime));
*ut = sig->prev_utime;
*st = sig->prev_stime;
}
void scheduler_tick(void)
{
int cpu = smp_processor_id();
struct rq *rq = cpu_rq(cpu);
struct task_struct *curr = rq->curr;
sched_clock_tick();
raw_spin_lock(&rq->lock);
update_rq_clock(rq);
update_cpu_load_active(rq);
curr->sched_class->task_tick(rq, curr, 0);
raw_spin_unlock(&rq->lock);
perf_event_task_tick();
#ifdef CONFIG_SMP
rq->idle_at_tick = idle_cpu(cpu);
trigger_load_balance(rq, cpu);
#endif
}
notrace unsigned long get_parent_ip(unsigned long addr)
{
if (in_lock_functions(addr)) {
addr = CALLER_ADDR2;
if (in_lock_functions(addr))
addr = CALLER_ADDR3;
}
return addr;
}
void __kprobes add_preempt_count(int val)
{
#ifdef CONFIG_DEBUG_PREEMPT
if (DEBUG_LOCKS_WARN_ON((preempt_count() < 0)))
return;
#endif
preempt_count() += val;
#ifdef CONFIG_DEBUG_PREEMPT
DEBUG_LOCKS_WARN_ON((preempt_count() & PREEMPT_MASK) >=
PREEMPT_MASK - 10);
#endif
if (preempt_count() == val)
trace_preempt_off(CALLER_ADDR0, get_parent_ip(CALLER_ADDR1));
}
void __kprobes sub_preempt_count(int val)
{
#ifdef CONFIG_DEBUG_PREEMPT
if (DEBUG_LOCKS_WARN_ON(val > preempt_count()))
return;
if (DEBUG_LOCKS_WARN_ON((val < PREEMPT_MASK) &&
!(preempt_count() & PREEMPT_MASK)))
return;
#endif
if (preempt_count() == val)
trace_preempt_on(CALLER_ADDR0, get_parent_ip(CALLER_ADDR1));
preempt_count() -= val;
}
static noinline void __schedule_bug(struct task_struct *prev)
{
struct pt_regs *regs = get_irq_regs();
printk(KERN_ERR "BUG: scheduling while atomic: %s/%d/0x%08x\n",
prev->comm, prev->pid, preempt_count());
debug_show_held_locks(prev);
print_modules();
if (irqs_disabled())
print_irqtrace_events(prev);
if (regs)
show_regs(regs);
else
dump_stack();
}
static inline void schedule_debug(struct task_struct *prev)
{
if (unlikely(in_atomic_preempt_off() && !prev->exit_state))
__schedule_bug(prev);
profile_hit(SCHED_PROFILING, __builtin_return_address(0));
schedstat_inc(this_rq(), sched_count);
}
static void put_prev_task(struct rq *rq, struct task_struct *prev)
{
if (prev->on_rq || rq->skip_clock_update < 0)
update_rq_clock(rq);
prev->sched_class->put_prev_task(rq, prev);
}
static inline struct task_struct *
pick_next_task(struct rq *rq)
{
const struct sched_class *class;
struct task_struct *p;
if (likely(rq->nr_running == rq->cfs.nr_running)) {
p = fair_sched_class.pick_next_task(rq);
if (likely(p))
return p;
}
for_each_class(class) {
p = class->pick_next_task(rq);
if (p)
return p;
}
BUG();
}
static void __sched __schedule(void)
{
struct task_struct *prev, *next;
unsigned long *switch_count;
struct rq *rq;
int cpu;
need_resched:
preempt_disable();
cpu = smp_processor_id();
rq = cpu_rq(cpu);
rcu_note_context_switch(cpu);
prev = rq->curr;
schedule_debug(prev);
if (sched_feat(HRTICK))
hrtick_clear(rq);
raw_spin_lock_irq(&rq->lock);
switch_count = &prev->nivcsw;
if (prev->state && !(preempt_count() & PREEMPT_ACTIVE)) {
if (unlikely(signal_pending_state(prev->state, prev))) {
prev->state = TASK_RUNNING;
} else {
deactivate_task(rq, prev, DEQUEUE_SLEEP);
prev->on_rq = 0;
if (prev->flags & PF_WQ_WORKER) {
struct task_struct *to_wakeup;
to_wakeup = wq_worker_sleeping(prev, cpu);
if (to_wakeup)
try_to_wake_up_local(to_wakeup);
}
}
switch_count = &prev->nvcsw;
}
pre_schedule(rq, prev);
if (unlikely(!rq->nr_running))
idle_balance(cpu, rq);
put_prev_task(rq, prev);
next = pick_next_task(rq);
clear_tsk_need_resched(prev);
rq->skip_clock_update = 0;
if (likely(prev != next)) {
rq->nr_switches++;
rq->curr = next;
++*switch_count;
context_switch(rq, prev, next);
cpu = smp_processor_id();
rq = cpu_rq(cpu);
} else
raw_spin_unlock_irq(&rq->lock);
post_schedule(rq);
preempt_enable_no_resched();
if (need_resched())
goto need_resched;
}
static inline void sched_submit_work(struct task_struct *tsk)
{
if (!tsk->state)
return;
if (blk_needs_flush_plug(tsk))
blk_schedule_flush_plug(tsk);
}
asmlinkage void __sched schedule(void)
{
struct task_struct *tsk = current;
sched_submit_work(tsk);
__schedule();
}
static inline bool owner_running(struct mutex *lock, struct task_struct *owner)
{
if (lock->owner != owner)
return false;
barrier();
return owner->on_cpu;
}
int mutex_spin_on_owner(struct mutex *lock, struct task_struct *owner)
{
if (!sched_feat(OWNER_SPIN))
return 0;
rcu_read_lock();
while (owner_running(lock, owner)) {
if (need_resched())
break;
arch_mutex_cpu_relax();
}
rcu_read_unlock();
return lock->owner == NULL;
}
asmlinkage void __sched notrace preempt_schedule(void)
{
struct thread_info *ti = current_thread_info();
if (likely(ti->preempt_count || irqs_disabled()))
return;
do {
add_preempt_count_notrace(PREEMPT_ACTIVE);
__schedule();
sub_preempt_count_notrace(PREEMPT_ACTIVE);
barrier();
} while (need_resched());
}
asmlinkage void __sched preempt_schedule_irq(void)
{
struct thread_info *ti = current_thread_info();
BUG_ON(ti->preempt_count || !irqs_disabled());
do {
add_preempt_count(PREEMPT_ACTIVE);
local_irq_enable();
__schedule();
local_irq_disable();
sub_preempt_count(PREEMPT_ACTIVE);
barrier();
} while (need_resched());
}
int default_wake_function(wait_queue_t *curr, unsigned mode, int wake_flags,
void *key)
{
return try_to_wake_up(curr->private, mode, wake_flags);
}
static void __wake_up_common(wait_queue_head_t *q, unsigned int mode,
int nr_exclusive, int wake_flags, void *key)
{
wait_queue_t *curr, *next;
list_for_each_entry_safe(curr, next, &q->task_list, task_list) {
unsigned flags = curr->flags;
if (curr->func(curr, mode, wake_flags, key) &&
(flags & WQ_FLAG_EXCLUSIVE) && !--nr_exclusive)
break;
}
}
void __wake_up(wait_queue_head_t *q, unsigned int mode,
int nr_exclusive, void *key)
{
unsigned long flags;
spin_lock_irqsave(&q->lock, flags);
__wake_up_common(q, mode, nr_exclusive, 0, key);
spin_unlock_irqrestore(&q->lock, flags);
}
void __wake_up_locked(wait_queue_head_t *q, unsigned int mode)
{
__wake_up_common(q, mode, 1, 0, NULL);
}
void __wake_up_locked_key(wait_queue_head_t *q, unsigned int mode, void *key)
{
__wake_up_common(q, mode, 1, 0, key);
}
void __wake_up_sync_key(wait_queue_head_t *q, unsigned int mode,
int nr_exclusive, void *key)
{
unsigned long flags;
int wake_flags = WF_SYNC;
if (unlikely(!q))
return;
if (unlikely(!nr_exclusive))
wake_flags = 0;
spin_lock_irqsave(&q->lock, flags);
__wake_up_common(q, mode, nr_exclusive, wake_flags, key);
spin_unlock_irqrestore(&q->lock, flags);
}
void __wake_up_sync(wait_queue_head_t *q, unsigned int mode, int nr_exclusive)
{
__wake_up_sync_key(q, mode, nr_exclusive, NULL);
}
void complete(struct completion *x)
{
unsigned long flags;
spin_lock_irqsave(&x->wait.lock, flags);
x->done++;
__wake_up_common(&x->wait, TASK_NORMAL, 1, 0, NULL);
spin_unlock_irqrestore(&x->wait.lock, flags);
}
void complete_all(struct completion *x)
{
unsigned long flags;
spin_lock_irqsave(&x->wait.lock, flags);
x->done += UINT_MAX/2;
__wake_up_common(&x->wait, TASK_NORMAL, 0, 0, NULL);
spin_unlock_irqrestore(&x->wait.lock, flags);
}
static inline long __sched
do_wait_for_common(struct completion *x, long timeout, int state)
{
if (!x->done) {
DECLARE_WAITQUEUE(wait, current);
__add_wait_queue_tail_exclusive(&x->wait, &wait);
do {
if (signal_pending_state(state, current)) {
timeout = -ERESTARTSYS;
break;
}
__set_current_state(state);
spin_unlock_irq(&x->wait.lock);
timeout = schedule_timeout(timeout);
spin_lock_irq(&x->wait.lock);
} while (!x->done && timeout);
__remove_wait_queue(&x->wait, &wait);
if (!x->done)
return timeout;
}
x->done--;
return timeout ?: 1;
}
static long __sched
wait_for_common(struct completion *x, long timeout, int state)
{
might_sleep();
spin_lock_irq(&x->wait.lock);
timeout = do_wait_for_common(x, timeout, state);
spin_unlock_irq(&x->wait.lock);
return timeout;
}
void __sched wait_for_completion(struct completion *x)
{
wait_for_common(x, MAX_SCHEDULE_TIMEOUT, TASK_UNINTERRUPTIBLE);
}
unsigned long __sched
wait_for_completion_timeout(struct completion *x, unsigned long timeout)
{
return wait_for_common(x, timeout, TASK_UNINTERRUPTIBLE);
}
int __sched wait_for_completion_interruptible(struct completion *x)
{
long t = wait_for_common(x, MAX_SCHEDULE_TIMEOUT, TASK_INTERRUPTIBLE);
if (t == -ERESTARTSYS)
return t;
return 0;
}
long __sched
wait_for_completion_interruptible_timeout(struct completion *x,
unsigned long timeout)
{
return wait_for_common(x, timeout, TASK_INTERRUPTIBLE);
}
int __sched wait_for_completion_killable(struct completion *x)
{
long t = wait_for_common(x, MAX_SCHEDULE_TIMEOUT, TASK_KILLABLE);
if (t == -ERESTARTSYS)
return t;
return 0;
}
long __sched
wait_for_completion_killable_timeout(struct completion *x,
unsigned long timeout)
{
return wait_for_common(x, timeout, TASK_KILLABLE);
}
bool try_wait_for_completion(struct completion *x)
{
unsigned long flags;
int ret = 1;
spin_lock_irqsave(&x->wait.lock, flags);
if (!x->done)
ret = 0;
else
x->done--;
spin_unlock_irqrestore(&x->wait.lock, flags);
return ret;
}
bool completion_done(struct completion *x)
{
unsigned long flags;
int ret = 1;
spin_lock_irqsave(&x->wait.lock, flags);
if (!x->done)
ret = 0;
spin_unlock_irqrestore(&x->wait.lock, flags);
return ret;
}
static long __sched
sleep_on_common(wait_queue_head_t *q, int state, long timeout)
{
unsigned long flags;
wait_queue_t wait;
init_waitqueue_entry(&wait, current);
__set_current_state(state);
spin_lock_irqsave(&q->lock, flags);
__add_wait_queue(q, &wait);
spin_unlock(&q->lock);
timeout = schedule_timeout(timeout);
spin_lock_irq(&q->lock);
__remove_wait_queue(q, &wait);
spin_unlock_irqrestore(&q->lock, flags);
return timeout;
}
void __sched interruptible_sleep_on(wait_queue_head_t *q)
{
sleep_on_common(q, TASK_INTERRUPTIBLE, MAX_SCHEDULE_TIMEOUT);
}
long __sched
interruptible_sleep_on_timeout(wait_queue_head_t *q, long timeout)
{
return sleep_on_common(q, TASK_INTERRUPTIBLE, timeout);
}
void __sched sleep_on(wait_queue_head_t *q)
{
sleep_on_common(q, TASK_UNINTERRUPTIBLE, MAX_SCHEDULE_TIMEOUT);
}
long __sched sleep_on_timeout(wait_queue_head_t *q, long timeout)
{
return sleep_on_common(q, TASK_UNINTERRUPTIBLE, timeout);
}
void rt_mutex_setprio(struct task_struct *p, int prio)
{
int oldprio, on_rq, running;
struct rq *rq;
const struct sched_class *prev_class;
BUG_ON(prio < 0 || prio > MAX_PRIO);
rq = __task_rq_lock(p);
trace_sched_pi_setprio(p, prio);
oldprio = p->prio;
prev_class = p->sched_class;
on_rq = p->on_rq;
running = task_current(rq, p);
if (on_rq)
dequeue_task(rq, p, 0);
if (running)
p->sched_class->put_prev_task(rq, p);
if (rt_prio(prio))
p->sched_class = &rt_sched_class;
else
p->sched_class = &fair_sched_class;
p->prio = prio;
if (running)
p->sched_class->set_curr_task(rq);
if (on_rq)
enqueue_task(rq, p, oldprio < prio ? ENQUEUE_HEAD : 0);
check_class_changed(rq, p, prev_class, oldprio);
__task_rq_unlock(rq);
}
void set_user_nice(struct task_struct *p, long nice)
{
int old_prio, delta, on_rq;
unsigned long flags;
struct rq *rq;
if (TASK_NICE(p) == nice || nice < -20 || nice > 19)
return;
rq = task_rq_lock(p, &flags);
if (task_has_rt_policy(p)) {
p->static_prio = NICE_TO_PRIO(nice);
goto out_unlock;
}
on_rq = p->on_rq;
if (on_rq)
dequeue_task(rq, p, 0);
p->static_prio = NICE_TO_PRIO(nice);
set_load_weight(p);
old_prio = p->prio;
p->prio = effective_prio(p);
delta = p->prio - old_prio;
if (on_rq) {
enqueue_task(rq, p, 0);
if (delta < 0 || (delta > 0 && task_running(rq, p)))
resched_task(rq->curr);
}
out_unlock:
task_rq_unlock(rq, p, &flags);
}
int can_nice(const struct task_struct *p, const int nice)
{
int nice_rlim = 20 - nice;
return (nice_rlim <= task_rlimit(p, RLIMIT_NICE) ||
capable(CAP_SYS_NICE));
}
int task_prio(const struct task_struct *p)
{
return p->prio - MAX_RT_PRIO;
}
int task_nice(const struct task_struct *p)
{
return TASK_NICE(p);
}
int idle_cpu(int cpu)
{
return cpu_curr(cpu) == cpu_rq(cpu)->idle;
}
struct task_struct *idle_task(int cpu)
{
return cpu_rq(cpu)->idle;
}
static struct task_struct *find_process_by_pid(pid_t pid)
{
return pid ? find_task_by_vpid(pid) : current;
}
static void
__setscheduler(struct rq *rq, struct task_struct *p, int policy, int prio)
{
p->policy = policy;
p->rt_priority = prio;
p->normal_prio = normal_prio(p);
p->prio = rt_mutex_getprio(p);
if (rt_prio(p->prio))
p->sched_class = &rt_sched_class;
else
p->sched_class = &fair_sched_class;
set_load_weight(p);
}
static bool check_same_owner(struct task_struct *p)
{
const struct cred *cred = current_cred(), *pcred;
bool match;
rcu_read_lock();
pcred = __task_cred(p);
if (cred->user->user_ns == pcred->user->user_ns)
match = (cred->euid == pcred->euid ||
cred->euid == pcred->uid);
else
match = false;
rcu_read_unlock();
return match;
}
static int __sched_setscheduler(struct task_struct *p, int policy,
const struct sched_param *param, bool user)
{
int retval, oldprio, oldpolicy = -1, on_rq, running;
unsigned long flags;
const struct sched_class *prev_class;
struct rq *rq;
int reset_on_fork;
BUG_ON(in_interrupt());
recheck:
if (policy < 0) {
reset_on_fork = p->sched_reset_on_fork;
policy = oldpolicy = p->policy;
} else {
reset_on_fork = !!(policy & SCHED_RESET_ON_FORK);
policy &= ~SCHED_RESET_ON_FORK;
if (policy != SCHED_FIFO && policy != SCHED_RR &&
policy != SCHED_NORMAL && policy != SCHED_BATCH &&
policy != SCHED_IDLE)
return -EINVAL;
}
if (param->sched_priority < 0 ||
(p->mm && param->sched_priority > MAX_USER_RT_PRIO-1) ||
(!p->mm && param->sched_priority > MAX_RT_PRIO-1))
return -EINVAL;
if (rt_policy(policy) != (param->sched_priority != 0))
return -EINVAL;
if (user && !capable(CAP_SYS_NICE)) {
if (rt_policy(policy)) {
unsigned long rlim_rtprio =
task_rlimit(p, RLIMIT_RTPRIO);
if (policy != p->policy && !rlim_rtprio)
return -EPERM;
if (param->sched_priority > p->rt_priority &&
param->sched_priority > rlim_rtprio)
return -EPERM;
}
if (p->policy == SCHED_IDLE && policy != SCHED_IDLE) {
if (!can_nice(p, TASK_NICE(p)))
return -EPERM;
}
if (!check_same_owner(p))
return -EPERM;
if (p->sched_reset_on_fork && !reset_on_fork)
return -EPERM;
}
if (user) {
retval = security_task_setscheduler(p);
if (retval)
return retval;
}
rq = task_rq_lock(p, &flags);
if (p == rq->stop) {
task_rq_unlock(rq, p, &flags);
return -EINVAL;
}
if (unlikely(policy == p->policy && (!rt_policy(policy) ||
param->sched_priority == p->rt_priority))) {
__task_rq_unlock(rq);
raw_spin_unlock_irqrestore(&p->pi_lock, flags);
return 0;
}
#ifdef CONFIG_RT_GROUP_SCHED
if (user) {
if (rt_bandwidth_enabled() && rt_policy(policy) &&
task_group(p)->rt_bandwidth.rt_runtime == 0 &&
!task_group_is_autogroup(task_group(p))) {
task_rq_unlock(rq, p, &flags);
return -EPERM;
}
}
#endif
if (unlikely(oldpolicy != -1 && oldpolicy != p->policy)) {
policy = oldpolicy = -1;
task_rq_unlock(rq, p, &flags);
goto recheck;
}
on_rq = p->on_rq;
running = task_current(rq, p);
if (on_rq)
deactivate_task(rq, p, 0);
if (running)
p->sched_class->put_prev_task(rq, p);
p->sched_reset_on_fork = reset_on_fork;
oldprio = p->prio;
prev_class = p->sched_class;
__setscheduler(rq, p, policy, param->sched_priority);
if (running)
p->sched_class->set_curr_task(rq);
if (on_rq)
activate_task(rq, p, 0);
check_class_changed(rq, p, prev_class, oldprio);
task_rq_unlock(rq, p, &flags);
rt_mutex_adjust_pi(p);
return 0;
}
int sched_setscheduler(struct task_struct *p, int policy,
const struct sched_param *param)
{
return __sched_setscheduler(p, policy, param, true);
}
int sched_setscheduler_nocheck(struct task_struct *p, int policy,
const struct sched_param *param)
{
return __sched_setscheduler(p, policy, param, false);
}
static int
do_sched_setscheduler(pid_t pid, int policy, struct sched_param __user *param)
{
struct sched_param lparam;
struct task_struct *p;
int retval;
if (!param || pid < 0)
return -EINVAL;
if (copy_from_user(&lparam, param, sizeof(struct sched_param)))
return -EFAULT;
rcu_read_lock();
retval = -ESRCH;
p = find_process_by_pid(pid);
if (p != NULL)
retval = sched_setscheduler(p, policy, &lparam);
rcu_read_unlock();
return retval;
}
long sched_setaffinity(pid_t pid, const struct cpumask *in_mask)
{
cpumask_var_t cpus_allowed, new_mask;
struct task_struct *p;
int retval;
get_online_cpus();
rcu_read_lock();
p = find_process_by_pid(pid);
if (!p) {
rcu_read_unlock();
put_online_cpus();
return -ESRCH;
}
get_task_struct(p);
rcu_read_unlock();
if (!alloc_cpumask_var(&cpus_allowed, GFP_KERNEL)) {
retval = -ENOMEM;
goto out_put_task;
}
if (!alloc_cpumask_var(&new_mask, GFP_KERNEL)) {
retval = -ENOMEM;
goto out_free_cpus_allowed;
}
retval = -EPERM;
if (!check_same_owner(p) && !task_ns_capable(p, CAP_SYS_NICE))
goto out_unlock;
retval = security_task_setscheduler(p);
if (retval)
goto out_unlock;
cpuset_cpus_allowed(p, cpus_allowed);
cpumask_and(new_mask, in_mask, cpus_allowed);
again:
retval = set_cpus_allowed_ptr(p, new_mask);
if (!retval) {
cpuset_cpus_allowed(p, cpus_allowed);
if (!cpumask_subset(new_mask, cpus_allowed)) {
cpumask_copy(new_mask, cpus_allowed);
goto again;
}
}
out_unlock:
free_cpumask_var(new_mask);
out_free_cpus_allowed:
free_cpumask_var(cpus_allowed);
out_put_task:
put_task_struct(p);
put_online_cpus();
return retval;
}
static int get_user_cpu_mask(unsigned long __user *user_mask_ptr, unsigned len,
struct cpumask *new_mask)
{
if (len < cpumask_size())
cpumask_clear(new_mask);
else if (len > cpumask_size())
len = cpumask_size();
return copy_from_user(new_mask, user_mask_ptr, len) ? -EFAULT : 0;
}
long sched_getaffinity(pid_t pid, struct cpumask *mask)
{
struct task_struct *p;
unsigned long flags;
int retval;
get_online_cpus();
rcu_read_lock();
retval = -ESRCH;
p = find_process_by_pid(pid);
if (!p)
goto out_unlock;
retval = security_task_getscheduler(p);
if (retval)
goto out_unlock;
raw_spin_lock_irqsave(&p->pi_lock, flags);
cpumask_and(mask, &p->cpus_allowed, cpu_online_mask);
raw_spin_unlock_irqrestore(&p->pi_lock, flags);
out_unlock:
rcu_read_unlock();
put_online_cpus();
return retval;
}
static inline int should_resched(void)
{
return need_resched() && !(preempt_count() & PREEMPT_ACTIVE);
}
static void __cond_resched(void)
{
add_preempt_count(PREEMPT_ACTIVE);
__schedule();
sub_preempt_count(PREEMPT_ACTIVE);
}
int __sched _cond_resched(void)
{
if (should_resched()) {
__cond_resched();
return 1;
}
return 0;
}
int __cond_resched_lock(spinlock_t *lock)
{
int resched = should_resched();
int ret = 0;
lockdep_assert_held(lock);
if (spin_needbreak(lock) || resched) {
spin_unlock(lock);
if (resched)
__cond_resched();
else
cpu_relax();
ret = 1;
spin_lock(lock);
}
return ret;
}
int __sched __cond_resched_softirq(void)
{
BUG_ON(!in_softirq());
if (should_resched()) {
local_bh_enable();
__cond_resched();
local_bh_disable();
return 1;
}
return 0;
}
void __sched yield(void)
{
set_current_state(TASK_RUNNING);
sys_sched_yield();
}
bool __sched yield_to(struct task_struct *p, bool preempt)
{
struct task_struct *curr = current;
struct rq *rq, *p_rq;
unsigned long flags;
bool yielded = 0;
local_irq_save(flags);
rq = this_rq();
again:
p_rq = task_rq(p);
double_rq_lock(rq, p_rq);
while (task_rq(p) != p_rq) {
double_rq_unlock(rq, p_rq);
goto again;
}
if (!curr->sched_class->yield_to_task)
goto out;
if (curr->sched_class != p->sched_class)
goto out;
if (task_running(p_rq, p) || p->state)
goto out;
yielded = curr->sched_class->yield_to_task(rq, p, preempt);
if (yielded) {
schedstat_inc(rq, yld_count);
if (preempt && rq != p_rq)
resched_task(p_rq->curr);
}
out:
double_rq_unlock(rq, p_rq);
local_irq_restore(flags);
if (yielded)
schedule();
return yielded;
}
void __sched io_schedule(void)
{
struct rq *rq = raw_rq();
delayacct_blkio_start();
atomic_inc(&rq->nr_iowait);
blk_flush_plug(current);
current->in_iowait = 1;
schedule();
current->in_iowait = 0;
atomic_dec(&rq->nr_iowait);
delayacct_blkio_end();
}
long __sched io_schedule_timeout(long timeout)
{
struct rq *rq = raw_rq();
long ret;
delayacct_blkio_start();
atomic_inc(&rq->nr_iowait);
blk_flush_plug(current);
current->in_iowait = 1;
ret = schedule_timeout(timeout);
current->in_iowait = 0;
atomic_dec(&rq->nr_iowait);
delayacct_blkio_end();
return ret;
}
void sched_show_task(struct task_struct *p)
{
unsigned long free = 0;
unsigned state;
state = p->state ? __ffs(p->state) + 1 : 0;
printk(KERN_INFO "%-15.15s %c", p->comm,
state < sizeof(stat_nam) - 1 ? stat_nam[state] : '?');
#if BITS_PER_LONG == 32
if (state == TASK_RUNNING)
printk(KERN_CONT " running ");
else
printk(KERN_CONT " %08lx ", thread_saved_pc(p));
#else
if (state == TASK_RUNNING)
printk(KERN_CONT " running task ");
else
printk(KERN_CONT " %016lx ", thread_saved_pc(p));
#endif
#ifdef CONFIG_DEBUG_STACK_USAGE
free = stack_not_used(p);
#endif
printk(KERN_CONT "%5lu %5d %6d 0x%08lx\n", free,
task_pid_nr(p), task_pid_nr(p->real_parent),
(unsigned long)task_thread_info(p)->flags);
show_stack(p, NULL);
}
void show_state_filter(unsigned long state_filter)
{
struct task_struct *g, *p;
#if BITS_PER_LONG == 32
printk(KERN_INFO
" task PC stack pid father\n");
#else
printk(KERN_INFO
" task PC stack pid father\n");
#endif
read_lock(&tasklist_lock);
do_each_thread(g, p) {
touch_nmi_watchdog();
if (!state_filter || (p->state & state_filter))
sched_show_task(p);
} while_each_thread(g, p);
touch_all_softlockup_watchdogs();
#ifdef CONFIG_SCHED_DEBUG
sysrq_sched_debug_show();
#endif
read_unlock(&tasklist_lock);
if (!state_filter)
debug_show_all_locks();
}
void __cpuinit init_idle_bootup_task(struct task_struct *idle)
{
idle->sched_class = &idle_sched_class;
}
void __cpuinit init_idle(struct task_struct *idle, int cpu)
{
struct rq *rq = cpu_rq(cpu);
unsigned long flags;
raw_spin_lock_irqsave(&rq->lock, flags);
__sched_fork(idle);
idle->state = TASK_RUNNING;
idle->se.exec_start = sched_clock();
do_set_cpus_allowed(idle, cpumask_of(cpu));
rcu_read_lock();
__set_task_cpu(idle, cpu);
rcu_read_unlock();
rq->curr = rq->idle = idle;
#if defined(CONFIG_SMP)
idle->on_cpu = 1;
#endif
raw_spin_unlock_irqrestore(&rq->lock, flags);
task_thread_info(idle)->preempt_count = 0;
idle->sched_class = &idle_sched_class;
ftrace_graph_init_idle_task(idle, cpu);
}
static int get_update_sysctl_factor(void)
{
unsigned int cpus = min_t(int, num_online_cpus(), 8);
unsigned int factor;
switch (sysctl_sched_tunable_scaling) {
case SCHED_TUNABLESCALING_NONE:
factor = 1;
break;
case SCHED_TUNABLESCALING_LINEAR:
factor = cpus;
break;
case SCHED_TUNABLESCALING_LOG:
default:
factor = 1 + ilog2(cpus);
break;
}
return factor;
}
static void update_sysctl(void)
{
unsigned int factor = get_update_sysctl_factor();
#define SET_SYSCTL(name) \
(sysctl_##name = (factor) * normalized_sysctl_##name)
SET_SYSCTL(sched_min_granularity);
SET_SYSCTL(sched_latency);
SET_SYSCTL(sched_wakeup_granularity);
#undef SET_SYSCTL
}
static inline void sched_init_granularity(void)
{
update_sysctl();
}
void do_set_cpus_allowed(struct task_struct *p, const struct cpumask *new_mask)
{
if (p->sched_class && p->sched_class->set_cpus_allowed)
p->sched_class->set_cpus_allowed(p, new_mask);
else {
cpumask_copy(&p->cpus_allowed, new_mask);
p->rt.nr_cpus_allowed = cpumask_weight(new_mask);
}
}
int set_cpus_allowed_ptr(struct task_struct *p, const struct cpumask *new_mask)
{
unsigned long flags;
struct rq *rq;
unsigned int dest_cpu;
int ret = 0;
rq = task_rq_lock(p, &flags);
if (cpumask_equal(&p->cpus_allowed, new_mask))
goto out;
if (!cpumask_intersects(new_mask, cpu_active_mask)) {
ret = -EINVAL;
goto out;
}
if (unlikely((p->flags & PF_THREAD_BOUND) && p != current)) {
ret = -EINVAL;
goto out;
}
do_set_cpus_allowed(p, new_mask);
if (cpumask_test_cpu(task_cpu(p), new_mask))
goto out;
dest_cpu = cpumask_any_and(cpu_active_mask, new_mask);
if (p->on_rq) {
struct migration_arg arg = { p, dest_cpu };
task_rq_unlock(rq, p, &flags);
stop_one_cpu(cpu_of(rq), migration_cpu_stop, &arg);
tlb_migrate_finish(p->mm);
return 0;
}
out:
task_rq_unlock(rq, p, &flags);
return ret;
}
static int __migrate_task(struct task_struct *p, int src_cpu, int dest_cpu)
{
struct rq *rq_dest, *rq_src;
int ret = 0;
if (unlikely(!cpu_active(dest_cpu)))
return ret;
rq_src = cpu_rq(src_cpu);
rq_dest = cpu_rq(dest_cpu);
raw_spin_lock(&p->pi_lock);
double_rq_lock(rq_src, rq_dest);
if (task_cpu(p) != src_cpu)
goto done;
if (!cpumask_test_cpu(dest_cpu, &p->cpus_allowed))
goto fail;
if (p->on_rq) {
deactivate_task(rq_src, p, 0);
set_task_cpu(p, dest_cpu);
activate_task(rq_dest, p, 0);
check_preempt_curr(rq_dest, p, 0);
}
done:
ret = 1;
fail:
double_rq_unlock(rq_src, rq_dest);
raw_spin_unlock(&p->pi_lock);
return ret;
}
static int migration_cpu_stop(void *data)
{
struct migration_arg *arg = data;
local_irq_disable();
__migrate_task(arg->task, raw_smp_processor_id(), arg->dest_cpu);
local_irq_enable();
return 0;
}
void idle_task_exit(void)
{
struct mm_struct *mm = current->active_mm;
BUG_ON(cpu_online(smp_processor_id()));
if (mm != &init_mm)
switch_mm(mm, &init_mm, current);
mmdrop(mm);
}
static void migrate_nr_uninterruptible(struct rq *rq_src)
{
struct rq *rq_dest = cpu_rq(cpumask_any(cpu_active_mask));
rq_dest->nr_uninterruptible += rq_src->nr_uninterruptible;
rq_src->nr_uninterruptible = 0;
}
static void calc_global_load_remove(struct rq *rq)
{
atomic_long_sub(rq->calc_load_active, &calc_load_tasks);
rq->calc_load_active = 0;
}
static void migrate_tasks(unsigned int dead_cpu)
{
struct rq *rq = cpu_rq(dead_cpu);
struct task_struct *next, *stop = rq->stop;
int dest_cpu;
rq->stop = NULL;
for ( ; ; ) {
if (rq->nr_running == 1)
break;
next = pick_next_task(rq);
BUG_ON(!next);
next->sched_class->put_prev_task(rq, next);
dest_cpu = select_fallback_rq(dead_cpu, next);
raw_spin_unlock(&rq->lock);
__migrate_task(next, dead_cpu, dest_cpu);
raw_spin_lock(&rq->lock);
}
rq->stop = stop;
}
static struct ctl_table *sd_alloc_ctl_entry(int n)
{
struct ctl_table *entry =
kcalloc(n, sizeof(struct ctl_table), GFP_KERNEL);
return entry;
}
static void sd_free_ctl_entry(struct ctl_table **tablep)
{
struct ctl_table *entry;
for (entry = *tablep; entry->mode; entry++) {
if (entry->child)
sd_free_ctl_entry(&entry->child);
if (entry->proc_handler == NULL)
kfree(entry->procname);
}
kfree(*tablep);
*tablep = NULL;
}
static void
set_table_entry(struct ctl_table *entry,
const char *procname, void *data, int maxlen,
mode_t mode, proc_handler *proc_handler)
{
entry->procname = procname;
entry->data = data;
entry->maxlen = maxlen;
entry->mode = mode;
entry->proc_handler = proc_handler;
}
static struct ctl_table *
sd_alloc_ctl_domain_table(struct sched_domain *sd)
{
struct ctl_table *table = sd_alloc_ctl_entry(13);
if (table == NULL)
return NULL;
set_table_entry(&table[0], "min_interval", &sd->min_interval,
sizeof(long), 0644, proc_doulongvec_minmax);
set_table_entry(&table[1], "max_interval", &sd->max_interval,
sizeof(long), 0644, proc_doulongvec_minmax);
set_table_entry(&table[2], "busy_idx", &sd->busy_idx,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[3], "idle_idx", &sd->idle_idx,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[4], "newidle_idx", &sd->newidle_idx,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[5], "wake_idx", &sd->wake_idx,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[6], "forkexec_idx", &sd->forkexec_idx,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[7], "busy_factor", &sd->busy_factor,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[8], "imbalance_pct", &sd->imbalance_pct,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[9], "cache_nice_tries",
&sd->cache_nice_tries,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[10], "flags", &sd->flags,
sizeof(int), 0644, proc_dointvec_minmax);
set_table_entry(&table[11], "name", sd->name,
CORENAME_MAX_SIZE, 0444, proc_dostring);
return table;
}
static ctl_table *sd_alloc_ctl_cpu_table(int cpu)
{
struct ctl_table *entry, *table;
struct sched_domain *sd;
int domain_num = 0, i;
char buf[32];
for_each_domain(cpu, sd)
domain_num++;
entry = table = sd_alloc_ctl_entry(domain_num + 1);
if (table == NULL)
return NULL;
i = 0;
for_each_domain(cpu, sd) {
snprintf(buf, 32, "domain%d", i);
entry->procname = kstrdup(buf, GFP_KERNEL);
entry->mode = 0555;
entry->child = sd_alloc_ctl_domain_table(sd);
entry++;
i++;
}
return table;
}
static void register_sched_domain_sysctl(void)
{
int i, cpu_num = num_possible_cpus();
struct ctl_table *entry = sd_alloc_ctl_entry(cpu_num + 1);
char buf[32];
WARN_ON(sd_ctl_dir[0].child);
sd_ctl_dir[0].child = entry;
if (entry == NULL)
return;
for_each_possible_cpu(i) {
snprintf(buf, 32, "cpu%d", i);
entry->procname = kstrdup(buf, GFP_KERNEL);
entry->mode = 0555;
entry->child = sd_alloc_ctl_cpu_table(i);
entry++;
}
WARN_ON(sd_sysctl_header);
sd_sysctl_header = register_sysctl_table(sd_ctl_root);
}
static void unregister_sched_domain_sysctl(void)
{
if (sd_sysctl_header)
unregister_sysctl_table(sd_sysctl_header);
sd_sysctl_header = NULL;
if (sd_ctl_dir[0].child)
sd_free_ctl_entry(&sd_ctl_dir[0].child);
}
static void register_sched_domain_sysctl(void)
{
}
static void unregister_sched_domain_sysctl(void)
{
}
static void set_rq_online(struct rq *rq)
{
if (!rq->online) {
const struct sched_class *class;
cpumask_set_cpu(rq->cpu, rq->rd->online);
rq->online = 1;
for_each_class(class) {
if (class->rq_online)
class->rq_online(rq);
}
}
}
static void set_rq_offline(struct rq *rq)
{
if (rq->online) {
const struct sched_class *class;
for_each_class(class) {
if (class->rq_offline)
class->rq_offline(rq);
}
cpumask_clear_cpu(rq->cpu, rq->rd->online);
rq->online = 0;
}
}
static int __cpuinit
migration_call(struct notifier_block *nfb, unsigned long action, void *hcpu)
{
int cpu = (long)hcpu;
unsigned long flags;
struct rq *rq = cpu_rq(cpu);
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
rq->calc_load_update = calc_load_update;
break;
case CPU_ONLINE:
raw_spin_lock_irqsave(&rq->lock, flags);
if (rq->rd) {
BUG_ON(!cpumask_test_cpu(cpu, rq->rd->span));
set_rq_online(rq);
}
raw_spin_unlock_irqrestore(&rq->lock, flags);
break;
#ifdef CONFIG_HOTPLUG_CPU
case CPU_DYING:
sched_ttwu_pending();
raw_spin_lock_irqsave(&rq->lock, flags);
if (rq->rd) {
BUG_ON(!cpumask_test_cpu(cpu, rq->rd->span));
set_rq_offline(rq);
}
migrate_tasks(cpu);
BUG_ON(rq->nr_running != 1);
raw_spin_unlock_irqrestore(&rq->lock, flags);
migrate_nr_uninterruptible(rq);
calc_global_load_remove(rq);
break;
#endif
}
update_max_interval();
return NOTIFY_OK;
}
static int __cpuinit sched_cpu_active(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_ONLINE:
case CPU_DOWN_FAILED:
set_cpu_active((long)hcpu, true);
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static int __cpuinit sched_cpu_inactive(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
set_cpu_active((long)hcpu, false);
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static int __init migration_init(void)
{
void *cpu = (void *)(long)smp_processor_id();
int err;
err = migration_call(&migration_notifier, CPU_UP_PREPARE, cpu);
BUG_ON(err == NOTIFY_BAD);
migration_call(&migration_notifier, CPU_ONLINE, cpu);
register_cpu_notifier(&migration_notifier);
cpu_notifier(sched_cpu_active, CPU_PRI_SCHED_ACTIVE);
cpu_notifier(sched_cpu_inactive, CPU_PRI_SCHED_INACTIVE);
return 0;
}
static int __init sched_domain_debug_setup(char *str)
{
sched_domain_debug_enabled = 1;
return 0;
}
static int sched_domain_debug_one(struct sched_domain *sd, int cpu, int level,
struct cpumask *groupmask)
{
struct sched_group *group = sd->groups;
char str[256];
cpulist_scnprintf(str, sizeof(str), sched_domain_span(sd));
cpumask_clear(groupmask);
printk(KERN_DEBUG "%*s domain %d: ", level, "", level);
if (!(sd->flags & SD_LOAD_BALANCE)) {
printk("does not load-balance\n");
if (sd->parent)
printk(KERN_ERR "ERROR: !SD_LOAD_BALANCE domain"
" has parent");
return -1;
}
printk(KERN_CONT "span %s level %s\n", str, sd->name);
if (!cpumask_test_cpu(cpu, sched_domain_span(sd))) {
printk(KERN_ERR "ERROR: domain->span does not contain "
"CPU%d\n", cpu);
}
if (!cpumask_test_cpu(cpu, sched_group_cpus(group))) {
printk(KERN_ERR "ERROR: domain->groups does not contain"
" CPU%d\n", cpu);
}
printk(KERN_DEBUG "%*s groups:", level + 1, "");
do {
if (!group) {
printk("\n");
printk(KERN_ERR "ERROR: group is NULL\n");
break;
}
if (!group->sgp->power) {
printk(KERN_CONT "\n");
printk(KERN_ERR "ERROR: domain->cpu_power not "
"set\n");
break;
}
if (!cpumask_weight(sched_group_cpus(group))) {
printk(KERN_CONT "\n");
printk(KERN_ERR "ERROR: empty group\n");
break;
}
if (cpumask_intersects(groupmask, sched_group_cpus(group))) {
printk(KERN_CONT "\n");
printk(KERN_ERR "ERROR: repeated CPUs\n");
break;
}
cpumask_or(groupmask, groupmask, sched_group_cpus(group));
cpulist_scnprintf(str, sizeof(str), sched_group_cpus(group));
printk(KERN_CONT " %s", str);
if (group->sgp->power != SCHED_POWER_SCALE) {
printk(KERN_CONT " (cpu_power = %d)",
group->sgp->power);
}
group = group->next;
} while (group != sd->groups);
printk(KERN_CONT "\n");
if (!cpumask_equal(sched_domain_span(sd), groupmask))
printk(KERN_ERR "ERROR: groups don't span domain->span\n");
if (sd->parent &&
!cpumask_subset(groupmask, sched_domain_span(sd->parent)))
printk(KERN_ERR "ERROR: parent span is not a superset "
"of domain->span\n");
return 0;
}
static void sched_domain_debug(struct sched_domain *sd, int cpu)
{
int level = 0;
if (!sched_domain_debug_enabled)
return;
if (!sd) {
printk(KERN_DEBUG "CPU%d attaching NULL sched-domain.\n", cpu);
return;
}
printk(KERN_DEBUG "CPU%d attaching sched-domain:\n", cpu);
for (;;) {
if (sched_domain_debug_one(sd, cpu, level, sched_domains_tmpmask))
break;
level++;
sd = sd->parent;
if (!sd)
break;
}
}
static int sd_degenerate(struct sched_domain *sd)
{
if (cpumask_weight(sched_domain_span(sd)) == 1)
return 1;
if (sd->flags & (SD_LOAD_BALANCE |
SD_BALANCE_NEWIDLE |
SD_BALANCE_FORK |
SD_BALANCE_EXEC |
SD_SHARE_CPUPOWER |
SD_SHARE_PKG_RESOURCES)) {
if (sd->groups != sd->groups->next)
return 0;
}
if (sd->flags & (SD_WAKE_AFFINE))
return 0;
return 1;
}
static int
sd_parent_degenerate(struct sched_domain *sd, struct sched_domain *parent)
{
unsigned long cflags = sd->flags, pflags = parent->flags;
if (sd_degenerate(parent))
return 1;
if (!cpumask_equal(sched_domain_span(sd), sched_domain_span(parent)))
return 0;
if (parent->groups == parent->groups->next) {
pflags &= ~(SD_LOAD_BALANCE |
SD_BALANCE_NEWIDLE |
SD_BALANCE_FORK |
SD_BALANCE_EXEC |
SD_SHARE_CPUPOWER |
SD_SHARE_PKG_RESOURCES);
if (nr_node_ids == 1)
pflags &= ~SD_SERIALIZE;
}
if (~cflags & pflags)
return 0;
return 1;
}
static void free_rootdomain(struct rcu_head *rcu)
{
struct root_domain *rd = container_of(rcu, struct root_domain, rcu);
cpupri_cleanup(&rd->cpupri);
free_cpumask_var(rd->rto_mask);
free_cpumask_var(rd->online);
free_cpumask_var(rd->span);
kfree(rd);
}
static void rq_attach_root(struct rq *rq, struct root_domain *rd)
{
struct root_domain *old_rd = NULL;
unsigned long flags;
raw_spin_lock_irqsave(&rq->lock, flags);
if (rq->rd) {
old_rd = rq->rd;
if (cpumask_test_cpu(rq->cpu, old_rd->online))
set_rq_offline(rq);
cpumask_clear_cpu(rq->cpu, old_rd->span);
if (!atomic_dec_and_test(&old_rd->refcount))
old_rd = NULL;
}
atomic_inc(&rd->refcount);
rq->rd = rd;
cpumask_set_cpu(rq->cpu, rd->span);
if (cpumask_test_cpu(rq->cpu, cpu_active_mask))
set_rq_online(rq);
raw_spin_unlock_irqrestore(&rq->lock, flags);
if (old_rd)
call_rcu_sched(&old_rd->rcu, free_rootdomain);
}
static int init_rootdomain(struct root_domain *rd)
{
memset(rd, 0, sizeof(*rd));
if (!alloc_cpumask_var(&rd->span, GFP_KERNEL))
goto out;
if (!alloc_cpumask_var(&rd->online, GFP_KERNEL))
goto free_span;
if (!alloc_cpumask_var(&rd->rto_mask, GFP_KERNEL))
goto free_online;
if (cpupri_init(&rd->cpupri) != 0)
goto free_rto_mask;
return 0;
free_rto_mask:
free_cpumask_var(rd->rto_mask);
free_online:
free_cpumask_var(rd->online);
free_span:
free_cpumask_var(rd->span);
out:
return -ENOMEM;
}
static void init_defrootdomain(void)
{
init_rootdomain(&def_root_domain);
atomic_set(&def_root_domain.refcount, 1);
}
static struct root_domain *alloc_rootdomain(void)
{
struct root_domain *rd;
rd = kmalloc(sizeof(*rd), GFP_KERNEL);
if (!rd)
return NULL;
if (init_rootdomain(rd) != 0) {
kfree(rd);
return NULL;
}
return rd;
}
static void free_sched_groups(struct sched_group *sg, int free_sgp)
{
struct sched_group *tmp, *first;
if (!sg)
return;
first = sg;
do {
tmp = sg->next;
if (free_sgp && atomic_dec_and_test(&sg->sgp->ref))
kfree(sg->sgp);
kfree(sg);
sg = tmp;
} while (sg != first);
}
static void free_sched_domain(struct rcu_head *rcu)
{
struct sched_domain *sd = container_of(rcu, struct sched_domain, rcu);
if (sd->flags & SD_OVERLAP) {
free_sched_groups(sd->groups, 1);
} else if (atomic_dec_and_test(&sd->groups->ref)) {
kfree(sd->groups->sgp);
kfree(sd->groups);
}
kfree(sd);
}
static void destroy_sched_domain(struct sched_domain *sd, int cpu)
{
call_rcu(&sd->rcu, free_sched_domain);
}
static void destroy_sched_domains(struct sched_domain *sd, int cpu)
{
for (; sd; sd = sd->parent)
destroy_sched_domain(sd, cpu);
}
static void
cpu_attach_domain(struct sched_domain *sd, struct root_domain *rd, int cpu)
{
struct rq *rq = cpu_rq(cpu);
struct sched_domain *tmp;
for (tmp = sd; tmp; ) {
struct sched_domain *parent = tmp->parent;
if (!parent)
break;
if (sd_parent_degenerate(tmp, parent)) {
tmp->parent = parent->parent;
if (parent->parent)
parent->parent->child = tmp;
destroy_sched_domain(parent, cpu);
} else
tmp = tmp->parent;
}
if (sd && sd_degenerate(sd)) {
tmp = sd;
sd = sd->parent;
destroy_sched_domain(tmp, cpu);
if (sd)
sd->child = NULL;
}
sched_domain_debug(sd, cpu);
rq_attach_root(rq, rd);
tmp = rq->sd;
rcu_assign_pointer(rq->sd, sd);
destroy_sched_domains(tmp, cpu);
}
static int __init isolated_cpu_setup(char *str)
{
alloc_bootmem_cpumask_var(&cpu_isolated_map);
cpulist_parse(str, cpu_isolated_map);
return 1;
}
static int find_next_best_node(int node, nodemask_t *used_nodes)
{
int i, n, val, min_val, best_node = -1;
min_val = INT_MAX;
for (i = 0; i < nr_node_ids; i++) {
n = (node + i) % nr_node_ids;
if (!nr_cpus_node(n))
continue;
if (node_isset(n, *used_nodes))
continue;
val = node_distance(node, n);
if (val < min_val) {
min_val = val;
best_node = n;
}
}
if (best_node != -1)
node_set(best_node, *used_nodes);
return best_node;
}
static void sched_domain_node_span(int node, struct cpumask *span)
{
nodemask_t used_nodes;
int i;
cpumask_clear(span);
nodes_clear(used_nodes);
cpumask_or(span, span, cpumask_of_node(node));
node_set(node, used_nodes);
for (i = 1; i < SD_NODES_PER_DOMAIN; i++) {
int next_node = find_next_best_node(node, &used_nodes);
if (next_node < 0)
break;
cpumask_or(span, span, cpumask_of_node(next_node));
}
}
static const struct cpumask *cpu_node_mask(int cpu)
{
lockdep_assert_held(&sched_domains_mutex);
sched_domain_node_span(cpu_to_node(cpu), sched_domains_tmpmask);
return sched_domains_tmpmask;
}
static const struct cpumask *cpu_allnodes_mask(int cpu)
{
return cpu_possible_mask;
}
static const struct cpumask *cpu_cpu_mask(int cpu)
{
return cpumask_of_node(cpu_to_node(cpu));
}
static int
build_overlap_sched_groups(struct sched_domain *sd, int cpu)
{
struct sched_group *first = NULL, *last = NULL, *groups = NULL, *sg;
const struct cpumask *span = sched_domain_span(sd);
struct cpumask *covered = sched_domains_tmpmask;
struct sd_data *sdd = sd->private;
struct sched_domain *child;
int i;
cpumask_clear(covered);
for_each_cpu(i, span) {
struct cpumask *sg_span;
if (cpumask_test_cpu(i, covered))
continue;
sg = kzalloc_node(sizeof(struct sched_group) + cpumask_size(),
GFP_KERNEL, cpu_to_node(i));
if (!sg)
goto fail;
sg_span = sched_group_cpus(sg);
child = *per_cpu_ptr(sdd->sd, i);
if (child->child) {
child = child->child;
cpumask_copy(sg_span, sched_domain_span(child));
} else
cpumask_set_cpu(i, sg_span);
cpumask_or(covered, covered, sg_span);
sg->sgp = *per_cpu_ptr(sdd->sgp, cpumask_first(sg_span));
atomic_inc(&sg->sgp->ref);
if (cpumask_test_cpu(cpu, sg_span))
groups = sg;
if (!first)
first = sg;
if (last)
last->next = sg;
last = sg;
last->next = first;
}
sd->groups = groups;
return 0;
fail:
free_sched_groups(first, 0);
return -ENOMEM;
}
static int get_group(int cpu, struct sd_data *sdd, struct sched_group **sg)
{
struct sched_domain *sd = *per_cpu_ptr(sdd->sd, cpu);
struct sched_domain *child = sd->child;
if (child)
cpu = cpumask_first(sched_domain_span(child));
if (sg) {
*sg = *per_cpu_ptr(sdd->sg, cpu);
(*sg)->sgp = *per_cpu_ptr(sdd->sgp, cpu);
atomic_set(&(*sg)->sgp->ref, 1);
}
return cpu;
}
static int
build_sched_groups(struct sched_domain *sd, int cpu)
{
struct sched_group *first = NULL, *last = NULL;
struct sd_data *sdd = sd->private;
const struct cpumask *span = sched_domain_span(sd);
struct cpumask *covered;
int i;
get_group(cpu, sdd, &sd->groups);
atomic_inc(&sd->groups->ref);
if (cpu != cpumask_first(sched_domain_span(sd)))
return 0;
lockdep_assert_held(&sched_domains_mutex);
covered = sched_domains_tmpmask;
cpumask_clear(covered);
for_each_cpu(i, span) {
struct sched_group *sg;
int group = get_group(i, sdd, &sg);
int j;
if (cpumask_test_cpu(i, covered))
continue;
cpumask_clear(sched_group_cpus(sg));
sg->sgp->power = 0;
for_each_cpu(j, span) {
if (get_group(j, sdd, NULL) != group)
continue;
cpumask_set_cpu(j, covered);
cpumask_set_cpu(j, sched_group_cpus(sg));
}
if (!first)
first = sg;
if (last)
last->next = sg;
last = sg;
}
last->next = first;
return 0;
}
static void init_sched_groups_power(int cpu, struct sched_domain *sd)
{
struct sched_group *sg = sd->groups;
WARN_ON(!sd || !sg);
do {
sg->group_weight = cpumask_weight(sched_group_cpus(sg));
sg = sg->next;
} while (sg != sd->groups);
if (cpu != group_first_cpu(sg))
return;
update_group_power(sd, cpu);
}
static int __init setup_relax_domain_level(char *str)
{
unsigned long val;
val = simple_strtoul(str, NULL, 0);
if (val < sched_domain_level_max)
default_relax_domain_level = val;
return 1;
}
static void set_domain_attribute(struct sched_domain *sd,
struct sched_domain_attr *attr)
{
int request;
if (!attr || attr->relax_domain_level < 0) {
if (default_relax_domain_level < 0)
return;
else
request = default_relax_domain_level;
} else
request = attr->relax_domain_level;
if (request < sd->level) {
sd->flags &= ~(SD_BALANCE_WAKE|SD_BALANCE_NEWIDLE);
} else {
sd->flags |= (SD_BALANCE_WAKE|SD_BALANCE_NEWIDLE);
}
}
static void __free_domain_allocs(struct s_data *d, enum s_alloc what,
const struct cpumask *cpu_map)
{
switch (what) {
case sa_rootdomain:
if (!atomic_read(&d->rd->refcount))
free_rootdomain(&d->rd->rcu);
case sa_sd:
free_percpu(d->sd);
case sa_sd_storage:
__sdt_free(cpu_map);
case sa_none:
break;
}
}
static enum s_alloc __visit_domain_allocation_hell(struct s_data *d,
const struct cpumask *cpu_map)
{
memset(d, 0, sizeof(*d));
if (__sdt_alloc(cpu_map))
return sa_sd_storage;
d->sd = alloc_percpu(struct sched_domain *);
if (!d->sd)
return sa_sd_storage;
d->rd = alloc_rootdomain();
if (!d->rd)
return sa_sd;
return sa_rootdomain;
}
static void claim_allocations(int cpu, struct sched_domain *sd)
{
struct sd_data *sdd = sd->private;
WARN_ON_ONCE(*per_cpu_ptr(sdd->sd, cpu) != sd);
*per_cpu_ptr(sdd->sd, cpu) = NULL;
if (atomic_read(&(*per_cpu_ptr(sdd->sg, cpu))->ref))
*per_cpu_ptr(sdd->sg, cpu) = NULL;
if (atomic_read(&(*per_cpu_ptr(sdd->sgp, cpu))->ref))
*per_cpu_ptr(sdd->sgp, cpu) = NULL;
}
static const struct cpumask *cpu_smt_mask(int cpu)
{
return topology_thread_cpumask(cpu);
}
static int __sdt_alloc(const struct cpumask *cpu_map)
{
struct sched_domain_topology_level *tl;
int j;
for (tl = sched_domain_topology; tl->init; tl++) {
struct sd_data *sdd = &tl->data;
sdd->sd = alloc_percpu(struct sched_domain *);
if (!sdd->sd)
return -ENOMEM;
sdd->sg = alloc_percpu(struct sched_group *);
if (!sdd->sg)
return -ENOMEM;
sdd->sgp = alloc_percpu(struct sched_group_power *);
if (!sdd->sgp)
return -ENOMEM;
for_each_cpu(j, cpu_map) {
struct sched_domain *sd;
struct sched_group *sg;
struct sched_group_power *sgp;
sd = kzalloc_node(sizeof(struct sched_domain) + cpumask_size(),
GFP_KERNEL, cpu_to_node(j));
if (!sd)
return -ENOMEM;
*per_cpu_ptr(sdd->sd, j) = sd;
sg = kzalloc_node(sizeof(struct sched_group) + cpumask_size(),
GFP_KERNEL, cpu_to_node(j));
if (!sg)
return -ENOMEM;
*per_cpu_ptr(sdd->sg, j) = sg;
sgp = kzalloc_node(sizeof(struct sched_group_power),
GFP_KERNEL, cpu_to_node(j));
if (!sgp)
return -ENOMEM;
*per_cpu_ptr(sdd->sgp, j) = sgp;
}
}
return 0;
}
static void __sdt_free(const struct cpumask *cpu_map)
{
struct sched_domain_topology_level *tl;
int j;
for (tl = sched_domain_topology; tl->init; tl++) {
struct sd_data *sdd = &tl->data;
for_each_cpu(j, cpu_map) {
struct sched_domain *sd = *per_cpu_ptr(sdd->sd, j);
if (sd && (sd->flags & SD_OVERLAP))
free_sched_groups(sd->groups, 0);
kfree(*per_cpu_ptr(sdd->sd, j));
kfree(*per_cpu_ptr(sdd->sg, j));
kfree(*per_cpu_ptr(sdd->sgp, j));
}
free_percpu(sdd->sd);
free_percpu(sdd->sg);
free_percpu(sdd->sgp);
}
}
struct sched_domain *build_sched_domain(struct sched_domain_topology_level *tl,
struct s_data *d, const struct cpumask *cpu_map,
struct sched_domain_attr *attr, struct sched_domain *child,
int cpu)
{
struct sched_domain *sd = tl->init(tl, cpu);
if (!sd)
return child;
set_domain_attribute(sd, attr);
cpumask_and(sched_domain_span(sd), cpu_map, tl->mask(cpu));
if (child) {
sd->level = child->level + 1;
sched_domain_level_max = max(sched_domain_level_max, sd->level);
child->parent = sd;
}
sd->child = child;
return sd;
}
static int build_sched_domains(const struct cpumask *cpu_map,
struct sched_domain_attr *attr)
{
enum s_alloc alloc_state = sa_none;
struct sched_domain *sd;
struct s_data d;
int i, ret = -ENOMEM;
alloc_state = __visit_domain_allocation_hell(&d, cpu_map);
if (alloc_state != sa_rootdomain)
goto error;
for_each_cpu(i, cpu_map) {
struct sched_domain_topology_level *tl;
sd = NULL;
for (tl = sched_domain_topology; tl->init; tl++) {
sd = build_sched_domain(tl, &d, cpu_map, attr, sd, i);
if (tl->flags & SDTL_OVERLAP || sched_feat(FORCE_SD_OVERLAP))
sd->flags |= SD_OVERLAP;
if (cpumask_equal(cpu_map, sched_domain_span(sd)))
break;
}
while (sd->child)
sd = sd->child;
*per_cpu_ptr(d.sd, i) = sd;
}
for_each_cpu(i, cpu_map) {
for (sd = *per_cpu_ptr(d.sd, i); sd; sd = sd->parent) {
sd->span_weight = cpumask_weight(sched_domain_span(sd));
if (sd->flags & SD_OVERLAP) {
if (build_overlap_sched_groups(sd, i))
goto error;
} else {
if (build_sched_groups(sd, i))
goto error;
}
}
}
for (i = nr_cpumask_bits-1; i >= 0; i--) {
if (!cpumask_test_cpu(i, cpu_map))
continue;
for (sd = *per_cpu_ptr(d.sd, i); sd; sd = sd->parent) {
claim_allocations(i, sd);
init_sched_groups_power(i, sd);
}
}
rcu_read_lock();
for_each_cpu(i, cpu_map) {
sd = *per_cpu_ptr(d.sd, i);
cpu_attach_domain(sd, d.rd, i);
}
rcu_read_unlock();
ret = 0;
error:
__free_domain_allocs(&d, alloc_state, cpu_map);
return ret;
}
cpumask_var_t *alloc_sched_domains(unsigned int ndoms)
{
int i;
cpumask_var_t *doms;
doms = kmalloc(sizeof(*doms) * ndoms, GFP_KERNEL);
if (!doms)
return NULL;
for (i = 0; i < ndoms; i++) {
if (!alloc_cpumask_var(&doms[i], GFP_KERNEL)) {
free_sched_domains(doms, i);
return NULL;
}
}
return doms;
}
void free_sched_domains(cpumask_var_t doms[], unsigned int ndoms)
{
unsigned int i;
for (i = 0; i < ndoms; i++)
free_cpumask_var(doms[i]);
kfree(doms);
}
static int init_sched_domains(const struct cpumask *cpu_map)
{
int err;
arch_update_cpu_topology();
ndoms_cur = 1;
doms_cur = alloc_sched_domains(ndoms_cur);
if (!doms_cur)
doms_cur = &fallback_doms;
cpumask_andnot(doms_cur[0], cpu_map, cpu_isolated_map);
dattr_cur = NULL;
err = build_sched_domains(doms_cur[0], NULL);
register_sched_domain_sysctl();
return err;
}
static void detach_destroy_domains(const struct cpumask *cpu_map)
{
int i;
rcu_read_lock();
for_each_cpu(i, cpu_map)
cpu_attach_domain(NULL, &def_root_domain, i);
rcu_read_unlock();
}
static int dattrs_equal(struct sched_domain_attr *cur, int idx_cur,
struct sched_domain_attr *new, int idx_new)
{
struct sched_domain_attr tmp;
if (!new && !cur)
return 1;
tmp = SD_ATTR_INIT;
return !memcmp(cur ? (cur + idx_cur) : &tmp,
new ? (new + idx_new) : &tmp,
sizeof(struct sched_domain_attr));
}
void partition_sched_domains(int ndoms_new, cpumask_var_t doms_new[],
struct sched_domain_attr *dattr_new)
{
int i, j, n;
int new_topology;
mutex_lock(&sched_domains_mutex);
unregister_sched_domain_sysctl();
new_topology = arch_update_cpu_topology();
n = doms_new ? ndoms_new : 0;
for (i = 0; i < ndoms_cur; i++) {
for (j = 0; j < n && !new_topology; j++) {
if (cpumask_equal(doms_cur[i], doms_new[j])
&& dattrs_equal(dattr_cur, i, dattr_new, j))
goto match1;
}
detach_destroy_domains(doms_cur[i]);
match1:
;
}
if (doms_new == NULL) {
ndoms_cur = 0;
doms_new = &fallback_doms;
cpumask_andnot(doms_new[0], cpu_active_mask, cpu_isolated_map);
WARN_ON_ONCE(dattr_new);
}
for (i = 0; i < ndoms_new; i++) {
for (j = 0; j < ndoms_cur && !new_topology; j++) {
if (cpumask_equal(doms_new[i], doms_cur[j])
&& dattrs_equal(dattr_new, i, dattr_cur, j))
goto match2;
}
build_sched_domains(doms_new[i], dattr_new ? dattr_new + i : NULL);
match2:
;
}
if (doms_cur != &fallback_doms)
free_sched_domains(doms_cur, ndoms_cur);
kfree(dattr_cur);
doms_cur = doms_new;
dattr_cur = dattr_new;
ndoms_cur = ndoms_new;
register_sched_domain_sysctl();
mutex_unlock(&sched_domains_mutex);
}
static void reinit_sched_domains(void)
{
get_online_cpus();
partition_sched_domains(0, NULL, NULL);
rebuild_sched_domains();
put_online_cpus();
}
static ssize_t sched_power_savings_store(const char *buf, size_t count, int smt)
{
unsigned int level = 0;
if (sscanf(buf, "%u", &level) != 1)
return -EINVAL;
if (level >= MAX_POWERSAVINGS_BALANCE_LEVELS)
return -EINVAL;
if (smt)
sched_smt_power_savings = level;
else
sched_mc_power_savings = level;
reinit_sched_domains();
return count;
}
static ssize_t sched_mc_power_savings_show(struct sysdev_class *class,
struct sysdev_class_attribute *attr,
char *page)
{
return sprintf(page, "%u\n", sched_mc_power_savings);
}
static ssize_t sched_mc_power_savings_store(struct sysdev_class *class,
struct sysdev_class_attribute *attr,
const char *buf, size_t count)
{
return sched_power_savings_store(buf, count, 0);
}
static ssize_t sched_smt_power_savings_show(struct sysdev_class *dev,
struct sysdev_class_attribute *attr,
char *page)
{
return sprintf(page, "%u\n", sched_smt_power_savings);
}
static ssize_t sched_smt_power_savings_store(struct sysdev_class *dev,
struct sysdev_class_attribute *attr,
const char *buf, size_t count)
{
return sched_power_savings_store(buf, count, 1);
}
int __init sched_create_sysfs_power_savings_entries(struct sysdev_class *cls)
{
int err = 0;
#ifdef CONFIG_SCHED_SMT
if (smt_capable())
err = sysfs_create_file(&cls->kset.kobj,
&attr_sched_smt_power_savings.attr);
#endif
#ifdef CONFIG_SCHED_MC
if (!err && mc_capable())
err = sysfs_create_file(&cls->kset.kobj,
&attr_sched_mc_power_savings.attr);
#endif
return err;
}
static int cpuset_cpu_active(struct notifier_block *nfb, unsigned long action,
void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_ONLINE:
case CPU_DOWN_FAILED:
cpuset_update_active_cpus();
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static int cpuset_cpu_inactive(struct notifier_block *nfb, unsigned long action,
void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
cpuset_update_active_cpus();
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
static int update_runtime(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
int cpu = (int)(long)hcpu;
switch (action) {
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
disable_runtime(cpu_rq(cpu));
return NOTIFY_OK;
case CPU_DOWN_FAILED:
case CPU_DOWN_FAILED_FROZEN:
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
enable_runtime(cpu_rq(cpu));
return NOTIFY_OK;
default:
return NOTIFY_DONE;
}
}
void __init sched_init_smp(void)
{
cpumask_var_t non_isolated_cpus;
alloc_cpumask_var(&non_isolated_cpus, GFP_KERNEL);
alloc_cpumask_var(&fallback_doms, GFP_KERNEL);
get_online_cpus();
mutex_lock(&sched_domains_mutex);
init_sched_domains(cpu_active_mask);
cpumask_andnot(non_isolated_cpus, cpu_possible_mask, cpu_isolated_map);
if (cpumask_empty(non_isolated_cpus))
cpumask_set_cpu(smp_processor_id(), non_isolated_cpus);
mutex_unlock(&sched_domains_mutex);
put_online_cpus();
hotcpu_notifier(cpuset_cpu_active, CPU_PRI_CPUSET_ACTIVE);
hotcpu_notifier(cpuset_cpu_inactive, CPU_PRI_CPUSET_INACTIVE);
hotcpu_notifier(update_runtime, 0);
init_hrtick();
if (set_cpus_allowed_ptr(current, non_isolated_cpus) < 0)
BUG();
sched_init_granularity();
free_cpumask_var(non_isolated_cpus);
init_sched_rt_class();
}
void __init sched_init_smp(void)
{
sched_init_granularity();
}
int in_sched_functions(unsigned long addr)
{
return in_lock_functions(addr) ||
(addr >= (unsigned long)__sched_text_start
&& addr < (unsigned long)__sched_text_end);
}
static void init_cfs_rq(struct cfs_rq *cfs_rq)
{
cfs_rq->tasks_timeline = RB_ROOT;
INIT_LIST_HEAD(&cfs_rq->tasks);
cfs_rq->min_vruntime = (u64)(-(1LL << 20));
#ifndef CONFIG_64BIT
cfs_rq->min_vruntime_copy = cfs_rq->min_vruntime;
#endif
}
static void init_rt_rq(struct rt_rq *rt_rq, struct rq *rq)
{
struct rt_prio_array *array;
int i;
array = &rt_rq->active;
for (i = 0; i < MAX_RT_PRIO; i++) {
INIT_LIST_HEAD(array->queue + i);
__clear_bit(i, array->bitmap);
}
__set_bit(MAX_RT_PRIO, array->bitmap);
#if defined CONFIG_SMP
rt_rq->highest_prio.curr = MAX_RT_PRIO;
rt_rq->highest_prio.next = MAX_RT_PRIO;
rt_rq->rt_nr_migratory = 0;
rt_rq->overloaded = 0;
plist_head_init(&rt_rq->pushable_tasks);
#endif
rt_rq->rt_time = 0;
rt_rq->rt_throttled = 0;
rt_rq->rt_runtime = 0;
raw_spin_lock_init(&rt_rq->rt_runtime_lock);
}
static void init_tg_cfs_entry(struct task_group *tg, struct cfs_rq *cfs_rq,
struct sched_entity *se, int cpu,
struct sched_entity *parent)
{
struct rq *rq = cpu_rq(cpu);
cfs_rq->tg = tg;
cfs_rq->rq = rq;
#ifdef CONFIG_SMP
cfs_rq->load_stamp = 1;
#endif
tg->cfs_rq[cpu] = cfs_rq;
tg->se[cpu] = se;
if (!se)
return;
if (!parent)
se->cfs_rq = &rq->cfs;
else
se->cfs_rq = parent->my_q;
se->my_q = cfs_rq;
update_load_set(&se->load, 0);
se->parent = parent;
}
static void init_tg_rt_entry(struct task_group *tg, struct rt_rq *rt_rq,
struct sched_rt_entity *rt_se, int cpu,
struct sched_rt_entity *parent)
{
struct rq *rq = cpu_rq(cpu);
rt_rq->highest_prio.curr = MAX_RT_PRIO;
rt_rq->rt_nr_boosted = 0;
rt_rq->rq = rq;
rt_rq->tg = tg;
tg->rt_rq[cpu] = rt_rq;
tg->rt_se[cpu] = rt_se;
if (!rt_se)
return;
if (!parent)
rt_se->rt_rq = &rq->rt;
else
rt_se->rt_rq = parent->my_q;
rt_se->my_q = rt_rq;
rt_se->parent = parent;
INIT_LIST_HEAD(&rt_se->run_list);
}
void __init sched_init(void)
{
int i, j;
unsigned long alloc_size = 0, ptr;
#ifdef CONFIG_FAIR_GROUP_SCHED
alloc_size += 2 * nr_cpu_ids * sizeof(void **);
#endif
#ifdef CONFIG_RT_GROUP_SCHED
alloc_size += 2 * nr_cpu_ids * sizeof(void **);
#endif
#ifdef CONFIG_CPUMASK_OFFSTACK
alloc_size += num_possible_cpus() * cpumask_size();
#endif
if (alloc_size) {
ptr = (unsigned long)kzalloc(alloc_size, GFP_NOWAIT);
#ifdef CONFIG_FAIR_GROUP_SCHED
root_task_group.se = (struct sched_entity **)ptr;
ptr += nr_cpu_ids * sizeof(void **);
root_task_group.cfs_rq = (struct cfs_rq **)ptr;
ptr += nr_cpu_ids * sizeof(void **);
#endif
#ifdef CONFIG_RT_GROUP_SCHED
root_task_group.rt_se = (struct sched_rt_entity **)ptr;
ptr += nr_cpu_ids * sizeof(void **);
root_task_group.rt_rq = (struct rt_rq **)ptr;
ptr += nr_cpu_ids * sizeof(void **);
#endif
#ifdef CONFIG_CPUMASK_OFFSTACK
for_each_possible_cpu(i) {
per_cpu(load_balance_tmpmask, i) = (void *)ptr;
ptr += cpumask_size();
}
#endif
}
#ifdef CONFIG_SMP
init_defrootdomain();
#endif
init_rt_bandwidth(&def_rt_bandwidth,
global_rt_period(), global_rt_runtime());
#ifdef CONFIG_RT_GROUP_SCHED
init_rt_bandwidth(&root_task_group.rt_bandwidth,
global_rt_period(), global_rt_runtime());
#endif
#ifdef CONFIG_CGROUP_SCHED
list_add(&root_task_group.list, &task_groups);
INIT_LIST_HEAD(&root_task_group.children);
autogroup_init(&init_task);
#endif
for_each_possible_cpu(i) {
struct rq *rq;
rq = cpu_rq(i);
raw_spin_lock_init(&rq->lock);
rq->nr_running = 0;
rq->calc_load_active = 0;
rq->calc_load_update = jiffies + LOAD_FREQ;
init_cfs_rq(&rq->cfs);
init_rt_rq(&rq->rt, rq);
#ifdef CONFIG_FAIR_GROUP_SCHED
root_task_group.shares = root_task_group_load;
INIT_LIST_HEAD(&rq->leaf_cfs_rq_list);
init_tg_cfs_entry(&root_task_group, &rq->cfs, NULL, i, NULL);
#endif
rq->rt.rt_runtime = def_rt_bandwidth.rt_runtime;
#ifdef CONFIG_RT_GROUP_SCHED
INIT_LIST_HEAD(&rq->leaf_rt_rq_list);
init_tg_rt_entry(&root_task_group, &rq->rt, NULL, i, NULL);
#endif
for (j = 0; j < CPU_LOAD_IDX_MAX; j++)
rq->cpu_load[j] = 0;
rq->last_load_update_tick = jiffies;
#ifdef CONFIG_SMP
rq->sd = NULL;
rq->rd = NULL;
rq->cpu_power = SCHED_POWER_SCALE;
rq->post_schedule = 0;
rq->active_balance = 0;
rq->next_balance = jiffies;
rq->push_cpu = 0;
rq->cpu = i;
rq->online = 0;
rq->idle_stamp = 0;
rq->avg_idle = 2*sysctl_sched_migration_cost;
rq_attach_root(rq, &def_root_domain);
#ifdef CONFIG_NO_HZ
rq->nohz_balance_kick = 0;
init_sched_softirq_csd(&per_cpu(remote_sched_softirq_cb, i));
#endif
#endif
init_rq_hrtick(rq);
atomic_set(&rq->nr_iowait, 0);
}
set_load_weight(&init_task);
#ifdef CONFIG_PREEMPT_NOTIFIERS
INIT_HLIST_HEAD(&init_task.preempt_notifiers);
#endif
#ifdef CONFIG_SMP
open_softirq(SCHED_SOFTIRQ, run_rebalance_domains);
#endif
#ifdef CONFIG_RT_MUTEXES
plist_head_init(&init_task.pi_waiters);
#endif
atomic_inc(&init_mm.mm_count);
enter_lazy_tlb(&init_mm, current);
init_idle(current, smp_processor_id());
calc_load_update = jiffies + LOAD_FREQ;
current->sched_class = &fair_sched_class;
zalloc_cpumask_var(&nohz_cpu_mask, GFP_NOWAIT);
#ifdef CONFIG_SMP
zalloc_cpumask_var(&sched_domains_tmpmask, GFP_NOWAIT);
#ifdef CONFIG_NO_HZ
zalloc_cpumask_var(&nohz.idle_cpus_mask, GFP_NOWAIT);
alloc_cpumask_var(&nohz.grp_idle_mask, GFP_NOWAIT);
atomic_set(&nohz.load_balancer, nr_cpu_ids);
atomic_set(&nohz.first_pick_cpu, nr_cpu_ids);
atomic_set(&nohz.second_pick_cpu, nr_cpu_ids);
#endif
if (cpu_isolated_map == NULL)
zalloc_cpumask_var(&cpu_isolated_map, GFP_NOWAIT);
#endif
scheduler_running = 1;
}
static inline int preempt_count_equals(int preempt_offset)
{
int nested = (preempt_count() & ~PREEMPT_ACTIVE) + rcu_preempt_depth();
return (nested == preempt_offset);
}
void __might_sleep(const char *file, int line, int preempt_offset)
{
static unsigned long prev_jiffy;
if ((preempt_count_equals(preempt_offset) && !irqs_disabled()) ||
system_state != SYSTEM_RUNNING || oops_in_progress)
return;
if (time_before(jiffies, prev_jiffy + HZ) && prev_jiffy)
return;
prev_jiffy = jiffies;
printk(KERN_ERR
"BUG: sleeping function called from invalid context at %s:%d\n",
file, line);
printk(KERN_ERR
"in_atomic(): %d, irqs_disabled(): %d, pid: %d, name: %s\n",
in_atomic(), irqs_disabled(),
current->pid, current->comm);
debug_show_held_locks(current);
if (irqs_disabled())
print_irqtrace_events(current);
dump_stack();
}
static void normalize_task(struct rq *rq, struct task_struct *p)
{
const struct sched_class *prev_class = p->sched_class;
int old_prio = p->prio;
int on_rq;
on_rq = p->on_rq;
if (on_rq)
deactivate_task(rq, p, 0);
__setscheduler(rq, p, SCHED_NORMAL, 0);
if (on_rq) {
activate_task(rq, p, 0);
resched_task(rq->curr);
}
check_class_changed(rq, p, prev_class, old_prio);
}
void normalize_rt_tasks(void)
{
struct task_struct *g, *p;
unsigned long flags;
struct rq *rq;
read_lock_irqsave(&tasklist_lock, flags);
do_each_thread(g, p) {
if (!p->mm)
continue;
p->se.exec_start = 0;
#ifdef CONFIG_SCHEDSTATS
p->se.statistics.wait_start = 0;
p->se.statistics.sleep_start = 0;
p->se.statistics.block_start = 0;
#endif
if (!rt_task(p)) {
if (TASK_NICE(p) < 0 && p->mm)
set_user_nice(p, 0);
continue;
}
raw_spin_lock(&p->pi_lock);
rq = __task_rq_lock(p);
normalize_task(rq, p);
__task_rq_unlock(rq);
raw_spin_unlock(&p->pi_lock);
} while_each_thread(g, p);
read_unlock_irqrestore(&tasklist_lock, flags);
}
struct task_struct *curr_task(int cpu)
{
return cpu_curr(cpu);
}
void set_curr_task(int cpu, struct task_struct *p)
{
cpu_curr(cpu) = p;
}
static void free_fair_sched_group(struct task_group *tg)
{
int i;
for_each_possible_cpu(i) {
if (tg->cfs_rq)
kfree(tg->cfs_rq[i]);
if (tg->se)
kfree(tg->se[i]);
}
kfree(tg->cfs_rq);
kfree(tg->se);
}
static
int alloc_fair_sched_group(struct task_group *tg, struct task_group *parent)
{
struct cfs_rq *cfs_rq;
struct sched_entity *se;
int i;
tg->cfs_rq = kzalloc(sizeof(cfs_rq) * nr_cpu_ids, GFP_KERNEL);
if (!tg->cfs_rq)
goto err;
tg->se = kzalloc(sizeof(se) * nr_cpu_ids, GFP_KERNEL);
if (!tg->se)
goto err;
tg->shares = NICE_0_LOAD;
for_each_possible_cpu(i) {
cfs_rq = kzalloc_node(sizeof(struct cfs_rq),
GFP_KERNEL, cpu_to_node(i));
if (!cfs_rq)
goto err;
se = kzalloc_node(sizeof(struct sched_entity),
GFP_KERNEL, cpu_to_node(i));
if (!se)
goto err_free_rq;
init_cfs_rq(cfs_rq);
init_tg_cfs_entry(tg, cfs_rq, se, i, parent->se[i]);
}
return 1;
err_free_rq:
kfree(cfs_rq);
err:
return 0;
}
static inline void unregister_fair_sched_group(struct task_group *tg, int cpu)
{
struct rq *rq = cpu_rq(cpu);
unsigned long flags;
if (!tg->cfs_rq[cpu]->on_list)
return;
raw_spin_lock_irqsave(&rq->lock, flags);
list_del_leaf_cfs_rq(tg->cfs_rq[cpu]);
raw_spin_unlock_irqrestore(&rq->lock, flags);
}
static inline void free_fair_sched_group(struct task_group *tg)
{
}
static inline
int alloc_fair_sched_group(struct task_group *tg, struct task_group *parent)
{
return 1;
}
static inline void unregister_fair_sched_group(struct task_group *tg, int cpu)
{
}
static void free_rt_sched_group(struct task_group *tg)
{
int i;
if (tg->rt_se)
destroy_rt_bandwidth(&tg->rt_bandwidth);
for_each_possible_cpu(i) {
if (tg->rt_rq)
kfree(tg->rt_rq[i]);
if (tg->rt_se)
kfree(tg->rt_se[i]);
}
kfree(tg->rt_rq);
kfree(tg->rt_se);
}
static
int alloc_rt_sched_group(struct task_group *tg, struct task_group *parent)
{
struct rt_rq *rt_rq;
struct sched_rt_entity *rt_se;
int i;
tg->rt_rq = kzalloc(sizeof(rt_rq) * nr_cpu_ids, GFP_KERNEL);
if (!tg->rt_rq)
goto err;
tg->rt_se = kzalloc(sizeof(rt_se) * nr_cpu_ids, GFP_KERNEL);
if (!tg->rt_se)
goto err;
init_rt_bandwidth(&tg->rt_bandwidth,
ktime_to_ns(def_rt_bandwidth.rt_period), 0);
for_each_possible_cpu(i) {
rt_rq = kzalloc_node(sizeof(struct rt_rq),
GFP_KERNEL, cpu_to_node(i));
if (!rt_rq)
goto err;
rt_se = kzalloc_node(sizeof(struct sched_rt_entity),
GFP_KERNEL, cpu_to_node(i));
if (!rt_se)
goto err_free_rq;
init_rt_rq(rt_rq, cpu_rq(i));
rt_rq->rt_runtime = tg->rt_bandwidth.rt_runtime;
init_tg_rt_entry(tg, rt_rq, rt_se, i, parent->rt_se[i]);
}
return 1;
err_free_rq:
kfree(rt_rq);
err:
return 0;
}
static inline void free_rt_sched_group(struct task_group *tg)
{
}
static inline
int alloc_rt_sched_group(struct task_group *tg, struct task_group *parent)
{
return 1;
}
static void free_sched_group(struct task_group *tg)
{
free_fair_sched_group(tg);
free_rt_sched_group(tg);
autogroup_free(tg);
kfree(tg);
}
struct task_group *sched_create_group(struct task_group *parent)
{
struct task_group *tg;
unsigned long flags;
tg = kzalloc(sizeof(*tg), GFP_KERNEL);
if (!tg)
return ERR_PTR(-ENOMEM);
if (!alloc_fair_sched_group(tg, parent))
goto err;
if (!alloc_rt_sched_group(tg, parent))
goto err;
spin_lock_irqsave(&task_group_lock, flags);
list_add_rcu(&tg->list, &task_groups);
WARN_ON(!parent);
tg->parent = parent;
INIT_LIST_HEAD(&tg->children);
list_add_rcu(&tg->siblings, &parent->children);
spin_unlock_irqrestore(&task_group_lock, flags);
return tg;
err:
free_sched_group(tg);
return ERR_PTR(-ENOMEM);
}
static void free_sched_group_rcu(struct rcu_head *rhp)
{
free_sched_group(container_of(rhp, struct task_group, rcu));
}
void sched_destroy_group(struct task_group *tg)
{
unsigned long flags;
int i;
for_each_possible_cpu(i)
unregister_fair_sched_group(tg, i);
spin_lock_irqsave(&task_group_lock, flags);
list_del_rcu(&tg->list);
list_del_rcu(&tg->siblings);
spin_unlock_irqrestore(&task_group_lock, flags);
call_rcu(&tg->rcu, free_sched_group_rcu);
}
void sched_move_task(struct task_struct *tsk)
{
int on_rq, running;
unsigned long flags;
struct rq *rq;
rq = task_rq_lock(tsk, &flags);
running = task_current(rq, tsk);
on_rq = tsk->on_rq;
if (on_rq)
dequeue_task(rq, tsk, 0);
if (unlikely(running))
tsk->sched_class->put_prev_task(rq, tsk);
#ifdef CONFIG_FAIR_GROUP_SCHED
if (tsk->sched_class->task_move_group)
tsk->sched_class->task_move_group(tsk, on_rq);
else
#endif
set_task_rq(tsk, task_cpu(tsk));
if (unlikely(running))
tsk->sched_class->set_curr_task(rq);
if (on_rq)
enqueue_task(rq, tsk, 0);
task_rq_unlock(rq, tsk, &flags);
}
int sched_group_set_shares(struct task_group *tg, unsigned long shares)
{
int i;
unsigned long flags;
if (!tg->se[0])
return -EINVAL;
shares = clamp(shares, scale_load(MIN_SHARES), scale_load(MAX_SHARES));
mutex_lock(&shares_mutex);
if (tg->shares == shares)
goto done;
tg->shares = shares;
for_each_possible_cpu(i) {
struct rq *rq = cpu_rq(i);
struct sched_entity *se;
se = tg->se[i];
raw_spin_lock_irqsave(&rq->lock, flags);
for_each_sched_entity(se)
update_cfs_shares(group_cfs_rq(se));
raw_spin_unlock_irqrestore(&rq->lock, flags);
}
done:
mutex_unlock(&shares_mutex);
return 0;
}
unsigned long sched_group_shares(struct task_group *tg)
{
return tg->shares;
}
static unsigned long to_ratio(u64 period, u64 runtime)
{
if (runtime == RUNTIME_INF)
return 1ULL << 20;
return div64_u64(runtime << 20, period);
}
static inline int tg_has_rt_tasks(struct task_group *tg)
{
struct task_struct *g, *p;
do_each_thread(g, p) {
if (rt_task(p) && rt_rq_of_se(&p->rt)->tg == tg)
return 1;
} while_each_thread(g, p);
return 0;
}
static int tg_schedulable(struct task_group *tg, void *data)
{
struct rt_schedulable_data *d = data;
struct task_group *child;
unsigned long total, sum = 0;
u64 period, runtime;
period = ktime_to_ns(tg->rt_bandwidth.rt_period);
runtime = tg->rt_bandwidth.rt_runtime;
if (tg == d->tg) {
period = d->rt_period;
runtime = d->rt_runtime;
}
if (runtime > period && runtime != RUNTIME_INF)
return -EINVAL;
if (rt_bandwidth_enabled() && !runtime && tg_has_rt_tasks(tg))
return -EBUSY;
total = to_ratio(period, runtime);
if (total > to_ratio(global_rt_period(), global_rt_runtime()))
return -EINVAL;
list_for_each_entry_rcu(child, &tg->children, siblings) {
period = ktime_to_ns(child->rt_bandwidth.rt_period);
runtime = child->rt_bandwidth.rt_runtime;
if (child == d->tg) {
period = d->rt_period;
runtime = d->rt_runtime;
}
sum += to_ratio(period, runtime);
}
if (sum > total)
return -EINVAL;
return 0;
}
static int __rt_schedulable(struct task_group *tg, u64 period, u64 runtime)
{
struct rt_schedulable_data data = {
.tg = tg,
.rt_period = period,
.rt_runtime = runtime,
};
return walk_tg_tree(tg_schedulable, tg_nop, &data);
}
static int tg_set_bandwidth(struct task_group *tg,
u64 rt_period, u64 rt_runtime)
{
int i, err = 0;
mutex_lock(&rt_constraints_mutex);
read_lock(&tasklist_lock);
err = __rt_schedulable(tg, rt_period, rt_runtime);
if (err)
goto unlock;
raw_spin_lock_irq(&tg->rt_bandwidth.rt_runtime_lock);
tg->rt_bandwidth.rt_period = ns_to_ktime(rt_period);
tg->rt_bandwidth.rt_runtime = rt_runtime;
for_each_possible_cpu(i) {
struct rt_rq *rt_rq = tg->rt_rq[i];
raw_spin_lock(&rt_rq->rt_runtime_lock);
rt_rq->rt_runtime = rt_runtime;
raw_spin_unlock(&rt_rq->rt_runtime_lock);
}
raw_spin_unlock_irq(&tg->rt_bandwidth.rt_runtime_lock);
unlock:
read_unlock(&tasklist_lock);
mutex_unlock(&rt_constraints_mutex);
return err;
}
int sched_group_set_rt_runtime(struct task_group *tg, long rt_runtime_us)
{
u64 rt_runtime, rt_period;
rt_period = ktime_to_ns(tg->rt_bandwidth.rt_period);
rt_runtime = (u64)rt_runtime_us * NSEC_PER_USEC;
if (rt_runtime_us < 0)
rt_runtime = RUNTIME_INF;
return tg_set_bandwidth(tg, rt_period, rt_runtime);
}
long sched_group_rt_runtime(struct task_group *tg)
{
u64 rt_runtime_us;
if (tg->rt_bandwidth.rt_runtime == RUNTIME_INF)
return -1;
rt_runtime_us = tg->rt_bandwidth.rt_runtime;
do_div(rt_runtime_us, NSEC_PER_USEC);
return rt_runtime_us;
}
int sched_group_set_rt_period(struct task_group *tg, long rt_period_us)
{
u64 rt_runtime, rt_period;
rt_period = (u64)rt_period_us * NSEC_PER_USEC;
rt_runtime = tg->rt_bandwidth.rt_runtime;
if (rt_period == 0)
return -EINVAL;
return tg_set_bandwidth(tg, rt_period, rt_runtime);
}
long sched_group_rt_period(struct task_group *tg)
{
u64 rt_period_us;
rt_period_us = ktime_to_ns(tg->rt_bandwidth.rt_period);
do_div(rt_period_us, NSEC_PER_USEC);
return rt_period_us;
}
static int sched_rt_global_constraints(void)
{
u64 runtime, period;
int ret = 0;
if (sysctl_sched_rt_period <= 0)
return -EINVAL;
runtime = global_rt_runtime();
period = global_rt_period();
if (runtime > period && runtime != RUNTIME_INF)
return -EINVAL;
mutex_lock(&rt_constraints_mutex);
read_lock(&tasklist_lock);
ret = __rt_schedulable(NULL, 0, 0);
read_unlock(&tasklist_lock);
mutex_unlock(&rt_constraints_mutex);
return ret;
}
int sched_rt_can_attach(struct task_group *tg, struct task_struct *tsk)
{
if (rt_task(tsk) && tg->rt_bandwidth.rt_runtime == 0)
return 0;
return 1;
}
static int sched_rt_global_constraints(void)
{
unsigned long flags;
int i;
if (sysctl_sched_rt_period <= 0)
return -EINVAL;
if (sysctl_sched_rt_runtime == 0)
return -EBUSY;
raw_spin_lock_irqsave(&def_rt_bandwidth.rt_runtime_lock, flags);
for_each_possible_cpu(i) {
struct rt_rq *rt_rq = &cpu_rq(i)->rt;
raw_spin_lock(&rt_rq->rt_runtime_lock);
rt_rq->rt_runtime = global_rt_runtime();
raw_spin_unlock(&rt_rq->rt_runtime_lock);
}
raw_spin_unlock_irqrestore(&def_rt_bandwidth.rt_runtime_lock, flags);
return 0;
}
int sched_rt_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int ret;
int old_period, old_runtime;
static DEFINE_MUTEX(mutex);
mutex_lock(&mutex);
old_period = sysctl_sched_rt_period;
old_runtime = sysctl_sched_rt_runtime;
ret = proc_dointvec(table, write, buffer, lenp, ppos);
if (!ret && write) {
ret = sched_rt_global_constraints();
if (ret) {
sysctl_sched_rt_period = old_period;
sysctl_sched_rt_runtime = old_runtime;
} else {
def_rt_bandwidth.rt_runtime = global_rt_runtime();
def_rt_bandwidth.rt_period =
ns_to_ktime(global_rt_period());
}
}
mutex_unlock(&mutex);
return ret;
}
static inline struct task_group *cgroup_tg(struct cgroup *cgrp)
{
return container_of(cgroup_subsys_state(cgrp, cpu_cgroup_subsys_id),
struct task_group, css);
}
static struct cgroup_subsys_state *
cpu_cgroup_create(struct cgroup_subsys *ss, struct cgroup *cgrp)
{
struct task_group *tg, *parent;
if (!cgrp->parent) {
return &root_task_group.css;
}
parent = cgroup_tg(cgrp->parent);
tg = sched_create_group(parent);
if (IS_ERR(tg))
return ERR_PTR(-ENOMEM);
return &tg->css;
}
static void
cpu_cgroup_destroy(struct cgroup_subsys *ss, struct cgroup *cgrp)
{
struct task_group *tg = cgroup_tg(cgrp);
sched_destroy_group(tg);
}
static int
cpu_cgroup_can_attach_task(struct cgroup *cgrp, struct task_struct *tsk)
{
#ifdef CONFIG_RT_GROUP_SCHED
if (!sched_rt_can_attach(cgroup_tg(cgrp), tsk))
return -EINVAL;
#else
if (tsk->sched_class != &fair_sched_class)
return -EINVAL;
#endif
return 0;
}
static void
cpu_cgroup_attach_task(struct cgroup *cgrp, struct task_struct *tsk)
{
sched_move_task(tsk);
}
static void
cpu_cgroup_exit(struct cgroup_subsys *ss, struct cgroup *cgrp,
struct cgroup *old_cgrp, struct task_struct *task)
{
if (!(task->flags & PF_EXITING))
return;
sched_move_task(task);
}
static int cpu_shares_write_u64(struct cgroup *cgrp, struct cftype *cftype,
u64 shareval)
{
return sched_group_set_shares(cgroup_tg(cgrp), scale_load(shareval));
}
static u64 cpu_shares_read_u64(struct cgroup *cgrp, struct cftype *cft)
{
struct task_group *tg = cgroup_tg(cgrp);
return (u64) scale_load_down(tg->shares);
}
static int cpu_rt_runtime_write(struct cgroup *cgrp, struct cftype *cft,
s64 val)
{
return sched_group_set_rt_runtime(cgroup_tg(cgrp), val);
}
static s64 cpu_rt_runtime_read(struct cgroup *cgrp, struct cftype *cft)
{
return sched_group_rt_runtime(cgroup_tg(cgrp));
}
static int cpu_rt_period_write_uint(struct cgroup *cgrp, struct cftype *cftype,
u64 rt_period_us)
{
return sched_group_set_rt_period(cgroup_tg(cgrp), rt_period_us);
}
static u64 cpu_rt_period_read_uint(struct cgroup *cgrp, struct cftype *cft)
{
return sched_group_rt_period(cgroup_tg(cgrp));
}
static int cpu_cgroup_populate(struct cgroup_subsys *ss, struct cgroup *cont)
{
return cgroup_add_files(cont, ss, cpu_files, ARRAY_SIZE(cpu_files));
}
static inline struct cpuacct *cgroup_ca(struct cgroup *cgrp)
{
return container_of(cgroup_subsys_state(cgrp, cpuacct_subsys_id),
struct cpuacct, css);
}
static inline struct cpuacct *task_ca(struct task_struct *tsk)
{
return container_of(task_subsys_state(tsk, cpuacct_subsys_id),
struct cpuacct, css);
}
static struct cgroup_subsys_state *cpuacct_create(
struct cgroup_subsys *ss, struct cgroup *cgrp)
{
struct cpuacct *ca = kzalloc(sizeof(*ca), GFP_KERNEL);
int i;
if (!ca)
goto out;
ca->cpuusage = alloc_percpu(u64);
if (!ca->cpuusage)
goto out_free_ca;
for (i = 0; i < CPUACCT_STAT_NSTATS; i++)
if (percpu_counter_init(&ca->cpustat[i], 0))
goto out_free_counters;
if (cgrp->parent)
ca->parent = cgroup_ca(cgrp->parent);
return &ca->css;
out_free_counters:
while (--i >= 0)
percpu_counter_destroy(&ca->cpustat[i]);
free_percpu(ca->cpuusage);
out_free_ca:
kfree(ca);
out:
return ERR_PTR(-ENOMEM);
}
static void
cpuacct_destroy(struct cgroup_subsys *ss, struct cgroup *cgrp)
{
struct cpuacct *ca = cgroup_ca(cgrp);
int i;
for (i = 0; i < CPUACCT_STAT_NSTATS; i++)
percpu_counter_destroy(&ca->cpustat[i]);
free_percpu(ca->cpuusage);
kfree(ca);
}
static u64 cpuacct_cpuusage_read(struct cpuacct *ca, int cpu)
{
u64 *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
u64 data;
#ifndef CONFIG_64BIT
raw_spin_lock_irq(&cpu_rq(cpu)->lock);
data = *cpuusage;
raw_spin_unlock_irq(&cpu_rq(cpu)->lock);
#else
data = *cpuusage;
#endif
return data;
}
static void cpuacct_cpuusage_write(struct cpuacct *ca, int cpu, u64 val)
{
u64 *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
#ifndef CONFIG_64BIT
raw_spin_lock_irq(&cpu_rq(cpu)->lock);
*cpuusage = val;
raw_spin_unlock_irq(&cpu_rq(cpu)->lock);
#else
*cpuusage = val;
#endif
}
static u64 cpuusage_read(struct cgroup *cgrp, struct cftype *cft)
{
struct cpuacct *ca = cgroup_ca(cgrp);
u64 totalcpuusage = 0;
int i;
for_each_present_cpu(i)
totalcpuusage += cpuacct_cpuusage_read(ca, i);
return totalcpuusage;
}
static int cpuusage_write(struct cgroup *cgrp, struct cftype *cftype,
u64 reset)
{
struct cpuacct *ca = cgroup_ca(cgrp);
int err = 0;
int i;
if (reset) {
err = -EINVAL;
goto out;
}
for_each_present_cpu(i)
cpuacct_cpuusage_write(ca, i, 0);
out:
return err;
}
static int cpuacct_percpu_seq_read(struct cgroup *cgroup, struct cftype *cft,
struct seq_file *m)
{
struct cpuacct *ca = cgroup_ca(cgroup);
u64 percpu;
int i;
for_each_present_cpu(i) {
percpu = cpuacct_cpuusage_read(ca, i);
seq_printf(m, "%llu ", (unsigned long long) percpu);
}
seq_printf(m, "\n");
return 0;
}
static int cpuacct_stats_show(struct cgroup *cgrp, struct cftype *cft,
struct cgroup_map_cb *cb)
{
struct cpuacct *ca = cgroup_ca(cgrp);
int i;
for (i = 0; i < CPUACCT_STAT_NSTATS; i++) {
s64 val = percpu_counter_read(&ca->cpustat[i]);
val = cputime64_to_clock_t(val);
cb->fill(cb, cpuacct_stat_desc[i], val);
}
return 0;
}
static int cpuacct_populate(struct cgroup_subsys *ss, struct cgroup *cgrp)
{
return cgroup_add_files(cgrp, ss, files, ARRAY_SIZE(files));
}
static void cpuacct_charge(struct task_struct *tsk, u64 cputime)
{
struct cpuacct *ca;
int cpu;
if (unlikely(!cpuacct_subsys.active))
return;
cpu = task_cpu(tsk);
rcu_read_lock();
ca = task_ca(tsk);
for (; ca; ca = ca->parent) {
u64 *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
*cpuusage += cputime;
}
rcu_read_unlock();
}
static void cpuacct_update_stats(struct task_struct *tsk,
enum cpuacct_stat_index idx, cputime_t val)
{
struct cpuacct *ca;
int batch = CPUACCT_BATCH;
if (unlikely(!cpuacct_subsys.active))
return;
rcu_read_lock();
ca = task_ca(tsk);
do {
__percpu_counter_add(&ca->cpustat[idx], val, batch);
ca = ca->parent;
} while (ca);
rcu_read_unlock();
}
