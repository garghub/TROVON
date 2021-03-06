static int intelfb_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct intel_fbdev *ifbdev =
container_of(helper, struct intel_fbdev, helper);
struct drm_device *dev = helper->dev;
struct drm_i915_private *dev_priv = dev->dev_private;
struct fb_info *info;
struct drm_framebuffer *fb;
struct drm_mode_fb_cmd2 mode_cmd = {};
struct drm_i915_gem_object *obj;
struct device *device = &dev->pdev->dev;
int size, ret;
if (sizes->surface_bpp == 24)
sizes->surface_bpp = 32;
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = ALIGN(mode_cmd.width *
DIV_ROUND_UP(sizes->surface_bpp, 8), 64);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
size = mode_cmd.pitches[0] * mode_cmd.height;
size = ALIGN(size, PAGE_SIZE);
obj = i915_gem_object_create_stolen(dev, size);
if (obj == NULL)
obj = i915_gem_alloc_object(dev, size);
if (!obj) {
DRM_ERROR("failed to allocate framebuffer\n");
ret = -ENOMEM;
goto out;
}
mutex_lock(&dev->struct_mutex);
ret = intel_pin_and_fence_fb_obj(dev, obj, NULL);
if (ret) {
DRM_ERROR("failed to pin fb: %d\n", ret);
goto out_unref;
}
info = framebuffer_alloc(0, device);
if (!info) {
ret = -ENOMEM;
goto out_unpin;
}
info->par = helper;
ret = intel_framebuffer_init(dev, &ifbdev->ifb, &mode_cmd, obj);
if (ret)
goto out_unpin;
fb = &ifbdev->ifb.base;
ifbdev->helper.fb = fb;
ifbdev->helper.fbdev = info;
strcpy(info->fix.id, "inteldrmfb");
info->flags = FBINFO_DEFAULT | FBINFO_CAN_FORCE_OUTPUT;
info->fbops = &intelfb_ops;
ret = fb_alloc_cmap(&info->cmap, 256, 0);
if (ret) {
ret = -ENOMEM;
goto out_unpin;
}
info->apertures = alloc_apertures(1);
if (!info->apertures) {
ret = -ENOMEM;
goto out_unpin;
}
info->apertures->ranges[0].base = dev->mode_config.fb_base;
info->apertures->ranges[0].size = dev_priv->gtt.mappable_end;
info->fix.smem_start = dev->mode_config.fb_base + i915_gem_obj_ggtt_offset(obj);
info->fix.smem_len = size;
info->screen_base =
ioremap_wc(dev_priv->gtt.mappable_base + i915_gem_obj_ggtt_offset(obj),
size);
if (!info->screen_base) {
ret = -ENOSPC;
goto out_unpin;
}
info->screen_size = size;
info->skip_vt_switch = true;
drm_fb_helper_fill_fix(info, fb->pitches[0], fb->depth);
drm_fb_helper_fill_var(info, &ifbdev->helper, sizes->fb_width, sizes->fb_height);
if (ifbdev->ifb.obj->stolen)
memset_io(info->screen_base, 0, info->screen_size);
DRM_DEBUG_KMS("allocated %dx%d fb: 0x%08lx, bo %p\n",
fb->width, fb->height,
i915_gem_obj_ggtt_offset(obj), obj);
mutex_unlock(&dev->struct_mutex);
vga_switcheroo_client_fb_set(dev->pdev, info);
return 0;
out_unpin:
i915_gem_object_unpin(obj);
out_unref:
drm_gem_object_unreference(&obj->base);
mutex_unlock(&dev->struct_mutex);
out:
return ret;
}
static void intel_crtc_fb_gamma_set(struct drm_crtc *crtc, u16 red, u16 green,
u16 blue, int regno)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
intel_crtc->lut_r[regno] = red >> 8;
intel_crtc->lut_g[regno] = green >> 8;
intel_crtc->lut_b[regno] = blue >> 8;
}
static void intel_crtc_fb_gamma_get(struct drm_crtc *crtc, u16 *red, u16 *green,
u16 *blue, int regno)
{
struct intel_crtc *intel_crtc = to_intel_crtc(crtc);
*red = intel_crtc->lut_r[regno] << 8;
*green = intel_crtc->lut_g[regno] << 8;
*blue = intel_crtc->lut_b[regno] << 8;
}
static void intel_fbdev_destroy(struct drm_device *dev,
struct intel_fbdev *ifbdev)
{
if (ifbdev->helper.fbdev) {
struct fb_info *info = ifbdev->helper.fbdev;
unregister_framebuffer(info);
iounmap(info->screen_base);
if (info->cmap.len)
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
drm_fb_helper_fini(&ifbdev->helper);
drm_framebuffer_unregister_private(&ifbdev->ifb.base);
intel_framebuffer_fini(&ifbdev->ifb);
}
int intel_fbdev_init(struct drm_device *dev)
{
struct intel_fbdev *ifbdev;
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ifbdev = kzalloc(sizeof(*ifbdev), GFP_KERNEL);
if (!ifbdev)
return -ENOMEM;
dev_priv->fbdev = ifbdev;
ifbdev->helper.funcs = &intel_fb_helper_funcs;
ret = drm_fb_helper_init(dev, &ifbdev->helper,
INTEL_INFO(dev)->num_pipes,
4);
if (ret) {
kfree(ifbdev);
return ret;
}
drm_fb_helper_single_add_all_connectors(&ifbdev->helper);
return 0;
}
void intel_fbdev_initial_config(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
drm_fb_helper_initial_config(&dev_priv->fbdev->helper, 32);
}
void intel_fbdev_fini(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (!dev_priv->fbdev)
return;
intel_fbdev_destroy(dev, dev_priv->fbdev);
kfree(dev_priv->fbdev);
dev_priv->fbdev = NULL;
}
void intel_fbdev_set_suspend(struct drm_device *dev, int state)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct intel_fbdev *ifbdev = dev_priv->fbdev;
struct fb_info *info;
if (!ifbdev)
return;
info = ifbdev->helper.fbdev;
if (state == FBINFO_STATE_RUNNING && ifbdev->ifb.obj->stolen)
memset_io(info->screen_base, 0, info->screen_size);
fb_set_suspend(info, state);
}
void intel_fbdev_output_poll_changed(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
drm_fb_helper_hotplug_event(&dev_priv->fbdev->helper);
}
void intel_fbdev_restore_mode(struct drm_device *dev)
{
int ret;
struct drm_i915_private *dev_priv = dev->dev_private;
if (INTEL_INFO(dev)->num_pipes == 0)
return;
drm_modeset_lock_all(dev);
ret = drm_fb_helper_restore_fbdev_mode(&dev_priv->fbdev->helper);
if (ret)
DRM_DEBUG("failed to restore crtc mode\n");
drm_modeset_unlock_all(dev);
}
