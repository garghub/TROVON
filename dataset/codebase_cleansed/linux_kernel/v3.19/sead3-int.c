void __init arch_init_irq(void)
{
if (!cpu_has_veic)
mips_cpu_irq_init();
sead3_config_reg = ioremap_nocache(SEAD_CONFIG_BASE, SEAD_CONFIG_SIZE);
gic_present = (__raw_readl(sead3_config_reg) &
SEAD_CONFIG_GIC_PRESENT_MSK) >>
SEAD_CONFIG_GIC_PRESENT_SHF;
pr_info("GIC: %spresent\n", (gic_present) ? "" : "not ");
pr_info("EIC: %s\n",
(current_cpu_data.options & MIPS_CPU_VEIC) ? "on" : "off");
if (gic_present)
gic_init(GIC_BASE_ADDR, GIC_ADDRSPACE_SZ, CPU_INT_GIC,
MIPS_GIC_IRQ_BASE);
}
