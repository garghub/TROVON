static int codec_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
int ret;
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
params_set_format(params, SNDRV_PCM_FORMAT_S24_LE);
ret = snd_soc_dai_set_fmt(rtd->cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBS_CFS);
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
static int aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_single(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE, 48000);
}
static int aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, DA7213_CLKSRC_MCLK,
19200000, SND_SOC_CLOCK_IN);
if (ret < 0)
dev_err(codec_dai->dev, "can't set codec sysclk configuration\n");
ret = snd_soc_dai_set_pll(codec_dai, 0,
DA7213_SYSCLK_PLL_SRM, 0, DA7213_PLL_FREQ_OUT_98304000);
if (ret < 0) {
dev_err(codec_dai->dev, "failed to start PLL: %d\n", ret);
return -EIO;
}
return ret;
}
static int aif1_hw_free(struct snd_pcm_substream *substream)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_pll(codec_dai, 0,
DA7213_SYSCLK_MCLK, 0, 0);
if (ret < 0) {
dev_err(codec_dai->dev, "failed to stop PLL: %d\n", ret);
return -EIO;
}
return ret;
}
static int bytcht_da7213_probe(struct platform_device *pdev)
{
int ret_val = 0;
int i;
struct snd_soc_card *card;
struct sst_acpi_mach *mach;
const char *i2c_name = NULL;
int dai_index = 0;
mach = (&pdev->dev)->platform_data;
card = &bytcht_da7213_card;
card->dev = &pdev->dev;
dai_index = MERR_DPCM_COMPR + 1;
for (i = 0; i < ARRAY_SIZE(dailink); i++) {
if (!strcmp(dailink[i].codec_name, "i2c-DLGS7213:00")) {
dai_index = i;
break;
}
}
i2c_name = sst_acpi_find_name_from_hid(mach->id);
if (i2c_name != NULL) {
snprintf(codec_name, sizeof(codec_name),
"%s%s", "i2c-", i2c_name);
dailink[dai_index].codec_name = codec_name;
}
ret_val = devm_snd_soc_register_card(&pdev->dev, card);
if (ret_val) {
dev_err(&pdev->dev,
"snd_soc_register_card failed %d\n", ret_val);
return ret_val;
}
platform_set_drvdata(pdev, card);
return ret_val;
}
