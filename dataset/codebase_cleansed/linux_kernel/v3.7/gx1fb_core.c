static int gx1_line_delta(int xres, int bpp)
{
int line_delta = xres * (bpp >> 3);
if (line_delta > 2048)
line_delta = 4096;
else if (line_delta > 1024)
line_delta = 2048;
else
line_delta = 1024;
return line_delta;
}
static int gx1fb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct geodefb_par *par = info->par;
if (var->xres > 1280 || var->yres > 1024)
return -EINVAL;
if (par->panel_x && (var->xres > par->panel_x || var->yres > par->panel_y))
return -EINVAL;
if (var->bits_per_pixel == 16) {
var->red.offset = 11; var->red.length = 5;
var->green.offset = 5; var->green.length = 6;
var->blue.offset = 0; var->blue.length = 5;
var->transp.offset = 0; var->transp.length = 0;
} else if (var->bits_per_pixel == 8) {
var->red.offset = 0; var->red.length = 8;
var->green.offset = 0; var->green.length = 8;
var->blue.offset = 0; var->blue.length = 8;
var->transp.offset = 0; var->transp.length = 0;
} else
return -EINVAL;
if (gx1_line_delta(var->xres, var->bits_per_pixel) * var->yres > info->fix.smem_len)
return -EINVAL;
return 0;
}
static int gx1fb_set_par(struct fb_info *info)
{
struct geodefb_par *par = info->par;
if (info->var.bits_per_pixel == 16)
info->fix.visual = FB_VISUAL_TRUECOLOR;
else
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.line_length = gx1_line_delta(info->var.xres, info->var.bits_per_pixel);
par->dc_ops->set_mode(info);
return 0;
}
static inline u_int chan_to_field(u_int chan, struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int gx1fb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct geodefb_par *par = info->par;
if (info->var.grayscale) {
red = green = blue = (red * 77 + green * 151 + blue * 28) >> 8;
}
if (info->fix.visual == FB_VISUAL_TRUECOLOR) {
u32 *pal = info->pseudo_palette;
u32 v;
if (regno >= 16)
return -EINVAL;
v = chan_to_field(red, &info->var.red);
v |= chan_to_field(green, &info->var.green);
v |= chan_to_field(blue, &info->var.blue);
pal[regno] = v;
} else {
if (regno >= 256)
return -EINVAL;
par->dc_ops->set_palette_reg(info, regno, red, green, blue);
}
return 0;
}
static int gx1fb_blank(int blank_mode, struct fb_info *info)
{
struct geodefb_par *par = info->par;
return par->vid_ops->blank_display(info, blank_mode);
}
static int __devinit gx1fb_map_video_memory(struct fb_info *info, struct pci_dev *dev)
{
struct geodefb_par *par = info->par;
unsigned gx_base;
int fb_len;
int ret;
gx_base = gx1_gx_base();
if (!gx_base)
return -ENODEV;
ret = pci_enable_device(dev);
if (ret < 0)
return ret;
ret = pci_request_region(dev, 0, "gx1fb (video)");
if (ret < 0)
return ret;
par->vid_regs = pci_ioremap_bar(dev, 0);
if (!par->vid_regs)
return -ENOMEM;
if (!request_mem_region(gx_base + 0x8300, 0x100, "gx1fb (display controller)"))
return -EBUSY;
par->dc_regs = ioremap(gx_base + 0x8300, 0x100);
if (!par->dc_regs)
return -ENOMEM;
if ((fb_len = gx1_frame_buffer_size()) < 0)
return -ENOMEM;
info->fix.smem_start = gx_base + 0x800000;
info->fix.smem_len = fb_len;
info->screen_base = ioremap(info->fix.smem_start, info->fix.smem_len);
if (!info->screen_base)
return -ENOMEM;
dev_info(&dev->dev, "%d Kibyte of video memory at 0x%lx\n",
info->fix.smem_len / 1024, info->fix.smem_start);
return 0;
}
static int parse_panel_option(struct fb_info *info)
{
struct geodefb_par *par = info->par;
if (strcmp(panel_option, "") != 0) {
int x, y;
char *s;
x = simple_strtol(panel_option, &s, 10);
if (!x)
return -EINVAL;
y = simple_strtol(s + 1, NULL, 10);
if (!y)
return -EINVAL;
par->panel_x = x;
par->panel_y = y;
}
return 0;
}
static struct fb_info * __devinit gx1fb_init_fbinfo(struct device *dev)
{
struct geodefb_par *par;
struct fb_info *info;
info = framebuffer_alloc(sizeof(struct geodefb_par) + sizeof(u32) * 16, dev);
if (!info)
return NULL;
par = info->par;
strcpy(info->fix.id, "GX1");
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.type_aux = 0;
info->fix.xpanstep = 0;
info->fix.ypanstep = 0;
info->fix.ywrapstep = 0;
info->fix.accel = FB_ACCEL_NONE;
info->var.nonstd = 0;
info->var.activate = FB_ACTIVATE_NOW;
info->var.height = -1;
info->var.width = -1;
info->var.accel_flags = 0;
info->var.vmode = FB_VMODE_NONINTERLACED;
info->fbops = &gx1fb_ops;
info->flags = FBINFO_DEFAULT;
info->node = -1;
info->pseudo_palette = (void *)par + sizeof(struct geodefb_par);
info->var.grayscale = 0;
par->enable_crt = crt_option;
if (parse_panel_option(info) < 0)
printk(KERN_WARNING "gx1fb: invalid 'panel' option -- disabling flat panel\n");
if (!par->panel_x)
par->enable_crt = 1;
if (fb_alloc_cmap(&info->cmap, 256, 0) < 0) {
framebuffer_release(info);
return NULL;
}
return info;
}
static int __devinit gx1fb_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct geodefb_par *par;
struct fb_info *info;
int ret;
info = gx1fb_init_fbinfo(&pdev->dev);
if (!info)
return -ENOMEM;
par = info->par;
par->dc_ops = &gx1_dc_ops;
par->vid_ops = &cs5530_vid_ops;
if ((ret = gx1fb_map_video_memory(info, pdev)) < 0) {
dev_err(&pdev->dev, "failed to map frame buffer or controller registers\n");
goto err;
}
ret = fb_find_mode(&info->var, info, mode_option,
gx1_modedb, ARRAY_SIZE(gx1_modedb), NULL, 16);
if (ret == 0 || ret == 4) {
dev_err(&pdev->dev, "could not find valid video mode\n");
ret = -EINVAL;
goto err;
}
memset_io(info->screen_base, 0, info->fix.smem_len);
gx1fb_check_var(&info->var, info);
gx1fb_set_par(info);
if (register_framebuffer(info) < 0) {
ret = -EINVAL;
goto err;
}
pci_set_drvdata(pdev, info);
printk(KERN_INFO "fb%d: %s frame buffer device\n", info->node, info->fix.id);
return 0;
err:
if (info->screen_base) {
iounmap(info->screen_base);
pci_release_region(pdev, 0);
}
if (par->vid_regs) {
iounmap(par->vid_regs);
pci_release_region(pdev, 1);
}
if (par->dc_regs) {
iounmap(par->dc_regs);
release_mem_region(gx1_gx_base() + 0x8300, 0x100);
}
if (info) {
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
return ret;
}
static void __devexit gx1fb_remove(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct geodefb_par *par = info->par;
unregister_framebuffer(info);
iounmap((void __iomem *)info->screen_base);
pci_release_region(pdev, 0);
iounmap(par->vid_regs);
pci_release_region(pdev, 1);
iounmap(par->dc_regs);
release_mem_region(gx1_gx_base() + 0x8300, 0x100);
fb_dealloc_cmap(&info->cmap);
pci_set_drvdata(pdev, NULL);
framebuffer_release(info);
}
static void __init gx1fb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return;
while ((this_opt = strsep(&options, ","))) {
if (!*this_opt)
continue;
if (!strncmp(this_opt, "mode:", 5))
strlcpy(mode_option, this_opt + 5, sizeof(mode_option));
else if (!strncmp(this_opt, "crt:", 4))
crt_option = !!simple_strtoul(this_opt + 4, NULL, 0);
else if (!strncmp(this_opt, "panel:", 6))
strlcpy(panel_option, this_opt + 6, sizeof(panel_option));
else
strlcpy(mode_option, this_opt, sizeof(mode_option));
}
}
static int __init gx1fb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("gx1fb", &option))
return -ENODEV;
gx1fb_setup(option);
#endif
return pci_register_driver(&gx1fb_driver);
}
static void __devexit gx1fb_cleanup(void)
{
pci_unregister_driver(&gx1fb_driver);
}
