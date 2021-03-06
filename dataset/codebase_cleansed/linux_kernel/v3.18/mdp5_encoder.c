static struct mdp5_kms *get_kms(struct drm_encoder *encoder)\r\n{\r\nstruct msm_drm_private *priv = encoder->dev->dev_private;\r\nreturn to_mdp5_kms(to_mdp_kms(priv->kms));\r\n}\r\nstatic void bs_init(struct mdp5_encoder *mdp5_encoder)\r\n{\r\nmdp5_encoder->bsc = msm_bus_scale_register_client(\r\n&mdp_bus_scale_table);\r\nDBG("bus scale client: %08x", mdp5_encoder->bsc);\r\n}\r\nstatic void bs_fini(struct mdp5_encoder *mdp5_encoder)\r\n{\r\nif (mdp5_encoder->bsc) {\r\nmsm_bus_scale_unregister_client(mdp5_encoder->bsc);\r\nmdp5_encoder->bsc = 0;\r\n}\r\n}\r\nstatic void bs_set(struct mdp5_encoder *mdp5_encoder, int idx)\r\n{\r\nif (mdp5_encoder->bsc) {\r\nDBG("set bus scaling: %d", idx);\r\nidx = 1;\r\nmsm_bus_scale_client_update_request(mdp5_encoder->bsc, idx);\r\n}\r\n}\r\nstatic void bs_init(struct mdp5_encoder *mdp5_encoder) {}\r\nstatic void bs_fini(struct mdp5_encoder *mdp5_encoder) {}\r\nstatic void bs_set(struct mdp5_encoder *mdp5_encoder, int idx) {}\r\nstatic void mdp5_encoder_destroy(struct drm_encoder *encoder)\r\n{\r\nstruct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);\r\nbs_fini(mdp5_encoder);\r\ndrm_encoder_cleanup(encoder);\r\nkfree(mdp5_encoder);\r\n}\r\nstatic void mdp5_encoder_dpms(struct drm_encoder *encoder, int mode)\r\n{\r\nstruct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);\r\nstruct mdp5_kms *mdp5_kms = get_kms(encoder);\r\nint intf = mdp5_encoder->intf;\r\nbool enabled = (mode == DRM_MODE_DPMS_ON);\r\nDBG("mode=%d", mode);\r\nif (enabled == mdp5_encoder->enabled)\r\nreturn;\r\nif (enabled) {\r\nbs_set(mdp5_encoder, 1);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(intf), 1);\r\n} else {\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_TIMING_ENGINE_EN(intf), 0);\r\nbs_set(mdp5_encoder, 0);\r\n}\r\nmdp5_encoder->enabled = enabled;\r\n}\r\nstatic bool mdp5_encoder_mode_fixup(struct drm_encoder *encoder,\r\nconst struct drm_display_mode *mode,\r\nstruct drm_display_mode *adjusted_mode)\r\n{\r\nreturn true;\r\n}\r\nstatic void mdp5_encoder_mode_set(struct drm_encoder *encoder,\r\nstruct drm_display_mode *mode,\r\nstruct drm_display_mode *adjusted_mode)\r\n{\r\nstruct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);\r\nstruct mdp5_kms *mdp5_kms = get_kms(encoder);\r\nint intf = mdp5_encoder->intf;\r\nuint32_t dtv_hsync_skew, vsync_period, vsync_len, ctrl_pol;\r\nuint32_t display_v_start, display_v_end;\r\nuint32_t hsync_start_x, hsync_end_x;\r\nuint32_t format;\r\nmode = adjusted_mode;\r\nDBG("set mode: %d:\"%s\" %d %d %d %d %d %d %d %d %d %d 0x%x 0x%x",\r\nmode->base.id, mode->name,\r\nmode->vrefresh, mode->clock,\r\nmode->hdisplay, mode->hsync_start,\r\nmode->hsync_end, mode->htotal,\r\nmode->vdisplay, mode->vsync_start,\r\nmode->vsync_end, mode->vtotal,\r\nmode->type, mode->flags);\r\nctrl_pol = 0;\r\nif (mode->flags & DRM_MODE_FLAG_NHSYNC)\r\nctrl_pol |= MDP5_INTF_POLARITY_CTL_HSYNC_LOW;\r\nif (mode->flags & DRM_MODE_FLAG_NVSYNC)\r\nctrl_pol |= MDP5_INTF_POLARITY_CTL_VSYNC_LOW;\r\ndtv_hsync_skew = 0;\r\nformat = 0x213f;\r\nhsync_start_x = (mode->htotal - mode->hsync_start);\r\nhsync_end_x = mode->htotal - (mode->hsync_start - mode->hdisplay) - 1;\r\nvsync_period = mode->vtotal * mode->htotal;\r\nvsync_len = (mode->vsync_end - mode->vsync_start) * mode->htotal;\r\ndisplay_v_start = (mode->vtotal - mode->vsync_start) * mode->htotal + dtv_hsync_skew;\r\ndisplay_v_end = vsync_period - ((mode->vsync_start - mode->vdisplay) * mode->htotal) + dtv_hsync_skew - 1;\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_HSYNC_CTL(intf),\r\nMDP5_INTF_HSYNC_CTL_PULSEW(mode->hsync_end - mode->hsync_start) |\r\nMDP5_INTF_HSYNC_CTL_PERIOD(mode->htotal));\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_VSYNC_PERIOD_F0(intf), vsync_period);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_VSYNC_LEN_F0(intf), vsync_len);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_DISPLAY_HCTL(intf),\r\nMDP5_INTF_DISPLAY_HCTL_START(hsync_start_x) |\r\nMDP5_INTF_DISPLAY_HCTL_END(hsync_end_x));\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_DISPLAY_VSTART_F0(intf), display_v_start);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_DISPLAY_VEND_F0(intf), display_v_end);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_BORDER_COLOR(intf), 0);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_UNDERFLOW_COLOR(intf), 0xff);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_HSYNC_SKEW(intf), dtv_hsync_skew);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_POLARITY_CTL(intf), ctrl_pol);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_ACTIVE_HCTL(intf),\r\nMDP5_INTF_ACTIVE_HCTL_START(0) |\r\nMDP5_INTF_ACTIVE_HCTL_END(0));\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_ACTIVE_VSTART_F0(intf), 0);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_ACTIVE_VEND_F0(intf), 0);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_PANEL_FORMAT(intf), format);\r\nmdp5_write(mdp5_kms, REG_MDP5_INTF_FRAME_LINE_COUNT_EN(intf), 0x3);\r\n}\r\nstatic void mdp5_encoder_prepare(struct drm_encoder *encoder)\r\n{\r\nmdp5_encoder_dpms(encoder, DRM_MODE_DPMS_OFF);\r\n}\r\nstatic void mdp5_encoder_commit(struct drm_encoder *encoder)\r\n{\r\nstruct mdp5_encoder *mdp5_encoder = to_mdp5_encoder(encoder);\r\nmdp5_crtc_set_intf(encoder->crtc, mdp5_encoder->intf,\r\nmdp5_encoder->intf_id);\r\nmdp5_encoder_dpms(encoder, DRM_MODE_DPMS_ON);\r\n}\r\nstruct drm_encoder *mdp5_encoder_init(struct drm_device *dev, int intf,\r\nenum mdp5_intf intf_id)\r\n{\r\nstruct drm_encoder *encoder = NULL;\r\nstruct mdp5_encoder *mdp5_encoder;\r\nint ret;\r\nmdp5_encoder = kzalloc(sizeof(*mdp5_encoder), GFP_KERNEL);\r\nif (!mdp5_encoder) {\r\nret = -ENOMEM;\r\ngoto fail;\r\n}\r\nmdp5_encoder->intf = intf;\r\nmdp5_encoder->intf_id = intf_id;\r\nencoder = &mdp5_encoder->base;\r\ndrm_encoder_init(dev, encoder, &mdp5_encoder_funcs,\r\nDRM_MODE_ENCODER_TMDS);\r\ndrm_encoder_helper_add(encoder, &mdp5_encoder_helper_funcs);\r\nbs_init(mdp5_encoder);\r\nreturn encoder;\r\nfail:\r\nif (encoder)\r\nmdp5_encoder_destroy(encoder);\r\nreturn ERR_PTR(ret);\r\n}
