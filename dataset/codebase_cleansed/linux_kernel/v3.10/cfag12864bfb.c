static int cfag12864bfb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
return vm_insert_page(vma, vma->vm_start,
virt_to_page(cfag12864b_buffer));
}
static int cfag12864bfb_probe(struct platform_device *device)
{
int ret = -EINVAL;
struct fb_info *info = framebuffer_alloc(0, &device->dev);
if (!info)
goto none;
info->screen_base = (char __iomem *) cfag12864b_buffer;
info->screen_size = CFAG12864B_SIZE;
info->fbops = &cfag12864bfb_ops;
info->fix = cfag12864bfb_fix;
info->var = cfag12864bfb_var;
info->pseudo_palette = NULL;
info->par = NULL;
info->flags = FBINFO_FLAG_DEFAULT;
if (register_framebuffer(info) < 0)
goto fballoced;
platform_set_drvdata(device, info);
printk(KERN_INFO "fb%d: %s frame buffer device\n", info->node,
info->fix.id);
return 0;
fballoced:
framebuffer_release(info);
none:
return ret;
}
static int cfag12864bfb_remove(struct platform_device *device)
{
struct fb_info *info = platform_get_drvdata(device);
if (info) {
unregister_framebuffer(info);
framebuffer_release(info);
}
return 0;
}
static int __init cfag12864bfb_init(void)
{
int ret = -EINVAL;
if (!cfag12864b_isinited()) {
printk(KERN_ERR CFAG12864BFB_NAME ": ERROR: "
"cfag12864b is not initialized\n");
goto none;
}
if (cfag12864b_enable()) {
printk(KERN_ERR CFAG12864BFB_NAME ": ERROR: "
"can't enable cfag12864b refreshing (being used)\n");
return -ENODEV;
}
ret = platform_driver_register(&cfag12864bfb_driver);
if (!ret) {
cfag12864bfb_device =
platform_device_alloc(CFAG12864BFB_NAME, 0);
if (cfag12864bfb_device)
ret = platform_device_add(cfag12864bfb_device);
else
ret = -ENOMEM;
if (ret) {
platform_device_put(cfag12864bfb_device);
platform_driver_unregister(&cfag12864bfb_driver);
}
}
none:
return ret;
}
static void __exit cfag12864bfb_exit(void)
{
platform_device_unregister(cfag12864bfb_device);
platform_driver_unregister(&cfag12864bfb_driver);
cfag12864b_disable();
}
