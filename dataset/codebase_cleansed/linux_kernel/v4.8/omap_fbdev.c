static void pan_worker(struct work_struct *work)
{
struct omap_fbdev *fbdev = container_of(work, struct omap_fbdev, work);
struct fb_info *fbi = fbdev->base.fbdev;
int npages;
npages = fbi->fix.line_length >> PAGE_SHIFT;
omap_gem_roll(fbdev->bo, fbi->var.yoffset * npages);
}
static int omap_fbdev_pan_display(struct fb_var_screeninfo *var,
struct fb_info *fbi)
{
struct drm_fb_helper *helper = get_fb(fbi);
struct omap_fbdev *fbdev = to_omap_fbdev(helper);
if (!helper)
goto fallback;
if (!fbdev->ywrap_enabled)
goto fallback;
if (drm_can_sleep()) {
pan_worker(&fbdev->work);
} else {
struct omap_drm_private *priv = helper->dev->dev_private;
queue_work(priv->wq, &fbdev->work);
}
return 0;
fallback:
return drm_fb_helper_pan_display(var, fbi);
}
static int omap_fbdev_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct omap_fbdev *fbdev = to_omap_fbdev(helper);
struct drm_device *dev = helper->dev;
struct omap_drm_private *priv = dev->dev_private;
struct drm_framebuffer *fb = NULL;
union omap_gem_size gsize;
struct fb_info *fbi = NULL;
struct drm_mode_fb_cmd2 mode_cmd = {0};
dma_addr_t paddr;
int ret;
sizes->surface_bpp = 32;
sizes->surface_depth = 24;
DBG("create fbdev: %dx%d@%d (%dx%d)", sizes->surface_width,
sizes->surface_height, sizes->surface_bpp,
sizes->fb_width, sizes->fb_height);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] =
DIV_ROUND_UP(mode_cmd.width * sizes->surface_bpp, 8);
fbdev->ywrap_enabled = priv->has_dmm && ywrap_enabled;
if (fbdev->ywrap_enabled) {
mode_cmd.pitches[0] = PAGE_ALIGN(mode_cmd.pitches[0]);
}
gsize = (union omap_gem_size){
.bytes = PAGE_ALIGN(mode_cmd.pitches[0] * mode_cmd.height),
};
DBG("allocating %d bytes for fb %d", gsize.bytes, dev->primary->index);
fbdev->bo = omap_gem_new(dev, gsize, OMAP_BO_SCANOUT | OMAP_BO_WC);
if (!fbdev->bo) {
dev_err(dev->dev, "failed to allocate buffer object\n");
ret = -ENOMEM;
goto fail;
}
fb = omap_framebuffer_init(dev, &mode_cmd, &fbdev->bo);
if (IS_ERR(fb)) {
dev_err(dev->dev, "failed to allocate fb\n");
drm_gem_object_unreference_unlocked(fbdev->bo);
ret = PTR_ERR(fb);
goto fail;
}
ret = omap_gem_get_paddr(fbdev->bo, &paddr, true);
if (ret) {
dev_err(dev->dev,
"could not map (paddr)! Skipping framebuffer alloc\n");
ret = -ENOMEM;
goto fail;
}
mutex_lock(&dev->struct_mutex);
fbi = drm_fb_helper_alloc_fbi(helper);
if (IS_ERR(fbi)) {
dev_err(dev->dev, "failed to allocate fb info\n");
ret = PTR_ERR(fbi);
goto fail_unlock;
}
DBG("fbi=%p, dev=%p", fbi, dev);
fbdev->fb = fb;
helper->fb = fb;
fbi->par = helper;
fbi->flags = FBINFO_DEFAULT;
fbi->fbops = &omap_fb_ops;
strcpy(fbi->fix.id, MODULE_NAME);
drm_fb_helper_fill_fix(fbi, fb->pitches[0], fb->depth);
drm_fb_helper_fill_var(fbi, helper, sizes->fb_width, sizes->fb_height);
dev->mode_config.fb_base = paddr;
fbi->screen_base = omap_gem_vaddr(fbdev->bo);
fbi->screen_size = fbdev->bo->size;
fbi->fix.smem_start = paddr;
fbi->fix.smem_len = fbdev->bo->size;
if (fbdev->ywrap_enabled) {
DRM_INFO("Enabling DMM ywrap scrolling\n");
fbi->flags |= FBINFO_HWACCEL_YWRAP | FBINFO_READS_FAST;
fbi->fix.ywrapstep = 1;
}
DBG("par=%p, %dx%d", fbi->par, fbi->var.xres, fbi->var.yres);
DBG("allocated %dx%d fb", fbdev->fb->width, fbdev->fb->height);
mutex_unlock(&dev->struct_mutex);
return 0;
fail_unlock:
mutex_unlock(&dev->struct_mutex);
fail:
if (ret) {
drm_fb_helper_release_fbi(helper);
if (fb) {
drm_framebuffer_unregister_private(fb);
drm_framebuffer_remove(fb);
}
}
return ret;
}
static struct drm_fb_helper *get_fb(struct fb_info *fbi)
{
if (!fbi || strcmp(fbi->fix.id, MODULE_NAME)) {
return NULL;
}
return fbi->par;
}
struct drm_fb_helper *omap_fbdev_init(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct omap_fbdev *fbdev = NULL;
struct drm_fb_helper *helper;
int ret = 0;
fbdev = kzalloc(sizeof(*fbdev), GFP_KERNEL);
if (!fbdev)
goto fail;
INIT_WORK(&fbdev->work, pan_worker);
helper = &fbdev->base;
drm_fb_helper_prepare(dev, helper, &omap_fb_helper_funcs);
ret = drm_fb_helper_init(dev, helper,
priv->num_crtcs, priv->num_connectors);
if (ret) {
dev_err(dev->dev, "could not init fbdev: ret=%d\n", ret);
goto fail;
}
ret = drm_fb_helper_single_add_all_connectors(helper);
if (ret)
goto fini;
ret = drm_fb_helper_initial_config(helper, 32);
if (ret)
goto fini;
priv->fbdev = helper;
return helper;
fini:
drm_fb_helper_fini(helper);
fail:
kfree(fbdev);
dev_warn(dev->dev, "omap_fbdev_init failed\n");
return NULL;
}
void omap_fbdev_free(struct drm_device *dev)
{
struct omap_drm_private *priv = dev->dev_private;
struct drm_fb_helper *helper = priv->fbdev;
struct omap_fbdev *fbdev;
DBG();
drm_fb_helper_unregister_fbi(helper);
drm_fb_helper_release_fbi(helper);
drm_fb_helper_fini(helper);
fbdev = to_omap_fbdev(priv->fbdev);
omap_gem_put_paddr(fbdev->bo);
if (fbdev->fb) {
drm_framebuffer_unregister_private(fbdev->fb);
drm_framebuffer_remove(fbdev->fb);
}
kfree(fbdev);
priv->fbdev = NULL;
}
