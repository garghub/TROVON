static void bochs_crtc_dpms(struct drm_crtc *crtc, int mode)
{
switch (mode) {
case DRM_MODE_DPMS_ON:
case DRM_MODE_DPMS_STANDBY:
case DRM_MODE_DPMS_SUSPEND:
case DRM_MODE_DPMS_OFF:
default:
return;
}
}
static int bochs_crtc_mode_set_base(struct drm_crtc *crtc, int x, int y,
struct drm_framebuffer *old_fb)
{
struct bochs_device *bochs =
container_of(crtc, struct bochs_device, crtc);
struct bochs_framebuffer *bochs_fb;
struct bochs_bo *bo;
u64 gpu_addr = 0;
int ret;
if (old_fb) {
bochs_fb = to_bochs_framebuffer(old_fb);
bo = gem_to_bochs_bo(bochs_fb->obj);
ret = ttm_bo_reserve(&bo->bo, true, false, NULL);
if (ret) {
DRM_ERROR("failed to reserve old_fb bo\n");
} else {
bochs_bo_unpin(bo);
ttm_bo_unreserve(&bo->bo);
}
}
if (WARN_ON(crtc->primary->fb == NULL))
return -EINVAL;
bochs_fb = to_bochs_framebuffer(crtc->primary->fb);
bo = gem_to_bochs_bo(bochs_fb->obj);
ret = ttm_bo_reserve(&bo->bo, true, false, NULL);
if (ret)
return ret;
ret = bochs_bo_pin(bo, TTM_PL_FLAG_VRAM, &gpu_addr);
if (ret) {
ttm_bo_unreserve(&bo->bo);
return ret;
}
ttm_bo_unreserve(&bo->bo);
bochs_hw_setbase(bochs, x, y, gpu_addr);
return 0;
}
static int bochs_crtc_mode_set(struct drm_crtc *crtc,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode,
int x, int y, struct drm_framebuffer *old_fb)
{
struct bochs_device *bochs =
container_of(crtc, struct bochs_device, crtc);
bochs_hw_setmode(bochs, mode);
bochs_crtc_mode_set_base(crtc, x, y, old_fb);
return 0;
}
static void bochs_crtc_prepare(struct drm_crtc *crtc)
{
}
static void bochs_crtc_commit(struct drm_crtc *crtc)
{
}
static int bochs_crtc_page_flip(struct drm_crtc *crtc,
struct drm_framebuffer *fb,
struct drm_pending_vblank_event *event,
uint32_t page_flip_flags,
struct drm_modeset_acquire_ctx *ctx)
{
struct bochs_device *bochs =
container_of(crtc, struct bochs_device, crtc);
struct drm_framebuffer *old_fb = crtc->primary->fb;
unsigned long irqflags;
crtc->primary->fb = fb;
bochs_crtc_mode_set_base(crtc, 0, 0, old_fb);
if (event) {
spin_lock_irqsave(&bochs->dev->event_lock, irqflags);
drm_crtc_send_vblank_event(crtc, event);
spin_unlock_irqrestore(&bochs->dev->event_lock, irqflags);
}
return 0;
}
static void bochs_crtc_init(struct drm_device *dev)
{
struct bochs_device *bochs = dev->dev_private;
struct drm_crtc *crtc = &bochs->crtc;
drm_crtc_init(dev, crtc, &bochs_crtc_funcs);
drm_crtc_helper_add(crtc, &bochs_helper_funcs);
}
static void bochs_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void bochs_encoder_dpms(struct drm_encoder *encoder, int state)
{
}
static void bochs_encoder_prepare(struct drm_encoder *encoder)
{
}
static void bochs_encoder_commit(struct drm_encoder *encoder)
{
}
static void bochs_encoder_init(struct drm_device *dev)
{
struct bochs_device *bochs = dev->dev_private;
struct drm_encoder *encoder = &bochs->encoder;
encoder->possible_crtcs = 0x1;
drm_encoder_init(dev, encoder, &bochs_encoder_encoder_funcs,
DRM_MODE_ENCODER_DAC, NULL);
drm_encoder_helper_add(encoder, &bochs_encoder_helper_funcs);
}
static int bochs_connector_get_modes(struct drm_connector *connector)
{
int count;
count = drm_add_modes_noedid(connector, 8192, 8192);
drm_set_preferred_mode(connector, defx, defy);
return count;
}
static int bochs_connector_mode_valid(struct drm_connector *connector,
struct drm_display_mode *mode)
{
struct bochs_device *bochs =
container_of(connector, struct bochs_device, connector);
unsigned long size = mode->hdisplay * mode->vdisplay * 4;
if (size * 2 > bochs->fb_size)
return MODE_BAD;
return MODE_OK;
}
static struct drm_encoder *
bochs_connector_best_encoder(struct drm_connector *connector)
{
int enc_id = connector->encoder_ids[0];
if (enc_id)
return drm_encoder_find(connector->dev, enc_id);
return NULL;
}
static void bochs_connector_init(struct drm_device *dev)
{
struct bochs_device *bochs = dev->dev_private;
struct drm_connector *connector = &bochs->connector;
drm_connector_init(dev, connector, &bochs_connector_connector_funcs,
DRM_MODE_CONNECTOR_VIRTUAL);
drm_connector_helper_add(connector,
&bochs_connector_connector_helper_funcs);
drm_connector_register(connector);
}
int bochs_kms_init(struct bochs_device *bochs)
{
drm_mode_config_init(bochs->dev);
bochs->mode_config_initialized = true;
bochs->dev->mode_config.max_width = 8192;
bochs->dev->mode_config.max_height = 8192;
bochs->dev->mode_config.fb_base = bochs->fb_base;
bochs->dev->mode_config.preferred_depth = 24;
bochs->dev->mode_config.prefer_shadow = 0;
bochs->dev->mode_config.funcs = &bochs_mode_funcs;
bochs_crtc_init(bochs->dev);
bochs_encoder_init(bochs->dev);
bochs_connector_init(bochs->dev);
drm_mode_connector_attach_encoder(&bochs->connector,
&bochs->encoder);
return 0;
}
void bochs_kms_fini(struct bochs_device *bochs)
{
if (bochs->mode_config_initialized) {
drm_mode_config_cleanup(bochs->dev);
bochs->mode_config_initialized = false;
}
}
