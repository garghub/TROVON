static int lq035q1_control(struct spi_device *spi, unsigned char reg, unsigned short value)
{
int ret;
u8 regs[3] = { LQ035_INDEX, 0, 0 };
u8 dat[3] = { LQ035_DATA, 0, 0 };
if (!spi)
return -ENODEV;
regs[2] = reg;
dat[1] = value >> 8;
dat[2] = value & 0xFF;
ret = spi_write(spi, regs, ARRAY_SIZE(regs));
ret |= spi_write(spi, dat, ARRAY_SIZE(dat));
return ret;
}
static int __devinit lq035q1_spidev_probe(struct spi_device *spi)
{
int ret;
struct spi_control *ctl;
struct bfin_lq035q1fb_info *info = container_of(spi->dev.driver,
struct bfin_lq035q1fb_info,
spidrv.driver);
ctl = kzalloc(sizeof(*ctl), GFP_KERNEL);
if (!ctl)
return -ENOMEM;
ctl->mode = (info->disp_info->mode &
LQ035_DRIVER_OUTPUT_MASK) | LQ035_DRIVER_OUTPUT_DEFAULT;
ret = lq035q1_control(spi, LQ035_SHUT_CTL, LQ035_ON);
ret |= lq035q1_control(spi, LQ035_DRIVER_OUTPUT_CTL, ctl->mode);
if (ret) {
kfree(ctl);
return ret;
}
spi_set_drvdata(spi, ctl);
return 0;
}
static int lq035q1_spidev_remove(struct spi_device *spi)
{
return lq035q1_control(spi, LQ035_SHUT_CTL, LQ035_SHUT);
}
static int lq035q1_spidev_suspend(struct spi_device *spi, pm_message_t state)
{
return lq035q1_control(spi, LQ035_SHUT_CTL, LQ035_SHUT);
}
static int lq035q1_spidev_resume(struct spi_device *spi)
{
int ret;
struct spi_control *ctl = spi_get_drvdata(spi);
ret = lq035q1_control(spi, LQ035_DRIVER_OUTPUT_CTL, ctl->mode);
if (ret)
return ret;
return lq035q1_control(spi, LQ035_SHUT_CTL, LQ035_ON);
}
static void lq035q1_spidev_shutdown(struct spi_device *spi)
{
lq035q1_control(spi, LQ035_SHUT_CTL, LQ035_SHUT);
}
static int lq035q1_backlight(struct bfin_lq035q1fb_info *info, unsigned arg)
{
if (info->disp_info->use_bl)
gpio_set_value(info->disp_info->gpio_bl, arg);
return 0;
}
static int bfin_lq035q1_calc_timing(struct bfin_lq035q1fb_info *fbi)
{
unsigned long clocks_per_pix, cpld_pipeline_delay_cor;
switch (fbi->disp_info->ppi_mode) {
case USE_RGB565_16_BIT_PPI:
fbi->lcd_bpp = 16;
clocks_per_pix = 1;
cpld_pipeline_delay_cor = 0;
break;
case USE_RGB565_8_BIT_PPI:
fbi->lcd_bpp = 16;
clocks_per_pix = 2;
cpld_pipeline_delay_cor = 3;
break;
case USE_RGB888_8_BIT_PPI:
fbi->lcd_bpp = 24;
clocks_per_pix = 3;
cpld_pipeline_delay_cor = 5;
break;
default:
return -EINVAL;
}
fbi->h_actpix = (LCD_X_RES * clocks_per_pix);
fbi->h_period = (336 * clocks_per_pix);
fbi->h_pulse = (2 * clocks_per_pix);
fbi->h_start = (7 * clocks_per_pix + cpld_pipeline_delay_cor);
fbi->v_lines = (LCD_Y_RES + U_LINE);
fbi->v_pulse = (2 * clocks_per_pix);
fbi->v_period = (fbi->h_period * fbi->v_lines);
return 0;
}
static void bfin_lq035q1_config_ppi(struct bfin_lq035q1fb_info *fbi)
{
unsigned ppi_pmode;
if (fbi->disp_info->ppi_mode == USE_RGB565_16_BIT_PPI)
ppi_pmode = DLEN_16;
else
ppi_pmode = (DLEN_8 | PACK_EN);
bfin_write_PPI_DELAY(fbi->h_start);
bfin_write_PPI_COUNT(fbi->h_actpix - 1);
bfin_write_PPI_FRAME(fbi->v_lines);
bfin_write_PPI_CONTROL(PPI_TX_MODE |
PPI_XFER_TYPE_11 |
PPI_PORT_CFG_01 |
ppi_pmode |
PPI_POLS_1);
}
static inline void bfin_lq035q1_disable_ppi(void)
{
bfin_write_PPI_CONTROL(bfin_read_PPI_CONTROL() & ~PORT_EN);
}
static inline void bfin_lq035q1_enable_ppi(void)
{
bfin_write_PPI_CONTROL(bfin_read_PPI_CONTROL() | PORT_EN);
}
static void bfin_lq035q1_start_timers(void)
{
enable_gptimers(TIMER_VSYNCbit | TIMER_HSYNCbit);
}
static void bfin_lq035q1_stop_timers(void)
{
disable_gptimers(TIMER_HSYNCbit | TIMER_VSYNCbit);
set_gptimer_status(0, TIMER_HSYNC_STATUS_TRUN | TIMER_VSYNC_STATUS_TRUN |
TIMER_HSYNC_STATUS_TIMIL | TIMER_VSYNC_STATUS_TIMIL |
TIMER_HSYNC_STATUS_TOVF | TIMER_VSYNC_STATUS_TOVF);
}
static void bfin_lq035q1_init_timers(struct bfin_lq035q1fb_info *fbi)
{
bfin_lq035q1_stop_timers();
set_gptimer_period(TIMER_HSYNC_id, fbi->h_period);
set_gptimer_pwidth(TIMER_HSYNC_id, fbi->h_pulse);
set_gptimer_config(TIMER_HSYNC_id, TIMER_MODE_PWM | TIMER_PERIOD_CNT |
TIMER_TIN_SEL | TIMER_CLK_SEL|
TIMER_EMU_RUN);
set_gptimer_period(TIMER_VSYNC_id, fbi->v_period);
set_gptimer_pwidth(TIMER_VSYNC_id, fbi->v_pulse);
set_gptimer_config(TIMER_VSYNC_id, TIMER_MODE_PWM | TIMER_PERIOD_CNT |
TIMER_TIN_SEL | TIMER_CLK_SEL |
TIMER_EMU_RUN);
}
static void bfin_lq035q1_config_dma(struct bfin_lq035q1fb_info *fbi)
{
set_dma_config(CH_PPI,
set_bfin_dma_config(DIR_READ, DMA_FLOW_AUTO,
INTR_DISABLE, DIMENSION_2D,
DATA_SIZE_16,
DMA_NOSYNC_KEEP_DMA_BUF));
set_dma_x_count(CH_PPI, (LCD_X_RES * fbi->lcd_bpp) / DMA_BUS_SIZE);
set_dma_x_modify(CH_PPI, DMA_BUS_SIZE / 8);
set_dma_y_count(CH_PPI, fbi->v_lines);
set_dma_y_modify(CH_PPI, DMA_BUS_SIZE / 8);
set_dma_start_addr(CH_PPI, (unsigned long)fbi->fb_buffer);
}
static inline void bfin_lq035q1_free_ports(unsigned ppi16)
{
if (ppi16)
peripheral_free_list(ppi0_req_16);
else
peripheral_free_list(ppi0_req_8);
if (ANOMALY_05000400)
gpio_free(P_IDENT(P_PPI0_FS3));
}
static int __devinit bfin_lq035q1_request_ports(struct platform_device *pdev,
unsigned ppi16)
{
int ret;
if (ANOMALY_05000400) {
int ret = gpio_request_one(P_IDENT(P_PPI0_FS3),
GPIOF_OUT_INIT_LOW, "PPI_FS3");
if (ret)
return ret;
}
if (ppi16)
ret = peripheral_request_list(ppi0_req_16, DRIVER_NAME);
else
ret = peripheral_request_list(ppi0_req_8, DRIVER_NAME);
if (ret) {
dev_err(&pdev->dev, "requesting peripherals failed\n");
return -EFAULT;
}
return 0;
}
static int bfin_lq035q1_fb_open(struct fb_info *info, int user)
{
struct bfin_lq035q1fb_info *fbi = info->par;
spin_lock(&fbi->lock);
fbi->lq035_open_cnt++;
if (fbi->lq035_open_cnt <= 1) {
bfin_lq035q1_disable_ppi();
SSYNC();
bfin_lq035q1_config_dma(fbi);
bfin_lq035q1_config_ppi(fbi);
bfin_lq035q1_init_timers(fbi);
enable_dma(CH_PPI);
bfin_lq035q1_enable_ppi();
bfin_lq035q1_start_timers();
lq035q1_backlight(fbi, 1);
}
spin_unlock(&fbi->lock);
return 0;
}
static int bfin_lq035q1_fb_release(struct fb_info *info, int user)
{
struct bfin_lq035q1fb_info *fbi = info->par;
spin_lock(&fbi->lock);
fbi->lq035_open_cnt--;
if (fbi->lq035_open_cnt <= 0) {
lq035q1_backlight(fbi, 0);
bfin_lq035q1_disable_ppi();
SSYNC();
disable_dma(CH_PPI);
bfin_lq035q1_stop_timers();
}
spin_unlock(&fbi->lock);
return 0;
}
static int bfin_lq035q1_fb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
struct bfin_lq035q1fb_info *fbi = info->par;
if (var->bits_per_pixel == fbi->lcd_bpp) {
var->red.offset = info->var.red.offset;
var->green.offset = info->var.green.offset;
var->blue.offset = info->var.blue.offset;
var->red.length = info->var.red.length;
var->green.length = info->var.green.length;
var->blue.length = info->var.blue.length;
var->transp.offset = 0;
var->transp.length = 0;
var->transp.msb_right = 0;
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
} else {
pr_debug("%s: depth not supported: %u BPP\n", __func__,
var->bits_per_pixel);
return -EINVAL;
}
if (info->var.xres != var->xres || info->var.yres != var->yres ||
info->var.xres_virtual != var->xres_virtual ||
info->var.yres_virtual != var->yres_virtual) {
pr_debug("%s: Resolution not supported: X%u x Y%u \n",
__func__, var->xres, var->yres);
return -EINVAL;
}
if ((info->fix.line_length * var->yres_virtual) > info->fix.smem_len) {
pr_debug("%s: Memory Limit requested yres_virtual = %u\n",
__func__, var->yres_virtual);
return -ENOMEM;
}
return 0;
}
int bfin_lq035q1_fb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
if (nocursor)
return 0;
else
return -EINVAL;
}
static int bfin_lq035q1_fb_setcolreg(u_int regno, u_int red, u_int green,
u_int blue, u_int transp,
struct fb_info *info)
{
if (regno >= BFIN_LCD_NBR_PALETTE_ENTRIES)
return -EINVAL;
if (info->var.grayscale) {
red = green = blue = (red * 77 + green * 151 + blue * 28) >> 8;
}
if (info->fix.visual == FB_VISUAL_TRUECOLOR) {
u32 value;
if (regno > 16)
return -EINVAL;
red >>= (16 - info->var.red.length);
green >>= (16 - info->var.green.length);
blue >>= (16 - info->var.blue.length);
value = (red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset);
value &= 0xFFFFFF;
((u32 *) (info->pseudo_palette))[regno] = value;
}
return 0;
}
static irqreturn_t bfin_lq035q1_irq_error(int irq, void *dev_id)
{
u16 status = bfin_read_PPI_STATUS();
bfin_write_PPI_STATUS(-1);
if (status) {
bfin_lq035q1_disable_ppi();
disable_dma(CH_PPI);
enable_dma(CH_PPI);
bfin_lq035q1_enable_ppi();
bfin_write_PPI_STATUS(-1);
}
return IRQ_HANDLED;
}
static int __devinit bfin_lq035q1_probe(struct platform_device *pdev)
{
struct bfin_lq035q1fb_info *info;
struct fb_info *fbinfo;
u32 active_video_mem_offset;
int ret;
ret = request_dma(CH_PPI, DRIVER_NAME"_CH_PPI");
if (ret < 0) {
dev_err(&pdev->dev, "PPI DMA unavailable\n");
goto out1;
}
fbinfo = framebuffer_alloc(sizeof(*info), &pdev->dev);
if (!fbinfo) {
ret = -ENOMEM;
goto out2;
}
info = fbinfo->par;
info->fb = fbinfo;
info->dev = &pdev->dev;
spin_lock_init(&info->lock);
info->disp_info = pdev->dev.platform_data;
platform_set_drvdata(pdev, fbinfo);
ret = bfin_lq035q1_calc_timing(info);
if (ret < 0) {
dev_err(&pdev->dev, "Failed PPI Mode\n");
goto out3;
}
strcpy(fbinfo->fix.id, DRIVER_NAME);
fbinfo->fix.type = FB_TYPE_PACKED_PIXELS;
fbinfo->fix.type_aux = 0;
fbinfo->fix.xpanstep = 0;
fbinfo->fix.ypanstep = 0;
fbinfo->fix.ywrapstep = 0;
fbinfo->fix.accel = FB_ACCEL_NONE;
fbinfo->fix.visual = FB_VISUAL_TRUECOLOR;
fbinfo->var.nonstd = 0;
fbinfo->var.activate = FB_ACTIVATE_NOW;
fbinfo->var.height = -1;
fbinfo->var.width = -1;
fbinfo->var.accel_flags = 0;
fbinfo->var.vmode = FB_VMODE_NONINTERLACED;
fbinfo->var.xres = LCD_X_RES;
fbinfo->var.xres_virtual = LCD_X_RES;
fbinfo->var.yres = LCD_Y_RES;
fbinfo->var.yres_virtual = LCD_Y_RES;
fbinfo->var.bits_per_pixel = info->lcd_bpp;
if (info->disp_info->mode & LQ035_BGR) {
if (info->lcd_bpp == 24) {
fbinfo->var.red.offset = 0;
fbinfo->var.green.offset = 8;
fbinfo->var.blue.offset = 16;
} else {
fbinfo->var.red.offset = 0;
fbinfo->var.green.offset = 5;
fbinfo->var.blue.offset = 11;
}
} else {
if (info->lcd_bpp == 24) {
fbinfo->var.red.offset = 16;
fbinfo->var.green.offset = 8;
fbinfo->var.blue.offset = 0;
} else {
fbinfo->var.red.offset = 11;
fbinfo->var.green.offset = 5;
fbinfo->var.blue.offset = 0;
}
}
fbinfo->var.transp.offset = 0;
if (info->lcd_bpp == 24) {
fbinfo->var.red.length = 8;
fbinfo->var.green.length = 8;
fbinfo->var.blue.length = 8;
} else {
fbinfo->var.red.length = 5;
fbinfo->var.green.length = 6;
fbinfo->var.blue.length = 5;
}
fbinfo->var.transp.length = 0;
active_video_mem_offset = ((U_LINE / 2) * LCD_X_RES * (info->lcd_bpp / 8));
fbinfo->fix.smem_len = LCD_X_RES * LCD_Y_RES * info->lcd_bpp / 8
+ active_video_mem_offset;
fbinfo->fix.line_length = fbinfo->var.xres_virtual *
fbinfo->var.bits_per_pixel / 8;
fbinfo->fbops = &bfin_lq035q1_fb_ops;
fbinfo->flags = FBINFO_FLAG_DEFAULT;
info->fb_buffer =
dma_alloc_coherent(NULL, fbinfo->fix.smem_len, &info->dma_handle,
GFP_KERNEL);
if (NULL == info->fb_buffer) {
dev_err(&pdev->dev, "couldn't allocate dma buffer\n");
ret = -ENOMEM;
goto out3;
}
fbinfo->screen_base = (void *)info->fb_buffer + active_video_mem_offset;
fbinfo->fix.smem_start = (int)info->fb_buffer + active_video_mem_offset;
fbinfo->fbops = &bfin_lq035q1_fb_ops;
fbinfo->pseudo_palette = &info->pseudo_pal;
ret = fb_alloc_cmap(&fbinfo->cmap, BFIN_LCD_NBR_PALETTE_ENTRIES, 0);
if (ret < 0) {
dev_err(&pdev->dev, "failed to allocate colormap (%d entries)\n",
BFIN_LCD_NBR_PALETTE_ENTRIES);
goto out4;
}
ret = bfin_lq035q1_request_ports(pdev,
info->disp_info->ppi_mode == USE_RGB565_16_BIT_PPI);
if (ret) {
dev_err(&pdev->dev, "couldn't request gpio port\n");
goto out6;
}
info->irq = platform_get_irq(pdev, 0);
if (info->irq < 0) {
ret = -EINVAL;
goto out7;
}
ret = request_irq(info->irq, bfin_lq035q1_irq_error, 0,
DRIVER_NAME" PPI ERROR", info);
if (ret < 0) {
dev_err(&pdev->dev, "unable to request PPI ERROR IRQ\n");
goto out7;
}
info->spidrv.driver.name = DRIVER_NAME"-spi";
info->spidrv.probe = lq035q1_spidev_probe;
info->spidrv.remove = __devexit_p(lq035q1_spidev_remove);
info->spidrv.shutdown = lq035q1_spidev_shutdown;
info->spidrv.suspend = lq035q1_spidev_suspend;
info->spidrv.resume = lq035q1_spidev_resume;
ret = spi_register_driver(&info->spidrv);
if (ret < 0) {
dev_err(&pdev->dev, "couldn't register SPI Interface\n");
goto out8;
}
if (info->disp_info->use_bl) {
ret = gpio_request_one(info->disp_info->gpio_bl,
GPIOF_OUT_INIT_LOW, "LQ035 Backlight");
if (ret) {
dev_err(&pdev->dev, "failed to request GPIO %d\n",
info->disp_info->gpio_bl);
goto out9;
}
}
ret = register_framebuffer(fbinfo);
if (ret < 0) {
dev_err(&pdev->dev, "unable to register framebuffer\n");
goto out10;
}
dev_info(&pdev->dev, "%dx%d %d-bit RGB FrameBuffer initialized\n",
LCD_X_RES, LCD_Y_RES, info->lcd_bpp);
return 0;
out10:
if (info->disp_info->use_bl)
gpio_free(info->disp_info->gpio_bl);
out9:
spi_unregister_driver(&info->spidrv);
out8:
free_irq(info->irq, info);
out7:
bfin_lq035q1_free_ports(info->disp_info->ppi_mode ==
USE_RGB565_16_BIT_PPI);
out6:
fb_dealloc_cmap(&fbinfo->cmap);
out4:
dma_free_coherent(NULL, fbinfo->fix.smem_len, info->fb_buffer,
info->dma_handle);
out3:
framebuffer_release(fbinfo);
out2:
free_dma(CH_PPI);
out1:
platform_set_drvdata(pdev, NULL);
return ret;
}
static int __devexit bfin_lq035q1_remove(struct platform_device *pdev)
{
struct fb_info *fbinfo = platform_get_drvdata(pdev);
struct bfin_lq035q1fb_info *info = fbinfo->par;
if (info->disp_info->use_bl)
gpio_free(info->disp_info->gpio_bl);
spi_unregister_driver(&info->spidrv);
unregister_framebuffer(fbinfo);
free_dma(CH_PPI);
free_irq(info->irq, info);
if (info->fb_buffer != NULL)
dma_free_coherent(NULL, fbinfo->fix.smem_len, info->fb_buffer,
info->dma_handle);
fb_dealloc_cmap(&fbinfo->cmap);
bfin_lq035q1_free_ports(info->disp_info->ppi_mode ==
USE_RGB565_16_BIT_PPI);
platform_set_drvdata(pdev, NULL);
framebuffer_release(fbinfo);
dev_info(&pdev->dev, "unregistered LCD driver\n");
return 0;
}
static int bfin_lq035q1_suspend(struct device *dev)
{
struct fb_info *fbinfo = dev_get_drvdata(dev);
struct bfin_lq035q1fb_info *info = fbinfo->par;
if (info->lq035_open_cnt) {
lq035q1_backlight(info, 0);
bfin_lq035q1_disable_ppi();
SSYNC();
disable_dma(CH_PPI);
bfin_lq035q1_stop_timers();
bfin_write_PPI_STATUS(-1);
}
return 0;
}
static int bfin_lq035q1_resume(struct device *dev)
{
struct fb_info *fbinfo = dev_get_drvdata(dev);
struct bfin_lq035q1fb_info *info = fbinfo->par;
if (info->lq035_open_cnt) {
bfin_lq035q1_disable_ppi();
SSYNC();
bfin_lq035q1_config_dma(info);
bfin_lq035q1_config_ppi(info);
bfin_lq035q1_init_timers(info);
enable_dma(CH_PPI);
bfin_lq035q1_enable_ppi();
bfin_lq035q1_start_timers();
lq035q1_backlight(info, 1);
}
return 0;
}
