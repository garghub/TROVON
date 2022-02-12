static int rcu_gp_in_progress(struct rcu_state *rsp)
{
return ACCESS_ONCE(rsp->completed) != ACCESS_ONCE(rsp->gpnum);
}
void rcu_sched_qs(int cpu)
{
struct rcu_data *rdp = &per_cpu(rcu_sched_data, cpu);
rdp->passed_quiesce_gpnum = rdp->gpnum;
barrier();
if (rdp->passed_quiesce == 0)
trace_rcu_grace_period("rcu_sched", rdp->gpnum, "cpuqs");
rdp->passed_quiesce = 1;
}
void rcu_bh_qs(int cpu)
{
struct rcu_data *rdp = &per_cpu(rcu_bh_data, cpu);
rdp->passed_quiesce_gpnum = rdp->gpnum;
barrier();
if (rdp->passed_quiesce == 0)
trace_rcu_grace_period("rcu_bh", rdp->gpnum, "cpuqs");
rdp->passed_quiesce = 1;
}
void rcu_note_context_switch(int cpu)
{
trace_rcu_utilization("Start context switch");
rcu_sched_qs(cpu);
rcu_preempt_note_context_switch(cpu);
trace_rcu_utilization("End context switch");
}
long rcu_batches_completed_sched(void)
{
return rcu_sched_state.completed;
}
long rcu_batches_completed_bh(void)
{
return rcu_bh_state.completed;
}
void rcu_bh_force_quiescent_state(void)
{
force_quiescent_state(&rcu_bh_state, 0);
}
void rcutorture_record_test_transition(void)
{
rcutorture_testseq++;
rcutorture_vernum = 0;
}
void rcutorture_record_progress(unsigned long vernum)
{
rcutorture_vernum++;
}
void rcu_sched_force_quiescent_state(void)
{
force_quiescent_state(&rcu_sched_state, 0);
}
static int
cpu_has_callbacks_ready_to_invoke(struct rcu_data *rdp)
{
return &rdp->nxtlist != rdp->nxttail[RCU_DONE_TAIL];
}
static int
cpu_needs_another_gp(struct rcu_state *rsp, struct rcu_data *rdp)
{
return *rdp->nxttail[RCU_DONE_TAIL] && !rcu_gp_in_progress(rsp);
}
static struct rcu_node *rcu_get_root(struct rcu_state *rsp)
{
return &rsp->node[0];
}
static int rcu_implicit_offline_qs(struct rcu_data *rdp)
{
if (cpu_is_offline(rdp->cpu) &&
ULONG_CMP_LT(rdp->rsp->gp_start + 2, jiffies)) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, "ofl");
rdp->offline_fqs++;
return 1;
}
return 0;
}
static void rcu_idle_enter_common(struct rcu_dynticks *rdtp, long long oldval)
{
trace_rcu_dyntick("Start", oldval, 0);
if (!is_idle_task(current)) {
struct task_struct *idle = idle_task(smp_processor_id());
trace_rcu_dyntick("Error on entry: not idle task", oldval, 0);
ftrace_dump(DUMP_ORIG);
WARN_ONCE(1, "Current pid: %d comm: %s / Idle pid: %d comm: %s",
current->pid, current->comm,
idle->pid, idle->comm);
}
rcu_prepare_for_idle(smp_processor_id());
smp_mb__before_atomic_inc();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic_inc();
WARN_ON_ONCE(atomic_read(&rdtp->dynticks) & 0x1);
rcu_lockdep_assert(!lock_is_held(&rcu_lock_map),
"Illegal idle entry in RCU read-side critical section.");
rcu_lockdep_assert(!lock_is_held(&rcu_bh_lock_map),
"Illegal idle entry in RCU-bh read-side critical section.");
rcu_lockdep_assert(!lock_is_held(&rcu_sched_lock_map),
"Illegal idle entry in RCU-sched read-side critical section.");
}
void rcu_idle_enter(void)
{
unsigned long flags;
long long oldval;
struct rcu_dynticks *rdtp;
local_irq_save(flags);
rdtp = &__get_cpu_var(rcu_dynticks);
oldval = rdtp->dynticks_nesting;
WARN_ON_ONCE((oldval & DYNTICK_TASK_NEST_MASK) == 0);
if ((oldval & DYNTICK_TASK_NEST_MASK) == DYNTICK_TASK_NEST_VALUE)
rdtp->dynticks_nesting = 0;
else
rdtp->dynticks_nesting -= DYNTICK_TASK_NEST_VALUE;
rcu_idle_enter_common(rdtp, oldval);
local_irq_restore(flags);
}
void rcu_irq_exit(void)
{
unsigned long flags;
long long oldval;
struct rcu_dynticks *rdtp;
local_irq_save(flags);
rdtp = &__get_cpu_var(rcu_dynticks);
oldval = rdtp->dynticks_nesting;
rdtp->dynticks_nesting--;
WARN_ON_ONCE(rdtp->dynticks_nesting < 0);
if (rdtp->dynticks_nesting)
trace_rcu_dyntick("--=", oldval, rdtp->dynticks_nesting);
else
rcu_idle_enter_common(rdtp, oldval);
local_irq_restore(flags);
}
static void rcu_idle_exit_common(struct rcu_dynticks *rdtp, long long oldval)
{
smp_mb__before_atomic_inc();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic_inc();
WARN_ON_ONCE(!(atomic_read(&rdtp->dynticks) & 0x1));
rcu_cleanup_after_idle(smp_processor_id());
trace_rcu_dyntick("End", oldval, rdtp->dynticks_nesting);
if (!is_idle_task(current)) {
struct task_struct *idle = idle_task(smp_processor_id());
trace_rcu_dyntick("Error on exit: not idle task",
oldval, rdtp->dynticks_nesting);
ftrace_dump(DUMP_ORIG);
WARN_ONCE(1, "Current pid: %d comm: %s / Idle pid: %d comm: %s",
current->pid, current->comm,
idle->pid, idle->comm);
}
}
void rcu_idle_exit(void)
{
unsigned long flags;
struct rcu_dynticks *rdtp;
long long oldval;
local_irq_save(flags);
rdtp = &__get_cpu_var(rcu_dynticks);
oldval = rdtp->dynticks_nesting;
WARN_ON_ONCE(oldval < 0);
if (oldval & DYNTICK_TASK_NEST_MASK)
rdtp->dynticks_nesting += DYNTICK_TASK_NEST_VALUE;
else
rdtp->dynticks_nesting = DYNTICK_TASK_EXIT_IDLE;
rcu_idle_exit_common(rdtp, oldval);
local_irq_restore(flags);
}
void rcu_irq_enter(void)
{
unsigned long flags;
struct rcu_dynticks *rdtp;
long long oldval;
local_irq_save(flags);
rdtp = &__get_cpu_var(rcu_dynticks);
oldval = rdtp->dynticks_nesting;
rdtp->dynticks_nesting++;
WARN_ON_ONCE(rdtp->dynticks_nesting == 0);
if (oldval)
trace_rcu_dyntick("++=", oldval, rdtp->dynticks_nesting);
else
rcu_idle_exit_common(rdtp, oldval);
local_irq_restore(flags);
}
void rcu_nmi_enter(void)
{
struct rcu_dynticks *rdtp = &__get_cpu_var(rcu_dynticks);
if (rdtp->dynticks_nmi_nesting == 0 &&
(atomic_read(&rdtp->dynticks) & 0x1))
return;
rdtp->dynticks_nmi_nesting++;
smp_mb__before_atomic_inc();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic_inc();
WARN_ON_ONCE(!(atomic_read(&rdtp->dynticks) & 0x1));
}
void rcu_nmi_exit(void)
{
struct rcu_dynticks *rdtp = &__get_cpu_var(rcu_dynticks);
if (rdtp->dynticks_nmi_nesting == 0 ||
--rdtp->dynticks_nmi_nesting != 0)
return;
smp_mb__before_atomic_inc();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic_inc();
WARN_ON_ONCE(atomic_read(&rdtp->dynticks) & 0x1);
}
int rcu_is_cpu_idle(void)
{
int ret;
preempt_disable();
ret = (atomic_read(&__get_cpu_var(rcu_dynticks).dynticks) & 0x1) == 0;
preempt_enable();
return ret;
}
bool rcu_lockdep_current_cpu_online(void)
{
struct rcu_data *rdp;
struct rcu_node *rnp;
bool ret;
if (in_nmi())
return 1;
preempt_disable();
rdp = &__get_cpu_var(rcu_sched_data);
rnp = rdp->mynode;
ret = (rdp->grpmask & rnp->qsmaskinit) ||
!rcu_scheduler_fully_active;
preempt_enable();
return ret;
}
int rcu_is_cpu_rrupt_from_idle(void)
{
return __get_cpu_var(rcu_dynticks).dynticks_nesting <= 1;
}
static int dyntick_save_progress_counter(struct rcu_data *rdp)
{
rdp->dynticks_snap = atomic_add_return(0, &rdp->dynticks->dynticks);
return (rdp->dynticks_snap & 0x1) == 0;
}
static int rcu_implicit_dynticks_qs(struct rcu_data *rdp)
{
unsigned int curr;
unsigned int snap;
curr = (unsigned int)atomic_add_return(0, &rdp->dynticks->dynticks);
snap = (unsigned int)rdp->dynticks_snap;
if ((curr & 0x1) == 0 || UINT_CMP_GE(curr, snap + 2)) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, "dti");
rdp->dynticks_fqs++;
return 1;
}
return rcu_implicit_offline_qs(rdp);
}
static int jiffies_till_stall_check(void)
{
int till_stall_check = ACCESS_ONCE(rcu_cpu_stall_timeout);
if (till_stall_check < 3) {
ACCESS_ONCE(rcu_cpu_stall_timeout) = 3;
till_stall_check = 3;
} else if (till_stall_check > 300) {
ACCESS_ONCE(rcu_cpu_stall_timeout) = 300;
till_stall_check = 300;
}
return till_stall_check * HZ + RCU_STALL_DELAY_DELTA;
}
static void record_gp_stall_check_time(struct rcu_state *rsp)
{
rsp->gp_start = jiffies;
rsp->jiffies_stall = jiffies + jiffies_till_stall_check();
}
static void print_other_cpu_stall(struct rcu_state *rsp)
{
int cpu;
long delta;
unsigned long flags;
int ndetected = 0;
struct rcu_node *rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave(&rnp->lock, flags);
delta = jiffies - rsp->jiffies_stall;
if (delta < RCU_STALL_RAT_DELAY || !rcu_gp_in_progress(rsp)) {
raw_spin_unlock_irqrestore(&rnp->lock, flags);
return;
}
rsp->jiffies_stall = jiffies + 3 * jiffies_till_stall_check() + 3;
raw_spin_unlock_irqrestore(&rnp->lock, flags);
printk(KERN_ERR "INFO: %s detected stalls on CPUs/tasks:",
rsp->name);
print_cpu_stall_info_begin();
rcu_for_each_leaf_node(rsp, rnp) {
raw_spin_lock_irqsave(&rnp->lock, flags);
ndetected += rcu_print_task_stall(rnp);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
if (rnp->qsmask == 0)
continue;
for (cpu = 0; cpu <= rnp->grphi - rnp->grplo; cpu++)
if (rnp->qsmask & (1UL << cpu)) {
print_cpu_stall_info(rsp, rnp->grplo + cpu);
ndetected++;
}
}
rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave(&rnp->lock, flags);
ndetected += rcu_print_task_stall(rnp);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
print_cpu_stall_info_end();
printk(KERN_CONT "(detected by %d, t=%ld jiffies)\n",
smp_processor_id(), (long)(jiffies - rsp->gp_start));
if (ndetected == 0)
printk(KERN_ERR "INFO: Stall ended before state dump start\n");
else if (!trigger_all_cpu_backtrace())
dump_stack();
rcu_print_detail_task_stall(rsp);
force_quiescent_state(rsp, 0);
}
static void print_cpu_stall(struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_node *rnp = rcu_get_root(rsp);
printk(KERN_ERR "INFO: %s self-detected stall on CPU", rsp->name);
print_cpu_stall_info_begin();
print_cpu_stall_info(rsp, smp_processor_id());
print_cpu_stall_info_end();
printk(KERN_CONT " (t=%lu jiffies)\n", jiffies - rsp->gp_start);
if (!trigger_all_cpu_backtrace())
dump_stack();
raw_spin_lock_irqsave(&rnp->lock, flags);
if (ULONG_CMP_GE(jiffies, rsp->jiffies_stall))
rsp->jiffies_stall = jiffies +
3 * jiffies_till_stall_check() + 3;
raw_spin_unlock_irqrestore(&rnp->lock, flags);
set_need_resched();
}
static void check_cpu_stall(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long j;
unsigned long js;
struct rcu_node *rnp;
if (rcu_cpu_stall_suppress)
return;
j = ACCESS_ONCE(jiffies);
js = ACCESS_ONCE(rsp->jiffies_stall);
rnp = rdp->mynode;
if ((ACCESS_ONCE(rnp->qsmask) & rdp->grpmask) && ULONG_CMP_GE(j, js)) {
print_cpu_stall(rsp);
} else if (rcu_gp_in_progress(rsp) &&
ULONG_CMP_GE(j, js + RCU_STALL_RAT_DELAY)) {
print_other_cpu_stall(rsp);
}
}
static int rcu_panic(struct notifier_block *this, unsigned long ev, void *ptr)
{
rcu_cpu_stall_suppress = 1;
return NOTIFY_DONE;
}
void rcu_cpu_stall_reset(void)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
rsp->jiffies_stall = jiffies + ULONG_MAX / 2;
}
static void __init check_cpu_stall_init(void)
{
atomic_notifier_chain_register(&panic_notifier_list, &rcu_panic_block);
}
static void __note_new_gpnum(struct rcu_state *rsp, struct rcu_node *rnp, struct rcu_data *rdp)
{
if (rdp->gpnum != rnp->gpnum) {
rdp->gpnum = rnp->gpnum;
trace_rcu_grace_period(rsp->name, rdp->gpnum, "cpustart");
if (rnp->qsmask & rdp->grpmask) {
rdp->qs_pending = 1;
rdp->passed_quiesce = 0;
} else {
rdp->qs_pending = 0;
}
zero_cpu_stall_ticks(rdp);
}
}
static void note_new_gpnum(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
struct rcu_node *rnp;
local_irq_save(flags);
rnp = rdp->mynode;
if (rdp->gpnum == ACCESS_ONCE(rnp->gpnum) ||
!raw_spin_trylock(&rnp->lock)) {
local_irq_restore(flags);
return;
}
__note_new_gpnum(rsp, rnp, rdp);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
static int
check_for_new_grace_period(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
int ret = 0;
local_irq_save(flags);
if (rdp->gpnum != rsp->gpnum) {
note_new_gpnum(rsp, rdp);
ret = 1;
}
local_irq_restore(flags);
return ret;
}
static void init_callback_list(struct rcu_data *rdp)
{
int i;
rdp->nxtlist = NULL;
for (i = 0; i < RCU_NEXT_SIZE; i++)
rdp->nxttail[i] = &rdp->nxtlist;
}
static void
__rcu_process_gp_end(struct rcu_state *rsp, struct rcu_node *rnp, struct rcu_data *rdp)
{
if (rdp->completed != rnp->completed) {
rdp->nxttail[RCU_DONE_TAIL] = rdp->nxttail[RCU_WAIT_TAIL];
rdp->nxttail[RCU_WAIT_TAIL] = rdp->nxttail[RCU_NEXT_READY_TAIL];
rdp->nxttail[RCU_NEXT_READY_TAIL] = rdp->nxttail[RCU_NEXT_TAIL];
rdp->completed = rnp->completed;
trace_rcu_grace_period(rsp->name, rdp->gpnum, "cpuend");
if (ULONG_CMP_LT(rdp->gpnum, rdp->completed))
rdp->gpnum = rdp->completed;
if ((rnp->qsmask & rdp->grpmask) == 0)
rdp->qs_pending = 0;
}
}
static void
rcu_process_gp_end(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
struct rcu_node *rnp;
local_irq_save(flags);
rnp = rdp->mynode;
if (rdp->completed == ACCESS_ONCE(rnp->completed) ||
!raw_spin_trylock(&rnp->lock)) {
local_irq_restore(flags);
return;
}
__rcu_process_gp_end(rsp, rnp, rdp);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
static void
rcu_start_gp_per_cpu(struct rcu_state *rsp, struct rcu_node *rnp, struct rcu_data *rdp)
{
__rcu_process_gp_end(rsp, rnp, rdp);
rdp->nxttail[RCU_NEXT_READY_TAIL] = rdp->nxttail[RCU_NEXT_TAIL];
rdp->nxttail[RCU_WAIT_TAIL] = rdp->nxttail[RCU_NEXT_TAIL];
__note_new_gpnum(rsp, rnp, rdp);
}
static void
rcu_start_gp(struct rcu_state *rsp, unsigned long flags)
__releases(rcu_get_root(rsp)->lock
static void rcu_report_qs_rsp(struct rcu_state *rsp, unsigned long flags)
__releases(rcu_get_root(rsp)->lock
static void
rcu_report_qs_rnp(unsigned long mask, struct rcu_state *rsp,
struct rcu_node *rnp, unsigned long flags)
__releases(rnp->lock)
{
struct rcu_node *rnp_c;
for (;;) {
if (!(rnp->qsmask & mask)) {
raw_spin_unlock_irqrestore(&rnp->lock, flags);
return;
}
rnp->qsmask &= ~mask;
trace_rcu_quiescent_state_report(rsp->name, rnp->gpnum,
mask, rnp->qsmask, rnp->level,
rnp->grplo, rnp->grphi,
!!rnp->gp_tasks);
if (rnp->qsmask != 0 || rcu_preempt_blocked_readers_cgp(rnp)) {
raw_spin_unlock_irqrestore(&rnp->lock, flags);
return;
}
mask = rnp->grpmask;
if (rnp->parent == NULL) {
break;
}
raw_spin_unlock_irqrestore(&rnp->lock, flags);
rnp_c = rnp;
rnp = rnp->parent;
raw_spin_lock_irqsave(&rnp->lock, flags);
WARN_ON_ONCE(rnp_c->qsmask);
}
rcu_report_qs_rsp(rsp, flags);
}
static void
rcu_report_qs_rdp(int cpu, struct rcu_state *rsp, struct rcu_data *rdp, long lastgp)
{
unsigned long flags;
unsigned long mask;
struct rcu_node *rnp;
rnp = rdp->mynode;
raw_spin_lock_irqsave(&rnp->lock, flags);
if (lastgp != rnp->gpnum || rnp->completed == rnp->gpnum) {
rdp->passed_quiesce = 0;
raw_spin_unlock_irqrestore(&rnp->lock, flags);
return;
}
mask = rdp->grpmask;
if ((rnp->qsmask & mask) == 0) {
raw_spin_unlock_irqrestore(&rnp->lock, flags);
} else {
rdp->qs_pending = 0;
rdp->nxttail[RCU_NEXT_READY_TAIL] = rdp->nxttail[RCU_NEXT_TAIL];
rcu_report_qs_rnp(mask, rsp, rnp, flags);
}
}
static void
rcu_check_quiescent_state(struct rcu_state *rsp, struct rcu_data *rdp)
{
if (check_for_new_grace_period(rsp, rdp))
return;
if (!rdp->qs_pending)
return;
if (!rdp->passed_quiesce)
return;
rcu_report_qs_rdp(rdp->cpu, rsp, rdp, rdp->passed_quiesce_gpnum);
}
static void
rcu_send_cbs_to_orphanage(int cpu, struct rcu_state *rsp,
struct rcu_node *rnp, struct rcu_data *rdp)
{
if (rdp->nxtlist != NULL) {
rsp->qlen_lazy += rdp->qlen_lazy;
rsp->qlen += rdp->qlen;
rdp->n_cbs_orphaned += rdp->qlen;
rdp->qlen_lazy = 0;
ACCESS_ONCE(rdp->qlen) = 0;
}
if (*rdp->nxttail[RCU_DONE_TAIL] != NULL) {
*rsp->orphan_nxttail = *rdp->nxttail[RCU_DONE_TAIL];
rsp->orphan_nxttail = rdp->nxttail[RCU_NEXT_TAIL];
*rdp->nxttail[RCU_DONE_TAIL] = NULL;
}
if (rdp->nxtlist != NULL) {
*rsp->orphan_donetail = rdp->nxtlist;
rsp->orphan_donetail = rdp->nxttail[RCU_DONE_TAIL];
}
init_callback_list(rdp);
}
static void rcu_adopt_orphan_cbs(struct rcu_state *rsp)
{
int i;
struct rcu_data *rdp = __this_cpu_ptr(rsp->rda);
if (rsp->rcu_barrier_in_progress &&
rsp->rcu_barrier_in_progress != current)
return;
rdp->qlen_lazy += rsp->qlen_lazy;
rdp->qlen += rsp->qlen;
rdp->n_cbs_adopted += rsp->qlen;
if (rsp->qlen_lazy != rsp->qlen)
rcu_idle_count_callbacks_posted();
rsp->qlen_lazy = 0;
rsp->qlen = 0;
if (rsp->orphan_donelist != NULL) {
*rsp->orphan_donetail = *rdp->nxttail[RCU_DONE_TAIL];
*rdp->nxttail[RCU_DONE_TAIL] = rsp->orphan_donelist;
for (i = RCU_NEXT_SIZE - 1; i >= RCU_DONE_TAIL; i--)
if (rdp->nxttail[i] == rdp->nxttail[RCU_DONE_TAIL])
rdp->nxttail[i] = rsp->orphan_donetail;
rsp->orphan_donelist = NULL;
rsp->orphan_donetail = &rsp->orphan_donelist;
}
if (rsp->orphan_nxtlist != NULL) {
*rdp->nxttail[RCU_NEXT_TAIL] = rsp->orphan_nxtlist;
rdp->nxttail[RCU_NEXT_TAIL] = rsp->orphan_nxttail;
rsp->orphan_nxtlist = NULL;
rsp->orphan_nxttail = &rsp->orphan_nxtlist;
}
}
static void rcu_cleanup_dying_cpu(struct rcu_state *rsp)
{
RCU_TRACE(unsigned long mask);
RCU_TRACE(struct rcu_data *rdp = this_cpu_ptr(rsp->rda));
RCU_TRACE(struct rcu_node *rnp = rdp->mynode);
RCU_TRACE(mask = rdp->grpmask);
trace_rcu_grace_period(rsp->name,
rnp->gpnum + 1 - !!(rnp->qsmask & mask),
"cpuofl");
}
static void rcu_cleanup_dead_cpu(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
unsigned long mask;
int need_report = 0;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rdp->mynode;
rcu_stop_cpu_kthread(cpu);
rcu_node_kthread_setaffinity(rnp, -1);
raw_spin_lock_irqsave(&rsp->onofflock, flags);
rcu_send_cbs_to_orphanage(cpu, rsp, rnp, rdp);
rcu_adopt_orphan_cbs(rsp);
mask = rdp->grpmask;
do {
raw_spin_lock(&rnp->lock);
rnp->qsmaskinit &= ~mask;
if (rnp->qsmaskinit != 0) {
if (rnp != rdp->mynode)
raw_spin_unlock(&rnp->lock);
break;
}
if (rnp == rdp->mynode)
need_report = rcu_preempt_offline_tasks(rsp, rnp, rdp);
else
raw_spin_unlock(&rnp->lock);
mask = rnp->grpmask;
rnp = rnp->parent;
} while (rnp != NULL);
raw_spin_unlock(&rsp->onofflock);
rnp = rdp->mynode;
if (need_report & RCU_OFL_TASKS_NORM_GP)
rcu_report_unblock_qs_rnp(rnp, flags);
else
raw_spin_unlock_irqrestore(&rnp->lock, flags);
if (need_report & RCU_OFL_TASKS_EXP_GP)
rcu_report_exp_rnp(rsp, rnp, true);
WARN_ONCE(rdp->qlen != 0 || rdp->nxtlist != NULL,
"rcu_cleanup_dead_cpu: Callbacks on offline CPU %d: qlen=%lu, nxtlist=%p\n",
cpu, rdp->qlen, rdp->nxtlist);
}
static void rcu_adopt_orphan_cbs(struct rcu_state *rsp)
{
}
static void rcu_cleanup_dying_cpu(struct rcu_state *rsp)
{
}
static void rcu_cleanup_dead_cpu(int cpu, struct rcu_state *rsp)
{
}
static void rcu_do_batch(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
struct rcu_head *next, *list, **tail;
int bl, count, count_lazy, i;
if (!cpu_has_callbacks_ready_to_invoke(rdp)) {
trace_rcu_batch_start(rsp->name, rdp->qlen_lazy, rdp->qlen, 0);
trace_rcu_batch_end(rsp->name, 0, !!ACCESS_ONCE(rdp->nxtlist),
need_resched(), is_idle_task(current),
rcu_is_callbacks_kthread());
return;
}
local_irq_save(flags);
WARN_ON_ONCE(cpu_is_offline(smp_processor_id()));
bl = rdp->blimit;
trace_rcu_batch_start(rsp->name, rdp->qlen_lazy, rdp->qlen, bl);
list = rdp->nxtlist;
rdp->nxtlist = *rdp->nxttail[RCU_DONE_TAIL];
*rdp->nxttail[RCU_DONE_TAIL] = NULL;
tail = rdp->nxttail[RCU_DONE_TAIL];
for (i = RCU_NEXT_SIZE - 1; i >= 0; i--)
if (rdp->nxttail[i] == rdp->nxttail[RCU_DONE_TAIL])
rdp->nxttail[i] = &rdp->nxtlist;
local_irq_restore(flags);
count = count_lazy = 0;
while (list) {
next = list->next;
prefetch(next);
debug_rcu_head_unqueue(list);
if (__rcu_reclaim(rsp->name, list))
count_lazy++;
list = next;
if (++count >= bl &&
(need_resched() ||
(!is_idle_task(current) && !rcu_is_callbacks_kthread())))
break;
}
local_irq_save(flags);
trace_rcu_batch_end(rsp->name, count, !!list, need_resched(),
is_idle_task(current),
rcu_is_callbacks_kthread());
if (list != NULL) {
*tail = rdp->nxtlist;
rdp->nxtlist = list;
for (i = 0; i < RCU_NEXT_SIZE; i++)
if (&rdp->nxtlist == rdp->nxttail[i])
rdp->nxttail[i] = tail;
else
break;
}
smp_mb();
rdp->qlen_lazy -= count_lazy;
ACCESS_ONCE(rdp->qlen) -= count;
rdp->n_cbs_invoked += count;
if (rdp->blimit == LONG_MAX && rdp->qlen <= qlowmark)
rdp->blimit = blimit;
if (rdp->qlen == 0 && rdp->qlen_last_fqs_check != 0) {
rdp->qlen_last_fqs_check = 0;
rdp->n_force_qs_snap = rsp->n_force_qs;
} else if (rdp->qlen < rdp->qlen_last_fqs_check - qhimark)
rdp->qlen_last_fqs_check = rdp->qlen;
WARN_ON_ONCE((rdp->nxtlist == NULL) != (rdp->qlen == 0));
local_irq_restore(flags);
if (cpu_has_callbacks_ready_to_invoke(rdp))
invoke_rcu_core();
}
void rcu_check_callbacks(int cpu, int user)
{
trace_rcu_utilization("Start scheduler-tick");
increment_cpu_stall_ticks();
if (user || rcu_is_cpu_rrupt_from_idle()) {
rcu_sched_qs(cpu);
rcu_bh_qs(cpu);
} else if (!in_softirq()) {
rcu_bh_qs(cpu);
}
rcu_preempt_check_callbacks(cpu);
if (rcu_pending(cpu))
invoke_rcu_core();
trace_rcu_utilization("End scheduler-tick");
}
static void force_qs_rnp(struct rcu_state *rsp, int (*f)(struct rcu_data *))
{
unsigned long bit;
int cpu;
unsigned long flags;
unsigned long mask;
struct rcu_node *rnp;
rcu_for_each_leaf_node(rsp, rnp) {
mask = 0;
raw_spin_lock_irqsave(&rnp->lock, flags);
if (!rcu_gp_in_progress(rsp)) {
raw_spin_unlock_irqrestore(&rnp->lock, flags);
return;
}
if (rnp->qsmask == 0) {
rcu_initiate_boost(rnp, flags);
continue;
}
cpu = rnp->grplo;
bit = 1;
for (; cpu <= rnp->grphi; cpu++, bit <<= 1) {
if ((rnp->qsmask & bit) != 0 &&
f(per_cpu_ptr(rsp->rda, cpu)))
mask |= bit;
}
if (mask != 0) {
rcu_report_qs_rnp(mask, rsp, rnp, flags);
continue;
}
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
rnp = rcu_get_root(rsp);
if (rnp->qsmask == 0) {
raw_spin_lock_irqsave(&rnp->lock, flags);
rcu_initiate_boost(rnp, flags);
}
}
static void force_quiescent_state(struct rcu_state *rsp, int relaxed)
{
unsigned long flags;
struct rcu_node *rnp = rcu_get_root(rsp);
trace_rcu_utilization("Start fqs");
if (!rcu_gp_in_progress(rsp)) {
trace_rcu_utilization("End fqs");
return;
}
if (!raw_spin_trylock_irqsave(&rsp->fqslock, flags)) {
rsp->n_force_qs_lh++;
trace_rcu_utilization("End fqs");
return;
}
if (relaxed && ULONG_CMP_GE(rsp->jiffies_force_qs, jiffies))
goto unlock_fqs_ret;
rsp->n_force_qs++;
raw_spin_lock(&rnp->lock);
rsp->jiffies_force_qs = jiffies + RCU_JIFFIES_TILL_FORCE_QS;
if(!rcu_gp_in_progress(rsp)) {
rsp->n_force_qs_ngp++;
raw_spin_unlock(&rnp->lock);
goto unlock_fqs_ret;
}
rsp->fqs_active = 1;
switch (rsp->fqs_state) {
case RCU_GP_IDLE:
case RCU_GP_INIT:
break;
case RCU_SAVE_DYNTICK:
raw_spin_unlock(&rnp->lock);
force_qs_rnp(rsp, dyntick_save_progress_counter);
raw_spin_lock(&rnp->lock);
if (rcu_gp_in_progress(rsp))
rsp->fqs_state = RCU_FORCE_QS;
break;
case RCU_FORCE_QS:
raw_spin_unlock(&rnp->lock);
force_qs_rnp(rsp, rcu_implicit_dynticks_qs);
raw_spin_lock(&rnp->lock);
break;
}
rsp->fqs_active = 0;
if (rsp->fqs_need_gp) {
raw_spin_unlock(&rsp->fqslock);
rsp->fqs_need_gp = 0;
rcu_start_gp(rsp, flags);
trace_rcu_utilization("End fqs");
return;
}
raw_spin_unlock(&rnp->lock);
unlock_fqs_ret:
raw_spin_unlock_irqrestore(&rsp->fqslock, flags);
trace_rcu_utilization("End fqs");
}
static void
__rcu_process_callbacks(struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_data *rdp = __this_cpu_ptr(rsp->rda);
WARN_ON_ONCE(rdp->beenonline == 0);
if (ULONG_CMP_LT(ACCESS_ONCE(rsp->jiffies_force_qs), jiffies))
force_quiescent_state(rsp, 1);
rcu_process_gp_end(rsp, rdp);
rcu_check_quiescent_state(rsp, rdp);
if (cpu_needs_another_gp(rsp, rdp)) {
raw_spin_lock_irqsave(&rcu_get_root(rsp)->lock, flags);
rcu_start_gp(rsp, flags);
}
if (cpu_has_callbacks_ready_to_invoke(rdp))
invoke_rcu_callbacks(rsp, rdp);
}
static void rcu_process_callbacks(struct softirq_action *unused)
{
struct rcu_state *rsp;
trace_rcu_utilization("Start RCU core");
for_each_rcu_flavor(rsp)
__rcu_process_callbacks(rsp);
trace_rcu_utilization("End RCU core");
}
static void invoke_rcu_callbacks(struct rcu_state *rsp, struct rcu_data *rdp)
{
if (unlikely(!ACCESS_ONCE(rcu_scheduler_fully_active)))
return;
if (likely(!rsp->boost)) {
rcu_do_batch(rsp, rdp);
return;
}
invoke_rcu_callbacks_kthread();
}
static void invoke_rcu_core(void)
{
raise_softirq(RCU_SOFTIRQ);
}
static void __call_rcu_core(struct rcu_state *rsp, struct rcu_data *rdp,
struct rcu_head *head, unsigned long flags)
{
if (rcu_is_cpu_idle() && cpu_online(smp_processor_id()))
invoke_rcu_core();
if (irqs_disabled_flags(flags) || cpu_is_offline(smp_processor_id()))
return;
if (unlikely(rdp->qlen > rdp->qlen_last_fqs_check + qhimark)) {
rcu_process_gp_end(rsp, rdp);
check_for_new_grace_period(rsp, rdp);
if (!rcu_gp_in_progress(rsp)) {
unsigned long nestflag;
struct rcu_node *rnp_root = rcu_get_root(rsp);
raw_spin_lock_irqsave(&rnp_root->lock, nestflag);
rcu_start_gp(rsp, nestflag);
} else {
rdp->blimit = LONG_MAX;
if (rsp->n_force_qs == rdp->n_force_qs_snap &&
*rdp->nxttail[RCU_DONE_TAIL] != head)
force_quiescent_state(rsp, 0);
rdp->n_force_qs_snap = rsp->n_force_qs;
rdp->qlen_last_fqs_check = rdp->qlen;
}
} else if (ULONG_CMP_LT(ACCESS_ONCE(rsp->jiffies_force_qs), jiffies))
force_quiescent_state(rsp, 1);
}
static void
__call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *rcu),
struct rcu_state *rsp, bool lazy)
{
unsigned long flags;
struct rcu_data *rdp;
WARN_ON_ONCE((unsigned long)head & 0x3);
debug_rcu_head_queue(head);
head->func = func;
head->next = NULL;
smp_mb();
local_irq_save(flags);
rdp = this_cpu_ptr(rsp->rda);
ACCESS_ONCE(rdp->qlen)++;
if (lazy)
rdp->qlen_lazy++;
else
rcu_idle_count_callbacks_posted();
smp_mb();
*rdp->nxttail[RCU_NEXT_TAIL] = head;
rdp->nxttail[RCU_NEXT_TAIL] = &head->next;
if (__is_kfree_rcu_offset((unsigned long)func))
trace_rcu_kfree_callback(rsp->name, head, (unsigned long)func,
rdp->qlen_lazy, rdp->qlen);
else
trace_rcu_callback(rsp->name, head, rdp->qlen_lazy, rdp->qlen);
__call_rcu_core(rsp, rdp, head, flags);
local_irq_restore(flags);
}
void call_rcu_sched(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
__call_rcu(head, func, &rcu_sched_state, 0);
}
void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
__call_rcu(head, func, &rcu_bh_state, 0);
}
static inline int rcu_blocking_is_gp(void)
{
int ret;
might_sleep();
preempt_disable();
ret = num_online_cpus() <= 1;
preempt_enable();
return ret;
}
void synchronize_sched(void)
{
rcu_lockdep_assert(!lock_is_held(&rcu_bh_lock_map) &&
!lock_is_held(&rcu_lock_map) &&
!lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_sched() in RCU-sched read-side critical section");
if (rcu_blocking_is_gp())
return;
wait_rcu_gp(call_rcu_sched);
}
void synchronize_rcu_bh(void)
{
rcu_lockdep_assert(!lock_is_held(&rcu_bh_lock_map) &&
!lock_is_held(&rcu_lock_map) &&
!lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_rcu_bh() in RCU-bh read-side critical section");
if (rcu_blocking_is_gp())
return;
wait_rcu_gp(call_rcu_bh);
}
static int synchronize_sched_expedited_cpu_stop(void *data)
{
smp_mb();
return 0;
}
void synchronize_sched_expedited(void)
{
int firstsnap, s, snap, trycount = 0;
firstsnap = snap = atomic_inc_return(&sync_sched_expedited_started);
get_online_cpus();
WARN_ON_ONCE(cpu_is_offline(raw_smp_processor_id()));
while (try_stop_cpus(cpu_online_mask,
synchronize_sched_expedited_cpu_stop,
NULL) == -EAGAIN) {
put_online_cpus();
if (trycount++ < 10) {
udelay(trycount * num_online_cpus());
} else {
synchronize_sched();
return;
}
s = atomic_read(&sync_sched_expedited_done);
if (UINT_CMP_GE((unsigned)s, (unsigned)firstsnap)) {
smp_mb();
return;
}
get_online_cpus();
snap = atomic_read(&sync_sched_expedited_started);
smp_mb();
}
do {
s = atomic_read(&sync_sched_expedited_done);
if (UINT_CMP_GE((unsigned)s, (unsigned)snap)) {
smp_mb();
break;
}
} while (atomic_cmpxchg(&sync_sched_expedited_done, s, snap) != s);
put_online_cpus();
}
static int __rcu_pending(struct rcu_state *rsp, struct rcu_data *rdp)
{
struct rcu_node *rnp = rdp->mynode;
rdp->n_rcu_pending++;
check_cpu_stall(rsp, rdp);
if (rcu_scheduler_fully_active &&
rdp->qs_pending && !rdp->passed_quiesce) {
rdp->n_rp_qs_pending++;
if (!rdp->preemptible &&
ULONG_CMP_LT(ACCESS_ONCE(rsp->jiffies_force_qs) - 1,
jiffies))
set_need_resched();
} else if (rdp->qs_pending && rdp->passed_quiesce) {
rdp->n_rp_report_qs++;
return 1;
}
if (cpu_has_callbacks_ready_to_invoke(rdp)) {
rdp->n_rp_cb_ready++;
return 1;
}
if (cpu_needs_another_gp(rsp, rdp)) {
rdp->n_rp_cpu_needs_gp++;
return 1;
}
if (ACCESS_ONCE(rnp->completed) != rdp->completed) {
rdp->n_rp_gp_completed++;
return 1;
}
if (ACCESS_ONCE(rnp->gpnum) != rdp->gpnum) {
rdp->n_rp_gp_started++;
return 1;
}
if (rcu_gp_in_progress(rsp) &&
ULONG_CMP_LT(ACCESS_ONCE(rsp->jiffies_force_qs), jiffies)) {
rdp->n_rp_need_fqs++;
return 1;
}
rdp->n_rp_need_nothing++;
return 0;
}
static int rcu_pending(int cpu)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
if (__rcu_pending(rsp, per_cpu_ptr(rsp->rda, cpu)))
return 1;
return 0;
}
static int rcu_cpu_has_callbacks(int cpu)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
if (per_cpu_ptr(rsp->rda, cpu)->nxtlist)
return 1;
return 0;
}
static void _rcu_barrier_trace(struct rcu_state *rsp, char *s,
int cpu, unsigned long done)
{
trace_rcu_barrier(rsp->name, s, cpu,
atomic_read(&rsp->barrier_cpu_count), done);
}
static void rcu_barrier_callback(struct rcu_head *rhp)
{
struct rcu_data *rdp = container_of(rhp, struct rcu_data, barrier_head);
struct rcu_state *rsp = rdp->rsp;
if (atomic_dec_and_test(&rsp->barrier_cpu_count)) {
_rcu_barrier_trace(rsp, "LastCB", -1, rsp->n_barrier_done);
complete(&rsp->barrier_completion);
} else {
_rcu_barrier_trace(rsp, "CB", -1, rsp->n_barrier_done);
}
}
static void rcu_barrier_func(void *type)
{
struct rcu_state *rsp = type;
struct rcu_data *rdp = __this_cpu_ptr(rsp->rda);
_rcu_barrier_trace(rsp, "IRQ", -1, rsp->n_barrier_done);
atomic_inc(&rsp->barrier_cpu_count);
rsp->call(&rdp->barrier_head, rcu_barrier_callback);
}
static void _rcu_barrier(struct rcu_state *rsp)
{
int cpu;
unsigned long flags;
struct rcu_data *rdp;
struct rcu_data rd;
unsigned long snap = ACCESS_ONCE(rsp->n_barrier_done);
unsigned long snap_done;
init_rcu_head_on_stack(&rd.barrier_head);
_rcu_barrier_trace(rsp, "Begin", -1, snap);
mutex_lock(&rsp->barrier_mutex);
smp_mb();
snap_done = ACCESS_ONCE(rsp->n_barrier_done);
_rcu_barrier_trace(rsp, "Check", -1, snap_done);
if (ULONG_CMP_GE(snap_done, ((snap + 1) & ~0x1) + 2)) {
_rcu_barrier_trace(rsp, "EarlyExit", -1, snap_done);
smp_mb();
mutex_unlock(&rsp->barrier_mutex);
return;
}
ACCESS_ONCE(rsp->n_barrier_done)++;
WARN_ON_ONCE((rsp->n_barrier_done & 0x1) != 1);
_rcu_barrier_trace(rsp, "Inc1", -1, rsp->n_barrier_done);
smp_mb();
init_completion(&rsp->barrier_completion);
atomic_set(&rsp->barrier_cpu_count, 1);
raw_spin_lock_irqsave(&rsp->onofflock, flags);
rsp->rcu_barrier_in_progress = current;
raw_spin_unlock_irqrestore(&rsp->onofflock, flags);
for_each_possible_cpu(cpu) {
preempt_disable();
rdp = per_cpu_ptr(rsp->rda, cpu);
if (cpu_is_offline(cpu)) {
_rcu_barrier_trace(rsp, "Offline", cpu,
rsp->n_barrier_done);
preempt_enable();
while (cpu_is_offline(cpu) && ACCESS_ONCE(rdp->qlen))
schedule_timeout_interruptible(1);
} else if (ACCESS_ONCE(rdp->qlen)) {
_rcu_barrier_trace(rsp, "OnlineQ", cpu,
rsp->n_barrier_done);
smp_call_function_single(cpu, rcu_barrier_func, rsp, 1);
preempt_enable();
} else {
_rcu_barrier_trace(rsp, "OnlineNQ", cpu,
rsp->n_barrier_done);
preempt_enable();
}
}
raw_spin_lock_irqsave(&rsp->onofflock, flags);
rcu_adopt_orphan_cbs(rsp);
rsp->rcu_barrier_in_progress = NULL;
raw_spin_unlock_irqrestore(&rsp->onofflock, flags);
atomic_inc(&rsp->barrier_cpu_count);
smp_mb__after_atomic_inc();
rd.rsp = rsp;
rsp->call(&rd.barrier_head, rcu_barrier_callback);
if (atomic_dec_and_test(&rsp->barrier_cpu_count))
complete(&rsp->barrier_completion);
smp_mb();
ACCESS_ONCE(rsp->n_barrier_done)++;
WARN_ON_ONCE((rsp->n_barrier_done & 0x1) != 0);
_rcu_barrier_trace(rsp, "Inc2", -1, rsp->n_barrier_done);
smp_mb();
wait_for_completion(&rsp->barrier_completion);
mutex_unlock(&rsp->barrier_mutex);
destroy_rcu_head_on_stack(&rd.barrier_head);
}
void rcu_barrier_bh(void)
{
_rcu_barrier(&rcu_bh_state);
}
void rcu_barrier_sched(void)
{
_rcu_barrier(&rcu_sched_state);
}
static void __init
rcu_boot_init_percpu_data(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave(&rnp->lock, flags);
rdp->grpmask = 1UL << (cpu - rdp->mynode->grplo);
init_callback_list(rdp);
rdp->qlen_lazy = 0;
ACCESS_ONCE(rdp->qlen) = 0;
rdp->dynticks = &per_cpu(rcu_dynticks, cpu);
WARN_ON_ONCE(rdp->dynticks->dynticks_nesting != DYNTICK_TASK_EXIT_IDLE);
WARN_ON_ONCE(atomic_read(&rdp->dynticks->dynticks) != 1);
rdp->cpu = cpu;
rdp->rsp = rsp;
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
static void __cpuinit
rcu_init_percpu_data(int cpu, struct rcu_state *rsp, int preemptible)
{
unsigned long flags;
unsigned long mask;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave(&rnp->lock, flags);
rdp->beenonline = 1;
rdp->preemptible = preemptible;
rdp->qlen_last_fqs_check = 0;
rdp->n_force_qs_snap = rsp->n_force_qs;
rdp->blimit = blimit;
rdp->dynticks->dynticks_nesting = DYNTICK_TASK_EXIT_IDLE;
atomic_set(&rdp->dynticks->dynticks,
(atomic_read(&rdp->dynticks->dynticks) & ~0x1) + 1);
rcu_prepare_for_idle_init(cpu);
raw_spin_unlock(&rnp->lock);
raw_spin_lock(&rsp->onofflock);
rnp = rdp->mynode;
mask = rdp->grpmask;
do {
raw_spin_lock(&rnp->lock);
rnp->qsmaskinit |= mask;
mask = rnp->grpmask;
if (rnp == rdp->mynode) {
rdp->gpnum = rnp->completed;
rdp->completed = rnp->completed;
rdp->passed_quiesce = 0;
rdp->qs_pending = 0;
rdp->passed_quiesce_gpnum = rnp->gpnum - 1;
trace_rcu_grace_period(rsp->name, rdp->gpnum, "cpuonl");
}
raw_spin_unlock(&rnp->lock);
rnp = rnp->parent;
} while (rnp != NULL && !(rnp->qsmaskinit & mask));
raw_spin_unlock_irqrestore(&rsp->onofflock, flags);
}
static void __cpuinit rcu_prepare_cpu(int cpu)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
rcu_init_percpu_data(cpu, rsp,
strcmp(rsp->name, "rcu_preempt") == 0);
}
static int __cpuinit rcu_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
long cpu = (long)hcpu;
struct rcu_data *rdp = per_cpu_ptr(rcu_state->rda, cpu);
struct rcu_node *rnp = rdp->mynode;
struct rcu_state *rsp;
trace_rcu_utilization("Start CPU hotplug");
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
rcu_prepare_cpu(cpu);
rcu_prepare_kthreads(cpu);
break;
case CPU_ONLINE:
case CPU_DOWN_FAILED:
rcu_node_kthread_setaffinity(rnp, -1);
rcu_cpu_kthread_setrt(cpu, 1);
break;
case CPU_DOWN_PREPARE:
rcu_node_kthread_setaffinity(rnp, cpu);
rcu_cpu_kthread_setrt(cpu, 0);
break;
case CPU_DYING:
case CPU_DYING_FROZEN:
for_each_rcu_flavor(rsp)
rcu_cleanup_dying_cpu(rsp);
rcu_cleanup_after_idle(cpu);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
for_each_rcu_flavor(rsp)
rcu_cleanup_dead_cpu(cpu, rsp);
break;
default:
break;
}
trace_rcu_utilization("End CPU hotplug");
return NOTIFY_OK;
}
void rcu_scheduler_starting(void)
{
WARN_ON(num_online_cpus() != 1);
WARN_ON(nr_context_switches() > 0);
rcu_scheduler_active = 1;
}
static void __init rcu_init_levelspread(struct rcu_state *rsp)
{
int i;
for (i = rcu_num_lvls - 1; i > 0; i--)
rsp->levelspread[i] = CONFIG_RCU_FANOUT;
rsp->levelspread[0] = rcu_fanout_leaf;
}
static void __init rcu_init_levelspread(struct rcu_state *rsp)
{
int ccur;
int cprv;
int i;
cprv = NR_CPUS;
for (i = rcu_num_lvls - 1; i >= 0; i--) {
ccur = rsp->levelcnt[i];
rsp->levelspread[i] = (cprv + ccur - 1) / ccur;
cprv = ccur;
}
}
static void __init rcu_init_one(struct rcu_state *rsp,
struct rcu_data __percpu *rda)
{
static char *buf[] = { "rcu_node_level_0",
"rcu_node_level_1",
"rcu_node_level_2",
"rcu_node_level_3" };
int cpustride = 1;
int i;
int j;
struct rcu_node *rnp;
BUILD_BUG_ON(MAX_RCU_LVLS > ARRAY_SIZE(buf));
for (i = 0; i < rcu_num_lvls; i++)
rsp->levelcnt[i] = num_rcu_lvl[i];
for (i = 1; i < rcu_num_lvls; i++)
rsp->level[i] = rsp->level[i - 1] + rsp->levelcnt[i - 1];
rcu_init_levelspread(rsp);
for (i = rcu_num_lvls - 1; i >= 0; i--) {
cpustride *= rsp->levelspread[i];
rnp = rsp->level[i];
for (j = 0; j < rsp->levelcnt[i]; j++, rnp++) {
raw_spin_lock_init(&rnp->lock);
lockdep_set_class_and_name(&rnp->lock,
&rcu_node_class[i], buf[i]);
rnp->gpnum = 0;
rnp->qsmask = 0;
rnp->qsmaskinit = 0;
rnp->grplo = j * cpustride;
rnp->grphi = (j + 1) * cpustride - 1;
if (rnp->grphi >= NR_CPUS)
rnp->grphi = NR_CPUS - 1;
if (i == 0) {
rnp->grpnum = 0;
rnp->grpmask = 0;
rnp->parent = NULL;
} else {
rnp->grpnum = j % rsp->levelspread[i - 1];
rnp->grpmask = 1UL << rnp->grpnum;
rnp->parent = rsp->level[i - 1] +
j / rsp->levelspread[i - 1];
}
rnp->level = i;
INIT_LIST_HEAD(&rnp->blkd_tasks);
}
}
rsp->rda = rda;
rnp = rsp->level[rcu_num_lvls - 1];
for_each_possible_cpu(i) {
while (i > rnp->grphi)
rnp++;
per_cpu_ptr(rsp->rda, i)->mynode = rnp;
rcu_boot_init_percpu_data(i, rsp);
}
list_add(&rsp->flavors, &rcu_struct_flavors);
}
static void __init rcu_init_geometry(void)
{
int i;
int j;
int n = nr_cpu_ids;
int rcu_capacity[MAX_RCU_LVLS + 1];
if (rcu_fanout_leaf == CONFIG_RCU_FANOUT_LEAF)
return;
rcu_capacity[0] = 1;
rcu_capacity[1] = rcu_fanout_leaf;
for (i = 2; i <= MAX_RCU_LVLS; i++)
rcu_capacity[i] = rcu_capacity[i - 1] * CONFIG_RCU_FANOUT;
if (rcu_fanout_leaf < CONFIG_RCU_FANOUT_LEAF ||
rcu_fanout_leaf > sizeof(unsigned long) * 8 ||
n > rcu_capacity[MAX_RCU_LVLS]) {
WARN_ON(1);
return;
}
for (i = 1; i <= MAX_RCU_LVLS; i++)
if (n <= rcu_capacity[i]) {
for (j = 0; j <= i; j++)
num_rcu_lvl[j] =
DIV_ROUND_UP(n, rcu_capacity[i - j]);
rcu_num_lvls = i;
for (j = i + 1; j <= MAX_RCU_LVLS; j++)
num_rcu_lvl[j] = 0;
break;
}
rcu_num_nodes = 0;
for (i = 0; i <= MAX_RCU_LVLS; i++)
rcu_num_nodes += num_rcu_lvl[i];
rcu_num_nodes -= n;
}
void __init rcu_init(void)
{
int cpu;
rcu_bootup_announce();
rcu_init_geometry();
rcu_init_one(&rcu_sched_state, &rcu_sched_data);
rcu_init_one(&rcu_bh_state, &rcu_bh_data);
__rcu_init_preempt();
open_softirq(RCU_SOFTIRQ, rcu_process_callbacks);
cpu_notifier(rcu_cpu_notify, 0);
for_each_online_cpu(cpu)
rcu_cpu_notify(NULL, CPU_UP_PREPARE, (void *)(long)cpu);
check_cpu_stall_init();
}
