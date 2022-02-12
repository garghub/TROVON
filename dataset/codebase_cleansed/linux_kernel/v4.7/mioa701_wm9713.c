static int rear_amp_power(struct snd_soc_codec *codec, int power)
{
unsigned short reg;
if (power) {
reg = snd_soc_read(codec, AC97_GPIO_CFG);
snd_soc_write(codec, AC97_GPIO_CFG, reg | 0x0100);
reg = snd_soc_read(codec, AC97_GPIO_PULL);
snd_soc_write(codec, AC97_GPIO_PULL, reg | (1<<15));
} else {
reg = snd_soc_read(codec, AC97_GPIO_CFG);
snd_soc_write(codec, AC97_GPIO_CFG, reg & ~0x0100);
reg = snd_soc_read(codec, AC97_GPIO_PULL);
snd_soc_write(codec, AC97_GPIO_PULL, reg & ~(1<<15));
}
return 0;
}
static int rear_amp_event(struct snd_soc_dapm_widget *widget,
struct snd_kcontrol *kctl, int event)
{
struct snd_soc_card *card = widget->dapm->card;
struct snd_soc_pcm_runtime *rtd;
struct snd_soc_codec *codec;
rtd = snd_soc_get_pcm_runtime(card, card->dai_link[0].name);
codec = rtd->codec;
return rear_amp_power(codec, SND_SOC_DAPM_EVENT_ON(event));
}
static int mioa701_wm9713_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
snd_soc_update_bits(codec, AC97_GPIO_CFG, 0x100, 0x100);
snd_soc_update_bits(codec, AC97_3D_CONTROL, 0xc000, 0xc000);
return 0;
}
static int mioa701_wm9713_probe(struct platform_device *pdev)
{
int rc;
if (!machine_is_mioa701())
return -ENODEV;
mioa701.dev = &pdev->dev;
rc = devm_snd_soc_register_card(&pdev->dev, &mioa701);
if (!rc)
dev_warn(&pdev->dev, "Be warned that incorrect mixers/muxes setup will"
"lead to overheating and possible destruction of your device."
" Do not use without a good knowledge of mio's board design!\n");
return rc;
}
