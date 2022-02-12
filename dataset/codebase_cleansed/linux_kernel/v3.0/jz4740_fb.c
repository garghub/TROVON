static unsigned int jzfb_num_ctrl_pins(struct jzfb *jzfb)
{
unsigned int num;
switch (jzfb->pdata->lcd_type) {
case JZ_LCD_TYPE_GENERIC_16_BIT:
num = 4;
break;
case JZ_LCD_TYPE_GENERIC_18_BIT:
num = 4;
break;
case JZ_LCD_TYPE_8BIT_SERIAL:
num = 3;
break;
case JZ_LCD_TYPE_SPECIAL_TFT_1:
case JZ_LCD_TYPE_SPECIAL_TFT_2:
case JZ_LCD_TYPE_SPECIAL_TFT_3:
num = 8;
break;
default:
num = 0;
break;
}
return num;
}
static unsigned int jzfb_num_data_pins(struct jzfb *jzfb)
{
unsigned int num;
switch (jzfb->pdata->lcd_type) {
case JZ_LCD_TYPE_GENERIC_16_BIT:
num = 16;
break;
case JZ_LCD_TYPE_GENERIC_18_BIT:
num = 18;
break;
case JZ_LCD_TYPE_8BIT_SERIAL:
num = 8;
break;
case JZ_LCD_TYPE_SPECIAL_TFT_1:
case JZ_LCD_TYPE_SPECIAL_TFT_2:
case JZ_LCD_TYPE_SPECIAL_TFT_3:
if (jzfb->pdata->bpp == 18)
num = 18;
else
num = 16;
break;
default:
num = 0;
break;
}
return num;
}
static inline uint32_t jzfb_convert_color_to_hw(unsigned val,
struct fb_bitfield *bf)
{
return (((val << bf->length) + 0x7FFF - val) >> 16) << bf->offset;
}
static int jzfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp, struct fb_info *fb)
{
uint32_t color;
if (regno >= 16)
return -EINVAL;
color = jzfb_convert_color_to_hw(red, &fb->var.red);
color |= jzfb_convert_color_to_hw(green, &fb->var.green);
color |= jzfb_convert_color_to_hw(blue, &fb->var.blue);
color |= jzfb_convert_color_to_hw(transp, &fb->var.transp);
((uint32_t *)(fb->pseudo_palette))[regno] = color;
return 0;
}
static int jzfb_get_controller_bpp(struct jzfb *jzfb)
{
switch (jzfb->pdata->bpp) {
case 18:
case 24:
return 32;
case 15:
return 16;
default:
return jzfb->pdata->bpp;
}
}
static struct fb_videomode *jzfb_get_mode(struct jzfb *jzfb,
struct fb_var_screeninfo *var)
{
size_t i;
struct fb_videomode *mode = jzfb->pdata->modes;
for (i = 0; i < jzfb->pdata->num_modes; ++i, ++mode) {
if (mode->xres == var->xres && mode->yres == var->yres)
return mode;
}
return NULL;
}
static int jzfb_check_var(struct fb_var_screeninfo *var, struct fb_info *fb)
{
struct jzfb *jzfb = fb->par;
struct fb_videomode *mode;
if (var->bits_per_pixel != jzfb_get_controller_bpp(jzfb) &&
var->bits_per_pixel != jzfb->pdata->bpp)
return -EINVAL;
mode = jzfb_get_mode(jzfb, var);
if (mode == NULL)
return -EINVAL;
fb_videomode_to_var(var, mode);
switch (jzfb->pdata->bpp) {
case 8:
break;
case 15:
var->red.offset = 10;
var->red.length = 5;
var->green.offset = 6;
var->green.length = 5;
var->blue.offset = 0;
var->blue.length = 5;
break;
case 16:
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
break;
case 18:
var->red.offset = 16;
var->red.length = 6;
var->green.offset = 8;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 6;
var->bits_per_pixel = 32;
break;
case 32:
case 24:
var->transp.offset = 24;
var->transp.length = 8;
var->red.offset = 16;
var->red.length = 8;
var->green.offset = 8;
var->green.length = 8;
var->blue.offset = 0;
var->blue.length = 8;
var->bits_per_pixel = 32;
break;
default:
break;
}
return 0;
}
static int jzfb_set_par(struct fb_info *info)
{
struct jzfb *jzfb = info->par;
struct jz4740_fb_platform_data *pdata = jzfb->pdata;
struct fb_var_screeninfo *var = &info->var;
struct fb_videomode *mode;
uint16_t hds, vds;
uint16_t hde, vde;
uint16_t ht, vt;
uint32_t ctrl;
uint32_t cfg;
unsigned long rate;
mode = jzfb_get_mode(jzfb, var);
if (mode == NULL)
return -EINVAL;
if (mode == info->mode)
return 0;
info->mode = mode;
hds = mode->hsync_len + mode->left_margin;
hde = hds + mode->xres;
ht = hde + mode->right_margin;
vds = mode->vsync_len + mode->upper_margin;
vde = vds + mode->yres;
vt = vde + mode->lower_margin;
ctrl = JZ_LCD_CTRL_OFUP | JZ_LCD_CTRL_BURST_16;
switch (pdata->bpp) {
case 1:
ctrl |= JZ_LCD_CTRL_BPP_1;
break;
case 2:
ctrl |= JZ_LCD_CTRL_BPP_2;
break;
case 4:
ctrl |= JZ_LCD_CTRL_BPP_4;
break;
case 8:
ctrl |= JZ_LCD_CTRL_BPP_8;
break;
case 15:
ctrl |= JZ_LCD_CTRL_RGB555;
case 16:
ctrl |= JZ_LCD_CTRL_BPP_15_16;
break;
case 18:
case 24:
case 32:
ctrl |= JZ_LCD_CTRL_BPP_18_24;
break;
default:
break;
}
cfg = pdata->lcd_type & 0xf;
if (!(mode->sync & FB_SYNC_HOR_HIGH_ACT))
cfg |= JZ_LCD_CFG_HSYNC_ACTIVE_LOW;
if (!(mode->sync & FB_SYNC_VERT_HIGH_ACT))
cfg |= JZ_LCD_CFG_VSYNC_ACTIVE_LOW;
if (pdata->pixclk_falling_edge)
cfg |= JZ_LCD_CFG_PCLK_FALLING_EDGE;
if (pdata->date_enable_active_low)
cfg |= JZ_LCD_CFG_DE_ACTIVE_LOW;
if (pdata->lcd_type == JZ_LCD_TYPE_GENERIC_18_BIT)
cfg |= JZ_LCD_CFG_18_BIT;
if (mode->pixclock) {
rate = PICOS2KHZ(mode->pixclock) * 1000;
mode->refresh = rate / vt / ht;
} else {
if (pdata->lcd_type == JZ_LCD_TYPE_8BIT_SERIAL)
rate = mode->refresh * (vt + 2 * mode->xres) * ht;
else
rate = mode->refresh * vt * ht;
mode->pixclock = KHZ2PICOS(rate / 1000);
}
mutex_lock(&jzfb->lock);
if (!jzfb->is_enabled)
clk_enable(jzfb->ldclk);
else
ctrl |= JZ_LCD_CTRL_ENABLE;
switch (pdata->lcd_type) {
case JZ_LCD_TYPE_SPECIAL_TFT_1:
case JZ_LCD_TYPE_SPECIAL_TFT_2:
case JZ_LCD_TYPE_SPECIAL_TFT_3:
writel(pdata->special_tft_config.spl, jzfb->base + JZ_REG_LCD_SPL);
writel(pdata->special_tft_config.cls, jzfb->base + JZ_REG_LCD_CLS);
writel(pdata->special_tft_config.ps, jzfb->base + JZ_REG_LCD_PS);
writel(pdata->special_tft_config.ps, jzfb->base + JZ_REG_LCD_REV);
break;
default:
cfg |= JZ_LCD_CFG_PS_DISABLE;
cfg |= JZ_LCD_CFG_CLS_DISABLE;
cfg |= JZ_LCD_CFG_SPL_DISABLE;
cfg |= JZ_LCD_CFG_REV_DISABLE;
break;
}
writel(mode->hsync_len, jzfb->base + JZ_REG_LCD_HSYNC);
writel(mode->vsync_len, jzfb->base + JZ_REG_LCD_VSYNC);
writel((ht << 16) | vt, jzfb->base + JZ_REG_LCD_VAT);
writel((hds << 16) | hde, jzfb->base + JZ_REG_LCD_DAH);
writel((vds << 16) | vde, jzfb->base + JZ_REG_LCD_DAV);
writel(cfg, jzfb->base + JZ_REG_LCD_CFG);
writel(ctrl, jzfb->base + JZ_REG_LCD_CTRL);
if (!jzfb->is_enabled)
clk_disable(jzfb->ldclk);
mutex_unlock(&jzfb->lock);
clk_set_rate(jzfb->lpclk, rate);
clk_set_rate(jzfb->ldclk, rate * 3);
return 0;
}
static void jzfb_enable(struct jzfb *jzfb)
{
uint32_t ctrl;
clk_enable(jzfb->ldclk);
jz_gpio_bulk_resume(jz_lcd_ctrl_pins, jzfb_num_ctrl_pins(jzfb));
jz_gpio_bulk_resume(jz_lcd_data_pins, jzfb_num_data_pins(jzfb));
writel(0, jzfb->base + JZ_REG_LCD_STATE);
writel(jzfb->framedesc->next, jzfb->base + JZ_REG_LCD_DA0);
ctrl = readl(jzfb->base + JZ_REG_LCD_CTRL);
ctrl |= JZ_LCD_CTRL_ENABLE;
ctrl &= ~JZ_LCD_CTRL_DISABLE;
writel(ctrl, jzfb->base + JZ_REG_LCD_CTRL);
}
static void jzfb_disable(struct jzfb *jzfb)
{
uint32_t ctrl;
ctrl = readl(jzfb->base + JZ_REG_LCD_CTRL);
ctrl |= JZ_LCD_CTRL_DISABLE;
writel(ctrl, jzfb->base + JZ_REG_LCD_CTRL);
do {
ctrl = readl(jzfb->base + JZ_REG_LCD_STATE);
} while (!(ctrl & JZ_LCD_STATE_DISABLED));
jz_gpio_bulk_suspend(jz_lcd_ctrl_pins, jzfb_num_ctrl_pins(jzfb));
jz_gpio_bulk_suspend(jz_lcd_data_pins, jzfb_num_data_pins(jzfb));
clk_disable(jzfb->ldclk);
}
static int jzfb_blank(int blank_mode, struct fb_info *info)
{
struct jzfb *jzfb = info->par;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
mutex_lock(&jzfb->lock);
if (jzfb->is_enabled) {
mutex_unlock(&jzfb->lock);
return 0;
}
jzfb_enable(jzfb);
jzfb->is_enabled = 1;
mutex_unlock(&jzfb->lock);
break;
default:
mutex_lock(&jzfb->lock);
if (!jzfb->is_enabled) {
mutex_unlock(&jzfb->lock);
return 0;
}
jzfb_disable(jzfb);
jzfb->is_enabled = 0;
mutex_unlock(&jzfb->lock);
break;
}
return 0;
}
static int jzfb_alloc_devmem(struct jzfb *jzfb)
{
int max_videosize = 0;
struct fb_videomode *mode = jzfb->pdata->modes;
void *page;
int i;
for (i = 0; i < jzfb->pdata->num_modes; ++mode, ++i) {
if (max_videosize < mode->xres * mode->yres)
max_videosize = mode->xres * mode->yres;
}
max_videosize *= jzfb_get_controller_bpp(jzfb) >> 3;
jzfb->framedesc = dma_alloc_coherent(&jzfb->pdev->dev,
sizeof(*jzfb->framedesc),
&jzfb->framedesc_phys, GFP_KERNEL);
if (!jzfb->framedesc)
return -ENOMEM;
jzfb->vidmem_size = PAGE_ALIGN(max_videosize);
jzfb->vidmem = dma_alloc_coherent(&jzfb->pdev->dev,
jzfb->vidmem_size,
&jzfb->vidmem_phys, GFP_KERNEL);
if (!jzfb->vidmem)
goto err_free_framedesc;
for (page = jzfb->vidmem;
page < jzfb->vidmem + PAGE_ALIGN(jzfb->vidmem_size);
page += PAGE_SIZE) {
SetPageReserved(virt_to_page(page));
}
jzfb->framedesc->next = jzfb->framedesc_phys;
jzfb->framedesc->addr = jzfb->vidmem_phys;
jzfb->framedesc->id = 0xdeafbead;
jzfb->framedesc->cmd = 0;
jzfb->framedesc->cmd |= max_videosize / 4;
return 0;
err_free_framedesc:
dma_free_coherent(&jzfb->pdev->dev, sizeof(*jzfb->framedesc),
jzfb->framedesc, jzfb->framedesc_phys);
return -ENOMEM;
}
static void jzfb_free_devmem(struct jzfb *jzfb)
{
dma_free_coherent(&jzfb->pdev->dev, jzfb->vidmem_size,
jzfb->vidmem, jzfb->vidmem_phys);
dma_free_coherent(&jzfb->pdev->dev, sizeof(*jzfb->framedesc),
jzfb->framedesc, jzfb->framedesc_phys);
}
static int __devinit jzfb_probe(struct platform_device *pdev)
{
int ret;
struct jzfb *jzfb;
struct fb_info *fb;
struct jz4740_fb_platform_data *pdata = pdev->dev.platform_data;
struct resource *mem;
if (!pdata) {
dev_err(&pdev->dev, "Missing platform data\n");
return -ENXIO;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "Failed to get register memory resource\n");
return -ENXIO;
}
mem = request_mem_region(mem->start, resource_size(mem), pdev->name);
if (!mem) {
dev_err(&pdev->dev, "Failed to request register memory region\n");
return -EBUSY;
}
fb = framebuffer_alloc(sizeof(struct jzfb), &pdev->dev);
if (!fb) {
dev_err(&pdev->dev, "Failed to allocate framebuffer device\n");
ret = -ENOMEM;
goto err_release_mem_region;
}
fb->fbops = &jzfb_ops;
fb->flags = FBINFO_DEFAULT;
jzfb = fb->par;
jzfb->pdev = pdev;
jzfb->pdata = pdata;
jzfb->mem = mem;
jzfb->ldclk = clk_get(&pdev->dev, "lcd");
if (IS_ERR(jzfb->ldclk)) {
ret = PTR_ERR(jzfb->ldclk);
dev_err(&pdev->dev, "Failed to get lcd clock: %d\n", ret);
goto err_framebuffer_release;
}
jzfb->lpclk = clk_get(&pdev->dev, "lcd_pclk");
if (IS_ERR(jzfb->lpclk)) {
ret = PTR_ERR(jzfb->lpclk);
dev_err(&pdev->dev, "Failed to get lcd pixel clock: %d\n", ret);
goto err_put_ldclk;
}
jzfb->base = ioremap(mem->start, resource_size(mem));
if (!jzfb->base) {
dev_err(&pdev->dev, "Failed to ioremap register memory region\n");
ret = -EBUSY;
goto err_put_lpclk;
}
platform_set_drvdata(pdev, jzfb);
mutex_init(&jzfb->lock);
fb_videomode_to_modelist(pdata->modes, pdata->num_modes,
&fb->modelist);
fb_videomode_to_var(&fb->var, pdata->modes);
fb->var.bits_per_pixel = pdata->bpp;
jzfb_check_var(&fb->var, fb);
ret = jzfb_alloc_devmem(jzfb);
if (ret) {
dev_err(&pdev->dev, "Failed to allocate video memory\n");
goto err_iounmap;
}
fb->fix = jzfb_fix;
fb->fix.line_length = fb->var.bits_per_pixel * fb->var.xres / 8;
fb->fix.mmio_start = mem->start;
fb->fix.mmio_len = resource_size(mem);
fb->fix.smem_start = jzfb->vidmem_phys;
fb->fix.smem_len = fb->fix.line_length * fb->var.yres;
fb->screen_base = jzfb->vidmem;
fb->pseudo_palette = jzfb->pseudo_palette;
fb_alloc_cmap(&fb->cmap, 256, 0);
clk_enable(jzfb->ldclk);
jzfb->is_enabled = 1;
writel(jzfb->framedesc->next, jzfb->base + JZ_REG_LCD_DA0);
fb->mode = NULL;
jzfb_set_par(fb);
jz_gpio_bulk_request(jz_lcd_ctrl_pins, jzfb_num_ctrl_pins(jzfb));
jz_gpio_bulk_request(jz_lcd_data_pins, jzfb_num_data_pins(jzfb));
ret = register_framebuffer(fb);
if (ret) {
dev_err(&pdev->dev, "Failed to register framebuffer: %d\n", ret);
goto err_free_devmem;
}
jzfb->fb = fb;
return 0;
err_free_devmem:
jz_gpio_bulk_free(jz_lcd_ctrl_pins, jzfb_num_ctrl_pins(jzfb));
jz_gpio_bulk_free(jz_lcd_data_pins, jzfb_num_data_pins(jzfb));
fb_dealloc_cmap(&fb->cmap);
jzfb_free_devmem(jzfb);
err_iounmap:
iounmap(jzfb->base);
err_put_lpclk:
clk_put(jzfb->lpclk);
err_put_ldclk:
clk_put(jzfb->ldclk);
err_framebuffer_release:
framebuffer_release(fb);
err_release_mem_region:
release_mem_region(mem->start, resource_size(mem));
return ret;
}
static int __devexit jzfb_remove(struct platform_device *pdev)
{
struct jzfb *jzfb = platform_get_drvdata(pdev);
jzfb_blank(FB_BLANK_POWERDOWN, jzfb->fb);
jz_gpio_bulk_free(jz_lcd_ctrl_pins, jzfb_num_ctrl_pins(jzfb));
jz_gpio_bulk_free(jz_lcd_data_pins, jzfb_num_data_pins(jzfb));
iounmap(jzfb->base);
release_mem_region(jzfb->mem->start, resource_size(jzfb->mem));
fb_dealloc_cmap(&jzfb->fb->cmap);
jzfb_free_devmem(jzfb);
platform_set_drvdata(pdev, NULL);
clk_put(jzfb->lpclk);
clk_put(jzfb->ldclk);
framebuffer_release(jzfb->fb);
return 0;
}
static int jzfb_suspend(struct device *dev)
{
struct jzfb *jzfb = dev_get_drvdata(dev);
console_lock();
fb_set_suspend(jzfb->fb, 1);
console_unlock();
mutex_lock(&jzfb->lock);
if (jzfb->is_enabled)
jzfb_disable(jzfb);
mutex_unlock(&jzfb->lock);
return 0;
}
static int jzfb_resume(struct device *dev)
{
struct jzfb *jzfb = dev_get_drvdata(dev);
clk_enable(jzfb->ldclk);
mutex_lock(&jzfb->lock);
if (jzfb->is_enabled)
jzfb_enable(jzfb);
mutex_unlock(&jzfb->lock);
console_lock();
fb_set_suspend(jzfb->fb, 0);
console_unlock();
return 0;
}
static int __init jzfb_init(void)
{
return platform_driver_register(&jzfb_driver);
}
static void __exit jzfb_exit(void)
{
platform_driver_unregister(&jzfb_driver);
}
