static enum drm_connector_status mdp4_lvds_connector_detect(
struct drm_connector *connector, bool force)
{
struct mdp4_lvds_connector *mdp4_lvds_connector =
to_mdp4_lvds_connector(connector);
if (!mdp4_lvds_connector->panel)
mdp4_lvds_connector->panel =
of_drm_find_panel(mdp4_lvds_connector->panel_node);
return mdp4_lvds_connector->panel ?
connector_status_connected :
connector_status_disconnected;
}
static void mdp4_lvds_connector_destroy(struct drm_connector *connector)
{
struct mdp4_lvds_connector *mdp4_lvds_connector =
to_mdp4_lvds_connector(connector);
drm_connector_cleanup(connector);
kfree(mdp4_lvds_connector);
}
static int mdp4_lvds_connector_get_modes(struct drm_connector *connector)
{
struct mdp4_lvds_connector *mdp4_lvds_connector =
to_mdp4_lvds_connector(connector);
struct drm_panel *panel = mdp4_lvds_connector->panel;
int ret = 0;
if (panel) {
drm_panel_attach(panel, connector);
ret = panel->funcs->get_modes(panel);
drm_panel_detach(panel);
}
return ret;
}
static int mdp4_lvds_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct mdp4_lvds_connector *mdp4_lvds_connector =
to_mdp4_lvds_connector(connector);
struct drm_encoder *encoder = mdp4_lvds_connector->encoder;
long actual, requested;
requested = 1000 * mode->clock;
actual = mdp4_lcdc_round_pixclk(encoder, requested);
DBG("requested=%ld, actual=%ld", requested, actual);
if (actual != requested)
return MODE_CLOCK_RANGE;
return MODE_OK;
}
static struct drm_encoder *
mdp4_lvds_connector_best_encoder(struct drm_connector *connector)
{
struct mdp4_lvds_connector *mdp4_lvds_connector =
to_mdp4_lvds_connector(connector);
return mdp4_lvds_connector->encoder;
}
struct drm_connector *mdp4_lvds_connector_init(struct drm_device *dev,
struct device_node *panel_node, struct drm_encoder *encoder)
{
struct drm_connector *connector = NULL;
struct mdp4_lvds_connector *mdp4_lvds_connector;
mdp4_lvds_connector = kzalloc(sizeof(*mdp4_lvds_connector), GFP_KERNEL);
if (!mdp4_lvds_connector)
return ERR_PTR(-ENOMEM);
mdp4_lvds_connector->encoder = encoder;
mdp4_lvds_connector->panel_node = panel_node;
connector = &mdp4_lvds_connector->base;
drm_connector_init(dev, connector, &mdp4_lvds_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
drm_connector_helper_add(connector, &mdp4_lvds_connector_helper_funcs);
connector->polled = 0;
connector->interlace_allowed = 0;
connector->doublescan_allowed = 0;
drm_mode_connector_attach_encoder(connector, encoder);
return connector;
}
