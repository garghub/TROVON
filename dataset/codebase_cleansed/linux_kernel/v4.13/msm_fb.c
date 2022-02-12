static int msm_framebuffer_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
return drm_gem_handle_create(file_priv,
msm_fb->planes[0], handle);
}
static void msm_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
int i, n = fb->format->num_planes;
DBG("destroy: FB ID: %d (%p)", fb->base.id, fb);
drm_framebuffer_cleanup(fb);
for (i = 0; i < n; i++) {
struct drm_gem_object *bo = msm_fb->planes[i];
drm_gem_object_unreference_unlocked(bo);
}
kfree(msm_fb);
}
void msm_framebuffer_describe(struct drm_framebuffer *fb, struct seq_file *m)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
int i, n = fb->format->num_planes;
seq_printf(m, "fb: %dx%d@%4.4s (%2d, ID:%d)\n",
fb->width, fb->height, (char *)&fb->format->format,
drm_framebuffer_read_refcount(fb), fb->base.id);
for (i = 0; i < n; i++) {
seq_printf(m, " %d: offset=%d pitch=%d, obj: ",
i, fb->offsets[i], fb->pitches[i]);
msm_gem_describe(msm_fb->planes[i], m);
}
}
int msm_framebuffer_prepare(struct drm_framebuffer *fb,
struct msm_gem_address_space *aspace)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
int ret, i, n = fb->format->num_planes;
uint64_t iova;
for (i = 0; i < n; i++) {
ret = msm_gem_get_iova(msm_fb->planes[i], aspace, &iova);
DBG("FB[%u]: iova[%d]: %08llx (%d)", fb->base.id, i, iova, ret);
if (ret)
return ret;
}
return 0;
}
void msm_framebuffer_cleanup(struct drm_framebuffer *fb,
struct msm_gem_address_space *aspace)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
int i, n = fb->format->num_planes;
for (i = 0; i < n; i++)
msm_gem_put_iova(msm_fb->planes[i], aspace);
}
uint32_t msm_framebuffer_iova(struct drm_framebuffer *fb,
struct msm_gem_address_space *aspace, int plane)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
if (!msm_fb->planes[plane])
return 0;
return msm_gem_iova(msm_fb->planes[plane], aspace) + fb->offsets[plane];
}
struct drm_gem_object *msm_framebuffer_bo(struct drm_framebuffer *fb, int plane)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
return msm_fb->planes[plane];
}
const struct msm_format *msm_framebuffer_format(struct drm_framebuffer *fb)
{
struct msm_framebuffer *msm_fb = to_msm_framebuffer(fb);
return msm_fb->format;
}
struct drm_framebuffer *msm_framebuffer_create(struct drm_device *dev,
struct drm_file *file, const struct drm_mode_fb_cmd2 *mode_cmd)
{
struct drm_gem_object *bos[4] = {0};
struct drm_framebuffer *fb;
int ret, i, n = drm_format_num_planes(mode_cmd->pixel_format);
for (i = 0; i < n; i++) {
bos[i] = drm_gem_object_lookup(file, mode_cmd->handles[i]);
if (!bos[i]) {
ret = -ENXIO;
goto out_unref;
}
}
fb = msm_framebuffer_init(dev, mode_cmd, bos);
if (IS_ERR(fb)) {
ret = PTR_ERR(fb);
goto out_unref;
}
return fb;
out_unref:
for (i = 0; i < n; i++)
drm_gem_object_unreference_unlocked(bos[i]);
return ERR_PTR(ret);
}
struct drm_framebuffer *msm_framebuffer_init(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *mode_cmd, struct drm_gem_object **bos)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_kms *kms = priv->kms;
struct msm_framebuffer *msm_fb = NULL;
struct drm_framebuffer *fb;
const struct msm_format *format;
int ret, i, n;
unsigned int hsub, vsub;
DBG("create framebuffer: dev=%p, mode_cmd=%p (%dx%d@%4.4s)",
dev, mode_cmd, mode_cmd->width, mode_cmd->height,
(char *)&mode_cmd->pixel_format);
n = drm_format_num_planes(mode_cmd->pixel_format);
hsub = drm_format_horz_chroma_subsampling(mode_cmd->pixel_format);
vsub = drm_format_vert_chroma_subsampling(mode_cmd->pixel_format);
format = kms->funcs->get_format(kms, mode_cmd->pixel_format);
if (!format) {
dev_err(dev->dev, "unsupported pixel format: %4.4s\n",
(char *)&mode_cmd->pixel_format);
ret = -EINVAL;
goto fail;
}
msm_fb = kzalloc(sizeof(*msm_fb), GFP_KERNEL);
if (!msm_fb) {
ret = -ENOMEM;
goto fail;
}
fb = &msm_fb->base;
msm_fb->format = format;
if (n > ARRAY_SIZE(msm_fb->planes)) {
ret = -EINVAL;
goto fail;
}
for (i = 0; i < n; i++) {
unsigned int width = mode_cmd->width / (i ? hsub : 1);
unsigned int height = mode_cmd->height / (i ? vsub : 1);
unsigned int min_size;
min_size = (height - 1) * mode_cmd->pitches[i]
+ width * drm_format_plane_cpp(mode_cmd->pixel_format, i)
+ mode_cmd->offsets[i];
if (bos[i]->size < min_size) {
ret = -EINVAL;
goto fail;
}
msm_fb->planes[i] = bos[i];
}
drm_helper_mode_fill_fb_struct(dev, fb, mode_cmd);
ret = drm_framebuffer_init(dev, fb, &msm_framebuffer_funcs);
if (ret) {
dev_err(dev->dev, "framebuffer init failed: %d\n", ret);
goto fail;
}
DBG("create: FB ID: %d (%p)", fb->base.id, fb);
return fb;
fail:
kfree(msm_fb);
return ERR_PTR(ret);
}
