static struct mxsfb_drm_private *
drm_connector_to_mxsfb_drm_private(struct drm_connector *connector)
{
return container_of(connector, struct mxsfb_drm_private, connector);
}
static int mxsfb_panel_get_modes(struct drm_connector *connector)
{
struct mxsfb_drm_private *mxsfb =
drm_connector_to_mxsfb_drm_private(connector);
if (mxsfb->panel)
return mxsfb->panel->funcs->get_modes(mxsfb->panel);
return 0;
}
static enum drm_connector_status
mxsfb_panel_connector_detect(struct drm_connector *connector, bool force)
{
struct mxsfb_drm_private *mxsfb =
drm_connector_to_mxsfb_drm_private(connector);
if (mxsfb->panel)
return connector_status_connected;
return connector_status_disconnected;
}
static void mxsfb_panel_connector_destroy(struct drm_connector *connector)
{
struct mxsfb_drm_private *mxsfb =
drm_connector_to_mxsfb_drm_private(connector);
if (mxsfb->panel)
drm_panel_detach(mxsfb->panel);
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
static int mxsfb_attach_endpoint(struct drm_device *drm,
const struct of_endpoint *ep)
{
struct mxsfb_drm_private *mxsfb = drm->dev_private;
struct device_node *np;
struct drm_panel *panel;
int ret = -EPROBE_DEFER;
np = of_graph_get_remote_port_parent(ep->local_node);
panel = of_drm_find_panel(np);
of_node_put(np);
if (!panel)
return -EPROBE_DEFER;
mxsfb->connector.dpms = DRM_MODE_DPMS_OFF;
mxsfb->connector.polled = 0;
drm_connector_helper_add(&mxsfb->connector,
&mxsfb_panel_connector_helper_funcs);
ret = drm_connector_init(drm, &mxsfb->connector,
&mxsfb_panel_connector_funcs,
DRM_MODE_CONNECTOR_Unknown);
if (!ret)
mxsfb->panel = panel;
return ret;
}
int mxsfb_create_output(struct drm_device *drm)
{
struct mxsfb_drm_private *mxsfb = drm->dev_private;
struct device_node *ep_np = NULL;
struct of_endpoint ep;
int ret;
for_each_endpoint_of_node(drm->dev->of_node, ep_np) {
ret = of_graph_parse_endpoint(ep_np, &ep);
if (!ret)
ret = mxsfb_attach_endpoint(drm, &ep);
if (ret) {
of_node_put(ep_np);
return ret;
}
}
if (!mxsfb->panel)
return -EPROBE_DEFER;
return 0;
}
