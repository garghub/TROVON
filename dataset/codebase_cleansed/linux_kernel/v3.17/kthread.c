static inline struct kthread *to_kthread(struct task_struct *k)
{
return __to_kthread(k->vfork_done);
}
static struct kthread *to_live_kthread(struct task_struct *k)
{
struct completion *vfork = ACCESS_ONCE(k->vfork_done);
if (likely(vfork))
return __to_kthread(vfork);
return NULL;
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
void *probe_kthread_data(struct task_struct *task)
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
struct kthread self;
int ret;
self.flags = 0;
self.data = data;
init_completion(&self.exited);
init_completion(&self.parked);
current->vfork_done = &self.exited;
done = xchg(&create->done, NULL);
if (!done) {
kfree(create);
do_exit(-EINTR);
}
__set_current_state(TASK_UNINTERRUPTIBLE);
create->result = current;
complete(done);
schedule();
ret = -EINTR;
if (!test_bit(KTHREAD_SHOULD_STOP, &self.flags)) {
__kthread_parkme(&self);
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
struct task_struct *kthread_create_on_node(int (*threadfn)(void *data),
void *data, int node,
const char namefmt[],
...)
{
DECLARE_COMPLETION_ONSTACK(done);
struct task_struct *task;
struct kthread_create_info *create = kmalloc(sizeof(*create),
GFP_KERNEL);
if (!create)
return ERR_PTR(-ENOMEM);
create->threadfn = threadfn;
create->data = data;
create->node = node;
create->done = &done;
spin_lock(&kthread_create_lock);
list_add_tail(&create->list, &kthread_create_list);
spin_unlock(&kthread_create_lock);
wake_up_process(kthreadd_task);
if (unlikely(wait_for_completion_killable(&done))) {
if (xchg(&create->done, NULL))
return ERR_PTR(-EINTR);
wait_for_completion(&done);
}
task = create->result;
if (!IS_ERR(task)) {
static const struct sched_param param = { .sched_priority = 0 };
va_list args;
va_start(args, namefmt);
vsnprintf(task->comm, sizeof(task->comm), namefmt, args);
va_end(args);
sched_setscheduler_nocheck(task, SCHED_NORMAL, &param);
set_cpus_allowed_ptr(task, cpu_all_mask);
}
kfree(create);
return task;
}
static void __kthread_bind(struct task_struct *p, unsigned int cpu, long state)
{
if (!wait_task_inactive(p, state)) {
WARN_ON(1);
return;
}
do_set_cpus_allowed(p, cpumask_of(cpu));
p->flags |= PF_NO_SETAFFINITY;
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
p = kthread_create_on_node(threadfn, data, cpu_to_mem(cpu), namefmt,
cpu);
if (IS_ERR(p))
return p;
set_bit(KTHREAD_IS_PER_CPU, &to_kthread(p)->flags);
to_kthread(p)->cpu = cpu;
kthread_park(p);
return p;
}
static void __kthread_unpark(struct task_struct *k, struct kthread *kthread)
{
clear_bit(KTHREAD_SHOULD_PARK, &kthread->flags);
if (test_and_clear_bit(KTHREAD_IS_PARKED, &kthread->flags)) {
if (test_bit(KTHREAD_IS_PER_CPU, &kthread->flags))
__kthread_bind(k, kthread->cpu, TASK_PARKED);
wake_up_state(k, TASK_PARKED);
}
}
void kthread_unpark(struct task_struct *k)
{
struct kthread *kthread = to_live_kthread(k);
if (kthread)
__kthread_unpark(k, kthread);
}
int kthread_park(struct task_struct *k)
{
struct kthread *kthread = to_live_kthread(k);
int ret = -ENOSYS;
if (kthread) {
if (!test_bit(KTHREAD_IS_PARKED, &kthread->flags)) {
set_bit(KTHREAD_SHOULD_PARK, &kthread->flags);
if (k != current) {
wake_up_process(k);
wait_for_completion(&kthread->parked);
}
}
ret = 0;
}
return ret;
}
int kthread_stop(struct task_struct *k)
{
struct kthread *kthread;
int ret;
trace_sched_kthread_stop(k);
get_task_struct(k);
kthread = to_live_kthread(k);
if (kthread) {
set_bit(KTHREAD_SHOULD_STOP, &kthread->flags);
__kthread_unpark(k, kthread);
wake_up_process(k);
wait_for_completion(&kthread->exited);
}
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
void __init_kthread_worker(struct kthread_worker *worker,
const char *name,
struct lock_class_key *key)
{
spin_lock_init(&worker->lock);
lockdep_set_class_and_name(&worker->lock, key, name);
INIT_LIST_HEAD(&worker->work_list);
worker->task = NULL;
}
int kthread_worker_fn(void *worker_ptr)
{
struct kthread_worker *worker = worker_ptr;
struct kthread_work *work;
WARN_ON(worker->task);
worker->task = current;
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
static void insert_kthread_work(struct kthread_worker *worker,
struct kthread_work *work,
struct list_head *pos)
{
lockdep_assert_held(&worker->lock);
list_add_tail(&work->node, pos);
work->worker = worker;
if (!worker->current_work && likely(worker->task))
wake_up_process(worker->task);
}
bool queue_kthread_work(struct kthread_worker *worker,
struct kthread_work *work)
{
bool ret = false;
unsigned long flags;
spin_lock_irqsave(&worker->lock, flags);
if (list_empty(&work->node)) {
insert_kthread_work(worker, work, &worker->work_list);
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
void flush_kthread_work(struct kthread_work *work)
{
struct kthread_flush_work fwork = {
KTHREAD_WORK_INIT(fwork.work, kthread_flush_work_fn),
COMPLETION_INITIALIZER_ONSTACK(fwork.done),
};
struct kthread_worker *worker;
bool noop = false;
retry:
worker = work->worker;
if (!worker)
return;
spin_lock_irq(&worker->lock);
if (work->worker != worker) {
spin_unlock_irq(&worker->lock);
goto retry;
}
if (!list_empty(&work->node))
insert_kthread_work(worker, &fwork.work, work->node.next);
else if (worker->current_work == work)
insert_kthread_work(worker, &fwork.work, worker->work_list.next);
else
noop = true;
spin_unlock_irq(&worker->lock);
if (!noop)
wait_for_completion(&fwork.done);
}
void flush_kthread_worker(struct kthread_worker *worker)
{
struct kthread_flush_work fwork = {
KTHREAD_WORK_INIT(fwork.work, kthread_flush_work_fn),
COMPLETION_INITIALIZER_ONSTACK(fwork.done),
};
queue_kthread_work(worker, &fwork.work);
wait_for_completion(&fwork.done);
}
