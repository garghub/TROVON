static void udl_enc_destroy(struct drm_encoder *encoder)
{
drm_encoder_cleanup(encoder);
kfree(encoder);
}
static void udl_encoder_disable(struct drm_encoder *encoder)
{
}
static bool udl_mode_fixup(struct drm_encoder *encoder,
const struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
return true;
}
static void udl_encoder_prepare(struct drm_encoder *encoder)
{
}
static void udl_encoder_commit(struct drm_encoder *encoder)
{
}
static void udl_encoder_mode_set(struct drm_encoder *encoder,
struct drm_display_mode *mode,
struct drm_display_mode *adjusted_mode)
{
}
static void
udl_encoder_dpms(struct drm_encoder *encoder, int mode)
{
}
struct drm_encoder *udl_encoder_init(struct drm_device *dev)
{
struct drm_encoder *encoder;
encoder = kzalloc(sizeof(struct drm_encoder), GFP_KERNEL);
if (!encoder)
return NULL;
drm_encoder_init(dev, encoder, &udl_enc_funcs, DRM_MODE_ENCODER_TMDS);
drm_encoder_helper_add(encoder, &udl_helper_funcs);
encoder->possible_crtcs = 1;
return encoder;
}
