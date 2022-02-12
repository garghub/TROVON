static irqreturn_t tmiofb_irq(int irq, void *__info)
{
struct fb_info *info = __info;
struct tmiofb_par *par = info->par;
unsigned int bbisc = tmio_ioread16(par->lcr + LCR_BBISC);
tmio_iowrite16(bbisc, par->lcr + LCR_BBISC);
#ifdef CONFIG_FB_TMIO_ACCELL
if (unlikely(par->use_polling && irq != -1)) {
printk(KERN_INFO "tmiofb: switching to waitq\n");
par->use_polling = false;
}
if (bbisc & 1)
wake_up(&par->wait_acc);
#endif
return IRQ_HANDLED;
}
static int tmiofb_hw_stop(struct platform_device *dev)
{
struct tmio_fb_data *data = dev->dev.platform_data;
struct fb_info *info = platform_get_drvdata(dev);
struct tmiofb_par *par = info->par;
tmio_iowrite16(0, par->ccr + CCR_UGCC);
tmio_iowrite16(0, par->lcr + LCR_GM);
data->lcd_set_power(dev, 0);
tmio_iowrite16(0x0010, par->lcr + LCR_LCDCCRC);
return 0;
}
static int tmiofb_hw_init(struct platform_device *dev)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
struct fb_info *info = platform_get_drvdata(dev);
struct tmiofb_par *par = info->par;
const struct resource *nlcr = &cell->resources[0];
const struct resource *vram = &cell->resources[2];
unsigned long base;
if (nlcr == NULL || vram == NULL)
return -EINVAL;
base = nlcr->start;
tmio_iowrite16(0x003a, par->ccr + CCR_UGCC);
tmio_iowrite16(0x003a, par->ccr + CCR_GCC);
tmio_iowrite16(0x3f00, par->ccr + CCR_USC);
msleep(2);
tmio_iowrite16(0x0000, par->ccr + CCR_USC);
tmio_iowrite16(base >> 16, par->ccr + CCR_BASEH);
tmio_iowrite16(base, par->ccr + CCR_BASEL);
tmio_iowrite16(0x0002, par->ccr + CCR_CMD);
tmio_iowrite16(0x40a8, par->ccr + CCR_VRAMRTC);
tmio_iowrite16(0x0018, par->ccr + CCR_VRAMSAC);
tmio_iowrite16(0x0002, par->ccr + CCR_VRAMBC);
msleep(2);
tmio_iowrite16(0x000b, par->ccr + CCR_VRAMBC);
base = vram->start + info->screen_size;
tmio_iowrite16(base >> 16, par->lcr + LCR_CFSAH);
tmio_iowrite16(base, par->lcr + LCR_CFSAL);
tmio_iowrite16(TMIOFB_FIFO_SIZE - 1, par->lcr + LCR_CFS);
tmio_iowrite16(1, par->lcr + LCR_CFC);
tmio_iowrite16(1, par->lcr + LCR_BBIE);
tmio_iowrite16(0, par->lcr + LCR_CFWS);
return 0;
}
static void tmiofb_hw_mode(struct platform_device *dev)
{
struct tmio_fb_data *data = dev->dev.platform_data;
struct fb_info *info = platform_get_drvdata(dev);
struct fb_videomode *mode = info->mode;
struct tmiofb_par *par = info->par;
unsigned int i;
tmio_iowrite16(0, par->lcr + LCR_GM);
data->lcd_set_power(dev, 0);
tmio_iowrite16(0x0010, par->lcr + LCR_LCDCCRC);
data->lcd_mode(dev, mode);
data->lcd_set_power(dev, 1);
tmio_iowrite16(info->fix.line_length, par->lcr + LCR_VHPN);
tmio_iowrite16(0, par->lcr + LCR_GDSAH);
tmio_iowrite16(0, par->lcr + LCR_GDSAL);
tmio_iowrite16(info->fix.line_length >> 16, par->lcr + LCR_VHPCH);
tmio_iowrite16(info->fix.line_length, par->lcr + LCR_VHPCL);
tmio_iowrite16(i = 0, par->lcr + LCR_HSS);
tmio_iowrite16(i += mode->hsync_len, par->lcr + LCR_HSE);
tmio_iowrite16(i += mode->left_margin, par->lcr + LCR_HDS);
tmio_iowrite16(i += mode->xres + mode->right_margin, par->lcr + LCR_HT);
tmio_iowrite16(mode->xres, par->lcr + LCR_HNP);
tmio_iowrite16(i = 0, par->lcr + LCR_VSS);
tmio_iowrite16(i += mode->vsync_len, par->lcr + LCR_VSE);
tmio_iowrite16(i += mode->upper_margin, par->lcr + LCR_VDS);
tmio_iowrite16(i += mode->yres, par->lcr + LCR_ILN);
tmio_iowrite16(i += mode->lower_margin, par->lcr + LCR_VT);
tmio_iowrite16(3, par->lcr + LCR_MISC);
tmio_iowrite16(1, par->lcr + LCR_GM);
tmio_iowrite16(0x4007, par->lcr + LCR_LCDCC);
tmio_iowrite16(3, par->lcr + LCR_SP);
tmio_iowrite16(0x0010, par->lcr + LCR_LCDCCRC);
msleep(5);
tmio_iowrite16(0x0014, par->lcr + LCR_LCDCCRC);
msleep(5);
tmio_iowrite16(0x0015, par->lcr + LCR_LCDCCRC);
tmio_iowrite16(0xfffa, par->lcr + LCR_VCS);
}
static int __must_check
tmiofb_acc_wait(struct fb_info *info, unsigned int ccs)
{
struct tmiofb_par *par = info->par;
if (irqs_disabled() || par->use_polling) {
int i = 0;
while (tmio_ioread16(par->lcr + LCR_CCS) > ccs) {
udelay(1);
i++;
if (i > 10000) {
pr_err("tmiofb: timeout waiting for %d\n",
ccs);
return -ETIMEDOUT;
}
tmiofb_irq(-1, info);
}
} else {
if (!wait_event_interruptible_timeout(par->wait_acc,
tmio_ioread16(par->lcr + LCR_CCS) <= ccs,
1000)) {
pr_err("tmiofb: timeout waiting for %d\n", ccs);
return -ETIMEDOUT;
}
}
return 0;
}
static int
tmiofb_acc_write(struct fb_info *info, const u32 *cmd, unsigned int count)
{
struct tmiofb_par *par = info->par;
int ret;
ret = tmiofb_acc_wait(info, TMIOFB_FIFO_SIZE - count);
if (ret)
return ret;
for (; count; count--, cmd++) {
tmio_iowrite16(*cmd >> 16, par->lcr + LCR_CMDH);
tmio_iowrite16(*cmd, par->lcr + LCR_CMDL);
}
return ret;
}
static int tmiofb_sync(struct fb_info *fbi)
{
struct tmiofb_par *par = fbi->par;
int ret;
int i = 0;
ret = tmiofb_acc_wait(fbi, 0);
while (tmio_ioread16(par->lcr + LCR_BBES) & 2) {
udelay(1);
i++ ;
if (i > 10000) {
printk(KERN_ERR "timeout waiting for blit to end!\n");
return -ETIMEDOUT;
}
}
return ret;
}
static void
tmiofb_fillrect(struct fb_info *fbi, const struct fb_fillrect *rect)
{
const u32 cmd[] = {
TMIOFB_ACC_DSADR((rect->dy * fbi->mode->xres + rect->dx) * 2),
TMIOFB_ACC_DHPIX(rect->width - 1),
TMIOFB_ACC_DVPIX(rect->height - 1),
TMIOFB_ACC_FILL(rect->color),
TMIOFB_ACC_FLGO,
};
if (fbi->state != FBINFO_STATE_RUNNING ||
fbi->flags & FBINFO_HWACCEL_DISABLED) {
cfb_fillrect(fbi, rect);
return;
}
tmiofb_acc_write(fbi, cmd, ARRAY_SIZE(cmd));
}
static void
tmiofb_copyarea(struct fb_info *fbi, const struct fb_copyarea *area)
{
const u32 cmd[] = {
TMIOFB_ACC_DSADR((area->dy * fbi->mode->xres + area->dx) * 2),
TMIOFB_ACC_DHPIX(area->width - 1),
TMIOFB_ACC_DVPIX(area->height - 1),
TMIOFB_ACC_SSADR((area->sy * fbi->mode->xres + area->sx) * 2),
TMIOFB_ACC_SCGO,
};
if (fbi->state != FBINFO_STATE_RUNNING ||
fbi->flags & FBINFO_HWACCEL_DISABLED) {
cfb_copyarea(fbi, area);
return;
}
tmiofb_acc_write(fbi, cmd, ARRAY_SIZE(cmd));
}
static void tmiofb_clearscreen(struct fb_info *info)
{
const struct fb_fillrect rect = {
.dx = 0,
.dy = 0,
.width = info->mode->xres,
.height = info->mode->yres,
.color = 0,
.rop = ROP_COPY,
};
info->fbops->fb_fillrect(info, &rect);
}
static int tmiofb_vblank(struct fb_info *fbi, struct fb_vblank *vblank)
{
struct tmiofb_par *par = fbi->par;
struct fb_videomode *mode = fbi->mode;
unsigned int vcount = tmio_ioread16(par->lcr + LCR_CDLN);
unsigned int vds = mode->vsync_len + mode->upper_margin;
vblank->vcount = vcount;
vblank->flags = FB_VBLANK_HAVE_VBLANK | FB_VBLANK_HAVE_VCOUNT
| FB_VBLANK_HAVE_VSYNC;
if (vcount < mode->vsync_len)
vblank->flags |= FB_VBLANK_VSYNCING;
if (vcount < vds || vcount > vds + mode->yres)
vblank->flags |= FB_VBLANK_VBLANKING;
return 0;
}
static int tmiofb_ioctl(struct fb_info *fbi,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case FBIOGET_VBLANK: {
struct fb_vblank vblank = {0};
void __user *argp = (void __user *) arg;
tmiofb_vblank(fbi, &vblank);
if (copy_to_user(argp, &vblank, sizeof vblank))
return -EFAULT;
return 0;
}
#ifdef CONFIG_FB_TMIO_ACCELL
case FBIO_TMIO_ACC_SYNC:
tmiofb_sync(fbi);
return 0;
case FBIO_TMIO_ACC_WRITE: {
u32 __user *argp = (void __user *) arg;
u32 len;
u32 acc[16];
if (get_user(len, argp))
return -EFAULT;
if (len > ARRAY_SIZE(acc))
return -EINVAL;
if (copy_from_user(acc, argp + 1, sizeof(u32) * len))
return -EFAULT;
return tmiofb_acc_write(fbi, acc, len);
}
#endif
}
return -ENOTTY;
}
static struct fb_videomode *
tmiofb_find_mode(struct fb_info *info, struct fb_var_screeninfo *var)
{
struct tmio_fb_data *data = info->device->platform_data;
struct fb_videomode *best = NULL;
int i;
for (i = 0; i < data->num_modes; i++) {
struct fb_videomode *mode = data->modes + i;
if (mode->xres >= var->xres && mode->yres >= var->yres
&& (!best || (mode->xres < best->xres
&& mode->yres < best->yres)))
best = mode;
}
return best;
}
static int tmiofb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct fb_videomode *mode;
struct tmio_fb_data *data = info->device->platform_data;
mode = tmiofb_find_mode(info, var);
if (!mode || var->bits_per_pixel > 16)
return -EINVAL;
fb_videomode_to_var(var, mode);
var->xres_virtual = mode->xres;
var->yres_virtual = info->screen_size / (mode->xres * 2);
if (var->yres_virtual < var->yres)
return -EINVAL;
var->xoffset = 0;
var->yoffset = 0;
var->bits_per_pixel = 16;
var->grayscale = 0;
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
var->transp.offset = 0;
var->transp.length = 0;
var->nonstd = 0;
var->height = data->height;
var->width = data->width;
var->rotate = 0;
return 0;
}
static int tmiofb_set_par(struct fb_info *info)
{
struct fb_var_screeninfo *var = &info->var;
struct fb_videomode *mode;
mode = tmiofb_find_mode(info, var);
if (!mode)
return -EINVAL;
info->mode = mode;
info->fix.line_length = info->mode->xres *
var->bits_per_pixel / 8;
tmiofb_hw_mode(to_platform_device(info->device));
tmiofb_clearscreen(info);
return 0;
}
static int tmiofb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct tmiofb_par *par = info->par;
if (regno < ARRAY_SIZE(par->pseudo_palette)) {
par->pseudo_palette[regno] =
((red & 0xf800)) |
((green & 0xfc00) >> 5) |
((blue & 0xf800) >> 11);
return 0;
}
return -EINVAL;
}
static int tmiofb_blank(int blank, struct fb_info *info)
{
return 0;
}
static int tmiofb_probe(struct platform_device *dev)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
struct tmio_fb_data *data = dev->dev.platform_data;
struct resource *ccr = platform_get_resource(dev, IORESOURCE_MEM, 1);
struct resource *lcr = platform_get_resource(dev, IORESOURCE_MEM, 0);
struct resource *vram = platform_get_resource(dev, IORESOURCE_MEM, 2);
int irq = platform_get_irq(dev, 0);
struct fb_info *info;
struct tmiofb_par *par;
int retval;
if (data == NULL) {
dev_err(&dev->dev, "NULL platform data!\n");
return -EINVAL;
}
if (ccr == NULL || lcr == NULL || vram == NULL || irq < 0) {
dev_err(&dev->dev, "missing resources\n");
return -EINVAL;
}
info = framebuffer_alloc(sizeof(struct tmiofb_par), &dev->dev);
if (!info)
return -ENOMEM;
par = info->par;
#ifdef CONFIG_FB_TMIO_ACCELL
init_waitqueue_head(&par->wait_acc);
par->use_polling = true;
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_COPYAREA
| FBINFO_HWACCEL_FILLRECT;
#else
info->flags = FBINFO_DEFAULT;
#endif
info->fbops = &tmiofb_ops;
strcpy(info->fix.id, "tmio-fb");
info->fix.smem_start = vram->start;
info->fix.smem_len = resource_size(vram);
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->fix.mmio_start = lcr->start;
info->fix.mmio_len = resource_size(lcr);
info->fix.accel = FB_ACCEL_NONE;
info->screen_size = info->fix.smem_len - (4 * TMIOFB_FIFO_SIZE);
info->pseudo_palette = par->pseudo_palette;
par->ccr = ioremap(ccr->start, resource_size(ccr));
if (!par->ccr) {
retval = -ENOMEM;
goto err_ioremap_ccr;
}
par->lcr = ioremap(info->fix.mmio_start, info->fix.mmio_len);
if (!par->lcr) {
retval = -ENOMEM;
goto err_ioremap_lcr;
}
info->screen_base = ioremap(info->fix.smem_start, info->fix.smem_len);
if (!info->screen_base) {
retval = -ENOMEM;
goto err_ioremap_vram;
}
retval = request_irq(irq, &tmiofb_irq, 0,
dev_name(&dev->dev), info);
if (retval)
goto err_request_irq;
platform_set_drvdata(dev, info);
retval = fb_find_mode(&info->var, info, mode_option,
data->modes, data->num_modes,
data->modes, 16);
if (!retval) {
retval = -EINVAL;
goto err_find_mode;
}
if (cell->enable) {
retval = cell->enable(dev);
if (retval)
goto err_enable;
}
retval = tmiofb_hw_init(dev);
if (retval)
goto err_hw_init;
fb_videomode_to_modelist(data->modes, data->num_modes,
&info->modelist);
retval = register_framebuffer(info);
if (retval < 0)
goto err_register_framebuffer;
printk(KERN_INFO "fb%d: %s frame buffer device\n",
info->node, info->fix.id);
return 0;
err_register_framebuffer:
tmiofb_hw_stop(dev);
err_hw_init:
if (cell->disable)
cell->disable(dev);
err_enable:
err_find_mode:
platform_set_drvdata(dev, NULL);
free_irq(irq, info);
err_request_irq:
iounmap(info->screen_base);
err_ioremap_vram:
iounmap(par->lcr);
err_ioremap_lcr:
iounmap(par->ccr);
err_ioremap_ccr:
framebuffer_release(info);
return retval;
}
static int tmiofb_remove(struct platform_device *dev)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
struct fb_info *info = platform_get_drvdata(dev);
int irq = platform_get_irq(dev, 0);
struct tmiofb_par *par;
if (info) {
par = info->par;
unregister_framebuffer(info);
tmiofb_hw_stop(dev);
if (cell->disable)
cell->disable(dev);
platform_set_drvdata(dev, NULL);
free_irq(irq, info);
iounmap(info->screen_base);
iounmap(par->lcr);
iounmap(par->ccr);
framebuffer_release(info);
}
return 0;
}
static void tmiofb_dump_regs(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
struct tmiofb_par *par = info->par;
printk(KERN_DEBUG "lhccr:\n");
#define CCR_PR(n) printk(KERN_DEBUG "\t" #n " = \t%04x\n",\
tmio_ioread16(par->ccr + CCR_ ## n));
CCR_PR(CMD);
CCR_PR(REVID);
CCR_PR(BASEL);
CCR_PR(BASEH);
CCR_PR(UGCC);
CCR_PR(GCC);
CCR_PR(USC);
CCR_PR(VRAMRTC);
CCR_PR(VRAMSAC);
CCR_PR(VRAMBC);
#undef CCR_PR
printk(KERN_DEBUG "lcr: \n");
#define LCR_PR(n) printk(KERN_DEBUG "\t" #n " = \t%04x\n",\
tmio_ioread16(par->lcr + LCR_ ## n));
LCR_PR(UIS);
LCR_PR(VHPN);
LCR_PR(CFSAL);
LCR_PR(CFSAH);
LCR_PR(CFS);
LCR_PR(CFWS);
LCR_PR(BBIE);
LCR_PR(BBISC);
LCR_PR(CCS);
LCR_PR(BBES);
LCR_PR(CMDL);
LCR_PR(CMDH);
LCR_PR(CFC);
LCR_PR(CCIFC);
LCR_PR(HWT);
LCR_PR(LCDCCRC);
LCR_PR(LCDCC);
LCR_PR(LCDCOPC);
LCR_PR(LCDIS);
LCR_PR(LCDIM);
LCR_PR(LCDIE);
LCR_PR(GDSAL);
LCR_PR(GDSAH);
LCR_PR(VHPCL);
LCR_PR(VHPCH);
LCR_PR(GM);
LCR_PR(HT);
LCR_PR(HDS);
LCR_PR(HSS);
LCR_PR(HSE);
LCR_PR(HNP);
LCR_PR(VT);
LCR_PR(VDS);
LCR_PR(VSS);
LCR_PR(VSE);
LCR_PR(CDLN);
LCR_PR(ILN);
LCR_PR(SP);
LCR_PR(MISC);
LCR_PR(VIHSS);
LCR_PR(VIVS);
LCR_PR(VIVE);
LCR_PR(VIVSS);
LCR_PR(VCCIS);
LCR_PR(VIDWSAL);
LCR_PR(VIDWSAH);
LCR_PR(VIDRSAL);
LCR_PR(VIDRSAH);
LCR_PR(VIPDDST);
LCR_PR(VIPDDET);
LCR_PR(VIE);
LCR_PR(VCS);
LCR_PR(VPHWC);
LCR_PR(VPHS);
LCR_PR(VPVWC);
LCR_PR(VPVS);
LCR_PR(PLHPIX);
LCR_PR(XS);
LCR_PR(XCKHW);
LCR_PR(STHS);
LCR_PR(VT2);
LCR_PR(YCKSW);
LCR_PR(YSTS);
LCR_PR(PPOLS);
LCR_PR(PRECW);
LCR_PR(VCLKHW);
LCR_PR(OC);
#undef LCR_PR
}
static int tmiofb_suspend(struct platform_device *dev, pm_message_t state)
{
struct fb_info *info = platform_get_drvdata(dev);
#ifdef CONFIG_FB_TMIO_ACCELL
struct tmiofb_par *par = info->par;
#endif
const struct mfd_cell *cell = mfd_get_cell(dev);
int retval = 0;
console_lock();
fb_set_suspend(info, 1);
if (info->fbops->fb_sync)
info->fbops->fb_sync(info);
#ifdef CONFIG_FB_TMIO_ACCELL
printk(KERN_INFO "tmiofb: switching to polling\n");
par->use_polling = true;
#endif
tmiofb_hw_stop(dev);
if (cell->suspend)
retval = cell->suspend(dev);
console_unlock();
return retval;
}
static int tmiofb_resume(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
const struct mfd_cell *cell = mfd_get_cell(dev);
int retval = 0;
console_lock();
if (cell->resume) {
retval = cell->resume(dev);
if (retval)
goto out;
}
tmiofb_irq(-1, info);
tmiofb_hw_init(dev);
tmiofb_hw_mode(dev);
fb_set_suspend(info, 0);
out:
console_unlock();
return retval;
}
static void __init tmiofb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!*this_opt)
continue;
}
}
static int __init tmiofb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("tmiofb", &option))
return -ENODEV;
tmiofb_setup(option);
#endif
return platform_driver_register(&tmiofb_driver);
}
static void __exit tmiofb_cleanup(void)
{
platform_driver_unregister(&tmiofb_driver);
}
