void psb_spank(struct drm_psb_private *dev_priv)
{
PSB_WSGX32(_PSB_CS_RESET_BIF_RESET | _PSB_CS_RESET_DPM_RESET |
_PSB_CS_RESET_TA_RESET | _PSB_CS_RESET_USE_RESET |
_PSB_CS_RESET_ISP_RESET | _PSB_CS_RESET_TSP_RESET |
_PSB_CS_RESET_TWOD_RESET, PSB_CR_SOFT_RESET);
PSB_RSGX32(PSB_CR_SOFT_RESET);
msleep(1);
PSB_WSGX32(0, PSB_CR_SOFT_RESET);
wmb();
PSB_WSGX32(PSB_RSGX32(PSB_CR_BIF_CTRL) | _PSB_CB_CTRL_CLEAR_FAULT,
PSB_CR_BIF_CTRL);
wmb();
(void) PSB_RSGX32(PSB_CR_BIF_CTRL);
msleep(1);
PSB_WSGX32(PSB_RSGX32(PSB_CR_BIF_CTRL) & ~_PSB_CB_CTRL_CLEAR_FAULT,
PSB_CR_BIF_CTRL);
(void) PSB_RSGX32(PSB_CR_BIF_CTRL);
PSB_WSGX32(dev_priv->gtt.gatt_start, PSB_CR_BIF_TWOD_REQ_BASE);
}
static int psb_2d_wait_available(struct drm_psb_private *dev_priv,
unsigned size)
{
uint32_t avail = PSB_RSGX32(PSB_CR_2D_SOCIF);
unsigned long t = jiffies + HZ;
while (avail < size) {
avail = PSB_RSGX32(PSB_CR_2D_SOCIF);
if (time_after(jiffies, t)) {
psb_spank(dev_priv);
return -EIO;
}
}
return 0;
}
static int psbfb_2d_submit(struct drm_psb_private *dev_priv, uint32_t *cmdbuf,
unsigned size)
{
int ret = 0;
int i;
unsigned submit_size;
unsigned long flags;
spin_lock_irqsave(&dev_priv->lock_2d, flags);
while (size > 0) {
submit_size = (size < 0x60) ? size : 0x60;
size -= submit_size;
ret = psb_2d_wait_available(dev_priv, submit_size);
if (ret)
break;
submit_size <<= 2;
for (i = 0; i < submit_size; i += 4)
PSB_WSGX32(*cmdbuf++, PSB_SGX_2D_SLAVE_PORT + i);
(void)PSB_RSGX32(PSB_SGX_2D_SLAVE_PORT + i - 4);
}
spin_unlock_irqrestore(&dev_priv->lock_2d, flags);
return ret;
}
static u32 psb_accel_2d_copy_direction(int xdir, int ydir)
{
if (xdir < 0)
return (ydir < 0) ? PSB_2D_COPYORDER_BR2TL :
PSB_2D_COPYORDER_TR2BL;
else
return (ydir < 0) ? PSB_2D_COPYORDER_BL2TR :
PSB_2D_COPYORDER_TL2BR;
}
static int psb_accel_2d_copy(struct drm_psb_private *dev_priv,
uint32_t src_offset, uint32_t src_stride,
uint32_t src_format, uint32_t dst_offset,
uint32_t dst_stride, uint32_t dst_format,
uint16_t src_x, uint16_t src_y,
uint16_t dst_x, uint16_t dst_y,
uint16_t size_x, uint16_t size_y)
{
uint32_t blit_cmd;
uint32_t buffer[10];
uint32_t *buf;
uint32_t direction;
buf = buffer;
direction =
psb_accel_2d_copy_direction(src_x - dst_x, src_y - dst_y);
if (direction == PSB_2D_COPYORDER_BR2TL ||
direction == PSB_2D_COPYORDER_TR2BL) {
src_x += size_x - 1;
dst_x += size_x - 1;
}
if (direction == PSB_2D_COPYORDER_BR2TL ||
direction == PSB_2D_COPYORDER_BL2TR) {
src_y += size_y - 1;
dst_y += size_y - 1;
}
blit_cmd =
PSB_2D_BLIT_BH |
PSB_2D_ROT_NONE |
PSB_2D_DSTCK_DISABLE |
PSB_2D_SRCCK_DISABLE |
PSB_2D_USE_PAT | PSB_2D_ROP3_SRCCOPY | direction;
*buf++ = PSB_2D_FENCE_BH;
*buf++ =
PSB_2D_DST_SURF_BH | dst_format | (dst_stride <<
PSB_2D_DST_STRIDE_SHIFT);
*buf++ = dst_offset;
*buf++ =
PSB_2D_SRC_SURF_BH | src_format | (src_stride <<
PSB_2D_SRC_STRIDE_SHIFT);
*buf++ = src_offset;
*buf++ =
PSB_2D_SRC_OFF_BH | (src_x << PSB_2D_SRCOFF_XSTART_SHIFT) |
(src_y << PSB_2D_SRCOFF_YSTART_SHIFT);
*buf++ = blit_cmd;
*buf++ =
(dst_x << PSB_2D_DST_XSTART_SHIFT) | (dst_y <<
PSB_2D_DST_YSTART_SHIFT);
*buf++ =
(size_x << PSB_2D_DST_XSIZE_SHIFT) | (size_y <<
PSB_2D_DST_YSIZE_SHIFT);
*buf++ = PSB_2D_FLUSH_BH;
return psbfb_2d_submit(dev_priv, buffer, buf - buffer);
}
static void psbfb_copyarea_accel(struct fb_info *info,
const struct fb_copyarea *a)
{
struct psb_fbdev *fbdev = info->par;
struct psb_framebuffer *psbfb = &fbdev->pfb;
struct drm_device *dev = psbfb->base.dev;
struct drm_framebuffer *fb = fbdev->psb_fb_helper.fb;
struct drm_psb_private *dev_priv = dev->dev_private;
uint32_t offset;
uint32_t stride;
uint32_t src_format;
uint32_t dst_format;
if (!fb)
return;
offset = psbfb->gtt->offset;
stride = fb->pitch;
switch (fb->depth) {
case 8:
src_format = PSB_2D_SRC_332RGB;
dst_format = PSB_2D_DST_332RGB;
break;
case 15:
src_format = PSB_2D_SRC_555RGB;
dst_format = PSB_2D_DST_555RGB;
break;
case 16:
src_format = PSB_2D_SRC_565RGB;
dst_format = PSB_2D_DST_565RGB;
break;
case 24:
case 32:
src_format = PSB_2D_SRC_8888ARGB;
dst_format = PSB_2D_DST_8888ARGB;
break;
default:
cfb_copyarea(info, a);
return;
}
if (!gma_power_begin(dev, false)) {
cfb_copyarea(info, a);
return;
}
psb_accel_2d_copy(dev_priv,
offset, stride, src_format,
offset, stride, dst_format,
a->sx, a->sy, a->dx, a->dy, a->width, a->height);
gma_power_end(dev);
}
void psbfb_copyarea(struct fb_info *info,
const struct fb_copyarea *region)
{
if (unlikely(info->state != FBINFO_STATE_RUNNING))
return;
if (region->width == 8 || region->height == 8 ||
(info->flags & FBINFO_HWACCEL_DISABLED))
return cfb_copyarea(info, region);
psbfb_copyarea_accel(info, region);
}
int psbfb_sync(struct fb_info *info)
{
struct psb_fbdev *fbdev = info->par;
struct psb_framebuffer *psbfb = &fbdev->pfb;
struct drm_device *dev = psbfb->base.dev;
struct drm_psb_private *dev_priv = dev->dev_private;
unsigned long _end = jiffies + DRM_HZ;
int busy = 0;
unsigned long flags;
spin_lock_irqsave(&dev_priv->lock_2d, flags);
if ((PSB_RSGX32(PSB_CR_2D_SOCIF) == _PSB_C2_SOCIF_EMPTY) &&
((PSB_RSGX32(PSB_CR_2D_BLIT_STATUS) & _PSB_C2B_STATUS_BUSY) == 0))
goto out;
do {
busy = (PSB_RSGX32(PSB_CR_2D_SOCIF) != _PSB_C2_SOCIF_EMPTY);
cpu_relax();
} while (busy && !time_after_eq(jiffies, _end));
if (busy)
busy = (PSB_RSGX32(PSB_CR_2D_SOCIF) != _PSB_C2_SOCIF_EMPTY);
if (busy)
goto out;
do {
busy = ((PSB_RSGX32(PSB_CR_2D_BLIT_STATUS) &
_PSB_C2B_STATUS_BUSY) != 0);
cpu_relax();
} while (busy && !time_after_eq(jiffies, _end));
if (busy)
busy = ((PSB_RSGX32(PSB_CR_2D_BLIT_STATUS) &
_PSB_C2B_STATUS_BUSY) != 0);
out:
spin_unlock_irqrestore(&dev_priv->lock_2d, flags);
return (busy) ? -EBUSY : 0;
}
int psb_accel_ioctl(struct drm_device *dev, void *data, struct drm_file *file)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct drm_psb_2d_op *op = data;
u32 *op_ptr = &op->cmd[0];
int i;
struct drm_gem_object *obj;
struct gtt_range *gtt;
int err = -EINVAL;
if (!dev_priv->ops->accel_2d)
return -EOPNOTSUPP;
if (op->size > PSB_2D_OP_BUFLEN)
return -EINVAL;
obj = drm_gem_object_lookup(dev, file, op->src);
if (obj == NULL)
return -ENOENT;
gtt = container_of(obj, struct gtt_range, gem);
if (psb_gtt_pin(gtt) < 0)
goto bad_2;
for (i = 0; i < op->size; i++, op_ptr++) {
u32 r = *op_ptr & 0xF0000000;
if (r == PSB_2D_SRC_SURF_BH ||
r == PSB_2D_DST_SURF_BH ||
r == PSB_2D_MASK_SURF_BH ||
r == PSB_2D_PAT_SURF_BH) {
i++;
op_ptr++;
if (i == op->size)
goto bad;
if (*op_ptr)
goto bad;
*op_ptr = gtt->offset;
continue;
}
}
psbfb_2d_submit(dev_priv, op->cmd, op->size);
err = 0;
bad:
psb_gtt_unpin(gtt);
bad_2:
drm_gem_object_unreference(obj);
return err;
}
