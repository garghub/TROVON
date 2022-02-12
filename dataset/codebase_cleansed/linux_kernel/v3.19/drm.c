int __init omap_init_drm(void)\r\n{\r\nplatform_data.omaprev = GET_OMAP_TYPE;\r\nreturn platform_device_register(&omap_drm_device);\r\n}\r\nint __init omap_init_drm(void) { return 0; }
