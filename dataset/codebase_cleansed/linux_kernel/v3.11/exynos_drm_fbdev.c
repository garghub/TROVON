static int exynos_drm_fb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
struct drm_fb_helper *helper = info->par;
struct exynos_drm_fbdev *exynos_fbd = to_exynos_fbdev(helper);
struct exynos_drm_gem_obj *exynos_gem_obj = exynos_fbd->exynos_gem_obj;
struct exynos_drm_gem_buf *buffer = exynos_gem_obj->buffer;
unsigned long vm_size;
int ret;
vma->vm_flags |= VM_IO | VM_DONTEXPAND | VM_DONTDUMP;
vm_size = vma->vm_end - vma->vm_start;
if (vm_size > buffer->size)
return -EINVAL;
ret = dma_mmap_attrs(helper->dev->dev, vma, buffer->pages,
buffer->dma_addr, buffer->size, &buffer->dma_attrs);
if (ret < 0) {
DRM_ERROR("failed to mmap.\n");
return ret;
}
return 0;
}
static int exynos_drm_fbdev_update(struct drm_fb_helper *helper,
struct drm_framebuffer *fb)
{
struct fb_info *fbi = helper->fbdev;
struct drm_device *dev = helper->dev;
struct exynos_drm_gem_buf *buffer;
unsigned int size = fb->width * fb->height * (fb->bits_per_pixel >> 3);
unsigned long offset;
drm_fb_helper_fill_fix(fbi, fb->pitches[0], fb->depth);
drm_fb_helper_fill_var(fbi, helper, fb->width, fb->height);
buffer = exynos_drm_fb_buffer(fb, 0);
if (!buffer) {
DRM_LOG_KMS("buffer is null.\n");
return -EFAULT;
}
if (!buffer->kvaddr) {
if (is_drm_iommu_supported(dev)) {
unsigned int nr_pages = buffer->size >> PAGE_SHIFT;
buffer->kvaddr = vmap(buffer->pages, nr_pages, VM_MAP,
pgprot_writecombine(PAGE_KERNEL));
} else {
phys_addr_t dma_addr = buffer->dma_addr;
if (dma_addr)
buffer->kvaddr = phys_to_virt(dma_addr);
else
buffer->kvaddr = (void __iomem *)NULL;
}
if (!buffer->kvaddr) {
DRM_ERROR("failed to map pages to kernel space.\n");
return -EIO;
}
}
exynos_drm_fb_set_buf_cnt(fb, 1);
offset = fbi->var.xoffset * (fb->bits_per_pixel >> 3);
offset += fbi->var.yoffset * fb->pitches[0];
dev->mode_config.fb_base = (resource_size_t)buffer->dma_addr;
fbi->screen_base = buffer->kvaddr + offset;
if (is_drm_iommu_supported(dev))
fbi->fix.smem_start = (unsigned long)
(page_to_phys(sg_page(buffer->sgt->sgl)) + offset);
else
fbi->fix.smem_start = (unsigned long)buffer->dma_addr;
fbi->screen_size = size;
fbi->fix.smem_len = size;
return 0;
}
static int exynos_drm_fbdev_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct exynos_drm_fbdev *exynos_fbdev = to_exynos_fbdev(helper);
struct exynos_drm_gem_obj *exynos_gem_obj;
struct drm_device *dev = helper->dev;
struct fb_info *fbi;
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
mutex_lock(&dev->struct_mutex);
fbi = framebuffer_alloc(0, &pdev->dev);
if (!fbi) {
DRM_ERROR("failed to allocate fb info.\n");
ret = -ENOMEM;
goto out;
}
size = mode_cmd.pitches[0] * mode_cmd.height;
exynos_gem_obj = exynos_drm_gem_create(dev, 0, size);
if (IS_ERR(exynos_gem_obj)) {
ret = PTR_ERR(exynos_gem_obj);
goto err_release_framebuffer;
}
exynos_fbdev->exynos_gem_obj = exynos_gem_obj;
helper->fb = exynos_drm_framebuffer_init(dev, &mode_cmd,
&exynos_gem_obj->base);
if (IS_ERR(helper->fb)) {
DRM_ERROR("failed to create drm framebuffer.\n");
ret = PTR_ERR(helper->fb);
goto err_destroy_gem;
}
helper->fbdev = fbi;
fbi->par = helper;
fbi->flags = FBINFO_FLAG_DEFAULT;
fbi->fbops = &exynos_drm_fb_ops;
ret = fb_alloc_cmap(&fbi->cmap, 256, 0);
if (ret) {
DRM_ERROR("failed to allocate cmap.\n");
goto err_destroy_framebuffer;
}
ret = exynos_drm_fbdev_update(helper, helper->fb);
if (ret < 0)
goto err_dealloc_cmap;
mutex_unlock(&dev->struct_mutex);
return ret;
err_dealloc_cmap:
fb_dealloc_cmap(&fbi->cmap);
err_destroy_framebuffer:
drm_framebuffer_cleanup(helper->fb);
err_destroy_gem:
exynos_drm_gem_destroy(exynos_gem_obj);
err_release_framebuffer:
framebuffer_release(fbi);
out:
mutex_unlock(&dev->struct_mutex);
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
drm_helper_disable_unused_functions(dev);
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
struct exynos_drm_gem_obj *exynos_gem_obj = exynos_fbd->exynos_gem_obj;
struct drm_framebuffer *fb;
if (is_drm_iommu_supported(dev) && exynos_gem_obj->buffer->kvaddr)
vunmap(exynos_gem_obj->buffer->kvaddr);
if (fb_helper->fb && fb_helper->fb->funcs) {
fb = fb_helper->fb;
if (fb) {
drm_framebuffer_unregister_private(fb);
drm_framebuffer_remove(fb);
}
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
if (fbdev->exynos_gem_obj)
exynos_drm_gem_destroy(fbdev->exynos_gem_obj);
exynos_drm_fbdev_destroy(dev, private->fb_helper);
kfree(fbdev);
private->fb_helper = NULL;
}
void exynos_drm_fbdev_restore_mode(struct drm_device *dev)
{
struct exynos_drm_private *private = dev->dev_private;
if (!private || !private->fb_helper)
return;
drm_modeset_lock_all(dev);
drm_fb_helper_restore_fbdev_mode(private->fb_helper);
drm_modeset_unlock_all(dev);
}
