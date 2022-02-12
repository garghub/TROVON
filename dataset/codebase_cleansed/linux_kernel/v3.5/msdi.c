int omap_msdi_reset(struct omap_hwmod *oh)
{
u16 v = 0;
int c = 0;
omap_hwmod_softreset(oh);
v |= MSDI_CON_POW_MASK;
v |= MSDI_TARGET_RESET_CLKD << MSDI_CON_CLKD_SHIFT;
omap_hwmod_write(v, oh, MSDI_CON_OFFSET);
omap_test_timeout((omap_hwmod_read(oh, oh->class->sysc->syss_offs)
& SYSS_RESETDONE_MASK),
MAX_MODULE_SOFTRESET_WAIT, c);
if (c == MAX_MODULE_SOFTRESET_WAIT)
pr_warning("%s: %s: softreset failed (waited %d usec)\n",
__func__, oh->name, MAX_MODULE_SOFTRESET_WAIT);
else
pr_debug("%s: %s: softreset in %d usec\n", __func__,
oh->name, c);
v &= ~MSDI_CON_CLKD_MASK;
omap_hwmod_write(v, oh, MSDI_CON_OFFSET);
return 0;
}
