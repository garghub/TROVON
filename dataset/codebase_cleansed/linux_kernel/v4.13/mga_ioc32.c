static int compat_mga_init(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_mga_init32_t init32;
drm_mga_init_t init;
if (copy_from_user(&init32, (void __user *)arg, sizeof(init32)))
return -EFAULT;
init.func = init32.func;
init.sarea_priv_offset = init32.sarea_priv_offset;
memcpy(&init.chipset, &init32.chipset,
offsetof(drm_mga_init_t, fb_offset) -
offsetof(drm_mga_init_t, chipset));
init.fb_offset = init32.fb_offset;
init.mmio_offset = init32.mmio_offset;
init.status_offset = init32.status_offset;
init.warp_offset = init32.warp_offset;
init.primary_offset = init32.primary_offset;
init.buffers_offset = init32.buffers_offset;
return drm_ioctl_kernel(file, mga_dma_init, &init,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
}
static int compat_mga_getparam(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_mga_getparam32_t getparam32;
drm_mga_getparam_t getparam;
if (copy_from_user(&getparam32, (void __user *)arg, sizeof(getparam32)))
return -EFAULT;
getparam.param = getparam32.param;
getparam.value = compat_ptr(getparam32.value);
return drm_ioctl_kernel(file, mga_getparam, &getparam, DRM_AUTH);
}
static int compat_mga_dma_bootstrap(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_mga_dma_bootstrap32_t dma_bootstrap32;
drm_mga_dma_bootstrap_t dma_bootstrap;
int err;
if (copy_from_user(&dma_bootstrap32, (void __user *)arg,
sizeof(dma_bootstrap32)))
return -EFAULT;
dma_bootstrap.texture_handle = dma_bootstrap32.texture_handle;
dma_bootstrap.texture_size = dma_bootstrap32.texture_size;
dma_bootstrap.primary_size = dma_bootstrap32.primary_size;
dma_bootstrap.secondary_bin_count = dma_bootstrap32.secondary_bin_count;
dma_bootstrap.secondary_bin_size = dma_bootstrap32.secondary_bin_size;
dma_bootstrap.agp_mode = dma_bootstrap32.agp_mode;
dma_bootstrap.agp_size = dma_bootstrap32.agp_size;
err = drm_ioctl_kernel(file, mga_dma_bootstrap, &dma_bootstrap,
DRM_AUTH|DRM_MASTER|DRM_ROOT_ONLY);
if (err)
return err;
dma_bootstrap32.texture_handle = dma_bootstrap.texture_handle;
dma_bootstrap32.texture_size = dma_bootstrap.texture_size;
dma_bootstrap32.primary_size = dma_bootstrap.primary_size;
dma_bootstrap32.secondary_bin_count = dma_bootstrap.secondary_bin_count;
dma_bootstrap32.secondary_bin_size = dma_bootstrap.secondary_bin_size;
dma_bootstrap32.agp_mode = dma_bootstrap.agp_mode;
dma_bootstrap32.agp_size = dma_bootstrap.agp_size;
if (copy_to_user((void __user *)arg, &dma_bootstrap32,
sizeof(dma_bootstrap32)))
return -EFAULT;
return 0;
}
long mga_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
struct drm_file *file_priv = filp->private_data;
drm_ioctl_compat_t *fn = NULL;
int ret;
if (nr < DRM_COMMAND_BASE)
return drm_compat_ioctl(filp, cmd, arg);
if (nr >= DRM_COMMAND_BASE + ARRAY_SIZE(mga_compat_ioctls))
return drm_ioctl(filp, cmd, arg);
fn = mga_compat_ioctls[nr - DRM_COMMAND_BASE].fn;
if (!fn)
return drm_ioctl(filp, cmd, arg);
DRM_DEBUG("pid=%d, dev=0x%lx, auth=%d, %s\n",
task_pid_nr(current),
(long)old_encode_dev(file_priv->minor->kdev->devt),
file_priv->authenticated,
mga_compat_ioctls[nr - DRM_COMMAND_BASE].name);
ret = (*fn) (filp, cmd, arg);
if (ret)
DRM_DEBUG("ret = %d\n", ret);
return ret;
}
