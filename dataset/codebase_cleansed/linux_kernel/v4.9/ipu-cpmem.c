static inline struct ipu_ch_param __iomem *
ipu_get_cpmem(struct ipuv3_channel *ch)
{
struct ipu_cpmem *cpmem = ch->ipu->cpmem_priv;
return cpmem->base + ch->num;
}
static void ipu_ch_param_write_field(struct ipuv3_channel *ch, u32 wbs, u32 v)
{
struct ipu_ch_param __iomem *base = ipu_get_cpmem(ch);
u32 bit = (wbs >> 8) % 160;
u32 size = wbs & 0xff;
u32 word = (wbs >> 8) / 160;
u32 i = bit / 32;
u32 ofs = bit % 32;
u32 mask = (1 << size) - 1;
u32 val;
pr_debug("%s %d %d %d\n", __func__, word, bit , size);
val = readl(&base->word[word].data[i]);
val &= ~(mask << ofs);
val |= v << ofs;
writel(val, &base->word[word].data[i]);
if ((bit + size - 1) / 32 > i) {
val = readl(&base->word[word].data[i + 1]);
val &= ~(mask >> (ofs ? (32 - ofs) : 0));
val |= v >> (ofs ? (32 - ofs) : 0);
writel(val, &base->word[word].data[i + 1]);
}
}
static u32 ipu_ch_param_read_field(struct ipuv3_channel *ch, u32 wbs)
{
struct ipu_ch_param __iomem *base = ipu_get_cpmem(ch);
u32 bit = (wbs >> 8) % 160;
u32 size = wbs & 0xff;
u32 word = (wbs >> 8) / 160;
u32 i = bit / 32;
u32 ofs = bit % 32;
u32 mask = (1 << size) - 1;
u32 val = 0;
pr_debug("%s %d %d %d\n", __func__, word, bit , size);
val = (readl(&base->word[word].data[i]) >> ofs) & mask;
if ((bit + size - 1) / 32 > i) {
u32 tmp;
tmp = readl(&base->word[word].data[i + 1]);
tmp &= mask >> (ofs ? (32 - ofs) : 0);
val |= tmp << (ofs ? (32 - ofs) : 0);
}
return val;
}
static int v4l2_pix_fmt_to_drm_fourcc(u32 pixelformat)
{
switch (pixelformat) {
case V4L2_PIX_FMT_RGB565:
return DRM_FORMAT_RGB565;
case V4L2_PIX_FMT_BGR24:
return DRM_FORMAT_RGB888;
case V4L2_PIX_FMT_RGB24:
return DRM_FORMAT_BGR888;
case V4L2_PIX_FMT_BGR32:
return DRM_FORMAT_XRGB8888;
case V4L2_PIX_FMT_RGB32:
return DRM_FORMAT_XBGR8888;
case V4L2_PIX_FMT_UYVY:
return DRM_FORMAT_UYVY;
case V4L2_PIX_FMT_YUYV:
return DRM_FORMAT_YUYV;
case V4L2_PIX_FMT_YUV420:
return DRM_FORMAT_YUV420;
case V4L2_PIX_FMT_YUV422P:
return DRM_FORMAT_YUV422;
case V4L2_PIX_FMT_YVU420:
return DRM_FORMAT_YVU420;
case V4L2_PIX_FMT_NV12:
return DRM_FORMAT_NV12;
case V4L2_PIX_FMT_NV16:
return DRM_FORMAT_NV16;
}
return -EINVAL;
}
void ipu_cpmem_zero(struct ipuv3_channel *ch)
{
struct ipu_ch_param __iomem *p = ipu_get_cpmem(ch);
void __iomem *base = p;
int i;
for (i = 0; i < sizeof(*p) / sizeof(u32); i++)
writel(0, base + i * sizeof(u32));
}
void ipu_cpmem_set_resolution(struct ipuv3_channel *ch, int xres, int yres)
{
ipu_ch_param_write_field(ch, IPU_FIELD_FW, xres - 1);
ipu_ch_param_write_field(ch, IPU_FIELD_FH, yres - 1);
}
void ipu_cpmem_set_stride(struct ipuv3_channel *ch, int stride)
{
ipu_ch_param_write_field(ch, IPU_FIELD_SLY, stride - 1);
}
void ipu_cpmem_set_high_priority(struct ipuv3_channel *ch)
{
struct ipu_soc *ipu = ch->ipu;
u32 val;
if (ipu->ipu_type == IPUV3EX)
ipu_ch_param_write_field(ch, IPU_FIELD_ID, 1);
val = ipu_idmac_read(ipu, IDMAC_CHA_PRI(ch->num));
val |= 1 << (ch->num % 32);
ipu_idmac_write(ipu, val, IDMAC_CHA_PRI(ch->num));
}
void ipu_cpmem_set_buffer(struct ipuv3_channel *ch, int bufnum, dma_addr_t buf)
{
if (bufnum)
ipu_ch_param_write_field(ch, IPU_FIELD_EBA1, buf >> 3);
else
ipu_ch_param_write_field(ch, IPU_FIELD_EBA0, buf >> 3);
}
void ipu_cpmem_set_uv_offset(struct ipuv3_channel *ch, u32 u_off, u32 v_off)
{
ipu_ch_param_write_field(ch, IPU_FIELD_UBO, u_off / 8);
ipu_ch_param_write_field(ch, IPU_FIELD_VBO, v_off / 8);
}
void ipu_cpmem_interlaced_scan(struct ipuv3_channel *ch, int stride)
{
ipu_ch_param_write_field(ch, IPU_FIELD_SO, 1);
ipu_ch_param_write_field(ch, IPU_FIELD_ILO, stride / 8);
ipu_ch_param_write_field(ch, IPU_FIELD_SLY, (stride * 2) - 1);
}
void ipu_cpmem_set_axi_id(struct ipuv3_channel *ch, u32 id)
{
id &= 0x3;
ipu_ch_param_write_field(ch, IPU_FIELD_ID, id);
}
int ipu_cpmem_get_burstsize(struct ipuv3_channel *ch)
{
return ipu_ch_param_read_field(ch, IPU_FIELD_NPB) + 1;
}
void ipu_cpmem_set_burstsize(struct ipuv3_channel *ch, int burstsize)
{
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, burstsize - 1);
}
void ipu_cpmem_set_block_mode(struct ipuv3_channel *ch)
{
ipu_ch_param_write_field(ch, IPU_FIELD_BM, 1);
}
void ipu_cpmem_set_rotation(struct ipuv3_channel *ch,
enum ipu_rotate_mode rot)
{
u32 temp_rot = bitrev8(rot) >> 5;
ipu_ch_param_write_field(ch, IPU_FIELD_ROT_HF_VF, temp_rot);
}
int ipu_cpmem_set_format_rgb(struct ipuv3_channel *ch,
const struct ipu_rgb *rgb)
{
int bpp = 0, npb = 0, ro, go, bo, to;
ro = rgb->bits_per_pixel - rgb->red.length - rgb->red.offset;
go = rgb->bits_per_pixel - rgb->green.length - rgb->green.offset;
bo = rgb->bits_per_pixel - rgb->blue.length - rgb->blue.offset;
to = rgb->bits_per_pixel - rgb->transp.length - rgb->transp.offset;
ipu_ch_param_write_field(ch, IPU_FIELD_WID0, rgb->red.length - 1);
ipu_ch_param_write_field(ch, IPU_FIELD_OFS0, ro);
ipu_ch_param_write_field(ch, IPU_FIELD_WID1, rgb->green.length - 1);
ipu_ch_param_write_field(ch, IPU_FIELD_OFS1, go);
ipu_ch_param_write_field(ch, IPU_FIELD_WID2, rgb->blue.length - 1);
ipu_ch_param_write_field(ch, IPU_FIELD_OFS2, bo);
if (rgb->transp.length) {
ipu_ch_param_write_field(ch, IPU_FIELD_WID3,
rgb->transp.length - 1);
ipu_ch_param_write_field(ch, IPU_FIELD_OFS3, to);
} else {
ipu_ch_param_write_field(ch, IPU_FIELD_WID3, 7);
ipu_ch_param_write_field(ch, IPU_FIELD_OFS3,
rgb->bits_per_pixel);
}
switch (rgb->bits_per_pixel) {
case 32:
bpp = 0;
npb = 15;
break;
case 24:
bpp = 1;
npb = 19;
break;
case 16:
bpp = 3;
npb = 31;
break;
case 8:
bpp = 5;
npb = 63;
break;
default:
return -EINVAL;
}
ipu_ch_param_write_field(ch, IPU_FIELD_BPP, bpp);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, npb);
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 7);
return 0;
}
int ipu_cpmem_set_format_passthrough(struct ipuv3_channel *ch, int width)
{
int bpp = 0, npb = 0;
switch (width) {
case 32:
bpp = 0;
npb = 15;
break;
case 24:
bpp = 1;
npb = 19;
break;
case 16:
bpp = 3;
npb = 31;
break;
case 8:
bpp = 5;
npb = 63;
break;
default:
return -EINVAL;
}
ipu_ch_param_write_field(ch, IPU_FIELD_BPP, bpp);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, npb);
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 6);
return 0;
}
void ipu_cpmem_set_yuv_interleaved(struct ipuv3_channel *ch, u32 pixel_format)
{
switch (pixel_format) {
case V4L2_PIX_FMT_UYVY:
ipu_ch_param_write_field(ch, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 0xA);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
case V4L2_PIX_FMT_YUYV:
ipu_ch_param_write_field(ch, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 0x8);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
}
}
void ipu_cpmem_set_yuv_planar_full(struct ipuv3_channel *ch,
unsigned int uv_stride,
unsigned int u_offset, unsigned int v_offset)
{
ipu_ch_param_write_field(ch, IPU_FIELD_SLUV, uv_stride - 1);
ipu_ch_param_write_field(ch, IPU_FIELD_UBO, u_offset / 8);
ipu_ch_param_write_field(ch, IPU_FIELD_VBO, v_offset / 8);
}
void ipu_cpmem_set_yuv_planar(struct ipuv3_channel *ch,
u32 pixel_format, int stride, int height)
{
int fourcc, u_offset, v_offset;
int uv_stride = 0;
fourcc = v4l2_pix_fmt_to_drm_fourcc(pixel_format);
switch (fourcc) {
case DRM_FORMAT_YUV420:
uv_stride = stride / 2;
u_offset = stride * height;
v_offset = u_offset + (uv_stride * height / 2);
break;
case DRM_FORMAT_YVU420:
uv_stride = stride / 2;
v_offset = stride * height;
u_offset = v_offset + (uv_stride * height / 2);
break;
case DRM_FORMAT_YUV422:
uv_stride = stride / 2;
u_offset = stride * height;
v_offset = u_offset + (uv_stride * height);
break;
case DRM_FORMAT_NV12:
case DRM_FORMAT_NV16:
uv_stride = stride;
u_offset = stride * height;
v_offset = 0;
break;
default:
return;
}
ipu_cpmem_set_yuv_planar_full(ch, uv_stride, u_offset, v_offset);
}
int ipu_cpmem_set_fmt(struct ipuv3_channel *ch, u32 drm_fourcc)
{
switch (drm_fourcc) {
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 2);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_YUV422:
case DRM_FORMAT_YVU422:
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 1);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_NV12:
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 4);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_NV16:
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 3);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_UYVY:
ipu_ch_param_write_field(ch, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 0xA);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_YUYV:
ipu_ch_param_write_field(ch, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(ch, IPU_FIELD_PFS, 0x8);
ipu_ch_param_write_field(ch, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_XBGR8888:
ipu_cpmem_set_format_rgb(ch, &def_xbgr_32);
break;
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_XRGB8888:
ipu_cpmem_set_format_rgb(ch, &def_xrgb_32);
break;
case DRM_FORMAT_RGBA8888:
case DRM_FORMAT_RGBX8888:
ipu_cpmem_set_format_rgb(ch, &def_rgbx_32);
break;
case DRM_FORMAT_BGRA8888:
case DRM_FORMAT_BGRX8888:
ipu_cpmem_set_format_rgb(ch, &def_bgrx_32);
break;
case DRM_FORMAT_BGR888:
ipu_cpmem_set_format_rgb(ch, &def_bgr_24);
break;
case DRM_FORMAT_RGB888:
ipu_cpmem_set_format_rgb(ch, &def_rgb_24);
break;
case DRM_FORMAT_RGB565:
ipu_cpmem_set_format_rgb(ch, &def_rgb_16);
break;
case DRM_FORMAT_BGR565:
ipu_cpmem_set_format_rgb(ch, &def_bgr_16);
break;
case DRM_FORMAT_ARGB1555:
ipu_cpmem_set_format_rgb(ch, &def_argb_16);
break;
case DRM_FORMAT_ABGR1555:
ipu_cpmem_set_format_rgb(ch, &def_abgr_16);
break;
case DRM_FORMAT_RGBA5551:
ipu_cpmem_set_format_rgb(ch, &def_rgba_16);
break;
case DRM_FORMAT_BGRA5551:
ipu_cpmem_set_format_rgb(ch, &def_bgra_16);
break;
case DRM_FORMAT_ARGB4444:
ipu_cpmem_set_format_rgb(ch, &def_argb_16_4444);
break;
default:
return -EINVAL;
}
return 0;
}
int ipu_cpmem_set_image(struct ipuv3_channel *ch, struct ipu_image *image)
{
struct v4l2_pix_format *pix = &image->pix;
int offset, u_offset, v_offset;
pr_debug("%s: resolution: %dx%d stride: %d\n",
__func__, pix->width, pix->height,
pix->bytesperline);
ipu_cpmem_set_resolution(ch, image->rect.width, image->rect.height);
ipu_cpmem_set_stride(ch, pix->bytesperline);
ipu_cpmem_set_fmt(ch, v4l2_pix_fmt_to_drm_fourcc(pix->pixelformat));
switch (pix->pixelformat) {
case V4L2_PIX_FMT_YUV420:
offset = Y_OFFSET(pix, image->rect.left, image->rect.top);
u_offset = U_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
v_offset = V_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
ipu_cpmem_set_yuv_planar_full(ch, pix->bytesperline / 2,
u_offset, v_offset);
break;
case V4L2_PIX_FMT_YVU420:
offset = Y_OFFSET(pix, image->rect.left, image->rect.top);
u_offset = U_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
v_offset = V_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
ipu_cpmem_set_yuv_planar_full(ch, pix->bytesperline / 2,
v_offset, u_offset);
break;
case V4L2_PIX_FMT_YUV422P:
offset = Y_OFFSET(pix, image->rect.left, image->rect.top);
u_offset = U2_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
v_offset = V2_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
ipu_cpmem_set_yuv_planar_full(ch, pix->bytesperline / 2,
u_offset, v_offset);
break;
case V4L2_PIX_FMT_NV12:
offset = Y_OFFSET(pix, image->rect.left, image->rect.top);
u_offset = UV_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
v_offset = 0;
ipu_cpmem_set_yuv_planar_full(ch, pix->bytesperline,
u_offset, v_offset);
break;
case V4L2_PIX_FMT_NV16:
offset = Y_OFFSET(pix, image->rect.left, image->rect.top);
u_offset = UV2_OFFSET(pix, image->rect.left,
image->rect.top) - offset;
v_offset = 0;
ipu_cpmem_set_yuv_planar_full(ch, pix->bytesperline,
u_offset, v_offset);
break;
case V4L2_PIX_FMT_UYVY:
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_RGB565:
offset = image->rect.left * 2 +
image->rect.top * pix->bytesperline;
break;
case V4L2_PIX_FMT_RGB32:
case V4L2_PIX_FMT_BGR32:
offset = image->rect.left * 4 +
image->rect.top * pix->bytesperline;
break;
case V4L2_PIX_FMT_RGB24:
case V4L2_PIX_FMT_BGR24:
offset = image->rect.left * 3 +
image->rect.top * pix->bytesperline;
break;
default:
return -EINVAL;
}
ipu_cpmem_set_buffer(ch, 0, image->phys0 + offset);
ipu_cpmem_set_buffer(ch, 1, image->phys1 + offset);
return 0;
}
void ipu_cpmem_dump(struct ipuv3_channel *ch)
{
struct ipu_ch_param __iomem *p = ipu_get_cpmem(ch);
struct ipu_soc *ipu = ch->ipu;
int chno = ch->num;
dev_dbg(ipu->dev, "ch %d word 0 - %08X %08X %08X %08X %08X\n", chno,
readl(&p->word[0].data[0]),
readl(&p->word[0].data[1]),
readl(&p->word[0].data[2]),
readl(&p->word[0].data[3]),
readl(&p->word[0].data[4]));
dev_dbg(ipu->dev, "ch %d word 1 - %08X %08X %08X %08X %08X\n", chno,
readl(&p->word[1].data[0]),
readl(&p->word[1].data[1]),
readl(&p->word[1].data[2]),
readl(&p->word[1].data[3]),
readl(&p->word[1].data[4]));
dev_dbg(ipu->dev, "PFS 0x%x, ",
ipu_ch_param_read_field(ch, IPU_FIELD_PFS));
dev_dbg(ipu->dev, "BPP 0x%x, ",
ipu_ch_param_read_field(ch, IPU_FIELD_BPP));
dev_dbg(ipu->dev, "NPB 0x%x\n",
ipu_ch_param_read_field(ch, IPU_FIELD_NPB));
dev_dbg(ipu->dev, "FW %d, ",
ipu_ch_param_read_field(ch, IPU_FIELD_FW));
dev_dbg(ipu->dev, "FH %d, ",
ipu_ch_param_read_field(ch, IPU_FIELD_FH));
dev_dbg(ipu->dev, "EBA0 0x%x\n",
ipu_ch_param_read_field(ch, IPU_FIELD_EBA0) << 3);
dev_dbg(ipu->dev, "EBA1 0x%x\n",
ipu_ch_param_read_field(ch, IPU_FIELD_EBA1) << 3);
dev_dbg(ipu->dev, "Stride %d\n",
ipu_ch_param_read_field(ch, IPU_FIELD_SL));
dev_dbg(ipu->dev, "scan_order %d\n",
ipu_ch_param_read_field(ch, IPU_FIELD_SO));
dev_dbg(ipu->dev, "uv_stride %d\n",
ipu_ch_param_read_field(ch, IPU_FIELD_SLUV));
dev_dbg(ipu->dev, "u_offset 0x%x\n",
ipu_ch_param_read_field(ch, IPU_FIELD_UBO) << 3);
dev_dbg(ipu->dev, "v_offset 0x%x\n",
ipu_ch_param_read_field(ch, IPU_FIELD_VBO) << 3);
dev_dbg(ipu->dev, "Width0 %d+1, ",
ipu_ch_param_read_field(ch, IPU_FIELD_WID0));
dev_dbg(ipu->dev, "Width1 %d+1, ",
ipu_ch_param_read_field(ch, IPU_FIELD_WID1));
dev_dbg(ipu->dev, "Width2 %d+1, ",
ipu_ch_param_read_field(ch, IPU_FIELD_WID2));
dev_dbg(ipu->dev, "Width3 %d+1, ",
ipu_ch_param_read_field(ch, IPU_FIELD_WID3));
dev_dbg(ipu->dev, "Offset0 %d, ",
ipu_ch_param_read_field(ch, IPU_FIELD_OFS0));
dev_dbg(ipu->dev, "Offset1 %d, ",
ipu_ch_param_read_field(ch, IPU_FIELD_OFS1));
dev_dbg(ipu->dev, "Offset2 %d, ",
ipu_ch_param_read_field(ch, IPU_FIELD_OFS2));
dev_dbg(ipu->dev, "Offset3 %d\n",
ipu_ch_param_read_field(ch, IPU_FIELD_OFS3));
}
int ipu_cpmem_init(struct ipu_soc *ipu, struct device *dev, unsigned long base)
{
struct ipu_cpmem *cpmem;
cpmem = devm_kzalloc(dev, sizeof(*cpmem), GFP_KERNEL);
if (!cpmem)
return -ENOMEM;
ipu->cpmem_priv = cpmem;
spin_lock_init(&cpmem->lock);
cpmem->base = devm_ioremap(dev, base, SZ_128K);
if (!cpmem->base)
return -ENOMEM;
dev_dbg(dev, "CPMEM base: 0x%08lx remapped to %p\n",
base, cpmem->base);
cpmem->ipu = ipu;
return 0;
}
void ipu_cpmem_exit(struct ipu_soc *ipu)
{
}
