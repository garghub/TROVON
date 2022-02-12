static int snd_soc_dapm_put_volsw_aic3x(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_dapm_widget_list *wlist = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_widget *widget = wlist->widgets[0];
struct soc_mixer_control *mc =
(struct soc_mixer_control *)kcontrol->private_value;
unsigned int reg = mc->reg;
unsigned int shift = mc->shift;
int max = mc->max;
unsigned int mask = (1 << fls(max)) - 1;
unsigned int invert = mc->invert;
unsigned short val, val_mask;
int ret;
struct snd_soc_dapm_path *path;
int found = 0;
val = (ucontrol->value.integer.value[0] & mask);
mask = 0xf;
if (val)
val = mask;
if (invert)
val = mask - val;
val_mask = mask << shift;
val = val << shift;
mutex_lock(&widget->codec->mutex);
if (snd_soc_test_bits(widget->codec, reg, val_mask, val)) {
list_for_each_entry(path, &widget->dapm->card->paths, list) {
if (path->kcontrol != kcontrol)
continue;
found = 1;
if (val)
path->connect = invert ? 0 : 1;
else
path->connect = invert ? 1 : 0;
dapm_mark_dirty(path->source, "tlv320aic3x source");
dapm_mark_dirty(path->sink, "tlv320aic3x sink");
break;
}
if (found)
snd_soc_dapm_sync(widget->dapm);
}
ret = snd_soc_update_bits(widget->codec, reg, val_mask, val);
mutex_unlock(&widget->codec->mutex);
return ret;
}
static int aic3x_add_widgets(struct snd_soc_codec *codec)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
struct snd_soc_dapm_context *dapm = &codec->dapm;
snd_soc_dapm_new_controls(dapm, aic3x_dapm_widgets,
ARRAY_SIZE(aic3x_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon, ARRAY_SIZE(intercon));
if (aic3x->model == AIC3X_MODEL_3007) {
snd_soc_dapm_new_controls(dapm, aic3007_dapm_widgets,
ARRAY_SIZE(aic3007_dapm_widgets));
snd_soc_dapm_add_routes(dapm, intercon_3007,
ARRAY_SIZE(intercon_3007));
}
return 0;
}
static int aic3x_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec =rtd->codec;
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
int codec_clk = 0, bypass_pll = 0, fsref, last_clk = 0;
u8 data, j, r, p, pll_q, pll_p = 1, pll_r = 1, pll_j = 1;
u16 d, pll_d = 1;
int clk;
data = snd_soc_read(codec, AIC3X_ASD_INTF_CTRLB) & (~(0x3 << 4));
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
data |= (0x01 << 4);
break;
case SNDRV_PCM_FORMAT_S24_LE:
data |= (0x02 << 4);
break;
case SNDRV_PCM_FORMAT_S32_LE:
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
data = snd_soc_read(codec, AIC3X_PLL_PROGA_REG);
snd_soc_write(codec, AIC3X_PLL_PROGA_REG,
data | (pll_p << PLLP_SHIFT));
snd_soc_write(codec, AIC3X_OVRF_STATUS_AND_PLLR_REG,
pll_r << PLLR_SHIFT);
snd_soc_write(codec, AIC3X_PLL_PROGB_REG, pll_j << PLLJ_SHIFT);
snd_soc_write(codec, AIC3X_PLL_PROGC_REG,
(pll_d >> 6) << PLLD_MSB_SHIFT);
snd_soc_write(codec, AIC3X_PLL_PROGD_REG,
(pll_d & 0x3F) << PLLD_LSB_SHIFT);
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
aic3x->sysclk = freq;
return 0;
}
static int aic3x_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
u8 iface_areg, iface_breg;
int delay = 0;
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
delay = 1;
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
snd_soc_write(codec, AIC3X_ASD_INTF_CTRLA, iface_areg);
snd_soc_write(codec, AIC3X_ASD_INTF_CTRLB, iface_breg);
snd_soc_write(codec, AIC3X_ASD_INTF_CTRLC, delay);
return 0;
}
static int aic3x_init_3007(struct snd_soc_codec *codec)
{
u8 tmp1, tmp2, *cache = codec->reg_cache;
tmp1 = cache[0xD];
tmp2 = cache[0x8];
snd_soc_write(codec, AIC3X_PAGE_SELECT, 0x0D);
snd_soc_write(codec, 0xD, 0x0D);
snd_soc_write(codec, 0x8, 0x5C);
snd_soc_write(codec, 0x8, 0x5D);
snd_soc_write(codec, 0x8, 0x5C);
snd_soc_write(codec, AIC3X_PAGE_SELECT, 0x00);
cache[0xD] = tmp1;
cache[0x8] = tmp2;
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
aic3x->codec->cache_sync = 1;
}
return 0;
}
static int aic3x_set_power(struct snd_soc_codec *codec, int power)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
int i, ret;
u8 *cache = codec->reg_cache;
if (power) {
ret = regulator_bulk_enable(ARRAY_SIZE(aic3x->supplies),
aic3x->supplies);
if (ret)
goto out;
aic3x->power = 1;
if (!codec->cache_sync)
goto out;
if (gpio_is_valid(aic3x->gpio_reset)) {
udelay(1);
gpio_set_value(aic3x->gpio_reset, 1);
}
codec->cache_only = 0;
for (i = AIC3X_SAMPLE_RATE_SEL_REG; i < ARRAY_SIZE(aic3x_reg); i++)
snd_soc_write(codec, i, cache[i]);
if (aic3x->model == AIC3X_MODEL_3007)
aic3x_init_3007(codec);
codec->cache_sync = 0;
} else {
snd_soc_write(codec, AIC3X_RESET, SOFT_RESET);
codec->cache_sync = 1;
aic3x->power = 0;
codec->cache_only = 1;
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
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY &&
aic3x->master) {
snd_soc_update_bits(codec, AIC3X_PLL_PROGA_REG,
PLL_ENABLE, PLL_ENABLE);
}
break;
case SND_SOC_BIAS_STANDBY:
if (!aic3x->power)
aic3x_set_power(codec, 1);
if (codec->dapm.bias_level == SND_SOC_BIAS_PREPARE &&
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
codec->dapm.bias_level = level;
return 0;
}
void aic3x_set_headset_detection(struct snd_soc_codec *codec, int detect,
int headset_debounce, int button_debounce)
{
u8 val;
val = ((detect & AIC3X_HEADSET_DETECT_MASK)
<< AIC3X_HEADSET_DETECT_SHIFT) |
((headset_debounce & AIC3X_HEADSET_DEBOUNCE_MASK)
<< AIC3X_HEADSET_DEBOUNCE_SHIFT) |
((button_debounce & AIC3X_BUTTON_DEBOUNCE_MASK)
<< AIC3X_BUTTON_DEBOUNCE_SHIFT);
if (detect & AIC3X_HEADSET_DETECT_MASK)
val |= AIC3X_HEADSET_DETECT_ENABLED;
snd_soc_write(codec, AIC3X_HEADSET_DETECT_CTRL_A, val);
}
static int aic3x_suspend(struct snd_soc_codec *codec)
{
aic3x_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int aic3x_resume(struct snd_soc_codec *codec)
{
aic3x_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
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
snd_soc_write(codec, DACL1_2_MONOLOPM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_write(codec, DACR1_2_MONOLOPM_VOL, DEFAULT_VOL | ROUTE_ON);
snd_soc_update_bits(codec, LLOPM_CTRL, UNMUTE, UNMUTE);
snd_soc_update_bits(codec, RLOPM_CTRL, UNMUTE, UNMUTE);
snd_soc_update_bits(codec, MONOLOPM_CTRL, UNMUTE, UNMUTE);
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
snd_soc_write(codec, PGAL_2_MONOLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, PGAR_2_MONOLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2L_2_HPLOUT_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_HPROUT_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2L_2_HPLCOM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_HPRCOM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2L_2_LLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_RLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2L_2_MONOLOPM_VOL, DEFAULT_VOL);
snd_soc_write(codec, LINE2R_2_MONOLOPM_VOL, DEFAULT_VOL);
if (aic3x->model == AIC3X_MODEL_3007) {
aic3x_init_3007(codec);
snd_soc_write(codec, CLASSD_CTRL, 0);
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
ret = snd_soc_codec_set_cache_io(codec, 8, 8, aic3x->control_type);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
if (gpio_is_valid(aic3x->gpio_reset) &&
!aic3x_is_shared_reset(aic3x)) {
ret = gpio_request(aic3x->gpio_reset, "tlv320aic3x reset");
if (ret != 0)
goto err_gpio;
gpio_direction_output(aic3x->gpio_reset, 0);
}
for (i = 0; i < ARRAY_SIZE(aic3x->supplies); i++)
aic3x->supplies[i].supply = aic3x_supply_names[i];
ret = regulator_bulk_get(codec->dev, ARRAY_SIZE(aic3x->supplies),
aic3x->supplies);
if (ret != 0) {
dev_err(codec->dev, "Failed to request supplies: %d\n", ret);
goto err_get;
}
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
codec->cache_only = 1;
aic3x_init(codec);
if (aic3x->setup) {
snd_soc_write(codec, AIC3X_GPIO1_REG,
(aic3x->setup->gpio_func[0] & 0xf) << 4);
snd_soc_write(codec, AIC3X_GPIO2_REG,
(aic3x->setup->gpio_func[1] & 0xf) << 4);
}
snd_soc_add_codec_controls(codec, aic3x_snd_controls,
ARRAY_SIZE(aic3x_snd_controls));
if (aic3x->model == AIC3X_MODEL_3007)
snd_soc_add_codec_controls(codec, &aic3x_classd_amp_gain_ctrl, 1);
aic3x_add_widgets(codec);
list_add(&aic3x->list, &reset_list);
return 0;
err_notif:
while (i--)
regulator_unregister_notifier(aic3x->supplies[i].consumer,
&aic3x->disable_nb[i].nb);
regulator_bulk_free(ARRAY_SIZE(aic3x->supplies), aic3x->supplies);
err_get:
if (gpio_is_valid(aic3x->gpio_reset) &&
!aic3x_is_shared_reset(aic3x))
gpio_free(aic3x->gpio_reset);
err_gpio:
return ret;
}
static int aic3x_remove(struct snd_soc_codec *codec)
{
struct aic3x_priv *aic3x = snd_soc_codec_get_drvdata(codec);
int i;
aic3x_set_bias_level(codec, SND_SOC_BIAS_OFF);
list_del(&aic3x->list);
if (gpio_is_valid(aic3x->gpio_reset) &&
!aic3x_is_shared_reset(aic3x)) {
gpio_set_value(aic3x->gpio_reset, 0);
gpio_free(aic3x->gpio_reset);
}
for (i = 0; i < ARRAY_SIZE(aic3x->supplies); i++)
regulator_unregister_notifier(aic3x->supplies[i].consumer,
&aic3x->disable_nb[i].nb);
regulator_bulk_free(ARRAY_SIZE(aic3x->supplies), aic3x->supplies);
return 0;
}
static int aic3x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct aic3x_pdata *pdata = i2c->dev.platform_data;
struct aic3x_priv *aic3x;
int ret;
aic3x = devm_kzalloc(&i2c->dev, sizeof(struct aic3x_priv), GFP_KERNEL);
if (aic3x == NULL) {
dev_err(&i2c->dev, "failed to create private data\n");
return -ENOMEM;
}
aic3x->control_type = SND_SOC_I2C;
i2c_set_clientdata(i2c, aic3x);
if (pdata) {
aic3x->gpio_reset = pdata->gpio_reset;
aic3x->setup = pdata->setup;
} else {
aic3x->gpio_reset = -1;
}
aic3x->model = id->driver_data;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_aic3x, &aic3x_dai, 1);
return ret;
}
static int aic3x_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init aic3x_modinit(void)
{
int ret = 0;
ret = i2c_add_driver(&aic3x_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register TLV320AIC3x I2C driver: %d\n",
ret);
}
return ret;
}
static void __exit aic3x_exit(void)
{
i2c_del_driver(&aic3x_i2c_driver);
}
