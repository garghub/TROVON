void wmt_ge_fillrect(struct fb_info *p, const struct fb_fillrect *rect)
{
unsigned long fg, pat;
if (p->state != FBINFO_STATE_RUNNING)
return;
if (p->fix.visual == FB_VISUAL_TRUECOLOR ||
p->fix.visual == FB_VISUAL_DIRECTCOLOR)
fg = ((u32 *) (p->pseudo_palette))[rect->color];
else
fg = rect->color;
pat = pixel_to_pat(p->var.bits_per_pixel, fg);
if (p->fbops->fb_sync)
p->fbops->fb_sync(p);
writel(p->var.bits_per_pixel == 32 ? 3 :
(p->var.bits_per_pixel == 8 ? 0 : 1), regbase + GE_DEPTH_OFF);
writel(p->var.bits_per_pixel == 15 ? 1 : 0, regbase + GE_HIGHCOLOR_OFF);
writel(p->fix.smem_start, regbase + GE_DESTBASE_OFF);
writel(p->var.xres_virtual - 1, regbase + GE_DESTDISPW_OFF);
writel(p->var.yres_virtual - 1, regbase + GE_DESTDISPH_OFF);
writel(rect->dx, regbase + GE_DESTAREAX_OFF);
writel(rect->dy, regbase + GE_DESTAREAY_OFF);
writel(rect->width - 1, regbase + GE_DESTAREAW_OFF);
writel(rect->height - 1, regbase + GE_DESTAREAH_OFF);
writel(pat, regbase + GE_PAT0C_OFF);
writel(1, regbase + GE_COMMAND_OFF);
writel(rect->rop == ROP_XOR ? 0x5a : 0xf0, regbase + GE_ROPCODE_OFF);
writel(1, regbase + GE_FIRE_OFF);
}
void wmt_ge_copyarea(struct fb_info *p, const struct fb_copyarea *area)
{
if (p->state != FBINFO_STATE_RUNNING)
return;
if (p->fbops->fb_sync)
p->fbops->fb_sync(p);
writel(p->var.bits_per_pixel > 16 ? 3 :
(p->var.bits_per_pixel > 8 ? 1 : 0), regbase + GE_DEPTH_OFF);
writel(p->fix.smem_start, regbase + GE_SRCBASE_OFF);
writel(p->var.xres_virtual - 1, regbase + GE_SRCDISPW_OFF);
writel(p->var.yres_virtual - 1, regbase + GE_SRCDISPH_OFF);
writel(area->sx, regbase + GE_SRCAREAX_OFF);
writel(area->sy, regbase + GE_SRCAREAY_OFF);
writel(area->width - 1, regbase + GE_SRCAREAW_OFF);
writel(area->height - 1, regbase + GE_SRCAREAH_OFF);
writel(p->fix.smem_start, regbase + GE_DESTBASE_OFF);
writel(p->var.xres_virtual - 1, regbase + GE_DESTDISPW_OFF);
writel(p->var.yres_virtual - 1, regbase + GE_DESTDISPH_OFF);
writel(area->dx, regbase + GE_DESTAREAX_OFF);
writel(area->dy, regbase + GE_DESTAREAY_OFF);
writel(area->width - 1, regbase + GE_DESTAREAW_OFF);
writel(area->height - 1, regbase + GE_DESTAREAH_OFF);
writel(0xcc, regbase + GE_ROPCODE_OFF);
writel(1, regbase + GE_COMMAND_OFF);
writel(1, regbase + GE_FIRE_OFF);
}
int wmt_ge_sync(struct fb_info *p)
{
int loops = 5000000;
while ((readl(regbase + GE_STATUS_OFF) & 4) && --loops)
cpu_relax();
return loops > 0 ? 0 : -EBUSY;
}
static int __devinit wmt_ge_rops_probe(struct platform_device *pdev)
{
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no I/O memory resource defined\n");
return -ENODEV;
}
if (unlikely(regbase)) {
WARN_ON(1);
return -EBUSY;
}
regbase = ioremap(res->start, resource_size(res));
if (regbase == NULL) {
dev_err(&pdev->dev, "failed to map I/O memory\n");
return -EBUSY;
}
writel(1, regbase + GE_ENABLE_OFF);
printk(KERN_INFO "Enabled support for WMT GE raster acceleration\n");
return 0;
}
static int __devexit wmt_ge_rops_remove(struct platform_device *pdev)
{
iounmap(regbase);
return 0;
}
static int __init wmt_ge_rops_init(void)
{
return platform_driver_register(&wmt_ge_rops_driver);
}
static void __exit wmt_ge_rops_exit(void)
{
platform_driver_unregister(&wmt_ge_rops_driver);
}
