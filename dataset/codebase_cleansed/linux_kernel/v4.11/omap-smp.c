void __iomem *omap4_get_scu_base(void)
{
return cfg.scu_base;
}
void omap5_erratum_workaround_801819(void)
{
u32 acr, revidr;
u32 acr_mask;
asm volatile ("mrc p15, 0, %0, c0, c0, 6" : "=r" (revidr));
if (revidr & (0x1 << 3))
return;
asm volatile ("mrc p15, 0, %0, c1, c0, 1" : "=r" (acr));
acr_mask = (0x3 << 25) | (0x3 << 27);
if ((acr & acr_mask) == acr_mask)
return;
acr |= acr_mask;
omap_smc1(OMAP5_DRA7_MON_SET_ACR_INDEX, acr);
pr_debug("%s: ARM erratum workaround 801819 applied on CPU%d\n",
__func__, smp_processor_id());
}
static inline void omap5_erratum_workaround_801819(void) { }
static void omap4_secondary_init(unsigned int cpu)
{
if (soc_is_omap443x() && (omap_type() != OMAP2_DEVICE_TYPE_GP))
omap_secure_dispatcher(OMAP4_PPA_CPU_ACTRL_SMP_INDEX,
4, 0, 0, 0, 0, 0);
if (soc_is_omap54xx() || soc_is_dra7xx()) {
set_cntfreq();
omap5_erratum_workaround_801819();
}
spin_lock(&boot_lock);
spin_unlock(&boot_lock);
}
static int omap4_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
static struct clockdomain *cpu1_clkdm;
static bool booted;
static struct powerdomain *cpu1_pwrdm;
spin_lock(&boot_lock);
if (omap_secure_apis_support())
omap_modify_auxcoreboot0(AUX_CORE_BOOT0_HS_RELEASE,
0xfffffdff);
else
writel_relaxed(AUX_CORE_BOOT0_GP_RELEASE,
cfg.wakeupgen_base + OMAP_AUX_CORE_BOOT_0);
if (!cpu1_clkdm && !cpu1_pwrdm) {
cpu1_clkdm = clkdm_lookup("mpu1_clkdm");
cpu1_pwrdm = pwrdm_lookup("cpu1_pwrdm");
}
if (booted && cpu1_pwrdm && cpu1_clkdm) {
if (IS_PM44XX_ERRATUM(PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD)) {
local_irq_disable();
gic_dist_disable();
}
clkdm_deny_idle_nolock(cpu1_clkdm);
pwrdm_set_next_pwrst(cpu1_pwrdm, PWRDM_POWER_ON);
clkdm_allow_idle_nolock(cpu1_clkdm);
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
cfg.scu_base = OMAP2_L4_IO_ADDRESS(scu_a9_get_base());
BUG_ON(!cfg.scu_base);
ncores = scu_get_core_count(cfg.scu_base);
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
static bool __init omap4_smp_cpu1_startup_valid(unsigned long addr)
{
if ((addr >= __pa(PAGE_OFFSET)) && (addr <= __pa(__bss_start)))
return false;
return true;
}
static void __init omap4_smp_maybe_reset_cpu1(struct omap_smp_config *c)
{
unsigned long cpu1_startup_pa, cpu1_ns_pa_addr;
bool needs_reset = false;
u32 released;
if (omap_secure_apis_support())
released = omap_read_auxcoreboot0() & AUX_CORE_BOOT0_HS_RELEASE;
else
released = readl_relaxed(cfg.wakeupgen_base +
OMAP_AUX_CORE_BOOT_0) &
AUX_CORE_BOOT0_GP_RELEASE;
if (released) {
pr_warn("smp: CPU1 not parked?\n");
return;
}
cpu1_startup_pa = readl_relaxed(cfg.wakeupgen_base +
OMAP_AUX_CORE_BOOT_1);
cpu1_ns_pa_addr = omap4_get_cpu1_ns_pa_addr();
if (!omap4_smp_cpu1_startup_valid(cpu1_startup_pa))
needs_reset = true;
if ((soc_is_omap44xx() || soc_is_omap54xx()) &&
!omap4_smp_cpu1_startup_valid(cpu1_ns_pa_addr))
needs_reset = true;
if (!needs_reset || !c->cpu1_rstctrl_va)
return;
pr_info("smp: CPU1 parked within kernel, needs reset (0x%lx 0x%lx)\n",
cpu1_startup_pa, cpu1_ns_pa_addr);
writel_relaxed(1, c->cpu1_rstctrl_va);
readl_relaxed(c->cpu1_rstctrl_va);
writel_relaxed(0, c->cpu1_rstctrl_va);
}
static void __init omap4_smp_prepare_cpus(unsigned int max_cpus)
{
const struct omap_smp_config *c = NULL;
if (soc_is_omap443x())
c = &omap443x_cfg;
else if (soc_is_omap446x())
c = &omap446x_cfg;
else if (soc_is_dra74x() || soc_is_omap54xx())
c = &omap5_cfg;
if (!c) {
pr_err("%s Unknown SMP SoC?\n", __func__);
return;
}
cfg.cpu1_rstctrl_pa = c->cpu1_rstctrl_pa;
cfg.startup_addr = c->startup_addr;
cfg.wakeupgen_base = omap_get_wakeupgen_base();
if (soc_is_dra74x() || soc_is_omap54xx()) {
if ((__boot_cpu_mode & MODE_MASK) == HYP_MODE)
cfg.startup_addr = omap5_secondary_hyp_startup;
omap5_erratum_workaround_801819();
}
cfg.cpu1_rstctrl_va = ioremap(cfg.cpu1_rstctrl_pa, 4);
if (!cfg.cpu1_rstctrl_va)
return;
if (cfg.scu_base)
scu_enable(cfg.scu_base);
omap4_smp_maybe_reset_cpu1(&cfg);
if (omap_secure_apis_support())
omap_auxcoreboot_addr(__pa_symbol(cfg.startup_addr));
else
writel_relaxed(__pa_symbol(cfg.startup_addr),
cfg.wakeupgen_base + OMAP_AUX_CORE_BOOT_1);
}
