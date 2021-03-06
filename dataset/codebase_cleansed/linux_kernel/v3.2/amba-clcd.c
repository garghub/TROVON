static inline void clcdfb_sleep(unsigned int ms)
{
if (in_atomic()) {
mdelay(ms);
} else {
msleep(ms);
}
}
static inline void clcdfb_set_start(struct clcd_fb *fb)
{
unsigned long ustart = fb->fb.fix.smem_start;
unsigned long lstart;
ustart += fb->fb.var.yoffset * fb->fb.fix.line_length;
lstart = ustart + fb->fb.var.yres * fb->fb.fix.line_length / 2;
writel(ustart, fb->regs + CLCD_UBAS);
writel(lstart, fb->regs + CLCD_LBAS);
}
static void clcdfb_disable(struct clcd_fb *fb)
{
u32 val;
if (fb->board->disable)
fb->board->disable(fb);
val = readl(fb->regs + fb->off_cntl);
if (val & CNTL_LCDPWR) {
val &= ~CNTL_LCDPWR;
writel(val, fb->regs + fb->off_cntl);
clcdfb_sleep(20);
}
if (val & CNTL_LCDEN) {
val &= ~CNTL_LCDEN;
writel(val, fb->regs + fb->off_cntl);
}
if (fb->clk_enabled) {
fb->clk_enabled = false;
clk_disable(fb->clk);
}
}
static void clcdfb_enable(struct clcd_fb *fb, u32 cntl)
{
if (!fb->clk_enabled) {
fb->clk_enabled = true;
clk_enable(fb->clk);
}
cntl |= CNTL_LCDEN;
writel(cntl, fb->regs + fb->off_cntl);
clcdfb_sleep(20);
cntl |= CNTL_LCDPWR;
writel(cntl, fb->regs + fb->off_cntl);
if (fb->board->enable)
fb->board->enable(fb);
}
static int
clcdfb_set_bitfields(struct clcd_fb *fb, struct fb_var_screeninfo *var)
{
u32 caps;
int ret = 0;
if (fb->panel->caps && fb->board->caps)
caps = fb->panel->caps & fb->board->caps;
else {
caps = fb->panel->cntl & CNTL_BGR ?
CLCD_CAP_BGR : CLCD_CAP_RGB;
caps &= ~CLCD_CAP_444;
}
if (!(fb->panel->cntl & CNTL_LCDTFT))
caps &= ~CLCD_CAP_888;
memset(&var->transp, 0, sizeof(var->transp));
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
switch (var->bits_per_pixel) {
case 1:
case 2:
case 4:
case 8:
caps &= CLCD_CAP_5551;
if (!caps) {
ret = -EINVAL;
break;
}
var->red.length = var->bits_per_pixel;
var->red.offset = 0;
var->green.length = var->bits_per_pixel;
var->green.offset = 0;
var->blue.length = var->bits_per_pixel;
var->blue.offset = 0;
break;
case 16:
if (!(caps & (CLCD_CAP_444 | CLCD_CAP_5551 | CLCD_CAP_565))) {
ret = -EINVAL;
break;
}
if (var->green.length == 4 && caps & CLCD_CAP_444)
caps &= CLCD_CAP_444;
if (var->green.length == 5 && caps & CLCD_CAP_5551)
caps &= CLCD_CAP_5551;
else if (var->green.length == 6 && caps & CLCD_CAP_565)
caps &= CLCD_CAP_565;
else {
if (caps & CLCD_CAP_565) {
var->green.length = 6;
caps &= CLCD_CAP_565;
} else if (caps & CLCD_CAP_5551) {
var->green.length = 5;
caps &= CLCD_CAP_5551;
} else {
var->green.length = 4;
caps &= CLCD_CAP_444;
}
}
if (var->green.length >= 5) {
var->red.length = 5;
var->blue.length = 5;
} else {
var->red.length = 4;
var->blue.length = 4;
}
break;
case 32:
caps &= CLCD_CAP_888;
if (!caps) {
ret = -EINVAL;
break;
}
var->red.length = 8;
var->green.length = 8;
var->blue.length = 8;
break;
default:
ret = -EINVAL;
break;
}
if (ret == 0 && var->bits_per_pixel >= 16) {
bool bgr, rgb;
bgr = caps & CLCD_CAP_BGR && var->blue.offset == 0;
rgb = caps & CLCD_CAP_RGB && var->red.offset == 0;
if (!bgr && !rgb)
bgr = caps & CLCD_CAP_BGR;
if (bgr) {
var->blue.offset = 0;
var->green.offset = var->blue.offset + var->blue.length;
var->red.offset = var->green.offset + var->green.length;
} else {
var->red.offset = 0;
var->green.offset = var->red.offset + var->red.length;
var->blue.offset = var->green.offset + var->green.length;
}
}
return ret;
}
static int clcdfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
int ret = -EINVAL;
if (fb->board->check)
ret = fb->board->check(fb, var);
if (ret == 0 &&
var->xres_virtual * var->bits_per_pixel / 8 *
var->yres_virtual > fb->fb.fix.smem_len)
ret = -EINVAL;
if (ret == 0)
ret = clcdfb_set_bitfields(fb, var);
return ret;
}
static int clcdfb_set_par(struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
struct clcd_regs regs;
fb->fb.fix.line_length = fb->fb.var.xres_virtual *
fb->fb.var.bits_per_pixel / 8;
if (fb->fb.var.bits_per_pixel <= 8)
fb->fb.fix.visual = FB_VISUAL_PSEUDOCOLOR;
else
fb->fb.fix.visual = FB_VISUAL_TRUECOLOR;
fb->board->decode(fb, &regs);
clcdfb_disable(fb);
writel(regs.tim0, fb->regs + CLCD_TIM0);
writel(regs.tim1, fb->regs + CLCD_TIM1);
writel(regs.tim2, fb->regs + CLCD_TIM2);
writel(regs.tim3, fb->regs + CLCD_TIM3);
clcdfb_set_start(fb);
clk_set_rate(fb->clk, (1000000000 / regs.pixclock) * 1000);
fb->clcd_cntl = regs.cntl;
clcdfb_enable(fb, regs.cntl);
#ifdef DEBUG
printk(KERN_INFO
"CLCD: Registers set to\n"
" %08x %08x %08x %08x\n"
" %08x %08x %08x %08x\n",
readl(fb->regs + CLCD_TIM0), readl(fb->regs + CLCD_TIM1),
readl(fb->regs + CLCD_TIM2), readl(fb->regs + CLCD_TIM3),
readl(fb->regs + CLCD_UBAS), readl(fb->regs + CLCD_LBAS),
readl(fb->regs + fb->off_ienb), readl(fb->regs + fb->off_cntl));
#endif
return 0;
}
static inline u32 convert_bitfield(int val, struct fb_bitfield *bf)
{
unsigned int mask = (1 << bf->length) - 1;
return (val >> (16 - bf->length) & mask) << bf->offset;
}
static int
clcdfb_setcolreg(unsigned int regno, unsigned int red, unsigned int green,
unsigned int blue, unsigned int transp, struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
if (regno < 16)
fb->cmap[regno] = convert_bitfield(transp, &fb->fb.var.transp) |
convert_bitfield(blue, &fb->fb.var.blue) |
convert_bitfield(green, &fb->fb.var.green) |
convert_bitfield(red, &fb->fb.var.red);
if (fb->fb.fix.visual == FB_VISUAL_PSEUDOCOLOR && regno < 256) {
int hw_reg = CLCD_PALETTE + ((regno * 2) & ~3);
u32 val, mask, newval;
newval = (red >> 11) & 0x001f;
newval |= (green >> 6) & 0x03e0;
newval |= (blue >> 1) & 0x7c00;
if (fb->clcd_cntl & CNTL_BEBO)
regno ^= 1;
if (regno & 1) {
newval <<= 16;
mask = 0x0000ffff;
} else {
mask = 0xffff0000;
}
val = readl(fb->regs + hw_reg) & mask;
writel(val | newval, fb->regs + hw_reg);
}
return regno > 255;
}
static int clcdfb_blank(int blank_mode, struct fb_info *info)
{
struct clcd_fb *fb = to_clcd(info);
if (blank_mode != 0) {
clcdfb_disable(fb);
} else {
clcdfb_enable(fb, fb->clcd_cntl);
}
return 0;
}
static int clcdfb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
struct clcd_fb *fb = to_clcd(info);
unsigned long len, off = vma->vm_pgoff << PAGE_SHIFT;
int ret = -EINVAL;
len = info->fix.smem_len;
if (off <= len && vma->vm_end - vma->vm_start <= len - off &&
fb->board->mmap)
ret = fb->board->mmap(fb, vma);
return ret;
}
static int clcdfb_register(struct clcd_fb *fb)
{
int ret;
if (amba_manf(fb->dev) == 0x41 && amba_part(fb->dev) == 0x111) {
fb->off_ienb = CLCD_PL111_IENB;
fb->off_cntl = CLCD_PL111_CNTL;
} else {
#ifdef CONFIG_ARCH_VERSATILE
fb->off_ienb = CLCD_PL111_IENB;
fb->off_cntl = CLCD_PL111_CNTL;
#else
fb->off_ienb = CLCD_PL110_IENB;
fb->off_cntl = CLCD_PL110_CNTL;
#endif
}
fb->clk = clk_get(&fb->dev->dev, NULL);
if (IS_ERR(fb->clk)) {
ret = PTR_ERR(fb->clk);
goto out;
}
ret = clk_prepare(fb->clk);
if (ret)
goto free_clk;
fb->fb.device = &fb->dev->dev;
fb->fb.fix.mmio_start = fb->dev->res.start;
fb->fb.fix.mmio_len = resource_size(&fb->dev->res);
fb->regs = ioremap(fb->fb.fix.mmio_start, fb->fb.fix.mmio_len);
if (!fb->regs) {
printk(KERN_ERR "CLCD: unable to remap registers\n");
ret = -ENOMEM;
goto clk_unprep;
}
fb->fb.fbops = &clcdfb_ops;
fb->fb.flags = FBINFO_FLAG_DEFAULT;
fb->fb.pseudo_palette = fb->cmap;
strncpy(fb->fb.fix.id, clcd_name, sizeof(fb->fb.fix.id));
fb->fb.fix.type = FB_TYPE_PACKED_PIXELS;
fb->fb.fix.type_aux = 0;
fb->fb.fix.xpanstep = 0;
fb->fb.fix.ypanstep = 0;
fb->fb.fix.ywrapstep = 0;
fb->fb.fix.accel = FB_ACCEL_NONE;
fb->fb.var.xres = fb->panel->mode.xres;
fb->fb.var.yres = fb->panel->mode.yres;
fb->fb.var.xres_virtual = fb->panel->mode.xres;
fb->fb.var.yres_virtual = fb->panel->mode.yres;
fb->fb.var.bits_per_pixel = fb->panel->bpp;
fb->fb.var.grayscale = fb->panel->grayscale;
fb->fb.var.pixclock = fb->panel->mode.pixclock;
fb->fb.var.left_margin = fb->panel->mode.left_margin;
fb->fb.var.right_margin = fb->panel->mode.right_margin;
fb->fb.var.upper_margin = fb->panel->mode.upper_margin;
fb->fb.var.lower_margin = fb->panel->mode.lower_margin;
fb->fb.var.hsync_len = fb->panel->mode.hsync_len;
fb->fb.var.vsync_len = fb->panel->mode.vsync_len;
fb->fb.var.sync = fb->panel->mode.sync;
fb->fb.var.vmode = fb->panel->mode.vmode;
fb->fb.var.activate = FB_ACTIVATE_NOW;
fb->fb.var.nonstd = 0;
fb->fb.var.height = fb->panel->height;
fb->fb.var.width = fb->panel->width;
fb->fb.var.accel_flags = 0;
fb->fb.monspecs.hfmin = 0;
fb->fb.monspecs.hfmax = 100000;
fb->fb.monspecs.vfmin = 0;
fb->fb.monspecs.vfmax = 400;
fb->fb.monspecs.dclkmin = 1000000;
fb->fb.monspecs.dclkmax = 100000000;
clcdfb_set_bitfields(fb, &fb->fb.var);
ret = fb_alloc_cmap(&fb->fb.cmap, 256, 0);
if (ret)
goto unmap;
writel(0, fb->regs + fb->off_ienb);
fb_set_var(&fb->fb, &fb->fb.var);
dev_info(&fb->dev->dev, "%s hardware, %s display\n",
fb->board->name, fb->panel->mode.name);
ret = register_framebuffer(&fb->fb);
if (ret == 0)
goto out;
printk(KERN_ERR "CLCD: cannot register framebuffer (%d)\n", ret);
fb_dealloc_cmap(&fb->fb.cmap);
unmap:
iounmap(fb->regs);
clk_unprep:
clk_unprepare(fb->clk);
free_clk:
clk_put(fb->clk);
out:
return ret;
}
static int clcdfb_probe(struct amba_device *dev, const struct amba_id *id)
{
struct clcd_board *board = dev->dev.platform_data;
struct clcd_fb *fb;
int ret;
if (!board)
return -EINVAL;
ret = amba_request_regions(dev, NULL);
if (ret) {
printk(KERN_ERR "CLCD: unable to reserve regs region\n");
goto out;
}
fb = kzalloc(sizeof(struct clcd_fb), GFP_KERNEL);
if (!fb) {
printk(KERN_INFO "CLCD: could not allocate new clcd_fb struct\n");
ret = -ENOMEM;
goto free_region;
}
fb->dev = dev;
fb->board = board;
dev_info(&fb->dev->dev, "PL%03x rev%u at 0x%08llx\n",
amba_part(dev), amba_rev(dev),
(unsigned long long)dev->res.start);
ret = fb->board->setup(fb);
if (ret)
goto free_fb;
ret = clcdfb_register(fb);
if (ret == 0) {
amba_set_drvdata(dev, fb);
goto out;
}
fb->board->remove(fb);
free_fb:
kfree(fb);
free_region:
amba_release_regions(dev);
out:
return ret;
}
static int clcdfb_remove(struct amba_device *dev)
{
struct clcd_fb *fb = amba_get_drvdata(dev);
amba_set_drvdata(dev, NULL);
clcdfb_disable(fb);
unregister_framebuffer(&fb->fb);
if (fb->fb.cmap.len)
fb_dealloc_cmap(&fb->fb.cmap);
iounmap(fb->regs);
clk_unprepare(fb->clk);
clk_put(fb->clk);
fb->board->remove(fb);
kfree(fb);
amba_release_regions(dev);
return 0;
}
static int __init amba_clcdfb_init(void)
{
if (fb_get_options("ambafb", NULL))
return -ENODEV;
return amba_driver_register(&clcd_driver);
}
static void __exit amba_clcdfb_exit(void)
{
amba_driver_unregister(&clcd_driver);
}
