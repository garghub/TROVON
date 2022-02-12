static int a370db_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
unsigned int freq;
switch (params_rate(params)) {
default:
case 44100:
freq = 11289600;
break;
case 48000:
freq = 12288000;
break;
case 96000:
freq = 24576000;
break;
}
return snd_soc_dai_set_sysclk(codec_dai, 0, freq, SND_SOC_CLOCK_IN);
}
static int a370db_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &a370db;
card->dev = &pdev->dev;
a370db_dai[0].cpu_of_node =
of_parse_phandle(pdev->dev.of_node,
"marvell,audio-controller", 0);
a370db_dai[0].platform_of_node = a370db_dai[0].cpu_of_node;
a370db_dai[0].codec_of_node =
of_parse_phandle(pdev->dev.of_node,
"marvell,audio-codec", 0);
a370db_dai[1].cpu_of_node = a370db_dai[0].cpu_of_node;
a370db_dai[1].platform_of_node = a370db_dai[0].cpu_of_node;
a370db_dai[1].codec_of_node =
of_parse_phandle(pdev->dev.of_node,
"marvell,audio-codec", 1);
a370db_dai[2].cpu_of_node = a370db_dai[0].cpu_of_node;
a370db_dai[2].platform_of_node = a370db_dai[0].cpu_of_node;
a370db_dai[2].codec_of_node =
of_parse_phandle(pdev->dev.of_node,
"marvell,audio-codec", 2);
return devm_snd_soc_register_card(card->dev, card);
}
