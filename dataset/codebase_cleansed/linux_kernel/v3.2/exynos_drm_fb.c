static void exynos_drm_fb_destroy(struct drm_framebuffer *fb)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
DRM_DEBUG_KMS("%s\n", __FILE__);
drm_framebuffer_cleanup(fb);
if (!exynos_fb->exynos_gem_obj && exynos_fb->buffer)
exynos_drm_buf_destroy(fb->dev, exynos_fb->buffer);
kfree(exynos_fb);
exynos_fb = NULL;
}
static int exynos_drm_fb_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
DRM_DEBUG_KMS("%s\n", __FILE__);
return drm_gem_handle_create(file_priv,
&exynos_fb->exynos_gem_obj->base, handle);
}
static int exynos_drm_fb_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv, unsigned flags,
unsigned color, struct drm_clip_rect *clips,
unsigned num_clips)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
static struct drm_framebuffer *
exynos_drm_fb_init(struct drm_file *file_priv, struct drm_device *dev,
struct drm_mode_fb_cmd *mode_cmd)
{
struct exynos_drm_fb *exynos_fb;
struct drm_framebuffer *fb;
struct exynos_drm_gem_obj *exynos_gem_obj = NULL;
struct drm_gem_object *obj;
unsigned int size;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
mode_cmd->pitch = max(mode_cmd->pitch,
mode_cmd->width * (mode_cmd->bpp >> 3));
DRM_LOG_KMS("drm fb create(%dx%d)\n",
mode_cmd->width, mode_cmd->height);
exynos_fb = kzalloc(sizeof(*exynos_fb), GFP_KERNEL);
if (!exynos_fb) {
DRM_ERROR("failed to allocate exynos drm framebuffer.\n");
return ERR_PTR(-ENOMEM);
}
fb = &exynos_fb->fb;
ret = drm_framebuffer_init(dev, fb, &exynos_drm_fb_funcs);
if (ret) {
DRM_ERROR("failed to initialize framebuffer.\n");
goto err_init;
}
DRM_LOG_KMS("create: fb id: %d\n", fb->base.id);
size = mode_cmd->pitch * mode_cmd->height;
if (!mode_cmd->handle) {
if (!file_priv) {
struct exynos_drm_gem_buf *buffer;
buffer = exynos_drm_buf_create(dev, size);
if (IS_ERR(buffer)) {
ret = PTR_ERR(buffer);
goto err_buffer;
}
exynos_fb->buffer = buffer;
DRM_LOG_KMS("default: dma_addr = 0x%lx, size = 0x%x\n",
(unsigned long)buffer->dma_addr, size);
goto out;
} else {
exynos_gem_obj = exynos_drm_gem_create(dev, file_priv,
&mode_cmd->handle,
size);
if (IS_ERR(exynos_gem_obj)) {
ret = PTR_ERR(exynos_gem_obj);
goto err_buffer;
}
}
} else {
obj = drm_gem_object_lookup(dev, file_priv, mode_cmd->handle);
if (!obj) {
DRM_ERROR("failed to lookup gem object.\n");
goto err_buffer;
}
exynos_gem_obj = to_exynos_gem_obj(obj);
drm_gem_object_unreference_unlocked(obj);
}
exynos_fb->buffer = exynos_gem_obj->buffer;
DRM_LOG_KMS("dma_addr = 0x%lx, size = 0x%x, gem object = 0x%x\n",
(unsigned long)exynos_fb->buffer->dma_addr, size,
(unsigned int)&exynos_gem_obj->base);
out:
exynos_fb->exynos_gem_obj = exynos_gem_obj;
drm_helper_mode_fill_fb_struct(fb, mode_cmd);
return fb;
err_buffer:
drm_framebuffer_cleanup(fb);
err_init:
kfree(exynos_fb);
return ERR_PTR(ret);
}
struct drm_framebuffer *exynos_drm_fb_create(struct drm_device *dev,
struct drm_file *file_priv,
struct drm_mode_fb_cmd *mode_cmd)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return exynos_drm_fb_init(file_priv, dev, mode_cmd);
}
struct exynos_drm_gem_buf *exynos_drm_fb_get_buf(struct drm_framebuffer *fb)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
struct exynos_drm_gem_buf *buffer;
DRM_DEBUG_KMS("%s\n", __FILE__);
buffer = exynos_fb->buffer;
if (!buffer)
return NULL;
DRM_DEBUG_KMS("vaddr = 0x%lx, dma_addr = 0x%lx\n",
(unsigned long)buffer->kvaddr,
(unsigned long)buffer->dma_addr);
return buffer;
}
static void exynos_drm_output_poll_changed(struct drm_device *dev)
{
struct exynos_drm_private *private = dev->dev_private;
struct drm_fb_helper *fb_helper = private->fb_helper;
if (fb_helper)
drm_fb_helper_hotplug_event(fb_helper);
}
void exynos_drm_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = 4096;
dev->mode_config.max_height = 4096;
dev->mode_config.funcs = &exynos_drm_mode_config_funcs;
}
