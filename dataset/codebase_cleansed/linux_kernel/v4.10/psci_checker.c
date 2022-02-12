static int psci_ops_check(void)
{
int migrate_type = -1;
int cpu;
if (!(psci_ops.cpu_off && psci_ops.cpu_on && psci_ops.cpu_suspend)) {
pr_warn("Missing PSCI operations, aborting tests\n");
return -EOPNOTSUPP;
}
if (psci_ops.migrate_info_type)
migrate_type = psci_ops.migrate_info_type();
if (migrate_type == PSCI_0_2_TOS_UP_MIGRATE ||
migrate_type == PSCI_0_2_TOS_UP_NO_MIGRATE) {
for_each_online_cpu(cpu)
if (psci_tos_resident_on(cpu)) {
tos_resident_cpu = cpu;
break;
}
if (tos_resident_cpu == -1)
pr_warn("UP Trusted OS resides on no online CPU\n");
}
return 0;
}
static int find_clusters(const struct cpumask *cpus,
const struct cpumask **clusters)
{
unsigned int nb = 0;
cpumask_var_t tmp;
if (!alloc_cpumask_var(&tmp, GFP_KERNEL))
return -ENOMEM;
cpumask_copy(tmp, cpus);
while (!cpumask_empty(tmp)) {
const struct cpumask *cluster =
topology_core_cpumask(cpumask_any(tmp));
clusters[nb++] = cluster;
cpumask_andnot(tmp, tmp, cluster);
}
free_cpumask_var(tmp);
return nb;
}
static unsigned int down_and_up_cpus(const struct cpumask *cpus,
struct cpumask *offlined_cpus)
{
int cpu;
int err = 0;
cpumask_clear(offlined_cpus);
for_each_cpu(cpu, cpus) {
int ret = cpu_down(cpu);
if (cpumask_weight(offlined_cpus) + 1 == nb_available_cpus) {
if (ret != -EBUSY) {
pr_err("Unexpected return code %d while trying "
"to power down last online CPU %d\n",
ret, cpu);
++err;
}
} else if (cpu == tos_resident_cpu) {
if (ret != -EPERM) {
pr_err("Unexpected return code %d while trying "
"to power down TOS resident CPU %d\n",
ret, cpu);
++err;
}
} else if (ret != 0) {
pr_err("Error occurred (%d) while trying "
"to power down CPU %d\n", ret, cpu);
++err;
}
if (ret == 0)
cpumask_set_cpu(cpu, offlined_cpus);
}
for_each_cpu(cpu, offlined_cpus) {
int ret = cpu_up(cpu);
if (ret != 0) {
pr_err("Error occurred (%d) while trying "
"to power up CPU %d\n", ret, cpu);
++err;
} else {
cpumask_clear_cpu(cpu, offlined_cpus);
}
}
WARN_ON(!cpumask_empty(offlined_cpus) ||
num_online_cpus() != nb_available_cpus);
return err;
}
static int hotplug_tests(void)
{
int err;
cpumask_var_t offlined_cpus;
int i, nb_cluster;
const struct cpumask **clusters;
char *page_buf;
err = -ENOMEM;
if (!alloc_cpumask_var(&offlined_cpus, GFP_KERNEL))
return err;
clusters = kmalloc_array(nb_available_cpus, sizeof(*clusters),
GFP_KERNEL);
if (!clusters)
goto out_free_cpus;
page_buf = (char *)__get_free_page(GFP_KERNEL);
if (!page_buf)
goto out_free_clusters;
err = 0;
nb_cluster = find_clusters(cpu_online_mask, clusters);
pr_info("Trying to turn off and on again all CPUs\n");
err += down_and_up_cpus(cpu_online_mask, offlined_cpus);
for (i = 0; i < nb_cluster; ++i) {
int cluster_id =
topology_physical_package_id(cpumask_any(clusters[i]));
ssize_t len = cpumap_print_to_pagebuf(true, page_buf,
clusters[i]);
page_buf[len - 1] = '\0';
pr_info("Trying to turn off and on again cluster %d "
"(CPUs %s)\n", cluster_id, page_buf);
err += down_and_up_cpus(clusters[i], offlined_cpus);
}
free_page((unsigned long)page_buf);
out_free_clusters:
kfree(clusters);
out_free_cpus:
free_cpumask_var(offlined_cpus);
return err;
}
static void dummy_callback(unsigned long ignored) {}
static int suspend_cpu(int index, bool broadcast)
{
int ret;
arch_cpu_idle_enter();
if (broadcast) {
ret = tick_broadcast_enter();
if (ret) {
cpu_do_idle();
ret = 0;
goto out_arch_exit;
}
}
ret = CPU_PM_CPU_IDLE_ENTER(arm_cpuidle_suspend, index);
if (broadcast)
tick_broadcast_exit();
out_arch_exit:
arch_cpu_idle_exit();
return ret;
}
static int suspend_test_thread(void *arg)
{
int cpu = (long)arg;
int i, nb_suspend = 0, nb_shallow_sleep = 0, nb_err = 0;
struct sched_param sched_priority = { .sched_priority = MAX_RT_PRIO-1 };
struct cpuidle_device *dev;
struct cpuidle_driver *drv;
struct timer_list wakeup_timer;
wait_for_completion(&suspend_threads_started);
if (sched_setscheduler_nocheck(current, SCHED_FIFO, &sched_priority))
pr_warn("Failed to set suspend thread scheduler on CPU %d\n",
cpu);
dev = this_cpu_read(cpuidle_devices);
drv = cpuidle_get_cpu_driver(dev);
pr_info("CPU %d entering suspend cycles, states 1 through %d\n",
cpu, drv->state_count - 1);
setup_timer_on_stack(&wakeup_timer, dummy_callback, 0);
for (i = 0; i < NUM_SUSPEND_CYCLE; ++i) {
int index;
for (index = 1; index < drv->state_count; ++index) {
struct cpuidle_state *state = &drv->states[index];
bool broadcast = state->flags & CPUIDLE_FLAG_TIMER_STOP;
int ret;
mod_timer(&wakeup_timer, jiffies +
usecs_to_jiffies(state->target_residency));
local_irq_disable();
ret = suspend_cpu(index, broadcast);
local_irq_enable();
if (ret == index) {
++nb_suspend;
} else if (ret >= 0) {
++nb_shallow_sleep;
} else {
pr_err("Failed to suspend CPU %d: error %d "
"(requested state %d, cycle %d)\n",
cpu, ret, index, i);
++nb_err;
}
}
}
del_timer(&wakeup_timer);
if (atomic_dec_return_relaxed(&nb_active_threads) == 0)
complete(&suspend_threads_done);
sched_priority.sched_priority = 0;
if (sched_setscheduler_nocheck(current, SCHED_NORMAL, &sched_priority))
pr_warn("Failed to set suspend thread scheduler on CPU %d\n",
cpu);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop()) {
__set_current_state(TASK_RUNNING);
break;
}
schedule();
}
pr_info("CPU %d suspend test results: success %d, shallow states %d, errors %d\n",
cpu, nb_suspend, nb_shallow_sleep, nb_err);
return nb_err;
}
static int suspend_tests(void)
{
int i, cpu, err = 0;
struct task_struct **threads;
int nb_threads = 0;
threads = kmalloc_array(nb_available_cpus, sizeof(*threads),
GFP_KERNEL);
if (!threads)
return -ENOMEM;
cpuidle_pause_and_lock();
for_each_online_cpu(cpu) {
struct task_struct *thread;
struct cpuidle_device *dev = per_cpu(cpuidle_devices, cpu);
struct cpuidle_driver *drv = cpuidle_get_cpu_driver(dev);
if (!dev || !drv) {
pr_warn("cpuidle not available on CPU %d, ignoring\n",
cpu);
continue;
}
thread = kthread_create_on_cpu(suspend_test_thread,
(void *)(long)cpu, cpu,
"psci_suspend_test");
if (IS_ERR(thread))
pr_err("Failed to create kthread on CPU %d\n", cpu);
else
threads[nb_threads++] = thread;
}
if (nb_threads < 1) {
err = -ENODEV;
goto out;
}
atomic_set(&nb_active_threads, nb_threads);
for (i = 0; i < nb_threads; ++i)
wake_up_process(threads[i]);
complete_all(&suspend_threads_started);
wait_for_completion(&suspend_threads_done);
for (i = 0; i < nb_threads; ++i)
err += kthread_stop(threads[i]);
out:
cpuidle_resume_and_unlock();
kfree(threads);
return err;
}
static int __init psci_checker(void)
{
int ret;
nb_available_cpus = num_online_cpus();
ret = psci_ops_check();
if (ret)
return ret;
pr_info("PSCI checker started using %u CPUs\n", nb_available_cpus);
pr_info("Starting hotplug tests\n");
ret = hotplug_tests();
if (ret == 0)
pr_info("Hotplug tests passed OK\n");
else if (ret > 0)
pr_err("%d error(s) encountered in hotplug tests\n", ret);
else {
pr_err("Out of memory\n");
return ret;
}
pr_info("Starting suspend tests (%d cycles per state)\n",
NUM_SUSPEND_CYCLE);
ret = suspend_tests();
if (ret == 0)
pr_info("Suspend tests passed OK\n");
else if (ret > 0)
pr_err("%d error(s) encountered in suspend tests\n", ret);
else {
switch (ret) {
case -ENOMEM:
pr_err("Out of memory\n");
break;
case -ENODEV:
pr_warn("Could not start suspend tests on any CPU\n");
break;
}
}
pr_info("PSCI checker completed\n");
return ret < 0 ? ret : 0;
}
