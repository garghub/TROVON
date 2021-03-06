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
static void cpu_stop_queue_work(struct cpu_stopper *stopper,
struct cpu_stop_work *work)
{
unsigned long flags;
spin_lock_irqsave(&stopper->lock, flags);
if (stopper->enabled) {
list_add_tail(&work->list, &stopper->works);
wake_up_process(stopper->thread);
} else
cpu_stop_signal_done(work->done, false);
spin_unlock_irqrestore(&stopper->lock, flags);
}
int stop_one_cpu(unsigned int cpu, cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_done done;
struct cpu_stop_work work = { .fn = fn, .arg = arg, .done = &done };
cpu_stop_init_done(&done, 1);
cpu_stop_queue_work(&per_cpu(cpu_stopper, cpu), &work);
wait_for_completion(&done.completion);
return done.executed ? done.ret : -ENOENT;
}
void stop_one_cpu_nowait(unsigned int cpu, cpu_stop_fn_t fn, void *arg,
struct cpu_stop_work *work_buf)
{
*work_buf = (struct cpu_stop_work){ .fn = fn, .arg = arg, };
cpu_stop_queue_work(&per_cpu(cpu_stopper, cpu), work_buf);
}
int __stop_cpus(const struct cpumask *cpumask, cpu_stop_fn_t fn, void *arg)
{
struct cpu_stop_work *work;
struct cpu_stop_done done;
unsigned int cpu;
for_each_cpu(cpu, cpumask) {
work = &per_cpu(stop_cpus_work, cpu);
work->fn = fn;
work->arg = arg;
work->done = &done;
}
cpu_stop_init_done(&done, cpumask_weight(cpumask));
preempt_disable();
for_each_cpu(cpu, cpumask)
cpu_stop_queue_work(&per_cpu(cpu_stopper, cpu),
&per_cpu(stop_cpus_work, cpu));
preempt_enable();
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
static int cpu_stopper_thread(void *data)
{
struct cpu_stopper *stopper = data;
struct cpu_stop_work *work;
int ret;
repeat:
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop()) {
__set_current_state(TASK_RUNNING);
return 0;
}
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
__set_current_state(TASK_RUNNING);
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
} else
schedule();
goto repeat;
}
static int __cpuinit cpu_stop_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
struct task_struct *p;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
BUG_ON(stopper->thread || stopper->enabled ||
!list_empty(&stopper->works));
p = kthread_create_on_node(cpu_stopper_thread,
stopper,
cpu_to_node(cpu),
"migration/%d", cpu);
if (IS_ERR(p))
return notifier_from_errno(PTR_ERR(p));
get_task_struct(p);
kthread_bind(p, cpu);
sched_set_stop_task(cpu, p);
stopper->thread = p;
break;
case CPU_ONLINE:
wake_up_process(stopper->thread);
spin_lock_irq(&stopper->lock);
stopper->enabled = true;
spin_unlock_irq(&stopper->lock);
break;
#ifdef CONFIG_HOTPLUG_CPU
case CPU_UP_CANCELED:
case CPU_POST_DEAD:
{
struct cpu_stop_work *work;
sched_set_stop_task(cpu, NULL);
kthread_stop(stopper->thread);
spin_lock_irq(&stopper->lock);
list_for_each_entry(work, &stopper->works, list)
cpu_stop_signal_done(work->done, false);
stopper->enabled = false;
spin_unlock_irq(&stopper->lock);
put_task_struct(stopper->thread);
stopper->thread = NULL;
break;
}
#endif
}
return NOTIFY_OK;
}
static int __init cpu_stop_init(void)
{
void *bcpu = (void *)(long)smp_processor_id();
unsigned int cpu;
int err;
for_each_possible_cpu(cpu) {
struct cpu_stopper *stopper = &per_cpu(cpu_stopper, cpu);
spin_lock_init(&stopper->lock);
INIT_LIST_HEAD(&stopper->works);
}
err = cpu_stop_cpu_callback(&cpu_stop_cpu_notifier, CPU_UP_PREPARE,
bcpu);
BUG_ON(err != NOTIFY_OK);
cpu_stop_cpu_callback(&cpu_stop_cpu_notifier, CPU_ONLINE, bcpu);
register_cpu_notifier(&cpu_stop_cpu_notifier);
return 0;
}
static void set_state(struct stop_machine_data *smdata,
enum stopmachine_state newstate)
{
atomic_set(&smdata->thread_ack, smdata->num_threads);
smp_wmb();
smdata->state = newstate;
}
static void ack_state(struct stop_machine_data *smdata)
{
if (atomic_dec_and_test(&smdata->thread_ack))
set_state(smdata, smdata->state + 1);
}
static int stop_machine_cpu_stop(void *data)
{
struct stop_machine_data *smdata = data;
enum stopmachine_state curstate = STOPMACHINE_NONE;
int cpu = smp_processor_id(), err = 0;
bool is_active;
if (!smdata->active_cpus)
is_active = cpu == cpumask_first(cpu_online_mask);
else
is_active = cpumask_test_cpu(cpu, smdata->active_cpus);
do {
cpu_relax();
if (smdata->state != curstate) {
curstate = smdata->state;
switch (curstate) {
case STOPMACHINE_DISABLE_IRQ:
local_irq_disable();
hard_irq_disable();
break;
case STOPMACHINE_RUN:
if (is_active)
err = smdata->fn(smdata->data);
break;
default:
break;
}
ack_state(smdata);
}
} while (curstate != STOPMACHINE_EXIT);
local_irq_enable();
return err;
}
int __stop_machine(int (*fn)(void *), void *data, const struct cpumask *cpus)
{
struct stop_machine_data smdata = { .fn = fn, .data = data,
.num_threads = num_online_cpus(),
.active_cpus = cpus };
set_state(&smdata, STOPMACHINE_PREPARE);
return stop_cpus(cpu_online_mask, stop_machine_cpu_stop, &smdata);
}
int stop_machine(int (*fn)(void *), void *data, const struct cpumask *cpus)
{
int ret;
get_online_cpus();
ret = __stop_machine(fn, data, cpus);
put_online_cpus();
return ret;
}
