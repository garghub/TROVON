static int wm2000_write(struct i2c_client *i2c, unsigned int reg,
unsigned int value)
{
struct wm2000_priv *wm2000 = i2c_get_clientdata(i2c);
return regmap_write(wm2000->regmap, reg, value);
}
static unsigned int wm2000_read(struct i2c_client *i2c, unsigned int r)
{
struct wm2000_priv *wm2000 = i2c_get_clientdata(i2c);
unsigned int val;
int ret;
ret = regmap_read(wm2000->regmap, r, &val);
if (ret < 0)
return -1;
return val;
}
static void wm2000_reset(struct wm2000_priv *wm2000)
{
struct i2c_client *i2c = wm2000->i2c;
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_ENG_CLR);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_CLR);
wm2000_write(i2c, WM2000_REG_ID1, 0);
wm2000->anc_mode = ANC_OFF;
}
static int wm2000_poll_bit(struct i2c_client *i2c,
unsigned int reg, u8 mask)
{
int timeout = 4000;
int val;
val = wm2000_read(i2c, reg);
while (!(val & mask) && --timeout) {
msleep(1);
val = wm2000_read(i2c, reg);
}
if (timeout == 0)
return 0;
else
return 1;
}
static int wm2000_power_up(struct i2c_client *i2c, int analogue)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
unsigned long rate;
int ret;
if (WARN_ON(wm2000->anc_mode != ANC_OFF))
return -EINVAL;
dev_dbg(&i2c->dev, "Beginning power up\n");
ret = regulator_bulk_enable(WM2000_NUM_SUPPLIES, wm2000->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
rate = clk_get_rate(wm2000->mclk);
if (rate <= 13500000) {
dev_dbg(&i2c->dev, "Disabling MCLK divider\n");
wm2000_write(i2c, WM2000_REG_SYS_CTL2,
WM2000_MCLK_DIV2_ENA_CLR);
} else {
dev_dbg(&i2c->dev, "Enabling MCLK divider\n");
wm2000_write(i2c, WM2000_REG_SYS_CTL2,
WM2000_MCLK_DIV2_ENA_SET);
}
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_ENG_CLR);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_ENG_SET);
if (!wm2000_poll_bit(i2c, WM2000_REG_ANC_STAT,
WM2000_ANC_ENG_IDLE)) {
dev_err(&i2c->dev, "ANC engine failed to reset\n");
regulator_bulk_disable(WM2000_NUM_SUPPLIES, wm2000->supplies);
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_BOOT_COMPLETE)) {
dev_err(&i2c->dev, "ANC engine failed to initialise\n");
regulator_bulk_disable(WM2000_NUM_SUPPLIES, wm2000->supplies);
return -ETIMEDOUT;
}
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_SET);
dev_dbg(&i2c->dev, "Downloading %d bytes\n",
wm2000->anc_download_size - 2);
ret = i2c_master_send(i2c, wm2000->anc_download,
wm2000->anc_download_size);
if (ret < 0) {
dev_err(&i2c->dev, "i2c_transfer() failed: %d\n", ret);
regulator_bulk_disable(WM2000_NUM_SUPPLIES, wm2000->supplies);
return ret;
}
if (ret != wm2000->anc_download_size) {
dev_err(&i2c->dev, "i2c_transfer() failed, %d != %d\n",
ret, wm2000->anc_download_size);
regulator_bulk_disable(WM2000_NUM_SUPPLIES, wm2000->supplies);
return -EIO;
}
dev_dbg(&i2c->dev, "Download complete\n");
if (analogue) {
wm2000_write(i2c, WM2000_REG_ANA_VMID_PU_TIME, 248 / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_MOUSE_ENABLE |
WM2000_MODE_THERMAL_ENABLE);
} else {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_MOUSE_ENABLE |
WM2000_MODE_THERMAL_ENABLE);
}
ret = wm2000_read(i2c, WM2000_REG_SPEECH_CLARITY);
if (wm2000->speech_clarity)
ret |= WM2000_SPEECH_CLARITY;
else
ret &= ~WM2000_SPEECH_CLARITY;
wm2000_write(i2c, WM2000_REG_SPEECH_CLARITY, ret);
wm2000_write(i2c, WM2000_REG_SYS_START0, 0x33);
wm2000_write(i2c, WM2000_REG_SYS_START1, 0x02);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_INT_N_CLR);
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_MOUSE_ACTIVE)) {
dev_err(&i2c->dev, "Timed out waiting for device\n");
regulator_bulk_disable(WM2000_NUM_SUPPLIES, wm2000->supplies);
return -ETIMEDOUT;
}
dev_dbg(&i2c->dev, "ANC active\n");
if (analogue)
dev_dbg(&i2c->dev, "Analogue active\n");
wm2000->anc_mode = ANC_ACTIVE;
return 0;
}
static int wm2000_power_down(struct i2c_client *i2c, int analogue)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
if (analogue) {
wm2000_write(i2c, WM2000_REG_ANA_VMID_PD_TIME, 248 / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_POWER_DOWN);
} else {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_POWER_DOWN);
}
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_POWER_DOWN_COMPLETE)) {
dev_err(&i2c->dev, "Timeout waiting for ANC power down\n");
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_ANC_STAT,
WM2000_ANC_ENG_IDLE)) {
dev_err(&i2c->dev, "Timeout waiting for ANC engine idle\n");
return -ETIMEDOUT;
}
regulator_bulk_disable(WM2000_NUM_SUPPLIES, wm2000->supplies);
dev_dbg(&i2c->dev, "powered off\n");
wm2000->anc_mode = ANC_OFF;
return 0;
}
static int wm2000_enter_bypass(struct i2c_client *i2c, int analogue)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
if (WARN_ON(wm2000->anc_mode != ANC_ACTIVE))
return -EINVAL;
if (analogue) {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_BYPASS_ENTRY);
} else {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_BYPASS_ENTRY);
}
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_ANC_DISABLED)) {
dev_err(&i2c->dev, "Timeout waiting for ANC disable\n");
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_ANC_STAT,
WM2000_ANC_ENG_IDLE)) {
dev_err(&i2c->dev, "Timeout waiting for ANC engine idle\n");
return -ETIMEDOUT;
}
wm2000_write(i2c, WM2000_REG_SYS_CTL1, WM2000_SYS_STBY);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_CLR);
wm2000->anc_mode = ANC_BYPASS;
dev_dbg(&i2c->dev, "bypass enabled\n");
return 0;
}
static int wm2000_exit_bypass(struct i2c_client *i2c, int analogue)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
if (WARN_ON(wm2000->anc_mode != ANC_BYPASS))
return -EINVAL;
wm2000_write(i2c, WM2000_REG_SYS_CTL1, 0);
if (analogue) {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_MOUSE_ENABLE |
WM2000_MODE_THERMAL_ENABLE);
} else {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_MOUSE_ENABLE |
WM2000_MODE_THERMAL_ENABLE);
}
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_SET);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_INT_N_CLR);
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_MOUSE_ACTIVE)) {
dev_err(&i2c->dev, "Timed out waiting for MOUSE\n");
return -ETIMEDOUT;
}
wm2000->anc_mode = ANC_ACTIVE;
dev_dbg(&i2c->dev, "MOUSE active\n");
return 0;
}
static int wm2000_enter_standby(struct i2c_client *i2c, int analogue)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
if (WARN_ON(wm2000->anc_mode != ANC_ACTIVE))
return -EINVAL;
if (analogue) {
wm2000_write(i2c, WM2000_REG_ANA_VMID_PD_TIME, 248 / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_STANDBY_ENTRY);
} else {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_STANDBY_ENTRY);
}
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_ANC_DISABLED)) {
dev_err(&i2c->dev,
"Timed out waiting for ANC disable after 1ms\n");
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_ANC_STAT, WM2000_ANC_ENG_IDLE)) {
dev_err(&i2c->dev,
"Timed out waiting for standby\n");
return -ETIMEDOUT;
}
wm2000_write(i2c, WM2000_REG_SYS_CTL1, WM2000_SYS_STBY);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_CLR);
wm2000->anc_mode = ANC_STANDBY;
dev_dbg(&i2c->dev, "standby\n");
if (analogue)
dev_dbg(&i2c->dev, "Analogue disabled\n");
return 0;
}
static int wm2000_exit_standby(struct i2c_client *i2c, int analogue)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
if (WARN_ON(wm2000->anc_mode != ANC_STANDBY))
return -EINVAL;
wm2000_write(i2c, WM2000_REG_SYS_CTL1, 0);
if (analogue) {
wm2000_write(i2c, WM2000_REG_ANA_VMID_PU_TIME, 248 / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_MOUSE_ENABLE);
} else {
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_MOUSE_ENABLE);
}
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_SET);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_INT_N_CLR);
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_MOUSE_ACTIVE)) {
dev_err(&i2c->dev, "Timed out waiting for MOUSE\n");
return -ETIMEDOUT;
}
wm2000->anc_mode = ANC_ACTIVE;
dev_dbg(&i2c->dev, "MOUSE active\n");
if (analogue)
dev_dbg(&i2c->dev, "Analogue enabled\n");
return 0;
}
static int wm2000_anc_transition(struct wm2000_priv *wm2000,
enum wm2000_anc_mode mode)
{
struct i2c_client *i2c = wm2000->i2c;
int i, j;
int ret;
if (wm2000->anc_mode == mode)
return 0;
for (i = 0; i < ARRAY_SIZE(anc_transitions); i++)
if (anc_transitions[i].source == wm2000->anc_mode &&
anc_transitions[i].dest == mode)
break;
if (i == ARRAY_SIZE(anc_transitions)) {
dev_err(&i2c->dev, "No transition for %d->%d\n",
wm2000->anc_mode, mode);
return -EINVAL;
}
if (anc_transitions[i].source == ANC_OFF) {
ret = clk_prepare_enable(wm2000->mclk);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable MCLK: %d\n", ret);
return ret;
}
}
for (j = 0; j < ARRAY_SIZE(anc_transitions[j].step); j++) {
if (!anc_transitions[i].step[j])
break;
ret = anc_transitions[i].step[j](i2c,
anc_transitions[i].analogue);
if (ret != 0)
return ret;
}
if (anc_transitions[i].dest == ANC_OFF)
clk_disable_unprepare(wm2000->mclk);
return ret;
}
static int wm2000_anc_set_mode(struct wm2000_priv *wm2000)
{
struct i2c_client *i2c = wm2000->i2c;
enum wm2000_anc_mode mode;
if (wm2000->anc_eng_ena && wm2000->spk_ena)
if (wm2000->anc_active)
mode = ANC_ACTIVE;
else
mode = ANC_BYPASS;
else
mode = ANC_STANDBY;
dev_dbg(&i2c->dev, "Set mode %d (enabled %d, mute %d, active %d)\n",
mode, wm2000->anc_eng_ena, !wm2000->spk_ena,
wm2000->anc_active);
return wm2000_anc_transition(wm2000, mode);
}
static int wm2000_anc_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
ucontrol->value.enumerated.item[0] = wm2000->anc_active;
return 0;
}
static int wm2000_anc_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
int anc_active = ucontrol->value.enumerated.item[0];
int ret;
if (anc_active > 1)
return -EINVAL;
mutex_lock(&wm2000->lock);
wm2000->anc_active = anc_active;
ret = wm2000_anc_set_mode(wm2000);
mutex_unlock(&wm2000->lock);
return ret;
}
static int wm2000_speaker_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
ucontrol->value.enumerated.item[0] = wm2000->spk_ena;
return 0;
}
static int wm2000_speaker_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_soc_kcontrol_codec(kcontrol);
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
int val = ucontrol->value.enumerated.item[0];
int ret;
if (val > 1)
return -EINVAL;
mutex_lock(&wm2000->lock);
wm2000->spk_ena = val;
ret = wm2000_anc_set_mode(wm2000);
mutex_unlock(&wm2000->lock);
return ret;
}
static int wm2000_anc_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct snd_soc_codec *codec = w->codec;
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
int ret;
mutex_lock(&wm2000->lock);
if (SND_SOC_DAPM_EVENT_ON(event))
wm2000->anc_eng_ena = 1;
if (SND_SOC_DAPM_EVENT_OFF(event))
wm2000->anc_eng_ena = 0;
ret = wm2000_anc_set_mode(wm2000);
mutex_unlock(&wm2000->lock);
return ret;
}
static int wm2000_suspend(struct snd_soc_codec *codec)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
return wm2000_anc_transition(wm2000, ANC_OFF);
}
static int wm2000_resume(struct snd_soc_codec *codec)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
return wm2000_anc_set_mode(wm2000);
}
static bool wm2000_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case WM2000_REG_SYS_START:
case WM2000_REG_ANC_GAIN_CTRL:
case WM2000_REG_MSE_TH1:
case WM2000_REG_MSE_TH2:
case WM2000_REG_SPEECH_CLARITY:
case WM2000_REG_SYS_WATCHDOG:
case WM2000_REG_ANA_VMID_PD_TIME:
case WM2000_REG_ANA_VMID_PU_TIME:
case WM2000_REG_CAT_FLTR_INDX:
case WM2000_REG_CAT_GAIN_0:
case WM2000_REG_SYS_STATUS:
case WM2000_REG_SYS_MODE_CNTRL:
case WM2000_REG_SYS_START0:
case WM2000_REG_SYS_START1:
case WM2000_REG_ID1:
case WM2000_REG_ID2:
case WM2000_REG_REVISON:
case WM2000_REG_SYS_CTL1:
case WM2000_REG_SYS_CTL2:
case WM2000_REG_ANC_STAT:
case WM2000_REG_IF_CTL:
case WM2000_REG_ANA_MIC_CTL:
case WM2000_REG_SPK_CTL:
return true;
default:
return false;
}
}
static int wm2000_probe(struct snd_soc_codec *codec)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
wm2000_anc_set_mode(wm2000);
return 0;
}
static int wm2000_remove(struct snd_soc_codec *codec)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(codec->dev);
return wm2000_anc_transition(wm2000, ANC_OFF);
}
static int wm2000_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *i2c_id)
{
struct wm2000_priv *wm2000;
struct wm2000_platform_data *pdata;
const char *filename;
const struct firmware *fw = NULL;
int ret, i;
int reg;
u16 id;
wm2000 = devm_kzalloc(&i2c->dev, sizeof(struct wm2000_priv),
GFP_KERNEL);
if (!wm2000)
return -ENOMEM;
mutex_init(&wm2000->lock);
dev_set_drvdata(&i2c->dev, wm2000);
wm2000->regmap = devm_regmap_init_i2c(i2c, &wm2000_regmap);
if (IS_ERR(wm2000->regmap)) {
ret = PTR_ERR(wm2000->regmap);
dev_err(&i2c->dev, "Failed to allocate register map: %d\n",
ret);
goto out;
}
for (i = 0; i < WM2000_NUM_SUPPLIES; i++)
wm2000->supplies[i].supply = wm2000_supplies[i];
ret = devm_regulator_bulk_get(&i2c->dev, WM2000_NUM_SUPPLIES,
wm2000->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to get supplies: %d\n", ret);
return ret;
}
ret = regulator_bulk_enable(WM2000_NUM_SUPPLIES, wm2000->supplies);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
reg = wm2000_read(i2c, WM2000_REG_ID1);
id = reg << 8;
reg = wm2000_read(i2c, WM2000_REG_ID2);
id |= reg & 0xff;
if (id != 0x2000) {
dev_err(&i2c->dev, "Device is not a WM2000 - ID %x\n", id);
ret = -ENODEV;
goto err_supplies;
}
reg = wm2000_read(i2c, WM2000_REG_REVISON);
dev_info(&i2c->dev, "revision %c\n", reg + 'A');
wm2000->mclk = devm_clk_get(&i2c->dev, "MCLK");
if (IS_ERR(wm2000->mclk)) {
ret = PTR_ERR(wm2000->mclk);
dev_err(&i2c->dev, "Failed to get MCLK: %d\n", ret);
goto err_supplies;
}
filename = "wm2000_anc.bin";
pdata = dev_get_platdata(&i2c->dev);
if (pdata) {
wm2000->speech_clarity = !pdata->speech_enh_disable;
if (pdata->download_file)
filename = pdata->download_file;
}
ret = request_firmware(&fw, filename, &i2c->dev);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to acquire ANC data: %d\n", ret);
goto err_supplies;
}
wm2000->anc_download_size = fw->size + 2;
wm2000->anc_download = devm_kzalloc(&i2c->dev,
wm2000->anc_download_size,
GFP_KERNEL);
if (wm2000->anc_download == NULL) {
dev_err(&i2c->dev, "Out of memory\n");
ret = -ENOMEM;
goto err_supplies;
}
wm2000->anc_download[0] = 0x80;
wm2000->anc_download[1] = 0x00;
memcpy(wm2000->anc_download + 2, fw->data, fw->size);
wm2000->anc_eng_ena = 1;
wm2000->anc_active = 1;
wm2000->spk_ena = 1;
wm2000->i2c = i2c;
wm2000_reset(wm2000);
ret = snd_soc_register_codec(&i2c->dev, &soc_codec_dev_wm2000, NULL, 0);
err_supplies:
regulator_bulk_disable(WM2000_NUM_SUPPLIES, wm2000->supplies);
out:
release_firmware(fw);
return ret;
}
static int wm2000_i2c_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
