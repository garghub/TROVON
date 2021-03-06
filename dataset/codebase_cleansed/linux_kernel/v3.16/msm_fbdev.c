static int msm_fbdev_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct msm_fbdev *fbdev = to_msm_fbdev(helper);
struct drm_device *dev = helper->dev;
struct drm_framebuffer *fb = NULL;
struct fb_info *fbi = NULL;
struct drm_mode_fb_cmd2 mode_cmd = {0};
uint32_t paddr;
int ret, size;
sizes->surface_bpp = 32;
sizes->surface_depth = 24;
DBG("create fbdev: %dx%d@%d (%dx%d)", sizes->surface_width,
sizes->surface_height, sizes->surface_bpp,
sizes->fb_width, sizes->fb_height);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = align_pitch(
mode_cmd.width, sizes->surface_bpp);
size = mode_cmd.pitches[0] * mode_cmd.height;
DBG("allocating %d bytes for fb %d", size, dev->primary->index);
mutex_lock(&dev->struct_mutex);
fbdev->bo = msm_gem_new(dev, size, MSM_BO_SCANOUT | MSM_BO_WC);
mutex_unlock(&dev->struct_mutex);
if (IS_ERR(fbdev->bo)) {
ret = PTR_ERR(fbdev->bo);
fbdev->bo = NULL;
dev_err(dev->dev, "failed to allocate buffer object: %d\n", ret);
goto fail;
}
fb = msm_framebuffer_init(dev, &mode_cmd, &fbdev->bo);
if (IS_ERR(fb)) {
dev_err(dev->dev, "failed to allocate fb\n");
drm_gem_object_unreference(fbdev->bo);
ret = PTR_ERR(fb);
goto fail;
}
mutex_lock(&dev->struct_mutex);
msm_gem_get_iova_locked(fbdev->bo, 0, &paddr);
fbi = framebuffer_alloc(0, dev->dev);
if (!fbi) {
dev_err(dev->dev, "failed to allocate fb info\n");
ret = -ENOMEM;
goto fail_unlock;
}
DBG("fbi=%p, dev=%p", fbi, dev);
fbdev->fb = fb;
helper->fb = fb;
helper->fbdev = fbi;
fbi->par = helper;
fbi->flags = FBINFO_DEFAULT;
fbi->fbops = &msm_fb_ops;
strcpy(fbi->fix.id, "msm");
ret = fb_alloc_cmap(&fbi->cmap, 256, 0);
if (ret) {
ret = -ENOMEM;
goto fail_unlock;
}
drm_fb_helper_fill_fix(fbi, fb->pitches[0], fb->depth);
drm_fb_helper_fill_var(fbi, helper, sizes->fb_width, sizes->fb_height);
dev->mode_config.fb_base = paddr;
fbi->screen_base = msm_gem_vaddr_locked(fbdev->bo);
fbi->screen_size = fbdev->bo->size;
fbi->fix.smem_start = paddr;
fbi->fix.smem_len = fbdev->bo->size;
DBG("par=%p, %dx%d", fbi->par, fbi->var.xres, fbi->var.yres);
DBG("allocated %dx%d fb", fbdev->fb->width, fbdev->fb->height);
mutex_unlock(&dev->struct_mutex);
return 0;
fail_unlock:
mutex_unlock(&dev->struct_mutex);
fail:
if (ret) {
if (fbi)
framebuffer_release(fbi);
if (fb) {
drm_framebuffer_unregister_private(fb);
drm_framebuffer_remove(fb);
}
}
return ret;
}
static void msm_crtc_fb_gamma_set(struct drm_crtc *crtc,
u16 red, u16 green, u16 blue, int regno)
{
DBG("fbdev: set gamma");
}
static void msm_crtc_fb_gamma_get(struct drm_crtc *crtc,
u16 *red, u16 *green, u16 *blue, int regno)
{
DBG("fbdev: get gamma");
}
struct drm_fb_helper *msm_fbdev_init(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_fbdev *fbdev = NULL;
struct drm_fb_helper *helper;
int ret = 0;
fbdev = kzalloc(sizeof(*fbdev), GFP_KERNEL);
if (!fbdev)
goto fail;
helper = &fbdev->base;
helper->funcs = &msm_fb_helper_funcs;
ret = drm_fb_helper_init(dev, helper,
priv->num_crtcs, priv->num_connectors);
if (ret) {
dev_err(dev->dev, "could not init fbdev: ret=%d\n", ret);
goto fail;
}
drm_fb_helper_single_add_all_connectors(helper);
drm_helper_disable_unused_functions(dev);
drm_fb_helper_initial_config(helper, 32);
priv->fbdev = helper;
return helper;
fail:
kfree(fbdev);
return NULL;
}
void msm_fbdev_free(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct drm_fb_helper *helper = priv->fbdev;
struct msm_fbdev *fbdev;
struct fb_info *fbi;
DBG();
fbi = helper->fbdev;
if (fbi) {
unregister_framebuffer(fbi);
framebuffer_release(fbi);
}
drm_fb_helper_fini(helper);
fbdev = to_msm_fbdev(priv->fbdev);
if (fbdev->fb) {
drm_framebuffer_unregister_private(fbdev->fb);
drm_framebuffer_remove(fbdev->fb);
}
kfree(fbdev);
priv->fbdev = NULL;
}
