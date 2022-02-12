static int exynos_drm_fb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
struct drm_fb_helper *helper = info->par;
struct exynos_drm_fbdev *exynos_fbd = to_exynos_fbdev(helper);
struct exynos_drm_gem *exynos_gem = exynos_fbd->exynos_gem;
unsigned long vm_size;
int ret;
vma->vm_flags |= VM_IO | VM_DONTEXPAND | VM_DONTDUMP;
vm_size = vma->vm_end - vma->vm_start;
if (vm_size > exynos_gem->size)
return -EINVAL;
ret = dma_mmap_attrs(to_dma_dev(helper->dev), vma, exynos_gem->cookie,
exynos_gem->dma_addr, exynos_gem->size,
&exynos_gem->dma_attrs);
if (ret < 0) {
DRM_ERROR("failed to mmap.\n");
return ret;
}
return 0;
}
static int exynos_drm_fbdev_update(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes,
struct exynos_drm_gem *exynos_gem)
{
struct fb_info *fbi;
struct drm_framebuffer *fb = helper->fb;
unsigned int size = fb->width * fb->height * (fb->bits_per_pixel >> 3);
unsigned int nr_pages;
unsigned long offset;
fbi = drm_fb_helper_alloc_fbi(helper);
if (IS_ERR(fbi)) {
DRM_ERROR("failed to allocate fb info.\n");
return PTR_ERR(fbi);
}
fbi->par = helper;
fbi->flags = FBINFO_FLAG_DEFAULT;
fbi->fbops = &exynos_drm_fb_ops;
drm_fb_helper_fill_fix(fbi, fb->pitches[0], fb->depth);
drm_fb_helper_fill_var(fbi, helper, sizes->fb_width, sizes->fb_height);
nr_pages = exynos_gem->size >> PAGE_SHIFT;
exynos_gem->kvaddr = (void __iomem *) vmap(exynos_gem->pages, nr_pages,
VM_MAP, pgprot_writecombine(PAGE_KERNEL));
if (!exynos_gem->kvaddr) {
DRM_ERROR("failed to map pages to kernel space.\n");
drm_fb_helper_release_fbi(helper);
return -EIO;
}
offset = fbi->var.xoffset * (fb->bits_per_pixel >> 3);
offset += fbi->var.yoffset * fb->pitches[0];
fbi->screen_base = exynos_gem->kvaddr + offset;
fbi->screen_size = size;
fbi->fix.smem_len = size;
return 0;
}
static int exynos_drm_fbdev_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct exynos_drm_fbdev *exynos_fbdev = to_exynos_fbdev(helper);
struct exynos_drm_gem *exynos_gem;
struct drm_device *dev = helper->dev;
struct drm_mode_fb_cmd2 mode_cmd = { 0 };
struct platform_device *pdev = dev->platformdev;
unsigned long size;
int ret;
DRM_DEBUG_KMS("surface width(%d), height(%d) and bpp(%d\n",
sizes->surface_width, sizes->surface_height,
sizes->surface_bpp);
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = sizes->surface_width * (sizes->surface_bpp >> 3);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
size = mode_cmd.pitches[0] * mode_cmd.height;
exynos_gem = exynos_drm_gem_create(dev, EXYNOS_BO_CONTIG, size);
if (IS_ERR(exynos_gem) && is_drm_iommu_supported(dev)) {
dev_warn(&pdev->dev, "contiguous FB allocation failed, falling back to non-contiguous\n");
exynos_gem = exynos_drm_gem_create(dev, EXYNOS_BO_NONCONTIG,
size);
}
if (IS_ERR(exynos_gem))
return PTR_ERR(exynos_gem);
exynos_fbdev->exynos_gem = exynos_gem;
helper->fb =
exynos_drm_framebuffer_init(dev, &mode_cmd, &exynos_gem, 1);
if (IS_ERR(helper->fb)) {
DRM_ERROR("failed to create drm framebuffer.\n");
ret = PTR_ERR(helper->fb);
goto err_destroy_gem;
}
ret = exynos_drm_fbdev_update(helper, sizes, exynos_gem);
if (ret < 0)
goto err_destroy_framebuffer;
return ret;
err_destroy_framebuffer:
drm_framebuffer_cleanup(helper->fb);
err_destroy_gem:
exynos_drm_gem_destroy(exynos_gem);
return ret;
}
static bool exynos_drm_fbdev_is_anything_connected(struct drm_device *dev)
{
struct drm_connector *connector;
bool ret = false;
mutex_lock(&dev->mode_config.mutex);
list_for_each_entry(connector, &dev->mode_config.connector_list, head) {
if (connector->status != connector_status_connected)
continue;
ret = true;
break;
}
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
int exynos_drm_fbdev_init(struct drm_device *dev)
{
struct exynos_drm_fbdev *fbdev;
struct exynos_drm_private *private = dev->dev_private;
struct drm_fb_helper *helper;
unsigned int num_crtc;
int ret;
if (!dev->mode_config.num_crtc || !dev->mode_config.num_connector)
return 0;
if (!exynos_drm_fbdev_is_anything_connected(dev))
return 0;
fbdev = kzalloc(sizeof(*fbdev), GFP_KERNEL);
if (!fbdev)
return -ENOMEM;
private->fb_helper = helper = &fbdev->drm_fb_helper;
drm_fb_helper_prepare(dev, helper, &exynos_drm_fb_helper_funcs);
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
struct exynos_drm_fbdev *exynos_fbd = to_exynos_fbdev(fb_helper);
struct exynos_drm_gem *exynos_gem = exynos_fbd->exynos_gem;
struct drm_framebuffer *fb;
if (exynos_gem->kvaddr)
vunmap(exynos_gem->kvaddr);
if (fb_helper->fb && fb_helper->fb->funcs) {
fb = fb_helper->fb;
if (fb) {
drm_framebuffer_unregister_private(fb);
drm_framebuffer_remove(fb);
}
}
drm_fb_helper_unregister_fbi(fb_helper);
drm_fb_helper_release_fbi(fb_helper);
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
drm_fb_helper_restore_fbdev_mode_unlocked(private->fb_helper);
}
void exynos_drm_output_poll_changed(struct drm_device *dev)
{
struct exynos_drm_private *private = dev->dev_private;
struct drm_fb_helper *fb_helper = private->fb_helper;
if (fb_helper)
drm_fb_helper_hotplug_event(fb_helper);
else
exynos_drm_fbdev_init(dev);
}
