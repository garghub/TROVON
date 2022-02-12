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
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_drm_encoder_complete_scanout(fb);
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
if (ret < 0) {
DRM_ERROR("cannot use this gem memory type for fb.\n");
return ERR_PTR(-EINVAL);
}
exynos_fb = kzalloc(sizeof(*exynos_fb), GFP_KERNEL);
if (!exynos_fb) {
DRM_ERROR("failed to allocate exynos drm framebuffer\n");
return ERR_PTR(-ENOMEM);
}
drm_helper_mode_fill_fb_struct(&exynos_fb->fb, mode_cmd);
exynos_fb->exynos_gem_obj[0] = exynos_gem_obj;
ret = drm_framebuffer_init(dev, &exynos_fb->fb, &exynos_drm_fb_funcs);
if (ret) {
DRM_ERROR("failed to initialize framebuffer\n");
return ERR_PTR(ret);
}
return &exynos_fb->fb;
}
static u32 exynos_drm_format_num_buffers(struct drm_mode_fb_cmd2 *mode_cmd)
{
unsigned int cnt = 0;
if (mode_cmd->pixel_format != DRM_FORMAT_NV12)
return drm_format_num_planes(mode_cmd->pixel_format);
while (cnt != MAX_FB_BUFFER) {
if (!mode_cmd->handles[cnt])
break;
cnt++;
}
if (cnt == 2) {
if (mode_cmd->offsets[1] &&
mode_cmd->handles[0] == mode_cmd->handles[1])
cnt = 1;
}
return cnt;
}
static struct drm_framebuffer *
exynos_user_fb_create(struct drm_device *dev, struct drm_file *file_priv,
struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *obj;
struct exynos_drm_fb *exynos_fb;
int i, ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
obj = drm_gem_object_lookup(dev, file_priv, mode_cmd->handles[0]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
return ERR_PTR(-ENOENT);
}
exynos_fb = kzalloc(sizeof(*exynos_fb), GFP_KERNEL);
if (!exynos_fb) {
DRM_ERROR("failed to allocate exynos drm framebuffer\n");
return ERR_PTR(-ENOMEM);
}
drm_helper_mode_fill_fb_struct(&exynos_fb->fb, mode_cmd);
exynos_fb->exynos_gem_obj[0] = to_exynos_gem_obj(obj);
exynos_fb->buf_cnt = exynos_drm_format_num_buffers(mode_cmd);
DRM_DEBUG_KMS("buf_cnt = %d\n", exynos_fb->buf_cnt);
for (i = 1; i < exynos_fb->buf_cnt; i++) {
struct exynos_drm_gem_obj *exynos_gem_obj;
int ret;
obj = drm_gem_object_lookup(dev, file_priv,
mode_cmd->handles[i]);
if (!obj) {
DRM_ERROR("failed to lookup gem object\n");
kfree(exynos_fb);
return ERR_PTR(-ENOENT);
}
exynos_gem_obj = to_exynos_gem_obj(obj);
ret = check_fb_gem_memory_type(dev, exynos_gem_obj);
if (ret < 0) {
DRM_ERROR("cannot use this gem memory type for fb.\n");
kfree(exynos_fb);
return ERR_PTR(ret);
}
exynos_fb->exynos_gem_obj[i] = to_exynos_gem_obj(obj);
}
ret = drm_framebuffer_init(dev, &exynos_fb->fb, &exynos_drm_fb_funcs);
if (ret) {
for (i = 0; i < exynos_fb->buf_cnt; i++) {
struct exynos_drm_gem_obj *gem_obj;
gem_obj = exynos_fb->exynos_gem_obj[i];
drm_gem_object_unreference_unlocked(&gem_obj->base);
}
kfree(exynos_fb);
return ERR_PTR(ret);
}
return &exynos_fb->fb;
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
DRM_DEBUG_KMS("dma_addr = 0x%lx\n", (unsigned long)buffer->dma_addr);
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
