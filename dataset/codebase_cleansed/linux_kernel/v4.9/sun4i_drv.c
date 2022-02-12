static int sun4i_drv_enable_vblank(struct drm_device *drm, unsigned int pipe)
{
struct sun4i_drv *drv = drm->dev_private;
struct sun4i_tcon *tcon = drv->tcon;
DRM_DEBUG_DRIVER("Enabling VBLANK on pipe %d\n", pipe);
sun4i_tcon_enable_vblank(tcon, true);
return 0;
}
static void sun4i_drv_disable_vblank(struct drm_device *drm, unsigned int pipe)
{
struct sun4i_drv *drv = drm->dev_private;
struct sun4i_tcon *tcon = drv->tcon;
DRM_DEBUG_DRIVER("Disabling VBLANK on pipe %d\n", pipe);
sun4i_tcon_enable_vblank(tcon, false);
}
static void sun4i_remove_framebuffers(void)
{
struct apertures_struct *ap;
ap = alloc_apertures(1);
if (!ap)
return;
ap->ranges[0].base = 0;
ap->ranges[0].size = ~0;
drm_fb_helper_remove_conflicting_framebuffers(ap, "sun4i-drm-fb", false);
kfree(ap);
}
static int sun4i_drv_bind(struct device *dev)
{
struct drm_device *drm;
struct sun4i_drv *drv;
int ret;
drm = drm_dev_alloc(&sun4i_drv_driver, dev);
if (IS_ERR(drm))
return PTR_ERR(drm);
drv = devm_kzalloc(dev, sizeof(*drv), GFP_KERNEL);
if (!drv) {
ret = -ENOMEM;
goto free_drm;
}
drm->dev_private = drv;
drm_vblank_init(drm, 1);
drm_mode_config_init(drm);
ret = component_bind_all(drm->dev, drm);
if (ret) {
dev_err(drm->dev, "Couldn't bind all pipelines components\n");
goto free_drm;
}
drv->layers = sun4i_layers_init(drm);
if (IS_ERR(drv->layers)) {
dev_err(drm->dev, "Couldn't create the planes\n");
ret = PTR_ERR(drv->layers);
goto free_drm;
}
drv->crtc = sun4i_crtc_init(drm);
if (!drv->crtc) {
dev_err(drm->dev, "Couldn't create the CRTC\n");
ret = -EINVAL;
goto free_drm;
}
drm->irq_enabled = true;
sun4i_remove_framebuffers();
drv->fbdev = sun4i_framebuffer_init(drm);
if (IS_ERR(drv->fbdev)) {
dev_err(drm->dev, "Couldn't create our framebuffer\n");
ret = PTR_ERR(drv->fbdev);
goto free_drm;
}
drm_kms_helper_poll_init(drm);
ret = drm_dev_register(drm, 0);
if (ret)
goto free_drm;
return 0;
free_drm:
drm_dev_unref(drm);
return ret;
}
static void sun4i_drv_unbind(struct device *dev)
{
struct drm_device *drm = dev_get_drvdata(dev);
drm_dev_unregister(drm);
drm_kms_helper_poll_fini(drm);
sun4i_framebuffer_free(drm);
drm_vblank_cleanup(drm);
drm_dev_unref(drm);
}
static bool sun4i_drv_node_is_frontend(struct device_node *node)
{
return of_device_is_compatible(node, "allwinner,sun5i-a13-display-frontend") ||
of_device_is_compatible(node, "allwinner,sun8i-a33-display-frontend");
}
static bool sun4i_drv_node_is_tcon(struct device_node *node)
{
return of_device_is_compatible(node, "allwinner,sun5i-a13-tcon") ||
of_device_is_compatible(node, "allwinner,sun8i-a33-tcon");
}
static int compare_of(struct device *dev, void *data)
{
DRM_DEBUG_DRIVER("Comparing of node %s with %s\n",
of_node_full_name(dev->of_node),
of_node_full_name(data));
return dev->of_node == data;
}
static int sun4i_drv_add_endpoints(struct device *dev,
struct component_match **match,
struct device_node *node)
{
struct device_node *port, *ep, *remote;
int count = 0;
if (!sun4i_drv_node_is_frontend(node) &&
!of_device_is_available(node))
return 0;
if (!sun4i_drv_node_is_frontend(node)) {
DRM_DEBUG_DRIVER("Adding component %s\n",
of_node_full_name(node));
component_match_add(dev, match, compare_of, node);
count++;
}
port = of_graph_get_port_by_id(node, 1);
if (!port) {
DRM_DEBUG_DRIVER("No output to bind\n");
return count;
}
for_each_available_child_of_node(port, ep) {
remote = of_graph_get_remote_port_parent(ep);
if (!remote) {
DRM_DEBUG_DRIVER("Error retrieving the output node\n");
of_node_put(remote);
continue;
}
if (sun4i_drv_node_is_tcon(node)) {
struct of_endpoint endpoint;
if (of_graph_parse_endpoint(ep, &endpoint)) {
DRM_DEBUG_DRIVER("Couldn't parse endpoint\n");
continue;
}
if (!endpoint.id) {
DRM_DEBUG_DRIVER("Endpoint is our panel... skipping\n");
continue;
}
}
count += sun4i_drv_add_endpoints(dev, match, remote);
of_node_put(remote);
}
return count;
}
static int sun4i_drv_probe(struct platform_device *pdev)
{
struct component_match *match = NULL;
struct device_node *np = pdev->dev.of_node;
int i, count = 0;
for (i = 0;; i++) {
struct device_node *pipeline = of_parse_phandle(np,
"allwinner,pipelines",
i);
if (!pipeline)
break;
count += sun4i_drv_add_endpoints(&pdev->dev, &match,
pipeline);
of_node_put(pipeline);
DRM_DEBUG_DRIVER("Queued %d outputs on pipeline %d\n",
count, i);
}
if (count)
return component_master_add_with_match(&pdev->dev,
&sun4i_drv_master_ops,
match);
else
return 0;
}
static int sun4i_drv_remove(struct platform_device *pdev)
{
return 0;
}
