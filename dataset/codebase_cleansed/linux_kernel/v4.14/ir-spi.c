static int ir_spi_tx(struct rc_dev *dev,
unsigned int *buffer, unsigned int count)
{
int i;
int ret;
unsigned int len = 0;
struct ir_spi_data *idata = dev->priv;
struct spi_transfer xfer;
for (i = 0; i < count; i++) {
unsigned int periods;
int j;
u16 val;
periods = DIV_ROUND_CLOSEST(buffer[i] * idata->freq, 1000000);
if (len + periods >= IR_SPI_MAX_BUFSIZE)
return -EINVAL;
val = (i % 2) ? idata->space : idata->pulse;
for (j = 0; j < periods; j++)
idata->tx_buf[len++] = val;
}
memset(&xfer, 0, sizeof(xfer));
xfer.speed_hz = idata->freq * 16;
xfer.len = len * sizeof(*idata->tx_buf);
xfer.tx_buf = idata->tx_buf;
ret = regulator_enable(idata->regulator);
if (ret)
return ret;
ret = spi_sync_transfer(idata->spi, &xfer, 1);
if (ret)
dev_err(&idata->spi->dev, "unable to deliver the signal\n");
regulator_disable(idata->regulator);
return ret ? ret : count;
}
static int ir_spi_set_tx_carrier(struct rc_dev *dev, u32 carrier)
{
struct ir_spi_data *idata = dev->priv;
if (!carrier)
return -EINVAL;
idata->freq = carrier;
return 0;
}
static int ir_spi_set_duty_cycle(struct rc_dev *dev, u32 duty_cycle)
{
struct ir_spi_data *idata = dev->priv;
if (duty_cycle >= 90)
idata->pulse = IR_SPI_PULSE_DC_90;
else if (duty_cycle >= 80)
idata->pulse = IR_SPI_PULSE_DC_80;
else if (duty_cycle >= 75)
idata->pulse = IR_SPI_PULSE_DC_75;
else if (duty_cycle >= 70)
idata->pulse = IR_SPI_PULSE_DC_70;
else if (duty_cycle >= 60)
idata->pulse = IR_SPI_PULSE_DC_60;
else
idata->pulse = IR_SPI_PULSE_DC_50;
if (idata->negated) {
idata->pulse = ~idata->pulse;
idata->space = 0xffff;
} else {
idata->space = 0;
}
return 0;
}
static int ir_spi_probe(struct spi_device *spi)
{
int ret;
u8 dc;
struct ir_spi_data *idata;
idata = devm_kzalloc(&spi->dev, sizeof(*idata), GFP_KERNEL);
if (!idata)
return -ENOMEM;
idata->regulator = devm_regulator_get(&spi->dev, "irda_regulator");
if (IS_ERR(idata->regulator))
return PTR_ERR(idata->regulator);
idata->rc = devm_rc_allocate_device(&spi->dev, RC_DRIVER_IR_RAW_TX);
if (!idata->rc)
return -ENOMEM;
idata->rc->tx_ir = ir_spi_tx;
idata->rc->s_tx_carrier = ir_spi_set_tx_carrier;
idata->rc->s_tx_duty_cycle = ir_spi_set_duty_cycle;
idata->rc->device_name = "IR SPI";
idata->rc->driver_name = IR_SPI_DRIVER_NAME;
idata->rc->priv = idata;
idata->spi = spi;
idata->negated = of_property_read_bool(spi->dev.of_node,
"led-active-low");
ret = of_property_read_u8(spi->dev.of_node, "duty-cycle", &dc);
if (ret)
dc = 50;
ir_spi_set_duty_cycle(idata->rc, dc);
idata->freq = IR_SPI_DEFAULT_FREQUENCY;
return devm_rc_register_device(&spi->dev, idata->rc);
}
static int ir_spi_remove(struct spi_device *spi)
{
return 0;
}
