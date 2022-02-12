static void ssmtc_send_ipi_single(int cpu, unsigned int action)
{
smtc_send_ipi(cpu, LINUX_SMP_IPI, action);
}
static inline void ssmtc_send_ipi_mask(const struct cpumask *mask,
unsigned int action)
{
unsigned int i;
for_each_cpu(i, mask)
ssmtc_send_ipi_single(i, action);
}
static void __cpuinit ssmtc_init_secondary(void)
{
smtc_init_secondary();
}
static void __cpuinit ssmtc_smp_finish(void)
{
smtc_smp_finish();
}
static void ssmtc_cpus_done(void)
{
}
static void __cpuinit ssmtc_boot_secondary(int cpu, struct task_struct *idle)
{
smtc_boot_secondary(cpu, idle);
}
static void __init ssmtc_smp_setup(void)
{
if (read_c0_config3() & (1 << 2))
mipsmt_build_cpu_map(0);
}
static void ssmtc_prepare_cpus(unsigned int max_cpus)
{
if (read_c0_config3() & (1 << 2)) {
mipsmt_prepare_cpus();
}
}
