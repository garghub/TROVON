static int compat_radeon_cp_init(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_init32_t init32;
drm_radeon_init_t __user *init;
if (copy_from_user(&init32, (void __user *)arg, sizeof(init32)))
return -EFAULT;
init = compat_alloc_user_space(sizeof(*init));
if (!access_ok(VERIFY_WRITE, init, sizeof(*init))
|| __put_user(init32.func, &init->func)
|| __put_user(init32.sarea_priv_offset, &init->sarea_priv_offset)
|| __put_user(init32.is_pci, &init->is_pci)
|| __put_user(init32.cp_mode, &init->cp_mode)
|| __put_user(init32.gart_size, &init->gart_size)
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
|| __put_user(init32.fb_offset, &init->fb_offset)
|| __put_user(init32.mmio_offset, &init->mmio_offset)
|| __put_user(init32.ring_offset, &init->ring_offset)
|| __put_user(init32.ring_rptr_offset, &init->ring_rptr_offset)
|| __put_user(init32.buffers_offset, &init->buffers_offset)
|| __put_user(init32.gart_textures_offset,
&init->gart_textures_offset))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_CP_INIT, (unsigned long)init);
}
static int compat_radeon_cp_clear(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_clear32_t clr32;
drm_radeon_clear_t __user *clr;
if (copy_from_user(&clr32, (void __user *)arg, sizeof(clr32)))
return -EFAULT;
clr = compat_alloc_user_space(sizeof(*clr));
if (!access_ok(VERIFY_WRITE, clr, sizeof(*clr))
|| __put_user(clr32.flags, &clr->flags)
|| __put_user(clr32.clear_color, &clr->clear_color)
|| __put_user(clr32.clear_depth, &clr->clear_depth)
|| __put_user(clr32.color_mask, &clr->color_mask)
|| __put_user(clr32.depth_mask, &clr->depth_mask)
|| __put_user((void __user *)(unsigned long)clr32.depth_boxes,
&clr->depth_boxes))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_CLEAR, (unsigned long)clr);
}
static int compat_radeon_cp_stipple(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_stipple32_t __user *argp = (void __user *)arg;
drm_radeon_stipple_t __user *request;
u32 mask;
if (get_user(mask, &argp->mask))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user((unsigned int __user *)(unsigned long)mask,
&request->mask))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_STIPPLE, (unsigned long)request);
}
static int compat_radeon_cp_texture(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_texture32_t req32;
drm_radeon_texture_t __user *request;
drm_radeon_tex_image32_t img32;
drm_radeon_tex_image_t __user *image;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
if (req32.image == 0)
return -EINVAL;
if (copy_from_user(&img32, (void __user *)(unsigned long)req32.image,
sizeof(img32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request) + sizeof(*image));
if (!access_ok(VERIFY_WRITE, request,
sizeof(*request) + sizeof(*image)))
return -EFAULT;
image = (drm_radeon_tex_image_t __user *) (request + 1);
if (__put_user(req32.offset, &request->offset)
|| __put_user(req32.pitch, &request->pitch)
|| __put_user(req32.format, &request->format)
|| __put_user(req32.width, &request->width)
|| __put_user(req32.height, &request->height)
|| __put_user(image, &request->image)
|| __put_user(img32.x, &image->x)
|| __put_user(img32.y, &image->y)
|| __put_user(img32.width, &image->width)
|| __put_user(img32.height, &image->height)
|| __put_user((const void __user *)(unsigned long)img32.data,
&image->data))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_TEXTURE, (unsigned long)request);
}
static int compat_radeon_cp_vertex2(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_vertex2_32_t req32;
drm_radeon_vertex2_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.idx, &request->idx)
|| __put_user(req32.discard, &request->discard)
|| __put_user(req32.nr_states, &request->nr_states)
|| __put_user((void __user *)(unsigned long)req32.state,
&request->state)
|| __put_user(req32.nr_prims, &request->nr_prims)
|| __put_user((void __user *)(unsigned long)req32.prim,
&request->prim))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_VERTEX2, (unsigned long)request);
}
static int compat_radeon_cp_cmdbuf(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_cmd_buffer32_t req32;
drm_radeon_cmd_buffer_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.bufsz, &request->bufsz)
|| __put_user((void __user *)(unsigned long)req32.buf,
&request->buf)
|| __put_user(req32.nbox, &request->nbox)
|| __put_user((void __user *)(unsigned long)req32.boxes,
&request->boxes))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_CMDBUF, (unsigned long)request);
}
static int compat_radeon_cp_getparam(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_getparam32_t req32;
drm_radeon_getparam_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.param, &request->param)
|| __put_user((void __user *)(unsigned long)req32.value,
&request->value))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_GETPARAM, (unsigned long)request);
}
static int compat_radeon_mem_alloc(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_mem_alloc32_t req32;
drm_radeon_mem_alloc_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.region, &request->region)
|| __put_user(req32.alignment, &request->alignment)
|| __put_user(req32.size, &request->size)
|| __put_user((int __user *)(unsigned long)req32.region_offset,
&request->region_offset))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_ALLOC, (unsigned long)request);
}
static int compat_radeon_irq_emit(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_irq_emit32_t req32;
drm_radeon_irq_emit_t __user *request;
if (copy_from_user(&req32, (void __user *)arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user((int __user *)(unsigned long)req32.irq_seq,
&request->irq_seq))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_IRQ_EMIT, (unsigned long)request);
}
static int compat_radeon_cp_setparam(struct file *file, unsigned int cmd,
unsigned long arg)
{
drm_radeon_setparam32_t req32;
drm_radeon_setparam_t __user *request;
if (copy_from_user(&req32, (void __user *) arg, sizeof(req32)))
return -EFAULT;
request = compat_alloc_user_space(sizeof(*request));
if (!access_ok(VERIFY_WRITE, request, sizeof(*request))
|| __put_user(req32.param, &request->param)
|| __put_user((void __user *)(unsigned long)req32.value,
&request->value))
return -EFAULT;
return drm_ioctl(file, DRM_IOCTL_RADEON_SETPARAM, (unsigned long) request);
}
long radeon_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
drm_ioctl_compat_t *fn = NULL;
int ret;
if (nr < DRM_COMMAND_BASE)
return drm_compat_ioctl(filp, cmd, arg);
if (nr < DRM_COMMAND_BASE + ARRAY_SIZE(radeon_compat_ioctls))
fn = radeon_compat_ioctls[nr - DRM_COMMAND_BASE];
if (fn != NULL)
ret = (*fn) (filp, cmd, arg);
else
ret = drm_ioctl(filp, cmd, arg);
return ret;
}
long radeon_kms_compat_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned int nr = DRM_IOCTL_NR(cmd);
int ret;
if (nr < DRM_COMMAND_BASE)
return drm_compat_ioctl(filp, cmd, arg);
ret = radeon_drm_ioctl(filp, cmd, arg);
return ret;
}
