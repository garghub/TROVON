void __init smp_init_cpus(void)
{
ct_desc->init_cpu_map();
}
void __init platform_smp_prepare_cpus(unsigned int max_cpus)
{
ct_desc->smp_enable(max_cpus);
writel(~0, MMIO_P2V(V2M_SYS_FLAGSCLR));
writel(BSYM(virt_to_phys(versatile_secondary_startup)),
MMIO_P2V(V2M_SYS_FLAGSSET));
}
