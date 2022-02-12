static int rk_hp_power(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct rk_drvdata *machine = snd_soc_card_get_drvdata(w->dapm->card);
if (!gpio_is_valid(machine->gpio_hp_en))
return 0;
gpio_set_value_cansleep(machine->gpio_hp_en,
SND_SOC_DAPM_EVENT_ON(event));
return 0;
}
static int rk_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
int ret = 0;
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int mclk;
switch (params_rate(params)) {
case 8000:
case 16000:
case 24000:
case 32000:
case 48000:
case 64000:
case 96000:
mclk = 12288000;
break;
case 11025:
case 22050:
case 44100:
case 88200:
mclk = 11289600;
break;
default:
return -EINVAL;
}
ret = snd_soc_dai_set_sysclk(cpu_dai, 0, mclk,
SND_SOC_CLOCK_OUT);
if (ret && ret != -ENOTSUPP) {
dev_err(codec_dai->dev, "Can't set cpu clock %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai, 0, mclk,
SND_SOC_CLOCK_IN);
if (ret && ret != -ENOTSUPP) {
dev_err(codec_dai->dev, "Can't set codec clock %d\n", ret);
return ret;
}
return 0;
}
static int rk_init(struct snd_soc_pcm_runtime *runtime)
{
struct rk_drvdata *machine = snd_soc_card_get_drvdata(runtime->card);
if (gpio_is_valid(machine->gpio_hp_det)) {
snd_soc_card_jack_new(runtime->card, "Headphone Jack",
SND_JACK_HEADPHONE, &headphone_jack,
headphone_jack_pins,
ARRAY_SIZE(headphone_jack_pins));
rk_hp_jack_gpio.gpio = machine->gpio_hp_det;
snd_soc_jack_add_gpios(&headphone_jack, 1, &rk_hp_jack_gpio);
}
return 0;
}
static int snd_rk_mc_probe(struct platform_device *pdev)
{
int ret = 0;
struct snd_soc_card *card = &snd_soc_card_rk;
struct device_node *np = pdev->dev.of_node;
struct rk_drvdata *machine;
struct of_phandle_args args;
machine = devm_kzalloc(&pdev->dev, sizeof(struct rk_drvdata),
GFP_KERNEL);
if (!machine)
return -ENOMEM;
card->dev = &pdev->dev;
machine->gpio_hp_det = of_get_named_gpio(np,
"rockchip,hp-det-gpios", 0);
if (!gpio_is_valid(machine->gpio_hp_det) && machine->gpio_hp_det != -ENODEV)
return machine->gpio_hp_det;
machine->gpio_hp_en = of_get_named_gpio(np,
"rockchip,hp-en-gpios", 0);
if (!gpio_is_valid(machine->gpio_hp_en) && machine->gpio_hp_en != -ENODEV)
return machine->gpio_hp_en;
if (gpio_is_valid(machine->gpio_hp_en)) {
ret = devm_gpio_request_one(&pdev->dev, machine->gpio_hp_en,
GPIOF_OUT_INIT_LOW, "hp_en");
if (ret) {
dev_err(card->dev, "cannot get hp_en gpio\n");
return ret;
}
}
ret = snd_soc_of_parse_card_name(card, "rockchip,model");
if (ret) {
dev_err(card->dev, "SoC parse card name failed %d\n", ret);
return ret;
}
rk_dailink.codecs[0].of_node = of_parse_phandle(np,
"rockchip,audio-codec",
0);
if (!rk_dailink.codecs[0].of_node) {
dev_err(&pdev->dev,
"Property 'rockchip,audio-codec' missing or invalid\n");
return -EINVAL;
}
ret = of_parse_phandle_with_fixed_args(np, "rockchip,audio-codec",
0, 0, &args);
if (ret) {
dev_err(&pdev->dev,
"Unable to parse property 'rockchip,audio-codec'\n");
return ret;
}
ret = snd_soc_get_dai_name(&args, &rk_dailink.codecs[0].dai_name);
if (ret) {
dev_err(&pdev->dev, "Unable to get codec_dai_name\n");
return ret;
}
rk_dailink.cpu_of_node = of_parse_phandle(np, "rockchip,i2s-controller",
0);
if (!rk_dailink.cpu_of_node) {
dev_err(&pdev->dev,
"Property 'rockchip,i2s-controller' missing or invalid\n");
return -EINVAL;
}
rk_dailink.platform_of_node = rk_dailink.cpu_of_node;
ret = snd_soc_of_parse_audio_routing(card, "rockchip,routing");
if (ret) {
dev_err(&pdev->dev,
"Unable to parse 'rockchip,routing' property\n");
return ret;
}
snd_soc_card_set_drvdata(card, machine);
ret = devm_snd_soc_register_card(&pdev->dev, card);
if (ret == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (ret) {
dev_err(&pdev->dev,
"Soc register card failed %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, card);
return ret;
}
