static int __init smp_psci_init_cpu(struct device_node *dn, int cpu)
{
return 0;
}
static int __init smp_psci_prepare_cpu(int cpu)
{
int err;
if (!psci_ops.cpu_on) {
pr_err("psci: no cpu_on method, not booting CPU%d\n", cpu);
return -ENODEV;
}
err = psci_ops.cpu_on(cpu_logical_map(cpu), __pa(secondary_holding_pen));
if (err) {
pr_err("psci: failed to boot CPU%d (%d)\n", cpu, err);
return err;
}
return 0;
}
