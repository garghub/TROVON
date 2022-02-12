uint32_t drm_color_lut_extract(uint32_t user_input, uint32_t bit_precision)
{
uint32_t val = user_input;
uint32_t max = 0xffff >> (16 - bit_precision);
if (bit_precision < 16) {
val += 1UL << (16 - bit_precision - 1);
val >>= 16 - bit_precision;
}
return clamp_val(val, 0, max);
}
void drm_crtc_enable_color_mgmt(struct drm_crtc *crtc,
uint degamma_lut_size,
bool has_ctm,
uint gamma_lut_size)
{
struct drm_device *dev = crtc->dev;
struct drm_mode_config *config = &dev->mode_config;
if (degamma_lut_size) {
drm_object_attach_property(&crtc->base,
config->degamma_lut_property, 0);
drm_object_attach_property(&crtc->base,
config->degamma_lut_size_property,
degamma_lut_size);
}
if (has_ctm)
drm_object_attach_property(&crtc->base,
config->ctm_property, 0);
if (gamma_lut_size) {
drm_object_attach_property(&crtc->base,
config->gamma_lut_property, 0);
drm_object_attach_property(&crtc->base,
config->gamma_lut_size_property,
gamma_lut_size);
}
}
int drm_mode_crtc_set_gamma_size(struct drm_crtc *crtc,
int gamma_size)
{
uint16_t *r_base, *g_base, *b_base;
int i;
crtc->gamma_size = gamma_size;
crtc->gamma_store = kcalloc(gamma_size, sizeof(uint16_t) * 3,
GFP_KERNEL);
if (!crtc->gamma_store) {
crtc->gamma_size = 0;
return -ENOMEM;
}
r_base = crtc->gamma_store;
g_base = r_base + gamma_size;
b_base = g_base + gamma_size;
for (i = 0; i < gamma_size; i++) {
r_base[i] = i << 8;
g_base[i] = i << 8;
b_base[i] = i << 8;
}
return 0;
}
int drm_mode_gamma_set_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_crtc_lut *crtc_lut = data;
struct drm_crtc *crtc;
void *r_base, *g_base, *b_base;
int size;
struct drm_modeset_acquire_ctx ctx;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
crtc = drm_crtc_find(dev, crtc_lut->crtc_id);
if (!crtc)
return -ENOENT;
if (crtc->funcs->gamma_set == NULL)
return -ENOSYS;
if (crtc_lut->gamma_size != crtc->gamma_size)
return -EINVAL;
drm_modeset_acquire_init(&ctx, 0);
retry:
ret = drm_modeset_lock_all_ctx(dev, &ctx);
if (ret)
goto out;
size = crtc_lut->gamma_size * (sizeof(uint16_t));
r_base = crtc->gamma_store;
if (copy_from_user(r_base, (void __user *)(unsigned long)crtc_lut->red, size)) {
ret = -EFAULT;
goto out;
}
g_base = r_base + size;
if (copy_from_user(g_base, (void __user *)(unsigned long)crtc_lut->green, size)) {
ret = -EFAULT;
goto out;
}
b_base = g_base + size;
if (copy_from_user(b_base, (void __user *)(unsigned long)crtc_lut->blue, size)) {
ret = -EFAULT;
goto out;
}
ret = crtc->funcs->gamma_set(crtc, r_base, g_base, b_base,
crtc->gamma_size, &ctx);
out:
if (ret == -EDEADLK) {
drm_modeset_backoff(&ctx);
goto retry;
}
drm_modeset_drop_locks(&ctx);
drm_modeset_acquire_fini(&ctx);
return ret;
}
int drm_mode_gamma_get_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_crtc_lut *crtc_lut = data;
struct drm_crtc *crtc;
void *r_base, *g_base, *b_base;
int size;
int ret = 0;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
return -EINVAL;
crtc = drm_crtc_find(dev, crtc_lut->crtc_id);
if (!crtc)
return -ENOENT;
if (crtc_lut->gamma_size != crtc->gamma_size)
return -EINVAL;
drm_modeset_lock(&crtc->mutex, NULL);
size = crtc_lut->gamma_size * (sizeof(uint16_t));
r_base = crtc->gamma_store;
if (copy_to_user((void __user *)(unsigned long)crtc_lut->red, r_base, size)) {
ret = -EFAULT;
goto out;
}
g_base = r_base + size;
if (copy_to_user((void __user *)(unsigned long)crtc_lut->green, g_base, size)) {
ret = -EFAULT;
goto out;
}
b_base = g_base + size;
if (copy_to_user((void __user *)(unsigned long)crtc_lut->blue, b_base, size)) {
ret = -EFAULT;
goto out;
}
out:
drm_modeset_unlock(&crtc->mutex);
return ret;
}
