static unsigned int tiadc_readl(struct tiadc_device *adc, unsigned int reg)
{
return readl(adc->mfd_tscadc->tscadc_base + reg);
}
static void tiadc_writel(struct tiadc_device *adc, unsigned int reg,
unsigned int val)
{
writel(val, adc->mfd_tscadc->tscadc_base + reg);
}
static void tiadc_step_config(struct tiadc_device *adc_dev)
{
unsigned int stepconfig;
int i, channels = 0, steps;
steps = TOTAL_STEPS - adc_dev->channels;
channels = TOTAL_CHANNELS - adc_dev->channels;
stepconfig = STEPCONFIG_AVG_16 | STEPCONFIG_FIFO1;
for (i = (steps + 1); i <= TOTAL_STEPS; i++) {
tiadc_writel(adc_dev, REG_STEPCONFIG(i),
stepconfig | STEPCONFIG_INP(channels));
tiadc_writel(adc_dev, REG_STEPDELAY(i),
STEPCONFIG_OPENDLY);
channels++;
}
tiadc_writel(adc_dev, REG_SE, STPENB_STEPENB);
}
static int tiadc_channel_init(struct iio_dev *indio_dev, int channels)
{
struct iio_chan_spec *chan_array;
int i;
indio_dev->num_channels = channels;
chan_array = kcalloc(indio_dev->num_channels,
sizeof(struct iio_chan_spec), GFP_KERNEL);
if (chan_array == NULL)
return -ENOMEM;
for (i = 0; i < (indio_dev->num_channels); i++) {
struct iio_chan_spec *chan = chan_array + i;
chan->type = IIO_VOLTAGE;
chan->indexed = 1;
chan->channel = i;
chan->info_mask = IIO_CHAN_INFO_RAW_SEPARATE_BIT;
}
indio_dev->channels = chan_array;
return indio_dev->num_channels;
}
static void tiadc_channels_remove(struct iio_dev *indio_dev)
{
kfree(indio_dev->channels);
}
static int tiadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct tiadc_device *adc_dev = iio_priv(indio_dev);
int i;
unsigned int fifo1count, readx1;
fifo1count = tiadc_readl(adc_dev, REG_FIFO1CNT);
for (i = 0; i < fifo1count; i++) {
readx1 = tiadc_readl(adc_dev, REG_FIFO1);
if (i == chan->channel)
*val = readx1 & 0xfff;
}
tiadc_writel(adc_dev, REG_SE, STPENB_STEPENB);
return IIO_VAL_INT;
}
static int tiadc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct tiadc_device *adc_dev;
struct ti_tscadc_dev *tscadc_dev = pdev->dev.platform_data;
struct mfd_tscadc_board *pdata;
int err;
pdata = tscadc_dev->dev->platform_data;
if (!pdata || !pdata->adc_init) {
dev_err(&pdev->dev, "Could not find platform data\n");
return -EINVAL;
}
indio_dev = iio_device_alloc(sizeof(struct tiadc_device));
if (indio_dev == NULL) {
dev_err(&pdev->dev, "failed to allocate iio device\n");
err = -ENOMEM;
goto err_ret;
}
adc_dev = iio_priv(indio_dev);
adc_dev->mfd_tscadc = tscadc_dev;
adc_dev->channels = pdata->adc_init->adc_channels;
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = dev_name(&pdev->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &tiadc_info;
tiadc_step_config(adc_dev);
err = tiadc_channel_init(indio_dev, adc_dev->channels);
if (err < 0)
goto err_free_device;
err = iio_device_register(indio_dev);
if (err)
goto err_free_channels;
platform_set_drvdata(pdev, indio_dev);
return 0;
err_free_channels:
tiadc_channels_remove(indio_dev);
err_free_device:
iio_device_free(indio_dev);
err_ret:
return err;
}
static int tiadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
iio_device_unregister(indio_dev);
tiadc_channels_remove(indio_dev);
iio_device_free(indio_dev);
return 0;
}
static int tiadc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct tiadc_device *adc_dev = iio_priv(indio_dev);
struct ti_tscadc_dev *tscadc_dev = dev->platform_data;
unsigned int idle;
if (!device_may_wakeup(tscadc_dev->dev)) {
idle = tiadc_readl(adc_dev, REG_CTRL);
idle &= ~(CNTRLREG_TSCSSENB);
tiadc_writel(adc_dev, REG_CTRL, (idle |
CNTRLREG_POWERDOWN));
}
return 0;
}
static int tiadc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct tiadc_device *adc_dev = iio_priv(indio_dev);
unsigned int restore;
restore = tiadc_readl(adc_dev, REG_CTRL);
restore &= ~(CNTRLREG_POWERDOWN);
tiadc_writel(adc_dev, REG_CTRL, restore);
tiadc_step_config(adc_dev);
return 0;
}
