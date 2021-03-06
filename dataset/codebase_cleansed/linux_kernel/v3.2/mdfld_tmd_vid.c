struct drm_display_mode *tmd_vid_get_config_mode(struct drm_device *dev)\r\n{\r\nstruct drm_display_mode *mode;\r\nstruct drm_psb_private *dev_priv = dev->dev_private;\r\nstruct mrst_timing_info *ti = &dev_priv->gct_data.DTD;\r\nbool use_gct = false;\r\nmode = kzalloc(sizeof(*mode), GFP_KERNEL);\r\nif (!mode) {\r\ndev_err(dev->dev, "Out of memory\n");\r\nreturn NULL;\r\n}\r\nif (use_gct) {\r\ndev_dbg(dev->dev, "gct find MIPI panel.\n");\r\nmode->hdisplay = (ti->hactive_hi << 8) | ti->hactive_lo;\r\nmode->vdisplay = (ti->vactive_hi << 8) | ti->vactive_lo;\r\nmode->hsync_start = mode->hdisplay +\r\n((ti->hsync_offset_hi << 8) |\r\nti->hsync_offset_lo);\r\nmode->hsync_end = mode->hsync_start +\r\n((ti->hsync_pulse_width_hi << 8) |\r\nti->hsync_pulse_width_lo);\r\nmode->htotal = mode->hdisplay + ((ti->hblank_hi << 8) |\r\nti->hblank_lo);\r\nmode->vsync_start = \\r\nmode->vdisplay + ((ti->vsync_offset_hi << 8) |\r\nti->vsync_offset_lo);\r\nmode->vsync_end = \\r\nmode->vsync_start + ((ti->vsync_pulse_width_hi << 8) | \\r\nti->vsync_pulse_width_lo);\r\nmode->vtotal = mode->vdisplay +\r\n((ti->vblank_hi << 8) | ti->vblank_lo);\r\nmode->clock = ti->pixel_clock * 10;\r\ndev_dbg(dev->dev, "hdisplay is %d\n", mode->hdisplay);\r\ndev_dbg(dev->dev, "vdisplay is %d\n", mode->vdisplay);\r\ndev_dbg(dev->dev, "HSS is %d\n", mode->hsync_start);\r\ndev_dbg(dev->dev, "HSE is %d\n", mode->hsync_end);\r\ndev_dbg(dev->dev, "htotal is %d\n", mode->htotal);\r\ndev_dbg(dev->dev, "VSS is %d\n", mode->vsync_start);\r\ndev_dbg(dev->dev, "VSE is %d\n", mode->vsync_end);\r\ndev_dbg(dev->dev, "vtotal is %d\n", mode->vtotal);\r\ndev_dbg(dev->dev, "clock is %d\n", mode->clock);\r\n} else {\r\nmode->hdisplay = 480;\r\nmode->vdisplay = 854;\r\nmode->hsync_start = 487;\r\nmode->hsync_end = 490;\r\nmode->htotal = 499;\r\nmode->vsync_start = 861;\r\nmode->vsync_end = 865;\r\nmode->vtotal = 873;\r\nmode->clock = 33264;\r\n}\r\ndrm_mode_set_name(mode);\r\ndrm_mode_set_crtcinfo(mode, 0);\r\nmode->type |= DRM_MODE_TYPE_PREFERRED;\r\nreturn mode;\r\n}\r\nstatic int tmd_vid_get_panel_info(struct drm_device *dev,\r\nint pipe,\r\nstruct panel_info *pi)\r\n{\r\nif (!dev || !pi)\r\nreturn -EINVAL;\r\npi->width_mm = TMD_PANEL_WIDTH;\r\npi->height_mm = TMD_PANEL_HEIGHT;\r\nreturn 0;\r\n}\r\nstatic void mdfld_dsi_tmd_drv_ic_init(struct mdfld_dsi_config *dsi_config,\r\nint pipe)\r\n{\r\nstatic u32 tmd_cmd_mcap_off[] = {0x000000b2};\r\nstatic u32 tmd_cmd_enable_lane_switch[] = {0x000101ef};\r\nstatic u32 tmd_cmd_set_lane_num[] = {0x006360ef};\r\nstatic u32 tmd_cmd_pushing_clock0[] = {0x00cc2fef};\r\nstatic u32 tmd_cmd_pushing_clock1[] = {0x00dd6eef};\r\nstatic u32 tmd_cmd_set_mode[] = {0x000000b3};\r\nstatic u32 tmd_cmd_set_sync_pulse_mode[] = {0x000961ef};\r\nstatic u32 tmd_cmd_set_column[] = {0x0100002a, 0x000000df};\r\nstatic u32 tmd_cmd_set_page[] = {0x0300002b, 0x00000055};\r\nstatic u32 tmd_cmd_set_video_mode[] = {0x00000153};\r\nstatic u32 tmd_cmd_enable_backlight[] = {0x00005ab4};\r\nstatic u32 tmd_cmd_set_backlight_dimming[] = {0x00000ebd};\r\nstruct mdfld_dsi_pkg_sender *sender\r\n= mdfld_dsi_get_pkg_sender(dsi_config);\r\nDRM_INFO("Enter mdfld init TMD MIPI display.\n");\r\nif (!sender) {\r\nDRM_ERROR("Cannot get sender\n");\r\nreturn;\r\n}\r\nif (dsi_config->dvr_ic_inited)\r\nreturn;\r\nmsleep(3);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_mcap_off, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_enable_lane_switch, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_set_lane_num, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_pushing_clock0, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_pushing_clock1, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_set_mode, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_set_sync_pulse_mode, 1, 0);\r\nmdfld_dsi_send_mcs_long_lp(sender, tmd_cmd_set_column, 2, 0);\r\nmdfld_dsi_send_mcs_long_lp(sender, tmd_cmd_set_page, 2, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_set_video_mode, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_enable_backlight, 1, 0);\r\nmdfld_dsi_send_gen_long_lp(sender, tmd_cmd_set_backlight_dimming, 1, 0);\r\ndsi_config->dvr_ic_inited = 1;\r\n}\r\nvoid tmd_vid_init(struct drm_device *dev, struct panel_funcs *p_funcs)\r\n{\r\nif (!dev || !p_funcs) {\r\ndev_err(dev->dev, "Invalid parameters\n");\r\nreturn;\r\n}\r\np_funcs->encoder_funcs = &mdfld_tpo_dpi_encoder_funcs;\r\np_funcs->encoder_helper_funcs = &mdfld_tpo_dpi_encoder_helper_funcs;\r\np_funcs->get_config_mode = &tmd_vid_get_config_mode;\r\np_funcs->update_fb = NULL;\r\np_funcs->get_panel_info = tmd_vid_get_panel_info;\r\np_funcs->reset = mdfld_dsi_panel_reset;\r\np_funcs->drv_ic_init = mdfld_dsi_tmd_drv_ic_init;\r\n}
