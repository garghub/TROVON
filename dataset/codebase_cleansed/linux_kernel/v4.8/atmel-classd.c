static struct atmel_classd_pdata *atmel_classd_dt_init(struct device *dev)
{
struct device_node *np = dev->of_node;
struct atmel_classd_pdata *pdata;
const char *pwm_type;
int ret;
if (!np) {
dev_err(dev, "device node not found\n");
return ERR_PTR(-EINVAL);
}
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
ret = of_property_read_string(np, "atmel,pwm-type", &pwm_type);
if ((ret == 0) && (strcmp(pwm_type, "diff") == 0))
pdata->pwm_type = CLASSD_MR_PWMTYP_DIFF;
else
pdata->pwm_type = CLASSD_MR_PWMTYP_SINGLE;
ret = of_property_read_u32(np,
"atmel,non-overlap-time", &pdata->non_overlap_time);
if (ret)
pdata->non_overlap_enable = false;
else
pdata->non_overlap_enable = true;
ret = of_property_read_string(np, "atmel,model", &pdata->card_name);
if (ret)
pdata->card_name = "CLASSD";
return pdata;
}
static inline struct atmel_classd_pdata *
atmel_classd_dt_init(struct device *dev)
{
return ERR_PTR(-EINVAL);
}
static int atmel_classd_cpu_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_classd *dd = snd_soc_card_get_drvdata(rtd->card);
regmap_write(dd->regmap, CLASSD_THR, 0x0);
return clk_prepare_enable(dd->pclk);
}
static void atmel_classd_cpu_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_classd *dd = snd_soc_card_get_drvdata(rtd->card);
clk_disable_unprepare(dd->pclk);
}
static int
atmel_classd_platform_configure_dma(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct dma_slave_config *slave_config)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_classd *dd = snd_soc_card_get_drvdata(rtd->card);
if (params_physical_width(params) != 16) {
dev_err(rtd->platform->dev,
"only supports 16-bit audio data\n");
return -EINVAL;
}
if (params_channels(params) == 1)
slave_config->dst_addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
else
slave_config->dst_addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
slave_config->direction = DMA_MEM_TO_DEV;
slave_config->dst_addr = dd->phy_base + CLASSD_THR;
slave_config->dst_maxburst = 1;
slave_config->src_maxburst = 1;
slave_config->device_fc = false;
return 0;
}
static int atmel_classd_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_card *card = snd_soc_codec_get_drvdata(codec);
struct atmel_classd *dd = snd_soc_card_get_drvdata(card);
const struct atmel_classd_pdata *pdata = dd->pdata;
u32 mask, val;
mask = CLASSD_MR_PWMTYP_MASK;
val = pdata->pwm_type << CLASSD_MR_PWMTYP_SHIFT;
mask |= CLASSD_MR_NON_OVERLAP_MASK;
if (pdata->non_overlap_enable) {
val |= (CLASSD_MR_NON_OVERLAP_EN
<< CLASSD_MR_NON_OVERLAP_SHIFT);
mask |= CLASSD_MR_NOVR_VAL_MASK;
switch (pdata->non_overlap_time) {
case 5:
val |= (CLASSD_MR_NOVR_VAL_5NS
<< CLASSD_MR_NOVR_VAL_SHIFT);
break;
case 10:
val |= (CLASSD_MR_NOVR_VAL_10NS
<< CLASSD_MR_NOVR_VAL_SHIFT);
break;
case 15:
val |= (CLASSD_MR_NOVR_VAL_15NS
<< CLASSD_MR_NOVR_VAL_SHIFT);
break;
case 20:
val |= (CLASSD_MR_NOVR_VAL_20NS
<< CLASSD_MR_NOVR_VAL_SHIFT);
break;
default:
val |= (CLASSD_MR_NOVR_VAL_10NS
<< CLASSD_MR_NOVR_VAL_SHIFT);
dev_warn(codec->dev,
"non-overlapping value %d is invalid, the default value 10 is specified\n",
pdata->non_overlap_time);
break;
}
}
snd_soc_update_bits(codec, CLASSD_MR, mask, val);
dev_info(codec->dev,
"PWM modulation type is %s, non-overlapping is %s\n",
pwm_type[pdata->pwm_type],
pdata->non_overlap_enable?"enabled":"disabled");
return 0;
}
static struct regmap *atmel_classd_codec_get_remap(struct device *dev)
{
return dev_get_regmap(dev, NULL);
}
static int atmel_classd_codec_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *codec_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_classd *dd = snd_soc_card_get_drvdata(rtd->card);
int ret;
ret = clk_prepare_enable(dd->aclk);
if (ret)
return ret;
return clk_prepare_enable(dd->gclk);
}
static int atmel_classd_codec_dai_digital_mute(struct snd_soc_dai *codec_dai,
int mute)
{
struct snd_soc_codec *codec = codec_dai->codec;
u32 mask, val;
mask = CLASSD_MR_LMUTE_MASK | CLASSD_MR_RMUTE_MASK;
if (mute)
val = mask;
else
val = 0;
snd_soc_update_bits(codec, CLASSD_MR, mask, val);
return 0;
}
static int
atmel_classd_codec_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *codec_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_classd *dd = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_codec *codec = codec_dai->codec;
int fs;
int i, best, best_val, cur_val, ret;
u32 mask, val;
fs = params_rate(params);
best = 0;
best_val = abs(fs - sample_rates[0].rate);
for (i = 1; i < ARRAY_SIZE(sample_rates); i++) {
cur_val = abs(fs - sample_rates[i].rate);
if (cur_val < best_val) {
best = i;
best_val = cur_val;
}
}
dev_dbg(codec->dev,
"Selected SAMPLE_RATE of %dHz, ACLK_RATE of %ldHz\n",
sample_rates[best].rate, sample_rates[best].aclk_rate);
clk_disable_unprepare(dd->gclk);
clk_disable_unprepare(dd->aclk);
ret = clk_set_rate(dd->aclk, sample_rates[best].aclk_rate);
if (ret)
return ret;
mask = CLASSD_INTPMR_DSP_CLK_FREQ_MASK | CLASSD_INTPMR_FRAME_MASK;
val = (sample_rates[best].dsp_clk << CLASSD_INTPMR_DSP_CLK_FREQ_SHIFT)
| (sample_rates[best].sample_rate << CLASSD_INTPMR_FRAME_SHIFT);
snd_soc_update_bits(codec, CLASSD_INTPMR, mask, val);
ret = clk_prepare_enable(dd->aclk);
if (ret)
return ret;
return clk_prepare_enable(dd->gclk);
}
static void
atmel_classd_codec_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *codec_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_classd *dd = snd_soc_card_get_drvdata(rtd->card);
clk_disable_unprepare(dd->gclk);
clk_disable_unprepare(dd->aclk);
}
static int atmel_classd_codec_dai_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *codec_dai)
{
struct snd_soc_codec *codec = codec_dai->codec;
snd_soc_update_bits(codec, CLASSD_MR,
CLASSD_MR_LEN_MASK | CLASSD_MR_REN_MASK,
(CLASSD_MR_LEN_DIS << CLASSD_MR_LEN_SHIFT)
|(CLASSD_MR_REN_DIS << CLASSD_MR_REN_SHIFT));
return 0;
}
static int atmel_classd_codec_dai_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *codec_dai)
{
struct snd_soc_codec *codec = codec_dai->codec;
u32 mask, val;
mask = CLASSD_MR_LEN_MASK | CLASSD_MR_REN_MASK;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
val = mask;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
val = (CLASSD_MR_LEN_DIS << CLASSD_MR_LEN_SHIFT)
| (CLASSD_MR_REN_DIS << CLASSD_MR_REN_SHIFT);
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, CLASSD_MR, mask, val);
return 0;
}
static int atmel_classd_asoc_card_init(struct device *dev,
struct snd_soc_card *card)
{
struct snd_soc_dai_link *dai_link;
struct atmel_classd *dd = snd_soc_card_get_drvdata(card);
dai_link = devm_kzalloc(dev, sizeof(*dai_link), GFP_KERNEL);
if (!dai_link)
return -ENOMEM;
dai_link->name = "CLASSD";
dai_link->stream_name = "CLASSD PCM";
dai_link->codec_dai_name = ATMEL_CLASSD_CODEC_DAI_NAME;
dai_link->cpu_dai_name = dev_name(dev);
dai_link->codec_name = dev_name(dev);
dai_link->platform_name = dev_name(dev);
card->dai_link = dai_link;
card->num_links = 1;
card->name = dd->pdata->card_name;
card->dev = dev;
return 0;
}
static int atmel_classd_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct atmel_classd *dd;
struct resource *res;
void __iomem *io_base;
const struct atmel_classd_pdata *pdata;
struct snd_soc_card *card;
int ret;
pdata = dev_get_platdata(dev);
if (!pdata) {
pdata = atmel_classd_dt_init(dev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
}
dd = devm_kzalloc(dev, sizeof(*dd), GFP_KERNEL);
if (!dd)
return -ENOMEM;
dd->pdata = pdata;
dd->irq = platform_get_irq(pdev, 0);
if (dd->irq < 0) {
ret = dd->irq;
dev_err(dev, "failed to could not get irq: %d\n", ret);
return ret;
}
dd->pclk = devm_clk_get(dev, "pclk");
if (IS_ERR(dd->pclk)) {
ret = PTR_ERR(dd->pclk);
dev_err(dev, "failed to get peripheral clock: %d\n", ret);
return ret;
}
dd->gclk = devm_clk_get(dev, "gclk");
if (IS_ERR(dd->gclk)) {
ret = PTR_ERR(dd->gclk);
dev_err(dev, "failed to get GCK clock: %d\n", ret);
return ret;
}
dd->aclk = devm_clk_get(dev, "aclk");
if (IS_ERR(dd->aclk)) {
ret = PTR_ERR(dd->aclk);
dev_err(dev, "failed to get audio clock: %d\n", ret);
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
io_base = devm_ioremap_resource(dev, res);
if (IS_ERR(io_base)) {
ret = PTR_ERR(io_base);
dev_err(dev, "failed to remap register memory: %d\n", ret);
return ret;
}
dd->phy_base = res->start;
dd->regmap = devm_regmap_init_mmio(dev, io_base,
&atmel_classd_regmap_config);
if (IS_ERR(dd->regmap)) {
ret = PTR_ERR(dd->regmap);
dev_err(dev, "failed to init register map: %d\n", ret);
return ret;
}
ret = devm_snd_soc_register_component(dev,
&atmel_classd_cpu_dai_component,
&atmel_classd_cpu_dai, 1);
if (ret) {
dev_err(dev, "could not register CPU DAI: %d\n", ret);
return ret;
}
ret = devm_snd_dmaengine_pcm_register(dev,
&atmel_classd_dmaengine_pcm_config,
0);
if (ret) {
dev_err(dev, "could not register platform: %d\n", ret);
return ret;
}
ret = snd_soc_register_codec(dev, &soc_codec_dev_classd,
&atmel_classd_codec_dai, 1);
if (ret) {
dev_err(dev, "could not register codec: %d\n", ret);
return ret;
}
card = devm_kzalloc(dev, sizeof(*card), GFP_KERNEL);
if (!card) {
ret = -ENOMEM;
goto unregister_codec;
}
snd_soc_card_set_drvdata(card, dd);
platform_set_drvdata(pdev, card);
ret = atmel_classd_asoc_card_init(dev, card);
if (ret) {
dev_err(dev, "failed to init sound card\n");
goto unregister_codec;
}
ret = devm_snd_soc_register_card(dev, card);
if (ret) {
dev_err(dev, "failed to register sound card: %d\n", ret);
goto unregister_codec;
}
return 0;
unregister_codec:
snd_soc_unregister_codec(dev);
return ret;
}
static int atmel_classd_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
