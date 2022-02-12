static void sun4i_codec_start_playback(struct sun4i_codec *scodec)
{
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_FIFO_FLUSH),
BIT(SUN4I_CODEC_DAC_FIFOC_FIFO_FLUSH));
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_DAC_DRQ_EN),
BIT(SUN4I_CODEC_DAC_FIFOC_DAC_DRQ_EN));
}
static void sun4i_codec_stop_playback(struct sun4i_codec *scodec)
{
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_DAC_DRQ_EN),
0);
}
static void sun4i_codec_start_capture(struct sun4i_codec *scodec)
{
regmap_field_update_bits(scodec->reg_adc_fifoc,
BIT(SUN4I_CODEC_ADC_FIFOC_ADC_DRQ_EN),
BIT(SUN4I_CODEC_ADC_FIFOC_ADC_DRQ_EN));
}
static void sun4i_codec_stop_capture(struct sun4i_codec *scodec)
{
regmap_field_update_bits(scodec->reg_adc_fifoc,
BIT(SUN4I_CODEC_ADC_FIFOC_ADC_DRQ_EN), 0);
}
static int sun4i_codec_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(rtd->card);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_RESUME:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sun4i_codec_start_playback(scodec);
else
sun4i_codec_start_capture(scodec);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_SUSPEND:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
sun4i_codec_stop_playback(scodec);
else
sun4i_codec_stop_capture(scodec);
break;
default:
return -EINVAL;
}
return 0;
}
static int sun4i_codec_prepare_capture(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(rtd->card);
regmap_field_update_bits(scodec->reg_adc_fifoc,
BIT(SUN4I_CODEC_ADC_FIFOC_FIFO_FLUSH),
BIT(SUN4I_CODEC_ADC_FIFOC_FIFO_FLUSH));
regmap_field_update_bits(scodec->reg_adc_fifoc,
0xf << SUN4I_CODEC_ADC_FIFOC_RX_TRIG_LEVEL,
0x7 << SUN4I_CODEC_ADC_FIFOC_RX_TRIG_LEVEL);
if (of_device_is_compatible(scodec->dev->of_node,
"allwinner,sun4i-a10-codec") ||
of_device_is_compatible(scodec->dev->of_node,
"allwinner,sun7i-a20-codec")) {
regmap_update_bits(scodec->regmap, SUN4I_CODEC_ADC_ACTL,
0x3 << 25,
0x1 << 25);
}
if (of_device_is_compatible(scodec->dev->of_node,
"allwinner,sun7i-a20-codec"))
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_TUNE,
0x3 << 8,
0x1 << 8);
regmap_field_update_bits(scodec->reg_adc_fifoc,
BIT(SUN4I_CODEC_ADC_FIFOC_RX_FIFO_MODE),
BIT(SUN4I_CODEC_ADC_FIFOC_RX_FIFO_MODE));
return 0;
}
static int sun4i_codec_prepare_playback(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(rtd->card);
u32 val;
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_FIFO_FLUSH),
BIT(SUN4I_CODEC_DAC_FIFOC_FIFO_FLUSH));
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
0x3f << SUN4I_CODEC_DAC_FIFOC_TX_TRIG_LEVEL,
0xf << SUN4I_CODEC_DAC_FIFOC_TX_TRIG_LEVEL);
if (substream->runtime->rate > 32000)
val = 0;
else
val = BIT(SUN4I_CODEC_DAC_FIFOC_FIR_VERSION);
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_FIR_VERSION),
val);
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_SEND_LASAT),
0);
return 0;
}
static int sun4i_codec_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
return sun4i_codec_prepare_playback(substream, dai);
return sun4i_codec_prepare_capture(substream, dai);
}
static unsigned long sun4i_codec_get_mod_freq(struct snd_pcm_hw_params *params)
{
unsigned int rate = params_rate(params);
switch (rate) {
case 176400:
case 88200:
case 44100:
case 33075:
case 22050:
case 14700:
case 11025:
case 7350:
return 22579200;
case 192000:
case 96000:
case 48000:
case 32000:
case 24000:
case 16000:
case 12000:
case 8000:
return 24576000;
default:
return 0;
}
}
static int sun4i_codec_get_hw_rate(struct snd_pcm_hw_params *params)
{
unsigned int rate = params_rate(params);
switch (rate) {
case 192000:
case 176400:
return 6;
case 96000:
case 88200:
return 7;
case 48000:
case 44100:
return 0;
case 32000:
case 33075:
return 1;
case 24000:
case 22050:
return 2;
case 16000:
case 14700:
return 3;
case 12000:
case 11025:
return 4;
case 8000:
case 7350:
return 5;
default:
return -EINVAL;
}
}
static int sun4i_codec_hw_params_capture(struct sun4i_codec *scodec,
struct snd_pcm_hw_params *params,
unsigned int hwrate)
{
regmap_field_update_bits(scodec->reg_adc_fifoc,
7 << SUN4I_CODEC_ADC_FIFOC_ADC_FS,
hwrate << SUN4I_CODEC_ADC_FIFOC_ADC_FS);
if (params_channels(params) == 1)
regmap_field_update_bits(scodec->reg_adc_fifoc,
BIT(SUN4I_CODEC_ADC_FIFOC_MONO_EN),
BIT(SUN4I_CODEC_ADC_FIFOC_MONO_EN));
else
regmap_field_update_bits(scodec->reg_adc_fifoc,
BIT(SUN4I_CODEC_ADC_FIFOC_MONO_EN),
0);
return 0;
}
static int sun4i_codec_hw_params_playback(struct sun4i_codec *scodec,
struct snd_pcm_hw_params *params,
unsigned int hwrate)
{
u32 val;
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
7 << SUN4I_CODEC_DAC_FIFOC_DAC_FS,
hwrate << SUN4I_CODEC_DAC_FIFOC_DAC_FS);
if (params_channels(params) == 1)
val = BIT(SUN4I_CODEC_DAC_FIFOC_MONO_EN);
else
val = 0;
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_MONO_EN),
val);
if (hw_param_interval(params, SNDRV_PCM_HW_PARAM_SAMPLE_BITS)->min == 32) {
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_TX_SAMPLE_BITS),
BIT(SUN4I_CODEC_DAC_FIFOC_TX_SAMPLE_BITS));
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_TX_FIFO_MODE),
0);
scodec->playback_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_4_BYTES;
} else {
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_TX_SAMPLE_BITS),
0);
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
BIT(SUN4I_CODEC_DAC_FIFOC_TX_FIFO_MODE),
BIT(SUN4I_CODEC_DAC_FIFOC_TX_FIFO_MODE));
scodec->playback_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
}
return 0;
}
static int sun4i_codec_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(rtd->card);
unsigned long clk_freq;
int ret, hwrate;
clk_freq = sun4i_codec_get_mod_freq(params);
if (!clk_freq)
return -EINVAL;
ret = clk_set_rate(scodec->clk_module, clk_freq);
if (ret)
return ret;
hwrate = sun4i_codec_get_hw_rate(params);
if (hwrate < 0)
return hwrate;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
return sun4i_codec_hw_params_playback(scodec, params,
hwrate);
return sun4i_codec_hw_params_capture(scodec, params,
hwrate);
}
static int sun4i_codec_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(rtd->card);
regmap_update_bits(scodec->regmap, SUN4I_CODEC_DAC_FIFOC,
3 << SUN4I_CODEC_DAC_FIFOC_DRQ_CLR_CNT,
3 << SUN4I_CODEC_DAC_FIFOC_DRQ_CLR_CNT);
return clk_prepare_enable(scodec->clk_module);
}
static void sun4i_codec_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(rtd->card);
clk_disable_unprepare(scodec->clk_module);
}
static int sun4i_codec_dai_probe(struct snd_soc_dai *dai)
{
struct snd_soc_card *card = snd_soc_dai_get_drvdata(dai);
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(card);
snd_soc_dai_init_dma_data(dai, &scodec->playback_dma_data,
&scodec->capture_dma_data);
return 0;
}
static struct snd_soc_dai_link *sun4i_codec_create_link(struct device *dev,
int *num_links)
{
struct snd_soc_dai_link *link = devm_kzalloc(dev, sizeof(*link),
GFP_KERNEL);
if (!link)
return NULL;
link->name = "cdc";
link->stream_name = "CDC PCM";
link->codec_dai_name = "Codec";
link->cpu_dai_name = dev_name(dev);
link->codec_name = dev_name(dev);
link->platform_name = dev_name(dev);
link->dai_fmt = SND_SOC_DAIFMT_I2S;
*num_links = 1;
return link;
}
static int sun4i_codec_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(w->dapm->card);
if (scodec->gpio_pa)
gpiod_set_value_cansleep(scodec->gpio_pa,
!!SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static struct snd_soc_card *sun4i_codec_create_card(struct device *dev)
{
struct snd_soc_card *card;
card = devm_kzalloc(dev, sizeof(*card), GFP_KERNEL);
if (!card)
return ERR_PTR(-ENOMEM);
card->dai_link = sun4i_codec_create_link(dev, &card->num_links);
if (!card->dai_link)
return ERR_PTR(-ENOMEM);
card->dev = dev;
card->name = "sun4i-codec";
card->dapm_widgets = sun4i_codec_card_dapm_widgets;
card->num_dapm_widgets = ARRAY_SIZE(sun4i_codec_card_dapm_widgets);
card->dapm_routes = sun4i_codec_card_dapm_routes;
card->num_dapm_routes = ARRAY_SIZE(sun4i_codec_card_dapm_routes);
return card;
}
static struct snd_soc_card *sun6i_codec_create_card(struct device *dev)
{
struct snd_soc_card *card;
int ret;
card = devm_kzalloc(dev, sizeof(*card), GFP_KERNEL);
if (!card)
return ERR_PTR(-ENOMEM);
card->dai_link = sun4i_codec_create_link(dev, &card->num_links);
if (!card->dai_link)
return ERR_PTR(-ENOMEM);
card->dev = dev;
card->name = "A31 Audio Codec";
card->dapm_widgets = sun6i_codec_card_dapm_widgets;
card->num_dapm_widgets = ARRAY_SIZE(sun6i_codec_card_dapm_widgets);
card->fully_routed = true;
ret = snd_soc_of_parse_audio_routing(card, "allwinner,audio-routing");
if (ret)
dev_warn(dev, "failed to parse audio-routing: %d\n", ret);
return card;
}
static struct snd_soc_card *sun8i_a23_codec_create_card(struct device *dev)
{
struct snd_soc_card *card;
int ret;
card = devm_kzalloc(dev, sizeof(*card), GFP_KERNEL);
if (!card)
return ERR_PTR(-ENOMEM);
aux_dev.codec_of_node = of_parse_phandle(dev->of_node,
"allwinner,codec-analog-controls",
0);
if (!aux_dev.codec_of_node) {
dev_err(dev, "Can't find analog controls for codec.\n");
return ERR_PTR(-EINVAL);
};
card->dai_link = sun4i_codec_create_link(dev, &card->num_links);
if (!card->dai_link)
return ERR_PTR(-ENOMEM);
card->dev = dev;
card->name = "A23 Audio Codec";
card->dapm_widgets = sun6i_codec_card_dapm_widgets;
card->num_dapm_widgets = ARRAY_SIZE(sun6i_codec_card_dapm_widgets);
card->dapm_routes = sun8i_codec_card_routes;
card->num_dapm_routes = ARRAY_SIZE(sun8i_codec_card_routes);
card->aux_dev = &aux_dev;
card->num_aux_devs = 1;
card->fully_routed = true;
ret = snd_soc_of_parse_audio_routing(card, "allwinner,audio-routing");
if (ret)
dev_warn(dev, "failed to parse audio-routing: %d\n", ret);
return card;
}
static struct snd_soc_card *sun8i_h3_codec_create_card(struct device *dev)
{
struct snd_soc_card *card;
int ret;
card = devm_kzalloc(dev, sizeof(*card), GFP_KERNEL);
if (!card)
return ERR_PTR(-ENOMEM);
aux_dev.codec_of_node = of_parse_phandle(dev->of_node,
"allwinner,codec-analog-controls",
0);
if (!aux_dev.codec_of_node) {
dev_err(dev, "Can't find analog controls for codec.\n");
return ERR_PTR(-EINVAL);
};
card->dai_link = sun4i_codec_create_link(dev, &card->num_links);
if (!card->dai_link)
return ERR_PTR(-ENOMEM);
card->dev = dev;
card->name = "H3 Audio Codec";
card->dapm_widgets = sun6i_codec_card_dapm_widgets;
card->num_dapm_widgets = ARRAY_SIZE(sun6i_codec_card_dapm_widgets);
card->dapm_routes = sun8i_codec_card_routes;
card->num_dapm_routes = ARRAY_SIZE(sun8i_codec_card_routes);
card->aux_dev = &aux_dev;
card->num_aux_devs = 1;
card->fully_routed = true;
ret = snd_soc_of_parse_audio_routing(card, "allwinner,audio-routing");
if (ret)
dev_warn(dev, "failed to parse audio-routing: %d\n", ret);
return card;
}
static int sun4i_codec_probe(struct platform_device *pdev)
{
struct snd_soc_card *card;
struct sun4i_codec *scodec;
const struct sun4i_codec_quirks *quirks;
struct resource *res;
void __iomem *base;
int ret;
scodec = devm_kzalloc(&pdev->dev, sizeof(*scodec), GFP_KERNEL);
if (!scodec)
return -ENOMEM;
scodec->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base)) {
dev_err(&pdev->dev, "Failed to map the registers\n");
return PTR_ERR(base);
}
quirks = of_device_get_match_data(&pdev->dev);
if (quirks == NULL) {
dev_err(&pdev->dev, "Failed to determine the quirks to use\n");
return -ENODEV;
}
scodec->regmap = devm_regmap_init_mmio(&pdev->dev, base,
quirks->regmap_config);
if (IS_ERR(scodec->regmap)) {
dev_err(&pdev->dev, "Failed to create our regmap\n");
return PTR_ERR(scodec->regmap);
}
scodec->clk_apb = devm_clk_get(&pdev->dev, "apb");
if (IS_ERR(scodec->clk_apb)) {
dev_err(&pdev->dev, "Failed to get the APB clock\n");
return PTR_ERR(scodec->clk_apb);
}
scodec->clk_module = devm_clk_get(&pdev->dev, "codec");
if (IS_ERR(scodec->clk_module)) {
dev_err(&pdev->dev, "Failed to get the module clock\n");
return PTR_ERR(scodec->clk_module);
}
if (quirks->has_reset) {
scodec->rst = devm_reset_control_get(&pdev->dev, NULL);
if (IS_ERR(scodec->rst)) {
dev_err(&pdev->dev, "Failed to get reset control\n");
return PTR_ERR(scodec->rst);
}
}
scodec->gpio_pa = devm_gpiod_get_optional(&pdev->dev, "allwinner,pa",
GPIOD_OUT_LOW);
if (IS_ERR(scodec->gpio_pa)) {
ret = PTR_ERR(scodec->gpio_pa);
if (ret != -EPROBE_DEFER)
dev_err(&pdev->dev, "Failed to get pa gpio: %d\n", ret);
return ret;
}
scodec->reg_adc_fifoc = devm_regmap_field_alloc(&pdev->dev,
scodec->regmap,
quirks->reg_adc_fifoc);
if (IS_ERR(scodec->reg_adc_fifoc)) {
ret = PTR_ERR(scodec->reg_adc_fifoc);
dev_err(&pdev->dev, "Failed to create regmap fields: %d\n",
ret);
return ret;
}
if (clk_prepare_enable(scodec->clk_apb)) {
dev_err(&pdev->dev, "Failed to enable the APB clock\n");
return -EINVAL;
}
if (scodec->rst) {
ret = reset_control_deassert(scodec->rst);
if (ret) {
dev_err(&pdev->dev,
"Failed to deassert the reset control\n");
goto err_clk_disable;
}
}
scodec->playback_dma_data.addr = res->start + quirks->reg_dac_txdata;
scodec->playback_dma_data.maxburst = 8;
scodec->playback_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
scodec->capture_dma_data.addr = res->start + quirks->reg_adc_rxdata;
scodec->capture_dma_data.maxburst = 8;
scodec->capture_dma_data.addr_width = DMA_SLAVE_BUSWIDTH_2_BYTES;
ret = snd_soc_register_codec(&pdev->dev, quirks->codec,
&sun4i_codec_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Failed to register our codec\n");
goto err_assert_reset;
}
ret = devm_snd_soc_register_component(&pdev->dev,
&sun4i_codec_component,
&dummy_cpu_dai, 1);
if (ret) {
dev_err(&pdev->dev, "Failed to register our DAI\n");
goto err_unregister_codec;
}
ret = devm_snd_dmaengine_pcm_register(&pdev->dev, NULL, 0);
if (ret) {
dev_err(&pdev->dev, "Failed to register against DMAEngine\n");
goto err_unregister_codec;
}
card = quirks->create_card(&pdev->dev);
if (IS_ERR(card)) {
ret = PTR_ERR(card);
dev_err(&pdev->dev, "Failed to create our card\n");
goto err_unregister_codec;
}
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, scodec);
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "Failed to register our card\n");
goto err_unregister_codec;
}
return 0;
err_unregister_codec:
snd_soc_unregister_codec(&pdev->dev);
err_assert_reset:
if (scodec->rst)
reset_control_assert(scodec->rst);
err_clk_disable:
clk_disable_unprepare(scodec->clk_apb);
return ret;
}
static int sun4i_codec_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct sun4i_codec *scodec = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
snd_soc_unregister_codec(&pdev->dev);
if (scodec->rst)
reset_control_assert(scodec->rst);
clk_disable_unprepare(scodec->clk_apb);
return 0;
}
