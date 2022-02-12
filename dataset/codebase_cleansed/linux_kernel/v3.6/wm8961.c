static int wm8961_volatile_register(struct snd_soc_codec *codec, unsigned int reg)
{
switch (reg) {
case WM8961_SOFTWARE_RESET:
case WM8961_WRITE_SEQUENCER_7:
case WM8961_DC_SERVO_1:
return 1;
default:
return 0;
}
}
static int wm8961_reset(struct snd_soc_codec *codec)
{
return snd_soc_write(codec, WM8961_SOFTWARE_RESET, 0);
}
static int wm8961_hp_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
u16 hp_reg = snd_soc_read(codec, WM8961_ANALOGUE_HP_0);
u16 cp_reg = snd_soc_read(codec, WM8961_CHARGE_PUMP_1);
u16 pwr_reg = snd_soc_read(codec, WM8961_PWR_MGMT_2);
u16 dcs_reg = snd_soc_read(codec, WM8961_DC_SERVO_1);
int timeout = 500;
if (event & SND_SOC_DAPM_POST_PMU) {
hp_reg &= ~(WM8961_HPR_RMV_SHORT | WM8961_HPL_RMV_SHORT);
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
cp_reg |= WM8961_CP_ENA;
snd_soc_write(codec, WM8961_CHARGE_PUMP_1, cp_reg);
mdelay(5);
pwr_reg |= WM8961_LOUT1_PGA | WM8961_ROUT1_PGA;
snd_soc_write(codec, WM8961_PWR_MGMT_2, pwr_reg);
hp_reg |= WM8961_HPR_ENA | WM8961_HPL_ENA;
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
hp_reg |= WM8961_HPR_ENA_DLY | WM8961_HPL_ENA_DLY;
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
dcs_reg |=
WM8961_DCS_ENA_CHAN_HPR | WM8961_DCS_TRIG_STARTUP_HPR |
WM8961_DCS_ENA_CHAN_HPL | WM8961_DCS_TRIG_STARTUP_HPL;
dev_dbg(codec->dev, "Enabling DC servo\n");
snd_soc_write(codec, WM8961_DC_SERVO_1, dcs_reg);
do {
msleep(1);
dcs_reg = snd_soc_read(codec, WM8961_DC_SERVO_1);
} while (--timeout &&
dcs_reg & (WM8961_DCS_TRIG_STARTUP_HPR |
WM8961_DCS_TRIG_STARTUP_HPL));
if (dcs_reg & (WM8961_DCS_TRIG_STARTUP_HPR |
WM8961_DCS_TRIG_STARTUP_HPL))
dev_err(codec->dev, "DC servo timed out\n");
else
dev_dbg(codec->dev, "DC servo startup complete\n");
hp_reg |= WM8961_HPR_ENA_OUTP | WM8961_HPL_ENA_OUTP;
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
hp_reg |= WM8961_HPR_RMV_SHORT | WM8961_HPL_RMV_SHORT;
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
}
if (event & SND_SOC_DAPM_PRE_PMD) {
hp_reg &= ~(WM8961_HPR_RMV_SHORT | WM8961_HPL_RMV_SHORT);
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
hp_reg &= ~(WM8961_HPR_ENA_OUTP | WM8961_HPL_ENA_OUTP);
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
dcs_reg &= ~(WM8961_DCS_ENA_CHAN_HPR |
WM8961_DCS_ENA_CHAN_HPL);
snd_soc_write(codec, WM8961_DC_SERVO_1, dcs_reg);
hp_reg &= ~(WM8961_HPR_ENA_DLY | WM8961_HPR_ENA |
WM8961_HPL_ENA_DLY | WM8961_HPL_ENA);
snd_soc_write(codec, WM8961_ANALOGUE_HP_0, hp_reg);
pwr_reg &= ~(WM8961_LOUT1_PGA | WM8961_ROUT1_PGA);
snd_soc_write(codec, WM8961_PWR_MGMT_2, pwr_reg);
dev_dbg(codec->dev, "Disabling charge pump\n");
snd_soc_write(codec, WM8961_CHARGE_PUMP_1,
cp_reg & ~WM8961_CP_ENA);
}
return 0;
}
static int wm8961_spk_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
u16 pwr_reg = snd_soc_read(codec, WM8961_PWR_MGMT_2);
u16 spk_reg = snd_soc_read(codec, WM8961_CLASS_D_CONTROL_1);
if (event & SND_SOC_DAPM_POST_PMU) {
pwr_reg |= WM8961_SPKL_PGA | WM8961_SPKR_PGA;
snd_soc_write(codec, WM8961_PWR_MGMT_2, pwr_reg);
spk_reg |= WM8961_SPKL_ENA | WM8961_SPKR_ENA;
snd_soc_write(codec, WM8961_CLASS_D_CONTROL_1, spk_reg);
}
if (event & SND_SOC_DAPM_PRE_PMD) {
spk_reg &= ~(WM8961_SPKL_ENA | WM8961_SPKR_ENA);
snd_soc_write(codec, WM8961_CLASS_D_CONTROL_1, spk_reg);
pwr_reg &= ~(WM8961_SPKL_PGA | WM8961_SPKR_PGA);
snd_soc_write(codec, WM8961_PWR_MGMT_2, pwr_reg);
}
return 0;
}
static int wm8961_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8961_priv *wm8961 = snd_soc_codec_get_drvdata(codec);
int i, best, target, fs;
u16 reg;
fs = params_rate(params);
if (!wm8961->sysclk) {
dev_err(codec->dev, "MCLK has not been specified\n");
return -EINVAL;
}
best = 0;
for (i = 0; i < ARRAY_SIZE(wm8961_srate); i++) {
if (abs(wm8961_srate[i].rate - fs) <
abs(wm8961_srate[best].rate - fs))
best = i;
}
reg = snd_soc_read(codec, WM8961_ADDITIONAL_CONTROL_3);
reg &= ~WM8961_SAMPLE_RATE_MASK;
reg |= wm8961_srate[best].val;
snd_soc_write(codec, WM8961_ADDITIONAL_CONTROL_3, reg);
dev_dbg(codec->dev, "Selected SRATE %dHz for %dHz\n",
wm8961_srate[best].rate, fs);
target = wm8961->sysclk / fs;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK && target < 64) {
dev_err(codec->dev,
"SYSCLK must be at least 64*fs for DAC\n");
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE && target < 256) {
dev_err(codec->dev,
"SYSCLK must be at least 256*fs for ADC\n");
return -EINVAL;
}
for (i = 0; i < ARRAY_SIZE(wm8961_clk_sys_ratio); i++) {
if (wm8961_clk_sys_ratio[i].ratio >= target)
break;
}
if (i == ARRAY_SIZE(wm8961_clk_sys_ratio)) {
dev_err(codec->dev, "Unable to generate CLK_SYS_RATE\n");
return -EINVAL;
}
dev_dbg(codec->dev, "Selected CLK_SYS_RATE of %d for %d/%d=%d\n",
wm8961_clk_sys_ratio[i].ratio, wm8961->sysclk, fs,
wm8961->sysclk / fs);
reg = snd_soc_read(codec, WM8961_CLOCKING_4);
reg &= ~WM8961_CLK_SYS_RATE_MASK;
reg |= wm8961_clk_sys_ratio[i].val << WM8961_CLK_SYS_RATE_SHIFT;
snd_soc_write(codec, WM8961_CLOCKING_4, reg);
reg = snd_soc_read(codec, WM8961_AUDIO_INTERFACE_0);
reg &= ~WM8961_WL_MASK;
switch (params_format(params)) {
case SNDRV_PCM_FORMAT_S16_LE:
break;
case SNDRV_PCM_FORMAT_S20_3LE:
reg |= 1 << WM8961_WL_SHIFT;
break;
case SNDRV_PCM_FORMAT_S24_LE:
reg |= 2 << WM8961_WL_SHIFT;
break;
case SNDRV_PCM_FORMAT_S32_LE:
reg |= 3 << WM8961_WL_SHIFT;
break;
default:
return -EINVAL;
}
snd_soc_write(codec, WM8961_AUDIO_INTERFACE_0, reg);
reg = snd_soc_read(codec, WM8961_ADC_DAC_CONTROL_2);
if (fs <= 24000)
reg |= WM8961_DACSLOPE;
else
reg &= ~WM8961_DACSLOPE;
snd_soc_write(codec, WM8961_ADC_DAC_CONTROL_2, reg);
return 0;
}
static int wm8961_set_sysclk(struct snd_soc_dai *dai, int clk_id,
unsigned int freq,
int dir)
{
struct snd_soc_codec *codec = dai->codec;
struct wm8961_priv *wm8961 = snd_soc_codec_get_drvdata(codec);
u16 reg = snd_soc_read(codec, WM8961_CLOCKING1);
if (freq > 33000000) {
dev_err(codec->dev, "MCLK must be <33MHz\n");
return -EINVAL;
}
if (freq > 16500000) {
dev_dbg(codec->dev, "Using MCLK/2 for %dHz MCLK\n", freq);
reg |= WM8961_MCLKDIV;
freq /= 2;
} else {
dev_dbg(codec->dev, "Using MCLK/1 for %dHz MCLK\n", freq);
reg &= ~WM8961_MCLKDIV;
}
snd_soc_write(codec, WM8961_CLOCKING1, reg);
wm8961->sysclk = freq;
return 0;
}
static int wm8961_set_fmt(struct snd_soc_dai *dai, unsigned int fmt)
{
struct snd_soc_codec *codec = dai->codec;
u16 aif = snd_soc_read(codec, WM8961_AUDIO_INTERFACE_0);
aif &= ~(WM8961_BCLKINV | WM8961_LRP |
WM8961_MS | WM8961_FORMAT_MASK);
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
aif |= WM8961_MS;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_RIGHT_J:
break;
case SND_SOC_DAIFMT_LEFT_J:
aif |= 1;
break;
case SND_SOC_DAIFMT_I2S:
aif |= 2;
break;
case SND_SOC_DAIFMT_DSP_B:
aif |= WM8961_LRP;
case SND_SOC_DAIFMT_DSP_A:
aif |= 3;
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
case SND_SOC_DAIFMT_IB_NF:
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
break;
case SND_SOC_DAIFMT_NB_IF:
aif |= WM8961_LRP;
break;
case SND_SOC_DAIFMT_IB_NF:
aif |= WM8961_BCLKINV;
break;
case SND_SOC_DAIFMT_IB_IF:
aif |= WM8961_BCLKINV | WM8961_LRP;
break;
default:
return -EINVAL;
}
return snd_soc_write(codec, WM8961_AUDIO_INTERFACE_0, aif);
}
static int wm8961_set_tristate(struct snd_soc_dai *dai, int tristate)
{
struct snd_soc_codec *codec = dai->codec;
u16 reg = snd_soc_read(codec, WM8961_ADDITIONAL_CONTROL_2);
if (tristate)
reg |= WM8961_TRIS;
else
reg &= ~WM8961_TRIS;
return snd_soc_write(codec, WM8961_ADDITIONAL_CONTROL_2, reg);
}
static int wm8961_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
u16 reg = snd_soc_read(codec, WM8961_ADC_DAC_CONTROL_1);
if (mute)
reg |= WM8961_DACMU;
else
reg &= ~WM8961_DACMU;
msleep(17);
return snd_soc_write(codec, WM8961_ADC_DAC_CONTROL_1, reg);
}
static int wm8961_set_clkdiv(struct snd_soc_dai *dai, int div_id, int div)
{
struct snd_soc_codec *codec = dai->codec;
u16 reg;
switch (div_id) {
case WM8961_BCLK:
reg = snd_soc_read(codec, WM8961_CLOCKING2);
reg &= ~WM8961_BCLKDIV_MASK;
reg |= div;
snd_soc_write(codec, WM8961_CLOCKING2, reg);
break;
case WM8961_LRCLK:
reg = snd_soc_read(codec, WM8961_AUDIO_INTERFACE_2);
reg &= ~WM8961_LRCLK_RATE_MASK;
reg |= div;
snd_soc_write(codec, WM8961_AUDIO_INTERFACE_2, reg);
break;
default:
return -EINVAL;
}
return 0;
}
static int wm8961_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
u16 reg;
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY) {
reg = snd_soc_read(codec, WM8961_ANTI_POP);
reg |= WM8961_BUFIOEN | WM8961_BUFDCOPEN;
snd_soc_write(codec, WM8961_ANTI_POP, reg);
reg = snd_soc_read(codec, WM8961_PWR_MGMT_1);
reg &= ~WM8961_VMIDSEL_MASK;
reg |= (1 << WM8961_VMIDSEL_SHIFT) | WM8961_VREF;
snd_soc_write(codec, WM8961_PWR_MGMT_1, reg);
}
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_PREPARE) {
reg = snd_soc_read(codec, WM8961_PWR_MGMT_1);
reg &= ~WM8961_VREF;
snd_soc_write(codec, WM8961_PWR_MGMT_1, reg);
reg = snd_soc_read(codec, WM8961_ANTI_POP);
reg &= ~(WM8961_BUFIOEN | WM8961_BUFDCOPEN);
snd_soc_write(codec, WM8961_ANTI_POP, reg);
reg = snd_soc_read(codec, WM8961_PWR_MGMT_1);
reg &= ~WM8961_VMIDSEL_MASK;
snd_soc_write(codec, WM8961_PWR_MGMT_1, reg);
}
break;
case SND_SOC_BIAS_OFF:
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int wm8961_probe(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret = 0;
u16 reg;
ret = snd_soc_codec_set_cache_io(codec, 8, 16, SND_SOC_I2C);
if (ret != 0) {
dev_err(codec->dev, "Failed to set cache I/O: %d\n", ret);
return ret;
}
reg = snd_soc_read(codec, WM8961_SOFTWARE_RESET);
if (reg != 0x1801) {
dev_err(codec->dev, "Device is not a WM8961: ID=0x%x\n", reg);
return -EINVAL;
}
codec->cache_bypass = 1;
reg = snd_soc_read(codec, WM8961_RIGHT_INPUT_VOLUME);
codec->cache_bypass = 0;
dev_info(codec->dev, "WM8961 family %d revision %c\n",
(reg & WM8961_DEVICE_ID_MASK) >> WM8961_DEVICE_ID_SHIFT,
((reg & WM8961_CHIP_REV_MASK) >> WM8961_CHIP_REV_SHIFT)
+ 'A');
ret = wm8961_reset(codec);
if (ret < 0) {
dev_err(codec->dev, "Failed to issue reset\n");
return ret;
}
reg = snd_soc_read(codec, WM8961_CHARGE_PUMP_B);
reg |= WM8961_CP_DYN_PWR_MASK;
snd_soc_write(codec, WM8961_CHARGE_PUMP_B, reg);
reg = snd_soc_read(codec, WM8961_ROUT1_VOLUME);
snd_soc_write(codec, WM8961_ROUT1_VOLUME,
reg | WM8961_LO1ZC | WM8961_OUT1VU);
snd_soc_write(codec, WM8961_LOUT1_VOLUME, reg | WM8961_LO1ZC);
reg = snd_soc_read(codec, WM8961_ROUT2_VOLUME);
snd_soc_write(codec, WM8961_ROUT2_VOLUME,
reg | WM8961_SPKRZC | WM8961_SPKVU);
snd_soc_write(codec, WM8961_LOUT2_VOLUME, reg | WM8961_SPKLZC);
reg = snd_soc_read(codec, WM8961_RIGHT_ADC_VOLUME);
snd_soc_write(codec, WM8961_RIGHT_ADC_VOLUME, reg | WM8961_ADCVU);
reg = snd_soc_read(codec, WM8961_RIGHT_INPUT_VOLUME);
snd_soc_write(codec, WM8961_RIGHT_INPUT_VOLUME, reg | WM8961_IPVU);
reg = snd_soc_read(codec, WM8961_ADC_DAC_CONTROL_2);
reg |= WM8961_DACSMM;
snd_soc_write(codec, WM8961_ADC_DAC_CONTROL_2, reg);
reg = snd_soc_read(codec, WM8961_CLOCKING_3);
reg &= ~WM8961_MANUAL_MODE;
snd_soc_write(codec, WM8961_CLOCKING_3, reg);
wm8961_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
snd_soc_add_codec_controls(codec, wm8961_snd_controls,
ARRAY_SIZE(wm8961_snd_controls));
snd_soc_dapm_new_controls(dapm, wm8961_dapm_widgets,
ARRAY_SIZE(wm8961_dapm_widgets));
snd_soc_dapm_add_routes(dapm, audio_paths, ARRAY_SIZE(audio_paths));
return 0;
}
static int wm8961_remove(struct snd_soc_codec *codec)
{
wm8961_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8961_suspend(struct snd_soc_codec *codec)
{
wm8961_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int wm8961_resume(struct snd_soc_codec *codec)
{
snd_soc_cache_sync(codec);
wm8961_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static __devinit int wm8961_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8961_priv *wm8961;
int ret;
wm8961 = devm_kzalloc(&i2c->dev, sizeof(struct wm8961_priv),
GFP_KERNEL);
if (wm8961 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8961);
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_wm8961, &wm8961_dai, 1);
return ret;
}
static __devexit int wm8961_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
static int __init wm8961_modinit(void)
{
int ret = 0;
ret = i2c_add_driver(&wm8961_i2c_driver);
if (ret != 0) {
printk(KERN_ERR "Failed to register wm8961 I2C driver: %d\n",
ret);
}
return ret;
}
static void __exit wm8961_exit(void)
{
i2c_del_driver(&wm8961_i2c_driver);
}
