static int armada_fb_create(struct drm_fb_helper *fbh,
struct drm_fb_helper_surface_size *sizes)
{
struct drm_device *dev = fbh->dev;
struct drm_mode_fb_cmd2 mode;
struct armada_framebuffer *dfb;
struct armada_gem_object *obj;
struct fb_info *info;
int size, ret;
void *ptr;
memset(&mode, 0, sizeof(mode));
mode.width = sizes->surface_width;
mode.height = sizes->surface_height;
mode.pitches[0] = armada_pitch(mode.width, sizes->surface_bpp);
mode.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
size = mode.pitches[0] * mode.height;
obj = armada_gem_alloc_private_object(dev, size);
if (!obj) {
DRM_ERROR("failed to allocate fb memory\n");
return -ENOMEM;
}
ret = armada_gem_linear_back(dev, obj);
if (ret) {
drm_gem_object_unreference_unlocked(&obj->obj);
return ret;
}
ptr = armada_gem_map_object(dev, obj);
if (!ptr) {
drm_gem_object_unreference_unlocked(&obj->obj);
return -ENOMEM;
}
dfb = armada_framebuffer_create(dev, &mode, obj);
drm_gem_object_unreference_unlocked(&obj->obj);
if (IS_ERR(dfb))
return PTR_ERR(dfb);
info = framebuffer_alloc(0, dev->dev);
if (!info) {
ret = -ENOMEM;
goto err_fballoc;
}
ret = fb_alloc_cmap(&info->cmap, 256, 0);
if (ret) {
ret = -ENOMEM;
goto err_fbcmap;
}
strlcpy(info->fix.id, "armada-drmfb", sizeof(info->fix.id));
info->par = fbh;
info->flags = FBINFO_DEFAULT | FBINFO_CAN_FORCE_OUTPUT;
info->fbops = &armada_fb_ops;
info->fix.smem_start = obj->phys_addr;
info->fix.smem_len = obj->obj.size;
info->screen_size = obj->obj.size;
info->screen_base = ptr;
fbh->fb = &dfb->fb;
fbh->fbdev = info;
drm_fb_helper_fill_fix(info, dfb->fb.pitches[0], dfb->fb.depth);
drm_fb_helper_fill_var(info, fbh, sizes->fb_width, sizes->fb_height);
DRM_DEBUG_KMS("allocated %dx%d %dbpp fb: 0x%08llx\n",
dfb->fb.width, dfb->fb.height, dfb->fb.bits_per_pixel,
(unsigned long long)obj->phys_addr);
return 0;
err_fbcmap:
framebuffer_release(info);
err_fballoc:
dfb->fb.funcs->destroy(&dfb->fb);
return ret;
}
static int armada_fb_probe(struct drm_fb_helper *fbh,
struct drm_fb_helper_surface_size *sizes)
{
int ret = 0;
if (!fbh->fb) {
ret = armada_fb_create(fbh, sizes);
if (ret == 0)
ret = 1;
}
return ret;
}
int armada_fbdev_init(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
struct drm_fb_helper *fbh;
int ret;
fbh = devm_kzalloc(dev->dev, sizeof(*fbh), GFP_KERNEL);
if (!fbh)
return -ENOMEM;
priv->fbdev = fbh;
fbh->funcs = &armada_fb_helper_funcs;
ret = drm_fb_helper_init(dev, fbh, 1, 1);
if (ret) {
DRM_ERROR("failed to initialize drm fb helper\n");
goto err_fb_helper;
}
ret = drm_fb_helper_single_add_all_connectors(fbh);
if (ret) {
DRM_ERROR("failed to add fb connectors\n");
goto err_fb_setup;
}
ret = drm_fb_helper_initial_config(fbh, 32);
if (ret) {
DRM_ERROR("failed to set initial config\n");
goto err_fb_setup;
}
return 0;
err_fb_setup:
drm_fb_helper_fini(fbh);
err_fb_helper:
priv->fbdev = NULL;
return ret;
}
void armada_fbdev_lastclose(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
drm_modeset_lock_all(dev);
if (priv->fbdev)
drm_fb_helper_restore_fbdev_mode(priv->fbdev);
drm_modeset_unlock_all(dev);
}
void armada_fbdev_fini(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
struct drm_fb_helper *fbh = priv->fbdev;
if (fbh) {
struct fb_info *info = fbh->fbdev;
if (info) {
unregister_framebuffer(info);
if (info->cmap.len)
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
drm_fb_helper_fini(fbh);
if (fbh->fb)
fbh->fb->funcs->destroy(fbh->fb);
priv->fbdev = NULL;
}
}
