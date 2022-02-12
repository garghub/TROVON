static int mi0283qt_init(struct mipi_dbi *mipi)
{
struct tinydrm_device *tdev = &mipi->tinydrm;
struct device *dev = tdev->drm->dev;
u8 addr_mode;
int ret;
DRM_DEBUG_KMS("\n");
ret = regulator_enable(mipi->regulator);
if (ret) {
dev_err(dev, "Failed to enable regulator %d\n", ret);
return ret;
}
if (mipi_dbi_display_is_on(mipi))
return 0;
mipi_dbi_hw_reset(mipi);
ret = mipi_dbi_command(mipi, MIPI_DCS_SOFT_RESET);
if (ret) {
dev_err(dev, "Error sending command %d\n", ret);
regulator_disable(mipi->regulator);
return ret;
}
msleep(20);
mipi_dbi_command(mipi, MIPI_DCS_SET_DISPLAY_OFF);
mipi_dbi_command(mipi, ILI9341_PWCTRLB, 0x00, 0x83, 0x30);
mipi_dbi_command(mipi, ILI9341_PWRSEQ, 0x64, 0x03, 0x12, 0x81);
mipi_dbi_command(mipi, ILI9341_DTCTRLA, 0x85, 0x01, 0x79);
mipi_dbi_command(mipi, ILI9341_PWCTRLA, 0x39, 0x2c, 0x00, 0x34, 0x02);
mipi_dbi_command(mipi, ILI9341_PUMPCTRL, 0x20);
mipi_dbi_command(mipi, ILI9341_DTCTRLB, 0x00, 0x00);
mipi_dbi_command(mipi, ILI9341_PWCTRL1, 0x26);
mipi_dbi_command(mipi, ILI9341_PWCTRL2, 0x11);
mipi_dbi_command(mipi, ILI9341_VMCTRL1, 0x35, 0x3e);
mipi_dbi_command(mipi, ILI9341_VMCTRL2, 0xbe);
mipi_dbi_command(mipi, MIPI_DCS_SET_PIXEL_FORMAT, 0x55);
switch (mipi->rotation) {
default:
addr_mode = ILI9341_MADCTL_MV | ILI9341_MADCTL_MY |
ILI9341_MADCTL_MX;
break;
case 90:
addr_mode = ILI9341_MADCTL_MY;
break;
case 180:
addr_mode = ILI9341_MADCTL_MV;
break;
case 270:
addr_mode = ILI9341_MADCTL_MX;
break;
}
addr_mode |= ILI9341_MADCTL_BGR;
mipi_dbi_command(mipi, MIPI_DCS_SET_ADDRESS_MODE, addr_mode);
mipi_dbi_command(mipi, ILI9341_FRMCTR1, 0x00, 0x1b);
mipi_dbi_command(mipi, ILI9341_EN3GAM, 0x08);
mipi_dbi_command(mipi, MIPI_DCS_SET_GAMMA_CURVE, 0x01);
mipi_dbi_command(mipi, ILI9341_PGAMCTRL,
0x1f, 0x1a, 0x18, 0x0a, 0x0f, 0x06, 0x45, 0x87,
0x32, 0x0a, 0x07, 0x02, 0x07, 0x05, 0x00);
mipi_dbi_command(mipi, ILI9341_NGAMCTRL,
0x00, 0x25, 0x27, 0x05, 0x10, 0x09, 0x3a, 0x78,
0x4d, 0x05, 0x18, 0x0d, 0x38, 0x3a, 0x1f);
mipi_dbi_command(mipi, ILI9341_ETMOD, 0x07);
mipi_dbi_command(mipi, ILI9341_DISCTRL, 0x0a, 0x82, 0x27, 0x00);
mipi_dbi_command(mipi, MIPI_DCS_EXIT_SLEEP_MODE);
msleep(100);
mipi_dbi_command(mipi, MIPI_DCS_SET_DISPLAY_ON);
msleep(100);
return 0;
}
static void mi0283qt_fini(void *data)
{
struct mipi_dbi *mipi = data;
DRM_DEBUG_KMS("\n");
regulator_disable(mipi->regulator);
}
static int mi0283qt_probe(struct spi_device *spi)
{
struct device *dev = &spi->dev;
struct tinydrm_device *tdev;
struct mipi_dbi *mipi;
struct gpio_desc *dc;
u32 rotation = 0;
int ret;
mipi = devm_kzalloc(dev, sizeof(*mipi), GFP_KERNEL);
if (!mipi)
return -ENOMEM;
mipi->reset = devm_gpiod_get_optional(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(mipi->reset)) {
dev_err(dev, "Failed to get gpio 'reset'\n");
return PTR_ERR(mipi->reset);
}
dc = devm_gpiod_get_optional(dev, "dc", GPIOD_OUT_LOW);
if (IS_ERR(dc)) {
dev_err(dev, "Failed to get gpio 'dc'\n");
return PTR_ERR(dc);
}
mipi->regulator = devm_regulator_get(dev, "power");
if (IS_ERR(mipi->regulator))
return PTR_ERR(mipi->regulator);
mipi->backlight = tinydrm_of_find_backlight(dev);
if (IS_ERR(mipi->backlight))
return PTR_ERR(mipi->backlight);
device_property_read_u32(dev, "rotation", &rotation);
ret = mipi_dbi_spi_init(spi, mipi, dc);
if (ret)
return ret;
ret = mipi_dbi_init(&spi->dev, mipi, &mi0283qt_pipe_funcs,
&mi0283qt_driver, &mi0283qt_mode, rotation);
if (ret)
return ret;
ret = mi0283qt_init(mipi);
if (ret)
return ret;
ret = devm_add_action(dev, mi0283qt_fini, mipi);
if (ret) {
mi0283qt_fini(mipi);
return ret;
}
tdev = &mipi->tinydrm;
ret = devm_tinydrm_register(tdev);
if (ret)
return ret;
spi_set_drvdata(spi, mipi);
DRM_DEBUG_DRIVER("Initialized %s:%s @%uMHz on minor %d\n",
tdev->drm->driver->name, dev_name(dev),
spi->max_speed_hz / 1000000,
tdev->drm->primary->index);
return 0;
}
static void mi0283qt_shutdown(struct spi_device *spi)
{
struct mipi_dbi *mipi = spi_get_drvdata(spi);
tinydrm_shutdown(&mipi->tinydrm);
}
static int __maybe_unused mi0283qt_pm_suspend(struct device *dev)
{
struct mipi_dbi *mipi = dev_get_drvdata(dev);
int ret;
ret = tinydrm_suspend(&mipi->tinydrm);
if (ret)
return ret;
mi0283qt_fini(mipi);
return 0;
}
static int __maybe_unused mi0283qt_pm_resume(struct device *dev)
{
struct mipi_dbi *mipi = dev_get_drvdata(dev);
int ret;
ret = mi0283qt_init(mipi);
if (ret)
return ret;
return tinydrm_resume(&mipi->tinydrm);
}
