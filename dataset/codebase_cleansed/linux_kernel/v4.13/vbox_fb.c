static void vbox_dirty_update(struct vbox_fbdev *fbdev,
int x, int y, int width, int height)
{
struct drm_gem_object *obj;
struct vbox_bo *bo;
int ret = -EBUSY;
bool store_for_later = false;
int x2, y2;
unsigned long flags;
struct drm_clip_rect rect;
obj = fbdev->afb.obj;
bo = gem_to_vbox_bo(obj);
if (drm_can_sleep())
ret = vbox_bo_reserve(bo, true);
if (ret) {
if (ret != -EBUSY)
return;
store_for_later = true;
}
x2 = x + width - 1;
y2 = y + height - 1;
spin_lock_irqsave(&fbdev->dirty_lock, flags);
if (fbdev->y1 < y)
y = fbdev->y1;
if (fbdev->y2 > y2)
y2 = fbdev->y2;
if (fbdev->x1 < x)
x = fbdev->x1;
if (fbdev->x2 > x2)
x2 = fbdev->x2;
if (store_for_later) {
fbdev->x1 = x;
fbdev->x2 = x2;
fbdev->y1 = y;
fbdev->y2 = y2;
spin_unlock_irqrestore(&fbdev->dirty_lock, flags);
return;
}
fbdev->x1 = INT_MAX;
fbdev->y1 = INT_MAX;
fbdev->x2 = 0;
fbdev->y2 = 0;
spin_unlock_irqrestore(&fbdev->dirty_lock, flags);
rect.x1 = x;
rect.x2 = x2 + 1;
rect.y1 = y;
rect.y2 = y2 + 1;
vbox_framebuffer_dirty_rectangles(&fbdev->afb.base, &rect, 1);
vbox_bo_unreserve(bo);
}
static void vbox_deferred_io(struct fb_info *info, struct list_head *pagelist)
{
struct vbox_fbdev *fbdev = info->par;
unsigned long start, end, min, max;
struct page *page;
int y1, y2;
min = ULONG_MAX;
max = 0;
list_for_each_entry(page, pagelist, lru) {
start = page->index << PAGE_SHIFT;
end = start + PAGE_SIZE - 1;
min = min(min, start);
max = max(max, end);
}
if (min < max) {
y1 = min / info->fix.line_length;
y2 = (max / info->fix.line_length) + 1;
DRM_INFO("%s: Calling dirty update: 0, %d, %d, %d\n",
__func__, y1, info->var.xres, y2 - y1 - 1);
vbox_dirty_update(fbdev, 0, y1, info->var.xres, y2 - y1 - 1);
}
}
static void vbox_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct vbox_fbdev *fbdev = info->par;
sys_fillrect(info, rect);
vbox_dirty_update(fbdev, rect->dx, rect->dy, rect->width, rect->height);
}
static void vbox_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct vbox_fbdev *fbdev = info->par;
sys_copyarea(info, area);
vbox_dirty_update(fbdev, area->dx, area->dy, area->width, area->height);
}
static void vbox_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct vbox_fbdev *fbdev = info->par;
sys_imageblit(info, image);
vbox_dirty_update(fbdev, image->dx, image->dy, image->width,
image->height);
}
static int vboxfb_create_object(struct vbox_fbdev *fbdev,
struct DRM_MODE_FB_CMD *mode_cmd,
struct drm_gem_object **gobj_p)
{
struct drm_device *dev = fbdev->helper.dev;
u32 size;
struct drm_gem_object *gobj;
u32 pitch = mode_cmd->pitches[0];
int ret;
size = pitch * mode_cmd->height;
ret = vbox_gem_create(dev, size, true, &gobj);
if (ret)
return ret;
*gobj_p = gobj;
return 0;
}
static int vboxfb_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct vbox_fbdev *fbdev =
container_of(helper, struct vbox_fbdev, helper);
struct drm_device *dev = fbdev->helper.dev;
struct DRM_MODE_FB_CMD mode_cmd;
struct drm_framebuffer *fb;
struct fb_info *info;
struct device *device = &dev->pdev->dev;
struct drm_gem_object *gobj;
struct vbox_bo *bo;
int size, ret;
u32 pitch;
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
pitch = mode_cmd.width * ((sizes->surface_bpp + 7) / 8);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
mode_cmd.pitches[0] = pitch;
size = pitch * mode_cmd.height;
ret = vboxfb_create_object(fbdev, &mode_cmd, &gobj);
if (ret) {
DRM_ERROR("failed to create fbcon backing object %d\n", ret);
return ret;
}
ret = vbox_framebuffer_init(dev, &fbdev->afb, &mode_cmd, gobj);
if (ret)
return ret;
bo = gem_to_vbox_bo(gobj);
ret = vbox_bo_reserve(bo, false);
if (ret)
return ret;
ret = vbox_bo_pin(bo, TTM_PL_FLAG_VRAM, NULL);
if (ret) {
vbox_bo_unreserve(bo);
return ret;
}
ret = ttm_bo_kmap(&bo->bo, 0, bo->bo.num_pages, &bo->kmap);
vbox_bo_unreserve(bo);
if (ret) {
DRM_ERROR("failed to kmap fbcon\n");
return ret;
}
info = framebuffer_alloc(0, device);
if (!info)
return -ENOMEM;
info->par = fbdev;
fbdev->size = size;
fb = &fbdev->afb.base;
fbdev->helper.fb = fb;
fbdev->helper.fbdev = info;
strcpy(info->fix.id, "vboxdrmfb");
info->flags = FBINFO_DEFAULT | FBINFO_CAN_FORCE_OUTPUT |
FBINFO_MISC_ALWAYS_SETPAR;
info->fbops = &vboxfb_ops;
ret = fb_alloc_cmap(&info->cmap, 256, 0);
if (ret)
return -ENOMEM;
info->apertures = alloc_apertures(1);
if (!info->apertures)
return -ENOMEM;
info->apertures->ranges[0].base = pci_resource_start(dev->pdev, 0);
info->apertures->ranges[0].size = pci_resource_len(dev->pdev, 0);
drm_fb_helper_fill_fix(info, fb->pitches[0], fb->format->depth);
drm_fb_helper_fill_var(info, &fbdev->helper, sizes->fb_width,
sizes->fb_height);
info->screen_base = bo->kmap.virtual;
info->screen_size = size;
#ifdef CONFIG_FB_DEFERRED_IO
info->fbdefio = &vbox_defio;
fb_deferred_io_init(info);
#endif
info->pixmap.flags = FB_PIXMAP_SYSTEM;
DRM_DEBUG_KMS("allocated %dx%d\n", fb->width, fb->height);
return 0;
}
static void vbox_fb_gamma_set(struct drm_crtc *crtc, u16 red, u16 green,
u16 blue, int regno)
{
}
static void vbox_fb_gamma_get(struct drm_crtc *crtc, u16 *red, u16 *green,
u16 *blue, int regno)
{
*red = regno;
*green = regno;
*blue = regno;
}
void vbox_fbdev_fini(struct drm_device *dev)
{
struct vbox_private *vbox = dev->dev_private;
struct vbox_fbdev *fbdev = vbox->fbdev;
struct vbox_framebuffer *afb = &fbdev->afb;
drm_fb_helper_unregister_fbi(&fbdev->helper);
if (afb->obj) {
struct vbox_bo *bo = gem_to_vbox_bo(afb->obj);
if (!vbox_bo_reserve(bo, false)) {
if (bo->kmap.virtual)
ttm_bo_kunmap(&bo->kmap);
if (bo->pin_count)
vbox_bo_unpin(bo);
vbox_bo_unreserve(bo);
}
drm_gem_object_unreference_unlocked(afb->obj);
afb->obj = NULL;
}
drm_fb_helper_fini(&fbdev->helper);
drm_framebuffer_unregister_private(&afb->base);
drm_framebuffer_cleanup(&afb->base);
}
int vbox_fbdev_init(struct drm_device *dev)
{
struct vbox_private *vbox = dev->dev_private;
struct vbox_fbdev *fbdev;
int ret;
fbdev = devm_kzalloc(dev->dev, sizeof(*fbdev), GFP_KERNEL);
if (!fbdev)
return -ENOMEM;
vbox->fbdev = fbdev;
spin_lock_init(&fbdev->dirty_lock);
drm_fb_helper_prepare(dev, &fbdev->helper, &vbox_fb_helper_funcs);
ret = drm_fb_helper_init(dev, &fbdev->helper, vbox->num_crtcs);
if (ret)
return ret;
ret = drm_fb_helper_single_add_all_connectors(&fbdev->helper);
if (ret)
goto err_fini;
drm_helper_disable_unused_functions(dev);
ret = drm_fb_helper_initial_config(&fbdev->helper, 32);
if (ret)
goto err_fini;
return 0;
err_fini:
drm_fb_helper_fini(&fbdev->helper);
return ret;
}
void vbox_fbdev_set_base(struct vbox_private *vbox, unsigned long gpu_addr)
{
struct fb_info *fbdev = vbox->fbdev->helper.fbdev;
fbdev->fix.smem_start = fbdev->apertures->ranges[0].base + gpu_addr;
fbdev->fix.smem_len = vbox->available_vram_size - gpu_addr;
}
