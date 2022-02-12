static enum fsl_diu_monitor_port fsl_diu_name_to_port(const char *s)
{
enum fsl_diu_monitor_port port = FSL_DIU_PORT_DVI;
unsigned long val;
if (s) {
if (!strict_strtoul(s, 10, &val) && (val <= 2))
port = (enum fsl_diu_monitor_port) val;
else if (strncmp(s, "lvds", 4) == 0)
port = FSL_DIU_PORT_LVDS;
else if (strncmp(s, "dlvds", 5) == 0)
port = FSL_DIU_PORT_DLVDS;
}
return diu_ops.valid_monitor_port(port);
}
void wr_reg_wa(u32 *reg, u32 val)
{
do {
out_be32(reg, val);
} while (in_be32(reg) != val);
}
static void fsl_diu_enable_panel(struct fb_info *info)
{
struct mfb_info *pmfbi, *cmfbi, *mfbi = info->par;
struct diu_ad *ad = mfbi->ad;
struct fsl_diu_data *data = mfbi->parent;
struct diu __iomem *hw = data->diu_reg;
switch (mfbi->index) {
case PLANE0:
wr_reg_wa(&hw->desc[0], ad->paddr);
break;
case PLANE1_AOI0:
cmfbi = &data->mfb[2];
if (hw->desc[1] != ad->paddr) {
if (cmfbi->count > 0)
ad->next_ad =
cpu_to_le32(cmfbi->ad->paddr);
else
ad->next_ad = 0;
wr_reg_wa(&hw->desc[1], ad->paddr);
}
break;
case PLANE2_AOI0:
cmfbi = &data->mfb[4];
if (hw->desc[2] != ad->paddr) {
if (cmfbi->count > 0)
ad->next_ad =
cpu_to_le32(cmfbi->ad->paddr);
else
ad->next_ad = 0;
wr_reg_wa(&hw->desc[2], ad->paddr);
}
break;
case PLANE1_AOI1:
pmfbi = &data->mfb[1];
ad->next_ad = 0;
if (hw->desc[1] == data->dummy_ad.paddr)
wr_reg_wa(&hw->desc[1], ad->paddr);
else
pmfbi->ad->next_ad = cpu_to_le32(ad->paddr);
break;
case PLANE2_AOI1:
pmfbi = &data->mfb[3];
ad->next_ad = 0;
if (hw->desc[2] == data->dummy_ad.paddr)
wr_reg_wa(&hw->desc[2], ad->paddr);
else
pmfbi->ad->next_ad = cpu_to_le32(ad->paddr);
break;
}
}
static void fsl_diu_disable_panel(struct fb_info *info)
{
struct mfb_info *pmfbi, *cmfbi, *mfbi = info->par;
struct diu_ad *ad = mfbi->ad;
struct fsl_diu_data *data = mfbi->parent;
struct diu __iomem *hw = data->diu_reg;
switch (mfbi->index) {
case PLANE0:
wr_reg_wa(&hw->desc[0], 0);
break;
case PLANE1_AOI0:
cmfbi = &data->mfb[2];
if (cmfbi->count > 0)
wr_reg_wa(&hw->desc[1], cmfbi->ad->paddr);
else
wr_reg_wa(&hw->desc[1], data->dummy_ad.paddr);
break;
case PLANE2_AOI0:
cmfbi = &data->mfb[4];
if (cmfbi->count > 0)
wr_reg_wa(&hw->desc[2], cmfbi->ad->paddr);
else
wr_reg_wa(&hw->desc[2], data->dummy_ad.paddr);
break;
case PLANE1_AOI1:
pmfbi = &data->mfb[1];
if (hw->desc[1] != ad->paddr) {
if (pmfbi->count > 0)
pmfbi->ad->next_ad = 0;
} else
wr_reg_wa(&hw->desc[1], data->dummy_ad.paddr);
break;
case PLANE2_AOI1:
pmfbi = &data->mfb[3];
if (hw->desc[2] != ad->paddr) {
if (pmfbi->count > 0)
pmfbi->ad->next_ad = 0;
} else
wr_reg_wa(&hw->desc[2], data->dummy_ad.paddr);
break;
}
}
static void enable_lcdc(struct fb_info *info)
{
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *data = mfbi->parent;
struct diu __iomem *hw = data->diu_reg;
out_be32(&hw->diu_mode, MFB_MODE1);
}
static void disable_lcdc(struct fb_info *info)
{
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *data = mfbi->parent;
struct diu __iomem *hw = data->diu_reg;
out_be32(&hw->diu_mode, 0);
}
static void adjust_aoi_size_position(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct mfb_info *lower_aoi_mfbi, *upper_aoi_mfbi, *mfbi = info->par;
struct fsl_diu_data *data = mfbi->parent;
int available_height, upper_aoi_bottom;
enum mfb_index index = mfbi->index;
int lower_aoi_is_open, upper_aoi_is_open;
__u32 base_plane_width, base_plane_height, upper_aoi_height;
base_plane_width = data->fsl_diu_info[0].var.xres;
base_plane_height = data->fsl_diu_info[0].var.yres;
if (mfbi->x_aoi_d < 0)
mfbi->x_aoi_d = 0;
if (mfbi->y_aoi_d < 0)
mfbi->y_aoi_d = 0;
switch (index) {
case PLANE0:
if (mfbi->x_aoi_d != 0)
mfbi->x_aoi_d = 0;
if (mfbi->y_aoi_d != 0)
mfbi->y_aoi_d = 0;
break;
case PLANE1_AOI0:
case PLANE2_AOI0:
lower_aoi_mfbi = data->fsl_diu_info[index+1].par;
lower_aoi_is_open = lower_aoi_mfbi->count > 0 ? 1 : 0;
if (var->xres > base_plane_width)
var->xres = base_plane_width;
if ((mfbi->x_aoi_d + var->xres) > base_plane_width)
mfbi->x_aoi_d = base_plane_width - var->xres;
if (lower_aoi_is_open)
available_height = lower_aoi_mfbi->y_aoi_d;
else
available_height = base_plane_height;
if (var->yres > available_height)
var->yres = available_height;
if ((mfbi->y_aoi_d + var->yres) > available_height)
mfbi->y_aoi_d = available_height - var->yres;
break;
case PLANE1_AOI1:
case PLANE2_AOI1:
upper_aoi_mfbi = data->fsl_diu_info[index-1].par;
upper_aoi_height = data->fsl_diu_info[index-1].var.yres;
upper_aoi_bottom = upper_aoi_mfbi->y_aoi_d + upper_aoi_height;
upper_aoi_is_open = upper_aoi_mfbi->count > 0 ? 1 : 0;
if (var->xres > base_plane_width)
var->xres = base_plane_width;
if ((mfbi->x_aoi_d + var->xres) > base_plane_width)
mfbi->x_aoi_d = base_plane_width - var->xres;
if (mfbi->y_aoi_d < 0)
mfbi->y_aoi_d = 0;
if (upper_aoi_is_open) {
if (mfbi->y_aoi_d < upper_aoi_bottom)
mfbi->y_aoi_d = upper_aoi_bottom;
available_height = base_plane_height
- upper_aoi_bottom;
} else
available_height = base_plane_height;
if (var->yres > available_height)
var->yres = available_height;
if ((mfbi->y_aoi_d + var->yres) > base_plane_height)
mfbi->y_aoi_d = base_plane_height - var->yres;
break;
}
}
static int fsl_diu_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
if (var->xres_virtual < var->xres)
var->xres_virtual = var->xres;
if (var->yres_virtual < var->yres)
var->yres_virtual = var->yres;
if (var->xoffset < 0)
var->xoffset = 0;
if (var->yoffset < 0)
var->yoffset = 0;
if (var->xoffset + info->var.xres > info->var.xres_virtual)
var->xoffset = info->var.xres_virtual - info->var.xres;
if (var->yoffset + info->var.yres > info->var.yres_virtual)
var->yoffset = info->var.yres_virtual - info->var.yres;
if ((var->bits_per_pixel != 32) && (var->bits_per_pixel != 24) &&
(var->bits_per_pixel != 16))
var->bits_per_pixel = default_bpp;
switch (var->bits_per_pixel) {
case 16:
var->red.length = 5;
var->red.offset = 11;
var->red.msb_right = 0;
var->green.length = 6;
var->green.offset = 5;
var->green.msb_right = 0;
var->blue.length = 5;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.length = 0;
var->transp.offset = 0;
var->transp.msb_right = 0;
break;
case 24:
var->red.length = 8;
var->red.offset = 0;
var->red.msb_right = 0;
var->green.length = 8;
var->green.offset = 8;
var->green.msb_right = 0;
var->blue.length = 8;
var->blue.offset = 16;
var->blue.msb_right = 0;
var->transp.length = 0;
var->transp.offset = 0;
var->transp.msb_right = 0;
break;
case 32:
var->red.length = 8;
var->red.offset = 16;
var->red.msb_right = 0;
var->green.length = 8;
var->green.offset = 8;
var->green.msb_right = 0;
var->blue.length = 8;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.length = 8;
var->transp.offset = 24;
var->transp.msb_right = 0;
break;
}
var->height = -1;
var->width = -1;
var->grayscale = 0;
var->sync |= var->nonstd;
var->nonstd |= var->sync;
adjust_aoi_size_position(var, info);
return 0;
}
static void set_fix(struct fb_info *info)
{
struct fb_fix_screeninfo *fix = &info->fix;
struct fb_var_screeninfo *var = &info->var;
struct mfb_info *mfbi = info->par;
strncpy(fix->id, mfbi->id, sizeof(fix->id));
fix->line_length = var->xres_virtual * var->bits_per_pixel / 8;
fix->type = FB_TYPE_PACKED_PIXELS;
fix->accel = FB_ACCEL_NONE;
fix->visual = FB_VISUAL_TRUECOLOR;
fix->xpanstep = 1;
fix->ypanstep = 1;
}
static void update_lcdc(struct fb_info *info)
{
struct fb_var_screeninfo *var = &info->var;
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *data = mfbi->parent;
struct diu __iomem *hw;
int i, j;
u8 *gamma_table_base;
u32 temp;
hw = data->diu_reg;
if (diu_ops.set_monitor_port)
diu_ops.set_monitor_port(data->monitor_port);
gamma_table_base = data->gamma;
for (i = 0; i <= 2; i++)
for (j = 0; j <= 255; j++)
*gamma_table_base++ = j;
if (diu_ops.set_gamma_table)
diu_ops.set_gamma_table(data->monitor_port, data->gamma);
disable_lcdc(info);
out_be32(&hw->gamma, DMA_ADDR(data, gamma));
out_be32(&hw->cursor, DMA_ADDR(data, cursor));
out_be32(&hw->bgnd, 0x007F7F7F);
out_be32(&hw->disp_size, (var->yres << 16) | var->xres);
temp = var->left_margin << 22 |
var->hsync_len << 11 |
var->right_margin;
out_be32(&hw->hsyn_para, temp);
temp = var->upper_margin << 22 |
var->vsync_len << 11 |
var->lower_margin;
out_be32(&hw->vsyn_para, temp);
diu_ops.set_pixel_clock(var->pixclock);
#ifndef CONFIG_PPC_MPC512x
out_be32(&hw->plut, 0x01F5F666);
#endif
enable_lcdc(info);
}
static int map_video_memory(struct fb_info *info)
{
u32 smem_len = info->fix.line_length * info->var.yres_virtual;
void *p;
p = alloc_pages_exact(smem_len, GFP_DMA | __GFP_ZERO);
if (!p) {
dev_err(info->dev, "unable to allocate fb memory\n");
return -ENOMEM;
}
mutex_lock(&info->mm_lock);
info->screen_base = p;
info->fix.smem_start = virt_to_phys(info->screen_base);
info->fix.smem_len = smem_len;
mutex_unlock(&info->mm_lock);
info->screen_size = info->fix.smem_len;
return 0;
}
static void unmap_video_memory(struct fb_info *info)
{
void *p = info->screen_base;
size_t l = info->fix.smem_len;
mutex_lock(&info->mm_lock);
info->screen_base = NULL;
info->fix.smem_start = 0;
info->fix.smem_len = 0;
mutex_unlock(&info->mm_lock);
if (p)
free_pages_exact(p, l);
}
static int fsl_diu_set_aoi(struct fb_info *info)
{
struct fb_var_screeninfo *var = &info->var;
struct mfb_info *mfbi = info->par;
struct diu_ad *ad = mfbi->ad;
ad->offset_xyi = cpu_to_le32((var->yoffset << 16) | var->xoffset);
ad->offset_xyd = cpu_to_le32((mfbi->y_aoi_d << 16) | mfbi->x_aoi_d);
return 0;
}
static u32 fsl_diu_get_pixel_format(unsigned int bits_per_pixel)
{
#define PF_BYTE_F 0x10000000
#define PF_ALPHA_C_MASK 0x0E000000
#define PF_ALPHA_C_SHIFT 25
#define PF_BLUE_C_MASK 0x01800000
#define PF_BLUE_C_SHIFT 23
#define PF_GREEN_C_MASK 0x00600000
#define PF_GREEN_C_SHIFT 21
#define PF_RED_C_MASK 0x00180000
#define PF_RED_C_SHIFT 19
#define PF_PALETTE 0x00040000
#define PF_PIXEL_S_MASK 0x00030000
#define PF_PIXEL_S_SHIFT 16
#define PF_COMP_3_MASK 0x0000F000
#define PF_COMP_3_SHIFT 12
#define PF_COMP_2_MASK 0x00000F00
#define PF_COMP_2_SHIFT 8
#define PF_COMP_1_MASK 0x000000F0
#define PF_COMP_1_SHIFT 4
#define PF_COMP_0_MASK 0x0000000F
#define PF_COMP_0_SHIFT 0
#define MAKE_PF(alpha, red, blue, green, size, c0, c1, c2, c3) \
cpu_to_le32(PF_BYTE_F | (alpha << PF_ALPHA_C_SHIFT) | \
(blue << PF_BLUE_C_SHIFT) | (green << PF_GREEN_C_SHIFT) | \
(red << PF_RED_C_SHIFT) | (c3 << PF_COMP_3_SHIFT) | \
(c2 << PF_COMP_2_SHIFT) | (c1 << PF_COMP_1_SHIFT) | \
(c0 << PF_COMP_0_SHIFT) | (size << PF_PIXEL_S_SHIFT))
switch (bits_per_pixel) {
case 32:
return MAKE_PF(3, 2, 0, 1, 3, 8, 8, 8, 8);
case 24:
return MAKE_PF(4, 0, 1, 2, 2, 0, 8, 8, 8);
case 16:
return MAKE_PF(4, 2, 1, 0, 1, 5, 6, 5, 0);
default:
pr_err("fsl-diu: unsupported color depth %u\n", bits_per_pixel);
return 0;
}
}
static int fsl_diu_set_par(struct fb_info *info)
{
unsigned long len;
struct fb_var_screeninfo *var = &info->var;
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *data = mfbi->parent;
struct diu_ad *ad = mfbi->ad;
struct diu __iomem *hw;
hw = data->diu_reg;
set_fix(info);
len = info->var.yres_virtual * info->fix.line_length;
if (len != info->fix.smem_len) {
if (info->fix.smem_start)
unmap_video_memory(info);
if (map_video_memory(info)) {
dev_err(info->dev, "unable to allocate fb memory 1\n");
return -ENOMEM;
}
}
if (diu_ops.get_pixel_format)
ad->pix_fmt = diu_ops.get_pixel_format(data->monitor_port,
var->bits_per_pixel);
else
ad->pix_fmt = fsl_diu_get_pixel_format(var->bits_per_pixel);
ad->addr = cpu_to_le32(info->fix.smem_start);
ad->src_size_g_alpha = cpu_to_le32((var->yres_virtual << 12) |
var->xres_virtual) | mfbi->g_alpha;
ad->aoi_size = cpu_to_le32((var->yres << 16) | var->xres);
ad->offset_xyi = cpu_to_le32((var->yoffset << 16) | var->xoffset);
ad->offset_xyd = cpu_to_le32((mfbi->y_aoi_d << 16) | mfbi->x_aoi_d);
ad->ckmax_r = 0;
ad->ckmax_g = 0;
ad->ckmax_b = 0;
ad->ckmin_r = 255;
ad->ckmin_g = 255;
ad->ckmin_b = 255;
if (mfbi->index == PLANE0)
update_lcdc(info);
return 0;
}
static inline __u32 CNVT_TOHW(__u32 val, __u32 width)
{
return ((val << width) + 0x7FFF - val) >> 16;
}
static int fsl_diu_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
int ret = 1;
if (info->var.grayscale)
red = green = blue = (19595 * red + 38470 * green +
7471 * blue) >> 16;
switch (info->fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
u32 *pal = info->pseudo_palette;
u32 v;
red = CNVT_TOHW(red, info->var.red.length);
green = CNVT_TOHW(green, info->var.green.length);
blue = CNVT_TOHW(blue, info->var.blue.length);
transp = CNVT_TOHW(transp, info->var.transp.length);
v = (red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset) |
(transp << info->var.transp.offset);
pal[regno] = v;
ret = 0;
}
break;
}
return ret;
}
static int fsl_diu_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
if ((info->var.xoffset == var->xoffset) &&
(info->var.yoffset == var->yoffset))
return 0;
if (var->xoffset < 0 || var->yoffset < 0
|| var->xoffset + info->var.xres > info->var.xres_virtual
|| var->yoffset + info->var.yres > info->var.yres_virtual)
return -EINVAL;
info->var.xoffset = var->xoffset;
info->var.yoffset = var->yoffset;
if (var->vmode & FB_VMODE_YWRAP)
info->var.vmode |= FB_VMODE_YWRAP;
else
info->var.vmode &= ~FB_VMODE_YWRAP;
fsl_diu_set_aoi(info);
return 0;
}
static int fsl_diu_ioctl(struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
struct mfb_info *mfbi = info->par;
struct diu_ad *ad = mfbi->ad;
struct mfb_chroma_key ck;
unsigned char global_alpha;
struct aoi_display_offset aoi_d;
__u32 pix_fmt;
void __user *buf = (void __user *)arg;
if (!arg)
return -EINVAL;
dev_dbg(info->dev, "ioctl %08x (dir=%s%s type=%u nr=%u size=%u)\n", cmd,
_IOC_DIR(cmd) & _IOC_READ ? "R" : "",
_IOC_DIR(cmd) & _IOC_WRITE ? "W" : "",
_IOC_TYPE(cmd), _IOC_NR(cmd), _IOC_SIZE(cmd));
switch (cmd) {
case MFB_SET_PIXFMT_OLD:
dev_warn(info->dev,
"MFB_SET_PIXFMT value of 0x%08x is deprecated.\n",
MFB_SET_PIXFMT_OLD);
case MFB_SET_PIXFMT:
if (copy_from_user(&pix_fmt, buf, sizeof(pix_fmt)))
return -EFAULT;
ad->pix_fmt = pix_fmt;
break;
case MFB_GET_PIXFMT_OLD:
dev_warn(info->dev,
"MFB_GET_PIXFMT value of 0x%08x is deprecated.\n",
MFB_GET_PIXFMT_OLD);
case MFB_GET_PIXFMT:
pix_fmt = ad->pix_fmt;
if (copy_to_user(buf, &pix_fmt, sizeof(pix_fmt)))
return -EFAULT;
break;
case MFB_SET_AOID:
if (copy_from_user(&aoi_d, buf, sizeof(aoi_d)))
return -EFAULT;
mfbi->x_aoi_d = aoi_d.x_aoi_d;
mfbi->y_aoi_d = aoi_d.y_aoi_d;
fsl_diu_check_var(&info->var, info);
fsl_diu_set_aoi(info);
break;
case MFB_GET_AOID:
aoi_d.x_aoi_d = mfbi->x_aoi_d;
aoi_d.y_aoi_d = mfbi->y_aoi_d;
if (copy_to_user(buf, &aoi_d, sizeof(aoi_d)))
return -EFAULT;
break;
case MFB_GET_ALPHA:
global_alpha = mfbi->g_alpha;
if (copy_to_user(buf, &global_alpha, sizeof(global_alpha)))
return -EFAULT;
break;
case MFB_SET_ALPHA:
if (copy_from_user(&global_alpha, buf, sizeof(global_alpha)))
return -EFAULT;
ad->src_size_g_alpha = (ad->src_size_g_alpha & (~0xff)) |
(global_alpha & 0xff);
mfbi->g_alpha = global_alpha;
break;
case MFB_SET_CHROMA_KEY:
if (copy_from_user(&ck, buf, sizeof(ck)))
return -EFAULT;
if (ck.enable &&
(ck.red_max < ck.red_min ||
ck.green_max < ck.green_min ||
ck.blue_max < ck.blue_min))
return -EINVAL;
if (!ck.enable) {
ad->ckmax_r = 0;
ad->ckmax_g = 0;
ad->ckmax_b = 0;
ad->ckmin_r = 255;
ad->ckmin_g = 255;
ad->ckmin_b = 255;
} else {
ad->ckmax_r = ck.red_max;
ad->ckmax_g = ck.green_max;
ad->ckmax_b = ck.blue_max;
ad->ckmin_r = ck.red_min;
ad->ckmin_g = ck.green_min;
ad->ckmin_b = ck.blue_min;
}
break;
#ifdef CONFIG_PPC_MPC512x
case MFB_SET_GAMMA: {
struct fsl_diu_data *data = mfbi->parent;
if (copy_from_user(data->gamma, buf, sizeof(data->gamma)))
return -EFAULT;
setbits32(&data->diu_reg->gamma, 0);
break;
}
case MFB_GET_GAMMA: {
struct fsl_diu_data *data = mfbi->parent;
if (copy_to_user(buf, data->gamma, sizeof(data->gamma)))
return -EFAULT;
break;
}
#endif
default:
dev_err(info->dev, "unknown ioctl command (0x%08X)\n", cmd);
return -ENOIOCTLCMD;
}
return 0;
}
static int fsl_diu_open(struct fb_info *info, int user)
{
struct mfb_info *mfbi = info->par;
int res = 0;
if ((mfbi->index == PLANE0) && diu_ops.release_bootmem)
diu_ops.release_bootmem();
spin_lock(&diu_lock);
mfbi->count++;
if (mfbi->count == 1) {
fsl_diu_check_var(&info->var, info);
res = fsl_diu_set_par(info);
if (res < 0)
mfbi->count--;
else {
struct fsl_diu_data *data = mfbi->parent;
#ifdef CONFIG_NOT_COHERENT_CACHE
clrbits32(&data->diu_reg->int_mask,
INT_UNDRUN | INT_VSYNC);
#else
clrbits32(&data->diu_reg->int_mask, INT_UNDRUN);
#endif
fsl_diu_enable_panel(info);
}
}
spin_unlock(&diu_lock);
return res;
}
static int fsl_diu_release(struct fb_info *info, int user)
{
struct mfb_info *mfbi = info->par;
int res = 0;
spin_lock(&diu_lock);
mfbi->count--;
if (mfbi->count == 0) {
struct fsl_diu_data *data = mfbi->parent;
out_be32(&data->diu_reg->int_mask, 0xffffffff);
fsl_diu_disable_panel(info);
}
spin_unlock(&diu_lock);
return res;
}
static int install_fb(struct fb_info *info)
{
int rc;
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *data = mfbi->parent;
const char *aoi_mode, *init_aoi_mode = "320x240";
struct fb_videomode *db = fsl_diu_mode_db;
unsigned int dbsize = ARRAY_SIZE(fsl_diu_mode_db);
int has_default_mode = 1;
info->var.activate = FB_ACTIVATE_NOW;
info->fbops = &fsl_diu_ops;
info->flags = FBINFO_DEFAULT | FBINFO_VIRTFB | FBINFO_PARTIAL_PAN_OK |
FBINFO_READS_FAST;
info->pseudo_palette = mfbi->pseudo_palette;
rc = fb_alloc_cmap(&info->cmap, 16, 0);
if (rc)
return rc;
if (mfbi->index == PLANE0) {
if (data->has_edid) {
fb_edid_to_monspecs(data->edid_data, &info->monspecs);
fb_videomode_to_modelist(info->monspecs.modedb,
info->monspecs.modedb_len,
&info->modelist);
db = info->monspecs.modedb;
dbsize = info->monspecs.modedb_len;
}
aoi_mode = fb_mode;
} else {
aoi_mode = init_aoi_mode;
}
rc = fb_find_mode(&info->var, info, aoi_mode, db, dbsize, NULL,
default_bpp);
if (!rc) {
if ((mfbi->index == PLANE0) && data->has_edid)
has_default_mode = 0;
else
return -EINVAL;
}
if (!has_default_mode) {
rc = fb_find_mode(&info->var, info, aoi_mode, fsl_diu_mode_db,
ARRAY_SIZE(fsl_diu_mode_db), NULL, default_bpp);
if (rc)
has_default_mode = 1;
}
if (!has_default_mode && info->monspecs.modedb) {
struct fb_monspecs *specs = &info->monspecs;
struct fb_videomode *modedb = &specs->modedb[0];
if (specs->misc & FB_MISC_1ST_DETAIL) {
int i;
for (i = 0; i < specs->modedb_len; i++) {
if (specs->modedb[i].flag & FB_MODE_IS_FIRST) {
modedb = &specs->modedb[i];
break;
}
}
}
info->var.bits_per_pixel = default_bpp;
fb_videomode_to_var(&info->var, modedb);
}
if (fsl_diu_check_var(&info->var, info)) {
dev_err(info->dev, "fsl_diu_check_var failed\n");
unmap_video_memory(info);
fb_dealloc_cmap(&info->cmap);
return -EINVAL;
}
if (register_framebuffer(info) < 0) {
dev_err(info->dev, "register_framebuffer failed\n");
unmap_video_memory(info);
fb_dealloc_cmap(&info->cmap);
return -EINVAL;
}
mfbi->registered = 1;
dev_info(info->dev, "%s registered successfully\n", mfbi->id);
return 0;
}
static void uninstall_fb(struct fb_info *info)
{
struct mfb_info *mfbi = info->par;
if (!mfbi->registered)
return;
unregister_framebuffer(info);
unmap_video_memory(info);
if (&info->cmap)
fb_dealloc_cmap(&info->cmap);
mfbi->registered = 0;
}
static irqreturn_t fsl_diu_isr(int irq, void *dev_id)
{
struct diu __iomem *hw = dev_id;
uint32_t status = in_be32(&hw->int_status);
if (status) {
if (status & INT_UNDRUN) {
out_be32(&hw->diu_mode, 0);
udelay(1);
out_be32(&hw->diu_mode, 1);
}
#if defined(CONFIG_NOT_COHERENT_CACHE)
else if (status & INT_VSYNC) {
unsigned int i;
for (i = 0; i < coherence_data_size;
i += d_cache_line_size)
__asm__ __volatile__ (
"dcbz 0, %[input]"
::[input]"r"(&coherence_data[i]));
}
#endif
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int fsl_diu_suspend(struct platform_device *ofdev, pm_message_t state)
{
struct fsl_diu_data *data;
data = dev_get_drvdata(&ofdev->dev);
disable_lcdc(data->fsl_diu_info);
return 0;
}
static int fsl_diu_resume(struct platform_device *ofdev)
{
struct fsl_diu_data *data;
data = dev_get_drvdata(&ofdev->dev);
enable_lcdc(data->fsl_diu_info);
return 0;
}
static ssize_t store_monitor(struct device *device,
struct device_attribute *attr, const char *buf, size_t count)
{
enum fsl_diu_monitor_port old_monitor_port;
struct fsl_diu_data *data =
container_of(attr, struct fsl_diu_data, dev_attr);
old_monitor_port = data->monitor_port;
data->monitor_port = fsl_diu_name_to_port(buf);
if (old_monitor_port != data->monitor_port) {
unsigned int i;
for (i=0; i < NUM_AOIS; i++)
fsl_diu_set_par(&data->fsl_diu_info[i]);
}
return count;
}
static ssize_t show_monitor(struct device *device,
struct device_attribute *attr, char *buf)
{
struct fsl_diu_data *data =
container_of(attr, struct fsl_diu_data, dev_attr);
switch (data->monitor_port) {
case FSL_DIU_PORT_DVI:
return sprintf(buf, "DVI\n");
case FSL_DIU_PORT_LVDS:
return sprintf(buf, "Single-link LVDS\n");
case FSL_DIU_PORT_DLVDS:
return sprintf(buf, "Dual-link LVDS\n");
}
return 0;
}
static int fsl_diu_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mfb_info *mfbi;
struct fsl_diu_data *data;
dma_addr_t dma_addr;
const void *prop;
unsigned int i;
int ret;
data = dmam_alloc_coherent(&pdev->dev, sizeof(struct fsl_diu_data),
&dma_addr, GFP_DMA | __GFP_ZERO);
if (!data)
return -ENOMEM;
data->dma_addr = dma_addr;
if ((unsigned long)data & 31) {
dev_err(&pdev->dev, "misaligned allocation");
ret = -ENOMEM;
goto error;
}
spin_lock_init(&data->reg_lock);
for (i = 0; i < NUM_AOIS; i++) {
struct fb_info *info = &data->fsl_diu_info[i];
info->device = &pdev->dev;
info->par = &data->mfb[i];
data->ad[i].paddr = DMA_ADDR(data, ad[i]);
info->fix.smem_start = 0;
mfbi = info->par;
memcpy(mfbi, &mfb_template[i], sizeof(struct mfb_info));
mfbi->parent = data;
mfbi->ad = &data->ad[i];
}
prop = of_get_property(np, "edid", &ret);
if (prop && ret == EDID_LENGTH) {
memcpy(data->edid_data, prop, EDID_LENGTH);
data->has_edid = true;
}
data->diu_reg = of_iomap(np, 0);
if (!data->diu_reg) {
dev_err(&pdev->dev, "cannot map DIU registers\n");
ret = -EFAULT;
goto error;
}
data->irq = irq_of_parse_and_map(np, 0);
if (!data->irq) {
dev_err(&pdev->dev, "could not get DIU IRQ\n");
ret = -EINVAL;
goto error;
}
data->monitor_port = monitor_port;
data->dummy_ad.addr = cpu_to_le32(DMA_ADDR(data, dummy_aoi));
data->dummy_ad.pix_fmt = 0x88882317;
data->dummy_ad.src_size_g_alpha = cpu_to_le32((4 << 12) | 4);
data->dummy_ad.aoi_size = cpu_to_le32((4 << 16) | 2);
data->dummy_ad.offset_xyi = 0;
data->dummy_ad.offset_xyd = 0;
data->dummy_ad.next_ad = 0;
data->dummy_ad.paddr = DMA_ADDR(data, dummy_ad);
if (in_be32(&data->diu_reg->diu_mode) == MFB_MODE0)
out_be32(&data->diu_reg->desc[0], 0);
out_be32(&data->diu_reg->desc[1], data->dummy_ad.paddr);
out_be32(&data->diu_reg->desc[2], data->dummy_ad.paddr);
for (i = 0; i < NUM_AOIS; i++) {
ret = install_fb(&data->fsl_diu_info[i]);
if (ret) {
dev_err(&pdev->dev, "could not register fb %d\n", i);
goto error;
}
}
out_be32(&data->diu_reg->int_mask, 0xffffffff);
in_be32(&data->diu_reg->int_status);
ret = request_irq(data->irq, fsl_diu_isr, 0, "fsl-diu-fb",
&data->diu_reg);
if (ret) {
dev_err(&pdev->dev, "could not claim irq\n");
goto error;
}
sysfs_attr_init(&data->dev_attr.attr);
data->dev_attr.attr.name = "monitor";
data->dev_attr.attr.mode = S_IRUGO|S_IWUSR;
data->dev_attr.show = show_monitor;
data->dev_attr.store = store_monitor;
ret = device_create_file(&pdev->dev, &data->dev_attr);
if (ret) {
dev_err(&pdev->dev, "could not create sysfs file %s\n",
data->dev_attr.attr.name);
}
dev_set_drvdata(&pdev->dev, data);
return 0;
error:
for (i = 0; i < NUM_AOIS; i++)
uninstall_fb(&data->fsl_diu_info[i]);
iounmap(data->diu_reg);
return ret;
}
static int fsl_diu_remove(struct platform_device *pdev)
{
struct fsl_diu_data *data;
int i;
data = dev_get_drvdata(&pdev->dev);
disable_lcdc(&data->fsl_diu_info[0]);
free_irq(data->irq, &data->diu_reg);
for (i = 0; i < NUM_AOIS; i++)
uninstall_fb(&data->fsl_diu_info[i]);
iounmap(data->diu_reg);
return 0;
}
static int __init fsl_diu_setup(char *options)
{
char *opt;
unsigned long val;
if (!options || !*options)
return 0;
while ((opt = strsep(&options, ",")) != NULL) {
if (!*opt)
continue;
if (!strncmp(opt, "monitor=", 8)) {
monitor_port = fsl_diu_name_to_port(opt + 8);
} else if (!strncmp(opt, "bpp=", 4)) {
if (!strict_strtoul(opt + 4, 10, &val))
default_bpp = val;
} else
fb_mode = opt;
}
return 0;
}
static int __init fsl_diu_init(void)
{
#ifdef CONFIG_NOT_COHERENT_CACHE
struct device_node *np;
const u32 *prop;
#endif
int ret;
#ifndef MODULE
char *option;
if (fb_get_options("fslfb", &option))
return -ENODEV;
fsl_diu_setup(option);
#else
monitor_port = fsl_diu_name_to_port(monitor_string);
#endif
pr_info("Freescale Display Interface Unit (DIU) framebuffer driver\n");
#ifdef CONFIG_NOT_COHERENT_CACHE
np = of_find_node_by_type(NULL, "cpu");
if (!np) {
pr_err("fsl-diu-fb: can't find 'cpu' device node\n");
return -ENODEV;
}
prop = of_get_property(np, "d-cache-size", NULL);
if (prop == NULL) {
pr_err("fsl-diu-fb: missing 'd-cache-size' property' "
"in 'cpu' node\n");
of_node_put(np);
return -ENODEV;
}
coherence_data_size = be32_to_cpup(prop) * 13;
coherence_data_size /= 8;
pr_debug("fsl-diu-fb: coherence data size is %zu bytes\n",
coherence_data_size);
prop = of_get_property(np, "d-cache-line-size", NULL);
if (prop == NULL) {
pr_err("fsl-diu-fb: missing 'd-cache-line-size' property' "
"in 'cpu' node\n");
of_node_put(np);
return -ENODEV;
}
d_cache_line_size = be32_to_cpup(prop);
pr_debug("fsl-diu-fb: cache lines size is %u bytes\n",
d_cache_line_size);
of_node_put(np);
coherence_data = vmalloc(coherence_data_size);
if (!coherence_data) {
pr_err("fsl-diu-fb: could not allocate coherence data "
"(size=%zu)\n", coherence_data_size);
return -ENOMEM;
}
#endif
ret = platform_driver_register(&fsl_diu_driver);
if (ret) {
pr_err("fsl-diu-fb: failed to register platform driver\n");
#if defined(CONFIG_NOT_COHERENT_CACHE)
vfree(coherence_data);
#endif
}
return ret;
}
static void __exit fsl_diu_exit(void)
{
platform_driver_unregister(&fsl_diu_driver);
#if defined(CONFIG_NOT_COHERENT_CACHE)
vfree(coherence_data);
#endif
}
