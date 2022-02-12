static void __cg14_reset(struct cg14_par *par)
{
struct cg14_regs __iomem *regs = par->regs;
u8 val;
val = sbus_readb(&regs->mcr);
val &= ~(CG14_MCR_PIXMODE_MASK);
sbus_writeb(val, &regs->mcr);
}
static int cg14_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct cg14_par *par = (struct cg14_par *) info->par;
unsigned long flags;
spin_lock_irqsave(&par->lock, flags);
__cg14_reset(par);
spin_unlock_irqrestore(&par->lock, flags);
if (var->xoffset || var->yoffset || var->vmode)
return -EINVAL;
return 0;
}
static int cg14_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
struct cg14_par *par = (struct cg14_par *) info->par;
struct cg14_clut __iomem *clut = par->clut;
unsigned long flags;
u32 val;
if (regno >= 256)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
val = (red | (green << 8) | (blue << 16));
spin_lock_irqsave(&par->lock, flags);
sbus_writel(val, &clut->c_clut[regno]);
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int cg14_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct cg14_par *par = (struct cg14_par *) info->par;
return sbusfb_mmap_helper(par->mmap_map,
info->fix.smem_start, info->fix.smem_len,
par->iospace, vma);
}
static int cg14_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
struct cg14_par *par = (struct cg14_par *) info->par;
struct cg14_regs __iomem *regs = par->regs;
struct mdi_cfginfo kmdi, __user *mdii;
unsigned long flags;
int cur_mode, mode, ret = 0;
switch (cmd) {
case MDI_RESET:
spin_lock_irqsave(&par->lock, flags);
__cg14_reset(par);
spin_unlock_irqrestore(&par->lock, flags);
break;
case MDI_GET_CFGINFO:
memset(&kmdi, 0, sizeof(kmdi));
spin_lock_irqsave(&par->lock, flags);
kmdi.mdi_type = FBTYPE_MDICOLOR;
kmdi.mdi_height = info->var.yres;
kmdi.mdi_width = info->var.xres;
kmdi.mdi_mode = par->mode;
kmdi.mdi_pixfreq = 72;
kmdi.mdi_size = par->ramsize;
spin_unlock_irqrestore(&par->lock, flags);
mdii = (struct mdi_cfginfo __user *) arg;
if (copy_to_user(mdii, &kmdi, sizeof(kmdi)))
ret = -EFAULT;
break;
case MDI_SET_PIXELMODE:
if (get_user(mode, (int __user *) arg)) {
ret = -EFAULT;
break;
}
spin_lock_irqsave(&par->lock, flags);
cur_mode = sbus_readb(&regs->mcr);
cur_mode &= ~CG14_MCR_PIXMODE_MASK;
switch(mode) {
case MDI_32_PIX:
cur_mode |= (CG14_MCR_PIXMODE_32 <<
CG14_MCR_PIXMODE_SHIFT);
break;
case MDI_16_PIX:
cur_mode |= (CG14_MCR_PIXMODE_16 <<
CG14_MCR_PIXMODE_SHIFT);
break;
case MDI_8_PIX:
break;
default:
ret = -ENOSYS;
break;
};
if (!ret) {
sbus_writeb(cur_mode, &regs->mcr);
par->mode = mode;
}
spin_unlock_irqrestore(&par->lock, flags);
break;
default:
ret = sbusfb_ioctl_helper(cmd, arg, info,
FBTYPE_MDICOLOR, 8,
info->fix.smem_len);
break;
};
return ret;
}
static void cg14_init_fix(struct fb_info *info, int linebytes,
struct device_node *dp)
{
const char *name = dp->name;
strlcpy(info->fix.id, name, sizeof(info->fix.id));
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.line_length = linebytes;
info->fix.accel = FB_ACCEL_SUN_CG14;
}
static void cg14_unmap_regs(struct platform_device *op, struct fb_info *info,
struct cg14_par *par)
{
if (par->regs)
of_iounmap(&op->resource[0],
par->regs, sizeof(struct cg14_regs));
if (par->clut)
of_iounmap(&op->resource[0],
par->clut, sizeof(struct cg14_clut));
if (par->cursor)
of_iounmap(&op->resource[0],
par->cursor, sizeof(struct cg14_cursor));
if (info->screen_base)
of_iounmap(&op->resource[1],
info->screen_base, info->fix.smem_len);
}
static int cg14_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct fb_info *info;
struct cg14_par *par;
int is_8mb, linebytes, i, err;
info = framebuffer_alloc(sizeof(struct cg14_par), &op->dev);
err = -ENOMEM;
if (!info)
goto out_err;
par = info->par;
spin_lock_init(&par->lock);
sbusfb_fill_var(&info->var, dp, 8);
info->var.red.length = 8;
info->var.green.length = 8;
info->var.blue.length = 8;
linebytes = of_getintprop_default(dp, "linebytes",
info->var.xres);
info->fix.smem_len = PAGE_ALIGN(linebytes * info->var.yres);
if (!strcmp(dp->parent->name, "sbus") ||
!strcmp(dp->parent->name, "sbi")) {
info->fix.smem_start = op->resource[0].start;
par->iospace = op->resource[0].flags & IORESOURCE_BITS;
} else {
info->fix.smem_start = op->resource[1].start;
par->iospace = op->resource[0].flags & IORESOURCE_BITS;
}
par->regs = of_ioremap(&op->resource[0], 0,
sizeof(struct cg14_regs), "cg14 regs");
par->clut = of_ioremap(&op->resource[0], CG14_CLUT1,
sizeof(struct cg14_clut), "cg14 clut");
par->cursor = of_ioremap(&op->resource[0], CG14_CURSORREGS,
sizeof(struct cg14_cursor), "cg14 cursor");
info->screen_base = of_ioremap(&op->resource[1], 0,
info->fix.smem_len, "cg14 ram");
if (!par->regs || !par->clut || !par->cursor || !info->screen_base)
goto out_unmap_regs;
is_8mb = (((op->resource[1].end - op->resource[1].start) + 1) ==
(8 * 1024 * 1024));
BUILD_BUG_ON(sizeof(par->mmap_map) != sizeof(__cg14_mmap_map));
memcpy(&par->mmap_map, &__cg14_mmap_map, sizeof(par->mmap_map));
for (i = 0; i < CG14_MMAP_ENTRIES; i++) {
struct sbus_mmap_map *map = &par->mmap_map[i];
if (!map->size)
break;
if (map->poff & 0x80000000)
map->poff = (map->poff & 0x7fffffff) +
(op->resource[0].start -
op->resource[1].start);
if (is_8mb &&
map->size >= 0x100000 &&
map->size <= 0x400000)
map->size *= 2;
}
par->mode = MDI_8_PIX;
par->ramsize = (is_8mb ? 0x800000 : 0x400000);
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
info->fbops = &cg14_ops;
__cg14_reset(par);
if (fb_alloc_cmap(&info->cmap, 256, 0))
goto out_unmap_regs;
fb_set_cmap(&info->cmap, info);
cg14_init_fix(info, linebytes, dp);
err = register_framebuffer(info);
if (err < 0)
goto out_dealloc_cmap;
dev_set_drvdata(&op->dev, info);
printk(KERN_INFO "%s: cgfourteen at %lx:%lx, %dMB\n",
dp->full_name,
par->iospace, info->fix.smem_start,
par->ramsize >> 20);
return 0;
out_dealloc_cmap:
fb_dealloc_cmap(&info->cmap);
out_unmap_regs:
cg14_unmap_regs(op, info, par);
framebuffer_release(info);
out_err:
return err;
}
static int cg14_remove(struct platform_device *op)
{
struct fb_info *info = dev_get_drvdata(&op->dev);
struct cg14_par *par = info->par;
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
cg14_unmap_regs(op, info, par);
framebuffer_release(info);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
static int __init cg14_init(void)
{
if (fb_get_options("cg14fb", NULL))
return -ENODEV;
return platform_driver_register(&cg14_driver);
}
static void __exit cg14_exit(void)
{
platform_driver_unregister(&cg14_driver);
}
