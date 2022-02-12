static void lcdtg_ssp_i2c_send(struct corgi_lcd *lcd, uint8_t data)
{
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS, data);
udelay(10);
}
static void lcdtg_i2c_send_bit(struct corgi_lcd *lcd, uint8_t data)
{
lcdtg_ssp_i2c_send(lcd, data);
lcdtg_ssp_i2c_send(lcd, data | POWER0_COM_DCLK);
lcdtg_ssp_i2c_send(lcd, data);
}
static void lcdtg_i2c_send_start(struct corgi_lcd *lcd, uint8_t base)
{
lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK | POWER0_COM_DOUT);
lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK);
lcdtg_ssp_i2c_send(lcd, base);
}
static void lcdtg_i2c_send_stop(struct corgi_lcd *lcd, uint8_t base)
{
lcdtg_ssp_i2c_send(lcd, base);
lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK);
lcdtg_ssp_i2c_send(lcd, base | POWER0_COM_DCLK | POWER0_COM_DOUT);
}
static void lcdtg_i2c_send_byte(struct corgi_lcd *lcd,
uint8_t base, uint8_t data)
{
int i;
for (i = 0; i < 8; i++) {
if (data & 0x80)
lcdtg_i2c_send_bit(lcd, base | POWER0_COM_DOUT);
else
lcdtg_i2c_send_bit(lcd, base);
data <<= 1;
}
}
static void lcdtg_i2c_wait_ack(struct corgi_lcd *lcd, uint8_t base)
{
lcdtg_i2c_send_bit(lcd, base);
}
static void lcdtg_set_common_voltage(struct corgi_lcd *lcd,
uint8_t base_data, uint8_t data)
{
lcdtg_i2c_send_start(lcd, base_data);
lcdtg_i2c_send_byte(lcd, base_data, 0x9c);
lcdtg_i2c_wait_ack(lcd, base_data);
lcdtg_i2c_send_byte(lcd, base_data, 0x00);
lcdtg_i2c_wait_ack(lcd, base_data);
lcdtg_i2c_send_byte(lcd, base_data, data);
lcdtg_i2c_wait_ack(lcd, base_data);
lcdtg_i2c_send_stop(lcd, base_data);
}
static int corgi_ssp_lcdtg_send(struct corgi_lcd *lcd, int adrs, uint8_t data)
{
struct spi_message msg;
struct spi_transfer xfer = {
.len = 1,
.cs_change = 1,
.tx_buf = lcd->buf,
};
lcd->buf[0] = ((adrs & 0x07) << 5) | (data & 0x1f);
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
return spi_sync(lcd->spi_dev, &msg);
}
static void lcdtg_set_phadadj(struct corgi_lcd *lcd, int mode)
{
int adj;
switch(mode) {
case CORGI_LCD_MODE_VGA:
adj = sharpsl_param.phadadj;
adj = (adj < 0) ? PHACTRL_PHASE_MANUAL :
PHACTRL_PHASE_MANUAL | ((adj & 0xf) << 1);
break;
case CORGI_LCD_MODE_QVGA:
default:
adj = (DEFAULT_PHAD_QVGA << 1) | PHACTRL_PHASE_MANUAL;
break;
}
corgi_ssp_lcdtg_send(lcd, PHACTRL_ADRS, adj);
}
static void corgi_lcd_power_on(struct corgi_lcd *lcd)
{
int comadj;
corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS,
PICTRL_POWER_DOWN | PICTRL_INIOFF |
PICTRL_INIT_STATE | PICTRL_COM_SIGNAL_OFF |
PICTRL_DAC_SIGNAL_OFF);
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_OFF |
POWER0_COM_OFF | POWER0_VCC5_OFF);
corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_OFF);
corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_ON);
mdelay(3);
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_ON |
POWER0_COM_OFF | POWER0_VCC5_OFF);
corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS,
PICTRL_INIT_STATE | PICTRL_COM_SIGNAL_OFF);
comadj = sharpsl_param.comadj;
if (comadj < 0)
comadj = DEFAULT_COMADJ;
lcdtg_set_common_voltage(lcd, POWER0_DAC_ON | POWER0_COM_OFF |
POWER0_VCC5_OFF, comadj);
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_ON |
POWER0_COM_OFF | POWER0_VCC5_ON);
corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
POWER1_VW_OFF | POWER1_GVSS_ON | POWER1_VDD_ON);
mdelay(2);
corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS, PICTRL_INIT_STATE);
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
POWER0_COM_DCLK | POWER0_COM_DOUT | POWER0_DAC_ON |
POWER0_COM_ON | POWER0_VCC5_ON);
corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
POWER1_VW_ON | POWER1_GVSS_ON | POWER1_VDD_ON);
corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS, 0);
lcdtg_set_phadadj(lcd, lcd->mode);
corgi_ssp_lcdtg_send(lcd, POLCTRL_ADRS,
POLCTRL_SYNC_POL_RISE | POLCTRL_EN_POL_RISE |
POLCTRL_DATA_POL_RISE | POLCTRL_SYNC_ACT_L |
POLCTRL_EN_ACT_H);
udelay(1000);
switch (lcd->mode) {
case CORGI_LCD_MODE_VGA:
corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_VGA);
break;
case CORGI_LCD_MODE_QVGA:
default:
corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_QVGA);
break;
}
}
static void corgi_lcd_power_off(struct corgi_lcd *lcd)
{
msleep(34);
corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
POWER1_VW_OFF | POWER1_GVSS_ON | POWER1_VDD_ON);
corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS, PICTRL_COM_SIGNAL_OFF);
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
POWER0_DAC_ON | POWER0_COM_OFF | POWER0_VCC5_ON);
lcdtg_set_common_voltage(lcd, POWER0_DAC_ON | POWER0_COM_OFF |
POWER0_VCC5_ON, 0);
corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_ON);
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
POWER0_DAC_ON | POWER0_COM_OFF | POWER0_VCC5_OFF);
corgi_ssp_lcdtg_send(lcd, PICTRL_ADRS,
PICTRL_INIOFF | PICTRL_DAC_SIGNAL_OFF |
PICTRL_POWER_DOWN | PICTRL_COM_SIGNAL_OFF);
corgi_ssp_lcdtg_send(lcd, POWERREG0_ADRS,
POWER0_DAC_OFF | POWER0_COM_OFF | POWER0_VCC5_OFF);
corgi_ssp_lcdtg_send(lcd, POWERREG1_ADRS,
POWER1_VW_OFF | POWER1_GVSS_OFF | POWER1_VDD_OFF);
}
static int corgi_lcd_set_mode(struct lcd_device *ld, struct fb_videomode *m)
{
struct corgi_lcd *lcd = dev_get_drvdata(&ld->dev);
int mode = CORGI_LCD_MODE_QVGA;
if (m->xres == 640 || m->xres == 480)
mode = CORGI_LCD_MODE_VGA;
if (lcd->mode == mode)
return 0;
lcdtg_set_phadadj(lcd, mode);
switch (mode) {
case CORGI_LCD_MODE_VGA:
corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_VGA);
break;
case CORGI_LCD_MODE_QVGA:
default:
corgi_ssp_lcdtg_send(lcd, RESCTL_ADRS, RESCTL_QVGA);
break;
}
lcd->mode = mode;
return 0;
}
static int corgi_lcd_set_power(struct lcd_device *ld, int power)
{
struct corgi_lcd *lcd = dev_get_drvdata(&ld->dev);
if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->power))
corgi_lcd_power_on(lcd);
if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->power))
corgi_lcd_power_off(lcd);
lcd->power = power;
return 0;
}
static int corgi_lcd_get_power(struct lcd_device *ld)
{
struct corgi_lcd *lcd = dev_get_drvdata(&ld->dev);
return lcd->power;
}
static int corgi_bl_get_intensity(struct backlight_device *bd)
{
struct corgi_lcd *lcd = dev_get_drvdata(&bd->dev);
return lcd->intensity;
}
static int corgi_bl_set_intensity(struct corgi_lcd *lcd, int intensity)
{
int cont;
if (intensity > 0x10)
intensity += 0x10;
corgi_ssp_lcdtg_send(lcd, DUTYCTRL_ADRS, intensity);
cont = !!(intensity & 0x20) ^ lcd->gpio_backlight_cont_inverted;
if (gpio_is_valid(lcd->gpio_backlight_cont))
gpio_set_value(lcd->gpio_backlight_cont, cont);
if (gpio_is_valid(lcd->gpio_backlight_on))
gpio_set_value(lcd->gpio_backlight_on, intensity);
if (lcd->kick_battery)
lcd->kick_battery();
lcd->intensity = intensity;
return 0;
}
static int corgi_bl_update_status(struct backlight_device *bd)
{
struct corgi_lcd *lcd = dev_get_drvdata(&bd->dev);
int intensity = bd->props.brightness;
if (bd->props.power != FB_BLANK_UNBLANK)
intensity = 0;
if (bd->props.fb_blank != FB_BLANK_UNBLANK)
intensity = 0;
if (corgibl_flags & CORGIBL_SUSPENDED)
intensity = 0;
if ((corgibl_flags & CORGIBL_BATTLOW) && intensity > lcd->limit_mask)
intensity = lcd->limit_mask;
return corgi_bl_set_intensity(lcd, intensity);
}
void corgi_lcd_limit_intensity(int limit)
{
if (limit)
corgibl_flags |= CORGIBL_BATTLOW;
else
corgibl_flags &= ~CORGIBL_BATTLOW;
backlight_update_status(the_corgi_lcd->bl_dev);
}
static int corgi_lcd_suspend(struct spi_device *spi, pm_message_t state)
{
struct corgi_lcd *lcd = dev_get_drvdata(&spi->dev);
corgibl_flags |= CORGIBL_SUSPENDED;
corgi_bl_set_intensity(lcd, 0);
corgi_lcd_set_power(lcd->lcd_dev, FB_BLANK_POWERDOWN);
return 0;
}
static int corgi_lcd_resume(struct spi_device *spi)
{
struct corgi_lcd *lcd = dev_get_drvdata(&spi->dev);
corgibl_flags &= ~CORGIBL_SUSPENDED;
corgi_lcd_set_power(lcd->lcd_dev, FB_BLANK_UNBLANK);
backlight_update_status(lcd->bl_dev);
return 0;
}
static int setup_gpio_backlight(struct corgi_lcd *lcd,
struct corgi_lcd_platform_data *pdata)
{
struct spi_device *spi = lcd->spi_dev;
int err;
lcd->gpio_backlight_on = -1;
lcd->gpio_backlight_cont = -1;
if (gpio_is_valid(pdata->gpio_backlight_on)) {
err = gpio_request(pdata->gpio_backlight_on, "BL_ON");
if (err) {
dev_err(&spi->dev, "failed to request GPIO%d for "
"backlight_on\n", pdata->gpio_backlight_on);
return err;
}
lcd->gpio_backlight_on = pdata->gpio_backlight_on;
gpio_direction_output(lcd->gpio_backlight_on, 0);
}
if (gpio_is_valid(pdata->gpio_backlight_cont)) {
err = gpio_request(pdata->gpio_backlight_cont, "BL_CONT");
if (err) {
dev_err(&spi->dev, "failed to request GPIO%d for "
"backlight_cont\n", pdata->gpio_backlight_cont);
goto err_free_backlight_on;
}
lcd->gpio_backlight_cont = pdata->gpio_backlight_cont;
if (gpio_is_valid(lcd->gpio_backlight_on)) {
lcd->gpio_backlight_cont_inverted = 1;
gpio_direction_output(lcd->gpio_backlight_cont, 1);
} else {
lcd->gpio_backlight_cont_inverted = 0;
gpio_direction_output(lcd->gpio_backlight_cont, 0);
}
}
return 0;
err_free_backlight_on:
if (gpio_is_valid(lcd->gpio_backlight_on))
gpio_free(lcd->gpio_backlight_on);
return err;
}
static int __devinit corgi_lcd_probe(struct spi_device *spi)
{
struct backlight_properties props;
struct corgi_lcd_platform_data *pdata = spi->dev.platform_data;
struct corgi_lcd *lcd;
int ret = 0;
if (pdata == NULL) {
dev_err(&spi->dev, "platform data not available\n");
return -EINVAL;
}
lcd = devm_kzalloc(&spi->dev, sizeof(struct corgi_lcd), GFP_KERNEL);
if (!lcd) {
dev_err(&spi->dev, "failed to allocate memory\n");
return -ENOMEM;
}
lcd->spi_dev = spi;
lcd->lcd_dev = lcd_device_register("corgi_lcd", &spi->dev,
lcd, &corgi_lcd_ops);
if (IS_ERR(lcd->lcd_dev))
return PTR_ERR(lcd->lcd_dev);
lcd->power = FB_BLANK_POWERDOWN;
lcd->mode = (pdata) ? pdata->init_mode : CORGI_LCD_MODE_VGA;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = pdata->max_intensity;
lcd->bl_dev = backlight_device_register("corgi_bl", &spi->dev, lcd,
&corgi_bl_ops, &props);
if (IS_ERR(lcd->bl_dev)) {
ret = PTR_ERR(lcd->bl_dev);
goto err_unregister_lcd;
}
lcd->bl_dev->props.brightness = pdata->default_intensity;
lcd->bl_dev->props.power = FB_BLANK_UNBLANK;
ret = setup_gpio_backlight(lcd, pdata);
if (ret)
goto err_unregister_bl;
lcd->kick_battery = pdata->kick_battery;
dev_set_drvdata(&spi->dev, lcd);
corgi_lcd_set_power(lcd->lcd_dev, FB_BLANK_UNBLANK);
backlight_update_status(lcd->bl_dev);
lcd->limit_mask = pdata->limit_mask;
the_corgi_lcd = lcd;
return 0;
err_unregister_bl:
backlight_device_unregister(lcd->bl_dev);
err_unregister_lcd:
lcd_device_unregister(lcd->lcd_dev);
return ret;
}
static int __devexit corgi_lcd_remove(struct spi_device *spi)
{
struct corgi_lcd *lcd = dev_get_drvdata(&spi->dev);
lcd->bl_dev->props.power = FB_BLANK_UNBLANK;
lcd->bl_dev->props.brightness = 0;
backlight_update_status(lcd->bl_dev);
backlight_device_unregister(lcd->bl_dev);
if (gpio_is_valid(lcd->gpio_backlight_on))
gpio_free(lcd->gpio_backlight_on);
if (gpio_is_valid(lcd->gpio_backlight_cont))
gpio_free(lcd->gpio_backlight_cont);
corgi_lcd_set_power(lcd->lcd_dev, FB_BLANK_POWERDOWN);
lcd_device_unregister(lcd->lcd_dev);
return 0;
}
