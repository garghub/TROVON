void armada_375_smp_cpu1_enable_wa(void)
{
void __iomem *sram_virt_base;
mvebu_mbus_del_window(BOOTROM_BASE, BOOTROM_SIZE);
mvebu_mbus_add_window_by_id(CRYPT0_ENG_ID, CRYPT0_ENG_ATTR,
SRAM_PHYS_BASE, SZ_64K);
sram_virt_base = ioremap(SRAM_PHYS_BASE, SZ_64K);
memcpy(sram_virt_base, &armada_375_smp_cpu1_enable_code_start,
&armada_375_smp_cpu1_enable_code_end
- &armada_375_smp_cpu1_enable_code_start);
}
static int __cpuinit mvebu_cortex_a9_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
int ret, hw_cpu;
pr_info("Booting CPU %d\n", cpu);
hw_cpu = cpu_logical_map(cpu);
if (of_machine_is_compatible("marvell,armada375")) {
u32 dev, rev;
if (mvebu_get_soc_id(&dev, &rev) == 0 &&
rev == ARMADA_375_Z1_REV)
armada_375_smp_cpu1_enable_wa();
mvebu_system_controller_set_cpu_boot_addr(mvebu_cortex_a9_secondary_startup);
}
else {
mvebu_pmsu_set_cpu_boot_addr(hw_cpu,
mvebu_cortex_a9_secondary_startup);
}
smp_wmb();
ret = mvebu_cpu_reset_deassert(hw_cpu);
if (ret) {
pr_err("Could not start the secondary CPU: %d\n", ret);
return ret;
}
arch_send_wakeup_ipi_mask(cpumask_of(cpu));
return 0;
}
