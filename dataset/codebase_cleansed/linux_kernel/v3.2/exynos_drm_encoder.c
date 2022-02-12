static void exynos_drm_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct drm_device *dev = encoder->dev;
struct drm_connector *connector;
struct exynos_drm_manager *manager = exynos_drm_get_manager(encoder);
struct exynos_drm_manager_ops *manager_ops = manager->ops;
DRM_DEBUG_KMS("%s, encoder dpms: %d\n", __FILE__, mode);
switch (mode) {
case DRM_MODE_DPMS_ON:
if (manager_ops && manager_ops->commit)
manager_ops->commit(manager->dev);
break;
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
if (manager_ops && manager_ops->disable)
manager_ops->disable(manager->dev);
break;
default:
DRM_ERROR("unspecified mode %d\n", mode);
break;
}
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->encoder == encoder) {
struct exynos_drm_display_ops *display_ops =
manager->display_ops;
DRM_DEBUG_KMS("connector[%d] dpms[%d]\n",
connector->base.id, mode);
if (display_ops && display_ops->power_on)
display_ops->power_on(manager->dev, mode);
}
}
}
static bool
exynos_drm_encoder_mode_fixup(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return true;
}
static void exynos_drm_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct drm_connector *connector;
struct exynos_drm_manager *manager = exynos_drm_get_manager(encoder);
struct exynos_drm_manager_ops *manager_ops = manager->ops;
struct exynos_drm_overlay_ops *overlay_ops = manager->overlay_ops;
struct exynos_drm_overlay *overlay = get_exynos_drm_overlay(dev,
encoder->crtc);
DRM_DEBUG_KMS("%s\n", __FILE__);
mode = adjusted_mode;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->encoder == encoder) {
if (manager_ops && manager_ops->mode_set)
manager_ops->mode_set(manager->dev, mode);
if (overlay_ops && overlay_ops->mode_set)
overlay_ops->mode_set(manager->dev, overlay);
}
}
}
static void exynos_drm_encoder_prepare(struct drm_encoder *encoder)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
}
static void exynos_drm_encoder_commit(struct drm_encoder *encoder)
{
struct exynos_drm_manager *manager = exynos_drm_get_manager(encoder);
struct exynos_drm_manager_ops *manager_ops = manager->ops;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (manager_ops && manager_ops->commit)
manager_ops->commit(manager->dev);
}
static struct drm_crtc *
exynos_drm_encoder_get_crtc(struct drm_encoder *encoder)
{
return encoder->crtc;
}
static void exynos_drm_encoder_destroy(struct drm_encoder *encoder)
{
struct exynos_drm_encoder *exynos_encoder =
to_exynos_encoder(encoder);
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_encoder->manager->pipe = -1;
drm_encoder_cleanup(encoder);
encoder->dev->mode_config.num_encoder--;
kfree(exynos_encoder);
}
struct drm_encoder *
exynos_drm_encoder_create(struct drm_device *dev,
struct exynos_drm_manager *manager,
unsigned int possible_crtcs)
{
struct drm_encoder *encoder;
struct exynos_drm_encoder *exynos_encoder;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!manager || !possible_crtcs)
return NULL;
if (!manager->dev)
return NULL;
exynos_encoder = kzalloc(sizeof(*exynos_encoder), GFP_KERNEL);
if (!exynos_encoder) {
DRM_ERROR("failed to allocate encoder\n");
return NULL;
}
exynos_encoder->manager = manager;
encoder = &exynos_encoder->drm_encoder;
encoder->possible_crtcs = possible_crtcs;
DRM_DEBUG_KMS("possible_crtcs = 0x%x\n", encoder->possible_crtcs);
drm_encoder_init(dev, encoder, &exynos_encoder_funcs,
DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(encoder, &exynos_encoder_helper_funcs);
DRM_DEBUG_KMS("encoder has been created\n");
return encoder;
}
struct exynos_drm_manager *exynos_drm_get_manager(struct drm_encoder *encoder)
{
return to_exynos_encoder(encoder)->manager;
}
void exynos_drm_fn_encoder(struct drm_crtc *crtc, void *data,
void (*fn)(struct drm_encoder *, void *))
{
struct drm_device *dev = crtc->dev;
struct drm_encoder *encoder;
struct exynos_drm_private *private = dev->dev_private;
struct exynos_drm_manager *manager;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head) {
if (!encoder->crtc) {
manager = to_exynos_encoder(encoder)->manager;
if (manager->pipe < 0 ||
private->crtc[manager->pipe] != crtc)
continue;
} else {
if (encoder->crtc != crtc)
continue;
}
fn(encoder, data);
}
}
void exynos_drm_enable_vblank(struct drm_encoder *encoder, void *data)
{
struct exynos_drm_manager *manager =
to_exynos_encoder(encoder)->manager;
struct exynos_drm_manager_ops *manager_ops = manager->ops;
int crtc = *(int *)data;
if (manager->pipe == -1)
manager->pipe = crtc;
if (manager_ops->enable_vblank)
manager_ops->enable_vblank(manager->dev);
}
void exynos_drm_disable_vblank(struct drm_encoder *encoder, void *data)
{
struct exynos_drm_manager *manager =
to_exynos_encoder(encoder)->manager;
struct exynos_drm_manager_ops *manager_ops = manager->ops;
int crtc = *(int *)data;
if (manager->pipe == -1)
manager->pipe = crtc;
if (manager_ops->disable_vblank)
manager_ops->disable_vblank(manager->dev);
}
void exynos_drm_encoder_crtc_commit(struct drm_encoder *encoder, void *data)
{
struct exynos_drm_manager *manager =
to_exynos_encoder(encoder)->manager;
struct exynos_drm_overlay_ops *overlay_ops = manager->overlay_ops;
int crtc = *(int *)data;
DRM_DEBUG_KMS("%s\n", __FILE__);
manager->pipe = crtc;
if (overlay_ops && overlay_ops->commit)
overlay_ops->commit(manager->dev);
}
void exynos_drm_encoder_crtc_mode_set(struct drm_encoder *encoder, void *data)
{
struct exynos_drm_manager *manager =
to_exynos_encoder(encoder)->manager;
struct exynos_drm_overlay_ops *overlay_ops = manager->overlay_ops;
struct exynos_drm_overlay *overlay = data;
if (overlay_ops && overlay_ops->mode_set)
overlay_ops->mode_set(manager->dev, overlay);
}
void exynos_drm_encoder_crtc_disable(struct drm_encoder *encoder, void *data)
{
struct exynos_drm_manager *manager =
to_exynos_encoder(encoder)->manager;
struct exynos_drm_overlay_ops *overlay_ops = manager->overlay_ops;
DRM_DEBUG_KMS("\n");
if (overlay_ops && overlay_ops->disable)
overlay_ops->disable(manager->dev);
if (!encoder->crtc)
manager->pipe = -1;
}
