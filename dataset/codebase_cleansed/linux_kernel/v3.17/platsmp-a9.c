static int __cpuinit mvebu_cortex_a9_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
int ret, hw_cpu;
pr_info("Booting CPU %d\n", cpu);
hw_cpu = cpu_logical_map(cpu);
if (of_machine_is_compatible("marvell,armada375"))
mvebu_system_controller_set_cpu_boot_addr(mvebu_cortex_a9_secondary_startup);
else
mvebu_pmsu_set_cpu_boot_addr(hw_cpu, mvebu_cortex_a9_secondary_startup);
smp_wmb();
ret = mvebu_cpu_reset_deassert(hw_cpu);
if (ret) {
pr_err("Could not start the secondary CPU: %d\n", ret);
return ret;
}
arch_send_wakeup_ipi_mask(cpumask_of(cpu));
return 0;
}
