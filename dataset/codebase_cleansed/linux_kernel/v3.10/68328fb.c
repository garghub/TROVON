static u_long get_line_length(int xres_virtual, int bpp)
{
u_long length;
length = xres_virtual * bpp;
length = (length + 31) & ~31;
length >>= 3;
return (length);
}
static int mc68x328fb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
u_long line_length;
if (var->vmode & FB_VMODE_CONUPDATE) {
var->vmode |= FB_VMODE_YWRAP;
var->xoffset = info->var.xoffset;
var->yoffset = info->var.yoffset;
}
if (!var->xres)
var->xres = 1;
if (!var->yres)
var->yres = 1;
if (var->xres > var->xres_virtual)
var->xres_virtual = var->xres;
if (var->yres > var->yres_virtual)
var->yres_virtual = var->yres;
if (var->bits_per_pixel <= 1)
var->bits_per_pixel = 1;
else if (var->bits_per_pixel <= 8)
var->bits_per_pixel = 8;
else if (var->bits_per_pixel <= 16)
var->bits_per_pixel = 16;
else if (var->bits_per_pixel <= 24)
var->bits_per_pixel = 24;
else if (var->bits_per_pixel <= 32)
var->bits_per_pixel = 32;
else
return -EINVAL;
if (var->xres_virtual < var->xoffset + var->xres)
var->xres_virtual = var->xoffset + var->xres;
if (var->yres_virtual < var->yoffset + var->yres)
var->yres_virtual = var->yoffset + var->yres;
line_length =
get_line_length(var->xres_virtual, var->bits_per_pixel);
if (line_length * var->yres_virtual > videomemorysize)
return -ENOMEM;
switch (var->bits_per_pixel) {
case 1:
var->red.offset = 0;
var->red.length = 1;
var->green.offset = 0;
var->green.length = 1;
var->blue.offset = 0;
var->blue.length = 1;
var->transp.offset = 0;
var->transp.length = 0;
break;
case 8:
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 0;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
break;
case 16:
if (var->transp.length) {
var->red.offset = 0;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 5;
var->blue.offset = 10;
var->blue.length = 5;
var->transp.offset = 15;
var->transp.length = 1;
} else {
var->red.offset = 0;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 11;
var->blue.length = 5;
var->transp.offset = 0;
var->transp.length = 0;
}
break;
case 24:
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 16;
var->blue.length = 8;
var->transp.offset = 0;
var->transp.length = 0;
break;
case 32:
var->red.offset = 0;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 16;
var->blue.length = 8;
var->transp.offset = 24;
var->transp.length = 8;
break;
}
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
var->transp.msb_right = 0;
return 0;
}
static int mc68x328fb_set_par(struct fb_info *info)
{
info->fix.line_length = get_line_length(info->var.xres_virtual,
info->var.bits_per_pixel);
return 0;
}
static int mc68x328fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
if (regno >= 256)
return 1;
if (info->var.grayscale) {
red = green = blue =
(red * 77 + green * 151 + blue * 28) >> 8;
}
#define CNVT_TOHW(val,width) ((((val)<<(width))+0x7FFF-(val))>>16)
switch (info->fix.visual) {
case FB_VISUAL_TRUECOLOR:
case FB_VISUAL_PSEUDOCOLOR:
red = CNVT_TOHW(red, info->var.red.length);
green = CNVT_TOHW(green, info->var.green.length);
blue = CNVT_TOHW(blue, info->var.blue.length);
transp = CNVT_TOHW(transp, info->var.transp.length);
break;
case FB_VISUAL_DIRECTCOLOR:
red = CNVT_TOHW(red, 8);
green = CNVT_TOHW(green, 8);
blue = CNVT_TOHW(blue, 8);
transp = CNVT_TOHW(transp, 8);
break;
}
#undef CNVT_TOHW
if (info->fix.visual == FB_VISUAL_TRUECOLOR) {
u32 v;
if (regno >= 16)
return 1;
v = (red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset) |
(transp << info->var.transp.offset);
switch (info->var.bits_per_pixel) {
case 8:
break;
case 16:
((u32 *) (info->pseudo_palette))[regno] = v;
break;
case 24:
case 32:
((u32 *) (info->pseudo_palette))[regno] = v;
break;
}
return 0;
}
return 0;
}
static int mc68x328fb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
if (var->vmode & FB_VMODE_YWRAP) {
if (var->yoffset < 0
|| var->yoffset >= info->var.yres_virtual
|| var->xoffset)
return -EINVAL;
} else {
if (var->xoffset + info->var.xres > info->var.xres_virtual ||
var->yoffset + info->var.yres > info->var.yres_virtual)
return -EINVAL;
}
info->var.xoffset = var->xoffset;
info->var.yoffset = var->yoffset;
if (var->vmode & FB_VMODE_YWRAP)
info->var.vmode |= FB_VMODE_YWRAP;
else
info->var.vmode &= ~FB_VMODE_YWRAP;
return 0;
}
static int mc68x328fb_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
#ifndef MMU
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_start = videomemory;
return 0;
#else
return -EINVAL;
#endif
}
int __init mc68x328fb_setup(char *options)
{
#if 0
char *this_opt;
#endif
if (!options || !*options)
return 1;
#if 0
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!*this_opt)
continue;
if (!strncmp(this_opt, "disable", 7))
mc68x328fb_enable = 0;
}
#endif
return 1;
}
int __init mc68x328fb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("68328fb", &option))
return -ENODEV;
mc68x328fb_setup(option);
#endif
mc68x328fb_default.xres = LXMAX;
mc68x328fb_default.yres = LYMAX+1;
mc68x328fb_default.xres_virtual = mc68x328fb_default.xres;
mc68x328fb_default.yres_virtual = mc68x328fb_default.yres;
mc68x328fb_default.bits_per_pixel = 1 + (LPICF & 0x01);
videomemory = LSSA;
videomemorysize = (mc68x328fb_default.xres_virtual+7) / 8 *
mc68x328fb_default.yres_virtual * mc68x328fb_default.bits_per_pixel;
fb_info.screen_base = (void *)videomemory;
fb_info.fbops = &mc68x328fb_ops;
fb_info.var = mc68x328fb_default;
fb_info.fix = mc68x328fb_fix;
fb_info.fix.smem_start = videomemory;
fb_info.fix.smem_len = videomemorysize;
fb_info.fix.line_length =
get_line_length(mc68x328fb_default.xres_virtual, mc68x328fb_default.bits_per_pixel);
fb_info.fix.visual = (mc68x328fb_default.bits_per_pixel) == 1 ?
MC68X328FB_MONO_VISUAL : FB_VISUAL_PSEUDOCOLOR;
if (fb_info.var.bits_per_pixel == 1) {
fb_info.var.red.length = fb_info.var.green.length = fb_info.var.blue.length = 1;
fb_info.var.red.offset = fb_info.var.green.offset = fb_info.var.blue.offset = 0;
}
fb_info.pseudo_palette = &mc68x328fb_pseudo_palette;
fb_info.flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
if (fb_alloc_cmap(&fb_info.cmap, 256, 0))
return -ENOMEM;
if (register_framebuffer(&fb_info) < 0) {
fb_dealloc_cmap(&fb_info.cmap);
return -EINVAL;
}
printk(KERN_INFO
"fb%d: %s frame buffer device\n", fb_info.node, fb_info.fix.id);
printk(KERN_INFO
"fb%d: %dx%dx%d at 0x%08lx\n", fb_info.node,
mc68x328fb_default.xres_virtual, mc68x328fb_default.yres_virtual,
1 << mc68x328fb_default.bits_per_pixel, videomemory);
return 0;
}
static void __exit mc68x328fb_cleanup(void)
{
unregister_framebuffer(&fb_info);
fb_dealloc_cmap(&fb_info.cmap);
}
