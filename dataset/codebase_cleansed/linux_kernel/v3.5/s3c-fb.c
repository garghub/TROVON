static bool s3c_fb_validate_win_bpp(struct s3c_fb_win *win, unsigned int bpp)
{
return win->variant.valid_bpp & VALID_BPP(bpp);
}
static int s3c_fb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct s3c_fb_win *win = info->par;
struct s3c_fb *sfb = win->parent;
dev_dbg(sfb->dev, "checking parameters\n");
var->xres_virtual = max(var->xres_virtual, var->xres);
var->yres_virtual = max(var->yres_virtual, var->yres);
if (!s3c_fb_validate_win_bpp(win, var->bits_per_pixel)) {
dev_dbg(sfb->dev, "win %d: unsupported bpp %d\n",
win->index, var->bits_per_pixel);
return -EINVAL;
}
var->transp.offset = 0;
var->transp.length = 0;
switch (var->bits_per_pixel) {
case 1:
case 2:
case 4:
case 8:
if (sfb->variant.palette[win->index] != 0) {
var->red.offset = 4;
var->green.offset = 2;
var->blue.offset = 0;
var->red.length = 5;
var->green.length = 3;
var->blue.length = 2;
var->transp.offset = 7;
var->transp.length = 1;
} else {
var->red.offset = 0;
var->red.length = var->bits_per_pixel;
var->green = var->red;
var->blue = var->red;
}
break;
case 19:
var->transp.offset = 18;
var->transp.length = 1;
case 18:
var->bits_per_pixel = 32;
var->red.offset = 12;
var->green.offset = 6;
var->blue.offset = 0;
var->red.length = 6;
var->green.length = 6;
var->blue.length = 6;
break;
case 16:
var->red.offset = 11;
var->green.offset = 5;
var->blue.offset = 0;
var->red.length = 5;
var->green.length = 6;
var->blue.length = 5;
break;
case 32:
case 28:
case 25:
var->transp.length = var->bits_per_pixel - 24;
var->transp.offset = 24;
case 24:
var->bits_per_pixel = 32;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
break;
default:
dev_err(sfb->dev, "invalid bpp\n");
}
dev_dbg(sfb->dev, "%s: verified parameters\n", __func__);
return 0;
}
static int s3c_fb_calc_pixclk(struct s3c_fb *sfb, unsigned int pixclk)
{
unsigned long clk;
unsigned long long tmp;
unsigned int result;
if (sfb->variant.has_clksel)
clk = clk_get_rate(sfb->bus_clk);
else
clk = clk_get_rate(sfb->lcd_clk);
tmp = (unsigned long long)clk;
tmp *= pixclk;
do_div(tmp, 1000000000UL);
result = (unsigned int)tmp / 1000;
dev_dbg(sfb->dev, "pixclk=%u, clk=%lu, div=%d (%lu)\n",
pixclk, clk, result, result ? clk / result : clk);
return result;
}
static int s3c_fb_align_word(unsigned int bpp, unsigned int pix)
{
int pix_per_word;
if (bpp > 16)
return pix;
pix_per_word = (8 * 32) / bpp;
return ALIGN(pix, pix_per_word);
}
static void vidosd_set_size(struct s3c_fb_win *win, u32 size)
{
struct s3c_fb *sfb = win->parent;
if (win->variant.osd_size_off)
writel(size, sfb->regs + OSD_BASE(win->index, sfb->variant)
+ win->variant.osd_size_off);
}
static void vidosd_set_alpha(struct s3c_fb_win *win, u32 alpha)
{
struct s3c_fb *sfb = win->parent;
if (win->variant.has_osd_alpha)
writel(alpha, sfb->regs + VIDOSD_C(win->index, sfb->variant));
}
static void shadow_protect_win(struct s3c_fb_win *win, bool protect)
{
struct s3c_fb *sfb = win->parent;
u32 reg;
if (protect) {
if (sfb->variant.has_prtcon) {
writel(PRTCON_PROTECT, sfb->regs + PRTCON);
} else if (sfb->variant.has_shadowcon) {
reg = readl(sfb->regs + SHADOWCON);
writel(reg | SHADOWCON_WINx_PROTECT(win->index),
sfb->regs + SHADOWCON);
}
} else {
if (sfb->variant.has_prtcon) {
writel(0, sfb->regs + PRTCON);
} else if (sfb->variant.has_shadowcon) {
reg = readl(sfb->regs + SHADOWCON);
writel(reg & ~SHADOWCON_WINx_PROTECT(win->index),
sfb->regs + SHADOWCON);
}
}
}
static void s3c_fb_enable(struct s3c_fb *sfb, int enable)
{
u32 vidcon0 = readl(sfb->regs + VIDCON0);
if (enable && !sfb->output_on)
pm_runtime_get_sync(sfb->dev);
if (enable) {
vidcon0 |= VIDCON0_ENVID | VIDCON0_ENVID_F;
} else {
if (vidcon0 & VIDCON0_ENVID) {
vidcon0 |= VIDCON0_ENVID;
vidcon0 &= ~VIDCON0_ENVID_F;
}
}
writel(vidcon0, sfb->regs + VIDCON0);
if (!enable && sfb->output_on)
pm_runtime_put_sync(sfb->dev);
sfb->output_on = enable;
}
static int s3c_fb_set_par(struct fb_info *info)
{
struct fb_var_screeninfo *var = &info->var;
struct s3c_fb_win *win = info->par;
struct s3c_fb *sfb = win->parent;
void __iomem *regs = sfb->regs;
void __iomem *buf = regs;
int win_no = win->index;
u32 alpha = 0;
u32 data;
u32 pagewidth;
dev_dbg(sfb->dev, "setting framebuffer parameters\n");
pm_runtime_get_sync(sfb->dev);
shadow_protect_win(win, 1);
switch (var->bits_per_pixel) {
case 32:
case 24:
case 16:
case 12:
info->fix.visual = FB_VISUAL_TRUECOLOR;
break;
case 8:
if (win->variant.palette_sz >= 256)
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
else
info->fix.visual = FB_VISUAL_TRUECOLOR;
break;
case 1:
info->fix.visual = FB_VISUAL_MONO01;
break;
default:
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
break;
}
info->fix.line_length = (var->xres_virtual * var->bits_per_pixel) / 8;
info->fix.xpanstep = info->var.xres_virtual > info->var.xres ? 1 : 0;
info->fix.ypanstep = info->var.yres_virtual > info->var.yres ? 1 : 0;
writel(0, regs + WINCON(win_no));
if (!sfb->output_on)
s3c_fb_enable(sfb, 1);
buf = regs + win_no * 8;
writel(info->fix.smem_start, buf + sfb->variant.buf_start);
data = info->fix.smem_start + info->fix.line_length * var->yres;
writel(data, buf + sfb->variant.buf_end);
pagewidth = (var->xres * var->bits_per_pixel) >> 3;
data = VIDW_BUF_SIZE_OFFSET(info->fix.line_length - pagewidth) |
VIDW_BUF_SIZE_PAGEWIDTH(pagewidth) |
VIDW_BUF_SIZE_OFFSET_E(info->fix.line_length - pagewidth) |
VIDW_BUF_SIZE_PAGEWIDTH_E(pagewidth);
writel(data, regs + sfb->variant.buf_size + (win_no * 4));
data = VIDOSDxA_TOPLEFT_X(0) | VIDOSDxA_TOPLEFT_Y(0) |
VIDOSDxA_TOPLEFT_X_E(0) | VIDOSDxA_TOPLEFT_Y_E(0);
writel(data, regs + VIDOSD_A(win_no, sfb->variant));
data = VIDOSDxB_BOTRIGHT_X(s3c_fb_align_word(var->bits_per_pixel,
var->xres - 1)) |
VIDOSDxB_BOTRIGHT_Y(var->yres - 1) |
VIDOSDxB_BOTRIGHT_X_E(s3c_fb_align_word(var->bits_per_pixel,
var->xres - 1)) |
VIDOSDxB_BOTRIGHT_Y_E(var->yres - 1);
writel(data, regs + VIDOSD_B(win_no, sfb->variant));
data = var->xres * var->yres;
alpha = VIDISD14C_ALPHA1_R(0xf) |
VIDISD14C_ALPHA1_G(0xf) |
VIDISD14C_ALPHA1_B(0xf);
vidosd_set_alpha(win, alpha);
vidosd_set_size(win, data);
if (sfb->variant.has_shadowcon) {
data = readl(sfb->regs + SHADOWCON);
data |= SHADOWCON_CHx_ENABLE(win_no);
writel(data, sfb->regs + SHADOWCON);
}
data = WINCONx_ENWIN;
sfb->enabled |= (1 << win->index);
switch (var->bits_per_pixel) {
case 1:
data |= WINCON0_BPPMODE_1BPP;
data |= WINCONx_BITSWP;
data |= WINCONx_BURSTLEN_4WORD;
break;
case 2:
data |= WINCON0_BPPMODE_2BPP;
data |= WINCONx_BITSWP;
data |= WINCONx_BURSTLEN_8WORD;
break;
case 4:
data |= WINCON0_BPPMODE_4BPP;
data |= WINCONx_BITSWP;
data |= WINCONx_BURSTLEN_8WORD;
break;
case 8:
if (var->transp.length != 0)
data |= WINCON1_BPPMODE_8BPP_1232;
else
data |= WINCON0_BPPMODE_8BPP_PALETTE;
data |= WINCONx_BURSTLEN_8WORD;
data |= WINCONx_BYTSWP;
break;
case 16:
if (var->transp.length != 0)
data |= WINCON1_BPPMODE_16BPP_A1555;
else
data |= WINCON0_BPPMODE_16BPP_565;
data |= WINCONx_HAWSWP;
data |= WINCONx_BURSTLEN_16WORD;
break;
case 24:
case 32:
if (var->red.length == 6) {
if (var->transp.length != 0)
data |= WINCON1_BPPMODE_19BPP_A1666;
else
data |= WINCON1_BPPMODE_18BPP_666;
} else if (var->transp.length == 1)
data |= WINCON1_BPPMODE_25BPP_A1888
| WINCON1_BLD_PIX;
else if ((var->transp.length == 4) ||
(var->transp.length == 8))
data |= WINCON1_BPPMODE_28BPP_A4888
| WINCON1_BLD_PIX | WINCON1_ALPHA_SEL;
else
data |= WINCON0_BPPMODE_24BPP_888;
data |= WINCONx_WSWP;
data |= WINCONx_BURSTLEN_16WORD;
break;
}
if (win_no > 0) {
u32 keycon0_data = 0, keycon1_data = 0;
void __iomem *keycon = regs + sfb->variant.keycon;
keycon0_data = ~(WxKEYCON0_KEYBL_EN |
WxKEYCON0_KEYEN_F |
WxKEYCON0_DIRCON) | WxKEYCON0_COMPKEY(0);
keycon1_data = WxKEYCON1_COLVAL(0xffffff);
keycon += (win_no - 1) * 8;
writel(keycon0_data, keycon + WKEYCON0);
writel(keycon1_data, keycon + WKEYCON1);
}
writel(data, regs + sfb->variant.wincon + (win_no * 4));
writel(0x0, regs + sfb->variant.winmap + (win_no * 4));
if (sfb->variant.has_blendcon) {
data = readl(sfb->regs + BLENDCON);
data &= ~BLENDCON_NEW_MASK;
if (var->transp.length > 4)
data |= BLENDCON_NEW_8BIT_ALPHA_VALUE;
else
data |= BLENDCON_NEW_4BIT_ALPHA_VALUE;
writel(data, sfb->regs + BLENDCON);
}
shadow_protect_win(win, 0);
pm_runtime_put_sync(sfb->dev);
return 0;
}
static void s3c_fb_update_palette(struct s3c_fb *sfb,
struct s3c_fb_win *win,
unsigned int reg,
u32 value)
{
void __iomem *palreg;
u32 palcon;
palreg = sfb->regs + sfb->variant.palette[win->index];
dev_dbg(sfb->dev, "%s: win %d, reg %d (%p): %08x\n",
__func__, win->index, reg, palreg, value);
win->palette_buffer[reg] = value;
palcon = readl(sfb->regs + WPALCON);
writel(palcon | WPALCON_PAL_UPDATE, sfb->regs + WPALCON);
if (win->variant.palette_16bpp)
writew(value, palreg + (reg * 2));
else
writel(value, palreg + (reg * 4));
writel(palcon, sfb->regs + WPALCON);
}
static inline unsigned int chan_to_field(unsigned int chan,
struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int s3c_fb_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
struct s3c_fb_win *win = info->par;
struct s3c_fb *sfb = win->parent;
unsigned int val;
dev_dbg(sfb->dev, "%s: win %d: %d => rgb=%d/%d/%d\n",
__func__, win->index, regno, red, green, blue);
pm_runtime_get_sync(sfb->dev);
switch (info->fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
u32 *pal = info->pseudo_palette;
val = chan_to_field(red, &info->var.red);
val |= chan_to_field(green, &info->var.green);
val |= chan_to_field(blue, &info->var.blue);
pal[regno] = val;
}
break;
case FB_VISUAL_PSEUDOCOLOR:
if (regno < win->variant.palette_sz) {
val = chan_to_field(red, &win->palette.r);
val |= chan_to_field(green, &win->palette.g);
val |= chan_to_field(blue, &win->palette.b);
s3c_fb_update_palette(sfb, win, regno, val);
}
break;
default:
pm_runtime_put_sync(sfb->dev);
return 1;
}
pm_runtime_put_sync(sfb->dev);
return 0;
}
static int s3c_fb_blank(int blank_mode, struct fb_info *info)
{
struct s3c_fb_win *win = info->par;
struct s3c_fb *sfb = win->parent;
unsigned int index = win->index;
u32 wincon;
u32 output_on = sfb->output_on;
dev_dbg(sfb->dev, "blank mode %d\n", blank_mode);
pm_runtime_get_sync(sfb->dev);
wincon = readl(sfb->regs + sfb->variant.wincon + (index * 4));
switch (blank_mode) {
case FB_BLANK_POWERDOWN:
wincon &= ~WINCONx_ENWIN;
sfb->enabled &= ~(1 << index);
case FB_BLANK_NORMAL:
shadow_protect_win(win, 1);
writel(WINxMAP_MAP | WINxMAP_MAP_COLOUR(0x0),
sfb->regs + sfb->variant.winmap + (index * 4));
shadow_protect_win(win, 0);
break;
case FB_BLANK_UNBLANK:
shadow_protect_win(win, 1);
writel(0x0, sfb->regs + sfb->variant.winmap + (index * 4));
shadow_protect_win(win, 0);
wincon |= WINCONx_ENWIN;
sfb->enabled |= (1 << index);
break;
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
default:
pm_runtime_put_sync(sfb->dev);
return 1;
}
shadow_protect_win(win, 1);
writel(wincon, sfb->regs + sfb->variant.wincon + (index * 4));
s3c_fb_enable(sfb, sfb->enabled ? 1 : 0);
shadow_protect_win(win, 0);
pm_runtime_put_sync(sfb->dev);
return output_on == sfb->output_on;
}
static int s3c_fb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct s3c_fb_win *win = info->par;
struct s3c_fb *sfb = win->parent;
void __iomem *buf = sfb->regs + win->index * 8;
unsigned int start_boff, end_boff;
pm_runtime_get_sync(sfb->dev);
start_boff = var->yoffset * info->fix.line_length;
if (info->var.bits_per_pixel >= 8) {
start_boff += var->xoffset * (info->var.bits_per_pixel >> 3);
} else {
switch (info->var.bits_per_pixel) {
case 4:
start_boff += var->xoffset >> 1;
break;
case 2:
start_boff += var->xoffset >> 2;
break;
case 1:
start_boff += var->xoffset >> 3;
break;
default:
dev_err(sfb->dev, "invalid bpp\n");
pm_runtime_put_sync(sfb->dev);
return -EINVAL;
}
}
end_boff = start_boff + info->var.yres * info->fix.line_length;
shadow_protect_win(win, 1);
writel(info->fix.smem_start + start_boff, buf + sfb->variant.buf_start);
writel(info->fix.smem_start + end_boff, buf + sfb->variant.buf_end);
shadow_protect_win(win, 0);
pm_runtime_put_sync(sfb->dev);
return 0;
}
static void s3c_fb_enable_irq(struct s3c_fb *sfb)
{
void __iomem *regs = sfb->regs;
u32 irq_ctrl_reg;
if (!test_and_set_bit(S3C_FB_VSYNC_IRQ_EN, &sfb->irq_flags)) {
irq_ctrl_reg = readl(regs + VIDINTCON0);
irq_ctrl_reg |= VIDINTCON0_INT_ENABLE;
irq_ctrl_reg |= VIDINTCON0_INT_FRAME;
irq_ctrl_reg &= ~VIDINTCON0_FRAMESEL0_MASK;
irq_ctrl_reg |= VIDINTCON0_FRAMESEL0_VSYNC;
irq_ctrl_reg &= ~VIDINTCON0_FRAMESEL1_MASK;
irq_ctrl_reg |= VIDINTCON0_FRAMESEL1_NONE;
writel(irq_ctrl_reg, regs + VIDINTCON0);
}
}
static void s3c_fb_disable_irq(struct s3c_fb *sfb)
{
void __iomem *regs = sfb->regs;
u32 irq_ctrl_reg;
if (test_and_clear_bit(S3C_FB_VSYNC_IRQ_EN, &sfb->irq_flags)) {
irq_ctrl_reg = readl(regs + VIDINTCON0);
irq_ctrl_reg &= ~VIDINTCON0_INT_FRAME;
irq_ctrl_reg &= ~VIDINTCON0_INT_ENABLE;
writel(irq_ctrl_reg, regs + VIDINTCON0);
}
}
static irqreturn_t s3c_fb_irq(int irq, void *dev_id)
{
struct s3c_fb *sfb = dev_id;
void __iomem *regs = sfb->regs;
u32 irq_sts_reg;
spin_lock(&sfb->slock);
irq_sts_reg = readl(regs + VIDINTCON1);
if (irq_sts_reg & VIDINTCON1_INT_FRAME) {
writel(VIDINTCON1_INT_FRAME, regs + VIDINTCON1);
sfb->vsync_info.count++;
wake_up_interruptible(&sfb->vsync_info.wait);
}
s3c_fb_disable_irq(sfb);
spin_unlock(&sfb->slock);
return IRQ_HANDLED;
}
static int s3c_fb_wait_for_vsync(struct s3c_fb *sfb, u32 crtc)
{
unsigned long count;
int ret;
if (crtc != 0)
return -ENODEV;
pm_runtime_get_sync(sfb->dev);
count = sfb->vsync_info.count;
s3c_fb_enable_irq(sfb);
ret = wait_event_interruptible_timeout(sfb->vsync_info.wait,
count != sfb->vsync_info.count,
msecs_to_jiffies(VSYNC_TIMEOUT_MSEC));
pm_runtime_put_sync(sfb->dev);
if (ret == 0)
return -ETIMEDOUT;
return 0;
}
static int s3c_fb_ioctl(struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
struct s3c_fb_win *win = info->par;
struct s3c_fb *sfb = win->parent;
int ret;
u32 crtc;
switch (cmd) {
case FBIO_WAITFORVSYNC:
if (get_user(crtc, (u32 __user *)arg)) {
ret = -EFAULT;
break;
}
ret = s3c_fb_wait_for_vsync(sfb, crtc);
break;
default:
ret = -ENOTTY;
}
return ret;
}
static void s3c_fb_missing_pixclock(struct fb_videomode *mode)
{
u64 pixclk = 1000000000000ULL;
u32 div;
div = mode->left_margin + mode->hsync_len + mode->right_margin +
mode->xres;
div *= mode->upper_margin + mode->vsync_len + mode->lower_margin +
mode->yres;
div *= mode->refresh ? : 60;
do_div(pixclk, div);
mode->pixclock = pixclk;
}
static int __devinit s3c_fb_alloc_memory(struct s3c_fb *sfb,
struct s3c_fb_win *win)
{
struct s3c_fb_pd_win *windata = win->windata;
unsigned int real_size, virt_size, size;
struct fb_info *fbi = win->fbinfo;
dma_addr_t map_dma;
dev_dbg(sfb->dev, "allocating memory for display\n");
real_size = windata->xres * windata->yres;
virt_size = windata->virtual_x * windata->virtual_y;
dev_dbg(sfb->dev, "real_size=%u (%u.%u), virt_size=%u (%u.%u)\n",
real_size, windata->xres, windata->yres,
virt_size, windata->virtual_x, windata->virtual_y);
size = (real_size > virt_size) ? real_size : virt_size;
size *= (windata->max_bpp > 16) ? 32 : windata->max_bpp;
size /= 8;
fbi->fix.smem_len = size;
size = PAGE_ALIGN(size);
dev_dbg(sfb->dev, "want %u bytes for window\n", size);
fbi->screen_base = dma_alloc_writecombine(sfb->dev, size,
&map_dma, GFP_KERNEL);
if (!fbi->screen_base)
return -ENOMEM;
dev_dbg(sfb->dev, "mapped %x to %p\n",
(unsigned int)map_dma, fbi->screen_base);
memset(fbi->screen_base, 0x0, size);
fbi->fix.smem_start = map_dma;
return 0;
}
static void s3c_fb_free_memory(struct s3c_fb *sfb, struct s3c_fb_win *win)
{
struct fb_info *fbi = win->fbinfo;
if (fbi->screen_base)
dma_free_writecombine(sfb->dev, PAGE_ALIGN(fbi->fix.smem_len),
fbi->screen_base, fbi->fix.smem_start);
}
static void s3c_fb_release_win(struct s3c_fb *sfb, struct s3c_fb_win *win)
{
u32 data;
if (win->fbinfo) {
if (sfb->variant.has_shadowcon) {
data = readl(sfb->regs + SHADOWCON);
data &= ~SHADOWCON_CHx_ENABLE(win->index);
data &= ~SHADOWCON_CHx_LOCAL_ENABLE(win->index);
writel(data, sfb->regs + SHADOWCON);
}
unregister_framebuffer(win->fbinfo);
if (win->fbinfo->cmap.len)
fb_dealloc_cmap(&win->fbinfo->cmap);
s3c_fb_free_memory(sfb, win);
framebuffer_release(win->fbinfo);
}
}
static int __devinit s3c_fb_probe_win(struct s3c_fb *sfb, unsigned int win_no,
struct s3c_fb_win_variant *variant,
struct s3c_fb_win **res)
{
struct fb_var_screeninfo *var;
struct fb_videomode initmode;
struct s3c_fb_pd_win *windata;
struct s3c_fb_win *win;
struct fb_info *fbinfo;
int palette_size;
int ret;
dev_dbg(sfb->dev, "probing window %d, variant %p\n", win_no, variant);
init_waitqueue_head(&sfb->vsync_info.wait);
palette_size = variant->palette_sz * 4;
fbinfo = framebuffer_alloc(sizeof(struct s3c_fb_win) +
palette_size * sizeof(u32), sfb->dev);
if (!fbinfo) {
dev_err(sfb->dev, "failed to allocate framebuffer\n");
return -ENOENT;
}
windata = sfb->pdata->win[win_no];
initmode = *sfb->pdata->vtiming;
WARN_ON(windata->max_bpp == 0);
WARN_ON(windata->xres == 0);
WARN_ON(windata->yres == 0);
win = fbinfo->par;
*res = win;
var = &fbinfo->var;
win->variant = *variant;
win->fbinfo = fbinfo;
win->parent = sfb;
win->windata = windata;
win->index = win_no;
win->palette_buffer = (u32 *)(win + 1);
ret = s3c_fb_alloc_memory(sfb, win);
if (ret) {
dev_err(sfb->dev, "failed to allocate display memory\n");
return ret;
}
if (win->variant.palette_16bpp) {
win->palette.r.offset = 11;
win->palette.r.length = 5;
win->palette.g.offset = 5;
win->palette.g.length = 6;
win->palette.b.offset = 0;
win->palette.b.length = 5;
} else {
win->palette.r.offset = 16;
win->palette.r.length = 8;
win->palette.g.offset = 8;
win->palette.g.length = 8;
win->palette.b.offset = 0;
win->palette.b.length = 8;
}
initmode.xres = windata->xres;
initmode.yres = windata->yres;
fb_videomode_to_var(&fbinfo->var, &initmode);
fbinfo->fix.type = FB_TYPE_PACKED_PIXELS;
fbinfo->fix.accel = FB_ACCEL_NONE;
fbinfo->var.activate = FB_ACTIVATE_NOW;
fbinfo->var.vmode = FB_VMODE_NONINTERLACED;
fbinfo->var.bits_per_pixel = windata->default_bpp;
fbinfo->fbops = &s3c_fb_ops;
fbinfo->flags = FBINFO_FLAG_DEFAULT;
fbinfo->pseudo_palette = &win->pseudo_palette;
ret = s3c_fb_check_var(&fbinfo->var, fbinfo);
if (ret < 0) {
dev_err(sfb->dev, "check_var failed on initial video params\n");
return ret;
}
ret = fb_alloc_cmap(&fbinfo->cmap, win->variant.palette_sz, 1);
if (ret == 0)
fb_set_cmap(&fbinfo->cmap, fbinfo);
else
dev_err(sfb->dev, "failed to allocate fb cmap\n");
s3c_fb_set_par(fbinfo);
dev_dbg(sfb->dev, "about to register framebuffer\n");
ret = register_framebuffer(fbinfo);
if (ret < 0) {
dev_err(sfb->dev, "failed to register framebuffer\n");
return ret;
}
dev_info(sfb->dev, "window %d: fb %s\n", win_no, fbinfo->fix.id);
return 0;
}
static void s3c_fb_set_rgb_timing(struct s3c_fb *sfb)
{
struct fb_videomode *vmode = sfb->pdata->vtiming;
void __iomem *regs = sfb->regs;
int clkdiv;
u32 data;
if (!vmode->pixclock)
s3c_fb_missing_pixclock(vmode);
clkdiv = s3c_fb_calc_pixclk(sfb, vmode->pixclock);
data = sfb->pdata->vidcon0;
data &= ~(VIDCON0_CLKVAL_F_MASK | VIDCON0_CLKDIR);
if (clkdiv > 1)
data |= VIDCON0_CLKVAL_F(clkdiv-1) | VIDCON0_CLKDIR;
else
data &= ~VIDCON0_CLKDIR;
if (sfb->variant.is_2443)
data |= (1 << 5);
writel(data, regs + VIDCON0);
data = VIDTCON0_VBPD(vmode->upper_margin - 1) |
VIDTCON0_VFPD(vmode->lower_margin - 1) |
VIDTCON0_VSPW(vmode->vsync_len - 1);
writel(data, regs + sfb->variant.vidtcon);
data = VIDTCON1_HBPD(vmode->left_margin - 1) |
VIDTCON1_HFPD(vmode->right_margin - 1) |
VIDTCON1_HSPW(vmode->hsync_len - 1);
writel(data, regs + sfb->variant.vidtcon + 4);
data = VIDTCON2_LINEVAL(vmode->yres - 1) |
VIDTCON2_HOZVAL(vmode->xres - 1) |
VIDTCON2_LINEVAL_E(vmode->yres - 1) |
VIDTCON2_HOZVAL_E(vmode->xres - 1);
writel(data, regs + sfb->variant.vidtcon + 8);
}
static void s3c_fb_clear_win(struct s3c_fb *sfb, int win)
{
void __iomem *regs = sfb->regs;
u32 reg;
writel(0, regs + sfb->variant.wincon + (win * 4));
writel(0, regs + VIDOSD_A(win, sfb->variant));
writel(0, regs + VIDOSD_B(win, sfb->variant));
writel(0, regs + VIDOSD_C(win, sfb->variant));
if (sfb->variant.has_shadowcon) {
reg = readl(sfb->regs + SHADOWCON);
reg &= ~(SHADOWCON_WINx_PROTECT(win) |
SHADOWCON_CHx_ENABLE(win) |
SHADOWCON_CHx_LOCAL_ENABLE(win));
writel(reg, sfb->regs + SHADOWCON);
}
}
static int __devinit s3c_fb_probe(struct platform_device *pdev)
{
const struct platform_device_id *platid;
struct s3c_fb_driverdata *fbdrv;
struct device *dev = &pdev->dev;
struct s3c_fb_platdata *pd;
struct s3c_fb *sfb;
struct resource *res;
int win;
int ret = 0;
u32 reg;
platid = platform_get_device_id(pdev);
fbdrv = (struct s3c_fb_driverdata *)platid->driver_data;
if (fbdrv->variant.nr_windows > S3C_FB_MAX_WIN) {
dev_err(dev, "too many windows, cannot attach\n");
return -EINVAL;
}
pd = pdev->dev.platform_data;
if (!pd) {
dev_err(dev, "no platform data specified\n");
return -EINVAL;
}
sfb = devm_kzalloc(dev, sizeof(struct s3c_fb), GFP_KERNEL);
if (!sfb) {
dev_err(dev, "no memory for framebuffers\n");
return -ENOMEM;
}
dev_dbg(dev, "allocate new framebuffer %p\n", sfb);
sfb->dev = dev;
sfb->pdata = pd;
sfb->variant = fbdrv->variant;
spin_lock_init(&sfb->slock);
sfb->bus_clk = clk_get(dev, "lcd");
if (IS_ERR(sfb->bus_clk)) {
dev_err(dev, "failed to get bus clock\n");
ret = PTR_ERR(sfb->bus_clk);
goto err_sfb;
}
clk_enable(sfb->bus_clk);
if (!sfb->variant.has_clksel) {
sfb->lcd_clk = clk_get(dev, "sclk_fimd");
if (IS_ERR(sfb->lcd_clk)) {
dev_err(dev, "failed to get lcd clock\n");
ret = PTR_ERR(sfb->lcd_clk);
goto err_bus_clk;
}
clk_enable(sfb->lcd_clk);
}
pm_runtime_enable(sfb->dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "failed to find registers\n");
ret = -ENOENT;
goto err_lcd_clk;
}
sfb->regs = devm_request_and_ioremap(dev, res);
if (!sfb->regs) {
dev_err(dev, "failed to map registers\n");
ret = -ENXIO;
goto err_lcd_clk;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "failed to acquire irq resource\n");
ret = -ENOENT;
goto err_lcd_clk;
}
sfb->irq_no = res->start;
ret = devm_request_irq(dev, sfb->irq_no, s3c_fb_irq,
0, "s3c_fb", sfb);
if (ret) {
dev_err(dev, "irq request failed\n");
goto err_lcd_clk;
}
dev_dbg(dev, "got resources (regs %p), probing windows\n", sfb->regs);
platform_set_drvdata(pdev, sfb);
pm_runtime_get_sync(sfb->dev);
pd->setup_gpio();
writel(pd->vidcon1, sfb->regs + VIDCON1);
if (sfb->variant.has_fixvclk) {
reg = readl(sfb->regs + VIDCON1);
reg &= ~VIDCON1_VCLK_MASK;
reg |= VIDCON1_VCLK_RUN;
writel(reg, sfb->regs + VIDCON1);
}
for (win = 0; win < fbdrv->variant.nr_windows; win++)
s3c_fb_clear_win(sfb, win);
for (win = 0; win < (fbdrv->variant.nr_windows - 1); win++) {
void __iomem *regs = sfb->regs + sfb->variant.keycon;
regs += (win * 8);
writel(0xffffff, regs + WKEYCON0);
writel(0xffffff, regs + WKEYCON1);
}
s3c_fb_set_rgb_timing(sfb);
for (win = 0; win < fbdrv->variant.nr_windows; win++) {
if (!pd->win[win])
continue;
ret = s3c_fb_probe_win(sfb, win, fbdrv->win[win],
&sfb->windows[win]);
if (ret < 0) {
dev_err(dev, "failed to create window %d\n", win);
for (; win >= 0; win--)
s3c_fb_release_win(sfb, sfb->windows[win]);
goto err_pm_runtime;
}
}
platform_set_drvdata(pdev, sfb);
pm_runtime_put_sync(sfb->dev);
return 0;
err_pm_runtime:
pm_runtime_put_sync(sfb->dev);
err_lcd_clk:
pm_runtime_disable(sfb->dev);
if (!sfb->variant.has_clksel) {
clk_disable(sfb->lcd_clk);
clk_put(sfb->lcd_clk);
}
err_bus_clk:
clk_disable(sfb->bus_clk);
clk_put(sfb->bus_clk);
err_sfb:
return ret;
}
static int __devexit s3c_fb_remove(struct platform_device *pdev)
{
struct s3c_fb *sfb = platform_get_drvdata(pdev);
int win;
pm_runtime_get_sync(sfb->dev);
for (win = 0; win < S3C_FB_MAX_WIN; win++)
if (sfb->windows[win])
s3c_fb_release_win(sfb, sfb->windows[win]);
if (!sfb->variant.has_clksel) {
clk_disable(sfb->lcd_clk);
clk_put(sfb->lcd_clk);
}
clk_disable(sfb->bus_clk);
clk_put(sfb->bus_clk);
pm_runtime_put_sync(sfb->dev);
pm_runtime_disable(sfb->dev);
return 0;
}
static int s3c_fb_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct s3c_fb *sfb = platform_get_drvdata(pdev);
struct s3c_fb_win *win;
int win_no;
pm_runtime_get_sync(sfb->dev);
for (win_no = S3C_FB_MAX_WIN - 1; win_no >= 0; win_no--) {
win = sfb->windows[win_no];
if (!win)
continue;
s3c_fb_blank(FB_BLANK_POWERDOWN, win->fbinfo);
}
if (!sfb->variant.has_clksel)
clk_disable(sfb->lcd_clk);
clk_disable(sfb->bus_clk);
pm_runtime_put_sync(sfb->dev);
return 0;
}
static int s3c_fb_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct s3c_fb *sfb = platform_get_drvdata(pdev);
struct s3c_fb_platdata *pd = sfb->pdata;
struct s3c_fb_win *win;
int win_no;
u32 reg;
pm_runtime_get_sync(sfb->dev);
clk_enable(sfb->bus_clk);
if (!sfb->variant.has_clksel)
clk_enable(sfb->lcd_clk);
pd->setup_gpio();
writel(pd->vidcon1, sfb->regs + VIDCON1);
if (sfb->variant.has_fixvclk) {
reg = readl(sfb->regs + VIDCON1);
reg &= ~VIDCON1_VCLK_MASK;
reg |= VIDCON1_VCLK_RUN;
writel(reg, sfb->regs + VIDCON1);
}
for (win_no = 0; win_no < sfb->variant.nr_windows; win_no++)
s3c_fb_clear_win(sfb, win_no);
for (win_no = 0; win_no < sfb->variant.nr_windows - 1; win_no++) {
void __iomem *regs = sfb->regs + sfb->variant.keycon;
win = sfb->windows[win_no];
if (!win)
continue;
shadow_protect_win(win, 1);
regs += (win_no * 8);
writel(0xffffff, regs + WKEYCON0);
writel(0xffffff, regs + WKEYCON1);
shadow_protect_win(win, 0);
}
s3c_fb_set_rgb_timing(sfb);
for (win_no = 0; win_no < S3C_FB_MAX_WIN; win_no++) {
win = sfb->windows[win_no];
if (!win)
continue;
dev_dbg(&pdev->dev, "resuming window %d\n", win_no);
s3c_fb_set_par(win->fbinfo);
}
pm_runtime_put_sync(sfb->dev);
return 0;
}
static int s3c_fb_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct s3c_fb *sfb = platform_get_drvdata(pdev);
if (!sfb->variant.has_clksel)
clk_disable(sfb->lcd_clk);
clk_disable(sfb->bus_clk);
return 0;
}
static int s3c_fb_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct s3c_fb *sfb = platform_get_drvdata(pdev);
struct s3c_fb_platdata *pd = sfb->pdata;
clk_enable(sfb->bus_clk);
if (!sfb->variant.has_clksel)
clk_enable(sfb->lcd_clk);
pd->setup_gpio();
writel(pd->vidcon1, sfb->regs + VIDCON1);
return 0;
}
