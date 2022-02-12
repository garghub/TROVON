static int q40fb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
if (regno > 255)
return 1;
red>>=11;
green>>=11;
blue>>=10;
if (regno < 16) {
((u32 *)info->pseudo_palette)[regno] = ((red & 31) <<6) |
((green & 31) << 11) |
(blue & 63);
}
return 0;
}
static int q40fb_probe(struct platform_device *dev)
{
struct fb_info *info;
if (!MACH_IS_Q40)
return -ENXIO;
q40fb_fix.smem_start = Q40_PHYS_SCREEN_ADDR;
info = framebuffer_alloc(sizeof(u32) * 16, &dev->dev);
if (!info)
return -ENOMEM;
info->var = q40fb_var;
info->fix = q40fb_fix;
info->fbops = &q40fb_ops;
info->flags = FBINFO_DEFAULT;
info->pseudo_palette = info->par;
info->par = NULL;
info->screen_base = (char *) q40fb_fix.smem_start;
if (fb_alloc_cmap(&info->cmap, 256, 0) < 0) {
framebuffer_release(info);
return -ENOMEM;
}
master_outb(3, DISPLAY_CONTROL_REG);
if (register_framebuffer(info) < 0) {
printk(KERN_ERR "Unable to register Q40 frame buffer\n");
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
return -EINVAL;
}
printk(KERN_INFO "fb%d: Q40 frame buffer alive and kicking !\n",
info->node);
return 0;
}
int __init q40fb_init(void)
{
int ret = 0;
if (fb_get_options("q40fb", NULL))
return -ENODEV;
ret = platform_driver_register(&q40fb_driver);
if (!ret) {
ret = platform_device_register(&q40fb_device);
if (ret)
platform_driver_unregister(&q40fb_driver);
}
return ret;
}
