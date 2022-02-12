static int cps_nc_enter(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
enum cps_pm_state pm_state;
int err;
if (!cpu_data[dev->cpu].core && (index > STATE_NC_WAIT))
index = STATE_NC_WAIT;
switch (index) {
case STATE_NC_WAIT:
pm_state = CPS_PM_NC_WAIT;
break;
case STATE_CLOCK_GATED:
pm_state = CPS_PM_CLOCK_GATED;
break;
case STATE_POWER_GATED:
pm_state = CPS_PM_POWER_GATED;
break;
default:
BUG();
return -EINVAL;
}
if ((pm_state == CPS_PM_POWER_GATED) && cpu_pm_enter())
return -EINTR;
err = cps_pm_enter_state(pm_state);
if (pm_state == CPS_PM_POWER_GATED)
cpu_pm_exit();
return err ?: index;
}
static void __init cps_cpuidle_unregister(void)
{
int cpu;
struct cpuidle_device *device;
for_each_possible_cpu(cpu) {
device = &per_cpu(cpuidle_dev, cpu);
cpuidle_unregister_device(device);
}
cpuidle_unregister_driver(&cps_driver);
}
static int __init cps_cpuidle_init(void)
{
int err, cpu, core, i;
struct cpuidle_device *device;
if (!cps_pm_support_state(CPS_PM_POWER_GATED))
cps_driver.state_count = STATE_CLOCK_GATED + 1;
if (!cps_pm_support_state(CPS_PM_CLOCK_GATED))
cps_driver.state_count = STATE_NC_WAIT + 1;
if (!cps_pm_support_state(CPS_PM_NC_WAIT))
cps_driver.state_count = STATE_WAIT + 1;
if (cps_driver.state_count < STATE_COUNT) {
pr_info("cpuidle-cps: limited to ");
switch (cps_driver.state_count - 1) {
case STATE_WAIT:
pr_cont("coherent wait\n");
break;
case STATE_NC_WAIT:
pr_cont("non-coherent wait\n");
break;
case STATE_CLOCK_GATED:
pr_cont("clock gating\n");
break;
}
}
if (coupled_coherence)
for (i = STATE_NC_WAIT; i < cps_driver.state_count; i++)
cps_driver.states[i].flags |= CPUIDLE_FLAG_COUPLED;
err = cpuidle_register_driver(&cps_driver);
if (err) {
pr_err("Failed to register CPS cpuidle driver\n");
return err;
}
for_each_possible_cpu(cpu) {
core = cpu_data[cpu].core;
device = &per_cpu(cpuidle_dev, cpu);
device->cpu = cpu;
#ifdef CONFIG_ARCH_NEEDS_CPU_IDLE_COUPLED
cpumask_copy(&device->coupled_cpus, &cpu_sibling_map[cpu]);
#endif
err = cpuidle_register_device(device);
if (err) {
pr_err("Failed to register CPU%d cpuidle device\n",
cpu);
goto err_out;
}
}
return 0;
err_out:
cps_cpuidle_unregister();
return err;
}
