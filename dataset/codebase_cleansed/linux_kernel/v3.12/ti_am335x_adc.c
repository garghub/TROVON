static unsigned int tiadc_readl(struct tiadc_device *adc, unsigned int reg)
{
return readl(adc->mfd_tscadc->tscadc_base + reg);
}
static void tiadc_writel(struct tiadc_device *adc, unsigned int reg,
unsigned int val)
{
writel(val, adc->mfd_tscadc->tscadc_base + reg);
}
static u32 get_adc_step_mask(struct tiadc_device *adc_dev)
{
u32 step_en;
step_en = ((1 << adc_dev->channels) - 1);
step_en <<= TOTAL_STEPS - adc_dev->channels + 1;
return step_en;
}
static void tiadc_step_config(struct tiadc_device *adc_dev)
{
unsigned int stepconfig;
int i, steps;
steps = TOTAL_STEPS - adc_dev->channels;
stepconfig = STEPCONFIG_AVG_16 | STEPCONFIG_FIFO1;
for (i = 0; i < adc_dev->channels; i++) {
int chan;
chan = adc_dev->channel_line[i];
tiadc_writel(adc_dev, REG_STEPCONFIG(steps),
stepconfig | STEPCONFIG_INP(chan));
tiadc_writel(adc_dev, REG_STEPDELAY(steps),
STEPCONFIG_OPENDLY);
adc_dev->channel_step[i] = steps;
steps++;
}
}
static int tiadc_channel_init(struct iio_dev *indio_dev, int channels)
{
struct tiadc_device *adc_dev = iio_priv(indio_dev);
struct iio_chan_spec *chan_array;
struct iio_chan_spec *chan;
int i;
indio_dev->num_channels = channels;
chan_array = kcalloc(channels,
sizeof(struct iio_chan_spec), GFP_KERNEL);
if (chan_array == NULL)
return -ENOMEM;
chan = chan_array;
for (i = 0; i < channels; i++, chan++) {
chan->type = IIO_VOLTAGE;
chan->indexed = 1;
chan->channel = adc_dev->channel_line[i];
chan->info_mask_separate = BIT(IIO_CHAN_INFO_RAW);
chan->datasheet_name = chan_name_ain[chan->channel];
chan->scan_type.sign = 'u';
chan->scan_type.realbits = 12;
chan->scan_type.storagebits = 32;
}
indio_dev->channels = chan_array;
return 0;
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
int i, map_val;
unsigned int fifo1count, read, stepid;
u32 step = UINT_MAX;
bool found = false;
u32 step_en;
unsigned long timeout = jiffies + usecs_to_jiffies
(IDLE_TIMEOUT * adc_dev->channels);
step_en = get_adc_step_mask(adc_dev);
am335x_tsc_se_set(adc_dev->mfd_tscadc, step_en);
while (tiadc_readl(adc_dev, REG_ADCFSM) & SEQ_STATUS) {
if (time_after(jiffies, timeout))
return -EAGAIN;
}
map_val = chan->channel + TOTAL_CHANNELS;
for (i = 0; i < ARRAY_SIZE(adc_dev->channel_step); i++) {
if (chan->channel == adc_dev->channel_line[i]) {
step = adc_dev->channel_step[i];
break;
}
}
if (WARN_ON_ONCE(step == UINT_MAX))
return -EINVAL;
fifo1count = tiadc_readl(adc_dev, REG_FIFO1CNT);
for (i = 0; i < fifo1count; i++) {
read = tiadc_readl(adc_dev, REG_FIFO1);
stepid = read & FIFOREAD_CHNLID_MASK;
stepid = stepid >> 0x10;
if (stepid == map_val) {
read = read & FIFOREAD_DATA_MASK;
found = true;
*val = read;
}
}
if (found == false)
return -EBUSY;
return IIO_VAL_INT;
}
static int tiadc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct tiadc_device *adc_dev;
struct device_node *node = pdev->dev.of_node;
struct property *prop;
const __be32 *cur;
int err;
u32 val;
int channels = 0;
if (!node) {
dev_err(&pdev->dev, "Could not find valid DT data.\n");
return -EINVAL;
}
indio_dev = devm_iio_device_alloc(&pdev->dev,
sizeof(struct tiadc_device));
if (indio_dev == NULL) {
dev_err(&pdev->dev, "failed to allocate iio device\n");
return -ENOMEM;
}
adc_dev = iio_priv(indio_dev);
adc_dev->mfd_tscadc = ti_tscadc_dev_get(pdev);
of_property_for_each_u32(node, "ti,adc-channels", prop, cur, val) {
adc_dev->channel_line[channels] = val;
channels++;
}
adc_dev->channels = channels;
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = dev_name(&pdev->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &tiadc_info;
tiadc_step_config(adc_dev);
err = tiadc_channel_init(indio_dev, adc_dev->channels);
if (err < 0)
return err;
err = iio_device_register(indio_dev);
if (err)
goto err_free_channels;
platform_set_drvdata(pdev, indio_dev);
return 0;
err_free_channels:
tiadc_channels_remove(indio_dev);
return err;
}
static int tiadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct tiadc_device *adc_dev = iio_priv(indio_dev);
u32 step_en;
iio_device_unregister(indio_dev);
tiadc_channels_remove(indio_dev);
step_en = get_adc_step_mask(adc_dev);
am335x_tsc_se_clr(adc_dev->mfd_tscadc, step_en);
return 0;
}
static int tiadc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct tiadc_device *adc_dev = iio_priv(indio_dev);
struct ti_tscadc_dev *tscadc_dev;
unsigned int idle;
tscadc_dev = ti_tscadc_dev_get(to_platform_device(dev));
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
