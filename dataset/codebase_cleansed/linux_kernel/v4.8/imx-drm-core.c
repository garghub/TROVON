unsigned int imx_drm_crtc_id(struct imx_drm_crtc *crtc)
{
return drm_crtc_index(crtc->crtc);
}
static void imx_drm_driver_lastclose(struct drm_device *drm)
{
struct imx_drm_device *imxdrm = drm->dev_private;
drm_fbdev_cma_restore_mode(imxdrm->fbhelper);
}
static int imx_drm_driver_unload(struct drm_device *drm)
{
struct imx_drm_device *imxdrm = drm->dev_private;
drm_kms_helper_poll_fini(drm);
if (imxdrm->fbhelper)
drm_fbdev_cma_fini(imxdrm->fbhelper);
component_unbind_all(drm->dev, drm);
drm_vblank_cleanup(drm);
drm_mode_config_cleanup(drm);
platform_set_drvdata(drm->platformdev, NULL);
return 0;
}
int imx_drm_crtc_vblank_get(struct imx_drm_crtc *imx_drm_crtc)
{
return drm_crtc_vblank_get(imx_drm_crtc->crtc);
}
void imx_drm_crtc_vblank_put(struct imx_drm_crtc *imx_drm_crtc)
{
drm_crtc_vblank_put(imx_drm_crtc->crtc);
}
void imx_drm_handle_vblank(struct imx_drm_crtc *imx_drm_crtc)
{
drm_crtc_handle_vblank(imx_drm_crtc->crtc);
}
static int imx_drm_enable_vblank(struct drm_device *drm, unsigned int pipe)
{
struct imx_drm_device *imxdrm = drm->dev_private;
struct imx_drm_crtc *imx_drm_crtc = imxdrm->crtc[pipe];
int ret;
if (!imx_drm_crtc)
return -EINVAL;
if (!imx_drm_crtc->imx_drm_helper_funcs.enable_vblank)
return -ENOSYS;
ret = imx_drm_crtc->imx_drm_helper_funcs.enable_vblank(
imx_drm_crtc->crtc);
return ret;
}
static void imx_drm_disable_vblank(struct drm_device *drm, unsigned int pipe)
{
struct imx_drm_device *imxdrm = drm->dev_private;
struct imx_drm_crtc *imx_drm_crtc = imxdrm->crtc[pipe];
if (!imx_drm_crtc)
return;
if (!imx_drm_crtc->imx_drm_helper_funcs.disable_vblank)
return;
imx_drm_crtc->imx_drm_helper_funcs.disable_vblank(imx_drm_crtc->crtc);
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
struct imx_drm_device *imxdrm = drm->dev_private;
drm_fbdev_cma_hotplug_event(imxdrm->fbhelper);
}
static int imx_drm_atomic_check(struct drm_device *dev,
struct drm_atomic_state *state)
{
int ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_planes(dev, state);
if (ret)
return ret;
ret = drm_atomic_helper_check_modeset(dev, state);
if (ret)
return ret;
return ret;
}
static void imx_drm_atomic_commit_tail(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
struct drm_crtc *crtc;
struct drm_crtc_state *crtc_state;
struct drm_plane_state *plane_state;
struct drm_gem_cma_object *cma_obj;
struct fence *excl;
unsigned shared_count;
struct fence **shared;
unsigned int i, j;
int ret;
for_each_crtc_in_state(state, crtc, crtc_state, i) {
plane_state = crtc->primary->state;
if (plane_state->fb) {
cma_obj = drm_fb_cma_get_gem_obj(plane_state->fb, 0);
if (cma_obj->base.dma_buf) {
ret = reservation_object_get_fences_rcu(
cma_obj->base.dma_buf->resv, &excl,
&shared_count, &shared);
if (unlikely(ret))
DRM_ERROR("failed to get fences "
"for buffer\n");
if (excl) {
fence_wait(excl, false);
fence_put(excl);
}
for (j = 0; j < shared_count; i++) {
fence_wait(shared[j], false);
fence_put(shared[j]);
}
}
}
}
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_planes(dev, state, true);
drm_atomic_helper_commit_modeset_enables(dev, state);
drm_atomic_helper_commit_hw_done(state);
drm_atomic_helper_wait_for_vblanks(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
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
drm->mode_config.helper_private = &imx_drm_mode_config_helpers;
drm_mode_config_init(drm);
ret = drm_vblank_init(drm, MAX_CRTC);
if (ret)
goto err_kms;
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
drm_mode_config_reset(drm);
#if IS_ENABLED(CONFIG_DRM_FBDEV_EMULATION)
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
struct imx_drm_crtc **new_crtc, struct drm_plane *primary_plane,
const struct imx_drm_crtc_helper_funcs *imx_drm_helper_funcs,
struct device_node *port)
{
struct imx_drm_device *imxdrm = drm->dev_private;
struct imx_drm_crtc *imx_drm_crtc;
if (imxdrm->pipes >= MAX_CRTC)
return -EINVAL;
if (imxdrm->drm->open_count)
return -EBUSY;
imx_drm_crtc = kzalloc(sizeof(*imx_drm_crtc), GFP_KERNEL);
if (!imx_drm_crtc)
return -ENOMEM;
imx_drm_crtc->imx_drm_helper_funcs = *imx_drm_helper_funcs;
imx_drm_crtc->crtc = crtc;
crtc->port = port;
imxdrm->crtc[imxdrm->pipes++] = imx_drm_crtc;
*new_crtc = imx_drm_crtc;
drm_crtc_helper_add(crtc,
imx_drm_crtc->imx_drm_helper_funcs.crtc_helper_funcs);
drm_crtc_init_with_planes(drm, crtc, primary_plane, NULL,
imx_drm_crtc->imx_drm_helper_funcs.crtc_funcs, NULL);
return 0;
}
int imx_drm_remove_crtc(struct imx_drm_crtc *imx_drm_crtc)
{
struct imx_drm_device *imxdrm = imx_drm_crtc->crtc->dev->dev_private;
unsigned int pipe = drm_crtc_index(imx_drm_crtc->crtc);
drm_crtc_cleanup(imx_drm_crtc->crtc);
imxdrm->crtc[pipe] = NULL;
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
static int compare_of(struct device *dev, void *data)
{
struct device_node *np = data;
if (strcmp(dev->driver->name, "imx-ipuv3-crtc") == 0) {
struct ipu_client_platformdata *pdata = dev->platform_data;
return pdata->of_node == np;
}
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
int ret = drm_of_component_probe(&pdev->dev, compare_of, &imx_drm_ops);
if (!ret)
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
return ret;
}
static int imx_drm_platform_remove(struct platform_device *pdev)
{
component_master_del(&pdev->dev, &imx_drm_ops);
return 0;
}
static int imx_drm_suspend(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
struct imx_drm_device *imxdrm;
if (drm_dev == NULL)
return 0;
drm_kms_helper_poll_disable(drm_dev);
imxdrm = drm_dev->dev_private;
imxdrm->state = drm_atomic_helper_suspend(drm_dev);
if (IS_ERR(imxdrm->state)) {
drm_kms_helper_poll_enable(drm_dev);
return PTR_ERR(imxdrm->state);
}
return 0;
}
static int imx_drm_resume(struct device *dev)
{
struct drm_device *drm_dev = dev_get_drvdata(dev);
struct imx_drm_device *imx_drm;
if (drm_dev == NULL)
return 0;
imx_drm = drm_dev->dev_private;
drm_atomic_helper_resume(drm_dev, imx_drm->state);
drm_kms_helper_poll_enable(drm_dev);
return 0;
}
