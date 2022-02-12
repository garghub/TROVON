static int rcu_gp_in_progress(struct rcu_state *rsp)
{
return ACCESS_ONCE(rsp->completed) != ACCESS_ONCE(rsp->gpnum);
}
void rcu_sched_qs(void)
{
if (!__this_cpu_read(rcu_sched_data.passed_quiesce)) {
trace_rcu_grace_period(TPS("rcu_sched"),
__this_cpu_read(rcu_sched_data.gpnum),
TPS("cpuqs"));
__this_cpu_write(rcu_sched_data.passed_quiesce, 1);
}
}
void rcu_bh_qs(void)
{
if (!__this_cpu_read(rcu_bh_data.passed_quiesce)) {
trace_rcu_grace_period(TPS("rcu_bh"),
__this_cpu_read(rcu_bh_data.gpnum),
TPS("cpuqs"));
__this_cpu_write(rcu_bh_data.passed_quiesce, 1);
}
}
static void rcu_momentary_dyntick_idle(void)
{
unsigned long flags;
struct rcu_data *rdp;
struct rcu_dynticks *rdtp;
int resched_mask;
struct rcu_state *rsp;
local_irq_save(flags);
resched_mask = raw_cpu_read(rcu_sched_qs_mask);
raw_cpu_write(rcu_sched_qs_mask, 0);
for_each_rcu_flavor(rsp) {
rdp = raw_cpu_ptr(rsp->rda);
if (!(resched_mask & rsp->flavor_mask))
continue;
smp_mb();
if (ACCESS_ONCE(rdp->mynode->completed) !=
ACCESS_ONCE(rdp->cond_resched_completed))
continue;
rdtp = this_cpu_ptr(&rcu_dynticks);
smp_mb__before_atomic();
atomic_add(2, &rdtp->dynticks);
smp_mb__after_atomic();
break;
}
local_irq_restore(flags);
}
void rcu_note_context_switch(void)
{
trace_rcu_utilization(TPS("Start context switch"));
rcu_sched_qs();
rcu_preempt_note_context_switch();
if (unlikely(raw_cpu_read(rcu_sched_qs_mask)))
rcu_momentary_dyntick_idle();
trace_rcu_utilization(TPS("End context switch"));
}
void rcu_all_qs(void)
{
if (unlikely(raw_cpu_read(rcu_sched_qs_mask)))
rcu_momentary_dyntick_idle();
this_cpu_inc(rcu_qs_ctr);
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
void rcu_force_quiescent_state(void)
{
force_quiescent_state(rcu_state_p);
}
void rcu_bh_force_quiescent_state(void)
{
force_quiescent_state(&rcu_bh_state);
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
*flags = ACCESS_ONCE(rsp->gp_flags);
*gpnum = ACCESS_ONCE(rsp->gpnum);
*completed = ACCESS_ONCE(rsp->completed);
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
void rcu_sched_force_quiescent_state(void)
{
force_quiescent_state(&rcu_sched_state);
}
static int
cpu_has_callbacks_ready_to_invoke(struct rcu_data *rdp)
{
return &rdp->nxtlist != rdp->nxttail[RCU_DONE_TAIL] &&
rdp->nxttail[RCU_DONE_TAIL] != NULL;
}
static struct rcu_node *rcu_get_root(struct rcu_state *rsp)
{
return &rsp->node[0];
}
static int rcu_future_needs_gp(struct rcu_state *rsp)
{
struct rcu_node *rnp = rcu_get_root(rsp);
int idx = (ACCESS_ONCE(rnp->completed) + 1) & 0x1;
int *fp = &rnp->need_future_gp[idx];
return ACCESS_ONCE(*fp);
}
static int
cpu_needs_another_gp(struct rcu_state *rsp, struct rcu_data *rdp)
{
int i;
if (rcu_gp_in_progress(rsp))
return 0;
if (rcu_future_needs_gp(rsp))
return 1;
if (!rdp->nxttail[RCU_NEXT_TAIL])
return 0;
if (*rdp->nxttail[RCU_NEXT_READY_TAIL])
return 1;
for (i = RCU_WAIT_TAIL; i < RCU_NEXT_TAIL; i++)
if (rdp->nxttail[i - 1] != rdp->nxttail[i] &&
ULONG_CMP_LT(ACCESS_ONCE(rsp->completed),
rdp->nxtcompleted[i]))
return 1;
return 0;
}
static void rcu_eqs_enter_common(long long oldval, bool user)
{
struct rcu_state *rsp;
struct rcu_data *rdp;
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
trace_rcu_dyntick(TPS("Start"), oldval, rdtp->dynticks_nesting);
if (!user && !is_idle_task(current)) {
struct task_struct *idle __maybe_unused =
idle_task(smp_processor_id());
trace_rcu_dyntick(TPS("Error on entry: not idle task"), oldval, 0);
ftrace_dump(DUMP_ORIG);
WARN_ONCE(1, "Current pid: %d comm: %s / Idle pid: %d comm: %s",
current->pid, current->comm,
idle->pid, idle->comm);
}
for_each_rcu_flavor(rsp) {
rdp = this_cpu_ptr(rsp->rda);
do_nocb_deferred_wakeup(rdp);
}
rcu_prepare_for_idle();
smp_mb__before_atomic();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic();
WARN_ON_ONCE(atomic_read(&rdtp->dynticks) & 0x1);
rcu_dynticks_task_enter();
rcu_lockdep_assert(!lock_is_held(&rcu_lock_map),
"Illegal idle entry in RCU read-side critical section.");
rcu_lockdep_assert(!lock_is_held(&rcu_bh_lock_map),
"Illegal idle entry in RCU-bh read-side critical section.");
rcu_lockdep_assert(!lock_is_held(&rcu_sched_lock_map),
"Illegal idle entry in RCU-sched read-side critical section.");
}
static void rcu_eqs_enter(bool user)
{
long long oldval;
struct rcu_dynticks *rdtp;
rdtp = this_cpu_ptr(&rcu_dynticks);
oldval = rdtp->dynticks_nesting;
WARN_ON_ONCE((oldval & DYNTICK_TASK_NEST_MASK) == 0);
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
unsigned long flags;
long long oldval;
struct rcu_dynticks *rdtp;
local_irq_save(flags);
rdtp = this_cpu_ptr(&rcu_dynticks);
oldval = rdtp->dynticks_nesting;
rdtp->dynticks_nesting--;
WARN_ON_ONCE(rdtp->dynticks_nesting < 0);
if (rdtp->dynticks_nesting)
trace_rcu_dyntick(TPS("--="), oldval, rdtp->dynticks_nesting);
else
rcu_eqs_enter_common(oldval, true);
rcu_sysidle_enter(1);
local_irq_restore(flags);
}
static void rcu_eqs_exit_common(long long oldval, int user)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
rcu_dynticks_task_exit();
smp_mb__before_atomic();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic();
WARN_ON_ONCE(!(atomic_read(&rdtp->dynticks) & 0x1));
rcu_cleanup_after_idle();
trace_rcu_dyntick(TPS("End"), oldval, rdtp->dynticks_nesting);
if (!user && !is_idle_task(current)) {
struct task_struct *idle __maybe_unused =
idle_task(smp_processor_id());
trace_rcu_dyntick(TPS("Error on exit: not idle task"),
oldval, rdtp->dynticks_nesting);
ftrace_dump(DUMP_ORIG);
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
WARN_ON_ONCE(oldval < 0);
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
unsigned long flags;
struct rcu_dynticks *rdtp;
long long oldval;
local_irq_save(flags);
rdtp = this_cpu_ptr(&rcu_dynticks);
oldval = rdtp->dynticks_nesting;
rdtp->dynticks_nesting++;
WARN_ON_ONCE(rdtp->dynticks_nesting == 0);
if (oldval)
trace_rcu_dyntick(TPS("++="), oldval, rdtp->dynticks_nesting);
else
rcu_eqs_exit_common(oldval, true);
rcu_sysidle_exit(1);
local_irq_restore(flags);
}
void rcu_nmi_enter(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
int incby = 2;
WARN_ON_ONCE(rdtp->dynticks_nmi_nesting < 0);
if (!(atomic_read(&rdtp->dynticks) & 0x1)) {
smp_mb__before_atomic();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic();
WARN_ON_ONCE(!(atomic_read(&rdtp->dynticks) & 0x1));
incby = 1;
}
rdtp->dynticks_nmi_nesting += incby;
barrier();
}
void rcu_nmi_exit(void)
{
struct rcu_dynticks *rdtp = this_cpu_ptr(&rcu_dynticks);
WARN_ON_ONCE(rdtp->dynticks_nmi_nesting <= 0);
WARN_ON_ONCE(!(atomic_read(&rdtp->dynticks) & 0x1));
if (rdtp->dynticks_nmi_nesting != 1) {
rdtp->dynticks_nmi_nesting -= 2;
return;
}
rdtp->dynticks_nmi_nesting = 0;
smp_mb__before_atomic();
atomic_inc(&rdtp->dynticks);
smp_mb__after_atomic();
WARN_ON_ONCE(atomic_read(&rdtp->dynticks) & 0x1);
}
bool notrace __rcu_is_watching(void)
{
return atomic_read(this_cpu_ptr(&rcu_dynticks.dynticks)) & 0x1;
}
bool notrace rcu_is_watching(void)
{
bool ret;
preempt_disable();
ret = __rcu_is_watching();
preempt_enable();
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
ret = (rdp->grpmask & rnp->qsmaskinit) ||
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
rdp->dynticks_snap = atomic_add_return(0, &rdp->dynticks->dynticks);
rcu_sysidle_check_cpu(rdp, isidle, maxj);
if ((rdp->dynticks_snap & 0x1) == 0) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, TPS("dti"));
return 1;
} else {
if (ULONG_CMP_LT(ACCESS_ONCE(rdp->gpnum) + ULONG_MAX / 4,
rdp->mynode->gpnum))
ACCESS_ONCE(rdp->gpwrap) = true;
return 0;
}
}
static int rcu_implicit_dynticks_qs(struct rcu_data *rdp,
bool *isidle, unsigned long *maxj)
{
unsigned int curr;
int *rcrmp;
unsigned int snap;
curr = (unsigned int)atomic_add_return(0, &rdp->dynticks->dynticks);
snap = (unsigned int)rdp->dynticks_snap;
if ((curr & 0x1) == 0 || UINT_CMP_GE(curr, snap + 2)) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, TPS("dti"));
rdp->dynticks_fqs++;
return 1;
}
if (ULONG_CMP_GE(rdp->rsp->gp_start + 2, jiffies))
return 0;
barrier();
if (cpu_is_offline(rdp->cpu)) {
trace_rcu_fqs(rdp->rsp->name, rdp->gpnum, rdp->cpu, TPS("ofl"));
rdp->offline_fqs++;
return 1;
}
rcrmp = &per_cpu(rcu_sched_qs_mask, rdp->cpu);
if (ULONG_CMP_GE(jiffies,
rdp->rsp->gp_start + jiffies_till_sched_qs) ||
ULONG_CMP_GE(jiffies, rdp->rsp->jiffies_resched)) {
if (!(ACCESS_ONCE(*rcrmp) & rdp->rsp->flavor_mask)) {
ACCESS_ONCE(rdp->cond_resched_completed) =
ACCESS_ONCE(rdp->mynode->completed);
smp_mb();
ACCESS_ONCE(*rcrmp) =
ACCESS_ONCE(*rcrmp) + rdp->rsp->flavor_mask;
resched_cpu(rdp->cpu);
rdp->rsp->jiffies_resched += 5;
} else if (ULONG_CMP_GE(jiffies, rdp->rsp->jiffies_resched)) {
resched_cpu(rdp->cpu);
rdp->rsp->jiffies_resched += 5;
}
}
return 0;
}
static void record_gp_stall_check_time(struct rcu_state *rsp)
{
unsigned long j = jiffies;
unsigned long j1;
rsp->gp_start = j;
smp_wmb();
j1 = rcu_jiffies_till_stall_check();
ACCESS_ONCE(rsp->jiffies_stall) = j + j1;
rsp->jiffies_resched = j + j1 / 2;
rsp->n_force_qs_gpstart = ACCESS_ONCE(rsp->n_force_qs);
}
static void rcu_check_gp_kthread_starvation(struct rcu_state *rsp)
{
unsigned long gpa;
unsigned long j;
j = jiffies;
gpa = ACCESS_ONCE(rsp->gp_activity);
if (j - gpa > 2 * HZ)
pr_err("%s kthread starved for %ld jiffies!\n",
rsp->name, j - gpa);
}
static void rcu_dump_cpu_stacks(struct rcu_state *rsp)
{
int cpu;
unsigned long flags;
struct rcu_node *rnp;
rcu_for_each_leaf_node(rsp, rnp) {
raw_spin_lock_irqsave(&rnp->lock, flags);
if (rnp->qsmask != 0) {
for (cpu = 0; cpu <= rnp->grphi - rnp->grplo; cpu++)
if (rnp->qsmask & (1UL << cpu))
dump_cpu_task(rnp->grplo + cpu);
}
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
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
raw_spin_lock_irqsave(&rnp->lock, flags);
delta = jiffies - ACCESS_ONCE(rsp->jiffies_stall);
if (delta < RCU_STALL_RAT_DELAY || !rcu_gp_in_progress(rsp)) {
raw_spin_unlock_irqrestore(&rnp->lock, flags);
return;
}
ACCESS_ONCE(rsp->jiffies_stall) = jiffies + 3 * rcu_jiffies_till_stall_check() + 3;
raw_spin_unlock_irqrestore(&rnp->lock, flags);
pr_err("INFO: %s detected stalls on CPUs/tasks:",
rsp->name);
print_cpu_stall_info_begin();
rcu_for_each_leaf_node(rsp, rnp) {
raw_spin_lock_irqsave(&rnp->lock, flags);
ndetected += rcu_print_task_stall(rnp);
if (rnp->qsmask != 0) {
for (cpu = 0; cpu <= rnp->grphi - rnp->grplo; cpu++)
if (rnp->qsmask & (1UL << cpu)) {
print_cpu_stall_info(rsp,
rnp->grplo + cpu);
ndetected++;
}
}
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
print_cpu_stall_info_end();
for_each_possible_cpu(cpu)
totqlen += per_cpu_ptr(rsp->rda, cpu)->qlen;
pr_cont("(detected by %d, t=%ld jiffies, g=%ld, c=%ld, q=%lu)\n",
smp_processor_id(), (long)(jiffies - rsp->gp_start),
(long)rsp->gpnum, (long)rsp->completed, totqlen);
if (ndetected) {
rcu_dump_cpu_stacks(rsp);
} else {
if (ACCESS_ONCE(rsp->gpnum) != gpnum ||
ACCESS_ONCE(rsp->completed) == gpnum) {
pr_err("INFO: Stall ended before state dump start\n");
} else {
j = jiffies;
gpa = ACCESS_ONCE(rsp->gp_activity);
pr_err("All QSes seen, last %s kthread activity %ld (%ld-%ld), jiffies_till_next_fqs=%ld\n",
rsp->name, j - gpa, j, gpa,
jiffies_till_next_fqs);
sched_show_task(current);
}
}
rcu_print_detail_task_stall(rsp);
rcu_check_gp_kthread_starvation(rsp);
force_quiescent_state(rsp);
}
static void print_cpu_stall(struct rcu_state *rsp)
{
int cpu;
unsigned long flags;
struct rcu_node *rnp = rcu_get_root(rsp);
long totqlen = 0;
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
raw_spin_lock_irqsave(&rnp->lock, flags);
if (ULONG_CMP_GE(jiffies, ACCESS_ONCE(rsp->jiffies_stall)))
ACCESS_ONCE(rsp->jiffies_stall) = jiffies +
3 * rcu_jiffies_till_stall_check() + 3;
raw_spin_unlock_irqrestore(&rnp->lock, flags);
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
if (rcu_cpu_stall_suppress || !rcu_gp_in_progress(rsp))
return;
j = jiffies;
gpnum = ACCESS_ONCE(rsp->gpnum);
smp_rmb();
js = ACCESS_ONCE(rsp->jiffies_stall);
smp_rmb();
gps = ACCESS_ONCE(rsp->gp_start);
smp_rmb();
completed = ACCESS_ONCE(rsp->completed);
if (ULONG_CMP_GE(completed, gpnum) ||
ULONG_CMP_LT(j, js) ||
ULONG_CMP_GE(gps, js))
return;
rnp = rdp->mynode;
if (rcu_gp_in_progress(rsp) &&
(ACCESS_ONCE(rnp->qsmask) & rdp->grpmask)) {
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
ACCESS_ONCE(rsp->jiffies_stall) = jiffies + ULONG_MAX / 2;
}
static void init_callback_list(struct rcu_data *rdp)
{
int i;
if (init_nocb_callback_list(rdp))
return;
rdp->nxtlist = NULL;
for (i = 0; i < RCU_NEXT_SIZE; i++)
rdp->nxttail[i] = &rdp->nxtlist;
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
ACCESS_ONCE(rnp_root->gpnum) != ACCESS_ONCE(rnp_root->completed)) {
rnp->need_future_gp[c & 0x1]++;
trace_rcu_future_gp(rnp, rdp, c, TPS("Startedleaf"));
goto out;
}
if (rnp != rnp_root) {
raw_spin_lock(&rnp_root->lock);
smp_mb__after_unlock_lock();
}
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
raw_spin_unlock(&rnp_root->lock);
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
rcu_nocb_gp_cleanup(rsp, rnp);
rnp->need_future_gp[c & 0x1] = 0;
needmore = rnp->need_future_gp[(c + 1) & 0x1];
trace_rcu_future_gp(rnp, rdp, c,
needmore ? TPS("CleanupMore") : TPS("Cleanup"));
return needmore;
}
static void rcu_gp_kthread_wake(struct rcu_state *rsp)
{
if (current == rsp->gp_kthread ||
!ACCESS_ONCE(rsp->gp_flags) ||
!rsp->gp_kthread)
return;
wake_up(&rsp->gp_wq);
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
if (rdp->completed == rnp->completed &&
!unlikely(ACCESS_ONCE(rdp->gpwrap))) {
ret = rcu_accelerate_cbs(rsp, rnp, rdp);
} else {
ret = rcu_advance_cbs(rsp, rnp, rdp);
rdp->completed = rnp->completed;
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("cpuend"));
}
if (rdp->gpnum != rnp->gpnum || unlikely(ACCESS_ONCE(rdp->gpwrap))) {
rdp->gpnum = rnp->gpnum;
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("cpustart"));
rdp->passed_quiesce = 0;
rdp->rcu_qs_ctr_snap = __this_cpu_read(rcu_qs_ctr);
rdp->qs_pending = !!(rnp->qsmask & rdp->grpmask);
zero_cpu_stall_ticks(rdp);
ACCESS_ONCE(rdp->gpwrap) = false;
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
if ((rdp->gpnum == ACCESS_ONCE(rnp->gpnum) &&
rdp->completed == ACCESS_ONCE(rnp->completed) &&
!unlikely(ACCESS_ONCE(rdp->gpwrap))) ||
!raw_spin_trylock(&rnp->lock)) {
local_irq_restore(flags);
return;
}
smp_mb__after_unlock_lock();
needwake = __note_gp_changes(rsp, rnp, rdp);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
if (needwake)
rcu_gp_kthread_wake(rsp);
}
static int rcu_gp_init(struct rcu_state *rsp)
{
struct rcu_data *rdp;
struct rcu_node *rnp = rcu_get_root(rsp);
ACCESS_ONCE(rsp->gp_activity) = jiffies;
rcu_bind_gp_kthread();
raw_spin_lock_irq(&rnp->lock);
smp_mb__after_unlock_lock();
if (!ACCESS_ONCE(rsp->gp_flags)) {
raw_spin_unlock_irq(&rnp->lock);
return 0;
}
ACCESS_ONCE(rsp->gp_flags) = 0;
if (WARN_ON_ONCE(rcu_gp_in_progress(rsp))) {
raw_spin_unlock_irq(&rnp->lock);
return 0;
}
record_gp_stall_check_time(rsp);
smp_store_release(&rsp->gpnum, rsp->gpnum + 1);
trace_rcu_grace_period(rsp->name, rsp->gpnum, TPS("start"));
raw_spin_unlock_irq(&rnp->lock);
mutex_lock(&rsp->onoff_mutex);
smp_mb__after_unlock_lock();
rcu_for_each_node_breadth_first(rsp, rnp) {
raw_spin_lock_irq(&rnp->lock);
smp_mb__after_unlock_lock();
rdp = this_cpu_ptr(rsp->rda);
rcu_preempt_check_blocked_tasks(rnp);
rnp->qsmask = rnp->qsmaskinit;
ACCESS_ONCE(rnp->gpnum) = rsp->gpnum;
WARN_ON_ONCE(rnp->completed != rsp->completed);
ACCESS_ONCE(rnp->completed) = rsp->completed;
if (rnp == rdp->mynode)
(void)__note_gp_changes(rsp, rnp, rdp);
rcu_preempt_boost_start_gp(rnp);
trace_rcu_grace_period_init(rsp->name, rnp->gpnum,
rnp->level, rnp->grplo,
rnp->grphi, rnp->qsmask);
raw_spin_unlock_irq(&rnp->lock);
cond_resched_rcu_qs();
ACCESS_ONCE(rsp->gp_activity) = jiffies;
}
mutex_unlock(&rsp->onoff_mutex);
return 1;
}
static int rcu_gp_fqs(struct rcu_state *rsp, int fqs_state_in)
{
int fqs_state = fqs_state_in;
bool isidle = false;
unsigned long maxj;
struct rcu_node *rnp = rcu_get_root(rsp);
ACCESS_ONCE(rsp->gp_activity) = jiffies;
rsp->n_force_qs++;
if (fqs_state == RCU_SAVE_DYNTICK) {
if (is_sysidle_rcu_state(rsp)) {
isidle = true;
maxj = jiffies - ULONG_MAX / 4;
}
force_qs_rnp(rsp, dyntick_save_progress_counter,
&isidle, &maxj);
rcu_sysidle_report_gp(rsp, isidle, maxj);
fqs_state = RCU_FORCE_QS;
} else {
isidle = false;
force_qs_rnp(rsp, rcu_implicit_dynticks_qs, &isidle, &maxj);
}
if (ACCESS_ONCE(rsp->gp_flags) & RCU_GP_FLAG_FQS) {
raw_spin_lock_irq(&rnp->lock);
smp_mb__after_unlock_lock();
ACCESS_ONCE(rsp->gp_flags) =
ACCESS_ONCE(rsp->gp_flags) & ~RCU_GP_FLAG_FQS;
raw_spin_unlock_irq(&rnp->lock);
}
return fqs_state;
}
static void rcu_gp_cleanup(struct rcu_state *rsp)
{
unsigned long gp_duration;
bool needgp = false;
int nocb = 0;
struct rcu_data *rdp;
struct rcu_node *rnp = rcu_get_root(rsp);
ACCESS_ONCE(rsp->gp_activity) = jiffies;
raw_spin_lock_irq(&rnp->lock);
smp_mb__after_unlock_lock();
gp_duration = jiffies - rsp->gp_start;
if (gp_duration > rsp->gp_max)
rsp->gp_max = gp_duration;
raw_spin_unlock_irq(&rnp->lock);
rcu_for_each_node_breadth_first(rsp, rnp) {
raw_spin_lock_irq(&rnp->lock);
smp_mb__after_unlock_lock();
ACCESS_ONCE(rnp->completed) = rsp->gpnum;
rdp = this_cpu_ptr(rsp->rda);
if (rnp == rdp->mynode)
needgp = __note_gp_changes(rsp, rnp, rdp) || needgp;
nocb += rcu_future_gp_cleanup(rsp, rnp);
raw_spin_unlock_irq(&rnp->lock);
cond_resched_rcu_qs();
ACCESS_ONCE(rsp->gp_activity) = jiffies;
}
rnp = rcu_get_root(rsp);
raw_spin_lock_irq(&rnp->lock);
smp_mb__after_unlock_lock();
rcu_nocb_gp_set(rnp, nocb);
ACCESS_ONCE(rsp->completed) = rsp->gpnum;
trace_rcu_grace_period(rsp->name, rsp->completed, TPS("end"));
rsp->fqs_state = RCU_GP_IDLE;
rdp = this_cpu_ptr(rsp->rda);
needgp = rcu_advance_cbs(rsp, rnp, rdp) || needgp;
if (needgp || cpu_needs_another_gp(rsp, rdp)) {
ACCESS_ONCE(rsp->gp_flags) = RCU_GP_FLAG_INIT;
trace_rcu_grace_period(rsp->name,
ACCESS_ONCE(rsp->gpnum),
TPS("newreq"));
}
raw_spin_unlock_irq(&rnp->lock);
}
static int __noreturn rcu_gp_kthread(void *arg)
{
int fqs_state;
int gf;
unsigned long j;
int ret;
struct rcu_state *rsp = arg;
struct rcu_node *rnp = rcu_get_root(rsp);
for (;;) {
for (;;) {
trace_rcu_grace_period(rsp->name,
ACCESS_ONCE(rsp->gpnum),
TPS("reqwait"));
rsp->gp_state = RCU_GP_WAIT_GPS;
wait_event_interruptible(rsp->gp_wq,
ACCESS_ONCE(rsp->gp_flags) &
RCU_GP_FLAG_INIT);
if (rcu_gp_init(rsp))
break;
cond_resched_rcu_qs();
ACCESS_ONCE(rsp->gp_activity) = jiffies;
WARN_ON(signal_pending(current));
trace_rcu_grace_period(rsp->name,
ACCESS_ONCE(rsp->gpnum),
TPS("reqwaitsig"));
}
fqs_state = RCU_SAVE_DYNTICK;
j = jiffies_till_first_fqs;
if (j > HZ) {
j = HZ;
jiffies_till_first_fqs = HZ;
}
ret = 0;
for (;;) {
if (!ret)
rsp->jiffies_force_qs = jiffies + j;
trace_rcu_grace_period(rsp->name,
ACCESS_ONCE(rsp->gpnum),
TPS("fqswait"));
rsp->gp_state = RCU_GP_WAIT_FQS;
ret = wait_event_interruptible_timeout(rsp->gp_wq,
((gf = ACCESS_ONCE(rsp->gp_flags)) &
RCU_GP_FLAG_FQS) ||
(!ACCESS_ONCE(rnp->qsmask) &&
!rcu_preempt_blocked_readers_cgp(rnp)),
j);
if (!ACCESS_ONCE(rnp->qsmask) &&
!rcu_preempt_blocked_readers_cgp(rnp))
break;
if (ULONG_CMP_GE(jiffies, rsp->jiffies_force_qs) ||
(gf & RCU_GP_FLAG_FQS)) {
trace_rcu_grace_period(rsp->name,
ACCESS_ONCE(rsp->gpnum),
TPS("fqsstart"));
fqs_state = rcu_gp_fqs(rsp, fqs_state);
trace_rcu_grace_period(rsp->name,
ACCESS_ONCE(rsp->gpnum),
TPS("fqsend"));
cond_resched_rcu_qs();
ACCESS_ONCE(rsp->gp_activity) = jiffies;
} else {
cond_resched_rcu_qs();
ACCESS_ONCE(rsp->gp_activity) = jiffies;
WARN_ON(signal_pending(current));
trace_rcu_grace_period(rsp->name,
ACCESS_ONCE(rsp->gpnum),
TPS("fqswaitsig"));
}
j = jiffies_till_next_fqs;
if (j > HZ) {
j = HZ;
jiffies_till_next_fqs = HZ;
} else if (j < 1) {
j = 1;
jiffies_till_next_fqs = 1;
}
}
rcu_gp_cleanup(rsp);
}
}
static bool
rcu_start_gp_advanced(struct rcu_state *rsp, struct rcu_node *rnp,
struct rcu_data *rdp)
{
if (!rsp->gp_kthread || !cpu_needs_another_gp(rsp, rdp)) {
return false;
}
ACCESS_ONCE(rsp->gp_flags) = RCU_GP_FLAG_INIT;
trace_rcu_grace_period(rsp->name, ACCESS_ONCE(rsp->gpnum),
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
smp_mb__after_unlock_lock();
WARN_ON_ONCE(rnp_c->qsmask);
}
rcu_report_qs_rsp(rsp, flags);
}
static void
rcu_report_qs_rdp(int cpu, struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
unsigned long mask;
bool needwake;
struct rcu_node *rnp;
rnp = rdp->mynode;
raw_spin_lock_irqsave(&rnp->lock, flags);
smp_mb__after_unlock_lock();
if ((rdp->passed_quiesce == 0 &&
rdp->rcu_qs_ctr_snap == __this_cpu_read(rcu_qs_ctr)) ||
rdp->gpnum != rnp->gpnum || rnp->completed == rnp->gpnum ||
rdp->gpwrap) {
rdp->passed_quiesce = 0;
rdp->rcu_qs_ctr_snap = __this_cpu_read(rcu_qs_ctr);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
return;
}
mask = rdp->grpmask;
if ((rnp->qsmask & mask) == 0) {
raw_spin_unlock_irqrestore(&rnp->lock, flags);
} else {
rdp->qs_pending = 0;
needwake = rcu_accelerate_cbs(rsp, rnp, rdp);
rcu_report_qs_rnp(mask, rsp, rnp, flags);
if (needwake)
rcu_gp_kthread_wake(rsp);
}
}
static void
rcu_check_quiescent_state(struct rcu_state *rsp, struct rcu_data *rdp)
{
note_gp_changes(rsp, rdp);
if (!rdp->qs_pending)
return;
if (!rdp->passed_quiesce &&
rdp->rcu_qs_ctr_snap == __this_cpu_read(rcu_qs_ctr))
return;
rcu_report_qs_rdp(rdp->cpu, rsp, rdp);
}
static void
rcu_send_cbs_to_orphanage(int cpu, struct rcu_state *rsp,
struct rcu_node *rnp, struct rcu_data *rdp)
{
if (rcu_is_nocb_cpu(rdp->cpu))
return;
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
static void rcu_adopt_orphan_cbs(struct rcu_state *rsp, unsigned long flags)
{
int i;
struct rcu_data *rdp = raw_cpu_ptr(rsp->rda);
if (rcu_nocb_adopt_orphan_cbs(rsp, rdp, flags))
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
TPS("cpuofl"));
}
static void rcu_cleanup_dead_rnp(struct rcu_node *rnp_leaf)
{
long mask;
struct rcu_node *rnp = rnp_leaf;
if (rnp->qsmaskinit || rcu_preempt_has_tasks(rnp))
return;
for (;;) {
mask = rnp->grpmask;
rnp = rnp->parent;
if (!rnp)
break;
raw_spin_lock(&rnp->lock);
smp_mb__after_unlock_lock();
rnp->qsmaskinit &= ~mask;
if (rnp->qsmaskinit) {
raw_spin_unlock(&rnp->lock);
return;
}
raw_spin_unlock(&rnp->lock);
}
}
static void rcu_cleanup_dead_cpu(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rdp->mynode;
rcu_boost_kthread_setaffinity(rnp, -1);
mutex_lock(&rsp->onoff_mutex);
raw_spin_lock_irqsave(&rsp->orphan_lock, flags);
rcu_send_cbs_to_orphanage(cpu, rsp, rnp, rdp);
rcu_adopt_orphan_cbs(rsp, flags);
raw_spin_unlock_irqrestore(&rsp->orphan_lock, flags);
raw_spin_lock_irqsave(&rnp->lock, flags);
smp_mb__after_unlock_lock();
rnp->qsmaskinit &= ~rdp->grpmask;
if (rnp->qsmaskinit == 0 && !rcu_preempt_has_tasks(rnp))
rcu_cleanup_dead_rnp(rnp);
rcu_report_qs_rnp(rdp->grpmask, rsp, rnp, flags);
WARN_ONCE(rdp->qlen != 0 || rdp->nxtlist != NULL,
"rcu_cleanup_dead_cpu: Callbacks on offline CPU %d: qlen=%lu, nxtlist=%p\n",
cpu, rdp->qlen, rdp->nxtlist);
init_callback_list(rdp);
rdp->nxttail[RCU_NEXT_TAIL] = NULL;
mutex_unlock(&rsp->onoff_mutex);
}
static void rcu_cleanup_dying_cpu(struct rcu_state *rsp)
{
}
static void __maybe_unused rcu_cleanup_dead_rnp(struct rcu_node *rnp_leaf)
{
}
static void rcu_cleanup_dead_cpu(int cpu, struct rcu_state *rsp)
{
}
static void rcu_do_batch(struct rcu_state *rsp, struct rcu_data *rdp)
{
unsigned long flags;
struct rcu_head *next, *list, **tail;
long bl, count, count_lazy;
int i;
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
ACCESS_ONCE(rdp->qlen) = rdp->qlen - count;
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
unsigned long bit;
int cpu;
unsigned long flags;
unsigned long mask;
struct rcu_node *rnp;
rcu_for_each_leaf_node(rsp, rnp) {
cond_resched_rcu_qs();
mask = 0;
raw_spin_lock_irqsave(&rnp->lock, flags);
smp_mb__after_unlock_lock();
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
if ((rnp->qsmask & bit) != 0) {
if ((rnp->qsmaskinit & bit) != 0)
*isidle = false;
if (f(per_cpu_ptr(rsp->rda, cpu), isidle, maxj))
mask |= bit;
}
}
if (mask != 0) {
rcu_report_qs_rnp(mask, rsp, rnp, flags);
continue;
}
raw_spin_unlock_irqrestore(&rnp->lock, flags);
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
ret = (ACCESS_ONCE(rsp->gp_flags) & RCU_GP_FLAG_FQS) ||
!raw_spin_trylock(&rnp->fqslock);
if (rnp_old != NULL)
raw_spin_unlock(&rnp_old->fqslock);
if (ret) {
rsp->n_force_qs_lh++;
return;
}
rnp_old = rnp;
}
raw_spin_lock_irqsave(&rnp_old->lock, flags);
smp_mb__after_unlock_lock();
raw_spin_unlock(&rnp_old->fqslock);
if (ACCESS_ONCE(rsp->gp_flags) & RCU_GP_FLAG_FQS) {
rsp->n_force_qs_lh++;
raw_spin_unlock_irqrestore(&rnp_old->lock, flags);
return;
}
ACCESS_ONCE(rsp->gp_flags) =
ACCESS_ONCE(rsp->gp_flags) | RCU_GP_FLAG_FQS;
raw_spin_unlock_irqrestore(&rnp_old->lock, flags);
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
raw_spin_lock(&rcu_get_root(rsp)->lock);
needwake = rcu_start_gp(rsp);
raw_spin_unlock_irqrestore(&rcu_get_root(rsp)->lock, flags);
if (needwake)
rcu_gp_kthread_wake(rsp);
} else {
local_irq_restore(flags);
}
if (cpu_has_callbacks_ready_to_invoke(rdp))
invoke_rcu_callbacks(rsp, rdp);
do_nocb_deferred_wakeup(rdp);
}
static void rcu_process_callbacks(struct softirq_action *unused)
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
if (cpu_online(smp_processor_id()))
raise_softirq(RCU_SOFTIRQ);
}
static void __call_rcu_core(struct rcu_state *rsp, struct rcu_data *rdp,
struct rcu_head *head, unsigned long flags)
{
bool needwake;
if (!rcu_is_watching() && cpu_online(smp_processor_id()))
invoke_rcu_core();
if (irqs_disabled_flags(flags) || cpu_is_offline(smp_processor_id()))
return;
if (unlikely(rdp->qlen > rdp->qlen_last_fqs_check + qhimark)) {
note_gp_changes(rsp, rdp);
if (!rcu_gp_in_progress(rsp)) {
struct rcu_node *rnp_root = rcu_get_root(rsp);
raw_spin_lock(&rnp_root->lock);
smp_mb__after_unlock_lock();
needwake = rcu_start_gp(rsp);
raw_spin_unlock(&rnp_root->lock);
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
__call_rcu(struct rcu_head *head, void (*func)(struct rcu_head *rcu),
struct rcu_state *rsp, int cpu, bool lazy)
{
unsigned long flags;
struct rcu_data *rdp;
WARN_ON_ONCE((unsigned long)head & 0x1);
if (debug_rcu_head_queue(head)) {
ACCESS_ONCE(head->func) = rcu_leak_callback;
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
offline = !__call_rcu_nocb(rdp, head, lazy, flags);
WARN_ON_ONCE(offline);
local_irq_restore(flags);
return;
}
ACCESS_ONCE(rdp->qlen) = rdp->qlen + 1;
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
__call_rcu(head, func, &rcu_sched_state, -1, 0);
}
void call_rcu_bh(struct rcu_head *head, void (*func)(struct rcu_head *rcu))
{
__call_rcu(head, func, &rcu_bh_state, -1, 0);
}
void kfree_call_rcu(struct rcu_head *head,
void (*func)(struct rcu_head *rcu))
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
rcu_lockdep_assert(!lock_is_held(&rcu_bh_lock_map) &&
!lock_is_held(&rcu_lock_map) &&
!lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_sched() in RCU-sched read-side critical section");
if (rcu_blocking_is_gp())
return;
if (rcu_expedited)
synchronize_sched_expedited();
else
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
if (rcu_expedited)
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
static int synchronize_sched_expedited_cpu_stop(void *data)
{
smp_mb();
return 0;
}
void synchronize_sched_expedited(void)
{
cpumask_var_t cm;
bool cma = false;
int cpu;
long firstsnap, s, snap;
int trycount = 0;
struct rcu_state *rsp = &rcu_sched_state;
if (ULONG_CMP_GE((ulong)atomic_long_read(&rsp->expedited_start),
(ulong)atomic_long_read(&rsp->expedited_done) +
ULONG_MAX / 8)) {
synchronize_sched();
atomic_long_inc(&rsp->expedited_wrap);
return;
}
snap = atomic_long_inc_return(&rsp->expedited_start);
firstsnap = snap;
if (!try_get_online_cpus()) {
wait_rcu_gp(call_rcu_sched);
atomic_long_inc(&rsp->expedited_normal);
return;
}
WARN_ON_ONCE(cpu_is_offline(raw_smp_processor_id()));
cma = zalloc_cpumask_var(&cm, GFP_KERNEL);
if (cma) {
cpumask_copy(cm, cpu_online_mask);
cpumask_clear_cpu(raw_smp_processor_id(), cm);
for_each_cpu(cpu, cm) {
struct rcu_dynticks *rdtp = &per_cpu(rcu_dynticks, cpu);
if (!(atomic_add_return(0, &rdtp->dynticks) & 0x1))
cpumask_clear_cpu(cpu, cm);
}
if (cpumask_weight(cm) == 0)
goto all_cpus_idle;
}
while (try_stop_cpus(cma ? cm : cpu_online_mask,
synchronize_sched_expedited_cpu_stop,
NULL) == -EAGAIN) {
put_online_cpus();
atomic_long_inc(&rsp->expedited_tryfail);
s = atomic_long_read(&rsp->expedited_done);
if (ULONG_CMP_GE((ulong)s, (ulong)firstsnap)) {
smp_mb__before_atomic();
atomic_long_inc(&rsp->expedited_workdone1);
free_cpumask_var(cm);
return;
}
if (trycount++ < 10) {
udelay(trycount * num_online_cpus());
} else {
wait_rcu_gp(call_rcu_sched);
atomic_long_inc(&rsp->expedited_normal);
free_cpumask_var(cm);
return;
}
s = atomic_long_read(&rsp->expedited_done);
if (ULONG_CMP_GE((ulong)s, (ulong)firstsnap)) {
smp_mb__before_atomic();
atomic_long_inc(&rsp->expedited_workdone2);
free_cpumask_var(cm);
return;
}
if (!try_get_online_cpus()) {
wait_rcu_gp(call_rcu_sched);
atomic_long_inc(&rsp->expedited_normal);
free_cpumask_var(cm);
return;
}
snap = atomic_long_read(&rsp->expedited_start);
smp_mb();
}
atomic_long_inc(&rsp->expedited_stoppedcpus);
all_cpus_idle:
free_cpumask_var(cm);
do {
atomic_long_inc(&rsp->expedited_done_tries);
s = atomic_long_read(&rsp->expedited_done);
if (ULONG_CMP_GE((ulong)s, (ulong)snap)) {
smp_mb__before_atomic();
atomic_long_inc(&rsp->expedited_done_lost);
break;
}
} while (atomic_long_cmpxchg(&rsp->expedited_done, s, snap) != s);
atomic_long_inc(&rsp->expedited_done_exit);
put_online_cpus();
}
static int __rcu_pending(struct rcu_state *rsp, struct rcu_data *rdp)
{
struct rcu_node *rnp = rdp->mynode;
rdp->n_rcu_pending++;
check_cpu_stall(rsp, rdp);
if (rcu_nohz_full_cpu(rsp))
return 0;
if (rcu_scheduler_fully_active &&
rdp->qs_pending && !rdp->passed_quiesce &&
rdp->rcu_qs_ctr_snap == __this_cpu_read(rcu_qs_ctr)) {
rdp->n_rp_qs_pending++;
} else if (rdp->qs_pending &&
(rdp->passed_quiesce ||
rdp->rcu_qs_ctr_snap != __this_cpu_read(rcu_qs_ctr))) {
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
if (ACCESS_ONCE(rnp->gpnum) != rdp->gpnum ||
unlikely(ACCESS_ONCE(rdp->gpwrap))) {
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
static int __maybe_unused rcu_cpu_has_callbacks(bool *all_lazy)
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
_rcu_barrier_trace(rsp, "LastCB", -1, rsp->n_barrier_done);
complete(&rsp->barrier_completion);
} else {
_rcu_barrier_trace(rsp, "CB", -1, rsp->n_barrier_done);
}
}
static void rcu_barrier_func(void *type)
{
struct rcu_state *rsp = type;
struct rcu_data *rdp = raw_cpu_ptr(rsp->rda);
_rcu_barrier_trace(rsp, "IRQ", -1, rsp->n_barrier_done);
atomic_inc(&rsp->barrier_cpu_count);
rsp->call(&rdp->barrier_head, rcu_barrier_callback);
}
static void _rcu_barrier(struct rcu_state *rsp)
{
int cpu;
struct rcu_data *rdp;
unsigned long snap = ACCESS_ONCE(rsp->n_barrier_done);
unsigned long snap_done;
_rcu_barrier_trace(rsp, "Begin", -1, snap);
mutex_lock(&rsp->barrier_mutex);
smp_mb();
snap_done = rsp->n_barrier_done;
_rcu_barrier_trace(rsp, "Check", -1, snap_done);
if (ULONG_CMP_GE(snap_done, (snap + 3) & ~0x1)) {
_rcu_barrier_trace(rsp, "EarlyExit", -1, snap_done);
smp_mb();
mutex_unlock(&rsp->barrier_mutex);
return;
}
ACCESS_ONCE(rsp->n_barrier_done) = rsp->n_barrier_done + 1;
WARN_ON_ONCE((rsp->n_barrier_done & 0x1) != 1);
_rcu_barrier_trace(rsp, "Inc1", -1, rsp->n_barrier_done);
smp_mb();
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
rsp->n_barrier_done);
} else {
_rcu_barrier_trace(rsp, "OnlineNoCB", cpu,
rsp->n_barrier_done);
smp_mb__before_atomic();
atomic_inc(&rsp->barrier_cpu_count);
__call_rcu(&rdp->barrier_head,
rcu_barrier_callback, rsp, cpu, 0);
}
} else if (ACCESS_ONCE(rdp->qlen)) {
_rcu_barrier_trace(rsp, "OnlineQ", cpu,
rsp->n_barrier_done);
smp_call_function_single(cpu, rcu_barrier_func, rsp, 1);
} else {
_rcu_barrier_trace(rsp, "OnlineNQ", cpu,
rsp->n_barrier_done);
}
}
put_online_cpus();
if (atomic_dec_and_test(&rsp->barrier_cpu_count))
complete(&rsp->barrier_completion);
smp_mb();
ACCESS_ONCE(rsp->n_barrier_done) = rsp->n_barrier_done + 1;
WARN_ON_ONCE((rsp->n_barrier_done & 0x1) != 0);
_rcu_barrier_trace(rsp, "Inc2", -1, rsp->n_barrier_done);
smp_mb();
wait_for_completion(&rsp->barrier_completion);
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
static void __init
rcu_boot_init_percpu_data(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rcu_get_root(rsp);
raw_spin_lock_irqsave(&rnp->lock, flags);
rdp->grpmask = 1UL << (cpu - rdp->mynode->grplo);
rdp->dynticks = &per_cpu(rcu_dynticks, cpu);
WARN_ON_ONCE(rdp->dynticks->dynticks_nesting != DYNTICK_TASK_EXIT_IDLE);
WARN_ON_ONCE(atomic_read(&rdp->dynticks->dynticks) != 1);
rdp->cpu = cpu;
rdp->rsp = rsp;
rcu_boot_init_nocb_percpu_data(rdp);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
static void
rcu_init_percpu_data(int cpu, struct rcu_state *rsp)
{
unsigned long flags;
unsigned long mask;
struct rcu_data *rdp = per_cpu_ptr(rsp->rda, cpu);
struct rcu_node *rnp = rcu_get_root(rsp);
mutex_lock(&rsp->onoff_mutex);
raw_spin_lock_irqsave(&rnp->lock, flags);
rdp->beenonline = 1;
rdp->qlen_last_fqs_check = 0;
rdp->n_force_qs_snap = rsp->n_force_qs;
rdp->blimit = blimit;
init_callback_list(rdp);
rdp->dynticks->dynticks_nesting = DYNTICK_TASK_EXIT_IDLE;
rcu_sysidle_init_percpu_data(rdp->dynticks);
atomic_set(&rdp->dynticks->dynticks,
(atomic_read(&rdp->dynticks->dynticks) & ~0x1) + 1);
raw_spin_unlock(&rnp->lock);
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
rdp->rcu_qs_ctr_snap = __this_cpu_read(rcu_qs_ctr);
rdp->qs_pending = 0;
trace_rcu_grace_period(rsp->name, rdp->gpnum, TPS("cpuonl"));
}
raw_spin_unlock(&rnp->lock);
rnp = rnp->parent;
} while (rnp != NULL && !(rnp->qsmaskinit & mask));
local_irq_restore(flags);
mutex_unlock(&rsp->onoff_mutex);
}
static void rcu_prepare_cpu(int cpu)
{
struct rcu_state *rsp;
for_each_rcu_flavor(rsp)
rcu_init_percpu_data(cpu, rsp);
}
static int rcu_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
long cpu = (long)hcpu;
struct rcu_data *rdp = per_cpu_ptr(rcu_state_p->rda, cpu);
struct rcu_node *rnp = rdp->mynode;
struct rcu_state *rsp;
trace_rcu_utilization(TPS("Start CPU hotplug"));
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
rcu_prepare_cpu(cpu);
rcu_prepare_kthreads(cpu);
rcu_spawn_all_nocb_kthreads(cpu);
break;
case CPU_ONLINE:
case CPU_DOWN_FAILED:
rcu_boost_kthread_setaffinity(rnp, -1);
break;
case CPU_DOWN_PREPARE:
rcu_boost_kthread_setaffinity(rnp, cpu);
break;
case CPU_DYING:
case CPU_DYING_FROZEN:
for_each_rcu_flavor(rsp)
rcu_cleanup_dying_cpu(rsp);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
for_each_rcu_flavor(rsp) {
rcu_cleanup_dead_cpu(cpu, rsp);
do_nocb_deferred_wakeup(per_cpu_ptr(rsp->rda, cpu));
}
break;
default:
break;
}
trace_rcu_utilization(TPS("End CPU hotplug"));
return NOTIFY_OK;
}
static int rcu_pm_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action) {
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
if (nr_cpu_ids <= 256)
rcu_expedited = 1;
break;
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
rcu_expedited = 0;
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
raw_spin_lock_irqsave(&rnp->lock, flags);
rsp->gp_kthread = t;
if (kthread_prio) {
sp.sched_priority = kthread_prio;
sched_setscheduler_nocheck(t, SCHED_FIFO, &sp);
}
wake_up_process(t);
raw_spin_unlock_irqrestore(&rnp->lock, flags);
}
rcu_spawn_nocb_kthreads();
rcu_spawn_boost_kthreads();
return 0;
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
rsp->levelspread[rcu_num_lvls - 1] = rcu_fanout_leaf;
for (i = rcu_num_lvls - 2; i >= 0; i--)
rsp->levelspread[i] = CONFIG_RCU_FANOUT;
}
static void __init rcu_init_levelspread(struct rcu_state *rsp)
{
int ccur;
int cprv;
int i;
cprv = nr_cpu_ids;
for (i = rcu_num_lvls - 1; i >= 0; i--) {
ccur = rsp->levelcnt[i];
rsp->levelspread[i] = (cprv + ccur - 1) / ccur;
cprv = ccur;
}
}
static void __init rcu_init_one(struct rcu_state *rsp,
struct rcu_data __percpu *rda)
{
static const char * const buf[] = {
"rcu_node_0",
"rcu_node_1",
"rcu_node_2",
"rcu_node_3" };
static const char * const fqs[] = {
"rcu_node_fqs_0",
"rcu_node_fqs_1",
"rcu_node_fqs_2",
"rcu_node_fqs_3" };
static u8 fl_mask = 0x1;
int cpustride = 1;
int i;
int j;
struct rcu_node *rnp;
BUILD_BUG_ON(MAX_RCU_LVLS > ARRAY_SIZE(buf));
if (rcu_num_lvls > RCU_NUM_LVLS)
panic("rcu_init_one: rcu_num_lvls overflow");
for (i = 0; i < rcu_num_lvls; i++)
rsp->levelcnt[i] = num_rcu_lvl[i];
for (i = 1; i < rcu_num_lvls; i++)
rsp->level[i] = rsp->level[i - 1] + rsp->levelcnt[i - 1];
rcu_init_levelspread(rsp);
rsp->flavor_mask = fl_mask;
fl_mask <<= 1;
for (i = rcu_num_lvls - 1; i >= 0; i--) {
cpustride *= rsp->levelspread[i];
rnp = rsp->level[i];
for (j = 0; j < rsp->levelcnt[i]; j++, rnp++) {
raw_spin_lock_init(&rnp->lock);
lockdep_set_class_and_name(&rnp->lock,
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
rnp->grpnum = j % rsp->levelspread[i - 1];
rnp->grpmask = 1UL << rnp->grpnum;
rnp->parent = rsp->level[i - 1] +
j / rsp->levelspread[i - 1];
}
rnp->level = i;
INIT_LIST_HEAD(&rnp->blkd_tasks);
rcu_init_one_nocb(rnp);
}
}
rsp->rda = rda;
init_waitqueue_head(&rsp->gp_wq);
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
int j;
int n = nr_cpu_ids;
int rcu_capacity[MAX_RCU_LVLS + 1];
d = RCU_JIFFIES_TILL_FORCE_QS + nr_cpu_ids / RCU_JIFFIES_FQS_DIV;
if (jiffies_till_first_fqs == ULONG_MAX)
jiffies_till_first_fqs = d;
if (jiffies_till_next_fqs == ULONG_MAX)
jiffies_till_next_fqs = d;
if (rcu_fanout_leaf == CONFIG_RCU_FANOUT_LEAF &&
nr_cpu_ids == NR_CPUS)
return;
pr_info("RCU: Adjusting geometry for rcu_fanout_leaf=%d, nr_cpu_ids=%d\n",
rcu_fanout_leaf, nr_cpu_ids);
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
rcu_init_one(&rcu_bh_state, &rcu_bh_data);
rcu_init_one(&rcu_sched_state, &rcu_sched_data);
__rcu_init_preempt();
open_softirq(RCU_SOFTIRQ, rcu_process_callbacks);
cpu_notifier(rcu_cpu_notify, 0);
pm_notifier(rcu_pm_notify, 0);
for_each_online_cpu(cpu)
rcu_cpu_notify(NULL, CPU_UP_PREPARE, (void *)(long)cpu);
rcu_early_boot_tests();
}
