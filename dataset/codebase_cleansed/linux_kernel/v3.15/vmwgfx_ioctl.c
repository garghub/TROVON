int vmw_getparam_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_getparam_arg *param =
(struct drm_vmw_getparam_arg *)data;
struct vmw_fpriv *vmw_fp = vmw_fpriv(file_priv);
switch (param->param) {
case DRM_VMW_PARAM_NUM_STREAMS:
param->value = vmw_overlay_num_overlays(dev_priv);
break;
case DRM_VMW_PARAM_NUM_FREE_STREAMS:
param->value = vmw_overlay_num_free_overlays(dev_priv);
break;
case DRM_VMW_PARAM_3D:
param->value = vmw_fifo_have_3d(dev_priv) ? 1 : 0;
break;
case DRM_VMW_PARAM_HW_CAPS:
param->value = dev_priv->capabilities;
break;
case DRM_VMW_PARAM_FIFO_CAPS:
param->value = dev_priv->fifo.capabilities;
break;
case DRM_VMW_PARAM_MAX_FB_SIZE:
param->value = dev_priv->prim_bb_mem;
break;
case DRM_VMW_PARAM_FIFO_HW_VERSION:
{
__le32 __iomem *fifo_mem = dev_priv->mmio_virt;
const struct vmw_fifo_state *fifo = &dev_priv->fifo;
if ((dev_priv->capabilities & SVGA_CAP_GBOBJECTS)) {
param->value = SVGA3D_HWVERSION_WS8_B1;
break;
}
param->value =
ioread32(fifo_mem +
((fifo->capabilities &
SVGA_FIFO_CAP_3D_HWVERSION_REVISED) ?
SVGA_FIFO_3D_HWVERSION_REVISED :
SVGA_FIFO_3D_HWVERSION));
break;
}
case DRM_VMW_PARAM_MAX_SURF_MEMORY:
if ((dev_priv->capabilities & SVGA_CAP_GBOBJECTS) &&
!vmw_fp->gb_aware)
param->value = dev_priv->max_mob_pages * PAGE_SIZE / 2;
else
param->value = dev_priv->memory_size;
break;
case DRM_VMW_PARAM_3D_CAPS_SIZE:
if ((dev_priv->capabilities & SVGA_CAP_GBOBJECTS) &&
vmw_fp->gb_aware)
param->value = SVGA3D_DEVCAP_MAX * sizeof(uint32_t);
else if (dev_priv->capabilities & SVGA_CAP_GBOBJECTS)
param->value = sizeof(struct svga_3d_compat_cap) +
sizeof(uint32_t);
else
param->value = (SVGA_FIFO_3D_CAPS_LAST -
SVGA_FIFO_3D_CAPS + 1) *
sizeof(uint32_t);
break;
case DRM_VMW_PARAM_MAX_MOB_MEMORY:
vmw_fp->gb_aware = true;
param->value = dev_priv->max_mob_pages * PAGE_SIZE;
break;
case DRM_VMW_PARAM_MAX_MOB_SIZE:
param->value = dev_priv->max_mob_size;
break;
default:
DRM_ERROR("Illegal vmwgfx get param request: %d\n",
param->param);
return -EINVAL;
}
return 0;
}
static int vmw_fill_compat_cap(struct vmw_private *dev_priv, void *bounce,
size_t size)
{
struct svga_3d_compat_cap *compat_cap =
(struct svga_3d_compat_cap *) bounce;
unsigned int i;
size_t pair_offset = offsetof(struct svga_3d_compat_cap, pairs);
unsigned int max_size;
if (size < pair_offset)
return -EINVAL;
max_size = (size - pair_offset) / sizeof(SVGA3dCapPair);
if (max_size > SVGA3D_DEVCAP_MAX)
max_size = SVGA3D_DEVCAP_MAX;
compat_cap->header.length =
(pair_offset + max_size * sizeof(SVGA3dCapPair)) / sizeof(u32);
compat_cap->header.type = SVGA3DCAPS_RECORD_DEVCAPS;
mutex_lock(&dev_priv->hw_mutex);
for (i = 0; i < max_size; ++i) {
vmw_write(dev_priv, SVGA_REG_DEV_CAP, i);
compat_cap->pairs[i][0] = i;
compat_cap->pairs[i][1] = vmw_read(dev_priv, SVGA_REG_DEV_CAP);
}
mutex_unlock(&dev_priv->hw_mutex);
return 0;
}
int vmw_get_cap_3d_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vmw_get_3d_cap_arg *arg =
(struct drm_vmw_get_3d_cap_arg *) data;
struct vmw_private *dev_priv = vmw_priv(dev);
uint32_t size;
__le32 __iomem *fifo_mem;
void __user *buffer = (void __user *)((unsigned long)(arg->buffer));
void *bounce;
int ret;
bool gb_objects = !!(dev_priv->capabilities & SVGA_CAP_GBOBJECTS);
struct vmw_fpriv *vmw_fp = vmw_fpriv(file_priv);
if (unlikely(arg->pad64 != 0)) {
DRM_ERROR("Illegal GET_3D_CAP argument.\n");
return -EINVAL;
}
if (gb_objects && vmw_fp->gb_aware)
size = SVGA3D_DEVCAP_MAX * sizeof(uint32_t);
else if (gb_objects)
size = sizeof(struct svga_3d_compat_cap) + sizeof(uint32_t);
else
size = (SVGA_FIFO_3D_CAPS_LAST - SVGA_FIFO_3D_CAPS + 1) *
sizeof(uint32_t);
if (arg->max_size < size)
size = arg->max_size;
bounce = vzalloc(size);
if (unlikely(bounce == NULL)) {
DRM_ERROR("Failed to allocate bounce buffer for 3D caps.\n");
return -ENOMEM;
}
if (gb_objects && vmw_fp->gb_aware) {
int i, num;
uint32_t *bounce32 = (uint32_t *) bounce;
num = size / sizeof(uint32_t);
if (num > SVGA3D_DEVCAP_MAX)
num = SVGA3D_DEVCAP_MAX;
mutex_lock(&dev_priv->hw_mutex);
for (i = 0; i < num; ++i) {
vmw_write(dev_priv, SVGA_REG_DEV_CAP, i);
*bounce32++ = vmw_read(dev_priv, SVGA_REG_DEV_CAP);
}
mutex_unlock(&dev_priv->hw_mutex);
} else if (gb_objects) {
ret = vmw_fill_compat_cap(dev_priv, bounce, size);
if (unlikely(ret != 0))
goto out_err;
} else {
fifo_mem = dev_priv->mmio_virt;
memcpy_fromio(bounce, &fifo_mem[SVGA_FIFO_3D_CAPS], size);
}
ret = copy_to_user(buffer, bounce, size);
if (ret)
ret = -EFAULT;
out_err:
vfree(bounce);
if (unlikely(ret != 0))
DRM_ERROR("Failed to report 3D caps info.\n");
return ret;
}
int vmw_present_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_present_arg *arg =
(struct drm_vmw_present_arg *)data;
struct vmw_surface *surface;
struct drm_vmw_rect __user *clips_ptr;
struct drm_vmw_rect *clips = NULL;
struct drm_framebuffer *fb;
struct vmw_framebuffer *vfb;
struct vmw_resource *res;
uint32_t num_clips;
int ret;
num_clips = arg->num_clips;
clips_ptr = (struct drm_vmw_rect *)(unsigned long)arg->clips_ptr;
if (unlikely(num_clips == 0))
return 0;
if (clips_ptr == NULL) {
DRM_ERROR("Variable clips_ptr must be specified.\n");
ret = -EINVAL;
goto out_clips;
}
clips = kcalloc(num_clips, sizeof(*clips), GFP_KERNEL);
if (clips == NULL) {
DRM_ERROR("Failed to allocate clip rect list.\n");
ret = -ENOMEM;
goto out_clips;
}
ret = copy_from_user(clips, clips_ptr, num_clips * sizeof(*clips));
if (ret) {
DRM_ERROR("Failed to copy clip rects from userspace.\n");
ret = -EFAULT;
goto out_no_copy;
}
drm_modeset_lock_all(dev);
fb = drm_framebuffer_lookup(dev, arg->fb_id);
if (!fb) {
DRM_ERROR("Invalid framebuffer id.\n");
ret = -ENOENT;
goto out_no_fb;
}
vfb = vmw_framebuffer_to_vfb(fb);
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
goto out_no_ttm_lock;
ret = vmw_user_resource_lookup_handle(dev_priv, tfile, arg->sid,
user_surface_converter,
&res);
if (ret)
goto out_no_surface;
surface = vmw_res_to_srf(res);
ret = vmw_kms_present(dev_priv, file_priv,
vfb, surface, arg->sid,
arg->dest_x, arg->dest_y,
clips, num_clips);
vmw_surface_unreference(&surface);
out_no_surface:
ttm_read_unlock(&dev_priv->reservation_sem);
out_no_ttm_lock:
drm_framebuffer_unreference(fb);
out_no_fb:
drm_modeset_unlock_all(dev);
out_no_copy:
kfree(clips);
out_clips:
return ret;
}
int vmw_present_readback_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_present_readback_arg *arg =
(struct drm_vmw_present_readback_arg *)data;
struct drm_vmw_fence_rep __user *user_fence_rep =
(struct drm_vmw_fence_rep __user *)
(unsigned long)arg->fence_rep;
struct drm_vmw_rect __user *clips_ptr;
struct drm_vmw_rect *clips = NULL;
struct drm_framebuffer *fb;
struct vmw_framebuffer *vfb;
uint32_t num_clips;
int ret;
num_clips = arg->num_clips;
clips_ptr = (struct drm_vmw_rect *)(unsigned long)arg->clips_ptr;
if (unlikely(num_clips == 0))
return 0;
if (clips_ptr == NULL) {
DRM_ERROR("Argument clips_ptr must be specified.\n");
ret = -EINVAL;
goto out_clips;
}
clips = kcalloc(num_clips, sizeof(*clips), GFP_KERNEL);
if (clips == NULL) {
DRM_ERROR("Failed to allocate clip rect list.\n");
ret = -ENOMEM;
goto out_clips;
}
ret = copy_from_user(clips, clips_ptr, num_clips * sizeof(*clips));
if (ret) {
DRM_ERROR("Failed to copy clip rects from userspace.\n");
ret = -EFAULT;
goto out_no_copy;
}
drm_modeset_lock_all(dev);
fb = drm_framebuffer_lookup(dev, arg->fb_id);
if (!fb) {
DRM_ERROR("Invalid framebuffer id.\n");
ret = -ENOENT;
goto out_no_fb;
}
vfb = vmw_framebuffer_to_vfb(fb);
if (!vfb->dmabuf) {
DRM_ERROR("Framebuffer not dmabuf backed.\n");
ret = -EINVAL;
goto out_no_ttm_lock;
}
ret = ttm_read_lock(&dev_priv->reservation_sem, true);
if (unlikely(ret != 0))
goto out_no_ttm_lock;
ret = vmw_kms_readback(dev_priv, file_priv,
vfb, user_fence_rep,
clips, num_clips);
ttm_read_unlock(&dev_priv->reservation_sem);
out_no_ttm_lock:
drm_framebuffer_unreference(fb);
out_no_fb:
drm_modeset_unlock_all(dev);
out_no_copy:
kfree(clips);
out_clips:
return ret;
}
unsigned int vmw_fops_poll(struct file *filp, struct poll_table_struct *wait)
{
struct drm_file *file_priv = filp->private_data;
struct vmw_private *dev_priv =
vmw_priv(file_priv->minor->dev);
vmw_fifo_ping_host(dev_priv, SVGA_SYNC_GENERIC);
return drm_poll(filp, wait);
}
ssize_t vmw_fops_read(struct file *filp, char __user *buffer,
size_t count, loff_t *offset)
{
struct drm_file *file_priv = filp->private_data;
struct vmw_private *dev_priv =
vmw_priv(file_priv->minor->dev);
vmw_fifo_ping_host(dev_priv, SVGA_SYNC_GENERIC);
return drm_read(filp, buffer, count, offset);
}
