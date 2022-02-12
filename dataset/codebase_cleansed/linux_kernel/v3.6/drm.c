static int __init omap_init_drm(void)
{
struct omap_hwmod *oh = NULL;
struct platform_device *pdev;
oh = omap_hwmod_lookup("dmm");
if (oh) {
pdev = omap_device_build(oh->name, -1, oh, NULL, 0, NULL, 0,
false);
WARN(IS_ERR(pdev), "Could not build omap_device for %s\n",
oh->name);
}
return platform_device_register(&omap_drm_device);
}
