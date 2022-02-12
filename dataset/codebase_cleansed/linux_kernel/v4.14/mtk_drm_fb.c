struct drm_gem_object *mtk_fb_get_gem_obj(struct drm_framebuffer *fb)
{
struct mtk_drm_fb *mtk_fb = to_mtk_fb(fb);
return mtk_fb->gem_obj;
}
static int mtk_drm_fb_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct mtk_drm_fb *mtk_fb = to_mtk_fb(fb);
return drm_gem_handle_create(file_priv, mtk_fb->gem_obj, handle);
}
static void mtk_drm_fb_destroy(struct drm_framebuffer *fb)
{
struct mtk_drm_fb *mtk_fb = to_mtk_fb(fb);
drm_framebuffer_cleanup(fb);
drm_gem_object_put_unlocked(mtk_fb->gem_obj);
kfree(mtk_fb);
}
static struct mtk_drm_fb *mtk_drm_framebuffer_init(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *mode,
struct drm_gem_object *obj)
{
struct mtk_drm_fb *mtk_fb;
int ret;
if (drm_format_num_planes(mode->pixel_format) != 1)
return ERR_PTR(-EINVAL);
mtk_fb = kzalloc(sizeof(*mtk_fb), GFP_KERNEL);
if (!mtk_fb)
return ERR_PTR(-ENOMEM);
drm_helper_mode_fill_fb_struct(dev, &mtk_fb->base, mode);
mtk_fb->gem_obj = obj;
ret = drm_framebuffer_init(dev, &mtk_fb->base, &mtk_drm_fb_funcs);
if (ret) {
DRM_ERROR("failed to initialize framebuffer\n");
kfree(mtk_fb);
return ERR_PTR(ret);
}
return mtk_fb;
}
int mtk_fb_wait(struct drm_framebuffer *fb)
{
struct drm_gem_object *gem;
struct reservation_object *resv;
long ret;
if (!fb)
return 0;
gem = mtk_fb_get_gem_obj(fb);
if (!gem || !gem->dma_buf || !gem->dma_buf->resv)
return 0;
resv = gem->dma_buf->resv;
ret = reservation_object_wait_timeout_rcu(resv, false, true,
MAX_SCHEDULE_TIMEOUT);
if (WARN_ON(ret < 0))
return ret;
return 0;
}
struct drm_framebuffer *mtk_drm_mode_fb_create(struct drm_device *dev,
struct drm_file *file,
const struct drm_mode_fb_cmd2 *cmd)
{
struct mtk_drm_fb *mtk_fb;
struct drm_gem_object *gem;
unsigned int width = cmd->width;
unsigned int height = cmd->height;
unsigned int size, bpp;
int ret;
if (drm_format_num_planes(cmd->pixel_format) != 1)
return ERR_PTR(-EINVAL);
gem = drm_gem_object_lookup(file, cmd->handles[0]);
if (!gem)
return ERR_PTR(-ENOENT);
bpp = drm_format_plane_cpp(cmd->pixel_format, 0);
size = (height - 1) * cmd->pitches[0] + width * bpp;
size += cmd->offsets[0];
if (gem->size < size) {
ret = -EINVAL;
goto unreference;
}
mtk_fb = mtk_drm_framebuffer_init(dev, cmd, gem);
if (IS_ERR(mtk_fb)) {
ret = PTR_ERR(mtk_fb);
goto unreference;
}
return &mtk_fb->base;
unreference:
drm_gem_object_put_unlocked(gem);
return ERR_PTR(ret);
}
