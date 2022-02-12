static int
bw2_blank(int blank, struct fb_info *info)
{
struct bw2_par *par = (struct bw2_par *) info->par;
struct bw2_regs __iomem *regs = par->regs;
unsigned long flags;
u8 val;
spin_lock_irqsave(&par->lock, flags);
switch (blank) {
case FB_BLANK_UNBLANK:
val = sbus_readb(&regs->control);
val |= BWTWO_CTL_ENABLE_VIDEO;
sbus_writeb(val, &regs->control);
par->flags &= ~BW2_FLAG_BLANKED;
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
val = sbus_readb(&regs->control);
val &= ~BWTWO_CTL_ENABLE_VIDEO;
sbus_writeb(val, &regs->control);
par->flags |= BW2_FLAG_BLANKED;
break;
}
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int bw2_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct bw2_par *par = (struct bw2_par *)info->par;
return sbusfb_mmap_helper(bw2_mmap_map,
info->fix.smem_start, info->fix.smem_len,
par->which_io,
vma);
}
static int bw2_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
return sbusfb_ioctl_helper(cmd, arg, info,
FBTYPE_SUN2BW, 1, info->fix.smem_len);
}
static void bw2_init_fix(struct fb_info *info, int linebytes)
{
strlcpy(info->fix.id, "bwtwo", sizeof(info->fix.id));
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_MONO01;
info->fix.line_length = linebytes;
info->fix.accel = FB_ACCEL_SUN_BWTWO;
}
static int bw2_do_default_mode(struct bw2_par *par, struct fb_info *info,
int *linebytes)
{
u8 status, mon;
u8 *p;
status = sbus_readb(&par->regs->status);
mon = status & BWTWO_SR_RES_MASK;
switch (status & BWTWO_SR_ID_MASK) {
case BWTWO_SR_ID_MONO_ECL:
if (mon == BWTWO_SR_1600_1280) {
p = bw2regs_1600;
info->var.xres = info->var.xres_virtual = 1600;
info->var.yres = info->var.yres_virtual = 1280;
*linebytes = 1600 / 8;
} else
p = bw2regs_ecl;
break;
case BWTWO_SR_ID_MONO:
p = bw2regs_analog;
break;
case BWTWO_SR_ID_MSYNC:
if (mon == BWTWO_SR_1152_900_76_A ||
mon == BWTWO_SR_1152_900_76_B)
p = bw2regs_76hz;
else
p = bw2regs_66hz;
break;
case BWTWO_SR_ID_NOCONN:
return 0;
default:
printk(KERN_ERR "bw2: can't handle SR %02x\n",
status);
return -EINVAL;
}
for ( ; *p; p += 2) {
u8 __iomem *regp = &((u8 __iomem *)par->regs)[p[0]];
sbus_writeb(p[1], regp);
}
return 0;
}
static int bw2_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct fb_info *info;
struct bw2_par *par;
int linebytes, err;
info = framebuffer_alloc(sizeof(struct bw2_par), &op->dev);
err = -ENOMEM;
if (!info)
goto out_err;
par = info->par;
spin_lock_init(&par->lock);
info->fix.smem_start = op->resource[0].start;
par->which_io = op->resource[0].flags & IORESOURCE_BITS;
sbusfb_fill_var(&info->var, dp, 1);
linebytes = of_getintprop_default(dp, "linebytes",
info->var.xres);
info->var.red.length = info->var.green.length =
info->var.blue.length = info->var.bits_per_pixel;
info->var.red.offset = info->var.green.offset =
info->var.blue.offset = 0;
par->regs = of_ioremap(&op->resource[0], BWTWO_REGISTER_OFFSET,
sizeof(struct bw2_regs), "bw2 regs");
if (!par->regs)
goto out_release_fb;
if (!of_find_property(dp, "width", NULL)) {
err = bw2_do_default_mode(par, info, &linebytes);
if (err)
goto out_unmap_regs;
}
info->fix.smem_len = PAGE_ALIGN(linebytes * info->var.yres);
info->flags = FBINFO_DEFAULT;
info->fbops = &bw2_ops;
info->screen_base = of_ioremap(&op->resource[0], 0,
info->fix.smem_len, "bw2 ram");
if (!info->screen_base) {
err = -ENOMEM;
goto out_unmap_regs;
}
bw2_blank(FB_BLANK_UNBLANK, info);
bw2_init_fix(info, linebytes);
err = register_framebuffer(info);
if (err < 0)
goto out_unmap_screen;
dev_set_drvdata(&op->dev, info);
printk(KERN_INFO "%s: bwtwo at %lx:%lx\n",
dp->full_name, par->which_io, info->fix.smem_start);
return 0;
out_unmap_screen:
of_iounmap(&op->resource[0], info->screen_base, info->fix.smem_len);
out_unmap_regs:
of_iounmap(&op->resource[0], par->regs, sizeof(struct bw2_regs));
out_release_fb:
framebuffer_release(info);
out_err:
return err;
}
static int bw2_remove(struct platform_device *op)
{
struct fb_info *info = dev_get_drvdata(&op->dev);
struct bw2_par *par = info->par;
unregister_framebuffer(info);
of_iounmap(&op->resource[0], par->regs, sizeof(struct bw2_regs));
of_iounmap(&op->resource[0], info->screen_base, info->fix.smem_len);
framebuffer_release(info);
return 0;
}
static int __init bw2_init(void)
{
if (fb_get_options("bw2fb", NULL))
return -ENODEV;
return platform_driver_register(&bw2_driver);
}
static void __exit bw2_exit(void)
{
platform_driver_unregister(&bw2_driver);
}
