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
int omap2_wd_timer_reset(struct omap_hwmod *oh)
{
int c = 0;
omap_hwmod_softreset(oh);
omap_test_timeout((omap_hwmod_read(oh,
oh->class->sysc->syss_offs)
& SYSS_RESETDONE_MASK),
MAX_MODULE_SOFTRESET_WAIT, c);
if (oh->class->sysc->srst_udelay)
udelay(oh->class->sysc->srst_udelay);
if (c == MAX_MODULE_SOFTRESET_WAIT)
pr_warning("%s: %s: softreset failed (waited %d usec)\n",
__func__, oh->name, MAX_MODULE_SOFTRESET_WAIT);
else
pr_debug("%s: %s: softreset in %d usec\n", __func__,
oh->name, c);
return (c == MAX_MODULE_SOFTRESET_WAIT) ? -ETIMEDOUT :
omap2_wd_timer_disable(oh);
}
