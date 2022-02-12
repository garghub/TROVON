static void l4f00242t03_reset(unsigned int gpio)
{
pr_debug("l4f00242t03_reset.\n");
gpio_set_value(gpio, 1);
mdelay(100);
gpio_set_value(gpio, 0);
mdelay(10);
gpio_set_value(gpio, 1);
mdelay(20);
}
static void l4f00242t03_lcd_init(struct spi_device *spi)
{
struct l4f00242t03_pdata *pdata = dev_get_platdata(&spi->dev);
struct l4f00242t03_priv *priv = spi_get_drvdata(spi);
const u16 cmd[] = { 0x36, param(0), 0x3A, param(0x60) };
int ret;
dev_dbg(&spi->dev, "initializing LCD\n");
ret = regulator_set_voltage(priv->io_reg, 1800000, 1800000);
if (ret) {
dev_err(&spi->dev, "failed to set the IO regulator voltage.\n");
return;
}
ret = regulator_enable(priv->io_reg);
if (ret) {
dev_err(&spi->dev, "failed to enable the IO regulator.\n");
return;
}
ret = regulator_set_voltage(priv->core_reg, 2800000, 2800000);
if (ret) {
dev_err(&spi->dev, "failed to set the core regulator voltage.\n");
regulator_disable(priv->io_reg);
return;
}
ret = regulator_enable(priv->core_reg);
if (ret) {
dev_err(&spi->dev, "failed to enable the core regulator.\n");
regulator_disable(priv->io_reg);
return;
}
l4f00242t03_reset(pdata->reset_gpio);
gpio_set_value(pdata->data_enable_gpio, 1);
msleep(60);
spi_write(spi, (const u8 *)cmd, ARRAY_SIZE(cmd) * sizeof(u16));
}
static void l4f00242t03_lcd_powerdown(struct spi_device *spi)
{
struct l4f00242t03_pdata *pdata = dev_get_platdata(&spi->dev);
struct l4f00242t03_priv *priv = spi_get_drvdata(spi);
dev_dbg(&spi->dev, "Powering down LCD\n");
gpio_set_value(pdata->data_enable_gpio, 0);
regulator_disable(priv->io_reg);
regulator_disable(priv->core_reg);
}
static int l4f00242t03_lcd_power_get(struct lcd_device *ld)
{
struct l4f00242t03_priv *priv = lcd_get_data(ld);
return priv->lcd_state;
}
static int l4f00242t03_lcd_power_set(struct lcd_device *ld, int power)
{
struct l4f00242t03_priv *priv = lcd_get_data(ld);
struct spi_device *spi = priv->spi;
const u16 slpout = 0x11;
const u16 dison = 0x29;
const u16 slpin = 0x10;
const u16 disoff = 0x28;
if (power <= FB_BLANK_NORMAL) {
if (priv->lcd_state <= FB_BLANK_NORMAL) {
} else if (priv->lcd_state < FB_BLANK_POWERDOWN) {
dev_dbg(&spi->dev, "Resuming LCD\n");
spi_write(spi, (const u8 *)&slpout, sizeof(u16));
msleep(60);
spi_write(spi, (const u8 *)&dison, sizeof(u16));
} else {
l4f00242t03_lcd_init(spi);
priv->lcd_state = FB_BLANK_VSYNC_SUSPEND;
l4f00242t03_lcd_power_set(priv->ld, power);
}
} else if (power < FB_BLANK_POWERDOWN) {
if (priv->lcd_state <= FB_BLANK_NORMAL) {
dev_dbg(&spi->dev, "Standby the LCD\n");
spi_write(spi, (const u8 *)&disoff, sizeof(u16));
msleep(60);
spi_write(spi, (const u8 *)&slpin, sizeof(u16));
} else if (priv->lcd_state < FB_BLANK_POWERDOWN) {
} else {
l4f00242t03_lcd_init(spi);
priv->lcd_state = FB_BLANK_UNBLANK;
l4f00242t03_lcd_power_set(ld, power);
}
} else {
if (priv->lcd_state != FB_BLANK_POWERDOWN) {
spi_write(spi, (const u8 *)&disoff, sizeof(u16));
msleep(60);
l4f00242t03_lcd_powerdown(spi);
}
}
priv->lcd_state = power;
return 0;
}
static int l4f00242t03_probe(struct spi_device *spi)
{
struct l4f00242t03_priv *priv;
struct l4f00242t03_pdata *pdata = dev_get_platdata(&spi->dev);
int ret;
if (pdata == NULL) {
dev_err(&spi->dev, "Uninitialized platform data.\n");
return -EINVAL;
}
priv = devm_kzalloc(&spi->dev, sizeof(struct l4f00242t03_priv),
GFP_KERNEL);
if (priv == NULL)
return -ENOMEM;
spi_set_drvdata(spi, priv);
spi->bits_per_word = 9;
spi_setup(spi);
priv->spi = spi;
ret = devm_gpio_request_one(&spi->dev, pdata->reset_gpio,
GPIOF_OUT_INIT_HIGH, "lcd l4f00242t03 reset");
if (ret) {
dev_err(&spi->dev,
"Unable to get the lcd l4f00242t03 reset gpio.\n");
return ret;
}
ret = devm_gpio_request_one(&spi->dev, pdata->data_enable_gpio,
GPIOF_OUT_INIT_LOW, "lcd l4f00242t03 data enable");
if (ret) {
dev_err(&spi->dev,
"Unable to get the lcd l4f00242t03 data en gpio.\n");
return ret;
}
priv->io_reg = devm_regulator_get(&spi->dev, "vdd");
if (IS_ERR(priv->io_reg)) {
dev_err(&spi->dev, "%s: Unable to get the IO regulator\n",
__func__);
return PTR_ERR(priv->io_reg);
}
priv->core_reg = devm_regulator_get(&spi->dev, "vcore");
if (IS_ERR(priv->core_reg)) {
dev_err(&spi->dev, "%s: Unable to get the core regulator\n",
__func__);
return PTR_ERR(priv->core_reg);
}
priv->ld = devm_lcd_device_register(&spi->dev, "l4f00242t03", &spi->dev,
priv, &l4f_ops);
if (IS_ERR(priv->ld))
return PTR_ERR(priv->ld);
l4f00242t03_lcd_init(spi);
priv->lcd_state = FB_BLANK_VSYNC_SUSPEND;
l4f00242t03_lcd_power_set(priv->ld, FB_BLANK_UNBLANK);
dev_info(&spi->dev, "Epson l4f00242t03 lcd probed.\n");
return 0;
}
static int l4f00242t03_remove(struct spi_device *spi)
{
struct l4f00242t03_priv *priv = spi_get_drvdata(spi);
l4f00242t03_lcd_power_set(priv->ld, FB_BLANK_POWERDOWN);
return 0;
}
static void l4f00242t03_shutdown(struct spi_device *spi)
{
struct l4f00242t03_priv *priv = spi_get_drvdata(spi);
if (priv)
l4f00242t03_lcd_power_set(priv->ld, FB_BLANK_POWERDOWN);
}
