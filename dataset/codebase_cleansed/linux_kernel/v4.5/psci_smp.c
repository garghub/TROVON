static int psci_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
if (psci_ops.cpu_on)
return psci_ops.cpu_on(cpu_logical_map(cpu),
virt_to_idmap(&secondary_startup));
return -ENODEV;
}
int psci_cpu_disable(unsigned int cpu)
{
if (!psci_ops.cpu_off)
return -EOPNOTSUPP;
if (psci_tos_resident_on(cpu))
return -EPERM;
return 0;
}
void psci_cpu_die(unsigned int cpu)
{
u32 state = PSCI_POWER_STATE_TYPE_POWER_DOWN <<
PSCI_0_2_POWER_STATE_TYPE_SHIFT;
if (psci_ops.cpu_off)
psci_ops.cpu_off(state);
panic("psci: cpu %d failed to shutdown\n", cpu);
}
int psci_cpu_kill(unsigned int cpu)
{
int err, i;
if (!psci_ops.affinity_info)
return 1;
for (i = 0; i < 10; i++) {
err = psci_ops.affinity_info(cpu_logical_map(cpu), 0);
if (err == PSCI_0_2_AFFINITY_LEVEL_OFF) {
pr_info("CPU%d killed.\n", cpu);
return 1;
}
msleep(10);
pr_info("Retrying again to check for CPU kill\n");
}
pr_warn("CPU%d may not have shut down cleanly (AFFINITY_INFO reports %d)\n",
cpu, err);
return 0;
}
bool __init psci_smp_available(void)
{
return (psci_ops.cpu_on != NULL);
}
