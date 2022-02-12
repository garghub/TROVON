int omap_hwmod_aess_preprogram(struct omap_hwmod *oh)
{
void __iomem *va;
va = omap_hwmod_get_mpu_rt_va(oh);
if (!va)
return -EINVAL;
aess_enable_autogating(va);
return 0;
}
