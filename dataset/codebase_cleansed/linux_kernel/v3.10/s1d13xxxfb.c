static inline u8
s1d13xxxfb_readreg(struct s1d13xxxfb_par *par, u16 regno)
{
#if defined(CONFIG_PLAT_M32700UT) || defined(CONFIG_PLAT_OPSPUT) || defined(CONFIG_PLAT_MAPPI3)
regno=((regno & 1) ? (regno & ~1L) : (regno + 1));
#endif
return readb(par->regs + regno);
}
static inline void
s1d13xxxfb_writereg(struct s1d13xxxfb_par *par, u16 regno, u8 value)
{
#if defined(CONFIG_PLAT_M32700UT) || defined(CONFIG_PLAT_OPSPUT) || defined(CONFIG_PLAT_MAPPI3)
regno=((regno & 1) ? (regno & ~1L) : (regno + 1));
#endif
writeb(value, par->regs + regno);
}
static inline void
s1d13xxxfb_runinit(struct s1d13xxxfb_par *par,
const struct s1d13xxxfb_regval *initregs,
const unsigned int size)
{
int i;
for (i = 0; i < size; i++) {
if ((initregs[i].addr == S1DREG_DELAYOFF) ||
(initregs[i].addr == S1DREG_DELAYON))
mdelay((int)initregs[i].value);
else {
s1d13xxxfb_writereg(par, initregs[i].addr, initregs[i].value);
}
}
mdelay(1);
}
static inline void
lcd_enable(struct s1d13xxxfb_par *par, int enable)
{
u8 mode = s1d13xxxfb_readreg(par, S1DREG_COM_DISP_MODE);
if (enable)
mode |= 0x01;
else
mode &= ~0x01;
s1d13xxxfb_writereg(par, S1DREG_COM_DISP_MODE, mode);
}
static inline void
crt_enable(struct s1d13xxxfb_par *par, int enable)
{
u8 mode = s1d13xxxfb_readreg(par, S1DREG_COM_DISP_MODE);
if (enable)
mode |= 0x02;
else
mode &= ~0x02;
s1d13xxxfb_writereg(par, S1DREG_COM_DISP_MODE, mode);
}
static inline void
s1d13xxxfb_setup_pseudocolour(struct fb_info *info)
{
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->var.red.length = 4;
info->var.green.length = 4;
info->var.blue.length = 4;
}
static inline void
s1d13xxxfb_setup_truecolour(struct fb_info *info)
{
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->var.bits_per_pixel = 16;
info->var.red.length = 5;
info->var.red.offset = 11;
info->var.green.length = 6;
info->var.green.offset = 5;
info->var.blue.length = 5;
info->var.blue.offset = 0;
}
static int
s1d13xxxfb_set_par(struct fb_info *info)
{
struct s1d13xxxfb_par *s1dfb = info->par;
unsigned int val;
dbg("s1d13xxxfb_set_par: bpp=%d\n", info->var.bits_per_pixel);
if ((s1dfb->display & 0x01))
val = s1d13xxxfb_readreg(s1dfb, S1DREG_LCD_DISP_MODE);
else
val = s1d13xxxfb_readreg(s1dfb, S1DREG_CRT_DISP_MODE);
val &= ~0x07;
switch (info->var.bits_per_pixel) {
case 4:
dbg("pseudo colour 4\n");
s1d13xxxfb_setup_pseudocolour(info);
val |= 2;
break;
case 8:
dbg("pseudo colour 8\n");
s1d13xxxfb_setup_pseudocolour(info);
val |= 3;
break;
case 16:
dbg("true colour\n");
s1d13xxxfb_setup_truecolour(info);
val |= 5;
break;
default:
dbg("bpp not supported!\n");
return -EINVAL;
}
dbg("writing %02x to display mode register\n", val);
if ((s1dfb->display & 0x01))
s1d13xxxfb_writereg(s1dfb, S1DREG_LCD_DISP_MODE, val);
else
s1d13xxxfb_writereg(s1dfb, S1DREG_CRT_DISP_MODE, val);
info->fix.line_length = info->var.xres * info->var.bits_per_pixel;
info->fix.line_length /= 8;
dbg("setting line_length to %d\n", info->fix.line_length);
dbg("done setup\n");
return 0;
}
static int
s1d13xxxfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
struct s1d13xxxfb_par *s1dfb = info->par;
unsigned int pseudo_val;
if (regno >= S1D_PALETTE_SIZE)
return -EINVAL;
dbg("s1d13xxxfb_setcolreg: %d: rgb=%d,%d,%d, tr=%d\n",
regno, red, green, blue, transp);
if (info->var.grayscale)
red = green = blue = (19595*red + 38470*green + 7471*blue) >> 16;
switch (info->fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno >= 16)
return -EINVAL;
pseudo_val = (red >> 11) << info->var.red.offset;
pseudo_val |= (green >> 10) << info->var.green.offset;
pseudo_val |= (blue >> 11) << info->var.blue.offset;
dbg("s1d13xxxfb_setcolreg: pseudo %d, val %08x\n",
regno, pseudo_val);
#if defined(CONFIG_PLAT_MAPPI)
((u32 *)info->pseudo_palette)[regno] = cpu_to_le16(pseudo_val);
#else
((u32 *)info->pseudo_palette)[regno] = pseudo_val;
#endif
break;
case FB_VISUAL_PSEUDOCOLOR:
s1d13xxxfb_writereg(s1dfb, S1DREG_LKUP_ADDR, regno);
s1d13xxxfb_writereg(s1dfb, S1DREG_LKUP_DATA, red);
s1d13xxxfb_writereg(s1dfb, S1DREG_LKUP_DATA, green);
s1d13xxxfb_writereg(s1dfb, S1DREG_LKUP_DATA, blue);
break;
default:
return -ENOSYS;
}
dbg("s1d13xxxfb_setcolreg: done\n");
return 0;
}
static int
s1d13xxxfb_blank(int blank_mode, struct fb_info *info)
{
struct s1d13xxxfb_par *par = info->par;
dbg("s1d13xxxfb_blank: blank=%d, info=%p\n", blank_mode, info);
switch (blank_mode) {
case FB_BLANK_UNBLANK:
case FB_BLANK_NORMAL:
if ((par->display & 0x01) != 0)
lcd_enable(par, 1);
if ((par->display & 0x02) != 0)
crt_enable(par, 1);
break;
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
break;
case FB_BLANK_POWERDOWN:
lcd_enable(par, 0);
crt_enable(par, 0);
break;
default:
return -EINVAL;
}
return ((blank_mode == FB_BLANK_NORMAL) ? 1 : 0);
}
static int
s1d13xxxfb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct s1d13xxxfb_par *par = info->par;
u32 start;
if (var->xoffset != 0)
return -EINVAL;
if (var->yoffset + info->var.yres > info->var.yres_virtual)
return -EINVAL;
start = (info->fix.line_length >> 1) * var->yoffset;
if ((par->display & 0x01)) {
s1d13xxxfb_writereg(par, S1DREG_LCD_DISP_START0, (start & 0xff));
s1d13xxxfb_writereg(par, S1DREG_LCD_DISP_START1, ((start >> 8) & 0xff));
s1d13xxxfb_writereg(par, S1DREG_LCD_DISP_START2, ((start >> 16) & 0x0f));
} else {
s1d13xxxfb_writereg(par, S1DREG_CRT_DISP_START0, (start & 0xff));
s1d13xxxfb_writereg(par, S1DREG_CRT_DISP_START1, ((start >> 8) & 0xff));
s1d13xxxfb_writereg(par, S1DREG_CRT_DISP_START2, ((start >> 16) & 0x0f));
}
return 0;
}
static u8
bltbit_wait_bitclear(struct fb_info *info, u8 bit, int timeout)
{
while (s1d13xxxfb_readreg(info->par, S1DREG_BBLT_CTL0) & bit) {
udelay(10);
if (!--timeout) {
dbg_blit("wait_bitclear timeout\n");
break;
}
}
return timeout;
}
static void
s1d13xxxfb_bitblt_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
u32 dst, src;
u32 stride;
u16 reverse = 0;
u16 sx = area->sx, sy = area->sy;
u16 dx = area->dx, dy = area->dy;
u16 width = area->width, height = area->height;
u16 bpp;
spin_lock(&s1d13xxxfb_bitblt_lock);
bpp = (info->var.bits_per_pixel >> 3);
stride = bpp * info->var.xres;
if ((dy > sy) || ((dy == sy) && (dx >= sx))) {
dst = (((dy + height - 1) * stride) + (bpp * (dx + width - 1)));
src = (((sy + height - 1) * stride) + (bpp * (sx + width - 1)));
reverse = 1;
} else {
dst = (dy * stride) + (bpp * dx);
src = (sy * stride) + (bpp * sx);
}
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_SRC_START0, (src & 0xff));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_SRC_START1, (src >> 8) & 0x00ff);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_SRC_START2, (src >> 16) & 0x00ff);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_DST_START0, (dst & 0xff));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_DST_START1, (dst >> 8) & 0x00ff);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_DST_START2, (dst >> 16) & 0x00ff);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_WIDTH0, (width & 0xff) - 1);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_WIDTH1, (width >> 8));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_HEIGHT0, (height & 0xff) - 1);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_HEIGHT1, (height >> 8));
if (reverse == 1) {
dbg_blit("(copyarea) negative rop\n");
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_OP, 0x03);
} else {
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_OP, 0x02);
dbg_blit("(copyarea) positive rop\n");
}
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_CTL0, 0x0);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_CTL1, (bpp >> 1));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_MEM_OFF0, (stride >> 1) & 0xff);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_MEM_OFF1, (stride >> 9));
dbg_blit("(copyarea) dx=%d, dy=%d\n", dx, dy);
dbg_blit("(copyarea) sx=%d, sy=%d\n", sx, sy);
dbg_blit("(copyarea) width=%d, height=%d\n", width - 1, height - 1);
dbg_blit("(copyarea) stride=%d\n", stride);
dbg_blit("(copyarea) bpp=%d=0x0%d, mem_offset1=%d, mem_offset2=%d\n", bpp, (bpp >> 1),
(stride >> 1) & 0xff, stride >> 9);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_CC_EXP, 0x0c);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_CTL0, 0x80);
bltbit_wait_bitclear(info, 0x80, 8000);
spin_unlock(&s1d13xxxfb_bitblt_lock);
}
static void
s1d13xxxfb_bitblt_solidfill(struct fb_info *info, const struct fb_fillrect *rect)
{
u32 screen_stride, dest;
u32 fg;
u16 bpp = (info->var.bits_per_pixel >> 3);
spin_lock(&s1d13xxxfb_bitblt_lock);
screen_stride = (bpp * info->var.xres);
dest = ((rect->dy * screen_stride) + (bpp * rect->dx));
dbg_blit("(solidfill) dx=%d, dy=%d, stride=%d, dest=%d\n"
"(solidfill) : rect_width=%d, rect_height=%d\n",
rect->dx, rect->dy, screen_stride, dest,
rect->width - 1, rect->height - 1);
dbg_blit("(solidfill) : xres=%d, yres=%d, bpp=%d\n",
info->var.xres, info->var.yres,
info->var.bits_per_pixel);
dbg_blit("(solidfill) : rop=%d\n", rect->rop);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_DST_START0, (dest & 0x00ff));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_DST_START1, ((dest >> 8) & 0x00ff));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_DST_START2, ((dest >> 16) & 0x00ff));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_WIDTH0, ((rect->width) & 0x00ff) - 1);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_WIDTH1, (rect->width >> 8));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_HEIGHT0, ((rect->height) & 0x00ff) - 1);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_HEIGHT1, (rect->height >> 8));
if (info->fix.visual == FB_VISUAL_TRUECOLOR ||
info->fix.visual == FB_VISUAL_DIRECTCOLOR) {
fg = ((u32 *)info->pseudo_palette)[rect->color];
dbg_blit("(solidfill) truecolor/directcolor\n");
dbg_blit("(solidfill) pseudo_palette[%d] = %d\n", rect->color, fg);
} else {
fg = rect->color;
dbg_blit("(solidfill) color = %d\n", rect->color);
}
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_FGC0, (fg & 0xff));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_FGC1, (fg >> 8) & 0xff);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_CTL0, 0x0);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_OP, BBLT_SOLID_FILL);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_CTL1, (info->var.bits_per_pixel >> 4));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_MEM_OFF0, (screen_stride >> 1) & 0x00ff);
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_MEM_OFF1, (screen_stride >> 9));
s1d13xxxfb_writereg(info->par, S1DREG_BBLT_CTL0, 0x80);
bltbit_wait_bitclear(info, 0x80, 8000);
spin_unlock(&s1d13xxxfb_bitblt_lock);
}
static void s1d13xxxfb_fetch_hw_state(struct fb_info *info)
{
struct fb_var_screeninfo *var = &info->var;
struct fb_fix_screeninfo *fix = &info->fix;
struct s1d13xxxfb_par *par = info->par;
u8 panel, display;
u16 offset;
u32 xres, yres;
u32 xres_virtual, yres_virtual;
int bpp, lcd_bpp;
int is_color, is_dual, is_tft;
int lcd_enabled, crt_enabled;
fix->type = FB_TYPE_PACKED_PIXELS;
par->display = s1d13xxxfb_readreg(par, S1DREG_COM_DISP_MODE);
crt_enabled = (par->display & 0x02) != 0;
lcd_enabled = (par->display & 0x01) != 0;
if (lcd_enabled && crt_enabled)
printk(KERN_WARNING PFX "Warning: LCD and CRT detected, using LCD\n");
if (lcd_enabled)
display = s1d13xxxfb_readreg(par, S1DREG_LCD_DISP_MODE);
else
display = s1d13xxxfb_readreg(par, S1DREG_CRT_DISP_MODE);
bpp = display & 0x07;
switch (bpp) {
case 2:
case 3:
var->bits_per_pixel = 8;
var->red.offset = var->green.offset = var->blue.offset = 0;
var->red.length = var->green.length = var->blue.length = 8;
break;
case 5:
s1d13xxxfb_setup_truecolour(info);
break;
default:
dbg("bpp: %i\n", bpp);
}
fb_alloc_cmap(&info->cmap, 256, 0);
panel = s1d13xxxfb_readreg(par, S1DREG_PANEL_TYPE);
is_color = (panel & 0x04) != 0;
is_dual = (panel & 0x02) != 0;
is_tft = (panel & 0x01) != 0;
lcd_bpp = s1d13xxxfb_width_tab[is_tft][(panel >> 4) & 3];
if (lcd_enabled) {
xres = (s1d13xxxfb_readreg(par, S1DREG_LCD_DISP_HWIDTH) + 1) * 8;
yres = (s1d13xxxfb_readreg(par, S1DREG_LCD_DISP_VHEIGHT0) +
((s1d13xxxfb_readreg(par, S1DREG_LCD_DISP_VHEIGHT1) & 0x03) << 8) + 1);
offset = (s1d13xxxfb_readreg(par, S1DREG_LCD_MEM_OFF0) +
((s1d13xxxfb_readreg(par, S1DREG_LCD_MEM_OFF1) & 0x7) << 8));
} else {
xres = (s1d13xxxfb_readreg(par, S1DREG_CRT_DISP_HWIDTH) + 1) * 8;
yres = (s1d13xxxfb_readreg(par, S1DREG_CRT_DISP_VHEIGHT0) +
((s1d13xxxfb_readreg(par, S1DREG_CRT_DISP_VHEIGHT1) & 0x03) << 8) + 1);
offset = (s1d13xxxfb_readreg(par, S1DREG_CRT_MEM_OFF0) +
((s1d13xxxfb_readreg(par, S1DREG_CRT_MEM_OFF1) & 0x7) << 8));
}
xres_virtual = offset * 16 / var->bits_per_pixel;
yres_virtual = fix->smem_len / (offset * 2);
var->xres = xres;
var->yres = yres;
var->xres_virtual = xres_virtual;
var->yres_virtual = yres_virtual;
var->xoffset = var->yoffset = 0;
fix->line_length = offset * 2;
var->grayscale = !is_color;
var->activate = FB_ACTIVATE_NOW;
dbg(PFX "bpp=%d, lcd_bpp=%d, "
"crt_enabled=%d, lcd_enabled=%d\n",
var->bits_per_pixel, lcd_bpp, crt_enabled, lcd_enabled);
dbg(PFX "xres=%d, yres=%d, vxres=%d, vyres=%d "
"is_color=%d, is_dual=%d, is_tft=%d\n",
xres, yres, xres_virtual, yres_virtual, is_color, is_dual, is_tft);
}
static int
s1d13xxxfb_remove(struct platform_device *pdev)
{
struct fb_info *info = platform_get_drvdata(pdev);
struct s1d13xxxfb_par *par = NULL;
if (info) {
par = info->par;
if (par && par->regs) {
s1d13xxxfb_writereg(par, S1DREG_COM_DISP_MODE, 0x00);
s1d13xxxfb_writereg(par, S1DREG_PS_CNF, 0x11);
iounmap(par->regs);
}
fb_dealloc_cmap(&info->cmap);
if (info->screen_base)
iounmap(info->screen_base);
framebuffer_release(info);
}
release_mem_region(pdev->resource[0].start,
pdev->resource[0].end - pdev->resource[0].start +1);
release_mem_region(pdev->resource[1].start,
pdev->resource[1].end - pdev->resource[1].start +1);
return 0;
}
static int s1d13xxxfb_probe(struct platform_device *pdev)
{
struct s1d13xxxfb_par *default_par;
struct fb_info *info;
struct s1d13xxxfb_pdata *pdata = NULL;
int ret = 0;
int i;
u8 revision, prod_id;
dbg("probe called: device is %p\n", pdev);
printk(KERN_INFO "Epson S1D13XXX FB Driver\n");
if (pdev->dev.platform_data)
pdata = pdev->dev.platform_data;
if (pdata && pdata->platform_init_video)
pdata->platform_init_video();
if (pdev->num_resources != 2) {
dev_err(&pdev->dev, "invalid num_resources: %i\n",
pdev->num_resources);
ret = -ENODEV;
goto bail;
}
if (pdev->resource[0].flags != IORESOURCE_MEM
|| pdev->resource[1].flags != IORESOURCE_MEM) {
dev_err(&pdev->dev, "invalid resource type\n");
ret = -ENODEV;
goto bail;
}
if (!request_mem_region(pdev->resource[0].start,
pdev->resource[0].end - pdev->resource[0].start +1, "s1d13xxxfb mem")) {
dev_dbg(&pdev->dev, "request_mem_region failed\n");
ret = -EBUSY;
goto bail;
}
if (!request_mem_region(pdev->resource[1].start,
pdev->resource[1].end - pdev->resource[1].start +1, "s1d13xxxfb regs")) {
dev_dbg(&pdev->dev, "request_mem_region failed\n");
ret = -EBUSY;
goto bail;
}
info = framebuffer_alloc(sizeof(struct s1d13xxxfb_par) + sizeof(u32) * 256, &pdev->dev);
if (!info) {
ret = -ENOMEM;
goto bail;
}
platform_set_drvdata(pdev, info);
default_par = info->par;
default_par->regs = ioremap_nocache(pdev->resource[1].start,
pdev->resource[1].end - pdev->resource[1].start +1);
if (!default_par->regs) {
printk(KERN_ERR PFX "unable to map registers\n");
ret = -ENOMEM;
goto bail;
}
info->pseudo_palette = default_par->pseudo_palette;
info->screen_base = ioremap_nocache(pdev->resource[0].start,
pdev->resource[0].end - pdev->resource[0].start +1);
if (!info->screen_base) {
printk(KERN_ERR PFX "unable to map framebuffer\n");
ret = -ENOMEM;
goto bail;
}
prod_id = s1d13xxxfb_readreg(default_par, S1DREG_REV_CODE) >> 2;
revision = s1d13xxxfb_readreg(default_par, S1DREG_REV_CODE) & 0x3;
ret = -ENODEV;
for (i = 0; i < ARRAY_SIZE(s1d13xxxfb_prod_ids); i++) {
if (prod_id == s1d13xxxfb_prod_ids[i]) {
default_par->prod_id = prod_id;
default_par->revision = revision;
ret = 0;
break;
}
}
if (!ret) {
printk(KERN_INFO PFX "chip production id %i = %s\n",
prod_id, s1d13xxxfb_prod_names[i]);
printk(KERN_INFO PFX "chip revision %i\n", revision);
} else {
printk(KERN_INFO PFX
"unknown chip production id %i, revision %i\n",
prod_id, revision);
printk(KERN_INFO PFX "please contact maintainer\n");
goto bail;
}
info->fix = s1d13xxxfb_fix;
info->fix.mmio_start = pdev->resource[1].start;
info->fix.mmio_len = pdev->resource[1].end - pdev->resource[1].start + 1;
info->fix.smem_start = pdev->resource[0].start;
info->fix.smem_len = pdev->resource[0].end - pdev->resource[0].start + 1;
printk(KERN_INFO PFX "regs mapped at 0x%p, fb %d KiB mapped at 0x%p\n",
default_par->regs, info->fix.smem_len / 1024, info->screen_base);
info->par = default_par;
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
info->fbops = &s1d13xxxfb_fbops;
switch(prod_id) {
case S1D13506_PROD_ID:
s1d13xxxfb_fbops.fb_fillrect = s1d13xxxfb_bitblt_solidfill;
s1d13xxxfb_fbops.fb_copyarea = s1d13xxxfb_bitblt_copyarea;
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN |
FBINFO_HWACCEL_FILLRECT | FBINFO_HWACCEL_COPYAREA;
break;
default:
break;
}
if (pdata && pdata->initregs)
s1d13xxxfb_runinit(info->par, pdata->initregs, pdata->initregssize);
s1d13xxxfb_fetch_hw_state(info);
if (register_framebuffer(info) < 0) {
ret = -EINVAL;
goto bail;
}
printk(KERN_INFO "fb%d: %s frame buffer device\n",
info->node, info->fix.id);
return 0;
bail:
s1d13xxxfb_remove(pdev);
return ret;
}
static int s1d13xxxfb_suspend(struct platform_device *dev, pm_message_t state)
{
struct fb_info *info = platform_get_drvdata(dev);
struct s1d13xxxfb_par *s1dfb = info->par;
struct s1d13xxxfb_pdata *pdata = NULL;
lcd_enable(s1dfb, 0);
crt_enable(s1dfb, 0);
if (dev->dev.platform_data)
pdata = dev->dev.platform_data;
#if 0
if (!s1dfb->disp_save)
s1dfb->disp_save = kmalloc(info->fix.smem_len, GFP_KERNEL);
if (!s1dfb->disp_save) {
printk(KERN_ERR PFX "no memory to save screen");
return -ENOMEM;
}
memcpy_fromio(s1dfb->disp_save, info->screen_base, info->fix.smem_len);
#else
s1dfb->disp_save = NULL;
#endif
if (!s1dfb->regs_save)
s1dfb->regs_save = kmalloc(info->fix.mmio_len, GFP_KERNEL);
if (!s1dfb->regs_save) {
printk(KERN_ERR PFX "no memory to save registers");
return -ENOMEM;
}
memcpy_fromio(s1dfb->regs_save, s1dfb->regs, info->fix.mmio_len);
s1d13xxxfb_writereg(s1dfb, S1DREG_PS_CNF, 0x11);
if (pdata && pdata->platform_suspend_video)
return pdata->platform_suspend_video();
else
return 0;
}
static int s1d13xxxfb_resume(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
struct s1d13xxxfb_par *s1dfb = info->par;
struct s1d13xxxfb_pdata *pdata = NULL;
s1d13xxxfb_writereg(s1dfb, S1DREG_PS_CNF, 0x10);
while ((s1d13xxxfb_readreg(s1dfb, S1DREG_PS_STATUS) & 0x01))
udelay(10);
if (dev->dev.platform_data)
pdata = dev->dev.platform_data;
if (s1dfb->regs_save) {
memcpy_toio(s1dfb->regs, s1dfb->regs_save, info->fix.mmio_len);
kfree(s1dfb->regs_save);
}
if (s1dfb->disp_save) {
memcpy_toio(info->screen_base, s1dfb->disp_save,
info->fix.smem_len);
kfree(s1dfb->disp_save);
}
if ((s1dfb->display & 0x01) != 0)
lcd_enable(s1dfb, 1);
if ((s1dfb->display & 0x02) != 0)
crt_enable(s1dfb, 1);
if (pdata && pdata->platform_resume_video)
return pdata->platform_resume_video();
else
return 0;
}
static int __init
s1d13xxxfb_init(void)
{
#ifndef MODULE
if (fb_get_options("s1d13xxxfb", NULL))
return -ENODEV;
#endif
return platform_driver_register(&s1d13xxxfb_driver);
}
static void __exit
s1d13xxxfb_exit(void)
{
platform_driver_unregister(&s1d13xxxfb_driver);
}
