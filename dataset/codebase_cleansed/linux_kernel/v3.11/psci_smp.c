static int psci_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
if (psci_ops.cpu_on)
return psci_ops.cpu_on(cpu_logical_map(cpu),
__pa(secondary_startup));
return -ENODEV;
}
void __ref psci_cpu_die(unsigned int cpu)
{
const struct psci_power_state ps = {
.type = PSCI_POWER_STATE_TYPE_POWER_DOWN,
};
if (psci_ops.cpu_off)
psci_ops.cpu_off(ps);
panic("psci: cpu %d failed to shutdown\n", cpu);
}
bool __init psci_smp_available(void)
{
return (psci_ops.cpu_on != NULL);
}
