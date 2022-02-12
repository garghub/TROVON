int vmw_getparam_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct drm_vmw_getparam_arg *param =
(struct drm_vmw_getparam_arg *)data;
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
case DRM_VMW_PARAM_FIFO_OFFSET:
param->value = dev_priv->mmio_start;
break;
case DRM_VMW_PARAM_HW_CAPS:
param->value = dev_priv->capabilities;
break;
case DRM_VMW_PARAM_FIFO_CAPS:
param->value = dev_priv->fifo.capabilities;
break;
case DRM_VMW_PARAM_MAX_FB_SIZE:
param->value = dev_priv->vram_size;
break;
default:
DRM_ERROR("Illegal vmwgfx get param request: %d\n",
param->param);
return -EINVAL;
}
return 0;
}
int vmw_fifo_debug_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_fifo_state *fifo_state = &dev_priv->fifo;
struct drm_vmw_fifo_debug_arg *arg =
(struct drm_vmw_fifo_debug_arg *)data;
__le32 __user *buffer = (__le32 __user *)
(unsigned long)arg->debug_buffer;
if (unlikely(fifo_state->last_buffer == NULL))
return -EINVAL;
if (arg->debug_buffer_size < fifo_state->last_data_size) {
arg->used_size = arg->debug_buffer_size;
arg->did_not_fit = 1;
} else {
arg->used_size = fifo_state->last_data_size;
arg->did_not_fit = 0;
}
return copy_to_user(buffer, fifo_state->last_buffer, arg->used_size);
}
