static void vt8623fb_tilecursor(struct fb_info *info, struct fb_tilecursor *cursor)
{
struct vt8623fb_info *par = info->par;
svga_tilecursor(par->state.vgabase, info, cursor);
}
static inline u32 expand_color(u32 c)
{
return ((c & 1) | ((c & 2) << 7) | ((c & 4) << 14) | ((c & 8) << 21)) * 0xFF;
}
static void vt8623fb_iplan_imageblit(struct fb_info *info, const struct fb_image *image)
{
u32 fg = expand_color(image->fg_color);
u32 bg = expand_color(image->bg_color);
const u8 *src1, *src;
u8 __iomem *dst1;
u32 __iomem *dst;
u32 val;
int x, y;
src1 = image->data;
dst1 = info->screen_base + (image->dy * info->fix.line_length)
+ ((image->dx / 8) * 4);
for (y = 0; y < image->height; y++) {
src = src1;
dst = (u32 __iomem *) dst1;
for (x = 0; x < image->width; x += 8) {
val = *(src++) * 0x01010101;
val = (val & fg) | (~val & bg);
fb_writel(val, dst++);
}
src1 += image->width / 8;
dst1 += info->fix.line_length;
}
}
static void vt8623fb_iplan_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
u32 fg = expand_color(rect->color);
u8 __iomem *dst1;
u32 __iomem *dst;
int x, y;
dst1 = info->screen_base + (rect->dy * info->fix.line_length)
+ ((rect->dx / 8) * 4);
for (y = 0; y < rect->height; y++) {
dst = (u32 __iomem *) dst1;
for (x = 0; x < rect->width; x += 8) {
fb_writel(fg, dst++);
}
dst1 += info->fix.line_length;
}
}
static inline u32 expand_pixel(u32 c)
{
return (((c & 1) << 24) | ((c & 2) << 27) | ((c & 4) << 14) | ((c & 8) << 17) |
((c & 16) << 4) | ((c & 32) << 7) | ((c & 64) >> 6) | ((c & 128) >> 3)) * 0xF;
}
static void vt8623fb_cfb4_imageblit(struct fb_info *info, const struct fb_image *image)
{
u32 fg = image->fg_color * 0x11111111;
u32 bg = image->bg_color * 0x11111111;
const u8 *src1, *src;
u8 __iomem *dst1;
u32 __iomem *dst;
u32 val;
int x, y;
src1 = image->data;
dst1 = info->screen_base + (image->dy * info->fix.line_length)
+ ((image->dx / 8) * 4);
for (y = 0; y < image->height; y++) {
src = src1;
dst = (u32 __iomem *) dst1;
for (x = 0; x < image->width; x += 8) {
val = expand_pixel(*(src++));
val = (val & fg) | (~val & bg);
fb_writel(val, dst++);
}
src1 += image->width / 8;
dst1 += info->fix.line_length;
}
}
static void vt8623fb_imageblit(struct fb_info *info, const struct fb_image *image)
{
if ((info->var.bits_per_pixel == 4) && (image->depth == 1)
&& ((image->width % 8) == 0) && ((image->dx % 8) == 0)) {
if (info->fix.type == FB_TYPE_INTERLEAVED_PLANES)
vt8623fb_iplan_imageblit(info, image);
else
vt8623fb_cfb4_imageblit(info, image);
} else
cfb_imageblit(info, image);
}
static void vt8623fb_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
if ((info->var.bits_per_pixel == 4)
&& ((rect->width % 8) == 0) && ((rect->dx % 8) == 0)
&& (info->fix.type == FB_TYPE_INTERLEAVED_PLANES))
vt8623fb_iplan_fillrect(info, rect);
else
cfb_fillrect(info, rect);
}
static void vt8623_set_pixclock(struct fb_info *info, u32 pixclock)
{
struct vt8623fb_info *par = info->par;
u16 m, n, r;
u8 regval;
int rv;
rv = svga_compute_pll(&vt8623_pll, 1000000000 / pixclock, &m, &n, &r, info->node);
if (rv < 0) {
printk(KERN_ERR "fb%d: cannot set requested pixclock, keeping old value\n", info->node);
return;
}
regval = vga_r(par->state.vgabase, VGA_MIS_R);
vga_w(par->state.vgabase, VGA_MIS_W, regval | VGA_MIS_ENB_PLL_LOAD);
vga_wseq(par->state.vgabase, 0x46, (n | (r << 6)));
vga_wseq(par->state.vgabase, 0x47, m);
udelay(1000);
svga_wseq_mask(par->state.vgabase, 0x40, 0x02, 0x02);
svga_wseq_mask(par->state.vgabase, 0x40, 0x00, 0x02);
}
static int vt8623fb_open(struct fb_info *info, int user)
{
struct vt8623fb_info *par = info->par;
mutex_lock(&(par->open_lock));
if (par->ref_count == 0) {
void __iomem *vgabase = par->state.vgabase;
memset(&(par->state), 0, sizeof(struct vgastate));
par->state.vgabase = vgabase;
par->state.flags = VGA_SAVE_MODE | VGA_SAVE_FONTS | VGA_SAVE_CMAP;
par->state.num_crtc = 0xA2;
par->state.num_seq = 0x50;
save_vga(&(par->state));
}
par->ref_count++;
mutex_unlock(&(par->open_lock));
return 0;
}
static int vt8623fb_release(struct fb_info *info, int user)
{
struct vt8623fb_info *par = info->par;
mutex_lock(&(par->open_lock));
if (par->ref_count == 0) {
mutex_unlock(&(par->open_lock));
return -EINVAL;
}
if (par->ref_count == 1)
restore_vga(&(par->state));
par->ref_count--;
mutex_unlock(&(par->open_lock));
return 0;
}
static int vt8623fb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
int rv, mem, step;
rv = svga_match_format (vt8623fb_formats, var, NULL);
if (rv < 0)
{
printk(KERN_ERR "fb%d: unsupported mode requested\n", info->node);
return rv;
}
if (var->xres > var->xres_virtual)
var->xres_virtual = var->xres;
if (var->yres > var->yres_virtual)
var->yres_virtual = var->yres;
step = vt8623fb_formats[rv].xresstep - 1;
var->xres_virtual = (var->xres_virtual+step) & ~step;
mem = ((var->bits_per_pixel * var->xres_virtual) >> 3) * var->yres_virtual;
if (mem > info->screen_size)
{
printk(KERN_ERR "fb%d: not enough framebuffer memory (%d kB requested , %d kB available)\n", info->node, mem >> 10, (unsigned int) (info->screen_size >> 10));
return -EINVAL;
}
if ((var->bits_per_pixel == 0) && (mem > (256*1024)))
{
printk(KERN_ERR "fb%d: text framebuffer size too large (%d kB requested, 256 kB possible)\n", info->node, mem >> 10);
return -EINVAL;
}
rv = svga_check_timings (&vt8623_timing_regs, var, info->node);
if (rv < 0)
{
printk(KERN_ERR "fb%d: invalid timings requested\n", info->node);
return rv;
}
if (var->vmode & FB_VMODE_INTERLACED)
return -EINVAL;
return 0;
}
static int vt8623fb_set_par(struct fb_info *info)
{
u32 mode, offset_value, fetch_value, screen_size;
struct vt8623fb_info *par = info->par;
u32 bpp = info->var.bits_per_pixel;
if (bpp != 0) {
info->fix.ypanstep = 1;
info->fix.line_length = (info->var.xres_virtual * bpp) / 8;
info->flags &= ~FBINFO_MISC_TILEBLITTING;
info->tileops = NULL;
info->pixmap.blit_x = (bpp == 4) ? (1 << (8 - 1)) : (~(u32)0);
info->pixmap.blit_y = ~(u32)0;
offset_value = (info->var.xres_virtual * bpp) / 64;
fetch_value = ((info->var.xres * bpp) / 128) + 4;
if (bpp == 4)
fetch_value = (info->var.xres / 8) + 8;
screen_size = info->var.yres_virtual * info->fix.line_length;
} else {
info->fix.ypanstep = 16;
info->fix.line_length = 0;
info->flags |= FBINFO_MISC_TILEBLITTING;
info->tileops = &vt8623fb_tile_ops;
info->pixmap.blit_x = 1 << (8 - 1);
info->pixmap.blit_y = 1 << (16 - 1);
offset_value = info->var.xres_virtual / 16;
fetch_value = (info->var.xres / 8) + 8;
screen_size = (info->var.xres_virtual * info->var.yres_virtual) / 64;
}
info->var.xoffset = 0;
info->var.yoffset = 0;
info->var.activate = FB_ACTIVATE_NOW;
svga_wseq_mask(par->state.vgabase, 0x10, 0x01, 0x01);
svga_wcrt_mask(par->state.vgabase, 0x11, 0x00, 0x80);
svga_wcrt_mask(par->state.vgabase, 0x47, 0x00, 0x01);
svga_wseq_mask(par->state.vgabase, 0x01, 0x20, 0x20);
svga_wcrt_mask(par->state.vgabase, 0x36, 0x30, 0x30);
svga_wcrt_mask(par->state.vgabase, 0x17, 0x00, 0x80);
svga_set_default_gfx_regs(par->state.vgabase);
svga_set_default_atc_regs(par->state.vgabase);
svga_set_default_seq_regs(par->state.vgabase);
svga_set_default_crt_regs(par->state.vgabase);
svga_wcrt_multi(par->state.vgabase, vt8623_line_compare_regs, 0xFFFFFFFF);
svga_wcrt_multi(par->state.vgabase, vt8623_start_address_regs, 0);
svga_wcrt_multi(par->state.vgabase, vt8623_offset_regs, offset_value);
svga_wseq_multi(par->state.vgabase, vt8623_fetch_count_regs, fetch_value);
svga_wcrt_mask(par->state.vgabase, 0x03, 0x00, 0x60);
svga_wcrt_mask(par->state.vgabase, 0x05, 0x00, 0x60);
if (info->var.vmode & FB_VMODE_DOUBLE)
svga_wcrt_mask(par->state.vgabase, 0x09, 0x80, 0x80);
else
svga_wcrt_mask(par->state.vgabase, 0x09, 0x00, 0x80);
svga_wseq_mask(par->state.vgabase, 0x1E, 0xF0, 0xF0);
svga_wseq_mask(par->state.vgabase, 0x2A, 0x0F, 0x0F);
svga_wseq_mask(par->state.vgabase, 0x16, 0x08, 0xBF);
vga_wseq(par->state.vgabase, 0x17, 0x1F);
vga_wseq(par->state.vgabase, 0x18, 0x4E);
svga_wseq_mask(par->state.vgabase, 0x1A, 0x08, 0x08);
vga_wcrt(par->state.vgabase, 0x32, 0x00);
vga_wcrt(par->state.vgabase, 0x34, 0x00);
vga_wcrt(par->state.vgabase, 0x6A, 0x80);
vga_wcrt(par->state.vgabase, 0x6A, 0xC0);
vga_wgfx(par->state.vgabase, 0x20, 0x00);
vga_wgfx(par->state.vgabase, 0x21, 0x00);
vga_wgfx(par->state.vgabase, 0x22, 0x00);
mode = svga_match_format(vt8623fb_formats, &(info->var), &(info->fix));
switch (mode) {
case 0:
pr_debug("fb%d: text mode\n", info->node);
svga_set_textmode_vga_regs(par->state.vgabase);
svga_wseq_mask(par->state.vgabase, 0x15, 0x00, 0xFE);
svga_wcrt_mask(par->state.vgabase, 0x11, 0x60, 0x70);
break;
case 1:
pr_debug("fb%d: 4 bit pseudocolor\n", info->node);
vga_wgfx(par->state.vgabase, VGA_GFX_MODE, 0x40);
svga_wseq_mask(par->state.vgabase, 0x15, 0x20, 0xFE);
svga_wcrt_mask(par->state.vgabase, 0x11, 0x00, 0x70);
break;
case 2:
pr_debug("fb%d: 4 bit pseudocolor, planar\n", info->node);
svga_wseq_mask(par->state.vgabase, 0x15, 0x00, 0xFE);
svga_wcrt_mask(par->state.vgabase, 0x11, 0x00, 0x70);
break;
case 3:
pr_debug("fb%d: 8 bit pseudocolor\n", info->node);
svga_wseq_mask(par->state.vgabase, 0x15, 0x22, 0xFE);
break;
case 4:
pr_debug("fb%d: 5/6/5 truecolor\n", info->node);
svga_wseq_mask(par->state.vgabase, 0x15, 0xB6, 0xFE);
break;
case 5:
pr_debug("fb%d: 8/8/8 truecolor\n", info->node);
svga_wseq_mask(par->state.vgabase, 0x15, 0xAE, 0xFE);
break;
default:
printk(KERN_ERR "vt8623fb: unsupported mode - bug\n");
return (-EINVAL);
}
vt8623_set_pixclock(info, info->var.pixclock);
svga_set_timings(par->state.vgabase, &vt8623_timing_regs, &(info->var), 1, 1,
(info->var.vmode & FB_VMODE_DOUBLE) ? 2 : 1, 1,
1, info->node);
memset_io(info->screen_base, 0x00, screen_size);
svga_wcrt_mask(par->state.vgabase, 0x17, 0x80, 0x80);
svga_wcrt_mask(par->state.vgabase, 0x36, 0x00, 0x30);
svga_wseq_mask(par->state.vgabase, 0x01, 0x00, 0x20);
return 0;
}
static int vt8623fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *fb)
{
switch (fb->var.bits_per_pixel) {
case 0:
case 4:
if (regno >= 16)
return -EINVAL;
outb(0x0F, VGA_PEL_MSK);
outb(regno, VGA_PEL_IW);
outb(red >> 10, VGA_PEL_D);
outb(green >> 10, VGA_PEL_D);
outb(blue >> 10, VGA_PEL_D);
break;
case 8:
if (regno >= 256)
return -EINVAL;
outb(0xFF, VGA_PEL_MSK);
outb(regno, VGA_PEL_IW);
outb(red >> 10, VGA_PEL_D);
outb(green >> 10, VGA_PEL_D);
outb(blue >> 10, VGA_PEL_D);
break;
case 16:
if (regno >= 16)
return 0;
if (fb->var.green.length == 5)
((u32*)fb->pseudo_palette)[regno] = ((red & 0xF800) >> 1) |
((green & 0xF800) >> 6) | ((blue & 0xF800) >> 11);
else if (fb->var.green.length == 6)
((u32*)fb->pseudo_palette)[regno] = (red & 0xF800) |
((green & 0xFC00) >> 5) | ((blue & 0xF800) >> 11);
else
return -EINVAL;
break;
case 24:
case 32:
if (regno >= 16)
return 0;
((u32*)fb->pseudo_palette)[regno] = ((red & 0xFF00) << 8) |
(green & 0xFF00) | ((blue & 0xFF00) >> 8);
break;
default:
return -EINVAL;
}
return 0;
}
static int vt8623fb_blank(int blank_mode, struct fb_info *info)
{
struct vt8623fb_info *par = info->par;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
pr_debug("fb%d: unblank\n", info->node);
svga_wcrt_mask(par->state.vgabase, 0x36, 0x00, 0x30);
svga_wseq_mask(par->state.vgabase, 0x01, 0x00, 0x20);
break;
case FB_BLANK_NORMAL:
pr_debug("fb%d: blank\n", info->node);
svga_wcrt_mask(par->state.vgabase, 0x36, 0x00, 0x30);
svga_wseq_mask(par->state.vgabase, 0x01, 0x20, 0x20);
break;
case FB_BLANK_HSYNC_SUSPEND:
pr_debug("fb%d: DPMS standby (hsync off)\n", info->node);
svga_wcrt_mask(par->state.vgabase, 0x36, 0x10, 0x30);
svga_wseq_mask(par->state.vgabase, 0x01, 0x20, 0x20);
break;
case FB_BLANK_VSYNC_SUSPEND:
pr_debug("fb%d: DPMS suspend (vsync off)\n", info->node);
svga_wcrt_mask(par->state.vgabase, 0x36, 0x20, 0x30);
svga_wseq_mask(par->state.vgabase, 0x01, 0x20, 0x20);
break;
case FB_BLANK_POWERDOWN:
pr_debug("fb%d: DPMS off (no sync)\n", info->node);
svga_wcrt_mask(par->state.vgabase, 0x36, 0x30, 0x30);
svga_wseq_mask(par->state.vgabase, 0x01, 0x20, 0x20);
break;
}
return 0;
}
static int vt8623fb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct vt8623fb_info *par = info->par;
unsigned int offset;
if (info->var.bits_per_pixel == 0) {
offset = (var->yoffset / 16) * info->var.xres_virtual
+ var->xoffset;
offset = offset >> 3;
} else {
offset = (var->yoffset * info->fix.line_length) +
(var->xoffset * info->var.bits_per_pixel / 8);
offset = offset >> ((info->var.bits_per_pixel == 4) ? 2 : 1);
}
svga_wcrt_multi(par->state.vgabase, vt8623_start_address_regs, offset);
return 0;
}
static int __devinit vt8623_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct pci_bus_region bus_reg;
struct resource vga_res;
struct fb_info *info;
struct vt8623fb_info *par;
unsigned int memsize1, memsize2;
int rc;
if (! svga_primary_device(dev)) {
dev_info(&(dev->dev), "ignoring secondary device\n");
return -ENODEV;
}
info = framebuffer_alloc(sizeof(struct vt8623fb_info), &(dev->dev));
if (! info) {
dev_err(&(dev->dev), "cannot allocate memory\n");
return -ENOMEM;
}
par = info->par;
mutex_init(&par->open_lock);
info->flags = FBINFO_PARTIAL_PAN_OK | FBINFO_HWACCEL_YPAN;
info->fbops = &vt8623fb_ops;
rc = pci_enable_device(dev);
if (rc < 0) {
dev_err(info->device, "cannot enable PCI device\n");
goto err_enable_device;
}
rc = pci_request_regions(dev, "vt8623fb");
if (rc < 0) {
dev_err(info->device, "cannot reserve framebuffer region\n");
goto err_request_regions;
}
info->fix.smem_start = pci_resource_start(dev, 0);
info->fix.smem_len = pci_resource_len(dev, 0);
info->fix.mmio_start = pci_resource_start(dev, 1);
info->fix.mmio_len = pci_resource_len(dev, 1);
info->screen_base = pci_iomap(dev, 0, 0);
if (! info->screen_base) {
rc = -ENOMEM;
dev_err(info->device, "iomap for framebuffer failed\n");
goto err_iomap_1;
}
par->mmio_base = pci_iomap(dev, 1, 0);
if (! par->mmio_base) {
rc = -ENOMEM;
dev_err(info->device, "iomap for MMIO failed\n");
goto err_iomap_2;
}
bus_reg.start = 0;
bus_reg.end = 64 * 1024;
vga_res.flags = IORESOURCE_IO;
pcibios_bus_to_resource(dev, &vga_res, &bus_reg);
par->state.vgabase = (void __iomem *) vga_res.start;
memsize1 = (vga_rseq(par->state.vgabase, 0x34) + 1) >> 1;
memsize2 = vga_rseq(par->state.vgabase, 0x39) << 2;
if ((16 <= memsize1) && (memsize1 <= 64) && (memsize1 == memsize2))
info->screen_size = memsize1 << 20;
else {
dev_err(info->device, "memory size detection failed (%x %x), suppose 16 MB\n", memsize1, memsize2);
info->screen_size = 16 << 20;
}
info->fix.smem_len = info->screen_size;
strcpy(info->fix.id, "VIA VT8623");
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
info->fix.ypanstep = 0;
info->fix.accel = FB_ACCEL_NONE;
info->pseudo_palette = (void*)par->pseudo_palette;
kparam_block_sysfs_write(mode_option);
rc = fb_find_mode(&(info->var), info, mode_option, NULL, 0, NULL, 8);
kparam_unblock_sysfs_write(mode_option);
if (! ((rc == 1) || (rc == 2))) {
rc = -EINVAL;
dev_err(info->device, "mode %s not found\n", mode_option);
goto err_find_mode;
}
rc = fb_alloc_cmap(&info->cmap, 256, 0);
if (rc < 0) {
dev_err(info->device, "cannot allocate colormap\n");
goto err_alloc_cmap;
}
rc = register_framebuffer(info);
if (rc < 0) {
dev_err(info->device, "cannot register framebugger\n");
goto err_reg_fb;
}
printk(KERN_INFO "fb%d: %s on %s, %d MB RAM\n", info->node, info->fix.id,
pci_name(dev), info->fix.smem_len >> 20);
pci_set_drvdata(dev, info);
#ifdef CONFIG_MTRR
if (mtrr) {
par->mtrr_reg = -1;
par->mtrr_reg = mtrr_add(info->fix.smem_start, info->fix.smem_len, MTRR_TYPE_WRCOMB, 1);
}
#endif
return 0;
err_reg_fb:
fb_dealloc_cmap(&info->cmap);
err_alloc_cmap:
err_find_mode:
pci_iounmap(dev, par->mmio_base);
err_iomap_2:
pci_iounmap(dev, info->screen_base);
err_iomap_1:
pci_release_regions(dev);
err_request_regions:
err_enable_device:
framebuffer_release(info);
return rc;
}
static void __devexit vt8623_pci_remove(struct pci_dev *dev)
{
struct fb_info *info = pci_get_drvdata(dev);
if (info) {
struct vt8623fb_info *par = info->par;
#ifdef CONFIG_MTRR
if (par->mtrr_reg >= 0) {
mtrr_del(par->mtrr_reg, 0, 0);
par->mtrr_reg = -1;
}
#endif
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
pci_iounmap(dev, info->screen_base);
pci_iounmap(dev, par->mmio_base);
pci_release_regions(dev);
pci_set_drvdata(dev, NULL);
framebuffer_release(info);
}
}
static int vt8623_pci_suspend(struct pci_dev* dev, pm_message_t state)
{
struct fb_info *info = pci_get_drvdata(dev);
struct vt8623fb_info *par = info->par;
dev_info(info->device, "suspend\n");
console_lock();
mutex_lock(&(par->open_lock));
if ((state.event == PM_EVENT_FREEZE) || (par->ref_count == 0)) {
mutex_unlock(&(par->open_lock));
console_unlock();
return 0;
}
fb_set_suspend(info, 1);
pci_save_state(dev);
pci_disable_device(dev);
pci_set_power_state(dev, pci_choose_state(dev, state));
mutex_unlock(&(par->open_lock));
console_unlock();
return 0;
}
static int vt8623_pci_resume(struct pci_dev* dev)
{
struct fb_info *info = pci_get_drvdata(dev);
struct vt8623fb_info *par = info->par;
dev_info(info->device, "resume\n");
console_lock();
mutex_lock(&(par->open_lock));
if (par->ref_count == 0)
goto fail;
pci_set_power_state(dev, PCI_D0);
pci_restore_state(dev);
if (pci_enable_device(dev))
goto fail;
pci_set_master(dev);
vt8623fb_set_par(info);
fb_set_suspend(info, 0);
fail:
mutex_unlock(&(par->open_lock));
console_unlock();
return 0;
}
static void __exit vt8623fb_cleanup(void)
{
pr_debug("vt8623fb: cleaning up\n");
pci_unregister_driver(&vt8623fb_pci_driver);
}
static int __init vt8623fb_init(void)
{
#ifndef MODULE
char *option = NULL;
if (fb_get_options("vt8623fb", &option))
return -ENODEV;
if (option && *option)
mode_option = option;
#endif
pr_debug("vt8623fb: initializing\n");
return pci_register_driver(&vt8623fb_pci_driver);
}
