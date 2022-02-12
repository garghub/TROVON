static inline struct panel_bridge *
drm_bridge_to_panel_bridge(struct drm_bridge *bridge)
{
return container_of(bridge, struct panel_bridge, bridge);
}
static inline struct panel_bridge *
drm_connector_to_panel_bridge(struct drm_connector *connector)
{
return container_of(connector, struct panel_bridge, connector);
}
static int panel_bridge_connector_get_modes(struct drm_connector *connector)
{
struct panel_bridge *panel_bridge =
drm_connector_to_panel_bridge(connector);
return drm_panel_get_modes(panel_bridge->panel);
}
static int panel_bridge_attach(struct drm_bridge *bridge)
{
struct panel_bridge *panel_bridge = drm_bridge_to_panel_bridge(bridge);
struct drm_connector *connector = &panel_bridge->connector;
int ret;
if (!bridge->encoder) {
DRM_ERROR("Missing encoder\n");
return -ENODEV;
}
drm_connector_helper_add(connector,
&panel_bridge_connector_helper_funcs);
ret = drm_connector_init(bridge->dev, connector,
&panel_bridge_connector_funcs,
panel_bridge->connector_type);
if (ret) {
DRM_ERROR("Failed to initialize connector\n");
return ret;
}
drm_mode_connector_attach_encoder(&panel_bridge->connector,
bridge->encoder);
ret = drm_panel_attach(panel_bridge->panel, &panel_bridge->connector);
if (ret < 0)
return ret;
return 0;
}
static void panel_bridge_detach(struct drm_bridge *bridge)
{
struct panel_bridge *panel_bridge = drm_bridge_to_panel_bridge(bridge);
drm_panel_detach(panel_bridge->panel);
}
static void panel_bridge_pre_enable(struct drm_bridge *bridge)
{
struct panel_bridge *panel_bridge = drm_bridge_to_panel_bridge(bridge);
drm_panel_prepare(panel_bridge->panel);
}
static void panel_bridge_enable(struct drm_bridge *bridge)
{
struct panel_bridge *panel_bridge = drm_bridge_to_panel_bridge(bridge);
drm_panel_enable(panel_bridge->panel);
}
static void panel_bridge_disable(struct drm_bridge *bridge)
{
struct panel_bridge *panel_bridge = drm_bridge_to_panel_bridge(bridge);
drm_panel_disable(panel_bridge->panel);
}
static void panel_bridge_post_disable(struct drm_bridge *bridge)
{
struct panel_bridge *panel_bridge = drm_bridge_to_panel_bridge(bridge);
drm_panel_unprepare(panel_bridge->panel);
}
struct drm_bridge *drm_panel_bridge_add(struct drm_panel *panel,
u32 connector_type)
{
struct panel_bridge *panel_bridge;
int ret;
if (!panel)
return ERR_PTR(-EINVAL);
panel_bridge = devm_kzalloc(panel->dev, sizeof(*panel_bridge),
GFP_KERNEL);
if (!panel_bridge)
return ERR_PTR(-ENOMEM);
panel_bridge->connector_type = connector_type;
panel_bridge->panel = panel;
panel_bridge->bridge.funcs = &panel_bridge_bridge_funcs;
#ifdef CONFIG_OF
panel_bridge->bridge.of_node = panel->dev->of_node;
#endif
ret = drm_bridge_add(&panel_bridge->bridge);
if (ret)
return ERR_PTR(ret);
return &panel_bridge->bridge;
}
void drm_panel_bridge_remove(struct drm_bridge *bridge)
{
struct panel_bridge *panel_bridge = drm_bridge_to_panel_bridge(bridge);
drm_bridge_remove(bridge);
devm_kfree(panel_bridge->panel->dev, bridge);
}
