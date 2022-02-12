static inline struct dumb_vga *
drm_bridge_to_dumb_vga(struct drm_bridge *bridge)
{
return container_of(bridge, struct dumb_vga, bridge);
}
static inline struct dumb_vga *
drm_connector_to_dumb_vga(struct drm_connector *connector)
{
return container_of(connector, struct dumb_vga, connector);
}
static int dumb_vga_get_modes(struct drm_connector *connector)
{
struct dumb_vga *vga = drm_connector_to_dumb_vga(connector);
struct edid *edid;
int ret;
if (IS_ERR(vga->ddc))
goto fallback;
edid = drm_get_edid(connector, vga->ddc);
if (!edid) {
DRM_INFO("EDID readout failed, falling back to standard modes\n");
goto fallback;
}
drm_mode_connector_update_edid_property(connector, edid);
return drm_add_edid_modes(connector, edid);
fallback:
ret = drm_add_modes_noedid(connector, 1920, 1200);
drm_set_preferred_mode(connector, 1024, 768);
return ret;
}
static enum drm_connector_status
dumb_vga_connector_detect(struct drm_connector *connector, bool force)
{
struct dumb_vga *vga = drm_connector_to_dumb_vga(connector);
if (!IS_ERR(vga->ddc) && drm_probe_ddc(vga->ddc))
return connector_status_connected;
return connector_status_unknown;
}
static int dumb_vga_attach(struct drm_bridge *bridge)
{
struct dumb_vga *vga = drm_bridge_to_dumb_vga(bridge);
int ret;
if (!bridge->encoder) {
DRM_ERROR("Missing encoder\n");
return -ENODEV;
}
drm_connector_helper_add(&vga->connector,
&dumb_vga_con_helper_funcs);
ret = drm_connector_init(bridge->dev, &vga->connector,
&dumb_vga_con_funcs, DRM_MODE_CONNECTOR_VGA);
if (ret) {
DRM_ERROR("Failed to initialize connector\n");
return ret;
}
drm_mode_connector_attach_encoder(&vga->connector,
bridge->encoder);
return 0;
}
static struct i2c_adapter *dumb_vga_retrieve_ddc(struct device *dev)
{
struct device_node *end_node, *phandle, *remote;
struct i2c_adapter *ddc;
end_node = of_graph_get_endpoint_by_regs(dev->of_node, 1, -1);
if (!end_node) {
dev_err(dev, "Missing connector endpoint\n");
return ERR_PTR(-ENODEV);
}
remote = of_graph_get_remote_port_parent(end_node);
of_node_put(end_node);
if (!remote) {
dev_err(dev, "Enable to parse remote node\n");
return ERR_PTR(-EINVAL);
}
phandle = of_parse_phandle(remote, "ddc-i2c-bus", 0);
of_node_put(remote);
if (!phandle)
return ERR_PTR(-ENODEV);
ddc = of_get_i2c_adapter_by_node(phandle);
of_node_put(phandle);
if (!ddc)
return ERR_PTR(-EPROBE_DEFER);
return ddc;
}
static int dumb_vga_probe(struct platform_device *pdev)
{
struct dumb_vga *vga;
int ret;
vga = devm_kzalloc(&pdev->dev, sizeof(*vga), GFP_KERNEL);
if (!vga)
return -ENOMEM;
platform_set_drvdata(pdev, vga);
vga->ddc = dumb_vga_retrieve_ddc(&pdev->dev);
if (IS_ERR(vga->ddc)) {
if (PTR_ERR(vga->ddc) == -ENODEV) {
dev_dbg(&pdev->dev,
"No i2c bus specified. Disabling EDID readout\n");
} else {
dev_err(&pdev->dev, "Couldn't retrieve i2c bus\n");
return PTR_ERR(vga->ddc);
}
}
vga->bridge.funcs = &dumb_vga_bridge_funcs;
vga->bridge.of_node = pdev->dev.of_node;
ret = drm_bridge_add(&vga->bridge);
if (ret && !IS_ERR(vga->ddc))
i2c_put_adapter(vga->ddc);
return ret;
}
static int dumb_vga_remove(struct platform_device *pdev)
{
struct dumb_vga *vga = platform_get_drvdata(pdev);
drm_bridge_remove(&vga->bridge);
if (!IS_ERR(vga->ddc))
i2c_put_adapter(vga->ddc);
return 0;
}
