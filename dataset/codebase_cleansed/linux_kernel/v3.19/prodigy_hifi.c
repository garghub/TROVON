static unsigned short wm_get(struct snd_ice1712 *ice, int reg)
{
reg <<= 1;
return ((unsigned short)ice->akm[0].images[reg] << 8) |
ice->akm[0].images[reg + 1];
}
static void wm_put_nocache(struct snd_ice1712 *ice, int reg, unsigned short val)
{
unsigned short cval;
cval = (reg << 9) | val;
snd_vt1724_write_i2c(ice, WM_DEV, cval >> 8, cval & 0xff);
}
static void wm_put(struct snd_ice1712 *ice, int reg, unsigned short val)
{
wm_put_nocache(ice, reg, val);
reg <<= 1;
ice->akm[0].images[reg] = val >> 8;
ice->akm[0].images[reg + 1] = val;
}
static void set_gpio_bit(struct snd_ice1712 *ice, unsigned int bit, int val)
{
unsigned int tmp = snd_ice1712_gpio_read(ice);
if (val)
tmp |= bit;
else
tmp &= ~bit;
snd_ice1712_gpio_write(ice, tmp);
}
static void wm8766_spi_send_word(struct snd_ice1712 *ice, unsigned int data)
{
int i;
for (i = 0; i < 16; i++) {
set_gpio_bit(ice, WM8766_SPI_CLK, 0);
udelay(1);
set_gpio_bit(ice, WM8766_SPI_MD, data & 0x8000);
udelay(1);
set_gpio_bit(ice, WM8766_SPI_CLK, 1);
udelay(1);
data <<= 1;
}
}
static void wm8766_spi_write(struct snd_ice1712 *ice, unsigned int reg,
unsigned int data)
{
unsigned int block;
snd_ice1712_gpio_set_dir(ice, WM8766_SPI_MD|
WM8766_SPI_CLK|WM8766_SPI_ML);
snd_ice1712_gpio_set_mask(ice, ~(WM8766_SPI_MD|
WM8766_SPI_CLK|WM8766_SPI_ML));
set_gpio_bit(ice, WM8766_SPI_ML, 0);
block = (reg << 9) | (data & 0x1ff);
wm8766_spi_send_word(ice, block);
set_gpio_bit(ice, WM8766_SPI_ML, 1);
udelay(1);
snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask);
snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
}
static void ak4396_send_word(struct snd_ice1712 *ice, unsigned int data)
{
int i;
for (i = 0; i < 16; i++) {
set_gpio_bit(ice, AK4396_CCLK, 0);
udelay(1);
set_gpio_bit(ice, AK4396_CDTI, data & 0x8000);
udelay(1);
set_gpio_bit(ice, AK4396_CCLK, 1);
udelay(1);
data <<= 1;
}
}
static void ak4396_write(struct snd_ice1712 *ice, unsigned int reg,
unsigned int data)
{
unsigned int block;
snd_ice1712_gpio_set_dir(ice, AK4396_CSN|AK4396_CCLK|AK4396_CDTI);
snd_ice1712_gpio_set_mask(ice, ~(AK4396_CSN|AK4396_CCLK|AK4396_CDTI));
set_gpio_bit(ice, AK4396_CSN, 0);
block = ((AK4396_ADDR & 0x03) << 14) | (1 << 13) |
((reg & 0x1f) << 8) | (data & 0xff);
ak4396_send_word(ice, block);
set_gpio_bit(ice, AK4396_CSN, 1);
udelay(1);
snd_ice1712_gpio_set_mask(ice, ice->gpio.write_mask);
snd_ice1712_gpio_set_dir(ice, ice->gpio.direction);
}
static int ak4396_dac_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0xFF;
return 0;
}
static int ak4396_dac_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int i;
for (i = 0; i < 2; i++)
ucontrol->value.integer.value[i] = spec->vol[i];
return 0;
}
static int ak4396_dac_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int i;
int change = 0;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
if (ucontrol->value.integer.value[i] != spec->vol[i]) {
spec->vol[i] = ucontrol->value.integer.value[i];
ak4396_write(ice, AK4396_LCH_ATT + i,
spec->vol[i] & 0xff);
change = 1;
}
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static void wm_set_vol(struct snd_ice1712 *ice, unsigned int index,
unsigned short vol, unsigned short master)
{
unsigned char nvol;
if ((master & WM_VOL_MUTE) || (vol & WM_VOL_MUTE))
nvol = 0;
else {
nvol = (((vol & ~WM_VOL_MUTE) * (master & ~WM_VOL_MUTE)) / 128)
& WM_VOL_MAX;
nvol = (nvol ? (nvol + DAC_MIN) : 0) & 0xff;
}
wm_put(ice, index, nvol);
wm_put_nocache(ice, index, 0x100 | nvol);
}
static void wm8766_set_vol(struct snd_ice1712 *ice, unsigned int index,
unsigned short vol, unsigned short master)
{
unsigned char nvol;
if ((master & WM_VOL_MUTE) || (vol & WM_VOL_MUTE))
nvol = 0;
else {
nvol = (((vol & ~WM_VOL_MUTE) * (master & ~WM_VOL_MUTE)) / 128)
& WM_VOL_MAX;
nvol = (nvol ? (nvol + DAC_MIN) : 0) & 0xff;
}
wm8766_spi_write(ice, index, (0x0100 | nvol));
}
static int wm_dac_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = DAC_RES;
return 0;
}
static int wm_dac_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int i;
for (i = 0; i < 2; i++)
ucontrol->value.integer.value[i] =
spec->vol[2 + i] & ~WM_VOL_MUTE;
return 0;
}
static int wm_dac_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int i, idx, change = 0;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
if (ucontrol->value.integer.value[i] != spec->vol[2 + i]) {
idx = WM_DAC_ATTEN_L + i;
spec->vol[2 + i] &= WM_VOL_MUTE;
spec->vol[2 + i] |= ucontrol->value.integer.value[i];
wm_set_vol(ice, idx, spec->vol[2 + i], spec->master[i]);
change = 1;
}
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm8766_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int voices = kcontrol->private_value >> 8;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = voices;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = DAC_RES;
return 0;
}
static int wm8766_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int i, ofs, voices;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xff;
for (i = 0; i < voices; i++)
ucontrol->value.integer.value[i] = spec->vol[ofs + i];
return 0;
}
static int wm8766_vol_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int i, idx, ofs, voices;
int change = 0;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xff;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < voices; i++) {
if (ucontrol->value.integer.value[i] != spec->vol[ofs + i]) {
idx = WM8766_LDA1 + ofs + i;
spec->vol[ofs + i] &= WM_VOL_MUTE;
spec->vol[ofs + i] |= ucontrol->value.integer.value[i];
wm8766_set_vol(ice, idx,
spec->vol[ofs + i], spec->master[i]);
change = 1;
}
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_master_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = DAC_RES;
return 0;
}
static int wm_master_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int i;
for (i = 0; i < 2; i++)
ucontrol->value.integer.value[i] = spec->master[i];
return 0;
}
static int wm_master_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct prodigy_hifi_spec *spec = ice->spec;
int ch, change = 0;
mutex_lock(&ice->gpio_mutex);
for (ch = 0; ch < 2; ch++) {
if (ucontrol->value.integer.value[ch] != spec->master[ch]) {
spec->master[ch] = ucontrol->value.integer.value[ch];
wm_set_vol(ice, WM_DAC_ATTEN_L + ch,
spec->vol[2 + ch], spec->master[ch]);
wm8766_set_vol(ice, WM8766_LDA1 + ch,
spec->vol[0 + ch], spec->master[ch]);
wm8766_set_vol(ice, WM8766_LDA2 + ch,
spec->vol[4 + ch], spec->master[ch]);
wm8766_set_vol(ice, WM8766_LDA3 + ch,
spec->vol[6 + ch], spec->master[ch]);
change = 1;
}
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_adc_mux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[32] = {
"NULL", WM_AIN1, WM_AIN2, WM_AIN1 "+" WM_AIN2,
WM_AIN3, WM_AIN1 "+" WM_AIN3, WM_AIN2 "+" WM_AIN3,
WM_AIN1 "+" WM_AIN2 "+" WM_AIN3,
WM_AIN4, WM_AIN1 "+" WM_AIN4, WM_AIN2 "+" WM_AIN4,
WM_AIN1 "+" WM_AIN2 "+" WM_AIN4,
WM_AIN3 "+" WM_AIN4, WM_AIN1 "+" WM_AIN3 "+" WM_AIN4,
WM_AIN2 "+" WM_AIN3 "+" WM_AIN4,
WM_AIN1 "+" WM_AIN2 "+" WM_AIN3 "+" WM_AIN4,
WM_AIN5, WM_AIN1 "+" WM_AIN5, WM_AIN2 "+" WM_AIN5,
WM_AIN1 "+" WM_AIN2 "+" WM_AIN5,
WM_AIN3 "+" WM_AIN5, WM_AIN1 "+" WM_AIN3 "+" WM_AIN5,
WM_AIN2 "+" WM_AIN3 "+" WM_AIN5,
WM_AIN1 "+" WM_AIN2 "+" WM_AIN3 "+" WM_AIN5,
WM_AIN4 "+" WM_AIN5, WM_AIN1 "+" WM_AIN4 "+" WM_AIN5,
WM_AIN2 "+" WM_AIN4 "+" WM_AIN5,
WM_AIN1 "+" WM_AIN2 "+" WM_AIN4 "+" WM_AIN5,
WM_AIN3 "+" WM_AIN4 "+" WM_AIN5,
WM_AIN1 "+" WM_AIN3 "+" WM_AIN4 "+" WM_AIN5,
WM_AIN2 "+" WM_AIN3 "+" WM_AIN4 "+" WM_AIN5,
WM_AIN1 "+" WM_AIN2 "+" WM_AIN3 "+" WM_AIN4 "+" WM_AIN5
};
return snd_ctl_enum_info(uinfo, 1, 32, texts);
}
static int wm_adc_mux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = wm_get(ice, WM_ADC_MUX) & 0x1f;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_mux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short oval, nval;
int change = 0;
mutex_lock(&ice->gpio_mutex);
oval = wm_get(ice, WM_ADC_MUX);
nval = (oval & 0xe0) | ucontrol->value.integer.value[0];
if (nval != oval) {
wm_put(ice, WM_ADC_MUX, nval);
change = 1;
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_adc_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = ADC_RES;
return 0;
}
static int wm_adc_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val;
int i;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
val = wm_get(ice, WM_ADC_ATTEN_L + i) & 0xff;
val = val > ADC_MIN ? (val - ADC_MIN) : 0;
ucontrol->value.integer.value[i] = val;
}
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int i, idx, change = 0;
mutex_lock(&ice->gpio_mutex);
for (i = 0; i < 2; i++) {
nvol = ucontrol->value.integer.value[i];
nvol = nvol ? (nvol + ADC_MIN) : 0;
idx = WM_ADC_ATTEN_L + i;
ovol = wm_get(ice, idx) & 0xff;
if (ovol != nvol) {
wm_put(ice, idx, nvol);
change = 1;
}
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_adc_mux_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int bit = kcontrol->private_value;
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] =
(wm_get(ice, WM_ADC_MUX) & (1 << bit)) ? 1 : 0;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_adc_mux_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int bit = kcontrol->private_value;
unsigned short oval, nval;
int change;
mutex_lock(&ice->gpio_mutex);
nval = oval = wm_get(ice, WM_ADC_MUX);
if (ucontrol->value.integer.value[0])
nval |= (1 << bit);
else
nval &= ~(1 << bit);
change = nval != oval;
if (change) {
wm_put(ice, WM_ADC_MUX, nval);
}
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_bypass_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] =
(wm_get(ice, WM_OUT_MUX) & 0x04) ? 1 : 0;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_bypass_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val, oval;
int change = 0;
mutex_lock(&ice->gpio_mutex);
val = oval = wm_get(ice, WM_OUT_MUX);
if (ucontrol->value.integer.value[0])
val |= 0x04;
else
val &= ~0x04;
if (val != oval) {
wm_put(ice, WM_OUT_MUX, val);
change = 1;
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static int wm_chswap_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] =
(wm_get(ice, WM_DAC_CTRL1) & 0xf0) != 0x90;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_chswap_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val, oval;
int change = 0;
mutex_lock(&ice->gpio_mutex);
oval = wm_get(ice, WM_DAC_CTRL1);
val = oval & 0x0f;
if (ucontrol->value.integer.value[0])
val |= 0x60;
else
val |= 0x90;
if (val != oval) {
wm_put(ice, WM_DAC_CTRL1, val);
wm_put_nocache(ice, WM_DAC_CTRL1, val);
change = 1;
}
mutex_unlock(&ice->gpio_mutex);
return change;
}
static void wm_proc_regs_write(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_ice1712 *ice = entry->private_data;
char line[64];
unsigned int reg, val;
mutex_lock(&ice->gpio_mutex);
while (!snd_info_get_line(buffer, line, sizeof(line))) {
if (sscanf(line, "%x %x", &reg, &val) != 2)
continue;
if (reg <= 0x17 && val <= 0xffff)
wm_put(ice, reg, val);
}
mutex_unlock(&ice->gpio_mutex);
}
static void wm_proc_regs_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_ice1712 *ice = entry->private_data;
int reg, val;
mutex_lock(&ice->gpio_mutex);
for (reg = 0; reg <= 0x17; reg++) {
val = wm_get(ice, reg);
snd_iprintf(buffer, "%02x = %04x\n", reg, val);
}
mutex_unlock(&ice->gpio_mutex);
}
static void wm_proc_init(struct snd_ice1712 *ice)
{
struct snd_info_entry *entry;
if (!snd_card_proc_new(ice->card, "wm_codec", &entry)) {
snd_info_set_text_ops(entry, ice, wm_proc_regs_read);
entry->mode |= S_IWUSR;
entry->c.text.write = wm_proc_regs_write;
}
}
static int prodigy_hifi_add_controls(struct snd_ice1712 *ice)
{
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(prodigy_hifi_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&prodigy_hifi_controls[i], ice));
if (err < 0)
return err;
}
wm_proc_init(ice);
return 0;
}
static int prodigy_hd2_add_controls(struct snd_ice1712 *ice)
{
unsigned int i;
int err;
for (i = 0; i < ARRAY_SIZE(prodigy_hd2_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&prodigy_hd2_controls[i], ice));
if (err < 0)
return err;
}
wm_proc_init(ice);
return 0;
}
static int prodigy_hifi_init(struct snd_ice1712 *ice)
{
static unsigned short wm_inits[] = {
WM_ADC_MUX, 0x0003,
WM_DAC_MUTE, 0x0001,
WM_DAC_CTRL1, 0x0000,
WM_POWERDOWN, 0x0008,
WM_RESET, 0x0000,
};
static unsigned short wm_inits2[] = {
WM_MASTER_CTRL, 0x0022,
WM_DAC_INT, 0x0022,
WM_ADC_INT, 0x0022,
WM_DAC_CTRL1, 0x0090,
WM_OUT_MUX, 0x0001,
WM_HP_ATTEN_L, 0x0179,
WM_HP_ATTEN_R, 0x0179,
WM_DAC_ATTEN_L, 0x0000,
WM_DAC_ATTEN_L, 0x0100,
WM_DAC_ATTEN_R, 0x0000,
WM_DAC_ATTEN_R, 0x0100,
WM_PHASE_SWAP, 0x0000,
#if 0
WM_DAC_MASTER, 0x0100,
#endif
WM_DAC_CTRL2, 0x0000,
WM_ADC_ATTEN_L, 0x0000,
WM_ADC_ATTEN_R, 0x0000,
#if 1
WM_ALC_CTRL1, 0x007b,
WM_ALC_CTRL2, 0x0000,
WM_ALC_CTRL3, 0x0000,
WM_NOISE_GATE, 0x0000,
#endif
WM_DAC_MUTE, 0x0000,
WM_ADC_MUX, 0x0003,
};
static unsigned short wm8766_inits[] = {
WM8766_RESET, 0x0000,
WM8766_DAC_CTRL, 0x0120,
WM8766_INT_CTRL, 0x0022,
WM8766_DAC_CTRL2, 0x0001,
WM8766_DAC_CTRL3, 0x0080,
WM8766_LDA1, 0x0100,
WM8766_LDA2, 0x0100,
WM8766_LDA3, 0x0100,
WM8766_RDA1, 0x0100,
WM8766_RDA2, 0x0100,
WM8766_RDA3, 0x0100,
WM8766_MUTE1, 0x0000,
WM8766_MUTE2, 0x0000,
};
struct prodigy_hifi_spec *spec;
unsigned int i;
ice->vt1720 = 0;
ice->vt1724 = 1;
ice->num_total_dacs = 8;
ice->num_total_adcs = 1;
ice->gpio.saved[0] = 0;
ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
if (! ice->akm)
return -ENOMEM;
ice->akm_codecs = 1;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
for (i = 0; i < ARRAY_SIZE(wm_inits); i += 2)
wm_put(ice, wm_inits[i], wm_inits[i+1]);
schedule_timeout_uninterruptible(1);
for (i = 0; i < ARRAY_SIZE(wm_inits2); i += 2)
wm_put(ice, wm_inits2[i], wm_inits2[i+1]);
for (i = 0; i < ARRAY_SIZE(wm8766_inits); i += 2)
wm8766_spi_write(ice, wm8766_inits[i], wm8766_inits[i+1]);
return 0;
}
static void ak4396_init(struct snd_ice1712 *ice)
{
static unsigned short ak4396_inits[] = {
AK4396_CTRL1, 0x87,
AK4396_CTRL2, 0x02,
AK4396_CTRL3, 0x00,
AK4396_LCH_ATT, 0x00,
AK4396_RCH_ATT, 0x00,
};
unsigned int i;
ak4396_write(ice, AK4396_CTRL1, 0x86);
msleep(100);
ak4396_write(ice, AK4396_CTRL1, 0x87);
for (i = 0; i < ARRAY_SIZE(ak4396_inits); i += 2)
ak4396_write(ice, ak4396_inits[i], ak4396_inits[i+1]);
}
static int prodigy_hd2_resume(struct snd_ice1712 *ice)
{
struct prodigy_hifi_spec *spec = ice->spec;
int i;
mutex_lock(&ice->gpio_mutex);
ak4396_init(ice);
for (i = 0; i < 2; i++)
ak4396_write(ice, AK4396_LCH_ATT + i, spec->vol[i] & 0xff);
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int prodigy_hd2_init(struct snd_ice1712 *ice)
{
struct prodigy_hifi_spec *spec;
ice->vt1720 = 0;
ice->vt1724 = 1;
ice->num_total_dacs = 1;
ice->num_total_adcs = 1;
ice->gpio.saved[0] = 0;
ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
if (! ice->akm)
return -ENOMEM;
ice->akm_codecs = 1;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
#ifdef CONFIG_PM_SLEEP
ice->pm_resume = &prodigy_hd2_resume;
ice->pm_suspend_enabled = 1;
#endif
ak4396_init(ice);
return 0;
}
