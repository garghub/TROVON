static int compat_i915_batchbuffer(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_i915_batchbuffer32_t batchbuffer32;
drm_i915_batchbuffer_t __user *batchbuffer;
if (copy_from_user
(&batchbuffer32, (void __user *)arg, sizeof(batchbuffer32)))
return -EFAULT;
batchbuffer = compat_alloc_user_space(sizeof(*batchbuffer));
if (!access_ok(VERIFY_WRITE, batchbuffer, sizeof(*batchbuffer))
|| __put_user(batchbuffer32.start, &batchbuffer->start)
|| __put_user(batchbuffer32.used, &batchbuffer->used)
|| __put_user(batchbuffer32.DR1, &batchbuffer->DR1)
|| __put_user(batchbuffer32.DR4, &batchbuffer->DR4)
|| __put_user(batchbuffer32.num_cliprects,
&batchbuffer->num_cliprects)
|| __put_user((int __user *)(unsigned long)batchbuffer32.cliprects,
&batchbuffer->cliprects))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_I915_BATCHBUFFER,
(unsigned long)batchbuffer);
}
static int compat_i915_cmdbuffer(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_i915_cmdbuffer32_t cmdbuffer32;
drm_i915_cmdbuffer_t __user *cmdbuffer;
if (copy_from_user
(&cmdbuffer32, (void __user *)arg, sizeof(cmdbuffer32)))
return -EFAULT;
cmdbuffer = compat_alloc_user_space(sizeof(*cmdbuffer));
if (!access_ok(VERIFY_WRITE, cmdbuffer, sizeof(*cmdbuffer))
|| __put_user((int __user *)(unsigned long)cmdbuffer32.buf,
&cmdbuffer->buf)
|| __put_user(cmdbuffer32.sz, &cmdbuffer->sz)
|| __put_user(cmdbuffer32.DR1, &cmdbuffer->DR1)
|| __put_user(cmdbuffer32.DR4, &cmdbuffer->DR4)
|| __put_user(cmdbuffer32.num_cliprects, &cmdbuffer->num_cliprects)
|| __put_user((int __user *)(unsigned long)cmdbuffer32.cliprects,
&cmdbuffer->cliprects))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_I915_CMDBUFFER,
(unsigned long)cmdbuffer);
}
static int compat_i915_irq_emit(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_i915_irq_emit32_t req32;
drm_i915_irq_emit_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user((int __user *)(unsigned long)req32.irq_seq,
&request->irq_seq))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_I915_IRQ_EMIT,
(unsigned long)request);
}
static int compat_i915_getparam(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_i915_getparam32_t req32;
drm_i915_getparam_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.param, &request->param)
|| __put_user((void __user *)(unsigned long)req32.value,
&request->value))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_I915_GETPARAM,
(unsigned long)request);
}
static int compat_i915_alloc(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_i915_mem_alloc32_t req32;
drm_i915_mem_alloc_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.region, &request->region)
|| __put_user(req32.alignment, &request->alignment)
|| __put_user(req32.size, &request->size)
|| __put_user((void __user *)(unsigned long)req32.region_offset,
&request->region_offset))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_I915_ALLOC,
(unsigned long)request);
}
long i915_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
drm_ioctl_compat_t *fn = NULL;
int ret;
if (nr < DRM_COMMAND_BASE)
return drm_compat_ioctl(filp, cmd, arg);
if (nr < DRM_COMMAND_BASE + DRM_ARRAY_SIZE(i915_compat_ioctls))
fn = i915_compat_ioctls[nr - DRM_COMMAND_BASE];
if (fn != NULL)
ret = (*fn) (filp, cmd, arg);
else
ret = drm_ioctl(filp, cmd, arg);
return ret;
}
