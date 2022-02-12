static int check_fb_gem_memory_type(struct drm_device *drm_dev,
struct exynos_drm_gem *exynos_gem)
{
unsigned int flags;
if (is_drm_iommu_supported(drm_dev))
return 0;
flags = exynos_gem->flags;
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
drm_framebuffer_cleanup(fb);
for (i = 0; i < ARRAY_SIZE(exynos_fb->exynos_gem); i++) {
struct drm_gem_object *obj;
if (exynos_fb->exynos_gem[i] == NULL)
continue;
obj = &exynos_fb->exynos_gem[i]->base;
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
return drm_gem_handle_create(file_priv,
&exynos_fb->exynos_gem[0]->base, handle);
}
static int exynos_drm_fb_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv, unsigned flags,
unsigned color, struct drm_clip_rect *clips,
unsigned num_clips)
{
return 0;
}
struct drm_framebuffer *
exynos_drm_framebuffer_init(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *mode_cmd,
struct exynos_drm_gem **exynos_gem,
int count)
{
struct exynos_drm_fb *exynos_fb;
int i;
int ret;
exynos_fb = kzalloc(sizeof(*exynos_fb), GFP_KERNEL);
if (!exynos_fb)
return ERR_PTR(-ENOMEM);
for (i = 0; i < count; i++) {
ret = check_fb_gem_memory_type(dev, exynos_gem[i]);
if (ret < 0)
goto err;
exynos_fb->exynos_gem[i] = exynos_gem[i];
exynos_fb->dma_addr[i] = exynos_gem[i]->dma_addr
+ mode_cmd->offsets[i];
}
drm_helper_mode_fill_fb_struct(&exynos_fb->fb, mode_cmd);
ret = drm_framebuffer_init(dev, &exynos_fb->fb, &exynos_drm_fb_funcs);
if (ret < 0) {
DRM_ERROR("failed to initialize framebuffer\n");
goto err;
}
return &exynos_fb->fb;
err:
kfree(exynos_fb);
return ERR_PTR(ret);
}
static struct drm_framebuffer *
exynos_user_fb_create(struct drm_device *dev, struct drm_file *file_priv,
const struct drm_mode_fb_cmd2 *mode_cmd)
{
struct exynos_drm_gem *exynos_gem[MAX_FB_BUFFER];
struct drm_gem_object *obj;
struct drm_framebuffer *fb;
int i;
int ret;
for (i = 0; i < drm_format_num_planes(mode_cmd->pixel_format); i++) {
obj = drm_gem_object_lookup(dev, file_priv,
mode_cmd->handles[i]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
ret = -ENOENT;
goto err;
}
exynos_gem[i] = to_exynos_gem(obj);
}
fb = exynos_drm_framebuffer_init(dev, mode_cmd, exynos_gem, i);
if (IS_ERR(fb)) {
ret = PTR_ERR(fb);
goto err;
}
return fb;
err:
while (i--)
drm_gem_object_unreference_unlocked(&exynos_gem[i]->base);
return ERR_PTR(ret);
}
dma_addr_t exynos_drm_fb_dma_addr(struct drm_framebuffer *fb, int index)
{
struct exynos_drm_fb *exynos_fb = to_exynos_fb(fb);
if (index >= MAX_FB_BUFFER)
return DMA_ERROR_CODE;
return exynos_fb->dma_addr[index];
}
void exynos_drm_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = 4096;
dev->mode_config.max_height = 4096;
dev->mode_config.funcs = &exynos_drm_mode_config_funcs;
}
