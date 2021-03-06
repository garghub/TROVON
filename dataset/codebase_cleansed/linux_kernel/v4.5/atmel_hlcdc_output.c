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
static inline struct atmel_hlcdc_panel *
atmel_hlcdc_rgb_output_to_panel(struct atmel_hlcdc_rgb_output *output)
{
return container_of(output, struct atmel_hlcdc_panel, base);
}
static void atmel_hlcdc_panel_encoder_enable(struct drm_encoder *encoder)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_encoder_to_atmel_hlcdc_rgb_output(encoder);
struct atmel_hlcdc_panel *panel = atmel_hlcdc_rgb_output_to_panel(rgb);
drm_panel_enable(panel->panel);
}
static void atmel_hlcdc_panel_encoder_disable(struct drm_encoder *encoder)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_encoder_to_atmel_hlcdc_rgb_output(encoder);
struct atmel_hlcdc_panel *panel = atmel_hlcdc_rgb_output_to_panel(rgb);
drm_panel_disable(panel->panel);
}
static bool
atmel_hlcdc_panel_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted)
{
return true;
}
static void
atmel_hlcdc_rgb_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_encoder_to_atmel_hlcdc_rgb_output(encoder);
struct drm_display_info *info = &rgb->connector.display_info;
unsigned int cfg;
cfg = 0;
if (info->num_bus_formats) {
switch (info->bus_formats[0]) {
case MEDIA_BUS_FMT_RGB565_1X16:
cfg |= ATMEL_HLCDC_CONNECTOR_RGB565 << 8;
break;
case MEDIA_BUS_FMT_RGB666_1X18:
cfg |= ATMEL_HLCDC_CONNECTOR_RGB666 << 8;
break;
case MEDIA_BUS_FMT_RGB888_1X24:
cfg |= ATMEL_HLCDC_CONNECTOR_RGB888 << 8;
break;
case MEDIA_BUS_FMT_RGB444_1X12:
default:
break;
}
}
regmap_update_bits(rgb->dc->hlcdc->regmap, ATMEL_HLCDC_CFG(5),
ATMEL_HLCDC_MODE_MASK,
cfg);
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
struct atmel_hlcdc_panel *panel = atmel_hlcdc_rgb_output_to_panel(rgb);
return panel->panel->funcs->get_modes(panel->panel);
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
return connector_status_connected;
}
static void
atmel_hlcdc_panel_connector_destroy(struct drm_connector *connector)
{
struct atmel_hlcdc_rgb_output *rgb =
drm_connector_to_atmel_hlcdc_rgb_output(connector);
struct atmel_hlcdc_panel *panel = atmel_hlcdc_rgb_output_to_panel(rgb);
drm_panel_detach(panel->panel);
drm_connector_cleanup(connector);
}
static int atmel_hlcdc_create_panel_output(struct drm_device *dev,
struct of_endpoint *ep)
{
struct atmel_hlcdc_dc *dc = dev->dev_private;
struct device_node *np;
struct drm_panel *p = NULL;
struct atmel_hlcdc_panel *panel;
int ret;
np = of_graph_get_remote_port_parent(ep->local_node);
if (!np)
return -EINVAL;
p = of_drm_find_panel(np);
of_node_put(np);
if (!p)
return -EPROBE_DEFER;
panel = devm_kzalloc(dev->dev, sizeof(*panel), GFP_KERNEL);
if (!panel)
return -EINVAL;
panel->base.dpms = DRM_MODE_DPMS_OFF;
panel->base.dc = dc;
drm_encoder_helper_add(&panel->base.encoder,
&atmel_hlcdc_panel_encoder_helper_funcs);
ret = drm_encoder_init(dev, &panel->base.encoder,
&atmel_hlcdc_panel_encoder_funcs,
DRM_MODE_ENCODER_LVDS, NULL);
if (ret)
return ret;
panel->base.connector.dpms = DRM_MODE_DPMS_OFF;
panel->base.connector.polled = DRM_CONNECTOR_POLL_CONNECT;
drm_connector_helper_add(&panel->base.connector,
&atmel_hlcdc_panel_connector_helper_funcs);
ret = drm_connector_init(dev, &panel->base.connector,
&atmel_hlcdc_panel_connector_funcs,
DRM_MODE_CONNECTOR_LVDS);
if (ret)
goto err_encoder_cleanup;
drm_mode_connector_attach_encoder(&panel->base.connector,
&panel->base.encoder);
panel->base.encoder.possible_crtcs = 0x1;
drm_panel_attach(p, &panel->base.connector);
panel->panel = p;
return 0;
err_encoder_cleanup:
drm_encoder_cleanup(&panel->base.encoder);
return ret;
}
int atmel_hlcdc_create_outputs(struct drm_device *dev)
{
struct device_node *port_np, *np;
struct of_endpoint ep;
int ret;
port_np = of_get_child_by_name(dev->dev->of_node, "port");
if (!port_np)
return -EINVAL;
np = of_get_child_by_name(port_np, "endpoint");
of_node_put(port_np);
if (!np)
return -EINVAL;
ret = of_graph_parse_endpoint(np, &ep);
of_node_put(port_np);
if (ret)
return ret;
return atmel_hlcdc_create_panel_output(dev, &ep);
}
