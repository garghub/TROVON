void mvebu_pmsu_set_cpu_boot_addr(int hw_cpu, void *boot_addr)
{
writel(virt_to_phys(boot_addr), pmsu_mp_base +
PMSU_BOOT_ADDR_REDIRECT_OFFSET(hw_cpu));
}
int mvebu_setup_boot_addr_wa(unsigned int crypto_eng_target,
unsigned int crypto_eng_attribute,
phys_addr_t resume_addr_reg)
{
void __iomem *sram_virt_base;
u32 code_len = &mvebu_boot_wa_end - &mvebu_boot_wa_start;
mvebu_mbus_del_window(BOOTROM_BASE, BOOTROM_SIZE);
mvebu_mbus_add_window_by_id(crypto_eng_target, crypto_eng_attribute,
SRAM_PHYS_BASE, SZ_64K);
sram_virt_base = ioremap(SRAM_PHYS_BASE, SZ_64K);
if (!sram_virt_base) {
pr_err("Unable to map SRAM to setup the boot address WA\n");
return -ENOMEM;
}
memcpy(sram_virt_base, &mvebu_boot_wa_start, code_len);
__raw_writel((unsigned long)resume_addr_reg,
sram_virt_base + code_len - 4);
iounmap(sram_virt_base);
return 0;
}
static int __init mvebu_v7_pmsu_init(void)
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
pmsu_mp_phys_base = res.start;
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
static void mvebu_v7_pmsu_enable_l2_powerdown_onidle(void)
{
u32 reg;
if (pmsu_mp_base == NULL)
return;
reg = readl(pmsu_mp_base + L2C_NFABRIC_PM_CTL);
reg |= L2C_NFABRIC_PM_CTL_PWR_DOWN;
writel(reg, pmsu_mp_base + L2C_NFABRIC_PM_CTL);
}
static int mvebu_v7_pmsu_idle_prepare(unsigned long flags)
{
unsigned int hw_cpu = cpu_logical_map(smp_processor_id());
u32 reg;
if (pmsu_mp_base == NULL)
return -EINVAL;
reg = readl(pmsu_mp_base + PMSU_STATUS_AND_MASK(hw_cpu));
reg |= PMSU_STATUS_AND_MASK_CPU_IDLE_WAIT |
PMSU_STATUS_AND_MASK_IRQ_WAKEUP |
PMSU_STATUS_AND_MASK_FIQ_WAKEUP |
PMSU_STATUS_AND_MASK_SNP_Q_EMPTY_WAIT |
PMSU_STATUS_AND_MASK_IRQ_MASK |
PMSU_STATUS_AND_MASK_FIQ_MASK;
writel(reg, pmsu_mp_base + PMSU_STATUS_AND_MASK(hw_cpu));
reg = readl(pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(hw_cpu));
if (flags & PMSU_PREPARE_DEEP_IDLE)
reg |= PMSU_CONTROL_AND_CONFIG_L2_PWDDN;
reg |= PMSU_CONTROL_AND_CONFIG_PWDDN_REQ;
writel(reg, pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(hw_cpu));
if (flags & PMSU_PREPARE_SNOOP_DISABLE) {
reg = readl(pmsu_mp_base + PMSU_CPU_POWER_DOWN_CONTROL(hw_cpu));
reg |= PMSU_CPU_POWER_DOWN_DIS_SNP_Q_SKIP;
writel(reg, pmsu_mp_base + PMSU_CPU_POWER_DOWN_CONTROL(hw_cpu));
}
return 0;
}
int armada_370_xp_pmsu_idle_enter(unsigned long deepidle)
{
unsigned long flags = PMSU_PREPARE_SNOOP_DISABLE;
int ret;
if (deepidle)
flags |= PMSU_PREPARE_DEEP_IDLE;
ret = mvebu_v7_pmsu_idle_prepare(flags);
if (ret)
return ret;
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
pr_debug("Failed to suspend the system\n");
return 0;
}
static int armada_370_xp_cpu_suspend(unsigned long deepidle)
{
return cpu_suspend(deepidle, armada_370_xp_pmsu_idle_enter);
}
static int armada_38x_do_cpu_suspend(unsigned long deepidle)
{
unsigned long flags = 0;
if (deepidle)
flags |= PMSU_PREPARE_DEEP_IDLE;
mvebu_v7_pmsu_idle_prepare(flags);
v7_exit_coherency_flush(louis);
scu_power_mode(mvebu_get_scu_base(), SCU_PM_POWEROFF);
cpu_do_idle();
return 1;
}
static int armada_38x_cpu_suspend(unsigned long deepidle)
{
return cpu_suspend(false, armada_38x_do_cpu_suspend);
}
void mvebu_v7_pmsu_idle_exit(void)
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
static int mvebu_v7_cpu_pm_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if (action == CPU_PM_ENTER) {
unsigned int hw_cpu = cpu_logical_map(smp_processor_id());
mvebu_pmsu_set_cpu_boot_addr(hw_cpu, mvebu_cpu_resume);
} else if (action == CPU_PM_EXIT) {
mvebu_v7_pmsu_idle_exit();
}
return NOTIFY_OK;
}
static __init int armada_370_cpuidle_init(void)
{
struct device_node *np;
phys_addr_t redirect_reg;
np = of_find_compatible_node(NULL, NULL, "marvell,coherency-fabric");
if (!np)
return -ENODEV;
of_node_put(np);
redirect_reg = pmsu_mp_phys_base + PMSU_BOOT_ADDR_REDIRECT_OFFSET(0);
mvebu_setup_boot_addr_wa(ARMADA_370_CRYPT0_ENG_TARGET,
ARMADA_370_CRYPT0_ENG_ATTR,
redirect_reg);
mvebu_cpu_resume = armada_370_xp_cpu_resume;
mvebu_v7_cpuidle_device.dev.platform_data = armada_370_xp_cpu_suspend;
mvebu_v7_cpuidle_device.name = "cpuidle-armada-370";
return 0;
}
static __init int armada_38x_cpuidle_init(void)
{
struct device_node *np;
void __iomem *mpsoc_base;
u32 reg;
np = of_find_compatible_node(NULL, NULL,
"marvell,armada-380-coherency-fabric");
if (!np)
return -ENODEV;
of_node_put(np);
np = of_find_compatible_node(NULL, NULL,
"marvell,armada-380-mpcore-soc-ctrl");
if (!np)
return -ENODEV;
mpsoc_base = of_iomap(np, 0);
BUG_ON(!mpsoc_base);
of_node_put(np);
reg = readl(mpsoc_base + MPCORE_RESET_CTL);
reg |= MPCORE_RESET_CTL_L2;
reg |= MPCORE_RESET_CTL_DEBUG;
writel(reg, mpsoc_base + MPCORE_RESET_CTL);
iounmap(mpsoc_base);
reg = readl(pmsu_mp_base + PMSU_POWERDOWN_DELAY);
reg &= ~PMSU_POWERDOWN_DELAY_MASK;
reg |= PMSU_DFLT_ARMADA38X_DELAY;
reg |= PMSU_POWERDOWN_DELAY_PMU;
writel(reg, pmsu_mp_base + PMSU_POWERDOWN_DELAY);
mvebu_cpu_resume = armada_38x_cpu_resume;
mvebu_v7_cpuidle_device.dev.platform_data = armada_38x_cpu_suspend;
mvebu_v7_cpuidle_device.name = "cpuidle-armada-38x";
return 0;
}
static __init int armada_xp_cpuidle_init(void)
{
struct device_node *np;
np = of_find_compatible_node(NULL, NULL, "marvell,coherency-fabric");
if (!np)
return -ENODEV;
of_node_put(np);
mvebu_cpu_resume = armada_370_xp_cpu_resume;
mvebu_v7_cpuidle_device.dev.platform_data = armada_370_xp_cpu_suspend;
mvebu_v7_cpuidle_device.name = "cpuidle-armada-xp";
return 0;
}
static int __init mvebu_v7_cpu_pm_init(void)
{
struct device_node *np;
int ret;
np = of_find_matching_node(NULL, of_pmsu_table);
if (!np)
return 0;
of_node_put(np);
if (of_machine_is_compatible("marvell,armadaxp"))
ret = armada_xp_cpuidle_init();
else if (of_machine_is_compatible("marvell,armada370"))
ret = armada_370_cpuidle_init();
else if (of_machine_is_compatible("marvell,armada380"))
ret = armada_38x_cpuidle_init();
else
return 0;
if (ret)
return ret;
mvebu_v7_pmsu_enable_l2_powerdown_onidle();
platform_device_register(&mvebu_v7_cpuidle_device);
cpu_pm_register_notifier(&mvebu_v7_cpu_pm_notifier);
return 0;
}
static void mvebu_pmsu_dfs_request_local(void *data)
{
u32 reg;
u32 cpu = smp_processor_id();
unsigned long flags;
local_irq_save(flags);
reg = readl(pmsu_mp_base + PMSU_STATUS_AND_MASK(cpu));
reg |= PMSU_STATUS_AND_MASK_CPU_IDLE_WAIT |
PMSU_STATUS_AND_MASK_IRQ_MASK |
PMSU_STATUS_AND_MASK_FIQ_MASK;
writel(reg, pmsu_mp_base + PMSU_STATUS_AND_MASK(cpu));
reg = readl(pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(cpu));
reg |= PMSU_CONTROL_AND_CONFIG_DFS_REQ;
writel(reg, pmsu_mp_base + PMSU_CONTROL_AND_CONFIG(cpu));
wfi();
reg = readl(pmsu_mp_base + PMSU_STATUS_AND_MASK(cpu));
reg &= ~PMSU_STATUS_AND_MASK_CPU_IDLE_WAIT;
writel(reg, pmsu_mp_base + PMSU_STATUS_AND_MASK(cpu));
local_irq_restore(flags);
}
int mvebu_pmsu_dfs_request(int cpu)
{
unsigned long timeout;
int hwcpu = cpu_logical_map(cpu);
u32 reg;
reg = readl(pmsu_mp_base + PMSU_EVENT_STATUS_AND_MASK(hwcpu));
reg &= ~PMSU_EVENT_STATUS_AND_MASK_DFS_DONE;
writel(reg, pmsu_mp_base + PMSU_EVENT_STATUS_AND_MASK(hwcpu));
reg = readl(pmsu_mp_base + PMSU_EVENT_STATUS_AND_MASK(hwcpu));
reg |= PMSU_EVENT_STATUS_AND_MASK_DFS_DONE_MASK;
writel(reg, pmsu_mp_base + PMSU_EVENT_STATUS_AND_MASK(hwcpu));
smp_call_function_single(cpu, mvebu_pmsu_dfs_request_local,
NULL, false);
timeout = jiffies + HZ;
while (time_before(jiffies, timeout)) {
reg = readl(pmsu_mp_base + PMSU_EVENT_STATUS_AND_MASK(hwcpu));
if (reg & PMSU_EVENT_STATUS_AND_MASK_DFS_DONE)
break;
udelay(10);
}
if (time_after(jiffies, timeout))
return -ETIME;
reg = readl(pmsu_mp_base + PMSU_EVENT_STATUS_AND_MASK(hwcpu));
reg &= ~PMSU_EVENT_STATUS_AND_MASK_DFS_DONE_MASK;
writel(reg, pmsu_mp_base + PMSU_EVENT_STATUS_AND_MASK(hwcpu));
return 0;
}
static int __init armada_xp_pmsu_cpufreq_init(void)
{
struct device_node *np;
struct resource res;
int ret, cpu;
if (!of_machine_is_compatible("marvell,armadaxp"))
return 0;
np = of_find_compatible_node(NULL, NULL, "marvell,armada-xp-cpu-clock");
if (!np)
return 0;
ret = of_address_to_resource(np, 1, &res);
if (ret) {
pr_warn(FW_WARN "not enabling cpufreq, deprecated armada-xp-cpu-clock binding\n");
of_node_put(np);
return 0;
}
of_node_put(np);
for_each_possible_cpu(cpu) {
struct device *cpu_dev;
struct clk *clk;
int ret;
cpu_dev = get_cpu_device(cpu);
if (!cpu_dev) {
pr_err("Cannot get CPU %d\n", cpu);
continue;
}
clk = clk_get(cpu_dev, 0);
if (IS_ERR(clk)) {
pr_err("Cannot get clock for CPU %d\n", cpu);
return PTR_ERR(clk);
}
ret = dev_pm_opp_add(cpu_dev, clk_get_rate(clk), 0);
if (ret) {
clk_put(clk);
return ret;
}
ret = dev_pm_opp_add(cpu_dev, clk_get_rate(clk) / 2, 0);
if (ret) {
clk_put(clk);
return ret;
}
}
platform_device_register_simple("cpufreq-generic", -1, NULL, 0);
return 0;
}
