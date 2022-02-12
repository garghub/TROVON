static bool cs35l35_volatile_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L35_INT_STATUS_1:
case CS35L35_INT_STATUS_2:
case CS35L35_INT_STATUS_3:
case CS35L35_INT_STATUS_4:
case CS35L35_PLL_STATUS:
case CS35L35_OTP_TRIM_STATUS:
return true;
default:
return false;
}
}
static bool cs35l35_readable_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L35_DEVID_AB ... CS35L35_PWRCTL3:
case CS35L35_CLK_CTL1 ... CS35L35_SP_FMT_CTL3:
case CS35L35_MAG_COMP_CTL ... CS35L35_AMP_GAIN_AUD_CTL:
case CS35L35_AMP_GAIN_PDM_CTL ... CS35L35_BST_PEAK_I:
case CS35L35_BST_RAMP_CTL ... CS35L35_BST_CONV_SW_FREQ:
case CS35L35_CLASS_H_CTL ... CS35L35_CLASS_H_VP_CTL:
case CS35L35_CLASS_H_STATUS:
case CS35L35_VPBR_CTL ... CS35L35_VPBR_MODE_VOL_CTL:
case CS35L35_VPBR_ATTEN_STATUS:
case CS35L35_SPKR_MON_CTL:
case CS35L35_IMON_SCALE_CTL ... CS35L35_ZEROFILL_DEPTH_CTL:
case CS35L35_MULT_DEV_SYNCH1 ... CS35L35_PROT_RELEASE_CTL:
case CS35L35_DIAG_MODE_REG_LOCK ... CS35L35_DIAG_MODE_CTL_2:
case CS35L35_INT_MASK_1 ... CS35L35_PLL_STATUS:
case CS35L35_OTP_TRIM_STATUS:
return true;
default:
return false;
}
}
static bool cs35l35_precious_register(struct device *dev, unsigned int reg)
{
switch (reg) {
case CS35L35_INT_STATUS_1:
case CS35L35_INT_STATUS_2:
case CS35L35_INT_STATUS_3:
case CS35L35_INT_STATUS_4:
case CS35L35_PLL_STATUS:
case CS35L35_OTP_TRIM_STATUS:
return true;
default:
return false;
}
}
static int cs35l35_wait_for_pdn(struct cs35l35_private *cs35l35)
{
int ret;
if (cs35l35->pdata.ext_bst) {
usleep_range(5000, 5500);
return 0;
}
reinit_completion(&cs35l35->pdn_done);
ret = wait_for_completion_timeout(&cs35l35->pdn_done,
msecs_to_jiffies(100));
if (ret == 0) {
dev_err(cs35l35->dev, "PDN_DONE did not complete\n");
return -ETIMEDOUT;
}
return 0;
}
static int cs35l35_sdin_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
int ret = 0;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
regmap_update_bits(cs35l35->regmap, CS35L35_CLK_CTL1,
CS35L35_MCLK_DIS_MASK,
0 << CS35L35_MCLK_DIS_SHIFT);
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL1,
CS35L35_DISCHG_FILT_MASK,
0 << CS35L35_DISCHG_FILT_SHIFT);
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL1,
CS35L35_PDN_ALL_MASK, 0);
break;
case SND_SOC_DAPM_POST_PMD:
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL1,
CS35L35_DISCHG_FILT_MASK,
1 << CS35L35_DISCHG_FILT_SHIFT);
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL1,
CS35L35_PDN_ALL_MASK, 1);
regmap_update_bits(cs35l35->regmap, CS35L35_AMP_DIG_VOL_CTL,
CS35L35_AMP_DIGSFT_MASK, 0);
ret = cs35l35_wait_for_pdn(cs35l35);
regmap_update_bits(cs35l35->regmap, CS35L35_CLK_CTL1,
CS35L35_MCLK_DIS_MASK,
1 << CS35L35_MCLK_DIS_SHIFT);
regmap_update_bits(cs35l35->regmap, CS35L35_AMP_DIG_VOL_CTL,
CS35L35_AMP_DIGSFT_MASK,
1 << CS35L35_AMP_DIGSFT_SHIFT);
break;
default:
dev_err(codec->dev, "Invalid event = 0x%x\n", event);
ret = -EINVAL;
}
return ret;
}
static int cs35l35_main_amp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
unsigned int reg[4];
int i;
switch (event) {
case SND_SOC_DAPM_PRE_PMU:
if (cs35l35->pdata.bst_pdn_fet_on)
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_BST_MASK,
0 << CS35L35_PDN_BST_FETON_SHIFT);
else
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_BST_MASK,
0 << CS35L35_PDN_BST_FETOFF_SHIFT);
break;
case SND_SOC_DAPM_POST_PMU:
usleep_range(5000, 5100);
if (cs35l35->pdm_mode)
regmap_update_bits(cs35l35->regmap,
CS35L35_BST_CVTR_V_CTL,
CS35L35_BST_CTL_MASK,
0 << CS35L35_BST_CTL_SHIFT);
regmap_update_bits(cs35l35->regmap, CS35L35_PROTECT_CTL,
CS35L35_AMP_MUTE_MASK, 0);
for (i = 0; i < 2; i++)
regmap_bulk_read(cs35l35->regmap, CS35L35_INT_STATUS_1,
&reg, ARRAY_SIZE(reg));
break;
case SND_SOC_DAPM_PRE_PMD:
regmap_update_bits(cs35l35->regmap, CS35L35_PROTECT_CTL,
CS35L35_AMP_MUTE_MASK,
1 << CS35L35_AMP_MUTE_SHIFT);
if (cs35l35->pdata.bst_pdn_fet_on)
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_BST_MASK,
1 << CS35L35_PDN_BST_FETON_SHIFT);
else
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_BST_MASK,
1 << CS35L35_PDN_BST_FETOFF_SHIFT);
break;
case SND_SOC_DAPM_POST_PMD:
usleep_range(5000, 5100);
if (cs35l35->pdm_mode)
regmap_update_bits(cs35l35->regmap,
CS35L35_BST_CVTR_V_CTL,
CS35L35_BST_CTL_MASK,
cs35l35->pdata.bst_vctl
<< CS35L35_BST_CTL_SHIFT);
break;
default:
dev_err(codec->dev, "Invalid event = 0x%x\n", event);
}
return 0;
}
static int cs35l35_set_dai_fmt(struct snd_soc_dai *codec_dai, unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
regmap_update_bits(cs35l35->regmap, CS35L35_CLK_CTL1,
CS35L35_MS_MASK, 1 << CS35L35_MS_SHIFT);
cs35l35->slave_mode = false;
break;
case SND_SOC_DAIFMT_CBS_CFS:
regmap_update_bits(cs35l35->regmap, CS35L35_CLK_CTL1,
CS35L35_MS_MASK, 0 << CS35L35_MS_SHIFT);
cs35l35->slave_mode = true;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
cs35l35->i2s_mode = true;
cs35l35->pdm_mode = false;
break;
case SND_SOC_DAIFMT_PDM:
cs35l35->pdm_mode = true;
cs35l35->i2s_mode = false;
break;
default:
return -EINVAL;
}
return 0;
}
static int cs35l35_get_clk_config(int sysclk, int srate)
{
int i;
for (i = 0; i < ARRAY_SIZE(cs35l35_clk_ctl); i++) {
if (cs35l35_clk_ctl[i].sysclk == sysclk &&
cs35l35_clk_ctl[i].srate == srate)
return cs35l35_clk_ctl[i].clk_cfg;
}
return -EINVAL;
}
static int cs35l35_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
struct classh_cfg *classh = &cs35l35->pdata.classh_algo;
int srate = params_rate(params);
int ret = 0;
u8 sp_sclks;
int audin_format;
int errata_chk;
int clk_ctl = cs35l35_get_clk_config(cs35l35->sysclk, srate);
if (clk_ctl < 0) {
dev_err(codec->dev, "Invalid CLK:Rate %d:%d\n",
cs35l35->sysclk, srate);
return -EINVAL;
}
ret = regmap_update_bits(cs35l35->regmap, CS35L35_CLK_CTL2,
CS35L35_CLK_CTL2_MASK, clk_ctl);
if (ret != 0) {
dev_err(codec->dev, "Failed to set port config %d\n", ret);
return ret;
}
errata_chk = clk_ctl & CS35L35_SP_RATE_MASK;
if (classh->classh_wk_fet_disable == 0x00 &&
(errata_chk == 0x01 || errata_chk == 0x03)) {
ret = regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_FET_DRIVE_CTL,
CS35L35_CH_WKFET_DEL_MASK,
0 << CS35L35_CH_WKFET_DEL_SHIFT);
if (ret != 0) {
dev_err(codec->dev, "Failed to set fet config %d\n",
ret);
return ret;
}
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
switch (params_width(params)) {
case 8:
audin_format = CS35L35_SDIN_DEPTH_8;
break;
case 16:
audin_format = CS35L35_SDIN_DEPTH_16;
break;
case 24:
audin_format = CS35L35_SDIN_DEPTH_24;
break;
default:
dev_err(codec->dev, "Unsupported Width %d\n",
params_width(params));
return -EINVAL;
}
regmap_update_bits(cs35l35->regmap,
CS35L35_AUDIN_DEPTH_CTL,
CS35L35_AUDIN_DEPTH_MASK,
audin_format <<
CS35L35_AUDIN_DEPTH_SHIFT);
if (cs35l35->pdata.stereo) {
regmap_update_bits(cs35l35->regmap,
CS35L35_AUDIN_DEPTH_CTL,
CS35L35_ADVIN_DEPTH_MASK,
audin_format <<
CS35L35_ADVIN_DEPTH_SHIFT);
}
}
if (cs35l35->i2s_mode) {
if ((cs35l35->sclk / srate) % 4) {
dev_err(codec->dev, "Unsupported sclk/fs ratio %d:%d\n",
cs35l35->sclk, srate);
return -EINVAL;
}
sp_sclks = ((cs35l35->sclk / srate) / 4) - 1;
if (cs35l35->slave_mode) {
switch (sp_sclks) {
case CS35L35_SP_SCLKS_32FS:
case CS35L35_SP_SCLKS_48FS:
case CS35L35_SP_SCLKS_64FS:
break;
default:
dev_err(codec->dev, "ratio not supported\n");
return -EINVAL;
}
} else {
switch (sp_sclks) {
case CS35L35_SP_SCLKS_32FS:
case CS35L35_SP_SCLKS_64FS:
break;
default:
dev_err(codec->dev, "ratio not supported\n");
return -EINVAL;
}
}
ret = regmap_update_bits(cs35l35->regmap,
CS35L35_CLK_CTL3,
CS35L35_SP_SCLKS_MASK, sp_sclks <<
CS35L35_SP_SCLKS_SHIFT);
if (ret != 0) {
dev_err(codec->dev, "Failed to set fsclk %d\n", ret);
return ret;
}
}
return ret;
}
static int cs35l35_pcm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
if (!substream->runtime)
return 0;
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &cs35l35_constraints);
regmap_update_bits(cs35l35->regmap, CS35L35_AMP_INP_DRV_CTL,
CS35L35_PDM_MODE_MASK,
0 << CS35L35_PDM_MODE_SHIFT);
return 0;
}
static int cs35l35_pdm_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
if (!substream->runtime)
return 0;
snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE,
&cs35l35_pdm_constraints);
regmap_update_bits(cs35l35->regmap, CS35L35_AMP_INP_DRV_CTL,
CS35L35_PDM_MODE_MASK,
1 << CS35L35_PDM_MODE_SHIFT);
return 0;
}
static int cs35l35_dai_set_sysclk(struct snd_soc_dai *dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
cs35l35->sclk = freq;
return 0;
}
static int cs35l35_codec_set_sysclk(struct snd_soc_codec *codec,
int clk_id, int source, unsigned int freq,
int dir)
{
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
int clksrc;
int ret = 0;
switch (clk_id) {
case 0:
clksrc = CS35L35_CLK_SOURCE_MCLK;
break;
case 1:
clksrc = CS35L35_CLK_SOURCE_SCLK;
break;
case 2:
clksrc = CS35L35_CLK_SOURCE_PDM;
break;
default:
dev_err(codec->dev, "Invalid CLK Source\n");
return -EINVAL;
}
switch (freq) {
case 5644800:
case 6144000:
case 11289600:
case 12000000:
case 12288000:
case 13000000:
case 22579200:
case 24000000:
case 24576000:
case 26000000:
cs35l35->sysclk = freq;
break;
default:
dev_err(codec->dev, "Invalid CLK Frequency Input : %d\n", freq);
return -EINVAL;
}
ret = regmap_update_bits(cs35l35->regmap, CS35L35_CLK_CTL1,
CS35L35_CLK_SOURCE_MASK,
clksrc << CS35L35_CLK_SOURCE_SHIFT);
if (ret != 0) {
dev_err(codec->dev, "Failed to set sysclk %d\n", ret);
return ret;
}
return ret;
}
static int cs35l35_codec_probe(struct snd_soc_codec *codec)
{
struct cs35l35_private *cs35l35 = snd_soc_codec_get_drvdata(codec);
struct classh_cfg *classh = &cs35l35->pdata.classh_algo;
struct monitor_cfg *monitor_config = &cs35l35->pdata.mon_cfg;
int ret;
if (cs35l35->pdata.bst_vctl)
regmap_update_bits(cs35l35->regmap, CS35L35_BST_CVTR_V_CTL,
CS35L35_BST_CTL_MASK,
cs35l35->pdata.bst_vctl);
if (cs35l35->pdata.bst_ipk)
regmap_update_bits(cs35l35->regmap, CS35L35_BST_PEAK_I,
CS35L35_BST_IPK_MASK,
cs35l35->pdata.bst_ipk <<
CS35L35_BST_IPK_SHIFT);
if (cs35l35->pdata.gain_zc)
regmap_update_bits(cs35l35->regmap, CS35L35_PROTECT_CTL,
CS35L35_AMP_GAIN_ZC_MASK,
cs35l35->pdata.gain_zc <<
CS35L35_AMP_GAIN_ZC_SHIFT);
if (cs35l35->pdata.aud_channel)
regmap_update_bits(cs35l35->regmap,
CS35L35_AUDIN_RXLOC_CTL,
CS35L35_AUD_IN_LR_MASK,
cs35l35->pdata.aud_channel <<
CS35L35_AUD_IN_LR_SHIFT);
if (cs35l35->pdata.stereo) {
regmap_update_bits(cs35l35->regmap,
CS35L35_ADVIN_RXLOC_CTL,
CS35L35_ADV_IN_LR_MASK,
cs35l35->pdata.adv_channel <<
CS35L35_ADV_IN_LR_SHIFT);
if (cs35l35->pdata.shared_bst)
regmap_update_bits(cs35l35->regmap, CS35L35_CLASS_H_CTL,
CS35L35_CH_STEREO_MASK,
1 << CS35L35_CH_STEREO_SHIFT);
ret = snd_soc_add_codec_controls(codec, cs35l35_adv_controls,
ARRAY_SIZE(cs35l35_adv_controls));
if (ret)
return ret;
}
if (cs35l35->pdata.sp_drv_str)
regmap_update_bits(cs35l35->regmap, CS35L35_CLK_CTL1,
CS35L35_SP_DRV_MASK,
cs35l35->pdata.sp_drv_str <<
CS35L35_SP_DRV_SHIFT);
if (cs35l35->pdata.sp_drv_unused)
regmap_update_bits(cs35l35->regmap, CS35L35_SP_FMT_CTL3,
CS35L35_SP_I2S_DRV_MASK,
cs35l35->pdata.sp_drv_unused <<
CS35L35_SP_I2S_DRV_SHIFT);
if (classh->classh_algo_enable) {
if (classh->classh_bst_override)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_CTL,
CS35L35_CH_BST_OVR_MASK,
classh->classh_bst_override <<
CS35L35_CH_BST_OVR_SHIFT);
if (classh->classh_bst_max_limit)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_CTL,
CS35L35_CH_BST_LIM_MASK,
classh->classh_bst_max_limit <<
CS35L35_CH_BST_LIM_SHIFT);
if (classh->classh_mem_depth)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_CTL,
CS35L35_CH_MEM_DEPTH_MASK,
classh->classh_mem_depth <<
CS35L35_CH_MEM_DEPTH_SHIFT);
if (classh->classh_headroom)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_HEADRM_CTL,
CS35L35_CH_HDRM_CTL_MASK,
classh->classh_headroom <<
CS35L35_CH_HDRM_CTL_SHIFT);
if (classh->classh_release_rate)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_RELEASE_RATE,
CS35L35_CH_REL_RATE_MASK,
classh->classh_release_rate <<
CS35L35_CH_REL_RATE_SHIFT);
if (classh->classh_wk_fet_disable)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_FET_DRIVE_CTL,
CS35L35_CH_WKFET_DIS_MASK,
classh->classh_wk_fet_disable <<
CS35L35_CH_WKFET_DIS_SHIFT);
if (classh->classh_wk_fet_delay)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_FET_DRIVE_CTL,
CS35L35_CH_WKFET_DEL_MASK,
classh->classh_wk_fet_delay <<
CS35L35_CH_WKFET_DEL_SHIFT);
if (classh->classh_wk_fet_thld)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_FET_DRIVE_CTL,
CS35L35_CH_WKFET_THLD_MASK,
classh->classh_wk_fet_thld <<
CS35L35_CH_WKFET_THLD_SHIFT);
if (classh->classh_vpch_auto)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_VP_CTL,
CS35L35_CH_VP_AUTO_MASK,
classh->classh_vpch_auto <<
CS35L35_CH_VP_AUTO_SHIFT);
if (classh->classh_vpch_rate)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_VP_CTL,
CS35L35_CH_VP_RATE_MASK,
classh->classh_vpch_rate <<
CS35L35_CH_VP_RATE_SHIFT);
if (classh->classh_vpch_man)
regmap_update_bits(cs35l35->regmap,
CS35L35_CLASS_H_VP_CTL,
CS35L35_CH_VP_MAN_MASK,
classh->classh_vpch_man <<
CS35L35_CH_VP_MAN_SHIFT);
}
if (monitor_config->is_present) {
if (monitor_config->vmon_specs) {
regmap_update_bits(cs35l35->regmap,
CS35L35_SPKMON_DEPTH_CTL,
CS35L35_VMON_DEPTH_MASK,
monitor_config->vmon_dpth <<
CS35L35_VMON_DEPTH_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VMON_TXLOC_CTL,
CS35L35_MON_TXLOC_MASK,
monitor_config->vmon_loc <<
CS35L35_MON_TXLOC_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VMON_TXLOC_CTL,
CS35L35_MON_FRM_MASK,
monitor_config->vmon_frm <<
CS35L35_MON_FRM_SHIFT);
}
if (monitor_config->imon_specs) {
regmap_update_bits(cs35l35->regmap,
CS35L35_SPKMON_DEPTH_CTL,
CS35L35_IMON_DEPTH_MASK,
monitor_config->imon_dpth <<
CS35L35_IMON_DEPTH_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_IMON_TXLOC_CTL,
CS35L35_MON_TXLOC_MASK,
monitor_config->imon_loc <<
CS35L35_MON_TXLOC_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_IMON_TXLOC_CTL,
CS35L35_MON_FRM_MASK,
monitor_config->imon_frm <<
CS35L35_MON_FRM_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_IMON_SCALE_CTL,
CS35L35_IMON_SCALE_MASK,
monitor_config->imon_scale <<
CS35L35_IMON_SCALE_SHIFT);
}
if (monitor_config->vpmon_specs) {
regmap_update_bits(cs35l35->regmap,
CS35L35_SUPMON_DEPTH_CTL,
CS35L35_VPMON_DEPTH_MASK,
monitor_config->vpmon_dpth <<
CS35L35_VPMON_DEPTH_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VPMON_TXLOC_CTL,
CS35L35_MON_TXLOC_MASK,
monitor_config->vpmon_loc <<
CS35L35_MON_TXLOC_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VPMON_TXLOC_CTL,
CS35L35_MON_FRM_MASK,
monitor_config->vpmon_frm <<
CS35L35_MON_FRM_SHIFT);
}
if (monitor_config->vbstmon_specs) {
regmap_update_bits(cs35l35->regmap,
CS35L35_SUPMON_DEPTH_CTL,
CS35L35_VBSTMON_DEPTH_MASK,
monitor_config->vpmon_dpth <<
CS35L35_VBSTMON_DEPTH_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VBSTMON_TXLOC_CTL,
CS35L35_MON_TXLOC_MASK,
monitor_config->vbstmon_loc <<
CS35L35_MON_TXLOC_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VBSTMON_TXLOC_CTL,
CS35L35_MON_FRM_MASK,
monitor_config->vbstmon_frm <<
CS35L35_MON_FRM_SHIFT);
}
if (monitor_config->vpbrstat_specs) {
regmap_update_bits(cs35l35->regmap,
CS35L35_SUPMON_DEPTH_CTL,
CS35L35_VPBRSTAT_DEPTH_MASK,
monitor_config->vpbrstat_dpth <<
CS35L35_VPBRSTAT_DEPTH_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VPBR_STATUS_TXLOC_CTL,
CS35L35_MON_TXLOC_MASK,
monitor_config->vpbrstat_loc <<
CS35L35_MON_TXLOC_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_VPBR_STATUS_TXLOC_CTL,
CS35L35_MON_FRM_MASK,
monitor_config->vpbrstat_frm <<
CS35L35_MON_FRM_SHIFT);
}
if (monitor_config->zerofill_specs) {
regmap_update_bits(cs35l35->regmap,
CS35L35_SUPMON_DEPTH_CTL,
CS35L35_ZEROFILL_DEPTH_MASK,
monitor_config->zerofill_dpth <<
CS35L35_ZEROFILL_DEPTH_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_ZERO_FILL_LOC_CTL,
CS35L35_MON_TXLOC_MASK,
monitor_config->zerofill_loc <<
CS35L35_MON_TXLOC_SHIFT);
regmap_update_bits(cs35l35->regmap,
CS35L35_ZERO_FILL_LOC_CTL,
CS35L35_MON_FRM_MASK,
monitor_config->zerofill_frm <<
CS35L35_MON_FRM_SHIFT);
}
}
return 0;
}
static irqreturn_t cs35l35_irq(int irq, void *data)
{
struct cs35l35_private *cs35l35 = data;
unsigned int sticky1, sticky2, sticky3, sticky4;
unsigned int mask1, mask2, mask3, mask4, current1;
regmap_read(cs35l35->regmap, CS35L35_INT_STATUS_4, &sticky4);
regmap_read(cs35l35->regmap, CS35L35_INT_STATUS_3, &sticky3);
regmap_read(cs35l35->regmap, CS35L35_INT_STATUS_2, &sticky2);
regmap_read(cs35l35->regmap, CS35L35_INT_STATUS_1, &sticky1);
regmap_read(cs35l35->regmap, CS35L35_INT_MASK_4, &mask4);
regmap_read(cs35l35->regmap, CS35L35_INT_MASK_3, &mask3);
regmap_read(cs35l35->regmap, CS35L35_INT_MASK_2, &mask2);
regmap_read(cs35l35->regmap, CS35L35_INT_MASK_1, &mask1);
if (!(sticky1 & ~mask1) && !(sticky2 & ~mask2) && !(sticky3 & ~mask3)
&& !(sticky4 & ~mask4))
return IRQ_NONE;
if (sticky2 & CS35L35_PDN_DONE)
complete(&cs35l35->pdn_done);
regmap_read(cs35l35->regmap, CS35L35_INT_STATUS_1, &current1);
if (sticky1 & CS35L35_CAL_ERR) {
dev_crit(cs35l35->dev, "Calibration Error\n");
if (!(current1 & CS35L35_CAL_ERR)) {
pr_debug("%s : Cal error release\n", __func__);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_CAL_ERR_RLS, 0);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_CAL_ERR_RLS,
CS35L35_CAL_ERR_RLS);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_CAL_ERR_RLS, 0);
}
}
if (sticky1 & CS35L35_AMP_SHORT) {
dev_crit(cs35l35->dev, "AMP Short Error\n");
if (!(current1 & CS35L35_AMP_SHORT)) {
dev_dbg(cs35l35->dev, "Amp short error release\n");
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_SHORT_RLS, 0);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_SHORT_RLS,
CS35L35_SHORT_RLS);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_SHORT_RLS, 0);
}
}
if (sticky1 & CS35L35_OTW) {
dev_warn(cs35l35->dev, "Over temperature warning\n");
if (!(current1 & CS35L35_OTW)) {
dev_dbg(cs35l35->dev, "Over temperature warn release\n");
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_OTW_RLS, 0);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_OTW_RLS,
CS35L35_OTW_RLS);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_OTW_RLS, 0);
}
}
if (sticky1 & CS35L35_OTE) {
dev_crit(cs35l35->dev, "Over temperature error\n");
if (!(current1 & CS35L35_OTE)) {
dev_dbg(cs35l35->dev, "Over temperature error release\n");
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_OTE_RLS, 0);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_OTE_RLS,
CS35L35_OTE_RLS);
regmap_update_bits(cs35l35->regmap,
CS35L35_PROT_RELEASE_CTL,
CS35L35_OTE_RLS, 0);
}
}
if (sticky3 & CS35L35_BST_HIGH) {
dev_crit(cs35l35->dev, "VBST error: powering off!\n");
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_AMP, CS35L35_PDN_AMP);
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL1,
CS35L35_PDN_ALL, CS35L35_PDN_ALL);
}
if (sticky3 & CS35L35_LBST_SHORT) {
dev_crit(cs35l35->dev, "LBST error: powering off!\n");
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_AMP, CS35L35_PDN_AMP);
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL1,
CS35L35_PDN_ALL, CS35L35_PDN_ALL);
}
if (sticky2 & CS35L35_VPBR_ERR)
dev_dbg(cs35l35->dev, "Error: Reactive Brownout\n");
if (sticky4 & CS35L35_VMON_OVFL)
dev_dbg(cs35l35->dev, "Error: VMON overflow\n");
if (sticky4 & CS35L35_IMON_OVFL)
dev_dbg(cs35l35->dev, "Error: IMON overflow\n");
return IRQ_HANDLED;
}
static int cs35l35_handle_of_data(struct i2c_client *i2c_client,
struct cs35l35_platform_data *pdata)
{
struct device_node *np = i2c_client->dev.of_node;
struct device_node *classh, *signal_format;
struct classh_cfg *classh_config = &pdata->classh_algo;
struct monitor_cfg *monitor_config = &pdata->mon_cfg;
unsigned int val32 = 0;
u8 monitor_array[4];
const int imon_array_size = ARRAY_SIZE(monitor_array);
const int mon_array_size = imon_array_size - 1;
int ret = 0;
if (!np)
return 0;
pdata->bst_pdn_fet_on = of_property_read_bool(np,
"cirrus,boost-pdn-fet-on");
ret = of_property_read_u32(np, "cirrus,boost-ctl-millivolt", &val32);
if (ret >= 0) {
if (val32 < 2600 || val32 > 9000) {
dev_err(&i2c_client->dev,
"Invalid Boost Voltage %d mV\n", val32);
return -EINVAL;
}
pdata->bst_vctl = ((val32 - 2600) / 100) + 1;
}
ret = of_property_read_u32(np, "cirrus,boost-peak-milliamp", &val32);
if (ret >= 0) {
if (val32 < 1680 || val32 > 4480) {
dev_err(&i2c_client->dev,
"Invalid Boost Peak Current %u mA\n", val32);
return -EINVAL;
}
pdata->bst_ipk = (val32 - 1680) / 110;
}
if (of_property_read_u32(np, "cirrus,sp-drv-strength", &val32) >= 0)
pdata->sp_drv_str = val32;
if (of_property_read_u32(np, "cirrus,sp-drv-unused", &val32) >= 0)
pdata->sp_drv_unused = val32 | CS35L35_VALID_PDATA;
pdata->stereo = of_property_read_bool(np, "cirrus,stereo-config");
if (pdata->stereo) {
ret = of_property_read_u32(np, "cirrus,audio-channel", &val32);
if (ret >= 0)
pdata->aud_channel = val32;
ret = of_property_read_u32(np, "cirrus,advisory-channel",
&val32);
if (ret >= 0)
pdata->adv_channel = val32;
pdata->shared_bst = of_property_read_bool(np,
"cirrus,shared-boost");
}
pdata->ext_bst = of_property_read_bool(np, "cirrus,external-boost");
pdata->gain_zc = of_property_read_bool(np, "cirrus,amp-gain-zc");
classh = of_get_child_by_name(np, "cirrus,classh-internal-algo");
classh_config->classh_algo_enable = classh ? true : false;
if (classh_config->classh_algo_enable) {
classh_config->classh_bst_override =
of_property_read_bool(np, "cirrus,classh-bst-overide");
ret = of_property_read_u32(classh,
"cirrus,classh-bst-max-limit",
&val32);
if (ret >= 0) {
val32 |= CS35L35_VALID_PDATA;
classh_config->classh_bst_max_limit = val32;
}
ret = of_property_read_u32(classh,
"cirrus,classh-bst-max-limit",
&val32);
if (ret >= 0) {
val32 |= CS35L35_VALID_PDATA;
classh_config->classh_bst_max_limit = val32;
}
ret = of_property_read_u32(classh, "cirrus,classh-mem-depth",
&val32);
if (ret >= 0) {
val32 |= CS35L35_VALID_PDATA;
classh_config->classh_mem_depth = val32;
}
ret = of_property_read_u32(classh, "cirrus,classh-release-rate",
&val32);
if (ret >= 0)
classh_config->classh_release_rate = val32;
ret = of_property_read_u32(classh, "cirrus,classh-headroom",
&val32);
if (ret >= 0) {
val32 |= CS35L35_VALID_PDATA;
classh_config->classh_headroom = val32;
}
ret = of_property_read_u32(classh,
"cirrus,classh-wk-fet-disable",
&val32);
if (ret >= 0)
classh_config->classh_wk_fet_disable = val32;
ret = of_property_read_u32(classh, "cirrus,classh-wk-fet-delay",
&val32);
if (ret >= 0) {
val32 |= CS35L35_VALID_PDATA;
classh_config->classh_wk_fet_delay = val32;
}
ret = of_property_read_u32(classh, "cirrus,classh-wk-fet-thld",
&val32);
if (ret >= 0)
classh_config->classh_wk_fet_thld = val32;
ret = of_property_read_u32(classh, "cirrus,classh-vpch-auto",
&val32);
if (ret >= 0) {
val32 |= CS35L35_VALID_PDATA;
classh_config->classh_vpch_auto = val32;
}
ret = of_property_read_u32(classh, "cirrus,classh-vpch-rate",
&val32);
if (ret >= 0) {
val32 |= CS35L35_VALID_PDATA;
classh_config->classh_vpch_rate = val32;
}
ret = of_property_read_u32(classh, "cirrus,classh-vpch-man",
&val32);
if (ret >= 0)
classh_config->classh_vpch_man = val32;
}
of_node_put(classh);
signal_format = of_get_child_by_name(np, "cirrus,monitor-signal-format");
monitor_config->is_present = signal_format ? true : false;
if (monitor_config->is_present) {
ret = of_property_read_u8_array(signal_format, "cirrus,imon",
monitor_array, imon_array_size);
if (!ret) {
monitor_config->imon_specs = true;
monitor_config->imon_dpth = monitor_array[0];
monitor_config->imon_loc = monitor_array[1];
monitor_config->imon_frm = monitor_array[2];
monitor_config->imon_scale = monitor_array[3];
}
ret = of_property_read_u8_array(signal_format, "cirrus,vmon",
monitor_array, mon_array_size);
if (!ret) {
monitor_config->vmon_specs = true;
monitor_config->vmon_dpth = monitor_array[0];
monitor_config->vmon_loc = monitor_array[1];
monitor_config->vmon_frm = monitor_array[2];
}
ret = of_property_read_u8_array(signal_format, "cirrus,vpmon",
monitor_array, mon_array_size);
if (!ret) {
monitor_config->vpmon_specs = true;
monitor_config->vpmon_dpth = monitor_array[0];
monitor_config->vpmon_loc = monitor_array[1];
monitor_config->vpmon_frm = monitor_array[2];
}
ret = of_property_read_u8_array(signal_format, "cirrus,vbstmon",
monitor_array, mon_array_size);
if (!ret) {
monitor_config->vbstmon_specs = true;
monitor_config->vbstmon_dpth = monitor_array[0];
monitor_config->vbstmon_loc = monitor_array[1];
monitor_config->vbstmon_frm = monitor_array[2];
}
ret = of_property_read_u8_array(signal_format, "cirrus,vpbrstat",
monitor_array, mon_array_size);
if (!ret) {
monitor_config->vpbrstat_specs = true;
monitor_config->vpbrstat_dpth = monitor_array[0];
monitor_config->vpbrstat_loc = monitor_array[1];
monitor_config->vpbrstat_frm = monitor_array[2];
}
ret = of_property_read_u8_array(signal_format, "cirrus,zerofill",
monitor_array, mon_array_size);
if (!ret) {
monitor_config->zerofill_specs = true;
monitor_config->zerofill_dpth = monitor_array[0];
monitor_config->zerofill_loc = monitor_array[1];
monitor_config->zerofill_frm = monitor_array[2];
}
}
of_node_put(signal_format);
return 0;
}
static int cs35l35_i2c_probe(struct i2c_client *i2c_client,
const struct i2c_device_id *id)
{
struct cs35l35_private *cs35l35;
struct device *dev = &i2c_client->dev;
struct cs35l35_platform_data *pdata = dev_get_platdata(dev);
int i;
int ret;
unsigned int devid = 0;
unsigned int reg;
cs35l35 = devm_kzalloc(dev, sizeof(struct cs35l35_private), GFP_KERNEL);
if (!cs35l35)
return -ENOMEM;
cs35l35->dev = dev;
i2c_set_clientdata(i2c_client, cs35l35);
cs35l35->regmap = devm_regmap_init_i2c(i2c_client, &cs35l35_regmap);
if (IS_ERR(cs35l35->regmap)) {
ret = PTR_ERR(cs35l35->regmap);
dev_err(dev, "regmap_init() failed: %d\n", ret);
goto err;
}
for (i = 0; i < ARRAY_SIZE(cs35l35_supplies); i++)
cs35l35->supplies[i].supply = cs35l35_supplies[i];
cs35l35->num_supplies = ARRAY_SIZE(cs35l35_supplies);
ret = devm_regulator_bulk_get(dev, cs35l35->num_supplies,
cs35l35->supplies);
if (ret != 0) {
dev_err(dev, "Failed to request core supplies: %d\n", ret);
return ret;
}
if (pdata) {
cs35l35->pdata = *pdata;
} else {
pdata = devm_kzalloc(dev, sizeof(struct cs35l35_platform_data),
GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (i2c_client->dev.of_node) {
ret = cs35l35_handle_of_data(i2c_client, pdata);
if (ret != 0)
return ret;
}
cs35l35->pdata = *pdata;
}
ret = regulator_bulk_enable(cs35l35->num_supplies,
cs35l35->supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable core supplies: %d\n", ret);
return ret;
}
cs35l35->reset_gpio = devm_gpiod_get_optional(dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(cs35l35->reset_gpio)) {
ret = PTR_ERR(cs35l35->reset_gpio);
cs35l35->reset_gpio = NULL;
if (ret == -EBUSY) {
dev_info(dev,
"Reset line busy, assuming shared reset\n");
} else {
dev_err(dev, "Failed to get reset GPIO: %d\n", ret);
goto err;
}
}
gpiod_set_value_cansleep(cs35l35->reset_gpio, 1);
init_completion(&cs35l35->pdn_done);
ret = devm_request_threaded_irq(dev, i2c_client->irq, NULL, cs35l35_irq,
IRQF_ONESHOT | IRQF_TRIGGER_LOW |
IRQF_SHARED, "cs35l35", cs35l35);
if (ret != 0) {
dev_err(dev, "Failed to request IRQ: %d\n", ret);
goto err;
}
ret = regmap_read(cs35l35->regmap, CS35L35_DEVID_AB, &reg);
devid = (reg & 0xFF) << 12;
ret = regmap_read(cs35l35->regmap, CS35L35_DEVID_CD, &reg);
devid |= (reg & 0xFF) << 4;
ret = regmap_read(cs35l35->regmap, CS35L35_DEVID_E, &reg);
devid |= (reg & 0xF0) >> 4;
if (devid != CS35L35_CHIP_ID) {
dev_err(dev, "CS35L35 Device ID (%X). Expected ID %X\n",
devid, CS35L35_CHIP_ID);
ret = -ENODEV;
goto err;
}
ret = regmap_read(cs35l35->regmap, CS35L35_REV_ID, &reg);
if (ret < 0) {
dev_err(dev, "Get Revision ID failed: %d\n", ret);
goto err;
}
ret = regmap_register_patch(cs35l35->regmap, cs35l35_errata_patch,
ARRAY_SIZE(cs35l35_errata_patch));
if (ret < 0) {
dev_err(dev, "Failed to apply errata patch: %d\n", ret);
goto err;
}
dev_info(dev, "Cirrus Logic CS35L35 (%x), Revision: %02X\n",
devid, reg & 0xFF);
regmap_write(cs35l35->regmap, CS35L35_INT_MASK_1,
CS35L35_INT1_CRIT_MASK);
regmap_write(cs35l35->regmap, CS35L35_INT_MASK_2,
CS35L35_INT2_CRIT_MASK);
regmap_write(cs35l35->regmap, CS35L35_INT_MASK_3,
CS35L35_INT3_CRIT_MASK);
regmap_write(cs35l35->regmap, CS35L35_INT_MASK_4,
CS35L35_INT4_CRIT_MASK);
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PWR2_PDN_MASK,
CS35L35_PWR2_PDN_MASK);
if (cs35l35->pdata.bst_pdn_fet_on)
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_BST_MASK,
1 << CS35L35_PDN_BST_FETON_SHIFT);
else
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL2,
CS35L35_PDN_BST_MASK,
1 << CS35L35_PDN_BST_FETOFF_SHIFT);
regmap_update_bits(cs35l35->regmap, CS35L35_PWRCTL3,
CS35L35_PWR3_PDN_MASK,
CS35L35_PWR3_PDN_MASK);
regmap_update_bits(cs35l35->regmap, CS35L35_PROTECT_CTL,
CS35L35_AMP_MUTE_MASK, 1 << CS35L35_AMP_MUTE_SHIFT);
ret = snd_soc_register_codec(dev, &soc_codec_dev_cs35l35, cs35l35_dai,
ARRAY_SIZE(cs35l35_dai));
if (ret < 0) {
dev_err(dev, "Failed to register codec: %d\n", ret);
goto err;
}
return 0;
err:
regulator_bulk_disable(cs35l35->num_supplies,
cs35l35->supplies);
gpiod_set_value_cansleep(cs35l35->reset_gpio, 0);
return ret;
}
static int cs35l35_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
