int drm_mode_create_dumb_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_create_dumb *args = data;
u32 cpp, stride, size;
if (!dev->driver->dumb_create)
return -ENOSYS;
if (!args->width || !args->height || !args->bpp)
return -EINVAL;
cpp = DIV_ROUND_UP(args->bpp, 8);
if (!cpp || cpp > 0xffffffffU / args->width)
return -EINVAL;
stride = cpp * args->width;
if (args->height > 0xffffffffU / stride)
return -EINVAL;
size = args->height * stride;
if (PAGE_ALIGN(size) == 0)
return -EINVAL;
args->handle = 0;
args->pitch = 0;
args->size = 0;
return dev->driver->dumb_create(file_priv, dev, args);
}
int drm_mode_mmap_dumb_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_map_dumb *args = data;
if (!dev->driver->dumb_create)
return -ENOSYS;
if (dev->driver->dumb_map_offset)
return dev->driver->dumb_map_offset(file_priv, dev,
args->handle,
&args->offset);
else
return drm_gem_dumb_map_offset(file_priv, dev, args->handle,
&args->offset);
}
int drm_mode_destroy_dumb_ioctl(struct drm_device *dev,
void *data, struct drm_file *file_priv)
{
struct drm_mode_destroy_dumb *args = data;
if (!dev->driver->dumb_create)
return -ENOSYS;
if (dev->driver->dumb_destroy)
return dev->driver->dumb_destroy(file_priv, dev, args->handle);
else
return drm_gem_dumb_destroy(file_priv, dev, args->handle);
}
