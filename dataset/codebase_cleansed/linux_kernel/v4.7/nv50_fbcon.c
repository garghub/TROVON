int
nv50_fbcon_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct nouveau_fbdev *nfbdev = info->par;
struct nouveau_drm *drm = nouveau_drm(nfbdev->dev);
struct nouveau_channel *chan = drm->channel;
int ret;
ret = RING_SPACE(chan, rect->rop == ROP_COPY ? 7 : 11);
if (ret)
return ret;
if (rect->rop != ROP_COPY) {
BEGIN_NV04(chan, NvSub2D, 0x02ac, 1);
OUT_RING(chan, 1);
}
BEGIN_NV04(chan, NvSub2D, 0x0588, 1);
if (info->fix.visual == FB_VISUAL_TRUECOLOR ||
info->fix.visual == FB_VISUAL_DIRECTCOLOR)
OUT_RING(chan, ((uint32_t *)info->pseudo_palette)[rect->color]);
else
OUT_RING(chan, rect->color);
BEGIN_NV04(chan, NvSub2D, 0x0600, 4);
OUT_RING(chan, rect->dx);
OUT_RING(chan, rect->dy);
OUT_RING(chan, rect->dx + rect->width);
OUT_RING(chan, rect->dy + rect->height);
if (rect->rop != ROP_COPY) {
BEGIN_NV04(chan, NvSub2D, 0x02ac, 1);
OUT_RING(chan, 3);
}
FIRE_RING(chan);
return 0;
}
int
nv50_fbcon_copyarea(struct fb_info *info, const struct fb_copyarea *region)
{
struct nouveau_fbdev *nfbdev = info->par;
struct nouveau_drm *drm = nouveau_drm(nfbdev->dev);
struct nouveau_channel *chan = drm->channel;
int ret;
ret = RING_SPACE(chan, 12);
if (ret)
return ret;
BEGIN_NV04(chan, NvSub2D, 0x0110, 1);
OUT_RING(chan, 0);
BEGIN_NV04(chan, NvSub2D, 0x08b0, 4);
OUT_RING(chan, region->dx);
OUT_RING(chan, region->dy);
OUT_RING(chan, region->width);
OUT_RING(chan, region->height);
BEGIN_NV04(chan, NvSub2D, 0x08d0, 4);
OUT_RING(chan, 0);
OUT_RING(chan, region->sx);
OUT_RING(chan, 0);
OUT_RING(chan, region->sy);
FIRE_RING(chan);
return 0;
}
int
nv50_fbcon_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct nouveau_fbdev *nfbdev = info->par;
struct nouveau_drm *drm = nouveau_drm(nfbdev->dev);
struct nouveau_channel *chan = drm->channel;
uint32_t dwords, *data = (uint32_t *)image->data;
uint32_t mask = ~(~0 >> (32 - info->var.bits_per_pixel));
uint32_t *palette = info->pseudo_palette;
int ret;
if (image->depth != 1)
return -ENODEV;
ret = RING_SPACE(chan, 11);
if (ret)
return ret;
BEGIN_NV04(chan, NvSub2D, 0x0814, 2);
if (info->fix.visual == FB_VISUAL_TRUECOLOR ||
info->fix.visual == FB_VISUAL_DIRECTCOLOR) {
OUT_RING(chan, palette[image->bg_color] | mask);
OUT_RING(chan, palette[image->fg_color] | mask);
} else {
OUT_RING(chan, image->bg_color);
OUT_RING(chan, image->fg_color);
}
BEGIN_NV04(chan, NvSub2D, 0x0838, 2);
OUT_RING(chan, image->width);
OUT_RING(chan, image->height);
BEGIN_NV04(chan, NvSub2D, 0x0850, 4);
OUT_RING(chan, 0);
OUT_RING(chan, image->dx);
OUT_RING(chan, 0);
OUT_RING(chan, image->dy);
dwords = ALIGN(image->width * image->height, 32) >> 5;
while (dwords) {
int push = dwords > 2047 ? 2047 : dwords;
ret = RING_SPACE(chan, push + 1);
if (ret)
return ret;
dwords -= push;
BEGIN_NI04(chan, NvSub2D, 0x0860, push);
OUT_RINGp(chan, data, push);
data += push;
}
FIRE_RING(chan);
return 0;
}
int
nv50_fbcon_accel_init(struct fb_info *info)
{
struct nouveau_fbdev *nfbdev = info->par;
struct nouveau_framebuffer *fb = &nfbdev->nouveau_fb;
struct drm_device *dev = nfbdev->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct nouveau_channel *chan = drm->channel;
int ret, format;
switch (info->var.bits_per_pixel) {
case 8:
format = 0xf3;
break;
case 15:
format = 0xf8;
break;
case 16:
format = 0xe8;
break;
case 32:
switch (info->var.transp.length) {
case 0:
case 8:
format = 0xe6;
break;
case 2:
format = 0xd1;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
ret = nvif_object_init(&chan->user, 0x502d, 0x502d, NULL, 0,
&nfbdev->twod);
if (ret)
return ret;
ret = RING_SPACE(chan, 58);
if (ret) {
nouveau_fbcon_gpu_lockup(info);
return ret;
}
BEGIN_NV04(chan, NvSub2D, 0x0000, 1);
OUT_RING(chan, nfbdev->twod.handle);
BEGIN_NV04(chan, NvSub2D, 0x0184, 3);
OUT_RING(chan, chan->vram.handle);
OUT_RING(chan, chan->vram.handle);
OUT_RING(chan, chan->vram.handle);
BEGIN_NV04(chan, NvSub2D, 0x0290, 1);
OUT_RING(chan, 0);
BEGIN_NV04(chan, NvSub2D, 0x0888, 1);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x02ac, 1);
OUT_RING(chan, 3);
BEGIN_NV04(chan, NvSub2D, 0x02a0, 1);
OUT_RING(chan, 0x55);
BEGIN_NV04(chan, NvSub2D, 0x08c0, 4);
OUT_RING(chan, 0);
OUT_RING(chan, 1);
OUT_RING(chan, 0);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x0580, 2);
OUT_RING(chan, 4);
OUT_RING(chan, format);
BEGIN_NV04(chan, NvSub2D, 0x02e8, 2);
OUT_RING(chan, 2);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x0804, 1);
OUT_RING(chan, format);
BEGIN_NV04(chan, NvSub2D, 0x0800, 1);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x0808, 3);
OUT_RING(chan, 0);
OUT_RING(chan, 0);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x081c, 1);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x0840, 4);
OUT_RING(chan, 0);
OUT_RING(chan, 1);
OUT_RING(chan, 0);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x0200, 2);
OUT_RING(chan, format);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x0214, 5);
OUT_RING(chan, info->fix.line_length);
OUT_RING(chan, info->var.xres_virtual);
OUT_RING(chan, info->var.yres_virtual);
OUT_RING(chan, upper_32_bits(fb->vma.offset));
OUT_RING(chan, lower_32_bits(fb->vma.offset));
BEGIN_NV04(chan, NvSub2D, 0x0230, 2);
OUT_RING(chan, format);
OUT_RING(chan, 1);
BEGIN_NV04(chan, NvSub2D, 0x0244, 5);
OUT_RING(chan, info->fix.line_length);
OUT_RING(chan, info->var.xres_virtual);
OUT_RING(chan, info->var.yres_virtual);
OUT_RING(chan, upper_32_bits(fb->vma.offset));
OUT_RING(chan, lower_32_bits(fb->vma.offset));
FIRE_RING(chan);
return 0;
}
