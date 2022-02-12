static int cg6_sync(struct fb_info *info)
{
struct cg6_par *par = (struct cg6_par *)info->par;
struct cg6_fbc __iomem *fbc = par->fbc;
int limit = 10000;
do {
if (!(sbus_readl(&fbc->s) & 0x10000000))
break;
udelay(10);
} while (--limit > 0);
return 0;
}
static void cg6_switch_from_graph(struct cg6_par *par)
{
struct cg6_thc __iomem *thc = par->thc;
unsigned long flags;
spin_lock_irqsave(&par->lock, flags);
sbus_writel(CG6_THC_CURSOFF, &thc->thc_cursxy);
spin_unlock_irqrestore(&par->lock, flags);
}
static int cg6_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct cg6_par *par = (struct cg6_par *)info->par;
cg6_switch_from_graph(par);
if (var->xoffset || var->yoffset || var->vmode)
return -EINVAL;
return 0;
}
static void cg6_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct cg6_par *par = (struct cg6_par *)info->par;
struct cg6_fbc __iomem *fbc = par->fbc;
unsigned long flags;
s32 val;
spin_lock_irqsave(&par->lock, flags);
cg6_sync(info);
sbus_writel(rect->color, &fbc->fg);
sbus_writel(~(u32)0, &fbc->pixelm);
sbus_writel(0xea80ff00, &fbc->alu);
sbus_writel(0, &fbc->s);
sbus_writel(0, &fbc->clip);
sbus_writel(~(u32)0, &fbc->pm);
sbus_writel(rect->dy, &fbc->arecty);
sbus_writel(rect->dx, &fbc->arectx);
sbus_writel(rect->dy + rect->height, &fbc->arecty);
sbus_writel(rect->dx + rect->width, &fbc->arectx);
do {
val = sbus_readl(&fbc->draw);
} while (val < 0 && (val & 0x20000000));
spin_unlock_irqrestore(&par->lock, flags);
}
static void cg6_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct cg6_par *par = (struct cg6_par *)info->par;
struct cg6_fbc __iomem *fbc = par->fbc;
unsigned long flags;
int i;
spin_lock_irqsave(&par->lock, flags);
cg6_sync(info);
sbus_writel(0xff, &fbc->fg);
sbus_writel(0x00, &fbc->bg);
sbus_writel(~0, &fbc->pixelm);
sbus_writel(0xe880cccc, &fbc->alu);
sbus_writel(0, &fbc->s);
sbus_writel(0, &fbc->clip);
sbus_writel(area->sy, &fbc->y0);
sbus_writel(area->sx, &fbc->x0);
sbus_writel(area->sy + area->height - 1, &fbc->y1);
sbus_writel(area->sx + area->width - 1, &fbc->x1);
sbus_writel(area->dy, &fbc->y2);
sbus_writel(area->dx, &fbc->x2);
sbus_writel(area->dy + area->height - 1, &fbc->y3);
sbus_writel(area->dx + area->width - 1, &fbc->x3);
do {
i = sbus_readl(&fbc->blit);
} while (i < 0 && (i & 0x20000000));
spin_unlock_irqrestore(&par->lock, flags);
}
static void cg6_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct cg6_par *par = (struct cg6_par *)info->par;
struct cg6_fbc __iomem *fbc = par->fbc;
const u8 *data = image->data;
unsigned long flags;
u32 x, y;
int i, width;
if (image->depth > 1) {
cfb_imageblit(info, image);
return;
}
spin_lock_irqsave(&par->lock, flags);
cg6_sync(info);
sbus_writel(image->fg_color, &fbc->fg);
sbus_writel(image->bg_color, &fbc->bg);
sbus_writel(0x140000, &fbc->mode);
sbus_writel(0xe880fc30, &fbc->alu);
sbus_writel(~(u32)0, &fbc->pixelm);
sbus_writel(0, &fbc->s);
sbus_writel(0, &fbc->clip);
sbus_writel(0xff, &fbc->pm);
sbus_writel(32, &fbc->incx);
sbus_writel(0, &fbc->incy);
x = image->dx;
y = image->dy;
for (i = 0; i < image->height; i++) {
width = image->width;
while (width >= 32) {
u32 val;
sbus_writel(y, &fbc->y0);
sbus_writel(x, &fbc->x0);
sbus_writel(x + 32 - 1, &fbc->x1);
val = ((u32)data[0] << 24) |
((u32)data[1] << 16) |
((u32)data[2] << 8) |
((u32)data[3] << 0);
sbus_writel(val, &fbc->font);
data += 4;
x += 32;
width -= 32;
}
if (width) {
u32 val;
sbus_writel(y, &fbc->y0);
sbus_writel(x, &fbc->x0);
sbus_writel(x + width - 1, &fbc->x1);
if (width <= 8) {
val = (u32) data[0] << 24;
data += 1;
} else if (width <= 16) {
val = ((u32) data[0] << 24) |
((u32) data[1] << 16);
data += 2;
} else {
val = ((u32) data[0] << 24) |
((u32) data[1] << 16) |
((u32) data[2] << 8);
data += 3;
}
sbus_writel(val, &fbc->font);
}
y += 1;
x = image->dx;
}
spin_unlock_irqrestore(&par->lock, flags);
}
static int cg6_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
struct cg6_par *par = (struct cg6_par *)info->par;
struct bt_regs __iomem *bt = par->bt;
unsigned long flags;
if (regno >= 256)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
spin_lock_irqsave(&par->lock, flags);
sbus_writel((u32)regno << 24, &bt->addr);
sbus_writel((u32)red << 24, &bt->color_map);
sbus_writel((u32)green << 24, &bt->color_map);
sbus_writel((u32)blue << 24, &bt->color_map);
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int cg6_blank(int blank, struct fb_info *info)
{
struct cg6_par *par = (struct cg6_par *)info->par;
struct cg6_thc __iomem *thc = par->thc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&par->lock, flags);
val = sbus_readl(&thc->thc_misc);
switch (blank) {
case FB_BLANK_UNBLANK:
val |= CG6_THC_MISC_VIDEO;
par->flags &= ~CG6_FLAG_BLANKED;
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
val &= ~CG6_THC_MISC_VIDEO;
par->flags |= CG6_FLAG_BLANKED;
break;
}
sbus_writel(val, &thc->thc_misc);
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int cg6_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct cg6_par *par = (struct cg6_par *)info->par;
return sbusfb_mmap_helper(cg6_mmap_map,
info->fix.smem_start, info->fix.smem_len,
par->which_io, vma);
}
static int cg6_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
return sbusfb_ioctl_helper(cmd, arg, info,
FBTYPE_SUNFAST_COLOR, 8, info->fix.smem_len);
}
static void __devinit cg6_init_fix(struct fb_info *info, int linebytes)
{
struct cg6_par *par = (struct cg6_par *)info->par;
const char *cg6_cpu_name, *cg6_card_name;
u32 conf;
conf = sbus_readl(par->fhc);
switch (conf & CG6_FHC_CPU_MASK) {
case CG6_FHC_CPU_SPARC:
cg6_cpu_name = "sparc";
break;
case CG6_FHC_CPU_68020:
cg6_cpu_name = "68020";
break;
default:
cg6_cpu_name = "i386";
break;
};
if (((conf >> CG6_FHC_REV_SHIFT) & CG6_FHC_REV_MASK) >= 11) {
if (info->fix.smem_len <= 0x100000)
cg6_card_name = "TGX";
else
cg6_card_name = "TGX+";
} else {
if (info->fix.smem_len <= 0x100000)
cg6_card_name = "GX";
else
cg6_card_name = "GX+";
}
sprintf(info->fix.id, "%s %s", cg6_card_name, cg6_cpu_name);
info->fix.id[sizeof(info->fix.id) - 1] = 0;
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.line_length = linebytes;
info->fix.accel = FB_ACCEL_SUN_CGSIX;
}
static void __devinit cg6_bt_init(struct cg6_par *par)
{
struct bt_regs __iomem *bt = par->bt;
sbus_writel(0x04 << 24, &bt->addr);
sbus_writel(0xff << 24, &bt->control);
sbus_writel(0x05 << 24, &bt->addr);
sbus_writel(0x00 << 24, &bt->control);
sbus_writel(0x06 << 24, &bt->addr);
sbus_writel(0x73 << 24, &bt->control);
sbus_writel(0x07 << 24, &bt->addr);
sbus_writel(0x00 << 24, &bt->control);
}
static void __devinit cg6_chip_init(struct fb_info *info)
{
struct cg6_par *par = (struct cg6_par *)info->par;
struct cg6_tec __iomem *tec = par->tec;
struct cg6_fbc __iomem *fbc = par->fbc;
struct cg6_thc __iomem *thc = par->thc;
u32 rev, conf, mode;
int i;
sbus_writel(CG6_THC_CURSOFF, &thc->thc_cursxy);
sbus_writel(0, &tec->tec_matrix);
sbus_writel(0, &tec->tec_clip);
sbus_writel(0, &tec->tec_vdc);
rev = (sbus_readl(par->fhc) >> CG6_FHC_REV_SHIFT) & CG6_FHC_REV_MASK;
if (rev < 5) {
conf = (sbus_readl(par->fhc) & CG6_FHC_RES_MASK) |
CG6_FHC_CPU_68020 | CG6_FHC_TEST |
(11 << CG6_FHC_TEST_X_SHIFT) |
(11 << CG6_FHC_TEST_Y_SHIFT);
if (rev < 2)
conf |= CG6_FHC_DST_DISABLE;
sbus_writel(conf, par->fhc);
}
mode = sbus_readl(&fbc->mode);
do {
i = sbus_readl(&fbc->s);
} while (i & 0x10000000);
mode &= ~(CG6_FBC_BLIT_MASK | CG6_FBC_MODE_MASK |
CG6_FBC_DRAW_MASK | CG6_FBC_BWRITE0_MASK |
CG6_FBC_BWRITE1_MASK | CG6_FBC_BREAD_MASK |
CG6_FBC_BDISP_MASK);
mode |= (CG6_FBC_BLIT_SRC | CG6_FBC_MODE_COLOR8 |
CG6_FBC_DRAW_RENDER | CG6_FBC_BWRITE0_ENABLE |
CG6_FBC_BWRITE1_DISABLE | CG6_FBC_BREAD_0 |
CG6_FBC_BDISP_0);
sbus_writel(mode, &fbc->mode);
sbus_writel(0, &fbc->clip);
sbus_writel(0, &fbc->offx);
sbus_writel(0, &fbc->offy);
sbus_writel(0, &fbc->clipminx);
sbus_writel(0, &fbc->clipminy);
sbus_writel(info->var.xres - 1, &fbc->clipmaxx);
sbus_writel(info->var.yres - 1, &fbc->clipmaxy);
}
static void cg6_unmap_regs(struct platform_device *op, struct fb_info *info,
struct cg6_par *par)
{
if (par->fbc)
of_iounmap(&op->resource[0], par->fbc, 4096);
if (par->tec)
of_iounmap(&op->resource[0], par->tec, sizeof(struct cg6_tec));
if (par->thc)
of_iounmap(&op->resource[0], par->thc, sizeof(struct cg6_thc));
if (par->bt)
of_iounmap(&op->resource[0], par->bt, sizeof(struct bt_regs));
if (par->fhc)
of_iounmap(&op->resource[0], par->fhc, sizeof(u32));
if (info->screen_base)
of_iounmap(&op->resource[0], info->screen_base,
info->fix.smem_len);
}
static int __devinit cg6_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct fb_info *info;
struct cg6_par *par;
int linebytes, err;
int dblbuf;
info = framebuffer_alloc(sizeof(struct cg6_par), &op->dev);
err = -ENOMEM;
if (!info)
goto out_err;
par = info->par;
spin_lock_init(&par->lock);
info->fix.smem_start = op->resource[0].start;
par->which_io = op->resource[0].flags & IORESOURCE_BITS;
sbusfb_fill_var(&info->var, dp, 8);
info->var.red.length = 8;
info->var.green.length = 8;
info->var.blue.length = 8;
linebytes = of_getintprop_default(dp, "linebytes",
info->var.xres);
info->fix.smem_len = PAGE_ALIGN(linebytes * info->var.yres);
dblbuf = of_getintprop_default(dp, "dblbuf", 0);
if (dblbuf)
info->fix.smem_len *= 4;
par->fbc = of_ioremap(&op->resource[0], CG6_FBC_OFFSET,
4096, "cgsix fbc");
par->tec = of_ioremap(&op->resource[0], CG6_TEC_OFFSET,
sizeof(struct cg6_tec), "cgsix tec");
par->thc = of_ioremap(&op->resource[0], CG6_THC_OFFSET,
sizeof(struct cg6_thc), "cgsix thc");
par->bt = of_ioremap(&op->resource[0], CG6_BROOKTREE_OFFSET,
sizeof(struct bt_regs), "cgsix dac");
par->fhc = of_ioremap(&op->resource[0], CG6_FHC_OFFSET,
sizeof(u32), "cgsix fhc");
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_IMAGEBLIT |
FBINFO_HWACCEL_COPYAREA | FBINFO_HWACCEL_FILLRECT |
FBINFO_READS_FAST;
info->fbops = &cg6_ops;
info->screen_base = of_ioremap(&op->resource[0], CG6_RAM_OFFSET,
info->fix.smem_len, "cgsix ram");
if (!par->fbc || !par->tec || !par->thc ||
!par->bt || !par->fhc || !info->screen_base)
goto out_unmap_regs;
info->var.accel_flags = FB_ACCELF_TEXT;
cg6_bt_init(par);
cg6_chip_init(info);
cg6_blank(FB_BLANK_UNBLANK, info);
if (fb_alloc_cmap(&info->cmap, 256, 0))
goto out_unmap_regs;
fb_set_cmap(&info->cmap, info);
cg6_init_fix(info, linebytes);
err = register_framebuffer(info);
if (err < 0)
goto out_dealloc_cmap;
dev_set_drvdata(&op->dev, info);
printk(KERN_INFO "%s: CGsix [%s] at %lx:%lx\n",
dp->full_name, info->fix.id,
par->which_io, info->fix.smem_start);
return 0;
out_dealloc_cmap:
fb_dealloc_cmap(&info->cmap);
out_unmap_regs:
cg6_unmap_regs(op, info, par);
framebuffer_release(info);
out_err:
return err;
}
static int __devexit cg6_remove(struct platform_device *op)
{
struct fb_info *info = dev_get_drvdata(&op->dev);
struct cg6_par *par = info->par;
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
cg6_unmap_regs(op, info, par);
framebuffer_release(info);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
static int __init cg6_init(void)
{
if (fb_get_options("cg6fb", NULL))
return -ENODEV;
return platform_driver_register(&cg6_driver);
}
static void __exit cg6_exit(void)
{
platform_driver_unregister(&cg6_driver);
}
