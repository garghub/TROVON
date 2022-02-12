static void FFBFifo(struct ffb_par *par, int n)
{
struct ffb_fbc __iomem *fbc;
int cache = par->fifo_cache;
if (cache - n < 0) {
fbc = par->fbc;
do {
cache = (upa_readl(&fbc->ucsr) & FFB_UCSR_FIFO_MASK);
cache -= 8;
} while (cache - n < 0);
}
par->fifo_cache = cache - n;
}
static void FFBWait(struct ffb_par *par)
{
struct ffb_fbc __iomem *fbc;
int limit = 10000;
fbc = par->fbc;
do {
if ((upa_readl(&fbc->ucsr) & FFB_UCSR_ALL_BUSY) == 0)
break;
if ((upa_readl(&fbc->ucsr) & FFB_UCSR_ALL_ERRORS) != 0) {
upa_writel(FFB_UCSR_ALL_ERRORS, &fbc->ucsr);
}
udelay(10);
} while (--limit > 0);
}
static int ffb_sync(struct fb_info *p)
{
struct ffb_par *par = (struct ffb_par *)p->par;
FFBWait(par);
return 0;
}
static __inline__ void ffb_rop(struct ffb_par *par, u32 rop)
{
if (par->rop_cache != rop) {
FFBFifo(par, 1);
upa_writel(rop, &par->fbc->rop);
par->rop_cache = rop;
}
}
static void ffb_switch_from_graph(struct ffb_par *par)
{
struct ffb_fbc __iomem *fbc = par->fbc;
struct ffb_dac __iomem *dac = par->dac;
unsigned long flags;
spin_lock_irqsave(&par->lock, flags);
FFBWait(par);
par->fifo_cache = 0;
FFBFifo(par, 7);
upa_writel(FFB_PPC_VCE_DISABLE | FFB_PPC_TBE_OPAQUE |
FFB_PPC_APE_DISABLE | FFB_PPC_CS_CONST,
&fbc->ppc);
upa_writel(0x2000707f, &fbc->fbc);
upa_writel(par->rop_cache, &fbc->rop);
upa_writel(0xffffffff, &fbc->pmask);
upa_writel((1 << 16) | (0 << 0), &fbc->fontinc);
upa_writel(par->fg_cache, &fbc->fg);
upa_writel(par->bg_cache, &fbc->bg);
FFBWait(par);
upa_writel(FFB_DAC_CUR_CTRL, &dac->type2);
if (par->flags & FFB_FLAG_INVCURSOR)
upa_writel(0, &dac->value2);
else
upa_writel((FFB_DAC_CUR_CTRL_P0 |
FFB_DAC_CUR_CTRL_P1), &dac->value2);
spin_unlock_irqrestore(&par->lock, flags);
}
static int ffb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct ffb_par *par = (struct ffb_par *)info->par;
ffb_switch_from_graph(par);
if (var->xoffset || var->yoffset || var->vmode)
return -EINVAL;
return 0;
}
static void ffb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
struct ffb_par *par = (struct ffb_par *)info->par;
struct ffb_fbc __iomem *fbc = par->fbc;
unsigned long flags;
u32 fg;
BUG_ON(rect->rop != ROP_COPY && rect->rop != ROP_XOR);
fg = ((u32 *)info->pseudo_palette)[rect->color];
spin_lock_irqsave(&par->lock, flags);
if (fg != par->fg_cache) {
FFBFifo(par, 1);
upa_writel(fg, &fbc->fg);
par->fg_cache = fg;
}
ffb_rop(par, rect->rop == ROP_COPY ?
FFB_ROP_NEW :
FFB_ROP_NEW_XOR_OLD);
FFBFifo(par, 5);
upa_writel(FFB_DRAWOP_RECTANGLE, &fbc->drawop);
upa_writel(rect->dy, &fbc->by);
upa_writel(rect->dx, &fbc->bx);
upa_writel(rect->height, &fbc->bh);
upa_writel(rect->width, &fbc->bw);
spin_unlock_irqrestore(&par->lock, flags);
}
static void ffb_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
struct ffb_par *par = (struct ffb_par *)info->par;
struct ffb_fbc __iomem *fbc = par->fbc;
unsigned long flags;
if (area->dx != area->sx ||
area->dy == area->sy) {
cfb_copyarea(info, area);
return;
}
spin_lock_irqsave(&par->lock, flags);
ffb_rop(par, FFB_ROP_OLD);
FFBFifo(par, 7);
upa_writel(FFB_DRAWOP_VSCROLL, &fbc->drawop);
upa_writel(area->sy, &fbc->by);
upa_writel(area->sx, &fbc->bx);
upa_writel(area->dy, &fbc->dy);
upa_writel(area->dx, &fbc->dx);
upa_writel(area->height, &fbc->bh);
upa_writel(area->width, &fbc->bw);
spin_unlock_irqrestore(&par->lock, flags);
}
static void ffb_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct ffb_par *par = (struct ffb_par *)info->par;
struct ffb_fbc __iomem *fbc = par->fbc;
const u8 *data = image->data;
unsigned long flags;
u32 fg, bg, xy;
u64 fgbg;
int i, width, stride;
if (image->depth > 1) {
cfb_imageblit(info, image);
return;
}
fg = ((u32 *)info->pseudo_palette)[image->fg_color];
bg = ((u32 *)info->pseudo_palette)[image->bg_color];
fgbg = ((u64) fg << 32) | (u64) bg;
xy = (image->dy << 16) | image->dx;
width = image->width;
stride = ((width + 7) >> 3);
spin_lock_irqsave(&par->lock, flags);
if (fgbg != *(u64 *)&par->fg_cache) {
FFBFifo(par, 2);
upa_writeq(fgbg, &fbc->fg);
*(u64 *)&par->fg_cache = fgbg;
}
if (width >= 32) {
FFBFifo(par, 1);
upa_writel(32, &fbc->fontw);
}
while (width >= 32) {
const u8 *next_data = data + 4;
FFBFifo(par, 1);
upa_writel(xy, &fbc->fontxy);
xy += (32 << 0);
for (i = 0; i < image->height; i++) {
u32 val = (((u32)data[0] << 24) |
((u32)data[1] << 16) |
((u32)data[2] << 8) |
((u32)data[3] << 0));
FFBFifo(par, 1);
upa_writel(val, &fbc->font);
data += stride;
}
data = next_data;
width -= 32;
}
if (width) {
FFBFifo(par, 2);
upa_writel(width, &fbc->fontw);
upa_writel(xy, &fbc->fontxy);
for (i = 0; i < image->height; i++) {
u32 val = (((u32)data[0] << 24) |
((u32)data[1] << 16) |
((u32)data[2] << 8) |
((u32)data[3] << 0));
FFBFifo(par, 1);
upa_writel(val, &fbc->font);
data += stride;
}
}
spin_unlock_irqrestore(&par->lock, flags);
}
static void ffb_fixup_var_rgb(struct fb_var_screeninfo *var)
{
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 16;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
}
static int ffb_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
u32 value;
if (regno >= 16)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
value = (blue << 16) | (green << 8) | red;
((u32 *)info->pseudo_palette)[regno] = value;
return 0;
}
static int ffb_blank(int blank, struct fb_info *info)
{
struct ffb_par *par = (struct ffb_par *)info->par;
struct ffb_dac __iomem *dac = par->dac;
unsigned long flags;
u32 val;
int i;
spin_lock_irqsave(&par->lock, flags);
FFBWait(par);
upa_writel(FFB_DAC_TGEN, &dac->type);
val = upa_readl(&dac->value);
switch (blank) {
case FB_BLANK_UNBLANK:
val |= FFB_DAC_TGEN_VIDE;
par->flags &= ~FFB_FLAG_BLANKED;
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
val &= ~FFB_DAC_TGEN_VIDE;
par->flags |= FFB_FLAG_BLANKED;
break;
}
upa_writel(FFB_DAC_TGEN, &dac->type);
upa_writel(val, &dac->value);
for (i = 0; i < 10; i++) {
upa_writel(FFB_DAC_TGEN, &dac->type);
upa_readl(&dac->value);
}
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int ffb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct ffb_par *par = (struct ffb_par *)info->par;
return sbusfb_mmap_helper(ffb_mmap_map,
par->physbase, par->fbsize,
0, vma);
}
static int ffb_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
struct ffb_par *par = (struct ffb_par *)info->par;
return sbusfb_ioctl_helper(cmd, arg, info,
FBTYPE_CREATOR, 24, par->fbsize);
}
static void ffb_init_fix(struct fb_info *info)
{
struct ffb_par *par = (struct ffb_par *)info->par;
const char *ffb_type_name;
if (!(par->flags & FFB_FLAG_AFB)) {
if ((par->board_type & 0x7) == 0x3)
ffb_type_name = "Creator 3D";
else
ffb_type_name = "Creator";
} else
ffb_type_name = "Elite 3D";
strlcpy(info->fix.id, ffb_type_name, sizeof(info->fix.id));
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->fix.line_length = 8192;
info->fix.accel = FB_ACCEL_SUN_CREATOR;
}
static int ffb_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct ffb_fbc __iomem *fbc;
struct ffb_dac __iomem *dac;
struct fb_info *info;
struct ffb_par *par;
u32 dac_pnum, dac_rev, dac_mrev;
int err;
info = framebuffer_alloc(sizeof(struct ffb_par), &op->dev);
err = -ENOMEM;
if (!info)
goto out_err;
par = info->par;
spin_lock_init(&par->lock);
par->fbc = of_ioremap(&op->resource[2], 0,
sizeof(struct ffb_fbc), "ffb fbc");
if (!par->fbc)
goto out_release_fb;
par->dac = of_ioremap(&op->resource[1], 0,
sizeof(struct ffb_dac), "ffb dac");
if (!par->dac)
goto out_unmap_fbc;
par->rop_cache = FFB_ROP_NEW;
par->physbase = op->resource[0].start;
info->flags = (FBINFO_DEFAULT |
FBINFO_HWACCEL_FILLRECT |
FBINFO_HWACCEL_IMAGEBLIT);
info->fbops = &ffb_ops;
info->screen_base = (char *) par->physbase + FFB_DFB24_POFF;
info->pseudo_palette = par->pseudo_palette;
sbusfb_fill_var(&info->var, dp, 32);
par->fbsize = PAGE_ALIGN(info->var.xres * info->var.yres * 4);
ffb_fixup_var_rgb(&info->var);
info->var.accel_flags = FB_ACCELF_TEXT;
if (!strcmp(dp->name, "SUNW,afb"))
par->flags |= FFB_FLAG_AFB;
par->board_type = of_getintprop_default(dp, "board_type", 0);
fbc = par->fbc;
if ((upa_readl(&fbc->ucsr) & FFB_UCSR_ALL_ERRORS) != 0)
upa_writel(FFB_UCSR_ALL_ERRORS, &fbc->ucsr);
dac = par->dac;
upa_writel(FFB_DAC_DID, &dac->type);
dac_pnum = upa_readl(&dac->value);
dac_rev = (dac_pnum & FFB_DAC_DID_REV) >> FFB_DAC_DID_REV_SHIFT;
dac_pnum = (dac_pnum & FFB_DAC_DID_PNUM) >> FFB_DAC_DID_PNUM_SHIFT;
upa_writel(FFB_DAC_UCTRL, &dac->type);
dac_mrev = upa_readl(&dac->value);
dac_mrev = (dac_mrev & FFB_DAC_UCTRL_MANREV) >>
FFB_DAC_UCTRL_MANREV_SHIFT;
if ((par->flags & FFB_FLAG_AFB) || dac_pnum == 0x236e) {
par->flags &= ~FFB_FLAG_INVCURSOR;
} else {
if (dac_mrev < 3)
par->flags |= FFB_FLAG_INVCURSOR;
}
ffb_switch_from_graph(par);
ffb_blank(FB_BLANK_UNBLANK, info);
if (fb_alloc_cmap(&info->cmap, 256, 0))
goto out_unmap_dac;
ffb_init_fix(info);
err = register_framebuffer(info);
if (err < 0)
goto out_dealloc_cmap;
dev_set_drvdata(&op->dev, info);
printk(KERN_INFO "%s: %s at %016lx, type %d, "
"DAC pnum[%x] rev[%d] manuf_rev[%d]\n",
dp->full_name,
((par->flags & FFB_FLAG_AFB) ? "AFB" : "FFB"),
par->physbase, par->board_type,
dac_pnum, dac_rev, dac_mrev);
return 0;
out_dealloc_cmap:
fb_dealloc_cmap(&info->cmap);
out_unmap_dac:
of_iounmap(&op->resource[1], par->dac, sizeof(struct ffb_dac));
out_unmap_fbc:
of_iounmap(&op->resource[2], par->fbc, sizeof(struct ffb_fbc));
out_release_fb:
framebuffer_release(info);
out_err:
return err;
}
static int ffb_remove(struct platform_device *op)
{
struct fb_info *info = dev_get_drvdata(&op->dev);
struct ffb_par *par = info->par;
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
of_iounmap(&op->resource[2], par->fbc, sizeof(struct ffb_fbc));
of_iounmap(&op->resource[1], par->dac, sizeof(struct ffb_dac));
framebuffer_release(info);
return 0;
}
static int __init ffb_init(void)
{
if (fb_get_options("ffb", NULL))
return -ENODEV;
return platform_driver_register(&ffb_driver);
}
static void __exit ffb_exit(void)
{
platform_driver_unregister(&ffb_driver);
}
