static void init_srcu_struct_nodes(struct srcu_struct *sp, bool is_static)
{
int cpu;
int i;
int level = 0;
int levelspread[RCU_NUM_LVLS];
struct srcu_data *sdp;
struct srcu_node *snp;
struct srcu_node *snp_first;
sp->level[0] = &sp->node[0];
for (i = 1; i < rcu_num_lvls; i++)
sp->level[i] = sp->level[i - 1] + num_rcu_lvl[i - 1];
rcu_init_levelspread(levelspread, num_rcu_lvl);
rcu_for_each_node_breadth_first(sp, snp) {
spin_lock_init(&snp->lock);
WARN_ON_ONCE(ARRAY_SIZE(snp->srcu_have_cbs) !=
ARRAY_SIZE(snp->srcu_data_have_cbs));
for (i = 0; i < ARRAY_SIZE(snp->srcu_have_cbs); i++) {
snp->srcu_have_cbs[i] = 0;
snp->srcu_data_have_cbs[i] = 0;
}
snp->srcu_gp_seq_needed_exp = 0;
snp->grplo = -1;
snp->grphi = -1;
if (snp == &sp->node[0]) {
snp->srcu_parent = NULL;
continue;
}
if (snp == sp->level[level + 1])
level++;
snp->srcu_parent = sp->level[level - 1] +
(snp - sp->level[level]) /
levelspread[level - 1];
}
WARN_ON_ONCE(ARRAY_SIZE(sdp->srcu_lock_count) !=
ARRAY_SIZE(sdp->srcu_unlock_count));
level = rcu_num_lvls - 1;
snp_first = sp->level[level];
for_each_possible_cpu(cpu) {
sdp = per_cpu_ptr(sp->sda, cpu);
spin_lock_init(&sdp->lock);
rcu_segcblist_init(&sdp->srcu_cblist);
sdp->srcu_cblist_invoking = false;
sdp->srcu_gp_seq_needed = sp->srcu_gp_seq;
sdp->srcu_gp_seq_needed_exp = sp->srcu_gp_seq;
sdp->mynode = &snp_first[cpu / levelspread[level]];
for (snp = sdp->mynode; snp != NULL; snp = snp->srcu_parent) {
if (snp->grplo < 0)
snp->grplo = cpu;
snp->grphi = cpu;
}
sdp->cpu = cpu;
INIT_DELAYED_WORK(&sdp->work, srcu_invoke_callbacks);
sdp->sp = sp;
sdp->grpmask = 1 << (cpu - sdp->mynode->grplo);
if (is_static)
continue;
for (i = 0; i < ARRAY_SIZE(sdp->srcu_lock_count); i++) {
sdp->srcu_lock_count[i] = 0;
sdp->srcu_unlock_count[i] = 0;
}
}
}
static int init_srcu_struct_fields(struct srcu_struct *sp, bool is_static)
{
mutex_init(&sp->srcu_cb_mutex);
mutex_init(&sp->srcu_gp_mutex);
sp->srcu_idx = 0;
sp->srcu_gp_seq = 0;
sp->srcu_barrier_seq = 0;
mutex_init(&sp->srcu_barrier_mutex);
atomic_set(&sp->srcu_barrier_cpu_cnt, 0);
INIT_DELAYED_WORK(&sp->work, process_srcu);
if (!is_static)
sp->sda = alloc_percpu(struct srcu_data);
init_srcu_struct_nodes(sp, is_static);
sp->srcu_gp_seq_needed_exp = 0;
sp->srcu_last_gp_end = ktime_get_mono_fast_ns();
smp_store_release(&sp->srcu_gp_seq_needed, 0);
return sp->sda ? 0 : -ENOMEM;
}
int __init_srcu_struct(struct srcu_struct *sp, const char *name,
struct lock_class_key *key)
{
debug_check_no_locks_freed((void *)sp, sizeof(*sp));
lockdep_init_map(&sp->dep_map, name, key, 0);
spin_lock_init(&sp->gp_lock);
return init_srcu_struct_fields(sp, false);
}
int init_srcu_struct(struct srcu_struct *sp)
{
spin_lock_init(&sp->gp_lock);
return init_srcu_struct_fields(sp, false);
}
static void check_init_srcu_struct(struct srcu_struct *sp)
{
unsigned long flags;
WARN_ON_ONCE(rcu_scheduler_active == RCU_SCHEDULER_INIT);
if (!rcu_seq_state(smp_load_acquire(&sp->srcu_gp_seq_needed)))
return;
spin_lock_irqsave(&sp->gp_lock, flags);
if (!rcu_seq_state(sp->srcu_gp_seq_needed)) {
spin_unlock_irqrestore(&sp->gp_lock, flags);
return;
}
init_srcu_struct_fields(sp, true);
spin_unlock_irqrestore(&sp->gp_lock, flags);
}
static unsigned long srcu_readers_lock_idx(struct srcu_struct *sp, int idx)
{
int cpu;
unsigned long sum = 0;
for_each_possible_cpu(cpu) {
struct srcu_data *cpuc = per_cpu_ptr(sp->sda, cpu);
sum += READ_ONCE(cpuc->srcu_lock_count[idx]);
}
return sum;
}
static unsigned long srcu_readers_unlock_idx(struct srcu_struct *sp, int idx)
{
int cpu;
unsigned long sum = 0;
for_each_possible_cpu(cpu) {
struct srcu_data *cpuc = per_cpu_ptr(sp->sda, cpu);
sum += READ_ONCE(cpuc->srcu_unlock_count[idx]);
}
return sum;
}
static bool srcu_readers_active_idx_check(struct srcu_struct *sp, int idx)
{
unsigned long unlocks;
unlocks = srcu_readers_unlock_idx(sp, idx);
smp_mb();
return srcu_readers_lock_idx(sp, idx) == unlocks;
}
static bool srcu_readers_active(struct srcu_struct *sp)
{
int cpu;
unsigned long sum = 0;
for_each_possible_cpu(cpu) {
struct srcu_data *cpuc = per_cpu_ptr(sp->sda, cpu);
sum += READ_ONCE(cpuc->srcu_lock_count[0]);
sum += READ_ONCE(cpuc->srcu_lock_count[1]);
sum -= READ_ONCE(cpuc->srcu_unlock_count[0]);
sum -= READ_ONCE(cpuc->srcu_unlock_count[1]);
}
return sum;
}
static unsigned long srcu_get_delay(struct srcu_struct *sp)
{
if (ULONG_CMP_LT(READ_ONCE(sp->srcu_gp_seq),
READ_ONCE(sp->srcu_gp_seq_needed_exp)))
return 0;
return SRCU_INTERVAL;
}
void cleanup_srcu_struct(struct srcu_struct *sp)
{
int cpu;
if (WARN_ON(!srcu_get_delay(sp)))
return;
if (WARN_ON(srcu_readers_active(sp)))
return;
flush_delayed_work(&sp->work);
for_each_possible_cpu(cpu)
flush_delayed_work(&per_cpu_ptr(sp->sda, cpu)->work);
if (WARN_ON(rcu_seq_state(READ_ONCE(sp->srcu_gp_seq)) != SRCU_STATE_IDLE) ||
WARN_ON(srcu_readers_active(sp))) {
pr_info("cleanup_srcu_struct: Active srcu_struct %p state: %d\n", sp, rcu_seq_state(READ_ONCE(sp->srcu_gp_seq)));
return;
}
free_percpu(sp->sda);
sp->sda = NULL;
}
int __srcu_read_lock(struct srcu_struct *sp)
{
int idx;
idx = READ_ONCE(sp->srcu_idx) & 0x1;
this_cpu_inc(sp->sda->srcu_lock_count[idx]);
smp_mb();
return idx;
}
void __srcu_read_unlock(struct srcu_struct *sp, int idx)
{
smp_mb();
this_cpu_inc(sp->sda->srcu_unlock_count[idx]);
}
static void srcu_gp_start(struct srcu_struct *sp)
{
struct srcu_data *sdp = this_cpu_ptr(sp->sda);
int state;
RCU_LOCKDEP_WARN(!lockdep_is_held(&sp->gp_lock),
"Invoked srcu_gp_start() without ->gp_lock!");
WARN_ON_ONCE(ULONG_CMP_GE(sp->srcu_gp_seq, sp->srcu_gp_seq_needed));
rcu_segcblist_advance(&sdp->srcu_cblist,
rcu_seq_current(&sp->srcu_gp_seq));
(void)rcu_segcblist_accelerate(&sdp->srcu_cblist,
rcu_seq_snap(&sp->srcu_gp_seq));
smp_mb();
rcu_seq_start(&sp->srcu_gp_seq);
state = rcu_seq_state(READ_ONCE(sp->srcu_gp_seq));
WARN_ON_ONCE(state != SRCU_STATE_SCAN1);
}
void srcu_online_cpu(unsigned int cpu)
{
WRITE_ONCE(per_cpu(srcu_online, cpu), true);
}
void srcu_offline_cpu(unsigned int cpu)
{
WRITE_ONCE(per_cpu(srcu_online, cpu), false);
}
static bool srcu_queue_delayed_work_on(int cpu, struct workqueue_struct *wq,
struct delayed_work *dwork,
unsigned long delay)
{
bool ret;
preempt_disable();
if (READ_ONCE(per_cpu(srcu_online, cpu)))
ret = queue_delayed_work_on(cpu, wq, dwork, delay);
else
ret = queue_delayed_work(wq, dwork, delay);
preempt_enable();
return ret;
}
static void srcu_schedule_cbs_sdp(struct srcu_data *sdp, unsigned long delay)
{
srcu_queue_delayed_work_on(sdp->cpu, system_power_efficient_wq,
&sdp->work, delay);
}
static void srcu_schedule_cbs_snp(struct srcu_struct *sp, struct srcu_node *snp,
unsigned long mask, unsigned long delay)
{
int cpu;
for (cpu = snp->grplo; cpu <= snp->grphi; cpu++) {
if (!(mask & (1 << (cpu - snp->grplo))))
continue;
srcu_schedule_cbs_sdp(per_cpu_ptr(sp->sda, cpu), delay);
}
}
static void srcu_gp_end(struct srcu_struct *sp)
{
unsigned long cbdelay;
bool cbs;
unsigned long gpseq;
int idx;
int idxnext;
unsigned long mask;
struct srcu_node *snp;
mutex_lock(&sp->srcu_cb_mutex);
spin_lock_irq(&sp->gp_lock);
idx = rcu_seq_state(sp->srcu_gp_seq);
WARN_ON_ONCE(idx != SRCU_STATE_SCAN2);
cbdelay = srcu_get_delay(sp);
sp->srcu_last_gp_end = ktime_get_mono_fast_ns();
rcu_seq_end(&sp->srcu_gp_seq);
gpseq = rcu_seq_current(&sp->srcu_gp_seq);
if (ULONG_CMP_LT(sp->srcu_gp_seq_needed_exp, gpseq))
sp->srcu_gp_seq_needed_exp = gpseq;
spin_unlock_irq(&sp->gp_lock);
mutex_unlock(&sp->srcu_gp_mutex);
idx = rcu_seq_ctr(gpseq) % ARRAY_SIZE(snp->srcu_have_cbs);
idxnext = (idx + 1) % ARRAY_SIZE(snp->srcu_have_cbs);
rcu_for_each_node_breadth_first(sp, snp) {
spin_lock_irq(&snp->lock);
cbs = false;
if (snp >= sp->level[rcu_num_lvls - 1])
cbs = snp->srcu_have_cbs[idx] == gpseq;
snp->srcu_have_cbs[idx] = gpseq;
rcu_seq_set_state(&snp->srcu_have_cbs[idx], 1);
if (ULONG_CMP_LT(snp->srcu_gp_seq_needed_exp, gpseq))
snp->srcu_gp_seq_needed_exp = gpseq;
mask = snp->srcu_data_have_cbs[idx];
snp->srcu_data_have_cbs[idx] = 0;
spin_unlock_irq(&snp->lock);
if (cbs) {
smp_mb();
srcu_schedule_cbs_snp(sp, snp, mask, cbdelay);
}
}
mutex_unlock(&sp->srcu_cb_mutex);
spin_lock_irq(&sp->gp_lock);
gpseq = rcu_seq_current(&sp->srcu_gp_seq);
if (!rcu_seq_state(gpseq) &&
ULONG_CMP_LT(gpseq, sp->srcu_gp_seq_needed)) {
srcu_gp_start(sp);
spin_unlock_irq(&sp->gp_lock);
srcu_reschedule(sp, rcu_seq_ctr(gpseq) & 0x3ff
? 0 : SRCU_INTERVAL);
} else {
spin_unlock_irq(&sp->gp_lock);
}
}
static void srcu_funnel_exp_start(struct srcu_struct *sp, struct srcu_node *snp,
unsigned long s)
{
unsigned long flags;
for (; snp != NULL; snp = snp->srcu_parent) {
if (rcu_seq_done(&sp->srcu_gp_seq, s) ||
ULONG_CMP_GE(READ_ONCE(snp->srcu_gp_seq_needed_exp), s))
return;
spin_lock_irqsave(&snp->lock, flags);
if (ULONG_CMP_GE(snp->srcu_gp_seq_needed_exp, s)) {
spin_unlock_irqrestore(&snp->lock, flags);
return;
}
WRITE_ONCE(snp->srcu_gp_seq_needed_exp, s);
spin_unlock_irqrestore(&snp->lock, flags);
}
spin_lock_irqsave(&sp->gp_lock, flags);
if (!ULONG_CMP_LT(sp->srcu_gp_seq_needed_exp, s))
sp->srcu_gp_seq_needed_exp = s;
spin_unlock_irqrestore(&sp->gp_lock, flags);
}
static void srcu_funnel_gp_start(struct srcu_struct *sp, struct srcu_data *sdp,
unsigned long s, bool do_norm)
{
unsigned long flags;
int idx = rcu_seq_ctr(s) % ARRAY_SIZE(sdp->mynode->srcu_have_cbs);
struct srcu_node *snp = sdp->mynode;
unsigned long snp_seq;
for (; snp != NULL; snp = snp->srcu_parent) {
if (rcu_seq_done(&sp->srcu_gp_seq, s) && snp != sdp->mynode)
return;
spin_lock_irqsave(&snp->lock, flags);
if (ULONG_CMP_GE(snp->srcu_have_cbs[idx], s)) {
snp_seq = snp->srcu_have_cbs[idx];
if (snp == sdp->mynode && snp_seq == s)
snp->srcu_data_have_cbs[idx] |= sdp->grpmask;
spin_unlock_irqrestore(&snp->lock, flags);
if (snp == sdp->mynode && snp_seq != s) {
smp_mb();
srcu_schedule_cbs_sdp(sdp, do_norm
? SRCU_INTERVAL
: 0);
return;
}
if (!do_norm)
srcu_funnel_exp_start(sp, snp, s);
return;
}
snp->srcu_have_cbs[idx] = s;
if (snp == sdp->mynode)
snp->srcu_data_have_cbs[idx] |= sdp->grpmask;
if (!do_norm && ULONG_CMP_LT(snp->srcu_gp_seq_needed_exp, s))
snp->srcu_gp_seq_needed_exp = s;
spin_unlock_irqrestore(&snp->lock, flags);
}
spin_lock_irqsave(&sp->gp_lock, flags);
if (ULONG_CMP_LT(sp->srcu_gp_seq_needed, s)) {
smp_store_release(&sp->srcu_gp_seq_needed, s);
}
if (!do_norm && ULONG_CMP_LT(sp->srcu_gp_seq_needed_exp, s))
sp->srcu_gp_seq_needed_exp = s;
if (!rcu_seq_done(&sp->srcu_gp_seq, s) &&
rcu_seq_state(sp->srcu_gp_seq) == SRCU_STATE_IDLE) {
WARN_ON_ONCE(ULONG_CMP_GE(sp->srcu_gp_seq, sp->srcu_gp_seq_needed));
srcu_gp_start(sp);
queue_delayed_work(system_power_efficient_wq, &sp->work,
srcu_get_delay(sp));
}
spin_unlock_irqrestore(&sp->gp_lock, flags);
}
static bool try_check_zero(struct srcu_struct *sp, int idx, int trycount)
{
for (;;) {
if (srcu_readers_active_idx_check(sp, idx))
return true;
if (--trycount + !srcu_get_delay(sp) <= 0)
return false;
udelay(SRCU_RETRY_CHECK_DELAY);
}
}
static void srcu_flip(struct srcu_struct *sp)
{
WRITE_ONCE(sp->srcu_idx, sp->srcu_idx + 1);
smp_mb();
}
static bool srcu_might_be_idle(struct srcu_struct *sp)
{
unsigned long curseq;
unsigned long flags;
struct srcu_data *sdp;
unsigned long t;
local_irq_save(flags);
sdp = this_cpu_ptr(sp->sda);
if (rcu_segcblist_pend_cbs(&sdp->srcu_cblist)) {
local_irq_restore(flags);
return false;
}
local_irq_restore(flags);
t = ktime_get_mono_fast_ns();
if (exp_holdoff == 0 ||
time_in_range_open(t, sp->srcu_last_gp_end,
sp->srcu_last_gp_end + exp_holdoff))
return false;
curseq = rcu_seq_current(&sp->srcu_gp_seq);
smp_mb();
if (ULONG_CMP_LT(curseq, READ_ONCE(sp->srcu_gp_seq_needed)))
return false;
smp_mb();
if (curseq != rcu_seq_current(&sp->srcu_gp_seq))
return false;
return true;
}
void __call_srcu(struct srcu_struct *sp, struct rcu_head *rhp,
rcu_callback_t func, bool do_norm)
{
unsigned long flags;
bool needexp = false;
bool needgp = false;
unsigned long s;
struct srcu_data *sdp;
check_init_srcu_struct(sp);
rhp->func = func;
local_irq_save(flags);
sdp = this_cpu_ptr(sp->sda);
spin_lock(&sdp->lock);
rcu_segcblist_enqueue(&sdp->srcu_cblist, rhp, false);
rcu_segcblist_advance(&sdp->srcu_cblist,
rcu_seq_current(&sp->srcu_gp_seq));
s = rcu_seq_snap(&sp->srcu_gp_seq);
(void)rcu_segcblist_accelerate(&sdp->srcu_cblist, s);
if (ULONG_CMP_LT(sdp->srcu_gp_seq_needed, s)) {
sdp->srcu_gp_seq_needed = s;
needgp = true;
}
if (!do_norm && ULONG_CMP_LT(sdp->srcu_gp_seq_needed_exp, s)) {
sdp->srcu_gp_seq_needed_exp = s;
needexp = true;
}
spin_unlock_irqrestore(&sdp->lock, flags);
if (needgp)
srcu_funnel_gp_start(sp, sdp, s, do_norm);
else if (needexp)
srcu_funnel_exp_start(sp, sdp->mynode, s);
}
void call_srcu(struct srcu_struct *sp, struct rcu_head *rhp,
rcu_callback_t func)
{
__call_srcu(sp, rhp, func, true);
}
static void __synchronize_srcu(struct srcu_struct *sp, bool do_norm)
{
struct rcu_synchronize rcu;
RCU_LOCKDEP_WARN(lock_is_held(&sp->dep_map) ||
lock_is_held(&rcu_bh_lock_map) ||
lock_is_held(&rcu_lock_map) ||
lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_srcu() in same-type SRCU (or in RCU) read-side critical section");
if (rcu_scheduler_active == RCU_SCHEDULER_INACTIVE)
return;
might_sleep();
check_init_srcu_struct(sp);
init_completion(&rcu.completion);
init_rcu_head_on_stack(&rcu.head);
__call_srcu(sp, &rcu.head, wakeme_after_rcu, do_norm);
wait_for_completion(&rcu.completion);
destroy_rcu_head_on_stack(&rcu.head);
}
void synchronize_srcu_expedited(struct srcu_struct *sp)
{
__synchronize_srcu(sp, rcu_gp_is_normal());
}
void synchronize_srcu(struct srcu_struct *sp)
{
if (srcu_might_be_idle(sp) || rcu_gp_is_expedited())
synchronize_srcu_expedited(sp);
else
__synchronize_srcu(sp, true);
}
static void srcu_barrier_cb(struct rcu_head *rhp)
{
struct srcu_data *sdp;
struct srcu_struct *sp;
sdp = container_of(rhp, struct srcu_data, srcu_barrier_head);
sp = sdp->sp;
if (atomic_dec_and_test(&sp->srcu_barrier_cpu_cnt))
complete(&sp->srcu_barrier_completion);
}
void srcu_barrier(struct srcu_struct *sp)
{
int cpu;
struct srcu_data *sdp;
unsigned long s = rcu_seq_snap(&sp->srcu_barrier_seq);
check_init_srcu_struct(sp);
mutex_lock(&sp->srcu_barrier_mutex);
if (rcu_seq_done(&sp->srcu_barrier_seq, s)) {
smp_mb();
mutex_unlock(&sp->srcu_barrier_mutex);
return;
}
rcu_seq_start(&sp->srcu_barrier_seq);
init_completion(&sp->srcu_barrier_completion);
atomic_set(&sp->srcu_barrier_cpu_cnt, 1);
for_each_possible_cpu(cpu) {
sdp = per_cpu_ptr(sp->sda, cpu);
spin_lock_irq(&sdp->lock);
atomic_inc(&sp->srcu_barrier_cpu_cnt);
sdp->srcu_barrier_head.func = srcu_barrier_cb;
if (!rcu_segcblist_entrain(&sdp->srcu_cblist,
&sdp->srcu_barrier_head, 0))
atomic_dec(&sp->srcu_barrier_cpu_cnt);
spin_unlock_irq(&sdp->lock);
}
if (atomic_dec_and_test(&sp->srcu_barrier_cpu_cnt))
complete(&sp->srcu_barrier_completion);
wait_for_completion(&sp->srcu_barrier_completion);
rcu_seq_end(&sp->srcu_barrier_seq);
mutex_unlock(&sp->srcu_barrier_mutex);
}
unsigned long srcu_batches_completed(struct srcu_struct *sp)
{
return sp->srcu_idx;
}
static void srcu_advance_state(struct srcu_struct *sp)
{
int idx;
mutex_lock(&sp->srcu_gp_mutex);
idx = rcu_seq_state(smp_load_acquire(&sp->srcu_gp_seq));
if (idx == SRCU_STATE_IDLE) {
spin_lock_irq(&sp->gp_lock);
if (ULONG_CMP_GE(sp->srcu_gp_seq, sp->srcu_gp_seq_needed)) {
WARN_ON_ONCE(rcu_seq_state(sp->srcu_gp_seq));
spin_unlock_irq(&sp->gp_lock);
mutex_unlock(&sp->srcu_gp_mutex);
return;
}
idx = rcu_seq_state(READ_ONCE(sp->srcu_gp_seq));
if (idx == SRCU_STATE_IDLE)
srcu_gp_start(sp);
spin_unlock_irq(&sp->gp_lock);
if (idx != SRCU_STATE_IDLE) {
mutex_unlock(&sp->srcu_gp_mutex);
return;
}
}
if (rcu_seq_state(READ_ONCE(sp->srcu_gp_seq)) == SRCU_STATE_SCAN1) {
idx = 1 ^ (sp->srcu_idx & 1);
if (!try_check_zero(sp, idx, 1)) {
mutex_unlock(&sp->srcu_gp_mutex);
return;
}
srcu_flip(sp);
rcu_seq_set_state(&sp->srcu_gp_seq, SRCU_STATE_SCAN2);
}
if (rcu_seq_state(READ_ONCE(sp->srcu_gp_seq)) == SRCU_STATE_SCAN2) {
idx = 1 ^ (sp->srcu_idx & 1);
if (!try_check_zero(sp, idx, 2)) {
mutex_unlock(&sp->srcu_gp_mutex);
return;
}
srcu_gp_end(sp);
}
}
static void srcu_invoke_callbacks(struct work_struct *work)
{
bool more;
struct rcu_cblist ready_cbs;
struct rcu_head *rhp;
struct srcu_data *sdp;
struct srcu_struct *sp;
sdp = container_of(work, struct srcu_data, work.work);
sp = sdp->sp;
rcu_cblist_init(&ready_cbs);
spin_lock_irq(&sdp->lock);
smp_mb();
rcu_segcblist_advance(&sdp->srcu_cblist,
rcu_seq_current(&sp->srcu_gp_seq));
if (sdp->srcu_cblist_invoking ||
!rcu_segcblist_ready_cbs(&sdp->srcu_cblist)) {
spin_unlock_irq(&sdp->lock);
return;
}
sdp->srcu_cblist_invoking = true;
rcu_segcblist_extract_done_cbs(&sdp->srcu_cblist, &ready_cbs);
spin_unlock_irq(&sdp->lock);
rhp = rcu_cblist_dequeue(&ready_cbs);
for (; rhp != NULL; rhp = rcu_cblist_dequeue(&ready_cbs)) {
local_bh_disable();
rhp->func(rhp);
local_bh_enable();
}
spin_lock_irq(&sdp->lock);
rcu_segcblist_insert_count(&sdp->srcu_cblist, &ready_cbs);
(void)rcu_segcblist_accelerate(&sdp->srcu_cblist,
rcu_seq_snap(&sp->srcu_gp_seq));
sdp->srcu_cblist_invoking = false;
more = rcu_segcblist_ready_cbs(&sdp->srcu_cblist);
spin_unlock_irq(&sdp->lock);
if (more)
srcu_schedule_cbs_sdp(sdp, 0);
}
static void srcu_reschedule(struct srcu_struct *sp, unsigned long delay)
{
bool pushgp = true;
spin_lock_irq(&sp->gp_lock);
if (ULONG_CMP_GE(sp->srcu_gp_seq, sp->srcu_gp_seq_needed)) {
if (!WARN_ON_ONCE(rcu_seq_state(sp->srcu_gp_seq))) {
pushgp = false;
}
} else if (!rcu_seq_state(sp->srcu_gp_seq)) {
srcu_gp_start(sp);
}
spin_unlock_irq(&sp->gp_lock);
if (pushgp)
queue_delayed_work(system_power_efficient_wq, &sp->work, delay);
}
void process_srcu(struct work_struct *work)
{
struct srcu_struct *sp;
sp = container_of(work, struct srcu_struct, work.work);
srcu_advance_state(sp);
srcu_reschedule(sp, srcu_get_delay(sp));
}
void srcutorture_get_gp_data(enum rcutorture_type test_type,
struct srcu_struct *sp, int *flags,
unsigned long *gpnum, unsigned long *completed)
{
if (test_type != SRCU_FLAVOR)
return;
*flags = 0;
*completed = rcu_seq_ctr(sp->srcu_gp_seq);
*gpnum = rcu_seq_ctr(sp->srcu_gp_seq_needed);
}
