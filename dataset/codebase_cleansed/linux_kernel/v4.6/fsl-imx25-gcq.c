static irqreturn_t mx25_gcq_irq(int irq, void *data)
{
struct mx25_gcq_priv *priv = data;
u32 stats;
regmap_read(priv->regs, MX25_ADCQ_SR, &stats);
if (stats & MX25_ADCQ_SR_EOQ) {
regmap_update_bits(priv->regs, MX25_ADCQ_MR,
MX25_ADCQ_MR_EOQ_IRQ, MX25_ADCQ_MR_EOQ_IRQ);
complete(&priv->completed);
}
regmap_update_bits(priv->regs, MX25_ADCQ_CR, MX25_ADCQ_CR_FQS, 0);
regmap_write(priv->regs, MX25_ADCQ_SR, MX25_ADCQ_SR_FRR |
MX25_ADCQ_SR_FUR | MX25_ADCQ_SR_FOR |
MX25_ADCQ_SR_EOQ | MX25_ADCQ_SR_PD);
return IRQ_HANDLED;
}
static int mx25_gcq_get_raw_value(struct device *dev,
struct iio_chan_spec const *chan,
struct mx25_gcq_priv *priv,
int *val)
{
long timeout;
u32 data;
regmap_write(priv->regs, MX25_ADCQ_ITEM_7_0,
MX25_ADCQ_ITEM(0, chan->channel));
regmap_update_bits(priv->regs, MX25_ADCQ_MR, MX25_ADCQ_MR_EOQ_IRQ, 0);
regmap_update_bits(priv->regs, MX25_ADCQ_CR, MX25_ADCQ_CR_FQS,
MX25_ADCQ_CR_FQS);
timeout = wait_for_completion_interruptible_timeout(
&priv->completed, MX25_GCQ_TIMEOUT);
if (timeout < 0) {
dev_err(dev, "ADC wait for measurement failed\n");
return timeout;
} else if (timeout == 0) {
dev_err(dev, "ADC timed out\n");
return -ETIMEDOUT;
}
regmap_read(priv->regs, MX25_ADCQ_FIFO, &data);
*val = MX25_ADCQ_FIFO_DATA(data);
return IIO_VAL_INT;
}
static int mx25_gcq_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
struct mx25_gcq_priv *priv = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
ret = mx25_gcq_get_raw_value(&indio_dev->dev, chan, priv, val);
mutex_unlock(&indio_dev->mlock);
return ret;
case IIO_CHAN_INFO_SCALE:
*val = priv->channel_vref_mv[chan->channel];
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static int mx25_gcq_setup_cfgs(struct platform_device *pdev,
struct mx25_gcq_priv *priv)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
struct device *dev = &pdev->dev;
unsigned int refp_used[4] = {};
int ret, i;
for (i = 0; i < MX25_NUM_CFGS; ++i)
regmap_write(priv->regs, MX25_ADCQ_CFG(i),
MX25_ADCQ_CFG_YPLL_OFF |
MX25_ADCQ_CFG_XNUR_OFF |
MX25_ADCQ_CFG_XPUL_OFF |
MX25_ADCQ_CFG_REFP_INT |
MX25_ADCQ_CFG_IN(i) |
MX25_ADCQ_CFG_REFN_NGND2);
priv->vref[MX25_ADC_REFP_INT] = NULL;
priv->vref[MX25_ADC_REFP_EXT] =
devm_regulator_get_optional(&pdev->dev, "vref-ext");
priv->vref[MX25_ADC_REFP_XP] =
devm_regulator_get_optional(&pdev->dev, "vref-xp");
priv->vref[MX25_ADC_REFP_YP] =
devm_regulator_get_optional(&pdev->dev, "vref-yp");
for_each_child_of_node(np, child) {
u32 reg;
u32 refp = MX25_ADCQ_CFG_REFP_INT;
u32 refn = MX25_ADCQ_CFG_REFN_NGND2;
ret = of_property_read_u32(child, "reg", &reg);
if (ret) {
dev_err(dev, "Failed to get reg property\n");
return ret;
}
if (reg >= MX25_NUM_CFGS) {
dev_err(dev,
"reg value is greater than the number of available configuration registers\n");
return -EINVAL;
}
of_property_read_u32(child, "fsl,adc-refp", &refp);
of_property_read_u32(child, "fsl,adc-refn", &refn);
switch (refp) {
case MX25_ADC_REFP_EXT:
case MX25_ADC_REFP_XP:
case MX25_ADC_REFP_YP:
if (IS_ERR(priv->vref[refp])) {
dev_err(dev, "Error, trying to use external voltage reference without a vref-%s regulator.",
mx25_gcq_refp_names[refp]);
return PTR_ERR(priv->vref[refp]);
}
priv->channel_vref_mv[reg] =
regulator_get_voltage(priv->vref[refp]);
priv->channel_vref_mv[reg] /= 1000;
break;
case MX25_ADC_REFP_INT:
priv->channel_vref_mv[reg] = 2500;
break;
default:
dev_err(dev, "Invalid positive reference %d\n", refp);
return -EINVAL;
}
++refp_used[refp];
refp = MX25_ADCQ_CFG_REFP(refp);
refn = MX25_ADCQ_CFG_REFN(refn);
if ((refp & MX25_ADCQ_CFG_REFP_MASK) != refp) {
dev_err(dev, "Invalid fsl,adc-refp property value\n");
return -EINVAL;
}
if ((refn & MX25_ADCQ_CFG_REFN_MASK) != refn) {
dev_err(dev, "Invalid fsl,adc-refn property value\n");
return -EINVAL;
}
regmap_update_bits(priv->regs, MX25_ADCQ_CFG(reg),
MX25_ADCQ_CFG_REFP_MASK |
MX25_ADCQ_CFG_REFN_MASK,
refp | refn);
}
regmap_update_bits(priv->regs, MX25_ADCQ_CR,
MX25_ADCQ_CR_FRST | MX25_ADCQ_CR_QRST,
MX25_ADCQ_CR_FRST | MX25_ADCQ_CR_QRST);
regmap_write(priv->regs, MX25_ADCQ_CR,
MX25_ADCQ_CR_PDMSK | MX25_ADCQ_CR_QSM_FQS);
for (i = 0; i != 4; ++i) {
if (!refp_used[i]) {
if (!IS_ERR_OR_NULL(priv->vref[i]))
devm_regulator_put(priv->vref[i]);
priv->vref[i] = NULL;
}
}
return 0;
}
static int mx25_gcq_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct mx25_gcq_priv *priv;
struct mx25_tsadc *tsadc = dev_get_drvdata(pdev->dev.parent);
struct device *dev = &pdev->dev;
struct resource *res;
void __iomem *mem;
int ret;
int i;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*priv));
if (!indio_dev)
return -ENOMEM;
priv = iio_priv(indio_dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mem = devm_ioremap_resource(dev, res);
if (IS_ERR(mem))
return PTR_ERR(mem);
priv->regs = devm_regmap_init_mmio(dev, mem, &mx25_gcq_regconfig);
if (IS_ERR(priv->regs)) {
dev_err(dev, "Failed to initialize regmap\n");
return PTR_ERR(priv->regs);
}
init_completion(&priv->completed);
ret = mx25_gcq_setup_cfgs(pdev, priv);
if (ret)
return ret;
for (i = 0; i != 4; ++i) {
if (!priv->vref[i])
continue;
ret = regulator_enable(priv->vref[i]);
if (ret)
goto err_regulator_disable;
}
priv->clk = tsadc->clk;
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(dev, "Failed to enable clock\n");
goto err_vref_disable;
}
priv->irq = platform_get_irq(pdev, 0);
if (priv->irq <= 0) {
dev_err(dev, "Failed to get IRQ\n");
ret = priv->irq;
if (!ret)
ret = -ENXIO;
goto err_clk_unprepare;
}
ret = request_irq(priv->irq, mx25_gcq_irq, 0, pdev->name, priv);
if (ret) {
dev_err(dev, "Failed requesting IRQ\n");
goto err_clk_unprepare;
}
indio_dev->dev.parent = &pdev->dev;
indio_dev->channels = mx25_gcq_channels;
indio_dev->num_channels = ARRAY_SIZE(mx25_gcq_channels);
indio_dev->info = &mx25_gcq_iio_info;
indio_dev->name = driver_name;
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(dev, "Failed to register iio device\n");
goto err_irq_free;
}
platform_set_drvdata(pdev, indio_dev);
return 0;
err_irq_free:
free_irq(priv->irq, priv);
err_clk_unprepare:
clk_disable_unprepare(priv->clk);
err_vref_disable:
i = 4;
err_regulator_disable:
for (; i-- > 0;) {
if (priv->vref[i])
regulator_disable(priv->vref[i]);
}
return ret;
}
static int mx25_gcq_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct mx25_gcq_priv *priv = iio_priv(indio_dev);
int i;
iio_device_unregister(indio_dev);
free_irq(priv->irq, priv);
clk_disable_unprepare(priv->clk);
for (i = 4; i-- > 0;) {
if (priv->vref[i])
regulator_disable(priv->vref[i]);
}
return 0;
}
