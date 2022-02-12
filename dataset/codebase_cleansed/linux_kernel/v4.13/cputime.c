void enable_sched_clock_irqtime(void)
{
sched_clock_irqtime = 1;
}
void disable_sched_clock_irqtime(void)
{
sched_clock_irqtime = 0;
}
static void irqtime_account_delta(struct irqtime *irqtime, u64 delta,
enum cpu_usage_stat idx)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
u64_stats_update_begin(&irqtime->sync);
cpustat[idx] += delta;
irqtime->total += delta;
irqtime->tick_delta += delta;
u64_stats_update_end(&irqtime->sync);
}
void irqtime_account_irq(struct task_struct *curr)
{
struct irqtime *irqtime = this_cpu_ptr(&cpu_irqtime);
s64 delta;
int cpu;
if (!sched_clock_irqtime)
return;
cpu = smp_processor_id();
delta = sched_clock_cpu(cpu) - irqtime->irq_start_time;
irqtime->irq_start_time += delta;
if (hardirq_count())
irqtime_account_delta(irqtime, delta, CPUTIME_IRQ);
else if (in_serving_softirq() && curr != this_cpu_ksoftirqd())
irqtime_account_delta(irqtime, delta, CPUTIME_SOFTIRQ);
}
static u64 irqtime_tick_accounted(u64 maxtime)
{
struct irqtime *irqtime = this_cpu_ptr(&cpu_irqtime);
u64 delta;
delta = min(irqtime->tick_delta, maxtime);
irqtime->tick_delta -= delta;
return delta;
}
static u64 irqtime_tick_accounted(u64 dummy)
{
return 0;
}
static inline void task_group_account_field(struct task_struct *p, int index,
u64 tmp)
{
__this_cpu_add(kernel_cpustat.cpustat[index], tmp);
cpuacct_account_field(p, index, tmp);
}
void account_user_time(struct task_struct *p, u64 cputime)
{
int index;
p->utime += cputime;
account_group_user_time(p, cputime);
index = (task_nice(p) > 0) ? CPUTIME_NICE : CPUTIME_USER;
task_group_account_field(p, index, cputime);
acct_account_cputime(p);
}
void account_guest_time(struct task_struct *p, u64 cputime)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
p->utime += cputime;
account_group_user_time(p, cputime);
p->gtime += cputime;
if (task_nice(p) > 0) {
cpustat[CPUTIME_NICE] += cputime;
cpustat[CPUTIME_GUEST_NICE] += cputime;
} else {
cpustat[CPUTIME_USER] += cputime;
cpustat[CPUTIME_GUEST] += cputime;
}
}
void account_system_index_time(struct task_struct *p,
u64 cputime, enum cpu_usage_stat index)
{
p->stime += cputime;
account_group_system_time(p, cputime);
task_group_account_field(p, index, cputime);
acct_account_cputime(p);
}
void account_system_time(struct task_struct *p, int hardirq_offset, u64 cputime)
{
int index;
if ((p->flags & PF_VCPU) && (irq_count() - hardirq_offset == 0)) {
account_guest_time(p, cputime);
return;
}
if (hardirq_count() - hardirq_offset)
index = CPUTIME_IRQ;
else if (in_serving_softirq())
index = CPUTIME_SOFTIRQ;
else
index = CPUTIME_SYSTEM;
account_system_index_time(p, cputime, index);
}
void account_steal_time(u64 cputime)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
cpustat[CPUTIME_STEAL] += cputime;
}
void account_idle_time(u64 cputime)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
struct rq *rq = this_rq();
if (atomic_read(&rq->nr_iowait) > 0)
cpustat[CPUTIME_IOWAIT] += cputime;
else
cpustat[CPUTIME_IDLE] += cputime;
}
static __always_inline u64 steal_account_process_time(u64 maxtime)
{
#ifdef CONFIG_PARAVIRT
if (static_key_false(&paravirt_steal_enabled)) {
u64 steal;
steal = paravirt_steal_clock(smp_processor_id());
steal -= this_rq()->prev_steal_time;
steal = min(steal, maxtime);
account_steal_time(steal);
this_rq()->prev_steal_time += steal;
return steal;
}
#endif
return 0;
}
static inline u64 account_other_time(u64 max)
{
u64 accounted;
WARN_ON_ONCE(!irqs_disabled());
accounted = steal_account_process_time(max);
if (accounted < max)
accounted += irqtime_tick_accounted(max - accounted);
return accounted;
}
static inline u64 read_sum_exec_runtime(struct task_struct *t)
{
return t->se.sum_exec_runtime;
}
static u64 read_sum_exec_runtime(struct task_struct *t)
{
u64 ns;
struct rq_flags rf;
struct rq *rq;
rq = task_rq_lock(t, &rf);
ns = t->se.sum_exec_runtime;
task_rq_unlock(rq, t, &rf);
return ns;
}
void thread_group_cputime(struct task_struct *tsk, struct task_cputime *times)
{
struct signal_struct *sig = tsk->signal;
u64 utime, stime;
struct task_struct *t;
unsigned int seq, nextseq;
unsigned long flags;
if (same_thread_group(current, tsk))
(void) task_sched_runtime(current);
rcu_read_lock();
nextseq = 0;
do {
seq = nextseq;
flags = read_seqbegin_or_lock_irqsave(&sig->stats_lock, &seq);
times->utime = sig->utime;
times->stime = sig->stime;
times->sum_exec_runtime = sig->sum_sched_runtime;
for_each_thread(tsk, t) {
task_cputime(t, &utime, &stime);
times->utime += utime;
times->stime += stime;
times->sum_exec_runtime += read_sum_exec_runtime(t);
}
nextseq = 1;
} while (need_seqretry(&sig->stats_lock, seq));
done_seqretry_irqrestore(&sig->stats_lock, seq, flags);
rcu_read_unlock();
}
static void irqtime_account_process_tick(struct task_struct *p, int user_tick,
struct rq *rq, int ticks)
{
u64 other, cputime = TICK_NSEC * ticks;
other = account_other_time(ULONG_MAX);
if (other >= cputime)
return;
cputime -= other;
if (this_cpu_ksoftirqd() == p) {
account_system_index_time(p, cputime, CPUTIME_SOFTIRQ);
} else if (user_tick) {
account_user_time(p, cputime);
} else if (p == rq->idle) {
account_idle_time(cputime);
} else if (p->flags & PF_VCPU) {
account_guest_time(p, cputime);
} else {
account_system_index_time(p, cputime, CPUTIME_SYSTEM);
}
}
static void irqtime_account_idle_ticks(int ticks)
{
struct rq *rq = this_rq();
irqtime_account_process_tick(current, 0, rq, ticks);
}
static inline void irqtime_account_idle_ticks(int ticks) {}
static inline void irqtime_account_process_tick(struct task_struct *p, int user_tick,
struct rq *rq, int nr_ticks) {}
void vtime_common_task_switch(struct task_struct *prev)
{
if (is_idle_task(prev))
vtime_account_idle(prev);
else
vtime_account_system(prev);
vtime_flush(prev);
arch_vtime_task_switch(prev);
}
void vtime_account_irq_enter(struct task_struct *tsk)
{
if (!in_interrupt() && is_idle_task(tsk))
vtime_account_idle(tsk);
else
vtime_account_system(tsk);
}
void task_cputime_adjusted(struct task_struct *p, u64 *ut, u64 *st)
{
*ut = p->utime;
*st = p->stime;
}
void thread_group_cputime_adjusted(struct task_struct *p, u64 *ut, u64 *st)
{
struct task_cputime cputime;
thread_group_cputime(p, &cputime);
*ut = cputime.utime;
*st = cputime.stime;
}
void account_process_tick(struct task_struct *p, int user_tick)
{
u64 cputime, steal;
struct rq *rq = this_rq();
if (vtime_accounting_cpu_enabled())
return;
if (sched_clock_irqtime) {
irqtime_account_process_tick(p, user_tick, rq, 1);
return;
}
cputime = TICK_NSEC;
steal = steal_account_process_time(ULONG_MAX);
if (steal >= cputime)
return;
cputime -= steal;
if (user_tick)
account_user_time(p, cputime);
else if ((p != rq->idle) || (irq_count() != HARDIRQ_OFFSET))
account_system_time(p, HARDIRQ_OFFSET, cputime);
else
account_idle_time(cputime);
}
void account_idle_ticks(unsigned long ticks)
{
u64 cputime, steal;
if (sched_clock_irqtime) {
irqtime_account_idle_ticks(ticks);
return;
}
cputime = ticks * TICK_NSEC;
steal = steal_account_process_time(ULONG_MAX);
if (steal >= cputime)
return;
cputime -= steal;
account_idle_time(cputime);
}
static u64 scale_stime(u64 stime, u64 rtime, u64 total)
{
u64 scaled;
for (;;) {
if (stime > rtime)
swap(rtime, stime);
if (total >> 32)
goto drop_precision;
if (!(rtime >> 32))
break;
if (stime >> 31)
goto drop_precision;
stime <<= 1;
rtime >>= 1;
continue;
drop_precision:
rtime >>= 1;
total >>= 1;
}
scaled = div_u64((u64) (u32) stime * (u64) (u32) rtime, (u32)total);
return scaled;
}
static void cputime_adjust(struct task_cputime *curr,
struct prev_cputime *prev,
u64 *ut, u64 *st)
{
u64 rtime, stime, utime;
unsigned long flags;
raw_spin_lock_irqsave(&prev->lock, flags);
rtime = curr->sum_exec_runtime;
if (prev->stime + prev->utime >= rtime)
goto out;
stime = curr->stime;
utime = curr->utime;
if (stime == 0) {
utime = rtime;
goto update;
}
if (utime == 0) {
stime = rtime;
goto update;
}
stime = scale_stime(stime, rtime, stime + utime);
update:
if (stime < prev->stime)
stime = prev->stime;
utime = rtime - stime;
if (utime < prev->utime) {
utime = prev->utime;
stime = rtime - utime;
}
prev->stime = stime;
prev->utime = utime;
out:
*ut = prev->utime;
*st = prev->stime;
raw_spin_unlock_irqrestore(&prev->lock, flags);
}
void task_cputime_adjusted(struct task_struct *p, u64 *ut, u64 *st)
{
struct task_cputime cputime = {
.sum_exec_runtime = p->se.sum_exec_runtime,
};
task_cputime(p, &cputime.utime, &cputime.stime);
cputime_adjust(&cputime, &p->prev_cputime, ut, st);
}
void thread_group_cputime_adjusted(struct task_struct *p, u64 *ut, u64 *st)
{
struct task_cputime cputime;
thread_group_cputime(p, &cputime);
cputime_adjust(&cputime, &p->signal->prev_cputime, ut, st);
}
static u64 vtime_delta(struct vtime *vtime)
{
unsigned long long clock;
clock = sched_clock();
if (clock < vtime->starttime)
return 0;
return clock - vtime->starttime;
}
static u64 get_vtime_delta(struct vtime *vtime)
{
u64 delta = vtime_delta(vtime);
u64 other;
other = account_other_time(delta);
WARN_ON_ONCE(vtime->state == VTIME_INACTIVE);
vtime->starttime += delta;
return delta - other;
}
static void __vtime_account_system(struct task_struct *tsk,
struct vtime *vtime)
{
vtime->stime += get_vtime_delta(vtime);
if (vtime->stime >= TICK_NSEC) {
account_system_time(tsk, irq_count(), vtime->stime);
vtime->stime = 0;
}
}
static void vtime_account_guest(struct task_struct *tsk,
struct vtime *vtime)
{
vtime->gtime += get_vtime_delta(vtime);
if (vtime->gtime >= TICK_NSEC) {
account_guest_time(tsk, vtime->gtime);
vtime->gtime = 0;
}
}
void vtime_account_system(struct task_struct *tsk)
{
struct vtime *vtime = &tsk->vtime;
if (!vtime_delta(vtime))
return;
write_seqcount_begin(&vtime->seqcount);
if (current->flags & PF_VCPU)
vtime_account_guest(tsk, vtime);
else
__vtime_account_system(tsk, vtime);
write_seqcount_end(&vtime->seqcount);
}
void vtime_user_enter(struct task_struct *tsk)
{
struct vtime *vtime = &tsk->vtime;
write_seqcount_begin(&vtime->seqcount);
__vtime_account_system(tsk, vtime);
vtime->state = VTIME_USER;
write_seqcount_end(&vtime->seqcount);
}
void vtime_user_exit(struct task_struct *tsk)
{
struct vtime *vtime = &tsk->vtime;
write_seqcount_begin(&vtime->seqcount);
vtime->utime += get_vtime_delta(vtime);
if (vtime->utime >= TICK_NSEC) {
account_user_time(tsk, vtime->utime);
vtime->utime = 0;
}
vtime->state = VTIME_SYS;
write_seqcount_end(&vtime->seqcount);
}
void vtime_guest_enter(struct task_struct *tsk)
{
struct vtime *vtime = &tsk->vtime;
write_seqcount_begin(&vtime->seqcount);
__vtime_account_system(tsk, vtime);
current->flags |= PF_VCPU;
write_seqcount_end(&vtime->seqcount);
}
void vtime_guest_exit(struct task_struct *tsk)
{
struct vtime *vtime = &tsk->vtime;
write_seqcount_begin(&vtime->seqcount);
vtime_account_guest(tsk, vtime);
current->flags &= ~PF_VCPU;
write_seqcount_end(&vtime->seqcount);
}
void vtime_account_idle(struct task_struct *tsk)
{
account_idle_time(get_vtime_delta(&tsk->vtime));
}
void arch_vtime_task_switch(struct task_struct *prev)
{
struct vtime *vtime = &prev->vtime;
write_seqcount_begin(&vtime->seqcount);
vtime->state = VTIME_INACTIVE;
write_seqcount_end(&vtime->seqcount);
vtime = &current->vtime;
write_seqcount_begin(&vtime->seqcount);
vtime->state = VTIME_SYS;
vtime->starttime = sched_clock();
write_seqcount_end(&vtime->seqcount);
}
void vtime_init_idle(struct task_struct *t, int cpu)
{
struct vtime *vtime = &t->vtime;
unsigned long flags;
local_irq_save(flags);
write_seqcount_begin(&vtime->seqcount);
vtime->state = VTIME_SYS;
vtime->starttime = sched_clock();
write_seqcount_end(&vtime->seqcount);
local_irq_restore(flags);
}
u64 task_gtime(struct task_struct *t)
{
struct vtime *vtime = &t->vtime;
unsigned int seq;
u64 gtime;
if (!vtime_accounting_enabled())
return t->gtime;
do {
seq = read_seqcount_begin(&vtime->seqcount);
gtime = t->gtime;
if (vtime->state == VTIME_SYS && t->flags & PF_VCPU)
gtime += vtime->gtime + vtime_delta(vtime);
} while (read_seqcount_retry(&vtime->seqcount, seq));
return gtime;
}
void task_cputime(struct task_struct *t, u64 *utime, u64 *stime)
{
struct vtime *vtime = &t->vtime;
unsigned int seq;
u64 delta;
if (!vtime_accounting_enabled()) {
*utime = t->utime;
*stime = t->stime;
return;
}
do {
seq = read_seqcount_begin(&vtime->seqcount);
*utime = t->utime;
*stime = t->stime;
if (vtime->state == VTIME_INACTIVE || is_idle_task(t))
continue;
delta = vtime_delta(vtime);
if (vtime->state == VTIME_USER || t->flags & PF_VCPU)
*utime += vtime->utime + delta;
else if (vtime->state == VTIME_SYS)
*stime += vtime->stime + delta;
} while (read_seqcount_retry(&vtime->seqcount, seq));
}
