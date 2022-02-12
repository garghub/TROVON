int imx_drm_crtc_id(struct imx_drm_crtc *crtc)
{
return crtc->pipe;
}
static void imx_drm_driver_lastclose(struct drm_device *drm)
{
#if IS_ENABLED(CONFIG_DRM_IMX_FB_HELPER)
struct imx_drm_device *imxdrm = drm->dev_private;
if (imxdrm->fbhelper)
drm_fbdev_cma_restore_mode(imxdrm->fbhelper);
#endif
}
static int imx_drm_driver_unload(struct drm_device *drm)
{
#if IS_ENABLED(CONFIG_DRM_IMX_FB_HELPER)
struct imx_drm_device *imxdrm = drm->dev_private;
#endif
drm_kms_helper_poll_fini(drm);
#if IS_ENABLED(CONFIG_DRM_IMX_FB_HELPER)
if (imxdrm->fbhelper)
drm_fbdev_cma_fini(imxdrm->fbhelper);
#endif
component_unbind_all(drm->dev, drm);
drm_vblank_cleanup(drm);
drm_mode_config_cleanup(drm);
platform_set_drvdata(drm->platformdev, NULL);
return 0;
}
static struct imx_drm_crtc *imx_drm_find_crtc(struct drm_crtc *crtc)
{
struct imx_drm_device *imxdrm = crtc->dev->dev_private;
unsigned i;
for (i = 0; i < MAX_CRTC; i++)
if (imxdrm->crtc[i] && imxdrm->crtc[i]->crtc == crtc)
return imxdrm->crtc[i];
return NULL;
}
int imx_drm_panel_format_pins(struct drm_encoder *encoder,
u32 interface_pix_fmt, int hsync_pin, int vsync_pin)
{
struct imx_drm_crtc_helper_funcs *helper;
struct imx_drm_crtc *imx_crtc;
imx_crtc = imx_drm_find_crtc(encoder->crtc);
if (!imx_crtc)
return -EINVAL;
helper = &imx_crtc->imx_drm_helper_funcs;
if (helper->set_interface_pix_fmt)
return helper->set_interface_pix_fmt(encoder->crtc,
interface_pix_fmt, hsync_pin, vsync_pin);
return 0;
}
int imx_drm_panel_format(struct drm_encoder *encoder, u32 interface_pix_fmt)
{
return imx_drm_panel_format_pins(encoder, interface_pix_fmt, 2, 3);
}
int imx_drm_crtc_vblank_get(struct imx_drm_crtc *imx_drm_crtc)
{
return drm_vblank_get(imx_drm_crtc->crtc->dev, imx_drm_crtc->pipe);
}
void imx_drm_crtc_vblank_put(struct imx_drm_crtc *imx_drm_crtc)
{
drm_vblank_put(imx_drm_crtc->crtc->dev, imx_drm_crtc->pipe);
}
void imx_drm_handle_vblank(struct imx_drm_crtc *imx_drm_crtc)
{
drm_handle_vblank(imx_drm_crtc->crtc->dev, imx_drm_crtc->pipe);
}
static int imx_drm_enable_vblank(struct drm_device *drm, int crtc)
{
struct imx_drm_device *imxdrm = drm->dev_private;
struct imx_drm_crtc *imx_drm_crtc = imxdrm->crtc[crtc];
int ret;
if (!imx_drm_crtc)
return -EINVAL;
if (!imx_drm_crtc->imx_drm_helper_funcs.enable_vblank)
return -ENOSYS;
ret = imx_drm_crtc->imx_drm_helper_funcs.enable_vblank(
imx_drm_crtc->crtc);
return ret;
}
static void imx_drm_disable_vblank(struct drm_device *drm, int crtc)
{
struct imx_drm_device *imxdrm = drm->dev_private;
struct imx_drm_crtc *imx_drm_crtc = imxdrm->crtc[crtc];
if (!imx_drm_crtc)
return;
if (!imx_drm_crtc->imx_drm_helper_funcs.disable_vblank)
return;
imx_drm_crtc->imx_drm_helper_funcs.disable_vblank(imx_drm_crtc->crtc);
}
static void imx_drm_driver_preclose(struct drm_device *drm,
struct drm_file *file)
{
int i;
if (!file->is_master)
return;
for (i = 0; i < MAX_CRTC; i++)
imx_drm_disable_vblank(drm, i);
}
void imx_drm_connector_destroy(struct drm_connector *connector)
{
drm_connector_unregister(connector);
drm_connector_cleanup(connector);
}
void imx_drm_encoder_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
}
static void imx_drm_output_poll_changed(struct drm_device *drm)
{
#if IS_ENABLED(CONFIG_DRM_IMX_FB_HELPER)
struct imx_drm_device *imxdrm = drm->dev_private;
drm_fbdev_cma_hotplug_event(imxdrm->fbhelper);
#endif
}
static int imx_drm_driver_load(struct drm_device *drm, unsigned long flags)
{
struct imx_drm_device *imxdrm;
struct drm_connector *connector;
int ret;
imxdrm = devm_kzalloc(drm->dev, sizeof(*imxdrm), GFP_KERNEL);
if (!imxdrm)
return -ENOMEM;
imxdrm->drm = drm;
drm->dev_private = imxdrm;
drm->irq_enabled = true;
drm->mode_config.min_width = 64;
drm->mode_config.min_height = 64;
drm->mode_config.max_width = 4096;
drm->mode_config.max_height = 4096;
drm->mode_config.funcs = &imx_drm_mode_config_funcs;
drm_mode_config_init(drm);
ret = drm_vblank_init(drm, MAX_CRTC);
if (ret)
goto err_kms;
drm->vblank_disable_allowed = true;
platform_set_drvdata(drm->platformdev, drm);
ret = component_bind_all(drm->dev, drm);
if (ret)
goto err_vblank;
list_for_each_entry(connector, &drm->mode_config.connector_list, head) {
ret = drm_connector_register(connector);
if (ret) {
dev_err(drm->dev,
"[CONNECTOR:%d:%s] drm_connector_register failed: %d\n",
connector->base.id,
connector->name, ret);
goto err_unbind;
}
}
#if IS_ENABLED(CONFIG_DRM_IMX_FB_HELPER)
if (legacyfb_depth != 16 && legacyfb_depth != 32) {
dev_warn(drm->dev, "Invalid legacyfb_depth. Defaulting to 16bpp\n");
legacyfb_depth = 16;
}
imxdrm->fbhelper = drm_fbdev_cma_init(drm, legacyfb_depth,
drm->mode_config.num_crtc, MAX_CRTC);
if (IS_ERR(imxdrm->fbhelper)) {
ret = PTR_ERR(imxdrm->fbhelper);
imxdrm->fbhelper = NULL;
goto err_unbind;
}
#endif
drm_kms_helper_poll_init(drm);
return 0;
err_unbind:
component_unbind_all(drm->dev, drm);
err_vblank:
drm_vblank_cleanup(drm);
err_kms:
drm_mode_config_cleanup(drm);
return ret;
}
int imx_drm_add_crtc(struct drm_device *drm, struct drm_crtc *crtc,
struct imx_drm_crtc **new_crtc,
const struct imx_drm_crtc_helper_funcs *imx_drm_helper_funcs,
struct device_node *port)
{
struct imx_drm_device *imxdrm = drm->dev_private;
struct imx_drm_crtc *imx_drm_crtc;
int ret;
if (imxdrm->pipes >= MAX_CRTC)
return -EINVAL;
if (imxdrm->drm->open_count)
return -EBUSY;
imx_drm_crtc = kzalloc(sizeof(*imx_drm_crtc), GFP_KERNEL);
if (!imx_drm_crtc)
return -ENOMEM;
imx_drm_crtc->imx_drm_helper_funcs = *imx_drm_helper_funcs;
imx_drm_crtc->pipe = imxdrm->pipes++;
imx_drm_crtc->crtc = crtc;
crtc->port = port;
imxdrm->crtc[imx_drm_crtc->pipe] = imx_drm_crtc;
*new_crtc = imx_drm_crtc;
ret = drm_mode_crtc_set_gamma_size(imx_drm_crtc->crtc, 256);
if (ret)
goto err_register;
drm_crtc_helper_add(crtc,
imx_drm_crtc->imx_drm_helper_funcs.crtc_helper_funcs);
drm_crtc_init(drm, crtc,
imx_drm_crtc->imx_drm_helper_funcs.crtc_funcs);
return 0;
err_register:
imxdrm->crtc[imx_drm_crtc->pipe] = NULL;
kfree(imx_drm_crtc);
return ret;
}
int imx_drm_remove_crtc(struct imx_drm_crtc *imx_drm_crtc)
{
struct imx_drm_device *imxdrm = imx_drm_crtc->crtc->dev->dev_private;
drm_crtc_cleanup(imx_drm_crtc->crtc);
imxdrm->crtc[imx_drm_crtc->pipe] = NULL;
kfree(imx_drm_crtc);
return 0;
}
int imx_drm_encoder_parse_of(struct drm_device *drm,
struct drm_encoder *encoder, struct device_node *np)
{
uint32_t crtc_mask = drm_of_find_possible_crtcs(drm, np);
if (crtc_mask == 0)
return -EPROBE_DEFER;
encoder->possible_crtcs = crtc_mask;
encoder->possible_clones = ~0;
return 0;
}
static struct device_node *imx_drm_of_get_next_endpoint(
const struct device_node *parent, struct device_node *prev)
{
struct device_node *node = of_graph_get_next_endpoint(parent, prev);
of_node_put(prev);
return node;
}
int imx_drm_encoder_get_mux_id(struct device_node *node,
struct drm_encoder *encoder)
{
struct imx_drm_crtc *imx_crtc = imx_drm_find_crtc(encoder->crtc);
struct device_node *ep = NULL;
struct of_endpoint endpoint;
struct device_node *port;
int ret;
if (!node || !imx_crtc)
return -EINVAL;
do {
ep = imx_drm_of_get_next_endpoint(node, ep);
if (!ep)
break;
port = of_graph_get_remote_port(ep);
of_node_put(port);
if (port == imx_crtc->crtc->port) {
ret = of_graph_parse_endpoint(ep, &endpoint);
return ret ? ret : endpoint.port;
}
} while (ep);
return -EINVAL;
}
static int compare_of(struct device *dev, void *data)
{
struct device_node *np = data;
if (of_node_cmp(np->name, "lvds-channel") == 0) {
np = of_get_parent(np);
of_node_put(np);
}
return dev->of_node == np;
}
static int imx_drm_bind(struct device *dev)
{
return drm_platform_init(&imx_drm_driver, to_platform_device(dev));
}
static void imx_drm_unbind(struct device *dev)
{
drm_put_dev(dev_get_drvdata(dev));
}
static int imx_drm_platform_probe(struct platform_device *pdev)
{
struct device_node *ep, *port, *remote;
struct component_match *match = NULL;
int ret;
int i;
for (i = 0; ; i++) {
port = of_parse_phandle(pdev->dev.of_node, "ports", i);
if (!port)
break;
component_match_add(&pdev->dev, &match, compare_of, port);
}
if (i == 0) {
dev_err(&pdev->dev, "missing 'ports' property\n");
return -ENODEV;
}
for (i = 0; ; i++) {
port = of_parse_phandle(pdev->dev.of_node, "ports", i);
if (!port)
break;
for_each_child_of_node(port, ep) {
remote = of_graph_get_remote_port_parent(ep);
if (!remote || !of_device_is_available(remote)) {
of_node_put(remote);
continue;
} else if (!of_device_is_available(remote->parent)) {
dev_warn(&pdev->dev, "parent device of %s is not available\n",
remote->full_name);
of_node_put(remote);
continue;
}
component_match_add(&pdev->dev, &match, compare_of,
remote);
of_node_put(remote);
}
of_node_put(port);
}
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (ret)
return ret;
return component_master_add_with_match(&pdev->dev, &imx_drm_ops, match);
}
static int imx_drm_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &imx_drm_ops);
return 0;
}
static int imx_drm_suspend(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
if (drm_dev == NULL)
return 0;
drm_kms_helper_poll_disable(drm_dev);
return 0;
}
static int imx_drm_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
if (drm_dev == NULL)
return 0;
drm_helper_resume_force_mode(drm_dev);
drm_kms_helper_poll_enable(drm_dev);
return 0;
}
