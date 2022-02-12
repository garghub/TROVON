static void exynos_drm_fb_destroy(struct drm_framebuffer *fb)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
DRM_DEBUG_KMS("%s\n", __FILE__);
drm_framebuffer_cleanup(fb);
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
&exynos_fb->exynos_gem_obj[0]->base, handle);
}
static int exynos_drm_fb_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv, unsigned flags,
unsigned color, struct drm_clip_rect *clips,
unsigned num_clips)
{
DRM_DEBUG_KMS("%s\n", __FILE__);
return 0;
}
struct drm_framebuffer *
exynos_drm_framebuffer_init(struct drm_device *dev,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_object *obj)
{
struct exynos_drm_fb *exynos_fb;
int ret;
exynos_fb = kzalloc(sizeof(*exynos_fb), GFP_KERNEL);
if (!exynos_fb) {
DRM_ERROR("failed to allocate exynos drm framebuffer\n");
return ERR_PTR(-ENOMEM);
}
ret = drm_framebuffer_init(dev, &exynos_fb->fb, &exynos_drm_fb_funcs);
if (ret) {
DRM_ERROR("failed to initialize framebuffer\n");
return ERR_PTR(ret);
}
drm_helper_mode_fill_fb_struct(&exynos_fb->fb, mode_cmd);
exynos_fb->exynos_gem_obj[0] = to_exynos_gem_obj(obj);
return &exynos_fb->fb;
}
static struct drm_framebuffer *
exynos_user_fb_create(struct drm_device *dev, struct drm_file *file_priv,
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *obj;
struct drm_framebuffer *fb;
struct exynos_drm_fb *exynos_fb;
int nr;
int i;
DRM_DEBUG_KMS("%s\n", __FILE__);
obj = drm_gem_object_lookup(dev, file_priv, mode_cmd->handles[0]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
return ERR_PTR(-ENOENT);
}
drm_gem_object_unreference_unlocked(obj);
fb = exynos_drm_framebuffer_init(dev, mode_cmd, obj);
if (IS_ERR(fb))
return fb;
exynos_fb = to_exynos_fb(fb);
nr = exynos_drm_format_num_buffers(fb->pixel_format);
for (i = 1; i < nr; i++) {
obj = drm_gem_object_lookup(dev, file_priv,
mode_cmd->handles[i]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
exynos_drm_fb_destroy(fb);
return ERR_PTR(-ENOENT);
}
drm_gem_object_unreference_unlocked(obj);
exynos_fb->exynos_gem_obj[i] = to_exynos_gem_obj(obj);
}
return fb;
}
struct exynos_drm_gem_buf *exynos_drm_fb_buffer(struct drm_framebuffer *fb,
int index)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
struct exynos_drm_gem_buf *buffer;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (index >= MAX_FB_BUFFER)
return NULL;
buffer = exynos_fb->exynos_gem_obj[index]->buffer;
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
