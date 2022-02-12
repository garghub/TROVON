static int msm_fbdev_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct drm_fb_helper *helper = (struct drm_fb_helper *)info->par;
struct msm_fbdev *fbdev = to_msm_fbdev(helper);
struct drm_gem_object *drm_obj = fbdev->bo;
int ret = 0;
ret = drm_gem_mmap_obj(drm_obj, drm_obj->size, vma);
if (ret) {
pr_err("%s:drm_gem_mmap_obj fail\n", __func__);
return ret;
}
return msm_gem_mmap_obj(drm_obj, vma);
}
static int msm_fbdev_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct msm_fbdev *fbdev = to_msm_fbdev(helper);
struct drm_device *dev = helper->dev;
struct msm_drm_private *priv = dev->dev_private;
struct drm_framebuffer *fb = NULL;
struct fb_info *fbi = NULL;
struct drm_mode_fb_cmd2 mode_cmd = {0};
uint64_t paddr;
int ret, size;
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
fbdev->bo = msm_gem_new(dev, size, MSM_BO_SCANOUT |
MSM_BO_WC | MSM_BO_STOLEN);
if (IS_ERR(fbdev->bo)) {
ret = PTR_ERR(fbdev->bo);
fbdev->bo = NULL;
dev_err(dev->dev, "failed to allocate buffer object: %d\n", ret);
goto fail;
}
fb = msm_framebuffer_init(dev, &mode_cmd, &fbdev->bo);
if (IS_ERR(fb)) {
dev_err(dev->dev, "failed to allocate fb\n");
drm_gem_object_unreference_unlocked(fbdev->bo);
ret = PTR_ERR(fb);
goto fail;
}
mutex_lock(&dev->struct_mutex);
ret = msm_gem_get_iova(fbdev->bo, priv->kms->aspace, &paddr);
if (ret) {
dev_err(dev->dev, "failed to get buffer obj iova: %d\n", ret);
goto fail_unlock;
}
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
fbi->fbops = &msm_fb_ops;
strcpy(fbi->fix.id, "msm");
drm_fb_helper_fill_fix(fbi, fb->pitches[0], fb->format->depth);
drm_fb_helper_fill_var(fbi, helper, sizes->fb_width, sizes->fb_height);
dev->mode_config.fb_base = paddr;
fbi->screen_base = msm_gem_get_vaddr(fbdev->bo);
if (IS_ERR(fbi->screen_base)) {
ret = PTR_ERR(fbi->screen_base);
goto fail_unlock;
}
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
if (fb)
drm_framebuffer_remove(fb);
}
return ret;
}
struct drm_fb_helper *msm_fbdev_init(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_fbdev *fbdev = NULL;
struct drm_fb_helper *helper;
int ret;
fbdev = kzalloc(sizeof(*fbdev), GFP_KERNEL);
if (!fbdev)
goto fail;
helper = &fbdev->base;
drm_fb_helper_prepare(dev, helper, &msm_fb_helper_funcs);
ret = drm_fb_helper_init(dev, helper, priv->num_connectors);
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
return NULL;
}
void msm_fbdev_free(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct drm_fb_helper *helper = priv->fbdev;
struct msm_fbdev *fbdev;
DBG();
drm_fb_helper_unregister_fbi(helper);
drm_fb_helper_fini(helper);
fbdev = to_msm_fbdev(priv->fbdev);
if (fbdev->fb) {
msm_gem_put_vaddr(fbdev->bo);
drm_framebuffer_remove(fbdev->fb);
}
kfree(fbdev);
priv->fbdev = NULL;
}
