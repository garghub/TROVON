static int tdo24m_writes(struct tdo24m *lcd, uint32_t *array)
{
struct spi_transfer *x = &lcd->xfer;
uint32_t data, *p = array;
int nparams, err = 0;
for (; *p != CMD_NULL; p++) {
if (!lcd->color_invert && *p == CMD0(0x21))
continue;
nparams = (*p >> 30) & 0x3;
data = *p << (7 - nparams);
switch (nparams) {
case 0:
lcd->buf[0] = (data >> 8) & 0xff;
lcd->buf[1] = data & 0xff;
break;
case 1:
lcd->buf[0] = (data >> 16) & 0xff;
lcd->buf[1] = (data >> 8) & 0xff;
lcd->buf[2] = data & 0xff;
break;
case 2:
lcd->buf[0] = (data >> 24) & 0xff;
lcd->buf[1] = (data >> 16) & 0xff;
lcd->buf[2] = (data >> 8) & 0xff;
lcd->buf[3] = data & 0xff;
break;
default:
continue;
}
x->len = nparams + 2;
err = spi_sync(lcd->spi_dev, &lcd->msg);
if (err)
break;
}
return err;
}
static int tdo24m_adj_mode(struct tdo24m *lcd, int mode)
{
switch (mode) {
case MODE_VGA:
tdo24m_writes(lcd, lcd_vga_pass_through_tdo24m);
tdo24m_writes(lcd, lcd_panel_config);
tdo24m_writes(lcd, lcd_vga_transfer_tdo24m);
break;
case MODE_QVGA:
tdo24m_writes(lcd, lcd_qvga_pass_through_tdo24m);
tdo24m_writes(lcd, lcd_panel_config);
tdo24m_writes(lcd, lcd_qvga_transfer);
break;
default:
return -EINVAL;
}
lcd->mode = mode;
return 0;
}
static int tdo35s_adj_mode(struct tdo24m *lcd, int mode)
{
switch (mode) {
case MODE_VGA:
tdo24m_writes(lcd, lcd_vga_pass_through_tdo35s);
tdo24m_writes(lcd, lcd_panel_config);
tdo24m_writes(lcd, lcd_vga_transfer_tdo35s);
break;
case MODE_QVGA:
tdo24m_writes(lcd, lcd_qvga_pass_through_tdo35s);
tdo24m_writes(lcd, lcd_panel_config);
tdo24m_writes(lcd, lcd_qvga_transfer);
break;
default:
return -EINVAL;
}
lcd->mode = mode;
return 0;
}
static int tdo24m_power_on(struct tdo24m *lcd)
{
int err;
err = tdo24m_writes(lcd, lcd_panel_on);
if (err)
goto out;
err = tdo24m_writes(lcd, lcd_panel_reset);
if (err)
goto out;
err = lcd->adj_mode(lcd, lcd->mode);
out:
return err;
}
static int tdo24m_power_off(struct tdo24m *lcd)
{
return tdo24m_writes(lcd, lcd_panel_off);
}
static int tdo24m_power(struct tdo24m *lcd, int power)
{
int ret = 0;
if (POWER_IS_ON(power) && !POWER_IS_ON(lcd->power))
ret = tdo24m_power_on(lcd);
else if (!POWER_IS_ON(power) && POWER_IS_ON(lcd->power))
ret = tdo24m_power_off(lcd);
if (!ret)
lcd->power = power;
return ret;
}
static int tdo24m_set_power(struct lcd_device *ld, int power)
{
struct tdo24m *lcd = lcd_get_data(ld);
return tdo24m_power(lcd, power);
}
static int tdo24m_get_power(struct lcd_device *ld)
{
struct tdo24m *lcd = lcd_get_data(ld);
return lcd->power;
}
static int tdo24m_set_mode(struct lcd_device *ld, struct fb_videomode *m)
{
struct tdo24m *lcd = lcd_get_data(ld);
int mode = MODE_QVGA;
if (m->xres == 640 || m->xres == 480)
mode = MODE_VGA;
if (lcd->mode == mode)
return 0;
return lcd->adj_mode(lcd, mode);
}
static int __devinit tdo24m_probe(struct spi_device *spi)
{
struct tdo24m *lcd;
struct spi_message *m;
struct spi_transfer *x;
struct tdo24m_platform_data *pdata;
enum tdo24m_model model;
int err;
pdata = spi->dev.platform_data;
if (pdata)
model = pdata->model;
else
model = TDO24M;
spi->bits_per_word = 8;
spi->mode = SPI_MODE_3;
err = spi_setup(spi);
if (err)
return err;
lcd = kzalloc(sizeof(struct tdo24m), GFP_KERNEL);
if (!lcd)
return -ENOMEM;
lcd->spi_dev = spi;
lcd->power = FB_BLANK_POWERDOWN;
lcd->mode = MODE_VGA;
lcd->buf = kmalloc(TDO24M_SPI_BUFF_SIZE, GFP_KERNEL);
if (lcd->buf == NULL) {
kfree(lcd);
return -ENOMEM;
}
m = &lcd->msg;
x = &lcd->xfer;
spi_message_init(m);
x->cs_change = 1;
x->tx_buf = &lcd->buf[0];
spi_message_add_tail(x, m);
switch (model) {
case TDO24M:
lcd->color_invert = 1;
lcd->adj_mode = tdo24m_adj_mode;
break;
case TDO35S:
lcd->adj_mode = tdo35s_adj_mode;
lcd->color_invert = 0;
break;
default:
dev_err(&spi->dev, "Unsupported model");
goto out_free;
}
lcd->lcd_dev = lcd_device_register("tdo24m", &spi->dev,
lcd, &tdo24m_ops);
if (IS_ERR(lcd->lcd_dev)) {
err = PTR_ERR(lcd->lcd_dev);
goto out_free;
}
dev_set_drvdata(&spi->dev, lcd);
err = tdo24m_power(lcd, FB_BLANK_UNBLANK);
if (err)
goto out_unregister;
return 0;
out_unregister:
lcd_device_unregister(lcd->lcd_dev);
out_free:
kfree(lcd->buf);
kfree(lcd);
return err;
}
static int __devexit tdo24m_remove(struct spi_device *spi)
{
struct tdo24m *lcd = dev_get_drvdata(&spi->dev);
tdo24m_power(lcd, FB_BLANK_POWERDOWN);
lcd_device_unregister(lcd->lcd_dev);
kfree(lcd->buf);
kfree(lcd);
return 0;
}
static int tdo24m_suspend(struct spi_device *spi, pm_message_t state)
{
struct tdo24m *lcd = dev_get_drvdata(&spi->dev);
return tdo24m_power(lcd, FB_BLANK_POWERDOWN);
}
static int tdo24m_resume(struct spi_device *spi)
{
struct tdo24m *lcd = dev_get_drvdata(&spi->dev);
return tdo24m_power(lcd, FB_BLANK_UNBLANK);
}
static void tdo24m_shutdown(struct spi_device *spi)
{
struct tdo24m *lcd = dev_get_drvdata(&spi->dev);
tdo24m_power(lcd, FB_BLANK_POWERDOWN);
}
