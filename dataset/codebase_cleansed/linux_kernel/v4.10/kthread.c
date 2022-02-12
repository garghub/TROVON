static inline void set_kthread_struct(void *kthread)
{
current->set_child_tid = (__force void __user *)kthread;
}
static inline struct kthread *to_kthread(struct task_struct *k)
{
WARN_ON(!(k->flags & PF_KTHREAD));
return (__force void *)k->set_child_tid;
}
void free_kthread_struct(struct task_struct *k)
{
kfree(to_kthread(k));
}
bool kthread_should_stop(void)
{
return test_bit(KTHREAD_SHOULD_STOP, &to_kthread(current)->flags);
}
bool kthread_should_park(void)
{
return test_bit(KTHREAD_SHOULD_PARK, &to_kthread(current)->flags);
}
bool kthread_freezable_should_stop(bool *was_frozen)
{
bool frozen = false;
might_sleep();
if (unlikely(freezing(current)))
frozen = __refrigerator(true);
if (was_frozen)
*was_frozen = frozen;
return kthread_should_stop();
}
void *kthread_data(struct task_struct *task)
{
return to_kthread(task)->data;
}
void *kthread_probe_data(struct task_struct *task)
{
struct kthread *kthread = to_kthread(task);
void *data = NULL;
probe_kernel_read(&data, &kthread->data, sizeof(data));
return data;
}
static void __kthread_parkme(struct kthread *self)
{
__set_current_state(TASK_PARKED);
while (test_bit(KTHREAD_SHOULD_PARK, &self->flags)) {
if (!test_and_set_bit(KTHREAD_IS_PARKED, &self->flags))
complete(&self->parked);
schedule();
__set_current_state(TASK_PARKED);
}
clear_bit(KTHREAD_IS_PARKED, &self->flags);
__set_current_state(TASK_RUNNING);
}
void kthread_parkme(void)
{
__kthread_parkme(to_kthread(current));
}
static int kthread(void *_create)
{
struct kthread_create_info *create = _create;
int (*threadfn)(void *data) = create->threadfn;
void *data = create->data;
struct completion *done;
struct kthread *self;
int ret;
self = kmalloc(sizeof(*self), GFP_KERNEL);
set_kthread_struct(self);
done = xchg(&create->done, NULL);
if (!done) {
kfree(create);
do_exit(-EINTR);
}
if (!self) {
create->result = ERR_PTR(-ENOMEM);
complete(done);
do_exit(-ENOMEM);
}
self->flags = 0;
self->data = data;
init_completion(&self->exited);
init_completion(&self->parked);
current->vfork_done = &self->exited;
__set_current_state(TASK_UNINTERRUPTIBLE);
create->result = current;
complete(done);
schedule();
ret = -EINTR;
if (!test_bit(KTHREAD_SHOULD_STOP, &self->flags)) {
__kthread_parkme(self);
ret = threadfn(data);
}
do_exit(ret);
}
int tsk_fork_get_node(struct task_struct *tsk)
{
#ifdef CONFIG_NUMA
if (tsk == kthreadd_task)
return tsk->pref_node_fork;
#endif
return NUMA_NO_NODE;
}
static void create_kthread(struct kthread_create_info *create)
{
int pid;
#ifdef CONFIG_NUMA
current->pref_node_fork = create->node;
#endif
pid = kernel_thread(kthread, create, CLONE_FS | CLONE_FILES | SIGCHLD);
if (pid < 0) {
struct completion *done = xchg(&create->done, NULL);
if (!done) {
kfree(create);
return;
}
create->result = ERR_PTR(pid);
complete(done);
}
}
task_struct *kthread_create_on_node(int (*threadfn)(void *data),
void *data, int node,
const char namefmt[],
...)
{
struct task_struct *task;
va_list args;
va_start(args, namefmt);
task = __kthread_create_on_node(threadfn, data, node, namefmt, args);
va_end(args);
return task;
}
static void __kthread_bind_mask(struct task_struct *p, const struct cpumask *mask, long state)
{
unsigned long flags;
if (!wait_task_inactive(p, state)) {
WARN_ON(1);
return;
}
raw_spin_lock_irqsave(&p->pi_lock, flags);
do_set_cpus_allowed(p, mask);
p->flags |= PF_NO_SETAFFINITY;
raw_spin_unlock_irqrestore(&p->pi_lock, flags);
}
static void __kthread_bind(struct task_struct *p, unsigned int cpu, long state)
{
__kthread_bind_mask(p, cpumask_of(cpu), state);
}
void kthread_bind_mask(struct task_struct *p, const struct cpumask *mask)
{
__kthread_bind_mask(p, mask, TASK_UNINTERRUPTIBLE);
}
void kthread_bind(struct task_struct *p, unsigned int cpu)
{
__kthread_bind(p, cpu, TASK_UNINTERRUPTIBLE);
}
struct task_struct *kthread_create_on_cpu(int (*threadfn)(void *data),
void *data, unsigned int cpu,
const char *namefmt)
{
struct task_struct *p;
p = kthread_create_on_node(threadfn, data, cpu_to_node(cpu), namefmt,
cpu);
if (IS_ERR(p))
return p;
kthread_bind(p, cpu);
set_bit(KTHREAD_IS_PER_CPU, &to_kthread(p)->flags);
to_kthread(p)->cpu = cpu;
return p;
}
void kthread_unpark(struct task_struct *k)
{
struct kthread *kthread = to_kthread(k);
clear_bit(KTHREAD_SHOULD_PARK, &kthread->flags);
if (test_and_clear_bit(KTHREAD_IS_PARKED, &kthread->flags)) {
if (test_bit(KTHREAD_IS_PER_CPU, &kthread->flags))
__kthread_bind(k, kthread->cpu, TASK_PARKED);
wake_up_state(k, TASK_PARKED);
}
}
int kthread_park(struct task_struct *k)
{
struct kthread *kthread = to_kthread(k);
if (WARN_ON(k->flags & PF_EXITING))
return -ENOSYS;
if (!test_bit(KTHREAD_IS_PARKED, &kthread->flags)) {
set_bit(KTHREAD_SHOULD_PARK, &kthread->flags);
if (k != current) {
wake_up_process(k);
wait_for_completion(&kthread->parked);
}
}
return 0;
}
int kthread_stop(struct task_struct *k)
{
struct kthread *kthread;
int ret;
trace_sched_kthread_stop(k);
get_task_struct(k);
kthread = to_kthread(k);
set_bit(KTHREAD_SHOULD_STOP, &kthread->flags);
kthread_unpark(k);
wake_up_process(k);
wait_for_completion(&kthread->exited);
ret = k->exit_code;
put_task_struct(k);
trace_sched_kthread_stop_ret(ret);
return ret;
}
int kthreadd(void *unused)
{
struct task_struct *tsk = current;
set_task_comm(tsk, "kthreadd");
ignore_signals(tsk);
set_cpus_allowed_ptr(tsk, cpu_all_mask);
set_mems_allowed(node_states[N_MEMORY]);
current->flags |= PF_NOFREEZE;
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (list_empty(&kthread_create_list))
schedule();
__set_current_state(TASK_RUNNING);
spin_lock(&kthread_create_lock);
while (!list_empty(&kthread_create_list)) {
struct kthread_create_info *create;
create = list_entry(kthread_create_list.next,
struct kthread_create_info, list);
list_del_init(&create->list);
spin_unlock(&kthread_create_lock);
create_kthread(create);
spin_lock(&kthread_create_lock);
}
spin_unlock(&kthread_create_lock);
}
return 0;
}
void __kthread_init_worker(struct kthread_worker *worker,
const char *name,
struct lock_class_key *key)
{
memset(worker, 0, sizeof(struct kthread_worker));
spin_lock_init(&worker->lock);
lockdep_set_class_and_name(&worker->lock, key, name);
INIT_LIST_HEAD(&worker->work_list);
INIT_LIST_HEAD(&worker->delayed_work_list);
}
int kthread_worker_fn(void *worker_ptr)
{
struct kthread_worker *worker = worker_ptr;
struct kthread_work *work;
WARN_ON(worker->task && worker->task != current);
worker->task = current;
if (worker->flags & KTW_FREEZABLE)
set_freezable();
repeat:
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop()) {
__set_current_state(TASK_RUNNING);
spin_lock_irq(&worker->lock);
worker->task = NULL;
spin_unlock_irq(&worker->lock);
return 0;
}
work = NULL;
spin_lock_irq(&worker->lock);
if (!list_empty(&worker->work_list)) {
work = list_first_entry(&worker->work_list,
struct kthread_work, node);
list_del_init(&work->node);
}
worker->current_work = work;
spin_unlock_irq(&worker->lock);
if (work) {
__set_current_state(TASK_RUNNING);
work->func(work);
} else if (!freezing(current))
schedule();
try_to_freeze();
goto repeat;
}
kthread_worker *
kthread_create_worker(unsigned int flags, const char namefmt[], ...)
{
struct kthread_worker *worker;
va_list args;
va_start(args, namefmt);
worker = __kthread_create_worker(-1, flags, namefmt, args);
va_end(args);
return worker;
}
struct kthread_worker *
kthread_create_worker_on_cpu(int cpu, unsigned int flags,
const char namefmt[], ...)
{
struct kthread_worker *worker;
va_list args;
va_start(args, namefmt);
worker = __kthread_create_worker(cpu, flags, namefmt, args);
va_end(args);
return worker;
}
static inline bool queuing_blocked(struct kthread_worker *worker,
struct kthread_work *work)
{
lockdep_assert_held(&worker->lock);
return !list_empty(&work->node) || work->canceling;
}
static void kthread_insert_work_sanity_check(struct kthread_worker *worker,
struct kthread_work *work)
{
lockdep_assert_held(&worker->lock);
WARN_ON_ONCE(!list_empty(&work->node));
WARN_ON_ONCE(work->worker && work->worker != worker);
}
static void kthread_insert_work(struct kthread_worker *worker,
struct kthread_work *work,
struct list_head *pos)
{
kthread_insert_work_sanity_check(worker, work);
list_add_tail(&work->node, pos);
work->worker = worker;
if (!worker->current_work && likely(worker->task))
wake_up_process(worker->task);
}
bool kthread_queue_work(struct kthread_worker *worker,
struct kthread_work *work)
{
bool ret = false;
unsigned long flags;
spin_lock_irqsave(&worker->lock, flags);
if (!queuing_blocked(worker, work)) {
kthread_insert_work(worker, work, &worker->work_list);
ret = true;
}
spin_unlock_irqrestore(&worker->lock, flags);
return ret;
}
void kthread_delayed_work_timer_fn(unsigned long __data)
{
struct kthread_delayed_work *dwork =
(struct kthread_delayed_work *)__data;
struct kthread_work *work = &dwork->work;
struct kthread_worker *worker = work->worker;
if (WARN_ON_ONCE(!worker))
return;
spin_lock(&worker->lock);
WARN_ON_ONCE(work->worker != worker);
WARN_ON_ONCE(list_empty(&work->node));
list_del_init(&work->node);
kthread_insert_work(worker, work, &worker->work_list);
spin_unlock(&worker->lock);
}
void __kthread_queue_delayed_work(struct kthread_worker *worker,
struct kthread_delayed_work *dwork,
unsigned long delay)
{
struct timer_list *timer = &dwork->timer;
struct kthread_work *work = &dwork->work;
WARN_ON_ONCE(timer->function != kthread_delayed_work_timer_fn ||
timer->data != (unsigned long)dwork);
if (!delay) {
kthread_insert_work(worker, work, &worker->work_list);
return;
}
kthread_insert_work_sanity_check(worker, work);
list_add(&work->node, &worker->delayed_work_list);
work->worker = worker;
timer_stats_timer_set_start_info(&dwork->timer);
timer->expires = jiffies + delay;
add_timer(timer);
}
bool kthread_queue_delayed_work(struct kthread_worker *worker,
struct kthread_delayed_work *dwork,
unsigned long delay)
{
struct kthread_work *work = &dwork->work;
unsigned long flags;
bool ret = false;
spin_lock_irqsave(&worker->lock, flags);
if (!queuing_blocked(worker, work)) {
__kthread_queue_delayed_work(worker, dwork, delay);
ret = true;
}
spin_unlock_irqrestore(&worker->lock, flags);
return ret;
}
static void kthread_flush_work_fn(struct kthread_work *work)
{
struct kthread_flush_work *fwork =
container_of(work, struct kthread_flush_work, work);
complete(&fwork->done);
}
void kthread_flush_work(struct kthread_work *work)
{
struct kthread_flush_work fwork = {
KTHREAD_WORK_INIT(fwork.work, kthread_flush_work_fn),
COMPLETION_INITIALIZER_ONSTACK(fwork.done),
};
struct kthread_worker *worker;
bool noop = false;
worker = work->worker;
if (!worker)
return;
spin_lock_irq(&worker->lock);
WARN_ON_ONCE(work->worker != worker);
if (!list_empty(&work->node))
kthread_insert_work(worker, &fwork.work, work->node.next);
else if (worker->current_work == work)
kthread_insert_work(worker, &fwork.work,
worker->work_list.next);
else
noop = true;
spin_unlock_irq(&worker->lock);
if (!noop)
wait_for_completion(&fwork.done);
}
static bool __kthread_cancel_work(struct kthread_work *work, bool is_dwork,
unsigned long *flags)
{
if (is_dwork) {
struct kthread_delayed_work *dwork =
container_of(work, struct kthread_delayed_work, work);
struct kthread_worker *worker = work->worker;
work->canceling++;
spin_unlock_irqrestore(&worker->lock, *flags);
del_timer_sync(&dwork->timer);
spin_lock_irqsave(&worker->lock, *flags);
work->canceling--;
}
if (!list_empty(&work->node)) {
list_del_init(&work->node);
return true;
}
return false;
}
bool kthread_mod_delayed_work(struct kthread_worker *worker,
struct kthread_delayed_work *dwork,
unsigned long delay)
{
struct kthread_work *work = &dwork->work;
unsigned long flags;
int ret = false;
spin_lock_irqsave(&worker->lock, flags);
if (!work->worker)
goto fast_queue;
WARN_ON_ONCE(work->worker != worker);
if (work->canceling)
goto out;
ret = __kthread_cancel_work(work, true, &flags);
fast_queue:
__kthread_queue_delayed_work(worker, dwork, delay);
out:
spin_unlock_irqrestore(&worker->lock, flags);
return ret;
}
static bool __kthread_cancel_work_sync(struct kthread_work *work, bool is_dwork)
{
struct kthread_worker *worker = work->worker;
unsigned long flags;
int ret = false;
if (!worker)
goto out;
spin_lock_irqsave(&worker->lock, flags);
WARN_ON_ONCE(work->worker != worker);
ret = __kthread_cancel_work(work, is_dwork, &flags);
if (worker->current_work != work)
goto out_fast;
work->canceling++;
spin_unlock_irqrestore(&worker->lock, flags);
kthread_flush_work(work);
spin_lock_irqsave(&worker->lock, flags);
work->canceling--;
out_fast:
spin_unlock_irqrestore(&worker->lock, flags);
out:
return ret;
}
bool kthread_cancel_work_sync(struct kthread_work *work)
{
return __kthread_cancel_work_sync(work, false);
}
bool kthread_cancel_delayed_work_sync(struct kthread_delayed_work *dwork)
{
return __kthread_cancel_work_sync(&dwork->work, true);
}
void kthread_flush_worker(struct kthread_worker *worker)
{
struct kthread_flush_work fwork = {
KTHREAD_WORK_INIT(fwork.work, kthread_flush_work_fn),
COMPLETION_INITIALIZER_ONSTACK(fwork.done),
};
kthread_queue_work(worker, &fwork.work);
wait_for_completion(&fwork.done);
}
void kthread_destroy_worker(struct kthread_worker *worker)
{
struct task_struct *task;
task = worker->task;
if (WARN_ON(!task))
return;
kthread_flush_worker(worker);
kthread_stop(task);
WARN_ON(!list_empty(&worker->work_list));
kfree(worker);
}
