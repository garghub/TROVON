static int tsc2007_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct tsc2007_iio *iio = iio_priv(indio_dev);
struct tsc2007 *tsc = iio->ts;
int adc_chan = chan->channel;
int ret = 0;
if (adc_chan >= ARRAY_SIZE(tsc2007_iio_channel))
return -EINVAL;
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
mutex_lock(&tsc->mlock);
switch (chan->channel) {
case 0:
*val = tsc2007_xfer(tsc, READ_X);
break;
case 1:
*val = tsc2007_xfer(tsc, READ_Y);
break;
case 2:
*val = tsc2007_xfer(tsc, READ_Z1);
break;
case 3:
*val = tsc2007_xfer(tsc, READ_Z2);
break;
case 4:
*val = tsc2007_xfer(tsc, (ADC_ON_12BIT | TSC2007_MEASURE_AUX));
break;
case 5: {
struct ts_event tc;
tc.x = tsc2007_xfer(tsc, READ_X);
tc.z1 = tsc2007_xfer(tsc, READ_Z1);
tc.z2 = tsc2007_xfer(tsc, READ_Z2);
*val = tsc2007_calculate_resistance(tsc, &tc);
break;
}
case 6:
*val = tsc2007_is_pen_down(tsc);
break;
case 7:
*val = tsc2007_xfer(tsc,
(ADC_ON_12BIT | TSC2007_MEASURE_TEMP0));
break;
case 8:
*val = tsc2007_xfer(tsc,
(ADC_ON_12BIT | TSC2007_MEASURE_TEMP1));
break;
}
tsc2007_xfer(tsc, PWRDOWN);
mutex_unlock(&tsc->mlock);
ret = IIO_VAL_INT;
return ret;
}
int tsc2007_iio_configure(struct tsc2007 *ts)
{
struct iio_dev *indio_dev;
struct tsc2007_iio *iio;
int error;
indio_dev = devm_iio_device_alloc(&ts->client->dev, sizeof(*iio));
if (!indio_dev) {
dev_err(&ts->client->dev, "iio_device_alloc failed\n");
return -ENOMEM;
}
iio = iio_priv(indio_dev);
iio->ts = ts;
indio_dev->name = "tsc2007";
indio_dev->dev.parent = &ts->client->dev;
indio_dev->info = &tsc2007_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = tsc2007_iio_channel;
indio_dev->num_channels = ARRAY_SIZE(tsc2007_iio_channel);
error = devm_iio_device_register(&ts->client->dev, indio_dev);
if (error) {
dev_err(&ts->client->dev,
"iio_device_register() failed: %d\n", error);
return error;
}
return 0;
}
