int __init omap_init_drm(void)
{
platform_data.omaprev = GET_OMAP_TYPE;
return platform_device_register(&omap_drm_device);
}
int __init omap_init_drm(void) { return 0; }
