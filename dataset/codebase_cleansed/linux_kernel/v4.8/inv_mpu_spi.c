static int inv_mpu_i2c_disable(struct iio_dev *indio_dev)
{
struct inv_mpu6050_state *st = iio_priv(indio_dev);
int ret = 0;
ret = inv_mpu6050_set_power_itg(st, true);
if (ret)
return ret;
ret = regmap_write(st->map, INV_MPU6050_REG_USER_CTRL,
INV_MPU6050_BIT_I2C_IF_DIS);
if (ret) {
inv_mpu6050_set_power_itg(st, false);
return ret;
}
return inv_mpu6050_set_power_itg(st, false);
}
static int inv_mpu_probe(struct spi_device *spi)
{
struct regmap *regmap;
const struct spi_device_id *spi_id;
const struct acpi_device_id *acpi_id;
const char *name = NULL;
enum inv_devices chip_type;
if ((spi_id = spi_get_device_id(spi))) {
chip_type = (enum inv_devices)spi_id->driver_data;
name = spi_id->name;
} else if ((acpi_id = acpi_match_device(spi->dev.driver->acpi_match_table, &spi->dev))) {
chip_type = (enum inv_devices)acpi_id->driver_data;
} else {
return -ENODEV;
}
regmap = devm_regmap_init_spi(spi, &inv_mpu_regmap_config);
if (IS_ERR(regmap)) {
dev_err(&spi->dev, "Failed to register spi regmap %d\n",
(int)PTR_ERR(regmap));
return PTR_ERR(regmap);
}
return inv_mpu_core_probe(regmap, spi->irq, name,
inv_mpu_i2c_disable, chip_type);
}
static int inv_mpu_remove(struct spi_device *spi)
{
return inv_mpu_core_remove(&spi->dev);
}
