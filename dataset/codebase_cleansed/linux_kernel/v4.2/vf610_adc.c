static inline void vf610_adc_calculate_rates(struct vf610_adc *info)
{
struct vf610_adc_feature *adc_feature = &info->adc_feature;
unsigned long adck_rate, ipg_rate = clk_get_rate(info->clk);
int divisor, i;
adck_rate = info->max_adck_rate[adc_feature->conv_mode];
if (adck_rate) {
divisor = ipg_rate / adck_rate;
adc_feature->clk_div = 1 << fls(divisor + 1);
} else {
adc_feature->clk_div = 8;
}
adck_rate = ipg_rate / info->adc_feature.clk_div;
for (i = 0; i < ARRAY_SIZE(vf610_hw_avgs); i++)
info->sample_freq_avail[i] =
adck_rate / (6 + vf610_hw_avgs[i] * (25 + 3));
}
static inline void vf610_adc_cfg_init(struct vf610_adc *info)
{
struct vf610_adc_feature *adc_feature = &info->adc_feature;
adc_feature->clk_sel = VF610_ADCIOC_BUSCLK_SET;
adc_feature->vol_ref = VF610_ADCIOC_VR_VREF_SET;
adc_feature->calibration = true;
adc_feature->ovwren = true;
adc_feature->res_mode = 12;
adc_feature->sample_rate = 1;
adc_feature->conv_mode = VF610_ADC_CONV_LOW_POWER;
vf610_adc_calculate_rates(info);
}
static void vf610_adc_cfg_post_set(struct vf610_adc *info)
{
struct vf610_adc_feature *adc_feature = &info->adc_feature;
int cfg_data = 0;
int gc_data = 0;
switch (adc_feature->clk_sel) {
case VF610_ADCIOC_ALTCLK_SET:
cfg_data |= VF610_ADC_ALTCLK_SEL;
break;
case VF610_ADCIOC_ADACK_SET:
cfg_data |= VF610_ADC_ADACK_SEL;
break;
default:
break;
}
cfg_data |= VF610_ADC_ADLPC_EN;
cfg_data |= VF610_ADC_ADHSC_EN;
switch (adc_feature->vol_ref) {
case VF610_ADCIOC_VR_VREF_SET:
break;
case VF610_ADCIOC_VR_VALT_SET:
cfg_data |= VF610_ADC_REFSEL_VALT;
break;
case VF610_ADCIOC_VR_VBG_SET:
cfg_data |= VF610_ADC_REFSEL_VBG;
break;
default:
dev_err(info->dev, "error voltage reference\n");
}
if (adc_feature->ovwren)
cfg_data |= VF610_ADC_OVWREN;
writel(cfg_data, info->regs + VF610_REG_ADC_CFG);
writel(gc_data, info->regs + VF610_REG_ADC_GC);
}
static void vf610_adc_calibration(struct vf610_adc *info)
{
int adc_gc, hc_cfg;
if (!info->adc_feature.calibration)
return;
hc_cfg = VF610_ADC_AIEN | VF610_ADC_CONV_DISABLE;
writel(hc_cfg, info->regs + VF610_REG_ADC_HC0);
adc_gc = readl(info->regs + VF610_REG_ADC_GC);
writel(adc_gc | VF610_ADC_CAL, info->regs + VF610_REG_ADC_GC);
if (!wait_for_completion_timeout(&info->completion, VF610_ADC_TIMEOUT))
dev_err(info->dev, "Timeout for adc calibration\n");
adc_gc = readl(info->regs + VF610_REG_ADC_GS);
if (adc_gc & VF610_ADC_CALF)
dev_err(info->dev, "ADC calibration failed\n");
info->adc_feature.calibration = false;
}
static void vf610_adc_cfg_set(struct vf610_adc *info)
{
struct vf610_adc_feature *adc_feature = &(info->adc_feature);
int cfg_data;
cfg_data = readl(info->regs + VF610_REG_ADC_CFG);
cfg_data &= ~VF610_ADC_ADLPC_EN;
if (adc_feature->conv_mode == VF610_ADC_CONV_LOW_POWER)
cfg_data |= VF610_ADC_ADLPC_EN;
cfg_data &= ~VF610_ADC_ADHSC_EN;
if (adc_feature->conv_mode == VF610_ADC_CONV_HIGH_SPEED)
cfg_data |= VF610_ADC_ADHSC_EN;
writel(cfg_data, info->regs + VF610_REG_ADC_CFG);
}
static void vf610_adc_sample_set(struct vf610_adc *info)
{
struct vf610_adc_feature *adc_feature = &(info->adc_feature);
int cfg_data, gc_data;
cfg_data = readl(info->regs + VF610_REG_ADC_CFG);
gc_data = readl(info->regs + VF610_REG_ADC_GC);
cfg_data &= ~VF610_ADC_MODE_MASK;
switch (adc_feature->res_mode) {
case 8:
cfg_data |= VF610_ADC_MODE_BIT8;
break;
case 10:
cfg_data |= VF610_ADC_MODE_BIT10;
break;
case 12:
cfg_data |= VF610_ADC_MODE_BIT12;
break;
default:
dev_err(info->dev, "error resolution mode\n");
break;
}
cfg_data &= ~(VF610_ADC_CLK_MASK | VF610_ADC_ADCCLK_MASK);
switch (adc_feature->clk_div) {
case 1:
break;
case 2:
cfg_data |= VF610_ADC_CLK_DIV2;
break;
case 4:
cfg_data |= VF610_ADC_CLK_DIV4;
break;
case 8:
cfg_data |= VF610_ADC_CLK_DIV8;
break;
case 16:
switch (adc_feature->clk_sel) {
case VF610_ADCIOC_BUSCLK_SET:
cfg_data |= VF610_ADC_BUSCLK2_SEL | VF610_ADC_CLK_DIV8;
break;
default:
dev_err(info->dev, "error clk divider\n");
break;
}
break;
}
cfg_data &= ~(VF610_ADC_ADLSMP_LONG | VF610_ADC_ADSTS_MASK);
cfg_data &= ~VF610_ADC_AVGS_MASK;
gc_data &= ~VF610_ADC_AVGEN;
switch (adc_feature->sample_rate) {
case VF610_ADC_SAMPLE_1:
break;
case VF610_ADC_SAMPLE_4:
gc_data |= VF610_ADC_AVGEN;
break;
case VF610_ADC_SAMPLE_8:
gc_data |= VF610_ADC_AVGEN;
cfg_data |= VF610_ADC_AVGS_8;
break;
case VF610_ADC_SAMPLE_16:
gc_data |= VF610_ADC_AVGEN;
cfg_data |= VF610_ADC_AVGS_16;
break;
case VF610_ADC_SAMPLE_32:
gc_data |= VF610_ADC_AVGEN;
cfg_data |= VF610_ADC_AVGS_32;
break;
default:
dev_err(info->dev,
"error hardware sample average select\n");
}
writel(cfg_data, info->regs + VF610_REG_ADC_CFG);
writel(gc_data, info->regs + VF610_REG_ADC_GC);
}
static void vf610_adc_hw_init(struct vf610_adc *info)
{
vf610_adc_cfg_post_set(info);
vf610_adc_sample_set(info);
vf610_adc_calibration(info);
vf610_adc_cfg_set(info);
}
static int vf610_set_conversion_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
unsigned int mode)
{
struct vf610_adc *info = iio_priv(indio_dev);
mutex_lock(&indio_dev->mlock);
info->adc_feature.conv_mode = mode;
vf610_adc_calculate_rates(info);
vf610_adc_hw_init(info);
mutex_unlock(&indio_dev->mlock);
return 0;
}
static int vf610_get_conversion_mode(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan)
{
struct vf610_adc *info = iio_priv(indio_dev);
return info->adc_feature.conv_mode;
}
static int vf610_adc_read_data(struct vf610_adc *info)
{
int result;
result = readl(info->regs + VF610_REG_ADC_R0);
switch (info->adc_feature.res_mode) {
case 8:
result &= 0xFF;
break;
case 10:
result &= 0x3FF;
break;
case 12:
result &= 0xFFF;
break;
default:
break;
}
return result;
}
static irqreturn_t vf610_adc_isr(int irq, void *dev_id)
{
struct vf610_adc *info = (struct vf610_adc *)dev_id;
int coco;
coco = readl(info->regs + VF610_REG_ADC_HS);
if (coco & VF610_ADC_HS_COCO0) {
info->value = vf610_adc_read_data(info);
complete(&info->completion);
}
return IRQ_HANDLED;
}
static ssize_t vf610_show_samp_freq_avail(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct vf610_adc *info = iio_priv(dev_to_iio_dev(dev));
size_t len = 0;
int i;
for (i = 0; i < ARRAY_SIZE(info->sample_freq_avail); i++)
len += scnprintf(buf + len, PAGE_SIZE - len,
"%u ", info->sample_freq_avail[i]);
buf[len - 1] = '\n';
return len;
}
static int vf610_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct vf610_adc *info = iio_priv(indio_dev);
unsigned int hc_cfg;
long ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
mutex_lock(&indio_dev->mlock);
reinit_completion(&info->completion);
hc_cfg = VF610_ADC_ADCHC(chan->channel);
hc_cfg |= VF610_ADC_AIEN;
writel(hc_cfg, info->regs + VF610_REG_ADC_HC0);
ret = wait_for_completion_interruptible_timeout
(&info->completion, VF610_ADC_TIMEOUT);
if (ret == 0) {
mutex_unlock(&indio_dev->mlock);
return -ETIMEDOUT;
}
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
switch (chan->type) {
case IIO_VOLTAGE:
*val = info->value;
break;
case IIO_TEMP:
*val = 25000 - ((int)info->value - 864) * 1000000 / 1840;
break;
default:
mutex_unlock(&indio_dev->mlock);
return -EINVAL;
}
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = info->vref_uv / 1000;
*val2 = info->adc_feature.res_mode;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = info->sample_freq_avail[info->adc_feature.sample_rate];
*val2 = 0;
return IIO_VAL_INT;
default:
break;
}
return -EINVAL;
}
static int vf610_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct vf610_adc *info = iio_priv(indio_dev);
int i;
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
for (i = 0;
i < ARRAY_SIZE(info->sample_freq_avail);
i++)
if (val == info->sample_freq_avail[i]) {
info->adc_feature.sample_rate = i;
vf610_adc_sample_set(info);
return 0;
}
break;
default:
break;
}
return -EINVAL;
}
static int vf610_adc_reg_access(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
struct vf610_adc *info = iio_priv(indio_dev);
if ((readval == NULL) ||
((reg % 4) || (reg > VF610_REG_ADC_PCTL)))
return -EINVAL;
*readval = readl(info->regs + reg);
return 0;
}
static int vf610_adc_probe(struct platform_device *pdev)
{
struct vf610_adc *info;
struct iio_dev *indio_dev;
struct resource *mem;
int irq;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(struct vf610_adc));
if (!indio_dev) {
dev_err(&pdev->dev, "Failed allocating iio device\n");
return -ENOMEM;
}
info = iio_priv(indio_dev);
info->dev = &pdev->dev;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->regs))
return PTR_ERR(info->regs);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
ret = devm_request_irq(info->dev, irq,
vf610_adc_isr, 0,
dev_name(&pdev->dev), info);
if (ret < 0) {
dev_err(&pdev->dev, "failed requesting irq, irq = %d\n", irq);
return ret;
}
info->clk = devm_clk_get(&pdev->dev, "adc");
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed getting clock, err = %ld\n",
PTR_ERR(info->clk));
return PTR_ERR(info->clk);
}
info->vref = devm_regulator_get(&pdev->dev, "vref");
if (IS_ERR(info->vref))
return PTR_ERR(info->vref);
ret = regulator_enable(info->vref);
if (ret)
return ret;
info->vref_uv = regulator_get_voltage(info->vref);
of_property_read_u32_array(pdev->dev.of_node, "fsl,adck-max-frequency",
info->max_adck_rate, 3);
platform_set_drvdata(pdev, indio_dev);
init_completion(&info->completion);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &vf610_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = vf610_adc_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(vf610_adc_iio_channels);
ret = clk_prepare_enable(info->clk);
if (ret) {
dev_err(&pdev->dev,
"Could not prepare or enable the clock.\n");
goto error_adc_clk_enable;
}
vf610_adc_cfg_init(info);
vf610_adc_hw_init(info);
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "Couldn't register the device.\n");
goto error_iio_device_register;
}
return 0;
error_iio_device_register:
clk_disable_unprepare(info->clk);
error_adc_clk_enable:
regulator_disable(info->vref);
return ret;
}
static int vf610_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct vf610_adc *info = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(info->vref);
clk_disable_unprepare(info->clk);
return 0;
}
static int vf610_adc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct vf610_adc *info = iio_priv(indio_dev);
int hc_cfg;
hc_cfg = readl(info->regs + VF610_REG_ADC_HC0);
hc_cfg |= VF610_ADC_CONV_DISABLE;
writel(hc_cfg, info->regs + VF610_REG_ADC_HC0);
clk_disable_unprepare(info->clk);
regulator_disable(info->vref);
return 0;
}
static int vf610_adc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct vf610_adc *info = iio_priv(indio_dev);
int ret;
ret = regulator_enable(info->vref);
if (ret)
return ret;
ret = clk_prepare_enable(info->clk);
if (ret)
goto disable_reg;
vf610_adc_hw_init(info);
return 0;
disable_reg:
regulator_disable(info->vref);
return ret;
}
