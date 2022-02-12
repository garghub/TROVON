static int vesafb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
#ifdef __i386__
int offset;
offset = (var->yoffset * info->fix.line_length + var->xoffset) / 4;
__asm__ __volatile__(
"call *(%%edi)"
:
: "a" (0x4f07),
"b" (0),
"c" (offset),
"d" (offset >> 16),
"D" (&pmi_start));
#endif
return 0;
}
static int vesa_setpalette(int regno, unsigned red, unsigned green,
unsigned blue)
{
int shift = 16 - depth;
int err = -EINVAL;
if (vga_compat) {
outb_p(regno, dac_reg);
outb_p(red >> shift, dac_val);
outb_p(green >> shift, dac_val);
outb_p(blue >> shift, dac_val);
err = 0;
}
#ifdef __i386__
if (err && pmi_setpal) {
struct { u_char blue, green, red, pad; } entry;
entry.red = red >> shift;
entry.green = green >> shift;
entry.blue = blue >> shift;
entry.pad = 0;
__asm__ __volatile__(
"call *(%%esi)"
:
: "a" (0x4f09),
"b" (0),
"c" (1),
"d" (regno),
"D" (&entry),
"S" (&pmi_pal));
err = 0;
}
#endif
return err;
}
static int vesafb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
int err = 0;
if (regno >= info->cmap.len)
return 1;
if (info->var.bits_per_pixel == 8)
err = vesa_setpalette(regno,red,green,blue);
else if (regno < 16) {
switch (info->var.bits_per_pixel) {
case 16:
if (info->var.red.offset == 10) {
((u32*) (info->pseudo_palette))[regno] =
((red & 0xf800) >> 1) |
((green & 0xf800) >> 6) |
((blue & 0xf800) >> 11);
} else {
((u32*) (info->pseudo_palette))[regno] =
((red & 0xf800) ) |
((green & 0xfc00) >> 5) |
((blue & 0xf800) >> 11);
}
break;
case 24:
case 32:
red >>= 8;
green >>= 8;
blue >>= 8;
((u32 *)(info->pseudo_palette))[regno] =
(red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset);
break;
}
}
return err;
}
static void vesafb_destroy(struct fb_info *info)
{
struct vesafb_par *par = info->par;
fb_dealloc_cmap(&info->cmap);
arch_phys_wc_del(par->wc_cookie);
if (info->screen_base)
iounmap(info->screen_base);
release_mem_region(info->apertures->ranges[0].base, info->apertures->ranges[0].size);
}
static int vesafb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!*this_opt) continue;
if (! strcmp(this_opt, "inverse"))
inverse=1;
else if (! strcmp(this_opt, "redraw"))
ypan=0;
else if (! strcmp(this_opt, "ypan"))
ypan=1;
else if (! strcmp(this_opt, "ywrap"))
ypan=2;
else if (! strcmp(this_opt, "vgapal"))
pmi_setpal=0;
else if (! strcmp(this_opt, "pmipal"))
pmi_setpal=1;
else if (! strncmp(this_opt, "mtrr:", 5))
mtrr = simple_strtoul(this_opt+5, NULL, 0);
else if (! strcmp(this_opt, "nomtrr"))
mtrr=0;
else if (! strncmp(this_opt, "vtotal:", 7))
vram_total = simple_strtoul(this_opt+7, NULL, 0);
else if (! strncmp(this_opt, "vremap:", 7))
vram_remap = simple_strtoul(this_opt+7, NULL, 0);
}
return 0;
}
static int vesafb_probe(struct platform_device *dev)
{
struct fb_info *info;
struct vesafb_par *par;
int i, err;
unsigned int size_vmode;
unsigned int size_remap;
unsigned int size_total;
char *option = NULL;
fb_get_options("vesafb", &option);
vesafb_setup(option);
if (screen_info.orig_video_isVGA != VIDEO_TYPE_VLFB)
return -ENODEV;
vga_compat = (screen_info.capabilities & 2) ? 0 : 1;
vesafb_fix.smem_start = screen_info.lfb_base;
vesafb_defined.bits_per_pixel = screen_info.lfb_depth;
if (15 == vesafb_defined.bits_per_pixel)
vesafb_defined.bits_per_pixel = 16;
vesafb_defined.xres = screen_info.lfb_width;
vesafb_defined.yres = screen_info.lfb_height;
vesafb_fix.line_length = screen_info.lfb_linelength;
vesafb_fix.visual = (vesafb_defined.bits_per_pixel == 8) ?
FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_TRUECOLOR;
size_vmode = vesafb_defined.yres * vesafb_fix.line_length;
size_total = screen_info.lfb_size * 65536;
if (vram_total)
size_total = vram_total * 1024 * 1024;
if (size_total < size_vmode)
size_total = size_vmode;
size_remap = size_vmode * 2;
if (vram_remap)
size_remap = vram_remap * 1024 * 1024;
if (size_remap < size_vmode)
size_remap = size_vmode;
if (size_remap > size_total)
size_remap = size_total;
vesafb_fix.smem_len = size_remap;
#ifndef __i386__
screen_info.vesapm_seg = 0;
#endif
if (!request_mem_region(vesafb_fix.smem_start, size_total, "vesafb")) {
printk(KERN_WARNING
"vesafb: cannot reserve video memory at 0x%lx\n",
vesafb_fix.smem_start);
}
info = framebuffer_alloc(sizeof(struct vesafb_par), &dev->dev);
if (!info) {
release_mem_region(vesafb_fix.smem_start, size_total);
return -ENOMEM;
}
platform_set_drvdata(dev, info);
par = info->par;
info->pseudo_palette = par->pseudo_palette;
info->apertures = alloc_apertures(1);
if (!info->apertures) {
err = -ENOMEM;
goto err;
}
info->apertures->ranges[0].base = screen_info.lfb_base;
info->apertures->ranges[0].size = size_total;
printk(KERN_INFO "vesafb: mode is %dx%dx%d, linelength=%d, pages=%d\n",
vesafb_defined.xres, vesafb_defined.yres, vesafb_defined.bits_per_pixel, vesafb_fix.line_length, screen_info.pages);
if (screen_info.vesapm_seg) {
printk(KERN_INFO "vesafb: protected mode interface info at %04x:%04x\n",
screen_info.vesapm_seg,screen_info.vesapm_off);
}
if (screen_info.vesapm_seg < 0xc000)
ypan = pmi_setpal = 0;
if (ypan || pmi_setpal) {
unsigned short *pmi_base;
pmi_base = (unsigned short*)phys_to_virt(((unsigned long)screen_info.vesapm_seg << 4) + screen_info.vesapm_off);
pmi_start = (void*)((char*)pmi_base + pmi_base[1]);
pmi_pal = (void*)((char*)pmi_base + pmi_base[2]);
printk(KERN_INFO "vesafb: pmi: set display start = %p, set palette = %p\n",pmi_start,pmi_pal);
if (pmi_base[3]) {
printk(KERN_INFO "vesafb: pmi: ports = ");
for (i = pmi_base[3]/2; pmi_base[i] != 0xffff; i++)
printk("%x ",pmi_base[i]);
printk("\n");
if (pmi_base[i] != 0xffff) {
printk(KERN_INFO "vesafb: can't handle memory requests, pmi disabled\n");
ypan = pmi_setpal = 0;
}
}
}
if (vesafb_defined.bits_per_pixel == 8 && !pmi_setpal && !vga_compat) {
printk(KERN_WARNING "vesafb: hardware palette is unchangeable,\n"
" colors may be incorrect\n");
vesafb_fix.visual = FB_VISUAL_STATIC_PSEUDOCOLOR;
}
vesafb_defined.xres_virtual = vesafb_defined.xres;
vesafb_defined.yres_virtual = vesafb_fix.smem_len / vesafb_fix.line_length;
if (ypan && vesafb_defined.yres_virtual > vesafb_defined.yres) {
printk(KERN_INFO "vesafb: scrolling: %s using protected mode interface, yres_virtual=%d\n",
(ypan > 1) ? "ywrap" : "ypan",vesafb_defined.yres_virtual);
} else {
printk(KERN_INFO "vesafb: scrolling: redraw\n");
vesafb_defined.yres_virtual = vesafb_defined.yres;
ypan = 0;
}
vesafb_defined.pixclock = 10000000 / vesafb_defined.xres * 1000 / vesafb_defined.yres;
vesafb_defined.left_margin = (vesafb_defined.xres / 8) & 0xf8;
vesafb_defined.hsync_len = (vesafb_defined.xres / 8) & 0xf8;
vesafb_defined.red.offset = screen_info.red_pos;
vesafb_defined.red.length = screen_info.red_size;
vesafb_defined.green.offset = screen_info.green_pos;
vesafb_defined.green.length = screen_info.green_size;
vesafb_defined.blue.offset = screen_info.blue_pos;
vesafb_defined.blue.length = screen_info.blue_size;
vesafb_defined.transp.offset = screen_info.rsvd_pos;
vesafb_defined.transp.length = screen_info.rsvd_size;
if (vesafb_defined.bits_per_pixel <= 8) {
depth = vesafb_defined.green.length;
vesafb_defined.red.length =
vesafb_defined.green.length =
vesafb_defined.blue.length =
vesafb_defined.bits_per_pixel;
}
printk(KERN_INFO "vesafb: %s: "
"size=%d:%d:%d:%d, shift=%d:%d:%d:%d\n",
(vesafb_defined.bits_per_pixel > 8) ?
"Truecolor" : (vga_compat || pmi_setpal) ?
"Pseudocolor" : "Static Pseudocolor",
screen_info.rsvd_size,
screen_info.red_size,
screen_info.green_size,
screen_info.blue_size,
screen_info.rsvd_pos,
screen_info.red_pos,
screen_info.green_pos,
screen_info.blue_pos);
vesafb_fix.ypanstep = ypan ? 1 : 0;
vesafb_fix.ywrapstep = (ypan>1) ? 1 : 0;
request_region(0x3c0, 32, "vesafb");
if (mtrr == 3) {
unsigned int temp_size = size_total;
temp_size = roundup_pow_of_two(temp_size);
do {
par->wc_cookie =
arch_phys_wc_add(vesafb_fix.smem_start,
temp_size);
temp_size >>= 1;
} while (temp_size >= PAGE_SIZE && par->wc_cookie < 0);
info->screen_base = ioremap_wc(vesafb_fix.smem_start, vesafb_fix.smem_len);
} else {
if (mtrr && mtrr != 3)
WARN_ONCE(1, "Only MTRR_TYPE_WRCOMB (3) make sense\n");
info->screen_base = ioremap(vesafb_fix.smem_start, vesafb_fix.smem_len);
}
if (!info->screen_base) {
printk(KERN_ERR
"vesafb: abort, cannot ioremap video memory 0x%x @ 0x%lx\n",
vesafb_fix.smem_len, vesafb_fix.smem_start);
err = -EIO;
goto err;
}
printk(KERN_INFO "vesafb: framebuffer at 0x%lx, mapped to 0x%p, "
"using %dk, total %dk\n",
vesafb_fix.smem_start, info->screen_base,
size_remap/1024, size_total/1024);
info->fbops = &vesafb_ops;
info->var = vesafb_defined;
info->fix = vesafb_fix;
info->flags = FBINFO_FLAG_DEFAULT | FBINFO_MISC_FIRMWARE |
(ypan ? FBINFO_HWACCEL_YPAN : 0);
if (!ypan)
info->fbops->fb_pan_display = NULL;
if (fb_alloc_cmap(&info->cmap, 256, 0) < 0) {
err = -ENOMEM;
goto err;
}
if (register_framebuffer(info)<0) {
err = -EINVAL;
fb_dealloc_cmap(&info->cmap);
goto err;
}
fb_info(info, "%s frame buffer device\n", info->fix.id);
return 0;
err:
arch_phys_wc_del(par->wc_cookie);
if (info->screen_base)
iounmap(info->screen_base);
framebuffer_release(info);
release_mem_region(vesafb_fix.smem_start, size_total);
return err;
}
static int vesafb_remove(struct platform_device *pdev)
{
struct fb_info *info = platform_get_drvdata(pdev);
unregister_framebuffer(info);
framebuffer_release(info);
return 0;
}
