static int read_mpidr(void)
{
unsigned int id;
asm volatile ("mrc p15, 0, %0, c0, c0, 5" : "=r" (id));
return id & MPIDR_HWID_BITMASK;
}
static void bL_do_switch(void *_arg)
{
unsigned ib_mpidr, ib_cpu, ib_cluster;
long volatile handshake, **handshake_ptr = _arg;
pr_debug("%s\n", __func__);
ib_mpidr = cpu_logical_map(smp_processor_id());
ib_cpu = MPIDR_AFFINITY_LEVEL(ib_mpidr, 0);
ib_cluster = MPIDR_AFFINITY_LEVEL(ib_mpidr, 1);
if (handshake_ptr) {
handshake = 0;
*handshake_ptr = &handshake;
} else
handshake = -1;
mcpm_set_entry_vector(ib_cpu, ib_cluster, cpu_resume);
sev();
while (!handshake) {
wfe();
smp_mb();
}
mcpm_cpu_power_down();
BUG();
}
static int bL_switchpoint(unsigned long _arg)
{
unsigned int mpidr = read_mpidr();
unsigned int clusterid = MPIDR_AFFINITY_LEVEL(mpidr, 1);
void *stack = current_thread_info() + 1;
stack = PTR_ALIGN(stack, L1_CACHE_BYTES);
stack += clusterid * STACK_SIZE + STACK_SIZE;
call_with_stack(bL_do_switch, (void *)_arg, stack);
BUG();
}
static int bL_switch_to(unsigned int new_cluster_id)
{
unsigned int mpidr, this_cpu, that_cpu;
unsigned int ob_mpidr, ob_cpu, ob_cluster, ib_mpidr, ib_cpu, ib_cluster;
struct completion inbound_alive;
long volatile *handshake_ptr;
int ipi_nr, ret;
this_cpu = smp_processor_id();
ob_mpidr = read_mpidr();
ob_cpu = MPIDR_AFFINITY_LEVEL(ob_mpidr, 0);
ob_cluster = MPIDR_AFFINITY_LEVEL(ob_mpidr, 1);
BUG_ON(cpu_logical_map(this_cpu) != ob_mpidr);
if (new_cluster_id == ob_cluster)
return 0;
that_cpu = bL_switcher_cpu_pairing[this_cpu];
ib_mpidr = cpu_logical_map(that_cpu);
ib_cpu = MPIDR_AFFINITY_LEVEL(ib_mpidr, 0);
ib_cluster = MPIDR_AFFINITY_LEVEL(ib_mpidr, 1);
pr_debug("before switch: CPU %d MPIDR %#x -> %#x\n",
this_cpu, ob_mpidr, ib_mpidr);
this_cpu = smp_processor_id();
mcpm_set_entry_vector(ob_cpu, ob_cluster, NULL);
mcpm_set_entry_vector(ib_cpu, ib_cluster, NULL);
init_completion(&inbound_alive);
ipi_nr = register_ipi_completion(&inbound_alive, this_cpu);
ipi_nr |= ((1 << 16) << bL_gic_id[ob_cpu][ob_cluster]);
mcpm_set_early_poke(ib_cpu, ib_cluster, gic_get_sgir_physaddr(), ipi_nr);
ret = mcpm_cpu_power_up(ib_cpu, ib_cluster);
if (ret) {
pr_err("%s: mcpm_cpu_power_up() returned %d\n", __func__, ret);
return ret;
}
gic_send_sgi(bL_gic_id[ib_cpu][ib_cluster], 0);
wait_for_completion(&inbound_alive);
mcpm_set_early_poke(ib_cpu, ib_cluster, 0, 0);
local_irq_disable();
local_fiq_disable();
trace_cpu_migrate_begin(ktime_get_real_ns(), ob_mpidr);
gic_migrate_target(bL_gic_id[ib_cpu][ib_cluster]);
tick_suspend_local();
ret = cpu_pm_enter();
if (ret)
panic("%s: cpu_pm_enter() returned %d\n", __func__, ret);
cpu_logical_map(this_cpu) = ib_mpidr;
cpu_logical_map(that_cpu) = ob_mpidr;
ret = cpu_suspend((unsigned long)&handshake_ptr, bL_switchpoint);
if (ret > 0)
panic("%s: cpu_suspend() returned %d\n", __func__, ret);
mpidr = read_mpidr();
pr_debug("after switch: CPU %d MPIDR %#x\n", this_cpu, mpidr);
BUG_ON(mpidr != ib_mpidr);
mcpm_cpu_powered_up();
ret = cpu_pm_exit();
tick_resume_local();
trace_cpu_migrate_finish(ktime_get_real_ns(), ib_mpidr);
local_fiq_enable();
local_irq_enable();
*handshake_ptr = 1;
dsb_sev();
if (ret)
pr_err("%s exiting with error %d\n", __func__, ret);
return ret;
}
static int bL_switcher_thread(void *arg)
{
struct bL_thread *t = arg;
struct sched_param param = { .sched_priority = 1 };
int cluster;
bL_switch_completion_handler completer;
void *completer_cookie;
sched_setscheduler_nocheck(current, SCHED_FIFO, &param);
complete(&t->started);
do {
if (signal_pending(current))
flush_signals(current);
wait_event_interruptible(t->wq,
t->wanted_cluster != -1 ||
kthread_should_stop());
spin_lock(&t->lock);
cluster = t->wanted_cluster;
completer = t->completer;
completer_cookie = t->completer_cookie;
t->wanted_cluster = -1;
t->completer = NULL;
spin_unlock(&t->lock);
if (cluster != -1) {
bL_switch_to(cluster);
if (completer)
completer(completer_cookie);
}
} while (!kthread_should_stop());
return 0;
}
static struct task_struct *bL_switcher_thread_create(int cpu, void *arg)
{
struct task_struct *task;
task = kthread_create_on_node(bL_switcher_thread, arg,
cpu_to_node(cpu), "kswitcher_%d", cpu);
if (!IS_ERR(task)) {
kthread_bind(task, cpu);
wake_up_process(task);
} else
pr_err("%s failed for CPU %d\n", __func__, cpu);
return task;
}
int bL_switch_request_cb(unsigned int cpu, unsigned int new_cluster_id,
bL_switch_completion_handler completer,
void *completer_cookie)
{
struct bL_thread *t;
if (cpu >= ARRAY_SIZE(bL_threads)) {
pr_err("%s: cpu %d out of bounds\n", __func__, cpu);
return -EINVAL;
}
t = &bL_threads[cpu];
if (IS_ERR(t->task))
return PTR_ERR(t->task);
if (!t->task)
return -ESRCH;
spin_lock(&t->lock);
if (t->completer) {
spin_unlock(&t->lock);
return -EBUSY;
}
t->completer = completer;
t->completer_cookie = completer_cookie;
t->wanted_cluster = new_cluster_id;
spin_unlock(&t->lock);
wake_up(&t->wq);
return 0;
}
int bL_switcher_register_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&bL_activation_notifier, nb);
}
int bL_switcher_unregister_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&bL_activation_notifier, nb);
}
static int bL_activation_notify(unsigned long val)
{
int ret;
ret = blocking_notifier_call_chain(&bL_activation_notifier, val, NULL);
if (ret & NOTIFY_STOP_MASK)
pr_err("%s: notifier chain failed with status 0x%x\n",
__func__, ret);
return notifier_to_errno(ret);
}
static void bL_switcher_restore_cpus(void)
{
int i;
for_each_cpu(i, &bL_switcher_removed_logical_cpus) {
struct device *cpu_dev = get_cpu_device(i);
int ret = device_online(cpu_dev);
if (ret)
dev_err(cpu_dev, "switcher: unable to restore CPU\n");
}
}
static int bL_switcher_halve_cpus(void)
{
int i, j, cluster_0, gic_id, ret;
unsigned int cpu, cluster, mask;
cpumask_t available_cpus;
mask = 0;
for_each_online_cpu(i) {
cpu = MPIDR_AFFINITY_LEVEL(cpu_logical_map(i), 0);
cluster = MPIDR_AFFINITY_LEVEL(cpu_logical_map(i), 1);
if (cluster >= 2) {
pr_err("%s: only dual cluster systems are supported\n", __func__);
return -EINVAL;
}
if (WARN_ON(cpu >= MAX_CPUS_PER_CLUSTER))
return -EINVAL;
mask |= (1 << cluster);
}
if (mask != 3) {
pr_err("%s: no CPU pairing possible\n", __func__);
return -EINVAL;
}
memset(bL_switcher_cpu_pairing, -1, sizeof(bL_switcher_cpu_pairing));
cpumask_copy(&available_cpus, cpu_online_mask);
cluster_0 = -1;
for_each_cpu(i, &available_cpus) {
int match = -1;
cluster = MPIDR_AFFINITY_LEVEL(cpu_logical_map(i), 1);
if (cluster_0 == -1)
cluster_0 = cluster;
if (cluster != cluster_0)
continue;
cpumask_clear_cpu(i, &available_cpus);
for_each_cpu(j, &available_cpus) {
cluster = MPIDR_AFFINITY_LEVEL(cpu_logical_map(j), 1);
if (cluster != cluster_0)
match = j;
}
if (match != -1) {
bL_switcher_cpu_pairing[i] = match;
cpumask_clear_cpu(match, &available_cpus);
pr_info("CPU%d paired with CPU%d\n", i, match);
}
}
cpumask_clear(&bL_switcher_removed_logical_cpus);
for_each_online_cpu(i) {
cpu = MPIDR_AFFINITY_LEVEL(cpu_logical_map(i), 0);
cluster = MPIDR_AFFINITY_LEVEL(cpu_logical_map(i), 1);
gic_id = gic_get_cpu_id(i);
if (gic_id < 0) {
pr_err("%s: bad GIC ID for CPU %d\n", __func__, i);
bL_switcher_restore_cpus();
return -EINVAL;
}
bL_gic_id[cpu][cluster] = gic_id;
pr_info("GIC ID for CPU %u cluster %u is %u\n",
cpu, cluster, gic_id);
if (bL_switcher_cpu_pairing[i] != -1) {
bL_switcher_cpu_original_cluster[i] = cluster;
continue;
}
ret = device_offline(get_cpu_device(i));
if (ret) {
bL_switcher_restore_cpus();
return ret;
}
cpumask_set_cpu(i, &bL_switcher_removed_logical_cpus);
}
return 0;
}
int bL_switcher_get_logical_index(u32 mpidr)
{
int cpu;
if (!bL_switcher_active)
return -EUNATCH;
mpidr &= MPIDR_HWID_BITMASK;
for_each_online_cpu(cpu) {
int pairing = bL_switcher_cpu_pairing[cpu];
if (pairing == -1)
continue;
if ((mpidr == cpu_logical_map(cpu)) ||
(mpidr == cpu_logical_map(pairing)))
return cpu;
}
return -EINVAL;
}
static void bL_switcher_trace_trigger_cpu(void *__always_unused info)
{
trace_cpu_migrate_current(ktime_get_real_ns(), read_mpidr());
}
int bL_switcher_trace_trigger(void)
{
int ret;
preempt_disable();
bL_switcher_trace_trigger_cpu(NULL);
ret = smp_call_function(bL_switcher_trace_trigger_cpu, NULL, true);
preempt_enable();
return ret;
}
static int bL_switcher_enable(void)
{
int cpu, ret;
mutex_lock(&bL_switcher_activation_lock);
lock_device_hotplug();
if (bL_switcher_active) {
unlock_device_hotplug();
mutex_unlock(&bL_switcher_activation_lock);
return 0;
}
pr_info("big.LITTLE switcher initializing\n");
ret = bL_activation_notify(BL_NOTIFY_PRE_ENABLE);
if (ret)
goto error;
ret = bL_switcher_halve_cpus();
if (ret)
goto error;
bL_switcher_trace_trigger();
for_each_online_cpu(cpu) {
struct bL_thread *t = &bL_threads[cpu];
spin_lock_init(&t->lock);
init_waitqueue_head(&t->wq);
init_completion(&t->started);
t->wanted_cluster = -1;
t->task = bL_switcher_thread_create(cpu, t);
}
bL_switcher_active = 1;
bL_activation_notify(BL_NOTIFY_POST_ENABLE);
pr_info("big.LITTLE switcher initialized\n");
goto out;
error:
pr_warn("big.LITTLE switcher initialization failed\n");
bL_activation_notify(BL_NOTIFY_POST_DISABLE);
out:
unlock_device_hotplug();
mutex_unlock(&bL_switcher_activation_lock);
return ret;
}
static void bL_switcher_disable(void)
{
unsigned int cpu, cluster;
struct bL_thread *t;
struct task_struct *task;
mutex_lock(&bL_switcher_activation_lock);
lock_device_hotplug();
if (!bL_switcher_active)
goto out;
if (bL_activation_notify(BL_NOTIFY_PRE_DISABLE) != 0) {
bL_activation_notify(BL_NOTIFY_POST_ENABLE);
goto out;
}
bL_switcher_active = 0;
for_each_online_cpu(cpu) {
t = &bL_threads[cpu];
task = t->task;
t->task = NULL;
if (!task || IS_ERR(task))
continue;
kthread_stop(task);
cluster = MPIDR_AFFINITY_LEVEL(cpu_logical_map(cpu), 1);
if (cluster == bL_switcher_cpu_original_cluster[cpu])
continue;
init_completion(&t->started);
t->wanted_cluster = bL_switcher_cpu_original_cluster[cpu];
task = bL_switcher_thread_create(cpu, t);
if (!IS_ERR(task)) {
wait_for_completion(&t->started);
kthread_stop(task);
cluster = MPIDR_AFFINITY_LEVEL(cpu_logical_map(cpu), 1);
if (cluster == bL_switcher_cpu_original_cluster[cpu])
continue;
}
pr_crit("%s: unable to restore original cluster for CPU %d\n",
__func__, cpu);
pr_crit("%s: CPU %d can't be restored\n",
__func__, bL_switcher_cpu_pairing[cpu]);
cpumask_clear_cpu(bL_switcher_cpu_pairing[cpu],
&bL_switcher_removed_logical_cpus);
}
bL_switcher_restore_cpus();
bL_switcher_trace_trigger();
bL_activation_notify(BL_NOTIFY_POST_DISABLE);
out:
unlock_device_hotplug();
mutex_unlock(&bL_switcher_activation_lock);
}
static ssize_t bL_switcher_active_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", bL_switcher_active);
}
static ssize_t bL_switcher_active_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
int ret;
switch (buf[0]) {
case '0':
bL_switcher_disable();
ret = 0;
break;
case '1':
ret = bL_switcher_enable();
break;
default:
ret = -EINVAL;
}
return (ret >= 0) ? count : ret;
}
static ssize_t bL_switcher_trace_trigger_store(struct kobject *kobj,
struct kobj_attribute *attr, const char *buf, size_t count)
{
int ret = bL_switcher_trace_trigger();
return ret ? ret : count;
}
static int __init bL_switcher_sysfs_init(void)
{
int ret;
bL_switcher_kobj = kobject_create_and_add("bL_switcher", kernel_kobj);
if (!bL_switcher_kobj)
return -ENOMEM;
ret = sysfs_create_group(bL_switcher_kobj, &bL_switcher_attr_group);
if (ret)
kobject_put(bL_switcher_kobj);
return ret;
}
bool bL_switcher_get_enabled(void)
{
mutex_lock(&bL_switcher_activation_lock);
return bL_switcher_active;
}
void bL_switcher_put_enabled(void)
{
mutex_unlock(&bL_switcher_activation_lock);
}
static int bL_switcher_hotplug_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
if (bL_switcher_active) {
int pairing = bL_switcher_cpu_pairing[(unsigned long)hcpu];
switch (action & 0xf) {
case CPU_UP_PREPARE:
case CPU_DOWN_PREPARE:
if (pairing == -1)
return NOTIFY_BAD;
}
}
return NOTIFY_DONE;
}
static int __init bL_switcher_init(void)
{
int ret;
if (!mcpm_is_available())
return -ENODEV;
cpu_notifier(bL_switcher_hotplug_callback, 0);
if (!no_bL_switcher) {
ret = bL_switcher_enable();
if (ret)
return ret;
}
#ifdef CONFIG_SYSFS
ret = bL_switcher_sysfs_init();
if (ret)
pr_err("%s: unable to create sysfs entry\n", __func__);
#endif
return 0;
}
