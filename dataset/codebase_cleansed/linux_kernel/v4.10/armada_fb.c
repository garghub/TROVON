static void armada_fb_destroy(struct drm_framebuffer *fb)
{
struct armada_framebuffer *dfb = drm_fb_to_armada_fb(fb);
drm_framebuffer_cleanup(&dfb->fb);
drm_gem_object_unreference_unlocked(&dfb->obj->obj);
kfree(dfb);
}
static int armada_fb_create_handle(struct drm_framebuffer *fb,
struct drm_file *dfile, unsigned int *handle)
{
struct armada_framebuffer *dfb = drm_fb_to_armada_fb(fb);
return drm_gem_handle_create(dfile, &dfb->obj->obj, handle);
}
struct armada_framebuffer *armada_framebuffer_create(struct drm_device *dev,
const struct drm_mode_fb_cmd2 *mode, struct armada_gem_object *obj)
{
struct armada_framebuffer *dfb;
uint8_t format, config;
int ret;
switch (mode->pixel_format) {
#define FMT(drm, fmt, mod) \
case DRM_FORMAT_##drm: \
format = CFG_##fmt; \
config = mod; \
break
FMT(RGB565, 565, CFG_SWAPRB);
FMT(BGR565, 565, 0);
FMT(ARGB1555, 1555, CFG_SWAPRB);
FMT(ABGR1555, 1555, 0);
FMT(RGB888, 888PACK, CFG_SWAPRB);
FMT(BGR888, 888PACK, 0);
FMT(XRGB8888, X888, CFG_SWAPRB);
FMT(XBGR8888, X888, 0);
FMT(ARGB8888, 8888, CFG_SWAPRB);
FMT(ABGR8888, 8888, 0);
FMT(YUYV, 422PACK, CFG_YUV2RGB | CFG_SWAPYU | CFG_SWAPUV);
FMT(UYVY, 422PACK, CFG_YUV2RGB);
FMT(VYUY, 422PACK, CFG_YUV2RGB | CFG_SWAPUV);
FMT(YVYU, 422PACK, CFG_YUV2RGB | CFG_SWAPYU);
FMT(YUV422, 422, CFG_YUV2RGB);
FMT(YVU422, 422, CFG_YUV2RGB | CFG_SWAPUV);
FMT(YUV420, 420, CFG_YUV2RGB);
FMT(YVU420, 420, CFG_YUV2RGB | CFG_SWAPUV);
FMT(C8, PSEUDO8, 0);
#undef FMT
default:
return ERR_PTR(-EINVAL);
}
dfb = kzalloc(sizeof(*dfb), GFP_KERNEL);
if (!dfb) {
DRM_ERROR("failed to allocate Armada fb object\n");
return ERR_PTR(-ENOMEM);
}
dfb->fmt = format;
dfb->mod = config;
dfb->obj = obj;
drm_helper_mode_fill_fb_struct(&dfb->fb, mode);
ret = drm_framebuffer_init(dev, &dfb->fb, &armada_fb_funcs);
if (ret) {
kfree(dfb);
return ERR_PTR(ret);
}
drm_gem_object_reference(&obj->obj);
return dfb;
}
static struct drm_framebuffer *armada_fb_create(struct drm_device *dev,
struct drm_file *dfile, const struct drm_mode_fb_cmd2 *mode)
{
struct armada_gem_object *obj;
struct armada_framebuffer *dfb;
int ret;
DRM_DEBUG_DRIVER("w%u h%u pf%08x f%u p%u,%u,%u\n",
mode->width, mode->height, mode->pixel_format,
mode->flags, mode->pitches[0], mode->pitches[1],
mode->pitches[2]);
if (drm_format_num_planes(mode->pixel_format) > 1 &&
(mode->handles[0] != mode->handles[1] ||
mode->handles[0] != mode->handles[2])) {
ret = -EINVAL;
goto err;
}
obj = armada_gem_object_lookup(dfile, mode->handles[0]);
if (!obj) {
ret = -ENOENT;
goto err;
}
if (obj->obj.import_attach && !obj->sgt) {
ret = armada_gem_map_import(obj);
if (ret)
goto err_unref;
}
if (obj->dev_addr == DMA_ERROR_CODE) {
ret = -EINVAL;
goto err_unref;
}
dfb = armada_framebuffer_create(dev, mode, obj);
if (IS_ERR(dfb)) {
ret = PTR_ERR(dfb);
goto err;
}
drm_gem_object_unreference_unlocked(&obj->obj);
return &dfb->fb;
err_unref:
drm_gem_object_unreference_unlocked(&obj->obj);
err:
DRM_ERROR("failed to initialize framebuffer: %d\n", ret);
return ERR_PTR(ret);
}
static void armada_output_poll_changed(struct drm_device *dev)
{
struct armada_private *priv = dev->dev_private;
struct drm_fb_helper *fbh = priv->fbdev;
if (fbh)
drm_fb_helper_hotplug_event(fbh);
}
