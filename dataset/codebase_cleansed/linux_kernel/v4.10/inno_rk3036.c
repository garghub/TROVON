static int rk3036_codec_antipop_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int rk3036_codec_antipop_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
int val, ret, regval;
ret = snd_soc_component_read(component, INNO_R09, &regval);
if (ret)
return ret;
val = ((regval >> INNO_R09_HPL_ANITPOP_SHIFT) &
INNO_R09_HP_ANTIPOP_MSK) == INNO_R09_HP_ANTIPOP_ON;
ucontrol->value.integer.value[0] = val;
val = ((regval >> INNO_R09_HPR_ANITPOP_SHIFT) &
INNO_R09_HP_ANTIPOP_MSK) == INNO_R09_HP_ANTIPOP_ON;
ucontrol->value.integer.value[1] = val;
return 0;
}
static int rk3036_codec_antipop_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_component *component = snd_kcontrol_chip(kcontrol);
int val, ret, regmsk;
val = (ucontrol->value.integer.value[0] ?
INNO_R09_HP_ANTIPOP_ON : INNO_R09_HP_ANTIPOP_OFF) <<
INNO_R09_HPL_ANITPOP_SHIFT;
val |= (ucontrol->value.integer.value[1] ?
INNO_R09_HP_ANTIPOP_ON : INNO_R09_HP_ANTIPOP_OFF) <<
INNO_R09_HPR_ANITPOP_SHIFT;
regmsk = INNO_R09_HP_ANTIPOP_MSK << INNO_R09_HPL_ANITPOP_SHIFT |
INNO_R09_HP_ANTIPOP_MSK << INNO_R09_HPR_ANITPOP_SHIFT;
ret = snd_soc_component_update_bits(component, INNO_R09,
regmsk, val);
if (ret < 0)
return ret;
return 0;
}
static int rk3036_codec_dai_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int reg01_val = 0, reg02_val = 0, reg03_val = 0;
dev_dbg(codec->dev, "rk3036_codec dai set fmt : %08x\n", fmt);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
reg01_val |= INNO_R01_PINDIR_IN_SLAVE |
INNO_R01_I2SMODE_SLAVE;
break;
case SND_SOC_DAIFMT_CBM_CFM:
reg01_val |= INNO_R01_PINDIR_OUT_MASTER |
INNO_R01_I2SMODE_MASTER;
break;
default:
dev_err(codec->dev, "invalid fmt\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
reg02_val |= INNO_R02_DACM_PCM;
break;
case SND_SOC_DAIFMT_I2S:
reg02_val |= INNO_R02_DACM_I2S;
break;
case SND_SOC_DAIFMT_RIGHT_J:
reg02_val |= INNO_R02_DACM_RJM;
break;
case SND_SOC_DAIFMT_LEFT_J:
reg02_val |= INNO_R02_DACM_LJM;
break;
default:
dev_err(codec->dev, "set dai format failed\n");
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
reg02_val |= INNO_R02_LRCP_NORMAL;
reg03_val |= INNO_R03_BCP_NORMAL;
break;
case SND_SOC_DAIFMT_IB_IF:
reg02_val |= INNO_R02_LRCP_REVERSAL;
reg03_val |= INNO_R03_BCP_REVERSAL;
break;
case SND_SOC_DAIFMT_IB_NF:
reg02_val |= INNO_R02_LRCP_REVERSAL;
reg03_val |= INNO_R03_BCP_NORMAL;
break;
case SND_SOC_DAIFMT_NB_IF:
reg02_val |= INNO_R02_LRCP_NORMAL;
reg03_val |= INNO_R03_BCP_REVERSAL;
break;
default:
dev_err(codec->dev, "set dai format failed\n");
return -EINVAL;
}
snd_soc_update_bits(codec, INNO_R01, INNO_R01_I2SMODE_MSK |
INNO_R01_PINDIR_MSK, reg01_val);
snd_soc_update_bits(codec, INNO_R02, INNO_R02_LRCP_MSK |
INNO_R02_DACM_MSK, reg02_val);
snd_soc_update_bits(codec, INNO_R03, INNO_R03_BCP_MSK, reg03_val);
return 0;
}
static int rk3036_codec_dai_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *hw_params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int reg02_val = 0, reg03_val = 0;
switch (params_format(hw_params)) {
case SNDRV_PCM_FORMAT_S16_LE:
reg02_val |= INNO_R02_VWL_16BIT;
break;
case SNDRV_PCM_FORMAT_S20_3LE:
reg02_val |= INNO_R02_VWL_20BIT;
break;
case SNDRV_PCM_FORMAT_S24_LE:
reg02_val |= INNO_R02_VWL_24BIT;
break;
case SNDRV_PCM_FORMAT_S32_LE:
reg02_val |= INNO_R02_VWL_32BIT;
break;
default:
return -EINVAL;
}
reg02_val |= INNO_R02_LRCP_NORMAL;
reg03_val |= INNO_R03_FWL_32BIT | INNO_R03_DACR_WORK;
snd_soc_update_bits(codec, INNO_R02, INNO_R02_LRCP_MSK |
INNO_R02_VWL_MSK, reg02_val);
snd_soc_update_bits(codec, INNO_R03, INNO_R03_DACR_MSK |
INNO_R03_FWL_MSK, reg03_val);
return 0;
}
static void rk3036_codec_reset(struct snd_soc_codec *codec)
{
snd_soc_write(codec, INNO_R00,
INNO_R00_CSR_RESET | INNO_R00_CDCR_RESET);
snd_soc_write(codec, INNO_R00,
INNO_R00_CSR_WORK | INNO_R00_CDCR_WORK);
}
static int rk3036_codec_probe(struct snd_soc_codec *codec)
{
rk3036_codec_reset(codec);
return 0;
}
static int rk3036_codec_remove(struct snd_soc_codec *codec)
{
rk3036_codec_reset(codec);
return 0;
}
static int rk3036_codec_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_STANDBY:
snd_soc_write(codec, INNO_R10, INNO_R10_MAX_CUR);
snd_soc_write(codec, INNO_R06, INNO_R06_DAC_PRECHARGE);
break;
case SND_SOC_BIAS_OFF:
snd_soc_write(codec, INNO_R10, INNO_R10_MAX_CUR);
snd_soc_write(codec, INNO_R06, INNO_R06_DAC_DISCHARGE);
break;
default:
break;
}
return 0;
}
static int rk3036_codec_platform_probe(struct platform_device *pdev)
{
struct rk3036_codec_priv *priv;
struct device_node *of_node = pdev->dev.of_node;
struct resource *res;
void __iomem *base;
struct regmap *grf;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
priv->base = base;
priv->regmap = devm_regmap_init_mmio(&pdev->dev, priv->base,
&rk3036_codec_regmap_config);
if (IS_ERR(priv->regmap)) {
dev_err(&pdev->dev, "init regmap failed\n");
return PTR_ERR(priv->regmap);
}
grf = syscon_regmap_lookup_by_phandle(of_node, "rockchip,grf");
if (IS_ERR(grf)) {
dev_err(&pdev->dev, "needs 'rockchip,grf' property\n");
return PTR_ERR(grf);
}
ret = regmap_write(grf, GRF_SOC_CON0, GRF_ACODEC_SEL);
if (ret) {
dev_err(&pdev->dev, "Could not write to GRF: %d\n", ret);
return ret;
}
priv->pclk = devm_clk_get(&pdev->dev, "acodec_pclk");
if (IS_ERR(priv->pclk))
return PTR_ERR(priv->pclk);
ret = clk_prepare_enable(priv->pclk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable clk\n");
return ret;
}
priv->dev = &pdev->dev;
dev_set_drvdata(&pdev->dev, priv);
ret = snd_soc_register_codec(&pdev->dev, &rk3036_codec_driver,
rk3036_codec_dai_driver,
ARRAY_SIZE(rk3036_codec_dai_driver));
if (ret) {
clk_disable_unprepare(priv->pclk);
dev_set_drvdata(&pdev->dev, NULL);
}
return ret;
}
static int rk3036_codec_platform_remove(struct platform_device *pdev)
{
struct rk3036_codec_priv *priv = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_codec(&pdev->dev);
clk_disable_unprepare(priv->pclk);
return 0;
}
