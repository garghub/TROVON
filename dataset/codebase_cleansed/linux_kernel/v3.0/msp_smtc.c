static void msp_smtc_send_ipi_single(int cpu, unsigned int action)
{
smtc_send_ipi(cpu, LINUX_SMP_IPI, action);
}
static void msp_smtc_send_ipi_mask(const struct cpumask *mask,
unsigned int action)
{
unsigned int i;
for_each_cpu(i, mask)
msp_smtc_send_ipi_single(i, action);
}
static void __cpuinit msp_smtc_init_secondary(void)
{
int myvpe;
myvpe = read_c0_tcbind() & TCBIND_CURVPE;
if (myvpe > 0)
change_c0_status(ST0_IM, STATUSF_IP0 | STATUSF_IP1 |
STATUSF_IP6 | STATUSF_IP7);
smtc_init_secondary();
}
static void __cpuinit msp_smtc_boot_secondary(int cpu,
struct task_struct *idle)
{
smtc_boot_secondary(cpu, idle);
}
static void __cpuinit msp_smtc_smp_finish(void)
{
smtc_smp_finish();
}
static void msp_smtc_cpus_done(void)
{
}
static void __init msp_smtc_smp_setup(void)
{
if (read_c0_config3() & (1 << 2))
smp_num_siblings = smtc_build_cpu_map(0);
}
static void __init msp_smtc_prepare_cpus(unsigned int max_cpus)
{
smtc_prepare_cpus(max_cpus);
}
