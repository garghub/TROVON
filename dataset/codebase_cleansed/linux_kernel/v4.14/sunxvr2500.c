static int s3d_get_props(struct s3d_info *sp)
{
sp->width = of_getintprop_default(sp->of_node, "width", 0);
sp->height = of_getintprop_default(sp->of_node, "height", 0);
sp->depth = of_getintprop_default(sp->of_node, "depth", 8);
if (!sp->width || !sp->height) {
printk(KERN_ERR "s3d: Critical properties missing for %s\n",
pci_name(sp->pdev));
return -EINVAL;
}
return 0;
}
static int s3d_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
u32 value;
if (regno < 16) {
red >>= 8;
green >>= 8;
blue >>= 8;
value = (blue << 24) | (green << 16) | (red << 8);
((u32 *)info->pseudo_palette)[regno] = value;
}
return 0;
}
static int s3d_set_fbinfo(struct s3d_info *sp)
{
struct fb_info *info = sp->info;
struct fb_var_screeninfo *var = &info->var;
info->flags = FBINFO_DEFAULT;
info->fbops = &s3d_ops;
info->screen_base = sp->fb_base;
info->screen_size = sp->fb_size;
info->pseudo_palette = sp->pseudo_palette;
strlcpy(info->fix.id, "s3d", sizeof(info->fix.id));
info->fix.smem_start = sp->fb_base_phys;
info->fix.smem_len = sp->fb_size;
info->fix.type = FB_TYPE_PACKED_PIXELS;
if (sp->depth == 32 || sp->depth == 24)
info->fix.visual = FB_VISUAL_TRUECOLOR;
else
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
var->xres = sp->width;
var->yres = sp->height;
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
var->bits_per_pixel = sp->depth;
var->red.offset = 8;
var->red.length = 8;
var->green.offset = 16;
var->green.length = 8;
var->blue.offset = 24;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
if (fb_alloc_cmap(&info->cmap, 256, 0)) {
printk(KERN_ERR "s3d: Cannot allocate color map.\n");
return -ENOMEM;
}
return 0;
}
static int s3d_pci_register(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct fb_info *info;
struct s3d_info *sp;
int err;
err = pci_enable_device(pdev);
if (err < 0) {
printk(KERN_ERR "s3d: Cannot enable PCI device %s\n",
pci_name(pdev));
goto err_out;
}
info = framebuffer_alloc(sizeof(struct s3d_info), &pdev->dev);
if (!info) {
printk(KERN_ERR "s3d: Cannot allocate fb_info\n");
err = -ENOMEM;
goto err_disable;
}
sp = info->par;
sp->info = info;
sp->pdev = pdev;
sp->of_node = pci_device_to_OF_node(pdev);
if (!sp->of_node) {
printk(KERN_ERR "s3d: Cannot find OF node of %s\n",
pci_name(pdev));
err = -ENODEV;
goto err_release_fb;
}
sp->fb_base_phys = pci_resource_start (pdev, 1);
err = pci_request_region(pdev, 1, "s3d framebuffer");
if (err < 0) {
printk("s3d: Cannot request region 1 for %s\n",
pci_name(pdev));
goto err_release_fb;
}
err = s3d_get_props(sp);
if (err)
goto err_release_pci;
switch (sp->depth) {
case 8:
info->fix.line_length = sp->width;
break;
case 16:
info->fix.line_length = sp->width * 2;
break;
case 24:
info->fix.line_length = sp->width * 3;
break;
case 32:
info->fix.line_length = sp->width * 4;
break;
}
sp->fb_size = info->fix.line_length * sp->height;
sp->fb_base = ioremap(sp->fb_base_phys, sp->fb_size);
if (!sp->fb_base) {
err = -ENOMEM;
goto err_release_pci;
}
err = s3d_set_fbinfo(sp);
if (err)
goto err_unmap_fb;
pci_set_drvdata(pdev, info);
printk("s3d: Found device at %s\n", pci_name(pdev));
err = register_framebuffer(info);
if (err < 0) {
printk(KERN_ERR "s3d: Could not register framebuffer %s\n",
pci_name(pdev));
goto err_unmap_fb;
}
return 0;
err_unmap_fb:
iounmap(sp->fb_base);
err_release_pci:
pci_release_region(pdev, 1);
err_release_fb:
framebuffer_release(info);
err_disable:
pci_disable_device(pdev);
err_out:
return err;
}
static int __init s3d_init(void)
{
if (fb_get_options("s3d", NULL))
return -ENODEV;
return pci_register_driver(&s3d_driver);
}
