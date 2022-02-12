static int cg3_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
struct cg3_par *par = (struct cg3_par *) info->par;
struct bt_regs __iomem *bt = &par->regs->cmap;
unsigned long flags;
u32 *p32;
u8 *p8;
int count;
if (regno >= 256)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
spin_lock_irqsave(&par->lock, flags);
p8 = (u8 *)par->sw_cmap + (regno * 3);
p8[0] = red;
p8[1] = green;
p8[2] = blue;
#define D4M3(x) ((((x)>>2)<<1) + ((x)>>2))
#define D4M4(x) ((x)&~0x3)
count = 3;
p32 = &par->sw_cmap[D4M3(regno)];
sbus_writel(D4M4(regno), &bt->addr);
while (count--)
sbus_writel(*p32++, &bt->color_map);
#undef D4M3
#undef D4M4
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int cg3_blank(int blank, struct fb_info *info)
{
struct cg3_par *par = (struct cg3_par *) info->par;
struct cg3_regs __iomem *regs = par->regs;
unsigned long flags;
u8 val;
spin_lock_irqsave(&par->lock, flags);
switch (blank) {
case FB_BLANK_UNBLANK:
val = sbus_readb(&regs->control);
val |= CG3_CR_ENABLE_VIDEO;
sbus_writeb(val, &regs->control);
par->flags &= ~CG3_FLAG_BLANKED;
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
val = sbus_readb(&regs->control);
val &= ~CG3_CR_ENABLE_VIDEO;
sbus_writeb(val, &regs->control);
par->flags |= CG3_FLAG_BLANKED;
break;
}
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int cg3_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct cg3_par *par = (struct cg3_par *)info->par;
return sbusfb_mmap_helper(cg3_mmap_map,
info->fix.smem_start, info->fix.smem_len,
par->which_io,
vma);
}
static int cg3_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
return sbusfb_ioctl_helper(cmd, arg, info,
FBTYPE_SUN3COLOR, 8, info->fix.smem_len);
}
static void cg3_init_fix(struct fb_info *info, int linebytes,
struct device_node *dp)
{
strlcpy(info->fix.id, dp->name, sizeof(info->fix.id));
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.line_length = linebytes;
info->fix.accel = FB_ACCEL_SUN_CGTHREE;
}
static void cg3_rdi_maybe_fixup_var(struct fb_var_screeninfo *var,
struct device_node *dp)
{
const char *params;
char *p;
int ww, hh;
params = of_get_property(dp, "params", NULL);
if (params) {
ww = simple_strtoul(params, &p, 10);
if (ww && *p == 'x') {
hh = simple_strtoul(p + 1, &p, 10);
if (hh && *p == '-') {
if (var->xres != ww ||
var->yres != hh) {
var->xres = var->xres_virtual = ww;
var->yres = var->yres_virtual = hh;
}
}
}
}
}
static int cg3_do_default_mode(struct cg3_par *par)
{
enum cg3_type type;
u8 *p;
if (par->flags & CG3_FLAG_RDI)
type = CG3_RDI;
else {
u8 status = sbus_readb(&par->regs->status), mon;
if ((status & CG3_SR_ID_MASK) == CG3_SR_ID_COLOR) {
mon = status & CG3_SR_RES_MASK;
if (mon == CG3_SR_1152_900_76_A ||
mon == CG3_SR_1152_900_76_B)
type = CG3_AT_76HZ;
else
type = CG3_AT_66HZ;
} else {
printk(KERN_ERR "cgthree: can't handle SR %02x\n",
status);
return -EINVAL;
}
}
for (p = cg3_regvals[type]; *p; p += 2) {
u8 __iomem *regp = &((u8 __iomem *)par->regs)[p[0]];
sbus_writeb(p[1], regp);
}
for (p = cg3_dacvals; *p; p += 2) {
u8 __iomem *regp;
regp = (u8 __iomem *)&par->regs->cmap.addr;
sbus_writeb(p[0], regp);
regp = (u8 __iomem *)&par->regs->cmap.control;
sbus_writeb(p[1], regp);
}
return 0;
}
static int cg3_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct fb_info *info;
struct cg3_par *par;
int linebytes, err;
info = framebuffer_alloc(sizeof(struct cg3_par), &op->dev);
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
if (!strcmp(dp->name, "cgRDI"))
par->flags |= CG3_FLAG_RDI;
if (par->flags & CG3_FLAG_RDI)
cg3_rdi_maybe_fixup_var(&info->var, dp);
linebytes = of_getintprop_default(dp, "linebytes",
info->var.xres);
info->fix.smem_len = PAGE_ALIGN(linebytes * info->var.yres);
par->regs = of_ioremap(&op->resource[0], CG3_REGS_OFFSET,
sizeof(struct cg3_regs), "cg3 regs");
if (!par->regs)
goto out_release_fb;
info->flags = FBINFO_DEFAULT;
info->fbops = &cg3_ops;
info->screen_base = of_ioremap(&op->resource[0], CG3_RAM_OFFSET,
info->fix.smem_len, "cg3 ram");
if (!info->screen_base)
goto out_unmap_regs;
cg3_blank(FB_BLANK_UNBLANK, info);
if (!of_find_property(dp, "width", NULL)) {
err = cg3_do_default_mode(par);
if (err)
goto out_unmap_screen;
}
err = fb_alloc_cmap(&info->cmap, 256, 0);
if (err)
goto out_unmap_screen;
fb_set_cmap(&info->cmap, info);
cg3_init_fix(info, linebytes, dp);
err = register_framebuffer(info);
if (err < 0)
goto out_dealloc_cmap;
dev_set_drvdata(&op->dev, info);
printk(KERN_INFO "%pOF: cg3 at %lx:%lx\n",
dp, par->which_io, info->fix.smem_start);
return 0;
out_dealloc_cmap:
fb_dealloc_cmap(&info->cmap);
out_unmap_screen:
of_iounmap(&op->resource[0], info->screen_base, info->fix.smem_len);
out_unmap_regs:
of_iounmap(&op->resource[0], par->regs, sizeof(struct cg3_regs));
out_release_fb:
framebuffer_release(info);
out_err:
return err;
}
static int cg3_remove(struct platform_device *op)
{
struct fb_info *info = dev_get_drvdata(&op->dev);
struct cg3_par *par = info->par;
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
of_iounmap(&op->resource[0], par->regs, sizeof(struct cg3_regs));
of_iounmap(&op->resource[0], info->screen_base, info->fix.smem_len);
framebuffer_release(info);
return 0;
}
static int __init cg3_init(void)
{
if (fb_get_options("cg3fb", NULL))
return -ENODEV;
return platform_driver_register(&cg3_driver);
}
static void __exit cg3_exit(void)
{
platform_driver_unregister(&cg3_driver);
}
