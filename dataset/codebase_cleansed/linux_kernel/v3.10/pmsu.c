int armada_xp_boot_cpu(unsigned int cpu_id, void *boot_addr)
{
int reg, hw_cpu;
if (!pmsu_mp_base || !pmsu_reset_base) {
pr_warn("Can't boot CPU. PMSU is uninitialized\n");
return 1;
}
hw_cpu = cpu_logical_map(cpu_id);
writel(virt_to_phys(boot_addr), pmsu_mp_base +
PMSU_BOOT_ADDR_REDIRECT_OFFSET(hw_cpu));
reg = readl(pmsu_reset_base + PMSU_RESET_CTL_OFFSET(hw_cpu));
reg &= (~0x1);
writel(reg, pmsu_reset_base + PMSU_RESET_CTL_OFFSET(hw_cpu));
return 0;
}
int __init armada_370_xp_pmsu_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, of_pmsu_table);
if (np) {
pr_info("Initializing Power Management Service Unit\n");
pmsu_mp_base = of_iomap(np, 0);
pmsu_reset_base = of_iomap(np, 1);
}
return 0;
}
