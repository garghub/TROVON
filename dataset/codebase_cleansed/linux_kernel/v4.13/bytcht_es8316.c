static inline struct snd_soc_dai *get_codec_dai(struct snd_soc_card *card)
{
struct snd_soc_pcm_runtime *rtd;
list_for_each_entry(rtd, &card->rtd_list, list) {
if (!strncmp(rtd->codec_dai->name, CODEC_DAI1,
strlen(CODEC_DAI1)))
return rtd->codec_dai;
}
return NULL;
}
static int byt_cht_es8316_init(struct snd_soc_pcm_runtime *runtime)
{
struct snd_soc_card *card = runtime->card;
struct byt_cht_es8316_private *priv = snd_soc_card_get_drvdata(card);
int ret;
card->dapm.idle_bias_off = true;
ret = clk_prepare_enable(priv->mclk);
if (!ret)
clk_disable_unprepare(priv->mclk);
ret = clk_set_rate(priv->mclk, 19200000);
if (ret)
dev_err(card->dev, "unable to set MCLK rate\n");
ret = clk_prepare_enable(priv->mclk);
if (ret)
dev_err(card->dev, "unable to enable MCLK\n");
ret = snd_soc_dai_set_sysclk(runtime->codec_dai, 0, 19200000,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(card->dev, "can't set codec clock %d\n", ret);
return ret;
}
return 0;
}
static int byt_cht_es8316_codec_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
int ret;
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
params_set_format(params, SNDRV_PCM_FORMAT_S24_LE);
ret = snd_soc_dai_set_fmt(rtd->cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS
);
if (ret < 0) {
dev_err(rtd->dev, "can't set format to I2S, err %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_tdm_slot(rtd->cpu_dai, 0x3, 0x3, 2, 24);
if (ret < 0) {
dev_err(rtd->dev, "can't set I2S config, err %d\n", ret);
return ret;
}
return 0;
}
static int byt_cht_es8316_aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_single(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE, 48000);
}
static int snd_byt_cht_es8316_mc_probe(struct platform_device *pdev)
{
int ret = 0;
struct byt_cht_es8316_private *priv;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_ATOMIC);
if (!priv)
return -ENOMEM;
byt_cht_es8316_card.dev = &pdev->dev;
snd_soc_card_set_drvdata(&byt_cht_es8316_card, priv);
priv->mclk = devm_clk_get(&pdev->dev, "pmc_plt_clk_3");
if (IS_ERR(priv->mclk)) {
ret = PTR_ERR(priv->mclk);
dev_err(&pdev->dev,
"Failed to get MCLK from pmc_plt_clk_3: %d\n",
ret);
return ret;
}
ret = devm_snd_soc_register_card(&pdev->dev, &byt_cht_es8316_card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, &byt_cht_es8316_card);
return ret;
}
