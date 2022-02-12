static int wm2000_write(struct i2c_client *i2c, unsigned int reg,
unsigned int value)
{
u8 data[3];
int ret;
data[0] = (reg >> 8) & 0xff;
data[1] = reg & 0xff;
data[2] = value & 0xff;
dev_vdbg(&i2c->dev, "write %x = %x\n", reg, value);
ret = i2c_master_send(i2c, data, 3);
if (ret == 3)
return 0;
if (ret < 0)
return ret;
else
return -EIO;
}
static unsigned int wm2000_read(struct i2c_client *i2c, unsigned int r)
{
struct i2c_msg xfer[2];
u8 reg[2];
u8 data;
int ret;
reg[0] = (r >> 8) & 0xff;
reg[1] = r & 0xff;
xfer[0].addr = i2c->addr;
xfer[0].flags = 0;
xfer[0].len = sizeof(reg);
xfer[0].buf = &reg[0];
xfer[1].addr = i2c->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = 1;
xfer[1].buf = &data;
ret = i2c_transfer(i2c->adapter, xfer, 2);
if (ret != 2) {
dev_err(&i2c->dev, "i2c_transfer() returned %d\n", ret);
return 0;
}
dev_vdbg(&i2c->dev, "read %x from %x\n", data, r);
return data;
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
unsigned int reg, u8 mask, int timeout)
{
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
int ret, timeout;
BUG_ON(wm2000->anc_mode != ANC_OFF);
dev_dbg(&i2c->dev, "Beginning power up\n");
if (!wm2000->mclk_div) {
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
WM2000_ANC_ENG_IDLE, 1)) {
dev_err(&i2c->dev, "ANC engine failed to reset\n");
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_BOOT_COMPLETE, 1)) {
dev_err(&i2c->dev, "ANC engine failed to initialise\n");
return -ETIMEDOUT;
}
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_SET);
dev_dbg(&i2c->dev, "Downloading %d bytes\n",
wm2000->anc_download_size - 2);
ret = i2c_master_send(i2c, wm2000->anc_download,
wm2000->anc_download_size);
if (ret < 0) {
dev_err(&i2c->dev, "i2c_transfer() failed: %d\n", ret);
return ret;
}
if (ret != wm2000->anc_download_size) {
dev_err(&i2c->dev, "i2c_transfer() failed, %d != %d\n",
ret, wm2000->anc_download_size);
return -EIO;
}
dev_dbg(&i2c->dev, "Download complete\n");
if (analogue) {
timeout = 248;
wm2000_write(i2c, WM2000_REG_ANA_VMID_PU_TIME, timeout / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_MOUSE_ENABLE |
WM2000_MODE_THERMAL_ENABLE);
} else {
timeout = 10;
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_MOUSE_ENABLE |
WM2000_MODE_THERMAL_ENABLE);
}
ret = wm2000_read(i2c, WM2000_REG_SPEECH_CLARITY);
if (wm2000->speech_clarity)
ret &= ~WM2000_SPEECH_CLARITY;
else
ret |= WM2000_SPEECH_CLARITY;
wm2000_write(i2c, WM2000_REG_SPEECH_CLARITY, ret);
wm2000_write(i2c, WM2000_REG_SYS_START0, 0x33);
wm2000_write(i2c, WM2000_REG_SYS_START1, 0x02);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_INT_N_CLR);
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_MOUSE_ACTIVE, timeout)) {
dev_err(&i2c->dev, "Timed out waiting for device after %dms\n",
timeout * 10);
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
int timeout;
if (analogue) {
timeout = 248;
wm2000_write(i2c, WM2000_REG_ANA_VMID_PD_TIME, timeout / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_POWER_DOWN);
} else {
timeout = 10;
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_POWER_DOWN);
}
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_POWER_DOWN_COMPLETE, timeout)) {
dev_err(&i2c->dev, "Timeout waiting for ANC power down\n");
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_ANC_STAT,
WM2000_ANC_ENG_IDLE, 1)) {
dev_err(&i2c->dev, "Timeout waiting for ANC engine idle\n");
return -ETIMEDOUT;
}
dev_dbg(&i2c->dev, "powered off\n");
wm2000->anc_mode = ANC_OFF;
return 0;
}
static int wm2000_enter_bypass(struct i2c_client *i2c, int analogue)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
BUG_ON(wm2000->anc_mode != ANC_ACTIVE);
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
WM2000_STATUS_ANC_DISABLED, 10)) {
dev_err(&i2c->dev, "Timeout waiting for ANC disable\n");
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_ANC_STAT,
WM2000_ANC_ENG_IDLE, 1)) {
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
BUG_ON(wm2000->anc_mode != ANC_BYPASS);
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
WM2000_STATUS_MOUSE_ACTIVE, 10)) {
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
int timeout;
BUG_ON(wm2000->anc_mode != ANC_ACTIVE);
if (analogue) {
timeout = 248;
wm2000_write(i2c, WM2000_REG_ANA_VMID_PD_TIME, timeout / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_STANDBY_ENTRY);
} else {
timeout = 10;
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_STANDBY_ENTRY);
}
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_ANC_DISABLED, timeout)) {
dev_err(&i2c->dev,
"Timed out waiting for ANC disable after 1ms\n");
return -ETIMEDOUT;
}
if (!wm2000_poll_bit(i2c, WM2000_REG_ANC_STAT, WM2000_ANC_ENG_IDLE,
1)) {
dev_err(&i2c->dev,
"Timed out waiting for standby after %dms\n",
timeout * 10);
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
int timeout;
BUG_ON(wm2000->anc_mode != ANC_STANDBY);
wm2000_write(i2c, WM2000_REG_SYS_CTL1, 0);
if (analogue) {
timeout = 248;
wm2000_write(i2c, WM2000_REG_ANA_VMID_PU_TIME, timeout / 4);
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_ANA_SEQ_INCLUDE |
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_MOUSE_ENABLE);
} else {
timeout = 10;
wm2000_write(i2c, WM2000_REG_SYS_MODE_CNTRL,
WM2000_MODE_THERMAL_ENABLE |
WM2000_MODE_MOUSE_ENABLE);
}
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_RAM_SET);
wm2000_write(i2c, WM2000_REG_SYS_CTL2, WM2000_ANC_INT_N_CLR);
if (!wm2000_poll_bit(i2c, WM2000_REG_SYS_STATUS,
WM2000_STATUS_MOUSE_ACTIVE, timeout)) {
dev_err(&i2c->dev, "Timed out waiting for MOUSE after %dms\n",
timeout * 10);
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
for (j = 0; j < ARRAY_SIZE(anc_transitions[j].step); j++) {
if (!anc_transitions[i].step[j])
break;
ret = anc_transitions[i].step[j](i2c,
anc_transitions[i].analogue);
if (ret != 0)
return ret;
}
return 0;
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
struct wm2000_priv *wm2000 = dev_get_drvdata(&wm2000_i2c->dev);
ucontrol->value.enumerated.item[0] = wm2000->anc_active;
return 0;
}
static int wm2000_anc_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&wm2000_i2c->dev);
int anc_active = ucontrol->value.enumerated.item[0];
if (anc_active > 1)
return -EINVAL;
wm2000->anc_active = anc_active;
return wm2000_anc_set_mode(wm2000);
}
static int wm2000_speaker_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&wm2000_i2c->dev);
ucontrol->value.enumerated.item[0] = wm2000->spk_ena;
return 0;
}
static int wm2000_speaker_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&wm2000_i2c->dev);
int val = ucontrol->value.enumerated.item[0];
if (val > 1)
return -EINVAL;
wm2000->spk_ena = val;
return wm2000_anc_set_mode(wm2000);
}
static int wm2000_anc_power_event(struct snd_soc_dapm_widget *w,
struct snd_kcontrol *kcontrol, int event)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&wm2000_i2c->dev);
if (SND_SOC_DAPM_EVENT_ON(event))
wm2000->anc_eng_ena = 1;
if (SND_SOC_DAPM_EVENT_OFF(event))
wm2000->anc_eng_ena = 0;
return wm2000_anc_set_mode(wm2000);
}
int wm2000_add_controls(struct snd_soc_codec *codec)
{
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret;
if (!wm2000_i2c) {
pr_err("WM2000 not yet probed\n");
return -ENODEV;
}
ret = snd_soc_dapm_new_controls(dapm, wm2000_dapm_widgets,
ARRAY_SIZE(wm2000_dapm_widgets));
if (ret < 0)
return ret;
ret = snd_soc_dapm_add_routes(dapm, audio_map, ARRAY_SIZE(audio_map));
if (ret < 0)
return ret;
return snd_soc_add_controls(codec, wm2000_controls,
ARRAY_SIZE(wm2000_controls));
}
static int __devinit wm2000_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *i2c_id)
{
struct wm2000_priv *wm2000;
struct wm2000_platform_data *pdata;
const char *filename;
const struct firmware *fw;
int reg, ret;
u16 id;
if (wm2000_i2c) {
dev_err(&i2c->dev, "Another WM2000 is already registered\n");
return -EINVAL;
}
wm2000 = kzalloc(sizeof(struct wm2000_priv), GFP_KERNEL);
if (wm2000 == NULL) {
dev_err(&i2c->dev, "Unable to allocate private data\n");
return -ENOMEM;
}
reg = wm2000_read(i2c, WM2000_REG_ID1);
id = reg << 8;
reg = wm2000_read(i2c, WM2000_REG_ID2);
id |= reg & 0xff;
if (id != 0x2000) {
dev_err(&i2c->dev, "Device is not a WM2000 - ID %x\n", id);
ret = -ENODEV;
goto err;
}
reg = wm2000_read(i2c, WM2000_REG_REVISON);
dev_info(&i2c->dev, "revision %c\n", reg + 'A');
filename = "wm2000_anc.bin";
pdata = dev_get_platdata(&i2c->dev);
if (pdata) {
wm2000->mclk_div = pdata->mclkdiv2;
wm2000->speech_clarity = !pdata->speech_enh_disable;
if (pdata->download_file)
filename = pdata->download_file;
}
ret = request_firmware(&fw, filename, &i2c->dev);
if (ret != 0) {
dev_err(&i2c->dev, "Failed to acquire ANC data: %d\n", ret);
goto err;
}
wm2000->anc_download_size = fw->size + 2;
wm2000->anc_download = kmalloc(wm2000->anc_download_size, GFP_KERNEL);
if (wm2000->anc_download == NULL) {
dev_err(&i2c->dev, "Out of memory\n");
ret = -ENOMEM;
goto err_fw;
}
wm2000->anc_download[0] = 0x80;
wm2000->anc_download[1] = 0x00;
memcpy(wm2000->anc_download + 2, fw->data, fw->size);
release_firmware(fw);
dev_set_drvdata(&i2c->dev, wm2000);
wm2000->anc_eng_ena = 1;
wm2000->anc_active = 1;
wm2000->spk_ena = 1;
wm2000->i2c = i2c;
wm2000_reset(wm2000);
wm2000_anc_set_mode(wm2000);
wm2000_i2c = i2c;
return 0;
err_fw:
release_firmware(fw);
err:
kfree(wm2000);
return ret;
}
static __devexit int wm2000_i2c_remove(struct i2c_client *i2c)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
wm2000_anc_transition(wm2000, ANC_OFF);
wm2000_i2c = NULL;
kfree(wm2000->anc_download);
kfree(wm2000);
return 0;
}
static void wm2000_i2c_shutdown(struct i2c_client *i2c)
{
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
wm2000_anc_transition(wm2000, ANC_OFF);
}
static int wm2000_i2c_suspend(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
return wm2000_anc_transition(wm2000, ANC_OFF);
}
static int wm2000_i2c_resume(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
struct wm2000_priv *wm2000 = dev_get_drvdata(&i2c->dev);
return wm2000_anc_set_mode(wm2000);
}
static int __init wm2000_init(void)
{
return i2c_add_driver(&wm2000_i2c_driver);
}
static void __exit wm2000_exit(void)
{
i2c_del_driver(&wm2000_i2c_driver);
}
