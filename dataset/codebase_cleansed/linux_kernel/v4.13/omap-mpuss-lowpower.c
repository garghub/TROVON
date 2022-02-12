static int default_finish_suspend(unsigned long cpu_state)
{
omap_do_wfi();
return 0;
}
static void dummy_cpu_resume(void)
{}
static void dummy_scu_prepare(unsigned int cpu_id, unsigned int cpu_state)
{}
static inline void set_cpu_wakeup_addr(unsigned int cpu_id, u32 addr)
{
struct omap4_cpu_pm_info *pm_info = &per_cpu(omap4_pm_info, cpu_id);
if (pm_info->wkup_sar_addr)
writel_relaxed(addr, pm_info->wkup_sar_addr);
}
static void scu_pwrst_prepare(unsigned int cpu_id, unsigned int cpu_state)
{
struct omap4_cpu_pm_info *pm_info = &per_cpu(omap4_pm_info, cpu_id);
u32 scu_pwr_st;
switch (cpu_state) {
case PWRDM_POWER_RET:
scu_pwr_st = SCU_PM_DORMANT;
break;
case PWRDM_POWER_OFF:
scu_pwr_st = SCU_PM_POWEROFF;
break;
case PWRDM_POWER_ON:
case PWRDM_POWER_INACTIVE:
default:
scu_pwr_st = SCU_PM_NORMAL;
break;
}
if (pm_info->scu_sar_addr)
writel_relaxed(scu_pwr_st, pm_info->scu_sar_addr);
}
static inline void mpuss_clear_prev_logic_pwrst(void)
{
u32 reg;
reg = omap4_prminst_read_inst_reg(OMAP4430_PRM_PARTITION,
OMAP4430_PRM_MPU_INST, OMAP4_RM_MPU_MPU_CONTEXT_OFFSET);
omap4_prminst_write_inst_reg(reg, OMAP4430_PRM_PARTITION,
OMAP4430_PRM_MPU_INST, OMAP4_RM_MPU_MPU_CONTEXT_OFFSET);
}
static inline void cpu_clear_prev_logic_pwrst(unsigned int cpu_id)
{
u32 reg;
if (cpu_id) {
reg = omap4_prcm_mpu_read_inst_reg(OMAP4430_PRCM_MPU_CPU1_INST,
cpu_context_offset);
omap4_prcm_mpu_write_inst_reg(reg, OMAP4430_PRCM_MPU_CPU1_INST,
cpu_context_offset);
} else {
reg = omap4_prcm_mpu_read_inst_reg(OMAP4430_PRCM_MPU_CPU0_INST,
cpu_context_offset);
omap4_prcm_mpu_write_inst_reg(reg, OMAP4430_PRCM_MPU_CPU0_INST,
cpu_context_offset);
}
}
static void l2x0_pwrst_prepare(unsigned int cpu_id, unsigned int save_state)
{
struct omap4_cpu_pm_info *pm_info = &per_cpu(omap4_pm_info, cpu_id);
if (pm_info->l2x0_sar_addr)
writel_relaxed(save_state, pm_info->l2x0_sar_addr);
}
static void __init save_l2x0_context(void)
{
void __iomem *l2x0_base = omap4_get_l2cache_base();
if (l2x0_base && sar_base) {
writel_relaxed(l2x0_saved_regs.aux_ctrl,
sar_base + L2X0_AUXCTRL_OFFSET);
writel_relaxed(l2x0_saved_regs.prefetch_ctrl,
sar_base + L2X0_PREFETCH_CTRL_OFFSET);
}
}
static void __init save_l2x0_context(void)
{}
int omap4_enter_lowpower(unsigned int cpu, unsigned int power_state)
{
struct omap4_cpu_pm_info *pm_info = &per_cpu(omap4_pm_info, cpu);
unsigned int save_state = 0, cpu_logic_state = PWRDM_POWER_RET;
unsigned int wakeup_cpu;
if (omap_rev() == OMAP4430_REV_ES1_0)
return -ENXIO;
switch (power_state) {
case PWRDM_POWER_ON:
case PWRDM_POWER_INACTIVE:
save_state = 0;
break;
case PWRDM_POWER_OFF:
cpu_logic_state = PWRDM_POWER_OFF;
save_state = 1;
break;
case PWRDM_POWER_RET:
if (IS_PM44XX_ERRATUM(PM_OMAP4_CPU_OSWR_DISABLE))
save_state = 0;
break;
default:
WARN_ON(1);
return -ENXIO;
}
pwrdm_pre_transition(NULL);
mpuss_clear_prev_logic_pwrst();
if ((pwrdm_read_next_pwrst(mpuss_pd) == PWRDM_POWER_RET) &&
(pwrdm_read_logic_retst(mpuss_pd) == PWRDM_POWER_OFF))
save_state = 2;
cpu_clear_prev_logic_pwrst(cpu);
pwrdm_set_next_pwrst(pm_info->pwrdm, power_state);
pwrdm_set_logic_retst(pm_info->pwrdm, cpu_logic_state);
set_cpu_wakeup_addr(cpu, __pa_symbol(omap_pm_ops.resume));
omap_pm_ops.scu_prepare(cpu, power_state);
l2x0_pwrst_prepare(cpu, save_state);
if (save_state)
cpu_suspend(save_state, omap_pm_ops.finish_suspend);
else
omap_pm_ops.finish_suspend(save_state);
if (IS_PM44XX_ERRATUM(PM_OMAP4_ROM_SMP_BOOT_ERRATUM_GICD) && cpu)
gic_dist_enable();
wakeup_cpu = smp_processor_id();
pwrdm_set_next_pwrst(pm_info->pwrdm, PWRDM_POWER_ON);
pwrdm_post_transition(NULL);
return 0;
}
int omap4_hotplug_cpu(unsigned int cpu, unsigned int power_state)
{
struct omap4_cpu_pm_info *pm_info = &per_cpu(omap4_pm_info, cpu);
unsigned int cpu_state = 0;
if (omap_rev() == OMAP4430_REV_ES1_0)
return -ENXIO;
power_state = pwrdm_get_valid_lp_state(pm_info->pwrdm,
false, power_state);
if (power_state == PWRDM_POWER_OFF)
cpu_state = 1;
pwrdm_clear_all_prev_pwrst(pm_info->pwrdm);
pwrdm_set_next_pwrst(pm_info->pwrdm, power_state);
set_cpu_wakeup_addr(cpu, __pa_symbol(omap_pm_ops.hotplug_restart));
omap_pm_ops.scu_prepare(cpu, power_state);
omap_pm_ops.finish_suspend(cpu_state);
pwrdm_set_next_pwrst(pm_info->pwrdm, PWRDM_POWER_ON);
return 0;
}
static void enable_mercury_retention_mode(void)
{
u32 reg;
reg = omap4_prcm_mpu_read_inst_reg(OMAP54XX_PRCM_MPU_DEVICE_INST,
OMAP54XX_PRCM_MPU_PRM_PSCON_COUNT_OFFSET);
reg |= BIT(24) | BIT(25);
omap4_prcm_mpu_write_inst_reg(reg, OMAP54XX_PRCM_MPU_DEVICE_INST,
OMAP54XX_PRCM_MPU_PRM_PSCON_COUNT_OFFSET);
}
int __init omap4_mpuss_init(void)
{
struct omap4_cpu_pm_info *pm_info;
if (omap_rev() == OMAP4430_REV_ES1_0) {
WARN(1, "Power Management not supported on OMAP4430 ES1.0\n");
return -ENODEV;
}
pm_info = &per_cpu(omap4_pm_info, 0x0);
if (sar_base) {
pm_info->scu_sar_addr = sar_base + SCU_OFFSET0;
if (cpu_is_omap44xx())
pm_info->wkup_sar_addr = sar_base +
CPU0_WAKEUP_NS_PA_ADDR_OFFSET;
else
pm_info->wkup_sar_addr = sar_base +
OMAP5_CPU0_WAKEUP_NS_PA_ADDR_OFFSET;
pm_info->l2x0_sar_addr = sar_base + L2X0_SAVE_OFFSET0;
}
pm_info->pwrdm = pwrdm_lookup("cpu0_pwrdm");
if (!pm_info->pwrdm) {
pr_err("Lookup failed for CPU0 pwrdm\n");
return -ENODEV;
}
pwrdm_clear_all_prev_pwrst(pm_info->pwrdm);
cpu_clear_prev_logic_pwrst(0);
pwrdm_set_next_pwrst(pm_info->pwrdm, PWRDM_POWER_ON);
pm_info = &per_cpu(omap4_pm_info, 0x1);
if (sar_base) {
pm_info->scu_sar_addr = sar_base + SCU_OFFSET1;
if (cpu_is_omap44xx())
pm_info->wkup_sar_addr = sar_base +
CPU1_WAKEUP_NS_PA_ADDR_OFFSET;
else
pm_info->wkup_sar_addr = sar_base +
OMAP5_CPU1_WAKEUP_NS_PA_ADDR_OFFSET;
pm_info->l2x0_sar_addr = sar_base + L2X0_SAVE_OFFSET1;
}
pm_info->pwrdm = pwrdm_lookup("cpu1_pwrdm");
if (!pm_info->pwrdm) {
pr_err("Lookup failed for CPU1 pwrdm\n");
return -ENODEV;
}
pwrdm_clear_all_prev_pwrst(pm_info->pwrdm);
cpu_clear_prev_logic_pwrst(1);
pwrdm_set_next_pwrst(pm_info->pwrdm, PWRDM_POWER_ON);
mpuss_pd = pwrdm_lookup("mpu_pwrdm");
if (!mpuss_pd) {
pr_err("Failed to lookup MPUSS power domain\n");
return -ENODEV;
}
pwrdm_clear_all_prev_pwrst(mpuss_pd);
mpuss_clear_prev_logic_pwrst();
if (sar_base) {
writel_relaxed((omap_type() != OMAP2_DEVICE_TYPE_GP) ? 1 : 0,
sar_base + OMAP_TYPE_OFFSET);
save_l2x0_context();
}
if (cpu_is_omap44xx()) {
omap_pm_ops.finish_suspend = omap4_finish_suspend;
omap_pm_ops.resume = omap4_cpu_resume;
omap_pm_ops.scu_prepare = scu_pwrst_prepare;
omap_pm_ops.hotplug_restart = omap4_secondary_startup;
cpu_context_offset = OMAP4_RM_CPU0_CPU0_CONTEXT_OFFSET;
} else if (soc_is_omap54xx() || soc_is_dra7xx()) {
cpu_context_offset = OMAP54XX_RM_CPU0_CPU0_CONTEXT_OFFSET;
enable_mercury_retention_mode();
}
if (cpu_is_omap446x())
omap_pm_ops.hotplug_restart = omap4460_secondary_startup;
return 0;
}
u32 omap4_get_cpu1_ns_pa_addr(void)
{
return old_cpu1_ns_pa_addr;
}
void __init omap4_mpuss_early_init(void)
{
unsigned long startup_pa;
void __iomem *ns_pa_addr;
if (!(soc_is_omap44xx() || soc_is_omap54xx()))
return;
sar_base = omap4_get_sar_ram_base();
if (soc_is_omap44xx())
ns_pa_addr = sar_base + CPU1_WAKEUP_NS_PA_ADDR_OFFSET;
else
ns_pa_addr = sar_base + OMAP5_CPU1_WAKEUP_NS_PA_ADDR_OFFSET;
old_cpu1_ns_pa_addr = readl_relaxed(ns_pa_addr);
if (soc_is_omap443x())
startup_pa = __pa_symbol(omap4_secondary_startup);
else if (soc_is_omap446x())
startup_pa = __pa_symbol(omap4460_secondary_startup);
else if ((__boot_cpu_mode & MODE_MASK) == HYP_MODE)
startup_pa = __pa_symbol(omap5_secondary_hyp_startup);
else
startup_pa = __pa_symbol(omap5_secondary_startup);
if (soc_is_omap44xx())
writel_relaxed(startup_pa, sar_base +
CPU1_WAKEUP_NS_PA_ADDR_OFFSET);
else
writel_relaxed(startup_pa, sar_base +
OMAP5_CPU1_WAKEUP_NS_PA_ADDR_OFFSET);
}
