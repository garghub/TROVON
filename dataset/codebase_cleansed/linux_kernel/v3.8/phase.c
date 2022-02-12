static int phase22_init(struct snd_ice1712 *ice)
{
struct snd_akm4xxx *ak;
int err;
switch (ice->eeprom.subvendor) {
case VT1724_SUBDEVICE_PHASE22:
case VT1724_SUBDEVICE_TS22:
ice->num_total_dacs = 2;
ice->num_total_adcs = 2;
ice->vt1720 = 1;
break;
default:
snd_BUG();
return -EINVAL;
}
ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
ak = ice->akm;
if (!ak)
return -ENOMEM;
ice->akm_codecs = 1;
switch (ice->eeprom.subvendor) {
case VT1724_SUBDEVICE_PHASE22:
case VT1724_SUBDEVICE_TS22:
err = snd_ice1712_akm4xxx_init(ak, &akm_phase22,
&akm_phase22_priv, ice);
if (err < 0)
return err;
break;
}
return 0;
}
static int phase22_add_controls(struct snd_ice1712 *ice)
{
int err = 0;
switch (ice->eeprom.subvendor) {
case VT1724_SUBDEVICE_PHASE22:
case VT1724_SUBDEVICE_TS22:
err = snd_ice1712_akm4xxx_build_controls(ice);
if (err < 0)
return err;
}
return 0;
}
static void phase28_spi_write(struct snd_ice1712 *ice, unsigned int cs,
unsigned int data, int bits)
{
unsigned int tmp;
int i;
tmp = snd_ice1712_gpio_read(ice);
snd_ice1712_gpio_set_mask(ice, ~(PHASE28_WM_RW|PHASE28_SPI_MOSI|
PHASE28_SPI_CLK|PHASE28_WM_CS));
tmp |= PHASE28_WM_RW;
tmp &= ~cs;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
for (i = bits - 1; i >= 0; i--) {
tmp &= ~PHASE28_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
if (data & (1 << i))
tmp |= PHASE28_SPI_MOSI;
else
tmp &= ~PHASE28_SPI_MOSI;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= PHASE28_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
tmp &= ~PHASE28_SPI_CLK;
tmp |= cs;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= PHASE28_SPI_CLK;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
}
static unsigned short wm_get(struct snd_ice1712 *ice, int reg)
{
reg <<= 1;
return ((unsigned short)ice->akm[0].images[reg] << 8) |
ice->akm[0].images[reg + 1];
}
static void wm_put_nocache(struct snd_ice1712 *ice, int reg, unsigned short val)
{
phase28_spi_write(ice, PHASE28_WM_CS, (reg << 9) | (val & 0x1ff), 16);
}
static void wm_put(struct snd_ice1712 *ice, int reg, unsigned short val)
{
wm_put_nocache(ice, reg, val);
reg <<= 1;
ice->akm[0].images[reg] = val >> 8;
ice->akm[0].images[reg + 1] = val;
}
static void wm_set_vol(struct snd_ice1712 *ice, unsigned int index,
unsigned short vol, unsigned short master)
{
unsigned char nvol;
if ((master & WM_VOL_MUTE) || (vol & WM_VOL_MUTE))
nvol = 0;
else
nvol = 127 - wm_vol[(((vol & ~WM_VOL_MUTE) *
(master & ~WM_VOL_MUTE)) / 127) & WM_VOL_MAX];
wm_put(ice, index, nvol);
wm_put_nocache(ice, index, 0x180 | nvol);
}
static int wm_pcm_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
mutex_lock(&ice->gpio_mutex);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_MUTE) & 0x10) ?
0 : 1;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_pcm_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short nval, oval;
int change;
snd_ice1712_save_gpio_status(ice);
oval = wm_get(ice, WM_MUTE);
nval = (oval & ~0x10) | (ucontrol->value.integer.value[0] ? 0 : 0x10);
change = (nval != oval);
if (change)
wm_put(ice, WM_MUTE, nval);
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_master_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = WM_VOL_MAX;
return 0;
}
static int wm_master_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
int i;
for (i = 0; i < 2; i++)
ucontrol->value.integer.value[i] = spec->master[i] &
~WM_VOL_MUTE;
return 0;
}
static int wm_master_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
int ch, change = 0;
snd_ice1712_save_gpio_status(ice);
for (ch = 0; ch < 2; ch++) {
unsigned int vol = ucontrol->value.integer.value[ch];
if (vol > WM_VOL_MAX)
continue;
vol |= spec->master[ch] & WM_VOL_MUTE;
if (vol != spec->master[ch]) {
int dac;
spec->master[ch] = vol;
for (dac = 0; dac < ice->num_total_dacs; dac += 2)
wm_set_vol(ice, WM_DAC_ATTEN + dac + ch,
spec->vol[dac + ch],
spec->master[ch]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int phase28_init(struct snd_ice1712 *ice)
{
static const unsigned short wm_inits_phase28[] = {
0x1b, 0x044,
0x1c, 0x00B,
0x1d, 0x009,
0x18, 0x000,
0x16, 0x122,
0x17, 0x022,
0x00, 0,
0x01, 0,
0x02, 0,
0x03, 0,
0x04, 0,
0x05, 0,
0x06, 0,
0x07, 0,
0x08, 0x100,
0x09, 0xff,
0x0a, 0xff,
0x0b, 0xff,
0x0c, 0xff,
0x0d, 0xff,
0x0e, 0xff,
0x0f, 0xff,
0x10, 0xff,
0x11, 0x1ff,
0x12, 0x000,
0x13, 0x090,
0x14, 0x000,
0x15, 0x000,
0x19, 0x000,
0x1a, 0x000,
(unsigned short)-1
};
unsigned int tmp;
struct snd_akm4xxx *ak;
struct phase28_spec *spec;
const unsigned short *p;
int i;
ice->num_total_dacs = 8;
ice->num_total_adcs = 2;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
ice->spec = spec;
ice->akm = kzalloc(sizeof(struct snd_akm4xxx), GFP_KERNEL);
ak = ice->akm;
if (!ak)
return -ENOMEM;
ice->akm_codecs = 1;
snd_ice1712_gpio_set_dir(ice, 0x5fffff);
snd_ice1712_save_gpio_status(ice);
snd_ice1712_gpio_set_mask(ice, ~(PHASE28_WM_RESET|PHASE28_WM_CS|
PHASE28_HP_SEL));
tmp = snd_ice1712_gpio_read(ice);
tmp &= ~PHASE28_WM_RESET;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= PHASE28_WM_CS;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
tmp |= PHASE28_WM_RESET;
snd_ice1712_gpio_write(ice, tmp);
udelay(1);
p = wm_inits_phase28;
for (; *p != (unsigned short)-1; p += 2)
wm_put(ice, p[0], p[1]);
snd_ice1712_restore_gpio_status(ice);
spec->master[0] = WM_VOL_MUTE;
spec->master[1] = WM_VOL_MUTE;
for (i = 0; i < ice->num_total_dacs; i++) {
spec->vol[i] = WM_VOL_MUTE;
wm_set_vol(ice, i, spec->vol[i], spec->master[i % 2]);
}
return 0;
}
static int wm_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
int voices = kcontrol->private_value >> 8;
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = voices;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 0x7F;
return 0;
}
static int wm_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
int i, ofs, voices;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xff;
for (i = 0; i < voices; i++)
ucontrol->value.integer.value[i] =
spec->vol[ofs+i] & ~WM_VOL_MUTE;
return 0;
}
static int wm_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
int i, idx, ofs, voices;
int change = 0;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xff;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < voices; i++) {
unsigned int vol;
vol = ucontrol->value.integer.value[i];
if (vol > 0x7f)
continue;
vol |= spec->vol[ofs+i] & WM_VOL_MUTE;
if (vol != spec->vol[ofs+i]) {
spec->vol[ofs+i] = vol;
idx = WM_DAC_ATTEN + ofs + i;
wm_set_vol(ice, idx, spec->vol[ofs+i],
spec->master[i]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_mute_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo) {
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = kcontrol->private_value >> 8;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int wm_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
int voices, ofs, i;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xFF;
for (i = 0; i < voices; i++)
ucontrol->value.integer.value[i] =
(spec->vol[ofs+i] & WM_VOL_MUTE) ? 0 : 1;
return 0;
}
static int wm_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
int change = 0, voices, ofs, i;
voices = kcontrol->private_value >> 8;
ofs = kcontrol->private_value & 0xFF;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < voices; i++) {
int val = (spec->vol[ofs + i] & WM_VOL_MUTE) ? 0 : 1;
if (ucontrol->value.integer.value[i] != val) {
spec->vol[ofs + i] &= ~WM_VOL_MUTE;
spec->vol[ofs + i] |=
ucontrol->value.integer.value[i] ? 0 :
WM_VOL_MUTE;
wm_set_vol(ice, ofs + i, spec->vol[ofs + i],
spec->master[i]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_master_mute_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
ucontrol->value.integer.value[0] =
(spec->master[0] & WM_VOL_MUTE) ? 0 : 1;
ucontrol->value.integer.value[1] =
(spec->master[1] & WM_VOL_MUTE) ? 0 : 1;
return 0;
}
static int wm_master_mute_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
struct phase28_spec *spec = ice->spec;
int change = 0, i;
snd_ice1712_save_gpio_status(ice);
for (i = 0; i < 2; i++) {
int val = (spec->master[i] & WM_VOL_MUTE) ? 0 : 1;
if (ucontrol->value.integer.value[i] != val) {
int dac;
spec->master[i] &= ~WM_VOL_MUTE;
spec->master[i] |=
ucontrol->value.integer.value[i] ? 0 :
WM_VOL_MUTE;
for (dac = 0; dac < ice->num_total_dacs; dac += 2)
wm_set_vol(ice, WM_DAC_ATTEN + dac + i,
spec->vol[dac + i],
spec->master[i]);
change = 1;
}
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int wm_pcm_vol_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = PCM_RES;
return 0;
}
static int wm_pcm_vol_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short val;
mutex_lock(&ice->gpio_mutex);
val = wm_get(ice, WM_DAC_DIG_MASTER_ATTEN) & 0xff;
val = val > PCM_MIN ? (val - PCM_MIN) : 0;
ucontrol->value.integer.value[0] = val;
mutex_unlock(&ice->gpio_mutex);
return 0;
}
static int wm_pcm_vol_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
unsigned short ovol, nvol;
int change = 0;
nvol = ucontrol->value.integer.value[0];
if (nvol > PCM_RES)
return -EINVAL;
snd_ice1712_save_gpio_status(ice);
nvol = (nvol ? (nvol + PCM_MIN) : 0) & 0xff;
ovol = wm_get(ice, WM_DAC_DIG_MASTER_ATTEN) & 0xff;
if (ovol != nvol) {
wm_put(ice, WM_DAC_DIG_MASTER_ATTEN, nvol);
wm_put_nocache(ice, WM_DAC_DIG_MASTER_ATTEN, nvol | 0x100);
change = 1;
}
snd_ice1712_restore_gpio_status(ice);
return change;
}
static int phase28_deemp_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = (wm_get(ice, WM_DAC_CTRL2) & 0xf) ==
0xf;
return 0;
}
static int phase28_deemp_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
int temp, temp2;
temp = wm_get(ice, WM_DAC_CTRL2);
temp2 = temp;
if (ucontrol->value.integer.value[0])
temp |= 0xf;
else
temp &= ~0xf;
if (temp != temp2) {
wm_put(ice, WM_DAC_CTRL2, temp);
return 1;
}
return 0;
}
static int phase28_oversampling_info(struct snd_kcontrol *k,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[2] = { "128x", "64x" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items -
1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int phase28_oversampling_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = (wm_get(ice, WM_MASTER) & 0x8) ==
0x8;
return 0;
}
static int phase28_oversampling_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
int temp, temp2;
struct snd_ice1712 *ice = snd_kcontrol_chip(kcontrol);
temp = wm_get(ice, WM_MASTER);
temp2 = temp;
if (ucontrol->value.enumerated.item[0])
temp |= 0x8;
else
temp &= ~0x8;
if (temp != temp2) {
wm_put(ice, WM_MASTER, temp);
return 1;
}
return 0;
}
static int phase28_add_controls(struct snd_ice1712 *ice)
{
unsigned int i, counts;
int err;
counts = ARRAY_SIZE(phase28_dac_controls);
for (i = 0; i < counts; i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&phase28_dac_controls[i],
ice));
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(wm_controls); i++) {
err = snd_ctl_add(ice->card,
snd_ctl_new1(&wm_controls[i], ice));
if (err < 0)
return err;
}
return 0;
}
