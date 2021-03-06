static void *rvmalloc(unsigned long size)
{
void *mem;
unsigned long adr;
size = PAGE_ALIGN(size);
mem = vmalloc_32(size);
if (!mem)
return NULL;
memset(mem, 0, size);
adr = (unsigned long) mem;
while (size > 0) {
SetPageReserved(vmalloc_to_page((void *)adr));
adr += PAGE_SIZE;
size -= PAGE_SIZE;
}
return mem;
}
static void rvfree(void *mem, unsigned long size)
{
unsigned long adr;
if (!mem)
return;
adr = (unsigned long) mem;
while ((long) size > 0) {
ClearPageReserved(vmalloc_to_page((void *)adr));
adr += PAGE_SIZE;
size -= PAGE_SIZE;
}
vfree(mem);
}
static u_long get_line_length(int xres_virtual, int bpp)
{
u_long length;
length = xres_virtual * bpp;
length = (length + 31) & ~31;
length >>= 3;
return (length);
}
static int vfb_check_var(struct fb_var_screeninfo *var,
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
static int vfb_set_par(struct fb_info *info)
{
info->fix.line_length = get_line_length(info->var.xres_virtual,
info->var.bits_per_pixel);
return 0;
}
static int vfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
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
static int vfb_pan_display(struct fb_var_screeninfo *var,
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
static int vfb_mmap(struct fb_info *info,
struct vm_area_struct *vma)
{
unsigned long start = vma->vm_start;
unsigned long size = vma->vm_end - vma->vm_start;
unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
unsigned long page, pos;
if (vma->vm_pgoff > (~0UL >> PAGE_SHIFT))
return -EINVAL;
if (size > info->fix.smem_len)
return -EINVAL;
if (offset > info->fix.smem_len - size)
return -EINVAL;
pos = (unsigned long)info->fix.smem_start + offset;
while (size > 0) {
page = vmalloc_to_pfn((void *)pos);
if (remap_pfn_range(vma, start, page, PAGE_SIZE, PAGE_SHARED)) {
return -EAGAIN;
}
start += PAGE_SIZE;
pos += PAGE_SIZE;
if (size > PAGE_SIZE)
size -= PAGE_SIZE;
else
size = 0;
}
return 0;
}
static int __init vfb_setup(char *options)
{
char *this_opt;
vfb_enable = 0;
if (!options)
return 1;
vfb_enable = 1;
if (!*options)
return 1;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!*this_opt)
continue;
if (!strcmp(this_opt, "disable"))
vfb_enable = 0;
}
return 1;
}
static int vfb_probe(struct platform_device *dev)
{
struct fb_info *info;
int retval = -ENOMEM;
if (!(videomemory = rvmalloc(videomemorysize)))
return retval;
memset(videomemory, 0, videomemorysize);
info = framebuffer_alloc(sizeof(u32) * 256, &dev->dev);
if (!info)
goto err;
info->screen_base = (char __iomem *)videomemory;
info->fbops = &vfb_ops;
retval = fb_find_mode(&info->var, info, NULL,
NULL, 0, NULL, 8);
if (!retval || (retval == 4))
info->var = vfb_default;
vfb_fix.smem_start = (unsigned long) videomemory;
vfb_fix.smem_len = videomemorysize;
info->fix = vfb_fix;
info->pseudo_palette = info->par;
info->par = NULL;
info->flags = FBINFO_FLAG_DEFAULT;
retval = fb_alloc_cmap(&info->cmap, 256, 0);
if (retval < 0)
goto err1;
retval = register_framebuffer(info);
if (retval < 0)
goto err2;
platform_set_drvdata(dev, info);
printk(KERN_INFO
"fb%d: Virtual frame buffer device, using %ldK of video memory\n",
info->node, videomemorysize >> 10);
return 0;
err2:
fb_dealloc_cmap(&info->cmap);
err1:
framebuffer_release(info);
err:
rvfree(videomemory, videomemorysize);
return retval;
}
static int vfb_remove(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
if (info) {
unregister_framebuffer(info);
rvfree(videomemory, videomemorysize);
fb_dealloc_cmap(&info->cmap);
framebuffer_release(info);
}
return 0;
}
static int __init vfb_init(void)
{
int ret = 0;
#ifndef MODULE
char *option = NULL;
if (fb_get_options("vfb", &option))
return -ENODEV;
vfb_setup(option);
#endif
if (!vfb_enable)
return -ENXIO;
ret = platform_driver_register(&vfb_driver);
if (!ret) {
vfb_device = platform_device_alloc("vfb", 0);
if (vfb_device)
ret = platform_device_add(vfb_device);
else
ret = -ENOMEM;
if (ret) {
platform_device_put(vfb_device);
platform_driver_unregister(&vfb_driver);
}
}
return ret;
}
static void __exit vfb_exit(void)
{
platform_device_unregister(vfb_device);
platform_driver_unregister(&vfb_driver);
}
