static int asoc_simple_card_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct asoc_simple_card_info *cinfo = asoc_simple_get_card_info(rtd);
struct asoc_simple_dai_init_info *iinfo = cinfo->init;
struct snd_soc_dai *codec = rtd->codec_dai;
struct snd_soc_dai *cpu = rtd->cpu_dai;
unsigned int cpu_daifmt = iinfo->fmt | iinfo->cpu_daifmt;
unsigned int codec_daifmt = iinfo->fmt | iinfo->codec_daifmt;
int ret;
if (codec_daifmt) {
ret = snd_soc_dai_set_fmt(codec, codec_daifmt);
if (ret < 0)
return ret;
}
if (iinfo->sysclk) {
ret = snd_soc_dai_set_sysclk(codec, 0, iinfo->sysclk, 0);
if (ret < 0)
return ret;
}
if (cpu_daifmt) {
ret = snd_soc_dai_set_fmt(cpu, cpu_daifmt);
if (ret < 0)
return ret;
}
return 0;
}
static int asoc_simple_card_probe(struct platform_device *pdev)
{
struct asoc_simple_card_info *cinfo = pdev->dev.platform_data;
if (!cinfo) {
dev_err(&pdev->dev, "no info for asoc-simple-card\n");
return -EINVAL;
}
if (!cinfo->name ||
!cinfo->card ||
!cinfo->cpu_dai ||
!cinfo->codec ||
!cinfo->platform ||
!cinfo->codec_dai) {
dev_err(&pdev->dev, "insufficient asoc_simple_card_info settings\n");
return -EINVAL;
}
cinfo->snd_link.name = cinfo->name;
cinfo->snd_link.stream_name = cinfo->name;
cinfo->snd_link.cpu_dai_name = cinfo->cpu_dai;
cinfo->snd_link.platform_name = cinfo->platform;
cinfo->snd_link.codec_name = cinfo->codec;
cinfo->snd_link.codec_dai_name = cinfo->codec_dai;
if (cinfo->init)
cinfo->snd_link.init = asoc_simple_card_dai_init;
cinfo->snd_card.name = cinfo->card;
cinfo->snd_card.owner = THIS_MODULE;
cinfo->snd_card.dai_link = &cinfo->snd_link;
cinfo->snd_card.num_links = 1;
cinfo->snd_card.dev = &pdev->dev;
return snd_soc_register_card(&cinfo->snd_card);
}
static int asoc_simple_card_remove(struct platform_device *pdev)
{
struct asoc_simple_card_info *cinfo = pdev->dev.platform_data;
return snd_soc_unregister_card(&cinfo->snd_card);
}
