static struct drm_display_mode *tmd_vid_get_config_mode(struct drm_device *dev)
{
struct drm_display_mode *mode;
struct drm_psb_private *dev_priv = dev->dev_private;
struct oaktrail_timing_info *ti = &dev_priv->gct_data.DTD;
bool use_gct = false;
mode = kzalloc(sizeof(*mode), GFP_KERNEL);
if (!mode)
return NULL;
if (use_gct) {
mode->hdisplay = (ti->hactive_hi << 8) | ti->hactive_lo;
mode->vdisplay = (ti->vactive_hi << 8) | ti->vactive_lo;
mode->hsync_start = mode->hdisplay + \
((ti->hsync_offset_hi << 8) | \
ti->hsync_offset_lo);
mode->hsync_end = mode->hsync_start + \
((ti->hsync_pulse_width_hi << 8) | \
ti->hsync_pulse_width_lo);
mode->htotal = mode->hdisplay + ((ti->hblank_hi << 8) | \
ti->hblank_lo);
mode->vsync_start = \
mode->vdisplay + ((ti->vsync_offset_hi << 8) | \
ti->vsync_offset_lo);
mode->vsync_end = \
mode->vsync_start + ((ti->vsync_pulse_width_hi << 8) | \
ti->vsync_pulse_width_lo);
mode->vtotal = mode->vdisplay + \
((ti->vblank_hi << 8) | ti->vblank_lo);
mode->clock = ti->pixel_clock * 10;
dev_dbg(dev->dev, "hdisplay is %d\n", mode->hdisplay);
dev_dbg(dev->dev, "vdisplay is %d\n", mode->vdisplay);
dev_dbg(dev->dev, "HSS is %d\n", mode->hsync_start);
dev_dbg(dev->dev, "HSE is %d\n", mode->hsync_end);
dev_dbg(dev->dev, "htotal is %d\n", mode->htotal);
dev_dbg(dev->dev, "VSS is %d\n", mode->vsync_start);
dev_dbg(dev->dev, "VSE is %d\n", mode->vsync_end);
dev_dbg(dev->dev, "vtotal is %d\n", mode->vtotal);
dev_dbg(dev->dev, "clock is %d\n", mode->clock);
} else {
mode->hdisplay = 480;
mode->vdisplay = 854;
mode->hsync_start = 487;
mode->hsync_end = 490;
mode->htotal = 499;
mode->vsync_start = 861;
mode->vsync_end = 865;
mode->vtotal = 873;
mode->clock = 33264;
}
drm_mode_set_name(mode);
drm_mode_set_crtcinfo(mode, 0);
mode->type |= DRM_MODE_TYPE_PREFERRED;
return mode;
}
static int tmd_vid_get_panel_info(struct drm_device *dev,
int pipe,
struct panel_info *pi)
{
if (!dev || !pi)
return -EINVAL;
pi->width_mm = TMD_PANEL_WIDTH;
pi->height_mm = TMD_PANEL_HEIGHT;
return 0;
}
static void mdfld_dsi_tmd_drv_ic_init(struct mdfld_dsi_config *dsi_config,
int pipe)
{
struct mdfld_dsi_pkg_sender *sender
= mdfld_dsi_get_pkg_sender(dsi_config);
DRM_INFO("Enter mdfld init TMD MIPI display.\n");
if (!sender) {
DRM_ERROR("Cannot get sender\n");
return;
}
if (dsi_config->dvr_ic_inited)
return;
msleep(3);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_mcap_off,
sizeof(tmd_cmd_mcap_off), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_enable_lane_switch,
sizeof(tmd_cmd_enable_lane_switch), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_set_lane_num,
sizeof(tmd_cmd_set_lane_num), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_pushing_clock0,
sizeof(tmd_cmd_pushing_clock0), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_pushing_clock1,
sizeof(tmd_cmd_pushing_clock1), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_set_mode,
sizeof(tmd_cmd_set_mode), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_set_sync_pulse_mode,
sizeof(tmd_cmd_set_sync_pulse_mode), false);
mdfld_dsi_send_mcs_long(sender, (u8 *) tmd_cmd_set_column,
sizeof(tmd_cmd_set_column), false);
mdfld_dsi_send_mcs_long(sender, (u8 *) tmd_cmd_set_page,
sizeof(tmd_cmd_set_page), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_set_video_mode,
sizeof(tmd_cmd_set_video_mode), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_enable_backlight,
sizeof(tmd_cmd_enable_backlight), false);
mdfld_dsi_send_gen_long(sender, (u8 *) tmd_cmd_set_backlight_dimming,
sizeof(tmd_cmd_set_backlight_dimming), false);
dsi_config->dvr_ic_inited = 1;
}
