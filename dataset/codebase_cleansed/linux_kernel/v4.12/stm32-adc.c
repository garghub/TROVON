static u32 stm32_adc_readl(struct stm32_adc *adc, u32 reg)
{
return readl_relaxed(adc->common->base + adc->offset + reg);
}
static u16 stm32_adc_readw(struct stm32_adc *adc, u32 reg)
{
return readw_relaxed(adc->common->base + adc->offset + reg);
}
static void stm32_adc_writel(struct stm32_adc *adc, u32 reg, u32 val)
{
writel_relaxed(val, adc->common->base + adc->offset + reg);
}
static void stm32_adc_set_bits(struct stm32_adc *adc, u32 reg, u32 bits)
{
unsigned long flags;
spin_lock_irqsave(&adc->lock, flags);
stm32_adc_writel(adc, reg, stm32_adc_readl(adc, reg) | bits);
spin_unlock_irqrestore(&adc->lock, flags);
}
static void stm32_adc_clr_bits(struct stm32_adc *adc, u32 reg, u32 bits)
{
unsigned long flags;
spin_lock_irqsave(&adc->lock, flags);
stm32_adc_writel(adc, reg, stm32_adc_readl(adc, reg) & ~bits);
spin_unlock_irqrestore(&adc->lock, flags);
}
static void stm32_adc_conv_irq_enable(struct stm32_adc *adc)
{
stm32_adc_set_bits(adc, STM32F4_ADC_CR1, STM32F4_EOCIE);
}
static void stm32_adc_conv_irq_disable(struct stm32_adc *adc)
{
stm32_adc_clr_bits(adc, STM32F4_ADC_CR1, STM32F4_EOCIE);
}
static void stm32_adc_set_res(struct stm32_adc *adc)
{
u32 val = stm32_adc_readl(adc, STM32F4_ADC_CR1);
val = (val & ~STM32F4_RES_MASK) | (adc->res << STM32F4_RES_SHIFT);
stm32_adc_writel(adc, STM32F4_ADC_CR1, val);
}
static void stm32_adc_start_conv(struct stm32_adc *adc, bool dma)
{
stm32_adc_set_bits(adc, STM32F4_ADC_CR1, STM32F4_SCAN);
if (dma)
stm32_adc_set_bits(adc, STM32F4_ADC_CR2,
STM32F4_DMA | STM32F4_DDS);
stm32_adc_set_bits(adc, STM32F4_ADC_CR2, STM32F4_EOCS | STM32F4_ADON);
usleep_range(2, 3);
if (!(stm32_adc_readl(adc, STM32F4_ADC_CR2) & STM32F4_EXTEN_MASK))
stm32_adc_set_bits(adc, STM32F4_ADC_CR2, STM32F4_SWSTART);
}
static void stm32_adc_stop_conv(struct stm32_adc *adc)
{
stm32_adc_clr_bits(adc, STM32F4_ADC_CR2, STM32F4_EXTEN_MASK);
stm32_adc_clr_bits(adc, STM32F4_ADC_SR, STM32F4_STRT);
stm32_adc_clr_bits(adc, STM32F4_ADC_CR1, STM32F4_SCAN);
stm32_adc_clr_bits(adc, STM32F4_ADC_CR2,
STM32F4_ADON | STM32F4_DMA | STM32F4_DDS);
}
static int stm32_adc_conf_scan_seq(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct stm32_adc *adc = iio_priv(indio_dev);
const struct iio_chan_spec *chan;
u32 val, bit;
int i = 0;
for_each_set_bit(bit, scan_mask, indio_dev->masklength) {
chan = indio_dev->channels + bit;
i++;
if (i > STM32_ADC_MAX_SQ)
return -EINVAL;
dev_dbg(&indio_dev->dev, "%s chan %d to SQ%d\n",
__func__, chan->channel, i);
val = stm32_adc_readl(adc, stm32f4_sq[i].reg);
val &= ~stm32f4_sq[i].mask;
val |= chan->channel << stm32f4_sq[i].shift;
stm32_adc_writel(adc, stm32f4_sq[i].reg, val);
}
if (!i)
return -EINVAL;
val = stm32_adc_readl(adc, stm32f4_sq[0].reg);
val &= ~stm32f4_sq[0].mask;
val |= ((i - 1) << stm32f4_sq[0].shift);
stm32_adc_writel(adc, stm32f4_sq[0].reg, val);
return 0;
}
static int stm32_adc_get_trig_extsel(struct iio_trigger *trig)
{
int i;
for (i = 0; stm32f4_adc_trigs[i].name; i++) {
if (is_stm32_timer_trigger(trig) &&
!strcmp(stm32f4_adc_trigs[i].name, trig->name)) {
return stm32f4_adc_trigs[i].extsel;
}
}
return -EINVAL;
}
static int stm32_adc_set_trig(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
struct stm32_adc *adc = iio_priv(indio_dev);
u32 val, extsel = 0, exten = STM32_EXTEN_SWTRIG;
unsigned long flags;
int ret;
if (trig) {
ret = stm32_adc_get_trig_extsel(trig);
if (ret < 0)
return ret;
extsel = ret;
exten = adc->trigger_polarity + STM32_EXTEN_HWTRIG_RISING_EDGE;
}
spin_lock_irqsave(&adc->lock, flags);
val = stm32_adc_readl(adc, STM32F4_ADC_CR2);
val &= ~(STM32F4_EXTEN_MASK | STM32F4_EXTSEL_MASK);
val |= exten << STM32F4_EXTEN_SHIFT;
val |= extsel << STM32F4_EXTSEL_SHIFT;
stm32_adc_writel(adc, STM32F4_ADC_CR2, val);
spin_unlock_irqrestore(&adc->lock, flags);
return 0;
}
static int stm32_adc_set_trig_pol(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
unsigned int type)
{
struct stm32_adc *adc = iio_priv(indio_dev);
adc->trigger_polarity = type;
return 0;
}
static int stm32_adc_get_trig_pol(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct stm32_adc *adc = iio_priv(indio_dev);
return adc->trigger_polarity;
}
static int stm32_adc_single_conv(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *res)
{
struct stm32_adc *adc = iio_priv(indio_dev);
long timeout;
u32 val;
int ret;
reinit_completion(&adc->completion);
adc->bufi = 0;
val = stm32_adc_readl(adc, stm32f4_sq[1].reg);
val &= ~stm32f4_sq[1].mask;
val |= chan->channel << stm32f4_sq[1].shift;
stm32_adc_writel(adc, stm32f4_sq[1].reg, val);
stm32_adc_clr_bits(adc, stm32f4_sq[0].reg, stm32f4_sq[0].mask);
stm32_adc_clr_bits(adc, STM32F4_ADC_CR2, STM32F4_EXTEN_MASK);
stm32_adc_conv_irq_enable(adc);
stm32_adc_start_conv(adc, false);
timeout = wait_for_completion_interruptible_timeout(
&adc->completion, STM32_ADC_TIMEOUT);
if (timeout == 0) {
ret = -ETIMEDOUT;
} else if (timeout < 0) {
ret = timeout;
} else {
*res = adc->buffer[0];
ret = IIO_VAL_INT;
}
stm32_adc_stop_conv(adc);
stm32_adc_conv_irq_disable(adc);
return ret;
}
static int stm32_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct stm32_adc *adc = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
if (chan->type == IIO_VOLTAGE)
ret = stm32_adc_single_conv(indio_dev, chan, val);
else
ret = -EINVAL;
iio_device_release_direct_mode(indio_dev);
return ret;
case IIO_CHAN_INFO_SCALE:
*val = adc->common->vref_mv;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static irqreturn_t stm32_adc_isr(int irq, void *data)
{
struct stm32_adc *adc = data;
struct iio_dev *indio_dev = iio_priv_to_dev(adc);
u32 status = stm32_adc_readl(adc, STM32F4_ADC_SR);
if (status & STM32F4_EOC) {
adc->buffer[adc->bufi] = stm32_adc_readw(adc, STM32F4_ADC_DR);
if (iio_buffer_enabled(indio_dev)) {
adc->bufi++;
if (adc->bufi >= adc->num_conv) {
stm32_adc_conv_irq_disable(adc);
iio_trigger_poll(indio_dev->trig);
}
} else {
complete(&adc->completion);
}
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int stm32_adc_validate_trigger(struct iio_dev *indio_dev,
struct iio_trigger *trig)
{
return stm32_adc_get_trig_extsel(trig) < 0 ? -EINVAL : 0;
}
static int stm32_adc_set_watermark(struct iio_dev *indio_dev, unsigned int val)
{
struct stm32_adc *adc = iio_priv(indio_dev);
unsigned int watermark = STM32_DMA_BUFFER_SIZE / 2;
watermark = min(watermark, val * (unsigned)(sizeof(u16)));
adc->rx_buf_sz = watermark * 2;
return 0;
}
static int stm32_adc_update_scan_mode(struct iio_dev *indio_dev,
const unsigned long *scan_mask)
{
struct stm32_adc *adc = iio_priv(indio_dev);
int ret;
adc->num_conv = bitmap_weight(scan_mask, indio_dev->masklength);
ret = stm32_adc_conf_scan_seq(indio_dev, scan_mask);
if (ret)
return ret;
return 0;
}
static int stm32_adc_of_xlate(struct iio_dev *indio_dev,
const struct of_phandle_args *iiospec)
{
int i;
for (i = 0; i < indio_dev->num_channels; i++)
if (indio_dev->channels[i].channel == iiospec->args[0])
return i;
return -EINVAL;
}
static int stm32_adc_debugfs_reg_access(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
struct stm32_adc *adc = iio_priv(indio_dev);
if (!readval)
stm32_adc_writel(adc, reg, writeval);
else
*readval = stm32_adc_readl(adc, reg);
return 0;
}
static unsigned int stm32_adc_dma_residue(struct stm32_adc *adc)
{
struct dma_tx_state state;
enum dma_status status;
status = dmaengine_tx_status(adc->dma_chan,
adc->dma_chan->cookie,
&state);
if (status == DMA_IN_PROGRESS) {
unsigned int i = adc->rx_buf_sz - state.residue;
unsigned int size;
if (i >= adc->bufi)
size = i - adc->bufi;
else
size = adc->rx_buf_sz + i - adc->bufi;
return size;
}
return 0;
}
static void stm32_adc_dma_buffer_done(void *data)
{
struct iio_dev *indio_dev = data;
iio_trigger_poll_chained(indio_dev->trig);
}
static int stm32_adc_dma_start(struct iio_dev *indio_dev)
{
struct stm32_adc *adc = iio_priv(indio_dev);
struct dma_async_tx_descriptor *desc;
dma_cookie_t cookie;
int ret;
if (!adc->dma_chan)
return 0;
dev_dbg(&indio_dev->dev, "%s size=%d watermark=%d\n", __func__,
adc->rx_buf_sz, adc->rx_buf_sz / 2);
desc = dmaengine_prep_dma_cyclic(adc->dma_chan,
adc->rx_dma_buf,
adc->rx_buf_sz, adc->rx_buf_sz / 2,
DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT);
if (!desc)
return -EBUSY;
desc->callback = stm32_adc_dma_buffer_done;
desc->callback_param = indio_dev;
cookie = dmaengine_submit(desc);
ret = dma_submit_error(cookie);
if (ret) {
dmaengine_terminate_all(adc->dma_chan);
return ret;
}
dma_async_issue_pending(adc->dma_chan);
return 0;
}
static int stm32_adc_buffer_postenable(struct iio_dev *indio_dev)
{
struct stm32_adc *adc = iio_priv(indio_dev);
int ret;
ret = stm32_adc_set_trig(indio_dev, indio_dev->trig);
if (ret) {
dev_err(&indio_dev->dev, "Can't set trigger\n");
return ret;
}
ret = stm32_adc_dma_start(indio_dev);
if (ret) {
dev_err(&indio_dev->dev, "Can't start dma\n");
goto err_clr_trig;
}
ret = iio_triggered_buffer_postenable(indio_dev);
if (ret < 0)
goto err_stop_dma;
adc->bufi = 0;
if (!adc->dma_chan)
stm32_adc_conv_irq_enable(adc);
stm32_adc_start_conv(adc, !!adc->dma_chan);
return 0;
err_stop_dma:
if (adc->dma_chan)
dmaengine_terminate_all(adc->dma_chan);
err_clr_trig:
stm32_adc_set_trig(indio_dev, NULL);
return ret;
}
static int stm32_adc_buffer_predisable(struct iio_dev *indio_dev)
{
struct stm32_adc *adc = iio_priv(indio_dev);
int ret;
stm32_adc_stop_conv(adc);
if (!adc->dma_chan)
stm32_adc_conv_irq_disable(adc);
ret = iio_triggered_buffer_predisable(indio_dev);
if (ret < 0)
dev_err(&indio_dev->dev, "predisable failed\n");
if (adc->dma_chan)
dmaengine_terminate_all(adc->dma_chan);
if (stm32_adc_set_trig(indio_dev, NULL))
dev_err(&indio_dev->dev, "Can't clear trigger\n");
return ret;
}
static irqreturn_t stm32_adc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct stm32_adc *adc = iio_priv(indio_dev);
dev_dbg(&indio_dev->dev, "%s bufi=%d\n", __func__, adc->bufi);
if (!adc->dma_chan) {
adc->bufi = 0;
iio_push_to_buffers_with_timestamp(indio_dev, adc->buffer,
pf->timestamp);
} else {
int residue = stm32_adc_dma_residue(adc);
while (residue >= indio_dev->scan_bytes) {
u16 *buffer = (u16 *)&adc->rx_buf[adc->bufi];
iio_push_to_buffers_with_timestamp(indio_dev, buffer,
pf->timestamp);
residue -= indio_dev->scan_bytes;
adc->bufi += indio_dev->scan_bytes;
if (adc->bufi >= adc->rx_buf_sz)
adc->bufi = 0;
}
}
iio_trigger_notify_done(indio_dev->trig);
if (!adc->dma_chan)
stm32_adc_conv_irq_enable(adc);
return IRQ_HANDLED;
}
static int stm32_adc_of_get_resolution(struct iio_dev *indio_dev)
{
struct device_node *node = indio_dev->dev.of_node;
struct stm32_adc *adc = iio_priv(indio_dev);
unsigned int i;
u32 res;
if (of_property_read_u32(node, "assigned-resolution-bits", &res))
res = stm32f4_adc_resolutions[0];
for (i = 0; i < ARRAY_SIZE(stm32f4_adc_resolutions); i++)
if (res == stm32f4_adc_resolutions[i])
break;
if (i >= ARRAY_SIZE(stm32f4_adc_resolutions)) {
dev_err(&indio_dev->dev, "Bad resolution: %u bits\n", res);
return -EINVAL;
}
dev_dbg(&indio_dev->dev, "Using %u bits resolution\n", res);
adc->res = i;
return 0;
}
static void stm32_adc_chan_init_one(struct iio_dev *indio_dev,
struct iio_chan_spec *chan,
const struct stm32_adc_chan_spec *channel,
int scan_index)
{
struct stm32_adc *adc = iio_priv(indio_dev);
chan->type = channel->type;
chan->channel = channel->channel;
chan->datasheet_name = channel->name;
chan->scan_index = scan_index;
chan->indexed = 1;
chan->info_mask_separate = BIT(IIO_CHAN_INFO_RAW);
chan->info_mask_shared_by_type = BIT(IIO_CHAN_INFO_SCALE);
chan->scan_type.sign = 'u';
chan->scan_type.realbits = stm32f4_adc_resolutions[adc->res];
chan->scan_type.storagebits = 16;
chan->ext_info = stm32_adc_ext_info;
}
static int stm32_adc_chan_of_init(struct iio_dev *indio_dev)
{
struct device_node *node = indio_dev->dev.of_node;
struct property *prop;
const __be32 *cur;
struct iio_chan_spec *channels;
int scan_index = 0, num_channels;
u32 val;
num_channels = of_property_count_u32_elems(node, "st,adc-channels");
if (num_channels < 0 ||
num_channels >= ARRAY_SIZE(stm32f4_adc123_channels)) {
dev_err(&indio_dev->dev, "Bad st,adc-channels?\n");
return num_channels < 0 ? num_channels : -EINVAL;
}
channels = devm_kcalloc(&indio_dev->dev, num_channels,
sizeof(struct iio_chan_spec), GFP_KERNEL);
if (!channels)
return -ENOMEM;
of_property_for_each_u32(node, "st,adc-channels", prop, cur, val) {
if (val >= ARRAY_SIZE(stm32f4_adc123_channels)) {
dev_err(&indio_dev->dev, "Invalid channel %d\n", val);
return -EINVAL;
}
stm32_adc_chan_init_one(indio_dev, &channels[scan_index],
&stm32f4_adc123_channels[val],
scan_index);
scan_index++;
}
indio_dev->num_channels = scan_index;
indio_dev->channels = channels;
return 0;
}
static int stm32_adc_dma_request(struct iio_dev *indio_dev)
{
struct stm32_adc *adc = iio_priv(indio_dev);
struct dma_slave_config config;
int ret;
adc->dma_chan = dma_request_slave_channel(&indio_dev->dev, "rx");
if (!adc->dma_chan)
return 0;
adc->rx_buf = dma_alloc_coherent(adc->dma_chan->device->dev,
STM32_DMA_BUFFER_SIZE,
&adc->rx_dma_buf, GFP_KERNEL);
if (!adc->rx_buf) {
ret = -ENOMEM;
goto err_release;
}
memset(&config, 0, sizeof(config));
config.src_addr = (dma_addr_t)adc->common->phys_base;
config.src_addr += adc->offset + STM32F4_ADC_DR;
config.src_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
ret = dmaengine_slave_config(adc->dma_chan, &config);
if (ret)
goto err_free;
return 0;
err_free:
dma_free_coherent(adc->dma_chan->device->dev, STM32_DMA_BUFFER_SIZE,
adc->rx_buf, adc->rx_dma_buf);
err_release:
dma_release_channel(adc->dma_chan);
return ret;
}
static int stm32_adc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct stm32_adc *adc;
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->common = dev_get_drvdata(pdev->dev.parent);
spin_lock_init(&adc->lock);
init_completion(&adc->completion);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &stm32_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
platform_set_drvdata(pdev, adc);
ret = of_property_read_u32(pdev->dev.of_node, "reg", &adc->offset);
if (ret != 0) {
dev_err(&pdev->dev, "missing reg property\n");
return -EINVAL;
}
adc->irq = platform_get_irq(pdev, 0);
if (adc->irq < 0) {
dev_err(&pdev->dev, "failed to get irq\n");
return adc->irq;
}
ret = devm_request_irq(&pdev->dev, adc->irq, stm32_adc_isr,
0, pdev->name, adc);
if (ret) {
dev_err(&pdev->dev, "failed to request IRQ\n");
return ret;
}
adc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(adc->clk)) {
dev_err(&pdev->dev, "Can't get clock\n");
return PTR_ERR(adc->clk);
}
ret = clk_prepare_enable(adc->clk);
if (ret < 0) {
dev_err(&pdev->dev, "clk enable failed\n");
return ret;
}
ret = stm32_adc_of_get_resolution(indio_dev);
if (ret < 0)
goto err_clk_disable;
stm32_adc_set_res(adc);
ret = stm32_adc_chan_of_init(indio_dev);
if (ret < 0)
goto err_clk_disable;
ret = stm32_adc_dma_request(indio_dev);
if (ret < 0)
goto err_clk_disable;
ret = iio_triggered_buffer_setup(indio_dev,
&iio_pollfunc_store_time,
&stm32_adc_trigger_handler,
&stm32_adc_buffer_setup_ops);
if (ret) {
dev_err(&pdev->dev, "buffer setup failed\n");
goto err_dma_disable;
}
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "iio dev register failed\n");
goto err_buffer_cleanup;
}
return 0;
err_buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
err_dma_disable:
if (adc->dma_chan) {
dma_free_coherent(adc->dma_chan->device->dev,
STM32_DMA_BUFFER_SIZE,
adc->rx_buf, adc->rx_dma_buf);
dma_release_channel(adc->dma_chan);
}
err_clk_disable:
clk_disable_unprepare(adc->clk);
return ret;
}
static int stm32_adc_remove(struct platform_device *pdev)
{
struct stm32_adc *adc = platform_get_drvdata(pdev);
struct iio_dev *indio_dev = iio_priv_to_dev(adc);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
if (adc->dma_chan) {
dma_free_coherent(adc->dma_chan->device->dev,
STM32_DMA_BUFFER_SIZE,
adc->rx_buf, adc->rx_dma_buf);
dma_release_channel(adc->dma_chan);
}
clk_disable_unprepare(adc->clk);
return 0;
}
