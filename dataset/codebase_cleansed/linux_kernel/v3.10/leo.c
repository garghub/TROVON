static void leo_wait(struct leo_lx_krn __iomem *lx_krn)
{
int i;
for (i = 0;
(sbus_readl(&lx_krn->krn_csr) & LEO_KRN_CSR_PROGRESS) &&
i < 300000;
i++)
udelay(1);
return;
}
static void leo_switch_from_graph(struct fb_info *info)
{
struct leo_par *par = (struct leo_par *) info->par;
struct leo_ld_ss0 __iomem *ss = par->ld_ss0;
struct leo_cursor __iomem *cursor = par->cursor;
unsigned long flags;
u32 val;
spin_lock_irqsave(&par->lock, flags);
par->extent = ((info->var.xres - 1) |
((info->var.yres - 1) << 16));
sbus_writel(0xffffffff, &ss->wid);
sbus_writel(0xffff, &ss->wmask);
sbus_writel(0, &ss->vclipmin);
sbus_writel(par->extent, &ss->vclipmax);
sbus_writel(0, &ss->fg);
sbus_writel(0xff000000, &ss->planemask);
sbus_writel(0x310850, &ss->rop);
sbus_writel(0, &ss->widclip);
sbus_writel((info->var.xres-1) | ((info->var.yres-1) << 11),
&par->lc_ss0_usr->extent);
sbus_writel(4, &par->lc_ss0_usr->addrspace);
sbus_writel(0x80000000, &par->lc_ss0_usr->fill);
sbus_writel(0, &par->lc_ss0_usr->fontt);
do {
val = sbus_readl(&par->lc_ss0_usr->csr);
} while (val & 0x20000000);
sbus_writel(1, &ss->wid);
sbus_writel(0x00ffffff, &ss->planemask);
sbus_writel(0x310b90, &ss->rop);
sbus_writel(0, &par->lc_ss0_usr->addrspace);
sbus_writel(sbus_readl(&cursor->cur_misc) & ~LEO_CUR_ENABLE, &cursor->cur_misc);
spin_unlock_irqrestore(&par->lock, flags);
}
static int leo_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
leo_switch_from_graph(info);
if (var->xoffset || var->yoffset || var->vmode)
return -EINVAL;
return 0;
}
static int leo_setcolreg(unsigned regno,
unsigned red, unsigned green, unsigned blue,
unsigned transp, struct fb_info *info)
{
struct leo_par *par = (struct leo_par *) info->par;
struct leo_lx_krn __iomem *lx_krn = par->lx_krn;
unsigned long flags;
u32 val;
int i;
if (regno >= 256)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
par->clut_data[regno] = red | (green << 8) | (blue << 16);
spin_lock_irqsave(&par->lock, flags);
leo_wait(lx_krn);
sbus_writel(LEO_KRN_TYPE_CLUTDATA, &lx_krn->krn_type);
for (i = 0; i < 256; i++)
sbus_writel(par->clut_data[i], &lx_krn->krn_value);
sbus_writel(LEO_KRN_TYPE_CLUT0, &lx_krn->krn_type);
val = sbus_readl(&lx_krn->krn_csr);
val |= (LEO_KRN_CSR_UNK | LEO_KRN_CSR_UNK2);
sbus_writel(val, &lx_krn->krn_csr);
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int leo_blank(int blank, struct fb_info *info)
{
struct leo_par *par = (struct leo_par *) info->par;
struct leo_lx_krn __iomem *lx_krn = par->lx_krn;
unsigned long flags;
u32 val;
spin_lock_irqsave(&par->lock, flags);
switch (blank) {
case FB_BLANK_UNBLANK:
val = sbus_readl(&lx_krn->krn_csr);
val |= LEO_KRN_CSR_ENABLE;
sbus_writel(val, &lx_krn->krn_csr);
par->flags &= ~LEO_FLAG_BLANKED;
break;
case FB_BLANK_NORMAL:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_POWERDOWN:
val = sbus_readl(&lx_krn->krn_csr);
val &= ~LEO_KRN_CSR_ENABLE;
sbus_writel(val, &lx_krn->krn_csr);
par->flags |= LEO_FLAG_BLANKED;
break;
}
spin_unlock_irqrestore(&par->lock, flags);
return 0;
}
static int leo_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
struct leo_par *par = (struct leo_par *)info->par;
return sbusfb_mmap_helper(leo_mmap_map,
info->fix.smem_start, info->fix.smem_len,
par->which_io, vma);
}
static int leo_ioctl(struct fb_info *info, unsigned int cmd, unsigned long arg)
{
return sbusfb_ioctl_helper(cmd, arg, info,
FBTYPE_SUNLEO, 32, info->fix.smem_len);
}
static void
leo_init_fix(struct fb_info *info, struct device_node *dp)
{
strlcpy(info->fix.id, dp->name, sizeof(info->fix.id));
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->fix.line_length = 8192;
info->fix.accel = FB_ACCEL_SUN_LEO;
}
static void leo_wid_put(struct fb_info *info, struct fb_wid_list *wl)
{
struct leo_par *par = (struct leo_par *) info->par;
struct leo_lx_krn __iomem *lx_krn = par->lx_krn;
struct fb_wid_item *wi;
unsigned long flags;
u32 val;
int i, j;
spin_lock_irqsave(&par->lock, flags);
leo_wait(lx_krn);
for (i = 0, wi = wl->wl_list; i < wl->wl_count; i++, wi++) {
switch (wi->wi_type) {
case FB_WID_DBL_8:
j = (wi->wi_index & 0xf) + 0x40;
break;
case FB_WID_DBL_24:
j = wi->wi_index & 0x3f;
break;
default:
continue;
};
sbus_writel(0x5800 + j, &lx_krn->krn_type);
sbus_writel(wi->wi_values[0], &lx_krn->krn_value);
}
sbus_writel(LEO_KRN_TYPE_WID, &lx_krn->krn_type);
val = sbus_readl(&lx_krn->krn_csr);
val |= (LEO_KRN_CSR_UNK | LEO_KRN_CSR_UNK2);
sbus_writel(val, &lx_krn->krn_csr);
spin_unlock_irqrestore(&par->lock, flags);
}
static void leo_init_wids(struct fb_info *info)
{
struct fb_wid_item wi;
struct fb_wid_list wl;
wl.wl_count = 1;
wl.wl_list = &wi;
wi.wi_type = FB_WID_DBL_8;
wi.wi_index = 0;
wi.wi_values [0] = 0x2c0;
leo_wid_put(info, &wl);
wi.wi_index = 1;
wi.wi_values [0] = 0x30;
leo_wid_put(info, &wl);
wi.wi_index = 2;
wi.wi_values [0] = 0x20;
leo_wid_put(info, &wl);
wi.wi_type = FB_WID_DBL_24;
wi.wi_index = 1;
wi.wi_values [0] = 0x30;
leo_wid_put(info, &wl);
}
static void leo_init_hw(struct fb_info *info)
{
struct leo_par *par = (struct leo_par *) info->par;
u32 val;
val = sbus_readl(&par->ld_ss1->ss1_misc);
val |= LEO_SS1_MISC_ENABLE;
sbus_writel(val, &par->ld_ss1->ss1_misc);
leo_switch_from_graph(info);
}
static void leo_fixup_var_rgb(struct fb_var_screeninfo *var)
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
static void leo_unmap_regs(struct platform_device *op, struct fb_info *info,
struct leo_par *par)
{
if (par->lc_ss0_usr)
of_iounmap(&op->resource[0], par->lc_ss0_usr, 0x1000);
if (par->ld_ss0)
of_iounmap(&op->resource[0], par->ld_ss0, 0x1000);
if (par->ld_ss1)
of_iounmap(&op->resource[0], par->ld_ss1, 0x1000);
if (par->lx_krn)
of_iounmap(&op->resource[0], par->lx_krn, 0x1000);
if (par->cursor)
of_iounmap(&op->resource[0],
par->cursor, sizeof(struct leo_cursor));
if (info->screen_base)
of_iounmap(&op->resource[0], info->screen_base, 0x800000);
}
static int leo_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
struct fb_info *info;
struct leo_par *par;
int linebytes, err;
info = framebuffer_alloc(sizeof(struct leo_par), &op->dev);
err = -ENOMEM;
if (!info)
goto out_err;
par = info->par;
spin_lock_init(&par->lock);
info->fix.smem_start = op->resource[0].start;
par->which_io = op->resource[0].flags & IORESOURCE_BITS;
sbusfb_fill_var(&info->var, dp, 32);
leo_fixup_var_rgb(&info->var);
linebytes = of_getintprop_default(dp, "linebytes",
info->var.xres);
info->fix.smem_len = PAGE_ALIGN(linebytes * info->var.yres);
par->lc_ss0_usr =
of_ioremap(&op->resource[0], LEO_OFF_LC_SS0_USR,
0x1000, "leolc ss0usr");
par->ld_ss0 =
of_ioremap(&op->resource[0], LEO_OFF_LD_SS0,
0x1000, "leold ss0");
par->ld_ss1 =
of_ioremap(&op->resource[0], LEO_OFF_LD_SS1,
0x1000, "leold ss1");
par->lx_krn =
of_ioremap(&op->resource[0], LEO_OFF_LX_KRN,
0x1000, "leolx krn");
par->cursor =
of_ioremap(&op->resource[0], LEO_OFF_LX_CURSOR,
sizeof(struct leo_cursor), "leolx cursor");
info->screen_base =
of_ioremap(&op->resource[0], LEO_OFF_SS0,
0x800000, "leo ram");
if (!par->lc_ss0_usr ||
!par->ld_ss0 ||
!par->ld_ss1 ||
!par->lx_krn ||
!par->cursor ||
!info->screen_base)
goto out_unmap_regs;
info->flags = FBINFO_DEFAULT;
info->fbops = &leo_ops;
info->pseudo_palette = par->clut_data;
leo_init_wids(info);
leo_init_hw(info);
leo_blank(FB_BLANK_UNBLANK, info);
if (fb_alloc_cmap(&info->cmap, 256, 0))
goto out_unmap_regs;
leo_init_fix(info, dp);
err = register_framebuffer(info);
if (err < 0)
goto out_dealloc_cmap;
dev_set_drvdata(&op->dev, info);
printk(KERN_INFO "%s: leo at %lx:%lx\n",
dp->full_name,
par->which_io, info->fix.smem_start);
return 0;
out_dealloc_cmap:
fb_dealloc_cmap(&info->cmap);
out_unmap_regs:
leo_unmap_regs(op, info, par);
framebuffer_release(info);
out_err:
return err;
}
static int leo_remove(struct platform_device *op)
{
struct fb_info *info = dev_get_drvdata(&op->dev);
struct leo_par *par = info->par;
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
leo_unmap_regs(op, info, par);
framebuffer_release(info);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
static int __init leo_init(void)
{
if (fb_get_options("leofb", NULL))
return -ENODEV;
return platform_driver_register(&leo_driver);
}
static void __exit leo_exit(void)
{
platform_driver_unregister(&leo_driver);
}
