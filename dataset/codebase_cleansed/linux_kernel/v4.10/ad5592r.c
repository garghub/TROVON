static int ad5592r_spi_wnop_r16(struct ad5592r_state *st, __be16 *buf)
{
struct spi_device *spi = container_of(st->dev, struct spi_device, dev);
struct spi_transfer t = {
.tx_buf = &st->spi_msg_nop,
.rx_buf = buf,
.len = 2
};
st->spi_msg_nop = 0;
return spi_sync_transfer(spi, &t, 1);
}
static int ad5592r_write_dac(struct ad5592r_state *st, unsigned chan, u16 value)
{
struct spi_device *spi = container_of(st->dev, struct spi_device, dev);
st->spi_msg = cpu_to_be16(BIT(15) | (chan << 12) | value);
return spi_write(spi, &st->spi_msg, sizeof(st->spi_msg));
}
static int ad5592r_read_adc(struct ad5592r_state *st, unsigned chan, u16 *value)
{
struct spi_device *spi = container_of(st->dev, struct spi_device, dev);
int ret;
st->spi_msg = cpu_to_be16((AD5592R_REG_ADC_SEQ << 11) | BIT(chan));
ret = spi_write(spi, &st->spi_msg, sizeof(st->spi_msg));
if (ret)
return ret;
ret = ad5592r_spi_wnop_r16(st, &st->spi_msg);
if (ret)
return ret;
ret = ad5592r_spi_wnop_r16(st, &st->spi_msg);
if (ret)
return ret;
*value = be16_to_cpu(st->spi_msg);
return 0;
}
static int ad5592r_reg_write(struct ad5592r_state *st, u8 reg, u16 value)
{
struct spi_device *spi = container_of(st->dev, struct spi_device, dev);
st->spi_msg = cpu_to_be16((reg << 11) | value);
return spi_write(spi, &st->spi_msg, sizeof(st->spi_msg));
}
static int ad5592r_reg_read(struct ad5592r_state *st, u8 reg, u16 *value)
{
struct spi_device *spi = container_of(st->dev, struct spi_device, dev);
int ret;
st->spi_msg = cpu_to_be16((AD5592R_REG_LDAC << 11) |
AD5592R_LDAC_READBACK_EN | (reg << 2));
ret = spi_write(spi, &st->spi_msg, sizeof(st->spi_msg));
if (ret)
return ret;
ret = ad5592r_spi_wnop_r16(st, &st->spi_msg);
if (ret)
return ret;
*value = be16_to_cpu(st->spi_msg);
return 0;
}
static int ad5593r_gpio_read(struct ad5592r_state *st, u8 *value)
{
int ret;
ret = ad5592r_reg_write(st, AD5592R_REG_GPIO_IN_EN,
AD5592R_GPIO_READBACK_EN | st->gpio_in);
if (ret)
return ret;
ret = ad5592r_spi_wnop_r16(st, &st->spi_msg);
if (ret)
return ret;
*value = (u8) be16_to_cpu(st->spi_msg);
return 0;
}
static int ad5592r_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
return ad5592r_probe(&spi->dev, id->name, &ad5592r_rw_ops);
}
static int ad5592r_spi_remove(struct spi_device *spi)
{
return ad5592r_remove(&spi->dev);
}
