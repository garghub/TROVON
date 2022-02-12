static int tegra_alc5632_asoc_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_card *card = codec->card;
struct tegra_alc5632 *alc5632 = snd_soc_card_get_drvdata(card);
int srate, mclk;
int err;
srate = params_rate(params);
mclk = 512 * srate;
err = tegra_asoc_utils_set_rate(&alc5632->util_data, srate, mclk);
if (err < 0) {
dev_err(card->dev, "Can't configure clocks\n");
return err;
}
err = snd_soc_dai_set_sysclk(codec_dai, 0, mclk,
SND_SOC_CLOCK_IN);
if (err < 0) {
dev_err(card->dev, "codec_dai clock not set\n");
return err;
}
return 0;
}
static int tegra_alc5632_asoc_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_codec *codec = rtd->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
struct device_node *np = codec->card->dev->of_node;
struct tegra_alc5632 *machine = snd_soc_card_get_drvdata(codec->card);
snd_soc_jack_new(codec, "Headset Jack", SND_JACK_HEADSET,
&tegra_alc5632_hs_jack);
snd_soc_jack_add_pins(&tegra_alc5632_hs_jack,
ARRAY_SIZE(tegra_alc5632_hs_jack_pins),
tegra_alc5632_hs_jack_pins);
machine->gpio_hp_det = of_get_named_gpio(np, "nvidia,hp-det-gpios", 0);
if (gpio_is_valid(machine->gpio_hp_det)) {
tegra_alc5632_hp_jack_gpio.gpio = machine->gpio_hp_det;
snd_soc_jack_add_gpios(&tegra_alc5632_hs_jack,
1,
&tegra_alc5632_hp_jack_gpio);
machine->gpio_requested |= GPIO_HP_DET;
}
snd_soc_dapm_force_enable_pin(dapm, "MICBIAS1");
return 0;
}
static __devinit int tegra_alc5632_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &snd_soc_tegra_alc5632;
struct tegra_alc5632 *alc5632;
int ret;
alc5632 = devm_kzalloc(&pdev->dev,
sizeof(struct tegra_alc5632), GFP_KERNEL);
if (!alc5632) {
dev_err(&pdev->dev, "Can't allocate tegra_alc5632\n");
ret = -ENOMEM;
goto err;
}
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, alc5632);
if (!(pdev->dev.of_node)) {
dev_err(&pdev->dev, "Must be instantiated using device tree\n");
ret = -EINVAL;
goto err;
}
ret = snd_soc_of_parse_card_name(card, "nvidia,model");
if (ret)
goto err;
ret = snd_soc_of_parse_audio_routing(card, "nvidia,audio-routing");
if (ret)
goto err;
tegra_alc5632_dai.codec_of_node = of_parse_phandle(
pdev->dev.of_node, "nvidia,audio-codec", 0);
if (!tegra_alc5632_dai.codec_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,audio-codec' missing or invalid\n");
ret = -EINVAL;
goto err;
}
tegra_alc5632_dai.cpu_dai_of_node = of_parse_phandle(
pdev->dev.of_node, "nvidia,i2s-controller", 0);
if (!tegra_alc5632_dai.cpu_dai_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,i2s-controller' missing or invalid\n");
ret = -EINVAL;
goto err;
}
tegra_alc5632_dai.platform_of_node = tegra_alc5632_dai.cpu_dai_of_node;
ret = tegra_asoc_utils_init(&alc5632->util_data, &pdev->dev);
if (ret)
goto err;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n",
ret);
goto err_fini_utils;
}
return 0;
err_fini_utils:
tegra_asoc_utils_fini(&alc5632->util_data);
err:
return ret;
}
static int __devexit tegra_alc5632_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_alc5632 *machine = snd_soc_card_get_drvdata(card);
if (machine->gpio_requested & GPIO_HP_DET)
snd_soc_jack_free_gpios(&tegra_alc5632_hs_jack,
1,
&tegra_alc5632_hp_jack_gpio);
machine->gpio_requested = 0;
snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&machine->util_data);
return 0;
}
