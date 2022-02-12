static int ad7266_wakeup(struct ad7266_state *st)
{
return spi_read(st->spi, &st->data.sample[0], 2);
}
static int ad7266_powerdown(struct ad7266_state *st)
{
return spi_read(st->spi, &st->data.sample[0], 1);
}
static int ad7266_preenable(struct iio_dev *indio_dev)
{
struct ad7266_state *st = iio_priv(indio_dev);
return ad7266_wakeup(st);
}
static int ad7266_postdisable(struct iio_dev *indio_dev)
{
struct ad7266_state *st = iio_priv(indio_dev);
return ad7266_powerdown(st);
}
static irqreturn_t ad7266_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct ad7266_state *st = iio_priv(indio_dev);
int ret;
ret = spi_read(st->spi, st->data.sample, 4);
if (ret == 0) {
iio_push_to_buffers_with_timestamp(indio_dev, &st->data,
pf->timestamp);
}
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static void ad7266_select_input(struct ad7266_state *st, unsigned int nr)
{
unsigned int i;
if (st->fixed_addr)
return;
switch (st->mode) {
case AD7266_MODE_SINGLE_ENDED:
nr >>= 1;
break;
case AD7266_MODE_PSEUDO_DIFF:
nr |= 1;
break;
case AD7266_MODE_DIFF:
nr &= ~1;
break;
}
for (i = 0; i < 3; ++i)
gpio_set_value(st->gpios[i].gpio, (bool)(nr & BIT(i)));
}
static int ad7266_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct ad7266_state *st = iio_priv(indio_dev);
unsigned int nr = find_first_bit(scan_mask, indio_dev->masklength);
ad7266_select_input(st, nr);
return 0;
}
static int ad7266_read_single(struct ad7266_state *st, int *val,
unsigned int address)
{
int ret;
ad7266_select_input(st, address);
ret = spi_sync(st->spi, &st->single_msg);
*val = be16_to_cpu(st->data.sample[address % 2]);
return ret;
}
static int ad7266_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long m)
{
struct ad7266_state *st = iio_priv(indio_dev);
unsigned long scale_mv;
int ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = ad7266_read_single(st, val, chan->address);
iio_device_release_direct_mode(indio_dev);
*val = (*val >> 2) & 0xfff;
if (chan->scan_type.sign == 's')
*val = sign_extend32(*val, 11);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
scale_mv = st->vref_mv;
if (st->mode == AD7266_MODE_DIFF)
scale_mv *= 2;
if (st->range == AD7266_RANGE_2VREF)
scale_mv *= 2;
*val = scale_mv;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_OFFSET:
if (st->range == AD7266_RANGE_2VREF &&
st->mode != AD7266_MODE_DIFF)
*val = 2048;
else
*val = 0;
return IIO_VAL_INT;
}
return -EINVAL;
}
static void ad7266_init_channels(struct iio_dev *indio_dev)
{
struct ad7266_state *st = iio_priv(indio_dev);
bool is_differential, is_signed;
const struct ad7266_chan_info *chan_info;
int i;
is_differential = st->mode != AD7266_MODE_SINGLE_ENDED;
is_signed = (st->range == AD7266_RANGE_2VREF) |
(st->mode == AD7266_MODE_DIFF);
i = AD7266_CHAN_INFO_INDEX(is_differential, is_signed, st->fixed_addr);
chan_info = &ad7266_chan_infos[i];
indio_dev->channels = chan_info->channels;
indio_dev->num_channels = chan_info->num_channels;
indio_dev->available_scan_masks = chan_info->scan_masks;
indio_dev->masklength = chan_info->num_channels - 1;
}
static int ad7266_probe(struct spi_device *spi)
{
struct ad7266_platform_data *pdata = spi->dev.platform_data;
struct iio_dev *indio_dev;
struct ad7266_state *st;
unsigned int i;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = devm_regulator_get_optional(&spi->dev, "vref");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
return ret;
ret = regulator_get_voltage(st->reg);
if (ret < 0)
goto error_disable_reg;
st->vref_mv = ret / 1000;
} else {
if (PTR_ERR(st->reg) != -ENODEV)
return PTR_ERR(st->reg);
st->vref_mv = 2500;
}
if (pdata) {
st->fixed_addr = pdata->fixed_addr;
st->mode = pdata->mode;
st->range = pdata->range;
if (!st->fixed_addr) {
for (i = 0; i < ARRAY_SIZE(st->gpios); ++i) {
st->gpios[i].gpio = pdata->addr_gpios[i];
st->gpios[i].flags = GPIOF_OUT_INIT_LOW;
st->gpios[i].label = ad7266_gpio_labels[i];
}
ret = gpio_request_array(st->gpios,
ARRAY_SIZE(st->gpios));
if (ret)
goto error_disable_reg;
}
} else {
st->fixed_addr = true;
st->range = AD7266_RANGE_VREF;
st->mode = AD7266_MODE_DIFF;
}
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
indio_dev->dev.parent = &spi->dev;
indio_dev->dev.of_node = spi->dev.of_node;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &ad7266_info;
ad7266_init_channels(indio_dev);
st->single_xfer[0].rx_buf = &st->data.sample[0];
st->single_xfer[0].len = 2;
st->single_xfer[0].cs_change = 1;
st->single_xfer[1].rx_buf = st->data.sample;
st->single_xfer[1].len = 4;
st->single_xfer[1].cs_change = 1;
st->single_xfer[2].tx_buf = &st->data.sample[0];
st->single_xfer[2].len = 1;
spi_message_init(&st->single_msg);
spi_message_add_tail(&st->single_xfer[0], &st->single_msg);
spi_message_add_tail(&st->single_xfer[1], &st->single_msg);
spi_message_add_tail(&st->single_xfer[2], &st->single_msg);
ret = iio_triggered_buffer_setup(indio_dev, &iio_pollfunc_store_time,
&ad7266_trigger_handler, &iio_triggered_buffer_setup_ops);
if (ret)
goto error_free_gpios;
ret = iio_device_register(indio_dev);
if (ret)
goto error_buffer_cleanup;
return 0;
error_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
error_free_gpios:
if (!st->fixed_addr)
gpio_free_array(st->gpios, ARRAY_SIZE(st->gpios));
error_disable_reg:
if (!IS_ERR_OR_NULL(st->reg))
regulator_disable(st->reg);
return ret;
}
static int ad7266_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7266_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (!st->fixed_addr)
gpio_free_array(st->gpios, ARRAY_SIZE(st->gpios));
if (!IS_ERR_OR_NULL(st->reg))
regulator_disable(st->reg);
return 0;
}
