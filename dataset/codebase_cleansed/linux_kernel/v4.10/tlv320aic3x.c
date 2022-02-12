static bool aic3x_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case AIC3X_RESET:
return true;
default:
return false;
}
}
static int snd_soc_dapm_put_volsw_aic3x(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_dapm_kcontrol_codec(kcontrol);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
unsigned short val;
struct snd_soc_dapm_update update = { 0 };
int connect, change;
val = (ucontrol->value.integer.value[0] & mask);
mask = 0xf;
if (val)
val = mask;
connect = !!val;
if (invert)
val = mask - val;
mask <<= shift;
val <<= shift;
change = snd_soc_test_bits(codec, reg, mask, val);
if (change) {
update.kcontrol = kcontrol;
update.reg = reg;
update.mask = mask;
update.val = val;
snd_soc_dapm_mixer_update_power(dapm, kcontrol, connect,
&update);
}
return change;
}
static int mic_bias_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
switch (event) {
case SND_SOC_DAPM_POST_PMU:
snd_soc_update_bits(codec, MICBIAS_CTRL,
MICBIAS_LEVEL_MASK,
aic3x->micbias_vg << MICBIAS_LEVEL_SHIFT);
break;
case SND_SOC_DAPM_PRE_PMD:
snd_soc_update_bits(codec, MICBIAS_CTRL,
MICBIAS_LEVEL_MASK, 0);
break;
}
return 0;
}
static int aic3x_add_widgets(struct snd_soc_codec *codec)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = snd_soc_codec_get_dapm(codec);
switch (aic3x->model) {
case AIC3X_MODEL_3X:
case AIC3X_MODEL_33:
snd_soc_dapm_new_controls(dapm, aic3x_extra_dapm_widgets,
ARRAY_SIZE(aic3x_extra_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon_extra,
ARRAY_SIZE(intercon_extra));
snd_soc_dapm_new_controls(dapm, aic3x_dapm_mono_widgets,
ARRAY_SIZE(aic3x_dapm_mono_widgets));
snd_soc_dapm_add_routes(dapm, intercon_mono,
ARRAY_SIZE(intercon_mono));
break;
case AIC3X_MODEL_3007:
snd_soc_dapm_new_controls(dapm, aic3x_extra_dapm_widgets,
ARRAY_SIZE(aic3x_extra_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon_extra,
ARRAY_SIZE(intercon_extra));
snd_soc_dapm_new_controls(dapm, aic3007_dapm_widgets,
ARRAY_SIZE(aic3007_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon_3007,
ARRAY_SIZE(intercon_3007));
break;
case AIC3X_MODEL_3104:
snd_soc_dapm_new_controls(dapm, aic3104_extra_dapm_widgets,
ARRAY_SIZE(aic3104_extra_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon_extra_3104,
ARRAY_SIZE(intercon_extra_3104));
break;
}
return 0;
}
static int aic3x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
int codec_clk = 0, bypass_pll = 0, fsref, last_clk = 0;
u8 data, j, r, p, pll_q, pll_p = 1, pll_r = 1, pll_j = 1;
u16 d, pll_d = 1;
int clk;
int width = aic3x->slot_width;
if (!width)
width = params_width(params);
data = snd_soc_read(codec, AIC3X_ASD_INTF_CTRLB) & (~(0x3 << 4));
switch (width) {
case 16:
break;
case 20:
data |= (0x01 << 4);
break;
case 24:
data |= (0x02 << 4);
break;
case 32:
data |= (0x03 << 4);
break;
}
snd_soc_write(codec, AIC3X_ASD_INTF_CTRLB, data);
fsref = (params_rate(params) % 11025 == 0) ? 44100 : 48000;
for (pll_q = 2; pll_q < 18; pll_q++)
if (aic3x->sysclk / (128 * pll_q) == fsref) {
bypass_pll = 1;
break;
}
if (bypass_pll) {
pll_q &= 0xf;
snd_soc_write(codec, AIC3X_PLL_PROGA_REG, pll_q << PLLQ_SHIFT);
snd_soc_write(codec, AIC3X_GPIOB_REG, CODEC_CLKIN_CLKDIV);
snd_soc_update_bits(codec, AIC3X_PLL_PROGA_REG, PLL_ENABLE, 0);
} else {
snd_soc_write(codec, AIC3X_GPIOB_REG, CODEC_CLKIN_PLLDIV);
snd_soc_update_bits(codec, AIC3X_PLL_PROGA_REG,
PLL_ENABLE, PLL_ENABLE);
}
data = (LDAC2LCH | RDAC2RCH);
data |= (fsref == 44100) ? FSREF_44100 : FSREF_48000;
if (params_rate(params) >= 64000)
data |= DUAL_RATE_MODE;
snd_soc_write(codec, AIC3X_CODEC_DATAPATH_REG, data);
data = (fsref * 20) / params_rate(params);
if (params_rate(params) < 64000)
data /= 2;
data /= 5;
data -= 2;
data |= (data << 4);
snd_soc_write(codec, AIC3X_SAMPLE_RATE_SEL_REG, data);
if (bypass_pll)
return 0;
codec_clk = (2048 * fsref) / (aic3x->sysclk / 1000);
for (r = 1; r <= 16; r++)
for (p = 1; p <= 8; p++) {
for (j = 4; j <= 55; j++) {
int tmp_clk = (1000 * j * r) / p;
if (abs(codec_clk - tmp_clk) <
abs(codec_clk - last_clk)) {
pll_j = j; pll_d = 0;
pll_r = r; pll_p = p;
last_clk = tmp_clk;
}
if (tmp_clk == codec_clk)
goto found;
}
}
for (p = 1; p <= 8; p++) {
j = codec_clk * p / 1000;
if (j < 4 || j > 11)
continue;
d = ((2048 * p * fsref) - j * aic3x->sysclk)
* 100 / (aic3x->sysclk/100);
clk = (10000 * j + d) / (10 * p);
if (abs(codec_clk - clk) < abs(codec_clk - last_clk)) {
pll_j = j; pll_d = d; pll_r = 1; pll_p = p;
last_clk = clk;
}
if (clk == codec_clk)
goto found;
}
if (last_clk == 0) {
printk(KERN_ERR "%s(): unable to setup PLL\n", __func__);
return -EINVAL;
}
found:
snd_soc_update_bits(codec, AIC3X_PLL_PROGA_REG, PLLP_MASK, pll_p);
snd_soc_write(codec, AIC3X_OVRF_STATUS_AND_PLLR_REG,
pll_r << PLLR_SHIFT);
snd_soc_write(codec, AIC3X_PLL_PROGB_REG, pll_j << PLLJ_SHIFT);
snd_soc_write(codec, AIC3X_PLL_PROGC_REG,
(pll_d >> 6) << PLLD_MSB_SHIFT);
snd_soc_write(codec, AIC3X_PLL_PROGD_REG,
(pll_d & 0x3F) << PLLD_LSB_SHIFT);
return 0;
}
static int aic3x_prepare(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
int delay = 0;
int width = aic3x->slot_width;
if (!width)
width = substream->runtime->sample_bits;
if (aic3x->dai_fmt == SND_SOC_DAIFMT_DSP_A)
delay += (aic3x->tdm_delay*width + 1);
else if (aic3x->dai_fmt == SND_SOC_DAIFMT_DSP_B)
delay += aic3x->tdm_delay*width;
snd_soc_write(codec, AIC3X_ASD_INTF_CTRLC, delay);
return 0;
}
static int aic3x_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u8 ldac_reg = snd_soc_read(codec, LDAC_VOL) & ~MUTE_ON;
u8 rdac_reg = snd_soc_read(codec, RDAC_VOL) & ~MUTE_ON;
if (mute) {
snd_soc_write(codec, LDAC_VOL, ldac_reg | MUTE_ON);
snd_soc_write(codec, RDAC_VOL, rdac_reg | MUTE_ON);
} else {
snd_soc_write(codec, LDAC_VOL, ldac_reg);
snd_soc_write(codec, RDAC_VOL, rdac_reg);
}
return 0;
}
static int aic3x_set_dai_sysclk(struct snd_soc_dai *codec_dai,
int clk_id, unsigned int freq, int dir)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
snd_soc_update_bits(codec, AIC3X_CLKGEN_CTRL_REG, PLLCLK_IN_MASK,
clk_id << PLLCLK_IN_SHIFT);
snd_soc_update_bits(codec, AIC3X_CLKGEN_CTRL_REG, CLKDIV_IN_MASK,
clk_id << CLKDIV_IN_SHIFT);
aic3x->sysclk = freq;
return 0;
}
static int aic3x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
u8 iface_areg, iface_breg;
iface_areg = snd_soc_read(codec, AIC3X_ASD_INTF_CTRLA) & 0x3f;
iface_breg = snd_soc_read(codec, AIC3X_ASD_INTF_CTRLB) & 0x3f;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
aic3x->master = 1;
iface_areg |= BIT_CLK_MASTER | WORD_CLK_MASTER;
break;
case SND_SOC_DAIFMT_CBS_CFS:
aic3x->master = 0;
iface_areg &= ~(BIT_CLK_MASTER | WORD_CLK_MASTER);
break;
default:
return -EINVAL;
}
switch (fmt & (SND_SOC_DAIFMT_FORMAT_MASK |
SND_SOC_DAIFMT_INV_MASK)) {
case (SND_SOC_DAIFMT_I2S | SND_SOC_DAIFMT_NB_NF):
break;
case (SND_SOC_DAIFMT_DSP_A | SND_SOC_DAIFMT_IB_NF):
case (SND_SOC_DAIFMT_DSP_B | SND_SOC_DAIFMT_IB_NF):
iface_breg |= (0x01 << 6);
break;
case (SND_SOC_DAIFMT_RIGHT_J | SND_SOC_DAIFMT_NB_NF):
iface_breg |= (0x02 << 6);
break;
case (SND_SOC_DAIFMT_LEFT_J | SND_SOC_DAIFMT_NB_NF):
iface_breg |= (0x03 << 6);
break;
default:
return -EINVAL;
}
aic3x->dai_fmt = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
snd_soc_write(codec, AIC3X_ASD_INTF_CTRLA, iface_areg);
snd_soc_write(codec, AIC3X_ASD_INTF_CTRLB, iface_breg);
return 0;
}
static int aic3x_set_dai_tdm_slot(struct snd_soc_dai *codec_dai,
unsigned int tx_mask, unsigned int rx_mask,
int slots, int slot_width)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
unsigned int lsb;
if (tx_mask != rx_mask) {
dev_err(codec->dev, "tx and rx masks must be symmetric\n");
return -EINVAL;
}
if (unlikely(!tx_mask)) {
dev_err(codec->dev, "tx and rx masks need to be non 0\n");
return -EINVAL;
}
lsb = __ffs(tx_mask);
if ((lsb + 1) != __fls(tx_mask)) {
dev_err(codec->dev, "Invalid mask, slots must be adjacent\n");
return -EINVAL;
}
switch (slot_width) {
case 16:
case 20:
case 24:
case 32:
break;
default:
dev_err(codec->dev, "Unsupported slot width %d\n", slot_width);
return -EINVAL;
}
aic3x->tdm_delay = lsb;
aic3x->slot_width = slot_width;
snd_soc_update_bits(codec, AIC3X_ASD_INTF_CTRLA,
DOUT_TRISTATE, DOUT_TRISTATE);
return 0;
}
static int aic3x_regulator_event(struct notifier_block *nb,
unsigned long event, void *data)
{
struct aic3x_disable_nb *disable_nb =
container_of(nb, struct aic3x_disable_nb, nb);
struct aic3x_priv *aic3x = disable_nb->aic3x;
if (event & REGULATOR_EVENT_DISABLE) {
if (gpio_is_valid(aic3x->gpio_reset))
gpio_set_value(aic3x->gpio_reset, 0);
regcache_mark_dirty(aic3x->regmap);
}
return 0;
}
static int aic3x_set_power(struct snd_soc_codec *codec, int power)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
unsigned int pll_c, pll_d;
int ret;
if (power) {
ret = regulator_bulk_enable(ARRAY_SIZE(aic3x->supplies),
aic3x->supplies);
if (ret)
goto out;
aic3x->power = 1;
if (gpio_is_valid(aic3x->gpio_reset)) {
udelay(1);
gpio_set_value(aic3x->gpio_reset, 1);
}
regcache_cache_only(aic3x->regmap, false);
regcache_sync(aic3x->regmap);
pll_c = snd_soc_read(codec, AIC3X_PLL_PROGC_REG);
pll_d = snd_soc_read(codec, AIC3X_PLL_PROGD_REG);
if (pll_c == aic3x_reg[AIC3X_PLL_PROGC_REG].def ||
pll_d == aic3x_reg[AIC3X_PLL_PROGD_REG].def) {
snd_soc_write(codec, AIC3X_PLL_PROGC_REG, pll_c);
snd_soc_write(codec, AIC3X_PLL_PROGD_REG, pll_d);
}
} else {
snd_soc_write(codec, AIC3X_RESET, SOFT_RESET);
regcache_mark_dirty(aic3x->regmap);
aic3x->power = 0;
regcache_cache_only(aic3x->regmap, true);
ret = regulator_bulk_disable(ARRAY_SIZE(aic3x->supplies),
aic3x->supplies);
}
out:
return ret;
}
static int aic3x_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_STANDBY &&
aic3x->master) {
snd_soc_update_bits(codec, AIC3X_PLL_PROGA_REG,
PLL_ENABLE, PLL_ENABLE);
}
break;
case SND_SOC_BIAS_STANDBY:
if (!aic3x->power)
aic3x_set_power(codec, 1);
if (snd_soc_codec_get_bias_level(codec) == SND_SOC_BIAS_PREPARE &&
aic3x->master) {
snd_soc_update_bits(codec, AIC3X_PLL_PROGA_REG,
PLL_ENABLE, 0);
}
break;
case SND_SOC_BIAS_OFF:
if (aic3x->power)
aic3x_set_power(codec, 0);
break;
}
return 0;
}
static void aic3x_mono_init(struct snd_soc_codec *codec)
{
snd_soc_write(codec, DACL1_2_MONOLOPM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_write(codec, DACR1_2_MONOLOPM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_update_bits(codec, MONOLOPM_CTRL, UNMUTE, UNMUTE);
snd_soc_write(codec, PGAL_2_MONOLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, PGAR_2_MONOLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2L_2_MONOLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_MONOLOPM_VOL, DEFAULT_VOL);
}
static int aic3x_init(struct snd_soc_codec *codec)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
snd_soc_write(codec, AIC3X_PAGE_SELECT, PAGE0_SELECT);
snd_soc_write(codec, AIC3X_RESET, SOFT_RESET);
snd_soc_write(codec, LDAC_VOL, DEFAULT_VOL | MUTE_ON);
snd_soc_write(codec, RDAC_VOL, DEFAULT_VOL | MUTE_ON);
snd_soc_write(codec, DACL1_2_HPLOUT_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_write(codec, DACR1_2_HPROUT_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_write(codec, DACL1_2_HPLCOM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_write(codec, DACR1_2_HPRCOM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_write(codec, DACL1_2_LLOPM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_write(codec, DACR1_2_RLOPM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_update_bits(codec, LLOPM_CTRL, UNMUTE, UNMUTE);
snd_soc_update_bits(codec, RLOPM_CTRL, UNMUTE, UNMUTE);
snd_soc_update_bits(codec, HPLOUT_CTRL, UNMUTE, UNMUTE);
snd_soc_update_bits(codec, HPROUT_CTRL, UNMUTE, UNMUTE);
snd_soc_update_bits(codec, HPLCOM_CTRL, UNMUTE, UNMUTE);
snd_soc_update_bits(codec, HPRCOM_CTRL, UNMUTE, UNMUTE);
snd_soc_write(codec, LADC_VOL, DEFAULT_GAIN);
snd_soc_write(codec, RADC_VOL, DEFAULT_GAIN);
snd_soc_write(codec, LINE1L_2_LADC_CTRL, 0x0);
snd_soc_write(codec, LINE1R_2_RADC_CTRL, 0x0);
snd_soc_write(codec, PGAL_2_HPLOUT_VOL, DEFAULT_VOL);
snd_soc_write(codec, PGAR_2_HPROUT_VOL, DEFAULT_VOL);
snd_soc_write(codec, PGAL_2_HPLCOM_VOL, DEFAULT_VOL);
snd_soc_write(codec, PGAR_2_HPRCOM_VOL, DEFAULT_VOL);
snd_soc_write(codec, PGAL_2_LLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, PGAR_2_RLOPM_VOL, DEFAULT_VOL);
if (aic3x->model != AIC3X_MODEL_3104) {
snd_soc_write(codec, LINE2L_2_HPLOUT_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_HPROUT_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2L_2_HPLCOM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_HPRCOM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2L_2_LLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_RLOPM_VOL, DEFAULT_VOL);
}
switch (aic3x->model) {
case AIC3X_MODEL_3X:
case AIC3X_MODEL_33:
aic3x_mono_init(codec);
break;
case AIC3X_MODEL_3007:
snd_soc_write(codec, CLASSD_CTRL, 0);
break;
}
return 0;
}
static bool aic3x_is_shared_reset(struct aic3x_priv *aic3x)
{
struct aic3x_priv *a;
list_for_each_entry(a, &reset_list, list) {
if (gpio_is_valid(aic3x->gpio_reset) &&
aic3x->gpio_reset == a->gpio_reset)
return true;
}
return false;
}
static int aic3x_probe(struct snd_soc_codec *codec)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
int ret, i;
INIT_LIST_HEAD(&aic3x->list);
aic3x->codec = codec;
for (i = 0; i < ARRAY_SIZE(aic3x->supplies); i++) {
aic3x->disable_nb[i].nb.notifier_call = aic3x_regulator_event;
aic3x->disable_nb[i].aic3x = aic3x;
ret = regulator_register_notifier(aic3x->supplies[i].consumer,
&aic3x->disable_nb[i].nb);
if (ret) {
dev_err(codec->dev,
"Failed to request regulator notifier: %d\n",
ret);
goto err_notif;
}
}
regcache_mark_dirty(aic3x->regmap);
aic3x_init(codec);
if (aic3x->setup) {
if (aic3x->model != AIC3X_MODEL_3104) {
snd_soc_write(codec, AIC3X_GPIO1_REG,
(aic3x->setup->gpio_func[0] & 0xf) << 4);
snd_soc_write(codec, AIC3X_GPIO2_REG,
(aic3x->setup->gpio_func[1] & 0xf) << 4);
} else {
dev_warn(codec->dev, "GPIO functionality is not supported on tlv320aic3104\n");
}
}
switch (aic3x->model) {
case AIC3X_MODEL_3X:
case AIC3X_MODEL_33:
snd_soc_add_codec_controls(codec, aic3x_extra_snd_controls,
ARRAY_SIZE(aic3x_extra_snd_controls));
snd_soc_add_codec_controls(codec, aic3x_mono_controls,
ARRAY_SIZE(aic3x_mono_controls));
break;
case AIC3X_MODEL_3007:
snd_soc_add_codec_controls(codec, aic3x_extra_snd_controls,
ARRAY_SIZE(aic3x_extra_snd_controls));
snd_soc_add_codec_controls(codec,
&aic3x_classd_amp_gain_ctrl, 1);
break;
case AIC3X_MODEL_3104:
break;
}
switch (aic3x->micbias_vg) {
case AIC3X_MICBIAS_2_0V:
case AIC3X_MICBIAS_2_5V:
case AIC3X_MICBIAS_AVDDV:
snd_soc_update_bits(codec, MICBIAS_CTRL,
MICBIAS_LEVEL_MASK,
(aic3x->micbias_vg) << MICBIAS_LEVEL_SHIFT);
break;
case AIC3X_MICBIAS_OFF:
break;
}
aic3x_add_widgets(codec);
return 0;
err_notif:
while (i--)
regulator_unregister_notifier(aic3x->supplies[i].consumer,
&aic3x->disable_nb[i].nb);
return ret;
}
static int aic3x_remove(struct snd_soc_codec *codec)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
int i;
list_del(&aic3x->list);
for (i = 0; i < ARRAY_SIZE(aic3x->supplies); i++)
regulator_unregister_notifier(aic3x->supplies[i].consumer,
&aic3x->disable_nb[i].nb);
return 0;
}
static int aic3x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct aic3x_pdata *pdata = i2c->dev.platform_data;
struct aic3x_priv *aic3x;
struct aic3x_setup_data *ai3x_setup;
struct device_node *np = i2c->dev.of_node;
int ret, i;
u32 value;
aic3x = devm_kzalloc(&i2c->dev, sizeof(struct aic3x_priv), GFP_KERNEL);
if (!aic3x)
return -ENOMEM;
aic3x->regmap = devm_regmap_init_i2c(i2c, &aic3x_regmap);
if (IS_ERR(aic3x->regmap)) {
ret = PTR_ERR(aic3x->regmap);
return ret;
}
regcache_cache_only(aic3x->regmap, true);
i2c_set_clientdata(i2c, aic3x);
if (pdata) {
aic3x->gpio_reset = pdata->gpio_reset;
aic3x->setup = pdata->setup;
aic3x->micbias_vg = pdata->micbias_vg;
} else if (np) {
ai3x_setup = devm_kzalloc(&i2c->dev, sizeof(*ai3x_setup),
GFP_KERNEL);
if (!ai3x_setup)
return -ENOMEM;
ret = of_get_named_gpio(np, "gpio-reset", 0);
if (ret >= 0)
aic3x->gpio_reset = ret;
else
aic3x->gpio_reset = -1;
if (of_property_read_u32_array(np, "ai3x-gpio-func",
ai3x_setup->gpio_func, 2) >= 0) {
aic3x->setup = ai3x_setup;
}
if (!of_property_read_u32(np, "ai3x-micbias-vg", &value)) {
switch (value) {
case 1 :
aic3x->micbias_vg = AIC3X_MICBIAS_2_0V;
break;
case 2 :
aic3x->micbias_vg = AIC3X_MICBIAS_2_5V;
break;
case 3 :
aic3x->micbias_vg = AIC3X_MICBIAS_AVDDV;
break;
default :
aic3x->micbias_vg = AIC3X_MICBIAS_OFF;
dev_err(&i2c->dev, "Unsuitable MicBias voltage "
"found in DT\n");
}
} else {
aic3x->micbias_vg = AIC3X_MICBIAS_OFF;
}
} else {
aic3x->gpio_reset = -1;
}
aic3x->model = id->driver_data;
if (gpio_is_valid(aic3x->gpio_reset) &&
!aic3x_is_shared_reset(aic3x)) {
ret = gpio_request(aic3x->gpio_reset, "tlv320aic3x reset");
if (ret != 0)
goto err;
gpio_direction_output(aic3x->gpio_reset, 0);
}
for (i = 0; i < ARRAY_SIZE(aic3x->supplies); i++)
aic3x->supplies[i].supply = aic3x_supply_names[i];
ret = devm_regulator_bulk_get(&i2c->dev, ARRAY_SIZE(aic3x->supplies),
aic3x->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to request supplies: %d\n", ret);
goto err_gpio;
}
if (aic3x->model == AIC3X_MODEL_3007) {
ret = regmap_register_patch(aic3x->regmap, aic3007_class_d,
ARRAY_SIZE(aic3007_class_d));
if (ret != 0)
dev_err(&i2c->dev, "Failed to init class D: %d\n",
ret);
}
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_aic3x, &aic3x_dai, 1);
if (ret != 0)
goto err_gpio;
list_add(&aic3x->list, &reset_list);
return 0;
err_gpio:
if (gpio_is_valid(aic3x->gpio_reset) &&
!aic3x_is_shared_reset(aic3x))
gpio_free(aic3x->gpio_reset);
err:
return ret;
}
static int aic3x_i2c_remove(struct i2c_client *client)
{
struct aic3x_priv *aic3x = i2c_get_clientdata(client);
snd_soc_unregister_codec(&client->dev);
if (gpio_is_valid(aic3x->gpio_reset) &&
!aic3x_is_shared_reset(aic3x)) {
gpio_set_value(aic3x->gpio_reset, 0);
gpio_free(aic3x->gpio_reset);
}
return 0;
}
