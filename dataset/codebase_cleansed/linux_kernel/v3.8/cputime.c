void enable_sched_clock_irqtime(void)
{
sched_clock_irqtime = 1;
}
void disable_sched_clock_irqtime(void)
{
sched_clock_irqtime = 0;
}
void irqtime_account_irq(struct task_struct *curr)
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
static int irqtime_account_hi_update(void)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
unsigned long flags;
u64 latest_ns;
int ret = 0;
local_irq_save(flags);
latest_ns = this_cpu_read(cpu_hardirq_time);
if (nsecs_to_cputime64(latest_ns) > cpustat[CPUTIME_IRQ])
ret = 1;
local_irq_restore(flags);
return ret;
}
static int irqtime_account_si_update(void)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
unsigned long flags;
u64 latest_ns;
int ret = 0;
local_irq_save(flags);
latest_ns = this_cpu_read(cpu_softirq_time);
if (nsecs_to_cputime64(latest_ns) > cpustat[CPUTIME_SOFTIRQ])
ret = 1;
local_irq_restore(flags);
return ret;
}
static inline void task_group_account_field(struct task_struct *p, int index,
u64 tmp)
{
#ifdef CONFIG_CGROUP_CPUACCT
struct kernel_cpustat *kcpustat;
struct cpuacct *ca;
#endif
__get_cpu_var(kernel_cpustat).cpustat[index] += tmp;
#ifdef CONFIG_CGROUP_CPUACCT
if (unlikely(!cpuacct_subsys.active))
return;
rcu_read_lock();
ca = task_ca(p);
while (ca && (ca != &root_cpuacct)) {
kcpustat = this_cpu_ptr(ca->cpustat);
kcpustat->cpustat[index] += tmp;
ca = parent_ca(ca);
}
rcu_read_unlock();
#endif
}
void account_user_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled)
{
int index;
p->utime += cputime;
p->utimescaled += cputime_scaled;
account_group_user_time(p, cputime);
index = (TASK_NICE(p) > 0) ? CPUTIME_NICE : CPUTIME_USER;
task_group_account_field(p, index, (__force u64) cputime);
acct_update_integrals(p);
}
static void account_guest_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
p->utime += cputime;
p->utimescaled += cputime_scaled;
account_group_user_time(p, cputime);
p->gtime += cputime;
if (TASK_NICE(p) > 0) {
cpustat[CPUTIME_NICE] += (__force u64) cputime;
cpustat[CPUTIME_GUEST_NICE] += (__force u64) cputime;
} else {
cpustat[CPUTIME_USER] += (__force u64) cputime;
cpustat[CPUTIME_GUEST] += (__force u64) cputime;
}
}
static inline
void __account_system_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled, int index)
{
p->stime += cputime;
p->stimescaled += cputime_scaled;
account_group_system_time(p, cputime);
task_group_account_field(p, index, (__force u64) cputime);
acct_update_integrals(p);
}
void account_system_time(struct task_struct *p, int hardirq_offset,
cputime_t cputime, cputime_t cputime_scaled)
{
int index;
if ((p->flags & PF_VCPU) && (irq_count() - hardirq_offset == 0)) {
account_guest_time(p, cputime, cputime_scaled);
return;
}
if (hardirq_count() - hardirq_offset)
index = CPUTIME_IRQ;
else if (in_serving_softirq())
index = CPUTIME_SOFTIRQ;
else
index = CPUTIME_SYSTEM;
__account_system_time(p, cputime, cputime_scaled, index);
}
void account_steal_time(cputime_t cputime)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
cpustat[CPUTIME_STEAL] += (__force u64) cputime;
}
void account_idle_time(cputime_t cputime)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
struct rq *rq = this_rq();
if (atomic_read(&rq->nr_iowait) > 0)
cpustat[CPUTIME_IOWAIT] += (__force u64) cputime;
else
cpustat[CPUTIME_IDLE] += (__force u64) cputime;
}
static __always_inline bool steal_account_process_tick(void)
{
#ifdef CONFIG_PARAVIRT
if (static_key_false(&paravirt_steal_enabled)) {
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
void thread_group_cputime(struct task_struct *tsk, struct task_cputime *times)
{
struct signal_struct *sig = tsk->signal;
struct task_struct *t;
times->utime = sig->utime;
times->stime = sig->stime;
times->sum_exec_runtime = sig->sum_sched_runtime;
rcu_read_lock();
if (!likely(pid_alive(tsk)))
goto out;
t = tsk;
do {
times->utime += t->utime;
times->stime += t->stime;
times->sum_exec_runtime += task_sched_runtime(t);
} while_each_thread(tsk, t);
void irqtime_account_process_tick(struct task_struct *p, int user_tick,
struct rq *rq)
{
cputime_t one_jiffy_scaled = cputime_to_scaled(cputime_one_jiffy);
u64 *cpustat = kcpustat_this_cpu->cpustat;
if (steal_account_process_tick())
return;
if (irqtime_account_hi_update()) {
cpustat[CPUTIME_IRQ] += (__force u64) cputime_one_jiffy;
} else if (irqtime_account_si_update()) {
cpustat[CPUTIME_SOFTIRQ] += (__force u64) cputime_one_jiffy;
} else if (this_cpu_ksoftirqd() == p) {
__account_system_time(p, cputime_one_jiffy, one_jiffy_scaled,
CPUTIME_SOFTIRQ);
} else if (user_tick) {
account_user_time(p, cputime_one_jiffy, one_jiffy_scaled);
} else if (p == rq->idle) {
account_idle_time(cputime_one_jiffy);
} else if (p->flags & PF_VCPU) {
account_guest_time(p, cputime_one_jiffy, one_jiffy_scaled);
} else {
__account_system_time(p, cputime_one_jiffy, one_jiffy_scaled,
CPUTIME_SYSTEM);
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
void task_cputime_adjusted(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
*ut = p->utime;
*st = p->stime;
}
void thread_group_cputime_adjusted(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
struct task_cputime cputime;
thread_group_cputime(p, &cputime);
*ut = cputime.utime;
*st = cputime.stime;
}
void vtime_account_system_irqsafe(struct task_struct *tsk)
{
unsigned long flags;
local_irq_save(flags);
vtime_account_system(tsk);
local_irq_restore(flags);
}
void vtime_task_switch(struct task_struct *prev)
{
if (is_idle_task(prev))
vtime_account_idle(prev);
else
vtime_account_system(prev);
vtime_account_user(prev);
arch_vtime_task_switch(prev);
}
void vtime_account(struct task_struct *tsk)
{
if (in_interrupt() || !is_idle_task(tsk))
vtime_account_system(tsk);
else
vtime_account_idle(tsk);
}
static cputime_t scale_utime(cputime_t utime, cputime_t rtime, cputime_t total)
{
u64 temp = (__force u64) rtime;
temp *= (__force u64) utime;
if (sizeof(cputime_t) == 4)
temp = div_u64(temp, (__force u32) total);
else
temp = div64_u64(temp, (__force u64) total);
return (__force cputime_t) temp;
}
static void cputime_adjust(struct task_cputime *curr,
struct cputime *prev,
cputime_t *ut, cputime_t *st)
{
cputime_t rtime, utime, total;
utime = curr->utime;
total = utime + curr->stime;
rtime = nsecs_to_cputime(curr->sum_exec_runtime);
if (total)
utime = scale_utime(utime, rtime, total);
else
utime = rtime;
prev->utime = max(prev->utime, utime);
prev->stime = max(prev->stime, rtime - prev->utime);
*ut = prev->utime;
*st = prev->stime;
}
void task_cputime_adjusted(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
struct task_cputime cputime = {
.utime = p->utime,
.stime = p->stime,
.sum_exec_runtime = p->se.sum_exec_runtime,
};
cputime_adjust(&cputime, &p->prev_cputime, ut, st);
}
void thread_group_cputime_adjusted(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
struct task_cputime cputime;
thread_group_cputime(p, &cputime);
cputime_adjust(&cputime, &p->signal->prev_cputime, ut, st);
}
