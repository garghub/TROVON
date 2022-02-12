void imx_drm_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 64;
dev->mode_config.min_height = 64;
dev->mode_config.max_width = 4096;
dev->mode_config.max_height = 4096;
dev->mode_config.funcs = &imx_drm_mode_config_funcs;
}
