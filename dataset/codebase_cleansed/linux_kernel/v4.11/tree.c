unsigned long rcu_rnp_online_cpus(struct rcu_node *rnp)
{
return READ_ONCE(rnp->qsmaskinitnext);
}
static int rcu_gp_in_progress(struct rcu_state *rsp)
{
return READ_ONCE(rsp->completed) != READ_ONCE(rsp->gpnum);
}
void rcu_sched_qs(void)
{
if (!__this_cpu_read(rcu_sched_data.cpu_no_qs.s))
return;
trace_rcu_grace_period(TPS("rcu_sched"),
__this_cpu_read(rcu_sched_data.gpnum),
TPS("cpuqs"));
__this_cpu_write(rcu_sched_data.cpu_no_qs.b.norm, false);
if (!__this_cpu_read(rcu_sched_data.cpu_no_qs.b.exp))
return;
__this_cpu_write(rcu_sched_data.cpu_no_qs.b.exp, false);
rcu_report_exp_rdp(&rcu_sched_state,
this_cpu_ptr(&rcu_sched_data), true);
}
void rcu_bh_qs(void)
{
if (__this_cpu_read(rcu_bh_data.cpu_no_qs.s)) {
trace_rcu_grace_period(TPS("rcu_bh"),
__this_cpu_read(rcu_bh_data.gpnum),
TPS("cpuqs"));
__this_cpu_write(rcu_bh_data.cpu_no_qs.b.norm, false);
}
}
static void rcu_dynticks_eqs_enter(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
int special;
special = atomic_inc_return(&rdtp->dynticks);
WARN_ON_ONCE(IS_ENABLED(CONFIG_RCU_EQS_DEBUG) && special & 0x1);
}
static void rcu_dynticks_eqs_exit(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
int special;
special = atomic_inc_return(&rdtp->dynticks);
WARN_ON_ONCE(IS_ENABLED(CONFIG_RCU_EQS_DEBUG) && !(special & 0x1));
}
static void rcu_dynticks_eqs_online(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
if (atomic_read(&rdtp->dynticks) & 0x1)
return;
atomic_add(0x1, &rdtp->dynticks);
}
bool rcu_dynticks_curr_cpu_in_eqs(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
return !(atomic_read(&rdtp->dynticks) & 0x1);
}
int rcu_dynticks_snap(struct rcu_dynticks *rdtp)
{
int snap = atomic_add_return(0, &rdtp->dynticks);
return snap;
}
static bool rcu_dynticks_in_eqs(int snap)
{
return !(snap & 0x1);
}
static bool rcu_dynticks_in_eqs_since(struct rcu_dynticks *rdtp, int snap)
{
return snap != rcu_dynticks_snap(rdtp);
}
static void rcu_dynticks_momentary_idle(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
int special = atomic_add_return(2, &rdtp->dynticks);
WARN_ON_ONCE(!(special & 0x1));
}
static void rcu_momentary_dyntick_idle(void)
{
struct rcu_data *rdp;
int resched_mask;
struct rcu_state *rsp;
resched_mask = raw_cpu_read(rcu_sched_qs_mask);
raw_cpu_write(rcu_sched_qs_mask, 0);
for_each_rcu_flavor(rsp) {
rdp = raw_cpu_ptr(rsp->rda);
if (!(resched_mask & rsp->flavor_mask))
continue;
smp_mb();
if (READ_ONCE(rdp->mynode->completed) !=
READ_ONCE(rdp->cond_resched_completed))
continue;
rcu_dynticks_momentary_idle();
break;
}
}
void rcu_note_context_switch(void)
{
barrier();
trace_rcu_utilization(TPS("Start context switch"));
rcu_sched_qs();
rcu_preempt_note_context_switch();
if (unlikely(raw_cpu_read(rcu_sched_qs_mask)))
rcu_momentary_dyntick_idle();
trace_rcu_utilization(TPS("End context switch"));
barrier();
}
void rcu_all_qs(void)
{
unsigned long flags;
barrier();
if (unlikely(raw_cpu_read(rcu_sched_qs_mask))) {
local_irq_save(flags);
rcu_momentary_dyntick_idle();
local_irq_restore(flags);
}
if (unlikely(raw_cpu_read(rcu_sched_data.cpu_no_qs.b.exp))) {
preempt_disable();
rcu_sched_qs();
preempt_enable();
}
this_cpu_inc(rcu_qs_ctr);
barrier();
}
unsigned long rcu_batches_started(void)
{
return rcu_state_p->gpnum;
}
unsigned long rcu_batches_started_sched(void)
{
return rcu_sched_state.gpnum;
}
unsigned long rcu_batches_started_bh(void)
{
return rcu_bh_state.gpnum;
}
unsigned long rcu_batches_completed(void)
{
return rcu_state_p->completed;
}
unsigned long rcu_batches_completed_sched(void)
{
return rcu_sched_state.completed;
}
unsigned long rcu_batches_completed_bh(void)
{
return rcu_bh_state.completed;
}
unsigned long rcu_exp_batches_completed(void)
{
return rcu_state_p->expedited_sequence;
}
unsigned long rcu_exp_batches_completed_sched(void)
{
return rcu_sched_state.expedited_sequence;
}
void rcu_force_quiescent_state(void)
{
force_quiescent_state(rcu_state_p);
}
void rcu_bh_force_quiescent_state(void)
{
force_quiescent_state(&rcu_bh_state);
}
void rcu_sched_force_quiescent_state(void)
{
force_quiescent_state(&rcu_sched_state);
}
void show_rcu_gp_kthreads(void)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp) {
pr_info("%s: wait state: %d ->state: %#lx\n",
rsp->name, rsp->gp_state, rsp->gp_kthread->state);
}
}
void rcutorture_record_test_transition(void)
{
rcutorture_testseq++;
rcutorture_vernum = 0;
}
void rcutorture_get_gp_data(enum rcutorture_type test_type, int *flags,
unsigned long *gpnum, unsigned long *completed)
{
struct rcu_state *rsp = NULL;
switch (test_type) {
case RCU_FLAVOR:
rsp = rcu_state_p;
break;
case RCU_BH_FLAVOR:
rsp = &rcu_bh_state;
break;
case RCU_SCHED_FLAVOR:
rsp = &rcu_sched_state;
break;
default:
break;
}
if (rsp != NULL) {
*flags = READ_ONCE(rsp->gp_flags);
*gpnum = READ_ONCE(rsp->gpnum);
*completed = READ_ONCE(rsp->completed);
return;
}
*flags = 0;
*gpnum = 0;
*completed = 0;
}
void rcutorture_record_progress(unsigned long vernum)
{
rcutorture_vernum++;
}
static int
cpu_has_callbacks_ready_to_invoke(struct rcu_data *rdp)
{
return &rdp->nxtlist != rdp->nxttail[RCU_DONE_TAIL] &&
rdp->nxttail[RCU_NEXT_TAIL] != NULL;
}
static struct rcu_node *rcu_get_root(struct rcu_state *rsp)
{
return &rsp->node[0];
}
static int rcu_future_needs_gp(struct rcu_state *rsp)
{
struct rcu_node *rnp = rcu_get_root(rsp);
int idx = (READ_ONCE(rnp->completed) + 1) & 0x1;
int *fp = &rnp->need_future_gp[idx];
return READ_ONCE(*fp);
}
static bool
cpu_needs_another_gp(struct rcu_state *rsp, struct rcu_data *rdp)
{
int i;
if (rcu_gp_in_progress(rsp))
return false;
if (rcu_future_needs_gp(rsp))
return true;
if (!rdp->nxttail[RCU_NEXT_TAIL])
return false;
if (*rdp->nxttail[RCU_NEXT_READY_TAIL])
return true;
for (i = RCU_WAIT_TAIL; i < RCU_NEXT_TAIL; i++)
if (rdp->nxttail[i - 1] != rdp->nxttail[i] &&
ULONG_CMP_LT(READ_ONCE(rsp->completed),
rdp->nxtcompleted[i]))
return true;
return false;
}
static void rcu_eqs_enter_common(long long oldval, bool user)
{
struct rcu_state *rsp;
struct rcu_data *rdp;
RCU_TRACE(struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);)
trace_rcu_dyntick(TPS("Start"), oldval, rdtp->dynticks_nesting);
if (IS_ENABLED(CONFIG_RCU_EQS_DEBUG) &&
!user && !is_idle_task(current)) {
struct task_struct *idle __maybe_unused =
idle_task(smp_processor_id());
trace_rcu_dyntick(TPS("Error on entry: not idle task"), oldval, 0);
rcu_ftrace_dump(DUMP_ORIG);
WARN_ONCE(1, "Current pid: %d comm: %s / Idle pid: %d comm: %s",
current->pid, current->comm,
idle->pid, idle->comm);
}
for_each_rcu_flavor(rsp) {
rdp = this_cpu_ptr(rsp->rda);
do_nocb_deferred_wakeup(rdp);
}
rcu_prepare_for_idle();
rcu_dynticks_eqs_enter();
rcu_dynticks_task_enter();
RCU_LOCKDEP_WARN(lock_is_held(&rcu_lock_map),
"Illegal idle entry in RCU read-side critical section.");
RCU_LOCKDEP_WARN(lock_is_held(&rcu_bh_lock_map),
"Illegal idle entry in RCU-bh read-side critical section.");
RCU_LOCKDEP_WARN(lock_is_held(&rcu_sched_lock_map),
"Illegal idle entry in RCU-sched read-side critical section.");
}
static void rcu_eqs_enter(bool user)
{
long long oldval;
struct rcu_dynticks *rdtp;
rdtp = this_cpu_ptr(&rcu_dynticks);
oldval = rdtp->dynticks_nesting;
WARN_ON_ONCE(IS_ENABLED(CONFIG_RCU_EQS_DEBUG) &&
(oldval & DYNTICK_TASK_NEST_MASK) == 0);
if ((oldval & DYNTICK_TASK_NEST_MASK) == DYNTICK_TASK_NEST_VALUE) {
rdtp->dynticks_nesting = 0;
rcu_eqs_enter_common(oldval, user);
} else {
rdtp->dynticks_nesting -= DYNTICK_TASK_NEST_VALUE;
}
}
void rcu_idle_enter(void)
{
unsigned long flags;
local_irq_save(flags);
rcu_eqs_enter(false);
rcu_sysidle_enter(0);
local_irq_restore(flags);
}
void rcu_user_enter(void)
{
rcu_eqs_enter(1);
}
void rcu_irq_exit(void)
{
long long oldval;
struct rcu_dynticks *rdtp;
RCU_LOCKDEP_WARN(!irqs_disabled(), "rcu_irq_exit() invoked with irqs enabled!!!");
rdtp = this_cpu_ptr(&rcu_dynticks);
oldval = rdtp->dynticks_nesting;
rdtp->dynticks_nesting--;
WARN_ON_ONCE(IS_ENABLED(CONFIG_RCU_EQS_DEBUG) &&
rdtp->dynticks_nesting < 0);
if (rdtp->dynticks_nesting)
trace_rcu_dyntick(TPS("--="), oldval, rdtp->dynticks_nesting);
else
rcu_eqs_enter_common(oldval, true);
rcu_sysidle_enter(1);
}
void rcu_irq_exit_irqson(void)
{
unsigned long flags;
local_irq_save(flags);
rcu_irq_exit();
local_irq_restore(flags);
}
static void rcu_eqs_exit_common(long long oldval, int user)
{
RCU_TRACE(struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);)
rcu_dynticks_task_exit();
rcu_dynticks_eqs_exit();
rcu_cleanup_after_idle();
trace_rcu_dyntick(TPS("End"), oldval, rdtp->dynticks_nesting);
if (IS_ENABLED(CONFIG_RCU_EQS_DEBUG) &&
!user && !is_idle_task(current)) {
struct task_struct *idle __maybe_unused =
idle_task(smp_processor_id());
trace_rcu_dyntick(TPS("Error on exit: not idle task"),
oldval, rdtp->dynticks_nesting);
rcu_ftrace_dump(DUMP_ORIG);
WARN_ONCE(1, "Current pid: %d comm: %s / Idle pid: %d comm: %s",
current->pid, current->comm,
idle->pid, idle->comm);
}
}
static void rcu_eqs_exit(bool user)
{
struct rcu_dynticks *rdtp;
long long oldval;
rdtp = this_cpu_ptr(&rcu_dynticks);
oldval = rdtp->dynticks_nesting;
WARN_ON_ONCE(IS_ENABLED(CONFIG_RCU_EQS_DEBUG) && oldval < 0);
if (oldval & DYNTICK_TASK_NEST_MASK) {
rdtp->dynticks_nesting += DYNTICK_TASK_NEST_VALUE;
} else {
rdtp->dynticks_nesting = DYNTICK_TASK_EXIT_IDLE;
rcu_eqs_exit_common(oldval, user);
}
}
void rcu_idle_exit(void)
{
unsigned long flags;
local_irq_save(flags);
rcu_eqs_exit(false);
rcu_sysidle_exit(0);
local_irq_restore(flags);
}
void rcu_user_exit(void)
{
rcu_eqs_exit(1);
}
void rcu_irq_enter(void)
{
struct rcu_dynticks *rdtp;
long long oldval;
RCU_LOCKDEP_WARN(!irqs_disabled(), "rcu_irq_enter() invoked with irqs enabled!!!");
rdtp = this_cpu_ptr(&rcu_dynticks);
oldval = rdtp->dynticks_nesting;
rdtp->dynticks_nesting++;
WARN_ON_ONCE(IS_ENABLED(CONFIG_RCU_EQS_DEBUG) &&
rdtp->dynticks_nesting == 0);
if (oldval)
trace_rcu_dyntick(TPS("++="), oldval, rdtp->dynticks_nesting);
else
rcu_eqs_exit_common(oldval, true);
rcu_sysidle_exit(1);
}
void rcu_irq_enter_irqson(void)
{
unsigned long flags;
local_irq_save(flags);
rcu_irq_enter();
local_irq_restore(flags);
}
void rcu_nmi_enter(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
int incby = 2;
WARN_ON_ONCE(rdtp->dynticks_nmi_nesting < 0);
if (rcu_dynticks_curr_cpu_in_eqs()) {
rcu_dynticks_eqs_exit();
incby = 1;
}
rdtp->dynticks_nmi_nesting += incby;
barrier();
}
void rcu_nmi_exit(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
WARN_ON_ONCE(rdtp->dynticks_nmi_nesting <= 0);
WARN_ON_ONCE(rcu_dynticks_curr_cpu_in_eqs());
if (rdtp->dynticks_nmi_nesting != 1) {
rdtp->dynticks_nmi_nesting -= 2;
return;
}
rdtp->dynticks_nmi_nesting = 0;
rcu_dynticks_eqs_enter();
}
bool notrace __rcu_is_watching(void)
{
return !rcu_dynticks_curr_cpu_in_eqs();
}
bool notrace rcu_is_watching(void)
{
bool ret;
preempt_disable_notrace();
ret = __rcu_is_watching();
preempt_enable_notrace();
return ret;
}
bool rcu_lockdep_current_cpu_online(void)
{
struct rcu_data *rdp;
struct rcu_node *rnp;
bool ret;
if (in_nmi())
return true;
preempt_disable();
rdp = this_cpu_ptr(&rcu_sched_data);
rnp = rdp->mynode;
ret = (rdp->grpmask & rcu_rnp_online_cpus(rnp)) ||
!rcu_scheduler_fully_active;
preempt_enable();
return ret;
}
static int rcu_is_cpu_rrupt_from_idle(void)
{
return __this_cpu_read(rcu_dynticks.dynticks_nesting) <= 1;
}
static int dyntick_save_progress_counter(struct rcu_data *rdp,
bool *isidle, unsigned long *maxj)
{
rdp->dynticks_snap = rcu_dynticks_snap(rdp->dynticks);
rcu_sysidle_check_cpu(rdp, isidle, maxj);
if (rcu_dynticks_in_eqs(rdp->dynticks_snap)) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, TPS("dti"));
if (ULONG_CMP_LT(READ_ONCE(rdp->gpnum) + ULONG_MAX / 4,
rdp->mynode->gpnum))
WRITE_ONCE(rdp->gpwrap, true);
return 1;
}
return 0;
}
static int rcu_implicit_dynticks_qs(struct rcu_data *rdp,
bool *isidle, unsigned long *maxj)
{
unsigned long jtsq;
int *rcrmp;
unsigned long rjtsc;
struct rcu_node *rnp;
if (rcu_dynticks_in_eqs_since(rdp->dynticks, rdp->dynticks_snap)) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, TPS("dti"));
rdp->dynticks_fqs++;
return 1;
}
jtsq = jiffies_till_sched_qs;
rjtsc = rcu_jiffies_till_stall_check();
if (jtsq > rjtsc / 2) {
WRITE_ONCE(jiffies_till_sched_qs, rjtsc);
jtsq = rjtsc / 2;
} else if (jtsq < 1) {
WRITE_ONCE(jiffies_till_sched_qs, 1);
jtsq = 1;
}
rnp = rdp->mynode;
if (time_after(jiffies, rdp->rsp->gp_start + jtsq) &&
READ_ONCE(rdp->rcu_qs_ctr_snap) != per_cpu(rcu_qs_ctr, rdp->cpu) &&
READ_ONCE(rdp->gpnum) == rnp->gpnum && !rdp->gpwrap) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, TPS("rqc"));
return 1;
}
if (!(rdp->grpmask & rcu_rnp_online_cpus(rnp))) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, TPS("ofl"));
rdp->offline_fqs++;
return 1;
}
rcrmp = &per_cpu(rcu_sched_qs_mask, rdp->cpu);
if (time_after(jiffies, rdp->rsp->gp_start + jtsq) ||
time_after(jiffies, rdp->rsp->jiffies_resched)) {
if (!(READ_ONCE(*rcrmp) & rdp->rsp->flavor_mask)) {
WRITE_ONCE(rdp->cond_resched_completed,
READ_ONCE(rdp->mynode->completed));
smp_mb();
WRITE_ONCE(*rcrmp,
READ_ONCE(*rcrmp) + rdp->rsp->flavor_mask);
}
rdp->rsp->jiffies_resched += 5;
}
if (jiffies - rdp->rsp->gp_start > rcu_jiffies_till_stall_check() / 2)
resched_cpu(rdp->cpu);
return 0;
}
static void record_gp_stall_check_time(struct rcu_state *rsp)
{
unsigned long j = jiffies;
unsigned long j1;
rsp->gp_start = j;
smp_wmb();
j1 = rcu_jiffies_till_stall_check();
WRITE_ONCE(rsp->jiffies_stall, j + j1);
rsp->jiffies_resched = j + j1 / 2;
rsp->n_force_qs_gpstart = READ_ONCE(rsp->n_force_qs);
}
static const char *gp_state_getname(short gs)
{
if (gs < 0 || gs >= ARRAY_SIZE(gp_state_names))
return "???";
return gp_state_names[gs];
}
static void rcu_check_gp_kthread_starvation(struct rcu_state *rsp)
{
unsigned long gpa;
unsigned long j;
j = jiffies;
gpa = READ_ONCE(rsp->gp_activity);
if (j - gpa > 2 * HZ) {
pr_err("%s kthread starved for %ld jiffies! g%lu c%lu f%#x %s(%d) ->state=%#lx\n",
rsp->name, j - gpa,
rsp->gpnum, rsp->completed,
rsp->gp_flags,
gp_state_getname(rsp->gp_state), rsp->gp_state,
rsp->gp_kthread ? rsp->gp_kthread->state : ~0);
if (rsp->gp_kthread) {
sched_show_task(rsp->gp_kthread);
wake_up_process(rsp->gp_kthread);
}
}
}
static void rcu_dump_cpu_stacks(struct rcu_state *rsp)
{
int cpu;
unsigned long flags;
struct rcu_node *rnp;
rcu_for_each_leaf_node(rsp, rnp) {
raw_spin_lock_irqsave_rcu_node(rnp, flags);
for_each_leaf_node_possible_cpu(rnp, cpu)
if (rnp->qsmask & leaf_node_cpu_bit(rnp, cpu))
if (!trigger_single_cpu_backtrace(cpu))
dump_cpu_task(cpu);
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
}
}
static void rcu_stall_kick_kthreads(struct rcu_state *rsp)
{
unsigned long j;
if (!rcu_kick_kthreads)
return;
j = READ_ONCE(rsp->jiffies_kick_kthreads);
if (time_after(jiffies, j) && rsp->gp_kthread &&
(rcu_gp_in_progress(rsp) || READ_ONCE(rsp->gp_flags))) {
WARN_ONCE(1, "Kicking %s grace-period kthread\n", rsp->name);
rcu_ftrace_dump(DUMP_ALL);
wake_up_process(rsp->gp_kthread);
WRITE_ONCE(rsp->jiffies_kick_kthreads, j + HZ);
}
}
static inline void panic_on_rcu_stall(void)
{
if (sysctl_panic_on_rcu_stall)
panic("RCU Stall\n");
}
static void print_other_cpu_stall(struct rcu_state *rsp, unsigned long gpnum)
{
int cpu;
long delta;
unsigned long flags;
unsigned long gpa;
unsigned long j;
int ndetected = 0;
struct rcu_node *rnp = rcu_get_root(rsp);
long totqlen = 0;
rcu_stall_kick_kthreads(rsp);
if (rcu_cpu_stall_suppress)
return;
raw_spin_lock_irqsave_rcu_node(rnp, flags);
delta = jiffies - READ_ONCE(rsp->jiffies_stall);
if (delta < RCU_STALL_RAT_DELAY || !rcu_gp_in_progress(rsp)) {
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
return;
}
WRITE_ONCE(rsp->jiffies_stall,
jiffies + 3 * rcu_jiffies_till_stall_check() + 3);
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
pr_err("INFO: %s detected stalls on CPUs/tasks:",
rsp->name);
print_cpu_stall_info_begin();
rcu_for_each_leaf_node(rsp, rnp) {
raw_spin_lock_irqsave_rcu_node(rnp, flags);
ndetected += rcu_print_task_stall(rnp);
if (rnp->qsmask != 0) {
for_each_leaf_node_possible_cpu(rnp, cpu)
if (rnp->qsmask & leaf_node_cpu_bit(rnp, cpu)) {
print_cpu_stall_info(rsp, cpu);
ndetected++;
}
}
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
}
print_cpu_stall_info_end();
for_each_possible_cpu(cpu)
totqlen += per_cpu_ptr(rsp->rda, cpu)->qlen;
pr_cont("(detected by %d, t=%ld jiffies, g=%ld, c=%ld, q=%lu)\n",
smp_processor_id(), (long)(jiffies - rsp->gp_start),
(long)rsp->gpnum, (long)rsp->completed, totqlen);
if (ndetected) {
rcu_dump_cpu_stacks(rsp);
rcu_print_detail_task_stall(rsp);
} else {
if (READ_ONCE(rsp->gpnum) != gpnum ||
READ_ONCE(rsp->completed) == gpnum) {
pr_err("INFO: Stall ended before state dump start\n");
} else {
j = jiffies;
gpa = READ_ONCE(rsp->gp_activity);
pr_err("All QSes seen, last %s kthread activity %ld (%ld-%ld), jiffies_till_next_fqs=%ld, root ->qsmask %#lx\n",
rsp->name, j - gpa, j, gpa,
jiffies_till_next_fqs,
rcu_get_root(rsp)->qsmask);
sched_show_task(current);
}
}
rcu_check_gp_kthread_starvation(rsp);
panic_on_rcu_stall();
force_quiescent_state(rsp);
}
static void print_cpu_stall(struct rcu_state *rsp)
{
int cpu;
unsigned long flags;
struct rcu_node *rnp = rcu_get_root(rsp);
long totqlen = 0;
rcu_stall_kick_kthreads(rsp);
if (rcu_cpu_stall_suppress)
return;
pr_err("INFO: %s self-detected stall on CPU", rsp->name);
print_cpu_stall_info_begin();
print_cpu_stall_info(rsp, smp_processor_id());
print_cpu_stall_info_end();
for_each_possible_cpu(cpu)
totqlen += per_cpu_ptr(rsp->rda, cpu)->qlen;
pr_cont(" (t=%lu jiffies g=%ld c=%ld q=%lu)\n",
jiffies - rsp->gp_start,
(long)rsp->gpnum, (long)rsp->completed, totqlen);
rcu_check_gp_kthread_starvation(rsp);
rcu_dump_cpu_stacks(rsp);
raw_spin_lock_irqsave_rcu_node(rnp, flags);
if (ULONG_CMP_GE(jiffies, READ_ONCE(rsp->jiffies_stall)))
WRITE_ONCE(rsp->jiffies_stall,
jiffies + 3 * rcu_jiffies_till_stall_check() + 3);
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
panic_on_rcu_stall();
resched_cpu(smp_processor_id());
}
static void check_cpu_stall(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long completed;
unsigned long gpnum;
unsigned long gps;
unsigned long j;
unsigned long js;
struct rcu_node *rnp;
if ((rcu_cpu_stall_suppress && !rcu_kick_kthreads) ||
!rcu_gp_in_progress(rsp))
return;
rcu_stall_kick_kthreads(rsp);
j = jiffies;
gpnum = READ_ONCE(rsp->gpnum);
smp_rmb();
js = READ_ONCE(rsp->jiffies_stall);
smp_rmb();
gps = READ_ONCE(rsp->gp_start);
smp_rmb();
completed = READ_ONCE(rsp->completed);
if (ULONG_CMP_GE(completed, gpnum) ||
ULONG_CMP_LT(j, js) ||
ULONG_CMP_GE(gps, js))
return;
rnp = rdp->mynode;
if (rcu_gp_in_progress(rsp) &&
(READ_ONCE(rnp->qsmask) & rdp->grpmask)) {
print_cpu_stall(rsp);
} else if (rcu_gp_in_progress(rsp) &&
ULONG_CMP_GE(j, js + RCU_STALL_RAT_DELAY)) {
print_other_cpu_stall(rsp, gpnum);
}
}
void rcu_cpu_stall_reset(void)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
WRITE_ONCE(rsp->jiffies_stall, jiffies + ULONG_MAX / 2);
}
static void init_default_callback_list(struct rcu_data *rdp)
{
int i;
rdp->nxtlist = NULL;
for (i = 0; i < RCU_NEXT_SIZE; i++)
rdp->nxttail[i] = &rdp->nxtlist;
}
static void init_callback_list(struct rcu_data *rdp)
{
if (init_nocb_callback_list(rdp))
return;
init_default_callback_list(rdp);
}
static unsigned long rcu_cbs_completed(struct rcu_state *rsp,
struct rcu_node *rnp)
{
if (rcu_get_root(rsp) == rnp && rnp->gpnum == rnp->completed)
return rnp->completed + 1;
return rnp->completed + 2;
}
static void trace_rcu_future_gp(struct rcu_node *rnp, struct rcu_data *rdp,
unsigned long c, const char *s)
{
trace_rcu_future_grace_period(rdp->rsp->name, rnp->gpnum,
rnp->completed, c, rnp->level,
rnp->grplo, rnp->grphi, s);
}
static bool __maybe_unused
rcu_start_future_gp(struct rcu_node *rnp, struct rcu_data *rdp,
unsigned long *c_out)
{
unsigned long c;
int i;
bool ret = false;
struct rcu_node *rnp_root = rcu_get_root(rdp->rsp);
c = rcu_cbs_completed(rdp->rsp, rnp);
trace_rcu_future_gp(rnp, rdp, c, TPS("Startleaf"));
if (rnp->need_future_gp[c & 0x1]) {
trace_rcu_future_gp(rnp, rdp, c, TPS("Prestartleaf"));
goto out;
}
if (rnp->gpnum != rnp->completed ||
READ_ONCE(rnp_root->gpnum) != READ_ONCE(rnp_root->completed)) {
rnp->need_future_gp[c & 0x1]++;
trace_rcu_future_gp(rnp, rdp, c, TPS("Startedleaf"));
goto out;
}
if (rnp != rnp_root)
raw_spin_lock_rcu_node(rnp_root);
c = rcu_cbs_completed(rdp->rsp, rnp_root);
for (i = RCU_DONE_TAIL; i < RCU_NEXT_TAIL; i++)
if (ULONG_CMP_LT(c, rdp->nxtcompleted[i]))
rdp->nxtcompleted[i] = c;
if (rnp_root->need_future_gp[c & 0x1]) {
trace_rcu_future_gp(rnp, rdp, c, TPS("Prestartedroot"));
goto unlock_out;
}
rnp_root->need_future_gp[c & 0x1]++;
if (rnp_root->gpnum != rnp_root->completed) {
trace_rcu_future_gp(rnp, rdp, c, TPS("Startedleafroot"));
} else {
trace_rcu_future_gp(rnp, rdp, c, TPS("Startedroot"));
ret = rcu_start_gp_advanced(rdp->rsp, rnp_root, rdp);
}
unlock_out:
if (rnp != rnp_root)
raw_spin_unlock_rcu_node(rnp_root);
out:
if (c_out != NULL)
*c_out = c;
return ret;
}
static int rcu_future_gp_cleanup(struct rcu_state *rsp, struct rcu_node *rnp)
{
int c = rnp->completed;
int needmore;
struct rcu_data *rdp = this_cpu_ptr(rsp->rda);
rnp->need_future_gp[c & 0x1] = 0;
needmore = rnp->need_future_gp[(c + 1) & 0x1];
trace_rcu_future_gp(rnp, rdp, c,
needmore ? TPS("CleanupMore") : TPS("Cleanup"));
return needmore;
}
static void rcu_gp_kthread_wake(struct rcu_state *rsp)
{
if (current == rsp->gp_kthread ||
!READ_ONCE(rsp->gp_flags) ||
!rsp->gp_kthread)
return;
swake_up(&rsp->gp_wq);
}
static bool rcu_accelerate_cbs(struct rcu_state *rsp, struct rcu_node *rnp,
struct rcu_data *rdp)
{
unsigned long c;
int i;
bool ret;
if (!rdp->nxttail[RCU_NEXT_TAIL] || !*rdp->nxttail[RCU_DONE_TAIL])
return false;
c = rcu_cbs_completed(rsp, rnp);
for (i = RCU_NEXT_TAIL - 1; i > RCU_DONE_TAIL; i--)
if (rdp->nxttail[i] != rdp->nxttail[i - 1] &&
!ULONG_CMP_GE(rdp->nxtcompleted[i], c))
break;
if (++i >= RCU_NEXT_TAIL)
return false;
for (; i <= RCU_NEXT_TAIL; i++) {
rdp->nxttail[i] = rdp->nxttail[RCU_NEXT_TAIL];
rdp->nxtcompleted[i] = c;
}
ret = rcu_start_future_gp(rnp, rdp, NULL);
if (!*rdp->nxttail[RCU_WAIT_TAIL])
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("AccWaitCB"));
else
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("AccReadyCB"));
return ret;
}
static bool rcu_advance_cbs(struct rcu_state *rsp, struct rcu_node *rnp,
struct rcu_data *rdp)
{
int i, j;
if (!rdp->nxttail[RCU_NEXT_TAIL] || !*rdp->nxttail[RCU_DONE_TAIL])
return false;
for (i = RCU_WAIT_TAIL; i < RCU_NEXT_TAIL; i++) {
if (ULONG_CMP_LT(rnp->completed, rdp->nxtcompleted[i]))
break;
rdp->nxttail[RCU_DONE_TAIL] = rdp->nxttail[i];
}
for (j = RCU_WAIT_TAIL; j < i; j++)
rdp->nxttail[j] = rdp->nxttail[RCU_DONE_TAIL];
for (j = RCU_WAIT_TAIL; i < RCU_NEXT_TAIL; i++, j++) {
if (rdp->nxttail[j] == rdp->nxttail[RCU_NEXT_TAIL])
break;
rdp->nxttail[j] = rdp->nxttail[i];
rdp->nxtcompleted[j] = rdp->nxtcompleted[i];
}
return rcu_accelerate_cbs(rsp, rnp, rdp);
}
static bool __note_gp_changes(struct rcu_state *rsp, struct rcu_node *rnp,
struct rcu_data *rdp)
{
bool ret;
bool need_gp;
if (rdp->completed == rnp->completed &&
!unlikely(READ_ONCE(rdp->gpwrap))) {
ret = rcu_accelerate_cbs(rsp, rnp, rdp);
} else {
ret = rcu_advance_cbs(rsp, rnp, rdp);
rdp->completed = rnp->completed;
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("cpuend"));
}
if (rdp->gpnum != rnp->gpnum || unlikely(READ_ONCE(rdp->gpwrap))) {
rdp->gpnum = rnp->gpnum;
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("cpustart"));
need_gp = !!(rnp->qsmask & rdp->grpmask);
rdp->cpu_no_qs.b.norm = need_gp;
rdp->rcu_qs_ctr_snap = __this_cpu_read(rcu_qs_ctr);
rdp->core_needs_qs = need_gp;
zero_cpu_stall_ticks(rdp);
WRITE_ONCE(rdp->gpwrap, false);
}
return ret;
}
static void note_gp_changes(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
bool needwake;
struct rcu_node *rnp;
local_irq_save(flags);
rnp = rdp->mynode;
if ((rdp->gpnum == READ_ONCE(rnp->gpnum) &&
rdp->completed == READ_ONCE(rnp->completed) &&
!unlikely(READ_ONCE(rdp->gpwrap))) ||
!raw_spin_trylock_rcu_node(rnp)) {
local_irq_restore(flags);
return;
}
needwake = __note_gp_changes(rsp, rnp, rdp);
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
if (needwake)
rcu_gp_kthread_wake(rsp);
}
static void rcu_gp_slow(struct rcu_state *rsp, int delay)
{
if (delay > 0 &&
!(rsp->gpnum % (rcu_num_nodes * PER_RCU_NODE_PERIOD * delay)))
schedule_timeout_uninterruptible(delay);
}
static bool rcu_gp_init(struct rcu_state *rsp)
{
unsigned long oldmask;
struct rcu_data *rdp;
struct rcu_node *rnp = rcu_get_root(rsp);
WRITE_ONCE(rsp->gp_activity, jiffies);
raw_spin_lock_irq_rcu_node(rnp);
if (!READ_ONCE(rsp->gp_flags)) {
raw_spin_unlock_irq_rcu_node(rnp);
return false;
}
WRITE_ONCE(rsp->gp_flags, 0);
if (WARN_ON_ONCE(rcu_gp_in_progress(rsp))) {
raw_spin_unlock_irq_rcu_node(rnp);
return false;
}
record_gp_stall_check_time(rsp);
smp_store_release(&rsp->gpnum, rsp->gpnum + 1);
trace_rcu_grace_period(rsp->name, rsp->gpnum, TPS("start"));
raw_spin_unlock_irq_rcu_node(rnp);
rcu_for_each_leaf_node(rsp, rnp) {
rcu_gp_slow(rsp, gp_preinit_delay);
raw_spin_lock_irq_rcu_node(rnp);
if (rnp->qsmaskinit == rnp->qsmaskinitnext &&
!rnp->wait_blkd_tasks) {
raw_spin_unlock_irq_rcu_node(rnp);
continue;
}
oldmask = rnp->qsmaskinit;
rnp->qsmaskinit = rnp->qsmaskinitnext;
if (!oldmask != !rnp->qsmaskinit) {
if (!oldmask)
rcu_init_new_rnp(rnp);
else if (rcu_preempt_has_tasks(rnp))
rnp->wait_blkd_tasks = true;
else
rcu_cleanup_dead_rnp(rnp);
}
if (rnp->wait_blkd_tasks &&
(!rcu_preempt_has_tasks(rnp) ||
rnp->qsmaskinit)) {
rnp->wait_blkd_tasks = false;
rcu_cleanup_dead_rnp(rnp);
}
raw_spin_unlock_irq_rcu_node(rnp);
}
rcu_for_each_node_breadth_first(rsp, rnp) {
rcu_gp_slow(rsp, gp_init_delay);
raw_spin_lock_irq_rcu_node(rnp);
rdp = this_cpu_ptr(rsp->rda);
rcu_preempt_check_blocked_tasks(rnp);
rnp->qsmask = rnp->qsmaskinit;
WRITE_ONCE(rnp->gpnum, rsp->gpnum);
if (WARN_ON_ONCE(rnp->completed != rsp->completed))
WRITE_ONCE(rnp->completed, rsp->completed);
if (rnp == rdp->mynode)
(void)__note_gp_changes(rsp, rnp, rdp);
rcu_preempt_boost_start_gp(rnp);
trace_rcu_grace_period_init(rsp->name, rnp->gpnum,
rnp->level, rnp->grplo,
rnp->grphi, rnp->qsmask);
raw_spin_unlock_irq_rcu_node(rnp);
cond_resched_rcu_qs();
WRITE_ONCE(rsp->gp_activity, jiffies);
}
return true;
}
static bool rcu_gp_fqs_check_wake(struct rcu_state *rsp, int *gfp)
{
struct rcu_node *rnp = rcu_get_root(rsp);
*gfp = READ_ONCE(rsp->gp_flags);
if (*gfp & RCU_GP_FLAG_FQS)
return true;
if (!READ_ONCE(rnp->qsmask) && !rcu_preempt_blocked_readers_cgp(rnp))
return true;
return false;
}
static void rcu_gp_fqs(struct rcu_state *rsp, bool first_time)
{
bool isidle = false;
unsigned long maxj;
struct rcu_node *rnp = rcu_get_root(rsp);
WRITE_ONCE(rsp->gp_activity, jiffies);
rsp->n_force_qs++;
if (first_time) {
if (is_sysidle_rcu_state(rsp)) {
isidle = true;
maxj = jiffies - ULONG_MAX / 4;
}
force_qs_rnp(rsp, dyntick_save_progress_counter,
&isidle, &maxj);
rcu_sysidle_report_gp(rsp, isidle, maxj);
} else {
isidle = true;
force_qs_rnp(rsp, rcu_implicit_dynticks_qs, &isidle, &maxj);
}
if (READ_ONCE(rsp->gp_flags) & RCU_GP_FLAG_FQS) {
raw_spin_lock_irq_rcu_node(rnp);
WRITE_ONCE(rsp->gp_flags,
READ_ONCE(rsp->gp_flags) & ~RCU_GP_FLAG_FQS);
raw_spin_unlock_irq_rcu_node(rnp);
}
}
static void rcu_gp_cleanup(struct rcu_state *rsp)
{
unsigned long gp_duration;
bool needgp = false;
int nocb = 0;
struct rcu_data *rdp;
struct rcu_node *rnp = rcu_get_root(rsp);
struct swait_queue_head *sq;
WRITE_ONCE(rsp->gp_activity, jiffies);
raw_spin_lock_irq_rcu_node(rnp);
gp_duration = jiffies - rsp->gp_start;
if (gp_duration > rsp->gp_max)
rsp->gp_max = gp_duration;
raw_spin_unlock_irq_rcu_node(rnp);
rcu_for_each_node_breadth_first(rsp, rnp) {
raw_spin_lock_irq_rcu_node(rnp);
WARN_ON_ONCE(rcu_preempt_blocked_readers_cgp(rnp));
WARN_ON_ONCE(rnp->qsmask);
WRITE_ONCE(rnp->completed, rsp->gpnum);
rdp = this_cpu_ptr(rsp->rda);
if (rnp == rdp->mynode)
needgp = __note_gp_changes(rsp, rnp, rdp) || needgp;
nocb += rcu_future_gp_cleanup(rsp, rnp);
sq = rcu_nocb_gp_get(rnp);
raw_spin_unlock_irq_rcu_node(rnp);
rcu_nocb_gp_cleanup(sq);
cond_resched_rcu_qs();
WRITE_ONCE(rsp->gp_activity, jiffies);
rcu_gp_slow(rsp, gp_cleanup_delay);
}
rnp = rcu_get_root(rsp);
raw_spin_lock_irq_rcu_node(rnp);
rcu_nocb_gp_set(rnp, nocb);
WRITE_ONCE(rsp->completed, rsp->gpnum);
trace_rcu_grace_period(rsp->name, rsp->completed, TPS("end"));
rsp->gp_state = RCU_GP_IDLE;
rdp = this_cpu_ptr(rsp->rda);
needgp = rcu_advance_cbs(rsp, rnp, rdp) || needgp;
if (needgp || cpu_needs_another_gp(rsp, rdp)) {
WRITE_ONCE(rsp->gp_flags, RCU_GP_FLAG_INIT);
trace_rcu_grace_period(rsp->name,
READ_ONCE(rsp->gpnum),
TPS("newreq"));
}
raw_spin_unlock_irq_rcu_node(rnp);
}
static int __noreturn rcu_gp_kthread(void *arg)
{
bool first_gp_fqs;
int gf;
unsigned long j;
int ret;
struct rcu_state *rsp = arg;
struct rcu_node *rnp = rcu_get_root(rsp);
rcu_bind_gp_kthread();
for (;;) {
for (;;) {
trace_rcu_grace_period(rsp->name,
READ_ONCE(rsp->gpnum),
TPS("reqwait"));
rsp->gp_state = RCU_GP_WAIT_GPS;
swait_event_interruptible(rsp->gp_wq,
READ_ONCE(rsp->gp_flags) &
RCU_GP_FLAG_INIT);
rsp->gp_state = RCU_GP_DONE_GPS;
if (rcu_gp_init(rsp))
break;
cond_resched_rcu_qs();
WRITE_ONCE(rsp->gp_activity, jiffies);
WARN_ON(signal_pending(current));
trace_rcu_grace_period(rsp->name,
READ_ONCE(rsp->gpnum),
TPS("reqwaitsig"));
}
first_gp_fqs = true;
j = jiffies_till_first_fqs;
if (j > HZ) {
j = HZ;
jiffies_till_first_fqs = HZ;
}
ret = 0;
for (;;) {
if (!ret) {
rsp->jiffies_force_qs = jiffies + j;
WRITE_ONCE(rsp->jiffies_kick_kthreads,
jiffies + 3 * j);
}
trace_rcu_grace_period(rsp->name,
READ_ONCE(rsp->gpnum),
TPS("fqswait"));
rsp->gp_state = RCU_GP_WAIT_FQS;
ret = swait_event_interruptible_timeout(rsp->gp_wq,
rcu_gp_fqs_check_wake(rsp, &gf), j);
rsp->gp_state = RCU_GP_DOING_FQS;
if (!READ_ONCE(rnp->qsmask) &&
!rcu_preempt_blocked_readers_cgp(rnp))
break;
if (ULONG_CMP_GE(jiffies, rsp->jiffies_force_qs) ||
(gf & RCU_GP_FLAG_FQS)) {
trace_rcu_grace_period(rsp->name,
READ_ONCE(rsp->gpnum),
TPS("fqsstart"));
rcu_gp_fqs(rsp, first_gp_fqs);
first_gp_fqs = false;
trace_rcu_grace_period(rsp->name,
READ_ONCE(rsp->gpnum),
TPS("fqsend"));
cond_resched_rcu_qs();
WRITE_ONCE(rsp->gp_activity, jiffies);
ret = 0;
j = jiffies_till_next_fqs;
if (j > HZ) {
j = HZ;
jiffies_till_next_fqs = HZ;
} else if (j < 1) {
j = 1;
jiffies_till_next_fqs = 1;
}
} else {
cond_resched_rcu_qs();
WRITE_ONCE(rsp->gp_activity, jiffies);
WARN_ON(signal_pending(current));
trace_rcu_grace_period(rsp->name,
READ_ONCE(rsp->gpnum),
TPS("fqswaitsig"));
ret = 1;
j = jiffies;
if (time_after(jiffies, rsp->jiffies_force_qs))
j = 1;
else
j = rsp->jiffies_force_qs - j;
}
}
rsp->gp_state = RCU_GP_CLEANUP;
rcu_gp_cleanup(rsp);
rsp->gp_state = RCU_GP_CLEANED;
}
}
static bool
rcu_start_gp_advanced(struct rcu_state *rsp, struct rcu_node *rnp,
struct rcu_data *rdp)
{
if (!rsp->gp_kthread || !cpu_needs_another_gp(rsp, rdp)) {
return false;
}
WRITE_ONCE(rsp->gp_flags, RCU_GP_FLAG_INIT);
trace_rcu_grace_period(rsp->name, READ_ONCE(rsp->gpnum),
TPS("newreq"));
return true;
}
static bool rcu_start_gp(struct rcu_state *rsp)
{
struct rcu_data *rdp = this_cpu_ptr(rsp->rda);
struct rcu_node *rnp = rcu_get_root(rsp);
bool ret = false;
ret = rcu_advance_cbs(rsp, rnp, rdp) || ret;
ret = rcu_start_gp_advanced(rsp, rnp, rdp) || ret;
return ret;
}
static void rcu_report_qs_rsp(struct rcu_state *rsp, unsigned long flags)
__releases(rcu_get_root(rsp)->lock
static void
rcu_report_qs_rnp(unsigned long mask, struct rcu_state *rsp,
struct rcu_node *rnp, unsigned long gps, unsigned long flags)
__releases(rnp->lock)
{
unsigned long oldmask = 0;
struct rcu_node *rnp_c;
for (;;) {
if (!(rnp->qsmask & mask) || rnp->gpnum != gps) {
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
return;
}
WARN_ON_ONCE(oldmask);
rnp->qsmask &= ~mask;
trace_rcu_quiescent_state_report(rsp->name, rnp->gpnum,
mask, rnp->qsmask, rnp->level,
rnp->grplo, rnp->grphi,
!!rnp->gp_tasks);
if (rnp->qsmask != 0 || rcu_preempt_blocked_readers_cgp(rnp)) {
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
return;
}
mask = rnp->grpmask;
if (rnp->parent == NULL) {
break;
}
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
rnp_c = rnp;
rnp = rnp->parent;
raw_spin_lock_irqsave_rcu_node(rnp, flags);
oldmask = rnp_c->qsmask;
}
rcu_report_qs_rsp(rsp, flags);
}
static void rcu_report_unblock_qs_rnp(struct rcu_state *rsp,
struct rcu_node *rnp, unsigned long flags)
__releases(rnp->lock)
{
unsigned long gps;
unsigned long mask;
struct rcu_node *rnp_p;
if (rcu_state_p == &rcu_sched_state || rsp != rcu_state_p ||
rnp->qsmask != 0 || rcu_preempt_blocked_readers_cgp(rnp)) {
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
return;
}
rnp_p = rnp->parent;
if (rnp_p == NULL) {
rcu_report_qs_rsp(rsp, flags);
return;
}
gps = rnp->gpnum;
mask = rnp->grpmask;
raw_spin_unlock_rcu_node(rnp);
raw_spin_lock_rcu_node(rnp_p);
rcu_report_qs_rnp(mask, rsp, rnp_p, gps, flags);
}
static void
rcu_report_qs_rdp(int cpu, struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
unsigned long mask;
bool needwake;
struct rcu_node *rnp;
rnp = rdp->mynode;
raw_spin_lock_irqsave_rcu_node(rnp, flags);
if (rdp->cpu_no_qs.b.norm || rdp->gpnum != rnp->gpnum ||
rnp->completed == rnp->gpnum || rdp->gpwrap) {
rdp->cpu_no_qs.b.norm = true;
rdp->rcu_qs_ctr_snap = __this_cpu_read(rcu_qs_ctr);
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
return;
}
mask = rdp->grpmask;
if ((rnp->qsmask & mask) == 0) {
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
} else {
rdp->core_needs_qs = false;
needwake = rcu_accelerate_cbs(rsp, rnp, rdp);
rcu_report_qs_rnp(mask, rsp, rnp, rnp->gpnum, flags);
if (needwake)
rcu_gp_kthread_wake(rsp);
}
}
static void
rcu_check_quiescent_state(struct rcu_state *rsp, struct rcu_data *rdp)
{
note_gp_changes(rsp, rdp);
if (!rdp->core_needs_qs)
return;
if (rdp->cpu_no_qs.b.norm)
return;
rcu_report_qs_rdp(rdp->cpu, rsp, rdp);
}
static void
rcu_send_cbs_to_orphanage(int cpu, struct rcu_state *rsp,
struct rcu_node *rnp, struct rcu_data *rdp)
{
if (!IS_ENABLED(CONFIG_HOTPLUG_CPU) || rcu_is_nocb_cpu(rdp->cpu))
return;
if (rdp->nxtlist != NULL) {
rsp->qlen_lazy += rdp->qlen_lazy;
rsp->qlen += rdp->qlen;
rdp->n_cbs_orphaned += rdp->qlen;
rdp->qlen_lazy = 0;
WRITE_ONCE(rdp->qlen, 0);
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
rdp->nxttail[RCU_NEXT_TAIL] = NULL;
}
static void rcu_adopt_orphan_cbs(struct rcu_state *rsp, unsigned long flags)
{
int i;
struct rcu_data *rdp = raw_cpu_ptr(rsp->rda);
if (!IS_ENABLED(CONFIG_HOTPLUG_CPU) ||
rcu_nocb_adopt_orphan_cbs(rsp, rdp, flags))
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
if (!IS_ENABLED(CONFIG_HOTPLUG_CPU))
return;
RCU_TRACE(mask = rdp->grpmask);
trace_rcu_grace_period(rsp->name,
rnp->gpnum + 1 - !!(rnp->qsmask & mask),
TPS("cpuofl"));
}
static void rcu_cleanup_dead_rnp(struct rcu_node *rnp_leaf)
{
long mask;
struct rcu_node *rnp = rnp_leaf;
if (!IS_ENABLED(CONFIG_HOTPLUG_CPU) ||
rnp->qsmaskinit || rcu_preempt_has_tasks(rnp))
return;
for (;;) {
mask = rnp->grpmask;
rnp = rnp->parent;
if (!rnp)
break;
raw_spin_lock_rcu_node(rnp);
rnp->qsmaskinit &= ~mask;
rnp->qsmask &= ~mask;
if (rnp->qsmaskinit) {
raw_spin_unlock_rcu_node(rnp);
return;
}
raw_spin_unlock_rcu_node(rnp);
}
}
static void rcu_cleanup_dead_cpu(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rdp->mynode;
if (!IS_ENABLED(CONFIG_HOTPLUG_CPU))
return;
rcu_boost_kthread_setaffinity(rnp, -1);
raw_spin_lock_irqsave(&rsp->orphan_lock, flags);
rcu_send_cbs_to_orphanage(cpu, rsp, rnp, rdp);
rcu_adopt_orphan_cbs(rsp, flags);
raw_spin_unlock_irqrestore(&rsp->orphan_lock, flags);
WARN_ONCE(rdp->qlen != 0 || rdp->nxtlist != NULL,
"rcu_cleanup_dead_cpu: Callbacks on offline CPU %d: qlen=%lu, nxtlist=%p\n",
cpu, rdp->qlen, rdp->nxtlist);
}
static void rcu_do_batch(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
struct rcu_head *next, *list, **tail;
long bl, count, count_lazy;
int i;
if (!cpu_has_callbacks_ready_to_invoke(rdp)) {
trace_rcu_batch_start(rsp->name, rdp->qlen_lazy, rdp->qlen, 0);
trace_rcu_batch_end(rsp->name, 0, !!READ_ONCE(rdp->nxtlist),
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
WRITE_ONCE(rdp->qlen, rdp->qlen - count);
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
void rcu_check_callbacks(int user)
{
trace_rcu_utilization(TPS("Start scheduler-tick"));
increment_cpu_stall_ticks();
if (user || rcu_is_cpu_rrupt_from_idle()) {
rcu_sched_qs();
rcu_bh_qs();
} else if (!in_softirq()) {
rcu_bh_qs();
}
rcu_preempt_check_callbacks();
if (rcu_pending())
invoke_rcu_core();
if (user)
rcu_note_voluntary_context_switch(current);
trace_rcu_utilization(TPS("End scheduler-tick"));
}
static void force_qs_rnp(struct rcu_state *rsp,
int (*f)(struct rcu_data *rsp, bool *isidle,
unsigned long *maxj),
bool *isidle, unsigned long *maxj)
{
int cpu;
unsigned long flags;
unsigned long mask;
struct rcu_node *rnp;
rcu_for_each_leaf_node(rsp, rnp) {
cond_resched_rcu_qs();
mask = 0;
raw_spin_lock_irqsave_rcu_node(rnp, flags);
if (rnp->qsmask == 0) {
if (rcu_state_p == &rcu_sched_state ||
rsp != rcu_state_p ||
rcu_preempt_blocked_readers_cgp(rnp)) {
rcu_initiate_boost(rnp, flags);
continue;
}
if (rnp->parent &&
(rnp->parent->qsmask & rnp->grpmask)) {
rcu_report_unblock_qs_rnp(rsp, rnp, flags);
continue;
}
}
for_each_leaf_node_possible_cpu(rnp, cpu) {
unsigned long bit = leaf_node_cpu_bit(rnp, cpu);
if ((rnp->qsmask & bit) != 0) {
if (f(per_cpu_ptr(rsp->rda, cpu), isidle, maxj))
mask |= bit;
}
}
if (mask != 0) {
rcu_report_qs_rnp(mask, rsp, rnp, rnp->gpnum, flags);
} else {
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
}
}
}
static void force_quiescent_state(struct rcu_state *rsp)
{
unsigned long flags;
bool ret;
struct rcu_node *rnp;
struct rcu_node *rnp_old = NULL;
rnp = __this_cpu_read(rsp->rda->mynode);
for (; rnp != NULL; rnp = rnp->parent) {
ret = (READ_ONCE(rsp->gp_flags) & RCU_GP_FLAG_FQS) ||
!raw_spin_trylock(&rnp->fqslock);
if (rnp_old != NULL)
raw_spin_unlock(&rnp_old->fqslock);
if (ret) {
rsp->n_force_qs_lh++;
return;
}
rnp_old = rnp;
}
raw_spin_lock_irqsave_rcu_node(rnp_old, flags);
raw_spin_unlock(&rnp_old->fqslock);
if (READ_ONCE(rsp->gp_flags) & RCU_GP_FLAG_FQS) {
rsp->n_force_qs_lh++;
raw_spin_unlock_irqrestore_rcu_node(rnp_old, flags);
return;
}
WRITE_ONCE(rsp->gp_flags, READ_ONCE(rsp->gp_flags) | RCU_GP_FLAG_FQS);
raw_spin_unlock_irqrestore_rcu_node(rnp_old, flags);
rcu_gp_kthread_wake(rsp);
}
static void
__rcu_process_callbacks(struct rcu_state *rsp)
{
unsigned long flags;
bool needwake;
struct rcu_data *rdp = raw_cpu_ptr(rsp->rda);
WARN_ON_ONCE(rdp->beenonline == 0);
rcu_check_quiescent_state(rsp, rdp);
local_irq_save(flags);
if (cpu_needs_another_gp(rsp, rdp)) {
raw_spin_lock_rcu_node(rcu_get_root(rsp));
needwake = rcu_start_gp(rsp);
raw_spin_unlock_irqrestore_rcu_node(rcu_get_root(rsp), flags);
if (needwake)
rcu_gp_kthread_wake(rsp);
} else {
local_irq_restore(flags);
}
if (cpu_has_callbacks_ready_to_invoke(rdp))
invoke_rcu_callbacks(rsp, rdp);
do_nocb_deferred_wakeup(rdp);
}
static __latent_entropy void rcu_process_callbacks(struct softirq_action *unused)
{
struct rcu_state *rsp;
if (cpu_is_offline(smp_processor_id()))
return;
trace_rcu_utilization(TPS("Start RCU core"));
for_each_rcu_flavor(rsp)
__rcu_process_callbacks(rsp);
trace_rcu_utilization(TPS("End RCU core"));
}
static void invoke_rcu_callbacks(struct rcu_state *rsp, struct rcu_data *rdp)
{
if (unlikely(!READ_ONCE(rcu_scheduler_fully_active)))
return;
if (likely(!rsp->boost)) {
rcu_do_batch(rsp, rdp);
return;
}
invoke_rcu_callbacks_kthread();
}
static void invoke_rcu_core(void)
{
if (cpu_online(smp_processor_id()))
raise_softirq(RCU_SOFTIRQ);
}
static void __call_rcu_core(struct rcu_state *rsp, struct rcu_data *rdp,
struct rcu_head *head, unsigned long flags)
{
bool needwake;
if (!rcu_is_watching())
invoke_rcu_core();
if (irqs_disabled_flags(flags) || cpu_is_offline(smp_processor_id()))
return;
if (unlikely(rdp->qlen > rdp->qlen_last_fqs_check + qhimark)) {
note_gp_changes(rsp, rdp);
if (!rcu_gp_in_progress(rsp)) {
struct rcu_node *rnp_root = rcu_get_root(rsp);
raw_spin_lock_rcu_node(rnp_root);
needwake = rcu_start_gp(rsp);
raw_spin_unlock_rcu_node(rnp_root);
if (needwake)
rcu_gp_kthread_wake(rsp);
} else {
rdp->blimit = LONG_MAX;
if (rsp->n_force_qs == rdp->n_force_qs_snap &&
*rdp->nxttail[RCU_DONE_TAIL] != head)
force_quiescent_state(rsp);
rdp->n_force_qs_snap = rsp->n_force_qs;
rdp->qlen_last_fqs_check = rdp->qlen;
}
}
}
static void rcu_leak_callback(struct rcu_head *rhp)
{
}
static void
__call_rcu(struct rcu_head *head, rcu_callback_t func,
struct rcu_state *rsp, int cpu, bool lazy)
{
unsigned long flags;
struct rcu_data *rdp;
WARN_ON_ONCE((unsigned long)head & (sizeof(void *) - 1));
if (debug_rcu_head_queue(head)) {
WRITE_ONCE(head->func, rcu_leak_callback);
WARN_ONCE(1, "__call_rcu(): Leaked duplicate callback\n");
return;
}
head->func = func;
head->next = NULL;
local_irq_save(flags);
rdp = this_cpu_ptr(rsp->rda);
if (unlikely(rdp->nxttail[RCU_NEXT_TAIL] == NULL) || cpu != -1) {
int offline;
if (cpu != -1)
rdp = per_cpu_ptr(rsp->rda, cpu);
if (likely(rdp->mynode)) {
offline = !__call_rcu_nocb(rdp, head, lazy, flags);
WARN_ON_ONCE(offline);
local_irq_restore(flags);
return;
}
BUG_ON(cpu != -1);
WARN_ON_ONCE(!rcu_is_watching());
if (!likely(rdp->nxtlist))
init_default_callback_list(rdp);
}
WRITE_ONCE(rdp->qlen, rdp->qlen + 1);
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
void call_rcu_sched(struct rcu_head *head, rcu_callback_t func)
{
__call_rcu(head, func, &rcu_sched_state, -1, 0);
}
void call_rcu_bh(struct rcu_head *head, rcu_callback_t func)
{
__call_rcu(head, func, &rcu_bh_state, -1, 0);
}
void kfree_call_rcu(struct rcu_head *head,
rcu_callback_t func)
{
__call_rcu(head, func, rcu_state_p, -1, 1);
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
RCU_LOCKDEP_WARN(lock_is_held(&rcu_bh_lock_map) ||
lock_is_held(&rcu_lock_map) ||
lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_sched() in RCU-sched read-side critical section");
if (rcu_blocking_is_gp())
return;
if (rcu_gp_is_expedited())
synchronize_sched_expedited();
else
wait_rcu_gp(call_rcu_sched);
}
void synchronize_rcu_bh(void)
{
RCU_LOCKDEP_WARN(lock_is_held(&rcu_bh_lock_map) ||
lock_is_held(&rcu_lock_map) ||
lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_rcu_bh() in RCU-bh read-side critical section");
if (rcu_blocking_is_gp())
return;
if (rcu_gp_is_expedited())
synchronize_rcu_bh_expedited();
else
wait_rcu_gp(call_rcu_bh);
}
unsigned long get_state_synchronize_rcu(void)
{
smp_mb();
return smp_load_acquire(&rcu_state_p->gpnum);
}
void cond_synchronize_rcu(unsigned long oldstate)
{
unsigned long newstate;
newstate = smp_load_acquire(&rcu_state_p->completed);
if (ULONG_CMP_GE(oldstate, newstate))
synchronize_rcu();
}
unsigned long get_state_synchronize_sched(void)
{
smp_mb();
return smp_load_acquire(&rcu_sched_state.gpnum);
}
void cond_synchronize_sched(unsigned long oldstate)
{
unsigned long newstate;
newstate = smp_load_acquire(&rcu_sched_state.completed);
if (ULONG_CMP_GE(oldstate, newstate))
synchronize_sched();
}
static void rcu_seq_start(unsigned long *sp)
{
WRITE_ONCE(*sp, *sp + 1);
smp_mb();
WARN_ON_ONCE(!(*sp & 0x1));
}
static void rcu_seq_end(unsigned long *sp)
{
smp_mb();
WRITE_ONCE(*sp, *sp + 1);
WARN_ON_ONCE(*sp & 0x1);
}
static unsigned long rcu_seq_snap(unsigned long *sp)
{
unsigned long s;
s = (READ_ONCE(*sp) + 3) & ~0x1;
smp_mb();
return s;
}
static bool rcu_seq_done(unsigned long *sp, unsigned long s)
{
return ULONG_CMP_GE(READ_ONCE(*sp), s);
}
static int __rcu_pending(struct rcu_state *rsp, struct rcu_data *rdp)
{
struct rcu_node *rnp = rdp->mynode;
rdp->n_rcu_pending++;
check_cpu_stall(rsp, rdp);
if (rcu_nohz_full_cpu(rsp))
return 0;
if (rcu_scheduler_fully_active &&
rdp->core_needs_qs && rdp->cpu_no_qs.b.norm &&
rdp->rcu_qs_ctr_snap == __this_cpu_read(rcu_qs_ctr)) {
rdp->n_rp_core_needs_qs++;
} else if (rdp->core_needs_qs && !rdp->cpu_no_qs.b.norm) {
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
if (READ_ONCE(rnp->completed) != rdp->completed) {
rdp->n_rp_gp_completed++;
return 1;
}
if (READ_ONCE(rnp->gpnum) != rdp->gpnum ||
unlikely(READ_ONCE(rdp->gpwrap))) {
rdp->n_rp_gp_started++;
return 1;
}
if (rcu_nocb_need_deferred_wakeup(rdp)) {
rdp->n_rp_nocb_defer_wakeup++;
return 1;
}
rdp->n_rp_need_nothing++;
return 0;
}
static int rcu_pending(void)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
if (__rcu_pending(rsp, this_cpu_ptr(rsp->rda)))
return 1;
return 0;
}
static bool __maybe_unused rcu_cpu_has_callbacks(bool *all_lazy)
{
bool al = true;
bool hc = false;
struct rcu_data *rdp;
struct rcu_state *rsp;
for_each_rcu_flavor(rsp) {
rdp = this_cpu_ptr(rsp->rda);
if (!rdp->nxtlist)
continue;
hc = true;
if (rdp->qlen != rdp->qlen_lazy || !all_lazy) {
al = false;
break;
}
}
if (all_lazy)
*all_lazy = al;
return hc;
}
static void _rcu_barrier_trace(struct rcu_state *rsp, const char *s,
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
_rcu_barrier_trace(rsp, "LastCB", -1, rsp->barrier_sequence);
complete(&rsp->barrier_completion);
} else {
_rcu_barrier_trace(rsp, "CB", -1, rsp->barrier_sequence);
}
}
static void rcu_barrier_func(void *type)
{
struct rcu_state *rsp = type;
struct rcu_data *rdp = raw_cpu_ptr(rsp->rda);
_rcu_barrier_trace(rsp, "IRQ", -1, rsp->barrier_sequence);
atomic_inc(&rsp->barrier_cpu_count);
rsp->call(&rdp->barrier_head, rcu_barrier_callback);
}
static void _rcu_barrier(struct rcu_state *rsp)
{
int cpu;
struct rcu_data *rdp;
unsigned long s = rcu_seq_snap(&rsp->barrier_sequence);
_rcu_barrier_trace(rsp, "Begin", -1, s);
mutex_lock(&rsp->barrier_mutex);
if (rcu_seq_done(&rsp->barrier_sequence, s)) {
_rcu_barrier_trace(rsp, "EarlyExit", -1, rsp->barrier_sequence);
smp_mb();
mutex_unlock(&rsp->barrier_mutex);
return;
}
rcu_seq_start(&rsp->barrier_sequence);
_rcu_barrier_trace(rsp, "Inc1", -1, rsp->barrier_sequence);
init_completion(&rsp->barrier_completion);
atomic_set(&rsp->barrier_cpu_count, 1);
get_online_cpus();
for_each_possible_cpu(cpu) {
if (!cpu_online(cpu) && !rcu_is_nocb_cpu(cpu))
continue;
rdp = per_cpu_ptr(rsp->rda, cpu);
if (rcu_is_nocb_cpu(cpu)) {
if (!rcu_nocb_cpu_needs_barrier(rsp, cpu)) {
_rcu_barrier_trace(rsp, "OfflineNoCB", cpu,
rsp->barrier_sequence);
} else {
_rcu_barrier_trace(rsp, "OnlineNoCB", cpu,
rsp->barrier_sequence);
smp_mb__before_atomic();
atomic_inc(&rsp->barrier_cpu_count);
__call_rcu(&rdp->barrier_head,
rcu_barrier_callback, rsp, cpu, 0);
}
} else if (READ_ONCE(rdp->qlen)) {
_rcu_barrier_trace(rsp, "OnlineQ", cpu,
rsp->barrier_sequence);
smp_call_function_single(cpu, rcu_barrier_func, rsp, 1);
} else {
_rcu_barrier_trace(rsp, "OnlineNQ", cpu,
rsp->barrier_sequence);
}
}
put_online_cpus();
if (atomic_dec_and_test(&rsp->barrier_cpu_count))
complete(&rsp->barrier_completion);
wait_for_completion(&rsp->barrier_completion);
_rcu_barrier_trace(rsp, "Inc2", -1, rsp->barrier_sequence);
rcu_seq_end(&rsp->barrier_sequence);
mutex_unlock(&rsp->barrier_mutex);
}
void rcu_barrier_bh(void)
{
_rcu_barrier(&rcu_bh_state);
}
void rcu_barrier_sched(void)
{
_rcu_barrier(&rcu_sched_state);
}
static void rcu_init_new_rnp(struct rcu_node *rnp_leaf)
{
long mask;
struct rcu_node *rnp = rnp_leaf;
for (;;) {
mask = rnp->grpmask;
rnp = rnp->parent;
if (rnp == NULL)
return;
raw_spin_lock_rcu_node(rnp);
rnp->qsmaskinit |= mask;
raw_spin_unlock_rcu_node(rnp);
}
}
static void __init
rcu_boot_init_percpu_data(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave_rcu_node(rnp, flags);
rdp->grpmask = leaf_node_cpu_bit(rdp->mynode, cpu);
rdp->dynticks = &per_cpu(rcu_dynticks, cpu);
WARN_ON_ONCE(rdp->dynticks->dynticks_nesting != DYNTICK_TASK_EXIT_IDLE);
WARN_ON_ONCE(rcu_dynticks_in_eqs(rcu_dynticks_snap(rdp->dynticks)));
rdp->cpu = cpu;
rdp->rsp = rsp;
rcu_boot_init_nocb_percpu_data(rdp);
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
}
static void
rcu_init_percpu_data(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave_rcu_node(rnp, flags);
rdp->qlen_last_fqs_check = 0;
rdp->n_force_qs_snap = rsp->n_force_qs;
rdp->blimit = blimit;
if (!rdp->nxtlist)
init_callback_list(rdp);
rdp->dynticks->dynticks_nesting = DYNTICK_TASK_EXIT_IDLE;
rcu_sysidle_init_percpu_data(rdp->dynticks);
rcu_dynticks_eqs_online();
raw_spin_unlock_rcu_node(rnp);
rnp = rdp->mynode;
raw_spin_lock_rcu_node(rnp);
if (!rdp->beenonline)
WRITE_ONCE(rsp->ncpus, READ_ONCE(rsp->ncpus) + 1);
rdp->beenonline = true;
rdp->gpnum = rnp->completed;
rdp->completed = rnp->completed;
rdp->cpu_no_qs.b.norm = true;
rdp->rcu_qs_ctr_snap = per_cpu(rcu_qs_ctr, cpu);
rdp->core_needs_qs = false;
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("cpuonl"));
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
}
int rcutree_prepare_cpu(unsigned int cpu)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
rcu_init_percpu_data(cpu, rsp);
rcu_prepare_kthreads(cpu);
rcu_spawn_all_nocb_kthreads(cpu);
return 0;
}
static void rcutree_affinity_setting(unsigned int cpu, int outgoing)
{
struct rcu_data *rdp = per_cpu_ptr(rcu_state_p->rda, cpu);
rcu_boost_kthread_setaffinity(rdp->mynode, outgoing);
}
int rcutree_online_cpu(unsigned int cpu)
{
sync_sched_exp_online_cleanup(cpu);
rcutree_affinity_setting(cpu, -1);
return 0;
}
int rcutree_offline_cpu(unsigned int cpu)
{
rcutree_affinity_setting(cpu, cpu);
return 0;
}
int rcutree_dying_cpu(unsigned int cpu)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
rcu_cleanup_dying_cpu(rsp);
return 0;
}
int rcutree_dead_cpu(unsigned int cpu)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp) {
rcu_cleanup_dead_cpu(cpu, rsp);
do_nocb_deferred_wakeup(per_cpu_ptr(rsp->rda, cpu));
}
return 0;
}
void rcu_cpu_starting(unsigned int cpu)
{
unsigned long flags;
unsigned long mask;
struct rcu_data *rdp;
struct rcu_node *rnp;
struct rcu_state *rsp;
for_each_rcu_flavor(rsp) {
rdp = per_cpu_ptr(rsp->rda, cpu);
rnp = rdp->mynode;
mask = rdp->grpmask;
raw_spin_lock_irqsave_rcu_node(rnp, flags);
rnp->qsmaskinitnext |= mask;
rnp->expmaskinitnext |= mask;
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
}
}
static void rcu_cleanup_dying_idle_cpu(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
unsigned long mask;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rdp->mynode;
mask = rdp->grpmask;
raw_spin_lock_irqsave_rcu_node(rnp, flags);
rnp->qsmaskinitnext &= ~mask;
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
}
void rcu_report_dead(unsigned int cpu)
{
struct rcu_state *rsp;
preempt_disable();
rcu_report_exp_rdp(&rcu_sched_state,
this_cpu_ptr(rcu_sched_state.rda), true);
preempt_enable();
for_each_rcu_flavor(rsp)
rcu_cleanup_dying_idle_cpu(cpu, rsp);
}
static int rcu_pm_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action) {
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
if (nr_cpu_ids <= 256)
rcu_expedite_gp();
break;
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
if (nr_cpu_ids <= 256)
rcu_unexpedite_gp();
break;
default:
break;
}
return NOTIFY_OK;
}
static int __init rcu_spawn_gp_kthread(void)
{
unsigned long flags;
int kthread_prio_in = kthread_prio;
struct rcu_node *rnp;
struct rcu_state *rsp;
struct sched_param sp;
struct task_struct *t;
if (IS_ENABLED(CONFIG_RCU_BOOST) && kthread_prio < 1)
kthread_prio = 1;
else if (kthread_prio < 0)
kthread_prio = 0;
else if (kthread_prio > 99)
kthread_prio = 99;
if (kthread_prio != kthread_prio_in)
pr_alert("rcu_spawn_gp_kthread(): Limited prio to %d from %d\n",
kthread_prio, kthread_prio_in);
rcu_scheduler_fully_active = 1;
for_each_rcu_flavor(rsp) {
t = kthread_create(rcu_gp_kthread, rsp, "%s", rsp->name);
BUG_ON(IS_ERR(t));
rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave_rcu_node(rnp, flags);
rsp->gp_kthread = t;
if (kthread_prio) {
sp.sched_priority = kthread_prio;
sched_setscheduler_nocheck(t, SCHED_FIFO, &sp);
}
raw_spin_unlock_irqrestore_rcu_node(rnp, flags);
wake_up_process(t);
}
rcu_spawn_nocb_kthreads();
rcu_spawn_boost_kthreads();
return 0;
}
void rcu_scheduler_starting(void)
{
WARN_ON(num_online_cpus() != 1);
WARN_ON(nr_context_switches() > 0);
rcu_test_sync_prims();
rcu_scheduler_active = RCU_SCHEDULER_INIT;
rcu_test_sync_prims();
}
static void __init rcu_init_levelspread(int *levelspread, const int *levelcnt)
{
int i;
if (rcu_fanout_exact) {
levelspread[rcu_num_lvls - 1] = rcu_fanout_leaf;
for (i = rcu_num_lvls - 2; i >= 0; i--)
levelspread[i] = RCU_FANOUT;
} else {
int ccur;
int cprv;
cprv = nr_cpu_ids;
for (i = rcu_num_lvls - 1; i >= 0; i--) {
ccur = levelcnt[i];
levelspread[i] = (cprv + ccur - 1) / ccur;
cprv = ccur;
}
}
}
static void __init rcu_init_one(struct rcu_state *rsp)
{
static const char * const buf[] = RCU_NODE_NAME_INIT;
static const char * const fqs[] = RCU_FQS_NAME_INIT;
static struct lock_class_key rcu_node_class[RCU_NUM_LVLS];
static struct lock_class_key rcu_fqs_class[RCU_NUM_LVLS];
static u8 fl_mask = 0x1;
int levelcnt[RCU_NUM_LVLS];
int levelspread[RCU_NUM_LVLS];
int cpustride = 1;
int i;
int j;
struct rcu_node *rnp;
BUILD_BUG_ON(RCU_NUM_LVLS > ARRAY_SIZE(buf));
if (rcu_num_lvls <= 0 || rcu_num_lvls > RCU_NUM_LVLS)
panic("rcu_init_one: rcu_num_lvls out of range");
for (i = 0; i < rcu_num_lvls; i++)
levelcnt[i] = num_rcu_lvl[i];
for (i = 1; i < rcu_num_lvls; i++)
rsp->level[i] = rsp->level[i - 1] + levelcnt[i - 1];
rcu_init_levelspread(levelspread, levelcnt);
rsp->flavor_mask = fl_mask;
fl_mask <<= 1;
for (i = rcu_num_lvls - 1; i >= 0; i--) {
cpustride *= levelspread[i];
rnp = rsp->level[i];
for (j = 0; j < levelcnt[i]; j++, rnp++) {
raw_spin_lock_init(&ACCESS_PRIVATE(rnp, lock));
lockdep_set_class_and_name(&ACCESS_PRIVATE(rnp, lock),
&rcu_node_class[i], buf[i]);
raw_spin_lock_init(&rnp->fqslock);
lockdep_set_class_and_name(&rnp->fqslock,
&rcu_fqs_class[i], fqs[i]);
rnp->gpnum = rsp->gpnum;
rnp->completed = rsp->completed;
rnp->qsmask = 0;
rnp->qsmaskinit = 0;
rnp->grplo = j * cpustride;
rnp->grphi = (j + 1) * cpustride - 1;
if (rnp->grphi >= nr_cpu_ids)
rnp->grphi = nr_cpu_ids - 1;
if (i == 0) {
rnp->grpnum = 0;
rnp->grpmask = 0;
rnp->parent = NULL;
} else {
rnp->grpnum = j % levelspread[i - 1];
rnp->grpmask = 1UL << rnp->grpnum;
rnp->parent = rsp->level[i - 1] +
j / levelspread[i - 1];
}
rnp->level = i;
INIT_LIST_HEAD(&rnp->blkd_tasks);
rcu_init_one_nocb(rnp);
init_waitqueue_head(&rnp->exp_wq[0]);
init_waitqueue_head(&rnp->exp_wq[1]);
init_waitqueue_head(&rnp->exp_wq[2]);
init_waitqueue_head(&rnp->exp_wq[3]);
spin_lock_init(&rnp->exp_lock);
}
}
init_swait_queue_head(&rsp->gp_wq);
init_swait_queue_head(&rsp->expedited_wq);
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
ulong d;
int i;
int rcu_capacity[RCU_NUM_LVLS];
d = RCU_JIFFIES_TILL_FORCE_QS + nr_cpu_ids / RCU_JIFFIES_FQS_DIV;
if (jiffies_till_first_fqs == ULONG_MAX)
jiffies_till_first_fqs = d;
if (jiffies_till_next_fqs == ULONG_MAX)
jiffies_till_next_fqs = d;
if (rcu_fanout_leaf == RCU_FANOUT_LEAF &&
nr_cpu_ids == NR_CPUS)
return;
pr_info("RCU: Adjusting geometry for rcu_fanout_leaf=%d, nr_cpu_ids=%d\n",
rcu_fanout_leaf, nr_cpu_ids);
if (rcu_fanout_leaf < 2 ||
rcu_fanout_leaf > sizeof(unsigned long) * 8) {
rcu_fanout_leaf = RCU_FANOUT_LEAF;
WARN_ON(1);
return;
}
rcu_capacity[0] = rcu_fanout_leaf;
for (i = 1; i < RCU_NUM_LVLS; i++)
rcu_capacity[i] = rcu_capacity[i - 1] * RCU_FANOUT;
if (nr_cpu_ids > rcu_capacity[RCU_NUM_LVLS - 1]) {
rcu_fanout_leaf = RCU_FANOUT_LEAF;
WARN_ON(1);
return;
}
for (i = 0; nr_cpu_ids > rcu_capacity[i]; i++) {
}
rcu_num_lvls = i + 1;
for (i = 0; i < rcu_num_lvls; i++) {
int cap = rcu_capacity[(rcu_num_lvls - 1) - i];
num_rcu_lvl[i] = DIV_ROUND_UP(nr_cpu_ids, cap);
}
rcu_num_nodes = 0;
for (i = 0; i < rcu_num_lvls; i++)
rcu_num_nodes += num_rcu_lvl[i];
}
static void __init rcu_dump_rcu_node_tree(struct rcu_state *rsp)
{
int level = 0;
struct rcu_node *rnp;
pr_info("rcu_node tree layout dump\n");
pr_info(" ");
rcu_for_each_node_breadth_first(rsp, rnp) {
if (rnp->level != level) {
pr_cont("\n");
pr_info(" ");
level = rnp->level;
}
pr_cont("%d:%d ^%d ", rnp->grplo, rnp->grphi, rnp->grpnum);
}
pr_cont("\n");
}
void __init rcu_init(void)
{
int cpu;
rcu_early_boot_tests();
rcu_bootup_announce();
rcu_init_geometry();
rcu_init_one(&rcu_bh_state);
rcu_init_one(&rcu_sched_state);
if (dump_tree)
rcu_dump_rcu_node_tree(&rcu_sched_state);
__rcu_init_preempt();
open_softirq(RCU_SOFTIRQ, rcu_process_callbacks);
pm_notifier(rcu_pm_notify, 0);
for_each_online_cpu(cpu) {
rcutree_prepare_cpu(cpu);
rcu_cpu_starting(cpu);
}
}
