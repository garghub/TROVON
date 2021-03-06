static inline struct sun4i_rgb *
drm_connector_to_sun4i_rgb(struct drm_connector *connector)
{
return container_of(connector, struct sun4i_rgb,
connector);
}
static inline struct sun4i_rgb *
drm_encoder_to_sun4i_rgb(struct drm_encoder *encoder)
{
return container_of(encoder, struct sun4i_rgb,
encoder);
}
static int sun4i_rgb_get_modes(struct drm_connector *connector)
{
struct sun4i_rgb *rgb =
drm_connector_to_sun4i_rgb(connector);
struct sun4i_tcon *tcon = rgb->tcon;
return drm_panel_get_modes(tcon->panel);
}
static int sun4i_rgb_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct sun4i_rgb *rgb = drm_connector_to_sun4i_rgb(connector);
struct sun4i_tcon *tcon = rgb->tcon;
u32 hsync = mode->hsync_end - mode->hsync_start;
u32 vsync = mode->vsync_end - mode->vsync_start;
unsigned long rate = mode->clock * 1000;
long rounded_rate;
DRM_DEBUG_DRIVER("Validating modes...\n");
if (hsync < 1)
return MODE_HSYNC_NARROW;
if (hsync > 0x3ff)
return MODE_HSYNC_WIDE;
if ((mode->hdisplay < 1) || (mode->htotal < 1))
return MODE_H_ILLEGAL;
if ((mode->hdisplay > 0x7ff) || (mode->htotal > 0xfff))
return MODE_BAD_HVALUE;
DRM_DEBUG_DRIVER("Horizontal parameters OK\n");
if (vsync < 1)
return MODE_VSYNC_NARROW;
if (vsync > 0x3ff)
return MODE_VSYNC_WIDE;
if ((mode->vdisplay < 1) || (mode->vtotal < 1))
return MODE_V_ILLEGAL;
if ((mode->vdisplay > 0x7ff) || (mode->vtotal > 0xfff))
return MODE_BAD_VVALUE;
DRM_DEBUG_DRIVER("Vertical parameters OK\n");
rounded_rate = clk_round_rate(tcon->dclk, rate);
if (rounded_rate < rate)
return MODE_CLOCK_LOW;
if (rounded_rate > rate)
return MODE_CLOCK_HIGH;
DRM_DEBUG_DRIVER("Clock rate OK\n");
return MODE_OK;
}
static void
sun4i_rgb_connector_destroy(struct drm_connector *connector)
{
struct sun4i_rgb *rgb = drm_connector_to_sun4i_rgb(connector);
struct sun4i_tcon *tcon = rgb->tcon;
drm_panel_detach(tcon->panel);
drm_connector_cleanup(connector);
}
static int sun4i_rgb_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
return 0;
}
static void sun4i_rgb_encoder_enable(struct drm_encoder *encoder)
{
struct sun4i_rgb *rgb = drm_encoder_to_sun4i_rgb(encoder);
struct sun4i_tcon *tcon = rgb->tcon;
DRM_DEBUG_DRIVER("Enabling RGB output\n");
if (!IS_ERR(tcon->panel))
drm_panel_prepare(tcon->panel);
sun4i_tcon_channel_enable(tcon, 0);
if (!IS_ERR(tcon->panel))
drm_panel_enable(tcon->panel);
}
static void sun4i_rgb_encoder_disable(struct drm_encoder *encoder)
{
struct sun4i_rgb *rgb = drm_encoder_to_sun4i_rgb(encoder);
struct sun4i_tcon *tcon = rgb->tcon;
DRM_DEBUG_DRIVER("Disabling RGB output\n");
if (!IS_ERR(tcon->panel))
drm_panel_disable(tcon->panel);
sun4i_tcon_channel_disable(tcon, 0);
if (!IS_ERR(tcon->panel))
drm_panel_unprepare(tcon->panel);
}
static void sun4i_rgb_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct sun4i_rgb *rgb = drm_encoder_to_sun4i_rgb(encoder);
struct sun4i_tcon *tcon = rgb->tcon;
sun4i_tcon0_mode_set(tcon, mode);
sun4i_tcon_set_mux(tcon, 0, encoder);
clk_set_phase(tcon->dclk, 120);
}
static void sun4i_rgb_enc_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
int sun4i_rgb_init(struct drm_device *drm, struct sun4i_tcon *tcon)
{
struct drm_encoder *encoder;
struct drm_bridge *bridge;
struct sun4i_rgb *rgb;
int ret;
rgb = devm_kzalloc(drm->dev, sizeof(*rgb), GFP_KERNEL);
if (!rgb)
return -ENOMEM;
rgb->tcon = tcon;
encoder = &rgb->encoder;
ret = drm_of_find_panel_or_bridge(tcon->dev->of_node, 1, 0,
&tcon->panel, &bridge);
if (ret) {
dev_info(drm->dev, "No panel or bridge found... RGB output disabled\n");
return 0;
}
drm_encoder_helper_add(&rgb->encoder,
&sun4i_rgb_enc_helper_funcs);
ret = drm_encoder_init(drm,
&rgb->encoder,
&sun4i_rgb_enc_funcs,
DRM_MODE_ENCODER_NONE,
NULL);
if (ret) {
dev_err(drm->dev, "Couldn't initialise the rgb encoder\n");
goto err_out;
}
rgb->encoder.possible_crtcs = BIT(drm_crtc_index(&tcon->crtc->crtc));
if (tcon->panel) {
drm_connector_helper_add(&rgb->connector,
&sun4i_rgb_con_helper_funcs);
ret = drm_connector_init(drm, &rgb->connector,
&sun4i_rgb_con_funcs,
DRM_MODE_CONNECTOR_Unknown);
if (ret) {
dev_err(drm->dev, "Couldn't initialise the rgb connector\n");
goto err_cleanup_connector;
}
drm_mode_connector_attach_encoder(&rgb->connector,
&rgb->encoder);
ret = drm_panel_attach(tcon->panel, &rgb->connector);
if (ret) {
dev_err(drm->dev, "Couldn't attach our panel\n");
goto err_cleanup_connector;
}
}
if (bridge) {
ret = drm_bridge_attach(encoder, bridge, NULL);
if (ret) {
dev_err(drm->dev, "Couldn't attach our bridge\n");
goto err_cleanup_connector;
}
}
return 0;
err_cleanup_connector:
drm_encoder_cleanup(&rgb->encoder);
err_out:
return ret;
}
