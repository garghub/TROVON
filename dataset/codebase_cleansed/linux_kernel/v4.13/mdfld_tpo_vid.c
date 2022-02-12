static struct drm_display_mode *tpo_vid_get_config_mode(struct drm_device *dev)
{
struct drm_display_mode *mode;
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
mode->hdisplay = 864;
mode->vdisplay = 480;
mode->hsync_start = 873;
mode->hsync_end = 876;
mode->htotal = 887;
mode->vsync_start = 487;
mode->vsync_end = 490;
mode->vtotal = 499;
mode->clock = 33264;
drm_mode_set_name(mode);
drm_mode_set_crtcinfo(mode, 0);
mode->type |= DRM_MODE_TYPE_PREFERRED;
return mode;
}
static int tpo_vid_get_panel_info(struct drm_device *dev,
int pipe,
struct panel_info *pi)
{
if (!dev || !pi)
return -EINVAL;
pi->width_mm = TPO_PANEL_WIDTH;
pi->height_mm = TPO_PANEL_HEIGHT;
return 0;
}
