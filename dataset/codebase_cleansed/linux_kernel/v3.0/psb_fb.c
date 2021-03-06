void *psbfb_vdc_reg(struct drm_device *dev)
{
struct drm_psb_private *dev_priv;
dev_priv = (struct drm_psb_private *) dev->dev_private;
return dev_priv->vdc_reg;
}
static int psbfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct psb_fbdev *fbdev = info->par;
struct drm_framebuffer *fb = fbdev->psb_fb_helper.fb;
uint32_t v;
if (!fb)
return -ENOMEM;
if (regno > 255)
return 1;
red = CMAP_TOHW(red, info->var.red.length);
blue = CMAP_TOHW(blue, info->var.blue.length);
green = CMAP_TOHW(green, info->var.green.length);
transp = CMAP_TOHW(transp, info->var.transp.length);
v = (red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset) |
(transp << info->var.transp.offset);
if (regno < 16) {
switch (fb->bits_per_pixel) {
case 16:
((uint32_t *) info->pseudo_palette)[regno] = v;
break;
case 24:
case 32:
((uint32_t *) info->pseudo_palette)[regno] = v;
break;
}
}
return 0;
}
static int psbfb_kms_off(struct drm_device *dev, int suspend)
{
struct drm_framebuffer *fb = 0;
struct psb_framebuffer *psbfb = to_psb_fb(fb);
DRM_DEBUG("psbfb_kms_off_ioctl\n");
mutex_lock(&dev->mode_config.mutex);
list_for_each_entry(fb, &dev->mode_config.fb_list, head) {
struct fb_info *info = psbfb->fbdev;
if (suspend) {
fb_set_suspend(info, 1);
drm_fb_helper_blank(FB_BLANK_POWERDOWN, info);
}
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
int psbfb_kms_off_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret;
if (drm_psb_no_fb)
return 0;
console_lock();
ret = psbfb_kms_off(dev, 0);
console_unlock();
return ret;
}
static int psbfb_kms_on(struct drm_device *dev, int resume)
{
struct drm_framebuffer *fb = 0;
struct psb_framebuffer *psbfb = to_psb_fb(fb);
DRM_DEBUG("psbfb_kms_on_ioctl\n");
mutex_lock(&dev->mode_config.mutex);
list_for_each_entry(fb, &dev->mode_config.fb_list, head) {
struct fb_info *info = psbfb->fbdev;
if (resume) {
fb_set_suspend(info, 0);
drm_fb_helper_blank(FB_BLANK_UNBLANK, info);
}
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
int psbfb_kms_on_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret;
if (drm_psb_no_fb)
return 0;
console_lock();
ret = psbfb_kms_on(dev, 0);
console_unlock();
drm_helper_disable_unused_functions(dev);
return ret;
}
void psbfb_suspend(struct drm_device *dev)
{
console_lock();
psbfb_kms_off(dev, 1);
console_unlock();
}
void psbfb_resume(struct drm_device *dev)
{
console_lock();
psbfb_kms_on(dev, 1);
console_unlock();
drm_helper_disable_unused_functions(dev);
}
static int psbfb_vm_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
int page_num = 0;
int i;
unsigned long address = 0;
int ret;
unsigned long pfn;
struct psb_framebuffer *psbfb = vma->vm_private_data;
struct drm_device *dev = psbfb->base.dev;
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned long phys_addr = (unsigned long)dev_priv->stolen_base;
page_num = (vma->vm_end - vma->vm_start) >> PAGE_SHIFT;
address = (unsigned long)vmf->virtual_address;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
for (i = 0; i < page_num; i++) {
pfn = (phys_addr >> PAGE_SHIFT);
ret = vm_insert_mixed(vma, address, pfn);
if (unlikely((ret == -EBUSY) || (ret != 0 && i > 0)))
break;
else if (unlikely(ret != 0)) {
ret = (ret == -ENOMEM) ? VM_FAULT_OOM : VM_FAULT_SIGBUS;
return ret;
}
address += PAGE_SIZE;
phys_addr += PAGE_SIZE;
}
return VM_FAULT_NOPAGE;
}
static void psbfb_vm_open(struct vm_area_struct *vma)
{
DRM_DEBUG("vm_open\n");
}
static void psbfb_vm_close(struct vm_area_struct *vma)
{
DRM_DEBUG("vm_close\n");
}
static int psbfb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct psb_fbdev *fbdev = info->par;
struct psb_framebuffer *psbfb = fbdev->pfb;
char *fb_screen_base = NULL;
struct drm_device *dev = psbfb->base.dev;
struct drm_psb_private *dev_priv = dev->dev_private;
if (vma->vm_pgoff != 0)
return -EINVAL;
if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT))
return -EINVAL;
if (!psbfb->addr_space)
psbfb->addr_space = vma->vm_file->f_mapping;
fb_screen_base = (char *)info->screen_base;
DRM_DEBUG("vm_pgoff 0x%lx, screen base %p vram_addr %p\n",
vma->vm_pgoff, fb_screen_base,
dev_priv->vram_addr);
if (1 || fb_screen_base == dev_priv->vram_addr) {
vma->vm_ops = &psbfb_vm_ops;
vma->vm_private_data = (void *)psbfb;
vma->vm_flags |= VM_RESERVED | VM_IO |
VM_MIXEDMAP | VM_DONTEXPAND;
} else {
}
return 0;
}
static int psbfb_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
struct psb_fbdev *fbdev = info->par;
struct psb_framebuffer *psbfb = fbdev->pfb;
struct drm_device *dev = psbfb->base.dev;
struct drm_psb_private *dev_priv = dev->dev_private;
u32 __user *p = (u32 __user *)arg;
u32 l;
u32 buf[32];
switch (cmd) {
case 0x12345678:
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
if (get_user(l, p))
return -EFAULT;
if (l > 32)
return -EMSGSIZE;
if (copy_from_user(buf, p + 1, l * sizeof(u32)))
return -EFAULT;
psbfb_2d_submit(dev_priv, buf, l);
return 0;
default:
return -ENOTTY;
}
}
static struct drm_framebuffer *psb_framebuffer_create
(struct drm_device *dev, struct drm_mode_fb_cmd *r,
struct gtt_range *gt)
{
struct psb_framebuffer *fb;
int ret;
fb = kzalloc(sizeof(*fb), GFP_KERNEL);
if (!fb)
return NULL;
ret = drm_framebuffer_init(dev, &fb->base, &psb_fb_funcs);
if (ret)
goto err;
drm_helper_mode_fill_fb_struct(&fb->base, r);
fb->gtt = gt;
return &fb->base;
err:
kfree(fb);
return NULL;
}
static struct gtt_range *psbfb_alloc(struct drm_device *dev, int aligned_size)
{
struct gtt_range *backing;
backing = psb_gtt_alloc_range(dev, aligned_size, "fb", 1);
if (backing)
return backing;
backing = psb_gtt_alloc_range(dev, aligned_size, "fb(gem)", 0);
if (backing == NULL)
return NULL;
if (drm_gem_object_init(dev, &backing->gem, aligned_size) != 0) {
psb_gtt_free_range(dev, backing);
return NULL;
}
return backing;
}
static int psbfb_create(struct psb_fbdev *fbdev,
struct drm_fb_helper_surface_size *sizes)
{
struct drm_device *dev = fbdev->psb_fb_helper.dev;
struct drm_psb_private *dev_priv = dev->dev_private;
struct fb_info *info;
struct drm_framebuffer *fb;
struct psb_framebuffer *psbfb;
struct drm_mode_fb_cmd mode_cmd;
struct device *device = &dev->pdev->dev;
int size, aligned_size;
int ret;
struct gtt_range *backing;
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.bpp = 32;
mode_cmd.pitch = ALIGN(mode_cmd.width * ((mode_cmd.bpp + 1) / 8), 64);
mode_cmd.depth = 24;
size = mode_cmd.pitch * mode_cmd.height;
aligned_size = ALIGN(size, PAGE_SIZE);
backing = psbfb_alloc(dev, aligned_size);
if (backing == NULL)
return -ENOMEM;
mutex_lock(&dev->struct_mutex);
fb = psb_framebuffer_create(dev, &mode_cmd, backing);
if (!fb) {
DRM_ERROR("failed to allocate fb.\n");
ret = -ENOMEM;
goto out_err1;
}
psbfb = to_psb_fb(fb);
info = framebuffer_alloc(sizeof(struct psb_fbdev), device);
if (!info) {
ret = -ENOMEM;
goto out_err0;
}
info->par = fbdev;
psbfb->fbdev = info;
fbdev->psb_fb_helper.fb = fb;
fbdev->psb_fb_helper.fbdev = info;
fbdev->pfb = psbfb;
strcpy(info->fix.id, "psbfb");
info->flags = FBINFO_DEFAULT;
info->fbops = &psbfb_ops;
info->fix.smem_start = dev->mode_config.fb_base;
info->fix.smem_len = size;
info->screen_base = (char *)dev_priv->vram_addr + backing->offset;
info->screen_size = size;
memset(info->screen_base, 0, size);
if (dev_priv->pg->stolen_size) {
info->apertures = alloc_apertures(1);
if (!info->apertures) {
ret = -ENOMEM;
goto out_err0;
}
info->apertures->ranges[0].base = dev->mode_config.fb_base;
info->apertures->ranges[0].size = dev_priv->pg->stolen_size;
}
drm_fb_helper_fill_fix(info, fb->pitch, fb->depth);
drm_fb_helper_fill_var(info, &fbdev->psb_fb_helper,
sizes->fb_width, sizes->fb_height);
info->fix.mmio_start = pci_resource_start(dev->pdev, 0);
info->fix.mmio_len = pci_resource_len(dev->pdev, 0);
info->pixmap.size = 64 * 1024;
info->pixmap.buf_align = 8;
info->pixmap.access_align = 32;
info->pixmap.flags = FB_PIXMAP_SYSTEM;
info->pixmap.scan_align = 1;
DRM_DEBUG("fb depth is %d\n", fb->depth);
DRM_DEBUG(" pitch is %d\n", fb->pitch);
printk(KERN_INFO"allocated %dx%d fb\n",
psbfb->base.width, psbfb->base.height);
mutex_unlock(&dev->struct_mutex);
return 0;
out_err0:
fb->funcs->destroy(fb);
out_err1:
mutex_unlock(&dev->struct_mutex);
psb_gtt_free_range(dev, backing);
return ret;
}
static struct drm_framebuffer *psb_user_framebuffer_create
(struct drm_device *dev, struct drm_file *filp,
struct drm_mode_fb_cmd *cmd)
{
struct gtt_range *r;
struct drm_gem_object *obj;
struct psb_framebuffer *psbfb;
obj = drm_gem_object_lookup(dev, filp, cmd->handle);
if (obj == NULL)
return ERR_PTR(-ENOENT);
psbfb = kzalloc(sizeof(*psbfb), GFP_KERNEL);
if (psbfb == NULL) {
drm_gem_object_unreference_unlocked(obj);
return ERR_PTR(-ENOMEM);
}
r = container_of(obj, struct gtt_range, gem);
if (psb_framebuffer_create(dev, cmd, r) == NULL) {
drm_gem_object_unreference_unlocked(obj);
kfree(psbfb);
return ERR_PTR(-EINVAL);
}
return &psbfb->base;
}
static void psbfb_gamma_set(struct drm_crtc *crtc, u16 red, u16 green,
u16 blue, int regno)
{
DRM_DEBUG("%s\n", __func__);
}
static void psbfb_gamma_get(struct drm_crtc *crtc, u16 *red,
u16 *green, u16 *blue, int regno)
{
DRM_DEBUG("%s\n", __func__);
}
static int psbfb_probe(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct psb_fbdev *psb_fbdev = (struct psb_fbdev *)helper;
int new_fb = 0;
int ret;
DRM_DEBUG("%s\n", __func__);
if (!helper->fb) {
ret = psbfb_create(psb_fbdev, sizes);
if (ret)
return ret;
new_fb = 1;
}
return new_fb;
}
int psb_fbdev_destroy(struct drm_device *dev, struct psb_fbdev *fbdev)
{
struct fb_info *info;
struct psb_framebuffer *psbfb = fbdev->pfb;
if (fbdev->psb_fb_helper.fbdev) {
info = fbdev->psb_fb_helper.fbdev;
if (psbfb->gtt->stolen)
psb_gtt_free_range(dev, psbfb->gtt);
else
drm_gem_object_unreference(&psbfb->gtt->gem);
unregister_framebuffer(info);
iounmap(info->screen_base);
framebuffer_release(info);
}
drm_fb_helper_fini(&fbdev->psb_fb_helper);
drm_framebuffer_cleanup(&psbfb->base);
return 0;
}
int psb_fbdev_init(struct drm_device *dev)
{
struct psb_fbdev *fbdev;
struct drm_psb_private *dev_priv = dev->dev_private;
int num_crtc;
fbdev = kzalloc(sizeof(struct psb_fbdev), GFP_KERNEL);
if (!fbdev) {
DRM_ERROR("no memory\n");
return -ENOMEM;
}
dev_priv->fbdev = fbdev;
fbdev->psb_fb_helper.funcs = &psb_fb_helper_funcs;
num_crtc = 2;
drm_fb_helper_init(dev, &fbdev->psb_fb_helper, num_crtc,
INTELFB_CONN_LIMIT);
drm_fb_helper_single_add_all_connectors(&fbdev->psb_fb_helper);
drm_fb_helper_initial_config(&fbdev->psb_fb_helper, 32);
return 0;
}
void psb_fbdev_fini(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (!dev_priv->fbdev)
return;
psb_fbdev_destroy(dev, dev_priv->fbdev);
kfree(dev_priv->fbdev);
dev_priv->fbdev = NULL;
}
static void psbfb_output_poll_changed(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_fbdev *fbdev = (struct psb_fbdev *)dev_priv->fbdev;
drm_fb_helper_hotplug_event(&fbdev->psb_fb_helper);
}
int psbfb_remove(struct drm_device *dev, struct drm_framebuffer *fb)
{
struct fb_info *info;
struct psb_framebuffer *psbfb = to_psb_fb(fb);
if (drm_psb_no_fb)
return 0;
info = psbfb->fbdev;
if (info)
framebuffer_release(info);
return 0;
}
static int psb_user_framebuffer_create_handle(struct drm_framebuffer *fb,
struct drm_file *file_priv,
unsigned int *handle)
{
struct psb_framebuffer *psbfb = to_psb_fb(fb);
struct gtt_range *r = psbfb->gtt;
if (r->stolen)
return -EOPNOTSUPP;
return drm_gem_handle_create(file_priv, &r->gem, handle);
}
static void psb_user_framebuffer_destroy(struct drm_framebuffer *fb)
{
struct drm_device *dev = fb->dev;
struct psb_framebuffer *psbfb = to_psb_fb(fb);
struct gtt_range *r = psbfb->gtt;
if (psbfb->fbdev)
psbfb_remove(dev, fb);
drm_framebuffer_cleanup(fb);
drm_gem_object_unreference_unlocked(&r->gem);
kfree(fb);
}
static int psb_create_backlight_property(struct drm_device *dev)
{
struct drm_psb_private *dev_priv
= (struct drm_psb_private *) dev->dev_private;
struct drm_property *backlight;
if (dev_priv->backlight_property)
return 0;
backlight = drm_property_create(dev,
DRM_MODE_PROP_RANGE,
"backlight",
2);
backlight->values[0] = 0;
backlight->values[1] = 100;
dev_priv->backlight_property = backlight;
return 0;
}
static void psb_setup_outputs(struct drm_device *dev)
{
struct drm_psb_private *dev_priv =
(struct drm_psb_private *) dev->dev_private;
struct drm_connector *connector;
PSB_DEBUG_ENTRY("\n");
drm_mode_create_scaling_mode_property(dev);
psb_create_backlight_property(dev);
if (IS_MRST(dev)) {
if (dev_priv->iLVDS_enable)
mrst_lvds_init(dev, &dev_priv->mode_dev);
else
DRM_ERROR("DSI is not supported\n");
} else {
psb_intel_lvds_init(dev, &dev_priv->mode_dev);
psb_intel_sdvo_init(dev, SDVOB);
}
list_for_each_entry(connector, &dev->mode_config.connector_list,
head) {
struct psb_intel_output *psb_intel_output =
to_psb_intel_output(connector);
struct drm_encoder *encoder = &psb_intel_output->enc;
int crtc_mask = 0, clone_mask = 0;
switch (psb_intel_output->type) {
case INTEL_OUTPUT_SDVO:
crtc_mask = ((1 << 0) | (1 << 1));
clone_mask = (1 << INTEL_OUTPUT_SDVO);
break;
case INTEL_OUTPUT_LVDS:
PSB_DEBUG_ENTRY("LVDS.\n");
if (IS_MRST(dev))
crtc_mask = (1 << 0);
else
crtc_mask = (1 << 1);
clone_mask = (1 << INTEL_OUTPUT_LVDS);
break;
case INTEL_OUTPUT_MIPI:
PSB_DEBUG_ENTRY("MIPI.\n");
crtc_mask = (1 << 0);
clone_mask = (1 << INTEL_OUTPUT_MIPI);
break;
case INTEL_OUTPUT_MIPI2:
PSB_DEBUG_ENTRY("MIPI2.\n");
crtc_mask = (1 << 2);
clone_mask = (1 << INTEL_OUTPUT_MIPI2);
break;
case INTEL_OUTPUT_HDMI:
PSB_DEBUG_ENTRY("HDMI.\n");
crtc_mask = (1 << 1);
clone_mask = (1 << INTEL_OUTPUT_HDMI);
break;
}
encoder->possible_crtcs = crtc_mask;
encoder->possible_clones =
psb_intel_connector_clones(dev, clone_mask);
}
}
void psb_modeset_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv =
(struct drm_psb_private *) dev->dev_private;
struct psb_intel_mode_device *mode_dev = &dev_priv->mode_dev;
int i;
PSB_DEBUG_ENTRY("\n");
drm_mode_config_init(dev);
dev->mode_config.min_width = 0;
dev->mode_config.min_height = 0;
dev->mode_config.funcs = (void *) &psb_mode_funcs;
pci_read_config_dword(dev->pdev, PSB_BSM, (u32 *)
&(dev->mode_config.fb_base));
for (i = 0; i < dev_priv->num_pipe; i++)
psb_intel_crtc_init(dev, i, mode_dev);
dev->mode_config.max_width = 2048;
dev->mode_config.max_height = 2048;
psb_setup_outputs(dev);
}
void psb_modeset_cleanup(struct drm_device *dev)
{
mutex_lock(&dev->struct_mutex);
drm_kms_helper_poll_fini(dev);
psb_fbdev_fini(dev);
drm_mode_config_cleanup(dev);
mutex_unlock(&dev->struct_mutex);
}
