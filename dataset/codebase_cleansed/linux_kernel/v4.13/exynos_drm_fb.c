static int check_fb_gem_memory_type(struct drm_device *drm_dev,
struct exynos_drm_gem *exynos_gem)
{
unsigned int flags;
if (is_drm_iommu_supported(drm_dev))
return 0;
flags = exynos_gem->flags;
if (IS_NONCONTIG_BUFFER(flags)) {
DRM_ERROR("Non-contiguous GEM memory is not supported.\n");
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
drm_helper_mode_fill_fb_struct(dev, &exynos_fb->fb, mode_cmd);
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
const struct drm_format_info *info = drm_get_format_info(dev, mode_cmd);
struct exynos_drm_gem *exynos_gem[MAX_FB_BUFFER];
struct drm_gem_object *obj;
struct drm_framebuffer *fb;
int i;
int ret;
for (i = 0; i < info->num_planes; i++) {
unsigned int height = (i == 0) ? mode_cmd->height :
DIV_ROUND_UP(mode_cmd->height, info->vsub);
unsigned long size = height * mode_cmd->pitches[i] +
mode_cmd->offsets[i];
obj = drm_gem_object_lookup(file_priv, mode_cmd->handles[i]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
ret = -ENOENT;
goto err;
}
exynos_gem[i] = to_exynos_gem(obj);
if (size > exynos_gem[i]->size) {
i++;
ret = -EINVAL;
goto err;
}
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
if (WARN_ON_ONCE(index >= MAX_FB_BUFFER))
return 0;
return exynos_fb->dma_addr[index];
}
static void exynos_drm_atomic_commit_tail(struct drm_atomic_state *state)
{
struct drm_device *dev = state->dev;
drm_atomic_helper_commit_modeset_disables(dev, state);
drm_atomic_helper_commit_modeset_enables(dev, state);
drm_atomic_helper_commit_planes(dev, state,
DRM_PLANE_COMMIT_ACTIVE_ONLY);
drm_atomic_helper_commit_hw_done(state);
drm_atomic_helper_wait_for_vblanks(dev, state);
drm_atomic_helper_cleanup_planes(dev, state);
}
void exynos_drm_mode_config_init(struct drm_device *dev)
{
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.max_width = 4096;
dev->mode_config.max_height = 4096;
dev->mode_config.funcs = &exynos_drm_mode_config_funcs;
dev->mode_config.helper_private = &exynos_drm_mode_config_helpers;
}
