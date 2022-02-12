static struct atmel_pdmic_pdata *atmel_pdmic_dt_init(struct device *dev)
{
struct device_node *np = dev->of_node;
struct atmel_pdmic_pdata *pdata;
if (!np) {
dev_err(dev, "device node not found\n");
return ERR_PTR(-EINVAL);
}
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return ERR_PTR(-ENOMEM);
if (of_property_read_string(np, "atmel,model", &pdata->card_name))
pdata->card_name = "PDMIC";
if (of_property_read_u32(np, "atmel,mic-min-freq",
&pdata->mic_min_freq)) {
dev_err(dev, "failed to get mic-min-freq\n");
return ERR_PTR(-EINVAL);
}
if (of_property_read_u32(np, "atmel,mic-max-freq",
&pdata->mic_max_freq)) {
dev_err(dev, "failed to get mic-max-freq\n");
return ERR_PTR(-EINVAL);
}
if (pdata->mic_max_freq < pdata->mic_min_freq) {
dev_err(dev,
"mic-max-freq should not less than mic-min-freq\n");
return ERR_PTR(-EINVAL);
}
if (of_property_read_s32(np, "atmel,mic-offset", &pdata->mic_offset))
pdata->mic_offset = 0;
if (pdata->mic_offset > PDMIC_OFFSET_MAX_VAL) {
dev_warn(dev,
"mic-offset value %d is larger than the max value %d, the max value is specified\n",
pdata->mic_offset, PDMIC_OFFSET_MAX_VAL);
pdata->mic_offset = PDMIC_OFFSET_MAX_VAL;
} else if (pdata->mic_offset < PDMIC_OFFSET_MIN_VAL) {
dev_warn(dev,
"mic-offset value %d is less than the min value %d, the min value is specified\n",
pdata->mic_offset, PDMIC_OFFSET_MIN_VAL);
pdata->mic_offset = PDMIC_OFFSET_MIN_VAL;
}
return pdata;
}
static int atmel_pdmic_cpu_dai_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_pdmic *dd = snd_soc_card_get_drvdata(rtd->card);
int ret;
ret = clk_prepare_enable(dd->gclk);
if (ret)
return ret;
ret = clk_prepare_enable(dd->pclk);
if (ret)
return ret;
regmap_write(dd->regmap, PDMIC_CR, 0);
dd->substream = substream;
regmap_write(dd->regmap, PDMIC_IER, PDMIC_IER_OVRE);
return 0;
}
static void atmel_pdmic_cpu_dai_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_pdmic *dd = snd_soc_card_get_drvdata(rtd->card);
regmap_write(dd->regmap, PDMIC_IDR, PDMIC_IDR_OVRE);
clk_disable_unprepare(dd->gclk);
clk_disable_unprepare(dd->pclk);
}
static int atmel_pdmic_cpu_dai_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *cpu_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_pdmic *dd = snd_soc_card_get_drvdata(rtd->card);
u32 val;
return regmap_read(dd->regmap, PDMIC_CDR, &val);
}
static int
atmel_pdmic_platform_configure_dma(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct dma_slave_config *slave_config)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_pdmic *dd = snd_soc_card_get_drvdata(rtd->card);
int ret;
ret = snd_hwparams_to_dma_slave_config(substream, params,
slave_config);
if (ret) {
dev_err(rtd->platform->dev,
"hw params to dma slave configure failed\n");
return ret;
}
slave_config->src_addr = dd->phy_base + PDMIC_CDR;
slave_config->src_maxburst = 1;
slave_config->dst_maxburst = 1;
return 0;
}
int pdmic_get_mic_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
unsigned int dgain_val, scale_val;
int i;
dgain_val = (snd_soc_read(codec, PDMIC_DSPR1) & PDMIC_DSPR1_DGAIN_MASK)
>> PDMIC_DSPR1_DGAIN_SHIFT;
scale_val = (snd_soc_read(codec, PDMIC_DSPR0) & PDMIC_DSPR0_SCALE_MASK)
>> PDMIC_DSPR0_SCALE_SHIFT;
for (i = 0; i < ARRAY_SIZE(mic_gain_table); i++) {
if ((mic_gain_table[i].dgain == dgain_val) &&
(mic_gain_table[i].scale == scale_val))
ucontrol->value.integer.value[0] = i;
}
return 0;
}
static int pdmic_put_mic_volsw(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
int max = mc->max;
unsigned int val;
int ret;
val = ucontrol->value.integer.value[0];
if (val > max)
return -EINVAL;
ret = snd_soc_update_bits(codec, PDMIC_DSPR1, PDMIC_DSPR1_DGAIN_MASK,
mic_gain_table[val].dgain << PDMIC_DSPR1_DGAIN_SHIFT);
if (ret < 0)
return ret;
ret = snd_soc_update_bits(codec, PDMIC_DSPR0, PDMIC_DSPR0_SCALE_MASK,
mic_gain_table[val].scale << PDMIC_DSPR0_SCALE_SHIFT);
if (ret < 0)
return ret;
return 0;
}
static int atmel_pdmic_codec_probe(struct snd_soc_codec *codec)
{
struct snd_soc_card *card = snd_soc_codec_get_drvdata(codec);
struct atmel_pdmic *dd = snd_soc_card_get_drvdata(card);
snd_soc_update_bits(codec, PDMIC_DSPR1, PDMIC_DSPR1_OFFSET_MASK,
(u32)(dd->pdata->mic_offset << PDMIC_DSPR1_OFFSET_SHIFT));
return 0;
}
static int
atmel_pdmic_codec_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *codec_dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct atmel_pdmic *dd = snd_soc_card_get_drvdata(rtd->card);
struct snd_soc_codec *codec = codec_dai->codec;
unsigned int rate_min = substream->runtime->hw.rate_min;
unsigned int rate_max = substream->runtime->hw.rate_max;
int fs = params_rate(params);
int bits = params_width(params);
unsigned long pclk_rate, gclk_rate;
unsigned int f_pdmic;
u32 mr_val, dspr0_val, pclk_prescal, gclk_prescal;
if (params_channels(params) != 1) {
dev_err(codec->dev,
"only supports one channel\n");
return -EINVAL;
}
if ((fs < rate_min) || (fs > rate_max)) {
dev_err(codec->dev,
"sample rate is %dHz, min rate is %dHz, max rate is %dHz\n",
fs, rate_min, rate_max);
return -EINVAL;
}
switch (bits) {
case 16:
dspr0_val = (PDMIC_DSPR0_SIZE_16_BITS
<< PDMIC_DSPR0_SIZE_SHIFT);
break;
case 32:
dspr0_val = (PDMIC_DSPR0_SIZE_32_BITS
<< PDMIC_DSPR0_SIZE_SHIFT);
break;
default:
return -EINVAL;
}
if ((fs << 7) > (rate_max << 6)) {
f_pdmic = fs << 6;
dspr0_val |= PDMIC_DSPR0_OSR_64 << PDMIC_DSPR0_OSR_SHIFT;
} else {
f_pdmic = fs << 7;
dspr0_val |= PDMIC_DSPR0_OSR_128 << PDMIC_DSPR0_OSR_SHIFT;
}
pclk_rate = clk_get_rate(dd->pclk);
gclk_rate = clk_get_rate(dd->gclk);
pclk_prescal = (u32)(pclk_rate/(f_pdmic << 1)) - 1;
gclk_prescal = (u32)(gclk_rate/(f_pdmic << 1)) - 1;
if ((pclk_prescal > PDMIC_MR_PRESCAL_MAX_VAL) ||
(gclk_rate/((gclk_prescal + 1) << 1) <
pclk_rate/((pclk_prescal + 1) << 1))) {
mr_val = gclk_prescal << PDMIC_MR_PRESCAL_SHIFT;
mr_val |= PDMIC_MR_CLKS_GCK << PDMIC_MR_CLKS_SHIFT;
} else {
mr_val = pclk_prescal << PDMIC_MR_PRESCAL_SHIFT;
mr_val |= PDMIC_MR_CLKS_PCK << PDMIC_MR_CLKS_SHIFT;
}
snd_soc_update_bits(codec, PDMIC_MR,
PDMIC_MR_PRESCAL_MASK | PDMIC_MR_CLKS_MASK, mr_val);
snd_soc_update_bits(codec, PDMIC_DSPR0,
PDMIC_DSPR0_OSR_MASK | PDMIC_DSPR0_SIZE_MASK, dspr0_val);
return 0;
}
static int atmel_pdmic_codec_dai_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *codec_dai)
{
struct snd_soc_codec *codec = codec_dai->codec;
snd_soc_update_bits(codec, PDMIC_CR, PDMIC_CR_ENPDM_MASK,
PDMIC_CR_ENPDM_DIS << PDMIC_CR_ENPDM_SHIFT);
return 0;
}
static int atmel_pdmic_codec_dai_trigger(struct snd_pcm_substream *substream,
int cmd, struct snd_soc_dai *codec_dai)
{
struct snd_soc_codec *codec = codec_dai->codec;
u32 val;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
val = PDMIC_CR_ENPDM_EN << PDMIC_CR_ENPDM_SHIFT;
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
val = PDMIC_CR_ENPDM_DIS << PDMIC_CR_ENPDM_SHIFT;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, PDMIC_CR, PDMIC_CR_ENPDM_MASK, val);
return 0;
}
static int atmel_pdmic_asoc_card_init(struct device *dev,
struct snd_soc_card *card)
{
struct snd_soc_dai_link *dai_link;
struct atmel_pdmic *dd = snd_soc_card_get_drvdata(card);
dai_link = devm_kzalloc(dev, sizeof(*dai_link), GFP_KERNEL);
if (!dai_link)
return -ENOMEM;
dai_link->name = "PDMIC";
dai_link->stream_name = "PDMIC PCM";
dai_link->codec_dai_name = ATMEL_PDMIC_CODEC_DAI_NAME;
dai_link->cpu_dai_name = dev_name(dev);
dai_link->codec_name = dev_name(dev);
dai_link->platform_name = dev_name(dev);
card->dai_link = dai_link;
card->num_links = 1;
card->name = dd->pdata->card_name;
card->dev = dev;
return 0;
}
static void atmel_pdmic_get_sample_rate(struct atmel_pdmic *dd,
unsigned int *rate_min, unsigned int *rate_max)
{
u32 mic_min_freq = dd->pdata->mic_min_freq;
u32 mic_max_freq = dd->pdata->mic_max_freq;
u32 clk_max_rate = (u32)(clk_get_rate(dd->pclk) >> 1);
u32 clk_min_rate = (u32)(clk_get_rate(dd->gclk) >> 8);
if (mic_max_freq > clk_max_rate)
mic_max_freq = clk_max_rate;
if (mic_min_freq < clk_min_rate)
mic_min_freq = clk_min_rate;
*rate_min = DIV_ROUND_CLOSEST(mic_min_freq, 128);
*rate_max = mic_max_freq >> 6;
}
static irqreturn_t atmel_pdmic_interrupt(int irq, void *dev_id)
{
struct atmel_pdmic *dd = (struct atmel_pdmic *)dev_id;
u32 pdmic_isr;
irqreturn_t ret = IRQ_NONE;
regmap_read(dd->regmap, PDMIC_ISR, &pdmic_isr);
if (pdmic_isr & PDMIC_ISR_OVRE) {
regmap_update_bits(dd->regmap, PDMIC_CR, PDMIC_CR_ENPDM_MASK,
PDMIC_CR_ENPDM_DIS << PDMIC_CR_ENPDM_SHIFT);
snd_pcm_stop_xrun(dd->substream);
ret = IRQ_HANDLED;
}
return ret;
}
static int atmel_pdmic_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct atmel_pdmic *dd;
struct resource *res;
void __iomem *io_base;
const struct atmel_pdmic_pdata *pdata;
struct snd_soc_card *card;
unsigned int rate_min, rate_max;
int ret;
pdata = atmel_pdmic_dt_init(dev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
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
dev_err(dev, "failed to get GCK: %d\n", ret);
return ret;
}
ret = clk_set_rate(dd->gclk, clk_get_rate(dd->pclk)/3);
if (ret) {
dev_err(dev, "failed to set GCK clock rate: %d\n", ret);
return ret;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "no memory resource\n");
return -ENXIO;
}
io_base = devm_ioremap_resource(dev, res);
if (IS_ERR(io_base)) {
ret = PTR_ERR(io_base);
dev_err(dev, "failed to remap register memory: %d\n", ret);
return ret;
}
dd->phy_base = res->start;
dd->regmap = devm_regmap_init_mmio(dev, io_base,
&atmel_pdmic_regmap_config);
if (IS_ERR(dd->regmap)) {
ret = PTR_ERR(dd->regmap);
dev_err(dev, "failed to init register map: %d\n", ret);
return ret;
}
ret = devm_request_irq(dev, dd->irq, atmel_pdmic_interrupt, 0,
"PDMIC", (void *)dd);
if (ret < 0) {
dev_err(dev, "can't register ISR for IRQ %u (ret=%i)\n",
dd->irq, ret);
return ret;
}
atmel_pdmic_get_sample_rate(dd, &rate_min, &rate_max);
atmel_pdmic_cpu_dai.capture.rate_min = rate_min;
atmel_pdmic_cpu_dai.capture.rate_max = rate_max;
ret = devm_snd_soc_register_component(dev,
&atmel_pdmic_cpu_dai_component,
&atmel_pdmic_cpu_dai, 1);
if (ret) {
dev_err(dev, "could not register CPU DAI: %d\n", ret);
return ret;
}
ret = devm_snd_dmaengine_pcm_register(dev,
&atmel_pdmic_dmaengine_pcm_config,
0);
if (ret) {
dev_err(dev, "could not register platform: %d\n", ret);
return ret;
}
atmel_pdmic_codec_dai.capture.rate_min = rate_min;
atmel_pdmic_codec_dai.capture.rate_max = rate_max;
ret = snd_soc_register_codec(dev, &soc_codec_dev_pdmic,
&atmel_pdmic_codec_dai, 1);
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
ret = atmel_pdmic_asoc_card_init(dev, card);
if (ret) {
dev_err(dev, "failed to init sound card: %d\n", ret);
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
static int atmel_pdmic_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
