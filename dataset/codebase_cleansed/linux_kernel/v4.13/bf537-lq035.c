static void set_vcomm(void)
{
int nr;
if (!ad5280_client)
return;
nr = i2c_smbus_write_byte_data(ad5280_client, 0x00, vcomm_value);
if (nr)
pr_err("i2c_smbus_write_byte_data fail: %d\n", nr);
}
static int ad5280_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev, "SMBUS Byte Data not Supported\n");
return -EIO;
}
ret = i2c_smbus_write_byte_data(client, 0x00, vcomm_value);
if (ret) {
dev_err(&client->dev, "write fail: %d\n", ret);
return ret;
}
ad5280_client = client;
return 0;
}
static int ad5280_remove(struct i2c_client *client)
{
ad5280_client = NULL;
return 0;
}
static void start_timers(void)
{
unsigned long flags;
local_irq_save(flags);
bfin_write_TIMER_ENABLE(TIMEN_REV);
SSYNC();
while (bfin_read_TIMER_REV_COUNTER() <= 11)
continue;
bfin_write_TIMER_ENABLE(TIMEN_LP);
SSYNC();
while (bfin_read_TIMER_LP_COUNTER() < 3)
continue;
bfin_write_TIMER_ENABLE(TIMEN_SP|TIMEN_SPS|TIMEN_PS_CLS);
SSYNC();
t_conf_done = 1;
local_irq_restore(flags);
}
static void config_timers(void)
{
bfin_write_TIMER_DISABLE(TIMDIS_SP|TIMDIS_SPS|TIMDIS_REV|
TIMDIS_LP|TIMDIS_PS_CLS);
SSYNC();
bfin_write_TIMER_LP_CONFIG(TIMER_CONFIG|PULSE_HI);
bfin_write_TIMER_LP_WIDTH(1);
bfin_write_TIMER_LP_PERIOD(DCLKS_PER_LINE);
SSYNC();
bfin_write_TIMER_SPS_CONFIG(TIMER_CONFIG|PULSE_HI);
bfin_write_TIMER_SPS_WIDTH(DCLKS_PER_LINE*2);
bfin_write_TIMER_SPS_PERIOD((DCLKS_PER_LINE * (LCD_Y_RES+U_LINES)));
SSYNC();
bfin_write_TIMER_SP_CONFIG(TIMER_CONFIG|PULSE_HI);
bfin_write_TIMER_SP_WIDTH(1);
bfin_write_TIMER_SP_PERIOD(DCLKS_PER_LINE);
SSYNC();
bfin_write_TIMER_PS_CLS_CONFIG(TIMER_CONFIG);
bfin_write_TIMER_PS_CLS_WIDTH(LCD_X_RES + START_LINES);
bfin_write_TIMER_PS_CLS_PERIOD(DCLKS_PER_LINE);
SSYNC();
#ifdef NO_BL
bfin_write_TIMER_REV_CONFIG(TIMER_CONFIG|PULSE_HI);
bfin_write_TIMER_REV_WIDTH(DCLKS_PER_LINE);
bfin_write_TIMER_REV_PERIOD(DCLKS_PER_LINE*2);
SSYNC();
#endif
}
static void config_ppi(void)
{
bfin_write_PPI_DELAY(PPI_DELAY_VALUE);
bfin_write_PPI_COUNT(LCD_X_RES-1);
bfin_write_PPI_CONTROL((PPI_CONFIG_VALUE|0x10) & (~POLS));
}
static int config_dma(void)
{
u32 i;
if (landscape) {
for (i = 0; i < U_LINES; ++i) {
dma_desc_table[2*i] = (unsigned long)&dma_desc_table[2*i+2];
dma_desc_table[2*i+1] = (unsigned long)fb_buffer;
}
for (i = U_LINES; i < U_LINES + LCD_Y_RES; ++i) {
dma_desc_table[2*i] = (unsigned long)&dma_desc_table[2*i+2];
dma_desc_table[2*i+1] = (unsigned long)fb_buffer +
(LCD_Y_RES+U_LINES-1-i)*2;
}
dma_desc_table[2*(LCD_Y_RES+U_LINES-1)] = (unsigned long)&dma_desc_table[0];
set_dma_x_count(CH_PPI, LCD_X_RES);
set_dma_x_modify(CH_PPI, LCD_Y_RES * (LCD_BBP / 8));
set_dma_y_count(CH_PPI, 0);
set_dma_y_modify(CH_PPI, 0);
set_dma_next_desc_addr(CH_PPI, (void *)dma_desc_table[0]);
set_dma_config(CH_PPI, DMAFLOW_LARGE | NDSIZE_4 | WDSIZE_16);
} else {
set_dma_config(CH_PPI, set_bfin_dma_config(DIR_READ,
DMA_FLOW_AUTO,
INTR_DISABLE,
DIMENSION_2D,
DATA_SIZE_16,
DMA_NOSYNC_KEEP_DMA_BUF));
set_dma_x_count(CH_PPI, LCD_X_RES);
set_dma_x_modify(CH_PPI, LCD_BBP / 8);
set_dma_y_count(CH_PPI, LCD_Y_RES+U_LINES);
set_dma_y_modify(CH_PPI, LCD_BBP / 8);
set_dma_start_addr(CH_PPI, (unsigned long) fb_buffer);
}
return 0;
}
static int request_ports(void)
{
u16 tmr_req[] = TIMERS;
if (peripheral_request_list(ppi_pins, KBUILD_MODNAME)) {
pr_err("requesting PPI peripheral failed\n");
return -EBUSY;
}
if (peripheral_request_list(tmr_req, KBUILD_MODNAME)) {
peripheral_free_list(ppi_pins);
pr_err("requesting timer peripheral failed\n");
return -EBUSY;
}
#if (defined(UD) && defined(LBR))
if (gpio_request_one(UD, GPIOF_OUT_INIT_LOW, KBUILD_MODNAME)) {
pr_err("requesting GPIO %d failed\n", UD);
return -EBUSY;
}
if (gpio_request_one(LBR, GPIOF_OUT_INIT_HIGH, KBUILD_MODNAME)) {
pr_err("requesting GPIO %d failed\n", LBR);
gpio_free(UD);
return -EBUSY;
}
#endif
if (gpio_request_one(MOD, GPIOF_OUT_INIT_HIGH, KBUILD_MODNAME)) {
pr_err("requesting GPIO %d failed\n", MOD);
#if (defined(UD) && defined(LBR))
gpio_free(LBR);
gpio_free(UD);
#endif
return -EBUSY;
}
SSYNC();
return 0;
}
static void free_ports(void)
{
u16 tmr_req[] = TIMERS;
peripheral_free_list(ppi_pins);
peripheral_free_list(tmr_req);
#if defined(UD) && defined(LBR)
gpio_free(LBR);
gpio_free(UD);
#endif
gpio_free(MOD);
}
static int bfin_lq035_fb_open(struct fb_info *info, int user)
{
unsigned long flags;
spin_lock_irqsave(&bfin_lq035_lock, flags);
lq035_open_cnt++;
spin_unlock_irqrestore(&bfin_lq035_lock, flags);
if (lq035_open_cnt <= 1) {
bfin_write_PPI_CONTROL(0);
SSYNC();
set_vcomm();
config_dma();
config_ppi();
enable_dma(CH_PPI);
SSYNC();
bfin_write_PPI_CONTROL(bfin_read_PPI_CONTROL() | PORT_EN);
SSYNC();
if (!t_conf_done) {
config_timers();
start_timers();
}
}
return 0;
}
static int bfin_lq035_fb_release(struct fb_info *info, int user)
{
unsigned long flags;
spin_lock_irqsave(&bfin_lq035_lock, flags);
lq035_open_cnt--;
spin_unlock_irqrestore(&bfin_lq035_lock, flags);
if (lq035_open_cnt <= 0) {
bfin_write_PPI_CONTROL(0);
SSYNC();
disable_dma(CH_PPI);
}
return 0;
}
static int bfin_lq035_fb_check_var(struct fb_var_screeninfo *var,
struct fb_info *info)
{
switch (var->bits_per_pixel) {
case 16:
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
break;
default:
pr_debug("%s: depth not supported: %u BPP\n", __func__,
var->bits_per_pixel);
return -EINVAL;
}
if (info->var.xres != var->xres ||
info->var.yres != var->yres ||
info->var.xres_virtual != var->xres_virtual ||
info->var.yres_virtual != var->yres_virtual) {
pr_debug("%s: Resolution not supported: X%u x Y%u\n",
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
static int bfin_lq035_fb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
if (nocursor)
return 0;
else
return -EINVAL;
}
static int bfin_lq035_fb_setcolreg(u_int regno, u_int red, u_int green,
u_int blue, u_int transp,
struct fb_info *info)
{
if (regno >= NBR_PALETTE)
return -EINVAL;
if (info->var.grayscale)
red = green = blue = (red * 77 + green * 151 + blue * 28) >> 8;
if (info->fix.visual == FB_VISUAL_TRUECOLOR) {
u32 value;
if (regno > 16)
return -EINVAL;
red >>= (16 - info->var.red.length);
green >>= (16 - info->var.green.length);
blue >>= (16 - info->var.blue.length);
value = (red << info->var.red.offset) |
(green << info->var.green.offset)|
(blue << info->var.blue.offset);
value &= 0xFFFF;
((u32 *) (info->pseudo_palette))[regno] = value;
}
return 0;
}
static int bl_get_brightness(struct backlight_device *bd)
{
return current_brightness;
}
static int bfin_lcd_get_power(struct lcd_device *dev)
{
return 0;
}
static int bfin_lcd_set_power(struct lcd_device *dev, int power)
{
return 0;
}
static int bfin_lcd_get_contrast(struct lcd_device *dev)
{
return (int)vcomm_value;
}
static int bfin_lcd_set_contrast(struct lcd_device *dev, int contrast)
{
if (contrast > 255)
contrast = 255;
if (contrast < 0)
contrast = 0;
vcomm_value = (unsigned char)contrast;
set_vcomm();
return 0;
}
static int bfin_lcd_check_fb(struct lcd_device *lcd, struct fb_info *fi)
{
if (!fi || (fi == &bfin_lq035_fb))
return 1;
return 0;
}
static int bfin_lq035_probe(struct platform_device *pdev)
{
struct backlight_properties props;
dma_addr_t dma_handle;
int ret;
if (request_dma(CH_PPI, KBUILD_MODNAME)) {
pr_err("couldn't request PPI DMA\n");
return -EFAULT;
}
if (request_ports()) {
pr_err("couldn't request gpio port\n");
ret = -EFAULT;
goto out_ports;
}
fb_buffer = dma_alloc_coherent(NULL, TOTAL_VIDEO_MEM_SIZE,
&dma_handle, GFP_KERNEL);
if (fb_buffer == NULL) {
pr_err("couldn't allocate dma buffer\n");
ret = -ENOMEM;
goto out_dma_coherent;
}
if (L1_DATA_A_LENGTH)
dma_desc_table = l1_data_sram_zalloc(TOTAL_DMA_DESC_SIZE);
else
dma_desc_table = dma_alloc_coherent(NULL, TOTAL_DMA_DESC_SIZE,
&dma_handle, 0);
if (dma_desc_table == NULL) {
pr_err("couldn't allocate dma descriptor\n");
ret = -ENOMEM;
goto out_table;
}
bfin_lq035_fb.screen_base = (void *)fb_buffer;
bfin_lq035_fb_fix.smem_start = (int)fb_buffer;
if (landscape) {
bfin_lq035_fb_defined.xres = LCD_Y_RES;
bfin_lq035_fb_defined.yres = LCD_X_RES;
bfin_lq035_fb_defined.xres_virtual = LCD_Y_RES;
bfin_lq035_fb_defined.yres_virtual = LCD_X_RES;
bfin_lq035_fb_fix.line_length = LCD_Y_RES*(LCD_BBP/8);
} else {
bfin_lq035_fb.screen_base += ACTIVE_VIDEO_MEM_OFFSET;
bfin_lq035_fb_fix.smem_start += ACTIVE_VIDEO_MEM_OFFSET;
}
bfin_lq035_fb_defined.green.msb_right = 0;
bfin_lq035_fb_defined.red.msb_right = 0;
bfin_lq035_fb_defined.blue.msb_right = 0;
bfin_lq035_fb_defined.green.offset = 5;
bfin_lq035_fb_defined.green.length = 6;
bfin_lq035_fb_defined.red.length = 5;
bfin_lq035_fb_defined.blue.length = 5;
if (bgr) {
bfin_lq035_fb_defined.red.offset = 0;
bfin_lq035_fb_defined.blue.offset = 11;
} else {
bfin_lq035_fb_defined.red.offset = 11;
bfin_lq035_fb_defined.blue.offset = 0;
}
bfin_lq035_fb.fbops = &bfin_lq035_fb_ops;
bfin_lq035_fb.var = bfin_lq035_fb_defined;
bfin_lq035_fb.fix = bfin_lq035_fb_fix;
bfin_lq035_fb.flags = FBINFO_DEFAULT;
bfin_lq035_fb.pseudo_palette = devm_kzalloc(&pdev->dev,
sizeof(u32) * 16,
GFP_KERNEL);
if (bfin_lq035_fb.pseudo_palette == NULL) {
pr_err("failed to allocate pseudo_palette\n");
ret = -ENOMEM;
goto out_table;
}
if (fb_alloc_cmap(&bfin_lq035_fb.cmap, NBR_PALETTE, 0) < 0) {
pr_err("failed to allocate colormap (%d entries)\n",
NBR_PALETTE);
ret = -EFAULT;
goto out_table;
}
if (register_framebuffer(&bfin_lq035_fb) < 0) {
pr_err("unable to register framebuffer\n");
ret = -EINVAL;
goto out_reg;
}
i2c_add_driver(&ad5280_driver);
memset(&props, 0, sizeof(props));
props.type = BACKLIGHT_RAW;
props.max_brightness = MAX_BRIGHENESS;
bl_dev = backlight_device_register("bf537-bl", NULL, NULL,
&bfin_lq035fb_bl_ops, &props);
lcd_dev = lcd_device_register(KBUILD_MODNAME, &pdev->dev, NULL,
&bfin_lcd_ops);
if (IS_ERR(lcd_dev)) {
pr_err("unable to register lcd\n");
ret = PTR_ERR(lcd_dev);
goto out_lcd;
}
lcd_dev->props.max_contrast = 255,
pr_info("initialized");
return 0;
out_lcd:
unregister_framebuffer(&bfin_lq035_fb);
out_reg:
fb_dealloc_cmap(&bfin_lq035_fb.cmap);
out_table:
dma_free_coherent(NULL, TOTAL_VIDEO_MEM_SIZE, fb_buffer, 0);
fb_buffer = NULL;
out_dma_coherent:
free_ports();
out_ports:
free_dma(CH_PPI);
return ret;
}
static int bfin_lq035_remove(struct platform_device *pdev)
{
if (fb_buffer != NULL)
dma_free_coherent(NULL, TOTAL_VIDEO_MEM_SIZE, fb_buffer, 0);
if (L1_DATA_A_LENGTH)
l1_data_sram_free(dma_desc_table);
else
dma_free_coherent(NULL, TOTAL_DMA_DESC_SIZE, NULL, 0);
bfin_write_TIMER_DISABLE(TIMEN_SP|TIMEN_SPS|TIMEN_PS_CLS|
TIMEN_LP|TIMEN_REV);
t_conf_done = 0;
free_dma(CH_PPI);
fb_dealloc_cmap(&bfin_lq035_fb.cmap);
lcd_device_unregister(lcd_dev);
backlight_device_unregister(bl_dev);
unregister_framebuffer(&bfin_lq035_fb);
i2c_del_driver(&ad5280_driver);
free_ports();
pr_info("unregistered LCD driver\n");
return 0;
}
static int bfin_lq035_suspend(struct platform_device *pdev, pm_message_t state)
{
if (lq035_open_cnt > 0) {
bfin_write_PPI_CONTROL(0);
SSYNC();
disable_dma(CH_PPI);
}
return 0;
}
static int bfin_lq035_resume(struct platform_device *pdev)
{
if (lq035_open_cnt > 0) {
bfin_write_PPI_CONTROL(0);
SSYNC();
config_dma();
config_ppi();
enable_dma(CH_PPI);
bfin_write_PPI_CONTROL(bfin_read_PPI_CONTROL() | PORT_EN);
SSYNC();
config_timers();
start_timers();
} else {
t_conf_done = 0;
}
return 0;
}
static int __init bfin_lq035_driver_init(void)
{
request_module("i2c-bfin-twi");
return platform_driver_register(&bfin_lq035_driver);
}
static void __exit bfin_lq035_driver_cleanup(void)
{
platform_driver_unregister(&bfin_lq035_driver);
}
