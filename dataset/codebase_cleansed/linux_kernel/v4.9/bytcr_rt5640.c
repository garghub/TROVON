static void log_quirks(struct device *dev)
{
if (BYT_RT5640_MAP(byt_rt5640_quirk) == BYT_RT5640_DMIC1_MAP)
dev_info(dev, "quirk DMIC1_MAP enabled");
if (BYT_RT5640_MAP(byt_rt5640_quirk) == BYT_RT5640_DMIC2_MAP)
dev_info(dev, "quirk DMIC2_MAP enabled");
if (BYT_RT5640_MAP(byt_rt5640_quirk) == BYT_RT5640_IN1_MAP)
dev_info(dev, "quirk IN1_MAP enabled");
if (BYT_RT5640_MAP(byt_rt5640_quirk) == BYT_RT5640_IN3_MAP)
dev_info(dev, "quirk IN3_MAP enabled");
if (byt_rt5640_quirk & BYT_RT5640_DMIC_EN)
dev_info(dev, "quirk DMIC enabled");
if (byt_rt5640_quirk & BYT_RT5640_MONO_SPEAKER)
dev_info(dev, "quirk MONO_SPEAKER enabled");
if (byt_rt5640_quirk & BYT_RT5640_DIFF_MIC)
dev_info(dev, "quirk DIFF_MIC enabled");
if (byt_rt5640_quirk & BYT_RT5640_SSP2_AIF2)
dev_info(dev, "quirk SSP2_AIF2 enabled");
if (byt_rt5640_quirk & BYT_RT5640_SSP0_AIF1)
dev_info(dev, "quirk SSP0_AIF1 enabled");
if (byt_rt5640_quirk & BYT_RT5640_SSP0_AIF2)
dev_info(dev, "quirk SSP0_AIF2 enabled");
if (byt_rt5640_quirk & BYT_RT5640_MCLK_EN)
dev_info(dev, "quirk MCLK_EN enabled");
if (byt_rt5640_quirk & BYT_RT5640_MCLK_25MHZ)
dev_info(dev, "quirk MCLK_25MHZ enabled");
}
static inline struct snd_soc_dai *byt_get_codec_dai(struct snd_soc_card *card)
{
struct snd_soc_pcm_runtime *rtd;
list_for_each_entry(rtd, &card->rtd_list, list) {
if (!strncmp(rtd->codec_dai->name, BYT_CODEC_DAI1,
strlen(BYT_CODEC_DAI1)))
return rtd->codec_dai;
if (!strncmp(rtd->codec_dai->name, BYT_CODEC_DAI2,
strlen(BYT_CODEC_DAI2)))
return rtd->codec_dai;
}
return NULL;
}
static int platform_clock_control(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_dapm_context *dapm = w->dapm;
struct snd_soc_card *card = dapm->card;
struct snd_soc_dai *codec_dai;
struct byt_rt5640_private *priv = snd_soc_card_get_drvdata(card);
int ret;
codec_dai = byt_get_codec_dai(card);
if (!codec_dai) {
dev_err(card->dev,
"Codec dai not found; Unable to set platform clock\n");
return -EIO;
}
if (SND_SOC_DAPM_EVENT_ON(event)) {
if ((byt_rt5640_quirk & BYT_RT5640_MCLK_EN) && priv->mclk) {
ret = clk_prepare_enable(priv->mclk);
if (ret < 0) {
dev_err(card->dev,
"could not configure MCLK state");
return ret;
}
}
ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_PLL1,
48000 * 512,
SND_SOC_CLOCK_IN);
} else {
ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_RCCLK,
0,
SND_SOC_CLOCK_IN);
if (!ret) {
if ((byt_rt5640_quirk & BYT_RT5640_MCLK_EN) && priv->mclk)
clk_disable_unprepare(priv->mclk);
}
}
if (ret < 0) {
dev_err(card->dev, "can't set codec sysclk: %d\n", ret);
return ret;
}
return 0;
}
static int byt_rt5640_aif1_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_dai *codec_dai = rtd->codec_dai;
int ret;
ret = snd_soc_dai_set_sysclk(codec_dai, RT5640_SCLK_S_PLL1,
params_rate(params) * 512,
SND_SOC_CLOCK_IN);
if (ret < 0) {
dev_err(rtd->dev, "can't set codec clock %d\n", ret);
return ret;
}
if (!(byt_rt5640_quirk & BYT_RT5640_MCLK_EN)) {
if ((byt_rt5640_quirk & BYT_RT5640_SSP0_AIF1) ||
(byt_rt5640_quirk & BYT_RT5640_SSP0_AIF2)) {
ret = snd_soc_dai_set_pll(codec_dai, 0,
RT5640_PLL1_S_BCLK1,
params_rate(params) * 32,
params_rate(params) * 512);
} else {
ret = snd_soc_dai_set_pll(codec_dai, 0,
RT5640_PLL1_S_BCLK1,
params_rate(params) * 50,
params_rate(params) * 512);
}
} else {
if (byt_rt5640_quirk & BYT_RT5640_MCLK_25MHZ) {
ret = snd_soc_dai_set_pll(codec_dai, 0,
RT5640_PLL1_S_MCLK,
25000000,
params_rate(params) * 512);
} else {
ret = snd_soc_dai_set_pll(codec_dai, 0,
RT5640_PLL1_S_MCLK,
19200000,
params_rate(params) * 512);
}
}
if (ret < 0) {
dev_err(rtd->dev, "can't set codec pll: %d\n", ret);
return ret;
}
return 0;
}
static int byt_rt5640_quirk_cb(const struct dmi_system_id *id)
{
byt_rt5640_quirk = (unsigned long)id->driver_data;
return 1;
}
static int byt_rt5640_init(struct snd_soc_pcm_runtime *runtime)
{
int ret;
struct snd_soc_codec *codec = runtime->codec;
struct snd_soc_card *card = runtime->card;
const struct snd_soc_dapm_route *custom_map;
struct byt_rt5640_private *priv = snd_soc_card_get_drvdata(card);
int num_routes;
card->dapm.idle_bias_off = true;
rt5640_sel_asrc_clk_src(codec,
RT5640_DA_STEREO_FILTER |
RT5640_DA_MONO_L_FILTER |
RT5640_DA_MONO_R_FILTER |
RT5640_AD_STEREO_FILTER |
RT5640_AD_MONO_L_FILTER |
RT5640_AD_MONO_R_FILTER,
RT5640_CLK_SEL_ASRC);
ret = snd_soc_add_card_controls(card, byt_rt5640_controls,
ARRAY_SIZE(byt_rt5640_controls));
if (ret) {
dev_err(card->dev, "unable to add card controls\n");
return ret;
}
switch (BYT_RT5640_MAP(byt_rt5640_quirk)) {
case BYT_RT5640_IN1_MAP:
custom_map = byt_rt5640_intmic_in1_map;
num_routes = ARRAY_SIZE(byt_rt5640_intmic_in1_map);
break;
case BYT_RT5640_IN3_MAP:
custom_map = byt_rt5640_intmic_in3_map;
num_routes = ARRAY_SIZE(byt_rt5640_intmic_in3_map);
break;
case BYT_RT5640_DMIC2_MAP:
custom_map = byt_rt5640_intmic_dmic2_map;
num_routes = ARRAY_SIZE(byt_rt5640_intmic_dmic2_map);
break;
default:
custom_map = byt_rt5640_intmic_dmic1_map;
num_routes = ARRAY_SIZE(byt_rt5640_intmic_dmic1_map);
}
ret = snd_soc_dapm_add_routes(&card->dapm, custom_map, num_routes);
if (ret)
return ret;
if (byt_rt5640_quirk & BYT_RT5640_SSP2_AIF2) {
ret = snd_soc_dapm_add_routes(&card->dapm,
byt_rt5640_ssp2_aif2_map,
ARRAY_SIZE(byt_rt5640_ssp2_aif2_map));
} else if (byt_rt5640_quirk & BYT_RT5640_SSP0_AIF1) {
ret = snd_soc_dapm_add_routes(&card->dapm,
byt_rt5640_ssp0_aif1_map,
ARRAY_SIZE(byt_rt5640_ssp0_aif1_map));
} else if (byt_rt5640_quirk & BYT_RT5640_SSP0_AIF2) {
ret = snd_soc_dapm_add_routes(&card->dapm,
byt_rt5640_ssp0_aif2_map,
ARRAY_SIZE(byt_rt5640_ssp0_aif2_map));
} else {
ret = snd_soc_dapm_add_routes(&card->dapm,
byt_rt5640_ssp2_aif1_map,
ARRAY_SIZE(byt_rt5640_ssp2_aif1_map));
}
if (ret)
return ret;
if (byt_rt5640_quirk & BYT_RT5640_MONO_SPEAKER) {
ret = snd_soc_dapm_add_routes(&card->dapm,
byt_rt5640_mono_spk_map,
ARRAY_SIZE(byt_rt5640_mono_spk_map));
} else {
ret = snd_soc_dapm_add_routes(&card->dapm,
byt_rt5640_stereo_spk_map,
ARRAY_SIZE(byt_rt5640_stereo_spk_map));
}
if (ret)
return ret;
if (byt_rt5640_quirk & BYT_RT5640_DIFF_MIC) {
snd_soc_update_bits(codec, RT5640_IN1_IN2, RT5640_IN_DF1,
RT5640_IN_DF1);
}
if (byt_rt5640_quirk & BYT_RT5640_DMIC_EN) {
ret = rt5640_dmic_enable(codec, 0, 0);
if (ret)
return ret;
}
snd_soc_dapm_ignore_suspend(&card->dapm, "Headphone");
snd_soc_dapm_ignore_suspend(&card->dapm, "Speaker");
if ((byt_rt5640_quirk & BYT_RT5640_MCLK_EN) && priv->mclk) {
ret = clk_prepare_enable(priv->mclk);
if (!ret)
clk_disable_unprepare(priv->mclk);
if (byt_rt5640_quirk & BYT_RT5640_MCLK_25MHZ)
ret = clk_set_rate(priv->mclk, 25000000);
else
ret = clk_set_rate(priv->mclk, 19200000);
if (ret)
dev_err(card->dev, "unable to set MCLK rate\n");
}
return ret;
}
static int byt_rt5640_codec_fixup(struct snd_soc_pcm_runtime *rtd,
struct snd_pcm_hw_params *params)
{
struct snd_interval *rate = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_RATE);
struct snd_interval *channels = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
int ret;
rate->min = rate->max = 48000;
channels->min = channels->max = 2;
if ((byt_rt5640_quirk & BYT_RT5640_SSP0_AIF1) ||
(byt_rt5640_quirk & BYT_RT5640_SSP0_AIF2)) {
params_set_format(params, SNDRV_PCM_FORMAT_S16_LE);
ret = snd_soc_dai_set_fmt(rtd->cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_IF |
SND_SOC_DAIFMT_CBS_CFS
);
if (ret < 0) {
dev_err(rtd->dev, "can't set format to I2S, err %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_tdm_slot(rtd->cpu_dai, 0x3, 0x3, 2, 16);
if (ret < 0) {
dev_err(rtd->dev, "can't set I2S config, err %d\n", ret);
return ret;
}
} else {
params_set_format(params, SNDRV_PCM_FORMAT_S24_LE);
ret = snd_soc_dai_set_fmt(rtd->cpu_dai,
SND_SOC_DAIFMT_I2S |
SND_SOC_DAIFMT_NB_IF |
SND_SOC_DAIFMT_CBS_CFS
);
if (ret < 0) {
dev_err(rtd->dev, "can't set format to I2S, err %d\n", ret);
return ret;
}
ret = snd_soc_dai_set_tdm_slot(rtd->cpu_dai, 0x3, 0x3, 2, 24);
if (ret < 0) {
dev_err(rtd->dev, "can't set I2S config, err %d\n", ret);
return ret;
}
}
return 0;
}
static int byt_rt5640_aif1_startup(struct snd_pcm_substream *substream)
{
return snd_pcm_hw_constraint_single(substream->runtime,
SNDRV_PCM_HW_PARAM_RATE, 48000);
}
static bool is_valleyview(void)
{
static const struct x86_cpu_id cpu_ids[] = {
{ X86_VENDOR_INTEL, 6, 55 },
{}
};
if (!x86_match_cpu(cpu_ids))
return false;
return true;
}
static int snd_byt_rt5640_mc_probe(struct platform_device *pdev)
{
int ret_val = 0;
struct sst_acpi_mach *mach;
const char *i2c_name = NULL;
int i;
int dai_index;
struct byt_rt5640_private *priv;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_ATOMIC);
if (!priv)
return -ENOMEM;
byt_rt5640_card.dev = &pdev->dev;
mach = byt_rt5640_card.dev->platform_data;
snd_soc_card_set_drvdata(&byt_rt5640_card, priv);
dai_index = MERR_DPCM_COMPR + 1;
for (i = 0; i < ARRAY_SIZE(byt_rt5640_dais); i++) {
if (!strcmp(byt_rt5640_dais[i].codec_name, "i2c-10EC5640:00")) {
dai_index = i;
break;
}
}
i2c_name = sst_acpi_find_name_from_hid(mach->id);
if (i2c_name != NULL) {
snprintf(byt_rt5640_codec_name, sizeof(byt_rt5640_codec_name),
"%s%s", "i2c-", i2c_name);
byt_rt5640_dais[dai_index].codec_name = byt_rt5640_codec_name;
}
if (is_valleyview()) {
struct sst_platform_info *p_info = mach->pdata;
const struct sst_res_info *res_info = p_info->res_info;
if (res_info->acpi_ipc_irq_index == 0) {
byt_rt5640_quirk |= BYT_RT5640_SSP0_AIF2;
}
}
dmi_check_system(byt_rt5640_quirk_table);
log_quirks(&pdev->dev);
if ((byt_rt5640_quirk & BYT_RT5640_SSP2_AIF2) ||
(byt_rt5640_quirk & BYT_RT5640_SSP0_AIF2)) {
snprintf(byt_rt5640_codec_aif_name,
sizeof(byt_rt5640_codec_aif_name),
"%s", "rt5640-aif2");
byt_rt5640_dais[dai_index].codec_dai_name =
byt_rt5640_codec_aif_name;
}
if ((byt_rt5640_quirk & BYT_RT5640_SSP0_AIF1) ||
(byt_rt5640_quirk & BYT_RT5640_SSP0_AIF2)) {
snprintf(byt_rt5640_cpu_dai_name,
sizeof(byt_rt5640_cpu_dai_name),
"%s", "ssp0-port");
byt_rt5640_dais[dai_index].cpu_dai_name =
byt_rt5640_cpu_dai_name;
}
if ((byt_rt5640_quirk & BYT_RT5640_MCLK_EN) && (is_valleyview())) {
priv->mclk = devm_clk_get(&pdev->dev, "pmc_plt_clk_3");
if (IS_ERR(priv->mclk)) {
dev_err(&pdev->dev,
"Failed to get MCLK from pmc_plt_clk_3: %ld\n",
PTR_ERR(priv->mclk));
return PTR_ERR(priv->mclk);
}
}
ret_val = devm_snd_soc_register_card(&pdev->dev, &byt_rt5640_card);
if (ret_val) {
dev_err(&pdev->dev, "devm_snd_soc_register_card failed %d\n",
ret_val);
return ret_val;
}
platform_set_drvdata(pdev, &byt_rt5640_card);
return ret_val;
}
