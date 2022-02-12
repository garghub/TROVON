struct drm_gem_object *drm_gem_fb_get_obj(struct drm_framebuffer *fb,
unsigned int plane)
{
if (plane >= 4)
return NULL;
return fb->obj[plane];
}
static struct drm_framebuffer *
drm_gem_fb_alloc(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_object **obj, unsigned int num_planes,
const struct drm_framebuffer_funcs *funcs)
{
struct drm_framebuffer *fb;
int ret, i;
fb = kzalloc(sizeof(*fb), GFP_KERNEL);
if (!fb)
return ERR_PTR(-ENOMEM);
drm_helper_mode_fill_fb_struct(dev, fb, mode_cmd);
for (i = 0; i < num_planes; i++)
fb->obj[i] = obj[i];
ret = drm_framebuffer_init(dev, fb, funcs);
if (ret) {
DRM_DEV_ERROR(dev->dev, "Failed to init framebuffer: %d\n",
ret);
kfree(fb);
return ERR_PTR(ret);
}
return fb;
}
void drm_gem_fb_destroy(struct drm_framebuffer *fb)
{
int i;
for (i = 0; i < 4; i++)
drm_gem_object_put_unlocked(fb->obj[i]);
drm_framebuffer_cleanup(fb);
kfree(fb);
}
int drm_gem_fb_create_handle(struct drm_framebuffer *fb, struct drm_file *file,
unsigned int *handle)
{
return drm_gem_handle_create(file, fb->obj[0], handle);
}
struct drm_framebuffer *
drm_gem_fb_create_with_funcs(struct drm_device *dev, struct drm_file *file,
const struct drm_mode_fb_cmd2 *mode_cmd,
const struct drm_framebuffer_funcs *funcs)
{
const struct drm_format_info *info;
struct drm_gem_object *objs[4];
struct drm_framebuffer *fb;
int ret, i;
info = drm_get_format_info(dev, mode_cmd);
if (!info)
return ERR_PTR(-EINVAL);
for (i = 0; i < info->num_planes; i++) {
unsigned int width = mode_cmd->width / (i ? info->hsub : 1);
unsigned int height = mode_cmd->height / (i ? info->vsub : 1);
unsigned int min_size;
objs[i] = drm_gem_object_lookup(file, mode_cmd->handles[i]);
if (!objs[i]) {
DRM_DEV_ERROR(dev->dev, "Failed to lookup GEM\n");
ret = -ENOENT;
goto err_gem_object_put;
}
min_size = (height - 1) * mode_cmd->pitches[i]
+ width * info->cpp[i]
+ mode_cmd->offsets[i];
if (objs[i]->size < min_size) {
drm_gem_object_put_unlocked(objs[i]);
ret = -EINVAL;
goto err_gem_object_put;
}
}
fb = drm_gem_fb_alloc(dev, mode_cmd, objs, i, funcs);
if (IS_ERR(fb)) {
ret = PTR_ERR(fb);
goto err_gem_object_put;
}
return fb;
err_gem_object_put:
for (i--; i >= 0; i--)
drm_gem_object_put_unlocked(objs[i]);
return ERR_PTR(ret);
}
struct drm_framebuffer *
drm_gem_fb_create(struct drm_device *dev, struct drm_file *file,
const struct drm_mode_fb_cmd2 *mode_cmd)
{
return drm_gem_fb_create_with_funcs(dev, file, mode_cmd,
&drm_gem_fb_funcs);
}
int drm_gem_fb_prepare_fb(struct drm_plane *plane,
struct drm_plane_state *state)
{
struct dma_buf *dma_buf;
struct dma_fence *fence;
if ((plane->state->fb == state->fb) || !state->fb)
return 0;
dma_buf = drm_gem_fb_get_obj(state->fb, 0)->dma_buf;
if (dma_buf) {
fence = reservation_object_get_excl_rcu(dma_buf->resv);
drm_atomic_set_fence_for_plane(state, fence);
}
return 0;
}
struct drm_framebuffer *
drm_gem_fbdev_fb_create(struct drm_device *dev,
struct drm_fb_helper_surface_size *sizes,
unsigned int pitch_align, struct drm_gem_object *obj,
const struct drm_framebuffer_funcs *funcs)
{
struct drm_mode_fb_cmd2 mode_cmd = { 0 };
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = sizes->surface_width *
DIV_ROUND_UP(sizes->surface_bpp, 8);
if (pitch_align)
mode_cmd.pitches[0] = roundup(mode_cmd.pitches[0],
pitch_align);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
if (obj->size < mode_cmd.pitches[0] * mode_cmd.height)
return ERR_PTR(-EINVAL);
return drm_gem_fb_alloc(dev, &mode_cmd, &obj, 1, funcs);
}
