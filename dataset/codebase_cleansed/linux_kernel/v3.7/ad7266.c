static int ad7266_wakeup(struct ad7266_state *st)
{
return spi_read(st->spi, st->data, 2);
}
static int ad7266_powerdown(struct ad7266_state *st)
{
return spi_read(st->spi, st->data, 1);
}
static int ad7266_preenable(struct iio_dev *indio_dev)
{
struct ad7266_state *st = iio_priv(indio_dev);
int ret;
ret = ad7266_wakeup(st);
if (ret)
return ret;
ret = iio_sw_buffer_preenable(indio_dev);
if (ret)
ad7266_powerdown(st);
return ret;
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
struct iio_buffer *buffer = indio_dev->buffer;
struct ad7266_state *st = iio_priv(indio_dev);
int ret;
ret = spi_read(st->spi, st->data, 4);
if (ret == 0) {
if (indio_dev->scan_timestamp)
((s64 *)st->data)[1] = pf->timestamp;
iio_push_to_buffer(buffer, (u8 *)st->data);
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
*val = be16_to_cpu(st->data[address % 2]);
return ret;
}
static int ad7266_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2, long m)
{
struct ad7266_state *st = iio_priv(indio_dev);
unsigned long scale_uv;
int ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
ret = ad7266_read_single(st, val, chan->address);
if (ret)
return ret;
*val = (*val >> 2) & 0xfff;
if (chan->scan_type.sign == 's')
*val = sign_extend32(*val, 11);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
scale_uv = (st->vref_uv * 100);
if (st->mode == AD7266_MODE_DIFF)
scale_uv *= 2;
if (st->range == AD7266_RANGE_2VREF)
scale_uv *= 2;
scale_uv >>= chan->scan_type.realbits;
*val = scale_uv / 100000;
*val2 = (scale_uv % 100000) * 10;
return IIO_VAL_INT_PLUS_MICRO;
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
static void __devinit ad7266_init_channels(struct iio_dev *indio_dev)
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
static int __devinit ad7266_probe(struct spi_device *spi)
{
struct ad7266_platform_data *pdata = spi->dev.platform_data;
struct iio_dev *indio_dev;
struct ad7266_state *st;
unsigned int i;
int ret;
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = regulator_get(&spi->dev, "vref");
if (!IS_ERR_OR_NULL(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
st->vref_uv = regulator_get_voltage(st->reg);
} else {
st->vref_uv = 2500000;
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
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &ad7266_info;
ad7266_init_channels(indio_dev);
st->single_xfer[0].rx_buf = &st->data;
st->single_xfer[0].len = 2;
st->single_xfer[0].cs_change = 1;
st->single_xfer[1].rx_buf = &st->data;
st->single_xfer[1].len = 4;
st->single_xfer[1].cs_change = 1;
st->single_xfer[2].tx_buf = &st->data;
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
error_put_reg:
if (!IS_ERR_OR_NULL(st->reg))
regulator_put(st->reg);
iio_device_free(indio_dev);
return ret;
}
static int __devexit ad7266_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad7266_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (!st->fixed_addr)
gpio_free_array(st->gpios, ARRAY_SIZE(st->gpios));
if (!IS_ERR_OR_NULL(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_free(indio_dev);
return 0;
}
