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
writel_relaxed(0xAAAA, base + OMAP_WDT_SPR);
while (readl_relaxed(base + OMAP_WDT_WPS) & 0x10)
cpu_relax();
writel_relaxed(0x5555, base + OMAP_WDT_SPR);
while (readl_relaxed(base + OMAP_WDT_WPS) & 0x10)
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
pr_warn("%s: %s: softreset failed (waited %d usec)\n",
__func__, oh->name, MAX_MODULE_SOFTRESET_WAIT);
else
pr_debug("%s: %s: softreset in %d usec\n", __func__,
oh->name, c);
return (c == MAX_MODULE_SOFTRESET_WAIT) ? -ETIMEDOUT :
omap2_wd_timer_disable(oh);
}
static int __init omap_init_wdt(void)
{
int id = -1;
struct platform_device *pdev;
struct omap_hwmod *oh;
char *oh_name = "wd_timer2";
char *dev_name = "omap_wdt";
struct omap_wd_timer_platform_data pdata;
if (!cpu_class_is_omap2() || of_have_populated_dt())
return 0;
oh = omap_hwmod_lookup(oh_name);
if (!oh) {
pr_err("Could not look up wd_timer%d hwmod\n", id);
return -EINVAL;
}
pdata.read_reset_sources = prm_read_reset_sources;
pdev = omap_device_build(dev_name, id, oh, &pdata,
sizeof(struct omap_wd_timer_platform_data));
WARN(IS_ERR(pdev), "Can't build omap_device for %s:%s.\n",
dev_name, oh->name);
return 0;
}
