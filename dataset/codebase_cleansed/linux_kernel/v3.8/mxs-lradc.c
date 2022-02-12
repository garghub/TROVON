static int mxs_lradc_read_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long m)
{
struct mxs_lradc *lradc = iio_priv(iio_dev);
int ret;
if (m != IIO_CHAN_INFO_RAW)
return -EINVAL;
if (chan->channel > LRADC_MAX_TOTAL_CHANS)
return -EINVAL;
ret = mutex_trylock(&lradc->lock);
if (!ret)
return -EBUSY;
INIT_COMPLETION(lradc->completion);
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(0xff, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
writel(chan->channel, lradc->base + LRADC_CTRL4);
writel(0, lradc->base + LRADC_CH(0));
writel(LRADC_CTRL1_LRADC_IRQ_EN(0),
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
writel(1 << 0, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
ret = wait_for_completion_killable_timeout(&lradc->completion, HZ);
if (!ret)
ret = -ETIMEDOUT;
if (ret < 0)
goto err;
*val = readl(lradc->base + LRADC_CH(0)) & LRADC_CH_VALUE_MASK;
ret = IIO_VAL_INT;
err:
writel(LRADC_CTRL1_LRADC_IRQ_EN(0),
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
mutex_unlock(&lradc->lock);
return ret;
}
static irqreturn_t mxs_lradc_handle_irq(int irq, void *data)
{
struct iio_dev *iio = data;
struct mxs_lradc *lradc = iio_priv(iio);
unsigned long reg = readl(lradc->base + LRADC_CTRL1);
if (!(reg & LRADC_CTRL1_LRADC_IRQ_MASK))
return IRQ_NONE;
if (iio_buffer_enabled(iio))
iio_trigger_poll(iio->trig, iio_get_time_ns());
else if (reg & LRADC_CTRL1_LRADC_IRQ(0))
complete(&lradc->completion);
writel(reg & LRADC_CTRL1_LRADC_IRQ_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
return IRQ_HANDLED;
}
static irqreturn_t mxs_lradc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *iio = pf->indio_dev;
struct mxs_lradc *lradc = iio_priv(iio);
const uint32_t chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
unsigned int i, j = 0;
for_each_set_bit(i, iio->active_scan_mask, iio->masklength) {
lradc->buffer[j] = readl(lradc->base + LRADC_CH(j));
writel(chan_value, lradc->base + LRADC_CH(j));
lradc->buffer[j] &= LRADC_CH_VALUE_MASK;
lradc->buffer[j] /= LRADC_DELAY_TIMER_LOOP;
j++;
}
if (iio->scan_timestamp) {
s64 *timestamp = (s64 *)((u8 *)lradc->buffer +
ALIGN(j, sizeof(s64)));
*timestamp = pf->timestamp;
}
iio_push_to_buffers(iio, (u8 *)lradc->buffer);
iio_trigger_notify_done(iio->trig);
return IRQ_HANDLED;
}
static int mxs_lradc_configure_trigger(struct iio_trigger *trig, bool state)
{
struct iio_dev *iio = trig->private_data;
struct mxs_lradc *lradc = iio_priv(iio);
const uint32_t st = state ? STMP_OFFSET_REG_SET : STMP_OFFSET_REG_CLR;
writel(LRADC_DELAY_KICK, lradc->base + LRADC_DELAY(0) + st);
return 0;
}
static int mxs_lradc_trigger_init(struct iio_dev *iio)
{
int ret;
struct iio_trigger *trig;
trig = iio_trigger_alloc("%s-dev%i", iio->name, iio->id);
if (trig == NULL)
return -ENOMEM;
trig->dev.parent = iio->dev.parent;
trig->private_data = iio;
trig->ops = &mxs_lradc_trigger_ops;
ret = iio_trigger_register(trig);
if (ret) {
iio_trigger_free(trig);
return ret;
}
iio->trig = trig;
return 0;
}
static void mxs_lradc_trigger_remove(struct iio_dev *iio)
{
iio_trigger_unregister(iio->trig);
iio_trigger_free(iio->trig);
}
static int mxs_lradc_buffer_preenable(struct iio_dev *iio)
{
struct mxs_lradc *lradc = iio_priv(iio);
struct iio_buffer *buffer = iio->buffer;
int ret = 0, chan, ofs = 0, enable = 0;
uint32_t ctrl4 = 0;
uint32_t ctrl1_irq = 0;
const uint32_t chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
const int len = bitmap_weight(buffer->scan_mask, LRADC_MAX_TOTAL_CHANS);
if (!len)
return -EINVAL;
ret = mutex_trylock(&lradc->lock);
if (!ret)
return -EBUSY;
lradc->buffer = kmalloc(len * sizeof(*lradc->buffer), GFP_KERNEL);
if (!lradc->buffer) {
ret = -ENOMEM;
goto err_mem;
}
ret = iio_sw_buffer_preenable(iio);
if (ret < 0)
goto err_buf;
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(0xff, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
for_each_set_bit(chan, buffer->scan_mask, LRADC_MAX_TOTAL_CHANS) {
ctrl4 |= chan << LRADC_CTRL4_LRADCSELECT_OFFSET(ofs);
ctrl1_irq |= LRADC_CTRL1_LRADC_IRQ_EN(ofs);
writel(chan_value, lradc->base + LRADC_CH(ofs));
enable |= 1 << ofs;
ofs++;
}
writel(LRADC_DELAY_TRIGGER_LRADCS_MASK | LRADC_DELAY_KICK,
lradc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_CLR);
writel(ctrl4, lradc->base + LRADC_CTRL4);
writel(ctrl1_irq, lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
writel(enable << LRADC_DELAY_TRIGGER_LRADCS_OFFSET,
lradc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_SET);
return 0;
err_buf:
kfree(lradc->buffer);
err_mem:
mutex_unlock(&lradc->lock);
return ret;
}
static int mxs_lradc_buffer_postdisable(struct iio_dev *iio)
{
struct mxs_lradc *lradc = iio_priv(iio);
writel(LRADC_DELAY_TRIGGER_LRADCS_MASK | LRADC_DELAY_KICK,
lradc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_CLR);
writel(0xff, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
kfree(lradc->buffer);
mutex_unlock(&lradc->lock);
return 0;
}
static bool mxs_lradc_validate_scan_mask(struct iio_dev *iio,
const unsigned long *mask)
{
const int mw = bitmap_weight(mask, iio->masklength);
return mw <= LRADC_MAX_MAPPED_CHANS;
}
static void mxs_lradc_hw_init(struct mxs_lradc *lradc)
{
int i;
const uint32_t cfg =
(LRADC_DELAY_TIMER_PER << LRADC_DELAY_DELAY_OFFSET);
stmp_reset_block(lradc->base);
for (i = 0; i < LRADC_MAX_DELAY_CHANS; i++)
writel(cfg | (1 << (LRADC_DELAY_TRIGGER_DELAYS_OFFSET + i)),
lradc->base + LRADC_DELAY(i));
writel(0, lradc->base + LRADC_CTRL2);
}
static void mxs_lradc_hw_stop(struct mxs_lradc *lradc)
{
int i;
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
for (i = 0; i < LRADC_MAX_DELAY_CHANS; i++)
writel(0, lradc->base + LRADC_DELAY(i));
}
static int mxs_lradc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mxs_lradc *lradc;
struct iio_dev *iio;
struct resource *iores;
int ret = 0;
int i;
iio = iio_device_alloc(sizeof(*lradc));
if (!iio) {
dev_err(dev, "Failed to allocate IIO device\n");
return -ENOMEM;
}
lradc = iio_priv(iio);
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
lradc->dev = &pdev->dev;
lradc->base = devm_request_and_ioremap(dev, iores);
if (!lradc->base) {
ret = -EADDRNOTAVAIL;
goto err_addr;
}
for (i = 0; i < 13; i++) {
lradc->irq[i] = platform_get_irq(pdev, i);
if (lradc->irq[i] < 0) {
ret = -EINVAL;
goto err_addr;
}
ret = devm_request_irq(dev, lradc->irq[i],
mxs_lradc_handle_irq, 0,
mxs_lradc_irq_name[i], iio);
if (ret)
goto err_addr;
}
platform_set_drvdata(pdev, iio);
init_completion(&lradc->completion);
mutex_init(&lradc->lock);
iio->name = pdev->name;
iio->dev.parent = &pdev->dev;
iio->info = &mxs_lradc_iio_info;
iio->modes = INDIO_DIRECT_MODE;
iio->channels = mxs_lradc_chan_spec;
iio->num_channels = ARRAY_SIZE(mxs_lradc_chan_spec);
ret = iio_triggered_buffer_setup(iio, &iio_pollfunc_store_time,
&mxs_lradc_trigger_handler,
&mxs_lradc_buffer_ops);
if (ret)
goto err_addr;
ret = mxs_lradc_trigger_init(iio);
if (ret)
goto err_trig;
ret = iio_device_register(iio);
if (ret) {
dev_err(dev, "Failed to register IIO device\n");
goto err_dev;
}
mxs_lradc_hw_init(lradc);
return 0;
err_dev:
mxs_lradc_trigger_remove(iio);
err_trig:
iio_triggered_buffer_cleanup(iio);
err_addr:
iio_device_free(iio);
return ret;
}
static int mxs_lradc_remove(struct platform_device *pdev)
{
struct iio_dev *iio = platform_get_drvdata(pdev);
struct mxs_lradc *lradc = iio_priv(iio);
mxs_lradc_hw_stop(lradc);
iio_device_unregister(iio);
iio_triggered_buffer_cleanup(iio);
mxs_lradc_trigger_remove(iio);
iio_device_free(iio);
return 0;
}
