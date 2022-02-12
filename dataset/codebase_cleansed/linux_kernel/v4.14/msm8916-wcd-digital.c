static int msm8916_wcd_digital_enable_interpolator(
struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
usleep_range(10000, 10100);
snd_soc_write(codec, rx_gain_reg[w->shift],
snd_soc_read(codec, rx_gain_reg[w->shift]));
break;
}
return 0;
}
static int msm8916_wcd_digital_enable_dec(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int decimator = w->shift + 1;
u16 dec_reset_reg, tx_vol_ctl_reg, tx_mux_ctl_reg;
u8 dec_hpf_cut_of_freq;
dec_reset_reg = LPASS_CDC_CLK_TX_RESET_B1_CTL;
tx_vol_ctl_reg = LPASS_CDC_TX1_VOL_CTL_CFG + 32 * (decimator - 1);
tx_mux_ctl_reg = LPASS_CDC_TX1_MUX_CTL + 32 * (decimator - 1);
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, tx_vol_ctl_reg,
TX_VOL_CTL_CFG_MUTE_EN_MASK,
TX_VOL_CTL_CFG_MUTE_EN_ENABLE);
dec_hpf_cut_of_freq = snd_soc_read(codec, tx_mux_ctl_reg) &
TX_MUX_CTL_CUT_OFF_FREQ_MASK;
dec_hpf_cut_of_freq >>= TX_MUX_CTL_CUT_OFF_FREQ_SHIFT;
if (dec_hpf_cut_of_freq != TX_MUX_CTL_CF_NEG_3DB_150HZ) {
snd_soc_update_bits(codec, tx_mux_ctl_reg,
TX_MUX_CTL_CUT_OFF_FREQ_MASK,
TX_MUX_CTL_CF_NEG_3DB_150HZ);
}
break;
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, tx_mux_ctl_reg,
TX_MUX_CTL_HPF_BP_SEL_MASK,
TX_MUX_CTL_HPF_BP_SEL_NO_BYPASS);
snd_soc_write(codec, tx_gain_reg[w->shift],
snd_soc_read(codec, tx_gain_reg[w->shift]));
snd_soc_update_bits(codec, tx_vol_ctl_reg,
TX_VOL_CTL_CFG_MUTE_EN_MASK, 0);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, tx_vol_ctl_reg,
TX_VOL_CTL_CFG_MUTE_EN_MASK,
TX_VOL_CTL_CFG_MUTE_EN_ENABLE);
snd_soc_update_bits(codec, tx_mux_ctl_reg,
TX_MUX_CTL_HPF_BP_SEL_MASK,
TX_MUX_CTL_HPF_BP_SEL_BYPASS);
break;
case SND_SOC_DAPM_POST_PMD:
snd_soc_update_bits(codec, dec_reset_reg, 1 << w->shift,
1 << w->shift);
snd_soc_update_bits(codec, dec_reset_reg, 1 << w->shift, 0x0);
snd_soc_update_bits(codec, tx_mux_ctl_reg,
TX_MUX_CTL_HPF_BP_SEL_MASK,
TX_MUX_CTL_HPF_BP_SEL_BYPASS);
snd_soc_update_bits(codec, tx_vol_ctl_reg,
TX_VOL_CTL_CFG_MUTE_EN_MASK, 0);
break;
}
return 0;
}
static int msm8916_wcd_digital_enable_dmic(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol,
int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int dmic;
int ret;
char *dmic_num = strpbrk(w->name, "12");
if (dmic_num == NULL) {
dev_err(codec->dev, "Invalid DMIC\n");
return -EINVAL;
}
ret = kstrtouint(dmic_num, 10, &dmic);
if (ret < 0 || dmic > 2) {
dev_err(codec->dev, "Invalid DMIC line on the codec\n");
return -EINVAL;
}
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
snd_soc_update_bits(codec, LPASS_CDC_CLK_DMIC_B1_CTL,
DMIC_B1_CTL_DMIC0_CLK_SEL_MASK,
DMIC_B1_CTL_DMIC0_CLK_SEL_DIV3);
switch (dmic) {
case 1:
snd_soc_update_bits(codec, LPASS_CDC_TX1_DMIC_CTL,
TXN_DMIC_CTL_CLK_SEL_MASK,
TXN_DMIC_CTL_CLK_SEL_DIV3);
break;
case 2:
snd_soc_update_bits(codec, LPASS_CDC_TX2_DMIC_CTL,
TXN_DMIC_CTL_CLK_SEL_MASK,
TXN_DMIC_CTL_CLK_SEL_DIV3);
break;
}
break;
}
return 0;
}
static int msm8916_wcd_digital_get_clks(struct platform_device *pdev,
struct msm8916_wcd_digital_priv *priv)
{
struct device *dev = &pdev->dev;
priv->ahbclk = devm_clk_get(dev, "ahbix-clk");
if (IS_ERR(priv->ahbclk)) {
dev_err(dev, "failed to get ahbix clk\n");
return PTR_ERR(priv->ahbclk);
}
priv->mclk = devm_clk_get(dev, "mclk");
if (IS_ERR(priv->mclk)) {
dev_err(dev, "failed to get mclk\n");
return PTR_ERR(priv->mclk);
}
return 0;
}
static int msm8916_wcd_digital_codec_probe(struct snd_soc_codec *codec)
{
struct msm8916_wcd_digital_priv *priv = dev_get_drvdata(codec->dev);
snd_soc_codec_set_drvdata(codec, priv);
return 0;
}
static int msm8916_wcd_digital_codec_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source,
unsigned int freq, int dir)
{
struct msm8916_wcd_digital_priv *p = dev_get_drvdata(codec->dev);
return clk_set_rate(p->mclk, freq);
}
static int msm8916_wcd_digital_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
u8 tx_fs_rate;
u8 rx_fs_rate;
switch (params_rate(params)) {
case 8000:
tx_fs_rate = TX_I2S_CTL_TX_I2S_FS_RATE_F_8_KHZ;
rx_fs_rate = RX_I2S_CTL_RX_I2S_FS_RATE_F_8_KHZ;
break;
case 16000:
tx_fs_rate = TX_I2S_CTL_TX_I2S_FS_RATE_F_16_KHZ;
rx_fs_rate = RX_I2S_CTL_RX_I2S_FS_RATE_F_16_KHZ;
break;
case 32000:
tx_fs_rate = TX_I2S_CTL_TX_I2S_FS_RATE_F_32_KHZ;
rx_fs_rate = RX_I2S_CTL_RX_I2S_FS_RATE_F_32_KHZ;
break;
case 48000:
tx_fs_rate = TX_I2S_CTL_TX_I2S_FS_RATE_F_48_KHZ;
rx_fs_rate = RX_I2S_CTL_RX_I2S_FS_RATE_F_48_KHZ;
break;
default:
dev_err(dai->codec->dev, "Invalid sampling rate %d\n",
params_rate(params));
return -EINVAL;
}
switch (substream->stream) {
case SNDRV_PCM_STREAM_CAPTURE:
snd_soc_update_bits(dai->codec, LPASS_CDC_CLK_TX_I2S_CTL,
TX_I2S_CTL_TX_I2S_FS_RATE_MASK, tx_fs_rate);
break;
case SNDRV_PCM_STREAM_PLAYBACK:
snd_soc_update_bits(dai->codec, LPASS_CDC_CLK_RX_I2S_CTL,
RX_I2S_CTL_RX_I2S_FS_RATE_MASK, rx_fs_rate);
break;
default:
return -EINVAL;
}
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
snd_soc_update_bits(dai->codec, LPASS_CDC_CLK_TX_I2S_CTL,
TX_I2S_CTL_TX_I2S_MODE_MASK,
TX_I2S_CTL_TX_I2S_MODE_16);
snd_soc_update_bits(dai->codec, LPASS_CDC_CLK_RX_I2S_CTL,
RX_I2S_CTL_RX_I2S_MODE_MASK,
RX_I2S_CTL_RX_I2S_MODE_16);
break;
case SNDRV_PCM_FORMAT_S24_LE:
snd_soc_update_bits(dai->codec, LPASS_CDC_CLK_TX_I2S_CTL,
TX_I2S_CTL_TX_I2S_MODE_MASK,
TX_I2S_CTL_TX_I2S_MODE_32);
snd_soc_update_bits(dai->codec, LPASS_CDC_CLK_RX_I2S_CTL,
RX_I2S_CTL_RX_I2S_MODE_MASK,
RX_I2S_CTL_RX_I2S_MODE_32);
break;
default:
dev_err(dai->dev, "%s: wrong format selected\n", __func__);
return -EINVAL;
}
return 0;
}
static int msm8916_wcd_digital_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct msm8916_wcd_digital_priv *msm8916_wcd;
unsigned long mclk_rate;
msm8916_wcd = snd_soc_codec_get_drvdata(codec);
snd_soc_update_bits(codec, LPASS_CDC_CLK_MCLK_CTL,
MCLK_CTL_MCLK_EN_MASK,
MCLK_CTL_MCLK_EN_ENABLE);
snd_soc_update_bits(codec, LPASS_CDC_CLK_PDM_CTL,
LPASS_CDC_CLK_PDM_CTL_PDM_CLK_SEL_MASK,
LPASS_CDC_CLK_PDM_CTL_PDM_CLK_SEL_FB);
mclk_rate = clk_get_rate(msm8916_wcd->mclk);
switch (mclk_rate) {
case 12288000:
snd_soc_update_bits(codec, LPASS_CDC_TOP_CTL,
TOP_CTL_DIG_MCLK_FREQ_MASK,
TOP_CTL_DIG_MCLK_FREQ_F_12_288MHZ);
break;
case 9600000:
snd_soc_update_bits(codec, LPASS_CDC_TOP_CTL,
TOP_CTL_DIG_MCLK_FREQ_MASK,
TOP_CTL_DIG_MCLK_FREQ_F_9_6MHZ);
break;
default:
dev_err(codec->dev, "Invalid mclk rate %ld\n", mclk_rate);
break;
}
return 0;
}
static void msm8916_wcd_digital_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
snd_soc_update_bits(dai->codec, LPASS_CDC_CLK_PDM_CTL,
LPASS_CDC_CLK_PDM_CTL_PDM_CLK_SEL_MASK, 0);
}
static int msm8916_wcd_digital_probe(struct platform_device *pdev)
{
struct msm8916_wcd_digital_priv *priv;
struct device *dev = &pdev->dev;
void __iomem *base;
struct resource *mem_res;
struct regmap *digital_map;
int ret;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, mem_res);
if (IS_ERR(base))
return PTR_ERR(base);
digital_map =
devm_regmap_init_mmio(&pdev->dev, base,
&msm8916_codec_regmap_config);
if (IS_ERR(digital_map))
return PTR_ERR(digital_map);
ret = msm8916_wcd_digital_get_clks(pdev, priv);
if (ret < 0)
return ret;
ret = clk_prepare_enable(priv->ahbclk);
if (ret < 0) {
dev_err(dev, "failed to enable ahbclk %d\n", ret);
return ret;
}
ret = clk_prepare_enable(priv->mclk);
if (ret < 0) {
dev_err(dev, "failed to enable mclk %d\n", ret);
return ret;
}
dev_set_drvdata(dev, priv);
return snd_soc_register_codec(dev, &msm8916_wcd_digital,
msm8916_wcd_digital_dai,
ARRAY_SIZE(msm8916_wcd_digital_dai));
}
static int msm8916_wcd_digital_remove(struct platform_device *pdev)
{
struct msm8916_wcd_digital_priv *priv = dev_get_drvdata(&pdev->dev);
snd_soc_unregister_codec(&pdev->dev);
clk_disable_unprepare(priv->mclk);
clk_disable_unprepare(priv->ahbclk);
return 0;
}
