static inline unsigned int lcdc_read(unsigned int addr)
{
return (unsigned int)__raw_readl(da8xx_fb_reg_base + (addr));
}
static inline void lcdc_write(unsigned int val, unsigned int addr)
{
__raw_writel(val, da8xx_fb_reg_base + (addr));
}
static inline void lcd_enable_raster(void)
{
u32 reg;
reg = lcdc_read(LCD_RASTER_CTRL_REG);
if (!(reg & LCD_RASTER_ENABLE))
lcdc_write(reg | LCD_RASTER_ENABLE, LCD_RASTER_CTRL_REG);
}
static inline void lcd_disable_raster(void)
{
u32 reg;
reg = lcdc_read(LCD_RASTER_CTRL_REG);
if (reg & LCD_RASTER_ENABLE)
lcdc_write(reg & ~LCD_RASTER_ENABLE, LCD_RASTER_CTRL_REG);
}
static void lcd_blit(int load_mode, struct da8xx_fb_par *par)
{
u32 start;
u32 end;
u32 reg_ras;
u32 reg_dma;
reg_ras = lcdc_read(LCD_RASTER_CTRL_REG);
reg_ras &= ~(3 << 20);
reg_dma = lcdc_read(LCD_DMA_CTRL_REG);
if (load_mode == LOAD_DATA) {
start = par->dma_start;
end = par->dma_end;
reg_ras |= LCD_PALETTE_LOAD_MODE(DATA_ONLY);
reg_dma |= LCD_END_OF_FRAME_INT_ENA;
reg_dma |= LCD_DUAL_FRAME_BUFFER_ENABLE;
lcdc_write(start, LCD_DMA_FRM_BUF_BASE_ADDR_0_REG);
lcdc_write(end, LCD_DMA_FRM_BUF_CEILING_ADDR_0_REG);
lcdc_write(start, LCD_DMA_FRM_BUF_BASE_ADDR_1_REG);
lcdc_write(end, LCD_DMA_FRM_BUF_CEILING_ADDR_1_REG);
} else if (load_mode == LOAD_PALETTE) {
start = par->p_palette_base;
end = start + par->palette_sz - 1;
reg_ras |= LCD_PALETTE_LOAD_MODE(PALETTE_ONLY);
reg_ras |= LCD_PL_ENABLE;
lcdc_write(start, LCD_DMA_FRM_BUF_BASE_ADDR_0_REG);
lcdc_write(end, LCD_DMA_FRM_BUF_CEILING_ADDR_0_REG);
}
lcdc_write(reg_dma, LCD_DMA_CTRL_REG);
lcdc_write(reg_ras, LCD_RASTER_CTRL_REG);
lcd_enable_raster();
}
static int lcd_cfg_dma(int burst_size)
{
u32 reg;
reg = lcdc_read(LCD_DMA_CTRL_REG) & 0x00000001;
switch (burst_size) {
case 1:
reg |= LCD_DMA_BURST_SIZE(LCD_DMA_BURST_1);
break;
case 2:
reg |= LCD_DMA_BURST_SIZE(LCD_DMA_BURST_2);
break;
case 4:
reg |= LCD_DMA_BURST_SIZE(LCD_DMA_BURST_4);
break;
case 8:
reg |= LCD_DMA_BURST_SIZE(LCD_DMA_BURST_8);
break;
case 16:
reg |= LCD_DMA_BURST_SIZE(LCD_DMA_BURST_16);
break;
default:
return -EINVAL;
}
lcdc_write(reg, LCD_DMA_CTRL_REG);
return 0;
}
static void lcd_cfg_ac_bias(int period, int transitions_per_int)
{
u32 reg;
reg = lcdc_read(LCD_RASTER_TIMING_2_REG) & 0xFFF00000;
reg |= LCD_AC_BIAS_FREQUENCY(period) |
LCD_AC_BIAS_TRANSITIONS_PER_INT(transitions_per_int);
lcdc_write(reg, LCD_RASTER_TIMING_2_REG);
}
static void lcd_cfg_horizontal_sync(int back_porch, int pulse_width,
int front_porch)
{
u32 reg;
reg = lcdc_read(LCD_RASTER_TIMING_0_REG) & 0xf;
reg |= ((back_porch & 0xff) << 24)
| ((front_porch & 0xff) << 16)
| ((pulse_width & 0x3f) << 10);
lcdc_write(reg, LCD_RASTER_TIMING_0_REG);
}
static void lcd_cfg_vertical_sync(int back_porch, int pulse_width,
int front_porch)
{
u32 reg;
reg = lcdc_read(LCD_RASTER_TIMING_1_REG) & 0x3ff;
reg |= ((back_porch & 0xff) << 24)
| ((front_porch & 0xff) << 16)
| ((pulse_width & 0x3f) << 10);
lcdc_write(reg, LCD_RASTER_TIMING_1_REG);
}
static int lcd_cfg_display(const struct lcd_ctrl_config *cfg)
{
u32 reg;
reg = lcdc_read(LCD_RASTER_CTRL_REG) & ~(LCD_TFT_MODE |
LCD_MONO_8BIT_MODE |
LCD_MONOCHROME_MODE);
switch (cfg->p_disp_panel->panel_shade) {
case MONOCHROME:
reg |= LCD_MONOCHROME_MODE;
if (cfg->mono_8bit_mode)
reg |= LCD_MONO_8BIT_MODE;
break;
case COLOR_ACTIVE:
reg |= LCD_TFT_MODE;
if (cfg->tft_alt_mode)
reg |= LCD_TFT_ALT_ENABLE;
break;
case COLOR_PASSIVE:
if (cfg->stn_565_mode)
reg |= LCD_STN_565_ENABLE;
break;
default:
return -EINVAL;
}
reg |= LCD_UNDERFLOW_INT_ENA;
lcdc_write(reg, LCD_RASTER_CTRL_REG);
reg = lcdc_read(LCD_RASTER_TIMING_2_REG);
if (cfg->sync_ctrl)
reg |= LCD_SYNC_CTRL;
else
reg &= ~LCD_SYNC_CTRL;
if (cfg->sync_edge)
reg |= LCD_SYNC_EDGE;
else
reg &= ~LCD_SYNC_EDGE;
if (cfg->invert_line_clock)
reg |= LCD_INVERT_LINE_CLOCK;
else
reg &= ~LCD_INVERT_LINE_CLOCK;
if (cfg->invert_frm_clock)
reg |= LCD_INVERT_FRAME_CLOCK;
else
reg &= ~LCD_INVERT_FRAME_CLOCK;
lcdc_write(reg, LCD_RASTER_TIMING_2_REG);
return 0;
}
static int lcd_cfg_frame_buffer(struct da8xx_fb_par *par, u32 width, u32 height,
u32 bpp, u32 raster_order)
{
u32 reg;
width &= 0x3f0;
reg = lcdc_read(LCD_RASTER_TIMING_0_REG);
reg &= 0xfffffc00;
reg |= ((width >> 4) - 1) << 4;
lcdc_write(reg, LCD_RASTER_TIMING_0_REG);
reg = lcdc_read(LCD_RASTER_TIMING_1_REG);
reg = ((height - 1) & 0x3ff) | (reg & 0xfffffc00);
lcdc_write(reg, LCD_RASTER_TIMING_1_REG);
reg = lcdc_read(LCD_RASTER_CTRL_REG) & ~(1 << 8);
if (raster_order)
reg |= LCD_RASTER_ORDER;
lcdc_write(reg, LCD_RASTER_CTRL_REG);
switch (bpp) {
case 1:
case 2:
case 4:
case 16:
par->palette_sz = 16 * 2;
break;
case 8:
par->palette_sz = 256 * 2;
break;
default:
return -EINVAL;
}
return 0;
}
static int fb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
struct da8xx_fb_par *par = info->par;
unsigned short *palette = (unsigned short *) par->v_palette_base;
u_short pal;
int update_hw = 0;
if (regno > 255)
return 1;
if (info->fix.visual == FB_VISUAL_DIRECTCOLOR)
return 1;
if (info->var.bits_per_pixel == 8) {
red >>= 4;
green >>= 8;
blue >>= 12;
pal = (red & 0x0f00);
pal |= (green & 0x00f0);
pal |= (blue & 0x000f);
if (palette[regno] != pal) {
update_hw = 1;
palette[regno] = pal;
}
} else if ((info->var.bits_per_pixel == 16) && regno < 16) {
red >>= (16 - info->var.red.length);
red <<= info->var.red.offset;
green >>= (16 - info->var.green.length);
green <<= info->var.green.offset;
blue >>= (16 - info->var.blue.length);
blue <<= info->var.blue.offset;
par->pseudo_palette[regno] = red | green | blue;
if (palette[0] != 0x4000) {
update_hw = 1;
palette[0] = 0x4000;
}
}
if (update_hw)
lcd_blit(LOAD_PALETTE, par);
return 0;
}
static void lcd_reset(struct da8xx_fb_par *par)
{
lcd_disable_raster();
lcdc_write(0, LCD_DMA_CTRL_REG);
lcdc_write(0, LCD_RASTER_CTRL_REG);
}
static void lcd_calc_clk_divider(struct da8xx_fb_par *par)
{
unsigned int lcd_clk, div;
lcd_clk = clk_get_rate(par->lcdc_clk);
div = lcd_clk / par->pxl_clk;
lcdc_write(LCD_CLK_DIVISOR(div) |
(LCD_RASTER_MODE & 0x1), LCD_CTRL_REG);
}
static int lcd_init(struct da8xx_fb_par *par, const struct lcd_ctrl_config *cfg,
struct da8xx_panel *panel)
{
u32 bpp;
int ret = 0;
lcd_reset(par);
lcd_calc_clk_divider(par);
if (panel->invert_pxl_clk)
lcdc_write((lcdc_read(LCD_RASTER_TIMING_2_REG) |
LCD_INVERT_PIXEL_CLOCK), LCD_RASTER_TIMING_2_REG);
else
lcdc_write((lcdc_read(LCD_RASTER_TIMING_2_REG) &
~LCD_INVERT_PIXEL_CLOCK), LCD_RASTER_TIMING_2_REG);
ret = lcd_cfg_dma(cfg->dma_burst_sz);
if (ret < 0)
return ret;
lcd_cfg_ac_bias(cfg->ac_bias, cfg->ac_bias_intrpt);
lcd_cfg_vertical_sync(panel->vbp, panel->vsw, panel->vfp);
lcd_cfg_horizontal_sync(panel->hbp, panel->hsw, panel->hfp);
ret = lcd_cfg_display(cfg);
if (ret < 0)
return ret;
if (QVGA != cfg->p_disp_panel->panel_type)
return -EINVAL;
if (cfg->bpp <= cfg->p_disp_panel->max_bpp &&
cfg->bpp >= cfg->p_disp_panel->min_bpp)
bpp = cfg->bpp;
else
bpp = cfg->p_disp_panel->max_bpp;
if (bpp == 12)
bpp = 16;
ret = lcd_cfg_frame_buffer(par, (unsigned int)panel->width,
(unsigned int)panel->height, bpp,
cfg->raster_order);
if (ret < 0)
return ret;
lcdc_write((lcdc_read(LCD_RASTER_CTRL_REG) & 0xfff00fff) |
(cfg->fdd << 12), LCD_RASTER_CTRL_REG);
return 0;
}
static irqreturn_t lcdc_irq_handler(int irq, void *arg)
{
struct da8xx_fb_par *par = arg;
u32 stat = lcdc_read(LCD_STAT_REG);
u32 reg_ras;
if ((stat & LCD_SYNC_LOST) && (stat & LCD_FIFO_UNDERFLOW)) {
lcd_disable_raster();
lcdc_write(stat, LCD_STAT_REG);
lcd_enable_raster();
} else if (stat & LCD_PL_LOAD_DONE) {
lcd_disable_raster();
lcdc_write(stat, LCD_STAT_REG);
reg_ras = lcdc_read(LCD_RASTER_CTRL_REG);
reg_ras &= ~LCD_PL_ENABLE;
lcdc_write(reg_ras, LCD_RASTER_CTRL_REG);
lcd_blit(LOAD_DATA, par);
} else {
lcdc_write(stat, LCD_STAT_REG);
if (stat & LCD_END_OF_FRAME0) {
lcdc_write(par->dma_start,
LCD_DMA_FRM_BUF_BASE_ADDR_0_REG);
lcdc_write(par->dma_end,
LCD_DMA_FRM_BUF_CEILING_ADDR_0_REG);
par->vsync_flag = 1;
wake_up_interruptible(&par->vsync_wait);
}
if (stat & LCD_END_OF_FRAME1) {
lcdc_write(par->dma_start,
LCD_DMA_FRM_BUF_BASE_ADDR_1_REG);
lcdc_write(par->dma_end,
LCD_DMA_FRM_BUF_CEILING_ADDR_1_REG);
par->vsync_flag = 1;
wake_up_interruptible(&par->vsync_wait);
}
}
return IRQ_HANDLED;
}
static int fb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
int err = 0;
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
case 4:
var->red.offset = 0;
var->red.length = 4;
var->green.offset = 0;
var->green.length = 4;
var->blue.offset = 0;
var->blue.length = 4;
var->transp.offset = 0;
var->transp.length = 0;
break;
case 16:
var->red.offset = 11;
var->red.length = 5;
var->green.offset = 5;
var->green.length = 6;
var->blue.offset = 0;
var->blue.length = 5;
var->transp.offset = 0;
var->transp.length = 0;
break;
default:
err = -EINVAL;
}
var->red.msb_right = 0;
var->green.msb_right = 0;
var->blue.msb_right = 0;
var->transp.msb_right = 0;
return err;
}
static int lcd_da8xx_cpufreq_transition(struct notifier_block *nb,
unsigned long val, void *data)
{
struct da8xx_fb_par *par;
par = container_of(nb, struct da8xx_fb_par, freq_transition);
if (val == CPUFREQ_PRECHANGE) {
lcd_disable_raster();
} else if (val == CPUFREQ_POSTCHANGE) {
lcd_calc_clk_divider(par);
lcd_enable_raster();
}
return 0;
}
static inline int lcd_da8xx_cpufreq_register(struct da8xx_fb_par *par)
{
par->freq_transition.notifier_call = lcd_da8xx_cpufreq_transition;
return cpufreq_register_notifier(&par->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static inline void lcd_da8xx_cpufreq_deregister(struct da8xx_fb_par *par)
{
cpufreq_unregister_notifier(&par->freq_transition,
CPUFREQ_TRANSITION_NOTIFIER);
}
static int __devexit fb_remove(struct platform_device *dev)
{
struct fb_info *info = dev_get_drvdata(&dev->dev);
if (info) {
struct da8xx_fb_par *par = info->par;
#ifdef CONFIG_CPU_FREQ
lcd_da8xx_cpufreq_deregister(par);
#endif
if (par->panel_power_ctrl)
par->panel_power_ctrl(0);
lcd_disable_raster();
lcdc_write(0, LCD_RASTER_CTRL_REG);
lcdc_write(0, LCD_DMA_CTRL_REG);
unregister_framebuffer(info);
fb_dealloc_cmap(&info->cmap);
dma_free_coherent(NULL, PALETTE_SIZE, par->v_palette_base,
par->p_palette_base);
dma_free_coherent(NULL, par->vram_size, par->vram_virt,
par->vram_phys);
free_irq(par->irq, par);
clk_disable(par->lcdc_clk);
clk_put(par->lcdc_clk);
framebuffer_release(info);
iounmap((void __iomem *)da8xx_fb_reg_base);
release_mem_region(lcdc_regs->start, resource_size(lcdc_regs));
}
return 0;
}
static int fb_wait_for_vsync(struct fb_info *info)
{
struct da8xx_fb_par *par = info->par;
int ret;
par->vsync_flag = 0;
ret = wait_event_interruptible_timeout(par->vsync_wait,
par->vsync_flag != 0,
par->vsync_timeout);
if (ret < 0)
return ret;
if (ret == 0)
return -ETIMEDOUT;
return 0;
}
static int fb_ioctl(struct fb_info *info, unsigned int cmd,
unsigned long arg)
{
struct lcd_sync_arg sync_arg;
switch (cmd) {
case FBIOGET_CONTRAST:
case FBIOPUT_CONTRAST:
case FBIGET_BRIGHTNESS:
case FBIPUT_BRIGHTNESS:
case FBIGET_COLOR:
case FBIPUT_COLOR:
return -ENOTTY;
case FBIPUT_HSYNC:
if (copy_from_user(&sync_arg, (char *)arg,
sizeof(struct lcd_sync_arg)))
return -EFAULT;
lcd_cfg_horizontal_sync(sync_arg.back_porch,
sync_arg.pulse_width,
sync_arg.front_porch);
break;
case FBIPUT_VSYNC:
if (copy_from_user(&sync_arg, (char *)arg,
sizeof(struct lcd_sync_arg)))
return -EFAULT;
lcd_cfg_vertical_sync(sync_arg.back_porch,
sync_arg.pulse_width,
sync_arg.front_porch);
break;
case FBIO_WAITFORVSYNC:
return fb_wait_for_vsync(info);
default:
return -EINVAL;
}
return 0;
}
static int cfb_blank(int blank, struct fb_info *info)
{
struct da8xx_fb_par *par = info->par;
int ret = 0;
if (par->blank == blank)
return 0;
par->blank = blank;
switch (blank) {
case FB_BLANK_UNBLANK:
if (par->panel_power_ctrl)
par->panel_power_ctrl(1);
lcd_enable_raster();
break;
case FB_BLANK_POWERDOWN:
if (par->panel_power_ctrl)
par->panel_power_ctrl(0);
lcd_disable_raster();
break;
default:
ret = -EINVAL;
}
return ret;
}
static int da8xx_pan_display(struct fb_var_screeninfo *var,
struct fb_info *fbi)
{
int ret = 0;
struct fb_var_screeninfo new_var;
struct da8xx_fb_par *par = fbi->par;
struct fb_fix_screeninfo *fix = &fbi->fix;
unsigned int end;
unsigned int start;
if (var->xoffset != fbi->var.xoffset ||
var->yoffset != fbi->var.yoffset) {
memcpy(&new_var, &fbi->var, sizeof(new_var));
new_var.xoffset = var->xoffset;
new_var.yoffset = var->yoffset;
if (fb_check_var(&new_var, fbi))
ret = -EINVAL;
else {
memcpy(&fbi->var, &new_var, sizeof(new_var));
start = fix->smem_start +
new_var.yoffset * fix->line_length +
new_var.xoffset * var->bits_per_pixel / 8;
end = start + var->yres * fix->line_length - 1;
par->dma_start = start;
par->dma_end = end;
}
}
return ret;
}
static int __devinit fb_probe(struct platform_device *device)
{
struct da8xx_lcdc_platform_data *fb_pdata =
device->dev.platform_data;
struct lcd_ctrl_config *lcd_cfg;
struct da8xx_panel *lcdc_info;
struct fb_info *da8xx_fb_info;
struct clk *fb_clk = NULL;
struct da8xx_fb_par *par;
resource_size_t len;
int ret, i;
if (fb_pdata == NULL) {
dev_err(&device->dev, "Can not get platform data\n");
return -ENOENT;
}
lcdc_regs = platform_get_resource(device, IORESOURCE_MEM, 0);
if (!lcdc_regs) {
dev_err(&device->dev,
"Can not get memory resource for LCD controller\n");
return -ENOENT;
}
len = resource_size(lcdc_regs);
lcdc_regs = request_mem_region(lcdc_regs->start, len, lcdc_regs->name);
if (!lcdc_regs)
return -EBUSY;
da8xx_fb_reg_base = (resource_size_t)ioremap(lcdc_regs->start, len);
if (!da8xx_fb_reg_base) {
ret = -EBUSY;
goto err_request_mem;
}
fb_clk = clk_get(&device->dev, NULL);
if (IS_ERR(fb_clk)) {
dev_err(&device->dev, "Can not get device clock\n");
ret = -ENODEV;
goto err_ioremap;
}
ret = clk_enable(fb_clk);
if (ret)
goto err_clk_put;
for (i = 0, lcdc_info = known_lcd_panels;
i < ARRAY_SIZE(known_lcd_panels);
i++, lcdc_info++) {
if (strcmp(fb_pdata->type, lcdc_info->name) == 0)
break;
}
if (i == ARRAY_SIZE(known_lcd_panels)) {
dev_err(&device->dev, "GLCD: No valid panel found\n");
ret = -ENODEV;
goto err_clk_disable;
} else
dev_info(&device->dev, "GLCD: Found %s panel\n",
fb_pdata->type);
lcd_cfg = (struct lcd_ctrl_config *)fb_pdata->controller_data;
da8xx_fb_info = framebuffer_alloc(sizeof(struct da8xx_fb_par),
&device->dev);
if (!da8xx_fb_info) {
dev_dbg(&device->dev, "Memory allocation failed for fb_info\n");
ret = -ENOMEM;
goto err_clk_disable;
}
par = da8xx_fb_info->par;
par->lcdc_clk = fb_clk;
par->pxl_clk = lcdc_info->pxl_clk;
if (fb_pdata->panel_power_ctrl) {
par->panel_power_ctrl = fb_pdata->panel_power_ctrl;
par->panel_power_ctrl(1);
}
if (lcd_init(par, lcd_cfg, lcdc_info) < 0) {
dev_err(&device->dev, "lcd_init failed\n");
ret = -EFAULT;
goto err_release_fb;
}
par->vram_size = lcdc_info->width * lcdc_info->height * lcd_cfg->bpp;
par->vram_size = PAGE_ALIGN(par->vram_size/8);
par->vram_size = par->vram_size * LCD_NUM_BUFFERS;
par->vram_virt = dma_alloc_coherent(NULL,
par->vram_size,
(resource_size_t *) &par->vram_phys,
GFP_KERNEL | GFP_DMA);
if (!par->vram_virt) {
dev_err(&device->dev,
"GLCD: kmalloc for frame buffer failed\n");
ret = -EINVAL;
goto err_release_fb;
}
da8xx_fb_info->screen_base = (char __iomem *) par->vram_virt;
da8xx_fb_fix.smem_start = par->vram_phys;
da8xx_fb_fix.smem_len = par->vram_size;
da8xx_fb_fix.line_length = (lcdc_info->width * lcd_cfg->bpp) / 8;
par->dma_start = par->vram_phys;
par->dma_end = par->dma_start + lcdc_info->height *
da8xx_fb_fix.line_length - 1;
par->v_palette_base = dma_alloc_coherent(NULL,
PALETTE_SIZE,
(resource_size_t *)
&par->p_palette_base,
GFP_KERNEL | GFP_DMA);
if (!par->v_palette_base) {
dev_err(&device->dev,
"GLCD: kmalloc for palette buffer failed\n");
ret = -EINVAL;
goto err_release_fb_mem;
}
memset(par->v_palette_base, 0, PALETTE_SIZE);
par->irq = platform_get_irq(device, 0);
if (par->irq < 0) {
ret = -ENOENT;
goto err_release_pl_mem;
}
da8xx_fb_info->var.bits_per_pixel = lcd_cfg->bpp;
da8xx_fb_var.xres = lcdc_info->width;
da8xx_fb_var.xres_virtual = lcdc_info->width;
da8xx_fb_var.yres = lcdc_info->height;
da8xx_fb_var.yres_virtual = lcdc_info->height * LCD_NUM_BUFFERS;
da8xx_fb_var.grayscale =
lcd_cfg->p_disp_panel->panel_shade == MONOCHROME ? 1 : 0;
da8xx_fb_var.bits_per_pixel = lcd_cfg->bpp;
da8xx_fb_var.hsync_len = lcdc_info->hsw;
da8xx_fb_var.vsync_len = lcdc_info->vsw;
da8xx_fb_info->flags = FBINFO_FLAG_DEFAULT;
da8xx_fb_info->fix = da8xx_fb_fix;
da8xx_fb_info->var = da8xx_fb_var;
da8xx_fb_info->fbops = &da8xx_fb_ops;
da8xx_fb_info->pseudo_palette = par->pseudo_palette;
da8xx_fb_info->fix.visual = (da8xx_fb_info->var.bits_per_pixel <= 8) ?
FB_VISUAL_PSEUDOCOLOR : FB_VISUAL_TRUECOLOR;
ret = fb_alloc_cmap(&da8xx_fb_info->cmap, PALETTE_SIZE, 0);
if (ret)
goto err_release_pl_mem;
da8xx_fb_info->cmap.len = par->palette_sz;
da8xx_fb_var.activate = FB_ACTIVATE_FORCE;
fb_set_var(da8xx_fb_info, &da8xx_fb_var);
dev_set_drvdata(&device->dev, da8xx_fb_info);
init_waitqueue_head(&par->vsync_wait);
par->vsync_timeout = HZ / 5;
if (register_framebuffer(da8xx_fb_info) < 0) {
dev_err(&device->dev,
"GLCD: Frame Buffer Registration Failed!\n");
ret = -EINVAL;
goto err_dealloc_cmap;
}
#ifdef CONFIG_CPU_FREQ
ret = lcd_da8xx_cpufreq_register(par);
if (ret) {
dev_err(&device->dev, "failed to register cpufreq\n");
goto err_cpu_freq;
}
#endif
ret = request_irq(par->irq, lcdc_irq_handler, 0, DRIVER_NAME, par);
if (ret)
goto irq_freq;
return 0;
irq_freq:
#ifdef CONFIG_CPU_FREQ
lcd_da8xx_cpufreq_deregister(par);
#endif
err_cpu_freq:
unregister_framebuffer(da8xx_fb_info);
err_dealloc_cmap:
fb_dealloc_cmap(&da8xx_fb_info->cmap);
err_release_pl_mem:
dma_free_coherent(NULL, PALETTE_SIZE, par->v_palette_base,
par->p_palette_base);
err_release_fb_mem:
dma_free_coherent(NULL, par->vram_size, par->vram_virt, par->vram_phys);
err_release_fb:
framebuffer_release(da8xx_fb_info);
err_clk_disable:
clk_disable(fb_clk);
err_clk_put:
clk_put(fb_clk);
err_ioremap:
iounmap((void __iomem *)da8xx_fb_reg_base);
err_request_mem:
release_mem_region(lcdc_regs->start, len);
return ret;
}
static int fb_suspend(struct platform_device *dev, pm_message_t state)
{
struct fb_info *info = platform_get_drvdata(dev);
struct da8xx_fb_par *par = info->par;
console_lock();
if (par->panel_power_ctrl)
par->panel_power_ctrl(0);
fb_set_suspend(info, 1);
lcd_disable_raster();
clk_disable(par->lcdc_clk);
console_unlock();
return 0;
}
static int fb_resume(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
struct da8xx_fb_par *par = info->par;
console_lock();
if (par->panel_power_ctrl)
par->panel_power_ctrl(1);
clk_enable(par->lcdc_clk);
lcd_enable_raster();
fb_set_suspend(info, 0);
console_unlock();
return 0;
}
static int __init da8xx_fb_init(void)
{
return platform_driver_register(&da8xx_fb_driver);
}
static void __exit da8xx_fb_cleanup(void)
{
platform_driver_unregister(&da8xx_fb_driver);
}
