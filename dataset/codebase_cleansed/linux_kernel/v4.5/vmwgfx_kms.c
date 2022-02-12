void vmw_du_cleanup(struct vmw_display_unit *du)
{
if (du->cursor_surface)
vmw_surface_unreference(&du->cursor_surface);
if (du->cursor_dmabuf)
vmw_dmabuf_unreference(&du->cursor_dmabuf);
drm_connector_unregister(&du->connector);
drm_crtc_cleanup(&du->crtc);
drm_encoder_cleanup(&du->encoder);
drm_connector_cleanup(&du->connector);
}
int vmw_cursor_update_image(struct vmw_private *dev_priv,
u32 *image, u32 width, u32 height,
u32 hotspotX, u32 hotspotY)
{
struct {
u32 cmd;
SVGAFifoCmdDefineAlphaCursor cursor;
} *cmd;
u32 image_size = width * height * 4;
u32 cmd_size = sizeof(*cmd) + image_size;
if (!image)
return -EINVAL;
cmd = vmw_fifo_reserve(dev_priv, cmd_size);
if (unlikely(cmd == NULL)) {
DRM_ERROR("Fifo reserve failed.\n");
return -ENOMEM;
}
memset(cmd, 0, sizeof(*cmd));
memcpy(&cmd[1], image, image_size);
cmd->cmd = SVGA_CMD_DEFINE_ALPHA_CURSOR;
cmd->cursor.id = 0;
cmd->cursor.width = width;
cmd->cursor.height = height;
cmd->cursor.hotspotX = hotspotX;
cmd->cursor.hotspotY = hotspotY;
vmw_fifo_commit_flush(dev_priv, cmd_size);
return 0;
}
int vmw_cursor_update_dmabuf(struct vmw_private *dev_priv,
struct vmw_dma_buffer *dmabuf,
u32 width, u32 height,
u32 hotspotX, u32 hotspotY)
{
struct ttm_bo_kmap_obj map;
unsigned long kmap_offset;
unsigned long kmap_num;
void *virtual;
bool dummy;
int ret;
kmap_offset = 0;
kmap_num = (width*height*4 + PAGE_SIZE - 1) >> PAGE_SHIFT;
ret = ttm_bo_reserve(&dmabuf->base, true, false, false, NULL);
if (unlikely(ret != 0)) {
DRM_ERROR("reserve failed\n");
return -EINVAL;
}
ret = ttm_bo_kmap(&dmabuf->base, kmap_offset, kmap_num, &map);
if (unlikely(ret != 0))
goto err_unreserve;
virtual = ttm_kmap_obj_virtual(&map, &dummy);
ret = vmw_cursor_update_image(dev_priv, virtual, width, height,
hotspotX, hotspotY);
ttm_bo_kunmap(&map);
err_unreserve:
ttm_bo_unreserve(&dmabuf->base);
return ret;
}
void vmw_cursor_update_position(struct vmw_private *dev_priv,
bool show, int x, int y)
{
u32 *fifo_mem = dev_priv->mmio_virt;
uint32_t count;
vmw_mmio_write(show ? 1 : 0, fifo_mem + SVGA_FIFO_CURSOR_ON);
vmw_mmio_write(x, fifo_mem + SVGA_FIFO_CURSOR_X);
vmw_mmio_write(y, fifo_mem + SVGA_FIFO_CURSOR_Y);
count = vmw_mmio_read(fifo_mem + SVGA_FIFO_CURSOR_COUNT);
vmw_mmio_write(++count, fifo_mem + SVGA_FIFO_CURSOR_COUNT);
}
int vmw_du_crtc_cursor_set2(struct drm_crtc *crtc, struct drm_file *file_priv,
uint32_t handle, uint32_t width, uint32_t height,
int32_t hot_x, int32_t hot_y)
{
struct vmw_private *dev_priv = vmw_priv(crtc->dev);
struct vmw_display_unit *du = vmw_crtc_to_du(crtc);
struct vmw_surface *surface = NULL;
struct vmw_dma_buffer *dmabuf = NULL;
s32 hotspot_x, hotspot_y;
int ret;
drm_modeset_unlock_crtc(crtc);
drm_modeset_lock_all(dev_priv->dev);
hotspot_x = hot_x + du->hotspot_x;
hotspot_y = hot_y + du->hotspot_y;
if (handle && (width != 64 || height != 64)) {
ret = -EINVAL;
goto out;
}
if (handle) {
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
ret = vmw_user_lookup_handle(dev_priv, tfile,
handle, &surface, &dmabuf);
if (ret) {
DRM_ERROR("failed to find surface or dmabuf: %i\n", ret);
ret = -EINVAL;
goto out;
}
}
if (surface && !surface->snooper.image) {
DRM_ERROR("surface not suitable for cursor\n");
vmw_surface_unreference(&surface);
ret = -EINVAL;
goto out;
}
if (du->cursor_surface) {
du->cursor_surface->snooper.crtc = NULL;
vmw_surface_unreference(&du->cursor_surface);
}
if (du->cursor_dmabuf)
vmw_dmabuf_unreference(&du->cursor_dmabuf);
ret = 0;
if (surface) {
du->cursor_surface = surface;
du->cursor_surface->snooper.crtc = crtc;
du->cursor_age = du->cursor_surface->snooper.age;
ret = vmw_cursor_update_image(dev_priv, surface->snooper.image,
64, 64, hotspot_x, hotspot_y);
} else if (dmabuf) {
du->cursor_dmabuf = dmabuf;
ret = vmw_cursor_update_dmabuf(dev_priv, dmabuf, width, height,
hotspot_x, hotspot_y);
} else {
vmw_cursor_update_position(dev_priv, false, 0, 0);
goto out;
}
if (!ret) {
vmw_cursor_update_position(dev_priv, true,
du->cursor_x + hotspot_x,
du->cursor_y + hotspot_y);
du->core_hotspot_x = hot_x;
du->core_hotspot_y = hot_y;
}
out:
drm_modeset_unlock_all(dev_priv->dev);
drm_modeset_lock_crtc(crtc, crtc->cursor);
return ret;
}
int vmw_du_crtc_cursor_move(struct drm_crtc *crtc, int x, int y)
{
struct vmw_private *dev_priv = vmw_priv(crtc->dev);
struct vmw_display_unit *du = vmw_crtc_to_du(crtc);
bool shown = du->cursor_surface || du->cursor_dmabuf ? true : false;
du->cursor_x = x + crtc->x;
du->cursor_y = y + crtc->y;
drm_modeset_unlock_crtc(crtc);
drm_modeset_lock_all(dev_priv->dev);
vmw_cursor_update_position(dev_priv, shown,
du->cursor_x + du->hotspot_x +
du->core_hotspot_x,
du->cursor_y + du->hotspot_y +
du->core_hotspot_y);
drm_modeset_unlock_all(dev_priv->dev);
drm_modeset_lock_crtc(crtc, crtc->cursor);
return 0;
}
void vmw_kms_cursor_snoop(struct vmw_surface *srf,
struct ttm_object_file *tfile,
struct ttm_buffer_object *bo,
SVGA3dCmdHeader *header)
{
struct ttm_bo_kmap_obj map;
unsigned long kmap_offset;
unsigned long kmap_num;
SVGA3dCopyBox *box;
unsigned box_count;
void *virtual;
bool dummy;
struct vmw_dma_cmd {
SVGA3dCmdHeader header;
SVGA3dCmdSurfaceDMA dma;
} *cmd;
int i, ret;
cmd = container_of(header, struct vmw_dma_cmd, header);
if (!srf->snooper.image)
return;
if (cmd->dma.host.face != 0 || cmd->dma.host.mipmap != 0) {
DRM_ERROR("face and mipmap for cursors should never != 0\n");
return;
}
if (cmd->header.size < 64) {
DRM_ERROR("at least one full copy box must be given\n");
return;
}
box = (SVGA3dCopyBox *)&cmd[1];
box_count = (cmd->header.size - sizeof(SVGA3dCmdSurfaceDMA)) /
sizeof(SVGA3dCopyBox);
if (cmd->dma.guest.ptr.offset % PAGE_SIZE ||
box->x != 0 || box->y != 0 || box->z != 0 ||
box->srcx != 0 || box->srcy != 0 || box->srcz != 0 ||
box->d != 1 || box_count != 1) {
DRM_ERROR("Cant snoop dma request for cursor!\n");
DRM_ERROR("(%u, %u, %u) (%u, %u, %u) (%ux%ux%u) %u %u\n",
box->srcx, box->srcy, box->srcz,
box->x, box->y, box->z,
box->w, box->h, box->d, box_count,
cmd->dma.guest.ptr.offset);
return;
}
kmap_offset = cmd->dma.guest.ptr.offset >> PAGE_SHIFT;
kmap_num = (64*64*4) >> PAGE_SHIFT;
ret = ttm_bo_reserve(bo, true, false, false, NULL);
if (unlikely(ret != 0)) {
DRM_ERROR("reserve failed\n");
return;
}
ret = ttm_bo_kmap(bo, kmap_offset, kmap_num, &map);
if (unlikely(ret != 0))
goto err_unreserve;
virtual = ttm_kmap_obj_virtual(&map, &dummy);
if (box->w == 64 && cmd->dma.guest.pitch == 64*4) {
memcpy(srf->snooper.image, virtual, 64*64*4);
} else {
for (i = 0; i < box->h; i++)
memcpy(srf->snooper.image + i * 64,
virtual + i * cmd->dma.guest.pitch,
box->w * 4);
}
srf->snooper.age++;
ttm_bo_kunmap(&map);
err_unreserve:
ttm_bo_unreserve(bo);
}
void vmw_kms_legacy_hotspot_clear(struct vmw_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct vmw_display_unit *du;
struct drm_crtc *crtc;
drm_modeset_lock_all(dev);
drm_for_each_crtc(crtc, dev) {
du = vmw_crtc_to_du(crtc);
du->hotspot_x = 0;
du->hotspot_y = 0;
}
drm_modeset_unlock_all(dev);
}
void vmw_kms_cursor_post_execbuf(struct vmw_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
struct vmw_display_unit *du;
struct drm_crtc *crtc;
mutex_lock(&dev->mode_config.mutex);
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
du = vmw_crtc_to_du(crtc);
if (!du->cursor_surface ||
du->cursor_age == du->cursor_surface->snooper.age)
continue;
du->cursor_age = du->cursor_surface->snooper.age;
vmw_cursor_update_image(dev_priv,
du->cursor_surface->snooper.image,
64, 64,
du->hotspot_x + du->core_hotspot_x,
du->hotspot_y + du->core_hotspot_y);
}
mutex_unlock(&dev->mode_config.mutex);
}
static void vmw_framebuffer_surface_destroy(struct drm_framebuffer *framebuffer)
{
struct vmw_framebuffer_surface *vfbs =
vmw_framebuffer_to_vfbs(framebuffer);
drm_framebuffer_cleanup(framebuffer);
vmw_surface_unreference(&vfbs->surface);
if (vfbs->base.user_obj)
ttm_base_object_unref(&vfbs->base.user_obj);
kfree(vfbs);
}
static int vmw_framebuffer_surface_dirty(struct drm_framebuffer *framebuffer,
struct drm_file *file_priv,
unsigned flags, unsigned color,
struct drm_clip_rect *clips,
unsigned num_clips)
{
struct vmw_private *dev_priv = vmw_priv(framebuffer->dev);
struct vmw_framebuffer_surface *vfbs =
vmw_framebuffer_to_vfbs(framebuffer);
struct drm_clip_rect norect;
int ret, inc = 1;
if (dev_priv->active_display_unit == vmw_du_legacy)
return -EINVAL;
drm_modeset_lock_all(dev_priv->dev);
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0)) {
drm_modeset_unlock_all(dev_priv->dev);
return ret;
}
if (!num_clips) {
num_clips = 1;
clips = &norect;
norect.x1 = norect.y1 = 0;
norect.x2 = framebuffer->width;
norect.y2 = framebuffer->height;
} else if (flags & DRM_MODE_FB_DIRTY_ANNOTATE_COPY) {
num_clips /= 2;
inc = 2;
}
if (dev_priv->active_display_unit == vmw_du_screen_object)
ret = vmw_kms_sou_do_surface_dirty(dev_priv, &vfbs->base,
clips, NULL, NULL, 0, 0,
num_clips, inc, NULL);
else
ret = vmw_kms_stdu_surface_dirty(dev_priv, &vfbs->base,
clips, NULL, NULL, 0, 0,
num_clips, inc, NULL);
vmw_fifo_flush(dev_priv, false);
ttm_read_unlock(&dev_priv->reservation_sem);
drm_modeset_unlock_all(dev_priv->dev);
return 0;
}
int vmw_kms_readback(struct vmw_private *dev_priv,
struct drm_file *file_priv,
struct vmw_framebuffer *vfb,
struct drm_vmw_fence_rep __user *user_fence_rep,
struct drm_vmw_rect *vclips,
uint32_t num_clips)
{
switch (dev_priv->active_display_unit) {
case vmw_du_screen_object:
return vmw_kms_sou_readback(dev_priv, file_priv, vfb,
user_fence_rep, vclips, num_clips);
case vmw_du_screen_target:
return vmw_kms_stdu_dma(dev_priv, file_priv, vfb,
user_fence_rep, NULL, vclips, num_clips,
1, false, true);
default:
WARN_ONCE(true,
"Readback called with invalid display system.\n");
}
return -ENOSYS;
}
static int vmw_kms_new_framebuffer_surface(struct vmw_private *dev_priv,
struct vmw_surface *surface,
struct vmw_framebuffer **out,
const struct drm_mode_fb_cmd
*mode_cmd,
bool is_dmabuf_proxy)
{
struct drm_device *dev = dev_priv->dev;
struct vmw_framebuffer_surface *vfbs;
enum SVGA3dSurfaceFormat format;
int ret;
if (dev_priv->active_display_unit == vmw_du_legacy)
return -ENOSYS;
if (unlikely(!surface->scanout))
return -EINVAL;
if (unlikely(surface->mip_levels[0] != 1 ||
surface->num_sizes != 1 ||
surface->base_size.width < mode_cmd->width ||
surface->base_size.height < mode_cmd->height ||
surface->base_size.depth != 1)) {
DRM_ERROR("Incompatible surface dimensions "
"for requested mode.\n");
return -EINVAL;
}
switch (mode_cmd->depth) {
case 32:
format = SVGA3D_A8R8G8B8;
break;
case 24:
format = SVGA3D_X8R8G8B8;
break;
case 16:
format = SVGA3D_R5G6B5;
break;
case 15:
format = SVGA3D_A1R5G5B5;
break;
default:
DRM_ERROR("Invalid color depth: %d\n", mode_cmd->depth);
return -EINVAL;
}
if (!dev_priv->has_dx && format != surface->format) {
DRM_ERROR("Invalid surface format for requested mode.\n");
return -EINVAL;
}
vfbs = kzalloc(sizeof(*vfbs), GFP_KERNEL);
if (!vfbs) {
ret = -ENOMEM;
goto out_err1;
}
vfbs->base.base.bits_per_pixel = mode_cmd->bpp;
vfbs->base.base.pitches[0] = mode_cmd->pitch;
vfbs->base.base.depth = mode_cmd->depth;
vfbs->base.base.width = mode_cmd->width;
vfbs->base.base.height = mode_cmd->height;
vfbs->surface = vmw_surface_reference(surface);
vfbs->base.user_handle = mode_cmd->handle;
vfbs->is_dmabuf_proxy = is_dmabuf_proxy;
*out = &vfbs->base;
ret = drm_framebuffer_init(dev, &vfbs->base.base,
&vmw_framebuffer_surface_funcs);
if (ret)
goto out_err2;
return 0;
out_err2:
vmw_surface_unreference(&surface);
kfree(vfbs);
out_err1:
return ret;
}
static void vmw_framebuffer_dmabuf_destroy(struct drm_framebuffer *framebuffer)
{
struct vmw_framebuffer_dmabuf *vfbd =
vmw_framebuffer_to_vfbd(framebuffer);
drm_framebuffer_cleanup(framebuffer);
vmw_dmabuf_unreference(&vfbd->buffer);
if (vfbd->base.user_obj)
ttm_base_object_unref(&vfbd->base.user_obj);
kfree(vfbd);
}
static int vmw_framebuffer_dmabuf_dirty(struct drm_framebuffer *framebuffer,
struct drm_file *file_priv,
unsigned flags, unsigned color,
struct drm_clip_rect *clips,
unsigned num_clips)
{
struct vmw_private *dev_priv = vmw_priv(framebuffer->dev);
struct vmw_framebuffer_dmabuf *vfbd =
vmw_framebuffer_to_vfbd(framebuffer);
struct drm_clip_rect norect;
int ret, increment = 1;
drm_modeset_lock_all(dev_priv->dev);
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0)) {
drm_modeset_unlock_all(dev_priv->dev);
return ret;
}
if (!num_clips) {
num_clips = 1;
clips = &norect;
norect.x1 = norect.y1 = 0;
norect.x2 = framebuffer->width;
norect.y2 = framebuffer->height;
} else if (flags & DRM_MODE_FB_DIRTY_ANNOTATE_COPY) {
num_clips /= 2;
increment = 2;
}
switch (dev_priv->active_display_unit) {
case vmw_du_screen_target:
ret = vmw_kms_stdu_dma(dev_priv, NULL, &vfbd->base, NULL,
clips, NULL, num_clips, increment,
true, true);
break;
case vmw_du_screen_object:
ret = vmw_kms_sou_do_dmabuf_dirty(dev_priv, &vfbd->base,
clips, num_clips, increment,
true,
NULL);
break;
case vmw_du_legacy:
ret = vmw_kms_ldu_do_dmabuf_dirty(dev_priv, &vfbd->base, 0, 0,
clips, num_clips, increment);
break;
default:
ret = -EINVAL;
WARN_ONCE(true, "Dirty called with invalid display system.\n");
break;
}
vmw_fifo_flush(dev_priv, false);
ttm_read_unlock(&dev_priv->reservation_sem);
drm_modeset_unlock_all(dev_priv->dev);
return ret;
}
static int vmw_framebuffer_pin(struct vmw_framebuffer *vfb)
{
struct vmw_private *dev_priv = vmw_priv(vfb->base.dev);
struct vmw_dma_buffer *buf;
int ret;
buf = vfb->dmabuf ? vmw_framebuffer_to_vfbd(&vfb->base)->buffer :
vmw_framebuffer_to_vfbs(&vfb->base)->surface->res.backup;
if (!buf)
return 0;
switch (dev_priv->active_display_unit) {
case vmw_du_legacy:
vmw_overlay_pause_all(dev_priv);
ret = vmw_dmabuf_pin_in_start_of_vram(dev_priv, buf, false);
vmw_overlay_resume_all(dev_priv);
break;
case vmw_du_screen_object:
case vmw_du_screen_target:
if (vfb->dmabuf)
return vmw_dmabuf_pin_in_vram_or_gmr(dev_priv, buf,
false);
return vmw_dmabuf_pin_in_placement(dev_priv, buf,
&vmw_mob_placement, false);
default:
return -EINVAL;
}
return ret;
}
static int vmw_framebuffer_unpin(struct vmw_framebuffer *vfb)
{
struct vmw_private *dev_priv = vmw_priv(vfb->base.dev);
struct vmw_dma_buffer *buf;
buf = vfb->dmabuf ? vmw_framebuffer_to_vfbd(&vfb->base)->buffer :
vmw_framebuffer_to_vfbs(&vfb->base)->surface->res.backup;
if (WARN_ON(!buf))
return 0;
return vmw_dmabuf_unpin(dev_priv, buf, false);
}
static int vmw_create_dmabuf_proxy(struct drm_device *dev,
const struct drm_mode_fb_cmd *mode_cmd,
struct vmw_dma_buffer *dmabuf_mob,
struct vmw_surface **srf_out)
{
uint32_t format;
struct drm_vmw_size content_base_size;
struct vmw_resource *res;
unsigned int bytes_pp;
int ret;
switch (mode_cmd->depth) {
case 32:
case 24:
format = SVGA3D_X8R8G8B8;
bytes_pp = 4;
break;
case 16:
case 15:
format = SVGA3D_R5G6B5;
bytes_pp = 2;
break;
case 8:
format = SVGA3D_P8;
bytes_pp = 1;
break;
default:
DRM_ERROR("Invalid framebuffer format %d\n", mode_cmd->depth);
return -EINVAL;
}
content_base_size.width = mode_cmd->pitch / bytes_pp;
content_base_size.height = mode_cmd->height;
content_base_size.depth = 1;
ret = vmw_surface_gb_priv_define(dev,
0,
0,
format,
true,
1,
0,
0,
content_base_size,
srf_out);
if (ret) {
DRM_ERROR("Failed to allocate proxy content buffer\n");
return ret;
}
res = &(*srf_out)->res;
mutex_lock(&res->dev_priv->cmdbuf_mutex);
(void) vmw_resource_reserve(res, false, true);
vmw_dmabuf_unreference(&res->backup);
res->backup = vmw_dmabuf_reference(dmabuf_mob);
res->backup_offset = 0;
vmw_resource_unreserve(res, false, NULL, 0);
mutex_unlock(&res->dev_priv->cmdbuf_mutex);
return 0;
}
static int vmw_kms_new_framebuffer_dmabuf(struct vmw_private *dev_priv,
struct vmw_dma_buffer *dmabuf,
struct vmw_framebuffer **out,
const struct drm_mode_fb_cmd
*mode_cmd)
{
struct drm_device *dev = dev_priv->dev;
struct vmw_framebuffer_dmabuf *vfbd;
unsigned int requested_size;
int ret;
requested_size = mode_cmd->height * mode_cmd->pitch;
if (unlikely(requested_size > dmabuf->base.num_pages * PAGE_SIZE)) {
DRM_ERROR("Screen buffer object size is too small "
"for requested mode.\n");
return -EINVAL;
}
if (dev_priv->active_display_unit == vmw_du_screen_object) {
switch (mode_cmd->depth) {
case 32:
case 24:
if (mode_cmd->bpp == 32)
break;
DRM_ERROR("Invalid color depth/bbp: %d %d\n",
mode_cmd->depth, mode_cmd->bpp);
return -EINVAL;
case 16:
case 15:
if (mode_cmd->bpp == 16)
break;
DRM_ERROR("Invalid color depth/bbp: %d %d\n",
mode_cmd->depth, mode_cmd->bpp);
return -EINVAL;
default:
DRM_ERROR("Invalid color depth: %d\n", mode_cmd->depth);
return -EINVAL;
}
}
vfbd = kzalloc(sizeof(*vfbd), GFP_KERNEL);
if (!vfbd) {
ret = -ENOMEM;
goto out_err1;
}
vfbd->base.base.bits_per_pixel = mode_cmd->bpp;
vfbd->base.base.pitches[0] = mode_cmd->pitch;
vfbd->base.base.depth = mode_cmd->depth;
vfbd->base.base.width = mode_cmd->width;
vfbd->base.base.height = mode_cmd->height;
vfbd->base.dmabuf = true;
vfbd->buffer = vmw_dmabuf_reference(dmabuf);
vfbd->base.user_handle = mode_cmd->handle;
*out = &vfbd->base;
ret = drm_framebuffer_init(dev, &vfbd->base.base,
&vmw_framebuffer_dmabuf_funcs);
if (ret)
goto out_err2;
return 0;
out_err2:
vmw_dmabuf_unreference(&dmabuf);
kfree(vfbd);
out_err1:
return ret;
}
struct vmw_framebuffer *
vmw_kms_new_framebuffer(struct vmw_private *dev_priv,
struct vmw_dma_buffer *dmabuf,
struct vmw_surface *surface,
bool only_2d,
const struct drm_mode_fb_cmd *mode_cmd)
{
struct vmw_framebuffer *vfb = NULL;
bool is_dmabuf_proxy = false;
int ret;
if (dmabuf && only_2d &&
dev_priv->active_display_unit == vmw_du_screen_target) {
ret = vmw_create_dmabuf_proxy(dev_priv->dev, mode_cmd,
dmabuf, &surface);
if (ret)
return ERR_PTR(ret);
is_dmabuf_proxy = true;
}
if (surface) {
ret = vmw_kms_new_framebuffer_surface(dev_priv, surface, &vfb,
mode_cmd,
is_dmabuf_proxy);
if (is_dmabuf_proxy)
vmw_surface_unreference(&surface);
} else if (dmabuf) {
ret = vmw_kms_new_framebuffer_dmabuf(dev_priv, dmabuf, &vfb,
mode_cmd);
} else {
BUG();
}
if (ret)
return ERR_PTR(ret);
vfb->pin = vmw_framebuffer_pin;
vfb->unpin = vmw_framebuffer_unpin;
return vfb;
}
static struct drm_framebuffer *vmw_kms_fb_create(struct drm_device *dev,
struct drm_file *file_priv,
const struct drm_mode_fb_cmd2 *mode_cmd2)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_framebuffer *vfb = NULL;
struct vmw_surface *surface = NULL;
struct vmw_dma_buffer *bo = NULL;
struct ttm_base_object *user_obj;
struct drm_mode_fb_cmd mode_cmd;
int ret;
mode_cmd.width = mode_cmd2->width;
mode_cmd.height = mode_cmd2->height;
mode_cmd.pitch = mode_cmd2->pitches[0];
mode_cmd.handle = mode_cmd2->handles[0];
drm_fb_get_bpp_depth(mode_cmd2->pixel_format, &mode_cmd.depth,
&mode_cmd.bpp);
if (!vmw_kms_validate_mode_vram(dev_priv,
mode_cmd.pitch,
mode_cmd.height)) {
DRM_ERROR("Requested mode exceed bounding box limit.\n");
return ERR_PTR(-ENOMEM);
}
user_obj = ttm_base_object_lookup(tfile, mode_cmd.handle);
if (unlikely(user_obj == NULL)) {
DRM_ERROR("Could not locate requested kms frame buffer.\n");
return ERR_PTR(-ENOENT);
}
ret = vmw_user_lookup_handle(dev_priv, tfile,
mode_cmd.handle,
&surface, &bo);
if (ret)
goto err_out;
vfb = vmw_kms_new_framebuffer(dev_priv, bo, surface,
!(dev_priv->capabilities & SVGA_CAP_3D),
&mode_cmd);
if (IS_ERR(vfb)) {
ret = PTR_ERR(vfb);
goto err_out;
}
err_out:
if (bo)
vmw_dmabuf_unreference(&bo);
if (surface)
vmw_surface_unreference(&surface);
if (ret) {
DRM_ERROR("failed to create vmw_framebuffer: %i\n", ret);
ttm_base_object_unref(&user_obj);
return ERR_PTR(ret);
} else
vfb->user_obj = user_obj;
return &vfb->base;
}
static int vmw_kms_generic_present(struct vmw_private *dev_priv,
struct drm_file *file_priv,
struct vmw_framebuffer *vfb,
struct vmw_surface *surface,
uint32_t sid,
int32_t destX, int32_t destY,
struct drm_vmw_rect *clips,
uint32_t num_clips)
{
return vmw_kms_sou_do_surface_dirty(dev_priv, vfb, NULL, clips,
&surface->res, destX, destY,
num_clips, 1, NULL);
}
int vmw_kms_present(struct vmw_private *dev_priv,
struct drm_file *file_priv,
struct vmw_framebuffer *vfb,
struct vmw_surface *surface,
uint32_t sid,
int32_t destX, int32_t destY,
struct drm_vmw_rect *clips,
uint32_t num_clips)
{
int ret;
switch (dev_priv->active_display_unit) {
case vmw_du_screen_target:
ret = vmw_kms_stdu_surface_dirty(dev_priv, vfb, NULL, clips,
&surface->res, destX, destY,
num_clips, 1, NULL);
break;
case vmw_du_screen_object:
ret = vmw_kms_generic_present(dev_priv, file_priv, vfb, surface,
sid, destX, destY, clips,
num_clips);
break;
default:
WARN_ONCE(true,
"Present called with invalid display system.\n");
ret = -ENOSYS;
break;
}
if (ret)
return ret;
vmw_fifo_flush(dev_priv, false);
return 0;
}
int vmw_kms_init(struct vmw_private *dev_priv)
{
struct drm_device *dev = dev_priv->dev;
int ret;
drm_mode_config_init(dev);
dev->mode_config.funcs = &vmw_kms_funcs;
dev->mode_config.min_width = 1;
dev->mode_config.min_height = 1;
dev->mode_config.max_width = dev_priv->texture_max_width;
dev->mode_config.max_height = dev_priv->texture_max_height;
ret = vmw_kms_stdu_init_display(dev_priv);
if (ret) {
ret = vmw_kms_sou_init_display(dev_priv);
if (ret)
ret = vmw_kms_ldu_init_display(dev_priv);
}
return ret;
}
int vmw_kms_close(struct vmw_private *dev_priv)
{
int ret;
drm_mode_config_cleanup(dev_priv->dev);
if (dev_priv->active_display_unit == vmw_du_screen_object)
ret = vmw_kms_sou_close_display(dev_priv);
else if (dev_priv->active_display_unit == vmw_du_screen_target)
ret = vmw_kms_stdu_close_display(dev_priv);
else
ret = vmw_kms_ldu_close_display(dev_priv);
return ret;
}
int vmw_kms_cursor_bypass_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_cursor_bypass_arg *arg = data;
struct vmw_display_unit *du;
struct drm_crtc *crtc;
int ret = 0;
mutex_lock(&dev->mode_config.mutex);
if (arg->flags & DRM_VMW_CURSOR_BYPASS_ALL) {
list_for_each_entry(crtc, &dev->mode_config.crtc_list, head) {
du = vmw_crtc_to_du(crtc);
du->hotspot_x = arg->xhot;
du->hotspot_y = arg->yhot;
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
crtc = drm_crtc_find(dev, arg->crtc_id);
if (!crtc) {
ret = -ENOENT;
goto out;
}
du = vmw_crtc_to_du(crtc);
du->hotspot_x = arg->xhot;
du->hotspot_y = arg->yhot;
out:
mutex_unlock(&dev->mode_config.mutex);
return ret;
}
int vmw_kms_write_svga(struct vmw_private *vmw_priv,
unsigned width, unsigned height, unsigned pitch,
unsigned bpp, unsigned depth)
{
if (vmw_priv->capabilities & SVGA_CAP_PITCHLOCK)
vmw_write(vmw_priv, SVGA_REG_PITCHLOCK, pitch);
else if (vmw_fifo_have_pitchlock(vmw_priv))
vmw_mmio_write(pitch, vmw_priv->mmio_virt +
SVGA_FIFO_PITCHLOCK);
vmw_write(vmw_priv, SVGA_REG_WIDTH, width);
vmw_write(vmw_priv, SVGA_REG_HEIGHT, height);
vmw_write(vmw_priv, SVGA_REG_BITS_PER_PIXEL, bpp);
if (vmw_read(vmw_priv, SVGA_REG_DEPTH) != depth) {
DRM_ERROR("Invalid depth %u for %u bpp, host expects %u\n",
depth, bpp, vmw_read(vmw_priv, SVGA_REG_DEPTH));
return -EINVAL;
}
return 0;
}
int vmw_kms_save_vga(struct vmw_private *vmw_priv)
{
struct vmw_vga_topology_state *save;
uint32_t i;
vmw_priv->vga_width = vmw_read(vmw_priv, SVGA_REG_WIDTH);
vmw_priv->vga_height = vmw_read(vmw_priv, SVGA_REG_HEIGHT);
vmw_priv->vga_bpp = vmw_read(vmw_priv, SVGA_REG_BITS_PER_PIXEL);
if (vmw_priv->capabilities & SVGA_CAP_PITCHLOCK)
vmw_priv->vga_pitchlock =
vmw_read(vmw_priv, SVGA_REG_PITCHLOCK);
else if (vmw_fifo_have_pitchlock(vmw_priv))
vmw_priv->vga_pitchlock = vmw_mmio_read(vmw_priv->mmio_virt +
SVGA_FIFO_PITCHLOCK);
if (!(vmw_priv->capabilities & SVGA_CAP_DISPLAY_TOPOLOGY))
return 0;
vmw_priv->num_displays = vmw_read(vmw_priv,
SVGA_REG_NUM_GUEST_DISPLAYS);
if (vmw_priv->num_displays == 0)
vmw_priv->num_displays = 1;
for (i = 0; i < vmw_priv->num_displays; ++i) {
save = &vmw_priv->vga_save[i];
vmw_write(vmw_priv, SVGA_REG_DISPLAY_ID, i);
save->primary = vmw_read(vmw_priv, SVGA_REG_DISPLAY_IS_PRIMARY);
save->pos_x = vmw_read(vmw_priv, SVGA_REG_DISPLAY_POSITION_X);
save->pos_y = vmw_read(vmw_priv, SVGA_REG_DISPLAY_POSITION_Y);
save->width = vmw_read(vmw_priv, SVGA_REG_DISPLAY_WIDTH);
save->height = vmw_read(vmw_priv, SVGA_REG_DISPLAY_HEIGHT);
vmw_write(vmw_priv, SVGA_REG_DISPLAY_ID, SVGA_ID_INVALID);
if (i == 0 && vmw_priv->num_displays == 1 &&
save->width == 0 && save->height == 0) {
save->width = vmw_priv->vga_width - save->pos_x;
save->height = vmw_priv->vga_height - save->pos_y;
}
}
return 0;
}
int vmw_kms_restore_vga(struct vmw_private *vmw_priv)
{
struct vmw_vga_topology_state *save;
uint32_t i;
vmw_write(vmw_priv, SVGA_REG_WIDTH, vmw_priv->vga_width);
vmw_write(vmw_priv, SVGA_REG_HEIGHT, vmw_priv->vga_height);
vmw_write(vmw_priv, SVGA_REG_BITS_PER_PIXEL, vmw_priv->vga_bpp);
if (vmw_priv->capabilities & SVGA_CAP_PITCHLOCK)
vmw_write(vmw_priv, SVGA_REG_PITCHLOCK,
vmw_priv->vga_pitchlock);
else if (vmw_fifo_have_pitchlock(vmw_priv))
vmw_mmio_write(vmw_priv->vga_pitchlock,
vmw_priv->mmio_virt + SVGA_FIFO_PITCHLOCK);
if (!(vmw_priv->capabilities & SVGA_CAP_DISPLAY_TOPOLOGY))
return 0;
for (i = 0; i < vmw_priv->num_displays; ++i) {
save = &vmw_priv->vga_save[i];
vmw_write(vmw_priv, SVGA_REG_DISPLAY_ID, i);
vmw_write(vmw_priv, SVGA_REG_DISPLAY_IS_PRIMARY, save->primary);
vmw_write(vmw_priv, SVGA_REG_DISPLAY_POSITION_X, save->pos_x);
vmw_write(vmw_priv, SVGA_REG_DISPLAY_POSITION_Y, save->pos_y);
vmw_write(vmw_priv, SVGA_REG_DISPLAY_WIDTH, save->width);
vmw_write(vmw_priv, SVGA_REG_DISPLAY_HEIGHT, save->height);
vmw_write(vmw_priv, SVGA_REG_DISPLAY_ID, SVGA_ID_INVALID);
}
return 0;
}
bool vmw_kms_validate_mode_vram(struct vmw_private *dev_priv,
uint32_t pitch,
uint32_t height)
{
return ((u64) pitch * (u64) height) < (u64)
((dev_priv->active_display_unit == vmw_du_screen_target) ?
dev_priv->prim_bb_mem : dev_priv->vram_size);
}
u32 vmw_get_vblank_counter(struct drm_device *dev, unsigned int pipe)
{
return 0;
}
int vmw_enable_vblank(struct drm_device *dev, unsigned int pipe)
{
return -ENOSYS;
}
void vmw_disable_vblank(struct drm_device *dev, unsigned int pipe)
{
}
static int vmw_du_update_layout(struct vmw_private *dev_priv, unsigned num,
struct drm_vmw_rect *rects)
{
struct drm_device *dev = dev_priv->dev;
struct vmw_display_unit *du;
struct drm_connector *con;
mutex_lock(&dev->mode_config.mutex);
#if 0
{
unsigned int i;
DRM_INFO("%s: new layout ", __func__);
for (i = 0; i < num; i++)
DRM_INFO("(%i, %i %ux%u) ", rects[i].x, rects[i].y,
rects[i].w, rects[i].h);
DRM_INFO("\n");
}
#endif
list_for_each_entry(con, &dev->mode_config.connector_list, head) {
du = vmw_connector_to_du(con);
if (num > du->unit) {
du->pref_width = rects[du->unit].w;
du->pref_height = rects[du->unit].h;
du->pref_active = true;
du->gui_x = rects[du->unit].x;
du->gui_y = rects[du->unit].y;
} else {
du->pref_width = 800;
du->pref_height = 600;
du->pref_active = false;
}
con->status = vmw_du_connector_detect(con, true);
}
mutex_unlock(&dev->mode_config.mutex);
return 0;
}
void vmw_du_crtc_gamma_set(struct drm_crtc *crtc,
u16 *r, u16 *g, u16 *b,
uint32_t start, uint32_t size)
{
struct vmw_private *dev_priv = vmw_priv(crtc->dev);
int i;
for (i = 0; i < size; i++) {
DRM_DEBUG("%d r/g/b = 0x%04x / 0x%04x / 0x%04x\n", i,
r[i], g[i], b[i]);
vmw_write(dev_priv, SVGA_PALETTE_BASE + i * 3 + 0, r[i] >> 8);
vmw_write(dev_priv, SVGA_PALETTE_BASE + i * 3 + 1, g[i] >> 8);
vmw_write(dev_priv, SVGA_PALETTE_BASE + i * 3 + 2, b[i] >> 8);
}
}
int vmw_du_connector_dpms(struct drm_connector *connector, int mode)
{
return 0;
}
enum drm_connector_status
vmw_du_connector_detect(struct drm_connector *connector, bool force)
{
uint32_t num_displays;
struct drm_device *dev = connector->dev;
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_display_unit *du = vmw_connector_to_du(connector);
num_displays = vmw_read(dev_priv, SVGA_REG_NUM_DISPLAYS);
return ((vmw_connector_to_du(connector)->unit < num_displays &&
du->pref_active) ?
connector_status_connected : connector_status_disconnected);
}
void vmw_guess_mode_timing(struct drm_display_mode *mode)
{
mode->hsync_start = mode->hdisplay + 50;
mode->hsync_end = mode->hsync_start + 50;
mode->htotal = mode->hsync_end + 50;
mode->vsync_start = mode->vdisplay + 50;
mode->vsync_end = mode->vsync_start + 50;
mode->vtotal = mode->vsync_end + 50;
mode->clock = (u32)mode->htotal * (u32)mode->vtotal / 100 * 6;
mode->vrefresh = drm_mode_vrefresh(mode);
}
int vmw_du_connector_fill_modes(struct drm_connector *connector,
uint32_t max_width, uint32_t max_height)
{
struct vmw_display_unit *du = vmw_connector_to_du(connector);
struct drm_device *dev = connector->dev;
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_display_mode *mode = NULL;
struct drm_display_mode *bmode;
struct drm_display_mode prefmode = { DRM_MODE("preferred",
DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
DRM_MODE_FLAG_NHSYNC | DRM_MODE_FLAG_PVSYNC)
};
int i;
u32 assumed_bpp = 2;
if (dev_priv->active_display_unit == vmw_du_screen_object)
assumed_bpp = 4;
if (dev_priv->active_display_unit == vmw_du_screen_target) {
max_width = min(max_width, dev_priv->stdu_max_width);
max_height = min(max_height, dev_priv->stdu_max_height);
}
mode = drm_mode_duplicate(dev, &prefmode);
if (!mode)
return 0;
mode->hdisplay = du->pref_width;
mode->vdisplay = du->pref_height;
vmw_guess_mode_timing(mode);
if (vmw_kms_validate_mode_vram(dev_priv,
mode->hdisplay * assumed_bpp,
mode->vdisplay)) {
drm_mode_probed_add(connector, mode);
} else {
drm_mode_destroy(dev, mode);
mode = NULL;
}
if (du->pref_mode) {
list_del_init(&du->pref_mode->head);
drm_mode_destroy(dev, du->pref_mode);
}
du->pref_mode = mode;
for (i = 0; vmw_kms_connector_builtin[i].type != 0; i++) {
bmode = &vmw_kms_connector_builtin[i];
if (bmode->hdisplay > max_width ||
bmode->vdisplay > max_height)
continue;
if (!vmw_kms_validate_mode_vram(dev_priv,
bmode->hdisplay * assumed_bpp,
bmode->vdisplay))
continue;
mode = drm_mode_duplicate(dev, bmode);
if (!mode)
return 0;
mode->vrefresh = drm_mode_vrefresh(mode);
drm_mode_probed_add(connector, mode);
}
drm_mode_connector_list_update(connector);
drm_mode_sort(&connector->modes);
return 1;
}
int vmw_du_connector_set_property(struct drm_connector *connector,
struct drm_property *property,
uint64_t val)
{
return 0;
}
int vmw_kms_update_layout_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_update_layout_arg *arg =
(struct drm_vmw_update_layout_arg *)data;
void __user *user_rects;
struct drm_vmw_rect *rects;
unsigned rects_size;
int ret;
int i;
u64 total_pixels = 0;
struct drm_mode_config *mode_config = &dev->mode_config;
struct drm_vmw_rect bounding_box = {0};
if (!arg->num_outputs) {
struct drm_vmw_rect def_rect = {0, 0, 800, 600};
vmw_du_update_layout(dev_priv, 1, &def_rect);
return 0;
}
rects_size = arg->num_outputs * sizeof(struct drm_vmw_rect);
rects = kcalloc(arg->num_outputs, sizeof(struct drm_vmw_rect),
GFP_KERNEL);
if (unlikely(!rects))
return -ENOMEM;
user_rects = (void __user *)(unsigned long)arg->rects;
ret = copy_from_user(rects, user_rects, rects_size);
if (unlikely(ret != 0)) {
DRM_ERROR("Failed to get rects.\n");
ret = -EFAULT;
goto out_free;
}
for (i = 0; i < arg->num_outputs; ++i) {
if (rects[i].x < 0 ||
rects[i].y < 0 ||
rects[i].x + rects[i].w > mode_config->max_width ||
rects[i].y + rects[i].h > mode_config->max_height) {
DRM_ERROR("Invalid GUI layout.\n");
ret = -EINVAL;
goto out_free;
}
if (rects[i].x + rects[i].w > bounding_box.w)
bounding_box.w = rects[i].x + rects[i].w;
if (rects[i].y + rects[i].h > bounding_box.h)
bounding_box.h = rects[i].y + rects[i].h;
total_pixels += (u64) rects[i].w * (u64) rects[i].h;
}
if (dev_priv->active_display_unit == vmw_du_screen_target) {
u64 bb_mem = bounding_box.w * bounding_box.h * 4;
u64 pixel_mem = total_pixels * 4;
if (bb_mem > dev_priv->prim_bb_mem) {
DRM_ERROR("Topology is beyond supported limits.\n");
ret = -EINVAL;
goto out_free;
}
if (pixel_mem > dev_priv->prim_bb_mem) {
DRM_ERROR("Combined output size too large\n");
ret = -EINVAL;
goto out_free;
}
}
vmw_du_update_layout(dev_priv, arg->num_outputs, rects);
out_free:
kfree(rects);
return ret;
}
int vmw_kms_helper_dirty(struct vmw_private *dev_priv,
struct vmw_framebuffer *framebuffer,
const struct drm_clip_rect *clips,
const struct drm_vmw_rect *vclips,
s32 dest_x, s32 dest_y,
int num_clips,
int increment,
struct vmw_kms_dirty *dirty)
{
struct vmw_display_unit *units[VMWGFX_NUM_DISPLAY_UNITS];
struct drm_crtc *crtc;
u32 num_units = 0;
u32 i, k;
dirty->dev_priv = dev_priv;
list_for_each_entry(crtc, &dev_priv->dev->mode_config.crtc_list, head) {
if (crtc->primary->fb != &framebuffer->base)
continue;
units[num_units++] = vmw_crtc_to_du(crtc);
}
for (k = 0; k < num_units; k++) {
struct vmw_display_unit *unit = units[k];
s32 crtc_x = unit->crtc.x;
s32 crtc_y = unit->crtc.y;
s32 crtc_width = unit->crtc.mode.hdisplay;
s32 crtc_height = unit->crtc.mode.vdisplay;
const struct drm_clip_rect *clips_ptr = clips;
const struct drm_vmw_rect *vclips_ptr = vclips;
dirty->unit = unit;
if (dirty->fifo_reserve_size > 0) {
dirty->cmd = vmw_fifo_reserve(dev_priv,
dirty->fifo_reserve_size);
if (!dirty->cmd) {
DRM_ERROR("Couldn't reserve fifo space "
"for dirty blits.\n");
return -ENOMEM;
}
memset(dirty->cmd, 0, dirty->fifo_reserve_size);
}
dirty->num_hits = 0;
for (i = 0; i < num_clips; i++, clips_ptr += increment,
vclips_ptr += increment) {
s32 clip_left;
s32 clip_top;
if (clips) {
dirty->fb_x = (s32) clips_ptr->x1;
dirty->fb_y = (s32) clips_ptr->y1;
dirty->unit_x2 = (s32) clips_ptr->x2 + dest_x -
crtc_x;
dirty->unit_y2 = (s32) clips_ptr->y2 + dest_y -
crtc_y;
} else {
dirty->fb_x = vclips_ptr->x;
dirty->fb_y = vclips_ptr->y;
dirty->unit_x2 = dirty->fb_x + vclips_ptr->w +
dest_x - crtc_x;
dirty->unit_y2 = dirty->fb_y + vclips_ptr->h +
dest_y - crtc_y;
}
dirty->unit_x1 = dirty->fb_x + dest_x - crtc_x;
dirty->unit_y1 = dirty->fb_y + dest_y - crtc_y;
if (dirty->unit_x1 >= crtc_width ||
dirty->unit_y1 >= crtc_height ||
dirty->unit_x2 <= 0 || dirty->unit_y2 <= 0)
continue;
dirty->unit_x2 = min_t(s32, dirty->unit_x2,
crtc_width);
dirty->unit_y2 = min_t(s32, dirty->unit_y2,
crtc_height);
clip_left = min_t(s32, dirty->unit_x1, 0);
clip_top = min_t(s32, dirty->unit_y1, 0);
dirty->unit_x1 -= clip_left;
dirty->unit_y1 -= clip_top;
dirty->fb_x -= clip_left;
dirty->fb_y -= clip_top;
dirty->clip(dirty);
}
dirty->fifo_commit(dirty);
}
return 0;
}
int vmw_kms_helper_buffer_prepare(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
bool interruptible,
bool validate_as_mob)
{
struct ttm_buffer_object *bo = &buf->base;
int ret;
ttm_bo_reserve(bo, false, false, interruptible, NULL);
ret = vmw_validate_single_buffer(dev_priv, bo, interruptible,
validate_as_mob);
if (ret)
ttm_bo_unreserve(bo);
return ret;
}
void vmw_kms_helper_buffer_revert(struct vmw_dma_buffer *buf)
{
if (buf)
ttm_bo_unreserve(&buf->base);
}
void vmw_kms_helper_buffer_finish(struct vmw_private *dev_priv,
struct drm_file *file_priv,
struct vmw_dma_buffer *buf,
struct vmw_fence_obj **out_fence,
struct drm_vmw_fence_rep __user *
user_fence_rep)
{
struct vmw_fence_obj *fence;
uint32_t handle;
int ret;
ret = vmw_execbuf_fence_commands(file_priv, dev_priv, &fence,
file_priv ? &handle : NULL);
if (buf)
vmw_fence_single_bo(&buf->base, fence);
if (file_priv)
vmw_execbuf_copy_fence_user(dev_priv, vmw_fpriv(file_priv),
ret, user_fence_rep, fence,
handle);
if (out_fence)
*out_fence = fence;
else
vmw_fence_obj_unreference(&fence);
vmw_kms_helper_buffer_revert(buf);
}
void vmw_kms_helper_resource_revert(struct vmw_resource *res)
{
vmw_kms_helper_buffer_revert(res->backup);
vmw_resource_unreserve(res, false, NULL, 0);
mutex_unlock(&res->dev_priv->cmdbuf_mutex);
}
int vmw_kms_helper_resource_prepare(struct vmw_resource *res,
bool interruptible)
{
int ret = 0;
if (interruptible)
ret = mutex_lock_interruptible(&res->dev_priv->cmdbuf_mutex);
else
mutex_lock(&res->dev_priv->cmdbuf_mutex);
if (unlikely(ret != 0))
return -ERESTARTSYS;
ret = vmw_resource_reserve(res, interruptible, false);
if (ret)
goto out_unlock;
if (res->backup) {
ret = vmw_kms_helper_buffer_prepare(res->dev_priv, res->backup,
interruptible,
res->dev_priv->has_mob);
if (ret)
goto out_unreserve;
}
ret = vmw_resource_validate(res);
if (ret)
goto out_revert;
return 0;
out_revert:
vmw_kms_helper_buffer_revert(res->backup);
out_unreserve:
vmw_resource_unreserve(res, false, NULL, 0);
out_unlock:
mutex_unlock(&res->dev_priv->cmdbuf_mutex);
return ret;
}
void vmw_kms_helper_resource_finish(struct vmw_resource *res,
struct vmw_fence_obj **out_fence)
{
if (res->backup || out_fence)
vmw_kms_helper_buffer_finish(res->dev_priv, NULL, res->backup,
out_fence, NULL);
vmw_resource_unreserve(res, false, NULL, 0);
mutex_unlock(&res->dev_priv->cmdbuf_mutex);
}
int vmw_kms_update_proxy(struct vmw_resource *res,
const struct drm_clip_rect *clips,
unsigned num_clips,
int increment)
{
struct vmw_private *dev_priv = res->dev_priv;
struct drm_vmw_size *size = &vmw_res_to_srf(res)->base_size;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdUpdateGBImage body;
} *cmd;
SVGA3dBox *box;
size_t copy_size = 0;
int i;
if (!clips)
return 0;
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd) * num_clips);
if (!cmd) {
DRM_ERROR("Couldn't reserve fifo space for proxy surface "
"update.\n");
return -ENOMEM;
}
for (i = 0; i < num_clips; ++i, clips += increment, ++cmd) {
box = &cmd->body.box;
cmd->header.id = SVGA_3D_CMD_UPDATE_GB_IMAGE;
cmd->header.size = sizeof(cmd->body);
cmd->body.image.sid = res->id;
cmd->body.image.face = 0;
cmd->body.image.mipmap = 0;
if (clips->x1 > size->width || clips->x2 > size->width ||
clips->y1 > size->height || clips->y2 > size->height) {
DRM_ERROR("Invalid clips outsize of framebuffer.\n");
return -EINVAL;
}
box->x = clips->x1;
box->y = clips->y1;
box->z = 0;
box->w = clips->x2 - clips->x1;
box->h = clips->y2 - clips->y1;
box->d = 1;
copy_size += sizeof(*cmd);
}
vmw_fifo_commit(dev_priv, copy_size);
return 0;
}
int vmw_kms_fbdev_init_data(struct vmw_private *dev_priv,
unsigned unit,
u32 max_width,
u32 max_height,
struct drm_connector **p_con,
struct drm_crtc **p_crtc,
struct drm_display_mode **p_mode)
{
struct drm_connector *con;
struct vmw_display_unit *du;
struct drm_display_mode *mode;
int i = 0;
list_for_each_entry(con, &dev_priv->dev->mode_config.connector_list,
head) {
if (i == unit)
break;
++i;
}
if (i != unit) {
DRM_ERROR("Could not find initial display unit.\n");
return -EINVAL;
}
if (list_empty(&con->modes))
(void) vmw_du_connector_fill_modes(con, max_width, max_height);
if (list_empty(&con->modes)) {
DRM_ERROR("Could not find initial display mode.\n");
return -EINVAL;
}
du = vmw_connector_to_du(con);
*p_con = con;
*p_crtc = &du->crtc;
list_for_each_entry(mode, &con->modes, head) {
if (mode->type & DRM_MODE_TYPE_PREFERRED)
break;
}
if (mode->type & DRM_MODE_TYPE_PREFERRED)
*p_mode = mode;
else {
WARN_ONCE(true, "Could not find initial preferred mode.\n");
*p_mode = list_first_entry(&con->modes,
struct drm_display_mode,
head);
}
return 0;
}
