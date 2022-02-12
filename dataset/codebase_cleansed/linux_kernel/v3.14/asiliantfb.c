static void mm_write_xr(struct fb_info *p, u8 reg, u8 data)
{
mm_write_ind(reg, data, 0x7ac, 0x7ad);
}
static void mm_write_fr(struct fb_info *p, u8 reg, u8 data)
{
mm_write_ind(reg, data, 0x7a0, 0x7a1);
}
static void mm_write_cr(struct fb_info *p, u8 reg, u8 data)
{
mm_write_ind(reg, data, 0x7a8, 0x7a9);
}
static void mm_write_gr(struct fb_info *p, u8 reg, u8 data)
{
mm_write_ind(reg, data, 0x79c, 0x79d);
}
static void mm_write_sr(struct fb_info *p, u8 reg, u8 data)
{
mm_write_ind(reg, data, 0x788, 0x789);
}
static void mm_write_ar(struct fb_info *p, u8 reg, u8 data)
{
readb(mmio_base + 0x7b4);
mm_write_ind(reg, data, 0x780, 0x780);
}
static void asiliant_calc_dclk2(u32 *ppixclock, u8 *dclk2_m, u8 *dclk2_n, u8 *dclk2_div)
{
unsigned pixclock = *ppixclock;
unsigned Ftarget = 1000000 * (1000000 / pixclock);
unsigned n;
unsigned best_error = 0xffffffff;
unsigned best_m = 0xffffffff,
best_n = 0xffffffff;
unsigned ratio;
unsigned remainder;
unsigned char divisor = 0;
ratio = 1000000 / pixclock;
remainder = 1000000 % pixclock;
Ftarget = 1000000 * ratio + (1000000 * remainder) / pixclock;
while (Ftarget < 100000000) {
divisor += 0x10;
Ftarget <<= 1;
}
ratio = Ftarget / Fref;
remainder = Ftarget % Fref;
for (n = 3; n <= 257; n++) {
unsigned m = n * ratio + (n * remainder) / Fref;
if (m >= 3 && m <= 257) {
unsigned new_error = Ftarget * n >= Fref * m ?
((Ftarget * n) - (Fref * m)) : ((Fref * m) - (Ftarget * n));
if (new_error < best_error) {
best_n = n;
best_m = m;
best_error = new_error;
}
}
else if (m <= 1028) {
unsigned new_error = Ftarget * n >= Fref * (m & ~3) ?
((Ftarget * n) - (Fref * (m & ~3))) : ((Fref * (m & ~3)) - (Ftarget * n));
if (new_error < best_error) {
best_n = n;
best_m = m;
best_error = new_error;
}
}
}
if (best_m > 257)
best_m >>= 2;
else
divisor |= 4;
*dclk2_m = best_m - 2;
*dclk2_n = best_n - 2;
*dclk2_div = divisor;
*ppixclock = pixclock;
return;
}
static void asiliant_set_timing(struct fb_info *p)
{
unsigned hd = p->var.xres / 8;
unsigned hs = (p->var.xres + p->var.right_margin) / 8;
unsigned he = (p->var.xres + p->var.right_margin + p->var.hsync_len) / 8;
unsigned ht = (p->var.left_margin + p->var.xres + p->var.right_margin + p->var.hsync_len) / 8;
unsigned vd = p->var.yres;
unsigned vs = p->var.yres + p->var.lower_margin;
unsigned ve = p->var.yres + p->var.lower_margin + p->var.vsync_len;
unsigned vt = p->var.upper_margin + p->var.yres + p->var.lower_margin + p->var.vsync_len;
unsigned wd = (p->var.xres_virtual * ((p->var.bits_per_pixel+7)/8)) / 8;
if ((p->var.xres == 640) && (p->var.yres == 480) && (p->var.pixclock == 39722)) {
write_fr(0x01, 0x02);
} else {
write_fr(0x01, 0x01);
}
write_cr(0x11, (ve - 1) & 0x0f);
write_cr(0x00, (ht - 5) & 0xff);
write_cr(0x01, hd - 1);
write_cr(0x02, hd);
write_cr(0x03, ((ht - 1) & 0x1f) | 0x80);
write_cr(0x04, hs);
write_cr(0x05, (((ht - 1) & 0x20) <<2) | (he & 0x1f));
write_cr(0x3c, (ht - 1) & 0xc0);
write_cr(0x06, (vt - 2) & 0xff);
write_cr(0x30, (vt - 2) >> 8);
write_cr(0x07, 0x00);
write_cr(0x08, 0x00);
write_cr(0x09, 0x00);
write_cr(0x10, (vs - 1) & 0xff);
write_cr(0x32, ((vs - 1) >> 8) & 0xf);
write_cr(0x11, ((ve - 1) & 0x0f) | 0x80);
write_cr(0x12, (vd - 1) & 0xff);
write_cr(0x31, ((vd - 1) & 0xf00) >> 8);
write_cr(0x13, wd & 0xff);
write_cr(0x41, (wd & 0xf00) >> 8);
write_cr(0x15, (vs - 1) & 0xff);
write_cr(0x33, ((vs - 1) >> 8) & 0xf);
write_cr(0x38, ((ht - 5) & 0x100) >> 8);
write_cr(0x16, (vt - 1) & 0xff);
write_cr(0x18, 0x00);
if (p->var.xres == 640) {
writeb(0xc7, mmio_base + 0x784);
} else {
writeb(0x07, mmio_base + 0x784);
}
}
static int asiliantfb_check_var(struct fb_var_screeninfo *var,
struct fb_info *p)
{
unsigned long Ftarget, ratio, remainder;
ratio = 1000000 / var->pixclock;
remainder = 1000000 % var->pixclock;
Ftarget = 1000000 * ratio + (1000000 * remainder) / var->pixclock;
if (Ftarget > 220000000 || Ftarget < 3125000) {
printk(KERN_ERR "asiliantfb dotclock must be between 3.125 and 220MHz\n");
return -ENXIO;
}
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
if (var->bits_per_pixel == 24) {
var->red.offset = 16;
var->green.offset = 8;
var->blue.offset = 0;
var->red.length = var->blue.length = var->green.length = 8;
} else if (var->bits_per_pixel == 16) {
switch (var->red.offset) {
case 11:
var->green.length = 6;
break;
case 10:
var->green.length = 5;
break;
default:
return -EINVAL;
}
var->green.offset = 5;
var->blue.offset = 0;
var->red.length = var->blue.length = 5;
} else if (var->bits_per_pixel == 8) {
var->red.offset = var->green.offset = var->blue.offset = 0;
var->red.length = var->green.length = var->blue.length = 8;
}
return 0;
}
static int asiliantfb_set_par(struct fb_info *p)
{
u8 dclk2_m;
u8 dclk2_n;
u8 dclk2_div;
asiliant_calc_dclk2(&p->var.pixclock, &dclk2_m, &dclk2_n, &dclk2_div);
if (p->var.bits_per_pixel == 24) {
write_xr(0x81, 0x16);
write_xr(0x82, 0x00);
write_xr(0x20, 0x20);
} else if (p->var.bits_per_pixel == 16) {
if (p->var.red.offset == 11)
write_xr(0x81, 0x15);
else
write_xr(0x81, 0x14);
write_xr(0x82, 0x00);
write_xr(0x20, 0x10);
} else if (p->var.bits_per_pixel == 8) {
write_xr(0x0a, 0x02);
write_xr(0x81, 0x12);
write_xr(0x82, 0x00);
write_xr(0x20, 0x00);
}
p->fix.line_length = p->var.xres * (p->var.bits_per_pixel >> 3);
p->fix.visual = (p->var.bits_per_pixel == 8) ? FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_TRUECOLOR;
write_xr(0xc4, dclk2_m);
write_xr(0xc5, dclk2_n);
write_xr(0xc7, dclk2_div);
asiliant_set_timing(p);
return 0;
}
static int asiliantfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *p)
{
if (regno > 255)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
writeb(regno, mmio_base + 0x790);
udelay(1);
writeb(red, mmio_base + 0x791);
writeb(green, mmio_base + 0x791);
writeb(blue, mmio_base + 0x791);
if (regno < 16) {
switch(p->var.red.offset) {
case 10:
((u32 *)(p->pseudo_palette))[regno] =
((red & 0xf8) << 7) |
((green & 0xf8) << 2) |
((blue & 0xf8) >> 3);
break;
case 11:
((u32 *)(p->pseudo_palette))[regno] =
((red & 0xf8) << 8) |
((green & 0xfc) << 3) |
((blue & 0xf8) >> 3);
break;
case 16:
((u32 *)(p->pseudo_palette))[regno] =
(red << 16) |
(green << 8) |
(blue);
break;
}
}
return 0;
}
static void chips_hw_init(struct fb_info *p)
{
int i;
for (i = 0; i < ARRAY_SIZE(chips_init_xr); ++i)
write_xr(chips_init_xr[i].addr, chips_init_xr[i].data);
write_xr(0x81, 0x12);
write_xr(0x82, 0x08);
write_xr(0x20, 0x00);
for (i = 0; i < ARRAY_SIZE(chips_init_sr); ++i)
write_sr(chips_init_sr[i].addr, chips_init_sr[i].data);
for (i = 0; i < ARRAY_SIZE(chips_init_gr); ++i)
write_gr(chips_init_gr[i].addr, chips_init_gr[i].data);
for (i = 0; i < ARRAY_SIZE(chips_init_ar); ++i)
write_ar(chips_init_ar[i].addr, chips_init_ar[i].data);
writeb(0x20, mmio_base + 0x780);
for (i = 0; i < ARRAY_SIZE(chips_init_cr); ++i)
write_cr(chips_init_cr[i].addr, chips_init_cr[i].data);
for (i = 0; i < ARRAY_SIZE(chips_init_fr); ++i)
write_fr(chips_init_fr[i].addr, chips_init_fr[i].data);
}
static int init_asiliant(struct fb_info *p, unsigned long addr)
{
int err;
p->fix = asiliantfb_fix;
p->fix.smem_start = addr;
p->var = asiliantfb_var;
p->fbops = &asiliantfb_ops;
p->flags = FBINFO_DEFAULT;
err = fb_alloc_cmap(&p->cmap, 256, 0);
if (err) {
printk(KERN_ERR "C&T 69000 fb failed to alloc cmap memory\n");
return err;
}
err = register_framebuffer(p);
if (err < 0) {
printk(KERN_ERR "C&T 69000 framebuffer failed to register\n");
fb_dealloc_cmap(&p->cmap);
return err;
}
fb_info(p, "Asiliant 69000 frame buffer (%dK RAM detected)\n",
p->fix.smem_len / 1024);
writeb(0xff, mmio_base + 0x78c);
chips_hw_init(p);
return 0;
}
static int asiliantfb_pci_init(struct pci_dev *dp,
const struct pci_device_id *ent)
{
unsigned long addr, size;
struct fb_info *p;
int err;
if ((dp->resource[0].flags & IORESOURCE_MEM) == 0)
return -ENODEV;
addr = pci_resource_start(dp, 0);
size = pci_resource_len(dp, 0);
if (addr == 0)
return -ENODEV;
if (!request_mem_region(addr, size, "asiliantfb"))
return -EBUSY;
p = framebuffer_alloc(sizeof(u32) * 16, &dp->dev);
if (!p) {
release_mem_region(addr, size);
return -ENOMEM;
}
p->pseudo_palette = p->par;
p->par = NULL;
p->screen_base = ioremap(addr, 0x800000);
if (p->screen_base == NULL) {
release_mem_region(addr, size);
framebuffer_release(p);
return -ENOMEM;
}
pci_write_config_dword(dp, 4, 0x02800083);
writeb(3, p->screen_base + 0x400784);
err = init_asiliant(p, addr);
if (err) {
iounmap(p->screen_base);
release_mem_region(addr, size);
framebuffer_release(p);
return err;
}
pci_set_drvdata(dp, p);
return 0;
}
static void asiliantfb_remove(struct pci_dev *dp)
{
struct fb_info *p = pci_get_drvdata(dp);
unregister_framebuffer(p);
fb_dealloc_cmap(&p->cmap);
iounmap(p->screen_base);
release_mem_region(pci_resource_start(dp, 0), pci_resource_len(dp, 0));
framebuffer_release(p);
}
static int __init asiliantfb_init(void)
{
if (fb_get_options("asiliantfb", NULL))
return -ENODEV;
return pci_register_driver(&asiliantfb_driver);
}
static void __exit asiliantfb_exit(void)
{
pci_unregister_driver(&asiliantfb_driver);
}
