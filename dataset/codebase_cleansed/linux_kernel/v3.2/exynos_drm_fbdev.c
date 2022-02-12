static int exynos_drm_fbdev_set_par(struct fb_info *info)
{
struct fb_var_screeninfo *var = &info->var;
switch (var->bits_per_pixel) {
case 32:
case 24:
case 18:
case 16:
case 12:
info->fix.visual = FB_VISUAL_TRUECOLOR;
break;
case 1:
info->fix.visual = FB_VISUAL_MONO01;
break;
default:
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
break;
}
info->fix.line_length = (var->xres_virtual * var->bits_per_pixel) / 8;
return drm_fb_helper_set_par(info);
}
static int exynos_drm_fbdev_update(struct drm_fb_helper *helper,
struct drm_framebuffer *fb)
{
struct fb_info *fbi = helper->fbdev;
struct drm_device *dev = helper->dev;
struct exynos_drm_fbdev *exynos_fb = to_exynos_fbdev(helper);
struct exynos_drm_gem_buf *buffer;
unsigned int size = fb->width * fb->height * (fb->bits_per_pixel >> 3);
unsigned long offset;
DRM_DEBUG_KMS("%s\n", __FILE__);
exynos_fb->fb = fb;
drm_fb_helper_fill_fix(fbi, fb->pitch, fb->depth);
drm_fb_helper_fill_var(fbi, helper, fb->width, fb->height);
buffer = exynos_drm_fb_get_buf(fb);
if (!buffer) {
DRM_LOG_KMS("buffer is null.\n");
return -EFAULT;
}
offset = fbi->var.xoffset * (fb->bits_per_pixel >> 3);
offset += fbi->var.yoffset * fb->pitch;
dev->mode_config.fb_base = (resource_size_t)buffer->dma_addr;
fbi->screen_base = buffer->kvaddr + offset;
fbi->fix.smem_start = (unsigned long)(buffer->dma_addr + offset);
fbi->screen_size = size;
fbi->fix.smem_len = size;
return 0;
}
static int exynos_drm_fbdev_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct exynos_drm_fbdev *exynos_fbdev = to_exynos_fbdev(helper);
struct drm_device *dev = helper->dev;
struct fb_info *fbi;
struct drm_mode_fb_cmd mode_cmd = { 0 };
struct platform_device *pdev = dev->platformdev;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
DRM_DEBUG_KMS("surface width(%d), height(%d) and bpp(%d\n",
sizes->surface_width, sizes->surface_height,
sizes->surface_bpp);
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.bpp = sizes->surface_bpp;
mode_cmd.depth = sizes->surface_depth;
mutex_lock(&dev->struct_mutex);
fbi = framebuffer_alloc(0, &pdev->dev);
if (!fbi) {
DRM_ERROR("failed to allocate fb info.\n");
ret = -ENOMEM;
goto out;
}
exynos_fbdev->fb = exynos_drm_fb_create(dev, NULL, &mode_cmd);
if (IS_ERR_OR_NULL(exynos_fbdev->fb)) {
DRM_ERROR("failed to create drm framebuffer.\n");
ret = PTR_ERR(exynos_fbdev->fb);
goto out;
}
helper->fb = exynos_fbdev->fb;
helper->fbdev = fbi;
fbi->par = helper;
fbi->flags = FBINFO_FLAG_DEFAULT;
fbi->fbops = &exynos_drm_fb_ops;
ret = fb_alloc_cmap(&fbi->cmap, 256, 0);
if (ret) {
DRM_ERROR("failed to allocate cmap.\n");
goto out;
}
ret = exynos_drm_fbdev_update(helper, helper->fb);
if (ret < 0)
fb_dealloc_cmap(&fbi->cmap);
out:
mutex_unlock(&dev->struct_mutex);
return ret;
}
static bool
exynos_drm_fbdev_is_samefb(struct drm_framebuffer *fb,
struct drm_fb_helper_surface_size *sizes)
{
if (fb->width != sizes->surface_width)
return false;
if (fb->height != sizes->surface_height)
return false;
if (fb->bits_per_pixel != sizes->surface_bpp)
return false;
if (fb->depth != sizes->surface_depth)
return false;
return true;
}
static int exynos_drm_fbdev_recreate(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct drm_device *dev = helper->dev;
struct exynos_drm_fbdev *exynos_fbdev = to_exynos_fbdev(helper);
struct drm_framebuffer *fb = exynos_fbdev->fb;
struct drm_mode_fb_cmd mode_cmd = { 0 };
DRM_DEBUG_KMS("%s\n", __FILE__);
if (helper->fb != fb) {
DRM_ERROR("drm framebuffer is different\n");
return -EINVAL;
}
if (exynos_drm_fbdev_is_samefb(fb, sizes))
return 0;
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.bpp = sizes->surface_bpp;
mode_cmd.depth = sizes->surface_depth;
if (fb->funcs->destroy)
fb->funcs->destroy(fb);
exynos_fbdev->fb = exynos_drm_fb_create(dev, NULL, &mode_cmd);
if (IS_ERR(exynos_fbdev->fb)) {
DRM_ERROR("failed to allocate fb.\n");
return PTR_ERR(exynos_fbdev->fb);
}
helper->fb = exynos_fbdev->fb;
return exynos_drm_fbdev_update(helper, helper->fb);
}
static int exynos_drm_fbdev_probe(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
int ret = 0;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!helper->fb) {
ret = exynos_drm_fbdev_create(helper, sizes);
if (ret < 0) {
DRM_ERROR("failed to create fbdev.\n");
return ret;
}
ret = 1;
} else {
ret = exynos_drm_fbdev_recreate(helper, sizes);
if (ret < 0) {
DRM_ERROR("failed to reconfigure fbdev\n");
return ret;
}
}
return ret;
}
int exynos_drm_fbdev_init(struct drm_device *dev)
{
struct exynos_drm_fbdev *fbdev;
struct exynos_drm_private *private = dev->dev_private;
struct drm_fb_helper *helper;
unsigned int num_crtc;
int ret;
DRM_DEBUG_KMS("%s\n", __FILE__);
if (!dev->mode_config.num_crtc || !dev->mode_config.num_connector)
return 0;
fbdev = kzalloc(sizeof(*fbdev), GFP_KERNEL);
if (!fbdev) {
DRM_ERROR("failed to allocate drm fbdev.\n");
return -ENOMEM;
}
private->fb_helper = helper = &fbdev->drm_fb_helper;
helper->funcs = &exynos_drm_fb_helper_funcs;
num_crtc = dev->mode_config.num_crtc;
ret = drm_fb_helper_init(dev, helper, num_crtc, MAX_CONNECTOR);
if (ret < 0) {
DRM_ERROR("failed to initialize drm fb helper.\n");
goto err_init;
}
ret = drm_fb_helper_single_add_all_connectors(helper);
if (ret < 0) {
DRM_ERROR("failed to register drm_fb_helper_connector.\n");
goto err_setup;
}
ret = drm_fb_helper_initial_config(helper, PREFERRED_BPP);
if (ret < 0) {
DRM_ERROR("failed to set up hw configuration.\n");
goto err_setup;
}
return 0;
err_setup:
drm_fb_helper_fini(helper);
err_init:
private->fb_helper = NULL;
kfree(fbdev);
return ret;
}
static void exynos_drm_fbdev_destroy(struct drm_device *dev,
struct drm_fb_helper *fb_helper)
{
struct drm_framebuffer *fb;
if (fb_helper->fb && fb_helper->fb->funcs) {
fb = fb_helper->fb;
if (fb && fb->funcs->destroy)
fb->funcs->destroy(fb);
}
if (fb_helper->fbdev) {
struct fb_info *info;
int ret;
info = fb_helper->fbdev;
ret = unregister_framebuffer(info);
if (ret < 0)
DRM_DEBUG_KMS("failed unregister_framebuffer()\n");
if (info->cmap.len)
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
drm_fb_helper_fini(fb_helper);
}
void exynos_drm_fbdev_fini(struct drm_device *dev)
{
struct exynos_drm_private *private = dev->dev_private;
struct exynos_drm_fbdev *fbdev;
if (!private || !private->fb_helper)
return;
fbdev = to_exynos_fbdev(private->fb_helper);
exynos_drm_fbdev_destroy(dev, private->fb_helper);
kfree(fbdev);
private->fb_helper = NULL;
}
void exynos_drm_fbdev_restore_mode(struct drm_device *dev)
{
struct exynos_drm_private *private = dev->dev_private;
if (!private || !private->fb_helper)
return;
drm_fb_helper_restore_fbdev_mode(private->fb_helper);
}
int exynos_drm_fbdev_reinit(struct drm_device *dev)
{
struct exynos_drm_private *private = dev->dev_private;
struct drm_fb_helper *fb_helper;
int ret;
if (!private)
return -EINVAL;
if (!dev->mode_config.num_connector) {
exynos_drm_fbdev_fini(dev);
return 0;
}
fb_helper = private->fb_helper;
if (fb_helper) {
struct list_head temp_list;
INIT_LIST_HEAD(&temp_list);
if (!list_empty(&fb_helper->kernel_fb_list))
list_replace_init(&fb_helper->kernel_fb_list,
&temp_list);
drm_fb_helper_fini(fb_helper);
ret = drm_fb_helper_init(dev, fb_helper,
dev->mode_config.num_crtc, MAX_CONNECTOR);
if (ret < 0) {
DRM_ERROR("failed to initialize drm fb helper\n");
return ret;
}
if (!list_empty(&temp_list))
list_replace(&temp_list, &fb_helper->kernel_fb_list);
ret = drm_fb_helper_single_add_all_connectors(fb_helper);
if (ret < 0) {
DRM_ERROR("failed to add fb helper to connectors\n");
goto err;
}
ret = drm_fb_helper_initial_config(fb_helper, PREFERRED_BPP);
if (ret < 0) {
DRM_ERROR("failed to set up hw configuration.\n");
goto err;
}
} else {
ret = exynos_drm_fbdev_init(dev);
}
return ret;
err:
if (fb_helper)
drm_fb_helper_fini(fb_helper);
return ret;
}
