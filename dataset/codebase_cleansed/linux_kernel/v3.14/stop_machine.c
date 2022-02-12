static void cpu_stop_init_done(struct cpu_stop_done *done, unsigned int nr_todo)
{
memset(done, 0, sizeof(*done));
atomic_set(&done->nr_todo, nr_todo);
init_completion(&done->completion);
}
static void cpu_stop_signal_done(struct cpu_stop_done *done, bool executed)
{
if (done) {
if (executed)
done->executed = true;
if (atomic_dec_and_test(&done->nr_todo))
complete(&done->completion);
}
}
static void cpu_stop_queue_work(unsigned int cpu, struct cpu_stop_work *work)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
struct task_struct *p = per_cpu(cpu_stopper_task, cpu);
unsigned long flags;
spin_lock_irqsave(&stopper->lock, flags);
if (stopper->enabled) {
list_add_tail(&work->list, &stopper->works);
wake_up_process(p);
} else
cpu_stop_signal_done(work->done, false);
spin_unlock_irqrestore(&stopper->lock, flags);
}
int stop_one_cpu(unsigned int cpu, cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_done done;
struct cpu_stop_work work = { .fn = fn, .arg = arg, .done = &done };
cpu_stop_init_done(&done, 1);
cpu_stop_queue_work(cpu, &work);
wait_for_completion(&done.completion);
return done.executed ? done.ret : -ENOENT;
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
}
} while (curstate != MULTI_STOP_EXIT);
local_irq_restore(flags);
return err;
}
static void irq_cpu_stop_queue_work(void *arg)
{
struct irq_cpu_stop_queue_work_info *info = arg;
cpu_stop_queue_work(info->cpu1, info->work1);
cpu_stop_queue_work(info->cpu2, info->work2);
}
int stop_two_cpus(unsigned int cpu1, unsigned int cpu2, cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_done done;
struct cpu_stop_work work1, work2;
struct irq_cpu_stop_queue_work_info call_args;
struct multi_stop_data msdata;
preempt_disable();
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
call_args = (struct irq_cpu_stop_queue_work_info){
.cpu1 = cpu1,
.cpu2 = cpu2,
.work1 = &work1,
.work2 = &work2,
};
cpu_stop_init_done(&done, 2);
set_state(&msdata, MULTI_STOP_PREPARE);
if (!cpu_active(cpu1) || !cpu_active(cpu2)) {
preempt_enable();
return -ENOENT;
}
lg_local_lock(&stop_cpus_lock);
smp_call_function_single(min(cpu1, cpu2),
&irq_cpu_stop_queue_work,
&call_args, 1);
lg_local_unlock(&stop_cpus_lock);
preempt_enable();
wait_for_completion(&done.completion);
return done.executed ? done.ret : -ENOENT;
}
void stop_one_cpu_nowait(unsigned int cpu, cpu_stop_fn_t fn, void *arg,
struct cpu_stop_work *work_buf)
{
*work_buf = (struct cpu_stop_work){ .fn = fn, .arg = arg, };
cpu_stop_queue_work(cpu, work_buf);
}
static void queue_stop_cpus_work(const struct cpumask *cpumask,
cpu_stop_fn_t fn, void *arg,
struct cpu_stop_done *done)
{
struct cpu_stop_work *work;
unsigned int cpu;
for_each_cpu(cpu, cpumask) {
work = &per_cpu(stop_cpus_work, cpu);
work->fn = fn;
work->arg = arg;
work->done = done;
}
lg_global_lock(&stop_cpus_lock);
for_each_cpu(cpu, cpumask)
cpu_stop_queue_work(cpu, &per_cpu(stop_cpus_work, cpu));
lg_global_unlock(&stop_cpus_lock);
}
static int __stop_cpus(const struct cpumask *cpumask,
cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_done done;
cpu_stop_init_done(&done, cpumask_weight(cpumask));
queue_stop_cpus_work(cpumask, fn, arg, &done);
wait_for_completion(&done.completion);
return done.executed ? done.ret : -ENOENT;
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
int ret;
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
char ksym_buf[KSYM_NAME_LEN] __maybe_unused;
preempt_disable();
ret = fn(arg);
if (ret)
done->ret = ret;
preempt_enable();
WARN_ONCE(preempt_count(),
"cpu_stop: %s(%p) leaked preempt count\n",
kallsyms_lookup((unsigned long)fn, NULL, NULL, NULL,
ksym_buf), arg);
cpu_stop_signal_done(done, true);
goto repeat;
}
}
static void cpu_stop_create(unsigned int cpu)
{
sched_set_stop_task(cpu, per_cpu(cpu_stopper_task, cpu));
}
static void cpu_stop_park(unsigned int cpu)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
struct cpu_stop_work *work;
unsigned long flags;
spin_lock_irqsave(&stopper->lock, flags);
list_for_each_entry(work, &stopper->works, list)
cpu_stop_signal_done(work->done, false);
stopper->enabled = false;
spin_unlock_irqrestore(&stopper->lock, flags);
}
static void cpu_stop_unpark(unsigned int cpu)
{
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
spin_lock_irq(&stopper->lock);
stopper->enabled = true;
spin_unlock_irq(&stopper->lock);
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
stop_machine_initialized = true;
return 0;
}
int __stop_machine(int (*fn)(void *), void *data, const struct cpumask *cpus)
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
int stop_machine(int (*fn)(void *), void *data, const struct cpumask *cpus)
{
int ret;
get_online_cpus();
ret = __stop_machine(fn, data, cpus);
put_online_cpus();
return ret;
}
int stop_machine_from_inactive_cpu(int (*fn)(void *), void *data,
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
