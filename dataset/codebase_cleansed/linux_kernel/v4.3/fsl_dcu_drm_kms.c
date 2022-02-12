int fsl_dcu_drm_modeset_init(struct fsl_dcu_drm_device *fsl_dev)
{
drm_mode_config_init(fsl_dev->drm);
fsl_dev->drm->mode_config.min_width = 0;
fsl_dev->drm->mode_config.min_height = 0;
fsl_dev->drm->mode_config.max_width = 2031;
fsl_dev->drm->mode_config.max_height = 2047;
fsl_dev->drm->mode_config.funcs = &fsl_dcu_drm_mode_config_funcs;
drm_kms_helper_poll_init(fsl_dev->drm);
fsl_dcu_drm_crtc_create(fsl_dev);
fsl_dcu_drm_encoder_create(fsl_dev, &fsl_dev->crtc);
fsl_dcu_drm_connector_create(fsl_dev, &fsl_dev->encoder);
drm_mode_config_reset(fsl_dev->drm);
return 0;
}
