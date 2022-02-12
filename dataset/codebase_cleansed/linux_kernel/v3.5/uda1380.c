static inline unsigned int uda1380_read_reg_cache(struct snd_soc_codec *codec,
unsigned int reg)
{
u16 *cache = codec->reg_cache;
if (reg == UDA1380_RESET)
return 0;
if (reg >= UDA1380_CACHEREGNUM)
return -1;
return cache[reg];
}
static inline void uda1380_write_reg_cache(struct snd_soc_codec *codec,
u16 reg, unsigned int value)
{
u16 *cache = codec->reg_cache;
if (reg >= UDA1380_CACHEREGNUM)
return;
if ((reg >= 0x10) && (cache[reg] != value))
set_bit(reg - 0x10, &uda1380_cache_dirty);
cache[reg] = value;
}
static int uda1380_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[3];
data[0] = reg;
data[1] = (value & 0xff00) >> 8;
data[2] = value & 0x00ff;
uda1380_write_reg_cache(codec, reg, value);
if (!codec->active && (reg >= UDA1380_MVOL))
return 0;
pr_debug("uda1380: hw write %x val %x\n", reg, value);
if (codec->hw_write(codec->control_data, data, 3) == 3) {
unsigned int val;
i2c_master_send(codec->control_data, data, 1);
i2c_master_recv(codec->control_data, data, 2);
val = (data[0]<<8) | data[1];
if (val != value) {
pr_debug("uda1380: READ BACK VAL %x\n",
(data[0]<<8) | data[1]);
return -EIO;
}
if (reg >= 0x10)
clear_bit(reg - 0x10, &uda1380_cache_dirty);
return 0;
} else
return -EIO;
}
static void uda1380_sync_cache(struct snd_soc_codec *codec)
{
int reg;
u8 data[3];
u16 *cache = codec->reg_cache;
for (reg = 0; reg < UDA1380_MVOL; reg++) {
data[0] = reg;
data[1] = (cache[reg] & 0xff00) >> 8;
data[2] = cache[reg] & 0x00ff;
if (codec->hw_write(codec->control_data, data, 3) != 3)
dev_err(codec->dev, "%s: write to reg 0x%x failed\n",
__func__, reg);
}
}
static int uda1380_reset(struct snd_soc_codec *codec)
{
struct uda1380_platform_data *pdata = codec->dev->platform_data;
if (gpio_is_valid(pdata->gpio_reset)) {
gpio_set_value(pdata->gpio_reset, 1);
mdelay(1);
gpio_set_value(pdata->gpio_reset, 0);
} else {
u8 data[3];
data[0] = UDA1380_RESET;
data[1] = 0;
data[2] = 0;
if (codec->hw_write(codec->control_data, data, 3) != 3) {
dev_err(codec->dev, "%s: failed\n", __func__);
return -EIO;
}
}
return 0;
}
static void uda1380_flush_work(struct work_struct *work)
{
struct uda1380_priv *uda1380 = container_of(work, struct uda1380_priv, work);
struct snd_soc_codec *uda1380_codec = uda1380->codec;
int bit, reg;
for_each_set_bit(bit, &uda1380_cache_dirty, UDA1380_CACHEREGNUM - 0x10) {
reg = 0x10 + bit;
pr_debug("uda1380: flush reg %x val %x:\n", reg,
uda1380_read_reg_cache(uda1380_codec, reg));
uda1380_write(uda1380_codec, reg,
uda1380_read_reg_cache(uda1380_codec, reg));
clear_bit(bit, &uda1380_cache_dirty);
}
}
static int uda1380_set_dai_fmt_both(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
int iface;
iface = uda1380_read_reg_cache(codec, UDA1380_IFACE);
iface &= ~(R01_SFORI_MASK | R01_SIM | R01_SFORO_MASK);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= R01_SFORI_I2S | R01_SFORO_I2S;
break;
case SND_SOC_DAIFMT_LSB:
iface |= R01_SFORI_LSB16 | R01_SFORO_LSB16;
break;
case SND_SOC_DAIFMT_MSB:
iface |= R01_SFORI_MSB | R01_SFORO_MSB;
}
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS)
return -EINVAL;
uda1380_write(codec, UDA1380_IFACE, iface);
return 0;
}
static int uda1380_set_dai_fmt_playback(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
int iface;
iface = uda1380_read_reg_cache(codec, UDA1380_IFACE);
iface &= ~R01_SFORI_MASK;
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= R01_SFORI_I2S;
break;
case SND_SOC_DAIFMT_LSB:
iface |= R01_SFORI_LSB16;
break;
case SND_SOC_DAIFMT_MSB:
iface |= R01_SFORI_MSB;
}
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) != SND_SOC_DAIFMT_CBS_CFS)
return -EINVAL;
uda1380_write(codec, UDA1380_IFACE, iface);
return 0;
}
static int uda1380_set_dai_fmt_capture(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
int iface;
iface = uda1380_read_reg_cache(codec, UDA1380_IFACE);
iface &= ~(R01_SIM | R01_SFORO_MASK);
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
iface |= R01_SFORO_I2S;
break;
case SND_SOC_DAIFMT_LSB:
iface |= R01_SFORO_LSB16;
break;
case SND_SOC_DAIFMT_MSB:
iface |= R01_SFORO_MSB;
}
if ((fmt & SND_SOC_DAIFMT_MASTER_MASK) == SND_SOC_DAIFMT_CBM_CFM)
iface |= R01_SIM;
uda1380_write(codec, UDA1380_IFACE, iface);
return 0;
}
static int uda1380_trigger(struct snd_pcm_substream *substream, int cmd,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct uda1380_priv *uda1380 = snd_soc_codec_get_drvdata(codec);
int mixer = uda1380_read_reg_cache(codec, UDA1380_MIXER);
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
case SNDRV_PCM_TRIGGER_PAUSE_RELEASE:
uda1380_write_reg_cache(codec, UDA1380_MIXER,
mixer & ~R14_SILENCE);
schedule_work(&uda1380->work);
break;
case SNDRV_PCM_TRIGGER_STOP:
case SNDRV_PCM_TRIGGER_PAUSE_PUSH:
uda1380_write_reg_cache(codec, UDA1380_MIXER,
mixer | R14_SILENCE);
schedule_work(&uda1380->work);
break;
}
return 0;
}
static int uda1380_pcm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params,
struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
u16 clk = uda1380_read_reg_cache(codec, UDA1380_CLK);
if (clk & R00_DAC_CLK) {
int rate = params_rate(params);
u16 pm = uda1380_read_reg_cache(codec, UDA1380_PM);
clk &= ~0x3;
switch (rate) {
case 6250 ... 12500:
clk |= 0x0;
break;
case 12501 ... 25000:
clk |= 0x1;
break;
case 25001 ... 50000:
clk |= 0x2;
break;
case 50001 ... 100000:
clk |= 0x3;
break;
}
uda1380_write(codec, UDA1380_PM, R02_PON_PLL | pm);
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
clk |= R00_EN_DAC | R00_EN_INT;
else
clk |= R00_EN_ADC | R00_EN_DEC;
uda1380_write(codec, UDA1380_CLK, clk);
return 0;
}
static void uda1380_pcm_shutdown(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct snd_soc_pcm_runtime *rtd = substream->private_data;
struct snd_soc_codec *codec = rtd->codec;
u16 clk = uda1380_read_reg_cache(codec, UDA1380_CLK);
if (clk & R00_DAC_CLK) {
u16 pm = uda1380_read_reg_cache(codec, UDA1380_PM);
uda1380_write(codec, UDA1380_PM, ~R02_PON_PLL & pm);
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
clk &= ~(R00_EN_DAC | R00_EN_INT);
else
clk &= ~(R00_EN_ADC | R00_EN_DEC);
uda1380_write(codec, UDA1380_CLK, clk);
}
static int uda1380_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
int pm = uda1380_read_reg_cache(codec, UDA1380_PM);
int reg;
struct uda1380_platform_data *pdata = codec->dev->platform_data;
if (codec->dapm.bias_level == level)
return 0;
switch (level) {
case SND_SOC_BIAS_ON:
case SND_SOC_BIAS_PREPARE:
uda1380_write(codec, UDA1380_PM, R02_PON_BIAS | pm);
break;
case SND_SOC_BIAS_STANDBY:
if (codec->dapm.bias_level == SND_SOC_BIAS_OFF) {
if (gpio_is_valid(pdata->gpio_power)) {
gpio_set_value(pdata->gpio_power, 1);
mdelay(1);
uda1380_reset(codec);
}
uda1380_sync_cache(codec);
}
uda1380_write(codec, UDA1380_PM, 0x0);
break;
case SND_SOC_BIAS_OFF:
if (!gpio_is_valid(pdata->gpio_power))
break;
gpio_set_value(pdata->gpio_power, 0);
for (reg = UDA1380_MVOL; reg < UDA1380_CACHEREGNUM; reg++)
set_bit(reg - 0x10, &uda1380_cache_dirty);
}
codec->dapm.bias_level = level;
return 0;
}
static int uda1380_suspend(struct snd_soc_codec *codec)
{
uda1380_set_bias_level(codec, SND_SOC_BIAS_OFF);
return 0;
}
static int uda1380_resume(struct snd_soc_codec *codec)
{
uda1380_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
return 0;
}
static int uda1380_probe(struct snd_soc_codec *codec)
{
struct uda1380_platform_data *pdata =codec->dev->platform_data;
struct uda1380_priv *uda1380 = snd_soc_codec_get_drvdata(codec);
int ret;
uda1380->codec = codec;
codec->hw_write = (hw_write_t)i2c_master_send;
codec->control_data = uda1380->control_data;
if (!pdata)
return -EINVAL;
if (gpio_is_valid(pdata->gpio_reset)) {
ret = gpio_request_one(pdata->gpio_reset, GPIOF_OUT_INIT_LOW,
"uda1380 reset");
if (ret)
goto err_out;
}
if (gpio_is_valid(pdata->gpio_power)) {
ret = gpio_request_one(pdata->gpio_power, GPIOF_OUT_INIT_LOW,
"uda1380 power");
if (ret)
goto err_free_gpio;
} else {
ret = uda1380_reset(codec);
if (ret)
goto err_free_gpio;
}
INIT_WORK(&uda1380->work, uda1380_flush_work);
uda1380_set_bias_level(codec, SND_SOC_BIAS_STANDBY);
switch (pdata->dac_clk) {
case UDA1380_DAC_CLK_SYSCLK:
uda1380_write_reg_cache(codec, UDA1380_CLK, 0);
break;
case UDA1380_DAC_CLK_WSPLL:
uda1380_write_reg_cache(codec, UDA1380_CLK,
R00_DAC_CLK);
break;
}
return 0;
err_free_gpio:
if (gpio_is_valid(pdata->gpio_reset))
gpio_free(pdata->gpio_reset);
err_out:
return ret;
}
static int uda1380_remove(struct snd_soc_codec *codec)
{
struct uda1380_platform_data *pdata =codec->dev->platform_data;
uda1380_set_bias_level(codec, SND_SOC_BIAS_OFF);
gpio_free(pdata->gpio_reset);
gpio_free(pdata->gpio_power);
return 0;
}
static __devinit int uda1380_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct uda1380_priv *uda1380;
int ret;
uda1380 = devm_kzalloc(&i2c->dev, sizeof(struct uda1380_priv),
GFP_KERNEL);
if (uda1380 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, uda1380);
uda1380->control_data = i2c;
ret = snd_soc_register_codec(&i2c->dev,
&soc_codec_dev_uda1380, uda1380_dai, ARRAY_SIZE(uda1380_dai));
return ret;
}
static int __devexit uda1380_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static int __init uda1380_modinit(void)
{
int ret = 0;
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
ret = i2c_add_driver(&uda1380_i2c_driver);
if (ret != 0)
pr_err("Failed to register UDA1380 I2C driver: %d\n", ret);
#endif
return ret;
}
static void __exit uda1380_exit(void)
{
#if defined(CONFIG_I2C) || defined(CONFIG_I2C_MODULE)
i2c_del_driver(&uda1380_i2c_driver);
#endif
}
