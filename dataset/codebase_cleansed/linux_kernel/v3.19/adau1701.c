static unsigned int adau1701_register_size(struct device *dev,
unsigned int reg)
{
switch (reg) {
case ADAU1701_PINCONF_0:
case ADAU1701_PINCONF_1:
return 3;
case ADAU1701_DSPCTRL:
case ADAU1701_SEROCTL:
case ADAU1701_AUXNPOW:
case ADAU1701_OSCIPOW:
case ADAU1701_DACSET:
return 2;
case ADAU1701_SERICTL:
return 1;
}
dev_err(dev, "Unsupported register address: %d\n", reg);
return 0;
}
static bool adau1701_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case ADAU1701_DACSET:
case ADAU1701_DSPCTRL:
return true;
default:
return false;
}
}
static int adau1701_reg_write(void *context, unsigned int reg,
unsigned int value)
{
struct i2c_client *client = context;
unsigned int i;
unsigned int size;
uint8_t buf[5];
int ret;
size = adau1701_register_size(&client->dev, reg);
if (size == 0)
return -EINVAL;
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
for (i = size + 1; i >= 2; --i) {
buf[i] = value;
value >>= 8;
}
ret = i2c_master_send(client, buf, size + 2);
if (ret == size + 2)
return 0;
else if (ret < 0)
return ret;
else
return -EIO;
}
static int adau1701_reg_read(void *context, unsigned int reg,
unsigned int *value)
{
int ret;
unsigned int i;
unsigned int size;
uint8_t send_buf[2], recv_buf[3];
struct i2c_client *client = context;
struct i2c_msg msgs[2];
size = adau1701_register_size(&client->dev, reg);
if (size == 0)
return -EINVAL;
send_buf[0] = reg >> 8;
send_buf[1] = reg & 0xff;
msgs[0].addr = client->addr;
msgs[0].len = sizeof(send_buf);
msgs[0].buf = send_buf;
msgs[0].flags = 0;
msgs[1].addr = client->addr;
msgs[1].len = size;
msgs[1].buf = recv_buf;
msgs[1].flags = I2C_M_RD;
ret = i2c_transfer(client->adapter, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
return ret;
else if (ret != ARRAY_SIZE(msgs))
return -EIO;
*value = 0;
for (i = 0; i < size; i++) {
*value <<= 8;
*value |= recv_buf[i];
}
return 0;
}
static int adau1701_safeload(struct sigmadsp *sigmadsp, unsigned int addr,
const uint8_t bytes[], size_t len)
{
struct i2c_client *client = to_i2c_client(sigmadsp->dev);
struct adau1701 *adau1701 = i2c_get_clientdata(client);
unsigned int val;
unsigned int i;
uint8_t buf[10];
int ret;
ret = regmap_read(adau1701->regmap, ADAU1701_DSPCTRL, &val);
if (ret)
return ret;
if (val & ADAU1701_DSPCTRL_IST)
msleep(50);
for (i = 0; i < len / 4; i++) {
put_unaligned_le16(ADAU1701_SAFELOAD_DATA(i), buf);
buf[2] = 0x00;
memcpy(buf + 3, bytes + i * 4, 4);
ret = i2c_master_send(client, buf, 7);
if (ret < 0)
return ret;
else if (ret != 7)
return -EIO;
put_unaligned_le16(ADAU1701_SAFELOAD_ADDR(i), buf);
put_unaligned_le16(addr + i, buf + 2);
ret = i2c_master_send(client, buf, 4);
if (ret < 0)
return ret;
else if (ret != 4)
return -EIO;
}
return regmap_update_bits(adau1701->regmap, ADAU1701_DSPCTRL,
ADAU1701_DSPCTRL_IST, ADAU1701_DSPCTRL_IST);
}
static int adau1701_reset(struct snd_soc_codec *codec, unsigned int clkdiv,
unsigned int rate)
{
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
int ret;
sigmadsp_reset(adau1701->sigmadsp);
if (clkdiv != ADAU1707_CLKDIV_UNSET &&
gpio_is_valid(adau1701->gpio_pll_mode[0]) &&
gpio_is_valid(adau1701->gpio_pll_mode[1])) {
switch (clkdiv) {
case 64:
gpio_set_value_cansleep(adau1701->gpio_pll_mode[0], 0);
gpio_set_value_cansleep(adau1701->gpio_pll_mode[1], 0);
break;
case 256:
gpio_set_value_cansleep(adau1701->gpio_pll_mode[0], 0);
gpio_set_value_cansleep(adau1701->gpio_pll_mode[1], 1);
break;
case 384:
gpio_set_value_cansleep(adau1701->gpio_pll_mode[0], 1);
gpio_set_value_cansleep(adau1701->gpio_pll_mode[1], 0);
break;
case 0:
case 512:
gpio_set_value_cansleep(adau1701->gpio_pll_mode[0], 1);
gpio_set_value_cansleep(adau1701->gpio_pll_mode[1], 1);
break;
}
}
adau1701->pll_clkdiv = clkdiv;
if (gpio_is_valid(adau1701->gpio_nreset)) {
gpio_set_value_cansleep(adau1701->gpio_nreset, 0);
udelay(1);
gpio_set_value_cansleep(adau1701->gpio_nreset, 1);
mdelay(85);
}
if (clkdiv != ADAU1707_CLKDIV_UNSET) {
ret = sigmadsp_setup(adau1701->sigmadsp, rate);
if (ret) {
dev_warn(codec->dev, "Failed to load firmware\n");
return ret;
}
}
regmap_write(adau1701->regmap, ADAU1701_DACSET, ADAU1701_DACSET_DACINIT);
regmap_write(adau1701->regmap, ADAU1701_DSPCTRL, ADAU1701_DSPCTRL_CR);
regcache_mark_dirty(adau1701->regmap);
regcache_sync(adau1701->regmap);
return 0;
}
static int adau1701_set_capture_pcm_format(struct snd_soc_codec *codec,
struct snd_pcm_hw_params *params)
{
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
unsigned int mask = ADAU1701_SEROCTL_WORD_LEN_MASK;
unsigned int val;
switch (params_width(params)) {
case 16:
val = ADAU1701_SEROCTL_WORD_LEN_16;
break;
case 20:
val = ADAU1701_SEROCTL_WORD_LEN_20;
break;
case 24:
val = ADAU1701_SEROCTL_WORD_LEN_24;
break;
default:
return -EINVAL;
}
if (adau1701->dai_fmt == SND_SOC_DAIFMT_RIGHT_J) {
switch (params_width(params)) {
case 16:
val |= ADAU1701_SEROCTL_MSB_DEALY16;
break;
case 20:
val |= ADAU1701_SEROCTL_MSB_DEALY12;
break;
case 24:
val |= ADAU1701_SEROCTL_MSB_DEALY8;
break;
}
mask |= ADAU1701_SEROCTL_MSB_DEALY_MASK;
}
regmap_update_bits(adau1701->regmap, ADAU1701_SEROCTL, mask, val);
return 0;
}
static int adau1701_set_playback_pcm_format(struct snd_soc_codec *codec,
struct snd_pcm_hw_params *params)
{
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
unsigned int val;
if (adau1701->dai_fmt != SND_SOC_DAIFMT_RIGHT_J)
return 0;
switch (params_width(params)) {
case 16:
val = ADAU1701_SERICTL_RIGHTJ_16;
break;
case 20:
val = ADAU1701_SERICTL_RIGHTJ_20;
break;
case 24:
val = ADAU1701_SERICTL_RIGHTJ_24;
break;
default:
return -EINVAL;
}
regmap_update_bits(adau1701->regmap, ADAU1701_SERICTL,
ADAU1701_SERICTL_MODE_MASK, val);
return 0;
}
static int adau1701_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params, struct snd_soc_dai *dai)
{
struct snd_soc_codec *codec = dai->codec;
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
unsigned int clkdiv = adau1701->sysclk / params_rate(params);
unsigned int val;
int ret;
if (clkdiv != adau1701->pll_clkdiv) {
ret = adau1701_reset(codec, clkdiv, params_rate(params));
if (ret < 0)
return ret;
}
switch (params_rate(params)) {
case 192000:
val = ADAU1701_DSPCTRL_SR_192;
break;
case 96000:
val = ADAU1701_DSPCTRL_SR_96;
break;
case 48000:
val = ADAU1701_DSPCTRL_SR_48;
break;
default:
return -EINVAL;
}
regmap_update_bits(adau1701->regmap, ADAU1701_DSPCTRL,
ADAU1701_DSPCTRL_SR_MASK, val);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
return adau1701_set_playback_pcm_format(codec, params);
else
return adau1701_set_capture_pcm_format(codec, params);
}
static int adau1701_set_dai_fmt(struct snd_soc_dai *codec_dai,
unsigned int fmt)
{
struct snd_soc_codec *codec = codec_dai->codec;
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
unsigned int serictl = 0x00, seroctl = 0x00;
bool invert_lrclk;
switch (fmt & SND_SOC_DAIFMT_MASTER_MASK) {
case SND_SOC_DAIFMT_CBM_CFM:
seroctl |= ADAU1701_SEROCTL_MASTER | ADAU1701_SEROCTL_OBF16
| ADAU1701_SEROCTL_OLF1024;
break;
case SND_SOC_DAIFMT_CBS_CFS:
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_INV_MASK) {
case SND_SOC_DAIFMT_NB_NF:
invert_lrclk = false;
break;
case SND_SOC_DAIFMT_NB_IF:
invert_lrclk = true;
break;
case SND_SOC_DAIFMT_IB_NF:
invert_lrclk = false;
serictl |= ADAU1701_SERICTL_INV_BCLK;
seroctl |= ADAU1701_SEROCTL_INV_BCLK;
break;
case SND_SOC_DAIFMT_IB_IF:
invert_lrclk = true;
serictl |= ADAU1701_SERICTL_INV_BCLK;
seroctl |= ADAU1701_SEROCTL_INV_BCLK;
break;
default:
return -EINVAL;
}
switch (fmt & SND_SOC_DAIFMT_FORMAT_MASK) {
case SND_SOC_DAIFMT_I2S:
break;
case SND_SOC_DAIFMT_LEFT_J:
serictl |= ADAU1701_SERICTL_LEFTJ;
seroctl |= ADAU1701_SEROCTL_MSB_DEALY0;
invert_lrclk = !invert_lrclk;
break;
case SND_SOC_DAIFMT_RIGHT_J:
serictl |= ADAU1701_SERICTL_RIGHTJ_24;
seroctl |= ADAU1701_SEROCTL_MSB_DEALY8;
invert_lrclk = !invert_lrclk;
break;
default:
return -EINVAL;
}
if (invert_lrclk) {
seroctl |= ADAU1701_SEROCTL_INV_LRCLK;
serictl |= ADAU1701_SERICTL_INV_LRCLK;
}
adau1701->dai_fmt = fmt & SND_SOC_DAIFMT_FORMAT_MASK;
regmap_write(adau1701->regmap, ADAU1701_SERICTL, serictl);
regmap_update_bits(adau1701->regmap, ADAU1701_SEROCTL,
~ADAU1701_SEROCTL_WORD_LEN_MASK, seroctl);
return 0;
}
static int adau1701_set_bias_level(struct snd_soc_codec *codec,
enum snd_soc_bias_level level)
{
unsigned int mask = ADAU1701_AUXNPOW_VBPD | ADAU1701_AUXNPOW_VRPD;
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
switch (level) {
case SND_SOC_BIAS_ON:
break;
case SND_SOC_BIAS_PREPARE:
break;
case SND_SOC_BIAS_STANDBY:
regmap_update_bits(adau1701->regmap,
ADAU1701_AUXNPOW, mask, 0x00);
break;
case SND_SOC_BIAS_OFF:
regmap_update_bits(adau1701->regmap,
ADAU1701_AUXNPOW, mask, mask);
break;
}
codec->dapm.bias_level = level;
return 0;
}
static int adau1701_digital_mute(struct snd_soc_dai *dai, int mute)
{
struct snd_soc_codec *codec = dai->codec;
unsigned int mask = ADAU1701_DSPCTRL_DAM;
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
unsigned int val;
if (mute)
val = 0;
else
val = mask;
regmap_update_bits(adau1701->regmap, ADAU1701_DSPCTRL, mask, val);
return 0;
}
static int adau1701_set_sysclk(struct snd_soc_codec *codec, int clk_id,
int source, unsigned int freq, int dir)
{
unsigned int val;
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
switch (clk_id) {
case ADAU1701_CLK_SRC_OSC:
val = 0x0;
break;
case ADAU1701_CLK_SRC_MCLK:
val = ADAU1701_OSCIPOW_OPD;
break;
default:
return -EINVAL;
}
regmap_update_bits(adau1701->regmap, ADAU1701_OSCIPOW,
ADAU1701_OSCIPOW_OPD, val);
adau1701->sysclk = freq;
return 0;
}
static int adau1701_startup(struct snd_pcm_substream *substream,
struct snd_soc_dai *dai)
{
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(dai->codec);
return sigmadsp_restrict_params(adau1701->sigmadsp, substream);
}
static int adau1701_probe(struct snd_soc_codec *codec)
{
int i, ret;
unsigned int val;
struct adau1701 *adau1701 = snd_soc_codec_get_drvdata(codec);
ret = sigmadsp_attach(adau1701->sigmadsp, &codec->component);
if (ret)
return ret;
adau1701->pll_clkdiv = ADAU1707_CLKDIV_UNSET;
ret = adau1701_reset(codec, adau1701->pll_clkdiv, 0);
if (ret < 0)
return ret;
val = 0;
for (i = 0; i < 6; i++)
val |= adau1701->pin_config[i] << (i * 4);
regmap_write(adau1701->regmap, ADAU1701_PINCONF_0, val);
val = 0;
for (i = 0; i < 6; i++)
val |= adau1701->pin_config[i + 6] << (i * 4);
regmap_write(adau1701->regmap, ADAU1701_PINCONF_1, val);
return 0;
}
static int adau1701_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct adau1701 *adau1701;
struct device *dev = &client->dev;
int gpio_nreset = -EINVAL;
int gpio_pll_mode[2] = { -EINVAL, -EINVAL };
int ret;
adau1701 = devm_kzalloc(dev, sizeof(*adau1701), GFP_KERNEL);
if (!adau1701)
return -ENOMEM;
adau1701->client = client;
adau1701->regmap = devm_regmap_init(dev, NULL, client,
&adau1701_regmap);
if (IS_ERR(adau1701->regmap))
return PTR_ERR(adau1701->regmap);
if (dev->of_node) {
gpio_nreset = of_get_named_gpio(dev->of_node, "reset-gpio", 0);
if (gpio_nreset < 0 && gpio_nreset != -ENOENT)
return gpio_nreset;
gpio_pll_mode[0] = of_get_named_gpio(dev->of_node,
"adi,pll-mode-gpios", 0);
if (gpio_pll_mode[0] < 0 && gpio_pll_mode[0] != -ENOENT)
return gpio_pll_mode[0];
gpio_pll_mode[1] = of_get_named_gpio(dev->of_node,
"adi,pll-mode-gpios", 1);
if (gpio_pll_mode[1] < 0 && gpio_pll_mode[1] != -ENOENT)
return gpio_pll_mode[1];
of_property_read_u32(dev->of_node, "adi,pll-clkdiv",
&adau1701->pll_clkdiv);
of_property_read_u8_array(dev->of_node, "adi,pin-config",
adau1701->pin_config,
ARRAY_SIZE(adau1701->pin_config));
}
if (gpio_is_valid(gpio_nreset)) {
ret = devm_gpio_request_one(dev, gpio_nreset, GPIOF_OUT_INIT_LOW,
"ADAU1701 Reset");
if (ret < 0)
return ret;
}
if (gpio_is_valid(gpio_pll_mode[0]) &&
gpio_is_valid(gpio_pll_mode[1])) {
ret = devm_gpio_request_one(dev, gpio_pll_mode[0],
GPIOF_OUT_INIT_LOW,
"ADAU1701 PLL mode 0");
if (ret < 0)
return ret;
ret = devm_gpio_request_one(dev, gpio_pll_mode[1],
GPIOF_OUT_INIT_LOW,
"ADAU1701 PLL mode 1");
if (ret < 0)
return ret;
}
adau1701->gpio_nreset = gpio_nreset;
adau1701->gpio_pll_mode[0] = gpio_pll_mode[0];
adau1701->gpio_pll_mode[1] = gpio_pll_mode[1];
i2c_set_clientdata(client, adau1701);
adau1701->sigmadsp = devm_sigmadsp_init_i2c(client,
&adau1701_sigmadsp_ops, ADAU1701_FIRMWARE);
if (IS_ERR(adau1701->sigmadsp))
return PTR_ERR(adau1701->sigmadsp);
ret = snd_soc_register_codec(&client->dev, &adau1701_codec_drv,
&adau1701_dai, 1);
return ret;
}
static int adau1701_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
