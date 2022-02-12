static void qxl_fb_image_init(struct qxl_fb_image *qxl_fb_image,
struct qxl_device *qdev, struct fb_info *info,
const struct fb_image *image)
{
qxl_fb_image->qdev = qdev;
if (info) {
qxl_fb_image->visual = info->fix.visual;
if (qxl_fb_image->visual == FB_VISUAL_TRUECOLOR ||
qxl_fb_image->visual == FB_VISUAL_DIRECTCOLOR)
memcpy(&qxl_fb_image->pseudo_palette,
info->pseudo_palette,
sizeof(qxl_fb_image->pseudo_palette));
} else {
if (image->depth == 1)
qxl_fb_image->visual = FB_VISUAL_MONO10;
else
qxl_fb_image->visual = FB_VISUAL_DIRECTCOLOR;
}
if (image) {
memcpy(&qxl_fb_image->fb_image, image,
sizeof(qxl_fb_image->fb_image));
}
}
static void qxlfb_destroy_pinned_object(struct drm_gem_object *gobj)
{
struct qxl_bo *qbo = gem_to_qxl_bo(gobj);
int ret;
ret = qxl_bo_reserve(qbo, false);
if (likely(ret == 0)) {
qxl_bo_kunmap(qbo);
qxl_bo_unpin(qbo);
qxl_bo_unreserve(qbo);
}
drm_gem_object_unreference_unlocked(gobj);
}
int qxl_get_handle_for_primary_fb(struct qxl_device *qdev,
struct drm_file *file_priv,
uint32_t *handle)
{
int r;
struct drm_gem_object *gobj = qdev->fbdev_qfb->obj;
BUG_ON(!gobj);
r = drm_gem_handle_create(file_priv, gobj, handle);
if (r)
return r;
return 0;
}
static int qxlfb_create_pinned_object(struct qxl_fbdev *qfbdev,
const struct drm_mode_fb_cmd2 *mode_cmd,
struct drm_gem_object **gobj_p)
{
struct qxl_device *qdev = qfbdev->qdev;
struct drm_gem_object *gobj = NULL;
struct qxl_bo *qbo = NULL;
int ret;
int aligned_size, size;
int height = mode_cmd->height;
size = mode_cmd->pitches[0] * height;
aligned_size = ALIGN(size, PAGE_SIZE);
ret = qxl_gem_object_create(qdev, aligned_size, 0,
QXL_GEM_DOMAIN_SURFACE,
false,
false,
NULL,
&gobj);
if (ret) {
pr_err("failed to allocate framebuffer (%d)\n",
aligned_size);
return -ENOMEM;
}
qbo = gem_to_qxl_bo(gobj);
qbo->surf.width = mode_cmd->width;
qbo->surf.height = mode_cmd->height;
qbo->surf.stride = mode_cmd->pitches[0];
qbo->surf.format = SPICE_SURFACE_FMT_32_xRGB;
ret = qxl_bo_reserve(qbo, false);
if (unlikely(ret != 0))
goto out_unref;
ret = qxl_bo_pin(qbo, QXL_GEM_DOMAIN_SURFACE, NULL);
if (ret) {
qxl_bo_unreserve(qbo);
goto out_unref;
}
ret = qxl_bo_kmap(qbo, NULL);
qxl_bo_unreserve(qbo);
if (ret)
goto out_unref;
*gobj_p = gobj;
return 0;
out_unref:
qxlfb_destroy_pinned_object(gobj);
*gobj_p = NULL;
return ret;
}
static int qxlfb_framebuffer_dirty(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned flags, unsigned color,
struct drm_clip_rect *clips,
unsigned num_clips)
{
struct qxl_device *qdev = fb->dev->dev_private;
struct fb_info *info = qdev->fbdev_info;
struct qxl_fbdev *qfbdev = info->par;
struct qxl_fb_image qxl_fb_image;
struct fb_image *image = &qxl_fb_image.fb_image;
int stride = qfbdev->qfb.base.pitches[0];
qxl_io_log(qdev, "dirty x[%d, %d], y[%d, %d]\n", clips->x1, clips->x2,
clips->y1, clips->y2);
image->dx = clips->x1;
image->dy = clips->y1;
image->width = clips->x2 - clips->x1;
image->height = clips->y2 - clips->y1;
image->fg_color = 0xffffffff;
image->bg_color = 0;
image->depth = 32;
image->cmap.start = 0;
image->cmap.len = 0;
image->cmap.red = NULL;
image->cmap.green = NULL;
image->cmap.blue = NULL;
image->cmap.transp = NULL;
image->data = qfbdev->shadow + (clips->x1 * 4) + (stride * clips->y1);
qxl_fb_image_init(&qxl_fb_image, qdev, info, NULL);
qxl_draw_opaque_fb(&qxl_fb_image, stride);
return 0;
}
static int qxlfb_create(struct qxl_fbdev *qfbdev,
struct drm_fb_helper_surface_size *sizes)
{
struct qxl_device *qdev = qfbdev->qdev;
struct fb_info *info;
struct drm_framebuffer *fb = NULL;
struct drm_mode_fb_cmd2 mode_cmd;
struct drm_gem_object *gobj = NULL;
struct qxl_bo *qbo = NULL;
int ret;
int size;
int bpp = sizes->surface_bpp;
int depth = sizes->surface_depth;
void *shadow;
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = ALIGN(mode_cmd.width * ((bpp + 1) / 8), 64);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(bpp, depth);
ret = qxlfb_create_pinned_object(qfbdev, &mode_cmd, &gobj);
if (ret < 0)
return ret;
qbo = gem_to_qxl_bo(gobj);
QXL_INFO(qdev, "%s: %dx%d %d\n", __func__, mode_cmd.width,
mode_cmd.height, mode_cmd.pitches[0]);
shadow = vmalloc(mode_cmd.pitches[0] * mode_cmd.height);
BUG_ON(!shadow);
QXL_INFO(qdev,
"surface0 at gpu offset %lld, mmap_offset %lld (virt %p, shadow %p)\n",
qxl_bo_gpu_offset(qbo),
qxl_bo_mmap_offset(qbo),
qbo->kptr,
shadow);
size = mode_cmd.pitches[0] * mode_cmd.height;
info = drm_fb_helper_alloc_fbi(&qfbdev->helper);
if (IS_ERR(info)) {
ret = PTR_ERR(info);
goto out_unref;
}
info->par = qfbdev;
qxl_framebuffer_init(qdev->ddev, &qfbdev->qfb, &mode_cmd, gobj,
&qxlfb_fb_funcs);
fb = &qfbdev->qfb.base;
qfbdev->helper.fb = fb;
qfbdev->shadow = shadow;
strcpy(info->fix.id, "qxldrmfb");
drm_fb_helper_fill_fix(info, fb->pitches[0], fb->depth);
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_COPYAREA | FBINFO_HWACCEL_FILLRECT;
info->fbops = &qxlfb_ops;
info->fix.smem_start = qdev->vram_base;
info->fix.smem_len = gobj->size;
info->screen_base = qfbdev->shadow;
info->screen_size = gobj->size;
drm_fb_helper_fill_var(info, &qfbdev->helper, sizes->fb_width,
sizes->fb_height);
info->apertures->ranges[0].base = qdev->ddev->mode_config.fb_base;
info->apertures->ranges[0].size = qdev->vram_size;
info->fix.mmio_start = 0;
info->fix.mmio_len = 0;
if (info->screen_base == NULL) {
ret = -ENOSPC;
goto out_destroy_fbi;
}
#ifdef CONFIG_DRM_FBDEV_EMULATION
info->fbdefio = &qxl_defio;
fb_deferred_io_init(info);
#endif
qdev->fbdev_info = info;
qdev->fbdev_qfb = &qfbdev->qfb;
DRM_INFO("fb mappable at 0x%lX, size %lu\n", info->fix.smem_start, (unsigned long)info->screen_size);
DRM_INFO("fb: depth %d, pitch %d, width %d, height %d\n", fb->depth, fb->pitches[0], fb->width, fb->height);
return 0;
out_destroy_fbi:
drm_fb_helper_release_fbi(&qfbdev->helper);
out_unref:
if (qbo) {
ret = qxl_bo_reserve(qbo, false);
if (likely(ret == 0)) {
qxl_bo_kunmap(qbo);
qxl_bo_unpin(qbo);
qxl_bo_unreserve(qbo);
}
}
if (fb && ret) {
drm_gem_object_unreference_unlocked(gobj);
drm_framebuffer_cleanup(fb);
kfree(fb);
}
drm_gem_object_unreference_unlocked(gobj);
return ret;
}
static int qxl_fb_find_or_create_single(
struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct qxl_fbdev *qfbdev =
container_of(helper, struct qxl_fbdev, helper);
int new_fb = 0;
int ret;
if (!helper->fb) {
ret = qxlfb_create(qfbdev, sizes);
if (ret)
return ret;
new_fb = 1;
}
return new_fb;
}
static int qxl_fbdev_destroy(struct drm_device *dev, struct qxl_fbdev *qfbdev)
{
struct qxl_framebuffer *qfb = &qfbdev->qfb;
drm_fb_helper_unregister_fbi(&qfbdev->helper);
drm_fb_helper_release_fbi(&qfbdev->helper);
if (qfb->obj) {
qxlfb_destroy_pinned_object(qfb->obj);
qfb->obj = NULL;
}
drm_fb_helper_fini(&qfbdev->helper);
vfree(qfbdev->shadow);
drm_framebuffer_cleanup(&qfb->base);
return 0;
}
int qxl_fbdev_init(struct qxl_device *qdev)
{
struct qxl_fbdev *qfbdev;
int bpp_sel = 32;
int ret;
qfbdev = kzalloc(sizeof(struct qxl_fbdev), GFP_KERNEL);
if (!qfbdev)
return -ENOMEM;
qfbdev->qdev = qdev;
qdev->mode_info.qfbdev = qfbdev;
spin_lock_init(&qfbdev->delayed_ops_lock);
INIT_LIST_HEAD(&qfbdev->delayed_ops);
drm_fb_helper_prepare(qdev->ddev, &qfbdev->helper,
&qxl_fb_helper_funcs);
ret = drm_fb_helper_init(qdev->ddev, &qfbdev->helper,
qxl_num_crtc ,
QXLFB_CONN_LIMIT);
if (ret)
goto free;
ret = drm_fb_helper_single_add_all_connectors(&qfbdev->helper);
if (ret)
goto fini;
ret = drm_fb_helper_initial_config(&qfbdev->helper, bpp_sel);
if (ret)
goto fini;
return 0;
fini:
drm_fb_helper_fini(&qfbdev->helper);
free:
kfree(qfbdev);
return ret;
}
void qxl_fbdev_fini(struct qxl_device *qdev)
{
if (!qdev->mode_info.qfbdev)
return;
qxl_fbdev_destroy(qdev->ddev, qdev->mode_info.qfbdev);
kfree(qdev->mode_info.qfbdev);
qdev->mode_info.qfbdev = NULL;
}
void qxl_fbdev_set_suspend(struct qxl_device *qdev, int state)
{
drm_fb_helper_set_suspend(&qdev->mode_info.qfbdev->helper, state);
}
bool qxl_fbdev_qobj_is_fb(struct qxl_device *qdev, struct qxl_bo *qobj)
{
if (qobj == gem_to_qxl_bo(qdev->mode_info.qfbdev->qfb.obj))
return true;
return false;
}
