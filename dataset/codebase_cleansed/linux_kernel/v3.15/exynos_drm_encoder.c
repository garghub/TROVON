static void exynos_drm_encoder_dpms(struct drm_encoder *encoder, int mode)
{
struct exynos_drm_encoder *exynos_encoder = to_exynos_encoder(encoder);
struct exynos_drm_display *display = exynos_encoder->display;
DRM_DEBUG_KMS("encoder dpms: %d\n", mode);
if (display->ops->dpms)
display->ops->dpms(display, mode);
}
static bool
exynos_drm_encoder_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct drm_device *dev = encoder->dev;
struct exynos_drm_encoder *exynos_encoder = to_exynos_encoder(encoder);
struct exynos_drm_display *display = exynos_encoder->display;
struct drm_connector *connector;
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->encoder != encoder)
continue;
if (display->ops->mode_fixup)
display->ops->mode_fixup(display, connector, mode,
adjusted_mode);
}
return true;
}
static void exynos_drm_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
struct exynos_drm_encoder *exynos_encoder = to_exynos_encoder(encoder);
struct exynos_drm_display *display = exynos_encoder->display;
if (display->ops->mode_set)
display->ops->mode_set(display, adjusted_mode);
}
static void exynos_drm_encoder_prepare(struct drm_encoder *encoder)
{
}
static void exynos_drm_encoder_commit(struct drm_encoder *encoder)
{
struct exynos_drm_encoder *exynos_encoder = to_exynos_encoder(encoder);
struct exynos_drm_display *display = exynos_encoder->display;
if (display->ops->dpms)
display->ops->dpms(display, DRM_MODE_DPMS_ON);
if (display->ops->commit)
display->ops->commit(display);
}
static void exynos_drm_encoder_disable(struct drm_encoder *encoder)
{
struct drm_plane *plane;
struct drm_device *dev = encoder->dev;
exynos_drm_encoder_dpms(encoder, DRM_MODE_DPMS_OFF);
drm_for_each_legacy_plane(plane, &dev->mode_config.plane_list) {
if (plane->crtc == encoder->crtc)
plane->funcs->disable_plane(plane);
}
}
static void exynos_drm_encoder_destroy(struct drm_encoder *encoder)
{
struct exynos_drm_encoder *exynos_encoder = to_exynos_encoder(encoder);
drm_encoder_cleanup(encoder);
kfree(exynos_encoder);
}
static unsigned int exynos_drm_encoder_clones(struct drm_encoder *encoder)
{
struct drm_encoder *clone;
struct drm_device *dev = encoder->dev;
struct exynos_drm_encoder *exynos_encoder = to_exynos_encoder(encoder);
struct exynos_drm_display *display = exynos_encoder->display;
unsigned int clone_mask = 0;
int cnt = 0;
list_for_each_entry(clone, &dev->mode_config.encoder_list, head) {
switch (display->type) {
case EXYNOS_DISPLAY_TYPE_LCD:
case EXYNOS_DISPLAY_TYPE_HDMI:
case EXYNOS_DISPLAY_TYPE_VIDI:
clone_mask |= (1 << (cnt++));
break;
default:
continue;
}
}
return clone_mask;
}
void exynos_drm_encoder_setup(struct drm_device *dev)
{
struct drm_encoder *encoder;
list_for_each_entry(encoder, &dev->mode_config.encoder_list, head)
encoder->possible_clones = exynos_drm_encoder_clones(encoder);
}
struct drm_encoder *
exynos_drm_encoder_create(struct drm_device *dev,
struct exynos_drm_display *display,
unsigned long possible_crtcs)
{
struct drm_encoder *encoder;
struct exynos_drm_encoder *exynos_encoder;
if (!possible_crtcs)
return NULL;
exynos_encoder = kzalloc(sizeof(*exynos_encoder), GFP_KERNEL);
if (!exynos_encoder)
return NULL;
exynos_encoder->display = display;
encoder = &exynos_encoder->drm_encoder;
encoder->possible_crtcs = possible_crtcs;
DRM_DEBUG_KMS("possible_crtcs = 0x%x\n", encoder->possible_crtcs);
drm_encoder_init(dev, encoder, &exynos_encoder_funcs,
DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(encoder, &exynos_encoder_helper_funcs);
DRM_DEBUG_KMS("encoder has been created\n");
return encoder;
}
struct exynos_drm_display *exynos_drm_get_display(struct drm_encoder *encoder)
{
return to_exynos_encoder(encoder)->display;
}
