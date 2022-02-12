static void sn95031_enable_mic_bias(struct snd_soc_codec *codec)
{
snd_soc_write(codec, SN95031_VAUD, BIT(2)|BIT(1)|BIT(0));
snd_soc_update_bits(codec, SN95031_MICBIAS, BIT(2), BIT(2));
}
static void configure_adc(struct snd_soc_codec *sn95031_codec, int val)
{
int value = snd_soc_read(sn95031_codec, SN95031_ADC1CNTL1);
if (val) {
value |= (SN95031_ADC_ENBL | SN95031_ADC_START);
value &= (~SN95031_ADC_NO_LOOP);
} else {
value &= (~SN95031_ADC_START);
}
snd_soc_write(sn95031_codec, SN95031_ADC1CNTL1, value);
}
static int find_free_channel(struct snd_soc_codec *sn95031_codec)
{
int i, value;
value = snd_soc_read(sn95031_codec, SN95031_ADC1CNTL1);
if ((value & SN95031_ADC_ENBL) == 0)
return 0;
for (i = 0; i < SN95031_ADC_CHANLS_MAX; i++) {
value = snd_soc_read(sn95031_codec,
SN95031_ADC_CHNL_START_ADDR + i);
if (value & SN95031_STOPBIT_MASK)
break;
}
return (i == SN95031_ADC_CHANLS_MAX) ? (-EINVAL) : i;
}
static int sn95031_initialize_adc(struct snd_soc_codec *sn95031_codec)
{
int base_addr, chnl_addr;
int value;
int channel_index;
channel_index = find_free_channel(sn95031_codec);
if (channel_index < 0) {
pr_err("No free ADC channels");
return channel_index;
}
base_addr = SN95031_ADC_CHNL_START_ADDR + channel_index;
if (!(channel_index == 0 || channel_index == SN95031_ADC_LOOP_MAX)) {
value = snd_soc_read(sn95031_codec, base_addr);
snd_soc_write(sn95031_codec, base_addr, value & 0xEF);
base_addr++;
channel_index++;
}
snd_soc_write(sn95031_codec, base_addr,
SN95031_AUDIO_DETECT_CODE | 0x10);
chnl_addr = SN95031_ADC_DATA_START_ADDR + 2 * channel_index;
pr_debug("mid_initialize : %x", chnl_addr);
configure_adc(sn95031_codec, 1);
return chnl_addr;
}
static unsigned int sn95031_get_mic_bias(struct snd_soc_codec *codec)
{
u16 adc_adr = sn95031_initialize_adc(codec);
u16 adc_val1, adc_val2;
unsigned int mic_bias;
sn95031_enable_mic_bias(codec);
snd_soc_write(codec, SN95031_ADC1CNTL3, 0x05);
snd_soc_write(codec, SN95031_ADC1CNTL3, 0x04);
msleep(1000);
adc_val1 = snd_soc_read(codec, adc_adr);
adc_adr++;
adc_val2 = snd_soc_read(codec, adc_adr);
mic_bias = (adc_val1 << 2) + (adc_val2 & 3);
mic_bias = (mic_bias * SN95031_ADC_ONE_LSB_MULTIPLIER) / 1000;
pr_debug("mic bias = %dmV\n", mic_bias);
return mic_bias;
}
static int sn95031_read(void *ctx, unsigned int reg, unsigned int *val)
{
u8 value = 0;
int ret;
ret = intel_scu_ipc_ioread8(reg, &value);
if (ret == 0)
*val = value;
return ret;
}
static int sn95031_write(void *ctx, unsigned int reg, unsigned int value)
{
return intel_scu_ipc_iowrite8(reg, value);
}
static int sn95031_set_vaud_bias(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
if (codec->dapm.bias_level == SND_SOC_BIAS_STANDBY) {
pr_debug("vaud_bias powering up pll\n");
snd_soc_write(codec, SN95031_AUDPLLCTRL, BIT(5));
snd_soc_update_bits(codec, SN95031_PCM2C2,
BIT(0), BIT(0));
}
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
pr_debug("vaud_bias power up rail\n");
snd_soc_write(codec, SN95031_VAUD,
BIT(2)|BIT(1)|BIT(0));
msleep(1);
} else if (codec->dapm.bias_level == SND_SOC_BIAS_PREPARE) {
pr_debug("vaud_bias power dn pcm\n");
snd_soc_update_bits(codec, SN95031_PCM2C2, BIT(0), 0);
snd_soc_write(codec, SN95031_AUDPLLCTRL, 0);
}
break;
case SND_SOC_BIAS_OFF:
pr_debug("vaud_bias _OFF doing rail shutdown\n");
snd_soc_write(codec, SN95031_VAUD, BIT(3));
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int sn95031_vhs_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
if (SND_SOC_DAPM_EVENT_ON(event)) {
pr_debug("VHS SND_SOC_DAPM_EVENT_ON doing rail startup now\n");
snd_soc_write(codec, SN95031_VHSP, 0x3D);
snd_soc_write(codec, SN95031_VHSN, 0x3F);
msleep(1);
} else if (SND_SOC_DAPM_EVENT_OFF(event)) {
pr_debug("VHS SND_SOC_DAPM_EVENT_OFF doing rail shutdown\n");
snd_soc_write(codec, SN95031_VHSP, 0xC4);
snd_soc_write(codec, SN95031_VHSN, 0x04);
}
return 0;
}
static int sn95031_vihf_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
if (SND_SOC_DAPM_EVENT_ON(event)) {
pr_debug("VIHF SND_SOC_DAPM_EVENT_ON doing rail startup now\n");
snd_soc_write(codec, SN95031_VIHF, 0x27);
msleep(1);
} else if (SND_SOC_DAPM_EVENT_OFF(event)) {
pr_debug("VIHF SND_SOC_DAPM_EVENT_OFF doing rail shutdown\n");
snd_soc_write(codec, SN95031_VIHF, 0x24);
}
return 0;
}
static int sn95031_dmic12_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int ldo = 0, clk_dir = 0, data_dir = 0;
if (SND_SOC_DAPM_EVENT_ON(event)) {
ldo = BIT(5)|BIT(4);
clk_dir = BIT(0);
data_dir = BIT(7);
}
snd_soc_update_bits(codec, SN95031_MICBIAS, BIT(5)|BIT(4), ldo);
snd_soc_update_bits(codec, SN95031_DMICBUF0123, BIT(0), clk_dir);
snd_soc_update_bits(codec, SN95031_DMICBUF0123, BIT(7), data_dir);
return 0;
}
static int sn95031_dmic34_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int ldo = 0, clk_dir = 0, data_dir = 0;
if (SND_SOC_DAPM_EVENT_ON(event)) {
ldo = BIT(5)|BIT(4);
clk_dir = BIT(2);
data_dir = BIT(1);
}
snd_soc_update_bits(codec, SN95031_MICBIAS, BIT(5)|BIT(4), ldo);
snd_soc_update_bits(codec, SN95031_DMICBUF0123, BIT(2), clk_dir);
snd_soc_update_bits(codec, SN95031_DMICBUF45, BIT(1), data_dir);
return 0;
}
static int sn95031_dmic56_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *k, int event)
{
struct snd_soc_codec *codec = snd_soc_dapm_to_codec(w->dapm);
unsigned int ldo = 0;
if (SND_SOC_DAPM_EVENT_ON(event))
ldo = BIT(7)|BIT(6);
snd_soc_update_bits(codec, SN95031_MICBIAS, BIT(7)|BIT(6), ldo);
return 0;
}
static int sn95031_pcm_hs_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec,
SN95031_HSLVOLCTRL, BIT(7), (!mute << 7));
snd_soc_update_bits(dai->codec,
SN95031_HSRVOLCTRL, BIT(7), (!mute << 7));
return 0;
}
static int sn95031_pcm_spkr_mute(struct snd_soc_dai *dai, int mute)
{
snd_soc_update_bits(dai->codec,
SN95031_IHFLVOLCTRL, BIT(7), (!mute << 7));
snd_soc_update_bits(dai->codec,
SN95031_IHFRVOLCTRL, BIT(7), (!mute << 7));
return 0;
}
static int sn95031_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
unsigned int format, rate;
switch (params_width(params)) {
case 16:
format = BIT(4)|BIT(5);
break;
case 24:
format = 0;
break;
default:
return -EINVAL;
}
snd_soc_update_bits(dai->codec, SN95031_PCM2C2,
BIT(4)|BIT(5), format);
switch (params_rate(params)) {
case 48000:
pr_debug("RATE_48000\n");
rate = 0;
break;
case 44100:
pr_debug("RATE_44100\n");
rate = BIT(7);
break;
default:
pr_err("ERR rate %d\n", params_rate(params));
return -EINVAL;
}
snd_soc_update_bits(dai->codec, SN95031_PCM1C1, BIT(7), rate);
return 0;
}
static inline void sn95031_disable_jack_btn(struct snd_soc_codec *codec)
{
snd_soc_write(codec, SN95031_BTNCTRL2, 0x00);
}
static inline void sn95031_enable_jack_btn(struct snd_soc_codec *codec)
{
snd_soc_write(codec, SN95031_BTNCTRL1, 0x77);
snd_soc_write(codec, SN95031_BTNCTRL2, 0x01);
}
static int sn95031_get_headset_state(struct snd_soc_codec *codec,
struct snd_soc_jack *mfld_jack)
{
int micbias = sn95031_get_mic_bias(codec);
int jack_type = snd_soc_jack_get_type(mfld_jack, micbias);
pr_debug("jack type detected = %d\n", jack_type);
if (jack_type == SND_JACK_HEADSET)
sn95031_enable_jack_btn(codec);
return jack_type;
}
void sn95031_jack_detection(struct snd_soc_codec *codec,
struct mfld_jack_data *jack_data)
{
unsigned int status;
unsigned int mask = SND_JACK_BTN_0 | SND_JACK_BTN_1 | SND_JACK_HEADSET;
pr_debug("interrupt id read in sram = 0x%x\n", jack_data->intr_id);
if (jack_data->intr_id & 0x1) {
pr_debug("short_push detected\n");
status = SND_JACK_HEADSET | SND_JACK_BTN_0;
} else if (jack_data->intr_id & 0x2) {
pr_debug("long_push detected\n");
status = SND_JACK_HEADSET | SND_JACK_BTN_1;
} else if (jack_data->intr_id & 0x4) {
pr_debug("headset or headphones inserted\n");
status = sn95031_get_headset_state(codec, jack_data->mfld_jack);
} else if (jack_data->intr_id & 0x8) {
pr_debug("headset or headphones removed\n");
status = 0;
sn95031_disable_jack_btn(codec);
} else {
pr_err("unidentified interrupt\n");
return;
}
snd_soc_jack_report(jack_data->mfld_jack, status, mask);
if ((status & SND_JACK_BTN_0) | (status & SND_JACK_BTN_1))
snd_soc_jack_report(jack_data->mfld_jack,
SND_JACK_HEADSET, mask);
}
static int sn95031_codec_probe(struct snd_soc_codec *codec)
{
pr_debug("codec_probe called\n");
snd_soc_write(codec, SN95031_PCM2RXSLOT01, 0x10);
snd_soc_write(codec, SN95031_PCM2RXSLOT23, 0x32);
snd_soc_write(codec, SN95031_PCM2RXSLOT45, 0x54);
snd_soc_write(codec, SN95031_PCM2TXSLOT01, 0x10);
snd_soc_write(codec, SN95031_PCM2TXSLOT23, 0x32);
snd_soc_write(codec, SN95031_PCM1C1, 0x00);
snd_soc_write(codec, SN95031_PCM2C1, 0x01);
snd_soc_write(codec, SN95031_PCM2C2, 0x0A);
snd_soc_write(codec, SN95031_HSMIXER, BIT(0)|BIT(4));
snd_soc_write(codec, SN95031_SSR5, 0x80);
snd_soc_write(codec, SN95031_SSR6, 0x80);
snd_soc_write(codec, SN95031_VIB1C5, 0x00);
snd_soc_write(codec, SN95031_VIB2C5, 0x00);
snd_soc_write(codec, SN95031_VIB1C3, 0x00);
snd_soc_write(codec, SN95031_VIB2C3, 0x00);
snd_soc_write(codec, SN95031_SOFTMUTE, 0x3);
snd_soc_write(codec, SN95031_HSLVOLCTRL, 0x08);
snd_soc_write(codec, SN95031_HSRVOLCTRL, 0x08);
snd_soc_write(codec, SN95031_IHFLVOLCTRL, 0x08);
snd_soc_write(codec, SN95031_IHFRVOLCTRL, 0x08);
snd_soc_write(codec, SN95031_SSR2, 0x10);
snd_soc_write(codec, SN95031_SSR3, 0x40);
return 0;
}
static int sn95031_device_probe(struct platform_device *pdev)
{
struct regmap *regmap;
pr_debug("codec device probe called for %s\n", dev_name(&pdev->dev));
regmap = devm_regmap_init(&pdev->dev, NULL, NULL, &sn95031_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
return snd_soc_register_codec(&pdev->dev, &sn95031_codec,
sn95031_dais, ARRAY_SIZE(sn95031_dais));
}
static int sn95031_device_remove(struct platform_device *pdev)
{
pr_debug("codec device remove called\n");
snd_soc_unregister_codec(&pdev->dev);
return 0;
}
