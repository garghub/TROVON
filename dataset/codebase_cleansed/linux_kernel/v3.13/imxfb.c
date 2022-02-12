static inline int is_imx1_fb(struct imxfb_info *fbi)
{
return fbi->devtype == IMX1_FB;
}
static inline u_int chan_to_field(u_int chan, struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int imxfb_setpalettereg(u_int regno, u_int red, u_int green, u_int blue,
u_int trans, struct fb_info *info)
{
struct imxfb_info *fbi = info->par;
u_int val, ret = 1;
#define CNVT_TOHW(val,width) ((((val)<<(width))+0x7FFF-(val))>>16)
if (regno < fbi->palette_size) {
val = (CNVT_TOHW(red, 4) << 8) |
(CNVT_TOHW(green,4) << 4) |
CNVT_TOHW(blue, 4);
writel(val, fbi->regs + 0x800 + (regno << 2));
ret = 0;
}
return ret;
}
static int imxfb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int trans, struct fb_info *info)
{
struct imxfb_info *fbi = info->par;
unsigned int val;
int ret = 1;
if (fbi->cmap_inverse) {
red = 0xffff - red;
green = 0xffff - green;
blue = 0xffff - blue;
}
if (info->var.grayscale)
red = green = blue = (19595 * red + 38470 * green +
7471 * blue) >> 16;
switch (info->fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
u32 *pal = info->pseudo_palette;
val = chan_to_field(red, &info->var.red);
val |= chan_to_field(green, &info->var.green);
val |= chan_to_field(blue, &info->var.blue);
pal[regno] = val;
ret = 0;
}
break;
case FB_VISUAL_STATIC_PSEUDOCOLOR:
case FB_VISUAL_PSEUDOCOLOR:
ret = imxfb_setpalettereg(regno, red, green, blue, trans, info);
break;
}
return ret;
}
static const struct imx_fb_videomode *imxfb_find_mode(struct imxfb_info *fbi)
{
struct imx_fb_videomode *m;
int i;
if (!fb_mode)
return &fbi->mode[0];
for (i = 0, m = &fbi->mode[0]; i < fbi->num_modes; i++, m++) {
if (!strcmp(m->mode.name, fb_mode))
return m;
}
return NULL;
}
static int imxfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct imxfb_info *fbi = info->par;
struct imxfb_rgb *rgb;
const struct imx_fb_videomode *imxfb_mode;
unsigned long lcd_clk;
unsigned long long tmp;
u32 pcr = 0;
if (var->xres < MIN_XRES)
var->xres = MIN_XRES;
if (var->yres < MIN_YRES)
var->yres = MIN_YRES;
imxfb_mode = imxfb_find_mode(fbi);
if (!imxfb_mode)
return -EINVAL;
var->xres = imxfb_mode->mode.xres;
var->yres = imxfb_mode->mode.yres;
var->bits_per_pixel = imxfb_mode->bpp;
var->pixclock = imxfb_mode->mode.pixclock;
var->hsync_len = imxfb_mode->mode.hsync_len;
var->left_margin = imxfb_mode->mode.left_margin;
var->right_margin = imxfb_mode->mode.right_margin;
var->vsync_len = imxfb_mode->mode.vsync_len;
var->upper_margin = imxfb_mode->mode.upper_margin;
var->lower_margin = imxfb_mode->mode.lower_margin;
var->sync = imxfb_mode->mode.sync;
var->xres_virtual = max(var->xres_virtual, var->xres);
var->yres_virtual = max(var->yres_virtual, var->yres);
pr_debug("var->bits_per_pixel=%d\n", var->bits_per_pixel);
lcd_clk = clk_get_rate(fbi->clk_per);
tmp = var->pixclock * (unsigned long long)lcd_clk;
do_div(tmp, 1000000);
if (do_div(tmp, 1000000) > 500000)
tmp++;
pcr = (unsigned int)tmp;
if (--pcr > 0x3F) {
pcr = 0x3F;
printk(KERN_WARNING "Must limit pixel clock to %luHz\n",
lcd_clk / pcr);
}
switch (var->bits_per_pixel) {
case 32:
pcr |= PCR_BPIX_18;
rgb = &def_rgb_18;
break;
case 16:
default:
if (is_imx1_fb(fbi))
pcr |= PCR_BPIX_12;
else
pcr |= PCR_BPIX_16;
if (imxfb_mode->pcr & PCR_TFT)
rgb = &def_rgb_16_tft;
else
rgb = &def_rgb_16_stn;
break;
case 8:
pcr |= PCR_BPIX_8;
rgb = &def_rgb_8;
break;
}
pcr |= imxfb_mode->pcr & ~(0x3f | (7 << 25));
fbi->pcr = pcr;
var->red = rgb->red;
var->green = rgb->green;
var->blue = rgb->blue;
var->transp = rgb->transp;
pr_debug("RGBT length = %d:%d:%d:%d\n",
var->red.length, var->green.length, var->blue.length,
var->transp.length);
pr_debug("RGBT offset = %d:%d:%d:%d\n",
var->red.offset, var->green.offset, var->blue.offset,
var->transp.offset);
return 0;
}
static int imxfb_set_par(struct fb_info *info)
{
struct imxfb_info *fbi = info->par;
struct fb_var_screeninfo *var = &info->var;
if (var->bits_per_pixel == 16 || var->bits_per_pixel == 32)
info->fix.visual = FB_VISUAL_TRUECOLOR;
else if (!fbi->cmap_static)
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
else {
info->fix.visual = FB_VISUAL_STATIC_PSEUDOCOLOR;
}
info->fix.line_length = var->xres_virtual * var->bits_per_pixel / 8;
fbi->palette_size = var->bits_per_pixel == 8 ? 256 : 16;
imxfb_activate_var(var, info);
return 0;
}
static int imxfb_bl_get_brightness(struct backlight_device *bl)
{
struct imxfb_info *fbi = bl_get_data(bl);
return readl(fbi->regs + LCDC_PWMR) & 0xFF;
}
static int imxfb_bl_update_status(struct backlight_device *bl)
{
struct imxfb_info *fbi = bl_get_data(bl);
int brightness = bl->props.brightness;
if (!fbi->pwmr)
return 0;
if (bl->props.power != FB_BLANK_UNBLANK)
brightness = 0;
if (bl->props.fb_blank != FB_BLANK_UNBLANK)
brightness = 0;
fbi->pwmr = (fbi->pwmr & ~0xFF) | brightness;
if (bl->props.fb_blank != FB_BLANK_UNBLANK) {
clk_prepare_enable(fbi->clk_ipg);
clk_prepare_enable(fbi->clk_ahb);
clk_prepare_enable(fbi->clk_per);
}
writel(fbi->pwmr, fbi->regs + LCDC_PWMR);
if (bl->props.fb_blank != FB_BLANK_UNBLANK) {
clk_disable_unprepare(fbi->clk_per);
clk_disable_unprepare(fbi->clk_ahb);
clk_disable_unprepare(fbi->clk_ipg);
}
return 0;
}
static void imxfb_init_backlight(struct imxfb_info *fbi)
{
struct backlight_properties props;
struct backlight_device *bl;
if (fbi->bl)
return;
memset(&props, 0, sizeof(struct backlight_properties));
props.max_brightness = 0xff;
props.type = BACKLIGHT_RAW;
writel(fbi->pwmr, fbi->regs + LCDC_PWMR);
bl = backlight_device_register("imxfb-bl", &fbi->pdev->dev, fbi,
&imxfb_lcdc_bl_ops, &props);
if (IS_ERR(bl)) {
dev_err(&fbi->pdev->dev, "error %ld on backlight register\n",
PTR_ERR(bl));
return;
}
fbi->bl = bl;
bl->props.power = FB_BLANK_UNBLANK;
bl->props.fb_blank = FB_BLANK_UNBLANK;
bl->props.brightness = imxfb_bl_get_brightness(bl);
}
static void imxfb_exit_backlight(struct imxfb_info *fbi)
{
if (fbi->bl)
backlight_device_unregister(fbi->bl);
}
static void imxfb_enable_controller(struct imxfb_info *fbi)
{
if (fbi->enabled)
return;
pr_debug("Enabling LCD controller\n");
writel(fbi->screen_dma, fbi->regs + LCDC_SSA);
writel(0x00000000, fbi->regs + LCDC_POS);
writel(readl(fbi->regs + LCDC_CPOS) & ~(CPOS_CC0 | CPOS_CC1),
fbi->regs + LCDC_CPOS);
writel(RMCR_LCDC_EN_MX1, fbi->regs + LCDC_RMCR);
clk_prepare_enable(fbi->clk_ipg);
clk_prepare_enable(fbi->clk_ahb);
clk_prepare_enable(fbi->clk_per);
fbi->enabled = true;
if (fbi->backlight_power)
fbi->backlight_power(1);
if (fbi->lcd_power)
fbi->lcd_power(1);
}
static void imxfb_disable_controller(struct imxfb_info *fbi)
{
if (!fbi->enabled)
return;
pr_debug("Disabling LCD controller\n");
if (fbi->backlight_power)
fbi->backlight_power(0);
if (fbi->lcd_power)
fbi->lcd_power(0);
clk_disable_unprepare(fbi->clk_per);
clk_disable_unprepare(fbi->clk_ipg);
clk_disable_unprepare(fbi->clk_ahb);
fbi->enabled = false;
writel(0, fbi->regs + LCDC_RMCR);
}
static int imxfb_blank(int blank, struct fb_info *info)
{
struct imxfb_info *fbi = info->par;
pr_debug("imxfb_blank: blank=%d\n", blank);
switch (blank) {
case FB_BLANK_POWERDOWN:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_NORMAL:
imxfb_disable_controller(fbi);
break;
case FB_BLANK_UNBLANK:
imxfb_enable_controller(fbi);
break;
}
return 0;
}
static int imxfb_activate_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct imxfb_info *fbi = info->par;
u32 ymax_mask = is_imx1_fb(fbi) ? YMAX_MASK_IMX1 : YMAX_MASK_IMX21;
pr_debug("var: xres=%d hslen=%d lm=%d rm=%d\n",
var->xres, var->hsync_len,
var->left_margin, var->right_margin);
pr_debug("var: yres=%d vslen=%d um=%d bm=%d\n",
var->yres, var->vsync_len,
var->upper_margin, var->lower_margin);
#if DEBUG_VAR
if (var->xres < 16 || var->xres > 1024)
printk(KERN_ERR "%s: invalid xres %d\n",
info->fix.id, var->xres);
if (var->hsync_len < 1 || var->hsync_len > 64)
printk(KERN_ERR "%s: invalid hsync_len %d\n",
info->fix.id, var->hsync_len);
if (var->left_margin > 255)
printk(KERN_ERR "%s: invalid left_margin %d\n",
info->fix.id, var->left_margin);
if (var->right_margin > 255)
printk(KERN_ERR "%s: invalid right_margin %d\n",
info->fix.id, var->right_margin);
if (var->yres < 1 || var->yres > ymax_mask)
printk(KERN_ERR "%s: invalid yres %d\n",
info->fix.id, var->yres);
if (var->vsync_len > 100)
printk(KERN_ERR "%s: invalid vsync_len %d\n",
info->fix.id, var->vsync_len);
if (var->upper_margin > 63)
printk(KERN_ERR "%s: invalid upper_margin %d\n",
info->fix.id, var->upper_margin);
if (var->lower_margin > 255)
printk(KERN_ERR "%s: invalid lower_margin %d\n",
info->fix.id, var->lower_margin);
#endif
writel(VPW_VPW(var->xres * var->bits_per_pixel / 8 / 4),
fbi->regs + LCDC_VPW);
writel(HCR_H_WIDTH(var->hsync_len - 1) |
HCR_H_WAIT_1(var->right_margin - 1) |
HCR_H_WAIT_2(var->left_margin - 3),
fbi->regs + LCDC_HCR);
writel(VCR_V_WIDTH(var->vsync_len) |
VCR_V_WAIT_1(var->lower_margin) |
VCR_V_WAIT_2(var->upper_margin),
fbi->regs + LCDC_VCR);
writel(SIZE_XMAX(var->xres) | (var->yres & ymax_mask),
fbi->regs + LCDC_SIZE);
writel(fbi->pcr, fbi->regs + LCDC_PCR);
#ifndef PWMR_BACKLIGHT_AVAILABLE
if (fbi->pwmr)
writel(fbi->pwmr, fbi->regs + LCDC_PWMR);
#endif
writel(fbi->lscr1, fbi->regs + LCDC_LSCR1);
if (fbi->dmacr)
writel(fbi->dmacr, fbi->regs + LCDC_DMACR);
return 0;
}
static int imxfb_suspend(struct platform_device *dev, pm_message_t state)
{
struct fb_info *info = platform_get_drvdata(dev);
struct imxfb_info *fbi = info->par;
pr_debug("%s\n", __func__);
imxfb_disable_controller(fbi);
return 0;
}
static int imxfb_resume(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
struct imxfb_info *fbi = info->par;
pr_debug("%s\n", __func__);
imxfb_enable_controller(fbi);
return 0;
}
static int imxfb_init_fbinfo(struct platform_device *pdev)
{
struct imx_fb_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct fb_info *info = dev_get_drvdata(&pdev->dev);
struct imxfb_info *fbi = info->par;
struct device_node *np;
pr_debug("%s\n",__func__);
info->pseudo_palette = kmalloc(sizeof(u32) * 16, GFP_KERNEL);
if (!info->pseudo_palette)
return -ENOMEM;
memset(fbi, 0, sizeof(struct imxfb_info));
fbi->devtype = pdev->id_entry->driver_data;
strlcpy(info->fix.id, IMX_NAME, sizeof(info->fix.id));
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.type_aux = 0;
info->fix.xpanstep = 0;
info->fix.ypanstep = 0;
info->fix.ywrapstep = 0;
info->fix.accel = FB_ACCEL_NONE;
info->var.nonstd = 0;
info->var.activate = FB_ACTIVATE_NOW;
info->var.height = -1;
info->var.width = -1;
info->var.accel_flags = 0;
info->var.vmode = FB_VMODE_NONINTERLACED;
info->fbops = &imxfb_ops;
info->flags = FBINFO_FLAG_DEFAULT |
FBINFO_READS_FAST;
if (pdata) {
info->var.grayscale = pdata->cmap_greyscale;
fbi->cmap_inverse = pdata->cmap_inverse;
fbi->cmap_static = pdata->cmap_static;
fbi->lscr1 = pdata->lscr1;
fbi->dmacr = pdata->dmacr;
fbi->pwmr = pdata->pwmr;
fbi->lcd_power = pdata->lcd_power;
fbi->backlight_power = pdata->backlight_power;
} else {
np = pdev->dev.of_node;
info->var.grayscale = of_property_read_bool(np,
"cmap-greyscale");
fbi->cmap_inverse = of_property_read_bool(np, "cmap-inverse");
fbi->cmap_static = of_property_read_bool(np, "cmap-static");
fbi->lscr1 = IMXFB_LSCR1_DEFAULT;
of_property_read_u32(np, "fsl,lscr1", &fbi->lscr1);
of_property_read_u32(np, "fsl,dmacr", &fbi->dmacr);
fbi->lcd_power = NULL;
fbi->backlight_power = NULL;
}
return 0;
}
static int imxfb_of_read_mode(struct device *dev, struct device_node *np,
struct imx_fb_videomode *imxfb_mode)
{
int ret;
struct fb_videomode *of_mode = &imxfb_mode->mode;
u32 bpp;
u32 pcr;
ret = of_property_read_string(np, "model", &of_mode->name);
if (ret)
of_mode->name = NULL;
ret = of_get_fb_videomode(np, of_mode, OF_USE_NATIVE_MODE);
if (ret) {
dev_err(dev, "Failed to get videomode from DT\n");
return ret;
}
ret = of_property_read_u32(np, "bits-per-pixel", &bpp);
ret |= of_property_read_u32(np, "fsl,pcr", &pcr);
if (ret) {
dev_err(dev, "Failed to read bpp and pcr from DT\n");
return -EINVAL;
}
if (bpp < 1 || bpp > 255) {
dev_err(dev, "Bits per pixel have to be between 1 and 255\n");
return -EINVAL;
}
imxfb_mode->bpp = bpp;
imxfb_mode->pcr = pcr;
return 0;
}
static int imxfb_probe(struct platform_device *pdev)
{
struct imxfb_info *fbi;
struct fb_info *info;
struct imx_fb_platform_data *pdata;
struct resource *res;
struct imx_fb_videomode *m;
const struct of_device_id *of_id;
int ret, i;
int bytes_per_pixel;
dev_info(&pdev->dev, "i.MX Framebuffer driver\n");
of_id = of_match_device(imxfb_of_dev_id, &pdev->dev);
if (of_id)
pdev->id_entry = of_id->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
pdata = dev_get_platdata(&pdev->dev);
info = framebuffer_alloc(sizeof(struct imxfb_info), &pdev->dev);
if (!info)
return -ENOMEM;
fbi = info->par;
platform_set_drvdata(pdev, info);
ret = imxfb_init_fbinfo(pdev);
if (ret < 0)
goto failed_init;
if (pdata) {
if (!fb_mode)
fb_mode = pdata->mode[0].mode.name;
fbi->mode = pdata->mode;
fbi->num_modes = pdata->num_modes;
} else {
struct device_node *display_np;
fb_mode = NULL;
display_np = of_parse_phandle(pdev->dev.of_node, "display", 0);
if (!display_np) {
dev_err(&pdev->dev, "No display defined in devicetree\n");
ret = -EINVAL;
goto failed_of_parse;
}
fbi->num_modes = 1;
fbi->mode = devm_kzalloc(&pdev->dev,
sizeof(struct imx_fb_videomode), GFP_KERNEL);
if (!fbi->mode) {
ret = -ENOMEM;
goto failed_of_parse;
}
ret = imxfb_of_read_mode(&pdev->dev, display_np, fbi->mode);
if (ret)
goto failed_of_parse;
}
m = &fbi->mode[0];
bytes_per_pixel = (m->bpp + 7) / 8;
for (i = 0; i < fbi->num_modes; i++, m++)
info->fix.smem_len = max_t(size_t, info->fix.smem_len,
m->mode.xres * m->mode.yres * bytes_per_pixel);
res = request_mem_region(res->start, resource_size(res),
DRIVER_NAME);
if (!res) {
ret = -EBUSY;
goto failed_req;
}
fbi->clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(fbi->clk_ipg)) {
ret = PTR_ERR(fbi->clk_ipg);
goto failed_getclock;
}
fbi->clk_ahb = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(fbi->clk_ahb)) {
ret = PTR_ERR(fbi->clk_ahb);
goto failed_getclock;
}
fbi->clk_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(fbi->clk_per)) {
ret = PTR_ERR(fbi->clk_per);
goto failed_getclock;
}
fbi->regs = ioremap(res->start, resource_size(res));
if (fbi->regs == NULL) {
dev_err(&pdev->dev, "Cannot map frame buffer registers\n");
ret = -ENOMEM;
goto failed_ioremap;
}
if (!pdata || !pdata->fixed_screen_cpu) {
fbi->map_size = PAGE_ALIGN(info->fix.smem_len);
fbi->map_cpu = dma_alloc_writecombine(&pdev->dev,
fbi->map_size, &fbi->map_dma, GFP_KERNEL);
if (!fbi->map_cpu) {
dev_err(&pdev->dev, "Failed to allocate video RAM: %d\n", ret);
ret = -ENOMEM;
goto failed_map;
}
info->screen_base = fbi->map_cpu;
fbi->screen_cpu = fbi->map_cpu;
fbi->screen_dma = fbi->map_dma;
info->fix.smem_start = fbi->screen_dma;
} else {
fbi->map_cpu = pdata->fixed_screen_cpu;
fbi->map_dma = pdata->fixed_screen_dma;
info->screen_base = fbi->map_cpu;
fbi->screen_cpu = fbi->map_cpu;
fbi->screen_dma = fbi->map_dma;
info->fix.smem_start = fbi->screen_dma;
}
if (pdata && pdata->init) {
ret = pdata->init(fbi->pdev);
if (ret)
goto failed_platform_init;
}
INIT_LIST_HEAD(&info->modelist);
for (i = 0; i < fbi->num_modes; i++)
fb_add_videomode(&fbi->mode[i].mode, &info->modelist);
imxfb_check_var(&info->var, info);
ret = fb_alloc_cmap(&info->cmap, 1 << info->var.bits_per_pixel, 0);
if (ret < 0)
goto failed_cmap;
imxfb_set_par(info);
ret = register_framebuffer(info);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register framebuffer\n");
goto failed_register;
}
imxfb_enable_controller(fbi);
fbi->pdev = pdev;
#ifdef PWMR_BACKLIGHT_AVAILABLE
imxfb_init_backlight(fbi);
#endif
return 0;
failed_register:
fb_dealloc_cmap(&info->cmap);
failed_cmap:
if (pdata && pdata->exit)
pdata->exit(fbi->pdev);
failed_platform_init:
if (pdata && !pdata->fixed_screen_cpu)
dma_free_writecombine(&pdev->dev,fbi->map_size,fbi->map_cpu,
fbi->map_dma);
failed_map:
iounmap(fbi->regs);
failed_ioremap:
failed_getclock:
release_mem_region(res->start, resource_size(res));
failed_req:
failed_of_parse:
kfree(info->pseudo_palette);
failed_init:
framebuffer_release(info);
return ret;
}
static int imxfb_remove(struct platform_device *pdev)
{
struct imx_fb_platform_data *pdata;
struct fb_info *info = platform_get_drvdata(pdev);
struct imxfb_info *fbi = info->par;
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
imxfb_disable_controller(fbi);
#ifdef PWMR_BACKLIGHT_AVAILABLE
imxfb_exit_backlight(fbi);
#endif
unregister_framebuffer(info);
pdata = dev_get_platdata(&pdev->dev);
if (pdata && pdata->exit)
pdata->exit(fbi->pdev);
fb_dealloc_cmap(&info->cmap);
kfree(info->pseudo_palette);
framebuffer_release(info);
iounmap(fbi->regs);
release_mem_region(res->start, resource_size(res));
return 0;
}
static void imxfb_shutdown(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
struct imxfb_info *fbi = info->par;
imxfb_disable_controller(fbi);
}
static int imxfb_setup(void)
{
#ifndef MODULE
char *opt, *options = NULL;
if (fb_get_options("imxfb", &options))
return -ENODEV;
if (!options || !*options)
return 0;
while ((opt = strsep(&options, ",")) != NULL) {
if (!*opt)
continue;
else
fb_mode = opt;
}
#endif
return 0;
}
static int __init imxfb_init(void)
{
int ret = imxfb_setup();
if (ret < 0)
return ret;
return platform_driver_probe(&imxfb_driver, imxfb_probe);
}
static void __exit imxfb_cleanup(void)
{
platform_driver_unregister(&imxfb_driver);
}
