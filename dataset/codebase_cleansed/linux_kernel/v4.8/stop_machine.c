static void cpu_stop_init_done(struct cpu_stop_done *done, unsigned int nr_todo)
{
memset(done, 0, sizeof(*done));
atomic_set(&done->nr_todo, nr_todo);
init_completion(&done->completion);
}
static void cpu_stop_signal_done(struct cpu_stop_done *done)
{
if (atomic_dec_and_test(&done->nr_todo))
complete(&done->completion);
}
static void __cpu_stop_queue_work(struct cpu_stopper *stopper,
struct cpu_stop_work *work)
{
list_add_tail(&work->list, &stopper->works);
wake_up_process(stopper->thread);
}
static bool cpu_stop_queue_work(unsigned int cpu, struct cpu_stop_work *work)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
unsigned long flags;
bool enabled;
spin_lock_irqsave(&stopper->lock, flags);
enabled = stopper->enabled;
if (enabled)
__cpu_stop_queue_work(stopper, work);
else if (work->done)
cpu_stop_signal_done(work->done);
spin_unlock_irqrestore(&stopper->lock, flags);
return enabled;
}
int stop_one_cpu(unsigned int cpu, cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_done done;
struct cpu_stop_work work = { .fn = fn, .arg = arg, .done = &done };
cpu_stop_init_done(&done, 1);
if (!cpu_stop_queue_work(cpu, &work))
return -ENOENT;
wait_for_completion(&done.completion);
return done.ret;
}
static void set_state(struct multi_stop_data *msdata,
enum multi_stop_state newstate)
{
atomic_set(&msdata->thread_ack, msdata->num_threads);
smp_wmb();
msdata->state = newstate;
}
static void ack_state(struct multi_stop_data *msdata)
{
if (atomic_dec_and_test(&msdata->thread_ack))
set_state(msdata, msdata->state + 1);
}
static int multi_cpu_stop(void *data)
{
struct multi_stop_data *msdata = data;
enum multi_stop_state curstate = MULTI_STOP_NONE;
int cpu = smp_processor_id(), err = 0;
unsigned long flags;
bool is_active;
local_save_flags(flags);
if (!msdata->active_cpus)
is_active = cpu == cpumask_first(cpu_online_mask);
else
is_active = cpumask_test_cpu(cpu, msdata->active_cpus);
do {
cpu_relax();
if (msdata->state != curstate) {
curstate = msdata->state;
switch (curstate) {
case MULTI_STOP_DISABLE_IRQ:
local_irq_disable();
hard_irq_disable();
break;
case MULTI_STOP_RUN:
if (is_active)
err = msdata->fn(msdata->data);
break;
default:
break;
}
ack_state(msdata);
} else if (curstate > MULTI_STOP_PREPARE) {
touch_nmi_watchdog();
}
} while (curstate != MULTI_STOP_EXIT);
local_irq_restore(flags);
return err;
}
static int cpu_stop_queue_two_works(int cpu1, struct cpu_stop_work *work1,
int cpu2, struct cpu_stop_work *work2)
{
struct cpu_stopper *stopper1 = per_cpu_ptr(&cpu_stopper, cpu1);
struct cpu_stopper *stopper2 = per_cpu_ptr(&cpu_stopper, cpu2);
int err;
lg_double_lock(&stop_cpus_lock, cpu1, cpu2);
spin_lock_irq(&stopper1->lock);
spin_lock_nested(&stopper2->lock, SINGLE_DEPTH_NESTING);
err = -ENOENT;
if (!stopper1->enabled || !stopper2->enabled)
goto unlock;
err = 0;
__cpu_stop_queue_work(stopper1, work1);
__cpu_stop_queue_work(stopper2, work2);
unlock:
spin_unlock(&stopper2->lock);
spin_unlock_irq(&stopper1->lock);
lg_double_unlock(&stop_cpus_lock, cpu1, cpu2);
return err;
}
int stop_two_cpus(unsigned int cpu1, unsigned int cpu2, cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_done done;
struct cpu_stop_work work1, work2;
struct multi_stop_data msdata;
msdata = (struct multi_stop_data){
.fn = fn,
.data = arg,
.num_threads = 2,
.active_cpus = cpumask_of(cpu1),
};
work1 = work2 = (struct cpu_stop_work){
.fn = multi_cpu_stop,
.arg = &msdata,
.done = &done
};
cpu_stop_init_done(&done, 2);
set_state(&msdata, MULTI_STOP_PREPARE);
if (cpu1 > cpu2)
swap(cpu1, cpu2);
if (cpu_stop_queue_two_works(cpu1, &work1, cpu2, &work2))
return -ENOENT;
wait_for_completion(&done.completion);
return done.ret;
}
bool stop_one_cpu_nowait(unsigned int cpu, cpu_stop_fn_t fn, void *arg,
struct cpu_stop_work *work_buf)
{
*work_buf = (struct cpu_stop_work){ .fn = fn, .arg = arg, };
return cpu_stop_queue_work(cpu, work_buf);
}
static bool queue_stop_cpus_work(const struct cpumask *cpumask,
cpu_stop_fn_t fn, void *arg,
struct cpu_stop_done *done)
{
struct cpu_stop_work *work;
unsigned int cpu;
bool queued = false;
lg_global_lock(&stop_cpus_lock);
for_each_cpu(cpu, cpumask) {
work = &per_cpu(cpu_stopper.stop_work, cpu);
work->fn = fn;
work->arg = arg;
work->done = done;
if (cpu_stop_queue_work(cpu, work))
queued = true;
}
lg_global_unlock(&stop_cpus_lock);
return queued;
}
static int __stop_cpus(const struct cpumask *cpumask,
cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_done done;
cpu_stop_init_done(&done, cpumask_weight(cpumask));
if (!queue_stop_cpus_work(cpumask, fn, arg, &done))
return -ENOENT;
wait_for_completion(&done.completion);
return done.ret;
}
int stop_cpus(const struct cpumask *cpumask, cpu_stop_fn_t fn, void *arg)
{
int ret;
mutex_lock(&stop_cpus_mutex);
ret = __stop_cpus(cpumask, fn, arg);
mutex_unlock(&stop_cpus_mutex);
return ret;
}
int try_stop_cpus(const struct cpumask *cpumask, cpu_stop_fn_t fn, void *arg)
{
int ret;
if (!mutex_trylock(&stop_cpus_mutex))
return -EAGAIN;
ret = __stop_cpus(cpumask, fn, arg);
mutex_unlock(&stop_cpus_mutex);
return ret;
}
static int cpu_stop_should_run(unsigned int cpu)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
unsigned long flags;
int run;
spin_lock_irqsave(&stopper->lock, flags);
run = !list_empty(&stopper->works);
spin_unlock_irqrestore(&stopper->lock, flags);
return run;
}
static void cpu_stopper_thread(unsigned int cpu)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
struct cpu_stop_work *work;
repeat:
work = NULL;
spin_lock_irq(&stopper->lock);
if (!list_empty(&stopper->works)) {
work = list_first_entry(&stopper->works,
struct cpu_stop_work, list);
list_del_init(&work->list);
}
spin_unlock_irq(&stopper->lock);
if (work) {
cpu_stop_fn_t fn = work->fn;
void *arg = work->arg;
struct cpu_stop_done *done = work->done;
int ret;
preempt_count_inc();
ret = fn(arg);
if (done) {
if (ret)
done->ret = ret;
cpu_stop_signal_done(done);
}
preempt_count_dec();
WARN_ONCE(preempt_count(),
"cpu_stop: %pf(%p) leaked preempt count\n", fn, arg);
goto repeat;
}
}
void stop_machine_park(int cpu)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
stopper->enabled = false;
kthread_park(stopper->thread);
}
static void cpu_stop_create(unsigned int cpu)
{
sched_set_stop_task(cpu, per_cpu(cpu_stopper.thread, cpu));
}
static void cpu_stop_park(unsigned int cpu)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
WARN_ON(!list_empty(&stopper->works));
}
void stop_machine_unpark(int cpu)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
stopper->enabled = true;
kthread_unpark(stopper->thread);
}
static int __init cpu_stop_init(void)
{
unsigned int cpu;
for_each_possible_cpu(cpu) {
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
spin_lock_init(&stopper->lock);
INIT_LIST_HEAD(&stopper->works);
}
BUG_ON(smpboot_register_percpu_thread(&cpu_stop_threads));
stop_machine_unpark(raw_smp_processor_id());
stop_machine_initialized = true;
return 0;
}
static int __stop_machine(cpu_stop_fn_t fn, void *data, const struct cpumask *cpus)
{
struct multi_stop_data msdata = {
.fn = fn,
.data = data,
.num_threads = num_online_cpus(),
.active_cpus = cpus,
};
if (!stop_machine_initialized) {
unsigned long flags;
int ret;
WARN_ON_ONCE(msdata.num_threads != 1);
local_irq_save(flags);
hard_irq_disable();
ret = (*fn)(data);
local_irq_restore(flags);
return ret;
}
set_state(&msdata, MULTI_STOP_PREPARE);
return stop_cpus(cpu_online_mask, multi_cpu_stop, &msdata);
}
int stop_machine(cpu_stop_fn_t fn, void *data, const struct cpumask *cpus)
{
int ret;
get_online_cpus();
ret = __stop_machine(fn, data, cpus);
put_online_cpus();
return ret;
}
int stop_machine_from_inactive_cpu(cpu_stop_fn_t fn, void *data,
const struct cpumask *cpus)
{
struct multi_stop_data msdata = { .fn = fn, .data = data,
.active_cpus = cpus };
struct cpu_stop_done done;
int ret;
BUG_ON(cpu_active(raw_smp_processor_id()));
msdata.num_threads = num_active_cpus() + 1;
while (!mutex_trylock(&stop_cpus_mutex))
cpu_relax();
set_state(&msdata, MULTI_STOP_PREPARE);
cpu_stop_init_done(&done, num_active_cpus());
queue_stop_cpus_work(cpu_active_mask, multi_cpu_stop, &msdata,
&done);
ret = multi_cpu_stop(&msdata);
while (!completion_done(&done.completion))
cpu_relax();
mutex_unlock(&stop_cpus_mutex);
return ret ?: done.ret;
}
