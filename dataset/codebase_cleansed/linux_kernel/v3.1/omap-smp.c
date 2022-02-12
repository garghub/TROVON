void __cpuinit platform_secondary_init(unsigned int cpu)
{
gic_secondary_init(0);
spin_lock(&boot_lock);
spin_unlock(&boot_lock);
}
int __cpuinit boot_secondary(unsigned int cpu, struct task_struct *idle)
{
spin_lock(&boot_lock);
omap_modify_auxcoreboot0(0x200, 0xfffffdff);
flush_cache_all();
smp_wmb();
gic_raise_softirq(cpumask_of(cpu), 1);
spin_unlock(&boot_lock);
return 0;
}
static void __init wakeup_secondary(void)
{
omap_auxcoreboot_addr(virt_to_phys(omap_secondary_startup));
smp_wmb();
dsb_sev();
mb();
}
void __init smp_init_cpus(void)
{
unsigned int i, ncores;
scu_base = ioremap(OMAP44XX_SCU_BASE, SZ_256);
BUG_ON(!scu_base);
ncores = scu_get_core_count(scu_base);
if (ncores > NR_CPUS) {
printk(KERN_WARNING
"OMAP4: no. of cores (%d) greater than configured "
"maximum of %d - clipping\n",
ncores, NR_CPUS);
ncores = NR_CPUS;
}
for (i = 0; i < ncores; i++)
set_cpu_possible(i, true);
set_smp_cross_call(gic_raise_softirq);
}
void __init platform_smp_prepare_cpus(unsigned int max_cpus)
{
scu_enable(scu_base);
wakeup_secondary();
}
