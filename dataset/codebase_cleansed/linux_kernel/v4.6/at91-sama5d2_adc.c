static unsigned at91_adc_startup_time(unsigned startup_time_min,
unsigned adc_clk_khz)
{
const unsigned startup_lookup[] = {
0, 8, 16, 24,
64, 80, 96, 112,
512, 576, 640, 704,
768, 832, 896, 960
};
unsigned ticks_min, i;
ticks_min = startup_time_min * adc_clk_khz / 1000;
for (i = 0; i < ARRAY_SIZE(startup_lookup); i++)
if (startup_lookup[i] > ticks_min)
break;
return i;
}
static void at91_adc_setup_samp_freq(struct at91_adc_state *st, unsigned freq)
{
struct iio_dev *indio_dev = iio_priv_to_dev(st);
unsigned f_per, prescal, startup;
f_per = clk_get_rate(st->per_clk);
prescal = (f_per / (2 * freq)) - 1;
startup = at91_adc_startup_time(st->soc_info.startup_time,
freq / 1000);
at91_adc_writel(st, AT91_SAMA5D2_MR,
AT91_SAMA5D2_MR_TRANSFER(2)
| AT91_SAMA5D2_MR_STARTUP(startup)
| AT91_SAMA5D2_MR_PRESCAL(prescal));
dev_dbg(&indio_dev->dev, "freq: %u, startup: %u, prescal: %u\n",
freq, startup, prescal);
}
static unsigned at91_adc_get_sample_freq(struct at91_adc_state *st)
{
unsigned f_adc, f_per = clk_get_rate(st->per_clk);
unsigned mr, prescal;
mr = at91_adc_readl(st, AT91_SAMA5D2_MR);
prescal = (mr >> AT91_SAMA5D2_MR_PRESCAL_OFFSET)
& AT91_SAMA5D2_MR_PRESCAL_MAX;
f_adc = f_per / (2 * (prescal + 1));
return f_adc;
}
static irqreturn_t at91_adc_interrupt(int irq, void *private)
{
struct iio_dev *indio = private;
struct at91_adc_state *st = iio_priv(indio);
u32 status = at91_adc_readl(st, AT91_SAMA5D2_ISR);
u32 imr = at91_adc_readl(st, AT91_SAMA5D2_IMR);
if (status & imr) {
st->conversion_value = at91_adc_readl(st, st->chan->address);
st->conversion_done = true;
wake_up_interruptible(&st->wq_data_available);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int at91_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct at91_adc_state *st = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&st->lock);
st->chan = chan;
at91_adc_writel(st, AT91_SAMA5D2_CHER, BIT(chan->channel));
at91_adc_writel(st, AT91_SAMA5D2_IER, BIT(chan->channel));
at91_adc_writel(st, AT91_SAMA5D2_CR, AT91_SAMA5D2_CR_START);
ret = wait_event_interruptible_timeout(st->wq_data_available,
st->conversion_done,
msecs_to_jiffies(1000));
if (ret == 0)
ret = -ETIMEDOUT;
if (ret > 0) {
*val = st->conversion_value;
ret = IIO_VAL_INT;
st->conversion_done = false;
}
at91_adc_writel(st, AT91_SAMA5D2_IDR, BIT(chan->channel));
at91_adc_writel(st, AT91_SAMA5D2_CHDR, BIT(chan->channel));
mutex_unlock(&st->lock);
return ret;
case IIO_CHAN_INFO_SCALE:
*val = st->vref_uv / 1000;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = at91_adc_get_sample_freq(st);
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int at91_adc_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct at91_adc_state *st = iio_priv(indio_dev);
if (mask != IIO_CHAN_INFO_SAMP_FREQ)
return -EINVAL;
if (val < st->soc_info.min_sample_rate ||
val > st->soc_info.max_sample_rate)
return -EINVAL;
at91_adc_setup_samp_freq(st, val);
return 0;
}
static int at91_adc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct at91_adc_state *st;
struct resource *res;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*st));
if (!indio_dev)
return -ENOMEM;
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = dev_name(&pdev->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &at91_adc_info;
indio_dev->channels = at91_adc_channels;
indio_dev->num_channels = ARRAY_SIZE(at91_adc_channels);
st = iio_priv(indio_dev);
ret = of_property_read_u32(pdev->dev.of_node,
"atmel,min-sample-rate-hz",
&st->soc_info.min_sample_rate);
if (ret) {
dev_err(&pdev->dev,
"invalid or missing value for atmel,min-sample-rate-hz\n");
return ret;
}
ret = of_property_read_u32(pdev->dev.of_node,
"atmel,max-sample-rate-hz",
&st->soc_info.max_sample_rate);
if (ret) {
dev_err(&pdev->dev,
"invalid or missing value for atmel,max-sample-rate-hz\n");
return ret;
}
ret = of_property_read_u32(pdev->dev.of_node, "atmel,startup-time-ms",
&st->soc_info.startup_time);
if (ret) {
dev_err(&pdev->dev,
"invalid or missing value for atmel,startup-time-ms\n");
return ret;
}
init_waitqueue_head(&st->wq_data_available);
mutex_init(&st->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
st->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(st->base))
return PTR_ERR(st->base);
st->irq = platform_get_irq(pdev, 0);
if (st->irq <= 0) {
if (!st->irq)
st->irq = -ENXIO;
return st->irq;
}
st->per_clk = devm_clk_get(&pdev->dev, "adc_clk");
if (IS_ERR(st->per_clk))
return PTR_ERR(st->per_clk);
st->reg = devm_regulator_get(&pdev->dev, "vddana");
if (IS_ERR(st->reg))
return PTR_ERR(st->reg);
st->vref = devm_regulator_get(&pdev->dev, "vref");
if (IS_ERR(st->vref))
return PTR_ERR(st->vref);
ret = devm_request_irq(&pdev->dev, st->irq, at91_adc_interrupt, 0,
pdev->dev.driver->name, indio_dev);
if (ret)
return ret;
ret = regulator_enable(st->reg);
if (ret)
return ret;
ret = regulator_enable(st->vref);
if (ret)
goto reg_disable;
st->vref_uv = regulator_get_voltage(st->vref);
if (st->vref_uv <= 0) {
ret = -EINVAL;
goto vref_disable;
}
at91_adc_writel(st, AT91_SAMA5D2_CR, AT91_SAMA5D2_CR_SWRST);
at91_adc_writel(st, AT91_SAMA5D2_IDR, 0xffffffff);
at91_adc_setup_samp_freq(st, st->soc_info.min_sample_rate);
ret = clk_prepare_enable(st->per_clk);
if (ret)
goto vref_disable;
platform_set_drvdata(pdev, indio_dev);
ret = iio_device_register(indio_dev);
if (ret < 0)
goto per_clk_disable_unprepare;
dev_info(&pdev->dev, "version: %x\n",
readl_relaxed(st->base + AT91_SAMA5D2_VERSION));
return 0;
per_clk_disable_unprepare:
clk_disable_unprepare(st->per_clk);
vref_disable:
regulator_disable(st->vref);
reg_disable:
regulator_disable(st->reg);
return ret;
}
static int at91_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct at91_adc_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
clk_disable_unprepare(st->per_clk);
regulator_disable(st->vref);
regulator_disable(st->reg);
return 0;
}
