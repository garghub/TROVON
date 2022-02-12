static int aafb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
struct aafb_par *par = info->par;
if (cursor->image.height > BT431_CURSOR_SIZE ||
cursor->image.width > BT431_CURSOR_SIZE) {
bt431_erase_cursor(par->bt431);
return -EINVAL;
}
if (!cursor->enable)
bt431_erase_cursor(par->bt431);
if (cursor->set & FB_CUR_SETPOS)
bt431_position_cursor(par->bt431,
cursor->image.dx, cursor->image.dy);
if (cursor->set & FB_CUR_SETCMAP) {
u8 fg = cursor->image.fg_color ? 0xf : 0x0;
u8 bg = cursor->image.bg_color ? 0xf : 0x0;
bt455_write_cmap_entry(par->bt455, 8, bg);
bt455_write_cmap_next(par->bt455, bg);
bt455_write_ovly_next(par->bt455, fg);
}
if (cursor->set & (FB_CUR_SETSIZE | FB_CUR_SETSHAPE | FB_CUR_SETIMAGE))
bt431_set_cursor(par->bt431,
cursor->image.data, cursor->mask, cursor->rop,
cursor->image.width, cursor->image.height);
if (cursor->enable)
bt431_enable_cursor(par->bt431);
return 0;
}
static int aafb_blank(int blank, struct fb_info *info)
{
struct aafb_par *par = info->par;
u8 val = blank ? 0x00 : 0x0f;
bt455_write_cmap_entry(par->bt455, 1, val);
return 0;
}
static int pmagaafb_probe(struct device *dev)
{
struct tc_dev *tdev = to_tc_dev(dev);
resource_size_t start, len;
struct fb_info *info;
struct aafb_par *par;
int err;
info = framebuffer_alloc(sizeof(struct aafb_par), dev);
if (!info) {
printk(KERN_ERR "%s: Cannot allocate memory\n", dev_name(dev));
return -ENOMEM;
}
par = info->par;
dev_set_drvdata(dev, info);
info->fbops = &aafb_ops;
info->fix = aafb_fix;
info->var = aafb_defined;
info->flags = FBINFO_DEFAULT;
start = tdev->resource.start;
len = tdev->resource.end - start + 1;
if (!request_mem_region(start, len, dev_name(dev))) {
printk(KERN_ERR "%s: Cannot reserve FB region\n",
dev_name(dev));
err = -EBUSY;
goto err_alloc;
}
info->fix.mmio_start = start + PMAG_AA_BT455_OFFSET;
par->mmio = ioremap_nocache(info->fix.mmio_start, info->fix.mmio_len);
if (!par->mmio) {
printk(KERN_ERR "%s: Cannot map MMIO\n", dev_name(dev));
err = -ENOMEM;
goto err_resource;
}
par->bt455 = par->mmio - PMAG_AA_BT455_OFFSET + PMAG_AA_BT455_OFFSET;
par->bt431 = par->mmio - PMAG_AA_BT455_OFFSET + PMAG_AA_BT431_OFFSET;
info->fix.smem_start = start + PMAG_AA_ONBOARD_FBMEM_OFFSET;
info->screen_base = ioremap_nocache(info->fix.smem_start,
info->fix.smem_len);
if (!info->screen_base) {
printk(KERN_ERR "%s: Cannot map FB\n", dev_name(dev));
err = -ENOMEM;
goto err_mmio_map;
}
info->screen_size = info->fix.smem_len;
bt455_write_cmap_entry(par->bt455, 0, 0x0);
bt455_write_cmap_next(par->bt455, 0xf);
bt431_erase_cursor(par->bt431);
bt431_init_cursor(par->bt431);
err = register_framebuffer(info);
if (err < 0) {
printk(KERN_ERR "%s: Cannot register framebuffer\n",
dev_name(dev));
goto err_smem_map;
}
get_device(dev);
pr_info("fb%d: %s frame buffer device at %s\n",
info->node, info->fix.id, dev_name(dev));
return 0;
err_smem_map:
iounmap(info->screen_base);
err_mmio_map:
iounmap(par->mmio);
err_resource:
release_mem_region(start, len);
err_alloc:
framebuffer_release(info);
return err;
}
static int __exit pmagaafb_remove(struct device *dev)
{
struct tc_dev *tdev = to_tc_dev(dev);
struct fb_info *info = dev_get_drvdata(dev);
struct aafb_par *par = info->par;
resource_size_t start, len;
put_device(dev);
unregister_framebuffer(info);
iounmap(info->screen_base);
iounmap(par->mmio);
start = tdev->resource.start;
len = tdev->resource.end - start + 1;
release_mem_region(start, len);
framebuffer_release(info);
return 0;
}
static int __init pmagaafb_init(void)
{
#ifndef MODULE
if (fb_get_options("pmagaafb", NULL))
return -ENXIO;
#endif
return tc_register_driver(&pmagaafb_driver);
}
static void __exit pmagaafb_exit(void)
{
tc_unregister_driver(&pmagaafb_driver);
}
