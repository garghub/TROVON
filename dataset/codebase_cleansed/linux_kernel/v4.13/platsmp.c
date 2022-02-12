static int s500_wakeup_secondary(unsigned int cpu)
{
int ret;
if (cpu > 3)
return -EINVAL;
switch (cpu) {
case 2:
ret = owl_sps_set_pg(sps_base_addr,
OWL_SPS_PG_CTL_PWR_CPU2,
OWL_SPS_PG_CTL_ACK_CPU2, true);
if (ret)
return ret;
break;
case 3:
ret = owl_sps_set_pg(sps_base_addr,
OWL_SPS_PG_CTL_PWR_CPU3,
OWL_SPS_PG_CTL_ACK_CPU3, true);
if (ret)
return ret;
break;
}
udelay(200);
writel(virt_to_phys(owl_secondary_startup),
timer_base_addr + OWL_CPU1_ADDR + (cpu - 1) * 4);
writel(OWL_CPUx_FLAG_BOOT,
timer_base_addr + OWL_CPU1_FLAG + (cpu - 1) * 4);
dsb_sev();
mb();
return 0;
}
static int s500_smp_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
unsigned long timeout;
int ret;
ret = s500_wakeup_secondary(cpu);
if (ret)
return ret;
udelay(10);
spin_lock(&boot_lock);
smp_send_reschedule(cpu);
timeout = jiffies + (1 * HZ);
while (time_before(jiffies, timeout)) {
if (pen_release == -1)
break;
}
writel(0, timer_base_addr + OWL_CPU1_ADDR + (cpu - 1) * 4);
writel(0, timer_base_addr + OWL_CPU1_FLAG + (cpu - 1) * 4);
spin_unlock(&boot_lock);
return 0;
}
static void __init s500_smp_prepare_cpus(unsigned int max_cpus)
{
struct device_node *node;
node = of_find_compatible_node(NULL, NULL, "actions,s500-timer");
if (!node) {
pr_err("%s: missing timer\n", __func__);
return;
}
timer_base_addr = of_iomap(node, 0);
if (!timer_base_addr) {
pr_err("%s: could not map timer registers\n", __func__);
return;
}
node = of_find_compatible_node(NULL, NULL, "actions,s500-sps");
if (!node) {
pr_err("%s: missing sps\n", __func__);
return;
}
sps_base_addr = of_iomap(node, 0);
if (!sps_base_addr) {
pr_err("%s: could not map sps registers\n", __func__);
return;
}
if (read_cpuid_part() == ARM_CPU_PART_CORTEX_A9) {
node = of_find_compatible_node(NULL, NULL, "arm,cortex-a9-scu");
if (!node) {
pr_err("%s: missing scu\n", __func__);
return;
}
scu_base_addr = of_iomap(node, 0);
if (!scu_base_addr) {
pr_err("%s: could not map scu registers\n", __func__);
return;
}
ncores = scu_get_core_count(scu_base_addr);
pr_debug("%s: ncores %d\n", __func__, ncores);
scu_enable(scu_base_addr);
}
}
