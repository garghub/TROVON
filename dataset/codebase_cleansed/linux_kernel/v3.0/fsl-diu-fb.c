static void *fsl_diu_alloc(size_t size, phys_addr_t *phys)
{
void *virt;
pr_debug("size=%zu\n", size);
virt = alloc_pages_exact(size, GFP_DMA | __GFP_ZERO);
if (virt) {
*phys = virt_to_phys(virt);
pr_debug("virt=%p phys=%llx\n", virt,
(unsigned long long)*phys);
}
return virt;
}
static void fsl_diu_free(void *virt, size_t size)
{
pr_debug("virt=%p size=%zu\n", virt, size);
if (virt && size)
free_pages_exact(virt, size);
}
void wr_reg_wa(u32 *reg, u32 val)
{
do {
out_be32(reg, val);
} while (in_be32(reg) != val);
}
static int fsl_diu_enable_panel(struct fb_info *info)
{
struct mfb_info *pmfbi, *cmfbi, *mfbi = info->par;
struct diu *hw = dr.diu_reg;
struct diu_ad *ad = mfbi->ad;
struct fsl_diu_data *machine_data = mfbi->parent;
int res = 0;
pr_debug("enable_panel index %d\n", mfbi->index);
if (mfbi->type != MFB_TYPE_OFF) {
switch (mfbi->index) {
case 0:
if (hw->desc[0] != ad->paddr)
wr_reg_wa(&hw->desc[0], ad->paddr);
break;
case 1:
cmfbi = machine_data->fsl_diu_info[2]->par;
if (hw->desc[1] != ad->paddr) {
if (cmfbi->count > 0)
ad->next_ad =
cpu_to_le32(cmfbi->ad->paddr);
else
ad->next_ad = 0;
wr_reg_wa(&hw->desc[1], ad->paddr);
}
break;
case 3:
cmfbi = machine_data->fsl_diu_info[4]->par;
if (hw->desc[2] != ad->paddr) {
if (cmfbi->count > 0)
ad->next_ad =
cpu_to_le32(cmfbi->ad->paddr);
else
ad->next_ad = 0;
wr_reg_wa(&hw->desc[2], ad->paddr);
}
break;
case 2:
pmfbi = machine_data->fsl_diu_info[1]->par;
ad->next_ad = 0;
if (hw->desc[1] == machine_data->dummy_ad->paddr)
wr_reg_wa(&hw->desc[1], ad->paddr);
else
pmfbi->ad->next_ad = cpu_to_le32(ad->paddr);
break;
case 4:
pmfbi = machine_data->fsl_diu_info[3]->par;
ad->next_ad = 0;
if (hw->desc[2] == machine_data->dummy_ad->paddr)
wr_reg_wa(&hw->desc[2], ad->paddr);
else
pmfbi->ad->next_ad = cpu_to_le32(ad->paddr);
break;
default:
res = -EINVAL;
break;
}
} else
res = -EINVAL;
return res;
}
static int fsl_diu_disable_panel(struct fb_info *info)
{
struct mfb_info *pmfbi, *cmfbi, *mfbi = info->par;
struct diu *hw = dr.diu_reg;
struct diu_ad *ad = mfbi->ad;
struct fsl_diu_data *machine_data = mfbi->parent;
int res = 0;
switch (mfbi->index) {
case 0:
if (hw->desc[0] != machine_data->dummy_ad->paddr)
wr_reg_wa(&hw->desc[0], machine_data->dummy_ad->paddr);
break;
case 1:
cmfbi = machine_data->fsl_diu_info[2]->par;
if (cmfbi->count > 0)
wr_reg_wa(&hw->desc[1], cmfbi->ad->paddr);
else
wr_reg_wa(&hw->desc[1], machine_data->dummy_ad->paddr);
break;
case 3:
cmfbi = machine_data->fsl_diu_info[4]->par;
if (cmfbi->count > 0)
wr_reg_wa(&hw->desc[2], cmfbi->ad->paddr);
else
wr_reg_wa(&hw->desc[2], machine_data->dummy_ad->paddr);
break;
case 2:
pmfbi = machine_data->fsl_diu_info[1]->par;
if (hw->desc[1] != ad->paddr) {
if (pmfbi->count > 0)
pmfbi->ad->next_ad = 0;
} else
wr_reg_wa(&hw->desc[1], machine_data->dummy_ad->paddr);
break;
case 4:
pmfbi = machine_data->fsl_diu_info[3]->par;
if (hw->desc[2] != ad->paddr) {
if (pmfbi->count > 0)
pmfbi->ad->next_ad = 0;
} else
wr_reg_wa(&hw->desc[2], machine_data->dummy_ad->paddr);
break;
default:
res = -EINVAL;
break;
}
return res;
}
static void enable_lcdc(struct fb_info *info)
{
struct diu *hw = dr.diu_reg;
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *machine_data = mfbi->parent;
if (!machine_data->fb_enabled) {
out_be32(&hw->diu_mode, dr.mode);
machine_data->fb_enabled++;
}
}
static void disable_lcdc(struct fb_info *info)
{
struct diu *hw = dr.diu_reg;
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *machine_data = mfbi->parent;
if (machine_data->fb_enabled) {
out_be32(&hw->diu_mode, 0);
machine_data->fb_enabled = 0;
}
}
static void adjust_aoi_size_position(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct mfb_info *lower_aoi_mfbi, *upper_aoi_mfbi, *mfbi = info->par;
struct fsl_diu_data *machine_data = mfbi->parent;
int available_height, upper_aoi_bottom, index = mfbi->index;
int lower_aoi_is_open, upper_aoi_is_open;
__u32 base_plane_width, base_plane_height, upper_aoi_height;
base_plane_width = machine_data->fsl_diu_info[0]->var.xres;
base_plane_height = machine_data->fsl_diu_info[0]->var.yres;
if (mfbi->x_aoi_d < 0)
mfbi->x_aoi_d = 0;
if (mfbi->y_aoi_d < 0)
mfbi->y_aoi_d = 0;
switch (index) {
case 0:
if (mfbi->x_aoi_d != 0)
mfbi->x_aoi_d = 0;
if (mfbi->y_aoi_d != 0)
mfbi->y_aoi_d = 0;
break;
case 1:
case 3:
lower_aoi_mfbi = machine_data->fsl_diu_info[index+1]->par;
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
case 2:
case 4:
upper_aoi_mfbi = machine_data->fsl_diu_info[index-1]->par;
upper_aoi_height =
machine_data->fsl_diu_info[index-1]->var.yres;
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
pr_debug("check_var xres: %d\n", var->xres);
pr_debug("check_var yres: %d\n", var->yres);
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
strncpy(fix->id, mfbi->id, strlen(mfbi->id));
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
struct fsl_diu_data *machine_data = mfbi->parent;
struct diu *hw;
int i, j;
char __iomem *cursor_base, *gamma_table_base;
u32 temp;
hw = dr.diu_reg;
if (mfbi->type == MFB_TYPE_OFF) {
fsl_diu_disable_panel(info);
return;
}
diu_ops.set_monitor_port(machine_data->monitor_port);
gamma_table_base = pool.gamma.vaddr;
cursor_base = pool.cursor.vaddr;
for (i = 0; i <= 2; i++)
for (j = 0; j <= 255; j++)
*gamma_table_base++ = j;
diu_ops.set_gamma_table(machine_data->monitor_port, pool.gamma.vaddr);
pr_debug("update-lcdc: HW - %p\n Disabling DIU\n", hw);
disable_lcdc(info);
out_be32(&hw->gamma, pool.gamma.paddr);
out_be32(&hw->cursor, pool.cursor.paddr);
out_be32(&hw->bgnd, 0x007F7F7F);
out_be32(&hw->bgnd_wb, 0);
out_be32(&hw->disp_size, (var->yres << 16 | var->xres));
pr_debug("DIU xres: %d\n", var->xres);
pr_debug("DIU yres: %d\n", var->yres);
out_be32(&hw->wb_size, 0);
out_be32(&hw->wb_mem_addr, 0);
temp = var->left_margin << 22 |
var->hsync_len << 11 |
var->right_margin;
out_be32(&hw->hsyn_para, temp);
temp = var->upper_margin << 22 |
var->vsync_len << 11 |
var->lower_margin;
out_be32(&hw->vsyn_para, temp);
pr_debug("DIU right_margin - %d\n", var->right_margin);
pr_debug("DIU left_margin - %d\n", var->left_margin);
pr_debug("DIU hsync_len - %d\n", var->hsync_len);
pr_debug("DIU upper_margin - %d\n", var->upper_margin);
pr_debug("DIU lower_margin - %d\n", var->lower_margin);
pr_debug("DIU vsync_len - %d\n", var->vsync_len);
pr_debug("DIU HSYNC - 0x%08x\n", hw->hsyn_para);
pr_debug("DIU VSYNC - 0x%08x\n", hw->vsyn_para);
diu_ops.set_pixel_clock(var->pixclock);
out_be32(&hw->syn_pol, 0);
out_be32(&hw->thresholds, 0x00037800);
out_be32(&hw->int_status, 0);
out_be32(&hw->plut, 0x01F5F666);
enable_lcdc(info);
}
static int map_video_memory(struct fb_info *info)
{
phys_addr_t phys;
u32 smem_len = info->fix.line_length * info->var.yres_virtual;
pr_debug("info->var.xres_virtual = %d\n", info->var.xres_virtual);
pr_debug("info->var.yres_virtual = %d\n", info->var.yres_virtual);
pr_debug("info->fix.line_length = %d\n", info->fix.line_length);
pr_debug("MAP_VIDEO_MEMORY: smem_len = %u\n", smem_len);
info->screen_base = fsl_diu_alloc(smem_len, &phys);
if (info->screen_base == NULL) {
printk(KERN_ERR "Unable to allocate fb memory\n");
return -ENOMEM;
}
mutex_lock(&info->mm_lock);
info->fix.smem_start = (unsigned long) phys;
info->fix.smem_len = smem_len;
mutex_unlock(&info->mm_lock);
info->screen_size = info->fix.smem_len;
pr_debug("Allocated fb @ paddr=0x%08lx, size=%d.\n",
info->fix.smem_start, info->fix.smem_len);
pr_debug("screen base %p\n", info->screen_base);
return 0;
}
static void unmap_video_memory(struct fb_info *info)
{
fsl_diu_free(info->screen_base, info->fix.smem_len);
mutex_lock(&info->mm_lock);
info->screen_base = NULL;
info->fix.smem_start = 0;
info->fix.smem_len = 0;
mutex_unlock(&info->mm_lock);
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
static int fsl_diu_set_par(struct fb_info *info)
{
unsigned long len;
struct fb_var_screeninfo *var = &info->var;
struct mfb_info *mfbi = info->par;
struct fsl_diu_data *machine_data = mfbi->parent;
struct diu_ad *ad = mfbi->ad;
struct diu *hw;
hw = dr.diu_reg;
set_fix(info);
mfbi->cursor_reset = 1;
len = info->var.yres_virtual * info->fix.line_length;
if (len != info->fix.smem_len) {
if (info->fix.smem_start)
unmap_video_memory(info);
pr_debug("SET PAR: smem_len = %d\n", info->fix.smem_len);
if (map_video_memory(info)) {
printk(KERN_ERR "Unable to allocate fb memory 1\n");
return -ENOMEM;
}
}
ad->pix_fmt =
diu_ops.get_pixel_format(var->bits_per_pixel,
machine_data->monitor_port);
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
if (mfbi->index == 0)
update_lcdc(info);
return 0;
}
static inline __u32 CNVT_TOHW(__u32 val, __u32 width)
{
return ((val<<width) + 0x7FFF - val)>>16;
}
static int fsl_diu_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp, struct fb_info *info)
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
case FB_VISUAL_STATIC_PSEUDOCOLOR:
case FB_VISUAL_PSEUDOCOLOR:
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
static int fsl_diu_blank(int blank_mode, struct fb_info *info)
{
struct mfb_info *mfbi = info->par;
mfbi->blank = blank_mode;
switch (blank_mode) {
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_NORMAL:
break;
case FB_BLANK_POWERDOWN:
break;
case FB_BLANK_UNBLANK:
break;
}
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
switch (cmd) {
case MFB_SET_PIXFMT:
if (copy_from_user(&pix_fmt, buf, sizeof(pix_fmt)))
return -EFAULT;
ad->pix_fmt = pix_fmt;
pr_debug("Set pixel format to 0x%08x\n", ad->pix_fmt);
break;
case MFB_GET_PIXFMT:
pix_fmt = ad->pix_fmt;
if (copy_to_user(buf, &pix_fmt, sizeof(pix_fmt)))
return -EFAULT;
pr_debug("get pixel format 0x%08x\n", ad->pix_fmt);
break;
case MFB_SET_AOID:
if (copy_from_user(&aoi_d, buf, sizeof(aoi_d)))
return -EFAULT;
mfbi->x_aoi_d = aoi_d.x_aoi_d;
mfbi->y_aoi_d = aoi_d.y_aoi_d;
pr_debug("set AOI display offset of index %d to (%d,%d)\n",
mfbi->index, aoi_d.x_aoi_d, aoi_d.y_aoi_d);
fsl_diu_check_var(&info->var, info);
fsl_diu_set_aoi(info);
break;
case MFB_GET_AOID:
aoi_d.x_aoi_d = mfbi->x_aoi_d;
aoi_d.y_aoi_d = mfbi->y_aoi_d;
if (copy_to_user(buf, &aoi_d, sizeof(aoi_d)))
return -EFAULT;
pr_debug("get AOI display offset of index %d (%d,%d)\n",
mfbi->index, aoi_d.x_aoi_d, aoi_d.y_aoi_d);
break;
case MFB_GET_ALPHA:
global_alpha = mfbi->g_alpha;
if (copy_to_user(buf, &global_alpha, sizeof(global_alpha)))
return -EFAULT;
pr_debug("get global alpha of index %d\n", mfbi->index);
break;
case MFB_SET_ALPHA:
if (copy_from_user(&global_alpha, buf, sizeof(global_alpha)))
return -EFAULT;
ad->src_size_g_alpha = (ad->src_size_g_alpha & (~0xff)) |
(global_alpha & 0xff);
mfbi->g_alpha = global_alpha;
pr_debug("set global alpha for index %d\n", mfbi->index);
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
pr_debug("set chroma key\n");
break;
case FBIOGET_GWINFO:
if (mfbi->type == MFB_TYPE_OFF)
return -ENODEV;
if (copy_to_user(buf, ad, sizeof(*ad)))
return -EFAULT;
break;
case FBIOGET_HWCINFO:
pr_debug("FBIOGET_HWCINFO:0x%08x\n", FBIOGET_HWCINFO);
break;
case FBIOPUT_MODEINFO:
pr_debug("FBIOPUT_MODEINFO:0x%08x\n", FBIOPUT_MODEINFO);
break;
case FBIOGET_DISPINFO:
pr_debug("FBIOGET_DISPINFO:0x%08x\n", FBIOGET_DISPINFO);
break;
default:
printk(KERN_ERR "Unknown ioctl command (0x%08X)\n", cmd);
return -ENOIOCTLCMD;
}
return 0;
}
static int fsl_diu_open(struct fb_info *info, int user)
{
struct mfb_info *mfbi = info->par;
int res = 0;
if (!mfbi->index && diu_ops.release_bootmem)
diu_ops.release_bootmem();
spin_lock(&diu_lock);
mfbi->count++;
if (mfbi->count == 1) {
pr_debug("open plane index %d\n", mfbi->index);
fsl_diu_check_var(&info->var, info);
res = fsl_diu_set_par(info);
if (res < 0)
mfbi->count--;
else {
res = fsl_diu_enable_panel(info);
if (res < 0)
mfbi->count--;
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
pr_debug("release plane index %d\n", mfbi->index);
res = fsl_diu_disable_panel(info);
if (res < 0)
mfbi->count++;
}
spin_unlock(&diu_lock);
return res;
}
static int init_fbinfo(struct fb_info *info)
{
struct mfb_info *mfbi = info->par;
info->device = NULL;
info->var.activate = FB_ACTIVATE_NOW;
info->fbops = &fsl_diu_ops;
info->flags = FBINFO_FLAG_DEFAULT;
info->pseudo_palette = &mfbi->pseudo_palette;
fb_alloc_cmap(&info->cmap, 16, 0);
return 0;
}
static int __devinit install_fb(struct fb_info *info)
{
int rc;
struct mfb_info *mfbi = info->par;
const char *aoi_mode, *init_aoi_mode = "320x240";
struct fb_videomode *db = fsl_diu_mode_db;
unsigned int dbsize = ARRAY_SIZE(fsl_diu_mode_db);
int has_default_mode = 1;
if (init_fbinfo(info))
return -EINVAL;
if (mfbi->index == 0) {
if (mfbi->edid_data) {
fb_edid_to_monspecs(mfbi->edid_data, &info->monspecs);
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
pr_debug("mode used = %s\n", aoi_mode);
rc = fb_find_mode(&info->var, info, aoi_mode, db, dbsize,
&fsl_diu_default_mode, default_bpp);
switch (rc) {
case 1:
pr_debug("using mode specified in @mode\n");
break;
case 2:
pr_debug("using mode specified in @mode "
"with ignored refresh rate\n");
break;
case 3:
pr_debug("using mode default mode\n");
break;
case 4:
pr_debug("using mode from list\n");
break;
default:
pr_debug("rc = %d\n", rc);
pr_debug("failed to find mode\n");
if (mfbi->index == 0 && mfbi->edid_data)
has_default_mode = 0;
else
return -EINVAL;
break;
}
if (!has_default_mode) {
rc = fb_find_mode(&info->var, info, aoi_mode, fsl_diu_mode_db,
ARRAY_SIZE(fsl_diu_mode_db),
&fsl_diu_default_mode,
default_bpp);
if (rc > 0 && rc < 5)
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
pr_debug("xres_virtual %d\n", info->var.xres_virtual);
pr_debug("bits_per_pixel %d\n", info->var.bits_per_pixel);
pr_debug("info->var.yres_virtual = %d\n", info->var.yres_virtual);
pr_debug("info->fix.line_length = %d\n", info->fix.line_length);
if (mfbi->type == MFB_TYPE_OFF)
mfbi->blank = FB_BLANK_NORMAL;
else
mfbi->blank = FB_BLANK_UNBLANK;
if (fsl_diu_check_var(&info->var, info)) {
printk(KERN_ERR "fb_check_var failed");
fb_dealloc_cmap(&info->cmap);
return -EINVAL;
}
if (register_framebuffer(info) < 0) {
printk(KERN_ERR "register_framebuffer failed");
unmap_video_memory(info);
fb_dealloc_cmap(&info->cmap);
return -EINVAL;
}
mfbi->registered = 1;
printk(KERN_INFO "fb%d: %s fb device registered successfully.\n",
info->node, info->fix.id);
return 0;
}
static void uninstall_fb(struct fb_info *info)
{
struct mfb_info *mfbi = info->par;
if (!mfbi->registered)
return;
if (mfbi->index == 0)
kfree(mfbi->edid_data);
unregister_framebuffer(info);
unmap_video_memory(info);
if (&info->cmap)
fb_dealloc_cmap(&info->cmap);
mfbi->registered = 0;
}
static irqreturn_t fsl_diu_isr(int irq, void *dev_id)
{
struct diu *hw = dr.diu_reg;
unsigned int status = in_be32(&hw->int_status);
if (status) {
if (status & INT_UNDRUN) {
out_be32(&hw->diu_mode, 0);
pr_debug("Err: DIU occurs underrun!\n");
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
static int request_irq_local(int irq)
{
unsigned long status, ints;
struct diu *hw;
int ret;
hw = dr.diu_reg;
status = in_be32(&hw->int_status);
ret = request_irq(irq, fsl_diu_isr, 0, "diu", NULL);
if (ret)
pr_info("Request diu IRQ failed.\n");
else {
ints = INT_PARERR | INT_LS_BF_VS;
#if !defined(CONFIG_NOT_COHERENT_CACHE)
ints |= INT_VSYNC;
#endif
if (dr.mode == MFB_MODE2 || dr.mode == MFB_MODE3)
ints |= INT_VSYNC_WB;
status = in_be32(&hw->int_status);
out_be32(&hw->int_mask, ints);
}
return ret;
}
static void free_irq_local(int irq)
{
struct diu *hw = dr.diu_reg;
out_be32(&hw->int_mask, 0x1f);
free_irq(irq, NULL);
}
static int fsl_diu_suspend(struct platform_device *ofdev, pm_message_t state)
{
struct fsl_diu_data *machine_data;
machine_data = dev_get_drvdata(&ofdev->dev);
disable_lcdc(machine_data->fsl_diu_info[0]);
return 0;
}
static int fsl_diu_resume(struct platform_device *ofdev)
{
struct fsl_diu_data *machine_data;
machine_data = dev_get_drvdata(&ofdev->dev);
enable_lcdc(machine_data->fsl_diu_info[0]);
return 0;
}
static int allocate_buf(struct device *dev, struct diu_addr *buf, u32 size,
u32 bytes_align)
{
u32 offset, ssize;
u32 mask;
dma_addr_t paddr = 0;
ssize = size + bytes_align;
buf->vaddr = dma_alloc_coherent(dev, ssize, &paddr, GFP_DMA |
__GFP_ZERO);
if (!buf->vaddr)
return -ENOMEM;
buf->paddr = (__u32) paddr;
mask = bytes_align - 1;
offset = (u32)buf->paddr & mask;
if (offset) {
buf->offset = bytes_align - offset;
buf->paddr = (u32)buf->paddr + offset;
} else
buf->offset = 0;
return 0;
}
static void free_buf(struct device *dev, struct diu_addr *buf, u32 size,
u32 bytes_align)
{
dma_free_coherent(dev, size + bytes_align,
buf->vaddr, (buf->paddr - buf->offset));
return;
}
static ssize_t store_monitor(struct device *device,
struct device_attribute *attr, const char *buf, size_t count)
{
int old_monitor_port;
unsigned long val;
struct fsl_diu_data *machine_data =
container_of(attr, struct fsl_diu_data, dev_attr);
if (strict_strtoul(buf, 10, &val))
return 0;
old_monitor_port = machine_data->monitor_port;
machine_data->monitor_port = diu_ops.set_sysfs_monitor_port(val);
if (old_monitor_port != machine_data->monitor_port) {
fsl_diu_set_par(machine_data->fsl_diu_info[0]);
fsl_diu_set_par(machine_data->fsl_diu_info[1]);
fsl_diu_set_par(machine_data->fsl_diu_info[2]);
fsl_diu_set_par(machine_data->fsl_diu_info[3]);
fsl_diu_set_par(machine_data->fsl_diu_info[4]);
}
return count;
}
static ssize_t show_monitor(struct device *device,
struct device_attribute *attr, char *buf)
{
struct fsl_diu_data *machine_data =
container_of(attr, struct fsl_diu_data, dev_attr);
return diu_ops.show_monitor_port(machine_data->monitor_port, buf);
}
static int __devinit fsl_diu_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct mfb_info *mfbi;
phys_addr_t dummy_ad_addr;
int ret, i, error = 0;
struct resource res;
struct fsl_diu_data *machine_data;
int diu_mode;
machine_data = kzalloc(sizeof(struct fsl_diu_data), GFP_KERNEL);
if (!machine_data)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(machine_data->fsl_diu_info); i++) {
machine_data->fsl_diu_info[i] =
framebuffer_alloc(sizeof(struct mfb_info), &ofdev->dev);
if (!machine_data->fsl_diu_info[i]) {
dev_err(&ofdev->dev, "cannot allocate memory\n");
ret = -ENOMEM;
goto error2;
}
mfbi = machine_data->fsl_diu_info[i]->par;
memcpy(mfbi, &mfb_template[i], sizeof(struct mfb_info));
mfbi->parent = machine_data;
if (mfbi->index == 0) {
const u8 *prop;
int len;
prop = of_get_property(np, "edid", &len);
if (prop && len == EDID_LENGTH)
mfbi->edid_data = kmemdup(prop, EDID_LENGTH,
GFP_KERNEL);
}
}
ret = of_address_to_resource(np, 0, &res);
if (ret) {
dev_err(&ofdev->dev, "could not obtain DIU address\n");
goto error;
}
if (!res.start) {
dev_err(&ofdev->dev, "invalid DIU address\n");
goto error;
}
dev_dbg(&ofdev->dev, "%s, res.start: 0x%08x\n", __func__, res.start);
dr.diu_reg = ioremap(res.start, sizeof(struct diu));
if (!dr.diu_reg) {
dev_err(&ofdev->dev, "Err: can't map DIU registers!\n");
ret = -EFAULT;
goto error2;
}
diu_mode = in_be32(&dr.diu_reg->diu_mode);
if (diu_mode != MFB_MODE1)
out_be32(&dr.diu_reg->diu_mode, 0);
machine_data->irq = irq_of_parse_and_map(np, 0);
if (!machine_data->irq) {
dev_err(&ofdev->dev, "could not get DIU IRQ\n");
ret = -EINVAL;
goto error;
}
machine_data->monitor_port = monitor_port;
if (allocate_buf(&ofdev->dev, &pool.ad,
sizeof(struct diu_ad) * FSL_AOI_NUM, 8))
return -ENOMEM;
if (allocate_buf(&ofdev->dev, &pool.gamma, 768, 32)) {
ret = -ENOMEM;
goto error;
}
if (allocate_buf(&ofdev->dev, &pool.cursor, MAX_CURS * MAX_CURS * 2,
32)) {
ret = -ENOMEM;
goto error;
}
i = ARRAY_SIZE(machine_data->fsl_diu_info);
machine_data->dummy_ad = (struct diu_ad *)
((u32)pool.ad.vaddr + pool.ad.offset) + i;
machine_data->dummy_ad->paddr = pool.ad.paddr +
i * sizeof(struct diu_ad);
machine_data->dummy_aoi_virt = fsl_diu_alloc(64, &dummy_ad_addr);
if (!machine_data->dummy_aoi_virt) {
ret = -ENOMEM;
goto error;
}
machine_data->dummy_ad->addr = cpu_to_le32(dummy_ad_addr);
machine_data->dummy_ad->pix_fmt = 0x88882317;
machine_data->dummy_ad->src_size_g_alpha = cpu_to_le32((4 << 12) | 4);
machine_data->dummy_ad->aoi_size = cpu_to_le32((4 << 16) | 2);
machine_data->dummy_ad->offset_xyi = 0;
machine_data->dummy_ad->offset_xyd = 0;
machine_data->dummy_ad->next_ad = 0;
if (diu_mode != MFB_MODE1)
out_be32(&dr.diu_reg->desc[0], machine_data->dummy_ad->paddr);
out_be32(&dr.diu_reg->desc[1], machine_data->dummy_ad->paddr);
out_be32(&dr.diu_reg->desc[2], machine_data->dummy_ad->paddr);
for (i = 0; i < ARRAY_SIZE(machine_data->fsl_diu_info); i++) {
machine_data->fsl_diu_info[i]->fix.smem_start = 0;
mfbi = machine_data->fsl_diu_info[i]->par;
mfbi->ad = (struct diu_ad *)((u32)pool.ad.vaddr
+ pool.ad.offset) + i;
mfbi->ad->paddr = pool.ad.paddr + i * sizeof(struct diu_ad);
ret = install_fb(machine_data->fsl_diu_info[i]);
if (ret) {
dev_err(&ofdev->dev,
"Failed to register framebuffer %d\n",
i);
goto error;
}
}
if (request_irq_local(machine_data->irq)) {
dev_err(machine_data->fsl_diu_info[0]->dev,
"could not request irq for diu.");
goto error;
}
sysfs_attr_init(&machine_data->dev_attr.attr);
machine_data->dev_attr.attr.name = "monitor";
machine_data->dev_attr.attr.mode = S_IRUGO|S_IWUSR;
machine_data->dev_attr.show = show_monitor;
machine_data->dev_attr.store = store_monitor;
error = device_create_file(machine_data->fsl_diu_info[0]->dev,
&machine_data->dev_attr);
if (error) {
dev_err(machine_data->fsl_diu_info[0]->dev,
"could not create sysfs %s file\n",
machine_data->dev_attr.attr.name);
}
dev_set_drvdata(&ofdev->dev, machine_data);
return 0;
error:
for (i = ARRAY_SIZE(machine_data->fsl_diu_info);
i > 0; i--)
uninstall_fb(machine_data->fsl_diu_info[i - 1]);
if (pool.ad.vaddr)
free_buf(&ofdev->dev, &pool.ad,
sizeof(struct diu_ad) * FSL_AOI_NUM, 8);
if (pool.gamma.vaddr)
free_buf(&ofdev->dev, &pool.gamma, 768, 32);
if (pool.cursor.vaddr)
free_buf(&ofdev->dev, &pool.cursor, MAX_CURS * MAX_CURS * 2,
32);
if (machine_data->dummy_aoi_virt)
fsl_diu_free(machine_data->dummy_aoi_virt, 64);
iounmap(dr.diu_reg);
error2:
for (i = 0; i < ARRAY_SIZE(machine_data->fsl_diu_info); i++)
if (machine_data->fsl_diu_info[i])
framebuffer_release(machine_data->fsl_diu_info[i]);
kfree(machine_data);
return ret;
}
static int fsl_diu_remove(struct platform_device *ofdev)
{
struct fsl_diu_data *machine_data;
int i;
machine_data = dev_get_drvdata(&ofdev->dev);
disable_lcdc(machine_data->fsl_diu_info[0]);
free_irq_local(machine_data->irq);
for (i = ARRAY_SIZE(machine_data->fsl_diu_info); i > 0; i--)
uninstall_fb(machine_data->fsl_diu_info[i - 1]);
if (pool.ad.vaddr)
free_buf(&ofdev->dev, &pool.ad,
sizeof(struct diu_ad) * FSL_AOI_NUM, 8);
if (pool.gamma.vaddr)
free_buf(&ofdev->dev, &pool.gamma, 768, 32);
if (pool.cursor.vaddr)
free_buf(&ofdev->dev, &pool.cursor, MAX_CURS * MAX_CURS * 2,
32);
if (machine_data->dummy_aoi_virt)
fsl_diu_free(machine_data->dummy_aoi_virt, 64);
iounmap(dr.diu_reg);
for (i = 0; i < ARRAY_SIZE(machine_data->fsl_diu_info); i++)
if (machine_data->fsl_diu_info[i])
framebuffer_release(machine_data->fsl_diu_info[i]);
kfree(machine_data);
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
if (!strict_strtoul(opt + 8, 10, &val) && (val <= 2))
monitor_port = val;
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
#endif
printk(KERN_INFO "Freescale DIU driver\n");
#ifdef CONFIG_NOT_COHERENT_CACHE
np = of_find_node_by_type(NULL, "cpu");
if (!np) {
printk(KERN_ERR "Err: can't find device node 'cpu'\n");
return -ENODEV;
}
prop = of_get_property(np, "d-cache-size", NULL);
if (prop == NULL) {
of_node_put(np);
return -ENODEV;
}
coherence_data_size = *prop * 13;
coherence_data_size /= 8;
prop = of_get_property(np, "d-cache-line-size", NULL);
if (prop == NULL) {
of_node_put(np);
return -ENODEV;
}
d_cache_line_size = *prop;
of_node_put(np);
coherence_data = vmalloc(coherence_data_size);
if (!coherence_data)
return -ENOMEM;
#endif
ret = platform_driver_register(&fsl_diu_driver);
if (ret) {
printk(KERN_ERR
"fsl-diu: failed to register platform driver\n");
#if defined(CONFIG_NOT_COHERENT_CACHE)
vfree(coherence_data);
#endif
iounmap(dr.diu_reg);
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
