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
__this_cpu_add(kernel_cpustat.cpustat[index], tmp);
cpuacct_account_field(p, index, tmp);
}
void account_user_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled)
{
int index;
p->utime += cputime;
p->utimescaled += cputime_scaled;
account_group_user_time(p, cputime);
index = (task_nice(p) > 0) ? CPUTIME_NICE : CPUTIME_USER;
task_group_account_field(p, index, (__force u64) cputime);
acct_account_cputime(p);
}
static void account_guest_time(struct task_struct *p, cputime_t cputime,
cputime_t cputime_scaled)
{
u64 *cpustat = kcpustat_this_cpu->cpustat;
p->utime += cputime;
p->utimescaled += cputime_scaled;
account_group_user_time(p, cputime);
p->gtime += cputime;
if (task_nice(p) > 0) {
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
acct_account_cputime(p);
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
u64 steal;
cputime_t steal_ct;
steal = paravirt_steal_clock(smp_processor_id());
steal -= this_rq()->prev_steal_time;
steal_ct = nsecs_to_cputime(steal);
this_rq()->prev_steal_time += cputime_to_nsecs(steal_ct);
account_steal_time(steal_ct);
return steal_ct;
}
#endif
return false;
}
void thread_group_cputime(struct task_struct *tsk, struct task_cputime *times)
{
struct signal_struct *sig = tsk->signal;
cputime_t utime, stime;
struct task_struct *t;
unsigned int seq, nextseq;
unsigned long flags;
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
times->sum_exec_runtime += task_sched_runtime(t);
}
nextseq = 1;
} while (need_seqretry(&sig->stats_lock, seq));
done_seqretry_irqrestore(&sig->stats_lock, seq, flags);
rcu_read_unlock();
}
static void irqtime_account_process_tick(struct task_struct *p, int user_tick,
struct rq *rq, int ticks)
{
cputime_t scaled = cputime_to_scaled(cputime_one_jiffy);
u64 cputime = (__force u64) cputime_one_jiffy;
u64 *cpustat = kcpustat_this_cpu->cpustat;
if (steal_account_process_tick())
return;
cputime *= ticks;
scaled *= ticks;
if (irqtime_account_hi_update()) {
cpustat[CPUTIME_IRQ] += cputime;
} else if (irqtime_account_si_update()) {
cpustat[CPUTIME_SOFTIRQ] += cputime;
} else if (this_cpu_ksoftirqd() == p) {
__account_system_time(p, cputime, scaled, CPUTIME_SOFTIRQ);
} else if (user_tick) {
account_user_time(p, cputime, scaled);
} else if (p == rq->idle) {
account_idle_time(cputime);
} else if (p->flags & PF_VCPU) {
account_guest_time(p, cputime, scaled);
} else {
__account_system_time(p, cputime, scaled, CPUTIME_SYSTEM);
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
#ifdef CONFIG_VIRT_CPU_ACCOUNTING_NATIVE
vtime_account_user(prev);
#endif
arch_vtime_task_switch(prev);
}
void vtime_common_account_irq_enter(struct task_struct *tsk)
{
if (!in_interrupt()) {
if (context_tracking_in_user()) {
vtime_account_user(tsk);
return;
}
if (is_idle_task(tsk)) {
vtime_account_idle(tsk);
return;
}
}
vtime_account_system(tsk);
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
void account_process_tick(struct task_struct *p, int user_tick)
{
cputime_t one_jiffy_scaled = cputime_to_scaled(cputime_one_jiffy);
struct rq *rq = this_rq();
if (vtime_accounting_cpu_enabled())
return;
if (sched_clock_irqtime) {
irqtime_account_process_tick(p, user_tick, rq, 1);
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
static cputime_t scale_stime(u64 stime, u64 rtime, u64 total)
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
return (__force cputime_t) scaled;
}
static void cputime_adjust(struct task_cputime *curr,
struct prev_cputime *prev,
cputime_t *ut, cputime_t *st)
{
cputime_t rtime, stime, utime;
unsigned long flags;
raw_spin_lock_irqsave(&prev->lock, flags);
rtime = nsecs_to_cputime(curr->sum_exec_runtime);
if (prev->stime + prev->utime >= rtime)
goto out;
stime = curr->stime;
utime = curr->utime;
if (utime == 0) {
stime = rtime;
goto update;
}
if (stime == 0) {
utime = rtime;
goto update;
}
stime = scale_stime((__force u64)stime, (__force u64)rtime,
(__force u64)(stime + utime));
if (stime < prev->stime)
stime = prev->stime;
utime = rtime - stime;
if (utime < prev->utime) {
utime = prev->utime;
stime = rtime - utime;
}
update:
prev->stime = stime;
prev->utime = utime;
out:
*ut = prev->utime;
*st = prev->stime;
raw_spin_unlock_irqrestore(&prev->lock, flags);
}
void task_cputime_adjusted(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
struct task_cputime cputime = {
.sum_exec_runtime = p->se.sum_exec_runtime,
};
task_cputime(p, &cputime.utime, &cputime.stime);
cputime_adjust(&cputime, &p->prev_cputime, ut, st);
}
void thread_group_cputime_adjusted(struct task_struct *p, cputime_t *ut, cputime_t *st)
{
struct task_cputime cputime;
thread_group_cputime(p, &cputime);
cputime_adjust(&cputime, &p->signal->prev_cputime, ut, st);
}
static unsigned long long vtime_delta(struct task_struct *tsk)
{
unsigned long long clock;
clock = local_clock();
if (clock < tsk->vtime_snap)
return 0;
return clock - tsk->vtime_snap;
}
static cputime_t get_vtime_delta(struct task_struct *tsk)
{
unsigned long long delta = vtime_delta(tsk);
WARN_ON_ONCE(tsk->vtime_snap_whence == VTIME_INACTIVE);
tsk->vtime_snap += delta;
return nsecs_to_cputime(delta);
}
static void __vtime_account_system(struct task_struct *tsk)
{
cputime_t delta_cpu = get_vtime_delta(tsk);
account_system_time(tsk, irq_count(), delta_cpu, cputime_to_scaled(delta_cpu));
}
void vtime_account_system(struct task_struct *tsk)
{
write_seqcount_begin(&tsk->vtime_seqcount);
__vtime_account_system(tsk);
write_seqcount_end(&tsk->vtime_seqcount);
}
void vtime_gen_account_irq_exit(struct task_struct *tsk)
{
write_seqcount_begin(&tsk->vtime_seqcount);
__vtime_account_system(tsk);
if (context_tracking_in_user())
tsk->vtime_snap_whence = VTIME_USER;
write_seqcount_end(&tsk->vtime_seqcount);
}
void vtime_account_user(struct task_struct *tsk)
{
cputime_t delta_cpu;
write_seqcount_begin(&tsk->vtime_seqcount);
delta_cpu = get_vtime_delta(tsk);
tsk->vtime_snap_whence = VTIME_SYS;
account_user_time(tsk, delta_cpu, cputime_to_scaled(delta_cpu));
write_seqcount_end(&tsk->vtime_seqcount);
}
void vtime_user_enter(struct task_struct *tsk)
{
write_seqcount_begin(&tsk->vtime_seqcount);
__vtime_account_system(tsk);
tsk->vtime_snap_whence = VTIME_USER;
write_seqcount_end(&tsk->vtime_seqcount);
}
void vtime_guest_enter(struct task_struct *tsk)
{
write_seqcount_begin(&tsk->vtime_seqcount);
__vtime_account_system(tsk);
current->flags |= PF_VCPU;
write_seqcount_end(&tsk->vtime_seqcount);
}
void vtime_guest_exit(struct task_struct *tsk)
{
write_seqcount_begin(&tsk->vtime_seqcount);
__vtime_account_system(tsk);
current->flags &= ~PF_VCPU;
write_seqcount_end(&tsk->vtime_seqcount);
}
void vtime_account_idle(struct task_struct *tsk)
{
cputime_t delta_cpu = get_vtime_delta(tsk);
account_idle_time(delta_cpu);
}
void arch_vtime_task_switch(struct task_struct *prev)
{
write_seqcount_begin(&prev->vtime_seqcount);
prev->vtime_snap_whence = VTIME_INACTIVE;
write_seqcount_end(&prev->vtime_seqcount);
write_seqcount_begin(&current->vtime_seqcount);
current->vtime_snap_whence = VTIME_SYS;
current->vtime_snap = sched_clock_cpu(smp_processor_id());
write_seqcount_end(&current->vtime_seqcount);
}
void vtime_init_idle(struct task_struct *t, int cpu)
{
unsigned long flags;
local_irq_save(flags);
write_seqcount_begin(&t->vtime_seqcount);
t->vtime_snap_whence = VTIME_SYS;
t->vtime_snap = sched_clock_cpu(cpu);
write_seqcount_end(&t->vtime_seqcount);
local_irq_restore(flags);
}
cputime_t task_gtime(struct task_struct *t)
{
unsigned int seq;
cputime_t gtime;
if (!vtime_accounting_enabled())
return t->gtime;
do {
seq = read_seqcount_begin(&t->vtime_seqcount);
gtime = t->gtime;
if (t->vtime_snap_whence == VTIME_SYS && t->flags & PF_VCPU)
gtime += vtime_delta(t);
} while (read_seqcount_retry(&t->vtime_seqcount, seq));
return gtime;
}
static void
fetch_task_cputime(struct task_struct *t,
cputime_t *u_dst, cputime_t *s_dst,
cputime_t *u_src, cputime_t *s_src,
cputime_t *udelta, cputime_t *sdelta)
{
unsigned int seq;
unsigned long long delta;
do {
*udelta = 0;
*sdelta = 0;
seq = read_seqcount_begin(&t->vtime_seqcount);
if (u_dst)
*u_dst = *u_src;
if (s_dst)
*s_dst = *s_src;
if (t->vtime_snap_whence == VTIME_INACTIVE ||
is_idle_task(t))
continue;
delta = vtime_delta(t);
if (t->vtime_snap_whence == VTIME_USER || t->flags & PF_VCPU) {
*udelta = delta;
} else {
if (t->vtime_snap_whence == VTIME_SYS)
*sdelta = delta;
}
} while (read_seqcount_retry(&t->vtime_seqcount, seq));
}
void task_cputime(struct task_struct *t, cputime_t *utime, cputime_t *stime)
{
cputime_t udelta, sdelta;
if (!vtime_accounting_enabled()) {
if (utime)
*utime = t->utime;
if (stime)
*stime = t->stime;
return;
}
fetch_task_cputime(t, utime, stime, &t->utime,
&t->stime, &udelta, &sdelta);
if (utime)
*utime += udelta;
if (stime)
*stime += sdelta;
}
void task_cputime_scaled(struct task_struct *t,
cputime_t *utimescaled, cputime_t *stimescaled)
{
cputime_t udelta, sdelta;
if (!vtime_accounting_enabled()) {
if (utimescaled)
*utimescaled = t->utimescaled;
if (stimescaled)
*stimescaled = t->stimescaled;
return;
}
fetch_task_cputime(t, utimescaled, stimescaled,
&t->utimescaled, &t->stimescaled, &udelta, &sdelta);
if (utimescaled)
*utimescaled += cputime_to_scaled(udelta);
if (stimescaled)
*stimescaled += cputime_to_scaled(sdelta);
}
