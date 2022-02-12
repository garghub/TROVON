static bool wm2200_volatile_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(wm2200_ranges); i++)
if ((reg >= wm2200_ranges[i].window_start &&
reg <= wm2200_ranges[i].window_start +
wm2200_ranges[i].window_len) ||
(reg >= wm2200_ranges[i].range_min &&
reg <= wm2200_ranges[i].range_max))
return true;
switch (reg) {
case WM2200_SOFTWARE_RESET:
case WM2200_DEVICE_REVISION:
case WM2200_ADPS1_IRQ0:
case WM2200_ADPS1_IRQ1:
case WM2200_INTERRUPT_STATUS_1:
case WM2200_INTERRUPT_STATUS_2:
case WM2200_INTERRUPT_RAW_STATUS_2:
return true;
default:
return false;
}
}
static bool wm2200_readable_register(struct device *dev, unsigned int reg)
{
int i;
for (i = 0; i < ARRAY_SIZE(wm2200_ranges); i++)
if ((reg >= wm2200_ranges[i].window_start &&
reg <= wm2200_ranges[i].window_start +
wm2200_ranges[i].window_len) ||
(reg >= wm2200_ranges[i].range_min &&
reg <= wm2200_ranges[i].range_max))
return true;
switch (reg) {
case WM2200_SOFTWARE_RESET:
case WM2200_DEVICE_REVISION:
case WM2200_TONE_GENERATOR_1:
case WM2200_CLOCKING_3:
case WM2200_CLOCKING_4:
case WM2200_FLL_CONTROL_1:
case WM2200_FLL_CONTROL_2:
case WM2200_FLL_CONTROL_3:
case WM2200_FLL_CONTROL_4:
case WM2200_FLL_CONTROL_6:
case WM2200_FLL_CONTROL_7:
case WM2200_FLL_EFS_1:
case WM2200_FLL_EFS_2:
case WM2200_MIC_CHARGE_PUMP_1:
case WM2200_MIC_CHARGE_PUMP_2:
case WM2200_DM_CHARGE_PUMP_1:
case WM2200_MIC_BIAS_CTRL_1:
case WM2200_MIC_BIAS_CTRL_2:
case WM2200_EAR_PIECE_CTRL_1:
case WM2200_EAR_PIECE_CTRL_2:
case WM2200_INPUT_ENABLES:
case WM2200_IN1L_CONTROL:
case WM2200_IN1R_CONTROL:
case WM2200_IN2L_CONTROL:
case WM2200_IN2R_CONTROL:
case WM2200_IN3L_CONTROL:
case WM2200_IN3R_CONTROL:
case WM2200_RXANC_SRC:
case WM2200_INPUT_VOLUME_RAMP:
case WM2200_ADC_DIGITAL_VOLUME_1L:
case WM2200_ADC_DIGITAL_VOLUME_1R:
case WM2200_ADC_DIGITAL_VOLUME_2L:
case WM2200_ADC_DIGITAL_VOLUME_2R:
case WM2200_ADC_DIGITAL_VOLUME_3L:
case WM2200_ADC_DIGITAL_VOLUME_3R:
case WM2200_OUTPUT_ENABLES:
case WM2200_DAC_VOLUME_LIMIT_1L:
case WM2200_DAC_VOLUME_LIMIT_1R:
case WM2200_DAC_VOLUME_LIMIT_2L:
case WM2200_DAC_VOLUME_LIMIT_2R:
case WM2200_DAC_AEC_CONTROL_1:
case WM2200_OUTPUT_VOLUME_RAMP:
case WM2200_DAC_DIGITAL_VOLUME_1L:
case WM2200_DAC_DIGITAL_VOLUME_1R:
case WM2200_DAC_DIGITAL_VOLUME_2L:
case WM2200_DAC_DIGITAL_VOLUME_2R:
case WM2200_PDM_1:
case WM2200_PDM_2:
case WM2200_AUDIO_IF_1_1:
case WM2200_AUDIO_IF_1_2:
case WM2200_AUDIO_IF_1_3:
case WM2200_AUDIO_IF_1_4:
case WM2200_AUDIO_IF_1_5:
case WM2200_AUDIO_IF_1_6:
case WM2200_AUDIO_IF_1_7:
case WM2200_AUDIO_IF_1_8:
case WM2200_AUDIO_IF_1_9:
case WM2200_AUDIO_IF_1_10:
case WM2200_AUDIO_IF_1_11:
case WM2200_AUDIO_IF_1_12:
case WM2200_AUDIO_IF_1_13:
case WM2200_AUDIO_IF_1_14:
case WM2200_AUDIO_IF_1_15:
case WM2200_AUDIO_IF_1_16:
case WM2200_AUDIO_IF_1_17:
case WM2200_AUDIO_IF_1_18:
case WM2200_AUDIO_IF_1_19:
case WM2200_AUDIO_IF_1_20:
case WM2200_AUDIO_IF_1_21:
case WM2200_AUDIO_IF_1_22:
case WM2200_OUT1LMIX_INPUT_1_SOURCE:
case WM2200_OUT1LMIX_INPUT_1_VOLUME:
case WM2200_OUT1LMIX_INPUT_2_SOURCE:
case WM2200_OUT1LMIX_INPUT_2_VOLUME:
case WM2200_OUT1LMIX_INPUT_3_SOURCE:
case WM2200_OUT1LMIX_INPUT_3_VOLUME:
case WM2200_OUT1LMIX_INPUT_4_SOURCE:
case WM2200_OUT1LMIX_INPUT_4_VOLUME:
case WM2200_OUT1RMIX_INPUT_1_SOURCE:
case WM2200_OUT1RMIX_INPUT_1_VOLUME:
case WM2200_OUT1RMIX_INPUT_2_SOURCE:
case WM2200_OUT1RMIX_INPUT_2_VOLUME:
case WM2200_OUT1RMIX_INPUT_3_SOURCE:
case WM2200_OUT1RMIX_INPUT_3_VOLUME:
case WM2200_OUT1RMIX_INPUT_4_SOURCE:
case WM2200_OUT1RMIX_INPUT_4_VOLUME:
case WM2200_OUT2LMIX_INPUT_1_SOURCE:
case WM2200_OUT2LMIX_INPUT_1_VOLUME:
case WM2200_OUT2LMIX_INPUT_2_SOURCE:
case WM2200_OUT2LMIX_INPUT_2_VOLUME:
case WM2200_OUT2LMIX_INPUT_3_SOURCE:
case WM2200_OUT2LMIX_INPUT_3_VOLUME:
case WM2200_OUT2LMIX_INPUT_4_SOURCE:
case WM2200_OUT2LMIX_INPUT_4_VOLUME:
case WM2200_OUT2RMIX_INPUT_1_SOURCE:
case WM2200_OUT2RMIX_INPUT_1_VOLUME:
case WM2200_OUT2RMIX_INPUT_2_SOURCE:
case WM2200_OUT2RMIX_INPUT_2_VOLUME:
case WM2200_OUT2RMIX_INPUT_3_SOURCE:
case WM2200_OUT2RMIX_INPUT_3_VOLUME:
case WM2200_OUT2RMIX_INPUT_4_SOURCE:
case WM2200_OUT2RMIX_INPUT_4_VOLUME:
case WM2200_AIF1TX1MIX_INPUT_1_SOURCE:
case WM2200_AIF1TX1MIX_INPUT_1_VOLUME:
case WM2200_AIF1TX1MIX_INPUT_2_SOURCE:
case WM2200_AIF1TX1MIX_INPUT_2_VOLUME:
case WM2200_AIF1TX1MIX_INPUT_3_SOURCE:
case WM2200_AIF1TX1MIX_INPUT_3_VOLUME:
case WM2200_AIF1TX1MIX_INPUT_4_SOURCE:
case WM2200_AIF1TX1MIX_INPUT_4_VOLUME:
case WM2200_AIF1TX2MIX_INPUT_1_SOURCE:
case WM2200_AIF1TX2MIX_INPUT_1_VOLUME:
case WM2200_AIF1TX2MIX_INPUT_2_SOURCE:
case WM2200_AIF1TX2MIX_INPUT_2_VOLUME:
case WM2200_AIF1TX2MIX_INPUT_3_SOURCE:
case WM2200_AIF1TX2MIX_INPUT_3_VOLUME:
case WM2200_AIF1TX2MIX_INPUT_4_SOURCE:
case WM2200_AIF1TX2MIX_INPUT_4_VOLUME:
case WM2200_AIF1TX3MIX_INPUT_1_SOURCE:
case WM2200_AIF1TX3MIX_INPUT_1_VOLUME:
case WM2200_AIF1TX3MIX_INPUT_2_SOURCE:
case WM2200_AIF1TX3MIX_INPUT_2_VOLUME:
case WM2200_AIF1TX3MIX_INPUT_3_SOURCE:
case WM2200_AIF1TX3MIX_INPUT_3_VOLUME:
case WM2200_AIF1TX3MIX_INPUT_4_SOURCE:
case WM2200_AIF1TX3MIX_INPUT_4_VOLUME:
case WM2200_AIF1TX4MIX_INPUT_1_SOURCE:
case WM2200_AIF1TX4MIX_INPUT_1_VOLUME:
case WM2200_AIF1TX4MIX_INPUT_2_SOURCE:
case WM2200_AIF1TX4MIX_INPUT_2_VOLUME:
case WM2200_AIF1TX4MIX_INPUT_3_SOURCE:
case WM2200_AIF1TX4MIX_INPUT_3_VOLUME:
case WM2200_AIF1TX4MIX_INPUT_4_SOURCE:
case WM2200_AIF1TX4MIX_INPUT_4_VOLUME:
case WM2200_AIF1TX5MIX_INPUT_1_SOURCE:
case WM2200_AIF1TX5MIX_INPUT_1_VOLUME:
case WM2200_AIF1TX5MIX_INPUT_2_SOURCE:
case WM2200_AIF1TX5MIX_INPUT_2_VOLUME:
case WM2200_AIF1TX5MIX_INPUT_3_SOURCE:
case WM2200_AIF1TX5MIX_INPUT_3_VOLUME:
case WM2200_AIF1TX5MIX_INPUT_4_SOURCE:
case WM2200_AIF1TX5MIX_INPUT_4_VOLUME:
case WM2200_AIF1TX6MIX_INPUT_1_SOURCE:
case WM2200_AIF1TX6MIX_INPUT_1_VOLUME:
case WM2200_AIF1TX6MIX_INPUT_2_SOURCE:
case WM2200_AIF1TX6MIX_INPUT_2_VOLUME:
case WM2200_AIF1TX6MIX_INPUT_3_SOURCE:
case WM2200_AIF1TX6MIX_INPUT_3_VOLUME:
case WM2200_AIF1TX6MIX_INPUT_4_SOURCE:
case WM2200_AIF1TX6MIX_INPUT_4_VOLUME:
case WM2200_EQLMIX_INPUT_1_SOURCE:
case WM2200_EQLMIX_INPUT_1_VOLUME:
case WM2200_EQLMIX_INPUT_2_SOURCE:
case WM2200_EQLMIX_INPUT_2_VOLUME:
case WM2200_EQLMIX_INPUT_3_SOURCE:
case WM2200_EQLMIX_INPUT_3_VOLUME:
case WM2200_EQLMIX_INPUT_4_SOURCE:
case WM2200_EQLMIX_INPUT_4_VOLUME:
case WM2200_EQRMIX_INPUT_1_SOURCE:
case WM2200_EQRMIX_INPUT_1_VOLUME:
case WM2200_EQRMIX_INPUT_2_SOURCE:
case WM2200_EQRMIX_INPUT_2_VOLUME:
case WM2200_EQRMIX_INPUT_3_SOURCE:
case WM2200_EQRMIX_INPUT_3_VOLUME:
case WM2200_EQRMIX_INPUT_4_SOURCE:
case WM2200_EQRMIX_INPUT_4_VOLUME:
case WM2200_LHPF1MIX_INPUT_1_SOURCE:
case WM2200_LHPF1MIX_INPUT_1_VOLUME:
case WM2200_LHPF1MIX_INPUT_2_SOURCE:
case WM2200_LHPF1MIX_INPUT_2_VOLUME:
case WM2200_LHPF1MIX_INPUT_3_SOURCE:
case WM2200_LHPF1MIX_INPUT_3_VOLUME:
case WM2200_LHPF1MIX_INPUT_4_SOURCE:
case WM2200_LHPF1MIX_INPUT_4_VOLUME:
case WM2200_LHPF2MIX_INPUT_1_SOURCE:
case WM2200_LHPF2MIX_INPUT_1_VOLUME:
case WM2200_LHPF2MIX_INPUT_2_SOURCE:
case WM2200_LHPF2MIX_INPUT_2_VOLUME:
case WM2200_LHPF2MIX_INPUT_3_SOURCE:
case WM2200_LHPF2MIX_INPUT_3_VOLUME:
case WM2200_LHPF2MIX_INPUT_4_SOURCE:
case WM2200_LHPF2MIX_INPUT_4_VOLUME:
case WM2200_DSP1LMIX_INPUT_1_SOURCE:
case WM2200_DSP1LMIX_INPUT_1_VOLUME:
case WM2200_DSP1LMIX_INPUT_2_SOURCE:
case WM2200_DSP1LMIX_INPUT_2_VOLUME:
case WM2200_DSP1LMIX_INPUT_3_SOURCE:
case WM2200_DSP1LMIX_INPUT_3_VOLUME:
case WM2200_DSP1LMIX_INPUT_4_SOURCE:
case WM2200_DSP1LMIX_INPUT_4_VOLUME:
case WM2200_DSP1RMIX_INPUT_1_SOURCE:
case WM2200_DSP1RMIX_INPUT_1_VOLUME:
case WM2200_DSP1RMIX_INPUT_2_SOURCE:
case WM2200_DSP1RMIX_INPUT_2_VOLUME:
case WM2200_DSP1RMIX_INPUT_3_SOURCE:
case WM2200_DSP1RMIX_INPUT_3_VOLUME:
case WM2200_DSP1RMIX_INPUT_4_SOURCE:
case WM2200_DSP1RMIX_INPUT_4_VOLUME:
case WM2200_DSP1AUX1MIX_INPUT_1_SOURCE:
case WM2200_DSP1AUX2MIX_INPUT_1_SOURCE:
case WM2200_DSP1AUX3MIX_INPUT_1_SOURCE:
case WM2200_DSP1AUX4MIX_INPUT_1_SOURCE:
case WM2200_DSP1AUX5MIX_INPUT_1_SOURCE:
case WM2200_DSP1AUX6MIX_INPUT_1_SOURCE:
case WM2200_DSP2LMIX_INPUT_1_SOURCE:
case WM2200_DSP2LMIX_INPUT_1_VOLUME:
case WM2200_DSP2LMIX_INPUT_2_SOURCE:
case WM2200_DSP2LMIX_INPUT_2_VOLUME:
case WM2200_DSP2LMIX_INPUT_3_SOURCE:
case WM2200_DSP2LMIX_INPUT_3_VOLUME:
case WM2200_DSP2LMIX_INPUT_4_SOURCE:
case WM2200_DSP2LMIX_INPUT_4_VOLUME:
case WM2200_DSP2RMIX_INPUT_1_SOURCE:
case WM2200_DSP2RMIX_INPUT_1_VOLUME:
case WM2200_DSP2RMIX_INPUT_2_SOURCE:
case WM2200_DSP2RMIX_INPUT_2_VOLUME:
case WM2200_DSP2RMIX_INPUT_3_SOURCE:
case WM2200_DSP2RMIX_INPUT_3_VOLUME:
case WM2200_DSP2RMIX_INPUT_4_SOURCE:
case WM2200_DSP2RMIX_INPUT_4_VOLUME:
case WM2200_DSP2AUX1MIX_INPUT_1_SOURCE:
case WM2200_DSP2AUX2MIX_INPUT_1_SOURCE:
case WM2200_DSP2AUX3MIX_INPUT_1_SOURCE:
case WM2200_DSP2AUX4MIX_INPUT_1_SOURCE:
case WM2200_DSP2AUX5MIX_INPUT_1_SOURCE:
case WM2200_DSP2AUX6MIX_INPUT_1_SOURCE:
case WM2200_GPIO_CTRL_1:
case WM2200_GPIO_CTRL_2:
case WM2200_GPIO_CTRL_3:
case WM2200_GPIO_CTRL_4:
case WM2200_ADPS1_IRQ0:
case WM2200_ADPS1_IRQ1:
case WM2200_MISC_PAD_CTRL_1:
case WM2200_INTERRUPT_STATUS_1:
case WM2200_INTERRUPT_STATUS_1_MASK:
case WM2200_INTERRUPT_STATUS_2:
case WM2200_INTERRUPT_RAW_STATUS_2:
case WM2200_INTERRUPT_STATUS_2_MASK:
case WM2200_INTERRUPT_CONTROL:
case WM2200_EQL_1:
case WM2200_EQL_2:
case WM2200_EQL_3:
case WM2200_EQL_4:
case WM2200_EQL_5:
case WM2200_EQL_6:
case WM2200_EQL_7:
case WM2200_EQL_8:
case WM2200_EQL_9:
case WM2200_EQL_10:
case WM2200_EQL_11:
case WM2200_EQL_12:
case WM2200_EQL_13:
case WM2200_EQL_14:
case WM2200_EQL_15:
case WM2200_EQL_16:
case WM2200_EQL_17:
case WM2200_EQL_18:
case WM2200_EQL_19:
case WM2200_EQL_20:
case WM2200_EQR_1:
case WM2200_EQR_2:
case WM2200_EQR_3:
case WM2200_EQR_4:
case WM2200_EQR_5:
case WM2200_EQR_6:
case WM2200_EQR_7:
case WM2200_EQR_8:
case WM2200_EQR_9:
case WM2200_EQR_10:
case WM2200_EQR_11:
case WM2200_EQR_12:
case WM2200_EQR_13:
case WM2200_EQR_14:
case WM2200_EQR_15:
case WM2200_EQR_16:
case WM2200_EQR_17:
case WM2200_EQR_18:
case WM2200_EQR_19:
case WM2200_EQR_20:
case WM2200_HPLPF1_1:
case WM2200_HPLPF1_2:
case WM2200_HPLPF2_1:
case WM2200_HPLPF2_2:
case WM2200_DSP1_CONTROL_1:
case WM2200_DSP1_CONTROL_2:
case WM2200_DSP1_CONTROL_3:
case WM2200_DSP1_CONTROL_4:
case WM2200_DSP1_CONTROL_5:
case WM2200_DSP1_CONTROL_6:
case WM2200_DSP1_CONTROL_7:
case WM2200_DSP1_CONTROL_8:
case WM2200_DSP1_CONTROL_9:
case WM2200_DSP1_CONTROL_10:
case WM2200_DSP1_CONTROL_11:
case WM2200_DSP1_CONTROL_12:
case WM2200_DSP1_CONTROL_13:
case WM2200_DSP1_CONTROL_14:
case WM2200_DSP1_CONTROL_15:
case WM2200_DSP1_CONTROL_16:
case WM2200_DSP1_CONTROL_17:
case WM2200_DSP1_CONTROL_18:
case WM2200_DSP1_CONTROL_19:
case WM2200_DSP1_CONTROL_20:
case WM2200_DSP1_CONTROL_21:
case WM2200_DSP1_CONTROL_22:
case WM2200_DSP1_CONTROL_23:
case WM2200_DSP1_CONTROL_24:
case WM2200_DSP1_CONTROL_25:
case WM2200_DSP1_CONTROL_26:
case WM2200_DSP1_CONTROL_27:
case WM2200_DSP1_CONTROL_28:
case WM2200_DSP1_CONTROL_29:
case WM2200_DSP1_CONTROL_30:
case WM2200_DSP1_CONTROL_31:
case WM2200_DSP2_CONTROL_1:
case WM2200_DSP2_CONTROL_2:
case WM2200_DSP2_CONTROL_3:
case WM2200_DSP2_CONTROL_4:
case WM2200_DSP2_CONTROL_5:
case WM2200_DSP2_CONTROL_6:
case WM2200_DSP2_CONTROL_7:
case WM2200_DSP2_CONTROL_8:
case WM2200_DSP2_CONTROL_9:
case WM2200_DSP2_CONTROL_10:
case WM2200_DSP2_CONTROL_11:
case WM2200_DSP2_CONTROL_12:
case WM2200_DSP2_CONTROL_13:
case WM2200_DSP2_CONTROL_14:
case WM2200_DSP2_CONTROL_15:
case WM2200_DSP2_CONTROL_16:
case WM2200_DSP2_CONTROL_17:
case WM2200_DSP2_CONTROL_18:
case WM2200_DSP2_CONTROL_19:
case WM2200_DSP2_CONTROL_20:
case WM2200_DSP2_CONTROL_21:
case WM2200_DSP2_CONTROL_22:
case WM2200_DSP2_CONTROL_23:
case WM2200_DSP2_CONTROL_24:
case WM2200_DSP2_CONTROL_25:
case WM2200_DSP2_CONTROL_26:
case WM2200_DSP2_CONTROL_27:
case WM2200_DSP2_CONTROL_28:
case WM2200_DSP2_CONTROL_29:
case WM2200_DSP2_CONTROL_30:
case WM2200_DSP2_CONTROL_31:
return true;
default:
return false;
}
}
static int wm2200_reset(struct wm2200_priv *wm2200)
{
if (wm2200->pdata.reset) {
gpio_set_value_cansleep(wm2200->pdata.reset, 0);
gpio_set_value_cansleep(wm2200->pdata.reset, 1);
return 0;
} else {
return regmap_write(wm2200->regmap, WM2200_SOFTWARE_RESET,
0x2200);
}
}
static int wm2200_probe(struct snd_soc_codec *codec)
{
struct wm2200_priv *wm2200 = dev_get_drvdata(codec->dev);
int ret;
wm2200->codec = codec;
codec->control_data = wm2200->regmap;
codec->dapm.bias_level = SND_SOC_BIAS_OFF;
ret = snd_soc_codec_set_cache_io(codec, 16, 16, SND_SOC_REGMAP);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
return ret;
}
static int wm2200_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
int lrclk, bclk, fmt_val;
lrclk = 0;
bclk = 0;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_DSP_A:
fmt_val = 0;
break;
case SND_SOC_DAIFMT_I2S:
fmt_val = 2;
break;
default:
dev_err(codec->dev, "Unsupported DAI format %d\n",
fmt & SND_SOC_DAIFMT_FORMAT_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBS_CFS:
break;
case SND_SOC_DAIFMT_CBS_CFM:
lrclk |= WM2200_AIF1TX_LRCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFS:
bclk |= WM2200_AIF1_BCLK_MSTR;
break;
case SND_SOC_DAIFMT_CBM_CFM:
lrclk |= WM2200_AIF1TX_LRCLK_MSTR;
bclk |= WM2200_AIF1_BCLK_MSTR;
break;
default:
dev_err(codec->dev, "Unsupported master mode %d\n",
fmt & SND_SOC_DAIFMT_MASTER_MASK);
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_IB_IF:
bclk |= WM2200_AIF1_BCLK_INV;
lrclk |= WM2200_AIF1TX_LRCLK_INV;
break;
case SND_SOC_DAIFMT_IB_NF:
bclk |= WM2200_AIF1_BCLK_INV;
break;
case SND_SOC_DAIFMT_NB_IF:
lrclk |= WM2200_AIF1TX_LRCLK_INV;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_1, WM2200_AIF1_BCLK_MSTR |
WM2200_AIF1_BCLK_INV, bclk);
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_2,
WM2200_AIF1TX_LRCLK_MSTR | WM2200_AIF1TX_LRCLK_INV,
lrclk);
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_3,
WM2200_AIF1TX_LRCLK_MSTR | WM2200_AIF1TX_LRCLK_INV,
lrclk);
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_5,
WM2200_AIF1_FMT_MASK, fmt_val);
return 0;
}
static int wm2200_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm2200_priv *wm2200 = snd_soc_codec_get_drvdata(codec);
int i, bclk, lrclk, wl, fl, sr_code;
int *bclk_rates;
wl = snd_pcm_format_width(params_format(params));
if (wl < 0)
return wl;
fl = snd_soc_params_to_frame_size(params);
if (fl < 0)
return fl;
dev_dbg(codec->dev, "Word length %d bits, frame length %d bits\n",
wl, fl);
bclk = snd_soc_params_to_bclk(params);
if (bclk < 0)
return bclk;
if (!wm2200->sysclk) {
dev_err(codec->dev, "SYSCLK has no rate set\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(wm2200_sr_code); i++)
if (wm2200_sr_code[i] == params_rate(params))
break;
if (i == ARRAY_SIZE(wm2200_sr_code)) {
dev_err(codec->dev, "Unsupported sample rate: %dHz\n",
params_rate(params));
return -EINVAL;
}
sr_code = i;
dev_dbg(codec->dev, "Target BCLK is %dHz, using %dHz SYSCLK\n",
bclk, wm2200->sysclk);
if (wm2200->sysclk % 4000)
bclk_rates = wm2200_bclk_rates_cd;
else
bclk_rates = wm2200_bclk_rates_dat;
for (i = 0; i < WM2200_NUM_BCLK_RATES; i++)
if (bclk_rates[i] >= bclk && (bclk_rates[i] % bclk == 0))
break;
if (i == WM2200_NUM_BCLK_RATES) {
dev_err(codec->dev,
"No valid BCLK for %dHz found from %dHz SYSCLK\n",
bclk, wm2200->sysclk);
return -EINVAL;
}
bclk = i;
dev_dbg(codec->dev, "Setting %dHz BCLK\n", bclk_rates[bclk]);
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_1,
WM2200_AIF1_BCLK_DIV_MASK, bclk);
lrclk = bclk_rates[bclk] / params_rate(params);
dev_dbg(codec->dev, "Setting %dHz LRCLK\n", bclk_rates[bclk] / lrclk);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK ||
dai->symmetric_rates)
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_7,
WM2200_AIF1RX_BCPF_MASK, lrclk);
else
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_6,
WM2200_AIF1TX_BCPF_MASK, lrclk);
i = (wl << WM2200_AIF1TX_WL_SHIFT) | wl;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_9,
WM2200_AIF1RX_WL_MASK |
WM2200_AIF1RX_SLOT_LEN_MASK, i);
else
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_8,
WM2200_AIF1TX_WL_MASK |
WM2200_AIF1TX_SLOT_LEN_MASK, i);
snd_soc_update_bits(codec, WM2200_CLOCKING_4,
WM2200_SAMPLE_RATE_1_MASK, sr_code);
return 0;
}
static int wm2200_set_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
struct wm2200_priv *wm2200 = snd_soc_codec_get_drvdata(codec);
int fval;
switch (clk_id) {
case WM2200_CLK_SYSCLK:
break;
default:
dev_err(codec->dev, "Unknown clock %d\n", clk_id);
return -EINVAL;
}
switch (source) {
case WM2200_CLKSRC_MCLK1:
case WM2200_CLKSRC_MCLK2:
case WM2200_CLKSRC_FLL:
case WM2200_CLKSRC_BCLK1:
break;
default:
dev_err(codec->dev, "Invalid source %d\n", source);
return -EINVAL;
}
switch (freq) {
case 22579200:
case 24576000:
fval = 2;
break;
default:
dev_err(codec->dev, "Invalid clock rate: %d\n", freq);
return -EINVAL;
}
snd_soc_update_bits(codec, WM2200_CLOCKING_3, WM2200_SYSCLK_FREQ_MASK |
WM2200_SYSCLK_SRC_MASK,
fval << WM2200_SYSCLK_FREQ_SHIFT | source);
wm2200->sysclk = freq;
return 0;
}
static int fll_factors(struct _fll_div *fll_div, unsigned int Fref,
unsigned int Fout)
{
unsigned int target;
unsigned int div;
unsigned int fratio, gcd_fll;
int i;
div = 1;
fll_div->fll_refclk_div = 0;
while ((Fref / div) > 13500000) {
div *= 2;
fll_div->fll_refclk_div++;
if (div > 8) {
pr_err("Can't scale %dMHz input down to <=13.5MHz\n",
Fref);
return -EINVAL;
}
}
pr_debug("FLL Fref=%u Fout=%u\n", Fref, Fout);
Fref /= div;
div = 2;
while (Fout * div < 90000000) {
div++;
if (div > 64) {
pr_err("Unable to find FLL_OUTDIV for Fout=%uHz\n",
Fout);
return -EINVAL;
}
}
target = Fout * div;
fll_div->fll_outdiv = div - 1;
pr_debug("FLL Fvco=%dHz\n", target);
for (i = 0; i < ARRAY_SIZE(fll_fratios); i++) {
if (fll_fratios[i].min <= Fref && Fref <= fll_fratios[i].max) {
fll_div->fll_fratio = fll_fratios[i].fll_fratio;
fratio = fll_fratios[i].ratio;
break;
}
}
if (i == ARRAY_SIZE(fll_fratios)) {
pr_err("Unable to find FLL_FRATIO for Fref=%uHz\n", Fref);
return -EINVAL;
}
fll_div->n = target / (fratio * Fref);
if (target % Fref == 0) {
fll_div->theta = 0;
fll_div->lambda = 0;
} else {
gcd_fll = gcd(target, fratio * Fref);
fll_div->theta = (target - (fll_div->n * fratio * Fref))
/ gcd_fll;
fll_div->lambda = (fratio * Fref) / gcd_fll;
}
pr_debug("FLL N=%x THETA=%x LAMBDA=%x\n",
fll_div->n, fll_div->theta, fll_div->lambda);
pr_debug("FLL_FRATIO=%x(%d) FLL_OUTDIV=%x FLL_REFCLK_DIV=%x\n",
fll_div->fll_fratio, fratio, fll_div->fll_outdiv,
fll_div->fll_refclk_div);
return 0;
}
static int wm2200_set_fll(struct snd_soc_codec *codec, int fll_id, int source,
unsigned int Fref, unsigned int Fout)
{
struct i2c_client *i2c = to_i2c_client(codec->dev);
struct wm2200_priv *wm2200 = snd_soc_codec_get_drvdata(codec);
struct _fll_div factors;
int ret, i, timeout;
if (!Fout) {
dev_dbg(codec->dev, "FLL disabled");
if (wm2200->fll_fout)
pm_runtime_put(codec->dev);
wm2200->fll_fout = 0;
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_1,
WM2200_FLL_ENA, 0);
return 0;
}
switch (source) {
case WM2200_FLL_SRC_MCLK1:
case WM2200_FLL_SRC_MCLK2:
case WM2200_FLL_SRC_BCLK:
break;
default:
dev_err(codec->dev, "Invalid FLL source %d\n", source);
return -EINVAL;
}
ret = fll_factors(&factors, Fref, Fout);
if (ret < 0)
return ret;
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_1, WM2200_FLL_ENA, 0);
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_2,
WM2200_FLL_OUTDIV_MASK | WM2200_FLL_FRATIO_MASK,
(factors.fll_outdiv << WM2200_FLL_OUTDIV_SHIFT) |
factors.fll_fratio);
if (factors.theta) {
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_3,
WM2200_FLL_FRACN_ENA,
WM2200_FLL_FRACN_ENA);
snd_soc_update_bits(codec, WM2200_FLL_EFS_2,
WM2200_FLL_EFS_ENA,
WM2200_FLL_EFS_ENA);
} else {
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_3,
WM2200_FLL_FRACN_ENA, 0);
snd_soc_update_bits(codec, WM2200_FLL_EFS_2,
WM2200_FLL_EFS_ENA, 0);
}
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_4, WM2200_FLL_THETA_MASK,
factors.theta);
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_6, WM2200_FLL_N_MASK,
factors.n);
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_7,
WM2200_FLL_CLK_REF_DIV_MASK |
WM2200_FLL_CLK_REF_SRC_MASK,
(factors.fll_refclk_div
<< WM2200_FLL_CLK_REF_DIV_SHIFT) | source);
snd_soc_update_bits(codec, WM2200_FLL_EFS_1,
WM2200_FLL_LAMBDA_MASK, factors.lambda);
try_wait_for_completion(&wm2200->fll_lock);
pm_runtime_get_sync(codec->dev);
snd_soc_update_bits(codec, WM2200_FLL_CONTROL_1,
WM2200_FLL_ENA, WM2200_FLL_ENA);
if (i2c->irq)
timeout = 2;
else
timeout = 50;
snd_soc_update_bits(codec, WM2200_CLOCKING_3, WM2200_SYSCLK_ENA,
WM2200_SYSCLK_ENA);
for (i = 0; i < timeout; i++) {
if (i2c->irq) {
ret = wait_for_completion_timeout(&wm2200->fll_lock,
msecs_to_jiffies(25));
if (ret > 0)
break;
} else {
msleep(1);
}
ret = snd_soc_read(codec,
WM2200_INTERRUPT_RAW_STATUS_2);
if (ret < 0) {
dev_err(codec->dev,
"Failed to read FLL status: %d\n",
ret);
continue;
}
if (ret & WM2200_FLL_LOCK_STS)
break;
}
if (i == timeout) {
dev_err(codec->dev, "FLL lock timed out\n");
pm_runtime_put(codec->dev);
return -ETIMEDOUT;
}
wm2200->fll_src = source;
wm2200->fll_fref = Fref;
wm2200->fll_fout = Fout;
dev_dbg(codec->dev, "FLL running %dHz->%dHz\n", Fref, Fout);
return 0;
}
static int wm2200_dai_probe(struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int val = 0;
int ret;
ret = snd_soc_read(codec, WM2200_GPIO_CTRL_1);
if (ret >= 0) {
if ((ret & WM2200_GP1_FN_MASK) != 0) {
dai->symmetric_rates = true;
val = WM2200_AIF1TX_LRCLK_SRC;
}
} else {
dev_err(codec->dev, "Failed to read GPIO 1 config: %d\n", ret);
}
snd_soc_update_bits(codec, WM2200_AUDIO_IF_1_2,
WM2200_AIF1TX_LRCLK_SRC, val);
return 0;
}
static irqreturn_t wm2200_irq(int irq, void *data)
{
struct wm2200_priv *wm2200 = data;
unsigned int val, mask;
int ret;
ret = regmap_read(wm2200->regmap, WM2200_INTERRUPT_STATUS_2, &val);
if (ret != 0) {
dev_err(wm2200->dev, "Failed to read IRQ status: %d\n", ret);
return IRQ_NONE;
}
ret = regmap_read(wm2200->regmap, WM2200_INTERRUPT_STATUS_2_MASK,
&mask);
if (ret != 0) {
dev_warn(wm2200->dev, "Failed to read IRQ mask: %d\n", ret);
mask = 0;
}
val &= ~mask;
if (val & WM2200_FLL_LOCK_EINT) {
dev_dbg(wm2200->dev, "FLL locked\n");
complete(&wm2200->fll_lock);
}
if (val) {
regmap_write(wm2200->regmap, WM2200_INTERRUPT_STATUS_2, val);
return IRQ_HANDLED;
} else {
return IRQ_NONE;
}
}
static int wm2200_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm2200_pdata *pdata = dev_get_platdata(&i2c->dev);
struct wm2200_priv *wm2200;
unsigned int reg;
int ret, i;
wm2200 = devm_kzalloc(&i2c->dev, sizeof(struct wm2200_priv),
GFP_KERNEL);
if (wm2200 == NULL)
return -ENOMEM;
wm2200->dev = &i2c->dev;
init_completion(&wm2200->fll_lock);
wm2200->regmap = devm_regmap_init_i2c(i2c, &wm2200_regmap);
if (IS_ERR(wm2200->regmap)) {
ret = PTR_ERR(wm2200->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
for (i = 0; i < 2; i++) {
wm2200->dsp[i].type = WMFW_ADSP1;
wm2200->dsp[i].part = "wm2200";
wm2200->dsp[i].num = i + 1;
wm2200->dsp[i].dev = &i2c->dev;
wm2200->dsp[i].regmap = wm2200->regmap;
}
wm2200->dsp[0].base = WM2200_DSP1_CONTROL_1;
wm2200->dsp[0].mem = wm2200_dsp1_regions;
wm2200->dsp[0].num_mems = ARRAY_SIZE(wm2200_dsp1_regions);
wm2200->dsp[1].base = WM2200_DSP2_CONTROL_1;
wm2200->dsp[1].mem = wm2200_dsp2_regions;
wm2200->dsp[1].num_mems = ARRAY_SIZE(wm2200_dsp2_regions);
if (pdata)
wm2200->pdata = *pdata;
i2c_set_clientdata(i2c, wm2200);
for (i = 0; i < ARRAY_SIZE(wm2200->core_supplies); i++)
wm2200->core_supplies[i].supply = wm2200_core_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev,
ARRAY_SIZE(wm2200->core_supplies),
wm2200->core_supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request core supplies: %d\n",
ret);
return ret;
}
ret = regulator_bulk_enable(ARRAY_SIZE(wm2200->core_supplies),
wm2200->core_supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable core supplies: %d\n",
ret);
return ret;
}
if (wm2200->pdata.ldo_ena) {
ret = devm_gpio_request_one(&i2c->dev, wm2200->pdata.ldo_ena,
GPIOF_OUT_INIT_HIGH,
"WM2200 LDOENA");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request LDOENA %d: %d\n",
wm2200->pdata.ldo_ena, ret);
goto err_enable;
}
msleep(2);
}
if (wm2200->pdata.reset) {
ret = devm_gpio_request_one(&i2c->dev, wm2200->pdata.reset,
GPIOF_OUT_INIT_HIGH,
"WM2200 /RESET");
if (ret < 0) {
dev_err(&i2c->dev, "Failed to request /RESET %d: %d\n",
wm2200->pdata.reset, ret);
goto err_ldo;
}
}
ret = regmap_read(wm2200->regmap, WM2200_SOFTWARE_RESET, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read ID register: %d\n", ret);
goto err_reset;
}
switch (reg) {
case 0x2200:
break;
default:
dev_err(&i2c->dev, "Device is not a WM2200, ID is %x\n", reg);
ret = -EINVAL;
goto err_reset;
}
ret = regmap_read(wm2200->regmap, WM2200_DEVICE_REVISION, &reg);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to read revision register\n");
goto err_reset;
}
wm2200->rev = reg & WM2200_DEVICE_REVISION_MASK;
dev_info(&i2c->dev, "revision %c\n", wm2200->rev + 'A');
switch (wm2200->rev) {
case 0:
case 1:
ret = regmap_register_patch(wm2200->regmap, wm2200_reva_patch,
ARRAY_SIZE(wm2200_reva_patch));
if (ret != 0) {
dev_err(&i2c->dev, "Failed to register patch: %d\n",
ret);
}
break;
default:
break;
}
ret = wm2200_reset(wm2200);
if (ret < 0) {
dev_err(&i2c->dev, "Failed to issue reset\n");
goto err_reset;
}
for (i = 0; i < ARRAY_SIZE(wm2200->pdata.gpio_defaults); i++) {
if (!wm2200->pdata.gpio_defaults[i])
continue;
regmap_write(wm2200->regmap, WM2200_GPIO_CTRL_1 + i,
wm2200->pdata.gpio_defaults[i]);
}
for (i = 0; i < ARRAY_SIZE(wm2200_dig_vu); i++)
regmap_update_bits(wm2200->regmap, wm2200_dig_vu[i],
WM2200_OUT_VU, WM2200_OUT_VU);
for (i = 0; i < 6; i++) {
regmap_write(wm2200->regmap, WM2200_AUDIO_IF_1_10 + i, i);
regmap_write(wm2200->regmap, WM2200_AUDIO_IF_1_16 + i, i);
}
for (i = 0; i < ARRAY_SIZE(wm2200->pdata.in_mode); i++) {
regmap_update_bits(wm2200->regmap, wm2200_mic_ctrl_reg[i],
WM2200_IN1_MODE_MASK |
WM2200_IN1_DMIC_SUP_MASK,
(wm2200->pdata.in_mode[i] <<
WM2200_IN1_MODE_SHIFT) |
(wm2200->pdata.dmic_sup[i] <<
WM2200_IN1_DMIC_SUP_SHIFT));
}
if (i2c->irq) {
ret = request_threaded_irq(i2c->irq, NULL, wm2200_irq,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"wm2200", wm2200);
if (ret == 0)
regmap_update_bits(wm2200->regmap,
WM2200_INTERRUPT_STATUS_2_MASK,
WM2200_FLL_LOCK_EINT, 0);
else
dev_err(&i2c->dev, "Failed to request IRQ %d: %d\n",
i2c->irq, ret);
}
pm_runtime_set_active(&i2c->dev);
pm_runtime_enable(&i2c->dev);
pm_request_idle(&i2c->dev);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_wm2200,
&wm2200_dai, 1);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to register CODEC: %d\n", ret);
goto err_pm_runtime;
}
return 0;
err_pm_runtime:
pm_runtime_disable(&i2c->dev);
err_reset:
if (wm2200->pdata.reset)
gpio_set_value_cansleep(wm2200->pdata.reset, 0);
err_ldo:
if (wm2200->pdata.ldo_ena)
gpio_set_value_cansleep(wm2200->pdata.ldo_ena, 0);
err_enable:
regulator_bulk_disable(ARRAY_SIZE(wm2200->core_supplies),
wm2200->core_supplies);
return ret;
}
static int wm2200_i2c_remove(struct i2c_client *i2c)
{
struct wm2200_priv *wm2200 = i2c_get_clientdata(i2c);
snd_soc_unregister_codec(&i2c->dev);
if (i2c->irq)
free_irq(i2c->irq, wm2200);
if (wm2200->pdata.reset)
gpio_set_value_cansleep(wm2200->pdata.reset, 0);
if (wm2200->pdata.ldo_ena)
gpio_set_value_cansleep(wm2200->pdata.ldo_ena, 0);
return 0;
}
static int wm2200_runtime_suspend(struct device *dev)
{
struct wm2200_priv *wm2200 = dev_get_drvdata(dev);
regcache_cache_only(wm2200->regmap, true);
regcache_mark_dirty(wm2200->regmap);
if (wm2200->pdata.ldo_ena)
gpio_set_value_cansleep(wm2200->pdata.ldo_ena, 0);
regulator_bulk_disable(ARRAY_SIZE(wm2200->core_supplies),
wm2200->core_supplies);
return 0;
}
static int wm2200_runtime_resume(struct device *dev)
{
struct wm2200_priv *wm2200 = dev_get_drvdata(dev);
int ret;
ret = regulator_bulk_enable(ARRAY_SIZE(wm2200->core_supplies),
wm2200->core_supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n",
ret);
return ret;
}
if (wm2200->pdata.ldo_ena) {
gpio_set_value_cansleep(wm2200->pdata.ldo_ena, 1);
msleep(2);
}
regcache_cache_only(wm2200->regmap, false);
regcache_sync(wm2200->regmap);
return 0;
}
