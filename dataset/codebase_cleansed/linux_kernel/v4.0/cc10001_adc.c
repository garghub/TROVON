static inline void cc10001_adc_write_reg(struct cc10001_adc_device *adc_dev,
u32 reg, u32 val)
{
writel(val, adc_dev->reg_base + reg);
}
static inline u32 cc10001_adc_read_reg(struct cc10001_adc_device *adc_dev,
u32 reg)
{
return readl(adc_dev->reg_base + reg);
}
static void cc10001_adc_start(struct cc10001_adc_device *adc_dev,
unsigned int channel)
{
u32 val;
val = (channel & CC10001_ADC_CH_MASK) | CC10001_ADC_MODE_SINGLE_CONV;
cc10001_adc_write_reg(adc_dev, CC10001_ADC_CONFIG, val);
val = cc10001_adc_read_reg(adc_dev, CC10001_ADC_CONFIG);
val = val | CC10001_ADC_START_CONV;
cc10001_adc_write_reg(adc_dev, CC10001_ADC_CONFIG, val);
}
static u16 cc10001_adc_poll_done(struct iio_dev *indio_dev,
unsigned int channel,
unsigned int delay)
{
struct cc10001_adc_device *adc_dev = iio_priv(indio_dev);
unsigned int poll_count = 0;
while (!(cc10001_adc_read_reg(adc_dev, CC10001_ADC_EOC) &
CC10001_ADC_EOC_SET)) {
ndelay(delay);
if (poll_count++ == CC10001_MAX_POLL_COUNT)
return CC10001_INVALID_SAMPLED;
}
poll_count = 0;
while ((cc10001_adc_read_reg(adc_dev, CC10001_ADC_CHSEL_SAMPLED) &
CC10001_ADC_CH_MASK) != channel) {
ndelay(delay);
if (poll_count++ == CC10001_MAX_POLL_COUNT)
return CC10001_INVALID_SAMPLED;
}
return cc10001_adc_read_reg(adc_dev, CC10001_ADC_DDATA_OUT) &
CC10001_ADC_DATA_MASK;
}
static irqreturn_t cc10001_adc_trigger_h(int irq, void *p)
{
struct cc10001_adc_device *adc_dev;
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev;
unsigned int delay_ns;
unsigned int channel;
bool sample_invalid;
u16 *data;
int i;
indio_dev = pf->indio_dev;
adc_dev = iio_priv(indio_dev);
data = adc_dev->buf;
mutex_lock(&adc_dev->lock);
cc10001_adc_write_reg(adc_dev, CC10001_ADC_POWER_UP,
CC10001_ADC_POWER_UP_SET);
ndelay(adc_dev->start_delay_ns);
delay_ns = adc_dev->eoc_delay_ns / CC10001_MAX_POLL_COUNT;
i = 0;
sample_invalid = false;
for_each_set_bit(channel, indio_dev->active_scan_mask,
indio_dev->masklength) {
cc10001_adc_start(adc_dev, channel);
data[i] = cc10001_adc_poll_done(indio_dev, channel, delay_ns);
if (data[i] == CC10001_INVALID_SAMPLED) {
dev_warn(&indio_dev->dev,
"invalid sample on channel %d\n", channel);
sample_invalid = true;
goto done;
}
i++;
}
done:
cc10001_adc_write_reg(adc_dev, CC10001_ADC_POWER_UP, 0);
mutex_unlock(&adc_dev->lock);
if (!sample_invalid)
iio_push_to_buffers_with_timestamp(indio_dev, data,
iio_get_time_ns());
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static u16 cc10001_adc_read_raw_voltage(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan)
{
struct cc10001_adc_device *adc_dev = iio_priv(indio_dev);
unsigned int delay_ns;
u16 val;
cc10001_adc_write_reg(adc_dev, CC10001_ADC_POWER_UP,
CC10001_ADC_POWER_UP_SET);
ndelay(adc_dev->start_delay_ns);
delay_ns = adc_dev->eoc_delay_ns / CC10001_MAX_POLL_COUNT;
cc10001_adc_start(adc_dev, chan->channel);
val = cc10001_adc_poll_done(indio_dev, chan->channel, delay_ns);
cc10001_adc_write_reg(adc_dev, CC10001_ADC_POWER_UP, 0);
return val;
}
static int cc10001_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct cc10001_adc_device *adc_dev = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (iio_buffer_enabled(indio_dev))
return -EBUSY;
mutex_lock(&adc_dev->lock);
*val = cc10001_adc_read_raw_voltage(indio_dev, chan);
mutex_unlock(&adc_dev->lock);
if (*val == CC10001_INVALID_SAMPLED)
return -EIO;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(adc_dev->reg);
if (ret)
return ret;
*val = ret / 1000;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static int cc10001_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct cc10001_adc_device *adc_dev = iio_priv(indio_dev);
kfree(adc_dev->buf);
adc_dev->buf = kmalloc(indio_dev->scan_bytes, GFP_KERNEL);
if (!adc_dev->buf)
return -ENOMEM;
return 0;
}
static int cc10001_adc_channel_init(struct iio_dev *indio_dev)
{
struct cc10001_adc_device *adc_dev = iio_priv(indio_dev);
struct iio_chan_spec *chan_array, *timestamp;
unsigned int bit, idx = 0;
indio_dev->num_channels = bitmap_weight(&adc_dev->channel_map,
CC10001_ADC_NUM_CHANNELS);
chan_array = devm_kcalloc(&indio_dev->dev, indio_dev->num_channels + 1,
sizeof(struct iio_chan_spec),
GFP_KERNEL);
if (!chan_array)
return -ENOMEM;
for_each_set_bit(bit, &adc_dev->channel_map, CC10001_ADC_NUM_CHANNELS) {
struct iio_chan_spec *chan = &chan_array[idx];
chan->type = IIO_VOLTAGE;
chan->indexed = 1;
chan->channel = bit;
chan->scan_index = idx;
chan->scan_type.sign = 'u';
chan->scan_type.realbits = 10;
chan->scan_type.storagebits = 16;
chan->info_mask_shared_by_type = BIT(IIO_CHAN_INFO_SCALE);
chan->info_mask_separate = BIT(IIO_CHAN_INFO_RAW);
idx++;
}
timestamp = &chan_array[idx];
timestamp->type = IIO_TIMESTAMP;
timestamp->channel = -1;
timestamp->scan_index = idx;
timestamp->scan_type.sign = 's';
timestamp->scan_type.realbits = 64;
timestamp->scan_type.storagebits = 64;
indio_dev->channels = chan_array;
return 0;
}
static int cc10001_adc_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct cc10001_adc_device *adc_dev;
unsigned long adc_clk_rate;
struct resource *res;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*adc_dev));
if (indio_dev == NULL)
return -ENOMEM;
adc_dev = iio_priv(indio_dev);
adc_dev->channel_map = GENMASK(CC10001_ADC_NUM_CHANNELS - 1, 0);
if (!of_property_read_u32(node, "adc-reserved-channels", &ret))
adc_dev->channel_map &= ~ret;
adc_dev->reg = devm_regulator_get(&pdev->dev, "vref");
if (IS_ERR(adc_dev->reg))
return PTR_ERR(adc_dev->reg);
ret = regulator_enable(adc_dev->reg);
if (ret)
return ret;
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = dev_name(&pdev->dev);
indio_dev->info = &cc10001_adc_info;
indio_dev->modes = INDIO_DIRECT_MODE;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
adc_dev->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(adc_dev->reg_base)) {
ret = PTR_ERR(adc_dev->reg_base);
goto err_disable_reg;
}
adc_dev->adc_clk = devm_clk_get(&pdev->dev, "adc");
if (IS_ERR(adc_dev->adc_clk)) {
dev_err(&pdev->dev, "failed to get the clock\n");
ret = PTR_ERR(adc_dev->adc_clk);
goto err_disable_reg;
}
ret = clk_prepare_enable(adc_dev->adc_clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable the clock\n");
goto err_disable_reg;
}
adc_clk_rate = clk_get_rate(adc_dev->adc_clk);
if (!adc_clk_rate) {
ret = -EINVAL;
dev_err(&pdev->dev, "null clock rate!\n");
goto err_disable_clk;
}
adc_dev->eoc_delay_ns = NSEC_PER_SEC / adc_clk_rate;
adc_dev->start_delay_ns = adc_dev->eoc_delay_ns * CC10001_WAIT_CYCLES;
ret = cc10001_adc_channel_init(indio_dev);
if (ret < 0)
goto err_disable_clk;
mutex_init(&adc_dev->lock);
ret = iio_triggered_buffer_setup(indio_dev, NULL,
&cc10001_adc_trigger_h, NULL);
if (ret < 0)
goto err_disable_clk;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto err_cleanup_buffer;
platform_set_drvdata(pdev, indio_dev);
return 0;
err_cleanup_buffer:
iio_triggered_buffer_cleanup(indio_dev);
err_disable_clk:
clk_disable_unprepare(adc_dev->adc_clk);
err_disable_reg:
regulator_disable(adc_dev->reg);
return ret;
}
static int cc10001_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct cc10001_adc_device *adc_dev = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
clk_disable_unprepare(adc_dev->adc_clk);
regulator_disable(adc_dev->reg);
return 0;
}
