static int imx_es8328_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct imx_es8328_data *data = container_of(rtd->card,
struct imx_es8328_data, card);
int ret = 0;
if (gpio_is_valid(data->jack_gpio)) {
ret = snd_soc_jack_new(rtd->codec, "Headphone",
SND_JACK_HEADPHONE | SND_JACK_BTN_0,
&headset_jack);
if (ret)
return ret;
headset_jack_gpios[0].gpio = data->jack_gpio;
ret = snd_soc_jack_add_gpios(&headset_jack,
ARRAY_SIZE(headset_jack_gpios),
headset_jack_gpios);
}
return ret;
}
static int imx_es8328_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *ssi_np = NULL, *codec_np = NULL;
struct platform_device *ssi_pdev;
struct imx_es8328_data *data;
u32 int_port, ext_port;
int ret;
struct device *dev = &pdev->dev;
ret = of_property_read_u32(np, "mux-int-port", &int_port);
if (ret) {
dev_err(dev, "mux-int-port missing or invalid\n");
goto fail;
}
if (int_port > MUX_PORT_MAX || int_port == 0) {
dev_err(dev, "mux-int-port: hardware only has %d mux ports\n",
MUX_PORT_MAX);
goto fail;
}
ret = of_property_read_u32(np, "mux-ext-port", &ext_port);
if (ret) {
dev_err(dev, "mux-ext-port missing or invalid\n");
goto fail;
}
if (ext_port > MUX_PORT_MAX || ext_port == 0) {
dev_err(dev, "mux-ext-port: hardware only has %d mux ports\n",
MUX_PORT_MAX);
ret = -EINVAL;
goto fail;
}
int_port--;
ext_port--;
ret = imx_audmux_v2_configure_port(int_port,
IMX_AUDMUX_V2_PTCR_SYN |
IMX_AUDMUX_V2_PTCR_TFSEL(ext_port) |
IMX_AUDMUX_V2_PTCR_TCSEL(ext_port) |
IMX_AUDMUX_V2_PTCR_TFSDIR |
IMX_AUDMUX_V2_PTCR_TCLKDIR,
IMX_AUDMUX_V2_PDCR_RXDSEL(ext_port));
if (ret) {
dev_err(dev, "audmux internal port setup failed\n");
return ret;
}
ret = imx_audmux_v2_configure_port(ext_port,
IMX_AUDMUX_V2_PTCR_SYN,
IMX_AUDMUX_V2_PDCR_RXDSEL(int_port));
if (ret) {
dev_err(dev, "audmux external port setup failed\n");
return ret;
}
ssi_np = of_parse_phandle(pdev->dev.of_node, "ssi-controller", 0);
codec_np = of_parse_phandle(pdev->dev.of_node, "audio-codec", 0);
if (!ssi_np || !codec_np) {
dev_err(dev, "phandle missing or invalid\n");
ret = -EINVAL;
goto fail;
}
ssi_pdev = of_find_device_by_node(ssi_np);
if (!ssi_pdev) {
dev_err(dev, "failed to find SSI platform device\n");
ret = -EINVAL;
goto fail;
}
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto fail;
}
data->dev = dev;
data->jack_gpio = of_get_named_gpio(pdev->dev.of_node, "jack-gpio", 0);
data->dai.name = "hifi";
data->dai.stream_name = "hifi";
data->dai.codec_dai_name = "es8328-hifi-analog";
data->dai.codec_of_node = codec_np;
data->dai.cpu_of_node = ssi_np;
data->dai.platform_of_node = ssi_np;
data->dai.init = &imx_es8328_dai_init;
data->dai.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM;
data->card.dev = dev;
data->card.dapm_widgets = imx_es8328_dapm_widgets;
data->card.num_dapm_widgets = ARRAY_SIZE(imx_es8328_dapm_widgets);
ret = snd_soc_of_parse_card_name(&data->card, "model");
if (ret) {
dev_err(dev, "Unable to parse card name\n");
goto fail;
}
ret = snd_soc_of_parse_audio_routing(&data->card, "audio-routing");
if (ret) {
dev_err(dev, "Unable to parse routing: %d\n", ret);
goto fail;
}
data->card.num_links = 1;
data->card.owner = THIS_MODULE;
data->card.dai_link = &data->dai;
ret = snd_soc_register_card(&data->card);
if (ret) {
dev_err(dev, "Unable to register: %d\n", ret);
goto fail;
}
platform_set_drvdata(pdev, data);
fail:
of_node_put(ssi_np);
of_node_put(codec_np);
return ret;
}
static int imx_es8328_remove(struct platform_device *pdev)
{
struct imx_es8328_data *data = platform_get_drvdata(pdev);
snd_soc_jack_free_gpios(&headset_jack, ARRAY_SIZE(headset_jack_gpios),
headset_jack_gpios);
snd_soc_unregister_card(&data->card);
return 0;
}
