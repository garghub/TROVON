static int compat_r128_init(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_r128_init32_t init32;
drm_r128_init_t __user *init;
if (copy_from_user(&init32, (void __user *)arg, sizeof(init32)))
return -EFAULT;
init = compat_alloc_user_space(sizeof(*init));
if (!access_ok(VERIFY_WRITE, init, sizeof(*init))
|| __put_user(init32.func, &init->func)
|| __put_user(init32.sarea_priv_offset, &init->sarea_priv_offset)
|| __put_user(init32.is_pci, &init->is_pci)
|| __put_user(init32.cce_mode, &init->cce_mode)
|| __put_user(init32.cce_secure, &init->cce_secure)
|| __put_user(init32.ring_size, &init->ring_size)
|| __put_user(init32.usec_timeout, &init->usec_timeout)
|| __put_user(init32.fb_bpp, &init->fb_bpp)
|| __put_user(init32.front_offset, &init->front_offset)
|| __put_user(init32.front_pitch, &init->front_pitch)
|| __put_user(init32.back_offset, &init->back_offset)
|| __put_user(init32.back_pitch, &init->back_pitch)
|| __put_user(init32.depth_bpp, &init->depth_bpp)
|| __put_user(init32.depth_offset, &init->depth_offset)
|| __put_user(init32.depth_pitch, &init->depth_pitch)
|| __put_user(init32.span_offset, &init->span_offset)
|| __put_user(init32.fb_offset, &init->fb_offset)
|| __put_user(init32.mmio_offset, &init->mmio_offset)
|| __put_user(init32.ring_offset, &init->ring_offset)
|| __put_user(init32.ring_rptr_offset, &init->ring_rptr_offset)
|| __put_user(init32.buffers_offset, &init->buffers_offset)
|| __put_user(init32.agp_textures_offset,
&init->agp_textures_offset))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_R128_INIT, (unsigned long)init);
}
static int compat_r128_depth(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_r128_depth32_t depth32;
drm_r128_depth_t __user *depth;
if (copy_from_user(&depth32, (void __user *)arg, sizeof(depth32)))
return -EFAULT;
depth = compat_alloc_user_space(sizeof(*depth));
if (!access_ok(VERIFY_WRITE, depth, sizeof(*depth))
|| __put_user(depth32.func, &depth->func)
|| __put_user(depth32.n, &depth->n)
|| __put_user((int __user *)(unsigned long)depth32.x, &depth->x)
|| __put_user((int __user *)(unsigned long)depth32.y, &depth->y)
|| __put_user((unsigned int __user *)(unsigned long)depth32.buffer,
&depth->buffer)
|| __put_user((unsigned char __user *)(unsigned long)depth32.mask,
&depth->mask))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_R128_DEPTH, (unsigned long)depth);
}
static int compat_r128_stipple(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_r128_stipple32_t stipple32;
drm_r128_stipple_t __user *stipple;
if (copy_from_user(&stipple32, (void __user *)arg, sizeof(stipple32)))
return -EFAULT;
stipple = compat_alloc_user_space(sizeof(*stipple));
if (!access_ok(VERIFY_WRITE, stipple, sizeof(*stipple))
|| __put_user((unsigned int __user *)(unsigned long)stipple32.mask,
&stipple->mask))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_R128_STIPPLE, (unsigned long)stipple);
}
static int compat_r128_getparam(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_r128_getparam32_t getparam32;
drm_r128_getparam_t __user *getparam;
if (copy_from_user(&getparam32, (void __user *)arg, sizeof(getparam32)))
return -EFAULT;
getparam = compat_alloc_user_space(sizeof(*getparam));
if (!access_ok(VERIFY_WRITE, getparam, sizeof(*getparam))
|| __put_user(getparam32.param, &getparam->param)
|| __put_user((void __user *)(unsigned long)getparam32.value,
&getparam->value))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_R128_GETPARAM, (unsigned long)getparam);
}
long r128_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
drm_ioctl_compat_t *fn = NULL;
int ret;
if (nr < DRM_COMMAND_BASE)
return drm_compat_ioctl(filp, cmd, arg);
if (nr < DRM_COMMAND_BASE + ARRAY_SIZE(r128_compat_ioctls))
fn = r128_compat_ioctls[nr - DRM_COMMAND_BASE];
if (fn != NULL)
ret = (*fn) (filp, cmd, arg);
else
ret = drm_ioctl(filp, cmd, arg);
return ret;
}
