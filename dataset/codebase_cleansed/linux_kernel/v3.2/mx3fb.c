static u32 mx3fb_read_reg(struct mx3fb_data *mx3fb, unsigned long reg)
{
return __raw_readl(mx3fb->reg_base + reg);
}
static void mx3fb_write_reg(struct mx3fb_data *mx3fb, u32 value, unsigned long reg)
{
__raw_writel(value, mx3fb->reg_base + reg);
}
static void sdc_fb_init(struct mx3fb_info *fbi)
{
struct mx3fb_data *mx3fb = fbi->mx3fb;
uint32_t reg;
reg = mx3fb_read_reg(mx3fb, SDC_COM_CONF);
mx3fb_write_reg(mx3fb, reg | SDC_COM_BG_EN, SDC_COM_CONF);
}
static uint32_t sdc_fb_uninit(struct mx3fb_info *fbi)
{
struct mx3fb_data *mx3fb = fbi->mx3fb;
uint32_t reg;
reg = mx3fb_read_reg(mx3fb, SDC_COM_CONF);
mx3fb_write_reg(mx3fb, reg & ~SDC_COM_BG_EN, SDC_COM_CONF);
return reg & SDC_COM_BG_EN;
}
static void sdc_enable_channel(struct mx3fb_info *mx3_fbi)
{
struct mx3fb_data *mx3fb = mx3_fbi->mx3fb;
struct idmac_channel *ichan = mx3_fbi->idmac_channel;
struct dma_chan *dma_chan = &ichan->dma_chan;
unsigned long flags;
dma_cookie_t cookie;
if (mx3_fbi->txd)
dev_dbg(mx3fb->dev, "mx3fbi %p, desc %p, sg %p\n", mx3_fbi,
to_tx_desc(mx3_fbi->txd), to_tx_desc(mx3_fbi->txd)->sg);
else
dev_dbg(mx3fb->dev, "mx3fbi %p, txd = NULL\n", mx3_fbi);
if (mx3_fbi->cookie < 0) {
mx3_fbi->txd = dma_chan->device->device_prep_slave_sg(dma_chan,
&mx3_fbi->sg[0], 1, DMA_TO_DEVICE, DMA_PREP_INTERRUPT);
if (!mx3_fbi->txd) {
dev_err(mx3fb->dev, "Cannot allocate descriptor on %d\n",
dma_chan->chan_id);
return;
}
mx3_fbi->txd->callback_param = mx3_fbi->txd;
mx3_fbi->txd->callback = mx3fb_dma_done;
cookie = mx3_fbi->txd->tx_submit(mx3_fbi->txd);
dev_dbg(mx3fb->dev, "%d: Submit %p #%d [%c]\n", __LINE__,
mx3_fbi->txd, cookie, list_empty(&ichan->queue) ? '-' : '+');
} else {
if (!mx3_fbi->txd || !mx3_fbi->txd->tx_submit) {
dev_err(mx3fb->dev, "Cannot enable channel %d\n",
dma_chan->chan_id);
return;
}
dma_async_issue_pending(dma_chan);
cookie = mx3_fbi->cookie;
dev_dbg(mx3fb->dev, "%d: Re-submit %p #%d [%c]\n", __LINE__,
mx3_fbi->txd, cookie, list_empty(&ichan->queue) ? '-' : '+');
}
if (cookie >= 0) {
spin_lock_irqsave(&mx3fb->lock, flags);
sdc_fb_init(mx3_fbi);
mx3_fbi->cookie = cookie;
spin_unlock_irqrestore(&mx3fb->lock, flags);
}
msleep(2);
}
static void sdc_disable_channel(struct mx3fb_info *mx3_fbi)
{
struct mx3fb_data *mx3fb = mx3_fbi->mx3fb;
uint32_t enabled;
unsigned long flags;
if (mx3_fbi->txd == NULL)
return;
spin_lock_irqsave(&mx3fb->lock, flags);
enabled = sdc_fb_uninit(mx3_fbi);
spin_unlock_irqrestore(&mx3fb->lock, flags);
mx3_fbi->txd->chan->device->device_control(mx3_fbi->txd->chan,
DMA_TERMINATE_ALL, 0);
mx3_fbi->txd = NULL;
mx3_fbi->cookie = -EINVAL;
}
static int sdc_set_window_pos(struct mx3fb_data *mx3fb, enum ipu_channel channel,
int16_t x_pos, int16_t y_pos)
{
if (channel != IDMAC_SDC_0)
return -EINVAL;
x_pos += mx3fb->h_start_width;
y_pos += mx3fb->v_start_width;
mx3fb_write_reg(mx3fb, (x_pos << 16) | y_pos, SDC_BG_POS);
return 0;
}
static int sdc_init_panel(struct mx3fb_data *mx3fb, enum ipu_panel panel,
uint32_t pixel_clk,
uint16_t width, uint16_t height,
enum pixel_fmt pixel_fmt,
uint16_t h_start_width, uint16_t h_sync_width,
uint16_t h_end_width, uint16_t v_start_width,
uint16_t v_sync_width, uint16_t v_end_width,
struct ipu_di_signal_cfg sig)
{
unsigned long lock_flags;
uint32_t reg;
uint32_t old_conf;
uint32_t div;
struct clk *ipu_clk;
dev_dbg(mx3fb->dev, "panel size = %d x %d", width, height);
if (v_sync_width == 0 || h_sync_width == 0)
return -EINVAL;
reg = ((uint32_t) (h_sync_width - 1) << 26) |
((uint32_t) (width + h_start_width + h_end_width - 1) << 16);
mx3fb_write_reg(mx3fb, reg, SDC_HOR_CONF);
#ifdef DEBUG
printk(KERN_CONT " hor_conf %x,", reg);
#endif
reg = ((uint32_t) (v_sync_width - 1) << 26) | SDC_V_SYNC_WIDTH_L |
((uint32_t) (height + v_start_width + v_end_width - 1) << 16);
mx3fb_write_reg(mx3fb, reg, SDC_VER_CONF);
#ifdef DEBUG
printk(KERN_CONT " ver_conf %x\n", reg);
#endif
mx3fb->h_start_width = h_start_width;
mx3fb->v_start_width = v_start_width;
switch (panel) {
case IPU_PANEL_SHARP_TFT:
mx3fb_write_reg(mx3fb, 0x00FD0102L, SDC_SHARP_CONF_1);
mx3fb_write_reg(mx3fb, 0x00F500F4L, SDC_SHARP_CONF_2);
mx3fb_write_reg(mx3fb, SDC_COM_SHARP | SDC_COM_TFT_COLOR, SDC_COM_CONF);
break;
case IPU_PANEL_TFT:
mx3fb_write_reg(mx3fb, SDC_COM_TFT_COLOR, SDC_COM_CONF);
break;
default:
return -EINVAL;
}
ipu_clk = clk_get(mx3fb->dev, NULL);
if (!IS_ERR(ipu_clk)) {
div = clk_get_rate(ipu_clk) * 16 / pixel_clk;
clk_put(ipu_clk);
} else {
div = 0;
}
if (div < 0x40) {
dev_dbg(mx3fb->dev,
"InitPanel() - Pixel clock divider less than 4\n");
div = 0x40;
}
dev_dbg(mx3fb->dev, "pixel clk = %u, divider %u.%u\n",
pixel_clk, div >> 4, (div & 7) * 125);
spin_lock_irqsave(&mx3fb->lock, lock_flags);
mx3fb_write_reg(mx3fb, (((div / 8) - 1) << 22) | div, DI_DISP3_TIME_CONF);
old_conf = mx3fb_read_reg(mx3fb, DI_DISP_IF_CONF) & 0x78FFFFFF;
old_conf |= sig.datamask_en << DI_D3_DATAMSK_SHIFT |
sig.clksel_en << DI_D3_CLK_SEL_SHIFT |
sig.clkidle_en << DI_D3_CLK_IDLE_SHIFT;
mx3fb_write_reg(mx3fb, old_conf, DI_DISP_IF_CONF);
old_conf = mx3fb_read_reg(mx3fb, DI_DISP_SIG_POL) & 0xE0FFFFFF;
old_conf |= sig.data_pol << DI_D3_DATA_POL_SHIFT |
sig.clk_pol << DI_D3_CLK_POL_SHIFT |
sig.enable_pol << DI_D3_DRDY_SHARP_POL_SHIFT |
sig.Hsync_pol << DI_D3_HSYNC_POL_SHIFT |
sig.Vsync_pol << DI_D3_VSYNC_POL_SHIFT;
mx3fb_write_reg(mx3fb, old_conf, DI_DISP_SIG_POL);
switch (pixel_fmt) {
case IPU_PIX_FMT_RGB24:
mx3fb_write_reg(mx3fb, di_mappings[0], DI_DISP3_B0_MAP);
mx3fb_write_reg(mx3fb, di_mappings[1], DI_DISP3_B1_MAP);
mx3fb_write_reg(mx3fb, di_mappings[2], DI_DISP3_B2_MAP);
mx3fb_write_reg(mx3fb, mx3fb_read_reg(mx3fb, DI_DISP_ACC_CC) |
((di_mappings[3] - 1) << 12), DI_DISP_ACC_CC);
break;
case IPU_PIX_FMT_RGB666:
mx3fb_write_reg(mx3fb, di_mappings[4], DI_DISP3_B0_MAP);
mx3fb_write_reg(mx3fb, di_mappings[5], DI_DISP3_B1_MAP);
mx3fb_write_reg(mx3fb, di_mappings[6], DI_DISP3_B2_MAP);
mx3fb_write_reg(mx3fb, mx3fb_read_reg(mx3fb, DI_DISP_ACC_CC) |
((di_mappings[7] - 1) << 12), DI_DISP_ACC_CC);
break;
case IPU_PIX_FMT_BGR666:
mx3fb_write_reg(mx3fb, di_mappings[8], DI_DISP3_B0_MAP);
mx3fb_write_reg(mx3fb, di_mappings[9], DI_DISP3_B1_MAP);
mx3fb_write_reg(mx3fb, di_mappings[10], DI_DISP3_B2_MAP);
mx3fb_write_reg(mx3fb, mx3fb_read_reg(mx3fb, DI_DISP_ACC_CC) |
((di_mappings[11] - 1) << 12), DI_DISP_ACC_CC);
break;
default:
mx3fb_write_reg(mx3fb, di_mappings[12], DI_DISP3_B0_MAP);
mx3fb_write_reg(mx3fb, di_mappings[13], DI_DISP3_B1_MAP);
mx3fb_write_reg(mx3fb, di_mappings[14], DI_DISP3_B2_MAP);
mx3fb_write_reg(mx3fb, mx3fb_read_reg(mx3fb, DI_DISP_ACC_CC) |
((di_mappings[15] - 1) << 12), DI_DISP_ACC_CC);
break;
}
spin_unlock_irqrestore(&mx3fb->lock, lock_flags);
dev_dbg(mx3fb->dev, "DI_DISP_IF_CONF = 0x%08X\n",
mx3fb_read_reg(mx3fb, DI_DISP_IF_CONF));
dev_dbg(mx3fb->dev, "DI_DISP_SIG_POL = 0x%08X\n",
mx3fb_read_reg(mx3fb, DI_DISP_SIG_POL));
dev_dbg(mx3fb->dev, "DI_DISP3_TIME_CONF = 0x%08X\n",
mx3fb_read_reg(mx3fb, DI_DISP3_TIME_CONF));
return 0;
}
static int sdc_set_color_key(struct mx3fb_data *mx3fb, enum ipu_channel channel,
bool enable, uint32_t color_key)
{
uint32_t reg, sdc_conf;
unsigned long lock_flags;
spin_lock_irqsave(&mx3fb->lock, lock_flags);
sdc_conf = mx3fb_read_reg(mx3fb, SDC_COM_CONF);
if (channel == IDMAC_SDC_0)
sdc_conf &= ~SDC_COM_GWSEL;
else
sdc_conf |= SDC_COM_GWSEL;
if (enable) {
reg = mx3fb_read_reg(mx3fb, SDC_GW_CTRL) & 0xFF000000L;
mx3fb_write_reg(mx3fb, reg | (color_key & 0x00FFFFFFL),
SDC_GW_CTRL);
sdc_conf |= SDC_COM_KEY_COLOR_G;
} else {
sdc_conf &= ~SDC_COM_KEY_COLOR_G;
}
mx3fb_write_reg(mx3fb, sdc_conf, SDC_COM_CONF);
spin_unlock_irqrestore(&mx3fb->lock, lock_flags);
return 0;
}
static int sdc_set_global_alpha(struct mx3fb_data *mx3fb, bool enable, uint8_t alpha)
{
uint32_t reg;
unsigned long lock_flags;
spin_lock_irqsave(&mx3fb->lock, lock_flags);
if (enable) {
reg = mx3fb_read_reg(mx3fb, SDC_GW_CTRL) & 0x00FFFFFFL;
mx3fb_write_reg(mx3fb, reg | ((uint32_t) alpha << 24), SDC_GW_CTRL);
reg = mx3fb_read_reg(mx3fb, SDC_COM_CONF);
mx3fb_write_reg(mx3fb, reg | SDC_COM_GLB_A, SDC_COM_CONF);
} else {
reg = mx3fb_read_reg(mx3fb, SDC_COM_CONF);
mx3fb_write_reg(mx3fb, reg & ~SDC_COM_GLB_A, SDC_COM_CONF);
}
spin_unlock_irqrestore(&mx3fb->lock, lock_flags);
return 0;
}
static void sdc_set_brightness(struct mx3fb_data *mx3fb, uint8_t value)
{
dev_dbg(mx3fb->dev, "%s: value = %d\n", __func__, value);
mx3fb_write_reg(mx3fb, 0x03000000UL | value << 16, SDC_PWM_CTRL);
return;
}
static uint32_t bpp_to_pixfmt(int bpp)
{
uint32_t pixfmt = 0;
switch (bpp) {
case 24:
pixfmt = IPU_PIX_FMT_BGR24;
break;
case 32:
pixfmt = IPU_PIX_FMT_BGR32;
break;
case 16:
pixfmt = IPU_PIX_FMT_RGB565;
break;
}
return pixfmt;
}
static int mx3fb_set_fix(struct fb_info *fbi)
{
struct fb_fix_screeninfo *fix = &fbi->fix;
struct fb_var_screeninfo *var = &fbi->var;
strncpy(fix->id, "DISP3 BG", 8);
fix->line_length = var->xres_virtual * var->bits_per_pixel / 8;
fix->type = FB_TYPE_PACKED_PIXELS;
fix->accel = FB_ACCEL_NONE;
fix->visual = FB_VISUAL_TRUECOLOR;
fix->xpanstep = 1;
fix->ypanstep = 1;
return 0;
}
static void mx3fb_dma_done(void *arg)
{
struct idmac_tx_desc *tx_desc = to_tx_desc(arg);
struct dma_chan *chan = tx_desc->txd.chan;
struct idmac_channel *ichannel = to_idmac_chan(chan);
struct mx3fb_data *mx3fb = ichannel->client;
struct mx3fb_info *mx3_fbi = mx3fb->fbi->par;
dev_dbg(mx3fb->dev, "irq %d callback\n", ichannel->eof_irq);
disable_irq_nosync(ichannel->eof_irq);
complete(&mx3_fbi->flip_cmpl);
}
static int __set_par(struct fb_info *fbi, bool lock)
{
u32 mem_len;
struct ipu_di_signal_cfg sig_cfg;
enum ipu_panel mode = IPU_PANEL_TFT;
struct mx3fb_info *mx3_fbi = fbi->par;
struct mx3fb_data *mx3fb = mx3_fbi->mx3fb;
struct idmac_channel *ichan = mx3_fbi->idmac_channel;
struct idmac_video_param *video = &ichan->params.video;
struct scatterlist *sg = mx3_fbi->sg;
if (mx3_fbi->txd)
sdc_disable_channel(mx3_fbi);
mx3fb_set_fix(fbi);
mem_len = fbi->var.yres_virtual * fbi->fix.line_length;
if (mem_len > fbi->fix.smem_len) {
if (fbi->fix.smem_start)
mx3fb_unmap_video_memory(fbi);
if (mx3fb_map_video_memory(fbi, mem_len, lock) < 0)
return -ENOMEM;
}
sg_init_table(&sg[0], 1);
sg_init_table(&sg[1], 1);
sg_dma_address(&sg[0]) = fbi->fix.smem_start;
sg_set_page(&sg[0], virt_to_page(fbi->screen_base),
fbi->fix.smem_len,
offset_in_page(fbi->screen_base));
if (mx3_fbi->ipu_ch == IDMAC_SDC_0) {
memset(&sig_cfg, 0, sizeof(sig_cfg));
if (fbi->var.sync & FB_SYNC_HOR_HIGH_ACT)
sig_cfg.Hsync_pol = true;
if (fbi->var.sync & FB_SYNC_VERT_HIGH_ACT)
sig_cfg.Vsync_pol = true;
if (fbi->var.sync & FB_SYNC_CLK_INVERT)
sig_cfg.clk_pol = true;
if (fbi->var.sync & FB_SYNC_DATA_INVERT)
sig_cfg.data_pol = true;
if (fbi->var.sync & FB_SYNC_OE_ACT_HIGH)
sig_cfg.enable_pol = true;
if (fbi->var.sync & FB_SYNC_CLK_IDLE_EN)
sig_cfg.clkidle_en = true;
if (fbi->var.sync & FB_SYNC_CLK_SEL_EN)
sig_cfg.clksel_en = true;
if (fbi->var.sync & FB_SYNC_SHARP_MODE)
mode = IPU_PANEL_SHARP_TFT;
dev_dbg(fbi->device, "pixclock = %ul Hz\n",
(u32) (PICOS2KHZ(fbi->var.pixclock) * 1000UL));
if (sdc_init_panel(mx3fb, mode,
(PICOS2KHZ(fbi->var.pixclock)) * 1000UL,
fbi->var.xres, fbi->var.yres,
(fbi->var.sync & FB_SYNC_SWAP_RGB) ?
IPU_PIX_FMT_BGR666 : IPU_PIX_FMT_RGB666,
fbi->var.left_margin,
fbi->var.hsync_len,
fbi->var.right_margin +
fbi->var.hsync_len,
fbi->var.upper_margin,
fbi->var.vsync_len,
fbi->var.lower_margin +
fbi->var.vsync_len, sig_cfg) != 0) {
dev_err(fbi->device,
"mx3fb: Error initializing panel.\n");
return -EINVAL;
}
}
sdc_set_window_pos(mx3fb, mx3_fbi->ipu_ch, 0, 0);
mx3_fbi->cur_ipu_buf = 0;
video->out_pixel_fmt = bpp_to_pixfmt(fbi->var.bits_per_pixel);
video->out_width = fbi->var.xres;
video->out_height = fbi->var.yres;
video->out_stride = fbi->var.xres_virtual;
if (mx3_fbi->blank == FB_BLANK_UNBLANK)
sdc_enable_channel(mx3_fbi);
return 0;
}
static int mx3fb_set_par(struct fb_info *fbi)
{
struct mx3fb_info *mx3_fbi = fbi->par;
struct mx3fb_data *mx3fb = mx3_fbi->mx3fb;
struct idmac_channel *ichan = mx3_fbi->idmac_channel;
int ret;
dev_dbg(mx3fb->dev, "%s [%c]\n", __func__, list_empty(&ichan->queue) ? '-' : '+');
mutex_lock(&mx3_fbi->mutex);
ret = __set_par(fbi, true);
mutex_unlock(&mx3_fbi->mutex);
return ret;
}
static int mx3fb_check_var(struct fb_var_screeninfo *var, struct fb_info *fbi)
{
struct mx3fb_info *mx3_fbi = fbi->par;
u32 vtotal;
u32 htotal;
dev_dbg(fbi->device, "%s\n", __func__);
if (var->xres_virtual < var->xres)
var->xres_virtual = var->xres;
if (var->yres_virtual < var->yres)
var->yres_virtual = var->yres;
if ((var->bits_per_pixel != 32) && (var->bits_per_pixel != 24) &&
(var->bits_per_pixel != 16))
var->bits_per_pixel = default_bpp;
switch (var->bits_per_pixel) {
case 16:
var->red.length = 5;
var->red.offset = 11;
var->red.msb_right = 0;
var->green.length = 6;
var->green.offset = 5;
var->green.msb_right = 0;
var->blue.length = 5;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.length = 0;
var->transp.offset = 0;
var->transp.msb_right = 0;
break;
case 24:
var->red.length = 8;
var->red.offset = 16;
var->red.msb_right = 0;
var->green.length = 8;
var->green.offset = 8;
var->green.msb_right = 0;
var->blue.length = 8;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.length = 0;
var->transp.offset = 0;
var->transp.msb_right = 0;
break;
case 32:
var->red.length = 8;
var->red.offset = 16;
var->red.msb_right = 0;
var->green.length = 8;
var->green.offset = 8;
var->green.msb_right = 0;
var->blue.length = 8;
var->blue.offset = 0;
var->blue.msb_right = 0;
var->transp.length = 8;
var->transp.offset = 24;
var->transp.msb_right = 0;
break;
}
if (var->pixclock < 1000) {
htotal = var->xres + var->right_margin + var->hsync_len +
var->left_margin;
vtotal = var->yres + var->lower_margin + var->vsync_len +
var->upper_margin;
var->pixclock = (vtotal * htotal * 6UL) / 100UL;
var->pixclock = KHZ2PICOS(var->pixclock);
dev_dbg(fbi->device, "pixclock set for 60Hz refresh = %u ps\n",
var->pixclock);
}
var->height = -1;
var->width = -1;
var->grayscale = 0;
var->sync |= mx3_fbi->sync;
mx3_fbi->sync |= var->sync;
return 0;
}
static u32 chan_to_field(unsigned int chan, struct fb_bitfield *bf)
{
chan &= 0xffff;
chan >>= 16 - bf->length;
return chan << bf->offset;
}
static int mx3fb_setcolreg(unsigned int regno, unsigned int red,
unsigned int green, unsigned int blue,
unsigned int trans, struct fb_info *fbi)
{
struct mx3fb_info *mx3_fbi = fbi->par;
u32 val;
int ret = 1;
dev_dbg(fbi->device, "%s, regno = %u\n", __func__, regno);
mutex_lock(&mx3_fbi->mutex);
if (fbi->var.grayscale)
red = green = blue = (19595 * red + 38470 * green +
7471 * blue) >> 16;
switch (fbi->fix.visual) {
case FB_VISUAL_TRUECOLOR:
if (regno < 16) {
u32 *pal = fbi->pseudo_palette;
val = chan_to_field(red, &fbi->var.red);
val |= chan_to_field(green, &fbi->var.green);
val |= chan_to_field(blue, &fbi->var.blue);
pal[regno] = val;
ret = 0;
}
break;
case FB_VISUAL_STATIC_PSEUDOCOLOR:
case FB_VISUAL_PSEUDOCOLOR:
break;
}
mutex_unlock(&mx3_fbi->mutex);
return ret;
}
static void __blank(int blank, struct fb_info *fbi)
{
struct mx3fb_info *mx3_fbi = fbi->par;
struct mx3fb_data *mx3fb = mx3_fbi->mx3fb;
int was_blank = mx3_fbi->blank;
mx3_fbi->blank = blank;
if (blank > FB_BLANK_UNBLANK && was_blank > FB_BLANK_UNBLANK)
return;
switch (blank) {
case FB_BLANK_POWERDOWN:
case FB_BLANK_VSYNC_SUSPEND:
case FB_BLANK_HSYNC_SUSPEND:
case FB_BLANK_NORMAL:
sdc_set_brightness(mx3fb, 0);
memset((char *)fbi->screen_base, 0, fbi->fix.smem_len);
msleep(25);
sdc_disable_channel(mx3_fbi);
break;
case FB_BLANK_UNBLANK:
sdc_enable_channel(mx3_fbi);
sdc_set_brightness(mx3fb, mx3fb->backlight_level);
break;
}
}
static int mx3fb_blank(int blank, struct fb_info *fbi)
{
struct mx3fb_info *mx3_fbi = fbi->par;
dev_dbg(fbi->device, "%s, blank = %d, base %p, len %u\n", __func__,
blank, fbi->screen_base, fbi->fix.smem_len);
if (mx3_fbi->blank == blank)
return 0;
mutex_lock(&mx3_fbi->mutex);
__blank(blank, fbi);
mutex_unlock(&mx3_fbi->mutex);
return 0;
}
static int mx3fb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *fbi)
{
struct mx3fb_info *mx3_fbi = fbi->par;
u32 y_bottom;
unsigned long base;
off_t offset;
dma_cookie_t cookie;
struct scatterlist *sg = mx3_fbi->sg;
struct dma_chan *dma_chan = &mx3_fbi->idmac_channel->dma_chan;
struct dma_async_tx_descriptor *txd;
int ret;
dev_dbg(fbi->device, "%s [%c]\n", __func__,
list_empty(&mx3_fbi->idmac_channel->queue) ? '-' : '+');
if (var->xoffset > 0) {
dev_dbg(fbi->device, "x panning not supported\n");
return -EINVAL;
}
if (fbi->var.xoffset == var->xoffset &&
fbi->var.yoffset == var->yoffset)
return 0;
y_bottom = var->yoffset;
if (!(var->vmode & FB_VMODE_YWRAP))
y_bottom += fbi->var.yres;
if (y_bottom > fbi->var.yres_virtual)
return -EINVAL;
mutex_lock(&mx3_fbi->mutex);
offset = var->yoffset * fbi->fix.line_length
+ var->xoffset * (fbi->var.bits_per_pixel / 8);
base = fbi->fix.smem_start + offset;
dev_dbg(fbi->device, "Updating SDC BG buf %d address=0x%08lX\n",
mx3_fbi->cur_ipu_buf, base);
init_completion(&mx3_fbi->flip_cmpl);
enable_irq(mx3_fbi->idmac_channel->eof_irq);
ret = wait_for_completion_timeout(&mx3_fbi->flip_cmpl, HZ / 10);
if (ret <= 0) {
mutex_unlock(&mx3_fbi->mutex);
dev_info(fbi->device, "Panning failed due to %s\n", ret < 0 ?
"user interrupt" : "timeout");
disable_irq(mx3_fbi->idmac_channel->eof_irq);
return ret ? : -ETIMEDOUT;
}
mx3_fbi->cur_ipu_buf = !mx3_fbi->cur_ipu_buf;
sg_dma_address(&sg[mx3_fbi->cur_ipu_buf]) = base;
sg_set_page(&sg[mx3_fbi->cur_ipu_buf],
virt_to_page(fbi->screen_base + offset), fbi->fix.smem_len,
offset_in_page(fbi->screen_base + offset));
if (mx3_fbi->txd)
async_tx_ack(mx3_fbi->txd);
txd = dma_chan->device->device_prep_slave_sg(dma_chan, sg +
mx3_fbi->cur_ipu_buf, 1, DMA_TO_DEVICE, DMA_PREP_INTERRUPT);
if (!txd) {
dev_err(fbi->device,
"Error preparing a DMA transaction descriptor.\n");
mutex_unlock(&mx3_fbi->mutex);
return -EIO;
}
txd->callback_param = txd;
txd->callback = mx3fb_dma_done;
cookie = txd->tx_submit(txd);
dev_dbg(fbi->device, "%d: Submit %p #%d\n", __LINE__, txd, cookie);
if (cookie < 0) {
dev_err(fbi->device,
"Error updating SDC buf %d to address=0x%08lX\n",
mx3_fbi->cur_ipu_buf, base);
mutex_unlock(&mx3_fbi->mutex);
return -EIO;
}
mx3_fbi->txd = txd;
fbi->var.xoffset = var->xoffset;
fbi->var.yoffset = var->yoffset;
if (var->vmode & FB_VMODE_YWRAP)
fbi->var.vmode |= FB_VMODE_YWRAP;
else
fbi->var.vmode &= ~FB_VMODE_YWRAP;
mutex_unlock(&mx3_fbi->mutex);
dev_dbg(fbi->device, "Update complete\n");
return 0;
}
static int mx3fb_suspend(struct platform_device *pdev, pm_message_t state)
{
struct mx3fb_data *mx3fb = platform_get_drvdata(pdev);
struct mx3fb_info *mx3_fbi = mx3fb->fbi->par;
console_lock();
fb_set_suspend(mx3fb->fbi, 1);
console_unlock();
if (mx3_fbi->blank == FB_BLANK_UNBLANK) {
sdc_disable_channel(mx3_fbi);
sdc_set_brightness(mx3fb, 0);
}
return 0;
}
static int mx3fb_resume(struct platform_device *pdev)
{
struct mx3fb_data *mx3fb = platform_get_drvdata(pdev);
struct mx3fb_info *mx3_fbi = mx3fb->fbi->par;
if (mx3_fbi->blank == FB_BLANK_UNBLANK) {
sdc_enable_channel(mx3_fbi);
sdc_set_brightness(mx3fb, mx3fb->backlight_level);
}
console_lock();
fb_set_suspend(mx3fb->fbi, 0);
console_unlock();
return 0;
}
static int mx3fb_map_video_memory(struct fb_info *fbi, unsigned int mem_len,
bool lock)
{
int retval = 0;
dma_addr_t addr;
fbi->screen_base = dma_alloc_writecombine(fbi->device,
mem_len,
&addr, GFP_DMA);
if (!fbi->screen_base) {
dev_err(fbi->device, "Cannot allocate %u bytes framebuffer memory\n",
mem_len);
retval = -EBUSY;
goto err0;
}
if (lock)
mutex_lock(&fbi->mm_lock);
fbi->fix.smem_start = addr;
fbi->fix.smem_len = mem_len;
if (lock)
mutex_unlock(&fbi->mm_lock);
dev_dbg(fbi->device, "allocated fb @ p=0x%08x, v=0x%p, size=%d.\n",
(uint32_t) fbi->fix.smem_start, fbi->screen_base, fbi->fix.smem_len);
fbi->screen_size = fbi->fix.smem_len;
memset((char *)fbi->screen_base, 0, fbi->fix.smem_len);
return 0;
err0:
fbi->fix.smem_len = 0;
fbi->fix.smem_start = 0;
fbi->screen_base = NULL;
return retval;
}
static int mx3fb_unmap_video_memory(struct fb_info *fbi)
{
dma_free_writecombine(fbi->device, fbi->fix.smem_len,
fbi->screen_base, fbi->fix.smem_start);
fbi->screen_base = 0;
mutex_lock(&fbi->mm_lock);
fbi->fix.smem_start = 0;
fbi->fix.smem_len = 0;
mutex_unlock(&fbi->mm_lock);
return 0;
}
static struct fb_info *mx3fb_init_fbinfo(struct device *dev, struct fb_ops *ops)
{
struct fb_info *fbi;
struct mx3fb_info *mx3fbi;
int ret;
fbi = framebuffer_alloc(sizeof(struct mx3fb_info), dev);
if (!fbi)
return NULL;
mx3fbi = fbi->par;
mx3fbi->cookie = -EINVAL;
mx3fbi->cur_ipu_buf = 0;
fbi->var.activate = FB_ACTIVATE_NOW;
fbi->fbops = ops;
fbi->flags = FBINFO_FLAG_DEFAULT;
fbi->pseudo_palette = mx3fbi->pseudo_palette;
mutex_init(&mx3fbi->mutex);
ret = fb_alloc_cmap(&fbi->cmap, 16, 0);
if (ret < 0) {
framebuffer_release(fbi);
return NULL;
}
return fbi;
}
static int init_fb_chan(struct mx3fb_data *mx3fb, struct idmac_channel *ichan)
{
struct device *dev = mx3fb->dev;
struct mx3fb_platform_data *mx3fb_pdata = dev->platform_data;
const char *name = mx3fb_pdata->name;
unsigned int irq;
struct fb_info *fbi;
struct mx3fb_info *mx3fbi;
const struct fb_videomode *mode;
int ret, num_modes;
ichan->client = mx3fb;
irq = ichan->eof_irq;
if (ichan->dma_chan.chan_id != IDMAC_SDC_0)
return -EINVAL;
fbi = mx3fb_init_fbinfo(dev, &mx3fb_ops);
if (!fbi)
return -ENOMEM;
if (!fb_mode)
fb_mode = name;
if (!fb_mode) {
ret = -EINVAL;
goto emode;
}
if (mx3fb_pdata->mode && mx3fb_pdata->num_modes) {
mode = mx3fb_pdata->mode;
num_modes = mx3fb_pdata->num_modes;
} else {
mode = mx3fb_modedb;
num_modes = ARRAY_SIZE(mx3fb_modedb);
}
if (!fb_find_mode(&fbi->var, fbi, fb_mode, mode,
num_modes, NULL, default_bpp)) {
ret = -EBUSY;
goto emode;
}
fb_videomode_to_modelist(mode, num_modes, &fbi->modelist);
fbi->var.yres_virtual = fbi->var.yres * 2;
mx3fb->fbi = fbi;
mx3fb_write_reg(mx3fb, 0x00100010L, DI_HSP_CLK_PER);
sdc_set_brightness(mx3fb, 255);
sdc_set_global_alpha(mx3fb, true, 0xFF);
sdc_set_color_key(mx3fb, IDMAC_SDC_0, false, 0);
mx3fbi = fbi->par;
mx3fbi->idmac_channel = ichan;
mx3fbi->ipu_ch = ichan->dma_chan.chan_id;
mx3fbi->mx3fb = mx3fb;
mx3fbi->blank = FB_BLANK_NORMAL;
init_completion(&mx3fbi->flip_cmpl);
disable_irq(ichan->eof_irq);
dev_dbg(mx3fb->dev, "disabling irq %d\n", ichan->eof_irq);
ret = __set_par(fbi, false);
if (ret < 0)
goto esetpar;
__blank(FB_BLANK_UNBLANK, fbi);
dev_info(dev, "registered, using mode %s\n", fb_mode);
ret = register_framebuffer(fbi);
if (ret < 0)
goto erfb;
return 0;
erfb:
esetpar:
emode:
fb_dealloc_cmap(&fbi->cmap);
framebuffer_release(fbi);
return ret;
}
static bool chan_filter(struct dma_chan *chan, void *arg)
{
struct dma_chan_request *rq = arg;
struct device *dev;
struct mx3fb_platform_data *mx3fb_pdata;
if (!imx_dma_is_ipu(chan))
return false;
if (!rq)
return false;
dev = rq->mx3fb->dev;
mx3fb_pdata = dev->platform_data;
return rq->id == chan->chan_id &&
mx3fb_pdata->dma_dev == chan->device->dev;
}
static void release_fbi(struct fb_info *fbi)
{
mx3fb_unmap_video_memory(fbi);
fb_dealloc_cmap(&fbi->cmap);
unregister_framebuffer(fbi);
framebuffer_release(fbi);
}
static int mx3fb_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int ret;
struct resource *sdc_reg;
struct mx3fb_data *mx3fb;
dma_cap_mask_t mask;
struct dma_chan *chan;
struct dma_chan_request rq;
sdc_reg = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!sdc_reg)
return -EINVAL;
mx3fb = kzalloc(sizeof(*mx3fb), GFP_KERNEL);
if (!mx3fb)
return -ENOMEM;
spin_lock_init(&mx3fb->lock);
mx3fb->reg_base = ioremap(sdc_reg->start, resource_size(sdc_reg));
if (!mx3fb->reg_base) {
ret = -ENOMEM;
goto eremap;
}
pr_debug("Remapped %pR at %p\n", sdc_reg, mx3fb->reg_base);
dmaengine_get();
mx3fb->dev = dev;
platform_set_drvdata(pdev, mx3fb);
rq.mx3fb = mx3fb;
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma_cap_set(DMA_PRIVATE, mask);
rq.id = IDMAC_SDC_0;
chan = dma_request_channel(mask, chan_filter, &rq);
if (!chan) {
ret = -EBUSY;
goto ersdc0;
}
mx3fb->backlight_level = 255;
ret = init_fb_chan(mx3fb, to_idmac_chan(chan));
if (ret < 0)
goto eisdc0;
return 0;
eisdc0:
dma_release_channel(chan);
ersdc0:
dmaengine_put();
iounmap(mx3fb->reg_base);
eremap:
kfree(mx3fb);
dev_err(dev, "mx3fb: failed to register fb\n");
return ret;
}
static int mx3fb_remove(struct platform_device *dev)
{
struct mx3fb_data *mx3fb = platform_get_drvdata(dev);
struct fb_info *fbi = mx3fb->fbi;
struct mx3fb_info *mx3_fbi = fbi->par;
struct dma_chan *chan;
chan = &mx3_fbi->idmac_channel->dma_chan;
release_fbi(fbi);
dma_release_channel(chan);
dmaengine_put();
iounmap(mx3fb->reg_base);
kfree(mx3fb);
return 0;
}
static int __init mx3fb_setup(void)
{
#ifndef MODULE
char *opt, *options = NULL;
if (fb_get_options("mx3fb", &options))
return -ENODEV;
if (!options || !*options)
return 0;
while ((opt = strsep(&options, ",")) != NULL) {
if (!*opt)
continue;
if (!strncmp(opt, "bpp=", 4))
default_bpp = simple_strtoul(opt + 4, NULL, 0);
else
fb_mode = opt;
}
#endif
return 0;
}
static int __init mx3fb_init(void)
{
int ret = mx3fb_setup();
if (ret < 0)
return ret;
ret = platform_driver_register(&mx3fb_driver);
return ret;
}
static void __exit mx3fb_exit(void)
{
platform_driver_unregister(&mx3fb_driver);
}
