static int imx_hifi_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
sample_rate = params_rate(params);
sample_format = params_format(params);
return 0;
}
static int imx_wm8962_set_bias_level(struct snd_soc_card *card,
struct snd_soc_dapm_context *dapm,
enum snd_soc_bias_level level)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
struct imx_priv *priv = &card_priv;
struct imx_wm8962_data *data = platform_get_drvdata(priv->pdev);
struct device *dev = &priv->pdev->dev;
unsigned int pll_out;
int ret;
if (dapm->dev != codec_dai->dev)
return 0;
switch (level) {
case SND_SOC_BIAS_PREPARE:
if (dapm->bias_level == SND_SOC_BIAS_STANDBY) {
if (sample_format == SNDRV_PCM_FORMAT_S24_LE)
pll_out = sample_rate * 384;
else
pll_out = sample_rate * 256;
ret = snd_soc_dai_set_pll(codec_dai, WM8962_FLL,
WM8962_FLL_MCLK, data->clk_frequency,
pll_out);
if (ret < 0) {
dev_err(dev, "failed to start FLL: %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_sysclk(codec_dai,
WM8962_SYSCLK_FLL, pll_out,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(dev, "failed to set SYSCLK: %d\n", ret);
return ret;
}
}
break;
case SND_SOC_BIAS_STANDBY:
if (dapm->bias_level == SND_SOC_BIAS_PREPARE) {
ret = snd_soc_dai_set_sysclk(codec_dai,
WM8962_SYSCLK_MCLK, data->clk_frequency,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(dev,
"failed to switch away from FLL: %d\n",
ret);
return ret;
}
ret = snd_soc_dai_set_pll(codec_dai, WM8962_FLL,
0, 0, 0);
if (ret < 0) {
dev_err(dev, "failed to stop FLL: %d\n", ret);
return ret;
}
}
break;
default:
break;
}
return 0;
}
static int imx_wm8962_late_probe(struct snd_soc_card *card)
{
struct snd_soc_dai *codec_dai = card->rtd[0].codec_dai;
struct imx_priv *priv = &card_priv;
struct imx_wm8962_data *data = platform_get_drvdata(priv->pdev);
struct device *dev = &priv->pdev->dev;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, WM8962_SYSCLK_MCLK,
data->clk_frequency, SND_SOC_CLOCK_IN);
if (ret < 0)
dev_err(dev, "failed to set sysclk in %s\n", __func__);
return ret;
}
static int imx_wm8962_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *ssi_np, *codec_np;
struct platform_device *ssi_pdev;
struct imx_priv *priv = &card_priv;
struct i2c_client *codec_dev;
struct imx_wm8962_data *data;
int int_port, ext_port;
int ret;
priv->pdev = pdev;
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
imx_audmux_v2_configure_port(ext_port,
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
ret = -EINVAL;
goto fail;
}
codec_dev = of_find_i2c_device_by_node(codec_np);
if (!codec_dev || !codec_dev->dev.driver) {
dev_err(&pdev->dev, "failed to find codec platform device\n");
ret = -EINVAL;
goto fail;
}
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
ret = -ENOMEM;
goto fail;
}
data->codec_clk = devm_clk_get(&codec_dev->dev, NULL);
if (IS_ERR(data->codec_clk)) {
ret = PTR_ERR(data->codec_clk);
dev_err(&codec_dev->dev, "failed to get codec clk: %d\n", ret);
goto fail;
}
data->clk_frequency = clk_get_rate(data->codec_clk);
ret = clk_prepare_enable(data->codec_clk);
if (ret) {
dev_err(&codec_dev->dev, "failed to enable codec clk: %d\n", ret);
goto fail;
}
data->dai.name = "HiFi";
data->dai.stream_name = "HiFi";
data->dai.codec_dai_name = "wm8962";
data->dai.codec_of_node = codec_np;
data->dai.cpu_dai_name = dev_name(&ssi_pdev->dev);
data->dai.platform_of_node = ssi_np;
data->dai.ops = &imx_hifi_ops;
data->dai.dai_fmt = SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF |
SND_SOC_DAIFMT_CBM_CFM;
data->card.dev = &pdev->dev;
ret = snd_soc_of_parse_card_name(&data->card, "model");
if (ret)
goto clk_fail;
ret = snd_soc_of_parse_audio_routing(&data->card, "audio-routing");
if (ret)
goto clk_fail;
data->card.num_links = 1;
data->card.dai_link = &data->dai;
data->card.dapm_widgets = imx_wm8962_dapm_widgets;
data->card.num_dapm_widgets = ARRAY_SIZE(imx_wm8962_dapm_widgets);
data->card.late_probe = imx_wm8962_late_probe;
data->card.set_bias_level = imx_wm8962_set_bias_level;
ret = devm_snd_soc_register_card(&pdev->dev, &data->card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
goto clk_fail;
}
platform_set_drvdata(pdev, data);
of_node_put(ssi_np);
of_node_put(codec_np);
return 0;
clk_fail:
clk_disable_unprepare(data->codec_clk);
fail:
if (ssi_np)
of_node_put(ssi_np);
if (codec_np)
of_node_put(codec_np);
return ret;
}
static int imx_wm8962_remove(struct platform_device *pdev)
{
struct imx_wm8962_data *data = platform_get_drvdata(pdev);
if (!IS_ERR(data->codec_clk))
clk_disable_unprepare(data->codec_clk);
return 0;
}
