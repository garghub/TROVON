static inline void rcu_batch_init(struct rcu_batch *b)
{
b->head = NULL;
b->tail = &b->head;
}
static inline void rcu_batch_queue(struct rcu_batch *b, struct rcu_head *head)
{
*b->tail = head;
b->tail = &head->next;
}
static inline bool rcu_batch_empty(struct rcu_batch *b)
{
return b->tail == &b->head;
}
static inline struct rcu_head *rcu_batch_dequeue(struct rcu_batch *b)
{
struct rcu_head *head;
if (rcu_batch_empty(b))
return NULL;
head = b->head;
b->head = head->next;
if (b->tail == &head->next)
rcu_batch_init(b);
return head;
}
static inline void rcu_batch_move(struct rcu_batch *to, struct rcu_batch *from)
{
if (!rcu_batch_empty(from)) {
*to->tail = from->head;
to->tail = from->tail;
rcu_batch_init(from);
}
}
static int init_srcu_struct_fields(struct srcu_struct *sp)
{
sp->completed = 0;
spin_lock_init(&sp->queue_lock);
sp->running = false;
rcu_batch_init(&sp->batch_queue);
rcu_batch_init(&sp->batch_check0);
rcu_batch_init(&sp->batch_check1);
rcu_batch_init(&sp->batch_done);
INIT_DELAYED_WORK(&sp->work, process_srcu);
sp->per_cpu_ref = alloc_percpu(struct srcu_array);
return sp->per_cpu_ref ? 0 : -ENOMEM;
}
int __init_srcu_struct(struct srcu_struct *sp, const char *name,
struct lock_class_key *key)
{
debug_check_no_locks_freed((void *)sp, sizeof(*sp));
lockdep_init_map(&sp->dep_map, name, key, 0);
return init_srcu_struct_fields(sp);
}
int init_srcu_struct(struct srcu_struct *sp)
{
return init_srcu_struct_fields(sp);
}
static unsigned long srcu_readers_lock_idx(struct srcu_struct *sp, int idx)
{
int cpu;
unsigned long sum = 0;
for_each_possible_cpu(cpu) {
struct srcu_array *cpuc = per_cpu_ptr(sp->per_cpu_ref, cpu);
sum += READ_ONCE(cpuc->lock_count[idx]);
}
return sum;
}
static unsigned long srcu_readers_unlock_idx(struct srcu_struct *sp, int idx)
{
int cpu;
unsigned long sum = 0;
for_each_possible_cpu(cpu) {
struct srcu_array *cpuc = per_cpu_ptr(sp->per_cpu_ref, cpu);
sum += READ_ONCE(cpuc->unlock_count[idx]);
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
struct srcu_array *cpuc = per_cpu_ptr(sp->per_cpu_ref, cpu);
sum += READ_ONCE(cpuc->lock_count[0]);
sum += READ_ONCE(cpuc->lock_count[1]);
sum -= READ_ONCE(cpuc->unlock_count[0]);
sum -= READ_ONCE(cpuc->unlock_count[1]);
}
return sum;
}
void cleanup_srcu_struct(struct srcu_struct *sp)
{
if (WARN_ON(srcu_readers_active(sp)))
return;
free_percpu(sp->per_cpu_ref);
sp->per_cpu_ref = NULL;
}
int __srcu_read_lock(struct srcu_struct *sp)
{
int idx;
idx = READ_ONCE(sp->completed) & 0x1;
__this_cpu_inc(sp->per_cpu_ref->lock_count[idx]);
smp_mb();
return idx;
}
void __srcu_read_unlock(struct srcu_struct *sp, int idx)
{
smp_mb();
this_cpu_inc(sp->per_cpu_ref->unlock_count[idx]);
}
static bool try_check_zero(struct srcu_struct *sp, int idx, int trycount)
{
for (;;) {
if (srcu_readers_active_idx_check(sp, idx))
return true;
if (--trycount <= 0)
return false;
udelay(SRCU_RETRY_CHECK_DELAY);
}
}
static void srcu_flip(struct srcu_struct *sp)
{
WRITE_ONCE(sp->completed, sp->completed + 1);
smp_mb();
}
void call_srcu(struct srcu_struct *sp, struct rcu_head *head,
rcu_callback_t func)
{
unsigned long flags;
head->next = NULL;
head->func = func;
spin_lock_irqsave(&sp->queue_lock, flags);
smp_mb__after_unlock_lock();
rcu_batch_queue(&sp->batch_queue, head);
if (!sp->running) {
sp->running = true;
queue_delayed_work(system_power_efficient_wq, &sp->work, 0);
}
spin_unlock_irqrestore(&sp->queue_lock, flags);
}
static void __synchronize_srcu(struct srcu_struct *sp, int trycount)
{
struct rcu_synchronize rcu;
struct rcu_head *head = &rcu.head;
bool done = false;
RCU_LOCKDEP_WARN(lock_is_held(&sp->dep_map) ||
lock_is_held(&rcu_bh_lock_map) ||
lock_is_held(&rcu_lock_map) ||
lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_srcu() in same-type SRCU (or in RCU) read-side critical section");
might_sleep();
init_completion(&rcu.completion);
head->next = NULL;
head->func = wakeme_after_rcu;
spin_lock_irq(&sp->queue_lock);
smp_mb__after_unlock_lock();
if (!sp->running) {
sp->running = true;
rcu_batch_queue(&sp->batch_check0, head);
spin_unlock_irq(&sp->queue_lock);
srcu_advance_batches(sp, trycount);
if (!rcu_batch_empty(&sp->batch_done)) {
BUG_ON(sp->batch_done.head != head);
rcu_batch_dequeue(&sp->batch_done);
done = true;
}
srcu_reschedule(sp);
} else {
rcu_batch_queue(&sp->batch_queue, head);
spin_unlock_irq(&sp->queue_lock);
}
if (!done) {
wait_for_completion(&rcu.completion);
smp_mb();
}
}
void synchronize_srcu(struct srcu_struct *sp)
{
__synchronize_srcu(sp, (rcu_gp_is_expedited() && !rcu_gp_is_normal())
? SYNCHRONIZE_SRCU_EXP_TRYCOUNT
: SYNCHRONIZE_SRCU_TRYCOUNT);
}
void synchronize_srcu_expedited(struct srcu_struct *sp)
{
__synchronize_srcu(sp, SYNCHRONIZE_SRCU_EXP_TRYCOUNT);
}
void srcu_barrier(struct srcu_struct *sp)
{
synchronize_srcu(sp);
}
unsigned long srcu_batches_completed(struct srcu_struct *sp)
{
return sp->completed;
}
static void srcu_collect_new(struct srcu_struct *sp)
{
if (!rcu_batch_empty(&sp->batch_queue)) {
spin_lock_irq(&sp->queue_lock);
rcu_batch_move(&sp->batch_check0, &sp->batch_queue);
spin_unlock_irq(&sp->queue_lock);
}
}
static void srcu_advance_batches(struct srcu_struct *sp, int trycount)
{
int idx = 1 ^ (sp->completed & 1);
if (rcu_batch_empty(&sp->batch_check0) &&
rcu_batch_empty(&sp->batch_check1))
return;
if (!try_check_zero(sp, idx, trycount))
return;
rcu_batch_move(&sp->batch_done, &sp->batch_check1);
if (rcu_batch_empty(&sp->batch_check0))
return;
srcu_flip(sp);
rcu_batch_move(&sp->batch_check1, &sp->batch_check0);
trycount = trycount < 2 ? 2 : trycount;
if (!try_check_zero(sp, idx^1, trycount))
return;
rcu_batch_move(&sp->batch_done, &sp->batch_check1);
}
static void srcu_invoke_callbacks(struct srcu_struct *sp)
{
int i;
struct rcu_head *head;
for (i = 0; i < SRCU_CALLBACK_BATCH; i++) {
head = rcu_batch_dequeue(&sp->batch_done);
if (!head)
break;
local_bh_disable();
head->func(head);
local_bh_enable();
}
}
static void srcu_reschedule(struct srcu_struct *sp)
{
bool pending = true;
if (rcu_batch_empty(&sp->batch_done) &&
rcu_batch_empty(&sp->batch_check1) &&
rcu_batch_empty(&sp->batch_check0) &&
rcu_batch_empty(&sp->batch_queue)) {
spin_lock_irq(&sp->queue_lock);
if (rcu_batch_empty(&sp->batch_done) &&
rcu_batch_empty(&sp->batch_check1) &&
rcu_batch_empty(&sp->batch_check0) &&
rcu_batch_empty(&sp->batch_queue)) {
sp->running = false;
pending = false;
}
spin_unlock_irq(&sp->queue_lock);
}
if (pending)
queue_delayed_work(system_power_efficient_wq,
&sp->work, SRCU_INTERVAL);
}
void process_srcu(struct work_struct *work)
{
struct srcu_struct *sp;
sp = container_of(work, struct srcu_struct, work.work);
srcu_collect_new(sp);
srcu_advance_batches(sp, 1);
srcu_invoke_callbacks(sp);
srcu_reschedule(sp);
}
