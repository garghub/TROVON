static int __devinit e3d_get_props(struct e3d_info *ep)
{
ep->width = of_getintprop_default(ep->of_node, "width", 0);
ep->height = of_getintprop_default(ep->of_node, "height", 0);
ep->depth = of_getintprop_default(ep->of_node, "depth", 8);
if (!ep->width || !ep->height) {
printk(KERN_ERR "e3d: Critical properties missing for %s\n",
pci_name(ep->pdev));
return -EINVAL;
}
return 0;
}
static void e3d_clut_write(struct e3d_info *ep, int index, u32 val)
{
void __iomem *ramdac = ep->ramdac;
unsigned long flags;
spin_lock_irqsave(&ep->lock, flags);
writel(index, ramdac + RAMDAC_INDEX);
writel(val, ramdac + RAMDAC_DATA);
spin_unlock_irqrestore(&ep->lock, flags);
}
static int e3d_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
struct e3d_info *ep = info->par;
u32 red_8, green_8, blue_8;
u32 red_10, green_10, blue_10;
u32 value;
if (regno >= 256)
return 1;
red_8 = red >> 8;
green_8 = green >> 8;
blue_8 = blue >> 8;
value = (blue_8 << 24) | (green_8 << 16) | (red_8 << 8);
if (info->fix.visual == FB_VISUAL_TRUECOLOR && regno < 16)
((u32 *)info->pseudo_palette)[regno] = value;
red_10 = red >> 6;
green_10 = green >> 6;
blue_10 = blue >> 6;
value = (blue_10 << 20) | (green_10 << 10) | (red_10 << 0);
e3d_clut_write(ep, regno, value);
return 0;
}
static void e3d_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct e3d_info *ep = info->par;
unsigned long flags;
spin_lock_irqsave(&ep->lock, flags);
cfb_imageblit(info, image);
info->screen_base += ep->fb8_buf_diff;
cfb_imageblit(info, image);
info->screen_base -= ep->fb8_buf_diff;
spin_unlock_irqrestore(&ep->lock, flags);
}
static void e3d_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct e3d_info *ep = info->par;
unsigned long flags;
spin_lock_irqsave(&ep->lock, flags);
cfb_fillrect(info, rect);
info->screen_base += ep->fb8_buf_diff;
cfb_fillrect(info, rect);
info->screen_base -= ep->fb8_buf_diff;
spin_unlock_irqrestore(&ep->lock, flags);
}
static void e3d_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct e3d_info *ep = info->par;
unsigned long flags;
spin_lock_irqsave(&ep->lock, flags);
cfb_copyarea(info, area);
info->screen_base += ep->fb8_buf_diff;
cfb_copyarea(info, area);
info->screen_base -= ep->fb8_buf_diff;
spin_unlock_irqrestore(&ep->lock, flags);
}
static int __devinit e3d_set_fbinfo(struct e3d_info *ep)
{
struct fb_info *info = ep->info;
struct fb_var_screeninfo *var = &info->var;
info->flags = FBINFO_DEFAULT;
info->fbops = &e3d_ops;
info->screen_base = ep->fb_base;
info->screen_size = ep->fb_size;
info->pseudo_palette = ep->pseudo_palette;
strlcpy(info->fix.id, "e3d", sizeof(info->fix.id));
info->fix.smem_start = ep->fb_base_phys;
info->fix.smem_len = ep->fb_size;
info->fix.type = FB_TYPE_PACKED_PIXELS;
if (ep->depth == 32 || ep->depth == 24)
info->fix.visual = FB_VISUAL_TRUECOLOR;
else
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
var->xres = ep->width;
var->yres = ep->height;
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
var->bits_per_pixel = ep->depth;
var->red.offset = 8;
var->red.length = 8;
var->green.offset = 16;
var->green.length = 8;
var->blue.offset = 24;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
if (fb_alloc_cmap(&info->cmap, 256, 0)) {
printk(KERN_ERR "e3d: Cannot allocate color map.\n");
return -ENOMEM;
}
return 0;
}
static int __devinit e3d_pci_register(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct device_node *of_node;
const char *device_type;
struct fb_info *info;
struct e3d_info *ep;
unsigned int line_length;
int err;
of_node = pci_device_to_OF_node(pdev);
if (!of_node) {
printk(KERN_ERR "e3d: Cannot find OF node of %s\n",
pci_name(pdev));
return -ENODEV;
}
device_type = of_get_property(of_node, "device_type", NULL);
if (!device_type) {
printk(KERN_INFO "e3d: Ignoring secondary output device "
"at %s\n", pci_name(pdev));
return -ENODEV;
}
err = pci_enable_device(pdev);
if (err < 0) {
printk(KERN_ERR "e3d: Cannot enable PCI device %s\n",
pci_name(pdev));
goto err_out;
}
info = framebuffer_alloc(sizeof(struct e3d_info), &pdev->dev);
if (!info) {
printk(KERN_ERR "e3d: Cannot allocate fb_info\n");
err = -ENOMEM;
goto err_disable;
}
ep = info->par;
ep->info = info;
ep->pdev = pdev;
spin_lock_init(&ep->lock);
ep->of_node = of_node;
pci_read_config_dword(pdev, PCI_BASE_ADDRESS_0,
&ep->fb_base_reg);
ep->fb_base_reg &= PCI_BASE_ADDRESS_MEM_MASK;
ep->regs_base_phys = pci_resource_start (pdev, 1);
err = pci_request_region(pdev, 1, "e3d regs");
if (err < 0) {
printk("e3d: Cannot request region 1 for %s\n",
pci_name(pdev));
goto err_release_fb;
}
ep->ramdac = ioremap(ep->regs_base_phys + 0x8000, 0x1000);
if (!ep->ramdac)
goto err_release_pci1;
ep->fb8_0_off = readl(ep->ramdac + RAMDAC_VID_8FB_0);
ep->fb8_0_off -= ep->fb_base_reg;
ep->fb8_1_off = readl(ep->ramdac + RAMDAC_VID_8FB_1);
ep->fb8_1_off -= ep->fb_base_reg;
ep->fb8_buf_diff = ep->fb8_1_off - ep->fb8_0_off;
ep->fb_base_phys = pci_resource_start (pdev, 0);
ep->fb_base_phys += ep->fb8_0_off;
err = pci_request_region(pdev, 0, "e3d framebuffer");
if (err < 0) {
printk("e3d: Cannot request region 0 for %s\n",
pci_name(pdev));
goto err_unmap_ramdac;
}
err = e3d_get_props(ep);
if (err)
goto err_release_pci0;
line_length = (readl(ep->ramdac + RAMDAC_VID_CFG) >> 16) & 0xff;
line_length = 1 << line_length;
switch (ep->depth) {
case 8:
info->fix.line_length = line_length;
break;
case 16:
info->fix.line_length = line_length * 2;
break;
case 24:
info->fix.line_length = line_length * 3;
break;
case 32:
info->fix.line_length = line_length * 4;
break;
}
ep->fb_size = info->fix.line_length * ep->height;
ep->fb_base = ioremap(ep->fb_base_phys, ep->fb_size);
if (!ep->fb_base)
goto err_release_pci0;
err = e3d_set_fbinfo(ep);
if (err)
goto err_unmap_fb;
pci_set_drvdata(pdev, info);
printk("e3d: Found device at %s\n", pci_name(pdev));
err = register_framebuffer(info);
if (err < 0) {
printk(KERN_ERR "e3d: Could not register framebuffer %s\n",
pci_name(pdev));
goto err_free_cmap;
}
return 0;
err_free_cmap:
fb_dealloc_cmap(&info->cmap);
err_unmap_fb:
iounmap(ep->fb_base);
err_release_pci0:
pci_release_region(pdev, 0);
err_unmap_ramdac:
iounmap(ep->ramdac);
err_release_pci1:
pci_release_region(pdev, 1);
err_release_fb:
framebuffer_release(info);
err_disable:
pci_disable_device(pdev);
err_out:
return err;
}
static void __devexit e3d_pci_unregister(struct pci_dev *pdev)
{
struct fb_info *info = pci_get_drvdata(pdev);
struct e3d_info *ep = info->par;
unregister_framebuffer(info);
iounmap(ep->ramdac);
iounmap(ep->fb_base);
pci_release_region(pdev, 0);
pci_release_region(pdev, 1);
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
pci_disable_device(pdev);
}
static int __init e3d_init(void)
{
if (fb_get_options("e3d", NULL))
return -ENODEV;
return pci_register_driver(&e3d_driver);
}
static void __exit e3d_exit(void)
{
pci_unregister_driver(&e3d_driver);
}
