static int mc13783_pcm_hw_params_dac(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int rate = params_rate(params);
int i;
for (i = 0; i < ARRAY_SIZE(mc13783_rates); i++) {
if (rate == mc13783_rates[i]) {
snd_soc_update_bits(codec, MC13783_AUDIO_DAC,
0xf << 17, i << 17);
return 0;
}
}
return -EINVAL;
}
static int mc13783_pcm_hw_params_codec(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int rate = params_rate(params);
unsigned int val;
switch (rate) {
case 8000:
val = 0;
break;
case 16000:
val = AUDIO_CODEC_CDCFS8K16K;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, MC13783_AUDIO_CODEC, AUDIO_CODEC_CDCFS8K16K,
val);
return 0;
}
static int mc13783_pcm_hw_params_sync(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
return mc13783_pcm_hw_params_dac(substream, params, dai);
else
return mc13783_pcm_hw_params_codec(substream, params, dai);
}
static int mc13783_set_fmt(struct snd_soc_dai *dai, unsigned int fmt,
unsigned int reg)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
unsigned int mask = AUDIO_CFS(3) | AUDIO_BCL_INV | AUDIO_CFS_INV |
AUDIO_CSM | AUDIO_C_CLK_EN | AUDIO_C_RESET;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
val |= AUDIO_CFS(2);
break;
case SND_SOC_DAIFMT_DSP_A:
val |= AUDIO_CFS(1);
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
val |= AUDIO_BCL_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
val |= AUDIO_BCL_INV | AUDIO_CFS_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
val |= AUDIO_CFS_INV;
break;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
val |= AUDIO_C_CLK_EN;
break;
case SND_SOC_DAIFMT_CBS_CFS:
val |= AUDIO_CSM;
break;
case SND_SOC_DAIFMT_CBM_CFS:
case SND_SOC_DAIFMT_CBS_CFM:
return -EINVAL;
}
val |= AUDIO_C_RESET;
snd_soc_update_bits(codec, reg, mask, val);
return 0;
}
static int mc13783_set_fmt_async(struct snd_soc_dai *dai, unsigned int fmt)
{
if (dai->id == MC13783_ID_STEREO_DAC)
return mc13783_set_fmt(dai, fmt, MC13783_AUDIO_DAC);
else
return mc13783_set_fmt(dai, fmt, MC13783_AUDIO_CODEC);
}
static int mc13783_set_fmt_sync(struct snd_soc_dai *dai, unsigned int fmt)
{
int ret;
ret = mc13783_set_fmt(dai, fmt, MC13783_AUDIO_DAC);
if (ret)
return ret;
fmt &= ~SND_SOC_DAIFMT_MASTER_MASK;
fmt |= SND_SOC_DAIFMT_CBS_CFS;
ret = mc13783_set_fmt(dai, fmt, MC13783_AUDIO_CODEC);
return ret;
}
static int mc13783_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir,
unsigned int reg)
{
struct snd_soc_codec *codec = dai->codec;
int clk;
unsigned int val = 0;
unsigned int mask = AUDIO_CLK(0x7) | AUDIO_CLK_SEL;
for (clk = 0; clk < ARRAY_SIZE(mc13783_sysclk); clk++) {
if (mc13783_sysclk[clk] < 0)
continue;
if (mc13783_sysclk[clk] == freq)
break;
}
if (clk == ARRAY_SIZE(mc13783_sysclk))
return -EINVAL;
if (clk_id == MC13783_CLK_CLIB)
val |= AUDIO_CLK_SEL;
val |= AUDIO_CLK(clk);
snd_soc_update_bits(codec, reg, mask, val);
return 0;
}
static int mc13783_set_sysclk_dac(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
return mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_DAC);
}
static int mc13783_set_sysclk_codec(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
return mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_CODEC);
}
static int mc13783_set_sysclk_sync(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
int ret;
ret = mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_DAC);
if (ret)
return ret;
return mc13783_set_sysclk(dai, clk_id, freq, dir, MC13783_AUDIO_CODEC);
}
static int mc13783_set_tdm_slot_dac(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask, int slots,
int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
unsigned int mask = SSI_NETWORK_DAC_SLOT_MASK |
SSI_NETWORK_DAC_RXSLOT_MASK;
switch (slots) {
case 2:
val |= SSI_NETWORK_DAC_SLOTS_2;
break;
case 4:
val |= SSI_NETWORK_DAC_SLOTS_4;
break;
case 8:
val |= SSI_NETWORK_DAC_SLOTS_8;
break;
default:
return -EINVAL;
}
switch (rx_mask) {
case 0xfffffffc:
val |= SSI_NETWORK_DAC_RXSLOT_0_1;
break;
case 0xfffffff3:
val |= SSI_NETWORK_DAC_RXSLOT_2_3;
break;
case 0xffffffcf:
val |= SSI_NETWORK_DAC_RXSLOT_4_5;
break;
case 0xffffff3f:
val |= SSI_NETWORK_DAC_RXSLOT_6_7;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, MC13783_SSI_NETWORK, mask, val);
return 0;
}
static int mc13783_set_tdm_slot_codec(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask, int slots,
int slot_width)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
unsigned int mask = 0x3f;
if (slots != 4)
return -EINVAL;
if (tx_mask != 0xfffffffc)
return -EINVAL;
val |= (0x00 << 2);
val |= (0x01 << 4);
snd_soc_update_bits(codec, MC13783_SSI_NETWORK, mask, val);
return 0;
}
static int mc13783_set_tdm_slot_sync(struct snd_soc_dai *dai,
unsigned int tx_mask, unsigned int rx_mask, int slots,
int slot_width)
{
int ret;
ret = mc13783_set_tdm_slot_dac(dai, tx_mask, rx_mask, slots,
slot_width);
if (ret)
return ret;
ret = mc13783_set_tdm_slot_codec(dai, tx_mask, rx_mask, slots,
slot_width);
return ret;
}
static int mc13783_probe(struct snd_soc_codec *codec)
{
struct mc13783_priv *priv = snd_soc_codec_get_drvdata(codec);
mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_RX0, 0x25893);
mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_RX1, 0x00d35A);
mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_TX, 0x420000);
mc13xxx_reg_write(priv->mc13xxx, MC13783_SSI_NETWORK, 0x013060);
mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_CODEC, 0x180027);
mc13xxx_reg_write(priv->mc13xxx, MC13783_AUDIO_DAC, 0x0e0004);
if (priv->adc_ssi_port == MC13783_SSI1_PORT)
mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_CODEC,
AUDIO_SSI_SEL, 0);
else
mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_CODEC,
0, AUDIO_SSI_SEL);
if (priv->dac_ssi_port == MC13783_SSI1_PORT)
mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_DAC,
AUDIO_SSI_SEL, 0);
else
mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_DAC,
0, AUDIO_SSI_SEL);
return 0;
}
static int mc13783_remove(struct snd_soc_codec *codec)
{
struct mc13783_priv *priv = snd_soc_codec_get_drvdata(codec);
mc13xxx_reg_rmw(priv->mc13xxx, MC13783_AUDIO_RX0, 0x3, 0);
return 0;
}
static struct regmap *mc13783_get_regmap(struct device *dev)
{
return dev_get_regmap(dev->parent, NULL);
}
static int __init mc13783_codec_probe(struct platform_device *pdev)
{
struct mc13783_priv *priv;
struct mc13xxx_codec_platform_data *pdata = pdev->dev.platform_data;
struct device_node *np;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (pdata) {
priv->adc_ssi_port = pdata->adc_ssi_port;
priv->dac_ssi_port = pdata->dac_ssi_port;
} else {
np = of_get_child_by_name(pdev->dev.parent->of_node, "codec");
if (!np)
return -ENOSYS;
ret = of_property_read_u32(np, "adc-port", &priv->adc_ssi_port);
if (ret) {
of_node_put(np);
return ret;
}
ret = of_property_read_u32(np, "dac-port", &priv->dac_ssi_port);
if (ret) {
of_node_put(np);
return ret;
}
of_node_put(np);
}
dev_set_drvdata(&pdev->dev, priv);
priv->mc13xxx = dev_get_drvdata(pdev->dev.parent);
if (priv->adc_ssi_port == priv->dac_ssi_port)
ret = snd_soc_register_codec(&pdev->dev, &soc_codec_dev_mc13783,
mc13783_dai_sync, ARRAY_SIZE(mc13783_dai_sync));
else
ret = snd_soc_register_codec(&pdev->dev, &soc_codec_dev_mc13783,
mc13783_dai_async, ARRAY_SIZE(mc13783_dai_async));
return ret;
}
static int mc13783_codec_remove(struct platform_device *pdev)
{
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
