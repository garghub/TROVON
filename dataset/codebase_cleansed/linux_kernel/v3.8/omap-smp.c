void __iomem *omap4_get_scu_base(void)
{
return scu_base;
}
static void __cpuinit omap4_secondary_init(unsigned int cpu)
{
if (cpu_is_omap443x() && (omap_type() != OMAP2_DEVICE_TYPE_GP))
omap_secure_dispatcher(OMAP4_PPA_CPU_ACTRL_SMP_INDEX,
4, 0, 0, 0, 0, 0);
gic_secondary_init(0);
spin_lock(&boot_lock);
spin_unlock(&boot_lock);
}
static int __cpuinit omap4_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
static struct clockdomain *cpu1_clkdm;
static bool booted;
void __iomem *base = omap_get_wakeupgen_base();
spin_lock(&boot_lock);
if (omap_secure_apis_support())
omap_modify_auxcoreboot0(0x200, 0xfffffdff);
else
__raw_writel(0x20, base + OMAP_AUX_CORE_BOOT_0);
flush_cache_all();
smp_wmb();
if (!cpu1_clkdm)
cpu1_clkdm = clkdm_lookup("mpu1_clkdm");
if (booted) {
if (IS_PM44XX_ERRATUM(PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD)) {
local_irq_disable();
gic_dist_disable();
}
clkdm_wakeup(cpu1_clkdm);
clkdm_allow_idle(cpu1_clkdm);
if (IS_PM44XX_ERRATUM(PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD)) {
while (gic_dist_disabled()) {
udelay(1);
cpu_relax();
}
gic_timer_retrigger();
local_irq_enable();
}
} else {
dsb_sev();
booted = true;
}
gic_raise_softirq(cpumask_of(cpu), 0);
spin_unlock(&boot_lock);
return 0;
}
static void __init wakeup_secondary(void)
{
void *startup_addr = omap_secondary_startup;
void __iomem *base = omap_get_wakeupgen_base();
if (cpu_is_omap446x()) {
startup_addr = omap_secondary_startup_4460;
pm44xx_errata |= PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD;
}
if (omap_secure_apis_support())
omap_auxcoreboot_addr(virt_to_phys(startup_addr));
else
__raw_writel(virt_to_phys(omap5_secondary_startup),
base + OMAP_AUX_CORE_BOOT_1);
smp_wmb();
dsb_sev();
mb();
}
static void __init omap4_smp_init_cpus(void)
{
unsigned int i = 0, ncores = 1, cpu_id;
cpu_id = read_cpuid(CPUID_ID) & CPU_MASK;
if (cpu_id == CPU_CORTEX_A9) {
scu_base = OMAP2_L4_IO_ADDRESS(OMAP44XX_SCU_BASE);
BUG_ON(!scu_base);
ncores = scu_get_core_count(scu_base);
} else if (cpu_id == CPU_CORTEX_A15) {
ncores = OMAP5_CORE_COUNT;
}
if (ncores > nr_cpu_ids) {
pr_warn("SMP: %u cores greater than maximum (%u), clipping\n",
ncores, nr_cpu_ids);
ncores = nr_cpu_ids;
}
for (i = 0; i < ncores; i++)
set_cpu_possible(i, true);
set_smp_cross_call(gic_raise_softirq);
}
static void __init omap4_smp_prepare_cpus(unsigned int max_cpus)
{
if (scu_base)
scu_enable(scu_base);
wakeup_secondary();
}
