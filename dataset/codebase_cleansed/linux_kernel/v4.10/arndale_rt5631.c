static int arndale_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int rfs, ret;
unsigned long rclk;
rfs = 256;
rclk = params_rate(params) * rfs;
ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_CDCLK,
0, SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(cpu_dai, SAMSUNG_I2S_RCLKSRC_0,
0, SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
ret = snd_soc_dai_set_sysclk(codec_dai, 0, rclk, SND_SOC_CLOCK_OUT);
if (ret < 0)
return ret;
return 0;
}
static int arndale_audio_probe(struct platform_device *pdev)
{
int n, ret;
struct device_node *np = pdev->dev.of_node;
struct snd_soc_card *card = &arndale_rt5631;
card->dev = &pdev->dev;
for (n = 0; np && n < ARRAY_SIZE(arndale_rt5631_dai); n++) {
if (!arndale_rt5631_dai[n].cpu_dai_name) {
arndale_rt5631_dai[n].cpu_of_node = of_parse_phandle(np,
"samsung,audio-cpu", n);
if (!arndale_rt5631_dai[n].cpu_of_node) {
dev_err(&pdev->dev,
"Property 'samsung,audio-cpu' missing or invalid\n");
return -EINVAL;
}
}
if (!arndale_rt5631_dai[n].platform_name)
arndale_rt5631_dai[n].platform_of_node =
arndale_rt5631_dai[n].cpu_of_node;
arndale_rt5631_dai[n].codec_name = NULL;
arndale_rt5631_dai[n].codec_of_node = of_parse_phandle(np,
"samsung,audio-codec", n);
if (!arndale_rt5631_dai[0].codec_of_node) {
dev_err(&pdev->dev,
"Property 'samsung,audio-codec' missing or invalid\n");
return -EINVAL;
}
}
ret = devm_snd_soc_register_card(card->dev, card);
if (ret)
dev_err(&pdev->dev, "snd_soc_register_card() failed:%d\n", ret);
return ret;
}
