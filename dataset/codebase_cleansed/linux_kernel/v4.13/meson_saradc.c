static unsigned int meson_sar_adc_get_fifo_count(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
u32 regval;
regmap_read(priv->regmap, MESON_SAR_ADC_REG0, &regval);
return FIELD_GET(MESON_SAR_ADC_REG0_FIFO_COUNT_MASK, regval);
}
static int meson_sar_adc_calib_val(struct iio_dev *indio_dev, int val)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int tmp;
tmp = div_s64((s64)val * priv->calibscale, MILLION) + priv->calibbias;
return clamp(tmp, 0, (1 << priv->data->resolution) - 1);
}
static int meson_sar_adc_wait_busy_clear(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int regval, timeout = 10000;
do {
udelay(1);
regmap_read(priv->regmap, MESON_SAR_ADC_REG0, &regval);
} while (FIELD_GET(MESON_SAR_ADC_REG0_BUSY_MASK, regval) && timeout--);
if (timeout < 0)
return -ETIMEDOUT;
return 0;
}
static int meson_sar_adc_read_raw_sample(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *val)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int regval, fifo_chan, fifo_val, count;
if(!wait_for_completion_timeout(&priv->done,
msecs_to_jiffies(MESON_SAR_ADC_TIMEOUT)))
return -ETIMEDOUT;
count = meson_sar_adc_get_fifo_count(indio_dev);
if (count != 1) {
dev_err(&indio_dev->dev,
"ADC FIFO has %d element(s) instead of one\n", count);
return -EINVAL;
}
regmap_read(priv->regmap, MESON_SAR_ADC_FIFO_RD, &regval);
fifo_chan = FIELD_GET(MESON_SAR_ADC_FIFO_RD_CHAN_ID_MASK, regval);
if (fifo_chan != chan->channel) {
dev_err(&indio_dev->dev,
"ADC FIFO entry belongs to channel %d instead of %d\n",
fifo_chan, chan->channel);
return -EINVAL;
}
fifo_val = FIELD_GET(MESON_SAR_ADC_FIFO_RD_SAMPLE_VALUE_MASK, regval);
fifo_val &= GENMASK(priv->data->resolution - 1, 0);
*val = meson_sar_adc_calib_val(indio_dev, fifo_val);
return 0;
}
static void meson_sar_adc_set_averaging(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum meson_sar_adc_avg_mode mode,
enum meson_sar_adc_num_samples samples)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int val, channel = chan->channel;
val = samples << MESON_SAR_ADC_AVG_CNTL_NUM_SAMPLES_SHIFT(channel);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_AVG_CNTL,
MESON_SAR_ADC_AVG_CNTL_NUM_SAMPLES_MASK(channel),
val);
val = mode << MESON_SAR_ADC_AVG_CNTL_AVG_MODE_SHIFT(channel);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_AVG_CNTL,
MESON_SAR_ADC_AVG_CNTL_AVG_MODE_MASK(channel), val);
}
static void meson_sar_adc_enable_channel(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
u32 regval;
regval = FIELD_PREP(MESON_SAR_ADC_CHAN_LIST_MAX_INDEX_MASK, 0);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_CHAN_LIST,
MESON_SAR_ADC_CHAN_LIST_MAX_INDEX_MASK, regval);
regval = FIELD_PREP(MESON_SAR_ADC_CHAN_LIST_ENTRY_MASK(0),
chan->channel);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_CHAN_LIST,
MESON_SAR_ADC_CHAN_LIST_ENTRY_MASK(0), regval);
regval = FIELD_PREP(MESON_SAR_ADC_DETECT_IDLE_SW_DETECT_MUX_MASK,
chan->channel);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DETECT_IDLE_SW,
MESON_SAR_ADC_DETECT_IDLE_SW_DETECT_MUX_MASK,
regval);
regval = FIELD_PREP(MESON_SAR_ADC_DETECT_IDLE_SW_IDLE_MUX_SEL_MASK,
chan->channel);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DETECT_IDLE_SW,
MESON_SAR_ADC_DETECT_IDLE_SW_IDLE_MUX_SEL_MASK,
regval);
if (chan->channel == 6)
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DELTA_10,
MESON_SAR_ADC_DELTA_10_TEMP_SEL, 0);
}
static void meson_sar_adc_set_chan7_mux(struct iio_dev *indio_dev,
enum meson_sar_adc_chan7_mux_sel sel)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
u32 regval;
regval = FIELD_PREP(MESON_SAR_ADC_REG3_CTRL_CHAN7_MUX_SEL_MASK, sel);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG3,
MESON_SAR_ADC_REG3_CTRL_CHAN7_MUX_SEL_MASK, regval);
usleep_range(10, 20);
}
static void meson_sar_adc_start_sample_engine(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
reinit_completion(&priv->done);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_FIFO_IRQ_EN,
MESON_SAR_ADC_REG0_FIFO_IRQ_EN);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_SAMPLE_ENGINE_ENABLE,
MESON_SAR_ADC_REG0_SAMPLE_ENGINE_ENABLE);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_SAMPLING_START,
MESON_SAR_ADC_REG0_SAMPLING_START);
}
static void meson_sar_adc_stop_sample_engine(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_FIFO_IRQ_EN, 0);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_SAMPLING_STOP,
MESON_SAR_ADC_REG0_SAMPLING_STOP);
meson_sar_adc_wait_busy_clear(indio_dev);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_SAMPLE_ENGINE_ENABLE, 0);
}
static int meson_sar_adc_lock(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int val, timeout = 10000;
mutex_lock(&indio_dev->mlock);
if (priv->data->has_bl30_integration) {
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DELAY,
MESON_SAR_ADC_DELAY_KERNEL_BUSY,
MESON_SAR_ADC_DELAY_KERNEL_BUSY);
do {
udelay(1);
regmap_read(priv->regmap, MESON_SAR_ADC_DELAY, &val);
} while (val & MESON_SAR_ADC_DELAY_BL30_BUSY && timeout--);
if (timeout < 0)
return -ETIMEDOUT;
}
return 0;
}
static void meson_sar_adc_unlock(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
if (priv->data->has_bl30_integration)
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DELAY,
MESON_SAR_ADC_DELAY_KERNEL_BUSY, 0);
mutex_unlock(&indio_dev->mlock);
}
static void meson_sar_adc_clear_fifo(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
unsigned int count, tmp;
for (count = 0; count < MESON_SAR_ADC_MAX_FIFO_SIZE; count++) {
if (!meson_sar_adc_get_fifo_count(indio_dev))
break;
regmap_read(priv->regmap, MESON_SAR_ADC_FIFO_RD, &tmp);
}
}
static int meson_sar_adc_get_sample(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
enum meson_sar_adc_avg_mode avg_mode,
enum meson_sar_adc_num_samples avg_samples,
int *val)
{
int ret;
ret = meson_sar_adc_lock(indio_dev);
if (ret)
return ret;
meson_sar_adc_clear_fifo(indio_dev);
meson_sar_adc_set_averaging(indio_dev, chan, avg_mode, avg_samples);
meson_sar_adc_enable_channel(indio_dev, chan);
meson_sar_adc_start_sample_engine(indio_dev);
ret = meson_sar_adc_read_raw_sample(indio_dev, chan, val);
meson_sar_adc_stop_sample_engine(indio_dev);
meson_sar_adc_unlock(indio_dev);
if (ret) {
dev_warn(indio_dev->dev.parent,
"failed to read sample for channel %d: %d\n",
chan->channel, ret);
return ret;
}
return IIO_VAL_INT;
}
static int meson_sar_adc_iio_info_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long mask)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
return meson_sar_adc_get_sample(indio_dev, chan, NO_AVERAGING,
ONE_SAMPLE, val);
break;
case IIO_CHAN_INFO_AVERAGE_RAW:
return meson_sar_adc_get_sample(indio_dev, chan,
MEAN_AVERAGING, EIGHT_SAMPLES,
val);
break;
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(priv->vref);
if (ret < 0) {
dev_err(indio_dev->dev.parent,
"failed to get vref voltage: %d\n", ret);
return ret;
}
*val = ret / 1000;
*val2 = priv->data->resolution;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_CALIBBIAS:
*val = priv->calibbias;
return IIO_VAL_INT;
case IIO_CHAN_INFO_CALIBSCALE:
*val = priv->calibscale / MILLION;
*val2 = priv->calibscale % MILLION;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int meson_sar_adc_clk_init(struct iio_dev *indio_dev,
void __iomem *base)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
struct clk_init_data init;
const char *clk_parents[1];
init.name = devm_kasprintf(&indio_dev->dev, GFP_KERNEL, "%s#adc_div",
of_node_full_name(indio_dev->dev.of_node));
init.flags = 0;
init.ops = &clk_divider_ops;
clk_parents[0] = __clk_get_name(priv->clkin);
init.parent_names = clk_parents;
init.num_parents = 1;
priv->clk_div.reg = base + MESON_SAR_ADC_REG3;
priv->clk_div.shift = MESON_SAR_ADC_REG3_ADC_CLK_DIV_SHIFT;
priv->clk_div.width = MESON_SAR_ADC_REG3_ADC_CLK_DIV_WIDTH;
priv->clk_div.hw.init = &init;
priv->clk_div.flags = 0;
priv->adc_div_clk = devm_clk_register(&indio_dev->dev,
&priv->clk_div.hw);
if (WARN_ON(IS_ERR(priv->adc_div_clk)))
return PTR_ERR(priv->adc_div_clk);
init.name = devm_kasprintf(&indio_dev->dev, GFP_KERNEL, "%s#adc_en",
of_node_full_name(indio_dev->dev.of_node));
init.flags = CLK_SET_RATE_PARENT;
init.ops = &clk_gate_ops;
clk_parents[0] = __clk_get_name(priv->adc_div_clk);
init.parent_names = clk_parents;
init.num_parents = 1;
priv->clk_gate.reg = base + MESON_SAR_ADC_REG3;
priv->clk_gate.bit_idx = fls(MESON_SAR_ADC_REG3_CLK_EN);
priv->clk_gate.hw.init = &init;
priv->adc_clk = devm_clk_register(&indio_dev->dev, &priv->clk_gate.hw);
if (WARN_ON(IS_ERR(priv->adc_clk)))
return PTR_ERR(priv->adc_clk);
return 0;
}
static int meson_sar_adc_init(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int regval, ret;
meson_sar_adc_set_chan7_mux(indio_dev, CHAN7_MUX_CH7_INPUT);
if (priv->data->has_bl30_integration) {
regmap_read(priv->regmap, MESON_SAR_ADC_REG3, &regval);
if (regval & MESON_SAR_ADC_REG3_BL30_INITIALIZED)
return 0;
}
meson_sar_adc_stop_sample_engine(indio_dev);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_ADC_TEMP_SEN_SEL,
MESON_SAR_ADC_REG0_ADC_TEMP_SEN_SEL);
regmap_write(priv->regmap, MESON_SAR_ADC_CHAN_LIST, 0x0);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG3,
MESON_SAR_ADC_REG3_CTRL_SAMPLING_CLOCK_PHASE, 0);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG3,
MESON_SAR_ADC_REG3_CNTL_USE_SC_DLY,
MESON_SAR_ADC_REG3_CNTL_USE_SC_DLY);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DELAY,
MESON_SAR_ADC_DELAY_INPUT_DLY_CNT_MASK,
FIELD_PREP(MESON_SAR_ADC_DELAY_SAMPLE_DLY_CNT_MASK,
10));
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DELAY,
MESON_SAR_ADC_DELAY_SAMPLE_DLY_SEL_MASK,
FIELD_PREP(MESON_SAR_ADC_DELAY_SAMPLE_DLY_SEL_MASK,
0));
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DELAY,
MESON_SAR_ADC_DELAY_INPUT_DLY_CNT_MASK,
FIELD_PREP(MESON_SAR_ADC_DELAY_INPUT_DLY_CNT_MASK,
10));
regmap_update_bits(priv->regmap, MESON_SAR_ADC_DELAY,
MESON_SAR_ADC_DELAY_INPUT_DLY_SEL_MASK,
FIELD_PREP(MESON_SAR_ADC_DELAY_INPUT_DLY_SEL_MASK,
1));
ret = clk_set_parent(priv->adc_sel_clk, priv->clkin);
if (ret) {
dev_err(indio_dev->dev.parent,
"failed to set adc parent to clkin\n");
return ret;
}
ret = clk_set_rate(priv->adc_clk, 1200000);
if (ret) {
dev_err(indio_dev->dev.parent,
"failed to set adc clock rate\n");
return ret;
}
return 0;
}
static int meson_sar_adc_hw_enable(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int ret;
u32 regval;
ret = meson_sar_adc_lock(indio_dev);
if (ret)
goto err_lock;
ret = regulator_enable(priv->vref);
if (ret < 0) {
dev_err(indio_dev->dev.parent,
"failed to enable vref regulator\n");
goto err_vref;
}
ret = clk_prepare_enable(priv->core_clk);
if (ret) {
dev_err(indio_dev->dev.parent, "failed to enable core clk\n");
goto err_core_clk;
}
ret = clk_prepare_enable(priv->sana_clk);
if (ret) {
dev_err(indio_dev->dev.parent, "failed to enable sana clk\n");
goto err_sana_clk;
}
regval = FIELD_PREP(MESON_SAR_ADC_REG0_FIFO_CNT_IRQ_MASK, 1);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG0,
MESON_SAR_ADC_REG0_FIFO_CNT_IRQ_MASK, regval);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG11,
MESON_SAR_ADC_REG11_BANDGAP_EN,
MESON_SAR_ADC_REG11_BANDGAP_EN);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG3,
MESON_SAR_ADC_REG3_ADC_EN,
MESON_SAR_ADC_REG3_ADC_EN);
udelay(5);
ret = clk_prepare_enable(priv->adc_clk);
if (ret) {
dev_err(indio_dev->dev.parent, "failed to enable adc clk\n");
goto err_adc_clk;
}
meson_sar_adc_unlock(indio_dev);
return 0;
err_adc_clk:
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG3,
MESON_SAR_ADC_REG3_ADC_EN, 0);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG11,
MESON_SAR_ADC_REG11_BANDGAP_EN, 0);
clk_disable_unprepare(priv->sana_clk);
err_sana_clk:
clk_disable_unprepare(priv->core_clk);
err_core_clk:
regulator_disable(priv->vref);
err_vref:
meson_sar_adc_unlock(indio_dev);
err_lock:
return ret;
}
static int meson_sar_adc_hw_disable(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int ret;
ret = meson_sar_adc_lock(indio_dev);
if (ret)
return ret;
clk_disable_unprepare(priv->adc_clk);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG3,
MESON_SAR_ADC_REG3_ADC_EN, 0);
regmap_update_bits(priv->regmap, MESON_SAR_ADC_REG11,
MESON_SAR_ADC_REG11_BANDGAP_EN, 0);
clk_disable_unprepare(priv->sana_clk);
clk_disable_unprepare(priv->core_clk);
regulator_disable(priv->vref);
meson_sar_adc_unlock(indio_dev);
return 0;
}
static irqreturn_t meson_sar_adc_irq(int irq, void *data)
{
struct iio_dev *indio_dev = data;
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
unsigned int cnt, threshold;
u32 regval;
regmap_read(priv->regmap, MESON_SAR_ADC_REG0, &regval);
cnt = FIELD_GET(MESON_SAR_ADC_REG0_FIFO_COUNT_MASK, regval);
threshold = FIELD_GET(MESON_SAR_ADC_REG0_FIFO_CNT_IRQ_MASK, regval);
if (cnt < threshold)
return IRQ_NONE;
complete(&priv->done);
return IRQ_HANDLED;
}
static int meson_sar_adc_calib(struct iio_dev *indio_dev)
{
struct meson_sar_adc_priv *priv = iio_priv(indio_dev);
int ret, nominal0, nominal1, value0, value1;
nominal0 = (1 << priv->data->resolution) / 4;
nominal1 = (1 << priv->data->resolution) * 3 / 4;
meson_sar_adc_set_chan7_mux(indio_dev, CHAN7_MUX_VDD_DIV4);
usleep_range(10, 20);
ret = meson_sar_adc_get_sample(indio_dev,
&meson_sar_adc_iio_channels[7],
MEAN_AVERAGING, EIGHT_SAMPLES, &value0);
if (ret < 0)
goto out;
meson_sar_adc_set_chan7_mux(indio_dev, CHAN7_MUX_VDD_MUL3_DIV4);
usleep_range(10, 20);
ret = meson_sar_adc_get_sample(indio_dev,
&meson_sar_adc_iio_channels[7],
MEAN_AVERAGING, EIGHT_SAMPLES, &value1);
if (ret < 0)
goto out;
if (value1 <= value0) {
ret = -EINVAL;
goto out;
}
priv->calibscale = div_s64((nominal1 - nominal0) * (s64)MILLION,
value1 - value0);
priv->calibbias = nominal0 - div_s64((s64)value0 * priv->calibscale,
MILLION);
ret = 0;
out:
meson_sar_adc_set_chan7_mux(indio_dev, CHAN7_MUX_CH7_INPUT);
return ret;
}
static int meson_sar_adc_probe(struct platform_device *pdev)
{
struct meson_sar_adc_priv *priv;
struct iio_dev *indio_dev;
struct resource *res;
void __iomem *base;
const struct of_device_id *match;
int irq, ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*priv));
if (!indio_dev) {
dev_err(&pdev->dev, "failed allocating iio device\n");
return -ENOMEM;
}
priv = iio_priv(indio_dev);
init_completion(&priv->done);
match = of_match_device(meson_sar_adc_of_match, &pdev->dev);
priv->data = match->data;
indio_dev->name = priv->data->name;
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &meson_sar_adc_iio_info;
indio_dev->channels = meson_sar_adc_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(meson_sar_adc_iio_channels);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
if (!irq)
return -EINVAL;
ret = devm_request_irq(&pdev->dev, irq, meson_sar_adc_irq, IRQF_SHARED,
dev_name(&pdev->dev), indio_dev);
if (ret)
return ret;
priv->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&meson_sar_adc_regmap_config);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
priv->clkin = devm_clk_get(&pdev->dev, "clkin");
if (IS_ERR(priv->clkin)) {
dev_err(&pdev->dev, "failed to get clkin\n");
return PTR_ERR(priv->clkin);
}
priv->core_clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(priv->core_clk)) {
dev_err(&pdev->dev, "failed to get core clk\n");
return PTR_ERR(priv->core_clk);
}
priv->sana_clk = devm_clk_get(&pdev->dev, "sana");
if (IS_ERR(priv->sana_clk)) {
if (PTR_ERR(priv->sana_clk) == -ENOENT) {
priv->sana_clk = NULL;
} else {
dev_err(&pdev->dev, "failed to get sana clk\n");
return PTR_ERR(priv->sana_clk);
}
}
priv->adc_clk = devm_clk_get(&pdev->dev, "adc_clk");
if (IS_ERR(priv->adc_clk)) {
if (PTR_ERR(priv->adc_clk) == -ENOENT) {
priv->adc_clk = NULL;
} else {
dev_err(&pdev->dev, "failed to get adc clk\n");
return PTR_ERR(priv->adc_clk);
}
}
priv->adc_sel_clk = devm_clk_get(&pdev->dev, "adc_sel");
if (IS_ERR(priv->adc_sel_clk)) {
if (PTR_ERR(priv->adc_sel_clk) == -ENOENT) {
priv->adc_sel_clk = NULL;
} else {
dev_err(&pdev->dev, "failed to get adc_sel clk\n");
return PTR_ERR(priv->adc_sel_clk);
}
}
if (!priv->adc_clk) {
ret = meson_sar_adc_clk_init(indio_dev, base);
if (ret)
return ret;
}
priv->vref = devm_regulator_get(&pdev->dev, "vref");
if (IS_ERR(priv->vref)) {
dev_err(&pdev->dev, "failed to get vref regulator\n");
return PTR_ERR(priv->vref);
}
priv->calibscale = MILLION;
ret = meson_sar_adc_init(indio_dev);
if (ret)
goto err;
ret = meson_sar_adc_hw_enable(indio_dev);
if (ret)
goto err;
ret = meson_sar_adc_calib(indio_dev);
if (ret)
dev_warn(&pdev->dev, "calibration failed\n");
platform_set_drvdata(pdev, indio_dev);
ret = iio_device_register(indio_dev);
if (ret)
goto err_hw;
return 0;
err_hw:
meson_sar_adc_hw_disable(indio_dev);
err:
return ret;
}
static int meson_sar_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
iio_device_unregister(indio_dev);
return meson_sar_adc_hw_disable(indio_dev);
}
static int __maybe_unused meson_sar_adc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
return meson_sar_adc_hw_disable(indio_dev);
}
static int __maybe_unused meson_sar_adc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
return meson_sar_adc_hw_enable(indio_dev);
}
