void __iomem *omap4_get_scu_base(void)
{
return scu_base;
}
static void omap4_secondary_init(unsigned int cpu)
{
if (cpu_is_omap443x() && (omap_type() != OMAP2_DEVICE_TYPE_GP))
omap_secure_dispatcher(OMAP4_PPA_CPU_ACTRL_SMP_INDEX,
4, 0, 0, 0, 0, 0);
if (soc_is_omap54xx() || soc_is_dra7xx())
set_cntfreq();
spin_lock(&boot_lock);
spin_unlock(&boot_lock);
}
static int omap4_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
static struct clockdomain *cpu1_clkdm;
static bool booted;
static struct powerdomain *cpu1_pwrdm;
void __iomem *base = omap_get_wakeupgen_base();
spin_lock(&boot_lock);
if (omap_secure_apis_support())
omap_modify_auxcoreboot0(0x200, 0xfffffdff);
else
writel_relaxed(0x20, base + OMAP_AUX_CORE_BOOT_0);
if (!cpu1_clkdm && !cpu1_pwrdm) {
cpu1_clkdm = clkdm_lookup("mpu1_clkdm");
cpu1_pwrdm = pwrdm_lookup("cpu1_pwrdm");
}
if (booted && cpu1_pwrdm && cpu1_clkdm) {
if (IS_PM44XX_ERRATUM(PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD)) {
local_irq_disable();
gic_dist_disable();
}
clkdm_wakeup(cpu1_clkdm);
omap_set_pwrdm_state(cpu1_pwrdm, PWRDM_POWER_ON);
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
arch_send_wakeup_ipi_mask(cpumask_of(cpu));
spin_unlock(&boot_lock);
return 0;
}
static void __init omap4_smp_init_cpus(void)
{
unsigned int i = 0, ncores = 1, cpu_id;
cpu_id = read_cpuid_id() & CPU_MASK;
if (cpu_id == CPU_CORTEX_A9) {
scu_base = OMAP2_L4_IO_ADDRESS(scu_a9_get_base());
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
}
static void __init omap4_smp_prepare_cpus(unsigned int max_cpus)
{
void *startup_addr = omap4_secondary_startup;
void __iomem *base = omap_get_wakeupgen_base();
if (scu_base)
scu_enable(scu_base);
if (cpu_is_omap446x())
startup_addr = omap4460_secondary_startup;
if (omap_secure_apis_support())
omap_auxcoreboot_addr(virt_to_phys(startup_addr));
else
if ((__boot_cpu_mode & MODE_MASK) == HYP_MODE)
writel_relaxed(virt_to_phys(omap5_secondary_hyp_startup),
base + OMAP_AUX_CORE_BOOT_1);
else
writel_relaxed(virt_to_phys(omap5_secondary_startup),
base + OMAP_AUX_CORE_BOOT_1);
}
