void mvebu_pmsu_set_cpu_boot_addr(int hw_cpu, void *boot_addr)
{
writel(virt_to_phys(boot_addr), pmsu_mp_base +
PMSU_BOOT_ADDR_REDIRECT_OFFSET(hw_cpu));
}
static int __init armada_370_xp_pmsu_init(void)
{
struct device_node *np;
struct resource res;
int ret = 0;
np = of_find_matching_node(NULL, of_pmsu_table);
if (!np)
return 0;
pr_info("Initializing Power Management Service Unit\n");
if (of_address_to_resource(np, 0, &res)) {
pr_err("unable to get resource\n");
ret = -ENOENT;
goto out;
}
if (of_device_is_compatible(np, "marvell,armada-370-xp-pmsu")) {
pr_warn(FW_WARN "deprecated pmsu binding\n");
res.start = res.start - PMSU_BASE_OFFSET;
res.end = res.start + PMSU_REG_SIZE - 1;
}
if (!request_mem_region(res.start, resource_size(&res),
np->full_name)) {
pr_err("unable to request region\n");
ret = -EBUSY;
goto out;
}
pmsu_mp_base = ioremap(res.start, resource_size(&res));
if (!pmsu_mp_base) {
pr_err("unable to map registers\n");
release_mem_region(res.start, resource_size(&res));
ret = -ENOMEM;
goto out;
}
out:
of_node_put(np);
return ret;
}
static void armada_370_xp_pmsu_enable_l2_powerdown_onidle(void)
{
u32 reg;
if (pmsu_mp_base == NULL)
return;
reg = readl(pmsu_mp_base + L2C_NFABRIC_PM_CTL);
reg |= L2C_NFABRIC_PM_CTL_PWR_DOWN;
writel(reg, pmsu_mp_base + L2C_NFABRIC_PM_CTL);
}
void armada_370_xp_pmsu_idle_prepare(bool deepidle)
{
unsigned int hw_cpu = cpu_logical_map(smp_processor_id());
u32 reg;
if (pmsu_mp_base == NULL)
return;
reg = readl(pmsu_mp_base + PMSU_STATUS_AND_MASK(hw_cpu));
reg |= PMSU_STATUS_AND_MASK_CPU_IDLE_WAIT |
PMSU_STATUS_AND_MASK_IRQ_WAKEUP |
PMSU_STATUS_AND_MASK_FIQ_WAKEUP |
PMSU_STATUS_AND_MASK_SNP_Q_EMPTY_WAIT |
PMSU_STATUS_AND_MASK_IRQ_MASK |
PMSU_STATUS_AND_MASK_FIQ_MASK;
writel(reg, pmsu_mp_base + PMSU_STATUS_AND_MASK(hw_cpu));
reg = readl(pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(hw_cpu));
if (deepidle)
reg |= PMSU_CONTROL_AND_CONFIG_L2_PWDDN;
reg |= PMSU_CONTROL_AND_CONFIG_PWDDN_REQ;
writel(reg, pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(hw_cpu));
reg = readl(pmsu_mp_base + PMSU_CPU_POWER_DOWN_CONTROL(hw_cpu));
reg |= PMSU_CPU_POWER_DOWN_DIS_SNP_Q_SKIP;
writel(reg, pmsu_mp_base + PMSU_CPU_POWER_DOWN_CONTROL(hw_cpu));
}
static noinline int do_armada_370_xp_cpu_suspend(unsigned long deepidle)
{
armada_370_xp_pmsu_idle_prepare(deepidle);
v7_exit_coherency_flush(all);
ll_disable_coherency();
dsb();
wfi();
local_flush_tlb_all();
ll_enable_coherency();
asm volatile(
"mrc p15, 0, r0, c1, c0, 0 \n\t"
"tst r0, #(1 << 2) \n\t"
"orreq r0, r0, #(1 << 2) \n\t"
"mcreq p15, 0, r0, c1, c0, 0 \n\t"
"isb "
: : : "r0");
pr_warn("Failed to suspend the system\n");
return 0;
}
static int armada_370_xp_cpu_suspend(unsigned long deepidle)
{
return cpu_suspend(deepidle, do_armada_370_xp_cpu_suspend);
}
static noinline void armada_370_xp_pmsu_idle_restore(void)
{
unsigned int hw_cpu = cpu_logical_map(smp_processor_id());
u32 reg;
if (pmsu_mp_base == NULL)
return;
reg = readl(pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(hw_cpu));
reg &= ~PMSU_CONTROL_AND_CONFIG_L2_PWDDN;
writel(reg, pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(hw_cpu));
reg = readl(pmsu_mp_base + PMSU_STATUS_AND_MASK(hw_cpu));
reg &= ~(PMSU_STATUS_AND_MASK_IRQ_WAKEUP | PMSU_STATUS_AND_MASK_FIQ_WAKEUP);
reg &= ~PMSU_STATUS_AND_MASK_CPU_IDLE_WAIT;
reg &= ~PMSU_STATUS_AND_MASK_SNP_Q_EMPTY_WAIT;
reg &= ~(PMSU_STATUS_AND_MASK_IRQ_MASK | PMSU_STATUS_AND_MASK_FIQ_MASK);
writel(reg, pmsu_mp_base + PMSU_STATUS_AND_MASK(hw_cpu));
}
static int armada_370_xp_cpu_pm_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if (action == CPU_PM_ENTER) {
unsigned int hw_cpu = cpu_logical_map(smp_processor_id());
mvebu_pmsu_set_cpu_boot_addr(hw_cpu, armada_370_xp_cpu_resume);
} else if (action == CPU_PM_EXIT) {
armada_370_xp_pmsu_idle_restore();
}
return NOTIFY_OK;
}
int __init armada_370_xp_cpu_pm_init(void)
{
struct device_node *np;
if (!of_machine_is_compatible("marvell,armadaxp"))
return 0;
np = of_find_compatible_node(NULL, NULL, "marvell,coherency-fabric");
if (!np)
return 0;
of_node_put(np);
np = of_find_matching_node(NULL, of_pmsu_table);
if (!np)
return 0;
of_node_put(np);
armada_370_xp_pmsu_enable_l2_powerdown_onidle();
armada_xp_cpuidle_device.dev.platform_data = armada_370_xp_cpu_suspend;
platform_device_register(&armada_xp_cpuidle_device);
cpu_pm_register_notifier(&armada_370_xp_cpu_pm_notifier);
return 0;
}
