static int wm8505fb_init_hw(struct fb_info *info)
{
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
int i;
for (i = 0; i < 0x200; i += 4)
writel(0, fbi->regbase + i);
writel(fbi->fb.fix.smem_start, fbi->regbase + WMT_GOVR_FBADDR);
writel(fbi->fb.fix.smem_start, fbi->regbase + WMT_GOVR_FBADDR1);
writel(0x31c, fbi->regbase + WMT_GOVR_COLORSPACE);
writel(1, fbi->regbase + WMT_GOVR_COLORSPACE1);
writel(info->var.xres, fbi->regbase + WMT_GOVR_XRES);
writel(info->var.xres_virtual, fbi->regbase + WMT_GOVR_XRES_VIRTUAL);
writel(0xf, fbi->regbase + WMT_GOVR_FHI);
writel(4, fbi->regbase + WMT_GOVR_DVO_SET);
writel(1, fbi->regbase + WMT_GOVR_MIF_ENABLE);
writel(1, fbi->regbase + WMT_GOVR_REG_UPDATE);
return 0;
}
static int wm8505fb_set_timing(struct fb_info *info)
{
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
int h_start = info->var.left_margin;
int h_end = h_start + info->var.xres;
int h_all = h_end + info->var.right_margin;
int h_sync = info->var.hsync_len;
int v_start = info->var.upper_margin;
int v_end = v_start + info->var.yres;
int v_all = v_end + info->var.lower_margin;
int v_sync = info->var.vsync_len;
writel(0, fbi->regbase + WMT_GOVR_TG);
writel(h_start, fbi->regbase + WMT_GOVR_TIMING_H_START);
writel(h_end, fbi->regbase + WMT_GOVR_TIMING_H_END);
writel(h_all, fbi->regbase + WMT_GOVR_TIMING_H_ALL);
writel(h_sync, fbi->regbase + WMT_GOVR_TIMING_H_SYNC);
writel(v_start, fbi->regbase + WMT_GOVR_TIMING_V_START);
writel(v_end, fbi->regbase + WMT_GOVR_TIMING_V_END);
writel(v_all, fbi->regbase + WMT_GOVR_TIMING_V_ALL);
writel(v_sync, fbi->regbase + WMT_GOVR_TIMING_V_SYNC);
writel(1, fbi->regbase + WMT_GOVR_TG);
return 0;
}
static int wm8505fb_set_par(struct fb_info *info)
{
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
if (!fbi)
return -EINVAL;
if (info->var.bits_per_pixel == 32) {
info->var.red.offset = 16;
info->var.red.length = 8;
info->var.red.msb_right = 0;
info->var.green.offset = 8;
info->var.green.length = 8;
info->var.green.msb_right = 0;
info->var.blue.offset = 0;
info->var.blue.length = 8;
info->var.blue.msb_right = 0;
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->fix.line_length = info->var.xres_virtual << 2;
} else if (info->var.bits_per_pixel == 16) {
info->var.red.offset = 11;
info->var.red.length = 5;
info->var.red.msb_right = 0;
info->var.green.offset = 5;
info->var.green.length = 6;
info->var.green.msb_right = 0;
info->var.blue.offset = 0;
info->var.blue.length = 5;
info->var.blue.msb_right = 0;
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->fix.line_length = info->var.xres_virtual << 1;
}
wm8505fb_set_timing(info);
writel(fbi->contrast<<16 | fbi->contrast<<8 | fbi->contrast,
fbi->regbase + WMT_GOVR_CONTRAST);
return 0;
}
static ssize_t contrast_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fb_info *info = dev_get_drvdata(dev);
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
return sprintf(buf, "%d\n", fbi->contrast);
}
static ssize_t contrast_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fb_info *info = dev_get_drvdata(dev);
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
unsigned long tmp;
if (strict_strtoul(buf, 10, &tmp) || (tmp > 0xff))
return -EINVAL;
fbi->contrast = tmp;
wm8505fb_set_par(info);
return count;
}
static inline u_int chan_to_field(u_int chan, struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int wm8505fb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info) {
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
int ret = 1;
unsigned int val;
if (regno >= 256)
return -EINVAL;
if (info->var.grayscale)
red = green = blue =
(19595 * red + 38470 * green + 7471 * blue) >> 16;
switch (fbi->fb.fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
u32 *pal = info->pseudo_palette;
val = chan_to_field(red, &fbi->fb.var.red);
val |= chan_to_field(green, &fbi->fb.var.green);
val |= chan_to_field(blue, &fbi->fb.var.blue);
pal[regno] = val;
ret = 0;
}
break;
}
return ret;
}
static int wm8505fb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
writel(var->xoffset, fbi->regbase + WMT_GOVR_XPAN);
writel(var->yoffset, fbi->regbase + WMT_GOVR_YPAN);
return 0;
}
static int wm8505fb_blank(int blank, struct fb_info *info)
{
struct wm8505fb_info *fbi = to_wm8505fb_info(info);
switch (blank) {
case FB_BLANK_UNBLANK:
wm8505fb_set_timing(info);
break;
default:
writel(0, fbi->regbase + WMT_GOVR_TIMING_V_SYNC);
break;
}
return 0;
}
static int wm8505fb_probe(struct platform_device *pdev)
{
struct wm8505fb_info *fbi;
struct resource *res;
void *addr;
int ret;
struct fb_videomode of_mode;
struct device_node *np;
u32 bpp;
dma_addr_t fb_mem_phys;
unsigned long fb_mem_len;
void *fb_mem_virt;
ret = -ENOMEM;
fbi = NULL;
fbi = devm_kzalloc(&pdev->dev, sizeof(struct wm8505fb_info) +
sizeof(u32) * 16, GFP_KERNEL);
if (!fbi) {
dev_err(&pdev->dev, "Failed to initialize framebuffer device\n");
ret = -ENOMEM;
goto failed;
}
strcpy(fbi->fb.fix.id, DRIVER_NAME);
fbi->fb.fix.type = FB_TYPE_PACKED_PIXELS;
fbi->fb.fix.xpanstep = 1;
fbi->fb.fix.ypanstep = 1;
fbi->fb.fix.ywrapstep = 0;
fbi->fb.fix.accel = FB_ACCEL_NONE;
fbi->fb.fbops = &wm8505fb_ops;
fbi->fb.flags = FBINFO_DEFAULT
| FBINFO_HWACCEL_COPYAREA
| FBINFO_HWACCEL_FILLRECT
| FBINFO_HWACCEL_XPAN
| FBINFO_HWACCEL_YPAN
| FBINFO_VIRTFB
| FBINFO_PARTIAL_PAN_OK;
fbi->fb.node = -1;
addr = fbi;
addr = addr + sizeof(struct wm8505fb_info);
fbi->fb.pseudo_palette = addr;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no I/O memory resource defined\n");
ret = -ENODEV;
goto failed_fbi;
}
res = request_mem_region(res->start, resource_size(res), DRIVER_NAME);
if (res == NULL) {
dev_err(&pdev->dev, "failed to request I/O memory\n");
ret = -EBUSY;
goto failed_fbi;
}
fbi->regbase = ioremap(res->start, resource_size(res));
if (fbi->regbase == NULL) {
dev_err(&pdev->dev, "failed to map I/O memory\n");
ret = -EBUSY;
goto failed_free_res;
}
np = of_parse_phandle(pdev->dev.of_node, "default-mode", 0);
if (!np) {
pr_err("%s: No display description in Device Tree\n", __func__);
ret = -EINVAL;
goto failed_free_res;
}
ret = 0;
ret |= of_property_read_u32(np, "hactive", &of_mode.xres);
ret |= of_property_read_u32(np, "vactive", &of_mode.yres);
ret |= of_property_read_u32(np, "hback-porch", &of_mode.left_margin);
ret |= of_property_read_u32(np, "hfront-porch", &of_mode.right_margin);
ret |= of_property_read_u32(np, "hsync-len", &of_mode.hsync_len);
ret |= of_property_read_u32(np, "vback-porch", &of_mode.upper_margin);
ret |= of_property_read_u32(np, "vfront-porch", &of_mode.lower_margin);
ret |= of_property_read_u32(np, "vsync-len", &of_mode.vsync_len);
ret |= of_property_read_u32(np, "bpp", &bpp);
if (ret) {
pr_err("%s: Unable to read display properties\n", __func__);
goto failed_free_res;
}
of_mode.vmode = FB_VMODE_NONINTERLACED;
fb_videomode_to_var(&fbi->fb.var, &of_mode);
fbi->fb.var.nonstd = 0;
fbi->fb.var.activate = FB_ACTIVATE_NOW;
fbi->fb.var.height = -1;
fbi->fb.var.width = -1;
fb_mem_len = of_mode.xres * of_mode.yres * 2 * (bpp / 8);
fb_mem_virt = dma_alloc_coherent(&pdev->dev, fb_mem_len, &fb_mem_phys,
GFP_KERNEL);
if (!fb_mem_virt) {
pr_err("%s: Failed to allocate framebuffer\n", __func__);
return -ENOMEM;
};
fbi->fb.var.xres_virtual = of_mode.xres;
fbi->fb.var.yres_virtual = of_mode.yres * 2;
fbi->fb.var.bits_per_pixel = bpp;
fbi->fb.fix.smem_start = fb_mem_phys;
fbi->fb.fix.smem_len = fb_mem_len;
fbi->fb.screen_base = fb_mem_virt;
fbi->fb.screen_size = fb_mem_len;
if (fb_alloc_cmap(&fbi->fb.cmap, 256, 0) < 0) {
dev_err(&pdev->dev, "Failed to allocate color map\n");
ret = -ENOMEM;
goto failed_free_io;
}
wm8505fb_init_hw(&fbi->fb);
fbi->contrast = 0x80;
ret = wm8505fb_set_par(&fbi->fb);
if (ret) {
dev_err(&pdev->dev, "Failed to set parameters\n");
goto failed_free_cmap;
}
platform_set_drvdata(pdev, fbi);
ret = register_framebuffer(&fbi->fb);
if (ret < 0) {
dev_err(&pdev->dev,
"Failed to register framebuffer device: %d\n", ret);
goto failed_free_cmap;
}
ret = device_create_file(&pdev->dev, &dev_attr_contrast);
if (ret < 0) {
printk(KERN_WARNING "fb%d: failed to register attributes (%d)\n",
fbi->fb.node, ret);
}
printk(KERN_INFO "fb%d: %s frame buffer at 0x%lx-0x%lx\n",
fbi->fb.node, fbi->fb.fix.id, fbi->fb.fix.smem_start,
fbi->fb.fix.smem_start + fbi->fb.fix.smem_len - 1);
return 0;
failed_free_cmap:
if (fbi->fb.cmap.len)
fb_dealloc_cmap(&fbi->fb.cmap);
failed_free_io:
iounmap(fbi->regbase);
failed_free_res:
release_mem_region(res->start, resource_size(res));
failed_fbi:
platform_set_drvdata(pdev, NULL);
kfree(fbi);
failed:
return ret;
}
static int wm8505fb_remove(struct platform_device *pdev)
{
struct wm8505fb_info *fbi = platform_get_drvdata(pdev);
struct resource *res;
device_remove_file(&pdev->dev, &dev_attr_contrast);
unregister_framebuffer(&fbi->fb);
writel(0, fbi->regbase);
if (fbi->fb.cmap.len)
fb_dealloc_cmap(&fbi->fb.cmap);
iounmap(fbi->regbase);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
kfree(fbi);
return 0;
}
