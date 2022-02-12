static int imx_sgtl5000_dai_init(struct snd_soc_pcm_runtime *rtd)
{
struct imx_sgtl5000_data *data = snd_soc_card_get_drvdata(rtd->card);
struct device *dev = rtd->card->dev;
int ret;
ret = snd_soc_dai_set_sysclk(rtd->codec_dai, SGTL5000_SYSCLK,
data->clk_frequency, SND_SOC_CLOCK_IN);
if (ret) {
dev_err(dev, "could not set codec driver clock params\n");
return ret;
}
return 0;
}
static int imx_sgtl5000_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *ssi_np, *codec_np;
struct platform_device *ssi_pdev;
struct i2c_client *codec_dev;
struct imx_sgtl5000_data *data = NULL;
int int_port, ext_port;
int ret;
ret = of_property_read_u32(np, "mux-int-port", &int_port);
if (ret) {
dev_err(&pdev->dev, "mux-int-port missing or invalid\n");
return ret;
}
ret = of_property_read_u32(np, "mux-ext-port", &ext_port);
if (ret) {
dev_err(&pdev->dev, "mux-ext-port missing or invalid\n");
return ret;
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
dev_err(&pdev->dev, "audmux internal port setup failed\n");
return ret;
}
ret = imx_audmux_v2_configure_port(ext_port,
IMX_AUDMUX_V2_PTCR_SYN,
IMX_AUDMUX_V2_PDCR_RXDSEL(int_port));
if (ret) {
dev_err(&pdev->dev, "audmux external port setup failed\n");
return ret;
}
ssi_np = of_parse_phandle(pdev->dev.of_node, "ssi-controller", 0);
codec_np = of_parse_phandle(pdev->dev.of_node, "audio-codec", 0);
if (!ssi_np || !codec_np) {
dev_err(&pdev->dev, "phandle missing or invalid\n");
ret = -EINVAL;
goto fail;
}
ssi_pdev = of_find_device_by_node(ssi_np);
if (!ssi_pdev) {
dev_err(&pdev->dev, "failed to find SSI platform device\n");
ret = -EPROBE_DEFER;
goto fail;
}
codec_dev = of_find_i2c_device_by_node(codec_np);
if (!codec_dev) {
dev_err(&pdev->dev, "failed to find codec platform device\n");
return -EPROBE_DEFER;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto fail;
}
data->codec_clk = clk_get(&codec_dev->dev, NULL);
if (IS_ERR(data->codec_clk)) {
ret = PTR_ERR(data->codec_clk);
goto fail;
}
data->clk_frequency = clk_get_rate(data->codec_clk);
data->dai.name = "HiFi";
data->dai.stream_name = "HiFi";
data->dai.codec_dai_name = "sgtl5000";
data->dai.codec_of_node = codec_np;
data->dai.cpu_of_node = ssi_np;
data->dai.platform_of_node = ssi_np;
data->dai.init = &imx_sgtl5000_dai_init;
data->dai.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM;
data->card.dev = &pdev->dev;
ret = snd_soc_of_parse_card_name(&data->card, "model");
if (ret)
goto fail;
ret = snd_soc_of_parse_audio_routing(&data->card, "audio-routing");
if (ret)
goto fail;
data->card.num_links = 1;
data->card.owner = THIS_MODULE;
data->card.dai_link = &data->dai;
data->card.dapm_widgets = imx_sgtl5000_dapm_widgets;
data->card.num_dapm_widgets = ARRAY_SIZE(imx_sgtl5000_dapm_widgets);
platform_set_drvdata(pdev, &data->card);
snd_soc_card_set_drvdata(&data->card, data);
ret = devm_snd_soc_register_card(&pdev->dev, &data->card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
goto fail;
}
of_node_put(ssi_np);
of_node_put(codec_np);
return 0;
fail:
if (data && !IS_ERR(data->codec_clk))
clk_put(data->codec_clk);
of_node_put(ssi_np);
of_node_put(codec_np);
return ret;
}
static int imx_sgtl5000_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
struct imx_sgtl5000_data *data = snd_soc_card_get_drvdata(card);
clk_put(data->codec_clk);
return 0;
}
