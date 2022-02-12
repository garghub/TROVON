static int at91_adc_configure_trigger(struct iio_trigger *trig, bool state)
{
struct iio_dev *indio = iio_trigger_get_drvdata(trig);
struct at91_adc_state *st = iio_priv(indio);
u32 status = at91_adc_readl(st, AT91_SAMA5D2_TRGR);
u8 bit;
status &= ~AT91_SAMA5D2_TRGR_TRGMOD_MASK;
if (state)
status |= st->selected_trig->trgmod_value;
at91_adc_writel(st, AT91_SAMA5D2_TRGR, status);
for_each_set_bit(bit, indio->active_scan_mask, indio->num_channels) {
struct iio_chan_spec const *chan = indio->channels + bit;
if (state) {
at91_adc_writel(st, AT91_SAMA5D2_CHER,
BIT(chan->channel));
at91_adc_writel(st, AT91_SAMA5D2_IER,
BIT(chan->channel));
} else {
at91_adc_writel(st, AT91_SAMA5D2_IDR,
BIT(chan->channel));
at91_adc_writel(st, AT91_SAMA5D2_CHDR,
BIT(chan->channel));
}
}
return 0;
}
static int at91_adc_reenable_trigger(struct iio_trigger *trig)
{
struct iio_dev *indio = iio_trigger_get_drvdata(trig);
struct at91_adc_state *st = iio_priv(indio);
enable_irq(st->irq);
at91_adc_readl(st, AT91_SAMA5D2_LCDR);
return 0;
}
static struct iio_trigger *at91_adc_allocate_trigger(struct iio_dev *indio,
char *trigger_name)
{
struct iio_trigger *trig;
int ret;
trig = devm_iio_trigger_alloc(&indio->dev, "%s-dev%d-%s", indio->name,
indio->id, trigger_name);
if (!trig)
return NULL;
trig->dev.parent = indio->dev.parent;
iio_trigger_set_drvdata(trig, indio);
trig->ops = &at91_adc_trigger_ops;
ret = devm_iio_trigger_register(&indio->dev, trig);
if (ret)
return ERR_PTR(ret);
return trig;
}
static int at91_adc_trigger_init(struct iio_dev *indio)
{
struct at91_adc_state *st = iio_priv(indio);
st->trig = at91_adc_allocate_trigger(indio, st->selected_trig->name);
if (IS_ERR(st->trig)) {
dev_err(&indio->dev,
"could not allocate trigger\n");
return PTR_ERR(st->trig);
}
return 0;
}
static irqreturn_t at91_adc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio = pf->indio_dev;
struct at91_adc_state *st = iio_priv(indio);
int i = 0;
u8 bit;
for_each_set_bit(bit, indio->active_scan_mask, indio->num_channels) {
struct iio_chan_spec const *chan = indio->channels + bit;
st->buffer[i] = at91_adc_readl(st, chan->address);
i++;
}
iio_push_to_buffers_with_timestamp(indio, st->buffer, pf->timestamp);
iio_trigger_notify_done(indio->trig);
return IRQ_HANDLED;
}
static int at91_adc_buffer_init(struct iio_dev *indio)
{
return devm_iio_triggered_buffer_setup(&indio->dev, indio,
&iio_pollfunc_store_time,
&at91_adc_trigger_handler, NULL);
}
static unsigned at91_adc_startup_time(unsigned startup_time_min,
unsigned adc_clk_khz)
{
static const unsigned int startup_lookup[] = {
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
unsigned f_per, prescal, startup, mr;
f_per = clk_get_rate(st->per_clk);
prescal = (f_per / (2 * freq)) - 1;
startup = at91_adc_startup_time(st->soc_info.startup_time,
freq / 1000);
mr = at91_adc_readl(st, AT91_SAMA5D2_MR);
mr &= ~(AT91_SAMA5D2_MR_STARTUP_MASK | AT91_SAMA5D2_MR_PRESCAL_MASK);
mr |= AT91_SAMA5D2_MR_STARTUP(startup);
mr |= AT91_SAMA5D2_MR_PRESCAL(prescal);
at91_adc_writel(st, AT91_SAMA5D2_MR, mr);
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
if (!(status & imr))
return IRQ_NONE;
if (iio_buffer_enabled(indio)) {
disable_irq_nosync(irq);
iio_trigger_poll(indio->trig);
} else {
st->conversion_value = at91_adc_readl(st, st->chan->address);
st->conversion_done = true;
wake_up_interruptible(&st->wq_data_available);
}
return IRQ_HANDLED;
}
static int at91_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct at91_adc_state *st = iio_priv(indio_dev);
u32 cor = 0;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
mutex_lock(&st->lock);
st->chan = chan;
if (chan->differential)
cor = (BIT(chan->channel) | BIT(chan->channel2)) <<
AT91_SAMA5D2_COR_DIFF_OFFSET;
at91_adc_writel(st, AT91_SAMA5D2_COR, cor);
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
if (chan->scan_type.sign == 's')
*val = sign_extend32(*val, 11);
ret = IIO_VAL_INT;
st->conversion_done = false;
}
at91_adc_writel(st, AT91_SAMA5D2_IDR, BIT(chan->channel));
at91_adc_writel(st, AT91_SAMA5D2_CHDR, BIT(chan->channel));
mutex_unlock(&st->lock);
iio_device_release_direct_mode(indio_dev);
return ret;
case IIO_CHAN_INFO_SCALE:
*val = st->vref_uv / 1000;
if (chan->differential)
*val *= 2;
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
static void at91_adc_hw_init(struct at91_adc_state *st)
{
at91_adc_writel(st, AT91_SAMA5D2_CR, AT91_SAMA5D2_CR_SWRST);
at91_adc_writel(st, AT91_SAMA5D2_IDR, 0xffffffff);
at91_adc_writel(st, AT91_SAMA5D2_MR,
AT91_SAMA5D2_MR_TRANSFER(2) | AT91_SAMA5D2_MR_ANACH);
at91_adc_setup_samp_freq(st, st->soc_info.min_sample_rate);
}
static int at91_adc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct at91_adc_state *st;
struct resource *res;
int ret, i;
u32 edge_type = IRQ_TYPE_NONE;
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
ret = of_property_read_u32(pdev->dev.of_node,
"atmel,trigger-edge-type", &edge_type);
if (ret) {
dev_dbg(&pdev->dev,
"atmel,trigger-edge-type not specified, only software trigger available\n");
}
st->selected_trig = NULL;
for (i = 0; i < AT91_SAMA5D2_HW_TRIG_CNT + 1; i++)
if (at91_adc_trigger_list[i].edge_type == edge_type) {
st->selected_trig = &at91_adc_trigger_list[i];
break;
}
if (!st->selected_trig) {
dev_err(&pdev->dev, "invalid external trigger edge value\n");
return -EINVAL;
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
at91_adc_hw_init(st);
ret = clk_prepare_enable(st->per_clk);
if (ret)
goto vref_disable;
platform_set_drvdata(pdev, indio_dev);
if (st->selected_trig->hw_trig) {
ret = at91_adc_buffer_init(indio_dev);
if (ret < 0) {
dev_err(&pdev->dev, "couldn't initialize the buffer.\n");
goto per_clk_disable_unprepare;
}
ret = at91_adc_trigger_init(indio_dev);
if (ret < 0) {
dev_err(&pdev->dev, "couldn't setup the triggers.\n");
goto per_clk_disable_unprepare;
}
}
ret = iio_device_register(indio_dev);
if (ret < 0)
goto per_clk_disable_unprepare;
if (st->selected_trig->hw_trig)
dev_info(&pdev->dev, "setting up trigger as %s\n",
st->selected_trig->name);
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
static __maybe_unused int at91_adc_suspend(struct device *dev)
{
struct iio_dev *indio_dev =
platform_get_drvdata(to_platform_device(dev));
struct at91_adc_state *st = iio_priv(indio_dev);
at91_adc_writel(st, AT91_SAMA5D2_CR, AT91_SAMA5D2_CR_SWRST);
clk_disable_unprepare(st->per_clk);
regulator_disable(st->vref);
regulator_disable(st->reg);
return pinctrl_pm_select_sleep_state(dev);
}
static __maybe_unused int at91_adc_resume(struct device *dev)
{
struct iio_dev *indio_dev =
platform_get_drvdata(to_platform_device(dev));
struct at91_adc_state *st = iio_priv(indio_dev);
int ret;
ret = pinctrl_pm_select_default_state(dev);
if (ret)
goto resume_failed;
ret = regulator_enable(st->reg);
if (ret)
goto resume_failed;
ret = regulator_enable(st->vref);
if (ret)
goto reg_disable_resume;
ret = clk_prepare_enable(st->per_clk);
if (ret)
goto vref_disable_resume;
at91_adc_hw_init(st);
if (iio_buffer_enabled(indio_dev))
at91_adc_configure_trigger(st->trig, true);
return 0;
vref_disable_resume:
regulator_disable(st->vref);
reg_disable_resume:
regulator_disable(st->reg);
resume_failed:
dev_err(&indio_dev->dev, "failed to resume\n");
return ret;
}
