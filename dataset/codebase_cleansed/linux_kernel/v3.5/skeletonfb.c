static int xxxfb_open(struct fb_info *info, int user)
{
return 0;
}
static int xxxfb_release(struct fb_info *info, int user)
{
return 0;
}
static int xxxfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
return 0;
}
static int xxxfb_set_par(struct fb_info *info)
{
struct xxx_par *par = info->par;
return 0;
}
static int xxxfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
if (regno >= 256)
return -EINVAL;
if (info->var.grayscale) {
red = green = blue = (red * 77 + green * 151 + blue * 28) >> 8;
}
#define CNVT_TOHW(val,width) ((((val)<<(width))+0x7FFF-(val))>>16)
red = CNVT_TOHW(red, info->var.red.length);
green = CNVT_TOHW(green, info->var.green.length);
blue = CNVT_TOHW(blue, info->var.blue.length);
transp = CNVT_TOHW(transp, info->var.transp.length);
#undef CNVT_TOHW
if (info->fix.visual == FB_VISUAL_DIRECTCOLOR ||
info->fix.visual == FB_VISUAL_TRUECOLOR)
write_{red|green|blue|transp}_to_clut();
if (info->fix.visual == FB_VISUAL_TRUECOLOR ||
info->fix.visual == FB_VISUAL_DIRECTCOLOR) {
u32 v;
if (regno >= 16)
return -EINVAL;
v = (red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset) |
(transp << info->var.transp.offset);
((u32*)(info->pseudo_palette))[regno] = v;
}
return 0;
}
static int xxxfb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
return 0;
}
static int xxxfb_blank(int blank_mode, struct fb_info *info)
{
return 0;
}
void xxxfb_fillrect(struct fb_info *p, const struct fb_fillrect *region)
{
}
void xxxfb_copyarea(struct fb_info *p, const struct fb_copyarea *area)
{
}
void xxxfb_imageblit(struct fb_info *p, const struct fb_image *image)
{
}
int xxxfb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
}
void xxxfb_rotate(struct fb_info *info, int angle)
{
}
int xxxfb_sync(struct fb_info *info)
{
return 0;
}
static int __devinit xxxfb_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
struct fb_info *info;
struct xxx_par *par;
struct device *device = &dev->dev;
int cmap_len, retval;
info = framebuffer_alloc(sizeof(struct xxx_par), device);
if (!info) {
}
par = info->par;
info->screen_base = framebuffer_virtual_memory;
info->fbops = &xxxfb_ops;
info->fix = xxxfb_fix;
info->pseudo_palette = pseudo_palette;
info->flags = FBINFO_DEFAULT;
info->pixmap.addr = kmalloc(PIXMAP_SIZE, GFP_KERNEL);
if (!info->pixmap.addr) {
}
info->pixmap.size = PIXMAP_SIZE;
info->pixmap.flags = FB_PIXMAP_SYSTEM;
info->pixmap.scan_align = 4;
info->pixmap.buf_align = 4;
info->pixmap.access_align = 32;
if (!mode_option)
mode_option = "640x480@60";
retval = fb_find_mode(&info->var, info, mode_option, NULL, 0, NULL, 8);
if (!retval || retval == 4)
return -EINVAL;
if (fb_alloc_cmap(&info->cmap, cmap_len, 0))
return -ENOMEM;
info->var = xxxfb_var;
xxxfb_check_var(&info->var, info);
if (register_framebuffer(info) < 0) {
fb_dealloc_cmap(&info->cmap);
return -EINVAL;
}
printk(KERN_INFO "fb%d: %s frame buffer device\n", info->node,
info->fix.id);
pci_set_drvdata(dev, info);
return 0;
}
static void __devexit xxxfb_remove(struct pci_dev *dev)
{
struct fb_info *info = pci_get_drvdata(dev);
if (info) {
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
}
static int xxxfb_suspend(struct pci_dev *dev, pm_message_t msg)
{
struct fb_info *info = pci_get_drvdata(dev);
struct xxxfb_par *par = info->par;
return 0;
}
static int xxxfb_resume(struct pci_dev *dev)
{
struct fb_info *info = pci_get_drvdata(dev);
struct xxxfb_par *par = info->par;
return 0;
}
int __init xxxfb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("xxxfb", &option))
return -ENODEV;
xxxfb_setup(option);
#endif
return pci_register_driver(&xxxfb_driver);
}
static void __exit xxxfb_exit(void)
{
pci_unregister_driver(&xxxfb_driver);
}
static int xxxfb_suspend(struct platform_device *dev, pm_message_t msg)
{
struct fb_info *info = platform_get_drvdata(dev);
struct xxxfb_par *par = info->par;
return 0;
}
static int xxxfb_resume(struct platform_dev *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
struct xxxfb_par *par = info->par;
return 0;
}
int __init xxxfb_setup(char *options)
{
}
static int __init xxxfb_init(void)
{
int ret;
#ifndef MODULE
char *option = NULL;
if (fb_get_options("xxxfb", &option))
return -ENODEV;
xxxfb_setup(option);
#endif
ret = platform_driver_register(&xxxfb_driver);
if (!ret) {
xxxfb_device = platform_device_register_simple("xxxfb", 0,
NULL, 0);
if (IS_ERR(xxxfb_device)) {
platform_driver_unregister(&xxxfb_driver);
ret = PTR_ERR(xxxfb_device);
}
}
return ret;
}
static void __exit xxxfb_exit(void)
{
platform_device_unregister(xxxfb_device);
platform_driver_unregister(&xxxfb_driver);
}
