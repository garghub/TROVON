static int check_fb_gem_memory_type(struct drm_device *drm_dev,
struct exynos_drm_gem_obj *exynos_gem_obj)
{
unsigned int flags;
if (is_drm_iommu_supported(drm_dev))
return 0;
flags = exynos_gem_obj->flags;
if (IS_NONCONTIG_BUFFER(flags)) {
DRM_ERROR("cannot use this gem memory type for fb.\n");
return -EINVAL;
}
return 0;
}
static void exynos_drm_fb_destroy(struct drm_framebuffer *fb)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
unsigned int i;
exynos_drm_crtc_complete_scanout(fb);
drm_framebuffer_cleanup(fb);
for (i = 0; i < ARRAY_SIZE(exynos_fb->exynos_gem_obj); i++) {
struct drm_gem_object *obj;
if (exynos_fb->exynos_gem_obj[i] == NULL)
continue;
obj = &exynos_fb->exynos_gem_obj[i]->base;
drm_gem_object_unreference_unlocked(obj);
}
kfree(exynos_fb);
exynos_fb = NULL;
}
static int exynos_drm_fb_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
if (WARN_ON(exynos_fb->buf_cnt != 1))
return -EINVAL;
return drm_gem_handle_create(file_priv,
&exynos_fb->exynos_gem_obj[0]->base, handle);
}
static int exynos_drm_fb_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv, unsigned flags,
unsigned color, struct drm_clip_rect *clips,
unsigned num_clips)
{
return 0;
}
void exynos_drm_fb_set_buf_cnt(struct drm_framebuffer *fb,
unsigned int cnt)
{
struct exynos_drm_fb *exynos_fb;
exynos_fb = to_exynos_fb(fb);
exynos_fb->buf_cnt = cnt;
}
unsigned int exynos_drm_fb_get_buf_cnt(struct drm_framebuffer *fb)
{
struct exynos_drm_fb *exynos_fb;
exynos_fb = to_exynos_fb(fb);
return exynos_fb->buf_cnt;
}
struct drm_framebuffer *
exynos_drm_framebuffer_init(struct drm_device *dev,
struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_object *obj)
{
struct exynos_drm_fb *exynos_fb;
struct exynos_drm_gem_obj *exynos_gem_obj;
int ret;
exynos_gem_obj = to_exynos_gem_obj(obj);
ret = check_fb_gem_memory_type(dev, exynos_gem_obj);
if (ret < 0)
return ERR_PTR(ret);
exynos_fb = kzalloc(sizeof(*exynos_fb), GFP_KERNEL);
if (!exynos_fb)
return ERR_PTR(-ENOMEM);
drm_helper_mode_fill_fb_struct(&exynos_fb->fb, mode_cmd);
exynos_fb->exynos_gem_obj[0] = exynos_gem_obj;
ret = drm_framebuffer_init(dev, &exynos_fb->fb, &exynos_drm_fb_funcs);
if (ret) {
kfree(exynos_fb);
DRM_ERROR("failed to initialize framebuffer\n");
return ERR_PTR(ret);
}
return &exynos_fb->fb;
}
static struct drm_framebuffer *
exynos_user_fb_create(struct drm_device *dev, struct drm_file *file_priv,
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *obj;
struct exynos_drm_gem_obj *exynos_gem_obj;
struct exynos_drm_fb *exynos_fb;
int i, ret;
exynos_fb = kzalloc(sizeof(*exynos_fb), GFP_KERNEL);
if (!exynos_fb)
return ERR_PTR(-ENOMEM);
obj = drm_gem_object_lookup(dev, file_priv, mode_cmd->handles[0]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
ret = -ENOENT;
goto err_free;
}
drm_helper_mode_fill_fb_struct(&exynos_fb->fb, mode_cmd);
exynos_fb->exynos_gem_obj[0] = to_exynos_gem_obj(obj);
exynos_fb->buf_cnt = drm_format_num_planes(mode_cmd->pixel_format);
DRM_DEBUG_KMS("buf_cnt = %d\n", exynos_fb->buf_cnt);
for (i = 1; i < exynos_fb->buf_cnt; i++) {
obj = drm_gem_object_lookup(dev, file_priv,
mode_cmd->handles[i]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
ret = -ENOENT;
exynos_fb->buf_cnt = i;
goto err_unreference;
}
exynos_gem_obj = to_exynos_gem_obj(obj);
exynos_fb->exynos_gem_obj[i] = exynos_gem_obj;
ret = check_fb_gem_memory_type(dev, exynos_gem_obj);
if (ret < 0)
goto err_unreference;
}
ret = drm_framebuffer_init(dev, &exynos_fb->fb, &exynos_drm_fb_funcs);
if (ret) {
DRM_ERROR("failed to init framebuffer.\n");
goto err_unreference;
}
return &exynos_fb->fb;
err_unreference:
for (i = 0; i < exynos_fb->buf_cnt; i++) {
struct drm_gem_object *obj;
obj = &exynos_fb->exynos_gem_obj[i]->base;
if (obj)
drm_gem_object_unreference_unlocked(obj);
}
err_free:
kfree(exynos_fb);
return ERR_PTR(ret);
}
struct exynos_drm_gem_buf *exynos_drm_fb_buffer(struct drm_framebuffer *fb,
int index)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
struct exynos_drm_gem_buf *buffer;
if (index >= MAX_FB_BUFFER)
return NULL;
buffer = exynos_fb->exynos_gem_obj[index]->buffer;
if (!buffer)
return NULL;
DRM_DEBUG_KMS("dma_addr = 0x%lx\n", (unsigned long)buffer->dma_addr);
return buffer;
}
static void exynos_drm_output_poll_changed(struct drm_device *dev)
{
struct exynos_drm_private *private = dev->dev_private;
struct drm_fb_helper *fb_helper = private->fb_helper;
if (fb_helper)
drm_fb_helper_hotplug_event(fb_helper);
else
exynos_drm_fbdev_init(dev);
}
static int exynos_atomic_commit(struct drm_device *dev,
struct drm_atomic_state *state,
bool async)
{
int ret;
ret = drm_atomic_helper_prepare_planes(dev, state);
if (ret)
return ret;
drm_atomic_helper_swap_state(dev, state);
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_modeset_enables(dev, state);
drm_atomic_helper_commit_planes(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
drm_atomic_state_free(state);
return 0;
}
void exynos_drm_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = 4096;
dev->mode_config.max_height = 4096;
dev->mode_config.funcs = &exynos_drm_mode_config_funcs;
}
