int alpine_cpu_wakeup(unsigned int phys_cpu, uint32_t phys_resume_addr)
{
if (!wakeup_supported)
return -ENOSYS;
writel(phys_resume_addr,
&al_cpu_resume_regs->per_cpu[phys_cpu].resume_addr);
regmap_write(al_sysfabric, AL_SYSFAB_POWER_CONTROL(phys_cpu), 0);
return 0;
}
void __init alpine_cpu_pm_init(void)
{
struct device_node *np;
uint32_t watermark;
al_sysfabric = syscon_regmap_lookup_by_compatible("al,alpine-sysfabric-service");
np = of_find_compatible_node(NULL, NULL, "al,alpine-cpu-resume");
al_cpu_resume_regs = of_iomap(np, 0);
wakeup_supported = !IS_ERR(al_sysfabric) && al_cpu_resume_regs;
if (wakeup_supported) {
watermark = readl(&al_cpu_resume_regs->watermark);
wakeup_supported = (watermark & AL_CPU_RESUME_MAGIC_NUM_MASK)
== AL_CPU_RESUME_MAGIC_NUM;
}
}
