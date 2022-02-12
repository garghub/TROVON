static int p9100_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
struct p9100_par *par = (struct p9100_par *) info->par;
struct p9100_regs __iomem *regs = par->regs;
unsigned long flags;
if (regno >= 256)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
spin_lock_irqsave(&par->lock, flags);
sbus_writel((regno << 16), &regs->ramdac_cmap_wridx);
sbus_writel((red << 16), &regs->ramdac_palette_data);
sbus_writel((green << 16), &regs->ramdac_palette_data);
sbus_writel((blue << 16), &regs->ramdac_palette_data);
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int
p9100_blank(int blank, struct fb_info *info)
{
struct p9100_par *par = (struct p9100_par *) info->par;
struct p9100_regs __iomem *regs = par->regs;
unsigned long flags;
u32 val;
spin_lock_irqsave(&par->lock, flags);
switch (blank) {
case FB_BLANK_UNBLANK:
val = sbus_readl(&regs->vid_screenpaint_timectl1);
val |= SCREENPAINT_TIMECTL1_ENABLE_VIDEO;
sbus_writel(val, &regs->vid_screenpaint_timectl1);
par->flags &= ~P9100_FLAG_BLANKED;
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
val = sbus_readl(&regs->vid_screenpaint_timectl1);
val &= ~SCREENPAINT_TIMECTL1_ENABLE_VIDEO;
sbus_writel(val, &regs->vid_screenpaint_timectl1);
par->flags |= P9100_FLAG_BLANKED;
break;
}
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int p9100_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct p9100_par *par = (struct p9100_par *)info->par;
return sbusfb_mmap_helper(p9100_mmap_map,
info->fix.smem_start, info->fix.smem_len,
par->which_io, vma);
}
static int p9100_ioctl(struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
return sbusfb_ioctl_helper(cmd, arg, info,
FBTYPE_SUN3COLOR, 8, info->fix.smem_len);
}
static void p9100_init_fix(struct fb_info *info, int linebytes, struct device_node *dp)
{
strlcpy(info->fix.id, dp->name, sizeof(info->fix.id));
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.line_length = linebytes;
info->fix.accel = FB_ACCEL_SUN_CGTHREE;
}
static int __devinit p9100_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct fb_info *info;
struct p9100_par *par;
int linebytes, err;
info = framebuffer_alloc(sizeof(struct p9100_par), &op->dev);
err = -ENOMEM;
if (!info)
goto out_err;
par = info->par;
spin_lock_init(&par->lock);
info->fix.smem_start = op->resource[2].start;
par->which_io = op->resource[2].flags & IORESOURCE_BITS;
sbusfb_fill_var(&info->var, dp, 8);
info->var.red.length = 8;
info->var.green.length = 8;
info->var.blue.length = 8;
linebytes = of_getintprop_default(dp, "linebytes", info->var.xres);
info->fix.smem_len = PAGE_ALIGN(linebytes * info->var.yres);
par->regs = of_ioremap(&op->resource[0], 0,
sizeof(struct p9100_regs), "p9100 regs");
if (!par->regs)
goto out_release_fb;
info->flags = FBINFO_DEFAULT;
info->fbops = &p9100_ops;
info->screen_base = of_ioremap(&op->resource[2], 0,
info->fix.smem_len, "p9100 ram");
if (!info->screen_base)
goto out_unmap_regs;
p9100_blank(FB_BLANK_UNBLANK, info);
if (fb_alloc_cmap(&info->cmap, 256, 0))
goto out_unmap_screen;
p9100_init_fix(info, linebytes, dp);
err = register_framebuffer(info);
if (err < 0)
goto out_dealloc_cmap;
fb_set_cmap(&info->cmap, info);
dev_set_drvdata(&op->dev, info);
printk(KERN_INFO "%s: p9100 at %lx:%lx\n",
dp->full_name,
par->which_io, info->fix.smem_start);
return 0;
out_dealloc_cmap:
fb_dealloc_cmap(&info->cmap);
out_unmap_screen:
of_iounmap(&op->resource[2], info->screen_base, info->fix.smem_len);
out_unmap_regs:
of_iounmap(&op->resource[0], par->regs, sizeof(struct p9100_regs));
out_release_fb:
framebuffer_release(info);
out_err:
return err;
}
static int __devexit p9100_remove(struct platform_device *op)
{
struct fb_info *info = dev_get_drvdata(&op->dev);
struct p9100_par *par = info->par;
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
of_iounmap(&op->resource[0], par->regs, sizeof(struct p9100_regs));
of_iounmap(&op->resource[2], info->screen_base, info->fix.smem_len);
framebuffer_release(info);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
static int __init p9100_init(void)
{
if (fb_get_options("p9100fb", NULL))
return -ENODEV;
return platform_driver_register(&p9100_driver);
}
static void __exit p9100_exit(void)
{
platform_driver_unregister(&p9100_driver);
}
