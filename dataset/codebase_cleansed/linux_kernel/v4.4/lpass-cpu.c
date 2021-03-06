static int lpass_cpu_daiops_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq, int dir)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
int ret;
if (IS_ERR(drvdata->mi2s_osr_clk[dai->driver->id]))
return 0;
ret = clk_set_rate(drvdata->mi2s_osr_clk[dai->driver->id], freq);
if (ret)
dev_err(dai->dev, "%s() error setting mi2s osrclk to %u: %d\n",
__func__, freq, ret);
return ret;
}
static int lpass_cpu_daiops_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
int ret;
if (!IS_ERR(drvdata->mi2s_osr_clk[dai->driver->id])) {
ret = clk_prepare_enable(
drvdata->mi2s_osr_clk[dai->driver->id]);
if (ret) {
dev_err(dai->dev, "%s() error in enabling mi2s osr clk: %d\n",
__func__, ret);
return ret;
}
}
ret = clk_prepare_enable(drvdata->mi2s_bit_clk[dai->driver->id]);
if (ret) {
dev_err(dai->dev, "%s() error in enabling mi2s bit clk: %d\n",
__func__, ret);
if (!IS_ERR(drvdata->mi2s_osr_clk[dai->driver->id]))
clk_disable_unprepare(
drvdata->mi2s_osr_clk[dai->driver->id]);
return ret;
}
return 0;
}
static void lpass_cpu_daiops_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
clk_disable_unprepare(drvdata->mi2s_bit_clk[dai->driver->id]);
if (!IS_ERR(drvdata->mi2s_osr_clk[dai->driver->id]))
clk_disable_unprepare(drvdata->mi2s_osr_clk[dai->driver->id]);
}
static int lpass_cpu_daiops_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
snd_pcm_format_t format = params_format(params);
unsigned int channels = params_channels(params);
unsigned int rate = params_rate(params);
unsigned int regval;
int bitwidth, ret;
bitwidth = snd_pcm_format_width(format);
if (bitwidth < 0) {
dev_err(dai->dev, "%s() invalid bit width given: %d\n",
__func__, bitwidth);
return bitwidth;
}
regval = LPAIF_I2SCTL_LOOPBACK_DISABLE |
LPAIF_I2SCTL_WSSRC_INTERNAL;
switch (bitwidth) {
case 16:
regval |= LPAIF_I2SCTL_BITWIDTH_16;
break;
case 24:
regval |= LPAIF_I2SCTL_BITWIDTH_24;
break;
case 32:
regval |= LPAIF_I2SCTL_BITWIDTH_32;
break;
default:
dev_err(dai->dev, "%s() invalid bitwidth given: %d\n",
__func__, bitwidth);
return -EINVAL;
}
switch (channels) {
case 1:
regval |= LPAIF_I2SCTL_SPKMODE_SD0;
regval |= LPAIF_I2SCTL_SPKMONO_MONO;
break;
case 2:
regval |= LPAIF_I2SCTL_SPKMODE_SD0;
regval |= LPAIF_I2SCTL_SPKMONO_STEREO;
break;
case 4:
regval |= LPAIF_I2SCTL_SPKMODE_QUAD01;
regval |= LPAIF_I2SCTL_SPKMONO_STEREO;
break;
case 6:
regval |= LPAIF_I2SCTL_SPKMODE_6CH;
regval |= LPAIF_I2SCTL_SPKMONO_STEREO;
break;
case 8:
regval |= LPAIF_I2SCTL_SPKMODE_8CH;
regval |= LPAIF_I2SCTL_SPKMONO_STEREO;
break;
default:
dev_err(dai->dev, "%s() invalid channels given: %u\n",
__func__, channels);
return -EINVAL;
}
ret = regmap_write(drvdata->lpaif_map,
LPAIF_I2SCTL_REG(drvdata->variant, dai->driver->id),
regval);
if (ret) {
dev_err(dai->dev, "%s() error writing to i2sctl reg: %d\n",
__func__, ret);
return ret;
}
ret = clk_set_rate(drvdata->mi2s_bit_clk[dai->driver->id],
rate * bitwidth * 2);
if (ret) {
dev_err(dai->dev, "%s() error setting mi2s bitclk to %u: %d\n",
__func__, rate * bitwidth * 2, ret);
return ret;
}
return 0;
}
static int lpass_cpu_daiops_hw_free(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
int ret;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_I2SCTL_REG(drvdata->variant, dai->driver->id),
0);
if (ret)
dev_err(dai->dev, "%s() error writing to i2sctl reg: %d\n",
__func__, ret);
return ret;
}
static int lpass_cpu_daiops_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
int ret;
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_I2SCTL_REG(drvdata->variant, dai->driver->id),
LPAIF_I2SCTL_SPKEN_MASK, LPAIF_I2SCTL_SPKEN_ENABLE);
if (ret)
dev_err(dai->dev, "%s() error writing to i2sctl reg: %d\n",
__func__, ret);
return ret;
}
static int lpass_cpu_daiops_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *dai)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
int ret = -EINVAL;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_I2SCTL_REG(drvdata->variant,
dai->driver->id),
LPAIF_I2SCTL_SPKEN_MASK,
LPAIF_I2SCTL_SPKEN_ENABLE);
if (ret)
dev_err(dai->dev, "%s() error writing to i2sctl reg: %d\n",
__func__, ret);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
ret = regmap_update_bits(drvdata->lpaif_map,
LPAIF_I2SCTL_REG(drvdata->variant,
dai->driver->id),
LPAIF_I2SCTL_SPKEN_MASK,
LPAIF_I2SCTL_SPKEN_DISABLE);
if (ret)
dev_err(dai->dev, "%s() error writing to i2sctl reg: %d\n",
__func__, ret);
break;
}
return ret;
}
int asoc_qcom_lpass_cpu_dai_probe(struct snd_soc_dai *dai)
{
struct lpass_data *drvdata = snd_soc_dai_get_drvdata(dai);
int ret;
ret = regmap_write(drvdata->lpaif_map,
LPAIF_I2SCTL_REG(drvdata->variant, dai->driver->id), 0);
if (ret)
dev_err(dai->dev, "%s() error writing to i2sctl reg: %d\n",
__func__, ret);
return ret;
}
static bool lpass_cpu_regmap_writeable(struct device *dev, unsigned int reg)
{
struct lpass_data *drvdata = dev_get_drvdata(dev);
struct lpass_variant *v = drvdata->variant;
int i;
for (i = 0; i < v->i2s_ports; ++i)
if (reg == LPAIF_I2SCTL_REG(v, i))
return true;
for (i = 0; i < v->irq_ports; ++i) {
if (reg == LPAIF_IRQEN_REG(v, i))
return true;
if (reg == LPAIF_IRQCLEAR_REG(v, i))
return true;
}
for (i = 0; i < v->rdma_channels; ++i) {
if (reg == LPAIF_RDMACTL_REG(v, i))
return true;
if (reg == LPAIF_RDMABASE_REG(v, i))
return true;
if (reg == LPAIF_RDMABUFF_REG(v, i))
return true;
if (reg == LPAIF_RDMAPER_REG(v, i))
return true;
}
return false;
}
static bool lpass_cpu_regmap_readable(struct device *dev, unsigned int reg)
{
struct lpass_data *drvdata = dev_get_drvdata(dev);
struct lpass_variant *v = drvdata->variant;
int i;
for (i = 0; i < v->i2s_ports; ++i)
if (reg == LPAIF_I2SCTL_REG(v, i))
return true;
for (i = 0; i < v->irq_ports; ++i) {
if (reg == LPAIF_IRQEN_REG(v, i))
return true;
if (reg == LPAIF_IRQSTAT_REG(v, i))
return true;
}
for (i = 0; i < v->rdma_channels; ++i) {
if (reg == LPAIF_RDMACTL_REG(v, i))
return true;
if (reg == LPAIF_RDMABASE_REG(v, i))
return true;
if (reg == LPAIF_RDMABUFF_REG(v, i))
return true;
if (reg == LPAIF_RDMACURR_REG(v, i))
return true;
if (reg == LPAIF_RDMAPER_REG(v, i))
return true;
}
return false;
}
static bool lpass_cpu_regmap_volatile(struct device *dev, unsigned int reg)
{
struct lpass_data *drvdata = dev_get_drvdata(dev);
struct lpass_variant *v = drvdata->variant;
int i;
for (i = 0; i < v->irq_ports; ++i)
if (reg == LPAIF_IRQSTAT_REG(v, i))
return true;
for (i = 0; i < v->rdma_channels; ++i)
if (reg == LPAIF_RDMACURR_REG(v, i))
return true;
return false;
}
int asoc_qcom_lpass_cpu_platform_probe(struct platform_device *pdev)
{
struct lpass_data *drvdata;
struct device_node *dsp_of_node;
struct resource *res;
struct lpass_variant *variant;
struct device *dev = &pdev->dev;
const struct of_device_id *match;
char clk_name[16];
int ret, i, dai_id;
dsp_of_node = of_parse_phandle(pdev->dev.of_node, "qcom,adsp", 0);
if (dsp_of_node) {
dev_err(&pdev->dev, "%s() DSP exists and holds audio resources\n",
__func__);
return -EBUSY;
}
drvdata = devm_kzalloc(&pdev->dev, sizeof(struct lpass_data),
GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
platform_set_drvdata(pdev, drvdata);
match = of_match_device(dev->driver->of_match_table, dev);
if (!match || !match->data)
return -EINVAL;
drvdata->variant = (struct lpass_variant *)match->data;
variant = drvdata->variant;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "lpass-lpaif");
drvdata->lpaif = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR((void const __force *)drvdata->lpaif)) {
dev_err(&pdev->dev, "%s() error mapping reg resource: %ld\n",
__func__,
PTR_ERR((void const __force *)drvdata->lpaif));
return PTR_ERR((void const __force *)drvdata->lpaif);
}
lpass_cpu_regmap_config.max_register = LPAIF_RDMAPER_REG(variant,
variant->rdma_channels);
drvdata->lpaif_map = devm_regmap_init_mmio(&pdev->dev, drvdata->lpaif,
&lpass_cpu_regmap_config);
if (IS_ERR(drvdata->lpaif_map)) {
dev_err(&pdev->dev, "%s() error initializing regmap: %ld\n",
__func__, PTR_ERR(drvdata->lpaif_map));
return PTR_ERR(drvdata->lpaif_map);
}
if (variant->init)
variant->init(pdev);
for (i = 0; i < variant->num_dai; i++) {
dai_id = variant->dai_driver[i].id;
if (variant->num_dai > 1)
sprintf(clk_name, "mi2s-osr-clk%d", i);
else
sprintf(clk_name, "mi2s-osr-clk");
drvdata->mi2s_osr_clk[dai_id] = devm_clk_get(&pdev->dev,
clk_name);
if (IS_ERR(drvdata->mi2s_osr_clk[dai_id])) {
dev_warn(&pdev->dev,
"%s() error getting mi2s-osr-clk: %ld\n",
__func__,
PTR_ERR(drvdata->mi2s_osr_clk[dai_id]));
}
if (variant->num_dai > 1)
sprintf(clk_name, "mi2s-bit-clk%d", i);
else
sprintf(clk_name, "mi2s-bit-clk");
drvdata->mi2s_bit_clk[dai_id] = devm_clk_get(&pdev->dev,
clk_name);
if (IS_ERR(drvdata->mi2s_bit_clk[dai_id])) {
dev_err(&pdev->dev,
"%s() error getting mi2s-bit-clk: %ld\n",
__func__,
PTR_ERR(drvdata->mi2s_bit_clk[dai_id]));
return PTR_ERR(drvdata->mi2s_bit_clk[dai_id]);
}
}
drvdata->ahbix_clk = devm_clk_get(&pdev->dev, "ahbix-clk");
if (IS_ERR(drvdata->ahbix_clk)) {
dev_err(&pdev->dev, "%s() error getting ahbix-clk: %ld\n",
__func__, PTR_ERR(drvdata->ahbix_clk));
return PTR_ERR(drvdata->ahbix_clk);
}
ret = clk_set_rate(drvdata->ahbix_clk, LPASS_AHBIX_CLOCK_FREQUENCY);
if (ret) {
dev_err(&pdev->dev, "%s() error setting rate on ahbix_clk: %d\n",
__func__, ret);
return ret;
}
dev_dbg(&pdev->dev, "%s() set ahbix_clk rate to %lu\n", __func__,
clk_get_rate(drvdata->ahbix_clk));
ret = clk_prepare_enable(drvdata->ahbix_clk);
if (ret) {
dev_err(&pdev->dev, "%s() error enabling ahbix_clk: %d\n",
__func__, ret);
return ret;
}
ret = devm_snd_soc_register_component(&pdev->dev,
&lpass_cpu_comp_driver,
variant->dai_driver,
variant->num_dai);
if (ret) {
dev_err(&pdev->dev, "%s() error registering cpu driver: %d\n",
__func__, ret);
goto err_clk;
}
ret = asoc_qcom_lpass_platform_register(pdev);
if (ret) {
dev_err(&pdev->dev, "%s() error registering platform driver: %d\n",
__func__, ret);
goto err_clk;
}
return 0;
err_clk:
clk_disable_unprepare(drvdata->ahbix_clk);
return ret;
}
int asoc_qcom_lpass_cpu_platform_remove(struct platform_device *pdev)
{
struct lpass_data *drvdata = platform_get_drvdata(pdev);
if (drvdata->variant->exit)
drvdata->variant->exit(pdev);
clk_disable_unprepare(drvdata->ahbix_clk);
return 0;
}
