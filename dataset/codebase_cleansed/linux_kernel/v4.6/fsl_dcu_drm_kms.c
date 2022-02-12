int fsl_dcu_drm_modeset_init(struct fsl_dcu_drm_device *fsl_dev)
{
int ret;
drm_mode_config_init(fsl_dev->drm);
fsl_dev->drm->mode_config.min_width = 0;
fsl_dev->drm->mode_config.min_height = 0;
fsl_dev->drm->mode_config.max_width = 2031;
fsl_dev->drm->mode_config.max_height = 2047;
fsl_dev->drm->mode_config.funcs = &fsl_dcu_drm_mode_config_funcs;
ret = fsl_dcu_drm_crtc_create(fsl_dev);
if (ret)
return ret;
ret = fsl_dcu_drm_encoder_create(fsl_dev, &fsl_dev->crtc);
if (ret)
goto fail_encoder;
ret = fsl_dcu_drm_connector_create(fsl_dev, &fsl_dev->encoder);
if (ret)
goto fail_connector;
drm_mode_config_reset(fsl_dev->drm);
drm_kms_helper_poll_init(fsl_dev->drm);
return 0;
fail_encoder:
fsl_dev->crtc.funcs->destroy(&fsl_dev->crtc);
fail_connector:
fsl_dev->encoder.funcs->destroy(&fsl_dev->encoder);
return ret;
}
