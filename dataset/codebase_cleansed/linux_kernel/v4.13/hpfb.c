static int hpfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
unsigned char _red =red>>8;
unsigned char _green=green>>8;
unsigned char _blue =blue>>8;
unsigned char _regno=regno;
if (regno >= info->cmap.len)
return 1;
while (in_be16(fb_regs + 0x6002) & 0x4) udelay(1);
out_be16(fb_regs + 0x60ba, 0xff);
out_be16(fb_regs + 0x60b2, _red);
out_be16(fb_regs + 0x60b4, _green);
out_be16(fb_regs + 0x60b6, _blue);
out_be16(fb_regs + 0x60b8, ~_regno);
out_be16(fb_regs + 0x60f0, 0xff);
udelay(100);
while (in_be16(fb_regs + 0x6002) & 0x4) udelay(1);
out_be16(fb_regs + 0x60b2, 0);
out_be16(fb_regs + 0x60b4, 0);
out_be16(fb_regs + 0x60b6, 0);
out_be16(fb_regs + 0x60b8, 0);
return 0;
}
static int hpfb_blank(int blank, struct fb_info *info)
{
out_8(fb_regs + TC_NBLANK, (blank ? 0x00 : fb_bitmask));
return 0;
}
static void topcat_blit(int x0, int y0, int x1, int y1, int w, int h, int rr)
{
if (rr >= 0) {
while (in_8(fb_regs + BUSY) & fb_bitmask)
;
}
out_8(fb_regs + TC_FBEN, fb_bitmask);
if (rr >= 0) {
out_8(fb_regs + TC_WEN, fb_bitmask);
out_8(fb_regs + WMRR, rr);
}
out_be16(fb_regs + SOURCE_X, x0);
out_be16(fb_regs + SOURCE_Y, y0);
out_be16(fb_regs + DEST_X, x1);
out_be16(fb_regs + DEST_Y, y1);
out_be16(fb_regs + WWIDTH, w);
out_be16(fb_regs + WHEIGHT, h);
out_8(fb_regs + WMOVE, fb_bitmask);
}
static void hpfb_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
topcat_blit(area->sx, area->sy, area->dx, area->dy, area->width, area->height, RR_COPY);
}
static void hpfb_fillrect(struct fb_info *p, const struct fb_fillrect *region)
{
u8 clr;
clr = region->color & 0xff;
while (in_8(fb_regs + BUSY) & fb_bitmask)
;
out_8(fb_regs + TC_WEN, fb_bitmask & clr);
out_8(fb_regs + WMRR, (region->rop == ROP_COPY ? RR_SET : RR_INVERT));
out_8(fb_regs + TC_WEN, fb_bitmask & ~clr);
out_8(fb_regs + WMRR, (region->rop == ROP_COPY ? RR_CLEAR : RR_NOOP));
topcat_blit(region->dx, region->dy, region->dx, region->dy, region->width, region->height, -1);
}
static int hpfb_sync(struct fb_info *info)
{
while (in_8(fb_regs + BUSY) & fb_bitmask)
;
out_8(fb_regs + TC_WEN, fb_bitmask);
out_8(fb_regs + TC_PRR, RR_COPY);
out_8(fb_regs + TC_FBEN, fb_bitmask);
return 0;
}
static int hpfb_init_one(unsigned long phys_base, unsigned long virt_base)
{
unsigned long fboff, fb_width, fb_height, fb_start;
int ret;
fb_regs = virt_base;
fboff = (in_8(fb_regs + HPFB_FBOMSB) << 8) | in_8(fb_regs + HPFB_FBOLSB);
fb_info.fix.smem_start = (in_8(fb_regs + fboff) << 16);
if (phys_base >= DIOII_BASE) {
fb_info.fix.smem_start += phys_base;
}
if (DIO_SECID(fb_regs) != DIO_ID2_TOPCAT) {
while (in_be16(fb_regs+0x4800) & 1)
;
out_be16(fb_regs+0x4800, 0);
out_be16(fb_regs+0x4510, 0);
out_be16(fb_regs+0x4512, 0);
out_be16(fb_regs+0x4514, 0);
out_be16(fb_regs+0x4516, 0);
out_be16(fb_regs+0x4206, 0x90);
out_be16(fb_regs+0x60a2, 0);
out_be16(fb_regs+0x60bc, 0);
}
fb_width = (in_8(fb_regs + HPFB_FBWMSB) << 8) | in_8(fb_regs + HPFB_FBWLSB);
fb_info.fix.line_length = fb_width;
fb_height = (in_8(fb_regs + HPFB_FBHMSB) << 8) | in_8(fb_regs + HPFB_FBHLSB);
fb_info.fix.smem_len = fb_width * fb_height;
fb_start = (unsigned long)ioremap_wt(fb_info.fix.smem_start,
fb_info.fix.smem_len);
hpfb_defined.xres = (in_8(fb_regs + HPFB_DWMSB) << 8) | in_8(fb_regs + HPFB_DWLSB);
hpfb_defined.yres = (in_8(fb_regs + HPFB_DHMSB) << 8) | in_8(fb_regs + HPFB_DHLSB);
hpfb_defined.xres_virtual = hpfb_defined.xres;
hpfb_defined.yres_virtual = hpfb_defined.yres;
hpfb_defined.bits_per_pixel = in_8(fb_regs + HPFB_NUMPLANES);
printk(KERN_INFO "hpfb: framebuffer at 0x%lx, mapped to 0x%lx, size %dk\n",
fb_info.fix.smem_start, fb_start, fb_info.fix.smem_len/1024);
printk(KERN_INFO "hpfb: mode is %dx%dx%d, linelength=%d\n",
hpfb_defined.xres, hpfb_defined.yres, hpfb_defined.bits_per_pixel, fb_info.fix.line_length);
out_8(fb_regs + TC_WEN, 0xff);
out_8(fb_regs + TC_PRR, RR_COPY);
out_8(fb_regs + TC_FBEN, 0xff);
out_8(fb_start, 0xff);
fb_bitmask = in_8(fb_start);
out_8(fb_start, 0);
out_8(fb_regs + TC_WEN, fb_bitmask);
out_8(fb_regs + TC_PRR, RR_COPY);
out_8(fb_regs + TC_REN, fb_bitmask);
out_8(fb_regs + TC_FBEN, fb_bitmask);
topcat_blit(0, 0, 0, 0, fb_width, fb_height, RR_CLEAR);
if (DIO_SECID(fb_regs) == DIO_ID2_TOPCAT)
strcat(fb_info.fix.id, "Topcat");
else
strcat(fb_info.fix.id, "Catseye");
fb_info.fbops = &hpfb_ops;
fb_info.flags = FBINFO_DEFAULT;
fb_info.var = hpfb_defined;
fb_info.screen_base = (char *)fb_start;
ret = fb_alloc_cmap(&fb_info.cmap, 1 << hpfb_defined.bits_per_pixel, 0);
if (ret < 0)
goto unmap_screen_base;
ret = register_framebuffer(&fb_info);
if (ret < 0)
goto dealloc_cmap;
fb_info(&fb_info, "%s frame buffer device\n", fb_info.fix.id);
return 0;
dealloc_cmap:
fb_dealloc_cmap(&fb_info.cmap);
unmap_screen_base:
if (fb_info.screen_base) {
iounmap(fb_info.screen_base);
fb_info.screen_base = NULL;
}
return ret;
}
static int hpfb_dio_probe(struct dio_dev *d, const struct dio_device_id *ent)
{
unsigned long paddr, vaddr;
paddr = d->resource.start;
if (!request_mem_region(d->resource.start, resource_size(&d->resource), d->name))
return -EBUSY;
if (d->scode >= DIOII_SCBASE) {
vaddr = (unsigned long)ioremap(paddr, resource_size(&d->resource));
} else {
vaddr = paddr + DIO_VIRADDRBASE;
}
printk(KERN_INFO "Topcat found at DIO select code %d "
"(secondary id %02x)\n", d->scode, (d->id >> 8) & 0xff);
if (hpfb_init_one(paddr, vaddr)) {
if (d->scode >= DIOII_SCBASE)
iounmap((void *)vaddr);
return -ENOMEM;
}
return 0;
}
static void hpfb_remove_one(struct dio_dev *d)
{
unregister_framebuffer(&fb_info);
if (d->scode >= DIOII_SCBASE)
iounmap((void *)fb_regs);
release_mem_region(d->resource.start, resource_size(&d->resource));
fb_dealloc_cmap(&fb_info.cmap);
if (fb_info.screen_base)
iounmap(fb_info.screen_base);
}
int __init hpfb_init(void)
{
unsigned int sid;
unsigned char i;
int err;
#define INTFBVADDR 0xf0560000
#define INTFBPADDR 0x560000
if (!MACH_IS_HP300)
return -ENODEV;
if (fb_get_options("hpfb", NULL))
return -ENODEV;
err = dio_register_driver(&hpfb_driver);
if (err)
return err;
err = probe_kernel_read(&i, (unsigned char *)INTFBVADDR + DIO_IDOFF, 1);
if (!err && (i == DIO_ID_FBUFFER) && topcat_sid_ok(sid = DIO_SECID(INTFBVADDR))) {
if (!request_mem_region(INTFBPADDR, DIO_DEVSIZE, "Internal Topcat"))
return -EBUSY;
printk(KERN_INFO "Internal Topcat found (secondary id %02x)\n", sid);
if (hpfb_init_one(INTFBPADDR, INTFBVADDR)) {
return -ENOMEM;
}
}
return 0;
}
void __exit hpfb_cleanup_module(void)
{
dio_unregister_driver(&hpfb_driver);
}
