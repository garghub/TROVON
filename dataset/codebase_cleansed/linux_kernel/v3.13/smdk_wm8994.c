static int smdk_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int pll_out;
int ret;
if (params_format(params) == SNDRV_PCM_FORMAT_S24_LE)
pll_out = params_rate(params) * 384;
else if (params_rate(params) == 8000 || params_rate(params) == 11025)
pll_out = params_rate(params) * 512;
else
pll_out = params_rate(params) * 256;
ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL1, WM8994_FLL_SRC_MCLK1,
SMDK_WM8994_FREQ, pll_out);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8994_SYSCLK_FLL1,
pll_out, SND_SOC_CLOCK_IN);
if (ret < 0)
return ret;
return 0;
}
static int smdk_wm8994_init_paiftx(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_enable_pin(dapm, "HPOUT1R");
snd_soc_dapm_enable_pin(dapm, "HPOUT1L");
snd_soc_dapm_enable_pin(dapm, "IN1LN");
snd_soc_dapm_enable_pin(dapm, "IN1RN");
snd_soc_dapm_enable_pin(dapm, "IN2LN");
snd_soc_dapm_enable_pin(dapm, "IN2RN");
snd_soc_dapm_nc_pin(dapm, "HPOUT2P");
snd_soc_dapm_nc_pin(dapm, "HPOUT2N");
snd_soc_dapm_nc_pin(dapm, "SPKOUTLN");
snd_soc_dapm_nc_pin(dapm, "SPKOUTLP");
snd_soc_dapm_nc_pin(dapm, "SPKOUTRP");
snd_soc_dapm_nc_pin(dapm, "SPKOUTRN");
snd_soc_dapm_nc_pin(dapm, "LINEOUT1N");
snd_soc_dapm_nc_pin(dapm, "LINEOUT1P");
snd_soc_dapm_nc_pin(dapm, "LINEOUT2N");
snd_soc_dapm_nc_pin(dapm, "LINEOUT2P");
snd_soc_dapm_nc_pin(dapm, "IN1LP");
snd_soc_dapm_nc_pin(dapm, "IN2LP:VXRN");
snd_soc_dapm_nc_pin(dapm, "IN1RP");
snd_soc_dapm_nc_pin(dapm, "IN2RP:VXRP");
return 0;
}
static int smdk_audio_probe(struct platform_device *pdev)
{
int ret;
struct device_node *np = pdev->dev.of_node;
struct snd_soc_card *card = &smdk;
struct smdk_wm8994_data *board;
const struct of_device_id *id;
card->dev = &pdev->dev;
board = devm_kzalloc(&pdev->dev, sizeof(*board), GFP_KERNEL);
if (!board)
return -ENOMEM;
if (np) {
smdk_dai[0].cpu_dai_name = NULL;
smdk_dai[0].cpu_of_node = of_parse_phandle(np,
"samsung,i2s-controller", 0);
if (!smdk_dai[0].cpu_of_node) {
dev_err(&pdev->dev,
"Property 'samsung,i2s-controller' missing or invalid\n");
ret = -EINVAL;
}
smdk_dai[0].platform_name = NULL;
smdk_dai[0].platform_of_node = smdk_dai[0].cpu_of_node;
}
id = of_match_device(samsung_wm8994_of_match, &pdev->dev);
if (id)
*board = *((struct smdk_wm8994_data *)id->data);
platform_set_drvdata(pdev, board);
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed:%d\n", ret);
return ret;
}
