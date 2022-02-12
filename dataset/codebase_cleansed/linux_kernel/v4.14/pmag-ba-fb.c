static inline void dac_write(struct pmagbafb_par *par, unsigned int reg, u8 v)
{
writeb(v, par->dac + reg / 4);
}
static inline u8 dac_read(struct pmagbafb_par *par, unsigned int reg)
{
return readb(par->dac + reg / 4);
}
static int pmagbafb_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int transp, struct fb_info *info)
{
struct pmagbafb_par *par = info->par;
if (regno >= info->cmap.len)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
mb();
dac_write(par, BT459_ADDR_LO, regno);
dac_write(par, BT459_ADDR_HI, 0x00);
wmb();
dac_write(par, BT459_CMAP, red);
wmb();
dac_write(par, BT459_CMAP, green);
wmb();
dac_write(par, BT459_CMAP, blue);
return 0;
}
static void pmagbafb_erase_cursor(struct fb_info *info)
{
struct pmagbafb_par *par = info->par;
mb();
dac_write(par, BT459_ADDR_LO, 0x00);
dac_write(par, BT459_ADDR_HI, 0x03);
wmb();
dac_write(par, BT459_DATA, 0x00);
}
static int pmagbafb_probe(struct device *dev)
{
struct tc_dev *tdev = to_tc_dev(dev);
resource_size_t start, len;
struct fb_info *info;
struct pmagbafb_par *par;
int err;
info = framebuffer_alloc(sizeof(struct pmagbafb_par), dev);
if (!info) {
printk(KERN_ERR "%s: Cannot allocate memory\n", dev_name(dev));
return -ENOMEM;
}
par = info->par;
dev_set_drvdata(dev, info);
if (fb_alloc_cmap(&info->cmap, 256, 0) < 0) {
printk(KERN_ERR "%s: Cannot allocate color map\n",
dev_name(dev));
err = -ENOMEM;
goto err_alloc;
}
info->fbops = &pmagbafb_ops;
info->fix = pmagbafb_fix;
info->var = pmagbafb_defined;
info->flags = FBINFO_DEFAULT;
start = tdev->resource.start;
len = tdev->resource.end - start + 1;
if (!request_mem_region(start, len, dev_name(dev))) {
printk(KERN_ERR "%s: Cannot reserve FB region\n",
dev_name(dev));
err = -EBUSY;
goto err_cmap;
}
info->fix.mmio_start = start;
par->mmio = ioremap_nocache(info->fix.mmio_start, info->fix.mmio_len);
if (!par->mmio) {
printk(KERN_ERR "%s: Cannot map MMIO\n", dev_name(dev));
err = -ENOMEM;
goto err_resource;
}
par->dac = par->mmio + PMAG_BA_BT459;
info->fix.smem_start = start + PMAG_BA_FBMEM;
info->screen_base = ioremap_nocache(info->fix.smem_start,
info->fix.smem_len);
if (!info->screen_base) {
printk(KERN_ERR "%s: Cannot map FB\n", dev_name(dev));
err = -ENOMEM;
goto err_mmio_map;
}
info->screen_size = info->fix.smem_len;
pmagbafb_erase_cursor(info);
err = register_framebuffer(info);
if (err < 0) {
printk(KERN_ERR "%s: Cannot register framebuffer\n",
dev_name(dev));
goto err_smem_map;
}
get_device(dev);
fb_info(info, "%s frame buffer device at %s\n",
info->fix.id, dev_name(dev));
return 0;
err_smem_map:
iounmap(info->screen_base);
err_mmio_map:
iounmap(par->mmio);
err_resource:
release_mem_region(start, len);
err_cmap:
fb_dealloc_cmap(&info->cmap);
err_alloc:
framebuffer_release(info);
return err;
}
static int pmagbafb_remove(struct device *dev)
{
struct tc_dev *tdev = to_tc_dev(dev);
struct fb_info *info = dev_get_drvdata(dev);
struct pmagbafb_par *par = info->par;
resource_size_t start, len;
put_device(dev);
unregister_framebuffer(info);
iounmap(info->screen_base);
iounmap(par->mmio);
start = tdev->resource.start;
len = tdev->resource.end - start + 1;
release_mem_region(start, len);
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
return 0;
}
static int __init pmagbafb_init(void)
{
#ifndef MODULE
if (fb_get_options("pmagbafb", NULL))
return -ENXIO;
#endif
return tc_register_driver(&pmagbafb_driver);
}
static void __exit pmagbafb_exit(void)
{
tc_unregister_driver(&pmagbafb_driver);
}
