static ssize_t lm70_sense_temp(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct lm70 *p_lm70 = dev_get_drvdata(dev);
struct spi_device *spi = p_lm70->spi;
int status, val = 0;
u8 rxbuf[2];
s16 raw = 0;
if (mutex_lock_interruptible(&p_lm70->lock))
return -ERESTARTSYS;
status = spi_write_then_read(spi, NULL, 0, &rxbuf[0], 2);
if (status < 0) {
pr_warn("spi_write_then_read failed with status %d\n", status);
goto out;
}
raw = (rxbuf[0] << 8) + rxbuf[1];
dev_dbg(dev, "rxbuf[0] : 0x%02x rxbuf[1] : 0x%02x raw=0x%04x\n",
rxbuf[0], rxbuf[1], raw);
switch (p_lm70->chip) {
case LM70_CHIP_LM70:
val = ((int)raw / 32) * 250;
break;
case LM70_CHIP_TMP121:
case LM70_CHIP_LM74:
val = ((int)raw / 8) * 625 / 10;
break;
case LM70_CHIP_LM71:
val = ((int)raw / 4) * 3125 / 100;
break;
}
status = sprintf(buf, "%d\n", val);
out:
mutex_unlock(&p_lm70->lock);
return status;
}
static int lm70_probe(struct spi_device *spi)
{
const struct of_device_id *match;
struct device *hwmon_dev;
struct lm70 *p_lm70;
int chip;
match = of_match_device(lm70_of_ids, &spi->dev);
if (match)
chip = (int)(uintptr_t)match->data;
else
chip = spi_get_device_id(spi)->driver_data;
if (spi->mode & (SPI_CPOL | SPI_CPHA))
return -EINVAL;
p_lm70 = devm_kzalloc(&spi->dev, sizeof(*p_lm70), GFP_KERNEL);
if (!p_lm70)
return -ENOMEM;
mutex_init(&p_lm70->lock);
p_lm70->chip = chip;
p_lm70->spi = spi;
hwmon_dev = devm_hwmon_device_register_with_groups(&spi->dev,
spi->modalias,
p_lm70, lm70_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
