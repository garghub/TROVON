static void up_send_ipi_single(int cpu, unsigned int action)
{
panic(KERN_ERR "%s called", __func__);
}
static inline void up_send_ipi_mask(const struct cpumask *mask,
unsigned int action)
{
panic(KERN_ERR "%s called", __func__);
}
static void up_init_secondary(void)
{
}
static void up_smp_finish(void)
{
}
static int up_boot_secondary(int cpu, struct task_struct *idle)
{
return 0;
}
static void __init up_smp_setup(void)
{
}
static void __init up_prepare_cpus(unsigned int max_cpus)
{
}
static int up_cpu_disable(void)
{
return -ENOSYS;
}
static void up_cpu_die(unsigned int cpu)
{
BUG();
}
