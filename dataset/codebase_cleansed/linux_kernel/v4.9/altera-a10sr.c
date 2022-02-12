static bool altr_a10sr_reg_readable(struct device *dev, unsigned int reg)
{
switch (reg) {
case ALTR_A10SR_VERSION_READ:
case ALTR_A10SR_LED_REG:
case ALTR_A10SR_PBDSW_REG:
case ALTR_A10SR_PBDSW_IRQ_REG:
case ALTR_A10SR_PWR_GOOD1_REG:
case ALTR_A10SR_PWR_GOOD2_REG:
case ALTR_A10SR_PWR_GOOD3_REG:
case ALTR_A10SR_FMCAB_REG:
case ALTR_A10SR_HPS_RST_REG:
case ALTR_A10SR_USB_QSPI_REG:
case ALTR_A10SR_SFPA_REG:
case ALTR_A10SR_SFPB_REG:
case ALTR_A10SR_I2C_M_REG:
case ALTR_A10SR_WARM_RST_REG:
case ALTR_A10SR_WR_KEY_REG:
case ALTR_A10SR_PMBUS_REG:
return true;
default:
return false;
}
}
static bool altr_a10sr_reg_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case ALTR_A10SR_LED_REG:
case ALTR_A10SR_PBDSW_IRQ_REG:
case ALTR_A10SR_FMCAB_REG:
case ALTR_A10SR_HPS_RST_REG:
case ALTR_A10SR_USB_QSPI_REG:
case ALTR_A10SR_SFPA_REG:
case ALTR_A10SR_SFPB_REG:
case ALTR_A10SR_WARM_RST_REG:
case ALTR_A10SR_WR_KEY_REG:
case ALTR_A10SR_PMBUS_REG:
return true;
default:
return false;
}
}
static bool altr_a10sr_reg_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case ALTR_A10SR_PBDSW_REG:
case ALTR_A10SR_PBDSW_IRQ_REG:
case ALTR_A10SR_PWR_GOOD1_REG:
case ALTR_A10SR_PWR_GOOD2_REG:
case ALTR_A10SR_PWR_GOOD3_REG:
case ALTR_A10SR_HPS_RST_REG:
case ALTR_A10SR_I2C_M_REG:
case ALTR_A10SR_WARM_RST_REG:
case ALTR_A10SR_WR_KEY_REG:
case ALTR_A10SR_PMBUS_REG:
return true;
default:
return false;
}
}
static int altr_a10sr_spi_probe(struct spi_device *spi)
{
int ret;
struct altr_a10sr *a10sr;
a10sr = devm_kzalloc(&spi->dev, sizeof(*a10sr),
GFP_KERNEL);
if (!a10sr)
return -ENOMEM;
spi->mode = SPI_MODE_3;
spi->bits_per_word = 8;
spi_setup(spi);
a10sr->dev = &spi->dev;
spi_set_drvdata(spi, a10sr);
a10sr->regmap = devm_regmap_init_spi(spi, &altr_a10sr_regmap_config);
if (IS_ERR(a10sr->regmap)) {
ret = PTR_ERR(a10sr->regmap);
dev_err(&spi->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
ret = devm_mfd_add_devices(a10sr->dev, PLATFORM_DEVID_AUTO,
altr_a10sr_subdev_info,
ARRAY_SIZE(altr_a10sr_subdev_info),
NULL, 0, NULL);
if (ret)
dev_err(a10sr->dev, "Failed to register sub-devices: %d\n",
ret);
return ret;
}
