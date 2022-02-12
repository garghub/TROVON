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
info = drm_fb_helper_alloc_fbi(helper);
if (IS_ERR(info))
return -PTR_ERR(info);
info->par = fbdev;
fbdev->size = size;
fb = &fbdev->afb.base;
fbdev->helper.fb = fb;
strcpy(info->fix.id, "vboxdrmfb");
info->flags = FBINFO_DEFAULT | FBINFO_CAN_FORCE_OUTPUT |
FBINFO_MISC_ALWAYS_SETPAR;
info->fbops = &vboxfb_ops;
info->apertures->ranges[0].base = pci_resource_start(dev->pdev, 0);
info->apertures->ranges[0].size = pci_resource_len(dev->pdev, 0);
drm_fb_helper_fill_fix(info, fb->pitches[0], fb->format->depth);
drm_fb_helper_fill_var(info, &fbdev->helper, sizes->fb_width,
sizes->fb_height);
info->screen_base = bo->kmap.virtual;
info->screen_size = size;
#ifdef CONFIG_DRM_KMS_FB_HELPER
info->fbdefio = &vbox_defio;
fb_deferred_io_init(info);
#endif
info->pixmap.flags = FB_PIXMAP_SYSTEM;
DRM_DEBUG_KMS("allocated %dx%d\n", fb->width, fb->height);
return 0;
}
void vbox_fbdev_fini(struct drm_device *dev)
{
struct vbox_private *vbox = dev->dev_private;
struct vbox_fbdev *fbdev = vbox->fbdev;
struct vbox_framebuffer *afb = &fbdev->afb;
#ifdef CONFIG_DRM_KMS_FB_HELPER
if (fbdev->helper.fbdev && fbdev->helper.fbdev->fbdefio)
fb_deferred_io_cleanup(fbdev->helper.fbdev);
#endif
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
drm_gem_object_put_unlocked(afb->obj);
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
