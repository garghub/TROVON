static int tusb1210_power_on(struct phy *phy)
{
struct tusb1210 *tusb = phy_get_drvdata(phy);
gpiod_set_value_cansleep(tusb->gpio_reset, 1);
gpiod_set_value_cansleep(tusb->gpio_cs, 1);
if (tusb->vendor_specific2)
ulpi_write(tusb->ulpi, TUSB1210_VENDOR_SPECIFIC2,
tusb->vendor_specific2);
return 0;
}
static int tusb1210_power_off(struct phy *phy)
{
struct tusb1210 *tusb = phy_get_drvdata(phy);
gpiod_set_value_cansleep(tusb->gpio_reset, 0);
gpiod_set_value_cansleep(tusb->gpio_cs, 0);
return 0;
}
static int tusb1210_probe(struct ulpi *ulpi)
{
struct tusb1210 *tusb;
u8 val, reg;
tusb = devm_kzalloc(&ulpi->dev, sizeof(*tusb), GFP_KERNEL);
if (!tusb)
return -ENOMEM;
tusb->gpio_reset = devm_gpiod_get_optional(&ulpi->dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(tusb->gpio_reset))
return PTR_ERR(tusb->gpio_reset);
gpiod_set_value_cansleep(tusb->gpio_reset, 1);
tusb->gpio_cs = devm_gpiod_get_optional(&ulpi->dev, "cs",
GPIOD_OUT_LOW);
if (IS_ERR(tusb->gpio_cs))
return PTR_ERR(tusb->gpio_cs);
gpiod_set_value_cansleep(tusb->gpio_cs, 1);
device_property_read_u8(&ulpi->dev, "ihstx", &val);
reg = val << TUSB1210_VENDOR_SPECIFIC2_IHSTX_SHIFT;
device_property_read_u8(&ulpi->dev, "zhsdrv", &val);
reg |= val << TUSB1210_VENDOR_SPECIFIC2_ZHSDRV_SHIFT;
device_property_read_u8(&ulpi->dev, "datapolarity", &val);
reg |= val << TUSB1210_VENDOR_SPECIFIC2_DP_SHIFT;
if (reg) {
ulpi_write(ulpi, TUSB1210_VENDOR_SPECIFIC2, reg);
tusb->vendor_specific2 = reg;
}
tusb->phy = ulpi_phy_create(ulpi, &phy_ops);
if (IS_ERR(tusb->phy))
return PTR_ERR(tusb->phy);
tusb->ulpi = ulpi;
phy_set_drvdata(tusb->phy, tusb);
ulpi_set_drvdata(ulpi, tusb);
return 0;
}
static void tusb1210_remove(struct ulpi *ulpi)
{
struct tusb1210 *tusb = ulpi_get_drvdata(ulpi);
ulpi_phy_destroy(ulpi, tusb->phy);
}
