static inline struct atmel_hlcdc_rgb_output *
drm_connector_to_atmel_hlcdc_rgb_output(struct drm_connector *connector)
{
return container_of(connector, struct atmel_hlcdc_rgb_output,
connector);
}
static inline struct atmel_hlcdc_rgb_output *
drm_encoder_to_atmel_hlcdc_rgb_output(struct drm_encoder *encoder)
{
return container_of(encoder, struct atmel_hlcdc_rgb_output, encoder);
}
static void atmel_hlcdc_rgb_encoder_enable(struct drm_encoder *encoder)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_encoder_to_atmel_hlcdc_rgb_output(encoder);
if (rgb->panel) {
drm_panel_prepare(rgb->panel);
drm_panel_enable(rgb->panel);
}
}
static void atmel_hlcdc_rgb_encoder_disable(struct drm_encoder *encoder)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_encoder_to_atmel_hlcdc_rgb_output(encoder);
if (rgb->panel) {
drm_panel_disable(rgb->panel);
drm_panel_unprepare(rgb->panel);
}
}
static void atmel_hlcdc_rgb_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
memset(encoder, 0, sizeof(*encoder));
}
static int atmel_hlcdc_panel_get_modes(struct drm_connector *connector)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_connector_to_atmel_hlcdc_rgb_output(connector);
if (rgb->panel)
return rgb->panel->funcs->get_modes(rgb->panel);
return 0;
}
static int atmel_hlcdc_rgb_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_connector_to_atmel_hlcdc_rgb_output(connector);
return atmel_hlcdc_dc_mode_valid(rgb->dc, mode);
}
static struct drm_encoder *
atmel_hlcdc_rgb_best_encoder(struct drm_connector *connector)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_connector_to_atmel_hlcdc_rgb_output(connector);
return &rgb->encoder;
}
static enum drm_connector_status
atmel_hlcdc_panel_connector_detect(struct drm_connector *connector, bool force)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_connector_to_atmel_hlcdc_rgb_output(connector);
if (rgb->panel)
return connector_status_connected;
return connector_status_disconnected;
}
static void
atmel_hlcdc_panel_connector_destroy(struct drm_connector *connector)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_connector_to_atmel_hlcdc_rgb_output(connector);
if (rgb->panel)
drm_panel_detach(rgb->panel);
drm_connector_cleanup(connector);
}
static int atmel_hlcdc_check_endpoint(struct drm_device *dev,
const struct of_endpoint *ep)
{
struct device_node *np;
void *obj;
np = of_graph_get_remote_port_parent(ep->local_node);
obj = of_drm_find_panel(np);
if (!obj)
obj = of_drm_find_bridge(np);
of_node_put(np);
return obj ? 0 : -EPROBE_DEFER;
}
static int atmel_hlcdc_attach_endpoint(struct drm_device *dev,
const struct of_endpoint *ep)
{
struct atmel_hlcdc_dc *dc = dev->dev_private;
struct atmel_hlcdc_rgb_output *output;
struct device_node *np;
struct drm_panel *panel;
struct drm_bridge *bridge;
int ret;
output = devm_kzalloc(dev->dev, sizeof(*output), GFP_KERNEL);
if (!output)
return -EINVAL;
output->dc = dc;
drm_encoder_helper_add(&output->encoder,
&atmel_hlcdc_panel_encoder_helper_funcs);
ret = drm_encoder_init(dev, &output->encoder,
&atmel_hlcdc_panel_encoder_funcs,
DRM_MODE_ENCODER_NONE, NULL);
if (ret)
return ret;
output->encoder.possible_crtcs = 0x1;
np = of_graph_get_remote_port_parent(ep->local_node);
ret = -EPROBE_DEFER;
panel = of_drm_find_panel(np);
if (panel) {
of_node_put(np);
output->connector.dpms = DRM_MODE_DPMS_OFF;
output->connector.polled = DRM_CONNECTOR_POLL_CONNECT;
drm_connector_helper_add(&output->connector,
&atmel_hlcdc_panel_connector_helper_funcs);
ret = drm_connector_init(dev, &output->connector,
&atmel_hlcdc_panel_connector_funcs,
DRM_MODE_CONNECTOR_Unknown);
if (ret)
goto err_encoder_cleanup;
drm_mode_connector_attach_encoder(&output->connector,
&output->encoder);
ret = drm_panel_attach(panel, &output->connector);
if (ret) {
drm_connector_cleanup(&output->connector);
goto err_encoder_cleanup;
}
output->panel = panel;
return 0;
}
bridge = of_drm_find_bridge(np);
of_node_put(np);
if (bridge) {
output->encoder.bridge = bridge;
bridge->encoder = &output->encoder;
ret = drm_bridge_attach(dev, bridge);
if (!ret)
return 0;
}
err_encoder_cleanup:
drm_encoder_cleanup(&output->encoder);
return ret;
}
int atmel_hlcdc_create_outputs(struct drm_device *dev)
{
struct device_node *ep_np = NULL;
struct of_endpoint ep;
int ret;
for_each_endpoint_of_node(dev->dev->of_node, ep_np) {
ret = of_graph_parse_endpoint(ep_np, &ep);
if (!ret)
ret = atmel_hlcdc_check_endpoint(dev, &ep);
if (ret) {
of_node_put(ep_np);
return ret;
}
}
for_each_endpoint_of_node(dev->dev->of_node, ep_np) {
ret = of_graph_parse_endpoint(ep_np, &ep);
if (!ret)
ret = atmel_hlcdc_attach_endpoint(dev, &ep);
if (ret) {
of_node_put(ep_np);
return ret;
}
}
return 0;
}
