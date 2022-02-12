int omap_hdq1w_reset(struct omap_hwmod *oh)
{
u32 v;
int c = 0;
omap_hwmod_softreset(oh);
v = omap_hwmod_read(oh, HDQ_CTRL_STATUS_OFFSET);
v |= 1 << HDQ_CTRL_STATUS_CLOCKENABLE_SHIFT;
omap_hwmod_write(v, oh, HDQ_CTRL_STATUS_OFFSET);
omap_test_timeout((omap_hwmod_read(oh,
oh->class->sysc->syss_offs)
& SYSS_RESETDONE_MASK),
MAX_MODULE_SOFTRESET_WAIT, c);
if (c == MAX_MODULE_SOFTRESET_WAIT)
pr_warning("%s: %s: softreset failed (waited %d usec)\n",
__func__, oh->name, MAX_MODULE_SOFTRESET_WAIT);
else
pr_debug("%s: %s: softreset in %d usec\n", __func__,
oh->name, c);
return 0;
}
