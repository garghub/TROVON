static int tegra_rt5640_asoc_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_card *card = rtd->card;
struct tegra_rt5640 *machine = snd_soc_card_get_drvdata(card);
int srate, mclk;
int err;
srate = params_rate(params);
mclk = 256 * srate;
err = tegra_asoc_utils_set_rate(&machine->util_data, srate, mclk);
if (err < 0) {
dev_err(card->dev, "Can't configure clocks\n");
return err;
}
err = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_MCLK, mclk,
SND_SOC_CLOCK_IN);
if (err < 0) {
dev_err(card->dev, "codec_dai clock not set\n");
return err;
}
return 0;
}
static int tegra_rt5640_asoc_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_codec *codec = codec_dai->codec;
struct tegra_rt5640 *machine = snd_soc_card_get_drvdata(rtd->card);
snd_soc_jack_new(codec, "Headphones", SND_JACK_HEADPHONE,
&tegra_rt5640_hp_jack);
snd_soc_jack_add_pins(&tegra_rt5640_hp_jack,
ARRAY_SIZE(tegra_rt5640_hp_jack_pins),
tegra_rt5640_hp_jack_pins);
if (gpio_is_valid(machine->gpio_hp_det)) {
tegra_rt5640_hp_jack_gpio.gpio = machine->gpio_hp_det;
snd_soc_jack_add_gpios(&tegra_rt5640_hp_jack,
1,
&tegra_rt5640_hp_jack_gpio);
}
return 0;
}
static int tegra_rt5640_card_remove(struct snd_soc_card *card)
{
struct tegra_rt5640 *machine = snd_soc_card_get_drvdata(card);
if (gpio_is_valid(machine->gpio_hp_det)) {
snd_soc_jack_free_gpios(&tegra_rt5640_hp_jack, 1,
&tegra_rt5640_hp_jack_gpio);
}
return 0;
}
static int tegra_rt5640_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct snd_soc_card *card = &snd_soc_tegra_rt5640;
struct tegra_rt5640 *machine;
int ret;
machine = devm_kzalloc(&pdev->dev,
sizeof(struct tegra_rt5640), GFP_KERNEL);
if (!machine) {
dev_err(&pdev->dev, "Can't allocate tegra_rt5640\n");
return -ENOMEM;
}
card->dev = &pdev->dev;
platform_set_drvdata(pdev, card);
snd_soc_card_set_drvdata(card, machine);
machine->gpio_hp_det = of_get_named_gpio(np, "nvidia,hp-det-gpios", 0);
if (machine->gpio_hp_det == -EPROBE_DEFER)
return -EPROBE_DEFER;
ret = snd_soc_of_parse_card_name(card, "nvidia,model");
if (ret)
goto err;
ret = snd_soc_of_parse_audio_routing(card, "nvidia,audio-routing");
if (ret)
goto err;
tegra_rt5640_dai.codec_of_node = of_parse_phandle(np,
"nvidia,audio-codec", 0);
if (!tegra_rt5640_dai.codec_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,audio-codec' missing or invalid\n");
ret = -EINVAL;
goto err;
}
tegra_rt5640_dai.cpu_of_node = of_parse_phandle(np,
"nvidia,i2s-controller", 0);
if (!tegra_rt5640_dai.cpu_of_node) {
dev_err(&pdev->dev,
"Property 'nvidia,i2s-controller' missing or invalid\n");
ret = -EINVAL;
goto err;
}
tegra_rt5640_dai.platform_of_node = tegra_rt5640_dai.cpu_of_node;
ret = tegra_asoc_utils_init(&machine->util_data, &pdev->dev);
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
tegra_asoc_utils_fini(&machine->util_data);
err:
return ret;
}
static int tegra_rt5640_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct tegra_rt5640 *machine = snd_soc_card_get_drvdata(card);
snd_soc_unregister_card(card);
tegra_asoc_utils_fini(&machine->util_data);
return 0;
}
