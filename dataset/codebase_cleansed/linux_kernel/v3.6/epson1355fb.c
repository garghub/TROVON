static inline u8 epson1355_read_reg(struct epson1355_par *par, int index)
{
return __raw_readb(par->reg_addr + index);
}
static inline void epson1355_write_reg(struct epson1355_par *par, u8 data, int index)
{
__raw_writeb(data, par->reg_addr + index);
}
static inline u16 epson1355_read_reg16(struct epson1355_par *par, int index)
{
u8 lo = epson1355_read_reg(par, index);
u8 hi = epson1355_read_reg(par, index + 1);
return (hi << 8) | lo;
}
static inline void epson1355_write_reg16(struct epson1355_par *par, u16 data, int index)
{
u8 lo = data & 0xff;
u8 hi = (data >> 8) & 0xff;
epson1355_write_reg(par, lo, index);
epson1355_write_reg(par, hi, index + 1);
}
static inline u32 epson1355_read_reg20(struct epson1355_par *par, int index)
{
u8 b0 = epson1355_read_reg(par, index);
u8 b1 = epson1355_read_reg(par, index + 1);
u8 b2 = epson1355_read_reg(par, index + 2);
return (b2 & 0x0f) << 16 | (b1 << 8) | b0;
}
static inline void epson1355_write_reg20(struct epson1355_par *par, u32 data, int index)
{
u8 b0 = data & 0xff;
u8 b1 = (data >> 8) & 0xff;
u8 b2 = (data >> 16) & 0x0f;
epson1355_write_reg(par, b0, index);
epson1355_write_reg(par, b1, index + 1);
epson1355_write_reg(par, b2, index + 2);
}
static void set_lut(struct epson1355_par *par, u8 index, u8 r, u8 g, u8 b)
{
epson1355_write_reg(par, index, REG_LUT_ADDR);
epson1355_write_reg(par, r, REG_LUT_DATA);
epson1355_write_reg(par, g, REG_LUT_DATA);
epson1355_write_reg(par, b, REG_LUT_DATA);
}
static int epson1355fb_setcolreg(unsigned regno, unsigned r, unsigned g,
unsigned b, unsigned transp,
struct fb_info *info)
{
struct epson1355_par *par = info->par;
if (info->var.grayscale)
r = g = b = (19595 * r + 38470 * g + 7471 * b) >> 16;
switch (info->fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno >= 16)
return -EINVAL;
((u32 *) info->pseudo_palette)[regno] =
(r & 0xf800) | (g & 0xfc00) >> 5 | (b & 0xf800) >> 11;
break;
case FB_VISUAL_PSEUDOCOLOR:
if (regno >= 256)
return -EINVAL;
set_lut(par, regno, r >> 8, g >> 8, b >> 8);
break;
default:
return -ENOSYS;
}
return 0;
}
static int epson1355fb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct epson1355_par *par = info->par;
u32 start;
if (var->xoffset != 0)
return -EINVAL;
if (var->yoffset + info->var.yres > info->var.yres_virtual)
return -EINVAL;
start = (info->fix.line_length >> 1) * var->yoffset;
epson1355_write_reg20(par, start, REG_SCRN1_DISP_START_ADDR0);
return 0;
}
static void lcd_enable(struct epson1355_par *par, int enable)
{
u8 mode = epson1355_read_reg(par, REG_DISPLAY_MODE);
if (enable)
mode |= 1;
else
mode &= ~1;
epson1355_write_reg(par, mode, REG_DISPLAY_MODE);
}
static void backlight_enable(int enable)
{
u8 pddr = clps_readb(PDDR);
if (enable)
pddr |= (1 << 5);
else
pddr &= ~(1 << 5);
clps_writeb(pddr, PDDR);
}
static void backlight_enable(int enable)
{
}
static int epson1355fb_blank(int blank_mode, struct fb_info *info)
{
struct epson1355_par *par = info->par;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
case FB_BLANK_NORMAL:
lcd_enable(par, 1);
backlight_enable(1);
break;
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
backlight_enable(0);
break;
case FB_BLANK_POWERDOWN:
backlight_enable(0);
lcd_enable(par, 0);
break;
default:
return -EINVAL;
}
return (blank_mode == FB_BLANK_NORMAL) ? 1 : 0;
}
static inline void epson1355fb_fb_writel(unsigned long v, unsigned long *a)
{
u16 *p = (u16 *) a;
u16 l = v & 0xffff;
u16 h = v >> 16;
fb_writew(l, p);
fb_writew(h, p + 1);
}
static inline unsigned long epson1355fb_fb_readl(const unsigned long *a)
{
const u16 *p = (u16 *) a;
u16 l = fb_readw(p);
u16 h = fb_readw(p + 1);
return (h << 16) | l;
}
static inline unsigned long copy_from_user16(void *to, const void *from,
unsigned long n)
{
u16 *dst = (u16 *) to;
u16 *src = (u16 *) from;
if (!access_ok(VERIFY_READ, from, n))
return n;
while (n > 1) {
u16 v;
if (__get_user(v, src))
return n;
fb_writew(v, dst);
src++, dst++;
n -= 2;
}
if (n) {
u8 v;
if (__get_user(v, ((u8 *) src)))
return n;
fb_writeb(v, dst);
}
return 0;
}
static inline unsigned long copy_to_user16(void *to, const void *from,
unsigned long n)
{
u16 *dst = (u16 *) to;
u16 *src = (u16 *) from;
if (!access_ok(VERIFY_WRITE, to, n))
return n;
while (n > 1) {
u16 v = fb_readw(src);
if (__put_user(v, dst))
return n;
src++, dst++;
n -= 2;
}
if (n) {
u8 v = fb_readb(src);
if (__put_user(v, ((u8 *) dst)))
return n;
}
return 0;
}
static ssize_t
epson1355fb_read(struct fb_info *info, char *buf, size_t count, loff_t * ppos)
{
unsigned long p = *ppos;
if (p >= info->fix.smem_len)
return 0;
if (count >= info->fix.smem_len)
count = info->fix.smem_len;
if (count + p > info->fix.smem_len)
count = info->fix.smem_len - p;
if (count) {
char *base_addr;
base_addr = info->screen_base;
count -= copy_to_user16(buf, base_addr + p, count);
if (!count)
return -EFAULT;
*ppos += count;
}
return count;
}
static ssize_t
epson1355fb_write(struct fb_info *info, const char *buf,
size_t count, loff_t * ppos)
{
unsigned long p = *ppos;
int err;
if (p > info->fix.smem_len)
return -ENOSPC;
if (count >= info->fix.smem_len)
count = info->fix.smem_len;
err = 0;
if (count + p > info->fix.smem_len) {
count = info->fix.smem_len - p;
err = -ENOSPC;
}
if (count) {
char *base_addr;
base_addr = info->screen_base;
count -= copy_from_user16(base_addr + p, buf, count);
*ppos += count;
err = -EFAULT;
}
if (count)
return count;
return err;
}
static __init unsigned int get_fb_size(struct fb_info *info)
{
unsigned int size = 2 * 1024 * 1024;
char *p = info->screen_base;
fb_writeb(1, p);
fb_writeb(0, p + 0x80000);
if (!fb_readb(p))
size = 512 * 1024;
fb_writeb(0, p);
return size;
}
static void __devinit fetch_hw_state(struct fb_info *info, struct epson1355_par *par)
{
struct fb_var_screeninfo *var = &info->var;
struct fb_fix_screeninfo *fix = &info->fix;
u8 panel, display;
u16 offset;
u32 xres, yres;
u32 xres_virtual, yres_virtual;
int bpp, lcd_bpp;
int is_color, is_dual, is_tft;
int lcd_enabled, crt_enabled;
fix->type = FB_TYPE_PACKED_PIXELS;
display = epson1355_read_reg(par, REG_DISPLAY_MODE);
bpp = epson1355_bpp_tab[(display >> 2) & 7];
switch (bpp) {
case 8:
fix->visual = FB_VISUAL_PSEUDOCOLOR;
var->bits_per_pixel = 8;
var->red.offset = var->green.offset = var->blue.offset = 0;
var->red.length = var->green.length = var->blue.length = 8;
break;
case 16:
fix->visual = FB_VISUAL_TRUECOLOR;
var->bits_per_pixel = 16;
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
break;
default:
BUG();
}
fb_alloc_cmap(&(info->cmap), 256, 0);
panel = epson1355_read_reg(par, REG_PANEL_TYPE);
is_color = (panel & 0x04) != 0;
is_dual = (panel & 0x02) != 0;
is_tft = (panel & 0x01) != 0;
crt_enabled = (display & 0x02) != 0;
lcd_enabled = (display & 0x01) != 0;
lcd_bpp = epson1355_width_tab[is_tft][(panel >> 4) & 3];
xres = (epson1355_read_reg(par, REG_HORZ_DISP_WIDTH) + 1) * 8;
yres = (epson1355_read_reg16(par, REG_VERT_DISP_HEIGHT0) + 1) *
((is_dual && !crt_enabled) ? 2 : 1);
offset = epson1355_read_reg16(par, REG_MEM_ADDR_OFFSET0) & 0x7ff;
xres_virtual = offset * 16 / bpp;
yres_virtual = fix->smem_len / (offset * 2);
var->xres = xres;
var->yres = yres;
var->xres_virtual = xres_virtual;
var->yres_virtual = yres_virtual;
var->xoffset = var->yoffset = 0;
fix->line_length = offset * 2;
fix->xpanstep = 0;
fix->ypanstep = 1;
fix->ywrapstep = 0;
fix->accel = FB_ACCEL_NONE;
var->grayscale = !is_color;
#ifdef DEBUG
printk(KERN_INFO
"epson1355fb: xres=%d, yres=%d, "
"is_color=%d, is_dual=%d, is_tft=%d\n",
xres, yres, is_color, is_dual, is_tft);
printk(KERN_INFO
"epson1355fb: bpp=%d, lcd_bpp=%d, "
"crt_enabled=%d, lcd_enabled=%d\n",
bpp, lcd_bpp, crt_enabled, lcd_enabled);
#endif
}
static void clearfb16(struct fb_info *info)
{
u16 *dst = (u16 *) info->screen_base;
unsigned long n = info->fix.smem_len;
while (n > 1) {
fb_writew(0, dst);
dst++, n -= 2;
}
if (n)
fb_writeb(0, dst);
}
static int epson1355fb_remove(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
struct epson1355_par *par = info->par;
backlight_enable(0);
if (par) {
lcd_enable(par, 0);
if (par && par->reg_addr)
iounmap((void *) par->reg_addr);
}
if (info) {
fb_dealloc_cmap(&info->cmap);
if (info->screen_base)
iounmap(info->screen_base);
framebuffer_release(info);
}
release_mem_region(EPSON1355FB_FB_PHYS, EPSON1355FB_FB_LEN);
release_mem_region(EPSON1355FB_REGS_PHYS, EPSON1355FB_REGS_LEN);
return 0;
}
static int __devinit epson1355fb_probe(struct platform_device *dev)
{
struct epson1355_par *default_par;
struct fb_info *info;
u8 revision;
int rc = 0;
if (!request_mem_region(EPSON1355FB_REGS_PHYS, EPSON1355FB_REGS_LEN, "S1D13505 registers")) {
printk(KERN_ERR "epson1355fb: unable to reserve "
"registers at 0x%0x\n", EPSON1355FB_REGS_PHYS);
rc = -EBUSY;
goto bail;
}
if (!request_mem_region(EPSON1355FB_FB_PHYS, EPSON1355FB_FB_LEN,
"S1D13505 framebuffer")) {
printk(KERN_ERR "epson1355fb: unable to reserve "
"framebuffer at 0x%0x\n", EPSON1355FB_FB_PHYS);
rc = -EBUSY;
goto bail;
}
info = framebuffer_alloc(sizeof(struct epson1355_par), &dev->dev);
if (!info) {
rc = -ENOMEM;
goto bail;
}
default_par = info->par;
default_par->reg_addr = (unsigned long) ioremap(EPSON1355FB_REGS_PHYS, EPSON1355FB_REGS_LEN);
if (!default_par->reg_addr) {
printk(KERN_ERR "epson1355fb: unable to map registers\n");
rc = -ENOMEM;
goto bail;
}
info->pseudo_palette = default_par->pseudo_palette;
info->screen_base = ioremap(EPSON1355FB_FB_PHYS, EPSON1355FB_FB_LEN);
if (!info->screen_base) {
printk(KERN_ERR "epson1355fb: unable to map framebuffer\n");
rc = -ENOMEM;
goto bail;
}
revision = epson1355_read_reg(default_par, REG_REVISION_CODE);
if ((revision >> 2) != 3) {
printk(KERN_INFO "epson1355fb: epson1355 not found\n");
rc = -ENODEV;
goto bail;
}
info->fix.mmio_start = EPSON1355FB_REGS_PHYS;
info->fix.mmio_len = EPSON1355FB_REGS_LEN;
info->fix.smem_start = EPSON1355FB_FB_PHYS;
info->fix.smem_len = get_fb_size(info);
printk(KERN_INFO "epson1355fb: regs mapped at 0x%lx, fb %d KiB mapped at 0x%p\n",
default_par->reg_addr, info->fix.smem_len / 1024, info->screen_base);
strcpy(info->fix.id, "S1D13505");
info->par = default_par;
info->fbops = &epson1355fb_fbops;
info->flags = FBINFO_DEFAULT | FBINFO_HWACCEL_YPAN;
fetch_hw_state(info, default_par);
clearfb16(info);
backlight_enable(1);
lcd_enable(default_par, 1);
if (register_framebuffer(info) < 0) {
rc = -EINVAL;
goto bail;
}
platform_set_drvdata(dev, info);
printk(KERN_INFO "fb%d: %s frame buffer device\n",
info->node, info->fix.id);
return 0;
bail:
epson1355fb_remove(dev);
return rc;
}
int __init epson1355fb_init(void)
{
int ret = 0;
if (fb_get_options("epson1355fb", NULL))
return -ENODEV;
ret = platform_driver_register(&epson1355fb_driver);
if (!ret) {
epson1355fb_device = platform_device_alloc("epson1355fb", 0);
if (epson1355fb_device)
ret = platform_device_add(epson1355fb_device);
else
ret = -ENOMEM;
if (ret) {
platform_device_put(epson1355fb_device);
platform_driver_unregister(&epson1355fb_driver);
}
}
return ret;
}
static void __exit epson1355fb_exit(void)
{
platform_device_unregister(epson1355fb_device);
platform_driver_unregister(&epson1355fb_driver);
}
