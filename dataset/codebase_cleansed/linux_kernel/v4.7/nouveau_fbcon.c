static void
nouveau_fbcon_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct nouveau_fbdev *fbcon = info->par;
struct nouveau_drm *drm = nouveau_drm(fbcon->dev);
struct nvif_device *device = &drm->device;
int ret;
if (info->state != FBINFO_STATE_RUNNING)
return;
ret = -ENODEV;
if (!in_interrupt() && !(info->flags & FBINFO_HWACCEL_DISABLED) &&
mutex_trylock(&drm->client.mutex)) {
if (device->info.family < NV_DEVICE_INFO_V0_TESLA)
ret = nv04_fbcon_fillrect(info, rect);
else
if (device->info.family < NV_DEVICE_INFO_V0_FERMI)
ret = nv50_fbcon_fillrect(info, rect);
else
ret = nvc0_fbcon_fillrect(info, rect);
mutex_unlock(&drm->client.mutex);
}
if (ret == 0)
return;
if (ret != -ENODEV)
nouveau_fbcon_gpu_lockup(info);
drm_fb_helper_cfb_fillrect(info, rect);
}
static void
nouveau_fbcon_copyarea(struct fb_info *info, const struct fb_copyarea *image)
{
struct nouveau_fbdev *fbcon = info->par;
struct nouveau_drm *drm = nouveau_drm(fbcon->dev);
struct nvif_device *device = &drm->device;
int ret;
if (info->state != FBINFO_STATE_RUNNING)
return;
ret = -ENODEV;
if (!in_interrupt() && !(info->flags & FBINFO_HWACCEL_DISABLED) &&
mutex_trylock(&drm->client.mutex)) {
if (device->info.family < NV_DEVICE_INFO_V0_TESLA)
ret = nv04_fbcon_copyarea(info, image);
else
if (device->info.family < NV_DEVICE_INFO_V0_FERMI)
ret = nv50_fbcon_copyarea(info, image);
else
ret = nvc0_fbcon_copyarea(info, image);
mutex_unlock(&drm->client.mutex);
}
if (ret == 0)
return;
if (ret != -ENODEV)
nouveau_fbcon_gpu_lockup(info);
drm_fb_helper_cfb_copyarea(info, image);
}
static void
nouveau_fbcon_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct nouveau_fbdev *fbcon = info->par;
struct nouveau_drm *drm = nouveau_drm(fbcon->dev);
struct nvif_device *device = &drm->device;
int ret;
if (info->state != FBINFO_STATE_RUNNING)
return;
ret = -ENODEV;
if (!in_interrupt() && !(info->flags & FBINFO_HWACCEL_DISABLED) &&
mutex_trylock(&drm->client.mutex)) {
if (device->info.family < NV_DEVICE_INFO_V0_TESLA)
ret = nv04_fbcon_imageblit(info, image);
else
if (device->info.family < NV_DEVICE_INFO_V0_FERMI)
ret = nv50_fbcon_imageblit(info, image);
else
ret = nvc0_fbcon_imageblit(info, image);
mutex_unlock(&drm->client.mutex);
}
if (ret == 0)
return;
if (ret != -ENODEV)
nouveau_fbcon_gpu_lockup(info);
drm_fb_helper_cfb_imageblit(info, image);
}
static int
nouveau_fbcon_sync(struct fb_info *info)
{
struct nouveau_fbdev *fbcon = info->par;
struct nouveau_drm *drm = nouveau_drm(fbcon->dev);
struct nouveau_channel *chan = drm->channel;
int ret;
if (!chan || !chan->accel_done || in_interrupt() ||
info->state != FBINFO_STATE_RUNNING ||
info->flags & FBINFO_HWACCEL_DISABLED)
return 0;
if (!mutex_trylock(&drm->client.mutex))
return 0;
ret = nouveau_channel_idle(chan);
mutex_unlock(&drm->client.mutex);
if (ret) {
nouveau_fbcon_gpu_lockup(info);
return 0;
}
chan->accel_done = false;
return 0;
}
static int
nouveau_fbcon_open(struct fb_info *info, int user)
{
struct nouveau_fbdev *fbcon = info->par;
struct nouveau_drm *drm = nouveau_drm(fbcon->dev);
int ret = pm_runtime_get_sync(drm->dev->dev);
if (ret < 0 && ret != -EACCES)
return ret;
return 0;
}
static int
nouveau_fbcon_release(struct fb_info *info, int user)
{
struct nouveau_fbdev *fbcon = info->par;
struct nouveau_drm *drm = nouveau_drm(fbcon->dev);
pm_runtime_put(drm->dev->dev);
return 0;
}
void
nouveau_fbcon_accel_save_disable(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (drm->fbcon) {
drm->fbcon->saved_flags = drm->fbcon->helper.fbdev->flags;
drm->fbcon->helper.fbdev->flags |= FBINFO_HWACCEL_DISABLED;
}
}
void
nouveau_fbcon_accel_restore(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (drm->fbcon) {
drm->fbcon->helper.fbdev->flags = drm->fbcon->saved_flags;
}
}
static void
nouveau_fbcon_accel_fini(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_fbdev *fbcon = drm->fbcon;
if (fbcon && drm->channel) {
console_lock();
fbcon->helper.fbdev->flags |= FBINFO_HWACCEL_DISABLED;
console_unlock();
nouveau_channel_idle(drm->channel);
nvif_object_fini(&fbcon->twod);
nvif_object_fini(&fbcon->blit);
nvif_object_fini(&fbcon->gdi);
nvif_object_fini(&fbcon->patt);
nvif_object_fini(&fbcon->rop);
nvif_object_fini(&fbcon->clip);
nvif_object_fini(&fbcon->surf2d);
}
}
static void
nouveau_fbcon_accel_init(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_fbdev *fbcon = drm->fbcon;
struct fb_info *info = fbcon->helper.fbdev;
int ret;
if (drm->device.info.family < NV_DEVICE_INFO_V0_TESLA)
ret = nv04_fbcon_accel_init(info);
else
if (drm->device.info.family < NV_DEVICE_INFO_V0_FERMI)
ret = nv50_fbcon_accel_init(info);
else
ret = nvc0_fbcon_accel_init(info);
if (ret == 0)
info->fbops = &nouveau_fbcon_ops;
}
static void nouveau_fbcon_gamma_set(struct drm_crtc *crtc, u16 red, u16 green,
u16 blue, int regno)
{
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
nv_crtc->lut.r[regno] = red;
nv_crtc->lut.g[regno] = green;
nv_crtc->lut.b[regno] = blue;
}
static void nouveau_fbcon_gamma_get(struct drm_crtc *crtc, u16 *red, u16 *green,
u16 *blue, int regno)
{
struct nouveau_crtc *nv_crtc = nouveau_crtc(crtc);
*red = nv_crtc->lut.r[regno];
*green = nv_crtc->lut.g[regno];
*blue = nv_crtc->lut.b[regno];
}
static void
nouveau_fbcon_zfill(struct drm_device *dev, struct nouveau_fbdev *fbcon)
{
struct fb_info *info = fbcon->helper.fbdev;
struct fb_fillrect rect;
rect.dx = rect.dy = 0;
rect.width = info->var.xres_virtual;
rect.height = info->var.yres_virtual;
rect.color = 0;
rect.rop = ROP_COPY;
info->fbops->fb_fillrect(info, &rect);
}
static int
nouveau_fbcon_create(struct drm_fb_helper *helper,
struct drm_fb_helper_surface_size *sizes)
{
struct nouveau_fbdev *fbcon =
container_of(helper, struct nouveau_fbdev, helper);
struct drm_device *dev = fbcon->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvif_device *device = &drm->device;
struct fb_info *info;
struct drm_framebuffer *fb;
struct nouveau_framebuffer *nouveau_fb;
struct nouveau_channel *chan;
struct nouveau_bo *nvbo;
struct drm_mode_fb_cmd2 mode_cmd;
int size, ret;
mode_cmd.width = sizes->surface_width;
mode_cmd.height = sizes->surface_height;
mode_cmd.pitches[0] = mode_cmd.width * (sizes->surface_bpp >> 3);
mode_cmd.pitches[0] = roundup(mode_cmd.pitches[0], 256);
mode_cmd.pixel_format = drm_mode_legacy_fb_format(sizes->surface_bpp,
sizes->surface_depth);
size = mode_cmd.pitches[0] * mode_cmd.height;
size = roundup(size, PAGE_SIZE);
ret = nouveau_gem_new(dev, size, 0, NOUVEAU_GEM_DOMAIN_VRAM,
0, 0x0000, &nvbo);
if (ret) {
NV_ERROR(drm, "failed to allocate framebuffer\n");
goto out;
}
ret = nouveau_bo_pin(nvbo, TTM_PL_FLAG_VRAM, false);
if (ret) {
NV_ERROR(drm, "failed to pin fb: %d\n", ret);
goto out_unref;
}
ret = nouveau_bo_map(nvbo);
if (ret) {
NV_ERROR(drm, "failed to map fb: %d\n", ret);
goto out_unpin;
}
chan = nouveau_nofbaccel ? NULL : drm->channel;
if (chan && device->info.family >= NV_DEVICE_INFO_V0_TESLA) {
ret = nouveau_bo_vma_add(nvbo, drm->client.vm,
&fbcon->nouveau_fb.vma);
if (ret) {
NV_ERROR(drm, "failed to map fb into chan: %d\n", ret);
chan = NULL;
}
}
info = drm_fb_helper_alloc_fbi(helper);
if (IS_ERR(info)) {
ret = PTR_ERR(info);
goto out_unlock;
}
info->skip_vt_switch = 1;
info->par = fbcon;
nouveau_framebuffer_init(dev, &fbcon->nouveau_fb, &mode_cmd, nvbo);
nouveau_fb = &fbcon->nouveau_fb;
fb = &nouveau_fb->base;
fbcon->helper.fb = fb;
strcpy(info->fix.id, "nouveaufb");
if (!chan)
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_DISABLED;
else
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_COPYAREA |
FBINFO_HWACCEL_FILLRECT |
FBINFO_HWACCEL_IMAGEBLIT;
info->flags |= FBINFO_CAN_FORCE_OUTPUT;
info->fbops = &nouveau_fbcon_sw_ops;
info->fix.smem_start = nvbo->bo.mem.bus.base +
nvbo->bo.mem.bus.offset;
info->fix.smem_len = size;
info->screen_base = nvbo_kmap_obj_iovirtual(nouveau_fb->nvbo);
info->screen_size = size;
drm_fb_helper_fill_fix(info, fb->pitches[0], fb->depth);
drm_fb_helper_fill_var(info, &fbcon->helper, sizes->fb_width, sizes->fb_height);
if (chan)
nouveau_fbcon_accel_init(dev);
nouveau_fbcon_zfill(dev, fbcon);
NV_INFO(drm, "allocated %dx%d fb: 0x%llx, bo %p\n",
nouveau_fb->base.width, nouveau_fb->base.height,
nvbo->bo.offset, nvbo);
vga_switcheroo_client_fb_set(dev->pdev, info);
return 0;
out_unlock:
if (chan)
nouveau_bo_vma_del(nvbo, &fbcon->nouveau_fb.vma);
nouveau_bo_unmap(nvbo);
out_unpin:
nouveau_bo_unpin(nvbo);
out_unref:
nouveau_bo_ref(NULL, &nvbo);
out:
return ret;
}
void
nouveau_fbcon_output_poll_changed(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (drm->fbcon)
drm_fb_helper_hotplug_event(&drm->fbcon->helper);
}
static int
nouveau_fbcon_destroy(struct drm_device *dev, struct nouveau_fbdev *fbcon)
{
struct nouveau_framebuffer *nouveau_fb = &fbcon->nouveau_fb;
drm_fb_helper_unregister_fbi(&fbcon->helper);
drm_fb_helper_release_fbi(&fbcon->helper);
if (nouveau_fb->nvbo) {
nouveau_bo_unmap(nouveau_fb->nvbo);
nouveau_bo_vma_del(nouveau_fb->nvbo, &nouveau_fb->vma);
nouveau_bo_unpin(nouveau_fb->nvbo);
drm_gem_object_unreference_unlocked(&nouveau_fb->nvbo->gem);
nouveau_fb->nvbo = NULL;
}
drm_fb_helper_fini(&fbcon->helper);
drm_framebuffer_unregister_private(&nouveau_fb->base);
drm_framebuffer_cleanup(&nouveau_fb->base);
return 0;
}
void nouveau_fbcon_gpu_lockup(struct fb_info *info)
{
struct nouveau_fbdev *fbcon = info->par;
struct nouveau_drm *drm = nouveau_drm(fbcon->dev);
NV_ERROR(drm, "GPU lockup - switching to software fbcon\n");
info->flags |= FBINFO_HWACCEL_DISABLED;
}
void
nouveau_fbcon_set_suspend(struct drm_device *dev, int state)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (drm->fbcon) {
console_lock();
if (state == FBINFO_STATE_RUNNING)
nouveau_fbcon_accel_restore(dev);
drm_fb_helper_set_suspend(&drm->fbcon->helper, state);
if (state != FBINFO_STATE_RUNNING)
nouveau_fbcon_accel_save_disable(dev);
console_unlock();
}
}
int
nouveau_fbcon_init(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_fbdev *fbcon;
int preferred_bpp;
int ret;
if (!dev->mode_config.num_crtc ||
(dev->pdev->class >> 8) != PCI_CLASS_DISPLAY_VGA)
return 0;
fbcon = kzalloc(sizeof(struct nouveau_fbdev), GFP_KERNEL);
if (!fbcon)
return -ENOMEM;
fbcon->dev = dev;
drm->fbcon = fbcon;
drm_fb_helper_prepare(dev, &fbcon->helper, &nouveau_fbcon_helper_funcs);
ret = drm_fb_helper_init(dev, &fbcon->helper,
dev->mode_config.num_crtc, 4);
if (ret)
goto free;
ret = drm_fb_helper_single_add_all_connectors(&fbcon->helper);
if (ret)
goto fini;
if (drm->device.info.ram_size <= 32 * 1024 * 1024)
preferred_bpp = 8;
else
if (drm->device.info.ram_size <= 64 * 1024 * 1024)
preferred_bpp = 16;
else
preferred_bpp = 32;
drm_helper_disable_unused_functions(dev);
ret = drm_fb_helper_initial_config(&fbcon->helper, preferred_bpp);
if (ret)
goto fini;
if (fbcon->helper.fbdev)
fbcon->helper.fbdev->pixmap.buf_align = 4;
return 0;
fini:
drm_fb_helper_fini(&fbcon->helper);
free:
kfree(fbcon);
return ret;
}
void
nouveau_fbcon_fini(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (!drm->fbcon)
return;
nouveau_fbcon_accel_fini(dev);
nouveau_fbcon_destroy(dev, drm->fbcon);
kfree(drm->fbcon);
drm->fbcon = NULL;
}
