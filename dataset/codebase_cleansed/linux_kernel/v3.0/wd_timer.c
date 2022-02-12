int omap2_wd_timer_disable(struct omap_hwmod *oh)
{
void __iomem *base;
if (!oh) {
pr_err("%s: Could not look up wdtimer_hwmod\n", __func__);
return -EINVAL;
}
base = omap_hwmod_get_mpu_rt_va(oh);
if (!base) {
pr_err("%s: Could not get the base address for %s\n",
oh->name, __func__);
return -EINVAL;
}
__raw_writel(0xAAAA, base + OMAP_WDT_SPR);
while (__raw_readl(base + OMAP_WDT_WPS) & 0x10)
cpu_relax();
__raw_writel(0x5555, base + OMAP_WDT_SPR);
while (__raw_readl(base + OMAP_WDT_WPS) & 0x10)
cpu_relax();
return 0;
}
