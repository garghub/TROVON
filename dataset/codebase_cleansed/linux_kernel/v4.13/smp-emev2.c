static int emev2_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
arch_send_wakeup_ipi_mask(cpumask_of(cpu_logical_map(cpu)));
return 0;
}
static void __init emev2_smp_prepare_cpus(unsigned int max_cpus)
{
void __iomem *smu;
smu = ioremap(EMEV2_SMU_BASE, PAGE_SIZE);
if (smu) {
iowrite32(__pa(shmobile_boot_vector), smu + SMU_GENERAL_REG0);
iounmap(smu);
}
shmobile_smp_scu_prepare_cpus(EMEV2_SCU_BASE, max_cpus);
}
