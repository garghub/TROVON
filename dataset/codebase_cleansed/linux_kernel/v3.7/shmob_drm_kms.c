const struct shmob_drm_format_info *shmob_drm_format_info(u32 fourcc)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(shmob_drm_format_infos); ++i) {
if (shmob_drm_format_infos[i].fourcc == fourcc)
return &shmob_drm_format_infos[i];
}
return NULL;
}
static struct drm_framebuffer *
shmob_drm_fb_create(struct drm_device *dev, struct drm_file *file_priv,
struct drm_mode_fb_cmd2 *mode_cmd)
{
const struct shmob_drm_format_info *format;
format = shmob_drm_format_info(mode_cmd->pixel_format);
if (format == NULL) {
dev_dbg(dev->dev, "unsupported pixel format %08x\n",
mode_cmd->pixel_format);
return ERR_PTR(-EINVAL);
}
if (mode_cmd->pitches[0] & 7 || mode_cmd->pitches[0] >= 65536) {
dev_dbg(dev->dev, "valid pitch value %u\n",
mode_cmd->pitches[0]);
return ERR_PTR(-EINVAL);
}
if (format->yuv) {
unsigned int chroma_cpp = format->bpp == 24 ? 2 : 1;
if (mode_cmd->pitches[1] != mode_cmd->pitches[0] * chroma_cpp) {
dev_dbg(dev->dev,
"luma and chroma pitches do not match\n");
return ERR_PTR(-EINVAL);
}
}
return drm_fb_cma_create(dev, file_priv, mode_cmd);
}
int shmob_drm_modeset_init(struct shmob_drm_device *sdev)
{
drm_mode_config_init(sdev->ddev);
shmob_drm_crtc_create(sdev);
shmob_drm_encoder_create(sdev);
shmob_drm_connector_create(sdev, &sdev->encoder.encoder);
drm_kms_helper_poll_init(sdev->ddev);
sdev->ddev->mode_config.min_width = 0;
sdev->ddev->mode_config.min_height = 0;
sdev->ddev->mode_config.max_width = 4095;
sdev->ddev->mode_config.max_height = 4095;
sdev->ddev->mode_config.funcs = &shmob_drm_mode_config_funcs;
drm_helper_disable_unused_functions(sdev->ddev);
return 0;
}
