void __init shx3_cache_init(void)
{
unsigned int ccr;
ccr = __raw_readl(SH_CCR);
if (boot_cpu_data.dcache.n_aliases || boot_cpu_data.icache.n_aliases) {
ccr |= CCR_CACHE_SNM;
boot_cpu_data.icache.n_aliases = 0;
boot_cpu_data.dcache.n_aliases = 0;
pr_info("Enabling hardware synonym avoidance\n");
}
#ifdef CONFIG_SMP
ccr |= CCR_CACHE_IBE;
#endif
writel_uncached(ccr, SH_CCR);
}
