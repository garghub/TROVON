static inline u32 ipu_cm_read(struct ipu_soc *ipu, unsigned offset)
{
return readl(ipu->cm_reg + offset);
}
static inline void ipu_cm_write(struct ipu_soc *ipu, u32 value, unsigned offset)
{
writel(value, ipu->cm_reg + offset);
}
static inline u32 ipu_idmac_read(struct ipu_soc *ipu, unsigned offset)
{
return readl(ipu->idmac_reg + offset);
}
static inline void ipu_idmac_write(struct ipu_soc *ipu, u32 value,
unsigned offset)
{
writel(value, ipu->idmac_reg + offset);
}
void ipu_srm_dp_sync_update(struct ipu_soc *ipu)
{
u32 val;
val = ipu_cm_read(ipu, IPU_SRM_PRI2);
val |= 0x8;
ipu_cm_write(ipu, val, IPU_SRM_PRI2);
}
struct ipu_ch_param __iomem *ipu_get_cpmem(struct ipuv3_channel *channel)
{
struct ipu_soc *ipu = channel->ipu;
return ipu->cpmem_base + channel->num;
}
void ipu_cpmem_set_high_priority(struct ipuv3_channel *channel)
{
struct ipu_soc *ipu = channel->ipu;
struct ipu_ch_param __iomem *p = ipu_get_cpmem(channel);
u32 val;
if (ipu->ipu_type == IPUV3EX)
ipu_ch_param_write_field(p, IPU_FIELD_ID, 1);
val = ipu_idmac_read(ipu, IDMAC_CHA_PRI(channel->num));
val |= 1 << (channel->num % 32);
ipu_idmac_write(ipu, val, IDMAC_CHA_PRI(channel->num));
}
void ipu_ch_param_write_field(struct ipu_ch_param __iomem *base, u32 wbs, u32 v)
{
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
u32 ipu_ch_param_read_field(struct ipu_ch_param __iomem *base, u32 wbs)
{
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
int ipu_cpmem_set_format_rgb(struct ipu_ch_param __iomem *p,
const struct ipu_rgb *rgb)
{
int bpp = 0, npb = 0, ro, go, bo, to;
ro = rgb->bits_per_pixel - rgb->red.length - rgb->red.offset;
go = rgb->bits_per_pixel - rgb->green.length - rgb->green.offset;
bo = rgb->bits_per_pixel - rgb->blue.length - rgb->blue.offset;
to = rgb->bits_per_pixel - rgb->transp.length - rgb->transp.offset;
ipu_ch_param_write_field(p, IPU_FIELD_WID0, rgb->red.length - 1);
ipu_ch_param_write_field(p, IPU_FIELD_OFS0, ro);
ipu_ch_param_write_field(p, IPU_FIELD_WID1, rgb->green.length - 1);
ipu_ch_param_write_field(p, IPU_FIELD_OFS1, go);
ipu_ch_param_write_field(p, IPU_FIELD_WID2, rgb->blue.length - 1);
ipu_ch_param_write_field(p, IPU_FIELD_OFS2, bo);
if (rgb->transp.length) {
ipu_ch_param_write_field(p, IPU_FIELD_WID3,
rgb->transp.length - 1);
ipu_ch_param_write_field(p, IPU_FIELD_OFS3, to);
} else {
ipu_ch_param_write_field(p, IPU_FIELD_WID3, 7);
ipu_ch_param_write_field(p, IPU_FIELD_OFS3,
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
ipu_ch_param_write_field(p, IPU_FIELD_BPP, bpp);
ipu_ch_param_write_field(p, IPU_FIELD_NPB, npb);
ipu_ch_param_write_field(p, IPU_FIELD_PFS, 7);
return 0;
}
int ipu_cpmem_set_format_passthrough(struct ipu_ch_param __iomem *p,
int width)
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
ipu_ch_param_write_field(p, IPU_FIELD_BPP, bpp);
ipu_ch_param_write_field(p, IPU_FIELD_NPB, npb);
ipu_ch_param_write_field(p, IPU_FIELD_PFS, 6);
return 0;
}
void ipu_cpmem_set_yuv_interleaved(struct ipu_ch_param __iomem *p,
u32 pixel_format)
{
switch (pixel_format) {
case V4L2_PIX_FMT_UYVY:
ipu_ch_param_write_field(p, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(p, IPU_FIELD_PFS, 0xA);
ipu_ch_param_write_field(p, IPU_FIELD_NPB, 31);
break;
case V4L2_PIX_FMT_YUYV:
ipu_ch_param_write_field(p, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(p, IPU_FIELD_PFS, 0x8);
ipu_ch_param_write_field(p, IPU_FIELD_NPB, 31);
break;
}
}
void ipu_cpmem_set_yuv_planar_full(struct ipu_ch_param __iomem *p,
u32 pixel_format, int stride, int u_offset, int v_offset)
{
switch (pixel_format) {
case V4L2_PIX_FMT_YUV420:
ipu_ch_param_write_field(p, IPU_FIELD_SLUV, (stride / 2) - 1);
ipu_ch_param_write_field(p, IPU_FIELD_UBO, u_offset / 8);
ipu_ch_param_write_field(p, IPU_FIELD_VBO, v_offset / 8);
break;
case V4L2_PIX_FMT_YVU420:
ipu_ch_param_write_field(p, IPU_FIELD_SLUV, (stride / 2) - 1);
ipu_ch_param_write_field(p, IPU_FIELD_UBO, v_offset / 8);
ipu_ch_param_write_field(p, IPU_FIELD_VBO, u_offset / 8);
break;
}
}
void ipu_cpmem_set_yuv_planar(struct ipu_ch_param __iomem *p, u32 pixel_format,
int stride, int height)
{
int u_offset, v_offset;
int uv_stride = 0;
switch (pixel_format) {
case V4L2_PIX_FMT_YUV420:
case V4L2_PIX_FMT_YVU420:
uv_stride = stride / 2;
u_offset = stride * height;
v_offset = u_offset + (uv_stride * height / 2);
ipu_cpmem_set_yuv_planar_full(p, pixel_format, stride,
u_offset, v_offset);
break;
}
}
int ipu_cpmem_set_fmt(struct ipu_ch_param __iomem *cpmem, u32 drm_fourcc)
{
switch (drm_fourcc) {
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
ipu_ch_param_write_field(cpmem, IPU_FIELD_PFS, 2);
ipu_ch_param_write_field(cpmem, IPU_FIELD_NPB, 63);
break;
case DRM_FORMAT_UYVY:
ipu_ch_param_write_field(cpmem, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(cpmem, IPU_FIELD_PFS, 0xA);
ipu_ch_param_write_field(cpmem, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_YUYV:
ipu_ch_param_write_field(cpmem, IPU_FIELD_BPP, 3);
ipu_ch_param_write_field(cpmem, IPU_FIELD_PFS, 0x8);
ipu_ch_param_write_field(cpmem, IPU_FIELD_NPB, 31);
break;
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_XBGR8888:
ipu_cpmem_set_format_rgb(cpmem, &def_bgr_32);
break;
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_XRGB8888:
ipu_cpmem_set_format_rgb(cpmem, &def_rgb_32);
break;
case DRM_FORMAT_BGR888:
ipu_cpmem_set_format_rgb(cpmem, &def_bgr_24);
break;
case DRM_FORMAT_RGB888:
ipu_cpmem_set_format_rgb(cpmem, &def_rgb_24);
break;
case DRM_FORMAT_RGB565:
ipu_cpmem_set_format_rgb(cpmem, &def_rgb_16);
break;
case DRM_FORMAT_BGR565:
ipu_cpmem_set_format_rgb(cpmem, &def_bgr_16);
break;
default:
return -EINVAL;
}
return 0;
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
case V4L2_PIX_FMT_YVU420:
return DRM_FORMAT_YVU420;
}
return -EINVAL;
}
enum ipu_color_space ipu_drm_fourcc_to_colorspace(u32 drm_fourcc)
{
switch (drm_fourcc) {
case DRM_FORMAT_RGB565:
case DRM_FORMAT_BGR565:
case DRM_FORMAT_RGB888:
case DRM_FORMAT_BGR888:
case DRM_FORMAT_XRGB8888:
case DRM_FORMAT_XBGR8888:
case DRM_FORMAT_RGBX8888:
case DRM_FORMAT_BGRX8888:
case DRM_FORMAT_ARGB8888:
case DRM_FORMAT_ABGR8888:
case DRM_FORMAT_RGBA8888:
case DRM_FORMAT_BGRA8888:
return IPUV3_COLORSPACE_RGB;
case DRM_FORMAT_YUYV:
case DRM_FORMAT_UYVY:
case DRM_FORMAT_YUV420:
case DRM_FORMAT_YVU420:
return IPUV3_COLORSPACE_YUV;
default:
return IPUV3_COLORSPACE_UNKNOWN;
}
}
int ipu_cpmem_set_image(struct ipu_ch_param __iomem *cpmem,
struct ipu_image *image)
{
struct v4l2_pix_format *pix = &image->pix;
int y_offset, u_offset, v_offset;
pr_debug("%s: resolution: %dx%d stride: %d\n",
__func__, pix->width, pix->height,
pix->bytesperline);
ipu_cpmem_set_resolution(cpmem, image->rect.width,
image->rect.height);
ipu_cpmem_set_stride(cpmem, pix->bytesperline);
ipu_cpmem_set_fmt(cpmem, v4l2_pix_fmt_to_drm_fourcc(pix->pixelformat));
switch (pix->pixelformat) {
case V4L2_PIX_FMT_YUV420:
case V4L2_PIX_FMT_YVU420:
y_offset = Y_OFFSET(pix, image->rect.left, image->rect.top);
u_offset = U_OFFSET(pix, image->rect.left,
image->rect.top) - y_offset;
v_offset = V_OFFSET(pix, image->rect.left,
image->rect.top) - y_offset;
ipu_cpmem_set_yuv_planar_full(cpmem, pix->pixelformat,
pix->bytesperline, u_offset, v_offset);
ipu_cpmem_set_buffer(cpmem, 0, image->phys + y_offset);
break;
case V4L2_PIX_FMT_UYVY:
case V4L2_PIX_FMT_YUYV:
ipu_cpmem_set_buffer(cpmem, 0, image->phys +
image->rect.left * 2 +
image->rect.top * image->pix.bytesperline);
break;
case V4L2_PIX_FMT_RGB32:
case V4L2_PIX_FMT_BGR32:
ipu_cpmem_set_buffer(cpmem, 0, image->phys +
image->rect.left * 4 +
image->rect.top * image->pix.bytesperline);
break;
case V4L2_PIX_FMT_RGB565:
ipu_cpmem_set_buffer(cpmem, 0, image->phys +
image->rect.left * 2 +
image->rect.top * image->pix.bytesperline);
break;
case V4L2_PIX_FMT_RGB24:
case V4L2_PIX_FMT_BGR24:
ipu_cpmem_set_buffer(cpmem, 0, image->phys +
image->rect.left * 3 +
image->rect.top * image->pix.bytesperline);
break;
default:
return -EINVAL;
}
return 0;
}
enum ipu_color_space ipu_pixelformat_to_colorspace(u32 pixelformat)
{
switch (pixelformat) {
case V4L2_PIX_FMT_YUV420:
case V4L2_PIX_FMT_YVU420:
case V4L2_PIX_FMT_UYVY:
case V4L2_PIX_FMT_YUYV:
return IPUV3_COLORSPACE_YUV;
case V4L2_PIX_FMT_RGB32:
case V4L2_PIX_FMT_BGR32:
case V4L2_PIX_FMT_RGB24:
case V4L2_PIX_FMT_BGR24:
case V4L2_PIX_FMT_RGB565:
return IPUV3_COLORSPACE_RGB;
default:
return IPUV3_COLORSPACE_UNKNOWN;
}
}
struct ipuv3_channel *ipu_idmac_get(struct ipu_soc *ipu, unsigned num)
{
struct ipuv3_channel *channel;
dev_dbg(ipu->dev, "%s %d\n", __func__, num);
if (num > 63)
return ERR_PTR(-ENODEV);
mutex_lock(&ipu->channel_lock);
channel = &ipu->channel[num];
if (channel->busy) {
channel = ERR_PTR(-EBUSY);
goto out;
}
channel->busy = true;
channel->num = num;
out:
mutex_unlock(&ipu->channel_lock);
return channel;
}
void ipu_idmac_put(struct ipuv3_channel *channel)
{
struct ipu_soc *ipu = channel->ipu;
dev_dbg(ipu->dev, "%s %d\n", __func__, channel->num);
mutex_lock(&ipu->channel_lock);
channel->busy = false;
mutex_unlock(&ipu->channel_lock);
}
void ipu_idmac_set_double_buffer(struct ipuv3_channel *channel,
bool doublebuffer)
{
struct ipu_soc *ipu = channel->ipu;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&ipu->lock, flags);
reg = ipu_cm_read(ipu, IPU_CHA_DB_MODE_SEL(channel->num));
if (doublebuffer)
reg |= idma_mask(channel->num);
else
reg &= ~idma_mask(channel->num);
ipu_cm_write(ipu, reg, IPU_CHA_DB_MODE_SEL(channel->num));
spin_unlock_irqrestore(&ipu->lock, flags);
}
int ipu_module_enable(struct ipu_soc *ipu, u32 mask)
{
unsigned long lock_flags;
u32 val;
spin_lock_irqsave(&ipu->lock, lock_flags);
val = ipu_cm_read(ipu, IPU_DISP_GEN);
if (mask & IPU_CONF_DI0_EN)
val |= IPU_DI0_COUNTER_RELEASE;
if (mask & IPU_CONF_DI1_EN)
val |= IPU_DI1_COUNTER_RELEASE;
ipu_cm_write(ipu, val, IPU_DISP_GEN);
val = ipu_cm_read(ipu, IPU_CONF);
val |= mask;
ipu_cm_write(ipu, val, IPU_CONF);
spin_unlock_irqrestore(&ipu->lock, lock_flags);
return 0;
}
int ipu_module_disable(struct ipu_soc *ipu, u32 mask)
{
unsigned long lock_flags;
u32 val;
spin_lock_irqsave(&ipu->lock, lock_flags);
val = ipu_cm_read(ipu, IPU_CONF);
val &= ~mask;
ipu_cm_write(ipu, val, IPU_CONF);
val = ipu_cm_read(ipu, IPU_DISP_GEN);
if (mask & IPU_CONF_DI0_EN)
val &= ~IPU_DI0_COUNTER_RELEASE;
if (mask & IPU_CONF_DI1_EN)
val &= ~IPU_DI1_COUNTER_RELEASE;
ipu_cm_write(ipu, val, IPU_DISP_GEN);
spin_unlock_irqrestore(&ipu->lock, lock_flags);
return 0;
}
int ipu_csi_enable(struct ipu_soc *ipu, int csi)
{
return ipu_module_enable(ipu, csi ? IPU_CONF_CSI1_EN : IPU_CONF_CSI0_EN);
}
int ipu_csi_disable(struct ipu_soc *ipu, int csi)
{
return ipu_module_disable(ipu, csi ? IPU_CONF_CSI1_EN : IPU_CONF_CSI0_EN);
}
int ipu_smfc_enable(struct ipu_soc *ipu)
{
return ipu_module_enable(ipu, IPU_CONF_SMFC_EN);
}
int ipu_smfc_disable(struct ipu_soc *ipu)
{
return ipu_module_disable(ipu, IPU_CONF_SMFC_EN);
}
int ipu_idmac_get_current_buffer(struct ipuv3_channel *channel)
{
struct ipu_soc *ipu = channel->ipu;
unsigned int chno = channel->num;
return (ipu_cm_read(ipu, IPU_CHA_CUR_BUF(chno)) & idma_mask(chno)) ? 1 : 0;
}
void ipu_idmac_select_buffer(struct ipuv3_channel *channel, u32 buf_num)
{
struct ipu_soc *ipu = channel->ipu;
unsigned int chno = channel->num;
unsigned long flags;
spin_lock_irqsave(&ipu->lock, flags);
if (buf_num == 0)
ipu_cm_write(ipu, idma_mask(chno), IPU_CHA_BUF0_RDY(chno));
else
ipu_cm_write(ipu, idma_mask(chno), IPU_CHA_BUF1_RDY(chno));
spin_unlock_irqrestore(&ipu->lock, flags);
}
int ipu_idmac_enable_channel(struct ipuv3_channel *channel)
{
struct ipu_soc *ipu = channel->ipu;
u32 val;
unsigned long flags;
spin_lock_irqsave(&ipu->lock, flags);
val = ipu_idmac_read(ipu, IDMAC_CHA_EN(channel->num));
val |= idma_mask(channel->num);
ipu_idmac_write(ipu, val, IDMAC_CHA_EN(channel->num));
spin_unlock_irqrestore(&ipu->lock, flags);
return 0;
}
bool ipu_idmac_channel_busy(struct ipu_soc *ipu, unsigned int chno)
{
return (ipu_idmac_read(ipu, IDMAC_CHA_BUSY(chno)) & idma_mask(chno));
}
int ipu_idmac_wait_busy(struct ipuv3_channel *channel, int ms)
{
struct ipu_soc *ipu = channel->ipu;
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(ms);
while (ipu_idmac_read(ipu, IDMAC_CHA_BUSY(channel->num)) &
idma_mask(channel->num)) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cpu_relax();
}
return 0;
}
int ipu_wait_interrupt(struct ipu_soc *ipu, int irq, int ms)
{
unsigned long timeout;
timeout = jiffies + msecs_to_jiffies(ms);
ipu_cm_write(ipu, BIT(irq % 32), IPU_INT_STAT(irq / 32));
while (!(ipu_cm_read(ipu, IPU_INT_STAT(irq / 32) & BIT(irq % 32)))) {
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
cpu_relax();
}
return 0;
}
int ipu_idmac_disable_channel(struct ipuv3_channel *channel)
{
struct ipu_soc *ipu = channel->ipu;
u32 val;
unsigned long flags;
spin_lock_irqsave(&ipu->lock, flags);
val = ipu_idmac_read(ipu, IDMAC_CHA_EN(channel->num));
val &= ~idma_mask(channel->num);
ipu_idmac_write(ipu, val, IDMAC_CHA_EN(channel->num));
ipu_cm_write(ipu, 0xf0000000, IPU_GPR);
if (ipu_cm_read(ipu, IPU_CHA_BUF0_RDY(channel->num)) &
idma_mask(channel->num)) {
ipu_cm_write(ipu, idma_mask(channel->num),
IPU_CHA_BUF0_RDY(channel->num));
}
if (ipu_cm_read(ipu, IPU_CHA_BUF1_RDY(channel->num)) &
idma_mask(channel->num)) {
ipu_cm_write(ipu, idma_mask(channel->num),
IPU_CHA_BUF1_RDY(channel->num));
}
ipu_cm_write(ipu, 0x0, IPU_GPR);
val = ipu_cm_read(ipu, IPU_CHA_DB_MODE_SEL(channel->num));
val &= ~idma_mask(channel->num);
ipu_cm_write(ipu, val, IPU_CHA_DB_MODE_SEL(channel->num));
spin_unlock_irqrestore(&ipu->lock, flags);
return 0;
}
static int ipu_memory_reset(struct ipu_soc *ipu)
{
unsigned long timeout;
ipu_cm_write(ipu, 0x807FFFFF, IPU_MEM_RST);
timeout = jiffies + msecs_to_jiffies(1000);
while (ipu_cm_read(ipu, IPU_MEM_RST) & 0x80000000) {
if (time_after(jiffies, timeout))
return -ETIME;
cpu_relax();
}
return 0;
}
static int ipu_submodules_init(struct ipu_soc *ipu,
struct platform_device *pdev, unsigned long ipu_base,
struct clk *ipu_clk)
{
char *unit;
int ret;
struct device *dev = &pdev->dev;
const struct ipu_devtype *devtype = ipu->devtype;
ret = ipu_di_init(ipu, dev, 0, ipu_base + devtype->disp0_ofs,
IPU_CONF_DI0_EN, ipu_clk);
if (ret) {
unit = "di0";
goto err_di_0;
}
ret = ipu_di_init(ipu, dev, 1, ipu_base + devtype->disp1_ofs,
IPU_CONF_DI1_EN, ipu_clk);
if (ret) {
unit = "di1";
goto err_di_1;
}
ret = ipu_dc_init(ipu, dev, ipu_base + devtype->cm_ofs +
IPU_CM_DC_REG_OFS, ipu_base + devtype->dc_tmpl_ofs);
if (ret) {
unit = "dc_template";
goto err_dc;
}
ret = ipu_dmfc_init(ipu, dev, ipu_base +
devtype->cm_ofs + IPU_CM_DMFC_REG_OFS, ipu_clk);
if (ret) {
unit = "dmfc";
goto err_dmfc;
}
ret = ipu_dp_init(ipu, dev, ipu_base + devtype->srm_ofs);
if (ret) {
unit = "dp";
goto err_dp;
}
ret = ipu_smfc_init(ipu, dev, ipu_base +
devtype->cm_ofs + IPU_CM_SMFC_REG_OFS);
if (ret) {
unit = "smfc";
goto err_smfc;
}
return 0;
err_smfc:
ipu_dp_exit(ipu);
err_dp:
ipu_dmfc_exit(ipu);
err_dmfc:
ipu_dc_exit(ipu);
err_dc:
ipu_di_exit(ipu, 1);
err_di_1:
ipu_di_exit(ipu, 0);
err_di_0:
dev_err(&pdev->dev, "init %s failed with %d\n", unit, ret);
return ret;
}
static void ipu_irq_handle(struct ipu_soc *ipu, const int *regs, int num_regs)
{
unsigned long status;
int i, bit, irq;
for (i = 0; i < num_regs; i++) {
status = ipu_cm_read(ipu, IPU_INT_STAT(regs[i]));
status &= ipu_cm_read(ipu, IPU_INT_CTRL(regs[i]));
for_each_set_bit(bit, &status, 32) {
irq = irq_linear_revmap(ipu->domain,
regs[i] * 32 + bit);
if (irq)
generic_handle_irq(irq);
}
}
}
static void ipu_irq_handler(unsigned int irq, struct irq_desc *desc)
{
struct ipu_soc *ipu = irq_desc_get_handler_data(desc);
const int int_reg[] = { 0, 1, 2, 3, 10, 11, 12, 13, 14};
struct irq_chip *chip = irq_get_chip(irq);
chained_irq_enter(chip, desc);
ipu_irq_handle(ipu, int_reg, ARRAY_SIZE(int_reg));
chained_irq_exit(chip, desc);
}
static void ipu_err_irq_handler(unsigned int irq, struct irq_desc *desc)
{
struct ipu_soc *ipu = irq_desc_get_handler_data(desc);
const int int_reg[] = { 4, 5, 8, 9};
struct irq_chip *chip = irq_get_chip(irq);
chained_irq_enter(chip, desc);
ipu_irq_handle(ipu, int_reg, ARRAY_SIZE(int_reg));
chained_irq_exit(chip, desc);
}
int ipu_map_irq(struct ipu_soc *ipu, int irq)
{
int virq;
virq = irq_linear_revmap(ipu->domain, irq);
if (!virq)
virq = irq_create_mapping(ipu->domain, irq);
return virq;
}
int ipu_idmac_channel_irq(struct ipu_soc *ipu, struct ipuv3_channel *channel,
enum ipu_channel_irq irq_type)
{
return ipu_map_irq(ipu, irq_type + channel->num);
}
static void ipu_submodules_exit(struct ipu_soc *ipu)
{
ipu_smfc_exit(ipu);
ipu_dp_exit(ipu);
ipu_dmfc_exit(ipu);
ipu_dc_exit(ipu);
ipu_di_exit(ipu, 1);
ipu_di_exit(ipu, 0);
}
static int platform_remove_devices_fn(struct device *dev, void *unused)
{
struct platform_device *pdev = to_platform_device(dev);
platform_device_unregister(pdev);
return 0;
}
static void platform_device_unregister_children(struct platform_device *pdev)
{
device_for_each_child(&pdev->dev, NULL, platform_remove_devices_fn);
}
static int ipu_add_client_devices(struct ipu_soc *ipu, unsigned long ipu_base)
{
struct device *dev = ipu->dev;
unsigned i;
int id, ret;
mutex_lock(&ipu_client_id_mutex);
id = ipu_client_id;
ipu_client_id += ARRAY_SIZE(client_reg);
mutex_unlock(&ipu_client_id_mutex);
for (i = 0; i < ARRAY_SIZE(client_reg); i++) {
const struct ipu_platform_reg *reg = &client_reg[i];
struct platform_device *pdev;
struct resource res;
if (reg->reg_offset) {
memset(&res, 0, sizeof(res));
res.flags = IORESOURCE_MEM;
res.start = ipu_base + ipu->devtype->cm_ofs + reg->reg_offset;
res.end = res.start + PAGE_SIZE - 1;
pdev = platform_device_register_resndata(dev, reg->name,
id++, &res, 1, &reg->pdata, sizeof(reg->pdata));
} else {
pdev = platform_device_register_data(dev, reg->name,
id++, &reg->pdata, sizeof(reg->pdata));
}
if (IS_ERR(pdev))
goto err_register;
}
return 0;
err_register:
platform_device_unregister_children(to_platform_device(dev));
return ret;
}
static int ipu_irq_init(struct ipu_soc *ipu)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
unsigned long unused[IPU_NUM_IRQS / 32] = {
0x400100d0, 0xffe000fd,
0x400100d0, 0xffe000fd,
0x400100d0, 0xffe000fd,
0x4077ffff, 0xffe7e1fd,
0x23fffffe, 0x8880fff0,
0xf98fe7d0, 0xfff81fff,
0x400100d0, 0xffe000fd,
0x00000000,
};
int ret, i;
ipu->domain = irq_domain_add_linear(ipu->dev->of_node, IPU_NUM_IRQS,
&irq_generic_chip_ops, ipu);
if (!ipu->domain) {
dev_err(ipu->dev, "failed to add irq domain\n");
return -ENODEV;
}
ret = irq_alloc_domain_generic_chips(ipu->domain, 32, 1, "IPU",
handle_level_irq, 0,
IRQF_VALID, 0);
if (ret < 0) {
dev_err(ipu->dev, "failed to alloc generic irq chips\n");
irq_domain_remove(ipu->domain);
return ret;
}
for (i = 0; i < IPU_NUM_IRQS; i += 32) {
gc = irq_get_domain_generic_chip(ipu->domain, i);
gc->reg_base = ipu->cm_reg;
gc->unused = unused[i / 32];
ct = gc->chip_types;
ct->chip.irq_ack = irq_gc_ack_set_bit;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->regs.ack = IPU_INT_STAT(i / 32);
ct->regs.mask = IPU_INT_CTRL(i / 32);
}
irq_set_chained_handler(ipu->irq_sync, ipu_irq_handler);
irq_set_handler_data(ipu->irq_sync, ipu);
irq_set_chained_handler(ipu->irq_err, ipu_err_irq_handler);
irq_set_handler_data(ipu->irq_err, ipu);
return 0;
}
static void ipu_irq_exit(struct ipu_soc *ipu)
{
int i, irq;
irq_set_chained_handler(ipu->irq_err, NULL);
irq_set_handler_data(ipu->irq_err, NULL);
irq_set_chained_handler(ipu->irq_sync, NULL);
irq_set_handler_data(ipu->irq_sync, NULL);
for (i = 0; i < IPU_NUM_IRQS; i++) {
irq = irq_linear_revmap(ipu->domain, i);
if (irq)
irq_dispose_mapping(irq);
}
irq_domain_remove(ipu->domain);
}
static int ipu_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(imx_ipu_dt_ids, &pdev->dev);
struct ipu_soc *ipu;
struct resource *res;
unsigned long ipu_base;
int i, ret, irq_sync, irq_err;
const struct ipu_devtype *devtype;
devtype = of_id->data;
irq_sync = platform_get_irq(pdev, 0);
irq_err = platform_get_irq(pdev, 1);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev_dbg(&pdev->dev, "irq_sync: %d irq_err: %d\n",
irq_sync, irq_err);
if (!res || irq_sync < 0 || irq_err < 0)
return -ENODEV;
ipu_base = res->start;
ipu = devm_kzalloc(&pdev->dev, sizeof(*ipu), GFP_KERNEL);
if (!ipu)
return -ENODEV;
for (i = 0; i < 64; i++)
ipu->channel[i].ipu = ipu;
ipu->devtype = devtype;
ipu->ipu_type = devtype->type;
spin_lock_init(&ipu->lock);
mutex_init(&ipu->channel_lock);
dev_dbg(&pdev->dev, "cm_reg: 0x%08lx\n",
ipu_base + devtype->cm_ofs);
dev_dbg(&pdev->dev, "idmac: 0x%08lx\n",
ipu_base + devtype->cm_ofs + IPU_CM_IDMAC_REG_OFS);
dev_dbg(&pdev->dev, "cpmem: 0x%08lx\n",
ipu_base + devtype->cpmem_ofs);
dev_dbg(&pdev->dev, "disp0: 0x%08lx\n",
ipu_base + devtype->disp0_ofs);
dev_dbg(&pdev->dev, "disp1: 0x%08lx\n",
ipu_base + devtype->disp1_ofs);
dev_dbg(&pdev->dev, "srm: 0x%08lx\n",
ipu_base + devtype->srm_ofs);
dev_dbg(&pdev->dev, "tpm: 0x%08lx\n",
ipu_base + devtype->tpm_ofs);
dev_dbg(&pdev->dev, "dc: 0x%08lx\n",
ipu_base + devtype->cm_ofs + IPU_CM_DC_REG_OFS);
dev_dbg(&pdev->dev, "ic: 0x%08lx\n",
ipu_base + devtype->cm_ofs + IPU_CM_IC_REG_OFS);
dev_dbg(&pdev->dev, "dmfc: 0x%08lx\n",
ipu_base + devtype->cm_ofs + IPU_CM_DMFC_REG_OFS);
dev_dbg(&pdev->dev, "vdi: 0x%08lx\n",
ipu_base + devtype->vdi_ofs);
ipu->cm_reg = devm_ioremap(&pdev->dev,
ipu_base + devtype->cm_ofs, PAGE_SIZE);
ipu->idmac_reg = devm_ioremap(&pdev->dev,
ipu_base + devtype->cm_ofs + IPU_CM_IDMAC_REG_OFS,
PAGE_SIZE);
ipu->cpmem_base = devm_ioremap(&pdev->dev,
ipu_base + devtype->cpmem_ofs, PAGE_SIZE);
if (!ipu->cm_reg || !ipu->idmac_reg || !ipu->cpmem_base)
return -ENOMEM;
ipu->clk = devm_clk_get(&pdev->dev, "bus");
if (IS_ERR(ipu->clk)) {
ret = PTR_ERR(ipu->clk);
dev_err(&pdev->dev, "clk_get failed with %d", ret);
return ret;
}
platform_set_drvdata(pdev, ipu);
ret = clk_prepare_enable(ipu->clk);
if (ret) {
dev_err(&pdev->dev, "clk_prepare_enable failed: %d\n", ret);
return ret;
}
ipu->dev = &pdev->dev;
ipu->irq_sync = irq_sync;
ipu->irq_err = irq_err;
ret = ipu_irq_init(ipu);
if (ret)
goto out_failed_irq;
ret = device_reset(&pdev->dev);
if (ret) {
dev_err(&pdev->dev, "failed to reset: %d\n", ret);
goto out_failed_reset;
}
ret = ipu_memory_reset(ipu);
if (ret)
goto out_failed_reset;
ipu_cm_write(ipu, 0x00400000L | (IPU_MCU_T_DEFAULT << 18),
IPU_DISP_GEN);
ret = ipu_submodules_init(ipu, pdev, ipu_base, ipu->clk);
if (ret)
goto failed_submodules_init;
ret = ipu_add_client_devices(ipu, ipu_base);
if (ret) {
dev_err(&pdev->dev, "adding client devices failed with %d\n",
ret);
goto failed_add_clients;
}
dev_info(&pdev->dev, "%s probed\n", devtype->name);
return 0;
failed_add_clients:
ipu_submodules_exit(ipu);
failed_submodules_init:
out_failed_reset:
ipu_irq_exit(ipu);
out_failed_irq:
clk_disable_unprepare(ipu->clk);
return ret;
}
static int ipu_remove(struct platform_device *pdev)
{
struct ipu_soc *ipu = platform_get_drvdata(pdev);
platform_device_unregister_children(pdev);
ipu_submodules_exit(ipu);
ipu_irq_exit(ipu);
clk_disable_unprepare(ipu->clk);
return 0;
}
