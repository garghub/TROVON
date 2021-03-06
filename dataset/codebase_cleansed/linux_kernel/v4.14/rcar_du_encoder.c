static void rcar_du_encoder_disable(struct drm_encoder *encoder)
{
struct rcar_du_encoder *renc = to_rcar_encoder(encoder);
if (renc->connector && renc->connector->panel) {
drm_panel_disable(renc->connector->panel);
drm_panel_unprepare(renc->connector->panel);
}
if (renc->lvds)
rcar_du_lvdsenc_enable(renc->lvds, encoder->crtc, false);
}
static void rcar_du_encoder_enable(struct drm_encoder *encoder)
{
struct rcar_du_encoder *renc = to_rcar_encoder(encoder);
if (renc->lvds)
rcar_du_lvdsenc_enable(renc->lvds, encoder->crtc, true);
if (renc->connector && renc->connector->panel) {
drm_panel_prepare(renc->connector->panel);
drm_panel_enable(renc->connector->panel);
}
}
static int rcar_du_encoder_atomic_check(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct rcar_du_encoder *renc = to_rcar_encoder(encoder);
struct drm_display_mode *adjusted_mode = &crtc_state->adjusted_mode;
const struct drm_display_mode *mode = &crtc_state->mode;
struct drm_connector *connector = conn_state->connector;
struct drm_device *dev = encoder->dev;
if (connector->connector_type == DRM_MODE_CONNECTOR_LVDS) {
const struct drm_display_mode *panel_mode;
if (list_empty(&connector->modes)) {
dev_dbg(dev->dev, "encoder: empty modes list\n");
return -EINVAL;
}
panel_mode = list_first_entry(&connector->modes,
struct drm_display_mode, head);
if (mode->hdisplay != panel_mode->hdisplay ||
mode->vdisplay != panel_mode->vdisplay)
return -EINVAL;
drm_mode_copy(adjusted_mode, panel_mode);
}
if (renc->lvds)
rcar_du_lvdsenc_atomic_check(renc->lvds, adjusted_mode);
return 0;
}
static void rcar_du_encoder_mode_set(struct drm_encoder *encoder,
struct drm_crtc_state *crtc_state,
struct drm_connector_state *conn_state)
{
struct rcar_du_encoder *renc = to_rcar_encoder(encoder);
struct drm_display_info *info = &conn_state->connector->display_info;
enum rcar_lvds_mode mode;
rcar_du_crtc_route_output(crtc_state->crtc, renc->output);
if (!renc->lvds) {
renc->connector = NULL;
return;
}
renc->connector = to_rcar_connector(conn_state->connector);
if (!info->num_bus_formats || !info->bus_formats) {
dev_err(encoder->dev->dev, "no LVDS bus format reported\n");
return;
}
switch (info->bus_formats[0]) {
case MEDIA_BUS_FMT_RGB666_1X7X3_SPWG:
case MEDIA_BUS_FMT_RGB888_1X7X4_JEIDA:
mode = RCAR_LVDS_MODE_JEIDA;
break;
case MEDIA_BUS_FMT_RGB888_1X7X4_SPWG:
mode = RCAR_LVDS_MODE_VESA;
break;
default:
dev_err(encoder->dev->dev,
"unsupported LVDS bus format 0x%04x\n",
info->bus_formats[0]);
return;
}
if (info->bus_flags & DRM_BUS_FLAG_DATA_LSB_TO_MSB)
mode |= RCAR_LVDS_MODE_MIRROR;
rcar_du_lvdsenc_set_mode(renc->lvds, mode);
}
int rcar_du_encoder_init(struct rcar_du_device *rcdu,
enum rcar_du_output output,
struct device_node *enc_node,
struct device_node *con_node)
{
struct rcar_du_encoder *renc;
struct drm_encoder *encoder;
struct drm_bridge *bridge = NULL;
int ret;
renc = devm_kzalloc(rcdu->dev, sizeof(*renc), GFP_KERNEL);
if (renc == NULL)
return -ENOMEM;
renc->output = output;
encoder = rcar_encoder_to_drm_encoder(renc);
switch (output) {
case RCAR_DU_OUTPUT_LVDS0:
renc->lvds = rcdu->lvds[0];
break;
case RCAR_DU_OUTPUT_LVDS1:
renc->lvds = rcdu->lvds[1];
break;
default:
break;
}
if (enc_node) {
dev_dbg(rcdu->dev, "initializing encoder %pOF for output %u\n",
enc_node, output);
bridge = of_drm_find_bridge(enc_node);
if (!bridge) {
ret = -EPROBE_DEFER;
goto done;
}
} else {
dev_dbg(rcdu->dev,
"initializing internal encoder for output %u\n",
output);
}
ret = drm_encoder_init(rcdu->ddev, encoder, &encoder_funcs,
DRM_MODE_ENCODER_NONE, NULL);
if (ret < 0)
goto done;
drm_encoder_helper_add(encoder, &encoder_helper_funcs);
if (bridge) {
ret = drm_bridge_attach(encoder, bridge, NULL);
if (ret) {
drm_encoder_cleanup(encoder);
return ret;
}
} else {
switch (output) {
case RCAR_DU_OUTPUT_LVDS0:
case RCAR_DU_OUTPUT_LVDS1:
ret = rcar_du_lvds_connector_init(rcdu, renc, con_node);
break;
default:
ret = -EINVAL;
break;
}
}
done:
if (ret < 0) {
if (encoder->name)
encoder->funcs->destroy(encoder);
devm_kfree(rcdu->dev, renc);
}
return ret;
}
